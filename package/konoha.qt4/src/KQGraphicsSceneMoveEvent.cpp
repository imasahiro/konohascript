//QGraphicsSceneMoveEvent QGraphicsSceneMoveEvent.new();
KMETHOD QGraphicsSceneMoveEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsSceneMoveEvent *ret_v = new KQGraphicsSceneMoveEvent();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QPointF QGraphicsSceneMoveEvent.newPos();
KMETHOD QGraphicsSceneMoveEvent_newPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneMoveEvent *  qp = RawPtr_to(QGraphicsSceneMoveEvent *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->newPos();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QGraphicsSceneMoveEvent.oldPos();
KMETHOD QGraphicsSceneMoveEvent_oldPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneMoveEvent *  qp = RawPtr_to(QGraphicsSceneMoveEvent *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->oldPos();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQGraphicsSceneMoveEvent::DummyQGraphicsSceneMoveEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGraphicsSceneMoveEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsSceneMoveEvent::self = ptr;
	DummyQGraphicsSceneEvent::setSelf(ptr);
}

bool DummyQGraphicsSceneMoveEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsSceneEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsSceneMoveEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsSceneMoveEvent::event_map->bigin();
	if ((itr = DummyQGraphicsSceneMoveEvent::event_map->find(str)) == DummyQGraphicsSceneMoveEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsSceneEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsSceneMoveEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsSceneMoveEvent::slot_map->bigin();
	if ((itr = DummyQGraphicsSceneMoveEvent::slot_map->find(str)) == DummyQGraphicsSceneMoveEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsSceneEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGraphicsSceneMoveEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsSceneMoveEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQGraphicsSceneEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGraphicsSceneMoveEvent::connection(QObject *o)
{
	QGraphicsSceneMoveEvent *p = dynamic_cast<QGraphicsSceneMoveEvent*>(o);
	if (p != NULL) {
	}
	DummyQGraphicsSceneEvent::connection(o);
}

KQGraphicsSceneMoveEvent::KQGraphicsSceneMoveEvent() : QGraphicsSceneMoveEvent()
{
	self = NULL;
	dummy = new DummyQGraphicsSceneMoveEvent();
}

KMETHOD QGraphicsSceneMoveEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsSceneMoveEvent *qp = RawPtr_to(KQGraphicsSceneMoveEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsSceneMoveEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsSceneMoveEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsSceneMoveEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsSceneMoveEvent *qp = RawPtr_to(KQGraphicsSceneMoveEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsSceneMoveEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsSceneMoveEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsSceneMoveEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsSceneMoveEvent *qp = (KQGraphicsSceneMoveEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsSceneMoveEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGraphicsSceneMoveEvent *qp = (KQGraphicsSceneMoveEvent *)p->rawptr;
//		KQGraphicsSceneMoveEvent *qp = static_cast<KQGraphicsSceneMoveEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsSceneMoveEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsSceneMoveEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQGraphicsSceneMoveEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsSceneMoveEvent";
	cdef->free = QGraphicsSceneMoveEvent_free;
	cdef->reftrace = QGraphicsSceneMoveEvent_reftrace;
	cdef->compareTo = QGraphicsSceneMoveEvent_compareTo;
}


