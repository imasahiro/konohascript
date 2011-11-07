//QHostInfo QHostInfo.new(int id);
KMETHOD QHostInfo_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int id = Int_to(int, sfp[1]);
	KQHostInfo *ret_v = new KQHostInfo(id);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QHostInfo QHostInfo.new(QHostInfo other);
KMETHOD QHostInfo_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QHostInfo  other = *RawPtr_to(const QHostInfo *, sfp[1]);
	KQHostInfo *ret_v = new KQHostInfo(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//Array<QHostAddress> QHostInfo.getAddresses();
KMETHOD QHostInfo_getAddresses(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostInfo *  qp = RawPtr_to(QHostInfo *, sfp[0]);
	if (qp) {
		QList<QHostAddress> ret_v = qp->addresses();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QHostAddress"));
		for (int n = 0; n < list_size; n++) {
			QHostAddress *ret_v_ = new QHostAddress(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//int QHostInfo.getError();
KMETHOD QHostInfo_getError(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostInfo *  qp = RawPtr_to(QHostInfo *, sfp[0]);
	if (qp) {
		QHostInfo::HostInfoError ret_v = qp->error();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QHostInfo.getErrorString();
KMETHOD QHostInfo_getErrorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostInfo *  qp = RawPtr_to(QHostInfo *, sfp[0]);
	if (qp) {
		QString ret_v = qp->errorString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QHostInfo.getHostName();
KMETHOD QHostInfo_getHostName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostInfo *  qp = RawPtr_to(QHostInfo *, sfp[0]);
	if (qp) {
		QString ret_v = qp->hostName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QHostInfo.getLookupId();
KMETHOD QHostInfo_getLookupId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostInfo *  qp = RawPtr_to(QHostInfo *, sfp[0]);
	if (qp) {
		int ret_v = qp->lookupId();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QHostInfo.setAddresses(Array<QHostAddress> addresses);
KMETHOD QHostInfo_setAddresses(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostInfo *  qp = RawPtr_to(QHostInfo *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QHostAddress> addresses;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			addresses.append(*(QHostAddress*)p->rawptr);
		}
		qp->setAddresses(addresses);
	}
	RETURNvoid_();
}

//void QHostInfo.setError(int error);
KMETHOD QHostInfo_setError(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostInfo *  qp = RawPtr_to(QHostInfo *, sfp[0]);
	if (qp) {
		QHostInfo::HostInfoError error = Int_to(QHostInfo::HostInfoError, sfp[1]);
		qp->setError(error);
	}
	RETURNvoid_();
}

//void QHostInfo.setErrorString(String str);
KMETHOD QHostInfo_setErrorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostInfo *  qp = RawPtr_to(QHostInfo *, sfp[0]);
	if (qp) {
		const QString str = String_to(const QString, sfp[1]);
		qp->setErrorString(str);
	}
	RETURNvoid_();
}

//void QHostInfo.setHostName(String hostName);
KMETHOD QHostInfo_setHostName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostInfo *  qp = RawPtr_to(QHostInfo *, sfp[0]);
	if (qp) {
		const QString hostName = String_to(const QString, sfp[1]);
		qp->setHostName(hostName);
	}
	RETURNvoid_();
}

//void QHostInfo.setLookupId(int id);
KMETHOD QHostInfo_setLookupId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostInfo *  qp = RawPtr_to(QHostInfo *, sfp[0]);
	if (qp) {
		int id = Int_to(int, sfp[1]);
		qp->setLookupId(id);
	}
	RETURNvoid_();
}

//void QHostInfo.abortHostLookup(int id);
KMETHOD QHostInfo_abortHostLookup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int id = Int_to(int, sfp[1]);
		QHostInfo::abortHostLookup(id);
	}
	RETURNvoid_();
}

//QHostInfo QHostInfo.fromName(String name);
KMETHOD QHostInfo_fromName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString name = String_to(const QString, sfp[1]);
		QHostInfo ret_v = QHostInfo::fromName(name);
		QHostInfo *ret_v_ = new QHostInfo(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QHostInfo.localDomainName();
KMETHOD QHostInfo_localDomainName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QString ret_v = QHostInfo::localDomainName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QHostInfo.localHostName();
KMETHOD QHostInfo_localHostName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QString ret_v = QHostInfo::localHostName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QHostInfo.lookupHost(String name, QObject receiver, String member);
KMETHOD QHostInfo_lookupHost(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString name = String_to(const QString, sfp[1]);
		QObject*  receiver = RawPtr_to(QObject*, sfp[2]);
		const char*  member = RawPtr_to(const char*, sfp[3]);
		int ret_v = QHostInfo::lookupHost(name, receiver, member);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<String> QHostInfo.parents();
KMETHOD QHostInfo_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostInfo *qp = RawPtr_to(QHostInfo*, sfp[0]);
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

DummyQHostInfo::DummyQHostInfo()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQHostInfo::setSelf(knh_RawPtr_t *ptr)
{
	DummyQHostInfo::self = ptr;
}

bool DummyQHostInfo::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQHostInfo::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHostInfo::event_map->bigin();
	if ((itr = DummyQHostInfo::event_map->find(str)) == DummyQHostInfo::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQHostInfo::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHostInfo::slot_map->bigin();
	if ((itr = DummyQHostInfo::slot_map->find(str)) == DummyQHostInfo::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQHostInfo::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQHostInfo::connection(QObject *o)
{
	QHostInfo *p = dynamic_cast<QHostInfo*>(o);
	if (p != NULL) {
	}
}

KQHostInfo::KQHostInfo(int id) : QHostInfo(id)
{
	self = NULL;
	dummy = new DummyQHostInfo();
}

KMETHOD QHostInfo_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHostInfo *qp = RawPtr_to(KQHostInfo *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QHostInfo]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHostInfo]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QHostInfo_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHostInfo *qp = RawPtr_to(KQHostInfo *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QHostInfo]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHostInfo]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QHostInfo_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQHostInfo *qp = (KQHostInfo *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QHostInfo_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQHostInfo *qp = (KQHostInfo *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QHostInfo_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQHostInfo::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QHostInfoConstInt[] = {
	{"NoError", QHostInfo::NoError},
	{"HostNotFound", QHostInfo::HostNotFound},
	{"UnknownError", QHostInfo::UnknownError},
	{NULL, 0}
};

DEFAPI(void) constQHostInfo(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QHostInfoConstInt);
}


DEFAPI(void) defQHostInfo(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QHostInfo";
	cdef->free = QHostInfo_free;
	cdef->reftrace = QHostInfo_reftrace;
	cdef->compareTo = QHostInfo_compareTo;
}


