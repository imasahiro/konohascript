//QDragMoveEvent QDragMoveEvent.new(QPoint pos, int actions, QMimeData data, int buttons, int modifiers, int type);
KMETHOD QDragMoveEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
	Qt::DropActions actions = Int_to(Qt::DropActions, sfp[2]);
	const QMimeData*  data = RawPtr_to(const QMimeData*, sfp[3]);
	Qt::MouseButtons buttons = Int_to(Qt::MouseButtons, sfp[4]);
	Qt::KeyboardModifiers modifiers = Int_to(Qt::KeyboardModifiers, sfp[5]);
	QDragMoveEvent::Type type = Int_to(QDragMoveEvent::Type, sfp[6]);
	KQDragMoveEvent *ret_v = new KQDragMoveEvent(pos, actions, data, buttons, modifiers, type);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

////void QDragMoveEvent.accept(QRect rectangle);
KMETHOD QDragMoveEvent_accept(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDragMoveEvent *  qp = RawPtr_to(QDragMoveEvent *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		qp->accept(rectangle);
	}
	RETURNvoid_();
}

/*
////void QDragMoveEvent.accept();
KMETHOD QDragMoveEvent_accept(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDragMoveEvent *  qp = RawPtr_to(QDragMoveEvent *, sfp[0]);
	if (qp != NULL) {
		qp->accept();
	}
	RETURNvoid_();
}
*/
//QRect QDragMoveEvent.answerRect();
KMETHOD QDragMoveEvent_answerRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDragMoveEvent *  qp = RawPtr_to(QDragMoveEvent *, sfp[0]);
	if (qp != NULL) {
		QRect ret_v = qp->answerRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

////void QDragMoveEvent.ignore(QRect rectangle);
KMETHOD QDragMoveEvent_ignore(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDragMoveEvent *  qp = RawPtr_to(QDragMoveEvent *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		qp->ignore(rectangle);
	}
	RETURNvoid_();
}

/*
////void QDragMoveEvent.ignore();
KMETHOD QDragMoveEvent_ignore(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDragMoveEvent *  qp = RawPtr_to(QDragMoveEvent *, sfp[0]);
	if (qp != NULL) {
		qp->ignore();
	}
	RETURNvoid_();
}
*/

DummyQDragMoveEvent::DummyQDragMoveEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQDragMoveEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDragMoveEvent::self = ptr;
	DummyQDropEvent::setSelf(ptr);
}

bool DummyQDragMoveEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQDropEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQDragMoveEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDragMoveEvent::event_map->bigin();
	if ((itr = DummyQDragMoveEvent::event_map->find(str)) == DummyQDragMoveEvent::event_map->end()) {
		bool ret;
		ret = DummyQDropEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDragMoveEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDragMoveEvent::slot_map->bigin();
	if ((itr = DummyQDragMoveEvent::event_map->find(str)) == DummyQDragMoveEvent::slot_map->end()) {
		bool ret;
		ret = DummyQDropEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQDragMoveEvent::KQDragMoveEvent(const QPoint pos, Qt::DropActions actions, const QMimeData* data, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, QDragMoveEvent::Type type) : QDragMoveEvent(pos, actions, data, buttons, modifiers, type)
{
	self = NULL;
}

KMETHOD QDragMoveEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDragMoveEvent *qp = RawPtr_to(KQDragMoveEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDragMoveEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQDragMoveEvent::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDragMoveEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QDragMoveEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDragMoveEvent *qp = RawPtr_to(KQDragMoveEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDragMoveEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQDragMoveEvent::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDragMoveEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDragMoveEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDragMoveEvent *qp = (KQDragMoveEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDragMoveEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQDragMoveEvent *qp = (KQDragMoveEvent *)p->rawptr;
		(void)qp;
	}
}

static int QDragMoveEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQDragMoveEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDragMoveEvent";
	cdef->free = QDragMoveEvent_free;
	cdef->reftrace = QDragMoveEvent_reftrace;
	cdef->compareTo = QDragMoveEvent_compareTo;
}


