//
//boolean QAbstractEventDispatcher.filterEvent(void message);
KMETHOD QAbstractEventDispatcher_filterEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractEventDispatcher *  qp = RawPtr_to(QAbstractEventDispatcher *, sfp[0]);
	if (qp) {
		void*  message = RawPtr_to(void*, sfp[1]);
		bool ret_v = qp->filterEvent(message);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual void QAbstractEventDispatcher.flush();
KMETHOD QAbstractEventDispatcher_flush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractEventDispatcher *  qp = RawPtr_to(QAbstractEventDispatcher *, sfp[0]);
	if (qp) {
		qp->flush();
	}
	RETURNvoid_();
}

//@Virtual boolean QAbstractEventDispatcher.hasPendingEvents();
KMETHOD QAbstractEventDispatcher_hasPendingEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractEventDispatcher *  qp = RawPtr_to(QAbstractEventDispatcher *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasPendingEvents();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual void QAbstractEventDispatcher.interrupt();
KMETHOD QAbstractEventDispatcher_interrupt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractEventDispatcher *  qp = RawPtr_to(QAbstractEventDispatcher *, sfp[0]);
	if (qp) {
		qp->interrupt();
	}
	RETURNvoid_();
}

//@Virtual boolean QAbstractEventDispatcher.processEvents(int flags);
KMETHOD QAbstractEventDispatcher_processEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractEventDispatcher *  qp = RawPtr_to(QAbstractEventDispatcher *, sfp[0]);
	if (qp) {
		QEventLoop::ProcessEventsFlags flags = Int_to(QEventLoop::ProcessEventsFlags, sfp[1]);
		bool ret_v = qp->processEvents(flags);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual void QAbstractEventDispatcher.registerSocketNotifier(QSocketNotifier notifier);
KMETHOD QAbstractEventDispatcher_registerSocketNotifier(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractEventDispatcher *  qp = RawPtr_to(QAbstractEventDispatcher *, sfp[0]);
	if (qp) {
		QSocketNotifier*  notifier = RawPtr_to(QSocketNotifier*, sfp[1]);
		qp->registerSocketNotifier(notifier);
	}
	RETURNvoid_();
}

//int QAbstractEventDispatcher.registerTimer(int interval, QObject object);
KMETHOD QAbstractEventDispatcher_registerTimer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractEventDispatcher *  qp = RawPtr_to(QAbstractEventDispatcher *, sfp[0]);
	if (qp) {
		int interval = Int_to(int, sfp[1]);
		QObject*  object = RawPtr_to(QObject*, sfp[2]);
		int ret_v = qp->registerTimer(interval, object);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//@Virtual void QAbstractEventDispatcher.registerTimer(int timerId, int interval, QObject object);
KMETHOD QAbstractEventDispatcher_registerTimer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractEventDispatcher *  qp = RawPtr_to(QAbstractEventDispatcher *, sfp[0]);
	if (qp) {
		int timerId = Int_to(int, sfp[1]);
		int interval = Int_to(int, sfp[2]);
		QObject*  object = RawPtr_to(QObject*, sfp[3]);
		qp->registerTimer(timerId, interval, object);
	}
	RETURNvoid_();
}
*/
//@Virtual void QAbstractEventDispatcher.unregisterSocketNotifier(QSocketNotifier notifier);
KMETHOD QAbstractEventDispatcher_unregisterSocketNotifier(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractEventDispatcher *  qp = RawPtr_to(QAbstractEventDispatcher *, sfp[0]);
	if (qp) {
		QSocketNotifier*  notifier = RawPtr_to(QSocketNotifier*, sfp[1]);
		qp->unregisterSocketNotifier(notifier);
	}
	RETURNvoid_();
}

//@Virtual boolean QAbstractEventDispatcher.unregisterTimer(int timerId);
KMETHOD QAbstractEventDispatcher_unregisterTimer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractEventDispatcher *  qp = RawPtr_to(QAbstractEventDispatcher *, sfp[0]);
	if (qp) {
		int timerId = Int_to(int, sfp[1]);
		bool ret_v = qp->unregisterTimer(timerId);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QAbstractEventDispatcher.unregisterTimers(QObject object);
KMETHOD QAbstractEventDispatcher_unregisterTimers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractEventDispatcher *  qp = RawPtr_to(QAbstractEventDispatcher *, sfp[0]);
	if (qp) {
		QObject*  object = RawPtr_to(QObject*, sfp[1]);
		bool ret_v = qp->unregisterTimers(object);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual void QAbstractEventDispatcher.wakeUp();
KMETHOD QAbstractEventDispatcher_wakeUp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractEventDispatcher *  qp = RawPtr_to(QAbstractEventDispatcher *, sfp[0]);
	if (qp) {
		qp->wakeUp();
	}
	RETURNvoid_();
}

//QAbstractEventDispatcher QAbstractEventDispatcher.instance(QThread thread);
KMETHOD QAbstractEventDispatcher_instance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QThread*  thread = RawPtr_to(QThread*, sfp[1]);
		QAbstractEventDispatcher* ret_v = QAbstractEventDispatcher::instance(thread);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractEventDispatcher*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQAbstractEventDispatcher::DummyQAbstractEventDispatcher()
{
	self = NULL;
	about_to_block_func = NULL;
	awake_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("about-to-block", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("awake", NULL));
}

void DummyQAbstractEventDispatcher::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractEventDispatcher::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQAbstractEventDispatcher::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractEventDispatcher::aboutToBlockSlot()
{
	if (about_to_block_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, about_to_block_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAbstractEventDispatcher::awakeSlot()
{
	if (awake_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, awake_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAbstractEventDispatcher::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractEventDispatcher::event_map->bigin();
	if ((itr = DummyQAbstractEventDispatcher::event_map->find(str)) == DummyQAbstractEventDispatcher::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractEventDispatcher::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractEventDispatcher::slot_map->bigin();
	if ((itr = DummyQAbstractEventDispatcher::slot_map->find(str)) == DummyQAbstractEventDispatcher::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		about_to_block_func = (*slot_map)["about-to-block"];
		awake_func = (*slot_map)["awake"];
		return true;
	}
}

void DummyQAbstractEventDispatcher::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, about_to_block_func);
	KNH_ADDNNREF(ctx, awake_func);

	KNH_SIZEREF(ctx);

	DummyQObject::reftrace(ctx, p, tail_);
}

void DummyQAbstractEventDispatcher::connection(QObject *o)
{
	QAbstractEventDispatcher *p = dynamic_cast<QAbstractEventDispatcher*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(aboutToBlock()), this, SLOT(aboutToBlockSlot()));
		connect(p, SIGNAL(awake()), this, SLOT(awakeSlot()));
	}
	DummyQObject::connection(o);
}

KQAbstractEventDispatcher::KQAbstractEventDispatcher(QObject* parent) : QAbstractEventDispatcher(parent)
{
	self = NULL;
	dummy = new DummyQAbstractEventDispatcher();
	dummy->connection((QObject*)this);
}

KMETHOD QAbstractEventDispatcher_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractEventDispatcher *qp = RawPtr_to(KQAbstractEventDispatcher *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractEventDispatcher]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractEventDispatcher]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAbstractEventDispatcher_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractEventDispatcher *qp = RawPtr_to(KQAbstractEventDispatcher *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractEventDispatcher]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractEventDispatcher]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractEventDispatcher_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAbstractEventDispatcher *qp = (KQAbstractEventDispatcher *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAbstractEventDispatcher_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQAbstractEventDispatcher *qp = (KQAbstractEventDispatcher *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAbstractEventDispatcher_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAbstractEventDispatcher::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQAbstractEventDispatcher::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QAbstractEventDispatcher::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQAbstractEventDispatcher(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractEventDispatcher";
	cdef->free = QAbstractEventDispatcher_free;
	cdef->reftrace = QAbstractEventDispatcher_reftrace;
	cdef->compareTo = QAbstractEventDispatcher_compareTo;
}


