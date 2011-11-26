/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 * You may choose one of the following two licelanges when you use konoha.
 * If you want to use the latter licelange, please contact us.
 *
 * (1) GNU General Public Licelange 3.0 (with K_UNDER_GPL)
 * (2) Konoha Non-Disclosure Licelange 1.
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

/* --------------- */
/* Token */

static void Token_init(CTX ctx, kRawPtr *o)
{
	kToken *tk = (kToken*)o;
	tk->uline     =   0;
	tk->token     =   TK_NONE;
	tk->topch     =   0;
	tk->lpos      =   -1;
	KNH_INITv(tk->text, TS_EMPTY);
}

static void Token_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kToken *tk = (kToken*)o;
	KNH_ADDREF(ctx, tk->text);
	KNH_SIZEREF(ctx);
}

static void Token_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kToken *tk = (kToken*)o;
//	if(IS_FMTdump(level)) {
//		if(tk->uline != 0) {
//			knh_write(ctx, w, STEXT("+L"));
//			knh_write_ifmt(ctx, w, KINT_FMT, ULINE_line(tk->uline));
//		}
//		if(SP(tk)->type != TYPE_var) {
//			knh_write(ctx, w, STEXT("+:")); knh_write_type(ctx, w, SP(tk)->type);
//		}
//	}
	knh_write(ctx, w, S_tobytes(tk->text));
}

static const kclassdef_t TokenDef = {
	Token_init, TODO_initcopy, Token_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Token_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Token", CFLAG_Token, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Token), 0,
};

/* --------------- */
/* Sugar */

static void Sugar_init(CTX ctx, kRawPtr *o)
{
	kSugar *sgr = (kSugar*)o;
	sgr->sugar = SUGAR_TOKEN;
	KNH_INITv(sgr->key, TS_EMPTY);
	KNH_INITv(sgr->rules, new_Array0(ctx, 0));
}

static void Sugar_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kSugar *sgr = (kSugar*)o;
	KNH_ADDREF(ctx, sgr->key);
	KNH_ADDREF(ctx, sgr->rules);
	KNH_SIZEREF(ctx);
}

static void Sugar_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
//	kSugar *sugar = (kSugar*)o;
//	if(IS_FMTdump(level)) {
//		if(tk->uline != 0) {
//			knh_write(ctx, w, STEXT("+L"));
//			knh_write_ifmt(ctx, w, KINT_FMT, ULINE_line(tk->uline));
//		}
//		if(SP(tk)->type != TYPE_var) {
//			knh_write(ctx, w, STEXT("+:")); knh_write_type(ctx, w, SP(tk)->type);
//		}
//	}
//	knh_write(ctx, w, S_tobytes(tk->text));
}

static const kclassdef_t SugarDef = {
	Sugar_init, TODO_initcopy, Sugar_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Sugar_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Sugar", CFLAG_Sugar, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Sugar), 0,
};

/* --------------- */
/* Expr */

static void Expr_init(CTX ctx, kRawPtr *o)
{
	kExpr *expr = (kExpr*)o;
	expr->kexpr       =   UEXPR_USER_DEFINED;
	expr->type       =   TYPE_var;
	expr->index      =   0;
	expr->xindex     =   0;
	KNH_INITv(expr->token, KNH_NULL);
	KNH_INITv(expr->data,  TS_EMPTY);
}

static void Expr_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kExpr *expr = (kExpr*)o;
	KNH_ADDREF(ctx, expr->token);
	KNH_ADDREF(ctx, expr->data);
	KNH_SIZEREF(ctx);
}

static void Expr_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kExpr *expr = (kExpr*)o;
	int i, kexpr = (int)expr->kexpr;
	switch(kexpr) {
	// untyped
	case UEXPR_TOKEN: {
		knh_write(ctx, w, S_tobytes(expr->token->text));
	}
	break;
	case UEXPR_METHOD_CALL:
	case UEXPR_CALL:
	case UEXPR_BINARY:
	case UEXPR_GETTER: {
		knh_putc(ctx, w, '(');
		for(i = 0; i < knh_Array_size(expr->cons); i++) {
			if(i > 0) knh_putc(ctx, w, ' ');
			knh_write_Object(ctx, w, expr->cons->list[i], FMT_line);
		}
		knh_putc(ctx, w, ')');
	}
	break;
	// typed
	case TEXPR_TYPE: {
		knh_write(ctx, w, STEXT("[TYPE]"));
		knh_write_type(ctx, w, expr->cid);
	}
	break;
	case TEXPR_CONST: {
		knh_write(ctx, w, STEXT("[CONST]"));
		knh_write_Object(ctx, w, expr->data, FMT_line);
	}
	break;
	case TEXPR_METHOD_CALL: {
		knh_write(ctx, w, STEXT("[CALL]"));
		knh_putc(ctx, w, '(');
		for(i = 0; i < knh_Array_size(expr->cons); i++) {
			if(i > 0) knh_putc(ctx, w, ' ');
			knh_write_Object(ctx, w, expr->cons->list[i], FMT_line);
		}
		knh_putc(ctx, w, ')');
	}
	break;
	default:
		knh_write(ctx, w, STEXT("**UNSET kexpr="));
		knh_write_ifmt(ctx, w, KINT_FMT, (kint_t)kexpr);
	}
	if(expr->type != TYPE_var) {
		knh_putc(ctx, w, ':');
		knh_write_type(ctx, w, expr->type);
	}
}

static const kclassdef_t ExprDef = {
	Expr_init, TODO_initcopy, Expr_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Expr_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Expr", CFLAG_Expr, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Expr), 0,
};

/* --------------- */
/* Stmt */

static void Stmt_init(CTX ctx, kRawPtr *o)
{
	kStmt *stmt = (kStmt*)o;
	stmt->uline      =   0;
	KNH_INITv(stmt->key,    TS_EMPTY);
	KNH_INITv(stmt->parent, KNH_NULL);
	KNH_INITv(stmt->clauseDictMap, new_DictMap0(ctx, 0, 0/*isCaseMap*/, NULL));
}

static void Stmt_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kStmt *stmt = (kStmt*)o;
	KNH_ADDREF(ctx, stmt->key);
	KNH_ADDREF(ctx, stmt->parent);
	KNH_ADDREF(ctx, stmt->clauseDictMap);
	KNH_SIZEREF(ctx);
}

static void Stmt_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
	kStmt *stmt = (kStmt*)o;
	knh_write_Object(ctx, w, UPCAST(stmt->key), FMT_line);
	if(IS_FMTdump(level)) {
		knh_write_EOL(ctx, w); knh_write_TAB(ctx, w);
		knh_write_Object(ctx, w, UPCAST(stmt->clauseDictMap), level);
	}
}

static const kclassdef_t StmtDef = {
	Stmt_init, TODO_initcopy, Stmt_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Stmt_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Stmt", CFLAG_Stmt, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Stmt), 0,
};

/* --------------- */
/* Block */

static void Block_init(CTX ctx, kRawPtr *o)
{
	kBlock *bk = (kBlock*)o;
	KNH_INITv(bk->parent, KNH_NULL);
	KNH_INITv(bk->blocks, new_Array0(ctx, 0));
}

static void Block_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kBlock *bk = (kBlock*)o;
	KNH_ADDREF(ctx, bk->parent);
	KNH_ADDREF(ctx, bk->blocks);
	KNH_SIZEREF(ctx);
}

static void Block_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{
//	kBlock *bk = (kBlock*)o;
//	knh_write(ctx, w, S_tobytes(tk->text));
}

static const kclassdef_t BlockDef = {
	Block_init, TODO_initcopy, Block_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Block_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Block", CFLAG_Block, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Block), 0,
};

static void Lang_init(CTX ctx, kRawPtr *o)
{
	kLang *lang = (kLang*)o;
	knh_LangEX_t *b;
#ifdef K_USING_BMGC
	b = DP(lang);
#else
	b = knh_bodymalloc(ctx, Lang);
	lang->b = b;
#endif
	knh_bzero(b, sizeof(knh_LangEX_t));
	lang->parentNULL       = NULL;
	KNH_INITv(lang->name,  TS_EMPTY);
	KNH_INITv(lang->gcbuf, new_Array0(ctx, 0));
}

static void Lang_reftrace(CTX ctx, kRawPtr *o FTRARG)
{
	kLang *lang = (kLang*)o;
	knh_LangEX_t *b = DP(lang);
	KNH_ADDREF(ctx, lang->name);
	KNH_ADDREF(ctx, lang->gcbuf);
	KNH_ADDNNREF(ctx, lang->parentNULL);
	KNH_ADDNNREF(ctx, b->tokenRulesNULL);
	KNH_ADDNNREF(ctx, b->uninaryRulesNULL);
	KNH_ADDNNREF(ctx, b->binaryRulesNULL);
	KNH_ADDNNREF(ctx, b->stmtRulesNULL);
	KNH_ADDNNREF(ctx, b->exprRulesNULL);
	KNH_SIZEREF(ctx);
}

static void Lang_free(CTX ctx, kRawPtr *o)
{
	BODY_free(ctx, o);
}

static void Lang_p(CTX ctx, kOutputStream *w, kRawPtr *o, int level)
{

}

static const kclassdef_t LangDef = {
	Lang_init, TODO_initcopy, Lang_reftrace, Lang_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Lang_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Lang", CFLAG_Lang, sizeof(knh_LangEX_t), NULL,
	NULL, DEFAULT_4, DEFAULT_5, sizeof_O(Lang), 0,
};

