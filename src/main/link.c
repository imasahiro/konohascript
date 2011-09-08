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

///* to:md5 */
//static knh_bool_t TOLINK_hasType(CTX ctx, knh_class_t cid)
//{
//	return IS_CONV(cid);
//}
//static knh_bool_t TOLINK_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
//{
//	const knh_ConverterDPI_t *dspi = knh_NameSpace_getConvTODSPINULL(ctx, ns, knh_bytes_next(path, ':'));
//	return (dspi != NULL);
//}
//static knh_Object_t* TOLINK_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
//{
//	knh_bytes_t path = knh_bytes_next(S_tobytes(s), ':');
//	const knh_ConverterDPI_t *dspi = knh_NameSpace_getConvTODSPINULL(ctx, ns, path);
//	KNH_ASSERT(dspi != NULL); // checked before
//	if(IS_CONV(cid)) {
//		return new_ConverterNULL(ctx, cid, path, dspi);
//	}
//	return NULL;
//}

///* from:toLower */
//static knh_bool_t FROMLINK_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
//{
//	const knh_ConverterDPI_t *dspi = knh_NameSpace_getConvFROMDSPINULL(ctx, ns, knh_bytes_next(path, ':'));
//	return (dspi != NULL);
//}
//
//static knh_Object_t* FROMLINK_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
//{
//	knh_bytes_t path = knh_bytes_next(S_tobytes(s), ':');
//	const knh_ConverterDPI_t *dspi = knh_NameSpace_getConvFROMDSPINULL(ctx, ns, path);
//	KNH_ASSERT(dspi != NULL); // checked before
//	if(IS_CONV(cid)) {
//		return new_ConverterNULL(ctx, cid, path, dspi);
//	}
//	return NULL;
//}
//
//static const knh_LinkDPI_t LINK_TOLINK = {
//	"to", "Converter|StringConverter|StringDecoder|StringEncoder",
//	TOLINK_hasType, TOLINK_exists, TOLINK_newObjectNULL,
//};
//
//static const knh_LinkDPI_t LINK_FROMLINK = {
//	"from", "Converter|StringConverter|StringDecoder|StringEncoder",
//	TOLINK_hasType, FROMLINK_exists, FROMLINK_newObjectNULL,
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
//
//static const knh_LinkDPI_t LINK_PKG = {
//	"pkg", "byte[]|InputStream", PACKAGE_hasType, PACKAGE_exists, PACKAGE_newObjectNULL,
//};
//
//void knh_buff_addScriptPath(CTX ctx, knh_Bytes_t *ba, size_t pos, knh_NameSpace_t *ns, knh_bytes_t path)
//{
//	knh_bytes_t bpath = knh_bytes_next(path, ':');
//	knh_buff_addospath(ctx, ba, pos, 0, S_tobytes(ns->rpath));
//	if(!knh_isdir(ctx, S_totext(ns->rpath))) {
//		knh_buff_trim(ctx, ba, pos, '/');
//	}
//	knh_buff_addospath(ctx, ba, pos, 1, bpath);
//}
//
//static knh_bool_t SCRIPT_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
//{
//	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
//	knh_bytes_t bpath = knh_bytes_next(path, ':');
//	bpath = CWB_ensure(ctx, cwb, bpath, K_PATHMAX);
//	knh_buff_addScriptPath(ctx, cwb->ba, cwb->pos, ns, bpath);
//	knh_bool_t res = knh_exists(ctx, CWB_totext(ctx, cwb));
//	CWB_close(cwb);
//	return res;
//}
//
//static knh_Object_t* SCRIPT_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
//{
//	knh_Object_t *res = NULL;
//	if(cid == CLASS_Bytes) {
//		knh_Bytes_t* ba = new_Bytes(ctx, NULL, 256);
//		knh_buff_addScriptPath(ctx, ba, 0, ns, S_tobytes(s));
//		return UPCAST(ba);
//	}
//	if(cid == CLASS_InputStream || cid == CLASS_OutputStream) {
//		CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
//		knh_bytes_t bpath = knh_bytes_next(S_tobytes(s), ':');
//		knh_buff_addScriptPath(ctx, cwb->ba, cwb->pos, ns, bpath);
//		if(cid == CLASS_InputStream) {
//			res = (knh_Object_t*)knh_Bytes_openInputStream(ctx, cwb->ba, cwb->pos, s);
//		}
//		else {
//			res = (knh_Object_t*)knh_Bytes_openOutputStream(ctx, cwb->ba, cwb->pos, s);
//		}
//		CWB_close(cwb);
//	}
//	return res;
//}
//



/* ------------------------------------------------------------------------ */
/* K_DSPI_QUERY */

static void NOP_qfree(knh_qcur_t *qcur)
{
}
static knh_qconn_t *NOP_qopen(CTX ctx, knh_bytes_t url)
{
	return NULL;
}
static knh_qcur_t *NOP_query(CTX ctx, knh_qconn_t *hdr, knh_bytes_t sql, knh_ResultSet_t *rs)
{
	return NULL;
}
static void NOP_qclose(CTX ctx, knh_qconn_t *hdr)
{
}
static int NOP_qnext(CTX ctx, knh_qcur_t *qcur, struct knh_ResultSet_t *rs)
{
	return 0;  /* NOMORE */
}

static const knh_QueryDPI_t QUERY_NOP = {
	K_DSPI_QUERY, "NOP",
	NOP_qopen, NOP_query, NOP_qclose, NOP_qnext, NOP_qfree
};

const knh_QueryDPI_t *knh_getDefaultQueryDPI(void)
{
	return &QUERY_NOP;
}

#ifdef K_USING_SQLITE3

#include<sqlite3.h>

static void knh_sqlite3_perror(CTX ctx, sqlite3 *db, int r)
{
	const char *msg = "sqlite3";
	if(r == SQLITE_PERM || r == SQLITE_AUTH) {
		msg = "Security";
	}
	KNH_LOG("sqlite3_error='%s', '%s'", msg, sqlite3_errmsg(db));
}

static knh_qconn_t *SQLITE3_qopen(CTX ctx, knh_bytes_t url)
{
	sqlite3 *db = NULL;
	url = knh_bytes_next(url, ':');
	int r = sqlite3_open(url.text, &db);
	if (r != SQLITE_OK) {
		return NULL;
	}
	return (knh_qconn_t*)db;
}

static int SQLITE3_qnext(CTX ctx, knh_qcur_t *qcur, struct knh_ResultSet_t *rs)
{
	sqlite3_stmt *stmt = (sqlite3_stmt*)qcur;
	int r = sqlite3_step(stmt);
	if(SQLITE_ROW == r) {
		size_t i;
		knh_ResultSet_initData(ctx, rs);
		for(i = 0; i < DP(rs)->column_size; i++) {
			int type = sqlite3_column_type(stmt, i);
			switch(type) {
				case SQLITE_INTEGER: {
					ResultSet_setInt(ctx, rs, i, (knh_int_t)sqlite3_column_int64(stmt, i));
					break;
				}
				case SQLITE_FLOAT: {
					ResultSet_setFloat(ctx, rs, i, (knh_float_t)sqlite3_column_double(stmt, i));
					break;
				}
				case SQLITE_TEXT: {
					knh_bytes_t t = {{(const char*)sqlite3_column_text(stmt,i)}, sqlite3_column_bytes(stmt, i)};
					ResultSet_setText(ctx, rs, i, t);
					break;
				}
				case SQLITE_BLOB: {
					knh_bytes_t t = {{(const char*)sqlite3_column_blob(stmt,i)}, sqlite3_column_bytes(stmt, i)};
					ResultSet_setBlob(ctx, rs, i, t);
					break;
				}
				case SQLITE_NULL:
				default: {
					ResultSet_setNULL(ctx, rs, i);
				}
			}
		}
		return 1;
	}
	else if (r != SQLITE_DONE) {
	   //
	}
	return 0;  /* NOMORE */
}

static knh_qcur_t *SQLITE3_query(CTX ctx, knh_qconn_t *hdr, knh_bytes_t sql, knh_ResultSet_t *rs)
{
	if(rs == NULL) {
		int r = sqlite3_exec((sqlite3*)hdr, sql.text, NULL, NULL, NULL);
		if(r != SQLITE_OK) {
			knh_sqlite3_perror(ctx, (sqlite3*)hdr, r);
		}
		return NULL;
	}
	else {
		sqlite3_stmt *stmt = NULL;
		sqlite3_prepare((sqlite3*)hdr, sql.text, sql.len, &stmt, NULL);
		size_t column_size = (size_t)sqlite3_column_count(stmt);
		knh_ResultSet_initColumn(ctx, rs, column_size);
		if(column_size > 0) {
			size_t i;
			for(i = 0; i < DP(rs)->column_size; i++) {
				const char *n = (const char*)sqlite3_column_name(stmt, i);
				if(n != NULL) {
					ResultSet_setName(ctx, rs, i, new_S(n, knh_strlen(n)));
				}
			}
		}
		return (knh_qcur_t*)stmt;
	}
}

static void SQLITE3_qclose(CTX ctx, knh_qconn_t *hdr)
{
	sqlite3_close((sqlite3*)hdr);
}

static void SQLITE3_qfree(knh_qcur_t *qcur)
{
	sqlite3_stmt *stmt = (sqlite3_stmt*)qcur;
	sqlite3_finalize(stmt);
}

static const knh_QueryDPI_t QUERY_SQLITE3 = {
	K_DSPI_QUERY, "sqlite3",
	SQLITE3_qopen, SQLITE3_query, SQLITE3_qclose, SQLITE3_qnext, SQLITE3_qfree
};

#endif/*K_USING_SQLITE3*/

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
	api->addQueryDPI(ctx, "nop", &QUERY_NOP);
#ifdef K_USING_SQLITE3
	api->addQueryDPI(ctx, "konoha.sqlite3", &QUERY_SQLITE3);
#endif
	knh_loadFFIDriver(ctx, ns);
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
