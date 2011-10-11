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

#include <gsl/gsl_combination.h>
#include <konoha1.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */

static void GslComb_init(CTX ctx, knh_RawPtr_t *po)
{
	po->rawptr = NULL;
}

static void GslComb_free(CTX ctx, knh_RawPtr_t *po)
{
	if (po->rawptr != NULL) {
		gsl_combination_free((gsl_combination *)po->rawptr);
		po->rawptr = NULL;
	}
}

DEFAPI(void) defGslComb(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	cdef->name = "GslComb";
	cdef->init = GslComb_init;
	cdef->free = GslComb_free;
}

//## @Native GslComb GslComb.new(int n, int k);
KMETHOD GslComb_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t n = Int_to(size_t, sfp[1]);
	size_t k = Int_to(size_t, sfp[2]);
	knh_RawPtr_t *p = sfp[0].p;
	p->rawptr = (void *)gsl_combination_alloc(n, k);
	if (p->rawptr == NULL) {
		/* add error handling here */
	}
	RETURN_(p);
}

#ifdef __cplusplus
}
#endif
