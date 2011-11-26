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



static kExpr* Expr_type(CTX ctx, kExpr *expr, kGamma *gma, kclass_t reqt);

static kExpr* Expr_typeCheck(CTX ctx, kExpr *expr, kGamma *gma, kclass_t reqt)
{
	kExpr *e = expr;
	if(e->type == TYPE_var) {
		e = Expr_type(ctx, expr, gma, reqt);
		if(e == NULL) {
			return NULL;
		}
		if(e->type == TYPE_var) {
			//
		}
	}
	// type-check here
	return expr;
}


static kMethod *Expr_toMethodNULL(CTX ctx, kExpr *expr, kGamma *gma, kclass_t reqt)
{
	return NULL;
}

//o.call("method", c, arg1, arg2);
static kExpr* MethodStaticCall_type(CTX ctx, kExpr *expr, kGamma *gma, kclass_t reqt);
static kExpr* MethodDynamicCall_type(CTX ctx, kExpr *expr, kGamma *gma, kclass_t reqt);

static kExpr* MethodCall_type(CTX ctx, kExpr *expr, kGamma *gma, kclass_t reqt)
{
	kArray *cons = expr->cons;
	kExpr *e = Expr_typeCheck(ctx, cons->exprs[0], gma, TYPE_Object);
	if(e == NULL) return e;
	KNH_SETv(ctx, cons->exprs[0], e);
	if(e->type == TYPE_dynamic) {
		return MethodDynamicCall_type(ctx, expr, gma, reqt);
	}
	else {
		kMethod *mtd = Expr_toMethodNULL(ctx, cons->exprs[1], gma, e->type);
		if(mtd == NULL) {
			return ERROR_TokenUndefinedMethod(ctx, cons->exprs[1]->token, e->type);
		}
		return MethodStaticCall_type(ctx, expr, gma, reqt);
	}
	return expr;
}

static kExpr* MethodStaticCall_type(CTX ctx, kExpr *expr, kGamma *gma, kclass_t reqt)
{
	kArray *cons = expr->cons;
	size_t i, csize = knh_Array_size(cons);
	expr->kexpr = TEXPR_METHOD_CALL;
	for(i = 2; i < csize; i++) {
		kExpr *e = Expr_typeCheck(ctx, cons->exprs[i], gma, TYPE_Object);
		if(e == NULL) {

			return e;
		}
		KNH_SETv(ctx, cons->exprs[i], e);
	}
	expr->type = TYPE_dynamic;
	return expr;
}

static kExpr* MethodDynamicCall_type(CTX ctx, kExpr *expr, kGamma *gma, kclass_t reqt)
{
	kArray *cons = expr->cons;
	size_t i, csize = knh_Array_size(cons);
	expr->kexpr = TEXPR_METHOD_CALL;
	for(i = 2; i < csize; i++) {
		kExpr *e = Expr_typeCheck(ctx, cons->exprs[i], gma, TYPE_Object);
		if(e == NULL) return e;
		KNH_SETv(ctx, cons->exprs[i], e);
	}
	expr->type = TYPE_dynamic;
	return expr;
}


static kExpr* Term_type(CTX ctx, kExpr *expr, kGamma *gma, kclass_t reqt);

static kExpr* Expr_type(CTX ctx, kExpr *expr, kGamma *gma, kclass_t reqt)
{
	DBG_ASSERT(expr->type != TYPE_var);
	kExpr *e = expr;
	switch(expr->kexpr) {
	case UEXPR_TOKEN:       e = Term_type(ctx, expr, gma, reqt);       break;
	case UEXPR_METHOD_CALL: e = MethodCall_type(ctx, expr, gma, reqt); break;
/*	case UEXPR_FUNC_CALL:   e = FuncCall_type(ctx, expr, gma, reqt);   break; */
/*	case UEXPR_NEW_CALL:    e = NewCall_type(ctx, expr, gma, reqt);    break; */
	case UEXPR_USER_DEFINED: break;
	}
	if(e->type == TYPE_var) {

	}
	return NULL;
}

static kExpr* TextTerm_type(CTX ctx, kExpr *expr, kGamma *gma, kclass_t reqt);
static kExpr* IntTerm_type(CTX ctx, kExpr *expr, kGamma *gma, kclass_t reqt);
static kExpr* FloatTerm_type(CTX ctx, kExpr *expr, kGamma *gma, kclass_t reqt);

static kExpr* Term_type(CTX ctx, kExpr *expr, kGamma *gma, kclass_t reqt)
{
	kToken *tk = expr->token;
	switch((int)tk->token) {
	case TK_SYMBOL:
	case TK_USYMBOL:
	case TK_TEXT:   return TextTerm_type(ctx, expr, gma, reqt);
	case TK_STEXT:  return TextTerm_type(ctx, expr, gma, reqt);
	case TK_INT:    return IntTerm_type(ctx, expr, gma, reqt);
	case TK_FLOAT:  return FloatTerm_type(ctx, expr, gma, reqt);
	case TK_URN:
	case TK_REGEX:
	default:
		DBG_P("** undeveloped token=%d", (int)tk->token);
		return NULL;
	}
	return NULL;
}

static kExpr* TextTerm_type(CTX ctx, kExpr *expr, kGamma *gma, kclass_t reqt)
{
	return Expr_setConst(ctx, expr, expr->token->text);
}

static kExpr* IntTerm_type(CTX ctx, kExpr *expr, kGamma *gma, kclass_t reqt)
{
	kToken *tk = expr->token;
	kbytes_t t = S_tobytes(tk->text);
	kint_t n = 0;
	if(reqt == CLASS_Boolean) {
		if(t.utext[0] == '0') {
			WARN_TokenMuchBetter(ctx, tk, "false");
			return Expr_setConst(ctx, expr, KNH_FALSE);
		}
		else {
			WARN_TokenMuchBetter(ctx, tk, "true");
			return Expr_setConst(ctx, expr, KNH_FALSE);
		}
	}
	if(!knh_bytes_parseint(t, &n)) {
		WARN_TokenOverflow(ctx, tk);
	}
	if(reqt == CLASS_Float) {
		return Expr_setConst(ctx, expr, new_Float(ctx, (kfloat_t)n));
	}
	else {
		return Expr_setConst(ctx, expr, new_Int(ctx, n));
	}
}

static kExpr* FloatTerm_type(CTX ctx, kExpr *expr, kGamma *gma, kclass_t reqt)
{
	kToken *tk = expr->token;
	kbytes_t t = S_tobytes(tk->text);
	kfloat_t num = 0;
	if(!knh_bytes_parsefloat(t, &num)) {
		WARN_TokenOverflow(ctx, tk);
	}
	if(reqt == CLASS_Int) {
		return Expr_setConst(ctx, expr, new_Int(ctx, (kint_t)num));
	}
	else {
		return Expr_setConst(ctx, expr, new_Float(ctx, num));
	}
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
