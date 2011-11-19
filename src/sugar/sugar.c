/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved..
 *
 * You may choose one of the following two licenses when you use konoha.
 * If you want to use the latter license, please contact us.
 *
 * (1) GNU General Public License 3.0 (with K_UNDER_GPL)
 * (2) Konoha Non-Disclosure License 1.
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

#include "perror.h"
#include "token.h"
#include "stmt.h"
#include "ast.h"
#include "decl.h"
#include "typecheck.h"
//#include "build.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* [term] */

struct stmtsugar_t {
	const char *rule;
	void *func;
} stmtsugar_t;

//static struct stmtsugar_t stmtsugars[] = {
//	{"\"if\" \"(\" cond: expr \")\" then: block [\"else\" else: block]", STMT_IF, NULL},
//	{"\"while\" \"(\" cond: expr \")\" block", STMT_WHILE, NULL},
//	{NULL, STMT_DONE, NULL},
//};

static knh_IntData_t TokenConstInt[] = {
	{"CODE", TK_CODE},
	{"USYMBOL", TK_USYMBOL},
	{"SYMBOL", TK_SYMBOL},
	{"OPERATOR", TK_OPERATOR},
	{"TEXT2", TK_TEXT},
	{"STEXT", TK_STEXT},
	{"REGEX", TK_REGEX},
	{"INT", TK_INT},
	{"FLOAT", TK_FLOAT},
	{"URN", TK_URN},
	{"PROP", TK_PROP},
	{"META", TK_META},
	{"INDENT", TK_INDENT},
	{"WHITESPACE", TK_WHITESPACE},
	{NULL, 0},
};

/* ------------------------------------------------------------------------ */
/* api */

// String[] String.tokenize()

static KMETHOD String_tokenize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = new_Array(ctx, CLASS_String, 0);
	size_t i;
	tenv_t tenvbuf = {
		1,
		a,
		{S_totext(sfp[0].s)}, S_totext(sfp[0].s),
		ctx->bufa,
		BA_size(ctx->bufa),
		3,
	};
	parse(ctx, &tenvbuf, 0);
	for(i = 0; i < knh_Array_size(a); i++) {
		knh_Token_t *tk = (knh_Token_t*)a->list[i];
		KNH_SETv(ctx, a->list[i], tk->text);
	}
	RETURN_(a);
}

// Token[] Lang.tokenize(String script)

static KMETHOD Lang_tokenize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = (knh_Array_t*)new_ReturnObject(ctx, sfp);
	tenv_t tenvbuf = {
		1,
		a,
		{S_totext(sfp[1].s)}, S_totext(sfp[1].s),
		ctx->bufa,
		BA_size(ctx->bufa),
		3,/*tabsize*/
		ctx->share->corelang,
	};
	KNH_SETv(ctx, sfp[K_RIX].o, a);
	parse(ctx, &tenvbuf, 0);
}

// only used in term.c
knh_Array_t* new_TokenArray(CTX ctx, const char *text, knh_uline_t uline)
{
	knh_Array_t *a = (knh_Array_t*)new_Array0(ctx, 0);
	PUSH_GCSTACK(ctx, a);
	tenv_t tenvbuf = {
		uline,
		a,
		{text}, text,
		ctx->bufa,
		BA_size(ctx->bufa),
		3,/*tabsize*/
		ctx->share->corelang,
	};
	DBG_ASSERT(!(BA_totext(ctx->bufa) <= text && text < BA_totext(ctx->bufa) + BA_size(ctx->bufa)));
	parse(ctx, &tenvbuf, 0);
	size_t i;
	for(i = 0; i < knh_Array_size(a); i++) {
		knh_Token_t *tk = a->tokens[i];
		fprintf(stdout, "TOKEN(%d): %d %d '%s'\n", (int)i, (knh_short_t)tk->uline, (int)tk->token, S_totext(tk->text));
	}
	return a;
}

// @Static Block Lang.newBlock(String script, int uline, NameSpace _)

static KMETHOD Lang_newBlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Lang_t *lang = ctx->share->corelang;
	klr_setesp(ctx, sfp+5);
	knh_Array_t *a = new_Array(ctx, CLASS_Token, 0);
	KNH_SETv(ctx, sfp[4].o, a);
	tenv_t tenvbuf = {
		sfp[2].ivalue == 0 ? 1 : (knh_uline_t)sfp[2].ivalue,
		a,
		{S_totext(sfp[1].s)}, S_totext(sfp[1].s),
		ctx->bufa,
		BA_size(ctx->bufa),
		3,/*tabsize*/
		lang,
	};
	parse(ctx, &tenvbuf, 0);
	RETURN_(new_Block(ctx, a, 0, knh_Array_size(a), lang, sfp[3].ns));
}

//// boolean Lang.evalSugarDecl(Stmt stmt, NameSpace _);
//
//static KMETHOD Lang_evalSugarDecl(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	knh_Stmt_t *stmt = sfp[1].stmt;
//	knh_String_t *key = Stmt_getStringNULL(ctx, "sugarname");
//	knh_Array_t *a = Stmt_getConst(ctx, "tokens");
//	knh_Sugar_t *sgr;
//
//}
//
//// void boolean Lang_evalBlock(Block block, NameSpace _);
//
//static KMETHOD Block_eval(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	knh_Lang_t *lang = ctx->share->corelang;
//	knh_Block_t *bk = sfp[1].bk;
//	size_t i;
//	for(i = 0; i < knh_Array_size(bk->blocks); i++) {
//		knh_Stmt_t *stmt = (knh_Stmt_t*)bk->blocks->list[i];
//		knh_Method_t *mtd = NULL;//Lang_getEvalNULL(ctx, lang, stmt->key);
//		if(mtd != NULL) {
//
//		}
//	}
//	RETURNb_(1);
//}
//
//// void boolean Block_typeCheck(Gamma gma);
//
//static KMETHOD Block_typeCheck(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	knh_Lang_t *lang = ctx->share->corelang;
//	knh_Block_t *bk = sfp[0].bk;
//	size_t i;
//	for(i = 0; i < knh_Array_size(bk->blocks); i++) {
//		knh_Stmt_t *stmt = (knh_Stmt_t*)bk->blocks->list[i];
//		knh_Method_t *mtd = NULL;//Lang_getTypeCheckNULL(ctx, lang, stmt->key);
//		if(mtd != NULL) {
//
//		}
//	}
//	RETURNb_(1);
//}
//
//// void boolean Block_build(Builder build);
//
//static KMETHOD Block_build(CTX ctx, knh_sfp_t *sfp _RIX)
//{
//	RETURNb_(1);
//}

static KMETHOD Token_getType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Token_t *tok = (knh_Token_t*)sfp[0].o;
	RETURNi_(tok->token);
}

static KMETHOD Token_getText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Token_t *tok = (knh_Token_t*)sfp[0].o;
	RETURN_(tok->text);
}

static KMETHOD Token_getLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Token_t *tok = (knh_Token_t*)sfp[0].o;
	RETURNi_(ULINE_line(tok->uline));
}

static KMETHOD Token_getPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Token_t *tok = (knh_Token_t*)sfp[0].o;
	RETURNi_(tok->lpos);
}

static KMETHOD Token_error(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Token_t *tok = (knh_Token_t*)sfp[0].o;
	knh_perror(ctx, ERR_, tok->uline, tok->lpos, "%s", S_totext(sfp[1].s));
}

static KMETHOD Token_warn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Token_t *tok = (knh_Token_t*)sfp[0].o;
	knh_perror(ctx, WARN_, tok->uline, tok->lpos, "%s", S_totext(sfp[1].s));
}

static KMETHOD Token_info(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Token_t *tok = (knh_Token_t*)sfp[0].o;
	knh_perror(ctx, INFO_, tok->uline, tok->lpos, "%s", S_totext(sfp[1].s));
}

// sugar tokens "=>" uname;

#define FuncData(X) {#X , X}

static knh_FuncData_t FuncData[] = {
	FuncData(String_tokenize),
	FuncData(Lang_tokenize),
	FuncData(Lang_newBlock),
	FuncData(Token_getLine),
	FuncData(Token_getText),
	FuncData(Token_getType),
	FuncData(Token_getPosition),
	FuncData(Token_error),
	FuncData(Token_warn),
	FuncData(Token_info),
	FuncData(Lang_evalMethodDecl),
	FuncData(Lang_evalSugarDecl),
	{NULL, NULL},
};

void knh_initSugarFuncData(CTX ctx, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, CLASS_Token, TokenConstInt);
	kapi->loadFuncData(ctx, FuncData);
//	struct stmtsugar_t *stmt = stmtsugars;
//	while(stmt->rule != NULL) {
//		knh_NameSpace_loadStatementSugar(ctx, ctx->share->rootns, stmt->rule, stmt->stmt, stmt->func);
//	}
}

void knh_initSugarData(CTX ctx, const knh_LoaderAPI_t *kapi)
{
//	struct stmtsugar_t *stmt = stmtsugars;
//	while(stmt->rule != NULL) {
//		knh_NameSpace_loadStatementSugar(ctx, ctx->share->rootns, stmt->rule, stmt->stmt, stmt->func);
//	}
}

#ifdef __cplusplus
}
#endif
