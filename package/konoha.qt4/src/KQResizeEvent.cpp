//QResizeEvent QResizeEvent.new(QSize size, QSize oldSize);
KMETHOD QResizeEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
	const QSize  oldSize = *RawPtr_to(const QSize *, sfp[2]);
	KQResizeEvent *ret_v = new KQResizeEvent(size, oldSize);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QSize QResizeEvent.oldSize();
KMETHOD QResizeEvent_oldSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QResizeEvent *  qp = RawPtr_to(QResizeEvent *, sfp[0]);
	if (qp) {
		const QSize ret_v = qp->oldSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSize QResizeEvent.size();
KMETHOD QResizeEvent_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QResizeEvent *  qp = RawPtr_to(QResizeEvent *, sfp[0]);
	if (qp) {
		const QSize ret_v = qp->size();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQResizeEvent::DummyQResizeEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQResizeEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQResizeEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQResizeEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQResizeEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQResizeEvent::event_map->bigin();
	if ((itr = DummyQResizeEvent::event_map->find(str)) == DummyQResizeEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQResizeEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQResizeEvent::slot_map->bigin();
	if ((itr = DummyQResizeEvent::slot_map->find(str)) == DummyQResizeEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQResizeEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQResizeEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQResizeEvent::connection(QObject *o)
{
	QResizeEvent *p = dynamic_cast<QResizeEvent*>(o);
	if (p != NULL) {
	}
	DummyQEvent::connection(o);
}

KQResizeEvent::KQResizeEvent(const QSize size, const QSize oldSize) : QResizeEvent(size, oldSize)
{
	self = NULL;
	dummy = new DummyQResizeEvent();
}

KMETHOD QResizeEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQResizeEvent *qp = RawPtr_to(KQResizeEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QResizeEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QResizeEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QResizeEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQResizeEvent *qp = RawPtr_to(KQResizeEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QResizeEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QResizeEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QResizeEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQResizeEvent *qp = (KQResizeEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QResizeEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQResizeEvent *qp = (KQResizeEvent *)p->rawptr;
//		KQResizeEvent *qp = static_cast<KQResizeEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QResizeEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQResizeEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQResizeEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QResizeEvent";
	cdef->free = QResizeEvent_free;
	cdef->reftrace = QResizeEvent_reftrace;
	cdef->compareTo = QResizeEvent_compareTo;
}


