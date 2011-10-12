//QTimer QTimer.new(QObject parent);
KMETHOD QTimer_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQTimer *ret_v = new KQTimer(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QTimer.getInterval();
KMETHOD QTimer_getInterval(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimer *  qp = RawPtr_to(QTimer *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->interval();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QTimer.isActive();
KMETHOD QTimer_isActive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimer *  qp = RawPtr_to(QTimer *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isActive();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTimer.isSingleShot();
KMETHOD QTimer_isSingleShot(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimer *  qp = RawPtr_to(QTimer *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isSingleShot();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTimer.setInterval(int msec);
KMETHOD QTimer_setInterval(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimer *  qp = RawPtr_to(QTimer *, sfp[0]);
	if (qp != NULL) {
		int msec = Int_to(int, sfp[1]);
		qp->setInterval(msec);
	}
	RETURNvoid_();
}

//void QTimer.setSingleShot(boolean singleShot);
KMETHOD QTimer_setSingleShot(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimer *  qp = RawPtr_to(QTimer *, sfp[0]);
	if (qp != NULL) {
		bool singleShot = Boolean_to(bool, sfp[1]);
		qp->setSingleShot(singleShot);
	}
	RETURNvoid_();
}

//int QTimer.timerId();
KMETHOD QTimer_timerId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimer *  qp = RawPtr_to(QTimer *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->timerId();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTimer.getSingleShot(int msec, QObject receiver, String member);
KMETHOD QTimer_getSingleShot(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimer *  qp = RawPtr_to(QTimer *, sfp[0]);
	if (qp != NULL) {
		int msec = Int_to(int, sfp[1]);
		QObject*  receiver = RawPtr_to(QObject*, sfp[2]);
		const char*  member = RawPtr_to(const char*, sfp[3]);
		qp->singleShot(msec, receiver, member);
	}
	RETURNvoid_();
}

//void QTimer.start(int msec);
KMETHOD QTimer_start(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimer *  qp = RawPtr_to(QTimer *, sfp[0]);
	if (qp != NULL) {
		int msec = Int_to(int, sfp[1]);
		qp->start(msec);
	}
	RETURNvoid_();
}

/*
//void QTimer.start();
KMETHOD QTimer_start(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimer *  qp = RawPtr_to(QTimer *, sfp[0]);
	if (qp != NULL) {
		qp->start();
	}
	RETURNvoid_();
}
*/
//void QTimer.stop();
KMETHOD QTimer_stop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimer *  qp = RawPtr_to(QTimer *, sfp[0]);
	if (qp != NULL) {
		qp->stop();
	}
	RETURNvoid_();
}


DummyQTimer::DummyQTimer()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTimer::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTimer::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQTimer::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTimer::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTimer::event_map->bigin();
	if ((itr = DummyQTimer::event_map->find(str)) == DummyQTimer::event_map->end()) {
		bool ret;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTimer::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTimer::slot_map->bigin();
	if ((itr = DummyQTimer::event_map->find(str)) == DummyQTimer::slot_map->end()) {
		bool ret;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTimer::KQTimer(QObject* parent) : QTimer(parent)
{
	self = NULL;
}

KMETHOD QTimer_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTimer *qp = RawPtr_to(KQTimer *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTimer]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQTimer::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTimer]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QTimer_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTimer *qp = RawPtr_to(KQTimer *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTimer]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQTimer::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTimer]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTimer_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTimer *qp = (KQTimer *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTimer_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTimer *qp = (KQTimer *)p->rawptr;
		(void)qp;
	}
}

static int QTimer_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQTimer::event(QEvent *event)
{
	if (!DummyQTimer::eventDispatcher(event)) {
		QTimer::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQTimer(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTimer";
	cdef->free = QTimer_free;
	cdef->reftrace = QTimer_reftrace;
	cdef->compareTo = QTimer_compareTo;
}


