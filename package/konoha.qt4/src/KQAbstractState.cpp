//QStateMachine QAbstractState.machine();
KMETHOD QAbstractState_machine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractState *  qp = RawPtr_to(QAbstractState *, sfp[0]);
	if (qp != NULL) {
		QStateMachine* ret_v = qp->machine();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QStateMachine*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QState QAbstractState.parentState();
KMETHOD QAbstractState_parentState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractState *  qp = RawPtr_to(QAbstractState *, sfp[0]);
	if (qp != NULL) {
		QState* ret_v = qp->parentState();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QState*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQAbstractState::DummyQAbstractState()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQAbstractState::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractState::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQAbstractState::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractState::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractState::event_map->bigin();
	if ((itr = DummyQAbstractState::event_map->find(str)) == DummyQAbstractState::event_map->end()) {
		bool ret;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractState::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractState::slot_map->bigin();
	if ((itr = DummyQAbstractState::event_map->find(str)) == DummyQAbstractState::slot_map->end()) {
		bool ret;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQAbstractState::KQAbstractState(QState* parent) : QAbstractState(parent)
{
	self = NULL;
}

KMETHOD QAbstractState_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractState *qp = RawPtr_to(KQAbstractState *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractState]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQAbstractState::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractState]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QAbstractState_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractState *qp = RawPtr_to(KQAbstractState *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractState]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQAbstractState::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractState]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractState_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAbstractState *qp = (KQAbstractState *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAbstractState_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQAbstractState *qp = (KQAbstractState *)p->rawptr;
		(void)qp;
	}
}

static int QAbstractState_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQAbstractState::event(QEvent *event)
{
	if (!DummyQAbstractState::eventDispatcher(event)) {
		QAbstractState::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQAbstractState(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractState";
	cdef->free = QAbstractState_free;
	cdef->reftrace = QAbstractState_reftrace;
	cdef->compareTo = QAbstractState_compareTo;
}


