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

static const char* symTKDATA[] = {
	"TK_NONE",
	"TK_CODE",
	"TK_INDENT",
	"TK_WHITESPACE",
	"TK_OPERATOR",
	"TK_SYMBOL",
	"TK_USYMBOL",
	"TK_TEXT",
	"TK_STEXT",
	"TK_INT",
	"TK_FLOAT",
	"TK_URN",
	"TK_REGEX",
	"TK_META",
	"TK_PROP",
	"TK_LIST",
	"TK_EXPR",
	"TK_STMT",
	"TK_BLOCK",
};

static const char *symTK(ktoken_t t)
{
	if(t <= TK_BLOCK) {
		return symTKDATA[t];
	}
	return "TK_UNKNOWN";
}

static void dumpTokenArray(CTX ctx, kArray *a, int s, int e)
{
	fprintf(stdout, "\n");
	while(s < e) {
		kToken *tk = a->tokens[s];
		fprintf(stdout, "TK(%d) %s %d+%d: '%s'\n", s, symTK(tk->token), (short)tk->uline, tk->lpos, S_totext(tk->text));
		s++;
	}
	fprintf(stdout, "====\n");
}

/* ------------------------------------------------------------------------ */

typedef enum {
	_Init, _Matching, _Deterministic, FoundError
} parserstatus_t;

typedef struct {
	const kcontext_t *ctx;
	kArray         *list;
	int cur;         int eol;
	parserstatus_t       status;
	kString        *key;
	kStmt          *stmt;
	kExpr          *expr;
	kLang          *lang;
	kNameSpace     *ns;
} toks_t;

static toks_t *new_toks(CTX ctx, toks_t *buf, kArray *a, kLang *lang, kNameSpace *ns)
{
	buf->ctx  = ctx;
	buf->list = a;
	buf->cur = 0;
	buf->eol = knh_Array_size(a);
	buf->eol = _Init;
	buf->key = NULL;      // rule
	buf->stmt = NULL;     // rule
	buf->expr = NULL;     // rule
	buf->lang = lang;
	buf->ns   = ns;
	return buf;
}

static inline void sub(toks_t *dst, toks_t *src, int s, int e)
{
	*dst = *src;
	dst->cur = s;
	dst->eol = e;
}

static inline int hasN(toks_t *toks, int n)
{
	int cur = toks->cur + n;
	return (cur < toks->eol);
}

static inline kToken *tkN(toks_t *toks, int n)
{
	int cur = toks->cur + n;
	static kToken dummyEND = {
		{0},
		TK_NONE, {NULL}, 0
	};
	if(cur < toks->eol) {
		kToken *tk = toks->list->tokens[cur];
		return tk;
	}
	return &dummyEND;
}

static inline void incN(toks_t *toks, int n)
{
	toks->cur += n;
}

static int findclose(toks_t *toks, int c, int opench, int closech)
{
	kToken *tkS = toks->list->tokens[c-1];
	for(;c < toks->eol; c++) {
		kToken *tk = toks->list->tokens[c];
		int ch = tk->topch;
		if(ch == closech) return c;
		if(ch == '(') {
			c = findclose(toks, c+1, '(', ')');
			if(c == -1) return -1;
		}
		else if(ch == '[') {
			c = findclose(toks, c+1, '[', ']');
			if(c == -1) return -1;
		}
		else if(ch == '{') {
			c = findclose(toks, c+1, '{', '}');
			if(c == -1) return -1;
		}
	}
	ERROR_NotFoundCloseToken(toks->ctx, tkS, closech);
	toks->status = FoundError;
	return -1;
}

static kbool_t subBetween(toks_t *dst, toks_t *src, int opench, int closech)
{
	int c = findclose(src, src->cur+1, opench, closech);
	if(c == -1) return 0;
	sub(dst, src, src->cur+1, c);
	return 1;
}

static int nextT(toks_t *toks, int n)
{
	int c = n;
	for(c = n; c < toks->eol; c++) {
		kToken *tk = toks->list->tokens[c];
		if(tk->token == TK_WHITESPACE || tk->token == TK_INDENT) continue;
		if(tk->token == TK_META) {
			toks->cur = c;
			tk = tkN(toks, 1);
			if(tk->topch == '(') {
				c = findclose(toks, c+2, '(', ')');
				if(c == -1) break;
				toks->cur = c + 1;
			}
			continue;
		}
		if(tk->topch == '(') {
			c = findclose(toks, c+1, '(', ')');
			if(c == -1) break;
			continue;
		}
		if(tk->topch == '{') {
			c = findclose(toks, c+1, '{', '}');
			if(c == -1) break;
			continue;
		}
		if(tk->topch == '[') {
			c = findclose(toks, c+1, '[', ']');
			if(c == -1) break;
			continue;
		}
		return c;
	}
	return toks->eol;
}

static void ERROR_SyntaxErrorRule(CTX ctx, kToken *rule, toks_t *toks)
{

}

/* -- */

static int checkStmtKey(toks_t *rule);
static int isDeterministic(toks_t *rule);
static int isSymbolRule(toks_t *rule);
static int isTermRule(toks_t *rule);
static int isOptionalRule(toks_t *rule);
static int matchSymbolRule(toks_t *rule, toks_t *toks);
static int matchTermRule(toks_t *rule, toks_t *toks);
static kExpr* matchExpr(CTX ctx, toks_t *toks);

static int matchLeft(toks_t *rule, toks_t *toks)
{
	toks_t sub;
	while(hasN(rule, 0)) {
		checkStmtKey(rule);
		if(isSymbolRule(rule)) {  // "is"
			if(!matchSymbolRule(rule, toks)) {
				if(toks->status == _Deterministic) {
					ERROR_SyntaxErrorRule(toks->ctx, tkN(rule, 0), toks);
					toks->status = FoundError;
				}
				return 0;
			}
			incN(rule, 1);
		}
		else if(isTermRule(rule)) {  // term
			if(!matchTermRule(rule, toks)) {
				if(toks->status == _Deterministic) {
					ERROR_SyntaxErrorRule(toks->ctx, tkN(rule, 0), toks);
					toks->status = FoundError;
				}
				return 0;
			}
			incN(rule, 1);
		}
		else if(isDeterministic(rule)) {
			toks->status = _Deterministic;
			incN(rule, 1);
		}
		else if(isOptionalRule(rule)) {
			int rollback = toks->cur;
			subBetween(&sub, rule, '[', ']');
			if(!matchLeft(&sub, toks)) {
				toks->cur = rollback;
				rule->cur = sub.eol + 1;
				kToken *tk = tkN(rule, 0);
				if(tk->topch == '*') incN(rule, 1);
			}
			else {
				int start = rule->cur;
				rule->cur = sub.eol + 1;
				kToken *tk = tkN(rule, 0);
				if(tk->topch == '*') rule->cur = start;
			}
		}
	}
	return 1;
}

/**
sugar SugarDecl  ::= "sugar" sugarname "::=" tokens;
sugar AliasDecl  ::= "sugar" text "::="  text;
sugar "int"      ::= "Int";

sugar DeclToken  ::= type name "," name ...
sugar DeclToken  ::= ... "+="

sugar MethodDecl ::= type [cname "."] name "(" params ")" [block];
sugar ReturnStmt ::= "return" [expr]
sugar IfStmt     ::= "if" "(" expr ")" block "else" block;
sugar DeclStmt   ::= type name ["=" expr];
sugar EqualExpr  ::= leftexpr  "=" expr;
sugar MethodCallExpr ::= expr "." name "(" expr ["," expr] ")";
sugar FuncCallExpr   ::= name "(" expr ["," expr] ")";
sugar NullTerm       ::= "null"
sugar TrueTerm       ::= "true"
sugar FalseTerm      ::= "false"
sugar IntTerm        ::= intnum;

sugar opAdd          ::= expr "+" expr
sugar opPlus         ::= "+" expr

sugar InterfaceFuncDecl   ::= type name "(" params ")";
sugar InterfaceBlock      ::= InterfaceFuncDecl
sugar InterfaceDecl       ::= "interface" cname InterfaceBlock
**/

static int matchStmt(CTX ctx, toks_t *toks, kStmt *stmt)
{
	kLang *lang = toks->lang;
	int i, toks_cur = toks->cur; int toks_eol = toks->eol;
	toks_t rulebuf;
	while(lang != NULL) {
		kArray *l = DP(lang)->stmtRulesNULL;
		if(l != NULL) {
			toks->status = _Matching;
			for(i = 0; i < knh_Array_size(l); i++) {
				kSugar *s = (kSugar*)l->list[i];
				toks_t *rule = new_toks(ctx, &rulebuf, s->rules, toks->lang, toks->ns);
				toks->cur = toks_cur; toks->eol = toks_eol;
				rule->stmt = stmt;
				if(matchLeft(rule, toks)) {
					KNH_SETv(ctx, stmt->key, s->key);
					return 1;
				}
				else {
					//Stmt_done(ctx, stmt);
				}
			}
		}
		lang = lang->parentNULL;
	}
	/* ExprStmt */ {
		toks->cur = toks_cur; toks->eol = toks_eol;
		kExpr *expr = matchExpr(ctx, toks);
		if(expr != NULL) {
			KNH_SETv(ctx, stmt->key, new_T("ExprStmt"));
			knh_DictMap_set(ctx, stmt->clauseDictMap, new_T("expr"), expr);
		}
	}
	return 0;
}

/* ------ */

// @Ensure #(n < 1)

static kbool_t skipAnotation(toks_t *toks)
{
	int c = toks->cur;
	for(;c < toks->eol; c++) {
		kToken *tk = toks->list->tokens[c];
		if(tk->token == TK_WHITESPACE) continue;
		if(tk->token == TK_META) {
			kToken *tk1 = tkN(toks, 1);
			if(tk1->topch == '(') {
				c = findclose(toks, c+2, '(', ')');
				if(c == -1) return 0;
			}
			toks->cur = c + 1;
			continue;
		}
		break;
	}
	return 1;
}

static void Stmt_addAnnotation(CTX ctx, kStmt *stmt, toks_t *toks)
{
	int c = toks->cur;
	for(;c < toks->eol; c++) {
		kToken *tk = toks->list->tokens[c];
		if(tk->token == TK_WHITESPACE) continue;
		if(tk->token == TK_META) {
			kToken *tk1 = tkN(toks, 1);
			knh_DictMap_set(ctx, stmt->clauseDictMap, tk->text, KNH_TRUE);
			if(tk1->topch == '(') {
				// TODO @Annotation(option)
				c = findclose(toks, c+2, '(', ')');
			}
			continue;
		}
	}
}

static kStmt *new_Stmt(CTX ctx, kArray *tlist, int s, int e, kLang *lang, kNameSpace *ns)
{
	kStmt *stmt = new_(Stmt);
	PUSH_GCSTACK(ctx, stmt);
	toks_t toksbuf, *toks = new_toks(ctx, &toksbuf, tlist, lang, ns);
	toks->cur = s; toks->eol = e;
	stmt->uline = tkN(toks, 0)->uline;

	int kerrno = knh_errno(ctx);
	if(skipAnotation(toks)) {
		if(matchStmt(ctx, toks, stmt)) {
			toks->cur = s; toks->eol = e;
			Stmt_addAnnotation(ctx, stmt, toks);
			return stmt;
		}
	}
	knh_DictMap_set(ctx, stmt->clauseDictMap, new_T("error"), knh_strerror(ctx, kerrno));
	return stmt;
}

kBlock *new_Block(CTX ctx, kArray *tlist, int s, int e, kLang *lang, kNameSpace *ns)
{
	kBlock *bk = new_(Block);
	int i = s, indent = 0;
	PUSH_GCSTACK(ctx, bk);
	while(i < e) {
		int start;
		kToken *tk = tlist->tokens[i];
		while(tk->token == TK_INDENT) {
			if(indent == 0) indent = tk->lpos;
			i++;
			if(!(i < e)) break;
			tk = tlist->tokens[i];
		}
		start = i;
		for(; i < e; i++) {
			tk = tlist->tokens[i];
			if(tk->topch == ';') break;
			if(tk->token == TK_INDENT && tk->lpos <= indent) break;
		}
		if(start < i) {
			INIT_GCSTACK(ctx);
			kStmt *stmt = new_Stmt(ctx, tlist, start, i, lang, ns);
			knh_Array_add(ctx, bk->blocks, stmt);
			KNH_SETv(ctx, stmt->parent, bk);
			RESET_GCSTACK(ctx);
		}
		if(tk->topch == ';') i++;
	}
	return bk;
}

/* ------------------------------------------------------------------------ */

static int checkStmtKey(toks_t *rule)
{
	kToken *tk0 = tkN(rule, 0);
	kToken *tk1 = tkN(rule, 1);
	rule->key = NULL;
	if(tk0->token == TK_SYMBOL && tk1->topch == ':') {
		rule->key = tk0->text;
		rule->cur += 2;
		return 1;
	}
	return 0;
}

// sugar IfStmt ::= "if" "(" ^ expr ")"

static int isDeterministic(toks_t *rule)
{
	kToken *tk0 = tkN(rule, 0);
	return (tk0->topch == '^');
}

static int isSymbolRule(toks_t *rule)
{
	kToken *tk0 = tkN(rule, 0);
	return (tk0->token == TK_TEXT || tk0->token == TK_STEXT);
}

static int isTermRule(toks_t *rule)
{
	kToken *tk0 = tkN(rule, 0);
	return (tk0->token == TK_USYMBOL || tk0->token == TK_USYMBOL);
}

static int isOptionalRule(toks_t *rule)
{
	kToken *tk0 = tkN(rule, 0);
	return (tk0->topch == '[');
}

static int matchSymbolRule(toks_t *rule, toks_t *toks)
{
	return 1;
}

typedef kExpr* (*Fmatch)(CTX, toks_t *);
static kExpr* matchTokens(CTX ctx, toks_t *toks);
static kExpr* matchName(CTX ctx, toks_t *toks);
static kExpr* matchUName(CTX ctx, toks_t *toks);
static kExpr* matchType(CTX ctx, toks_t *toks);
static kExpr* matchExpr(CTX ctx, toks_t *toks);
static kExpr* matchBlock(CTX ctx, toks_t *toks);

static Fmatch findTermFunc(kString *termType)
{
	int ch = S_totext(termType)[0];
	switch(ch) {
	case 'b':
		if(knh_String_equals(termType, "block")) {
			return matchBlock;
		}
		break;
	case 'e':
		if(knh_String_equals(termType, "expr")) {
			return matchExpr;
		}
		break;
	case 'n':
		if(knh_String_equals(termType, "name")) {
			return matchName;
		}
		break;
	case 's':
		if(knh_String_equals(termType, "sugarname")) {
			return matchName;
		}
		break;
	case 't':
		if(knh_String_equals(termType, "tokens")) {
			return matchTokens;
		}
		if(knh_String_equals(termType, "type")) {
			return matchType;
		}
		break;
	case 'u':
		if(knh_String_equals(termType, "uname")) {
			return matchUName;
		}
		break;
	}
	return NULL;
}

static int matchTermRule(toks_t *rule, toks_t *toks)
{
	const kcontext_t *ctx = toks->ctx;
	kString *termType = tkN(rule, 0)->text;
	Fmatch match = findTermFunc(termType);
	kExpr *term = match(ctx, toks);
	if(term == NULL) {
		return 0;
	}
	else {
		DBG_ASSERT(rule->stmt != NULL);
		if(rule->key == NULL) {
			rule->key = termType;
		}
		knh_DictMap_set(ctx, rule->stmt->clauseDictMap, rule->key, term);
	}
	return 1;
}

static kExpr* new_Expr(CTX ctx, toks_t *toks, kexpr_t t, kToken *tk)
{
	kExpr *expr = new_(Expr);
	PUSH_GCSTACK(ctx, expr);
	DBG_ASSERT(tk->token != TK_NONE);
	KNH_SETv(ctx, expr->token, tk);
	expr->kexpr = t;
	return expr;
}

// sugar IntType := "int";

static kExpr* matchTokens(CTX ctx, toks_t *toks)
{
	kExpr *expr = new_Expr(ctx, toks, TEXPR_CONST, tkN(toks, 0));
	kArray *a = new_Array(ctx, CLASS_Token, (toks->eol - toks->cur));
	KNH_SETv(ctx, expr->data, a);
	int i;
	for(i=toks->cur;i < toks->eol; i++) {
		knh_Array_add(ctx, a, toks->list->tokens[i]);
	}
	toks->cur = toks->eol;
	return expr;
}

static kExpr* matchName(CTX ctx, toks_t *toks)
{
	kToken *tk0 = tkN(toks, 0);
	if(tk0->token == TK_SYMBOL) {
		kExpr *expr = new_Expr(ctx, toks, UEXPR_TOKEN, tk0);
		incN(toks, 1);
		return expr;
	}
	return NULL;
}

static kExpr* matchUName(CTX ctx, toks_t *toks)
{
	kToken *tk0 = tkN(toks, 0);
	if(tk0->token == TK_USYMBOL) {
		kExpr *expr = new_Expr(ctx, toks, UEXPR_TOKEN, tk0);
		incN(toks, 1);
		return expr;
	}
	return NULL;
}


//sugar IntType   ::= "int"
//sugar ArrayType ::= type "[" "]"

static kExpr* matchType(CTX ctx, toks_t *toks)
{
	kToken *tk0 = tkN(toks, 0);
	kExpr *expr = NULL;
	if(tk0->token == TK_USYMBOL) {
		kclass_t cid = knh_NameSpace_getcid(ctx, toks->ns, S_tobytes(tk0->text));
		if(cid != CLASS_unknown) {
			expr = new_Expr(ctx, toks, TEXPR_TYPE, tk0);
			KNH_SETv(ctx, expr->data, new_Type(ctx, cid));
			incN(toks, 1);
		}
	}
	if(expr != NULL) {

	}
	return expr;
}

static kExpr *new_SugarExpr(CTX ctx, kSugar *sgr, toks_t *toks)
{
	kExpr *expr = new_(Expr);
	expr->kexpr = TEXPR_CONST;
	DBG_ASSERT(expr == NULL);
	return expr;
}

//static kbool_t matchExprLeftRule(CTX ctx, toks_t *rule, toks_t *toks)
//{
//	toks_t sub;
//	while(hasN(rule, 0)) {
//		if(isSymbolRule(rule)) {  // "is"
//			if(matchSymbolRule(rule, toks)) {
//			}
//			incN(rule, 1);
//		}
//		else if(isTermRule(rule)) {  // term
//			if(!matchTermRule(rule, toks)) {
//				if(toks->status == _Deterministic) {
//					ERROR_SyntaxErrorRule(toks->ctx, tkN(rule, 0), toks);
//					toks->status = FoundError;
//				}
//				return 0;
//			}
//			incN(rule, 1);
//		}
//		else if(isDeterministic(rule)) {
//			toks->status = _Deterministic;
//			incN(rule, 1);
//		}
//		else if(isOptionalRule(rule)) {
//			int rollback = toks->cur;
//			subBetween(&sub, rule, '[', ']');
//			if(!matchLeft(&sub, toks)) {
//				toks->cur = rollback;
//				rule->cur = sub.eol + 1;
//				kToken *tk = tkN(rule, 0);
//				if(tk->topch == '*') incN(rule, 1);
//			}
//			else {
//				int start = rule->cur;
//				rule->cur = sub.eol + 1;
//				kToken *tk = tkN(rule, 0);
//				if(tk->topch == '*') rule->cur = start;
//			}
//		}
//	}
//	return 1;
//}

static kExpr* matchSugarExpr(CTX ctx, toks_t *toks)
{
	kLang *lang = toks->lang;
	int i, toks_cur = toks->cur; int toks_eol = toks->eol;
	toks_t rulebuf;
	while(lang != NULL) {
		kArray *l = DP(lang)->exprRulesNULL;
		if(l != NULL) {
			for(i = knh_Array_size(l) - 1; i >= 0; i--) {
				kSugar *s = (kSugar*)l->list[i];
				toks_t *rule = new_toks(ctx, &rulebuf, s->rules, toks->lang, toks->ns);
				toks->cur = toks_cur; toks->eol = toks_eol;
				if(matchLeft(rule, toks)) {
					return new_SugarExpr(ctx, s, toks);
				}
				else {
					if(toks->status == FoundError) return NULL;
				}
			}
		}
		lang = lang->parentNULL;
	}
	return NULL;
}

static kExpr *ERROR_NotTerm(CTX ctx, kToken *tk, toks_t *toks)
{
	knh_perror(ctx, 0, tk->uline, tk->lpos, "not valid term: %s", S_totext(tk->text));
	toks->status = FoundError;
	return NULL;
}

static kExpr *matchTerm(CTX ctx, toks_t *toks)
{
	kToken *tk0 = tkN(toks, 0);
	switch((int)tk0->token) {
	case TK_NONE:
	case TK_CODE:
	case TK_OPERATOR:
		break;
	case TK_INDENT:
	case TK_WHITESPACE:
		incN(toks, 1);
		return matchTerm(ctx, toks);
	case TK_SYMBOL:
	case TK_USYMBOL:
	case TK_TEXT:
	case TK_STEXT:
	case TK_INT:
	case TK_FLOAT:
	case TK_URN:   {
		incN(toks, 1);
		return new_Expr(ctx, toks, UEXPR_TOKEN, tk0);
	}
	case TK_REGEX:
	case TK_META:
	case TK_PROP:
	case TK_EXPR:
	case TK_STMT:
	case TK_BLOCK:
		break;
	}
	ERROR_NotTerm(ctx, tk0, toks);
	return NULL;
}

static kExpr* new_ConsExpr(CTX ctx, kexpr_t etype, kToken *tk)
{
	kExpr *expr = new_(Expr);
	PUSH_GCSTACK(ctx, expr);
	expr->kexpr = etype;
	KNH_SETv(ctx, expr->token, tk);
	KNH_SETv(ctx, expr->cons, new_Array0(ctx, 0));
	knh_Array_add(ctx, expr->cons, tk);
	return expr;
}

static kbool_t Expr_add(CTX ctx, kExpr *expr, kExpr *e)
{
	DBG_ASSERT(IS_Array(expr->cons));
	if(e != NULL) {
		knh_Array_add(ctx, expr->cons, e);
		return 1;
	}
	return 0;
}

static kExpr *Expr_addParams(CTX ctx, kExpr *expr, toks_t *toks)
{
	int i, start = toks->cur, level = 0;
	for(i = toks->cur; i < toks->eol; i++) {
		kToken *tk = toks->list->tokens[i];
		if(tk->topch == ',' && level == 0) {
			if(start < i) {
				toks_t subtoks;
				sub(&subtoks, toks, start, i);
				if(!Expr_add(ctx, expr, matchExpr(ctx, &subtoks))) return NULL;
				start = i + 1;
			}
			else {
				// NULL;
				// Expr_add(ctx, expr, )
			}
		}
		if(tk->topch == '(' || tk->topch == '[' || tk->topch == '{') level++;
		if(tk->topch == ')' || tk->topch == ']' || tk->topch == '}') level--;
	}
	DBG_ASSERT(level == 0);
	if(start < i) {
		toks_t subtoks;
		sub(&subtoks, toks, start, i);
		if(!Expr_add(ctx, expr, matchExpr(ctx, &subtoks))) return NULL;
	}
	return expr;
}

static kExpr* callExpr(CTX ctx, toks_t *toks, kExpr *expr, kToken *tk, kexpr_t etype)
{
	toks_t subtoks;
	if(subBetween(&subtoks, toks, '(', ')')) {
		kExpr *expr2 = new_ConsExpr(ctx, UEXPR_CALL, tk);
		Expr_add(ctx, expr2, expr);
		toks->cur = subtoks.eol + 1;
		return Expr_addParams(ctx, expr2, &subtoks);
	}
	return NULL;
}

static kExpr *ERROR_TokenExpr(CTX ctx, kToken *tk)
{
	knh_perror(ctx, ERR_, tk->uline, tk->lpos, "syntax error: %s", S_totext(tk->text));
	return NULL;
}

static kExpr* matchExprLeft(CTX ctx, toks_t *toks)
{
	kExpr *expr = matchSugarExpr(ctx, toks);
	if(expr == NULL) {
		if(toks->status == FoundError) return NULL;
		expr = matchTerm(ctx, toks);
		if(toks->status == FoundError) return NULL;
	}
	while(expr != NULL && hasN(toks, 0)) {
		kToken *tk0 = tkN(toks, 0);
		if(tk0->topch == '(') {   /* $expr() */
			expr = callExpr(ctx, toks, expr, tk0, UEXPR_CALL);
			continue;
		}
		if(tk0->topch == '.') {
			kToken *tk1 = tkN(toks, 1);
			if(tk1->token == TK_SYMBOL || tk1->token == TK_USYMBOL) {
				kToken *tk2 = tkN(toks, 2);
				if(tk2->topch == '(') {
					incN(toks, 2);
					expr = callExpr(ctx, toks, expr, tk1, UEXPR_METHOD_CALL);
				}
				else {
					kExpr *expr2 = new_ConsExpr(ctx, UEXPR_GETTER, tk1);
					Expr_add(ctx, expr2, expr);
					expr = expr2;
				}
				continue;
			}
			tk0 = tk1; // for error message
		}
		return ERROR_TokenExpr(ctx, tk0);
	}
	return expr;
}

// kDictMap*   tokenRulesNULL;

static int skipUninary(toks_t *toks, int n)
{
	//kSugar *bin = Lang_getBinary(ctx, toks->lang, S_tobytes(tk->text));
	return nextT(toks, n);
}

static int findBinaryOperator(toks_t *toks)
{
	int idx = -1, i = skipUninary(toks, toks->cur), priority = 10000;
	kToken *tkf = NULL;
	for(i = toks->cur; i < toks->eol; i = nextT(toks, i)) {
		kToken *tk = toks->list->tokens[i];
		if(tk->token == TK_OPERATOR) {
			kSugar *bin = (kSugar*)knh_DictMap_getNULL(toks->ctx, DP(toks->lang)->binaryRulesNULL, S_tobytes(tk->text));
			if(bin != NULL && bin->optnum <= priority) {
				priority = bin->optnum;
				idx = i;
				tkf = tk;
				i = skipUninary(toks, i);
			}
		}
	}
//	if(tt_found != TT_EOT) {
//		for(i = itr->c; i < itr->e; i++) {
//			if(TT_(ts[i]) == tt_found) {
//				idx = i; /* last idx */
//				if(!TT_isBINARY(tt_found)) break; /* fisrt idx */
//			}
//		}
//	}
	//DBG_P("idx=%d=<%d<%d %s", itr->c, idx, itr->e, TT__(ts[idx]->tt));
	return idx;
}

//sugar SizeExpr  ::= "|" expr "|"
//sugar IndexExpr ::= expr "[" expr "]"

static kExpr* matchExpr(CTX ctx, toks_t *toks)
{
	int idx = findBinaryOperator(toks);
	if(idx != -1) {
		toks_t ltoks, rtoks;
		sub(&ltoks, toks, toks->cur, idx);
		sub(&rtoks, toks, idx+1, toks->eol);
		kExpr *lexpr = matchExpr(ctx, &ltoks);
		kExpr *rexpr = matchExpr(ctx, &rtoks);
		kToken *tk = tkN(toks, idx);
		kExpr *expr = new_ConsExpr(ctx, UEXPR_BINARY, tk);
		if(Expr_add(ctx, expr, lexpr) && Expr_add(ctx, expr, rexpr)) {
			return expr;
		}
		return NULL;
	}
	return matchExprLeft(ctx, toks);
}

static kExpr* matchBlock(CTX ctx, toks_t *toks)
{
	toks_t sub;
	kToken *tk0 = tkN(toks, 0);
	kBlock *bk = NULL;
	if(tk0->topch == '{') {
		if(subBetween(&sub, toks, '{', '}')) {
			bk = new_Block(ctx, toks->list, sub.cur, sub.eol, toks->lang, toks->ns);
		}
	}
	else if(tk0->token == TK_CODE) {
		DBG_P("@@='''%s'''", S_totext(tk0->text));
		size_t toks_listsize = knh_Array_size(toks->list);
		tenv_t tenvbuf = {
			tk0->uline,
			toks->list,
			{S_totext(tk0->text)},
			S_totext(tk0->text),
			ctx->bufa,
			BA_size(ctx->bufa),
			3,
			toks->lang,
			_TOPLEVEL,
		};
		parse(ctx, &tenvbuf, _METHOD);
		bk = new_Block(ctx, toks->list, toks_listsize, knh_Array_size(toks->list), toks->lang, toks->ns);
		knh_Array_clear(ctx, toks->list, toks_listsize);
	}
	return (kExpr*)bk;
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
