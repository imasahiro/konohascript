//QEventLoop QEventLoop.new(QObject parent);
KMETHOD QEventLoop_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQEventLoop *ret_v = new KQEventLoop(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QEventLoop.exec(int flags);
KMETHOD QEventLoop_exec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEventLoop *  qp = RawPtr_to(QEventLoop *, sfp[0]);
	if (qp != NULL) {
		QEventLoop::ProcessEventsFlags flags = Int_to(QEventLoop::ProcessEventsFlags, sfp[1]);
		int ret_v = qp->exec(flags);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QEventLoop.exit(int returnCode);
KMETHOD QEventLoop_exit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEventLoop *  qp = RawPtr_to(QEventLoop *, sfp[0]);
	if (qp != NULL) {
		int returnCode = Int_to(int, sfp[1]);
		qp->exit(returnCode);
	}
	RETURNvoid_();
}

//boolean QEventLoop.isRunning();
KMETHOD QEventLoop_isRunning(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEventLoop *  qp = RawPtr_to(QEventLoop *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isRunning();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QEventLoop.processEvents(int flags);
KMETHOD QEventLoop_processEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEventLoop *  qp = RawPtr_to(QEventLoop *, sfp[0]);
	if (qp != NULL) {
		QEventLoop::ProcessEventsFlags flags = Int_to(QEventLoop::ProcessEventsFlags, sfp[1]);
		bool ret_v = qp->processEvents(flags);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//void QEventLoop.processEvents(int flags, int maxTime);
KMETHOD QEventLoop_processEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEventLoop *  qp = RawPtr_to(QEventLoop *, sfp[0]);
	if (qp != NULL) {
		QEventLoop::ProcessEventsFlags flags = Int_to(QEventLoop::ProcessEventsFlags, sfp[1]);
		int maxTime = Int_to(int, sfp[2]);
		qp->processEvents(flags, maxTime);
	}
	RETURNvoid_();
}
*/
//void QEventLoop.wakeUp();
KMETHOD QEventLoop_wakeUp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEventLoop *  qp = RawPtr_to(QEventLoop *, sfp[0]);
	if (qp != NULL) {
		qp->wakeUp();
	}
	RETURNvoid_();
}

//void QEventLoop.quit();
KMETHOD QEventLoop_quit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEventLoop *  qp = RawPtr_to(QEventLoop *, sfp[0]);
	if (qp != NULL) {
		qp->quit();
	}
	RETURNvoid_();
}


DummyQEventLoop::DummyQEventLoop()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQEventLoop::setSelf(knh_RawPtr_t *ptr)
{
	DummyQEventLoop::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQEventLoop::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQEventLoop::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQEventLoop::event_map->bigin();
	if ((itr = DummyQEventLoop::event_map->find(str)) == DummyQEventLoop::event_map->end()) {
		bool ret;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQEventLoop::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQEventLoop::slot_map->bigin();
	if ((itr = DummyQEventLoop::event_map->find(str)) == DummyQEventLoop::slot_map->end()) {
		bool ret;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQEventLoop::KQEventLoop(QObject* parent) : QEventLoop(parent)
{
	self = NULL;
}

KMETHOD QEventLoop_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQEventLoop *qp = RawPtr_to(KQEventLoop *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QEventLoop]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQEventLoop::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QEventLoop]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QEventLoop_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQEventLoop *qp = RawPtr_to(KQEventLoop *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QEventLoop]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQEventLoop::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QEventLoop]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QEventLoop_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQEventLoop *qp = (KQEventLoop *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QEventLoop_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQEventLoop *qp = (KQEventLoop *)p->rawptr;
		(void)qp;
	}
}

static int QEventLoop_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQEventLoop::event(QEvent *event)
{
	if (!DummyQEventLoop::eventDispatcher(event)) {
		QEventLoop::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQEventLoop(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QEventLoop";
	cdef->free = QEventLoop_free;
	cdef->reftrace = QEventLoop_reftrace;
	cdef->compareTo = QEventLoop_compareTo;
}

static knh_IntData_t QEventLoopConstInt[] = {
	{"AllEvents", QEventLoop::AllEvents},
	{"ExcludeUserInputEvents", QEventLoop::ExcludeUserInputEvents},
	{"ExcludeSocketNotifiers", QEventLoop::ExcludeSocketNotifiers},
	{"WaitForMoreEvents", QEventLoop::WaitForMoreEvents},
	{"DeferredDeletion", QEventLoop::DeferredDeletion},
	{NULL, 0}
};

DEFAPI(void) constQEventLoop(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QEventLoopConstInt);
}

