// THIS FILE WAS AUTOMATICALLY GENERATED

#ifdef __cplusplus
extern "C" {
#endif



#ifdef K_INTERNAL
KNHAPI2(knh_bool_t) knh_eval(CTX ctx, const char *script, knh_uline_t uline, knh_OutputStream_t *w);
KNHAPI2(knh_Array_t*) new_Array(CTX ctx, knh_class_t p1, size_t capacity);
KNHAPI2(void) knh_Array_add_(CTX ctx, knh_Array_t *a, knh_Object_t *value);
KNHAPI2(void) knh_Array_remove_(CTX ctx, knh_Array_t *a, size_t n);
KNHAPI2(void) knh_Array_swap(CTX ctx, knh_Array_t *a, size_t n, size_t m);
KNHAPI2(knh_Iterator_t*) new_IteratorG(CTX ctx, knh_class_t cid, knh_Object_t *source, knh_Fitrnext fnext);
KNHAPI2(void) knh_Bytes_clear(knh_Bytes_t *ba, size_t pos);
KNHAPI2(void) knh_Bytes_write2(CTX ctx, knh_Bytes_t *ba, const char *text, size_t len);
KNHAPI2(knh_text_t*) CWB_totext(CTX ctx, CWB_t *cwb);
KNHAPI2(knh_String_t*) CWB_newString(CTX ctx, CWB_t *cwb, int pol);
KNHAPI2(void) knh_Object_toNULL_(CTX ctx, Object *o);
KNHAPI2(knh_RawPtr_t*) new_RawPtr(CTX ctx, const knh_ClassTBL_t *ct, void *rawptr);
KNHAPI2(knh_Object_t*) new_ReturnObject(CTX ctx, knh_sfp_t *sfp);
KNHAPI2(knh_RawPtr_t*) new_ReturnCppObject(CTX ctx, knh_sfp_t *sfp, void *rawptr, knh_Frawfree pfree);
KNHAPI2(void) knh_addConstPool(CTX ctx, knh_Object_t *o);
KNHAPI2(void) knh_write_cid(CTX ctx, knh_OutputStream_t *w, knh_class_t cid);
KNHAPI2(void) knh_write_type(CTX ctx, knh_OutputStream_t *w, knh_type_t type);
KNHAPI2(Object*) knh_getClassDefaultValue(CTX ctx, knh_class_t cid);
KNHAPI2(knh_class_t) knh_type_tocid(CTX ctx, knh_type_t ptype, knh_class_t this_cid);
KNHAPI2(knh_param_t*) knh_ParamArray_get(knh_ParamArray_t *pa, size_t n);
KNHAPI2(knh_type_t) knh_Method_rtype(CTX ctx, knh_Method_t *mtd, knh_class_t this_cid);
KNHAPI2(size_t) knh_Method_psize(knh_Method_t *mtd);
KNHAPI2(knh_type_t) knh_Method_ptype(CTX ctx, knh_Method_t *mtd, size_t n, knh_class_t this_cid);
KNHAPI2(knh_type_t) knh_ParamArray_rtype(knh_ParamArray_t *pa);
KNHAPI2(void) knh_write_mn(CTX ctx, knh_OutputStream_t *w, knh_methodn_t mn);
KNHAPI2(knh_bool_t) Method_isAbstract(knh_Method_t *mtd);
KNHAPI2(void) knh_Func_invoke(CTX ctx, knh_Func_t *fo, knh_sfp_t *rtnsfp, int argc);
KNHAPI2(void) knh_addTypeMap(CTX ctx, knh_TypeMap_t *tmr, int initCache);
KNHAPI2(void) knh_TypeMap_exec(CTX ctx, knh_TypeMap_t *tmr, knh_sfp_t *sfp _RIX);
KNHAPI2(knh_TypeMap_t*) new_TypeMap(CTX ctx, knh_flag_t flag, knh_class_t scid, knh_class_t tcid, knh_Ftypemap func);
KNHAPI2(knh_TypeMap_t*) new_TypeMapData(CTX ctx, knh_flag_t flag, knh_class_t scid, knh_class_t tcid, knh_Ftypemap func, Object *mapdata);
KNHAPI2(knh_TypeMap_t*) knh_findTypeMapNULL(CTX ctx, knh_class_t scid0, knh_class_t tcid0);
KNHAPI2(knh_context_t*) knh_getCurrentContext(void);
KNHAPI2(int) knh_isVerbose(void);
KNHAPI2(void) knh_nthrow(CTX ctx, knh_sfp_t *sfp, const char *fault, knh_ldata_t *ldata);
KNHAPI2(void) THROW_OutOfRange(CTX ctx, knh_sfp_t *sfp, knh_int_t n, size_t max);
KNHAPI2(knh_String_t*) knh_DictMap_keyAt(knh_DictMap_t *m, size_t n);
KNHAPI2(Object*) knh_DictMap_valueAt(knh_DictMap_t *m, size_t n);
KNHAPI2(knh_Map_t*) new_DataMap(CTX ctx);
KNHAPI2(void) knh_DataMap_set(CTX ctx, knh_Map_t *m, knh_String_t *key, knh_Object_t *value);
KNHAPI2(void) knh_DataMap_setString(CTX ctx, knh_Map_t *m, const char *key, const char *value);
KNHAPI2(void) knh_DataMap_setInt(CTX ctx, knh_Map_t *m, const char *key, knh_int_t value);
KNHAPI2(void) knh_DataMap_setFloat(CTX ctx, knh_Map_t *m, const char *key, knh_float_t value);
KNHAPI2(void) knh_DataMap_setBlob(CTX ctx, knh_Map_t *m, const char *key, const char *value, size_t size);
KNHAPI2(knh_Int_t*) new_Int(CTX ctx, knh_int_t value);
KNHAPI2(knh_Float_t*) new_Float(CTX ctx, knh_float_t value);
KNHAPI2(void) knh_boxing(CTX ctx, knh_sfp_t *sfp, int type);
KNHAPI2(knh_Path_t*) new_Path(CTX ctx, knh_String_t *path);
KNHAPI2(knh_InputStream_t*) new_InputStream(CTX ctx, knh_io2_t *io2, knh_Path_t *path);
KNHAPI2(knh_OutputStream_t*) new_OutputStream(CTX ctx,  knh_io2_t *io2, knh_Path_t *path);
KNHAPI2(knh_OutputStream_t*) new_BytesOutputStream(CTX ctx, knh_Bytes_t *ba);
KNHAPI2(void) knh_OutputStream_flush(CTX ctx, knh_OutputStream_t *w);
KNHAPI2(void) knh_OutputStream_putc(CTX ctx, knh_OutputStream_t *w, int ch);
KNHAPI2(void) knh_OutputStream_write(CTX ctx, knh_OutputStream_t *w, knh_bytes_t buf);
KNHAPI2(void) knh_OutputStream_p(CTX ctx, knh_OutputStream_t *w, knh_bytes_t buf);
KNHAPI2(void) knh_write_EOL(CTX ctx, knh_OutputStream_t *w);
KNHAPI2(void) knh_write_TAB(CTX ctx, knh_OutputStream_t *w);
KNHAPI2(void) knh_write_ascii(CTX ctx, knh_OutputStream_t *w, const char *text);
KNHAPI2(void) knh_write_utf8(CTX ctx, knh_OutputStream_t *w, knh_bytes_t t, int hasUTF8);
KNHAPI2(void) knh_printf(CTX ctx, knh_OutputStream_t *w, const char *fmt, ...);
KNHAPI2(knh_String_t*) new_String(CTX ctx, const char *str);
KNHAPI2(void) knh_setPropertyText(CTX ctx, char *key, char *value);
KNHAPI2(knh_String_t*) knh_getFieldName(CTX ctx, ksymbol_t fn);
#endif

typedef struct knh_api2_t {
	size_t crc32;
	Object*  (*DictMap_valueAt)(knh_DictMap_t *m, size_t n);
	Object*  (*getClassDefaultValue)(CTX ctx, knh_class_t cid);
	int  (*isVerbose)(void);
	knh_Array_t* (*new_Array)(CTX ctx, knh_class_t p1, size_t capacity);
	knh_Float_t* (*new_Float)(CTX ctx, knh_float_t value);
	knh_InputStream_t* (*new_InputStream)(CTX ctx, knh_io2_t *io2, knh_Path_t *path);
	knh_Int_t* (*new_Int)(CTX ctx, knh_int_t value);
	knh_Iterator_t* (*new_IteratorG)(CTX ctx, knh_class_t cid, knh_Object_t *source, knh_Fitrnext fnext);
	knh_Map_t* (*new_DataMap)(CTX ctx);
	knh_Object_t* (*new_ReturnObject)(CTX ctx, knh_sfp_t *sfp);
	knh_OutputStream_t* (*new_BytesOutputStream)(CTX ctx, knh_Bytes_t *ba);
	knh_OutputStream_t* (*new_OutputStream)(CTX ctx,  knh_io2_t *io2, knh_Path_t *path);
	knh_Path_t* (*new_Path)(CTX ctx, knh_String_t *path);
	knh_RawPtr_t* (*new_RawPtr)(CTX ctx, const knh_ClassTBL_t *ct, void *rawptr);
	knh_RawPtr_t* (*new_ReturnCppObject)(CTX ctx, knh_sfp_t *sfp, void *rawptr, knh_Frawfree pfree);
	knh_String_t* (*CWB_newString)(CTX ctx, CWB_t *cwb, int pol);
	knh_String_t*  (*DictMap_keyAt)(knh_DictMap_t *m, size_t n);
	knh_String_t*  (*getFieldName)(CTX ctx, ksymbol_t fn);
	knh_String_t* (*new_String)(CTX ctx, const char *str);
	knh_TypeMap_t*  (*findTypeMapNULL)(CTX ctx, knh_class_t scid0, knh_class_t tcid0);
	knh_TypeMap_t* (*new_TypeMap)(CTX ctx, knh_flag_t flag, knh_class_t scid, knh_class_t tcid, knh_Ftypemap func);
	knh_TypeMap_t* (*new_TypeMapData)(CTX ctx, knh_flag_t flag, knh_class_t scid, knh_class_t tcid, knh_Ftypemap func, Object *mapdata);
	knh_bool_t (*Method_isAbstract)(knh_Method_t *mtd);
	knh_bool_t  (*eval)(CTX ctx, const char *script, knh_uline_t uline, knh_OutputStream_t *w);
	knh_class_t  (*type_tocid)(CTX ctx, knh_type_t ptype, knh_class_t this_cid);
	knh_context_t*  (*getCurrentContext)(void);
	knh_param_t*  (*ParamArray_get)(knh_ParamArray_t *pa, size_t n);
	knh_text_t* (*CWB_totext)(CTX ctx, CWB_t *cwb);
	knh_type_t  (*Method_ptype)(CTX ctx, knh_Method_t *mtd, size_t n, knh_class_t this_cid);
	knh_type_t  (*Method_rtype)(CTX ctx, knh_Method_t *mtd, knh_class_t this_cid);
	knh_type_t  (*ParamArray_rtype)(knh_ParamArray_t *pa);
	size_t  (*Method_psize)(knh_Method_t *mtd);
	void (*THROW_OutOfRange)(CTX ctx, knh_sfp_t *sfp, knh_int_t n, size_t max);
	void  (*Array_add_)(CTX ctx, knh_Array_t *a, knh_Object_t *value);
	void  (*Array_remove_)(CTX ctx, knh_Array_t *a, size_t n);
	void  (*Array_swap)(CTX ctx, knh_Array_t *a, size_t n, size_t m);
	void  (*Bytes_clear)(knh_Bytes_t *ba, size_t pos);
	void  (*Bytes_write2)(CTX ctx, knh_Bytes_t *ba, const char *text, size_t len);
	void  (*DataMap_set)(CTX ctx, knh_Map_t *m, knh_String_t *key, knh_Object_t *value);
	void  (*DataMap_setBlob)(CTX ctx, knh_Map_t *m, const char *key, const char *value, size_t size);
	void  (*DataMap_setFloat)(CTX ctx, knh_Map_t *m, const char *key, knh_float_t value);
	void  (*DataMap_setInt)(CTX ctx, knh_Map_t *m, const char *key, knh_int_t value);
	void  (*DataMap_setString)(CTX ctx, knh_Map_t *m, const char *key, const char *value);
	void  (*Func_invoke)(CTX ctx, knh_Func_t *fo, knh_sfp_t *rtnsfp, int argc);
	void  (*Object_toNULL_)(CTX ctx, Object *o);
	void  (*OutputStream_flush)(CTX ctx, knh_OutputStream_t *w);
	void  (*OutputStream_p)(CTX ctx, knh_OutputStream_t *w, knh_bytes_t buf);
	void  (*OutputStream_putc)(CTX ctx, knh_OutputStream_t *w, int ch);
	void  (*OutputStream_write)(CTX ctx, knh_OutputStream_t *w, knh_bytes_t buf);
	void  (*TypeMap_exec)(CTX ctx, knh_TypeMap_t *tmr, knh_sfp_t *sfp _RIX);
	void  (*addConstPool)(CTX ctx, knh_Object_t *o);
	void  (*addTypeMap)(CTX ctx, knh_TypeMap_t *tmr, int initCache);
	void  (*boxing)(CTX ctx, knh_sfp_t *sfp, int type);
	void  (*nthrow)(CTX ctx, knh_sfp_t *sfp, const char *fault, knh_ldata_t *ldata);
	void  (*printf)(CTX ctx, knh_OutputStream_t *w, const char *fmt, ...);
	void  (*setPropertyText)(CTX ctx, char *key, char *value);
	void  (*write_EOL)(CTX ctx, knh_OutputStream_t *w);
	void  (*write_TAB)(CTX ctx, knh_OutputStream_t *w);
	void  (*write_ascii)(CTX ctx, knh_OutputStream_t *w, const char *text);
	void  (*write_cid)(CTX ctx, knh_OutputStream_t *w, knh_class_t cid);
	void  (*write_mn)(CTX ctx, knh_OutputStream_t *w, knh_methodn_t mn);
	void  (*write_type)(CTX ctx, knh_OutputStream_t *w, knh_type_t type);
	void  (*write_utf8)(CTX ctx, knh_OutputStream_t *w, knh_bytes_t t, int hasUTF8);
} knh_api2_t;
	
#define K_API2_CRC32 ((size_t)849853371)
#ifdef K_DEFINE_API2
static const knh_api2_t* getapi2(void) {
	static const knh_api2_t DATA_API2 = {
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
		Method_isAbstract,
		knh_eval,
		knh_type_tocid,
		knh_getCurrentContext,
		knh_ParamArray_get,
		CWB_totext,
		knh_Method_ptype,
		knh_Method_rtype,
		knh_ParamArray_rtype,
		knh_Method_psize,
		THROW_OutOfRange,
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
		knh_Object_toNULL_,
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
#define Method_isAbstract   ctx->api2->Method_isAbstract
#define knh_eval   ctx->api2->eval
#define knh_type_tocid   ctx->api2->type_tocid
#define knh_getCurrentContext   ctx->api2->getCurrentContext
#define knh_ParamArray_get   ctx->api2->ParamArray_get
#define CWB_totext   ctx->api2->CWB_totext
#define knh_Method_ptype   ctx->api2->Method_ptype
#define knh_Method_rtype   ctx->api2->Method_rtype
#define knh_ParamArray_rtype   ctx->api2->ParamArray_rtype
#define knh_Method_psize   ctx->api2->Method_psize
#define THROW_OutOfRange   ctx->api2->THROW_OutOfRange
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
#define knh_Object_toNULL_   ctx->api2->Object_toNULL_
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
knh_BasicBlock_t* new_BasicBlockLABEL(CTX ctx);
void knh_BasicBlock_add_(CTX ctx, knh_BasicBlock_t *bb, knh_ushort_t line, knh_opline_t *op, size_t size);
KMETHOD knh_Fmethod_runVM(CTX ctx, knh_sfp_t *sfp _RIX);
void knh_PROP(CTX ctx, knh_sfp_t *sfp, knh_sfpidx_t c, const knh_ClassTBL_t *ct);
void knh_NPROP(CTX ctx, knh_sfp_t *sfp, knh_sfpidx_t c, const knh_ClassTBL_t *ct);
void knh_PRINT(CTX ctx, knh_sfp_t *sfp, knh_flag_t flag, knh_uline_t uline, knh_String_t *msg, knh_Object_t *o);
void knh_PRINTi(CTX ctx, knh_sfp_t *sfp, knh_flag_t flag, knh_uline_t uline, knh_String_t *msg, knh_int_t n);
void knh_PRINTf(CTX ctx, knh_sfp_t *sfp, knh_flag_t flag, knh_uline_t uline, knh_String_t *msg, knh_float_t f);
void knh_PRINTb(CTX ctx, knh_sfp_t *sfp, knh_flag_t flag, knh_uline_t uline, knh_String_t *msg, knh_bool_t b);
void GammaBuilder_shiftLocalScope(CTX ctx);
void knh_Method_asm(CTX ctx, knh_Method_t *mtd, knh_StmtExpr_t *stmtB, knh_Ftyping typing);
KMETHOD knh_Fmethod_asm(CTX ctx, knh_sfp_t *sfp _RIX);
void knh_loadScriptSystemKonohaCode(CTX ctx);
void knh_write_vmfunc(CTX ctx, knh_OutputStream_t *w, void *f);
knh_Fmethod knh_gluefunc(CTX ctx, knh_Method_t *mtd, knh_NameSpace_t *ns, knh_DictMap_t *mdata);
knh_bool_t knh_Method_ffi(CTX ctx, knh_Method_t *mtd, knh_NameSpace_t *ns, knh_DictMap_t *mdata);
void knh_loadFFIDriver(CTX ctx, knh_NameSpace_t *ns);
void *knh_copyCallbackFunc(CTX ctx, void *tmpl, void *dest, knh_Func_t *fo);
const char* TERM_BBOLD(CTX ctx);
const char* TERM_EBOLD(CTX ctx);
const char* TERM_BNOTE(CTX ctx, int pe);
const char* TERM_ENOTE(CTX ctx, int pe);
knh_Term_t* ERROR_NotFound(CTX ctx, const char *whatis, const char *t);
void WARN_NotFound(CTX ctx, const char *whatis, const char *t);
knh_Term_t* ERROR_Incompatible(CTX ctx, const char *whatis, const char *name);
knh_Term_t* ERROR_SingleParam(CTX ctx);
void WARN_MuchBetter(CTX ctx, const char *token, const char *token2);
void WarningMethodName(CTX ctx, const char *name);
void WARN_MustCloseWith(CTX ctx, int ch);
void WARN_Semicolon(CTX ctx);
void WARN_UnxpectedMultiByteChar(CTX ctx, const char *ch);
knh_Term_t *ErrorHazardousStatement(CTX ctx);
void WarningNoEffect(CTX ctx);
knh_Term_t* ErrorMisplaced(CTX ctx);
knh_Term_t* ERROR_UnableToAdd(CTX ctx, knh_class_t cid, const char *whatis);
knh_Term_t* ERROR_Block(CTX ctx, const char* block);
knh_Term_t* ERROR_WrongFFILink(CTX ctx, const char* link);
knh_Term_t* ERROR_text(CTX ctx, const char *keyword K_TRACEARGV);
knh_Term_t* ERROR_Term(CTX ctx, knh_Term_t *tk K_TRACEARGV);
knh_Term_t* ERROR_Stmt(CTX ctx, knh_StmtExpr_t *stmt K_TRACEARGV);
knh_Term_t* ERROR_TermIsNot(CTX ctx, knh_Term_t *tk, const char* whatis);
knh_Term_t* ERROR_TermIs(CTX ctx, knh_Term_t *tk, const char* whatis);
knh_Term_t* ERROR_Required(CTX ctx, knh_Term_t *tk, const char *stmtexpr, const char *token);
void WarningNotInitialized(CTX ctx, knh_Term_t *tk, const char *tool);
knh_Term_t* ERROR_RegexCompilation(CTX ctx, knh_Term_t *tk, const char *regname, const char *regdata);
knh_Term_t* ERROR_Undefined(CTX ctx, const char *whatis, knh_class_t cid, knh_Term_t *tk);
knh_Term_t* ERROR_UndefinedName(CTX ctx, knh_Term_t *tk);
void WARN_Undefined(CTX ctx, const char *whatis, knh_class_t cid, knh_Term_t *tk);
knh_Term_t* ERROR_AlreadyDefined(CTX ctx, const char *whatis, Object *o);
void WARN_AlreadyDefined(CTX ctx, const char *whatis, Object *o);
void WARN_AlreadyDefinedClass(CTX ctx, knh_class_t cid, knh_class_t oldcid);
knh_Term_t* ERROR_Denied(CTX ctx, const char *why, knh_Term_t *tk);
void WarningUnknownClass(CTX ctx, knh_Term_t *tk, knh_class_t defc);
knh_Term_t* ERROR_UnableToAssign(CTX ctx, knh_Term_t *tk);
knh_Term_t* ErrorUnsupportedConstructor(CTX ctx, knh_class_t mtd_cid);
knh_Term_t* ERROR_UndefinedBehavior(CTX ctx, const char *token);
knh_Term_t* ERROR_CompilerControlledParameter(CTX ctx, knh_class_t mtd_cid, knh_methodn_t mn, int n);
knh_Term_t* ERROR_RequiredParameter(CTX ctx);
void WARN_WrongTypeParam(CTX ctx, knh_class_t cid);
void INFO_Typing(CTX ctx, const char *prefix, knh_bytes_t name, knh_type_t type);
void WARN_Overflow(CTX ctx, const char *floatorint, knh_bytes_t t);
void WARN_Unused(CTX ctx, knh_Term_t *tk, ksymbol_t fn);
knh_Term_t* ERROR_AlreadyDefinedType(CTX ctx, ksymbol_t fn, knh_type_t type);
knh_Term_t* ErrorTooManyVariables(CTX ctx);
void WARN_UseDefaultValue(CTX ctx, const char *whatis, knh_type_t type);
void WarningNoFmt(CTX ctx, const char *fmt);
void WarningIllegalFormatting(CTX ctx, const char *fmt);
knh_Term_t* ERROR_MethodIsNot(CTX ctx, knh_Method_t *mtd, const char *how);
void WARN_MethodIs(CTX ctx, knh_Method_t *mtd, const char *how);
knh_Term_t *ERROR_Unsupported(CTX ctx, const char *whatis, knh_class_t cid, const char *symbol);
void WARN_Unsupported(CTX ctx, const char *msg);
void WARN_Ignored(CTX ctx, const char *whatis, knh_class_t cid, const char *symbol);
void WARN_Unnecesary(CTX ctx, knh_Term_t *tk);
void WarningUnnecessaryOperation(CTX ctx, const char *msg);
void WARN_TooMany(CTX ctx, const char *whatis, const char *symbol);
knh_Term_t* ERROR_Needs(CTX ctx, const char *whatis);
knh_Term_t* ERROR_MustBe(CTX ctx, const char *whatis, const char* token);
knh_Term_t* ERROR_OutOfIndex(CTX ctx, knh_int_t s, knh_int_t n, knh_int_t e);
void WarningNullable(CTX ctx, knh_class_t cid);
knh_Term_t* ErrorComparedDiffrentType(CTX ctx, knh_type_t t1, knh_type_t t2);
knh_Term_t *TERROR_Term(CTX ctx, knh_Term_t *tk, knh_class_t type, knh_class_t reqt);
knh_Term_t *TypeErrorStmtNN(CTX ctx, knh_StmtExpr_t *stmt, int n, knh_type_t reqt, knh_type_t type);
knh_Term_t* TypeErrorCallParam(CTX ctx, int n, knh_Method_t *mtd, knh_class_t reqt, knh_class_t type);
void WARN_Cast(CTX ctx, const char *whatis, knh_class_t tcid, knh_class_t scid);
knh_Term_t* ERROR_ForeachNotIterative(CTX ctx, knh_class_t p1, knh_class_t type);
void WarningDuplicatedDefault(CTX ctx);
void WarningNotConstant(CTX ctx);
void WarningAlwaysFalseAssertion(CTX ctx);
void WarningDifferentMethodClass(CTX ctx, knh_bytes_t name, knh_class_t cid);
void WarningDeprecated(CTX ctx, const char *msg);
knh_Term_t* ErrorFinalMethod(CTX ctx, knh_class_t cid, knh_methodn_t mn);
knh_Term_t* ErrorDifferentlyDefinedMethod(CTX ctx, knh_class_t mtd_cid, knh_methodn_t mn);
knh_Term_t* ERROR_OnlyTopLevel(CTX ctx, const char* stmt);
knh_Term_t* ErrorUndefinedLabel(CTX ctx, knh_Term_t *tk);
void WarningAbstractMethod(CTX ctx, knh_Method_t *mtd);
void WARN_DividedByZero(CTX ctx);
void WarningUndefinedFmt(CTX ctx, knh_class_t cid, knh_methodn_t mn);
void NoticeInliningMethod(CTX ctx, knh_Method_t *mtd);
knh_NameSpace_t* new_NameSpace(CTX ctx, knh_NameSpace_t *parent);
knh_class_t knh_NameSpace_getcid(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t sname);
knh_bool_t knh_NameSpace_isInsideScope(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid);
knh_flag_t knh_Stmt_flag_(CTX ctx, knh_StmtExpr_t *stmt, knh_bytes_t name, knh_flag_t flag);
knh_class_t knh_NameSpace_getFuncClass(CTX ctx, knh_NameSpace_t *ns, knh_methodn_t mn);
knh_type_t knh_NameSpace_gettype(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t name);
knh_type_t knh_NameSpace_tagcid(CTX ctx, knh_NameSpace_t *o, knh_class_t cid, knh_bytes_t tag);
knh_bool_t knh_NameSpace_include(CTX ctx, knh_NameSpace_t *ns, knh_Path_t *pth);
void knh_Script_setNSName(CTX ctx, knh_Script_t* scr, knh_String_t *nsname);
knh_status_t knh_loadPackage(CTX ctx, knh_bytes_t pkgname);
Object *knh_NameSpace_getConstNULL(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t name);
void knh_RefTraverse(CTX ctx, knh_Ftraverse ftr);
knh_bool_t knh_beval2(CTX ctx, const char *script, knh_uline_t uline);
knh_bool_t knh_beval(CTX ctx, knh_InputStream_t *in, knh_uline_t uline);
knh_status_t knh_InputStream_load(CTX ctx, knh_InputStream_t *in, knh_uline_t uline);
knh_status_t knh_InputStream_load(CTX ctx, knh_InputStream_t *in, knh_uline_t uline);
knh_status_t knh_load(CTX ctx, knh_Path_t *pth);
knh_status_t knh_startScript(CTX ctx, const char *path);
knh_Term_t* new_Term(CTX ctx, knh_term_t tt);
knh_StmtExpr_t* new_Stmt2(CTX ctx, knh_term_t stt, ...);
void knh_Stmt_swap(CTX ctx, knh_StmtExpr_t *stmt, size_t n, size_t m);
void knh_StmtExpr_trimToSize(CTX ctx, knh_StmtExpr_t *stmt, size_t n);
knh_Term_t *knh_Stmt_done(CTX ctx, knh_StmtExpr_t *stmt);
void knh_StmtExpr_toERR(CTX ctx, knh_StmtExpr_t *stmt, knh_Term_t *tkERR);
knh_Term_t *knh_Stmt_add_(CTX ctx, knh_StmtExpr_t *stmt, ...);
knh_Term_t *new_TermMN(CTX ctx, knh_methodn_t mn);
void knh_Regex_setGlobalOption(CTX ctx, knh_Regex_t *re, const char *opt);
knh_StmtExpr_t *knh_parseStmt(CTX ctx, const char *script, knh_uline_t uline);
knh_StmtExpr_t *knh_InputStream_parseStmt(CTX ctx, knh_InputStream_t *in, knh_uline_t *ul);
knh_StmtExpr_t *knh_Term_parseStmt(CTX ctx, knh_uline_t uline, knh_Term_t *tk);
knh_StmtExpr_t *knh_bytes_parseStmt(CTX ctx, knh_bytes_t expr, knh_uline_t uline);
knh_Term_t* Tn_typing(CTX ctx, knh_StmtExpr_t *stmt, size_t n, knh_type_t reqt, knh_flag_t opflag);
knh_Term_t* knh_Term_toCID(CTX ctx, knh_Term_t *tk, knh_class_t cid);
knh_Term_t* knh_Term_toTYPED(CTX ctx, knh_Term_t *tk, knh_term_t tt, knh_type_t type, knh_short_t nn);
knh_Term_t* new_TermTYPED(CTX ctx, knh_term_t tt, knh_type_t type, knh_short_t nn);
knh_bool_t StmtMETA_is_(CTX ctx, knh_StmtExpr_t *stmt, knh_bytes_t name);
ksymbol_t Term_fnq(CTX ctx, knh_Term_t *tk);
knh_class_t knh_Term_cid(CTX ctx, knh_Term_t *tk, knh_type_t reqt);
void knh_GammaBuilder_init(CTX ctx);
knh_bool_t typingFunction(CTX ctx, knh_Method_t *mtd, knh_StmtExpr_t *stmtB);
void SCRIPT_typing(CTX ctx, knh_StmtExpr_t *stmt);
knh_bool_t typingMethod2(CTX ctx, knh_Method_t *mtd, knh_StmtExpr_t *stmtB);
void SCRIPT_asm(CTX ctx, knh_StmtExpr_t *stmt);
void knh_opcode_check(void);
const char *OPCODE__(knh_opcode_t opcode);
size_t knh_opcode_size(knh_opcode_t opcode);
knh_bool_t knh_opcode_hasjump(knh_opcode_t opcode);
knh_bool_t knh_opcode_usedef(knh_opcode_t opcode, int i);
knh_Object_t** knh_opline_reftrace(CTX ctx, knh_opline_t *c FTRARG);
void knh_opcode_dump(CTX ctx, knh_opline_t *c, knh_OutputStream_t *w, knh_opline_t *pc_start);
void knh_opcode_shift(knh_opline_t *c, int shift);
knh_opline_t* knh_VirtualMachine_run(CTX ctx, knh_sfp_t *sfp0, knh_opline_t *pc);
knh_Array_t* new_ArrayG(CTX ctx, knh_class_t cid, size_t capacity);
void knh_Array_grow(CTX ctx, knh_Array_t *a, size_t newsize, size_t reqsize);
void knh_Array_clear(CTX ctx, knh_Array_t *a, size_t n);
knh_Array_t* new_Array0(CTX ctx, size_t capacity);
void knh_Array_initAPI(CTX ctx, knh_Array_t *a);
void knh_Iterator_close(CTX ctx, knh_Iterator_t *it);
void *bm_malloc(CTX ctx, size_t n);
void bm_free(CTX ctx, void *ptr, size_t n);
void *bm_realloc(CTX ctx, void *ptr, size_t os, size_t ns);
void knh_share_initArena(CTX ctx, knh_share_t *share);
void knh_share_freeArena(CTX ctx, knh_share_t *share);
void knh_initFirstObjectArena(CTX ctx);
void knh_ObjectArena_finalfree(CTX ctx, knh_ObjectArenaTBL_t *oat, size_t oatSize);
knh_bool_t knh_isObject(CTX ctx, knh_Object_t *o);
knh_Object_t *new_hObject_(CTX ctx, const knh_ClassTBL_t *ct);
knh_Object_t *new_Object_init2(CTX ctx, const knh_ClassTBL_t *ct);
void TR_NEW(CTX ctx, knh_sfp_t *sfp, knh_sfpidx_t c, const knh_ClassTBL_t *ct);
size_t k_goodsize(size_t ss);
size_t k_goodsize2(size_t ss, size_t wsize);
const knh_dim_t *new_dim(CTX ctx, size_t capacity, size_t wsize);
void knh_dimfree(CTX ctx, void *p, const knh_dim_t *dim);
void knh_Bytes_expands(CTX ctx, knh_Bytes_t *ba, size_t newsize);
void knh_Bytes_dispose(CTX ctx, knh_Bytes_t *ba);
knh_Bytes_t* new_Bytes(CTX ctx, const char *name, size_t capacity);
void knh_Bytes_ensureSize(CTX ctx, knh_Bytes_t *ba, size_t len);
const char *knh_Bytes_ensureZero(CTX ctx, knh_Bytes_t *ba);
void knh_Bytes_putc(CTX ctx, knh_Bytes_t *ba, int ch);
void knh_Bytes_reduce(knh_Bytes_t *ba, size_t size);
void knh_Bytes_write(CTX ctx, knh_Bytes_t *ba, knh_bytes_t t);
knh_bytes_t CWB_ensure(CTX ctx, CWB_t *cwb, knh_bytes_t t, size_t reqsize);
int knh_Object_compareTo(Object *o1, Object *o2);
knh_bool_t knh_invokeMethod0(CTX ctx, Object *o, knh_NameSpace_t *ns, unsigned long mnd, void **retval, ...);
knh_RawPtr_t *new_Pointer(CTX ctx, const char *name, void *rawptr, knh_Frawfree pfree);
const char *SAFESTRUCT__(CTX ctx, knh_class_t bcid);
const char *SAFETYPE__(CTX ctx, knh_type_t type);
const char *SAFECLASS__(CTX ctx, knh_class_t cid);
const knh_ClassTBL_t* DBG_ClassTBL(CTX ctx, knh_class_t cid);
knh_Class_t *new_Type(CTX ctx, knh_type_t type);
void knh_write_cname(CTX ctx, knh_OutputStream_t *w, knh_class_t cid);
void knh_setClassName(CTX ctx, knh_class_t cid, knh_String_t *lname, knh_String_t *snameNULL);
knh_class_t knh_getcid(CTX ctx, knh_bytes_t lname);
void knh_setClassDefaultValue_(CTX ctx, knh_class_t cid, Object *value, knh_Fdefnull f);
void knh_setClassDef(CTX ctx, knh_ClassTBL_t *ct, const knh_ClassDef_t *cdef);
knh_bool_t ClassTBL_isa_(CTX ctx, const knh_ClassTBL_t *ct, const knh_ClassTBL_t *ct2);
int knh_class_isGenerics(CTX ctx, knh_class_t cid);
knh_bytes_t knh_class_bname(CTX ctx, knh_class_t bcid);
void knh_setClassParam(CTX ctx, knh_ClassTBL_t *t, knh_ParamArray_t *pa);
knh_class_t knh_addGenericsClass(CTX ctx, knh_class_t cid, knh_class_t bcid, knh_ParamArray_t *pa);
knh_class_t knh_class_Generics(CTX ctx, knh_class_t bcid, knh_ParamArray_t *pa);
knh_class_t knh_class_P1(CTX ctx, knh_class_t bcid, knh_type_t p1);
knh_class_t knh_class_P2(CTX ctx, knh_class_t bcid, knh_type_t p1, knh_type_t p2);
knh_bool_t knh_ParamArray_hasTypeVar(knh_ParamArray_t *pa);
void knh_ParamArray_tocid(CTX ctx, knh_ParamArray_t *pa, knh_class_t this_cid, knh_ParamArray_t *npa);
knh_ParamArray_t *new_ParamArrayR0(CTX ctx, knh_type_t t);
knh_ParamArray_t *new_ParamArrayP1(CTX ctx, knh_type_t rtype, knh_type_t p1, ksymbol_t fn1);
void knh_ParamArray_add(CTX ctx, knh_ParamArray_t *pa, knh_param_t p);
void knh_ParamArray_addParam(CTX ctx, knh_ParamArray_t *pa, knh_type_t type, ksymbol_t fn);
void knh_ParamArray_addReturnType(CTX ctx, knh_ParamArray_t *pa, knh_type_t type);
knh_bool_t knh_ParamArray_equalsType(knh_ParamArray_t *pa, knh_ParamArray_t *pa2);
void knh_Method_setFunc(CTX ctx, knh_Method_t *mtd, knh_Fmethod func);
void knh_Method_toAbstract(CTX ctx, knh_Method_t *mtd);
knh_Method_t* new_Method(CTX ctx, knh_flag_t flag, knh_class_t cid, knh_methodn_t mn, knh_Fmethod func);
knh_index_t knh_Method_indexOfGetterField(knh_Method_t *o);
knh_index_t knh_Method_indexOfSetterField(knh_Method_t *o);
knh_DictMap_t* knh_Object_getXData(CTX ctx, knh_Object_t *o);
void knh_ClassTBL_addXField(CTX ctx, const knh_ClassTBL_t *ct, knh_type_t type, ksymbol_t fn);
knh_Method_t *knh_NameSpace_addXSetter(CTX ctx, knh_NameSpace_t *ns, const knh_ClassTBL_t *ct, knh_type_t type, knh_methodn_t mn_setter);
void knh_ClassTBL_addMethod(CTX ctx, const knh_ClassTBL_t *t, knh_Method_t *mtd, int isCHECK);
knh_Method_t* knh_ClassTBL_findMethodNULL(CTX ctx, const knh_ClassTBL_t *ct, knh_methodn_t mn, int isGEN);
knh_Method_t *knh_ClassTBL_getFmtNULL(CTX ctx, const knh_ClassTBL_t *t, knh_methodn_t mn0);
knh_Method_t *knh_ClassTBL_getFmt(CTX ctx, const knh_ClassTBL_t *t, knh_methodn_t mn0);
void knh_NameSpace_addMethod(CTX ctx, knh_class_t mtd_cid, knh_Method_t *mtd);
knh_Method_t* knh_NameSpace_getMethodNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_methodn_t mn);
knh_Method_t* knh_NameSpace_getFmtNULL(CTX ctx, knh_NameSpace_t *ns, knh_class_t cid, knh_methodn_t mn);
void knh_NameSpace_addFmt(CTX ctx, knh_NameSpace_t *ns, knh_Method_t *mtd);
void knh_addTypeMapFunc(CTX ctx, knh_flag_t flag, knh_type_t stype, knh_type_t ttype, knh_Ftypemap fTYPEMAP, Object *mapdata);
knh_TypeMap_t *new_TypeMapMethod(CTX ctx, knh_flag_t flag, knh_Method_t *mtd);
knh_bool_t TypeMap_isNoSuchMapping(knh_TypeMap_t *tmr);
void knh_addTypeMapRule(CTX ctx, knh_class_t scid, knh_class_t tcid, knh_Ftypemaprule func);
knh_Iterator_t* new_ArrayIterator(CTX ctx, knh_Array_t *a);
knh_bool_t knh_isArrayIterator(knh_Iterator_t *itr);
void knh_Object_fastset(CTX ctx, knh_Object_t *o, knh_Method_t *mtd, knh_Object_t *v);
void knh_Object_setData(CTX ctx, knh_Object_t *o, knh_Map_t *m, knh_NameSpace_t *ns, int Checked);
void knh_loadSystemTypeMapRule(CTX ctx);
void knh_NameSpace_setLinkClass(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t linkname, const knh_ClassTBL_t *ct);
const knh_ClassTBL_t *knh_NameSpace_getLinkClassTBLNULL(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path, knh_class_t tcid);
knh_class_t knh_ClassTBL_linkType(CTX ctx, const knh_ClassTBL_t *ct, knh_class_t tcid);
knh_Object_t *knh_NameSpace_newObject(CTX ctx, knh_NameSpace_t *ns, knh_String_t *path, knh_class_t tcid);
void knh_initClassFuncData(CTX ctx, const knh_LoaderAPI_t *kapi);
knh_class_t new_ClassId(CTX ctx);
void knh_EventTBL_expand(CTX ctx);
knh_context_t *new_ThreadContext(CTX ctx);
void Context_initMultiThread(CTX ctx);
knh_Context_t* knh_toContext(CTX ctx);
void knh_Context_free(CTX ctx, knh_context_t* ctxo);
void knh_beginContext(CTX ctx, void **bottom);
void knh_endContext(CTX ctx);
konoha_t konoha_open(void);
knh_Object_t **knh_reftraceRoot(CTX ctx FTRARG);
void konoha_close(konoha_t konoha);
const char* knh_sfile(const char *file);
void knh_write_now(CTX ctx, knh_OutputStream_t *w);
void knh_fsyslog(FILE *fp, const char *group, const char *msg);
void knh_logprintf(const char *group, int verbose, const char *fmt, ...);
void knh_closelog(void);
int knh_isVerboseLang(void);
void opt_verbose_lang(int mode, const char *optstr);
int knh_isVerboseGC(void);
int knh_isVerbosePref(void);
void loadPolicy(CTX ctx);
void knh_enforceSecurity(CTX ctx, knh_Method_t *mtd);
void knh_PleaseLetUsKnowYourOS(CTX ctx, const char *msg, const char *file, int line);
knh_bool_t knh_VirtualMachine_launch(CTX ctx, knh_sfp_t *sfp);
void konoha_ginit(int argc, const char **argv);
void dbg_p(const char *file, const char *func, int line, const char *fmt, ...);
void todo_p(const char *file, const char *func, int line, const char *fmt, ...);
void knh_write_uline(CTX ctx, knh_OutputStream_t *w, knh_uline_t uline);
void knh_write_mline(CTX ctx, knh_OutputStream_t *w, knh_methodn_t mn, knh_uline_t uline);
void knh_write_sfp(CTX ctx, knh_OutputStream_t *w, knh_type_t type, knh_sfp_t *sfp, int level);
void knh_throw(CTX ctx, knh_sfp_t *sfp, long start);
void knh_assert(CTX ctx, knh_sfp_t *sfp, long start, knh_uline_t uline);
knh_bool_t knh_isTrace(CTX ctx, const char *event);
void knh_ntrace(CTX ctx, const char *event, int pe, knh_ldata_t *ldata);
void knh_dtrace(CTX ctx, const char *event, int pe, knh_DictMap_t *data);
void THROW_Halt(CTX ctx, knh_sfp_t *sfp, const char *msg);
void THROW_OutOfMemory(CTX ctx, size_t size);
void THROW_StackOverflow(CTX ctx, knh_sfp_t *sfp);
void THROW_Arithmetic(CTX ctx, knh_sfp_t *sfp, const char *msg);
void THROW_TypeError(CTX ctx, knh_sfp_t *sfp, knh_type_t reqt, knh_type_t type);
void THROW_NoSuchMethod(CTX ctx, knh_sfp_t *sfp, knh_class_t cid, knh_methodn_t mn);
void THROW_ParamTypeError(CTX ctx, knh_sfp_t *sfp, size_t n, knh_methodn_t mn, knh_class_t reqt, knh_class_t cid);
const knh_LoaderAPI_t* knh_getLoaderAPI(void);
void knh_initBuiltInPackage(CTX ctx, const knh_LoaderAPI_t *kapi);
void knh_loadSystemDriver(CTX ctx, knh_NameSpace_t *ns);
knh_PtrMap_t* new_PtrMap(CTX ctx, size_t max);
void* knh_PtrMap_get(CTX ctx, knh_PtrMap_t *pm, void *keyptr);
void knh_PtrMap_add(CTX ctx, knh_PtrMap_t *pm, void *keyptr, void *valueptr);
void knh_PtrMap_rm(CTX ctx, knh_PtrMap_t *pm, void *keyptr);
size_t knh_PtrMap_size(knh_PtrMap_t *pm);
void knh_PtrMap_stat(CTX ctx, knh_PtrMap_t *pm, const char *name);
knh_String_t* knh_PtrMap_getS(CTX ctx, knh_PtrMap_t *pm, const char *k, size_t len);
void knh_PtrMap_addS(CTX ctx, knh_PtrMap_t *pm, knh_String_t *v);
void knh_PtrMap_rmS(CTX ctx, knh_PtrMap_t *pm, knh_String_t *s);
knh_Int_t* knh_PtrMap_getI(CTX ctx, knh_PtrMap_t *pm, knh_ndata_t k);
void knh_PtrMap_addI(CTX ctx, knh_PtrMap_t *pm, knh_Int_t *v);
void knh_PtrMap_rmI(CTX ctx, knh_PtrMap_t *pm, knh_Int_t *v);
knh_Method_t* knh_PtrMap_getM(CTX ctx, knh_PtrMap_t *pm, knh_hashcode_t hcode);
void knh_PtrMap_addM(CTX ctx, knh_PtrMap_t *pm, knh_hashcode_t hcode, knh_Method_t *v);
void knh_PtrMap_rmM(CTX ctx, knh_PtrMap_t *pm, knh_Method_t *mtd);
int knh_bytes_strcasecmp2(knh_bytes_t t1, knh_bytes_t t2);
knh_DictMap_t* new_DictMap0_(CTX ctx, size_t capacity, int isCaseMap, const char *DBGNAME);
knh_DictMap_t* knh_toDictMap(CTX ctx, knh_Map_t *m, int isCreation);
knh_DictSet_t* new_DictSet0_(CTX ctx, size_t capacity, int isCaseMap, const char *DBGNAME);
knh_uintptr_t knh_DictSet_valueAt(knh_DictSet_t *m, size_t n);
knh_index_t knh_DictMap_index(knh_DictMap_t *m, knh_bytes_t key);
Object *knh_DictMap_getNULL(CTX ctx, knh_DictMap_t *m, knh_bytes_t key);
knh_uintptr_t knh_DictSet_get(CTX ctx, knh_DictSet_t *m, knh_bytes_t key);
void knh_DictMap_set_(CTX ctx, knh_DictMap_t *m, knh_String_t *key, dynamic *v);
void knh_DictSet_set(CTX ctx, knh_DictSet_t *m, knh_String_t *key, knh_uintptr_t n);
void knh_DictMap_append(CTX ctx, knh_DictMap_t *m, knh_String_t *key, knh_Object_t *v);
void knh_DictSet_append(CTX ctx, knh_DictSet_t *m, knh_String_t *key, knh_uintptr_t n);
void knh_DictSet_sort(CTX ctx, knh_DictSet_t *m);
void knh_loadScriptDefaultMapDSPI(CTX ctx, knh_NameSpace_t *ns);
const knh_MapDPI_t *knh_getDefaultMapDSPI(CTX ctx, knh_class_t p1, knh_class_t p2);
const knh_MapDPI_t *knh_getDictMapDSPI(CTX ctx, knh_class_t p1, knh_class_t p2);
void *knh_malloc(CTX ctx, size_t size);
void knh_free(CTX ctx, void *block, size_t size);
void *knh_valloc(CTX ctx, size_t size);
void knh_vfree(CTX ctx, void *block, size_t size);
void *TRACE_malloc(CTX ctx, size_t size K_TRACEARGV);
void TRACE_free(CTX ctx, void *p, size_t size K_TRACEARGV);
void *TRACE_realloc(CTX ctx, void *p, size_t os, size_t ns, size_t wsize K_TRACEARGV);
void *knh_xmalloc(CTX ctx, size_t size);
void xmem_freeall(CTX ctx);
void *knh_fastmalloc(CTX ctx, size_t size);
void knh_fastfree(CTX ctx, void *block, size_t size);
void* knh_fastrealloc(CTX ctx, void *block, size_t os, size_t ns, size_t wsize);
void knh_share_initArena(CTX ctx, knh_share_t *share);
void knh_share_freeArena(CTX ctx, knh_share_t *share);
knh_bool_t knh_isObject(CTX ctx, knh_Object_t *o);
void knh_initFirstObjectArena(CTX ctx);
knh_Object_t *new_hObject_(CTX ctx, const knh_ClassTBL_t *ct);
knh_Object_t *new_Object_init2(CTX ctx, const knh_ClassTBL_t *ct);
void TR_NEW(CTX ctx, knh_sfp_t *sfp, knh_sfpidx_t c, const knh_ClassTBL_t *ct);
knh_Object_t** knh_ensurerefs(CTX ctx, knh_Object_t** tail, size_t size);
void knh_Object_RCfree(CTX ctx, Object *o);
void knh_Object_RCsweep(CTX ctx, Object *o);
void knh_ObjectArena_finalfree(CTX ctx, knh_ObjectArenaTBL_t *oat, size_t oatSize);
void knh_System_gc(CTX ctx, int needsCStackTrace);
void knh_srand(knh_uint_t seed);
knh_uint_t knh_rand(void);
knh_float_t knh_float_rand(void);
knh_Int_t* new_Int_(CTX ctx, knh_class_t cid, knh_int_t value);
knh_Float_t* new_Float_(CTX ctx, knh_class_t cid, knh_float_t value);
Object* new_Boxing(CTX ctx, knh_sfp_t *sfp, const knh_ClassTBL_t *ct);
KMETHOD Bytes_getSize(CTX ctx, knh_sfp_t *sfp _RIX);
KMETHOD Tuple_getSize(CTX ctx, knh_sfp_t *sfp _RIX);
KMETHOD Map_getSize(CTX ctx, knh_sfp_t *sfp _RIX);
void knh_DataMap_log(CTX ctx, knh_DictMap_t *conf, knh_type_t type, const char *key);
knh_bool_t knh_DataMap_check(CTX ctx, knh_DictMap_t *conf, knh_type_t type, const char *key, const char *key2);
knh_String_t *knh_DataMap_getString(CTX ctx, knh_DictMap_t *conf, const char *key, const char *key2, knh_String_t *def);
knh_String_t *knh_View_getQuery(CTX ctx, knh_View_t *view);
const knh_sysinfo_t* knh_getsysinfo(void);
void dump_sysinfo(CTX ctx, knh_OutputStream_t *w, int isALL);
knh_String_t *knh_buff_newRealPathString(CTX ctx, knh_Bytes_t *ba, size_t pos);
knh_Path_t* new_CurrentPath(CTX ctx);
knh_bool_t knh_exists(CTX ctx, const char *fname);
knh_bool_t knh_isfile(CTX ctx, const char *phname);
knh_bool_t knh_buff_isfile(CTX ctx, knh_Bytes_t *ba, size_t pos);
knh_bool_t knh_isdir(CTX ctx, const char *pname);
knh_bool_t knh_buff_isdir(CTX ctx, knh_Bytes_t *ba, size_t pos);
knh_bool_t knh_buff_mkdir(CTX ctx, knh_Bytes_t *ba, size_t pos);
void knh_System_initPath(CTX ctx);
void *knh_dlopen(CTX ctx, const char* path);
void *knh_dlsym(CTX ctx, void* handler, const char* symbol, const char *another, int isTest);
int knh_dlclose(CTX ctx, void* handler);
const char *knh_dlerror();
const char *knh_getSystemEncoding(void);
void knh_loadSystemQueryDriver(CTX ctx, knh_NameSpace_t *ns);
knh_bool_t knh_isCompileOnly(CTX ctx);
void knh_loadScriptPackageList(CTX ctx, const char *pkglist);
void knh_setSecurityAlertMessage(const char *msg, int isNeedFree);
int konoha_main(konoha_t konoha, int argc, const char **argv);
void knh_askSecurityAlert(CTX ctx);
void knh_checkSecurityManager(CTX ctx, knh_sfp_t *sfp);
knh_Int_t* new_Int_X(CTX ctx, knh_class_t cid, knh_int_t value);
knh_Float_t* new_Float_X(CTX ctx, knh_class_t cid, knh_float_t value);
void knh_write_intx(CTX ctx, knh_OutputStream_t *w, knh_Semantics_t *u, knh_int_t v);
void knh_write_floatx(CTX ctx, knh_OutputStream_t *w, knh_Semantics_t *u, knh_float_t v);
void knh_Semantics_reuse(CTX ctx, knh_Semantics_t *u, knh_class_t cid);
knh_Semantics_t* new_Enum(CTX ctx, char *tag, knh_bytes_t urn, knh_int_t min, knh_int_t max);
knh_Semantics_t* new_Unit(CTX ctx, char *tag, knh_bytes_t urn, knh_float_t min, knh_float_t max, knh_float_t step);
knh_Semantics_t* new_Vocab(CTX ctx, char *tag, knh_bytes_t urn, int base, char **terms);
knh_bytes_t knh_getURNAlias(CTX ctx, knh_bytes_t aurn);
void knh_loadScriptURNAliasData(CTX ctx, knh_StringData_t *data);
void knh_loadScriptSemanticsFuncData(CTX ctx, knh_FuncData_t *data);
knh_Semantics_t *knh_getSemantics(CTX ctx, knh_class_t cid);
knh_class_t knh_findcidx(CTX ctx, knh_bytes_t lname);
knh_sfp_t* knh_stack_initexpand(CTX ctx, knh_sfp_t *sfp, size_t n);
void knh_stack_clear(CTX ctx, knh_sfp_t *sfp);
knh_sfp_t* knh_stack_local(CTX ctx, size_t n);
void knh_checkSafePoint(CTX ctx, knh_sfp_t *sfp, const char *file, int line);
int event_isa(CTX ctx, knh_event_t eid, knh_event_t parent);
knh_String_t *knh_getEventName(CTX ctx, knh_event_t eid);
knh_event_t knh_addEvent(CTX ctx, knh_flag_t flag, knh_String_t *name, knh_class_t peid);
knh_bool_t knh_isDefinedEvent(CTX ctx, knh_bytes_t t);
knh_event_t knh_geteid(CTX ctx, knh_bytes_t t);
knh_Exception_t* new_Error(CTX ctx, knh_uline_t uline, knh_String_t *emsg);
void CTX_setThrowingException(CTX ctx, knh_Exception_t *e);
knh_bool_t isCATCH(CTX ctx, knh_rbp_t *rbp, int en, knh_event_t peid);
void Context_push(CTX ctx, knh_Object_t *o);
knh_Object_t *Context_pop(CTX ctx);
knh_ExceptionHandler_t* ExceptionHandler_setjmp(CTX ctx, knh_ExceptionHandler_t *hdr);
knh_ExceptionHandler_t *knh_ExceptionHandler_longjmp(CTX ctx, knh_ExceptionHandler_t *hdr);
void knh_buff_addpath(CTX ctx, knh_Bytes_t *ba, size_t pos, int needsSEP, knh_bytes_t t);
void knh_buff_addospath(CTX ctx, knh_Bytes_t *ba, size_t pos, int needsSEP, knh_bytes_t t);
void knh_buff_trim(CTX ctx, knh_Bytes_t *ba, size_t pos, int ch);
knh_Path_t *new_ScriptPath(CTX ctx, knh_String_t *urn, knh_NameSpace_t *ns);
knh_Array_t *knh_PathDir_toArray(CTX ctx, knh_Path_t *path);
knh_io2_t* new_FILE(CTX ctx, FILE *fp, size_t bufsiz);
knh_io2_t* new_io2(CTX ctx, int fd, size_t bufsiz);
knh_io2_t* new_io2ReadBuffer(CTX ctx, const char *buf, size_t bufsiz);
knh_io2_t* new_io2WriteBuffer(CTX ctx, knh_Bytes_t *ba);
knh_io2_t *io2_null(void);
void io2_free(CTX ctx, knh_io2_t *io2);
void io2_close(CTX ctx, knh_io2_t *io2);
knh_bool_t io2_isClosed(CTX ctx, knh_io2_t *io2);
int io2_getc(CTX ctx, knh_io2_t *io2);
size_t io2_read(CTX ctx, knh_io2_t *io2, char *buf, size_t bufsiz);
knh_String_t* io2_readLine(CTX ctx, knh_io2_t *io2, knh_StringDecoder_t *dec);
void io2_readAll(CTX ctx, knh_io2_t *io2, knh_Bytes_t *ba);
void io2_flush(CTX ctx, knh_io2_t *io2);
size_t io2_write(CTX ctx, knh_io2_t *io2, const char *buf, size_t bufsiz);
size_t io2_writeMultiByteChar(CTX ctx, knh_io2_t *io2, const char *buf, size_t bufsiz, knh_StringEncoder_t *enc);
knh_bool_t NOFILE_exists(CTX ctx, knh_Path_t *path);
void NOFILE_ospath(CTX ctx, knh_Path_t *path, knh_NameSpace_t *ns);
knh_io2_t* NOFILE_openNULL(CTX ctx, knh_Path_t *path, const char *mode, knh_DictMap_t *conf);
const knh_PathDPI_t *knh_getDefaultPathStreamDPI(void);
knh_InputStream_t* new_BytesInputStream(CTX ctx, const char *buf, size_t bufsiz);
void knh_InputStream_setCharset(CTX ctx, knh_InputStream_t *in, knh_StringDecoder_t *c);
void knh_OutputStream_setCharset(CTX ctx, knh_OutputStream_t *w, knh_StringEncoder_t *c);
void knh_write_bool(CTX ctx, knh_OutputStream_t *w, int b);
void knh_write_ptr(CTX ctx, knh_OutputStream_t *w, void *ptr);
void knh_write_dfmt(CTX ctx, knh_OutputStream_t *w, const char *fmt, knh_intptr_t n);
void knh_write_ifmt(CTX ctx, knh_OutputStream_t *w, const char *fmt, knh_int_t n);
void knh_write_ffmt(CTX ctx, knh_OutputStream_t *w, const char *fmt, knh_float_t n);
void knh_write_flag(CTX ctx, knh_OutputStream_t *w, knh_flag_t flag);
void knh_write_quote(CTX ctx, knh_OutputStream_t *w, int quote, knh_bytes_t t, int hasUTF8);
void knh_write_cap(CTX ctx, knh_OutputStream_t *w, knh_bytes_t t, int hasUTF8);
void knh_write_Object(CTX ctx, knh_OutputStream_t *w, Object *o, int level);
void knh_write_InObject(CTX ctx, knh_OutputStream_t *w, Object *o, int level);
void knh_vprintf(CTX ctx, knh_OutputStream_t *w, const char *fmt, va_list ap);
void knh_initStreamFuncData(CTX ctx, const knh_LoaderAPI_t *kapi);
int knh_bytes_parseint(knh_bytes_t t, knh_int_t *value);
int knh_bytes_parsefloat(knh_bytes_t t, knh_float_t *value);
int knh_bytes_strcmp(knh_bytes_t v1, knh_bytes_t v2);
int knh_utf8len(int c);
knh_bool_t knh_bytes_checkENCODING(knh_bytes_t v);
size_t knh_bytes_mlen(knh_bytes_t v);
knh_bytes_t knh_bytes_mofflen(knh_bytes_t v, size_t moff, size_t mlen);
knh_int_t knh_uchar_toucs4(knh_utext_t *utf8)   /* utf8 -> ucs4 */;
char *knh_format_utf8(char *buf, size_t bufsiz, knh_uint_t ucs4);
knh_String_t* new_String2(CTX ctx, knh_class_t cid, const char *text, size_t len, int policy);
knh_StringDecoder_t* new_StringDecoderNULL(CTX ctx, knh_bytes_t t);
knh_StringEncoder_t* new_StringEncoderNULL(CTX ctx, knh_bytes_t t);
knh_String_t *CWB_newStringDECODE(CTX ctx, CWB_t *cwb, knh_StringDecoder_t *c);
int knh_bytes_strcasecmp(knh_bytes_t v1, knh_bytes_t v2);
const knh_RegexSPI_t* knh_getStrRegexSPI(void);
knh_bool_t Regex_isSTRREGEX(knh_Regex_t *re);
const knh_RegexSPI_t* knh_getRegexSPI(void);
void knh_linkDynamicRegex(CTX ctx);
knh_bool_t knh_class_canObjectCopy(CTX ctx, knh_class_t cid);
const knh_ClassDef_t* knh_getDefaultClassDef(void);
void knh_ClassTBL_setConstPool(CTX ctx, const knh_ClassTBL_t *ct);
void knh_ClassTBL_setObjectCSPI(CTX ctx, knh_ClassTBL_t *ct);
const knh_ClassDef_t* knh_getCppClassDef(void);
knh_Thunk_t* new_Thunk(CTX ctx, knh_class_t p1, size_t envsize);
void knh_loadScriptSystemStructData(CTX ctx, const knh_LoaderAPI_t *kapi);
void knh_loadScriptSystemString(CTX ctx);
void knh_loadScriptSystemData(CTX ctx, knh_NameSpace_t *ns, const knh_LoaderAPI_t *kapi);
void knh_loadScriptSystemMethod(CTX ctx, const knh_LoaderAPI_t *kapi);
knh_String_t* knh_getPropertyNULL(CTX ctx, knh_bytes_t key);
void knh_setProperty(CTX ctx, knh_String_t *key, dynamic *value);
Object *knh_getClassConstNULL(CTX ctx, knh_class_t cid, knh_bytes_t name);
int knh_addClassConst(CTX ctx, knh_class_t cid, knh_String_t* name, Object *value);
ksymbol_t knh_addname(CTX ctx, knh_String_t *s, knh_Fdictset f);
ksymbol_t knh_getfnq(CTX ctx, knh_bytes_t tname, ksymbol_t def);
knh_methodn_t knh_getmn(CTX ctx, knh_bytes_t tname, knh_methodn_t def);
const char* knh_getmnname(CTX ctx, knh_methodn_t mn);
knh_uri_t knh_getURI(CTX ctx, knh_bytes_t t);
knh_String_t *knh_getURN(CTX ctx, knh_uri_t uri);
const knh_PathDPI_t *knh_NameSpace_getStreamDPINULL(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path);
const knh_MapDPI_t *knh_NameSpace_getMapDPINULL(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path);
const knh_ConverterDPI_t *knh_NameSpace_getConverterDPINULL(CTX ctx, knh_NameSpace_t *ns, knh_bytes_t path);
void knh_exit(CTX ctx, int status);
knh_thread_t knh_thread_self(void);
int knh_thread_create(CTX ctx, knh_thread_t *thread, void *attr, knh_Fthread fgo, void * arg);
int knh_thread_detach(CTX ctx, knh_thread_t th);
int knh_thread_join(CTX ctx, knh_thread_t thread, void **ret);
int knh_mutex_init(knh_mutex_t *m);
int knh_mutex_lock(knh_mutex_t *m);
int knh_mutex_trylock(knh_mutex_t *m);
int knh_mutex_unlock(knh_mutex_t *m);
int knh_mutex_destroy(knh_mutex_t *m);
knh_mutex_t *knh_mutex_malloc(CTX ctx);
void knh_mutex_free(CTX ctx, knh_mutex_t *m);
knh_cond_t *knh_thread_cond_init(CTX ctx);
int knh_thread_cond_wait(knh_cond_t *cond, knh_mutex_t *m);
int knh_thread_cond_signal(knh_cond_t *cond);
int knh_thread_cond_broadcast(knh_cond_t *cond);
knh_cond_t *knh_thread_cond_init(CTX ctx);
int knh_thread_cond_wait(knh_cond_t *cond, knh_mutex_t *m);
int knh_thread_cond_signal(knh_cond_t *cond);
int knh_thread_cond_broadcast(knh_cond_t *cond);
int knh_thread_key_create(knh_thread_key_t *key);
int thread_setspecific(knh_thread_key_t key, const void *data);
void* knh_thread_getspecific(knh_thread_key_t key);
int knh_thread_key_delete(knh_thread_key_t key);
knh_Array_t* new_TokenArray(CTX ctx, const char *text, knh_uline_t uline);
void knh_initSugarFuncData(CTX ctx, const knh_LoaderAPI_t *kapi);
void knh_initSugarData(CTX ctx, const knh_LoaderAPI_t *kapi);

#ifdef __cplusplus
}
#endif

// THIS FILE WAS AUTOMATICALLY GENERATED. DON'T EDIT.

