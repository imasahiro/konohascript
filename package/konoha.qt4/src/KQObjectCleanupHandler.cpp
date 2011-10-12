//QObjectCleanupHandler QObjectCleanupHandler.new();
KMETHOD QObjectCleanupHandler_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQObjectCleanupHandler *ret_v = new KQObjectCleanupHandler();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QObject QObjectCleanupHandler.add(QObject object);
KMETHOD QObjectCleanupHandler_add(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObjectCleanupHandler *  qp = RawPtr_to(QObjectCleanupHandler *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
		qp->clear();
	}
	RETURNvoid_();
}

//boolean QObjectCleanupHandler.isEmpty();
KMETHOD QObjectCleanupHandler_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObjectCleanupHandler *  qp = RawPtr_to(QObjectCleanupHandler *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
		QObject*  object = RawPtr_to(QObject*, sfp[1]);
		qp->remove(object);
	}
	RETURNvoid_();
}


DummyQObjectCleanupHandler::DummyQObjectCleanupHandler()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
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
		bool ret;
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
	if ((itr = DummyQObjectCleanupHandler::event_map->find(str)) == DummyQObjectCleanupHandler::slot_map->end()) {
		bool ret;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQObjectCleanupHandler::KQObjectCleanupHandler() : QObjectCleanupHandler()
{
	self = NULL;
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
		if (!qp->DummyQObjectCleanupHandler::addEvent(callback_func, str)) {
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
		if (!qp->DummyQObjectCleanupHandler::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QObjectCleanupHandler]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QObjectCleanupHandler_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQObjectCleanupHandler *qp = (KQObjectCleanupHandler *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QObjectCleanupHandler_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQObjectCleanupHandler *qp = (KQObjectCleanupHandler *)p->rawptr;
		(void)qp;
	}
}

static int QObjectCleanupHandler_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQObjectCleanupHandler::event(QEvent *event)
{
	if (!DummyQObjectCleanupHandler::eventDispatcher(event)) {
		QObjectCleanupHandler::event(event);
		return false;
	}
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


