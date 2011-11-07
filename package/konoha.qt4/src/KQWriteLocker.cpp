//QWriteLocker QWriteLocker.new(QReadWriteLock lock);
KMETHOD QWriteLocker_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QReadWriteLock*  lock = RawPtr_to(QReadWriteLock*, sfp[1]);
	KQWriteLocker *ret_v = new KQWriteLocker(lock);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QReadWriteLock QWriteLocker.readWriteLock();
KMETHOD QWriteLocker_readWriteLock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWriteLocker *  qp = RawPtr_to(QWriteLocker *, sfp[0]);
	if (qp) {
		QReadWriteLock* ret_v = qp->readWriteLock();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QReadWriteLock*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWriteLocker.relock();
KMETHOD QWriteLocker_relock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWriteLocker *  qp = RawPtr_to(QWriteLocker *, sfp[0]);
	if (qp) {
		qp->relock();
	}
	RETURNvoid_();
}

//void QWriteLocker.unlock();
KMETHOD QWriteLocker_unlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWriteLocker *  qp = RawPtr_to(QWriteLocker *, sfp[0]);
	if (qp) {
		qp->unlock();
	}
	RETURNvoid_();
}

//Array<String> QWriteLocker.parents();
KMETHOD QWriteLocker_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWriteLocker *qp = RawPtr_to(QWriteLocker*, sfp[0]);
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

DummyQWriteLocker::DummyQWriteLocker()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQWriteLocker::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWriteLocker::self = ptr;
}

bool DummyQWriteLocker::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQWriteLocker::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWriteLocker::event_map->bigin();
	if ((itr = DummyQWriteLocker::event_map->find(str)) == DummyQWriteLocker::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWriteLocker::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWriteLocker::slot_map->bigin();
	if ((itr = DummyQWriteLocker::slot_map->find(str)) == DummyQWriteLocker::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQWriteLocker::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQWriteLocker::connection(QObject *o)
{
	QWriteLocker *p = dynamic_cast<QWriteLocker*>(o);
	if (p != NULL) {
	}
}

KQWriteLocker::KQWriteLocker(QReadWriteLock* lock) : QWriteLocker(lock)
{
	self = NULL;
	dummy = new DummyQWriteLocker();
}

KMETHOD QWriteLocker_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWriteLocker *qp = RawPtr_to(KQWriteLocker *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWriteLocker]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWriteLocker]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWriteLocker_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWriteLocker *qp = RawPtr_to(KQWriteLocker *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWriteLocker]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWriteLocker]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWriteLocker_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWriteLocker *qp = (KQWriteLocker *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWriteLocker_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQWriteLocker *qp = (KQWriteLocker *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWriteLocker_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWriteLocker::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQWriteLocker(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWriteLocker";
	cdef->free = QWriteLocker_free;
	cdef->reftrace = QWriteLocker_reftrace;
	cdef->compareTo = QWriteLocker_compareTo;
}


