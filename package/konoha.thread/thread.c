/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c)  2010-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * See www.konohaware.org/license.html for further information.
 *
 * (1) GNU Lesser General Public License 3.0 (with KONOHA_UNDER_LGPL3)
 * (2) Konoha Software Foundation License 1.0
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

// **************************************************************************
// LIST OF CONTRIBUTERS
//  kimio - Kimio Kuramitsu, Yokohama National University, Japan
//  yukkiwakka - Yuuki Wakamatsu, Yokohama National University, Japan
// **************************************************************************

#define K_INTERNAL
#include <konoha1.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ======================================================================== */
// [private functions]

typedef struct {
	kcontext_t *ctx;
	kthread_t thread;
	kFunc *func;
	kArray *args;
} Thread_t;

static void *spawn_start(void *v)
{
	Thread_t *t = (Thread_t *)v;
	kcontext_t *ctx = t->ctx;

	KONOHA_BEGIN(ctx);
	// set ExceptionHandler
	//kExceptionHandler* hdr = new_(ExceptionHandler);
	//ctx->esp[0].hdr = hdr;
	//ctx->esp++;
	// set args
	ksfp_t *sfp = ctx->esp;
	int i, argc = knh_Array_size(t->args);
	for(i=0; i<argc; i++) {
		kObject *o = knh_Array_n(t->args, i);
		switch(O_cid(o)) {
		case CLASS_Int:
			sfp[K_CALLDELTA + i + 1].ivalue = N_toint(o);
			break;
		case CLASS_Float:
			sfp[K_CALLDELTA + i + 1].fvalue = N_tofloat(o);
			break;
		case CLASS_Boolean:
			sfp[K_CALLDELTA + i + 1].bvalue = N_tobool(o);
			break;
		default:
			KNH_SETv(ctx, sfp[K_CALLDELTA + i + 1].o, o);
		}
	}
	knh_Func_invoke(ctx, t->func, sfp, argc);

	//int jump = knh_setjmp(DP(hdr)->jmpbuf);
	//if(jump == 0) {
	//	hdr->espidx = (ctx->esp - ctx->stack);
	//	hdr->parentNC = ctx->ehdrNC;
	//	((kcontext_t*)ctx)->ehdrNC = hdr;
	//	knh_Func_invoke(ctx, t->func, sfp, argc);
	//} else {
	//	/* catch exception */
	//	hdr = ctx->ehdrNC;
	//	((kcontext_t*)ctx)->ehdrNC = hdr->parentNC;
	//}
	//kthread_detach(ctx, t->thread);
	//KNH_FREE(ctx, t, sizeof(Thread_t));

	KNH_SYSLOCK(ctx);
	ctx->ctxobjNC = NULL;
	ctx->wshare->threadCounter--;
	KONOHA_END(ctx);
	if(ctx->share->gcStopCounter != 0) {
		kthread_cond_signal(ctx->share->start_cond);
	}else if(ctx->share->threadCounter == 1) {
		kthread_cond_signal(ctx->share->close_cond);
	}
	KNH_SYSUNLOCK(ctx);
	return NULL;
}

static void Mutex_init(CTX ctx, kRawPtr *po)
{
	po->rawptr = NULL;
}

static void Mutex_free(CTX ctx, kRawPtr *po)
{
	if(po->rawptr != NULL) {
		knh_mutex_free(ctx, (kmutex_t *)po->rawptr);
		po->rawptr = NULL;
	}
}

/* ======================================================================== */
// [KMETHODS]

//## @Native Thread Thread.spawn(dynamic f, dynamic[] args)
KMETHOD Thread_spawn(CTX ctx, ksfp_t *sfp _RIX)
{
	kFunc *f = sfp[1].fo;
	kArray *args = sfp[2].a;
	if(IS_NOTNULL(((kObject *)f))) {
		Thread_t *t = (Thread_t *)KNH_MALLOC(ctx, sizeof(Thread_t));
		kcontext_t *newCtx = new_ThreadContext(WCTX(ctx));
		t->ctx = newCtx;
		t->func = f;
		t->args = args;
		kthread_create(ctx, &(t->thread), NULL, spawn_start, t);
		RETURN_(new_ReturnRawPtr(ctx, sfp, t));
	}
}

//## @Native void Thread.join();
KMETHOD Thread_join(CTX ctx, ksfp_t *sfp _RIX)
{
	Thread_t *t = RawPtr_to(Thread_t *, sfp[0]);
	void *v;

	KNH_SYSLOCK(ctx);
	ctx->wshare->stopCounter++;
	if(ctx->share->gcStopCounter != 0) {
		kthread_cond_signal(ctx->share->start_cond);
	}
	KNH_SYSUNLOCK(ctx);

	kthread_join(ctx, t->thread, &v);

	KNH_SYSLOCK(ctx);
	ctx->wshare->stopCounter--;
	KNH_SYSUNLOCK(ctx);

	RETURNvoid_();
}

//## @Native void Object.synchronized()(dynamic f, dynamic[] args)
KMETHOD Object_synchronized(CTX ctx, ksfp_t *sfp _RIX)
{
	// TODO
	RETURNvoid_();
}

//## @Native Mutex Mutex.new()
KMETHOD Mutex_new(CTX ctx, ksfp_t *sfp _RIX)
{
	kRawPtr *p = sfp[0].p;
	p->rawptr = (void *)knh_mutex_malloc(ctx);
	RETURN_(p);
}

//## @Native void Mutex.lock()
KMETHOD Mutex_lock(CTX ctx, ksfp_t *sfp _RIX)
{
	kmutex_t *m = RawPtr_to(kmutex_t *, sfp[0]);

	KNH_SYSLOCK(ctx);
	ctx->wshare->stopCounter++;
	if(ctx->share->gcStopCounter != 0) {
		kthread_cond_signal(ctx->share->start_cond);
	}
	KNH_SYSUNLOCK(ctx);

	knh_mutex_lock(m);

	KNH_SYSLOCK(ctx);
	ctx->wshare->stopCounter--;
	KNH_SYSUNLOCK(ctx);

	RETURNvoid_();
}

//## @Native void Mutex.unlock()
KMETHOD Mutex_unlock(CTX ctx, ksfp_t *sfp _RIX)
{
	kmutex_t *m = RawPtr_to(kmutex_t *, sfp[0]);
	knh_mutex_unlock(m);
	RETURNvoid_();
}

/* ======================================================================== */
// [DEFAPI]

DEFAPI(void) defThread(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "Thread";
}

DEFAPI(void) defMutex(CTX ctx, kclass_t cid, kclassdef_t *cdef)
{
	cdef->name = "Mutex";
	cdef->init = Mutex_init;
	cdef->free = Mutex_free;
}

#ifdef _SETUP
DEFAPI(const knh_PackageDef_t*) init(CTX ctx, knh_LoaderAPI_t *kapi)
{
	RETURN_PKGINFO("konoha.thread");
}
#endif /* _SETUP */

#ifdef __cplusplus
}
#endif
