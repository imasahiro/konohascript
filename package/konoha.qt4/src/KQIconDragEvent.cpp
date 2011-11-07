//QIconDragEvent QIconDragEvent.new();
KMETHOD QIconDragEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQIconDragEvent *ret_v = new KQIconDragEvent();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}


DummyQIconDragEvent::DummyQIconDragEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQIconDragEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQIconDragEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQIconDragEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQIconDragEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQIconDragEvent::event_map->bigin();
	if ((itr = DummyQIconDragEvent::event_map->find(str)) == DummyQIconDragEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQIconDragEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQIconDragEvent::slot_map->bigin();
	if ((itr = DummyQIconDragEvent::slot_map->find(str)) == DummyQIconDragEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQIconDragEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQEvent::reftrace(ctx, p, tail_);
}

void DummyQIconDragEvent::connection(QObject *o)
{
	QIconDragEvent *p = dynamic_cast<QIconDragEvent*>(o);
	if (p != NULL) {
	}
	DummyQEvent::connection(o);
}

KQIconDragEvent::KQIconDragEvent() : QIconDragEvent()
{
	self = NULL;
	dummy = new DummyQIconDragEvent();
}

KMETHOD QIconDragEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQIconDragEvent *qp = RawPtr_to(KQIconDragEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QIconDragEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QIconDragEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QIconDragEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQIconDragEvent *qp = RawPtr_to(KQIconDragEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QIconDragEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QIconDragEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QIconDragEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQIconDragEvent *qp = (KQIconDragEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QIconDragEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQIconDragEvent *qp = (KQIconDragEvent *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QIconDragEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQIconDragEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQIconDragEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QIconDragEvent";
	cdef->free = QIconDragEvent_free;
	cdef->reftrace = QIconDragEvent_reftrace;
	cdef->compareTo = QIconDragEvent_compareTo;
}


