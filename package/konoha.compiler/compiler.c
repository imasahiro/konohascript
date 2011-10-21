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
#define CAST(T, O)    ((T) o)
#define WRAP(p) ((void*)p)
#define tkNN(stmt, n)        (stmt)->tokens[(n)]
#define stmtNN(stmt, n)      (stmt)->stmts[(n)]
#define STT_(stmt)   SP(stmt)->stt
#define TT_(tk)   SP(tk)->tt

DEFAPI(const knh_PackageDef_t*) init(CTX ctx, const knh_LoaderAPI_t *kapi)
{
	RETURN_PKGINFO("compiler-0.1");
}

#define CASE_ASM(XX, ...) case STT_##XX : do { \
    XX##_asm(ctx, stmt, ## __VA_ARGS__); \
    break;\
} while(0)

static void BLOCK_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void LET_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void IF_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void SWITCH_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void WHILE_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void DO_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void FOR_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void FOREACH_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void BREAK_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void CONTINUE_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void TRY_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void THROW_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void RETURN_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void YIELD_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void PRINT_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void ASSURE_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void ASSERT_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void ERR_asm(CTX ctx, knh_Stmt_t *stmt)
{
}

static void LETEXPR_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void FUNCCALL_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void CALL_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void CALL1_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void BOX_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void OPR_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void NEW_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void TCAST_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void AND_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void OR_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void ALT_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void TRI_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void SEND_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void W1_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

static void FMTCALL_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
{
}

#define STT_LETEXPR  STT_LET
static void EXPR_asm(CTX ctx, knh_Stmt_t *stmt, int espidx)
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
    knh_Object_t *o  = sfp[0].o;
    knh_Stmt_t *stmtH = CAST(knh_Stmt_t*, sfp[1].o);
    knh_Stmt_t *stmt = stmtH;
    while(stmt != NULL) {
        ctx->gma->uline = stmt->uline;
        switch(STT_(stmt)) {
            case STT_REGISTER:
                KNH_TODO("no support register stmt");
                break;
            case STT_BLOCK :
                BLOCK_asm(ctx, stmtNN(stmt, 0));
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
                EXPR_asm(ctx, stmt, DP(stmt)->espidx);
        }
        stmt = DP(stmt)->nextNULL;
    }
    RETURNvoid_();
}

struct knh_CompilerAPI_t {
    knh_Object_t *Instance;
    knh_Method_t *ASM;
    knh_Method_t *BLOCK;
    knh_Method_t *LET;
    knh_Method_t *IF;
    knh_Method_t *SWITCH;
    knh_Method_t *WHILE;
    knh_Method_t *DO;
    knh_Method_t *FOR;
    knh_Method_t *FOREACH;
    knh_Method_t *BREAK;
    knh_Method_t *CONTINUE;
    knh_Method_t *TRY;
    knh_Method_t *THROW;
    knh_Method_t *RETURN;
    knh_Method_t *YIELD;
    knh_Method_t *PRINT;
    knh_Method_t *ASSURE;
    knh_Method_t *ASSERT;
    knh_Method_t *ERR;
    knh_Method_t *EXPR;
    knh_Method_t *LETEXPR;
    knh_Method_t *FUNCCALL;
    knh_Method_t *CALL;
    knh_Method_t *CALL1;
    knh_Method_t *BOX;
    knh_Method_t *OPR;
    knh_Method_t *NEW;
    knh_Method_t *TCAST;
    knh_Method_t *AND;
    knh_Method_t *OR;
    knh_Method_t *ALT;
    knh_Method_t *TRI;
    knh_Method_t *SEND;
    knh_Method_t *W1;
    knh_Method_t *FMTCALL;
};

static void kook_compiler_compiler(CTX ctx, knh_Method_t *mtd, knh_Stmt_t *stmtB)
{
    KNH_P("hello world");
    knh_Method_sync(ctx, mtd, f);
}

static knh_Method_t *load_method(CTX ctx, knh_class_t cid, knh_bytes_t t)
{
    knh_methodn_t mn = knh_getmn(ctx, t, MN_NONAME);
    knh_Method_t *mtd = knh_NameSpace_getMethodNULL(ctx, NULL, cid, mn);
    assert(mtd != NULL);
    return mtd;
}
#define LOADMTD(ctx, cid, name) load_method(ctx, cid, STEXT(name))

static struct knh_CompilerAPI_t COMPILER_API = {};
DEFAPI(void) complete(CTX ctx)
{
    knh_class_t cid = knh_getcid(ctx, B("konoha.compiler.Compiler"));
    struct knh_CompilerAPI_t *api = &COMPILER_API;
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
    ctx->wshare->konoha_compiler = api->Instance;
    ctx->wshare->compilerAPI = (void *) kook_compiler_compiler;
}

