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

#ifndef KONOHA_T_H_
#define KONOHA_T_H_

#include"konoha_config.h"

#ifdef K_USING_STDC_
#include<stdio.h>
#include<limits.h>
#include<float.h>
//#include<setjmp.h>

#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS
#endif
#include<stdint.h>
#define __STDC_FORMAT_MACROS
#include<inttypes.h>
#endif

#if defined(K_USING_PTHREAD)
	#include<pthread.h>
#endif

#if defined(K_USING_SIGNAL)
#ifdef K_USING_POSIX_
#include<signal.h>
#endif
#endif

#if defined(K_USING_WINDOWS_)
#include <winsock2.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */

#define K_SYSTEMBIT       (sizeof(void*) * CHAR_BIT)

typedef int16_t           knh_int16_t;
typedef uint16_t          knh_uint16_t;
typedef int32_t           knh_int32_t;
typedef uint32_t          knh_uint32_t;
typedef int64_t           knh_int64_t;
typedef uint64_t          knh_uint64_t;

typedef intptr_t          knh_intptr_t;
typedef uintptr_t         knh_uintptr_t;
typedef knh_intptr_t      knh_index_t;

#define K_INTPTR_FMT      "%"PRIdPTR
#define K_INTPTR_UFMT     "%"PRIuPTR

#if defined(__LP64__) || defined(_WIN64)
#define K_USING_64_    1
typedef int32_t           knh_short_t;
typedef uint32_t          knh_ushort_t;
typedef uintptr_t         knh_ndata_t;
#ifndef K_USING_NOFLOAT
typedef double            knh_floatptr_t;
#endif
#undef K_USING_INT32
#else
typedef int16_t           knh_short_t;
typedef uint16_t          knh_ushort_t;
#if defined(K_USING_INT32)
typedef uint32_t          knh_ndata_t;
#else
typedef uint64_t          knh_ndata_t;
#define K_USING_DBLNDATA_  1
#endif
#ifndef K_USING_NOFLOAT
typedef float             knh_floatptr_t;
#endif
#endif

#ifdef K_USING_DBLNDATA_   /*virtual machine*/
#define VMTX_INT  ,VMT_VOID
#define VMTSIZE_int 1
#define VMTX_FLOAT  ,VMT_VOID
#define VMTSIZE_float 1
#define DBLNDATA_(STMT)    STMT
#else
#define VMTX_INT
#define VMTSIZE_int 0
#define VMTX_FLOAT
#define VMTSIZE_float 0
#define DBLNDATA_(STMT)
#endif

/* ------------------------------------------------------------------------ */
/* Bool(ean), knh_bool_t */
/* ------------------------------------------------------------------------ */

typedef knh_intptr_t      knh_bool_t;
typedef knh_intptr_t      knh_boolean_t;

typedef enum {
	K_BREAK, K_CONTINUE, K_REDO
} knh_status_t;

/* ------------------------------------------------------------------------ */
/* Integer, knh_int_t */
/* ------------------------------------------------------------------------ */

#ifdef K_USING_INT32
typedef long                knh_int_t;
typedef unsigned long       knh_uint_t;

#define K_INT_MAX               LONG_MAX
#define K_INT_MIN               LONG_MIN
#define K_INT0                  0UL
#define K_INT_FMT               "%ld"
#define K_INT_XFMT              "%lx"
#define K_UINT_MAX              ULONG_MAX
#define K_UINT_MIN              0
#define K_UINT_FMT              "%lu"
#define knh_abs(n)              labs(n)
#define VMTX_INT
#define VMTSIZE_int 0

#else /*K_USING_INT32*/

typedef knh_int64_t        knh_int_t;
typedef knh_uint64_t       knh_uint_t;

#ifndef LLONG_MIN
#define LLONG_MIN -9223372036854775807LL
#define LLONG_MAX  9223372036854775807LL
#endif

#ifndef ULLONG_MAX
#define ULLONG_MAX 18446744073709551615ULL
#endif

#define K_INT_MAX               LLONG_MAX
#define K_INT_MIN               LLONG_MIN
#define K_INT_FMT               "%lld"
#define K_INT_XFMT              "%llx"
#define K_INT0                  0ULL
#define K_UINT_MAX              ULLONG_MAX
#define K_UINT_MIN              0ULL
#define K_UINT_FMT              "%llu"
#define knh_abs(n)              llabs(n)

#endif/*K_USING_INT32*/

#define K_INT_FMTSIZ            40

/* ------------------------------------------------------------------------ */
/* Float, knh_float_t */
/* ------------------------------------------------------------------------ */

#ifdef K_USING_NOFLOAT
/* dummy */
typedef long                    knh_float_t;
typedef long                    knh_floatptr_t;

#define K_FLOAT_MAX             0
#define K_FLOAT_MIN             0
#define K_FLOAT_STEP            0
#define K_FLOAT_FMT             "%d"
#define K_FLOAT_FMT1            "%d"
#define K_FLOAT_FMT2            "%d"
#define K_FLOAT_FMT3            "%d"
#define K_FLOAT_FMT4            "%d"
#define K_FLOAT_FMTE            "%d"
#define K_FLOAT_NAN             0
#define K_FLOAT_NULL            K_FLOAT_NAN
#define K_FLOAT_FMTSIZ          40
#define K_FLOAT_ZERO            0
#define K_FLOAT_ONE             1
#else
#define K_FLOAT_ZERO            0.0
#define K_FLOAT_ONE             1.0
#endif/*K_USING_NOFLOAT*/

#if defined(K_USING_INT32) && !defined(K_FLOAT_FMT)
typedef float                   knh_float_t;
#define K_FLOAT_MAX             FLT_MAX
#define K_FLOAT_MIN             (-(FLT_MAX))
#define K_FLOAT_STEP            FLT_MIN
#define K_FLOAT_EPSILON         FLT_EPSILON
#define K_FLOAT_FMT             "%.6f"
#define K_FLOAT_FMT1            "%.1f"
#define K_FLOAT_FMT2            "%.2f"
#define K_FLOAT_FMT3            "%.3f"
#define K_FLOAT_FMT4            "%.4f"
#define K_FLOAT_FMTE            "%e"
#endif

#ifndef K_FLOAT_FMT
typedef double                  knh_float_t;
#define K_FLOAT_MAX             DBL_MAX
#define K_FLOAT_MIN             (-(DBL_MAX))
#define K_FLOAT_STEP            DBL_MIN
#define K_FLOAT_EPSILON         DBL_EPSILON
#define K_FLOAT_FMT             "%.20f"
#define K_FLOAT_FMT1            "%.20f"
#define K_FLOAT_FMT2            "%.20f"
#define K_FLOAT_FMT3            "%.20f"
#define K_FLOAT_FMT4            "%.20f"
#define K_FLOAT_FMTE            "%e"
#endif

#ifndef K_FLOAT_NAN
#define K_FLOAT_NAN             (0.0/0.0)
#define K_FLOAT_NULL            K_FLOAT_NAN
#define K_FLOAT_FMTSIZ          80
#endif /*K_FLOAT_NAN*/

/* ------------------------------------------------------------------------ */
/* String, knh_uchar_t */
/* ------------------------------------------------------------------------ */

typedef unsigned char           knh_uchar_t;    /* byte */
typedef const char              knh_text_t;
typedef const unsigned char     knh_utext_t;

typedef struct {
	union {
		const char *text;
		const unsigned char *utext;
		char *buf;
		knh_uchar_t *ubuf;
	};
	size_t       len;
} knh_bytes_t;

#define ismulti(c)             (((knh_uchar_t)c)>127)

#define B(c)      new_bytes((char*)c)
#define STEXT(c)  new_bytes2(c,sizeof(c)-1)
#define ISB(t,c) (t.len == (sizeof(c)-1) && knh_strncmp(t.text, c, t.len) == 0)

/* ------------------------------------------------------------------------ */
/* knh_flag_t */
/* ------------------------------------------------------------------------ */

typedef knh_ushort_t              knh_flag_t;    /* flag field */
#define K_FLAG_H(N)               ((sizeof(knh_flag_t)*8)-N)
#define K_FLAG_H0                 ((knh_flag_t)(1 << K_FLAG_H(1)))
#define K_FLAG_H1                 ((knh_flag_t)(1 << K_FLAG_H(2)))
#define K_FLAG_H2                 ((knh_flag_t)(1 << K_FLAG_H(3)))
#define K_FLAG_H3                 ((knh_flag_t)(1 << K_FLAG_H(4)))
#define K_FLAG_H4                 ((knh_flag_t)(1 << K_FLAG_H(5)))
#define K_FLAG_H5                 ((knh_flag_t)(1 << K_FLAG_H(6)))
#define K_FLAG_H6                 ((knh_flag_t)(1 << K_FLAG_H(7)))
#define K_FLAG_H7                 ((knh_flag_t)(1 << K_FLAG_H(8)))

#define TFLAG_is(T,f,op)          (((T)(f) & (T)(op)) == (T)(op))
#define TFLAG_set1(T,f,op)        f = (((T)(f)) | ((T)(op)))
#define TFLAG_set0(T,f,op)        f = (((T)(f)) & (~((T)(op))))
#define TFLAG_set(T,f,op,b)       if(b) {TFLAG_set1(T,f,op);} else {TFLAG_set0(T,f,op);}
#define TFLAG_setNOT(T,f,op,b)    if(!(b)) {TFLAG_set0(T,f,op);} else {TFLAG_set1(T,f,op);}

#define FLAG_set(f,op)            TFLAG_set1(knh_flag_t,f,op)
#define FLAG_unset(f,op)          TFLAG_set0(knh_flag_t,f,op)
#define FLAG_is(f,op)             TFLAG_is(knh_flag_t,f,op)

/* ------------------------------------------------------------------------ */
/* Struct, Class, Type  */
/* ------------------------------------------------------------------------ */

struct knh_context_t;
#define CTX const struct knh_context_t *const

typedef knh_ushort_t       knh_class_t;  /* class id */
typedef knh_ushort_t       knh_type_t;   /* extended knh_type_t */
typedef knh_ushort_t       knh_event_t;    /* knh_event_t */

/* knh_class_t */
#define CLASS_newid                ((knh_class_t)-1)
#define CLASS_unknown              ((knh_class_t)-2)

#define DBG_ASSERT_cid(cid)        DBG_ASSERT(cid < ctx->share->sizeClassTBL)

/* knh_type_t */
#define TYPE_void           CLASS_Tvoid
#define TYPE_T0             ((knh_type_t)30000)
#define TYPE_This           TYPE_T0
#define TYPE_T(n)           (TYPE_T0+(n))
#define TYPE_T1             TYPE_T(1)
#define TYPE_T2             TYPE_T(2)
#define TYPE_T3             TYPE_T(3)
#define TYPE_T4             TYPE_T(4)

#define CLASS_t(t)          (((t) >= TYPE_This) ? CLASS_Object : (t))
#define TYPE_cid(t)         (t)

//#define IS_Tfield(t)      (ClassTBL(CLASS_t(t))->bcid == CLASS_Object)
#define IS_Tint(t)        (t == CLASS_Int || ClassTBL(CLASS_t(t))->bcid == CLASS_Int)
#define IS_Tfloat(t)      (t == CLASS_Float || ClassTBL(CLASS_t(t))->bcid == CLASS_Float)
#define IS_Tbool(t)       (TYPE_Boolean == t)
#define IS_Tunbox(t)      (IS_Tint(t) || IS_Tfloat(t) || IS_Tbool(t))
#define IS_Tfunc(t)       (ClassTBL(CLASS_t(t))->bcid == CLASS_Func)
#define IS_Tstr(t)        (t == CLASS_String || ClassTBL(CLASS_t(t))->bcid == CLASS_String)
#define IS_Tvany(t)       (t == CLASS_Tdynamic || t == TYPE_var || t == TYPE_void)

#define ClassTBL_isa(t, reqt)   (t->cid == reqt || ClassTBL_isa_(ctx, t, ClassTBL(reqt)))
#define class_isa(cid, reqt)    (cid == reqt || ClassTBL_isa_(ctx, ClassTBL(cid), ClassTBL(reqt)))

#define CLASS__(cid)               SAFECLASS__(ctx, cid)
#define STRUCT__(bcid)             SAFESTRUCT__(ctx, bcid)
#define O__(o)                     S_totext(O_cTBL(o)->sname)
#define TYPE__(type)               SAFETYPE__(ctx,type)

/* knh_event_t */
#define EVENT_unknown            ((knh_event_t)-1)
#define EVENT_newid              ((knh_event_t)0)
#define ASSERT_ebi(eid)        DBG_ASSERT(eid < ctx->share->sizeEventTBL + 1)
#define EVENT__(eid)             S_totext(knh_getEventName(ctx, eid))

/* ------------------------------------------------------------------------ */

typedef knh_ushort_t          knh_fieldn_t;
typedef knh_ushort_t          knh_methodn_t;

#define FN_NONAME    ((knh_fieldn_t)-1)
#define FN_NEWID     ((knh_fieldn_t)-2)
#define FN_return    FN_

#define MN_NONAME    ((knh_methodn_t)-1)
#define MN_NEWID     ((knh_methodn_t)-2)

#define K_FLAG_FN_U1         K_FLAG_H0
#define K_FLAG_FN_U2         K_FLAG_H1
#define K_FLAG_FN_SUPER      (K_FLAG_H0|K_FLAG_H1)

#define FN_isSUPER(fnq)      ((fnq & K_FLAG_FN_SUPER) == K_FLAG_FN_SUPER)
#define FN_isU1(fnq)         ((fnq & K_FLAG_FN_U1) == K_FLAG_FN_U1)
#define FN_isU2(fnq)         ((fnq & K_FLAG_FN_U2) == K_FLAG_FN_U2)

#define K_FLAG_FN_REF        K_FLAG_H0
#define K_FLAG_FN_NEMPTY     K_FLAG_H1
#define K_FLAG_FN_SYSTEM     K_FLAG_H2

#define FN_UNMASK(fnq)       (fnq & (~(K_FLAG_H0|K_FLAG_H1|K_FLAG_H2)))

#define K_FLAG_MN_ISBOOL     K_FLAG_H0
#define K_FLAG_MN_GETTER     K_FLAG_H1
#define K_FLAG_MN_SETTER     K_FLAG_H2
#define K_FLAG_MN_FMT        (K_FLAG_H0|K_FLAG_H1|K_FLAG_H2)
#define K_FLAG_MN_FIELDN     (~K_FLAG_MN_FMT)

#define MN_isISBOOL(mn)   ((mn & K_FLAG_MN_FMT) == K_FLAG_MN_ISBOOL)
#define MN_toISBOOL(mn)   (mn | K_FLAG_MN_ISBOOL)
#define MN_isGETTER(mn)   ((mn & K_FLAG_MN_FMT) == K_FLAG_MN_GETTER)
#define MN_toGETTER(mn)   (mn | K_FLAG_MN_GETTER)
#define MN_isSETTER(mn)   ((mn & K_FLAG_MN_FMT) == K_FLAG_MN_SETTER)
#define MN_toSETTER(mn)   (mn | K_FLAG_MN_SETTER)
#define MN_isFMT(mn)      ((mn & K_FLAG_MN_FMT) == K_FLAG_MN_FMT)
#define MN_toFMT(mn)      (mn | K_FLAG_MN_FMT)

#define MN_toFN(mn)       (mn & K_FLAG_MN_FIELDN)

#define MN_LAMBDA          FN_

const char *knh_getopname(knh_methodn_t mn);
#define FN__(fn)          S_totext(knh_getFieldName(ctx, fn))
#define MN__(mn)          knh_getmnname(ctx, mn)

/* ------------------------------------------------------------------------ */
/* Object */
/* ------------------------------------------------------------------------ */

#define K_OBJECT_MAGIC        (578L << ((sizeof(knh_flag_t)*8)+1))
#define K_CFLAGMASK           (FLAG_Object_Ref)
#define KNH_MAGICFLAG(f)      (K_OBJECT_MAGIC | ((knh_uintptr_t)(f) & K_CFLAGMASK))
#define DBG_ASSERT_ISOBJECT(o)   DBG_ASSERT(TFLAG_is(knh_uintptr_t,(o)->h.magicflag, K_OBJECT_MAGIC))

#ifdef K_USING_RCGC
#define KNH_HOBJECT_REFC      1
#endif

typedef struct knh_hObject_t {
	knh_uintptr_t magicflag;
	const struct knh_ClassTBL_t *cTBL;
	union {
		knh_uintptr_t refc;
		knh_uintptr_t mscheck;
		void *gcinfo;
	};
	void *meta;   // reserved for traits
} knh_hObject_t ;

typedef struct knh_Object_t {
	knh_hObject_t h;
	void *ref;
	void *ref2_unused;
	void *ref3_unused;
	struct knh_Object_t *ref4_tail;  // this is used for tailing ObjectArena
} knh_Object_t ;

#define K_FASTMALLOC_SIZE     sizeof(knh_Object_t)

#define SP(o)               (o)
#define DP(o)               ((o)->b)
#define _(s)          s

#define knh_bodycpy(o, s) \
	o->ref = s->ref;\
	o->ref2_unused = s->ref2_unused;\
	o->ref3_unused = s->ref3_unused;\
	o->ref4_tail   = s->ref4_tail;\

#define knh_bodyextcpy(o, s) \
	o->ref2_unused = s->ref2_unused;\
	o->ref3_unused = s->ref3_unused;\
	o->ref4_tail   = s->ref4_tail;\

/* types of basic objects (not type-checked) */

#define Object          struct knh_Object_t
#define dynamic         struct knh_Object_t
//#define This          knh_Object_t
//#define T1            knh_Object_t
//#define T2            knh_Object_t
#define UPCAST(o)       (knh_Object_t*)(o)
#define RAWPTR(o)       (knh_RawPtr_t*)(o)

#define knh_Object_toNULL(ctx, o)   knh_Object_toNULL_(ctx, UPCAST(o))
#define O_data(o)       (((knh_Int_t*)(o))->n.data)

/* ------------------------------------------------------------------------ */
/* Common Object Structure */

typedef knh_ushort_t              knh_uri_t;
#define URI_unknown               ((knh_uri_t)-1)
#define URI_EVAL                  ((knh_uri_t)0)
#define URI_UNMASK(uri)           (uri)

#define URI__(uri) S_totext(knh_getURN(ctx, uri))
#define FILENAME__(uri) knh_sfile(URI__(uri))

typedef knh_uintptr_t             knh_uline_t;
#define new_ULINE(uri, line)       ((((knh_uline_t)uri) << (sizeof(knh_uri_t) * 8)) | ((knh_ushort_t)line))
#define ULINE_setURI(line, uri)    line |= (((knh_uline_t)uri) << (sizeof(knh_uri_t) * 8))
#define ULINE_uri(line)            ((knh_uri_t)(line >> (sizeof(knh_uri_t) * 8)))
#define ULINE_line(line)           (line & (knh_uline_t)((knh_uri_t)-1))

/* ------------------------------------------------------------------------ */
/* Thread */
/* ------------------------------------------------------------------------ */

#if defined(K_USING_WINTHREAD_)
#define knh_thread_t HANDLE
#define knh_thread_key_t DWORD
#define knh_mutex_t CRITICAL_SECTION
#elif defined(K_USING_PTHREAD)
#define knh_thread_t pthread_t
#define knh_thread_key_t pthread_key_t
#define knh_mutex_t pthread_mutex_t
#elif defined(K_USING_BTRON)
#define knh_thread_t W
#define knh_thread_key_t W
#define knh_mutex_t W
#else
typedef knh_intptr_t knh_thread_t;
typedef knh_intptr_t knh_thread_key_t;
typedef knh_intptr_t knh_mutex_t;
#endif

typedef void *(*knh_Fthread)(void *);

#define OLD_LOCK(ctx, lockid, o)
#define OLD_UNLOCK(ctx, lockid, o)

#define KNH_MEMLOCK(ctx)   knh_mutex_lock(ctx->share->memlock)
#define KNH_MEMUNLOCK(ctx) knh_mutex_unlock(ctx->share->memlock)
#define KNH_SYSLOCK(ctx)   knh_mutex_lock(ctx->share->syslock)
#define KNH_SYSUNLOCK(ctx) knh_mutex_unlock(ctx->share->syslock)
#define KNH_CTXLOCK(ctx)   knh_mutex_lock(ctx->ctxlock)
#define KNH_CTXUNLOCK(ctx) knh_mutex_unlock(ctx->ctxlock)
 
/* ------------------------------------------------------------------------ */
/* Stack Frame Pointer */
/* ------------------------------------------------------------------------ */

#define ASSERT_SFP(sfp)  KNH_ASSERT(((((knh_rbp_t*)sfp) - ((knh_rbp_t*)(ctx->stack))) % 2) == 0)

#define K_FRAME_NCMEMBER \
		knh_ndata_t   ndata;  \
		knh_bool_t    bvalue; \
		knh_int_t     ivalue; \
		knh_uint_t    uvalue; \
		knh_float_t   fvalue; \
		knh_intptr_t  shift;  \
		struct knh_opline_t     *pc; \
		struct knh_Method_t     *mtdNC; \
		struct knh_TypeMap_t    *tmrNC; \
		struct knh_sfp_t *env \

#define K_FRAME_MEMBER \
		Object *o; \
		struct knh_Int_t    *i; \
		struct knh_Float_t  *f; \
		struct knh_Class_t  *c; \
		struct knh_String_t *s; \
		struct knh_Date_t *dt;\
		struct knh_Bytes_t  *ba; \
		struct knh_Regex_t  *re; \
		struct knh_Range_t  *range; \
		struct knh_Array_t  *a; \
		struct knh_Iterator_t *it; \
		struct knh_Map_t           *m;    \
		struct knh_Func_t         *fo; \
		struct knh_Path_t         *pth; \
		struct knh_InputStream_t  *in; \
		struct knh_OutputStream_t *w;  \
		struct knh_View_t *rel;\
		struct knh_Method_t            *mtd;\
		struct knh_TypeMap_t           *tmr;\
		struct knh_Exception_t         *e;\
		struct knh_ExceptionHandler_t  *hdr; \
		struct knh_NameSpace_t         *ns;\
		struct knh_RawPtr_t   *p; \
		struct knh_ObjectField_t *ox; \
		struct knh_Converter_t         *conv;\
		struct knh_Context_t           *cx;\
		struct knh_Script_t            *scr;\
		struct knh_Assurance_t         *as;\
		knh_int_t     dummy_ivalue;\
		knh_float_t   dummy_fvalue \

typedef struct knh_sfp_t {
	union {
		K_FRAME_MEMBER;
	};
	union {
		K_FRAME_NCMEMBER;
	};
} knh_sfp_t;

#define K_USING_RBP_                  1

#ifdef K_USING_RBP_
typedef struct knh_rbp_t {
	union {
		K_FRAME_NCMEMBER;
		K_FRAME_MEMBER;
	};
} knh_rbp_t;
#else
typedef struct knh_rbp_t {
	union {
		K_FRAME_NCMEMBER;
	};
	union {
		K_FRAME_MEMBER;
	};
} knh_rbp_t;
#endif

/* ------------------------------------------------------------------------ */
/* [ObjectFunc] */

#define O_hasRef(o)   (1/*O_cTBL(o)->fast_reftrace != NONE_reftrace*/)

typedef void (*knh_Ftraverse)(CTX, Object *);
#define K_USING_FASTREFS_  1

#define FTRARG    , knh_Object_t** tail_
#define FTRDATA   , tail_

#define KNH_ENSUREREF(ctx, SIZE)  tail_ = knh_ensurerefs(ctx, tail_, SIZE)

#define KNH_ADDREF(ctx, p)  {\
		DBG_ASSERT(p != NULL);\
		tail_[0] = (Object*)p;\
		tail_++;\
	}\

#define KNH_ADDNNREF(ctx, p)  if(p != NULL) {\
		tail_[0] = (Object*)p;\
		tail_++;\
	}\

#define KNH_SIZEREF(ctx)  {\
		((knh_context_t*)ctx)->ref_size = (tail_ - ctx->ref_buf);\
	}\

#define KNH_SETREF(ctx, LIST, SIZE)  {\
		((knh_context_t*)ctx)->refs = LIST;\
		((knh_context_t*)ctx)->ref_size = SIZE;\
	}\

#define KNH_ADDREF2(ctx, p)  {\
		ctx->refs[ctx->ref_size] = (Object*)p;\
		((knh_context_t*)ctx)->ref_size++;\
		tail_++;\
	}\

#define KNH_ADDNNREF2(ctx, p)  if(p != NULL) {\
		ctx->refs[ctx->ref_size] = (Object*)p;\
		((knh_context_t*)ctx)->ref_size++;\
		tail_++;\
	}\

#define KNH_SIZEREF2(ctx)  {\
		KNH_ASSERT(ctx->ref_size == (tail_ - ctx->refs));\
	}\

typedef void (*knh_Freftrace)(CTX, Object * FTRARG);

typedef knh_uintptr_t                knh_hashcode_t;  /* knh_hashcode_t */
#define knh_hcode_join(s1,s2)	   ((knh_hashcode_t)s1 << (sizeof(knh_short_t)*8)) + s2;

typedef knh_Object_t* (*knh_Fdefnull)(CTX ctx, knh_class_t cid);

typedef struct {
	knh_flag_t    flag  ;
	knh_short_t   israw ;
	knh_type_t    type  ;
	knh_fieldn_t  fn    ;
} knh_fields_t ;

#define TFMT_s      0
#define FMT_s       1
#define TFMT_line   2
#define FMT_line    3
#define TFMT_data   4
#define FMT_data    5
#define TFMT_dump   6
#define FMT_dump    7

#define IS_FMTs(level)     (level <= FMT_s)
#define IS_FMTline(level)  (level <= FMT_line)
#define IS_FMTdump(level)  (level >= TFMT_dump)

/* ------------------------------------------------------------------------ */

typedef struct {
	struct knh_OutputStream_t *w;  // always set
	void *pk;      // for msgpack
	void *sbuffer; // for msgpack
} knh_packer_t;

typedef struct knh_PackSPI_t {
	const char *name;
	void* (*pack_init)(CTX, knh_packer_t *);
	void  (*pack_flushfree)(CTX, knh_packer_t *);
	void  (*pack_null)(CTX, void*);
	void  (*pack_bool)(CTX, void*, int d);
	void  (*pack_int)(CTX, void*, knh_int_t d);
	void  (*pack_float)(CTX, void*, knh_float_t d);
	void  (*pack_string)(CTX, void*, const char *str, size_t n);
	void  (*pack_raw)(CTX, void*, const char *str, size_t n);
	void  (*pack_putc)(CTX, void*, int ch);  // use for delim : or ,
	void  (*pack_beginarray)(CTX, void*, size_t n);
	void  (*pack_endarray)(CTX, void*);   // unnecessary for msgpack
	void  (*pack_beginmap)(CTX, void*, size_t n);
	void  (*pack_endmap)(CTX, void*);     // unnecessary for msgpack
	knh_type_t (*unpack)(CTX, const char *, size_t, knh_sfp_t*);   // put sfp[0]
//	knh_type_t (*unpackS)(CTX, struct knh_InputStream_t *, knh_sfp_t*);   // put sfp[0]
} knh_PackSPI_t;

/***
void knh_OutputStream_writeObject(CTX ctx, knh_OutputStream_t *w, knh_Object_t *o, const knh_PackSPI_t *packspi)
{
	knh_packer_t packer = {w, NULL, NULL};
	void *pkr = packspi->packinit(ctx, &packer);
	if(O_cTBL(o)->ospi->wdata == NULL) {
		O_cTBL(o)->ospi->wdata(ctx, pkr, o, packspi);
	}
	packspi->pack_flushfree(ctx, &packer);
}

knh_Object_t *knh_InputStream_readObject(CTX ctx, knh_InputStream_t *in, knh_type_t reqc, const knh_PackSPI_t *packspi)
{
	BEGIN_LOCAL(ctx, lsfp, 2);
	knh_type_t type = packspi->unpack(ctx, in, lsfp);
	if(type != TYPE_void) {
		// convert type to reqc;
	}
	END_LOCAL(ctx, lsfp);
}
***/

typedef struct knh_ClassDef_t {
	void (*init)(CTX, struct knh_RawPtr_t*);
	void (*initcopy)(CTX, struct knh_RawPtr_t*, struct knh_RawPtr_t*);
	void (*reftrace)(CTX, struct knh_RawPtr_t* FTRARG);
	void (*free)(CTX, struct knh_RawPtr_t*);
	void (*checkin)(CTX, knh_sfp_t *sfp, struct knh_RawPtr_t*);
	void (*checkout)(CTX, struct knh_RawPtr_t*, int);
	int  (*compareTo)(struct knh_RawPtr_t*, struct knh_RawPtr_t*);
	void (*p)(CTX, struct knh_OutputStream_t*, struct knh_RawPtr_t*, int);

	struct knh_String_t* (*getkey)(CTX, knh_sfp_t*);
	knh_hashcode_t       (*hashCode)(CTX, struct knh_RawPtr_t*);
//	knh_int_t   (*toint)(CTX ctx, knh_sfp_t*);
//	knh_float_t (*tofloat)(CTX ctx, knh_sfp_t*);
	void *RESERVED0;
	void *RESERVED1;
//	struct knh_TypeMap_t* (*findTypeMapNULL)(CTX, knh_class_t, knh_class_t, int);
	void *RESERVED1_1;
	void (*wdata)(CTX, struct knh_RawPtr_t*, void *, const knh_PackSPI_t *);
	void *RESERVED2;
	void *RESERVED3;

	const char             *name;
	knh_flag_t              cflag;
	knh_ushort_t            struct_size;
	knh_fields_t            *fields;

	knh_Fdefnull            getDefaultNull;
	void *RESERVED4;
	void *RESERVED5;
	void *RESERVED6;
	size_t asize;           /* set it to zero usually */
} knh_ClassDef_t;

/* ------------------------------------------------------------------------ */

#define K_CLASSTABLE_INIT 128

typedef struct knh_ClassTBL_t {
	const knh_ClassDef_t *cdef;
	knh_uintptr_t magicflag;
	knh_flag_t    cflag;        knh_uri_t     domain;
	knh_class_t   cid;          knh_class_t   imcid;
	knh_class_t   bcid;         knh_class_t   supcid;
	const struct knh_ClassTBL_t *baseTBL;
	const struct knh_ClassTBL_t *supTBL;
	struct knh_ParamArray_t     *cparam;
	knh_class_t   p1;           knh_class_t   p2;
	struct knh_Class_t          *typeNULL;
	struct knh_String_t         *lname;
	struct knh_String_t         *sname;
	struct knh_Array_t          *methods;
	struct knh_Array_t          *typemaps;
	knh_fields_t                *fields;
	knh_ushort_t  fsize;         knh_ushort_t  fcapacity;
	knh_short_t   keyidx;        knh_short_t   xdataidx;
	union {
		struct knh_ObjectField_t  *protoNULL;
		const struct knh_ClassTBL_t     *simTBL;
	};
	knh_Fdefnull               fdefnull;
	union {
		struct knh_Object_t       *defnull;
		struct knh_ObjectField_t  *defobj;
		struct knh_Func_t         *deffunc;
//		struct knh_Semantics_t    *cspec;
	};
	struct knh_DictMap_t          *constDictCaseMapNULL;
	struct knh_PtrMap_t           *constPoolMapNULL;
	size_t subclass;
	size_t count;
	size_t total;
} knh_ClassTBL_t;

#define C_bcid(c)           ClassTBL(c)->bcid
#define C_bname(c)          knh_class_bname(ctx, cid)
#define C_p1(c)             ClassTBL(c)->p1
#define C_p2(c)             ClassTBL(c)->p2
#define C_p(c, n)           knh_class_p(ctx, c, n)
#define C_isGenerics(c)     knh_class_isGenerics(ctx, c)

#define IS_Tcparam(cid)     (ClassTBL(cid)->cparam != NULL)

#define PTYPE_Array           "[]"
#define PTYPE_Iterator        ".."
#define PTYPE_Immutable       "!"
#define PTYPE_KindOf          "?"

/* ------------------------------------------------------------------------ */

#ifndef K_EVENTTBL_INIT
#define K_EVENTTBL_INIT 64
#endif

#define SIZEOF_TEXPT(n)  (n * sizeof(knh_EventTBL_t))

typedef struct {
	knh_flag_t   flag;
	knh_event_t   parent;
	struct knh_String_t     *name;
} knh_EventTBL_t;

/* ------------------------------------------------------------------------ */
/* [SystemStat] */

#ifdef K_USING_STAT
#define STAT_(STMT)    STMT
#else
#define STAT_(STMT)
#endif

#define K_GC_MARGIN   1024

typedef struct {
	size_t                      usedMemorySize;
	size_t                      maxMemoryUsage;
//	size_t                      usedObjectSize;
//	size_t                      gcBoundary;
//	size_t                      maxObjectUsage;
	long                        gcObjectCount;
	knh_uint64_t markingTime;   // marking time [ms]
	knh_uint64_t sweepingTime;  // sweeping time [ms]
	knh_uint64_t gcTime;        // total gc time [ms]
	size_t gcCount;             // How many times GC occured.
	knh_uint64_t latestGcTime;  // lastest time
	size_t markedObject;
	size_t movedObject;
	size_t collectedObject;
} knh_stat_t;


/* ------------------------------------------------------------------------ */
/* [SystemShare] */

#define SIZEOF_TSTRING (sizeof(knh_Object_t*) * K_TSTRING_SIZE)

#define KNH_ENC             ctx->share->enc

#define KNH_NULL            (ctx->share->constNull)
#define KNH_TRUE            (ctx->share->constTrue)
#define KNH_FALSE           (ctx->share->constFalse)
#define K_EMPTYARRAY       (ctx->share->emptyArray)
#define KNH_SYSTEM          (ctx->sys)
#define knh_Object_sweep    knh_Object_RCsweep

typedef struct knh_nameinfo_t knh_nameinfo_t;

struct knh_nameinfo_t { // FIXME
	struct knh_String_t *name;
	knh_methodn_t parent_mn;
	knh_methodn_t parentMF;
	knh_class_t   principle_mtd;
	knh_class_t   mtdfCID;
};

/* ------------------------------------------------------------------------ */
/* Arena */

#define K_OPAGE(o)    ((knh_ObjectPage_t*)((((knh_uintptr_t)(o)) / K_PAGESIZE) * K_PAGESIZE))
#define K_SHIFTPTR(p, size)   ((char*)p + size)
#define K_MEMSIZE(p, p2)      (((char*)p) - ((char*)p2))

#define K_PAGEOBJECTSIZE ((K_PAGESIZE / sizeof(knh_Object_t)) - 1)

#define K_ARENATBL_INITSIZE     32
#define K_NBITMAP 2

#ifdef K_USING_RCGC
#define K_ARENASIZE             (sizeof(knh_Object_t) * K_PAGESIZE)
#else
#define K_ARENASIZE             ((sizeof(knh_Object_t) * K_PAGESIZE) * 16) /*4MB*/
#endif

typedef struct knh_ObjectArenaTBL_t knh_ObjectArenaTBL_t;
typedef struct knh_memslot_t knh_memslot_t;
typedef struct knh_MemoryArenaTBL_t knh_MemoryArenaTBL_t;
struct knh_Stmt_t;
typedef void (*fMethod_compile)(CTX, struct knh_Method_t *, struct knh_Stmt_t *);

typedef struct knh_share_t {
	/* system table */
	const knh_ClassTBL_t    **ClassTBL;
	size_t                    sizeClassTBL;
	size_t                    capacityClassTBL;

	const knh_EventTBL_t     *EventTBL;
	size_t                    sizeEventTBL;
	size_t                    capacityEventTBL;


	knh_ObjectArenaTBL_t     *ObjectArenaTBL;
	size_t                    sizeObjectArenaTBL;
	size_t                    capacityObjectArenaTBL;
	struct knh_Object_t      *freeObjectList;
	struct knh_Object_t      *freeObjectTail;

	// reserved
	knh_ObjectArenaTBL_t     *YoungArenaTBL;
	size_t                    sizeYoungArenaTBL;
	size_t                    capacityYoungArenaTBL;
	struct knh_Object_t      *freeYoungList;
	struct knh_Object_t      *freeYoungTail;

	knh_MemoryArenaTBL_t     *MemoryArenaTBL;
	size_t                    sizeMemoryArenaTBL;
	size_t                    capacityMemoryArenaTBL;
	struct knh_memslot_t     *freeMemoryList;
	struct knh_memslot_t     *freeMemoryTail;

	char                     *xmem_root;    // xmalloc
	char                     *xmem_top;
	char                     *xmem_freelist;

	knh_mutex_t              *memlock;
	knh_mutex_t              *syslock;

	/* system shared const */
	knh_Object_t             *constNull;
	knh_Object_t             *constTrue;
	knh_Object_t             *constFalse;
	struct knh_String_t     **tString;
	struct knh_Array_t       *emptyArray;
	struct knh_Path_t        *cwdPath;
	struct knh_NameSpace_t   *rootns;
	struct knh_context_t     *ctx0;   // root context
	struct knh_Script_t      *script;
	struct knh_DictSet_t     *funcDictSet;   //


	struct knh_opline_t      *PRECOMPILED_LAUNCH;
	struct knh_opline_t      *PRECOMPILED_FUNCCALL;
	struct knh_opline_t      *PRECOMPILED_VEXEC;  // TODO nakata
//	struct knh_opline_t      *PC_ABSTRACT;

	/* system */
	struct knh_DictMap_t     *sysAliasDictMap;
	struct knh_PtrMap_t      *inferPtrMap;  // mapinfer
	struct knh_PtrMap_t      *constPtrMap;
	struct knh_PtrMap_t      *xdataPtrMap;
	struct knh_Array_t       *constPools;

	/* symbol, names */
	struct knh_DictMap_t       *packageDictMap;
	struct knh_DictMap_t       *securityDictMap; // added by Wakamori
	struct knh_DictSet_t       *classNameDictSet;
	struct knh_DictSet_t       *eventDictSet;
	struct knh_DictSet_t       *streamDpiDictSet;
	struct knh_DictSet_t       *convDpiDictSet;
	struct knh_DictSet_t       *rconvDpiDictSet;
	struct knh_DictSet_t       *mapDpiDictSet;

	struct knh_DictMap_t*      props;
	struct knh_InputStream_t*  in;
	struct knh_OutputStream_t* out;
	struct knh_OutputStream_t* err;
	struct knh_String_t*       enc;

	struct knh_DictSet_t       *tokenDictSet;
	struct knh_DictSet_t       *nameDictCaseSet;  // fn, mn
	size_t                      namecapacity;
	knh_nameinfo_t             *nameinfo;
	struct knh_DictSet_t       *urnDictSet;
	struct knh_Array_t         *urns;
//	struct knh_DictMap_t       *URNAliasDictMap;

	/* thread */
	size_t              contextCounter;
	size_t              threadCounter;
	struct knh_Array_t *contextListNULL;  // for matz

	/* CompilerAPI */
	struct knh_Object_t *konoha_compiler;
	fMethod_compile compilerAPI;
} knh_share_t ;

#define KNH_ASSERT_CTX0(ctx)   KNH_ASSERT((ctx)->ctxid == 0)
#if defined(K_USING_DEBUG) && defined(K_INTERNAL)
#define ClassTBL(cid)     DBG_ClassTBL(ctx, cid)
#else
#define ClassTBL(cid)     (ctx->share->ClassTBL[cid])
#endif

#define varClassTBL(cid)    (knh_ClassTBL_t*)ClassTBL(cid)
#define EventTBL(eid)    ctx->share->EventTBL[eid]
#define pEventTBL(eid)   (knh_EventTBL_t*)(ctx->share->EventTBL + (eid))
#define knh_setClassDefaultValue(ctx, cid, v, f) knh_setClassDefaultValue_(ctx, cid, UPCAST(v), f)

/* ------------------------------------------------------------------------ */

typedef struct {
	knh_class_t cid; knh_methodn_t mn;
} knh_hcache_t;

typedef struct knh_mtdcache_t {
	knh_class_t cid; knh_methodn_t mn;
	struct knh_Method_t *mtd;
} knh_mtdcache_t ;

#define hashcode_mtd(cid, mn, HMAX) (((((knh_hashcode_t)cid) << (sizeof(knh_class_t) * 8)) + mn) % HMAX)

typedef struct knh_tmrcache_t {
	knh_class_t scid; knh_class_t tcid;
	struct knh_TypeMap_t *tmr;
} knh_tmrcache_t ;

#define hashcode_tmr(scid, tcid, HMAX) (((((knh_hashcode_t)scid) << (sizeof(knh_class_t) * 8)) + tcid) % HMAX)

#ifdef K_USING_ICONV
#include<iconv.h>
typedef iconv_t knh_iconv_t;
#else
typedef long knh_iconv_t;
#endif

struct knh_logdata_t;
struct knh_Iterator_t;

typedef const char* knh_ldata_t;

typedef struct knh_ServiceSPI_t {
	/* sync spi */
#ifdef K_USING_DEBUG
	int (*lockSPI)(knh_mutex_t *m, const char *_file, const char* _func, int _line);
	int (*unlockSPI)(knh_mutex_t *m, const char *_file, const char* _func, int _line);
#else
	int (*lockSPI)(knh_mutex_t *m);
	int (*unlockSPI)(knh_mutex_t *m);
#endif
	/* syslog spi */
	void (*syslog)(int, const char *, ...);
	void (*vsyslog)(int, const char *, va_list);
	/* readline spi*/
	char* (*readline)(const char*);
	int (*add_history)(const char*);
	/* iconv spi*/
	knh_iconv_t (*iconv_openSPI)(const char*, const char*);
	size_t (*iconvSPI)(knh_iconv_t, char**, size_t*, char**, size_t*);
	int (*iconv_closeSPI)(knh_iconv_t);
	/* shell spi */
	const char *syncspi;     // debug
	const char *syslogspi;   // debug
	const char *readlinespi; // debug
	const char *iconvspi;    // debug
	/* konoha spi */
	void* (*mallocSPI)(CTX, size_t);       	// memory
	void  (*freeSPI)(CTX, void *, size_t);
	// stack operation
	void  (*setsfpSPI)(CTX, knh_sfp_t *, void *);
	void  (*closeItrSPI)(CTX, struct knh_Iterator_t *);
	// evidence
	void (*ntraceSPI)(CTX, const char *, int, knh_ldata_t *);
	void  (*pSPI)(const char*, const char*, int, const char*, ...);
} knh_ServiceSPI_t;

#define WCTX(ctx)     ((knh_context_t*)ctx)

typedef struct knh_context_t {
	int						      safepoint; // set to 1
	/* @Sharable */
	union {
		const knh_share_t         *share;
		knh_share_t *wshare;   // writable
	};
	knh_stat_t                     *stat;
	const knh_ServiceSPI_t         *spi;
	const struct knh_api2_t        *api2;
	struct knh_Script_t*         script;  // sharable or not?

	/* stack */
	knh_sfp_t*                      stack;
	knh_sfp_t*                      esp;
	size_t                          stacksize;
	knh_sfp_t*                      stack_uplimit;
	void*                           cstack_bottom;  // for GC
	struct knh_Exception_t         *e;
	struct knh_ExceptionHandler_t  *ehdrNC;
	struct knh_Object_t            *evaled;
	knh_bool_t                      isEvaled;

	/* cache */
	knh_mtdcache_t              *mtdcache;
	knh_tmrcache_t              *tmrcache;

	/* memory (gc) */
	knh_Object_t                *freeObjectList;
	knh_Object_t                *freeObjectTail;
	size_t                       freeObjectListSize;
	knh_memslot_t               *freeMemoryList;
	knh_memslot_t               *freeMemoryTail;

	struct knh_Object_t        **refs;
	size_t                       ref_size;
	struct knh_Object_t        **ref_buf;        // allocated body
	size_t                       ref_capacity;

	struct knh_Object_t        **queue;
	size_t                       queue_capacity;
	size_t                       queue_log2;

	struct knh_String_t*         enc;
	struct knh_InputStream_t*    in;
	struct knh_OutputStream_t*   out;
	struct knh_OutputStream_t*   err;
	struct knh_Bytes_t*          bufa;
	struct knh_OutputStream_t*   bufw;
	struct knh_Gamma_t*          gma;

#ifndef K_USING_STRINGPOOL
	struct knh_DictMap_t*        symbolDictMap;
#endif

	knh_flag_t                   flag;
	knh_ushort_t                 ctxid;
	struct knh_Context_t        *ctxobjNC;
	struct knh_context_t        *parent;
	knh_mutex_t                 *ctxlock;

	/* logging */
	char                            trace[16];  // random
	knh_uint_t                      seq;        // for logging
	/* signal */
	int                             signal;
	void                           *siginfo;
#if defined(K_USING_MINGW_)
#define K_SIGNAL_MAX NSIG
#else
#define K_SIGNAL_MAX _POSIX_SIGQUEUE_MAX
#endif
	struct knh_Func_t             **sighandlers; // modified by Wakamori
} knh_context_t ;

#define SAFEPOINT_GC                  1
#define SAFEPOINT_SETGC(ctx)          WCTX(ctx)->safepoint |= SAFEPOINT_GC

#define SAFEPOINT_SIGNAL     (1<<1)
#define SAFEPOINT_SETSIGNAL(ctx)      WCTX(ctx)->safepoint |= SAFEPOINT_SIGNAL

#define SAFEPOINT_MONITOR    (1<<2)
#define SAFEPOINT_SETMONITOR(ctx)     WCTX(ctx)->safepoint |= SAFEPOINT_MONITOR


/* ------------------------------------------------------------------------ */
/* logdata */


#define LOG_END       ((const char*)0L)
#define LOGT_s        1
#define LOG_s(K,V)    ((const char*)LOGT_s), K, V
#define LOG_msg(V)    ((const char*)LOGT_s), "msg", V
#define LOG_t(K, V)   ((const char*)LOGT_s), K, (TYPE__(V))
#define LOGT_i        2
#define LOG_i(K,V)    ((const char*)LOGT_i), K, ((const char*)(knh_intptr_t)(V))
#define LOGT_u        3
#define LOG_u(K,V)    ((const char*)LOGT_u), K, ((const char*)(knh_uintptr_t)(V))
#define LOGT_f        4
#define LOG_f(K,V)    ((const char*)LOGT_f), K, ((const char*)(knh_intptr_t)((V)*1000))
#define LOGT_p        5
#define LOG_p(K,V)    ((const char*)LOGT_p), K, ((const char*)(V))
#define LOGT_o        6
#define LOG_o(K,V)    ((const char*)LOGT_o), K, ((const char*)(V))
#define LOGT_sfp      7
#define LOG_sfp       ((const char*)LOGT_sfp), ((const char*)(sfp))

#ifdef K_EXPORTS
#define KNH_NTRACE ctx->spi->ntraceSPI
#else
#define KNH_NTRACE knh_ntrace
#endif

#define KNH_NTHROW(ctx, sfp, fault, event, pe, ldata) \
	KNH_NTRACE(ctx, event, pe, ldata);  \
	knh_nthrow(ctx, sfp, fault, ldata); \

#define FLAG_TRACE_FAILED 1
#define FLAG_TRACE_ERRNO  (1<<1)
#define FLAG_TRACE_ALWAYS (1<<2)
#define FLAG_TRACE_DEBUG  (1<<3)

#define K_OK          0
#define K_FAILED      1
//#define K_okerror   2
#define K_PERROR      3
#define K_NOTICE      4
//#define K_af        5
//#define K_af        6
//#define K_af        7
#define K_DOK         8
#define K_DFAILED     (9 & FLAG_TRACE_ERRNO)

/* ------------------------------------------------------------------------ */

typedef const knh_context_t* konoha_t;

#define KONOHA_BEGIN(v)   knh_beginContext(v, (void**)&v)
#define KONOHA_END(v)     knh_endContext(v)

/* ------------------------------------------------------------------------ */
/* cwb */
/* ------------------------------------------------------------------------ */

typedef struct {
	struct knh_Bytes_t          *ba;
	struct knh_OutputStream_t   *w;
	size_t pos;
} CWB_t;

#define CWB_clear(cwb, len)        knh_Bytes_clear(cwb->ba, (cwb->pos)+len)

/* ------------------------------------------------------------------------ */
/* Functions */
/* ------------------------------------------------------------------------ */

#define _RIX   ,long _rix
#define K_RIX  _rix

#ifdef K_USING_WIN32_
#define KMETHOD  void CC_EXPORT
#define TYPEMAP  KMETHOD
#define ITRNEXT int   CC_EXPORT
typedef void (CC_EXPORT *knh_Fmethod)(CTX, knh_sfp_t* _RIX);
typedef void (CC_EXPORT *knh_Ftypemap)(CTX, knh_sfp_t * _RIX);
typedef int  (CC_EXPORT *knh_Fitrnext)(CTX, knh_sfp_t * _RIX);
#else
#define KMETHOD  void  CC_FASTCALL_
#define TYPEMAP  KMETHOD
#define ITRNEXT int   CC_FASTCALL_
typedef KMETHOD (*knh_Fmethod)(CTX, knh_sfp_t* _RIX);
typedef TYPEMAP (*knh_Ftypemap)(CTX, knh_sfp_t * _RIX);
typedef ITRNEXT (*knh_Fitrnext)(CTX, knh_sfp_t * _RIX);
#endif

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}

/*  this is defintion of KSObject */
namespace konoha {
class KSObject {
public:
	KSObject();
	~KSObject();
private:
	struct knh_RawPtr_t *kself;
	int isGCSync;
	KSObject(const KSObject &);
	KSObject operator=(const KSObject &);
};
}

#endif

#endif /*KONOHA_T_H_*/
