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
 * (1) GNU General Public License 3.0 (with KONOHA_UNDER_LGPL3)
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

#include <konoha1.h>

#ifdef K_USING_WINTHREAD_
#define _USE_MATH_DEFINES
#endif

#include <math.h>

#ifdef __cplusplus 
extern "C" {
#endif

/* ------------------------------------------------------------------------ */

METHOD Math_fabs(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(fabs(Float_to(double, sfp[1])));
}

METHOD Math_abs(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(fabs(Float_to(double, sfp[1])));
}

METHOD Math_pow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(pow(Float_to(double, sfp[1]),Float_to(double, sfp[2])));
}

METHOD Math_ldexp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(ldexp(Float_to(double, sfp[1]), Int_to(int, sfp[2])));
}

METHOD Math_modf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	double iprt = Float_to(double, sfp[2]);
	RETURNf_(modf(Float_to(double, sfp[1]), &iprt));
}

METHOD Math_frexp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int exp = Int_to(int, sfp[2]);
	RETURNf_(frexp(Float_to(double, sfp[1]), &exp));
}

METHOD Math_fmod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(fmod(Float_to(double, sfp[1]),Float_to(double, sfp[2])));
}

METHOD Math_ceil(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(ceil(Float_to(double, sfp[1])));
}

#if K_USING_WINTHREAD_
METHOD Math_round(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(round(Float_to(double, sfp[1])));
}

METHOD Math_nearbyint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(nearbyint(Float_to(double, sfp[1])));
}
#endif

METHOD Math_floor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(floor(Float_to(double, sfp[1])));
}

METHOD Math_sqrt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(sqrt(Float_to(double, sfp[1])));
}

METHOD Math_exp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(exp(Float_to(double, sfp[1])));
}

METHOD Math_log10(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(log10(Float_to(double, sfp[1])));
}

METHOD Math_log(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(log(Float_to(double, sfp[1])));
}

METHOD Math_sin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(sin(Float_to(double, sfp[1])));
}

METHOD Math_cos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(cos(Float_to(double, sfp[1])));
}

METHOD Math_tan(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(tan(Float_to(double, sfp[1])));
}

METHOD Math_asin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(asin(Float_to(double, sfp[1])));
}

METHOD Math_acos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(acos(Float_to(double, sfp[1])));
}

METHOD Math_atan(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(atan(Float_to(double, sfp[1])));
}

METHOD Math_atan2(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(atan2(Float_to(double, sfp[1]),Float_to(double, sfp[2])));
}

METHOD Math_sinh(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(sinh(Float_to(double, sfp[1])));
}

METHOD Math_cosh(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(cosh(Float_to(double, sfp[1])));
}

METHOD Math_tanh(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(tanh(Float_to(double, sfp[1])));
}

#if defined(K_USING_WINTHREAD_)
METHOD Math_asinh(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(asinh(Float_to(double, sfp[1])));
}

METHOD Math_acosh(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(acosh(Float_to(double, sfp[1])));
}

METHOD Math_atanh(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNf_(atanh(Float_to(double, sfp[1])));
}
#endif

/* ------------------------------------------------------------------------ */

#ifdef _SETUP

static knh_FloatData_t FloatConstData[] = {
	{"Math.E", M_E},
	{"Math.LOG2E",M_LOG2E},
	{"Math.LOG10E",M_LOG10E},
	{"Math.LN2",M_LN2},
	{"Math.LN10",M_LN10},
	{"Math.PI", M_PI},
//	{"Math.PI2",M_PI_2},
//	{"Math.PI4",M_PI_4},
	{"Math.SQRT2",M_SQRT2},
	{NULL, K_FLOAT_ZERO}
};

EXPORTAPI(const knh_PackageDef_t*) init(CTX ctx)
{
	static const knh_PackageDef_t pkgdef = KNH_PKGINFO("math", "1.0", "Konoha Standard Math Library", NULL);
	return &pkgdef;
}

EXPORTAPI(void) MathCONST(CTX ctx, const knh_PackageLoaderAPI_t *kapi, knh_NameSpace_t *ns)
{
	if(ns == NULL) {
		kapi->loadFloatData(ctx, FloatConstData);
	}
}

#endif

#ifdef __cplusplus
}
#endif

