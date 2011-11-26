/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c)  2011-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * See www.konohaware.org/license.html for further information.
 *
 * (1) GNU Lesser General Public License 3.0 (with KONOHA_UNDER_LGPL3)
 * (2) Konoha Software Foundation License 1.0
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

// **************************************************************************
// LIST OF CONTRIBUTERS
//  kimio - Kimio Kuramitsu, Yokohama National University, Japan
//  shinpei - Shinpei Nakata, Yokohama National University, Japan
//  okachin - Okamoto Yuki, Yokohama National University Japan
// **************************************************************************

#define K_INTERNAL
#include <gsl/gsl_math.h>
#include <konoha1.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */

static knh_FloatData_t GslMathConstFloat[] = {
	{"E", M_E},
	{"LOG2E", M_LOG2E},
	{"LOG10E", M_LOG10E},
	{"SQRT2", M_SQRT2},
	{"SQRT1_2", M_SQRT1_2},
	{"SQRT3", M_SQRT3},
	{"PI", M_PI},
	{"PI_2", M_PI_2},
	{"PI_4", M_PI_4},
	{"SQRTPI", M_SQRTPI},
	{"LN10", M_LN10},
	{"LN2", M_LN2},
	{"LNPI", M_LNPI},
	{"EULER", M_EULER},
	{NULL, KFLOAT_ZERO}
};

DEFAPI(void) constGslMath(CTX ctx, kclass_t cid, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassFloatConst(ctx, cid, GslMathConstFloat);
}

KMETHOD GslMath_isNan(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNb_(gsl_isnan(Float_to(const double, sfp[1])));
}

KMETHOD GslMath_isInf(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNi_(gsl_isinf(Float_to(const double, sfp[1])));
}

KMETHOD GslMath_isFinite(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNb_(gsl_finite(Float_to(const double, sfp[1])));
}

KMETHOD GslMath_log1p(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(gsl_log1p(Float_to(const double, sfp[1])));
}

KMETHOD GslMath_expm1(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(gsl_expm1(Float_to(const double, sfp[1])));
}

KMETHOD GslMath_hypot(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(gsl_hypot(Float_to(const double, sfp[1]), Float_to(const double, sfp[2])));
}

KMETHOD GslMath_hypot3(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(gsl_hypot3(Float_to(const double, sfp[1]), Float_to(const double, sfp[2]), Float_to(const double, sfp[3])));
}

KMETHOD GslMath_acosh(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(gsl_acosh(Float_to(const double, sfp[1])));
}

KMETHOD GslMath_asinh(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(gsl_asinh(Float_to(const double, sfp[1])));
}

KMETHOD GslMath_atanh(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(gsl_atanh(Float_to(const double, sfp[1])));
}

KMETHOD GslMath_ldexp(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(gsl_ldexp(Float_to(double, sfp[1]), Int_to(int, sfp[2])));
}

KMETHOD GslMath_frexp(CTX ctx, ksfp_t *sfp _RIX)
{
	double x = Float_to(double, sfp[1]);
	int e;
	double f = gsl_frexp(x, &e);
	kTuple *t = (kTuple*)new_ReturnObject(ctx, sfp);
	t->ffields[0] = (kfloat_t)f;
	t->ifields[1] = (kint_t)e;
	RETURN_(t);
}

KMETHOD GslMath_powInt(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(gsl_pow_int(Float_to(double, sfp[1]), Int_to(int, sfp[2])));
}

KMETHOD GslMath_pow2(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(gsl_pow_2(Float_to(const double, sfp[1])));
}

KMETHOD GslMath_pow3(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(gsl_pow_3(Float_to(const double, sfp[1])));
}

KMETHOD GslMath_pow4(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(gsl_pow_4(Float_to(const double, sfp[1])));
}

KMETHOD GslMath_pow5(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(gsl_pow_5(Float_to(const double, sfp[1])));
}

KMETHOD GslMath_pow6(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(gsl_pow_6(Float_to(const double, sfp[1])));
}

KMETHOD GslMath_pow7(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(gsl_pow_7(Float_to(const double, sfp[1])));
}

KMETHOD GslMath_pow8(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(gsl_pow_8(Float_to(const double, sfp[1])));
}

KMETHOD GslMath_pow9(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNf_(gsl_pow_9(Float_to(const double, sfp[1])));
}

KMETHOD GslMath_sign(CTX ctx, ksfp_t *sfp _RIX)
{
	int i = GSL_SIGN(Float_to(double, sfp[1]));
	if(i == 1) RETURNb_(1)
	else RETURNb_(0);
}

KMETHOD GslMath_isOdd(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNb_(GSL_IS_ODD(Int_to(int, sfp[1])));
}

KMETHOD GslMath_isEven(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNb_(GSL_IS_EVEN(Int_to(int, sfp[1])));
}

KMETHOD GslMath_fcmp(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNi_(gsl_fcmp(Float_to(double, sfp[1]), Float_to(double, sfp[2]), Float_to(double, sfp[3])));
}

DEFAPI(void) defGslMath(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "GslMath";
}

#ifdef __cplusplus
}
#endif
