//QHistoryState QHistoryState.new(QState parent);
KMETHOD QHistoryState_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState*  parent = RawPtr_to(QState*, sfp[1]);
	KQHistoryState *ret_v = new KQHistoryState(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QHistoryState QHistoryState.new(int type, QState parent);
KMETHOD QHistoryState_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHistoryState::HistoryType type = Int_to(QHistoryState::HistoryType, sfp[1]);
	QState*  parent = RawPtr_to(QState*, sfp[2]);
	KQHistoryState *ret_v = new KQHistoryState(type, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QAbstractState QHistoryState.getDefaultState();
KMETHOD QHistoryState_getDefaultState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHistoryState *  qp = RawPtr_to(QHistoryState *, sfp[0]);
	if (qp) {
		QAbstractState* ret_v = qp->defaultState();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractState*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QHistoryState.getHistoryType();
KMETHOD QHistoryState_getHistoryType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHistoryState *  qp = RawPtr_to(QHistoryState *, sfp[0]);
	if (qp) {
		QHistoryState::HistoryType ret_v = qp->historyType();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QHistoryState.setDefaultState(QAbstractState state);
KMETHOD QHistoryState_setDefaultState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHistoryState *  qp = RawPtr_to(QHistoryState *, sfp[0]);
	if (qp) {
		QAbstractState*  state = RawPtr_to(QAbstractState*, sfp[1]);
		qp->setDefaultState(state);
	}
	RETURNvoid_();
}

//void QHistoryState.setHistoryType(int type);
KMETHOD QHistoryState_setHistoryType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHistoryState *  qp = RawPtr_to(QHistoryState *, sfp[0]);
	if (qp) {
		QHistoryState::HistoryType type = Int_to(QHistoryState::HistoryType, sfp[1]);
		qp->setHistoryType(type);
	}
	RETURNvoid_();
}


DummyQHistoryState::DummyQHistoryState()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQHistoryState::~DummyQHistoryState()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQHistoryState::setSelf(knh_RawPtr_t *ptr)
{
	DummyQHistoryState::self = ptr;
	DummyQAbstractState::setSelf(ptr);
}

bool DummyQHistoryState::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractState::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQHistoryState::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHistoryState::event_map->bigin();
	if ((itr = DummyQHistoryState::event_map->find(str)) == DummyQHistoryState::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractState::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQHistoryState::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHistoryState::slot_map->bigin();
	if ((itr = DummyQHistoryState::slot_map->find(str)) == DummyQHistoryState::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractState::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQHistoryState::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQHistoryState::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQAbstractState::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQHistoryState::connection(QObject *o)
{
	QHistoryState *p = dynamic_cast<QHistoryState*>(o);
	if (p != NULL) {
	}
	DummyQAbstractState::connection(o);
}

KQHistoryState::KQHistoryState(QState* parent) : QHistoryState(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQHistoryState();
	dummy->connection((QObject*)this);
}

KQHistoryState::~KQHistoryState()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QHistoryState_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHistoryState *qp = RawPtr_to(KQHistoryState *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QHistoryState]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHistoryState]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QHistoryState_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHistoryState *qp = RawPtr_to(KQHistoryState *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QHistoryState]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHistoryState]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QHistoryState_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQHistoryState *qp = (KQHistoryState *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QHistoryState*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QHistoryState_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQHistoryState *qp = (KQHistoryState *)p->rawptr;
		KQHistoryState *qp = static_cast<KQHistoryState*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QHistoryState_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQHistoryState::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQHistoryState::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QHistoryState::event(event);
		return false;
	}
//	QHistoryState::event(event);
	return true;
}

static knh_IntData_t QHistoryStateConstInt[] = {
	{"ShallowHistory", QHistoryState::ShallowHistory},
	{"DeepHistory", QHistoryState::DeepHistory},
	{NULL, 0}
};

DEFAPI(void) constQHistoryState(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QHistoryStateConstInt);
}


DEFAPI(void) defQHistoryState(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QHistoryState";
	cdef->free = QHistoryState_free;
	cdef->reftrace = QHistoryState_reftrace;
	cdef->compareTo = QHistoryState_compareTo;
}


