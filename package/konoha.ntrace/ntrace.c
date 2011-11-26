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
//  shinpei_NKT - Shinpei Nakata, Yokohama National University, Japan
// **************************************************************************

#define K_INTERNAL 1
#include <konoha1.h>

#ifdef __cplusplus
extern "C" {
#endif

//@Native @Public System.ntrace_notice(String title, Map ldata);
KMETHOD System_ntraceNotice (CTX ctx, ksfp_t *sfp _RIX)
{
	char *title = String_to(char *, sfp[1]);
	kMap *mdata = sfp[2].m;
	kmapptr_t *mapptr = mdata->mapptr;
	knh_ldata_t log_buffer[64] = {0};
	int logidx = 0;
	// suppose p1 is "String"
	ksfp_t *lsfp = ctx->esp;
	knitr_t mitrbuf = K_NITR_INIT, *mitr = &mitrbuf;
	klr_setesp(ctx, lsfp+1);
	while(mdata->spi->next(ctx, mapptr, mitr, lsfp)) {
		kString *key = lsfp[0].s;
		kObject *value = knh_DictMap_getNULL(ctx, (kDictMap*)mdata, S_tobytes(key));
		kclass_t cid = O_cid(value);
		if (cid == CLASS_Int) {
			knh_ldata_t item[] = {LOG_i(S_totext(key), N_toint(value))};
			log_buffer[logidx++] = item[0];
			log_buffer[logidx++] = item[1];
			log_buffer[logidx++] = item[2];
		} else if (cid == CLASS_Float) {
			knh_ldata_t item[] = {LOG_f(S_totext(key), N_tofloat(value))};
			log_buffer[logidx++] = item[0];
			log_buffer[logidx++] = item[1];
			log_buffer[logidx++] = item[2];
		} else if (cid == CLASS_String) {
			knh_ldata_t item[] = {LOG_s(S_totext(key), S_totext((kString*)value))};
			log_buffer[logidx++] = item[0];
			log_buffer[logidx++] = item[1];
			log_buffer[logidx++] = item[2];
		} else {
			// cannot map...
		}
		klr_setesp(ctx, lsfp+1);
	}
	log_buffer[logidx++] = (char*)LOG_END;
	KNH_NTRACE(ctx, title, K_NOTICE, log_buffer);
	RETURNvoid_();
}

//@Native @Public System.ntrace_ok(String title, Map ldata);
KMETHOD System_ntraceOk (CTX ctx, ksfp_t *sfp _RIX)
{
	char *title = String_to(char *, sfp[1]);
	kMap *mdata = sfp[2].m;
	kmapptr_t *mapptr = mdata->mapptr;
	knh_ldata_t log_buffer[64] = {0};
	int logidx = 0;
	// suppose p1 is "String"
	ksfp_t *lsfp = ctx->esp;
	knitr_t mitrbuf = K_NITR_INIT, *mitr = &mitrbuf;
	klr_setesp(ctx, lsfp+1);
	while(mdata->spi->next(ctx, mapptr, mitr, lsfp)) {
		kString *key = lsfp[0].s;
		kObject *value = knh_DictMap_getNULL(ctx, (kDictMap*)mdata, S_tobytes(key));
		kclass_t cid = O_cid(value);
		if (cid == CLASS_Int) {
			knh_ldata_t item[] = {LOG_i(S_totext(key), N_toint(value))};
			log_buffer[logidx++] = item[0];
			log_buffer[logidx++] = item[1];
			log_buffer[logidx++] = item[2];
		} else if (cid == CLASS_Float) {
			knh_ldata_t item[] = {LOG_f(S_totext(key), N_tofloat(value))};
			log_buffer[logidx++] = item[0];
			log_buffer[logidx++] = item[1];
			log_buffer[logidx++] = item[2];
		} else if (cid == CLASS_String) {
			knh_ldata_t item[] = {LOG_s(S_totext(key), S_totext((kString*)value))};
			log_buffer[logidx++] = item[0];
			log_buffer[logidx++] = item[1];
			log_buffer[logidx++] = item[2];
		} else {
			// cannot map...
		}
		klr_setesp(ctx, lsfp+1);
	}
	log_buffer[logidx++] = (char*)LOG_END;
	KNH_NTRACE(ctx, title, K_OK, log_buffer);
	RETURNvoid_();
}

//@Native @Public System.ntrace_failed(String title, Map ldata);
KMETHOD System_ntraceFailed (CTX ctx, ksfp_t *sfp _RIX)
{
	char *title = String_to(char *, sfp[1]);
	kMap *mdata = sfp[2].m;
	kmapptr_t *mapptr = mdata->mapptr;
	knh_ldata_t log_buffer[64] = {0};
	int logidx = 0;
	// suppose p1 is "String"
	ksfp_t *lsfp = ctx->esp;
	knitr_t mitrbuf = K_NITR_INIT, *mitr = &mitrbuf;
	klr_setesp(ctx, lsfp+1);
	while(mdata->spi->next(ctx, mapptr, mitr, lsfp)) {
		kString *key = lsfp[0].s;
		kObject *value = knh_DictMap_getNULL(ctx, (kDictMap*)mdata, S_tobytes(key));
		kclass_t cid = O_cid(value);
		if (cid == CLASS_Int) {
			knh_ldata_t item[] = {LOG_i(S_totext(key), N_toint(value))};
			log_buffer[logidx++] = item[0];
			log_buffer[logidx++] = item[1];
			log_buffer[logidx++] = item[2];
		} else if (cid == CLASS_Float) {
			knh_ldata_t item[] = {LOG_f(S_totext(key), N_tofloat(value))};
			log_buffer[logidx++] = item[0];
			log_buffer[logidx++] = item[1];
			log_buffer[logidx++] = item[2];
		} else if (cid == CLASS_String) {
			knh_ldata_t item[] = {LOG_s(S_totext(key), S_totext((kString*)value))};
			log_buffer[logidx++] = item[0];
			log_buffer[logidx++] = item[1];
			log_buffer[logidx++] = item[2];
		} else {
			// cannot map...
		}
		klr_setesp(ctx, lsfp+1);
	}
	log_buffer[logidx++] = (char*)LOG_END;
	KNH_NTRACE(ctx, title, K_FAILED, log_buffer);
	RETURNvoid_();
}

/* ======================================================================== */
// [DEFAPI]

#ifdef _SETUP
DEFAPI(const knh_PackageDef_t*) init(CTX ctx, knh_LoaderAPI_t *kapi)
{
	//knh_NameSpace_setLinkClass(ctx, ctx->share->rootns, STEXT("memcached"), ClassTBL(CLASS_Tvoid));
	RETURN_PKGINFO("konoha.ntrace");
}
#endif /* _SETUP */

#ifdef __cplusplus
}
#endif
