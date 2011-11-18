//QGraphicsSceneResizeEvent QGraphicsSceneResizeEvent.new();
KMETHOD QGraphicsSceneResizeEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsSceneResizeEvent *ret_v = new KQGraphicsSceneResizeEvent();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QSizeF QGraphicsSceneResizeEvent.newSize();
KMETHOD QGraphicsSceneResizeEvent_newSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneResizeEvent *  qp = RawPtr_to(QGraphicsSceneResizeEvent *, sfp[0]);
	if (qp) {
		QSizeF ret_v = qp->newSize();
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSizeF QGraphicsSceneResizeEvent.oldSize();
KMETHOD QGraphicsSceneResizeEvent_oldSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsSceneResizeEvent *  qp = RawPtr_to(QGraphicsSceneResizeEvent *, sfp[0]);
	if (qp) {
		QSizeF ret_v = qp->oldSize();
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQGraphicsSceneResizeEvent::DummyQGraphicsSceneResizeEvent()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQGraphicsSceneResizeEvent::~DummyQGraphicsSceneResizeEvent()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQGraphicsSceneResizeEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsSceneResizeEvent::self = ptr;
	DummyQGraphicsSceneEvent::setSelf(ptr);
}

bool DummyQGraphicsSceneResizeEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsSceneEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsSceneResizeEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsSceneResizeEvent::event_map->bigin();
	if ((itr = DummyQGraphicsSceneResizeEvent::event_map->find(str)) == DummyQGraphicsSceneResizeEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsSceneEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsSceneResizeEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsSceneResizeEvent::slot_map->bigin();
	if ((itr = DummyQGraphicsSceneResizeEvent::slot_map->find(str)) == DummyQGraphicsSceneResizeEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsSceneEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGraphicsSceneResizeEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsSceneResizeEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQGraphicsSceneEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGraphicsSceneResizeEvent::connection(QObject *o)
{
	QGraphicsSceneResizeEvent *p = dynamic_cast<QGraphicsSceneResizeEvent*>(o);
	if (p != NULL) {
	}
	DummyQGraphicsSceneEvent::connection(o);
}

KQGraphicsSceneResizeEvent::KQGraphicsSceneResizeEvent() : QGraphicsSceneResizeEvent()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQGraphicsSceneResizeEvent();
}

KQGraphicsSceneResizeEvent::~KQGraphicsSceneResizeEvent()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QGraphicsSceneResizeEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsSceneResizeEvent *qp = RawPtr_to(KQGraphicsSceneResizeEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsSceneResizeEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsSceneResizeEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsSceneResizeEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsSceneResizeEvent *qp = RawPtr_to(KQGraphicsSceneResizeEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsSceneResizeEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsSceneResizeEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsSceneResizeEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQGraphicsSceneResizeEvent *qp = (KQGraphicsSceneResizeEvent *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QGraphicsSceneResizeEvent*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QGraphicsSceneResizeEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQGraphicsSceneResizeEvent *qp = (KQGraphicsSceneResizeEvent *)p->rawptr;
		KQGraphicsSceneResizeEvent *qp = static_cast<KQGraphicsSceneResizeEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsSceneResizeEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsSceneResizeEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQGraphicsSceneResizeEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsSceneResizeEvent";
	cdef->free = QGraphicsSceneResizeEvent_free;
	cdef->reftrace = QGraphicsSceneResizeEvent_reftrace;
	cdef->compareTo = QGraphicsSceneResizeEvent_compareTo;
}


