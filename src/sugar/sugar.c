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

#include "token.h"

#ifdef __cplusplus
extern "C" {
#endif


/* ------------------------------------------------------------------------ */

void knh_NameSpace_loadAlias(CTX ctx, knh_NameSpace_t *ns, const char *rule, const char *alias)
{
	if(DP(ns)->aliasRulesNULL == NULL) {
		KNH_INITv(DP(ns)->aliasRulesNULL, new_DictMap0(ctx, 0, 0, NULL));
	}
	knh_DictMap_set(ctx, DP(ns)->aliasRulesNULL, new_T(rule), (knh_Object_t*)new_T(alias));
}

void knh_NameSpace_loadSyntaxSugar(CTX ctx, knh_NameSpace_t *ns, const char *rules, void *func)
{
	if(DP(ns)->syntaxRulesNULL == NULL) {
		KNH_INITv(DP(ns)->syntaxRulesNULL, new_Array0(ctx, 0));
	}
	knh_Sugar_t *sugar = new_(Sugar);
	KNH_SETv(ctx, sugar->rules, new_Array0(ctx, 0));
	KNH_SETv(ctx, sugar->action, new_RawPtr(ctx, ClassTBL(CLASS_Tdynamic), func));
	knh_Array_add(ctx, DP(ns)->syntaxRulesNULL, sugar);
	tenv_t tenvbuf = {
		0,
		sugar->rules,
		(const knh_uchar_t *)rules,
		ctx->bufa,
		BA_size(ctx->bufa),
		3,
	};
	parse(ctx, &tenvbuf, 0);
}

void knh_NameSpace_loadStatementSugar(CTX ctx, knh_NameSpace_t *ns, const char *rules, void *func)
{
	if(DP(ns)->statementRulesNULL == NULL) {
		KNH_INITv(DP(ns)->statementRulesNULL, new_Array0(ctx, 0));
	}
	knh_Sugar_t *sugar = new_(Sugar);
	KNH_SETv(ctx, sugar->rules, new_Array0(ctx, 0));
	KNH_SETv(ctx, sugar->action, new_RawPtr(ctx, ClassTBL(CLASS_Tdynamic), func));
	knh_Array_add(ctx, DP(ns)->statementRulesNULL, sugar);
	tenv_t tenvbuf = {
		0,
		sugar->rules,
		(const knh_uchar_t *)rules,
		ctx->bufa,
		BA_size(ctx->bufa),
		3,
	};
	parse(ctx, &tenvbuf, 0);
}

/* ------------------------------------------------------------------------ */
/* [term] */

static knh_IntData_t TokenConstInt[] = {
	{"CODE", TK_CODE},
	{"USYMBOL", TK_USYMBOL},
	{"SYMBOL", TK_SYMBOL},
	{"OPERATOR", TK_OPERATOR},
	{"TEXT", TK_TEXT},
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
		(const knh_uchar_t *)S_totext(sfp[0].s),
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

// Token[] System.tokenize(String script, NameSpace _)

static KMETHOD System_tokenize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	knh_Array_t *a = (knh_Array_t*)new_ReturnObject(ctx, sfp);
	tenv_t tenvbuf = {
		1,
		a,
		(const knh_uchar_t *)S_totext(sfp[1].s),
		ctx->bufa,
		BA_size(ctx->bufa),
		3,/*tabsize*/
	};
	KNH_SETv(ctx, sfp[K_RIX].o, a);
	parse(ctx, &tenvbuf, 0);
}

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

#define FuncData(X) {#X , X}

static knh_FuncData_t FuncData[] = {
	FuncData(String_tokenize),
	FuncData(System_tokenize),
	FuncData(Token_getLine),
	FuncData(Token_getText),
	FuncData(Token_getType),
	{NULL, NULL},
};

void knh_initSugarFuncData(CTX ctx, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, CLASS_Token, TokenConstInt);
	kapi->loadFuncData(ctx, FuncData);
}

#ifdef __cplusplus
}
#endif
