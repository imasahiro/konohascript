//QGestureEvent QGestureEvent.new(Array<QGesture> gestures);
KMETHOD QGestureEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QGesture*> gestures;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			gestures.append((QGesture*)p->rawptr);
		}
	KQGestureEvent *ret_v = new KQGestureEvent(gestures);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//Array<QGesture> QGestureEvent.activeGestures();
KMETHOD QGestureEvent_activeGestures(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGestureEvent *  qp = RawPtr_to(QGestureEvent *, sfp[0]);
	if (qp) {
		QList<QGesture*> ret_v = qp->activeGestures();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QGesture"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//Array<QGesture> QGestureEvent.canceledGestures();
KMETHOD QGestureEvent_canceledGestures(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGestureEvent *  qp = RawPtr_to(QGestureEvent *, sfp[0]);
	if (qp) {
		QList<QGesture*> ret_v = qp->canceledGestures();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QGesture"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QGesture QGestureEvent.gesture(int type);
KMETHOD QGestureEvent_gesture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGestureEvent *  qp = RawPtr_to(QGestureEvent *, sfp[0]);
	if (qp) {
		Qt::GestureType type = Int_to(Qt::GestureType, sfp[1]);
		QGesture* ret_v = qp->gesture(type);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGesture*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QGesture> QGestureEvent.gestures();
KMETHOD QGestureEvent_gestures(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGestureEvent *  qp = RawPtr_to(QGestureEvent *, sfp[0]);
	if (qp) {
		QList<QGesture*> ret_v = qp->gestures();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QGesture"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QPointF QGestureEvent.mapToGraphicsScene(QPointF gesturePoint);
KMETHOD QGestureEvent_mapToGraphicsScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGestureEvent *  qp = RawPtr_to(QGestureEvent *, sfp[0]);
	if (qp) {
		const QPointF  gesturePoint = *RawPtr_to(const QPointF *, sfp[1]);
		QPointF ret_v = qp->mapToGraphicsScene(gesturePoint);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QGestureEvent.widget();
KMETHOD QGestureEvent_widget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGestureEvent *  qp = RawPtr_to(QGestureEvent *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->widget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQGestureEvent::DummyQGestureEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGestureEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGestureEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQGestureEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGestureEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGestureEvent::event_map->bigin();
	if ((itr = DummyQGestureEvent::event_map->find(str)) == DummyQGestureEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGestureEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGestureEvent::slot_map->bigin();
	if ((itr = DummyQGestureEvent::slot_map->find(str)) == DummyQGestureEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGestureEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGestureEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGestureEvent::connection(QObject *o)
{
	QGestureEvent *p = dynamic_cast<QGestureEvent*>(o);
	if (p != NULL) {
	}
	DummyQEvent::connection(o);
}

KQGestureEvent::KQGestureEvent(const QList<QGesture*> gestures) : QGestureEvent(gestures)
{
	self = NULL;
	dummy = new DummyQGestureEvent();
}

KMETHOD QGestureEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGestureEvent *qp = RawPtr_to(KQGestureEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGestureEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGestureEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGestureEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGestureEvent *qp = RawPtr_to(KQGestureEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGestureEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGestureEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGestureEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGestureEvent *qp = (KQGestureEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGestureEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGestureEvent *qp = (KQGestureEvent *)p->rawptr;
//		KQGestureEvent *qp = static_cast<KQGestureEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGestureEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGestureEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQGestureEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGestureEvent";
	cdef->free = QGestureEvent_free;
	cdef->reftrace = QGestureEvent_reftrace;
	cdef->compareTo = QGestureEvent_compareTo;
}


