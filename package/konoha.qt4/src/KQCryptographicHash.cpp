//QCryptographicHash QCryptographicHash.new(int method);
KMETHOD QCryptographicHash_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCryptographicHash::Algorithm method = Int_to(QCryptographicHash::Algorithm, sfp[1]);
	KQCryptographicHash *ret_v = new KQCryptographicHash(method);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QCryptographicHash.addData(String data, int length);
KMETHOD QCryptographicHash_addData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCryptographicHash *  qp = RawPtr_to(QCryptographicHash *, sfp[0]);
	if (qp != NULL) {
		const char*  data = RawPtr_to(const char*, sfp[1]);
		int length = Int_to(int, sfp[2]);
		qp->addData(data, length);
	}
	RETURNvoid_();
}

/*
//void QCryptographicHash.addData(QByteArray data);
KMETHOD QCryptographicHash_addData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCryptographicHash *  qp = RawPtr_to(QCryptographicHash *, sfp[0]);
	if (qp != NULL) {
		const QByteArray  data = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->addData(data);
	}
	RETURNvoid_();
}
*/
//void QCryptographicHash.reset();
KMETHOD QCryptographicHash_reset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCryptographicHash *  qp = RawPtr_to(QCryptographicHash *, sfp[0]);
	if (qp != NULL) {
		qp->reset();
	}
	RETURNvoid_();
}

//QByteArray QCryptographicHash.result();
KMETHOD QCryptographicHash_result(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCryptographicHash *  qp = RawPtr_to(QCryptographicHash *, sfp[0]);
	if (qp != NULL) {
		QByteArray ret_v = qp->result();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QCryptographicHash.hash(QByteArray data, int method);
KMETHOD QCryptographicHash_hash(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCryptographicHash *  qp = RawPtr_to(QCryptographicHash *, sfp[0]);
	if (qp != NULL) {
		const QByteArray  data = *RawPtr_to(const QByteArray *, sfp[1]);
		QCryptographicHash::Algorithm method = Int_to(QCryptographicHash::Algorithm, sfp[2]);
		QByteArray ret_v = qp->hash(data, method);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQCryptographicHash::DummyQCryptographicHash()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQCryptographicHash::setSelf(knh_RawPtr_t *ptr)
{
	DummyQCryptographicHash::self = ptr;
}

bool DummyQCryptographicHash::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQCryptographicHash::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCryptographicHash::event_map->bigin();
	if ((itr = DummyQCryptographicHash::event_map->find(str)) == DummyQCryptographicHash::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQCryptographicHash::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCryptographicHash::slot_map->bigin();
	if ((itr = DummyQCryptographicHash::slot_map->find(str)) == DummyQCryptographicHash::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQCryptographicHash::connection(QObject *o)
{
	return;
}

KQCryptographicHash::KQCryptographicHash(QCryptographicHash::Algorithm method) : QCryptographicHash(method)
{
	self = NULL;
	dummy = new DummyQCryptographicHash();
	dummy->connection((QObject*)this);
}

KMETHOD QCryptographicHash_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCryptographicHash *qp = RawPtr_to(KQCryptographicHash *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QCryptographicHash]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCryptographicHash]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QCryptographicHash_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCryptographicHash *qp = RawPtr_to(KQCryptographicHash *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QCryptographicHash]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCryptographicHash]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QCryptographicHash_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQCryptographicHash *qp = (KQCryptographicHash *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QCryptographicHash_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQCryptographicHash *qp = (KQCryptographicHash *)p->rawptr;
		(void)qp;
	}
}

static int QCryptographicHash_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQCryptographicHash::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQCryptographicHash(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QCryptographicHash";
	cdef->free = QCryptographicHash_free;
	cdef->reftrace = QCryptographicHash_reftrace;
	cdef->compareTo = QCryptographicHash_compareTo;
}

static knh_IntData_t QCryptographicHashConstInt[] = {
	{"Md4", QCryptographicHash::Md4},
	{"Md5", QCryptographicHash::Md5},
	{"Sha1", QCryptographicHash::Sha1},
	{NULL, 0}
};

DEFAPI(void) constQCryptographicHash(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QCryptographicHashConstInt);
}

