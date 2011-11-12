//QEventLoop QEventLoop.new(QObject parent);
KMETHOD QEventLoop_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQEventLoop *ret_v = new KQEventLoop(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QEventLoop.exec(QEventLoopProcessEventsFlags flags);
KMETHOD QEventLoop_exec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEventLoop *  qp = RawPtr_to(QEventLoop *, sfp[0]);
	if (qp) {
		initFlag(flags, QEventLoop::ProcessEventsFlags, sfp[1]);
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
	if (qp) {
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
	if (qp) {
		bool ret_v = qp->isRunning();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QEventLoop.processEvents(QEventLoopProcessEventsFlags flags);
KMETHOD QEventLoop_processEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEventLoop *  qp = RawPtr_to(QEventLoop *, sfp[0]);
	if (qp) {
		initFlag(flags, QEventLoop::ProcessEventsFlags, sfp[1]);
		bool ret_v = qp->processEvents(flags);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//void QEventLoop.processEvents(QEventLoopProcessEventsFlags flags, int maxTime);
KMETHOD QEventLoop_processEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEventLoop *  qp = RawPtr_to(QEventLoop *, sfp[0]);
	if (qp) {
		initFlag(flags, QEventLoop::ProcessEventsFlags, sfp[1]);
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
	if (qp) {
		qp->wakeUp();
	}
	RETURNvoid_();
}

//void QEventLoop.quit();
KMETHOD QEventLoop_quit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEventLoop *  qp = RawPtr_to(QEventLoop *, sfp[0]);
	if (qp) {
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
		bool ret = false;
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
	if ((itr = DummyQEventLoop::slot_map->find(str)) == DummyQEventLoop::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQEventLoop::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQEventLoop::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQEventLoop::connection(QObject *o)
{
	QEventLoop *p = dynamic_cast<QEventLoop*>(o);
	if (p != NULL) {
	}
	DummyQObject::connection(o);
}

KQEventLoop::KQEventLoop(QObject* parent) : QEventLoop(parent)
{
	self = NULL;
	dummy = new DummyQEventLoop();
	dummy->connection((QObject*)this);
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
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
	if (p->rawptr != NULL) {
		KQEventLoop *qp = (KQEventLoop *)p->rawptr;
//		KQEventLoop *qp = static_cast<KQEventLoop*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QEventLoop_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQEventLoop::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQEventLoop::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QEventLoop::event(event);
		return false;
	}
//	QEventLoop::event(event);
	return true;
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


DEFAPI(void) defQEventLoop(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QEventLoop";
	cdef->free = QEventLoop_free;
	cdef->reftrace = QEventLoop_reftrace;
	cdef->compareTo = QEventLoop_compareTo;
}

//## QEventLoopProcessEventsFlags QEventLoopProcessEventsFlags.new(int value);
KMETHOD QEventLoopProcessEventsFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QEventLoop::ProcessEventsFlag i = Int_to(QEventLoop::ProcessEventsFlag, sfp[1]);
	QEventLoop::ProcessEventsFlags *ret_v = new QEventLoop::ProcessEventsFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QEventLoopProcessEventsFlags QEventLoopProcessEventsFlags.and(int mask);
KMETHOD QEventLoopProcessEventsFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QEventLoop::ProcessEventsFlags *qp = RawPtr_to(QEventLoop::ProcessEventsFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QEventLoop::ProcessEventsFlags ret = ((*qp) & i);
		QEventLoop::ProcessEventsFlags *ret_ = new QEventLoop::ProcessEventsFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QEventLoopProcessEventsFlags QEventLoopProcessEventsFlags.iand(QEventLoop::QEventLoopProcessEventsFlags other);
KMETHOD QEventLoopProcessEventsFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QEventLoop::ProcessEventsFlags *qp = RawPtr_to(QEventLoop::ProcessEventsFlags*, sfp[0]);
	if (qp != NULL) {
		QEventLoop::ProcessEventsFlags *other = RawPtr_to(QEventLoop::ProcessEventsFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QEventLoopProcessEventsFlags QEventLoopProcessEventsFlags.or(QEventLoopProcessEventsFlags f);
KMETHOD QEventLoopProcessEventsFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEventLoop::ProcessEventsFlags *qp = RawPtr_to(QEventLoop::ProcessEventsFlags*, sfp[0]);
	if (qp != NULL) {
		QEventLoop::ProcessEventsFlags *f = RawPtr_to(QEventLoop::ProcessEventsFlags*, sfp[1]);
		QEventLoop::ProcessEventsFlags ret = ((*qp) | (*f));
		QEventLoop::ProcessEventsFlags *ret_ = new QEventLoop::ProcessEventsFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QEventLoopProcessEventsFlags QEventLoopProcessEventsFlags.ior(QEventLoop::QEventLoopProcessEventsFlags other);
KMETHOD QEventLoopProcessEventsFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QEventLoop::ProcessEventsFlags *qp = RawPtr_to(QEventLoop::ProcessEventsFlags*, sfp[0]);
	if (qp != NULL) {
		QEventLoop::ProcessEventsFlags *other = RawPtr_to(QEventLoop::ProcessEventsFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QEventLoopProcessEventsFlags QEventLoopProcessEventsFlags.xor(QEventLoopProcessEventsFlags f);
KMETHOD QEventLoopProcessEventsFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEventLoop::ProcessEventsFlags *qp = RawPtr_to(QEventLoop::ProcessEventsFlags*, sfp[0]);
	if (qp != NULL) {
		QEventLoop::ProcessEventsFlags *f = RawPtr_to(QEventLoop::ProcessEventsFlags*, sfp[1]);
		QEventLoop::ProcessEventsFlags ret = ((*qp) ^ (*f));
		QEventLoop::ProcessEventsFlags *ret_ = new QEventLoop::ProcessEventsFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QEventLoopProcessEventsFlags QEventLoopProcessEventsFlags.ixor(QEventLoop::QEventLoopProcessEventsFlags other);
KMETHOD QEventLoopProcessEventsFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QEventLoop::ProcessEventsFlags *qp = RawPtr_to(QEventLoop::ProcessEventsFlags*, sfp[0]);
	if (qp != NULL) {
		QEventLoop::ProcessEventsFlags *other = RawPtr_to(QEventLoop::ProcessEventsFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QEventLoopProcessEventsFlags.testFlag(int flag);
KMETHOD QEventLoopProcessEventsFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QEventLoop::ProcessEventsFlags *qp = RawPtr_to(QEventLoop::ProcessEventsFlags *, sfp[0]);
	if (qp != NULL) {
		QEventLoop::ProcessEventsFlag flag = Int_to(QEventLoop::ProcessEventsFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QEventLoopProcessEventsFlags.value();
KMETHOD QEventLoopProcessEventsFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QEventLoop::ProcessEventsFlags *qp = RawPtr_to(QEventLoop::ProcessEventsFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QEventLoopProcessEventsFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QEventLoop::ProcessEventsFlags *qp = (QEventLoop::ProcessEventsFlags *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QEventLoopProcessEventsFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QEventLoop::ProcessEventsFlags *qp = (QEventLoop::ProcessEventsFlags *)p->rawptr;
		(void)qp;
	}
}

static int QEventLoopProcessEventsFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QEventLoop::ProcessEventsFlags*)p1->rawptr);
//		int v2 = int(*(QEventLoop::ProcessEventsFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QEventLoop::ProcessEventsFlags v1 = *(QEventLoop::ProcessEventsFlags*)p1->rawptr;
		QEventLoop::ProcessEventsFlags v2 = *(QEventLoop::ProcessEventsFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQEventLoopProcessEventsFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QEventLoopProcessEventsFlags";
	cdef->free = QEventLoopProcessEventsFlags_free;
	cdef->reftrace = QEventLoopProcessEventsFlags_reftrace;
	cdef->compareTo = QEventLoopProcessEventsFlags_compareTo;
}

