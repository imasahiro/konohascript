//QFocusEvent QFocusEvent.new(int type, int reason);
KMETHOD QFocusEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFocusEvent::Type type = Int_to(QFocusEvent::Type, sfp[1]);
	Qt::FocusReason reason = Int_to(Qt::FocusReason, sfp[2]);
	KQFocusEvent *ret_v = new KQFocusEvent(type, reason);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QFocusEvent.gotFocus();
KMETHOD QFocusEvent_gotFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFocusEvent *  qp = RawPtr_to(QFocusEvent *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->gotFocus();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QFocusEvent.lostFocus();
KMETHOD QFocusEvent_lostFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFocusEvent *  qp = RawPtr_to(QFocusEvent *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->lostFocus();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QFocusEvent.reason();
KMETHOD QFocusEvent_reason(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFocusEvent *  qp = RawPtr_to(QFocusEvent *, sfp[0]);
	if (qp != NULL) {
		Qt::FocusReason ret_v = qp->reason();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQFocusEvent::DummyQFocusEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQFocusEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQFocusEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQFocusEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQFocusEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFocusEvent::event_map->bigin();
	if ((itr = DummyQFocusEvent::event_map->find(str)) == DummyQFocusEvent::event_map->end()) {
		bool ret;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQFocusEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFocusEvent::slot_map->bigin();
	if ((itr = DummyQFocusEvent::event_map->find(str)) == DummyQFocusEvent::slot_map->end()) {
		bool ret;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQFocusEvent::KQFocusEvent(QFocusEvent::Type type, Qt::FocusReason reason) : QFocusEvent(type, reason)
{
	self = NULL;
}

KMETHOD QFocusEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFocusEvent *qp = RawPtr_to(KQFocusEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QFocusEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQFocusEvent::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFocusEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QFocusEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFocusEvent *qp = RawPtr_to(KQFocusEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QFocusEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQFocusEvent::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFocusEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QFocusEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQFocusEvent *qp = (KQFocusEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QFocusEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQFocusEvent *qp = (KQFocusEvent *)p->rawptr;
		(void)qp;
	}
}

static int QFocusEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQFocusEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFocusEvent";
	cdef->free = QFocusEvent_free;
	cdef->reftrace = QFocusEvent_reftrace;
	cdef->compareTo = QFocusEvent_compareTo;
}


