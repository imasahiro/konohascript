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
// **************************************************************************

#define K_INTERNAL
#include <konoha1.h>
#include <konoha1/inlinelibs.h>
#include <libmemcached/memcached.h>

#ifdef __cplusplus
extern "C" {
#endif

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
	memc->a = NULL;
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
		KNH_NTRACE(ctx, "memc_init", K_FAILED, ldata);
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
	KNH_ADDREF(ctx, memc->a);
	KNH_SIZEREF(ctx);
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
		if (memc->a == NULL) {
			KNH_INITv(memc->a, new_Array0(ctx, memc_size(ctx, memc)));
		}
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
