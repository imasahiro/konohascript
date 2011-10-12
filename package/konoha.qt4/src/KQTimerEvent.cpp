//QTimerEvent QTimerEvent.new(int timerId);
KMETHOD QTimerEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int timerId = Int_to(int, sfp[1]);
	KQTimerEvent *ret_v = new KQTimerEvent(timerId);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QTimerEvent.timerId();
KMETHOD QTimerEvent_timerId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTimerEvent *  qp = RawPtr_to(QTimerEvent *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->timerId();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQTimerEvent::DummyQTimerEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTimerEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTimerEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQTimerEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTimerEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTimerEvent::event_map->bigin();
	if ((itr = DummyQTimerEvent::event_map->find(str)) == DummyQTimerEvent::event_map->end()) {
		bool ret;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTimerEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTimerEvent::slot_map->bigin();
	if ((itr = DummyQTimerEvent::event_map->find(str)) == DummyQTimerEvent::slot_map->end()) {
		bool ret;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTimerEvent::KQTimerEvent(int timerId) : QTimerEvent(timerId)
{
	self = NULL;
}

KMETHOD QTimerEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTimerEvent *qp = RawPtr_to(KQTimerEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTimerEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQTimerEvent::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTimerEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QTimerEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTimerEvent *qp = RawPtr_to(KQTimerEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTimerEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQTimerEvent::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTimerEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTimerEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTimerEvent *qp = (KQTimerEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTimerEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTimerEvent *qp = (KQTimerEvent *)p->rawptr;
		(void)qp;
	}
}

static int QTimerEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQTimerEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTimerEvent";
	cdef->free = QTimerEvent_free;
	cdef->reftrace = QTimerEvent_reftrace;
	cdef->compareTo = QTimerEvent_compareTo;
}


