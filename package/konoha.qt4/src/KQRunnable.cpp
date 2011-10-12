//
//boolean QRunnable.getAutoDelete();
KMETHOD QRunnable_getAutoDelete(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRunnable *  qp = RawPtr_to(QRunnable *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->autoDelete();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual void QRunnable.run();
KMETHOD QRunnable_run(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRunnable *  qp = RawPtr_to(QRunnable *, sfp[0]);
	if (qp != NULL) {
		qp->run();
	}
	RETURNvoid_();
}

//void QRunnable.setAutoDelete(boolean autoDelete);
KMETHOD QRunnable_setAutoDelete(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRunnable *  qp = RawPtr_to(QRunnable *, sfp[0]);
	if (qp != NULL) {
		bool autoDelete = Boolean_to(bool, sfp[1]);
		qp->setAutoDelete(autoDelete);
	}
	RETURNvoid_();
}


DummyQRunnable::DummyQRunnable()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQRunnable::setSelf(knh_RawPtr_t *ptr)
{
	DummyQRunnable::self = ptr;
}

bool DummyQRunnable::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQRunnable::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRunnable::event_map->bigin();
	if ((itr = DummyQRunnable::event_map->find(str)) == DummyQRunnable::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQRunnable::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRunnable::slot_map->bigin();
	if ((itr = DummyQRunnable::event_map->find(str)) == DummyQRunnable::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQRunnable::KQRunnable() : QRunnable()
{
	self = NULL;
}

KMETHOD QRunnable_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRunnable *qp = RawPtr_to(KQRunnable *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QRunnable]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQRunnable::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRunnable]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QRunnable_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRunnable *qp = RawPtr_to(KQRunnable *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QRunnable]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQRunnable::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRunnable]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QRunnable_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQRunnable *qp = (KQRunnable *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QRunnable_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQRunnable *qp = (KQRunnable *)p->rawptr;
		(void)qp;
	}
}

static int QRunnable_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQRunnable(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QRunnable";
	cdef->free = QRunnable_free;
	cdef->reftrace = QRunnable_reftrace;
	cdef->compareTo = QRunnable_compareTo;
}


