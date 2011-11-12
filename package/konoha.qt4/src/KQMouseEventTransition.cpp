//QMouseEventTransition QMouseEventTransition.new(QState sourceState);
KMETHOD QMouseEventTransition_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState*  sourceState = RawPtr_to(QState*, sfp[1]);
	KQMouseEventTransition *ret_v = new KQMouseEventTransition(sourceState);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QMouseEventTransition QMouseEventTransition.new(QObject object, int type, int button, QState sourceState);
KMETHOD QMouseEventTransition_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  object = RawPtr_to(QObject*, sfp[1]);
	QEvent::Type type = Int_to(QEvent::Type, sfp[2]);
	Qt::MouseButton button = Int_to(Qt::MouseButton, sfp[3]);
	QState*  sourceState = RawPtr_to(QState*, sfp[4]);
	KQMouseEventTransition *ret_v = new KQMouseEventTransition(object, type, button, sourceState);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QMouseEventTransition.getButton();
KMETHOD QMouseEventTransition_getButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMouseEventTransition *  qp = RawPtr_to(QMouseEventTransition *, sfp[0]);
	if (qp) {
		Qt::MouseButton ret_v = qp->button();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPainterPath QMouseEventTransition.getHitTestPath();
KMETHOD QMouseEventTransition_getHitTestPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMouseEventTransition *  qp = RawPtr_to(QMouseEventTransition *, sfp[0]);
	if (qp) {
		QPainterPath ret_v = qp->hitTestPath();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QtKeyboardModifiers QMouseEventTransition.getModifierMask();
KMETHOD QMouseEventTransition_getModifierMask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMouseEventTransition *  qp = RawPtr_to(QMouseEventTransition *, sfp[0]);
	if (qp) {
		Qt::KeyboardModifiers ret_v = qp->modifierMask();
		Qt::KeyboardModifiers *ret_v_ = new Qt::KeyboardModifiers(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QMouseEventTransition.setButton(int button);
KMETHOD QMouseEventTransition_setButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMouseEventTransition *  qp = RawPtr_to(QMouseEventTransition *, sfp[0]);
	if (qp) {
		Qt::MouseButton button = Int_to(Qt::MouseButton, sfp[1]);
		qp->setButton(button);
	}
	RETURNvoid_();
}

//void QMouseEventTransition.setHitTestPath(QPainterPath path);
KMETHOD QMouseEventTransition_setHitTestPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMouseEventTransition *  qp = RawPtr_to(QMouseEventTransition *, sfp[0]);
	if (qp) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		qp->setHitTestPath(path);
	}
	RETURNvoid_();
}

//void QMouseEventTransition.setModifierMask(QtKeyboardModifiers modifierMask);
KMETHOD QMouseEventTransition_setModifierMask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMouseEventTransition *  qp = RawPtr_to(QMouseEventTransition *, sfp[0]);
	if (qp) {
		initFlag(modifierMask, Qt::KeyboardModifiers, sfp[1]);
		qp->setModifierMask(modifierMask);
	}
	RETURNvoid_();
}


DummyQMouseEventTransition::DummyQMouseEventTransition()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQMouseEventTransition::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMouseEventTransition::self = ptr;
	DummyQEventTransition::setSelf(ptr);
}

bool DummyQMouseEventTransition::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEventTransition::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQMouseEventTransition::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMouseEventTransition::event_map->bigin();
	if ((itr = DummyQMouseEventTransition::event_map->find(str)) == DummyQMouseEventTransition::event_map->end()) {
		bool ret = false;
		ret = DummyQEventTransition::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMouseEventTransition::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMouseEventTransition::slot_map->bigin();
	if ((itr = DummyQMouseEventTransition::slot_map->find(str)) == DummyQMouseEventTransition::slot_map->end()) {
		bool ret = false;
		ret = DummyQEventTransition::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQMouseEventTransition::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQMouseEventTransition::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQEventTransition::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQMouseEventTransition::connection(QObject *o)
{
	QMouseEventTransition *p = dynamic_cast<QMouseEventTransition*>(o);
	if (p != NULL) {
	}
	DummyQEventTransition::connection(o);
}

KQMouseEventTransition::KQMouseEventTransition(QState* sourceState) : QMouseEventTransition(sourceState)
{
	self = NULL;
	dummy = new DummyQMouseEventTransition();
	dummy->connection((QObject*)this);
}

KMETHOD QMouseEventTransition_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMouseEventTransition *qp = RawPtr_to(KQMouseEventTransition *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMouseEventTransition]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMouseEventTransition]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QMouseEventTransition_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMouseEventTransition *qp = RawPtr_to(KQMouseEventTransition *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMouseEventTransition]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMouseEventTransition]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMouseEventTransition_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMouseEventTransition *qp = (KQMouseEventTransition *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMouseEventTransition_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQMouseEventTransition *qp = (KQMouseEventTransition *)p->rawptr;
//		KQMouseEventTransition *qp = static_cast<KQMouseEventTransition*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QMouseEventTransition_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMouseEventTransition::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQMouseEventTransition::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QMouseEventTransition::event(event);
		return false;
	}
//	QMouseEventTransition::event(event);
	return true;
}



DEFAPI(void) defQMouseEventTransition(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMouseEventTransition";
	cdef->free = QMouseEventTransition_free;
	cdef->reftrace = QMouseEventTransition_reftrace;
	cdef->compareTo = QMouseEventTransition_compareTo;
}


