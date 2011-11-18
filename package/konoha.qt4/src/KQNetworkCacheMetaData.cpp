//QNetworkCacheMetaData QNetworkCacheMetaData.new();
KMETHOD QNetworkCacheMetaData_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkCacheMetaData *ret_v = new KQNetworkCacheMetaData();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QNetworkCacheMetaData QNetworkCacheMetaData.new(QNetworkCacheMetaData other);
KMETHOD QNetworkCacheMetaData_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QNetworkCacheMetaData  other = *RawPtr_to(const QNetworkCacheMetaData *, sfp[1]);
	KQNetworkCacheMetaData *ret_v = new KQNetworkCacheMetaData(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QDateTime QNetworkCacheMetaData.getExpirationDate();
KMETHOD QNetworkCacheMetaData_getExpirationDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCacheMetaData *  qp = RawPtr_to(QNetworkCacheMetaData *, sfp[0]);
	if (qp) {
		QDateTime ret_v = qp->expirationDate();
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QNetworkCacheMetaData.getLastModified();
KMETHOD QNetworkCacheMetaData_getLastModified(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCacheMetaData *  qp = RawPtr_to(QNetworkCacheMetaData *, sfp[0]);
	if (qp) {
		QDateTime ret_v = qp->lastModified();
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QNetworkCacheMetaData.getSaveToDisk();
KMETHOD QNetworkCacheMetaData_getSaveToDisk(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCacheMetaData *  qp = RawPtr_to(QNetworkCacheMetaData *, sfp[0]);
	if (qp) {
		bool ret_v = qp->saveToDisk();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QNetworkCacheMetaData.setExpirationDate(QDateTime dateTime);
KMETHOD QNetworkCacheMetaData_setExpirationDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCacheMetaData *  qp = RawPtr_to(QNetworkCacheMetaData *, sfp[0]);
	if (qp) {
		const QDateTime  dateTime = *RawPtr_to(const QDateTime *, sfp[1]);
		qp->setExpirationDate(dateTime);
	}
	RETURNvoid_();
}

//void QNetworkCacheMetaData.setLastModified(QDateTime dateTime);
KMETHOD QNetworkCacheMetaData_setLastModified(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCacheMetaData *  qp = RawPtr_to(QNetworkCacheMetaData *, sfp[0]);
	if (qp) {
		const QDateTime  dateTime = *RawPtr_to(const QDateTime *, sfp[1]);
		qp->setLastModified(dateTime);
	}
	RETURNvoid_();
}

//void QNetworkCacheMetaData.setSaveToDisk(boolean allow);
KMETHOD QNetworkCacheMetaData_setSaveToDisk(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCacheMetaData *  qp = RawPtr_to(QNetworkCacheMetaData *, sfp[0]);
	if (qp) {
		bool allow = Boolean_to(bool, sfp[1]);
		qp->setSaveToDisk(allow);
	}
	RETURNvoid_();
}

//void QNetworkCacheMetaData.setUrl(QUrl url);
KMETHOD QNetworkCacheMetaData_setUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCacheMetaData *  qp = RawPtr_to(QNetworkCacheMetaData *, sfp[0]);
	if (qp) {
		const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
		qp->setUrl(url);
	}
	RETURNvoid_();
}

//QUrl QNetworkCacheMetaData.getUrl();
KMETHOD QNetworkCacheMetaData_getUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCacheMetaData *  qp = RawPtr_to(QNetworkCacheMetaData *, sfp[0]);
	if (qp) {
		QUrl ret_v = qp->url();
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QNetworkCacheMetaData.parents();
KMETHOD QNetworkCacheMetaData_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCacheMetaData *qp = RawPtr_to(QNetworkCacheMetaData*, sfp[0]);
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

DummyQNetworkCacheMetaData::DummyQNetworkCacheMetaData()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQNetworkCacheMetaData::~DummyQNetworkCacheMetaData()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQNetworkCacheMetaData::setSelf(knh_RawPtr_t *ptr)
{
	DummyQNetworkCacheMetaData::self = ptr;
}

bool DummyQNetworkCacheMetaData::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQNetworkCacheMetaData::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkCacheMetaData::event_map->bigin();
	if ((itr = DummyQNetworkCacheMetaData::event_map->find(str)) == DummyQNetworkCacheMetaData::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQNetworkCacheMetaData::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkCacheMetaData::slot_map->bigin();
	if ((itr = DummyQNetworkCacheMetaData::slot_map->find(str)) == DummyQNetworkCacheMetaData::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQNetworkCacheMetaData::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQNetworkCacheMetaData::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQNetworkCacheMetaData::connection(QObject *o)
{
	QNetworkCacheMetaData *p = dynamic_cast<QNetworkCacheMetaData*>(o);
	if (p != NULL) {
	}
}

KQNetworkCacheMetaData::KQNetworkCacheMetaData() : QNetworkCacheMetaData()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQNetworkCacheMetaData();
}

KQNetworkCacheMetaData::~KQNetworkCacheMetaData()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QNetworkCacheMetaData_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkCacheMetaData *qp = RawPtr_to(KQNetworkCacheMetaData *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkCacheMetaData]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkCacheMetaData]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QNetworkCacheMetaData_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkCacheMetaData *qp = RawPtr_to(KQNetworkCacheMetaData *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkCacheMetaData]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkCacheMetaData]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QNetworkCacheMetaData_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQNetworkCacheMetaData *qp = (KQNetworkCacheMetaData *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QNetworkCacheMetaData*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QNetworkCacheMetaData_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQNetworkCacheMetaData *qp = (KQNetworkCacheMetaData *)p->rawptr;
		KQNetworkCacheMetaData *qp = static_cast<KQNetworkCacheMetaData*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QNetworkCacheMetaData_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QNetworkCacheMetaData*>(p1->rawptr) == *static_cast<QNetworkCacheMetaData*>(p2->rawptr) ? 0 : 1);
}

void KQNetworkCacheMetaData::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQNetworkCacheMetaData(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkCacheMetaData";
	cdef->free = QNetworkCacheMetaData_free;
	cdef->reftrace = QNetworkCacheMetaData_reftrace;
	cdef->compareTo = QNetworkCacheMetaData_compareTo;
}


