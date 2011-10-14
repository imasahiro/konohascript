//QThreadPool QThreadPool.new(QObject parent);
KMETHOD QThreadPool_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQThreadPool *ret_v = new KQThreadPool(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QThreadPool.activeThreadCount();
KMETHOD QThreadPool_activeThreadCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThreadPool *  qp = RawPtr_to(QThreadPool *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->activeThreadCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QThreadPool.getExpiryTimeout();
KMETHOD QThreadPool_getExpiryTimeout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThreadPool *  qp = RawPtr_to(QThreadPool *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->expiryTimeout();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QThreadPool.getMaxThreadCount();
KMETHOD QThreadPool_getMaxThreadCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThreadPool *  qp = RawPtr_to(QThreadPool *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->maxThreadCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QThreadPool.releaseThread();
KMETHOD QThreadPool_releaseThread(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThreadPool *  qp = RawPtr_to(QThreadPool *, sfp[0]);
	if (qp != NULL) {
		qp->releaseThread();
	}
	RETURNvoid_();
}

//void QThreadPool.reserveThread();
KMETHOD QThreadPool_reserveThread(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThreadPool *  qp = RawPtr_to(QThreadPool *, sfp[0]);
	if (qp != NULL) {
		qp->reserveThread();
	}
	RETURNvoid_();
}

//void QThreadPool.setExpiryTimeout(int expiryTimeout);
KMETHOD QThreadPool_setExpiryTimeout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThreadPool *  qp = RawPtr_to(QThreadPool *, sfp[0]);
	if (qp != NULL) {
		int expiryTimeout = Int_to(int, sfp[1]);
		qp->setExpiryTimeout(expiryTimeout);
	}
	RETURNvoid_();
}

//void QThreadPool.setMaxThreadCount(int maxThreadCount);
KMETHOD QThreadPool_setMaxThreadCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThreadPool *  qp = RawPtr_to(QThreadPool *, sfp[0]);
	if (qp != NULL) {
		int maxThreadCount = Int_to(int, sfp[1]);
		qp->setMaxThreadCount(maxThreadCount);
	}
	RETURNvoid_();
}

//void QThreadPool.start(QRunnable runnable, int priority);
KMETHOD QThreadPool_start(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThreadPool *  qp = RawPtr_to(QThreadPool *, sfp[0]);
	if (qp != NULL) {
		QRunnable*  runnable = RawPtr_to(QRunnable*, sfp[1]);
		int priority = Int_to(int, sfp[2]);
		qp->start(runnable, priority);
	}
	RETURNvoid_();
}

//boolean QThreadPool.tryStart(QRunnable runnable);
KMETHOD QThreadPool_tryStart(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThreadPool *  qp = RawPtr_to(QThreadPool *, sfp[0]);
	if (qp != NULL) {
		QRunnable*  runnable = RawPtr_to(QRunnable*, sfp[1]);
		bool ret_v = qp->tryStart(runnable);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QThreadPool.waitForDone();
KMETHOD QThreadPool_waitForDone(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThreadPool *  qp = RawPtr_to(QThreadPool *, sfp[0]);
	if (qp != NULL) {
		qp->waitForDone();
	}
	RETURNvoid_();
}

//QThreadPool QThreadPool.globalInstance();
KMETHOD QThreadPool_globalInstance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThreadPool *  qp = RawPtr_to(QThreadPool *, sfp[0]);
	if (qp != NULL) {
		QThreadPool* ret_v = qp->globalInstance();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QThreadPool*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQThreadPool::DummyQThreadPool()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQThreadPool::setSelf(knh_RawPtr_t *ptr)
{
	DummyQThreadPool::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQThreadPool::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQThreadPool::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQThreadPool::event_map->bigin();
	if ((itr = DummyQThreadPool::event_map->find(str)) == DummyQThreadPool::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQThreadPool::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQThreadPool::slot_map->bigin();
	if ((itr = DummyQThreadPool::slot_map->find(str)) == DummyQThreadPool::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQThreadPool::connection(QObject *o)
{
	DummyQObject::connection(o);
}

KQThreadPool::KQThreadPool(QObject* parent) : QThreadPool(parent)
{
	self = NULL;
	dummy = new DummyQThreadPool();
	dummy->connection((QObject*)this);
}

KMETHOD QThreadPool_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQThreadPool *qp = RawPtr_to(KQThreadPool *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QThreadPool]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QThreadPool]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QThreadPool_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQThreadPool *qp = RawPtr_to(KQThreadPool *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QThreadPool]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QThreadPool]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QThreadPool_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQThreadPool *qp = (KQThreadPool *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QThreadPool_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQThreadPool *qp = (KQThreadPool *)p->rawptr;
		(void)qp;
	}
}

static int QThreadPool_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQThreadPool::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQThreadPool::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QThreadPool::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQThreadPool(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QThreadPool";
	cdef->free = QThreadPool_free;
	cdef->reftrace = QThreadPool_reftrace;
	cdef->compareTo = QThreadPool_compareTo;
}


