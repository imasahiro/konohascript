//QCloseEvent QCloseEvent.new();
KMETHOD QCloseEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCloseEvent *ret_v = new KQCloseEvent();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}


DummyQCloseEvent::DummyQCloseEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQCloseEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQCloseEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQCloseEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQCloseEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCloseEvent::event_map->bigin();
	if ((itr = DummyQCloseEvent::event_map->find(str)) == DummyQCloseEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQCloseEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCloseEvent::slot_map->bigin();
	if ((itr = DummyQCloseEvent::slot_map->find(str)) == DummyQCloseEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQCloseEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQEvent::reftrace(ctx, p, tail_);
}

void DummyQCloseEvent::connection(QObject *o)
{
	QCloseEvent *p = dynamic_cast<QCloseEvent*>(o);
	if (p != NULL) {
	}
	DummyQEvent::connection(o);
}

KQCloseEvent::KQCloseEvent() : QCloseEvent()
{
	self = NULL;
	dummy = new DummyQCloseEvent();
}

KMETHOD QCloseEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCloseEvent *qp = RawPtr_to(KQCloseEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QCloseEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCloseEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QCloseEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCloseEvent *qp = RawPtr_to(KQCloseEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QCloseEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCloseEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QCloseEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQCloseEvent *qp = (KQCloseEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QCloseEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQCloseEvent *qp = (KQCloseEvent *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QCloseEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQCloseEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQCloseEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QCloseEvent";
	cdef->free = QCloseEvent_free;
	cdef->reftrace = QCloseEvent_reftrace;
	cdef->compareTo = QCloseEvent_compareTo;
}


