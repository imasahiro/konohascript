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

#ifndef KONOHA_GC_H_
#define KONOHA_GC_H_

#include"konoha_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */
/* config for generational gc */

#ifdef K_USING_GENGC

#define GC_TENURE       , 1
#define GC_YOUNG        , 0
#define GC_Tenure       1
#define GC_Young        0
#define GC_ARG          , int isTenure
#define GC_DATA         , isTenure

#define setYoung(o)   (o->h.refc = GC_Young)
#define setTenure(o)  (o->h.refc = GC_Tenure)
#define set_age(o, n) (o->h.refc = n)

//#define isYoung(o)  isYoung_(o)
//#define isTenure(o) isTenure_(o)
#define isYoung(o)  (o->h.refc == GC_Young)
#define isTenure(o) (o->h.refc == GC_Tenure)
#define setRemSet(o) setRemSet_(o)
#define invoke_gc(ctx) invoke_gc_(ctx)

#else

#define GC_TENURE
#define GC_YOUNG
#define GC_Tenure       0
#define GC_Young        0
#define GC_ARG
#define GC_DATA

#define setYoung(o)
#define setTenure(o)
#define set_age(o, n)

#define isYoung(o)
#define isTenure(o)
#define setRemSet(o)
#define invoke_gc(ctx) knh_System_gc(ctx, 1); // GC enables Cstack trace
#endif

/* ------------------------------------------------------------------------ */
/* common interface for gc.c */

void *knh_malloc(CTX ctx, size_t size);
void knh_free(CTX ctx, void *block, size_t size);
void *knh_valloc(CTX ctx, size_t size);
void knh_vfree(CTX ctx, void *block, size_t size);
void *TRACE_malloc(CTX ctx, size_t size K_TRACEARGV);
void TRACE_free(CTX ctx, void *p, size_t size K_TRACEARGV);
void *TRACE_realloc(CTX ctx, void *p, size_t os, size_t ns, size_t wsize K_TRACEARGV);
kbool_t knh_isObject(CTX ctx, kObject *o);
void kmemshare_init(CTX ctx);
void kmemshare_free(CTX ctx);
void kmemshare_gc_destroy(CTX ctx);
void kmemlocal_init(CTX ctx);
void kmemlocal_free(CTX ctx);
void *knh_xmalloc(CTX ctx, size_t size);
void *knh_fastmalloc(CTX ctx, size_t size);
void knh_fastfree(CTX ctx, void *block, size_t size);
void* knh_fastrealloc(CTX ctx, void *block, size_t os, size_t ns, size_t wsize);
kObject *new_hObject_(CTX ctx, const knh_ClassTBL_t *ct);
kObject *new_Object_init2(CTX ctx, const knh_ClassTBL_t *ct);
void TR_NEW(CTX ctx, ksfp_t *sfp, ksfpidx_t c, const knh_ClassTBL_t *ct);
kObject** knh_ensurerefs(CTX ctx, kObject** tail, size_t size);
void knh_sizerefs(CTX ctx, kObject** tail);
void knh_setrefs(CTX ctx,  kObject** list, size_t size);
void knh_Object_RCfree(CTX ctx, Object *o);
void knh_Object_RCsweep(CTX ctx, Object *o);
void knh_System_gc(CTX ctx, int needsCStackTrace GC_ARG);
void setRemSet_(kObject *o);
void dump_memstat();
#ifdef K_USING_RCGC
void knh_traverse_refs(CTX ctx, knh_Ftraverse ftr);
#endif
void invoke_gc_(CTX ctx);

/* ------------------------------------------------------------------------ */

#define K_RCGC_INIT           0

#ifdef K_USING_RCGC
#define knh_Object_RCinc(o)     (o)->h.refc ++
#define DBG_Object_RCinc(o)    {\
		(o)->h.refc ++; \
		if(O_cid(o) == CLASS_Tdynamic) {\
			DBG_P("p=%p refc=%d", o, o->h.refc);\
		}\
	}\

#define knh_Object_RCplus(o,n)  (o)->h.refc += n
#define knh_Object_DRCsweep(ctx, o)  knh_Object_sweep(ctx, o)
#define knh_Object_RCdec(o)     (o)->h.refc--
#define knh_Object_RCset(o,c)   (o)->h.refc = (c)
#define Object_isRC0(o)     ((o)->h.refc == 0)
#define RCGC_(STMT)             STMT
#define MSGC_(STMT)
#define MTGC_(STMT)

#define KNH_SWAPMOV(ctx, sfp, n, n2) {\
		ksfp_t sfpN = sfp[n];\
		sfp[n] = sfp[n2];\
		sfp[n2] = sfpN;\
	}\

#define KNH_SAFEPOINT(ctx, sfp)
//#define KNH_GC(ctx)  DBG_(knh_System_gc(ctx))
#define O_toTenure(o)

#else/* K_USING_RCGC*/

#ifdef K_USING_MTGC
#define knh_Object_RCinc(o)       (o)->h.mscheck = ctx->mscheck
#define knh_Object_RCplus(o,n)    (o)->h.mscheck = ctx->mscheck
#define MTGC_(STMT)             STMT
#else
#define knh_Object_RCinc(o)
#define knh_Object_RCplus(o,n)
#define MTGC_(STMT)
#endif

#define knh_Object_RCdec(o)
#define Object_isRC0(o)    (0)
#define knh_Object_RCset(o,c)
#define knh_Object_DRCsweep(ctx, o)
#define RCGC_(STMT)
#define MSGC_(STMT)             STMT

#define KNH_SWAPMOV(ctx, sfp, n, n2) {\
		sfp[n] = sfp[n2];\
	}\

#define KNH_SAFEPOINT(ctx, sfp) \
	if(ctx->safepoint != 0) knh_checkSafePoint(ctx, sfp, __FILE__, __LINE__);

#define O_toTenure(o)  kObjectoTenure(ctx, o)

#endif/*K_USING_RCGC*/

#ifdef _MSC_VER
#define OBJECT_SET(v, h) {\
	kObject **v_ = (kObject**)&v; \
	v_[0] = (h_); \
}
#else
#define OBJECT_SET(v, h) v = (typeof(v))(h_)
#endif /*_MSC_VER*/

#define KNH_INITv(v,o) {\
		kObject *h_ = (kObject*)o; \
		DBG_ASSERT_ISOBJECT(h_); \
		knh_Object_RCinc(h_); \
		OBJECT_SET(v, h_);\
	}\

#define KNH_SETv(ctx,v,o) {\
		kObject *h_ = (kObject*)(o); \
		DBG_ASSERT_ISOBJECT(v);  \
		DBG_ASSERT_ISOBJECT(h_); \
		knh_Object_RCinc(h_); \
		knh_Object_DRCsweep(ctx, (kObject*)v); \
		OBJECT_SET(v, h_);\
	}\

#ifdef K_USING_GENGC
/* [write barrier] */
#define knh_writeBarrier(parent, o) {\
		if (unlikely(isTenure(parent))) {\
			setRemSet((kObject *)(o));\
		}\
	}\

#define KNH_INITv_withWB(parent, v, o) {\
		kObject *h_ = (kObject*)o; \
		DBG_ASSERT_ISOBJECT(h_); \
		knh_Object_RCinc(h_); \
		OBJECT_SET(v, h_);\
		knh_writeBarrier(parent, h_);\
	}\

#define KNH_SETv_withWB(ctx, parent, v, o) {\
		kObject *h_ = (kObject*)(o); \
		DBG_ASSERT_ISOBJECT(v);  \
		DBG_ASSERT_ISOBJECT(h_); \
		knh_Object_RCinc(h_); \
		knh_Object_DRCsweep(ctx, (kObject*)v); \
		OBJECT_SET(v, h_);\
		knh_writeBarrier(parent, h_);\
	}\

#else 
#define knh_writeBarrier(parent, o)
#define KNH_INITv_withWB(parent, v, o) KNH_INITv(v, o)
#define KNH_SETv_withWB(ctx, parent, v, o) KNH_SETv(ctx, v, o)

#endif
#define KNH_RCSETv(ctx,v,o) {\
		kObject *h_ = (kObject*)o; \
		DBG_ASSERT_ISOBJECT(v);  \
		DBG_ASSERT_ISOBJECT(h_); \
		knh_Object_RCinc(h_); \
		knh_Object_DRCsweep(ctx, (kObject*)v); \
		OBJECT_SET(v, h_);\
	}\

#define KNH_NGCSETv(ctx,v,o) {\
		kObject *h_ = (kObject*)o; \
		DBG_ASSERT_ISOBJECT(h_); \
		knh_Object_RCinc(h_); \
		knh_Object_RCdec(v); \
		OBJECT_SET(v, h_);\
	}\

#define KNH_FINALv(ctx, v) {\
		knh_Object_DRCsweep(ctx, UPCAST(v)); \
		v = NULL; \
	}\

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif

#endif /*KONOHA_GC_H_*/
