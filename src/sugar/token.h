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

#define knh_String_equals(STR, t)   (knh_bytes_equals(S_tobytes(STR), t))

typedef struct {
	knh_uline_t uline;
	knh_Array_t *list;
	union {
		const char *s;
		const knh_uchar_t *line;
	};
	const char *bol;
	knh_Bytes_t *buf;
	size_t bufhead;
	int tab;
	knh_Lang_t *lang;
	int rcur_count;  // to check infinite recursion
} tenv_t;

static void parse(CTX ctx, tenv_t *tenv, int pol);

static inline int lpos(tenv_t *tenv, const char *s)
{
	return (tenv->bol == NULL) ? -1 : s - tenv->bol;
}

static knh_Token_t *new_Token(CTX ctx, knh_token_t token, knh_uline_t uline, int lpos, knh_String_t *text, int dummy)
{
	knh_Token_t *tk = new_(Token);
	tk->token = token;
	tk->uline = uline;
	tk->lpos = (knh_ushort_t)lpos;
	tk->topch = 0;
	KNH_SETv(ctx, tk->text, text);
	return tk;
}

static void addToken(CTX ctx, tenv_t *tenv, knh_Token_t *tk)
{
	knh_Array_add(ctx, tenv->list, tk);
//	knh_Lang_t *lang = tenv->lang;
//	while(lang != NULL) {
//		if(DP(lang)->tokenRulesNULL != NULL) {
//			knh_String_t *alias = (knh_String_t*)knh_DictMap_getNULL(ctx, DP(lang)->tokenRulesNULL, t);
//			if(alias != NULL && IS_String(alias)) {
//				DEBUG_TokenAlias(ctx, tenv->uline, lpos(tenv, s), t, alias);
//				return alias;
//			}
//		}
//		lang = lang->parentNULL;
//	}
//
//	if(tenv->lang != NULL) {
//
//	}
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

#define DUMMY 1
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
		const char *s = tenv->s + tok_start;
		knh_String_t *text = new_String2(ctx, CLASS_String, s, ((pos-1)-tok_start), pol);
		addToken(ctx, tenv, new_Token(ctx, TK_URN, tenv->uline, lpos(tenv, s), text, DUMMY));
	}
	return pos-1;
}

static size_t addBlock(CTX ctx, tenv_t *tenv, size_t pos, int lpos)
{
	int c, this_indent = 0, ch, prev = '{', level = 1;
	size_t tok_start = pos;
	knh_uline_t uline = tenv->uline;
	while((ch = tenv->line[pos++]) != 0) {
		L_STARTLINE:;
		if(ch == '}' && prev != '\\') {
			level--;
			if(level == 0) {
				knh_String_t *text = new_String2(ctx, CLASS_String, tenv->s + tok_start, ((pos-1)-tok_start), K_SPOLICY_POOLNEVER);
				addToken(ctx, tenv, new_Token(ctx, TK_CODE, uline, lpos, text, DUMMY));
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

static knh_String_t *getAliasNULL(CTX ctx, tenv_t *tenv, const char *s, size_t len)
{
	knh_bytes_t t = {{s}, len};
	knh_Lang_t *lang = tenv->lang;
	while(lang != NULL) {
		if(DP(lang)->tokenRulesNULL != NULL) {
			knh_String_t *alias = (knh_String_t*)knh_DictMap_getNULL(ctx, DP(lang)->tokenRulesNULL, t);
			if(alias != NULL && IS_String(alias)) {
				DEBUG_TokenAlias(ctx, tenv->uline, lpos(tenv, s), t, alias);
				return alias;
			}
		}
		lang = lang->parentNULL;
	}
	return NULL;
}

static void addSymbol(CTX ctx, tenv_t *tenv, size_t s, size_t e)
{
	if(s < e) {
		if(tenv->lang != NULL && tenv->rcur_count < 32) {  // "int" => "Int"
			knh_String_t *alias = getAliasNULL(ctx, tenv, tenv->s + s, (e-s));
			if(alias != NULL) {
				tenv_t tenvbuf = {
					tenv->uline,
					tenv->list,
					{S_totext(alias)},
					NULL,
					tenv->buf,
					tenv->bufhead,
					tenv->tab,
					tenv->lang,    // set NULL if you want to stop the recursion.
					tenv->rcur_count + 1
				};
				parse(ctx, &tenvbuf, 0);
				return;
			}
		}
		else {
			knh_String_t *text = new_String2(ctx, CLASS_String, tenv->s + s, (e-s), K_SPOLICY_ASCII|K_SPOLICY_POOLALWAYS);
			knh_token_t ttype = (isupper(S_totext(text)[0])) ? TK_USYMBOL : TK_SYMBOL;
			addToken(ctx, tenv, new_Token(ctx, ttype, tenv->uline, lpos(tenv, tenv->s + s), text, DUMMY));
		}
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
	knh_uline_t uline = tenv->uline;
	const char *qs = tenv->s - 1;
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
				WARN_LiteralMustCloseWith(ctx, uline, lpos(tenv, qs), quote);
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
				const char *s1 = BA_totext(tenv->buf) + tenv->bufhead;
				size_t len = BA_size(tenv->buf) - tenv->bufhead;
				knh_String_t *text = new_String2(ctx, CLASS_String, s1, len, 0);
				knh_token_t ttype = (quote == '"') ? TK_TEXT : TK_STEXT;
				addToken(ctx, tenv, new_Token(ctx, ttype, uline, lpos(tenv, qs), text, DUMMY));
				knh_Bytes_clear(tenv->buf, tenv->bufhead);
				return pos;
			}
		}
		knh_Bytes_putc(ctx, tenv->buf, ch);
	}
	WARN_LiteralMustCloseWith(ctx, uline, lpos(tenv, qs), quote);
	return pos-1;
}

static size_t addRawQuote(CTX ctx, tenv_t *tenv, size_t pos, int quote)
{
	int ch, isTriple = 0;
	knh_uline_t uline = tenv->uline;
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
				knh_String_t *text = new_String2(ctx, CLASS_String, tenv->s + tok_start, (pos-1)-tok_start, 0);
				knh_type_t ttype = (quote == '"') ? TK_TEXT : TK_STEXT;
				addToken(ctx, tenv, new_Token(ctx, ttype, uline, lpos(tenv, tenv->s + tok_start), text, DUMMY));
				return pos;
			}
		}
	}
	return pos-1;
}

static size_t checkRegex(CTX ctx, tenv_t *tenv, size_t pos)
{
	DBG_ASSERT(pos > 0);
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
		break;
	}
	{
		const char *s = tenv->s + tok_start;
		knh_String_t *text = new_String2(ctx, CLASS_String, s, (pos-1)-tok_start, K_SPOLICY_ASCII|K_SPOLICY_POOLALWAYS);
		knh_Token_t *tk = new_Token(ctx, TK_OPERATOR, tenv->uline, lpos(tenv, s), text, DUMMY);
		if(S_size(text) == 1) {
			tk->topch = S_totext(text)[0];
		}
		addToken(ctx, tenv, tk);
	}
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
	{
		const char *s = tenv->s + tok_start;
		knh_String_t *text = new_String2(ctx, CLASS_String, s, (pos-1)-tok_start, K_SPOLICY_ASCII|K_SPOLICY_POOLALWAYS);
		addToken(ctx, tenv, new_Token(ctx, TK_META, tenv->uline, lpos(tenv, s), text, DUMMY));
	}
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
	{
		const char *s = tenv->s + tok_start;
		knh_String_t *text = new_String2(ctx, CLASS_String, s, (pos-1)-tok_start, K_SPOLICY_ASCII|K_SPOLICY_POOLALWAYS);
		addToken(ctx, tenv, new_Token(ctx, TK_PROP, tenv->uline, lpos(tenv, s), text, DUMMY));
	}
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
			knh_Bytes_putc(ctx, tenv->buf, ch);
			knh_Bytes_putc(ctx, tenv->buf, tenv->line[pos]);
			pos++;
			continue;
		}
		if(!isalnum(ch)) break;
		knh_Bytes_putc(ctx, tenv->buf, ch);
	}
	L_NUM: {
		const char *s = tenv->s + tok_start;
		const char *s1 = BA_totext(tenv->buf) + tenv->bufhead;
		size_t len = BA_size(tenv->buf) - tenv->bufhead;
		knh_String_t *text = new_String2(ctx, CLASS_String, s1, len, K_SPOLICY_ASCII);
		int ttype = (dot == 0) ? TK_INT : TK_FLOAT;
		addToken(ctx, tenv, new_Token(ctx, ttype, tenv->uline, lpos(tenv, s), text, DUMMY));
		knh_Bytes_clear(tenv->buf, tenv->bufhead);
	}
	return pos-1;
}

static int skipMultiByteChar(CTX ctx, tenv_t *tenv, size_t tok_start)
{
	int ch, pos = tok_start;
	while((ch = tenv->line[pos]) > 127) pos++;
	const char *s = tenv->s + tok_start;
	IGNORE_UnxpectedMultiByteChar(ctx, tenv->uline, lpos(tenv, s), (char*)s, pos - tok_start);
	return pos;
}

static size_t addWhiteSpace(CTX ctx, tenv_t *tenv, size_t pos)
{
	int ch, tok_start = pos;
	do {
		ch = tenv->line[pos++];
	}
	while(ch == ' ' || ch == '\t');
	addToken(ctx, tenv, new_Token(ctx, TK_WHITESPACE, tenv->uline, lpos(tenv, tenv->s + tok_start), TS_EMPTY, DUMMY));
	return pos-1;
}

#define _UNFOLD      (1)
#define _WHITESPACE  (1<<1)
#define _INDENT      (1<<2)

#define _TOPLEVEL    _INDENT|_UNFOLD
#define _METHOD      _INDENT

static size_t addNewLine(CTX ctx, tenv_t *tenv, size_t pos, int pol)
{
	int ch, c = 0;
	while((ch = tenv->line[pos++]) != 0) {
		if(ch == '\t') { c += tenv->tab; }
		else if(ch == ' ') { c += 1; }
		break;
	}
	if(FLAG_is(pol, _INDENT)) {
		addToken(ctx, tenv, new_Token(ctx, TK_INDENT, tenv->uline, c, TS_EMPTY, DUMMY));
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
			tenv->bol = tenv->s + pos;
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
				pos = addBlock(ctx, tenv, pos, lpos(tenv, tenv->s + (pos - 1)));
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

typedef enum {
	_Init, _Matching, _Deterministic, FoundError
} parserstatus_t;

typedef struct {
	const knh_context_t *ctx;
	knh_Array_t         *list;
	int cur;         int eol;
	parserstatus_t       status;
	knh_String_t        *key;
	knh_Stmt_t          *stmt;
	knh_Expr_t          *expr;
	knh_Lang_t          *lang;
	knh_NameSpace_t     *ns;
} toks_t;

static toks_t *new_toks(CTX ctx, toks_t *buf, knh_Array_t *a, knh_Lang_t *lang, knh_NameSpace_t *ns)
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

static inline knh_Token_t *tkN(toks_t *toks, int n)
{
	int cur = toks->cur + n;
	static knh_Token_t dummyEND = {
		{0},
		TK_NONE, {NULL}, 0
	};
	if(cur < toks->eol) {
		knh_Token_t *tk = toks->list->tokens[cur];
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
	knh_Token_t *tkS = toks->list->tokens[c-1];
	for(;c < toks->eol; c++) {
		knh_Token_t *tk = toks->list->tokens[c];
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

static knh_bool_t skipAnotation(toks_t *toks)
{
	int c = toks->cur;
	for(;c < toks->eol; c++) {
		knh_Token_t *tk = toks->list->tokens[c];
		if(tk->token == TK_WHITESPACE) continue;
		if(tk->token == TK_META) {
			toks->cur = c;
			tk = tkN(toks, 1);
			if(tk->topch == '(') {
				c = findclose(toks, c+2, '(', ')');
				if(c == -1) return 0;
				toks->cur = c + 1;
			}
			continue;
		}
		break;
	}
	return 1;
}

static knh_bool_t subBetween(toks_t *dst, toks_t *src, int opench, int closech)
{
	int c = findclose(src, src->cur+1, opench, closech);
	if(c == -1) return 0;
	sub(dst, src, src->cur, c);
	return 1;
}

static int nextT(toks_t *toks, int n)
{
	int c = n;
	for(c = n; c < toks->eol; c++) {
		knh_Token_t *tk = toks->list->tokens[c];
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

void static ERROR_SyntaxErrorRule(CTX ctx, knh_Token_t *rule, toks_t *toks)
{

}

void static ERROR_NotTerm(CTX ctx, knh_Token_t *tk, toks_t *toks)
{

}

/* -- */

#define INDENT_GCBUF(lang)      size_t gcindent_  = knh_Array_size(lang->gcbuf)
#define PUSH_GCBUF(lang, o)     knh_Array_add(ctx, lang->gcbuf, o)
#define CLEAR_GCBUF(lang)       knh_Array_clear(ctx, lang->gcbuf, gcindent_)

static int checkStmtKey(toks_t *rule);
static int isDeterministic(toks_t *rule);
static int isSymbolRule(toks_t *rule);
static int isTermRule(toks_t *rule);
static int isOptionalRule(toks_t *rule);
static int matchSymbolRule(toks_t *rule, toks_t *toks);
static int matchTermRule(toks_t *rule, toks_t *toks);

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
				knh_Token_t *tk = tkN(rule, 0);
				if(tk->topch == '*') incN(rule, 1);
			}
			else {
				int start = rule->cur;
				rule->cur = sub.eol + 1;
				knh_Token_t *tk = tkN(rule, 0);
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

sugar MethodDecl ::= type [cname "."]　name "(" params ")" [block];
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

static int matchStmt(CTX ctx, toks_t *toks, knh_Stmt_t *stmt)
{
	knh_Lang_t *lang = toks->lang;
	int i, toks_cur = toks->cur; int toks_eol = toks->eol;
	toks_t rulebuf;
	while(lang != NULL) {
		knh_Array_t *l = DP(lang)->stmtRulesNULL;
		if(l != NULL) {
			toks->status = _Matching;
			for(i = 0; i < knh_Array_size(l); i++) {
				knh_Sugar_t *s = (knh_Sugar_t*)l->list[i];
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
	return 0;
}


static void Stmt_addMetaData(CTX ctx, knh_Stmt_t *stmt, toks_t *toks);

static knh_Stmt_t *new_Stmt(CTX ctx, knh_Array_t *tlist, int s, int e, knh_Lang_t *lang, knh_NameSpace_t *ns)
{
	knh_Stmt_t *stmt = new_(Stmt);
	PUSH_GCBUF(lang, stmt);
	toks_t toksbuf, *toks = new_toks(ctx, &toksbuf, tlist, lang, ns);
	toks->cur = s; toks->eol = e;
	int kerrno = knh_errno(ctx);
	if(!skipAnotation(toks)) {
		stmt->stmt = STMT_ERR;
		knh_DictMap_set(ctx, stmt->clauseDictMap, new_T("error"), knh_strerror(ctx, kerrno));
	}
	if(matchStmt(ctx, toks, stmt)) {
		Stmt_addMetaData(ctx, stmt, toks);
	}
	else {

	}
	return stmt;
}

// @Ensure #(n < 1)
static void Stmt_addMetaData(CTX ctx, knh_Stmt_t *stmt, toks_t *toks)
{
	// TODO;
}

knh_Block_t *new_Block(CTX ctx, knh_Array_t *tlist, int s, int e, knh_Lang_t *lang, knh_NameSpace_t *ns)
{
	int i = s;
	knh_Block_t *bk = new_(Block);
	PUSH_GCBUF(lang, bk);
	INDENT_GCBUF(lang);
	while(i < e) {
		int start = i, indent = 0;
		knh_Token_t *tk = tlist->tokens[start];
		while(tk->token == TK_INDENT) {
			i++;
			indent = tk->lpos;
		}
		for(i = start; i < e; i++) {
			knh_Token_t *tk = tlist->tokens[i];
			if(tk->topch == ';') break;
			if(tk->token == TK_INDENT && tk->lpos == indent) break;
		}
		if(start < i) {
			knh_Stmt_t *stmt = new_Stmt(ctx, tlist, start, i, lang, ns);
			knh_Array_add(ctx, bk->blocks, stmt);
		}
		i++;
	}
	CLEAR_GCBUF(lang);
	return bk;
}

/* ------------------------------------------------------------------------ */

static int checkStmtKey(toks_t *rule)
{
	knh_Token_t *tk0 = tkN(rule, 0);
	knh_Token_t *tk1 = tkN(rule, 1);
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
	knh_Token_t *tk0 = tkN(rule, 0);
	return (tk0->topch == '^');
}

static int isSymbolRule(toks_t *rule)
{
	knh_Token_t *tk0 = tkN(rule, 0);
	return (tk0->token == TK_TEXT);
}

static int isTermRule(toks_t *rule)
{
	knh_Token_t *tk0 = tkN(rule, 0);
	return (tk0->token == TK_USYMBOL || tk0->token == TK_USYMBOL);
}

static int isOptionalRule(toks_t *rule)
{
	knh_Token_t *tk0 = tkN(rule, 0);
	return (tk0->topch == '[');
}

static int matchSymbolRule(toks_t *rule, toks_t *toks)
{
	return 1;
}

typedef knh_Expr_t* (*Fmatch)(CTX, toks_t *);
static knh_Expr_t* matchTokens(CTX ctx, toks_t *toks);
static knh_Expr_t* matchName(CTX ctx, toks_t *toks);
static knh_Expr_t* matchType(CTX ctx, toks_t *toks);
static knh_Expr_t* matchExpr(CTX ctx, toks_t *toks);
static knh_Expr_t* matchBlock(CTX ctx, toks_t *toks);

static Fmatch findTermFunc(knh_String_t *termType)
{
	int ch = S_totext(termType)[0];
	switch(ch) {
	case 'b':
		if(knh_String_equals(termType, STEXT("block"))) {
			return matchBlock;
		}
		break;
	case 'e':
		if(knh_String_equals(termType, STEXT("expr"))) {
			return matchExpr;
		}
		break;
	case 'n':
		if(knh_String_equals(termType, STEXT("name"))) {
			return matchName;
		}
		break;
	case 's':
		if(knh_String_equals(termType, STEXT("sugarname"))) {
			return matchName;
		}
		break;
	case 't':
		if(knh_String_equals(termType, STEXT("tokens"))) {
			return matchTokens;
		}
		if(knh_String_equals(termType, STEXT("type"))) {
			return matchType;
		}
		break;
	}
	return NULL;
}

static int matchTermRule(toks_t *rule, toks_t *toks)
{
	const knh_context_t *ctx = toks->ctx;
	knh_String_t *termType = tkN(rule, 0)->text;
	Fmatch match = findTermFunc(termType);
	knh_Expr_t *term = match(ctx, toks);
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

static knh_Expr_t* new_Expr(CTX ctx, toks_t *toks, knh_expr_t t, knh_Token_t *tk)
{
	knh_Expr_t *expr = new_(Expr);
	PUSH_GCBUF(toks->lang, expr);
	DBG_ASSERT(tk->token != TK_NONE);
	KNH_SETv(ctx, expr->token, tk);
	expr->expr = TERM_TYPE;
	return expr;
}

// sugar IntType := "int";

static knh_Expr_t* matchTokens(CTX ctx, toks_t *toks)
{
	knh_Expr_t *expr = new_Expr(ctx, toks, TERM_CONST, tkN(toks, 0));
	knh_Array_t *a = new_Array(ctx, CLASS_Token, (toks->eol - toks->cur));
	KNH_SETv(ctx, expr->data, a);
	int i;
	for(i=toks->cur;i < toks->eol; i++) {
		knh_Array_add(ctx, a, toks->list->tokens[i]);
	}
	toks->cur = toks->eol;
	return expr;
}

static knh_Expr_t* matchName(CTX ctx, toks_t *toks)
{
	knh_Token_t *tk0 = tkN(toks, 0);
	if(tk0->token == TK_SYMBOL) {
		knh_Expr_t *expr = new_Expr(ctx, toks, TERM_TOKEN, tk0);
		incN(toks, 1);
		return expr;
	}
	return NULL;
}

//sugar IntType   ::= "int"
//sugar ArrayType ::= type "[" "]"

static knh_Expr_t* matchType(CTX ctx, toks_t *toks)
{
	knh_Token_t *tk0 = tkN(toks, 0);
	knh_Expr_t *expr = NULL;
	if(tk0->token == TK_USYMBOL) {
		knh_class_t cid = knh_NameSpace_getcid(ctx, toks->ns, S_tobytes(tk0->text));
		if(cid != CLASS_unknown) {
			expr = new_Expr(ctx, toks, TERM_TYPE, tk0);
			KNH_SETv(ctx, expr->data, new_Type(ctx, cid));
			incN(toks, 1);
		}
	}
	if(expr != NULL) {

	}
	return expr;
}

static knh_Expr_t *new_SingleTerm(CTX ctx, knh_Token_t *tk)
{
	knh_Expr_t *expr = new_(Expr);
	expr->expr = TERM_CONST;
	KNH_SETv(ctx, expr->data, tk);
	return expr;
}

static knh_Expr_t *new_SugarExpr(CTX ctx, knh_Sugar_t *sgr, toks_t *toks)
{
	knh_Expr_t *expr = new_(Expr);
	expr->expr = TERM_CONST;
	DBG_ASSERT(expr == NULL);
	return expr;
}

// sugar NewTuple ::= "(" exprN ")"

static knh_Expr_t* matchSugarExpr(CTX ctx, toks_t *toks)
{
	knh_Lang_t *lang = toks->lang;
	int i, toks_cur = toks->cur; int toks_eol = toks->eol;
	toks_t rulebuf;
	while(lang != NULL) {
		knh_Array_t *l = DP(lang)->exprRulesNULL;
		if(l != NULL) {
			for(i = knh_Array_size(l) - 1; i >= 0; i--) {
				knh_Sugar_t *s = (knh_Sugar_t*)l->list[i];
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

static knh_Expr_t *matchTerm(CTX ctx, toks_t *toks)
{
	knh_Token_t *tk0 = tkN(toks, 0);
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
	case TK_URN:
	case TK_REGEX: {
		incN(toks, 1);
		return new_SingleTerm(ctx, tk0);
	}
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

static knh_Expr_t* matchExprLeft(CTX ctx, toks_t *toks)
{
	knh_Expr_t *expr = matchSugarExpr(ctx, toks);
	if(expr == NULL) {
		if(toks->status == FoundError) return NULL;
		expr = matchTerm(ctx, toks);
		if(toks->status == FoundError) return NULL;
	}
	while(hasN(toks, 0)) {

	}
	return expr;
}

// knh_DictMap_t*   tokenRulesNULL;

static int skipUninary(toks_t *toks, int n)
{
	//knh_Sugar_t *bin = Lang_getBinary(ctx, toks->lang, S_tobytes(tk->text));
	return nextT(toks, n);
}

static int findBinaryOperator(toks_t *toks)
{
	int idx = -1, i = skipUninary(toks, toks->cur), priority = 10000;
	knh_Token_t *tkf = NULL;
	for(i = toks->cur; i < toks->eol; i = nextT(toks, i)) {
		knh_Token_t *tk = toks->list->tokens[i];
		if(tk->token == TK_OPERATOR) {
			knh_Sugar_t *bin = (knh_Sugar_t*)knh_DictMap_getNULL(toks->ctx, DP(toks->lang)->binaryRulesNULL, S_tobytes(tk->text));
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

static knh_Expr_t *new_BinaryExpr(CTX ctx, knh_Token_t *tk, knh_Expr_t *lexpr, knh_Expr_t *rexpr)
{
	knh_Expr_t *expr = new_(Expr);
	KNH_SETv(ctx, expr->cons, new_Array0(ctx, 0));
	knh_Array_add(ctx, expr->cons, tk);
	knh_Array_add(ctx, expr->cons, lexpr);
	if(rexpr != NULL) {
		knh_Array_add(ctx, expr->cons, rexpr);
	}
	return expr;
}

static knh_Expr_t* matchExpr(CTX ctx, toks_t *toks)
{
	int idx = findBinaryOperator(toks);
	if(idx != -1) {
		toks_t ltoks, rtoks;
		sub(&ltoks, toks, toks->cur, idx);
		sub(&rtoks, toks, idx+1, toks->eol);
		knh_Expr_t *lexpr = matchExpr(ctx, &ltoks);
		if(lexpr == NULL) return NULL;
		knh_Expr_t *rexpr = matchExpr(ctx, &rtoks);
		if(rexpr == NULL) return NULL;
		knh_Token_t *tk = tkN(toks, idx);
//		knh_Sugar_t *bin = Lang_getBinary(ctx, toks->lang, S_tobytes(tk->text));
		return new_BinaryExpr(ctx, tk, lexpr, rexpr);
	}
	return matchExprLeft(ctx, toks);
}

static knh_Expr_t* matchBlock(CTX ctx, toks_t *toks)
{
	toks_t sub;
	knh_Token_t *tk0 = tkN(toks, 0);
	knh_Block_t *bk = NULL;
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
			1
		};
		parse(ctx, &tenvbuf, _METHOD);
		bk = new_Block(ctx, toks->list, toks_listsize, knh_Array_size(toks->list), toks->lang, toks->ns);
		knh_Array_clear(ctx, toks->list, toks_listsize);
	}
	return (knh_Expr_t*)bk;
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
