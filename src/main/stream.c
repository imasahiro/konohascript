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

//#ifdef HAVE_LIBCURL
//#define K_USING_CURL 1
//#endif

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

static const char *new_cwbtext(CTX ctx, CWB_t *cwb, size_t *lenref)
{
	const char *p = CWB_totext(ctx, cwb);
	size_t len = knh_strlen(p) + 1;
	char *newtext = (char*) KNH_MALLOC(ctx, len);
	knh_memcpy(newtext, p, len);
	lenref[0] = len;
	return (const char*)newtext;
}

KNHAPI2(knh_Path_t*) new_Path(CTX ctx, knh_String_t *path)
{
	knh_Path_t *pth = new_(Path);
	KNH_SETv(ctx, pth->urn, path);
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, S_tobytes(path));
	if(knh_strcmp(S_totext(path), CWB_totext(ctx, cwb)) == 0) {
		pth->ospath = S_totext(path);
		pth->asize = 0;
	}
	else {
		pth->ospath = new_cwbtext(ctx, cwb, &(pth->asize));
	}
	CWB_close(cwb);
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
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	KNH_SETv(ctx, pth->urn, urn);
	knh_bytes_t bpath = knh_bytes_next(S_tobytes(urn), ':');
	knh_buff_addScriptPath(ctx, cwb->ba, cwb->pos, ns, bpath);
	pth->ospath = new_cwbtext(ctx, cwb, &(pth->asize));
	CWB_close(cwb);
	return pth;
}

#ifdef K_USING_POSIX_
#include <unistd.h>
#include <dirent.h>
#endif

knh_Array_t *knh_PathDir_toArray(CTX ctx, knh_Path_t *path)
{
	knh_Array_t *a = new_ArrayG(ctx, CLASS_StringARRAY, 0);
#ifdef K_USING_POSIX_
	DIR *dirptr = opendir(path->ospath);
	if(dirptr != NULL) {
		struct dirent *dp;
		while((dp = readdir(dirptr))!= NULL) {
			const char *d = dp->d_name;
			if(d[0] == '.' && (d[1] == 0 || (d[2] == 0 && d[1] == '.'))) continue;
			knh_Array_add(ctx, a, new_String(ctx, d));
		}
		closedir(dirptr);
	}
#endif
	return a;
}

/* ------------------------------------------------------------------------ */
/* K_DPI_STREAM */

static size_t io2_writeNOP(CTX ctx, knh_io2_t *io2, const char *buf, size_t bufsiz)
{
	return 0;
}
static knh_bool_t io2_readNOP(CTX ctx, knh_io2_t *io2)
{
	return 0;
}
static void io2_closeNOP(CTX ctx, knh_io2_t *io2)
{
}

static knh_bool_t io2_readFILE(CTX ctx, knh_io2_t *io2)
{
	if(io2->bufsiz == 0) {
		io2->bufsiz = K_PAGESIZE;
		io2->buffer = KNH_MALLOC(ctx, io2->bufsiz);
	}
	size_t size = fread(io2->buffer, 1, io2->bufsiz, io2->fp);
	if(size == 0) {
		int tf = 1;
		if(ferror(io2->fp)) {
			knh_ldata_t ldata[] = {LOG_p("fp", io2->fp), LOG_s("path", io2->DBG_NAME), LOG_END};
			KNH_NTRACE(ctx, "fread", K_PERROR, ldata);
			tf = 0;
		}
		io2->_close(ctx, io2);
		return 0;
	}
	else {
		io2->top = 0;
		io2->tail = size;
		return 1;
	}
}

static size_t io2_writeFILE(CTX ctx, knh_io2_t *io2, const char *buf, size_t bufsiz)
{
	fflush(io2->fp);
	ssize_t size = fwrite(buf, 1, bufsiz, io2->fp);
	if(size == 0) {
		if(ferror(io2->fp)) {
			knh_ldata_t ldata[] = {LOG_i("fp", io2->fp), LOG_s("path", io2->DBG_NAME), LOG_END};
			KNH_NTRACE(ctx, "fwrite", K_PERROR, ldata);
		}
		io2->_close(ctx, io2);
		return 0;
	}
	fflush(io2->fp);
	return size;
}

static void io2_closeFILE(CTX ctx, knh_io2_t *io2)
{
	DBG_ASSERT(io2->isRunning == 1);
	fclose(io2->fp);
	io2->isRunning = 0;
}

knh_io2_t* new_FILE(CTX ctx, FILE *fp, size_t bufsiz)
{
	knh_io2_t *io2 = KNH_MALLOC(ctx, sizeof(knh_io2_t));
	io2->fp  = fp;
	io2->isRunning = 1;
	io2->bufsiz = bufsiz;
	if(bufsiz > 0) {
		io2->buffer = KNH_MALLOC(ctx, bufsiz);
	}
	io2->top  = 0;
	io2->tail = 0;
	io2->_close         = io2_closeFILE;
	io2->_blockread     = io2_readFILE;
	io2->_unblockread   = io2_readFILE;
	io2->_read          = io2_readFILE;
	io2->_blockwrite    = io2_writeFILE;
	io2->_unblockwrite  = io2_writeFILE;
	io2->_write         = io2_writeFILE;
	return io2;
}

static knh_bool_t io2_blockread(CTX ctx, knh_io2_t *io2)
{
	if(io2->bufsiz == 0) {
		io2->bufsiz = K_PAGESIZE;
		io2->buffer = KNH_MALLOC(ctx, io2->bufsiz);
	}
	int fd = io2->fd;
	ssize_t size = read(fd, io2->buffer, io2->bufsiz);
	if(size == -1) {
		knh_ldata_t ldata[] = {LOG_i("fd", fd), LOG_s("path", io2->DBG_NAME), LOG_END};
		KNH_NTRACE(ctx, "read", K_PERROR, ldata);
		io2->_close(ctx, io2);
		return 0;
	}
	else {
		io2->top = 0;
		io2->tail = size;
		if(size == 0) {
			io2->_close(ctx, io2);
		}
		return 1;
	}
}

static knh_bool_t io2_unblockread(CTX ctx, knh_io2_t *io2)
{
	int fd = io2->fd;
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(fd, &fds);
	int rc = select(fd + 1, &fds, NULL, NULL, NULL);
	if(rc != -1) {
		if(FD_ISSET((int)fd,&fds)) {
			return io2->_blockread(ctx, io2);
		}
		knh_bzero(io2->buffer, io2->bufsiz);
		io2->top  = 0;
		io2->tail = 0;
		return 1;
	}
	{
		knh_ldata_t ldata[] = {LOG_i("fd", fd), LOG_s("path", io2->DBG_NAME), LOG_END};
		KNH_NTRACE(ctx, "select", K_PERROR, ldata);
	}
	return 0;
}

static size_t io2_blockwrite(CTX ctx, knh_io2_t *io2, const char *buf, size_t bufsiz)
{
	int fd = io2->fd;
	ssize_t size = write(fd, buf, bufsiz);
	if(size == -1) {
		knh_ldata_t ldata[] = {LOG_i("fd", fd), LOG_s("path", io2->DBG_NAME), LOG_END};
		KNH_NTRACE(ctx, "write", K_PERROR, ldata);
		io2->_close(ctx, io2);
	}
	return 0;
}

static size_t io2_unblockwrite(CTX ctx, knh_io2_t *io2, const char *buf, size_t size)
{
	int fd = io2->fd;
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(fd, &fds);
	int rc = select(fd + 1, NULL, &fds, NULL, NULL);
	if(rc != -1) {
		if(FD_ISSET((int)fd,&fds)) {
			return io2->_blockwrite(ctx, io2, buf, size);
		}
		return 0;
	}
	{
		knh_ldata_t ldata[] = {LOG_i("fd", fd), LOG_s("path", io2->DBG_NAME), LOG_END};
		KNH_NTRACE(ctx, "select", K_PERROR, ldata);
	}
	return 0;
}

static void io2_closeFD(CTX ctx, knh_io2_t *io2)
{
	DBG_ASSERT(io2->isRunning == 1);
	close(io2->fd);
	io2->isRunning = 0;
}

knh_io2_t* new_io2(CTX ctx, int fd, size_t bufsiz)
{
	knh_io2_t *io2 = KNH_MALLOC(ctx, sizeof(knh_io2_t));
	io2->handler  = NULL;
	io2->handler2 = NULL;
	io2->fd = fd;
	io2->isRunning = 1;
	io2->bufsiz = bufsiz;
	if(bufsiz > 0) {
		io2->buffer = KNH_MALLOC(ctx, bufsiz);
	}
	io2->top  = 0;
	io2->tail = 0;
	io2->_close         = io2_closeFD;
	io2->_blockread     = io2_blockread;
	io2->_unblockread   = io2_unblockread;
	io2->_read          = io2_blockread;
	io2->_blockwrite    = io2_blockwrite;
	io2->_unblockwrite  = io2_unblockwrite;
	io2->_write         = io2_blockwrite;
	return io2;
}

knh_io2_t* new_io2ReadBuffer(CTX ctx, const char *buf, size_t bufsiz)
{
	knh_io2_t *io2 = KNH_MALLOC(ctx, sizeof(knh_io2_t));
	io2->handler  = NULL;
	io2->handler2 = NULL;
	io2->fd = -1;
	io2->isRunning = 0;
	io2->buffer = KNH_MALLOC(ctx, bufsiz);
	knh_memcpy(io2->buffer, buf, bufsiz);
	io2->bufsiz = bufsiz;
	io2->top  = 0;
	io2->tail = bufsiz;
	io2->_close         = io2_close;
	io2->_blockread     = io2_readNOP;
	io2->_unblockread   = io2_readNOP;
	io2->_read          = io2_readNOP;
	io2->_blockwrite    = io2_writeNOP;
	io2->_unblockwrite  = io2_writeNOP;
	io2->_write         = io2_writeNOP;
	return io2;
}

static size_t io2_writeBytes(CTX ctx, knh_io2_t *io2, const char *buf, size_t bufsiz)
{
	knh_Bytes_write2(ctx, io2->baNC, buf, bufsiz);
	return bufsiz;
}

static void io2_closeBytes(CTX ctx, knh_io2_t *io2)
{
	io2->_blockwrite    = io2_writeNOP;
	io2->_unblockwrite  = io2_writeNOP;
	io2->_write         = io2_writeNOP;
	io2->isRunning = 0;
}

knh_io2_t* new_io2WriteBuffer(CTX ctx, knh_Bytes_t *ba)
{
	knh_io2_t *io2 = KNH_MALLOC(ctx, sizeof(knh_io2_t));
	io2->baNC  = ba;
	io2->isRunning = 1;
	io2->buffer = NULL;
	io2->bufsiz = 0;
	io2->top  = 0;
	io2->tail = 0;
	io2->_close         = io2_closeBytes;
	io2->_blockread     = io2_readNOP;
	io2->_unblockread   = io2_readNOP;
	io2->_read          = io2_readNOP;
	io2->_blockwrite    = io2_writeBytes;
	io2->_unblockwrite  = io2_writeBytes;
	io2->_write         = io2_writeBytes;
	return io2;
}

knh_io2_t *io2_null(void)
{
	static knh_io2_t io2_dummy = {
			{0}, NULL
	};
	io2_dummy._close = io2_closeNOP;
	io2_dummy._read  = io2_readNOP;
	io2_dummy._write = io2_writeNOP;
	return &io2_dummy;
}

void io2_free(CTX ctx, knh_io2_t *io2)
{
	if(io2->isRunning == 1) {
		io2->_close(ctx, io2);
	}
	if(io2->bufsiz > 0) {
		KNH_FREE(ctx, io2->buffer, io2->bufsiz);
		io2->bufsiz = 0;
		io2->buffer = NULL;
		io2->top = 0;
		io2->tail = 0;
	}
	if(io2 != io2_null()) {
		KNH_FREE(ctx, io2, sizeof(knh_io2_t));
	}
}

void io2_close(CTX ctx, knh_io2_t *io2)
{
	if(io2->isRunning == 1) {
		io2->_close(ctx, io2);
		io2->top  = 0;
		io2->tail = 0;
	}
}

knh_bool_t io2_isClosed(CTX ctx, knh_io2_t *io2)
{
	return (io2->isRunning == 0 && io2->top >= io2->tail);
}

int io2_getc(CTX ctx, knh_io2_t *io2)
{
	int ch = EOF;
	if(io2->top < io2->tail) {
		ch = io2->buffer[io2->top];
		io2->top += 1;
	}
	else if(io2->isRunning) {
		io2->_read(ctx, io2);
		if(io2->top < io2->tail) {
			ch = io2->buffer[io2->top];
			io2->top += 1;
		}
	}
	return ch;
}

size_t io2_read(CTX ctx, knh_io2_t *io2, char *buf, size_t bufsiz)
{
	size_t rsize = 0;
	while(bufsiz > 0) {
		long remsiz = io2->tail - io2->top;
		if(remsiz > 0) {
			if(remsiz <= bufsiz) {
				knh_memcpy(buf, io2->buffer + io2->top, bufsiz);
				io2->top += bufsiz;
				rsize += bufsiz;
				return rsize;
			}
			else {
				knh_memcpy(buf, io2->buffer + io2->top, remsiz);
				buf    += remsiz;
				rsize  += remsiz;
				bufsiz -= remsiz;
			}
		}
		if(!io2->isRunning) break;
		io2->_read(ctx, io2);
	}
	return rsize;
}

static knh_String_t *CWB_newLine(CTX ctx, CWB_t *cwb, knh_StringDecoder_t *dec)
{
	if(CWB_size(cwb) > 0) {
		if(cwb->ba->bu.buf[cwb->ba->bu.len - 1] == '\r') {
			cwb->ba->bu.buf[cwb->ba->bu.len - 1] = 0;
			cwb->ba->bu.len =- 1;
			if(CWB_size(cwb) == 0) return TS_EMPTY;
		}
		if(dec == NULL) {
			return CWB_newString(ctx, cwb, K_SPOLICY_POOLNEVER);
		}
		else {
			return CWB_newStringDECODE(ctx, cwb, dec);
		}
	}
	return TS_EMPTY;
}

knh_String_t* io2_readLine(CTX ctx, knh_io2_t *io2, knh_StringDecoder_t *dec)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	while(io2->isRunning) {
		size_t i, start, hasUTF8 = 0;
		if(!(io2->top < io2->tail)) {
			io2->_read(ctx, io2);
		}
		start = io2->top;
		for(i = io2->top; i < io2->tail; i++) {
			int ch = ((unsigned char*)io2->buffer)[i];
			if(ch == '\n') {
				knh_Bytes_write2(ctx, cwb->ba, (const char*)io2->buffer + start, i - start);
				io2->top = i + 1;
				return CWB_newLine(ctx, cwb, hasUTF8 ? dec : NULL);
			}
			if(ch > 127) hasUTF8 = 1;
		}
	}
	if(io2->top < io2->tail) {
		knh_Bytes_write2(ctx, cwb->ba, (const char*)io2->buffer + io2->top, io2->tail - io2->top);
		io2->top  = 0;
		io2->tail = 0;
		return CWB_newLine(ctx, cwb, dec);
	}
	return KNH_TNULL(String);
}

void io2_readAll(CTX ctx, knh_io2_t *io2, knh_Bytes_t *ba)
{
	while(io2->isRunning == 1) {
		if(!(io2->top < io2->tail)) {
			io2->_read(ctx, io2);
		}
		if(io2->tail > io2->top) {
			knh_Bytes_write2(ctx, ba, (const char*)io2->buffer + io2->top, io2->tail - io2->top);
			io2->top  = 0;
			io2->tail = 0;
		}
	}
}

void io2_flush(CTX ctx, knh_io2_t *io2)
{
	if(io2->bufsiz > 0 && io2->tail > 0) {
		io2->_write(ctx, io2, io2->buffer, io2->tail);
		io2->tail = 0;
	}
}

size_t io2_write(CTX ctx, knh_io2_t *io2, const char *buf, size_t bufsiz)
{
	if(io2->bufsiz > 0) {
		if(io2->tail + bufsiz < io2->bufsiz) {
			knh_memcpy(io2->buffer + io2->tail, buf, bufsiz);
			io2->tail += bufsiz;
			return bufsiz;
		}
		io2->_write(ctx, io2, io2->buffer, io2->tail);
		io2->tail = 0;
		if(bufsiz < io2->bufsiz) {
			knh_memcpy(io2->buffer, buf, bufsiz);
			io2->tail += bufsiz;
			return bufsiz;
		}
	}
	return io2->_write(ctx, io2, buf, bufsiz);
}

size_t io2_writeMultiByteChar(CTX ctx, knh_io2_t *io2, const char *buf, size_t bufsiz, knh_StringEncoder_t *enc)
{
	KNH_TODO("enc");
	return io2->_write(ctx, io2, buf, bufsiz);
}

knh_bool_t NOFILE_exists(CTX ctx, knh_Path_t *path)
{
	return 0;
}
void NOFILE_ospath(CTX ctx, knh_Path_t *path, knh_NameSpace_t *ns)
{
	path->ospath ="";
	path->asize = 0;
}
knh_io2_t* NOFILE_openNULL(CTX ctx, knh_Path_t *path, const char *mode, knh_DictMap_t *conf)
{
	return NULL;
}

static const knh_PathDPI_t STREAM_NOFILE = {
	K_STREAM_NULL, "NOFILE", K_PAGESIZE,
	NOFILE_exists, NOFILE_ospath, NOFILE_openNULL,
};

static knh_bool_t FILE_exists(CTX ctx, knh_Path_t *path)
{
	return knh_exists(ctx, path->ospath);
}
static void FILE_ospath(CTX ctx, knh_Path_t *path, knh_NameSpace_t *ns)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_bytes_t urn = S_tobytes(path->urn);
	if(isalpha(urn.text[0]) && urn.text[1] == ':') { // C:\Windows
		knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, urn);
	}
	else {
		knh_buff_addospath(ctx, cwb->ba, cwb->pos, 0, knh_bytes_next(urn, ':'));
	}
	if(knh_strcmp(S_totext(path->urn), CWB_totext(ctx, cwb)) == 0) {
		path->ospath = S_totext(path->urn);
		path->asize = 0;
	}
	else {
		path->ospath = new_cwbtext(ctx, cwb, &(path->asize));
	}
	CWB_close(cwb);
}
static knh_io2_t* FILE_openNULL(CTX ctx, knh_Path_t *path, const char *mode, knh_DictMap_t *conf)
{
	FILE *fp = fopen(path->ospath, mode);
	if(fp != NULL) return new_FILE(ctx, fp, 4096);
	return NULL;
}

static const knh_PathDPI_t STREAM_FILE = {
	K_STREAM_FILE, "file", K_OUTBUF_MAXSIZ,
	FILE_exists, FILE_ospath, FILE_openNULL,
};

static void SCRIPT_ospath(CTX ctx, knh_Path_t *path, knh_NameSpace_t *ns)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_bytes_t bpath = knh_bytes_next(S_tobytes(path->urn), ':');
	knh_buff_addScriptPath(ctx, cwb->ba, cwb->pos, ns, bpath);
	path->ospath = new_cwbtext(ctx, cwb, &(path->asize));
	CWB_close(cwb);
}

static const knh_PathDPI_t STREAM_SCRIPT = {
	K_STREAM_FILE, "script", K_OUTBUF_MAXSIZ,
	FILE_exists, SCRIPT_ospath, FILE_openNULL,
};

/* ------------------------------------------------------------------------ */

#ifdef K_USING_CURL

#include<curl/curl.h>

static knh_bool_t CURL_exists(CTX ctx, knh_Path_t *path)
{
	knh_bool_t res = 0;
	CURL *curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, S_totext(path->urn));
	curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
	curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
	CURLcode code = curl_easy_perform(curl);
	res = (code == CURLE_OK);
	curl_easy_cleanup(curl);
	return res;
}

static void CURL_ospath(CTX ctx, knh_Path_t *path, knh_NameSpace_t *ns)
{
	path->ospath = NULL;
	path->asize = 0;
}

typedef struct {
	CURL *curl;
	CURLM *multi_handle;
	char *buffer;               /* buffer to store cached data*/
	long pos;
	long buffer_len;             /* currently allocated buffers length */
	long buffer_pos;             /* end of data in buffer*/
	int still_running;          /* Is background url fetch still in progress */
} curl_t;

static size_t write_callback(char *buffer, size_t size, size_t nitems, void *userp)
{
	curl_t *cp = (curl_t*)userp;
	char *newbuff;
	size *= nitems;
	long rembuff = cp->buffer_len - cp->buffer_pos; /* remaining space in buffer */
	if(size > rembuff) {
		newbuff = realloc(cp->buffer, cp->buffer_len + (size - rembuff));
		if(newbuff == NULL) {
			size = rembuff;
		}
		else {
			cp->buffer_len += size - rembuff;
			cp->buffer = newbuff;
		}
	}
	memcpy(&cp->buffer[cp->buffer_pos], buffer, size);
	cp->buffer_pos += size;
	return size;
}

static knh_io_t CURL_open(CTX ctx, knh_Path_t *path, const char *mode, knh_DictMap_t *conf)
{
	curl_t *cp = knh_malloc(ctx, sizeof(curl_t));
	memset(cp, 0, sizeof(curl_t));
	cp->curl = curl_easy_init();
	curl_easy_setopt(cp->curl, CURLOPT_URL, S_totext(path->urn));
	curl_easy_setopt(cp->curl, CURLOPT_WRITEDATA, cp);
	curl_easy_setopt(cp->curl, CURLOPT_VERBOSE, 0L);
	curl_easy_setopt(cp->curl, CURLOPT_WRITEFUNCTION, write_callback);
	cp->multi_handle = curl_multi_init();
	curl_multi_add_handle(cp->multi_handle, cp->curl);

	/* lets start the fetch */
	while(curl_multi_perform(cp->multi_handle, &cp->still_running) == CURLM_CALL_MULTI_PERFORM );

	if((cp->buffer_pos == 0) && (!cp->still_running)) {
		/* if still_running is 0 now, we should return NULL */
		/* make sure the easy handle is not in the multi handle anymore */
		curl_multi_remove_handle(cp->multi_handle, cp->curl);
		/* cleanup */
		curl_easy_cleanup(cp->curl);
		knh_free(ctx, cp, sizeof(curl_t));
		cp = NULL;
	}
	return (knh_io_t)cp;
}

static knh_bool_t CURL_info(CTX ctx, knh_io_t fd, knh_Object_t *o)
{
	//	if(cp->contenttype == NULL){
	//		char *type = NULL;
	//		curl_easy_getinfo(cp->curl, CURLINFO_CONTENT_TYPE, &type);
	//		if(type != NULL){
	//			char *charset = NULL;
	//			charset = strrchr(type, '=');
	//			if(charset != NULL){
	//				charset++;
	//				type = strtok(type, ";");
	//			}
	//			cp->charset = (const char*)charset;
	//			cp->contenttype = (const char*)type;
	//		}
	//	}
	return 0;
}

/* only attempt to fill buffer if transactions still running and buffer
 * doesnt exceed required size already
 */

static int fill_buffer(curl_t *cp, int want, int waittime2)
{
	if((!cp->still_running) || (cp->buffer_pos > want)) {
		return 0;
	}
	/* attempt to fill buffer */
	do {
		int maxfd = -1;
		fd_set fdread;
		fd_set fdwrite;
		fd_set fdexcep;
		struct timeval timeout;
		int rc;

		FD_ZERO(&fdread);
		FD_ZERO(&fdwrite);
		FD_ZERO(&fdexcep);

		/* set a suitable timeout to fail on */
		timeout.tv_sec = 60; /* 1 minute */
		timeout.tv_usec = 0;

		/* get file descriptors from the transfers */
		curl_multi_fdset(cp->multi_handle, &fdread, &fdwrite, &fdexcep, &maxfd);

		/* In a real-world program you OF COURSE check the return code of the
		 * function calls.  On success, the value of maxfd is guaranteed to be
		 * greater or equal than -1.  We call select(maxfd + 1, ...), specially
		 * in case of (maxfd == -1), we call select(0, ...), which is basically
		 * equal to sleep. */

		KNH_ASSERT(maxfd != -1);
		rc = select(maxfd+1, &fdread, &fdwrite, &fdexcep, &timeout);
		switch(rc) {
		case -1: /* select error */
		case 0: break;
		default:
			/* timeout or readable/writable sockets */
			/* note we *could* be more efficient and not wait for
			 * CURLM_CALL_MULTI_PERFORM to clear here and check it on re-entry
			 * but that gets messy */
			while(curl_multi_perform(cp->multi_handle, &cp->still_running) == CURLM_CALL_MULTI_PERFORM);
			break;
		}
	} while(cp->still_running && (cp->buffer_pos < want));
	return 1;
}

/* use to remove want bytes from the front of a files buffer */
static int use_buffer(curl_t *cp, int want)
{
	/* sort out buffer */
	if((cp->buffer_pos - want) <= 0) {
		/* ditch buffer - write will recreate */
		if(cp->buffer != NULL) free(cp->buffer);
		cp->buffer = NULL;
		cp->buffer_pos = 0;
		cp->buffer_len = 0;
	} else { /* move rest down make it available for later */
		memmove(cp->buffer, &cp->buffer[want], (cp->buffer_pos - want));
		cp->buffer_pos -= want;
	}
	return 0;
}

//static knh_intptr_t CURL_read(CTX ctx, knh_io_t fd, char *buf, size_t bufsiz)
//{
//	curl_t *cp = (curl_t*)fd;
//	fill_buffer(cp, bufsiz, 1);
//	if(!cp->buffer_pos) return 0;
//	/* ensure only available data is considered */
//	if(cp->buffer_pos < bufsiz) bufsiz = cp->buffer_pos;
//	/* xfer data to caller */
//	memcpy(buf, cp->buffer, bufsiz);
//	use_buffer(cp, bufsiz);
//	return bufsiz;
//}
//
//static knh_bool_t CURL_readline(CTX ctx, knh_io_t fd, knh_Bytes_t *ba)
//{
//	curl_t *cp = (curl_t*)fd;
//	int ret = 0;
//	while(1) {
//		int i, prev = 0;
//		fill_buffer(cp, K_PAGESIZE, 1);
//		if(!cp->buffer_pos) return ret;
//		for(i = 0; i < cp->buffer_pos; i++) {
//			int ch = cp->buffer[i];
//			if(ch == '\n') {
//				if(prev == '\r') {
//					knh_Bytes_write2(ctx, ba, cp->buffer, i-1); /* Windows */
//				}
//				else {
//					knh_Bytes_write2(ctx, ba, cp->buffer, i);   /* UNIX */
//				}
//				use_buffer(cp, i);
//				return 1;
//			}
//			if(prev == '\r' /*&& ch != '\n'*/) { /* OLD MAC */
//				knh_Bytes_write2(ctx, ba, cp->buffer, i-1);
//				use_buffer(cp, i);
//				return 1;
//			}
//			prev = ch;
//		}
//		ret = 1;
//		knh_Bytes_write2(ctx, ba, cp->buffer, cp->buffer_pos);
//		use_buffer(cp, cp->buffer_pos);
//	}
//}
//
//static void CURL_close(CTX ctx, knh_io_t fd)
//{
//	curl_t *cp = (curl_t*)fd;
//	curl_multi_remove_handle(cp->multi_handle, cp->curl);
//	curl_easy_cleanup(cp->curl);
//	if(cp->buffer) free(cp->buffer);
//	knh_free(ctx, cp, sizeof(curl_t));
//}
//
//static int CURL_feof(CTX ctx, knh_io_t fd)
//{
//	curl_t *cp = (curl_t*)fd;
//	int ret = 0;
//	if((cp->buffer_pos == 0) && (!cp->still_running)) {
//		ret = 1;
//	}
//	return ret;
//}
//
//static int CURL_getc(CTX ctx, knh_io_t fd)
//{
//	curl_t *file = (curl_t*)fd;
//	if(!file->buffer_pos || file->buffer_pos < file->buffer_len)
//		fill_buffer(file, K_PAGESIZE, 1);
//	return file->buffer[file->buffer_pos++];
//}
//
//static knh_intptr_t CURL_write(CTX ctx, knh_io_t fd, const char *buf, size_t bufsiz)
//{
//	return 0;
//}
//
//static void CURL_flush(CTX ctx, knh_io_t fd)
//{
//
//}

const knh_PathDPI_t STREAM_CURL = {
	K_STREAM_NET, "curl", K_PAGESIZE,
	CURL_exists,
	CURL_ospath,
	CURL_open,
//	CURL_read,
//	CURL_write,
//	CURL_close,
//	CURL_info,
//	CURL_getc,
//	CURL_readline,
//	CURL_feof,
//	CURL_flush,
};

#endif/*K_USING_CURL*/

const knh_PathDPI_t *knh_getDefaultPathStreamDPI(void)
{
	return &STREAM_FILE;
}

/* ------------------------------------------------------------------------ */

KNHAPI2(knh_InputStream_t*) new_InputStream(CTX ctx, knh_io2_t *io2, knh_Path_t *path)
{
	knh_InputStream_t* in = new_(InputStream);
	in->io2 = io2;
	if(path != NULL) {
		KNH_SETv(ctx, in->path, path);
		io2->DBG_NAME = S_totext(path->urn);
		if(io2 == NULL) {
			io2 = path->dpi->io2openNULL(ctx, path, "r", NULL);
			if(io2 == NULL) {
				io2 = io2_null();
				knh_Object_toNULL(ctx, in);
			}
			in->io2 = io2;
		}
	}
	return in;
}

knh_InputStream_t* new_BytesInputStream(CTX ctx, const char *buf, size_t bufsiz)
{
	return new_InputStream(ctx, new_io2ReadBuffer(ctx, buf, bufsiz), NULL);
}

KNHAPI2(knh_OutputStream_t*) new_OutputStream(CTX ctx,  knh_io2_t *io2, knh_Path_t *path)
{
	knh_OutputStream_t* w = new_(OutputStream);
	w->io2 = io2;
	if(path != NULL) {
		KNH_SETv(ctx, w->path, path);
		io2->DBG_NAME = S_totext(path->urn);
		if(io2 == NULL) {
			io2 = path->dpi->io2openNULL(ctx, path, "a", NULL);
			if(io2 == NULL) {
				io2 = io2_null();
				knh_Object_toNULL(ctx, w);
			}
			w->io2 = io2;
		}
	}
	return w;
}

void knh_InputStream_setCharset(CTX ctx, knh_InputStream_t *in, knh_StringDecoder_t *c)
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

void knh_OutputStream_setCharset(CTX ctx, knh_OutputStream_t *w, knh_StringEncoder_t *c)
{
	if(w->encNULL == NULL) {
		KNH_INITv(w->encNULL, c);
	}
	else {
		KNH_SETv(ctx, w->encNULL, c);
	}
}

KNHAPI2(knh_OutputStream_t*) new_BytesOutputStream(CTX ctx, knh_Bytes_t *ba)
{
	knh_OutputStream_t *w = new_OutputStream(ctx, new_io2WriteBuffer(ctx, ba), NULL);
	KNH_INITv(w->bufferNULL, ba);
	return w;
}

KNHAPI2(void) knh_OutputStream_flush(CTX ctx, knh_OutputStream_t *w)
{
	io2_flush(ctx, w->io2);
}

KNHAPI2(void) knh_OutputStream_putc(CTX ctx, knh_OutputStream_t *w, int ch)
{
	char buf[8] = {ch};
	io2_write(ctx, w->io2, buf, 1);
}

KNHAPI2(void) knh_OutputStream_write(CTX ctx, knh_OutputStream_t *w, knh_bytes_t buf)
{
	io2_write(ctx, w->io2, buf.text, buf.len);
}

KNHAPI2(void) knh_OutputStream_p(CTX ctx, knh_OutputStream_t *w, knh_bytes_t buf)
{
	if(w->encNULL != NULL) {
		size_t i;
		for(i = 0; i < buf.len; i++) {
			int ch = buf.ubuf[i];
			if(ch > 127) {
				io2_writeMultiByteChar(ctx, w->io2, buf.text, buf.len, w->encNULL);
				return;
			}
		}
	}
	io2_write(ctx, w->io2, buf.text, buf.len);
}

/* ------------------------------------------------------------------------ */
/* [knh_write] */

KNHAPI2(void) knh_write_EOL(CTX ctx, knh_OutputStream_t *w)
{
	io2_write(ctx, w->io2, K_OSLINEFEED, sizeof(K_OSLINEFEED));
	if(OutputStream_isAutoFlush(w)) {
		io2_flush(ctx, w->io2);
	}
	//OutputStream_setBOL(w, 1);
}

KNHAPI2(void) knh_write_TAB(CTX ctx, knh_OutputStream_t *w)
{
	io2_write(ctx, w->io2, "\t", 1);
}

/* ------------------------------------------------------------------------ */
/* [datatype] */

void knh_write_bool(CTX ctx, knh_OutputStream_t *w, int b)
{
	knh_bytes_t t = (b) ? STEXT("true") : STEXT("false");
	io2_write(ctx, w->io2, t.text, t.len);
}

void knh_write_ptr(CTX ctx, knh_OutputStream_t *w, void *ptr)
{
	char buf[K_INT_FMTSIZ];
	knh_snprintf(buf, sizeof(buf), "%p", ptr);
	io2_write(ctx, w->io2, (const char*)buf, knh_strlen(buf));
}

void knh_write_dfmt(CTX ctx, knh_OutputStream_t *w, const char *fmt, knh_intptr_t n)
{
	char buf[K_INT_FMTSIZ];
	knh_snprintf(buf, sizeof(buf), fmt, n);
	io2_write(ctx, w->io2, (const char*)buf, knh_strlen(buf));
}

void knh_write_ifmt(CTX ctx, knh_OutputStream_t *w, const char *fmt, knh_int_t n)
{
	char buf[K_INT_FMTSIZ];
	knh_snprintf(buf, sizeof(buf), fmt, n);
	io2_write(ctx, w->io2, (const char*)buf, knh_strlen(buf));
}

void knh_write_ffmt(CTX ctx, knh_OutputStream_t *w, const char *fmt, knh_float_t n)
{
	char buf[K_FLOAT_FMTSIZ];
	knh_snprintf(buf, sizeof(buf), fmt, n);
	io2_write(ctx, w->io2, (const char*)buf, knh_strlen(buf));
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
			io2_write(ctx, w->io2, t.text, 1);
		}
		ubuf[0] = ((f & flag) == f) ? '1' : '0';
		io2_write(ctx, w->io2, t.text, 1);
		f = f >> 1;
	}
}

KNHAPI2(void) knh_write_ascii(CTX ctx, knh_OutputStream_t *w, const char *text)
{
	io2_write(ctx, w->io2, text, knh_strlen(text));
}

KNHAPI2(void) knh_write_utf8(CTX ctx, knh_OutputStream_t *w, knh_bytes_t t, int hasUTF8)
{
	if(hasUTF8 && w->encNULL != NULL) {
		io2_writeMultiByteChar(ctx, w->io2, t.text, t.len, w->encNULL);
	}
	else {
		io2_write(ctx, w->io2, t.text, t.len);
	}
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

static KMETHOD InputStream_getByte(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(io2_getc(ctx, (sfp[0].in)->io2));
}

// Bytes InputStream.read(Bytes buf, size_t size);

static KMETHOD InputStream_read(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Bytes_t *ba = sfp[1].ba;
	if(IS_NULL(ba)) {
		ba = new_Bytes(ctx, NULL, 4096);
		KNH_SETv(ctx, sfp[1].ba, ba);
		io2_readAll(ctx, (sfp[0].in)->io2, ba);
	}
	else {
		size_t len = Int_to2(size_t, sfp[3], ba->dim->capacity);
		if(!(len < ba->dim->capacity)) {
			THROW_OutOfRange(ctx, sfp, len, ba->dim->capacity);
		}
		len = io2_read(ctx, (sfp[0].in)->io2, ba->bu.buf, len);
		ba->bu.len = len;
	}
	RETURN_(ba);
}

static KMETHOD InputStream_eachLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_sfp_t *thissfp = sfp + 2 + K_CALLDELTA;
	//knh_Method_t *mtd = knh_Func_preset(ctx, sfp[1].fo, thissfp);
	while(1) {
		knh_String_t *line = io2_readLine(ctx, (sfp[0].in)->io2, (sfp[0].in)->decNULL);
		if(IS_NULL(line)) break;
		KNH_SETv(ctx, thissfp[1].o, line);
		knh_Func_invoke(ctx, sfp[1].fo, sfp+2, 1);
//		((knh_context_t*)ctx)->esp = thissfp + 2;
//		(mtd)->fcall_1(ctx, thissfp, K_CALLDELTA);
	}
	RETURNvoid_();
}

static KMETHOD InputStream_isClosed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(io2_isClosed(ctx, (sfp[0].in)->io2));
}

static KMETHOD InputStream_setCharset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_InputStream_setCharset(ctx, sfp[0].in, (knh_StringDecoder_t*)sfp[1].o);
	RETURN_(sfp[1].o);
}

static KMETHOD OutputStream_putByte(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_t *w = sfp[0].w;
	knh_putc(ctx, w, (int)(sfp[1].ivalue));
	RETURNvoid_();
}

static KMETHOD OutputStream_isClosed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(io2_isClosed(ctx, (sfp[0].in)->io2));
}

static KMETHOD OutputStream_setCharset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_setCharset(ctx, sfp[0].w, (knh_StringEncoder_t*)sfp[1].o);
	RETURN_(sfp[1].o);
}

static KMETHOD System_addHistory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	ctx->spi->add_history(S_totext(sfp[1].s));
	RETURNvoid_();
}

#define FuncData(X) {#X , X}

static knh_FuncData_t FuncData[] = {
	FuncData(InputStream_getByte),
	FuncData(InputStream_read),
	FuncData(InputStream_eachLine),
	FuncData(InputStream_isClosed),
	FuncData(InputStream_setCharset),
	FuncData(OutputStream_putByte),
	FuncData(OutputStream_isClosed),
	FuncData(OutputStream_setCharset),
	FuncData(System_addHistory),
	{NULL, NULL},
};

void knh_initStreamFuncData(CTX ctx, const knh_LoaderAPI_t *kapi)
{
	kapi->addStreamDPI(ctx, "file", &STREAM_FILE);
	knh_NameSpace_setLinkClass(ctx, ctx->share->rootns, STEXT("file"), ClassTBL(CLASS_Path));
	kapi->addStreamDPI(ctx, "script", &STREAM_SCRIPT);
	knh_NameSpace_setLinkClass(ctx, ctx->share->rootns, STEXT("script"), ClassTBL(CLASS_Path));
#ifdef K_USING_CURL
	kapi->addStreamDPI(ctx, "http", &STREAM_CURL);
	knh_NameSpace_setLinkClass(ctx, ctx->share->rootns, STEXT("http"), ClassTBL(CLASS_Path));
#endif
	kapi->loadFuncData(ctx, FuncData);
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
