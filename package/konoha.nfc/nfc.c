/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c)  2010-      Konoha Team konohaken@googlegroups.com
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
//  chen_ji - Takuma Wakamori, Yokohama National University, Japan
// **************************************************************************

#include <konoha1.h>
#include <nfc/nfc.h>
#include <nfc/nfc-types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ======================================================================== */
// [PRIVATE FUNCTIONS]

static void Pasori_init(CTX ctx, kRawPtr *po)
{
	po->rawptr = NULL;
}

static void Pasori_free(CTX ctx, kRawPtr *po)
{
	if (po->rawptr != NULL) {
		nfc_disconnect((nfc_device_t *)po->rawptr);
		po->rawptr = NULL;
	}
}


/* ======================================================================== */
// [KMETHODS]

//## @Native Pasori Pasori.new();
KMETHOD Pasori_new(CTX ctx, ksfp_t *sfp _RIX)
{
	nfc_device_t *pnd = nfc_connect(NULL);
	if (pnd == NULL) {
		KNH_NTRACE2(ctx, "nfc_connect", K_FAILED, KNH_LDATA0);
		kObjectoNULL(ctx, sfp[0].o);
		RETURN_(sfp[0].o);
	}
	RETURN_(new_ReturnRawPtr(ctx, sfp, pnd));
}

//## @Native String Pasori.readId();
KMETHOD Pasori_readId(CTX ctx, ksfp_t *sfp _RIX)
{
	nfc_device_t *pnd = RawPtr_to(nfc_device_t *, sfp[0]);
	if (pnd == NULL) RETURN_(KNH_TNULL(String));
	const uint8_t uiPollNr = 20;
	const uint8_t uiPeriod = 2;
	const size_t modSize = 1;
	const nfc_modulation_t mod[] = {
		{NMT_FELICA/* nmt */, NBR_212/* nbr */}
	};
	int res;
	nfc_target_t nt;
	nfc_initiator_init(pnd);
	res = nfc_initiator_poll_target(pnd, mod, modSize, uiPollNr, uiPeriod, &nt);
	while (res == 0) {
		{
			KNH_NTRACE2(ctx, "nfc_initiator_poll_target", K_FAILED, KNH_LDATA(LOG_i("res", res)));
		}
		res = nfc_initiator_poll_target(pnd, mod, modSize, uiPollNr, uiPeriod, &nt);
	}
	DBG_ASSERT(nt.nm.nmt == NMT_FELICA);
	nfc_felica_info_t nfc = nt.nti.nfi;
	char idm[32];
	byte_t *d = nfc.abtId;
	snprintf(idm, 32, "%02x%02x%02x%02x%02x%02x%02x%02x", d[0], d[1], d[2], d[3], d[4], d[5], d[6], d[7]);
	RETURN_(new_String(ctx, idm));
}

/* ======================================================================== */
// [DEFAPIS]

DEFAPI(void) defPasori(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->init = Pasori_init;
	cdef->free = Pasori_free;
	cdef->name = "Pasori";
}

#ifdef _SETUP
DEFAPI(const knh_PackageDef_t*) init(CTX ctx, knh_LoaderAPI_t *kapi)
{
	RETURN_PKGINFO("konoha.nfc");
}
#endif /* _SETUP */

#ifdef __cplusplus
}
#endif
