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

#define USE_STEXT 1
#define USE_B     1
//#define USE_bytes_startsWith  1

#define USE_cwb_open      1
#define USE_cwb_size      1
#define USE_cwb_tobytes   1

#include"commons.h"

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* [InputStream] */

KNHAPI2(knh_InputStream_t*) new_InputStreamDSPI(CTX ctx, knh_io_t fd, const knh_StreamDSPI_t *dspi)
{
	knh_InputStream_t* in = new_(InputStream);
	DP(in)->fd = fd;
	SP(in)->dspi = dspi;
	DP(in)->bufsiz = dspi->bufsiz;
	if(DP(in)->bufsiz > 0) {
		KNH_SETv(ctx, DP(in)->ba, new_Bytes(ctx, DP(in)->bufsiz));
		DP(in)->buf = (char*)(DP(in)->ba)->bu.ubuf;
	}
	else {
		InputStream_setFILE(in, 1);
	}
	DP(in)->bufpos = 0;
	DP(in)->bufend = 0;  /* empty */
	return in;
}

knh_InputStream_t* new_BytesInputStream(CTX ctx, knh_Bytes_t *ba)
{
	knh_InputStream_t* in = new_(InputStream);
	DBG_ASSERT(ba != ctx->bufa);
	DP(in)->fd = IO_NULL;
	KNH_SETv(ctx, DP(in)->ba, ba);
	DP(in)->buf = (char*)(ba)->bu.ubuf;
	DP(in)->bufsiz = BA_size(ba);
	DP(in)->bufpos   = 0;
	DP(in)->bufend   = BA_size(ba);
	return in;
}

void BytesInputStream_setpos(CTX ctx, knh_InputStream_t *in, size_t s, size_t e)
{
	knh_Bytes_t *ba = DP(in)->ba;
	DBG_ASSERT(DP(in)->fd == IO_NULL);
	DP(in)->buf = (char*)(ba)->bu.ubuf;
	DP(in)->bufsiz = (ba)->bu.len;
	DBG_ASSERT(e <= BA_size(ba));
	DBG_ASSERT(s <= e);
	DP(in)->bufpos   = s;
	DP(in)->bufend   = e;
}

knh_InputStream_t* new_StringInputStream(CTX ctx, knh_String_t *str, size_t s, size_t e)
{
	knh_InputStream_t* o = new_(InputStream);
	DP(o)->fd = IO_NULL;
	DBG_ASSERT(IS_String(str));
	KNH_SETv(ctx, DP(o)->str, str);
	DP(o)->buf = (char*)S_tochar(str);
	DP(o)->bufsiz = S_size(str);
	DBG_ASSERT(e <= S_size(str));
	DBG_ASSERT(s <= e);
	DP(o)->bufpos   = s;
	DP(o)->bufend   = e;
	return o;
}

/* ------------------------------------------------------------------------ */

int knh_InputStream_getc(CTX ctx, knh_InputStream_t *in)
{
	int ch;
	if(InputStream_isFILE(in)) {
		ch = SP(in)->dspi->fgetc(ctx, DP(in)->fd);
	}
	else {
		while(1) {
			if(DP(in)->bufpos < DP(in)->bufend) {
				ch = (knh_uchar_t)DP(in)->buf[DP(in)->bufpos];
				DP(in)->bufpos++;
				break;
			}
			DP(in)->bufpos = 0;
			DP(in)->bufend = SP(in)->dspi->fread(ctx, DP(in)->fd, DP(in)->buf, DP(in)->bufsiz);
			if(DP(in)->bufend == 0) return EOF;
		}
	}
	{ /* statstics */
		DP(in)->size++;
		if(ch == '\n') {
			if(DP(in)->prev != '\r') {
				SP(in)->uline += 1;
			}
		}
		else if(ch == '\r') {
			SP(in)->uline += 1;
		}
		else if(ch == EOF) {
			knh_InputStream_close(ctx, in);
		}
	}
	return ch;
}

/* ------------------------------------------------------------------------ */

size_t knh_InputStream_read(CTX ctx, knh_InputStream_t *in, char *buf, size_t bufsiz)
{
	if(InputStream_isFILE(in)) {
		return SP(in)->dspi->fread(ctx, DP(in)->fd, buf, bufsiz);
	}
	else {
		size_t inbufsiz = (DP(in)->bufend - DP(in)->bufpos);
		if(bufsiz <= inbufsiz) {
			knh_memcpy(buf, DP(in)->buf, bufsiz);
			DP(in)->bufpos += bufsiz;
			{
				DP(in)->size += bufsiz;
			}
			return bufsiz;
		}
		// XXX when both InputStream.read and InputStream.readLine method call,
		// it seams strange. so, move DP(o)->buf's pointer to bufpos.
		knh_memcpy(buf, DP(in)->buf + DP(in)->bufpos, inbufsiz);
		DP(in)->bufpos += inbufsiz;
		DP(in)->size += bufsiz;
		buf += inbufsiz;
		size_t s = SP(in)->dspi->fread(ctx, DP(in)->fd, buf+inbufsiz, bufsiz-inbufsiz);
		DP(in)->size += s;
		return s + inbufsiz;
	}
}

knh_String_t* knh_InputStream_readLine(CTX ctx, knh_InputStream_t *in)
{
	int ch;
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	if(DP(in)->decNULL == NULL && in->dspi->getCharset != NULL) {
		char *charset = (char*)in->dspi->getCharset(ctx, DP(in)->fd);
		if(charset != NULL) {
			InputStream_setCharset(ctx, in, new_StringDecoderNULL(ctx, B(charset)));
		}
	}
	while((ch = knh_InputStream_getc(ctx, in)) != EOF) {
		if(ch == '\r') {
			DP(in)->prev = ch;
			goto L_TOSTRING;
		}
		else if(ch == '\n') {
			if(DP(in)->prev == '\r') continue;
			DP(in)->prev = ch;
			goto L_TOSTRING;
		}
		else {
			knh_Bytes_putc(ctx, cwb->ba, ch);
		}
	}
	L_TOSTRING:;
	if(knh_cwb_size(cwb) != 0) {
		if(DP(in)->decNULL == NULL) {
			return knh_cwb_newString(ctx, cwb);
		}
		else {
			return knh_cwb_newStringDECODE(ctx, cwb, DP(in)->decNULL);
		}
	}
	return KNH_TNULL(String);
}

/* ------------------------------------------------------------------------ */

void knh_InputStream_close(CTX ctx, knh_InputStream_t *in)
{
	SP(in)->dspi->fclose(ctx, DP(in)->fd);
	SP(in)->dspi = knh_getStreamDSPI(ctx, K_DEFAULT_DSPI);
	DP(in)->fd = IO_NULL;
	KNH_SETv(ctx, DP(in)->ba, KNH_NULL);
	InputStream_setFILE(in, 0);
}

/* ------------------------------------------------------------------------ */

int InputStream_isClosed(CTX ctx, knh_InputStream_t *in)
{
	return (DP(in)->fd == IO_NULL && IS_NULL(DP(in)->ba));
}

/* ------------------------------------------------------------------------ */

void InputStream_setCharset(CTX ctx, knh_InputStream_t *in, knh_StringDecoder_t *c)
{
	if(DP(in)->decNULL == NULL) {
		if(c != NULL) {
			KNH_INITv(DP(in)->decNULL, c);
		}
	}
	else {
		if(c != NULL) {
			KNH_SETv(ctx, DP(in)->decNULL, c);
		}
		else {
			KNH_FINALv(ctx, DP(in)->decNULL);
			DP(in)->decNULL = c;
		}
	}
}

/* ------------------------------------------------------------------------ */
/* [OutputStream] */

KNHAPI2(knh_OutputStream_t*) new_OutputStreamDSPI(CTX ctx, knh_io_t fd, const knh_StreamDSPI_t *dspi)
{
	knh_OutputStream_t* w = new_(OutputStream);
//	KNH_SETv(ctx, DP(w)->urn, urn);
	DP(w)->fd = fd;
	SP(w)->dspi = dspi;
	//KNH_SETv(ctx, DP(w)->ba, new_Bytes(ctx, K_PAGESIZE));
	OutputStream_setBOL(w,1);
	return w;
}

/* ------------------------------------------------------------------------ */

KNHAPI2(knh_OutputStream_t*) new_BytesOutputStream(CTX ctx, knh_Bytes_t *ba)
{
	knh_OutputStream_t* w = new_(OutputStream);
	KNH_SETv(ctx, DP(w)->ba, ba);
	OutputStream_setBOL(w, 1);
	OutputStream_setStoringBuffer(w, 1);
	return w;
}

/* ------------------------------------------------------------------------ */
/* [methods] */

KNHAPI2(void) knh_OutputStream_putc(CTX ctx, knh_OutputStream_t *w, int ch)
{
	knh_Bytes_t *ba = DP(w)->ba;
	DBG_ASSERT(IS_Bytes(ba));
	knh_Bytes_putc(ctx, ba, ch);
	if(!OutputStream_isStoringBuffer(w) && BA_size(ba) > SP(w)->dspi->bufsiz) {
		SP(w)->dspi->fwrite(ctx, DP(w)->fd, (ba)->bu.text, (ba)->bu.len);
		knh_Bytes_clear(ba, 0);
	}
	DP(w)->size++;
}

/* ------------------------------------------------------------------------ */

KNHAPI2(void) knh_OutputStream_write(CTX ctx, knh_OutputStream_t *w, knh_bytes_t buf)
{
	knh_Bytes_t *ba = DP(w)->ba;
	DBG_ASSERT(IS_Bytes(ba));
	knh_Bytes_write(ctx, ba, buf);
	if(!OutputStream_isStoringBuffer(w) && BA_size(ba) > SP(w)->dspi->bufsiz) {
		SP(w)->dspi->fwrite(ctx, DP(w)->fd, (ba)->bu.text, (ba)->bu.len);
		knh_Bytes_clear(ba, 0);
	}
	DP(w)->size += buf.len;
}

/* ------------------------------------------------------------------------ */

KNHAPI2(void) knh_OutputStream_flush(CTX ctx, knh_OutputStream_t *w)
{
	if(!OutputStream_isStoringBuffer(w)) {
		knh_Bytes_t *ba = DP(w)->ba;
		SP(w)->dspi->fwrite(ctx, DP(w)->fd, (ba)->bu.text, (ba)->bu.len);
		knh_Bytes_clear(ba, 0);
	}
}

/* ------------------------------------------------------------------------ */

void knh_OutputStream_clear(CTX ctx, knh_OutputStream_t *w)
{
	if(OutputStream_isStoringBuffer(w)) {
		knh_Bytes_clear(DP(w)->ba, 0);
	}
}

/* ------------------------------------------------------------------------ */

void knh_OutputStream_close(CTX ctx, knh_OutputStream_t *w)
{
	knh_OutputStream_flush(ctx, w);
	knh_Fclose f = SP(w)->dspi->fclose;
	SP(w)->dspi = knh_getStreamDSPI(ctx, K_DEFAULT_DSPI);
	f(ctx, DP(w)->fd);
	DP(w)->fd = IO_NULL;
}

/* ------------------------------------------------------------------------ */

int OutputStream_isClosed(knh_OutputStream_t *w)
{
	return (DP(w)->fd == IO_NULL);
}

/* ------------------------------------------------------------------------ */

void OutputStream_setCharset(CTX ctx, knh_OutputStream_t *w, knh_StringEncoder_t *c)
{
	if(DP(w)->encNULL == NULL) {
		KNH_INITv(DP(w)->encNULL, c);
	}
	else {
		KNH_SETv(ctx, DP(w)->encNULL, c);
	}
}

/* ------------------------------------------------------------------------ */

static knh_bool_t bytes_isASCII(knh_bytes_t t)
{
	size_t i;
	for(i = 0; i < t.len; i++) {
		if(!(t.ustr[i] < 127)) return 0;
	}
	return 1;
}

static knh_bool_t knh_bytes_in(knh_bytes_t t, knh_uchar_t *p)
{
	return (t.ubuf <= p && p < t.ubuf + t.len);
}

KNHAPI2(void) knh_OutputStream_writeLine(CTX ctx, knh_OutputStream_t *w, knh_bytes_t t, knh_bool_t isNEWLINE)
{
	if(OutputStream_isBOL(w)) {
		knh_write_BOL(ctx, w);
	}
	if(t.len > 0) {
		if(DP(w)->encNULL != NULL && !bytes_isASCII(t)) {
			if(knh_bytes_in(ctx->bufa->bu, t.ubuf)) {
				KNH_TODO("write cwb->buf with encoding");
			}
			else {
				knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
				knh_StringEncoder_t *c = DP(w)->encNULL;
				c->dspi->enc(ctx, c->conv, t, cwb->ba);
				knh_write(ctx, w, knh_cwb_tobytes(cwb));
				knh_cwb_close(cwb);
			}
		}
		else {
			knh_OutputStream_write(ctx, w, t);
		}
	}
	if(isNEWLINE) {
		knh_write_EOL(ctx, w);
	}
}

/* ------------------------------------------------------------------------ */
/* [knh_write] */

KNHAPI2(void) knh_write_EOL(CTX ctx, knh_OutputStream_t *w)
{
	knh_OutputStream_write(ctx, w, S_tobytes(DP(w)->NEWLINE));
	if(OutputStream_isAutoFlush(w)) {
		knh_OutputStream_flush(ctx, w);
	}
	OutputStream_setBOL(w, 1);
}

/* ------------------------------------------------------------------------ */

KNHAPI2(void) knh_write_TAB(CTX ctx, knh_OutputStream_t *w)
{
	knh_OutputStream_write(ctx, w, S_tobytes(DP(w)->TAB));
}

/* ------------------------------------------------------------------------ */

KNHAPI2(void) knh_write_BOL(CTX ctx, knh_OutputStream_t *w)
{
	knh_intptr_t i, n = DP(w)->indent;
	if(!OutputStream_isBOL(w)) {
		knh_write_EOL(ctx, w);
	}
	for(i = 0; i < n; i++) {
		knh_OutputStream_write(ctx, w, S_tobytes(DP(w)->TAB));
	}
	OutputStream_setBOL(w, 0);
}

/* ------------------------------------------------------------------------ */

void knh_write_begin(CTX ctx, knh_OutputStream_t *w, int ch)
{
	if(ch != 0) {
		knh_putc(ctx, w, ch);
		knh_write_EOL(ctx, w);
	}
	DP(w)->indent++;
}

/* ------------------------------------------------------------------------ */

void knh_write_end(CTX ctx, knh_OutputStream_t *w, int ch)
{
	DP(w)->indent--;
	if(ch != 0) {
		knh_write_BOL(ctx, w);
		knh_putc(ctx, w, ch);
	}
}

/* ------------------------------------------------------------------------ */
/* [datatype] */

void knh_write_bool(CTX ctx, knh_OutputStream_t *w, int b)
{
	if(b) {
		knh_write(ctx, w, S_tobytes(TS_true));
	}
	else {
		knh_write(ctx, w, S_tobytes(TS_false));
	}
}

/* ------------------------------------------------------------------------ */

void knh_write__p(CTX ctx, knh_OutputStream_t *w, void *ptr)
{
	char buf[K_INT_FMTSIZ];
	knh_snprintf(buf, sizeof(buf), "%p", ptr);
	knh_write(ctx, w, B(buf));
}

/* ------------------------------------------------------------------------ */

void knh_write_dfmt(CTX ctx, knh_OutputStream_t *w, const char *fmt, knh_intptr_t n)
{
	char buf[K_INT_FMTSIZ];
	knh_snprintf(buf, sizeof(buf), fmt, n);
	knh_write(ctx, w, B(buf));
}

/* ------------------------------------------------------------------------ */

void knh_write_ifmt(CTX ctx, knh_OutputStream_t *w, const char *fmt, knh_int_t n)
{
	char buf[K_INT_FMTSIZ];
	knh_snprintf(buf, sizeof(buf), fmt, n);
	knh_write(ctx, w, B(buf));
}

/* ------------------------------------------------------------------------ */

void knh_write_ffmt(CTX ctx, knh_OutputStream_t *w, const char *fmt, knh_float_t n)
{
	char buf[K_FLOAT_FMTSIZ];
	knh_snprintf(buf, sizeof(buf), fmt, n);
	knh_write(ctx, w, B(buf));
}

/* ------------------------------------------------------------------------ */

KNHAPI2(void) knh_write_text(CTX ctx, knh_OutputStream_t *w, const char *text)
{
	knh_bytes_t t;
	t.text = text; t.len = knh_strlen(text);
	knh_write(ctx, w, t);
}

/* ------------------------------------------------------------------------ */
/* [flag] */

void knh_write_flag(CTX ctx, knh_OutputStream_t *w, knh_flag_t flag)
{
	knh_intptr_t i;
	knh_flag_t f = 1 << 15;
	for(i = 0; i < 16; i++) {
		if(i > 0 && i % 8 == 0) knh_putc(ctx, w, ' ');
		if((f & flag) == f) {
			knh_putc(ctx, w, '1');
		}else{
			knh_putc(ctx, w, '0');
		}
		f = f >> 1;
	}
}

/* ------------------------------------------------------------------------ */

void knh_write_cap(CTX ctx, knh_OutputStream_t *w, knh_bytes_t t)
{
	if(islower(t.ustr[0])) {
		knh_putc(ctx, w, toupper(t.ustr[0]));
		t.ustr = t.ustr+1; t.len = t.len -1;
	}
	knh_write(ctx, w, t);
}

/* ------------------------------------------------------------------------ */
/* [String] */

knh_bool_t knh_write_ndata(CTX ctx, knh_OutputStream_t *w, knh_class_t cid, knh_ndata_t d)
{
	switch(cid) {
	case CLASS_Boolean:
		knh_write_bool(ctx, w, (int)d);
		return 1;
	case CLASS_Int:
		knh_write_ifmt(ctx, w, K_INT_FMT, d);
		return 1;
	case CLASS_Float: {
		// removed warrning by ide
		union { knh_float_t f; knh_ndata_t n; } v;
		v.n = d;
		knh_write_ffmt(ctx, w, K_FLOAT_FMT, v.f);
		return 1;
	}
	}
	return 0;
}

/* ------------------------------------------------------------------------ */

void knh_write_Object(CTX ctx, knh_OutputStream_t *w, knh_sfp_t *esp, knh_mtdcache_t *mcache, knh_Object_t *o, knh_methodn_t mn)
{
	if(IS_NULL(o)) {
		knh_write_text(ctx, w, "null");
	}
	else {
		const knh_ClassTBL_t *t = O_cTBL(o);
		if(mcache->cid != t->cid || mcache->mn != mn) {
			mcache->mtd = knh_ClassTBL_getFmt(ctx, t, mn);
		}
		KNH_SETv(ctx, esp[K_CALLDELTA].o, w);
		KNH_SETv(ctx, esp[K_CALLDELTA+1].o, o);
		esp[K_CALLDELTA+1].ndata = O_data(o); // this is necessary
		KNH_SCALL(ctx, esp, 0, mcache->mtd, 1);
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

/* ------------------------------------------------------------------------ */
/* @data */

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
			c = knh_vprintf_parseindex(c++, &index);
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
		knh_mtdcache_t mcache = {0, 0, NULL};
		//knh_Method_t *mtd = NULL;
		knh_sfp_t *esp = ctx->esp;
		c = fmt;
		bindex = 0;
		b.text = c;
		b.len = 0;
		while((ch = *c) != '\0') {
			c++;
			if(ch == '\\') {
				if(b.len > 0) {
					knh_print(ctx, w, b);
				}
				ch = *c;
				switch(ch) {
					case '\0' : return ;
					case 'n': knh_println(ctx, w, STEXT("")); break;
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
				  knh_print(ctx, w, b);
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
						knh_write__p(ctx, w, args[index].pvalue);
						break;
					case 'L':
						DBG_ASSERT(args[index].atype == VA_OBJECT);
						if(IS_Token(args[index].ovalue)) {
							knh_write_token(ctx, w, (knh_Token_t*)args[index].ovalue);
							break;
						}
					case 'O': case 'o':
						DBG_ASSERT(args[index].atype == VA_OBJECT);
						knh_write_Object(ctx, w, esp, &mcache, args[index].ovalue, MN__s);
						break;
					case 'K': case 'k':
						DBG_ASSERT(args[index].atype == VA_OBJECT);
						knh_write_Object(ctx, w, esp, &mcache, args[index].ovalue, MN__k);
						break;
					case 'N': case 'F':
						DBG_ASSERT(args[index].atype == VA_FIELDN);
						knh_write_text(ctx, w, FN__(args[index].fn));
						break;
					case 'M':
						DBG_ASSERT(args[index].atype == VA_METHODN);
						knh_write_mn(ctx, w, args[index].mn);
						break;
					case 'C':
						DBG_ASSERT(args[index].atype == VA_CLASS);
						knh_write_type(ctx, w, args[index].cid);
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
		  knh_print(ctx, w, b);
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
