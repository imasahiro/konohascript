//QEventTransition QEventTransition.new(QState sourceState);
KMETHOD QEventTransition_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState*  sourceState = RawPtr_to(QState*, sfp[1]);
	KQEventTransition *ret_v = new KQEventTransition(sourceState);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QEventTransition QEventTransition.new(QObject object, int type, QState sourceState);
KMETHOD QEventTransition_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  object = RawPtr_to(QObject*, sfp[1]);
	QEvent::Type type = Int_to(QEvent::Type, sfp[2]);
	QState*  sourceState = RawPtr_to(QState*, sfp[3]);
	KQEventTransition *ret_v = new KQEventTransition(object, type, sourceState);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QObject QEventTransition.getEventSource();
KMETHOD QEventTransition_getEventSource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEventTransition *  qp = RawPtr_to(QEventTransition *, sfp[0]);
	if (qp) {
		QObject* ret_v = qp->eventSource();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QEventTransition.getEventType();
KMETHOD QEventTransition_getEventType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEventTransition *  qp = RawPtr_to(QEventTransition *, sfp[0]);
	if (qp) {
		QEvent::Type ret_v = qp->eventType();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QEventTransition.setEventSource(QObject object);
KMETHOD QEventTransition_setEventSource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEventTransition *  qp = RawPtr_to(QEventTransition *, sfp[0]);
	if (qp) {
		QObject*  object = RawPtr_to(QObject*, sfp[1]);
		qp->setEventSource(object);
	}
	RETURNvoid_();
}

//void QEventTransition.setEventType(int type);
KMETHOD QEventTransition_setEventType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEventTransition *  qp = RawPtr_to(QEventTransition *, sfp[0]);
	if (qp) {
		QEvent::Type type = Int_to(QEvent::Type, sfp[1]);
		qp->setEventType(type);
	}
	RETURNvoid_();
}


DummyQEventTransition::DummyQEventTransition()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQEventTransition::setSelf(knh_RawPtr_t *ptr)
{
	DummyQEventTransition::self = ptr;
	DummyQAbstractTransition::setSelf(ptr);
}

bool DummyQEventTransition::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractTransition::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQEventTransition::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQEventTransition::event_map->bigin();
	if ((itr = DummyQEventTransition::event_map->find(str)) == DummyQEventTransition::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractTransition::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQEventTransition::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQEventTransition::slot_map->bigin();
	if ((itr = DummyQEventTransition::slot_map->find(str)) == DummyQEventTransition::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractTransition::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQEventTransition::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQAbstractTransition::reftrace(ctx, p, tail_);
}

void DummyQEventTransition::connection(QObject *o)
{
	QEventTransition *p = dynamic_cast<QEventTransition*>(o);
	if (p != NULL) {
	}
	DummyQAbstractTransition::connection(o);
}

KQEventTransition::KQEventTransition(QState* sourceState) : QEventTransition(sourceState)
{
	self = NULL;
	dummy = new DummyQEventTransition();
	dummy->connection((QObject*)this);
}

KMETHOD QEventTransition_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQEventTransition *qp = RawPtr_to(KQEventTransition *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QEventTransition]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QEventTransition]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QEventTransition_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQEventTransition *qp = RawPtr_to(KQEventTransition *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QEventTransition]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QEventTransition]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QEventTransition_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQEventTransition *qp = (KQEventTransition *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QEventTransition_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQEventTransition *qp = (KQEventTransition *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QEventTransition_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQEventTransition::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQEventTransition::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QEventTransition::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQEventTransition(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QEventTransition";
	cdef->free = QEventTransition_free;
	cdef->reftrace = QEventTransition_reftrace;
	cdef->compareTo = QEventTransition_compareTo;
}


