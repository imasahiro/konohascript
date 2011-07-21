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

#ifdef __cplusplus
extern "C" {
#endif

#include"commons.h"

/* ************************************************************************ */

void knh_buff_addpath(CTX ctx, knh_Bytes_t *ba, size_t pos, int needsSEP, knh_bytes_t t)
{
	size_t i;
	if(needsSEP) {
		knh_bytes_t b = {{ba->bu.text}, pos};
		if(!(b.len > 0 && b.buf[b.len-1] == '/')) {
			knh_Bytes_putc(ctx, ba, '/');
		}
	}
	for(i = 0; i < t.len; i++) {
		int ch = t.ubuf[i];
		knh_Bytes_putc(ctx, ba, ch);
	}
}

void knh_buff_addospath(CTX ctx, knh_Bytes_t *ba, size_t pos, int needsSEP, knh_bytes_t t)
{
	size_t i;
	if(needsSEP) {
		knh_bytes_t b = {{ba->bu.text}, pos};
		if(!(b.len > 0 && b.buf[b.len-1] == K_SEP)) {
			knh_Bytes_putc(ctx, ba, K_SEP);
		}
	}
	for(i = 0; i < t.len; i++) {
		int ch = t.ubuf[i];
		if(ch == '\\' || ch == '/') ch = K_SEP;
		if(ch < 128) {
			knh_Bytes_putc(ctx, ba, ch);
			continue;
		}
		knh_Bytes_putc(ctx, ba, ch);
	}
}

void knh_buff_trim(CTX ctx, knh_Bytes_t *ba, size_t pos, int ch)
{
	knh_uchar_t *ubuf = ba->bu.ubuf + pos;
	long i, len = BA_size(ba) - pos;
	if(ch == '/' && ch != K_SEP) ch = K_SEP;
	for(i = len - 1; i >= 0 ; i--) {
		if(ubuf[i] == ch) {
			knh_Bytes_clear(ba, pos + i);
			return;
		}
	}
}

KNHAPI2(knh_bool_t) knh_String_ospath(CTX ctx, knh_String_t *s, knh_NameSpace_t *ns, char *buf, size_t bufsiz)
{
	knh_bool_t res = 0;
	knh_index_t loc = knh_bytes_index(S_tobytes(s), ':');
	if(loc == -1) {
		knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
//		knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, S_tobytes(ns->rpath));
		knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, S_tobytes(s));
		const char *p = knh_cwb_tochar(ctx, cwb);
		size_t len = knh_strlen(p) + 1;
		if(len < bufsiz) {
			knh_memcpy(buf, p, len); res = 1;
		}
		knh_cwb_close(cwb);
	}
	else {
		knh_Link_t *lnk = knh_NameSpace_getLinkNULL(ctx, ns, S_tobytes(s));
		if(lnk != NULL && knh_Link_hasType(ctx, lnk, CLASS_Bytes)) {
			knh_Bytes_t *ba = (knh_Bytes_t*)knh_Link_newObjectNULL(ctx, lnk, ns, s, CLASS_Bytes);
			if(ba != NULL) {
				KNH_SETv(ctx, ctx->esp[0].o, ba);  //TOGC
				knh_Bytes_ensureZero(ctx, ba);
				if(BA_size(ba) + 1 < bufsiz) {
					knh_memcpy(buf, ba->bu.buf, BA_size(ba) + 1); res = 1;
				}
			}
		}
	}
	if(res == 1) {
		DBG_P("ospath='%s'", buf);
	}
	else {
		buf[0] = 0;
	}
	return res;
}

static const char *new_cwbtext(CTX ctx, knh_cwb_t *cwb, size_t *lenref)
{
	const char *p = knh_cwb_tochar(ctx, cwb);
	size_t len = knh_strlen(p) + 1;
	char *newtext = KNH_MALLOC(ctx, len);
	knh_memcpy(newtext, p, len);
	lenref[0] = len;
	return (const char*)newtext;
}

KNHAPI2(knh_Path_t*) new_Path(CTX ctx, knh_String_t *path)
{
	knh_Path_t *pth = new_(Path);
	KNH_SETv(ctx, pth->urn, path);
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, S_tobytes(path));
	if(knh_strcmp(S_tochar(path), knh_cwb_tochar(ctx, cwb)) == 0) {
		pth->ospath = S_tochar(path);
		pth->asize = 0;
	}
	else {
		pth->ospath = new_cwbtext(ctx, cwb, &(pth->asize));
	}
	knh_cwb_close(cwb);
	return pth;
}

static void knh_buff_addScriptPath(CTX ctx, knh_Bytes_t *ba, size_t pos, knh_NameSpace_t *ns, knh_bytes_t path)
{
	knh_bytes_t bpath = knh_bytes_next(path, ':');
	knh_buff_addpath(ctx, ba, pos, 0, B(ns->path->ospath));
	if(!knh_buff_isdir(ctx, ba, pos)) {
		knh_buff_trim(ctx, ba, pos, '/');
	}
	knh_buff_addospath(ctx, ba, pos, 1, bpath);
}

knh_Path_t *new_ScriptPath(CTX ctx, knh_String_t *urn, knh_NameSpace_t *ns)
{
	knh_Path_t *pth = new_(Path);
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	KNH_SETv(ctx, pth->urn, urn);
	knh_bytes_t bpath = knh_bytes_next(S_tobytes(urn), ':');
	knh_buff_addScriptPath(ctx, cwb->ba, cwb->pos, ns, bpath);
	pth->ospath = new_cwbtext(ctx, cwb, &(pth->asize));
	knh_cwb_close(cwb);
	return pth;
}

/* ------------------------------------------------------------------------ */
/* K_DPI_STREAM */

static knh_bool_t NOFILE_exists(CTX ctx, knh_Path_t *path)
{
	return 0;
}
static knh_io_t NOFILE_open(CTX ctx, knh_Path_t *path, const char *mode)
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
	NOFILE_exists,
	NOFILE_open, NOFILE_open, NOFILE_read, NOFILE_write, NOFILE_close
};

static const knh_StreamDPI_t STREAM_BYTE = {
	K_DSPI_STREAM, "BYTE", K_OUTBUF_MAXSIZ,
	NOFILE_exists,
	NOFILE_open, NOFILE_open, NOFILE_read, BYTE_write, NOFILE_close
};
static knh_bool_t FILE_exists(CTX ctx, knh_Path_t *path)
{
	return knh_exists(ctx, path->ospath);
}
static knh_io_t FILE_open(CTX ctx, knh_Path_t *path, const char *mode)
{
	return (knh_io_t)fopen(path->ospath, mode);
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
	FILE_exists,
	FILE_open, FILE_open, FILE_read, FILE_write, FILE_close,
};
static knh_bool_t STDIO_exists(CTX ctx, knh_Path_t *path)
{
	return 1;
}
static const knh_StreamDPI_t STREAM_STDIO = {
	K_DSPI_STREAM, "stdio", K_OUTBUF_MAXSIZ,
	STDIO_exists,
	NOFILE_open, NOFILE_open, FILE_read, FILE_write, NOFILE_close,
};

KNHAPI2(knh_InputStream_t*) new_InputStreamDPI(CTX ctx, knh_io_t fio, const knh_StreamDPI_t *dpi, knh_Path_t *path)
{
	knh_InputStream_t* in = new_(InputStream);
	DP(in)->fio  = fio;
	if(fio == IO_NULL) {
		dpi = NULL;
		knh_Object_toNULL(ctx, in);
	}
	else {
		KNH_ASSERT(DP(in)->ba->bu.len == 0);
		knh_Bytes_expands(ctx, DP(in)->ba, K_STREAM_BUFSIZ);
	}
	in->dpi = (dpi == NULL) ? &STREAM_FILE : dpi;
	KNH_SETv(ctx, DP(in)->path, path);
	DP(in)->path->dpi = dpi;
	return in;
}

KNHAPI2(knh_OutputStream_t*) new_OutputStreamDPI(CTX ctx, knh_io_t fio, const knh_StreamDPI_t *dpi, knh_Path_t *path)
{
	knh_OutputStream_t* w = new_(OutputStream);
	DP(w)->fio = fio;
	if(fio == IO_NULL) {
		dpi = NULL;
		knh_Object_toNULL(ctx, w);
	}
	w->dpi = (dpi == NULL) ? &STREAM_FILE : dpi;
	KNH_SETv(ctx, DP(w)->path, path);
	DP(w)->path->dpi = dpi;
	return w;
}

knh_InputStream_t *new_InputStreamSTDIO(CTX ctx, FILE *fp, knh_String_t *enc)
{
	return new_InputStreamDPI(ctx, (knh_io_t)stdin, &STREAM_STDIO, new_Path(ctx, TS_DEVSTDIN));
}

knh_OutputStream_t *new_OutputStreamSTDIO(CTX ctx, FILE *fp, knh_String_t *enc)
{
	KNH_ASSERT(fp == stdout || fp == stderr);
	knh_OutputStream_t* o = new_OutputStreamDPI(ctx, (knh_io_t)fp, &STREAM_STDIO, new_Path(ctx, (fp == stdout) ? TS_DEVSTDOUT : TS_DEVSTDERR));
	OutputStream_setAutoFlush(o, 1);
	return o;
}

//knh_InputStream_t* knh_Bytes_openInputStream(CTX ctx, knh_Bytes_t *ba, size_t pos, knh_String_t *path)
//{
//	FILE *fp = fopen(knh_Bytes_ensureZero(ctx, ba)+pos, "r");
//	knh_InputStream_t *in = new_InputStreamDPI(ctx, (knh_io_t)fp, &STREAM_FILE);
//	KNH_SETv(ctx, DP(in)->urn, path);
//	return in;
//}
//
//knh_OutputStream_t* knh_Bytes_openOutputStream(CTX ctx, knh_Bytes_t *ba, size_t pos, knh_String_t *path)
//{
//	FILE *fp = fopen(knh_Bytes_ensureZero(ctx, ba)+pos, "a");
//	knh_OutputStream_t *out = new_OutputStreamDPI(ctx, (knh_io_t)fp, &STREAM_FILE);
//	KNH_SETv(ctx, DP(out)->urn, path);
//	return out;
//}


const knh_StreamDPI_t *knh_getDefaultStreamDPI(void)
{
	return &STREAM_NOFILE;
}

const knh_StreamDPI_t *knh_getByteStreamDPI(void)
{
	return &STREAM_BYTE;
}

KNHAPI2(knh_InputStream_t*) new_InputStreamNULL(CTX ctx, knh_Path_t *pth, const char *mode)
{
	knh_io_t fd = pth->dpi->fopenSPI(ctx, pth, mode);
	if(fd != IO_NULL) {
		return new_InputStreamDPI(ctx, fd, pth->dpi, pth);
	}
	return NULL;
}

knh_InputStream_t* new_BytesInputStream(CTX ctx, knh_Bytes_t *ba)
{
	knh_InputStream_t* in = new_(InputStream);
	DBG_ASSERT(ba != ctx->bufa);
	DP(in)->fio = IO_BUF;
	KNH_SETv(ctx, DP(in)->ba, ba);
	DP(in)->posend = ba->bu.len;
	return in;
}

knh_InputStream_t* new_StringInputStream(CTX ctx, knh_String_t *str)
{
	knh_InputStream_t* in = new_(InputStream);
	DBG_ASSERT(IS_String(str));
	DP(in)->fio = IO_BUF;
	KNH_SETv(ctx, DP(in)->str, str);
	DP(in)->pos   = 0;
	DP(in)->posend = S_size(str);
	return in;
}

void knh_InputStream_setpos(CTX ctx, knh_InputStream_t *in, size_t s, size_t e)
{
	DBG_ASSERT(e <= BA_size(DP(in)->ba));
	DBG_ASSERT(s <= e);
	DP(in)->pos   = s;
	DP(in)->posend = e;
	DP(in)->fio = IO_BUF;
	in->dpi = knh_getByteStreamDPI();
}

/* ------------------------------------------------------------------------ */

static int readbuf(CTX ctx, knh_InputStream_t *in, knh_Bytes_t *ba)
{
	if(IS_Bytes(ba)) {
		long ssize = in->dpi->freadSPI(ctx, DP(in)->fio, ba->bu.buf, ba->dim->capacity);
		if(ssize > 0) {
			DP(in)->stat_size += ssize;
			DP(in)->pos = 0;
			DP(in)->posend = ssize;
			return 1;
		}
	}
	knh_InputStream_close(ctx, in);
	return 0;
}

int knh_InputStream_getc(CTX ctx, knh_InputStream_t *in)
{
	knh_Bytes_t *ba = DP(in)->ba;
	if(!(DP(in)->pos < DP(in)->posend)) {
		if(DP(in)->fio == IO_NULL || readbuf(ctx, in, ba) == 0) {
			return EOF;
		}
	}
	int ch = ba->bu.ubuf[DP(in)->pos++];
	if(ch == '\n') {
		in->uline += 1;
	}
	return ch;
}

knh_String_t* knh_InputStream_readLine(CTX ctx, knh_InputStream_t *in)
{
	knh_Bytes_t *ba = DP(in)->ba;
	if(!(DP(in)->pos < DP(in)->posend)) {
		if(DP(in)->fio == IO_NULL || readbuf(ctx, in, ba) == 0) {
			return KNH_TNULL(String);
		}
	}
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	while(1) {
		if(!(DP(in)->pos < DP(in)->posend)) {
			if(DP(in)->fio == IO_NULL || readbuf(ctx, in, ba) == 0) {
				knh_InputStream_close(ctx, in);
				if(knh_cwb_size(cwb) == 0) {
					return KNH_TNULL(String);
				}
				goto L_TOSTRING;
			}
		}
		size_t i, pos = DP(in)->pos, posend = DP(in)->posend;
		knh_uchar_t *p = ba->bu.ubuf;
		for(i = pos; i < posend; i++) {
			int ch = p[i];
			if(ch == '\n') {
				DP(in)->pos = i + 1;
				knh_bytes_t buf = {{ba->bu.text + pos}, i - pos};
				knh_Bytes_write(ctx, cwb->ba, buf);
				goto L_TOSTRING;
			}
		}
	}
	L_TOSTRING:;
	if(in->decNULL == NULL) {
		return knh_cwb_newString(ctx, cwb);
	}
	else {
		return knh_cwb_newStringDECODE(ctx, cwb, in->decNULL);
	}
}

void knh_InputStream_close(CTX ctx, knh_InputStream_t *in)
{
	if(DP(in)->fio != IO_NULL) {
		in->dpi->fcloseSPI(ctx, DP(in)->fio);
		if(DP(in)->fio != IO_BUF) {
//			DBG_P("stream in=%s", S_tochar(DP(in)->urn));
			knh_Bytes_dispose(ctx, DP(in)->ba);
		}
		DP(in)->fio = IO_NULL;
		in->dpi = knh_getDefaultStreamDPI();
	}
}

int InputStream_isClosed(CTX ctx, knh_InputStream_t *in)
{
	return (DP(in)->fio == IO_NULL);
}

void InputStream_setCharset(CTX ctx, knh_InputStream_t *in, knh_StringDecoder_t *c)
{
	if(in->decNULL == NULL) {
		if(c != NULL) {
			KNH_INITv(in->decNULL, c);
		}
	}
	else {
		if(c != NULL) {
			KNH_SETv(ctx, in->decNULL, c);
		}
		else {
			KNH_FINALv(ctx, in->decNULL);
			in->decNULL = c;
		}
	}
}

/* ------------------------------------------------------------------------ */
/* [OutputStream] */

KNHAPI2(knh_OutputStream_t*) new_OutputStreamNULL(CTX ctx, knh_Path_t *pth, const char *mode)
{
	knh_io_t fd = pth->dpi->wopenSPI(ctx, pth, mode);
	if(fd != IO_NULL) {
		return new_OutputStreamDPI(ctx, fd, pth->dpi, pth);
	}
	return NULL;
}

KNHAPI2(knh_OutputStream_t*) new_BytesOutputStream(CTX ctx, knh_Bytes_t *ba)
{
	knh_OutputStream_t* w = new_(OutputStream);
	DP(w)->fio = IO_BUF;
	w->dpi = knh_getByteStreamDPI();
	KNH_SETv(ctx, DP(w)->ba, ba);
	return w;
}

/* ------------------------------------------------------------------------ */
/* [methods] */

KNHAPI2(void) knh_OutputStream_flush(CTX ctx, knh_OutputStream_t *w, int isNEWLINE)
{
	knh_Bytes_t *ba = DP(w)->ba;
	if(ba->bu.len > 0) {
		if(w->encNULL != NULL && OutputStream_hasUTF8(w)) {
			knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
			knh_StringEncoder_t *c = w->encNULL;
			KNH_ASSERT(ba != cwb->ba);
			c->dpi->enc(ctx, c->conv, BA_tobytes(ba), cwb->ba);
			ba = cwb->ba;
			if(w->dpi->fwriteSPI(ctx, DP(w)->fio, (ba)->bu.text, (ba)->bu.len) > 0) {
				knh_Bytes_clear(DP(w)->ba, 0);
			}
			knh_cwb_close(cwb);
			OutputStream_setUTF8(w, 0);
		}
		else if(w->dpi->fwriteSPI(ctx, DP(w)->fio, (ba)->bu.text, (ba)->bu.len) > 0) {
			knh_Bytes_clear(ba, 0);
		}
	}
}

KNHAPI2(void) knh_OutputStream_putc(CTX ctx, knh_OutputStream_t *w, int ch)
{
	knh_Bytes_t *ba = DP(w)->ba;
	knh_uchar_t ubuf[8] = {ch};
	knh_bytes_t t = {{(const char*)ubuf}, 1};
	knh_Bytes_write(ctx, ba, t);
	DP(w)->stat_size++;
}

KNHAPI2(void) knh_OutputStream_write(CTX ctx, knh_OutputStream_t *w, knh_bytes_t buf)
{
	knh_Bytes_t *ba = DP(w)->ba;
	knh_Bytes_write(ctx, ba, buf);
	if(ba->bu.len > w->dpi->wbufsiz) {
		knh_OutputStream_flush(ctx, w, 0);
	}
}

void knh_OutputStream_clear(CTX ctx, knh_OutputStream_t *w)
{
	knh_Bytes_clear(DP(w)->ba, 0);
}

void knh_OutputStream_close(CTX ctx, knh_OutputStream_t *w)
{
	if(DP(w)->fio != IO_NULL) {
		knh_OutputStream_flush(ctx, w, 1);
		w->dpi->fcloseSPI(ctx, DP(w)->fio);
		if(DP(w)->fio != IO_BUF) {
			knh_Bytes_dispose(ctx, DP(w)->ba);
		}
		DP(w)->fio = IO_NULL;
		w->dpi = knh_getDefaultStreamDPI();
	}
}

int OutputStream_isClosed(knh_OutputStream_t *w)
{
	return (DP(w)->fio == IO_NULL);
}

/* ------------------------------------------------------------------------ */

void OutputStream_setCharset(CTX ctx, knh_OutputStream_t *w, knh_StringEncoder_t *c)
{
	if(w->encNULL == NULL) {
		KNH_INITv(w->encNULL, c);
	}
	else {
		KNH_SETv(ctx, w->encNULL, c);
	}
}

/* ------------------------------------------------------------------------ */
/* [knh_write] */

KNHAPI2(void) knh_write_BOL(CTX ctx, knh_OutputStream_t *w)
{
	knh_intptr_t i, n = DP(w)->indent;
	if(!OutputStream_isBOL(w)) {
		knh_write_EOL(ctx, w);
	}
	for(i = 0; i < n; i++) {
		knh_Bytes_write(ctx, DP(w)->ba, S_tobytes(DP(w)->TAB));
	}
	OutputStream_setBOL(w, 0);
}

KNHAPI2(void) knh_write_EOL(CTX ctx, knh_OutputStream_t *w)
{
	knh_Bytes_write(ctx, DP(w)->ba, S_tobytes(DP(w)->NEWLINE));
	if(OutputStream_isAutoFlush(w)) {
		knh_OutputStream_flush(ctx, w, 1);
	}
	OutputStream_setBOL(w, 1);
}

KNHAPI2(void) knh_write_TAB(CTX ctx, knh_OutputStream_t *w)
{
	knh_Bytes_write(ctx, DP(w)->ba, S_tobytes(DP(w)->TAB));
}

//void knh_write_begin(CTX ctx, knh_OutputStream_t *w, int ch)
//{
//	if(ch != 0) {
//		knh_putc(ctx, w, ch);
//		knh_write_EOL(ctx, w);
//	}
//	DP(w)->indent++;
//}
//
//void knh_write_end(CTX ctx, knh_OutputStream_t *w, int ch)
//{
//	DP(w)->indent--;
//	if(ch != 0) {
//		knh_write_BOL(ctx, w);
//		knh_putc(ctx, w, ch);
//	}
//}

/* ------------------------------------------------------------------------ */
/* [datatype] */

void knh_write_bool(CTX ctx, knh_OutputStream_t *w, int b)
{
	knh_String_t *s = (b) ? TS_true : TS_false;
	knh_Bytes_write(ctx, DP(w)->ba, S_tobytes(s));
}

void knh_write_ptr(CTX ctx, knh_OutputStream_t *w, void *ptr)
{
	char buf[K_INT_FMTSIZ];
	knh_snprintf(buf, sizeof(buf), "%p", ptr);
	knh_Bytes_write(ctx, DP(w)->ba, B(buf));
}

void knh_write_dfmt(CTX ctx, knh_OutputStream_t *w, const char *fmt, knh_intptr_t n)
{
	char buf[K_INT_FMTSIZ];
	knh_snprintf(buf, sizeof(buf), fmt, n);
	knh_Bytes_write(ctx, DP(w)->ba, B(buf));
}

void knh_write_ifmt(CTX ctx, knh_OutputStream_t *w, const char *fmt, knh_int_t n)
{
	char buf[K_INT_FMTSIZ];
	knh_snprintf(buf, sizeof(buf), fmt, n);
	knh_Bytes_write(ctx, DP(w)->ba, B(buf));
}

void knh_write_ffmt(CTX ctx, knh_OutputStream_t *w, const char *fmt, knh_float_t n)
{
	char buf[K_FLOAT_FMTSIZ];
	knh_snprintf(buf, sizeof(buf), fmt, n);
	knh_Bytes_write(ctx, DP(w)->ba, B(buf));
}

void knh_write_flag(CTX ctx, knh_OutputStream_t *w, knh_flag_t flag)
{
	knh_uchar_t ubuf[8];
	knh_bytes_t t = {{(const char*)ubuf}, 1};
	knh_intptr_t i;
	knh_flag_t f = 1 << 15;
	for(i = 0; i < 16; i++) {
		if(i > 0 && i % 8 == 0) {
			ubuf[0] = ' ';
			knh_Bytes_write(ctx, DP(w)->ba, t);
		}
		ubuf[0] = ((f & flag) == f) ? '1' : '0';
		knh_Bytes_write(ctx, DP(w)->ba, t);
		f = f >> 1;
	}
}

KNHAPI2(void) knh_write_ascii(CTX ctx, knh_OutputStream_t *w, const char *text)
{
	knh_bytes_t t;
	t.text = text; t.len = knh_strlen(text);
	knh_Bytes_write(ctx, DP(w)->ba, t);
}

KNHAPI2(void) knh_write_utf8(CTX ctx, knh_OutputStream_t *w, knh_bytes_t t, int hasUTF8)
{
	if(hasUTF8 && w->encNULL != NULL && !OutputStream_hasUTF8(w)) {
		size_t i;
		for(i = 0; i < t.len; i++) {
			if(t.ubuf[i] > 127) {
				OutputStream_setUTF8(w, 1);
				break;
			}
		}
	}
	knh_Bytes_write(ctx, DP(w)->ba, t);
}

/* ------------------------------------------------------------------------ */

void knh_write_quote(CTX ctx, knh_OutputStream_t *w, int quote, knh_bytes_t t, int hasUTF8)
{
	knh_bytes_t sub = t;
	size_t i, s = 0;
	knh_putc(ctx, w, quote);
	for(i = 0; i < t.len; i++) {
		int ch = t.utext[i];
		if(ch == '\t' || ch == '\n' || ch == '\r' || ch == '\\' || ch == quote) {
			sub.utext = t.utext + s;
			sub.len = i - s;
			knh_write_utf8(ctx, w, sub, hasUTF8);
			s = i + 1;
			knh_putc(ctx, w, '\\');
			if(ch == '\t') {
				knh_putc(ctx, w, 't');
			}
			else if(ch == '\n') {
				knh_putc(ctx, w, 'n');
			}
			else if(ch == '\r') {
				knh_putc(ctx, w, 'r');
			}
			else {
				knh_putc(ctx, w, ch);
			}
		}
	}
	if (s < t.len) {
		sub.utext = t.utext + s;
		sub.len = t.len - s;
		knh_write_utf8(ctx, w, sub, hasUTF8);
	}
	knh_putc(ctx, w, quote);
}

void knh_write_cap(CTX ctx, knh_OutputStream_t *w, knh_bytes_t t, int hasUTF8)
{
	if(islower(t.utext[0])) {
		knh_putc(ctx, w, toupper(t.utext[0]));
		t.utext = t.utext+1; t.len = t.len -1;
	}
	knh_write_utf8(ctx, w, t, hasUTF8);
}

void knh_write_Object(CTX ctx, knh_OutputStream_t *w, Object *o, int level)
{
	if(level % 2 == 0) { // TYPED
		knh_write_ascii(ctx, w, CLASS__(O_cid(o)));
		knh_putc(ctx, w, ':');
	}
	if(Object_isNullObject(o)) {
		knh_write(ctx, w, STEXT("null"));
	}
	else {
		O_cTBL(o)->cdef->p(ctx, w, RAWPTR(o), level);
	}
	if(IS_FMTdump(level)) {
		knh_write_EOL(ctx, w);
	}
}

void knh_write_InObject(CTX ctx, knh_OutputStream_t *w, Object *o, int level)
{
	if(level % 2 == 0) { // TYPED
		knh_write_ascii(ctx, w, CLASS__(O_cid(o)));
		knh_putc(ctx, w, ':');
	}
	if(Object_isNullObject(o)) {
		knh_write_ascii(ctx, w, "null");
	}
	else {
//		if(checkRecursiveCalls(ctx, sfp)) {
//			knh_write_dots(ctx, w);
//			goto L_CLOSE;
//		}
		O_cTBL(o)->cdef->p(ctx, w, RAWPTR(o), level);
	}
}

/* ------------------------------------------------------------------------ */
/* [printf] */

static const char* knh_vprintf_parseindex(const char *p, int *index)
{
	const char *ptr = p+1;
	if(ptr[0] == '{' && isdigit(ptr[1]) && ptr[2] == '}') {
		*index = ptr[1] - '0';
		ptr += 3;
		return ptr;
	}
	return p;
}

#define VA_NOP                0
#define VA_DIGIT              1 /* intptr_t */
#define VA_LONG               2 /* knh_int_t */
#define VA_FLOAT              3
#define VA_CHAR               4
#define VA_POINTER            5
#define VA_OBJECT             6
#define VA_FIELDN             7
#define VA_CLASS              8
#define VA_TYPE               9
#define VA_METHODN            10
#define VA_BYTES              11

typedef struct {
	int atype;
	union {
		knh_intptr_t  dvalue;
		knh_uintptr_t uvalue;
		knh_int_t     ivalue;
		knh_float_t   fvalue;
		knh_float_t   evalue;
		void         *pvalue;
		char         *svalue;
		Object       *ovalue;
		knh_bytes_t   bvalue;
		knh_class_t     cid;
		knh_type_t      type;
		knh_fieldn_t    fn;
		knh_methodn_t   mn;
	};
} knh_valist_t;

/* ------------------------------------------------------------------------ */

void knh_vprintf(CTX ctx, knh_OutputStream_t *w, const char *fmt, va_list ap)
{
	knh_valist_t args[10];
	const char *c = fmt;
	int i, ch, bindex = 0, bindex_max = 10;
	for(i = 0; i < bindex_max; i++) args[i].atype = 0;
	while((ch = *c) != '\0') {
		c++;
		if(ch == '%') {
			int index;
			ch = *c;
			if(ch == '%') {
				c++;
				continue;
			}
			index = bindex++;
			c = knh_vprintf_parseindex(c, &index);
			//DBG_P("bindex=%d, index=%d", bindex, index);
			switch(ch) {
				case 'd': case 'u':
				args[index].atype = VA_DIGIT; break;
				case 'l': case 'i':
					args[index].atype = VA_LONG; break;
				case 'f': case 'e':
					args[index].atype = VA_FLOAT; break;
				case 's':
					args[index].atype = VA_CHAR; break;
				case 'p':
					args[index].atype = VA_POINTER; break;
				case 'L':
				case 'K': case 'k':
				case 'O': case 'o':
					args[index].atype = VA_OBJECT; break;
				case 'N': case 'F':
					args[index].atype = VA_FIELDN; break;
				case 'M':
					args[index].atype = VA_METHODN; break;
				case 'C':
					args[index].atype = VA_CLASS; break;
				case 'T':
					args[index].atype = VA_TYPE; break;
				case 'B':
					args[index].atype = VA_BYTES; break;
				// TODO
				// we should care if "fmt" has "%%".
				// sometimes, next args is NULL.
				case '%':
					index--;
					c++;
				default:
					bindex--;
			}
			if(bindex == 10) {
				DBG_ASSERT(bindex < 10);
				break;
			}
		}
	}

	for(i = 0; i < 10; i++) {
		switch(args[i].atype) {
		case VA_DIGIT:
			args[i].dvalue = (knh_intptr_t)va_arg(ap, knh_intptr_t); break;
		case VA_LONG:
			args[i].ivalue = (knh_int_t)va_arg(ap, knh_int_t); break;
		case VA_FLOAT:
#if defined(K_USING_NOFLOAT)
			args[i].fvalue = (knh_float_t)va_arg(ap, knh_float_t);
#else
			args[i].fvalue = (knh_float_t)va_arg(ap, double);
#endif
			break;
		case VA_CHAR:
			args[i].svalue = (char*)va_arg(ap, char*); break;
		case VA_POINTER:
			args[i].pvalue = (void*)va_arg(ap, void*); break;
		case VA_OBJECT:
			args[i].ovalue = (Object*)va_arg(ap, Object*); break;
		case VA_FIELDN:
			args[i].fn = (knh_fieldn_t)va_arg(ap, int/*knh_fieldn_t*/); break;
		case VA_METHODN:
			args[i].mn = (knh_methodn_t)va_arg(ap, int/*knh_methodn_t*/); break;
		case VA_CLASS:
			args[i].cid = (knh_class_t)va_arg(ap, int/*knh_class_t*/); break;
		case VA_TYPE:
			args[i].type = (knh_type_t)va_arg(ap, int/*knh_type_t*/); break;
		case VA_BYTES:
			args[i].bvalue = (knh_bytes_t)va_arg(ap, knh_bytes_t); break;
		default:
			bindex_max = i;
			goto L_FORMAT;
		}
	}

	L_FORMAT: {
		knh_bytes_t b;
		c = fmt;
		bindex = 0;
		b.text = c;
		b.len = 0;
		while((ch = *c) != '\0') {
			c++;
			if(ch == '\\') {
				if(b.len > 0) {
					knh_write_utf8(ctx, w, b, 1);
				}
				ch = *c;
				switch(ch) {
					case '\0' : return ;
					case 'n': knh_write_EOL(ctx, w); break;
					case 't': knh_write_TAB(ctx, w); break;
					default:
						knh_putc(ctx, w, '\\');
						knh_putc(ctx, w, ch);
				}
				b.text = c;
				b.len = 0;
			}
			else if(ch == '%') {
				if(b.len > 0) {
				  knh_write_utf8(ctx, w, b, 1);
				}
				ch = *c;
				if(ch == '%') {
					knh_putc(ctx, w, '%');
					c++;
					b.text = c;
					b.len = 0;
					continue;
				}
				int index = bindex++;
				c = knh_vprintf_parseindex(++c, &index);

				switch(ch) {
					case '\0' : return ;
					case 'd':
						DBG_ASSERT(args[index].atype == VA_DIGIT);
						knh_write_dfmt(ctx, w, K_INTPTR_FMT, args[index].dvalue);
						break;
					case 'u':
						DBG_ASSERT(args[index].atype == VA_DIGIT);
						knh_write_dfmt(ctx, w, K_INTPTR_UFMT, args[index].uvalue);
						break;
					case 'l': case 'i' :
						DBG_ASSERT(args[index].atype == VA_LONG);
						knh_write_ifmt(ctx, w, K_INT_FMT, args[index].ivalue);
						break;
					case 'f':
						DBG_ASSERT(args[index].atype == VA_FLOAT);
						knh_write_ffmt(ctx, w, K_FLOAT_FMT, args[index].fvalue);
						break;
					case 'e':
						DBG_ASSERT(args[index].atype == VA_FLOAT);
						knh_write_ffmt(ctx, w, K_FLOAT_FMTE, args[index].fvalue);
						break;
					case 's':
						DBG_ASSERT(args[index].atype == VA_CHAR);
						knh_write(ctx, w, B(args[index].svalue));
						break;
					case 'p':
						DBG_ASSERT(args[index].atype == VA_POINTER);
						knh_write_ptr(ctx, w, args[index].pvalue);
						break;
					case 'L':
					case 'O': case 'o':
						DBG_ASSERT(args[index].atype == VA_OBJECT);
						knh_write_Object(ctx, w, args[index].ovalue, FMT_s);
						break;
					case 'K': case 'k':
						DBG_ASSERT(args[index].atype == VA_OBJECT);
						knh_write_Object(ctx, w, args[index].ovalue, FMT_line);
						break;
					case 'N': case 'F':
						DBG_ASSERT(args[index].atype == VA_FIELDN);
						knh_write_ascii(ctx, w, FN__(args[index].fn));
						break;
					case 'M':
						DBG_ASSERT(args[index].atype == VA_METHODN);
						knh_write_mn(ctx, w, args[index].mn);
						break;
					case 'C':
						DBG_ASSERT(args[index].atype == VA_CLASS);
						knh_write_cid(ctx, w, args[index].cid);
						break;
					case 'T':
						DBG_ASSERT(args[index].atype == VA_TYPE);
						knh_write_type(ctx, w, args[index].type);
						break;
					case 'B':
						DBG_ASSERT(args[index].atype == VA_BYTES);
						knh_write(ctx,w, args[index].bvalue);
						break;
					case '%':
						index--;
						bindex--;
					default:
						//knh_putc(ctx, w, '%');
						knh_putc(ctx, w, ch);
				}
				b.text = c;
				b.len = 0;
				if(!(bindex <= bindex_max)) {
					DBG_ASSERT(bindex <= bindex_max);
					break;
				}
			}
			else {
				b.len = b.len+1;
			}
		}
		if(b.len > 0) {
		  knh_write_utf8(ctx, w, b, 1);
		}
	}
}

KNHAPI2(void) knh_printf(CTX ctx, knh_OutputStream_t *w, const char *fmt, ...)
{
	va_list ap;
	va_start(ap , fmt);
	knh_vprintf(ctx, w, fmt, ap);
	va_end(ap);
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
