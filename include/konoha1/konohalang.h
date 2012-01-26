// THIS FILE WAS AUTOMATICALLY GENERATED

#ifdef __cplusplus
extern "C" {
#endif


#ifndef MN_OPSIZE
#define STT_MAX  (58)
#define TT_MAX   (143)
#define MN_OPSIZE  (41)
#define MN_opNOT                        ((kmethodn_t)0)
#define MN_opEXISTS                     ((kmethodn_t)1)
#define MN_opLINK                       ((kmethodn_t)2)
#define MN_opQUERY                      ((kmethodn_t)3)
#define MN_opFROM                       ((kmethodn_t)4)
#define MN_opUNTIL                      ((kmethodn_t)5)
#define MN_opIS                         ((kmethodn_t)6)
#define MN_opOF                         ((kmethodn_t)7)
#define MN_opHAS                        ((kmethodn_t)8)
#define MN_opTO                         ((kmethodn_t)9)
#define MN_opEQ                         ((kmethodn_t)10)
#define MN_opNOTEQ                      ((kmethodn_t)11)
#define MN_opLT                         ((kmethodn_t)12)
#define MN_opLTE                        ((kmethodn_t)13)
#define MN_opGT                         ((kmethodn_t)14)
#define MN_opGTE                        ((kmethodn_t)15)
#define MN_opWITH                       ((kmethodn_t)16)
#define MN_opMATCH                      ((kmethodn_t)17)
#define MN_opAS                         ((kmethodn_t)18)
#define MN_opWHERE                      ((kmethodn_t)19)
#define MN_opEACH                       ((kmethodn_t)20)
#define MN_opLOR                        ((kmethodn_t)21)
#define MN_opLXOR                       ((kmethodn_t)22)
#define MN_opLAND                       ((kmethodn_t)23)
#define MN_opADD                        ((kmethodn_t)24)
#define MN_opSUB                        ((kmethodn_t)25)
#define MN_opDIV                        ((kmethodn_t)26)
#define MN_opMOD                        ((kmethodn_t)27)
#define MN_opMUL                        ((kmethodn_t)28)
#define MN_opLSFT                       ((kmethodn_t)29)
#define MN_opRSFT                       ((kmethodn_t)30)
#define MN_opLNOT                       ((kmethodn_t)31)
#define MN_opNEXT                       ((kmethodn_t)32)
#define MN_opPREV                       ((kmethodn_t)33)
#define MN_opITR                        ((kmethodn_t)34)
#define MN_opSEQ                        ((kmethodn_t)35)
#define MN_opEXPT                       ((kmethodn_t)36)
#define MN_opADDR                       ((kmethodn_t)37)
#define MN_opCAST                       ((kmethodn_t)38)
#define MN_opPLUS                       ((kmethodn_t)39)
#define MN_opNEG                        ((kmethodn_t)40)

/* ------------------------------------------------------------------------ */

#define STT_DONE  ((kterm_t)0)
#define STT_BLOCK  ((kterm_t)1)
#define STT_PRAGMA  ((kterm_t)2)
#define STT_NAMESPACE  ((kterm_t)3)
#define STT_DEFMACRO  ((kterm_t)4)
#define STT_INCLUDE  ((kterm_t)5)
#define STT_ALLOW  ((kterm_t)6)
#define STT_DENY  ((kterm_t)7)
#define STT_USING  ((kterm_t)8)
#define STT_CLASS  ((kterm_t)9)
#define STT_FORMAT  ((kterm_t)10)
#define STT_RETURN  ((kterm_t)11)
#define STT_YIELD  ((kterm_t)12)
#define STT_IF  ((kterm_t)13)
#define STT_SWITCH  ((kterm_t)14)
#define STT_CASE  ((kterm_t)15)
#define STT_WHILE  ((kterm_t)16)
#define STT_DO  ((kterm_t)17)
#define STT_FOR  ((kterm_t)18)
#define STT_FOREACH  ((kterm_t)19)
#define STT_BREAK  ((kterm_t)20)
#define STT_CONTINUE  ((kterm_t)21)
#define STT_TRY  ((kterm_t)22)
#define STT_CATCH  ((kterm_t)23)
#define STT_THROW  ((kterm_t)24)
#define STT_PRINT  ((kterm_t)25)
#define STT_ASSURE  ((kterm_t)26)
#define STT_ASSERT  ((kterm_t)27)
#define STT_REGISTER  ((kterm_t)28)
#define STT_FUNCTION  ((kterm_t)29)
#define STT_METHOD  ((kterm_t)30)
#define STT_TYPEMAP  ((kterm_t)31)
#define STT_DECL  ((kterm_t)32)
#define STT_CHKOUT  ((kterm_t)33)
#define STT_LETM  ((kterm_t)34)
#define STT_SELECT  ((kterm_t)35)
#define STT_SWAP  ((kterm_t)36)
#define STT_CONST  ((kterm_t)37)
#define STT_ERR  ((kterm_t)38)
#define STT_LET  ((kterm_t)39)
#define STT_TCAST  ((kterm_t)40)
#define STT_BOX  ((kterm_t)41)
#define STT_OPR  ((kterm_t)42)
#define STT_CALL  ((kterm_t)43)
#define STT_NEW  ((kterm_t)44)
#define STT_FUNCCALL  ((kterm_t)45)
#define STT_ACALL  ((kterm_t)46)
#define STT_THUNK  ((kterm_t)47)
#define STT_TLINK  ((kterm_t)48)
#define STT_ALT  ((kterm_t)49)
#define STT_MATCH  ((kterm_t)50)
#define STT_TRI  ((kterm_t)51)
#define STT_AND  ((kterm_t)52)
#define STT_OR  ((kterm_t)53)
#define STT_W1  ((kterm_t)54)
#define STT_SEND  ((kterm_t)55)
#define STT_FMTCALL  ((kterm_t)56)
#define STT_CALL1  ((kterm_t)57)
#define TT_PRAGMA   ((kterm_t)58)
#define TT_NAMESPACE   ((kterm_t)59)
#define TT_INCLUDE   ((kterm_t)60)
#define TT_IMPORT   ((kterm_t)61)
#define TT_USING   ((kterm_t)62)
#define TT_CLASS   ((kterm_t)63)
#define TT_FORMAT   ((kterm_t)64)
#define TT_RETURN   ((kterm_t)65)
#define TT_YIELD   ((kterm_t)66)
#define TT_IF   ((kterm_t)67)
#define TT_SWITCH   ((kterm_t)68)
#define TT_CASE   ((kterm_t)69)
#define TT_WHILE   ((kterm_t)70)
#define TT_DO   ((kterm_t)71)
#define TT_FOR   ((kterm_t)72)
#define TT_FOREACH   ((kterm_t)73)
#define TT_BREAK   ((kterm_t)74)
#define TT_CONTINUE   ((kterm_t)75)
#define TT_GOTO   ((kterm_t)76)
#define TT_TRY   ((kterm_t)77)
#define TT_CATCH   ((kterm_t)78)
#define TT_THROW   ((kterm_t)79)
#define TT_PRINT   ((kterm_t)80)
#define TT_ASSURE   ((kterm_t)81)
#define TT_ASSERT   ((kterm_t)82)
#define TT_REGISTER   ((kterm_t)83)
#define TT_EXTENDS   ((kterm_t)84)
#define TT_IMPLEMENTS   ((kterm_t)85)
#define TT_ELSE   ((kterm_t)86)
#define TT_DEFAULT   ((kterm_t)87)
#define TT_FINALLY   ((kterm_t)88)
#define TT_SEMICOLON   ((kterm_t)89)
#define TT_COMMA   ((kterm_t)90)
#define TT_DIAMOND   ((kterm_t)91)
#define TT_ARROW   ((kterm_t)92)
#define TT_DARROW   ((kterm_t)93)
#define TT_TARROW   ((kterm_t)94)
#define TT_TDARROW   ((kterm_t)95)
#define TT_LSEND   ((kterm_t)96)
#define TT_RSEND   ((kterm_t)97)
#define TT_DOTS   ((kterm_t)98)
#define TT_DMUL   ((kterm_t)99)
#define TT_ASIS   ((kterm_t)100)
#define TT_FUNCTION   ((kterm_t)101)
#define TT_NEW   ((kterm_t)102)
#define TT_NULL   ((kterm_t)103)
#define TT_TYPEOF   ((kterm_t)104)
#define TT_VOID   ((kterm_t)105)
#define TT_VAR   ((kterm_t)106)
#define TT_BYTE   ((kterm_t)107)
#define TT_DYNAMIC   ((kterm_t)108)
#define TT_TRUE   ((kterm_t)109)
#define TT_FALSE   ((kterm_t)110)
#define TT_BRACE   ((kterm_t)111)
#define TT_PARENTHESIS   ((kterm_t)112)
#define TT_BRANCET   ((kterm_t)113)
#define TT_DECLLET   ((kterm_t)114)
#define TT_LSFTE   ((kterm_t)115)
#define TT_RSFTE   ((kterm_t)116)
#define TT_ADDE   ((kterm_t)117)
#define TT_SUBE   ((kterm_t)118)
#define TT_DIVE   ((kterm_t)119)
#define TT_MODE   ((kterm_t)120)
#define TT_MULE   ((kterm_t)121)
#define TT_LANDE   ((kterm_t)122)
#define TT_LORE   ((kterm_t)123)
#define TT_ALTLET   ((kterm_t)124)
#define TT_LET   ((kterm_t)125)
#define TT_ALT   ((kterm_t)126)
#define TT_QTN   ((kterm_t)127)
#define TT_COLON   ((kterm_t)128)
#define TT_DOT   ((kterm_t)129)
#define TT_OR   ((kterm_t)130)
#define TT_AND   ((kterm_t)131)
#define TT_NOT   ((kterm_t)132)
#define TT_EXISTS   ((kterm_t)133)
#define TT_LINK   ((kterm_t)134)
#define TT_QUERY   ((kterm_t)135)
#define TT_FROM   ((kterm_t)136)
#define TT_UNTIL   ((kterm_t)137)
#define TT_IS   ((kterm_t)138)
#define TT_OF   ((kterm_t)139)
#define TT_IN   ((kterm_t)140)
#define TT_TO   ((kterm_t)141)
#define TT_EQ   ((kterm_t)142)
#define TT_NEQ   ((kterm_t)143)
#define TT_LT   ((kterm_t)144)
#define TT_LTE   ((kterm_t)145)
#define TT_GT   ((kterm_t)146)
#define TT_GTE   ((kterm_t)147)
#define TT_WITH   ((kterm_t)148)
#define TT_MATCH   ((kterm_t)149)
#define TT_AS   ((kterm_t)150)
#define TT_WHERE   ((kterm_t)151)
#define TT_EACH   ((kterm_t)152)
#define TT_LOR   ((kterm_t)153)
#define TT_XOR   ((kterm_t)154)
#define TT_LAND   ((kterm_t)155)
#define TT_ADD   ((kterm_t)156)
#define TT_SUB   ((kterm_t)157)
#define TT_DIV   ((kterm_t)158)
#define TT_MOD   ((kterm_t)159)
#define TT_MUL   ((kterm_t)160)
#define TT_LSFT   ((kterm_t)161)
#define TT_RSFT   ((kterm_t)162)
#define TT_LNOT   ((kterm_t)163)
#define TT_NEXT   ((kterm_t)164)
#define TT_PREV   ((kterm_t)165)
#define TT_ITR   ((kterm_t)166)
#define TT_SEQ   ((kterm_t)167)
#define TT_EXPT   ((kterm_t)168)
#define TT_TAND   ((kterm_t)169)
#define TT_TMUL   ((kterm_t)170)
#define TT_TADD   ((kterm_t)171)
#define TT_TSUB   ((kterm_t)172)
#define TT_CODE   ((kterm_t)173)
#define TT_DOCU   ((kterm_t)174)
#define TT_NUM   ((kterm_t)175)
#define TT_STR   ((kterm_t)176)
#define TT_TSTR   ((kterm_t)177)
#define TT_ESTR   ((kterm_t)178)
#define TT_REGEX   ((kterm_t)179)
#define TT_DOC   ((kterm_t)180)
#define TT_METAN   ((kterm_t)181)
#define TT_PROPN   ((kterm_t)182)
#define TT_URN   ((kterm_t)183)
#define TT_TLINK   ((kterm_t)184)
#define TT_NAME   ((kterm_t)185)
#define TT_UNAME   ((kterm_t)186)
#define TT_FUNCNAME   ((kterm_t)187)
#define TT_UFUNCNAME   ((kterm_t)188)
#define TT_PTYPE   ((kterm_t)189)
#define TT_CID   ((kterm_t)190)
#define TT_MN   ((kterm_t)191)
#define TT_FMT   ((kterm_t)192)
#define TT_CONST   ((kterm_t)193)
#define TT_SYSVAL   ((kterm_t)194)
#define TT_FVAR   ((kterm_t)195)
#define TT_LVAR   ((kterm_t)196)
#define TT_FIELD   ((kterm_t)197)
#define TT_LFIELD   ((kterm_t)198)
#define TT_ERR   ((kterm_t)199)
#define TT_EOT   ((kterm_t)200)
#endif/*MN_OPSIZE*/


#ifdef K_USING_LOADDATA

typedef struct {
	const char *name;
	kflag_t  flag;
	kshort_t to;
} TERMDATA_t;

#define _BIN 1

static TERMDATA_t TERMDATA[] = {
	{"DONE", 0, -1}, 
	{"BLOCK", 0, -1}, 
	{"pragma", 0, -1}, 
	{"namespace", 0, -1}, 
	{"defmacro", 0, -1}, 
	{"include", 0, -1}, 
	{"allow", 0, -1}, 
	{"deny", 0, -1}, 
	{"using", 0, -1}, 
	{"class", 0, -1}, 
	{"format", 0, -1}, 
	{"return", 0, -1}, 
	{"yield", 0, -1}, 
	{"if", 0, -1}, 
	{"switch", 0, -1}, 
	{"case", 0, -1}, 
	{"while", 0, -1}, 
	{"do", 0, -1}, 
	{"for", 0, -1}, 
	{"foreach", 0, -1}, 
	{"break", 0, -1}, 
	{"continue", 0, -1}, 
	{"try", 0, -1}, 
	{"catch", 0, -1}, 
	{"throw", 0, -1}, 
	{"print", 0, -1}, 
	{"assure", 0, -1}, 
	{"assert", 0, -1}, 
	{"register", 0, -1}, 
	{"function", 0, -1}, 
	{"METHOD", 0, -1}, 
	{"TYPEMAP", 0, -1}, 
	{"DECL", 0, -1}, 
	{"CHKOUT", 0, -1}, 
	{"LETM", 0, -1}, 
	{"SELECT", 0, -1}, 
	{"SWAP", 0, -1}, 
	{"CONST", 0, -1}, 
	{"ERR", 0, -1}, 
	{"LET", 0, -1}, 
	{"TCAST", 0, -1}, 
	{"BOX", 0, -1}, 
	{"OPR", 0, -1}, 
	{"CALL", 0, -1}, 
	{"NEW", 0, -1}, 
	{"FUNCCALL", 0, -1}, 
	{"ACALL", 0, -1}, 
	{"THUNK", 0, -1}, 
	{"TLINK", 0, -1}, 
	{"ALT", 0, -1}, 
	{"MATCH", 0, -1}, 
	{"TRI", 0, -1}, 
	{"AND", 0, -1}, 
	{"OR", 0, -1}, 
	{"W1", 0, -1}, 
	{"SEND", 0, -1}, 
	{"FMTCALL", 0, -1}, 
	{"CALL1", 0, -1}, 
	{"pragma", 0, STT_PRAGMA}, 
	{"namespace", 0, STT_NAMESPACE}, 
	{"include", 0, STT_INCLUDE}, 
	{"import", 0, -1}, 
	{"using", 0, STT_USING}, 
	{"class", 0, STT_CLASS}, 
	{"format", 0, STT_FORMAT}, 
	{"return", 0, STT_RETURN}, 
	{"yield", 0, STT_YIELD}, 
	{"if", 0, STT_IF}, 
	{"switch", 0, STT_SWITCH}, 
	{"case", 0, STT_CASE}, 
	{"while", 0, STT_WHILE}, 
	{"do", 0, STT_DO}, 
	{"for", 0, STT_FOR}, 
	{"foreach", 0, STT_FOREACH}, 
	{"break", 0, STT_BREAK}, 
	{"continue", 0, STT_CONTINUE}, 
	{"goto", 0, -1}, 
	{"try", 0, STT_TRY}, 
	{"catch", 0, STT_CATCH}, 
	{"throw", 0, STT_THROW}, 
	{"print", 0, STT_PRINT}, 
	{"assure", 0, STT_ASSURE}, 
	{"assert", 0, STT_ASSERT}, 
	{"register", 0, STT_REGISTER}, 
	{"extends", 0, -1}, 
	{"implements", 0, -1}, 
	{"else", 0, -1}, 
	{"default", 0, -1}, 
	{"finally", 0, -1}, 
	{";", 0, -1}, 
	{",", 0, -1}, 
	{"<>", 0, -1}, 
	{"->", 0, -1}, 
	{"=>", 0, -1}, 
	{"-->", 0, -1}, 
	{"==>", 0, -1}, 
	{"<<<", 0, -1}, 
	{">>>", 0, -1}, 
	{"...", 0, -1}, 
	{"**", 0, -1}, 
	{"_", 0, -1}, 
	{"function", 0, STT_FUNCTION}, 
	{"new", 0, -1}, 
	{"null", 0, -1}, 
	{"typeof", 0, -1}, 
	{"void", 0, -1}, 
	{"var", 0, -1}, 
	{"byte", 0, -1}, 
	{"dynamic", 0, -1}, 
	{"true", 0, -1}, 
	{"false", 0, -1}, 
	{"{", 0, -1}, 
	{"(", 0, -1}, 
	{"[", 0, -1}, 
	{":=", 0, -1}, 
	{"<<=", 0, TT_LSFT}, 
	{">>=", 0, TT_RSFT}, 
	{"+=", 0, TT_ADD}, 
	{"-=", 0, TT_SUB}, 
	{"/=", 0, TT_DIV}, 
	{"%=", 0, TT_MOD}, 
	{"*=", 0, TT_MUL}, 
	{"&=", 0, TT_LAND}, 
	{"|=", 0, TT_LOR}, 
	{"?\?=", 0, TT_ALT}, 
	{"=", 0, MN_NONAME}, 
	{"?\?", 0, MN_NONAME}, 
	{"?", 0, MN_NONAME}, 
	{":", 0, MN_NONAME}, 
	{".", 0, MN_NONAME}, 
	{"or", 0, MN_NONAME}, 
	{"and", 0, MN_NONAME}, 
	{"not", 0, MN_opNOT}, 
	{"exists", 0, MN_opEXISTS}, 
	{"::", 0, MN_opLINK}, 
	{":?", 0, MN_opQUERY}, 
	{"from", 0, MN_opFROM}, 
	{"until", 0, MN_opUNTIL}, 
	{"is?", _BIN, MN_opIS}, 
	{"<:", _BIN, MN_opOF}, 
	{"in?", _BIN, MN_opHAS}, 
	{"to", _BIN, MN_opTO}, 
	{"==", _BIN, MN_opEQ}, 
	{"!=", _BIN, MN_opNOTEQ}, 
	{"<", _BIN, MN_opLT}, 
	{"<=", _BIN, MN_opLTE}, 
	{">", _BIN, MN_opGT}, 
	{">=", _BIN, MN_opGTE}, 
	{"with", _BIN, MN_opWITH}, 
	{"match", _BIN, MN_opMATCH}, 
	{"as", _BIN, MN_opAS}, 
	{"where", _BIN, MN_opWHERE}, 
	{"each", _BIN, MN_opEACH}, 
	{"|", _BIN, MN_opLOR}, 
	{"^", _BIN, MN_opLXOR}, 
	{"&", _BIN, MN_opLAND}, 
	{"+", _BIN, MN_opADD}, 
	{"-", _BIN, MN_opSUB}, 
	{"/", _BIN, MN_opDIV}, 
	{"%", _BIN, MN_opMOD}, 
	{"*", _BIN, MN_opMUL}, 
	{"<<", _BIN, MN_opLSFT}, 
	{">>", _BIN, MN_opRSFT}, 
	{"~", 0, MN_opLNOT}, 
	{"++", 0, MN_opNEXT}, 
	{"--", 0, MN_opPREV}, 
	{"..", 0, MN_opITR}, 
	{"()", 0, MN_opSEQ}, 
	{"!!", 0, MN_opEXPT}, 
	{"&&&", 0, MN_opADDR}, 
	{"***", 0, MN_opCAST}, 
	{"+++", 0, MN_opPLUS}, 
	{"---", 0, MN_opNEG}, 
	{"CODE", 0, -1}, 
	{"DOCU", 0, -1}, 
	{"NUM", 0, -1}, 
	{"STR", 0, -1}, 
	{"TSTR", 0, -1}, 
	{"ESTR", 0, -1}, 
	{"REGEX", 0, -1}, 
	{"DOC", 0, -1}, 
	{"METAN", 0, -1}, 
	{"PROPN", 0, -1}, 
	{"URN", 0, -1}, 
	{"TLINK", 0, -1}, 
	{"NAME", 0, -1}, 
	{"UNAME", 0, -1}, 
	{"FUNCNAME", 0, -1}, 
	{"UFUNCNAME", 0, -1}, 
	{"PTYPE", 0, -1}, 
	{"CID", 0, -1}, 
	{"MN", 0, -1}, 
	{"FMT", 0, -1}, 
	{"CONST", 0, -1}, 
	{"SYSVAL", 0, -1}, 
	{"FVAR", 0, -1}, 
	{"LVAR", 0, -1}, 
	{"FIELD", 0, -1}, 
	{"LFIELD", 0, -1}, 
	{"ERR", 0, -1}, 
	{"EOT", 0, -1}, 
	{NULL, 0, 0}
};

static void knh_loadScriptTermData(CTX ctx)
{
	kDictSet *ds = ctx->share->tokenDictSet;
	TERMDATA_t *data = TERMDATA + STT_MAX;
	int tt = STT_MAX;
	while(data->name != NULL) {
		if(!isupper(data->name[0])) {
			knh_DictSet_append(ctx, ds, new_T(data->name), tt);
		}
		tt++;
		data++;
	}
	knh_DictSet_sort(ctx, ds);
}

const char *TT__(kterm_t tt)
{
	if(tt < TT_MAX + STT_MAX) {
		return TERMDATA[tt].name;
	}
	DBG_P("tt=%d", tt);
	return "UNDEFINED";
}

kbool_t TT_is(kterm_t tt, kflag_t flag)
{
	return FLAG_is(TERMDATA[tt].flag, flag);
}

kshort_t TT_to(kterm_t tt)
{
	return TERMDATA[tt].to;
}

void knh_dumpKeyword(CTX ctx, kOutputStream *w)
{
	TERMDATA_t *data = TERMDATA + STT_MAX;
	while(data->name != NULL) {
		if(islower(data->name[0])) {
			knh_write_ascii(ctx, w, data->name);
			knh_putc(ctx, w, ' ');
		}
		data++;
	}
	knh_write_EOL(ctx, w);
}

typedef struct {
	const char *name;
	const char *alias;
} ALIASDATA_t;

static ALIASDATA_t __AliasData[] = {
	{"!", "not"}, 
	{"&&", "and"}, 
	{"===", "is"}, 
	{"FALSE", "false"}, 
	{"False", "false"}, 
	{"Integer", "Int"}, 
	{"NULL", "null"}, 
	{"TRUE", "true"}, 
	{"True", "true"}, 
	{"boolean", "Boolean"}, 
	{"char", "Int"}, 
	{"const", "@Const"}, 
	{"def", "function"}, 
	{"double", "Float"}, 
	{"final", "@Final"}, 
	{"float", "Float"}, 
	{"instanceof", "<:"}, 
	{"int", "Int"}, 
	{"long", "Int"}, 
	{"mod", "%"}, 
	{"private", "@Private"}, 
	{"public", "@Public"}, 
	{"short", "Int"}, 
	{"static", "@Static"}, 
	{"string", "String"}, 
	{"virtual", "@Virtual"}, 
	{"||", "or"}, 
	{NULL, NULL}
};

void knh_loadScriptAliasTermData(CTX ctx)
{
	ALIASDATA_t *data = __AliasData;
	kDictMap *dm = new_DictMap0(ctx, sizeof(__AliasData), 0/*isCaseMap*/, "AliasDictMap");
	KNH_INITv(ctx->wshare->sysAliasDictMap, dm);
	while(data->name != NULL) {
		knh_DictMap_append(ctx, dm, new_T(data->name), UPCAST(new_T(data->alias)));
		data++;
	}
}

typedef struct { 
	kushort_t priority;
	kmethodn_t mn;
} OPDATA_t;

static OPDATA_t OPDATA[] = {
	{2, MN_NONAME}, /* = */
	{4, MN_NONAME}, /* ?\? */
	{4, MN_NONAME}, /* ? */
	{99, MN_NONAME}, /* : */
	{99, MN_NONAME}, /* . */
	{5, MN_NONAME}, /* or */
	{6, MN_NONAME}, /* and */
	{7, MN_opNOT}, /* not */
	{8, MN_opEXISTS}, /* exists */
	{9, MN_opLINK}, /* :: */
	{9, MN_opQUERY}, /* :? */
	{9, MN_opFROM}, /* from */
	{9, MN_opUNTIL}, /* until */
	{10, MN_opIS}, /* is? */
	{10, MN_opOF}, /* <: */
	{10, MN_opHAS}, /* in? */
	{10, MN_opTO}, /* to */
	{10, MN_opEQ}, /* == */
	{10, MN_opNOTEQ}, /* != */
	{10, MN_opLT}, /* < */
	{10, MN_opLTE}, /* <= */
	{10, MN_opGT}, /* > */
	{10, MN_opGTE}, /* >= */
	{12, MN_opWITH}, /* with */
	{12, MN_opMATCH}, /* match */
	{12, MN_opAS}, /* as */
	{12, MN_opWHERE}, /* where */
	{12, MN_opEACH}, /* each */
	{14, MN_opLOR}, /* | */
	{16, MN_opLXOR}, /* ^ */
	{18, MN_opLAND}, /* & */
	{20, MN_opADD}, /* + */
	{20, MN_opSUB}, /* - */
	{25, MN_opDIV}, /* / */
	{25, MN_opMOD}, /* % */
	{25, MN_opMUL}, /* * */
	{35, MN_opLSFT}, /* << */
	{35, MN_opRSFT}, /* >> */
	{40, MN_opLNOT}, /* ~ */
	{40, MN_opNEXT}, /* ++ */
	{40, MN_opPREV}, /* -- */
	{40, MN_opITR}, /* .. */
	{40, MN_opSEQ}, /* () */
	{40, MN_opEXPT}, /* !! */
	{40, MN_opADDR}, /* &&& */
	{40, MN_opCAST}, /* *** */
	{40, MN_opPLUS}, /* +++ */
	{40, MN_opNEG}, /* --- */
};

static const char *OPNAME[] = {
	"not",
	"exists",
	"::",
	":?",
	"from",
	"until",
	"is?",
	"<:",
	"in?",
	"to",
	"==",
	"!=",
	"<",
	"<=",
	">",
	">=",
	"with",
	"match",
	"as",
	"where",
	"each",
	"|",
	"^",
	"&",
	"+",
	"-",
	"/",
	"%",
	"*",
	"<<",
	">>",
	"~",
	"++",
	"--",
	"..",
	"()",
	"!!",
	"&&&",
	"***",
	"+++",
	"---",
};

static const char *MN_opNAME[] = {
	"opNOT",
	"opEXISTS",
	"opLINK",
	"opQUERY",
	"opFROM",
	"opUNTIL",
	"opIS",
	"opOF",
	"opHAS",
	"opTO",
	"opEQ",
	"opNOTEQ",
	"opLT",
	"opLTE",
	"opGT",
	"opGTE",
	"opWITH",
	"opMATCH",
	"opAS",
	"opWHERE",
	"opEACH",
	"opLOR",
	"opLXOR",
	"opLAND",
	"opADD",
	"opSUB",
	"opDIV",
	"opMOD",
	"opMUL",
	"opLSFT",
	"opRSFT",
	"opLNOT",
	"opNEXT",
	"opPREV",
	"opITR",
	"opSEQ",
	"opEXPT",
	"opADDR",
	"opCAST",
	"opPLUS",
	"opNEG",
};

int TT_priority(kterm_t tt)
{
	if(TT_LET <= tt && tt <= TT_TSUB) {
		return OPDATA[tt-TT_LET].priority;
	}
	if(TT_ASIS <= tt && tt < TT_ERR) {
		return 99;
	}
	return 0;
}

kmethodn_t TT_toMN(kterm_t tt)
{
	if(TT_LET <= tt && tt <= TT_TSUB) {
		return OPDATA[tt - TT_LET].mn;
	}
	return MN_NONAME;
}

const char* knh_getopname(kmethodn_t mn)
{
	DBG_ASSERT(mn + TT_NOT <= TT_TSUB);
	return OPNAME[mn];
}

const char* knh_getopMethodName(kmethodn_t mn)
{
	DBG_ASSERT(mn + TT_NOT <= TT_TSUB);
	return MN_opNAME[mn];
}

#endif/*K_USING_LOADDATA*/


#ifdef __cplusplus
}
#endif

// THIS FILE WAS AUTOMATICALLY GENERATED. DON'T EDIT.

