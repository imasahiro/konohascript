//QWheelEvent QWheelEvent.new(QPoint pos, int delta, QtMouseButtons buttons, QtKeyboardModifiers modifiers, int orient);
KMETHOD QWheelEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
	int delta = Int_to(int, sfp[2]);
	initFlag(buttons, Qt::MouseButtons, sfp[3]);
	initFlag(modifiers, Qt::KeyboardModifiers, sfp[4]);
	Qt::Orientation orient = Int_to(Qt::Orientation, sfp[5]);
	KQWheelEvent *ret_v = new KQWheelEvent(pos, delta, buttons, modifiers, orient);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QWheelEvent QWheelEvent.new(QPoint pos, QPoint globalPos, int delta, QtMouseButtons buttons, QtKeyboardModifiers modifiers, int orient);
KMETHOD QWheelEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
	const QPoint  globalPos = *RawPtr_to(const QPoint *, sfp[2]);
	int delta = Int_to(int, sfp[3]);
	initFlag(buttons, Qt::MouseButtons, sfp[4]);
	initFlag(modifiers, Qt::KeyboardModifiers, sfp[5]);
	Qt::Orientation orient = Int_to(Qt::Orientation, sfp[6]);
	KQWheelEvent *ret_v = new KQWheelEvent(pos, globalPos, delta, buttons, modifiers, orient);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QtMouseButtons QWheelEvent.buttons();
KMETHOD QWheelEvent_buttons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWheelEvent *  qp = RawPtr_to(QWheelEvent *, sfp[0]);
	if (qp) {
		Qt::MouseButtons ret_v = qp->buttons();
		Qt::MouseButtons *ret_v_ = new Qt::MouseButtons(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWheelEvent.delta();
KMETHOD QWheelEvent_delta(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWheelEvent *  qp = RawPtr_to(QWheelEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->delta();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPoint QWheelEvent.globalPos();
KMETHOD QWheelEvent_globalPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWheelEvent *  qp = RawPtr_to(QWheelEvent *, sfp[0]);
	if (qp) {
		const QPoint ret_v = qp->globalPos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWheelEvent.globalX();
KMETHOD QWheelEvent_globalX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWheelEvent *  qp = RawPtr_to(QWheelEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->globalX();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QWheelEvent.globalY();
KMETHOD QWheelEvent_globalY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWheelEvent *  qp = RawPtr_to(QWheelEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->globalY();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QWheelEvent.orientation();
KMETHOD QWheelEvent_orientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWheelEvent *  qp = RawPtr_to(QWheelEvent *, sfp[0]);
	if (qp) {
		Qt::Orientation ret_v = qp->orientation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPoint QWheelEvent.pos();
KMETHOD QWheelEvent_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWheelEvent *  qp = RawPtr_to(QWheelEvent *, sfp[0]);
	if (qp) {
		const QPoint ret_v = qp->pos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWheelEvent.x();
KMETHOD QWheelEvent_x(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWheelEvent *  qp = RawPtr_to(QWheelEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->x();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QWheelEvent.y();
KMETHOD QWheelEvent_y(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWheelEvent *  qp = RawPtr_to(QWheelEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->y();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQWheelEvent::DummyQWheelEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQWheelEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWheelEvent::self = ptr;
	DummyQInputEvent::setSelf(ptr);
}

bool DummyQWheelEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQInputEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQWheelEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWheelEvent::event_map->bigin();
	if ((itr = DummyQWheelEvent::event_map->find(str)) == DummyQWheelEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQInputEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWheelEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWheelEvent::slot_map->bigin();
	if ((itr = DummyQWheelEvent::slot_map->find(str)) == DummyQWheelEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQInputEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQWheelEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQWheelEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQInputEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQWheelEvent::connection(QObject *o)
{
	QWheelEvent *p = dynamic_cast<QWheelEvent*>(o);
	if (p != NULL) {
	}
	DummyQInputEvent::connection(o);
}

KQWheelEvent::KQWheelEvent(const QPoint pos, int delta, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, Qt::Orientation orient) : QWheelEvent(pos, delta, buttons, modifiers, orient)
{
	self = NULL;
	dummy = new DummyQWheelEvent();
}

KMETHOD QWheelEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWheelEvent *qp = RawPtr_to(KQWheelEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWheelEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWheelEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWheelEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWheelEvent *qp = RawPtr_to(KQWheelEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWheelEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWheelEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWheelEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWheelEvent *qp = (KQWheelEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWheelEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQWheelEvent *qp = (KQWheelEvent *)p->rawptr;
//		KQWheelEvent *qp = static_cast<KQWheelEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWheelEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWheelEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQWheelEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWheelEvent";
	cdef->free = QWheelEvent_free;
	cdef->reftrace = QWheelEvent_reftrace;
	cdef->compareTo = QWheelEvent_compareTo;
}


