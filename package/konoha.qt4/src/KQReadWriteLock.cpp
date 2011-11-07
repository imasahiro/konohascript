//QReadWriteLock QReadWriteLock.new();
KMETHOD QReadWriteLock_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQReadWriteLock *ret_v = new KQReadWriteLock();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QReadWriteLock QReadWriteLock.new(int recursionMode);
KMETHOD QReadWriteLock_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QReadWriteLock::RecursionMode recursionMode = Int_to(QReadWriteLock::RecursionMode, sfp[1]);
	KQReadWriteLock *ret_v = new KQReadWriteLock(recursionMode);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QReadWriteLock.lockForRead();
KMETHOD QReadWriteLock_lockForRead(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QReadWriteLock *  qp = RawPtr_to(QReadWriteLock *, sfp[0]);
	if (qp) {
		qp->lockForRead();
	}
	RETURNvoid_();
}

//void QReadWriteLock.lockForWrite();
KMETHOD QReadWriteLock_lockForWrite(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QReadWriteLock *  qp = RawPtr_to(QReadWriteLock *, sfp[0]);
	if (qp) {
		qp->lockForWrite();
	}
	RETURNvoid_();
}

//boolean QReadWriteLock.tryLockForRead();
KMETHOD QReadWriteLock_tryLockForRead(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QReadWriteLock *  qp = RawPtr_to(QReadWriteLock *, sfp[0]);
	if (qp) {
		bool ret_v = qp->tryLockForRead();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QReadWriteLock.tryLockForRead(int timeout);
KMETHOD QReadWriteLock_tryLockForRead(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QReadWriteLock *  qp = RawPtr_to(QReadWriteLock *, sfp[0]);
	if (qp) {
		int timeout = Int_to(int, sfp[1]);
		bool ret_v = qp->tryLockForRead(timeout);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//boolean QReadWriteLock.tryLockForWrite();
KMETHOD QReadWriteLock_tryLockForWrite(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QReadWriteLock *  qp = RawPtr_to(QReadWriteLock *, sfp[0]);
	if (qp) {
		bool ret_v = qp->tryLockForWrite();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QReadWriteLock.tryLockForWrite(int timeout);
KMETHOD QReadWriteLock_tryLockForWrite(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QReadWriteLock *  qp = RawPtr_to(QReadWriteLock *, sfp[0]);
	if (qp) {
		int timeout = Int_to(int, sfp[1]);
		bool ret_v = qp->tryLockForWrite(timeout);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//void QReadWriteLock.unlock();
KMETHOD QReadWriteLock_unlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QReadWriteLock *  qp = RawPtr_to(QReadWriteLock *, sfp[0]);
	if (qp) {
		qp->unlock();
	}
	RETURNvoid_();
}

//Array<String> QReadWriteLock.parents();
KMETHOD QReadWriteLock_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QReadWriteLock *qp = RawPtr_to(QReadWriteLock*, sfp[0]);
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

DummyQReadWriteLock::DummyQReadWriteLock()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQReadWriteLock::setSelf(knh_RawPtr_t *ptr)
{
	DummyQReadWriteLock::self = ptr;
}

bool DummyQReadWriteLock::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQReadWriteLock::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQReadWriteLock::event_map->bigin();
	if ((itr = DummyQReadWriteLock::event_map->find(str)) == DummyQReadWriteLock::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQReadWriteLock::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQReadWriteLock::slot_map->bigin();
	if ((itr = DummyQReadWriteLock::slot_map->find(str)) == DummyQReadWriteLock::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQReadWriteLock::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQReadWriteLock::connection(QObject *o)
{
	QReadWriteLock *p = dynamic_cast<QReadWriteLock*>(o);
	if (p != NULL) {
	}
}

KQReadWriteLock::KQReadWriteLock() : QReadWriteLock()
{
	self = NULL;
	dummy = new DummyQReadWriteLock();
}

KMETHOD QReadWriteLock_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQReadWriteLock *qp = RawPtr_to(KQReadWriteLock *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QReadWriteLock]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QReadWriteLock]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QReadWriteLock_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQReadWriteLock *qp = RawPtr_to(KQReadWriteLock *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QReadWriteLock]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QReadWriteLock]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QReadWriteLock_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQReadWriteLock *qp = (KQReadWriteLock *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QReadWriteLock_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQReadWriteLock *qp = (KQReadWriteLock *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QReadWriteLock_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQReadWriteLock::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QReadWriteLockConstInt[] = {
	{"Recursive", QReadWriteLock::Recursive},
	{"NonRecursive", QReadWriteLock::NonRecursive},
	{NULL, 0}
};

DEFAPI(void) constQReadWriteLock(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QReadWriteLockConstInt);
}


DEFAPI(void) defQReadWriteLock(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QReadWriteLock";
	cdef->free = QReadWriteLock_free;
	cdef->reftrace = QReadWriteLock_reftrace;
	cdef->compareTo = QReadWriteLock_compareTo;
}


