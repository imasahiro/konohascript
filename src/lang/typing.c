/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us
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

#define USE_cwb_open          1
#define USE_cwb_size          1

#include"commons.h"

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */

#define STT_DECLFIELD  STT_DECL
#define STT_DECLSCRIPT STT_DECL

static knh_gint_t GammaBuilder_espidx(CTX ctx)
{
	return 	DP(ctx->gma)->gsize - DP(ctx->gma)->fvarsize;
}

#define BEGIN_BLOCK(STMT, X) knh_gint_t X = GammaBuilder_espidx(ctx);

#define END_BLOCK(STMT, X) \
	if(GammaBuilder_espidx(ctx) > X) {\
		GammaBuilder_clear(ctx, (DP(ctx->gma)->gsize - GammaBuilder_espidx(ctx) + X), STMT);\
	}\

#define _TINFER      0        // for readability
#define _NOWARN      1
#define _NOVOID      (1<<1)
#define _ALLOWVAR    (1<<2)
#define _NOCHECK     (1<<3)
#define _BCHECK      (1<<4)
#define _BOX         (1<<5)
#define _NOBOX       (1<<6)
#define _NOCAST      (1<<7)
#define _ITRCAST     (1<<8)
#define _COERCION    (1<<9)
#define _CONSTASIS   (1<<10)
#define _CONSTONLY   (1<<11)

#define TYPING(ctx, stmt, n, reqt, mode) {\
		kTerm *tkRES_ = Tn_typing(ctx, stmt, n, reqt, mode); \
		if(TT_(tkRES_) == TT_ERR) return tkRES_;\
	}\

// _NOCAST is necessary to prevent from ## dyn v; if(v) ...
#define TYPING_Condition(ctx, stmt, n) { \
		kTerm *tkRES_ = Tn_typing(ctx, stmt, n, TYPE_Boolean, _NOVOID);\
		if(TT_(tkRES_) == TT_ERR) return tkRES_;\
	}\

#define TYPING_UntypedObject(ctx, stmt, n) { \
		kTerm *tkRES_ = Tn_typing(ctx, stmt, n, TYPE_Object, _NOVOID|_BOX);\
		if(TT_(tkRES_) == TT_ERR) return tkRES_;\
	}\

#define TYPING_TypedObject(ctx, stmt, n, reqt) { \
		kTerm *tkRES_ = Tn_typing(ctx, stmt, n, reqt, _NOVOID|_BOX);\
		if(TT_(tkRES_) == TT_ERR) return tkRES_;\
	}\

#define TYPING_UntypedExpr(ctx, stmt, n) { \
		kTerm *tkRES_ = Tn_typing(ctx, stmt, n, TYPE_var, _NOVOID);\
		if(TT_(tkRES_) == TT_ERR) return tkRES_;\
	}\

#define TYPING_TypedExpr(ctx, stmt, n, reqt) { \
		kTerm *tkRES_ = Tn_typing(ctx, stmt, n, reqt, _NOVOID);\
		if(TT_(tkRES_) == TT_ERR) return tkRES_;\
	}\

static inline void Stmt_toSTT(kStmtExpr *stmt, kterm_t stt)
{
	DBG_ASSERT(stt < TT_PRAGMA);
	DP(stmt)->flag0 = 0;
	STT_(stmt) = stt;
}

static inline kTerm *Stmt_typed(CTX ctx, kStmtExpr *stmt, ktype_t type)
{
	SP(stmt)->type = type;
	return (kTerm*)stmt;
}

static kTerm *new_StmtBOX(CTX ctx, kTerm *tk, ktype_t reqt)
{
	kStmtExpr *stmt = new_Stmt2(ctx, STT_BOX, tk, NULL);
	return Stmt_typed(ctx, stmt, reqt);
}

static void Stmt_boxAll(CTX ctx, kStmtExpr *stmt, size_t s, size_t e, ktype_t reqt)
{
	size_t i;
	for(i = s; i < e; i++) {
		kclass_t bcid = C_bcid(Tn_cid(stmt, i));
		if(bcid == CLASS_Int || bcid == CLASS_Float || bcid == CLASS_Boolean) {
			if(TT_(tkNN(stmt, i)) == TT_CONST) {
				tkNN(stmt, i)->type = reqt;  // re-typing as boxed value
			}
			else {
				KNH_SETv(ctx, stmtNN(stmt, i), new_StmtBOX(ctx, tkNN(stmt, i), reqt/*Tn_cid(stmt, i)*/));
			}
		}
	}
}

static kTerm* TERROR_Stmt(CTX ctx, kStmtExpr *stmt, size_t n, ktype_t reqt)
{
	kTerm *tkERR = NULL;
	ktype_t type = TYPE_void;
	if(n < DP(stmt)->size) {
		type = Tn_type(stmt, n);
	}
	else {
		DBG_P("!! n < DP(stmt)->size: n=%d, DP(stmt)->size=%d", n, DP(stmt)->size);
	}
	switch(SP(stmt)->stt) {
	case STT_NEW:
	case STT_FUNCCALL:
	case STT_CALL:
	case STT_OPR:
	{
		kMethod *mtd = (tkNN(stmt, 0))->mtd;
		tkERR = TypeErrorCallParam(ctx, n-1, mtd, reqt, type);
		break;
	}
	case STT_LET:
	case STT_DECL:
		tkERR = TERROR_Term(ctx, tkNN(stmt, 1), type, reqt);
		break;
	default :
		tkERR = TypeErrorStmtNN(ctx, stmt, n, reqt, type);
		break;
	}
	DBG_ASSERT(tkERR == NULL); // always check if K_USING_DEBUG_
	return tkERR;
}

#define ERROR_IF(c)     if(c)  goto L_ERROR;
#define PERROR_IF(c)    if(c)  goto L_PERROR;

static kTerm *Term_typing(CTX ctx, kTerm *tk, ktype_t tcid);
static kTerm *Stmt_typing(CTX ctx, kStmtExpr *stmt, int needsReturn);
static kTerm *CALL_typing(CTX ctx, kStmtExpr *stmt, kclass_t tcid);
static kTerm *EXPR_typing(CTX ctx, kStmtExpr *stmt, kclass_t tcid);
static kTerm* CALLPARAMs_typing(CTX ctx, kStmtExpr *stmt, ktype_t tcid, kclass_t new_cid, kMethod *mtd);

static kTerm *new_TermDYNCAST(CTX ctx, kclass_t tcid, kmethodn_t mn, kTerm *tkO);
static kTerm *new_TermTCAST(CTX ctx, kclass_t tcid, kTypeMap *mpr, kTerm *tkO);

kTerm* Tn_typing(CTX ctx, kStmtExpr *stmt, size_t n, ktype_t reqt, kflag_t opflag)
{
	kflag_t flagorig = DP(ctx->gma)->flag;
	kTerm *tk = tkNN(stmt, n), *tkRES = NULL;
	ktype_t vart = TYPE_void;
	DBG_ASSERT(STT_(stmt) != STT_ERR);
	if(FLAG_is(opflag, _NOWARN)) {
		DBG_P("@@ NOWARN stt=%s n=%d, reqt=%s, vart=%s", TT__(SP(stmt)->stt), (int)n, TYPE__(reqt), TYPE__(vart));
		GammaBuilder_setQuiet(ctx->gma, 1);
	}
	if(!(n < DP(stmt)->size)) {
		goto L_PERROR;
	}
	tkRES = IS_Term(tk) ? Term_typing(ctx, tk, reqt) : EXPR_typing(ctx, stmtNN(stmt, n), reqt);
	if(tk != tkRES) {
		KNH_SETv(ctx, tmNN(stmt, n), tkRES);
	}
	if(TT_(tkRES) == TT_ERR) goto L_PERROR;
	vart = Tn_type(stmt, n);
	//DBG_P("@@ stt=%s n=%d, reqt=%s, vart=%s", TT__(SP(stmt)->stt), (int)n, TYPE__(reqt), TYPE__(vart));
	if(vart == TYPE_void && FLAG_is(opflag, _NOVOID)) {
		goto L_PERROR;
	}
	if(vart == TYPE_var && !(FLAG_is(opflag, _ALLOWVAR)))  {
		tkRES = ERROR_MustBe(ctx, "statically typed", TT__(TT_(tmNN(stmt, n))));
		goto L_PERROR;
	}
	if(FLAG_is(opflag, _NOCHECK)) {
		DBG_P("NOCHECK stt=%s n=%d, reqt=%s, vart=%s", TT__(SP(stmt)->stt), (int)n, TYPE__(reqt), TYPE__(vart));
		goto L_RETURN;
	}
	if(FLAG_is(opflag, _BCHECK)) {
		if(C_bcid(CLASS_t(vart)) == reqt) goto L_RETURN;
		tkRES = NULL;
	}
	else { 	/*TYPECHECK*/
		if(reqt == TYPE_void) goto L_RETURN;
		if(reqt == vart || reqt == TYPE_var || reqt == TYPE_dyn || reqt == TYPE_Object || class_isa(vart, reqt)) {
			if(IS_Tunbox(vart)) {
				if(FLAG_is(opflag, _BOX) || reqt == TYPE_Object || reqt == TYPE_Number || reqt == TYPE_dyn) {
					Stmt_boxAll(ctx, stmt, n, n+1, reqt);
				}
			}
			goto L_RETURN;
		}
		tkRES = NULL;
	}
	if(FLAG_is(opflag, _ITRCAST)) {

	}
	if(!FLAG_is(opflag, _NOCAST)) {
		if(vart == TYPE_dyn) {
			KNH_SETv(ctx, tmNN(stmt, n), new_TermDYNCAST(ctx, reqt, MN_typeCheck, tkNN(stmt, n)));
			goto L_RETURN;
		}
		else {
			kTypeMap *tmr = knh_findTypeMapNULL(ctx, vart, reqt);
			if(tmr != NULL) {
				int isCOERCION = (!!(FLAG_is(opflag, _COERCION))) || (!!(TypeMap_isSemantic(tmr)));
				DBG_P("reqt=%s, vart=%s isSemantic=%d, isConst=%d", TYPE__(reqt), TYPE__(vart), isCOERCION, TypeMap_isConst(tmr));
				if(isCOERCION) {
					KNH_SETv(ctx, tmNN(stmt, n), new_TermTCAST(ctx, reqt, tmr, tkNN(stmt, n)));
					goto L_RETURN;
				}
			}
		}
	}

	L_PERROR:;
	DBG_P("stt=%s n=%d, reqt=%s, vart=%s", TT__(SP(stmt)->stt), (int)n, TYPE__(reqt), TYPE__(vart));
	if(tkRES == NULL) {
		DP(ctx->gma)->flag |= flagorig;
		return TERROR_Stmt(ctx, stmt, n, reqt);
	}

	L_RETURN:;
	DP(ctx->gma)->flag |= flagorig;
	if(tkRES == NULL) {
		tkRES = tkNN(stmt, n);
	}
	if(FLAG_is(opflag, _CONSTASIS)) {
		kterm_t tt = TT_(tkRES);
		if(tt != TT_ASIS && tt != TT_CONST && tt != TT_NULL) {
			tkRES = ERROR_MustBe(ctx, "a constant value", NULL/*TT__(tkNN(stmt, n)->tt)*/);
		}
	}
	else if(FLAG_is(opflag, _CONSTONLY)) {
		kterm_t tt = TT_(tkRES);
		if(tt != TT_CONST && tt != TT_NULL) {
			tkRES = ERROR_MustBe(ctx, "a constant value", NULL/*TT__(tkNN(stmt, n)->tt)*/);
		}
	}
	return tkRES;
}

/* ----------------------------------------------------------------------- */

//#define CONSTPOOL(v)   knh_getConstPools(ctx, v)

#define _FREADONLY   FLAG_Field_ReadOnly
#define _FGETTER     FLAG_Field_Getter
#define _FSETTER     FLAG_Field_Setter
#define _FKEY        FLAG_Field_Key
#define _FREG        (FLAG_Field_Key|FLAG_Field_ReadOnly)
#define _FCHKOUT     FLAG_Field_Hidden

#define IS_SCRIPTLEVEL(ctx)       IS_NULL(DP(ctx->gma)->mtd)

#define GammaBuilder_type(ctx, type)  ktype_tocid(ctx, type, DP(ctx->gma)->this_cid)

/* ----------------------------------------------------------------------- */
/* [Term] */

static kTerm* Term_toCONST(CTX ctx, kTerm *tk)
{
	DBG_ASSERT(IS_Term(tk));
	TT_(tk) = TT_CONST;
	SP(tk)->type = O_cid((tk)->data);
	return tk;
}

#define Term_setCONST(ctx, tk, d)  Term_setCONST_(ctx, tk, UPCAST(d))
static kTerm* Term_setCONST_(CTX ctx, kTerm *tk, dynamic *data)
{
	KNH_SETv(ctx, (tk)->data, data);
	return Term_toCONST(ctx, tk);
}

static kTerm* new_TermCONST_(CTX ctx, dynamic *data)
{
	kTerm *tk = new_(Term);
	Term_setCONST_(ctx, tk, data);
	return tk;
}

static void Term_setMethod(CTX ctx, kTerm *tk, kmethodn_t mn, kMethod *mtd)
{
	TT_(tk) = TT_MN;
	(tk)->mn = mn;
	SP(tk)->type = TYPE_Method;
	if(mtd != NULL) {
		KNH_SETv(ctx, (tk)->data, mtd);
	}
}

kTerm* kTermoCID(CTX ctx, kTerm *tk, kclass_t cid)
{
	TK_typing(tk, TT_CID, CLASS_Class, cid);
	return tk;
}

kTerm* kTermoTYPED(CTX ctx, kTerm *tk, kterm_t tt, ktype_t type, kshort_t nn)
{
	TK_typing(tk, tt, type, nn);
	if(tt == TT_FIELD) {GammaBuilder_foundFIELD(ctx->gma, 1); }
	return tk;
}

kTerm* new_TermTYPED(CTX ctx, kterm_t tt, ktype_t type, kshort_t nn)
{
	kTerm *tk = new_(Term);
	kTermoTYPED(ctx, tk, tt, type, nn);
	return tk;
}

kbool_t StmtMETA_is_(CTX ctx, kStmtExpr *stmt, kbytes_t name)
{
	if(IS_Map(DP(stmt)->metaDictCaseMap)) {
		Object *v = knh_DictMap_getNULL(ctx, DP(stmt)->metaDictCaseMap, name);
		if(v != NULL) return 1;
	}
	return 0;
}

#define Stmt_insert(ctx, stmt, n, tm)   Stmt_insert_(ctx, stmt, n, (kTerm*)(tm))

static void Stmt_insert_(CTX ctx, kStmtExpr *stmt, size_t n, kTerm *tm)
{
	size_t i = DP(stmt)->size;
	DBG_ASSERT(n <= DP(stmt)->size);
	knh_Stmt_add_(ctx, stmt, tm, NULL); // DP(o)->size++;
	for(; n < i ; i--) {
		knh_Stmt_swap(ctx, stmt, i - 1, i);
	}
}

/* ------------------------------------------------------------------------ */

#define Term_fn(ctx, tk) FN_UNMASK(Term_fnq(ctx, tk))

ksymbol_t Term_fnq(CTX ctx, kTerm *tk)
{
	ksymbol_t fn = FN_;
	if(TT_(tk) == TT_NAME || TT_(tk) == TT_UNAME) {
		fn = knh_getfnq(ctx, TK_tobytes(tk), FN_NEWID);
	}
	return fn;
}

static kmethodn_t Term_mn(CTX ctx, kTerm *tk)
{
	if(TT_(tk) == TT_FUNCNAME || TT_(tk) == TT_NAME || TT_(tk) == TT_UNAME || TT_(tk) == TT_UFUNCNAME) {
		TT_(tk) = TT_MN;
		(tk)->mn = knh_getmn(ctx, TK_tobytes(tk), MN_NEWID);
	}
	if(TT_(tk) == TT_NEW) {
		TT_(tk) = TT_MN;
		(tk)->mn = knh_getmn(ctx, TK_tobytes(tk), MN_NEWID);
	}
	DBG_ASSERT(TT_(tk) == TT_MN);
	if(Term_isISBOOL(tk)) {
		(tk)->mn = MN_toISBOOL(MN_toFN((tk)->mn));
		Term_setISBOOL(tk, 0);
	}
	else if(Term_isGetter(tk)) {
		(tk)->mn = MN_toGETTER(MN_toFN((tk)->mn));
		Term_setGetter(tk, 0);
	}
	else if(Term_isSetter(tk)) {
		(tk)->mn = MN_toSETTER(MN_toFN((tk)->mn));
		Term_setSetter(tk, 0);
	}
	return (tk)->mn;
}

static kclass_t TermPTYPE_cid(CTX ctx, kTerm *tk, kclass_t bcid)
{
	BEGIN_LOCAL(ctx, lsfp, 1);
	kclass_t cid = bcid;
	LOCAL_NEW(ctx, lsfp, 0, kParam*, pa, new_Param(ctx));
	kParam *bpa = ClassTBL(bcid)->cparam;
	size_t i;
	int psize = knh_Array_size(tk->list) - 1;
	for(i = 1; i < knh_Array_size((tk)->list); i++) {
		kTerm *tkT = (tk)->list->terms[i];
		if(TT_(tkT) == TT_DARROW) { i++; break; }
		ktype_t ptype = knh_Term_cid(ctx, tkT, CLASS_Tdynamic);
		if(ptype == TYPE_void) continue;
		if(psize == 1 && (bcid == CLASS_Map || bcid == CLASS_Tuple)) {
			knh_Param_addParam(ctx, pa, CLASS_String, FN_k); // Tuple<T> => Tuple<String, T>
		}
		knh_Param_addParam(ctx, pa, ptype, FN_NONAME);
	}
	if(bcid == CLASS_Func) { /* Func<T => T> */
		if(i < knh_Array_size((tk)->list)) {
			kTerm *tkT = tk->list->terms[i];
			knh_Param_addReturnType(ctx, pa, knh_Term_cid(ctx, tkT, CLASS_Tdynamic));
		}
		if(pa->psize == 0 && pa->rsize == 0) {
			cid = CLASS_Func;
			goto L_END;
		}
	}
	if(bcid != CLASS_Func && bcid != CLASS_Tuple) {
		if((pa)->psize != (bpa)->psize || (pa)->rsize != (bpa)->rsize) {
			WARN_WrongTypeParam(ctx, bcid);
			cid = bcid;
			goto L_END;
		}
		for(i = 0; i < (size_t)((pa)->psize + (pa)->rsize); i++) {
			kparam_t* p = knh_Param_get(pa, i);
			kparam_t* bp = knh_Param_get(bpa, i);
			p->fn = bp->fn;
			if(bp->type == TYPE_dyn) continue;
			if(p->type == bp->type) continue;
			kclass_t tcid = ktype_tocid(ctx, p->type, DP(ctx->gma)->this_cid);
			if(!class_isa(tcid, bp->type)) {
				WARN_WrongTypeParam(ctx, bcid);
				cid = bcid;
				goto L_END;
			}
		}
	}
	cid = knh_class_Generics(ctx, bcid, pa);
	L_END:;
	END_LOCAL(ctx, lsfp);
	return cid;
}

kclass_t knh_Term_cid(CTX ctx, kTerm *tk, ktype_t reqt)
{
	kclass_t cid = CLASS_unknown;
	switch(TT_(tk)) {
		case TT_CID : {
			DBG_ASSERT((tk)->cid != CLASS_unknown);
			return (tk)->cid;
		}
		case TT_VAR : case TT_ASIS: {
			if(reqt != TYPE_var) cid = reqt;
			break;
		}
		case TT_VOID: cid = CLASS_Tvoid; break;
		case TT_DYN: cid = CLASS_Tdynamic; break;
		case TT_BYTE: {
			WARN_MuchBetter(ctx, "int", "byte");
			cid = CLASS_Int;
			break;
		}
		case TT_UNAME: case TT_UFUNCNAME: {
			kNameSpace *ns = K_GMANS;
			if(Term_isExceptionType(tk)) {
				(tk)->cid = CLASS_Exception;
				return CLASS_Exception;
			}
			cid = knh_NameSpace_getcid(ctx, ns, TK_tobytes(tk));
			break;
		}
		case TT_TYPEOF: {
			DBG_ASSERT(IS_StmtExpr((tk)->data));
			if(IS_StmtExpr((tk)->data)) {
				kStmtExpr *stmt = (tk)->stmt;
				kTerm *tkRES = Stmt_typing(ctx, stmt, TYPE_var);
				KNH_SETv(ctx, tk->data, tkRES); // TO AVIOD RCGC
				if(TT_(tkRES) == TT_ERR) {
					TT_(tk) = TT_ERR;
					KNH_SETv(ctx, tk->data, tkRES->data);
					tk->uline = tkRES->uline;
				}
				else {
					cid = CLASS_t(tkRES->type);
					DBG_P("typeof(cid=%d,%s)", cid, CLASS__(cid));
				}
			}
			break;
		}
		case TT_PTYPE: {
			DBG_ASSERT(IS_Array((tk)->list));
			kTerm *tkC = tk->list->terms[0];
			kclass_t bcid = knh_Term_cid(ctx, tkC, CLASS_unknown);
			if(bcid != CLASS_unknown && C_isGenerics(bcid)) {
				cid = TermPTYPE_cid(ctx, tk, bcid);
			}
			else {
				WARN_WrongTypeParam(ctx, bcid);  /* @CODE: String<T> // no such generics */
				cid = bcid;
			}
		}
		default : {

		}
	}
	if(cid == CLASS_unknown && reqt != CLASS_unknown) {
		cid = reqt;
		if(reqt != TYPE_var) {
			WarningUnknownClass(ctx, tk, cid);
		}
	}
	if(TT_(tk) != TT_CID && cid != CLASS_unknown) {
		kTermoCID(ctx, tk, cid);
	}
	return cid;
}

static kTerm *TTYPE_typing(CTX ctx, kTerm *tk, ktype_t reqt)
{
	kclass_t cid = knh_Term_cid(ctx, tk, reqt);
	if(cid == CLASS_unknown) {
		return ERROR_Undefined(ctx, "name", CLASS_unknown, tk);
	}
	return tk;
}

/* ------------------------------------------------------------------------ */
/* GammaBuilder */

static void *knh_loadGlueFunc(CTX ctx, const char *funcname, int isVerbose)
{
	void *f = NULL;
	kNameSpace *ns = K_GMANS;
	if(ns->gluehdr != NULL) {
		f = knh_dlsym(ctx, ns->gluehdr, funcname, NULL, 0/*isTest*/);
		if(f != NULL) return f;
	}
	f = (void*)knh_DictSet_get(ctx, ctx->share->funcDictSet, B(funcname));
	if(isVerbose && f == NULL) {
		WARN_NotFound(ctx, _("glue function"), funcname);
	}
	return f;
}

static knh_Fmethod GammaBuilder_loadMethodFunc(CTX ctx, kclass_t cid, kmethodn_t mn, int isNATIVE)
{
	DBG_ASSERT_cid(cid);
	char buf[80];
	const char *cname = S_totext(ClassTBL(cid)->sname);
	if(MN_isFMT(mn)) {
		knh_snprintf(buf, sizeof(buf), "%s__%s", cname, FN__(MN_toFN(mn)));
	}
	else if(MN_isGETTER(mn)) {
		int off = knh_strlen(cname)+4/*sizeof("_get")*/;
		knh_snprintf(buf, sizeof(buf), "%s_get%s", cname, FN__(MN_toFN(mn)));
		if(islower(buf[off])) buf[off] = toupper(buf[off]);
	}
	else if(MN_isSETTER(mn)) {
		int off = knh_strlen(cname)+4/*sizeof("_set")*/;
		knh_snprintf(buf, sizeof(buf), "%s_set%s", cname, FN__(MN_toFN(mn)));
		if(islower(buf[off])) buf[off] = toupper(buf[off]);
	}
	else if(MN_isISBOOL(mn)) {
		int off = knh_strlen(cname)+3/*sizeof("_is")*/;
		knh_snprintf(buf, sizeof(buf), "%s_is%s", cname, FN__(MN_toFN(mn)));
		if(islower(buf[off])) buf[off] = toupper(buf[off]);
	}
	else {
		knh_snprintf(buf, sizeof(buf), "%s_%s", cname, FN__(mn));
	}
	return (knh_Fmethod)knh_loadGlueFunc(ctx, (const char*)buf, isNATIVE);
}

static knh_gamma2_t* GammaBuilder_expand(CTX ctx, kGammaBuilder *gma, size_t minimum)
{
	knh_GammaBuilderEX_t *b = DP(gma);
	size_t i, s = b->gcapacity;
	knh_gamma2_t *gf = NULL;
	b->gcapacity = b->gcapacity * 2;
	if(b->gcapacity < minimum) b->gcapacity = minimum;
	b->gf = (knh_gamma2_t*)KNH_REALLOC(ctx, "gmafield", b->gf, s, b->gcapacity, sizeof(knh_gamma2_t));
	gf = b->gf;
	for(i = s; i < b->gcapacity; i++) {
		gf[i].flag  = 0;
		gf[i].ucnt  = 0;
		gf[i].type  = TYPE_void;
		gf[i].fn    = FN_NONAME;
		KNH_INITv(gf[i].tkIDX, KNH_NULL);
		KNH_INITv(gf[i].stmt,  KNH_NULL);
	}
	return b->gf;
}

void knh_GammaBuilder_init(CTX ctx)
{
	if(DP(ctx->gma)->gcapacity == 0) {
		GammaBuilder_expand(ctx, ctx->gma, 16/*init*/);
	}
}

static void GammaBuilder_clear(CTX ctx, knh_gint_t offset, kStmtExpr *stmt)
{
	size_t i;
	knh_gamma2_t *gf = DP(ctx->gma)->gf;
	if(stmt != NULL) {
		while(DP(stmt)->nextNULL != NULL) {
			stmt = DP(stmt)->nextNULL;
		}
	}
	for(i = offset; i < DP(ctx->gma)->gsize; i++) {
		gf[i].flag  = 0;
		gf[i].type  = TYPE_void;
		gf[i].fn    = FN_NONAME;
		gf[i].ucnt  = 0;
		KNH_SETv(ctx, gf[i].stmt, KNH_NULL);
		KNH_SETv(ctx, gf[i].tkIDX, KNH_NULL);
	}
	DP(ctx->gma)->gsize = offset;
	if(offset < DP(ctx->gma)->fvarsize) {
		DP(ctx->gma)->fvarsize = offset;
	}
}

static kTerm *GammaBuilder_tokenIDX(CTX ctx, kTerm *tk)
{
	if(TT_(tk) == TT_LVAR || TT_(tk) == TT_LFIELD) {
		knh_Array_add(ctx, DP(ctx->gma)->insts, tk);
	}
	return tk;
}

#define GF_FIELD     (1)
#define GF_UNIQUE    (1<<1)
#define GF_FUNCVAR   (1<<2)
#define GF_USEDCOUNT (1<<3)

static kTerm *GammaBuilder_add(CTX ctx, kflag_t flag, kTerm *tkT, kTerm *tkN, kTerm *tkV, kflag_t op)
{
	kindex_t idx = 0;
	knh_gamma2_t *gf = DP(ctx->gma)->gf;
	ksymbol_t fn = Term_fn(ctx, tkN);
	ktype_t type = (tkT)->cid;

	if(FLAG_is(op, GF_UNIQUE)) {
		for(idx = 0; idx < DP(ctx->gma)->gsize; idx++) {
			if(gf[idx].fn == fn) {
				if(gf[idx].type == type) return gf[idx].tkIDX;
				return ERROR_AlreadyDefinedType(ctx, fn, type);
			}
		}
	}

	idx = DP(ctx->gma)->gsize;
	if(!(idx < DP(ctx->gma)->gcapacity)) {
		gf = GammaBuilder_expand(ctx, ctx->gma, /*minimum*/4);
	}
	if(FLAG_is(op, GF_FUNCVAR)) {
		kTermoTYPED(ctx, tkN, TT_FVAR, type, idx);
		STRICT_(Term_setReadOnly(tkN, 1));
		DP(ctx->gma)->fvarsize += 1;
	}
	else {
		kTermoTYPED(ctx, tkN, TT_LVAR, type, idx - DP(ctx->gma)->fvarsize);
		Term_setReadOnly(tkN, FLAG_is(flag, _FREADONLY));
	}
	gf[idx].flag  = flag;
	gf[idx].type  = type;
	gf[idx].fn    = fn;
	gf[idx].ucnt  = FLAG_is(op, GF_USEDCOUNT) ? 1 : 0;
	if(tkV != NULL && TT_(tkV) == TT_CONST) {
		KNH_SETv(ctx, gf[idx].tk, tkV);
	}
	KNH_SETv(ctx, gf[idx].tkIDX, GammaBuilder_tokenIDX(ctx, tkN));
	DP(ctx->gma)->gsize += 1;
	DBLNDATA_(if(FLAG_is(op, GF_FIELD) && IS_Tunbox(type)) {
		idx = DP(ctx->gma)->gsize;
		if(!(idx < DP(ctx->gma)->gcapacity)) {
			gf = GammaBuilder_expand(ctx, ctx->gma, /*minimum*/4);
		}
		gf[idx].flag  = 0;
		gf[idx].type  = TYPE_void;
		gf[idx].fn    = FN_;
		gf[idx].ucnt  = 1;
		DP(ctx->gma)->gsize += 1;
	})
	return tkN;
}

static kTerm *GammaBuilder_addLVAR(CTX ctx, kflag_t flag, ktype_t type, ksymbol_t fn, int ucnt)
{
	kindex_t idx = DP(ctx->gma)->gsize;
	knh_gamma2_t *gf = DP(ctx->gma)->gf;
	kTerm *tkIDX = new_TermTYPED(ctx, TT_LVAR, type, idx - DP(ctx->gma)->fvarsize);
	if(!(idx < DP(ctx->gma)->gcapacity)) {
		gf = GammaBuilder_expand(ctx, ctx->gma, /*minimum*/4);
	}
	gf[idx].flag  = flag;
	gf[idx].type  = type;
	gf[idx].fn    = fn;
	gf[idx].ucnt  = ucnt;
	KNH_SETv(ctx, gf[idx].tkIDX, GammaBuilder_tokenIDX(ctx, tkIDX));
	DP(ctx->gma)->gsize += 1;
	return gf[idx].tkIDX;
}

static kTerm *GammaBuilder_addFVAR(CTX ctx, kflag_t flag, ktype_t type, ksymbol_t fn, int ucnt)
{
	kindex_t idx = DP(ctx->gma)->fvarsize;
	knh_gamma2_t *gf = DP(ctx->gma)->gf;
	if(!(DP(ctx->gma)->gsize < DP(ctx->gma)->gcapacity)) {
		gf = GammaBuilder_expand(ctx, ctx->gma, /*minimum*/4);
	}
	if(idx < DP(ctx->gma)->gsize) {
		kindex_t n = DP(ctx->gma)->gsize;
		knh_gamma2_t gftmp = gf[n];
		for(; idx < n; n--) {
			gf[n] = gf[n-1];
		}
		//DBG_ASSERT(n == idx);
		gf[idx] = gftmp;
	}
	gf[idx].flag  = flag;
	gf[idx].type  = type;
	gf[idx].fn    = fn;
	KNH_SETv(ctx, gf[idx].tkIDX, new_TermTYPED(ctx, TT_FVAR, type, idx));
	gf[idx].ucnt  = 1;
	DP(ctx->gma)->fvarsize += 1;
	DP(ctx->gma)->gsize  += 1;
	return gf[idx].tkIDX;
}

static kTerm* GammaBuilder_rindexFNQ(CTX ctx, kGammaBuilder *gma, ksymbol_t fnq, int ucnt)
{
	kindex_t idx;
	ksymbol_t fn = FN_UNMASK(fnq);
	knh_gamma2_t *gf = DP(gma)->gf;
	for(idx = DP(gma)->gsize - 1; idx >= 0; idx--) {
		if(gf[idx].fn == fn) {
			gf[idx].ucnt += ucnt;
			gf[idx].tkIDX->type = gf[idx].type;
			return gf[idx].tkIDX;
		}
	}
	return NULL;
}

static kfieldinfo_t* class_rindexFNQ(CTX ctx, kclass_t cid, ksymbol_t fnq, kindex_t *n)
{
	ksymbol_t fn = FN_UNMASK(fnq);
	const knh_ClassTBL_t *t = ClassTBL(cid);
	kindex_t idx;
	for(idx = (kindex_t)t->fsize - 1; idx >= 0 ; idx--) {
		kfieldinfo_t *cf = t->fields + idx;
		if(cf->fn == fn) {
			*n = idx;
			return cf;
		}
	}
	return NULL;
}

#define MN_isNEW(mn)  MN_isNEW_(ctx, mn)

static int MN_isNEW_(CTX ctx, kmethodn_t mn)
{
	if(mn == MN_new) return 1;
	if(!MN_isFMT(mn) && !MN_isGETTER(mn) && !MN_isSETTER(mn)) {
		const char *n = MN__(mn);
		if(n[0] == 'n' && n[1] == 'e' && n[2] == 'w' && n[3] == ':') {
			return 1;
		}
	}
	return 0;
}

#define IS_SYSVAL(t,v)  (knh_bytes_strcasecmp(t, STEXT(v)) == 0)

#define _FINDLOCAL      (1<<1)
#define _FINDFIELD      (1<<2)
#define _FINDSCRIPT     (1<<3)
#define _USEDCOUNT      (1<<4)
#define _FINDFUNC       (1<<5)
#define _CHECKREADONLY  (1<<6)
#define _TOERROR        (1<<7)

static kclass_t class_FuncType(CTX ctx, kclass_t this_cid, kMethod *mtd);
static kFunc * new_StaticFunc(CTX ctx, kclass_t cid, kMethod *mtd);

static kTerm *TNAME_typing(CTX ctx, kTerm *tkN, ktype_t reqt, kflag_t op)
{
	ksymbol_t fnq = Term_fnq(ctx, tkN);
	DBG_ASSERT(fnq != FN_NONAME);
	if(FN_isU1(fnq) || FN_isSUPER(fnq)) goto L_FIELD;  /* _name */
	if(FN_isU2(fnq)) {
		if(DP(ctx->gma)->this_cid == O_cid(K_GMASCR)) goto L_FIELD;
		goto L_SCRIPT; /* __name */
	}
	if(FLAG_is(op, _FINDLOCAL)){
		kTerm *tkIDX = GammaBuilder_rindexFNQ(ctx, ctx->gma, fnq, 1);
		if(tkIDX != NULL) {
			if(FLAG_is(op, _CHECKREADONLY) && Term_isReadOnly(tkIDX)) {
				return ERROR_Denied(ctx, "read only", tkN);
			}
			if(DP(ctx->gma)->funcbase0 > 0) {
				if(tkIDX->index < DP(ctx->gma)->funcbase0) {
					int fi = tkIDX->index * (sizeof(ksfp_t)/sizeof(Object*));
					if(IS_Tunbox(tkIDX->type)) fi += 1;
					kTermoTYPED(ctx, tkN, TT_FIELD, tkIDX->type, fi);
					DBG_P("@@LEXICAL SCOPE IDX=%d", fi);
					GammaBuilder_foundLexicalScope(ctx->gma, 1);
				}
				else {
					kTermoTYPED(ctx, tkN, tkIDX->tt, tkIDX->type, (tkIDX)->index - DP(ctx->gma)->funcbase0);
				}
			}
			else {
				kTermoTYPED(ctx, tkN, tkIDX->tt, tkIDX->type, (tkIDX)->index);
			}
			return GammaBuilder_tokenIDX(ctx, tkN);
		}
	}
	L_FIELD:;
	if(FLAG_is(op, _FINDFIELD)) {
		kindex_t idx = -1;
		kfieldinfo_t *cf = class_rindexFNQ(ctx, DP(ctx->gma)->this_cid, fnq, &idx);
		if(cf != NULL) {
			ktype_t type = GammaBuilder_type(ctx, cf->type);
			if(FLAG_is(op, _CHECKREADONLY) && FLAG_is(cf->flag, _FREADONLY)) {
				kMethod *mtd = DP(ctx->gma)->mtd;
				if(!MN_isNEW((mtd)->mn)) {
					return ERROR_Denied(ctx, "read only", tkN);
				}
			}
			if(DP(ctx->gma)->funcbase0 > 0) {
				kTermoTYPED(ctx, tkN, TT_FIELD, type, idx);
				if(DP(ctx->gma)->tkFuncThisNC == NULL) {
					DP(ctx->gma)->tkFuncThisNC = GammaBuilder_addFVAR(ctx, 0, DP(ctx->gma)->this_cid, FN_, 1);
					DBG_P("@@THIS IDX=%d", DP(ctx->gma)->tkFuncThisNC->index);
					GammaBuilder_foundLexicalScope(ctx->gma, 1);
				}
				KNH_SETv(ctx, tkN->tkIDX, DP(ctx->gma)->tkFuncThisNC);
			}
			else {
				kTermoTYPED(ctx, tkN, TT_FIELD, type, idx);
				GammaBuilder_foundFIELD(ctx->gma, 1);
			}
			return GammaBuilder_tokenIDX(ctx, tkN);
		}
	}
	L_SCRIPT:;
	if(FLAG_is(op, _FINDSCRIPT)) {
		kclass_t scrcid = O_cid(K_GMASCR);
		if(DP(ctx->gma)->this_cid != scrcid) {
			kindex_t idx = -1;
			kfieldinfo_t *cf = class_rindexFNQ(ctx, scrcid, fnq, &idx);
			if(cf != NULL) {
				ktype_t type = GammaBuilder_type(ctx, cf->type);
				kTermoTYPED(ctx, tkN, TT_FIELD, type, idx);
				if(DP(ctx->gma)->tkScriptNC == NULL) {
					DP(ctx->gma)->tkScriptNC = GammaBuilder_addFVAR(ctx, 0, scrcid, FN_, 1);
					DBG_P("@@SCRIPT IDX=%d", DP(ctx->gma)->tkScriptNC->index);
				}
				KNH_SETv(ctx, tkN->tkIDX, DP(ctx->gma)->tkScriptNC);
				return GammaBuilder_tokenIDX(ctx, tkN);
			}
		}
	}
	if(FLAG_is(op, _FINDLOCAL) && fnq == FN_it) {
		if(DP(ctx->gma)->psize > 0) {
			kTermoTYPED(ctx, tkN, TT_FVAR, DP(ctx->gma)->gf[DP(ctx->gma)->funcbase0+1].type, 1);
		}
		return GammaBuilder_tokenIDX(ctx, tkN);
	}

	if(FLAG_is(op, _FINDFUNC)) { // TODO_AC
		kMethod *mtd = NULL;
		kNameSpace *ns = K_GMANS;
		kclass_t this_cid = DP(ctx->gma)->this_cid;
		kclass_t mtd_cid = knh_NameSpace_getFuncClass(ctx, ns, fnq);
		if(mtd_cid != CLASS_unknown) {
			mtd = knh_NameSpace_getMethodNULL(ctx, ns, mtd_cid, fnq);
			if(!Method_isStatic(mtd)) mtd = NULL;
		}
		if(mtd == NULL) {
			mtd = knh_NameSpace_getMethodNULL(ctx, ns, this_cid, fnq);
			if(mtd != NULL && !Method_isStatic(mtd)) {
				mtd = NULL;
			}
		}
		if(mtd == NULL) {
			mtd_cid = O_cid(K_GMASCR);
			mtd = knh_NameSpace_getMethodNULL(ctx, ns, mtd_cid, fnq);
			if(mtd != NULL && !Method_isStatic(mtd)) {
				mtd = NULL;
			}
		}
		if(mtd != NULL) {
			if(Method_isRestricted(mtd)) {
				return ERROR_MethodIsNot(ctx, mtd, "allowed");
			}
			this_cid = class_FuncType(ctx, this_cid, mtd);
			return Term_setCONST(ctx, tkN, new_StaticFunc(ctx, this_cid, mtd));
		}
	}
	if(FLAG_is(op, _TOERROR)) {
		return ERROR_Undefined(ctx, "variable", CLASS_unknown, tkN);
	}
	return NULL;
}

/* UNAME */

static kTerm* Term_toSYSVAL(CTX ctx, kTerm *tk)
{
	kbytes_t t = TK_tobytes(tk);
	if(IS_SYSVAL(t, "CTX")) {
		TK_typing(tk, TT_SYSVAL, TYPE_Context, K_SYSVAL_CTX);
	}
	else if(IS_SYSVAL(t, "OUT")) {
		if(GammaBuilder_isCompilingFmt(ctx)) {
			TK_typing(tk, TT_LVAR, TYPE_OutputStream, 0);
		}
		else {
			TK_typing(tk, TT_SYSVAL, TYPE_OutputStream, K_SYSVAL_CTXOUT);
		}
	}
	else if(IS_SYSVAL(t, "EOL")) {
		Term_setCONST(ctx, tk, TS_EOL);
	}
	else if(IS_SYSVAL(t, "IN")) {
		TK_typing(tk, TT_SYSVAL, TYPE_InputStream, K_SYSVAL_CTXIN);
	}
	else if(IS_SYSVAL(t, "ERR")) {
		TK_typing(tk, TT_SYSVAL, TYPE_OutputStream, K_SYSVAL_CTXERR);
	}
	else if(IS_SYSVAL(t, "STDIN")) {
		Term_setCONST(ctx, tk, KNH_STDIN);
	}
	else if(IS_SYSVAL(t, "STDOUT")) {
		Term_setCONST(ctx, tk, KNH_STDOUT);
	}
	else if(IS_SYSVAL(t, "STDERR")) {
		Term_setCONST(ctx, tk, KNH_STDERR);
	}
	else if(IS_SYSVAL(t, "LINE")) {
		Term_setCONST(ctx, tk, new_Int(ctx, ULINE_line(tk->uline)));
	}
	else if(IS_SYSVAL(t, "FILENAME")) {
		Term_setCONST(ctx, tk, K_GMANS->path->urn);
	}
	else if(IS_SYSVAL(t, "MTD")) {
		Term_setCONST(ctx, tk, DP(ctx->gma)->mtd);
	}
	else if(IS_SYSVAL(t, "NS")) {
		kNameSpace *ns = K_GMANS;
		Term_setCONST(ctx, tk, ns);
	}
	else if(IS_SYSVAL(t, "BEGIN")) {
		Term_setCONST(ctx, tk, TS_BEGIN);
	}
	else if(IS_SYSVAL(t, "END")) {
		Term_setCONST(ctx, tk, TS_END);
	}
	else {
		return ERROR_Undefined(ctx, "name", CLASS_unknown, tk);
	}
	return tk;
}

static kTerm* TUNAME_typing(CTX ctx, kTerm *tk)
{
	kclass_t cid = knh_Term_cid(ctx, tk, CLASS_unknown);
	if(cid != CLASS_unknown) {
		return kTermoCID(ctx, tk, cid);
	}
	else {
		kNameSpace *ns = K_GMANS;
		Object *value = knh_NameSpace_getConstNULL(ctx, ns, TK_tobytes(tk));
		if(value != NULL) {
			return Term_setCONST(ctx, tk, value);
		}
	}
	return Term_toSYSVAL(ctx, tk);
}

static kTerm* TPROPN_typing(CTX ctx, kTerm *tk, ktype_t reqt)
{
	kbytes_t t = S_tobytes((tk)->text);
	if(B_endsWith(t, "*")) { /* name.* */
		kStmtExpr *stmt =
			new_Stmt2(ctx, STT_CALL, new_TermMN(ctx, MN_listProperties), new_TermCONST(ctx, KNH_NULL), tk, NULL);
		Term_toCONST(ctx, tk);
		return CALL_typing(ctx, stmt, reqt);
	}
	else {
		size_t i;
		kObject *v = (kObject*)knh_getPropertyNULL(ctx, t);
		if(v != NULL) {
			SP(tk)->type = O_cid(v);
		}
		else {
			if(IS_Tvany(reqt)) {
				reqt = TYPE_String;
				INFO_Typing(ctx, "$", t, TYPE_String);
			}
			tk->type = reqt;
			v = KNH_NULVAL(CLASS_t(reqt));
			knh_setProperty(ctx, tk->text, v);
		}
		for(i = 0; i < t.len; i++) {
			if(islower(t.buf[i])) return TM(tk);
		}
		return Term_setCONST(ctx, tk, v);
	}
}

/* ------------------------------------------------------------------------ */
/* [NUM] */

#ifdef K_USING_SEMANTICS
static kclass_t kTermagcNUM(CTX ctx, kTerm *tk, kclass_t reqc, kNameSpace *ns)
{
	kbytes_t t = TK_tobytes(ctx, tk), tag = STEXT("");
	size_t i = 1;
	int ishex = 0;
	if(t.utext[0] == '0' && (t.utext[1] == 'x' || t.utext[1] == 'b')) {
		i = 2;
		ishex = 1;
		knh_style(ctx, 1);
	}
	for(; i < t.len; i++) {
		if(isdigit(t.utext[i]) || t.utext[i] == '_' || t.utext[i] == '.') continue;
		if(t.utext[i] == '[') {
			int loc;
			tag.buf = t.buf + i + 1;
			tag.len = t.len - (i + 1);
			loc = knh_bytes_index(tag, ']');
			if(loc > 0) {
				tag = knh_bytes_first(tag, loc);
			}
			break;
		}
		else if(t.utext[i] == ':') {
			tag.buf = t.buf + i + 1;
			tag.len = t.len - (i + 1);
			break;
		}
		else {
			if((t.utext[i] == 'E' || t.utext[i] == 'e')) {
				if(isdigit(t.utext[i+1]) || t.utext[i+1] == '-' || t.utext[i+1] == '+') {
					i++;
					continue;
				}
			}
			tag.buf = t.buf + i;
			tag.len = t.len - (i);
			break;
		}
	}
	if(tag.len == 0 || ishex) {
		return reqc;
	}
	else {
		kclass_t tagc = kNameSpaceagcid(ctx, ns, reqc, tag);
		if(tagc == CLASS_unknown) {
			knh_GammaBuilder_perror(ctx, tk, KC_DWARN, _("unknown class tag: %L"), tk);
			return reqc;
		}
		knh_style(ctx, 1);
		return tagc;
	}
}
#endif

/* ------------------------------------------------------------------------ */

static kclass_t bytes_guessNUMcid(CTX ctx, kbytes_t t)
{
	size_t i;
	if(t.utext[0] == '0' && (t.utext[1] == 'x' || t.utext[1]=='b')) {
		return CLASS_Int;
	}
	for(i = 1; i < t.len; i++) {
		if(t.utext[i] == '_') {
#ifdef CLASS_Decimal
			return CLASS_Decimal;
#endif
		}
		else if(t.utext[i] == '.') {
			return CLASS_Float;
		}
		if(!isdigit(t.utext[i])) break;
	}
	return CLASS_Int;
}

static kTerm* NUM_typing(CTX ctx, kTerm *tk, kclass_t reqt)
{
	kbytes_t t = TK_tobytes(tk);
	kclass_t breqc = C_bcid(reqt);
	if(reqt == CLASS_Boolean) {
		if(t.utext[0] == '0') {
			WARN_MuchBetter(ctx, "false", "0");
			return Term_setCONST(ctx, tk, KNH_FALSE);
		}
		else {
			WARN_MuchBetter(ctx, "true", NULL);
			return Term_setCONST(ctx, tk, KNH_TRUE);
		}
	}
	if(breqc != CLASS_Int && breqc != CLASS_Float) {
		reqt = bytes_guessNUMcid(ctx, t);
		breqc = C_bcid(reqt);
	}
	if(breqc == CLASS_Float) {
		kfloat_t n = KFLOAT_ZERO;
		if(!knh_bytes_parsefloat(t, &n)) {
			WARN_Overflow(ctx, "float", t);
		}
#if defined(K_USING_SEMANTICS)
		kclass_t tagc = kTermagcNUM(ctx, tk, reqc, ns);
		kSemantics *u = knh_getSemantics(ctx, tagc);
		if(!DP(u)->ffchk(u, n)) {
			knh_GammaBuilder_perror(ctx, KC_ERRATA, _("%C: out of range: %B ==> %O"), tagc, t, DP(u)->fvalue);
			return Term_setCONST(ctx, tk, UPCAST(DP(u)->fvalue));
		}
		else {
			return Term_setCONST(ctx, tk, UPCAST(new_Float_X(ctx, tagc, n)));
		}
#else
		return Term_setCONST(ctx, tk, new_Float_(ctx, CLASS_Float, n));
#endif/*K_USING_SEMANTICS*/
	}
	else { /* if(req_bcid == CLASS_Int) */
		kint_t n = 0;
		if(!knh_bytes_parseint(t, &n)) {
			WARN_Overflow(ctx, "integer", t);
		}
#if defined(K_USING_SEMANTICS)
		kclass_t tagc = kTermagcNUM(ctx, tk, reqc, ns);
		kSemantics *u = knh_getSemantics(ctx, tagc);
		if(!DP(u)->fichk(u, n)) {
			knh_GammaBuilder_perror(ctx, KC_ERRATA, _("%C: out of range: %B ==> %O"), tagc, t, DP(u)->ivalue);
			return Term_setCONST(ctx, tk, UPCAST(DP(u)->ivalue));
		}
		else {
			return Term_setCONST(ctx, tk, UPCAST(new_Int_X(ctx, tagc, n)));
		}
#else
		return Term_setCONST(ctx, tk, new_Int_(ctx, CLASS_Int, n));
#endif/*K_USING_SEMANTICS*/
	}
}

static kTerm* TSTR_typing(CTX ctx, kTerm *tk, kclass_t reqt)
{
	kbytes_t t = TK_tobytes(tk);
	if(CLASS_t(reqt) != CLASS_String && knh_bytes_mlen(t) == 1) {
		/* 'A' ==> int if not String */
		kbytes_t sub = knh_bytes_mofflen(t, 0, 1);
		return Term_setCONST(ctx, tk, new_Int_(ctx, CLASS_Int, kchar_toucs4(&sub.utext[0])));
	}
	return Term_toCONST(ctx, tk);
}

static kbool_t bytes_isLONGFMT(kbytes_t t)
{
	size_t i = 0, size = t.len - 1;
	if(t.len < 1) return 0;
	L_AGAIN:;
	for(;i < size; i++) {
		if(t.utext[i] == '%') {
			int ch = t.utext[i+1];
			i++;
			if(isdigit(ch) || ch == ' ' || ch == '.' || ch == '+' || ch == '-' || ch == '#') {
				goto L_CFMT;
			}
			if(isalpha(ch)) goto L_KFMT;
		}
		if(t.utext[i] == '$' && isalpha(t.utext[i+1])) return 1;
	}
	return 0;
	L_CFMT:;
	for(; i < size; i++) {
		int ch = t.utext[i];
		if(isalpha(ch) || t.utext[i+1] == '{') return 1;
		if(!isdigit(ch) && ch != '.') goto L_AGAIN;
	}
	return 0;
	L_KFMT:;
	for(; i < size; i++) {
		int ch = t.utext[i];
		if(ch == '{') return 1;
		if(!isalnum(ch) && ch != ':') goto L_AGAIN;
	}
	return 0;
}

static kclass_t bytes_CFMT(kbytes_t t)
{
	if(t.utext[0] == '%') {
		int fmtidx = (isdigit(t.utext[1]) || t.utext[1] == ' ' || t.utext[1] == '.') ? t.len - 1 : 1;
		int ch = t.utext[fmtidx];
		switch(ch) {
			case 'd': case 'u': case 'x': case 'X': case 'c': return CLASS_Int;
			case 'e': case 'E': case 'f': return CLASS_Float;
			//case 's': return CLASS_String;
		}
	}
	return CLASS_unknown;
}

static kmethodn_t bytes_parsemn(CTX ctx, kbytes_t t)
{
	if(t.utext[0] == '%' && t.utext[1] != '%') {
		size_t i;
		for(i = 1; i < t.len; i++) {
			int ch = t.utext[i];
			if(isalnum(ch) || ch == ':' || ch == ' ') continue;
			if(ch == '.' && !isalpha(t.utext[i-1])) continue;
			break;
		}
		if(i == t.len) {
			return knh_getmn(ctx, t, MN_NEWID);
		}
	}
	return MN__s;
}

static kTerm *W1_typing(CTX ctx, kStmtExpr *stmt)
{
	kTerm *tkFMT = tkNN(stmt, 0);
	kbytes_t fmt = S_tobytes((tkFMT)->text);
	kclass_t cid = bytes_CFMT(fmt);
	if(DP(stmt)->size > 3) {
		WARN_TooMany(ctx, "parameters", fmt.text);
		kStmtExprrimToSize(ctx, stmt, 3);
	}
	if(cid != CLASS_unknown) {  // "%4d"(1), not "%d"(1)
		kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, cid, MN_format);
		DBG_ASSERT(mtd != NULL);
		Term_setCONST(ctx, tkNN(stmt, 1), (tkFMT)->data);
		TYPING(ctx, stmt, 2, cid, _NOBOX);
		knh_Stmt_swap(ctx, stmt, 1, 2);
		Term_setMethod(ctx, tkFMT, MN_format, mtd);
		STT_(stmt) = STT_CALL;
		return CALLPARAMs_typing(ctx, stmt, TYPE_String, cid, mtd);
	}
	if(DP(stmt)->size == 3) { //"%bits" (a)
		STT_(stmt) = STT_W1;
		TYPING_UntypedExpr(ctx, stmt, 2);
		kmethodn_t mn = bytes_parsemn(ctx, fmt);
		kMethod *mtdf = knh_NameSpace_getFmtNULL(ctx, K_GMANS, Tn_cid(stmt, 2), mn);
		if(mtdf != NULL) {
			KNH_SETv(ctx, (tkFMT)->data, mtdf);
		}
		else {
			WARN_Undefined(ctx, "formatter", Tn_cid(stmt, 2), tkFMT);
		}
		DBG_ASSERT(TT_(tmNN(stmt, 1)) == TT_ASIS);
	}
	return Stmt_typed(ctx, stmt, TYPE_String);
}

static kStmtExpr* new_StmtW1(CTX ctx, kTerm *tkFMT, kTerm *tkW, kTerm *tkEXPR)
{
	if(tkFMT == NULL) tkFMT = new_TermCONST(ctx, TS_EMPTY);
	kStmtExpr *stmtW = new_Stmt2(ctx, STT_W1, tkFMT, tkW, tkEXPR, NULL);
	kTerm *tkRES = W1_typing(ctx, stmtW);
	if(TT_(tkRES) == STT_CALL) {
		return new_StmtW1(ctx, NULL, tkW, tkRES);  //"%d{expr}"
	}
	else if(TT_(tkRES) == TT_ERR) {
		KNH_SETv(ctx, stmtNN(stmtW, 0), tkRES);
		knh_Stmt_done(ctx, stmtW);
	}
	//DBG_P("STT=%s", TT__(stmtW->stt));
	return stmtW;
}

#define APPEND_TAIL(stmtHEAD, stmtTAIL, stmtW) {\
		if(stmtHEAD == NULL) {stmtHEAD = stmtW;}\
		else {KNH_INITv(DP(stmtTAIL)->nextNULL, stmtW);}\
		stmtTAIL = stmtW;\
	}\

static kTerm *FMTCALL_typing(CTX ctx, kStmtExpr *stmt)
{
	kTerm *tkFMT = tkNN(stmt, 0);
	kbytes_t t = S_tobytes((tkFMT)->text);
	kStmtExpr *stmtHEAD = NULL, *stmtTAIL = NULL, *stmtW;
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	kline_t uline = tkFMT->uline;
	size_t i = 0, s = 0;
	while(i < t.len) {
		for(;i < t.len; i++) {
			int ch = t.utext[i];
			if(ch == '\n') uline++;
			if(ch == '%') {
				i++;
				if(t.text[i] == '%') {
					knh_Bytes_putc(ctx, cwb->ba, '%');
					continue;
				}
				break;
			}
			if(ch == '$' && t.text[i+1] == '$') {
				i+=2;
				break;
			}
			knh_Bytes_putc(ctx, cwb->ba, ch);
		}
		if(CWB_size(cwb) > 0) {
			stmtW = new_StmtW1(ctx, NULL, tkNN(stmt,1), new_TermCONST(ctx, CWB_newString(ctx, cwb, 0)));
			APPEND_TAIL(stmtHEAD, stmtTAIL, stmtW);
		}
		if(!(i < t.len)) break;
		s = i - 1;
		DBG_P("FMT t[%d]=%c", s, t.utext[s]);
		if(t.utext[s] == '$') {
			for(;i < t.len; i++) {
				int ch = t.utext[i];
				if(!isalnum(ch)) break;
			}
			DBG_P("nm last t[%d]=%c", i-1, t.utext[-1]);
			kbytes_t name = {{t.text + s + 1}, i - (s + 1)};
			kTerm *tkN = new_(Term);
			tkN->tt = isupper(t.text[0]) ? TT_UNAME : TT_NAME;
			tkN->uline = uline;
			KNH_SETv(ctx, tkN->data, new_S(name.text, name.len));
			stmtW = new_StmtW1(ctx, new_TermCONST(ctx, new_S("%s", sizeof("%s"))), tkNN(stmt, 1), tkN);
			APPEND_TAIL(stmtHEAD, stmtTAIL, stmtW);
		}
		else if(t.utext[s] == '%') {
			for(;i < t.len; i++) {
				int ch = t.utext[i];
				DBG_P("t[%d]=%c", i, ch);
				if(ch == '{') {
					kbytes_t mt = {{t.text + s}, i - s};
					kbytes_t expr = {{t.text + (i+1)}, t.len - (i+1)};
					kindex_t loc = knh_bytes_index(expr, '}');
					if(loc == -1) {
						WarningIllegalFormatting(ctx, expr.text - 1);
						DBG_P("unclosed }");
						goto L_ERROR;
					}
					if(expr.text[0] == '#' && isdigit(expr.text[1])) {
						long n = strtol(expr.text+1, NULL, 10);
						if(n < 0 || DP(stmt)->size - 2 <= n) {
							WarningIllegalFormatting(ctx, mt.text);
							DBG_P("out of number: %d !< %d", n, DP(stmt)->size - 2);
							goto L_ERROR;
						}
						TYPING_UntypedExpr(ctx, stmt, 2 + n);
						stmtW = new_StmtW1(ctx, new_TermCONST(ctx, new_S(mt.text, mt.len)), tkNN(stmt, 1), new_TermTYPED(ctx, TT_NUM, Tn_type(stmt, n+2), n));
						APPEND_TAIL(stmtHEAD, stmtTAIL, stmtW);
					}
					else {
						stmtW = new_StmtW1(ctx, new_TermCONST(ctx, new_S(mt.text, mt.len)),
								tkNN(stmt, 1), (kTerm*)knh_bytes_parseStmt(ctx, expr, uline));
						APPEND_TAIL(stmtHEAD, stmtTAIL, stmtW);
					}
					i += (loc + 2);
					break;
				}
				else if(!isalnum(ch) && ch != '.') {
					WarningIllegalFormatting(ctx, t.text + i);
					DBG_P("illegal char: %c", ch);
					goto L_ERROR;
				}
			}
		}
	}/*while*/
	STT_(stmt) = STT_FMTCALL;
	for(i = 2; i < DP(stmt)->size; i++) {
		if(tmNN(stmt, i)->type == TYPE_var) {  // unused
			KNH_SETv(ctx, tkNN(stmt, i), new_(Term)); // ASIS
		}
	}
	DBG_ASSERT(stmtHEAD != NULL);
	KNH_SETv(ctx, stmtNN(stmt, 0), stmtHEAD);
	CWB_close(ctx, cwb);
	return Stmt_typed(ctx, stmt, TYPE_String);

	L_ERROR:
	CWB_close(ctx, cwb);
	return new_TermCONST(ctx, TS_EMPTY);
}

static kTerm *FMTOP_typing(CTX ctx, kStmtExpr *stmt, ktype_t reqt)
{
	kTerm *tkFMT = tkNN(stmt, 0);
	kbytes_t t = S_tobytes((tkFMT)->text);
	if(bytes_isLONGFMT(t)) {
		return FMTCALL_typing(ctx, stmt);
	}
	else if(t.text[0] == '%' && t.text[1] != '%') {
		return W1_typing(ctx, stmt);
	}
	else {
		return Term_toCONST(ctx, tkFMT);
	}
}

static kTerm* ESTR_typing(CTX ctx, kTerm *tk, kclass_t reqt)
{
	kbytes_t t = S_tobytes((tk)->text);
	if(bytes_isLONGFMT(t)) {
		kStmtExpr *stmt = new_Stmt2(ctx, STT_FUNCCALL, tk, new_(Term)/*ASIS*/, NULL);
		return FMTOP_typing(ctx, stmt, reqt);
	}
	else {
		return Term_toCONST(ctx, tk);
	}
}

static kTerm* TURN_typing(CTX ctx, kTerm *tk, kclass_t reqt)
{
	if(reqt == TYPE_String) {
		return Term_toCONST(ctx, tk);
	}
	else {
		kNameSpace *ns = K_GMANS;
		kString *path = (tk)->text;
		const knh_ClassTBL_t *ct = knh_NameSpace_getLinkClassTBLNULL(ctx, ns, S_tobytes(path), reqt);
		if(ct == NULL) {
			return ERROR_Undefined(ctx, "link", CLASS_unknown, tk);
		}
		if(TT_(tk) != TT_URN) {  // this is necessary for exists URN;
			return Term_toCONST(ctx, tk);
		}
		if(reqt == CLASS_Tdynamic || reqt == CLASS_Tvar || reqt == CLASS_Tvar) {
			reqt = ct->cid;
		}
		Object *value = knh_NameSpace_newObject(ctx, ns, path, reqt);
		if(IS_NULL(value)) {
			WARN_Undefined(ctx, "literal", reqt, tk);
		}
		return Term_setCONST(ctx, tk, value);
	}
}

/* @see _EXPRCAST */
static kTerm* TLINK_typing(CTX ctx, kStmtExpr *stmt, ktype_t reqt)
{
	kTerm *tkLNK = tkNN(stmt, 1);
	kNameSpace *ns = K_GMANS;
	kString *path = (tkLNK)->text;
	const knh_ClassTBL_t *ct = knh_NameSpace_getLinkClassTBLNULL(ctx, ns, S_tobytes(path), reqt);
	if(ct == NULL) {
		return ERROR_Undefined(ctx, "link", CLASS_unknown, tkLNK);
	}
	if(TT_(tkNN(stmt, 2)) == TT_ASIS) {
		Term_setCONST(ctx, tkNN(stmt, 2), tkLNK->data);
	}
	else {
		TYPING_TypedExpr(ctx, stmt, 2, TYPE_String);
	}
	if(reqt == CLASS_Tdynamic || reqt == CLASS_Tvar || reqt == CLASS_Tvar) {
		reqt = ct->cid;
	}
	kclass_t cid = knh_ClassTBL_linkType(ctx, ct, reqt);
	if(cid != CLASS_unknown) {
		DBG_ASSERT(DP(stmt)->size == 3);
		STT_(stmt) = STT_CALL;
		Term_setMethod(ctx, tkNN(stmt, 0), MN_opLINK, knh_NameSpace_getMethodNULL(ctx, ns, CLASS_String, MN_opLINK));
		Term_setCONST(ctx, tkLNK, path);
		// expr
		knh_Stmt_add(ctx, stmt, new_TermCONST(ctx, K_GMANS));
		knh_Stmt_add(ctx, stmt, new_TermCONST(ctx, new_Type(ctx, cid)));
		return Stmt_typed(ctx, stmt, cid);
	}
	else {
		return TERROR_Term(ctx, tkLNK, ct->cid, reqt);
	}
}

/* ------------------------------------------------------------------------ */
/* [Term] */

static kTerm *Term_typing(CTX ctx, kTerm *tk, ktype_t tcid)
{
	if(Term_isTyped(tk)) return tk;
	if(tcid == TYPE_var || tcid == TYPE_void) tcid = TYPE_dyn;
	switch(TT_(tk)) {
	case TT_ASIS:  tk->type = tcid; return tk;
	case TT_NULL:  return kTermoTYPED(ctx, tk, TT_NULL/*DEFVAL*/, tcid, CLASS_t(tcid));
	case TT_TRUE:  return Term_setCONST(ctx, tk, KNH_TRUE);
	case TT_FALSE: return Term_setCONST(ctx, tk, KNH_FALSE);
	case TT_NAME:  return TNAME_typing(ctx, tk, tcid, _FINDLOCAL|_FINDFIELD|_FINDSCRIPT|_FINDFUNC|_TOERROR);
	case TT_UNAME: return TUNAME_typing(ctx, tk);
	case TT_TYPEOF: case TT_DYN:
	case TT_PTYPE:  return TTYPE_typing(ctx, tk, tcid);
	case TT_PROPN: return TPROPN_typing(ctx, tk, tcid);
	case TT_REGEX: case TT_STR: return Term_toCONST(ctx, tk);
	case TT_TSTR: return TSTR_typing(ctx, tk, tcid);
	case TT_ESTR: return ESTR_typing(ctx, tk, tcid);
	case TT_NUM: return NUM_typing(ctx, tk, tcid);
	case TT_URN: case TT_TLINK: return TURN_typing(ctx, tk, tcid);
	case TT_ERR: return tk;
	case TT_MN:
	default:
		return ERROR_Term(ctx, tk K_TRACEPOINT);
	}
}
/* ------------------------------------------------------------------------ */
/* STMT */

static ktype_t Method_lookupVariableType(CTX ctx, kMethod *mtd, ksymbol_t fn)
{
	size_t i;
	kParam *pa = DP(mtd)->mp;
	for(i = 0; i < pa->psize; i++) {
		kparam_t *p = knh_Param_get(pa, i);
		if(FN_UNMASK(p->fn) == fn) return p->type;
	}
	return TYPE_var;
}

static ktype_t Class_lookupVariableType(CTX ctx, kclass_t cid, ksymbol_t fn)
{
	kindex_t idx;
	kfieldinfo_t *cf = class_rindexFNQ(ctx, cid, fn, &idx);
	if(cf != NULL) {
		return cf->type;
	}
	else {
		const char *vname = FN__(fn);
		if(vname[1] != 0) {
			kArray *a = ClassTBL(cid)->methods;
			long i;
			for(i = knh_Array_size(a) - 1; i >=0; i--) {
				kMethod *mtd = a->methods[i];
				ktype_t itype = Method_lookupVariableType(ctx, mtd, fn);
				if(itype != TYPE_var) return itype;
			}
		}
	}
	return TYPE_var;
}

#define _VFINDTHIS          (1<<1)
#define _VFINDSCRIPT        (1<<2)

static ktype_t GammaBuilder_lookupVariableType(CTX ctx, kTerm *tkN, kflag_t op)
{
	ktype_t itype = TYPE_var;  // if not found
	kclass_t this_cid = DP(ctx->gma)->this_cid;
	ksymbol_t fn = Term_fn(ctx, tkN);
	if(FLAG_is(op, _VFINDTHIS)) {
		itype = Class_lookupVariableType(ctx, this_cid, fn);
	}
	if(itype == TYPE_var && FLAG_is(op, _VFINDSCRIPT) &&  this_cid != O_cid(K_GMASCR)) {
		itype = Class_lookupVariableType(ctx, O_cid(K_GMASCR), fn);
	}
	return itype;
}

static kTerm *DECL3_typing(CTX ctx, kStmtExpr *stmt, size_t n, ktype_t reqt, kflag_t opflag, int allowDynamic)
{
	kTerm *tkT = TTYPE_typing(ctx, tkNN(stmt, n), reqt);
	kTerm *tkN = tkNN(stmt, n+1);
	kTerm *tkV = tkNN(stmt, n+2);
	if((tkT)->cid == TYPE_var) {
		ktype_t itype = TYPE_var;
		if(itype == TYPE_var && TT_(tkV) != TT_ASIS) {
			TYPING(ctx, stmt, n+2, TYPE_var, _TINFER | _NOVOID | _NOBOX);
			itype = Tn_type(stmt, n+2);
		}
		if(itype == TYPE_var && TT_(tkV) == TT_ASIS) {
			itype = GammaBuilder_lookupVariableType(ctx, tkN, opflag);
		}
		if(itype == TYPE_var) {
			if(!allowDynamic) {
				return ERROR_MustBe(ctx, "typed", S_totext(tkN->text));
			}
		}
		else {
			kTermoCID(ctx, tkT, itype);
			INFO_Typing(ctx, "", TK_tobytes(tkN), itype);
		}
	}
	else {
		if(TT_(tkV) == TT_ASIS) {
			kTermoTYPED(ctx, tkNN(stmt, n+2), TT_NULL, tkT->cid, tkT->cid);
		}
		else {
			TYPING_TypedExpr(ctx, stmt, n+2, (tkT)->cid);
		}
	}
	return tkT;
}

static kflag_t DECL_flag(CTX ctx, kStmtExpr *o, kflag_t flag)
{
	if(IS_Map(DP(o)->metaDictCaseMap)) {
		if(knh_DictMap_getNULL(ctx, DP(o)->metaDictCaseMap, STEXT("Private"))) {
			flag = 0;
		}
		ADD_FLAG(flag, "Getter", _FGETTER);
		ADD_FLAG(flag, "Setter", _FSETTER);
		ADD_FLAG(flag, "Volatile", FLAG_Field_Volatile);
		ADD_FLAG(flag, "ReadOnly", _FREADONLY);
		ADD_FLAG(flag, "Key", _FKEY);
		if((flag & _FREADONLY) == _FREADONLY) {
			flag = ((~_FSETTER) & flag);
		}
	}
	return flag;
}

static kTerm *DECL_typing(CTX ctx, kStmtExpr *stmt) /* LOCAL*/
{
	kflag_t flag  = DECL_flag(ctx, stmt, 0);
	kTerm *tkT = DECL3_typing(ctx, stmt, 0, TYPE_var, 0, 0);
	if(TT_(tkT) != TT_ERR) {
		tkT = GammaBuilder_add(ctx, flag, tkNN(stmt, 0), tkNN(stmt, 1), NULL, 0);
		if(TT_(tkT) != TT_ERR) {
			Stmt_toSTT(stmt, STT_LET);
			return Stmt_typed(ctx, stmt, TYPE_void);
		}
	}
	else {
		kStmtExproERR(ctx, stmt, tkT);
	}
	return tkT;
}

/* ------------------------------------------------------------------------ */

static kfieldinfo_t *ClassTBL_expandFields(CTX ctx, knh_ClassTBL_t *ct)
{
	size_t newsize = (ct->fcapacity == 0) ? K_FASTMALLOC_SIZE / sizeof(kfieldinfo_t) : ct->fcapacity * 2;
	ct->fields = (kfieldinfo_t*)KNH_REALLOC(ctx, "fields", ct->fields, ct->fcapacity, newsize, sizeof(kfieldinfo_t));
	ct->fcapacity = newsize;
	return ct->fields;
}

static void class_addField(CTX ctx, kclass_t cid, kflag_t flag, ktype_t type, ksymbol_t fn)
{
	knh_ClassTBL_t *t = varClassTBL(cid);
	kfieldinfo_t *cf = t->fields;
	size_t n = t->fsize;
	if(t->fcapacity == n) {
		cf = ClassTBL_expandFields(ctx, t);
	}
	cf[n].flag = flag;
	cf[n].fn   = fn;
	cf[n].type = type;
	cf[n].israw = (type == TYPE_void || IS_Tunbox(type)) ? 1 : 0;
	t->fsize += 1;
	DBLNDATA_(if(IS_Tunbox(type)) {
		n = t->fsize;
		if(t->fcapacity == n) {
			cf = ClassTBL_expandFields(ctx, t);
		}
		cf[n].fn   = FN_;
		cf[n].type = TYPE_void;
		cf[n].israw = 1;
		t->fsize += 1;
	})
}

static void ObjectField_expand(CTX ctx, kObject *of, size_t oldsize, size_t newsize)
{
	kObject **oldf = of->fields;
	if(newsize < K_SMALLOBJECT_FIELDSIZE) {
		of->fields = &(of->smallobject);
		if(oldsize == 0) {
			of->fields[0] = of->fields[1] = of->fields[2] = NULL;
		}
	}
	else if(oldsize != 0 && oldsize < K_SMALLOBJECT_FIELDSIZE) {
		kObject** newf = (kObject**)KNH_MALLOC(ctx, newsize*sizeof(Object*));
		knh_memcpy(newf, oldf, oldsize*sizeof(Object*));
		knh_bzero(newf+oldsize, (newsize-oldsize)*sizeof(Object*));
		of->fields = newf;
	}
	else {
		of->fields = (kObject**)KNH_REALLOC(ctx, "ObjectField", oldf, oldsize, newsize, sizeof(Object*));
	}
	//DBG_P("fields=%p => %p, size=%d => %d", oldf, of->fields, oldsize, newsize);
}

static void ObjectField_add(CTX ctx, kclass_t this_cid, kObject **v, size_t i, ktype_t type, kObject *o)
{
	kclass_t cid = ktype_tocid(ctx, type, this_cid);
	kclass_t bcid = C_bcid(type);
	switch(bcid) {
		case CLASS_Boolean: {
			kunbox_t *nn = (kunbox_t*)(v + i);
			nn[0] = IS_Boolean(o) ? N_tobool(o) : 0;
			break;
		}
		case CLASS_Int: {
			kint_t *nn = (kint_t*)(v + i);
			nn[0] = IS_bInt(o) ? N_toint(o) : 0;
			break;
		}
		case CLASS_Float: {
			kfloat_t *nn = (kfloat_t*)(v + i);
			nn[0] = IS_bFloat(o) ? N_tofloat(o) : KFLOAT_ZERO;
			break;
		}
		case CLASS_Tvoid: {
			break;
		}
		default: {
			if(IS_NOTNULL(o)) {
				KNH_INITv(v[i], o);
			}
			else {
				KNH_INITv(v[i], KNH_NULVAL(cid));
			}
		}
	}
}

//#define k_goodbsize(n)   (k_goodsize((n) * sizeof(void*)) / sizeof(void*))

static kindex_t Script_addField(CTX ctx, kScript *scr, kflag_t flag, ktype_t type, ksymbol_t fn)
{
	const knh_ClassTBL_t *ct = O_cTBL(scr);
	size_t fsize = ct->fsize, fcapacity = ct->fcapacity;
	DBG_ASSERT(scr == (kScript*)ct->defnull);
	class_addField(ctx, ct->cid, flag, type, fn);
	if(fcapacity < ct->fcapacity) {
		DBG_P("fsize=%d=>%d, fcapacity=%d=>%d", fsize, ct->fsize, fcapacity, ct->fcapacity);
		ObjectField_expand(ctx, (kObject*)scr, fcapacity, ct->fcapacity);
	}
	ObjectField_add(ctx, ct->cid, scr->fields, fsize, type, KNH_NULL);
	return (kindex_t)fsize;
}

static kTerm *DECLSCRIPT_typing(CTX ctx, kStmtExpr *stmt)
{
	kflag_t flag  = DECL_flag(ctx, stmt, _FGETTER | _FSETTER);
	kTerm *tkT = DECL3_typing(ctx, stmt, 0, TYPE_var, _VFINDSCRIPT, 0);
	kTerm *tkN = tkNN(stmt, 1);
	if(TT_(tkT) != TT_ERR) {
		kScript *scr = K_GMASCR;
		ksymbol_t fn = Term_fn(ctx, tkN);
		const knh_ClassTBL_t *t = O_cTBL(scr);
		kindex_t idx = -1;
		for(idx = (kindex_t)t->fsize - 1; idx >= 0 ; idx--) {
			if(t->fields[idx].fn == fn) {
				if(t->fields[idx].type != tkT->cid) {
					return ERROR_AlreadyDefinedType(ctx, fn, tkT->cid);
				}
				break;
			}
		}
		if(idx == -1) {
			idx = Script_addField(ctx, scr, flag, (tkT)->cid, fn);
		}
		kTermoTYPED(ctx, tkN, TT_FIELD, (tkT)->cid, idx);
		Stmt_toSTT(stmt, STT_LET);
		Stmt_typed(ctx, stmt, TYPE_void);
		return TM(stmt);
	}
	else {
		kStmtExproERR(ctx, stmt, tkT);
	}
	return tkT;
}

static kTerm *OPR_typing(CTX ctx, kStmtExpr *stmt, ktype_t tcid);

static kTerm *SETPROPN_typing(CTX ctx, kStmtExpr *stmt, ktype_t reqt)
{
	kTerm *tkN = tkNN(stmt, 1);
	kString *v = knh_getPropertyNULL(ctx, S_tobytes(tkN->text));
	ktype_t type;
	if(v != NULL) {
		type = O_cid(v);
		TYPING_TypedObject(ctx, stmt, 2, type);
	}
	else {
		TYPING_UntypedObject(ctx, stmt, 2);
		type = Tn_type(stmt, 2);
		INFO_Typing(ctx, "$", S_tobytes(tkN->text), type);
	}
	Stmt_toSTT(stmt, STT_CALL);
	KNH_SETv(ctx, tkNN(stmt, 0), new_TermMN(ctx, MN_setProperty));
	Stmt_insert(ctx, stmt, 1, new_TermTYPED(ctx, TT_CID, CLASS_Class, CLASS_System));
	TT_(tkN) = TT_STR;  // reset
	return CALL_typing(ctx, stmt, type);
}

static kTerm *TNAME_infer(CTX ctx, kTerm *tkN, kStmtExpr *stmt, size_t n)
{
	TYPING(ctx, stmt, n, TYPE_var, _NOCHECK|_NOVOID);
	ktype_t type = Tn_type(stmt, n);
	INFO_Typing(ctx, "", TK_tobytes(tkN), type);
	ksymbol_t fn = Term_fn(ctx, tkN);
	if(IS_SCRIPTLEVEL(ctx)) {
		kindex_t idx = Script_addField(ctx, K_GMASCR, 0, type, fn);
		kTermoTYPED(ctx, tkN, TT_FIELD, type, idx);
		return tkN;
	}
	else {
		return GammaBuilder_addFVAR(ctx, 0, type, fn, 0);
	}
}

static kTerm *LET_typing(CTX ctx, kStmtExpr *stmt, ktype_t reqt)
{
	kTerm *tkN = tkNN(stmt, 1);
	Term_setReadOnly(tkN, 0);
	if(reqt == TYPE_Boolean) {
		WARN_MuchBetter(ctx, "==", "=");
		STT_(stmt) = STT_OPR;
		KNH_SETv(ctx, tkNN(stmt, 0), new_TermMN(ctx, MN_opEQ));
		return OPR_typing(ctx, stmt, reqt);
	}
	if(TT_(tkN) == TT_NAME) {
		kTerm *tkRES = TNAME_typing(ctx, tkN, reqt, _FINDLOCAL | _FINDFIELD | _FINDSCRIPT| _CHECKREADONLY);
		if(tkRES == NULL) { /* not found */
			tkRES = TNAME_infer(ctx, tkN, stmt, 2);
		}
		if(TT_(tkRES) != TT_ERR) {
			TYPING_TypedExpr(ctx, stmt, 2, tkRES->type);
			kTermoTYPED(ctx, tkN, tkRES->tt, tkRES->type, (tkRES)->index);
			return Stmt_typed(ctx, stmt, tkN->type);
		}
		return tkRES;
	}
	if(TT_(tkN) == STT_CALL) {
		kStmtExpr *stmtGET = (kStmtExpr*)tkN;
		kTerm *tkS = tkNN(stmtGET, 0);
		if(Term_isGetter(tkS)) {  // required copy for a[i] += 1
			kTerm *tkM = new_Term(ctx, TT_(tkS));
			(tkM)->flag0 = (tkS)->flag0;
			KNH_SETv(ctx, (tkM)->data, (tkS)->data);
			(tkM)->mn = (tkS)->mn;
			Term_setGetter(tkM, 0);
			Term_setSetter(tkM, 1);
			{
				size_t i;
				Stmt_toSTT(stmt, STT_CALL);
				KNH_SETv(ctx, tkNN(stmt, 0), tkM);
				KNH_SETv(ctx, tkNN(stmt, 1), tkNN(stmtGET, 1));
				for(i = 2; i < DP(stmtGET)->size; i++) {
					Stmt_insert(ctx, stmt, i, tmNN(stmtGET, i));
				}
				return CALL_typing(ctx, stmt, reqt);
			}
		}
	}
	if(TT_(tkN) == TT_PROPN) {
		return SETPROPN_typing(ctx, stmt, reqt);
	}
	if(TT_(tkN) == TT_UNAME) {
		return ERROR_OnlyTopLevel(ctx, "constant definition");
	}
	return ERROR_UnableToAssign(ctx, tkN);
}

static void Stmt_setESPIDX(CTX ctx, kStmtExpr *stmt)
{
	knh_Array_add(ctx, DP(ctx->gma)->insts, stmt);
	DP(stmt)->espidx = GammaBuilder_espidx(ctx);
}

static void LET_addVAR(CTX ctx, kStmtExpr *stmt, size_t n, ktype_t type, kTerm *tkN)
{
	ksymbol_t fn = Term_fn(ctx, tkN);
	DBG_P("script level=%d", IS_SCRIPTLEVEL(ctx));
	if(IS_SCRIPTLEVEL(ctx)) {
		kindex_t idx = Script_addField(ctx, K_GMASCR, 0, type, fn);
		kTermoTYPED(ctx, tkN, TT_FIELD, type, idx);
	}
	else {
		tkN = GammaBuilder_addFVAR(ctx, 0, type, fn, 0);
	}
	KNH_SETv(ctx, tmNN(stmt, n), tkN);
}

// a, b = hoge

static kTerm *LETM_typing(CTX ctx, kStmtExpr *stmt)
{
//	kclass_t tuplecid = CLASS_Tuple;
	size_t i, msize = DP(stmt)->size - 1, tsize = msize;
	int CheckReadOnly = 0;  // TODO
	TYPING(ctx, stmt, msize, TYPE_Tuple, _BCHECK);
	kclass_t tplcid = Tn_cid(stmt, msize);
	const knh_ClassTBL_t *ct = ClassTBL(tplcid);
	if(ct->cparam->psize < tsize) {
		kTerm *tkN = tkNN(stmt, ct->cparam->psize);
		WARN_TooMany(ctx, "variables", S_totext(tkN->text));
		for(i = ct->cparam->psize;i < msize; i++) {
			TT_(tkNN(stmt, i)) = TT_ASIS;
		}
		tsize = ct->cparam->psize;
	}
	for(i = 0; i < tsize; i++) {
		kTerm *tkN = tkNN(stmt, i);
		Term_setReadOnly(tkN, 0);
		if(TT_(tkN) == TT_ASIS) continue;
		if(TT_(tkN) != TT_NAME) {
			return ERROR_text(ctx, "unsupported token for tuple selection" K_TRACEPOINT);
		}
		kTerm *tkRES = TNAME_typing(ctx, tkN, TYPE_dyn, _FINDLOCAL | _FINDFIELD | _FINDSCRIPT | CheckReadOnly);
		if(tkRES == NULL) {
			ktype_t type = knh_Param_get(ct->cparam, i)->type;
			LET_addVAR(ctx, stmt, i, type, tkN);
		}
	}
	{
		BEGIN_BLOCK(stmt, espidx);
		kTerm *tkASIS = new_(Term);
		kTerm *tkIDX = GammaBuilder_addLVAR(ctx, 0, tplcid, FN_, 1);
		//DBG_P("espidx=%d, tkIDX->index=%d, GammaBuilder_espidx()=%d", espidx, tkIDX->index, GammaBuilder_espidx(ctx));
		kStmtExpr *stmtLET = new_Stmt2(ctx, STT_LET, tkASIS, tkIDX, tmNN(stmt, msize), NULL);
		kStmtExpr *stmtTAIL = stmtLET;
		size_t ti = 0;
		Stmt_setESPIDX(ctx, stmtTAIL);
		stmtTAIL->type = TYPE_void;
		for(i = 0; i < tsize; i++) {
			kTerm *tkN = tkNN(stmt, i);
			if(TT_(tkN) != TT_ASIS) {
				kStmtExpr *stmtLET2 = NULL;
				kTerm *tkTPL = new_TermTYPED(ctx, TT_FIELD, tkN->type, ti);
				KNH_SETv(ctx, tkTPL->data, tkIDX);
				if(TT_(tkN) == TT_LVAR || TT_(tkN) == TT_FVAR || TT_(tkN) == TT_FIELD || TT_(tkN) == TT_LFIELD) {
					stmtLET2 = new_Stmt2(ctx, STT_LET, tkASIS, tkN, tkTPL, NULL);
				}
				DBG_ASSERT(stmtLET2 != NULL);
				KNH_INITv(DP(stmtTAIL)->nextNULL, stmtLET2);
				stmtTAIL = stmtLET2;
				Stmt_setESPIDX(ctx, stmtTAIL);
				stmtTAIL->type = TYPE_void;
				ti++;
				DBLNDATA_(if(IS_Tunbox(tkN->type)) ti++;)
			}
		}
		Stmt_toSTT(stmt, STT_BLOCK);
		kStmtExprrimToSize(ctx, stmt, 1);
		KNH_SETv(ctx, stmtNN(stmt, 0), stmtLET);
		END_BLOCK(stmt, espidx);
	}
	return Stmt_typed(ctx, stmt, TYPE_void);
}

static kTerm *SELECT_typing(CTX ctx, kStmtExpr *stmt)
{
	size_t i, msize = DP(stmt)->size - 1;
	int CheckReadOnly = 0;  // TODO
	TYPING_UntypedExpr(ctx, stmt, msize);
	kclass_t cid = Tn_cid(stmt, msize);
	const knh_ClassTBL_t *ct = ClassTBL(cid);
	if(ct->bcid == CLASS_Tuple) {
		WARN_MuchBetter(ctx, "=", "from");
		STT_(stmt) = STT_LETM;
		return LETM_typing(ctx, stmt);
	}
	kMethod *getters[msize];
	for(i = 0; i < msize; i++) {
		kTerm *tkN = tkNN(stmt, i);
		Term_setReadOnly(tkN, 0);
		if(TT_(tkN) == TT_ASIS) continue;
		if(TT_(tkN) != TT_NAME) {
			return ERROR_text(ctx, "unsupported token for selector" K_TRACEPOINT);
		}
		ksymbol_t fn = Term_fn(ctx, tkN);
		kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, cid, MN_toGETTER(fn));
		if(mtd == NULL) {
			mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, cid, MN_toISBOOL(fn));
			if(mtd == NULL) {
				return ERROR_Undefined(ctx, "field", cid, tkN);
			}
		}
		getters[i] = mtd;
		ktype_t rtype = knh_Method_rtype(ctx, mtd, cid);
		kTerm *tkRES = TNAME_typing(ctx, tkN, rtype, _FINDLOCAL | _FINDFIELD | _FINDSCRIPT | CheckReadOnly);
		if(tkRES == NULL) {
			LET_addVAR(ctx, stmt, i, rtype, tkN);
		}
		else if(rtype != tkRES->type) {

		}
		DBG_P("rtype=%s, tkN->type=%s", TYPE__(rtype), TYPE__(tkN->type));
	}
	{
		BEGIN_BLOCK(stmt, espidx);
		kTerm *tkASIS = new_(Term);
		kTerm *tkOBJ = GammaBuilder_addLVAR(ctx, 0, cid, FN_, 1);
		//DBG_P("espidx=%d, tkIDX->index=%d, GammaBuilder_espidx()=%d", espidx, tkIDX->index, GammaBuilder_espidx(ctx));
		kStmtExpr *stmtLET = new_Stmt2(ctx, STT_LET, tkASIS, tkOBJ, tmNN(stmt, msize), NULL);
		kStmtExpr *stmtTAIL = stmtLET;
		Stmt_setESPIDX(ctx, stmtTAIL);
		stmtTAIL->type = TYPE_void;
		for(i = 0; i < msize; i++) {
			kTerm *tkN = tkNN(stmt, i);
			DBG_ASSERT(TT_(tkN) == TT_LVAR || TT_(tkN) == TT_FVAR || TT_(tkN) == TT_FIELD || TT_(tkN) == TT_LFIELD);
			kStmtExpr *stmtLET2 = NULL;
			kTerm *tkMTD = new_TermTYPED(ctx, TT_MN, TYPE_void, 0);
			Term_setMethod(ctx, tkMTD, getters[i]->mn, getters[i]);
			kStmtExpr *stmtGET = new_Stmt2(ctx, STT_CALL, tkMTD, GammaBuilder_tokenIDX(ctx, new_TermTYPED(ctx, TT_LVAR, tkOBJ->type, tkOBJ->index)), NULL);
			stmtGET->type = tkN->type;
			stmtLET2 = new_Stmt2(ctx, STT_LET, tkASIS, tkN, stmtGET, NULL);
			KNH_INITv(DP(stmtTAIL)->nextNULL, stmtLET2);
			stmtTAIL = stmtLET2;
			Stmt_setESPIDX(ctx, stmtTAIL);
			stmtTAIL->type = TYPE_void;
		}
		Stmt_toSTT(stmt, STT_BLOCK);
		kStmtExprrimToSize(ctx, stmt, 1);
		KNH_SETv(ctx, stmtNN(stmt, 0), stmtLET);
		END_BLOCK(stmt, espidx);
	}
	return Stmt_typed(ctx, stmt, TYPE_void);
}


/* a[i], a[2] = a, j */

static kTerm *SWAP_typing(CTX ctx, kStmtExpr *stmt)
{
	size_t i, msize = DP(stmt)->size / 2;
	for(i = 0; i < msize; i++) {
		kTerm *tkN = tkNN(stmt, i);
		if(TT_(tkN) == TT_NAME) {
			Term_setReadOnly(tkN, 0);
			kTerm *tkRES = TNAME_typing(ctx, tkN, TYPE_dyn, _FINDLOCAL | _FINDFIELD | _FINDSCRIPT | _CHECKREADONLY);
			if(tkRES == NULL) { /* not found */
				tkRES = TNAME_infer(ctx, tkN, stmt, msize+i);
				if(TT_(tkRES) == TT_ERR) return tkRES;
				KNH_SETv(ctx, tkNN(stmt, i), tkRES);
			}
			else {
				if(TT_(tkRES) == TT_ERR) return tkRES;
				TYPING_TypedExpr(ctx, stmt, msize+i, tkRES->type);
			}
			continue;
		}
		if(STT_(stmtNN(stmt, i)) == STT_CALL){
			kStmtExpr *stmtGET = stmtNN(stmt, i);
			kTerm *tkM = tkNN(stmtGET, 0);
			TYPING_UntypedExpr(ctx, stmt, msize+i);
			if(Term_isGetter(tkM)) {
				Term_setGetter(tkM, 0);
				Term_setSetter(tkM, 1);
				knh_Stmt_add(ctx, stmtGET, tkNN(stmt, msize+i));
				TYPING_TypedExpr(ctx, stmt, i, TYPE_void);
				continue;
			}
		}
		return ERROR_UnableToAssign(ctx, tkN);
	}
	{
		BEGIN_BLOCK(stmt, espidx);
		kTerm *tkASIS = new_(Term);
		kStmtExpr *stmtLET = NULL;
		kStmtExpr *stmtTAIL = NULL;
		for(i = 0; i < msize; i++) {
			kTerm *tkV = tkNN(stmt, msize + i);
			if(TT_(tkV) == TT_CONST) continue;
			kTerm *tkIDX = GammaBuilder_addLVAR(ctx, 0, tkV->type, FN_, 1);
			kStmtExpr *stmtR = new_Stmt2(ctx, STT_LET, tkASIS, tkIDX, tmNN(stmt, msize+i), NULL);
			KNH_SETv(ctx, tmNN(stmt, msize+i), tkIDX); //
			Stmt_setESPIDX(ctx, stmtR);
			if(stmtLET == NULL) {
				stmtLET = stmtR;
			}
			else {
				KNH_INITv(DP(stmtTAIL)->nextNULL, stmtR);
			}
			stmtTAIL = stmtR;
			stmtTAIL->type = TYPE_void;
		}
		for(i = 0; i < msize; i++) {
			kStmtExpr *stmtL;
			kTerm *tkIDX = tkNN(stmt, msize+i); //
			if(STT_(stmtNN(stmt, i)) == STT_CALL) {
				stmtL = stmtNN(stmt, i);
				KNH_SETv(ctx, tkNN(stmtL, (DP(stmtL)->size-1)), tkIDX);
			}
			else {
				DBG_P("TT=%s", TT__(tkNN(stmt, i)->tt));
				stmtL = new_Stmt2(ctx, STT_LET, tkASIS, tkNN(stmt, i), tkIDX, NULL);
			}
			Stmt_setESPIDX(ctx, stmtL);
			DBG_P("DP(stmt)->espidx=%d", DP(stmt)->espidx);
			if(stmtLET == NULL) { stmtLET = stmtL; }
			else {
				KNH_INITv(DP(stmtTAIL)->nextNULL, stmtL);
			}
			stmtTAIL = stmtL;
			stmtTAIL->type = TYPE_void;
		}
		knh_Stmt_add(ctx, stmt, tkASIS); // for RCGC;
		Stmt_toSTT(stmt, STT_BLOCK);
		KNH_SETv(ctx, stmtNN(stmt, 0), stmtLET);
		kStmtExprrimToSize(ctx, stmt, 1);
		END_BLOCK(stmt, espidx);
	}
	return Stmt_typed(ctx, stmt, TYPE_void);
}

static kTerm* CALL1_typing(CTX ctx, kStmtExpr *stmt, ktype_t reqt)
{
	if(IS_StmtExpr(DP(stmt)->stmtPOST)) {
		kStmtExpr *stmtPOST = DP(stmt)->stmtPOST;
		kTerm *tkRES = Stmt_typing(ctx, DP(stmt)->stmtPOST, reqt);
		if(TT_(tkRES) == TT_ERR) return tkRES;
		DBG_ASSERT((void*)(tkRES) == (void*)stmtPOST);
		Stmt_setESPIDX(ctx, stmtPOST);
		if(reqt == TYPE_stmtexpr) {
			stmtPOST->type = TYPE_void;
			STT_(stmt) = STT_BLOCK;
			KNH_SETv(ctx, stmtNN(stmt, 0), stmtPOST);
			return Stmt_typed(ctx, stmt, TYPE_void);
		}
	}
//	else {
//		if(reqt == TYPE_stmtexpr) {
//			WarningNoEffect(ctx);
//			return knh_Stmt_done(ctx, stmt);
//		}
//	}
	TYPING_TypedExpr(ctx, stmt, 0, reqt);
	return Stmt_typed(ctx, stmt, Tn_type(stmt, 0));
}

/* ------------------------------------------------------------------------ */

static inline void unboxSFP(CTX ctx, ksfp_t *sfp)
{
	sfp[0].ndata = (sfp[0].i)->n.data;
}

static kTerm* CALL_toCONST(CTX ctx, kStmtExpr *stmt, kMethod *mtd)
{
	int isCONST = 0;
	size_t size = DP(stmt)->size;
#ifdef K_USING_DEBUG
	if(Method_isConst(mtd) || GammaBuilder_isEnforceConst(ctx->gma)) {
#else
	if(Method_isConst(mtd) || GammaBuilder_isEnforceConst(ctx->gma) || IS_SCRIPTLEVEL(ctx)) {
#endif
		size_t i = STT_(stmt) == TT_NEW ? 2: 1;
		for(; i < size; i++) {
			kTerm *tk = tkNN(stmt, i);
			if(TT_(tk) == TT_CID) {
				Term_setCONST(ctx, tk, new_Type(ctx, tk->cid));
			}
			if(TT_(tk) != TT_CONST && TT_(tk) != TT_NULL) goto L_NEXT;
		}
		isCONST = 1;
	}
	L_NEXT: ;
	//DBG_P("isCONST=%d, %d", isCONST,  GammaBuilder_isEnforceConst(ctx->gma));
	if(isCONST) {
		BEGIN_LOCAL(ctx, lsfp, DP(stmt)->size + K_CALLDELTA);
		long rtnidx = 0, thisidx = rtnidx + K_CALLDELTA;
		kTerm *rvalue;
		size_t i = 1;
		if(MN_isNEW((mtd)->mn)) {
			kclass_t cid = CLASS_t(stmt->type);
			//DBG_P("CONST NEW", CLASS__(cid));
			KNH_SETv(ctx, lsfp[thisidx].o, new_Object_init2(ctx, ClassTBL(cid)));
			i = 2;
		}
		DBG_P("STMT = %s TURNED INTO CONST", TT__(STT_(stmt)));
		for(; i < size; i++) {
			kTerm *tk = tkNN(stmt, i);
			if(TT_(tk) == TT_NULL) {    // Int.class
				KNH_SETv(ctx, (tk)->data, KNH_NULVAL(tk->type));
			}
			KNH_SETv(ctx, lsfp[thisidx+(i-1)].o, (tk)->data);
			unboxSFP(ctx, &lsfp[thisidx+(i-1)]);
		}
		KNH_SCALL(ctx, lsfp, rtnidx, mtd, (size - 2));
		knh_boxing(ctx, &lsfp[rtnidx], stmt->type);
		rvalue = ((DP(mtd)->mp)->rsize == 0) ? knh_Stmt_done(ctx, stmt) : Term_setCONST(ctx, tkNN(stmt, 0), lsfp[0].o);
		END_LOCAL(ctx, lsfp);
		return rvalue;
	}
	else {
		kclass_t mtd_cid = mtd->cid, this_cid = Tn_cid(stmt, 1);
		if(IS_Tunbox(this_cid) && (mtd_cid == CLASS_Object || mtd_cid == CLASS_Number)) {
			Stmt_boxAll(ctx, stmt, 1, 2, mtd_cid);
		}
	}
	return TM(stmt);
}

static void METHOD_asm(CTX ctx, kStmtExpr *stmt);

static kTerm *new_TermDEFAULT(CTX ctx, kclass_t cid, ktype_t reqt)
{
	switch(cid) {
	case CLASS_Class:
		reqt = (reqt == TYPE_var) ? TYPE_dyn : reqt;
		return new_TermCONST(ctx, new_Type(ctx, reqt));
	case CLASS_NameSpace: return new_TermCONST(ctx, K_GMANS);
	case CLASS_Script: return new_TermCONST(ctx, ctx->gma->scr);
	default:
		return new_TermTYPED(ctx, TT_NULL/*DEFVAL*/, cid, cid);
	}
}

static kTerm *new_TermCODE(CTX ctx, kTerm *tkD)
{
	DBG_ASSERT(IS_Term(tkD));
	DBG_ASSERT(TT_(tkD) == TT_DOC);
	kTerm *tk = new_(Term);
	TT_(tk) = TT_CODE;
	KNH_SETv(ctx, tk->data, tkD->data);
	tk->uline = tkD->uline;
	DBG_P("compiling '''%s'''", S_totext(tkD->text));
	return tk;
}

static void StmtCALL_lazyasm(CTX ctx, kStmtExpr *stmt, kMethod *mtd)
{
	Method_setDynamic(mtd, 0);
	if(IS_Term(DP(mtd)->tsource)) {
		size_t i;
		BEGIN_LOCAL(ctx, lsfp, 3);
		DBG_P("dynamic compiled method");
		LOCAL_NEW(ctx, lsfp, 0, kGammaBuilder*, gma, ctx->gma);
		LOCAL_NEW(ctx, lsfp, 1, kTerm*, tkC, new_TermCODE(ctx, DP(mtd)->tsource));
		LOCAL_NEW(ctx, lsfp, 2, kStmtExpr*, stmtB, knh_Term_parseStmt(ctx, 0, tkC));
		kParam *pa = DP(mtd)->mp;
		for(i = 0; i < pa->psize; i++) {
			kparam_t *p = knh_Param_get(pa, i);
			if(p->type == TYPE_var) {
				p->type = tmNN(stmt, i+2)->type;
				INFO_Typing(ctx, FN__(p->fn), STEXT(""), p->type);
			}
		}
		KNH_SETv(ctx, ((kcontext_t*)ctx)->gma, new_(GammaBuilder));
		knh_GammaBuilder_init(ctx);
		DBG_ASSERT(IS_bScript(DP(mtd)->gmascr));
		KNH_SETv(ctx, ctx->gma->scr, DP(mtd)->gmascr);
		knh_Method_asm(ctx, mtd, stmtB, typingMethod2);
		DBG_ASSERT(!IS_bScript(DP(mtd)->gmascr));
		Stmt_typed(ctx, stmt, knh_Param_rtype(pa));
		KNH_SETv(ctx, ((kcontext_t*)ctx)->gma, gma);
		END_LOCAL(ctx, lsfp); // NEED TO CHECK
	}
	else {
		kMethodoAbstract(ctx, mtd);
	}
}

static kTerm* CALLPARAMs_typing(CTX ctx, kStmtExpr *stmt, ktype_t tcid, kclass_t new_cid, kMethod *mtd)
{
	size_t i, size = DP(stmt)->size;
	kParam *pa = DP(mtd)->mp;
	ktype_t rtype = ktype_tocid(ctx, knh_Param_rtype(pa), new_cid);
	if(rtype == TYPE_var && DP(ctx->gma)->mtd == mtd) {
		return ERROR_Unsupported(ctx, "type inference of recursive calls", CLASS_unknown, NULL);
	}
	Stmt_typed(ctx, stmt, rtype);
	for(i = 0; i < pa->psize; i++) {
		size_t n = i + 2;
		kparam_t* p = knh_Param_get(pa, i);
		ktype_t param_reqt = ktype_tocid(ctx, p->type, new_cid);
		if(n < size) {
			TYPING_TypedExpr(ctx, stmt, n, param_reqt);
		}
		else {
			if(/*!(n < size) &&*/ !Param_isVARGs(pa)) {
				if(param_reqt == TYPE_var) {
					return ERROR_RequiredParameter(ctx);
				}
				else {
					knh_Stmt_add(ctx, stmt, new_TermDEFAULT(ctx, param_reqt, CLASS_t(tcid)));
				}
			}
		}
		if(param_reqt == CLASS_Class) { // Method_isSmart
			if(rtype == CLASS_Tvar || (Method_isSmart(mtd) && C_bcid(tcid) == C_bcid(rtype))) {
				Stmt_typed(ctx, stmt, CLASS_t(tcid));
			}
		}
	}
	if(Param_isVARGs(pa)) {
		ktype_t param_reqt = knh_Param_get(pa, i)->type;
		param_reqt = ktype_tocid(ctx, param_reqt, new_cid);
		for(i = pa->psize; i + 2 < size; i++) {
			TYPING_TypedExpr(ctx, stmt, i+2, param_reqt);
		}
	}
	else if(i + 2 < size) {
		WARN_TooMany(ctx, "parameters", MN__(mtd->mn));
		kStmtExprrimToSize(ctx, stmt, i+2);
	}
	if(Method_isDynamic(mtd)) {
		StmtCALL_lazyasm(ctx, stmt, mtd);
		if(Method_isAbstract(mtd)) {
			WARN_MethodIs(ctx, mtd, "abstract");
		}
	}
	return CALL_toCONST(ctx, stmt, mtd);
}

static void NameSpace_lookupMethods(CTX ctx, kNameSpace *ns, kclass_t cid, kmethodn_t mn, kMethod **mlists, size_t remaining)
{
	size_t i;
	while(ns != NULL) {
		if(DP(ns)->methodsNULL != NULL) {
			kArray *methods = DP(ns)->methodsNULL;
			for(i = 0; i < knh_Array_size(methods); i++) {
				kMethod *mtd = methods->methods[i];
				if(mtd->cid == cid && mtd->mn == mn) {
					mlists[0] = mtd;
					mlists++;
					remaining--;
					if(remaining == 0) return ;
				}
			}
		}
		ns = ns->parentNULL;
	}
	{
		const knh_ClassTBL_t *p , *t0 = ClassTBL(cid);
		do {
			size_t i;
			kArray *a = t0->methods;
			for(i = 0; i < knh_Array_size(a); i++) {
				kMethod *mtd = a->methods[i];
				if((mtd)->mn == mn) {
					mlists[0] = mtd;
					mlists++;
					remaining--;
					if(remaining == 0) return ;
				}
			}
			p = t0;
			t0 = t0->supTBL;
		}
		while(p != t0);
	}
}

static kTerm* OLCALLPARAMs_typing(CTX ctx, kStmtExpr *stmt, ktype_t tcid, kclass_t new_cid, kMethod *mtd0)
{
	size_t i, size = DP(stmt)->size;
	kMethod *mlists[32] = {NULL}, **mp = mlists;
	kMethod *tmtd = NULL;
	NameSpace_lookupMethods(ctx, K_GMANS, mtd0->cid, mtd0->mn, mlists, 30);
	for(i = 2; i < size; i++) {
		TYPING_UntypedExpr(ctx, stmt, i);
	}
	while(*mp != NULL) {
		kMethod *mtd = mp[0];
		kParam *pa = DP(mtd)->mp;
		if(size - 2 == pa->psize) {
			int status = 0;
			for(i = 0; i < pa->psize; i++) {
				size_t n = i + 2;
				kparam_t* p = knh_Param_get(pa, i);
				ktype_t param_reqt = ktype_tocid(ctx, p->type, new_cid);
				ktype_t type = Tn_type(stmt, n);
				if(type == param_reqt || ClassTBL_isa_(ctx, ClassTBL(type), ClassTBL(param_reqt)) || param_reqt == TYPE_dynamic) {
					continue;
				}
				kTypeMap *tmr =knh_findTypeMapNULL(ctx, type, param_reqt);
				if(tmr != NULL && TypeMap_isSemantic(tmr)) {
					status = 1; // needs type coerusion
					continue;
				}
				status = 2; break;
			}
			if(status == 0) {
				ktype_t rtype = ktype_tocid(ctx, knh_Param_rtype(pa), new_cid);
				Stmt_typed(ctx, stmt, rtype);
				KNH_SETv(ctx, tkNN(stmt, 0)->data, mtd);
				return CALL_toCONST(ctx, stmt, mtd);
			}
			if(status == 1 && tmtd != NULL) {
				tmtd = mtd;
			}
		}
		mp++;
	}
	if(tmtd != NULL) {
		KNH_SETv(ctx, tkNN(stmt, 0)->data, tmtd);
		return CALLPARAMs_typing(ctx, stmt, tcid, new_cid, tmtd);
	}
	return ERROR_Unsupported(ctx, "no matched method", mtd0->cid, NULL);
}

static inline kint_t Tn_int(kStmtExpr *stmt, size_t n)
{
	kTerm *tk = tkNN(stmt, n);
	DBG_ASSERT(TT_(tk) == TT_CONST);
	return ((tk)->num)->n.ivalue;
}

static kTerm* CALL_typing(CTX ctx, kStmtExpr *stmt, kclass_t tcid)
{
	kTerm *tkM = tkNN(stmt, 0);
	kTerm *tkO = tkNN(stmt, 1);
	int maybeCLASSCONST = (TT_(tkM) == TT_UNAME && TT_(tkO) == TT_UNAME && DP(stmt)->size == 2) ? 1 : 0;
	kmethodn_t mn = Term_mn(ctx, tkM);
	kMethod *mtd = NULL;
	kclass_t mtd_cid = CLASS_Object;
	DBG_ASSERT(TT_(tkO) != TT_ASIS);
	if(MN_isNEW(mn)) { /* reported by Maeda */
		return ERROR_Unsupported(ctx, "calling new as method", CLASS_unknown, NULL);
	}
	TYPING_UntypedExpr(ctx, stmt, 1);
	if(Tn_isCID(stmt, 1)) {
		kTermoTYPED(ctx, tkO, TT_NULL/*DEFVAL*/, (tkO)->cid, (tkO)->cid);
	}
	mtd_cid = Tn_cid(stmt, 1);
	mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, mtd_cid, mn);
	if(mtd == NULL) {
		if(DP(stmt)->size == 3 && MN_isSETTER(mn)) {
			TYPING_UntypedExpr(ctx, stmt, 2);
			DBG_P("ptype=%s", TYPE__(Tn_type(stmt, 2)));
			mtd = knh_NameSpace_addXSetter(ctx, K_GMANS, ClassTBL(mtd_cid), Tn_type(stmt, 2), mn);
		}
	}
	if(mtd != NULL) {
		if(Method_isRestricted(mtd)) {
			return ERROR_MethodIsNot(ctx, mtd, "allowed");
		}
		if(IS_Tunbox(mtd_cid) && !IS_Tunbox(mtd->cid)) {
			Stmt_boxAll(ctx, stmt, 1, 2, mtd->cid);
		}
		Term_setMethod(ctx, tkM, mn, mtd);
		if(Method_isOverload(mtd)) {
			return OLCALLPARAMs_typing(ctx, stmt, tcid, mtd_cid, mtd);
		}
		return CALLPARAMs_typing(ctx, stmt, tcid, mtd_cid, mtd);
	}
	else {
		size_t i;
		if(maybeCLASSCONST) {
			kObject *v = knh_getClassConstNULL(ctx, mtd_cid, S_tobytes((tkM)->text));
			if(v != NULL) {
				return Term_setCONST(ctx, tkM, v);
			}
			TT_(tkM) = TT_UNAME; tkM->flag0 = 0;
			return ERROR_Undefined(ctx, "const", mtd_cid, tkM);
		}
		Term_setMethod(ctx, tkM, mn, mtd);
		if(C_bcid(mtd_cid) == CLASS_Tuple && (mn == MN_get || mn == MN_set)) { // t[0] = 1;
			kParam *pa = ClassTBL(mtd_cid)->cparam;
			size_t psize = pa->psize;
			TYPING(ctx, stmt, 2, TYPE_Int, _CONSTONLY);
			kint_t ivalue = (kint_t)Tn_int(stmt, 2);
			size_t n = (ivalue < 0) ? psize + ivalue : ivalue;
			if(!(n < psize)) {
				return ERROR_OutOfIndex(ctx, 0, ivalue, psize);
			}
			tkNN(stmt,2)->index = n;
			kparam_t *p = knh_Param_get(pa, n);
			if(mn == MN_get) {
				return Stmt_typed(ctx, stmt, p->type);
			}
			else { /* mtd_mn == MN_set */
				TYPING_TypedExpr(ctx, stmt, 3, p->type);
				return Stmt_typed(ctx, stmt, TYPE_void);
			}
		}
		if(mtd_cid != TYPE_dyn) {
			return ERROR_Undefined(ctx, "method", mtd_cid, tkM);
		}
		for(i = 2; i < DP(stmt)->size; i++) {
			TYPING_UntypedObject(ctx, stmt, i);
		}
		return Stmt_typed(ctx, stmt, TYPE_dyn);
	}
}

/* ------------------------------------------------------------------------ */
/* [built-in function] */

static kTerm* defined_typing(CTX ctx, kStmtExpr *stmt)
{
	kTerm *tk = tkNN(stmt, 0);
	if(TT_(tk) == TT_URN) {
		kTerm *tkRES = Tn_typing(ctx, stmt, 2, TYPE_Boolean, _NOWARN | _NOCHECK);
		if(TT_(tkRES) == TT_ERR) {
			Term_setCONST(ctx, tk, KNH_FALSE);
		}
		return tk;
	}
	else {
		kTerm *tkRES = Tn_typing(ctx, stmt, 2, TYPE_dyn, _NOWARN | _NOCHECK);
		if(TT_(tkRES) != TT_ERR) {
			return Term_setCONST(ctx, tk, KNH_TRUE);
		}
		else {
			return Term_setCONST(ctx, tk, KNH_FALSE);
		}
	}
}

//static kTerm* copy_typing(CTX ctx, kStmtExpr *stmt)
//{
//	kTerm *tkRES = Tn_typing(ctx, stmt, 2, TYPE_dyn, 0);
//	if(TT_(tkRES) == TT_ERR) {
//		return tkRES;
//	}
//	else {
//		kclass_t cid = Tn_cid(stmt, 2);
//		if(knh_class_canObjectCopy(ctx, cid)) {
//			kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, CLASS_Object, MN_copy);
//			KNH_SETv(ctx, tmNN(stmt, 1), tmNN(stmt, 2));
//			Term_setMethod(ctx, tkNN(stmt, 0), MN_copy, mtd);
//			kStmtExprrimToSize(ctx, stmt, 2);
//			/* XXX(imasahiro) rewrite FUNCCALL => CALL */
//			STT_(stmt) = STT_CALL;
//			return Stmt_typed(ctx, stmt, cid);
//		}
//		else {
//			WarningUnnecessaryOperation(ctx, "copy");
//			return tkNN(stmt, 2);
//		}
//	}
//}

static kTerm* this_typing(CTX ctx, kStmtExpr *stmt, kmethodn_t mn)
{
	kclass_t mtd_cid = DP(ctx->gma)->this_cid;
	kTerm *tkMTD = tkNN(stmt, 0); /* change */
	kMethod *mtd;
	mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, mtd_cid, MN_new);
	if(mtd == NULL || (mtd)->cid != mtd_cid) {
		return ErrorUnsupportedConstructor(ctx, mtd_cid);
	}
	kTermoTYPED(ctx, tkNN(stmt, 1), TT_FVAR, TYPE_cid(mtd_cid), 0); /* this */
	Term_setMethod(ctx, tkMTD, MN_new, mtd);
	return TM(stmt);
}


static kclass_t class_FuncType(CTX ctx, kclass_t this_cid, kMethod *mtd)
{
	kclass_t cid;
	kParam *pa = DP(mtd)->mp;
	if(knh_Param_hasTypeVar(pa)) {
		BEGIN_LOCAL(ctx, lsfp, 1);
		kParam *npa = new_Param(ctx);
		KNH_SETv(ctx, lsfp[0].o, npa);
		kParamocid(ctx, pa, this_cid, npa);
		cid = knh_class_Generics(ctx, CLASS_Func, npa);
		END_LOCAL(ctx, lsfp);
	}
	else {
		cid = knh_class_Generics(ctx, CLASS_Func, pa);
	}
	return cid;
}

/* delegate, iterate */

static kFunc * new_StaticFunc(CTX ctx, kclass_t cid, kMethod *mtd)
{
	kFunc *fo = new_H(Func);
	O_cTBL(fo) = ClassTBL(cid);
	KNH_INITv(fo->mtd, mtd);
	fo->baseNULL = NULL;
//	fo->xsfp = NULL;
//	fo->xsize = 0;
	return fo;
}

static kTerm* delegate_typing(CTX ctx, kStmtExpr *stmt)
{
	if(DP(stmt)->size == 4) {
		kTerm *tkMN = tkNN(stmt, 3);
		TYPING_UntypedExpr(ctx, stmt, 2);
		kclass_t cid = Tn_cid(stmt, 2), this_cid = DP(ctx->gma)->this_cid;
		if(Tn_isCID(stmt, 2)) { /* delegate(Class, f) */
			kTerm *tkC = tkNN(stmt, 2);
			kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, (tkC)->cid, Term_mn(ctx, tkMN));
			if(mtd == NULL) {
				return ERROR_Undefined(ctx, "method", (tkC)->cid, tkMN);
			}
			if(!Method_isStatic(mtd)) {
				return ERROR_MethodIsNot(ctx, mtd, "static");
			}
			cid = class_FuncType(ctx, this_cid, mtd);
			return Term_setCONST(ctx, tkMN, new_StaticFunc(ctx, cid, mtd));
		}
		else {
			kclass_t cid = Tn_cid(stmt, 2);
			kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, cid, Term_mn(ctx, tkMN));
			if(mtd == NULL) {
				return ERROR_Undefined(ctx, "method", cid, tkMN);
			}
			cid = class_FuncType(ctx, this_cid, mtd);
			if(Method_isStatic(mtd)) {
				return Term_setCONST(ctx, tkMN, new_StaticFunc(ctx, cid, mtd));
			}
			kTermoCID(ctx, tkNN(stmt, 1), cid);
			Term_setCONST(ctx, tkNN(stmt, 3), mtd);
			STT_(stmt) = STT_NEW;
			mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, CLASS_Func, MN_new);
			DBG_ASSERT(mtd != NULL);
			Term_setMethod(ctx, tkNN(stmt, 0), (mtd)->mn, mtd);
			return Stmt_typed(ctx, stmt, cid);
		}
	}
	else {
		return ERROR_text(ctx, "delegate(expr, methodname)" K_TRACEPOINT);
	}
}

static kTerm* proceed_typing(CTX ctx, kStmtExpr *stmt, ktype_t reqt)
{
	if(DP(ctx->gma)->proceedNC != NULL) {
		kMethod *promtd = DP(ctx->gma)->proceedNC;
		kclass_t this_cid = DP(ctx->gma)->this_cid;
		KNH_ASSERT(IS_Method(promtd));
		Term_setMethod(ctx, tkNN(stmt, 0), promtd->mn, promtd);
		KNH_SETv(ctx, tkNN(stmt, 1), new_TermTYPED(ctx, TT_FVAR, this_cid, 0));
		STT_(stmt) = STT_CALL;
		if(DP(stmt)->size == 2) {
			size_t i;
			for(i=0; i < knh_Method_psize(promtd); i++) {
				knh_Stmt_add(ctx, stmt, new_TermTYPED(ctx, TT_FVAR, DP(ctx->gma)->gf[i+1].type, i+1));
			}
		}
		return CALLPARAMs_typing(ctx, stmt, reqt, this_cid, promtd);
	}
	else {
		return ERROR_text(ctx, "proceed(...) must be in @Around" K_TRACEPOINT);
	}
}

static kTerm* FUNCCALLPARAMs_typing(CTX ctx, kStmtExpr *stmt, ktype_t reqt)
{
	size_t i;
	kclass_t cid = Tn_cid(stmt, 0);
	DBG_ASSERT(IS_Tfunc(cid));
	kParam *pa = ClassTBL(cid)->cparam;
	kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, cid, MN_);
	KNH_ASSERT(mtd != NULL);
		/* 0 1 2 3 4 .. 5 */
	knh_Stmt_swap(ctx, stmt, 0, 1);
	DBG_ASSERT(TT_(tkNN(stmt, 0)) == TT_ASIS);
	Term_setMethod(ctx, tkNN(stmt, 0), MN_, mtd);
	for(i = 0; i < pa->psize; i++) {
		kparam_t *p = knh_Param_get(pa, i);
		ktype_t type = GammaBuilder_type(ctx, p->type);
		if(2 + i < DP(stmt)->size) {
			TYPING_TypedExpr(ctx, stmt, 2 + i, type);
		}
		else {
			knh_Stmt_add(ctx, stmt, new_TermTYPED(ctx, TT_NULL/*DEFVAL*/, type, CLASS_t(type)));
		}
	}
	if(pa->psize + 2 < DP(stmt)->size) {
		WARN_TooMany(ctx, "parameters", "function");
		kStmtExprrimToSize(ctx, stmt, 2+ pa->psize);
	}
	STT_(stmt) = STT_FUNCCALL;
	reqt = GammaBuilder_type(ctx, knh_Param_rtype(pa));
	return Stmt_typed(ctx, stmt, reqt);
}

static kTerm* FUNCDYNCALL_typing(CTX ctx, kStmtExpr *stmt, ktype_t reqt)
{
	BEGIN_LOCAL(ctx, lsfp, 1);
	size_t i;
	kclass_t cid = CLASS_Func;
	LOCAL_NEW(ctx, lsfp, 0, kParam*, pa, new_Param(ctx));
	for(i = 2; i < DP(stmt)->size; i++) {
		TYPING_UntypedObject(ctx, stmt, i);
		knh_Param_addParam(ctx, pa, Tn_type(stmt, i), FN_);
	}
	knh_Param_addReturnType(ctx, pa, (reqt == TYPE_var) ? TYPE_dyn : reqt);
	cid = knh_class_Generics(ctx, CLASS_Func, pa);
	DBG_ASSERT(cid != CLASS_unknown);
	if(IS_String(tkNN(stmt,0)->text)) {
		INFO_Typing(ctx, "function ", S_tobytes(tkNN(stmt,0)->text), cid);
	}
	else {
		INFO_Typing(ctx, "function ", STEXT(""), cid);
	}
	tkNN(stmt, 0)->type = cid;
	Stmt_setDYNCALL(stmt, 1);
	{
		kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, cid, MN_);
		KNH_ASSERT(mtd != NULL);
		knh_Stmt_swap(ctx, stmt, 0, 1);
		DBG_ASSERT(TT_(tkNN(stmt, 0)) == TT_ASIS);
		Term_setMethod(ctx, tkNN(stmt, 0), MN_, mtd);
	}
	END_LOCAL(ctx, lsfp);
	STT_(stmt) = STT_FUNCCALL;
	reqt = GammaBuilder_type(ctx, knh_Param_rtype(pa));
	return Stmt_typed(ctx, stmt, reqt);
}

static kTerm* func_typingNULL(CTX ctx, kStmtExpr *stmt, kclass_t reqt)
{
	kTerm *tkF = tkNN(stmt, 0);
	kmethodn_t mn = Term_mn(ctx, tkF);
	kTerm *tkIDX = NULL;
	{ /* 1. lookup builtin function */
		switch(mn) {
//				case MN_likely:
//				case MN_unlikely: return FLIKELY_typing(ctx, stmt);
//				case MN_format:  return knh_StmtFFORMAT_typing(ctx, stmt);
//				case MN_domain:  return knh_StmtDOMAIN_typing(ctx, stmt);
//			case MN_copy: return copy_typing(ctx, stmt);
			case MN_defined: return defined_typing(ctx, stmt);
			case MN_this: return this_typing(ctx, stmt, mn);
			case MN_delegate: return delegate_typing(ctx, stmt);
			case MN_proceed: return proceed_typing(ctx, stmt, reqt);
		}
	}
	{ /* 2. searching local variable of Func */
		ksymbol_t fn = Term_fn(ctx, tkF);
		tkIDX = GammaBuilder_rindexFNQ(ctx, ctx->gma, fn, 0);
		if(tkIDX != NULL && IS_Tfunc(tkIDX->type)) {
			GammaBuilder_rindexFNQ(ctx, ctx->gma, fn, 1);  // use count
			KNH_SETv(ctx, tkNN(stmt, 0), tkIDX);
			return FUNCCALLPARAMs_typing(ctx, stmt, reqt);
		}
	}

	kclass_t mtd_cid = knh_NameSpace_getFuncClass(ctx, K_GMANS, mn);
	kMethod *mtd = NULL;

	/* 3. static function in namespace */
	if(mtd_cid != CLASS_unknown) {
		mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, mtd_cid, mn);
		if(mtd != NULL) {
			kTermoTYPED(ctx, tkNN(stmt, 1), TT_NULL, mtd_cid, mtd_cid);
			goto L_CALLPARAMs;
		}
	}
	mtd_cid = DP(ctx->gma)->this_cid;
	mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, mtd_cid, mn);
	if(mtd != NULL) {
		/* Removed by @imasahiro to improve method performance. */
		//GammaBuilder_foundFIELD(ctx->gma, 1);
		kTermoTYPED(ctx, tkNN(stmt, 1), TT_FVAR, mtd_cid, 0);
		goto L_CALLPARAMs;
	}

	if(mtd_cid != O_cid(K_GMASCR)) {
		mtd_cid = O_cid(K_GMASCR);
		mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, mtd_cid, mn);
		if(mtd != NULL) {
			kTermoTYPED(ctx, tkNN(stmt, 1), TT_NULL/*DEFVAL*/, mtd_cid, mtd_cid);
			goto L_CALLPARAMs;
		}
	}

	mtd_cid = CLASS_System;
	mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, mtd_cid, mn);
	DBG_P("********* mtd=%p", mtd);
	if(mtd != NULL) {
		if(Method_isRestricted(mtd)) {
			return ERROR_MethodIsNot(ctx, mtd, "allowed");
		}
		kTermoTYPED(ctx, tkNN(stmt, 1), TT_NULL/*DEFVAL*/, mtd_cid, mtd_cid);
		goto L_CALLPARAMs;
	}
	return NULL; // continue to variable ErrorUndefinedName(ctx, tkF);

	L_CALLPARAMs:;
	DBG_ASSERT(mtd != NULL);
	STT_(stmt) = STT_CALL;
	Term_setMethod(ctx, tkF, mn, mtd);
	{
		kTerm *tkRES;
		if(Method_isOverload(mtd)) {
			tkRES = OLCALLPARAMs_typing(ctx, stmt, reqt, mtd_cid, mtd);
		} else {
			tkRES = CALLPARAMs_typing(ctx, stmt, reqt, mtd_cid, mtd);
		}
		return tkRES;
	}
}

static kTerm* FUNCCALL_typing(CTX ctx, kStmtExpr *stmt, kclass_t reqt)
{
	kTerm *tkF = tkNN(stmt, 0);
	DBG_ASSERT(TT_(tkNN(stmt, 1)) == TT_ASIS);
	if(TT_(tkF) == TT_FUNCNAME || TT_(tkF) == TT_UFUNCNAME) {
		TT_(tkF) = TT_NAME;
	}
	if(TT_(tkF) == TT_NAME || TT_(tkF) == TT_UNAME) {
		tkF = func_typingNULL(ctx, stmt, reqt);
		if(tkF != NULL) {
			return tkF;
		}
		tkF = tkNN(stmt, 0);
		TT_(tkF) = TT_NAME;
	}
	TYPING_UntypedExpr(ctx, stmt, 0);
	ktype_t type = Tn_type(stmt, 0);
	if(type == TYPE_String && TT_(tkNN(stmt, 0)) == TT_CONST) {
		return FMTOP_typing(ctx, stmt, reqt);
	}
	if(IS_Tfunc(type)) {
		return FUNCCALLPARAMs_typing(ctx, stmt, reqt);
	}
	if(type == TYPE_dyn) {
		return FUNCDYNCALL_typing(ctx, stmt, reqt);
	}
	return ERROR_Needs(ctx, _("function"));
}

/* ------------------------------------------------------------------------ */
/* [NEW] */

static kTerm* NEWPARAMs_typing(CTX ctx, kStmtExpr *stmt, kclass_t new_cid, kmethodn_t mn, int needsTypingPARAMs)
{
	kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, new_cid, mn);
	kTerm *tkRES = (kTerm*)stmt;
	if(mtd == NULL || ClassTBL((mtd)->cid)->bcid != ClassTBL(new_cid)->bcid) {
		return ERROR_Undefined(ctx, _("constructor"), new_cid, tkNN(stmt, 0));
	}
	if(Method_isRestricted(mtd)) {
		return ERROR_MethodIsNot(ctx, mtd, "allowed");
	}
	DBG_P("new_cid=%s", CLASS__(new_cid));
	Term_setMethod(ctx, tkNN(stmt, 0), mn, mtd);
	kTermoCID(ctx, tkNN(stmt, 1), new_cid);
	tkRES->type = new_cid;
	if(Method_isOverload(mtd)) {
		tkRES = OLCALLPARAMs_typing(ctx, stmt, new_cid, new_cid, mtd);
	}
	else if(needsTypingPARAMs) {
		tkRES = CALLPARAMs_typing(ctx, stmt, new_cid, new_cid, mtd);
	}
	else {
		return CALL_toCONST(ctx, stmt, mtd);
	}
	stmt->type = new_cid;
	return tkRES;
}

#define IS_NEWLIST(cid)  (cid == CLASS_Array || cid == CLASS_Range)

static kTerm* FIELD_typing(CTX ctx, kclass_t cid, kStmtExpr *stmt, size_t n)
{
	kTerm *tkK = tkNN(stmt, n); DBG_ASSERT(IS_String(tkK->text));
	ksymbol_t fn = knh_getfnq(ctx, S_tobytes(tkK->text), FN_NEWID);
	kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, cid, MN_toSETTER(fn));
	if(mtd == NULL) {
		TYPING_UntypedExpr(ctx, stmt, n+1);
		mtd = knh_NameSpace_addXSetter(ctx, K_GMANS, ClassTBL(cid), Tn_type(stmt, n+1), fn);
		if(mtd == NULL) {
			WARN_Undefined(ctx, "field", cid, tkK);
		}
	}
	else if(knh_Method_psize(mtd) == 1) {
		ktype_t ptype = knh_Method_ptype(ctx, mtd, 0, cid);
		TYPING_TypedExpr(ctx, stmt, n+1, ptype);
		Stmt_boxAll(ctx, stmt, n+1, n+2, CLASS_Tdynamic);
	}
	else {
		TYPING_UntypedExpr(ctx, stmt, n+1);
	}
	return tkK; // OK
}

static kTerm* NEWMAP_typing(CTX ctx, kStmtExpr *stmt, kclass_t reqt)
{
	size_t i;
	if(reqt == TYPE_dyn || reqt == TYPE_Object) reqt = TYPE_Map;
	kclass_t breqt = C_bcid(reqt);
	DBG_P("mtdcid=%s, reqt=%s, bcid=%s", CLASS__(tkNN(stmt,1)->cid), CLASS__(reqt), CLASS__(breqt));
	for(i = 2; i < DP(stmt)->size; i+=2) {
		TYPING_TypedExpr(ctx, stmt, i, TYPE_String);  // key
	}
	if(breqt != CLASS_Map) {
		for(i = 2; i < DP(stmt)->size; i+=2) {
			kTerm *tkRES = FIELD_typing(ctx, CLASS_t(reqt), stmt, i);
			if(TT_(tkRES) == TT_ERR) return tkRES;
		}
		return NEWPARAMs_typing(ctx, stmt, CLASS_Map, MN_newMAP, 0/*needsTypingPARAMs*/);
	}
	else if(reqt != CLASS_Map) {
		kclass_t p2 = C_p2(reqt);
		for(i = 2; i < DP(stmt)->size; i+=2) {
			TYPING_TypedExpr(ctx, stmt, i+1, p2);       // value
		}
		if(!IS_Tunbox(p2)) {
			Stmt_boxAll(ctx, stmt, 2, DP(stmt)->size, p2);
		}
		return NEWPARAMs_typing(ctx, stmt, reqt, MN_newMAP, 0/*needsTypingPARAMs*/);
	}
	else {
		for(i = 2; i < DP(stmt)->size; i+=2) {
			TYPING_TypedExpr(ctx, stmt, i+1, TYPE_dyn); // value
		}
		Stmt_boxAll(ctx, stmt, 2, DP(stmt)->size, TYPE_dyn);
		return NEWPARAMs_typing(ctx, stmt, TYPE_Map, MN_newMAP, 0/*needsTypingPARAMs*/);
	}
}

static kTerm* NEW_typing(CTX ctx, kStmtExpr *stmt, kclass_t reqt)
{
	kTerm *tkMTD = tkNN(stmt, 0);
	kTerm *tkC = tkNN(stmt, 1);
	kmethodn_t mn = Term_mn(ctx, tkMTD);
	if(reqt == TYPE_var || reqt == TYPE_void) reqt = TYPE_dyn;

	if(mn == MN_newMAP) {  /* {hoge: 1, hogo: 2} */
		return NEWMAP_typing(ctx, stmt, reqt);
	}

	kclass_t new_cid = CLASS_unknown;
	if(TT_(tkC) == TT_ASIS) { /* new () */
		if(reqt == TYPE_dyn) {
			return ERROR_Needs(ctx, "class");
		}
		new_cid = CLASS_t(reqt);
	}
	else {
		new_cid = knh_Term_cid(ctx, tkC, CLASS_unknown);
	}
	if(new_cid == CLASS_unknown) { /* new UnknownClass(...) */
		if(reqt == TYPE_dyn) {
			return ERROR_UndefinedName(ctx, tkC);
		}
		new_cid = CLASS_t(reqt);
	}
	DBG_P("new_cid=%s", CLASS__(new_cid));

	if(mn == MN_newARRAY) {  /* new C [10, 10] */
		size_t i;
		for(i = 2; i < DP(stmt)->size; i++) {
			TYPING_TypedExpr(ctx, stmt, i, TYPE_Int);
		}
		return NEWPARAMs_typing(ctx, stmt, new_cid, mn, 0/*needsTypingPARAMs*/);
	}
	if(mn == MN_newLIST) {  /* [1, 2, .. ] */
		size_t i;
		DBG_ASSERT(IS_NEWLIST(new_cid));
		kclass_t bcid = C_bcid(reqt);
		if(!IS_NEWLIST(bcid) && DP(stmt)->size > 2) {
			kclass_t p1;
			TYPING_UntypedExpr(ctx, stmt, 2);
			p1 = Tn_cid(stmt, 2);
			for(i = 3; i < DP(stmt)->size; i++) {
				TYPING_UntypedExpr(ctx, stmt, i);
				if(p1 != TYPE_dyn && p1 != Tn_cid(stmt, i)) p1 = TYPE_dyn;
			}
			if(p1 != TYPE_dyn) {
				new_cid = knh_class_P1(ctx, new_cid, p1);
			}
			if(!IS_Tunbox(p1)) {
				Stmt_boxAll(ctx, stmt, 2, DP(stmt)->size, p1);
			}
		}
		else {
			kclass_t p1 = C_p1(reqt);
			for(i = 2; i < DP(stmt)->size; i++) {
				TYPING(ctx, stmt, i, p1, _NOVOID|_NOCHECK);
				if(Tn_cid(stmt, i) != p1) {
					reqt = CLASS_Array;
				}
			}
			if(reqt == CLASS_Array) {
				Stmt_boxAll(ctx, stmt, 2, DP(stmt)->size, CLASS_Object);
			}
			new_cid = (reqt != TYPE_dyn) ? reqt : new_cid;
		}
		return NEWPARAMs_typing(ctx, stmt, new_cid, mn, 0/*needsTypingPARAMs*/);
	}

	if(mn == MN_newTUPLE) {  /* (1, 2) */
		BEGIN_LOCAL(ctx, lsfp, 1);
		size_t i;
		LOCAL_NEW(ctx, lsfp, 0, kParam*, pa, new_Param(ctx));
		for(i = 2; i < DP(stmt)->size; i++) {
			TYPING_UntypedExpr(ctx, stmt, i);
			kparam_t p = {Tn_type(stmt, i), FN_NONAME};
			knh_Param_add(ctx, pa, p);
		}
		new_cid = knh_class_Generics(ctx, CLASS_Tuple, pa);
		END_LOCAL(ctx, lsfp);
		return NEWPARAMs_typing(ctx, stmt, new_cid, mn, 0/*needsTypingPARAMs*/);
	}
	if(new_cid == CLASS_Exception) {
		if(!knh_isDefinedEvent(ctx, S_tobytes((tkC)->text))) {
			WARN_Undefined(ctx, "fault", CLASS_Exception, tkC);
		}
		Term_toCONST(ctx, tkC);
		tkC = new_TermTYPED(ctx, TT_CID, CLASS_Class, new_cid);
		Stmt_insert(ctx, stmt, 1, tkC);
		DBG_ASSERT(TT_(tmNN(stmt, 2)) == TT_CONST);
		DBG_ASSERT((tmNN(stmt, 2))->type == CLASS_String);
	}
	return NEWPARAMs_typing(ctx, stmt, new_cid, mn, 1/*needsTypingPARAMs*/);
}



/* ------------------------------------------------------------------------ */
/* [OPR] */

static kTerm *OPR_setMethod(CTX ctx, kStmtExpr *stmt, kclass_t mtd_cid, kmethodn_t mn, kclass_t reqt)
{
	kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, mtd_cid, mn);
	if(mtd == NULL) {
		if(mtd_cid != CLASS_Tdynamic) {
			return ERROR_Unsupported(ctx, "operator", mtd_cid, mn == MN_NONAME ? S_totext(tkNN(stmt, 0)->text) : knh_getopname(mn));
		}
		Stmt_boxAll(ctx, stmt, 2, DP(stmt)->size, TYPE_dyn);
		Term_setMethod(ctx, tkNN(stmt, 0), mn, mtd);
		return Stmt_typed(ctx, stmt, TYPE_dyn);
	}
	if(Method_isRestricted(mtd)) {
		return ERROR_MethodIsNot(ctx, mtd, "allowed");
	}
	Term_setMethod(ctx, tkNN(stmt, 0), mn, mtd);
	TYPING_TypedExpr(ctx, stmt, 1, mtd_cid);
	return CALLPARAMs_typing(ctx, stmt, reqt, mtd_cid, mtd);
}

static kTerm* OPRWITH_typing(CTX ctx, kStmtExpr *stmt, ktype_t reqt)
{
	if(TT_(tkNN(stmt, 1)) == TT_CID) {
		KNH_TODO("new C {}");
	}
	else {
		DBG_P("BEGIN_%d", GammaBuilder_isEnforceConst(ctx->gma));
		TYPING_TypedExpr(ctx, stmt, 1, reqt);
		DBG_P("END_%d", GammaBuilder_isEnforceConst(ctx->gma));
	}
	kStmtExpr *stmtCALL = stmtNN(stmt, 1);
	if(STT_(stmtCALL) == STT_CALL || STT_(stmtCALL) == STT_NEW) {
		size_t i;
		for(i = 2; DP(stmtCALL)->size; i++) { /* f.call() with .. */
			kTerm *tkM = tkNN(stmtCALL, i);
			if(tkM->type == TYPE_Map && TT_(tkM) == TT_NULL && IS_NULL(tkM->data)) {
				GammaBuilder_setEnforceConst(ctx->gma, 1);
				DBG_P("BEGIN_%d", GammaBuilder_isEnforceConst(ctx->gma));
				kTerm *tkRES = Tn_typing(ctx, stmt, 2, TYPE_Map, _NOVOID);
				DBG_P("END_%d", GammaBuilder_isEnforceConst(ctx->gma));
				GammaBuilder_setEnforceConst(ctx->gma, 0);
				if(TT_(tkRES) == TT_ERR) return tkRES;
				KNH_SETv(ctx, stmtNN(stmtCALL, i), stmtNN(stmt, 2));
				return TM(stmtCALL);
			}
		}
	}
	GammaBuilder_setEnforceConst(ctx->gma, 1);
	kTerm *tkRES = Tn_typing(ctx, stmt, 2, Tn_cid(stmt, 1), _NOCHECK);
	GammaBuilder_setEnforceConst(ctx->gma, 0);
	if(TT_(tkRES) == TT_ERR) return tkRES;
	kclass_t dcid = Tn_cid(stmt, 2);
	if(C_bcid(dcid) == CLASS_Map && C_p1(dcid) == CLASS_String) {

	}
	return OPR_setMethod(ctx, stmt, Tn_cid(stmt, 1), MN_opWITH, reqt);
}

static kclass_t OPADD_bcid(CTX ctx, kStmtExpr *stmt)
{
	kclass_t cid1 = Tn_cid(stmt, 1);
	kclass_t cid2 = Tn_cid(stmt, 2);
	kclass_t bcid1 = C_bcid(cid1);
	kclass_t bcid2 = C_bcid(cid2);
	if(cid1 == CLASS_Tdynamic || cid2 == CLASS_Tdynamic) return CLASS_Tdynamic;
	if(cid1 == cid2) return cid1;
	if(bcid1 == bcid2) return bcid1;
	if(bcid1 == CLASS_Float && bcid2 == CLASS_Int) return cid1;
	if(bcid2 == CLASS_Float && bcid1 == CLASS_Int) return cid2;
	if(bcid1 == CLASS_String || bcid2 == CLASS_String) return CLASS_String;
	return cid1;
}

static kclass_t OPEQ_bcid(CTX ctx, kStmtExpr *stmt)
{
	kclass_t cid1 = Tn_cid(stmt, 1);
	kclass_t cid2 = Tn_cid(stmt, 2);
	kclass_t bcid1 = C_bcid(cid1);
	kclass_t bcid2 = C_bcid(cid2);
	if(cid1 == cid2) return cid1;
	if(cid1 == CLASS_Tdynamic || cid2 == CLASS_Tdynamic) return CLASS_Tdynamic;
	if(bcid1 == cid2) return bcid1;
	if(bcid2 == cid1) return bcid2;
	if(bcid1 == CLASS_Float && bcid2 == CLASS_Int) return cid1;
	if(bcid2 == CLASS_Float && bcid1 == CLASS_Int) return cid2;
	return CLASS_unknown;
}

kmethodn_t TT_toMN(kterm_t tt);

static const char* _unbox(kclass_t cid)
{
	if(cid == TYPE_Boolean) return "boolean";
	if(cid == TYPE_Float) return "float";
	return "int";
}

static kTerm *new_TermCID(CTX ctx, kclass_t cid)
{
	kTerm *tk = new_(Term);
	TT_(tk) = TT_CID;
	tk->uline = ctx->gma->uline;
	(tk)->cid = cid;
	return tk;
}

static kTerm* StmtCALL_toIterator(CTX ctx, kStmtExpr *stmt)
{
	kTerm *tkMN = tkNN(stmt, 0);
	kMethod *mtd = tkMN->mtd;
	if(IS_Method(mtd) && Method_isIterative(mtd)) {
		ktype_t rtype = ktype_tocid(ctx, knh_Param_rtype(DP(mtd)->mp), Tn_cid(stmt, 1));
		kclass_t itrcid = knh_class_P1(ctx, CLASS_Iterator, rtype);
		Stmt_insert(ctx, stmt, 1, new_TermCID(ctx, itrcid));
		knh_Stmt_add(ctx, stmt, new_TermCONST(ctx, mtd));
		KNH_SETv(ctx, tkMN->mtd, knh_NameSpace_getMethodNULL(ctx, K_GMANS, CLASS_Iterator, MN_new));
		tkMN->mn = MN_new;
		STT_(stmt) = STT_NEW;
		return NEW_typing(ctx, stmt, itrcid);
	}
	return ERROR_MethodIsNot(ctx, mtd, "@Iterative");
}

static kTerm* OPR_typing(CTX ctx, kStmtExpr *stmt, ktype_t tcid)
{
	size_t i, opsize = DP(stmt)->size - 1;
	kTerm *tkOP = tkNN(stmt, 0);
	kclass_t mtd_cid = CLASS_Tdynamic;
	kmethodn_t mn;
	if(TT_(tkOP) == TT_MN) {
		mn = (tkOP)->mn;
		mtd_cid = Tn_cid(stmt, 1);
	}
	else {
		mn = TT_toMN(TT_(tkOP));
		if(TT_isBINARY(TT_(tkOP)) && opsize != 2) {
			return ERROR_MustBe(ctx, _("binary operator"), knh_getopname(mn));
		}
		if(mn == MN_opWITH) {
			return OPRWITH_typing(ctx, stmt, tcid);
		}
		if(mn != MN_opEXISTS) {
			for(i = 1; i < opsize + 1; i++) {
				TYPING_UntypedExpr(ctx, stmt, i);
			}
		}
	}

	if(mn == MN_opEQ || mn == MN_opNOTEQ) {
		kterm_t tt = TT_TERMs(stmt, 1);
		if(tt == TT_NULL || tt == TT_TRUE || tt == TT_FALSE || tt == TT_CONST) {
			knh_Stmt_swap(ctx, stmt, 1, 2);
		}
		if(Tn_isNULL(stmt, 2)) { /* o == null, o != null */
			kclass_t cid = Tn_cid(stmt, 1);
			if(IS_Tunbox(cid)) {
				return ERROR_UndefinedBehavior(ctx, _unbox(cid));
			}
			mn = (mn == MN_opEQ) ? MN_isNull : MN_isNotNull;
			mtd_cid = CLASS_Object;
			kStmtExprrimToSize(ctx, stmt, 2);
			goto L_LOOKUPMETHOD;
		}
	}

	for(i = 1; i < opsize + 1; i++) {
		if(TT_(tmNN(stmt, i)) == TT_NULL) {
			return ERROR_UndefinedBehavior(ctx, "null");
		}
	}

	switch(mn) {
	case MN_opADD: /* a + b */
	case MN_opSUB: /* a - b */
	case MN_opMUL: /* a * b */
	case MN_opDIV: /* a / b */
	case MN_opMOD: /* a % b */
	{
		mtd_cid = OPADD_bcid(ctx, stmt);
		if(mtd_cid == CLASS_String && mn == MN_opADD && (!Tn_isCONST(stmt, 1) || !Tn_isCONST(stmt, 2))) {
			kTerm *tk = new_(Term);
			TT_(tk) = TT_ASIS;
			Stmt_insert(ctx, stmt, 1, tk);
			STT_(stmt) = STT_SEND;
			return Stmt_typed(ctx, stmt, TYPE_String);
		}
		goto L_LOOKUPMETHOD;
	}
	case MN_opPLUS:
		return tkNN(stmt, 1);

	case MN_opEQ: case MN_opNOTEQ:
	{
		if(Tn_isTRUE(stmt, 1) || Tn_isFALSE(stmt, 1)) {
			knh_Stmt_swap(ctx, stmt, 1, 2);
		}
		if((Tn_isTRUE(stmt, 2) && (mn == MN_opEQ)) /* b == true */
		|| (Tn_isFALSE(stmt, 2) && (mn == MN_opNOTEQ))) {  /* b != false */
			TYPING_TypedExpr(ctx, stmt, 1, TYPE_Boolean);
			return tkNN(stmt, 1);
		}
		if((Tn_isTRUE(stmt, 2) && (mn == MN_opNOTEQ)) /* b != true */
		|| (Tn_isFALSE(stmt, 2) && (mn == MN_opEQ))) {  /* b == false */
			TYPING_TypedExpr(ctx, stmt, 1, TYPE_Boolean);
			mn = MN_opNOT;
			mtd_cid = CLASS_Boolean;
			kStmtExprrimToSize(ctx, stmt, 2);
			goto L_LOOKUPMETHOD;
		}
		mtd_cid = OPEQ_bcid(ctx, stmt);
		if(mtd_cid == CLASS_unknown) {
			return ErrorComparedDiffrentType(ctx, Tn_type(stmt, 1), Tn_type(stmt, 2));
		}
		goto L_LOOKUPMETHOD;
	}
	case MN_opGT: case MN_opGTE: case MN_opLT: case MN_opLTE:
	{
		mtd_cid = OPEQ_bcid(ctx, stmt);
		if(mtd_cid == CLASS_unknown) {
			return ErrorComparedDiffrentType(ctx, Tn_type(stmt, 1), Tn_type(stmt, 2));
		}
		goto L_LOOKUPMETHOD;
	}
	case MN_opHAS:
	{
		knh_Stmt_swap(ctx, stmt, 1, 2);
		mtd_cid = Tn_cid(stmt, 1);
		goto L_LOOKUPMETHOD;
	}

	case MN_opOF:
	{
		kTerm *tkC = tkNN(stmt, 2);
		kclass_t cid = CLASS_t((tkC)->type);
		mtd_cid = Tn_cid(stmt, 1);
		if(TT_(tkC) == TT_CID) {
			if(mtd_cid == CLASS_Exception) {
				mtd_cid = CLASS_Object;
			}
			cid = (tkC)->cid;
		}
		if(mtd_cid == CLASS_Exception){
			goto L_LOOKUPMETHOD;
		}
//		This must be checked later
//		if(mtd_cid == cid || cid == CLASS_Tdynamic) {
//			return Term_setCONST(ctx, tkC, KNH_TRUE);
//		}
//		if(!class_isa(mtd_cid, cid)) {
//			return Term_setCONST(ctx, tkC, KNH_FALSE);
//		}
		goto L_LOOKUPMETHOD;
	}

	case MN_opEXISTS:
	{
		if(TT_(tkNN(stmt,1)) == TT_URN) {
			TT_(tkNN(stmt,1)) = TT_CONST;
			TURN_typing(ctx, tkNN(stmt, 1), TYPE_Boolean);
		}
		else if(STT_(stmtNN(stmt,1)) == STT_TLINK) {
			return TLINK_typing(ctx, stmtNN(stmt, 1), TYPE_Boolean);
		}
		else {
			TYPING_UntypedExpr(ctx, stmt, 1);
		}
		mtd_cid = Tn_cid(stmt, 1);
		if(mtd_cid == CLASS_String) {
			knh_Stmt_add(ctx, stmt, new_TermCONST(ctx, K_GMANS));
		}
		else if(IS_Tunbox(mtd_cid)) {
			return ERROR_UndefinedBehavior(ctx, _unbox(mtd_cid));
		}
		else {
			mtd_cid = CLASS_Object;
			mn = MN_isNotNull;
		}
		goto L_LOOKUPMETHOD;
	}

	case MN_opITR:
	{
		if(STT_(stmtNN(stmt, 1)) == STT_CALL) {
			return StmtCALL_toIterator(ctx, stmtNN(stmt, 1));
		}
	} /* FALLTHROUGH */

	default:
		mtd_cid = Tn_cid(stmt, 1);
		break;
	}

	L_LOOKUPMETHOD:;
	DBG_ASSERT_cid(mtd_cid);
	{
		kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, mtd_cid, mn);
		if(mtd == NULL) {
			if(mtd_cid != CLASS_Tdynamic) {
				return ERROR_Unsupported(ctx, "operator", mtd_cid, mn == MN_NONAME ? S_totext(tkOP->text) : knh_getopname(mn));
			}
			Stmt_boxAll(ctx, stmt, 2, DP(stmt)->size, TYPE_dyn);
			Term_setMethod(ctx, tkOP, mn, mtd);
			return Stmt_typed(ctx, stmt, TYPE_dyn);
		}
		if(Method_isRestricted(mtd)) {
			return ERROR_MethodIsNot(ctx, mtd, "allowed");
		}
		Term_setMethod(ctx, tkOP, mn, mtd);
		TYPING_TypedExpr(ctx, stmt, 1, mtd_cid);
		return CALLPARAMs_typing(ctx, stmt, tcid, mtd_cid, mtd);
	}
}

static kTerm* SEND_typing(CTX ctx, kStmtExpr *stmt, ktype_t reqt)
{
	size_t i;
	for(i = 1; i < DP(stmt)->size; i++) {
		TYPING_UntypedExpr(ctx, stmt, i);
	}
	kclass_t mtd_cid = Tn_cid(stmt, 1);
	if(mtd_cid == CLASS_OutputStream) {
		return Stmt_typed(ctx, stmt, TYPE_void);
	} else {
		kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, mtd_cid, MN_send);
		if(mtd == NULL) {
			return ERROR_Unsupported(ctx, "operator", mtd_cid, "<<<");
		}
		STT_(stmt) = STT_CALL;
		Term_setMethod(ctx, tkNN(stmt, 0), MN_send, mtd);
		return CALLPARAMs_typing(ctx, stmt, reqt, mtd_cid, mtd);
	}
}

static kTerm* ACALL_typing(CTX ctx, kStmtExpr *stmt, ktype_t reqt)
{
	return ERROR_Unsupported(ctx, "actor", CLASS_unknown, NULL);
}

/* ------------------------------------------------------------------------ */
/* [TCAST] */

static void Term_setTypeMap(CTX ctx, kTerm *tk, kclass_t tcid, kTypeMap *tmrNULL)
{
	(tk)->cid = tcid;
	if(tmrNULL != NULL) {
		KNH_SETv(ctx, (tk)->data, tmrNULL);
	}
	else {
		KNH_SETv(ctx, (tk)->data, KNH_NULL);
	}
}

static kTerm *new_TermDYNCAST(CTX ctx, kclass_t tcid, kmethodn_t mn, kTerm *tkO)
{
	kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, CLASS_Object, mn);
	if(Method_isRestricted(mtd)) {
		return ERROR_MethodIsNot(ctx, mtd, "allowed");
	}
	DBG_ASSERT(mtd != NULL);
	kTerm *tkMN = new_TermTYPED(ctx, TT_MN,  TYPE_var, mn);
	kTerm *tkC = new_TermTYPED(ctx, TT_CID, TYPE_Class, CLASS_t(tcid));
	kStmtExpr *stmt = new_Stmt2(ctx, STT_CALL, tkMN, tkO, tkC, NULL);
	Term_setMethod(ctx, tkMN, mn, mtd);
	return Stmt_typed(ctx, stmt, tcid);
}

static kTerm *new_TermTCAST(CTX ctx, kclass_t tcid, kTypeMap *tmr, kTerm *tkO)
{
	DBG_ASSERT(tmr != NULL);
	if(TT_(tkO) == TT_CONST && TypeMap_isConst(tmr)) {
		BEGIN_LOCAL(ctx, lsfp, 1);
		KNH_SETv(ctx, lsfp[0].o, (tkO)->data);
		lsfp[0].ndata = O_ndata((tkO)->data);
		klr_setesp(ctx, lsfp+1);
		knh_TypeMap_exec(ctx, tmr, lsfp, 0);
		knh_boxing(ctx, lsfp, SP(tmr)->tcid);
		Term_setCONST(ctx, tkO, lsfp[0].o);
		END_LOCAL(ctx, lsfp);
		return tkO;
	}
	else {
		kTerm *tkC = new_TermTYPED(ctx, TT_CID, TYPE_Class, tcid);
		kStmtExpr *stmt = new_Stmt2(ctx, STT_TCAST, tkC, tkO, NULL);
		Term_setTypeMap(ctx, tkC, tcid, tmr);
		return Stmt_typed(ctx, stmt, tcid);
	}
}

static kTerm* TCAST_typing(CTX ctx, kStmtExpr *stmt, ktype_t reqt)
{
	kclass_t scid, tcid;
	kTerm *tkC = TTYPE_typing(ctx, tkNN(stmt, 0), CLASS_unknown);
	kTypeMap *tmr = NULL;
	if(TT_(tkC) == TT_ERR) return tkC;
	tcid = (tkC)->cid;
	if(tcid == CLASS_Tdynamic) {   /* (dyn)expr */
		tcid = CLASS_t(reqt);
		if(tcid == CLASS_Tdynamic || tcid == CLASS_Tvar || tcid == CLASS_Tvoid) {
			TYPING_UntypedObject(ctx, stmt, 1);
			return tkNN(stmt, 1);
		}
	}
	TYPING(ctx, stmt, 1, tcid, _NOCHECK|_NOVOID|_NOCAST);
	scid = Tn_cid(stmt, 1);
	if(Term_isDiamond(tkC) && C_isGenerics(tcid)) {
		if(C_p1(scid) != CLASS_Tvoid) {
			tcid = knh_class_P1(ctx, tcid, C_p1(scid)); /* (A<>)I<T> => (A<T>)I<T>) */
		}
		else {
			tcid = knh_class_P1(ctx, tcid, scid); /* (Im<>)T => (Im<T>)T */
		}
	}
	if(scid == CLASS_Tdynamic) {
		kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, CLASS_Object, MN_typeCheck);
		Term_setMethod(ctx, tkC, MN_typeCheck, mtd);
		knh_Stmt_add(ctx, stmt, new_TermTYPED(ctx, TT_CID, TYPE_Class, CLASS_t(tcid)));
		Stmt_toSTT(stmt, STT_CALL);
		return Stmt_typed(ctx, stmt, tcid);
	}
	DBG_P("TRANS=%d", Stmt_isTRANS(stmt));
	if(scid == tcid || (class_isa(scid, tcid) && !(Stmt_isTRANS(stmt)))) {
		return tkNN(stmt, 1);
	}
	if(class_isa(tcid, scid) && !(Stmt_isTRANS(stmt))) {  /* downcast */
		Term_setTypeMap(ctx, tkC, tcid, NULL);
		WARN_Cast(ctx, "downcast", tcid, scid);
		return Stmt_typed(ctx, stmt, tcid);
	}

	tmr = knh_findTypeMapNULL(ctx, scid, tcid/*, Stmt_isTRANS(stmt)*/);
	if(tmr == NULL) {
		WARN_Cast(ctx, "undefined cast", tcid, scid);
		kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, CLASS_Object, MN_to);
		Term_setMethod(ctx, tkC, MN_to, mtd);
		knh_Stmt_add(ctx, stmt, new_TermTYPED(ctx, TT_CID, TYPE_Class, CLASS_t(tcid)));
		Stmt_toSTT(stmt, STT_CALL);
		if(IS_Tunbox(scid)) {
			Stmt_boxAll(ctx, stmt, 1, 2, CLASS_Object);
		}
		return Stmt_typed(ctx, stmt, tcid);
	}
	if(TypeMap_isConst(tmr) && Tn_isCONST(stmt, 1)) {
		BEGIN_LOCAL(ctx, lsfp, 1);
		kTerm *tk1 = tkNN(stmt, 1);
		KNH_SETv(ctx, lsfp[0].o, (tk1)->data);
		lsfp[0].ndata = (lsfp[0].i)->n.data;
		klr_setesp(ctx, lsfp+1);
		knh_TypeMap_exec(ctx, tmr, lsfp, 0);
		knh_boxing(ctx, &lsfp[0], SP(tmr)->tcid);
		Term_setCONST(ctx, tk1, lsfp[0].o);
		DBG_P("const TCAST %s ==> %s, %s", CLASS__(SP(tmr)->scid), CLASS__(SP(tmr)->tcid), O__(lsfp[0].o));
		END_LOCAL(ctx, lsfp);  // NEED TO CHECK
		return TM(tk1);
	}
	else {
		DBG_P("tmr=%p, scid=%s, tcid=%s", tmr, TYPE__(tmr->scid), TYPE__(tcid));
		Term_setTypeMap(ctx, tkC, tcid, tmr);
		return Stmt_typed(ctx, stmt, tcid);
	}
}

/* [MT,AND,OR,] */
static kTerm* AND_typing(CTX ctx, kStmtExpr *stmt, ktype_t reqt)
{
	size_t i;
	for(i = 0; i < DP(stmt)->size; i++) {
		TYPING_Condition(ctx, stmt, i);
		if(Tn_isFALSE(stmt, i)) {
			return new_TermCONST(ctx, KNH_FALSE);
		}
	}
	return Stmt_typed(ctx, stmt, TYPE_Boolean);
}

static kTerm* OR_typing(CTX ctx, kStmtExpr *stmt, ktype_t reqt)
{
	size_t i;
	for(i = 0; i < DP(stmt)->size; i++) {
		TYPING_Condition(ctx, stmt, i);
		if(Tn_isTRUE(stmt, i)) {
			return new_TermCONST(ctx, KNH_TRUE);
		}
	}
	return Stmt_typed(ctx, stmt, TYPE_Boolean);
}

static kTerm* ALT_typing(CTX ctx, kStmtExpr *stmt, ktype_t reqt)
{
	size_t i;
	DBG_ASSERT(DP(stmt)->size > 1);
	for(i = 0; i < DP(stmt)->size; i++) {
		TYPING_TypedExpr(ctx, stmt, i, reqt);
	}
	return Stmt_typed(ctx, stmt, reqt);
}

static kTerm* TRI_typing(CTX ctx, kStmtExpr *stmt, ktype_t reqt)
{
	TYPING_Condition(ctx, stmt, 0);
	TYPING_TypedExpr(ctx, stmt, 1, reqt);
	if(reqt == TYPE_var || reqt == TYPE_void) {
		reqt = Tn_type(stmt, 1);
	}
	TYPING_TypedExpr(ctx, stmt, 2, reqt);
	if(Tn_isTRUE(stmt, 0)) return tkNN(stmt, 1);
	if(Tn_isFALSE(stmt, 0)) return tkNN(stmt, 2);
	return Stmt_typed(ctx, stmt, reqt);
}

static ktype_t GammaBuilder_getReturnType(CTX ctx)
{
	kMethod *mtd = DP(ctx->gma)->mtd;
	return GammaBuilder_type(ctx, knh_Param_rtype(DP(mtd)->mp));
}

static void GammaBuilder_inferReturnType(CTX ctx, ktype_t rtype)
{
	kMethod *mtd = DP(ctx->gma)->mtd;
	kParam *pa = DP(mtd)->mp;
	if(Param_isRVAR(pa)) {
		DBG_ASSERT(pa->rsize == 0);
		knh_Param_addReturnType(ctx, pa, rtype);
		INFO_Typing(ctx, "return value", STEXT(""), rtype);
		Param_setRVAR(pa, 0);
	}
}

static kTerm* RETURN_typing(CTX ctx, kStmtExpr *stmt)
{
	size_t size = DP(stmt)->size;
	kMethod *mtd = DP(ctx->gma)->mtd;
	kParam *pa = DP(mtd)->mp;
	kclass_t this_cid = DP(ctx->gma)->this_cid;
	ktype_t rtype = GammaBuilder_type(ctx, knh_Param_rtype(pa));
	Stmt_setSTOPITR(stmt, 1);
	if(size > 1) {
		WARN_Unsupported(ctx, "returning multiple values");
		size = (rtype == TYPE_void) ? 0: 1;
		kStmtExprrimToSize(ctx, stmt, size);
	}
	if(size == 0 && MN_isNEW((mtd)->mn)) {
		kTerm *tk = new_TermTYPED(ctx, TT_FVAR, this_cid, 0);
		knh_Stmt_add(ctx, stmt, tk);
		return Stmt_typed(ctx, stmt, rtype);
	}
	if(Param_isRVAR(pa)) {
		DBG_ASSERT(pa->rsize == 0);
		rtype = TYPE_void;
		if(size > 0) {
			TYPING_UntypedExpr(ctx, stmt, 0);
			rtype = Tn_type(stmt, 0);
		}
		GammaBuilder_inferReturnType(ctx, rtype);
		return Stmt_typed(ctx, stmt, rtype);
	}
	if(Stmt_isImplicit(stmt)) { /*size > 0 */
		TYPING_UntypedObject(ctx, stmt, 0);
		if(Tn_type(stmt, 0) != TYPE_void) {
			Stmt_setImplicit(stmt, 0);
		}
		return Stmt_typed(ctx, stmt, Tn_type(stmt, 0));
	}
	if(size == 0) {
		if(rtype != TYPE_void) {
			kTerm *tk = new_TermTYPED(ctx, TT_NULL/*DEFVAL*/, rtype, CLASS_t(rtype));
			knh_Stmt_add(ctx, stmt, tk);
			WARN_UseDefaultValue(ctx, "return", rtype);
		}
	}
	else { /* size > 0 */
		TYPING_TypedExpr(ctx, stmt, 0, rtype);
		if(rtype == TYPE_void) {
			WARN_Ignored(ctx, "return value", CLASS_unknown, NULL);
			kStmtExprrimToSize(ctx, stmt, 0);
		}
//		else {
//			if(STT_(stmtNN(stmt, 0)) == STT_CALL) {
//				kTerm *tkF = tkNN(stmtNN(stmt, 0), 0);
//				if(DP(ctx->gma)->mtd == (tkF)->mtd) {
//					Stmt_setTAILRECURSION(stmtNN(stmt, 0), 1);
//				}
//			}
//		}
	}
	return Stmt_typed(ctx, stmt, rtype);
}

#define TYPING_Block(ctx, stmt, n) StmtITR_typing(ctx, stmtNN(stmt, n), 0)

static int/*hasRETURN*/ StmtITR_typing(CTX ctx, kStmtExpr *stmt, int needsRETURN)
{
	kStmtExpr *stmtITR = stmt;
	int needs = (DP(stmtITR)->nextNULL != NULL) ? 0 : needsRETURN;
	int hasRETURN = 0;
	BEGIN_BLOCK(stmt, espidx);
	DBG_ASSERT(IS_StmtExpr(stmtITR));
	while(stmtITR != NULL) {
		kTerm *tkRES;
		ctx->gma->uline = stmtITR->uline;
		Stmt_setESPIDX(ctx, stmtITR);
		tkRES = Stmt_typing(ctx, stmtITR, needs);
		if(TT_(tkRES) == TT_ERR) {
			stmt->uline = stmtITR->uline;
			kStmtExproERR(ctx, stmt, tkRES);
			if(DP(stmt)->nextNULL != NULL) {
				KNH_FINALv(ctx, DP(stmt)->nextNULL);
			}
			hasRETURN = 1;
			break; // return
		}
		if(IS_Term(tkRES)) {
			WarningNoEffect(ctx);
			knh_Stmt_done(ctx, stmtITR);
		}
		if(Stmt_isSTOPITR(stmtITR)) {
			if(DP(stmtITR)->nextNULL != NULL) {
				KNH_FINALv(ctx, DP(stmtITR)->nextNULL);
			}
			hasRETURN = 1;
			break;
		}
		needs = (DP(stmtITR)->nextNULL != NULL) ? 0 : needsRETURN;
		stmtITR = DP(stmtITR)->nextNULL;
	}
	END_BLOCK(stmt, espidx);
	return hasRETURN;
}

kbool_t typingFunction(CTX ctx, kMethod *mtd, kStmtExpr *stmtB)
{
	kParam *mp = DP(mtd)->mp;
	size_t i, psize = mp->psize;
	GammaBuilder_addFVAR(ctx, 0/*_FREADONLY*/, TYPE_Object, FN_, 0);
	for(i = 0; i < psize; i++) {
		kparam_t *p = knh_Param_get(mp, i);
		GammaBuilder_addFVAR(ctx, 0/*_FREADONLY*/, p->type, p->fn, 0);
	}
	DP(ctx->gma)->psize = DP(ctx->gma)->funcbase0 + psize;
	DBG_ASSERT(DP(ctx->gma)->psize + 1 == DP(ctx->gma)->fvarsize);
	DP(ctx->gma)->tkFuncThisNC = GammaBuilder_addFVAR(ctx, 0/*_FREADONLY*/, DP(ctx->gma)->this_cid, FN_this, 0);

	int needsReturn = (GammaBuilder_getReturnType(ctx) != TYPE_void) && (GammaBuilder_getReturnType(ctx) != TYPE_var);
	int hasReturn = StmtITR_typing(ctx, stmtB, needsReturn);
	if(GammaBuilder_getReturnType(ctx) == TYPE_var) {
		GammaBuilder_inferReturnType(ctx, TYPE_void);
		needsReturn = 0;
	}
	if(!hasReturn && needsReturn) {
		kStmtExpr *stmtRETURN = new_Stmt2(ctx, STT_RETURN, NULL);
		kStmtExpr *stmtLAST = stmtB;
		while(DP(stmtLAST)->nextNULL != NULL) stmtLAST = DP(stmtLAST)->nextNULL;
		KNH_INITv(DP(stmtLAST)->nextNULL, stmtRETURN);
		RETURN_typing(ctx, stmtRETURN);
	}
	return (STT_(stmtB) != STT_ERR);
}

static kTerm* FUNCTION_typing(CTX ctx, kStmtExpr *stmt, ktype_t reqt)
{
	kStmtExpr *stmtP = stmtNN(stmt, 1);
	kStmtExpr *stmtB = stmtNN(stmt, 3);
	if(DP(ctx->gma)->funcbase0 > 0) {
		return ERROR_Unsupported(ctx, "nested function", CLASS_unknown, NULL);
	}
	kMethod *mtd = new_Method(ctx, 0, DP(ctx->gma)->this_cid, MN_, NULL);
	kParam *mp = new_Param(ctx);
	KNH_SETv(ctx, DP(mtd)->mp, mp);
	DBG_ASSERT(TT_(tkNN(stmt, 2)) == TT_DOC);
	KNH_SETv(ctx, DP(mtd)->tsource, stmtNN(stmt, 2));
	DBG_ASSERT(TT_(tkNN(stmt, 0)) == TT_ASIS);
	Term_setCONST(ctx, tkNN(stmt, 0), mtd);
	DBG_ASSERT(STT_(stmtP) == STT_DECL);
	if(IS_Tfunc(reqt)) {
		kParam *cpm = ClassTBL(reqt)->cparam;
		if(DP(stmtP)->size / 3 != cpm->psize) {
			return ErrorDifferentlyDefinedMethod(ctx, (mtd)->cid, (mtd)->mn);
		}
		size_t i;
		for(i = 0; i < DP(stmtP)->size; i += 3) {
			size_t n = i / 3;
			kparam_t *p = knh_Param_get(cpm, n);
			kTerm *tkT = DECL3_typing(ctx, stmtP, i+0, p->type, _VFINDTHIS | _VFINDSCRIPT, 0);
			if(TT_(tkT) == TT_ERR) {
				kStmtExproERR(ctx, stmt, tkT);
				return tkT;
			}
			if(tkT->cid != p->type) {
				return ErrorDifferentlyDefinedMethod(ctx, (mtd)->cid, (mtd)->mn);
			}
			else {
				knh_Param_addParam(ctx, mp, tkT->cid, Term_fn(ctx, tkNN(stmtP, i+1)));
			}
		}
		if(cpm->rsize > 0) {
			kparam_t *p = knh_Param_rget(cpm, 0);
			knh_Param_addReturnType(ctx, mp, p->type);
		}
	}
	else {
		size_t i;
		for(i = 0; i < DP(stmtP)->size; i += 3) {
			kTerm *tkT = DECL3_typing(ctx, stmtP, i+0, TYPE_var, _VFINDTHIS | _VFINDSCRIPT, 0);
			if(TT_(tkT) != TT_ERR) {
				kparam_t p = {tkT->cid, Term_fn(ctx, tkNN(stmtP, i+1))};
				knh_Param_add(ctx, mp, p);
			}
			else {
				kStmtExproERR(ctx, stmt, tkT);
				return tkT;
			}
		}
		Param_setRVAR(mp, 1);
	}
	kTerm *tkRES = TM(stmt);
	{
		kflag_t gma_flag = DP(ctx->gma)->flag;
		int gma_funcbase0 = DP(ctx->gma)->funcbase0;
		int gma_psize = DP(ctx->gma)->psize;
		int gma_fvarsize = DP(ctx->gma)->fvarsize;
		DP(ctx->gma)->funcbase0 = DP(ctx->gma)->gsize;
		kMethod* gma_mtd = DP(ctx->gma)->mtd;
		KNH_SETv(ctx, DP(ctx->gma)->mtd, mtd);
		if(typingFunction(ctx, mtd, stmtB)) {
			reqt = knh_class_Generics(ctx, CLASS_Func, DP(mtd)->mp);
			KNH_SETv(ctx, DP(mtd)->stmtB, stmtB);
			DP(mtd)->delta = DP(ctx->gma)->fvarsize - DP(ctx->gma)->funcbase0;
			mtd->fcall_1 = knh_Fmethod_asm;
			if(GammaBuilder_hasLexicalScope(ctx->gma)) {
				kTerm *tkIDX = GammaBuilder_addFVAR(ctx, _FCHKOUT, reqt, FN_, 1);
				KNH_SETv(ctx, stmtNN(stmt, 1), tkIDX);
				DBG_P("lexical scope: idx=%d", tkIDX->index);
				if(DP(stmt)->espidx == 0) {
					Stmt_setESPIDX(ctx, stmt);
				}
				tkRES = Stmt_typed(ctx, stmt, reqt);
			}
			else {
				tkRES = new_TermCONST(ctx, new_StaticFunc(ctx, reqt, mtd));
			}
		}
		else {
			reqt = knh_class_Generics(ctx, CLASS_Func, DP(mtd)->mp);
			kMethodoAbstract(ctx, mtd);
			tkRES = Stmt_typed(ctx, stmt, reqt);
		}
		GammaBuilder_clear(ctx, DP(ctx->gma)->funcbase0, 0);
		DP(ctx->gma)->flag = gma_flag;
		DP(ctx->gma)->gsize = DP(ctx->gma)->funcbase0;
		DP(ctx->gma)->funcbase0 = gma_funcbase0;
		DP(ctx->gma)->psize = gma_psize;
		DP(ctx->gma)->fvarsize = gma_fvarsize;
		KNH_SETv(ctx, DP(ctx->gma)->mtd, gma_mtd);
	}
	return tkRES;
}

#define CASE_EXPR(XX, ...) case STT_##XX : { \
		return XX##_typing(ctx, ## __VA_ARGS__); \
	}\


static kTerm* EXPR_typing(CTX ctx, kStmtExpr *stmt, kclass_t tcid)
{
	if(stmt->type != TYPE_var) return TM(stmt);
	switch(STT_(stmt)) {
		CASE_EXPR(CALL1, stmt, tcid);
		CASE_EXPR(LET, stmt, tcid);
		CASE_EXPR(FUNCCALL, stmt, tcid);
		CASE_EXPR(CALL, stmt, tcid);
		CASE_EXPR(NEW, stmt, tcid);
		CASE_EXPR(OPR, stmt, tcid);
		CASE_EXPR(ACALL, stmt, tcid);
		CASE_EXPR(SEND, stmt, tcid);
		CASE_EXPR(TCAST, stmt, tcid);
		CASE_EXPR(TLINK, stmt, tcid);
		CASE_EXPR(AND, stmt, tcid);
		CASE_EXPR(OR, stmt, tcid);
		CASE_EXPR(ALT, stmt, tcid);
		CASE_EXPR(TRI, stmt, tcid);
		CASE_EXPR(FUNCTION, stmt, tcid);
	default:
		return ERROR_Unsupported(ctx, "expression", CLASS_unknown, Stmt__((stmt)));
	}
}

/* ------------------------------------------------------------------------ */


static kTerm* YIELD_typing(CTX ctx, kStmtExpr *stmt)
{
	return ERROR_Unsupported(ctx, "statement", CLASS_unknown, "yield");
}

static kTerm* Stmt_toBLOCK(CTX ctx, kStmtExpr *stmt, size_t n)
{
	DBG_ASSERT(DP(stmt)->size > 0);
	STT_(stmt) = STT_BLOCK;
	KNH_SETv(ctx, tmNN(stmt, 0), tmNN(stmt, n));
	kStmtExprrimToSize(ctx, stmt, 1);
	return Stmt_typed(ctx, stmt, TYPE_void);
}

static kTerm* IF_typing(CTX ctx, kStmtExpr *stmt, int needsRETURN)
{
	TYPING_Condition(ctx, stmt, 0);
	if(Tn_isTRUE(stmt, 0)) {
		int hasReturnT = StmtITR_typing(ctx, stmtNN(stmt, 1), needsRETURN);
		Stmt_setSTOPITR(stmt, hasReturnT);
		knh_Stmt_done(ctx, stmtNN(stmt, 2));
		return Stmt_toBLOCK(ctx, stmt, 1);
	}
	else if(Tn_isFALSE(stmt, 0)) {
		int hasReturnF = StmtITR_typing(ctx, stmtNN(stmt, 2), needsRETURN);
		Stmt_setSTOPITR(stmt, hasReturnF);
		knh_Stmt_done(ctx, stmtNN(stmt, 1));
		return Stmt_toBLOCK(ctx, stmt, 2);
	}
	else {
		int hasReturnT = StmtITR_typing(ctx, stmtNN(stmt, 1), needsRETURN);
		int hasReturnF = StmtITR_typing(ctx, stmtNN(stmt, 2), needsRETURN);
		Stmt_setSTOPITR(stmt, (hasReturnT && hasReturnF));
	}
	return Stmt_typed(ctx, stmt, TYPE_void);
}

static kTerm *Tn_it(CTX ctx, kStmtExpr *stmt, size_t n, ktype_t type)
{
	kTerm *tkIT = tkNN(stmt, n);
	if(TT_(tkIT) != TT_LVAR) {
		tkIT = GammaBuilder_addLVAR(ctx, 0, type, FN_, 1/*ucnt*/);
		KNH_SETv(ctx, tkNN(stmt, n), tkIT);
	}
	return tkIT;
}

static kStmtExpr* new_StmtCASE(CTX ctx, kTerm *tkIT, kTerm *tkC)
{
	ktype_t switch_type = (tkIT)->type;
	ktype_t case_type = (tkC)->type;
	kmethodn_t mn = MN_opEQ;
	DBG_P("switch_type=%s, case_type=%s", TYPE__(switch_type), TYPE__(case_type));
	if(case_type == CLASS_Class) {  // case Object:
		mn = MN_opOF;
	}
	if(switch_type == CLASS_String && case_type == CLASS_Regex) {  // case /s/:
		mn = MN_opHAS;
	}
	return new_Stmt2(ctx, STT_OPR, new_TermMN(ctx, mn), tkIT, tkC, NULL);
}

static kTerm* SWITCH_typing(CTX ctx, kStmtExpr *stmt, int needsRETURN)
{
	int hasReturn = 1, hasReturnCASE = 0;
	TYPING_UntypedExpr(ctx, stmt, 0);
	if(TT_(tkNN(stmt, 0)) == TT_LVAR) {
		KNH_SETv(ctx, tkNN(stmt, 2), tkNN(stmt, 0));
	}
	{
		BEGIN_BLOCK(stmt, esp);
		ktype_t type = Tn_type(stmt, 0);
		kTerm *tkIT = Tn_it(ctx, stmt, 2/*IT*/, type);
		int c = 0;
		kStmtExpr *stmtCASE, *stmtDEFAULT = NULL;
		stmtCASE = stmtNN(stmt, 1);
		while(stmtCASE != NULL) {
			if(STT_(stmtCASE) == STT_CASE) {
				Stmt_setESPIDX(ctx, stmtCASE);
				if(Tn_isASIS(stmtCASE, 0)) {
					if(stmtDEFAULT != NULL) {
						WarningDuplicatedDefault(ctx);
						knh_Stmt_done(ctx, stmtCASE);
						goto L_NEXT;
					}
					stmtDEFAULT = stmtCASE;
					goto L_STMT;
				}
				else if(!Tn_typing(ctx, stmtCASE, 0, type, _NOCHECK)) {
					knh_Stmt_done(ctx, stmtCASE);
					goto L_NEXT;
				}
				if(Tn_isCONST(stmtCASE, 0)) {
					kStmtExpr *stmtOP = new_StmtCASE(ctx, tkIT, tkNN(stmtCASE, 0));
					KNH_SETv(ctx, tmNN(stmtCASE, 0), stmtOP);
					if(!Tn_typing(ctx, stmtCASE, 0, TYPE_Boolean, _NOCAST)) {
						knh_Stmt_done(ctx, stmtCASE);
						goto L_NEXT;
					}
				}
				else {
					WarningNotConstant(ctx);
					knh_Stmt_done(ctx, stmtCASE);
					goto L_NEXT;
				}
//				if(Tn_isCONST(stmtCASE, 0)){
//				}
				L_STMT:;
				hasReturnCASE = StmtITR_typing(ctx, stmtNN(stmtCASE, 1), needsRETURN);
				hasReturn = (hasReturn && hasReturnCASE);
				c++;
			}
			L_NEXT:;
			stmtCASE = DP(stmtCASE)->nextNULL;
		}
		if(c == 0) {
			return knh_Stmt_done(ctx, stmt);
		}
		Stmt_setSTOPITR(stmt, hasReturn);
		END_BLOCK(stmt, esp);
	}
	return TM(stmt);
}

static kTerm* WHILE_typing(CTX ctx, kStmtExpr *stmt)
{
	TYPING_Condition(ctx, stmt, 0);
	if(Tn_isFALSE(stmt, 0)) {
		return knh_Stmt_done(ctx, stmt);
	}
	else {
		TYPING_Block(ctx, stmt, 1);
	}
	return Stmt_typed(ctx, stmt, TYPE_void);
}

static kTerm* DO_typing(CTX ctx, kStmtExpr *stmt)
{
	TYPING_Block(ctx, stmt, 0);
	TYPING_Condition(ctx, stmt, 1);
	return Stmt_typed(ctx, stmt, TYPE_void);
}

static kTerm* FOR_typing(CTX ctx, kStmtExpr *stmt)
{
	BEGIN_BLOCK(stmt, esp);
	kTerm *tkRES = Stmt_typing(ctx, stmtNN(stmt, 0), TYPE_void);
	Stmt_setESPIDX(ctx, stmtNN(stmt, 0));
	if(tkRES != NULL) {
		TYPING_Condition(ctx, stmt, 1);
		if(Tn_isFALSE(stmt, 1)) {
			return tkNN(stmt, 0);
		}
		else {
			TYPING_Block(ctx, stmt, 2);
			TYPING_Block(ctx, stmt, 3);
		}
		tkRES = Stmt_typed(ctx, stmt, TYPE_void);
	}
	END_BLOCK(stmt, esp);
	return tkRES;
}

static kTerm* FOREACH1_toIterator(CTX ctx, kStmtExpr *stmt, size_t n)
{
	kclass_t cid = Tn_cid(stmt, n);
	kclass_t bcid = C_bcid(cid), p1 = C_p1(cid);
	DBG_P("bcid=%s, p1=%s", TYPE__(bcid), TYPE__(p1));
	if(bcid == CLASS_Iterator) {
		return tkNN(stmt, n); // OK
	}
	if(p1 != TYPE_void) {
		kclass_t tcid = knh_class_P1(ctx, CLASS_Iterator, p1);
		kTypeMap *tmr = knh_findTypeMapNULL(ctx, cid, tcid);
		if(tmr != NULL) {
			KNH_SETv(ctx, stmtNN(stmt, n), new_TermTCAST(ctx, tcid, tmr, tkNN(stmt, n)));
			return tkNN(stmt, n);
		}
	}
	if(bcid == CLASS_Tuple) {
		KNH_TODO("tuple iterator");
	}
	{
		kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, cid, MN_opITR);
		if(mtd != NULL) {
			kStmtExpr *stmtC = new_Stmt2(ctx, STT_CALL, new_TermMN(ctx, MN_opITR), tmNN(stmt, n), NULL);
			KNH_SETv(ctx, tmNN(stmt, n), CALL_typing(ctx, stmtC, TYPE_var));
			cid = knh_Method_rtype(ctx, mtd, cid);
			return tkNN(stmt, n);
		}
	}
	return ERROR_ForeachNotIterative(ctx, TYPE_var, cid);
}

static kTerm* FOREACH1_typing(CTX ctx, kStmtExpr *stmt)
{
	kStmtExpr *stmtDECL = stmtNN(stmt, 0);
//	if(IS_StmtExpr(stmtDECL)) {
	BEGIN_BLOCK(stmt, esp);
	kclass_t itrcid = CLASS_unknown;
	kTerm *tkT = TTYPE_typing(ctx, tkNN(stmtDECL, 0), TYPE_var);
	kTerm *tkN = tkNN(stmtDECL, 1);
	ksymbol_t fn = Term_fn(ctx, tkN);
	kclass_t p1 = tkT->cid;
	if(p1 == TYPE_var) {  // foreach(s from in..) ;
		kTerm *tkN2 = TNAME_typing(ctx, tkN, TYPE_dyn, _FINDLOCAL | _FINDFIELD | _FINDSCRIPT | _USEDCOUNT);
		if(tkN2 == NULL) {
			TYPING(ctx, stmt, 1, TYPE_dyn, _NOCHECK);
			tkT = FOREACH1_toIterator(ctx, stmt, 1);
			if(TT_(tkT) == TT_ERR) return tkT;
			itrcid = Tn_cid(stmt, 1);
			p1 = C_p1(itrcid);
			KNH_SETv(ctx, tkNN(stmt, 0), GammaBuilder_addLVAR(ctx, 0, p1, fn, 1/*ucnt*/));
			INFO_Typing(ctx, "", TK_tobytes(tkN), p1);
			Tn_it(ctx, stmt, 2, itrcid);
			goto L_BLOCK;
		}
		p1 = tkN2->type;
		if(TT_(tkN2) != TT_LVAR || TT_(tkN2) != TT_FVAR) {
			KNH_SETv(ctx, tkNN(stmt, 0), GammaBuilder_addLVAR(ctx, 0, p1, fn, 1/*ucnt*/));
		}
		else {
			KNH_SETv(ctx, tkNN(stmt, 0), tkN);
		}
	}
	else {
		KNH_SETv(ctx, tkNN(stmt, 0), GammaBuilder_addLVAR(ctx, 0, p1, fn, 1/*ucnt*/));
	}
	itrcid = knh_class_P1(ctx, CLASS_Iterator, p1);
	TYPING(ctx, stmt, 1, itrcid, _COERCION);
	Tn_it(ctx, stmt, 2, itrcid);

	L_BLOCK:;
	TYPING_Block(ctx, stmt, 3);
	END_BLOCK(stmt, esp);
	return Stmt_typed(ctx, stmt, TYPE_void);
}

static kTerm* FOREACH_typing(CTX ctx, kStmtExpr *stmt)
{
	if(isSINGLEFOREACH(stmtNN(stmt, 0))) {
		return FOREACH1_typing(ctx, stmt);
	}
	else {
		return ERROR_Unsupported(ctx, "multi variable iteration", CLASS_unknown, NULL);
	}
}

static kTerm* TRY_typing(CTX ctx, kStmtExpr *stmt, int needsReturn)
{
	int hasReturn = 0, hasReturnEach = 0;
	BEGIN_BLOCK(stmt, esp);
	kStmtExpr *stmtCATCH = stmtNN(stmt, 1);
	Tn_it(ctx, stmt, 3/*HDR*/, TYPE_ExceptionHandler);
	hasReturn = StmtITR_typing(ctx, stmtNN(stmt, 0), needsReturn);
	while(stmtCATCH != NULL) {
		DBG_ASSERT(IS_StmtExpr(stmtCATCH));
		if(STT_(stmtCATCH) == STT_CATCH) {
			BEGIN_BLOCK(stmt, esp2);
			ksymbol_t fn = Term_fn(ctx, tkNN(stmtCATCH, 1));
			kTerm *tkIDX = GammaBuilder_addLVAR(ctx, 0, TYPE_Exception, fn, 1/*ucnt*/);
			KNH_SETv(ctx, tkNN(stmtCATCH, 1), tkIDX);
			Stmt_setESPIDX(ctx, stmtCATCH);
			hasReturnEach = StmtITR_typing(ctx, stmtNN(stmtCATCH, 2), needsReturn);
			hasReturn = hasReturn && hasReturnEach;
			END_BLOCK(stmt, esp2);
		}
		stmtCATCH = DP(stmtCATCH)->nextNULL;
	}
	hasReturnEach = StmtITR_typing(ctx, stmtNN(stmt, 2), 0);
	Stmt_setSTOPITR(stmt, hasReturn || hasReturnEach);
	END_BLOCK(stmt, esp);
	return TM(stmt);
}

static kTerm* THROW_typing(CTX ctx, kStmtExpr *stmt)
{
	TYPING_TypedExpr(ctx, stmt, 0, TYPE_Exception);
	Stmt_setSTOPITR(stmt, 1);
	return TM(stmt);
}

static kTerm* PRINT_typing(CTX ctx, kStmtExpr *stmt)
{
	size_t i;
	for(i = 0; i < DP(stmt)->size; i++) {
		TYPING_UntypedExpr(ctx, stmt, i);
	}
	return Stmt_typed(ctx, stmt, TYPE_void);
}

static kTerm *ASSURE_typing(CTX ctx, kStmtExpr *stmt)
{
	BEGIN_BLOCK(stmt, esp);
	TYPING_TypedExpr(ctx, stmt, 0, TYPE_String);
	{
		kTerm *tkC = new_TermTYPED(ctx, TT_CID, CLASS_Class, CLASS_Assurance);
		kTerm *tkCALL = new_(Term);
		kMethod* mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, CLASS_Assurance, MN_new);
		Term_setMethod(ctx, tkCALL, MN_new, mtd);
		kStmtExpr *stmtCALL = new_Stmt2(ctx, STT_NEW, tkCALL, tkC, tmNN(stmt, 0), NULL);
		KNH_SETv(ctx, tmNN(stmt, 0), stmtCALL);
		TYPING_TypedExpr(ctx, stmt, 0, CLASS_Assurance); // To make constant
	}
	Tn_it(ctx, stmt, 2/*VAL*/, Tn_type(stmt, 0));
	int hasReturn = StmtITR_typing(ctx, stmtNN(stmt, 1), 0);
	Stmt_setSTOPITR(stmt, hasReturn);
	END_BLOCK(stmt, esp);
	return Stmt_typed(ctx, stmt, TYPE_void);
}

static kTerm* ASSERT_typing(CTX ctx, kStmtExpr *stmt)
{
	TYPING_Condition(ctx, stmt, 0);
	if(Tn_isTRUE(stmt, 0)) {
		return knh_Stmt_done(ctx, stmt);
	}
	if(Tn_isFALSE(stmt, 0)) {
		WarningAlwaysFalseAssertion(ctx);
	}
	return Stmt_typed(ctx, stmt, TYPE_void);
}

/* ------------------------------------------------------------------------ */
/* [METHOD] */

static kflag_t METHOD_flag(CTX ctx, kStmtExpr *o, kclass_t cid)
{
	kflag_t flag = 0;
	if(IS_Map(DP(o)->metaDictCaseMap)) {
		ADD_FLAG(flag, "Virtual", FLAG_Method_Virtual);
		ADD_FLAG(flag, "Private", FLAG_Method_Private);
		ADD_FLAG(flag, "Const", FLAG_Method_Const);
		ADD_FLAG(flag, "Static", FLAG_Method_Static);
		ADD_FLAG(flag, "Immutable", FLAG_Method_Static);
		ADD_FLAG(flag, "Throwable", FLAG_Method_Throwable);
		ADD_FLAG(flag, "Iterative", FLAG_Method_Iterative);
		ADD_FLAG(flag, "Restricted", FLAG_Method_Restricted);
		ADD_FLAG(flag, "Smart", FLAG_Method_Restricted);
		if(class_isSingleton(cid)) flag |= FLAG_Method_Static;
		if(class_isImmutable(cid)) flag |= FLAG_Method_Immutable;
//		if(class_isDebug(cid)) flag |= FLAG_Method_Debug;
	}
	return flag;
}

static kclass_t METHOD_cid(CTX ctx, kStmtExpr *stmt)
{
	kTerm *tkC = tkNN(stmt, 1); DBG_ASSERT(IS_Term(tkC));
	kclass_t this_cid = DP(ctx->gma)->this_cid;
	if(TT_(tkC) == TT_ASIS) {
		return this_cid;
	}
	else {
		kclass_t cid = knh_Term_cid(ctx, tkC, DP(ctx->gma)->this_cid);
		if(this_cid != O_cid(K_GMASCR) && this_cid != cid) {
			cid = this_cid;
			WarningDifferentMethodClass(ctx, TK_tobytes(tkC), cid);
		}
		return cid;
	}
}

static kmethodn_t METHOD_name(CTX ctx, kStmtExpr *stmt)
{
	kTerm *tkN = tkNN(stmt, 2); DBG_ASSERT(IS_Term(tkN));
	return (TT_(tkN) == TT_ASIS) ? MN_new : Term_mn(ctx, tkN);
}

#define Stmt_isAbstractMethod(stmt)   (DP(stmt)->size == 4)

static kTerm* knh_StmtMTD_typing(CTX ctx, kStmtExpr *stmt, kMethod *mtd, kclass_t mtd_cid)
{
	knh_Fmethod func = NULL;
	DP(mtd)->uri = ULINE_uri(stmt->uline);
	Term_setCONST(ctx, tkNN(stmt, 2/*method*/), mtd);
	func = GammaBuilder_loadMethodFunc(ctx, mtd_cid, (mtd)->mn, knh_StmtMETA_is(ctx, stmt, "Native"));
	if(func != NULL) {
		knh_Method_setFunc(ctx, mtd, func);
		return knh_Stmt_done(ctx, stmt);
	}
	if(Stmt_isAbstractMethod(stmt)) {
		return knh_Stmt_done(ctx, stmt);
	}
	return TM(stmt);
}

static kTerm* METHOD_typing(CTX ctx, kStmtExpr *stmtM)
{
	kclass_t mtd_cid = METHOD_cid(ctx, stmtM);
	kflag_t flag   = METHOD_flag(ctx, stmtM, mtd_cid);
	kmethodn_t mn = METHOD_name(ctx, stmtM);
	kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, K_GMANS, mtd_cid, mn);
	kParam *mp = NULL;
	kStmtExpr *stmtP = stmtNN(stmtM, 3/*PARAMs*/);
	int isDynamic = 0, allowDynamic = 1;
	if(StmtMETHOD_isFFI(stmtM) || knh_StmtMETA_is(ctx, stmtM, "Native") || knh_StmtMETA_is(ctx, stmtM, "Glue")) {
		allowDynamic = 0;
	}
	if(mtd != NULL && (mtd)->mn < MN_OPSIZE) { /* op */
		WarningDeprecated(ctx, "operator overriding");
		mtd = NULL;
	}
	/* New method, and constructors are always new */
	if(mtd != NULL) {
		DBG_P("OVERRIDING %s.%s", CLASS__(mtd->cid), MN__(mtd->mn));
		if(mtd->cid != mtd_cid && (Method_isPrivate(mtd) || mn == MN_new)) {
			mtd = NULL;
			goto L_CheckScope;
		}
		if(Method_isOverload(mtd) && knh_StmtMETA_is(ctx, stmtM, "Overload")) {
			mtd = NULL;
		}
	}
L_CheckScope:;
	if(!knh_NameSpace_isInsideScope(ctx, K_GMANS, mtd_cid)) {
		if(!knh_StmtMETA_is(ctx, stmtM, "Public")) {
			flag |= FLAG_Method_Private;
		}
	}
	if(mtd == NULL) {  // newly defined method
		size_t i;
		mtd = new_Method(ctx, flag, mtd_cid, mn, NULL);
		if(knh_StmtMETA_is(ctx, stmtM, "Overload")) {
			Method_setOverload(mtd, 1);
		}
		knh_NameSpace_addMethod(ctx, mtd_cid, mtd);
//		DP(mtd)->uri = ULINE_uri(stmtM->uline);
//		Term_setCONST(ctx, tkNN(stmtM, 2/*method*/), mtd);
		mp = new_Param(ctx);
		KNH_SETv(ctx, DP(mtd)->mp, mp);
		for(i = 0; i < DP(stmtP)->size; i += 3) {
			kTerm *tkT = DECL3_typing(ctx, stmtP, i, TYPE_var, _VFINDTHIS | _VFINDSCRIPT, allowDynamic);
			if(TT_(tkT) != TT_ERR) {
				knh_Param_addParam(ctx, mp, tkT->cid, Term_fn(ctx, tkNN(stmtP, i+1)));
				if(tkT->cid == TYPE_var) isDynamic = 1;
			}
			else{
				kStmtExproERR(ctx, stmtM, tkT);
				return tkT;
			}
		}
		Param_setVARGs(mp, StmtMETHOD_isVARGs(stmtM));
		kTerm *tkR = TTYPE_typing(ctx, tkNN(stmtM, 0), TYPE_var);
		ktype_t rtype = (tkR)->cid;
		if(rtype == TYPE_var) {
			Param_setRVAR(mp, 1);
		}
		else  {
			knh_Param_addReturnType(ctx, mp, rtype);
		}
		if(knh_StmtMETA_is(ctx, stmtM, "Around")) {
			WARN_Ignored(ctx, "annotation", CLASS_unknown, "@Around");
		}
	}
	else {  // overriding method
		size_t i;
		mp = DP(mtd)->mp;
		if((mtd)->cid != mtd_cid) { /* Overriding */
			if(Method_isFinal(mtd)) {
				return ErrorFinalMethod(ctx, (mtd)->cid, mn);
			}
		}
		if(DP(stmtP)->size / 3 != mp->psize && Param_isVARGs(mp) != StmtMETHOD_isVARGs(stmtM)) {
			return ErrorDifferentlyDefinedMethod(ctx, mtd_cid, mn);
		}
		for(i = 0; i < DP(stmtP)->size; i += 3) {
			size_t n = i / 3;
			kparam_t *p = knh_Param_get(mp, n);
			kTerm *tkT = DECL3_typing(ctx, stmtP, i, p->type, _VFINDTHIS | _VFINDSCRIPT, allowDynamic);
			if(TT_(tkT) == TT_ERR) {
				kStmtExproERR(ctx, stmtM, tkT);
				return tkT;
			}
			if(tkT->cid == TYPE_var) {
				isDynamic = 1; continue;
			}
			if((tkT)->cid != p->type) {
				return ErrorDifferentlyDefinedMethod(ctx, mtd_cid, mn);
			}
		}
		/* check return value */
		if(mp->rsize == 0) {
			kTerm *tkR = TTYPE_typing(ctx, tkNN(stmtM, 0), TYPE_void);
			ktype_t rtype = (tkR)->cid;
			if(rtype != TYPE_void) {
				return ErrorDifferentlyDefinedMethod(ctx, mtd_cid, mn);
			}
		}
		else {
			kparam_t *p = knh_Param_rget(mp, 0);
			kTerm *tkR = TTYPE_typing(ctx, tkNN(stmtM, 0), p->type);
			ktype_t rtype = (tkR)->cid;
			if(rtype != p->type) {
				return ErrorDifferentlyDefinedMethod(ctx, mtd_cid, mn);
			}
		}
		if((mtd)->cid != mtd_cid) { /* @Override */
			mtd = new_Method(ctx, flag, mtd_cid, mn, NULL);
			knh_NameSpace_addMethod(ctx, mtd_cid, mtd);
			KNH_SETv(ctx, DP(mtd)->mp, mp);
		}
		else if(knh_StmtMETA_is(ctx, stmtM, "Around")) {
			kMethod *promtd = new_Method(ctx, DP(mtd)->flag, mtd_cid, mn, NULL);
#ifdef K_USING_BMGC
			knh_MethodEX_t temp;
			knh_memcpy(&temp, DP(mtd), sizeof(knh_MethodEX_t));
			knh_memcpy(DP(mtd), DP(promtd), sizeof(knh_MethodEX_t));
			knh_memcpy(DP(promtd), &temp, sizeof(knh_MethodEX_t));
#else
			knh_MethodEX_t *temp = mtd->b; mtd->b = promtd->b; promtd->b = temp;
#endif
			promtd->fcall_1 = mtd->fcall_1;
			promtd->pc_start = mtd->pc_start; // copied from mtd => promtd
			KNH_SETv(ctx, DP(mtd)->mp, mp);
			KNH_SETv(ctx, DP(mtd)->proceed, promtd);
		}
//		DP(mtd)->uri = ULINE_uri(stmtM->uline);
//		Term_setCONST(ctx, tkNN(stmtM, 2/*method*/), mtd);
	}

	Method_setFastCall(mtd, 0);
	if(knh_StmtMETA_is(ctx, stmtM, "FastCall")) {
		if(DP(mtd)->mp->psize == 0 || (DP(mtd)->mp->psize == 1 && Method_isStatic(mtd))) {
			Method_setFastCall(mtd, 1);
		}
	}
	if(knh_StmtMETA_is(ctx, stmtM, "Iterative")) {
		if(DP(mtd)->mp->psize != 0) {
			return ERROR_Unsupported(ctx, "parameterized iterative method", CLASS_unknown, NULL);
		}
	}
	if(isDynamic == 1) {
		DBG_P("************************* dynamic ******************************");
		Method_setDynamic(mtd, 1);
		KNH_SETv(ctx, DP(mtd)->gmascr, ctx->gma->scr);
		if(DP(stmtM)->size > 4) {
			KNH_SETv(ctx, DP(mtd)->tsource, tkNN(stmtM, 4/*source*/));
		}
		else {
			KNH_SETv(ctx, DP(mtd)->tsource, KNH_NULL);
		}
		return knh_Stmt_done(ctx, stmtM);
	}
	if(StmtMETHOD_isFFI(stmtM)) {
		kDictMap *mdata = (kDictMap*)tkNN(stmtM, 4)->data;
		if(!knh_Method_ffi(ctx, mtd, K_GMANS, mdata)) {
			return ERROR_WrongFFILink(ctx, S_totext(tkNN(stmtM, 4)->text));
		}
		return knh_Stmt_done(ctx, stmtM);
	}
	return knh_StmtMTD_typing(ctx, stmtM, mtd, mtd_cid);
}

/* ------------------------------------------------------------------------ */

static kTerm *DECLFIRST_typing(CTX ctx, kStmtExpr *stmtP)
{
	if(DP(stmtP)->size == 3) {
		return DECL3_typing(ctx, stmtP, 0, TYPE_var, _VFINDTHIS | _VFINDSCRIPT, 0);
	}
	return ERROR_SingleParam(ctx);
}

static kflag_t TYPEMAP_flag(CTX ctx, kStmtExpr *stmt)
{
	kflag_t flag = 0;
	if(IS_Map(DP(stmt)->metaDictCaseMap)) {
		if(knh_DictMap_getNULL(ctx, DP(stmt)->metaDictCaseMap, STEXT("Const"))) {
			flag |= FLAG_TypeMap_Const;
		}
		if(knh_DictMap_getNULL(ctx, DP(stmt)->metaDictCaseMap, STEXT("Semantic"))) {
			flag |= FLAG_TypeMap_Semantic;
		}
	}
	return flag;
}

static knh_Fmethod loadTypeMapFunc(CTX ctx, kclass_t scid, kclass_t tcid)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	knh_write_cname(ctx, cwb->w, scid);
	knh_putc(ctx, cwb->w, '_');
	knh_write_cname(ctx, cwb->w, tcid);
	char *p = (char*)CWB_totext(ctx, cwb);
	while(*p != 0) {
		if(!isalnum(*p)) *p = '_';
		p++;
	}
	DBG_P("funcname='%s'", CWB_totext(ctx, cwb));
	knh_Fmethod f = (knh_Fmethod)knh_loadGlueFunc(ctx, CWB_totext(ctx, cwb), 1/*isVerbose*/);
	CWB_close(ctx, cwb);
	return f;
}

static kTerm* TYPEMAP_typing(CTX ctx, kStmtExpr *stmt)
{
	kTerm *tkT = TTYPE_typing(ctx, tkNN(stmt, 1), CLASS_unknown);
	kTerm *tkS = DECLFIRST_typing(ctx, stmtNN(stmt, 2));
	if(TT_(tkT) == TT_ERR) return tkT;
	if(TT_(tkS) == TT_ERR) return tkS;
	kclass_t scid = tkS->cid, tcid = tkT->cid;
	DBG_P("%s ==> %s", CLASS__(scid), CLASS__(tcid));
	kTypeMap *tmr = knh_findTypeMapNULL(ctx, scid, tcid);
	if(tmr != NULL && tmr->scid == scid && !knh_StmtMETA_is(ctx, stmt, "Override")) {
		return ERROR_AlreadyDefined(ctx, "typemap", UPCAST(tmr)); // FIXME
	}
	kMethod *mtd = new_Method(ctx, 0, O_cid(ctx->gma->scr), MN_, NULL);
	kParam *pa = new_(Param);
	KNH_SETv(ctx, DP(mtd)->mp, pa);
	knh_Param_addParam(ctx, pa, scid, Term_fn(ctx, tkNN(stmtNN(stmt, 2), 1)));
	knh_Param_addReturnType(ctx, pa, tcid);
	DP(mtd)->uri = ULINE_uri(stmt->uline);
	tmr = new_TypeMapMethod(ctx, TYPEMAP_flag(ctx, stmt), mtd);
	knh_addTypeMap(ctx, tmr, 1/*initCache*/);
	DBG_ASSERT(TT_(tkNN(stmt, 3)) == TT_ASIS);
	if(knh_StmtMETA_is(ctx, stmt, "Native")) {
		knh_Fmethod func = loadTypeMapFunc(ctx, tkS->cid, tkT->cid);
		if(func != NULL) {
			knh_Method_setFunc(ctx, mtd, func);
		}
		return knh_Stmt_done(ctx, stmt);
	}
	KNH_SETv(ctx, tkNN(stmt, 3)->data, mtd);
	return Stmt_typed(ctx, stmt, TYPE_void);
}

static kTerm* FORMAT_typing(CTX ctx, kStmtExpr *stmt)
{
	kmethodn_t mn = MN_toFMT(Term_mn(ctx, tkNN(stmt, 2)));
	DBG_ASSERT(DP(stmt)->size == 3); // check
	kTerm *tkT = DECLFIRST_typing(ctx, stmtNN(stmt, 3));
	if(TT_(tkT) != TT_ERR) {
		kclass_t cid = tkT->cid;
		kMethod *mtd = knh_NameSpace_getFmtNULL(ctx, K_GMANS, cid, mn);
		if(mtd == NULL) {
			mtd = new_Method(ctx, 0, cid, mn, NULL);
			KNH_SETv(ctx, DP(mtd)->mp, KNH_TNULL(Param));
			knh_NameSpace_addFmt(ctx, K_GMANS, mtd);
		}
		return knh_StmtMTD_typing(ctx, stmt, mtd, cid);
	}
	return tkT;
}

/* ------------------------------------------------------------------------ */

#define CASE_STMT(XX, ...) case STT_##XX : { \
		tkRES = XX##_typing(ctx, ## __VA_ARGS__); \
		break;\
	}\

static kTerm *DECLFIELD_typing(CTX ctx, kStmtExpr *stmt, size_t i)
{
	kflag_t flag  = DECL_flag(ctx, stmt, _FGETTER | _FSETTER);
	kTerm *tkT = DECL3_typing(ctx, stmt, i, TYPE_var, _VFINDSCRIPT, 0);
	if(TT_(tkT) != TT_ERR) {
		return GammaBuilder_add(ctx, flag, tkT, tkNN(stmt,i+1), tkNN(stmt,i+2), GF_UNIQUE|GF_FIELD|GF_USEDCOUNT);
	}
	return tkT;
}


static int GammaBuilder_initClassTBLField(CTX ctx, kclass_t cid)
{
	const knh_ClassTBL_t *ct = ClassTBL(cid);
	if(ct->fsize == 0 && (ct->bcid == CLASS_Object || ct->bcid == CLASS_CppObject)) {
		knh_gamma2_t *gf = DP(ctx->gma)->gf;
		size_t i;
		const knh_ClassTBL_t *supct = ct->supTBL;
		DP(ctx->gma)->flag = 0;
		DP(ctx->gma)->this_cid = cid;
		if(!(supct->fsize < DP(ctx->gma)->gcapacity)) {
			gf = GammaBuilder_expand(ctx, ctx->gma, supct->fsize);
		}
		GammaBuilder_clear(ctx, 0, NULL);
		for(i = 0; i < supct->fsize; i++) {
			gf[i].flag = supct->fields[i].flag;
			gf[i].type = supct->fields[i].type;
			gf[i].fn   = supct->fields[i].fn;
			gf[i].ucnt = 1;
		}
		DP(ctx->gma)->gsize = supct->fsize;
		if(class_isExpando(cid) && ct->xdataidx == -1) {
			i = DP(ctx->gma)->gsize;
			gf[i].flag = 0;
			gf[i].type = TYPE_Map;
			gf[i].fn   = FN_xdata;
			gf[i].ucnt = 1;
			KNH_SETv(ctx, gf[i].tk, KNH_NULL);
			((knh_ClassTBL_t*)ct)->xdataidx = (kshort_t)i;
			DP(ctx->gma)->gsize += 1;
		}
		return 1;
	}
	return 0;
}

static void ClassTBL_newField(CTX ctx, knh_ClassTBL_t *ct)
{
	size_t i, gsize = DP(ctx->gma)->gsize, fsize = gsize;
	knh_gamma2_t *gf = DP(ctx->gma)->gf;
	DBLNDATA_(
		for(i = 0; i < gsize; i++) {
			ktype_t type = gf[i].type;
			if(IS_Tunbox(type)) fsize++;
		}
	);
	if(fsize > 0) {
		size_t fi = 0;
		ct->fields = (kfieldinfo_t*)KNH_MALLOC(ctx, fsize * sizeof(kfieldinfo_t));
		ct->fcapacity = fsize;
		ct->fsize = fsize;
		for(i = 0; i < gsize; i++) {
			ktype_t type = gf[i].type;
			ct->fields[fi].flag = gf[i].flag;
			ct->fields[fi].type = type;
			ct->fields[fi].fn = gf[i].fn;
			ct->fields[fi].israw = (type == TYPE_void || IS_Tunbox(type)) ? 1 : 0;
			fi++;
			DBLNDATA_(if(IS_Tunbox(type)) {
				ct->fields[fi].fn   = FN_;
				ct->fields[fi].type = TYPE_void;
				ct->fields[fi].israw = 1;
				fi++;
			})
		}
	}
}

static kObject** ObjectField_new(CTX ctx, kObject *o)
{
	const knh_ClassTBL_t *ct = O_cTBL(o);
	if(ct->bcid == CLASS_CppObject) {
		kRawPtr *p = (kRawPtr*)o;
		p->kfields = (kObject**)KNH_MALLOC(ctx, sizeof(kObject*) * ct->fsize);
		return p->kfields;
	}
	else {
		o->fields = &(o->smallobject);
		if(!(ct->fsize < K_SMALLOBJECT_FIELDSIZE)) {
			o->fields = (kObject**)KNH_MALLOC(ctx, sizeof(kObject*) * ct->fsize);
		}
		return o->fields;
	}
}

static void ObjectField_init(CTX ctx, kObject *o)
{
	size_t i;
	knh_gamma2_t *gf = DP(ctx->gma)->gf;
	const knh_ClassTBL_t *ct = O_cTBL(o), *supct = ct->supTBL;
	kObject **v = ObjectField_new(ctx, o);
	if(supct->fsize > 0) {
		kObject **supv = (supct->bcid == CLASS_Object) ? supct->protoNULL->fields : ((kRawPtr*)supct->protoNULL)->kfields;
		knh_memcpy(v, supv, sizeof(kObject*) * supct->fsize);
#ifdef K_USING_RCGC
		for(i = 0; i < supct->fsize; i++) {
			if(supct->fields[i].israw == 0) {
				RCinc(ctx, supv[i]);
			}
		}
#endif
	}
	for(i = supct->fsize; i < ct->fsize; i++) {
		Object *val = (IS_Term(gf[i].tk)) ? gf[i].tk->data : KNH_NULL;
		ObjectField_add(ctx, ct->cid, v, i, gf[i].type, val);
	}
}

static void GammaBuilder_declareClassField(CTX ctx, kclass_t cid, size_t s)
{
	knh_ClassTBL_t *ct = varClassTBL(cid);
	DBG_ASSERT(O_cid(ct->defnull) == cid);
	ClassTBL_newField(ctx, ct);
	ObjectField_init(ctx, ct->protoNULL);
	ObjectField_init(ctx, ct->defobj);
	knh_ClassTBL_setObjectCSPI(ctx, ct);
	GammaBuilder_clear(ctx, 0, NULL);
}

#define IS_DeclareScalaClass(stmt)   (TT_(tkNN(stmt, 1)) != TT_ASIS)

static kTerm* CLASS_typing(CTX ctx, kStmtExpr *stmt)
{
	kTerm *tkC = tkNN(stmt, 0);
	kclass_t this_cid = (tkC)->cid;
	size_t i;
	kTerm *tkRES = NULL;
	int isAllowedNewField = GammaBuilder_initClassTBLField(ctx, this_cid);
	if(DP(stmt)->size == 5) {
		kStmtExpr *stmtFIELD = knh_Term_parseStmt(ctx, stmt->uline, tkNN(stmt, 4));
		KNH_SETv(ctx, stmtNN(stmt, 4), stmtFIELD);
	}
	size_t s = DP(ctx->gma)->gsize;
	if(IS_DeclareScalaClass(stmt)) {  /* @ac(DeclareScalaClass) */
		if(!isAllowedNewField) {
			return ERROR_UnableToAdd(ctx, this_cid, "field");
		}
		kStmtExpr *stmtP = stmtNN(stmt, 1);
		for(i = 0; i < DP(stmtP)->size; i += 3) {
			tkRES = DECLFIELD_typing(ctx, stmtP, i);
			if(TT_(tkRES) == TT_ERR) return tkRES;
		}
		{
			CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
			knh_Bytes_write(ctx, cwb->ba, S_tobytes(tkC->text));
			knh_Bytes_write(ctx, cwb->ba, STEXT("("));
			for(i = 0; i < DP(stmtP)->size; i += 3) {
				if(i > 0) knh_Bytes_write(ctx, cwb->ba, STEXT(", "));
				knh_Bytes_write(ctx, cwb->ba, S_tobytes(tkNN(stmtP, i+1)->text));
			}
			knh_Bytes_write(ctx, cwb->ba, STEXT(") {"));
			for(i = 0; i < DP(stmtP)->size; i += 3) {
				const char *t = S_totext(tkNN(stmtP, i+1)->text);
				knh_printf(ctx, cwb->w, "this.%s=%s; ", t, t);
			}
			knh_Bytes_write(ctx, cwb->ba, STEXT("}"));
			kStmtExpr *stmtNEW = knh_bytes_parseStmt(ctx, CWB_tobytes(cwb), stmt->uline);
			DBG_ASSERT(DP(stmtNEW)->nextNULL == NULL);
			if(DP(stmt)->size == 5) {
				KNH_INITv(DP(stmtNEW)->nextNULL, stmtNN(stmt, 4));
				KNH_SETv(ctx, stmtNN(stmt, 4), stmtNEW);
			}
			else {
				DBG_ASSERT(DP(stmt)->size == 4);
				knh_Stmt_add(ctx, stmt, stmtNEW);
			}
			CWB_close(ctx, cwb);
		}
	}
	if(DP(stmt)->size == 5) {
		kStmtExpr *stmtFIELD = stmtNN(stmt, 4/*instmt*/);
		while(stmtFIELD != NULL) {
			ctx->gma->uline = stmtFIELD->uline;
			if(STT_(stmtFIELD) == STT_DECLFIELD) {
				if(!isAllowedNewField) {
					return ERROR_UnableToAdd(ctx, this_cid, "field");
				}
				tkRES = DECLFIELD_typing(ctx, stmtFIELD, /*n*/0);
				if(TT_(tkRES) == TT_ERR) {
					kStmtExproERR(ctx, stmt, tkRES);
					return tkRES;
				}
			}
			stmtFIELD = DP(stmtFIELD)->nextNULL;
		}
	}
	GammaBuilder_declareClassField(ctx, this_cid, s);
	if(DP(stmt)->size == 5) {
		kStmtExpr *stmtFIELD = stmtNN(stmt, 4/*instmt*/);
		while(stmtFIELD != NULL) {
			tkRES = NULL;
			ctx->gma->uline = stmtFIELD->uline;
			switch(STT_(stmtFIELD)) {
				CASE_STMT(METHOD, stmtFIELD);
				CASE_STMT(FORMAT, stmtFIELD);
				case STT_DONE: case STT_DECL: case STT_LET: case STT_ERR: break;
				default: {
					WARN_Ignored(ctx, "statement", CLASS_unknown, TT__(STT_(stmtFIELD)));
					knh_Stmt_done(ctx, stmtFIELD);
				}
			}
			if(tkRES != NULL && TT_(tkRES) == TT_ERR) {
				kStmtExproERR(ctx, stmtFIELD, tkRES);
			}
			stmtFIELD = DP(stmtFIELD)->nextNULL;
		}
	}
	return TM(stmt);
}

/* ------------------------------------------------------------------------ */
/* [REGISTER] */

static kTerm* REGISTER_typing(CTX ctx, kStmtExpr *stmt)
{
	size_t i;
	kStmtExpr *stmtTAIL = stmt;
	if(DP(stmtTAIL)->nextNULL == NULL) {
		knh_Stmt_done(ctx, stmt);
	}
	for(i = 0; i < DP(stmt)->size; i++) {
		TYPING(ctx, stmt, i, TYPE_var, _NOVOID|_NOBOX);
		kStmtExpr *stmtREG = stmtNN(stmt, i);
		if(IS_StmtExpr(stmtREG) && stmtREG->type != TYPE_var) {
			kindex_t idx = DP(ctx->gma)->gsize;
			knh_gamma2_t *gf = DP(ctx->gma)->gf;
			kTerm *tkIDX = new_TermTYPED(ctx, TT_LVAR, stmtREG->type, idx - DP(ctx->gma)->fvarsize);
			if(!(idx < DP(ctx->gma)->gcapacity)) {
				gf = GammaBuilder_expand(ctx, ctx->gma, /*minimum*/4);
			}
			gf[idx].flag  = _FREG;
			gf[idx].type  = stmtREG->type;
			gf[idx].fn    = FN_;
			gf[idx].ucnt  = 1;
			KNH_SETv(ctx, gf[idx].tkIDX, tkIDX);
			KNH_SETv(ctx, gf[idx].stmt, stmtREG);
			DP(ctx->gma)->gsize += 1;
			GammaBuilder_foundREGISTER(ctx->gma, 1);
			{
				kStmtExpr *stmtLET = new_Stmt2(ctx, STT_LET, new_(Term), tkIDX, stmtREG, NULL);
				Stmt_setESPIDX(ctx, stmtLET);
				Stmt_typed(ctx, stmtLET, TYPE_void);
				KNH_INITv(DP(stmtLET)->nextNULL, DP(stmtTAIL)->nextNULL);
				KNH_SETv(ctx, DP(stmtTAIL)->nextNULL, stmtLET);
				stmtTAIL = stmtLET;
			}
			DBG_P("******* REGISTER %s _%d(gsize=%d) TT=%s ******", TYPE__(tkIDX->type), idx, DP(ctx->gma)->gsize, TT__(stmtREG->stt));
		}
	}
	return Stmt_typed(ctx, stmt, TYPE_void);
}

static int Term_equals(CTX ctx, kTerm *tk, kTerm *tk2)
{
	switch(TT_(tk)) {
		case TT_CONST: {
			return (knh_Object_compareTo((tk)->data, (tk2)->data) == 0);
		}
		default: {
			//DBG_P("TT=%s", TT__(TT_(tk2)));
			if((tk)->index != (tk2)->index) return 0;
		}
	}
	return 1;
}

static kbool_t Stmt_equals(CTX ctx, kStmtExpr *stmt, kStmtExpr *stmtA)
{
	size_t i;
	for(i = 0; i < DP(stmt)->size; i++) {
		kTerm *t1 = tmNN(stmt, i);
		kTerm *t2 = tmNN(stmtA, i);
		if(TT_(t1) == TT_(t2) && t1->type == t2->type) {
			if(IS_StmtExpr(t1)) {
				kStmtExpr *stmt1 = (kStmtExpr*)t1;
				kStmtExpr *stmt2 = (kStmtExpr*)t2;
				if(DP(stmt1)->size == DP(stmt2)->size) {
					if(!Stmt_equals(ctx, stmt1, stmt2)) return 0;
				}
			}
			else {
				if(!Term_equals(ctx, (kTerm*)t1, (kTerm*)t2)) return 0;
			}
		}
	}
	return 1;
}

static kTerm *GammaBuilder_findRegExpr(CTX ctx, kStmtExpr *stmt)
{
	knh_gamma2_t *gf = DP(ctx->gma)->gf;
	size_t i = DP(ctx->gma)->fvarsize, size = DP(ctx->gma)->gsize;
	for(; i < size; i++) {
		kStmtExpr *stmtREG = gf[i].stmt;
		if(FLAG_is(gf[i].flag, _FREG) /*&& IS_StmtExpr(stmtREG)*/ && STT_(stmt) == STT_(stmtREG) && stmt->type == stmtREG->type
			&& DP(stmt)->size == DP(stmtREG)->size && Stmt_equals(ctx, stmt, stmtREG)) {
			DBG_P("*** FOUND REG %s _%d TT=%s", TYPE__(stmtREG->type), (gf[i].tkIDX)->index, TT__(stmtREG->stt));
			return new_TermTYPED(ctx, TT_LVAR, stmtREG->type, (gf[i].tkIDX)->index);
		}
	}
	return TM(stmt);
}

static kTerm* BLOCK_typing(CTX ctx, kStmtExpr *stmt, int needsReturn)
{
	int hasReturn = StmtITR_typing(ctx, stmtNN(stmt, 0), needsReturn);
	Stmt_setSTOPITR(stmt, hasReturn);
	return TM(stmt);
}

static kTerm *Stmt_typing(CTX ctx, kStmtExpr *stmt, int needsReturn)
{
	kTerm *tkRES = NULL;
	if(Stmt_isTyped(stmt)) return TM(stmt);
	if(STT_isExpr(STT_(stmt))) {
		tkRES = EXPR_typing(ctx, stmt, TYPE_void);
		if(GammaBuilder_hasREGISTER(ctx->gma) && IS_StmtExpr(tkRES)) {
			tkRES = GammaBuilder_findRegExpr(ctx, (kStmtExpr*)tkRES);
		}
	}
	else {
		switch(STT_(stmt)) {
			CASE_STMT(BLOCK, stmt, needsReturn);
			CASE_STMT(DECL, stmt);
			CASE_STMT(LETM, stmt);
			CASE_STMT(SELECT, stmt);
			CASE_STMT(SWAP, stmt);
			CASE_STMT(IF, stmt, needsReturn);
			CASE_STMT(SWITCH, stmt, needsReturn);
			CASE_STMT(WHILE, stmt);
			CASE_STMT(DO, stmt);
			CASE_STMT(FOR, stmt);
			CASE_STMT(FOREACH, stmt);
			CASE_STMT(TRY, stmt, needsReturn);
			CASE_STMT(THROW, stmt);
			CASE_STMT(RETURN, stmt);
			CASE_STMT(YIELD, stmt);
			CASE_STMT(PRINT, stmt);
			CASE_STMT(REGISTER, stmt);
			CASE_STMT(ASSURE, stmt);
			CASE_STMT(ASSERT, stmt);
			case STT_ERR:
			case STT_BREAK:
			case STT_CONTINUE:
			case STT_DONE:
				tkRES = Stmt_typed(ctx, stmt, TYPE_void);
				break;
			default:
				tkRES = ERROR_OnlyTopLevel(ctx, TT__(STT_(stmt)));
		}
	}
	return tkRES;
}


static void GammaBuilder_initThis(CTX ctx, kclass_t cid, ktype_t it_type)
{
	knh_gamma2_t *gf = DP(ctx->gma)->gf;
	GammaBuilder_clear(ctx, 0, NULL);
	DP(ctx->gma)->this_cid = cid;
	gf[0].flag = 0;
	gf[0].type = TYPE_cid(cid);
	gf[0].fn   = FN_this;
	gf[0].ucnt = 1;
	KNH_SETv(ctx, gf[0].tkIDX, KNH_TNULL(Term));
	DBG_ASSERT(TT_(gf[0].tkIDX) == TT_FVAR);
	DBG_ASSERT((gf[0].tkIDX)->index == 0);
	if(it_type == TYPE_void) {
		DP(ctx->gma)->psize    = 0;
		DP(ctx->gma)->gsize    = 1;
		DP(ctx->gma)->fvarsize = 1;
	}
	else {
		DP(ctx->gma)->psize = 1;
		gf[1].flag = 0;
		gf[1].type = it_type;
		gf[1].fn   = FN_it;
		gf[1].ucnt = 1;
		DP(ctx->gma)->gsize  = 2;
		DP(ctx->gma)->fvarsize = 2;
		KNH_SETv(ctx, gf[1].tkIDX, new_TermTYPED(ctx, TT_FVAR, it_type, 1));
	}
	DBG_P("******* proceedNC = %p *********", DP(ctx->gma)->proceedNC);
	DP(ctx->gma)->tkScriptNC = NULL;
	DP(ctx->gma)->proceedNC = NULL;
}

#define CASE_STMT2(XX, ...) case STT_##XX : {              \
		GammaBuilder_initThis(ctx, this_cid, O_cid(ctx->evaled)); \
		tkRES = XX##_typing(ctx, ## __VA_ARGS__);          \
		GammaBuilder_shiftLocalScope(ctx);                        \
		break;                                             \
	}\

void SCRIPT_typing(CTX ctx, kStmtExpr *stmt)
{
	kclass_t this_cid = O_cid(K_GMASCR);
	kTerm *tkRES = TM(stmt);
	if(DP(ctx->gma)->gcapacity == 0) {
		GammaBuilder_expand(ctx, ctx->gma, 8/*init*/);
	}
	ctx->gma->uline = stmt->uline;
	DP(ctx->gma)->this_cid = O_cid(ctx->gma->scr);
	KNH_SETv(ctx, DP(ctx->gma)->mtd, KNH_NULL);
	switch(STT_(stmt)) {
		CASE_STMT(CLASS, stmt);
		CASE_STMT(METHOD, stmt);
		CASE_STMT(FORMAT, stmt);
		CASE_STMT(TYPEMAP, stmt);
		CASE_STMT2(DECLSCRIPT, stmt);
		CASE_STMT2(LET, stmt, TYPE_void);
		CASE_STMT2(SWAP, stmt);
		CASE_STMT2(LETM, stmt);
		CASE_STMT2(SELECT, stmt);
	}
	if(TT_(tkRES) == TT_ERR) {
		kStmtExproERR(ctx, stmt, tkRES);
	}
	if(IS_Term(tkRES)) {
		knh_Stmt_done(ctx, stmt);
	}
}

/* ------------------------------------------------------------------------ */
/* [asm] */

kbool_t typingMethod2(CTX ctx, kMethod *mtd, kStmtExpr *stmtB)
{
	kParam *mp = DP(mtd)->mp;
	size_t i, psize = mp->psize;
	GammaBuilder_initThis(ctx, (mtd)->cid, TYPE_void);
	for(i = 0; i < psize; i++) {
		kparam_t *p = knh_Param_get(mp, i);
		GammaBuilder_addFVAR(ctx, 0/*_FREADONLY*/, p->type, p->fn, 0);
	}
	DP(ctx->gma)->psize = psize;
	DBG_ASSERT(DP(ctx->gma)->psize + 1 == DP(ctx->gma)->fvarsize);
	if(Param_isVARGs(mp)) {
		GammaBuilder_addFVAR(ctx, _FREADONLY, TYPE_void/*FIXME*/, FN_vargs, 0);
	}
	if(IS_Method(DP(mtd)->proceed)) {
		DP(ctx->gma)->proceedNC = DP(mtd)->proceed;
	}
	int needsReturn = (GammaBuilder_getReturnType(ctx) != TYPE_void) && (GammaBuilder_getReturnType(ctx) != TYPE_var);
	int hasReturn = StmtITR_typing(ctx, stmtB, needsReturn);
	if(GammaBuilder_getReturnType(ctx) == TYPE_var) {
		GammaBuilder_inferReturnType(ctx, TYPE_void);
		needsReturn = 0;
	}
	if(!hasReturn && needsReturn) {
		kStmtExpr *stmtRETURN = new_Stmt2(ctx, STT_RETURN, NULL);
		kStmtExpr *stmtLAST = stmtB;
		while(DP(stmtLAST)->nextNULL != NULL) stmtLAST = DP(stmtLAST)->nextNULL;
		KNH_INITv(DP(stmtLAST)->nextNULL, stmtRETURN);
		RETURN_typing(ctx, stmtRETURN);
	}
	return (STT_(stmtB) != STT_ERR);
}

static void METHOD_asm(CTX ctx, kStmtExpr *stmt)
{
	kMethod *mtd = (tkNN(stmt, 2/*method*/))->mtd;
	DBG_ASSERT(IS_Method(mtd));
	DBG_ASSERT(DP(stmt)->size == 6);
	if(TT_(tkNN(stmt, 4)) == TT_DOC) {
		KNH_SETv(ctx, DP(mtd)->tsource, tkNN(stmt, 4/*source*/));
//		DBG_P("@@ stmt_line =%d, stmt_code=%d", (kshort_t)stmt->uline, (kshort_t)tkNN(stmt, 4)->uline);
//		DBG_P("source='''%s'''", S_totext(tkNN(stmt, 4/*source*/)->text));
	}
	if(TT_(tkNN(stmt, 5)) == TT_CODE) {  // source code should be parsed just before asm
//		DBG_P("@@ stmt_line =%d, stmt_code=%d", (kshort_t)stmt->uline, (kshort_t)tkNN(stmt, 5)->uline);
		KNH_SETv(ctx, stmtNN(stmt, 5), knh_Term_parseStmt(ctx, stmt->uline, tkNN(stmt, 5)));
	}
	//DBG_ASSERT(tkNN(stmt, 5)->uline == stmt->uline);  // bugs fixed
	knh_Method_asm(ctx, mtd, stmtNN(stmt, 5), typingMethod2);
}

static void TYPEMAP_asm(CTX ctx, kStmtExpr *stmt)
{
	kMethod *mtd = (tkNN(stmt, 3/*method*/))->mtd;
	DBG_ASSERT(IS_Method(mtd));
	if(TT_(tkNN(stmt, 4)) == TT_DOC) {
		KNH_SETv(ctx, DP(mtd)->tsource, tkNN(stmt, 4/*source*/));
	}
	if(TT_(tkNN(stmt, 5)) == TT_CODE) {
		KNH_SETv(ctx, stmtNN(stmt, 5), knh_Term_parseStmt(ctx, stmt->uline, tkNN(stmt, 5)));
	}
	knh_Method_asm(ctx, mtd, stmtNN(stmt, 5), typingMethod2);
}

static kbool_t typingFormat2(CTX ctx, kMethod *mtd, kStmtExpr *stmtB)
{
	GammaBuilder_initThis(ctx, CLASS_OutputStream, TYPE_void);
	GammaBuilder_addFVAR(ctx, 0, mtd->cid, FN_it, 1/*ucnt*/);
	StmtITR_typing(ctx, stmtB, 0);
	return (STT_(stmtB) != STT_ERR);
}

static void FORMAT_asm(CTX ctx, kStmtExpr *stmt)
{
	kMethod *mtd = (tkNN(stmt, 2/*method*/))->mtd;
	if(DP(stmt)->size == 5) {
		kStmtExpr *stmtOP = new_Stmt2(ctx, STT_OPR, NULL); // TODO
		knh_Stmt_add(ctx, stmt, stmtOP);
	}
	else {
		DBG_ASSERT(DP(stmt)->size == 6);
		DBG_ASSERT(TT_(tkNN(stmt, 5)) == TT_CODE);
		KNH_SETv(ctx, stmtNN(stmt, 5), knh_Term_parseStmt(ctx, stmt->uline, tkNN(stmt, 5)));
	}
	KNH_SETv(ctx, DP(mtd)->tsource, tkNN(stmt, 4/*source*/));
	knh_Method_asm(ctx, mtd, stmtNN(stmt,5), typingFormat2);
}

static void CLASS_asm(CTX ctx, kStmtExpr *stmt)
{
	kGammaBuilder *kc = ctx->gma;
	kclass_t prev_cid = DP(kc)->this_cid;
	kclass_t this_cid = (tkNN(stmt, 0))->cid;
	kStmtExpr *stmtFIELD = stmtNN(stmt, 4/*instmt*/);
	DP(kc)->this_cid = this_cid;
	while(stmtFIELD != NULL) {
		ctx->gma->uline = stmtFIELD->uline;
		if(STT_(stmtFIELD) == STT_METHOD) {
			METHOD_asm(ctx, stmtFIELD);
		}
		else if(STT_(stmtFIELD) == STT_FORMAT) {
			FORMAT_asm(ctx, stmtFIELD);
		}
		stmtFIELD = DP(stmtFIELD)->nextNULL;
	}
	DP(kc)->this_cid = prev_cid;
	knh_Stmt_done(ctx, stmt);
}

void SCRIPT_asm(CTX ctx, kStmtExpr *stmt)
{
	switch(STT_(stmt)) {
	case STT_CLASS: CLASS_asm(ctx, stmt); break;
	case STT_METHOD: METHOD_asm(ctx, stmt); break;
	case STT_FORMAT: FORMAT_asm(ctx, stmt); break;
	case STT_TYPEMAP: TYPEMAP_asm(ctx, stmt); break;
	default: return;
	}
	knh_Stmt_done(ctx, stmt);
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
