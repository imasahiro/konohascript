/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2011 Masahiro Ide <imasahiro9 at gmail.com>
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
#define stmtNN(stmt, n)      (stmt)->stmts[(n)]
#define STT_(stmt)   SP(stmt)->stt
#define TT_(tk)   SP(tk)->tt

#define SET0(n, o0)                     KNH_SETv(ctx, lsfp[n].o, o0)
#define SET1(n, o0, o1)                 SET0(n, o0);                SET0(n+1, o1)
#define SET2(n, o0, o1, o2)             SET1(n, o0, o1);            SET0(n+2, o2)
#define SET3(n, o0, o1, o2, o3)         SET2(n, o0, o1, o2);        SET0(n+3, o3)
#define SET4(n, o0, o1, o2, o3, o4)     SET3(n, o0, o1, o2, o3);    SET0(n+4, o4)
#define SET5(n, o0, o1, o2, o3, o4, o5) SET4(n, o0, o1, o2, o3, o4);SET0(n+5, o5)

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
    CALL(ctx, COMPILER_API.LET, 3, stmt, tkL, tkV);
}

static void kook_IF_asm(CTX ctx, knh_Stmt_t *stmt)
{
    knh_Stmt_t *stmt0 = stmtNN(stmt, 1);
    knh_Stmt_t *stmt1 = stmtNN(stmt, 2);
    knh_Stmt_t *stmt2 = stmtNN(stmt, 2);
    CALL(ctx, COMPILER_API.IF, 4, stmt, stmt0, stmt1, stmt2);
}

static void kook_SWITCH_asm(CTX ctx, knh_Stmt_t *stmt)
{
    KNH_TODO("");
}

static void kook_WHILE_asm(CTX ctx, knh_Stmt_t *stmt)
{
    KNH_TODO("");
}

static void kook_DO_asm(CTX ctx, knh_Stmt_t *stmt)
{
    KNH_TODO("");
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
}

static void kook_BREAK_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void kook_CONTINUE_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void kook_TRY_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void kook_THROW_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void kook_RETURN_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void kook_YIELD_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void kook_PRINT_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void kook_ASSURE_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void kook_ASSERT_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void kook_ERR_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void kook_LETEXPR_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void kook_FUNCCALL_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void kook_CALL_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void kook_CALL1_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void kook_BOX_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void kook_OPR_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void kook_NEW_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void kook_TCAST_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void kook_AND_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void kook_OR_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void kook_ALT_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void kook_TRI_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void kook_SEND_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void kook_W1_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void kook_FMTCALL_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

#define STT_LETEXPR  STT_LET
#define CASE_ASM(XX, ...) case STT_##XX : do { \
    kook_##XX##_asm(ctx, stmt, ## __VA_ARGS__); \
    break;\
} while(0)

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

static void kook_compiler_emit(CTX ctx, knh_Method_t *mtd)
{
    CALL(ctx, COMPILER_API.EMITCODE, 1, mtd);
}

static void kook_compiler_compiler(CTX ctx, knh_Method_t *mtd, knh_Stmt_t *stmtB)
{
    KNH_P("hello world");
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
    ctx->wshare->konoha_compiler = api->Instance;
    ctx->wshare->compilerAPI = (void *) kook_compiler_compiler;
    CALL(ctx, newmtd, 0);
}

