//QMouseEvent QMouseEvent.new(int type, QPoint position, int button, QtMouseButtons buttons, QtKeyboardModifiers modifiers);
KMETHOD QMouseEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMouseEvent::Type type = Int_to(QMouseEvent::Type, sfp[1]);
	const QPoint  position = *RawPtr_to(const QPoint *, sfp[2]);
	Qt::MouseButton button = Int_to(Qt::MouseButton, sfp[3]);
	initFlag(buttons, Qt::MouseButtons, sfp[4]);
	initFlag(modifiers, Qt::KeyboardModifiers, sfp[5]);
	KQMouseEvent *ret_v = new KQMouseEvent(type, position, button, buttons, modifiers);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QMouseEvent QMouseEvent.new(int type, QPoint pos, QPoint globalPos, int button, QtMouseButtons buttons, QtKeyboardModifiers modifiers);
KMETHOD QMouseEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMouseEvent::Type type = Int_to(QMouseEvent::Type, sfp[1]);
	const QPoint  pos = *RawPtr_to(const QPoint *, sfp[2]);
	const QPoint  globalPos = *RawPtr_to(const QPoint *, sfp[3]);
	Qt::MouseButton button = Int_to(Qt::MouseButton, sfp[4]);
	initFlag(buttons, Qt::MouseButtons, sfp[5]);
	initFlag(modifiers, Qt::KeyboardModifiers, sfp[6]);
	KQMouseEvent *ret_v = new KQMouseEvent(type, pos, globalPos, button, buttons, modifiers);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QMouseEvent.button();
KMETHOD QMouseEvent_button(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMouseEvent *  qp = RawPtr_to(QMouseEvent *, sfp[0]);
	if (qp) {
		Qt::MouseButton ret_v = qp->button();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QtMouseButtons QMouseEvent.buttons();
KMETHOD QMouseEvent_buttons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMouseEvent *  qp = RawPtr_to(QMouseEvent *, sfp[0]);
	if (qp) {
		Qt::MouseButtons ret_v = qp->buttons();
		Qt::MouseButtons *ret_v_ = new Qt::MouseButtons(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QMouseEvent.globalPos();
KMETHOD QMouseEvent_globalPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMouseEvent *  qp = RawPtr_to(QMouseEvent *, sfp[0]);
	if (qp) {
		const QPoint ret_v = qp->globalPos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMouseEvent.globalX();
KMETHOD QMouseEvent_globalX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMouseEvent *  qp = RawPtr_to(QMouseEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->globalX();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMouseEvent.globalY();
KMETHOD QMouseEvent_globalY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMouseEvent *  qp = RawPtr_to(QMouseEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->globalY();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPoint QMouseEvent.pos();
KMETHOD QMouseEvent_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMouseEvent *  qp = RawPtr_to(QMouseEvent *, sfp[0]);
	if (qp) {
		const QPoint ret_v = qp->pos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QMouseEvent.posF();
KMETHOD QMouseEvent_posF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMouseEvent *  qp = RawPtr_to(QMouseEvent *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->posF();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMouseEvent.x();
KMETHOD QMouseEvent_x(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMouseEvent *  qp = RawPtr_to(QMouseEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->x();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMouseEvent.y();
KMETHOD QMouseEvent_y(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMouseEvent *  qp = RawPtr_to(QMouseEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->y();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQMouseEvent::DummyQMouseEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQMouseEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMouseEvent::self = ptr;
	DummyQInputEvent::setSelf(ptr);
}

bool DummyQMouseEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQInputEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQMouseEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMouseEvent::event_map->bigin();
	if ((itr = DummyQMouseEvent::event_map->find(str)) == DummyQMouseEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQInputEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMouseEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMouseEvent::slot_map->bigin();
	if ((itr = DummyQMouseEvent::slot_map->find(str)) == DummyQMouseEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQInputEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQMouseEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQInputEvent::reftrace(ctx, p, tail_);
}

void DummyQMouseEvent::connection(QObject *o)
{
	QMouseEvent *p = dynamic_cast<QMouseEvent*>(o);
	if (p != NULL) {
	}
	DummyQInputEvent::connection(o);
}

KQMouseEvent::KQMouseEvent(QMouseEvent::Type type, const QPoint position, Qt::MouseButton button, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers) : QMouseEvent(type, position, button, buttons, modifiers)
{
	self = NULL;
	dummy = new DummyQMouseEvent();
}

KMETHOD QMouseEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMouseEvent *qp = RawPtr_to(KQMouseEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMouseEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMouseEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QMouseEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMouseEvent *qp = RawPtr_to(KQMouseEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMouseEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMouseEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMouseEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMouseEvent *qp = (KQMouseEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMouseEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQMouseEvent *qp = (KQMouseEvent *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QMouseEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMouseEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQMouseEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMouseEvent";
	cdef->free = QMouseEvent_free;
	cdef->reftrace = QMouseEvent_reftrace;
	cdef->compareTo = QMouseEvent_compareTo;
}


