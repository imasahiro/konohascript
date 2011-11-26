/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c)  2010-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * See www.konohaware.org/license.html for further information.
 *
 * (1) GNU Lesser General Public License 3.0 (with KONOHA_UNDER_LGPL3)
 * (2) Konoha Software Foundation License 1.0
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

// **************************************************************************
// LIST OF CONTRIBUTERS
//  kimio - Kimio Kuramitsu, Yokohama National University, Japan
//
// **************************************************************************

#define K_INTERNAL
#include <konoha1.h>
#include <konoha1/konohalang.h>

#ifdef __cplusplus 
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* [man]*/

static void knh_write_ctext(CTX ctx, kOutputStream *w, const char *msg)
{
//	knh_write_ascii(ctx, w, TERM_BBOLD(ctx));
	knh_write_ascii(ctx, w, msg);
//	knh_write_ascii(ctx, w, TERM_EBOLD(ctx));
	knh_write_EOL(ctx, w);
}

static void ClassNAME_man(CTX ctx, kOutputStream *w, const knh_ClassTBL_t *ct)
{
	knh_write_ctext(ctx, w, _("CLASS"));
	knh_write_TAB(ctx, w);
	knh_write_cid(ctx, w, ct->cid);
	knh_write_EOL(ctx, w);

	while(ct->supcid != CLASS_Object) {
		kclass_t cid = ct->supcid;
		knh_write_TAB(ctx, w);
		knh_write_ascii(ctx, w, _("extends "));
		knh_write_cid(ctx, w, cid);
		knh_write_EOL(ctx, w);
		ct = ct->supTBL;
	}
	knh_write_EOL(ctx, w);
}

static void ClassCONST_man(CTX ctx, kOutputStream *w, const knh_ClassTBL_t *ct, kNameSpace *ns)
{
	kDictMap *tcmap = ct->constDictCaseMapNULL;
	size_t i, size = knh_Map_size(tcmap);
	int hasCaption = 0;
	for(i = 0; i < size; i++) {
		if(!hasCaption) {
			knh_write_ctext(ctx, w, _("CONST"));
			hasCaption = 1;
		}
		knh_printf(ctx, w, "\t%s.%s: %O\n", S_totext(ct->sname), S_totext(knh_DictMap_keyAt(tcmap, i)), knh_DictMap_valueAt(tcmap, i));
	}
	if(hasCaption == 1) {
		knh_write_EOL(ctx, w);
	}
}

static const char *MNOP__(kmethodn_t mn)
{
	switch(mn) {
	case MN_opNOT: return "!x";
	case MN_opOF: return "x <: T";

	case MN_opHAS:  return "y in? x";
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
	case MN_send:  return "x <<< y";
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
	case MN_opUNTIL: return "x[m : n]";
	}
	return NULL;
}

static void ClassOP_man(CTX ctx, kOutputStream *w, const knh_ClassTBL_t *ct, kNameSpace *ns)
{
	size_t i, cnt = 0, hasCaption = 0;
	kArray *a = ct->methods;
	int isBOL = 1;
	char buf[40];
	for(i = 0; i < knh_Array_size(a); i++) {
		kMethod *mtd = a->methods[i];
		const char *op = MNOP__(SP(mtd)->mn);
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
		knh_write_ascii(ctx, w, buf);
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

static void knh_write_Method(CTX ctx, kOutputStream *w, const knh_ClassTBL_t *ct, kMethod *o)
{
	knh_write_TAB(ctx, w);
	if(Method_isAbstract(o)) {
		knh_write_ascii(ctx, w, "@Abstract ");
	}
	knh_write_type(ctx, w, ktype_tocid(ctx, knh_Param_rtype(DP(o)->mp), ct->cid));
	knh_putc(ctx, w, ' ');
	if(Method_isStatic(o)) {
		knh_write_ascii(ctx, w, S_totext(ct->sname));
		knh_putc(ctx, w, '.');
	}
	knh_write_mn(ctx, w, SP(o)->mn);
	knh_putc(ctx, w, '(');
	size_t i;
	for(i = 0; i < knh_Method_psize(o); i++) {
		kparam_t *p = knh_Param_get(DP(o)->mp, i);
		if(i > 0) {
			knh_write_delim(ctx, w);
		}
		knh_write_type(ctx, w, ktype_tocid(ctx, p->type, ct->cid));
		knh_putc(ctx, w, ' ');
		knh_write_ascii(ctx, w, FN__(p->fn));
	}
	if(Param_isVARGs(DP(o)->mp)) {
		knh_write_delim(ctx, w);
		knh_write_dots(ctx, w);
	}
	knh_putc(ctx, w, ')');
	knh_write_EOL(ctx, w);
}

static void ClassMETHOD_man(CTX ctx, kOutputStream *w, const knh_ClassTBL_t *ct, kNameSpace *ns)
{
	size_t i, cnt = 0, hasCaption = 0;
	kArray *a = ct->methods;
	for(i = 0; i < knh_Array_size(a); i++) {
		kMethod *mtd = a->methods[i];
		if(mtd->mn < MN_OPSIZE) continue;
		if(MN_isFMT(mtd->mn)) continue;
		if(Method_isHidden(mtd) && !knh_isVerbose()) continue;
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

static void ClassFMT_man(CTX ctx, kOutputStream *w, const knh_ClassTBL_t *ct, kNameSpace *ns)
{
	size_t i, cnt = 0, hasCaption = 0;
	kArray *a = ct->methods;
	for(i = 0; i < knh_Array_size(a); i++) {
		kMethod *mtd = a->methods[i];
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

static void ClassTYPEMAP_man(CTX ctx, kOutputStream *w, const knh_ClassTBL_t *ct, kNameSpace *ns)
{
	size_t i;
	int hasCaption = 0;
	kArray *typemaps = ct->typemaps;
	for(i = 0; i < typemaps->size; i++) {
		if(hasCaption == 0) {
			knh_write_ctext(ctx, w, _("TYPEMAP"));
			hasCaption = 1;
		}
		kTypeMap *mpr = typemaps->trans[i];
		knh_write_TAB(ctx, w); /*knh_write_TAB(ctx, w);*/
		if(TypeMap_isInterface(mpr)) {
			knh_write_ascii(ctx, w, "interface ");
		}
		else {
			knh_write_ascii(ctx, w, "to ");
		}
		knh_write_cid(ctx, w, SP(mpr)->tcid);
		knh_write_EOL(ctx, w);
	}
	if(hasCaption == 1) {
		knh_write_EOL(ctx, w);
	}
}
static void _System_man(CTX ctx, const knh_ClassTBL_t *ct, kNameSpace *ns)
{
	kOutputStream *w = KNH_STDOUT;
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

//## @Static method void System.man(Object c, NameSpace ns);
KMETHOD System_man(CTX ctx, ksfp_t *sfp _RIX)
{
	const knh_ClassTBL_t *ct = O_cTBL(sfp[1].o);
	kNameSpace *ns = sfp[2].ns;
	if(IS_Class(sfp[1].o)) {
		ct = ClassTBL(((kClass*)sfp[1].o)->cid);
	}
	_System_man(ctx, ct, ns);
}

/* ------------------------------------------------------------------------ */

#ifdef _SETUP
DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_LoaderAPI_t *kapi)
{
	RETURN_PKGINFO("konoha.i");
}
#endif


#ifdef __cplusplus
}
#endif

