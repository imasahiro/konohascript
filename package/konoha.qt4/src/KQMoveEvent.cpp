//QMoveEvent QMoveEvent.new(QPoint pos, QPoint oldPos);
KMETHOD QMoveEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
	const QPoint  oldPos = *RawPtr_to(const QPoint *, sfp[2]);
	KQMoveEvent *ret_v = new KQMoveEvent(pos, oldPos);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QPoint QMoveEvent.oldPos();
KMETHOD QMoveEvent_oldPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMoveEvent *  qp = RawPtr_to(QMoveEvent *, sfp[0]);
	if (qp) {
		const QPoint ret_v = qp->oldPos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QMoveEvent.pos();
KMETHOD QMoveEvent_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMoveEvent *  qp = RawPtr_to(QMoveEvent *, sfp[0]);
	if (qp) {
		const QPoint ret_v = qp->pos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQMoveEvent::DummyQMoveEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQMoveEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMoveEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQMoveEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQMoveEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMoveEvent::event_map->bigin();
	if ((itr = DummyQMoveEvent::event_map->find(str)) == DummyQMoveEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMoveEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMoveEvent::slot_map->bigin();
	if ((itr = DummyQMoveEvent::slot_map->find(str)) == DummyQMoveEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQMoveEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQEvent::reftrace(ctx, p, tail_);
}

void DummyQMoveEvent::connection(QObject *o)
{
	QMoveEvent *p = dynamic_cast<QMoveEvent*>(o);
	if (p != NULL) {
	}
	DummyQEvent::connection(o);
}

KQMoveEvent::KQMoveEvent(const QPoint pos, const QPoint oldPos) : QMoveEvent(pos, oldPos)
{
	self = NULL;
	dummy = new DummyQMoveEvent();
}

KMETHOD QMoveEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMoveEvent *qp = RawPtr_to(KQMoveEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMoveEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMoveEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QMoveEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMoveEvent *qp = RawPtr_to(KQMoveEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMoveEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMoveEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMoveEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMoveEvent *qp = (KQMoveEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMoveEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQMoveEvent *qp = (KQMoveEvent *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QMoveEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMoveEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQMoveEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMoveEvent";
	cdef->free = QMoveEvent_free;
	cdef->reftrace = QMoveEvent_reftrace;
	cdef->compareTo = QMoveEvent_compareTo;
}


