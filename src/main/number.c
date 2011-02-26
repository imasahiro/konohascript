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

#ifdef K_USED_TO_BE_ON_LKM
#include <linux/random.h>
#else
#include<time.h>
#ifdef K_USING_POSIX_
#include<unistd.h>
#endif
#endif

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* [random] */

void init_genrand(unsigned long s);
void init_genrand64(unsigned long long seed);
unsigned long genrand_int31(void);
unsigned long long genrand64_int63(void);
#ifndef K_USING_NOFLOAT
double genrand_real1(void);
double genrand64_real1(void);
#endif

/* ------------------------------------------------------------------------ */

void knh_srand(knh_uint_t seed)
{
#ifndef K_USED_TO_BE_ON_LKM
	if(seed == 0) {
#ifdef K_USING_POSIX_
		seed = (knh_uint_t)time(NULL) + getpid();
#else
		seed = (knh_uint_t)time(NULL);
#endif
	}
#ifdef K_USING_INT32
	init_genrand((unsigned long)seed);
#else
	init_genrand64((unsigned long long int)seed);
#endif
#endif /* K_USED_TO_BE_ON_LKM */
}

/* ------------------------------------------------------------------------ */

knh_uint_t knh_rand(void)
{
#if defined(K_USING_INT32)
	return (knh_uint_t)genrand_int31();
#else
	return (knh_uint_t)genrand64_int63();
#endif
}

knh_float_t knh_float_rand(void)
{
#if defined(K_USING_NOFLOAT)
	return (knh_float_t)knh_rand();
#elif defined(K_USING_INT32)
	return (knh_float_t)genrand_real1();
#else
	return (knh_float_t)genrand64_real1();
#endif
}

///* ------------------------------------------------------------------------ */
///* [Number] */
//
//knh_bool_t Object_isNumber(CTX ctx, knh_Object_t *o)
//{
//	knh_NumberSPI_t *cspi = (knh_NumberSPI_t*)ClassTBL(O_cid(o))->cspi;
//	return (cspi->magic == K_NUMBERCSPI_MAGIC);
//}
//
///* ------------------------------------------------------------------------ */
//
//FASTAPI(knh_int_t) knh_stack0_toint(CTX ctx, knh_sfp_t *sfp)
//{
//	knh_NumberSPI_t *cspi = (knh_NumberSPI_t*)ClassTBL(O_cid(sfp[0].o))->cspi;
//	DBG_ASSERT(cspi->magic == K_NUMBERCSPI_MAGIC);
//	return cspi->to_int(ctx, sfp);
//}
//
///* ------------------------------------------------------------------------ */
//
//FASTAPI(knh_float_t) knh_stack0_tofloat(CTX ctx, knh_sfp_t *sfp)
//{
//	knh_NumberSPI_t *cspi = (knh_NumberSPI_t*)ClassTBL(O_cid(sfp[0].o))->cspi;
//	DBG_ASSERT(cspi->magic == K_NUMBERCSPI_MAGIC);
//	return cspi->to_float(ctx, sfp);
//}

/* ------------------------------------------------------------------------ */
/* [Int] */

KNHAPI2(knh_Int_t*) new_Int(CTX ctx, knh_class_t cid, knh_int_t value)
{
	knh_Int_t *b = (knh_Int_t*)new_hObject_(ctx, ClassTBL(cid));
	b->n.ivalue = value;
	return b;
}

/* ------------------------------------------------------------------------ */

KNHAPI2(knh_Float_t*) new_Float(CTX ctx, knh_class_t cid, knh_float_t value)
{
	knh_Float_t *b = (knh_Float_t*)new_hObject_(ctx, ClassTBL(cid));
	b->n.fvalue = value;
	return b;
}


///* ------------------------------------------------------------------------ */
///* [Affine] */
//
//static
//knh_AffineConv_t *new_AffineConv(CTX ctx, knh_float_t fa, knh_float_t fb)
//{
//	knh_AffineConv_t *af = (knh_AffineConv_t*)new_Object_bcid(ctx, CLASS_AffineConv, 0);
//	af->scale = (knh_affinefloat_t)fa;
//	af->shift = (knh_affinefloat_t)fb;
//	return af;
//}
//
///* ------------------------------------------------------------------------ */
///* [mapper] */
//
//static
//TCAST knh_AffineConv_fmap__i2i(CTX ctx, knh_sfp_t *sfp, long rix)
//{
//	knh_AffineConv_t *af = (knh_AffineConv_t*)DP(sfp[1].mpr)->mapdata;
//	DBG_ASSERT(IS_AffineConv(af));
//	knh_float_t y = (sfp[0].ivalue * af->scale) + af->shift;
//	KNH_MAPPED_Int(ctx, sfp, (knh_int_t)y);
//}
//
///* ------------------------------------------------------------------------ */
//
//static TCAST knh_AffineConv_fmap__i2f(CTX ctx, knh_sfp_t *sfp, long rix)
//{
//	knh_AffineConv_t *af = (knh_AffineConv_t*)DP(sfp[1].mpr)->mapdata;
//	DBG_ASSERT(IS_AffineConv(af));
//	knh_float_t y = (sfp[0].ivalue * af->scale) + af->shift;
//	KNH_MAPPED_Float(ctx, sfp, y);
//}
//
///* ------------------------------------------------------------------------ */
//
//static TCAST knh_AffineConv_fmap__f2i(CTX ctx, knh_sfp_t *sfp, long rix)
//{
//	knh_AffineConv_t *af = (knh_AffineConv_t*)DP(sfp[1].mpr)->mapdata;
//	DBG_ASSERT(IS_AffineConv(af));
//	knh_float_t y = (sfp[0].fvalue * af->scale) + af->shift;
//	KNH_MAPPED_Int(ctx, sfp, (knh_int_t)y);
//}
//
///* ------------------------------------------------------------------------ */
//
//static TCAST knh_AffineConv_fmap__f2f(CTX ctx, knh_sfp_t *sfp, long rix)
//{
//	knh_AffineConv_t *af = (knh_AffineConv_t*)DP(sfp[1].mpr)->mapdata;
//	DBG_ASSERT(IS_AffineConv(af));
//	knh_float_t y = (sfp[0].fvalue * af->scale) + af->shift;
//	KNH_MAPPED_Float(ctx, sfp, y);
//}
//
///* ------------------------------------------------------------------------ */
//
//static knh_Ftmapper knh_Ftmapper_affine(knh_class_t scid, knh_class_t tcid)
//{
//	if(scid == CLASS_Int) {
//		if(tcid == CLASS_Int) return knh_AffineConv_fmap__i2i;
//		DBG_ASSERT(tcid == CLASS_Float);
//		return knh_AffineConv_fmap__i2f;
//	}
//	//DBG_ASSERT(scid == CLASS_Float);
//	{
//		if(tcid == CLASS_Int) return knh_AffineConv_fmap__f2i;
//		//DBG_ASSERT(tcid == CLASS_Float);
//		return knh_AffineConv_fmap__f2f;
//	}
//}
//
///* ------------------------------------------------------------------------ */
///* [TAFFINE] */
//
//static
//void KNH_TAFFINE(CTX ctx, knh_class_t scid, knh_class_t tcid, knh_float_t scale, knh_float_t shift)
//{
//	knh_TypeMap_t *mpr = new_TypeMap(ctx, FLAG_TypeMap_Affine, scid, tcid,
//			knh_Ftmapper_affine(ctx->share->ClassTBL[scid].bcid, ctx->share->ClassTBL[tcid].bcid),
//			(Object*)new_AffineConv(ctx, scale, shift));
//	knh_ClassMap_add(ctx, ctx->share->ClassTBL[scid].cmap, mpr);
//}
//
///* ------------------------------------------------------------------------ */
//
//KNHAPI2(void) knh_addAffineTypeMap(CTX ctx, knh_class_t scid, char *text, knh_float_t scale, knh_float_t shift)
//{
//	knh_class_t tcid = knh_getcid(ctx, B(text));
//	if(tcid != CLASS_unknown && ClassTBL(tcid)->bcid != tcid) {
//		KNH_TAFFINE(ctx, scid, tcid, scale, shift);
//		if(scale != K_FLOAT_ZERO) {
//			KNH_TAFFINE(ctx, tcid, scid, K_FLOAT_ONE / scale, -(shift/scale));
//		}
//	}
//}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
