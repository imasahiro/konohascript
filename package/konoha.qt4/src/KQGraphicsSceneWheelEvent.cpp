//QtMouseButtons QGraphicsSceneWheelEvent.buttons();
KMETHOD QGraphicsSceneWheelEvent_buttons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneWheelEvent *  qp = RawPtr_to(QGraphicsSceneWheelEvent *, sfp[0]);
	if (qp) {
		Qt::MouseButtons ret_v = qp->buttons();
		Qt::MouseButtons *ret_v_ = new Qt::MouseButtons(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGraphicsSceneWheelEvent.delta();
KMETHOD QGraphicsSceneWheelEvent_delta(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneWheelEvent *  qp = RawPtr_to(QGraphicsSceneWheelEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->delta();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QtKeyboardModifiers QGraphicsSceneWheelEvent.modifiers();
KMETHOD QGraphicsSceneWheelEvent_modifiers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneWheelEvent *  qp = RawPtr_to(QGraphicsSceneWheelEvent *, sfp[0]);
	if (qp) {
		Qt::KeyboardModifiers ret_v = qp->modifiers();
		Qt::KeyboardModifiers *ret_v_ = new Qt::KeyboardModifiers(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGraphicsSceneWheelEvent.orientation();
KMETHOD QGraphicsSceneWheelEvent_orientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneWheelEvent *  qp = RawPtr_to(QGraphicsSceneWheelEvent *, sfp[0]);
	if (qp) {
		Qt::Orientation ret_v = qp->orientation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPointF QGraphicsSceneWheelEvent.pos();
KMETHOD QGraphicsSceneWheelEvent_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneWheelEvent *  qp = RawPtr_to(QGraphicsSceneWheelEvent *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->pos();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QGraphicsSceneWheelEvent.scenePos();
KMETHOD QGraphicsSceneWheelEvent_scenePos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneWheelEvent *  qp = RawPtr_to(QGraphicsSceneWheelEvent *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->scenePos();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QGraphicsSceneWheelEvent.screenPos();
KMETHOD QGraphicsSceneWheelEvent_screenPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneWheelEvent *  qp = RawPtr_to(QGraphicsSceneWheelEvent *, sfp[0]);
	if (qp) {
		QPoint ret_v = qp->screenPos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQGraphicsSceneWheelEvent::DummyQGraphicsSceneWheelEvent()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQGraphicsSceneWheelEvent::~DummyQGraphicsSceneWheelEvent()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQGraphicsSceneWheelEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsSceneWheelEvent::self = ptr;
	DummyQGraphicsSceneEvent::setSelf(ptr);
}

bool DummyQGraphicsSceneWheelEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsSceneEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsSceneWheelEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsSceneWheelEvent::event_map->bigin();
	if ((itr = DummyQGraphicsSceneWheelEvent::event_map->find(str)) == DummyQGraphicsSceneWheelEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsSceneEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsSceneWheelEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsSceneWheelEvent::slot_map->bigin();
	if ((itr = DummyQGraphicsSceneWheelEvent::slot_map->find(str)) == DummyQGraphicsSceneWheelEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsSceneEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGraphicsSceneWheelEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsSceneWheelEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQGraphicsSceneEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGraphicsSceneWheelEvent::connection(QObject *o)
{
	QGraphicsSceneWheelEvent *p = dynamic_cast<QGraphicsSceneWheelEvent*>(o);
	if (p != NULL) {
	}
	DummyQGraphicsSceneEvent::connection(o);
}

KQGraphicsSceneWheelEvent::~KQGraphicsSceneWheelEvent()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QGraphicsSceneWheelEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsSceneWheelEvent *qp = RawPtr_to(KQGraphicsSceneWheelEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsSceneWheelEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsSceneWheelEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsSceneWheelEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsSceneWheelEvent *qp = RawPtr_to(KQGraphicsSceneWheelEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsSceneWheelEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsSceneWheelEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsSceneWheelEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQGraphicsSceneWheelEvent *qp = (KQGraphicsSceneWheelEvent *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QGraphicsSceneWheelEvent*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QGraphicsSceneWheelEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQGraphicsSceneWheelEvent *qp = (KQGraphicsSceneWheelEvent *)p->rawptr;
		KQGraphicsSceneWheelEvent *qp = static_cast<KQGraphicsSceneWheelEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsSceneWheelEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsSceneWheelEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQGraphicsSceneWheelEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsSceneWheelEvent";
	cdef->free = QGraphicsSceneWheelEvent_free;
	cdef->reftrace = QGraphicsSceneWheelEvent_reftrace;
	cdef->compareTo = QGraphicsSceneWheelEvent_compareTo;
}


