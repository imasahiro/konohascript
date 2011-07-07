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

#include<time.h>
#ifdef K_USING_POSIX_
#include<unistd.h>
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

void knh_srand(knh_uint_t seed)
{
	if(seed == 0) {
		/* You may choose a more secure way of generating the seed */
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
}

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

/* ------------------------------------------------------------------------ */

knh_Int_t* new_Int_(CTX ctx, knh_class_t cid, knh_int_t value)
{
	const knh_ClassTBL_t *ct = ClassTBL(cid);
	if(ct->constPoolMapNULL != NULL) {
		knh_Int_t *n = knh_PtrMap_getI(ctx, ct->constPoolMapNULL, (knh_ndata_t)value);
		if(n == NULL) {
			n = (knh_Int_t*)new_hObject_(ctx, ct);
			n->n.ivalue = value;
			knh_PtrMap_addI(ctx, ct->constPoolMapNULL, n);
		}
		return n;
	}
	else {
		knh_Int_t *b = (knh_Int_t*)new_hObject_(ctx, ct);
		b->n.ivalue = value;
		return b;
	}
}

knh_Float_t* new_Float_(CTX ctx, knh_class_t cid, knh_float_t value)
{
	const knh_ClassTBL_t *ct = ClassTBL(cid);
	if(ct->constPoolMapNULL != NULL) {
		knh_sfp_t lsfp;
		lsfp.fvalue = value;
		knh_Int_t *n = knh_PtrMap_getI(ctx, ct->constPoolMapNULL, lsfp.ndata);
		if(n == NULL) {
			n = (knh_Int_t*)new_hObject_(ctx, ct);
			n->n.fvalue = value;
			knh_PtrMap_addI(ctx, ct->constPoolMapNULL, n);
		}
		return (knh_Float_t*)n;
	}
	else {
		knh_Float_t *b = (knh_Float_t*)new_hObject_(ctx, ct);
		b->n.fvalue = value;
		return b;
	}
}

KNHAPI2(knh_Int_t*) new_Int(CTX ctx, knh_int_t value)
{
	return new_Int_(ctx, CLASS_Int, value);
}

KNHAPI2(knh_Float_t*) new_Float(CTX ctx, knh_float_t value)
{
	return new_Float_(ctx, CLASS_Float, value);
}

Object* new_Boxing(CTX ctx, knh_sfp_t *sfp, const knh_ClassTBL_t *ct)
{
	knh_Object_t *o = NULL;
	if(ct->constPoolMapNULL != NULL) {
		o = (knh_Object_t*)knh_PtrMap_getI(ctx, ct->constPoolMapNULL, sfp[0].ndata);
		if(o == NULL) {
			o = new_hObject_(ctx, ct);
			((knh_Int_t*)o)->n.data = sfp[0].ndata;
			knh_PtrMap_addI(ctx, ct->constPoolMapNULL, (knh_Int_t*)o);
		}
	}
	else {
		o = new_hObject_(ctx, ct);
		((knh_Int_t*)o)->n.data = sfp[0].ndata;
	}
	return o;
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
