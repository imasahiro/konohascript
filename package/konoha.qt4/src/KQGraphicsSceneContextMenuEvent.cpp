//QtKeyboardModifiers QGraphicsSceneContextMenuEvent.modifiers();
KMETHOD QGraphicsSceneContextMenuEvent_modifiers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneContextMenuEvent *  qp = RawPtr_to(QGraphicsSceneContextMenuEvent *, sfp[0]);
	if (qp) {
		Qt::KeyboardModifiers ret_v = qp->modifiers();
		Qt::KeyboardModifiers *ret_v_ = new Qt::KeyboardModifiers(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QGraphicsSceneContextMenuEvent.pos();
KMETHOD QGraphicsSceneContextMenuEvent_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneContextMenuEvent *  qp = RawPtr_to(QGraphicsSceneContextMenuEvent *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->pos();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGraphicsSceneContextMenuEvent.reason();
KMETHOD QGraphicsSceneContextMenuEvent_reason(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneContextMenuEvent *  qp = RawPtr_to(QGraphicsSceneContextMenuEvent *, sfp[0]);
	if (qp) {
		QGraphicsSceneContextMenuEvent::Reason ret_v = qp->reason();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPointF QGraphicsSceneContextMenuEvent.scenePos();
KMETHOD QGraphicsSceneContextMenuEvent_scenePos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneContextMenuEvent *  qp = RawPtr_to(QGraphicsSceneContextMenuEvent *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->scenePos();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QGraphicsSceneContextMenuEvent.screenPos();
KMETHOD QGraphicsSceneContextMenuEvent_screenPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneContextMenuEvent *  qp = RawPtr_to(QGraphicsSceneContextMenuEvent *, sfp[0]);
	if (qp) {
		QPoint ret_v = qp->screenPos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQGraphicsSceneContextMenuEvent::DummyQGraphicsSceneContextMenuEvent()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQGraphicsSceneContextMenuEvent::~DummyQGraphicsSceneContextMenuEvent()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQGraphicsSceneContextMenuEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsSceneContextMenuEvent::self = ptr;
	DummyQGraphicsSceneEvent::setSelf(ptr);
}

bool DummyQGraphicsSceneContextMenuEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsSceneEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsSceneContextMenuEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsSceneContextMenuEvent::event_map->bigin();
	if ((itr = DummyQGraphicsSceneContextMenuEvent::event_map->find(str)) == DummyQGraphicsSceneContextMenuEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsSceneEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsSceneContextMenuEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsSceneContextMenuEvent::slot_map->bigin();
	if ((itr = DummyQGraphicsSceneContextMenuEvent::slot_map->find(str)) == DummyQGraphicsSceneContextMenuEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsSceneEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGraphicsSceneContextMenuEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsSceneContextMenuEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQGraphicsSceneEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGraphicsSceneContextMenuEvent::connection(QObject *o)
{
	QGraphicsSceneContextMenuEvent *p = dynamic_cast<QGraphicsSceneContextMenuEvent*>(o);
	if (p != NULL) {
	}
	DummyQGraphicsSceneEvent::connection(o);
}

KQGraphicsSceneContextMenuEvent::~KQGraphicsSceneContextMenuEvent()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QGraphicsSceneContextMenuEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsSceneContextMenuEvent *qp = RawPtr_to(KQGraphicsSceneContextMenuEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsSceneContextMenuEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsSceneContextMenuEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsSceneContextMenuEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsSceneContextMenuEvent *qp = RawPtr_to(KQGraphicsSceneContextMenuEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsSceneContextMenuEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsSceneContextMenuEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsSceneContextMenuEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQGraphicsSceneContextMenuEvent *qp = (KQGraphicsSceneContextMenuEvent *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QGraphicsSceneContextMenuEvent*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QGraphicsSceneContextMenuEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQGraphicsSceneContextMenuEvent *qp = (KQGraphicsSceneContextMenuEvent *)p->rawptr;
		KQGraphicsSceneContextMenuEvent *qp = static_cast<KQGraphicsSceneContextMenuEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsSceneContextMenuEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsSceneContextMenuEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QGraphicsSceneContextMenuEventConstInt[] = {
	{"Mouse", QGraphicsSceneContextMenuEvent::Mouse},
	{"Keyboard", QGraphicsSceneContextMenuEvent::Keyboard},
	{"Other", QGraphicsSceneContextMenuEvent::Other},
	{NULL, 0}
};

DEFAPI(void) constQGraphicsSceneContextMenuEvent(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QGraphicsSceneContextMenuEventConstInt);
}


DEFAPI(void) defQGraphicsSceneContextMenuEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsSceneContextMenuEvent";
	cdef->free = QGraphicsSceneContextMenuEvent_free;
	cdef->reftrace = QGraphicsSceneContextMenuEvent_reftrace;
	cdef->compareTo = QGraphicsSceneContextMenuEvent_compareTo;
}


