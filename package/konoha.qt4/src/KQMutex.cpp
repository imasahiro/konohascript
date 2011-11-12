//QMutex QMutex.new(int mode);
KMETHOD QMutex_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMutex::RecursionMode mode = Int_to(QMutex::RecursionMode, sfp[1]);
	KQMutex *ret_v = new KQMutex(mode);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QMutex.lock();
KMETHOD QMutex_lock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMutex *  qp = RawPtr_to(QMutex *, sfp[0]);
	if (qp) {
		qp->lock();
	}
	RETURNvoid_();
}

//boolean QMutex.tryLock();
KMETHOD QMutex_tryLock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMutex *  qp = RawPtr_to(QMutex *, sfp[0]);
	if (qp) {
		bool ret_v = qp->tryLock();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QMutex.tryLock(int timeout);
KMETHOD QMutex_tryLock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMutex *  qp = RawPtr_to(QMutex *, sfp[0]);
	if (qp) {
		int timeout = Int_to(int, sfp[1]);
		bool ret_v = qp->tryLock(timeout);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//void QMutex.unlock();
KMETHOD QMutex_unlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMutex *  qp = RawPtr_to(QMutex *, sfp[0]);
	if (qp) {
		qp->unlock();
	}
	RETURNvoid_();
}

//Array<String> QMutex.parents();
KMETHOD QMutex_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMutex *qp = RawPtr_to(QMutex*, sfp[0]);
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

DummyQMutex::DummyQMutex()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQMutex::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMutex::self = ptr;
}

bool DummyQMutex::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQMutex::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMutex::event_map->bigin();
	if ((itr = DummyQMutex::event_map->find(str)) == DummyQMutex::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMutex::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMutex::slot_map->bigin();
	if ((itr = DummyQMutex::slot_map->find(str)) == DummyQMutex::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQMutex::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQMutex::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQMutex::connection(QObject *o)
{
	QMutex *p = dynamic_cast<QMutex*>(o);
	if (p != NULL) {
	}
}

KQMutex::KQMutex(QMutex::RecursionMode mode) : QMutex(mode)
{
	self = NULL;
	dummy = new DummyQMutex();
}

KMETHOD QMutex_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMutex *qp = RawPtr_to(KQMutex *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMutex]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMutex]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QMutex_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMutex *qp = RawPtr_to(KQMutex *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMutex]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMutex]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMutex_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMutex *qp = (KQMutex *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMutex_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQMutex *qp = (KQMutex *)p->rawptr;
//		KQMutex *qp = static_cast<KQMutex*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QMutex_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMutex::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QMutexConstInt[] = {
	{"Recursive", QMutex::Recursive},
	{"NonRecursive", QMutex::NonRecursive},
	{NULL, 0}
};

DEFAPI(void) constQMutex(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QMutexConstInt);
}


DEFAPI(void) defQMutex(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMutex";
	cdef->free = QMutex_free;
	cdef->reftrace = QMutex_reftrace;
	cdef->compareTo = QMutex_compareTo;
}


