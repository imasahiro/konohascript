//QChildEvent QChildEvent.new(int type, QObject child);
KMETHOD QChildEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChildEvent::Type type = Int_to(QChildEvent::Type, sfp[1]);
	QObject*  child = RawPtr_to(QObject*, sfp[2]);
	KQChildEvent *ret_v = new KQChildEvent(type, child);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QChildEvent.added();
KMETHOD QChildEvent_added(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChildEvent *  qp = RawPtr_to(QChildEvent *, sfp[0]);
	if (qp) {
		bool ret_v = qp->added();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QObject QChildEvent.child();
KMETHOD QChildEvent_child(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChildEvent *  qp = RawPtr_to(QChildEvent *, sfp[0]);
	if (qp) {
		QObject* ret_v = qp->child();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QChildEvent.polished();
KMETHOD QChildEvent_polished(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChildEvent *  qp = RawPtr_to(QChildEvent *, sfp[0]);
	if (qp) {
		bool ret_v = qp->polished();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QChildEvent.removed();
KMETHOD QChildEvent_removed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QChildEvent *  qp = RawPtr_to(QChildEvent *, sfp[0]);
	if (qp) {
		bool ret_v = qp->removed();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQChildEvent::DummyQChildEvent()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQChildEvent::~DummyQChildEvent()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQChildEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQChildEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQChildEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQChildEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQChildEvent::event_map->bigin();
	if ((itr = DummyQChildEvent::event_map->find(str)) == DummyQChildEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQChildEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQChildEvent::slot_map->bigin();
	if ((itr = DummyQChildEvent::slot_map->find(str)) == DummyQChildEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQChildEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQChildEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQChildEvent::connection(QObject *o)
{
	QChildEvent *p = dynamic_cast<QChildEvent*>(o);
	if (p != NULL) {
	}
	DummyQEvent::connection(o);
}

KQChildEvent::KQChildEvent(QChildEvent::Type type, QObject* child) : QChildEvent(type, child)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQChildEvent();
}

KQChildEvent::~KQChildEvent()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QChildEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQChildEvent *qp = RawPtr_to(KQChildEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QChildEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QChildEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QChildEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQChildEvent *qp = RawPtr_to(KQChildEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QChildEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QChildEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QChildEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQChildEvent *qp = (KQChildEvent *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QChildEvent*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QChildEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQChildEvent *qp = (KQChildEvent *)p->rawptr;
		KQChildEvent *qp = static_cast<KQChildEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QChildEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQChildEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQChildEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QChildEvent";
	cdef->free = QChildEvent_free;
	cdef->reftrace = QChildEvent_reftrace;
	cdef->compareTo = QChildEvent_compareTo;
}


