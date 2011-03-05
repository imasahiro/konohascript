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
/* [format] */

static const char *newfmt(char *buf, size_t bufsiz, knh_bytes_t fmt, const char *t)
{
	char *p = buf + (fmt.len - 1);
	strncpy(buf, fmt.text, bufsiz);
	strncpy(p, t, bufsiz - fmt.len);
	DBG_P("FMT='%s'", buf);
	return (const char*)buf;
}

/* ------------------------------------------------------------------------ */
//## @Const @FastCall method String Int.format(String fmt);

static METHOD Int_format(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_sfp_t *arg = ctx->esp - 1;
	DBG_ASSERT(arg == sfp+1);
	knh_bytes_t fmt = S_tobytes(arg[0].s);
	L_RETRY:;
	int ch = fmt.ustr[fmt.len - 1];
	if(fmt.ustr[0] == '%' && (ch == 'u' || ch == 'd' || ch == 'x')) {
		char fmtbuf[40], buf[80];
		const char *ifmt = (ch == 'd') ? K_INT_FMT : ((ch == 'x') ? K_INT_XFMT : K_UINT_FMT);
		knh_snprintf(buf, sizeof(buf), newfmt(fmtbuf, sizeof(fmtbuf), fmt, ifmt + 1), sfp[0].ivalue);
		RETURN_(new_S(ctx, B(buf)));
	}
	if(fmt.len != 0) {
		KNH_SYSLOG(ctx, LOG_WARNING, "Format!!", "invalid format: %s", fmt.text);
	}
	fmt = STEXT("%d");
	goto L_RETRY;
}

/* ------------------------------------------------------------------------ */
//## @Const @FastCall method String Float.format(String fmt);

static METHOD Float_format(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_sfp_t *arg = ctx->esp - 1;
	DBG_ASSERT(arg == sfp+1);
	knh_bytes_t fmt = S_tobytes(arg[0].s);
	L_RETRY:;
	int ch = fmt.ustr[fmt.len - 1];
	if(fmt.ustr[0] == '%' && (ch == 'f' || ch == 'e')) {
		char buf[80];
		const char *ifmt = (ch == 'f') ? K_FLOAT_FMT : K_FLOAT_FMTE;
		knh_snprintf(buf, sizeof(buf), ifmt, sfp[0].fvalue);
		RETURN_(new_S(ctx, B(buf)));
	}
	if(fmt.len != 0) {
		KNH_SYSLOG(ctx, LOG_WARNING, "Format!!", "invalid format: %s", fmt.text);
	}
	fmt = STEXT("%f");
	goto L_RETRY;
}

/* ------------------------------------------------------------------------ */
//## @Const @FastCall method String String.format(String fmt);

static METHOD String_format(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_sfp_t *arg = ctx->esp - 1;
	DBG_ASSERT(arg == sfp+1);
	knh_bytes_t fmt = S_tobytes(arg[0].s);
	if(fmt.ustr[0] == '%' && fmt.ustr[fmt.len-1] == 's') {
		char buf[256];
		knh_snprintf(buf, sizeof(buf), fmt.text, S_tochar(sfp[0].s));
		RETURN_(new_S(ctx, B(buf)));
	}
	if(fmt.len != 0) {
		KNH_SYSLOG(ctx, LOG_WARNING, "Format!!", "invalid format: %s", fmt.text);
	}
	RETURN_(sfp[0].s);
}

/* ------------------------------------------------------------------------ */
/* [utils] */

static knh_bool_t checkRecursiveCalls(CTX ctx, knh_sfp_t *sfp)
{
	knh_sfp_t *sp = sfp - 3;
	while(ctx->stack < sp) {
		if(sp[0].mtdNC == sfp[0].mtdNC && sp[1].w == sfp[1].w && sp[2].o == sfp[2].o) {
			return 1;
		}
		sp--;
	}
	return 0;
}

static inline knh_ndata_t O_ndata(void *p)
{
	if(sizeof(knh_int_t) < sizeof(knh_ndata_t)) {
		return ((knh_int_t*)p)[0];
	}
	return ((knh_ndata_t*)p)[0];
}

static void knh_write_ObjectField(CTX ctx, knh_OutputStream_t *w, Object **v, size_t i, knh_type_t type, knh_methodn_t mn)
{
	if(!knh_write_ndata(ctx, w, CLASS_t(type), O_ndata(v+i))) {
		knh_mtdcache_t mcache = {0, 0, NULL};
		knh_write_Object(ctx, w, ctx->esp, &mcache, v[i], mn);
	}
}

/* ------------------------------------------------------------------------ */
/* %empty */

//## method void Object.%empty();
static METHOD Object__empty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	if(CTX_isDebug(ctx)) {
		KNH_SYSLOG(ctx, LOG_WARNING, "Format!!", "*%%empty(%s)", O__(sfp[1].o));
	}
}

/* ------------------------------------------------------------------------ */
/* %s */

//## method void Object.%s();
static METHOD Object__s(CTX ctx, knh_sfp_t *sfp _RIX)
{
	if(IS_NULL(sfp[1].o)) {
		knh_write(ctx, sfp[0].w, STEXT("null"));
	}
	else {
		knh_write_text(ctx, sfp[0].w, CLASS__(O_cid(sfp[1].o)));
		knh_putc(ctx, sfp[0].w, ':');
		knh_write__p(ctx, sfp[0].w, (void*)sfp[1].o);
	}
}

/* ------------------------------------------------------------------------ */
//## method void Boolean.%s();

static METHOD Boolean__s(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_bool(ctx, sfp[0].w, sfp[1].bvalue);
}

/* ------------------------------------------------------------------------ */
//## method void Int.%s();
//## method void Int.%d();

static METHOD Int__s(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_ifmt(ctx, sfp[0].w, K_INT_FMT, sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## method void Float.%s();
//## method void Float.%f();

static METHOD Float__s(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_ffmt(ctx, sfp[0].w, K_FLOAT_FMT, sfp[1].fvalue);
}

/* ------------------------------------------------------------------------ */

static void knh_write_quote(CTX ctx, knh_OutputStream_t *w, knh_bytes_t t, int quote)
{
	knh_bytes_t sub = t;
	size_t i, s = 0;
	knh_putc(ctx, w, quote);
	for(i = 0; i < t.len; i++) {
		int ch = t.ustr[i];
		if(ch == '\t' || ch == '\n' || ch == '\r' || ch == '\\' || ch == quote) {
			sub.ustr = t.ustr + s;
			sub.len = i - s;
			knh_print(ctx, w, sub); s = i + 1;
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
		sub.ustr = t.ustr + s;
		sub.len = t.len - s;
		knh_print(ctx, w, sub);
	}
	knh_putc(ctx, w, quote);
}

/* ------------------------------------------------------------------------ */
//## method void String.%s();

static METHOD String__s(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_print(ctx, sfp[0].w, S_tobytes(sfp[1].s));
}

/* ------------------------------------------------------------------------ */
//## method void Bytes.%s();

static METHOD Bytes__s(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_printf(ctx, sfp[0].w, "byte[%d]", (sfp[1].ba)->bu.len);
}

/* ------------------------------------------------------------------------ */
//## method void Regex.%s();

static METHOD Regex__s(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_quote(ctx, sfp[0].w, S_tobytes((sfp[1].re)->pattern), '/');
}

/* ------------------------------------------------------------------------ */
//## method void Class.%s();

static METHOD Class__s(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_cid(ctx, sfp[0].w, knh_Class_cid(sfp[1].c));
}

/* ------------------------------------------------------------------------ */
//## method void Method.%s();

static METHOD Method__s(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_type(ctx, sfp[0].w, (sfp[1].mtd)->cid);
	knh_putc(ctx, sfp[0].w, '.');
	knh_write_mn(ctx, sfp[0].w, (sfp[1].mtd)->mn);
}

/* ------------------------------------------------------------------------ */
//## method void Exception.%s();

static METHOD Exception__s(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_text(ctx, sfp[0].w, EBI__(DP(sfp[1].e)->eid));
	knh_write_text(ctx, sfp[0].w, "!!");
}

/* ------------------------------------------------------------------------ */
//## method void Goal.%s();

static METHOD Goal__s(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Goal_t *g = sfp[1].goal;
	knh_write(ctx, sfp[0].w, S_tobytes(g->type));
	knh_putc(ctx, sfp[0].w, '-');
	knh_write_ifmt(ctx, sfp[0].w, K_INT_FMT, g->id);
	knh_putc(ctx, sfp[0].w, ' ');
	knh_write_quote(ctx, sfp[0].w, S_tobytes(g->msg), '"');
}

/* ------------------------------------------------------------------------ */
//## method void UnitTest.%s();

static METHOD UnitTest__s(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_UnitTest_t *ut = (knh_UnitTest_t*)sfp[1].o;
	knh_write_quote(ctx, sfp[0].w, S_tobytes(ut->msg), '\'');
}

/* ------------------------------------------------------------------------ */
//## method void Object.%k();

static METHOD Object__k(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_t *w = sfp[0].w;
	Object *o = sfp[1].o;
	if(IS_NULL(o)) {
		knh_write(ctx, w, STEXT("null"));
	}
	else if(IS_ObjectField(o)) {
		knh_fields_t *tf = O_cTBL(o)->fields;
		size_t i, fsize = O_cTBL(o)->fsize;
		Object **v = (Object**)o->ref;
		knh_putc(ctx, w, '{');
		if(checkRecursiveCalls(ctx, sfp)) {
			knh_write_dots(ctx, w);
			goto L_CLOSE;
		}
		if(fsize > 0) {
			knh_write_fn(ctx, w, tf[0].fn);
			knh_write(ctx, w, STEXT(": "));
			knh_write_ObjectField(ctx, w, v, 0, tf[0].type, MN__k);
		}
		for(i = 1; i < fsize; i++) {
			if(tf[i].type == TYPE_void) continue;
			knh_write_delim(ctx, w);
			knh_write_fn(ctx, w, tf[i].fn);
			knh_write(ctx, w, STEXT(": "));
			knh_write_ObjectField(ctx, w, v, i, tf[i].type, MN__k);
		}
		L_CLOSE:;
		knh_putc(ctx, w, '}');
	}
	else {
		knh_write_text(ctx, w, CLASS__(O_cid(o)));
		knh_putc(ctx, w, ':');
		knh_write__p(ctx, w, (void*)o);
	}
}

/* ------------------------------------------------------------------------ */
//## method void Int.%k();

static METHOD Int__k(CTX ctx, knh_sfp_t *sfp _RIX)
{
#if defined(K_USING_SEMANTICS)
	knh_Semantics_t *u = knh_getSemantics(ctx, O_cid(sfp[1].o));
	knh_write_intx(ctx, sfp[0].w, u, sfp[1].ivalue);
#else
	knh_write_ifmt(ctx, sfp[0].w, K_INT_FMT, sfp[1].ivalue);
#endif
}

/* ------------------------------------------------------------------------ */
//## method void Float.%k();

static METHOD Float__k(CTX ctx, knh_sfp_t *sfp _RIX)
{
#if defined(K_USING_SEMANTICS)
	knh_Semantics_t *u = knh_getSemantics(ctx, O_cid(sfp[1].o));
	knh_write_floatx(ctx, sfp[0].w, u, sfp[1].fvalue);
#else
	knh_write_ffmt(ctx, sfp[0].w, K_FLOAT_FMT, sfp[1].fvalue);
#endif
}

/* ------------------------------------------------------------------------ */
//## method void String.%k();

static METHOD String__k(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_quote(ctx, sfp[0].w, S_tobytes(sfp[1].s), '"');
}

/* ------------------------------------------------------------------------ */
//## method void Tuple.%k();

static METHOD Tuple__k(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_t *w = sfp[0].w;
	Object *o = sfp[1].o;
	if(Object_isNullObject(o)) {
		knh_write(ctx, w, STEXT("null"));
	}
	else {
		knh_fields_t *tf = O_cTBL(o)->fields;
		size_t i, fsize = O_cTBL(o)->fsize;
		Object **v = (Object**)o->ref;
		knh_putc(ctx, w, '(');
		if(checkRecursiveCalls(ctx, sfp)) {
			knh_write_dots(ctx, w);
			goto L_CLOSE;
		}
		knh_write_ObjectField(ctx, w, v, 0, tf[0].type, MN__k);
		for(i = 1; i < fsize; i++) {
			if(tf[i].type == TYPE_void) continue;
			knh_write_delim(ctx, w);
			knh_write_ObjectField(ctx, w, v, i, tf[i].type, MN__k);
		}
		L_CLOSE:;
		knh_putc(ctx, w, ')');
	}
}

/* ------------------------------------------------------------------------ */
//## method void Range.%k();

static METHOD Range__k(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Range_t *o = sfp[1].range;
	knh_OutputStream_t *w = sfp[0].w;
	knh_class_t p1 = O_p1(o);
	knh_putc(ctx, w, '[');
	knh_write_ObjectField(ctx, w, &o->ostart, 0, p1, MN__k);
	knh_write(ctx, w, STEXT(" to "));
	knh_write_ObjectField(ctx, w, &o->oend, 0, p1, MN__k);
	knh_putc(ctx, w, ']');
}

/* ------------------------------------------------------------------------ */
//## method void Array.%k();

static METHOD Array__k(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_t *w = sfp[0].w;
	knh_putc(ctx, w, '[');
	if(checkRecursiveCalls(ctx, sfp)) {
		knh_write_dots(ctx,w);
	}
	else {
		knh_Array_t *a = sfp[1].a;
		knh_class_t p1 = O_p1(a);
		size_t c, size = knh_Array_size(a);
		if(size > 0) {
			if(IS_Tint(p1) || p1 == TYPE_Boolean) {
				knh_write_ifmt(ctx, w, K_INT_FMT, a->ilist[0]);
				for(c = 1; c < size; c++) {
					knh_write_delim(ctx, w);
					knh_write_ifmt(ctx, w, K_INT_FMT, a->ilist[c]);
				}
			}
			else if(IS_Tfloat(p1)) {
				knh_write_ffmt(ctx, w, K_FLOAT_FMT, a->flist[0]);
				for(c = 1; c < knh_Array_size(a); c++) {
					knh_write_delim(ctx, w);
					knh_write_ffmt(ctx, w, K_FLOAT_FMT, a->flist[c]);
				}
			}
			else {
				knh_mtdcache_t mcache = {0, 0, NULL};
				knh_write_Object(ctx, w, ctx->esp, &mcache, a->list[0], MN__k);
				for(c = 1; c < size; c++) {
					knh_write_delim(ctx, w);
					knh_write_Object(ctx, w, ctx->esp, &mcache, a->list[c], MN__k);
				}
			}
		}
	}
	knh_putc(ctx, w, ']');
}

/* ------------------------------------------------------------------------ */
//## method void Map.%k();

#define knh_Map_size(o) ((o)->dspi->size(ctx, o->map))

static METHOD Map__k(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_t *w = sfp[0].w;
	knh_putc(ctx, w, '{');
	if(checkRecursiveCalls(ctx, sfp)) {
		knh_write_dots(ctx, w);
	}
	else {
	}
	knh_putc(ctx, w, '}');
}

/* ------------------------------------------------------------------------ */
//## method void Class.%k();

static METHOD Class__k(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_cid(ctx, sfp[0].w, ((knh_Class_t*)sfp[1].o)->type);
}

/* ------------------------------------------------------------------------ */
//## method void Method.%k();

static METHOD Method__k(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Method_t *o = sfp[1].mtd;
	knh_OutputStream_t *w = sfp[0].w;
	int isInline = IS_NULL(sfp[2].o) ? 1 : 0;
	if(!isInline && Method_isAbstract(o)) {
		knh_write(ctx, w, STEXT("@Abstract"));
		knh_putc(ctx, w, ' ');
	}
	if(knh_ParamArray_rtype(DP(o)->mp) == TYPE_void) {
		knh_write(ctx, w, S_tobytes(TS_void));
	}else{
		knh_write_type(ctx, w, knh_ParamArray_rtype(DP(o)->mp));
	}
	knh_putc(ctx, w, ' ');
	Method__s(ctx, sfp, rix);
	knh_putc(ctx, w, '(');
	size_t i;
	for(i = 0; i < knh_Method_psize(o); i++) {
		knh_param_t *p = knh_ParamArray_get(DP(o)->mp, i);
		if(i > 0) {
			knh_write_delim(ctx, w);
		}
		knh_write_type(ctx, w, p->type);
		if(!isInline) {
			knh_putc(ctx, w, ' ');
			knh_write(ctx, w, B(FN__(p->fn)));
		}
	}
	if(ParamArray_isVARGs(DP(o)->mp)) {
		knh_write_delim(ctx, w);
		knh_write_dots(ctx, w);
	}
	knh_putc(ctx, w, ')');
}

/* ------------------------------------------------------------------------ */
//## method void TypeMap.%k();

static METHOD TypeMap__k(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_TypeMap_t *o = sfp[1].trl;
	knh_OutputStream_t *w = sfp[0].w;
	knh_write_type(ctx, w, SP(o)->scid);
	knh_write(ctx, w, STEXT("=>"));
	knh_write_type(ctx, w, SP(o)->tcid);
}

/* ------------------------------------------------------------------------ */
//## method void InputStream.%k();

static METHOD InputStream__k(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_quote(ctx, sfp[0].w, S_tobytes(DP((knh_InputStream_t*)sfp[1].o)->urn), '\'');
}

/* ------------------------------------------------------------------------ */
//## method void OutputStream.%k();

static METHOD OutputStream__k(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_quote(ctx, sfp[0].w, S_tobytes(DP(sfp[1].w)->urn), '\'');
}

///* ------------------------------------------------------------------------ */
////## method void dynamic.%k();
//
//static METHOD dynamic__k(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	if(IS_NULL(sfp[1].o)) {
//		knh_write(ctx, sfp[0].w, S_tobytes(TS_null));
//	}
//	else {
//		knh_write_type(ctx, sfp[0].w, O_cid(sfp[1].o));
//		knh_putc(ctx, sfp[0].w, ':');
//		knh_write__p(ctx, sfp[0].w, (sfp[1].p)->ptr);
//	}
//}

/* ------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------ */
//## method void Bytes.%dump();

static METHOD Bytes__dump(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Bytes_t *ba = sfp[1].ba;
	knh_OutputStream_t *w = sfp[0].w;
	size_t i, j, n;
	char buf[40];
	for(j = 0; j * 16 < ba->bu.len; j++) {
		knh_snprintf(buf, sizeof(buf), "%08x", (int)(j*16));
		knh_write(ctx, w, B(buf));
		for(i = 0; i < 16; i++) {
			n = j * 16 + i;
			if(n < ba->bu.len) {
				knh_snprintf(buf, sizeof(buf), " %2x", (int)ba->bu.ustr[n]);
				knh_write(ctx, w, B(buf));
			}
			else {
				knh_write(ctx, w, STEXT("   "));
			}
		}
		knh_write(ctx, w, STEXT("    "));
		for(i = 0; i < 16; i++) {
			n = j * 16 + i;
			if(n < ba->bu.len && isprint(ba->bu.ustr[n])) {
				knh_snprintf(buf, sizeof(buf), "%c", (int)ba->bu.ustr[n]);
				knh_write(ctx, w, B(buf));
			}
			else {
				knh_write(ctx, w, STEXT(" "));
			}
		}
		knh_write_EOL(ctx, w);
	}
}

/* ------------------------------------------------------------------------ */
//## method void Iterator.%dump();

static METHOD Iterator__dump(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_t *w = sfp[0].w;
	knh_Iterator_t *it = sfp[1].it;
	knh_ParamArray_t *pa = ClassTBL(O_cid(it))->cparam;
	knh_class_t p1 = O_p1(it);
	knh_mtdcache_t mcache = {0, 0, NULL};
	if(pa->psize > 1) {
		TODO();
	}
	if(pa->psize == 1) {
		size_t c = 0;
		while(it->fnext_1(ctx, sfp+1, /*1+*/1)) {
			if(c > 0) {
				knh_write_EOL(ctx, w);
			}
			if(IS_Tint(p1)) {
				knh_write_ifmt(ctx, w, K_INT_FMT, sfp[2].ivalue);
			}
			else if(IS_Tfloat(p1)) {
				knh_write_ffmt(ctx, w, K_FLOAT_FMT, sfp[2].fvalue);
			}
			else {
				knh_write_Object(ctx, w, sfp+4, &mcache, sfp[2].o, MN__k);
			}
			c++;
		}
	}
}

/* ------------------------------------------------------------------------ */
//## method void Method.%dump();

static METHOD Method__dump(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Method_t *mtd = sfp[1].mtd;
	knh_OutputStream_t *w = sfp[0].w;
	KNH_SETv(ctx, sfp[2].o, TS_EMPTY);
	Method__k(ctx, sfp, rix);
	knh_write_EOL(ctx, w);
	if(Method_isObjectCode(mtd)) {
		if(IS_KonohaCode(DP(mtd)->kcode)) {
			knh_opline_t *pc = SP(mtd)->pc_start;
			while(1) {
				knh_opcode_dump(ctx, pc, w, SP(mtd)->pc_start);
				if(pc->opcode == OPCODE_RET) break;
				pc++;
			}
		}
	}
}

/* ------------------------------------------------------------------------ */
//## method void Script.%dump();

static METHOD Script__dump(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_t *w = sfp[0].w;
	knh_Script_t *o = sfp[1].scr;
	const knh_ClassTBL_t *t = O_cTBL(o);
	size_t i;
	for(i = 0; i < t->fsize; i++) {
		knh_fields_t *cf = t->fields + i;
		if(cf->type == TYPE_void) continue;
		{
			knh_type_t type = knh_type_tocid(ctx, cf->type, t->cid);
			knh_printf(ctx, w, "[%d] %T %s=", i, type, FN__(cf->fn));
			knh_write_ObjectField(ctx, w, o->fields, i, type, MN__k);
			knh_write_EOL(ctx, w);
		}
	}
}

/* ------------------------------------------------------------------------ */
//## method void Exception.%dump();

static METHOD Exception__dump(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Exception_t *e = sfp[1].e;
	knh_OutputStream_t *w = sfp[0].w;
	knh_write_EOL(ctx, w);
	if(DP(e)->uline != 0) {
		knh_write_uline(ctx, w, DP(e)->uline);
	}
	{
		knh_bytes_t emsg = S_tobytes(DP(e)->event);
		knh_bytes_t msg = S_tobytes(DP(e)->msg);
		const char *fmt = (DP(e)->eid <= 1) ? "%B: %B" : "%BException: %B";
		knh_printf(ctx, w, fmt, emsg, msg);
	}
	if(DP(e)->tracesNULL != NULL) {
		knh_Array_t *a = DP(e)->tracesNULL;
		size_t i, size = knh_Array_size(a), c = 0;
		knh_bytes_t prev = STEXT("?");
		for(i = 0; i < size; i++) {
			knh_String_t *s = a->strings[i];
			if(S_startsWith(s, prev)) {
				c++; continue;
			}
			if(c > 0) {
				knh_write_EOL(ctx, w);
				knh_printf(ctx, w, "  *** called %d times recursively ***", c);
				c = 0;
			}
			knh_write_EOL(ctx, w);
			knh_printf(ctx, w, "  at %s", S_tochar(s));
			prev = S_tobytes(s);
			prev = knh_bytes_first(prev, knh_bytes_rindex(prev, '('));
		}
	}
	knh_write_EOL(ctx, w);
}

/* ------------------------------------------------------------------------ */
//## method void Object.%p();

static METHOD Object__p(CTX ctx, knh_sfp_t *sfp _RIX)
{
	void *p = NULL;
	if(IS_bInt(sfp[1].o) || IS_bFloat(sfp[1].o)) {
		p = (void*)(&sfp[1] + sizeof(void*));
	}
	else if(IS_Boolean(sfp[1].o)) {
		p = (sfp[1].bvalue) ? (void*)(KNH_TRUE) : (void*)(KNH_FALSE);
	}
	else if(IS_NOTNULL(sfp[1].o)) {
		p = (void*)sfp[1].o;
	}
	knh_write__p(ctx, sfp[0].w, p);
}

/* ------------------------------------------------------------------------ */
//## method void Int.%c();

static METHOD Int__c(CTX ctx, knh_sfp_t *sfp _RIX)
{
	char buf[16];
	knh_uint_t c = (knh_uint_t) sfp[1].ivalue;
	knh_format_utf8(buf, sizeof(buf), c);
	knh_write(ctx, sfp[0].w, B(buf));
}

/* ------------------------------------------------------------------------ */
/* [number] */

/* ------------------------------------------------------------------------ */
//## method void Int.%u();

static METHOD Int__u(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_ifmt(ctx, sfp[0].w, K_UINT_FMT, sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## method void Int.%f();

static METHOD Int__f(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_ffmt(ctx, sfp[0].w, K_FLOAT_FMT, (knh_float_t)sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */
//## method void Int.%x();

static METHOD Int__x(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_ifmt(ctx, sfp[0].w, K_INT_XFMT, sfp[1].ivalue);
}

/* ------------------------------------------------------------------------ */

static void knh_write_bits(CTX ctx, knh_OutputStream_t *w, knh_uint64_t n, size_t bits)
{
	size_t i;
	knh_uint64_t flag = 1ULL << (bits - 1);
	for(i = 0; i < bits; i++) {
		if(i > 0 && i % 8 == 0) {
			knh_putc(ctx, w, ' ');
		}
		if((flag & n) == flag) {
			knh_putc(ctx, w, '1');
		}else{
			knh_putc(ctx, w, '0');
		}
		flag = flag >> 1;
	}
}

/* ------------------------------------------------------------------------ */
//## method void Int.%bits();

static METHOD Int__bits(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_bits(ctx, sfp[0].w, sfp[1].ivalue, sizeof(knh_int_t) * 8);
}

/* ------------------------------------------------------------------------ */
//## method void Float.%d();

static METHOD Float__d(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_ifmt(ctx, sfp[0].w, K_INT_FMT, (knh_int_t)sfp[1].fvalue);
}

/* ------------------------------------------------------------------------ */
//## method void Float.%bits();

static METHOD Float__bits(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_write_bits(ctx, sfp[0].w, sfp[1].ndata, sizeof(knh_float_t) * 8);
}

#endif/* K_USING_DEFAULTAPI*/

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
