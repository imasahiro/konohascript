//QWhatsThisClickedEvent QWhatsThisClickedEvent.new(String href);
KMETHOD QWhatsThisClickedEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString href = String_to(const QString, sfp[1]);
	KQWhatsThisClickedEvent *ret_v = new KQWhatsThisClickedEvent(href);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//String QWhatsThisClickedEvent.href();
KMETHOD QWhatsThisClickedEvent_href(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWhatsThisClickedEvent *  qp = RawPtr_to(QWhatsThisClickedEvent *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->href();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQWhatsThisClickedEvent::DummyQWhatsThisClickedEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQWhatsThisClickedEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWhatsThisClickedEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQWhatsThisClickedEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQWhatsThisClickedEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWhatsThisClickedEvent::event_map->bigin();
	if ((itr = DummyQWhatsThisClickedEvent::event_map->find(str)) == DummyQWhatsThisClickedEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWhatsThisClickedEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWhatsThisClickedEvent::slot_map->bigin();
	if ((itr = DummyQWhatsThisClickedEvent::slot_map->find(str)) == DummyQWhatsThisClickedEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQWhatsThisClickedEvent::connection(QObject *o)
{
	DummyQEvent::connection(o);
}

KQWhatsThisClickedEvent::KQWhatsThisClickedEvent(const QString href) : QWhatsThisClickedEvent(href)
{
	self = NULL;
	dummy = new DummyQWhatsThisClickedEvent();
	dummy->connection((QObject*)this);
}

KMETHOD QWhatsThisClickedEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWhatsThisClickedEvent *qp = RawPtr_to(KQWhatsThisClickedEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWhatsThisClickedEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWhatsThisClickedEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWhatsThisClickedEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWhatsThisClickedEvent *qp = RawPtr_to(KQWhatsThisClickedEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWhatsThisClickedEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWhatsThisClickedEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWhatsThisClickedEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWhatsThisClickedEvent *qp = (KQWhatsThisClickedEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWhatsThisClickedEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQWhatsThisClickedEvent *qp = (KQWhatsThisClickedEvent *)p->rawptr;
		(void)qp;
	}
}

static int QWhatsThisClickedEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWhatsThisClickedEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQWhatsThisClickedEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWhatsThisClickedEvent";
	cdef->free = QWhatsThisClickedEvent_free;
	cdef->reftrace = QWhatsThisClickedEvent_reftrace;
	cdef->compareTo = QWhatsThisClickedEvent_compareTo;
}


