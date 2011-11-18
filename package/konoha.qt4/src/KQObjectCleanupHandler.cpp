//QObjectCleanupHandler QObjectCleanupHandler.new();
KMETHOD QObjectCleanupHandler_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQObjectCleanupHandler *ret_v = new KQObjectCleanupHandler();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QObject QObjectCleanupHandler.add(QObject object);
KMETHOD QObjectCleanupHandler_add(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObjectCleanupHandler *  qp = RawPtr_to(QObjectCleanupHandler *, sfp[0]);
	if (qp) {
		QObject*  object = RawPtr_to(QObject*, sfp[1]);
		QObject* ret_v = qp->add(object);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QObjectCleanupHandler.clear();
KMETHOD QObjectCleanupHandler_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObjectCleanupHandler *  qp = RawPtr_to(QObjectCleanupHandler *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//boolean QObjectCleanupHandler.isEmpty();
KMETHOD QObjectCleanupHandler_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObjectCleanupHandler *  qp = RawPtr_to(QObjectCleanupHandler *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QObjectCleanupHandler.remove(QObject object);
KMETHOD QObjectCleanupHandler_remove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObjectCleanupHandler *  qp = RawPtr_to(QObjectCleanupHandler *, sfp[0]);
	if (qp) {
		QObject*  object = RawPtr_to(QObject*, sfp[1]);
		qp->remove(object);
	}
	RETURNvoid_();
}


DummyQObjectCleanupHandler::DummyQObjectCleanupHandler()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQObjectCleanupHandler::~DummyQObjectCleanupHandler()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQObjectCleanupHandler::setSelf(knh_RawPtr_t *ptr)
{
	DummyQObjectCleanupHandler::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQObjectCleanupHandler::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQObjectCleanupHandler::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQObjectCleanupHandler::event_map->bigin();
	if ((itr = DummyQObjectCleanupHandler::event_map->find(str)) == DummyQObjectCleanupHandler::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQObjectCleanupHandler::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQObjectCleanupHandler::slot_map->bigin();
	if ((itr = DummyQObjectCleanupHandler::slot_map->find(str)) == DummyQObjectCleanupHandler::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQObjectCleanupHandler::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQObjectCleanupHandler::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQObjectCleanupHandler::connection(QObject *o)
{
	QObjectCleanupHandler *p = dynamic_cast<QObjectCleanupHandler*>(o);
	if (p != NULL) {
	}
	DummyQObject::connection(o);
}

KQObjectCleanupHandler::KQObjectCleanupHandler() : QObjectCleanupHandler()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQObjectCleanupHandler();
	dummy->connection((QObject*)this);
}

KQObjectCleanupHandler::~KQObjectCleanupHandler()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QObjectCleanupHandler_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQObjectCleanupHandler *qp = RawPtr_to(KQObjectCleanupHandler *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QObjectCleanupHandler]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QObjectCleanupHandler]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QObjectCleanupHandler_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQObjectCleanupHandler *qp = RawPtr_to(KQObjectCleanupHandler *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QObjectCleanupHandler]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QObjectCleanupHandler]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QObjectCleanupHandler_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQObjectCleanupHandler *qp = (KQObjectCleanupHandler *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QObjectCleanupHandler*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QObjectCleanupHandler_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQObjectCleanupHandler *qp = (KQObjectCleanupHandler *)p->rawptr;
		KQObjectCleanupHandler *qp = static_cast<KQObjectCleanupHandler*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QObjectCleanupHandler_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQObjectCleanupHandler::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQObjectCleanupHandler::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QObjectCleanupHandler::event(event);
		return false;
	}
//	QObjectCleanupHandler::event(event);
	return true;
}



DEFAPI(void) defQObjectCleanupHandler(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QObjectCleanupHandler";
	cdef->free = QObjectCleanupHandler_free;
	cdef->reftrace = QObjectCleanupHandler_reftrace;
	cdef->compareTo = QObjectCleanupHandler_compareTo;
}


