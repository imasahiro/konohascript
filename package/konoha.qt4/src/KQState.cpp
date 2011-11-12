//QState QState.new(QState parent);
KMETHOD QState_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState*  parent = RawPtr_to(QState*, sfp[1]);
	KQState *ret_v = new KQState(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
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
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QState.addTransition(QAbstractTransition transition);
KMETHOD QState_addTransition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState *  qp = RawPtr_to(QState *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		QList<QAbstractTransition*> ret_v = qp->transitions();
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
	finished_func = NULL;
	properties_assigned_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("finished", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("properties-assigned", NULL));
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

bool DummyQState::finishedSlot()
{
	if (finished_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, finished_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQState::propertiesAssignedSlot()
{
	if (properties_assigned_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, properties_assigned_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQState::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQState::event_map->bigin();
	if ((itr = DummyQState::event_map->find(str)) == DummyQState::event_map->end()) {
		bool ret = false;
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
	if ((itr = DummyQState::slot_map->find(str)) == DummyQState::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractState::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		finished_func = (*slot_map)["finished"];
		properties_assigned_func = (*slot_map)["properties-assigned"];
		return true;
	}
}

knh_Object_t** DummyQState::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQState::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, finished_func);
	KNH_ADDNNREF(ctx, properties_assigned_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQAbstractState::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQState::connection(QObject *o)
{
	QState *p = dynamic_cast<QState*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(finished()), this, SLOT(finishedSlot()));
		connect(p, SIGNAL(propertiesAssigned()), this, SLOT(propertiesAssignedSlot()));
	}
	DummyQAbstractState::connection(o);
}

KQState::KQState(QState* parent) : QState(parent)
{
	self = NULL;
	dummy = new DummyQState();
	dummy->connection((QObject*)this);
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
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
	if (p->rawptr != NULL) {
		KQState *qp = (KQState *)p->rawptr;
//		KQState *qp = static_cast<KQState*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QState_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQState::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQState::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QState::event(event);
		return false;
	}
//	QState::event(event);
	return true;
}

static knh_IntData_t QStateConstInt[] = {
	{"ExclusiveStates", QState::ExclusiveStates},
	{"ParallelStates", QState::ParallelStates},
	{NULL, 0}
};

DEFAPI(void) constQState(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStateConstInt);
}


DEFAPI(void) defQState(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QState";
	cdef->free = QState_free;
	cdef->reftrace = QState_reftrace;
	cdef->compareTo = QState_compareTo;
}


