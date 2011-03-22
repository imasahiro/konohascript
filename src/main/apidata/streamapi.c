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

/* ------------------------------------------------------------------------ */

#ifdef K_USING_DEFAULTAPI

/* ------------------------------------------------------------------------ */
//## method InputStream InputStream.new(String urn, String mode);

static METHOD InputStream_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_InputStream_t *in = sfp[0].in;
	knh_bytes_t path = S_tobytes(sfp[1].s);
	knh_index_t loc = knh_bytes_index(path, ':');
	const char *mode = IS_NULL(sfp[2].s) ? "r" : S_tochar(sfp[2].s);
	knh_uri_t uri = 0;
	if(loc == -1 || (loc == 1 && isalpha(path.ustr[0]))) {  /* 'C:/' */
		SP(in)->dspi = knh_getStreamDSPI(ctx, STEXT("file"));
	}
	else {
		SP(in)->dspi = knh_getStreamDSPI(ctx, knh_bytes_first(path, loc));
	}
	DP(in)->fd = SP(in)->dspi->fopen(ctx, path, mode);
	if(DP(in)->fd != IO_NULL) {
		KNH_SETv(ctx, DP(in)->urn, sfp[1].s);
		ULINE_setURI(SP(in)->uline, uri);
		DP(in)->bufsiz = SP(in)->dspi->bufsiz;
		if(DP(in)->bufsiz > 0) {
			KNH_SETv(ctx, DP(in)->ba, new_Bytes(ctx, DP(in)->bufsiz));
			DP(in)->buf = (char*)(DP(in)->ba)->bu.ubuf;
		}
		else {
			InputStream_setFILE(in, 1);
		}
		DP(in)->bufpos = 0;
		DP(in)->bufend = 0;  /* empty */
	}
	else {
		knh_Object_toNULL(ctx, in);
		SP(in)->dspi = knh_getStreamDSPI(ctx, K_DEFAULT_DSPI);
	}
	RETURN_(in);
}

/* ------------------------------------------------------------------------ */
//## method Int InputStream.getChar();

static METHOD InputStream_getChar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNi_(knh_InputStream_getc(ctx, sfp[0].in));
}

/* ------------------------------------------------------------------------ */
//## method Int InputStream.read(Bytes buf, Int offset, Int length);

static METHOD InputStream_read(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Bytes_t *ba = sfp[1].ba;
	knh_bytes_t buf = BA_tobytes(ba);
	size_t offset = Int_to(size_t,sfp[2]);
	size_t len    = Int_to(size_t,sfp[3]);
	if(unlikely(offset > buf.len)) {
		THROW_OutOfRange(ctx, sfp, offset, buf.len);
	}
	buf = knh_bytes_last(buf, offset);
	if(len != 0) {
		knh_Bytes_ensureSize(ctx, ba, offset + len);
		buf.len = len;
		buf.ubuf = ba->bu.ubuf;
	}
	RETURNi_(knh_InputStream_read(ctx, sfp[0].in, (char*)buf.ubuf, buf.len));
}

/* ------------------------------------------------------------------------ */
//## method Boolean InputStream.isClosed();

static METHOD InputStream_isClosed_(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(InputStream_isClosed(ctx, sfp[0].in));
}

/* ------------------------------------------------------------------------ */
//## method void InputStream.close();

static METHOD InputStream_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_InputStream_close(ctx, sfp[0].in);
}

/* ------------------------------------------------------------------------ */
//## method StringDecoder InputStream.setCharset(StringDecoder c);

static METHOD InputStream_setCharset_(CTX ctx, knh_sfp_t *sfp _RIX)
{
	InputStream_setCharset(ctx, sfp[0].in, (knh_StringDecoder_t*)sfp[1].o);
	RETURN_(sfp[1].o);
}

/* ------------------------------------------------------------------------ */
//## method String InputStream.readLine();

static METHOD InputStream_readLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *s = knh_InputStream_readLine(ctx, sfp[0].in);
	RETURN_(s);
}

///* ------------------------------------------------------------------------ */
////## method dynamic InputStream.readData();
//
//static METHOD InputStream_readData(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	Object *v = knh_InputStream_readData(ctx, sfp[0].in);
//	RETURN_(v);
//}

/* ------------------------------------------------------------------------ */
/* [iterators] */

static ITRNEXT knh_InputStream_nextLine(CTX ctx, knh_sfp_t *sfp, long rtnidx)
{
	int ch;
	knh_Iterator_t *it = sfp[0].it;
	knh_InputStream_t *in = (knh_InputStream_t*)DP(it)->source;
	knh_cwb_t cwbbuf;
	knh_cwb_t *cwb = knh_cwb_open(ctx, &cwbbuf);
	while((ch = knh_InputStream_getc(ctx, in)) != EOF) {
		if(ch == 13) continue;
		if(ch == 10) {
			//ITRNEXT_(new_String__cwbconv(ctx, cwb, DP(in)->bconv));
			ITRNEXT_(knh_cwb_newString(ctx, cwb));
		}
		knh_Bytes_putc(ctx, cwb->ba, ch);
	}
	if(knh_cwb_size(cwb) != 0) {
		ITRNEXT_(knh_cwb_newString(ctx, cwb));
	}
	ITREND_();
}

/* ------------------------------------------------------------------------ */
//## @Final mapper InputStream String..;

static TCAST knh_InputStream_String__(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_(new_Iterator(ctx, CLASS_String, sfp[K_TRLIDX].o, knh_InputStream_nextLine));
}

/* ------------------------------------------------------------------------ */
/* [OutputStream] */

//## method OutputStream OutputStream.new(String urn, String mode);

static METHOD OutputStream_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_t *w = sfp[0].w;
	knh_bytes_t path = S_tobytes(sfp[1].s);
	knh_index_t loc = knh_bytes_index(path, ':');
	const char *mode = IS_NULL(sfp[2].s) ? "w" : S_tochar(sfp[2].s);
	knh_uri_t uri = 0;
	if(loc == -1 || (loc == 1 && isalpha(path.ustr[0]))) {  /* 'C:/' */
		SP(w)->dspi = knh_getStreamDSPI(ctx, STEXT("file"));
	}
	else {
		SP(w)->dspi = knh_getStreamDSPI(ctx, knh_bytes_first(path, loc));
	}
	DP(w)->fd = SP(w)->dspi->wopen(ctx, path, mode);
	if(DP(w)->fd != IO_NULL) {
		KNH_SETv(ctx, DP(w)->urn, sfp[1].s);
		ULINE_setURI(SP(w)->uline, uri);
		KNH_SETv(ctx, DP(w)->ba, new_Bytes(ctx, K_PAGESIZE));
		OutputStream_setBOL(w,1);
	}
	else {
		knh_Object_toNULL(ctx, w);
		SP(w)->dspi = knh_getStreamDSPI(ctx, K_DEFAULT_DSPI);
	}
	RETURN_(w);
}

/* ------------------------------------------------------------------------ */
//## method void OutputStream.writeChar(Int ch);

static METHOD OutputStream_writeChar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_t *w = sfp[0].w;
	knh_Bytes_t *ba = DP(w)->ba;
	const struct _knh_StreamDSPI_t *dspi = SP(w)->dspi;
	KNH_ASSERT(IS_Bytes(ba));
	knh_Bytes_putc(ctx, ba, (int)(sfp[1].ivalue));
	if(!OutputStream_isStoringBuffer(w) && BA_size(ba) > dspi->bufsiz) {
		dspi->fwrite(ctx, DP(w)->fd, (ba)->bu.text, (ba)->bu.len);
		knh_Bytes_clear(ba, 0);
	}
	DP(w)->size++;
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void OutputStream.write(Bytes buf, Int offset, Int length);

static METHOD OutputStream_write(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bytes_t t = BA_tobytes(sfp[1].ba);
	size_t offset = (sfp[2].ivalue == 0) ? 0 : knh_array_index(ctx, sfp, Int_to(size_t, sfp[2]), t.len);
	size_t len = (sfp[3].ivalue == 0) ? (t.len - offset) : Int_to(size_t, sfp[3]);
	if(offset + len > t.len) len = t.len - offset;
	t.ustr = &(t.ustr[offset]);
	t.len = len;
	knh_OutputStream_write(ctx, sfp[0].w, t);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method Boolean OutputStream.isClosed();

static METHOD OutputStream_isClosed_(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(OutputStream_isClosed(sfp[0].w));
}

/* ------------------------------------------------------------------------ */
static void _OutputStream_writeLine(CTX ctx, knh_OutputStream_t *w, knh_String_t *s)
{
	if(s == TS_EOL) {
		knh_write_EOL(ctx, w);
	}
	else if(s == TS_BEGIN) {
		DP(w)->indent++;
	}
	else if(s == TS_END) {
		DP(w)->indent--;
	}
	else {
		knh_OutputStream_writeLine(ctx, w, S_tobytes(s), 0);
	}
}
/* ------------------------------------------------------------------------ */
//## method void OutputStream.print(Object value, ...);

static METHOD OutputStream_print(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_t *w = sfp[0].w;
	knh_sfp_t *v = sfp + 1;
	size_t i, ac = knh_stack_argc(ctx, v);
	for(i = 0; i < ac; i++) {
		if(IS_bString(v[i].o)) {
			_OutputStream_writeLine(ctx, w, v[i].s);
		}
		else {/*if(!knh_write_ndata(ctx, w, O_bcid(v[i].o), v[i].ndata)) {*/
			knh_write_Object2(ctx, w, v[i].o, FMT_s);
		}
	}
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void OutputStream.opSEND(String s, ...);

static METHOD OutputStream_opSEND(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_t *w = sfp[0].w;
	knh_sfp_t *v = sfp + 1;
	size_t i, ac = knh_stack_argc(ctx, v);
	if(ctx->bufw == w) {
		for(i = 0; i < ac; i++) {
			knh_Bytes_write(ctx, ctx->bufa, S_tobytes(v[i].s));
		}
	}
	else {
		for(i = 0; i < ac; i++) {
			_OutputStream_writeLine(ctx, w, v[i].s);
		}
	}
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void OutputStream.println(dynamic value, ...);

static METHOD OutputStream_println(CTX ctx, knh_sfp_t *sfp _RIX)
{
	KNH_SETv(ctx, ctx->esp[0].o, TS_EOL);
	klr_setesp(ctx, (ctx->esp+1));
	OutputStream_print(ctx, sfp, rix);
}

/* ------------------------------------------------------------------------ */
//## method void OutputStream.writeData(Object data, ...);

static METHOD OutputStream_writeData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_t *w = sfp[0].w;
	knh_sfp_t *v = sfp + 1;
	int i, ac = knh_stack_argc(ctx, v);
	knh_intptr_t indent = DP(w)->indent;
	for(i = 0; i < ac; i++) {
		DP(w)->indent = 0;
//		if(!knh_write_ndata(ctx, w, O_bcid(v[i].o), v[i].ndata)) {
		knh_write_Object2(ctx, w, v[i].o, FMT_data);
//		}
		knh_putc(ctx, w, ';');
		knh_write_EOL(ctx, w);
	}
	DP(w)->indent = indent;
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void OutputStream.flush();

static METHOD OutputStream_flush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_flush(ctx, sfp[0].w);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void OutputStream.clearBuffer();

static METHOD OutputStream_clearBuffer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_clear(ctx, sfp[0].w);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method void OutputStream.close();

static METHOD OutputStream_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_close(ctx, sfp[0].w);
	RETURNvoid_();
}

/* ------------------------------------------------------------------------ */
//## method StringEncoder OutputStream.setCharset(StringEncoder c);

static METHOD OutputStream_setCharaset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	OutputStream_setCharset(ctx, sfp[0].w, (knh_StringEncoder_t*)sfp[1].s);
	RETURN_(sfp[1].o);
}

/* ------------------------------------------------------------------------ */

#endif /*K_USING_DEFAULTAPI*/


#ifdef __cplusplus
}
#endif
