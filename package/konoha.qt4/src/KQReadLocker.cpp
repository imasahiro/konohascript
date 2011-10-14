//QReadLocker QReadLocker.new(QReadWriteLock lock);
KMETHOD QReadLocker_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QReadWriteLock*  lock = RawPtr_to(QReadWriteLock*, sfp[1]);
	KQReadLocker *ret_v = new KQReadLocker(lock);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QReadWriteLock QReadLocker.readWriteLock();
KMETHOD QReadLocker_readWriteLock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QReadLocker *  qp = RawPtr_to(QReadLocker *, sfp[0]);
	if (qp != NULL) {
		QReadWriteLock* ret_v = qp->readWriteLock();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QReadWriteLock*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QReadLocker.relock();
KMETHOD QReadLocker_relock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QReadLocker *  qp = RawPtr_to(QReadLocker *, sfp[0]);
	if (qp != NULL) {
		qp->relock();
	}
	RETURNvoid_();
}

//void QReadLocker.unlock();
KMETHOD QReadLocker_unlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QReadLocker *  qp = RawPtr_to(QReadLocker *, sfp[0]);
	if (qp != NULL) {
		qp->unlock();
	}
	RETURNvoid_();
}


DummyQReadLocker::DummyQReadLocker()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQReadLocker::setSelf(knh_RawPtr_t *ptr)
{
	DummyQReadLocker::self = ptr;
}

bool DummyQReadLocker::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQReadLocker::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQReadLocker::event_map->bigin();
	if ((itr = DummyQReadLocker::event_map->find(str)) == DummyQReadLocker::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQReadLocker::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQReadLocker::slot_map->bigin();
	if ((itr = DummyQReadLocker::slot_map->find(str)) == DummyQReadLocker::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQReadLocker::connection(QObject *o)
{
	return;
}

KQReadLocker::KQReadLocker(QReadWriteLock* lock) : QReadLocker(lock)
{
	self = NULL;
	dummy = new DummyQReadLocker();
	dummy->connection((QObject*)this);
}

KMETHOD QReadLocker_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQReadLocker *qp = RawPtr_to(KQReadLocker *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QReadLocker]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QReadLocker]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QReadLocker_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQReadLocker *qp = RawPtr_to(KQReadLocker *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QReadLocker]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QReadLocker]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QReadLocker_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQReadLocker *qp = (KQReadLocker *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QReadLocker_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQReadLocker *qp = (KQReadLocker *)p->rawptr;
		(void)qp;
	}
}

static int QReadLocker_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQReadLocker::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQReadLocker(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QReadLocker";
	cdef->free = QReadLocker_free;
	cdef->reftrace = QReadLocker_reftrace;
	cdef->compareTo = QReadLocker_compareTo;
}


