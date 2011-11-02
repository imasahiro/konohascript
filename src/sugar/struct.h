/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
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

/* --------------- */
/* Token */

static void Token_init(CTX ctx, knh_RawPtr_t *o)
{
	knh_Token_t *tk = (knh_Token_t*)o;
	tk->uline     =   0;
	tk->token     =   TK_WHITESPACE;
	tk->optnum     =   0;
	KNH_INITv(tk->text, TS_EMPTY);
}

static void Token_reftrace(CTX ctx, knh_RawPtr_t *o FTRARG)
{
	knh_Token_t *tk = (knh_Token_t*)o;
	KNH_ADDREF(ctx, tk->text);
	KNH_SIZEREF(ctx);
}

static void Token_p(CTX ctx, knh_OutputStream_t *w, knh_RawPtr_t *o, int level)
{
	knh_Token_t *tk = (knh_Token_t*)o;
//	if(IS_FMTdump(level)) {
//		if(tk->uline != 0) {
//			knh_write(ctx, w, STEXT("+L"));
//			knh_write_ifmt(ctx, w, K_INT_FMT, ULINE_line(tk->uline));
//		}
//		if(SP(tk)->type != TYPE_var) {
//			knh_write(ctx, w, STEXT("+:")); knh_write_type(ctx, w, SP(tk)->type);
//		}
//	}
	knh_write(ctx, w, S_tobytes(tk->text));
}

static const knh_ClassDef_t TokenDef = {
	Token_init, TODO_initcopy, Token_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Token_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Token", CFLAG_Token, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, DEFAULT_6, 0,
};

/* --------------- */
/* Sugar */

static void Sugar_init(CTX ctx, knh_RawPtr_t *o)
{
	knh_Sugar_t *sugar = (knh_Sugar_t*)o;
	sugar->sugar = SUGAR_SYNTAX;
	KNH_INITv(sugar->rules, new_Array0(ctx, 0));
	KNH_INITv(sugar->action, KNH_NULL);
}

static void Sugar_reftrace(CTX ctx, knh_RawPtr_t *o FTRARG)
{
	knh_Sugar_t *sugar = (knh_Sugar_t*)o;
	KNH_ADDREF(ctx, sugar->rules);
	KNH_ADDREF(ctx, sugar->action);
	KNH_SIZEREF(ctx);
}

static void Sugar_p(CTX ctx, knh_OutputStream_t *w, knh_RawPtr_t *o, int level)
{
//	knh_Sugar_t *sugar = (knh_Sugar_t*)o;
//	if(IS_FMTdump(level)) {
//		if(tk->uline != 0) {
//			knh_write(ctx, w, STEXT("+L"));
//			knh_write_ifmt(ctx, w, K_INT_FMT, ULINE_line(tk->uline));
//		}
//		if(SP(tk)->type != TYPE_var) {
//			knh_write(ctx, w, STEXT("+:")); knh_write_type(ctx, w, SP(tk)->type);
//		}
//	}
//	knh_write(ctx, w, S_tobytes(tk->text));
}

static const knh_ClassDef_t SugarDef = {
	Sugar_init, TODO_initcopy, Sugar_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Sugar_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Sugar", CFLAG_Sugar, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, DEFAULT_6, 0,
};

/* --------------- */
/* Expr */

static void Expr_init(CTX ctx, knh_RawPtr_t *o)
{
	knh_Expr_t *expr = (knh_Expr_t*)o;
	expr->uline      =   0;
	expr->expr       =   EXPR_USER;
	expr->type       =   TYPE_var;
	expr->index      =    0;
	expr->xindex     =    0;
	KNH_INITv(expr->data, TS_EMPTY);
}

static void Expr_reftrace(CTX ctx, knh_RawPtr_t *o FTRARG)
{
	knh_Expr_t *expr = (knh_Expr_t*)o;
	KNH_ADDREF(ctx, expr->data);
	KNH_SIZEREF(ctx);
}

static void Expr_p(CTX ctx, knh_OutputStream_t *w, knh_RawPtr_t *o, int level)
{
//	knh_Expr_t *tk = (knh_Expr_t*)o;
//	if(IS_FMTdump(level)) {
//		if(tk->uline != 0) {
//			knh_write(ctx, w, STEXT("+L"));
//			knh_write_ifmt(ctx, w, K_INT_FMT, ULINE_line(tk->uline));
//		}
//		if(SP(tk)->type != TYPE_var) {
//			knh_write(ctx, w, STEXT("+:")); knh_write_type(ctx, w, SP(tk)->type);
//		}
//	}
//	knh_write(ctx, w, S_tobytes(tk->text));
}

static const knh_ClassDef_t ExprDef = {
	Expr_init, TODO_initcopy, Expr_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Expr_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Expr", CFLAG_Expr, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, DEFAULT_6, 0,
};

/* --------------- */
/* Stmt */

static void Stmt_init(CTX ctx, knh_RawPtr_t *o)
{
	knh_Stmt_t *stmt = (knh_Stmt_t*)o;
	stmt->uline     =   0;
	stmt->stmt      =   STMT_USER;
	stmt->optnum    =   0;
	KNH_INITv(stmt->clauseDictMap, new_DictMap0(ctx, 0, 0/*isCaseMap*/, NULL));
}

static void Stmt_reftrace(CTX ctx, knh_RawPtr_t *o FTRARG)
{
	knh_Stmt_t *stmt = (knh_Stmt_t*)o;
	KNH_ADDREF(ctx, stmt->clauseDictMap);
	KNH_SIZEREF(ctx);
}

static void Stmt_p(CTX ctx, knh_OutputStream_t *w, knh_RawPtr_t *o, int level)
{
//	knh_Stmt_t *tk = (knh_Stmt_t*)o;
//	if(IS_FMTdump(level)) {
//		if(tk->uline != 0) {
//			knh_write(ctx, w, STEXT("+L"));
//			knh_write_ifmt(ctx, w, K_INT_FMT, ULINE_line(tk->uline));
//		}
//		if(SP(tk)->type != TYPE_var) {
//			knh_write(ctx, w, STEXT("+:")); knh_write_type(ctx, w, SP(tk)->type);
//		}
//	}
//	knh_write(ctx, w, S_tobytes(tk->text));
}

static const knh_ClassDef_t StmtDef = {
	Stmt_init, TODO_initcopy, Stmt_reftrace, DEFAULT_free,
	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Stmt_p,
	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
	"Stmt", CFLAG_Stmt, 0, NULL,
	NULL, DEFAULT_4, DEFAULT_5, DEFAULT_6, 0,
};

///* --------------- */
///* Stmt */
//
//static void Stmt_init(CTX ctx, knh_RawPtr_t *o)
//{
//	knh_Stmt_t *tk = (knh_Stmt_t*)o;
//	tk->uline     =   0;
//	tk->token     =   TK_WHITESPACE;
//	tk->optnum     =   0;
//	KNH_INITv(tk->text, TS_EMPTY);
//}
//
//static void Stmt_reftrace(CTX ctx, knh_RawPtr_t *o FTRARG)
//{
//	knh_Stmt_t *tk = (knh_Stmt_t*)o;
//	KNH_ADDREF(ctx, tk->text);
//	KNH_SIZEREF(ctx);
//}
//
//static void Stmt_p(CTX ctx, knh_OutputStream_t *w, knh_RawPtr_t *o, int level)
//{
//	knh_Stmt_t *tk = (knh_Stmt_t*)o;
////	if(IS_FMTdump(level)) {
////		if(tk->uline != 0) {
////			knh_write(ctx, w, STEXT("+L"));
////			knh_write_ifmt(ctx, w, K_INT_FMT, ULINE_line(tk->uline));
////		}
////		if(SP(tk)->type != TYPE_var) {
////			knh_write(ctx, w, STEXT("+:")); knh_write_type(ctx, w, SP(tk)->type);
////		}
////	}
//	knh_write(ctx, w, S_tobytes(tk->text));
//}
//
//static const knh_ClassDef_t StmtDef = {
//	Stmt_init, TODO_initcopy, Stmt_reftrace, DEFAULT_free,
//	DEFAULT_checkin, DEFAULT_checkout, DEFAULT_compareTo, Stmt_p,
//	DEFAULT_getkey, DEFAULT_hashCode, DEFAULT_0, DEFAULT_1,
//	DEFAULT_findTypeMapNULL, DEFAULT_wdata, DEFAULT_2, DEFAULT_3,
//	"Stmt", CFLAG_Stmt, 0, NULL,
//	NULL, DEFAULT_4, DEFAULT_5, DEFAULT_6, 0,
//};

