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
//  shunsuke - Shunsuke Shida, Yokohama National University, Japan
// **************************************************************************

#include <gsl/gsl_multiset.h>
#include <konoha1.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */

static void GslMulti_init(CTX ctx, kRawPtr *po)
{
	po->rawptr = NULL;
}

static void GslMulti_free(CTX ctx, kRawPtr *po)
{
	if (po->rawptr != NULL) {
		gsl_multiset_free((gsl_multiset *)po->rawptr);
		po->rawptr = NULL;
	}
}

DEFAPI(void) defGslMulti(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "GslMulti";
	cdef->init = GslMulti_init;
	cdef->free = GslMulti_free;
}

//## @Native GslMulti GslMulti.new(int n, int k);
KMETHOD GslMulti_new(CTX ctx, ksfp_t *sfp _RIX)
{
	size_t n = Int_to(size_t, sfp[1]);
	size_t k = Int_to(size_t, sfp[2]);
	kRawPtr *p = sfp[0].p;
	p->rawptr = gsl_multiset_calloc(n, k);
	RETURN_(p);
}

//## @Native void GslMulti.InitFirst();
KMETHOD GslMulti_initFirst(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_multiset *c = RawPtr_to(gsl_multiset *, sfp[0]);
	gsl_multiset_init_first(c);
	RETURNvoid_();
}

//## @Native void GslMulti.InitLast();
KMETHOD GslMulti_initLast(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_multiset *c = RawPtr_to(gsl_multiset *, sfp[0]);
	gsl_multiset_init_last(c);
	RETURNvoid_();
}

//## @Native GslMulti GslMulti.copy();
KMETHOD GslMulti_copy(CTX ctx, ksfp_t *sfp _RIX)
{
	const gsl_multiset *src = RawPtr_to(const gsl_multiset *, sfp[0]);
	size_t n = gsl_multiset_n(src);
	size_t k = gsl_multiset_k(src);
	gsl_multiset *dest = gsl_multiset_alloc(n, k);
	gsl_multiset_memcpy(dest, src);
	kRawPtr *res = new_ReturnRawPtr(ctx, sfp, dest);
	RETURN_(res);
}

//## @Native int GslMulti.get(int i);
KMETHOD GslMulti_get(CTX ctx, ksfp_t *sfp _RIX)
{
	const gsl_multiset *c = RawPtr_to(const gsl_multiset *, sfp[0]);
	size_t i = Int_to(size_t, sfp[1]);
	RETURNi_(gsl_multiset_get(c, i));
}

//## @Native int GslMulti.range();
KMETHOD GslMulti_range(CTX ctx, ksfp_t *sfp _RIX)
{
	const gsl_multiset *c = RawPtr_to(const gsl_multiset *, sfp[0]);
	size_t range = gsl_multiset_n(c);
	RETURNi_(range);
}

//## @Native int GslMulti.size();
KMETHOD GslMulti_size(CTX ctx, ksfp_t *sfp _RIX)
{
	const gsl_multiset *c = RawPtr_to(const gsl_multiset *, sfp[0]);
	size_t size = gsl_multiset_k(c);
	RETURNi_(size);
}

//## @Native Array<Int> GslMulti.getData();
KMETHOD GslMulti_getData(CTX ctx, ksfp_t *sfp _RIX)
{
	const gsl_multiset *c = RawPtr_to(const gsl_multiset *, sfp[0]);
	size_t *data = gsl_multiset_data(c);
	size_t k = gsl_multiset_k(c);
	int i = 0;
	kArray *res = new_Array(ctx, CLASS_Int, 0);
	for (; i < k; i++) {
		knh_Array_add(ctx, res, data[i]);
	}
	RETURN_(res);
}

//## @Native boolean GslMulti.valid();
KMETHOD GslMulti_valid(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_multiset *c = RawPtr_to(gsl_multiset *, sfp[0]);
	RETURNb_(gsl_multiset_valid(c));
}

//## @Native GslMulti GslMulti.next();
KMETHOD GslMulti_next(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_multiset *c = RawPtr_to(gsl_multiset *, sfp[0]);
	size_t n = gsl_multiset_n(c);
	size_t k = gsl_multiset_k(c);
	gsl_multiset *dest = gsl_multiset_alloc(n, k);
	gsl_multiset_memcpy(dest, c);
	int res = gsl_multiset_next(dest);
	if (res == GSL_SUCCESS) {
		RETURN_(new_ReturnRawPtr(ctx, sfp, dest));
	} else {
		KNH_NTRACE2(ctx, "gsl.multiset", K_NOTICE, KNH_LDATA(LOG_s("msg", gsl_strerror(GSL_FAILURE))));
		RETURN_(KNH_NULL);
	}
}

//## @Native GslMulti GslMulti.prev();
KMETHOD GslMulti_prev(CTX ctx, ksfp_t *sfp _RIX)
{
	gsl_multiset *c = RawPtr_to(gsl_multiset *, sfp[0]);
	size_t n = gsl_multiset_n(c);
	size_t k = gsl_multiset_k(c);
	gsl_multiset *dest = gsl_multiset_alloc(n, k);
	gsl_multiset_memcpy(dest, c);
	int res = gsl_multiset_prev(dest);
	if (res == GSL_SUCCESS) {
		RETURN_(new_ReturnRawPtr(ctx, sfp, dest));
	} else {
		KNH_NTRACE2(ctx, "gsl.multiset", K_NOTICE, KNH_LDATA(LOG_s("msg", gsl_strerror(GSL_FAILURE))));
		RETURN_(KNH_NULL);
	}

}

#ifdef __cplusplus
}
#endif
