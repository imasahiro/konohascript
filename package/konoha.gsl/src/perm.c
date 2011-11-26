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
//  sugy - Taihei Sugimoto, Yokohama National University, Japan
// **************************************************************************

#define USE_STRUCT_OutputStream
#define USE_STRUCT_InputStream

#include <gsl/gsl_permutation.h>
#include <konoha1.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */

static void GslPerm_init(CTX ctx, kRawPtr *po)
{
	po->rawptr = NULL;
}

static void GslPerm_free(CTX ctx, kRawPtr *po)
{
	if (po->rawptr != NULL) {
		gsl_permutation_free((gsl_permutation *)po->rawptr);
		po->rawptr = NULL;
	}
}

DEFAPI(void) defGslPerm(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "GslPerm";
	cdef->init = GslPerm_init;
	cdef->free = GslPerm_free;
}

//## @Native GslPerm GslPerm.new(int n);
KMETHOD GslPerm_new(CTX ctx, ksfp_t *sfp _RIX)
{
	size_t n = Int_to(size_t, sfp[1]);
	kRawPtr *p = sfp[0].p;
	p->rawptr = (void *)gsl_permutation_alloc(n);
	gsl_permutation_init(p->rawptr);
	RETURN_(p);
}

//## @Native int GslPerm.get(int i);
KMETHOD GslPerm_get(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_permutation *p = RawPtr_to(gsl_permutation *, sfp[0]);
	const size_t i = Int_to(const size_t, sfp[1]);
	RETURNi_(gsl_permutation_get(p, i));
}

//## @Native int GslPerm.swap(int i, int j);
KMETHOD GslPerm_swap(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_permutation *p = RawPtr_to(gsl_permutation *, sfp[0]);
	const size_t i = Int_to(const size_t, sfp[1]);
	const size_t j = Int_to(const size_t, sfp[2]);
	RETURNi_(gsl_permutation_swap(p, i, j));
}

//## @Native int GslPerm.size();
KMETHOD GslPerm_size(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_permutation *p = RawPtr_to(gsl_permutation *, sfp[0]);
	RETURNi_(gsl_permutation_size(p));
}

//## @Native Array<int> GslPerm.data();
KMETHOD GslPerm_data(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_permutation *p = RawPtr_to(gsl_permutation *, sfp[0]);
	size_t psize = gsl_permutation_size(p);
	size_t *data = gsl_permutation_data(p);
	kArray *res = new_Array(ctx, CLASS_Int, 0);
	int i;
	for(i = 0; i < psize; i++){
		knh_Array_add(ctx, res, data[i]);
	}
	RETURN_(res);
}

//## @Native int GslPerm.valid();
KMETHOD GslPerm_valid(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_permutation *p = RawPtr_to(gsl_permutation *, sfp[0]);
	RETURNi_(gsl_permutation_valid(p));
}

//## @Native void GslPerm.reverse();
KMETHOD GslPerm_reverse(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_permutation *p = RawPtr_to(gsl_permutation *, sfp[0]);
	gsl_permutation_reverse(p);
	RETURNvoid_();
}

//## @Native GslPerm GslPerm.inverse();
KMETHOD GslPerm_inverse(CTX ctx, ksfp_t *sfp _RIX)
{
	const gsl_permutation *p = RawPtr_to(const gsl_permutation *, sfp[0]);
	size_t psize = gsl_permutation_size(p);
	gsl_permutation *inv = gsl_permutation_alloc(psize);
	gsl_permutation_inverse(inv, p);
	RETURN_(new_ReturnRawPtr(ctx, sfp, inv));
}

//## @Native int GslPerm.next();
KMETHOD GslPerm_next(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_permutation *p = RawPtr_to(gsl_permutation *, sfp[0]);
	RETURNi_(gsl_permutation_next(p));
}

//## @Native int GslPerm.prev();
KMETHOD GslPerm_prev(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_permutation *p = RawPtr_to(gsl_permutation *, sfp[0]);
	RETURNi_(gsl_permutation_prev(p));
}

//## @Native GslPerm GslPerm.mul(GslPerm pb);
KMETHOD GslPerm_mul(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_permutation *pa = RawPtr_to(gsl_permutation *, sfp[0]);
	size_t psize = gsl_permutation_size(pa);
	gsl_permutation *p = gsl_permutation_alloc(psize);
	const gsl_permutation *pb = RawPtr_to(gsl_permutation *, sfp[1]);
	gsl_permutation_mul(p, pa, pb);
	RETURN_(new_ReturnRawPtr(ctx, sfp, p));
}

//## @Native int GslPerm.fprintf(OutputStream stream, string formatter);
KMETHOD GslPerm_fprintf(CTX ctx, ksfp_t *sfp _RIX)
{
//	const gsl_permutation *p = RawPtr_to(const gsl_permutation *, sfp[0]);
//	kOutputStream *w = sfp[1].w;
//	knh_OutputStream_flush(ctx, w);
//	const char *format = String_to(const char *, sfp[2]);
//	FILE *file = (FILE*)DP(w)->fio;
//	gsl_permutation_fprintf(file, p, format);
	KNH_TODO("FILE pointer is not always given."); // by kimio
	RETURNvoid_();
}

//## @Native GslPerm GslPerm.linearToCanonical();
KMETHOD GslPerm_linearToCanonical(CTX ctx, ksfp_t *sfp _RIX)
{
	const gsl_permutation *lp = RawPtr_to(const gsl_permutation *, sfp[0]);
	size_t lpsize = gsl_permutation_size(lp);
	gsl_permutation *cp = gsl_permutation_alloc(lpsize);
	gsl_permutation_linear_to_canonical(cp, lp);
	RETURN_(new_ReturnRawPtr(ctx, sfp, cp));
}

//## @Native GslPerm GslPerm.canonicalToLinear();
KMETHOD GslPerm_canonicalToLinear(CTX ctx, ksfp_t *sfp _RIX)
{
	const gsl_permutation *cp = RawPtr_to(const gsl_permutation *, sfp[0]);
	size_t cpsize = gsl_permutation_size(cp);
	gsl_permutation *lp = gsl_permutation_alloc(cpsize);
	gsl_permutation_canonical_to_linear(lp, cp);
	RETURN_(new_ReturnRawPtr(ctx, sfp, lp));
}

//## @Native int GslPerm.inversions();
KMETHOD GslPerm_inversions(CTX ctx, ksfp_t *sfp _RIX)
{
	const gsl_permutation *p = RawPtr_to(const gsl_permutation *, sfp[0]);
	RETURNi_(gsl_permutation_inversions(p));
}

//## @Native int GslPerm.linearCycles();
KMETHOD GslPerm_linearCycles(CTX ctx, ksfp_t *sfp _RIX)
{
	const gsl_permutation *lp = RawPtr_to(const gsl_permutation *, sfp[0]);
	RETURNi_(gsl_permutation_linear_cycles(lp));
}

//## @Native int GslPerm.canonicalCycles();
KMETHOD GslPerm_canonicalCycles(CTX ctx, ksfp_t *sfp _RIX)
{
	const gsl_permutation *cp = RawPtr_to(const gsl_permutation *, sfp[0]);
	RETURNi_(gsl_permutation_canonical_cycles(cp));
}

#ifdef __cplusplus
}
#endif
