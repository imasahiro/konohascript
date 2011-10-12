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

#define	K_SMALLOBJECT_FIELDSIZE 3

typedef struct knh_ObjectField_t knh_ObjectField_t;
#if defined(K_INTERNAL) || defined(USE_STRUCT_ObjectField) || defined(USE_STRUCT_Tuple)
struct knh_ObjectField_t  {
	knh_hObject_t h;
	union {
		Object  **fields;
		knh_int_t *ifields;
		knh_float_t *ffields;
	};
	Object  *smallobject;  // small object
};
#endif

#define IS_NULL(o)     ((((o)->h.magicflag) & FLAG_Object_NullObject) == FLAG_Object_NullObject)
#define IS_NOTNULL(o)  ((((o)->h.magicflag) & FLAG_Object_NullObject) != FLAG_Object_NullObject)

#define CLASS_ObjectField   CLASS_Object
#define O_cid(o)   (((o)->h.cTBL)->cid)
#define O_bcid(o)  (((o)->h.cTBL)->bcid)
#define O_cTBL(o)     ((o)->h.cTBL)
#define O_p1(o)    (((o)->h.cTBL)->p1)
#define O_p2(o)    (((o)->h.cTBL)->p2)
#define IS_ObjectField(o)  (((o)->h.cTBL)->bcid == CLASS_Object)

#define new_H(C)         (knh_##C##_t*)new_hObject_(ctx, ClassTBL(CLASS_##C))
#define new_hObject(ctx, cid)          new_hObject_(ctx, ClassTBL(cid))
#define new_(C)          (knh_##C##_t*)new_Object_init2(ctx, ClassTBL(CLASS_##C))
#define new_O(C,cid)     (knh_##C##_t*)new_Object_init2(ctx, ClassTBL(cid))

/* ------------------------------------------------------------------------ */
//## @Immutable class Boolean Object;

typedef union knh_num_t knh_num_t;
#ifdef K_INTERNAL
union knh_num_t {
	knh_ndata_t   data;
	knh_bool_t    bvalue;
	knh_int_t     ivalue;
	knh_float_t   fvalue;
};
#endif

typedef struct knh_Boolean_t knh_Boolean_t;
#ifdef K_INTERNAL
struct knh_Boolean_t {
	knh_hObject_t h;
	knh_num_t n;
};
#endif

#define IS_TRUE(o)         (O_bcid(o) == CLASS_Boolean && N_tobool(o))
#define IS_FALSE(o)        (O_bcid(o) == CLASS_Boolean && N_tobool(o) == 0)
#define new_Boolean(ctx, c)    ((c) ? KNH_TRUE : KNH_FALSE)
#define O_ndata(o)        (((knh_Number_t*)o)->n.data)

/* ------------------------------------------------------------------------ */
//## @Immutable class Number Object;

typedef struct knh_Number_t knh_Number_t;
#ifdef K_INTERNAL
struct knh_Number_t {
	knh_hObject_t h;
	knh_num_t n;
};
#endif

#define N_toint(o)         (((knh_Number_t*)o)->n.ivalue)
#define N_tofloat(o)       (((knh_Number_t*)o)->n.fvalue)
#define N_tobool(o)        (((knh_Number_t*)o)->n.bvalue)

/* ------------------------------------------------------------------------ */
//## @Immutable class Int Number;

typedef struct knh_Int_t knh_Int_t;
#ifdef K_INTERNAL
struct knh_Int_t {
	knh_hObject_t h;
	knh_num_t n;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Immutable class Float Number;

typedef struct knh_Float_t knh_Float_t;
#ifdef K_INTERNAL
struct knh_Float_t {
	knh_hObject_t h;
	knh_num_t n;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Immutable class Date Object;

typedef struct knh_date_t {
	knh_short_t year; knh_short_t month;
	knh_short_t day;  knh_short_t hour;
	knh_short_t min;  knh_short_t sec;
	knh_short_t gmtoff; knh_short_t isdst; /* summer time */
} knh_date_t ;

typedef struct knh_Date_t {
	knh_hObject_t h;
	knh_date_t dt;
} knh_Date_t;

/* ------------------------------------------------------------------------ */
//## @Immutable class String Object;
//## flag String TextSgm 1 - is set  *   *;
//## flag String ASCII   2 - is set  is  *;
//## flag String Pooled  3 - is set  is  *;

#define K_SPOLICY_TEXT          (1<<0)
#define K_SPOLICY_ASCII         (1<<1)
#define K_SPOLICY_UTF8          (1<<2)
#define K_SPOLICY_POOLNEVER     (1<<3)
#define K_SPOLICY_POOLALWAYS    (1<<4)

typedef struct knh_String_t knh_String_t;
struct knh_String_t {
	knh_hObject_t h;
	knh_bytes_t str;
	knh_hashcode_t hashCode;
};

#define new_T(t)            new_String2(ctx, CLASS_String, t, knh_strlen(t), K_SPOLICY_TEXT|K_SPOLICY_ASCII|K_SPOLICY_POOLALWAYS)
#define new_S(T, L)         new_String2(ctx, CLASS_String, T, L, K_SPOLICY_ASCII|K_SPOLICY_POOLALWAYS)
#define new_String_()

#define S_tobytep(s)          (&(s)->str)
#define S_tobytes(s)          ((s)->str)
#define S_totext(s)           ((s)->str.text)
#define S_size(s)             ((s)->str.len)
#define S_equals(s, b)        knh_bytes_equals(S_tobytes(s), b)
#define S_startsWith(s, b)    knh_bytes_startsWith(S_tobytes(s), b)
#define S_endsWith(s, b)      knh_bytes_endsWith(S_tobytes(s), b)

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
} knh_dim_t ;

typedef struct knh_Bytes_t knh_Bytes_t;
struct knh_Bytes_t {
	knh_hObject_t h;
	knh_bytes_t   bu;
	const knh_dim_t    *dim;
	const char *DBG_name;
};

#define KNH_SIZE(v)     v
#define k_grow(N)       ((N)*2)

#define BA_tobytes(o)   (o)->bu
#define BA_size(o)      (o)->bu.len
#define BA_totext(o)    (o)->bu.text

#define B_equals(b, t)        (knh_bytes_strcmp(b, STEXT(t)) == 0)
#define B_startsWith(b, t)    knh_bytes_startsWith(b, STEXT(t))
#define B_endsWith(b, t)      knh_bytes_endsWith(b, STEXT(t))

/* ------------------------------------------------------------------------ */
//## class Pointer Object;

typedef struct knh_Pointer_t knh_Pointer_t;

struct knh_Pointer_t {
	knh_hObject_t h;
	union {
		void *ptr;
		unsigned char *uptr;
	};
	size_t size;
	size_t wsize;
	struct knh_Object_t *gcref;
};

/* ------------------------------------------------------------------------ */
//## class Iterator Object;
//## flag Iterator NDATA     1 - is set * *;
//## type IteratorVar     Iterator 0 Tvar;
//## type DataITR         Iterator 0 Map;
//## type FuncEach        Func  1 T1 T1;
//## type FuncWhere       Func  1 T1 Boolean;

typedef struct knh_nitr_t {
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
} knh_nitr_t;

#define K_NITR_INIT   {NULL, NULL, {0L}, {0L}}
#define ITR(sfp)   sfp[0].it

typedef void (*knh_Ffree)(void *nptr);

typedef struct knh_Iterator_t knh_Iterator_t;

#ifdef K_INTERNAL
typedef struct {
	Object    *source;
	union {
		struct knh_Method_t  *mtdNULL;
		struct knh_Func_t    *funcNULL;
		struct knh_TypeMap_t *tmrNULL;
	};
	struct     knh_nitr_t m;
} knh_IteratorEX_t;

struct knh_Iterator_t {
	knh_hObject_t h;
	knh_IteratorEX_t *b;
	knh_Fitrnext fnext_1;
};
#endif

/* ------------------------------------------------------------------------ */
//## class Tuple Object;

typedef knh_ObjectField_t knh_Tuple_t;

/* ------------------------------------------------------------------------ */
//## @Immutable class Range Object;
//## flag Range NDATA     1 - is set * *;
//## flag Range Inclusive 2 - is set * *;
//## type RangeInt  Range 0 Int;

typedef struct knh_Range_t knh_Range_t;
#ifdef K_INTERNAL
struct knh_Range_t {
	knh_hObject_t h;
	union {
		knh_Object_t  *ostart;
		knh_ndata_t    nstart;
	};
	union {
		knh_Object_t  *oend;
		knh_ndata_t    nend;
	};
};
#endif

/* ------------------------------------------------------------------------ */
//## class Array   Object;
//## flag  Array   NDATA     1 - is set * *;
//## type ArrayInt  Array 0 Int;
//## type CmprT1    Func  1 T1 T1 Int;

typedef struct {
	size_t   (*index)(CTX ctx, knh_sfp_t *sfp, knh_int_t n, size_t size);
	void     (*fastget)(CTX ctx, knh_sfp_t *sfp, size_t n _RIX);
	void     (*get)(CTX ctx, struct knh_Array_t *, size_t n, knh_sfp_t *sfp);
	void     (*set)(CTX ctx, struct knh_Array_t *, size_t n, knh_sfp_t *sfp);
	void     (*add)(CTX ctx, struct knh_Array_t *, knh_sfp_t *sfp);
	void     (*multiadd)(CTX ctx, struct knh_Array_t *, knh_sfp_t *sfp);
} knh_ArrayAPI_t;

typedef struct knh_Array_t knh_Array_t;
struct knh_Array_t {
	knh_hObject_t h;
	union {
		knh_ndata_t             *nlist;
		knh_int_t               *ilist;
		knh_float_t             *flist;
		struct knh_Object_t    **list;
		struct knh_RawPtr_t    **ptrs;
		struct knh_String_t    **strings;
		struct knh_Int_t       **ints;
		struct knh_Method_t    **methods;
		struct knh_TypeMap_t   **trans;
		struct knh_Token_t     **tokens;
		struct knh_Stmt_t      **stmts;
	};
	size_t size;
	const knh_dim_t *dim;
	const knh_ArrayAPI_t *api;
};

#define knh_Array_n(a,n)      (a)->list[(n)]
#define knh_Array_size(a)     (a)->size
#define knh_Array_trimSize(ctx, a, newsize)  knh_Array_clear(ctx, a, newsize)
#define knh_Array_add(ctx, a, o)    knh_Array_add_(ctx, a, UPCAST(o))
#define knh_Array_remove(ctx, a, n)    knh_Array_remove_(ctx, a, n)
//#define knh_TOKENs_n(a, n)    ((knh_Token_t*)(a)->list[(n)])

///* ------------------------------------------------------------------------ */
//## class Map Object;

typedef void  knh_mapptr_t;

typedef struct knh_MapDPI_t {
	int   type;
	const char *name;
	const struct knh_MapDPI_t* (*config)(CTX, knh_class_t, knh_class_t);
	knh_mapptr_t* (*init)(CTX, size_t, const char*, struct knh_DictMap_t *);
	void (*reftrace)(CTX, knh_mapptr_t* FTRARG);
	void (*freemap)(CTX, knh_mapptr_t*);
	// main
	knh_bool_t (*get)(CTX, knh_mapptr_t*, knh_sfp_t*, knh_sfp_t *);
	void (*set)(CTX, knh_mapptr_t*, knh_sfp_t *);
	void (*remove)(CTX, knh_mapptr_t*, knh_sfp_t *);
	size_t (*size)(CTX, knh_mapptr_t*);
	knh_bool_t (*next)(CTX, knh_mapptr_t*, knh_nitr_t *, knh_sfp_t *);
} knh_MapDPI_t;

typedef struct knh_Map_t {
	knh_hObject_t h;
	knh_mapptr_t  *mapptr;
	const struct knh_MapDPI_t *spi;
} knh_Map_t;

typedef struct knh_PtrMap_t {
	knh_hObject_t h;
	knh_mapptr_t  *mapptr;
	const struct knh_MapDPI_t *spi;
} knh_PtrMap_t;

#define knh_Map_size(m)  (m)->spi->size(NULL, (m)->mapptr)

// DictMap, DictSet are old names of Map;

typedef struct knh_DictMap_t {
	knh_hObject_t h;
	knh_mapptr_t     *mapptr;
	const struct knh_MapDPI_t *spi;
	knh_uline_t uline;
} knh_DictMap_t;

#define new_DictMap0(ctx, N, F, NAME)      new_DictMap0_(ctx, N, F, NAME)
#define knh_DictMap_set(ctx, m, k, v)      knh_DictMap_set_(ctx, m, k, UPCAST(v))

typedef struct knh_DictSet_t {
	knh_hObject_t h;
	knh_mapptr_t     *mapptr;
	const struct knh_MapDPI_t *spi;
} knh_DictSet_t;

typedef void (*knh_Fdictset)(CTX, knh_DictSet_t*, knh_String_t *k, knh_uintptr_t);
#define new_DictSet0(ctx, N, F, NAME)   new_DictSet0_(ctx, N, F, NAME)
#define knh_DictSet_keyAt(ds, n)    knh_DictMap_keyAt((knh_DictMap_t*)ds, n)
#define knh_DictSet_index(ds, key)  knh_DictMap_index((knh_DictMap_t*)ds, key)

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

#define FLAG_Field_Hidden          ((knh_flag_t)(1<<0))
#define FLAG_Field_Protected       ((knh_flag_t)(1<<1))
#define FLAG_Field_Getter          ((knh_flag_t)(1<<2))
#define FLAG_Field_Setter          ((knh_flag_t)(1<<3))
#define FLAG_Field_Key             ((knh_flag_t)(1<<4))
#define FLAG_Field_Volatile        ((knh_flag_t)(1<<5))
#define FLAG_Field_ReadOnly        ((knh_flag_t)(1<<6))
#define FLAG_Field_Property        ((knh_flag_t)(1<<7))

typedef struct knh_Class_t knh_Class_t;
struct knh_Class_t {
	knh_hObject_t h;
	knh_class_t   cid;
	knh_type_t    type;
	const knh_ClassTBL_t *cTBL;
};

/* class */

#define KNH_NULVAL(cid)      knh_getClassDefaultValue(ctx, cid)
#define KNH_TNULL(T)         (knh_##T##_t*)knh_getClassDefaultValue(ctx, CLASS_##T)
#define knh_Class_cid(c)     (knh_class_t)(c)->cid
typedef void (*knh_Fwritecid)(CTX ctx, struct knh_OutputStream_t *w, knh_class_t cid);

/* ------------------------------------------------------------------------ */
//## @Private @Immutable class ParamArray Object;
//## flag ParamArray VARGs  1 - is set * *;
//## flag ParamArray RVAR   2 - is set * *;

typedef struct knh_param_t {
	knh_type_t    type;  knh_fieldn_t  fn;
} knh_param_t;

typedef struct knh_ParamArray_t knh_ParamArray_t;
struct knh_ParamArray_t {
	knh_hObject_t h;
	knh_ushort_t psize; knh_ushort_t rsize;
	union {
		knh_param_t* params;
		knh_param_t  p0;
	};
	union {
		knh_param_t p1;
		size_t capacity;
	};
	knh_param_t p2;
};

#define new_ParamArray(ctx)         new_(ParamArray);
#define knh_param_hash(h, t, fn)    (fn + (((h * 31) + t) * 7))
#define knh_ParamArray_rget(pa, n)  knh_ParamArray_get(pa, (pa->psize) + n)

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

typedef struct knh_Method_t knh_Method_t;

typedef struct {
	knh_flag_t     flag;  knh_ushort_t   delta;
	struct knh_ParamArray_t*    mp;
	void*                       cfunc;
	union {
		knh_Object_t            *objdata;
		struct knh_KonohaCode_t *kcode;
		struct knh_Script_t     *gmascr;       // Dynamic
		struct knh_Stmt_t       *stmtB;        // stmt block
		struct knh_RawPtr_t     *rfunc;        // ffi
		struct knh_Method_t     *proceed;      // during typing, asm
	};
	struct knh_Array_t *paramsNULL;
	struct knh_Token_t *tsource;
	knh_uri_t      uri;   knh_uri_t      domain;
	knh_uintptr_t  count;
} knh_MethodEX_t;

struct knh_Method_t {
	knh_hObject_t        h;
	knh_MethodEX_t      *b;
	knh_class_t          cid;   knh_methodn_t  mn;
	knh_Fmethod          fcall_1;
	struct knh_opline_t *pc_start;
};

#define knh_Method_mf(mtd)    DP(mtd)->mp
#define knh_ParamArray_psize(mf)    ((mf)->psize)
//#define knh_Method_psize(mtd)       ((DP(mtd)->mp)->psize)

//#define knh_Method_pztype(mtd, n) (knh_ParamArray_get(DP(mtd)->mp, n))->type

#define ClassTBL_getMethodNULL(ctx, c, mn)    knh_ClassTBL_findMethodNULL(ctx, c, mn, 0)
#define ClassTBL_getMethod(ctx, c, mn)        knh_ClassTBL_findMethodNULL(ctx, c, mn, 1)

//#define knh_getDefaultFmt(ctx, mn)   knh_ClassTBL_getFmt(ctx, CLASS_Tvoid, mn)

#define knh_stack_argc(ctx, sfp)      (ctx->esp - (sfp))

/* ------------------------------------------------------------------------ */
//## class TypeMap Object;
//## flag TypeMap Interface  1 - is set * *;
//## flag TypeMap Semantic   2 - is set * *;
//## flag TypeMap Const      3 - is set * *;
//## flag TypeMap NDATA      4 - is set * *;

typedef struct knh_TypeMap_t knh_TypeMap_t;

struct knh_TypeMap_t {
	knh_hObject_t h;
	knh_class_t  scid; knh_class_t  tcid;
	knh_Ftypemap ftypemap_1;
	union {
		Object* mapdata;
		struct knh_Method_t  *mtd;
		struct knh_TypeMap_t *tmr1;
	};
	struct knh_TypeMap_t *tmr2;
};

typedef knh_TypeMap_t* (*knh_Ftypemaprule)(CTX ctx, const knh_ClassTBL_t *, const knh_ClassTBL_t *);

/* ------------------------------------------------------------------------ */
//## @Immutable class Func Object;
//## cparam Func 1 R dynamic P dynamic;
//## flag Func StoredEnv 1 - is set * *;

typedef struct knh_Func_t knh_Func_t;
#ifdef USE_STRUCT_Func
struct knh_Func_t {
	knh_hObject_t h;
	struct knh_Method_t* mtd;
	Object* baseNULL;
	struct knh_String_t* name;
	void *cfunc;
};
#endif

/* ------------------------------------------------------------------------ */
//## class Thunk Object;
//## flag Thunk Evaluated 1 - is set * *;

typedef struct knh_Thunk_t knh_Thunk_t;
#ifdef K_INTERNAL
struct knh_Thunk_t {
	knh_hObject_t h;
	knh_sfp_t *envsfp;
	size_t     envsize;
};
#endif

///* ------------------------------------------------------------------------ */
////## class0 Thread Object;
//
//typedef struct knh_Thread_t {
//	knh_hObject_t h;
//	knh_context_t *context;
//	knh_thread_t  th;
//} knh_Thread_t;

/* ------------------------------------------------------------------------ */
//## class Exception Object;

//## expt Exception!! -;
//## expt Assertion!! -;
//## expt Script!! -;
//## expt StackOverflow!! Script!!;
//## expt Security!! -;

typedef struct knh_Exception_t knh_Exception_t;
#ifdef USE_STRUCT_Exception
struct knh_Exception_t {
	knh_hObject_t h;
	knh_String_t   *emsg;
	knh_uline_t     uline;

	knh_Array_t*    tracesNULL;
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
	struct knh_opline_t *pc;
	struct klr_TRY_t *op;
	knh_intptr_t sfpidx;
};
#endif

#else

#ifdef K_INTERNAL
struct knh_ExceptionHandlerEX_t {
	struct knh_opline_t *pc;
	struct klr_TRY_t *op;
	knh_intptr_t sfpidx;
	void *return_address;
	void *frame_address;
	knh_uintptr_t stack_pointer;
};
#endif

#endif/*K_USING_SETJMP_*/

typedef struct knh_ExceptionHandler_t knh_ExceptionHandler_t;
#ifdef K_INTERNAL
struct knh_ExceptionHandler_t {
	knh_hObject_t h;
	knh_ExceptionHandlerEX_t *b;
	knh_intptr_t espidx;
	struct knh_ExceptionHandler_t *parentNC;
	struct knh_Array_t *stacklist;
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

typedef void knh_regex_t;

/* REGEX_SPI */

#ifndef K_REGEX_MATCHSIZE
#define K_REGEX_MATCHSIZE    16
#endif

typedef struct {
	int rm_so;   /* start of match */
	int rm_eo;   /* end of match */
	knh_bytes_t rm_name;  /* {NULL, 0}, if not NAMED */
} knh_regmatch_t;

typedef struct knh_RegexSPI_t {
	const char *name;
	knh_regex_t* (*regmalloc)(CTX, knh_String_t *);
	int (*parse_cflags)(CTX, const char *opt);
	int (*parse_eflags)(CTX, const char *opt);
	int (*regcomp)(CTX, knh_regex_t *, const char *, int);
	int (*regnmatchsize)(CTX, knh_regex_t *);
	int (*regexec)(CTX, knh_regex_t *, const char *, size_t, knh_regmatch_t*, int);
	size_t (*regerror)(int, knh_regex_t *, char *, size_t);
	void (*regfree)(CTX, knh_regex_t *);
//	// this must be defined by uh for named grouping
//	int (*regexec2)(CTX, knh_regex_t *, const char *, ...);
} knh_RegexSPI_t;


typedef struct knh_Regex_t knh_Regex_t;
struct knh_Regex_t {
	knh_hObject_t h;
	knh_regex_t *reg;
	int eflags;
	const struct knh_RegexSPI_t *spi;
	struct knh_String_t *pattern;
};

/* ------------------------------------------------------------------------ */
//## @Immutable class Converter Object;

typedef void knh_conv_t;

typedef struct knh_ConverterDPI_t {
	int  type;
	const char *name;
	knh_conv_t* (*open)(CTX, const char*, const char*);
	knh_bool_t  (*conv)(CTX,  knh_conv_t *, const char*, size_t, knh_Bytes_t *);
	knh_bool_t  (*enc)(CTX,   knh_conv_t *, const char*, size_t, knh_Bytes_t *);
	knh_bool_t  (*dec)(CTX,   knh_conv_t *, const char*, size_t, knh_Bytes_t *);
	knh_bool_t  (*sconv)(CTX, knh_conv_t *, const char*, size_t, knh_Bytes_t *);
	void (*close)(CTX ctx, knh_conv_t*);
	void (*setparam)(CTX ctx, knh_conv_t *, void *, void *);
} knh_ConverterDPI_t;

typedef struct knh_Converter_t knh_Converter_t;
#ifdef K_INTERNAL
struct knh_Converter_t {
	knh_hObject_t h;
	knh_conv_t *conv;
	const struct knh_ConverterDPI_t *dpi;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Immutable class StringEncoder Converter;

typedef struct knh_StringEncoder_t knh_StringEncoder_t;
#ifdef K_INTERNAL
struct knh_StringEncoder_t {
	knh_hObject_t h;
	knh_conv_t *conv;
	const struct knh_ConverterDPI_t *dpi;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Immutable class StringDecoder Converter;

typedef struct knh_StringDecoder_t knh_StringDecoder_t;
#ifdef K_INTERNAL
struct knh_StringDecoder_t {
	knh_hObject_t h;
	knh_conv_t *conv;
	const struct knh_ConverterDPI_t *dpi;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Immutable class StringConverter Converter;

typedef struct knh_StringConveter_t knh_StringConverter_t;
#ifdef K_INTERNAL
struct knh_StringConveter_t {
	knh_hObject_t h;
	knh_conv_t *conv;
	const struct knh_ConverterDPI_t *dpi;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Private class Semantics Object;

#define KNH_SEMANTICS_FMT    "%s{%s}"
struct  knh_Semantics_t;
typedef struct  knh_Semantics_t knh_Semantics_t;

typedef int (*knh_Fichk)(struct knh_Semantics_t *, knh_int_t v);
typedef int (*knh_Ficmp)(struct knh_Semantics_t *, knh_int_t v1, knh_int_t v2);

typedef int (*knh_Ffchk)(struct knh_Semantics_t *, knh_float_t v);
typedef int (*knh_Ffcmp)(struct knh_Semantics_t *, knh_float_t v1, knh_float_t v2);

typedef knh_String_t *(*knh_Fsnew)(CTX, knh_class_t cid, knh_bytes_t, struct knh_String_t *, int *);
typedef int (*knh_Fscmp)(struct knh_Semantics_t *, knh_bytes_t, knh_bytes_t);

typedef struct knh_Semantics_t* (*knh_fspec)(CTX ctx, knh_bytes_t urn);

#ifdef K_INTERNAL
typedef struct knh_SemanticsEX_t knh_SemanticsEX_t;
struct knh_SemanticsEX_t {
	knh_flag_t  flag;
	knh_class_t ucid;
	knh_class_t ubcid;
	knh_String_t* urn;
	knh_String_t* tag;
	struct knh_Int_t    *ivalue;
	struct knh_Float_t  *fvalue;
	struct knh_String_t *svalue;

	// int
	union {
		knh_int_t imin;
		knh_uint_t umin;
	};
	union {
		knh_int_t imax;
		knh_uint_t umax;
	};
	knh_Fichk fichk;
	knh_Ficmp ficmp;

	// float
	knh_float_t fmin;
	knh_float_t fmax;
	knh_float_t fstep;
	knh_Ffchk   ffchk;
	knh_Ffcmp   ffcmp;

	// String
	size_t bytelen;
	size_t charlen;
	Object* pattern;
//	struct knh_DictIdx_t* vocabDictIdx;
	struct knh_StringEncoder_t *bconv;
	knh_Fsnew    fsnew;
	knh_Fscmp    fscmp;
};

struct knh_Semantics_t {
	knh_hObject_t h;
	knh_SemanticsEX_t *b;
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

typedef struct knh_Path_t knh_Path_t;
typedef void   knh_qconn_t;
typedef knh_uintptr_t knh_io_t;
#define IO_NULL   ((knh_io_t)(NULL))
#define IO_BUF    ((knh_io_t)1)
#define K_STREAM_BUFSIZ  K_PAGESIZE
#define K_OUTBUF_MAXSIZ      (512L * 1024 * 1024)  // 512Mb

#define K_STREAM_NULL      0
#define K_STREAM_INMEMORY  1
#define K_STREAM_STDIO     2
#define K_STREAM_FILE      3
#define K_STREAM_FD        4
#define K_STREAM_NET       5

typedef struct knh_StreamDPI_t {
	int type;
	const char   *name;
	size_t       wbufsiz;  // write bufsize
	knh_bool_t   (*existsSPI)(CTX, struct knh_Path_t *);
	void         (*ospath)(CTX, struct knh_Path_t *, struct knh_NameSpace_t *);
	// stream
	knh_io_t     (*fopenSPI)(CTX, struct knh_Path_t*, const char *, knh_DictMap_t *);
	knh_io_t     (*wopenSPI)(CTX, struct knh_Path_t*, const char *, knh_DictMap_t *);
	knh_intptr_t (*freadSPI)(CTX, knh_io_t, char *, size_t);
	knh_intptr_t (*fwriteSPI)(CTX, knh_io_t, const char *, size_t);
	void         (*fcloseSPI)(CTX, knh_io_t);
	knh_bool_t   (*info)(CTX, knh_io_t, knh_Object_t *);
	int          (*fgetcSPI)(CTX, knh_io_t);
	knh_bool_t   (*fgetlineSPI)(CTX, knh_io_t, knh_Bytes_t *);
	int          (*feofSPI)(CTX, knh_io_t);
	void         (*fflushSPI)(CTX, knh_io_t);

	// query
//	knh_qconn_t*  (*qopen)(CTX, struct knh_Path_t*, knh_DictMap_t *);
//	void          (*qclose)(CTX, struct knh_Path_t*, knh_qconn_t *);
	knh_Fitrnext  qnextData;
} knh_StreamDPI_t;

#ifdef USE_STRUCT_Path
struct knh_Path_t {
	knh_hObject_t h;
	const char               *ospath;
	size_t                    asize;
	struct knh_String_t      *urn;
	const struct knh_StreamDPI_t   *dpi;
};
#endif

/* ------------------------------------------------------------------------ */
//## class InputStream Object;

#define KNH_STDIN          (ctx->in)
#define KNH_STDOUT         (ctx->out)
#define KNH_STDERR         (ctx->err)

typedef struct knh_InputStream_t knh_InputStream_t;
#ifdef USE_STRUCT_InputStream
typedef struct {
	knh_Path_t *path;
	knh_io_t fio;
	union {
		struct knh_Bytes_t  *ba;
		struct knh_String_t *str;
	};
	size_t pos;  size_t posend;
	size_t stat_size;
} knh_InputStreamEX_t;

struct knh_InputStream_t {
	knh_hObject_t h;
	knh_InputStreamEX_t *b;
	knh_uline_t  uline;
	const struct knh_StreamDPI_t  *dpi;
	struct knh_StringDecoder_t*    decNULL;
};
#endif

/* ------------------------------------------------------------------------ */
//## class OutputStream Object;
//## flag OutputStream BOL            1 - is set * *;
//## flag OutputStream AutoFlush      2 - is set is set;
//## flag OutputStream UTF8           3 - has set * *;

typedef struct knh_OutputStream_t knh_OutputStream_t;
#ifdef USE_STRUCT_OutputStream
typedef struct {
	knh_Path_t* path;
	knh_io_t fio;
	struct knh_Bytes_t *ba;
	size_t stat_size;
	knh_String_t*  NEWLINE;
	knh_String_t*  TAB;
	knh_short_t    indent;
} knh_OutputStreamEX_t;

struct knh_OutputStream_t {
	knh_hObject_t h;
	knh_OutputStreamEX_t *b;
	knh_uline_t  uline;
	const struct knh_StreamDPI_t *dpi;
	struct knh_StringEncoder_t* encNULL;
};
#endif

#define knh_putc(ctx, w, ch)       knh_OutputStream_putc(ctx, w, ch)
#define knh_write(ctx, w, s)       knh_OutputStream_write(ctx, w, s)
#define knh_flush(ctx, w)          knh_OutputStream_flush(ctx, w, 0)
#define knh_write_delim(ctx, w)    knh_write_ascii(ctx, w, ", ")
#define knh_write_dots(ctx, w)     knh_write_ascii(ctx, w, "...")
#define knh_write_delimdots(ctx, w)     knh_write_ascii(ctx, w, ", ...")
#define knh_write_fn(ctx, w, fn)   knh_write_ascii(ctx, w, FN__(fn))
#define knh_write__O(ctx, w, o)    knh_write_Object(ctx, w, MN__k, o)

/* ------------------------------------------------------------------------ */
//## class View Object;

typedef struct knh_View_t knh_View_t;

#ifdef USE_STRUCT_View
struct knh_View_t {
	knh_hObject_t h;
	knh_Path_t                   *path;
	knh_DictMap_t                *conf;
};
#endif

/* ------------------------------------------------------------------------ */
//## class NameSpace Object;
typedef struct knh_NameSpace_t knh_NameSpace_t;

#ifdef K_INTERNAL
typedef struct knh_NameSpaceEX_t {
	knh_String_t *nsname;
	struct knh_DictMap_t*   constDictCaseMapNULL;
	struct knh_Array_t *    ffilinksNULL;
	struct knh_DictMap_t   *linkDictMapNULL;

	struct knh_DictSet_t*   name2ctDictSetNULL;
	struct knh_DictMap_t*   name2dpiNameDictMapNULL;
	struct knh_Array_t*     methodsNULL;
	struct knh_Array_t*     formattersNULL;
} knh_NameSpaceEX_t;

struct knh_NameSpace_t {
	knh_hObject_t h;
	knh_NameSpaceEX_t *b;
	struct knh_NameSpace_t   *parentNULL;
	knh_Path_t               *path;
	void                     *gluehdr;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Private @Singleton class Script Object;

typedef struct knh_Script_t knh_Script_t;
#ifdef K_INTERNAL
struct knh_Script_t {
	knh_hObject_t h;
	Object **fields;
	struct knh_NameSpace_t *ns;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Singleton @Struct class System Object;

typedef struct knh_System_t knh_System_t;

struct knh_System_t {
	knh_hObject_t h;
};

/* ------------------------------------------------------------------------ */
//## class Context Object;
//## flag Context Debug        1 ((knh_context_t*)%s)->flag is set is set;
//## flag Context CompileOnly  2 ((knh_context_t*)%s)->flag is set * *;
//## flag Context Interactive  3 ((knh_context_t*)%s)->flag is set * *;

typedef struct knh_Context_t knh_Context_t;
#ifdef K_INTERNAL
struct knh_Context_t {
	knh_hObject_t h;
	const knh_context_t *ctx;
};
#endif

/* ------------------------------------------------------------------------ */
//## class Assurance Object;
//## flag Assurance  CheckedIn        1 - is set * *;

typedef struct knh_Assurance_t knh_Assurance_t;
#ifdef K_INTERNAL
struct knh_Assurance_t {
	knh_hObject_t h;
	struct knh_String_t *msg;
	knh_uintptr_t aid;
	knh_sfp_t *sfp;
	knh_intptr_t stime;
};
#endif

/* ------------------------------------------------------------------------ */
/* konohac.h */

/* ------------------------------------------------------------------------ */
//## @Struct class Token Object;
//## flag Token BOL           0 SP(%s)->flag0 is set * *;
//## flag Token DOT           1 SP(%s)->flag0 is set * *;
//## flag Token NWS           2 SP(%s)->flag0 is set * *;
//## flag Token ISBOOL        3 SP(%s)->flag0 is set * *;
//## flag Token Getter        4 SP(%s)->flag0 is set * *;
//## flag Token Setter        5 SP(%s)->flag0 is set * *;
//## flag Token ExceptionType 6 SP(%s)->flag0 is set * *;
//## flag Token Diamond       7 SP(%s)->flag0 is set * *;
//## flag Token MEMO1         8 SP(%s)->flag0 is set * *;

// TT_BRACE, TT_PARENTHESIS, TT_BRANCET
#define Token_isSAMELINE(o)  Token_isMEMO1(o)
#define Token_setSAMELINE(o, b) Token_setMEMO1(o, b)

// TT_NAME
#define Token_isPNAME(o)      Token_isMEMO1(o)
#define Token_setPNAME(o, b)  Token_setMEMO1(o, b)

// TT_UNAME
#define Token_isBYTE(o)       Token_isMEMO1(o)
#define Token_setBYTE(o, b)   Token_setMEMO1(o, b)

// TT_URN
#define Token_isDYNAMIC(o)  Token_isMEMO1(o)
#define Token_setDYNAMIC(o, b) Token_setMEMO1(o, b)

// TT_LVAR,
#define Token_isSUPER(o)      Token_isMEMO1(o)
#define Token_setSUPER(o, b)  Token_setMEMO1(o, b)

// TT_LVAR, TT_FIELD, TT_SCRIPT
#define Token_isReadOnly(tk)   Token_isBOL(tk)
#define Token_setReadOnly(tk, b)   Token_setBOL(tk, b)

typedef knh_ushort_t   knh_term_t;

typedef struct knh_Term_t knh_Term_t;
#ifdef K_INTERNAL
struct knh_Term_t {
	knh_hObject_t h;
	void *ref;
	knh_uline_t uline;                   //Term
	knh_type_t type; knh_term_t  tt;     //Term
};
#endif

#define Term_isTyped(o)     (o->type != TYPE_var)

typedef struct knh_Token_t knh_Token_t;
#ifdef K_INTERNAL
struct knh_Token_t {
	knh_hObject_t h;
	union {
		Object* data;
		struct knh_Array_t   *list;
		struct knh_String_t  *text;
		struct knh_Token_t   *token;
		struct knh_Stmt_t    *stmt;
		struct knh_Method_t  *mtd;
		struct knh_TypeMap_t *mpr;
		struct knh_Token_t   *tkIDX;
		struct knh_Int_t     *num;
	};
	knh_uline_t uline;                  // Term
	knh_type_t type; knh_term_t  tt;    // Term
	knh_flag_t   flag0;
	union {
		knh_short_t   index;
		knh_class_t   cid;
		knh_methodn_t mn;
	};
};
#endif

#define Token_isTyped(o)    (SP(o)->type != TYPE_var)
#define new_TokenCONST(ctx, d)  new_TokenCONST_(ctx, UPCAST(d))
#define new_TermCONST(ctx, d)   TM(new_TokenCONST_(ctx, UPCAST(d)))

/* ------------------------------------------------------------------------ */
//## @Struct class Stmt Object;
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

typedef struct knh_Stmt_t knh_Stmt_t;
#ifdef K_INTERNAL
typedef struct {
	knh_flag_t   flag0;   knh_ushort_t espidx;
	knh_ushort_t size;    knh_ushort_t capacity;
	union {
		struct knh_DictMap_t* metaDictCaseMap;
		struct knh_String_t*  errMsg;
		struct knh_Stmt_t*    stmtPOST;
	};
	struct knh_Stmt_t* nextNULL;
} knh_StmtEX_t;

struct knh_Stmt_t {
	knh_hObject_t h;
	knh_StmtEX_t *b;
	knh_uline_t uline;                 // Term
	knh_type_t type; knh_term_t  stt;  // Term
	union {
		struct knh_Term_t**  terms;
		struct knh_Token_t** tokens;
		struct knh_Stmt_t**  stmts;
	};
};
#endif

#define Stmt_isTyped(o)        ((o)->type != TYPE_var)

/* ------------------------------------------------------------------------ */
//## @Struct @Private class Gamma Object;
//## flag Gamma EnforceConst  0 DP(%s)->flag is  set   * *;
//## flag Gamma Quiet         1 DP(%s)->flag is  set   * *;
//## flag Gamma Throwable     2 DP(%s)->flag is  set   * *;
//## flag Gamma PROCEED       3 DP(%s)->flag has found * *;
//## flag Gamma REGISTER      4 DP(%s)->flag has found * *;
//## flag Gamma YEILD         5 DP(%s)->flag has found * *;
//## flag Gamma FIELD         6 DP(%s)->flag has found * *;
//## flag Gamma LexicalScope  7 DP(%s)->flag has found * *;
//## flag Gamma SCRIPT        8 DP(%s)->flag has found * *;

//## flag Gamma InlineFunction  0 DP(%s)->cflag is set * *;
//## flag Gamma TailRecursion   1 DP(%s)->cflag is set * *;

#ifndef K_GAMMAMAX
#define K_GAMMAMAX 64
#endif

typedef struct knh_Gamma_t knh_Gamma_t;

#ifdef K_INTERNAL
typedef knh_short_t knh_gint_t;
typedef struct {
	knh_flag_t    flag;  knh_term_t    ucnt;
	knh_type_t    type;  knh_fieldn_t  fn;
	union {
		knh_Token_t   *tkIDX;
	};
	union {
		knh_Token_t   *tk;
		knh_Stmt_t    *stmt;
	};
} knh_gamma2_t ;

#define K_GMASCR   ((ctx->gma)->scr)
#define K_GMANS    ((ctx->gma)->scr->ns)

typedef struct knh_GammaEX_t {
	knh_flag_t                 flag;
	knh_flag_t                 cflag;
	struct knh_Stmt_t*         stmt;
	struct knh_Method_t*       mtd;
	knh_class_t                this_cid;
	knh_gint_t                 funcbase0;

	/*gamma*/
	knh_gamma2_t*             gf;
	knh_gint_t                gsize;
	knh_gint_t                gcapacity;
	knh_gint_t                psize; /* param size */
	knh_gint_t                fvarsize;

	knh_Token_t              *tkScriptNC;
	knh_Token_t              *tkFuncThisNC;
	knh_Method_t             *proceedNC;  /*@Around*/

	struct knh_BasicBlock_t    *bbNC;
	struct knh_Array_t         *insts;  // bbNC->listNC
	struct knh_Array_t         *lstacks;
	struct knh_Stmt_t          *finallyStmt;
	struct knh_Array_t         *errmsgs;
	void  *asm_data;           // what is this?
} knh_GammaEX_t;

struct knh_Gamma_t {
	knh_hObject_t h;
	knh_GammaEX_t *b;
	knh_uline_t uline;         // same as Term
	knh_Script_t *scr;
};
#endif

typedef knh_bool_t (*knh_Ftyping)(CTX, knh_Method_t *, knh_Stmt_t *);

///* ------------------------------------------------------------------------ */

typedef knh_uintptr_t          knh_opcode_t;
typedef knh_intptr_t           knh_sfpidx_t;
typedef knh_intptr_t           knh_r_t;
typedef knh_intptr_t           knh_ro_t;
typedef knh_intptr_t           knh_rn_t;
typedef void*                  knh_dummyptr_t;
struct knh_opline_t;
typedef struct knh_opline_t knh_opline_t;

#ifdef K_INTERNAL
#define klr_Ffcall    knh_Fmethod
typedef void (*klr_Fth)(CTX, struct knh_opline_t *, void**);
struct klr_LDMTD_t;
typedef void (*klr_Floadmtd)(CTX, knh_sfp_t *, struct klr_LDMTD_t *);
typedef long   (*klr_Finttr)(long u);
typedef double (*klr_Ffloattr)(double u);
typedef void (*klr_Ftr)(CTX, knh_sfp_t*, knh_sfpidx_t, const knh_ClassTBL_t *);
typedef void (*klr_Fcheckin)(CTX, knh_sfp_t *, struct knh_RawPtr_t *);
typedef void (*klr_Fcheckout)(CTX, struct knh_RawPtr_t *, int);
struct klr_P_t;
typedef void (*klr_Fprint)(CTX, knh_sfp_t*, struct klr_P_t*);
struct klr_PROBE_t;
typedef void (*klr_Fprobe)(CTX, knh_sfp_t* , struct klr_PROBE_t *pc);

typedef struct {
	knh_dummyptr_t _d1;
	knh_dummyptr_t _d2;
	knh_dummyptr_t _d3;
	knh_dummyptr_t _d4;
	knh_dummyptr_t _d5;
} knh_opdummy_t;

typedef struct {
	knh_sfpidx_t i;
	knh_sfpidx_t n;
} knh_sfx_t;

#if defined(K_USING_THCODE_)
#define KCODE_HEAD \
	void *codeaddr; \
	size_t count; \
	knh_ushort_t opcode; \
	knh_ushort_t line

#else
#define KCODE_HEAD \
	size_t count; \
	knh_opcode_t opcode; \
	knh_uintptr_t line \

#endif/*K_USING_THCODE_*/

struct knh_opline_t {
	KCODE_HEAD;
	union {
		knh_intptr_t data[5];
		void *p[5];
		knh_uchar_t *u[5];
	};
};
#endif

#define DBG_ASSERT_OPCODE(c) \
	if(((knh_opcode_t)c) >= OPCODE_MAX) {\
		DBG_P("Invalid opcode=%d", (int)c); \
		DBG_ASSERT(c < OPCODE_MAX); \
	}\

/* ------------------------------------------------------------------------ */
//## class BasicBlock Object;
//## flag BasicBlock Visited  1 - is set  *   *;
//## flag BasicBlock StackChecked 2 - is set * *;

typedef struct knh_BasicBlock_t knh_BasicBlock_t;
#ifdef K_INTERNAL
typedef struct knh_BasicBlockEX_t {
	knh_ushort_t id;     knh_ushort_t incoming;
	knh_opline_t *opbuf;
	knh_ushort_t size;   knh_ushort_t capacity;
	knh_ushort_t bottom; knh_ushort_t top;
	knh_opline_t *code;
	knh_opline_t *opjmp;
} knh_BasicBlockEX_t ;

struct knh_BasicBlock_t {
	knh_hObject_t h;
	knh_BasicBlockEX_t *b;
	struct knh_Array_t *listNC;
	struct knh_BasicBlock_t *nextNC;
	struct knh_BasicBlock_t *jumpNC;
};
#endif

/* ------------------------------------------------------------------------ */
//## class KonohaCode Object;
//## flag KonohaCode NativeCompiled  1 - is set  *   *;

typedef struct knh_KonohaCode_t knh_KonohaCode_t;
#ifdef K_INTERNAL
struct knh_KonohaCode_t {
	knh_hObject_t h;
	knh_opline_t*  code;
	size_t        codesize;
	knh_String_t *source;
	knh_uri_t     uri; knh_uri_t     domain;
};
#endif

/* ------------------------------------------------------------------------ */
//## @Immutable class Immutable Object;

typedef struct knh_Immutable_t {
	knh_hObject_t h;
} knh_Immutable_t;

/* ------------------------------------------------------------------------ */
//## class KindOf Object;

typedef struct knh_KindOf_t {
	knh_hObject_t h;
} knh_KindOf_t;

/* ------------------------------------------------------------------------ */
//## class Tdynamic Object;

typedef void (*knh_Frawfree)(void *);

typedef struct knh_RawPtr_t {
	knh_hObject_t h;
	void *rawptr;
	struct knh_Object_t **kfields;  // c++
	const char *DBG_NAME;
	knh_Frawfree rawfree;
} knh_RawPtr_t ;

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
	if(unlikely(n == K_FLOAT_ZERO)) { \
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

#define klr_setesp(ctx, newesp)  ((knh_context_t*)ctx)->esp = (newesp)
#define klr_setmtdNC(ctx, sfpA, mtdO)   sfpA.mtdNC = mtdO

#define Method_isKonohaCode(mtd) ((mtd)->fcall_1 == knh_Fmethod_runVM)

#define Gamma_hasJIT(ctx)     0
#define CODE_VEXEC     (ctx->share->PRECOMPILED_VEXEC)
#define CODE_LAUNCH    (ctx->share->PRECOMPILED_LAUNCH)
#define CODE_FUNCCALL  (ctx->share->PRECOMPILED_FUNCCALL)
//#define CODE_ABSTRACT  (ctx->share->PC_ABSTRACT)

#define KNH_SCALL(ctx, lsfp, rtnidx, mtdO, argc) { \
		knh_intptr_t thisidx_ = rtnidx+ K_CALLDELTA;\
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
		knh_intptr_t thisidx_ = rtnidx+ K_CALLDELTA;           \
		KNH_SETv(ctx, lsfp[thisidx].o, fo);                    \
		if (fo->baseNULL != NULL) {					           \
			KNH_SETv(ctx, lsfp[thisidx].o, fo->baseNULL);      \
		}												       \
		klr_setmtdNC(ctx, lsfp[thisidx_+K_MTDIDX], fo->mtd);   \
		klr_setesp(ctx, lsfp + thisidx_ + argc + 1);           \
		KNH_SELFCALL(ctx, lsfp, fo->mtd, K_RTNIDX);            \
	}                                                          \

#define BEGIN_LOCAL(ctx, lsfp, n) \
		knh_sfp_t *lsfp = knh_stack_local(ctx, n);\
		KNH_SAFEPOINT(ctx, lsfp); \
		int sfpidx_ = lsfp - ctx->stack;\

#define BEGIN_UNSAFELOCAL(ctx, lsfp, n) \
		knh_sfp_t *lsfp = knh_stack_local(ctx, n); \
		int sfpidx_ = lsfp - ctx->stack;\

#ifdef __cplusplus
#define __CONST_CAST__(T, expr) (const_cast<T>(expr))
#else
#define __CONST_CAST__(T, expr) ((T)expr)
#endif

#define END_LOCAL(ctx, lsfp) \
	(__CONST_CAST__(knh_context_t*, ctx))->esp = ctx->stack + sfpidx_;\


#define LOCAL_NEW(ctx, lsfp, n, T, V, O) \
	T V = O;\
	KNH_SETv(ctx, lsfp[n].o, V);\

#define KNH_SECURE(ctx, sfp) knh_checkSecurityManager(ctx, sfp)

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif

#endif /*CLASS_KONOHA_H_*/

