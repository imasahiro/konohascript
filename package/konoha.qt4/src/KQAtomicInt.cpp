//QAtomicInt QAtomicInt.new(int value);
KMETHOD QAtomicInt_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int value = Int_to(int, sfp[1]);
	KQAtomicInt *ret_v = new KQAtomicInt(value);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QAtomicInt QAtomicInt.new(QAtomicInt other);
KMETHOD QAtomicInt_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QAtomicInt  other = *RawPtr_to(const QAtomicInt *, sfp[1]);
	KQAtomicInt *ret_v = new KQAtomicInt(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QAtomicInt.deref();
KMETHOD QAtomicInt_deref(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->deref();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QAtomicInt.fetchAndAddAcquire(int valueToAdd);
KMETHOD QAtomicInt_fetchAndAddAcquire(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		int valueToAdd = Int_to(int, sfp[1]);
		int ret_v = qp->fetchAndAddAcquire(valueToAdd);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAtomicInt.fetchAndAddOrdered(int valueToAdd);
KMETHOD QAtomicInt_fetchAndAddOrdered(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		int valueToAdd = Int_to(int, sfp[1]);
		int ret_v = qp->fetchAndAddOrdered(valueToAdd);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAtomicInt.fetchAndAddRelaxed(int valueToAdd);
KMETHOD QAtomicInt_fetchAndAddRelaxed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		int valueToAdd = Int_to(int, sfp[1]);
		int ret_v = qp->fetchAndAddRelaxed(valueToAdd);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAtomicInt.fetchAndAddRelease(int valueToAdd);
KMETHOD QAtomicInt_fetchAndAddRelease(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		int valueToAdd = Int_to(int, sfp[1]);
		int ret_v = qp->fetchAndAddRelease(valueToAdd);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAtomicInt.fetchAndStoreAcquire(int new_Value);
KMETHOD QAtomicInt_fetchAndStoreAcquire(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		int new_Value = Int_to(int, sfp[1]);
		int ret_v = qp->fetchAndStoreAcquire(new_Value);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAtomicInt.fetchAndStoreOrdered(int new_Value);
KMETHOD QAtomicInt_fetchAndStoreOrdered(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		int new_Value = Int_to(int, sfp[1]);
		int ret_v = qp->fetchAndStoreOrdered(new_Value);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAtomicInt.fetchAndStoreRelaxed(int new_Value);
KMETHOD QAtomicInt_fetchAndStoreRelaxed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		int new_Value = Int_to(int, sfp[1]);
		int ret_v = qp->fetchAndStoreRelaxed(new_Value);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAtomicInt.fetchAndStoreRelease(int new_Value);
KMETHOD QAtomicInt_fetchAndStoreRelease(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		int new_Value = Int_to(int, sfp[1]);
		int ret_v = qp->fetchAndStoreRelease(new_Value);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QAtomicInt.ref();
KMETHOD QAtomicInt_ref(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->ref();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAtomicInt.testAndSetAcquire(int expectedValue, int new_Value);
KMETHOD QAtomicInt_testAndSetAcquire(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		int expectedValue = Int_to(int, sfp[1]);
		int new_Value = Int_to(int, sfp[2]);
		bool ret_v = qp->testAndSetAcquire(expectedValue, new_Value);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAtomicInt.testAndSetOrdered(int expectedValue, int new_Value);
KMETHOD QAtomicInt_testAndSetOrdered(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		int expectedValue = Int_to(int, sfp[1]);
		int new_Value = Int_to(int, sfp[2]);
		bool ret_v = qp->testAndSetOrdered(expectedValue, new_Value);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAtomicInt.testAndSetRelaxed(int expectedValue, int new_Value);
KMETHOD QAtomicInt_testAndSetRelaxed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		int expectedValue = Int_to(int, sfp[1]);
		int new_Value = Int_to(int, sfp[2]);
		bool ret_v = qp->testAndSetRelaxed(expectedValue, new_Value);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAtomicInt.testAndSetRelease(int expectedValue, int new_Value);
KMETHOD QAtomicInt_testAndSetRelease(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		int expectedValue = Int_to(int, sfp[1]);
		int new_Value = Int_to(int, sfp[2]);
		bool ret_v = qp->testAndSetRelease(expectedValue, new_Value);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAtomicInt.isFetchAndAddNative();
KMETHOD QAtomicInt_isFetchAndAddNative(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isFetchAndAddNative();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAtomicInt.isFetchAndAddWaitFree();
KMETHOD QAtomicInt_isFetchAndAddWaitFree(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isFetchAndAddWaitFree();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAtomicInt.isFetchAndStoreNative();
KMETHOD QAtomicInt_isFetchAndStoreNative(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isFetchAndStoreNative();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAtomicInt.isFetchAndStoreWaitFree();
KMETHOD QAtomicInt_isFetchAndStoreWaitFree(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isFetchAndStoreWaitFree();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAtomicInt.isReferenceCountingNative();
KMETHOD QAtomicInt_isReferenceCountingNative(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isReferenceCountingNative();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAtomicInt.isReferenceCountingWaitFree();
KMETHOD QAtomicInt_isReferenceCountingWaitFree(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isReferenceCountingWaitFree();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAtomicInt.isTestAndSetNative();
KMETHOD QAtomicInt_isTestAndSetNative(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isTestAndSetNative();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAtomicInt.isTestAndSetWaitFree();
KMETHOD QAtomicInt_isTestAndSetWaitFree(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAtomicInt *  qp = RawPtr_to(QAtomicInt *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isTestAndSetWaitFree();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQAtomicInt::DummyQAtomicInt()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQAtomicInt::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAtomicInt::self = ptr;
}

bool DummyQAtomicInt::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQAtomicInt::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAtomicInt::event_map->bigin();
	if ((itr = DummyQAtomicInt::event_map->find(str)) == DummyQAtomicInt::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAtomicInt::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAtomicInt::slot_map->bigin();
	if ((itr = DummyQAtomicInt::slot_map->find(str)) == DummyQAtomicInt::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQAtomicInt::connection(QObject *o)
{
	return;
}

KQAtomicInt::KQAtomicInt(int value) : QAtomicInt(value)
{
	self = NULL;
	dummy = new DummyQAtomicInt();
	dummy->connection((QObject*)this);
}

KMETHOD QAtomicInt_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAtomicInt *qp = RawPtr_to(KQAtomicInt *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAtomicInt]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAtomicInt]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAtomicInt_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAtomicInt *qp = RawPtr_to(KQAtomicInt *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAtomicInt]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAtomicInt]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAtomicInt_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAtomicInt *qp = (KQAtomicInt *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAtomicInt_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQAtomicInt *qp = (KQAtomicInt *)p->rawptr;
		(void)qp;
	}
}

static int QAtomicInt_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QAtomicInt*>(p1->rawptr) == *static_cast<QAtomicInt*>(p2->rawptr) ? 0 : 1);
}

void KQAtomicInt::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQAtomicInt(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAtomicInt";
	cdef->free = QAtomicInt_free;
	cdef->reftrace = QAtomicInt_reftrace;
	cdef->compareTo = QAtomicInt_compareTo;
}


