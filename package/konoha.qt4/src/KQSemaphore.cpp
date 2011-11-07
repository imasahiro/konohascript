//QSemaphore QSemaphore.new(int n);
KMETHOD QSemaphore_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int n = Int_to(int, sfp[1]);
	KQSemaphore *ret_v = new KQSemaphore(n);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QSemaphore.acquire(int n);
KMETHOD QSemaphore_acquire(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSemaphore *  qp = RawPtr_to(QSemaphore *, sfp[0]);
	if (qp) {
		int n = Int_to(int, sfp[1]);
		qp->acquire(n);
	}
	RETURNvoid_();
}

//int QSemaphore.available();
KMETHOD QSemaphore_available(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSemaphore *  qp = RawPtr_to(QSemaphore *, sfp[0]);
	if (qp) {
		int ret_v = qp->available();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QSemaphore.release(int n);
KMETHOD QSemaphore_release(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSemaphore *  qp = RawPtr_to(QSemaphore *, sfp[0]);
	if (qp) {
		int n = Int_to(int, sfp[1]);
		qp->release(n);
	}
	RETURNvoid_();
}

//boolean QSemaphore.tryAcquire(int n);
KMETHOD QSemaphore_tryAcquire(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSemaphore *  qp = RawPtr_to(QSemaphore *, sfp[0]);
	if (qp) {
		int n = Int_to(int, sfp[1]);
		bool ret_v = qp->tryAcquire(n);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QSemaphore.tryAcquire(int n, int timeout);
KMETHOD QSemaphore_tryAcquire(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSemaphore *  qp = RawPtr_to(QSemaphore *, sfp[0]);
	if (qp) {
		int n = Int_to(int, sfp[1]);
		int timeout = Int_to(int, sfp[2]);
		bool ret_v = qp->tryAcquire(n, timeout);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//Array<String> QSemaphore.parents();
KMETHOD QSemaphore_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSemaphore *qp = RawPtr_to(QSemaphore*, sfp[0]);
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

DummyQSemaphore::DummyQSemaphore()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSemaphore::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSemaphore::self = ptr;
}

bool DummyQSemaphore::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQSemaphore::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSemaphore::event_map->bigin();
	if ((itr = DummyQSemaphore::event_map->find(str)) == DummyQSemaphore::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSemaphore::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSemaphore::slot_map->bigin();
	if ((itr = DummyQSemaphore::slot_map->find(str)) == DummyQSemaphore::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQSemaphore::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQSemaphore::connection(QObject *o)
{
	QSemaphore *p = dynamic_cast<QSemaphore*>(o);
	if (p != NULL) {
	}
}

KQSemaphore::KQSemaphore(int n) : QSemaphore(n)
{
	self = NULL;
	dummy = new DummyQSemaphore();
}

KMETHOD QSemaphore_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSemaphore *qp = RawPtr_to(KQSemaphore *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSemaphore]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSemaphore]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSemaphore_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSemaphore *qp = RawPtr_to(KQSemaphore *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSemaphore]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSemaphore]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSemaphore_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSemaphore *qp = (KQSemaphore *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSemaphore_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQSemaphore *qp = (KQSemaphore *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSemaphore_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSemaphore::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQSemaphore(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSemaphore";
	cdef->free = QSemaphore_free;
	cdef->reftrace = QSemaphore_reftrace;
	cdef->compareTo = QSemaphore_compareTo;
}


