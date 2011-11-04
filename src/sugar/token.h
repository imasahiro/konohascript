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
/* [term] */


typedef struct {
	knh_uline_t uline;
	knh_Array_t *list;
	const knh_uchar_t *line;
	knh_Bytes_t *buf;
	size_t bufhead;
	int tab;
	knh_NameSpace_t *ns;
} tenv_t;

static void parse(CTX ctx, tenv_t *tenv, int pol);

//static int Token_startsWithExpr(CTX ctx, knh_Token_t *tkB)
//{
//	knh_Token_t *tk = Token_lastChildNULL(tkB);
//	if(tk != NULL) {
//		knh_term_t tt = TT_(tk);
//		if(tt == TT_COMMA || tt == TT_SEMICOLON || tt == TT_COLON) return 1;
//		if(tt == TT_CASE || tt == TT_RETURN || tt == TT_YIELD
//			|| tt == TT_PRINT || tt == TT_ASSERT) return 1;
//		if(tt == TT_PREV || tt == TT_NEXT) return 0;  // a++ + 1
//		if(TT_LET <= tt && tt <= TT_TSUB) return 1;
//		return 0;
//	}
//	return 1;
//}

//static knh_IntData_t MathConstINT[] = {
//	{"CODE", TK_CODE},
//	{"USYMBOL", TK_USYMBOL},
//	{"SYMBOL", TK_SYMBOL},
//	{"OPERATOR", TK_OPERATOR},
//	{"TEXT", TK_TEXT},
//	{"STEXT", TK_STEXT},
//	{"REGEX", TK_REGEX},
//	{"INT", TK_INT},
//	{"FLOAT", TK_FLOAT},
//	{"URN", TK_URN},
//	{"PROP", TK_PROP},
//	{"META", TK_META},
//	{"INDENT", TK_INDENT},
//	{"WHITESPACE", TK_WHITESPACE},
//	{NULL, 0},
//};
//
//DEFAPI(void) constToken(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
//{
//	kapi->loadClassIntConst(ctx, cid, MathConstInt);
//}


static knh_Token_t *new_Token(CTX ctx, knh_token_t tt, knh_uline_t uline, int optnum, knh_String_t *text)
{
	knh_Token_t *tk = new_(Token);
	tk->token = tt;
	tk->uline = uline;
	tk->optnum = optnum;
	KNH_SETv(ctx, tk->text, text);
	return tk;
}

static void addToken(CTX ctx, tenv_t *tenv, knh_Token_t *tk)
{
	knh_Array_add(ctx, tenv->list, tk);

}

static size_t skipLine(CTX ctx, tenv_t *tenv, size_t pos)
{
	int ch;
	while((ch = tenv->line[pos++]) != 0) {
		if(ch == '\n') {
			tenv->uline += 1;
			return pos;
		}
	}
	return pos-1;/*EOF*/
}

static size_t skipComment(CTX ctx, tenv_t *tenv, size_t pos)
{
	int ch, prev = 0, level = 1;
	while((ch = tenv->line[pos++]) != 0) {
		if(ch == '\n') {
			tenv->uline += 1;
		}
		if(prev == '*' && ch == '/') {
			level--;
			if(level == 0) break;
		}else if(prev == '/' && ch == '*') {
			level++;
		}
		prev = ch;
	}
	return pos-1;/*EOF*/
}

static size_t skipQuote(CTX ctx, tenv_t *tenv, size_t pos, int quote)
{
	int ch, prev = 0;
	while((ch = tenv->line[pos++]) != 0) {
		if(ch == '\n') {
			tenv->uline += 1;
		}
		if(ch == quote) {
			if(prev == '\\') continue;
			return pos;
		}
	}
	return pos-1;/*EOF*/
}

#define skipURN(ctx, tenv, pos)  addURN(ctx, tenv, pos, pos, 1)

static int addURN(CTX ctx, tenv_t *tenv, size_t pos, size_t tok_start, int skip)
{
	int ch, pol = K_SPOLICY_ASCII;
	while((ch = tenv->line[pos++]) != 0) {
		switch(ch) {
			case '\n': case '\r': case ' ':  case '\t': case ';': case ',':
			case '\'': case '"': case '`':
			case ')': case '}': case ']':
			case '(': case '{': case '[':
				break;
		}
		if(ch > 0) {
			pol = K_SPOLICY_UTF8;
		}
	}
	if(!skip) {
		knh_String_t *text = new_String2(ctx, CLASS_String, (const char*)tenv->line+tok_start, ((pos-1)-tok_start), pol);
		addToken(ctx, tenv, new_Token(ctx, TK_URN, tenv->uline, 0, text));
	}
	return pos-1;
}

static size_t addBlock(CTX ctx, tenv_t *tenv, size_t pos)
{
	int c, this_indent = 0, ch, prev = '{', level = 1;
	size_t tok_start = pos;
	DBG_P("pos =%d", pos);
	while((ch = tenv->line[pos++]) != 0) {
		L_STARTLINE:;
		if(ch == '}' && prev != '\\') {
			level--;
			if(level == 0) {
				knh_String_t *text = new_String2(ctx, CLASS_String, (const char*)tenv->line + tok_start, ((pos - 1)-tok_start), K_SPOLICY_POOLNEVER);
				addToken(ctx, tenv, new_Token(ctx, TK_CODE, tenv->uline, 0, text));
				return pos;
			}
		}
		if(ch == '{' && prev != '\\') {
			level++;
		}
		else if(prev == ':' && !(ch == ' ' || ch == '\t')) {
			pos = skipURN(ctx, tenv, pos); prev = 0; continue;
		}
		else if((prev == '#' && ch == '#') || (prev == '/' && ch == '/')) {
			pos = skipLine(ctx, tenv, pos); prev = 0; continue;
		}
		else if(ch == '"' || ch == '`' || ch == '\'') {
			pos = skipQuote(ctx, tenv, pos, ch); prev = 0; continue;
		}
		else if(prev == '/' && ch == '*') {
			pos = skipComment(ctx, tenv, pos); prev = 0; continue;
		}
		prev = ch;
		if(ch == '\n') {
			tenv->uline +=1;
			prev = ch;
			break;
		}
	}

	c = 0;
	while((ch = tenv->line[pos++]) != 0) {
		if(ch == '\t') { c += tenv->tab; continue; }
		if(ch == ' ') { c += 1; continue; }
		break;
	}
	if(ch != 0) {
		if(this_indent == 0 && c > 0) this_indent = c;
		goto L_STARTLINE;
	}
	return pos-1;
}

static knh_String_t *knh_NameSpace_getAliasNULL(CTX ctx, knh_NameSpace_t *ns, const char *s, size_t len)
{
	knh_bytes_t t = {{s}, len};
	while(ns != NULL) {
		if(DP(ns)->aliasRulesNULL != NULL) {
			knh_Object_t *alias = knh_DictMap_getNULL(ctx, DP(ns)->aliasRulesNULL, t);
			if(alias != NULL) return (knh_String_t*)alias;
		}
		ns = ns->parentNULL;
	}
	return NULL;
}

static void addSymbol(CTX ctx, tenv_t *tenv, size_t s, size_t e)
{
	if(s < e) {
		if(tenv->ns != NULL) {  // "int" => "Int"
			knh_String_t *alias = knh_NameSpace_getAliasNULL(ctx, tenv->ns, (const char*)tenv->line + s, (e-s));
			if(alias != NULL) {
				tenv_t tenvbuf = {
					tenv->uline,
					tenv->list,
					(const knh_uchar_t *)S_totext(alias),
					tenv->buf,
					tenv->bufhead,
					tenv->tab,
					tenv->ns,    // set NULL if you want to stop the recursion.
				};
				parse(ctx, &tenvbuf, 0);
				return;
			}
		}
		knh_String_t *text = new_String2(ctx, CLASS_String, (const char*)tenv->line + s, (e-s), K_SPOLICY_ASCII|K_SPOLICY_POOLALWAYS);
		int ttype = (isupper(S_totext(text)[0])) ? TK_USYMBOL : TK_SYMBOL;
		addToken(ctx, tenv, new_Token(ctx, ttype, tenv->uline, 0, text));
	}
}

static size_t addQuoteEsc(CTX ctx, tenv_t *tenv, size_t pos)
{
	int ch = tenv->line[pos++];
	if(ch == 'n') ch = '\n';
	else if(ch == 't') ch = '\t';
	else if(ch == 'r') ch = '\r';
	else if(ch == 0) return pos-1;
	knh_Bytes_putc(ctx, tenv->buf, ch);
	return pos;
}

static size_t addQuote(CTX ctx, tenv_t *tenv, size_t pos, int quote)
{
	int ch, isTriple = 0;
	if(tenv->line[pos] == quote && tenv->line[pos+1] == quote) {
		if(tenv->line[pos+2] == '\n') pos += 3; else pos += 2;
		isTriple = 1;
	}
	else if(quote == '#' && tenv->line[pos] == '#') {
		if(tenv->line[pos+1] == ' ') pos += 2; else pos += 1;
		quote = '\n';
	}
	size_t tok_start = pos;
	while((ch = tenv->line[pos++]) != 0) {
		if(ch == '\n') {
			if(!isTriple || quote != '\n') {
				WARN_MustCloseWith(ctx, /*tenv->uline, */quote);
			}
			tenv->uline += 1;
		}
		if(ch == '\\') {
			pos = addQuoteEsc(ctx, tenv, pos);
			continue;
		}
		// %s{a}
		if(ch == '%') {

		}
		if(ch == quote) {
			if(!isTriple || (pos-3 >= tok_start && tenv->line[pos-2] == quote && tenv->line[pos-3] == quote)) {
				knh_String_t *text = new_String2(ctx, CLASS_String, BA_totext(tenv->buf), BA_size(tenv->buf), 0);
				int ttype = (quote == '"') ? TK_TEXT : TK_STEXT;
				addToken(ctx, tenv, new_Token(ctx, ttype, tenv->uline, 0, text));
				knh_Bytes_clear(tenv->buf, tenv->bufhead);
				return pos;
			}
		}
		knh_Bytes_putc(ctx, tenv->buf, ch);
	}
	return pos-1;
}

static size_t addRawQuote(CTX ctx, tenv_t *tenv, size_t pos, int quote)
{
	int ch, isTriple = 0;
	if(tenv->line[pos] == quote && tenv->line[pos+1] == quote) {
		if(tenv->line[pos+2] == '\n') pos += 3; else pos += 2;
		isTriple = 1;
	}
	else if(quote == '#' && tenv->line[pos] == '#') {
		if(tenv->line[pos+1] == ' ') pos += 2; else pos += 1;
		quote = '\n';
	}
	size_t tok_start = pos;
	while((ch = tenv->line[pos++]) != 0) {
		if(ch == '\n') {
			if(!isTriple || quote != '\n') {
				WARN_MustCloseWith(ctx, /*tenv->uline, */quote);
			}
			tenv->uline += 1;
		}
		if(ch == quote) {
			if(!isTriple || (pos-3 >= tok_start && tenv->line[pos-2] == quote && tenv->line[pos-3] == quote)) {
				knh_String_t *text = new_String2(ctx, CLASS_String, (const char*)tenv->line + tok_start, (pos-1)-tok_start, 0);
				int ttype = (quote == '"') ? TK_TEXT : TK_STEXT;
				addToken(ctx, tenv, new_Token(ctx, ttype, tenv->uline, 0, text));
				return pos;
			}
		}
	}
	return pos-1;
}

static size_t checkRegex(CTX ctx, tenv_t *tenv, size_t pos)
{
	if(pos == 1) return 1;
	int i, ch,  prev = tenv->line[pos-2], next = tenv->line[pos];
	for(i = pos - 2; i >= 0; i--) {
		ch = tenv->line[i];
		if(ch == ' ' || ch == '\t') continue;
		switch(ch) {
			case '\n': case '=': case ',': case ':':
			case '(': case ')': case '[': case ']':
			case '{': case '}': case ';':
			case '+': case '-': case '*':
			case '<': case '>': case '%': case '$':
			case '!': case '&': case '?':
				return 1;  // regex
		}
	}
	int p=0, p2=0, p3 = 0;
	while((ch = tenv->line[pos++]) != '/') {
		if(ch > 127) return 1; // non ascii
		switch(ch) {
			case 0: case '\n': case ' ': return 0;  // Not
			case '(':  p++;  break;
			case '[':  p2++; break;
			case '{':  p3++; break;
			case ')':  p--; if(p < 0) return 0;   break; // Not
			case ']':  p2--; if(p2 < 0) return 0; break; // Not
			case '}':  p3--; if(p3 < 0) return 0; break; // Not
			case '\\':  return 1; // regex;
		}
	}
	if(isalnum(prev) && isalnum(next)) return 0; /* a/a+b/i */
	if(isspace(prev)) return 1; /* return /a+b/i */
	return 0;
}

static size_t addRegex(CTX ctx,  tenv_t *tenv, size_t pos)
{
	int ch, prev = 0;
	while((ch = tenv->line[pos++]) != 0) {
		if(ch == '\n') {
			WARN_MustCloseWith(ctx, /*tenv->uline,*/ '/');
			tenv->uline += 1;
			break;
		}
		if(ch == '/') {
			if(prev != '\\') break;
		}
		if(prev == '\\' && ch == '\\') ch = 0;
		prev = ch;
	}
	return pos-1;
}

static int addOperator(CTX ctx, tenv_t *tenv, int tok_start)
{
	int ch, pos = tok_start;
	while((ch = tenv->line[pos++]) != 0) {
		if(isalnum(ch)) break;
		switch(ch) {
			case '<': case '>':
			case '+': case '-': case '*': case '%': case '/':
			case '=': case '&': case '?': case ':': case '.':
			case '^': case '!': case '~': case '|':
			continue;
		}
	}
	knh_String_t *text = new_String2(ctx, CLASS_String, (const char*)tenv->line + tok_start, (pos-1)-tok_start, K_SPOLICY_ASCII|K_SPOLICY_POOLALWAYS);
	addToken(ctx, tenv, new_Token(ctx, TK_OPERATOR, tenv->uline, 0, text));
	return pos-1;
}

static int addMetaName(CTX ctx, tenv_t *tenv, int tok_start)
{
	int ch, pos = tok_start+1;
	while((ch = tenv->line[pos++]) != 0) {
		if(!isalnum(ch) && ch != '_' && ch != '.') {
			break;
		}
	}
	knh_String_t *text = new_String2(ctx, CLASS_String, (const char*)tenv->line + tok_start, (pos-1)-tok_start, K_SPOLICY_ASCII|K_SPOLICY_POOLALWAYS);
	addToken(ctx, tenv, new_Token(ctx, TK_META, tenv->uline, 0, text));
	return pos - 1;
}

static int addPropName(CTX ctx, tenv_t *tenv, int tok_start)
{
	int ch, pos = tok_start+1;
	while((ch = tenv->line[pos++]) != 0) {
		if(!isalnum(ch) && ch != '_' && ch != '.' && ch != '*') {
			break;
		}
	}
	knh_String_t *text = new_String2(ctx, CLASS_String, (const char*)tenv->line + tok_start, (pos-1)-tok_start, K_SPOLICY_ASCII|K_SPOLICY_POOLALWAYS);
	addToken(ctx, tenv, new_Token(ctx, TK_PROP, tenv->uline, 0, text));
	return pos - 1;
}

static size_t addNumber(CTX ctx, tenv_t *tenv, int tok_start)
{
	int ch, dot = 0, pos = tok_start;
	if(tenv->line[tok_start] == '.') {
		knh_Bytes_putc(ctx, tenv->buf, '0');
		knh_Bytes_putc(ctx, tenv->buf, '.');
		dot=1; pos++;
	}
	while((ch = tenv->line[pos++]) != 0) {
		if(ch == '_') continue; // nothing
		if(ch == '.') {
			if(tenv->line[pos] == '.') {
				goto L_NUM;
			}
			dot++;
			knh_Bytes_putc(ctx, tenv->buf, '.');
			continue;
		}
		if((ch == 'e' || ch == 'E') && (tenv->line[pos] == '+' || tenv->line[pos] =='-')) {
			pos++;
		}
		if(!isalnum(ch)) break;
		knh_Bytes_putc(ctx, tenv->buf, ch);
	}
	L_NUM: {
		knh_String_t *text = new_String2(ctx, CLASS_String, BA_totext(tenv->buf), BA_size(tenv->buf), K_SPOLICY_ASCII);
		int ttype = (dot == 0) ? TK_INT : TK_FLOAT;
		addToken(ctx, tenv, new_Token(ctx, ttype, tenv->uline, 0, text));
		knh_Bytes_clear(tenv->buf, tenv->bufhead);
	}
	return pos-1;
}

static int skipMultiByteChar(CTX ctx, tenv_t *tenv, size_t tok_start)
{
	int ch, pos = tok_start;
	while((ch = tenv->line[pos++]) > 127);
	WARN_UnxpectedMultiByteChar(ctx, NULL);
	return pos;
}

static size_t addWhiteSpace(CTX ctx, tenv_t *tenv, size_t pos)
{
	int ch;
	do {
		ch = tenv->line[pos++];
	}
	while(ch == ' ' || ch == '\t');
	addToken(ctx, tenv, new_Token(ctx, TK_WHITESPACE, tenv->uline, 0, TS_EMPTY));
	return pos-1;
}

#define _UNFOLD      (1)
#define _WHITESPACE  (1<<1)
#define _INDENT      (1<<2)

static size_t addNewLine(CTX ctx, tenv_t *tenv, size_t pos, int pol)
{
	int ch, c = 0;
	while((ch = tenv->line[pos++]) != 0) {
		if(ch == '\t') { c += tenv->tab; }
		else if(ch == ' ') { c += 1; }
		break;
	}
	if(FLAG_is(pol, _INDENT)) {
		addToken(ctx, tenv, new_Token(ctx, TK_INDENT, tenv->uline, c, TS_EMPTY));
	}
	return pos - 1;
}

static void parse(CTX ctx, tenv_t *tenv, int pol)
{
	int ch;
	size_t pos = addNewLine(ctx, tenv, 0, pol), tok_start = 0;

	L_NEWTOKEN:;
	tok_start = pos;
	while((ch = tenv->line[pos++]) != 0) {
		switch(ch) {
		case '\n':
			addSymbol(ctx, tenv, tok_start, pos-1);
			tenv->uline += 1;
			pos = addNewLine(ctx, tenv, pos, pol);
			goto L_NEWTOKEN;

		case ' ': case '\t':
			addSymbol(ctx, tenv, tok_start, pos-1);
			if(FLAG_is(pol, _WHITESPACE)) {
				pos = addWhiteSpace(ctx, tenv, pos);
			}
			goto L_NEWTOKEN;

		case '{':
			if(!FLAG_is(pos, _UNFOLD)) {
				addSymbol(ctx, tenv, tok_start, pos-1);
				pos = addBlock(ctx, tenv, pos);
				goto L_NEWTOKEN;
			}
		case '}':
		case '\v': case '\r': case ';': case ',':
		case '(':  case ')':  case '[': case ']':
			addSymbol(ctx, tenv, tok_start, pos-1);
			addSymbol(ctx, tenv, pos-1, pos);
			goto L_NEWTOKEN;

		/* token */
		case '\'': case '"': case '`' :
		case '#':
			addSymbol(ctx, tenv, tok_start, pos-1);
			pos = addQuote(ctx, tenv, pos, ch);
			goto L_NEWTOKEN;

		case '$':
			addSymbol(ctx, tenv, tok_start, pos-1);
			pos = addPropName(ctx, tenv, pos-1);
			goto L_NEWTOKEN;
//
		case '@':
			addSymbol(ctx, tenv, tok_start, pos-1);
			ch = tenv->line[pos];  // look ahead
			if(ch == '\'' || ch == '"' || ch == '`') {
				pos = addRawQuote(ctx, tenv, pos+1, ch);
			}
			else {
				pos = addMetaName(ctx, tenv, pos-1);
			}
			goto L_NEWTOKEN;

		case '/':
			addSymbol(ctx, tenv, tok_start, pos-1);
			ch = tenv->line[pos];  // look ahead
			if(ch == '/') {
				pos = skipLine(ctx, tenv, pos);
			}
			else if(ch == '*') {
				pos = skipComment(ctx, tenv, pos);
			}
			else if(checkRegex(ctx, tenv, pos)) {
				pos = addRegex(ctx, tenv, pos);
			}
			else {
				pos = addOperator(ctx, tenv, pos-1);
			}
			goto L_NEWTOKEN;

		case '.':
			ch = tenv->line[pos];
			if(isdigit(ch)) {
				addSymbol(ctx, tenv, tok_start, pos-1);
				pos = addNumber(ctx, tenv, pos-1);
				goto L_NEWTOKEN;
			}
		case '+': case '-': case '*': case '%':
		case '<': case '>':
		case '=': case '&': case '?': case '|':
		case '^': case '!': case '~':
			addSymbol(ctx, tenv, tok_start, pos-1);
			pos = addOperator(ctx, tenv, pos-1);
			goto L_NEWTOKEN;

		case ':':
			ch = tenv->line[pos];
			if(isalnum(ch) || ch == '/' || ch == '-') {
				pos = addURN(ctx, tenv, pos+1, tok_start, 0);
				goto L_NEWTOKEN;
			}
			else {
				addSymbol(ctx, tenv, tok_start, pos-1);
				addSymbol(ctx, tenv, pos-1, pos);
			}
			goto L_NEWTOKEN;

		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			if(pos == tok_start+1) {
				pos = addNumber(ctx, tenv, tok_start);
				goto L_NEWTOKEN;
			}

		default:
			if(ch > 127) {
				addSymbol(ctx, tenv, tok_start, pos-1);
				pos = skipMultiByteChar(ctx, tenv, pos-1);
				goto L_NEWTOKEN;
			}
		} /* switch */
	}/*while*/
	addSymbol(ctx, tenv, tok_start, pos-1);
}


/* ------------------------------------------------------------------------ */

typedef struct {
	knh_Array_t *list;
	int cur;     int eol;
	knh_String_t *key;
	knh_Stmt_t *stmt;
} toks_t;

static toks_t *new_toks(toks_t *buf, knh_Array_t *a)
{
	buf->list = a;
	buf->cur = 0;
	buf->eol = knh_Array_size(a);
	buf->key = NULL;
	buf->stmt = NULL;
	return buf;
}

static inline int hasN(toks_t *toks, int n)
{
	int cur = toks->cur + n;
	return (cur < toks->eol);
}

static inline knh_Token_t *tkN(toks_t *toks, int n)
{
	int cur = toks->cur + n;
	static knh_Token_t dummyEND = {
		{0},
		TK_END, 0, 0, NULL
	};
	if(cur < toks->eol) {
		knh_Token_t *tk = toks->list->tokens[cur];
		return tk;
	}
	return &dummyEND;
}

static inline void nextN(toks_t *toks, int n)
{
	toks->cur += n;
}

static inline toks_t* subBetween(toks_t *dst, toks_t *src, int opench, int closech)
{
	int c = src->cur, p = 0;
	*dst = *src;
	while(c < src->eol) {
		knh_Token_t *tk = src->list->tokens[c];
		if(tk->token == TK_SYMBOL) {
			if(tk->optnum == opench) p++;
			if(tk->optnum == closech) {
				if(p==1) break;
				p--;
			}
		}
		c++;
	}
	dst->eol = c;
	return dst;
}

/* -- */

static int checkStmtKey(CTX ctx, toks_t *rule);
static int isSymbolRule(toks_t *rule);
static int isTermRule(toks_t *rule);
static int isOptionalRule(toks_t *rule);
static int matchSymbolRule(CTX ctx, toks_t *rule, toks_t *toks);
static int matchTermRule(CTX ctx, toks_t *rule, toks_t *toks, knh_NameSpace_t *ns);

static int matchLeft(CTX ctx, toks_t *rule, toks_t *toks, knh_NameSpace_t *ns)
{
	while(hasN(toks, 0)) {
		checkStmtKey(ctx, rule);
		if(isSymbolRule(rule)) {
			if(matchSymbolRule(ctx, rule, toks)) {
				return 0;
			}
			nextN(rule, 1);
		}
		else if(isTermRule(rule)) {
			if(matchTermRule(ctx, rule, toks, ns)) {
				return 0;
			}
			nextN(rule, 1);
		}
		else if(isOptionalRule(rule)) {
			toks_t subrulebuf, *subrule = subBetween(&subrulebuf, rule, '[', ']');
			int rollback = toks->cur;
			if(!matchLeft(ctx, subrule, toks, ns)) {
				toks->cur = rollback;
				rule->cur = subrule->eol + 1;
				knh_Token_t *tk = tkN(rule, 0);
				if(tk->optnum == '*') nextN(rule, 1);
			}
			else {
				int start = rule->cur;
				rule->cur = subrule->eol + 1;
				knh_Token_t *tk = tkN(rule, 0);
				if(tk->optnum == '*') rule->cur = start;
			}
		}
	}
	return 1;
}

static knh_Stmt_t* Sugar_matchLeftNULL(CTX ctx, knh_Sugar_t *sugar, toks_t *toks, knh_NameSpace_t *ns)
{
	toks_t rulebuf, *rule = new_toks(&rulebuf, sugar->rules);
	if(matchLeft(ctx, rule, toks, ns)) {
		return rule->stmt;
	}
	return NULL;
}

knh_Stmt_t* block(CTX ctx, knh_Array_t *tlist, knh_NameSpace_t *ns)
{
	return Sugar_matchLeftNULL(NULL, NULL, NULL, NULL); //TODO
}

static int checkStmtKey(CTX ctx, toks_t *rule)
{
	knh_Token_t *tk0 = tkN(rule, 0);
	knh_Token_t *tk1 = tkN(rule, 1);
	rule->key = NULL;
	if(tk0->token == TK_SYMBOL && tk1->optnum == ':') {
		rule->key = tk0->text;
		rule->cur += 2;
		return 1;
	}
	return 0;
}

static int isSymbolRule(toks_t *rule)
{
	knh_Token_t *tk0 = tkN(rule, 0);
	return (tk0->token == TK_TEXT);
}

static int isTermRule(toks_t *rule)
{
	knh_Token_t *tk0 = tkN(rule, 0);
	return (tk0->token == TK_USYMBOL);
}

static int isOptionalRule(toks_t *rule)
{
	knh_Token_t *tk0 = tkN(rule, 0);
	return (tk0->token == TK_SYMBOL && tk0->optnum == '[');
}

static int matchSymbolRule(CTX ctx, toks_t *rule, toks_t *toks)
{
	return 1;
}

static int matchTermRule(CTX ctx, toks_t *rule, toks_t *toks, knh_NameSpace_t *ns)
{
	return 1;
}

//static void _EXPR1(CTX ctx, knh_StmtExpr_t *stmt, tkitr_t *itr)
//{
//	//if(ITR_hasNext(itr)) {
//		knh_Term_t *tkCUR = ITR_nextTK(itr);
//		switch(TT_(tkCUR)) {
//			case TT_NAME:    /* @CODE: name */
//			case TT_UNAME:   /* @CODE: NAME */
//				DBG_ASSERT(!ITR_hasNext(itr));  // to avoid name. hoge
//			case TT_NULL:    /* @CODE: null */
//			case TT_TRUE:    /* @CODE: true */
//			case TT_FALSE:   /* @CODE: false */
//			case TT_PTYPE:    /* @CODE: T<T> */
//			case TT_PROPN:   /* @CODE: $NAME */
//			case TT_TYPEOF:  /* @CODE: typeof(expr) */
//			case TT_STR:     /* @CODE: "hoge" */
//			case TT_TSTR:    /* @CODE: 'hoge' */
//			case TT_ESTR:    /* @CODE: `hoge` */
//			case TT_NUM:     /* @CODE: 123m */
//			case TT_URN:     /* @CODE: URL */
//			case TT_TLINK:   /* @CODE: link:: */
//			case TT_DYN:
//				knh_Stmt_add(ctx, stmt, tkCUR);
//				break;
//			case TT_BYTE:    /* @CODE: byte */
//				TT_(tkCUR) = TT_NAME;
//				knh_Stmt_add(ctx, stmt, tkCUR);
//				break;
//			case TT_REGEX:
//				_REGEX(ctx, stmt, itr, tkCUR);
//				break;
//			case TT_PARENTHESIS: /* @CODE: () */ {
//				tkitr_t pbuf, *pitr = ITR_new(tkCUR, &pbuf);
//				int c = ITR_count(pitr, TT_COMMA);
//				if(c == 0) {
//					if(ITR_hasNext(pitr)) {   /* @CODE: (expr) => expr */
//						_EXPR(ctx, stmt, pitr);
//					}
//					else { /* @CODE: () => null */
//						TT_(tkCUR) = TT_NULL;
//						knh_Stmt_add(ctx, stmt, tkCUR);
//					}
//				}
//				else {  /* @CODE: (1, 2) */
//					stmt = new_StmtREUSE(ctx, stmt, STT_NEW);
//					_ARRAY(ctx, stmt, MN_newTUPLE, CLASS_Tuple, pitr);
//				}
//				break;
//			}
//			case TT_BRANCET: {  /* @CODE: [] */
//				tkitr_t pbuf, *pitr = ITR_new(tkCUR, &pbuf);
//				knh_class_t cid = CLASS_Array;
//				knh_index_t idx = ITR_indexTT(pitr, TT_TO, -1);
//				if(idx != -1) { /* [1 to 2] => [1, 2] */
//					cid = CLASS_Range;
//					TT_(pitr->ts[idx]) = TT_COMMA;
//				}
//				stmt = new_StmtREUSE(ctx, stmt, STT_NEW);
//				_ARRAY(ctx, stmt, MN_newLIST, cid, pitr);
//				break;
//			}
//			case TT_CODE: {
//				knh_bytes_t t = S_tobytes(tkCUR->text);
//				if(t.len == 0 || knh_bytes_index(t, ':') != -1) {
//					stmt = new_StmtREUSE(ctx, stmt, STT_NEW);
//					knh_Stmt_add(ctx, stmt, new_TermMN(ctx, MN_newMAP));
//					_DICT(ctx, stmt, new_TermCID(ctx, CLASS_Map), tkCUR);
//				}
//				else {
//					stmt = new_StmtREUSE(ctx, stmt, STT_FUNCTION);
//					_ASIS(ctx, stmt, itr);
//					knh_Stmt_add(ctx, stmt, new_Stmt2(ctx, STT_DECL, NULL));
//					knh_Term_t *tkDOC = new_Term(ctx, TT_DOC);
//					KNH_SETv(ctx, (tkDOC)->data, (tkCUR)->text);
//					knh_Stmt_add(ctx, stmt, tkDOC);
//					itr->c -= 1;
//					_STMT1(ctx, stmt, itr);
//					DBG_P("SIZE=%d", DP(stmt)->size);
//				}
//				break;
//			}
//			case TT_ERR:
//				knh_StmtExpr_toERR(ctx, stmt, tkCUR);
//				break;
//			default: {
//				Stmt_toSyntaxError(ctx, stmt, tkCUR K_TRACEPOINT);
//			}
//		}
////	}
////	else {
////		knh_StmtExpr_toERR(ctx, stmt, ERROR_text(ctx, TT__(stmt->stt) K_TRACEPOINT));
////	}
//}
//
//static knh_Expr_t *_EXPR(CTX ctx, toks_t *toks, knh_NameSpace_t *ns)
//{
//	knh_Token_t *tk0 = tkN(toks, 0);
//
//	size_t n = ITR_size(itr);
//	if(n == 1) {
//		_EXPR1(ctx, stmt, itr);
//	}
//	else if(n > 1) {
//		int idx = ITR_indexLET(itr);
//		if(idx != -1) { /* a = b */
//			_EXPRLET(ctx, stmt, itr, idx);
//			return;
//		}
//		int isCAST = ITR_isCAST(itr);
//		idx = ITR_indexOPR(ctx, itr, 0);
//		if(idx != -1 && (!isCAST || IS_BIN(TT_(itr->ts[idx])))) {
//			_EXPROP(ctx, stmt, itr, idx);
//		}
//		else if(isCAST) {
//			_EXPRCAST(ctx, stmt, itr);
//		}
//		else {  /*f -1*/
//			_EXPRCALL(ctx, stmt, itr);
//		}
//	}
//	else {
//		_ASIS(ctx, stmt, itr);
//	}
//}

//typedef knh_Object_t* (*Fmatch)(CTX, toks_t *, knh_NameSpace_t *);
//
//static Fmatch findTermFunc(knh_Token_t *p)
//{
//	return NULL;
//}
//
//static int reduceLine(toks_t *toks, knh_Token_t *p)
//{
//	int i, p1 = 0, p2 = 0, p3 = 0;
//	for(i = toks->cur; i < toks->eol; i++) {
//		knh_Token_t *tk = toks->list->tokens[i];
//		if(tk)
//		if(tk->optnum == '(') p1++; continue;
//		if(tk->optnum == '[') p2++; continue;
//		if(tk->optnum == '{') p3++; continue;
//
//	}
//}
//
//static int matchTermRule(CTX ctx, toks_t *rule, toks_t *toks, knh_NameSpace_t *ns)
//{
//	Fmatch *match = findTermFunc(toks(rule, 0));
//	int eol = toks->eol;
//	knh_Token_t *tk1 = toks(rule, 1);
//	if(tk1->token == TK_TEXT) { // EXPR ")"
//		if(!reduceTokenLine(toks, tk1)) {
//			//ERROR()
//		}
//	}
//	Object *expr = match(ctx, toks, ns);
//}

//class AssignmentOperator extends SyntaxRule {
//	void transform(Token[] tokens, int offset) {
//
//	}
//};
//
//sugar syntax indent "else" => "else"
//sugar syntax $ * "+=" => AssignmentOperator

/* ------------------------------------------------------------------------ */

/**
sugar syntax "Int" "int"
sugar syntax BOL "else" "else"
sugar statement "if" "(" expr ")" stmt => new IfStmt(expr, stmt, null)
sugar statement "if" "(" expr ")" stmt "else" stmt => new IfStmt2(expr, stmt, stmt)
sugar operator expr "+" expr
**/

#ifdef __cplusplus
}
#endif
