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

	"AST_()",
	"AST_[]",
	"AST_{}",
	"AST_EXPR",
	"AST_STMT",
	"AST_BLOCK",
};

static const char *symTK(ktoken_t t)
{
	if(t <= AST_BLOCK) {
		return symTKDATA[t];
	}
	return "TK_UNKNOWN";
}

static void dumpTokenArray(CTX ctx, int nest, kArray *a, int s, int e)
{
	if(nest == 0) fprintf(stdout, "\n");
	while(s < e) {
		kToken *tk = a->tokens[s];
		int i;
		for(i = 0; i < nest; i++) {
			fputc(' ', stdout); fputc(' ', stdout);
		}
		if(IS_Array(tk->sub)) {
			fprintf(stdout, "%c\n", tk->topch);
			dumpTokenArray(ctx, nest+1, tk->sub, 0, knh_Array_size(tk->sub));
			for(i = 0; i < nest; i++) {
				fputc(' ', stdout); fputc(' ', stdout);
			}
			fprintf(stdout, "%c\n", tk->lpos);
		}
		else {
			fprintf(stdout, "TK(%d) %s %d+%d: '%s'\n", s, symTK(tk->token), (short)tk->uline, tk->lpos, S_totext(tk->text));
		}
		s++;
	}
	if(nest == 0) fprintf(stdout, "====\n");
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

static toks_t *new_toks(CTX ctx, toks_t *buf, kArray *a, int s, int e, kLang *lang, kNameSpace *ns)
{
	buf->ctx  = ctx;
	buf->list = a;
	buf->cur  = s;
	buf->eol  = e;
	buf->status  = _Init;
	buf->key  = NULL;      // rule
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
	ERROR_Expected(toks->ctx, tkS, closech, NULL);
	toks->status = FoundError;
	return -1;
}

/* -- */

static int matchTermRule(CTX ctx, kToken *ru0, toks_t *rus, toks_t *toks);
static kExpr* matchExpr(CTX ctx, toks_t *toks);

// sugar IfStmt ::= "if" "(" ^ expr ")"

static int subrule(toks_t *dst, toks_t *src, int s, int opench, int closech)
{
	int i, level = 1;
	for(i = s ; i < src->eol; i++) {
		kToken *tk = src->list->tokens[i];
		if(tk->token != TK_TEXT && tk->token != TK_STEXT) continue;
		kbytes_t t = S_tobytes(tk->text);
		if(t.text[0] == opench && t.len == 1) {
			level++;
			continue;
		}
		if(t.text[0] == closech && t.len ==1) {
			level--;
			if(level == 0) {
				sub(dst, src, s, i-1);
				return 1;
			}
		}
	}
	return 0;
}

static int matchStmtEachRule(CTX ctx, toks_t *rus, toks_t *toks, int level);

static int matchSubStmtRule(CTX ctx, toks_t* rus, toks_t *toks, kToken *tk, int opench, int closech)
{
	toks_t subrules, subtoks;
	subrule(&subrules, rus, rus->cur, opench, closech);
	new_toks(ctx, &subtoks, tk->sub, 0, knh_Array_size(tk->sub), toks->lang, toks->ns);
	int res = matchStmtEachRule(ctx, &subrules, &subtoks, 1);
	if(res == 1) {

	}
	return res;
}

static int matchSymbolRule(CTX ctx, kToken *ru0, toks_t *rus, toks_t *toks)
{
	kbytes_t t = S_tobytes(ru0->text);
	kToken *tk = tkN(toks, 0);
	if(t.len == 1) {
		if(t.text[0] == '(') {
			if(tk->token != AST_PARENTHESIS) return 0;
			return matchSubStmtRule(ctx, rus, toks, tk, '(', ')');
		}
		if(t.text[0] == '[') {
			if(tk->token != AST_BRANCET) return 0;
			return matchSubStmtRule(ctx, rus, toks, tk, '[', ']');
		}
		if(t.text[0] == '{') {
			if(tk->token != AST_BRACE) return 0;
			return matchSubStmtRule(ctx, rus, toks, tk, '{', '}');
		}
	}
	if(knh_bytes_equals(S_tobytes(ru0->text), S_tobytes(tk->text))) {
		incN(toks, +1);
		return 1;
	}
	return 0;
}

/**
sugar SugarDecl  ::= "sugar" sugarname "::=" tokens;
sugar AliasDecl  ::= "sugar" text "::="  text;
sugar "int"      ::= "Int";

sugar DeclToken  ::= type name "," name ...
sugar DeclToken  ::= ... "+="

sugar MethodDecl     ::= type [cname "."] name params [block];
sugar ReturnStmt     ::= "return" [expr]
sugar IfStmt         ::= "if" "(" expr ")" block "else" block;
sugar DeclStmt       ::= type name ["=" expr];
sugar EqualExpr      ::= leftexpr  "=" expr;
sugar MethodCallExpr ::= expr "." name "(" expr ["," expr] ")";
sugar FuncCallExpr   ::= name "(" expr ["," expr] ")";
sugar NullTerm       ::= "null"
sugar TrueTerm       ::= "true"
sugar FalseTerm      ::= "false"
sugar IntTerm        ::= intnum;

sugar AddOp          ::= expr "+" expr
sugar PlusOp         ::= "+" expr

sugar InterfaceFuncDecl   ::= type name "(" params ")";
sugar InterfaceBlock      ::= InterfaceFuncDecl
sugar InterfaceDecl       ::= "interface" cname InterfaceBlock
**/

static kbool_t skipWhiteSpace(toks_t *toks)
{
	int c = toks->cur, foundMETA = 0;
	for(;c < toks->eol; c++) {
		kToken *tk = toks->list->tokens[c];
		if(tk->token == TK_WHITESPACE) continue;
		if(tk->token == TK_INDENT) continue;
		if(tk->token == TK_META) {
			foundMETA = 1;
			knh_perror(toks->ctx, WARN_, tk->uline, tk->lpos, "ignored %s", kToken_s(tk));
			continue;
		}
		if(foundMETA && tk->token == AST_PARENTHESIS) {
			foundMETA = 0;
			continue;
		}
		toks->cur = c;
		return 1;
	}
	return 0;
}

static void ERROR_StmtRuleLine(CTX ctx, kToken *ru, toks_t *toks)
{
	if(toks->status == _Deterministic) {
		toks->status = FoundError;
		kToken *tk = toks->list->tokens[toks->eol-1];
		knh_perror(ctx, ERR_, tk->uline, 0, "%s is required", S_totext(ru->text));
	}
}

static void ERROR_StmtRuleToken(CTX ctx, kToken *ru, toks_t *toks)
{
	if(toks->status == _Deterministic) {
		toks->status = FoundError;
		kToken *tk = toks->list->tokens[toks->cur];
		knh_perror(ctx, ERR_, tk->uline, tk->lpos, "%s is required, but %s is given", S_totext(ru->text), kToken_s(tk));
	}
}

static void WARN_StmtRuleIgnored(CTX ctx, toks_t *toks)
{
	if(toks->status == _Deterministic) {
		kToken *tkS = toks->list->tokens[toks->cur];
		kToken *tkE = toks->list->tokens[toks->eol-1];
		if(tkS == tkE) {
			knh_perror(ctx, WARN_, tkS->uline, tkS->lpos, "ignored %s", kToken_s(tkS));
		}
		else {
			knh_perror(ctx, WARN_, tkS->uline, tkS->lpos, "ignored %s .. %s", kToken_s(tkS), kToken_s(tkE));
		}
	}
}

static int matchStmtEachRule(CTX ctx, toks_t *rus, toks_t *toks, int level)
{
	while(hasN(rus, 0)) {
		kToken *ru0 = tkN(rus, 0);
		//DBG_P("rule->cur=%d, rule->eol=%d, toks->cur=%d, toks->eol=%d", rule->cur, rule->eol, toks->cur, toks->eol);
		incN(rus, 1);
		if(ru0->token == TK_SYMBOL && tkN(rus, 1)->topch == ':') {
			rus->key = ru0->text;
			incN(rus, 1);
			continue;
		}
		if(ru0->topch == '^') {  // deterministic
			DBG_P("Moving on Deterministic");
			toks->status = _Deterministic;
			continue;
		}
		if(ru0->topch == '[') {
			int rollback = toks->cur;
			int c = findclose(rus, rus->cur, '[', ']');
			KNH_ASSERT(c != -1);
			toks_t srule;
			sub(&srule, rus, rus->cur, c);
			srule.status = _Matching;
			if(matchStmtEachRule(ctx, &srule, toks, level+1)) {
//				int start = rule->cur;
				rus->cur = c + 1;
//				kToken *tk = tkN(rule, 0);
//				if(tk->topch == '*') rule->cur = start;
			}
			else {
				toks->cur = rollback;
				rus->cur = c + 1;
//				kToken *tk = tkN(rule, 0);
//				if(tk->topch == '*') incN(rule, 1);
			}
			continue;
		}
		if(!skipWhiteSpace(toks)) {
			ERROR_StmtRuleLine(ctx, ru0, toks);
			return 0;
		}
		DBG_P("Trying matching '%s' with %s ..", kToken_s(tkN(toks, 0)), S_totext(ru0->text));
		if(ru0->token == TK_TEXT) {  // "if"
			if(!matchSymbolRule(ctx, ru0, rus, toks)) {
				ERROR_StmtRuleToken(ctx, ru0, toks);
				return 0;
			}
			continue;
		}
		if(ru0->token == TK_SYMBOL || ru0->token == TK_USYMBOL) {  //expr
			if(!matchTermRule(ctx, ru0, rus, toks)) {
				ERROR_StmtRuleToken(ctx, ru0, toks);
				return 0;
			}
			rus->key = NULL;
			continue;
		}
		DBG_ABORT("Undefined Rule");
	}
	DBG_P("E rule->cur=%d, rule->eol=%d, toks->cur=%d, toks->eol=%d", rus->cur, rus->eol, toks->cur, toks->eol);
	if(hasN(toks, 0) && level == 0) {
		WARN_StmtRuleIgnored(ctx, toks);
		return 0;
	}
	return 1;
}

static int matchStmtRule(CTX ctx, toks_t *toks, kStmt *stmt)
{
	kLang *lang = toks->lang;
	int i, toks_cur = toks->cur, toks_eol = toks->eol;
	while(lang != NULL) {
		kArray *l = DP(lang)->stmtRulesNULL;
		if(l != NULL) {
			for(i = 0; i < knh_Array_size(l); i++) {
				kSugar *sgr = (kSugar*)l->list[i];
				toks_t rusbuf, *rus = new_toks(ctx, &rusbuf, sgr->rules, 0, knh_Array_size(sgr->rules), toks->lang, toks->ns);
				toks->cur = toks_cur; toks->eol = toks_eol;
				toks->status = _Matching;
				rus->stmt = stmt;
				DBG_P("%s: trying to match", S_totext(sgr->key));
				if(matchStmtEachRule(ctx, rus, toks, 0)) {
					DBG_P("matched: %s", S_totext(sgr->key));
					knh_write_Object(ctx, KNH_STDERR, UPCAST(sgr->rules), FMT_dump);
					KNH_SETv(ctx, stmt->key, sgr->key);
					return 1;
				}
				else {
					DBG_P("mismatched: %s", S_totext(sgr->key));
					DBG_ASSERT(toks->status != _Deterministic);
					if(toks->status == FoundError) {
						return 0;
					}
				}
			}
		}
		lang = lang->parentNULL;
	}
	/* ExprStmt */ {
		DBG_P("** ExprStmt **");
		toks->cur = toks_cur; toks->eol = toks_eol;
		kExpr *expr = matchExpr(ctx, toks);
		if(expr != NULL) {
			KNH_SETv(ctx, stmt->key, new_T("ExprStmt"));
			knh_DictMap_set(ctx, stmt->clauseDictMap, new_T("expr"), expr);
		}
	}
	return 0;
}

static kbool_t skipAnotation(toks_t *toks);
static void Stmt_addAnnotation(CTX ctx, kStmt *stmt, toks_t *toks);

static kStmt *Block_addNewStmt(CTX ctx, kBlock *bk, toks_t *toks)
{
	int toks_cur = toks->cur, toks_eol = toks->eol;
	kStmt *stmt = new_(Stmt);
	knh_Array_add(ctx, bk->blocks, stmt);
	KNH_SETv(ctx, stmt->parent, bk);
	stmt->uline = tkN(toks, 0)->uline;
	int kerrno = knh_errno(ctx);
	if(skipAnotation(toks)) {
		if(matchStmtRule(ctx, toks, stmt)) {
			toks->cur = toks_cur; toks->eol = toks_eol;
			Stmt_addAnnotation(ctx, stmt, toks);
			return stmt;
		}
	}
	DBG_P("Found Stmt Error");
	knh_DictMap_set(ctx, stmt->clauseDictMap, new_T("error"), knh_strerror(ctx, kerrno));
	return stmt;
}

/* ------ */

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

static int makeTree(CTX ctx, kArray *tsrc, ktoken_t tt, int s, int e, int closech, kArray *tdst)
{
	kToken *tk = tsrc->tokens[s];
	kToken *tkp = new_(Token);
	tkp->token = tt; tkp->uline = tk->uline; tkp->topch = tk->topch; tkp->lpos = closech;
	KNH_SETv(ctx, tkp->sub, new_Array0(ctx, 0));
	knh_Array_add(ctx, tdst, tkp);
	{
		int i;
		for(i = s + 1; i < e; i++) {
			kToken *tk = tsrc->tokens[i];
			if(tk->topch == '(') { i = makeTree(ctx, tsrc, AST_PARENTHESIS, i, e, ')', tkp->sub); continue; }
			if(tk->topch == '[') { i = makeTree(ctx, tsrc, AST_BRANCET, i, e, ']', tkp->sub); continue; }
			if(tk->topch == '{') { i = makeTree(ctx, tsrc, AST_BRACE, i, e, '}', tkp->sub); continue; }
			if(tk->topch == closech) {
				return i;
			}
			if(tk->token == TK_INDENT && closech != '}') continue;  // remove INDENT;
			knh_Array_add(ctx, tkp->sub, tk);
		}
	}
	/* syntax error */ {
		ERROR_Expected(ctx, tsrc->tokens[e-1], closech, NULL);
	}
	return e;
}

kBlock *new_Block(CTX ctx, kArray *tlist, int s, int e, kLang *lang, kNameSpace *ns)
{
	kBlock *bk = new_(Block);
	PUSH_GCSTACK(ctx, bk);
	int i = s, indent = 0, atop = knh_Array_size(tlist), prevMeta = 0;
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
			if(tk->token == TK_META) {           // @Const
				prevMeta = 1;                    // function .. is the same line
				knh_Array_add(ctx, tlist, tk);
				continue;
			}
			if(tk->topch == '(') {
				i = makeTree(ctx, tlist, AST_PARENTHESIS, i, e, ')', tlist);
				continue;
			}
			if(tk->token == TK_INDENT) {
				if(!prevMeta && tk->lpos <= indent) break;
				continue;
			}
			prevMeta = 0;
			if(tk->topch == '[') { i = makeTree(ctx, tlist, AST_BRANCET, i, e, ']', tlist); continue; }
			if(tk->topch == '{') { i = makeTree(ctx, tlist, AST_BRACE, i, e, '}', tlist); continue; }
			if(tk->topch == ';') break;
			knh_Array_add(ctx, tlist, tk);
		}
		if(knh_Array_size(tlist) > atop) {
			toks_t tokbuf, *ptoks = new_toks(ctx, &tokbuf, tlist, atop, knh_Array_size(tlist), lang, ns);
			dumpTokenArray(ctx, 0, tlist, atop, knh_Array_size(tlist));
			Block_addNewStmt(ctx, bk, ptoks);
			if(tk->topch == ';') i++;
			knh_Array_clear(ctx, tlist, atop);
			continue;
		}
		break;
	}
	return bk;
}

/* ------------------------------------------------------------------------ */

static kExpr* new_Expr(CTX ctx, kexpr_t t, kToken *tk)
{
	kExpr *expr = new_(Expr);
	PUSH_GCSTACK(ctx, expr);
	DBG_ASSERT(tk->token != TK_NONE);
	KNH_SETv(ctx, expr->token, tk);
	expr->kexpr = t;
	return expr;
}

static kExpr* Expr_toCONST(CTX ctx, kExpr *expr, Object *data)
{
	KNH_SETv(ctx, expr->data, data);
	expr->kexpr = TEXPR_CONST;
	expr->type = O_cid(data);
	return expr;
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

typedef int (*Fis)(kToken *tk);

static int isCOMMA(kToken *tk)
{
	return (tk->topch == ',');
}

static int countN(toks_t *toks, Fis f)
{
	int i, c = 0;
	for(i = toks->cur; i < toks->eol; i++) {
		kToken *tk = toks->list->tokens[i];
		if(f(tk)) c++;
	}
	return c;
}

static kExpr *Expr_addParams(CTX ctx, kExpr *expr, toks_t *toks)
{
	int i, start = toks->cur, level = 0;
	for(i = toks->cur; i < toks->eol; i++) {
		kToken *tk = toks->list->tokens[i];
		if(tk->topch == ',') {
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
	}
	DBG_ASSERT(level == 0);
	if(start < i) {
		toks_t subtoks;
		sub(&subtoks, toks, start, i);
		if(!Expr_add(ctx, expr, matchExpr(ctx, &subtoks))) return NULL;
	}
	return expr;
}

/* ------------------------------------------------------------------------ */

typedef kExpr* (*Fmatch)(CTX, toks_t *);
static kExpr* matchTokens(CTX ctx, toks_t *toks);
static kExpr* matchName(CTX ctx, toks_t *toks);
static kExpr* matchUName(CTX ctx, toks_t *toks);
static kExpr* matchType(CTX ctx, toks_t *toks);
static kExpr* matchExpr(CTX ctx, toks_t *toks);
static kExpr* matchParamBlock(CTX ctx, toks_t *toks);
static kExpr* matchBlock1(CTX ctx, toks_t *toks);
static kExpr* matchBlock(CTX ctx, toks_t *toks);
static kExpr* matchBody(CTX ctx, toks_t *toks);

static kExpr* matchUNKNOWN(CTX ctx, toks_t *toks)
{
	DBG_P("unknown term");
	return NULL;
}

#define return_if(F, N) if(knh_String_equals(termType, N)) return F

static Fmatch findTermFunc(kString *termType)
{
	int ch = S_totext(termType)[0];
	switch(ch) {
	case 'b':
		return_if(matchBody,  "body");
		return_if(matchBlock, "block");
		return_if(matchBlock1, "block1");
		break;
	case 'e':
		return_if(matchExpr,  "expr");
		break;
	case 'n':
		return_if(matchName,  "name");
		break;
	case 'p':
		return_if(matchParamBlock,  "param");
		return_if(matchParamBlock,  "params");
		break;
	case 's':
		return_if(matchName,  "sugarname");
		break;
	case 't':
		return_if(matchType,  "type");
		return_if(matchTokens, "tokens");
		break;
	case 'u':
		return_if(matchUName,  "uname");
		break;
	}
	return matchUNKNOWN;
}

static int matchTermRule(CTX ctx, kToken *ru0, toks_t *rus, toks_t *toks)
{
	kString *termType = ru0->text;
	DBG_P("termType: %s", S_totext(termType));
	Fmatch fmatch = findTermFunc(termType);
	kExpr *term = fmatch(ctx, toks);
	if(term != NULL) {
		if(rus->key == NULL) {
			rus->key = termType;
		}
		DBG_ASSERT(rus->stmt != NULL);
		knh_DictMap_set(ctx, rus->stmt->clauseDictMap, rus->key, term);
		DBG_P("*** key: %s   value: %s ***", S_totext(rus->key), CLASS__(O_cid(term)));
		return 1;
	}
	return 0;
}

// sugar IntType := "int";

static kExpr* matchTokens(CTX ctx, toks_t *toks)
{
	kExpr *expr = new_Expr(ctx, TEXPR_CONST, tkN(toks, 0));
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
		kExpr *expr = new_Expr(ctx, UEXPR_TOKEN, tk0);
		incN(toks, 1);
		return expr;
	}
	return NULL;
}

static kExpr* matchUName(CTX ctx, toks_t *toks)
{
	kToken *tk0 = tkN(toks, 0);
	if(tk0->token == TK_USYMBOL) {
		kExpr *expr = new_Expr(ctx, UEXPR_TOKEN, tk0);
		incN(toks, 1);
		return expr;
	}
	return NULL;
}

static kExpr* Expr_addTypeParam(CTX ctx, kExpr *expr, kToken *tk0)
{
	DBG_ASSERT(tk0->token == AST_BRANCET);
	TODO();
	return expr;
}

//sugar IntType   ::= "int"
//sugar ArrayType ::= type "[" "]"

static kExpr* matchType(CTX ctx, toks_t *toks)
{
	kToken *tk0 = tkN(toks, 0);
	kExpr *expr = NULL;
	kclass_t cid;
	if(tk0->token == TK_USYMBOL) {
		cid = knh_NameSpace_getcid(ctx, toks->ns, S_tobytes(tk0->text));
		if(cid != CLASS_unknown) {
			expr = new_Expr(ctx, TEXPR_TYPE, tk0);
			KNH_SETv(ctx, expr->data, new_Type(ctx, cid));
			incN(toks, 1);
		}
	}
	if(expr == NULL) {
		return NULL;
	}
	tk0 = tkN(toks, 0);
	while(tk0->token == AST_BRANCET) {
		expr = Expr_addTypeParam(ctx, expr, tk0);
		incN(toks, 1);
		tk0 = tkN(toks, 0);
	}
	return expr;
}

static kExpr *ERROR_NotTerm(CTX ctx, kToken *tk, toks_t *toks)
{
	knh_perror(ctx, 0, tk->uline, tk->lpos, "not valid term: %s", S_totext(tk->text));
	toks->status = FoundError;
	return NULL;
}

static kExpr *matchSYMBOL(CTX ctx, kToken *tk0)
{
	kbytes_t t = S_tobytes(tk0->text);
	if(t.buf[0] == 'n' && t.buf[1] == 'u' && t.buf[2] == 'l' && t.buf[3] == 'l' && t.buf[4] == 0) {
		return new_Expr(ctx, UEXPR_NULL, tk0);
	}
	kExpr *expr = new_Expr(ctx, UEXPR_TOKEN, tk0);
	if(t.buf[0] == 't' && t.buf[1] == 'r' && t.buf[2] == 'u' && t.buf[3] == 'e' && t.buf[4] == 0) {
		return Expr_toCONST(ctx, expr, KNH_TRUE);
	}
	if(t.buf[0] == 'f' && t.buf[1] == 'a' && t.buf[2] == 'l' && t.buf[3] == 's' && t.buf[4] == 'e' && t.buf[5] == 0) {
		return Expr_toCONST(ctx, expr, KNH_FALSE);
	}
	return expr;
}

static kExpr *matchPARENTHESIS(CTX ctx, kToken *tk0, toks_t *toks)
{
	toks_t pbuf, *ptoks = new_toks(ctx, &pbuf, tk0->sub, 0, knh_Array_size(tk0->sub), toks->lang, toks->ns);
	int c = countN(ptoks, isCOMMA);
	if(c == 0) {
		return matchExpr(ctx, ptoks);
	}
	else {
		TODO();
	}
	return NULL;
}

static kExpr *matchTerm(CTX ctx, toks_t *toks)
{
	kToken *tk0 = tkN(toks, 0);
	incN(toks, 1);
	switch((int)tk0->token) {
	case TK_NONE:
	case TK_CODE:
	case TK_OPERATOR:    break;
	case TK_INDENT:
	case TK_WHITESPACE:  return matchTerm(ctx, toks);
	case TK_SYMBOL:      return matchSYMBOL(ctx, tk0);
	case TK_USYMBOL:
	case TK_TEXT:
	case TK_STEXT:
	case TK_INT:
	case TK_FLOAT:
	case TK_URN:   {
		return new_Expr(ctx, UEXPR_TOKEN, tk0);
	}
	case TK_REGEX:
	case TK_META:
	case TK_PROP:
	case AST_PARENTHESIS: return matchPARENTHESIS(ctx, tk0, toks);
	case AST_BRACE:
	case AST_BRANCET:
	case AST_EXPR: {
		DBG_ASSERT(IS_Expr(tk0->expr));
		return tk0->expr;
	}
	case AST_STMT: {
		DBG_ASSERT(IS_Stmt(tk0->stmt));
		return (kExpr*)tk0->stmt;
	}
	case AST_BLOCK:
		DBG_ASSERT(IS_Block(tk0->bk));
		return (kExpr*)tk0->bk;
	}
	ERROR_NotTerm(ctx, tk0, toks);
	return NULL;
}

static kExpr* matchExprLeft(CTX ctx, toks_t *toks)
{
	kExpr *expr = matchTerm(ctx, toks);
	if(toks->status == FoundError || expr == NULL) return NULL;
	while(expr != NULL && hasN(toks, 0)) {
		kToken *tk0 = tkN(toks, 0);
		incN(toks, 1);
		if(tk0->token == AST_PARENTHESIS) {  // expr (expr, expr)
			toks_t toksbuf, *ptoks = new_toks(ctx, &toksbuf, tk0->sub, 0, knh_Array_size(tk0->sub), toks->lang, toks->ns);
			kExpr *expr2 = new_ConsExpr(ctx, UEXPR_CALL, tk0);
			Expr_add(ctx, expr2, expr);
			expr = Expr_addParams(ctx, expr2, ptoks);
			continue;
		}
		if(tk0->topch == '.') {
			kToken *tk1 = tkN(toks, 1);
			if(tk1->token == TK_SYMBOL || tk1->token == TK_USYMBOL) {
				kToken *tk2 = tkN(toks, 2);
				if(tk2->token == AST_PARENTHESIS) {
					toks_t toksbuf, *ptoks = new_toks(ctx, &toksbuf, tk2->sub, 0, knh_Array_size(tk0->sub), toks->lang, toks->ns);
					kExpr *expr2 = new_ConsExpr(ctx, UEXPR_METHOD_CALL, tk1);
					Expr_add(ctx, expr2, expr);
					expr = Expr_addParams(ctx, expr2, ptoks);
					continue;
				}
				else {
					kExpr *expr2 = new_ConsExpr(ctx, UEXPR_GETTER, tk1);
					Expr_add(ctx, expr2, expr);
					expr = expr2;
					continue;
				}
			}
			return ERROR_UnexpectedToken(ctx, tk1, "symbol");
		}
		return ERROR_UnexpectedToken(ctx, tk0, ".");
	}
	return expr;
}

static void Lang_addUninary(CTX ctx, kLang *lang, kString *tok, kuintptr_t mn)
{
	if(DP(lang)->uninaryDictSetNULL == NULL) {
		KNH_INITv(DP(lang)->uninaryDictSetNULL, new_DictSet0(ctx, 0, 0/*isCase*/, "UNINARY"));
	}
	knh_DictSet_set(ctx, DP(lang)->uninaryDictSetNULL, tok, mn);
}

static kbool_t Lang_isUninary(CTX ctx, kLang *lang, kToken *tk, kmethodn_t *mn)
{
	while(lang != NULL) {
		if(DP(lang)->uninaryDictSetNULL != NULL) {
			kuintptr_t n = knh_DictSet_get(ctx, DP(lang)->uninaryDictSetNULL, S_tobytes(tk->text));
			if(n != 0) {
				*mn = (kmethodn_t)n;
				return 1;
			}
		}
		lang = lang->parentNULL;
	}
	return 0;
}

static void Lang_addBinary(CTX ctx, kLang *lang, kString *tok, kuintptr_t primn)
{
	if(DP(lang)->binaryDictSetNULL == NULL) {
		KNH_INITv(DP(lang)->binaryDictSetNULL, new_DictSet0(ctx, 0, 0/*isCase*/, "BINARY"));
	}
	//kuintptr_t n = ((pri) << (sizeof(kmethodn_t) * 2)) | mn;
	knh_DictSet_set(ctx, DP(lang)->binaryDictSetNULL, tok, primn);
}

static kbool_t Lang_isBinary(CTX ctx, kLang *lang, kToken *tk, int *pri, kmethodn_t *mn)
{
	while(lang != NULL) {
		if(DP(lang)->binaryDictSetNULL != NULL) {
			kuintptr_t n = knh_DictSet_get(ctx, DP(lang)->binaryDictSetNULL, S_tobytes(tk->text));
			if(n != 0) {
				*mn = (kmethodn_t)n;
				*pri = (int)(n >> (sizeof(kmethodn_t) * 8));
				return 1;
			}
		}
		lang = lang->parentNULL;
	}
	return 0;
}

static int skipUninaryWERR(CTX ctx, toks_t *toks, int n)
{
	int i = n;
	kmethodn_t dummy;
	for(i = n; i < toks->eol; i++) {
		kToken *tk = toks->list->tokens[i];
		if(tk->token == TK_OPERATOR) {
			if(Lang_isUninary(ctx, toks->lang, tk, &dummy)) {
				continue;
			}
			else {
				ERROR_UndefinedToken(ctx, tk, "operator");
				toks->status = FoundError;
				toks->eol = i;
			}
		}
		if(tk->token == TK_SYMBOL) {
			if(Lang_isUninary(ctx, toks->lang, tk, &dummy)) {
				continue;
			}
		}
		break;
	}
	return i;
}

//sugar SizeExpr  ::= "|" expr "|"
//sugar IndexExpr ::= expr "[" expr "]"
//sugar NewExpr   ::= "new" class "(" exprN ")"
//sugar IncExpr   ::= expr "++" $
//sugar IncExpr   ::= "++" expr

static int matchExprSugar(toks_t *rus, toks_t *toks);
static kbool_t Lang_callSugarFunc(CTX ctx, kString *key);

static kbool_t replaceExprSugar(CTX ctx, toks_t *toks)
{
	kLang *lang = toks->lang;
	int i, toks_cur = toks->cur; int toks_eol = toks->eol;
	toks_t rulebuf;
	while(lang != NULL) {
		kArray *l = DP(lang)->exprRulesNULL;
		if(l != NULL) {
			for(i = knh_Array_size(l) - 1; i >= 0; i--) {
				kSugar *s = (kSugar*)l->list[i];
				toks_t *rus = new_toks(ctx, &rulebuf, s->rules, 0, knh_Array_size(s->rules), toks->lang, toks->ns);
				toks->cur = toks_cur; toks->eol = toks_eol;
				if(matchExprSugar(rus, toks) && Lang_callSugarFunc(ctx, s->key)) {
					return 1;
				}
				else {
					if(toks->status == FoundError) return 0;
				}
			}
		}
		lang = lang->parentNULL;
	}
	return 1;
}

static int matchExprSugar(toks_t *rus, toks_t *toks)
{
	return 0;
}

static kMethod *Lang_findSugarFuncNULL(CTX ctx, kString *key)
{
	return 0;
}


// boolean sugar (Token[] src, Token[] dst) //
static kbool_t Lang_callSugarFunc(CTX ctx, kString *key)
{
	kMethod *mtd = Lang_findSugarFuncNULL(ctx, key);
	if(mtd != NULL) {

	}
	return 1;
}

static kExpr* matchUninaryExpr(CTX ctx, toks_t *toks)
{
	kmethodn_t dummy;
	kToken *tk = toks->list->tokens[toks->cur];
	replaceExprSugar(ctx, toks);
	if(Lang_isUninary(ctx, toks->lang, tk, &dummy)) {
		kExpr *expr = new_ConsExpr(ctx, UEXPR_BINARY, tk);
		incN(toks, +1);
		if(Expr_add(ctx, expr, matchUninaryExpr(ctx, toks))) {
			return expr;
		}
		return NULL;
	}
	return matchExprLeft(ctx, toks);
}

static int nextN(toks_t *toks, int n)
{
	int c = n;
	for(c = n; c < toks->eol; c++) {
		kToken *tk = toks->list->tokens[c];
		if(tk->token == TK_WHITESPACE || tk->token == TK_INDENT) continue;
		if(tk->token == TK_META) {
			tk = toks->list->tokens[c+1];
			if(tk->token == AST_PARENTHESIS || tk->token == TK_INDENT) {
				c++;
			}
			continue;
		}
		return c + 1;
	}
	return toks->eol;
}

static int findBinaryOperatorWERR(CTX ctx, toks_t *toks)
{
	int idx = -1, i = skipUninaryWERR(ctx, toks, toks->cur), priority = 10000;
	kToken *tkf = NULL;
	kmethodn_t dummy = 0;
	for(i = toks->cur; i < toks->eol; i = nextN(toks, i)) {
		kToken *tk = toks->list->tokens[i];
		if(tk->token == TK_OPERATOR || tk->token == TK_SYMBOL) {
			int pri = 0;
			if(Lang_isBinary(ctx, toks->lang, tk, &pri, &dummy) && pri <= priority) {
				priority = pri;
				idx = i;
				tkf = tk;
				i = skipUninaryWERR(ctx, toks, i+1);
			}

		}
	}
	return idx;
}

static kExpr* matchExpr(CTX ctx, toks_t *toks)
{
	int idx = findBinaryOperatorWERR(ctx, toks);
	if(toks->status == FoundError) return NULL;
	if(idx != -1) {
		DBG_P("** Found BinaryOperator: %s **", S_totext(toks->list->tokens[idx]->text));
		toks_t ltoks, rtoks;
		sub(&ltoks, toks, toks->cur, idx);
		sub(&rtoks, toks, idx+1, toks->eol);
		kExpr *lexpr = matchExpr(ctx, &ltoks);
		kExpr *rexpr = matchExpr(ctx, &rtoks);
		kExpr *expr = new_ConsExpr(ctx, UEXPR_BINARY, toks->list->tokens[idx]);
		if(Expr_add(ctx, expr, lexpr) && Expr_add(ctx, expr, rexpr)) {
			return expr;
		}
		return NULL;
	}
	return matchUninaryExpr(ctx, toks);
}

static kBlock *new_BlockParam(CTX ctx, toks_t *toks)
{
	kBlock *bk = new_(Block);
	PUSH_GCSTACK(ctx, bk);
	int i = toks->cur, e = toks->eol;
	while(i < e) {
		int start = i;
		kToken *tk = toks->list->tokens[i];
		for(; i < e; i++) {
			tk = toks->list->tokens[i];
			if(tk->topch == ',') break;
		}
		if(start < i) {
			toks_t subtoks;
			new_toks(ctx, &subtoks, toks->list, start, i, toks->lang, toks->ns);
			Block_addNewStmt(ctx, bk, &subtoks);
			if(tk->topch == ',') i++;
		}
		else {
			if(tk->topch == ',') {
				knh_perror(ctx, WARN_, tk->uline, tk->lpos, "empty");
				i++;
			}
		}
	}
	return bk;
}

static kExpr* matchParamBlock(CTX ctx, toks_t *toks)
{
	kBlock *bk = NULL;
	kToken *tk0 = tkN(toks, 0);
	if(tk0->token == AST_PARENTHESIS) {
		toks_t tokbuf, *ptoks = new_toks(ctx, &tokbuf, tk0->sub, 0, knh_Array_size(tk0->sub), toks->lang, toks->ns);
		bk = new_BlockParam(ctx, ptoks);
		incN(toks, 1);
	}
	return (kExpr*)bk;
}

static kbool_t kToken_toBRACE(CTX ctx, kToken *tk0, kLang *lang)
{
	if(tk0->token == TK_CODE) {
		INIT_GCSTACK(ctx);
		kArray *a = new_Array0(ctx, 0);
		PUSH_GCSTACK(ctx, a);
		tenv_t tenvbuf = {
				tk0->uline,
				a,
				{S_totext(tk0->text)},
				S_totext(tk0->text),
				ctx->bufa,
				BA_size(ctx->bufa),
				3,
				lang,
				0/*recur_count*/,
		};
		parse(ctx, &tenvbuf, _METHOD);
		tk0->token = AST_BRACE; tk0->topch = '{'; tk0->lpos = '}';
		KNH_SETv(ctx, tk0->sub, a);
		RESET_GCSTACK(ctx);
		return 1;
	}
	return 0;
}

static kExpr* matchBlock1(CTX ctx, toks_t *toks)
{
	kBlock *bk = NULL;
	kToken *tk0 = tkN(toks, 0);
	kToken_toBRACE(ctx, tk0, toks->lang);
	if(tk0->token == AST_BRACE) {
		bk = new_Block(ctx, tk0->sub, 0, knh_Array_size(tk0->sub), toks->lang, toks->ns);
		incN(toks, 1);
	}
	else {
		bk = new_Block(ctx, toks->list, toks->cur, toks->eol, toks->lang, toks->ns);
		toks->cur = toks->eol;
	}
	return (kExpr*)bk;
}

static kExpr* matchBlock(CTX ctx, toks_t *toks)
{
	kBlock *bk = NULL;
	kToken *tk0 = tkN(toks, 0);
	kToken_toBRACE(ctx, tk0, toks->lang);
	if(tk0->token == AST_BRACE) {
		bk = new_Block(ctx, tk0->sub, 0, knh_Array_size(tk0->sub), toks->lang, toks->ns);
		incN(toks, 1);
	}
	return (kExpr*)bk;
}

static kExpr* matchBody(CTX ctx, toks_t *toks)
{
	kToken *tk0 = tkN(toks, 0);
	if(tk0->token == TK_CODE) {
		incN(toks, 1);
		return (kExpr*)tk0;
	}
	return NULL;
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
