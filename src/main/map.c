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

#include"commons.h"

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* [HashMap] */

#define K_HASH_INITSIZE 83

typedef struct knh_hentry_t {
	knh_hashcode_t hcode;
	struct knh_hentry_t *next;
	union {
		Object       *key;
		knh_String_t *skey;
		knh_ndata_t   nkey;
		void         *pkey;
	};
	union {
		Object       *value;
		void         *pvalue;
		knh_ndata_t   nvalue;
	};
} knh_hentry_t;

typedef struct knh_hmap_t {
	knh_hentry_t *arena;
	knh_hentry_t *unused;
	knh_hentry_t **hentry;
	size_t arenasize;
	size_t size;
	size_t hmax;
	size_t stat_total;
	size_t stat_hit;
} knh_hmap_t;

static void hmap_setfreelist(knh_hmap_t *hmap, size_t s, size_t e)
{
	DBG_ASSERT(hmap->unused == NULL);
	knh_bzero(hmap->arena + s, (e - s) * sizeof(knh_hentry_t));
	hmap->unused = hmap->arena + s;
	size_t i;
	for(i = s; i < e - 1; i++) {
		hmap->arena[i].hcode = ((knh_hashcode_t)-1);
		hmap->arena[i].nvalue = 0;
		hmap->arena[i].next = hmap->arena + i + 1;
	}
	hmap->arena[e-1].hcode = ((knh_hashcode_t)-1);
	hmap->arena[e-1].nvalue = 0;
	DBG_ASSERT(hmap->arena[e-1].next == NULL);
}

static void hmap_rehash(CTX ctx, knh_hmap_t *hmap)
{
	size_t i, newhmax = hmap->hmax * 2 + 1;
	knh_hentry_t **newhentry = (knh_hentry_t**)KNH_MALLOC(ctx, newhmax * sizeof(knh_hentry_t*));
	knh_bzero(newhentry, newhmax * sizeof(knh_hentry_t*));
	for(i = 0; i < hmap->arenasize / 2; i++) {
		knh_hentry_t *e = hmap->arena + i;
		knh_hashcode_t ni = e->hcode % newhmax;
		e->next = newhentry[ni];
		newhentry[ni] = e;
	}
	KNH_FREE(ctx, hmap->hentry, hmap->hmax * sizeof(knh_hentry_t*));
	hmap->hentry = newhentry;
	hmap->hmax = newhmax;
}

static void hmap_shiftptr(knh_hmap_t *hmap, knh_intptr_t shift)
{
	size_t i, size = hmap->arenasize / 2;
	for(i = 0; i < size; i++) {
		knh_hentry_t *e = hmap->arena + i;
		if(e->next != NULL) {
			e->next = (knh_hentry_t*)(((char*)e->next) + shift);
			DBG_ASSERT(hmap->arena <= e->next && e->next < hmap->arena + size);
		}
	}
}

static knh_hentry_t *new_hentry(CTX ctx, knh_hmap_t *hmap, knh_hashcode_t hcode)
{
	knh_hentry_t *e;
	if(hmap->unused == NULL) {
		size_t oarenasize = hmap->arenasize;
		char *oarena = (char*)hmap->arena;
		hmap->arenasize *= 2;
		hmap->arena = (knh_hentry_t*)KNH_REALLOC(ctx, path, hmap->arena, oarenasize, hmap->arenasize, sizeof(knh_hentry_t));
		DBG_P("extend arena: %p %p size=%d", oarena, hmap->arena, hmap->arenasize);
		if((void*)hmap->arena != oarena) {
			hmap_shiftptr(hmap, (char*)hmap->arena - oarena);
		}
		hmap_setfreelist(hmap, oarenasize, hmap->arenasize);
		hmap_rehash(ctx, hmap);
	}
	e = hmap->unused;
	hmap->unused = e->next;
	e->hcode = hcode;
	e->next = NULL;
	hmap->size++;
	return e;
}

static void hmap_unuse(knh_hmap_t *hmap, knh_hentry_t *e)
{
	e->next = hmap->unused;
	hmap->unused = e;
	e->hcode = ((knh_hashcode_t)-1);
	e->nvalue  = 0;
	hmap->size--;
}

static knh_mapptr_t *hmap_init(CTX ctx, size_t init, const char *path, struct knh_DictMap_t *opt)
{
	knh_hmap_t *hmap = (knh_hmap_t*)KNH_MALLOC(ctx, sizeof(knh_hmap_t));
	knh_bzero(hmap, sizeof(knh_hmap_t));
	if(init < K_HASH_INITSIZE) init = K_HASH_INITSIZE;
	hmap->arenasize = (init * 3) / 4;
	hmap->arena = (knh_hentry_t*)KNH_MALLOC(ctx, hmap->arenasize * sizeof(knh_hentry_t));
	hmap_setfreelist(hmap, 0, hmap->arenasize);
	hmap->hentry = (knh_hentry_t**)KNH_MALLOC(ctx, init * sizeof(knh_hentry_t*));
	knh_bzero(hmap->hentry, init * sizeof(knh_hentry_t*));
	hmap->hmax = init;
	hmap->size = 0;
	return (knh_mapptr_t*)hmap;
}

static void hmap_reftraceOO(CTX ctx, knh_mapptr_t *m FTRARG)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
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

static void hmap_reftraceNO(CTX ctx, knh_mapptr_t *m FTRARG)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	size_t i;
	KNH_ENSUREREF(ctx, hmap->size);
	for(i = 0; i < hmap->hmax; i++) {
		knh_hentry_t *e = hmap->hentry[i];
		while(e != NULL) {
			KNH_ADDREF(ctx, e->value);
			e = e->next;
		}
	}
	KNH_SIZEREF(ctx);
}

static void hmap_reftraceON(CTX ctx, knh_mapptr_t *m FTRARG)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
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

static void hmap_reftraceNN(CTX ctx, knh_mapptr_t *m FTRARG)
{
	KNH_SIZEREF(ctx);
}

static void hmap_free(CTX ctx, knh_mapptr_t *m)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	KNH_FREE(ctx, hmap->arena, sizeof(knh_hentry_t)*(hmap->arenasize));
	KNH_FREE(ctx, hmap->hentry, sizeof(knh_hentry_t*)*(hmap->hmax));
	KNH_FREE(ctx, hmap, sizeof(knh_hmap_t));
}

static knh_hentry_t *hmap_getentry(knh_hmap_t* hmap, knh_hashcode_t hcode)
{
	knh_hentry_t **hlist = hmap->hentry;
	size_t idx = hcode % hmap->hmax;
	knh_hentry_t *e = hlist[idx];
	while(e != NULL) {
		if(e->hcode == hcode) return e;
		e = e->next;
	}
	return NULL;
}

static void hmap_add(knh_hmap_t* hmap, knh_hentry_t *ne)
{
	DBG_ASSERT(ne->next == NULL);
	knh_hentry_t **hlist = hmap->hentry;
	size_t idx = ne->hcode % hmap->hmax;
	ne->next = hlist[idx];
	hlist[idx] = ne;
}

static void hmap_remove(knh_hmap_t* hmap, knh_hentry_t *oe)
{
	knh_hentry_t **hlist = hmap->hentry;
	size_t idx = oe->hcode % hmap->hmax;
	knh_hentry_t *e = hlist[idx];
	while(e != NULL) {
		if(e->next == oe) {
			e->next = oe->next;
			return;
		}
		e = e->next;
	}
	hlist[idx] = oe->next;
}

static void hmap_top(knh_hmap_t* hmap, knh_hentry_t *oe)
{
	DBG_ASSERT(oe->next == NULL);
	knh_hentry_t **hlist = hmap->hentry;
	size_t idx = oe->hcode % hmap->hmax;
	if(hlist[idx] != oe) {
		hmap_remove(hmap, oe);
		oe->next = hlist[idx];
		hlist[idx] = oe;
	}
}

static knh_bool_t hmap_getOO(CTX ctx, knh_mapptr_t* m, knh_sfp_t *ksfp, knh_sfp_t *rsfp)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_Object_t *key = ksfp[0].o;
	knh_hashcode_t hcode = O_cTBL(key)->cdef->hashCode(ctx, ksfp[0].p);
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode && knh_Object_compareTo(key, e->key) == 0) {
			KNH_SETv(ctx, rsfp[0].o, e->value);
			return 1;
		}
		e = e->next;
	}
	return 0;
}

static knh_bool_t hmap_getON(CTX ctx, knh_mapptr_t* m, knh_sfp_t *ksfp, knh_sfp_t *rsfp)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_Object_t *key = ksfp[0].o;
	knh_hashcode_t hcode = O_cTBL(key)->cdef->hashCode(ctx, ksfp[0].p);
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode && knh_Object_compareTo(key, e->key) == 0) {
			rsfp[0].ndata = e->nvalue;
			return 1;
		}
		e = e->next;
	}
	return 0;
}

#define knh_String_equals(STR, t)   (knh_bytes_equals(S_tobytes(STR), t))

static knh_bool_t hmap_getSO(CTX ctx, knh_mapptr_t* m, knh_sfp_t *ksfp, knh_sfp_t *rsfp)
{
	DBG_ASSERT(IS_bString(ksfp[0].s));
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_bytes_t k = S_tobytes(ksfp[0].s);
	knh_hashcode_t hcode = knh_hash(0, k.text, k.len);
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode && knh_String_equals(e->skey, k)) {
			KNH_SETv(ctx, rsfp[0].o, e->value);
			return 1;
		}
		e = e->next;
	}
	return 0;
}

static knh_bool_t hmap_getSN(CTX ctx, knh_mapptr_t* m, knh_sfp_t *ksfp, knh_sfp_t *rsfp)
{
	DBG_ASSERT(IS_bString(ksfp[0].s));
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_bytes_t k = S_tobytes(ksfp[0].s);
	knh_hashcode_t hcode = knh_hash(0, k.text, k.len);
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode && knh_String_equals(e->skey, k)) {
			rsfp[0].ndata = e->nvalue;
			return 1;
		}
		e = e->next;
	}
	return 0;
}

static knh_bool_t hmap_getNO(CTX ctx, knh_mapptr_t* m, knh_sfp_t *ksfp, knh_sfp_t *rsfp)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_hashcode_t hcode = (knh_hashcode_t)ksfp[0].ndata;
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode) {
			KNH_SETv(ctx, rsfp[0].o, e->value);
			return 1;
		}
		e = e->next;
	}
	return 0;
}

static knh_bool_t hmap_getNN(CTX ctx, knh_mapptr_t* m, knh_sfp_t *ksfp, knh_sfp_t *rsfp)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_hashcode_t hcode = (knh_hashcode_t)ksfp[0].ndata;
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode) {
			rsfp[0].ndata = e->nvalue;
			return 1;
		}
		e = e->next;
	}
	return 0;
}

static void hmap_setOO(CTX ctx, knh_mapptr_t* m, knh_sfp_t *kvsfp)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_Object_t *key = kvsfp[0].o;
	knh_hashcode_t hcode = O_cTBL(key)->cdef->hashCode(ctx, kvsfp[0].p);
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode && knh_Object_compareTo(key, e->key) == 0) {
			KNH_SETv(ctx, e->value, kvsfp[1].o);
			return;
		}
		e = e->next;
	}
	e = new_hentry(ctx, hmap, hcode);
	KNH_INITv(e->key, kvsfp[0].o);
	KNH_INITv(e->value, kvsfp[1].o);
	hmap_add(hmap, e);
}

static void hmap_setON(CTX ctx, knh_mapptr_t* m, knh_sfp_t *kvsfp)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_Object_t *key = kvsfp[0].o;
	knh_hashcode_t hcode = O_cTBL(key)->cdef->hashCode(ctx, kvsfp[0].p);
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode && knh_Object_compareTo(key, e->key) == 0) {
			e->nvalue = kvsfp[0].ndata;
			return;
		}
		e = e->next;
	}
	e = new_hentry(ctx, hmap, hcode);
	KNH_INITv(e->key, kvsfp[0].o);
	e->nvalue = kvsfp[1].ndata;
	hmap_add(hmap, e);
}

static void hmap_setSO(CTX ctx, knh_mapptr_t* m, knh_sfp_t *kvsfp)
{
	DBG_ASSERT(IS_bString(kvsfp[0].s));
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_bytes_t k = S_tobytes(kvsfp[0].s);
	knh_hashcode_t hcode = knh_hash(0, k.text, k.len);
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode && knh_String_equals(e->skey, k)) {
			KNH_SETv(ctx, e->value, kvsfp[1].o);
			return;
		}
		e = e->next;
	}
	e = new_hentry(ctx, hmap, hcode);
	KNH_INITv(e->key, kvsfp[0].o);
	KNH_INITv(e->value, kvsfp[1].o);
	hmap_add(hmap, e);
}

static void hmap_setSN(CTX ctx, knh_mapptr_t* m, knh_sfp_t *kvsfp)
{
	DBG_ASSERT(IS_bString(kvsfp[0].s));
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_bytes_t k = S_tobytes(kvsfp[0].s);
	knh_hashcode_t hcode = knh_hash(0, k.text, k.len);
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode && knh_String_equals(e->skey, k)) {
			e->nvalue = kvsfp[0].ndata;
			return;
		}
		e = e->next;
	}
	e = new_hentry(ctx, hmap, hcode);
	KNH_INITv(e->key, kvsfp[0].o);
	e->nvalue = kvsfp[1].ndata;
	hmap_add(hmap, e);
}

static void hmap_setNO(CTX ctx, knh_mapptr_t* m, knh_sfp_t *kvsfp)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_hashcode_t hcode = (knh_hashcode_t)kvsfp[0].ndata;
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode) {
			KNH_SETv(ctx, e->value, kvsfp[1].o);
			return;
		}
		e = e->next;
	}
	e = new_hentry(ctx, hmap, hcode);
	KNH_INITv(e->key, kvsfp[0].o);
	KNH_INITv(e->value, kvsfp[1].o);
	hmap_add(hmap, e);
}

static void hmap_setNN(CTX ctx, knh_mapptr_t* m, knh_sfp_t *kvsfp)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_hashcode_t hcode = (knh_hashcode_t)kvsfp[0].ndata;
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode) {
			e->nvalue = kvsfp[0].ndata;
			return;
		}
		e = e->next;
	}
	e = new_hentry(ctx, hmap, hcode);
	KNH_INITv(e->key, kvsfp[0].o);
	e->nvalue = kvsfp[1].ndata;
	hmap_add(hmap, e);
}

static void hmap_removeOO(CTX ctx, knh_mapptr_t* m, knh_sfp_t *ksfp)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_Object_t *key = ksfp[0].o;
	knh_hashcode_t hcode = O_cTBL(key)->cdef->hashCode(ctx, ksfp[0].p);
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode && knh_Object_compareTo(key, e->key) == 0) {
			KNH_FINALv(ctx, e->key);
			KNH_FINALv(ctx, e->value);
			hmap_remove(hmap, e);
			hmap_unuse(hmap, e);
			return;
		}
		e = e->next;
	}
}

static void hmap_removeON(CTX ctx, knh_mapptr_t* m, knh_sfp_t *ksfp)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_Object_t *key = ksfp[0].o;
	knh_hashcode_t hcode = O_cTBL(key)->cdef->hashCode(ctx, ksfp[0].p);
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode && knh_Object_compareTo(key, e->key) == 0) {
			KNH_FINALv(ctx, e->key);
			hmap_remove(hmap, e);
			hmap_unuse(hmap, e);
			return;
		}
		e = e->next;
	}
}

#define knh_String_equals(STR, t)   (knh_bytes_equals(S_tobytes(STR), t))

static void hmap_removeSO(CTX ctx, knh_mapptr_t* m, knh_sfp_t *ksfp)
{
	DBG_ASSERT(IS_bString(ksfp[0].s));
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_bytes_t k = S_tobytes(ksfp[0].s);
	knh_hashcode_t hcode = knh_hash(0, k.text, k.len);
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode && knh_String_equals(e->skey, k)) {
			KNH_FINALv(ctx, e->key);
			KNH_FINALv(ctx, e->value);
			hmap_remove(hmap, e);
			hmap_unuse(hmap, e);
			return;
		}
		e = e->next;
	}
}

static void hmap_removeSN(CTX ctx, knh_mapptr_t* m, knh_sfp_t *ksfp)
{
	DBG_ASSERT(IS_bString(ksfp[0].s));
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_bytes_t k = S_tobytes(ksfp[0].s);
	knh_hashcode_t hcode = knh_hash(0, k.text, k.len);
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode && knh_String_equals(e->skey, k)) {
			KNH_FINALv(ctx, e->key);
			hmap_remove(hmap, e);
			hmap_unuse(hmap, e);
			return;
		}
		e = e->next;
	}
}

static void hmap_removeNO(CTX ctx, knh_mapptr_t* m, knh_sfp_t *ksfp)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_hashcode_t hcode = (knh_hashcode_t)ksfp[0].ndata;
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode) {
			KNH_FINALv(ctx, e->value);
			hmap_remove(hmap, e);
			hmap_unuse(hmap, e);
			return;
		}
		e = e->next;
	}
}

static void hmap_removeNN(CTX ctx, knh_mapptr_t* m, knh_sfp_t *ksfp)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	knh_hashcode_t hcode = (knh_hashcode_t)ksfp[0].ndata;
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	while(e != NULL) {
		if(e->hcode == hcode) {
			hmap_remove(hmap, e);
			hmap_unuse(hmap, e);
			return;
		}
		e = e->next;
	}
}

static size_t hmap_size(CTX ctx, knh_mapptr_t* m)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	return hmap->size;
}

static knh_bool_t hmap_nextOO(CTX ctx, knh_mapptr_t *m, knh_nitr_t *mitr, knh_sfp_t *rsfp)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	size_t i;
	for(i = mitr->index; i < hmap->arenasize; i++) {
		knh_hentry_t *e = hmap->arena + i;
		if(e->hcode == ((knh_hashcode_t)-1) && e->nvalue == 0) continue;
		KNH_SETv(ctx, rsfp[0].o, e->key);
		KNH_SETv(ctx, rsfp[1].o, e->value);
		mitr->index = i + 1;
		return 1;
	}
	mitr->index = hmap->arenasize;
	return 0;
}

static knh_bool_t hmap_nextON(CTX ctx, knh_mapptr_t *m, knh_nitr_t *mitr, knh_sfp_t *rsfp)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	size_t i;
	for(i = mitr->index; i < hmap->arenasize; i++) {
		knh_hentry_t *e = hmap->arena + i;
		if(e->hcode == ((knh_hashcode_t)-1) && e->nvalue == 0) continue;
		KNH_SETv(ctx, rsfp[0].o, e->key);
		rsfp[1].ndata = e->nvalue;
		mitr->index = i + 1;
		return 1;
	}
	mitr->index = hmap->arenasize;
	return 0;
}

static knh_bool_t hmap_nextNO(CTX ctx, knh_mapptr_t *m, knh_nitr_t *mitr, knh_sfp_t *rsfp)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	size_t i;
	for(i = mitr->index; i < hmap->arenasize; i++) {
		knh_hentry_t *e = hmap->arena + i;
		if(e->hcode == ((knh_hashcode_t)-1) && e->nvalue == 0) continue;
		rsfp[0].ndata = e->nkey;
		KNH_SETv(ctx, rsfp[1].o, e->value);
		mitr->index = i + 1;
		return 1;
	}
	mitr->index = hmap->arenasize;
	return 0;
}

static knh_bool_t hmap_nextNN(CTX ctx, knh_mapptr_t *m, knh_nitr_t *mitr, knh_sfp_t *rsfp)
{
	knh_hmap_t *hmap = (knh_hmap_t*)m;
	size_t i;
	for(i = mitr->index; i < hmap->arenasize; i++) {
		knh_hentry_t *e = hmap->arena + i;
		if(e->hcode == ((knh_hashcode_t)-1) && e->nvalue == 0) continue;
		rsfp[0].ndata = e->nkey;
		rsfp[1].ndata = e->nvalue;
		mitr->index = i + 1;
		return 1;
	}
	mitr->index = hmap->arenasize;
	return 0;
}

static const knh_MapDPI_t* hmap_config(CTX ctx, knh_class_t p1, knh_class_t p2);

static const knh_MapDPI_t HMAP_OO = {
	K_DSPI_MAP, "hash",
	hmap_config, hmap_init, hmap_reftraceOO, hmap_free,
	hmap_getOO, hmap_setOO, hmap_removeOO, hmap_size, hmap_nextOO,
};
static const knh_MapDPI_t HMAP_ON = {
	K_DSPI_MAP, "hash",
	hmap_config, hmap_init, hmap_reftraceON, hmap_free,
	hmap_getON, hmap_setON, hmap_removeON, hmap_size, hmap_nextON,
};
static const knh_MapDPI_t HMAP_SO = {
	K_DSPI_MAP, "hash",
	hmap_config, hmap_init, hmap_reftraceOO, hmap_free,
	hmap_getSO, hmap_setSO, hmap_removeSO, hmap_size, hmap_nextOO,
};
static const knh_MapDPI_t HMAP_SN = {
	K_DSPI_MAP, "hash",
	hmap_config, hmap_init, hmap_reftraceON, hmap_free,
	hmap_getSN, hmap_setSN, hmap_removeSN, hmap_size, hmap_nextON,
};
static const knh_MapDPI_t HMAP_NO = {
	K_DSPI_MAP, "hash",
	hmap_config, hmap_init, hmap_reftraceNO, hmap_free,
	hmap_getNO, hmap_setNO, hmap_removeNO, hmap_size, hmap_nextNO,
};
static const knh_MapDPI_t HMAP_NN = {
	K_DSPI_MAP, "hash",
	hmap_config, hmap_init, hmap_reftraceNN, hmap_free,
	hmap_getNN, hmap_setNN, hmap_removeNN, hmap_size, hmap_nextNN,
};

static const knh_MapDPI_t* hmap_config(CTX ctx, knh_class_t p1, knh_class_t p2)
{
	if(IS_Tunbox(p2)) {
		if(IS_Tstr(p1)) {
			return &HMAP_SN;
		}
		else if(IS_Tunbox(p1)) {
			return &HMAP_NN;
		}
		return &HMAP_ON;
	}
	else {
		if(IS_Tstr(p1)) {
			return &HMAP_SO;
		}
		else if(IS_Tunbox(p1)) {
			return &HMAP_NO;
		}
		return &HMAP_OO;
	}
}

knh_PtrMap_t* new_PtrMap(CTX ctx, size_t max)
{
	knh_Map_t *m = new_H(Map);
	m->spi = &HMAP_NN;
	m->mapptr = m->spi->init(ctx, max, NULL, NULL);
	return (knh_PtrMap_t*)m;
}

void* knh_PtrMap_get(CTX ctx, knh_PtrMap_t *pm, void *keyptr)
{
	knh_hmap_t *hmap = (knh_hmap_t*)pm->mapptr;
	knh_hashcode_t hcode = (knh_hashcode_t)keyptr;
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	if(e != NULL) {
		hmap_top(hmap, e);
		return e->pvalue;
	}
	return NULL;
}

void knh_PtrMap_add(CTX ctx, knh_PtrMap_t *pm, void *keyptr, void *valueptr)
{
	knh_hmap_t *hmap = (knh_hmap_t*)pm->mapptr;
	knh_hashcode_t hcode = (knh_hashcode_t)keyptr;
	knh_hentry_t *e = new_hentry(ctx, hmap, hcode);
	e->pvalue = valueptr;
	hmap_add(hmap, e);
}

void knh_PtrMap_rm(CTX ctx, knh_PtrMap_t *pm, void *keyptr)
{
	knh_hmap_t *hmap = (knh_hmap_t*)pm->mapptr;
	knh_hashcode_t hcode = (knh_hashcode_t)keyptr;
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	DBG_ASSERT(e != NULL);
	hmap_remove(hmap, e);
	hmap_unuse(hmap, e);
}

size_t knh_PtrMap_size(knh_PtrMap_t *pm)
{
	knh_hmap_t *hmap = (knh_hmap_t*)pm->mapptr;
	return hmap->size;
}

void knh_PtrMap_stat(CTX ctx, knh_PtrMap_t *pm, const char *name)
{
	knh_hmap_t *hmap = (knh_hmap_t*)pm->mapptr;
	if(hmap->stat_total > 9) {
		knh_logprintf("STAT", knh_isVerbosePref(), "size=%lu, name=%s count=%d %f%%", hmap->size, name, hmap->stat_total, 100.0 * hmap->stat_hit / hmap->stat_total);
//		LOGSFPDATA = {sDATA("name", name), /*fDATA("rate", hmap->stat_hit / hmap->stat_total),*/ iDATA("count", hmap->stat_total)};
//		LIB_STAT("konoha.PtrMap");
	}
}

knh_String_t* knh_PtrMap_getS(CTX ctx, knh_PtrMap_t *pm, const char *k, size_t len)
{
	knh_hmap_t *hmap = (knh_hmap_t*)pm->mapptr;
	knh_hashcode_t hcode = knh_hash(0, k, len);
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	hmap->stat_total++;
	while(e != NULL) {
		const char *es = (const char*)e->pkey;
		if(e->hcode == hcode && es[len] == 0 && strncmp(k, es, len) == 0) {
			hmap->stat_hit++;
			return (knh_String_t*)e->pvalue;
		}
		e = e->next;
	}
	return NULL;
}

void knh_PtrMap_addS(CTX ctx, knh_PtrMap_t *pm, knh_String_t *v)
{
	knh_hmap_t *hmap = (knh_hmap_t*)pm->mapptr;
	const char *k = S_totext(v);
	size_t len = knh_strlen(k);
	knh_hashcode_t hcode = knh_hash(0, k, len);
	knh_hentry_t *e = new_hentry(ctx, hmap, hcode);
	DBG_ASSERT(IS_bString(v));
	e->pkey = (void*)k;
	e->pvalue = (void*)v;
	hmap_add(hmap, e);
}

void knh_PtrMap_rmS(CTX ctx, knh_PtrMap_t *pm, knh_String_t *s)
{
	knh_hmap_t *hmap = (knh_hmap_t*)pm->mapptr;
	knh_bytes_t t = S_tobytes(s);
	knh_hashcode_t hcode = knh_hash(0, t.text, t.len);
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	DBG_ASSERT(IS_bString(s));
	while(e != NULL) {
		if(e->hcode == hcode && e->pvalue == (void*)s) {
			hmap_remove(hmap, e);
			hmap_unuse(hmap, e);
			return;
		}
		e = e->next;
	}
	DBG_P("not found removed %x '%s' %p", hcode, t.text, s);
	//KNH_ASSERT(ctx == NULL);
}

knh_Int_t* knh_PtrMap_getI(CTX ctx, knh_PtrMap_t *pm, knh_ndata_t k)
{
	knh_hmap_t *hmap = (knh_hmap_t*)pm->mapptr;
	knh_hashcode_t hcode = (knh_hashcode_t)k;
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	hmap->stat_total++;
	while(e != NULL) {
		if(e->hcode == hcode DBLNDATA_(&& e->nkey == k)) {
			hmap->stat_hit++;
			return (knh_Int_t*)e->pvalue;
		}
		e = e->next;
	}
	return NULL;
}

void knh_PtrMap_addI(CTX ctx, knh_PtrMap_t *pm, knh_Int_t *v)
{
	knh_hmap_t *hmap = (knh_hmap_t*)pm->mapptr;
	knh_ndata_t k = v->n.data;
	knh_hashcode_t hcode = (knh_hashcode_t)k;
	knh_hentry_t *e = new_hentry(ctx, hmap, hcode);
	e->nkey = k;
	e->pvalue = (void*)v;
	hmap_add(hmap, e);
}

void knh_PtrMap_rmI(CTX ctx, knh_PtrMap_t *pm, knh_Int_t *v)
{
	knh_hmap_t *hmap = (knh_hmap_t*)pm->mapptr;
	knh_hentry_t *e = hmap_getentry(hmap, (knh_hashcode_t)v->n.data);
	while(e != NULL) {
		if(e->pvalue == (void*)v) {
			hmap_remove(hmap, e);
			hmap_unuse(hmap, e);
			return;
		}
		e = e->next;
	}
	DBG_P("not found removed %d %p", (knh_hashcode_t)v->n.data, v);
	//KNH_ASSERT(ctx == NULL);
}

knh_Method_t* knh_PtrMap_getM(CTX ctx, knh_PtrMap_t *pm, knh_hashcode_t hcode)
{
	knh_hmap_t *hmap = (knh_hmap_t*)pm->mapptr;
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	hmap->stat_total++;
	while(e != NULL) {
		if(e->hcode == hcode) {
			hmap->stat_hit++;
			return (knh_Method_t*)e->pvalue;
		}
		e = e->next;
	}
	return NULL;
}

void knh_PtrMap_addM(CTX ctx, knh_PtrMap_t *pm, knh_hashcode_t hcode, knh_Method_t *v)
{
	knh_hmap_t *hmap = (knh_hmap_t*)pm->mapptr;
	knh_hentry_t *e = new_hentry(ctx, hmap, hcode);
	DBG_ASSERT(IS_bMethod(v));
	e->pvalue = (void*)v;
	hmap_add(hmap, e);
}

void knh_PtrMap_rmM(CTX ctx, knh_PtrMap_t *pm, knh_Method_t *mtd)
{
	knh_hmap_t *hmap = (knh_hmap_t*)pm->mapptr;
	knh_hashcode_t hcode = hashcode_mtd(mtd->cid, mtd->mn, K_MTDCACHE_SIZE);
	knh_hentry_t *e = hmap_getentry(hmap, hcode);
	DBG_ASSERT(IS_bMethod(mtd));
	while(e != NULL) {
		if(e->hcode == hcode && e->pvalue == (void*)mtd) {
			hmap_remove(hmap, e);
			hmap_unuse(hmap, e);
			return;
		}
		e = e->next;
	}
	DBG_P("not found removed %x %d.%d", hcode, mtd->cid, mtd->mn);
	//KNH_ASSERT(ctx == NULL);
}

/* ------------------------------------------------------------------------ */
/* DictMap */

#define K_USE_FASTDMAP(STMT)  STMT

typedef struct knh_dentry_t {
K_USE_FASTDMAP(knh_uint64_t ukey;)
	union {
		knh_String_t  *key;
		knh_intptr_t   ikey;
		knh_floatptr_t fkey;
		knh_ndata_t    nkey;
	};
	union {
		Object           *value;
		knh_ndata_t    nvalue;
	};
} knh_dentry_t;

typedef struct knh_dmap_t {
	knh_dentry_t *dentry;
	size_t size;
	size_t capacity;
K_USE_FASTDMAP(knh_uint64_t (*strkeyuint)(knh_bytes_t);)
	int (*dentrycmpr)(const void *, const void *);
	int (*strcmpr)(knh_bytes_t, knh_bytes_t);
	size_t sorted;
	const char *DBGNAME;
} knh_dmap_t ;

#define UNSORTED 8
#define knh_map_dmap(m)        ((knh_dmap_t*)m)
#define knh_map_dentry(m)      (((knh_dmap_t*)m)->dentry)

static knh_uint64_t knh_struint64(knh_bytes_t t)
{
	const unsigned char *p = (const unsigned char*)t.text;
	knh_uint64_t n = 0;
	if(t.len > 0) {
		switch(t.len) {
		default: n |= (((knh_uint64_t)p[7]) << (64-64)); /* FALLTHROUGH */
		case 7 : n |= (((knh_uint64_t)p[6]) << (64-56)); /* FALLTHROUGH */
		case 6 : n |= (((knh_uint64_t)p[5]) << (64-48)); /* FALLTHROUGH */
		case 5 : n |= (((knh_uint64_t)p[4]) << (64-40)); /* FALLTHROUGH */
		case 4 : n |= (((knh_uint64_t)p[3]) << (64-32)); /* FALLTHROUGH */
		case 3 : n |= (((knh_uint64_t)p[2]) << (64-24)); /* FALLTHROUGH */
		case 2 : n |= (((knh_uint64_t)p[1]) << (64-16)); /* FALLTHROUGH */
		case 1 : n |= (((knh_uint64_t)p[0]) << (64- 8));
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

static knh_mapptr_t *dmap_init(CTX ctx, size_t init, const char *path, struct knh_DictMap_t *opt)
{
	knh_dmap_t *dmap = (knh_dmap_t*)KNH_MALLOC(ctx, sizeof(knh_dmap_t));
	if(init < K_HASH_INITSIZE) init = 4;
	dmap->dentry = (knh_dentry_t*)KNH_REALLOC(ctx, NULL, NULL, 0, init, sizeof(knh_dentry_t));
	dmap->capacity = init;
	dmap->size = 0;
	dmap->sorted = 0;
	dmap->strcmpr = knh_bytes_strcmp;
	K_USE_FASTDMAP(dmap->strkeyuint = knh_struint64;)
	dmap->dentrycmpr = dentry_strcmp;
	return dmap;
}

static void dmap_reftraceOO(CTX ctx, knh_mapptr_t *m FTRARG)
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

static void dmap_free(CTX ctx, knh_mapptr_t *m)
{
	knh_dmap_t *dmap = knh_map_dmap(m);
	//DBG_P("DBGNAME=%s", dmap->DBGNAME);
	KNH_FREE(ctx, dmap->dentry, sizeof(knh_dentry_t)*dmap->capacity);
	KNH_FREE(ctx, dmap, sizeof(knh_dmap_t));
}

static size_t dmap_size(CTX ctx, knh_mapptr_t* m)
{
	knh_dmap_t *dmap = knh_map_dmap(m);
	return dmap->size;
}

static knh_bool_t dmap_nextOO(CTX ctx, knh_mapptr_t *m, knh_nitr_t* mitr, knh_sfp_t *rsfp)
{
	knh_dmap_t *dmap = knh_map_dmap(m);
	if(mitr->index < dmap->size) {
		knh_dentry_t *dentry = knh_map_dentry(m);
		KNH_SETv(ctx, rsfp[0].o, dentry[mitr->index].key);
		KNH_SETv(ctx, rsfp[1].o, dentry[mitr->index].value);
		mitr->index += 1;
		return 1;
	}
	return 0;
}

/* ------------------------------------------------------------------------ */
/* String */

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

static knh_bool_t dmap_getSO(CTX ctx, knh_mapptr_t* m, knh_sfp_t *ksfp, knh_sfp_t *rsfp)
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

#define dmap_grow(ctx, dmap) {\
		if(!(dmap->size < dmap->capacity)) {\
			size_t newsize = k_grow(dmap->capacity);\
			dmap->dentry = (knh_dentry_t*)KNH_REALLOC(ctx, dmap->DBGNAME, dmap->dentry, dmap->capacity, newsize, sizeof(knh_dentry_t));\
			dmap->capacity = newsize;\
		}\
	}\

#define dmap_sort(dmap) \
	if(!((dmap->size - dmap->sorted) < UNSORTED)) {\
		/*DBG_P("SORTED %s sorted=%d, size=%d", dmap->DBGNAME, dmap->sorted, dmap->size); */\
		knh_qsort(dmap->dentry, dmap->size, sizeof(knh_dentry_t), dmap->dentrycmpr);\
		dmap->sorted = dmap->size;\
	}\


//static void dmap_sort_(knh_dmap_t *dmap, int isforced)
//{
//	if(isforced || dmap->size != dmap->sorted) {
//		//DBG_P("SORTED* %s, sorted=%d, size=%d", dmap->DBGNAME, dmap->sorted, dmap->size);
//		knh_qsort(dmap->dentry, dmap->size, sizeof(knh_dentry_t), dmap->dentrycmpr);
//		dmap->sorted = dmap->size;
//	}
//}

static void dmap_addSO(CTX ctx, knh_dmap_t *dmap, knh_sfp_t *kvsfp)
{
	size_t loc = dmap->size;
	dmap_grow(ctx, dmap);
	KNH_INITv(dmap->dentry[loc].key, kvsfp[0].s);
	KNH_INITv(dmap->dentry[loc].value, kvsfp[1].o);
	K_USE_FASTDMAP(dmap->dentry[loc].ukey = dmap->strkeyuint(S_tobytes(kvsfp[0].s)));
	dmap->size++;
}

static void dmap_setSO(CTX ctx, knh_mapptr_t* m, knh_sfp_t* kvsfp)
{
	knh_dmap_t *dmap = knh_map_dmap(m);
	knh_bytes_t key = S_tobytes(kvsfp[0].s);
	knh_index_t loc = dmap_index(dmap, 0, dmap->sorted, key);
	if(loc == -1) {
		loc = dmap_index(dmap, dmap->sorted, dmap->size, key);
		if(loc == -1) {
			dmap_addSO(ctx, dmap, kvsfp);
			dmap_sort(dmap);
			return;
		}
	}
	KNH_SETv(ctx, dmap->dentry[loc].value, kvsfp[1].o);
}

static void dmap_removeSO(CTX ctx, knh_mapptr_t* m, knh_sfp_t *kvsfp)
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

static const knh_MapDPI_t* dmap_config(CTX ctx, knh_class_t p1, knh_class_t p2);

static const knh_MapDPI_t DMAP_SO = {
	K_DSPI_MAP, "dictionary",
	dmap_config, dmap_init, dmap_reftraceOO, dmap_free,
	dmap_getSO, dmap_setSO, dmap_removeSO, dmap_size, dmap_nextOO,
};

static void dmap_reftraceON(CTX ctx, knh_mapptr_t *m FTRARG)
{
	knh_dmap_t *dmap = knh_map_dmap(m);
	knh_dentry_t *dentry = knh_map_dentry(m);
	size_t i;
	KNH_ENSUREREF(ctx, dmap->size);
	for(i = 0; i < dmap->size; i++) {
		KNH_ADDREF(ctx, dentry[i].key);
	}
	KNH_SIZEREF(ctx);
}

static knh_bool_t dmap_nextON(CTX ctx, knh_mapptr_t *m, knh_nitr_t* mitr, knh_sfp_t *rsfp)
{
	knh_dmap_t *dmap = knh_map_dmap(m);
	if(mitr->index < dmap->size) {
		knh_dentry_t *dentry = knh_map_dentry(m);
		KNH_SETv(ctx, rsfp[0].o, dentry[mitr->index].key);
		rsfp[1].ndata = dentry[mitr->index].nvalue; /* thanks, ide */
		mitr->index += 1;
		return 1;
	}
	return 0;
}

static knh_bool_t dmap_getSN(CTX ctx, knh_mapptr_t* m, knh_sfp_t *ksfp, knh_sfp_t *rsfp)
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

static void dmap_addSN(CTX ctx, knh_dmap_t *dmap, knh_sfp_t *kvsfp)
{
	size_t loc = dmap->size;
	dmap_grow(ctx, dmap);
	KNH_INITv(dmap->dentry[loc].key, kvsfp[0].s);
	dmap->dentry[loc].nvalue = kvsfp[1].ndata;
	K_USE_FASTDMAP(dmap->dentry[loc].ukey = dmap->strkeyuint(S_tobytes(kvsfp[0].s)));
	dmap->size++;
}

static void dmap_setSN(CTX ctx, knh_mapptr_t* m, knh_sfp_t* kvsfp)
{
	knh_dmap_t *dmap = knh_map_dmap(m);
	knh_bytes_t key = S_tobytes(kvsfp[0].s);
	knh_index_t loc = dmap_index(dmap, 0, dmap->sorted, key);
	if(loc == -1) {
		loc = dmap_index(dmap, dmap->sorted, dmap->size, key);
		if(loc == -1) {
			dmap_addSN(ctx, dmap, kvsfp);
			dmap_sort(dmap);
			return;
		}
	}
	dmap->dentry[loc].nvalue = kvsfp[1].ndata;
}

static void dmap_removeSN(CTX ctx, knh_mapptr_t* m, knh_sfp_t *kvsfp)
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

static const knh_MapDPI_t DMAP_SN = {
	K_DSPI_MAP, "dictionary",
	dmap_config, dmap_init, dmap_reftraceON, dmap_free,
	dmap_getSN, dmap_setSN, dmap_removeSN, dmap_size, dmap_nextON,
};

static const knh_MapDPI_t* dmap_config(CTX ctx, knh_class_t p1, knh_class_t p2)
{
	if(IS_Tstr(p1)) {
		if(IS_Tunbox(p2)) {
			return &DMAP_SN;
		}
		return &DMAP_SO;
	}
	return NULL;
}

/* ------------------------------------------------------------------------- */
/* [casecmp] */

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
	m->spi = &DMAP_SO;
	m->mapptr = m->spi->init(ctx, capacity, NULL, NULL);
	DBG_ASSERT(m->mapptr != NULL);
	knh_dmap_t *dmap = (knh_dmap_t*)m->mapptr;
	if(isCaseMap) dmap_case(dmap);
	dmap->DBGNAME = DBGNAME;
	return (knh_DictMap_t*)m;
}

knh_DictMap_t* knh_toDictMap(CTX ctx, knh_Map_t *m, int isCreation)
{
	if(m->spi != &DMAP_SO) {
		return (isCreation) ? new_DictMap0(ctx, 0, 1/*isCaseMap*/, __FUNCTION__) : NULL;
	}
	return (knh_DictMap_t*)m;
}

knh_DictSet_t* new_DictSet0_(CTX ctx, size_t capacity, int isCaseMap, const char *DBGNAME)
{
	knh_Map_t *m = new_H(Map);
	m->spi = &DMAP_SN;
	m->mapptr = m->spi->init(ctx, capacity, NULL, NULL);
	DBG_ASSERT(m->mapptr != NULL);
	knh_dmap_t *dmap = (knh_dmap_t*)m->mapptr;
	if(isCaseMap) dmap_case(dmap);
	dmap->DBGNAME = DBGNAME;
	return (knh_DictSet_t*)m;
}

// @see ClassCONST_man

KNHAPI2(knh_String_t*) knh_DictMap_keyAt(knh_DictMap_t *m, size_t n)
{
	knh_dmap_t *dmap = (knh_dmap_t*)m->mapptr;
	DBG_ASSERT(n < knh_Map_size(m));
	return dmap->dentry[n].key;
}

KNHAPI2(Object*) knh_DictMap_valueAt(knh_DictMap_t *m, size_t n)
{
	knh_dmap_t *dmap = (knh_dmap_t*)m->mapptr;
	DBG_ASSERT(n < knh_Map_size(m));
	return dmap->dentry[n].value;
}

knh_uintptr_t knh_DictSet_valueAt(knh_DictSet_t *m, size_t n)
{
	knh_dmap_t *dmap = (knh_dmap_t*)m->mapptr;
	DBG_ASSERT(n < knh_Map_size(m));
	return (knh_uintptr_t)dmap->dentry[n].nvalue;
}

knh_index_t knh_DictMap_index(knh_DictMap_t *m, knh_bytes_t key)
{
	knh_dmap_t *dmap = (knh_dmap_t*)m->mapptr;
	knh_index_t loc = dmap_index(dmap, 0, dmap->sorted, key);
	if(loc == -1) {
		loc = dmap_index(dmap, dmap->sorted, dmap->size, key);
	}
	return loc;
}

Object *knh_DictMap_getNULL(CTX ctx, knh_DictMap_t *m, knh_bytes_t key)
{
	knh_dmap_t *dmap = (knh_dmap_t*)m->mapptr;
	knh_index_t loc = dmap_index(dmap, 0, dmap->sorted, key);
	if(loc == -1) {
		loc = dmap_index(dmap, dmap->sorted, dmap->size, key);
	}
	return (loc == -1) ? NULL : dmap->dentry[loc].value;
}

knh_uintptr_t knh_DictSet_get(CTX ctx, knh_DictSet_t *m, knh_bytes_t key)
{
	knh_dmap_t *dmap = (knh_dmap_t*)m->mapptr;
	knh_index_t loc = dmap_index(dmap, 0, dmap->sorted, key);
	if(loc == -1) {
		loc = dmap_index(dmap, dmap->sorted, dmap->size, key);
	}
	return (loc == -1) ? 0 : (knh_uintptr_t)dmap->dentry[loc].nvalue;
}

void knh_DictMap_set_(CTX ctx, knh_DictMap_t *m, knh_String_t *key, dynamic *v)
{
	knh_sfp_t* kvsfp = ctx->esp;
	KNH_SETv(ctx, kvsfp[0].o, key);
	KNH_SETv(ctx, kvsfp[1].o, v);
	m->spi->set(ctx, m->mapptr, kvsfp);
}

void knh_DictSet_set(CTX ctx, knh_DictSet_t *m, knh_String_t *key, knh_uintptr_t n)
{
	knh_sfp_t* kvsfp = ctx->esp;
	KNH_SETv(ctx, kvsfp[0].o, key);
	kvsfp[1].ivalue = n;
	m->spi->set(ctx, m->mapptr, kvsfp);
}

void knh_DictMap_append(CTX ctx, knh_DictMap_t *m, knh_String_t *key, knh_Object_t *v)
{
	knh_sfp_t* kvsfp = ctx->esp;
	knh_dmap_t *dmap = (knh_dmap_t*)m->mapptr;
	KNH_SETv(ctx, kvsfp[0].o, key);
	KNH_SETv(ctx, kvsfp[1].o, v);
	dmap_addSO(ctx, dmap, kvsfp);
}

//void knh_DictMap_sort(CTX ctx, knh_DictMap_t *m)
//{
//	knh_dmap_t *dmap = (knh_dmap_t*)m->mapptr;
//	dmap_sort(dmap);
//}

void knh_DictSet_append(CTX ctx, knh_DictSet_t *m, knh_String_t *key, knh_uintptr_t n)
{
	knh_sfp_t* kvsfp = ctx->esp;
	knh_dmap_t *dmap = (knh_dmap_t*)m->mapptr;
	KNH_SETv(ctx, kvsfp[0].o, key);
	kvsfp[1].ivalue = n;
	dmap_addSN(ctx, dmap, kvsfp);
}

void knh_DictSet_sort(CTX ctx, knh_DictSet_t *m)
{
	knh_dmap_t *dmap = (knh_dmap_t*)m->mapptr;
	dmap_sort(dmap);
}

/* ------------------------------------------------------------------------ */
/* API2 */

KNHAPI2(knh_Map_t*) new_DataMap(CTX ctx)
{
	knh_Map_t *m = new_H(Map);
	m->spi = &DMAP_SO;
	m->mapptr = m->spi->init(ctx, 4, NULL, NULL);
	DBG_ASSERT(m->mapptr != NULL);
	return m;
}

KNHAPI2(void) knh_DataMap_set(CTX ctx, knh_Map_t *m, knh_String_t *key, knh_Object_t *value)
{
	knh_sfp_t* kvsfp = ctx->esp;
	KNH_SETv(ctx, kvsfp[0].o, key);
	KNH_SETv(ctx, kvsfp[1].o, value);
	m->spi->set(ctx, m->mapptr, kvsfp);
}

KNHAPI2(void) knh_DataMap_setString(CTX ctx, knh_Map_t *m, const char *key, const char *value)
{
	knh_sfp_t* kvsfp = ctx->esp;
	KNH_SETv(ctx, kvsfp[0].o, new_String2(ctx, CLASS_String, key, strlen(key), K_SPOLICY_POOLALWAYS));
	KNH_SETv(ctx, kvsfp[1].o, new_String2(ctx, CLASS_String, value, strlen(value), 0));
	m->spi->set(ctx, m->mapptr, kvsfp);
}

KNHAPI2(void) knh_DataMap_setInt(CTX ctx, knh_Map_t *m, const char *key, knh_int_t value)
{
	knh_sfp_t* kvsfp = ctx->esp;
	KNH_SETv(ctx, kvsfp[0].o, new_String2(ctx, CLASS_String, key, strlen(key), K_SPOLICY_POOLALWAYS));
	KNH_SETv(ctx, kvsfp[1].o, new_Int_(ctx, CLASS_Int, value));
	m->spi->set(ctx, m->mapptr, kvsfp);
}

/* ------------------------------------------------------------------------ */

void knh_loadScriptDefaultMapDSPI(CTX ctx, knh_NameSpace_t *ns)
{
	const knh_LoaderAPI_t* ploader = knh_getLoaderAPI();
	ploader->addMapDPI(ctx, "hash", &HMAP_SO);
	ploader->addMapDPI(ctx, "dict", &DMAP_SO);
}

/* ------------------------------------------------------------------------ */

const knh_MapDPI_t *knh_getDefaultMapDSPI(CTX ctx, knh_class_t p1, knh_class_t p2)
{
	return hmap_config(ctx, p1, p2);
}

const knh_MapDPI_t *knh_getDictMapDSPI(CTX ctx, knh_class_t p1, knh_class_t p2)
{
	if(IS_Tstr(p1)) {
		if(IS_Tunbox(p2)) {
			return &DMAP_SN;
		}
		return &DMAP_SO;
	}
	return NULL;
}

#ifdef __cplusplus
}
#endif

