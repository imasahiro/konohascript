//QMutexLocker QMutexLocker.new(QMutex mutex);
KMETHOD QMutexLocker_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMutex*  mutex = RawPtr_to(QMutex*, sfp[1]);
	KQMutexLocker *ret_v = new KQMutexLocker(mutex);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QMutex QMutexLocker.mutex();
KMETHOD QMutexLocker_mutex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMutexLocker *  qp = RawPtr_to(QMutexLocker *, sfp[0]);
	if (qp != NULL) {
		QMutex* ret_v = qp->mutex();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMutex*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QMutexLocker.relock();
KMETHOD QMutexLocker_relock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMutexLocker *  qp = RawPtr_to(QMutexLocker *, sfp[0]);
	if (qp != NULL) {
		qp->relock();
	}
	RETURNvoid_();
}

//void QMutexLocker.unlock();
KMETHOD QMutexLocker_unlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMutexLocker *  qp = RawPtr_to(QMutexLocker *, sfp[0]);
	if (qp != NULL) {
		qp->unlock();
	}
	RETURNvoid_();
}


DummyQMutexLocker::DummyQMutexLocker()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQMutexLocker::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMutexLocker::self = ptr;
}

bool DummyQMutexLocker::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQMutexLocker::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMutexLocker::event_map->bigin();
	if ((itr = DummyQMutexLocker::event_map->find(str)) == DummyQMutexLocker::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMutexLocker::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMutexLocker::slot_map->bigin();
	if ((itr = DummyQMutexLocker::slot_map->find(str)) == DummyQMutexLocker::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQMutexLocker::connection(QObject *o)
{
	return;
}

KQMutexLocker::KQMutexLocker(QMutex* mutex) : QMutexLocker(mutex)
{
	self = NULL;
	dummy = new DummyQMutexLocker();
	dummy->connection((QObject*)this);
}

KMETHOD QMutexLocker_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMutexLocker *qp = RawPtr_to(KQMutexLocker *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMutexLocker]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMutexLocker]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QMutexLocker_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMutexLocker *qp = RawPtr_to(KQMutexLocker *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMutexLocker]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMutexLocker]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMutexLocker_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMutexLocker *qp = (KQMutexLocker *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMutexLocker_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQMutexLocker *qp = (KQMutexLocker *)p->rawptr;
		(void)qp;
	}
}

static int QMutexLocker_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMutexLocker::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQMutexLocker(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMutexLocker";
	cdef->free = QMutexLocker_free;
	cdef->reftrace = QMutexLocker_reftrace;
	cdef->compareTo = QMutexLocker_compareTo;
}


