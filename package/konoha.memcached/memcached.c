/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c)  2010-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * See www.konohaware.org/license.html for further information.
 *
 * (1) GNU Lesser General Public License 3.0 (with KONOHA_UNDER_LGPL3)
 * (2) Konoha Software Foundation License 1.0
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

// **************************************************************************
// LIST OF CONTRIBUTERS
//  kimio - Kimio Kuramitsu, Yokohama National University, Japan
//  imasahiro - Masahiro Ide, Yokohama National University, Japan
//  chen_ji - Takuma Wakamori, Yokohama National University, Japan
//  shinpei_NKT - Shinpei Nakata, Yokohama National University, Japan
//  okachin - Okamoto Yuki, Yokohama National University, Japan
// **************************************************************************

#define K_INTERNAL
#include <konoha1.h>
#include <konoha1/inlinelibs.h>
#include <libmemcached/memcached.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ======================================================================== */
// [class Memcache functions]
typedef struct {
	knh_hObject_t h;
	memcached_st *st;
} knh_Memcache_t ;


/* ------------------------------------------------------------------------ */


static void Memcache_init(CTX ctx, knh_RawPtr_t *po)
{
	po->rawptr = NULL;
}

static void Memcache_free(CTX ctx, knh_RawPtr_t *po)
{
	if (po->rawptr != NULL) {
		po->rawptr = NULL;
	}
}

DEFAPI(void) defMemcache(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->init = Memcache_init;
	cdef->free = Memcache_free;
	cdef->name = "Memcache";
}

static knh_IntData_t MemcacheConstInt[] = {
	{"DEFAULT_PORT", MEMCACHED_DEFAULT_PORT},
	{"MAX_KEY", MEMCACHED_MAX_KEY},
	{"STRIDE", MEMCACHED_STRIDE},
	//{"LIBMEMCACHED_VERSION_STRING", LIBMEMCACHED_VERSION_STRING},
	{"LIBMEMCACHED_VERSION_HEX", LIBMEMCACHED_VERSION_HEX},
	{NULL, 0}
};

DEFAPI(void) constMemcache(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, cid, MemcacheConstInt);
}

//@Native @Public Memcache Memcache_new (String host, int port)
KMETHOD Memcache_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char* host = String_to(const char*, sfp[1]);
	knh_int_t port = Int_to(knh_int_t, sfp[2]);
	Memcache_init(ctx, (knh_RawPtr_t*)mcd);
	// first, create structure
	mcd->st = memcached_create(NULL);
	if (mcd->st == NULL) {
		// failed
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTHROW(ctx, sfp, "Memcache!!", "memcached_create", K_FAILED, ldata);
	} else {
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_create", K_OK, ldata);
	}
	// second, connect to server
	memcached_server_list_st servers;
	memcached_return_t rc;
	servers = memcached_server_list_append(NULL, host, port, &rc);
	if (rc != MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_s("host", host), 
							   LOG_i("port", port), 
							   LOG_i("return_t", rc),
							   LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
							   LOG_END};
		KNH_NTRACE(ctx, "memcached_server_list_append", K_FAILED, ldata);
		goto L_RETURN;
	}
	rc = memcached_server_push(mcd->st, servers);
	if (rc != MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_s("host", host), 
							   LOG_i("port", port), 
							   LOG_i("return_t", rc),
							   LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
							   LOG_END};
		KNH_NTRACE(ctx, "memcached_server_push", K_FAILED, ldata);
	}
	memcached_server_list_free(servers);
 L_RETURN:
	RETURN_(sfp[0].o);
}


//## @Native @Hidden Memcache Memcache.opLINK(String path, NameSpace _)
//KMETHOD Memcache_opLINK(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	knh_bytes_t host_port = knh_bytes_next(S_tobyte(sfp[1].s), ':');
//	knh_index_t idx = knh_bytes_index(host_port, ':');
//	if (idx == -1) {
//		knh_ldata_t ldata[] = {LOG_s{"path", host_port.text), LOG_s("type", "Memcache"), LOG_END};
//		KNH_NTRACE(ctx, "konoha:link", K_FAILED, ldata);
//		knh_Object_toNULL(ctx, sfp[0].o);
//		RETURN_(sfp[0].o);
//	}
//	knh_int_t port;
//}

/* ======================================================================== */
// [Incrementing and decrementing values]
//@Native @Public int Memcache.increment(String key, int offset);
KMETHOD Memcache_increment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *key = String_to(const char*, sfp[1]);
	size_t key_length = ((sfp[1].s)->str.len);
	unsigned int offset;
	int i = Int_to(int, sfp[2]);
	if(i >= 0) offset = (unsigned int)i;
	else offset = (unsigned int)(-1)*i;
	uint64_t value;
	memcached_return_t rc = 
		memcached_increment(mcd->st, key, key_length, offset, &value);
	if(rc == MEMCACHED_SUCCESS) {
		// key is
		 knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_increment", K_OK, ldata);
		RETURNi_((int)value);
	} else {
		// its might be error
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc),
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_increment", K_FAILED, ldata);
		RETURN_(KNH_NULL);
	}
}

//@Native @Public int Memcache.decrement(String key, int offset);
KMETHOD Memcache_decrement(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *key = String_to(const char*, sfp[1]);
	size_t key_length = ((sfp[1].s)->str.len);
	unsigned int offset;
	int i = Int_to(int, sfp[2]);
	if(i >= 0) offset = (unsigned int)i;
	else offset = (unsigned int)(-1)*i;
	uint64_t value;
	memcached_return_t rc = 
		memcached_decrement(mcd->st, key, key_length, offset, &value);
	if(rc == MEMCACHED_SUCCESS) {
		// key is
		 knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_increment", K_OK, ldata);
		RETURNi_((int)value);
	} else {
		// its might be error
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc),
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_increment", K_FAILED, ldata);
		RETURN_(KNH_NULL);
	}
}


/* ======================================================================== */
// [Deleting data]

//@Native @Public Boolean Memcache.delete(String key, int expiration_sec);
KMETHOD Memcache_delete(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *key = String_to(const char*, sfp[1]);
	size_t key_length = ((sfp[1].s)->str.len);
	time_t expiration_sec = Int_to(time_t, sfp[2]);
	memcached_return_t rc = 
		memcached_delete(mcd->st, key, key_length, expiration_sec);
	if (rc == MEMCACHED_SUCCESS) {
		// key is 
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_delete", K_OK, ldata);
	} else {
		// its might be error
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_delete", K_FAILED, ldata);

	}
	RETURNb_(rc == MEMCACHED_SUCCESS);
}

//@Native @Public Boolean Memcache.delete_by_key(String group_key, String key, int expiration_sec);
KMETHOD Memcache_deleteByKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *group_key = String_to(const char*, sfp[1]);
	size_t group_key_length = ((sfp[1].s)->str.len);
	const char *key = String_to(const char*, sfp[2]);
	size_t key_length = ((sfp[2].s)->str.len);
	time_t expiration_sec = Int_to(time_t, sfp[3]);
	memcached_return_t rc = 
		memcached_delete_by_key(mcd->st, group_key, group_key_length,
								key, key_length, expiration_sec);
	if (rc == MEMCACHED_SUCCESS) {
		// key is 
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_delete_by_key", K_OK, ldata);
	} else {
		// its might be error
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_delete_by_key", K_FAILED, ldata);
	}
	RETURNb_(rc == MEMCACHED_SUCCESS);
}

/* ======================================================================== */
// [Determine if a keys exists]

//@Native @Public Boolean Memcache.exist(String key);
# if LIBMEMCACHED_VERSION_HEX == 0x00053000
KMETHOD Memcache_exist(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *key = String_to(const char*, sfp[1]);
	size_t key_length = ((sfp[1].s)->str.len);
	memcached_return_t rc = 
		memcached_exist(mcd->st, key, key_length);
	if (rc == MEMCACHED_SUCCESS || rc == MEMCACHED_NOTFOUND) {
		// key is exists
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_exist", K_OK, ldata);
	} else {
		// its might be error
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_exist", K_FAILED, ldata);
	}
	RETURNb_(rc == MEMCACHED_SUCCESS);
}
#endif /* LIBMEMCACHED_VERSION_HEX == 0x00053000 */

//@Native @Public Boolean Memcache.exist_by_key(String key);
# if LIBMEMCACHED_VERSION_HEX == 0x00053000
KMETHOD Memcache_existByKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *group_key = String_to(const char*, sfp[1]);
	size_t group_key_length = ((sfp[1].s)->str.len);
	const char *key = String_to(const char*, sfp[2]);
	size_t key_length = ((sfp[2].s)->str.len);
	memcached_return_t rc = 
		memcached_exist_by_key(mcd->st, group_key, group_key_length,
							   key, key_length);
	if (rc == MEMCACHED_SUCCESS) {
		// key is exists
	} else if (rc == MEMCACHED_NOTFOUND) {
		// key is not found
	} else {
		// its might be error
	}
	RETURNb_(rc == MEMCACHED_SUCCESS);
}
#endif /* LIBMEMCACHED_VERSION_HEX == 0x00053000 */

/* ======================================================================== */
// [Flushing client buffers]

//@Native @Public Boolean Memcache.flushBuffers(void);
KMETHOD Memcache_flushBuffers (CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	memcached_return_t rc = memcached_flush_buffers(mcd->st);
	if (rc == MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_flush_buffers", K_FAILED, ldata);
	} else {
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_flush_buffers", K_FAILED, ldata);
	}
	RETURNb_(rc == MEMCACHED_SUCCESS);
}

/* ======================================================================== */
// [Wiping clean the contents of a server]

//@Native @Public Boolean Memcache.flush(int expiration_sec);
KMETHOD Memcache_flush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	time_t expiration_sec = Int_to(time_t, sfp[1]);
	memcached_return_t rc = memcached_flush(mcd->st, expiration_sec);
	if (rc == MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_flush", K_FAILED, ldata);
	} else {
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_flush", K_FAILED, ldata);
	}
	RETURNb_(rc == MEMCACHED_SUCCESS);
}
/* ======================================================================== */
// [Retrieving data from the server]

//@Native @Public String Memcache.get (String key);
KMETHOD Memcache_get(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *key = String_to(const char*, sfp[1]);
	size_t key_length = (sfp[1].s)->str.len;
	size_t value_length;
	uint32_t flags;
	memcached_return_t rc;
	char *value = memcached_get(mcd->st, key, key_length, &value_length, &flags, &rc);
	if(rc == MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_get", K_OK, ldata);
		RETURN_(new_String(ctx, value));   //Ignore flags.
	} else {
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_get", K_FAILED, ldata);
		RETURN_(KNH_NULL);
	}
}

//@Native @Public String[] Memcache.mGet (String[] keys);
KMETHOD Memcache_mGet(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	knh_Array_t *a = sfp[1].a;
	int number_of_keys = knh_Array_size(a);
	const char *keys[number_of_keys];
	size_t key_length[number_of_keys];
	int i;
	for(i = 0; i < number_of_keys; i++) {
		keys[i] = S_totext(a->strings[i]);
		key_length[i] = S_size(a->strings[i]);
	}
	const char * const *keys_ptr = keys;
	memcached_return_t rc;
	rc = memcached_mget(mcd->st, keys_ptr, key_length, number_of_keys);
	if (rc != MEMCACHED_SUCCESS) {
		goto L_ERR;
	}
	knh_ldata_t ldata[] = {LOG_END};
	KNH_NTRACE(ctx, "memcached_mget", K_OK, ldata);
	knh_Array_t *ret = new_Array(ctx, CLASS_String, number_of_keys);
	memcached_result_st *result = &mcd->st->result;
//	memcached_result_create(mcd->st, result);
	while(1) {
		result = memcached_fetch_result(mcd->st, result, &rc);
		if(rc == MEMCACHED_END) break;
		if (result == NULL) {
			goto L_ERR;
		}
		knh_Array_add(ctx, ret, new_String(ctx, memcached_result_value(result)));
	}
	memcached_result_free(result);
	RETURN_(ret);
L_ERR:;
	{
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_mget", K_FAILED, ldata);
		RETURN_(KNH_NULL);
	}
}

//@Native @Public String Memcache.getByKey (String key);
KMETHOD Memcache_getByKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *group_key = String_to(const char*, sfp[1]);
	size_t group_key_length = (sfp[1].s)->str.len;
	const char *key = String_to(const char*, sfp[2]);
	size_t key_length = ((sfp[2].s)->str.len);
	size_t value_length;
	uint32_t flags;
	memcached_return_t rc;
	char *value = memcached_get_by_key(mcd->st, group_key, group_key_length, key, key_length, &value_length, &flags, &rc);
	if(rc == MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_get_by_key", K_OK, ldata);
		RETURN_(new_String(ctx, value));   //Ignore flags.
	} else {
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_get_by_key", K_FAILED, ldata);
		RETURN_(KNH_NULL);
	}
}

//@Native @Public String[] Memcache.mGetByKey (String group_key, String[] keys);
KMETHOD Memcache_mGetByKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *group_key = String_to(const char*, sfp[1]);
	size_t group_key_length = sfp[1].s->str.len;
	knh_Array_t *a = sfp[2].a;
	int number_of_keys = knh_Array_size(a);
	const char *keys[number_of_keys];
	size_t key_length[number_of_keys];
	int i;
	for(i = 0; i < number_of_keys; i++) {
		keys[i] = S_totext(a->strings[i]);
		key_length[i] = S_size(a->strings[i]);
	}
	const char * const *keys_ptr = keys;
	memcached_return_t rc;
	rc = memcached_mget_by_key(mcd->st, group_key, group_key_length, keys_ptr, key_length, number_of_keys);
	if (rc != MEMCACHED_SUCCESS) {
		goto L_ERR;
	}
	knh_ldata_t ldata[] = {LOG_END};
	KNH_NTRACE(ctx, "memcached_mgetByKey", K_OK, ldata);
	knh_Array_t *ret = new_Array(ctx, CLASS_String, number_of_keys);
	memcached_result_st *result = &mcd->st->result;
	while(1) {
		result = memcached_fetch_result(mcd->st, result, &rc);
		if(rc == MEMCACHED_END) break;
		if (result == NULL) {
			goto L_ERR;
		}
		knh_Array_add(ctx, ret, new_String(ctx, memcached_result_value(result)));
	}
	memcached_result_free(result);
	RETURN_(ret);
L_ERR:;
	{
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_mgetByKey", K_FAILED, ldata);
		RETURN_(KNH_NULL);
	}
}
/* ======================================================================== */
// [Working with result sets]

/* ======================================================================== */
// [Store, replace add, or atomically add data]

//@Native @Public void Memcache.set (String key, String value, int expiration_sec, int falgs);
KMETHOD Memcache_set (CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *key = String_to(const char*, sfp[1]);
	size_t key_length = ((sfp[1].s)->str.len);
	const char *value = String_to(const char *, sfp[2]);
	size_t value_length = ((sfp[2].s)->str.len);
	long expiration_sec = Int_to(time_t, sfp[3]);
	uint32_t flags = Int_to(uint32_t, sfp[4]);
	memcached_return_t rc = 
		memcached_set(mcd->st, key, key_length, value, value_length, 
					  expiration_sec, flags);
	if (rc == MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_set", K_OK, ldata);
	} else {
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_set", K_FAILED, ldata);
	}
	RETURNvoid_();
}

//@Native @Public void Memcache.add (String key, String value, int expiration_sec, int flags);
KMETHOD Memcache_add (CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *key = String_to(const char*, sfp[1]);
	size_t key_length = ((sfp[1].s)->str.len);
	const char *value = String_to(const char *, sfp[2]);
	size_t value_length = ((sfp[2].s)->str.len);
	time_t expiration_sec = Int_to(time_t, sfp[3]);
	uint32_t flags = Int_to(uint32_t, sfp[4]);
	memcached_return_t rc = 
		memcached_add(mcd->st, key, key_length, value, value_length,
					  expiration_sec, flags);
	if (rc == MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_add", K_OK, ldata);
	} else {
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_add", K_FAILED, ldata);
	}
	RETURNvoid_();
}

//@Native @Public void Memcache.replace (String key, String value, int expiration_sec, int flags);
KMETHOD Memcache_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *key = String_to(const char*, sfp[1]);
	size_t key_length = ((sfp[1].s)->str.len);
	const char *value = String_to(const char *, sfp[2]);
	size_t value_length = ((sfp[2].s)->str.len);
	time_t expiration_sec = Int_to(time_t, sfp[3]);
	uint32_t flags = Int_to(uint32_t, sfp[4]);
	memcached_return_t rc = 
		memcached_replace(mcd->st, key, key_length, value, value_length, 
						  expiration_sec, flags);
	if (rc == MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_replace", K_OK, ldata);
	} else {
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_replace", K_FAILED, ldata);
	}
	RETURNvoid_();
}

//@Native @Public void Memcache.set_by_key (String group_key, String key, String value, int expiration_sec, int flags);
KMETHOD Memcache_setByKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *group_key = String_to(const char*, sfp[1]);
	size_t group_key_length = ((sfp[1].s)->str.len);
	const char *key = String_to(const char*, sfp[2]);
	size_t key_length = ((sfp[2].s)->str.len);
	const char *value = String_to(const char *, sfp[3]);
	size_t value_length = ((sfp[3].s)->str.len);
	time_t expiration_sec = Int_to(time_t, sfp[4]);
	uint32_t flags = Int_to(uint32_t, sfp[5]);
	memcached_return_t rc = 
		memcached_set_by_key(mcd->st, group_key, group_key_length, 
								 key, key_length, value, value_length, 
								 expiration_sec, flags);
	if (rc == MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_set_by_key", K_OK, ldata);
	} else {
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_set_by_key", K_FAILED, ldata);
	}
	RETURNvoid_();
}

//@Native @Public void Memcache.add_by_key (String group_key, String key, String value, int expiration_sec, int flags);
KMETHOD Memcache_addByKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *group_key = String_to(const char *, sfp[1]);
	size_t group_key_length = ((sfp[1].s)->str.len);
	const char *key = String_to(const char*, sfp[2]);
	size_t key_length = ((sfp[2].s)->str.len);
	const char *value = String_to(const char *, sfp[3]);
	size_t value_length = ((sfp[3].s)->str.len);
	time_t expiration_sec = Int_to(time_t, sfp[4]);
	uint32_t flags = Int_to(uint32_t, sfp[5]);
	memcached_return_t rc = 
		memcached_add_by_key(mcd->st, group_key, group_key_length, 
								 key, key_length, value, value_length, 
								 expiration_sec, flags);
	if (rc == MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_add_by_key", K_OK, ldata);
	} else {
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_add_by_key", K_FAILED, ldata);
	}
	RETURNvoid_();
}

//@Native @Public void Memcache.replace_by_key (String group_key, String key, String value, int expiration_sec, int flags);
KMETHOD Memcache_replaceByKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *group_key = String_to(const char *, sfp[1]);
	size_t group_key_length = ((sfp[1].s)->str.len);
	const char *key = String_to(const char*, sfp[2]);
	size_t key_length = ((sfp[2].s)->str.len);
	const char *value = String_to(const char *, sfp[3]);
	size_t value_length = ((sfp[3].s)->str.len);
	time_t expiration_sec = Int_to(time_t, sfp[4]);
	uint32_t flags = Int_to(uint32_t, sfp[5]);
	memcached_return_t rc = 
		memcached_replace_by_key(mcd->st, group_key, group_key_length, 
								 key, key_length, value, value_length, 
								 expiration_sec, flags);
	if (rc == MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_replace_by_key", K_OK, ldata);
	} else {
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_replace_by_key", K_FAILED, ldata);
	}
	RETURNvoid_();
}

/* ======================================================================== */
// [appending or prepending]

//@Native @Public Boolean Memcache.prepend(String key, String vlaue, int expiration_sec, int flags);
KMETHOD Memcache_prepend(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *key = String_to(const char*, sfp[1]);
	size_t key_length = ((sfp[1].s)->str.len);
	const char *value = String_to(const char *, sfp[2]);
	size_t value_length = ((sfp[2].s)->str.len);
	time_t expiration_sec = Int_to(time_t, sfp[3]);
	uint32_t flags = Int_to(uint32_t, sfp[4]);
	memcached_return_t rc = 
		memcached_prepend(mcd->st, key, key_length, value, value_length, 
						  expiration_sec, flags);
	if (rc == MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_prepend", K_OK, ldata);
	} else {
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_prepend", K_FAILED, ldata);
	}
	RETURNb_(rc == MEMCACHED_SUCCESS);
}


//@Native @Public Boolean Memcache.append(String key, String vlaue, int expiration_sec, int flags);
KMETHOD Memcache_append(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *key = String_to(const char*, sfp[1]);
	size_t key_length = ((sfp[1].s)->str.len);
	const char *value = String_to(const char *, sfp[2]);
	size_t value_length = ((sfp[2].s)->str.len);
	time_t expiration_sec = Int_to(time_t, sfp[3]);
	uint32_t flags = Int_to(uint32_t, sfp[4]);
	memcached_return_t rc = 
		memcached_append(mcd->st, key, key_length, value, value_length, 
						  expiration_sec, flags);
	if (rc == MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_append", K_OK, ldata);
	} else {
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_append", K_FAILED, ldata);
	}
	RETURNb_(rc == MEMCACHED_SUCCESS);
}

//@Native @Public Boolean Memcache.prepend_by_key(String group_key, String key, String vlaue, int expiration_sec, int flags);
KMETHOD Memcache_prependByKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *group_key = String_to(const char *, sfp[1]);
	size_t group_key_length = ((sfp[1].s)->str.len);
	const char *key = String_to(const char*, sfp[2]);
	size_t key_length = ((sfp[2].s)->str.len);
	const char *value = String_to(const char *, sfp[3]);
	size_t value_length = ((sfp[3].s)->str.len);
	time_t expiration_sec = Int_to(time_t, sfp[4]);
	uint32_t flags = Int_to(uint32_t, sfp[5]);
	memcached_return_t rc = 
		memcached_prepend_by_key(mcd->st, group_key, group_key_length, 
								 key, key_length, value, value_length, 
								 expiration_sec, flags);
	if (rc == MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_prepend_by_key", K_OK, ldata);
	} else {
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_prepend_by_key", K_FAILED, ldata);
	}
	RETURNvoid_();
}

//@Native @Public Boolean Memcache.append_by_key(String group_key, String key, String vlaue, int expiration_sec, int flags);
KMETHOD Memcache_appendByKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Memcache_t *mcd = (knh_Memcache_t *)sfp[0].o;
	const char *group_key = String_to(const char *, sfp[1]);
	size_t group_key_length = ((sfp[1].s)->str.len);
	const char *key = String_to(const char*, sfp[2]);
	size_t key_length = ((sfp[2].s)->str.len);
	const char *value = String_to(const char *, sfp[3]);
	size_t value_length = ((sfp[3].s)->str.len);
	time_t expiration_sec = Int_to(time_t, sfp[4]);
	uint32_t flags = Int_to(uint32_t, sfp[5]);
	memcached_return_t rc = 
		memcached_append_by_key(mcd->st, group_key, group_key_length, 
								 key, key_length, value, value_length, 
								 expiration_sec, flags);
	if (rc == MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_END};
		KNH_NTRACE(ctx, "memcached_append_by_key", K_OK, ldata);
	} else {
		knh_ldata_t ldata[] = {
			LOG_i("return_t", rc), 
			LOG_s("memcached_err", memcached_strerror(mcd->st, rc)),
			LOG_END};
		KNH_NTRACE(ctx, "memcached_append_by_key", K_FAILED, ldata);
	}
	RETURNb_(rc == MEMCACHED_SUCCESS);
}

/* ======================================================================== */
// [Working with data on the server in an atomic fashion]

/* ======================================================================== */
// [private functions]

typedef struct {
	knh_context_t *ctx;
	knh_Array_t *a;
	memcached_st *st;
} knh_memcached_t;

static knh_memcached_t *knh_memcached_malloc(CTX ctx)
{
	return (knh_memcached_t *)KNH_MALLOC(ctx, sizeof(knh_memcached_t));
}

static void knh_memcached_init(CTX ctx, knh_memcached_t *memc, memcached_st *st)
{
	memc->ctx = NULL;
	memc->a = new_Array0(ctx, 0);
	memc->st = st;
}

static void knh_memcached_free(CTX ctx, knh_memcached_t *memc)
{
	memcached_free(memc->st);
	KNH_FREE(ctx, memc, sizeof(knh_memcached_t));
}

static knh_mapptr_t *memc_init(CTX ctx, size_t init, const char *path, struct knh_DictMap_t *opt)
{
	memcached_return rc;
	memcached_server_list_st servers;
	knh_bytes_t host, host_port = knh_bytes_next(B(path), ':');
	knh_index_t idx = knh_bytes_index(host_port, ':');
	if (idx == -1) {
		knh_ldata_t ldata[] = {LOG_s("path", host_port.text), LOG_END};
		KNH_NTRACE(ctx, "memc_init", K_FAILED, ldata);
		return NULL;
	} else {
		knh_ldata_t ldata[] = {LOG_s("path", host_port.text), LOG_END};
		KNH_NTRACE(ctx, "memc_init", K_OK, ldata);
	}
	host = knh_bytes_first(host_port, idx);
	knh_int_t port;
	if (!knh_bytes_parseint(knh_bytes_next(host_port, ':'), &port)) {
		knh_ldata_t ldata[] = {LOG_s("path", host_port.text), LOG_END};
		KNH_NTRACE(ctx, "memc_init", K_FAILED, ldata);
		return NULL;
	}
	memcached_st *st = memcached_create(NULL);
	char tmp = host.buf[host.len];
	host.buf[host.len] = '\0';
	servers = memcached_server_list_append(NULL, host.text, port, &rc);
	if (rc != MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_s("host", host.text), LOG_i("port", port), LOG_s("error", memcached_strerror(st, rc)), LOG_END};
		KNH_NTRACE(ctx, "memcached_server_list_append", K_FAILED, ldata);
		return NULL;
	}
	host.buf[host.len] = tmp;
	rc = memcached_server_push(st, servers);
	if (rc != MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_s("host", host.text), LOG_i("port", port), LOG_s("error", memcached_strerror(st, rc)), LOG_END};
		KNH_NTRACE(ctx, "memc_init", K_FAILED, ldata);
		return NULL;
	}
	memcached_server_list_free(servers);
	knh_memcached_t *memc = knh_memcached_malloc(ctx);
	knh_memcached_init(ctx, memc, st);
	return (knh_mapptr_t *)memc;
}

static void memc_reftrace(CTX ctx, knh_mapptr_t *m FTRARG)
{
	knh_memcached_t *memc = (knh_memcached_t *)m;
	if (memc->ctx == NULL) {
		KNH_ADDREF(ctx, memc->a);
		KNH_SIZEREF(ctx);
	}
}

static void memc_freemap(CTX ctx, knh_mapptr_t *m)
{
	knh_memcached_t *memc = (knh_memcached_t *)m;
	knh_memcached_free(ctx, memc);
}

static knh_bool_t string_isprint(const char *s, size_t len)
{
	size_t i;
	for (i = 0; i < len; i++) {
		if (iscntrl(s[i])) return 0;
	}
	return 1;
}

static knh_bool_t memc_get(CTX ctx, knh_mapptr_t* m, knh_sfp_t *ksfp, knh_sfp_t *rsfp)
{
	memcached_return rc;
	knh_memcached_t *memc = (knh_memcached_t *)m;
	knh_String_t *key = ksfp[0].s;
	size_t vlen;
	uint32_t flags;
	const char *val = memcached_get(memc->st, S_totext(key), S_size(key), &vlen, &flags, &rc);
	if (rc != MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_s("key", S_totext(key)), LOG_s("error", memcached_strerror(memc->st, rc)), LOG_END};
		KNH_NTRACE(ctx, "memc_get", K_FAILED, ldata);
		return 0;
	}
	if (string_isprint(val, vlen)) {
		KNH_SETv(ctx, rsfp[0].s, new_String(ctx, val));
	} else {
		knh_Bytes_t *ba = new_Bytes(ctx, "memc_get", vlen);
		knh_Bytes_write2(ctx, ba, val, vlen);
		KNH_SETv(ctx, rsfp[0].ba, ba);
	}
	free((char *)val);
	return 1;
}

static void memc_remove(CTX ctx, knh_mapptr_t* m, knh_sfp_t *ksfp)
{
	memcached_return rc;
	knh_memcached_t *memc = (knh_memcached_t *)m;
	knh_String_t *key =ksfp[0].s;
	rc = memcached_delete(memc->st, S_totext(key), S_size(key), 0);
	if (rc != MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_s("key", S_totext(key)), LOG_s("error", memcached_strerror(memc->st, rc)), LOG_END};
		KNH_NTRACE(ctx, "memc_remove", K_FAILED, ldata);
	}
}

static size_t memc_size(CTX ctx, knh_mapptr_t* m)
{
	memcached_return rc;
	knh_memcached_t *memc = (knh_memcached_t *)m;
	memcached_stat_st *stat = memcached_stat(memc->st, "", &rc);
	size_t size = stat->curr_items;
	memcached_stat_free(memc->st, stat);
	return size;
}

static memcached_return knh_memcached_set(memcached_st *ptr, const char *key, size_t key_length,
		const char *value, size_t value_length, time_t expiration, uint32_t flags) {
	memcached_return rc;
	rc = memcached_add(ptr, key, key_length, value, value_length, expiration, flags);
	if (rc == MEMCACHED_NOTSTORED) {
		rc = memcached_replace(ptr, key, key_length, value, value_length, expiration, flags);
	}
	return rc;
}

static void memc_set(CTX ctx, knh_mapptr_t* m, knh_sfp_t *kvsfp)
{
	memcached_return rc;
	knh_memcached_t *memc = (knh_memcached_t *)m;
	knh_String_t *key = kvsfp[0].s;
	if (IS_String(kvsfp[1].o)) {
		knh_String_t *val = kvsfp[1].s;
		rc = knh_memcached_set(memc->st, S_totext(key), S_size(key), S_totext(val), S_size(val), 0, 0);
	} else if (IS_Bytes(kvsfp[1].o)) {
		knh_Bytes_t *val = kvsfp[1].ba;
		rc = knh_memcached_set(memc->st, S_totext(key), S_size(key), BA_totext(val), BA_size(val), 0, 0);
	} else {
		knh_ldata_t ldata[] = {LOG_msg("unknown value type"), LOG_END};
		KNH_NTRACE(ctx, "memc_set", K_FAILED, ldata);
		return;
	}
	if (rc != MEMCACHED_SUCCESS) {
		knh_ldata_t ldata[] = {LOG_s("key", S_totext(key)),
			LOG_s("val", IS_String(kvsfp[1].o) ? S_totext(kvsfp[1].s) : BA_totext(kvsfp[1].ba)),
			LOG_s("error", memcached_strerror(memc->st, rc)), LOG_END};
		KNH_NTRACE(ctx, "memc_set", K_FAILED, ldata);
		return;
	}
}

static memcached_return_t dumper(const memcached_st *st, const char *key, size_t keylen, void *context)
{
	knh_memcached_t *memc = (knh_memcached_t *)context;
	knh_context_t *ctx = memc->ctx;
	knh_Array_t *a = memc->a;
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	CWB_write(ctx, cwb, new_bytes2(key, keylen));
	knh_Array_add(ctx, a, CWB_newString(ctx, cwb, 0));
	return MEMCACHED_SUCCESS;
}

static knh_bool_t memc_next(CTX ctx, knh_mapptr_t *m, knh_nitr_t *mitr, knh_sfp_t *rsfp)
{
	memcached_return rc;
	knh_memcached_t *memc = (knh_memcached_t *)m;
	if (memc->ctx == NULL) {
		memc->ctx = WCTX(ctx);
		memcached_dump_fn callbacks[1];
		callbacks[0] = &dumper;
		rc = memcached_dump(memc->st, callbacks, memc, 1);
		if (rc != MEMCACHED_SUCCESS) {
			knh_ldata_t ldata[] = {LOG_s("error", memcached_strerror(memc->st, rc)), LOG_END};
			KNH_NTRACE(ctx, "memc_next", K_FAILED, ldata);
			return 0;
		}
	}
	if (mitr->index < knh_Array_size(memc->a)) {
		knh_String_t *key = (knh_String_t *)knh_Array_n(memc->a, mitr->index);
		KNH_SETv(ctx, rsfp[0].s, key);
		BEGIN_LOCAL(ctx, lsfp, 2);
		knh_sfp_t *ksfp = &lsfp[0];
		KNH_SETv(ctx, ksfp[0].s, key);
		knh_sfp_t *vsfp = &lsfp[1];
		if (memc_get(ctx, m, ksfp, vsfp)) {
			if (IS_String(vsfp[0].o)) {
				KNH_SETv(ctx, rsfp[1].s, vsfp[0].s);
			} else if (IS_Bytes(vsfp[0].o)) {
				KNH_SETv(ctx, rsfp[1].ba, vsfp[0].ba);
			}
		}
		END_LOCAL(ctx, lsfp);
		mitr->index++;
		return 1;
	}
	mitr->index = knh_Array_size(memc->a);
	knh_Array_clear(ctx, memc->a, 0);
	memc->ctx = NULL;
	return 0;
}

static const knh_MapDPI_t* memc_config(CTX ctx, knh_class_t p1, knh_class_t p2);

static const knh_MapDPI_t MEMCMAP_SO = {
	K_DSPI_MAP,    // type
	"memcached",   // name
	memc_config,   // config
	memc_init,     // init
	memc_reftrace, // reftrace
	memc_freemap,  // freemap
	memc_get,      // get
	memc_set,      // set
	memc_remove,   // remove
	memc_size,     // size
	memc_next,     // next
};

static const knh_MapDPI_t *memc_config(CTX ctx, knh_class_t p1, knh_class_t p2)
{
	if (IS_Tstr(p1)) {
		return &MEMCMAP_SO;
	}
	return NULL;
}

/* ======================================================================== */
// [DEFAPI]

#ifdef _SETUP
DEFAPI(const knh_PackageDef_t*) init(CTX ctx, knh_LoaderAPI_t *kapi)
{
	kapi->addMapDPI(ctx, "memcached", &MEMCMAP_SO);
	//knh_NameSpace_setLinkClass(ctx, ctx->share->rootns, STEXT("memcached"), ClassTBL(CLASS_Tvoid));
	RETURN_PKGINFO("konoha.memcached");
}
#endif /* _SETUP */

#ifdef __cplusplus
}
#endif
