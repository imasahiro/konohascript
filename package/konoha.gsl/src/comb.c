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
//  takeo - Takeo Onoda, Yokohama National University, Japan
// **************************************************************************

#include <gsl/gsl_combination.h>
#include <konoha1.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */

static void GslComb_init(CTX ctx, kRawPtr *po)
{
	po->rawptr = NULL;
}

static void GslComb_free(CTX ctx, kRawPtr *po)
{
	if (po->rawptr != NULL) {
		gsl_combination_free((gsl_combination *)po->rawptr);
		po->rawptr = NULL;
	}
}

DEFAPI(void) defGslComb(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "GslComb";
	cdef->init = GslComb_init;
	cdef->free = GslComb_free;
}

//## @Native GslComb GslComb.new(int n, int k);
KMETHOD GslComb_new(CTX ctx, ksfp_t *sfp _RIX)
{
	size_t n = Int_to(size_t, sfp[1]);
	size_t k = Int_to(size_t, sfp[2]);
	kRawPtr *p = sfp[0].p;
	p->rawptr = gsl_combination_calloc(n, k);
	RETURN_(p);
}

//## @Native void GslComb.initFirst();
KMETHOD GslComb_initFirst(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_combination *c = RawPtr_to(gsl_combination *, sfp[0]);
	gsl_combination_init_first(c);
	RETURNvoid_();
}

//## @Native void GslComb.initLast();
KMETHOD GslComb_initLast(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_combination *c = RawPtr_to(gsl_combination *, sfp[0]);
	gsl_combination_init_last(c);
	RETURNvoid_();
}

//## @Narive GslComb GslComb.memcpy();
KMETHOD GslComb_memcpy(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_combination *c = RawPtr_to(gsl_combination *, sfp[0]);
	size_t n = gsl_combination_n(c);
	size_t k = gsl_combination_k(c);
	gsl_combination *dest = gsl_combination_alloc(n, k);
	gsl_combination_memcpy(dest, c);
	if (dest != NULL) {
		kRawPtr *ret = new_ReturnRawPtr(ctx, sfp, dest);
		RETURN_(ret);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## @Narive int GslComb.get(int i);
KMETHOD GslComb_get(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_combination *c = RawPtr_to(gsl_combination *, sfp[0]);
	size_t i = Int_to(size_t, sfp[1]);
	size_t ret = gsl_combination_get(c, i);
	RETURNi_(ret);
}

//## @Narive int GslComb.getN();
KMETHOD GslComb_getN(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_combination *c = RawPtr_to(gsl_combination *, sfp[0]);
	size_t ret = gsl_combination_n(c);
	RETURNi_(ret);
}

//## @Narive int GslComb.getK();
KMETHOD GslComb_getK(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_combination *c = RawPtr_to(gsl_combination *, sfp[0]);
	size_t ret = gsl_combination_k(c);
	RETURNi_(ret);
}

//## @Narive Array<Int> GslComb.getData();
KMETHOD GslComb_getData(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_combination *c = RawPtr_to(gsl_combination *, sfp[0]);
	size_t *data = gsl_combination_data(c);
	size_t k = gsl_combination_k(c);
	kArray *res = new_Array(ctx, CLASS_Int, k);
	BEGIN_LOCAL(ctx, lsfp, k);
	int i;
	for (i = 0; i < k; i++) {
		lsfp[i].ivalue = data[i];
		//knh_Array_add(ctx, res, data[i]);
	}
	res->api->multiadd(ctx, res, lsfp);
	END_LOCAL(ctx, lsfp);
	RETURN_(res);
}

//## @Native bool GslComb.valid();
KMETHOD GslComb_valid(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_combination *c = RawPtr_to(gsl_combination *, sfp[0]);
	if (c != NULL) {
		int ret = gsl_combination_valid(c);
		RETURNb_(ret);
	} else {
		RETURNb_(0);
	}
}

//## @Native GslComb GslComb.next();
KMETHOD GslComb_next(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_combination *src = RawPtr_to(gsl_combination *, sfp[0]);
	size_t n = gsl_combination_n(src);
	size_t k = gsl_combination_k(src);
	gsl_combination *dist = gsl_combination_calloc(n, k);
	gsl_combination_memcpy(dist, src);

	int flag = gsl_combination_next(dist);
	if (flag == GSL_SUCCESS) {
		kRawPtr *ret = new_ReturnRawPtr(ctx, sfp, dist);
		RETURN_(ret);
	} else {
		gsl_combination_free(dist);
	}
	RETURN_(KNH_NULL);
}

//## @Native GslComb GslComb.prev();
KMETHOD GslComb_prev(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_combination *src = RawPtr_to(gsl_combination *, sfp[0]);
	size_t n = gsl_combination_n(src);
	size_t k = gsl_combination_k(src);
	gsl_combination *dist = gsl_combination_calloc(n, k);
	gsl_combination_memcpy(dist, src);

	int flag = gsl_combination_prev(dist);
	if (flag == GSL_SUCCESS) {
		kRawPtr *ret = new_ReturnRawPtr(ctx, sfp, dist);
		RETURN_(ret);
	} else {
		gsl_combination_free(dist);
	}
	RETURN_(KNH_NULL);
}

#ifdef __cplusplus
}
#endif
