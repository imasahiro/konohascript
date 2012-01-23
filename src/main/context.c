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

#define K_DEFINE_API2
#include"commons.h"

#ifdef K_USING_POSIX_
#include <unistd.h>
#endif

#define K_USING_LOADDATA
#include"../../include/konoha1/konohalang.h"

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------ */
/* [Initialize Object] */

static kInputStream *new_InputStreamStdIn(CTX ctx, kString *enc)
{
	kio_t *io2 = new_io2_stdio(ctx, 0, 0);
	return new_InputStream(ctx, io2, new_Path(ctx, TS_DEVSTDIN));
}

static kOutputStream *new_OutputStreamStdOut(CTX ctx, kString *enc)
{
	kio_t *io2 = new_io2_stdio(ctx, 1, 4096);
	kOutputStream *w = new_OutputStream(ctx, io2, new_Path(ctx, TS_DEVSTDOUT));
	OutputStream_setAutoFlush(w, 1);
	return w;
}

static kOutputStream *new_OutputStreamStdErr(CTX ctx, kString *enc)
{
	kio_t *io2 = new_io2_stdio(ctx, 2, 0);
	return new_OutputStream(ctx, io2, new_Path(ctx, TS_DEVSTDERR));
}

/* ------------------------------------------------------------------------ */
/* [ContextTable] */

static kcontext_t* new_hcontext(CTX ctx0)
{
	kcontext_t *ctx;
	static volatile size_t ctxid_counter = 0;
	if(ctx0 == NULL) {
		ctx = (kcontext_t*)malloc(sizeof(kcontext_t));
		knh_bzero(ctx, sizeof(kcontext_t));
	}
	else {
		KNH_ASSERT_CTX0(ctx0);
		ctx = (kcontext_t*)KNH_MALLOC(ctx0, sizeof(kcontext_t));
		knh_bzero(ctx, sizeof(kcontext_t));
	}
	ctx->flag = 0;
	ctx->ctxid = ctxid_counter;
	ctxid_counter++;
//	ctx->freeObjectList = NULL;
//	ctx->freeMemoryList = NULL;
	ctx->parent = ctx;
	ctx->api2 = getapi2();
	{
		kuintptr_t i = 0, ch;
		kuint_t t = knh_rand();
		ch = t % 26;
		ctx->trace[i] = 'A' + ch;
		for(i = 1; i < 9; i++) {
			t = t / 36;
			if (t == 0) t = knh_rand();
			ch = t % 36;
			ctx->trace[i] = (ch < 10) ? '0' + ch : 'A' + (ch - 10);
		}
	}
	ctx->seq = 0;
	ctx->ctxobjNC = NULL;
	if(ctx0 == NULL) {
		const char *ptrace = knh_getenv(K_DEOS_TRACE);
		if(ptrace == NULL) {
			ptrace = "$(setenv " K_DEOS_TRACE ")";
		}
		KNH_NTRACE2(ctx, "konoha:newtrace", K_NOTICE, KNH_LDATA(
					LOG_s("parent", ptrace)
#if defined(K_USING_POSIX_)
					, LOG_u("ppid", getppid())
#endif /* !defined(K_USING_POSIX_) */
					));
	}
	else {
		KNH_NTRACE2(ctx, "konoha:newtrace", K_NOTICE, KNH_LDATA(LOG_s("parent", ctx0->trace), LOG_u("seq", ctx0->seq)));
	}
	return ctx;
}

/* ------------------------------------------------------------------------ */
/* [ContextCommon] */

static void CommonContext_init(CTX ctx, kcontext_t *o)
{
	KNH_ASSERT_CTX0(ctx);
	DBG_ASSERT(o->script != NULL);
	DBG_ASSERT(o->gma != NULL);
	KNH_INITv(o->enc, ctx->share->enc);
	KNH_INITv(o->in,  ctx->share->in);
	KNH_INITv(o->out, ctx->share->out);
	KNH_INITv(o->err, ctx->share->err);
	KNH_INITv(o->e, KNH_NULL);
	KNH_INITv(o->evaled, KNH_NULL);
	KNH_INITv(o->errmsgs, new_Array0(ctx, 0));
	KNH_INITv(o->gcstack, new_Array0(ctx, 0));
#ifndef K_USING_STRINGPOOL
	KNH_INITv(o->symbolDictMap, new_DictMap0(ctx, 256, 0/*isCaseMap*/, "Context.symbolDictMap"));
#endif
//	KNH_INITv(o->constPools, new_Array0(ctx, 0));
	o->ctxlock = knh_mutex_malloc(ctx);
}

static kObject** CommonContext_reftrace(CTX ctx, kcontext_t *ctxo FTRARG)
{
	size_t i;
#ifndef K_USING_STRINGPOOL
	KNH_ADDREF(ctx, ctxo->symbolDictMap);
#endif
//	KNH_ADDREF(ctx, ctxo->constPools);
	KNH_ADDREF(ctx, ctxo->e);
	KNH_ADDREF(ctx, ctxo->evaled);
	KNH_ADDREF(ctx, ctxo->errmsgs);
	KNH_ADDREF(ctx, ctxo->gcstack);
	KNH_ADDREF(ctx, (ctxo->script));
	KNH_ADDREF(ctx, (ctxo->enc));
	KNH_ADDREF(ctx, (ctxo->in));
	KNH_ADDREF(ctx, (ctxo->out));
	KNH_ADDREF(ctx, (ctxo->err));
	KNH_ADDREF(ctx, ctxo->gma);
	// stack
	KNH_ADDREF(ctx, (ctxo->bufa));
	KNH_ADDREF(ctx, (ctxo->bufw));
#ifdef K_USING_RCGC
	KNH_ENSUREREF(ctx, ctxo->stacksize);
	for(i = 0; i < ctxo->stacksize; i++) {
		KNH_ADDREF(ctx, ctxo->stack[i].o);
	}
#else
	{
		size_t stacksize = (ctxo->esp - ctxo->stack) + 8;
		KNH_ENSUREREF(ctx, stacksize);
		for(i = 0; i < stacksize; i++) {
			KNH_ADDREF(ctx, ctxo->stack[i].o);
		}
	}
#endif
	if(ctxo->sighandlers != NULL) {
		KNH_ENSUREREF(ctx, K_SIGNAL_MAX);
		for (i = 0; i < K_SIGNAL_MAX; i++) {
			KNH_ADDNNREF(ctx, ctxo->sighandlers[i]);
		}
	}
	return tail_;
}

static void CommonContext_free(CTX ctx, kcontext_t *ctxo)
{
	KNH_FREE(ctx, ctxo->stack, sizeof(ksfp_t) * ctxo->stacksize);
	ctxo->stack = NULL;
	ctxo->esp = NULL;
	ctxo->stack_uplimit = NULL;
	ctxo->stacksize = 0;
	KNH_FREE(ctx, ctxo->mtdcache,  K_MTDCACHE_SIZE * sizeof(knh_mtdcache_t));
	KNH_FREE(ctx, ctxo->tmrcache, K_TMAPCACHE_SIZE * sizeof(knh_tmrcache_t));
	ctxo->mtdcache  = NULL;
	ctxo->tmrcache = NULL;
	knh_mutex_free(ctxo, ctxo->ctxlock);
	ctxo->ctxlock = NULL;
	ctxo->bufa = NULL;
	if(ctx->sighandlers != NULL) {
		KNH_FREE(ctx, ctx->sighandlers, sizeof(kFunc*) * K_SIGNAL_MAX);
		ctxo->sighandlers = NULL;
	}
}

/* ------------------------------------------------------------------------ */
/* [RootContext] */

static void ClassTBL_expand(CTX ctx)
{
	size_t max = ctx->share->capacityClassTBL * 2;
	const knh_ClassTBL_t **newt = (const knh_ClassTBL_t**)
		KNH_REALLOC(ctx, "ClassTBL", ctx->share->ClassTBL, (ctx->share->capacityClassTBL), max, sizeof(knh_ClassTBL_t*));
	((kshare_t*)ctx->share)->ClassTBL = newt;
	((kshare_t*)ctx->share)->capacityClassTBL = max;
}

kclass_t new_ClassId(CTX ctx)
{
	kclass_t newid = ctx->share->sizeClassTBL;
	if(ctx->share->sizeClassTBL == ctx->share->capacityClassTBL) {
		ClassTBL_expand(ctx);
	}
	DBG_ASSERT(ctx->share->ClassTBL[newid] == NULL);
	{
		knh_ClassTBL_t *ct = (knh_ClassTBL_t*)KNH_MALLOC(ctx, sizeof(knh_ClassTBL_t));
		knh_bzero(ct, sizeof(knh_ClassTBL_t));
		ct->cid    = newid;
		ct->keyidx = -1;
		ct->xdataidx = -1;
		ctx->share->ClassTBL[newid] = ct;
	}
	((kshare_t*)ctx->share)->sizeClassTBL = newid + 1;
	return newid;
}

/* ------------------------------------------------------------------------ */

void knh_EventTBL_expand(CTX ctx)
{
	size_t s = ctx->share->sizeEventTBL, max = ctx->share->capacityEventTBL * 2;
	knh_EventTBL_t *newt = (knh_EventTBL_t*)KNH_MALLOC(ctx, SIZEOF_TEXPT(max));
	knh_bzero(newt, SIZEOF_TEXPT(max));
	knh_memcpy(newt, ctx->share->EventTBL, SIZEOF_TEXPT(s));
	((kshare_t*)ctx->share)->EventTBL = newt;
	((kshare_t*)ctx->share)->capacityEventTBL = max;
}

static void initServiceSPI(knh_ServiceSPI_t *spi);
void knh_loadScriptAliasTermData(CTX ctx);

static kcontext_t* new_RootContext(void)
{
	kcontext_t *ctx = (kcontext_t*)new_hcontext(NULL);
	const knh_LoaderAPI_t *kapi = knh_getLoaderAPI();
	kshare_t *share = (kshare_t*)malloc(sizeof(kshare_t) + sizeof(kstatinfo_t) + sizeof(knh_ServiceSPI_t));
	ctx->share = share;
	knh_bzero(share, sizeof(kshare_t) + sizeof(kstatinfo_t) + sizeof(knh_ServiceSPI_t));
	share->syslock = knh_mutex_malloc(ctx);
	ctx->stat = (kstatinfo_t*)((share+1));
	ctx->spi = (const knh_ServiceSPI_t*)(ctx->stat + 1);
	initServiceSPI((knh_ServiceSPI_t*)ctx->spi);

	kmemshare_init(ctx);
	share->ClassTBL = (const knh_ClassTBL_t**)KNH_MALLOC((CTX)ctx, sizeof(knh_ClassTBL_t*)*(K_CLASSTABLE_INIT));
	knh_bzero(share->ClassTBL, sizeof(knh_ClassTBL_t*)*(K_CLASSTABLE_INIT));
	share->sizeClassTBL = 0;
	share->capacityClassTBL  = K_CLASSTABLE_INIT;

	share->EventTBL = (knh_EventTBL_t*)KNH_MALLOC(ctx, SIZEOF_TEXPT(K_EVENTTBL_INIT));
	knh_bzero((void*)share->EventTBL, SIZEOF_TEXPT(K_EVENTTBL_INIT));
	share->sizeEventTBL = 0;
	share->capacityEventTBL  = K_EVENTTBL_INIT;
	knh_loadScriptSystemStructData(ctx, kapi);

	KNH_INITv(share->funcDictSet, new_DictSet0(ctx, 0, 0, "funcDictSet"));
	KNH_INITv(share->constPtrMap, new_PtrMap(ctx, 0));
	KNH_INITv(share->inferPtrMap, new_PtrMap(ctx, 0));
	KNH_INITv(share->xdataPtrMap, new_PtrMap(ctx, 0));
	KNH_INITv(share->constPools, new_Array0(ctx, 0));
	knh_loadSystemTypeMapRule(ctx);
	knh_ClassTBL_setConstPool(ctx, ClassTBL(CLASS_Int));
	knh_ClassTBL_setConstPool(ctx, ClassTBL(CLASS_Float));
#ifdef K_USING_STRINGPOOL
	knh_ClassTBL_setConstPool(ctx, ClassTBL(CLASS_String));
#endif
	{
		kObject *p = (kObject*)new_hObject_(ctx, ClassTBL(CLASS_Object));
		Object_setNullObject(p, 1);
		KNH_INITv(share->constNull, p);
	}
	{
		kBoolean *o = new_H(Boolean);
		o->n.bvalue = 1;
		KNH_INITv(share->constTrue, o);
		o = new_H(Boolean);
		o->n.bvalue = 0;
		KNH_INITv(share->constFalse, o);
	}
	{
		static const kdim_t dimINIT = {};
		kArray *a = new_H(Array);
		(a)->size = 0;
		(a)->dim = &dimINIT;
		KNH_INITv(share->emptyArray, a);
	}
	share->tString = (kString**)KNH_MALLOC(ctx, SIZEOF_TSTRING);
	knh_bzero(share->tString, SIZEOF_TSTRING);
	knh_loadScriptSystemString(ctx);
	KNH_INITv(share->cwdPath, new_CurrentPath(ctx));

	/* These are not shared, but needed to initialize System*/
	knh_stack_initexpand(ctx, NULL, K_STACKSIZE);
	KNH_INITv(share->packageDictMap, new_DictMap0(ctx, 0, 1/*isCaseMap*/, "packageDictMap"));
	KNH_INITv(share->securityDictMap, new_DictMap0(ctx, 0, 1/*isCaseMap*/, "securityDictMap")); // added by Wakamori
	KNH_INITv(share->classNameDictSet, new_DictSet0(ctx, 128, 1/*isCaseMap*/, "classNameDictSet"));
	KNH_INITv(share->eventDictSet, new_DictSet0(ctx, 32, 1/*isCaseMap*/, "eventDictSet"));
	KNH_INITv(share->streamDpiDictSet, new_DictSet0(ctx, 0, 1/*isCaseMap*/, "streamDpiDictSet"));
	KNH_INITv(share->mapDpiDictSet, new_DictSet0(ctx, 0, 1/*isCaseMap*/, "mapDpiDictSet"));
	KNH_INITv(share->convDpiDictSet, new_DictSet0(ctx, 0, 1/*isCaseMap*/, "convDpiDictSet"));
	KNH_INITv(share->rconvDpiDictSet, new_DictSet0(ctx, 0, 1/*isCaseMap*/, "convDpiDictSet"));

	KNH_INITv(share->enc,   new_T(knh_getSystemEncoding()));
	KNH_INITv(share->in,    new_InputStreamStdIn(ctx, share->enc));
	KNH_INITv(share->out,   new_OutputStreamStdOut(ctx, share->enc));
	KNH_INITv(share->err,   new_OutputStreamStdErr(ctx, share->enc));

	KNH_INITv(share->props, new_DictMap0(ctx, 20, 1/*isCaseMap*/, "System.props"));
	KNH_INITv(share->symbolDictCaseSet, new_DictSet0(ctx, K_TFIELD_SIZE + 10, 1/*isCaseMap*/, "System.symbolDictSet"));
	KNH_INITv(share->symbolList, new_Array0(ctx, K_TFIELD_SIZE + 10));
	KNH_INITv(share->urnDictSet, new_DictSet0(ctx, 0, 0/*isCaseMap*/, "System.urnDictSet"));
	KNH_INITv(share->urns, new_Array0(ctx, 1));
	KNH_INITv(share->corelang, new_(Lang));
	knh_initSugarData(ctx);
	KNH_INITv(share->tokenDictSet, new_DictSet0(ctx, (TT_MAX - STT_MAX), 0/*isCaseMap*/, "System.tokenDictSet"));
//	KNH_INITv(share->URNAliasDictMap, new_DictMap0(ctx, 0, 0/*isCaseMap*/, "System.URNAliasDictMap"));

	KNH_INITv(share->rootns, new_(NameSpace));
	knh_loadScriptSystemData(ctx, share->rootns, kapi);
	knh_System_initPath(ctx);                 // require rootns
	KNH_INITv(ctx->script, new_(Script));     // require rootns
	KNH_INITv(ctx->gma, new_(GammaBuilder));         // require script
	knh_loadScriptSystemKonohaCode(ctx);      // require gamma
	loadPolicy(ctx); // added by Wakamori
	knh_loadScriptSystemMethod(ctx, kapi);
	CommonContext_init(ctx, ctx);
	knh_loadScriptTermData(ctx);
	knh_loadScriptAliasTermData(ctx);
	share->ctx0 = ctx;
	knh_GammaBuilder_init(ctx);  // initalize gamma->gf, reported by uh
	knh_initBuiltInPackage(ctx, knh_getLoaderAPI());

	/* CompilerAPI */
	KNH_INITv(share->konoha_compiler, KNH_NULL);
	share->compilerAPI = NULL;

	share->contextCounter = 1;
	share->threadCounter = 1;
	share->stopCounter = 0;
	share->gcStopCounter = 0;
	KNH_INITv(share->contextListNULL, new_Array0(ctx, 4));
	knh_Array_add(ctx, ctx->share->contextListNULL, knh_toContext(ctx));
#if defined(K_USING_THREAD)
	share->stop_cond = kthread_cond_init(ctx);
	share->start_cond = kthread_cond_init(ctx);
	share->close_cond = kthread_cond_init(ctx);
#endif
	return ctx;
}

kcontext_t *new_ThreadContext(CTX ctx)
{
	KNH_SYSLOCK(ctx);
	kcontext_t *newCtx = new_hcontext(ctx);
	newCtx->share = ctx->share;
	newCtx->stat = ctx->stat;
	newCtx->spi = ctx->spi;
	newCtx->script = ctx->script;
	newCtx->parent = WCTX(ctx);
//	newCtx->freeObjectList = NULL;
//	newCtx->freeObjectTail = NULL;
	KNH_INITv(newCtx->gma, new_(GammaBuilder));
	knh_GammaBuilder_init(newCtx);
	CommonContext_init(ctx, newCtx);
	knh_stack_initexpand(newCtx, NULL, K_STACKSIZE);

	ctx->wshare->contextCounter++;
	ctx->wshare->threadCounter++;
	if(newCtx->ctxobjNC == NULL) {
		newCtx->ctxobjNC = knh_toContext(newCtx);
	}
	knh_Array_add(ctx, ctx->share->contextListNULL, newCtx->ctxobjNC);
	newCtx->safepoint = ctx->share->ctx0->safepoint;
	KNH_SYSUNLOCK(ctx);
	return newCtx;
}

static int _lock(kmutex_t *m DBG_TRACE)
{
	TRACE_P("LOCK mutex=%p", m);
	return 0;
}

static int _unlock(kmutex_t *m DBG_TRACE)
{
	TRACE_P("UNLOCK mutex=%p", m);
	return 0;
}

static int thread_lock(kmutex_t *m DBG_TRACE)
{
	TRACE_P("LOCK mutex=%p", m);
	return knh_mutex_lock(m);
}

static int thread_unlock(kmutex_t *m DBG_TRACE)
{
	TRACE_P("UNLOCK mutex=%p", m);
	return knh_mutex_unlock(m);
}

static knh_iconv_t _iconv_open(const char *t, const char *f)
{
	return (knh_iconv_t)(-1);
}
static size_t _iconv(knh_iconv_t i, char **t, size_t *ts, char **f, size_t *fs)
{
	return 0;
}
static int _iconv_close(knh_iconv_t i)
{
	return 0;
}

static void _setsfp(CTX ctx, ksfp_t *sfp, void *v)
{
	kObject *o = (kObject*)v;
	DBG_ASSERT_ISOBJECT(o);
	knh_Object_RCinc(o);
	knh_Object_RCdec(sfp[0].o);
	if(Object_isRC0(sfp[0].o)) {
		knh_Object_RCfree(ctx, sfp[0].o);
	}
	sfp[0].o = o;
}

extern void (*knh_syslog)(int priority, const char *message, ...);
extern void (*knh_vsyslog)(int priority, const char *message, va_list args);

static void initServiceSPI(knh_ServiceSPI_t *spi)
{
	spi->syncspi = "nothread";
	spi->lockSPI = _lock;
	spi->unlockSPI = _unlock;
	spi->syslogspi = "fprintf(stderr)";
	spi->syslog = knh_syslog;  // unnecessary
	spi->vsyslog = knh_vsyslog;
	spi->iconvspi       = "noiconv";
	spi->iconv_openSPI  = _iconv_open;
	spi->iconvSPI       = _iconv;
	spi->iconv_closeSPI = _iconv_close;
	spi->mallocSPI = knh_fastmalloc;
	spi->freeSPI = knh_fastfree;
	spi->setsfpSPI = _setsfp;
	spi->closeItrSPI = knh_Iterator_close;
	spi->ntraceSPI = knh_ntrace;
	spi->pSPI = dbg_p;
}

/* ------------------------------------------------------------------------ */

void Context_initMultiThread(CTX ctx)
{
	knh_ServiceSPI_t *spi = __CONST_CAST__(knh_ServiceSPI_t*, ctx->spi);
	spi->syncspi   = "thread";
	spi->lockSPI   = thread_lock;
	spi->unlockSPI = thread_unlock;
}
/* ------------------------------------------------------------------------ */

static kObject **share_reftrace(CTX ctx, kshare_t *share FTRARG)
{
	size_t i;
	KNH_ADDREF(ctx,   share->constNull);
	KNH_ADDREF(ctx,   share->constTrue);
	KNH_ADDREF(ctx,   share->constFalse);
	KNH_ADDREF(ctx,   share->emptyArray);
	KNH_ADDREF(ctx,   share->cwdPath);

	KNH_ADDREF(ctx, (share->enc));
	KNH_ADDREF(ctx, (share->in));
	KNH_ADDREF(ctx, (share->out));
	KNH_ADDREF(ctx, (share->err));
	KNH_ADDREF(ctx, (share->props));
	KNH_ADDREF(ctx, (share->symbolDictCaseSet));
	KNH_ADDREF(ctx, (share->symbolList));
	KNH_ADDREF(ctx, (share->urnDictSet));
	KNH_ADDREF(ctx, (share->urns));
	KNH_ADDREF(ctx, (share->tokenDictSet));
	KNH_ADDREF(ctx, (share->corelang));
//	KNH_ADDREF(ctx, (share->URNAliasDictMap));

	KNH_ADDREF(ctx,   share->rootns);
	KNH_ADDREF(ctx,   share->funcDictSet);
	KNH_ADDREF(ctx, share->sysAliasDictMap);
	KNH_ADDREF(ctx,   share->constPtrMap);
	KNH_ADDREF(ctx,   share->inferPtrMap);
	KNH_ADDREF(ctx,   share->xdataPtrMap);
	KNH_ADDREF(ctx,   share->constPools);
	KNH_ADDREF(ctx,   share->packageDictMap);
	KNH_ADDREF(ctx,   share->securityDictMap); // added by Wakamori
	KNH_ADDREF(ctx,   share->classNameDictSet);
	KNH_ADDREF(ctx,   share->eventDictSet);
	KNH_ADDREF(ctx,   share->streamDpiDictSet);
	KNH_ADDREF(ctx,   share->mapDpiDictSet);
	KNH_ADDREF(ctx,   share->convDpiDictSet);
	KNH_ADDREF(ctx,   share->rconvDpiDictSet);
	KNH_ADDNNREF(ctx,   share->contextListNULL);

	KNH_ENSUREREF(ctx, K_TSTRING_SIZE);
	for(i = 0; i < K_TSTRING_SIZE; i++) {
		KNH_ADDREF(ctx, share->tString[i]);
	}
	KNH_ENSUREREF(ctx, share->sizeEventTBL);
	for(i = 0; i < share->sizeEventTBL; i++) {
		if(EventTBL(i).name != NULL) {
			KNH_ADDREF(ctx, EventTBL(i).name);
		}
	}
	/* tclass */
	KNH_ENSUREREF(ctx, share->sizeClassTBL * 11);
	for(i = 0; i < share->sizeClassTBL; i++) {
		const knh_ClassTBL_t *ct = ClassTBL(i);
		DBG_ASSERT(ct->lname != NULL);
		KNH_ADDNNREF(ctx,   ct->typeNULL);
		KNH_ADDREF(ctx,     ct->methods);
		KNH_ADDREF(ctx,     ct->typemaps);
		KNH_ADDNNREF(ctx,   ct->cparam);
		KNH_ADDNNREF(ctx,   ct->defnull);
		KNH_ADDNNREF(ctx,   ct->constDictCaseMapNULL);
		KNH_ADDREF(ctx,     ct->sname);
		KNH_ADDREF(ctx,     ct->lname);
		if(ct->bcid == CLASS_Object && ct->cid > ct->bcid) {
			KNH_ADDREF(ctx, ct->protoNULL);
		}
		KNH_ADDNNREF(ctx, ct->constPoolMapNULL);
	}

	/* CompilerAPI */
	KNH_ADDREF(ctx, share->konoha_compiler);
	return tail_;
}

static void share_free(CTX ctx, kshare_t *share)
{
	size_t i;
	/* CompilerAPI */
	share->compilerAPI = NULL;
	KNH_FREE(ctx, (void*)share->EventTBL, SIZEOF_TEXPT(ctx->share->capacityEventTBL));
	share->EventTBL = NULL;
	KNH_FREE(ctx, share->tString, SIZEOF_TSTRING);
	share->tString = NULL;
	for(i = 0; i < share->sizeClassTBL; i++) {
		knh_ClassTBL_t *ct = varClassTBL(i);
		if(ct->constPoolMapNULL) {
			knh_PtrMap_stat(ctx, ct->constPoolMapNULL, S_totext(ct->sname));
			ct->constPoolMapNULL = NULL;
		}
	}
	kmemshare_free(ctx);
	/* freeing cdef */
	for(i = 0; i < share->sizeClassTBL; i++) {
		knh_ClassTBL_t *ct = varClassTBL(i);
		const knh_ClassTBL_t *supTBL = ClassTBL(ct->supcid);
		if (ct->cdef != supTBL ->cdef && ct->cdef->asize > 0) {
			DBG_P("freeing ClassDef cid=%d %s", i, ct->cdef->name);
			KNH_FREE(ctx, (void*)ct->cdef, ct->cdef->asize);
		}
	}
	/* freeing ClassTBL->fields and ClassTBL */
	for(i = 0; i < share->sizeClassTBL; i++) {
		knh_ClassTBL_t *ct = varClassTBL(i);
		if(ct->fcapacity > 0) {
			KNH_FREE(ctx, ct->fields, sizeof(kfieldinfo_t) * ct->fcapacity);
			ct->fields = NULL;
		}
		KNH_FREE(ctx, ct, sizeof(knh_ClassTBL_t));
	}
	KNH_FREE(ctx, (void*)share->ClassTBL, sizeof(knh_ClassTBL_t*)*(share->capacityClassTBL));
	share->ClassTBL = NULL;

	if(ctx->stat->usedMemorySize != 0) {
		GC_LOG("memory leaking size=%ldbytes", (long)ctx->stat->usedMemorySize);
	}
	kmemlocal_free(ctx);
	knh_mutex_free(ctx, share->syslock);
	knh_bzero(share, sizeof(kshare_t) + sizeof(kstatinfo_t) + sizeof(knh_ServiceSPI_t));
	free(share);
}

/* ------------------------------------------------------------------------ */

kContext* knh_toContext(CTX ctx)
{
	if(ctx->ctxobjNC == NULL) {
		kContext *cx = new_H(Context);
		cx->ctx = (kcontext_t*)ctx;
		((kcontext_t*)ctx)->ctxobjNC = cx;
	}
	return ctx->ctxobjNC;
}

static kcontext_t* knh_getRootContext(CTX ctx)
{
	kcontext_t *ctx0 = (kcontext_t*)ctx;
	while(ctx0->parent != ctx0) {
		ctx0 = ctx0->parent;
	}
	return ctx0;
}

static kObject **knh_context_reftrace(CTX ctx, kcontext_t *o FTRARG)
{
	tail_ = CommonContext_reftrace(ctx, o FTRDATA);
	if(knh_getRootContext(ctx) == (CTX)o) {
		tail_ = share_reftrace(ctx, (kshare_t*)o->share FTRDATA);
	}
	KNH_SIZEREF(ctx);
	return tail_;
}

void knh_Context_free(CTX ctx, kcontext_t* ctxo)
{
	CommonContext_free(ctx, ctxo);
	if(knh_getRootContext(ctx) == (CTX)ctxo) {
		size_t i, j;
		for(i = 0; i < ctxo->share->sizeClassTBL; i++) {
			knh_ClassTBL_t *t = varClassTBL(i);
			kArray *a = t->methods;
			for(j = 0; j < knh_Array_size(a); j++) {
				kMethodoAbstract(ctx, a->methods[j]);
			}
		}
		share_free(ctx, (kshare_t*)ctxo->share);
		knh_bzero((void*)ctxo, sizeof(kcontext_t));
		free((void*)ctxo);
	}
	else {
		kmemlocal_free(ctx);
		knh_bzero((void*)ctxo, sizeof(kcontext_t));
		KNH_FREE(ctx, (void*)ctxo, sizeof(kcontext_t));
	}
}


/* ------------------------------------------------------------------------ */
/* [konoha api] */

/* ------------------------------------------------------------------------ */
/* [ctxkey] */

#ifdef K_USING_THREAD
#ifdef CC_TYPE_TLS
static CC_TYPE_TLS  kcontext_t *curctx = NULL;
#else
static kthread_key_t ctxkey;
static kcontext_t *curctx = NULL;
#endif
#else
static kcontext_t *curctx = NULL;
#endif

static void konoha_init(void)
{
	static int isInit = 0;
	if(isInit == 0) {
		isInit = 1;
		knh_opcode_check();
#if defined(K_USING_THREAD) && !defined(CC_TYPE_TLS)
		kthread_key_create((kthread_key_t*)&ctxkey);
#endif
		knh_srand(0);
	}
}

void knh_beginContext(CTX ctx, void **bottom)
{
	((kcontext_t*)ctx)->cstack_bottom = bottom;
#ifdef K_USING_THREAD
	knh_mutex_lock(ctx->ctxlock);
#if !defined(CC_TYPE_TLS)
	thread_setspecific(ctxkey, ctx);
#endif
	curctx = (kcontext_t*)ctx;
#else
	curctx = (kcontext_t*)ctx;
#endif
}

void knh_endContext(CTX ctx)
{
#ifdef K_USING_THREAD
#if !defined(CC_TYPE_TLS)
	thread_setspecific(ctxkey, NULL);
#endif
	knh_mutex_unlock(ctx->ctxlock);
	curctx = NULL;
#else
	curctx = NULL;
#endif
	((kcontext_t*)ctx)->cstack_bottom = NULL;
}

KNHAPI2(kcontext_t*) knh_getCurrentContext(void)
{
#if defined(K_USING_THREAD) && !defined(CC_TYPE_TLS)
	kcontext_t* ctx = (kcontext_t*)kthread_getspecific(ctxkey);
	if(ctx == NULL) {
		ctx = curctx;
	}
#else
	kcontext_t* ctx = curctx;
#endif
	if(ctx == NULL) {
		KNH_DIE("NOT IN KONOHA CTX");
	}
	return ctx;
}

konoha_t konoha_open(void)
{
	konoha_init();
	return (konoha_t)new_RootContext();
}

kObject **knh_reftraceRoot(CTX ctx FTRARG)
{
	int i, size = knh_Array_size(ctx->share->contextListNULL);
	for(i=0; i<size; i++) {
		kContext *ctx0 = (kContext *)knh_Array_n(ctx->share->contextListNULL, i);
		tail_ = knh_context_reftrace(ctx, (kcontext_t *)ctx0->ctx FTRDATA);
	}
	KNH_SIZEREF(ctx);
	return tail_;
}

static void check_allThreadExit(CTX ctx)
{
	int i;
	KNH_SYSLOCK(ctx);
	ctx->wshare->stopCounter++;
	if(ctx->share->gcStopCounter != 0) {
		kthread_cond_signal(ctx->share->start_cond);
	}
	if(ctx->share->threadCounter != 1) {
		kthread_cond_wait(ctx->share->close_cond, ctx->share->syslock);
	}
	for(i = knh_Array_size(ctx->share->contextListNULL) - 1; i >= 0; i--) {
		kContext *c = (kContext *)knh_Array_n(ctx->share->contextListNULL, i);
		if(c->ctx != ctx) {
			knh_Context_free(ctx, WCTX(c->ctx));
			knh_Array_remove(ctx, ctx->share->contextListNULL, i);
		}
	}
	KNH_SYSUNLOCK(ctx);
}

void konoha_close(konoha_t konoha)
{
	CTX ctx = (kcontext_t*)konoha;
	check_allThreadExit(ctx);
	if(ctx->share->threadCounter > 1) {
		KNH_NTRACE2(ctx, "konoha:close", K_FAILED,
				KNH_LDATA(LOG_msg("stil threads running"),
					LOG_i("threads", ctx->share->threadCounter)));
		return;
	}
#ifdef K_USING_RCGC
	knh_context_reftrace(ctx, (kcontext_t*)ctx, FTRDATA);
#endif
	knh_flush(ctx, KNH_STDOUT); // flush before ending
	{
		KNH_NTRACE2(ctx, "stat:konoha:gc", K_NOTICE,
				KNH_LDATA(LOG_u("gc_count", ctx->stat->gcCount),
				LOG_u("marking_time:ms", ctx->stat->markingTime),
				LOG_u("sweeping_time:ms", ctx->stat->sweepingTime),
				LOG_u("gc_time:ms", ctx->stat->gcTime)));
	}
	((kcontext_t*)ctx)->bufa = NULL; // necessary for KNH_SYSLOG
	knh_Context_free(ctx, (kcontext_t*)ctx);
}

/* ------------------------------------------------------------------------ */

#ifdef __cplusplus
}
#endif
