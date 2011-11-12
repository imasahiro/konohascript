//QDragLeaveEvent QDragLeaveEvent.new();
KMETHOD QDragLeaveEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDragLeaveEvent *ret_v = new KQDragLeaveEvent();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}


DummyQDragLeaveEvent::DummyQDragLeaveEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQDragLeaveEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDragLeaveEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQDragLeaveEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQDragLeaveEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDragLeaveEvent::event_map->bigin();
	if ((itr = DummyQDragLeaveEvent::event_map->find(str)) == DummyQDragLeaveEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDragLeaveEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDragLeaveEvent::slot_map->bigin();
	if ((itr = DummyQDragLeaveEvent::slot_map->find(str)) == DummyQDragLeaveEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQDragLeaveEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQDragLeaveEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQDragLeaveEvent::connection(QObject *o)
{
	QDragLeaveEvent *p = dynamic_cast<QDragLeaveEvent*>(o);
	if (p != NULL) {
	}
	DummyQEvent::connection(o);
}

KQDragLeaveEvent::KQDragLeaveEvent() : QDragLeaveEvent()
{
	self = NULL;
	dummy = new DummyQDragLeaveEvent();
}

KMETHOD QDragLeaveEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDragLeaveEvent *qp = RawPtr_to(KQDragLeaveEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDragLeaveEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDragLeaveEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QDragLeaveEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDragLeaveEvent *qp = RawPtr_to(KQDragLeaveEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDragLeaveEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDragLeaveEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDragLeaveEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDragLeaveEvent *qp = (KQDragLeaveEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDragLeaveEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQDragLeaveEvent *qp = (KQDragLeaveEvent *)p->rawptr;
//		KQDragLeaveEvent *qp = static_cast<KQDragLeaveEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QDragLeaveEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQDragLeaveEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQDragLeaveEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDragLeaveEvent";
	cdef->free = QDragLeaveEvent_free;
	cdef->reftrace = QDragLeaveEvent_reftrace;
	cdef->compareTo = QDragLeaveEvent_compareTo;
}


