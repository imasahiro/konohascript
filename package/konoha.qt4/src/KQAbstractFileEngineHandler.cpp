//
//@Virtual QAbstractFileEngine QAbstractFileEngineHandler.create(String fileName);
KMETHOD QAbstractFileEngineHandler_create(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngineHandler *  qp = RawPtr_to(QAbstractFileEngineHandler *, sfp[0]);
	if (qp) {
		const QString fileName = String_to(const QString, sfp[1]);
		QAbstractFileEngine* ret_v = qp->create(fileName);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractFileEngine*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QAbstractFileEngineHandler.parents();
KMETHOD QAbstractFileEngineHandler_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngineHandler *qp = RawPtr_to(QAbstractFileEngineHandler*, sfp[0]);
	if (qp != NULL) {
		int size = 10;
		knh_Array_t *a = new_Array0(ctx, size);
		const knh_ClassTBL_t *ct = sfp[0].p->h.cTBL;
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}

DummyQAbstractFileEngineHandler::DummyQAbstractFileEngineHandler()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQAbstractFileEngineHandler::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractFileEngineHandler::self = ptr;
}

bool DummyQAbstractFileEngineHandler::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQAbstractFileEngineHandler::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractFileEngineHandler::event_map->bigin();
	if ((itr = DummyQAbstractFileEngineHandler::event_map->find(str)) == DummyQAbstractFileEngineHandler::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractFileEngineHandler::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractFileEngineHandler::slot_map->bigin();
	if ((itr = DummyQAbstractFileEngineHandler::slot_map->find(str)) == DummyQAbstractFileEngineHandler::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQAbstractFileEngineHandler::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQAbstractFileEngineHandler::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQAbstractFileEngineHandler::connection(QObject *o)
{
	QAbstractFileEngineHandler *p = dynamic_cast<QAbstractFileEngineHandler*>(o);
	if (p != NULL) {
	}
}

KQAbstractFileEngineHandler::KQAbstractFileEngineHandler() : QAbstractFileEngineHandler()
{
	self = NULL;
	dummy = new DummyQAbstractFileEngineHandler();
}

KMETHOD QAbstractFileEngineHandler_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractFileEngineHandler *qp = RawPtr_to(KQAbstractFileEngineHandler *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractFileEngineHandler]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractFileEngineHandler]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAbstractFileEngineHandler_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractFileEngineHandler *qp = RawPtr_to(KQAbstractFileEngineHandler *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractFileEngineHandler]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractFileEngineHandler]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractFileEngineHandler_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAbstractFileEngineHandler *qp = (KQAbstractFileEngineHandler *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAbstractFileEngineHandler_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQAbstractFileEngineHandler *qp = (KQAbstractFileEngineHandler *)p->rawptr;
//		KQAbstractFileEngineHandler *qp = static_cast<KQAbstractFileEngineHandler*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAbstractFileEngineHandler_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAbstractFileEngineHandler::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQAbstractFileEngineHandler(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractFileEngineHandler";
	cdef->free = QAbstractFileEngineHandler_free;
	cdef->reftrace = QAbstractFileEngineHandler_reftrace;
	cdef->compareTo = QAbstractFileEngineHandler_compareTo;
}


