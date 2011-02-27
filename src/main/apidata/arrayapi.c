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

#ifdef K_USING_DEFAULTAPI

/* ------------------------------------------------------------------------ */
/* [Bytes, byte[]] */

/* ------------------------------------------------------------------------ */
//## method void Bytes.putc(Int char);

static METHOD Bytes_putc(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Bytes_t *o = (knh_Bytes_t*)sfp[0].o;
	knh_Bytes_putc(ctx, o, Int_to(size_t, sfp[1]));
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void Bytes.write(BytesIm buf, Int offset, Int length);
//## method void Bytes.add(BytesIm buf, Int offset, Int length);

static METHOD Bytes_write(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Bytes_t *ba = sfp[0].ba;
	knh_bytes_t t = BA_tobytes(sfp[1].ba);
	if(sfp[2].ivalue != 0) {
		size_t n = knh_array_index(ctx, sfp, Int_to(size_t, sfp[2]), t.len);
		t = knh_bytes_last(t, n);
	}
	if(sfp[3].ivalue != 0) {
		size_t l = Int_to(size_t, sfp[3]);
		if(l < t.len) t.len = l;
	}
	knh_Bytes_write(ctx, ba, t);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
/* [Array, ArrayIm] */

/* ------------------------------------------------------------------------ */
//## method T1 Array.get(Int n);
//## method T1 ArrayIm.get(Int n);

static METHOD Array_get(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	size_t n2 = a->api->index(ctx, sfp, Int_to(size_t, ctx->esp[-1]), a->size);
	a->api->get(ctx, sfp, n2, rix);
}

/* ------------------------------------------------------------------------ */
//## @Hidden method T1 Array.get2(Int x, Int y);
//## @Hidden method T1 ArrayIm.get2(Int x, Int y);

static METHOD Array_get2(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	const knh_dim_t *dim = a->dim;
	knh_int_t n = sfp[1].ivalue + (sfp[2].ivalue * dim->x);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->get(ctx, sfp, n2, rix);
}

/* ------------------------------------------------------------------------ */
//## @Hidden method T1 Array.get3(Int x, Int y, Int z);
//## @Hidden method T1 ArrayIm.get3(Int x, Int y, Int z);

static METHOD Array_get3(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	const knh_dim_t *dim = a->dim;
	knh_int_t n = sfp[1].ivalue + (sfp[2].ivalue * dim->x) + (sfp[3].ivalue * dim->xy);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->get(ctx, sfp, n2, rix);
}

/* ------------------------------------------------------------------------ */
//## @Hidden method T1 Array.get4(Int x, Int y, Int z, Int w);
//## @Hidden method T1 ArrayIm.get4(Int x, Int y, Int z, Int w);

static METHOD Array_get4(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	const knh_dim_t *dim = a->dim;
	knh_int_t n = sfp[1].ivalue + (sfp[2].ivalue * dim->x) + (sfp[3].ivalue * dim->xy) + (sfp[4].ivalue * dim->xyz);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->get(ctx, sfp, n2, rix);
}

/* ------------------------------------------------------------------------ */
//## method T1 Array.set(Int n, T1 v);

static METHOD Array_set(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	knh_int_t n = sfp[1].ivalue;
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->set(ctx, sfp[0].a, n2, sfp+2);
	a->api->get(ctx, sfp, n2, rix);
}

/* ------------------------------------------------------------------------ */
//## method T1 Array.set2(Int x, Int y, T1 v);

static METHOD Array_set2(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	const knh_dim_t *dim = (sfp[0].a)->dim;
	knh_int_t n = sfp[1].ivalue + (sfp[2].ivalue * dim->x);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->set(ctx, a, n2, sfp+3);
	a->api->get(ctx, sfp, n2, rix);
}

/* ------------------------------------------------------------------------ */
//## method T1 Array.set3(Int x, Int y, Int z, T1 v);

static METHOD Array_set3(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	const knh_dim_t *dim = (sfp[0].a)->dim;
	knh_int_t n = sfp[1].ivalue + (sfp[2].ivalue * dim->x) + (sfp[3].ivalue * dim->xy);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->set(ctx, a, n2, sfp+4);
	a->api->get(ctx, sfp, n2, rix);
}

/* ------------------------------------------------------------------------ */
//## method T1 Array.set4(Int x, Int y, Int z, T1 v);

static METHOD Array_set4(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	const knh_dim_t *dim = (sfp[0].a)->dim;
	knh_int_t n = sfp[1].ivalue + (sfp[2].ivalue * dim->x) + (sfp[3].ivalue * dim->xy) + (sfp[4].ivalue * dim->xyz);
	size_t n2 = a->api->index(ctx, sfp, n, a->size);
	a->api->set(ctx, a, n2, sfp+5);
	a->api->get(ctx, sfp, n2, rix);
}

/* ------------------------------------------------------------------------ */
//## method T1 Array.setAll(T1 v);

static METHOD Array_setAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t i;
	for(i = 0; i < (sfp[0].a)->size; i++) {
		(sfp[0].a)->api->set(ctx, sfp[0].a, i, sfp+1);
	}
	if((sfp[0].a)->size > 0) {
		(sfp[0].a)->api->get(ctx, sfp, 0, rix);
	}
	else {
		sfp[rix].ndata = sfp[1].ndata;
		RETURN_(sfp[1].o);
	}
}

/* ------------------------------------------------------------------------ */
//## method void Array.add(T1 value, ...);
//## method void Array.opSEND(T1 value, ...);

static METHOD Array_add(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	a->api->add(ctx, a, sfp+1);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void Array.insert(Int n, T1 value);

static METHOD Array_insert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	size_t size, n = a->api->index(ctx, sfp, Int_to(size_t, sfp[1]), a->size);
	const knh_dim_t *dim = a->dim;
	BEGIN_LOCAL(ctx, lsfp, 1);
	if(a->size == dim->capacity) {
		knh_Array_grow(ctx, a, k_grow(dim->capacity), a->size + 1);
	}
	if(Array_isNDATA(a)) {
		size = sizeof(knh_ndata_t);
		lsfp[0].ndata = a->nlist[a->size];
	}else {
		size = sizeof(knh_Object_t*);
		KNH_SETv(ctx, lsfp[0].o, a->list[a->size]);
	}
	a->size++;
	knh_memmove(a->list+(n+1), a->list+n, size * (a->size - n));
	a->api->set(ctx, a, n, sfp+2);
	END_LOCAL_(ctx, lsfp);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void Array.clear();

static METHOD Array_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_clear(ctx, sfp[0].a, 0);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */

static void knh_Array_remove_(CTX ctx, knh_Array_t *a, size_t n)
{
	DBG_ASSERT(n < a->size);
	size_t size;
	if (Array_isNDATA(a)) {
		size = sizeof(knh_ndata_t);
	} else {
		size = sizeof(knh_Object_t*);
		KNH_FINALv(ctx, a->list[n]);
	}
	knh_memmove(a->list+n, a->list+(n+1), size * (a->size - n - 1));
	a->size--;
}

/* ------------------------------------------------------------------------ */
//## method void Array.remove(Int n);

static METHOD Array_remove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *o = (knh_Array_t*)sfp[0].o;
	size_t n = knh_array_index(ctx, sfp, sfp[1].ivalue, o->size);
	knh_Array_remove_(ctx, o, n);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method T1! Array.pop();

static METHOD Array_pop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	if (a->size > 0) {
		(a)->api->get(ctx, sfp, a->size - 1, rix);
		knh_Array_clear(ctx, a, a->size - 1);
	}
}
/* ------------------------------------------------------------------------ */
//## method Int Array.indexOf(T1 value);

static METHOD Array_indexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	knh_int_t res = -1;
	size_t i;
	if(Array_isNDATA(a)) {
		knh_ndata_t ndata = sfp[1].ndata;
		for(i = 0; i < a->size; i++) {
			if(a->nlist[i] == ndata) {
				res = i; break;
			}
		}
	}else {
		knh_Object_t *o = sfp[1].o;
		for(i = 0; i < a->size; i++) {
			if(knh_Object_compareTo(a->list[i], o) == 0) {
				res = i; break;
			}
		}
	}
	RETURNi_(res);
}
/* ------------------------------------------------------------------------ */
//## method Int Array.lastIndexOf(T1 value);

static METHOD Array_lastIndexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	long i;
	if(Array_isNDATA(a)) {
		knh_ndata_t ndata = sfp[1].ndata;
		for(i = a->size - 1; i >= 0; i--) {
			if(a->nlist[i] == ndata) {
				break;
			}
		}
	}else {
		knh_Object_t *o = sfp[1].o;
		for(i = a->size - 1; i >= 0; i--) {
			if(knh_Object_compareTo(a->list[i], o) == 0) {
				break;
			}
		}
	}
	RETURNi_(i);
}

///* ------------------------------------------------------------------------ */
///* [Collections] */
//
//typedef struct {
//	CTX ctx;
//	knh_sfp_t *sfp;
//} knh_env_t;
//
//static int knh_env_comp(knh_env_t *env, Object **a1, Object **a2)
//{
//	CTX ctx = env->ctx;
//	knh_sfp_t *lsfp = env->sfp + 2;
//	knh_putsfp(ctx, lsfp, 2, a1[0]);
//	knh_putsfp(ctx, lsfp, 3, a2[0]);
//	knh_Func_invokesfp(ctx, env->sfp[1].cc, lsfp, 1/*rtnidx*/, 2);
//	return (int)lsfp[0].ivalue;
//}
//
///* ------------------------------------------------------------------------ */
////## method void Array.sort(Cmpr? cc);
//
//static METHOD Array_sort(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	
//	knh_Array_t *o = sfp[0].a;
//	if(IS_NULL(sfp[1].o)) {
//		knh_qsort_r(o->list, o->size, sizeof(Object*),
//			(void*)ctx, (int (*)(void*, const void*, const void*))knh_Object_compareTo2);
//	}
//	else {
//		knh_env_t env = {ctx, sfp};
//		knh_qsort_r(o->list, o->size, sizeof(Object*), (void*)&env,
//				(int (*)(void *, const void* , const void*))knh_env_comp);
//	}
//	RETURNvoid_();
//}
//
///* ------------------------------------------------------------------------ */
//
//static int qsort_icmp(const void* ap, const void* bp)
//{
//	knh_int_t a = *((knh_int_t*)ap);
//	knh_int_t b = *((knh_int_t*)bp);
//	if(a < b) return -1;
//	if(a > b) return 1;
//	return 0;
//}
//
///* ------------------------------------------------------------------------ */
////## method void IArray.sort();
//
//static METHOD IArray_sort(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	
//	knh_IArray_t *o = (knh_IArray_t*)sfp[0].o;
//	knh_qsort(o->ilist, o->size, sizeof(knh_int_t), qsort_icmp);
//	RETURNvoid_();
//}
//
///* ------------------------------------------------------------------------ */
//
//static int qsort_fcmp(const void* ap, const void* bp)
//{
//	knh_float_t a = *((knh_float_t*)ap);
//	knh_float_t b = *((knh_float_t*)bp);
//	if(a < b) return -1;
//	if(a > b) return 1;
//	return 0;
//}
//
///* ------------------------------------------------------------------------ */
////## method void FArray.sort();
//
//static METHOD FArray_sort(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	
//	knh_FArray_t *o = (knh_FArray_t*)sfp[0].o;
//	knh_qsort(o->flist, o->size, sizeof(knh_float_t), qsort_fcmp);
//	RETURNvoid_();
//}
//
/* ------------------------------------------------------------------------ */

static inline void NArray_swap(CTX ctx, knh_Array_t *a, size_t n, size_t m)
{
	knh_ndata_t temp = a->nlist[n];
	a->nlist[n] = a->nlist[m];
	a->nlist[m] = temp;
}

static inline void OArray_swap(CTX ctx, knh_Array_t *a, size_t n, size_t m)
{
	knh_sfp_t *esp1 = ctx->esp + 1;
	esp1[0].o = a->list[n];
	a->list[n] = a->list[m];
	a->list[m] = esp1[0].o;
}

/* ------------------------------------------------------------------------ */
//## method void Array.swap(Int m, Int n);

static METHOD Array_swap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = sfp[0].a;
	size_t m = knh_array_index(ctx, sfp, (sfp[1].ivalue), a->size);
	size_t n = knh_array_index(ctx, sfp, (sfp[2].ivalue), a->size);
	if(Array_isNDATA(a)) {
		NArray_swap(ctx, a, n, m);
	}
	else {
		OArray_swap(ctx, a, n, m);
	}
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void Array.shuffle();
static METHOD Array_shuffle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t i;
	knh_Array_t *a = sfp[0].a;
	if(Array_isNDATA(a)) {
		for(i = 0; i < a->size * 2; i++) {
			size_t m = knh_rand() % a->size;
			size_t n = knh_rand() % a->size;
			NArray_swap(ctx, a, m, n);
		}
	}
	else {
		for(i = 0; i < a->size * 2; i++) {
			size_t m = knh_rand() % a->size;
			size_t n = knh_rand() % a->size;
			OArray_swap(ctx, a, m, n);
		}
	}
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void Array.reverse();

static METHOD Array_reverse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t i;
	knh_Array_t *a = sfp[0].a;
	if(Array_isNDATA(a)) {
		for(i = 0; i < a->size / 2; i++) {
			size_t n = a->size - i - 1;
			NArray_swap(ctx, a, i, n);
		}
	}
	else {
		for(i = 0; i < a->size / 2; i++) {
			size_t n = a->size - i - 1;
			OArray_swap(ctx, a, i, n);
		}
	}
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */

#endif/*K_USING_DEFAULTAPI*/

#ifdef __cplusplus
}
#endif
