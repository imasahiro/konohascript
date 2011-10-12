//int QInputEvent.modifiers();
KMETHOD QInputEvent_modifiers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputEvent *  qp = RawPtr_to(QInputEvent *, sfp[0]);
	if (qp != NULL) {
		Qt::KeyboardModifiers ret_v = qp->modifiers();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQInputEvent::DummyQInputEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQInputEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQInputEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQInputEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQInputEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQInputEvent::event_map->bigin();
	if ((itr = DummyQInputEvent::event_map->find(str)) == DummyQInputEvent::event_map->end()) {
		bool ret;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQInputEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQInputEvent::slot_map->bigin();
	if ((itr = DummyQInputEvent::event_map->find(str)) == DummyQInputEvent::slot_map->end()) {
		bool ret;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KMETHOD QInputEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQInputEvent *qp = RawPtr_to(KQInputEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QInputEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQInputEvent::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QInputEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QInputEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQInputEvent *qp = RawPtr_to(KQInputEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QInputEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQInputEvent::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QInputEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QInputEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQInputEvent *qp = (KQInputEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QInputEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQInputEvent *qp = (KQInputEvent *)p->rawptr;
		(void)qp;
	}
}

static int QInputEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQInputEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QInputEvent";
	cdef->free = QInputEvent_free;
	cdef->reftrace = QInputEvent_reftrace;
	cdef->compareTo = QInputEvent_compareTo;
}


