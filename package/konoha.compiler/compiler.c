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
    knh_Object_t *Instance;
#define DEF1(a) knh_Method_t *a
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

static void kook_BLOCK_asm(CTX ctx, knh_Stmt_t *stmt)
{
    CALL(ctx, COMPILER_API.BLOCK, 1, stmt);
}

static void kook_LET_asm(CTX ctx, knh_Stmt_t *stmt)
{
    knh_Token_t *tkL = tkNN(stmt, 1);
    knh_Token_t *tkV = tkNN(stmt, 2);
    knh_Token_t *tk3 = KNH_TNULL(Token);
    if (IS_Token(tkV)) {
        tk3 = tkV;
    }
    CALL(ctx, COMPILER_API.LET, 4, stmt, tkL, tkV, tk3);
}

static void kook_IF_asm(CTX ctx, knh_Stmt_t *stmt)
{
    knh_Stmt_t *stmt0 = stmtNN(stmt, 0);
    knh_Stmt_t *stmt1 = stmtNN(stmt, 1);
    knh_Stmt_t *stmt2 = stmtNN(stmt, 2);
    CALL(ctx, COMPILER_API.IF, 4, stmt, stmt0, stmt1, stmt2);
}

static void kook_SWITCH_asm(CTX ctx, knh_Stmt_t *stmt)
{
    knh_Stmt_t *stmt0 = stmtNN(stmt, 0);
    knh_Stmt_t *stmt1 = stmtNN(stmt, 1);
    CALL(ctx, COMPILER_API.SWITCH, 3, stmt, stmt0, stmt1);
}

static void kook_WHILE_asm(CTX ctx, knh_Stmt_t *stmt)
{
    knh_Stmt_t *stmt0 = stmtNN(stmt, 0);
    knh_Stmt_t *stmt1 = stmtNN(stmt, 1);
    CALL(ctx, COMPILER_API.WHILE, 3, stmt, stmt0, stmt1);
}

static void kook_DO_asm(CTX ctx, knh_Stmt_t *stmt)
{
    knh_Stmt_t *stmt0 = stmtNN(stmt, 0);
    knh_Stmt_t *stmt1 = stmtNN(stmt, 1);
    CALL(ctx, COMPILER_API.DO, 3, stmt, stmt1, stmt0);
}

static void kook_FOR_asm(CTX ctx, knh_Stmt_t *stmt)
{
    knh_Stmt_t *stmt0 = stmtNN(stmt, 0);
    knh_Stmt_t *stmt1 = stmtNN(stmt, 1);
    knh_Stmt_t *stmt2 = stmtNN(stmt, 2);
    knh_Stmt_t *stmt3 = stmtNN(stmt, 3);
    CALL(ctx, COMPILER_API.FOR, 5, stmt, stmt0, stmt1, stmt2, stmt3);
}

static void kook_FOREACH_asm(CTX ctx, knh_Stmt_t *stmt)
{
    knh_Token_t *tkVar = tkNN(stmt, 0);
    knh_Stmt_t *stmt1 = stmtNN(stmt, 1);
    knh_Stmt_t *stmt2 = stmtNN(stmt, 2);
    knh_Stmt_t *stmt3 = stmtNN(stmt, 3);
    CALL(ctx, COMPILER_API.FOREACH, 5, stmt, tkVar, stmt1, stmt2, stmt3);
}

static void kook_BREAK_asm(CTX ctx, knh_Stmt_t *stmt)
{
    knh_Stmt_t *stmt0 = stmtNN(stmt, 0);
    CALL(ctx, COMPILER_API.BREAK, 2, stmt, stmt0);
}

static void kook_CONTINUE_asm(CTX ctx, knh_Stmt_t *stmt)
{
    knh_Stmt_t *stmt0 = stmtNN(stmt, 0);
    CALL(ctx, COMPILER_API.CONTINUE, 2, stmt, stmt0);
}

static void kook_TRY_asm(CTX ctx, knh_Stmt_t *stmt)
{
    knh_Stmt_t *stmt0 = stmtNN(stmt, 0);
    knh_Stmt_t *stmt1 = stmtNN(stmt, 1);
    knh_Stmt_t *stmt2 = stmtNN(stmt, 2);
    CALL(ctx, COMPILER_API.TRY, 4, stmt, stmt0, stmt1, stmt2);
}

static void kook_THROW_asm(CTX ctx, knh_Stmt_t *stmt)
{
    knh_Stmt_t *stmt0 = stmtNN(stmt, 0);
    CALL(ctx, COMPILER_API.THROW, 2, stmt, stmt0);
}

static void kook_RETURN_asm(CTX ctx, knh_Stmt_t *stmt)
{
	knh_Stmt_t *stmt0 = NULL;
	if (DP(stmt)->size > 0) {
		stmt0 = stmtNN(stmt, 0);
	} else {
		stmt0 = KNH_TNULL(Stmt);
	}
	CALL(ctx, COMPILER_API.RETURN, 2, stmt, stmt0);
}

static void kook_YIELD_asm(CTX ctx, knh_Stmt_t *stmt)
{
	KNH_TODO("");
}

static void kook_PRINT_asm(CTX ctx, knh_Stmt_t *stmt)
{
    KNH_TODO("");
}

static void kook_ASSURE_asm(CTX ctx, knh_Stmt_t *stmt)
{
    knh_Stmt_t *stmt0 = stmtNN(stmt, 0);
    knh_Stmt_t *stmt1 = stmtNN(stmt, 1);
    CALL(ctx, COMPILER_API.ASSURE, 3, stmt, stmt0, stmt1);
}

static void kook_ASSERT_asm(CTX ctx, knh_Stmt_t *stmt)
{
    knh_Stmt_t *stmt0 = stmtNN(stmt, 0);
    CALL(ctx, COMPILER_API.ASSERT, 2, stmt, stmt0);
}

static void kook_ERR_asm(CTX ctx, knh_Stmt_t *stmt)
{
    knh_Token_t *tkErr = tkNN(stmt, 0);
    CALL(ctx, COMPILER_API.ERR, 2, stmt, tkErr);
}

static void kook_LETEXPR_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
    knh_Token_t *tk = tkNN(stmt, 0);
    CALL(ctx, COMPILER_API.LETEXPR, 3, stmt, NN(espidx), tk);
}

static void kook_FUNCCALL_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
    knh_Method_t *mtd = tkNN(stmt, 0)->mtd;
    knh_class_t cid = Tn_cid(stmt, 1);
    knh_bool_t flag = Stmt_isDYNCALL(stmt);
    knh_Class_t *c = new_Type(ctx, cid);
    CALL(ctx, COMPILER_API.FUNCCALL, 5, stmt, NN(espidx), mtd, c, NN(flag));
}

static void kook_CALL_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
    knh_Token_t *tkMTD = tkNN(stmt, 0);
    knh_Method_t *mtd = tkMTD->mtd;
    knh_class_t cid = Tn_cid(stmt, 1);
    //knh_Stmt_t *stmt0 = stmtNN(stmt, 2);
    knh_Class_t *c = new_Type(ctx, cid);
    CALL(ctx, COMPILER_API.CALL, 5, stmt, NN(espidx), tkMTD, mtd, c);
}

static void kook_CALL1_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
    knh_Stmt_t *expr1 = stmtNN(stmt, 0);
    knh_Stmt_t *stmtPost = DP(stmt)->stmtPOST;
    CALL(ctx, COMPILER_API.CALL1, 4, stmt, NN(espidx), expr1, stmtPost);
}

static void kook_BOX_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
    knh_class_t cid = Tn_cid(stmt, 0);
    knh_Stmt_t *expr = stmtNN(stmt, 0);
    knh_Class_t *c = new_Type(ctx, cid);
    CALL(ctx, COMPILER_API.BOX, 4, stmt, NN(espidx), c, expr);
}

static void kook_OPR_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
    knh_Method_t *mtd = tkNN(stmt, 0)->mtd;
    knh_class_t cid = Tn_cid(stmt, 1);
    knh_Stmt_t *lhs = stmtNN(stmt, 1);
    knh_Stmt_t *rhs = stmtNN(stmt, 2);
    knh_Class_t *c = new_Type(ctx, cid);
    knh_Stmt_t *_rhs = (rhs != NULL ? rhs : KNH_TNULL(Stmt));
    CALL(ctx, COMPILER_API.OPR, 6, stmt, NN(espidx), mtd, c, lhs, _rhs);
}

static void kook_NEW_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
    knh_Method_t *mtd = tkNN(stmt, 0)->mtd;
    knh_class_t cid = (tkNN(stmt, 1))->cid;
    knh_Class_t *c = new_Type(ctx, cid);
    CALL(ctx, COMPILER_API.NEW, 4, stmt, NN(espidx), c, mtd);
}

static void kook_TCAST_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
    knh_TypeMap_t *tmr = tkNN(stmt, 0)->mpr;
    knh_Stmt_t *expr = stmtNN(stmt, 1);
    knh_int_t fptr = (knh_int_t)knh_TypeMap_exec;
    CALL(ctx, COMPILER_API.TCAST, 5, stmt, NN(espidx), tmr, expr, NN(fptr));
}

static void kook_AND_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
    CALL(ctx, COMPILER_API.AND, 2, stmt, NN(espidx));
}

static void kook_OR_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
    CALL(ctx, COMPILER_API.OR, 2, stmt, NN(espidx));
}

static void kook_ALT_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void kook_TRI_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
    knh_Stmt_t *stmt1 = stmtNN(stmt, 0);
    knh_Stmt_t *stmt2 = stmtNN(stmt, 1);
    knh_Stmt_t *stmt3 = stmtNN(stmt, 2);
    CALL(ctx, COMPILER_API.TRI, 5, stmt, NN(espidx), stmt1, stmt2, stmt3);
}

static void kook_SEND_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
    CALL(ctx, COMPILER_API.SEND, 2, stmt, NN(espidx));
}

static void kook_W1_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
    knh_Method_t *mtd = tkNN(stmt, 0)->mtd;
    knh_Token_t *streamTk = tkNN(stmt, 1);
    knh_Stmt_t *expr = stmtNN(stmt, 2);
    CALL(ctx, COMPILER_API.W1, 5, stmt, NN(espidx), mtd, streamTk, expr);
}

static void kook_FMTCALL_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
    knh_Method_t *mtd = tkNN(stmt, 0)->mtd;
    knh_Token_t *streamTk = tkNN(stmt, 1);
    knh_Stmt_t *expr = stmtNN(stmt, 2);
    CALL(ctx, COMPILER_API.W1, 5, stmt, NN(espidx), mtd, streamTk, expr);
}

#define STT_LETEXPR  STT_LET
#define CASE_ASM(XX, ...) case STT_##XX : { \
    kook_##XX##_asm(ctx, stmt, ## __VA_ARGS__); \
    break;\
}

static void kook_EXPR_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
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
KMETHOD Compiler_asmCALL2(CTX ctx, knh_sfp_t *sfp _RIX) {
    knh_Stmt_t *stmt = CAST(knh_Stmt_t*, sfp[1].o);
    knh_int_t espidx = Int_to(knh_int_t, sfp[2]);
    knh_Token_t *tkMTD = tkNN(stmt, 0);
    knh_Method_t *mtd = tkMTD->mtd;
    knh_class_t cid = Tn_cid(stmt, 1);
    //knh_Stmt_t *stmt0 = stmtNN(stmt, 2);
    knh_Class_t *c = new_Type(ctx, cid);
    CALL(ctx, COMPILER_API.CALL, 5, stmt, NN(espidx), tkMTD, mtd, c);
}
KMETHOD Compiler_gammaHasFIELD(CTX ctx, knh_sfp_t *sfp _RIX)
{
    RETURNb_(Gamma_hasFIELD(ctx->gma));
}
KMETHOD Compiler_gammaGetThiscid(CTX ctx, knh_sfp_t *sfp _RIX)
{
    RETURN_(new_Type(ctx, DP(ctx->gma)->this_cid));
}
static KMETHOD Fmethod_empty(CTX ctx, knh_sfp_t *sfp _RIX) {}
static knh_Method_t* Gamma_getFmt(CTX ctx, knh_class_t cid, knh_methodn_t mn0) 
{
    knh_methodn_t mn = mn0; 
    knh_NameSpace_t *ns = K_GMANS;
    knh_Method_t *mtd = knh_NameSpace_getFmtNULL(ctx, ns, cid, mn); 
    if(mtd == NULL) {
        WarningUndefinedFmt(ctx, cid, mn0);
        mtd = new_Method(ctx, 0, cid, mn0, Fmethod_empty);
        KNH_SETv(ctx, DP(mtd)->mp, KNH_TNULL(ParamArray));
        knh_NameSpace_addFmt(ctx, ns, mtd);
    }    
    return mtd; 
}
KMETHOD Compiler_getSendMethod(CTX ctx, knh_sfp_t *sfp _RIX)
{
    knh_Stmt_t *stmt = (knh_Stmt_t*)sfp[1].o;
    knh_int_t idx = Int_to(knh_int_t, sfp[2]);
    knh_class_t cid = Tn_cid(stmt, idx);
    if (cid == CLASS_String) {
        RETURN_(knh_NameSpace_getMethodNULL(ctx, K_GMANS, TYPE_OutputStream, MN_send));
    } else {
        RETURN_(Gamma_getFmt(ctx, cid, MN__s));
    }
}
KMETHOD Compiler_createSafePointMtd(CTX ctx, knh_sfp_t *sfp _RIX)
{
    RETURNi_((knh_int_t)knh_checkSafePoint);
}
KMETHOD Compiler_asmEXPR(CTX ctx, knh_sfp_t *sfp _RIX)
{
    //knh_Object_t *o  = sfp[0].o;
    knh_Stmt_t *stmt = CAST(knh_Stmt_t*, sfp[1].o);
    int espidx = sfp[2].ivalue;
    kook_EXPR_asm(ctx, stmt, espidx);
    RETURNvoid_();
}

KMETHOD Compiler_asmBLOCK(CTX ctx, knh_sfp_t *sfp _RIX)
{
    //knh_Object_t *o  = sfp[0].o;
    knh_Stmt_t *stmtH = CAST(knh_Stmt_t*, sfp[1].o);
    knh_Stmt_t *stmt = stmtH;
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

KMETHOD Compiler_debug(CTX ctx, knh_sfp_t *sfp _RIX)
{
    asm volatile("int3");
}

static void kook_compiler_emit(CTX ctx, knh_Method_t *mtd)
{
    CALL(ctx, COMPILER_API.EMITCODE, 1, mtd);
}

static void kook_compiler_compiler(CTX ctx, knh_Method_t *mtd, knh_Stmt_t *stmtB)
{
    KNH_P("hello world");
    CALL(ctx, COMPILER_API.INIT, 1, mtd);
    kook_BLOCK_asm(ctx, stmtB);
    kook_compiler_emit(ctx, mtd);
}

static knh_Method_t *load_method(CTX ctx, knh_class_t cid, knh_bytes_t t)
{
    knh_methodn_t mn = knh_getmn(ctx, t, MN_NONAME);
    knh_Method_t *mtd = knh_NameSpace_getMethodNULL(ctx, NULL, cid, mn);
    assert(mtd != NULL);
    return mtd;
}

#define LOADMTD(ctx, cid, name) load_method(ctx, cid, STEXT(name))

DEFAPI(void) complete(CTX ctx)
{
    knh_class_t cid = knh_getcid(ctx, B("konoha.compiler.Compiler"));
    struct knh_CompilerAPI_t *api = &COMPILER_API;
    knh_Method_t *newmtd = LOADMTD(ctx, cid, "new");
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
    ctx->wshare->konoha_compiler = api->Instance;
    ctx->wshare->compilerAPI = (void *) kook_compiler_compiler;
    CALL(ctx, newmtd, 0);
}

