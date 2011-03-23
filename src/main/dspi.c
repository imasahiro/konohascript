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

#ifdef __cplusplus
extern "C" {
#endif

#ifdef K_INCLUDE_BUILTINAPI

#if defined(K_USING_POSIX_)
#include <dirent.h>
#endif

/* ------------------------------------------------------------------------ */
/* K_DSPI_PATH */

knh_bytes_t knh_bytes_skipPATHHEAD(knh_bytes_t path)
{
	size_t i;
	size_t len = (K_PATHHEAD_MAXSIZ < path.len) ? K_PATHHEAD_MAXSIZ : path.len;
	for(i = 1; i < len; i++) {
		if(path.ustr[i] == ':') {
			path.ustr = path.ustr + (i + 1);
			path.len = path.len - (i + 1);
			return path;
		}
	}
	return path;
}

/* ------------------------------------------------------------------------ */
/* [PATH] */

static knh_uintptr_t NOPATH_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	return PATH_unknown;
}

static knh_bool_t NOPATH_hasType(CTX ctx, knh_class_t cid)
{
	return 0;
}

static knh_Object_t* NOPATH_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
{
	return NULL/*(knh_Object_t*)s*/;
}

static const knh_PathDSPI_t PATH_NOPATH = {
	K_DSPI_PATH, "NOPATH",
	CLASS_Tvoid, CLASS_Tvoid,
	NOPATH_hasType, NOPATH_exists, NOPATH_newObjectNULL,
};

/* charset:UTF-8 */

static knh_bool_t CHARSET_hasType(CTX ctx, knh_class_t cid)
{
	return (cid == CLASS_StringEncoder || cid == CLASS_StringDecoder || PATH_hasType(cid));
}

static knh_uintptr_t CHARSET_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	knh_bytes_t t = knh_bytes_skipPATHHEAD(path);
	knh_uintptr_t res = PATH_unknown;
	iconv_t ic = ctx->spi->iconv_open(t.text, K_ENCODING);
	if(ic != (iconv_t)(-1)) {
		res = PATH_found;
		ctx->spi->iconv_close(ic);
	}
	else if(knh_bytes_strcasecmp(t, STEXT(K_ENCODING)) == 0) {
		res = PATH_found;
	}
	return res;
}

static knh_Object_t* CHARSET_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
{
	knh_bytes_t t = knh_bytes_skipPATHHEAD(S_tobytes(s));
	if(cid == CLASS_StringEncoder) {
		return (knh_Object_t*)new_StringEncoderNULL(ctx, t);
	}
	if(cid == CLASS_StringDecoder) {
		return (knh_Object_t*)new_StringDecoderNULL(ctx, t);
	}
	return NULL;
}

static const knh_PathDSPI_t PATH_CHARSET = {
	K_DSPI_PATH, "charset",
	CLASS_Boolean, CLASS_Tvoid,
	CHARSET_hasType, CHARSET_exists, CHARSET_newObjectNULL,
};

/* ------------------------------------------------------------------------ */
/* Path to:md5 */
/* Path from:toLower */

#define IS_CONV(cid) (CLASS_Converter <= cid && cid <= CLASS_StringConverter)

static Object* new_ConverterNULL(CTX ctx, knh_class_t cid, knh_bytes_t path, const knh_ConvDSPI_t *dspi)
{
	knh_conv_t *conv = NULL;
	DBG_ASSERT(IS_CONV(cid));
	if((cid == CLASS_StringConverter && dspi->sconv == NULL) ||
		(cid == CLASS_StringEncoder && dspi->enc == NULL) ||
		(cid == CLASS_StringDecoder && dspi->dec == NULL) ||
		(cid == CLASS_Converter && dspi->conv == NULL)) {
		return NULL;
	}
	if(dspi->open != NULL) {
		conv = dspi->open(ctx, path.text, NULL);
		if(conv == NULL) {
			KNH_WARN(ctx, "unknown path='%s'", path.text);
			return NULL;
		}
	}
	{
		knh_Converter_t *c = new_O(Converter, cid);
		c->dspi = dspi;
		c->conv = conv;
		return (knh_Object_t*)c;
	}
}

static knh_bool_t TOPATH_hasType(CTX ctx, knh_class_t cid)
{
	if(IS_CONV(cid)) return 1;
	return PATH_hasType(cid);
}

static knh_uintptr_t TOPATH_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	const knh_ConvDSPI_t *dspi = knh_NameSpace_getConvTODSPINULL(ctx, ns, knh_bytes_skipPATHHEAD(path));
	return (dspi != NULL) ? PATH_found : PATH_unknown;
}

static knh_Object_t* TOPATH_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
{
	knh_bytes_t path = knh_bytes_skipPATHHEAD(S_tobytes(s));
	const knh_ConvDSPI_t *dspi = knh_NameSpace_getConvTODSPINULL(ctx, ns, path);
	KNH_ASSERT(dspi != NULL);
	if(IS_CONV(cid)) {
		return new_ConverterNULL(ctx, cid, path, dspi);
	}
	return NULL;
}

static knh_uintptr_t FROMPATH_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	const knh_ConvDSPI_t *dspi = knh_NameSpace_getConvFROMDSPINULL(ctx, ns, knh_bytes_skipPATHHEAD(path));
	return (dspi != NULL) ? PATH_found : PATH_unknown;
}

static knh_Object_t* FROMPATH_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
{
	knh_bytes_t path = knh_bytes_skipPATHHEAD(S_tobytes(s));
	const knh_ConvDSPI_t *dspi = knh_NameSpace_getConvFROMDSPINULL(ctx, ns, path);
	KNH_ASSERT(dspi != NULL);
	if(IS_CONV(cid)) {
		return new_ConverterNULL(ctx, cid, path, dspi);
	}
	return NULL;
}

static const knh_PathDSPI_t PATH_TOPATH = {
	K_DSPI_PATH, "to",
	CLASS_Converter, CLASS_Tvoid,
	TOPATH_hasType, TOPATH_exists, TOPATH_newObjectNULL,
};

static const knh_PathDSPI_t PATH_FROMPATH = {
	K_DSPI_PATH, "from",
	CLASS_Converter, CLASS_Tvoid,
	TOPATH_hasType, FROMPATH_exists, FROMPATH_newObjectNULL,
};

/* ------------------------------------------------------------------------ */
/* file:/usr/local */

static knh_bool_t FILE_hasType(CTX ctx, knh_class_t cid)
{
	return (cid == CLASS_InputStream || cid == CLASS_OutputStream || PATH_hasType(cid));
}

static knh_uintptr_t FILE_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	knh_bytes_t n = knh_bytes_skipPATHHEAD(path);
	knh_cwb_t cwbbuf, *cwb = knh_cwb_openinit(ctx, &cwbbuf, n);
	knh_cwb_ospath(ctx, cwb);
	knh_uintptr_t res = cwb_isfile(ctx, cwb) ? 1: PATH_unknown;
	if(res != PATH_unknown) {
		res = knh_getURI(ctx, knh_cwb_tobytes(cwb));
	}
	knh_cwb_close(cwb);
	return res;
}

static knh_Object_t* FILE_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
{
	if(cid == CLASS_InputStream) {
		knh_InputStream_t *in = new_InputStreamNULL(ctx, ns, s, "r");
		return (knh_Object_t*)in;
	}
	if(cid == CLASS_OutputStream) {
		knh_OutputStream_t *out = new_OutputStreamNULL(ctx, ns, s, "a");
		return (knh_Object_t*)out;
	}
	return NULL;
}

static const knh_PathDSPI_t PATH_FILE = {
	K_DSPI_PATH, "file",
	CLASS_Boolean, CLASS_InputStream,
	FILE_hasType, FILE_exists, FILE_newObjectNULL,
};

static knh_uintptr_t LIB_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_bytes_t libname = knh_bytes_skipPATHHEAD(path), funcname = STEXT(""); /* lib:m.sin */
	knh_index_t loc = knh_bytes_index(libname, '.');
	if(loc != -1) {
		libname = knh_bytes_first(libname, loc);
		funcname = knh_bytes_last(libname, loc+1);
	}
	knh_cwb_write(ctx, cwb, libname);
	knh_cwb_ospath(ctx, cwb);
	void *p = knh_cwb_dlopen(ctx, LOG_DEBUG, cwb);
	knh_uintptr_t res = PATH_unknown;
	if(p == NULL && !knh_bytes_startsWith(libname, STEXT("lib"))) {
		knh_cwb_clear(cwb, 0);
		knh_cwb_write(ctx, cwb, STEXT("lib"));
		knh_cwb_write(ctx, cwb, libname);
		knh_cwb_ospath(ctx, cwb);
		p = knh_cwb_dlopen(ctx, LOG_DEBUG, cwb);
	}
	if(p != NULL) {
		res = PATH_found;
		if(funcname.len != 0) {
			void *f = knh_dlsym(ctx, LOG_DEBUG, p, funcname.text);
			res = (f != NULL) ? PATH_found : PATH_unknown;
		}
		knh_dlclose(ctx, p);
	}
	knh_cwb_close(cwb);
	return res;
}

static const knh_PathDSPI_t PATH_LIB = {
	K_DSPI_PATH, "lib",
	CLASS_Boolean, CLASS_Tvoid,
	NOPATH_hasType, LIB_exists, NOPATH_newObjectNULL,
};

/* ------------------------------------------------------------------------ */
/* K_DSPI_STREAM */

static knh_io_t NOFILE_open(CTX ctx, knh_bytes_t n, const char *mode)
{
	return IO_NULL;
}
static knh_intptr_t NOFILE_read(CTX ctx, knh_io_t fd, char *buf, size_t bufsiz)
{
	return 0;
}
static knh_intptr_t NOFILE_write(CTX ctx, knh_io_t fd, const char *buf, size_t bufsiz)
{
	return bufsiz;
}
static void NOFILE_close(CTX ctx, knh_io_t fd)
{
}
static int NOFILE_feof(CTX ctx, knh_io_t fd)
{
	return 1;
}
static int NOFILE_getc(CTX ctx, knh_io_t fd)
{
	return -1;
}

static const knh_StreamDSPI_t STREAM_NOFILE = {
	K_DSPI_STREAM, "NOFILE", 0,
	NOFILE_open, NOFILE_open, NOFILE_read, NOFILE_write, NOFILE_close,
	NOFILE_feof, NOFILE_getc
};

/* ------------------------------------------------------------------------ */

static knh_io_t FILE_open(CTX ctx, knh_bytes_t path, const char *mode)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_openinit(ctx, &cwbbuf, knh_bytes_skipPATHHEAD(path));
	knh_cwb_ospath(ctx, cwb);
	FILE *fp = knh_fopen(ctx, LOG_ERR, knh_cwb_tochar(ctx, cwb), mode);
	knh_cwb_close(cwb);
	return (knh_io_t)fp;
}
static knh_io_t NOFILE_wopen(CTX ctx, knh_bytes_t n, const char *mode)
{
	KNH_WARN(ctx, "nofile path='%s', mode='%s'", n.text, mode);
	return IO_NULL;
}
static knh_intptr_t FILE_read(CTX ctx, knh_io_t fd, char *buf, size_t bufsiz)
{
	return knh_fread(ctx, buf, bufsiz, (FILE*)fd);
}

static knh_intptr_t FILE_write(CTX ctx, knh_io_t fd, const char *buf, size_t bufsiz)
{
	size_t ssize = knh_fwrite(ctx, buf, bufsiz, (FILE*)fd);
	knh_fflush(ctx, (FILE*)fd);
	return ssize;
}

static void FILE_close(CTX ctx, knh_io_t fd)
{
	knh_fclose(ctx, (FILE*)fd);
}
static int FILE_feof(CTX ctx, knh_io_t fd)
{
	return feof((FILE*)fd);
}
static int FILE_getc(CTX ctx, knh_io_t fd)
{
	return fgetc((FILE*)fd);
}

static const knh_StreamDSPI_t STREAM_FILE = {
	K_DSPI_STREAM, "file", 0,
	FILE_open, FILE_open, FILE_read, FILE_write, FILE_close,
	FILE_feof, FILE_getc,
};

static const knh_StreamDSPI_t STREAM_STDIO = {
	K_DSPI_STREAM, "stdio", 0,
	NOFILE_open, NOFILE_open, FILE_read, FILE_write, NOFILE_close,
	FILE_feof, FILE_getc,
};

static knh_InputStream_t *new_InputStreamSTDIO(CTX ctx, FILE *fp, knh_String_t *enc)
{
	knh_InputStream_t* in = new_InputStreamDSPI(ctx, (knh_io_t)stdin, &STREAM_STDIO);
	KNH_SETv(ctx, DP(in)->urn, TS_DEVSTDIN);
	return in;
}

static knh_OutputStream_t *new_OutputStreamSTDIO(CTX ctx, FILE *fp, knh_String_t *enc)
{
#ifdef K_USING_NOFILE
	knh_OutputStream_t* o = new_OutputStream__FILE(ctx, TS_DEVSTDOUT, NULL, &STREAM_STDIO);
#else
	KNH_ASSERT(fp == stdout || fp == stderr);
	knh_OutputStream_t* o = new_OutputStreamDSPI(ctx, (knh_io_t)fp, &STREAM_STDIO);
	knh_String_t *urn = (fp == stdout) ? TS_DEVSTDOUT : TS_DEVSTDERR;
	KNH_SETv(ctx, DP(o)->urn, urn);
#endif
	OutputStream_setAutoFlush(o, 1);
	return o;
}

//#ifdef K_USING_POSIX_
//static void PIPE_close(CTX ctx, knh_io_t fd)
//{
//	pclose((FILE*)fd);
//}
//
//static const knh_StreamDSPI_t PIPE_DSPI = {
//	K_DSPI_STREAM, "pipe", 0,
//	NOFILE_open, NOFILE_open, FILE_read, FILE_write, PIPE_close,
//	FILE_feof, FILE_getc,
//};
//
//const knh_StreamDSPI_t* knh_getPIPEStreamDSPI(void)
//{
//	return &PIPE_DSPI;
//}
//#endif


static knh_bytes_t knh_bytes_lastname(knh_bytes_t t)
{
	knh_index_t loc = knh_bytes_rindex(t, '.');
	if(loc != -1) {
		return knh_bytes_last(t, loc+1);
	}
	return t;
}

static void knh_cwb_writePKG(CTX ctx, knh_cwb_t *cwb, knh_bytes_t tpath, knh_bytes_t path)
{
	knh_cwb_clear(cwb, 0);
	knh_cwb_write(ctx, cwb, tpath);
	knh_cwb_putc(ctx, cwb, '/');
	knh_cwb_write(ctx, cwb, path); // konoha.math
	knh_cwb_putc(ctx, cwb, '/');
	knh_cwb_write(ctx, cwb, knh_bytes_lastname(path));
	knh_cwb_write(ctx, cwb, STEXT(".k"));
	knh_cwb_ospath(ctx, cwb);
}

static knh_bool_t knh_cwb_existsPKG(CTX ctx, knh_cwb_t *cwb, knh_bytes_t path)
{
	char *epath = knh_getenv("KONOHA_PACKAGE");
	knh_String_t *tpath = knh_getPropertyNULL(ctx, STEXT("konoha.package.path"));
	if(epath != NULL) {
		knh_cwb_writePKG(ctx, cwb, B(epath), path);
		if(cwb_isfile(ctx, cwb)) return 1;
	}
	if(tpath != NULL) {
		knh_cwb_writePKG(ctx, cwb, S_tobytes(tpath), path);
		if(cwb_isfile(ctx, cwb)) return 1;
	}
	tpath = knh_getPropertyNULL(ctx, STEXT("user.package.path"));
	if(tpath != NULL) {
		knh_cwb_writePKG(ctx, cwb, S_tobytes(tpath), path);
		if(cwb_isfile(ctx, cwb)) return 1;
	}
	return 0;
}

static knh_uintptr_t PKG_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_uintptr_t res =
		knh_cwb_existsPKG(ctx, cwb, knh_bytes_skipPATHHEAD(path)) ? knh_getURI(ctx, knh_cwb_tobytes(cwb)) : PATH_unknown;
	knh_cwb_close(cwb);
	return res;
}

static const knh_PathDSPI_t PATH_PKG = {
	K_DSPI_PATH, "pkg",
	CLASS_Boolean, CLASS_InputStream,
	NOPATH_hasType, PKG_exists, NOPATH_newObjectNULL,
};

static knh_io_t PKG_open(CTX ctx, knh_bytes_t path, const char *mode)
{
	FILE *fp = NULL;
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_bool_t res = knh_cwb_existsPKG(ctx, cwb, knh_bytes_skipPATHHEAD(path));
	if(res == 1) {
		fp = knh_fopen(ctx, LOG_ERR, knh_cwb_tochar(ctx, cwb), mode);
	}
	knh_cwb_close(cwb);
	return (knh_io_t)fp;
}

static const knh_StreamDSPI_t STREAM_PKG = {
	K_DSPI_STREAM, "pkg", 0,
	PKG_open, NOFILE_wopen, FILE_read, NOFILE_write, FILE_close,
	FILE_feof, FILE_getc,
};

static void knh_cwb_writeSCRIPT(CTX ctx, knh_cwb_t *cwb, knh_bytes_t path)
{
	knh_uri_t uri = ULINE_uri(ctx->gma->uline);
	knh_bytes_t t = S_tobytes(knh_getURN(ctx, uri));
	if(t.ustr[0] != '(') {  /* NOT (eval) */
		knh_cwb_write(ctx, cwb, t);
		knh_bool_t ret = knh_cwb_parentpath(ctx, cwb, NULL);
		if (ret) {
			knh_cwb_putc(ctx, cwb, '/');
		}
	}
	{
		size_t i;
		for(i = 0; i < path.len; i++) {
			if(path.ustr[i] == '.' && path.ustr[i+1] == '.'
				&& (path.ustr[i+2] == '/' || path.ustr[i+2] == '\\')) {
				i += 2; continue;
			}
			knh_Bytes_putc(ctx, cwb->ba, path.ustr[i]);
		}
	}
	knh_cwb_ospath(ctx, cwb);
}

static knh_uintptr_t SCRIPT_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_cwb_writeSCRIPT(ctx, cwb, knh_bytes_skipPATHHEAD(path));
	knh_uintptr_t res = cwb_isfile(ctx, cwb) ? knh_getURI(ctx, knh_cwb_tobytes(cwb)) : PATH_unknown;
	knh_cwb_close(cwb);
	return res;
}

static knh_io_t SCRIPT_open(CTX ctx, knh_bytes_t path, const char *mode)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_cwb_writeSCRIPT(ctx, cwb, knh_bytes_skipPATHHEAD(path));
	FILE *fp = knh_fopen(ctx, LOG_ERR, knh_cwb_tochar(ctx, cwb), mode);
	knh_cwb_close(cwb);
	return (knh_io_t)fp;
}

static const knh_PathDSPI_t PATH_SCRIPT = {
	K_DSPI_PATH, "script",
	CLASS_Script, CLASS_InputStream,
	FILE_hasType, SCRIPT_exists, FILE_newObjectNULL,
};

static const knh_StreamDSPI_t STREAM_SCRIPT = {
	K_DSPI_STREAM, "script", 0,
	SCRIPT_open, NOFILE_wopen, FILE_read, FILE_write, FILE_close,
	FILE_feof, FILE_getc,
};

/* ------------------------------------------------------------------------ */

static void SYSLOG_UnknownPathType(CTX ctx, knh_bytes_t path)
{
	KNH_WARN(ctx, "undefined path='%s'", path.text);
}

const knh_StreamDSPI_t *knh_getStreamDSPI(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	if(path.len == 0) {
		return &STREAM_NOFILE;
	}
	else {
		const knh_StreamDSPI_t *p = (const knh_StreamDSPI_t*)knh_NameSpace_getDSPINULL(ctx, ns, K_DSPI_STREAM, path);
		if(p == NULL) {
			SYSLOG_UnknownPathType(ctx, path);
			p = &STREAM_NOFILE;
		}
		return p;
	}
}

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

static const knh_QueryDSPI_t QUERY_NOP = {
	K_DSPI_QUERY, "NOP",
	NOP_qopen, NOP_query, NOP_qclose, NOP_qnext, NOP_qfree
};

#ifdef K_USING_SQLITE3

#include<sqlite3.h>

static void knh_sqlite3_perror(CTX ctx, sqlite3 *db, int r)
{
	const char *msg = "sqlite3";
	if(r == SQLITE_PERM || r == SQLITE_AUTH) {
		msg = "Security";
	}
	KNH_WARN(ctx, "sqlite3_error='%s'", sqlite3_errmsg(db));
}

static knh_qconn_t *SQLITE3_qopen(CTX ctx, knh_bytes_t url)
{
	sqlite3 *db = NULL;
	url = knh_bytes_skipPATHHEAD(url);
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
//	if (r != SQLITE_OK) {
//		sqlite3_finalize(stmt);
//		DBG_P("msg='%s', sqlite3_errmsg((sqlite3)hdr));
//		return NULL;
//	}
//		r = sqlite3_reset(stmt);
//	if(r != SQLITE_OK) {
//		sqlite3_finalize(stmt);
//		return NULL;
//	}
		size_t column_size = (size_t)sqlite3_column_count(stmt);
		//DBG_P("column_size=%d", column_size);
		knh_ResultSet_initColumn(ctx, rs, column_size);
		if(column_size > 0) {
			size_t i;
			for(i = 0; i < DP(rs)->column_size; i++) {
				char *n = (char*)sqlite3_column_name(stmt, i);
				//DBG_P("(%d) name = '%s'", i, n);
				if(n != NULL) {
					ResultSet_setName(ctx, rs, i, new_S(ctx, B(n)));
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

static const knh_QueryDSPI_t QUERY_SQLITE3 = {
	K_DSPI_QUERY, "sqlite3",
	SQLITE3_qopen, SQLITE3_query, SQLITE3_qclose, SQLITE3_qnext, SQLITE3_qfree
};

#endif/*K_USING_SQLITE3*/

/* ------------------------------------------------------------------------ */

const knh_QueryDSPI_t *knh_getQueryDSPI(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	if(path.len == 0) {
		return &QUERY_NOP;
	}
	else {
		const knh_QueryDSPI_t *p = (const knh_QueryDSPI_t *)knh_NameSpace_getDSPINULL(ctx, ns, K_DSPI_QUERY, path);
		if(p == NULL) {
			SYSLOG_UnknownPathType(ctx, path);
			p = &QUERY_NOP;
		}
		return p;
	}
}

/* ------------------------------------------------------------------------ */

static knh_bool_t tolowercase(CTX ctx, knh_conv_t *cv, knh_bytes_t t, knh_Bytes_t *tobuf)
{
	size_t i, s = BA_size(tobuf);
	knh_Bytes_write(ctx, tobuf, t);
	knh_bytes_t tt = {{tobuf->bu.text + s}, BA_size(tobuf) - s};
	for(i = 0; i < tt.len; i++) {
		int ch = tt.ustr[i];
		if('A' <= ch && ch <= 'Z') {
			tt.ubuf[i] = ch - 'A' + 'a';
		}
	}
	return 1;
}

static knh_bool_t touppercase(CTX ctx, knh_conv_t *cv, knh_bytes_t t, knh_Bytes_t *tobuf)
{
	size_t i, s = BA_size(tobuf);
	knh_Bytes_write(ctx, tobuf, t);
	knh_bytes_t tt = {{tobuf->bu.text + s}, BA_size(tobuf) - s};
	for(i = 0; i < tt.len; i++) {
		int ch = tt.ustr[i];
		if('a' <= ch && ch <= 'z') {
			tt.ubuf[i] = ch - 'a' + 'A';
		}
	}
	return 1;
}

static const knh_ConvDSPI_t TO_lower = {
	K_DSPI_CONVTO, "lower",
	NULL, tolowercase, tolowercase, tolowercase, tolowercase, NULL, NULL,
};

static const knh_ConvDSPI_t TO_upper = {
	K_DSPI_CONVTO, "upper",
	NULL, touppercase, touppercase, touppercase, touppercase, NULL, NULL,
};

void knh_loadScriptDriver(CTX ctx, knh_NameSpace_t *ns)
{
	const knh_PackageLoaderAPI_t *api = knh_getPackageAPI();
	api->addPathDSPI(ctx, ns, NULL, &PATH_NOPATH);
	api->addPathDSPI(ctx, ns, "charset", &PATH_CHARSET);
	api->addPathDSPI(ctx, ns, "to", &PATH_TOPATH);
	api->addPathDSPI(ctx, ns, "from", &PATH_FROMPATH);
//	api->addPathDSPI(ctx, ns, "class", &CLASSPATH_DSPI);
//	api->addPathDSPI(ctx, ns, "method", &METHODPATH_DSPI);
	api->addPathDSPI(ctx, ns, "file", &PATH_FILE);
//	api->addPathDSPI(ctx, ns, "dir", &DIRPATH_DSPI);
	api->addPathDSPI(ctx, ns, "lib", &PATH_LIB);

	api->addPathDSPI(ctx, ns, "pkg", &PATH_PKG);
	api->addPathDSPI(ctx, ns, "script", &PATH_SCRIPT);
//	api->addPathDSPI(ctx, ns, "tool", &TOOLPATH_DSPI);

	api->addConvDSPI(ctx, ns, "lower", &TO_lower);
	api->addConvDSPI(ctx, ns, "upper", &TO_upper);

	api->addStreamDSPI(ctx, ns, NULL, &STREAM_NOFILE);
	api->addStreamDSPI(ctx, ns, "file", &STREAM_FILE);
	api->addStreamDSPI(ctx, ns, "script", &STREAM_SCRIPT);
//	api->addStreamDSPI(ctx, ns, "tool", &TOOLFILE_DSPI);
	api->addStreamDSPI(ctx, ns, "pkg", &STREAM_PKG);

	api->addQueryDSPI(ctx, ns, NULL, &QUERY_NOP);
#ifdef K_USING_SQLITE3
	api->addQueryDSPI(ctx, ns, "sqlite3", &QUERY_SQLITE3);
#endif
}

/* ------------------------------------------------------------------------ */
#endif/* K_INCLUDE_BUILTINAPI*/

#ifdef __cplusplus
}
#endif
