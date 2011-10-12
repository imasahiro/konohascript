//QBasicTimer QBasicTimer.new();
KMETHOD QBasicTimer_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQBasicTimer *ret_v = new KQBasicTimer();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QBasicTimer.isActive();
KMETHOD QBasicTimer_isActive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBasicTimer *  qp = RawPtr_to(QBasicTimer *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isActive();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QBasicTimer.start(int msec, QObject object);
KMETHOD QBasicTimer_start(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBasicTimer *  qp = RawPtr_to(QBasicTimer *, sfp[0]);
	if (qp != NULL) {
		int msec = Int_to(int, sfp[1]);
		QObject*  object = RawPtr_to(QObject*, sfp[2]);
		qp->start(msec, object);
	}
	RETURNvoid_();
}

//void QBasicTimer.stop();
KMETHOD QBasicTimer_stop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBasicTimer *  qp = RawPtr_to(QBasicTimer *, sfp[0]);
	if (qp != NULL) {
		qp->stop();
	}
	RETURNvoid_();
}

//int QBasicTimer.timerId();
KMETHOD QBasicTimer_timerId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBasicTimer *  qp = RawPtr_to(QBasicTimer *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->timerId();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQBasicTimer::DummyQBasicTimer()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQBasicTimer::setSelf(knh_RawPtr_t *ptr)
{
	DummyQBasicTimer::self = ptr;
}

bool DummyQBasicTimer::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQBasicTimer::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQBasicTimer::event_map->bigin();
	if ((itr = DummyQBasicTimer::event_map->find(str)) == DummyQBasicTimer::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQBasicTimer::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQBasicTimer::slot_map->bigin();
	if ((itr = DummyQBasicTimer::event_map->find(str)) == DummyQBasicTimer::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQBasicTimer::KQBasicTimer() : QBasicTimer()
{
	self = NULL;
}

KMETHOD QBasicTimer_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQBasicTimer *qp = RawPtr_to(KQBasicTimer *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QBasicTimer]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQBasicTimer::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QBasicTimer]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QBasicTimer_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQBasicTimer *qp = RawPtr_to(KQBasicTimer *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QBasicTimer]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQBasicTimer::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QBasicTimer]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QBasicTimer_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQBasicTimer *qp = (KQBasicTimer *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QBasicTimer_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQBasicTimer *qp = (KQBasicTimer *)p->rawptr;
		(void)qp;
	}
}

static int QBasicTimer_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQBasicTimer(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QBasicTimer";
	cdef->free = QBasicTimer_free;
	cdef->reftrace = QBasicTimer_reftrace;
	cdef->compareTo = QBasicTimer_compareTo;
}


