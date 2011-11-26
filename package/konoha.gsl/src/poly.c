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
//  yukkiwakka - Yuuki Wakamatsu, Yokohama National University, Japan
// **************************************************************************

#define USE_STRUCT_Tuple
#include <gsl/gsl_poly.h>
#include <konoha1.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */

DEFAPI(void) defGslPoly(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "GslPoly";
}

//## @Native float GslPoly.eval(float[] c, float x);
KMETHOD GslPoly_eval(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *c = sfp[1].a;
	double x = sfp[2].fvalue;
	double r = gsl_poly_eval(c->flist, knh_Array_size(c), x);
	RETURNf_(r);
}

//## @Native int GslPoly.evalDerivs(float[] c, float x, float[] res);
KMETHOD GslPoly_evalDerivs(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *c = sfp[1].a;
	double x = sfp[2].fvalue;
	kArray *res = sfp[3].a;
	int n = gsl_poly_eval_derivs(c->flist, knh_Array_size(c), x, res->flist, knh_Array_size(res));
	RETURNi_(n);
}

//## @Native int GslPoly.ddInit(float[] dd, float[] xa, double ya[]);
KMETHOD GslPoly_ddInit(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *dd = sfp[1].a;
	kArray *xa = sfp[2].a;
	kArray *ya = sfp[3].a;
	int size = knh_Array_size(dd);
	int r = gsl_poly_dd_init(dd->flist, xa->flist, ya->flist, size);
	RETURNi_(r);
}

//## @Native float GslPoly.ddEval(float[] dd, float[] xa, double x);
KMETHOD GslPoly_ddEval(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *dd = sfp[1].a;
	kArray *xa = sfp[2].a;
	double x = sfp[3].fvalue;
	double r = gsl_poly_dd_eval(dd->flist, xa->flist, knh_Array_size(xa), x);
	RETURNf_(r);
}

//## @Native int GslPoly.ddTaylor(float[] c, float xp, float[] dd, float[] xa, double w[]);
KMETHOD GslPoly_ddTaylor(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *c = sfp[1].a;
	double xp = sfp[2].fvalue;
	kArray *dd = sfp[3].a;
	kArray *xa = sfp[4].a;
	kArray *w = sfp[5].a;
	int r = gsl_poly_dd_taylor(c->flist, xp, dd->flist, xa->flist, knh_Array_size(dd), w->flist);
	RETURNi_(r);
}

//## @Native Tuple<float,float> GslPoly.solveQuadratic(float a, float b, float c);
KMETHOD GslPoly_solveQuadratic(CTX ctx, ksfp_t *sfp _RIX)
{
	double a = Float_to(double, sfp[1]);
	double b = Float_to(double, sfp[2]);
	double c = Float_to(double, sfp[3]);
	double x0 = 0.0, x1 = 0.0;
	gsl_poly_solve_quadratic(a, b, c, &x0, &x1);
	kTuple *t = (kTuple*)new_ReturnObject(ctx, sfp);
	t->ffields[0] = (kfloat_t)x0;
	t->ffields[1] = (kfloat_t)x1;
	RETURN_(t);
}

//## @Native Tuple<float,float,float> GslPoly.solveCubic(float a, float b, float c);
KMETHOD GslPoly_solveCubic(CTX ctx, ksfp_t *sfp _RIX)
{
	double a = Float_to(double, sfp[1]);
	double b = Float_to(double, sfp[2]);
	double c = Float_to(double, sfp[3]);
	double x0 = 0.0, x1 = 0.0, x2 = 0.0;
	gsl_poly_solve_cubic(a, b, c, &x0, &x1, &x2);
	kTuple *t = (kTuple*)new_ReturnObject(ctx, sfp);
	t->ffields[0] = (kfloat_t)x0;
	t->ffields[1] = (kfloat_t)x1;
	t->ffields[2] = (kfloat_t)x2;
	RETURN_(t);
}

//## @Native float[] GslPoly.complexSolve(float[] a, GslPolyComplexWorkspace ws);
KMETHOD GslPoly_complexSolve(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *a = sfp[1].a;
	int size = knh_Array_size(a);
	kArray *z = new_Array(ctx, CLASS_Float, (size - 1) * 2);
	z->size = (size - 1) * 2;
	gsl_poly_complex_workspace *ws;
	if(IS_NULL(sfp[2].o)) {
		ws = gsl_poly_complex_workspace_alloc(size);
	}else{
		ws = RawPtr_to(gsl_poly_complex_workspace *, sfp[2]);
	}
	gsl_poly_complex_solve(a->flist, size, ws, z->flist);
	if(IS_NULL(sfp[2].o)) {
		gsl_poly_complex_workspace_free(ws);
	}
	RETURN_(z);
}

/* ------------------------------------------------------------------------ */

static void GslPolyComplexWorkspace_init(CTX ctx, kRawPtr *po)
{
	po->rawptr = NULL;
}

static void GslPolyComplexWorkspace_free(CTX ctx, kRawPtr *po)
{
	if (po->rawptr != NULL) {
		gsl_poly_complex_workspace_free((gsl_poly_complex_workspace *)po->rawptr);
		po->rawptr = NULL;
	}
}

DEFAPI(void) defGslPolyComplexWorkspace(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "GslPolyComplexWorkspace";
	cdef->init = GslPolyComplexWorkspace_init;
	cdef->free = GslPolyComplexWorkspace_free;
}

//## @Native GslPolyComplexWorkspace GslPolyComplexWorkspace.new(int size);
KMETHOD GslPolyComplexWorkspace_new(CTX ctx, ksfp_t *sfp _RIX)
{
	size_t size = Int_to(size_t, sfp[1]);
	kRawPtr *p = sfp[0].p;
	p->rawptr = gsl_poly_complex_workspace_alloc(size);
	RETURN_(p);
}

#ifdef __cplusplus
}
#endif
