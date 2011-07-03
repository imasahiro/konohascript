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

static const knh_dim_t dimINIT = {
	0, 0, 0, 0, 0, 0, 0,
};

KNHAPI2(knh_Array_t*) new_Array(CTX ctx, knh_class_t p1, size_t capacity)
{
	knh_class_t cid = knh_class_P1(ctx, CLASS_Array, p1);
	knh_Array_t *a = (knh_Array_t*)new_Object_init2(ctx, ClassTBL(cid));
	if(capacity > 0) {
		knh_Array_grow(ctx, a, capacity, 8);
	}
	return a;
}

void knh_Array_grow(CTX ctx, knh_Array_t *a, size_t newsize, size_t reqsize)
{
	size_t capacity = a->dim->capacity;
	if(newsize < reqsize) newsize = reqsize;
	if(newsize == 0) return;
	if(capacity == 0) {
		size_t wsize = (Array_isNDATA(a)) ? sizeof(knh_ndata_t) : sizeof(Object*);
		a->dim = new_dim(ctx, newsize, wsize);
		DBG_ASSERT(a->list == NULL);
	}
	else {
		((knh_dim_t*)a->dim)->capacity = newsize;
	}
	a->list = (knh_Object_t**)KNH_REALLOC(ctx, "Array", a->list, capacity, newsize, a->dim->wsize);
}

KNHAPI2(void) knh_Array_add_(CTX ctx, knh_Array_t *a, knh_Object_t *value)
{
	size_t capacity = a->dim->capacity;
	if(a->size == capacity) {
		knh_Array_grow(ctx, a, k_grow(capacity), a->size + 1);
	}
	KNH_INITv(a->list[a->size], value);
	a->size++;
}

KNHAPI2(void) knh_Array_swap(CTX ctx, knh_Array_t *a, size_t n, size_t m)
{
	DBG_ASSERT(n < a->size);
	DBG_ASSERT(m < a->size);
#ifdef K_USING_RCGC
	Object *temp = a->list[n];
	a->list[n] = a->list[m];
	a->list[m] = temp;
#else
	knh_sfp_t *esp1 = ctx->esp + 1;
	esp1[0].o = a->list[n];
	a->list[n] = a->list[m];
	a->list[m] = esp1[0].o;
#endif
}

void knh_Array_clear(CTX ctx, knh_Array_t *a, size_t n)
{
	if(!Array_isNDATA(a)) {
		size_t i;
		for(i = n; i < a->size; i++) {
			KNH_FINALv(ctx, a->list[i]);
		}
	}
	a->size = n;
}

/* ------------------------------------------------------------------------ */
/* [api] */

static void Farray_getO(CTX ctx, knh_sfp_t *sfp, size_t n2 _RIX)
{
	knh_Array_t *a = sfp[0].a;
	RETURN_(a->list[n2]);
}

static void Farray_getN(CTX ctx, knh_sfp_t *sfp, size_t n2 _RIX)
{
	knh_Array_t *a = sfp[0].a;
	RETURNd_(a->nlist[n2]);
}

static void Farray_setO(CTX ctx, knh_Array_t *a, size_t n2, knh_sfp_t *vsfp)
{
	KNH_SETv(ctx, a->list[n2], vsfp[0].o);
}

static void Farray_setN(CTX ctx, knh_Array_t *a, size_t n2, knh_sfp_t *vsfp)
{
	a->nlist[n2] = vsfp[0].ndata;
}

static void Farray_addO(CTX ctx, knh_Array_t *a, knh_sfp_t *v)
{
	size_t i, n = knh_stack_argc(ctx, v);
	size_t capacity = a->dim->capacity;
	if(!(a->size + n < capacity)) {
		knh_Array_grow(ctx, a, k_grow(a->size), a->size + n);
	}
	for(i = 0; i < n; i++) {
		KNH_INITv(a->list[a->size+i], v[i].o);
	}
	a->size += n;
}

static void Farray_addN(CTX ctx, knh_Array_t *a, knh_sfp_t *v)
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
	Farray_getO,
	Farray_setO,
	Farray_addO,
};

knh_Array_t* new_Array0(CTX ctx, size_t capacity)
{
	knh_Array_t *a = new_H(Array);
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
	Farray_getN,
	Farray_setN,
	Farray_addN,
};

void knh_Array_initAPI(CTX ctx, knh_Array_t *a)
{
	knh_class_t p1 = O_p1(a);
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

static ITRNEXT Fitrnext_end(CTX ctx, knh_sfp_t *sfp _RIX)
{
	ITREND_();
}

/* ------------------------------------------------------------------------ */

void knh_Iterator_close(CTX ctx, knh_Iterator_t *it)
{
	DBG_ASSERT(IS_bIterator(it));
	if(it->fnext_1 != Fitrnext_end) {
		KNH_SETv(ctx, DP(it)->source, KNH_NULL);
		if(DP(it)->freffree != NULL) {
			if(DP(it)->nptr != NULL) {
				DP(it)->freffree(DP(it)->nptr);
			}
			DP(it)->freffree = NULL;
		}
		DP(it)->nptr = NULL;
		it->fnext_1   = Fitrnext_end;
	}
}

/* ------------------------------------------------------------------------ */

KNHAPI2(knh_Iterator_t*) new_Iterator(CTX ctx, knh_class_t p1, knh_Object_t *source, knh_Fitrnext fnext)
{
	knh_class_t cid = knh_class_P1(ctx, CLASS_Iterator, p1);
	knh_Iterator_t *it = new_O(Iterator, cid);
	if(IS_NULL(source)) fnext = Fitrnext_end;
	KNH_SETv(ctx, DP(it)->source, source);
	it->fnext_1 = fnext;
	return it;
}

/* ------------------------------------------------------------------------ */
/* [ArrayIterator] */

static ITRNEXT Array_nextO(CTX ctx, knh_sfp_t *sfp _RIX)
{
	DBG_ASSERT(IS_bIterator(sfp[0].it));
	knh_Iterator_t *itr = ITR(sfp);
	knh_Array_t *a = (knh_Array_t*)DP(itr)->source;
	size_t pos = (size_t)DP(itr)->mitr.index;
	if(pos < a->size) {
		DP(itr)->mitr.index = pos + 1;
		ITRNEXT_(a->list[pos]);
	}
	ITREND_();
}

static ITRNEXT Array_nextN(CTX ctx, knh_sfp_t *sfp _RIX)
{
	DBG_ASSERT(IS_bIterator(sfp[0].it));
	knh_Iterator_t *itr = ITR(sfp);
	knh_Array_t *a = (knh_Array_t*)DP(itr)->source;
	size_t pos = (size_t)DP(itr)->mitr.index;
	if(pos < a->size) {
		DP(itr)->mitr.index = pos+1;
		ITRNEXTd_(a->nlist[pos]);
	}
	ITREND_();
}

knh_Iterator_t* new_ArrayIterator(CTX ctx, knh_Array_t *a)
{
	knh_class_t cid = O_p1(a);
	knh_Fitrnext fnext = Array_isNDATA(a) ? Array_nextN : Array_nextO;
	return new_Iterator(ctx, cid, UPCAST(a), fnext);
}

knh_bool_t knh_isArrayIterator(knh_Iterator_t *itr)
{
	return (itr->fnext_1 == Array_nextO || itr->fnext_1 == Array_nextN);
}

knh_Array_t* knh_Iterator_toArray(CTX ctx, knh_Iterator_t *itr)
{
	knh_Array_t *a = new_Array(ctx, O_cTBL(itr)->p1, 0);
	BEGIN_LOCAL(ctx, lsfp, 2);
	KNH_SETv(ctx, lsfp[1].o, itr);
	while(itr->fnext_1(ctx, lsfp + 1, -1)) {
		a->api->add(ctx, a, lsfp);
	}
	END_LOCAL_(ctx, lsfp);
	return a;
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif

