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

static void knh_write_ctext(CTX ctx, knh_OutputStream_t *w, const char *msg)
{
	knh_write_text(ctx, w, TERM_BBOLD(ctx));
	knh_write_text(ctx, w, msg);
	knh_write_text(ctx, w, TERM_EBOLD(ctx));
	knh_write_EOL(ctx, w);
}

static void ClassNAME_man(CTX ctx, knh_OutputStream_t *w, const knh_ClassTBL_t *ct)
{
	knh_write_ctext(ctx, w, _("CLASS"));
	knh_write_TAB(ctx, w);
	knh_write_cid(ctx, w, ct->cid);
	knh_write_EOL(ctx, w);

	while(ct->supcid != CLASS_Object) {
		knh_class_t cid = ct->supcid;
		knh_write_TAB(ctx, w);
		knh_write_text(ctx, w, _("extends "));
		knh_write_cid(ctx, w, cid);
		knh_write_EOL(ctx, w);
		ct = ct->supTBL;
	}
	knh_write_EOL(ctx, w);
}

static void ClassCONST_man(CTX ctx, knh_OutputStream_t *w, const knh_ClassTBL_t *ct, knh_NameSpace_t *ns)
{
	knh_DictMap_t *tcmap = ct->constDictCaseMapNULL;
	size_t i, size = knh_DictMap_size(tcmap);
	int hasCaption = 0;
	for(i = 0; i < size; i++) {
		if(!hasCaption) {
			knh_write_ctext(ctx, w, _("CONST"));
			hasCaption = 1;
		}
		knh_printf(ctx, w, "\t%s.%s: %O\n", S_tochar(ct->sname), S_tochar(knh_DictMap_keyAt(tcmap, i)), knh_DictMap_valueAt(tcmap, i));
	}
	if(hasCaption == 1) {
		knh_write_EOL(ctx, w);
	}
}

static char *MNOP__(knh_methodn_t mn)
{
	switch(mn) {
	case MN_opNOT: return "!x";
	case MN_opOF: return "x instanceof T";

	case MN_opHAS:  return "y in x";
	case MN_opIS:  return "x is y";
//	case MN_opAs:  return "x as y";
//	case MN_opInto:  return "x into y";

	case MN_opEQ:  return "x == y";
	case MN_opNOTEQ:  return "x != y";
	case MN_opLT:  return "x < y";
	case MN_opLTE:  return "x <= y";
	case MN_opGT:  return "x > y";
	case MN_opGTE:  return "x >= y";

	case MN_opLSFT:  return "x << y";
	case MN_opSEND:  return "x << y";
	case MN_opRSFT:  return "x >> y";

	case MN_opMOD:  return "x mod y";

	case MN_opADD:  return "x + y";
	case MN_opNEG:  return "-x";
	case MN_opSUB:  return "x - y";
	case MN_opDIV:  return "x / y";
	case MN_opMUL:  return "x * y";

	case MN_opLOR:        return "x & y";
	case MN_opLAND:       return "x | y";
	case MN_opLNOT:       return "~x";
	case MN_opLXOR:        return "x ^ y";
	case MN_opNEXT:       return "x++";
	case MN_opPREV:       return "x--";
	case MN_opITR:        return "x..";
	case MN_getSize:      return "|x|";
	case MN_get:          return "x[n]";
	case MN_set:          return "x[n]=y";
	case MN_setAll:       return "x[]=y";
	case MN_opTO:    return "x[m to n]";
	case MN_opUNTIL: return "x[m until n]";
	}
	return NULL;
}

static void ClassOP_man(CTX ctx, knh_OutputStream_t *w, const knh_ClassTBL_t *ct, knh_NameSpace_t *ns)
{
	size_t i, cnt = 0, hasCaption = 0;
	knh_Array_t *a = ct->methods;
	int isBOL = 1;
	char buf[40];
	for(i = 0; i < knh_Array_size(a); i++) {
		knh_Method_t *mtd = a->methods[i];
		char *op = MNOP__(SP(mtd)->mn);
		if(op == NULL) continue;
		if(hasCaption == 0) {
			knh_write_ctext(ctx, w, _("OPERATOR"));
			hasCaption = 1;
		}
		if(isBOL == 1) {
			knh_write_TAB(ctx, w);
			isBOL = 0;
		}
		knh_snprintf(buf, sizeof(buf), "%-14s", op);
		knh_write_text(ctx, w, buf);
		if(cnt % 5 == 4) {
			knh_write_EOL(ctx, w);
			isBOL = 1;
		}
		cnt++;
	}
	if(isBOL != 1) {
		knh_write_EOL(ctx, w);
	}
	if(hasCaption == 1) {
		knh_write_EOL(ctx, w);
	}
}

static void knh_write_Method(CTX ctx, knh_OutputStream_t *w, const knh_ClassTBL_t *ct, knh_Method_t *o)
{
	knh_write_TAB(ctx, w);
	if(Method_isAbstract(o)) {
		knh_write_text(ctx, w, "@Abstract ");
	}
	knh_write_type(ctx, w, knh_type_tocid(ctx, knh_ParamArray_rtype(DP(o)->mp), ct->cid));
	knh_putc(ctx, w, ' ');
	if(Method_isStatic(o)) {
		knh_write_text(ctx, w, S_tochar(ct->sname));
		knh_putc(ctx, w, '.');
	}
	knh_write_mn(ctx, w, SP(o)->mn);
	knh_putc(ctx, w, '(');
	size_t i;
	for(i = 0; i < knh_Method_psize(o); i++) {
		knh_param_t *p = knh_ParamArray_get(DP(o)->mp, i);
		if(i > 0) {
			knh_write_delim(ctx, w);
		}
		knh_write_type(ctx, w, knh_type_tocid(ctx, p->type, ct->cid));
		knh_putc(ctx, w, ' ');
		knh_write(ctx, w, B(FN__(p->fn)));
	}
	if(ParamArray_isVARGs(DP(o)->mp)) {
		knh_write_delim(ctx, w);
		knh_write_dots(ctx, w);
	}
	knh_putc(ctx, w, ')');
	knh_write_EOL(ctx, w);
}

static void ClassMETHOD_man(CTX ctx, knh_OutputStream_t *w, const knh_ClassTBL_t *ct, knh_NameSpace_t *ns)
{
	size_t i, cnt = 0, hasCaption = 0;
	knh_Array_t *a = ct->methods;
	for(i = 0; i < knh_Array_size(a); i++) {
		knh_Method_t *mtd = a->methods[i];
		if(mtd->mn < MN_OPSIZE) continue;
		if(MN_isFMT(mtd->mn)) continue;
		if(Method_isHidden(mtd) && !knh_isSystemVerbose()) continue;
		if(hasCaption == 0) {
			knh_write_ctext(ctx, w, _("METHOD"));
			hasCaption = 1;
		}
		knh_write_Method(ctx, w, ct, mtd);
		cnt++;
	}
	if(hasCaption == 1) {
		knh_write_EOL(ctx, w);
	}
}

static void ClassFMT_man(CTX ctx, knh_OutputStream_t *w, const knh_ClassTBL_t *ct, knh_NameSpace_t *ns)
{
	size_t i, cnt = 0, hasCaption = 0;
	knh_Array_t *a = ct->methods;
	for(i = 0; i < knh_Array_size(a); i++) {
		knh_Method_t *mtd = a->methods[i];
		if(!MN_isFMT(mtd->mn)) continue;
		if(hasCaption == 0) {
			knh_write_ctext(ctx, w, _("FORMAT"));
			hasCaption = 1;
		}
		knh_write_TAB(ctx, w);
		knh_write_mn(ctx, w, mtd->mn);
		knh_write_EOL(ctx, w);
		cnt++;
	}
	if(hasCaption == 1) {
		knh_write_EOL(ctx, w);
	}
}

static void ClassTYPEMAP_man(CTX ctx, knh_OutputStream_t *w, const knh_ClassTBL_t *ct, knh_NameSpace_t *ns)
{
	size_t i;
	int hasCaption = 0;
	knh_Array_t *tmaps = ct->tmaps;
	for(i = 0; i < tmaps->size; i++) {
		if(hasCaption == 0) {
			knh_write_ctext(ctx, w, _("TYPEMAP"));
			hasCaption = 1;
		}
		knh_TypeMap_t *mpr = tmaps->trans[i];
		knh_write_TAB(ctx, w); /*knh_write_TAB(ctx, w);*/
		if(TypeMap_isInterface(mpr)) {
			knh_write_text(ctx, w, "interface ");
		}
		else {
			knh_write_text(ctx, w, "to ");
		}
		knh_write_cid(ctx, w, SP(mpr)->tcid);
		if(!TypeMap_isTotal(mpr)) {
			knh_write_text(ctx, w, "or null");
		}
		knh_write_EOL(ctx, w);
	}
	if(hasCaption == 1) {
		knh_write_EOL(ctx, w);
	}
}

/* ------------------------------------------------------------------------ */
//## @Static method void Script.man(Object c, NameSpace ns);

static METHOD Script_man(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_OutputStream_t *w = KNH_STDOUT;
	const knh_ClassTBL_t *ct = O_cTBL(sfp[1].o);
	knh_NameSpace_t *ns = sfp[2].ns;
	if(IS_Class(sfp[1].o)) {
		ct = ClassTBL(((knh_Class_t*)sfp[1].o)->cid);
	}
	ClassNAME_man(ctx, w, ct);
	if(!class_isPrivate(ct->cid)) {
		if(ct->constDictCaseMapNULL != NULL) {
			ClassCONST_man(ctx, w, ct, ns);
		}
		ClassOP_man(ctx, w, ct, ns);
		ClassMETHOD_man(ctx, w, ct, ns);
		ClassFMT_man(ctx, w, ct, ns);
		ClassTYPEMAP_man(ctx, w, ct, ns);
	}
}

/* ------------------------------------------------------------------------ */


/* ------------------------------------------------------------------------ */
//## @Static @Audit method String System.exec(String cmd, Class reqt);

static METHOD System_exec(CTX ctx, knh_sfp_t *sfp _RIX)
{
#ifdef K_DEOS_TRACE
	char cmd[1024];
	knh_snprintf(cmd, sizeof(cmd), "%s=%s %s", K_DEOS_TRACE, ctx->trace, S_tochar(sfp[1].s));
#else
	const char *cmd = S_tochar(sfp[1].s);
#endif
	KNH_SYSLOG(ctx, LOG_NOTICE, "fork", "command='%s'", cmd);
#ifdef K_USING_POSIX_
	FILE *fp = popen((const char*)cmd, "r+");
	if(fp != NULL) {
		knh_cwb_t cwbbuf, *cwb = knh_cwb_open(ctx, &cwbbuf);
		char buf[K_PAGESIZE];
		while(1) {
			size_t size = fread(buf, 1, sizeof(buf), fp);
			if(size > 0) {
				knh_bytes_t t = {{buf}, size};
				knh_Bytes_write(ctx, cwb->ba, t);
			}
			else {
				break;
			}
		};
		pclose(fp);
		RETURN_(knh_cwb_newString(ctx, cwb));
	}
	else {
		KNH_SYSLOG(ctx, LOG_ERR, "Failed", "command='%s'", cmd);
	}
#endif
	RETURN_(KNH_NULVAL(CLASS_String));
}

///* ------------------------------------------------------------------------ */
////## @Static @Audit method void Script.join();
//
//static METHOD Script_join(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//
//}

/* ------------------------------------------------------------------------ */

#endif/* K_USING_DEFAULTAPI*/

#ifdef __cplusplus
}
#endif
