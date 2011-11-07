//QStatusTipEvent QStatusTipEvent.new(String tip);
KMETHOD QStatusTipEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString tip = String_to(const QString, sfp[1]);
	KQStatusTipEvent *ret_v = new KQStatusTipEvent(tip);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//String QStatusTipEvent.tip();
KMETHOD QStatusTipEvent_tip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStatusTipEvent *  qp = RawPtr_to(QStatusTipEvent *, sfp[0]);
	if (qp) {
		QString ret_v = qp->tip();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQStatusTipEvent::DummyQStatusTipEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStatusTipEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStatusTipEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQStatusTipEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStatusTipEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStatusTipEvent::event_map->bigin();
	if ((itr = DummyQStatusTipEvent::event_map->find(str)) == DummyQStatusTipEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStatusTipEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStatusTipEvent::slot_map->bigin();
	if ((itr = DummyQStatusTipEvent::slot_map->find(str)) == DummyQStatusTipEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQStatusTipEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQEvent::reftrace(ctx, p, tail_);
}

void DummyQStatusTipEvent::connection(QObject *o)
{
	QStatusTipEvent *p = dynamic_cast<QStatusTipEvent*>(o);
	if (p != NULL) {
	}
	DummyQEvent::connection(o);
}

KQStatusTipEvent::KQStatusTipEvent(const QString tip) : QStatusTipEvent(tip)
{
	self = NULL;
	dummy = new DummyQStatusTipEvent();
}

KMETHOD QStatusTipEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStatusTipEvent *qp = RawPtr_to(KQStatusTipEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStatusTipEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStatusTipEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStatusTipEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStatusTipEvent *qp = RawPtr_to(KQStatusTipEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStatusTipEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStatusTipEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStatusTipEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStatusTipEvent *qp = (KQStatusTipEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStatusTipEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQStatusTipEvent *qp = (KQStatusTipEvent *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStatusTipEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStatusTipEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQStatusTipEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStatusTipEvent";
	cdef->free = QStatusTipEvent_free;
	cdef->reftrace = QStatusTipEvent_reftrace;
	cdef->compareTo = QStatusTipEvent_compareTo;
}


