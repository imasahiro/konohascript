
/* ------------------------------------------------------------------------ */

static knh_IntData_t StmtInt[] = {

    {"STT_DONE", STT_DONE},
    {"STT_BLOCK", STT_BLOCK},
    {"STT_PRAGMA", STT_PRAGMA},
    {"STT_NAMESPACE", STT_NAMESPACE},
    {"STT_DEFMACRO", STT_DEFMACRO},
    {"STT_INCLUDE", STT_INCLUDE},
    {"STT_ALLOW", STT_ALLOW},
    {"STT_DENY", STT_DENY},
    {"STT_USING", STT_USING},
    {"STT_CLASS", STT_CLASS},
    {"STT_FORMAT", STT_FORMAT},
    {"STT_RETURN", STT_RETURN},
    {"STT_YIELD", STT_YIELD},
    {"STT_IF", STT_IF},
    {"STT_SWITCH", STT_SWITCH},
    {"STT_CASE", STT_CASE},
    {"STT_WHILE", STT_WHILE},
    {"STT_DO", STT_DO},
    {"STT_FOR", STT_FOR},
    {"STT_FOREACH", STT_FOREACH},
    {"STT_BREAK", STT_BREAK},
    {"STT_CONTINUE", STT_CONTINUE},
    {"STT_TRY", STT_TRY},
    {"STT_CATCH", STT_CATCH},
    {"STT_THROW", STT_THROW},
    {"STT_PRINT", STT_PRINT},
    {"STT_ASSURE", STT_ASSURE},
    {"STT_ASSERT", STT_ASSERT},
    {"STT_REGISTER", STT_REGISTER},
    {"STT_FUNCTION", STT_FUNCTION},
    {"STT_METHOD", STT_METHOD},
    {"STT_TYPEMAP", STT_TYPEMAP},
    {"STT_DECL", STT_DECL},
    {"STT_CHKOUT", STT_CHKOUT},
    {"STT_LETM", STT_LETM},
    {"STT_SELECT", STT_SELECT},
    {"STT_SWAP", STT_SWAP},
    {"STT_CONST", STT_CONST},
    {"STT_ERR", STT_ERR},
    {"STT_LET", STT_LET},
    {"STT_TCAST", STT_TCAST},
    {"STT_BOX", STT_BOX},
    {"STT_OPR", STT_OPR},
    {"STT_CALL", STT_CALL},
    {"STT_NEW", STT_NEW},
    {"STT_FUNCCALL", STT_FUNCCALL},
    {"STT_ACALL", STT_ACALL},
    {"STT_THUNK", STT_THUNK},
    {"STT_TLINK", STT_TLINK},
    {"STT_ALT", STT_ALT},
    {"STT_MATCH", STT_MATCH},
    {"STT_TRI", STT_TRI},
    {"STT_AND", STT_AND},
    {"STT_OR", STT_OR},
    {"STT_W1", STT_W1},
    {"STT_SEND", STT_SEND},
    {"STT_FMTCALL", STT_FMTCALL},
    {"STT_CALL1", STT_CALL1},
    {"STT_GO", STT_GO},
};
static knh_IntData_t TokenInt[] = {

    {"TT_PRAGMA", TT_PRAGMA},
    {"TT_NAMESPACE", TT_NAMESPACE},
    {"TT_INCLUDE", TT_INCLUDE},
    {"TT_IMPORT", TT_IMPORT},
    {"TT_USING", TT_USING},
    {"TT_CLASS", TT_CLASS},
    {"TT_FORMAT", TT_FORMAT},
    {"TT_RETURN", TT_RETURN},
    {"TT_YIELD", TT_YIELD},
    {"TT_IF", TT_IF},
    {"TT_SWITCH", TT_SWITCH},
    {"TT_CASE", TT_CASE},
    {"TT_WHILE", TT_WHILE},
    {"TT_DO", TT_DO},
    {"TT_FOR", TT_FOR},
    {"TT_FOREACH", TT_FOREACH},
    {"TT_BREAK", TT_BREAK},
    {"TT_CONTINUE", TT_CONTINUE},
    {"TT_GOTO", TT_GOTO},
    {"TT_TRY", TT_TRY},
    {"TT_CATCH", TT_CATCH},
    {"TT_THROW", TT_THROW},
    {"TT_PRINT", TT_PRINT},
    {"TT_ASSURE", TT_ASSURE},
    {"TT_ASSERT", TT_ASSERT},
    {"TT_REGISTER", TT_REGISTER},
    {"TT_GO", TT_GO},
    {"TT_EXTENDS", TT_EXTENDS},
    {"TT_IMPLEMENTS", TT_IMPLEMENTS},
    {"TT_ELSE", TT_ELSE},
    {"TT_DEFAULT", TT_DEFAULT},
    {"TT_FINALLY", TT_FINALLY},
    {"TT_SEMICOLON", TT_SEMICOLON},
    {"TT_COMMA", TT_COMMA},
    {"TT_DIAMOND", TT_DIAMOND},
    {"TT_ARROW", TT_ARROW},
    {"TT_DARROW", TT_DARROW},
    {"TT_TARROW", TT_TARROW},
    {"TT_TDARROW", TT_TDARROW},
    {"TT_LSEND", TT_LSEND},
    {"TT_RSEND", TT_RSEND},
    {"TT_DOTS", TT_DOTS},
    {"TT_DMUL", TT_DMUL},
    {"TT_ASIS", TT_ASIS},
    {"TT_FUNCTION", TT_FUNCTION},
    {"TT_NEW", TT_NEW},
    {"TT_NULL", TT_NULL},
    {"TT_TYPEOF", TT_TYPEOF},
    {"TT_VOID", TT_VOID},
    {"TT_VAR", TT_VAR},
    {"TT_BYTE", TT_BYTE},
    {"TT_DYNAMIC", TT_DYNAMIC},
    {"TT_TRUE", TT_TRUE},
    {"TT_FALSE", TT_FALSE},
    {"TT_BRACE", TT_BRACE},
    {"TT_PARENTHESIS", TT_PARENTHESIS},
    {"TT_BRANCET", TT_BRANCET},
    {"TT_DECLLET", TT_DECLLET},
    {"TT_LSFTE", TT_LSFTE},
    {"TT_RSFTE", TT_RSFTE},
    {"TT_ADDE", TT_ADDE},
    {"TT_SUBE", TT_SUBE},
    {"TT_DIVE", TT_DIVE},
    {"TT_MODE", TT_MODE},
    {"TT_MULE", TT_MULE},
    {"TT_LANDE", TT_LANDE},
    {"TT_LORE", TT_LORE},
    {"TT_ALTLET", TT_ALTLET},
    {"TT_LET", TT_LET},
    {"TT_ALT", TT_ALT},
    {"TT_QTN", TT_QTN},
    {"TT_COLON", TT_COLON},
    {"TT_DOT", TT_DOT},
    {"TT_OR", TT_OR},
    {"TT_AND", TT_AND},
    {"TT_NOT", TT_NOT},
    {"TT_EXISTS", TT_EXISTS},
    {"TT_LINK", TT_LINK},
    {"TT_QUERY", TT_QUERY},
    {"TT_FROM", TT_FROM},
    {"TT_UNTIL", TT_UNTIL},
    {"TT_IS", TT_IS},
    {"TT_OF", TT_OF},
    {"TT_IN", TT_IN},
    {"TT_TO", TT_TO},
    {"TT_EQ", TT_EQ},
    {"TT_NEQ", TT_NEQ},
    {"TT_LT", TT_LT},
    {"TT_LTE", TT_LTE},
    {"TT_GT", TT_GT},
    {"TT_GTE", TT_GTE},
    {"TT_WITH", TT_WITH},
    {"TT_MATCH", TT_MATCH},
    {"TT_AS", TT_AS},
    {"TT_WHERE", TT_WHERE},
    {"TT_EACH", TT_EACH},
    {"TT_LOR", TT_LOR},
    {"TT_XOR", TT_XOR},
    {"TT_LAND", TT_LAND},
    {"TT_ADD", TT_ADD},
    {"TT_SUB", TT_SUB},
    {"TT_DIV", TT_DIV},
    {"TT_MOD", TT_MOD},
    {"TT_MUL", TT_MUL},
    {"TT_LSFT", TT_LSFT},
    {"TT_RSFT", TT_RSFT},
    {"TT_LNOT", TT_LNOT},
    {"TT_NEXT", TT_NEXT},
    {"TT_PREV", TT_PREV},
    {"TT_ITR", TT_ITR},
    {"TT_SEQ", TT_SEQ},
    {"TT_EXPT", TT_EXPT},
    {"TT_TAND", TT_TAND},
    {"TT_TMUL", TT_TMUL},
    {"TT_TADD", TT_TADD},
    {"TT_TSUB", TT_TSUB},
    {"TT_CODE", TT_CODE},
    {"TT_DOCU", TT_DOCU},
    {"TT_NUM", TT_NUM},
    {"TT_STR", TT_STR},
    {"TT_TSTR", TT_TSTR},
    {"TT_ESTR", TT_ESTR},
    {"TT_REGEX", TT_REGEX},
    {"TT_DOC", TT_DOC},
    {"TT_METAN", TT_METAN},
    {"TT_PROPN", TT_PROPN},
    {"TT_URN", TT_URN},
    {"TT_TLINK", TT_TLINK},
    {"TT_NAME", TT_NAME},
    {"TT_UNAME", TT_UNAME},
    {"TT_FUNCNAME", TT_FUNCNAME},
    {"TT_UFUNCNAME", TT_UFUNCNAME},
    {"TT_PTYPE", TT_PTYPE},
    {"TT_CID", TT_CID},
    {"TT_MN", TT_MN},
    {"TT_FMT", TT_FMT},
    {"TT_CONST", TT_CONST},
    {"TT_SYSVAL", TT_SYSVAL},
    {"TT_FVAR", TT_FVAR},
    {"TT_LVAR", TT_LVAR},
    {"TT_FIELD", TT_FIELD},
    {"TT_LFIELD", TT_LFIELD},
    {"TT_ERR", TT_ERR},
    {"TT_EOT", TT_EOT},
};
