//QAccessibleEvent QAccessibleEvent.new(int type, int child);
KMETHOD QAccessibleEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleEvent::Type type = Int_to(QAccessibleEvent::Type, sfp[1]);
	int child = Int_to(int, sfp[2]);
	KQAccessibleEvent *ret_v = new KQAccessibleEvent(type, child);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QAccessibleEvent.child();
KMETHOD QAccessibleEvent_child(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleEvent *  qp = RawPtr_to(QAccessibleEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->child();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QAccessibleEvent.setValue(String text);
KMETHOD QAccessibleEvent_setValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleEvent *  qp = RawPtr_to(QAccessibleEvent *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setValue(text);
	}
	RETURNvoid_();
}

//String QAccessibleEvent.getValue();
KMETHOD QAccessibleEvent_getValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleEvent *  qp = RawPtr_to(QAccessibleEvent *, sfp[0]);
	if (qp) {
		QString ret_v = qp->value();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQAccessibleEvent::DummyQAccessibleEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQAccessibleEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAccessibleEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQAccessibleEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAccessibleEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAccessibleEvent::event_map->bigin();
	if ((itr = DummyQAccessibleEvent::event_map->find(str)) == DummyQAccessibleEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAccessibleEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAccessibleEvent::slot_map->bigin();
	if ((itr = DummyQAccessibleEvent::slot_map->find(str)) == DummyQAccessibleEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQAccessibleEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQEvent::reftrace(ctx, p, tail_);
}

void DummyQAccessibleEvent::connection(QObject *o)
{
	QAccessibleEvent *p = dynamic_cast<QAccessibleEvent*>(o);
	if (p != NULL) {
	}
	DummyQEvent::connection(o);
}

KQAccessibleEvent::KQAccessibleEvent(QAccessibleEvent::Type type, int child) : QAccessibleEvent(type, child)
{
	self = NULL;
	dummy = new DummyQAccessibleEvent();
}

KMETHOD QAccessibleEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAccessibleEvent *qp = RawPtr_to(KQAccessibleEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAccessibleEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAccessibleEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAccessibleEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAccessibleEvent *qp = RawPtr_to(KQAccessibleEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAccessibleEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAccessibleEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAccessibleEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAccessibleEvent *qp = (KQAccessibleEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAccessibleEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQAccessibleEvent *qp = (KQAccessibleEvent *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAccessibleEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAccessibleEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQAccessibleEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAccessibleEvent";
	cdef->free = QAccessibleEvent_free;
	cdef->reftrace = QAccessibleEvent_reftrace;
	cdef->compareTo = QAccessibleEvent_compareTo;
}


