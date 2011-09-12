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
// **************************************************************************

#define USE_STRUCT_Tuple
#include <gsl/gsl_poly.h>
#include <konoha1.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */

DEFAPI(void) defGslPoly(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "GslPoly";
}

//## @Native Tuple<float,float> GslPoly.solveQuadratic(float a, float b, float c);
KMETHOD GslPoly_solveQuadratic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	double a = (double)sfp[1].fvalue;
	double b = (double)sfp[2].fvalue;
	double c = (double)sfp[3].fvalue;
	double x0 = 0.0, x1 = 0.0;
	gsl_poly_solve_quadratic(a, b, c, &x0, &x1);
	knh_Tuple_t *t = (knh_Tuple_t*)new_ReturnObject(ctx, sfp);
	t->ffields[0] = (knh_float_t)x0;
	t->ffields[1] = (knh_float_t)x1;
	RETURN_(t);
}

#ifdef __cplusplus
}
#endif
