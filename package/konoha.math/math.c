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

#ifdef K_USING_WIN32_
#define _USE_MATH_DEFINES
#endif

#include <math.h>

#ifdef __cplusplus 
extern "C" {
#endif

/* ------------------------------------------------------------------------ */

DEFAPI(void) defMath(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "Math";
}

static knh_FloatData_t MathConstFloat[] = {
		{"E", M_E},
		{"LOG2E",M_LOG2E},
		{"LOG10E",M_LOG10E},
		{"LN2",M_LN2},
		{"LN10",M_LN10},
		{"PI", M_PI},
		{"SQRT2",M_SQRT2},
		{NULL, KFLOAT_ZERO}
};

DEFAPI(void) constMath(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassFloatConst(ctx, cid, MathConstFloat);
}

KMETHOD Math_abs(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNi_(abs(Int_to(int, sfp[1])));
}

KMETHOD Math_fabs(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(fabs(Float_to(double, sfp[1])));
}

KMETHOD Math_pow(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(pow(Float_to(double, sfp[1]),Float_to(double, sfp[2])));
}

KMETHOD Math_ldexp(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(ldexp(Float_to(double, sfp[1]), Int_to(int, sfp[2])));
}

KMETHOD Math_modf(CTX ctx, ksfp_t *sfp _RIX)
{
	double iprt = Float_to(double, sfp[2]);
	RETURNf_(modf(Float_to(double, sfp[1]), &iprt));
}

KMETHOD Math_frexp(CTX ctx, ksfp_t *sfp _RIX)
{
	int exp = Int_to(int, sfp[2]);
	RETURNf_(frexp(Float_to(double, sfp[1]), &exp));
}

KMETHOD Math_fmod(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(fmod(Float_to(double, sfp[1]),Float_to(double, sfp[2])));
}

KMETHOD Math_ceil(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(ceil(Float_to(double, sfp[1])));
}

#ifdef K_USING_WIN32_
KMETHOD Math_round(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(round(Float_to(double, sfp[1])));
}

KMETHOD Math_nearbyint(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(nearbyint(Float_to(double, sfp[1])));
}
#endif

KMETHOD Math_floor(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(floor(Float_to(double, sfp[1])));
}

KMETHOD Math_sqrt(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(sqrt(Float_to(double, sfp[1])));
}

KMETHOD Math_exp(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(exp(Float_to(double, sfp[1])));
}

KMETHOD Math_log10(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(log10(Float_to(double, sfp[1])));
}

KMETHOD Math_log(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(log(Float_to(double, sfp[1])));
}

KMETHOD Math_sin(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(sin(Float_to(double, sfp[1])));
}

KMETHOD Math_cos(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(cos(Float_to(double, sfp[1])));
}

KMETHOD Math_tan(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(tan(Float_to(double, sfp[1])));
}

KMETHOD Math_asin(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(asin(Float_to(double, sfp[1])));
}

KMETHOD Math_acos(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(acos(Float_to(double, sfp[1])));
}

KMETHOD Math_atan(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(atan(Float_to(double, sfp[1])));
}

KMETHOD Math_atan2(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(atan2(Float_to(double, sfp[1]),Float_to(double, sfp[2])));
}

KMETHOD Math_sinh(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(sinh(Float_to(double, sfp[1])));
}

KMETHOD Math_cosh(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(cosh(Float_to(double, sfp[1])));
}

KMETHOD Math_tanh(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(tanh(Float_to(double, sfp[1])));
}

#if defined(K_USING_WIN32_)
KMETHOD Math_asinh(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(asinh(Float_to(double, sfp[1])));
}

KMETHOD Math_acosh(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(acosh(Float_to(double, sfp[1])));
}

KMETHOD Math_atanh(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(atanh(Float_to(double, sfp[1])));
}
#endif

/* ------------------------------------------------------------------------ */

#ifdef _SETUP

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_LoaderAPI_t *kapi)
{
	kapi->setPackageProperty(ctx, "name", "math");
	kapi->setPackageProperty(ctx, "version", "1.0");
	RETURN_PKGINFO("konoha.math");
}

#endif

#ifdef K_USING_KONOHA_MATH

#endif

#ifdef __cplusplus
}
#endif

