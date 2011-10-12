//QState QState.new(QState parent);
KMETHOD QState_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState*  parent = RawPtr_to(QState*, sfp[1]);
	KQState *ret_v = new KQState(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QState QState.new(int childMode, QState parent);
KMETHOD QState_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState::ChildMode childMode = Int_to(QState::ChildMode, sfp[1]);
	QState*  parent = RawPtr_to(QState*, sfp[2]);
	KQState *ret_v = new KQState(childMode, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QState.addTransition(QAbstractTransition transition);
KMETHOD QState_addTransition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState *  qp = RawPtr_to(QState *, sfp[0]);
	if (qp != NULL) {
		QAbstractTransition*  transition = RawPtr_to(QAbstractTransition*, sfp[1]);
		qp->addTransition(transition);
	}
	RETURNvoid_();
}

/*
//QSignalTransition QState.addTransition(QObject sender, String signal, QAbstractState target);
KMETHOD QState_addTransition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState *  qp = RawPtr_to(QState *, sfp[0]);
	if (qp != NULL) {
		QObject*  sender = RawPtr_to(QObject*, sfp[1]);
		const char*  signal = RawPtr_to(const char*, sfp[2]);
		QAbstractState*  target = RawPtr_to(QAbstractState*, sfp[3]);
		QSignalTransition* ret_v = qp->addTransition(sender, signal, target);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QSignalTransition*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QAbstractTransition QState.addTransition(QAbstractState target);
KMETHOD QState_addTransition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState *  qp = RawPtr_to(QState *, sfp[0]);
	if (qp != NULL) {
		QAbstractState*  target = RawPtr_to(QAbstractState*, sfp[1]);
		QAbstractTransition* ret_v = qp->addTransition(target);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractTransition*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//void QState.assignProperty(QObject object, String name, QVariant value);
KMETHOD QState_assignProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState *  qp = RawPtr_to(QState *, sfp[0]);
	if (qp != NULL) {
		QObject*  object = RawPtr_to(QObject*, sfp[1]);
		const char*  name = RawPtr_to(const char*, sfp[2]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[3]);
		qp->assignProperty(object, name, value);
	}
	RETURNvoid_();
}

//int QState.getChildMode();
KMETHOD QState_getChildMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState *  qp = RawPtr_to(QState *, sfp[0]);
	if (qp != NULL) {
		QState::ChildMode ret_v = qp->childMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QAbstractState QState.getErrorState();
KMETHOD QState_getErrorState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState *  qp = RawPtr_to(QState *, sfp[0]);
	if (qp != NULL) {
		QAbstractState* ret_v = qp->errorState();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractState*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAbstractState QState.getInitialState();
KMETHOD QState_getInitialState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState *  qp = RawPtr_to(QState *, sfp[0]);
	if (qp != NULL) {
		QAbstractState* ret_v = qp->initialState();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractState*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QState.removeTransition(QAbstractTransition transition);
KMETHOD QState_removeTransition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState *  qp = RawPtr_to(QState *, sfp[0]);
	if (qp != NULL) {
		QAbstractTransition*  transition = RawPtr_to(QAbstractTransition*, sfp[1]);
		qp->removeTransition(transition);
	}
	RETURNvoid_();
}

//void QState.setChildMode(int mode);
KMETHOD QState_setChildMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState *  qp = RawPtr_to(QState *, sfp[0]);
	if (qp != NULL) {
		QState::ChildMode mode = Int_to(QState::ChildMode, sfp[1]);
		qp->setChildMode(mode);
	}
	RETURNvoid_();
}

//void QState.setErrorState(QAbstractState state);
KMETHOD QState_setErrorState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState *  qp = RawPtr_to(QState *, sfp[0]);
	if (qp != NULL) {
		QAbstractState*  state = RawPtr_to(QAbstractState*, sfp[1]);
		qp->setErrorState(state);
	}
	RETURNvoid_();
}

//void QState.setInitialState(QAbstractState state);
KMETHOD QState_setInitialState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState *  qp = RawPtr_to(QState *, sfp[0]);
	if (qp != NULL) {
		QAbstractState*  state = RawPtr_to(QAbstractState*, sfp[1]);
		qp->setInitialState(state);
	}
	RETURNvoid_();
}

//Array<QAbstractTransition> QState.transitions();
KMETHOD QState_transitions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState *  qp = RawPtr_to(QState *, sfp[0]);
	if (qp != NULL) {
		QList<QAbstractTransition*>ret_v = qp->transitions();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QAbstractTransition"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	


DummyQState::DummyQState()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQState::setSelf(knh_RawPtr_t *ptr)
{
	DummyQState::self = ptr;
	DummyQAbstractState::setSelf(ptr);
}

bool DummyQState::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractState::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQState::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQState::event_map->bigin();
	if ((itr = DummyQState::event_map->find(str)) == DummyQState::event_map->end()) {
		bool ret;
		ret = DummyQAbstractState::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQState::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQState::slot_map->bigin();
	if ((itr = DummyQState::event_map->find(str)) == DummyQState::slot_map->end()) {
		bool ret;
		ret = DummyQAbstractState::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQState::KQState(QState* parent) : QState(parent)
{
	self = NULL;
}

KMETHOD QState_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQState *qp = RawPtr_to(KQState *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QState]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQState::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QState]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QState_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQState *qp = RawPtr_to(KQState *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QState]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQState::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QState]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QState_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQState *qp = (KQState *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QState_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQState *qp = (KQState *)p->rawptr;
		(void)qp;
	}
}

static int QState_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQState::event(QEvent *event)
{
	if (!DummyQState::eventDispatcher(event)) {
		QState::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQState(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QState";
	cdef->free = QState_free;
	cdef->reftrace = QState_reftrace;
	cdef->compareTo = QState_compareTo;
}

static knh_IntData_t QStateConstInt[] = {
	{"ExclusiveStates", QState::ExclusiveStates},
	{"ParallelStates", QState::ParallelStates},
	{NULL, 0}
};

DEFAPI(void) constQState(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStateConstInt);
}

