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
} tenv_t;

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
	while((ch = tenv->line[pos++]) != 0) {
		L_STARTLINE:;
		if(ch == '}' && prev != '\\') {
			level--;
			if(level == 0) {
				knh_String_t *text = new_String2(ctx, CLASS_String, (const char*)tenv->line, ((pos - 1)-tok_start), K_SPOLICY_POOLNEVER);
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

static void addSymbol(CTX ctx, tenv_t *tenv, size_t s, size_t e)
{
	if(s < e) {
		knh_String_t *text = new_String2(ctx, CLASS_String, (const char*)tenv->line, (e-s), K_SPOLICY_ASCII|K_SPOLICY_POOLALWAYS);
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

static size_t addNewLine(CTX ctx, tenv_t *tenv, size_t pos)
{
	int ch, c = 0;
	while((ch = tenv->line[pos++]) != 0) {
		if(ch == '\t') { c += tenv->tab; }
		else if(ch == ' ') { c += 1; }
		break;
	}
	addToken(ctx, tenv, new_Token(ctx, TK_INDENT, tenv->uline, c, TS_EMPTY));
	return pos;
}

#define _UNFOLD      (1)
#define _WHITESPACE  (1<<1)

static void parse(CTX ctx, tenv_t *tenv, int pol)
{
	int ch;
	size_t pos = addNewLine(ctx, tenv, 0), tok_start = 0;

	L_NEWTOKEN:;
	tok_start = pos;
	while((ch = tenv->line[pos++]) != 0) {
		switch(ch) {
		case '\n':
			addSymbol(ctx, tenv, tok_start, pos-1);
			tenv->uline += 1;
			pos = addNewLine(ctx, tenv, 0);
			goto L_NEWTOKEN;

		case '{':
			if(FLAG_is(pos, _UNFOLD)) {
				addSymbol(ctx, tenv, tok_start, pos-1);
				pos = addBlock(ctx, tenv, pos);
				goto L_NEWTOKEN;
			}
		case '}':
		case ' ': case '\t':
			addSymbol(ctx, tenv, tok_start, pos-1);
			if(FLAG_is(pol, _WHITESPACE)) {
				pos = addWhiteSpace(ctx, tenv, pos);
			}
			goto L_NEWTOKEN;
		case '\v': case '\r': case ';': case ',':
		case '(':  case ')':  case '[': case ']': case '<': case '>':
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

/**
typedef struct {
	knh_uline_t uline;
	knh_Array_t *list;
	const knh_uchar_t *line;
	knh_Bytes_t *buf;
	int bufhead;
	int tab;
} tenv_t;
**/

/* ------------------------------------------------------------------------ */
/* api */

// String[] String.tokenize()

static KMETHOD String_tokenize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	size_t i;
	knh_Array_t *a = new_Array(ctx, CLASS_String, 0);
	tenv_t tenvbuf = {
		0,
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
		0,
		a,
		(const knh_uchar_t *)S_totext(sfp[1].s),
		ctx->bufa,
		BA_size(ctx->bufa),
		3,/*tabsize*/
	};
	KNH_SETv(ctx, sfp[K_RIX].o, a);
	parse(ctx, &tenvbuf, 0);
}



//
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
