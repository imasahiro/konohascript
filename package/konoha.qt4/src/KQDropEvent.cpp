//@Virtual @Override QByteArray QDropEvent.encodedData(String fmt);
KMETHOD QDropEvent_encodedData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp) {
		const char*  format = RawPtr_to(const char*, sfp[1]);
		QByteArray ret_v = qp->encodedData(format);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override String QDropEvent.format(int n);
KMETHOD QDropEvent_format(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp) {
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
	if (qp) {
		const char*  mimeType = RawPtr_to(const char*, sfp[1]);
		bool ret_v = qp->provides(mimeType);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QDropEvent QDropEvent.new(QPoint pos, QtDropActions actions, QMimeData data, QtMouseButtons buttons, QtKeyboardModifiers modifiers, int type);
KMETHOD QDropEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
	initFlag(actions, Qt::DropActions, sfp[2]);
	const QMimeData*  data = RawPtr_to(const QMimeData*, sfp[3]);
	initFlag(buttons, Qt::MouseButtons, sfp[4]);
	initFlag(modifiers, Qt::KeyboardModifiers, sfp[5]);
	QDropEvent::Type type = Int_to(QDropEvent::Type, sfp[6]);
	KQDropEvent *ret_v = new KQDropEvent(pos, actions, data, buttons, modifiers, type);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QDropEvent.acceptProposedAction();
KMETHOD QDropEvent_acceptProposedAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp) {
		qp->acceptProposedAction();
	}
	RETURNvoid_();
}

//int QDropEvent.getDropAction();
KMETHOD QDropEvent_getDropAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp) {
		Qt::DropAction ret_v = qp->dropAction();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QtKeyboardModifiers QDropEvent.keyboardModifiers();
KMETHOD QDropEvent_keyboardModifiers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp) {
		Qt::KeyboardModifiers ret_v = qp->keyboardModifiers();
		Qt::KeyboardModifiers *ret_v_ = new Qt::KeyboardModifiers(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QMimeData QDropEvent.mimeData();
KMETHOD QDropEvent_mimeData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp) {
		const QMimeData* ret_v = qp->mimeData();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMimeData*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QtMouseButtons QDropEvent.mouseButtons();
KMETHOD QDropEvent_mouseButtons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp) {
		Qt::MouseButtons ret_v = qp->mouseButtons();
		Qt::MouseButtons *ret_v_ = new Qt::MouseButtons(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QDropEvent.pos();
KMETHOD QDropEvent_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp) {
		const QPoint ret_v = qp->pos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QtDropActions QDropEvent.possibleActions();
KMETHOD QDropEvent_possibleActions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp) {
		Qt::DropActions ret_v = qp->possibleActions();
		Qt::DropActions *ret_v_ = new Qt::DropActions(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDropEvent.proposedAction();
KMETHOD QDropEvent_proposedAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDropEvent *  qp = RawPtr_to(QDropEvent *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		QWidget* ret_v = qp->source();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQDropEvent::DummyQDropEvent()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQDropEvent::~DummyQDropEvent()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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
		bool ret = false;
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
	if ((itr = DummyQDropEvent::slot_map->find(str)) == DummyQDropEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQDropEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQDropEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQDropEvent::connection(QObject *o)
{
	QDropEvent *p = dynamic_cast<QDropEvent*>(o);
	if (p != NULL) {
	}
	DummyQEvent::connection(o);
}

KQDropEvent::KQDropEvent(const QPoint pos, Qt::DropActions actions, const QMimeData* data, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, QDropEvent::Type type) : QDropEvent(pos, actions, data, buttons, modifiers, type)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQDropEvent();
}

KQDropEvent::~KQDropEvent()
{
	delete dummy;
	dummy = NULL;
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDropEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDropEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQDropEvent *qp = (KQDropEvent *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QDropEvent*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QDropEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQDropEvent *qp = (KQDropEvent *)p->rawptr;
		KQDropEvent *qp = static_cast<KQDropEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QDropEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQDropEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQDropEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDropEvent";
	cdef->free = QDropEvent_free;
	cdef->reftrace = QDropEvent_reftrace;
	cdef->compareTo = QDropEvent_compareTo;
}


