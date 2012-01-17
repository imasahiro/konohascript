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
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif
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

typedef int16_t           kint16_t;
typedef uint16_t          kuint16_t;
typedef int32_t           kint32_t;
typedef uint32_t          kuint32_t;
typedef int64_t           kint64_t;
typedef uint64_t          kuint64_t;

typedef intptr_t          kintptr_t;
typedef uintptr_t         kuintptr_t;
typedef kintptr_t         kindex_t;

#define K_INTPTR_FMT      "%"PRIdPTR
#define K_INTPTR_UFMT     "%"PRIuPTR

#if defined(__LP64__) || defined(_WIN64)
#define K_USING_64_    1
typedef int32_t           kshort_t;
typedef uint32_t          kushort_t;
typedef uintptr_t         kunbox_t;
#ifndef K_USING_NOFLOAT
typedef double            kfloatptr_t;
#endif
#undef K_USING_INT32
#else
typedef int16_t           kshort_t;
typedef uint16_t          kushort_t;
#if defined(K_USING_INT32)
typedef uint32_t          kunbox_t;
#else
typedef uint64_t          kunbox_t;
#define K_USING_DBLNDATA_  1
#endif
#ifndef K_USING_NOFLOAT
typedef float             kfloatptr_t;
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
/* Bool(ean), kbool_t */
/* ------------------------------------------------------------------------ */

typedef kintptr_t      kbool_t;

typedef enum {
	K_BREAK, K_CONTINUE, K_REDO
} kstatus_t;

/* ------------------------------------------------------------------------ */
/* Integer, kint_t */
/* ------------------------------------------------------------------------ */

#ifdef K_USING_INT32
typedef long                kint_t;
typedef unsigned long       kuint_t;

#define KINT_MAX               LONG_MAX
#define KINT_MIN               LONG_MIN
#define KINT0                  0UL
#define KINT_FMT               "%ld"
#define KINT_XFMT              "%lx"
#define KUINT_MAX              ULONG_MAX
#define KUINT_MIN              0
#define KUINT_FMT              "%lu"
#define knh_abs(n)              labs(n)
#define VMTX_INT
#define VMTSIZE_int 0

#else /*K_USING_INT32*/

typedef kint64_t        kint_t;
typedef kuint64_t       kuint_t;

#ifndef LLONG_MIN
#define LLONG_MIN -9223372036854775807LL
#define LLONG_MAX  9223372036854775807LL
#endif

#ifndef ULLONG_MAX
#define ULLONG_MAX 18446744073709551615ULL
#endif

#define KINT_MAX               LLONG_MAX
#define KINT_MIN               LLONG_MIN
#define KINT_FMT               "%lld"
#define KINT_XFMT              "%llx"
#define KINT0                  0ULL
#define KUINT_MAX              ULLONG_MAX
#define KUINT_MIN              0ULL
#define KUINT_FMT              "%llu"
#define knh_abs(n)              llabs(n)

#endif/*K_USING_INT32*/

#define KINT_FMTSIZ            40

/* ------------------------------------------------------------------------ */
/* Float, kfloat_t */
/* ------------------------------------------------------------------------ */

#ifdef K_USING_NOFLOAT
/* dummy */
typedef long                    kfloat_t;
typedef long                    kfloatptr_t;

#define KFLOAT_MAX             0
#define KFLOAT_MIN             0
#define KFLOAT_STEP            0
#define KFLOAT_FMT             "%d"
#define KFLOAT_FMT1            "%d"
#define KFLOAT_FMT2            "%d"
#define KFLOAT_FMT3            "%d"
#define KFLOAT_FMT4            "%d"
#define KFLOAT_FMTE            "%d"
#define KFLOAT_NAN             0
#define KFLOAT_NULL            KFLOAT_NAN
#define KFLOAT_FMTSIZ          40
#define KFLOAT_ZERO            0
#define KFLOAT_ONE             1
#else
#define KFLOAT_ZERO            0.0
#define KFLOAT_ONE             1.0
#endif/*K_USING_NOFLOAT*/

#if defined(K_USING_INT32) && !defined(KFLOAT_FMT)
typedef float                   kfloat_t;
#define KFLOAT_MAX             FLT_MAX
#define KFLOAT_MIN             (-(FLT_MAX))
#define KFLOAT_STEP            FLT_MIN
#define KFLOAT_EPSILON         FLT_EPSILON
#define KFLOAT_FMT             "%.6f"
#define KFLOAT_FMT1            "%.1f"
#define KFLOAT_FMT2            "%.2f"
#define KFLOAT_FMT3            "%.3f"
#define KFLOAT_FMT4            "%.4f"
#define KFLOAT_FMTE            "%e"
#endif

#ifndef KFLOAT_FMT
typedef double                  kfloat_t;
#define KFLOAT_MAX             DBL_MAX
#define KFLOAT_MIN             (-(DBL_MAX))
#define KFLOAT_STEP            DBL_MIN
#define KFLOAT_EPSILON         DBL_EPSILON
#define KFLOAT_FMT             "%.6f"
#define KFLOAT_FMT1            "%.1f"
#define KFLOAT_FMT2            "%.2f"
#define KFLOAT_FMT3            "%.3f"
#define KFLOAT_FMT4            "%.4f"
#define KFLOAT_FMTE            "%e"
#endif

#ifndef KFLOAT_NAN
#define KFLOAT_NAN             (0.0/0.0)
#define KFLOAT_NULL            KFLOAT_NAN
#define KFLOAT_FMTSIZ          80
#endif /*KFLOAT_NAN*/

/* ------------------------------------------------------------------------ */
/* String, kchar_t */
/* ------------------------------------------------------------------------ */

typedef unsigned char           kchar_t;    /* byte */
typedef const char              kascii_t;
typedef const unsigned char     kutext_t;

typedef struct {
	union {
		const char *text;
		const unsigned char *utext;
		char *buf;
		kchar_t *ubuf;
	};
	size_t       len;
} kbytes_t;

#define ismulti(c)             (((kchar_t)c)>127)

#define B(c)      new_bytes((char*)c)
#define STEXT(c)  new_bytes2(c,sizeof(c)-1)
#define ISB(t,c) (t.len == (sizeof(c)-1) && knh_strncmp(t.text, c, t.len) == 0)

/* ------------------------------------------------------------------------ */
/* kflag_t */
/* ------------------------------------------------------------------------ */

typedef kushort_t                 kflag_t;    /* flag field */
#define KFLAG_H(N)               ((sizeof(kflag_t)*8)-N)
#define KFLAG_H0                 ((kflag_t)(1 << KFLAG_H(1)))
#define KFLAG_H1                 ((kflag_t)(1 << KFLAG_H(2)))
#define KFLAG_H2                 ((kflag_t)(1 << KFLAG_H(3)))
#define KFLAG_H3                 ((kflag_t)(1 << KFLAG_H(4)))
#define KFLAG_H4                 ((kflag_t)(1 << KFLAG_H(5)))
#define KFLAG_H5                 ((kflag_t)(1 << KFLAG_H(6)))
#define KFLAG_H6                 ((kflag_t)(1 << KFLAG_H(7)))
#define KFLAG_H7                 ((kflag_t)(1 << KFLAG_H(8)))

#define TFLAG_is(T,f,op)          (((T)(f) & (T)(op)) == (T)(op))
#define TFLAG_set1(T,f,op)        f = (((T)(f)) | ((T)(op)))
#define TFLAG_set0(T,f,op)        f = (((T)(f)) & (~((T)(op))))
#define TFLAG_set(T,f,op,b)       if(b) {TFLAG_set1(T,f,op);} else {TFLAG_set0(T,f,op);}
#define TFLAG_setNOT(T,f,op,b)    if(!(b)) {TFLAG_set0(T,f,op);} else {TFLAG_set1(T,f,op);}

#define FLAG_set(f,op)            TFLAG_set1(kflag_t,f,op)
#define FLAG_unset(f,op)          TFLAG_set0(kflag_t,f,op)
#define FLAG_is(f,op)             TFLAG_is(kflag_t,f,op)

/* ------------------------------------------------------------------------ */
/* Struct, Class, Type  */
/* ------------------------------------------------------------------------ */

struct  kcontext_t;
#define CTX const struct kcontext_t *const

typedef kushort_t       kclass_t;  /* class id */
typedef kushort_t       ktype_t;   /* extended ktype_t */
typedef kushort_t       kevent_t;    /* kevent_t */

/* kclass_t */
#define CLASS_newid                ((kclass_t)-1)
#define CLASS_unknown              ((kclass_t)-2)

#define DBG_ASSERT_cid(cid)        DBG_ASSERT(cid < ctx->share->sizeClassTBL)

/* ktype_t */
#define TYPE_void           CLASS_Tvoid
#define TYPE_T0             ((ktype_t)30000)
#define TYPE_This           TYPE_T0
#define TYPE_T(n)           (TYPE_T0+(n))
#define TYPE_T1             TYPE_T(1)
#define TYPE_T2             TYPE_T(2)
#define TYPE_T3             TYPE_T(3)
#define TYPE_T4             TYPE_T(4)

#define CLASS_t(t)          (((t) >= TYPE_This) ? CLASS_Object : (t))
#define TYPE_cid(t)         (t)

//#define IS_Tfield(t)      (ClassTBL(CLASS_t(t))->bcid == CLASS_Object)
#define IS_Tint(t)          (t == CLASS_Int || ClassTBL(CLASS_t(t))->bcid == CLASS_Int)
#define IS_Tfloat(t)        (t == CLASS_Float || ClassTBL(CLASS_t(t))->bcid == CLASS_Float)
#define IS_Tbool(t)         (TYPE_Boolean == t)
#define IS_Tunbox(t)        (IS_Tint(t) || IS_Tfloat(t) || IS_Tbool(t))
#define IS_Tfunc(t)         (ClassTBL(CLASS_t(t))->bcid == CLASS_Func)
#define IS_Tstr(t)          (t == CLASS_String || ClassTBL(CLASS_t(t))->bcid == CLASS_String)
#define IS_Tvany(t)         (t == CLASS_Tdynamic || t == TYPE_var || t == TYPE_void)

#define ClassTBL_isa(t, reqt)   (t->cid == reqt || ClassTBL_isa_(ctx, t, ClassTBL(reqt)))
#define class_isa(cid, reqt)    (cid == reqt || ClassTBL_isa_(ctx, ClassTBL(cid), ClassTBL(reqt)))

#define CLASS__(cid)               SAFECLASS__(ctx, cid)
#define STRUCT__(bcid)             SAFESTRUCT__(ctx, bcid)
#define O__(o)                     S_totext(O_cTBL(o)->sname)
#define TYPE__(type)               SAFETYPE__(ctx,type)

/* kevent_t */
#define EVENT_unknown            ((kevent_t)-1)
#define EVENT_newid              ((kevent_t)0)
#define ASSERT_ebi(eid)        DBG_ASSERT(eid < ctx->share->sizeEventTBL + 1)
#define EVENT__(eid)             S_totext(knh_getEventName(ctx, eid))

/* ------------------------------------------------------------------------ */

typedef kushort_t          ksymbol_t;
typedef kushort_t          kmethodn_t;

#define FN_NONAME    ((ksymbol_t)-1)
#define FN_NEWID     ((ksymbol_t)-2)
#define FN_return    FN_

#define MN_NONAME    ((kmethodn_t)-1)
#define MN_NEWID     ((kmethodn_t)-2)

#define KFLAG_FN_U1         KFLAG_H0
#define KFLAG_FN_U2         KFLAG_H1
#define KFLAG_FN_SUPER      (KFLAG_H0|KFLAG_H1)

#define FN_isSUPER(fnq)      ((fnq & KFLAG_FN_SUPER) == KFLAG_FN_SUPER)
#define FN_isU1(fnq)         ((fnq & KFLAG_FN_U1) == KFLAG_FN_U1)
#define FN_isU2(fnq)         ((fnq & KFLAG_FN_U2) == KFLAG_FN_U2)

#define KFLAG_FN_REF        KFLAG_H0
#define KFLAG_FN_NEMPTY     KFLAG_H1
#define KFLAG_FN_SYSTEM     KFLAG_H2

#define FN_UNMASK(fnq)       (fnq & (~(KFLAG_H0|KFLAG_H1|KFLAG_H2)))

#define KFLAG_MN_ISBOOL     KFLAG_H0
#define KFLAG_MN_GETTER     KFLAG_H1
#define KFLAG_MN_SETTER     KFLAG_H2
#define KFLAG_MN_FMT        (KFLAG_H0|KFLAG_H1|KFLAG_H2)
#define KFLAG_MN_FIELDN     (~KFLAG_MN_FMT)

#define MN_isISBOOL(mn)   ((mn & KFLAG_MN_FMT) == KFLAG_MN_ISBOOL)
#define MN_toISBOOL(mn)   (mn | KFLAG_MN_ISBOOL)
#define MN_isGETTER(mn)   ((mn & KFLAG_MN_FMT) == KFLAG_MN_GETTER)
#define MN_toGETTER(mn)   (mn | KFLAG_MN_GETTER)
#define MN_isSETTER(mn)   ((mn & KFLAG_MN_FMT) == KFLAG_MN_SETTER)
#define MN_toSETTER(mn)   (mn | KFLAG_MN_SETTER)
#define MN_isFMT(mn)      ((mn & KFLAG_MN_FMT) == KFLAG_MN_FMT)
#define MN_toFMT(mn)      (mn | KFLAG_MN_FMT)

#define MN_toFN(mn)       (mn & KFLAG_MN_FIELDN)

#define MN_LAMBDA          FN_

const char *knh_getopname(kmethodn_t mn);
#define FN__(fn)          S_totext(knh_getFieldName(ctx, fn))
#define MN__(mn)          knh_getmnname(ctx, mn)

/* ------------------------------------------------------------------------ */
/* Object */
/* ------------------------------------------------------------------------ */

#define K_OBJECT_MAGIC        (578L << ((sizeof(kflag_t)*8)))
#define K_CFLAGMASK           (FLAG_Object_Ref)
#define KNH_MAGICFLAG(f)      (K_OBJECT_MAGIC | ((kuintptr_t)(f) & K_CFLAGMASK))
#define DBG_ASSERT_ISOBJECT(o)   DBG_ASSERT(TFLAG_is(kuintptr_t,(o)->h.magicflag, K_OBJECT_MAGIC))

#ifdef K_USING_RCGC
#define KNH_HOBJECT_REFC      1
#endif

typedef struct kObjectHeader {
	kuintptr_t magicflag;
	const struct knh_ClassTBL_t *cTBL;
	union {
		kuintptr_t refc;
		kuintptr_t mscheck;
		void *gcinfo;
	};
	void *meta;   // reserved for traits
} kObjectHeader ;

#ifndef K_USING_BMGC
#define SP(o)               (o)
#define DP(o)               ((o)->b)
#define KNH_EX_REF          *
#else
#define SP(o)               (o)
#define DP(o)               (&(o)->b)
#define KNH_EX_REF
#endif
#define _(s)          s

/* types of basic objects (not type-checked) */

#define Object          struct kObject
#define dynamic         struct kObject
#define UPCAST(o)       (kObject*)(o)
#define RAWPTR(o)       (kRawPtr*)(o)

#define kObjectoNULL(ctx, o)   kObjectoNULL_(ctx, UPCAST(o))
#define O_data(o)       (((kInt*)(o))->n.data)

/* ------------------------------------------------------------------------ */
/* Common Object Structure */

typedef kushort_t                 kuri_t;
#define URI_unknown               ((kuri_t)-1)
#define URI_EVAL                  ((kuri_t)0)
#define URI_UNMASK(uri)           (uri)

#define URI__(uri) S_totext(knh_getURN(ctx, uri))
#define FILENAME__(uri) knh_sfile(URI__(uri))

typedef kuintptr_t                 kline_t;
#define new_ULINE(uri, line)       ((((kline_t)uri) << (sizeof(kuri_t) * 8)) | ((kushort_t)line))
#define ULINE_setURI(line, uri)    line |= (((kline_t)uri) << (sizeof(kuri_t) * 8))
#define ULINE_uri(line)            ((kuri_t)(line >> (sizeof(kuri_t) * 8)))
#define ULINE_line(line)           (line & (kline_t)((kuri_t)-1))

/* ------------------------------------------------------------------------ */
/* Thread */
/* ------------------------------------------------------------------------ */

#if defined(K_USING_WINTHREAD_)
#define kthread_t HANDLE
#define kthread_key_t DWORD

// reference URL: http://www.cs.wustl.edu/~schmidt/win32-cv-1.html

enum {
	E_SIGNAL = 0,
	E_BROADCAST = 1,
	E_MAX_EVENTS = 2
};

typedef struct {
	HANDLE events_[E_MAX_EVENTS];
	// Signal and broadcast event HANDLEs.
} knh_cond_t;

#define kmutex_t CRITICAL_SECTION

typedef struct {
	// Current count of the semaphore.
	u_int count_;
	// Number of threads that have called <sema_wait>.
	u_long waiters_count_;
	// Serialize access to <count_> and <waiters_count_>.
	kmutex_t lock_;
	// Condition variable that blocks the <count_> 0.
	knh_cond_t count_nonzero_;
} sema_t;

#elif defined(K_USING_PTHREAD)
#define kthread_t pthread_t
#define kthread_key_t pthread_key_t
#define kmutex_t pthread_mutex_t
#define knh_cond_t pthread_cond_t
#elif defined(K_USING_BTRON)
#define kthread_t W
#define kthread_key_t W
#define kmutex_t W
#else
typedef kintptr_t kthread_t;
typedef kintptr_t kthread_key_t;
typedef kintptr_t kmutex_t;
typedef kintptr_t knh_cond_t;
#endif

typedef void *(*knh_Fthread)(void *);

#define OLD_LOCK(ctx, lockid, o)
#define OLD_UNLOCK(ctx, lockid, o)

#define KNH_SYSLOCK(ctx)   knh_mutex_lock(ctx->share->syslock)
#define KNH_SYSUNLOCK(ctx) knh_mutex_unlock(ctx->share->syslock)
#define KNH_CTXLOCK(ctx)   knh_mutex_lock(ctx->ctxlock)
#define KNH_CTXUNLOCK(ctx) knh_mutex_unlock(ctx->ctxlock)

/* ------------------------------------------------------------------------ */
/* Stack Frame Pointer */
/* ------------------------------------------------------------------------ */

#define ASSERT_SFP(sfp)  KNH_ASSERT(((((krbp_t*)sfp) - ((krbp_t*)(ctx->stack))) % 2) == 0)

#define K_FRAME_NCMEMBER \
		kunbox_t   ndata;  \
		kbool_t    bvalue; \
		kint_t     ivalue; \
		kuint_t    uvalue; \
		kfloat_t   fvalue; \
		kintptr_t  shift;  \
		struct kopl_t     *pc; \
		struct kMethod     *mtdNC; \
		struct kTypeMap    *tmrNC; \
		struct ksfp_t *env \

#define K_FRAME_MEMBER \
		struct kObject *o; \
		struct kInt    *i; \
		struct kFloat  *f; \
		struct kClass  *c; \
		struct kString *s; \
		struct kDate *dt;\
		struct kBytes  *ba; \
		struct kRegex  *re; \
		struct kRange  *range; \
		struct kArray  *a; \
		struct kIterator *it; \
		struct kMap           *m;    \
		struct kFunc         *fo; \
		struct kPath         *pth; \
		struct kInputStream  *in; \
		struct kOutputStream *w;  \
		struct kView *rel;\
		struct kMethod            *mtd;\
		struct kTypeMap           *tmr;\
		struct kException         *e;\
		struct kExceptionHandler  *hdr; \
		struct kNameSpace         *ns;\
		struct kRawPtr   *p; \
		struct kObject *ox; \
		struct kConverter         *conv;\
		struct kContext           *cx;\
		struct kScript            *scr;\
		struct kAssurance         *as;\
		struct kToken             *tk;\
		struct kStmt              *stmt;\
		struct kExpr              *expr;\
		struct kBlock             *bk;\
		struct kLang              *lang;\
		struct kGamma             *gma;\
		struct knh_Build_t             *bui;\
		kint_t     dummy_ivalue;\
		kfloat_t   dummy_fvalue \

typedef struct ksfp_t {
	union {
		K_FRAME_MEMBER;
	};
	union {
		K_FRAME_NCMEMBER;
	};
} ksfp_t;

#define K_USING_RBP_                  1

#ifdef K_USING_RBP_
typedef struct krbp_t {
	union {
		K_FRAME_NCMEMBER;
		K_FRAME_MEMBER;
	};
} krbp_t;
#else
typedef struct krbp_t {
	union {
		K_FRAME_NCMEMBER;
	};
	union {
		K_FRAME_MEMBER;
	};
} krbp_t;
#endif

/* ------------------------------------------------------------------------ */
/* [ObjectFunc] */

#define O_hasRef(o)   (1/*O_cTBL(o)->fast_reftrace != NONE_reftrace*/)

typedef void (*knh_Ftraverse)(CTX, Object *);
#define K_USING_FASTREFS_  1

#define FTRARG    , struct kObject** tail_
#define FTRDATA   , tail_

#define KNH_ENSUREREF(ctx, SIZE)  tail_ = knh_ensurerefs(ctx, tail_, SIZE)
#define KNH_SIZEREF(ctx)  knh_sizerefs(ctx, tail_)
#define KNH_SETREF(ctx, LIST, SIZE)  knh_setrefs(ctx, LIST, SIZE)

#define KNH_ADDREF(ctx, p)  {\
		DBG_ASSERT(p != NULL);\
		tail_[0] = (Object*)p;\
		tail_++;\
	}\

#define KNH_ADDNNREF(ctx, p)  if(p != NULL) {\
		tail_[0] = (Object*)p;\
		tail_++;\
	}\

typedef void (*knh_Freftrace)(CTX, Object * FTRARG);

typedef kuintptr_t                khashcode_t;  /* khashcode_t */
#define knh_hcode_join(s1,s2)	   ((khashcode_t)s1 << (sizeof(kshort_t)*8)) + s2;

typedef struct kObject* (*knh_Fdefnull)(CTX ctx, kclass_t cid);

typedef struct {
	kflag_t    flag  ;
	kshort_t   israw ;
	ktype_t    type  ;
	ksymbol_t  fn    ;
} kfieldinfo_t ;

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
	struct kOutputStream *w;  // always set
	void *pk;      // for msgpack
	void *sbuffer; // for msgpack
} kpackAPI_t;

typedef struct knh_PackSPI_t {
	const char *name;
	void* (*pack_init)(CTX, kpackAPI_t *);
	void  (*pack_flushfree)(CTX, kpackAPI_t *);
	void  (*pack_null)(CTX, void*);
	void  (*pack_bool)(CTX, void*, int d);
	void  (*pack_int)(CTX, void*, kint_t d);
	void  (*pack_float)(CTX, void*, kfloat_t d);
	void  (*pack_string)(CTX, void*, const char *str, size_t n);
	void  (*pack_raw)(CTX, void*, const char *str, size_t n);
	void  (*pack_putc)(CTX, void*, int ch);  // use for delim : or ,
	void  (*pack_beginarray)(CTX, void*, size_t n);
	void  (*pack_endarray)(CTX, void*);   // unnecessary for msgpack
	void  (*pack_beginmap)(CTX, void*, size_t n);
	void  (*pack_endmap)(CTX, void*);     // unnecessary for msgpack
	ktype_t (*unpack)(CTX, const char *, size_t, ksfp_t*);   // put sfp[0]
//	ktype_t (*unpackS)(CTX, struct kInputStream *, ksfp_t*);   // put sfp[0]
} knh_PackSPI_t;


typedef struct kclassdef_t {
	void (*init)(CTX, struct kRawPtr*);
	void (*initcopy)(CTX, struct kRawPtr*, struct kRawPtr*);
	void (*reftrace)(CTX, struct kRawPtr* FTRARG);
	void (*free)(CTX, struct kRawPtr*);
	void (*checkin)(CTX, ksfp_t *sfp, struct kRawPtr*);
	void (*checkout)(CTX, struct kRawPtr*, int);
	int  (*compareTo)(struct kRawPtr*, struct kRawPtr*);
	void (*p)(CTX, struct kOutputStream*, struct kRawPtr*, int);

	struct kString* (*getkey)(CTX, ksfp_t*);
	khashcode_t       (*hashCode)(CTX, struct kRawPtr*);
//	kint_t   (*toint)(CTX ctx, ksfp_t*);
//	kfloat_t (*tofloat)(CTX ctx, ksfp_t*);
	void *RESERVED0;
	void *RESERVED1;
//	struct kTypeMap* (*findTypeMapNULL)(CTX, kclass_t, kclass_t, int);
	void *RESERVED1_1;
	void (*wdata)(CTX, struct kRawPtr*, void *, const knh_PackSPI_t *);
	void *RESERVED2;
	void *RESERVED3;

	const char             *name;
	kflag_t              cflag;
	kushort_t            struct_size;
	kfieldinfo_t            *fields;

	knh_Fdefnull            getDefaultNull;
	void *RESERVED4;
	void *RESERVED5;
	//void *RESERVED6;
	size_t c_struct_size;
	size_t asize;           /* set it to zero usually */
} kclassdef_t;

/* ------------------------------------------------------------------------ */

#define K_CLASSTABLE_INIT 128

typedef struct knh_ClassTBL_t {
	const kclassdef_t *cdef;
	kuintptr_t magicflag;
	kflag_t    cflag;        kuri_t     domain;
	kclass_t   cid;          kclass_t   imcid;
	kclass_t   bcid;         kclass_t   supcid;
	const struct knh_ClassTBL_t *baseTBL;
	const struct knh_ClassTBL_t *supTBL;
	struct kParam     *cparam;
	kclass_t   p1;           kclass_t   p2;
	struct kClass          *typeNULL;
	struct kString         *lname;
	struct kString         *sname;
	struct kArray          *methods;
	struct kArray          *typemaps;
	kfieldinfo_t                *fields;
	kushort_t  fsize;         kushort_t  fcapacity;
	kshort_t   keyidx;        kshort_t   xdataidx;
	union {
		struct kObject  *protoNULL;
		const struct knh_ClassTBL_t     *simTBL;
	};
	knh_Fdefnull               fdefnull;
	union {
		struct kObject       *defnull;
		struct kObject  *defobj;
		struct kFunc         *deffunc;
//		struct kSemantics    *cspec;
	};
	struct kDictMap          *constDictCaseMapNULL;
	struct kPtrMap           *constPoolMapNULL;
	size_t subclass;
	size_t count;
	size_t total;
	size_t struct_size;
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
	kflag_t   flag;
	kevent_t   parent;
	struct kString     *name;
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
	long                        gcObjectCount;
	kuint64_t markingTime;   // marking time [ms]
	kuint64_t sweepingTime;  // sweeping time [ms]
	kuint64_t gcTime;        // total gc time [ms]
	size_t gcCount;             // How many times GC occured.
	kuint64_t latestGcTime;  // lastest time
	size_t markedObject;
	size_t movedObject;
	size_t collectedObject;
} kstatinfo_t;


/* ------------------------------------------------------------------------ */
/* [SystemShare] */

#define SIZEOF_TSTRING (sizeof(kObject*) * K_TSTRING_SIZE)

#define KNH_ENC             ctx->share->enc

#define KNH_NULL            (ctx->share->constNull)
#define KNH_TRUE            (ctx->share->constTrue)
#define KNH_FALSE           (ctx->share->constFalse)
#define K_EMPTYARRAY        (ctx->share->emptyArray)
#define KNH_SYSTEM          (ctx->sys)
#define knh_Object_sweep    knh_Object_RCsweep

struct kStmtExpr;
typedef void (*fMethod_compile)(CTX, struct kMethod *, struct kStmtExpr *);

typedef struct kshare_t {
	/* system table */
	const knh_ClassTBL_t    **ClassTBL;
	size_t                    sizeClassTBL;
	size_t                    capacityClassTBL;

	const knh_EventTBL_t     *EventTBL;
	size_t                    sizeEventTBL;
	size_t                    capacityEventTBL;


	kmutex_t              *syslock;

	/* system shared const */
	struct kObject      *constNull;
	struct kObject      *constTrue;
	struct kObject      *constFalse;
	struct kString     **tString;
	struct kArray       *emptyArray;
	struct kPath        *cwdPath;
	struct kNameSpace   *rootns;
	struct kcontext_t     *ctx0;   // root context
	struct kScript      *script;
	struct kDictSet     *funcDictSet;   //


	struct kopl_t      *PRECOMPILED_LAUNCH;
	struct kopl_t      *PRECOMPILED_FUNCCALL;
	struct kopl_t      *PRECOMPILED_VEXEC;
//	struct kopl_t      *PC_ABSTRACT;

	/* system */
	struct kDictMap     *sysAliasDictMap;
	struct kLang        *corelang;     // core lang
	struct kPtrMap      *inferPtrMap;  // mapinfer
	struct kPtrMap      *constPtrMap;
	struct kPtrMap      *xdataPtrMap;
	struct kArray       *constPools;

	/* symbol, names */
	struct kDictMap       *packageDictMap;
	struct kDictMap       *securityDictMap; // added by Wakamori
	struct kDictSet       *classNameDictSet;
	struct kDictSet       *eventDictSet;
	struct kDictSet       *streamDpiDictSet;
	struct kDictSet       *convDpiDictSet;
	struct kDictSet       *rconvDpiDictSet;
	struct kDictSet       *mapDpiDictSet;

	struct kDictMap*      props;
	struct kInputStream*  in;
	struct kOutputStream* out;
	struct kOutputStream* err;
	struct kString*       enc;

	struct kDictSet       *tokenDictSet;
	struct kDictSet       *symbolDictCaseSet;
	struct kArray         *symbolList;
	struct kDictSet       *urnDictSet;
	struct kArray         *urns;
//	struct kDictMap       *URNAliasDictMap;

	/* thread */
	size_t              contextCounter;
	size_t              threadCounter;
	struct kArray *contextListNULL;  // for matz
	int									stopCounter;
	int									gcStopCounter;
	knh_cond_t				 *stop_cond;
	knh_cond_t				 *start_cond;
	knh_cond_t				 *close_cond;

	/* CompilerAPI */
	struct kObject *konoha_compiler;
	fMethod_compile compilerAPI;
} kshare_t ;

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
	kclass_t cid; kmethodn_t mn;
} kcachedata_t;

typedef struct knh_mtdcache_t {
	kclass_t cid; kmethodn_t mn;
	struct kMethod *mtd;
} knh_mtdcache_t ;

#define hashcode_mtd(cid, mn, HMAX) (((((khashcode_t)cid) << (sizeof(kclass_t) * 8)) + mn) % HMAX)

typedef struct knh_tmrcache_t {
	kclass_t scid; kclass_t tcid;
	struct kTypeMap *tmr;
} knh_tmrcache_t ;

#define hashcode_tmr(scid, tcid, HMAX) (((((khashcode_t)scid) << (sizeof(kclass_t) * 8)) + tcid) % HMAX)

#ifdef K_USING_ICONV
#include<iconv.h>
typedef iconv_t knh_iconv_t;
#else
typedef long knh_iconv_t;
#endif

struct knh_logdata_t;
struct kIterator;

typedef const char* knh_ldata_t;

typedef struct knh_ServiceSPI_t {
	/* sync spi */
#ifdef K_USING_DEBUG
	int (*lockSPI)(kmutex_t *m, const char *_file, const char* _func, int _line);
	int (*unlockSPI)(kmutex_t *m, const char *_file, const char* _func, int _line);
#else
	int (*lockSPI)(kmutex_t *m);
	int (*unlockSPI)(kmutex_t *m);
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
	void  (*setsfpSPI)(CTX, ksfp_t *, void *);
	void  (*closeItrSPI)(CTX, struct kIterator *);
	// evidence
	void (*ntraceSPI)(CTX, const char *, int, knh_ldata_t *);
	void  (*pSPI)(const char*, const char*, int, const char*, ...);
} knh_ServiceSPI_t;

#define WCTX(ctx)     ((kcontext_t*)ctx)

typedef struct kcontext_t {
	int						      safepoint; // set to 1
	/* @Sharable */
	union {
		const kshare_t         *share;
		kshare_t *wshare;   // writable
	};
	struct kmemshare_t             *memshare;
	struct kmemlocal_t             *memlocal;
	kstatinfo_t                    *stat;
	const knh_ServiceSPI_t         *spi;
	const struct kpackageapi_t        *api2;
	struct kScript*         script;  // sharable or not?

	/* stack */
	ksfp_t*                      stack;
	ksfp_t*                      esp;
	size_t                       stacksize;
	ksfp_t*                      stack_uplimit;
	void*                        cstack_bottom;  // for GC
	struct kException           *e;
	struct kExceptionHandler    *ehdrNC;
	struct kObject              *evaled;
	kbool_t                      isEvaled;
	struct kArray               *errmsgs;
	struct kArray               *gcstack;

	/* cache */
	knh_mtdcache_t              *mtdcache;
	knh_tmrcache_t              *tmrcache;

	struct kString*         enc;
	struct kInputStream*    in;
	struct kOutputStream*   out;
	struct kOutputStream*   err;
	struct kBytes*          bufa;
	struct kOutputStream*   bufw;
	struct kGammaBuilder*          gma;

#ifndef K_USING_STRINGPOOL
	struct kDictMap*        symbolDictMap;
#endif

	kflag_t                   flag;
	kushort_t                 ctxid;
	struct kContext        *ctxobjNC;
	struct kcontext_t        *parent;
	kmutex_t                 *ctxlock;

	/* logging */
	char                            trace[16];  // random
	kuint_t                      seq;        // for logging
	/* signal */
	int                             signal;
	void                           *siginfo;
#if defined(K_USING_MINGW_)
#define K_SIGNAL_MAX NSIG
#else
#define K_SIGNAL_MAX _POSIX_SIGQUEUE_MAX
#endif
	struct kFunc             **sighandlers; // modified by Wakamori

} kcontext_t ;

#define IS_RUNNING(ctx) ((ctx)->ctxobjNC != NULL)

#define SAFEPOINT_GC                  1
#define SAFEPOINT_SETGC(ctx)          WCTX(ctx)->safepoint |= SAFEPOINT_GC

#define SAFEPOINT_SIGNAL     (1<<1)
#define SAFEPOINT_SETSIGNAL(ctx)      WCTX(ctx)->safepoint |= SAFEPOINT_SIGNAL

#define SAFEPOINT_MONITOR    (1<<2)
#define SAFEPOINT_SETMONITOR(ctx)     WCTX(ctx)->safepoint |= SAFEPOINT_MONITOR

#define INIT_GCSTACK(ctx)         size_t gcstack_ = knh_Array_size(ctx->gcstack)
#define PUSH_GCSTACK(ctx, o)      knh_Array_add(ctx, ctx->gcstack, o)
#define RESET_GCSTACK(ctx)        knh_Array_clear(ctx, ctx->gcstack, gcstack_)

/* ------------------------------------------------------------------------ */
/* logdata */


#define LOG_END       ((const char*)0L)
#define LOGT_s        1
#define LOG_s(K,V)    ((const char*)LOGT_s), K, V
#define LOG_msg(V)    ((const char*)LOGT_s), "msg", V
#define LOG_t(K, V)   ((const char*)LOGT_s), K, (TYPE__(V))
#define LOGT_i        2
#define LOG_i(K,V)    ((const char*)LOGT_i), K, ((const char*)(kintptr_t)(V))
#define LOGT_u        3
#define LOG_u(K,V)    ((const char*)LOGT_u), K, ((const char*)(kuintptr_t)(V))
#define LOGT_f        4
#define LOG_f(K,V)    ((const char*)LOGT_f), K, ((const char*)(kintptr_t)((V)*1000))
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

#define KNH_LDATA(...) { __VA_ARGS__, LOG_END}
#define KNH_LDATA0     {LOG_END}
#define KNH_NTRACE2(ctx, event, pe, L) do {\
	knh_ldata_t ldata[] = L;\
	KNH_NTRACE(ctx, event, pe, ldata);\
} while (0)
#define KNH_NTHROW2(ctx, sfp, fault, event, pe, L) do {\
	knh_ldata_t ldata[] = L;\
	KNH_NTRACE(ctx, event, pe, ldata);  \
	knh_nthrow(ctx, sfp, fault, ldata); \
} while (0)


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

typedef const kcontext_t* konoha_t;

#define KONOHA_BEGIN(v)   knh_beginContext(v, (void**)&v)
#define KONOHA_END(v)     knh_endContext(v)

/* ------------------------------------------------------------------------ */
/* cwb */
/* ------------------------------------------------------------------------ */

typedef struct {
	struct kBytes          *ba;
	struct kOutputStream   *w;
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
typedef void (CC_EXPORT *knh_Fmethod)(CTX, ksfp_t* _RIX);
typedef void (CC_EXPORT *knh_Ftypemap)(CTX, ksfp_t * _RIX);
typedef int  (CC_EXPORT *knh_Fitrnext)(CTX, ksfp_t * _RIX);
#else
#define KMETHOD  void  CC_FASTCALL_
#define TYPEMAP  KMETHOD
#define ITRNEXT int   CC_FASTCALL_
typedef KMETHOD (*knh_Fmethod)(CTX, ksfp_t* _RIX);
typedef TYPEMAP (*knh_Ftypemap)(CTX, ksfp_t * _RIX);
typedef ITRNEXT (*knh_Fitrnext)(CTX, ksfp_t * _RIX);
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
	struct kRawPtr *kself;
	int isGCSync;
	KSObject(const KSObject &);
	KSObject operator=(const KSObject &);
};
}

#endif

#endif /*KONOHA_T_H_*/
