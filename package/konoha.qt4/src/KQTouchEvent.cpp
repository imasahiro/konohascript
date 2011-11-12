//QTouchEvent QTouchEvent.new(int eventType, int deviceType, QtKeyboardModifiers modifiers, QtTouchPointStates touchPointStates, Array<int> touchPoints);
KMETHOD QTouchEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEvent::Type eventType = Int_to(QEvent::Type, sfp[1]);
	QTouchEvent::DeviceType deviceType = Int_to(QTouchEvent::DeviceType, sfp[2]);
	initFlag(modifiers, Qt::KeyboardModifiers, sfp[3]);
	initFlag(touchPointStates, Qt::TouchPointStates, sfp[4]);
	knh_Array_t *a = sfp[5].a;
		int asize = knh_Array_size(a);
		QList<QTouchEvent::TouchPoint> touchPoints;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			touchPoints.append(*(QTouchEvent::TouchPoint*)p->rawptr);
		}
	KQTouchEvent *ret_v = new KQTouchEvent(eventType, deviceType, modifiers, touchPointStates, touchPoints);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QTouchEvent.deviceType();
KMETHOD QTouchEvent_deviceType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTouchEvent *  qp = RawPtr_to(QTouchEvent *, sfp[0]);
	if (qp) {
		QTouchEvent::DeviceType ret_v = qp->deviceType();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QtTouchPointStates QTouchEvent.touchPointStates();
KMETHOD QTouchEvent_touchPointStates(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTouchEvent *  qp = RawPtr_to(QTouchEvent *, sfp[0]);
	if (qp) {
		Qt::TouchPointStates ret_v = qp->touchPointStates();
		Qt::TouchPointStates *ret_v_ = new Qt::TouchPointStates(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<int> QTouchEvent.touchPoints();
KMETHOD QTouchEvent_touchPoints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTouchEvent *  qp = RawPtr_to(QTouchEvent *, sfp[0]);
	if (qp) {
		const QList<QTouchEvent::TouchPoint> ret_v = qp->touchPoints();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QTouchEvent::TouchPoint"));
		for (int n = 0; n < list_size; n++) {
			QTouchEvent::TouchPoint *ret_v_ = new QTouchEvent::TouchPoint(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QWidget QTouchEvent.widget();
KMETHOD QTouchEvent_widget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTouchEvent *  qp = RawPtr_to(QTouchEvent *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->widget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQTouchEvent::DummyQTouchEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTouchEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTouchEvent::self = ptr;
	DummyQInputEvent::setSelf(ptr);
}

bool DummyQTouchEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQInputEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTouchEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTouchEvent::event_map->bigin();
	if ((itr = DummyQTouchEvent::event_map->find(str)) == DummyQTouchEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQInputEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTouchEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTouchEvent::slot_map->bigin();
	if ((itr = DummyQTouchEvent::slot_map->find(str)) == DummyQTouchEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQInputEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTouchEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTouchEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQInputEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQTouchEvent::connection(QObject *o)
{
	QTouchEvent *p = dynamic_cast<QTouchEvent*>(o);
	if (p != NULL) {
	}
	DummyQInputEvent::connection(o);
}

KQTouchEvent::KQTouchEvent(QEvent::Type eventType, QTouchEvent::DeviceType deviceType, Qt::KeyboardModifiers modifiers, Qt::TouchPointStates touchPointStates, const QList<QTouchEvent::TouchPoint> touchPoints) : QTouchEvent(eventType, deviceType, modifiers, touchPointStates, touchPoints)
{
	self = NULL;
	dummy = new DummyQTouchEvent();
}

KMETHOD QTouchEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTouchEvent *qp = RawPtr_to(KQTouchEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTouchEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTouchEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTouchEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTouchEvent *qp = RawPtr_to(KQTouchEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTouchEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTouchEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTouchEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTouchEvent *qp = (KQTouchEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTouchEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQTouchEvent *qp = (KQTouchEvent *)p->rawptr;
//		KQTouchEvent *qp = static_cast<KQTouchEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTouchEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTouchEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QTouchEventConstInt[] = {
	{"TouchScreen", QTouchEvent::TouchScreen},
	{"TouchPad", QTouchEvent::TouchPad},
	{NULL, 0}
};

DEFAPI(void) constQTouchEvent(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTouchEventConstInt);
}


DEFAPI(void) defQTouchEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTouchEvent";
	cdef->free = QTouchEvent_free;
	cdef->reftrace = QTouchEvent_reftrace;
	cdef->compareTo = QTouchEvent_compareTo;
}


