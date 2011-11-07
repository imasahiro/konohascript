//QSharedMemory QSharedMemory.new(String key, QObject parent);
KMETHOD QSharedMemory_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString key = String_to(const QString, sfp[1]);
	QObject*  parent = RawPtr_to(QObject*, sfp[2]);
	KQSharedMemory *ret_v = new KQSharedMemory(key, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QSharedMemory QSharedMemory.new(QObject parent);
KMETHOD QSharedMemory_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQSharedMemory *ret_v = new KQSharedMemory(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QSharedMemory.attach(int mode);
KMETHOD QSharedMemory_attach(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSharedMemory *  qp = RawPtr_to(QSharedMemory *, sfp[0]);
	if (qp) {
		QSharedMemory::AccessMode mode = Int_to(QSharedMemory::AccessMode, sfp[1]);
		bool ret_v = qp->attach(mode);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QSharedMemory.constData();
KMETHOD QSharedMemory_constData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSharedMemory *  qp = RawPtr_to(QSharedMemory *, sfp[0]);
	if (qp) {
		const void* ret_v = qp->constData();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (void*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QSharedMemory.create(int size, int mode);
KMETHOD QSharedMemory_create(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSharedMemory *  qp = RawPtr_to(QSharedMemory *, sfp[0]);
	if (qp) {
		int size = Int_to(int, sfp[1]);
		QSharedMemory::AccessMode mode = Int_to(QSharedMemory::AccessMode, sfp[2]);
		bool ret_v = qp->create(size, mode);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QSharedMemory.data();
KMETHOD QSharedMemory_data(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSharedMemory *  qp = RawPtr_to(QSharedMemory *, sfp[0]);
	if (qp) {
		void* ret_v = qp->data();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (void*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//void QSharedMemory.data();
KMETHOD QSharedMemory_data(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSharedMemory *  qp = RawPtr_to(QSharedMemory *, sfp[0]);
	if (qp) {
		const void* ret_v = qp->data();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (void*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//boolean QSharedMemory.detach();
KMETHOD QSharedMemory_detach(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSharedMemory *  qp = RawPtr_to(QSharedMemory *, sfp[0]);
	if (qp) {
		bool ret_v = qp->detach();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QSharedMemory.error();
KMETHOD QSharedMemory_error(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSharedMemory *  qp = RawPtr_to(QSharedMemory *, sfp[0]);
	if (qp) {
		QSharedMemory::SharedMemoryError ret_v = qp->error();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QSharedMemory.errorString();
KMETHOD QSharedMemory_errorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSharedMemory *  qp = RawPtr_to(QSharedMemory *, sfp[0]);
	if (qp) {
		QString ret_v = qp->errorString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QSharedMemory.isAttached();
KMETHOD QSharedMemory_isAttached(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSharedMemory *  qp = RawPtr_to(QSharedMemory *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isAttached();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QSharedMemory.getKey();
KMETHOD QSharedMemory_getKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSharedMemory *  qp = RawPtr_to(QSharedMemory *, sfp[0]);
	if (qp) {
		QString ret_v = qp->key();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QSharedMemory.lock();
KMETHOD QSharedMemory_lock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSharedMemory *  qp = RawPtr_to(QSharedMemory *, sfp[0]);
	if (qp) {
		bool ret_v = qp->lock();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QSharedMemory.setKey(String key);
KMETHOD QSharedMemory_setKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSharedMemory *  qp = RawPtr_to(QSharedMemory *, sfp[0]);
	if (qp) {
		const QString key = String_to(const QString, sfp[1]);
		qp->setKey(key);
	}
	RETURNvoid_();
}

//int QSharedMemory.size();
KMETHOD QSharedMemory_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSharedMemory *  qp = RawPtr_to(QSharedMemory *, sfp[0]);
	if (qp) {
		int ret_v = qp->size();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QSharedMemory.unlock();
KMETHOD QSharedMemory_unlock(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSharedMemory *  qp = RawPtr_to(QSharedMemory *, sfp[0]);
	if (qp) {
		bool ret_v = qp->unlock();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQSharedMemory::DummyQSharedMemory()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSharedMemory::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSharedMemory::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQSharedMemory::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQSharedMemory::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSharedMemory::event_map->bigin();
	if ((itr = DummyQSharedMemory::event_map->find(str)) == DummyQSharedMemory::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSharedMemory::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSharedMemory::slot_map->bigin();
	if ((itr = DummyQSharedMemory::slot_map->find(str)) == DummyQSharedMemory::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQSharedMemory::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQObject::reftrace(ctx, p, tail_);
}

void DummyQSharedMemory::connection(QObject *o)
{
	QSharedMemory *p = dynamic_cast<QSharedMemory*>(o);
	if (p != NULL) {
	}
	DummyQObject::connection(o);
}

KQSharedMemory::KQSharedMemory(const QString key, QObject* parent) : QSharedMemory(key, parent)
{
	self = NULL;
	dummy = new DummyQSharedMemory();
	dummy->connection((QObject*)this);
}

KMETHOD QSharedMemory_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSharedMemory *qp = RawPtr_to(KQSharedMemory *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSharedMemory]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSharedMemory]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSharedMemory_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSharedMemory *qp = RawPtr_to(KQSharedMemory *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSharedMemory]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSharedMemory]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSharedMemory_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSharedMemory *qp = (KQSharedMemory *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSharedMemory_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQSharedMemory *qp = (KQSharedMemory *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSharedMemory_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSharedMemory::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQSharedMemory::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QSharedMemory::event(event);
		return false;
	}
	return true;
}

static knh_IntData_t QSharedMemoryConstInt[] = {
	{"ReadOnly", QSharedMemory::ReadOnly},
	{"ReadWrite", QSharedMemory::ReadWrite},
	{"NoError", QSharedMemory::NoError},
	{"PermissionDenied", QSharedMemory::PermissionDenied},
	{"InvalidSize", QSharedMemory::InvalidSize},
	{"KeyError", QSharedMemory::KeyError},
	{"AlreadyExists", QSharedMemory::AlreadyExists},
	{"NotFound", QSharedMemory::NotFound},
	{"LockError", QSharedMemory::LockError},
	{"OutOfResources", QSharedMemory::OutOfResources},
	{"UnknownError", QSharedMemory::UnknownError},
	{NULL, 0}
};

DEFAPI(void) constQSharedMemory(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QSharedMemoryConstInt);
}


DEFAPI(void) defQSharedMemory(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSharedMemory";
	cdef->free = QSharedMemory_free;
	cdef->reftrace = QSharedMemory_reftrace;
	cdef->compareTo = QSharedMemory_compareTo;
}


