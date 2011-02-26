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
/* [String] */

static ITRNEXT knh_String_nextChar(CTX ctx, knh_sfp_t *sfp, long rtnidx)
{
	knh_Iterator_t *itr = sfp[0].it;
	knh_String_t *s = (knh_String_t*)DP(itr)->source;
	knh_bytes_t base = S_tobytes(s);
	size_t pos = (size_t)DP(itr)->pos;
	if(pos < knh_bytes_mlen(base)) {
		DP(itr)->pos = pos+1;
		knh_bytes_t sub = knh_bytes_mofflen(base, pos, 1);
		s = new_String_(ctx, CLASS_String, sub, s);
		ITRNEXT_(s);
	}
	ITREND_();
}

/* ------------------------------------------------------------------------ */
//## @General mapper String Iterator;
//## mapper String String..;
//## method String.. String.opITR();

static TCAST String_Iterator(CTX ctx, knh_sfp_t *sfp, long rix)
{
	RETURN_(new_Iterator(ctx, CLASS_String, sfp[K_SELFIDX].o, knh_String_nextChar));
}

/* ------------------------------------------------------------------------ */
/* [Range] */

//static ITRNEXT knh_Range_inext(CTX ctx, knh_sfp_t *sfp, long rtnidx)
//{
//	knh_Iterator_t *itr = sfp[0].it;
//	knh_Range_t *rng = (knh_Range_t*)DP(itr)->source;
//	knh_int_t pos = DP(itr)->pos;
//	if(pos < N_toint((rng)->end)) {
//		DP(itr)->pos = pos+1;
//		ITRNEXTi_(pos);
//	}
//	ITREND_();
//}
//
//static ITRNEXT knh_Range_inextInclusive(CTX ctx, knh_sfp_t *sfp, long rtnidx)
//{
//	knh_Iterator_t *itr = sfp[0].it;
//	knh_Range_t *rng = (knh_Range_t*)DP(itr)->source;
//	knh_int_t pos = DP(itr)->pos;
//	if(pos <= N_toint((rng)->end)) {
//		DP(itr)->pos = pos+1;
//		ITRNEXTi_(pos);
//	}
//	ITREND_();
//}
//
//static ITRNEXT knh_Range_fnext(CTX ctx, knh_sfp_t *sfp, long rtnidx)
//{
//	knh_Iterator_t *itr = sfp[0].it;
//	knh_Range_t *rng = (knh_Range_t*)DP(itr)->source;
//	knh_int_t pos = DP(itr)->pos;
//	if(pos < N_toint((rng)->end)) {
//		DP(itr)->pos = pos+1;
//		ITRNEXTf_((knh_float_t)pos);
//	}
//	ITREND_();
//}
//
//static ITRNEXT knh_Range_fnextInclusive(CTX ctx, knh_sfp_t *sfp, long rtnidx)
//{
//	knh_Iterator_t *itr = sfp[0].it;
//	knh_Range_t *rng = (knh_Range_t*)DP(itr)->source;
//	knh_int_t pos = DP(itr)->pos;
//	if(pos <= N_toint((rng)->end)) {
//		DP(itr)->pos = pos+1;
//		ITRNEXTf_((knh_float_t)pos);
//	}
//	ITREND_();
//}
//
//static knh_Iterator_t *new_RangeIterator(CTX ctx, knh_Range_t *rng)
//{
//	knh_class_t p1 = O_p1(rng);
//	if(ClassTBL(p1)->bcid == CLASS_Int) {
//		knh_Iterator_t *itr = new_Iterator(ctx, p1, UPCAST(rng), Range_isInclusive(rng) ? knh_Range_inextInclusive : knh_Range_inext);
//		DP(itr)->pos = N_toint(rng->start);
//		return itr;
//	}
//	else if(ClassTBL(p1)->bcid == CLASS_Float) {
//		knh_Iterator_t *itr = new_Iterator(ctx, p1, UPCAST(rng), Range_isInclusive(rng) ? knh_Range_fnextInclusive : knh_Range_fnext);
//		knh_float_t s = N_tofloat((rng)->start);
//		DP(itr)->pos = (knh_int_t)s;
//		if((knh_float_t)DP(itr)->pos < s) DP(itr)->pos += 1;
//		return itr;
//	}
//	else {
//		knh_Array_t *a = new_Array(ctx, p1, 2);
//		knh_Array_add(ctx, a, (rng)->start);
//		if(Range_isInclusive(rng)) {
//			knh_Array_add(ctx, a, (rng)->end);
//		}
//		return new_ArrayIterator(ctx, a);
//	}
//}
//

/* ------------------------------------------------------------------------ */
/* [ArrayIterator] */

static ITRNEXT knh_Array_nextO(CTX ctx, knh_sfp_t *sfp, long rtnidx)
{
	DBG_ASSERT(IS_bIterator(sfp[0].it));
	knh_Array_t *a = (knh_Array_t*)DP(sfp[0].it)->source;
	size_t pos = (size_t)(DP(sfp[0].it)->pos);
	if(pos < a->size) {
		DP(sfp[0].it)->pos = pos+1;
		ITRNEXT_(a->list[pos]);
	}
	ITREND_();
}

static ITRNEXT knh_Array_nextN(CTX ctx, knh_sfp_t *sfp, long rtnidx)
{
	DBG_ASSERT(IS_bIterator(sfp[0].it));
	knh_Array_t *a = (knh_Array_t*)DP(sfp[0].it)->source;
	size_t pos = (size_t)(DP(sfp[0].it)->pos);
	if(pos < a->size) {
		DP(sfp[0].it)->pos = pos+1;
		ITRNEXTd_(a->nlist[pos]);
	}
	ITREND_();
}

/* ------------------------------------------------------------------------ */

static knh_Iterator_t* new_ArrayIterator(CTX ctx, knh_Array_t *a)
{
	knh_class_t cid = O_p1(a);
	knh_Fitrnext fnext = Array_isNDATA(a) ? knh_Array_nextN : knh_Array_nextO;
	return new_Iterator(ctx, cid, UPCAST(a), fnext);
}


///* ------------------------------------------------------------------------ */
////## @General mapper Range Iterator;
////## method T1.. Range.opITR();
//
//static TCAST Range_Iterator(CTX ctx, knh_sfp_t *sfp, long rix)
//{
//	RETURN_(new_RangeIterator(ctx, sfp[K_SELFIDX].range));
//}

/* ------------------------------------------------------------------------ */
/* [Array] */
//## @General mapper Array Iterator;
//## method T1.. Array.opITR();

static TCAST Array_Iterator(CTX ctx, knh_sfp_t *sfp, long rix)
{
	RETURN_(new_ArrayIterator(ctx, sfp[K_SELFIDX].a));
}

/* ------------------------------------------------------------------------ */
/* [DictMap] */

//static ITRNEXT knh_DictMap_key_next(CTX ctx, knh_sfp_t *sfp, long rtnidx)
//{
//	Iterator *it = sfp[0].it;
//	DictMap *o = (DictMap*)DP(it)->source;
//	size_t pos;
//	for(pos = DP(it)->pos; pos < o->size; pos++) {
//		if(IS_NOTNULL(o->list[pos].value)) {
//			DP(it)->pos = pos+1;
//			ITRNEXT_((Object*)o->list[pos].key);
//		}
//	}
//	DP(it)->pos = pos;
//	ITREND_();
//}

///* ------------------------------------------------------------------------ */
//
//typedef void (*knh_fadd_dict)(CTX, knh_Array_t *a, knh_String_t *key, Object *value);
//
//static void knh_DictMap_array(CTX ctx, knh_DictMap_t *d, knh_Array_t *a, knh_fadd_dict fadd)
//{
//	size_t i;
//	knh_DictMap_sort(d);
//	for(i = 0; i < d->size; i++) {
//		Object *v = knh_DictMap_valueAt(d, i);
//		if(IS_NOTNULL(v)) {
//			fadd(ctx, a, knh_DictMap_keyAt(d, i), v);
//		}
//	}
//}
//
//static void knh_fadd_dictkey(CTX ctx, knh_Array_t *a, knh_String_t *key, Object *value)
//{
//	knh_Array_add_(ctx, a, UPCAST(key));
//}

//static void knh_fadd_dictentry(CTX ctx, knh_Array_t *a, knh_String_t *key, Object *value)
//{
//	TODO();DBG_ABORT();
//	knh_Pair_t *p = (knh_Pair_t*)new_H(ctx, FLAG_Pair, CLASS_Pair, O_p1(a));
//	KNH_INITv(p->first, key);
//	KNH_INITv(p->second, value);
//	knh_Array_add_(ctx, a, UPCAST(p));
//}

/* ------------------------------------------------------------------------ */
//## mapper Map Iterator!;
//## mapper Map String..!;
//## method String.. Map.opITR();

static TCAST DictMap_String__(CTX ctx, knh_sfp_t *sfp, long rix)
{
	knh_Map_t *o = sfp[0].m;
	knh_Iterator_t *itr = new_Iterator(ctx, CLASS_Tuple, UPCAST(o), NULL);
	o->dspi->setIterator(ctx, o->map, itr);
	RETURN_(itr);
//	long selfidx = K_SELFIDX;
//	knh_Array_t *a = new_Array(ctx, CLASS_String, (sfp[selfidx].dmap)->size);
//	knh_DictMap_array(ctx, sfp[selfidx].dmap, a, knh_fadd_dictkey);
//	RETURN_(new_ArrayIterator(ctx, a));
}

#endif/* K_USING_DEFAULTAPI*/

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
