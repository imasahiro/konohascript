//QNetworkCookie QNetworkCookie.new(QByteArray name, QByteArray value);
KMETHOD QNetworkCookie_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QByteArray  name = *RawPtr_to(const QByteArray *, sfp[1]);
	const QByteArray  value = *RawPtr_to(const QByteArray *, sfp[2]);
	KQNetworkCookie *ret_v = new KQNetworkCookie(name, value);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QNetworkCookie QNetworkCookie.new(QNetworkCookie other);
KMETHOD QNetworkCookie_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QNetworkCookie  other = *RawPtr_to(const QNetworkCookie *, sfp[1]);
	KQNetworkCookie *ret_v = new KQNetworkCookie(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//String QNetworkCookie.getDomain();
KMETHOD QNetworkCookie_getDomain(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookie *  qp = RawPtr_to(QNetworkCookie *, sfp[0]);
	if (qp) {
		QString ret_v = qp->domain();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QNetworkCookie.getExpirationDate();
KMETHOD QNetworkCookie_getExpirationDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookie *  qp = RawPtr_to(QNetworkCookie *, sfp[0]);
	if (qp) {
		QDateTime ret_v = qp->expirationDate();
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QNetworkCookie.isHttpOnly();
KMETHOD QNetworkCookie_isHttpOnly(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookie *  qp = RawPtr_to(QNetworkCookie *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isHttpOnly();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QNetworkCookie.isSecure();
KMETHOD QNetworkCookie_isSecure(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookie *  qp = RawPtr_to(QNetworkCookie *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSecure();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QNetworkCookie.isSessionCookie();
KMETHOD QNetworkCookie_isSessionCookie(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookie *  qp = RawPtr_to(QNetworkCookie *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSessionCookie();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QByteArray QNetworkCookie.getName();
KMETHOD QNetworkCookie_getName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookie *  qp = RawPtr_to(QNetworkCookie *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->name();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QNetworkCookie.getPath();
KMETHOD QNetworkCookie_getPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookie *  qp = RawPtr_to(QNetworkCookie *, sfp[0]);
	if (qp) {
		QString ret_v = qp->path();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QNetworkCookie.setDomain(String domain);
KMETHOD QNetworkCookie_setDomain(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookie *  qp = RawPtr_to(QNetworkCookie *, sfp[0]);
	if (qp) {
		const QString domain = String_to(const QString, sfp[1]);
		qp->setDomain(domain);
	}
	RETURNvoid_();
}

//void QNetworkCookie.setExpirationDate(QDateTime date);
KMETHOD QNetworkCookie_setExpirationDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookie *  qp = RawPtr_to(QNetworkCookie *, sfp[0]);
	if (qp) {
		const QDateTime  date = *RawPtr_to(const QDateTime *, sfp[1]);
		qp->setExpirationDate(date);
	}
	RETURNvoid_();
}

//void QNetworkCookie.setHttpOnly(boolean enable);
KMETHOD QNetworkCookie_setHttpOnly(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookie *  qp = RawPtr_to(QNetworkCookie *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setHttpOnly(enable);
	}
	RETURNvoid_();
}

//void QNetworkCookie.setName(QByteArray cookieName);
KMETHOD QNetworkCookie_setName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookie *  qp = RawPtr_to(QNetworkCookie *, sfp[0]);
	if (qp) {
		const QByteArray  cookieName = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->setName(cookieName);
	}
	RETURNvoid_();
}

//void QNetworkCookie.setPath(String path);
KMETHOD QNetworkCookie_setPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookie *  qp = RawPtr_to(QNetworkCookie *, sfp[0]);
	if (qp) {
		const QString path = String_to(const QString, sfp[1]);
		qp->setPath(path);
	}
	RETURNvoid_();
}

//void QNetworkCookie.setSecure(boolean enable);
KMETHOD QNetworkCookie_setSecure(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookie *  qp = RawPtr_to(QNetworkCookie *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setSecure(enable);
	}
	RETURNvoid_();
}

//void QNetworkCookie.setValue(QByteArray value);
KMETHOD QNetworkCookie_setValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookie *  qp = RawPtr_to(QNetworkCookie *, sfp[0]);
	if (qp) {
		const QByteArray  value = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->setValue(value);
	}
	RETURNvoid_();
}

//QByteArray QNetworkCookie.toRawForm(int form);
KMETHOD QNetworkCookie_toRawForm(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookie *  qp = RawPtr_to(QNetworkCookie *, sfp[0]);
	if (qp) {
		QNetworkCookie::RawForm form = Int_to(QNetworkCookie::RawForm, sfp[1]);
		QByteArray ret_v = qp->toRawForm(form);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QNetworkCookie.getValue();
KMETHOD QNetworkCookie_getValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookie *  qp = RawPtr_to(QNetworkCookie *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->value();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QNetworkCookie> QNetworkCookie.parseCookies(QByteArray cookieString);
KMETHOD QNetworkCookie_parseCookies(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QByteArray  cookieString = *RawPtr_to(const QByteArray *, sfp[1]);
		QList<QNetworkCookie> ret_v = QNetworkCookie::parseCookies(cookieString);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QNetworkCookie"));
		for (int n = 0; n < list_size; n++) {
			QNetworkCookie *ret_v_ = new QNetworkCookie(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//Array<String> QNetworkCookie.parents();
KMETHOD QNetworkCookie_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkCookie *qp = RawPtr_to(QNetworkCookie*, sfp[0]);
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

DummyQNetworkCookie::DummyQNetworkCookie()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQNetworkCookie::setSelf(knh_RawPtr_t *ptr)
{
	DummyQNetworkCookie::self = ptr;
}

bool DummyQNetworkCookie::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQNetworkCookie::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkCookie::event_map->bigin();
	if ((itr = DummyQNetworkCookie::event_map->find(str)) == DummyQNetworkCookie::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQNetworkCookie::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkCookie::slot_map->bigin();
	if ((itr = DummyQNetworkCookie::slot_map->find(str)) == DummyQNetworkCookie::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQNetworkCookie::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQNetworkCookie::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQNetworkCookie::connection(QObject *o)
{
	QNetworkCookie *p = dynamic_cast<QNetworkCookie*>(o);
	if (p != NULL) {
	}
}

KQNetworkCookie::KQNetworkCookie(const QByteArray name, const QByteArray value) : QNetworkCookie(name, value)
{
	self = NULL;
	dummy = new DummyQNetworkCookie();
}

KMETHOD QNetworkCookie_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkCookie *qp = RawPtr_to(KQNetworkCookie *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkCookie]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkCookie]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QNetworkCookie_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkCookie *qp = RawPtr_to(KQNetworkCookie *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkCookie]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkCookie]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QNetworkCookie_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQNetworkCookie *qp = (KQNetworkCookie *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QNetworkCookie_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQNetworkCookie *qp = (KQNetworkCookie *)p->rawptr;
//		KQNetworkCookie *qp = static_cast<KQNetworkCookie*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QNetworkCookie_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QNetworkCookie*>(p1->rawptr) == *static_cast<QNetworkCookie*>(p2->rawptr) ? 0 : 1);
}

void KQNetworkCookie::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QNetworkCookieConstInt[] = {
	{"NameAndValueOnly", QNetworkCookie::NameAndValueOnly},
	{"Full", QNetworkCookie::Full},
	{NULL, 0}
};

DEFAPI(void) constQNetworkCookie(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QNetworkCookieConstInt);
}


DEFAPI(void) defQNetworkCookie(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkCookie";
	cdef->free = QNetworkCookie_free;
	cdef->reftrace = QNetworkCookie_reftrace;
	cdef->compareTo = QNetworkCookie_compareTo;
}


