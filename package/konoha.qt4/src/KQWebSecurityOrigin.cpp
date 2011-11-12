//QWebSecurityOrigin QWebSecurityOrigin.new(QWebSecurityOrigin other);
KMETHOD QWebSecurityOrigin_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QWebSecurityOrigin  other = *RawPtr_to(const QWebSecurityOrigin *, sfp[1]);
	KQWebSecurityOrigin *ret_v = new KQWebSecurityOrigin(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QWebSecurityOrigin.getDatabaseQuota();
KMETHOD QWebSecurityOrigin_getDatabaseQuota(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSecurityOrigin *  qp = RawPtr_to(QWebSecurityOrigin *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->databaseQuota();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWebSecurityOrigin.databaseUsage();
KMETHOD QWebSecurityOrigin_databaseUsage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSecurityOrigin *  qp = RawPtr_to(QWebSecurityOrigin *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->databaseUsage();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QWebDatabase> QWebSecurityOrigin.databases();
KMETHOD QWebSecurityOrigin_databases(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSecurityOrigin *  qp = RawPtr_to(QWebSecurityOrigin *, sfp[0]);
	if (qp) {
		QList<QWebDatabase> ret_v = qp->databases();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QWebDatabase"));
		for (int n = 0; n < list_size; n++) {
			QWebDatabase *ret_v_ = new QWebDatabase(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//String QWebSecurityOrigin.host();
KMETHOD QWebSecurityOrigin_host(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSecurityOrigin *  qp = RawPtr_to(QWebSecurityOrigin *, sfp[0]);
	if (qp) {
		QString ret_v = qp->host();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWebSecurityOrigin.port();
KMETHOD QWebSecurityOrigin_port(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSecurityOrigin *  qp = RawPtr_to(QWebSecurityOrigin *, sfp[0]);
	if (qp) {
		int ret_v = qp->port();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QWebSecurityOrigin.scheme();
KMETHOD QWebSecurityOrigin_scheme(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSecurityOrigin *  qp = RawPtr_to(QWebSecurityOrigin *, sfp[0]);
	if (qp) {
		QString ret_v = qp->scheme();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebSecurityOrigin.setDatabaseQuota(int quota);
KMETHOD QWebSecurityOrigin_setDatabaseQuota(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSecurityOrigin *  qp = RawPtr_to(QWebSecurityOrigin *, sfp[0]);
	if (qp) {
		qint64 quota = Int_to(qint64, sfp[1]);
		qp->setDatabaseQuota(quota);
	}
	RETURNvoid_();
}

//void QWebSecurityOrigin.addLocalScheme(String scheme);
KMETHOD QWebSecurityOrigin_addLocalScheme(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString scheme = String_to(const QString, sfp[1]);
		QWebSecurityOrigin::addLocalScheme(scheme);
	}
	RETURNvoid_();
}

//Array<QWebSecurityOrigin> QWebSecurityOrigin.allOrigins();
KMETHOD QWebSecurityOrigin_allOrigins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QList<QWebSecurityOrigin> ret_v = QWebSecurityOrigin::allOrigins();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QWebSecurityOrigin"));
		for (int n = 0; n < list_size; n++) {
			QWebSecurityOrigin *ret_v_ = new QWebSecurityOrigin(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//void QWebSecurityOrigin.removeLocalScheme(String scheme);
KMETHOD QWebSecurityOrigin_removeLocalScheme(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString scheme = String_to(const QString, sfp[1]);
		QWebSecurityOrigin::removeLocalScheme(scheme);
	}
	RETURNvoid_();
}

//Array<String> QWebSecurityOrigin.parents();
KMETHOD QWebSecurityOrigin_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebSecurityOrigin *qp = RawPtr_to(QWebSecurityOrigin*, sfp[0]);
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

DummyQWebSecurityOrigin::DummyQWebSecurityOrigin()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQWebSecurityOrigin::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWebSecurityOrigin::self = ptr;
}

bool DummyQWebSecurityOrigin::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQWebSecurityOrigin::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebSecurityOrigin::event_map->bigin();
	if ((itr = DummyQWebSecurityOrigin::event_map->find(str)) == DummyQWebSecurityOrigin::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWebSecurityOrigin::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebSecurityOrigin::slot_map->bigin();
	if ((itr = DummyQWebSecurityOrigin::slot_map->find(str)) == DummyQWebSecurityOrigin::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQWebSecurityOrigin::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQWebSecurityOrigin::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQWebSecurityOrigin::connection(QObject *o)
{
	QWebSecurityOrigin *p = dynamic_cast<QWebSecurityOrigin*>(o);
	if (p != NULL) {
	}
}

KQWebSecurityOrigin::KQWebSecurityOrigin(const QWebSecurityOrigin other) : QWebSecurityOrigin(other)
{
	self = NULL;
	dummy = new DummyQWebSecurityOrigin();
}

KMETHOD QWebSecurityOrigin_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebSecurityOrigin *qp = RawPtr_to(KQWebSecurityOrigin *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWebSecurityOrigin]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebSecurityOrigin]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWebSecurityOrigin_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebSecurityOrigin *qp = RawPtr_to(KQWebSecurityOrigin *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWebSecurityOrigin]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebSecurityOrigin]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWebSecurityOrigin_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWebSecurityOrigin *qp = (KQWebSecurityOrigin *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWebSecurityOrigin_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQWebSecurityOrigin *qp = (KQWebSecurityOrigin *)p->rawptr;
//		KQWebSecurityOrigin *qp = static_cast<KQWebSecurityOrigin*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWebSecurityOrigin_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWebSecurityOrigin::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQWebSecurityOrigin(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWebSecurityOrigin";
	cdef->free = QWebSecurityOrigin_free;
	cdef->reftrace = QWebSecurityOrigin_reftrace;
	cdef->compareTo = QWebSecurityOrigin_compareTo;
}


