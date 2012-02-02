// THIS FILE WAS AUTOMATICALLY GENERATED

#ifdef __cplusplus
extern "C" {
#endif



#ifdef K_INTERNAL
KNHAPI2(kbool_t) knh_eval(CTX ctx, const char *script, kline_t uline, kOutputStream *w);
KNHAPI2(kArray*) new_Array(CTX ctx, kclass_t p1, size_t capacity);
KNHAPI2(void) knh_Array_add_(CTX ctx, kArray *a, kObject *value);
KNHAPI2(void) knh_Array_remove_(CTX ctx, kArray *a, size_t n);
KNHAPI2(void) knh_Array_swap(CTX ctx, kArray *a, size_t n, size_t m);
KNHAPI2(kIterator*) new_IteratorG(CTX ctx, kclass_t cid, kObject *source, knh_Fitrnext fnext);
KNHAPI2(void) knh_Bytes_clear(kBytes *ba, size_t pos);
KNHAPI2(void) knh_Bytes_write2(CTX ctx, kBytes *ba, const char *text, size_t len);
KNHAPI2(kascii_t*) CWB_totext(CTX ctx, CWB_t *cwb);
KNHAPI2(kString*) CWB_newString(CTX ctx, CWB_t *cwb, int pol);
KNHAPI2(void) kObjectoNULL_(CTX ctx, Object *o);
KNHAPI2(kRawPtr*) new_RawPtr(CTX ctx, const knh_ClassTBL_t *ct, void *rawptr);
KNHAPI2(kObject*) new_ReturnObject(CTX ctx, ksfp_t *sfp);
KNHAPI2(kRawPtr*) new_ReturnCppObject(CTX ctx, ksfp_t *sfp, void *rawptr, knh_Frawfree pfree);
KNHAPI2(void) knh_addConstPool(CTX ctx, kObject *o);
KNHAPI2(void) knh_write_cid(CTX ctx, kOutputStream *w, kclass_t cid);
KNHAPI2(void) knh_write_type(CTX ctx, kOutputStream *w, ktype_t type);
KNHAPI2(Object*) knh_getClassDefaultValue(CTX ctx, kclass_t cid);
KNHAPI2(kclass_t) ktype_tocid(CTX ctx, ktype_t ptype, kclass_t this_cid);
KNHAPI2(kparam_t*) knh_Param_get(kParam *pa, size_t n);
KNHAPI2(ktype_t) knh_Method_rtype(CTX ctx, kMethod *mtd, kclass_t this_cid);
KNHAPI2(size_t) knh_Method_psize(kMethod *mtd);
KNHAPI2(ktype_t) knh_Method_ptype(CTX ctx, kMethod *mtd, size_t n, kclass_t this_cid);
KNHAPI2(ktype_t) knh_Param_rtype(kParam *pa);
KNHAPI2(void) knh_write_mn(CTX ctx, kOutputStream *w, kmethodn_t mn);
KNHAPI2(kbool_t) Method_isAbstract(kMethod *mtd);
KNHAPI2(void) knh_Func_invoke(CTX ctx, kFunc *fo, ksfp_t *rtnsfp, int argc);
KNHAPI2(void) knh_addTypeMap(CTX ctx, kTypeMap *tmr, int initCache);
KNHAPI2(void) knh_TypeMap_exec(CTX ctx, kTypeMap *tmr, ksfp_t *sfp _RIX);
KNHAPI2(kTypeMap*) new_TypeMap(CTX ctx, kflag_t flag, kclass_t scid, kclass_t tcid, knh_Ftypemap func);
KNHAPI2(kTypeMap*) new_TypeMapData(CTX ctx, kflag_t flag, kclass_t scid, kclass_t tcid, knh_Ftypemap func, Object *mapdata);
KNHAPI2(kTypeMap*) knh_findTypeMapNULL(CTX ctx, kclass_t scid0, kclass_t tcid0);
KNHAPI2(kcontext_t*) knh_getCurrentContext(void);
KNHAPI2(int) knh_isVerbose(void);
KNHAPI2(void) knh_nthrow(CTX ctx, ksfp_t *sfp, const char *fault, knh_ldata_t *ldata);
KNHAPI2(void) THROW_OutOfRange(CTX ctx, ksfp_t *sfp, kint_t n, size_t max);
KNHAPI2(kString*) knh_DictMap_keyAt(kDictMap *m, size_t n);
KNHAPI2(Object*) knh_DictMap_valueAt(kDictMap *m, size_t n);
KNHAPI2(kMap*) new_DataMap(CTX ctx);
KNHAPI2(void) knh_DataMap_set(CTX ctx, kMap *m, kString *key, kObject *value);
KNHAPI2(void) knh_DataMap_setString(CTX ctx, kMap *m, const char *key, const char *value);
KNHAPI2(void) knh_DataMap_setInt(CTX ctx, kMap *m, const char *key, kint_t value);
KNHAPI2(void) knh_DataMap_setFloat(CTX ctx, kMap *m, const char *key, kfloat_t value);
KNHAPI2(void) knh_DataMap_setBlob(CTX ctx, kMap *m, const char *key, const char *value, size_t size);
KNHAPI2(kInt*) new_Int(CTX ctx, kint_t value);
KNHAPI2(kFloat*) new_Float(CTX ctx, kfloat_t value);
KNHAPI2(void) knh_boxing(CTX ctx, ksfp_t *sfp, int type);
KNHAPI2(kPath*) new_Path(CTX ctx, kString *path);
KNHAPI2(kInputStream*) new_InputStream(CTX ctx, kio_t *io2, kPath *path);
KNHAPI2(kOutputStream*) new_OutputStream(CTX ctx,  kio_t *io2, kPath *path);
KNHAPI2(kOutputStream*) new_BytesOutputStream(CTX ctx, kBytes *ba);
KNHAPI2(void) knh_OutputStream_flush(CTX ctx, kOutputStream *w);
KNHAPI2(void) knh_OutputStream_putc(CTX ctx, kOutputStream *w, int ch);
KNHAPI2(void) knh_OutputStream_write(CTX ctx, kOutputStream *w, kbytes_t buf);
KNHAPI2(void) knh_OutputStream_p(CTX ctx, kOutputStream *w, kbytes_t buf);
KNHAPI2(void) knh_write_EOL(CTX ctx, kOutputStream *w);
KNHAPI2(void) knh_write_TAB(CTX ctx, kOutputStream *w);
KNHAPI2(void) knh_write_ascii(CTX ctx, kOutputStream *w, const char *text);
KNHAPI2(void) knh_write_utf8(CTX ctx, kOutputStream *w, kbytes_t t, int hasUTF8);
KNHAPI2(void) knh_printf(CTX ctx, kOutputStream *w, const char *fmt, ...);
KNHAPI2(kString*) new_String(CTX ctx, const char *str);
KNHAPI2(void) knh_setPropertyText(CTX ctx, char *key, char *value);
KNHAPI2(kString*) knh_getFieldName(CTX ctx, ksymbol_t fn);
#endif

typedef struct kpackageapi_t {
	size_t crc32;
	Object*  (*DictMap_valueAt)(kDictMap *m, size_t n);
	Object*  (*getClassDefaultValue)(CTX ctx, kclass_t cid);
	int  (*isVerbose)(void);
	kArray* (*new_Array)(CTX ctx, kclass_t p1, size_t capacity);
	kFloat* (*new_Float)(CTX ctx, kfloat_t value);
	kInputStream* (*new_InputStream)(CTX ctx, kio_t *io2, kPath *path);
	kInt* (*new_Int)(CTX ctx, kint_t value);
	kIterator* (*new_IteratorG)(CTX ctx, kclass_t cid, kObject *source, knh_Fitrnext fnext);
	kMap* (*new_DataMap)(CTX ctx);
	kObject* (*new_ReturnObject)(CTX ctx, ksfp_t *sfp);
	kOutputStream* (*new_BytesOutputStream)(CTX ctx, kBytes *ba);
	kOutputStream* (*new_OutputStream)(CTX ctx,  kio_t *io2, kPath *path);
	kPath* (*new_Path)(CTX ctx, kString *path);
	kRawPtr* (*new_RawPtr)(CTX ctx, const knh_ClassTBL_t *ct, void *rawptr);
	kRawPtr* (*new_ReturnCppObject)(CTX ctx, ksfp_t *sfp, void *rawptr, knh_Frawfree pfree);
	kString* (*CWB_newString)(CTX ctx, CWB_t *cwb, int pol);
	kString*  (*DictMap_keyAt)(kDictMap *m, size_t n);
	kString*  (*getFieldName)(CTX ctx, ksymbol_t fn);
	kString* (*new_String)(CTX ctx, const char *str);
	kTypeMap*  (*findTypeMapNULL)(CTX ctx, kclass_t scid0, kclass_t tcid0);
	kTypeMap* (*new_TypeMap)(CTX ctx, kflag_t flag, kclass_t scid, kclass_t tcid, knh_Ftypemap func);
	kTypeMap* (*new_TypeMapData)(CTX ctx, kflag_t flag, kclass_t scid, kclass_t tcid, knh_Ftypemap func, Object *mapdata);
	kascii_t* (*CWB_totext)(CTX ctx, CWB_t *cwb);
	kbool_t (*Method_isAbstract)(kMethod *mtd);
	kbool_t  (*eval)(CTX ctx, const char *script, kline_t uline, kOutputStream *w);
	kclass_t (*ktype_tocid)(CTX ctx, ktype_t ptype, kclass_t this_cid);
	kcontext_t*  (*getCurrentContext)(void);
	kparam_t*  (*Param_get)(kParam *pa, size_t n);
	ktype_t  (*Method_ptype)(CTX ctx, kMethod *mtd, size_t n, kclass_t this_cid);
	ktype_t  (*Method_rtype)(CTX ctx, kMethod *mtd, kclass_t this_cid);
	ktype_t  (*Param_rtype)(kParam *pa);
	size_t  (*Method_psize)(kMethod *mtd);
	void (*THROW_OutOfRange)(CTX ctx, ksfp_t *sfp, kint_t n, size_t max);
	void (*kObjectoNULL_)(CTX ctx, Object *o);
	void  (*Array_add_)(CTX ctx, kArray *a, kObject *value);
	void  (*Array_remove_)(CTX ctx, kArray *a, size_t n);
	void  (*Array_swap)(CTX ctx, kArray *a, size_t n, size_t m);
	void  (*Bytes_clear)(kBytes *ba, size_t pos);
	void  (*Bytes_write2)(CTX ctx, kBytes *ba, const char *text, size_t len);
	void  (*DataMap_set)(CTX ctx, kMap *m, kString *key, kObject *value);
	void  (*DataMap_setBlob)(CTX ctx, kMap *m, const char *key, const char *value, size_t size);
	void  (*DataMap_setFloat)(CTX ctx, kMap *m, const char *key, kfloat_t value);
	void  (*DataMap_setInt)(CTX ctx, kMap *m, const char *key, kint_t value);
	void  (*DataMap_setString)(CTX ctx, kMap *m, const char *key, const char *value);
	void  (*Func_invoke)(CTX ctx, kFunc *fo, ksfp_t *rtnsfp, int argc);
	void  (*OutputStream_flush)(CTX ctx, kOutputStream *w);
	void  (*OutputStream_p)(CTX ctx, kOutputStream *w, kbytes_t buf);
	void  (*OutputStream_putc)(CTX ctx, kOutputStream *w, int ch);
	void  (*OutputStream_write)(CTX ctx, kOutputStream *w, kbytes_t buf);
	void  (*TypeMap_exec)(CTX ctx, kTypeMap *tmr, ksfp_t *sfp _RIX);
	void  (*addConstPool)(CTX ctx, kObject *o);
	void  (*addTypeMap)(CTX ctx, kTypeMap *tmr, int initCache);
	void  (*boxing)(CTX ctx, ksfp_t *sfp, int type);
	void  (*nthrow)(CTX ctx, ksfp_t *sfp, const char *fault, knh_ldata_t *ldata);
	void  (*printf)(CTX ctx, kOutputStream *w, const char *fmt, ...);
	void  (*setPropertyText)(CTX ctx, char *key, char *value);
	void  (*write_EOL)(CTX ctx, kOutputStream *w);
	void  (*write_TAB)(CTX ctx, kOutputStream *w);
	void  (*write_ascii)(CTX ctx, kOutputStream *w, const char *text);
	void  (*write_cid)(CTX ctx, kOutputStream *w, kclass_t cid);
	void  (*write_mn)(CTX ctx, kOutputStream *w, kmethodn_t mn);
	void  (*write_type)(CTX ctx, kOutputStream *w, ktype_t type);
	void  (*write_utf8)(CTX ctx, kOutputStream *w, kbytes_t t, int hasUTF8);
} kpackageapi_t;
	
#define K_API2_CRC32 ((size_t)1134416443)
#ifdef K_DEFINE_API2
static const kpackageapi_t* getapi2(void) {
	static const kpackageapi_t DATA_API2 = {
		K_API2_CRC32,
		knh_DictMap_valueAt,
		knh_getClassDefaultValue,
		knh_isVerbose,
		new_Array,
		new_Float,
		new_InputStream,
		new_Int,
		new_IteratorG,
		new_DataMap,
		new_ReturnObject,
		new_BytesOutputStream,
		new_OutputStream,
		new_Path,
		new_RawPtr,
		new_ReturnCppObject,
		CWB_newString,
		knh_DictMap_keyAt,
		knh_getFieldName,
		new_String,
		knh_findTypeMapNULL,
		new_TypeMap,
		new_TypeMapData,
		CWB_totext,
		Method_isAbstract,
		knh_eval,
		ktype_tocid,
		knh_getCurrentContext,
		knh_Param_get,
		knh_Method_ptype,
		knh_Method_rtype,
		knh_Param_rtype,
		knh_Method_psize,
		THROW_OutOfRange,
		kObjectoNULL_,
		knh_Array_add_,
		knh_Array_remove_,
		knh_Array_swap,
		knh_Bytes_clear,
		knh_Bytes_write2,
		knh_DataMap_set,
		knh_DataMap_setBlob,
		knh_DataMap_setFloat,
		knh_DataMap_setInt,
		knh_DataMap_setString,
		knh_Func_invoke,
		knh_OutputStream_flush,
		knh_OutputStream_p,
		knh_OutputStream_putc,
		knh_OutputStream_write,
		knh_TypeMap_exec,
		knh_addConstPool,
		knh_addTypeMap,
		knh_boxing,
		knh_nthrow,
		knh_printf,
		knh_setPropertyText,
		knh_write_EOL,
		knh_write_TAB,
		knh_write_ascii,
		knh_write_cid,
		knh_write_mn,
		knh_write_type,
		knh_write_utf8,
	};
	return &DATA_API2;
};
#endif/*K_DEFINE_API2*/

#ifndef K_INTERNAL
#define knh_DictMap_valueAt   ctx->api2->DictMap_valueAt
#define knh_getClassDefaultValue   ctx->api2->getClassDefaultValue
#define knh_isVerbose   ctx->api2->isVerbose
#define new_Array   ctx->api2->new_Array
#define new_Float   ctx->api2->new_Float
#define new_InputStream   ctx->api2->new_InputStream
#define new_Int   ctx->api2->new_Int
#define new_IteratorG   ctx->api2->new_IteratorG
#define new_DataMap   ctx->api2->new_DataMap
#define new_ReturnObject   ctx->api2->new_ReturnObject
#define new_BytesOutputStream   ctx->api2->new_BytesOutputStream
#define new_OutputStream   ctx->api2->new_OutputStream
#define new_Path   ctx->api2->new_Path
#define new_RawPtr   ctx->api2->new_RawPtr
#define new_ReturnCppObject   ctx->api2->new_ReturnCppObject
#define CWB_newString   ctx->api2->CWB_newString
#define knh_DictMap_keyAt   ctx->api2->DictMap_keyAt
#define knh_getFieldName   ctx->api2->getFieldName
#define new_String   ctx->api2->new_String
#define knh_findTypeMapNULL   ctx->api2->findTypeMapNULL
#define new_TypeMap   ctx->api2->new_TypeMap
#define new_TypeMapData   ctx->api2->new_TypeMapData
#define CWB_totext   ctx->api2->CWB_totext
#define Method_isAbstract   ctx->api2->Method_isAbstract
#define knh_eval   ctx->api2->eval
#define ktype_tocid   ctx->api2->ktype_tocid
#define knh_getCurrentContext   ctx->api2->getCurrentContext
#define knh_Param_get   ctx->api2->Param_get
#define knh_Method_ptype   ctx->api2->Method_ptype
#define knh_Method_rtype   ctx->api2->Method_rtype
#define knh_Param_rtype   ctx->api2->Param_rtype
#define knh_Method_psize   ctx->api2->Method_psize
#define THROW_OutOfRange   ctx->api2->THROW_OutOfRange
#define kObjectoNULL_   ctx->api2->kObjectoNULL_
#define knh_Array_add_   ctx->api2->Array_add_
#define knh_Array_remove_   ctx->api2->Array_remove_
#define knh_Array_swap   ctx->api2->Array_swap
#define knh_Bytes_clear   ctx->api2->Bytes_clear
#define knh_Bytes_write2   ctx->api2->Bytes_write2
#define knh_DataMap_set   ctx->api2->DataMap_set
#define knh_DataMap_setBlob   ctx->api2->DataMap_setBlob
#define knh_DataMap_setFloat   ctx->api2->DataMap_setFloat
#define knh_DataMap_setInt   ctx->api2->DataMap_setInt
#define knh_DataMap_setString   ctx->api2->DataMap_setString
#define knh_Func_invoke   ctx->api2->Func_invoke
#define knh_OutputStream_flush   ctx->api2->OutputStream_flush
#define knh_OutputStream_p   ctx->api2->OutputStream_p
#define knh_OutputStream_putc   ctx->api2->OutputStream_putc
#define knh_OutputStream_write   ctx->api2->OutputStream_write
#define knh_TypeMap_exec   ctx->api2->TypeMap_exec
#define knh_addConstPool   ctx->api2->addConstPool
#define knh_addTypeMap   ctx->api2->addTypeMap
#define knh_boxing   ctx->api2->boxing
#define knh_nthrow   ctx->api2->nthrow
#define knh_printf   ctx->api2->printf
#define knh_setPropertyText   ctx->api2->setPropertyText
#define knh_write_EOL   ctx->api2->write_EOL
#define knh_write_TAB   ctx->api2->write_TAB
#define knh_write_ascii   ctx->api2->write_ascii
#define knh_write_cid   ctx->api2->write_cid
#define knh_write_mn   ctx->api2->write_mn
#define knh_write_type   ctx->api2->write_type
#define knh_write_utf8   ctx->api2->write_utf8
#endif


/* ------------------------------------------------------------------------ */
/* DEVELOPERS API */
kBasicBlock* new_BasicBlockLABEL(CTX ctx);
void knh_BasicBlock_add_(CTX ctx, kBasicBlock *bb, kushort_t line, kopl_t *op, size_t size);
KMETHOD knh_Fmethod_runVM(CTX ctx, ksfp_t *sfp _RIX);
void knh_PROP(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct);
void knh_NPROP(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct);
void knh_PRINT(CTX ctx, ksfp_t *sfp, kflag_t flag, kline_t uline, kString *msg, kObject *o);
void knh_PRINTi(CTX ctx, ksfp_t *sfp, kflag_t flag, kline_t uline, kString *msg, kint_t n);
void knh_PRINTf(CTX ctx, ksfp_t *sfp, kflag_t flag, kline_t uline, kString *msg, kfloat_t f);
void knh_PRINTb(CTX ctx, ksfp_t *sfp, kflag_t flag, kline_t uline, kString *msg, kbool_t b);
void GammaBuilder_shiftLocalScope(CTX ctx);
void knh_Method_asm(CTX ctx, kMethod *mtd, kStmtExpr *stmtB, knh_Ftyping typing);
KMETHOD knh_Fmethod_asm(CTX ctx, ksfp_t *sfp _RIX);
void knh_loadScriptSystemKonohaCode(CTX ctx);
void knh_write_vmfunc(CTX ctx, kOutputStream *w, void *f);
knh_Fmethod knh_gluefunc(CTX ctx, kMethod *mtd, kNameSpace *ns, kDictMap *mdata);
kbool_t knh_Method_ffi(CTX ctx, kMethod *mtd, kNameSpace *ns, kDictMap *mdata);
void knh_loadFFIDriver(CTX ctx, kNameSpace *ns);
void *knh_copyCallbackFunc(CTX ctx, void *tmpl, void *dest, kFunc *fo);
const char* TERM_BBOLD(CTX ctx);
const char* TERM_EBOLD(CTX ctx);
const char* TERM_BNOTE(CTX ctx, int pe);
const char* TERM_ENOTE(CTX ctx, int pe);
kTerm* ERROR_NotFound(CTX ctx, const char *whatis, const char *t);
void WARN_NotFound(CTX ctx, const char *whatis, const char *t);
kTerm* ERROR_Incompatible(CTX ctx, const char *whatis, const char *name);
kTerm* ERROR_SingleParam(CTX ctx);
void WARN_MuchBetter(CTX ctx, const char *token, const char *token2);
void WarningMethodName(CTX ctx, const char *name);
void WARN_MustCloseWith(CTX ctx, int ch);
void WARN_Semicolon(CTX ctx);
void WARN_UnxpectedMultiByteChar(CTX ctx, const char *ch);
kTerm *ErrorHazardousStatement(CTX ctx);
void WarningNoEffect(CTX ctx);
kTerm* ErrorMisplaced(CTX ctx);
kTerm* ERROR_UnableToAdd(CTX ctx, kclass_t cid, const char *whatis);
kTerm* ERROR_Block(CTX ctx, const char* block);
kTerm* ERROR_WrongFFILink(CTX ctx, const char* link);
kTerm* ERROR_text(CTX ctx, const char *keyword K_TRACEARGV);
kTerm* ERROR_Term(CTX ctx, kTerm *tk K_TRACEARGV);
kTerm* ERROR_Stmt(CTX ctx, kStmtExpr *stmt K_TRACEARGV);
kTerm* ERROR_TermIsNot(CTX ctx, kTerm *tk, const char* whatis);
kTerm* ERROR_TermIs(CTX ctx, kTerm *tk, const char* whatis);
kTerm* ERROR_Required(CTX ctx, kTerm *tk, const char *stmtexpr, const char *token);
void WarningNotInitialized(CTX ctx, kTerm *tk, const char *tool);
kTerm* ERROR_RegexCompilation(CTX ctx, kTerm *tk, const char *regname, const char *regdata);
kTerm* ERROR_Undefined(CTX ctx, const char *whatis, kclass_t cid, kTerm *tk);
kTerm* ERROR_UndefinedName(CTX ctx, kTerm *tk);
void WARN_Undefined(CTX ctx, const char *whatis, kclass_t cid, kTerm *tk);
kTerm* ERROR_AlreadyDefined(CTX ctx, const char *whatis, Object *o);
void WARN_AlreadyDefined(CTX ctx, const char *whatis, Object *o);
void WARN_AlreadyDefinedClass(CTX ctx, kclass_t cid, kclass_t oldcid);
kTerm* ERROR_Denied(CTX ctx, const char *why, kTerm *tk);
void WarningUnknownClass(CTX ctx, kTerm *tk, kclass_t defc);
kTerm* ERROR_UnableToAssign(CTX ctx, kTerm *tk);
kTerm* ErrorUnsupportedConstructor(CTX ctx, kclass_t mtd_cid);
kTerm* ERROR_UndefinedBehavior(CTX ctx, const char *token);
kTerm* ERROR_CompilerControlledParameter(CTX ctx, kclass_t mtd_cid, kmethodn_t mn, int n);
kTerm* ERROR_RequiredParameter(CTX ctx);
void WARN_WrongTypeParam(CTX ctx, kclass_t cid);
void INFO_Typing(CTX ctx, const char *prefix, kbytes_t name, ktype_t type);
void WARN_Overflow(CTX ctx, const char *floatorint, kbytes_t t);
void WARN_Unused(CTX ctx, kTerm *tk, ksymbol_t fn);
kTerm* ERROR_AlreadyDefinedType(CTX ctx, ksymbol_t fn, ktype_t type);
kTerm* ErrorTooManyVariables(CTX ctx);
void WARN_UseDefaultValue(CTX ctx, const char *whatis, ktype_t type);
void WarningNoFmt(CTX ctx, const char *fmt);
void WarningIllegalFormatting(CTX ctx, const char *fmt);
kTerm* ERROR_MethodIsNot(CTX ctx, kMethod *mtd, const char *how);
void WARN_MethodIs(CTX ctx, kMethod *mtd, const char *how);
kTerm *ERROR_Unsupported(CTX ctx, const char *whatis, kclass_t cid, const char *symbol);
void WARN_Unsupported(CTX ctx, const char *msg);
void WARN_Ignored(CTX ctx, const char *whatis, kclass_t cid, const char *symbol);
void WARN_Unnecesary(CTX ctx, kTerm *tk);
void WarningUnnecessaryOperation(CTX ctx, const char *msg);
void WARN_TooMany(CTX ctx, const char *whatis, const char *symbol);
kTerm* ERROR_Needs(CTX ctx, const char *whatis);
kTerm* ERROR_MustBe(CTX ctx, const char *whatis, const char* token);
kTerm* ERROR_OutOfIndex(CTX ctx, kint_t s, kint_t n, kint_t e);
void WarningNullable(CTX ctx, kclass_t cid);
kTerm* ErrorComparedDiffrentType(CTX ctx, ktype_t t1, ktype_t t2);
kTerm *TERROR_Term(CTX ctx, kTerm *tk, kclass_t type, kclass_t reqt);
kTerm *TypeErrorStmtNN(CTX ctx, kStmtExpr *stmt, int n, ktype_t reqt, ktype_t type);
kTerm* TypeErrorCallParam(CTX ctx, int n, kMethod *mtd, kclass_t reqt, kclass_t type);
void WARN_Cast(CTX ctx, const char *whatis, kclass_t tcid, kclass_t scid);
kTerm* ERROR_ForeachNotIterative(CTX ctx, kclass_t p1, kclass_t type);
void WarningDuplicatedDefault(CTX ctx);
void WarningNotConstant(CTX ctx);
void WarningAlwaysFalseAssertion(CTX ctx);
void WarningDifferentMethodClass(CTX ctx, kbytes_t name, kclass_t cid);
void WarningDeprecated(CTX ctx, const char *msg);
kTerm* ErrorFinalMethod(CTX ctx, kclass_t cid, kmethodn_t mn);
kTerm* ErrorDifferentlyDefinedMethod(CTX ctx, kclass_t mtd_cid, kmethodn_t mn);
kTerm* ERROR_OnlyTopLevel(CTX ctx, const char* stmt);
kTerm* ErrorUndefinedLabel(CTX ctx, kTerm *tk);
void WarningAbstractMethod(CTX ctx, kMethod *mtd);
void WARN_DividedByZero(CTX ctx);
void WarningUndefinedFmt(CTX ctx, kclass_t cid, kmethodn_t mn);
void NoticeInliningMethod(CTX ctx, kMethod *mtd);
kNameSpace* new_NameSpace(CTX ctx, kNameSpace *parent);
kclass_t knh_NameSpace_getcid(CTX ctx, kNameSpace *ns, kbytes_t sname);
kbool_t knh_NameSpace_isInsideScope(CTX ctx, kNameSpace *ns, kclass_t cid);
kflag_t knh_Stmt_flag_(CTX ctx, kStmtExpr *stmt, kbytes_t name, kflag_t flag);
kclass_t knh_NameSpace_getFuncClass(CTX ctx, kNameSpace *ns, kmethodn_t mn);
ktype_t knh_NameSpace_gettype(CTX ctx, kNameSpace *ns, kbytes_t name);
ktype_t kNameSpaceagcid(CTX ctx, kNameSpace *o, kclass_t cid, kbytes_t tag);
kbool_t knh_NameSpace_include(CTX ctx, kNameSpace *ns, kPath *pth);
void knh_Script_setNSName(CTX ctx, kScript* scr, kString *nsname);
kstatus_t knh_loadPackage(CTX ctx, kbytes_t pkgname);
Object *knh_NameSpace_getConstNULL(CTX ctx, kNameSpace *ns, kbytes_t name);
kbool_t knh_beval2(CTX ctx, const char *script, kline_t uline);
kbool_t knh_beval(CTX ctx, kInputStream *in, kline_t uline);
kstatus_t knh_InputStream_load(CTX ctx, kInputStream *in, kline_t uline);
kstatus_t knh_InputStream_load(CTX ctx, kInputStream *in, kline_t uline);
kstatus_t knh_load(CTX ctx, kPath *pth);
kstatus_t knh_startScript(CTX ctx, const char *path);
kTerm* new_Term(CTX ctx, kterm_t tt);
kStmtExpr* new_Stmt2(CTX ctx, kterm_t stt, ...);
void knh_Stmt_swap(CTX ctx, kStmtExpr *stmt, size_t n, size_t m);
void kStmtExprrimToSize(CTX ctx, kStmtExpr *stmt, size_t n);
kTerm *knh_Stmt_done(CTX ctx, kStmtExpr *stmt);
void kStmtExproERR(CTX ctx, kStmtExpr *stmt, kTerm *tkERR);
kTerm *knh_Stmt_add_(CTX ctx, kStmtExpr *stmt, ...);
kTerm *new_TermMN(CTX ctx, kmethodn_t mn);
void knh_Regex_setGlobalOption(CTX ctx, kRegex *re, const char *opt);
kStmtExpr *knh_parseStmt(CTX ctx, const char *script, kline_t uline);
kStmtExpr *knh_InputStream_parseStmt(CTX ctx, kInputStream *in, kline_t *ul);
kStmtExpr *knh_Term_parseStmt(CTX ctx, kline_t uline, kTerm *tk);
kStmtExpr *knh_bytes_parseStmt(CTX ctx, kbytes_t expr, kline_t uline);
kTerm* Tn_typing(CTX ctx, kStmtExpr *stmt, size_t n, ktype_t reqt, kflag_t opflag);
kTerm* kTermoCID(CTX ctx, kTerm *tk, kclass_t cid);
kTerm* kTermoTYPED(CTX ctx, kTerm *tk, kterm_t tt, ktype_t type, kshort_t nn);
kTerm* new_TermTYPED(CTX ctx, kterm_t tt, ktype_t type, kshort_t nn);
kbool_t StmtMETA_is_(CTX ctx, kStmtExpr *stmt, kbytes_t name);
ksymbol_t Term_fnq(CTX ctx, kTerm *tk);
kclass_t knh_Term_cid(CTX ctx, kTerm *tk, ktype_t reqt);
void knh_GammaBuilder_init(CTX ctx);
kbool_t typingFunction(CTX ctx, kMethod *mtd, kStmtExpr *stmtB);
void SCRIPT_typing(CTX ctx, kStmtExpr *stmt);
kbool_t typingMethod2(CTX ctx, kMethod *mtd, kStmtExpr *stmtB);
void SCRIPT_asm(CTX ctx, kStmtExpr *stmt);
void knh_opcode_check(void);
const char *OPCODE__(kopcode_t opcode);
size_t knh_opcode_size(kopcode_t opcode);
kbool_t knh_opcode_hasjump(kopcode_t opcode);
kbool_t knh_opcode_usedef(kopcode_t opcode, int i);
kObject** knh_opline_reftrace(CTX ctx, kopl_t *c FTRARG);
void knh_opcode_dump(CTX ctx, kopl_t *c, kOutputStream *w, kopl_t *pc_start);
void knh_opcode_shift(kopl_t *c, int shift);
kopl_t* knh_VirtualMachine_run(CTX ctx, ksfp_t *sfp0, kopl_t *pc);
kArray* new_ArrayG(CTX ctx, kclass_t cid, size_t capacity);
void knh_Array_grow(CTX ctx, kArray *a, size_t newsize, size_t reqsize);
void knh_Array_clear(CTX ctx, kArray *a, size_t n);
kArray* new_Array0(CTX ctx, size_t capacity);
void knh_Array_initAPI(CTX ctx, kArray *a);
void knh_Iterator_close(CTX ctx, kIterator *it);
size_t k_goodsize(size_t ss);
size_t k_goodsize2(size_t ss, size_t wsize);
const kdim_t *new_dim(CTX ctx, size_t capacity, size_t wsize);
void knh_dimfree(CTX ctx, void *p, const kdim_t *dim);
void knh_Bytes_expands(CTX ctx, kBytes *ba, size_t newsize);
void knh_Bytes_dispose(CTX ctx, kBytes *ba);
kBytes* new_Bytes(CTX ctx, const char *name, size_t capacity);
void knh_Bytes_ensureSize(CTX ctx, kBytes *ba, size_t len);
const char *knh_Bytes_ensureZero(CTX ctx, kBytes *ba);
void knh_Bytes_putc(CTX ctx, kBytes *ba, int ch);
void knh_Bytes_reduce(kBytes *ba, size_t size);
void knh_Bytes_write(CTX ctx, kBytes *ba, kbytes_t t);
kbytes_t CWB_ensure(CTX ctx, CWB_t *cwb, kbytes_t t, size_t reqsize);
int knh_Object_compareTo(Object *o1, Object *o2);
kbool_t knh_invokeMethod0(CTX ctx, Object *o, kNameSpace *ns, unsigned long mnd, void **retval, ...);
kRawPtr *new_Pointer(CTX ctx, const char *name, void *rawptr, knh_Frawfree pfree);
const char *SAFESTRUCT__(CTX ctx, kclass_t bcid);
const char *SAFETYPE__(CTX ctx, ktype_t type);
const char *SAFECLASS__(CTX ctx, kclass_t cid);
const knh_ClassTBL_t* DBG_ClassTBL(CTX ctx, kclass_t cid);
kClass *new_Type(CTX ctx, ktype_t type);
void knh_write_cname(CTX ctx, kOutputStream *w, kclass_t cid);
void knh_setClassName(CTX ctx, kclass_t cid, kString *lname, kString *snameNULL);
kclass_t knh_getcid(CTX ctx, kbytes_t lname);
void knh_setClassDefaultValue_(CTX ctx, kclass_t cid, Object *value, knh_Fdefnull f);
void knh_setClassDef(CTX ctx, knh_ClassTBL_t *ct, const kclassdef_t *cdef);
kbool_t ClassTBL_isa_(CTX ctx, const knh_ClassTBL_t *ct, const knh_ClassTBL_t *ct2);
int knh_class_isGenerics(CTX ctx, kclass_t cid);
kbytes_t knh_class_bname(CTX ctx, kclass_t bcid);
void knh_setClassParam(CTX ctx, knh_ClassTBL_t *t, kParam *pa);
kclass_t knh_addGenericsClass(CTX ctx, kclass_t cid, kclass_t bcid, kParam *pa);
kclass_t knh_class_Generics(CTX ctx, kclass_t bcid, kParam *pa);
kclass_t knh_class_P1(CTX ctx, kclass_t bcid, ktype_t p1);
kclass_t knh_class_P2(CTX ctx, kclass_t bcid, ktype_t p1, ktype_t p2);
kbool_t knh_Param_hasTypeVar(kParam *pa);
void kParamocid(CTX ctx, kParam *pa, kclass_t this_cid, kParam *npa);
kParam *new_ParamR0(CTX ctx, ktype_t t);
kParam *new_ParamP1(CTX ctx, ktype_t rtype, ktype_t p1, ksymbol_t fn1);
void knh_Param_add(CTX ctx, kParam *pa, kparam_t p);
void knh_Param_addParam(CTX ctx, kParam *pa, ktype_t type, ksymbol_t fn);
void knh_Param_addReturnType(CTX ctx, kParam *pa, ktype_t type);
kbool_t knh_Param_equalsType(kParam *pa, kParam *pa2);
void knh_Method_setFunc(CTX ctx, kMethod *mtd, knh_Fmethod func);
void kMethodoAbstract(CTX ctx, kMethod *mtd);
kMethod* new_Method(CTX ctx, kflag_t flag, kclass_t cid, kmethodn_t mn, knh_Fmethod func);
kindex_t knh_Method_indexOfGetterField(kMethod *o);
kindex_t knh_Method_indexOfSetterField(kMethod *o);
kDictMap* knh_Object_getXData(CTX ctx, kObject *o);
void knh_ClassTBL_addXField(CTX ctx, const knh_ClassTBL_t *ct, ktype_t type, ksymbol_t fn);
kMethod *knh_NameSpace_addXSetter(CTX ctx, kNameSpace *ns, const knh_ClassTBL_t *ct, ktype_t type, kmethodn_t mn_setter);
void knh_ClassTBL_addMethod(CTX ctx, const knh_ClassTBL_t *t, kMethod *mtd, int isCHECK);
kMethod* knh_ClassTBL_findMethodNULL(CTX ctx, const knh_ClassTBL_t *ct, kmethodn_t mn, int isGEN);
kMethod *knh_ClassTBL_getFmtNULL(CTX ctx, const knh_ClassTBL_t *t, kmethodn_t mn0);
kMethod *knh_ClassTBL_getFmt(CTX ctx, const knh_ClassTBL_t *t, kmethodn_t mn0);
void knh_NameSpace_addMethod(CTX ctx, kclass_t mtd_cid, kMethod *mtd);
kMethod* knh_NameSpace_getMethodNULL(CTX ctx, kNameSpace *ns, kclass_t cid, kmethodn_t mn);
kMethod* knh_NameSpace_getFmtNULL(CTX ctx, kNameSpace *ns, kclass_t cid, kmethodn_t mn);
void knh_NameSpace_addFmt(CTX ctx, kNameSpace *ns, kMethod *mtd);
void knh_addTypeMapFunc(CTX ctx, kflag_t flag, ktype_t stype, ktype_t ttype, knh_Ftypemap fTYPEMAP, Object *mapdata);
kTypeMap *new_TypeMapMethod(CTX ctx, kflag_t flag, kMethod *mtd);
kbool_t TypeMap_isNoSuchMapping(kTypeMap *tmr);
void knh_addTypeMapRule(CTX ctx, kclass_t scid, kclass_t tcid, knh_Ftypemaprule func);
kIterator* new_ArrayIterator(CTX ctx, kArray *a);
kbool_t knh_isArrayIterator(kIterator *itr);
void knh_Object_fastset(CTX ctx, kObject *o, kMethod *mtd, kObject *v);
void knh_Object_setData(CTX ctx, kObject *o, kMap *m, kNameSpace *ns, int Checked);
void knh_loadSystemTypeMapRule(CTX ctx);
void knh_NameSpace_setLinkClass(CTX ctx, kNameSpace *ns, kbytes_t linkname, const knh_ClassTBL_t *ct);
const knh_ClassTBL_t *knh_NameSpace_getLinkClassTBLNULL(CTX ctx, kNameSpace *ns, kbytes_t path, kclass_t tcid);
kclass_t knh_ClassTBL_linkType(CTX ctx, const knh_ClassTBL_t *ct, kclass_t tcid);
kObject *knh_NameSpace_newObject(CTX ctx, kNameSpace *ns, kString *path, kclass_t tcid);
void knh_initClassFuncData(CTX ctx, const knh_LoaderAPI_t *kapi);
kclass_t new_ClassId(CTX ctx);
void knh_EventTBL_expand(CTX ctx);
kcontext_t *new_ThreadContext(CTX ctx);
void Context_initMultiThread(CTX ctx);
kContext* knh_toContext(CTX ctx);
void knh_Context_free(CTX ctx, kcontext_t* ctxo);
void knh_beginContext(CTX ctx, void **bottom);
void knh_endContext(CTX ctx);
konoha_t konoha_open(void);
kObject **knh_reftraceRoot(CTX ctx FTRARG);
void konoha_close(konoha_t konoha);
const char* knh_sfile(const char *file);
void knh_write_now(CTX ctx, kOutputStream *w);
void knh_fsyslog(FILE *fp, const char *group, const char *msg);
void knh_logprintf(const char *group, int verbose, const char *fmt, ...);
void knh_closelog(void);
int knh_isVerboseLang(void);
void opt_verbose_lang(int mode, const char *optstr);
int knh_isVerboseGC(void);
int knh_isVerbosePref(void);
void loadPolicy(CTX ctx);
void knh_enforceSecurity(CTX ctx, kMethod *mtd);
void knh_PleaseLetUsKnowYourOS(CTX ctx, const char *msg, const char *file, int line);
kbool_t knh_VirtualMachine_launch(CTX ctx, ksfp_t *sfp);
void konoha_ginit(int argc, const char **argv);
void dbg_p(const char *file, const char *func, int line, const char *fmt, ...);
void todo_p(const char *file, const char *func, int line, const char *fmt, ...);
void knh_write_uline(CTX ctx, kOutputStream *w, kline_t uline);
void knh_write_mline(CTX ctx, kOutputStream *w, kmethodn_t mn, kline_t uline);
void knh_write_sfp(CTX ctx, kOutputStream *w, ktype_t type, ksfp_t *sfp, int level);
void knh_throw(CTX ctx, ksfp_t *sfp, long start);
void knh_assert(CTX ctx, ksfp_t *sfp, long start, kline_t uline);
kbool_t knh_isTrace(CTX ctx, const char *event);
void knh_ntrace(CTX ctx, const char *event, int pe, knh_ldata_t *ldata);
void knh_dtrace(CTX ctx, const char *event, int pe, kDictMap *data);
void THROW_Halt(CTX ctx, ksfp_t *sfp, const char *msg);
void THROW_OutOfMemory(CTX ctx, size_t size);
void THROW_StackOverflow(CTX ctx, ksfp_t *sfp);
void THROW_Arithmetic(CTX ctx, ksfp_t *sfp, const char *msg);
void THROW_TypeError(CTX ctx, ksfp_t *sfp, ktype_t reqt, ktype_t type);
void THROW_NoSuchMethod(CTX ctx, ksfp_t *sfp, kclass_t cid, kmethodn_t mn);
void THROW_ParamTypeError(CTX ctx, ksfp_t *sfp, size_t n, kmethodn_t mn, kclass_t reqt, kclass_t cid);
const knh_LoaderAPI_t* knh_getLoaderAPI(void);
void knh_initBuiltInPackage(CTX ctx, const knh_LoaderAPI_t *kapi);
void knh_loadSystemDriver(CTX ctx, kNameSpace *ns);
kPtrMap* new_PtrMap(CTX ctx, size_t max);
void* knh_PtrMap_get(CTX ctx, kPtrMap *pm, void *keyptr);
void knh_PtrMap_add(CTX ctx, kPtrMap *pm, void *keyptr, void *valueptr);
void knh_PtrMap_rm(CTX ctx, kPtrMap *pm, void *keyptr);
size_t knh_PtrMap_size(kPtrMap *pm);
void knh_PtrMap_stat(CTX ctx, kPtrMap *pm, const char *name);
kString* knh_PtrMap_getS(CTX ctx, kPtrMap *pm, const char *k, size_t len);
void knh_PtrMap_addS(CTX ctx, kPtrMap *pm, kString *v);
void knh_PtrMap_rmS(CTX ctx, kPtrMap *pm, kString *s);
kInt* knh_PtrMap_getI(CTX ctx, kPtrMap *pm, kunbox_t k);
void knh_PtrMap_addI(CTX ctx, kPtrMap *pm, kInt *v);
void knh_PtrMap_rmI(CTX ctx, kPtrMap *pm, kInt *v);
kMethod* knh_PtrMap_getM(CTX ctx, kPtrMap *pm, khashcode_t hcode);
void knh_PtrMap_addM(CTX ctx, kPtrMap *pm, khashcode_t hcode, kMethod *v);
void knh_PtrMap_rmM(CTX ctx, kPtrMap *pm, kMethod *mtd);
int knh_bytes_strcasecmp2(kbytes_t t1, kbytes_t t2);
kDictMap* new_DictMap0_(CTX ctx, size_t capacity, int isCaseMap, const char *DBGNAME);
kDictMap* knh_toDictMap(CTX ctx, kMap *m, int isCreation);
kDictSet* new_DictSet0_(CTX ctx, size_t capacity, int isCaseMap, const char *DBGNAME);
kuintptr_t knh_DictSet_valueAt(kDictSet *m, size_t n);
kindex_t knh_DictMap_index(kDictMap *m, kbytes_t key);
Object *knh_DictMap_getNULL(CTX ctx, kDictMap *m, kbytes_t key);
kuintptr_t knh_DictSet_get(CTX ctx, kDictSet *m, kbytes_t key);
void knh_DictMap_set_(CTX ctx, kDictMap *m, kString *key, dynamic *v);
void knh_DictSet_set(CTX ctx, kDictSet *m, kString *key, kuintptr_t n);
void knh_DictMap_append(CTX ctx, kDictMap *m, kString *key, kObject *v);
void knh_DictSet_append(CTX ctx, kDictSet *m, kString *key, kuintptr_t n);
void knh_DictSet_sort(CTX ctx, kDictSet *m);
void knh_loadScriptDefaultMapDSPI(CTX ctx, kNameSpace *ns);
const knh_MapDPI_t *knh_getDefaultMapDSPI(CTX ctx, kclass_t p1, kclass_t p2);
const knh_MapDPI_t *knh_getDictMapDSPI(CTX ctx, kclass_t p1, kclass_t p2);
void knh_srand(kuint_t seed);
kuint_t knh_rand(void);
kfloat_t kfloat_rand(void);
kInt* new_Int_(CTX ctx, kclass_t cid, kint_t value);
kFloat* new_Float_(CTX ctx, kclass_t cid, kfloat_t value);
Object* new_Boxing(CTX ctx, ksfp_t *sfp, const knh_ClassTBL_t *ct);
KMETHOD Bytes_getSize(CTX ctx, ksfp_t *sfp _RIX);
KMETHOD Tuple_getSize(CTX ctx, ksfp_t *sfp _RIX);
KMETHOD Map_getSize(CTX ctx, ksfp_t *sfp _RIX);
void knh_DataMap_log(CTX ctx, kDictMap *conf, ktype_t type, const char *key);
kbool_t knh_DataMap_check(CTX ctx, kDictMap *conf, ktype_t type, const char *key, const char *key2);
kString *knh_DataMap_getString(CTX ctx, kDictMap *conf, const char *key, const char *key2, kString *def);
kString *knh_View_getQuery(CTX ctx, kView *view);
const knh_sysinfo_t* knh_getsysinfo(void);
void dump_sysinfo(CTX ctx, kOutputStream *w, int isALL);
kString *knh_buff_newRealPathString(CTX ctx, kBytes *ba, size_t pos);
kPath* new_CurrentPath(CTX ctx);
kbool_t knh_exists(CTX ctx, const char *fname);
kbool_t knh_isfile(CTX ctx, const char *phname);
kbool_t knh_buff_isfile(CTX ctx, kBytes *ba, size_t pos);
kbool_t knh_isdir(CTX ctx, const char *pname);
kbool_t knh_buff_isdir(CTX ctx, kBytes *ba, size_t pos);
kbool_t knh_buff_mkdir(CTX ctx, kBytes *ba, size_t pos);
void knh_System_initPath(CTX ctx);
void *knh_dlopen(CTX ctx, const char* path);
void *knh_dlsym(CTX ctx, void* handler, const char* symbol, const char *another, int isTest);
int knh_dlclose(CTX ctx, void* handler);
const char *knh_dlerror();
const char *knh_getSystemEncoding(void);
void knh_loadSystemQueryDriver(CTX ctx, kNameSpace *ns);
kbool_t knh_isCompileOnly(CTX ctx);
void knh_setCompileMode(CTX ctx, int mode);
void knh_loadScriptPackageList(CTX ctx, const char *pkglist);
void knh_setSecurityAlertMessage(const char *msg, int isNeedFree);
int konoha_main(konoha_t konoha, int argc, const char **argv);
void knh_askSecurityAlert(CTX ctx);
void knh_checkSecurityManager(CTX ctx, ksfp_t *sfp);
kInt* new_Int_X(CTX ctx, kclass_t cid, kint_t value);
kFloat* new_Float_X(CTX ctx, kclass_t cid, kfloat_t value);
void knh_write_intx(CTX ctx, kOutputStream *w, kSemantics *u, kint_t v);
void knh_write_floatx(CTX ctx, kOutputStream *w, kSemantics *u, kfloat_t v);
void knh_Semantics_reuse(CTX ctx, kSemantics *u, kclass_t cid);
kSemantics* new_Enum(CTX ctx, char *tag, kbytes_t urn, kint_t min, kint_t max);
kSemantics* new_Unit(CTX ctx, char *tag, kbytes_t urn, kfloat_t min, kfloat_t max, kfloat_t step);
kSemantics* new_Vocab(CTX ctx, char *tag, kbytes_t urn, int base, char **terms);
kbytes_t knh_getURNAlias(CTX ctx, kbytes_t aurn);
void knh_loadScriptURNAliasData(CTX ctx, knh_StringData_t *data);
void knh_loadScriptSemanticsFuncData(CTX ctx, knh_FuncData_t *data);
kSemantics *knh_getSemantics(CTX ctx, kclass_t cid);
kclass_t knh_findcidx(CTX ctx, kbytes_t lname);
ksfp_t* knh_stack_initexpand(CTX ctx, ksfp_t *sfp, size_t n);
void knh_stack_clear(CTX ctx, ksfp_t *sfp);
ksfp_t* knh_stack_local(CTX ctx, size_t n);
void knh_checkSafePoint(CTX ctx, ksfp_t *sfp, const char *file, int line);
int event_isa(CTX ctx, kevent_t eid, kevent_t parent);
kString *knh_getEventName(CTX ctx, kevent_t eid);
kevent_t knh_addEvent(CTX ctx, kflag_t flag, kString *name, kclass_t peid);
kbool_t knh_isDefinedEvent(CTX ctx, kbytes_t t);
kevent_t knh_geteid(CTX ctx, kbytes_t t);
kException* new_Error(CTX ctx, kline_t uline, kString *emsg);
void CTX_setThrowingException(CTX ctx, kException *e);
kbool_t isCATCH(CTX ctx, krbp_t *rbp, int en, kevent_t peid);
void Context_push(CTX ctx, kObject *o);
kObject *Context_pop(CTX ctx);
kExceptionHandler* ExceptionHandler_setjmp(CTX ctx, kExceptionHandler *hdr);
kExceptionHandler *knh_ExceptionHandler_longjmp(CTX ctx, kExceptionHandler *hdr);
void knh_buff_addpath(CTX ctx, kBytes *ba, size_t pos, int needsSEP, kbytes_t t);
void knh_buff_addospath(CTX ctx, kBytes *ba, size_t pos, int needsSEP, kbytes_t t);
void knh_buff_trim(CTX ctx, kBytes *ba, size_t pos, int ch);
kPath *new_ScriptPath(CTX ctx, kString *urn, kNameSpace *ns);
kArray *knh_PathDir_toArray(CTX ctx, kPath *path);
kio_t* new_FILE(CTX ctx, FILE *fp, size_t bufsiz);
kio_t* new_io2(CTX ctx, int fd, size_t bufsiz);
kio_t* new_io2_stdio(CTX ctx, int fd, size_t bufsiz);
kio_t* new_io2ReadBuffer(CTX ctx, const char *buf, size_t bufsiz);
kio_t* new_io2WriteBuffer(CTX ctx, kBytes *ba);
kio_t *io2_null(void);
void io2_free(CTX ctx, kio_t *io2);
void io2_close(CTX ctx, kio_t *io2);
kbool_t io2_isClosed(CTX ctx, kio_t *io2);
int io2_getc(CTX ctx, kio_t *io2);
size_t io2_read(CTX ctx, kio_t *io2, char *buf, size_t bufsiz);
kString* io2_readLine(CTX ctx, kio_t *io2, kStringDecoder *dec);
void io2_readAll(CTX ctx, kio_t *io2, kBytes *ba);
void io2_flush(CTX ctx, kio_t *io2);
size_t io2_write(CTX ctx, kio_t *io2, const char *buf, size_t bufsiz);
size_t io2_writeMultiByteChar(CTX ctx, kio_t *io2, const char *buf, size_t bufsiz, kStringEncoder *enc);
kbool_t NOFILE_exists(CTX ctx, kPath *path);
void NOFILE_ospath(CTX ctx, kPath *path, kNameSpace *ns);
kio_t* NOFILE_openNULL(CTX ctx, kPath *path, const char *mode, kDictMap *conf);
const knh_PathDPI_t *knh_getDefaultPathStreamDPI(void);
kInputStream* new_BytesInputStream(CTX ctx, const char *buf, size_t bufsiz);
void knh_InputStream_setCharset(CTX ctx, kInputStream *in, kStringDecoder *c);
void knh_OutputStream_setCharset(CTX ctx, kOutputStream *w, kStringEncoder *c);
void knh_write_bool(CTX ctx, kOutputStream *w, int b);
void knh_write_ptr(CTX ctx, kOutputStream *w, void *ptr);
void knh_write_dfmt(CTX ctx, kOutputStream *w, const char *fmt, kintptr_t n);
void knh_write_ifmt(CTX ctx, kOutputStream *w, const char *fmt, kint_t n);
void knh_write_ffmt(CTX ctx, kOutputStream *w, const char *fmt, kfloat_t n);
void knh_write_flag(CTX ctx, kOutputStream *w, kflag_t flag);
void knh_write_quote(CTX ctx, kOutputStream *w, int quote, kbytes_t t, int hasUTF8);
void knh_write_cap(CTX ctx, kOutputStream *w, kbytes_t t, int hasUTF8);
void knh_write_Object(CTX ctx, kOutputStream *w, Object *o, int level);
void knh_write_InObject(CTX ctx, kOutputStream *w, Object *o, int level);
void knh_vprintf(CTX ctx, kOutputStream *w, const char *fmt, va_list ap);
void knh_initStreamFuncData(CTX ctx, const knh_LoaderAPI_t *kapi);
int knh_bytes_parseint(kbytes_t t, kint_t *value);
int knh_bytes_parsefloat(kbytes_t t, kfloat_t *value);
int knh_bytes_strcmp(kbytes_t v1, kbytes_t v2);
int knh_utf8len(int c);
kbool_t knh_bytes_checkENCODING(kbytes_t v);
size_t knh_bytes_mlen(kbytes_t v);
kbytes_t knh_bytes_mofflen(kbytes_t v, size_t moff, size_t mlen);
kint_t kchar_toucs4(kutext_t *utf8)   /* utf8 -> ucs4 */;
char *knh_format_utf8(char *buf, size_t bufsiz, kuint_t ucs4);
kString* new_String2(CTX ctx, kclass_t cid, const char *text, size_t len, int policy);
kStringDecoder* new_StringDecoderNULL(CTX ctx, kbytes_t t);
kStringEncoder* new_StringEncoderNULL(CTX ctx, kbytes_t t);
kString *CWB_newStringDECODE(CTX ctx, CWB_t *cwb, kStringDecoder *c);
int knh_bytes_strcasecmp(kbytes_t v1, kbytes_t v2);
const knh_RegexSPI_t* knh_getStrRegexSPI(void);
kbool_t Regex_isSTRREGEX(kRegex *re);
const knh_RegexSPI_t* knh_getRegexSPI(void);
void knh_linkDynamicRegex(CTX ctx);
kbool_t knh_class_canObjectCopy(CTX ctx, kclass_t cid);
const kclassdef_t* knh_getDefaultClassDef(void);
void knh_ClassTBL_setConstPool(CTX ctx, const knh_ClassTBL_t *ct);
void knh_ClassTBL_setObjectCSPI(CTX ctx, knh_ClassTBL_t *ct);
const kclassdef_t* knh_getCppClassDef(void);
kThunk* new_Thunk(CTX ctx, kclass_t p1, size_t envsize);
void knh_loadScriptSystemStructData(CTX ctx, const knh_LoaderAPI_t *kapi);
void knh_loadScriptSystemString(CTX ctx);
void knh_loadScriptSystemData(CTX ctx, kNameSpace *ns, const knh_LoaderAPI_t *kapi);
void knh_loadScriptSystemMethod(CTX ctx, const knh_LoaderAPI_t *kapi);
kString* knh_getPropertyNULL(CTX ctx, kbytes_t key);
void knh_setProperty(CTX ctx, kString *key, dynamic *value);
Object *knh_getClassConstNULL(CTX ctx, kclass_t cid, kbytes_t name);
int knh_addClassConst(CTX ctx, kclass_t cid, kString* name, Object *value);
ksymbol_t knh_addname(CTX ctx, kString *s, knh_Fdictset f);
ksymbol_t knh_getfnq(CTX ctx, kbytes_t tname, ksymbol_t def);
kmethodn_t knh_getmn(CTX ctx, kbytes_t tname, kmethodn_t def);
const char* knh_getmnname(CTX ctx, kmethodn_t mn);
kuri_t knh_getURI(CTX ctx, kbytes_t t);
kString *knh_getURN(CTX ctx, kuri_t uri);
const knh_PathDPI_t *knh_NameSpace_getStreamDPINULL(CTX ctx, kNameSpace *ns, kbytes_t path);
const knh_MapDPI_t *knh_NameSpace_getMapDPINULL(CTX ctx, kNameSpace *ns, kbytes_t path);
const knh_ConverterDPI_t *knh_NameSpace_getConverterDPINULL(CTX ctx, kNameSpace *ns, kbytes_t path);
void knh_exit(CTX ctx, int status);
kthread_t kthread_self(void);
int kthread_create(CTX ctx, kthread_t *thread, void *attr, knh_Fthread fgo, void * arg);
int kthread_detach(CTX ctx, kthread_t th);
int kthread_join(CTX ctx, kthread_t thread, void **ret);
int knh_mutex_init(kmutex_t *m);
int knh_mutex_lock(kmutex_t *m);
int kmutex_trylock(kmutex_t *m);
int knh_mutex_unlock(kmutex_t *m);
int knh_mutex_destroy(kmutex_t *m);
kmutex_t *knh_mutex_malloc(CTX ctx);
void knh_mutex_free(CTX ctx, kmutex_t *m);
knh_cond_t *kthread_cond_init(CTX ctx);
int kthread_cond_wait(knh_cond_t *cond, kmutex_t *m);
int kthread_cond_signal(knh_cond_t *cond);
int kthread_cond_broadcast(knh_cond_t *cond);
knh_cond_t *kthread_cond_init(CTX ctx);
int kthread_cond_wait(knh_cond_t *cond, kmutex_t *m);
int kthread_cond_signal(knh_cond_t *cond);
int kthread_cond_broadcast(knh_cond_t *cond);
int kthread_key_create(kthread_key_t *key);
int thread_setspecific(kthread_key_t key, const void *data);
void* kthread_getspecific(kthread_key_t key);
int kthread_key_delete(kthread_key_t key);
kArray* new_TokenArray(CTX ctx, const char *text, kline_t uline);
void knh_initSugarFuncData(CTX ctx, const knh_LoaderAPI_t *kapi);
void knh_initSugarData(CTX ctx);

#ifdef __cplusplus
}
#endif

// THIS FILE WAS AUTOMATICALLY GENERATED. DON'T EDIT.

