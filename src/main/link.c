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

#define USE_bytes_next        1
#define USE_bytes_rnext       1
#define USE_bytes_startsWith  1
#define USE_bytes_endsWith    1
#define USE_STEXT             1
#define USE_B                 1
#define USE_cwb_open          1

#include"commons.h"

/* ************************************************************************ */

#ifdef K_USING_CURL
#include<curl/curl.h>
#endif/*K_USING_CURL*/

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* K_DSPI_STREAM */

static knh_io_t NOFILE_open(CTX ctx, const char *fname, const char *mode)
{
	return IO_NULL;
}
static knh_intptr_t NOFILE_read(CTX ctx, knh_io_t fd, char *buf, size_t bufsiz)
{
	return 0;  // read nothing. this means that we reach the end of the stream.
}
static knh_intptr_t NOFILE_write(CTX ctx, knh_io_t fd, const char *buf, size_t bufsiz)
{
	DBG_ASSERT(fd != IO_BUF);
	return bufsiz;
}
static knh_intptr_t BYTE_write(CTX ctx, knh_io_t fd, const char *buf, size_t bufsiz)
{
	DBG_ASSERT(fd == IO_BUF);
	return 0; // write nothing. this means that we are unable to clear buffer
}
static void NOFILE_close(CTX ctx, knh_io_t fd)
{
}

static const knh_StreamDPI_t STREAM_NOFILE = {
	K_DSPI_STREAM, "NOFILE", K_PAGESIZE,
	NOFILE_open, NOFILE_open, NOFILE_read, NOFILE_write, NOFILE_close
};

static const knh_StreamDPI_t STREAM_BYTE = {
	K_DSPI_STREAM, "BYTE", K_OUTBUF_MAXSIZ,
	NOFILE_open, NOFILE_open, NOFILE_read, BYTE_write, NOFILE_close
};

static knh_io_t FILE_open(CTX ctx, const char *fname, const char *mode)
{
	return (knh_io_t)fopen(fname, mode);
}

static knh_io_t NOFILE_wopen(CTX ctx, const char *fname, const char *mode)
{
	return IO_NULL;
}

static knh_intptr_t FILE_read(CTX ctx, knh_io_t fio, char *buf, size_t bufsiz)
{
	return fread(buf, 1, bufsiz, (FILE*)fio);
}

static knh_intptr_t FILE_write(CTX ctx, knh_io_t fio, const char *buf, size_t bufsiz)
{
	knh_intptr_t ssize = fwrite(buf, 1, bufsiz, (FILE*)fio);
	fflush((FILE*)fio);
	return ssize;
}

static void FILE_close(CTX ctx, knh_io_t fd)
{
	fclose((FILE*)fd);
}

static const knh_StreamDPI_t STREAM_FILE = {
	K_DSPI_STREAM, "file", K_OUTBUF_MAXSIZ,
	FILE_open, FILE_open, FILE_read, FILE_write, FILE_close,
};

static const knh_StreamDPI_t STREAM_STDIO = {
	K_DSPI_STREAM, "stdio", K_OUTBUF_MAXSIZ,
	NOFILE_open, NOFILE_wopen, FILE_read, FILE_write, NOFILE_close,
};

KNHAPI2(knh_InputStream_t*) new_InputStreamDPI(CTX ctx, knh_io_t fio, const knh_StreamDPI_t *dspi)
{
	knh_InputStream_t* in = new_(InputStream);
	DP(in)->fio  = fio;
	if(fio == IO_NULL) {
		dspi = &STREAM_NOFILE;
		knh_Object_toNULL(ctx, in);
	}
	else {
		KNH_ASSERT(DP(in)->ba->bu.len == 0);
		knh_Bytes_expands(ctx, DP(in)->ba, K_STREAM_BUFSIZ);
	}
	in->dspi = (dspi == NULL) ? &STREAM_FILE : dspi;
	return in;
}

KNHAPI2(knh_OutputStream_t*) new_OutputStreamDPI(CTX ctx, knh_io_t fio, const knh_StreamDPI_t *dspi)
{
	knh_OutputStream_t* w = new_(OutputStream);
	DP(w)->fio = fio;
	if(fio == IO_NULL) {
		dspi = &STREAM_NOFILE;
		knh_Object_toNULL(ctx, w);
	}
	w->dspi = (dspi == NULL) ? &STREAM_FILE : dspi;
	return w;
}

knh_InputStream_t *new_InputStreamSTDIO(CTX ctx, FILE *fp, knh_String_t *enc)
{
	knh_InputStream_t* in = new_InputStreamDPI(ctx, (knh_io_t)stdin, &STREAM_STDIO);
	KNH_SETv(ctx, DP(in)->urn, TS_DEVSTDIN);
	return in;
}

knh_OutputStream_t *new_OutputStreamSTDIO(CTX ctx, FILE *fp, knh_String_t *enc)
{
#ifdef K_USING_NOFILE
	knh_OutputStream_t* o = new_OutputStream__FILE(ctx, TS_DEVSTDOUT, NULL, &STREAM_STDIO);
#else
	KNH_ASSERT(fp == stdout || fp == stderr);
	knh_OutputStream_t* o = new_OutputStreamDPI(ctx, (knh_io_t)fp, &STREAM_STDIO);
	knh_String_t *urn = (fp == stdout) ? TS_DEVSTDOUT : TS_DEVSTDERR;
	KNH_SETv(ctx, DP(o)->urn, urn);
#endif
	OutputStream_setAutoFlush(o, 1);
	return o;
}

knh_InputStream_t* knh_Bytes_openInputStream(CTX ctx, knh_Bytes_t *ba, size_t pos, knh_String_t *path)
{
	FILE *fp = fopen(knh_Bytes_ensureZero(ctx, ba)+pos, "r");
	return new_InputStreamDPI(ctx, (knh_io_t)fp, &STREAM_FILE);
}

knh_OutputStream_t* knh_Bytes_openOutputStream(CTX ctx, knh_Bytes_t *ba, size_t pos, knh_String_t *path)
{
	FILE *fp = fopen(knh_Bytes_ensureZero(ctx, ba)+pos, "a");
	return new_OutputStreamDPI(ctx, (knh_io_t)fp, &STREAM_FILE);
}

static void SYSLOG_UnknownPathType(CTX ctx, knh_bytes_t path)
{
	KNH_LOG("undefined path='%s'", path.text);
}

const knh_StreamDPI_t *knh_getDefaultStreamDPI(void)
{
	return &STREAM_NOFILE;
}

const knh_StreamDPI_t *knh_getByteStreamDPI(void)
{
	return &STREAM_BYTE;
}

const knh_StreamDPI_t *knh_getStreamDPI(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	const knh_StreamDPI_t *p = (const knh_StreamDPI_t*)knh_NameSpace_getDSPINULL(ctx, ns, K_DSPI_STREAM, path);
	if(p == NULL) {
		p = &STREAM_FILE;
	}
	return p;
}

knh_bool_t knh_isFILEStreamDPI(const knh_StreamDPI_t *dpi)
{
	return (dpi == &STREAM_FILE);
}

/* ------------------------------------------------------------------------ */
/* [LINK] */

static knh_bool_t NOLINK_hasType(CTX ctx, knh_class_t cid)
{
	return 0;
}
static knh_bool_t NOLINK_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	return 0;
}
static knh_Object_t* NOLINK_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
{
	return NULL/*(knh_Object_t*)s*/;
}

static const knh_LinkDPI_t LINK_NOLINK = {
	"NOLINK", NULL, NOLINK_hasType, NOLINK_exists, NOLINK_newObjectNULL,
};

/* link:link*/
static knh_bool_t LINK_hasType(CTX ctx, knh_class_t cid)
{
	return (cid == CLASS_Link);
}
static knh_bool_t LINK_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	knh_bytes_t bpath = knh_bytes_next(path, ':');
	knh_Link_t *lnk = knh_NameSpace_getLinkNULL(ctx, ns, bpath);
	return (lnk != NULL);
}
static knh_Object_t* LINK_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
{
	if(cid == CLASS_Link) {
		knh_bytes_t bpath = knh_bytes_next(S_tobytes(s), ':');
		knh_Link_t *lnk = knh_NameSpace_getLinkNULL(ctx, ns, bpath);
		return UPCAST(lnk);
	}
	return NULL/*(knh_Object_t*)s*/;
}

static const knh_LinkDPI_t LINK_LINK = {
	"NOLINK", "Link", LINK_hasType, LINK_exists, LINK_newObjectNULL,
};

/* charset:UTF-8 */
static knh_bool_t CHARSET_hasType(CTX ctx, knh_class_t cid)
{
	return (cid == CLASS_StringEncoder || cid == CLASS_StringDecoder);
}

static knh_bool_t CHARSET_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	knh_bytes_t t = knh_bytes_next(path, ':');
	iconv_t ic = ctx->spi->iconv_open(t.text, K_ENCODING);
	if(ic != (iconv_t)(-1)) {
		ctx->spi->iconv_close(ic);
		return 1;
	}
	else if(knh_bytes_strcasecmp(t, STEXT(K_ENCODING)) == 0) {
		return 1;
	}
	return 0;
}

static knh_Object_t* CHARSET_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
{
	knh_bytes_t t = knh_bytes_next(S_tobytes(s), ':');
	if(cid == CLASS_StringEncoder) {
		return (knh_Object_t*)new_StringEncoderNULL(ctx, t);
	}
	if(cid == CLASS_StringDecoder) {
		return (knh_Object_t*)new_StringDecoderNULL(ctx, t);
	}
	return NULL;
}

static const knh_LinkDPI_t LINK_CHARSET = {
	"charset", "StringConverter|StringDecoder", CHARSET_hasType, CHARSET_exists, CHARSET_newObjectNULL,
};

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
			KNH_LOG("unknown path='%s'", path.text);
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

/* to:md5 */
static knh_bool_t TOLINK_hasType(CTX ctx, knh_class_t cid)
{
	return IS_CONV(cid);
}
static knh_bool_t TOLINK_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	const knh_ConvDSPI_t *dspi = knh_NameSpace_getConvTODSPINULL(ctx, ns, knh_bytes_next(path, ':'));
	return (dspi != NULL);
}
static knh_Object_t* TOLINK_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
{
	knh_bytes_t path = knh_bytes_next(S_tobytes(s), ':');
	const knh_ConvDSPI_t *dspi = knh_NameSpace_getConvTODSPINULL(ctx, ns, path);
	KNH_ASSERT(dspi != NULL); // checked before
	if(IS_CONV(cid)) {
		return new_ConverterNULL(ctx, cid, path, dspi);
	}
	return NULL;
}

/* from:toLower */
static knh_bool_t FROMLINK_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	const knh_ConvDSPI_t *dspi = knh_NameSpace_getConvFROMDSPINULL(ctx, ns, knh_bytes_next(path, ':'));
	return (dspi != NULL);
}

static knh_Object_t* FROMLINK_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
{
	knh_bytes_t path = knh_bytes_next(S_tobytes(s), ':');
	const knh_ConvDSPI_t *dspi = knh_NameSpace_getConvFROMDSPINULL(ctx, ns, path);
	KNH_ASSERT(dspi != NULL); // checked before
	if(IS_CONV(cid)) {
		return new_ConverterNULL(ctx, cid, path, dspi);
	}
	return NULL;
}

static const knh_LinkDPI_t LINK_TOLINK = {
	"to", "Converter|StringConverter|StringDecoder|StringEncoder",
	TOLINK_hasType, TOLINK_exists, TOLINK_newObjectNULL,
};

static const knh_LinkDPI_t LINK_FROMLINK = {
	"from", "Converter|StringConverter|StringDecoder|StringEncoder",
	TOLINK_hasType, FROMLINK_exists, FROMLINK_newObjectNULL,
};

static knh_bool_t LIB_hasType(CTX ctx, knh_class_t cid)
{
	return 0;
}

static knh_bool_t LIB_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_bytes_t libname = knh_bytes_next(path, ':');
	knh_bytes_t funcname = knh_bytes_rnext(path, '.');
	libname = knh_cwb_ensure(ctx, cwb, libname, K_PATHMAX);
	knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, libname);
	knh_buff_trim(ctx, cwb->ba, cwb->pos, '.');
	knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, STEXT(K_OSDLLEXT));
	void *p = knh_dlopen(ctx, knh_cwb_tochar(ctx, cwb));
	if(p == NULL && !knh_bytes_startsWith(libname, STEXT("lib"))) {
		knh_cwb_clear(cwb, 0);
		knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, STEXT("lib"));
		knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, libname);
		knh_buff_trim(ctx, cwb->ba, cwb->pos, '.');
		knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, STEXT(K_OSDLLEXT));
		p = knh_dlopen(ctx, knh_cwb_tochar(ctx, cwb));
	}
	knh_cwb_close(cwb);
	knh_bool_t res = 0;
	if(p != NULL) {
		if(funcname.len != libname.len) {
			void *f = knh_dlsym(ctx, p, funcname.text, 1/*isTest*/);
			res = (f != NULL);
		}
		knh_dlclose(ctx, p);
	}
	return res;
}

static const knh_LinkDPI_t LINK_LIB = {
	"lib", NULL, LIB_hasType, LIB_exists, NOLINK_newObjectNULL,
};

/* ------------------------------------------------------------------------ */
/* file:/usr/local */

static knh_bool_t FILE_hasType(CTX ctx, knh_class_t cid)
{
	return (cid == CLASS_Bytes || cid == CLASS_InputStream || cid == CLASS_OutputStream);
}
static knh_bool_t FILE_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_bytes_t bpath = knh_bytes_next(path, ':');
	bpath = knh_cwb_ensure(ctx, cwb, bpath, K_PATHMAX);
	knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, bpath);
	knh_bool_t res = knh_Bytes_isfile(ctx, cwb->ba, cwb->pos);
	knh_cwb_clear(cwb, 0);
	return res;
}

static knh_Object_t* FILE_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
{
	knh_Object_t *res = NULL;
	if(cid == CLASS_Bytes) {
		knh_Bytes_t* ba = new_Bytes(ctx, NULL, S_size(s));
		knh_buff_addospath(ctx, ba, 0, 0, knh_bytes_next(S_tobytes(s), ':'));
		return UPCAST(ba);
	}
	if(cid == CLASS_InputStream || cid == CLASS_OutputStream) {
		knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
		knh_bytes_t bpath = knh_bytes_next(S_tobytes(s), ':');
		knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, bpath);
		if(cid == CLASS_InputStream) {
			res = (knh_Object_t*)knh_Bytes_openInputStream(ctx, cwb->ba, cwb->pos, s);
		}
		else {
			res = (knh_Object_t*)knh_Bytes_openOutputStream(ctx, cwb->ba, cwb->pos, s);
		}
		knh_cwb_clear(cwb, 0);
	}
	return res;
}

static const knh_LinkDPI_t LINK_FILE = {
	"file", "byte[]|InputStream|OutputStream", FILE_hasType, FILE_exists, FILE_newObjectNULL,
};

static knh_bool_t isFoundPackage(CTX ctx, knh_Bytes_t* ba, size_t pos, knh_bytes_t tpath, knh_bytes_t bpath)
{
	knh_Bytes_clear(ba, pos);
	knh_buff_addospath(ctx, ba, pos, 0, tpath);
	knh_buff_addospath(ctx, ba, pos, 1, bpath); // konoha.math
	knh_buff_addospath(ctx, ba, pos, 1, knh_bytes_rnext(bpath, '.')); // math
	knh_buff_addospath(ctx, ba, pos, 0, STEXT(".k"));
	return knh_Bytes_isfile(ctx, ba, pos);
}

knh_bool_t knh_Bytes_addPackagePath(CTX ctx, knh_Bytes_t *ba, size_t pos, knh_bytes_t path)
{
	char *epath = knh_getenv("KONOHA_PACKAGE");
	knh_bytes_t bpath = knh_bytes_next(path, ':');
	if(epath != NULL && isFoundPackage(ctx, ba, pos, B(epath), bpath)) {
		return 1;
	}
	knh_String_t *tpath = knh_getPropertyNULL(ctx, STEXT("konoha.package.path"));
	if(tpath != NULL && isFoundPackage(ctx, ba, pos, S_tobytes(tpath), bpath)) {
		return 1;
	}
	tpath = knh_getPropertyNULL(ctx, STEXT("user.package.path"));
	if(tpath != NULL && isFoundPackage(ctx, ba, pos, S_tobytes(tpath), bpath)) {
		return 1;
	}
	return 0;
}

static knh_bool_t PACKAGE_hasType(CTX ctx, knh_class_t cid)
{
	return (cid == CLASS_Bytes || cid == CLASS_InputStream);
}

static knh_bool_t PACKAGE_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_bytes_t bpath = knh_bytes_next(path, ':');
	bpath = knh_cwb_ensure(ctx, cwb, bpath, K_PATHMAX);
	knh_bool_t res = knh_Bytes_addPackagePath(ctx, cwb->ba, cwb->pos, bpath);
	knh_cwb_clear(cwb, 0);
	return res;
}

static knh_Object_t* PACKAGE_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
{
	knh_Object_t *res = NULL;
	if(cid == CLASS_Bytes) {
		knh_Bytes_t* ba = new_Bytes(ctx, NULL, 256);
		if(!knh_Bytes_addPackagePath(ctx, ba, 0, S_tobytes(s))) {
			knh_Object_toNULL(ctx, ba);
		}
		return UPCAST(ba);
	}
	if(cid == CLASS_InputStream) {
		knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
		knh_bytes_t bpath = knh_bytes_next(S_tobytes(s), ':');
		knh_Bytes_addPackagePath(ctx, cwb->ba, cwb->pos, bpath);
		res = (knh_Object_t*)knh_Bytes_openInputStream(ctx, cwb->ba, cwb->pos, s);
		knh_cwb_clear(cwb, 0);
	}
	return res;
}

static const knh_LinkDPI_t LINK_PKG = {
	"pkg", "byte[]|InputStream", PACKAGE_hasType, PACKAGE_exists, PACKAGE_newObjectNULL,
};

void knh_Bytes_addScriptPath(CTX ctx, knh_Bytes_t *ba, size_t pos, knh_NameSpace_t *ns, knh_bytes_t path)
{
	knh_bytes_t bpath = knh_bytes_next(path, ':');
	knh_buff_addospath(ctx, ba, pos, 0, S_tobytes(ns->rpath));
	knh_buff_addospath(ctx, ba, pos, 1, bpath);
}

static knh_bool_t SCRIPT_exists(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_bytes_t bpath = knh_bytes_next(path, ':');
	bpath = knh_cwb_ensure(ctx, cwb, bpath, K_PATHMAX);
	knh_Bytes_addScriptPath(ctx, cwb->ba, cwb->pos, ns, bpath);
	knh_bool_t res = knh_exists(ctx, knh_cwb_tochar(ctx, cwb));
	knh_cwb_clear(cwb, 0);
	return res;
}

static knh_Object_t* SCRIPT_newObjectNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
{
	knh_Object_t *res = NULL;
	if(cid == CLASS_Bytes) {
		knh_Bytes_t* ba = new_Bytes(ctx, NULL, 256);
		knh_Bytes_addScriptPath(ctx, ba, 0, ns, S_tobytes(s));
		return UPCAST(ba);
	}
	if(cid == CLASS_InputStream || cid == CLASS_OutputStream) {
		knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
		knh_bytes_t bpath = knh_bytes_next(S_tobytes(s), ':');
		knh_Bytes_addScriptPath(ctx, cwb->ba, cwb->pos, ns, bpath);
		if(cid == CLASS_InputStream) {
			res = (knh_Object_t*)knh_Bytes_openInputStream(ctx, cwb->ba, cwb->pos, s);
		}
		else {
			res = (knh_Object_t*)knh_Bytes_openOutputStream(ctx, cwb->ba, cwb->pos, s);
		}
		knh_cwb_clear(cwb, 0);
	}
	return NULL;
}

static const knh_LinkDPI_t LINK_SCRIPT = {
	"script", "byte[]|InputStream|OutputStream", FILE_hasType, SCRIPT_exists, SCRIPT_newObjectNULL,
};


/* ------------------------------------------------------------------------ */

#ifdef K_USING_CURL

typedef struct {
	CURL *curl;
	const char *charset;
	const char *contenttype;
	char *buffer;               /* buffer to store cached data*/
	long pos;
	long buffer_len;             /* currently allocated buffers length */
	long buffer_pos;             /* end of data in buffer*/
	int still_running;          /* Is background url fetch still in progress */
} CURLFILE;

/* This global variable was originated in a sample code in libcurl */
static CURLM *multi_handle = NULL;
static CURLM *emulti_handle = NULL;

static size_t write_callback(char *buffer, size_t size, size_t nitems, void *userp)
{
	char *newbuff;
	CURLFILE *url = (CURLFILE *)userp;
	size *= nitems;
	long rembuff = url->buffer_len - url->buffer_pos; /* remaining space in buffer */
	if(size > rembuff) {
		newbuff = realloc(url->buffer, url->buffer_len + (size - rembuff));
		if(newbuff == NULL) {
			size = rembuff;
		}
		else {
			url->buffer_len += size - rembuff;
			url->buffer = newbuff;
		}
	}
	memcpy(&url->buffer[url->buffer_pos], buffer, size);
	url->buffer_pos += size;
	if(url->contenttype == NULL){
		char *type = NULL;
		curl_easy_getinfo(url->curl, CURLINFO_CONTENT_TYPE, &type);
		if(type != NULL){
			char *charset = NULL;
			charset = strrchr(type, '=');
			if(charset != NULL){
				charset++;
				type = strtok(type, ";");
			}
			url->charset = (const char*)charset;
			url->contenttype = (const char*)type;
		}
	}
	return size;
}

static int fill_buffer(CURLFILE *file, int want, int waittime)
{
	fd_set fdread;
	fd_set fdwrite;
	fd_set fdexcep;
	struct timeval timeout;
	int rc;
	/* only attempt to fill buffer if transactions still running and buffer
	 * doesnt exceed required size already
	 */
	if((!file->still_running) || (file->buffer_pos > want))
		return 0;

	/* attempt to fill buffer */
	do {
		int maxfd = -1;
		FD_ZERO(&fdread);
		FD_ZERO(&fdwrite);
		FD_ZERO(&fdexcep);

		/* set a suitable timeout to fail on */
		timeout.tv_sec = 60; /* 1 minute */
		timeout.tv_usec = 0;

		/* get file descriptors from the transfers */
		curl_multi_fdset(multi_handle, &fdread, &fdwrite, &fdexcep, &maxfd);

		/* In a real-world program you OF COURSE check the return code of the
           function calls.  On success, the value of maxfd is guaranteed to be
           greater or equal than -1.  We call select(maxfd + 1, ...), specially
           in case of (maxfd == -1), we call select(0, ...), which is basically
           equal to sleep. */

		rc = select(maxfd+1, &fdread, &fdwrite, &fdexcep, &timeout);
		switch(rc) {
		case -1: /* select error */
		case 0: break;
		default:
			/* timeout or readable/writable sockets */
			/* note we *could* be more efficient and not wait for
			 * CURLM_CALL_MULTI_PERFORM to clear here and check it on re-entry
			 * but that gets messy */
			while(curl_multi_perform(multi_handle, &file->still_running) == CURLM_CALL_MULTI_PERFORM);
			break;
		}
	} while(file->still_running && (file->buffer_pos < want));
	return 1;
}

/* use to remove want bytes from the front of a files buffer */
static int use_buffer(CURLFILE *file, int want)
{
	/* sort out buffer */
	if((file->buffer_pos - want) <= 0) {
		/* ditch buffer - write will recreate */
		if(file->buffer != NULL) free(file->buffer);
		file->buffer=NULL;
		file->buffer_pos=0;
		file->buffer_len=0;
	} else { /* move rest down make it available for later */
		memmove(file->buffer, &file->buffer[want], (file->buffer_pos - want));
		file->buffer_pos -= want;
	}
	return 0;
}

static knh_io_t CURL_open(Ctx *ctx, knh_bytes_t path, const char *mode)
{
	//TODO mode treats as method
	CURLFILE *file = malloc(sizeof(CURLFILE));
	if(file == NULL) return (knh_io_t)NULL;
	memset(file, 0, sizeof(CURLFILE));
	file->curl = curl_easy_init();
	curl_easy_setopt(file->curl, CURLOPT_URL, path.ubuf);
	curl_easy_setopt(file->curl, CURLOPT_WRITEDATA, file);
	curl_easy_setopt(file->curl, CURLOPT_VERBOSE, 0L);
	curl_easy_setopt(file->curl, CURLOPT_WRITEFUNCTION, write_callback);
	if(!multi_handle) multi_handle = curl_multi_init();
	curl_multi_add_handle(multi_handle, file->curl);

	/* lets start the fetch */
	while(curl_multi_perform(multi_handle, &file->still_running) == CURLM_CALL_MULTI_PERFORM );

	if((file->buffer_pos == 0) && (!file->still_running)) {
		/* if still_running is 0 now, we should return NULL */
		/* make sure the easy handle is not in the multi handle anymore */
		curl_multi_remove_handle(multi_handle, file->curl);
		/* cleanup */
		curl_easy_cleanup(file->curl);
		free(file);
		file = NULL;
	}
	return (knh_io_t)file;
}

//new OutputStream(http://...)
static knh_io_t CURL_init(Ctx *ctx, knh_bytes_t path, const char *mode)
{
	return (knh_io_t)NULL;
}

static void CURL_close(Ctx *ctx, knh_io_t fd)
{
	CURLFILE *file = (CURLFILE*)fd;
	curl_multi_remove_handle(multi_handle, file->curl);
	curl_easy_cleanup(file->curl);
	if(file->buffer) free(file->buffer);
	free(file);
}

static int url_feof(CURLFILE *file)
{
	int ret=0;
	if((file->buffer_pos == 0) && (!file->still_running))
		ret = 1;
	return ret;
}

static knh_intptr_t CURL_read(Ctx *ctx, knh_io_t fd, char *buf, size_t bufsiz)
{
	CURLFILE *file = (CURLFILE*)fd;
	if(file == NULL) return 0;
	fill_buffer(file, bufsiz, 1);
	if(!file->buffer_pos) return 0;
	/* ensure only available data is considered */
	if(file->buffer_pos < bufsiz) bufsiz = file->buffer_pos;
	/* xfer data to caller */
	memcpy(buf, file->buffer, bufsiz);
	use_buffer(file, bufsiz);
	return bufsiz;
}

static knh_intptr_t CURL_write(Ctx *ctx, knh_io_t fd, const char *buf, size_t bufsiz)
{
	return 0;
}

static int CURL_feof(Ctx *ctx, knh_io_t fd)
{
	return url_feof((CURLFILE*)fd);
}

static int CURL_getc(Ctx *ctx, knh_io_t fd)
{
	CURLFILE *file = (CURLFILE*)fd;
	if(!file->buffer_pos || file->buffer_pos < file->buffer_len)
		fill_buffer(file, 1024, 1);
	return file->buffer[file->buffer_pos++];
}

static const char* CURL_getContentType(Ctx *ctx, knh_io_t fd)
{
	CURLFILE *file = (CURLFILE*)fd;
	if(file != NULL){
		if(file->contenttype != NULL){
			return file->contenttype;
		}
	}
	return NULL;
}

static const char* CURL_getCharset(Ctx *ctx, knh_io_t fd)
{
	CURLFILE *file = (CURLFILE*)fd;
	if(file != NULL){
		if(file->charset != NULL){
			return file->charset;
		}
	}
	return NULL;
}

static knh_StreamDPI_t STREAM_CURL = {
		K_DSPI_STREAM, "curl", 0,
		CURL_open, CURL_init, CURL_read, CURL_write, CURL_close,
		CURL_feof, CURL_getc, CURL_getContentType, CURL_getCharset
};

static knh_bool_t CURL_exists(Ctx *ctx, knh_NameSpace_t *ns, knh_bytes_t path)
{
	CURLFILE *file = knh_malloc(ctx, sizeof(CURLFILE));
	if(file == NULL) return LINK_unknown;
	memset(file, 0, sizeof(CURLFILE));
	file->curl = curl_easy_init();
	curl_easy_setopt(file->curl, CURLOPT_URL, path.ubuf);
	curl_easy_setopt(file->curl, CURLOPT_WRITEDATA, file);
	curl_easy_setopt(file->curl, CURLOPT_VERBOSE, 0L);
	curl_easy_setopt(file->curl, CURLOPT_WRITEFUNCTION, write_callback);

	emulti_handle = curl_multi_init();
	curl_multi_add_handle(emulti_handle, file->curl);

	/* lets start the fetch */
	while(curl_multi_perform(emulti_handle, &file->still_running) == CURLM_CALL_MULTI_PERFORM );
	if((file->buffer_pos == 0) && (!file->still_running)) {
		/* if still_running is 0 now, we should return NULL */
		/* make sure the easy handle is not in the multi handle anymore */
		curl_multi_remove_handle(emulti_handle, file->curl);
		/* cleanup */
		curl_easy_cleanup(file->curl);
		knh_free(ctx, file, sizeof(CURLFILE));
		emulti_handle = NULL;
		file = NULL;
		return LINK_unknown;
	}
	emulti_handle = NULL;
	knh_free(ctx, file, sizeof(CURLFILE));
	return (knh_bool_t)1;
}

static knh_bool_t CURL_hasType(Ctx *ctx, knh_class_t cid)
{
	return (cid == CLASS_InputStream);
}

static Object* CURL_newObjectNULL(Ctx *ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_String_t *s)
{
	return (Object*)s;
}

static knh_LinkDPI_t LINK_CURL = {
		K_DSPI_LINK, "curl", CLASS_InputStream, CLASS_Tvoid,
		CURL_hasType, CURL_exists, CURL_newObjectNULL
};

#endif/*K_USING_CURL*/

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
	KNH_LOG("sqlite3_error='%s'", sqlite3_errmsg(db));
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
		int ch = tt.utext[i];
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
		int ch = tt.utext[i];
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

void knh_loadSystemDriver(CTX ctx, knh_NameSpace_t *ns)
{
	const knh_PackageLoaderAPI_t *api = knh_getPackageLoaderAPI();
	api->addLinkDPI(ctx, ns, "link", &LINK_LINK);
	api->addLinkDPI(ctx, ns, "charset", &LINK_CHARSET);
	api->addLinkDPI(ctx, ns, "to", &LINK_TOLINK);
	api->addLinkDPI(ctx, ns, "from", &LINK_FROMLINK);
	api->addLinkDPI(ctx, ns, "file", &LINK_FILE);
	api->addLinkDPI(ctx, ns, "lib", &LINK_LIB);
	api->addLinkDPI(ctx, ns, "pkg", &LINK_PKG);
	api->addLinkDPI(ctx, ns, "script", &LINK_SCRIPT);

	api->addConvDSPI(ctx, ns, "lower", &TO_lower);
	api->addConvDSPI(ctx, ns, "upper", &TO_upper);
	api->addStreamDPI(ctx, ns, NULL, &STREAM_NOFILE);
	api->addStreamDPI(ctx, ns, "file", &STREAM_FILE);
	api->addQueryDSPI(ctx, ns, NULL, &QUERY_NOP);
#ifdef K_USING_SQLITE3
	api->addQueryDSPI(ctx, ns, "sqlite3", &QUERY_SQLITE3);
#endif
#ifdef K_USING_CURL
	api->addLinkDPI(ctx, ns, "http", &LINK_CURL);
	api->addStreamDPI(ctx, ns, "http", &STREAM_CURL);
#endif
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
