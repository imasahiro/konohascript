/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2006-2011, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
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

#ifndef CLASS_KONOHA_H_
#define CLASS_KONOHA_H_

#include"konoha_t.h"
#include"konoha_name.h"

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* Type Variable */
//## @TypeVariable class Tvoid Tvoid;
//## @TypeVariable class Tvar  Tvoid;

#define TYPE_void                 CLASS_Tvoid
#define TYPE_var                  CLASS_Tvar

/* ------------------------------------------------------------------------ */
//## class Object Object knh_ObjectField_t;
//## flag Object Ref           0 (%s)->h.magicflag has set * *;
//## flag Object NullObject    1 (%s)->h.magicflag is set  * *;
//## flag Object XData         2 (%s)->h.magicflag is set  * *;
//## flag Object Modified      3 (%s)->h.magicflag is set  * *;
//## flag Object Local1       12 (%s)->h.magicflag is set  * *;
//## flag Object Local2       13 (%s)->h.magicflag is set  * *;
//## flag Object Local3       14 (%s)->h.magicflag is set  * *;
//## flag Object Local4       15 (%s)->h.magicflag is set  * *;

#ifndef K_FIELDSIZE
#define K_FIELDSIZE 64
#endif

#define K_FASTMALLOC_SIZE  (sizeof(void*) * 8)
#define	K_SMALLOBJECT_FIELDSIZE 3

typedef struct kObject kObject;
#if defined(K_INTERNAL) || defined(USE_STRUCT_ObjectField) || defined(USE_STRUCT_Tuple)
struct kObject {
	kObjectHeader h;
	union {
		Object   **fields;
		kint_t    *ifields;
		kfloat_t  *ffields;
	};
	Object        *smallobject;  // small object
};
#endif

#define IS_NULL(o)        ((((o)->h.magicflag) & FLAG_Object_NullObject) == FLAG_Object_NullObject)
#define IS_NOTNULL(o)     ((((o)->h.magicflag) & FLAG_Object_NullObject) != FLAG_Object_NullObject)

#define CLASS_ObjectField   CLASS_Object
#define O_cid(o)            (((o)->h.cTBL)->cid)
#define O_bcid(o)           (((o)->h.cTBL)->bcid)
#define O_cTBL(o)           ((o)->h.cTBL)
#define O_p1(o)             (((o)->h.cTBL)->p1)
#define O_p2(o)             (((o)->h.cTBL)->p2)
#define IS_ObjectField(o)   (((o)->h.cTBL)->bcid == CLASS_Object)

#define new_H(C)            (k##C*)new_hObject_(ctx, ClassTBL(CLASS_##C))
#define new_hObject(ctx, cid)          new_hObject_(ctx, ClassTBL(cid))
#define new_(C)             (k##C*)new_Object_init2(ctx, ClassTBL(CLASS_##C))
#define new_O(C,cid)        (k##C*)new_Object_init2(ctx, ClassTBL(cid))

/* ------------------------------------------------------------------------ */
//## @Immutable class Boolean Object;

typedef union knbody_t knbody_t;
union knbody_t {
	kunbox_t   data;
	kbool_t    bvalue;
	kint_t     ivalue;
	kfloat_t   fvalue;
};

typedef struct kBoolean kBoolean;
#ifdef USE_STRUCT_Boolean
struct kBoolean {
	kObjectHeader h;
	knbody_t n;
};
#endif

#define IS_TRUE(o)         (O_bcid(o) == CLASS_Boolean && N_tobool(o))
#define IS_FALSE(o)        (O_bcid(o) == CLASS_Boolean && N_tobool(o) == 0)
#define new_Boolean(ctx, c)    ((c) ? KNH_TRUE : KNH_FALSE)
#define O_ndata(o)        (((kNumber*)o)->n.data)

/* ------------------------------------------------------------------------ */
//## @Immutable class Number Object;

typedef struct kNumber kNumber;
#ifdef USE_STRUCT_Number
struct kNumber {
	kObjectHeader h;
	knbody_t n;
};
#endif

#define N_toint(o)         (((kNumber*)o)->n.ivalue)
#define N_tofloat(o)       (((kNumber*)o)->n.fvalue)
#define N_tobool(o)        (((kNumber*)o)->n.bvalue)

/* ------------------------------------------------------------------------ */
//## @Immutable class Int Number;

typedef struct kInt kInt;
#ifdef USE_STRUCT_Int
struct kInt {
	kObjectHeader h;
	knbody_t n;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Immutable class Float Number;

typedef struct kFloat kFloat;
#ifdef USE_STRUCT_Float
struct kFloat {
	kObjectHeader h;
	knbody_t n;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Immutable class Date Object;

typedef struct kdate_t {
	kshort_t year; kshort_t month;
	kshort_t day;  kshort_t hour;
	kshort_t min;  kshort_t sec;
	kshort_t gmtoff; kshort_t isdst; /* summer time */
} kdate_t ;

typedef struct kDate kDate;
#ifdef USE_STRUCT_Date
struct kDate {
	kObjectHeader h;
	kdate_t dt;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Immutable class String Object;
//## flag String TextSgm 1 - is set  *   *;
//## flag String ASCII   2 - is set  is  *;
//## flag String Pooled  3 - is set  is  *;

#define SPOL_TEXT          (1<<0)
#define SPOL_ASCII         (1<<1)
#define SPOL_UTF8          (1<<2)
#define SPOL_POOLNEVER     (1<<3)
#define SPOL_POOLALWAYS    (1<<4)

typedef struct kString kString;
struct kString {
	kObjectHeader h;
	kbytes_t str;
	khashcode_t hashCode;
};

#define new_T(t)            new_String2(ctx, CLASS_String, t, knh_strlen(t), SPOL_TEXT|SPOL_ASCII|SPOL_POOLALWAYS)
#define new_S(T, L)         new_String2(ctx, CLASS_String, T, L, SPOL_ASCII|SPOL_POOLALWAYS)
#define new_String_()

#define S_tobytep(s)          (&(s)->str)
#define S_tobytes(s)          ((s)->str)
#define S_totext(s)           ((s)->str.text)
#define S_size(s)             ((s)->str.len)
#define S_equals(s, b)        knh_bytes_equals(S_tobytes(s), b)
#define S_startsWith(s, b)    knh_bytes_startsWith_(S_tobytes(s), b)
#define S_endsWith(s, b)      knh_bytes_endsWith_(S_tobytes(s), b)

/* ------------------------------------------------------------------------ */
//## class Bytes Object;

typedef struct {
	size_t capacity;
	size_t wsize;
	size_t sorted;
	size_t dim;
	size_t x;
	size_t xy;
	size_t xyz;
} kdim_t ;

typedef struct kBytes kBytes;
struct kBytes {
	kObjectHeader h;
	kbytes_t   bu;
	const kdim_t    *dim;
	const char *DBG_name;
};

#define KNH_SIZE(v)     v
#define k_grow(N)       ((N)*2)

#define BA_tobytes(o)   (o)->bu
#define BA_size(o)      (o)->bu.len
#define BA_totext(o)    (o)->bu.text

#define B_equals(b, t)        (knh_bytes_strcmp(b, STEXT(t)) == 0)
#define B_startsWith(b, t)    knh_bytes_startsWith_(b, STEXT(t))
#define B_endsWith(b, t)      knh_bytes_endsWith_(b, STEXT(t))

/* ------------------------------------------------------------------------ */
//## class Pointer Object;

typedef struct kPointer kPointer;
#ifdef USE_STRUCT_Pointer
struct kPointer {
	kObjectHeader h;
	union {
		void *ptr;
		unsigned char *uptr;
	};
	size_t size;
	size_t wsize;
	struct kObject *gcref;
};
#endif

/* ------------------------------------------------------------------------ */
//## class Iterator Object;
//## flag Iterator NDATA     1 - is set * *;
//## type IteratorVar     Iterator 0 Tvar;
//## type DataITR         Iterator 0 Map;
//## type FuncEach        Func  1 T1 T1;
//## type FuncWhere       Func  1 T1 Boolean;

typedef struct knitr_t {
	void   *nptr;
	void   (*nfree)(void *nptr);
	union {
		size_t  index;
		void *qconn;
	};
	union {
		size_t  max;
		void *qstmt;
	};
} knitr_t;

#define K_NITR_INIT   {NULL, NULL, {0L}, {0L}}
#define ITR(sfp)   sfp[0].it

typedef void (*knh_Ffree)(void *nptr);

typedef struct kIterator kIterator;

#ifdef USE_STRUCT_Iterator
typedef struct {
	Object    *source;
	union {
		struct kMethod  *mtdNULL;
		struct kFunc    *funcNULL;
		struct kTypeMap *tmrNULL;
	};
	struct     knitr_t m;
} knh_IteratorEX_t;

struct kIterator {
	kObjectHeader h;
	knh_IteratorEX_t KNH_EX_REF b;
	knh_Fitrnext fnext_1;
};
#endif

/* ------------------------------------------------------------------------ */
//## class Tuple Object;

typedef kObject kTuple;

/* ------------------------------------------------------------------------ */
//## @Immutable class Range Object;
//## flag Range NDATA     1 - is set * *;
//## flag Range Inclusive 2 - is set * *;
//## type RangeInt  Range 0 Int;

typedef struct kRange kRange;
#ifdef USE_STRUCT_Range
struct kRange {
	kObjectHeader h;
	union {
		kObject  *ostart;
		kunbox_t  nstart;
	};
	union {
		kObject  *oend;
		kunbox_t  nend;
	};
};
#endif

/* ------------------------------------------------------------------------ */
//## class Array   Object;
//## flag  Array   NDATA     1 - is set * *;
//## type ArrayInt  Array 0 Int;
//## type CmprT1    Func  1 T1 T1 Int;

typedef struct {
	size_t   (*index)(CTX ctx, ksfp_t *sfp, kint_t n, size_t size);
	void     (*fastget)(CTX ctx, ksfp_t *sfp, size_t n _RIX);
	void     (*get)(CTX ctx, struct kArray *, size_t n, ksfp_t *sfp);
	void     (*set)(CTX ctx, struct kArray *, size_t n, ksfp_t *sfp);
	void     (*add)(CTX ctx, struct kArray *, ksfp_t *sfp);
	void     (*multiadd)(CTX ctx, struct kArray *, ksfp_t *sfp);
} knh_ArrayAPI_t;

typedef struct kArray kArray;

struct kArray {
	kObjectHeader h;
	union {
		kunbox_t                 *nlist;
		kint_t                   *ilist;
		kfloat_t                 *flist;
		struct kObject        **list;
		struct kRawPtr        **ptrs;
		struct kString        **strings;
		struct kInt           **ints;
		struct kMethod        **methods;
		struct kTypeMap       **trans;
		struct kToken         **tokens;
		struct kExpr          **exprs;
		struct kTerm          **terms;
		struct kStmtExpr      **stmts;
	};
	size_t size;
	const kdim_t *dim;
	const knh_ArrayAPI_t *api;
};

#define knh_Array_n(a,n)      (a)->list[(n)]
#define knh_Array_size(a)     (a)->size
#define kArrayrimSize(ctx, a, newsize)  knh_Array_clear(ctx, a, newsize)
#define knh_Array_add(ctx, a, o)    knh_Array_add_(ctx, a, UPCAST(o))
#define knh_Array_remove(ctx, a, n)    knh_Array_remove_(ctx, a, n)
//#define knh_TOKENs_n(a, n)    ((kTerm*)(a)->list[(n)])

///* ------------------------------------------------------------------------ */
//## class Map Object;

typedef void  kmapptr_t;

typedef struct knh_MapDPI_t {
	int   type;
	const char *name;
	const struct knh_MapDPI_t* (*config)(CTX, kclass_t, kclass_t);
	kmapptr_t* (*init)(CTX, size_t, const char*, struct kDictMap *);
	void (*reftrace)(CTX, kmapptr_t* FTRARG);
	void (*freemap)(CTX, kmapptr_t*);
	// main
	kbool_t (*get)(CTX, kmapptr_t*, ksfp_t*, ksfp_t *);
	void (*set)(CTX, kmapptr_t*, ksfp_t *);
	void (*remove)(CTX, kmapptr_t*, ksfp_t *);
	size_t (*size)(CTX, kmapptr_t*);
	kbool_t (*next)(CTX, kmapptr_t*, knitr_t *, ksfp_t *);
} knh_MapDPI_t;

typedef struct kMap {
	kObjectHeader h;
	kmapptr_t  *mapptr;
	const struct knh_MapDPI_t *spi;
} kMap;

typedef struct kPtrMap {
	kObjectHeader h;
	kmapptr_t  *mapptr;
	const struct knh_MapDPI_t *spi;
} kPtrMap;

#define knh_Map_size(m)  (m)->spi->size(NULL, (m)->mapptr)

// DictMap, DictSet are old names of Map;

typedef struct kDictMap {
	kObjectHeader h;
	kmapptr_t     *mapptr;
	const struct knh_MapDPI_t *spi;
	kline_t uline;
} kDictMap;

#define new_DictMap0(ctx, N, F, NAME)      new_DictMap0_(ctx, N, F, NAME)
#define knh_DictMap_set(ctx, m, k, v)      knh_DictMap_set_(ctx, m, k, UPCAST(v))

typedef struct kDictSet {
	kObjectHeader h;
	kmapptr_t     *mapptr;
	const struct knh_MapDPI_t *spi;
} kDictSet;

typedef void (*knh_Fdictset)(CTX, kDictSet*, kString *k, kuintptr_t);
#define new_DictSet0(ctx, N, F, NAME)   new_DictSet0_(ctx, N, F, NAME)
#define knh_DictSet_keyAt(ds, n)    knh_DictMap_keyAt((kDictMap*)ds, n)
#define knh_DictSet_index(ds, key)  knh_DictMap_index((kDictMap*)ds, key)

/* ------------------------------------------------------------------------ */
//## @Immutable class Class Object;
//## flag Class Ref            0 (ClassTBL(%s))->cflag is * * *;
//## flag Class Expando        1 (ClassTBL(%s))->cflag is * * *;
//## flag Class Immutable      2 (ClassTBL(%s))->cflag is * * *;
//## flag Class Private!Public 4 (ClassTBL(%s))->cflag is * * *;
//## flag Class Final          5 (ClassTBL(%s))->cflag  is * * *;
//## flag Class Singleton      6 (ClassTBL(%s))->cflag  is * * *;
//## flag Class Unique         7 (ClassTBL(%s))->cflag  is * * *;
//## flag Class Interface      8 (ClassTBL(%s))->cflag  is * * *;
//## flag Class TypeVariable   9 (ClassTBL(%s))->cflag  is set * *;

#define FLAG_Field_Hidden          ((kflag_t)(1<<0))
#define FLAG_Field_Protected       ((kflag_t)(1<<1))
#define FLAG_Field_Getter          ((kflag_t)(1<<2))
#define FLAG_Field_Setter          ((kflag_t)(1<<3))
#define FLAG_Field_Key             ((kflag_t)(1<<4))
#define FLAG_Field_Volatile        ((kflag_t)(1<<5))
#define FLAG_Field_ReadOnly        ((kflag_t)(1<<6))
#define FLAG_Field_Property        ((kflag_t)(1<<7))

typedef struct kClass kClass;
struct kClass {
	kObjectHeader h;
	kclass_t   cid;
	ktype_t    type;
	const knh_ClassTBL_t *cTBL;
};

/* class */

#define KNH_NULVAL(cid)      knh_getClassDefaultValue(ctx, cid)
#define KNH_TNULL(T)         (k##T *)knh_getClassDefaultValue(ctx, CLASS_##T)
#define knh_Class_cid(c)     (kclass_t)(c)->cid
typedef void (*knh_Fwritecid)(CTX ctx, struct kOutputStream *w, kclass_t cid);

/* ------------------------------------------------------------------------ */
//## @Private @Immutable class Param Object;
//## flag Param VARGs  1 - is set * *;
//## flag Param RVAR   2 - is set * *;

typedef struct kparam_t {
	ktype_t    type;  ksymbol_t  fn;
} kparam_t;

typedef struct kParam kParam;
struct kParam {
	kObjectHeader h;
	kushort_t psize; kushort_t rsize;
	union {
		kparam_t* params;
		kparam_t  p0;
	};
	union {
		kparam_t p1;
		size_t capacity;
	};
	kparam_t p2;
};

#define new_Param(ctx)         new_(Param);
#define knh_param_hash(h, t, fn)    (fn + (((h * 31) + t) * 7))
#define knh_Param_rget(pa, n)  knh_Param_get(pa, (pa->psize) + n)

/* ------------------------------------------------------------------------ */
//## class Method Object;
//## flag Method Private!Public  0 DP(%s)->flag is set * *;
//## flag Method Virtual!Final   1 DP(%s)->flag is set * *;
//## flag Method Hidden          2 DP(%s)->flag is set * *;
//## flag Method Const           3 DP(%s)->flag is * * *;
//## flag Method Static          4 DP(%s)->flag is * * *;
//## flag Method Smart           5 DP(%s)->flag is set * *;
//## flag Method Dynamic         6 DP(%s)->flag is set * *;
//## flag Method Immutable       7 DP(%s)->flag is set * *;
//## flag Method Iterative       8 DP(%s)->flag is set * *;
//## flag Method Throwable       9 DP(%s)->flag is set * *;
//## flag Method Message        10 DP(%s)->flag is set * *;
//## flag Method Restricted     11 DP(%s)->flag is set * *;
//## flag Method FastCall       12 DP(%s)->flag is set * *;
//## flag Method Overload       13 DP(%s)->flag is set * *;

typedef struct kMethod kMethod;

typedef struct {
	kflag_t     flag;  kushort_t   delta;
	struct kParam*    mp;
	void*                       cfunc;
	union {
		kObject            *objdata;
		struct kKonohaCode *kcode;
		struct kScript     *gmascr;       // Dynamic
		struct kStmtExpr       *stmtB;        // stmt block
		struct kRawPtr     *rfunc;        // ffi
		struct kMethod     *proceed;      // during typing, asm
	};
	struct kArray *paramsNULL;
	union {
		struct kTerm *tsource;
		struct kToken *tcode;
	};
	kuri_t      uri;   kuri_t      domain;
	kuintptr_t  count;
} knh_MethodEX_t;

struct kMethod {
	kObjectHeader        h;
	knh_MethodEX_t KNH_EX_REF b;
	kclass_t          cid;   kmethodn_t  mn;
	knh_Fmethod          fcall_1;
	struct kopl_t *pc_start;
};

#define knh_Method_mf(mtd)    DP(mtd)->mp
#define knh_Param_psize(mf)    ((mf)->psize)
#define ClassTBL_getMethodNULL(ctx, c, mn)    knh_ClassTBL_findMethodNULL(ctx, c, mn, 0)
#define ClassTBL_getMethod(ctx, c, mn)        knh_ClassTBL_findMethodNULL(ctx, c, mn, 1)
#define knh_stack_argc(ctx, sfp)      (ctx->esp - (sfp))

/* ------------------------------------------------------------------------ */
//## class TypeMap Object;
//## flag TypeMap Interface  1 - is set * *;
//## flag TypeMap Semantic   2 - is set * *;
//## flag TypeMap Const      3 - is set * *;
//## flag TypeMap NDATA      4 - is set * *;

typedef struct kTypeMap kTypeMap;

struct kTypeMap {
	kObjectHeader h;
	kclass_t  scid; kclass_t  tcid;
	knh_Ftypemap ftypemap_1;
	union {
		Object* mapdata;
		struct kMethod  *mtd;
		struct kTypeMap *tmr1;
	};
	struct kTypeMap *tmr2;
};

typedef kTypeMap* (*knh_Ftypemaprule)(CTX ctx, const knh_ClassTBL_t *, const knh_ClassTBL_t *);

/* ------------------------------------------------------------------------ */
//## @Immutable class Func Object;

//## cparam Func 1 R dynamic P dynamic;
//## flag Func StoredEnv 1 - is set * *;

typedef struct kFunc kFunc;
#ifdef USE_STRUCT_Func
struct kFunc {
	kObjectHeader h;
	struct kMethod* mtd;
	Object* baseNULL;
	struct kString* name;
	void *cfunc;
};
#endif

/* ------------------------------------------------------------------------ */
//## class Thunk Object;
//## flag Thunk Evaluated 1 - is set * *;

typedef struct kThunk kThunk;
#ifdef K_INTERNAL
struct kThunk {
	kObjectHeader h;
	ksfp_t *envsfp;
	size_t     envsize;
};
#endif

///* ------------------------------------------------------------------------ */
////## class0 Thread Object;
//
//typedef struct knh_Thread_t {
//	kObjectHeader h;
//	kcontext_t *context;
//	kthread_t  th;
//} knh_Thread_t;

/* ------------------------------------------------------------------------ */
//## class Exception Object;

//## expt Exception!! -;
//## expt Assertion!! -;
//## expt Script!! -;
//## expt StackOverflow!! Script!!;
//## expt Security!! -;

typedef struct kException kException;
#ifdef USE_STRUCT_Exception
struct kException {
	kObjectHeader h;
	kString   *emsg;
	kline_t     uline;

	kArray*    tracesNULL;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Private class ExceptionHandler Object;
//## flag ExceptionHandler Catching   1 - is set * *;

typedef struct knh_ExceptionHandlerEX_t knh_ExceptionHandlerEX_t;
#ifdef K_USING_SETJMP_
#ifdef K_USING_POSIX_
typedef sigjmp_buf knh_jmpbuf_t;
#define knh_setjmp(buf)         sigsetjmp(buf, 1)
#define knh_longjmp(buf, val)   siglongjmp(buf, val)
#else
typedef jmp_buf knh_jmpbuf_t;
#define knh_setjmp(buf)         setjmp(buf)
#define knh_longjmp(buf, val)   longjmp(buf, val)
#endif

#ifdef K_INTERNAL
struct knh_ExceptionHandlerEX_t {
	knh_jmpbuf_t jmpbuf;
	struct kopl_t *pc;
	struct klr_TRY_t *op;
	kintptr_t sfpidx;
};
#endif

#else

#ifdef K_INTERNAL
struct knh_ExceptionHandlerEX_t {
	struct kopl_t *pc;
	struct klr_TRY_t *op;
	kintptr_t sfpidx;
	void *return_address;
	void *frame_address;
	kuintptr_t stack_pointer;
};
#endif

#endif/*K_USING_SETJMP_*/

typedef struct kExceptionHandler kExceptionHandler;
#ifdef K_INTERNAL
struct kExceptionHandler {
	kObjectHeader h;
	knh_ExceptionHandlerEX_t KNH_EX_REF b;
	kintptr_t espidx;
	struct kExceptionHandler *parentNC;
	struct kArray *stacklist;
};
#endif

#define KNH_NOAPI(ctx, cwb, isThrowable) { \
		knh_throw_Unsupported(ctx, cwb, __FUNCTION__, __FILE__, __LINE__, isThrowable); \
	}\

#define KNH_THROW_OUTOFINDEX(ctx, n, max) { \
		knh_throw_OutOfIndex(ctx, n, max, __FILE__, __LINE__); \
	}\

/* ------------------------------------------------------------------------ */
//## @Immutable class Regex Object;
//## flag Regex GlobalOption  1 - is set * *;

typedef void kregex_t;

/* REGEX_SPI */

#ifndef KREGEX_MATCHSIZE
#define KREGEX_MATCHSIZE    16
#endif

typedef struct {
	int rm_so;   /* start of match */
	int rm_eo;   /* end of match */
	kbytes_t rm_name;  /* {NULL, 0}, if not NAMED */
} kregmatch_t;

typedef struct knh_RegexSPI_t {
	const char *name;
	kregex_t* (*regmalloc)(CTX, kString *);
	int (*parse_cflags)(CTX, const char *opt);
	int (*parse_eflags)(CTX, const char *opt);
	int (*regcomp)(CTX, kregex_t *, const char *, int);
	int (*regnmatchsize)(CTX, kregex_t *);
	int (*regexec)(CTX, kregex_t *, const char *, size_t, kregmatch_t*, int);
	size_t (*regerror)(int, kregex_t *, char *, size_t);
	void (*regfree)(CTX, kregex_t *);
//	// this must be defined by uh for named grouping
//	int (*regexec2)(CTX, kregex_t *, const char *, ...);
} knh_RegexSPI_t;


typedef struct kRegex kRegex;
struct kRegex {
	kObjectHeader h;
	kregex_t *reg;
	int eflags;
	const struct knh_RegexSPI_t *spi;
	struct kString *pattern;
};

/* ------------------------------------------------------------------------ */
//## @Immutable class Converter Object;

typedef void knh_conv_t;

typedef struct knh_ConverterDPI_t {
	int  type;
	const char *name;
	knh_conv_t* (*open)(CTX, const char*, const char*);
	kbool_t  (*conv)(CTX,  knh_conv_t *, const char*, size_t, kBytes *);
	kbool_t  (*enc)(CTX,   knh_conv_t *, const char*, size_t, kBytes *);
	kbool_t  (*dec)(CTX,   knh_conv_t *, const char*, size_t, kBytes *);
	kbool_t  (*sconv)(CTX, knh_conv_t *, const char*, size_t, kBytes *);
	void (*close)(CTX ctx, knh_conv_t*);
	void (*setparam)(CTX ctx, knh_conv_t *, void *, void *);
} knh_ConverterDPI_t;

typedef struct kConverter kConverter;
#ifdef K_INTERNAL
struct kConverter {
	kObjectHeader h;
	knh_conv_t *conv;
	const struct knh_ConverterDPI_t *dpi;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Immutable class StringEncoder Converter;

typedef struct kStringEncoder kStringEncoder;
#ifdef K_INTERNAL
struct kStringEncoder {
	kObjectHeader h;
	knh_conv_t *conv;
	const struct knh_ConverterDPI_t *dpi;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Immutable class StringDecoder Converter;

typedef struct kStringDecoder kStringDecoder;
#ifdef K_INTERNAL
struct kStringDecoder {
	kObjectHeader h;
	knh_conv_t *conv;
	const struct knh_ConverterDPI_t *dpi;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Immutable class StringConverter Converter;

typedef struct kStringConverter kStringConverter;
#ifdef K_INTERNAL
struct kStringConverter {
	kObjectHeader h;
	knh_conv_t *conv;
	const struct knh_ConverterDPI_t *dpi;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Private class Semantics Object;

#define KNH_SEMANTICS_FMT    "%s{%s}"
struct  kSemantics;
typedef struct  kSemantics kSemantics;

typedef int (*knh_Fichk)(struct kSemantics *, kint_t v);
typedef int (*knh_Ficmp)(struct kSemantics *, kint_t v1, kint_t v2);

typedef int (*knh_Ffchk)(struct kSemantics *, kfloat_t v);
typedef int (*knh_Ffcmp)(struct kSemantics *, kfloat_t v1, kfloat_t v2);

typedef kString *(*knh_Fsnew)(CTX, kclass_t cid, kbytes_t, struct kString *, int *);
typedef int (*knh_Fscmp)(struct kSemantics *, kbytes_t, kbytes_t);

typedef struct kSemantics* (*knh_fspec)(CTX ctx, kbytes_t urn);

#ifdef K_INTERNAL
typedef struct knh_SemanticsEX_t knh_SemanticsEX_t;
struct knh_SemanticsEX_t {
	kflag_t  flag;
	kclass_t ucid;
	kclass_t ubcid;
	kString* urn;
	kString* tag;
	struct kInt    *ivalue;
	struct kFloat  *fvalue;
	struct kString *svalue;

	// int
	union {
		kint_t imin;
		kuint_t umin;
	};
	union {
		kint_t imax;
		kuint_t umax;
	};
	knh_Fichk fichk;
	knh_Ficmp ficmp;

	// float
	kfloat_t fmin;
	kfloat_t fmax;
	kfloat_t fstep;
	knh_Ffchk   ffchk;
	knh_Ffcmp   ffcmp;

	// String
	size_t bytelen;
	size_t charlen;
	Object* pattern;
//	struct knh_DictIdx_t* vocabDictIdx;
	struct kStringEncoder *bconv;
	knh_Fsnew    fsnew;
	knh_Fscmp    fscmp;
};

struct kSemantics {
	kObjectHeader h;
	knh_SemanticsEX_t KNH_EX_REF b;
};
#endif

/* ------------------------------------------------------------------------ */
//## class Path Object;
//## flag Path Trusted        1 - is set * *;
//## flag Path Temporary      2 - is set * *;

#ifdef PATH_MAX
#define K_PATHMAX PATH_MAX
#else
#define K_PATHMAX 256
#endif

typedef struct kPath kPath;
typedef void   kconn_t;
//typedef kuintptr_t int;
#define IO_NULL   ((kuintptr_t)0)
#define IO_BUF    ((kuintptr_t)1)
#define K_STREAM_BUFSIZ  K_PAGESIZE
#define K_OUTBUF_MAXSIZ      (512L * 1024 * 1024)  // 512Mb

#define K_STREAM_NULL      0
#define K_STREAM_INMEMORY  1
#define K_STREAM_STDIO     2
#define K_STREAM_FILE      3
#define K_STREAM_FD        4
#define K_STREAM_NET       5

typedef struct kio_t kio_t;

struct kio_t {
	union {
		int  fd;
		void *handler;
		FILE *fp;
		struct kBytes *baNC;
	};
	void *handler2; // NULL
	int  isRunning;
	char  *buffer;
	size_t bufsiz;
	size_t top; size_t tail;
	kbool_t    (*_read)(CTX, struct kio_t *);
	size_t     (*_write)(CTX, struct kio_t *, const char *buf, size_t bufsiz);
	void       (*_close)(CTX, struct kio_t *);

	kbool_t (*_blockread)(CTX, struct kio_t *);
	kbool_t (*_unblockread)(CTX, struct kio_t *);
	size_t     (*_blockwrite)(CTX, struct kio_t *, const char *buf, size_t bufsiz);
	size_t     (*_unblockwrite)(CTX, struct kio_t *, const char *buf, size_t bufsiz);
	const char *DBG_NAME;  // unnecessary for free
};

typedef struct knh_PathDPI_t {
	int type;
	const char   *name;
	size_t       wbufsiz;  // write bufsize
	kbool_t   (*existsSPI)(CTX, struct kPath *);
	void         (*ospath)(CTX, struct kPath *, struct kNameSpace *);
	// stream
	kio_t*   (*io2openNULL)(CTX, struct kPath*, const char *, kDictMap *);
	knh_Fitrnext  qnextData;
} knh_PathDPI_t;


#ifdef USE_STRUCT_Path
struct kPath {
	kObjectHeader h;
	const char                  *ospath;
	size_t                       asize;
	struct kString          *urn;
	const struct knh_PathDPI_t   *dpi;
};
#endif

/* ------------------------------------------------------------------------ */
//## class InputStream Object;

#define KNH_STDIN          (ctx->in)
#define KNH_STDOUT         (ctx->out)
#define KNH_STDERR         (ctx->err)

#define knh_InputStream_getc(ctx, in)          io2_getc(ctx, (in)->io2)
#define knh_InputStream_readLine(ctx, in)      io2_readLine(ctx, (in)->io2, (in)->decNULL)
#define knh_InputStream_close(ctx, in)         io2_close(ctx, (in)->io2)

typedef struct kInputStream kInputStream;
#ifdef USE_STRUCT_InputStream
struct kInputStream {
	kObjectHeader h;
	kio_t *io2;
	kPath *path;
	struct kStringDecoder* decNULL;
};
#endif

/* ------------------------------------------------------------------------ */
//## class OutputStream Object;
//## flag OutputStream BOL            1 - is set * *;
//## flag OutputStream AutoFlush      2 - is set is set;
//## flag OutputStream UTF8           3 - has set * *;

typedef struct kOutputStream kOutputStream;

#ifdef USE_STRUCT_OutputStream
struct kOutputStream {
	kObjectHeader h;
	kio_t *io2;
	struct kPath *path;
	struct kBytes *bufferNULL;
	struct kStringEncoder* encNULL;
};
#endif

#define knh_putc(ctx, w, ch)       knh_OutputStream_putc(ctx, w, ch)
#define knh_write(ctx, w, s)       knh_OutputStream_write(ctx, w, s)
#define knh_flush(ctx, w)          knh_OutputStream_flush(ctx, w)
#define knh_write_delim(ctx, w)    knh_write_ascii(ctx, w, ", ")
#define knh_write_dots(ctx, w)     knh_write_ascii(ctx, w, "...")
#define knh_write_delimdots(ctx, w)     knh_write_ascii(ctx, w, ", ...")
#define knh_write_fn(ctx, w, fn)   knh_write_ascii(ctx, w, FN__(fn))
#define knh_write__O(ctx, w, o)    knh_write_Object(ctx, w, MN__k, o)

/* ------------------------------------------------------------------------ */
//## class View Object;

typedef struct kView kView;

#ifdef USE_STRUCT_View
struct kView {
	kObjectHeader h;
	kPath                   *path;
	kDictMap                *conf;
};
#endif

/* ------------------------------------------------------------------------ */
//## class NameSpace Object;
typedef struct kNameSpace kNameSpace;

#ifdef USE_STRUCT_NameSpace
typedef struct knh_NameSpaceEX_t {
	kString *nsname;
	struct kDictMap*   constDictCaseMapNULL;
	struct kArray *    ffilinksNULL;
	struct kDictMap   *linkDictMapNULL;

	struct kDictSet*   name2ctDictSetNULL;
	struct kDictMap*   name2dpiNameDictMapNULL;
	struct kArray*     methodsNULL;
	struct kArray*     formattersNULL;
} knh_NameSpaceEX_t;

struct kNameSpace {
	kObjectHeader h;
	knh_NameSpaceEX_t KNH_EX_REF b;
	struct kNameSpace   *parentNULL;
	kPath               *path;
	void                     *gluehdr;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Private @Singleton class Script Object;

typedef struct kScript kScript;
#ifdef USE_STRUCT_Script
struct kScript {
	kObjectHeader h;
	Object **fields;
	struct kNameSpace *ns;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Singleton @Struct class System Object;

typedef struct kSystem kSystem;

struct kSystem {
	kObjectHeader h;
};

/* ------------------------------------------------------------------------ */
//## class Context Object;
//## flag Context Debug        1 ((kcontext_t*)%s)->flag is set is set;
//## flag Context CompileOnly  2 ((kcontext_t*)%s)->flag is set * *;
//## flag Context Interactive  3 ((kcontext_t*)%s)->flag is set * *;

typedef struct kContext kContext;
#ifdef K_INTERNAL
struct kContext {
	kObjectHeader h;
	const kcontext_t *ctx;
};
#endif

/* ------------------------------------------------------------------------ */
//## class Assurance Object;
//## flag Assurance  CheckedIn        1 - is set * *;

typedef struct kAssurance kAssurance;
#ifdef K_INTERNAL
struct kAssurance {
	kObjectHeader h;
	struct kString *msg;
	kuintptr_t aid;
	ksfp_t *sfp;
	kintptr_t stime;
};
#endif

/* ------------------------------------------------------------------------ */
/* konohac.h */

//## class Token Object;
//## class Sugar Object;
//## class Expr  Object;
//## class Stmt  Object;
//## class Block Object;
//## @Singleton class Lang Object;

typedef kshort_t    ksugar_t;
typedef kushort_t   kexpr_t;

typedef enum {
	TK_NONE,
	TK_CODE,
	TK_INDENT,
	TK_WHITESPACE,
	TK_OPERATOR,
	TK_SYMBOL,
	TK_USYMBOL,
	TK_TEXT,
	TK_STEXT,
	TK_INT,
	TK_FLOAT,
	TK_URN,
	TK_REGEX,
	TK_META,
	TK_PROP,
	TK_LIST,
	TK_EXPR,
	TK_STMT,
	TK_BLOCK,
} ktoken_t ;

typedef struct kToken kToken;
#ifdef USE_STRUCT_Token
struct kToken {
	kObjectHeader h;
	ktoken_t token;
	union {
		struct kString *text;
		struct kExpr *expr;
	};
	kline_t     uline;
	kushort_t lpos; kshort_t  topch;
};
#endif

#define SUGAR_TOKEN     0
#define SUGAR_DECL      1
#define SUGAR_STMT      2
#define SUGAR_EXPR      3
#define SUGAR_TYPE      4
#define SUGAR_UNINARY   5
#define SUGAR_BINARY    6

typedef struct kSugar kSugar;
#ifdef USE_STRUCT_Sugar
struct kSugar {
	kObjectHeader h;
	ksugar_t sugar;  kshort_t optnum;
	struct kString *key;
	struct kArray  *rules;
};
#endif

#define UEXPR_USER_DEFINED   0
#define UEXPR_TOKEN          1
#define UEXPR_METHOD_CALL    2
#define UEXPR_NEW            3
#define UEXPR_CALL           4
#define UEXPR_BINARY         5
#define UEXPR_GETTER         6

#define TEXPR_TYPE           10
#define TEXPR_CONST          (TEXPR_TYPE+1)
#define TEXPR_METHOD_CALL    (TEXPR_TYPE+2)

typedef struct kExpr kExpr;
#ifdef USE_STRUCT_Expr
struct kExpr {
	kObjectHeader h;
	kexpr_t kexpr; ktype_t type;
	kToken *token;
	union {
		struct kArray *cons;  // (expr).x
		Object* data;
	};
	union {
		kshort_t   index;
		kclass_t   cid;
		kmethodn_t mn;
	};
	kflag_t xindex;
};
#endif

typedef struct kStmt kStmt;
#ifdef USE_STRUCT_Stmt
struct kStmt {
	kObjectHeader h;
	kline_t uline;
	struct kStmt      *key;
	struct kBlock     *parent;
	struct kDictMap   *clauseDictMap;
};
#endif

typedef struct kBlock kBlock;
#ifdef USE_STRUCT_Block
struct kBlock {
	kObjectHeader h;
	struct kStmt    *parent;
	struct kArray   *blocks;
};
#endif

typedef struct kGamma kGamma;


typedef struct kLang kLang;
#ifdef USE_STRUCT_Lang
typedef struct knh_LangEX_t {
	struct kDictMap*   tokenRulesNULL;
	struct kDictMap*   uninaryRulesNULL;
	struct kDictMap*   binaryRulesNULL;
	struct kArray*     stmtRulesNULL;
	struct kArray*     exprRulesNULL;
} knh_LangEX_t ;


struct kLang {
	kObjectHeader h;
	knh_LangEX_t KNH_EX_REF b;
	struct kString  *name;
	struct kLang    *parentNULL;
	struct kArray   *gcbuf;   // gc buffer
};
#endif

/* ------------------------------------------------------------------------ */
//## class Term Object;
//## flag Term BOL           0 SP(%s)->flag0 is set * *;
//## flag Term DOT           1 SP(%s)->flag0 is set * *;
//## flag Term NWS           2 SP(%s)->flag0 is set * *;
//## flag Term ISBOOL        3 SP(%s)->flag0 is set * *;
//## flag Term Getter        4 SP(%s)->flag0 is set * *;
//## flag Term Setter        5 SP(%s)->flag0 is set * *;
//## flag Term ExceptionType 6 SP(%s)->flag0 is set * *;
//## flag Term Diamond       7 SP(%s)->flag0 is set * *;
//## flag Term MEMO1         8 SP(%s)->flag0 is set * *;

// TT_BRACE, TT_PARENTHESIS, TT_BRANCET
#define Term_isSAMELINE(o)  Term_isMEMO1(o)
#define Term_setSAMELINE(o, b) Term_setMEMO1(o, b)

// TT_NAME
#define Term_isPNAME(o)      Term_isMEMO1(o)
#define Term_setPNAME(o, b)  Term_setMEMO1(o, b)

// TT_UNAME
#define Term_isBYTE(o)       Term_isMEMO1(o)
#define Term_setBYTE(o, b)   Term_setMEMO1(o, b)

// TT_URN
#define Term_isDYNAMIC(o)  Term_isMEMO1(o)
#define Term_setDYNAMIC(o, b) Term_setMEMO1(o, b)

// TT_LVAR,
#define Term_isSUPER(o)      Term_isMEMO1(o)
#define Term_setSUPER(o, b)  Term_setMEMO1(o, b)

// TT_LVAR, TT_FIELD, TT_SCRIPT
#define Term_isReadOnly(tk)   Term_isBOL(tk)
#define Term_setReadOnly(tk, b)   Term_setBOL(tk, b)

typedef kushort_t   kterm_t;

//typedef struct kTerm kTerm;
//#ifdef K_INTERNAL
//struct kTerm {
//	kObjectHeader h;
//	void *ref;
//	kline_t uline;                   //Term
//	ktype_t type; kterm_t  tt;     //Term
//};
//#endif

typedef struct kTerm kTerm;
#ifdef K_INTERNAL
struct kTerm {
	kObjectHeader h;
	union {
		Object* data;
		struct kArray   *list;
		struct kString  *text;
		struct kTerm   *token;
		struct kStmtExpr    *stmt;
		struct kMethod  *mtd;
		struct kTypeMap *mpr;
		struct kTerm   *tkIDX;
		struct kInt     *num;
	};
	kline_t uline;                  // Term
	ktype_t type; kterm_t  tt;    // Term
	kflag_t flag0;
	union {
		kshort_t   index;
		kclass_t   cid;
		kmethodn_t mn;
	};
};
#endif

#define Term_isTyped(o)    (SP(o)->type != TYPE_var)
#define new_TermCONST(ctx, d)  new_TermCONST_(ctx, UPCAST(d))

/* ------------------------------------------------------------------------ */
//## @Struct class StmtExpr Object;
//## flag Stmt STOPITR    0 DP(%s)->flag0 is set * *;
//## flag Stmt CONSTOLD      2 DP(%s)->flag0 is set * *;
//## flag Stmt Memo1      4 DP(%s)->flag0 is set * *;
//## flag Stmt Memo2      5 DP(%s)->flag0 is set * *;

/* STT_METHOD*/
#define StmtMETHOD_isVARGs(s)          Stmt_isMemo1(s)
#define StmtMETHOD_setVARGs(s,b)       Stmt_setMemo1(s,b)
#define StmtMETHOD_isFFI(s)            Stmt_isMemo2(s)
#define StmtMETHOD_setFFI(s,b)         Stmt_setMemo2(s,b)

/* STT_TCAST*/
#define Stmt_isTRANS(s)          Stmt_isMemo1(s)
#define Stmt_setTRANS(s,b)       Stmt_setMemo1(s,b)
#define Stmt_isDOWNCAST(s)       Stmt_isMemo2(s)
#define Stmt_setDOWNCAST(s,b)    Stmt_setMemo2(s,b)

/* STT_CALL*/
#define Stmt_isTAILRECURSION(s)       Stmt_isMemo1(s)
#define Stmt_setTAILRECURSION(s,b)    Stmt_setMemo1(s,b)
#define Stmt_isCLASSCONSTDEF(s)       Stmt_isMemo2(s)
#define Stmt_setCLASSCONSTDEF(s,b)    Stmt_setMemo2(s,b)

/* STT_FUNCCALL*/
#define Stmt_isDYNCALL(s)       Stmt_isMemo1(s)
#define Stmt_setDYNCALL(s,b)    Stmt_setMemo1(s,b)

/* STT_PRINT */
#define Stmt_isBreakPoint(s)       Stmt_isMemo1(s)
#define Stmt_setBreakPoint(s,b)    Stmt_setMemo1(s,b)

/* STT_RETURN */
#define Stmt_isImplicit(s)       Stmt_isMemo1(s)
#define Stmt_setImplicit(s,b)    Stmt_setMemo1(s,b)

/* STT_LSEND */
#define Stmt_isLSHIFT(s)          Stmt_isMemo1(s)
#define Stmt_setLSHIFT(s,b)       Stmt_setMemo1(s,b)

typedef struct kStmtExpr kStmtExpr;
#ifdef K_INTERNAL
typedef struct {
	kflag_t   flag0;   kushort_t espidx;
	kushort_t size;    kushort_t capacity;
	union {
		struct kDictMap* metaDictCaseMap;
		struct kString*  errMsg;
		struct kStmtExpr*    stmtPOST;
	};
	struct kStmtExpr* nextNULL;
} knh_StmtEX_t;

struct kStmtExpr {
	kObjectHeader h;
#ifdef K_USING_BMGC
	void *unused;
	kline_t uline;                 // Term
	ktype_t type; kterm_t  stt;  // Term
	knh_StmtEX_t KNH_EX_REF b;
#else
	knh_StmtEX_t KNH_EX_REF b;
	kline_t uline;                 // Term
	ktype_t type; kterm_t  stt;  // Term
#endif
	union {
		struct kTerm**  terms;
		struct kTerm** tokens;
		struct kStmtExpr**  stmts;
	};
};
#endif

#define Stmt_isTyped(o)        ((o)->type != TYPE_var)

/* ------------------------------------------------------------------------ */
//## @Struct @Private class GammaBuilder Object;
//## flag GammaBuilder EnforceConst  0 DP(%s)->flag is  set   * *;
//## flag GammaBuilder Quiet         1 DP(%s)->flag is  set   * *;
//## flag GammaBuilder Throwable     2 DP(%s)->flag is  set   * *;
//## flag GammaBuilder PROCEED       3 DP(%s)->flag has found * *;
//## flag GammaBuilder REGISTER      4 DP(%s)->flag has found * *;
//## flag GammaBuilder YEILD         5 DP(%s)->flag has found * *;
//## flag GammaBuilder FIELD         6 DP(%s)->flag has found * *;
//## flag GammaBuilder LexicalScope  7 DP(%s)->flag has found * *;
//## flag GammaBuilder SCRIPT        8 DP(%s)->flag has found * *;

//## flag GammaBuilder InlineFunction  0 DP(%s)->cflag is set * *;
//## flag GammaBuilder TailRecursion   1 DP(%s)->cflag is set * *;

#ifndef K_GAMMAMAX
#define K_GAMMAMAX 64
#endif

typedef struct kGammaBuilder kGammaBuilder;

#ifdef K_INTERNAL
typedef kshort_t knh_gint_t;
typedef struct {
	kflag_t    flag;  kterm_t    ucnt;
	ktype_t    type;  ksymbol_t  fn;
	union {
		kTerm   *tkIDX;
	};
	union {
		kTerm   *tk;
		kStmtExpr    *stmt;
	};
} knh_gamma2_t ;

#define K_GMASCR   ((ctx->gma)->scr)
#define K_GMANS    ((ctx->gma)->scr->ns)

typedef struct knh_GammaBuilderEX_t {
	kflag_t                 flag;
	kflag_t                 cflag;
	struct kStmtExpr*         stmt;
	struct kMethod*       mtd;
	kclass_t                this_cid;
	knh_gint_t                 funcbase0;

	/*gamma*/
	knh_gamma2_t*             gf;
	knh_gint_t                gsize;
	knh_gint_t                gcapacity;
	knh_gint_t                psize; /* param size */
	knh_gint_t                fvarsize;

	kTerm              *tkScriptNC;
	kTerm              *tkFuncThisNC;
	kMethod             *proceedNC;  /*@Around*/

	struct kBasicBlock    *bbNC;
	struct kArray         *insts;  // bbNC->listNC
	struct kArray         *lstacks;
	struct kStmtExpr          *finallyStmt;
	struct kArray         *errmsgs;
	void  *asm_data;           // what is this?
} knh_GammaBuilderEX_t;

struct kGammaBuilder {
	kObjectHeader h;
#ifdef K_USING_BMGC
	void *unused;
	kline_t uline;         // same as Term
	knh_GammaBuilderEX_t KNH_EX_REF b;
#else
	knh_GammaBuilderEX_t KNH_EX_REF b;
	kline_t uline;         // same as Term
#endif
	kScript *scr;
};
#endif

typedef kbool_t (*knh_Ftyping)(CTX, kMethod *, kStmtExpr *);

///* ------------------------------------------------------------------------ */

typedef kuintptr_t          kopcode_t;
typedef kintptr_t           ksfpidx_t;
typedef kintptr_t           kreg_t;
typedef kintptr_t           kregO_t;
typedef kintptr_t           kregN_t;
typedef void*               kdummyptr_t;

struct  kopl_t;
typedef struct kopl_t kopl_t;

#ifdef K_INTERNAL
#define klr_Ffcall    knh_Fmethod
typedef void (*klr_Fth)(CTX, struct kopl_t *, void**);
struct klr_LDMTD_t;
typedef void (*klr_Floadmtd)(CTX, ksfp_t *, struct klr_LDMTD_t *);
typedef long   (*klr_Finttr)(long u);
typedef double (*klr_Ffloattr)(double u);
typedef void (*klr_Ftr)(CTX, ksfp_t*, ksfpidx_t, const knh_ClassTBL_t *);
typedef void (*klr_Fcheckin)(CTX, ksfp_t *, struct kRawPtr *);
typedef void (*klr_Fcheckout)(CTX, struct kRawPtr *, int);
struct klr_P_t;
typedef void (*klr_Fprint)(CTX, ksfp_t*, struct klr_P_t*);
struct klr_PROBE_t;
typedef void (*klr_Fprobe)(CTX, ksfp_t* , struct klr_PROBE_t *pc);

typedef struct {
	kdummyptr_t _d1;
	kdummyptr_t _d2;
	kdummyptr_t _d3;
	kdummyptr_t _d4;
	kdummyptr_t _d5;
} knh_opdummy_t;

typedef struct {
	ksfpidx_t i;
	ksfpidx_t n;
} ksfx_t;

#if defined(K_USING_THCODE_)
#define KCODE_HEAD \
	void *codeaddr; \
	size_t count; \
	kushort_t opcode; \
	kushort_t line

#else
#define KCODE_HEAD \
	size_t count; \
	kopcode_t opcode; \
	kuintptr_t line \

#endif/*K_USING_THCODE_*/

struct kopl_t {
	KCODE_HEAD;
	union {
		kintptr_t data[5];
		void *p[5];
		kchar_t *u[5];
	};
};
#endif

#define DBG_ASSERT_OPCODE(c) \
	if(((kopcode_t)c) >= OPCODE_MAX) {\
		DBG_P("Invalid opcode=%d", (int)c); \
		DBG_ASSERT(c < OPCODE_MAX); \
	}\

/* ------------------------------------------------------------------------ */
//## class BasicBlock Object;
//## flag BasicBlock Visited  1 - is set  *   *;
//## flag BasicBlock StackChecked 2 - is set * *;

typedef struct kBasicBlock kBasicBlock;
#ifdef K_INTERNAL
typedef struct knh_BasicBlockEX_t {
	kushort_t id;     kushort_t incoming;
	kopl_t *opbuf;
	kushort_t size;   kushort_t capacity;
	kushort_t bottom; kushort_t top;
	kopl_t *code;
	kopl_t *opjmp;
} knh_BasicBlockEX_t ;

struct kBasicBlock {
	kObjectHeader h;
	knh_BasicBlockEX_t KNH_EX_REF b;
	struct kArray *listNC;
	struct kBasicBlock *nextNC;
	struct kBasicBlock *jumpNC;
};
#endif

/* ------------------------------------------------------------------------ */
//## class KonohaCode Object;
//## flag KonohaCode NativeCompiled  1 - is set  *   *;

typedef struct kKonohaCode kKonohaCode;
#ifdef K_INTERNAL
struct kKonohaCode {
	kObjectHeader h;
	kopl_t*  code;
	size_t        codesize;
	kString *source;
	kuri_t     uri; kuri_t     domain;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Immutable class Immutable Object;

typedef struct kImmutable {
	kObjectHeader h;
} kImmutable;

/* ------------------------------------------------------------------------ */
//## class KindOf Object;

typedef struct kKindOf {
	kObjectHeader h;
} kKindOf;

/* ------------------------------------------------------------------------ */
//## class Tdynamic Object;

typedef void (*knh_Frawfree)(void *);

typedef struct kRawPtr {
	kObjectHeader h;
	void *rawptr;
	struct kObject **kfields;  // c++
	const char *DBG_NAME;
	knh_Frawfree rawfree;
} kRawPtr ;

#define CLASS_Tdyn      CLASS_Tdynamic
#define CLASS_dynamic   CLASS_Tdynamic
#define TYPE_dyn        CLASS_Tdynamic
#define TYPE_dynamic    CLASS_Tdynamic
#define CLASS_CppObject CLASS_Tdynamic
#define new_ReturnRawPtr(ctx, sfp, p)  new_ReturnCppObject(ctx, sfp, p, NULL)

/* ------------------------------------------------------------------------ */

#define SYSLOG_iZERODIV(ctx, sfp, n)
#define SYSLOG_fZERODIV(ctx, sfp, n)

#define SYSLOG_iZERODIV2(ctx, sfp, n)  \
	if(unlikely(n == 0)) { \
		THROW_Arithmetic(ctx, sfp, "zero divided"); \
	}\

#define SYSLOG_fZERODIV2(ctx, sfp, n)  \
	if(unlikely(n == KFLOAT_ZERO)) { \
		THROW_Arithmetic(ctx, sfp, "zero divided"); \
	}\

#define K_CALLDELTA   4
#define K_RTNIDX    (-4)
#define K_SHIFTIDX  (-3)
#define K_PCIDX     (-2)
#define K_MTDIDX    (-1)
#define K_TMRIDX    (0)
#define K_SELFIDX   0

#define K_NEXTIDX    2
#define K_SHIFTIDX2  (-5)
#define K_PCIDX2     (-3)
#define K_MTDIDX2    (-1)

#define klr_setesp(ctx, newesp)  ((kcontext_t*)ctx)->esp = (newesp)
#define klr_setmtdNC(ctx, sfpA, mtdO)   sfpA.mtdNC = mtdO

#define Method_isKonohaCode(mtd) ((mtd)->fcall_1 == knh_Fmethod_runVM)

#define GammaBuilder_hasJIT(ctx)     0
#define CODE_VEXEC     (ctx->share->PRECOMPILED_VEXEC)
#define CODE_LAUNCH    (ctx->share->PRECOMPILED_LAUNCH)
#define CODE_FUNCCALL  (ctx->share->PRECOMPILED_FUNCCALL)
//#define CODE_ABSTRACT  (ctx->share->PC_ABSTRACT)

#define KNH_SCALL(ctx, lsfp, rtnidx, mtdO, argc) { \
		kintptr_t thisidx_ = rtnidx+ K_CALLDELTA;\
		DBG_ASSERT(IS_Method(mtdO));\
		klr_setmtdNC(ctx, lsfp[thisidx_+K_MTDIDX], mtdO);\
		klr_setesp(ctx, lsfp + thisidx_ + argc + 1);\
		if(Method_isKonohaCode(mtdO)) {\
			knh_VirtualMachine_run(ctx, lsfp + thisidx_, CODE_VEXEC);\
		}else {\
			(mtdO)->fcall_1(ctx, lsfp + thisidx_, K_RTNIDX);\
		}\
		klr_setmtdNC(ctx, lsfp[thisidx_+K_MTDIDX], NULL);\
		klr_setesp(ctx, lsfp + rtnidx);\
	} \

#define KNH_SELFCALL(ctx, sfp, mtd, rix) { \
		(mtd)->fcall_1(ctx, sfp, rix);\
	} \

#define KNH_FINVOKE(ctx, lsfp, rtnidx, fo, argc) {             \
		kintptr_t thisidx_ = rtnidx+ K_CALLDELTA;           \
		KNH_SETv(ctx, lsfp[thisidx].o, fo);                    \
		if (fo->baseNULL != NULL) {					           \
			KNH_SETv(ctx, lsfp[thisidx].o, fo->baseNULL);      \
		}												       \
		klr_setmtdNC(ctx, lsfp[thisidx_+K_MTDIDX], fo->mtd);   \
		klr_setesp(ctx, lsfp + thisidx_ + argc + 1);           \
		KNH_SELFCALL(ctx, lsfp, fo->mtd, K_RTNIDX);            \
	}                                                          \

#define BEGIN_LOCAL(ctx, lsfp, n) \
		ksfp_t *lsfp = knh_stack_local(ctx, n);\
		KNH_SAFEPOINT(ctx, lsfp); \
		int sfpidx_ = lsfp - ctx->stack;\

#define BEGIN_UNSAFELOCAL(ctx, lsfp, n) \
		ksfp_t *lsfp = knh_stack_local(ctx, n); \
		int sfpidx_ = lsfp - ctx->stack;\

#ifdef __cplusplus
#define __CONST_CAST__(T, expr) (const_cast<T>(expr))
#else
#define __CONST_CAST__(T, expr) ((T)expr)
#endif

#define END_LOCAL(ctx, lsfp) \
	(__CONST_CAST__(kcontext_t*, ctx))->esp = ctx->stack + sfpidx_;\


#define LOCAL_NEW(ctx, lsfp, n, T, V, O) \
	T V = O;\
	KNH_SETv(ctx, lsfp[n].o, V);\

#define KNH_SECURE(ctx, sfp) knh_checkSecurityManager(ctx, sfp)

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif

#endif /*CLASS_KONOHA_H_*/

