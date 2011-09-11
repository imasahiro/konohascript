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
 * (1) GNU General Public License 3.0 (with K_UNDER_GPL)
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

/* ************************************************************************ */

#include"commons.h"

/* ************************************************************************ */

#ifdef K_USING_CURL
#include<curl/curl.h>
#endif/*K_USING_CURL*/

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* [LINK] */

///* charset:UTF-8 */
//static knh_bool_t CHARSET_hasType(CTX ctx, knh_class_t cid)
//{
//	return (cid == CLASS_StringEncoder || cid == CLASS_StringDecoder);
//}
//
//static knh_bool_t CHARSET_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
//{
//	knh_bytes_t t = knh_bytes_next(path, ':');
//	knh_iconv_t ic = ctx->spi->iconv_openSPI(t.text, K_ENCODING);
//	if(ic != (knh_iconv_t)(-1)) {
//		ctx->spi->iconv_closeSPI(ic);
//		return 1;
//	}
//	else if(knh_bytes_strcasecmp(t, STEXT(K_ENCODING)) == 0) {
//		return 1;
//	}
//	return 0;
//}
//
//static knh_Object_t* CHARSET_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
//{
//	knh_bytes_t t = knh_bytes_next(S_tobytes(s), ':');
//	if(cid == CLASS_StringEncoder) {
//		return (knh_Object_t*)new_StringEncoderNULL(ctx, t);
//	}
//	if(cid == CLASS_StringDecoder) {
//		return (knh_Object_t*)new_StringDecoderNULL(ctx, t);
//	}
//	return NULL;
//}

//static const knh_LinkDPI_t LINK_CHARSET = {
//	"charset", "StringConverter|StringDecoder", CHARSET_hasType, CHARSET_exists, CHARSET_newObjectNULL,
//};

//static knh_bool_t PACKAGE_hasType(CTX ctx, knh_class_t cid)
//{
//	return (cid == CLASS_Bytes || cid == CLASS_InputStream);
//}
//
//static knh_bool_t PACKAGE_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
//{
//	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
//	knh_bytes_t bpath = knh_bytes_next(path, ':');
//	bpath = CWB_ensure(ctx, cwb, bpath, K_PATHMAX);
//	knh_bool_t res = knh_buff_addPackagePath(ctx, cwb->ba, cwb->pos, bpath);
//	CWB_close(cwb);
//	return res;
//}
//
//static knh_Object_t* PACKAGE_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
//{
//	knh_Object_t *res = NULL;
//	if(cid == CLASS_Bytes) {
//		knh_Bytes_t* ba = new_Bytes(ctx, NULL, 256);
//		if(!knh_buff_addPackagePath(ctx, ba, 0, S_tobytes(s))) {
//			knh_Object_toNULL(ctx, ba);
//		}
//		return UPCAST(ba);
//	}
//	if(cid == CLASS_InputStream) {
//		CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
//		knh_bytes_t bpath = knh_bytes_next(S_tobytes(s), ':');
//		knh_buff_addPackagePath(ctx, cwb->ba, cwb->pos, bpath);
//		res = (knh_Object_t*)knh_Bytes_openInputStream(ctx, cwb->ba, cwb->pos, s);
//		CWB_close(cwb);
//	}
//	return res;
//}

/* ------------------------------------------------------------------------ */
/* K_DSPI_QUERY */


/* ------------------------------------------------------------------------ */

static knh_bool_t tolowercase(CTX ctx, knh_conv_t *cv, const char *text, size_t len, knh_Bytes_t *tobuf)
{
	size_t i, s = BA_size(tobuf);
	knh_Bytes_write2(ctx, tobuf, text, len);
	knh_bytes_t tt = {{tobuf->bu.text + s}, BA_size(tobuf) - s};
	for(i = 0; i < tt.len; i++) {
		int ch = tt.utext[i];
		if('A' <= ch && ch <= 'Z') {
			tt.ubuf[i] = ch - 'A' + 'a';
		}
	}
	return 1;
}

static knh_bool_t touppercase(CTX ctx, knh_conv_t *cv, const char *text, size_t len, knh_Bytes_t *tobuf)
{
	size_t i, s = BA_size(tobuf);
	knh_Bytes_write2(ctx, tobuf, text, len);
	knh_bytes_t tt = {{tobuf->bu.text + s}, BA_size(tobuf) - s};
	for(i = 0; i < tt.len; i++) {
		int ch = tt.utext[i];
		if('a' <= ch && ch <= 'z') {
			tt.ubuf[i] = ch - 'a' + 'A';
		}
	}
	return 1;
}

static const knh_ConverterDPI_t TO_lower = {
	K_DSPI_CONVTO, "lower",
	NULL, tolowercase, tolowercase, tolowercase, tolowercase, NULL, NULL,
};

static const knh_ConverterDPI_t TO_upper = {
	K_DSPI_CONVTO, "upper",
	NULL, touppercase, touppercase, touppercase, touppercase, NULL, NULL,
};

void knh_loadSystemDriver(CTX ctx, knh_NameSpace_t *ns)
{
	const knh_LoaderAPI_t *api = knh_getLoaderAPI();
	knh_NameSpace_setLinkClass(ctx, ns, STEXT("link"), ClassTBL(CLASS_Tdynamic));
	api->addConverterDPI(ctx, "lower", &TO_lower, NULL);
	api->addConverterDPI(ctx, "upper", &TO_upper, NULL);
//	api->addQueryDPI(ctx, "nop", &QUERY_NOP);
//#ifdef K_USING_SQLITE3
//	api->addQueryDPI(ctx, "konoha.sqlite3", &QUERY_SQLITE3);
//#endif
	knh_loadFFIDriver(ctx, ns);
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
