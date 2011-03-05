/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us.
 *
 * (1) GNU General Public License 3.0 (with K_UNDER_GPL)
 * (2) Konoha Non-Disclosure License 1.0
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

/* ************************************************************************ */

//#define USE_STEXT 1
//#define USE_B     1
#define USE_bytes_strcmp      1
#define USE_bytes_strcasecmp  1
#define USE_bytes_equals      1
#define USE_hash              1

#include"commons.h"

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

#define K_USING_HASHMAP 1
#ifdef K_USING_HASHMAP

/* ------------------------------------------------------------------------ */
/* [HashMap] */

#define knh_map_hmap(m)      ((knh_hmap_t*)m)
#define knh_map_hentry(m)    (((knh_hmap_t*)m)->hentry)

static knh_map_t *hmap_init(CTX ctx, size_t init, const char *path, void *option)
{
	knh_hmap_t *hmap = (knh_hmap_t*)KNH_MALLOC(ctx, sizeof(knh_hmap_t));
	knh_bzero(hmap, sizeof(knh_hmap_t));
	if(init < K_HASH_INITSIZE) init = K_HASH_INITSIZE;
	hmap->hentry = (knh_hentry_t**)KNH_REALLOC(ctx, NULL, 0, init, sizeof(knh_hentry_t*));
	hmap->hmax = init;
	hmap->size = 0;
	hmap->factor = KNH_HASH_FACTOR(hmap->hmax);
	return (knh_map_t*)hmap;
}

static knh_hmap_t *hmap_rehash(CTX ctx, knh_hmap_t *hmap)
{
	size_t i, newhmax = hmap->hmax * 2 + 1;
	knh_hentry_t **hentry = knh_map_hentry(hmap);
	knh_hentry_t **newhentry = (knh_hentry_t**)KNH_REALLOC(ctx, NULL, 0, newhmax, sizeof(knh_hentry_t*));
	for(i = 0; i < hmap->hmax; i++) {
		knh_hentry_t *e = hentry[i];
		while(e != NULL) {
			knh_hentry_t *p = e;
			knh_hashcode_t ni = p->hcode % newhmax;
			e = e->next;
			p->next = newhentry[ni];
			newhentry[ni] = p;
		}
	}
	KNH_FREE(ctx, hentry, hmap->hmax * sizeof(knh_hentry_t*));
	hmap->hentry = newhentry;
	hmap->hmax = newhmax;
	hmap->factor = KNH_HASH_FACTOR(newhmax);
	return hmap;
}

static void hmap_ftr(CTX ctx, knh_map_t *m FTRARG)
{
	knh_hmap_t *hmap = knh_map_hmap(m);
	size_t i;
	KNH_ENSUREREF(ctx, hmap->size * 2);
	for(i = 0; i < hmap->hmax; i++) {
		knh_hentry_t *e = hmap->hentry[i];
		while(e != NULL) {
			KNH_ADDREF(ctx, e->key);
			KNH_ADDREF(ctx, e->value);
			e = e->next;
		}
	}
	KNH_SIZEREF(ctx);
}

static void hmap_ftrdata(CTX ctx, knh_map_t *m FTRARG)
{
	knh_hmap_t *hmap = knh_map_hmap(m);
	size_t i;
	KNH_ENSUREREF(ctx, hmap->size);
	for(i = 0; i < hmap->hmax; i++) {
		knh_hentry_t *e = hmap->hentry[i];
		while(e != NULL) {
			KNH_ADDREF(ctx, e->key);
			e = e->next;
		}
	}
	KNH_SIZEREF(ctx);
}

static void hmap_free(CTX ctx, knh_map_t *m)
{
	knh_hmap_t *hmap = knh_map_hmap(m);
	size_t i;
	for(i = 0; i < hmap->hmax; i++) {
		knh_hentry_t *e = hmap->hentry[i];
		while(e != NULL) {
			knh_hentry_t *p = e;
			e = e->next;
			KNH_FREE(ctx, p, sizeof(knh_hentry_t));
		}
	}
	KNH_FREE(ctx, hmap->hentry, sizeof(knh_hentry_t*)*(hmap->hmax));
	KNH_FREE(ctx, hmap, sizeof(knh_hmap_t));
}

static knh_bool_t hmap_get(CTX ctx, knh_map_t* m, knh_sfp_t *ksfp, knh_sfp_t *rsfp)
{
	knh_hmap_t *hmap = knh_map_hmap(m);
	knh_hentry_t **hentry = knh_map_hentry(m);
	knh_bytes_t k = S_tobytes(ksfp[0].s);
	knh_hashcode_t hcode = knh_hash(0, k.text, k.len);
	size_t idx = hcode % hmap->hmax;
	knh_hentry_t *e = hentry[idx];
	while(e != NULL) {
		knh_bytes_t k2 = S_tobytes(e->skey);
		if(e->hcode == hcode && knh_bytes_equals(k, k2)) {
			KNH_SETv(ctx, rsfp[0].o, e->value);
			return 1;
		}
		e = e->next;
	}
	return 0;
}

static knh_bool_t hmap_getdata(CTX ctx, knh_map_t* m, knh_sfp_t *ksfp, knh_sfp_t *rsfp)
{
	knh_hmap_t *hmap = knh_map_hmap(m);
	knh_hentry_t **hentry = knh_map_hentry(m);
	knh_bytes_t k = S_tobytes(ksfp[0].s);
	knh_hashcode_t hcode = knh_hash(0, k.text, k.len);
	size_t idx = hcode % hmap->hmax;
	knh_hentry_t *e = hentry[idx];
	while(e != NULL) {
		knh_bytes_t k2 = S_tobytes(e->skey);
		if(e->hcode == hcode && knh_bytes_equals(k, k2)) {
			rsfp[0].ndata = e->dvalue;
			return 1;
		}
		e = e->next;
	}
	rsfp[0].ndata = 0;
	return 0;
}

static void hmap_set(CTX ctx, knh_map_t* m, knh_sfp_t *kvsfp)
{
	knh_hmap_t *hmap = knh_map_hmap(m);
	knh_hentry_t **hentry = knh_map_hentry(m);
	knh_bytes_t k = S_tobytes(kvsfp[0].s);
	knh_hashcode_t hcode = knh_hash(0, k.text, k.len);
	size_t idx = hcode % hmap->hmax;
	knh_hentry_t *e = hentry[idx];
	while(e != NULL) {
		knh_bytes_t k2 = S_tobytes(e->skey);
		if(e->hcode == hcode && knh_bytes_equals(k, k2)) {
			KNH_SETv(ctx, e->value, kvsfp[1].o);
			return;
		}
		e = e->next;
	}
	if(hmap->size > hmap->factor) {
		hmap = hmap_rehash(ctx, hmap);
		hentry = knh_map_hentry(hmap);
		idx = hcode % hmap->hmax;
	}
	e = (knh_hentry_t*)KNH_MALLOC(ctx, sizeof(knh_hentry_t));
	e->hcode = hcode;
	KNH_INITv(e->key, kvsfp[0].o);
	KNH_INITv(e->value, kvsfp[1].o);
	e->next = hentry[idx];
	hentry[idx] = e;
	hmap->size += 1;
}

static void hmap_setdata(CTX ctx, knh_map_t* m, knh_sfp_t *kvsfp)
{
	knh_hmap_t *hmap = knh_map_hmap(m);
	knh_hentry_t **hentry = knh_map_hentry(m);
	knh_bytes_t k = S_tobytes(kvsfp[0].s);
	knh_hashcode_t hcode = knh_hash(0, k.text, k.len);
	size_t idx = hcode % hmap->hmax;
	knh_hentry_t *e = hentry[idx];
	while(e != NULL) {
		knh_bytes_t k2 = S_tobytes(e->skey);
		if(e->hcode == hcode && knh_bytes_equals(k, k2)) {
			e->dvalue = kvsfp[1].ndata;
			return ;
		}
		e = e->next;
	}
	if(hmap->size > hmap->factor) {
		hmap = hmap_rehash(ctx, hmap);
		hentry = knh_map_hentry(hmap);
	}
	e = (knh_hentry_t*)KNH_MALLOC(ctx, sizeof(knh_hentry_t));
	e->hcode = hcode;
	KNH_INITv(e->key, kvsfp[0].o);
	e->dvalue = kvsfp[1].ndata;
	e->next = hentry[idx];
	hentry[idx] = e;
	hmap->size += 1;
}

static void hmap_remove(CTX ctx, knh_map_t* m, knh_sfp_t *ksfp)
{
	KNH_TODO("HashMap.remove");
}

//static void hmap_dremove(CTX ctx, knh_map_t* m, knh_sfp_t *ksfp)
//{
//	KNH_TODO("HashMap.remove");
//}

static size_t hmap_size(CTX ctx, knh_map_t* m)
{
	knh_hmap_t *hmap = knh_map_hmap(m);
	return hmap->size;
}

static ITRNEXT hmap_key_next(CTX ctx, knh_sfp_t *sfp, long rtnidx)
{
//	knh_Iterator_t *it = sfp[0].it;
//	knh_Map_t *m = (knh_Map_t*) DP(it)->source;
//	knh_hmap_t *hmap = m->hmap;
//	knh_hentry_t **hentry = knh_map_hentry(hmap);
//	size_t pos;
//	for(pos = DP(it)->pos; pos < hmap->hmax; pos++) {
//		knh_hentry_t *e = hentry[pos];
//		while(e != NULL) {
//			knh_Tuple_t *t = new_Tuple(ctx, O_cid(e->value), 2);
//			KNH_SETv(ctx, t->first,  e->key);
//			KNH_SETv(ctx, t->second, e->value);
//			DP(it)->pos = pos+1;
//			ITRNEXT_(t);
//			e = e->next;
//		}
//	}
//	DP(it)->pos = pos;
	KNH_TODO(__FUNCTION__);
	ITREND_();
}

static knh_bool_t hmap_setIterator(CTX ctx, knh_map_t* m, knh_Iterator_t *it)
{
	it->fnext_1 = DP(it)->fnext = hmap_key_next;
	return 0;
}

static knh_MapDSPI_t* hmap_config(CTX ctx, knh_class_t p1, knh_class_t p2);

static knh_MapDSPI_t MAP_StringObject = {
	K_DSPI_MAP, "hash",
	hmap_config,
	hmap_init, hmap_ftr, hmap_free,
	hmap_get, hmap_set, hmap_remove, hmap_size,
	hmap_setIterator,
};

static knh_MapDSPI_t MAP_StringData = {
	K_DSPI_MAP, "hash",
	hmap_config, hmap_init, hmap_ftrdata, hmap_free,
	hmap_getdata, hmap_setdata, hmap_remove, hmap_size,
	hmap_setIterator,
};

//static knh_MapDSPI_t MAP_DataObject = {
//	K_DSPI_MAP, "hash",
//	hmap_config, hmap_init, hmap_dftr, hmap_free,
//	hmap_dget, hmap_dset, hmap_dremove, hmap_size,
//	hmap_setIterator,
//};
//
//static knh_MapDSPI_t MAP_DataData = {
//	K_DSPI_MAP, "hash",
//	hmap_config, hmap_init, hmap_dftrdata, hmap_free,
//	hmap_dgetdata, hmap_dsetdata, hmap_dremove, hmap_size,
//	hmap_setIterator,
//};

static knh_MapDSPI_t* hmap_config(CTX ctx, knh_class_t p1, knh_class_t p2)
{
//	if(IS_Tunbox(p1)) {
//		if(IS_Tunbox(p2)) {
//			return &MAP_DataData;
//		}
//		return &MAP_DataObject;
//	}
//	else {
	if(IS_Tstr(p1)) {
		if(IS_Tunbox(p2)) {
			return &MAP_StringData;
		}
		return &MAP_StringObject;
	}
	return NULL;
}

#endif

/* ------------------------------------------------------------------------ */
/* dmap */

#define UNSORTED 8
#define knh_map_dmap(m)        ((knh_dmap_t*)m)
#define knh_map_dentry(m)      (((knh_dmap_t*)m)->dentry)

static knh_uint64_t knh_struint64(knh_bytes_t t)
{
	const unsigned char *p = (const unsigned char*)t.text;
	knh_uint64_t n = 0;
	if(t.len > 0) {
		switch(t.len) {
		default: n |= ((knh_uint64_t)p[7]);
		case 7: n |= (((knh_uint64_t)p[6]) << (64-56));
		case 6: n |= (((knh_uint64_t)p[5]) << (64-48));
		case 5: n |= (((knh_uint64_t)p[4]) << (64-40));
		case 4: n |= (((knh_uint64_t)p[3]) << (64-32));
		case 3: n |= (((knh_uint64_t)p[2]) << (64-24));
		case 2: n |= (((knh_uint64_t)p[1]) << (64-16));
		case 1: n |= (((knh_uint64_t)p[0]) << (64-8));
		}
	}
	return n;
}

static int dentry_strcmp(const void *p, const void *p2)
{
	knh_dentry_t *e = (knh_dentry_t*)p;
	knh_dentry_t *e2 = (knh_dentry_t*)p2;
	K_USE_FASTDMAP(if(e->ukey == e2->ukey))
		return knh_bytes_strcmp(S_tobytes(e->key), S_tobytes(e2->key));
	K_USE_FASTDMAP(return (e->ukey < e2->ukey) ? -1 : 1;)
}

static knh_map_t *dmap_init(CTX ctx, size_t init, const char *path, void *option)
{
	knh_dmap_t *dmap = (knh_dmap_t*)KNH_MALLOC(ctx, sizeof(knh_dmap_t));
	if(init < K_HASH_INITSIZE) init = 4;
	dmap->dentry = (knh_dentry_t*)KNH_REALLOC(ctx, NULL, 0, init, sizeof(knh_dentry_t));
	dmap->capacity = init;
	dmap->size = 0;
	dmap->sorted = 0;
	dmap->strcmpr = knh_bytes_strcmp;
	K_USE_FASTDMAP(dmap->strkeyuint = knh_struint64;)
	dmap->dentrycmpr = dentry_strcmp;
	return dmap;
}

static void dmap_ftr(CTX ctx, knh_map_t *m FTRARG)
{
	knh_dmap_t *dmap = knh_map_dmap(m);
	knh_dentry_t *dentry = knh_map_dentry(m);
	size_t i;
	KNH_ENSUREREF(ctx, dmap->size * 2);
	for(i = 0; i < dmap->size; i++) {
		KNH_ADDREF(ctx, dentry[i].key);
		KNH_ADDREF(ctx, dentry[i].value);
	}
	KNH_SIZEREF(ctx);
}

static void dmap_ftrdata(CTX ctx, knh_map_t *m FTRARG)
{
	knh_dmap_t *dmap = knh_map_dmap(m);
	knh_dentry_t *dentry = knh_map_dentry(m);
	size_t i;
	KNH_ENSUREREF(ctx, dmap->size);
	for(i = 0; i < dmap->size; i++) {
		KNH_ADDREF(ctx,dentry[i].key);
	}
	KNH_SIZEREF(ctx);
}


static void dmap_free(CTX ctx, knh_map_t *m)
{
	knh_dmap_t *dmap = knh_map_dmap(m);
	KNH_FREE(ctx, dmap->dentry, sizeof(knh_dentry_t)*dmap->capacity);
	if(dmap->DBGNAME != NULL) {
		KNH_SYSLOG(ctx, LOG_DEBUG, "USAGE", "*name=%s, size=%d", dmap->DBGNAME, dmap->size);
	}
	KNH_FREE(ctx, dmap, sizeof(knh_dmap_t));
}

static size_t dmap_size(CTX ctx, knh_map_t* m)
{
	knh_dmap_t *dmap = knh_map_dmap(m);
	return dmap->size;
}

static ITRNEXT dmap_key_next(CTX ctx, knh_sfp_t *sfp, long rtnidx)
{
//	knh_Iterator_t *it = sfp[0].it;
//	knh_Map_t *m = (knh_Map_t*) DP(it)->source;
//	knh_dmap_t *dmap = knh_map_dmap(m->dmap);
//	knh_dentry_t *dentry = knh_map_dentry(m->dmap);
//	size_t i;
//	for(i = DP(it)->pos; i < dmap->size; i++) {
//		knh_Tuple_t *t = new_Tuple(ctx, O_cid(dentry[i].value), 2);
//		KNH_SETv(ctx, t->first,  dentry[i].key);
//		KNH_SETv(ctx, t->second, dentry[i].value);
//		DP(it)->pos = i+1;
//		ITRNEXT_(t);
//	}
//	DP(it)->pos = i;
	KNH_TODO(__FUNCTION__);
	ITREND_();
}

static knh_bool_t dmap_setIterator(CTX ctx, knh_map_t* m, knh_Iterator_t *it)
{
	it->fnext_1 = DP(it)->fnext = dmap_key_next;
	return 0;
}

/* ------------------------------------------------------------------------ */
/* String */

//static void dump(knh_dentry_t *a, size_t sp, size_t ep, int res)
//{
//	size_t i;
//	for(i = sp; i < ep; i++) {
//		DBG_P("a[%ld] %llx %s %ld", i, a[i].ukey, S_tochar(a[i].key), a[i].nvalue);
//	}
//}

//static knh_index_t dmap_index(knh_dmap_t *dmap, size_t sp, size_t ep, knh_bytes_t key)
//{
//	knh_dentry_t *a = dmap->dentry;
//	L_TAIL:;
//	if(ep - sp < UNSORTED) {
//		size_t i;
//		for(i = sp; i < ep; i++) {
//			if(dmap->strcmpr(S_tobytes(a[i].key), key) == 0) return i;
//		}
//		return -1;
//	}
//	else {
//		size_t cp = KNH_MID(sp, ep);
//		int res = dmap->strcmpr(S_tobytes(a[cp].key), key);
//		if(res == 0) {return cp; }
//		else if(res > 0) { ep = cp; }
//		else { sp = cp + 1; }
//		goto L_TAIL;
//	}
//}

static knh_index_t dmap_index(knh_dmap_t *dmap, size_t sp, size_t ep, knh_bytes_t key)
{
	knh_dentry_t *a = dmap->dentry;
	knh_uint64_t ukey = dmap->strkeyuint(key);
	L_TAIL:;
	if(ep - sp < UNSORTED) {
		size_t i;
		for(i = sp; i < ep; i++) {
			if(a[i].ukey == ukey) {
				knh_bytes_t k = S_tobytes(a[i].key);
				if(key.len < 8) {
					//DBG_ASSERT(key.len == k.len);
					return i;
				}
				if(dmap->strcmpr(k, key) == 0) return i;
			}
		}
		return -1;
	}
	else {
		size_t cp = KNH_MID(sp, ep);
		if(a[cp].ukey < ukey) {
			sp = cp + 1;
		}
		else if(a[cp].ukey > ukey) {
			ep = cp;
		}
		else {
			knh_bytes_t k = S_tobytes(a[cp].key);
			int res = dmap->strcmpr(k, key);
			if(res == 0) {return cp; }
			else if(res > 0) { ep = cp; }
			else { sp = cp + 1; }
		}
		goto L_TAIL;
	}
}

static knh_bool_t dmap_get(CTX ctx, knh_map_t* m, knh_sfp_t *ksfp, knh_sfp_t *rsfp)
{
	knh_dmap_t *dmap = knh_map_dmap(m);
	knh_bytes_t key = S_tobytes(ksfp[0].s);
	knh_index_t loc = dmap_index(dmap, 0, dmap->sorted, key);
	if(loc == -1) {
		loc = dmap_index(dmap, dmap->sorted, dmap->size, key);
		if(loc == -1) return 0;
	}
	KNH_SETv(ctx, rsfp[0].o, dmap->dentry[loc].value);
	return 1;
}

static knh_bool_t dmap_getdata(CTX ctx, knh_map_t* m, knh_sfp_t *ksfp, knh_sfp_t *rsfp)
{
	knh_dmap_t *dmap = knh_map_dmap(m);
	knh_bytes_t key = S_tobytes(ksfp[0].s);
	knh_index_t loc = dmap_index(dmap, 0, dmap->sorted, key);
	if(loc == -1) {
		loc = dmap_index(dmap, dmap->sorted, dmap->size, key);
		if(loc == -1) return 0;
	}
	rsfp[0].ndata = dmap->dentry[loc].nvalue;
	return 1;
}

#define dmap_grow(ctx, dmap) {\
		if(!(dmap->size < dmap->capacity)) {\
			size_t newsize = k_grow(dmap->capacity);\
			DBG_P("GROW %s capacity=%d, newsize=%d", dmap->DBGNAME, dmap->capacity, newsize);\
			dmap->dentry = (knh_dentry_t*)KNH_REALLOC(ctx, dmap->dentry, dmap->capacity, newsize, sizeof(knh_dentry_t));\
			dmap->capacity = newsize;\
		}\
	}\

#define dmap_sort(dmap) \
	if(!((dmap->size - dmap->sorted) < UNSORTED)) {\
		/*DBG_P("SORTED %s sorted=%d, size=%d", dmap->DBGNAME, dmap->sorted, dmap->size); */\
		knh_qsort(dmap->dentry, dmap->size, sizeof(knh_dentry_t), dmap->dentrycmpr);\
		dmap->sorted = dmap->size;\
	}\

void dmap_sort_(knh_dmap_t *dmap, int isforced)
{
	if(isforced || dmap->size != dmap->sorted) {
		//DBG_P("SORTED* %s, sorted=%d, size=%d", dmap->DBGNAME, dmap->sorted, dmap->size);
		knh_qsort(dmap->dentry, dmap->size, sizeof(knh_dentry_t), dmap->dentrycmpr);
		dmap->sorted = dmap->size;
	}
}

static void dmap_add(CTX ctx, knh_dmap_t *dmap, knh_sfp_t *kvsfp)
{
	size_t loc = dmap->size;
	dmap_grow(ctx, dmap);
	KNH_INITv(dmap->dentry[loc].key, kvsfp[0].s);
	KNH_INITv(dmap->dentry[loc].value, kvsfp[1].o);
	K_USE_FASTDMAP(dmap->dentry[loc].ukey = dmap->strkeyuint(S_tobytes(kvsfp[0].s)));
	dmap->size++;
}

static void dmap_adddata(CTX ctx, knh_dmap_t *dmap, knh_sfp_t *kvsfp)
{
	size_t loc = dmap->size;
	dmap_grow(ctx, dmap);
	KNH_INITv(dmap->dentry[loc].key, kvsfp[0].s);
	dmap->dentry[loc].nvalue = kvsfp[1].ndata;
	K_USE_FASTDMAP(dmap->dentry[loc].ukey = dmap->strkeyuint(S_tobytes(kvsfp[0].s)));
	dmap->size++;
}

static void dmap_set(CTX ctx, knh_map_t* m, knh_sfp_t* kvsfp)
{
	knh_dmap_t *dmap = knh_map_dmap(m);
	knh_bytes_t key = S_tobytes(kvsfp[0].s);
	knh_index_t loc = dmap_index(dmap, 0, dmap->sorted, key);
	if(loc == -1) {
		loc = dmap_index(dmap, dmap->sorted, dmap->size, key);
		if(loc == -1) {
			dmap_add(ctx, dmap, kvsfp);
			dmap_sort(dmap);
			return;
		}
	}
	KNH_SETv(ctx, dmap->dentry[loc].value, kvsfp[1].o);
}

static void dmap_setdata(CTX ctx, knh_map_t* m, knh_sfp_t* kvsfp)
{
	knh_dmap_t *dmap = knh_map_dmap(m);
	knh_bytes_t key = S_tobytes(kvsfp[0].s);
	knh_index_t loc = dmap_index(dmap, 0, dmap->sorted, key);
	if(loc == -1) {
		loc = dmap_index(dmap, dmap->sorted, dmap->size, key);
		if(loc == -1) {
			dmap_adddata(ctx, dmap, kvsfp);
			dmap_sort(dmap);
			return;
		}
	}
	dmap->dentry[loc].nvalue = kvsfp[1].ndata;
}

static void dmap_remove(CTX ctx, knh_map_t* m, knh_sfp_t *kvsfp)
{
	knh_dmap_t *dmap = knh_map_dmap(m);
	knh_bytes_t key = S_tobytes(kvsfp[0].s);
	knh_index_t loc = dmap_index(dmap, 0, dmap->sorted, key);
	if(loc == -1) {
		loc = dmap_index(dmap, dmap->sorted, dmap->size, key);
		if(loc == -1) {
			return;
		}
	}
	KNH_FINALv(ctx, dmap->dentry[loc].key);
	KNH_FINALv(ctx, dmap->dentry[loc].value);
	if((size_t)loc < dmap->sorted) {
		dmap->sorted -= 1;
	}
	memmove(dmap->dentry + loc, dmap->dentry + loc + 1, (dmap->size - loc - 1)*sizeof(knh_dentry_t));
	dmap->size--;
}

static void dmap_removedata(CTX ctx, knh_map_t* m, knh_sfp_t *kvsfp)
{
	knh_dmap_t *dmap = knh_map_dmap(m);
	knh_bytes_t key = S_tobytes(kvsfp[0].s);
	knh_index_t loc = dmap_index(dmap, 0, dmap->sorted, key);
	if(loc == -1) {
		loc = dmap_index(dmap, dmap->sorted, dmap->size, key);
		if(loc == -1) {
			return;
		}
	}
	KNH_FINALv(ctx, dmap->dentry[loc].key);
	if((size_t)loc < dmap->sorted) {
		dmap->sorted -= 1;
	}
	memmove(dmap->dentry + loc, dmap->dentry + loc + 1, (dmap->size - loc - 1)*sizeof(knh_dentry_t));
	dmap->size--;
}

static knh_MapDSPI_t* dmap_config(CTX ctx, knh_class_t p1, knh_class_t p2);

static knh_MapDSPI_t DMAP_StringObject = {
	K_DSPI_MAP, "dict",
	dmap_config, dmap_init, dmap_ftr, dmap_free,
	dmap_get, dmap_set, dmap_remove, dmap_size, dmap_setIterator,
};

static knh_MapDSPI_t DMAP_StringInt = {
	K_DSPI_MAP, "dict",
	dmap_config, dmap_init, dmap_ftrdata, dmap_free,
	dmap_getdata, dmap_setdata, dmap_removedata, dmap_size, dmap_setIterator,
};

static knh_MapDSPI_t* dmap_config(CTX ctx, knh_class_t p1, knh_class_t p2)
{
	if(IS_Tstr(p1)) {
		if(IS_Tint(p2) || p2 == TYPE_Boolean) {
			return &DMAP_StringInt;
		}
		if(IS_Tfloat(p1)) {
			return &DMAP_StringInt;
		}
		return &DMAP_StringObject;
	}
	return NULL;
}

/* ------------------------------------------------------------------------- */
/* [casecmp] */

//knh_uint64_t knh_strcaseuint64(knh_bytes_t t)
//{
//	const unsigned char *p = (const unsigned char*)t.text;
//	knh_uint64_t n = 0;
//	if(t.len > 0) {
//		switch(t.len) {
//		default: n |= ((knh_uint64_t)toupper(p[7]));
//		case 7: n |= (((knh_uint64_t)toupper(p[6])) << (64-56));
//		case 6: n |= (((knh_uint64_t)toupper(p[5])) << (64-48));
//		case 5: n |= (((knh_uint64_t)toupper(p[4])) << (64-40));
//		case 4: n |= (((knh_uint64_t)toupper(p[3])) << (64-32));
//		case 3: n |= (((knh_uint64_t)toupper(p[2])) << (64-24));
//		case 2: n |= (((knh_uint64_t)toupper(p[1])) << (64-16));
//		case 1: n |= (((knh_uint64_t)toupper(p[0])) << (64-8));
//		}
//	}
//	return n;
//}

static knh_uint64_t knh_strcaseuint64(knh_bytes_t t)
{
	int ch[8] = {0};
	knh_uint64_t n = 0;
	size_t i, c = 0;
	for(i = 0; i < 8; i++) {
		while(t.text[c] == '_') c++;
		if(c >= t.len) break;
		ch[i] = toupper(t.text[c]); c++;
	}
	if(i > 0) {
		switch(i) {
		default: n |= ((knh_uint64_t)ch[7]);
		case 7: n |= (((knh_uint64_t)ch[6]) << (64-56));
		case 6: n |= (((knh_uint64_t)ch[5]) << (64-48));
		case 5: n |= (((knh_uint64_t)ch[4]) << (64-40));
		case 4: n |= (((knh_uint64_t)ch[3]) << (64-32));
		case 3: n |= (((knh_uint64_t)ch[2]) << (64-24));
		case 2: n |= (((knh_uint64_t)ch[1]) << (64-16));
		case 1: n |= (((knh_uint64_t)ch[0]) << (64-8));
		}
	}
	return n;
}

int knh_bytes_strcasecmp2(knh_bytes_t t1, knh_bytes_t t2)
{
	const char *p1 = t1.text, *e1 = t1.text + t1.len;
	const char *p2 = t2.text, *e2 = t2.text + t2.len;
	int ch1, ch2;
	while(1) {
		while(*p1 == '_') p1++;
		while(*p2 == '_') p2++;
		if(p1 == e1) return (p2 == e2) ? 0 : 1;
		if(p2 == e2) return -1;
		ch1 = toupper((unsigned char)*p1);
		ch2 = toupper((unsigned char)*p2);
		if(ch1 == ch2) {
			p1++; p2++; continue;
		}
		return (ch1 < ch2) ? -1 : 1;
	}
}

static int dentry_strcasecmp(const void *p, const void *p2)
{
	knh_dentry_t *e = (knh_dentry_t*)p;
	knh_dentry_t *e2 = (knh_dentry_t*)p2;
	K_USE_FASTDMAP(if(e->ukey == e2->ukey))
		return knh_bytes_strcasecmp2(S_tobytes(e->key), S_tobytes(e2->key));
	K_USE_FASTDMAP(return (e->ukey < e2->ukey) ? -1 : 1;)
}

static void dmap_case(knh_dmap_t *dmap)
{
	dmap->strkeyuint = knh_strcaseuint64;
	dmap->dentrycmpr = dentry_strcasecmp;
	dmap->strcmpr = knh_bytes_strcasecmp2;
}

/* ------------------------------------------------------------------------ */
/* DictMap */

knh_DictMap_t* new_DictMap0_(CTX ctx, size_t capacity, int isCaseMap, const char *DBGNAME)
{
	knh_Map_t *m = new_H(Map);
	m->dspi = &DMAP_StringObject;
	m->map = m->dspi->init(ctx, capacity, NULL, NULL);
	DBG_ASSERT(m->map != NULL);
	if(isCaseMap) dmap_case(m->dmap);
	m->dmap->DBGNAME = DBGNAME;
	return (knh_DictMap_t*)m;
}

knh_DictSet_t* new_DictSet0_(CTX ctx, size_t capacity, int isCaseMap, const char *DBGNAME)
{
	knh_Map_t *m = new_H(Map);
	m->dspi = &DMAP_StringInt;
	m->map = m->dspi->init(ctx, capacity, NULL, NULL);
	DBG_ASSERT(m->map != NULL);
	if(isCaseMap) dmap_case(m->dmap);
	m->dmap->DBGNAME = DBGNAME;
	return (knh_DictSet_t*)m;
}

knh_String_t* knh_DictMap_keyAt(knh_DictMap_t *m, size_t n)
{
	DBG_ASSERT(n < knh_DictMap_size(m));
	return m->dmap->dentry[n].key;
}

Object* knh_DictMap_valueAt(knh_DictMap_t *m, size_t n)
{
	DBG_ASSERT(n < knh_DictMap_size(m));
	return m->dmap->dentry[n].value;
}

knh_uintptr_t knh_DictSet_valueAt(knh_DictSet_t *m, size_t n)
{
	DBG_ASSERT(n < knh_DictSet_size(m));
	return (knh_uintptr_t)m->dmap->dentry[n].nvalue;
}

knh_index_t knh_DictMap_index(knh_DictMap_t *m, knh_bytes_t key)
{
	knh_dmap_t *dmap = knh_map_dmap(m->dmap);
	knh_index_t loc = dmap_index(dmap, 0, dmap->sorted, key);
	if(loc == -1) {
		loc = dmap_index(dmap, dmap->sorted, dmap->size, key);
	}
//	if(loc == -1) {
//		DBG_P("%s key='%s'", dmap->DBGNAME, key.text);
//		dump(dmap->dentry, 0, dmap->sorted, -1);
//		DBG_P("*unsorted %d", dmap->sorted);
//		dump(dmap->dentry, dmap->sorted, dmap->size, -1);
//	}
	return loc;
}

Object *knh_DictMap_getNULL(CTX ctx, knh_DictMap_t *m, knh_bytes_t key)
{
	knh_dmap_t *dmap = knh_map_dmap(m->dmap);
	knh_index_t loc = dmap_index(dmap, 0, dmap->sorted, key);
	if(loc == -1) {
		loc = dmap_index(dmap, dmap->sorted, dmap->size, key);
	}
//	if(loc == -1) {
//		DBG_P("%s key='%s'", dmap->DBGNAME, key.text);
//		dump(dmap->dentry, 0, dmap->sorted, -1);
//		DBG_P("*unsorted %d", dmap->sorted);
//		dump(dmap->dentry, dmap->sorted, dmap->size, -1);
//	}
	return (loc == -1) ? NULL : dmap->dentry[loc].value;
}

knh_uintptr_t knh_DictSet_get(CTX ctx, knh_DictSet_t *m, knh_bytes_t key)
{
	knh_dmap_t *dmap = knh_map_dmap(m->dmap);
	knh_index_t loc = dmap_index(dmap, 0, dmap->sorted, key);
	if(loc == -1) {
		loc = dmap_index(dmap, dmap->sorted, dmap->size, key);
	}
//	if(loc == -1) {
//		DBG_P("%s key='%s'", dmap->DBGNAME, key.text);
//		dump(dmap->dentry, 0, dmap->sorted, -1);
//		DBG_P("*unsorted %d", dmap->sorted);
//		dump(dmap->dentry, dmap->sorted, dmap->size, -1);
//	}
	return (loc == -1) ? 0 : (knh_uintptr_t)dmap->dentry[loc].nvalue;
}

void DictMap_set_(CTX ctx, knh_DictMap_t *m, knh_String_t *key, dynamic *v)
{
	knh_sfp_t* kvsfp = ctx->esp;
	KNH_SETv(ctx, kvsfp[0].o, key);
	KNH_SETv(ctx, kvsfp[1].o, v);
	m->dspi->set(ctx, m->map, kvsfp);
}

void knh_DictSet_set(CTX ctx, knh_DictSet_t *m, knh_String_t *key, knh_uintptr_t n)
{
	knh_sfp_t* kvsfp = ctx->esp;
	KNH_SETv(ctx, kvsfp[0].o, key);
	kvsfp[1].ivalue = n;
	m->dspi->set(ctx, m->map, kvsfp);
}

void knh_DictMap_append(CTX ctx, knh_DictMap_t *m, knh_String_t *key, knh_Object_t *v)
{
	knh_sfp_t* kvsfp = ctx->esp;
	KNH_SETv(ctx, kvsfp[0].o, key);
	KNH_SETv(ctx, kvsfp[1].o, v);
	dmap_add(ctx, m->dmap, kvsfp);
}

void knh_DictSet_append(CTX ctx, knh_DictSet_t *m, knh_String_t *key, knh_uintptr_t n)
{
	knh_sfp_t* kvsfp = ctx->esp;
	KNH_SETv(ctx, kvsfp[0].o, key);
	kvsfp[1].ivalue = n;
	dmap_adddata(ctx, m->dmap, kvsfp);
}

void knh_DictSet_sort(CTX ctx, knh_DictSet_t *m)
{
	dmap_sort(m->dmap);
}

/* ------------------------------------------------------------------------ */

void knh_loadScriptDefaultMapDSPI(CTX ctx)
{
#ifdef K_USING_HASHMAP
	knh_addDSPI(ctx, "hash", (knh_DSPI_t*)&MAP_StringObject);
#endif
	knh_hash(0, "", 0); // dummy
	knh_addDSPI(ctx, "dict", (knh_DSPI_t*)&DMAP_StringObject);
}

/* ------------------------------------------------------------------------ */

knh_MapDSPI_t *knh_getMapDSPI(CTX ctx, knh_bytes_t path)
{
	if(path.len == 0) {
		return &DMAP_StringObject;
	}
	else {
		knh_MapDSPI_t *p = (knh_MapDSPI_t*) knh_getDSPINULL(ctx, K_DSPI_MAP, path);
		if(p == NULL) {
			//SYSLOG_UnknownPathType(ctx, path);
			p = &DMAP_StringObject;
		}
		return p;
	}
}

knh_MapDSPI_t *knh_getMapDSPIfromCID(CTX ctx, knh_class_t p1, knh_class_t p2)
{
#ifdef K_USING_HASHMAP
	if(IS_Tstr(p1)) {
		if(IS_Tunbox(p2)) {
			return &MAP_StringData;
		}
		return &MAP_StringObject;
	}
#endif
	if(IS_Tstr(p1)) {
		if(IS_Tint(p2) || p2 == TYPE_Boolean) {
			return &DMAP_StringInt;
		}
		if(IS_Tfloat(p1)) {
			return &DMAP_StringInt;
		}
		return &DMAP_StringObject;
	}
	return &DMAP_StringObject;
}

//void testDict(CTX ctx)
//{
//	knh_DictSet_t *ds = DP(ctx->sys)->tokenDictSet;
//	int i0, i2, i1, i3;
//	knh_uchar_t buf[16] = {0};
//	knh_bytes_t t = {{buf}, 0};
//	size_t cnt = 0;
//	dmap_case(ds->dmap);
//	dmap_sort_(ds->dmap, 1);
//	for(i0 = 'A'; i0 < 'z'; i0++) {
//		for(i1 = 'A'; i1 < 'z'; i1++) {
//			for(i2 = 'A'; i2 < 'z'; i2++) {
//				for(i3 = 'A'; i3 < 'z'; i3++) {
//					buf[0] = i0; buf[1] = i1; buf[2] = i2; buf[3] = i3; buf[4] = 0;
//					t.len = 4;
//					if(knh_DictSet_index(ds, t) != -1) cnt++;
//					buf[4] = i0; buf[5] = i1; buf[6] = i2; buf[7] = i3; buf[8] = 0;
//					t.len = 4;
//					if(knh_DictSet_index(ds, t) != -1) cnt++;
//					buf[8] = i0; buf[9] = i1; buf[10] = i2; buf[11] = i3; buf[12] = 0;
//					t.len = 4;
//					if(knh_DictSet_index(ds, t) != -1) cnt++;
//				}
//			}
//		}
//	}
//	fprintf(stderr, "cnt=%d\n", cnt);
//}

/* ------------------------------------------------------------------------ */
#ifdef __cplusplus
}
#endif
