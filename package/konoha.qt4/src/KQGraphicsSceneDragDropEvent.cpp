//void QGraphicsSceneDragDropEvent.acceptProposedAction();
KMETHOD QGraphicsSceneDragDropEvent_acceptProposedAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneDragDropEvent *  qp = RawPtr_to(QGraphicsSceneDragDropEvent *, sfp[0]);
	if (qp) {
		qp->acceptProposedAction();
	}
	RETURNvoid_();
}

//QtMouseButtons QGraphicsSceneDragDropEvent.buttons();
KMETHOD QGraphicsSceneDragDropEvent_buttons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneDragDropEvent *  qp = RawPtr_to(QGraphicsSceneDragDropEvent *, sfp[0]);
	if (qp) {
		Qt::MouseButtons ret_v = qp->buttons();
		Qt::MouseButtons *ret_v_ = new Qt::MouseButtons(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGraphicsSceneDragDropEvent.getDropAction();
KMETHOD QGraphicsSceneDragDropEvent_getDropAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneDragDropEvent *  qp = RawPtr_to(QGraphicsSceneDragDropEvent *, sfp[0]);
	if (qp) {
		Qt::DropAction ret_v = qp->dropAction();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QMimeData QGraphicsSceneDragDropEvent.mimeData();
KMETHOD QGraphicsSceneDragDropEvent_mimeData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneDragDropEvent *  qp = RawPtr_to(QGraphicsSceneDragDropEvent *, sfp[0]);
	if (qp) {
		const QMimeData* ret_v = qp->mimeData();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMimeData*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QtKeyboardModifiers QGraphicsSceneDragDropEvent.modifiers();
KMETHOD QGraphicsSceneDragDropEvent_modifiers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneDragDropEvent *  qp = RawPtr_to(QGraphicsSceneDragDropEvent *, sfp[0]);
	if (qp) {
		Qt::KeyboardModifiers ret_v = qp->modifiers();
		Qt::KeyboardModifiers *ret_v_ = new Qt::KeyboardModifiers(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QGraphicsSceneDragDropEvent.pos();
KMETHOD QGraphicsSceneDragDropEvent_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneDragDropEvent *  qp = RawPtr_to(QGraphicsSceneDragDropEvent *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->pos();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QtDropActions QGraphicsSceneDragDropEvent.possibleActions();
KMETHOD QGraphicsSceneDragDropEvent_possibleActions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneDragDropEvent *  qp = RawPtr_to(QGraphicsSceneDragDropEvent *, sfp[0]);
	if (qp) {
		Qt::DropActions ret_v = qp->possibleActions();
		Qt::DropActions *ret_v_ = new Qt::DropActions(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGraphicsSceneDragDropEvent.proposedAction();
KMETHOD QGraphicsSceneDragDropEvent_proposedAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneDragDropEvent *  qp = RawPtr_to(QGraphicsSceneDragDropEvent *, sfp[0]);
	if (qp) {
		Qt::DropAction ret_v = qp->proposedAction();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPointF QGraphicsSceneDragDropEvent.scenePos();
KMETHOD QGraphicsSceneDragDropEvent_scenePos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneDragDropEvent *  qp = RawPtr_to(QGraphicsSceneDragDropEvent *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->scenePos();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QGraphicsSceneDragDropEvent.screenPos();
KMETHOD QGraphicsSceneDragDropEvent_screenPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneDragDropEvent *  qp = RawPtr_to(QGraphicsSceneDragDropEvent *, sfp[0]);
	if (qp) {
		QPoint ret_v = qp->screenPos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsSceneDragDropEvent.setDropAction(int action);
KMETHOD QGraphicsSceneDragDropEvent_setDropAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneDragDropEvent *  qp = RawPtr_to(QGraphicsSceneDragDropEvent *, sfp[0]);
	if (qp) {
		Qt::DropAction action = Int_to(Qt::DropAction, sfp[1]);
		qp->setDropAction(action);
	}
	RETURNvoid_();
}

//QWidget QGraphicsSceneDragDropEvent.source();
KMETHOD QGraphicsSceneDragDropEvent_source(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneDragDropEvent *  qp = RawPtr_to(QGraphicsSceneDragDropEvent *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->source();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQGraphicsSceneDragDropEvent::DummyQGraphicsSceneDragDropEvent()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQGraphicsSceneDragDropEvent::~DummyQGraphicsSceneDragDropEvent()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQGraphicsSceneDragDropEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsSceneDragDropEvent::self = ptr;
	DummyQGraphicsSceneEvent::setSelf(ptr);
}

bool DummyQGraphicsSceneDragDropEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsSceneEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsSceneDragDropEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsSceneDragDropEvent::event_map->bigin();
	if ((itr = DummyQGraphicsSceneDragDropEvent::event_map->find(str)) == DummyQGraphicsSceneDragDropEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsSceneEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsSceneDragDropEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsSceneDragDropEvent::slot_map->bigin();
	if ((itr = DummyQGraphicsSceneDragDropEvent::slot_map->find(str)) == DummyQGraphicsSceneDragDropEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsSceneEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGraphicsSceneDragDropEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsSceneDragDropEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQGraphicsSceneEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGraphicsSceneDragDropEvent::connection(QObject *o)
{
	QGraphicsSceneDragDropEvent *p = dynamic_cast<QGraphicsSceneDragDropEvent*>(o);
	if (p != NULL) {
	}
	DummyQGraphicsSceneEvent::connection(o);
}

KQGraphicsSceneDragDropEvent::~KQGraphicsSceneDragDropEvent()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QGraphicsSceneDragDropEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsSceneDragDropEvent *qp = RawPtr_to(KQGraphicsSceneDragDropEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsSceneDragDropEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsSceneDragDropEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsSceneDragDropEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsSceneDragDropEvent *qp = RawPtr_to(KQGraphicsSceneDragDropEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsSceneDragDropEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsSceneDragDropEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsSceneDragDropEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQGraphicsSceneDragDropEvent *qp = (KQGraphicsSceneDragDropEvent *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QGraphicsSceneDragDropEvent*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QGraphicsSceneDragDropEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQGraphicsSceneDragDropEvent *qp = (KQGraphicsSceneDragDropEvent *)p->rawptr;
		KQGraphicsSceneDragDropEvent *qp = static_cast<KQGraphicsSceneDragDropEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsSceneDragDropEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsSceneDragDropEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQGraphicsSceneDragDropEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsSceneDragDropEvent";
	cdef->free = QGraphicsSceneDragDropEvent_free;
	cdef->reftrace = QGraphicsSceneDragDropEvent_reftrace;
	cdef->compareTo = QGraphicsSceneDragDropEvent_compareTo;
}


