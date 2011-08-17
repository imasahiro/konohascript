#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

KTimer::KTimer(int interval_, knh_Func_t *fo_)
{
	interval = interval_;
	fo = fo_;
}

int KTimer::start(void)
{
	timer_id = startTimer(interval);
	return timer_id;
}

void KTimer::timerEvent(QTimerEvent *event)
{
	CTX lctx = knh_getCurrentContext();
	knh_sfp_t *lsfp = lctx->esp;
	knh_RawPtr_t *p = new_RawPtrFromClass(TimerEvent, event);
	KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(p));
	knh_Func_invoke(lctx, fo, lsfp, 1/*argc*/);
}

KMETHOD Timer_new(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	int interval = Int_to(int, sfp[1]);
	KTimer *t = new KTimer(interval, sfp[2].fo);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, t, NULL);
	RETURN_(p);
}

KMETHOD Timer_start(Ctx *ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	KTimer *t = RawPtr_to(KTimer *, sfp[0]);
	int timer_id = t->start();
	RETURNi_(timer_id);
}

static void Timer_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL && O_cTBL(p)->total < 4) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Timer:free\n");
#endif
		KTimer *t = (KTimer *)p->rawptr;
		//fprintf(stderr, "fo->mtd->fcall_1 = [%p]\n", t->fo->mtd->fcall_1);
		(void)t;
		//delete t;
	}
}

static void Timer_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx;
	(void)p;
	(void)tail_;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "Timer:reftrace\n");
#endif
		KTimer *t = (KTimer *)p->rawptr;
		KNH_ADDREF(ctx, t->fo);
	}
}

DEFAPI(void) defTimer(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "Timer";
	cdef->free = Timer_free;
	cdef->reftrace = Timer_reftrace;
}

DEFAPI(void) constTimer(CTX ctx, knh_class_t cid, const knh_PackageLoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

static void TimerEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL && O_cTBL(p)->total < 4) {
		fprintf(stderr, "TimerEvent:free\n");
		QTimerEvent *t = (QTimerEvent *)p->rawptr;
		(void)t;
		//delete t;
	}
}

static void TimerEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx;
	(void)p;
	(void)tail_;
	fprintf(stderr, "TimerEvent:reftrace\n");
	//QApplication *app = (QApplication *)p->rawptr;
}

DEFAPI(void) defTimerEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "TimerEvent";
	cdef->free = TimerEvent_free;
	cdef->reftrace = TimerEvent_reftrace;
}

DEFAPI(void) constTimerEvent(CTX ctx, knh_class_t cid, const knh_PackageLoaderAPI_t *kapi)
{
	(void)ctx;
	(void)cid;
	(void)kapi;
	//kapi->loadIntClassConst(ctx, cid, TimeLineConstInt);
}

#ifdef __cplusplus
}
#endif
