//QSignalTransition QSignalTransition.new(QState sourceState);
KMETHOD QSignalTransition_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState*  sourceState = RawPtr_to(QState*, sfp[1]);
	KQSignalTransition *ret_v = new KQSignalTransition(sourceState);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QSignalTransition QSignalTransition.new(QObject sender, String signal, QState sourceState);
KMETHOD QSignalTransition_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  sender = RawPtr_to(QObject*, sfp[1]);
	const char*  signal = RawPtr_to(const char*, sfp[2]);
	QState*  sourceState = RawPtr_to(QState*, sfp[3]);
	KQSignalTransition *ret_v = new KQSignalTransition(sender, signal, sourceState);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QObject QSignalTransition.getSenderObject();
KMETHOD QSignalTransition_getSenderObject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSignalTransition *  qp = RawPtr_to(QSignalTransition *, sfp[0]);
	if (qp != NULL) {
		QObject* ret_v = qp->senderObject();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QSignalTransition.setSenderObject(QObject sender);
KMETHOD QSignalTransition_setSenderObject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSignalTransition *  qp = RawPtr_to(QSignalTransition *, sfp[0]);
	if (qp != NULL) {
		QObject*  sender = RawPtr_to(QObject*, sfp[1]);
		qp->setSenderObject(sender);
	}
	RETURNvoid_();
}

//void QSignalTransition.setSignal(QByteArray signal);
KMETHOD QSignalTransition_setSignal(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSignalTransition *  qp = RawPtr_to(QSignalTransition *, sfp[0]);
	if (qp != NULL) {
		const QByteArray  signal = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->setSignal(signal);
	}
	RETURNvoid_();
}

//QByteArray QSignalTransition.getSignal();
KMETHOD QSignalTransition_getSignal(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSignalTransition *  qp = RawPtr_to(QSignalTransition *, sfp[0]);
	if (qp != NULL) {
		QByteArray ret_v = qp->signal();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQSignalTransition::DummyQSignalTransition()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSignalTransition::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSignalTransition::self = ptr;
	DummyQAbstractTransition::setSelf(ptr);
}

bool DummyQSignalTransition::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractTransition::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQSignalTransition::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSignalTransition::event_map->bigin();
	if ((itr = DummyQSignalTransition::event_map->find(str)) == DummyQSignalTransition::event_map->end()) {
		bool ret;
		ret = DummyQAbstractTransition::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSignalTransition::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSignalTransition::slot_map->bigin();
	if ((itr = DummyQSignalTransition::event_map->find(str)) == DummyQSignalTransition::slot_map->end()) {
		bool ret;
		ret = DummyQAbstractTransition::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQSignalTransition::KQSignalTransition(QState* sourceState) : QSignalTransition(sourceState)
{
	self = NULL;
}

KMETHOD QSignalTransition_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSignalTransition *qp = RawPtr_to(KQSignalTransition *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSignalTransition]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQSignalTransition::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSignalTransition]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QSignalTransition_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSignalTransition *qp = RawPtr_to(KQSignalTransition *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSignalTransition]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQSignalTransition::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSignalTransition]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSignalTransition_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSignalTransition *qp = (KQSignalTransition *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSignalTransition_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQSignalTransition *qp = (KQSignalTransition *)p->rawptr;
		(void)qp;
	}
}

static int QSignalTransition_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQSignalTransition::event(QEvent *event)
{
	if (!DummyQSignalTransition::eventDispatcher(event)) {
		QSignalTransition::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQSignalTransition(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSignalTransition";
	cdef->free = QSignalTransition_free;
	cdef->reftrace = QSignalTransition_reftrace;
	cdef->compareTo = QSignalTransition_compareTo;
}


