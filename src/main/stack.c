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

/* ************************************************************************ */

#include"commons.h"

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------------ */

ksfp_t* knh_stack_initexpand(CTX ctx, ksfp_t *sfp, size_t n)
{
	kcontext_t *ctxo = (kcontext_t*)ctx;
	size_t i, s = 0;
	if(sfp == NULL) {
		DBG_ASSERT(ctxo->stacksize == 0);
		s = 0;
		ctxo->stacksize = n;
		ctxo->stack = (ksfp_t*)KNH_MALLOC(ctx, sizeof(ksfp_t) * ctxo->stacksize);
		ctxo->esp = ctxo->stack;
		ctxo->mtdcache = (knh_mtdcache_t*)KNH_MALLOC(ctx, K_MTDCACHE_SIZE * sizeof(knh_mtdcache_t));
		knh_bzero(ctxo->mtdcache, K_MTDCACHE_SIZE * sizeof(knh_mtdcache_t));
		ctxo->tmrcache = (knh_tmrcache_t*)KNH_MALLOC(ctx, K_TMAPCACHE_SIZE * sizeof(knh_tmrcache_t));
		knh_bzero(ctxo->tmrcache, K_TMAPCACHE_SIZE * sizeof(knh_tmrcache_t));
		KNH_INITv(ctxo->bufa, new_Bytes(ctx, "cwbbuf", K_PAGESIZE * 4));
		KNH_INITv(ctxo->bufw, new_BytesOutputStream(ctx, ctxo->bufa));
	}
#ifdef K_USING_STACKEXPANSION
	else if(ctxo->stacksize < K_STACK_MAXSIZ) {
		ksfp_t **cstack_top = &sfp;
		ksfp_t *oldstack = ctxo->stack;
		size_t espidx = (ctxo->esp - ctxo->stack);
		size_t size = ctxo->stacksize, newsize = ctxo->stacksize * 2;
		if(newsize < size + n) newsize = size + n;
#ifdef K_USING_LINUX_
		/* TODO stack rewriting may not work on Linux */
		KNH_TODO("stack rewriting");
#endif
		// Don't use realloc
		ctxo->stack = (ksfp_t*)KNH_MALLOC(ctx, newsize*sizeof(ksfp_t));
		knh_memcpy(ctxo->stack, oldstack, size*sizeof(ksfp_t));
		KNH_MEMINFO(ctx, "realloc ctx->stack oldsize=%d, newsize=%d, oldblock=(%p,%p) newblock=(%p,%p)",
			(int)size, (int)newsize, oldstack, oldstack+size, ctxo->stack, ctxo->stack+newsize);
		if(oldstack != ctxo->stack) {
			ksfp_t **p = (ksfp_t**)ctxo->cstack_bottom;
			if(!(ctxo->cstack_bottom < (void*)cstack_top)) {
				p = cstack_top;
				cstack_top = (ksfp_t**)ctxo->cstack_bottom;
			}
			while(p <= cstack_top) {
				kuintptr_t addr = (kuintptr_t)p[0];
				if((oldstack<= p[0] && p[0] < oldstack + size) && addr % sizeof(void*) == 0) {
					ksfp_t *newsfp = p[0] + (ctxo->stack - oldstack);
					KNH_ASSERT(ctxo->stack <= newsfp && newsfp < ctxo->stack + size);
					//DBG_P("addr=%lld, sfp=%p[%d] => %p[%d]", (kint_t)(addr % sizeof(void*)), p[0], (int)(p[0]->ivalue), newsfp, (int)newsfp->ivalue);
					KNH_ASSERT((p[0])->ndata == newsfp->ndata);
					p[0] = newsfp;
				}
				p++;
			}
		}
		ctxo->stacksize = newsize;
		ctxo->esp = ctxo->stack + espidx;
		KNH_FREE(ctx, oldstack, size*sizeof(ksfp_t));
		s = size;
	}
#endif
	else {
		THROW_StackOverflow(ctx, sfp);
	}
	for(i = s; i < ctxo->stacksize; i++) {
		KNH_INITv(ctxo->stack[i].o, KNH_NULL);
		ctxo->stack[i].ndata = 0;
	}
	ctxo->stack_uplimit = ctxo->stack + (ctxo->stacksize - K_GAMMAMAX);
	return sfp;
}

/* ------------------------------------------------------------------------ */

void knh_stack_clear(CTX ctx, ksfp_t *sfp)
{
	if(!(ctx->stack <= sfp && sfp < ctx->stack_uplimit)) {
		sfp = ctx->stack; // sometimes, rewriting pointer is failed.
	}
	while(sfp < ctx->stack + ctx->stacksize) {
		KNH_SETv(ctx, sfp[0].o, KNH_NULL);
		sfp[0].ndata = 0;
		sfp++;
	}
}

/* ------------------------------------------------------------------------ */

ksfp_t* knh_stack_local(CTX ctx, size_t n)
{
	long remaining = ctx->stacksize - ((ctx->esp - ctx->stack) + (n + 64));
	if(remaining < 0) {
		DBG_P("LACK OF STACK: stacksize=%d, remaining=%d", ctx->stacksize , remaining);
		knh_stack_initexpand(ctx, ctx->esp, ctx->stacksize + n + 64);
	}
	ksfp_t *esp = ctx->esp;
	((kcontext_t*)ctx)->esp = esp + n;
	return esp;
}

void knh_checkSafePoint(CTX ctx, ksfp_t *sfp, const char *file, int line)
{
	int safepoint = ctx->safepoint;
	WCTX(ctx)->safepoint = 0;
	if(TFLAG_is(int, safepoint, SAFEPOINT_GC)) {
		if(line != 0) {
			GC_LOG("%s:%d safepoint=%d", file, line, safepoint);
		}
		invoke_gc(ctx);
	}
	if(TFLAG_is(int, safepoint, SAFEPOINT_SIGNAL)) {
		if (ctx->sighandlers != NULL) {
			KNH_ASSERT(ctx->signal < K_SIGNAL_MAX);
			kFunc *handler_func = (kFunc *)ctx->sighandlers[ctx->signal];
			if (handler_func != NULL) {
				ksfp_t *lsfp = ctx->esp + 1; // for safety
				lsfp[K_CALLDELTA + 1].ivalue = ctx->signal;
				knh_Func_invoke(ctx, handler_func, lsfp, 1/* argc */);
			}
		}
		WCTX(ctx)->signal = 0;
	}
	if(TFLAG_is(int, safepoint, SAFEPOINT_MONITOR)) {
		//
	}
}

///* ------------------------------------------------------------------------ */
///* [call] */
//
//void knh_stack_typecheck(CTX ctx, ksfp_t *sfp, kMethod *mtd, kopl_t *pc)
//{
//	kclass_t this_cid = O_cid(sfp[0].o);
//	int i, argc;
//	DBG_ASSERT(IS_Method(sfp[K_MTDIDX].mtdNC));
//	argc = Param_isVARGs(DP(mtd)->mp) ? (ctx->esp - sfp) : knh_Method_psize(mtd);
//	for(i = 1; i < argc; i++) {
//		ktype_t reqt = knh_Method_ptype(ctx, mtd, this_cid, i - 1);
//		const knh_ClassTBL_t *t = O_cTBL(sfp[i].o);
//		if(!ClassTBL_isa(t, reqt)) {
//			THROW_ParamTypeError(ctx, sfp, (mtd)->mn, i, reqt, O_cid(sfp[i].o));
//			break;
//		}
//	}
//	return;
//}


///* ------------------------------------------------------------------------ */
//
//KNHAPI2(void) konoha_throwSecurityException(void)
//{
//	CTX ctx = knh_getCurrentContext();
//	knh_stack_throw(ctx, new_Exception(ctx, knh_getEventName(ctx, EVENT_Security)), NULL, 0);
//}


/* ------------------------------------------------------------------------ */
/* [Event] */

int event_isa(CTX ctx, kevent_t eid, kevent_t parent)
{
	ASSERT_ebi(eid);
	DBG_ASSERT(parent <= ctx->share->sizeEventTBL);
	if(eid == parent || parent == EVENT_Exception) return 1;
	while((eid = ctx->share->EventTBL[eid].parent) != EVENT_Exception) {
		if(eid == parent) return 1;
	}
	return 0;
}

/* ------------------------------------------------------------------------ */

kString *knh_getEventName(CTX ctx, kevent_t eid)
{
	ASSERT_ebi(eid);
	return ctx->share->EventTBL[eid-1].name;
}

/* ------------------------------------------------------------------------ */
/* [TABLE] */

kevent_t knh_addEvent(CTX ctx, kflag_t flag, kString *name, kclass_t peid)
{
	kevent_t eid = 0;
	OLD_LOCK(ctx, LOCK_SYSTBL, NULL);
	if(ctx->share->sizeEventTBL == ctx->share->capacityEventTBL) {
		knh_EventTBL_expand(ctx);
	}
	eid = ctx->share->sizeEventTBL;
	((kshare_t*)ctx->share)->sizeEventTBL += 1;
	OLD_UNLOCK(ctx, LOCK_SYSTBL, NULL);

	{
		knh_EventTBL_t *et = pEventTBL(eid);
		DBG_ASSERT(et->name == NULL);
		et->flag = flag;
		et->parent = peid;
		KNH_INITv(et->name, name);
		OLD_LOCK(ctx, LOCK_SYSTBL, NULL);
		knh_DictSet_set(ctx, ctx->share->eventDictSet, name, eid+1);
		OLD_UNLOCK(ctx, LOCK_SYSTBL, NULL);
	}
	return eid;
}

kbool_t knh_isDefinedEvent(CTX ctx, kbytes_t t)
{
	int eid;
	kintptr_t loc = knh_bytes_index(t, '!');
	if(loc != -1) {
		t = knh_bytes_first(t, loc);
	}
	OLD_LOCK(ctx, LOCK_SYSTBL, NULL);
	eid = (kevent_t)knh_DictSet_get(ctx, ctx->share->eventDictSet, t);
	OLD_UNLOCK(ctx, LOCK_SYSTBL, NULL);
	return (eid > 0) ;
}

kevent_t knh_geteid(CTX ctx, kbytes_t t)
{
	kevent_t eid = EVENT_Exception;
	kintptr_t loc = knh_bytes_index(t, '!');
	if(loc != -1) {
		t = knh_bytes_first(t, loc);
	}
	OLD_LOCK(ctx, LOCK_SYSTBL, NULL);
	eid = (kevent_t)knh_DictSet_get(ctx, ctx->share->eventDictSet, t);
	OLD_UNLOCK(ctx, LOCK_SYSTBL, NULL);
	if(eid == 0) {
		return knh_addEvent(ctx, 0, new_String2(ctx, CLASS_String, t.text, t.len, SPOL_ASCII|SPOL_POOLALWAYS), EVENT_Exception);
	}
	else {
		return eid - 1;
	}
}

/* ------------------------------------------------------------------------ */
/* [Exception.new] */

kException* new_Error(CTX ctx, kline_t uline, kString *emsg)
{
	kException* e = new_(Exception);
	KNH_SETv(ctx, e->emsg, emsg);
	e->uline = uline;
	return e;
}

void CTX_setThrowingException(CTX ctx, kException *e)
{
	KNH_SETv(ctx, ((kcontext_t*)ctx)->e, e);
}

/* rbp is ok, because isCATCH is called from only vm */
kbool_t isCATCH(CTX ctx, krbp_t *rbp, int en, kevent_t peid)
{
	kException *e = ctx->e;
	kevent_t eid = knh_geteid(ctx, S_tobytes(e->emsg));
	int res = event_isa(ctx, eid, peid);
	if(res == 1) {
		KNH_SETv(ctx, rbp[en].o, e);
		KNH_SETv(ctx, ((kcontext_t*)ctx)->e, KNH_NULL);
	}
	return res;
}

void Context_push(CTX ctx, kObject *o)
{
	kArray *a = ctx->ehdrNC->stacklist;
	knh_Array_add(ctx, a, o);
}

kObject *Context_pop(CTX ctx)
{
	kArray *a = ctx->ehdrNC->stacklist;
	DBG_ASSERT(a->size > 0);
	a->size -= 1;
	{
		kObject *o = a->list[a->size];
		KNH_FINALv(ctx, a->list[a->size]);
		return o;
	}
}

/* ------------------------------------------------------------------------ */

#ifndef K_USING_SETJMP_

#if defined(__i386__)
#define reg(r) "%%e" r
#elif defined(__x86_64__)
#define reg(r) "%%r" r
#endif

/*
 * we verified setjmp, longjmp at
 *  * MacOSX x86_64 GCC 4.0.1/4.2.1 (-O0/-O1/-O2)
 *  * MacOSX i386   GCC 4.0.1 (-O2)
 */

kExceptionHandler* ExceptionHandler_setjmp(CTX ctx, kExceptionHandler *hdr)
{
#if !defined(__i386__) && !defined(__x86_64__)
#warning ExceptionHandler dose not work in your environment. Please define K_USING_SETJMP_=1
#else
#if defined(__GNUC__)
	kuintptr_t rsp;
	asm volatile ("mov " reg("sp") ", %0;" : "=r" (rsp));
	DP(hdr)->return_address = __builtin_return_address(0);
	DP(hdr)->frame_address = __builtin_frame_address(1);
#if defined(__i386__)
	DP(hdr)->stack_pointer = rsp + 0x08;
#elif defined(__x86_64__)
	DP(hdr)->stack_pointer = rsp + 0x10;
#endif
#endif
#endif
	return NULL;
}

kExceptionHandler *knh_ExceptionHandler_longjmp(CTX ctx, kExceptionHandler *hdr)
{
#if defined(__GNUC__)
#if defined(__i386__)
	//@shinpei_NKT : fixed offset of kExceptionHandler, i386 code
	asm volatile(
			"pop %%ebp;"
			"mov 0x10(%%eax),%%esi;" /* esi = DP(hdr) */
			"mov 0x0c(%%esi),%%edx;" /* edx = DP(hdr)->return_address */
			"mov 0x10(%%esi),%%ebp;" /* ebp = DP(hdr)->frame_address */
			"mov 0x14(%%esi),%%esp;" /* esp = DP(hdr)->stack_pointer */
			"pop %%esi;"
			"jmp *%%edx;"
			::
			"a"(hdr)
			: "%esi", "%edx");
#elif defined(__x86_64__)
	asm volatile(
			"pop %%rbp;"
			"mov %0,%%rsi;"
			"mov %%rsi,%%rbp;"
			"mov %2,%%rsp;"
			"mov %3,%%rax;"
			"mov %4, %%rsi;"
			"mov %%rsi, %%rdi;"
			"jmp *%1;"
			::
			"r"(DP(hdr)->frame_address),
			"r"(DP(hdr)->return_address),
			"r"(DP(hdr)->stack_pointer),
			"r"(hdr),
			"r"(ctx)
			: "%rax", "%rsi", "%rdi");
#endif
#endif
	return hdr;
}
#endif/*K_USING_SETJMP_*/

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
