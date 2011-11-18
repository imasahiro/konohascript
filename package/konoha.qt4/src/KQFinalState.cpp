//QFinalState QFinalState.new(QState parent);
KMETHOD QFinalState_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState*  parent = RawPtr_to(QState*, sfp[1]);
	KQFinalState *ret_v = new KQFinalState(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}


DummyQFinalState::DummyQFinalState()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQFinalState::~DummyQFinalState()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQFinalState::setSelf(knh_RawPtr_t *ptr)
{
	DummyQFinalState::self = ptr;
	DummyQAbstractState::setSelf(ptr);
}

bool DummyQFinalState::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractState::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQFinalState::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFinalState::event_map->bigin();
	if ((itr = DummyQFinalState::event_map->find(str)) == DummyQFinalState::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractState::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQFinalState::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFinalState::slot_map->bigin();
	if ((itr = DummyQFinalState::slot_map->find(str)) == DummyQFinalState::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractState::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQFinalState::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQFinalState::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQAbstractState::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQFinalState::connection(QObject *o)
{
	QFinalState *p = dynamic_cast<QFinalState*>(o);
	if (p != NULL) {
	}
	DummyQAbstractState::connection(o);
}

KQFinalState::KQFinalState(QState* parent) : QFinalState(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQFinalState();
	dummy->connection((QObject*)this);
}

KQFinalState::~KQFinalState()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QFinalState_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFinalState *qp = RawPtr_to(KQFinalState *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QFinalState]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFinalState]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QFinalState_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFinalState *qp = RawPtr_to(KQFinalState *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QFinalState]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFinalState]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QFinalState_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQFinalState *qp = (KQFinalState *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QFinalState*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QFinalState_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQFinalState *qp = (KQFinalState *)p->rawptr;
		KQFinalState *qp = static_cast<KQFinalState*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QFinalState_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQFinalState::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQFinalState::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QFinalState::event(event);
		return false;
	}
//	QFinalState::event(event);
	return true;
}



DEFAPI(void) defQFinalState(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFinalState";
	cdef->free = QFinalState_free;
	cdef->reftrace = QFinalState_reftrace;
	cdef->compareTo = QFinalState_compareTo;
}


