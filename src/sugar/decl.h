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

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif


/* ------------------------------------------------------------------------ */
/* [lang interface] */

static kbool_t checkTEXT(CTX ctx, kToken *tk)
{
	if (tk->token == TK_TEXT || tk->token == TK_STEXT) {
		return 1;
	}
	return ERROR_TokenMustBe(ctx, tk, "\"TEXT\"");
}

static kbool_t checkexpr(CTX ctx, kToken *tk)
{
	if (tk->token == TK_SYMBOL && knh_String_equals(tk->text, "expr")) {
		return 1;
	}
	return ERROR_TokenMustBe(ctx, tk, "expr");
}

static kbool_t checkSugarRule(CTX ctx, kArray *rules)
{
	size_t i, size = knh_Array_size(rules);
	for(i = 0; i < size; i++) {
		kToken *tk = rules->tokens[i];
		if(tk->token == TK_TEXT || tk->token == TK_STEXT || tk->token == TK_SYMBOL || tk->token == TK_USYMBOL) continue;
		if(tk->topch == '[' || tk->topch == ']' || tk->topch == '^' || tk->topch == ':') continue;
		return ERROR_TokenError(ctx, tk);
	}
	return 1;
}

static kbool_t checkSizeEq(CTX ctx, kline_t uline, size_t size, size_t eq)
{
	if(size == eq) {
		return 1;
	}
	return ERROR_SyntaxError(ctx, uline);
}

static kbool_t Lang_addSugar(CTX ctx, kLang *lang, kSugar *sgr, kline_t uline)
{
	kArray *rules = sgr->rules;
	size_t size = knh_Array_size(rules);
	switch(sgr->sugar) {
	case SUGAR_TOKEN:
		if(checkSizeEq(ctx, uline, size, 1) && checkTEXT(ctx, rules->tokens[0])) {
			knh_DictMap_set(ctx, DP(lang)->tokenRulesNULL, sgr->key, rules->tokens[0]->text);
			return 1;
		}
		break;
	case SUGAR_DECL:
	case SUGAR_STMT:
		if(checkSugarRule(ctx, rules)) {
			knh_Array_add(ctx, DP(lang)->stmtRulesNULL, sgr);
			return 1;
		}
		break;
	case SUGAR_EXPR:
	case SUGAR_TYPE:
		if(checkSugarRule(ctx, rules)) {
			knh_Array_add(ctx, DP(lang)->exprRulesNULL, sgr);
			return 1;
		}
		break;
	case SUGAR_BINARY:
		if(size == 3) {
			kToken *tk1 = rules->tokens[1];
			if(checkTEXT(ctx, tk1) && checkexpr(ctx, rules->tokens[0]) && checkexpr(ctx, rules->tokens[2])) {
				knh_DictMap_set(ctx, DP(lang)->binaryRulesNULL, tk1->text, sgr);
				return 1;
			}
		}
		else if(size == 2){
			kToken *tk0 = rules->tokens[0];
			if(checkTEXT(ctx, tk0) && checkexpr(ctx, rules->tokens[1])) {
				sgr->sugar = SUGAR_UNINARY;
				knh_DictMap_set(ctx, DP(lang)->uninaryRulesNULL, tk0->text, sgr);
				return 1;
			}
		}
		return checkSizeEq(ctx, uline, size, 3);
	}
	return 0;
}

static kbool_t NameSpace_checkMethodAddition(CTX ctx, kNameSpace *ns, kMethod *mtd, kline_t uline)
{
	knh_ClassTBL_addMethod(ctx, ClassTBL(mtd->cid), mtd, 0);
	return 1;
}

/* ------------------------------------------------------------------------ */
/* [SugarDecl] */

static kbool_t declSugar(CTX ctx, kStmt *stmt, kLang *lang);

// boolean Lang.evalSugarDecl(Stmt stmt, Object scr, NameSpace ns);
static KMETHOD Lang_evalSugarDecl(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNb_(declSugar(ctx, sfp[1].stmt, ctx->share->corelang));
}

static kbool_t declSugar(CTX ctx, kStmt *stmt, kLang *lang)
{
	kToken *tk = Stmt_getTokenNULL(ctx, stmt, "sugar");
	kArray  *rule = (kArray*)Stmt_getConst(ctx, stmt, "tokens", knh_class_P1(ctx, CLASS_Array, CLASS_Token));
	if(tk == NULL || knh_Array_size(rule) == 0) {
		return ERROR_SyntaxError(ctx, stmt->uline);
	}
	kbytes_t n = S_tobytes(tk->text);
	ksugar_t sugar = -1;
	if(n.len > 0) {
		if(knh_bytes_endsWith(n, "Decl")) {
			sugar = SUGAR_DECL;
		}
		else if(knh_bytes_endsWith(n, "Stmt")) {
			sugar = SUGAR_STMT;
		}
		else if(knh_bytes_endsWith(n, "Expr")) {
			sugar = SUGAR_EXPR;
		}
		else if(knh_bytes_endsWith(n, "Type")) {
			sugar = SUGAR_TYPE;
		}
		else if(knh_bytes_startsWith(n, "op")) {
			sugar = SUGAR_BINARY;
		}
	}
	if(sugar != -1) {
		kSugar *sgr = new_(Sugar);
		sgr->sugar = sugar;
		KNH_SETv(ctx, sgr->key, tk->text);
		KNH_SETv(ctx, sgr->key, rule);
		if(sugar == SUGAR_BINARY) {
			sgr->optnum = (kshort_t)Stmt_getint(ctx, stmt, "@Priority", 10);
		}
		Lang_addSugar(ctx, lang, sgr, stmt->uline);
		return 1;
	}
	return 0;
}

/* ------------------------------------------------------------------------ */
/* [MethodDecl] */

static kbool_t declMethod(CTX ctx, kStmt *stmt, kObject *scr, kNameSpace *ns);
static kParam *Block_newMethodParam(CTX ctx, kBlock *params, kNameSpace *ns);
static void inferMethodParam(CTX ctx, kParam *pa, kclass_t cid);

// boolean Lang.evalMethodDecl(Stmt stmt, Object scr, NameSpace ns);

static KMETHOD Lang_evalMethodDecl(CTX ctx, ksfp_t *sfp _RIX)
{
	RETURNb_(declMethod(ctx, sfp[1].stmt, sfp[2].o, sfp[3].ns));
}

static flagop_t MethodDeclFlag[] = {
	{AKEY("@Virtual"), FLAG_Method_Virtual},
	{AKEY("@Private"), FLAG_Method_Private},
	{AKEY("@Const"), FLAG_Method_Const},
	{AKEY("@Static"), FLAG_Method_Static},
	{AKEY("@Immutable"), FLAG_Method_Static},
	{AKEY("@Throwable"), FLAG_Method_Throwable},
	{AKEY("@Iterative"), FLAG_Method_Iterative},
	{AKEY("@Restricted"), FLAG_Method_Restricted},
	{AKEY("@Smart"), FLAG_Method_Restricted},
	{NULL},
};

static kbool_t declMethod(CTX ctx, kStmt *stmt, kObject *scr, kNameSpace *ns)
{
	kflag_t flag =  Stmt_flag(ctx, stmt, MethodDeclFlag, 0);
	kclass_t cid =  Stmt_getcid(ctx, stmt, "class", ns, O_cid(scr));
	kmethodn_t mn = Stmt_getmn(ctx, stmt, "method", MN_new);
	kMethod *mtd = new_Method(ctx, flag, cid, mn, NULL);
	kParam *pa = Block_newMethodParam(ctx, Stmt_getBlock(ctx, stmt, "params"), ns);
	inferMethodParam(ctx, pa, cid);
	knh_Param_addReturnType(ctx, pa, Stmt_gettype(ctx, stmt, "rtype", ns, TYPE_var));
	kToken *tcode = Stmt_getTokenNULL(ctx, stmt, "code");
	if(tcode != NULL) {
		KNH_SETv(ctx, DP(mtd)->tcode, tcode);
	}
	if(!NameSpace_checkMethodAddition(ctx, ns, mtd, Stmt_uline(stmt))) {
		Stmt_done(ctx, stmt);
		return 0;
	}
	return 1;
}

static kParam *Block_newMethodParam(CTX ctx, kBlock *params, kNameSpace *ns)
{
	size_t i, psize = knh_Array_size(params->blocks);
	kParam *pa = new_(Param);
	for(i = 0; i < psize; i++) {
		kStmt *stmt = (kStmt*)params->blocks->list[i];
		kclass_t cid  = Stmt_getcid(ctx, stmt, "type", ns, CLASS_unknown);
		ksymbol_t fn  = Stmt_getfn(ctx, stmt, "name", FN_);
		knh_Param_addParam(ctx, pa, cid, fn);
	}
	return pa;
}

static void inferMethodParam(CTX ctx, kParam *pa, kclass_t cid)
{

}

static kbool_t checkMethodParam(CTX ctx, kParam *pa, kParam *sup_pa)
{
	return 1;
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
