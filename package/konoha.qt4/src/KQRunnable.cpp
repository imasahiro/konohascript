//
//boolean QRunnable.getAutoDelete();
KMETHOD QRunnable_getAutoDelete(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRunnable *  qp = RawPtr_to(QRunnable *, sfp[0]);
	if (qp) {
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
	if (qp) {
		qp->run();
	}
	RETURNvoid_();
}

//void QRunnable.setAutoDelete(boolean autoDelete);
KMETHOD QRunnable_setAutoDelete(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRunnable *  qp = RawPtr_to(QRunnable *, sfp[0]);
	if (qp) {
		bool autoDelete = Boolean_to(bool, sfp[1]);
		qp->setAutoDelete(autoDelete);
	}
	RETURNvoid_();
}

//Array<String> QRunnable.parents();
KMETHOD QRunnable_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRunnable *qp = RawPtr_to(QRunnable*, sfp[0]);
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
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQRunnable::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRunnable::slot_map->bigin();
	if ((itr = DummyQRunnable::slot_map->find(str)) == DummyQRunnable::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQRunnable::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQRunnable::connection(QObject *o)
{
	QRunnable *p = dynamic_cast<QRunnable*>(o);
	if (p != NULL) {
	}
}

KQRunnable::KQRunnable() : QRunnable()
{
	self = NULL;
	dummy = new DummyQRunnable();
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
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
	if (p->rawptr != NULL) {
		KQRunnable *qp = (KQRunnable *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QRunnable_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQRunnable::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQRunnable(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QRunnable";
	cdef->free = QRunnable_free;
	cdef->reftrace = QRunnable_reftrace;
	cdef->compareTo = QRunnable_compareTo;
}


