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

#define USE_STEXT

#include"commons.h"

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* These utf8 functions were originally written by Shinpei Nakata */

#define utf8_isLead(c)      ((c & 0xC0) != 0x80)
#define utf8_isTrail(c)     ((0x80 <= c) && (c <= 0xBF))
#define utf8_isSingleton(c) (c <= 0x7f)

//static knh_ushort_t utf8_getBytes0(knh_uchar_t c)
//{
//	return (utf8_isSingleton(c))?1:(c<=0x7f)?2:(c<=0xef)?3:(c<=0xf7)?4:(c<=0xfb)?5:6;
//}

static const knh_uchar_t _utf8len[] = {
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 0, 0,
};

#define utf8len(c)    _utf8len[(knh_uchar_t)c]


/* ------------------------------------------------------------------------ */

//knh_bool_t knh_bytes_checkENCODING0(knh_bytes_t s)
//{
//#ifdef K_USING_UTF8
//	size_t i, j;
//	knh_uchar_t ch;
//	size_t bytes = 0;
//	for (i=0; i < s.len; i++) {
//		ch = s.ustr[i];
//		/* UTF8 must be in
//		 * single: 0x00 - 0x7f
//		 * lead: 0xC0 - 0xFD (actually, 0xC2-0xF4)
//		 * trail: 0x80 - 0xBF
//		 * consequently, invalid utf8 is ranged
//		 * 0xC0 - 0xC1, 0xF5 - 0xFF
//		 *  */
//		if (utf8_isSingleton(ch)) {
//		} else if (utf8_isLead(ch)) {
//			bytes = utf8_getBytes(ch);
//			for (j=1;j<bytes;j++)
//			{
//				ch = s.ustr[i+j];
//				if (!utf8_isTrail(ch)) {
//					DBG_P("invalid UTF!");
//					return 0;
//				}
//			}
//			i += bytes;
//		}
//	}
//	return 1;
//#else
//	return 1;
//#endif
//}

knh_bool_t knh_bytes_checkENCODING(knh_bytes_t v)
{
#ifdef K_USING_UTF8
	const unsigned char *s = v.ustr;
	const unsigned char *e = s + v.len;
	while (s < e) {
		size_t ulen = utf8len(s[0]);
		switch(ulen) {
		case 1: s++; break;
		case 2:
			if(!utf8_isTrail(s[1])) return 0;
			s+=2; break;
		case 3:
			if(!utf8_isTrail(s[1])) return 0;
			if(!utf8_isTrail(s[2])) return 0;
			s+=3; break;
		case 4:
			if(!utf8_isTrail(s[1])) return 0;
			if(!utf8_isTrail(s[2])) return 0;
			if(!utf8_isTrail(s[3])) return 0;
			s+=4; break;
		case 5: case 6: case 0: default:
			return 0;
		}
	}
	return (s == e);
#else
	return 1;
#endif
}

/* ------------------------------------------------------------------------ */

//size_t knh_bytes_mlen0(knh_bytes_t v)
//{
//	size_t size = v.len;
//#ifdef K_USING_UTF8
//	const unsigned char *s = v.ustr;
//	const unsigned char *e = s + size;
//	size_t len = 0, ulen = 0;
//	while (s < e) {
//		unsigned char c = *s++;
//		if (utf8_isSingleton(c)) len++;
//		else if (utf8_isLead(c)) ulen++;
//	}
//	return ulen + len;
//#else
//	return size;
//#endif
//}

size_t knh_bytes_mlen(knh_bytes_t v)
{
#ifdef K_USING_UTF8
	size_t size = 0;
	const unsigned char *s = v.ustr;
	const unsigned char *e = s + v.len;
	while (s < e) {
		size_t ulen = utf8len(s[0]);
		size ++;
		s += ulen;
	}
	return size;
#else
	return v.len;
#endif
}

/* ------------------------------------------------------------------------ */

//knh_bytes_t knh_bytes_mofflen0(knh_bytes_t m, size_t moff, size_t mlen)
//{
//#ifdef K_USING_UTF8
//	knh_uchar_t ch;
//	const unsigned char *s = m.ustr;
//	size_t i, l = knh_bytes_mlen(m);
//
//	// boundary check
//	mlen = (l < mlen)? l - moff : mlen;
//
//	{
//		size_t len = 0, ulen = 0;
//		for (i = 0; i < m.len; i++) {
//			ch = *s;
//			if (utf8_isSingleton(ch)) len++;
//			else if (utf8_isLead(ch)) ulen++;
//			if (ulen + len == moff+1) {
//				break;
//			}
//			s++;
//		}
//	}
//	DBG_ASSERT(i <= m.len);
//	{
//		for(i = 0; i < mlen; i+=utf8_getBytes(ch)) {
//			ch  = s[i];
//		}
//		m.ustr = s;
//		m.len = i;
//	}
//	return m;
//#else
//	return knh_bytes_subbytes(m, moff, mlen); /* if K_ENCODING is not set */
//#endif
//}

knh_bytes_t knh_bytes_mofflen(knh_bytes_t v, size_t moff, size_t mlen)
{
#ifdef K_USING_UTF8
	size_t i;
	const unsigned char *s = v.ustr;
	const unsigned char *e = s + v.len;
	for(i = 0; i < moff; i++) {
		s += utf8len(s[0]);
	}
	v.ubuf = (knh_uchar_t*)s;
	for(i = 0; i < mlen; i++) {
		s += utf8len(s[0]);
	}
	KNH_ASSERT(s <= e);
	v.len = (const char*)s - v.text;
	return v;
#else
	return knh_bytes_subbytes(m, moff, mlen); /* if K_ENCODING is not set */
#endif
}

/* ------------------------------------------------------------------------ */

knh_int_t knh_uchar_toucs4(knh_ustr_t *utf8)   /* utf8 -> ucs4 */
{
#if defined(K_USING_UTF8)
	knh_int_t ucs4 = 0;
	int i= 0;
	knh_uchar_t ret = 0;
	if (!utf8_isSingleton(utf8[0])) {
		knh_ushort_t length_utf8 = utf8len(utf8[i]);
		knh_uchar_t mask = (knh_uchar_t)(1 << 0 | 1 << 1 | 1 << 2 | 1 << 3);

		switch(length_utf8){
		case 2:
			/* 110xxxxx 10xxxxxx */
			TODO();
			break;
		case 3:
			/* format 1110xxxx 10xxxxxx 10xxxxxx */
			// first 4 bits
			ucs4 = 0;
			ret = utf8[0] & mask;
			ucs4 = ucs4 | ret;
			// second bit
			ucs4 = ucs4 << 6;
			mask = mask | 1 << 4 | 1 << 5;
			ret = utf8[1] & mask;
			ucs4 = ucs4  | ret;
			// third bit
			ucs4 = ucs4 << 6;
			ret = mask & utf8[2];
			ucs4 = ucs4 | ret;
			break;
		default:
			/* TODO: */
			break;
		}
	} else {
		/* ASCII, let it goes...*/
		ucs4 = utf8[0];
	}
	return ucs4;
#else
	return (knh_int_t)utf8[0];
#endif
}

/* ------------------------------------------------------------------------ */
/* ucs4 -> utf8 */

char *knh_format_utf8(char *buf, size_t bufsiz, knh_uint_t ucs4)
{
	/* TODO: here, we assume that BOM bigEndian
	 and only 3 bytes or 1 byte UTF
	 */
	knh_uint_t mask = 0x0;
	knh_uint_t byte1 = 0x7F;
	knh_uint_t byte2 = 0x7FF;
	knh_uint_t byte3 = 0xFFFF;

	char *ret = buf;
	unsigned char utf8[8];
	if (ucs4 <= byte1) {
		/* 7 bits */
		knh_snprintf(buf, bufsiz, "%c", (int)(0xffff & ucs4));
		ret = buf;
	} else if (ucs4 <= byte2) {
		/* cut last 6 bits */
		TODO();
		/* first 5 bits */
	} else if (ucs4 <= byte3) {
		/* cut last 6 bits */
		mask = 1 << 0 | 1 << 1 | 1 << 2 | 1 << 3| 1 << 4 | 1 << 5;
		utf8[2] = (unsigned char)(ucs4 & mask);
		utf8[2] = utf8[2] | 1 << 7;
		/* cut next 6 bits */
		ucs4 = ucs4 >> 6;
		utf8[1] = (unsigned char)(ucs4 & mask);
		utf8[1] = utf8[1] | 1 << 7;
		/* first 4 bits */
		mask = 1 << 0 | 1 << 1 | 1 << 2 | 1 << 3;
		ucs4 = ucs4 >> 6;
		utf8[0] = (unsigned char)(ucs4 & mask);
		utf8[0] = utf8[0] | 1 << 7 | 1 << 6 | 1 << 5;
		utf8[3] = '\0';
		knh_snprintf(buf, bufsiz, "%s", utf8);
	} else {
		TODO();
	}
	return ret;
}
/* ------------------------------------------------------------------------ */
/* [String] */

static void knh_String_checkASCII(knh_String_t *o)
{
	unsigned char ch = 0;
	long len = S_size(o);
	const knh_uchar_t *p = (const knh_uchar_t *) S_tochar(o);
#ifdef K_USING_FASTESTFASTMODE /* written by ide */
	int len = S_size(o), n = (len + 3) / 4;
	/* Duff's device */
	switch(len%4){
	case 0: do{ ch |= *p++;
	case 3:     ch |= *p++;
	case 2:     ch |= *p++;
	case 1:     ch |= *p++;
	} while(--n>0);
	}
#else
	const knh_uchar_t *const e = p + len;
	while(p < e) {
		int n = len % 8;
		switch(n) {
			case 0: ch |= *p++;
			case 7: ch |= *p++;
			case 6: ch |= *p++;
			case 5: ch |= *p++;
			case 4: ch |= *p++;
			case 3: ch |= *p++;
			case 2: ch |= *p++;
			case 1: ch |= *p++;
		}
		len -= n;
	}
#endif
	String_setASCII(o, (ch < 128));
}

/* ------------------------------------------------------------------------ */

KNHAPI2(knh_String_t*) new_String_(CTX ctx, knh_class_t cid, knh_bytes_t t, knh_String_t *memoNULL)
{
	knh_String_t *s = (knh_String_t*)new_hObject(ctx, cid);
	if(t.len + 1 < sizeof(void*) * 2) {
		s->str.ubuf = (knh_uchar_t*)(&(s->hashCode));
		s->str.len = t.len;
		knh_memcpy(s->str.ubuf, t.ustr, t.len);
		s->str.ubuf[s->str.len] = '\0';
		String_setTextSgm(s, 1);
	}
	else {
		s->str.len = t.len;
		s->str.ubuf = (knh_uchar_t*)KNH_MALLOC(ctx, KNH_SIZE(s->str.len+1));
		knh_memcpy(s->str.ubuf, t.ustr, t.len);
		s->str.ubuf[s->str.len] = '\0';
		s->hashCode = 0;
	}
	if(memoNULL != NULL && String_isASCII(memoNULL)) {
		String_setASCII(s, 1);
	}
	else {
		knh_String_checkASCII(s);
	}
	return s;
}

knh_String_t *new_TEXT(CTX ctx, knh_class_t cid, knh_TEXT_t text, int isASCII)
{
	knh_String_t *s = (knh_String_t*)new_hObject(ctx, cid);
	s->str.text = text;
	s->str.len = knh_strlen(text);
	s->hashCode = 0;
	String_setASCII(s, isASCII);
	String_setTextSgm(s, 1);
	return s;
}

/* ------------------------------------------------------------------------ */

int knh_bytes_strcasecmp(knh_bytes_t v1, knh_bytes_t v2)
{
	if(v1.len < v2.len) {
		int res = knh_strncasecmp(v1.text, v2.text, v1.len);
		return (res == 0) ? -1 : res;
	}
	else if(v1.len > v2.len) {
		int res = knh_strncasecmp(v1.text, v2.text, v2.len);
		return (res == 0) ? 1 : res;
	}
	else {
		return knh_strncasecmp(v1.text, v2.text, v1.len);
	}
}

/* ------------------------------------------------------------------------ */
/* regex */

static knh_regex_t* strregex_malloc(CTX ctx, knh_String_t *pattern)
{
	return (knh_regex_t*)pattern;
}
static int strregex_parsecflags(CTX ctx, const char *opt)
{
	return 0;
}
static int strregex_parseeflags(CTX ctx, const char *opt)
{
	return 0;
}
static int strregex_regcomp(CTX ctx, knh_regex_t *reg, const char *pattern, int cflags)
{
	return 0;
}
static size_t strregex_regerror(int errcode, knh_regex_t *reg, char *ebuf, size_t ebuf_size)
{
	ebuf[0] = 0;
	return 0;
}
static int strregex_regexec(CTX ctx, knh_regex_t *reg, const char *str, size_t nmatch, knh_regmatch_t p[], int flags)
{
	size_t e = 0;
	knh_String_t *ptn = (knh_String_t*)reg;
	const char *po = strstr(str, S_tochar(ptn));
	if(po != NULL) {
		p[e].rm_so = po - str;
		p[e].rm_eo = p[e].rm_so + S_size(ptn);
		p[e].rm_name.ubuf = NULL;
		p[e].rm_name.len = 0;
		e++;
	}
	DBG_ASSERT(e < nmatch);
	p[e].rm_so = -1;
	p[e].rm_eo = -1;
	p[e].rm_name.ubuf = NULL;
	p[e].rm_name.len = 0;
	return (po) ? 0 : -1;
}

static void strregex_regfree(CTX ctx, knh_regex_t *reg) { }

static const knh_RegexSPI_t STRREGEXSPI = {
	"strregex",
	strregex_malloc,
	strregex_parsecflags, strregex_parseeflags,
	strregex_regcomp, strregex_regexec, strregex_regerror,
	strregex_regfree
};

const knh_RegexSPI_t* knh_getStrRegexSPI(void)
{
	return &STRREGEXSPI;
}

knh_bool_t Regex_isSTRREGEX(knh_Regex_t *re)
{
	return (re->spi == &STRREGEXSPI);
}

#ifdef K_USING_REGEX

static knh_regex_t* regex_malloc(CTX ctx, knh_String_t *pattern)
{
	regex_t *preg = (regex_t*) KNH_MALLOC(ctx, sizeof(regex_t));
	return (knh_regex_t *) preg;
}

static int regex_parsecflags(CTX ctx, const char *option)
{
	int i, cflags = 0 /*REG_UTF8*/;
	int optlen = strlen(option);
	for (i = 0; i < optlen; i++) {
		switch(option[i]) {
		case 'i': // caseless
			cflags |= REG_ICASE;
			break;
		case 'm': // multiline
			cflags |= REG_NEWLINE;
			break;
		case 's': // dotall
			cflags |= REG_DOTALL;
			break;
		case 'x': //extended
			cflags |= REG_EXTENDED;
			break;
		default: break;
		}
	}
	return cflags;
}

static int regex_parseeflags(CTX ctx, const char *opt)
{
	int i, eflags = 0;
	int optlen = strlen(option);
	for (i = 0; i < optlen; i++) {
		switch(option[i]){
		case 'g': // global
		eflags |= REG_NOTBOL;
		break;
		default: break;
		}
	}
	return eflags;
}
static int regex_regcomp(CTX ctx, knh_regex_t *reg, const char *pattern, int cflags)
{
	regex_t* preg = (regex_t*)reg;
	return regcomp(preg, pattern, cflags);
}
static size_t regex_regerror(int errcode, knh_regex_t *reg, char *ebuf, size_t ebuf_size)
{
	return regerror(res, (regex_t*)reg, ebuf, ebufsize);
}
static int regex_regexec(CTX ctx, knh_regex_t *reg, const char *str, size_t nmatch, knh_regmatch_t p[], int flags)
{
	KNH_TODO("regexec IDE MUST DO THIS");
	return regexec(preg, str, nmatch, (regmatch_t*)p, eflags);
}

static void regex_regfree(CTX ctx, knh_regex_t *reg)
{
	regex_t *preg = (regex_t*)reg;
	regfree(preg);
	KNH_FREE(ctx, preg, sizeof(regex_t));
}

static const knh_RegexSPI_t REGEXSPI = {
	"posix.regex",
	regex_malloc, regex_parsecflags, regex_parseeflags,
	regex_regcomp, regex_regexec, regex_regerror, regex_regfree
};
#endif

const knh_RegexSPI_t* knh_getRegexSPI(void)
{
#ifdef K_USING_REGEX
	return &REGEXSPI;
#else
	return &STRREGEXSPI;
#endif
}

/* ------------------------------------------------------------------------ */

knh_StringDecoder_t* new_StringDecoderNULL(CTX ctx, knh_bytes_t t, knh_NameSpace_t *ns)
{
	if(knh_bytes_strcasecmp(t, STEXT(K_ENCODING)) == 0) {
		return KNH_TNULL(StringDecoder);
	}
	if(ctx->share->iconvDSPI == NULL) {
		((knh_share_t*)ctx->share)->iconvDSPI = knh_NameSpace_getConvTODSPINULL(ctx, ns, STEXT("iconv"));
	}
	if(ctx->share->iconvDSPI != NULL) {
		const knh_ConvDSPI_t *dspi = ctx->share->iconvDSPI;
		knh_conv_t *conv = dspi->open(ctx, K_ENCODING, t.text);
		if(conv != NULL) {
			knh_StringDecoder_t *c = new_(StringDecoder);
			c->conv = conv;
			c->dspi = dspi;
			return c;
		}
	}
	return NULL;
}

/* ------------------------------------------------------------------------ */

knh_StringEncoder_t* new_StringEncoderNULL(CTX ctx, knh_bytes_t t, knh_NameSpace_t *ns)
{
	if(knh_bytes_strcasecmp(t, STEXT(K_ENCODING)) == 0) {
		return KNH_TNULL(StringEncoder);
	}
	if(ctx->share->iconvDSPI == NULL) {
		((knh_share_t*)ctx->share)->iconvDSPI = knh_NameSpace_getConvTODSPINULL(ctx, ns, STEXT("iconv"));
	}
	if(ctx->share->iconvDSPI != NULL) {
		const knh_ConvDSPI_t *dspi = ctx->share->iconvDSPI;
		knh_conv_t *conv = dspi->open(ctx, t.text, K_ENCODING);
		if(conv != NULL) {
			knh_StringEncoder_t *c = new_(StringEncoder);
			c->conv = conv;
			c->dspi = dspi;
			return c;
		}
	}
	return NULL;
}

/* ------------------------------------------------------------------------ */

knh_String_t *knh_cwb_newStringDECODE(CTX ctx, knh_cwb_t *cwb, knh_StringDecoder_t *c)
{
	BEGIN_LOCAL(ctx, lsfp, 1);
	LOCAL_NEW(ctx, lsfp, 0, knh_String_t*, s, knh_cwb_newString(ctx, cwb));
	if(!String_isASCII(s)) {
		c->dspi->dec(ctx, c->conv, S_tobytes(s), cwb->ba);
		s = knh_cwb_newString(ctx, cwb);
		KNH_SETv(ctx, lsfp[0].o, KNH_NULL); //
	}
	END_LOCAL(ctx, lsfp, s);
	return s;
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
