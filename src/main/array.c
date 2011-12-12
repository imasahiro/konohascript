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
/* Array */

static const kdim_t dimINIT = {
	0, 0, 0, 0, 0, 0, 0,
};

KNHAPI2(kArray*) new_Array(CTX ctx, kclass_t p1, size_t capacity)
{
	kclass_t cid = knh_class_P1(ctx, CLASS_Array, p1);
	kArray *a = (kArray*)new_Object_init2(ctx, ClassTBL(cid));
	if(capacity > 0) {
		knh_Array_grow(ctx, a, capacity, 8);
	}
	return a;
}

kArray* new_ArrayG(CTX ctx, kclass_t cid, size_t capacity)
{
	kArray *a = (kArray*)new_Object_init2(ctx, ClassTBL(cid));
	if(capacity > 0) {
		knh_Array_grow(ctx, a, capacity, 8);
	}
	return a;
}

void knh_Array_grow(CTX ctx, kArray *a, size_t newsize, size_t reqsize)
{
	size_t capacity = a->dim->capacity;
	if(newsize < reqsize) newsize = reqsize;
	if(newsize == 0) return;
	if(capacity == 0) {
		size_t wsize = (Array_isNDATA(a)) ? sizeof(kunbox_t) : sizeof(Object*);
		a->dim = new_dim(ctx, newsize, wsize);
		DBG_ASSERT(a->list == NULL);
	}
	else {
		((kdim_t*)a->dim)->capacity = newsize;
	}
	a->list = (kObject**)KNH_REALLOC(ctx, "Array", a->list, capacity, newsize, a->dim->wsize);
}

KNHAPI2(void) knh_Array_add_(CTX ctx, kArray *a, kObject *value)
{
	size_t capacity = a->dim->capacity;
	if(a->size == capacity) {
		knh_Array_grow(ctx, a, k_grow(capacity), a->size + 1);
	}
	KNH_INITv(a->list[a->size], value);
	a->size++;
}

KNHAPI2(void) knh_Array_remove_(CTX ctx, kArray *a, size_t n)
{
	DBG_ASSERT(n < a->size);
	if (Array_isNDATA(a)) {
		knh_memmove(a->nlist+n, a->nlist+(n+1), sizeof(kunbox_t) * (a->size - n - 1));
	} else {
		KNH_FINALv(ctx, a->list[n]);
		knh_memmove(a->list+n, a->list+(n+1), sizeof(kObject*) * (a->size - n - 1));
	}
	a->size--;
}

KNHAPI2(void) knh_Array_swap(CTX ctx, kArray *a, size_t n, size_t m)
{
	DBG_ASSERT(n < a->size);
	DBG_ASSERT(m < a->size);
#ifdef K_USING_RCGC
	Object *temp = a->list[n];
	a->list[n] = a->list[m];
	a->list[m] = temp;
#else
	ksfp_t *esp1 = ctx->esp + 1;
	esp1[0].o = a->list[n];
	a->list[n] = a->list[m];
	a->list[m] = esp1[0].o;
#endif
}

void knh_Array_clear(CTX ctx, kArray *a, size_t n)
{
	if(!Array_isNDATA(a)) {
#ifdef K_USING_RCGC
		size_t i;
		for(i = n; i < a->size; i++) {
			KNH_FINALv(ctx, a->list[i]);
		}
#else
		knh_bzero(a->list + n, sizeof(void*) * (a->size - n));
#endif
	}
	a->size = n;
}

/* ------------------------------------------------------------------------ */
/* [api] */

static void Farray_fastgetO(CTX ctx, ksfp_t *sfp, size_t n2 _RIX)
{
	kArray *a = sfp[0].a;
	RETURN_(a->list[n2]);
}

static void Farray_fastgetN(CTX ctx, ksfp_t *sfp, size_t n2 _RIX)
{
	kArray *a = sfp[0].a;
	RETURNd_(a->nlist[n2]);
}

static void Farray_getO(CTX ctx, kArray *a, size_t n2, ksfp_t *vsfp)
{
	KNH_SETv(ctx, vsfp[0].o, a->list[n2]);
}

static void Farray_getN(CTX ctx, kArray *a, size_t n2, ksfp_t *vsfp)
{
	vsfp[0].ndata = a->nlist[n2];
}

static void Farray_setO(CTX ctx, kArray *a, size_t n2, ksfp_t *vsfp)
{
	KNH_SETv_withWB(ctx, a, a->list[n2], vsfp[0].o);
}

static void Farray_setN(CTX ctx, kArray *a, size_t n2, ksfp_t *vsfp)
{
	a->nlist[n2] = vsfp[0].ndata;
}

static void Farray_addO(CTX ctx, kArray *a, ksfp_t *v)
{
	size_t capacity = a->dim->capacity;
	if(!(a->size + 1 < capacity)) {
		knh_Array_grow(ctx, a, k_grow(a->size), a->size + 1);
	}
	KNH_INITv_withWB(a, a->list[a->size], v[0].o);
	a->size += 1;
}

static void Farray_addN(CTX ctx, kArray *a, ksfp_t *v)
{
	size_t capacity = a->dim->capacity;
	if(!(a->size + 1 < capacity)) {
		knh_Array_grow(ctx, a, k_grow(a->size), a->size + 1);
	}
	a->nlist[a->size] = v[0].ndata;
	a->size += 1;
}

static void Farray_multiaddO(CTX ctx, kArray *a, ksfp_t *v)
{
	size_t i, n = knh_stack_argc(ctx, v);
	size_t capacity = a->dim->capacity;
	if(!(a->size + n < capacity)) {
		knh_Array_grow(ctx, a, k_grow(a->size), a->size + n);
	}
	for(i = 0; i < n; i++) {
		KNH_INITv_withWB(a, a->list[a->size+i], v[i].o);
	}
	a->size += n;
}

static void Farray_multiaddN(CTX ctx, kArray *a, ksfp_t *v)
{
	size_t i, n = knh_stack_argc(ctx, v);
	size_t capacity = a->dim->capacity;
	if(!(a->size + n < capacity)) {
		knh_Array_grow(ctx, a, k_grow(a->size), a->size + n);
	}
	for(i = 0; i < n; i++) {
		a->nlist[a->size+i] = v[i].ndata;
	}
	a->size += n;
}

static knh_ArrayAPI_t ArrayOAPI = {
	knh_array_index,
	Farray_fastgetO,
	Farray_getO,
	Farray_setO,
	Farray_addO,
	Farray_multiaddO,
};

kArray* new_Array0(CTX ctx, size_t capacity)
{
	kArray *a = new_H(Array);
	a->dim = &dimINIT;
	a->api = &ArrayOAPI;
	a->list = NULL;
	if(capacity > 0) {
		knh_Array_grow(ctx, a, capacity, 8);
	}
	a->size = 0;
	return a;
}

static knh_ArrayAPI_t ArrayNAPI = {
	knh_array_index,
	Farray_fastgetN,
	Farray_getN,
	Farray_setN,
	Farray_addN,
	Farray_multiaddN,
};

void knh_Array_initAPI(CTX ctx, kArray *a)
{
	kclass_t p1 = O_p1(a);
	if(IS_Tunbox(p1)) {
		Array_setNDATA(a, 1);
		a->api = &ArrayNAPI;
	}
	else {
		a->api = &ArrayOAPI;
	}
}

/* ------------------------------------------------------------------------ */
/* Iterator */

static ITRNEXT Fitrnext_end(CTX ctx, ksfp_t *sfp _RIX)
{
	ITREND_();
}

void knh_Iterator_close(CTX ctx, kIterator *it)
{
	DBG_ASSERT(IS_bIterator(it));
	if(it->fnext_1 != Fitrnext_end) {
		KNH_SETv(ctx, DP(it)->source, KNH_NULL);
		if(DP(it)->m.nfree != NULL) {
			if(DP(it)->m.nptr != NULL) {
				DP(it)->m.nfree(DP(it)->m.nptr);
			}
			DP(it)->m.nfree = NULL;
		}
		DP(it)->m.nptr = NULL;
		it->fnext_1   = Fitrnext_end;
	}
}

KNHAPI2(kIterator*) new_IteratorG(CTX ctx, kclass_t cid, kObject *source, knh_Fitrnext fnext)
{
	DBG_ASSERT(C_bcid(cid) == CLASS_Iterator);
	kIterator *it = new_O(Iterator, cid);
	if(IS_NULL(source)) fnext = Fitrnext_end;
	KNH_SETv_withWB(ctx, it, DP(it)->source, source);
	it->fnext_1 = fnext;
	return it;
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif

