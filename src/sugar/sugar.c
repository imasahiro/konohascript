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

/* ************************************************************************ */

#include"commons.h"

/* ************************************************************************ */

#include "perror.h"
#include "token.h"
#include "stmt.h"
#include "ast.h"
#include "decl.h"
#include "typecheck.h"
//#include "build.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* [term] */


/* ------------------------------------------------------------------------ */
/* api */

// String[] String.tokenize()

static KMETHOD String_tokenize(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *a = new_Array(ctx, CLASS_String, 0);
	size_t i;
	tenv_t tenvbuf = {
		1,
		a,
		{S_totext(sfp[0].s)}, S_totext(sfp[0].s),
		ctx->bufa,
		BA_size(ctx->bufa),
		3,
	};
	parse(ctx, &tenvbuf, 0);
	for(i = 0; i < knh_Array_size(a); i++) {
		kToken *tk = (kToken*)a->list[i];
		KNH_SETv(ctx, a->list[i], tk->text);
	}
	RETURN_(a);
}

// Token[] Lang.tokenize(String script)

static KMETHOD Lang_tokenize(CTX ctx, ksfp_t *sfp _RIX)
{
	kArray *a = (kArray*)new_ReturnObject(ctx, sfp);
	tenv_t tenvbuf = {
		1,
		a,
		{S_totext(sfp[1].s)}, S_totext(sfp[1].s),
		ctx->bufa,
		BA_size(ctx->bufa),
		3,/*tabsize*/
		ctx->share->corelang,
	};
	KNH_SETv(ctx, sfp[K_RIX].o, a);
	parse(ctx, &tenvbuf, 0);
}

// only used in term.c
kArray* new_TokenArray(CTX ctx, const char *text, kline_t uline)
{
	kArray *a = (kArray*)new_Array0(ctx, 0);
	PUSH_GCSTACK(ctx, a);
	tenv_t tenvbuf = {
		uline,
		a,
		{text}, text,
		ctx->bufa,
		BA_size(ctx->bufa),
		3,/*tabsize*/
		ctx->share->corelang,
	};
	DBG_ASSERT(!(BA_totext(ctx->bufa) <= text && text < BA_totext(ctx->bufa) + BA_size(ctx->bufa)));
	parse(ctx, &tenvbuf, _TOPLEVEL);
	dumpTokenArray(ctx, 0, a, 0, knh_Array_size(a));
	return a;
}

static kBlock* new_BlockTEXT(CTX ctx, kLang *lang, kNameSpace *ns, const char* script, kline_t uline)
{
	kArray *a = new_Array(ctx, CLASS_Token, 0);
	PUSH_GCSTACK(ctx, a);
	tenv_t tenvbuf = {
		uline,
		a,
		{script}, script,
		ctx->bufa,
		BA_size(ctx->bufa),
		3,/*tabsize*/
		lang,
	};
	parse(ctx, &tenvbuf, _TOPLEVEL);
	kBlock *bk = new_Block(ctx, a, 0, knh_Array_size(a), lang, ns);
	return bk;
}

// @Static Block Lang.newBlock(String script, int uline, NameSpace _)

static KMETHOD Lang_newBlock(CTX ctx, ksfp_t *sfp _RIX)
{
	kLang *lang = ctx->share->corelang;
	kline_t uline = sfp[2].ivalue == 0 ? 1 : (kline_t)sfp[2].ivalue;
	GCRETURN_(new_BlockTEXT(ctx, lang, sfp[3].ns, S_totext(sfp[1].s), uline));
}

//// void boolean Lang_evalBlock(Block block, NameSpace _);
//
//static KMETHOD Block_eval(CTX ctx, ksfp_t *sfp _RIX)
//{
//	kLang *lang = ctx->share->corelang;
//	kBlock *bk = sfp[1].bk;
//	size_t i;
//	for(i = 0; i < knh_Array_size(bk->blocks); i++) {
//		kStmt *stmt = (kStmt*)bk->blocks->list[i];
//		kMethod *mtd = NULL;//Lang_getEvalNULL(ctx, lang, stmt->key);
//		if(mtd != NULL) {
//
//		}
//	}
//	RETURNb_(1);
//}
//
//// void boolean Block_typeCheck(Gamma gma);
//
//static KMETHOD Block_typeCheck(CTX ctx, ksfp_t *sfp _RIX)
//{
//	kLang *lang = ctx->share->corelang;
//	kBlock *bk = sfp[0].bk;
//	size_t i;
//	for(i = 0; i < knh_Array_size(bk->blocks); i++) {
//		kStmt *stmt = (kStmt*)bk->blocks->list[i];
//		kMethod *mtd = NULL;//Lang_getTypeCheckNULL(ctx, lang, stmt->key);
//		if(mtd != NULL) {
//
//		}
//	}
//	RETURNb_(1);
//}
//
//// void boolean Block_build(Builder build);
//
//static KMETHOD Block_build(CTX ctx, ksfp_t *sfp _RIX)
//{
//	RETURNb_(1);
//}

static KMETHOD Token_getType(CTX ctx, ksfp_t *sfp _RIX)
{
	kToken *tok = (kToken*)sfp[0].o;
	RETURNi_(tok->token);
}

static KMETHOD Token_getText(CTX ctx, ksfp_t *sfp _RIX)
{
	kToken *tok = (kToken*)sfp[0].o;
	RETURN_(tok->text);
}

static KMETHOD Token_getLine(CTX ctx, ksfp_t *sfp _RIX)
{
	kToken *tok = (kToken*)sfp[0].o;
	RETURNi_(ULINE_line(tok->uline));
}

static KMETHOD Token_getPosition(CTX ctx, ksfp_t *sfp _RIX)
{
	kToken *tok = (kToken*)sfp[0].o;
	RETURNi_(tok->lpos);
}

static KMETHOD Token_error(CTX ctx, ksfp_t *sfp _RIX)
{
	kToken *tok = (kToken*)sfp[0].o;
	knh_perror(ctx, ERR_, tok->uline, tok->lpos, "%s", S_totext(sfp[1].s));
}

static KMETHOD Token_warn(CTX ctx, ksfp_t *sfp _RIX)
{
	kToken *tok = (kToken*)sfp[0].o;
	knh_perror(ctx, WARN_, tok->uline, tok->lpos, "%s", S_totext(sfp[1].s));
}

static KMETHOD Token_info(CTX ctx, ksfp_t *sfp _RIX)
{
	kToken *tok = (kToken*)sfp[0].o;
	knh_perror(ctx, INFO_, tok->uline, tok->lpos, "%s", S_totext(sfp[1].s));
}

/* ------------------------------------------------------------------------ */

static kline_t readQuote(CTX ctx, kInputStream *in, kline_t line, kBytes *ba, int quote)
{
	int ch, prev = quote;
	while((ch = knh_InputStream_getc(ctx, in)) != EOF) {
		if(ch == '\r') continue;
		knh_Bytes_putc(ctx, ba, ch);
		if(ch == '\n') line++;
		if(ch == quote && prev != '\\') {
			return line;
		}
		prev = ch;
	}
	return line;
}

static kline_t readComment(CTX ctx, kInputStream *in, kline_t line, kBytes *ba)
{
	int ch, prev = 0, level = 1;
	while((ch = knh_InputStream_getc(ctx, in)) != EOF) {
		if(ch == '\r') continue;
		knh_Bytes_putc(ctx, ba, ch);
		if(ch == '\n') line++;
		if(prev == '*' && ch == '/') level--;
		if(prev == '/' && ch == '*') level++;
		if(level == 0) return line;
		prev = ch;
	}
	return line;
}

static kline_t readChunk(CTX ctx, kInputStream *in, kline_t line, kBytes *ba)
{
	int ch;
	int prev = 0, isBLOCK = 0;
	while((ch = knh_InputStream_getc(ctx, in)) != EOF) {
		if(ch == '\r') continue;
		if(ch == '\n') line++;
		knh_Bytes_putc(ctx, ba, ch);
		if(prev == '/' && ch == '*') {
			line = readComment(ctx, in, line, ba);
			continue;
		}
		if(ch == '\'' || ch == '"' || ch == '`') {
			line = readQuote(ctx, in, line, ba, ch);
			continue;
		}
		if(isBLOCK != 1 && prev == '\n' && ch == '\n') {
			break;
		}
		if(prev == '{') {
			isBLOCK = 1;
		}
		if(prev == '\n' && ch == '}') {
			isBLOCK = 0;
		}
		prev = ch;
	}
	return line;
}

static int isempty(kbytes_t t)
{
	size_t i;
	for(i = 0; i < t.len; i++) {
		if(!isspace(t.utext[i])) return 0;
	}
	return 1;
}

static void loadScriptFile(CTX ctx, kLang *lang, kNameSpace *ns, kPath *path)
{
	kio_t *io2 = path->dpi->io2openNULL(ctx, path, "r", NULL);
	INIT_GCSTACK(ctx);
	if(io2 != NULL) {
		kInputStream *in = new_InputStream(ctx, io2, path);
		PUSH_GCSTACK(ctx, in);
		kline_t uline = 1;
		kuri_t uri = knh_getURI(ctx, S_tobytes(path->urn));
		ULINE_setURI(uline, uri);
		kBytes*ba = new_Bytes(ctx, "chunk", K_PAGESIZE);
		PUSH_GCSTACK(ctx, ba);
		kline_t linenum = uline;
		do {
			knh_Bytes_clear(ba, 0);
			if(!io2_isClosed(ctx, in->io2)) {
				uline = linenum;
				linenum = readChunk(ctx, in, linenum, ba);
			}
			if(!isempty(ba->bu)) {
//				DBG_(if(knh_isVerboseLang()) {
					fprintf(stderr, "\n>>>--------------------------------\n");
					fprintf(stderr, "%s<<<--------------------------------\n", knh_Bytes_ensureZero(ctx, ba));
//				});
				kBlock *bk = new_BlockTEXT(ctx, lang, ns, knh_Bytes_ensureZero(ctx, ba), uline);
				knh_write_Object(ctx, KNH_STDOUT, UPCAST(bk), FMT_dump);
				RESET_GCSTACK(ctx);
			}
		} while(BA_size(ba) > 0);
	}
	RESET_GCSTACK(ctx);
}

// @Static Block Lang.load(Path path, NameSpace ns)

static KMETHOD Lang_load(CTX ctx, ksfp_t *sfp _RIX)
{
	kLang *lang = ctx->share->corelang;
	loadScriptFile(ctx, lang, sfp[2].ns, sfp[1].pth);
}

// sugar tokens "=>" uname;

#define FuncData(X) {#X , X}

static knh_FuncData_t FuncData[] = {
	FuncData(String_tokenize),
	FuncData(Lang_tokenize),
	FuncData(Lang_newBlock),
	FuncData(Token_getLine),
	FuncData(Token_getText),
	FuncData(Token_getType),
	FuncData(Token_getPosition),
	FuncData(Token_error),
	FuncData(Token_warn),
	FuncData(Token_info),
	FuncData(Lang_evalMethodDecl),
	FuncData(Lang_evalSugarDecl),
	FuncData(Lang_load),
	{NULL, NULL},
};

static knh_IntData_t TokenConstInt[] = {
	{"CODE", TK_CODE},
	{"USYMBOL", TK_USYMBOL},
	{"SYMBOL", TK_SYMBOL},
	{"OPERATOR", TK_OPERATOR},
	{"TEXT2", TK_TEXT},
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

struct sugardef_t {
	ksugar_t sugar;
	const char *key;
	const char *rule;
} ;

// sugar name ':' type ::= type name

static struct sugardef_t sugars[] = {
	{SUGAR_DECL, "SugarDecl",  "'sugar' name '::=' tokens"},
	{SUGAR_DECL, "MethodDecl", "type [cname '.'] name params block"},
//	{SUGAR_DECL, "VarDecl",    "type name ['=' expr] [',' name ['=' expr]]"},
	{SUGAR_DECL, "VarDecl",    "type name ['=' expr]"},
	{SUGAR_STMT, "IfStmt",     "'if' ^ '(' expr ')' block ['else' block]"},
	{SUGAR_STMT, "ReturnStmt", "'return' [expr]"},
//	{SUGAR_BINARY, "AddOp", "expr '+' expr", 10},
	{0, NULL, NULL},
};

struct opdef_t {
	ksugar_t sugar;
	const char *key;
	kuintptr_t  mn;
};

#define _OPMN(P, MN)    (((kuintptr_t)P << (sizeof(kmethodn_t) * 8)) | (kuintptr_t)MN)

/*
=       TT_LET          0      2       MN_NONAME
#<<<     TT_SEND         0      2      MN_send
#>>>     TT_RECV         0      2      MN_NONAME
#a = a >>> function(it) {
#}

?\?     TT_ALT          0      4       MN_NONAME
?       TT_QTN          0      4       MN_NONAME
:       TT_COLON        0      99      MN_NONAME
.       TT_DOT          0      99      MN_NONAME
or      TT_OR           0      5       MN_NONAME
and     TT_AND          0      6       MN_NONAME
not     TT_NOT          0      7       MN_opNOT
exists  TT_EXISTS       0      8       MN_opEXISTS
::      TT_LINK         0      9       MN_opLINK
:?      TT_QUERY        0      9       MN_opQUERY
from    TT_FROM         0      9       MN_opFROM
until   TT_UNTIL        0      9       MN_opUNTIL

# f() as Class == 1

#define    TT_isBINARY(tt) (TT_IS <= (tt) && (tt) <= TT_RSFT)
is?        TT_IS        _BIN    10      MN_opIS
<:         TT_OF        _BIN    10      MN_opOF
in?        TT_IN        _BIN    10      MN_opHAS
to         TT_TO        _BIN    10      MN_opTO
==         TT_EQ        _BIN    10      MN_opEQ
!=         TT_NEQ       _BIN    10      MN_opNOTEQ
<          TT_LT        _BIN    10      MN_opLT
<=         TT_LTE       _BIN    10      MN_opLTE
>          TT_GT        _BIN    10      MN_opGT
>=         TT_GTE       _BIN    10      MN_opGTE

with       TT_WITH      _BIN    12      MN_opWITH
match      TT_MATCH     _BIN    12      MN_opMATCH
as         TT_AS        _BIN    12      MN_opAS
where      TT_WHERE     _BIN    12      MN_opWHERE
each       TT_EACH      _BIN    12      MN_opEACH

|          TT_LOR       _BIN    14      MN_opLOR
^          TT_XOR       _BIN    16      MN_opLXOR
&          TT_LAND      _BIN    18      MN_opLAND
+          TT_ADD       _BIN    20      MN_opADD
-          TT_SUB       _BIN    20      MN_opSUB
/          TT_DIV       _BIN    25      MN_opDIV
%          TT_MOD       _BIN    25      MN_opMOD
*          TT_MUL       _BIN    25      MN_opMUL
<<         TT_LSFT      _BIN    35      MN_opLSFT
>>         TT_RSFT      _BIN    35      MN_opRSFT

~          TT_LNOT      0       40      MN_opLNOT
++         TT_NEXT      0       40      MN_opNEXT
--         TT_PREV      0       40      MN_opPREV
..         TT_ITR       0       40      MN_opITR
()         TT_SEQ       0       40      MN_opSEQ
!!         TT_EXPT      0       40      MN_opEXPT
&&&        TT_TAND      0       40      MN_opADDR
***        TT_TMUL      0       40      MN_opCAST
+++        TT_TADD      0       40      MN_opPLUS
---        TT_TSUB      0       40      MN_opNEG
'''
**/
static struct opdef_t ops[] = {
	{SUGAR_BINARY, "=",   _OPMN(10L, MN_)},
	{SUGAR_BINARY, "||",  _OPMN(20L, MN_)},
	{SUGAR_BINARY, "&&",  _OPMN(20L, MN_)},
	{SUGAR_UNINARY, "!",  _OPMN(0L,  MN_opNOT)},
	{SUGAR_BINARY, "==",  _OPMN(100L,  MN_opEQ)},
	{SUGAR_BINARY, "!=",  _OPMN(100L,  MN_opNOTEQ)},
	{SUGAR_BINARY, "<",   _OPMN(100L,  MN_opLT)},
	{SUGAR_BINARY, "<=",  _OPMN(100L,  MN_opLTE)},
	{SUGAR_BINARY, ">",   _OPMN(100L,  MN_opGT)},
	{SUGAR_BINARY, ">=",  _OPMN(100L,  MN_opGTE)},

	{SUGAR_BINARY, "+",   _OPMN(1000L,  MN_opADD)},
	{SUGAR_BINARY, "-",   _OPMN(1000L,  MN_opSUB)},
	{SUGAR_BINARY, "*",   _OPMN(1200L,  MN_opMUL)},
	{SUGAR_BINARY, "/",   _OPMN(1200L,  MN_opDIV)},
	{SUGAR_BINARY, "%",   _OPMN(1200L,  MN_opMOD)},

	{SUGAR_UNINARY, "+",   _OPMN(0L,  MN_opPLUS)},
	{SUGAR_UNINARY, "-",   _OPMN(0L,  MN_opNEG)},

//	{SUGAR_BINARY, "AddOp", "expr '+' expr", 10},
	{0, NULL, 0},
};

static void loadSugarDef(CTX ctx, kLang *lang, struct sugardef_t *sd, struct opdef_t *od)
{
	while(sd->key != NULL) {
		kSugar *sgr = new_(Sugar);
		sgr->sugar = sd->sugar;
		KNH_SETv(ctx, sgr->key, new_T(sd->key));
		KNH_SETv(ctx, sgr->rules, new_Array0(ctx, 0));
		tenv_t tenvbuf = {
			0,/*uline*/
			sgr->rules,
			{sd->rule}, sd->rule,
			ctx->bufa,
			BA_size(ctx->bufa),
			3,/*tabsize*/
			lang,
		};
		parse(ctx, &tenvbuf, 0);
		Lang_addSugar(ctx, lang, sgr, 0);
		dumpTokenArray(ctx, 0, sgr->rules, 0, knh_Array_size(sgr->rules));
		sd++;
	}
	while(od->key != NULL) {
		if(od->sugar == SUGAR_BINARY) {
			Lang_addBinary(ctx, lang, new_T(od->key), od->mn);
		}
		else {
			Lang_addUninary(ctx, lang, new_T(od->key), od->mn);
		}
		od++;
	}
}

void knh_initSugarFuncData(CTX ctx, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, CLASS_Token, TokenConstInt);
	kapi->loadFuncData(ctx, FuncData);
}

void knh_initSugarData(CTX ctx)
{
	loadSugarDef(ctx, ctx->share->corelang, sugars, ops);
}

#ifdef __cplusplus
}
#endif
