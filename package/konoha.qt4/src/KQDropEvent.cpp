//@Virtual @Override QByteArray QDropEvent.encodedData(String fmt);
KMETHOD QDropEvent_encodedData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp != NULL) {
		const char*  format = RawPtr_to(const char*, sfp[1]);
		QByteArray ret_v = qp->encodedData(format);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override String QDropEvent.fmt(int n);
KMETHOD QDropEvent_format(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp != NULL) {
		int n = Int_to(int, sfp[1]);
		const char* ret_v = qp->format(n);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (char*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QDropEvent.provides(String mimeType);
KMETHOD QDropEvent_provides(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp != NULL) {
		const char*  mimeType = RawPtr_to(const char*, sfp[1]);
		bool ret_v = qp->provides(mimeType);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QDropEvent QDropEvent.new(QPoint pos, int actions, QMimeData data, int buttons, int modifiers, int type);
KMETHOD QDropEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
	Qt::DropActions actions = Int_to(Qt::DropActions, sfp[2]);
	const QMimeData*  data = RawPtr_to(const QMimeData*, sfp[3]);
	Qt::MouseButtons buttons = Int_to(Qt::MouseButtons, sfp[4]);
	Qt::KeyboardModifiers modifiers = Int_to(Qt::KeyboardModifiers, sfp[5]);
	QDropEvent::Type type = Int_to(QDropEvent::Type, sfp[6]);
	KQDropEvent *ret_v = new KQDropEvent(pos, actions, data, buttons, modifiers, type);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

////void QDropEvent.acceptProposedAction();
KMETHOD QDropEvent_acceptProposedAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp != NULL) {
		qp->acceptProposedAction();
	}
	RETURNvoid_();
}

//int QDropEvent.getDropAction();
KMETHOD QDropEvent_getDropAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp != NULL) {
		Qt::DropAction ret_v = qp->dropAction();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QDropEvent.keyboardModifiers();
KMETHOD QDropEvent_keyboardModifiers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp != NULL) {
		Qt::KeyboardModifiers ret_v = qp->keyboardModifiers();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QMimeData QDropEvent.mimeData();
KMETHOD QDropEvent_mimeData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp != NULL) {
		const QMimeData* ret_v = qp->mimeData();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMimeData*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDropEvent.mouseButtons();
KMETHOD QDropEvent_mouseButtons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp != NULL) {
		Qt::MouseButtons ret_v = qp->mouseButtons();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPoint QDropEvent.pos();
KMETHOD QDropEvent_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp != NULL) {
		const QPoint ret_v = qp->pos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDropEvent.possibleActions();
KMETHOD QDropEvent_possibleActions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp != NULL) {
		Qt::DropActions ret_v = qp->possibleActions();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QDropEvent.proposedAction();
KMETHOD QDropEvent_proposedAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp != NULL) {
		Qt::DropAction ret_v = qp->proposedAction();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QDropEvent.setDropAction(int action);
KMETHOD QDropEvent_setDropAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp != NULL) {
		Qt::DropAction action = Int_to(Qt::DropAction, sfp[1]);
		qp->setDropAction(action);
	}
	RETURNvoid_();
}

//QWidget QDropEvent.source();
KMETHOD QDropEvent_source(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->source();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQDropEvent::DummyQDropEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQDropEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDropEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQDropEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQDropEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDropEvent::event_map->bigin();
	if ((itr = DummyQDropEvent::event_map->find(str)) == DummyQDropEvent::event_map->end()) {
		bool ret;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDropEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDropEvent::slot_map->bigin();
	if ((itr = DummyQDropEvent::event_map->find(str)) == DummyQDropEvent::slot_map->end()) {
		bool ret;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQDropEvent::KQDropEvent(const QPoint pos, Qt::DropActions actions, const QMimeData* data, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, QDropEvent::Type type) : QDropEvent(pos, actions, data, buttons, modifiers, type)
{
	self = NULL;
}

KMETHOD QDropEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDropEvent *qp = RawPtr_to(KQDropEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDropEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQDropEvent::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDropEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QDropEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDropEvent *qp = RawPtr_to(KQDropEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDropEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQDropEvent::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDropEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDropEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDropEvent *qp = (KQDropEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDropEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQDropEvent *qp = (KQDropEvent *)p->rawptr;
		(void)qp;
	}
}

static int QDropEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQDropEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDropEvent";
	cdef->free = QDropEvent_free;
	cdef->reftrace = QDropEvent_reftrace;
	cdef->compareTo = QDropEvent_compareTo;
}


