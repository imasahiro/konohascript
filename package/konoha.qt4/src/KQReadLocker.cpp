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
	if (qp) {
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
	if (qp) {
		qp->relock();
	}
	RETURNvoid_();
}

//void QReadLocker.unlock();
KMETHOD QReadLocker_unlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QReadLocker *  qp = RawPtr_to(QReadLocker *, sfp[0]);
	if (qp) {
		qp->unlock();
	}
	RETURNvoid_();
}

//Array<String> QReadLocker.parents();
KMETHOD QReadLocker_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QReadLocker *qp = RawPtr_to(QReadLocker*, sfp[0]);
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

DummyQReadLocker::DummyQReadLocker()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQReadLocker::~DummyQReadLocker()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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

knh_Object_t** DummyQReadLocker::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQReadLocker::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQReadLocker::connection(QObject *o)
{
	QReadLocker *p = dynamic_cast<QReadLocker*>(o);
	if (p != NULL) {
	}
}

KQReadLocker::KQReadLocker(QReadWriteLock* lock) : QReadLocker(lock)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQReadLocker();
}

KQReadLocker::~KQReadLocker()
{
	delete dummy;
	dummy = NULL;
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
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQReadLocker *qp = (KQReadLocker *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QReadLocker*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QReadLocker_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQReadLocker *qp = (KQReadLocker *)p->rawptr;
		KQReadLocker *qp = static_cast<KQReadLocker*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
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


