//QSystemSemaphore QSystemSemaphore.new(String key, int initialValue, int mode);
KMETHOD QSystemSemaphore_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString key = String_to(const QString, sfp[1]);
	int initialValue = Int_to(int, sfp[2]);
	QSystemSemaphore::AccessMode mode = Int_to(QSystemSemaphore::AccessMode, sfp[3]);
	KQSystemSemaphore *ret_v = new KQSystemSemaphore(key, initialValue, mode);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QSystemSemaphore.acquire();
KMETHOD QSystemSemaphore_acquire(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemSemaphore *  qp = RawPtr_to(QSystemSemaphore *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->acquire();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QSystemSemaphore.error();
KMETHOD QSystemSemaphore_error(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemSemaphore *  qp = RawPtr_to(QSystemSemaphore *, sfp[0]);
	if (qp != NULL) {
		QSystemSemaphore::SystemSemaphoreError ret_v = qp->error();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QSystemSemaphore.errorString();
KMETHOD QSystemSemaphore_errorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemSemaphore *  qp = RawPtr_to(QSystemSemaphore *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->errorString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QSystemSemaphore.getKey();
KMETHOD QSystemSemaphore_getKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemSemaphore *  qp = RawPtr_to(QSystemSemaphore *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->key();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QSystemSemaphore.release(int n);
KMETHOD QSystemSemaphore_release(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemSemaphore *  qp = RawPtr_to(QSystemSemaphore *, sfp[0]);
	if (qp != NULL) {
		int n = Int_to(int, sfp[1]);
		bool ret_v = qp->release(n);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QSystemSemaphore.setKey(String key, int initialValue, int mode);
KMETHOD QSystemSemaphore_setKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemSemaphore *  qp = RawPtr_to(QSystemSemaphore *, sfp[0]);
	if (qp != NULL) {
		const QString key = String_to(const QString, sfp[1]);
		int initialValue = Int_to(int, sfp[2]);
		QSystemSemaphore::AccessMode mode = Int_to(QSystemSemaphore::AccessMode, sfp[3]);
		qp->setKey(key, initialValue, mode);
	}
	RETURNvoid_();
}


DummyQSystemSemaphore::DummyQSystemSemaphore()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSystemSemaphore::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSystemSemaphore::self = ptr;
}

bool DummyQSystemSemaphore::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQSystemSemaphore::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSystemSemaphore::event_map->bigin();
	if ((itr = DummyQSystemSemaphore::event_map->find(str)) == DummyQSystemSemaphore::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSystemSemaphore::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSystemSemaphore::slot_map->bigin();
	if ((itr = DummyQSystemSemaphore::slot_map->find(str)) == DummyQSystemSemaphore::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQSystemSemaphore::connection(QObject *o)
{
	return;
}

KQSystemSemaphore::KQSystemSemaphore(const QString key, int initialValue, QSystemSemaphore::AccessMode mode) : QSystemSemaphore(key, initialValue, mode)
{
	self = NULL;
	dummy = new DummyQSystemSemaphore();
	dummy->connection((QObject*)this);
}

KMETHOD QSystemSemaphore_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSystemSemaphore *qp = RawPtr_to(KQSystemSemaphore *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSystemSemaphore]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSystemSemaphore]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSystemSemaphore_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSystemSemaphore *qp = RawPtr_to(KQSystemSemaphore *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSystemSemaphore]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSystemSemaphore]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSystemSemaphore_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSystemSemaphore *qp = (KQSystemSemaphore *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSystemSemaphore_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQSystemSemaphore *qp = (KQSystemSemaphore *)p->rawptr;
		(void)qp;
	}
}

static int QSystemSemaphore_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSystemSemaphore::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQSystemSemaphore(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSystemSemaphore";
	cdef->free = QSystemSemaphore_free;
	cdef->reftrace = QSystemSemaphore_reftrace;
	cdef->compareTo = QSystemSemaphore_compareTo;
}

static knh_IntData_t QSystemSemaphoreConstInt[] = {
	{"Open", QSystemSemaphore::Open},
	{"Create", QSystemSemaphore::Create},
	{"NoError", QSystemSemaphore::NoError},
	{"PermissionDenied", QSystemSemaphore::PermissionDenied},
	{"KeyError", QSystemSemaphore::KeyError},
	{"AlreadyExists", QSystemSemaphore::AlreadyExists},
	{"NotFound", QSystemSemaphore::NotFound},
	{"OutOfResources", QSystemSemaphore::OutOfResources},
	{"UnknownError", QSystemSemaphore::UnknownError},
	{NULL, 0}
};

DEFAPI(void) constQSystemSemaphore(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QSystemSemaphoreConstInt);
}

