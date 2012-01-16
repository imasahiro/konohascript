/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2011 Masahiro Ide <imasahiro9 at gmail.com>
 *           (c) 2011 Shunsuke Shida
 *           (c) 2011 Konoha Team konohaken@googlegroups.com
 *
 * All rights reserved.
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


#define K_INTERNAL 1
#include <konoha1.h>
#include <konoha1/konohalang.h>
#include <konoha1/inlinelibs.h>
#define CAST(T, O)    ((T) O)
#define WRAP(p) ((void*)p)
#define tkNN(stmt, n)        (stmt)->tokens[(n)]
#define tmNN(stmt, n)        (stmt)->terms[(n)]
#define stmtNN(stmt, n)      (stmt)->stmts[(n)]
#define STT_(stmt)   SP(stmt)->stt
#define TT_(tk)   SP(tk)->tt
#define Tn_type(stmt, n)     SP(tmNN(stmt, n))->type
#define Tn_cid(stmt, n)      CLASS_t(Tn_type(stmt, n))

#define NN(n) new_Int(ctx, n)
#define SET0(n, a) do {\
	KNH_SETv(ctx, lsfp[n].o, a);\
	lsfp[n].ndata = O_data(a);\
} while (0)

#define SET1(n, a, b)                SET0(n, a);               SET0(n+1, b)
#define SET2(n, a, b, c)             SET1(n, a, b);            SET0(n+2, c)
#define SET3(n, a, b, c, d)          SET2(n, a, b, c);         SET0(n+3, d)
#define SET4(n, a, b, c, d, e)       SET3(n, a, b, c, d);      SET0(n+4, e)
#define SET5(n, a, b, c, d, e, f)    SET4(n, a, b, c, d, e);   SET0(n+5, f)
#define SET6(n, a, b, c, d, e, f, g) SET5(n, a, b, c, d, e, f);SET0(n+6, g)

#define CALL_(ctx, lsfp, mtd, argc) KNH_SCALL(ctx, lsfp, 0, mtd, argc)
#define CALL(ctx, mtd, n, ...) do {\
	BEGIN_LOCAL(ctx, lsfp, K_CALLDELTA+n);\
	SET##n (K_CALLDELTA, COMPILER_API.Instance, ## __VA_ARGS__);\
	CALL_(ctx, lsfp, mtd, n);\
	END_LOCAL(ctx, lsfp);\
} while (0)

struct knh_CompilerAPI_t {
	kObject *Instance;
#define DEF1(a) kMethod *a
#define DEF2(a, b)                   DEF1(a);DEF1(b)
#define DEF4(a, b, c, d)             DEF2(a, b);DEF2(c, d)
#define DEF8(a, b, c, d, e, f, g, h) DEF4(a, b, c, d);DEF4(e, f, g, h)
	DEF8(ASM, BLOCK, LET, IF, SWITCH, WHILE, DO, FOR);
	DEF8(FOREACH, BREAK, CONTINUE, TRY, THROW, RETURN, YIELD, PRINT);
	DEF8(ASSURE, ASSERT, ERR, EXPR, LETEXPR, FUNCCALL, CALL, CALL1);
	DEF8(BOX, OPR, NEW, TCAST, AND, OR, ALT, TRI);
	DEF4(SEND, W1, FMTCALL, EMITCODE);
	DEF1(INIT);
};
static struct knh_CompilerAPI_t COMPILER_API = {};

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_LoaderAPI_t *kapi)
{
	RETURN_PKGINFO("compiler-0.1");
}

static void kook_BLOCK_asm(CTX ctx, kStmtExpr *stmt)
{
	CALL(ctx, COMPILER_API.BLOCK, 1, stmt);
}

static void kook_LET_asm(CTX ctx, kStmtExpr *stmt)
{
	kTerm *tkL = tkNN(stmt, 1);
	kTerm *tkV = tkNN(stmt, 2);
	kTerm *tk3 = KNH_TNULL(Term);
	if (IS_Term(tkV)) {
		tk3 = tkV;
	}
	CALL(ctx, COMPILER_API.LET, 4, stmt, tkL, tkV, tk3);
}

static void kook_IF_asm(CTX ctx, kStmtExpr *stmt)
{
	kStmtExpr *stmt0 = stmtNN(stmt, 0);
	kStmtExpr *stmt1 = stmtNN(stmt, 1);
	kStmtExpr *stmt2 = stmtNN(stmt, 2);
	CALL(ctx, COMPILER_API.IF, 4, stmt, stmt0, stmt1, stmt2);
}

static void kook_SWITCH_asm(CTX ctx, kStmtExpr *stmt)
{
	kStmtExpr *stmt0 = stmtNN(stmt, 0);
	kStmtExpr *stmt1 = stmtNN(stmt, 1);
	CALL(ctx, COMPILER_API.SWITCH, 3, stmt, stmt0, stmt1);
}

static void kook_WHILE_asm(CTX ctx, kStmtExpr *stmt)
{
	kStmtExpr *stmt0 = stmtNN(stmt, 0);
	kStmtExpr *stmt1 = stmtNN(stmt, 1);
	CALL(ctx, COMPILER_API.WHILE, 3, stmt, stmt0, stmt1);
}

static void kook_DO_asm(CTX ctx, kStmtExpr *stmt)
{
	kStmtExpr *stmt0 = stmtNN(stmt, 0);
	kStmtExpr *stmt1 = stmtNN(stmt, 1);
	CALL(ctx, COMPILER_API.DO, 3, stmt, stmt1, stmt0);
}

static void kook_FOR_asm(CTX ctx, kStmtExpr *stmt)
{
	kStmtExpr *stmt0 = stmtNN(stmt, 0);
	kStmtExpr *stmt1 = stmtNN(stmt, 1);
	kStmtExpr *stmt2 = stmtNN(stmt, 2);
	kStmtExpr *stmt3 = stmtNN(stmt, 3);
	CALL(ctx, COMPILER_API.FOR, 5, stmt, stmt0, stmt1, stmt2, stmt3);
}

static void kook_FOREACH_asm(CTX ctx, kStmtExpr *stmt)
{
	kTerm *tkVar = tkNN(stmt, 0);
	kStmtExpr *stmt1 = stmtNN(stmt, 1);
	kStmtExpr *stmt2 = stmtNN(stmt, 2);
	kStmtExpr *stmt3 = stmtNN(stmt, 3);
	CALL(ctx, COMPILER_API.FOREACH, 5, stmt, tkVar, stmt1, stmt2, stmt3);
}

static void kook_BREAK_asm(CTX ctx, kStmtExpr *stmt)
{
	kStmtExpr *stmt0 = stmtNN(stmt, 0);
	CALL(ctx, COMPILER_API.BREAK, 2, stmt, stmt0);
}

static void kook_CONTINUE_asm(CTX ctx, kStmtExpr *stmt)
{
	kStmtExpr *stmt0 = stmtNN(stmt, 0);
	CALL(ctx, COMPILER_API.CONTINUE, 2, stmt, stmt0);
}

static void kook_TRY_asm(CTX ctx, kStmtExpr *stmt)
{
	kStmtExpr *stmt0 = stmtNN(stmt, 0);
	kStmtExpr *stmt1 = stmtNN(stmt, 1);
	kStmtExpr *stmt2 = stmtNN(stmt, 2);
	CALL(ctx, COMPILER_API.TRY, 4, stmt, stmt0, stmt1, stmt2);
}

static void kook_THROW_asm(CTX ctx, kStmtExpr *stmt)
{
	kStmtExpr *stmt0 = stmtNN(stmt, 0);
	CALL(ctx, COMPILER_API.THROW, 2, stmt, stmt0);
}

static void kook_RETURN_asm(CTX ctx, kStmtExpr *stmt)
{
	kStmtExpr *stmt0 = NULL;
	kStmtExpr *stmtPOST = NULL;
	if (DP(stmt)->size == 1) {
		stmt0 = stmtNN(stmt, 0);
	} else {
		stmt0 = KNH_TNULL(StmtExpr);
	}
	if (IS_StmtExpr(DP(stmt)->stmtPOST)) {
		DP(DP(stmt)->stmtPOST)->espidx = DP(stmt)->espidx + 1;
		stmtPOST = DP(stmt)->stmtPOST;
	} else {
		stmtPOST = KNH_TNULL(StmtExpr);
	}
	CALL(ctx, COMPILER_API.RETURN, 3, stmt, stmt0, stmtPOST);
}

static void kook_YIELD_asm(CTX ctx, kStmtExpr *stmt)
{
	KNH_TODO("");
}

#define KFLAG_PF_BOL         (1<<1)
#define KFLAG_PF_TIME        (1<<2)
#define KFLAG_PF_NAME        (1<<3)
#define KFLAG_PF_EOL         (1<<4)
#define KFLAG_PF_NCOMMA      (1<<5)
#define KFLAG_PF_LINE        (1<<6)
#define KFLAG_PF_BREAK       (1<<7)
static kflag_t PRINT_flag(CTX ctx, kStmtExpr *o)
{
	kflag_t flag = 0;
	if(IS_Map(DP(o)->metaDictCaseMap)) {
		Object *v = knh_DictMap_getNULL(ctx,  DP(o)->metaDictCaseMap, STEXT("Time"));
		if(v != NULL) {
			flag |= KFLAG_PF_TIME;
		}
	}
	return flag;
}

static void kook_PRINT_asm(CTX ctx, kStmtExpr *stmt)
{
	kflag_t flag = PRINT_flag(ctx, stmt) | KFLAG_PF_BOL | KFLAG_PF_LINE;
	CALL(ctx, COMPILER_API.PRINT, 2, stmt, NN(flag));
}

static void kook_ASSURE_asm(CTX ctx, kStmtExpr *stmt)
{
	kStmtExpr *stmt0 = stmtNN(stmt, 0);
	kStmtExpr *stmt1 = stmtNN(stmt, 1);
	CALL(ctx, COMPILER_API.ASSURE, 3, stmt, stmt0, stmt1);
}

static void kook_ASSERT_asm(CTX ctx, kStmtExpr *stmt)
{
	kStmtExpr *stmt0 = stmtNN(stmt, 0);
	CALL(ctx, COMPILER_API.ASSERT, 2, stmt, stmt0);
}

static void kook_ERR_asm(CTX ctx, kStmtExpr *stmt)
{
	kTerm *tkErr = tkNN(stmt, 0);
	CALL(ctx, COMPILER_API.ERR, 2, stmt, tkErr);
}

static void kook_LETEXPR_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kTerm *tk = tkNN(stmt, 1);
	kStmtExpr *expr = stmtNN(stmt, 2);
	CALL(ctx, COMPILER_API.LETEXPR, 4, stmt, NN(espidx), tk, expr);
}

static void kook_FUNCCALL_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kMethod *mtd = (tkNN(stmt, 0))->mtd;
	kclass_t cid = Tn_cid(stmt, 1);
	kClass *funcclass = new_Type(ctx, cid);
	ktype_t rtype = funcclass->cTBL->p1;
	kClass *rc = new_Type(ctx, rtype);
	kbool_t flag = Stmt_isDYNCALL(stmt);
	kClass *c = new_Type(ctx, cid);
	CALL(ctx, COMPILER_API.FUNCCALL, 6, stmt, NN(espidx), mtd, c, rc, NN(flag));
}

static void kook_CALL_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kTerm *tkMTD = tkNN(stmt, 0);
	kMethod *mtd = tkMTD->mtd;
	kclass_t cid = Tn_cid(stmt, 1);
	//kStmtExpr *stmt0 = stmtNN(stmt, 2);
	kClass *c = new_Type(ctx, cid);
	CALL(ctx, COMPILER_API.CALL, 5, stmt, NN(espidx), tkMTD, mtd, c);
}

static void kook_CALL1_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kStmtExpr *expr1 = stmtNN(stmt, 0);
	kStmtExpr *stmtPost = DP(stmt)->stmtPOST;
	CALL(ctx, COMPILER_API.CALL1, 4, stmt, NN(espidx), expr1, stmtPost);
}

static void kook_BOX_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kclass_t cid = Tn_cid(stmt, 0);
	kStmtExpr *expr = stmtNN(stmt, 0);
	kClass *c = new_Type(ctx, cid);
	CALL(ctx, COMPILER_API.BOX, 4, stmt, NN(espidx), c, expr);
}

static void kook_OPR_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kMethod *mtd = tkNN(stmt, 0)->mtd;
	kclass_t cid = Tn_cid(stmt, 1);
	kStmtExpr *lhs = stmtNN(stmt, 1);
	kStmtExpr *rhs = stmtNN(stmt, 2);
	kClass *c = new_Type(ctx, cid);
	kStmtExpr *_rhs = (rhs != NULL ? rhs : KNH_TNULL(StmtExpr));
	CALL(ctx, COMPILER_API.OPR, 6, stmt, NN(espidx), mtd, c, lhs, _rhs);
}

static void kook_NEW_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kMethod *mtd = tkNN(stmt, 0)->mtd;
	kclass_t cid = (tkNN(stmt, 1))->cid;
	kClass *c = new_Type(ctx, cid);
	CALL(ctx, COMPILER_API.NEW, 4, stmt, NN(espidx), c, mtd);
}

static void kook_TCAST_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kTypeMap *tmr = tkNN(stmt, 0)->mpr;
	kStmtExpr *expr = stmtNN(stmt, 1);
	kint_t fptr = (kint_t)knh_TypeMap_exec;
	CALL(ctx, COMPILER_API.TCAST, 5, stmt, NN(espidx), tmr, expr, NN(fptr));
}

static void kook_AND_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	CALL(ctx, COMPILER_API.AND, 2, stmt, NN(espidx));
}

static void kook_OR_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	CALL(ctx, COMPILER_API.OR, 2, stmt, NN(espidx));
}

static void kook_ALT_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
}

static void kook_TRI_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kStmtExpr *stmt1 = stmtNN(stmt, 0);
	kStmtExpr *stmt2 = stmtNN(stmt, 1);
	kStmtExpr *stmt3 = stmtNN(stmt, 2);
	CALL(ctx, COMPILER_API.TRI, 5, stmt, NN(espidx), stmt1, stmt2, stmt3);
}

static void kook_SEND_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	CALL(ctx, COMPILER_API.SEND, 2, stmt, NN(espidx));
}

static void kook_W1_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kMethod *mtd = tkNN(stmt, 0)->mtd;
	kTerm *streamTk = tkNN(stmt, 1);
	kStmtExpr *expr = stmtNN(stmt, 2);
	CALL(ctx, COMPILER_API.W1, 5, stmt, NN(espidx), mtd, streamTk, expr);
}

static void kook_FMTCALL_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	kMethod *mtd = tkNN(stmt, 0)->mtd;
	kTerm *streamTk = tkNN(stmt, 1);
	kStmtExpr *expr = stmtNN(stmt, 2);
	CALL(ctx, COMPILER_API.W1, 5, stmt, NN(espidx), mtd, streamTk, expr);
}

#define STT_LETEXPR  STT_LET
#define CASE_ASM(XX, ...) case STT_##XX : { \
	kook_##XX##_asm(ctx, stmt, ## __VA_ARGS__); \
	break;\
}

static void kook_EXPR_asm(CTX ctx, kStmtExpr *stmt, int espidx)
{
	switch(STT_(stmt)) {
		CASE_ASM(LETEXPR, espidx);
		CASE_ASM(FUNCCALL, espidx);
		CASE_ASM(CALL, espidx);
		CASE_ASM(CALL1, espidx);
		CASE_ASM(BOX, espidx);
		CASE_ASM(OPR, espidx);
		CASE_ASM(NEW, espidx);
		CASE_ASM(TCAST, espidx);
		CASE_ASM(AND, espidx);
		CASE_ASM(OR, espidx);
		CASE_ASM(ALT, espidx);
		CASE_ASM(TRI, espidx);
		CASE_ASM(SEND, espidx);
		CASE_ASM(W1, espidx);
		CASE_ASM(FMTCALL, espidx);
		default:
		DBG_ABORT("unknown stt=%d", STT_(stmt));
	}
}
KMETHOD Compiler_getMnName(CTX ctx, ksfp_t *sfp _RIX) {
	kint_t mn = Int_to(kint_t, sfp[1]);
	RETURN_(new_String(ctx, MN__(mn)));
}
KMETHOD Compiler_asmCALL2(CTX ctx, ksfp_t *sfp _RIX) {
	kStmtExpr *stmt = CAST(kStmtExpr*, sfp[1].o);
	kint_t espidx = Int_to(kint_t, sfp[2]);
	kTerm *tkMTD = tkNN(stmt, 0);
	kMethod *mtd = tkMTD->mtd;
	kclass_t cid = Tn_cid(stmt, 1);
	//kStmtExpr *stmt0 = stmtNN(stmt, 2);
	kClass *c = new_Type(ctx, cid);
	CALL(ctx, COMPILER_API.CALL, 5, stmt, NN(espidx), tkMTD, mtd, c);
}
KMETHOD Compiler_gammaHasFIELD(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNb_(GammaBuilder_hasFIELD(ctx->gma));
}
KMETHOD Compiler_gammaFvarsize(CTX ctx, ksfp_t *sfp _RIX)
{
    RETURNi_(DP(ctx->gma)->fvarsize);
}
KMETHOD Compiler_gammaGfFn(CTX ctx, ksfp_t *sfp _RIX)
{
    kint_t i = Int_to(kint_t, sfp[1]);
    RETURNi_(DP(ctx->gma)->gf[i].fn);
}
KMETHOD Compiler_gammaGfType(CTX ctx, ksfp_t *sfp _RIX)
{
    kint_t i = Int_to(kint_t, sfp[1]);
    ktype_t type = DP(ctx->gma)->gf[i].type;
    RETURN_(new_Type(ctx, type));
}
KMETHOD Compiler_gammaGetThiscid(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURN_(new_Type(ctx, DP(ctx->gma)->this_cid));
}
static KMETHOD Fmethod_empty(CTX ctx, ksfp_t *sfp _RIX) {}
static kMethod* Gamma_getFmt(CTX ctx, kclass_t cid, kmethodn_t mn0)
{
	kmethodn_t mn = mn0;
	kNameSpace *ns = K_GMANS;
	kMethod *mtd = knh_NameSpace_getFmtNULL(ctx, ns, cid, mn);
	if(mtd == NULL) {
		WarningUndefinedFmt(ctx, cid, mn0);
		mtd = new_Method(ctx, 0, cid, mn0, Fmethod_empty);
		KNH_SETv(ctx, DP(mtd)->mp, KNH_TNULL(Param));
		knh_NameSpace_addFmt(ctx, ns, mtd);
	}
	return mtd;
}
KMETHOD Compiler_getSendMethod(CTX ctx, ksfp_t *sfp _RIX)
{
	kStmtExpr *stmt = (kStmtExpr*)sfp[1].o;
	kint_t idx = Int_to(kint_t, sfp[2]);
	kclass_t cid = Tn_cid(stmt, idx);
	if (cid == CLASS_String) {
		RETURN_(knh_NameSpace_getMethodNULL(ctx, K_GMANS, TYPE_OutputStream, MN_send));
	} else {
		RETURN_(Gamma_getFmt(ctx, cid, MN__s));
	}
}
//KMETHOD Compiler_createSafePointMtd(CTX ctx, ksfp_t *sfp _RIX)
//{
//	RETURNi_((kint_t)knh_checkSafePoint);
//}
KMETHOD Compiler_asmEXPR(CTX ctx, ksfp_t *sfp _RIX)
{
	//kObject *o  = sfp[0].o;
	kStmtExpr *stmt = CAST(kStmtExpr*, sfp[1].o);
	int espidx = sfp[2].ivalue;
	kook_EXPR_asm(ctx, stmt, espidx);
	RETURNvoid_();
}

KMETHOD Compiler_asmBLOCK(CTX ctx, ksfp_t *sfp _RIX)
{
	//kObject *o  = sfp[0].o;
	kStmtExpr *stmtH = CAST(kStmtExpr*, sfp[1].o);
	kStmtExpr *stmt = stmtH;
	while(stmt != NULL) {
		ctx->gma->uline = stmt->uline;
		switch(STT_(stmt)) {
			case STT_REGISTER:
				KNH_TODO("no support register stmt");
				break;
			case STT_BLOCK :
				kook_BLOCK_asm(ctx, stmtNN(stmt, 0));
				break;
				CASE_ASM(LET);
				CASE_ASM(IF);
				CASE_ASM(SWITCH);
				CASE_ASM(WHILE);
				CASE_ASM(DO);
				CASE_ASM(FOR);
				CASE_ASM(FOREACH);
				CASE_ASM(BREAK);
				CASE_ASM(CONTINUE);
				CASE_ASM(TRY);
				CASE_ASM(THROW);
				CASE_ASM(RETURN);
				CASE_ASM(YIELD);
				CASE_ASM(PRINT);
				CASE_ASM(ASSURE);
				CASE_ASM(ASSERT);
				CASE_ASM(ERR);
			case STT_DECL: case STT_DONE: break;
			default:
				kook_EXPR_asm(ctx, stmt, DP(stmt)->espidx);
		}
		stmt = DP(stmt)->nextNULL;
	}
	RETURNvoid_();
}

//## @Native Compiler.getCurrentUline();
KMETHOD Compiler_getCurrentUline(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNi_(ctx->gma->uline);
}

KMETHOD Compiler_debug(CTX ctx, ksfp_t *sfp _RIX)
{
	asm volatile("int3");
}
KMETHOD _debug_(CTX ctx, ksfp_t *sfp, kint_t a, kint_t b)
{
	asm volatile("int3");
	//void *p1 = (void*) a;
	//void *p2 = (void*) b;
	//fprintf(stderr, "%p %p %ld %ld %p %p\n", ctx, sfp, a, b, p1, p2);
}
void __test__(void *a, void *b)
{
	fprintf(stderr, "%p %p\n", a, b);
	asm volatile("int3");
}
static void kook_compiler_emit(CTX ctx, kMethod *mtd)
{
	CALL(ctx, COMPILER_API.EMITCODE, 1, mtd);
}

static void kook_compiler_compiler(CTX ctx, kMethod *mtd, kStmtExpr *stmtB)
{
	//KNH_P("hello world");
	CALL(ctx, COMPILER_API.INIT, 1, mtd);
	kook_BLOCK_asm(ctx, stmtB);
	kook_compiler_emit(ctx, mtd);
}
/* copied from src/lang/asm.c */
void compiler_CWB(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct)
{
	CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
	KNH_SETv(ctx, sfp[c].o, cwb->w);
	sfp[c].ivalue = cwb->pos;
}
/* copied from src/lang/asm.c */
void compiler_TOSTR(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct)
{
	DBG_ASSERT(IS_OutputStream(sfp[0].w));
	CWB_t cwbbuf = {ctx->bufa, ctx->bufw, (size_t)(sfp[0].ivalue)};
	kString *s = CWB_newString(ctx, &cwbbuf, 0);
	KNH_SETv(ctx, sfp[c].o, s);
}
/* copied from src/lang/asm.c */
void compiler_NULVAL(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct)
{
	KNH_SETv(ctx, sfp[c].o, ct->fdefnull(ctx, ct->cid));
}

kMethod *compiler_LOOKUPMTD(CTX ctx, kObject *o, knh_mtdcache_t *cache)
{
	const knh_ClassTBL_t *ct = O_cTBL(o);
	kMethod *mtd = cache->mtd;
	if(cache->cid != ct->cid) {
		mtd = ClassTBL_getMethod(ctx, ct, cache->mn);
		cache->mtd = mtd;
		cache->cid = ct->cid;
	}
	return mtd;
}

KMETHOD Method_lazycompile(CTX ctx, ksfp_t *sfp _RIX) {
    kMethod *mtd = sfp[-1].mtdNC;
    assert(IS_Method(mtd));
    asm volatile("int3");
    CWB_t cwbbuf, *cwb = CWB_open(ctx, &cwbbuf);
    knh_write_cid(ctx, cwb->w, (mtd)->cid);
    knh_putc(ctx, cwb->w, '.');
    knh_write_mn(ctx, cwb->w, (mtd)->mn);
    fprintf(stderr, "%s\n", CWB_tobytes(cwb).utext);
    CWB_close(ctx, cwb);
    RETURNvoid_();
}

KMETHOD Method_setLazycompile(CTX ctx, ksfp_t *sfp _RIX) {
    kMethod *mtd = sfp[0].mtd;
    assert(IS_Method(mtd));
    assert(Method_isAbstract(mtd));
    knh_Method_setFunc(ctx, mtd, Method_lazycompile);
    RETURNvoid_();
}

static kMethod *load_method(CTX ctx, kclass_t cid, kbytes_t t)
{
	kmethodn_t mn = knh_getmn(ctx, t, MN_NONAME);
	kMethod *mtd = knh_NameSpace_getMethodNULL(ctx, NULL, cid, mn);
	assert(mtd != NULL);
	return mtd;
}

#define LOADMTD(ctx, cid, name) load_method(ctx, cid, STEXT(name))
DEFAPI(void) reset_compiler_api(CTX ctx)
{
	kclass_t cid = knh_getcid(ctx, B("konoha.compiler.Compiler"));
	struct knh_CompilerAPI_t *api = &COMPILER_API;
	kMethod *newmtd = LOADMTD(ctx, cid, "new");
	api->Instance = new_Object_init2(ctx, ClassTBL(cid));
	api->ASM      = LOADMTD(ctx, cid, "asm");
	api->BLOCK    = LOADMTD(ctx, cid, "asmBLOCK");
	api->LET      = LOADMTD(ctx, cid, "asmLET");
	api->IF       = LOADMTD(ctx, cid, "asmIF");
	api->SWITCH   = LOADMTD(ctx, cid, "asmSWITCH");
	api->WHILE    = LOADMTD(ctx, cid, "asmWHILE");
	api->DO       = LOADMTD(ctx, cid, "asmDO");
	api->FOR      = LOADMTD(ctx, cid, "asmFOR");
	api->FOREACH  = LOADMTD(ctx, cid, "asmFOREACH");
	api->BREAK    = LOADMTD(ctx, cid, "asmBREAK");
	api->CONTINUE = LOADMTD(ctx, cid, "asmCONTINUE");
	api->TRY      = LOADMTD(ctx, cid, "asmTRY");
	api->THROW    = LOADMTD(ctx, cid, "asmTHROW");
	api->RETURN   = LOADMTD(ctx, cid, "asmRETURN");
	api->YIELD    = LOADMTD(ctx, cid, "asmYIELD");
	api->PRINT    = LOADMTD(ctx, cid, "asmPRINT");
	api->ASSURE   = LOADMTD(ctx, cid, "asmASSURE");
	api->ASSERT   = LOADMTD(ctx, cid, "asmASSERT");
	api->ERR      = LOADMTD(ctx, cid, "asmERR");
	api->EXPR     = LOADMTD(ctx, cid, "asmEXPR");
	api->LETEXPR  = LOADMTD(ctx, cid, "asmLETEXPR");
	api->FUNCCALL = LOADMTD(ctx, cid, "asmFUNCCALL");
	api->CALL     = LOADMTD(ctx, cid, "asmCALL");
	api->CALL1    = LOADMTD(ctx, cid, "asmCALL1");
	api->BOX      = LOADMTD(ctx, cid, "asmBOX");
	api->OPR      = LOADMTD(ctx, cid, "asmOPR");
	api->NEW      = LOADMTD(ctx, cid, "asmNEW");
	api->TCAST    = LOADMTD(ctx, cid, "asmTCAST");
	api->AND      = LOADMTD(ctx, cid, "asmAND");
	api->OR       = LOADMTD(ctx, cid, "asmOR");
	api->ALT      = LOADMTD(ctx, cid, "asmALT");
	api->TRI      = LOADMTD(ctx, cid, "asmTRI");
	api->SEND     = LOADMTD(ctx, cid, "asmSEND");
	api->W1       = LOADMTD(ctx, cid, "asmW1");
	api->FMTCALL  = LOADMTD(ctx, cid, "asmFMTCALL");
	api->EMITCODE = LOADMTD(ctx, cid, "emit");
	api->INIT     = LOADMTD(ctx, cid, "init");
	KNH_SETv(ctx, ctx->wshare->konoha_compiler, api->Instance);
	CALL(ctx, newmtd, 0);
}

DEFAPI(void) complete(CTX ctx)
{
	ctx->wshare->compilerAPI = (void *) kook_compiler_compiler;
	reset_compiler_api(ctx);
}

