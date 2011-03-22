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

#ifdef K_USING_DEFAULTAPI

/* ------------------------------------------------------------------------ */
//## @Const method Boolean String.opEXISTS(NameSpace ns);

static METHOD String_opEXISTS(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bytes_t path = S_tobytes(sfp[0].s);
	DBG_ASSERT(IS_NameSpace(sfp[1].ns));
	knh_PathDSPI_t *dspi = knh_NameSpace_getPathDSPINULL(ctx, sfp[1].ns, path);
	knh_bool_t tf = 0;
	if(dspi != NULL) tf = (dspi->exists(ctx, path, sfp[1].ns) != PATH_unknown) ? 1 : 0;
	RETURNb_(tf);
}

/* ------------------------------------------------------------------------ */
//## @Hidden @Private method dynamic String.path(String qualifier, NameSpace ns, Class c);

static METHOD String_path(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_class_t cid = (sfp[3].c)->cid;
	knh_bytes_t path = S_tobytes(sfp[0].s);
	knh_bytes_t qpath = S_tobytes(sfp[1].s);
	knh_PathDSPI_t *dspi = knh_NameSpace_getPathDSPINULL(ctx, sfp[2].ns, qpath);
	knh_String_t* spath = sfp[0].s;
	Object *v = NULL;
	int isTRIM = 0;
	if(!knh_bytes_startsWith(path, qpath)) {
		knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
		knh_Bytes_write(ctx, cwb->ba, qpath);
		knh_Bytes_write(ctx, cwb->ba, path);
		spath = knh_cwb_newString(ctx, cwb);
		KNH_SETv(ctx, sfp[rix].s, spath);
		path = S_tobytes(spath);
		isTRIM = 1;
	}
	KNH_ASSERT(dspi != NULL);
	KNH_ASSERT(dspi->isTyped(ctx, cid));
	if(cid == CLASS_Boolean) {
		sfp[rix].bvalue = dspi->exists(ctx, path, NULL) == PATH_unknown ? 0 : 1;
		v = sfp[rix].bvalue ? KNH_TRUE : KNH_FALSE;
	}
	else {
		v = dspi->newObjectNULL(ctx, cid, spath, sfp[2].ns);
		if(v == NULL && cid != CLASS_String) {
			KNH_SYSLOG(ctx, sfp, LOG_WARNING, "MissingPath", 0, "qpath='%B', path='%B' for %C", qpath, path, cid);
		}
	}
	if(v == NULL) {
		if(cid != CLASS_String) {
			v = KNH_NULVAL(cid);
		}
		else if(isTRIM) {
			v = sfp[0].o;
		}
		else {
			path = S_tobytes(spath);
			v = (Object*)new_String_(ctx, CLASS_String, knh_bytes_last(path, qpath.len), spath);
		}
	}
	RETURN_(v);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean String.equals(String s);

static METHOD String_equals(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_((S_size(sfp[0].s) == S_size(sfp[1].s) &&
		knh_bytes_strcmp(S_tobytes(sfp[0].s), S_tobytes(sfp[1].s)) == 0));
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean String.startsWith(String s);

static METHOD String_startsWith(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(knh_bytes_startsWith(S_tobytes(sfp[0].s), S_tobytes(sfp[1].s)));
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean String.endsWith(String s);

static METHOD String_endsWith(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURNb_(knh_bytes_endsWith(S_tobytes(sfp[0].s), S_tobytes(sfp[1].s)));
}

/* ------------------------------------------------------------------------ */
//## @Const method String String.concat(Object value, ...);
//## @Const method String String.opADD(dynamic value);

static METHOD String_concat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int i, ac = knh_stack_argc(ctx, sfp);
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	for(i = 0; i < ac; i++) {
		if(IS_bString(sfp[i].o)) {
			knh_Bytes_write(ctx, cwb->ba, S_tobytes(sfp[i].s));
		}
		else {
			knh_write_Object(ctx, cwb->w, sfp[i].o, FMT_s);
		}
	}
	RETURN_(knh_cwb_newString(ctx, cwb));
}

/* ------------------------------------------------------------------------ */
//## @Const method Int String.indexOf(String s);

static METHOD String_indexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bytes_t base = S_tobytes(sfp[0].s);
	if (IS_NULL(sfp[1].o)) RETURNi_(-1);
	knh_bytes_t delim = S_tobytes(sfp[1].s);
	knh_index_t loc = knh_bytes_indexOf(base, delim);
	if(delim.len == 0) loc--;
	if (loc >= 0 && !String_isASCII(sfp[0].s)) {
		base.len = (size_t)loc;
		loc = knh_bytes_mlen(base);
	}
	RETURNi_(loc);
}

/* ------------------------------------------------------------------------ */
//## @Const method Int String.lastIndexOf(String s);

static METHOD String_lastIndexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bytes_t base = S_tobytes(sfp[0].s);
	if (IS_NULL(sfp[1].o)) RETURNi_(-1);
	knh_bytes_t delim = S_tobytes(sfp[1].s);
	knh_index_t loc = base.len - delim.len;
	if(delim.len == 0) loc--;
	for(; loc >= 0; loc--) {
		if(base.ustr[loc] == delim.ustr[0]) {
			knh_bytes_t sub = {{base.text + loc}, delim.len};
			if(knh_bytes_strcmp(sub, delim) == 0) break;
		}
	}
	if (loc >= 0 && !String_isASCII(sfp[0].s)) {
		base.len = (size_t)loc;
		loc = knh_bytes_mlen(base);
	}
	RETURNi_(loc);
}

/* ------------------------------------------------------------------------ */
//## @Const method Int String.search(Regex re);

static METHOD String_search(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Regex_t *re = sfp[1].re;
	if(IS_NULL(re) || S_size(re->pattern) == 0) RETURNi_(-1);
	knh_index_t loc = -1;
	const char *str = S_tochar(sfp[0].s);  // necessary
	knh_regmatch_t pmatch[1];
	int res = re->spi->regexec(ctx, re->reg, str, 1, pmatch, re->eflags);
	if(res == 0) {
		loc = pmatch[0].rm_so;
		if (!String_isASCII(sfp[0].s) && loc != -1) {
			knh_bytes_t base = {{str}, loc};
			loc = knh_bytes_mlen(base);
		}
	}
//	else {
//		char ebuf[K_ERRBUFSIZE];
//		re->spi->regerror(res, re->reg, ebuf, K_ERRBUFSIZE);
//		ctx->api->ebilog(ctx, re->spi->name, "regexec", LOG_WARNING, "errmsg='%s'", ebuf);
//	}
	RETURNi_(loc);
}

/* ------------------------------------------------------------------------ */
//## @Const method String[] String.match(Regex re);

static METHOD String_match(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *s0 = sfp[0].s;
	knh_Regex_t *re = sfp[1].re;
	knh_Array_t *a = NULL;
	if(IS_NULL(re) || S_size(re->pattern) == 0) {
		a = new_Array(ctx, CLASS_String, 0);
	}
	else {
		const char *str = S_tochar(sfp[0].s);  // necessary
		knh_regmatch_t pmatch[K_REGEX_MATCHSIZE];
		int res = re->spi->regexec(ctx, re->reg, str, K_REGEX_MATCHSIZE, pmatch, re->eflags);
		a = new_Array(ctx, CLASS_String, K_REGEX_MATCHSIZE);
		if(res == 0) {
			knh_bytes_t sub = S_tobytes(s0);
			int i;
			for(i = 0; i < K_REGEX_MATCHSIZE; i++) {
				if(pmatch[i].rm_so == -1) break;
				//DBG_P("[%d], rm_so=%d, rm_eo=%d", i, pmatch[i].rm_so, pmatch[i].rm_eo);
				sub.text = str + pmatch[i].rm_so;
				sub.len = pmatch[i].rm_eo - pmatch[i].rm_so;
				knh_Array_add(ctx, a, new_String_(ctx, CLASS_String, sub, s0));
			}
		}
//		else {
//			char ebuf[K_ERRBUFSIZE];
//			re->spi->regerror(res, re->reg, ebuf, K_ERRBUFSIZE);
//			ctx->api->ebilog(ctx, re->spi->name, "regexec", LOG_WARNING, "errmsg='%s'", ebuf);
//		}
	}
	RETURN_(a);
}

///* ------------------------------------------------------------------------ */
//
//static int knh_bytes_equals_(knh_bytes_t base, size_t s, knh_bytes_t target)
//{
//	size_t i;
//	for(i = 1; i < target.len; i++) {
//		if(base.ustr[s+i] != target.ustr[i]) return 0;
//	}
//	return 1;
//}

/* ------------------------------------------------------------------------ */
//## @Const method String String.replace(Regex re, String s);

static METHOD String_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *s0 = sfp[0].s;
	knh_Regex_t *re = sfp[1].re;
	knh_String_t *s = s0;
	if(!IS_NULL(re) && S_size(re->pattern) > 0) {
		knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
		knh_bytes_t tos = S_tobytes(sfp[2].s);
		const char *str = S_tochar(s0);  // necessary
		const char *estr = str + S_size(s0);
		knh_regmatch_t pmatch[K_REGEX_MATCHSIZE];
		while (str < estr) {
			int res = re->spi->regexec(ctx, re->reg, str, K_REGEX_MATCHSIZE, pmatch, re->eflags);
			if (res == 0) {
				knh_bytes_t sub = {{str},  pmatch[0].rm_so};
				knh_Bytes_write(ctx, cwb->ba, sub);
				knh_Bytes_write(ctx, cwb->ba, tos);
				str += (pmatch[0].rm_eo);
			}
			else {
				knh_bytes_t sub = {{str}, knh_strlen(str)};
				knh_Bytes_write(ctx, cwb->ba, sub);
				break;
			}
		}
		s = knh_cwb_newString(ctx, cwb);
	}
	RETURN_(s);
}

/* ------------------------------------------------------------------------ */

static knh_Array_t *knh_String_toCharArray(CTX ctx, knh_String_t *bs, int istrim)
{
	knh_bytes_t base = S_tobytes(bs);
	if(String_isASCII(bs)) {
		size_t i, n = base.len;
		knh_Array_t *a = new_Array(ctx, CLASS_String, n);
		for(i = 0; i < n; i++) {
			if(istrim && isspace(base.ustr[i])) continue;
			knh_bytes_t sub = {{base.text + i}, 1};
			knh_Array_add(ctx, a, new_String_(ctx, CLASS_String, sub, bs));
		}
		return a;
	}
	else {
		size_t i, n = knh_bytes_mlen(base);
		knh_Array_t *a = new_Array(ctx, CLASS_String, n);
		for(i = 0; i < n; i++) {
			if(istrim && isspace(base.ustr[i])) continue;
			knh_bytes_t sub = knh_bytes_mofflen(base, i, 1);
			knh_Array_add(ctx, a, new_String_(ctx, CLASS_String, sub, bs));
		}
		return a;
	}
}

/* ------------------------------------------------------------------------ */

static knh_bytes_t knh_bytes_trim(knh_bytes_t t)
{
	while(isspace(t.ustr[0])) {
		t.ustr++;
		t.len--;
	}
	if(t.len == 0) return t;
	while(isspace(t.ustr[t.len-1])) {
		t.len--;
		if(t.len == 0) return t;
	}
	return t;
}

/* ------------------------------------------------------------------------ */
//## @Const method String[] String.split(Regex re);

static METHOD String_split(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_String_t *s0 = sfp[0].s;
	knh_Regex_t *re = sfp[1].re;
	knh_Array_t *a = NULL;
	KNH_GC(ctx);
	if(IS_NULL(re) || S_size(re->pattern) == 0) {
		a = knh_String_toCharArray(ctx, s0, 0);
	}
	else {
		const char *str = S_tochar(s0);  // necessary
		const char *estr = str + S_size(s0);
		knh_regmatch_t pmatch[K_REGEX_MATCHSIZE];
		a = new_Array(ctx, CLASS_String, 0);
		while (str < estr) {
			int res = re->spi->regexec(ctx, re->reg, str, K_REGEX_MATCHSIZE, pmatch, re->eflags);
			if(res == 0) {
				knh_bytes_t sub = {{str},  pmatch[0].rm_so};
				knh_Array_add(ctx, a, new_String_(ctx, CLASS_String, sub, s0));
				str += (pmatch[0].rm_eo);
			}
			else {
				knh_bytes_t sub = {{str}, knh_strlen(str)};
				knh_Array_add(ctx, a, new_String_(ctx, CLASS_String, sub, s0));
				break;
			}
		}
	}
	RETURN_(a);
}

/* ------------------------------------------------------------------------ */
//## @Const method Bytes Bytes.(Converter enc);

static METHOD Bytes_convert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_Converter_t *c = sfp[1].conv;
	c->dspi->conv(ctx, c->conv, BA_tobytes(sfp[0].ba), cwb->ba);
	knh_Bytes_t *ba = new_Bytes(ctx, knh_cwb_size(cwb));
	knh_Bytes_write(ctx, ba, knh_cwb_tobytes(cwb));
	knh_cwb_close(cwb);
	RETURN_(ba);
}

/* ------------------------------------------------------------------------ */
//## @Const method Bytes String.encode(StringEncoder enc);

static METHOD String_encode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_Converter_t *c = sfp[1].conv;
	//fprintf(stderr, "%s, c=%p, c->dspi=%p, c->dspi->enc=****\n", CLASS__(c->h.cid), c, c->dspi);
	c->dspi->enc(ctx, c->conv, S_tobytes(sfp[0].s), cwb->ba);
	knh_Bytes_t *ba = new_Bytes(ctx, knh_cwb_size(cwb));
	knh_Bytes_write(ctx, ba, knh_cwb_tobytes(cwb));
	knh_cwb_close(cwb);
	RETURN_(ba);
}

/* ------------------------------------------------------------------------ */
//## @Const method String Bytes.decode(StringDecoder c);

static METHOD Bytes_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_Converter_t *c = sfp[1].conv;
	c->dspi->dec(ctx, c->conv, BA_tobytes(sfp[0].ba), cwb->ba);
	RETURN_(knh_cwb_newString(ctx, cwb));
}

/* ------------------------------------------------------------------------ */
//## @Const method String String.(StringConverter c);
//## @Const method String String.convert(StringConverter c);

static METHOD String_convert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
	knh_Converter_t *c = sfp[1].conv;
	if (!IS_NULL(c)) {
		c->dspi->sconv(ctx, c->conv, S_tobytes(sfp[0].s), cwb->ba);
	}
	RETURN_(knh_cwb_newString(ctx, cwb));
}

/* ------------------------------------------------------------------------ */
//## @Const method String String.trim();

static METHOD String_trim(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_bytes_t t = S_tobytes(sfp[0].s);
	knh_bytes_t t2 = knh_bytes_trim(t);
	knh_String_t *s = sfp[0].s;
	if(t.len > t2.len) {
		s = new_String_(ctx, CLASS_String, t2, s);
	}
	RETURN_(s);
}

/* ------------------------------------------------------------------------ */
//## @Const method Boolean Regex.opHAS(String s);

static METHOD Regex_opHAS(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Regex_t *re = sfp[0].re;
	knh_regmatch_t pmatch[1];
	const char *str = S_tochar(sfp[1].s);
	int res = re->spi->regexec(ctx, re->reg, str, 1, pmatch, re->eflags);
	RETURNb_(res == 0);
}

#endif/*K_USING_DEFAULTAPI*/

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
