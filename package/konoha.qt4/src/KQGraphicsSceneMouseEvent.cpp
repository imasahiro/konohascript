//int QGraphicsSceneMouseEvent.button();
KMETHOD QGraphicsSceneMouseEvent_button(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneMouseEvent *  qp = RawPtr_to(QGraphicsSceneMouseEvent *, sfp[0]);
	if (qp != NULL) {
		Qt::MouseButton ret_v = qp->button();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPointF QGraphicsSceneMouseEvent.buttonDownPos(int button);
KMETHOD QGraphicsSceneMouseEvent_buttonDownPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneMouseEvent *  qp = RawPtr_to(QGraphicsSceneMouseEvent *, sfp[0]);
	if (qp != NULL) {
		Qt::MouseButton button = Int_to(Qt::MouseButton, sfp[1]);
		QPointF ret_v = qp->buttonDownPos(button);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QGraphicsSceneMouseEvent.buttonDownScenePos(int button);
KMETHOD QGraphicsSceneMouseEvent_buttonDownScenePos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneMouseEvent *  qp = RawPtr_to(QGraphicsSceneMouseEvent *, sfp[0]);
	if (qp != NULL) {
		Qt::MouseButton button = Int_to(Qt::MouseButton, sfp[1]);
		QPointF ret_v = qp->buttonDownScenePos(button);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QGraphicsSceneMouseEvent.buttonDownScreenPos(int button);
KMETHOD QGraphicsSceneMouseEvent_buttonDownScreenPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneMouseEvent *  qp = RawPtr_to(QGraphicsSceneMouseEvent *, sfp[0]);
	if (qp != NULL) {
		Qt::MouseButton button = Int_to(Qt::MouseButton, sfp[1]);
		QPoint ret_v = qp->buttonDownScreenPos(button);
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGraphicsSceneMouseEvent.buttons();
KMETHOD QGraphicsSceneMouseEvent_buttons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneMouseEvent *  qp = RawPtr_to(QGraphicsSceneMouseEvent *, sfp[0]);
	if (qp != NULL) {
		Qt::MouseButtons ret_v = qp->buttons();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPointF QGraphicsSceneMouseEvent.lastPos();
KMETHOD QGraphicsSceneMouseEvent_lastPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneMouseEvent *  qp = RawPtr_to(QGraphicsSceneMouseEvent *, sfp[0]);
	if (qp != NULL) {
		QPointF ret_v = qp->lastPos();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QGraphicsSceneMouseEvent.lastScenePos();
KMETHOD QGraphicsSceneMouseEvent_lastScenePos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneMouseEvent *  qp = RawPtr_to(QGraphicsSceneMouseEvent *, sfp[0]);
	if (qp != NULL) {
		QPointF ret_v = qp->lastScenePos();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QGraphicsSceneMouseEvent.lastScreenPos();
KMETHOD QGraphicsSceneMouseEvent_lastScreenPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneMouseEvent *  qp = RawPtr_to(QGraphicsSceneMouseEvent *, sfp[0]);
	if (qp != NULL) {
		QPoint ret_v = qp->lastScreenPos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGraphicsSceneMouseEvent.modifiers();
KMETHOD QGraphicsSceneMouseEvent_modifiers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneMouseEvent *  qp = RawPtr_to(QGraphicsSceneMouseEvent *, sfp[0]);
	if (qp != NULL) {
		Qt::KeyboardModifiers ret_v = qp->modifiers();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPointF QGraphicsSceneMouseEvent.pos();
KMETHOD QGraphicsSceneMouseEvent_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneMouseEvent *  qp = RawPtr_to(QGraphicsSceneMouseEvent *, sfp[0]);
	if (qp != NULL) {
		QPointF ret_v = qp->pos();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QGraphicsSceneMouseEvent.scenePos();
KMETHOD QGraphicsSceneMouseEvent_scenePos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneMouseEvent *  qp = RawPtr_to(QGraphicsSceneMouseEvent *, sfp[0]);
	if (qp != NULL) {
		QPointF ret_v = qp->scenePos();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QGraphicsSceneMouseEvent.screenPos();
KMETHOD QGraphicsSceneMouseEvent_screenPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneMouseEvent *  qp = RawPtr_to(QGraphicsSceneMouseEvent *, sfp[0]);
	if (qp != NULL) {
		QPoint ret_v = qp->screenPos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQGraphicsSceneMouseEvent::DummyQGraphicsSceneMouseEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGraphicsSceneMouseEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsSceneMouseEvent::self = ptr;
	DummyQGraphicsSceneEvent::setSelf(ptr);
}

bool DummyQGraphicsSceneMouseEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsSceneEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsSceneMouseEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsSceneMouseEvent::event_map->bigin();
	if ((itr = DummyQGraphicsSceneMouseEvent::event_map->find(str)) == DummyQGraphicsSceneMouseEvent::event_map->end()) {
		bool ret;
		ret = DummyQGraphicsSceneEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsSceneMouseEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsSceneMouseEvent::slot_map->bigin();
	if ((itr = DummyQGraphicsSceneMouseEvent::event_map->find(str)) == DummyQGraphicsSceneMouseEvent::slot_map->end()) {
		bool ret;
		ret = DummyQGraphicsSceneEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQGraphicsSceneMouseEvent::KQGraphicsSceneMouseEvent() : QGraphicsSceneMouseEvent()
{
	self = NULL;
}

KMETHOD QGraphicsSceneMouseEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsSceneMouseEvent *qp = RawPtr_to(KQGraphicsSceneMouseEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsSceneMouseEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQGraphicsSceneMouseEvent::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsSceneMouseEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QGraphicsSceneMouseEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsSceneMouseEvent *qp = RawPtr_to(KQGraphicsSceneMouseEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsSceneMouseEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQGraphicsSceneMouseEvent::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsSceneMouseEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsSceneMouseEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsSceneMouseEvent *qp = (KQGraphicsSceneMouseEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsSceneMouseEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQGraphicsSceneMouseEvent *qp = (KQGraphicsSceneMouseEvent *)p->rawptr;
		(void)qp;
	}
}

static int QGraphicsSceneMouseEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQGraphicsSceneMouseEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsSceneMouseEvent";
	cdef->free = QGraphicsSceneMouseEvent_free;
	cdef->reftrace = QGraphicsSceneMouseEvent_reftrace;
	cdef->compareTo = QGraphicsSceneMouseEvent_compareTo;
}


