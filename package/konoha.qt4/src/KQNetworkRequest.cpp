//QNetworkRequest QNetworkRequest.new(QUrl url);
KMETHOD QNetworkRequest_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
	KQNetworkRequest *ret_v = new KQNetworkRequest(url);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QNetworkRequest QNetworkRequest.new(QNetworkRequest other);
KMETHOD QNetworkRequest_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QNetworkRequest  other = *RawPtr_to(const QNetworkRequest *, sfp[1]);
	KQNetworkRequest *ret_v = new KQNetworkRequest(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QVariant QNetworkRequest.getAttribute(int code, QVariant defaultValue);
KMETHOD QNetworkRequest_getAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkRequest *  qp = RawPtr_to(QNetworkRequest *, sfp[0]);
	if (qp) {
		QNetworkRequest::Attribute code = Int_to(QNetworkRequest::Attribute, sfp[1]);
		const QVariant  defaultValue = *RawPtr_to(const QVariant *, sfp[2]);
		QVariant ret_v = qp->attribute(code, defaultValue);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QNetworkRequest.hasRawHeader(QByteArray headerName);
KMETHOD QNetworkRequest_hasRawHeader(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkRequest *  qp = RawPtr_to(QNetworkRequest *, sfp[0]);
	if (qp) {
		const QByteArray  headerName = *RawPtr_to(const QByteArray *, sfp[1]);
		bool ret_v = qp->hasRawHeader(headerName);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QVariant QNetworkRequest.getHeader(int header);
KMETHOD QNetworkRequest_getHeader(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkRequest *  qp = RawPtr_to(QNetworkRequest *, sfp[0]);
	if (qp) {
		QNetworkRequest::KnownHeaders header = Int_to(QNetworkRequest::KnownHeaders, sfp[1]);
		QVariant ret_v = qp->header(header);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QObject QNetworkRequest.getOriginatingObject();
KMETHOD QNetworkRequest_getOriginatingObject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkRequest *  qp = RawPtr_to(QNetworkRequest *, sfp[0]);
	if (qp) {
		QObject* ret_v = qp->originatingObject();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QNetworkRequest.getPriority();
KMETHOD QNetworkRequest_getPriority(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkRequest *  qp = RawPtr_to(QNetworkRequest *, sfp[0]);
	if (qp) {
		QNetworkRequest::Priority ret_v = qp->priority();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QByteArray QNetworkRequest.getRawHeader(QByteArray headerName);
KMETHOD QNetworkRequest_getRawHeader(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkRequest *  qp = RawPtr_to(QNetworkRequest *, sfp[0]);
	if (qp) {
		const QByteArray  headerName = *RawPtr_to(const QByteArray *, sfp[1]);
		QByteArray ret_v = qp->rawHeader(headerName);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QByteArray> QNetworkRequest.rawHeaderList();
KMETHOD QNetworkRequest_rawHeaderList(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkRequest *  qp = RawPtr_to(QNetworkRequest *, sfp[0]);
	if (qp) {
		QList<QByteArray> ret_v = qp->rawHeaderList();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QByteArray"));
		for (int n = 0; n < list_size; n++) {
			QByteArray *ret_v_ = new QByteArray(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//void QNetworkRequest.setAttribute(int code, QVariant value);
KMETHOD QNetworkRequest_setAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkRequest *  qp = RawPtr_to(QNetworkRequest *, sfp[0]);
	if (qp) {
		QNetworkRequest::Attribute code = Int_to(QNetworkRequest::Attribute, sfp[1]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[2]);
		qp->setAttribute(code, value);
	}
	RETURNvoid_();
}

//void QNetworkRequest.setHeader(int header, QVariant value);
KMETHOD QNetworkRequest_setHeader(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkRequest *  qp = RawPtr_to(QNetworkRequest *, sfp[0]);
	if (qp) {
		QNetworkRequest::KnownHeaders header = Int_to(QNetworkRequest::KnownHeaders, sfp[1]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[2]);
		qp->setHeader(header, value);
	}
	RETURNvoid_();
}

//void QNetworkRequest.setOriginatingObject(QObject object);
KMETHOD QNetworkRequest_setOriginatingObject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkRequest *  qp = RawPtr_to(QNetworkRequest *, sfp[0]);
	if (qp) {
		QObject*  object = RawPtr_to(QObject*, sfp[1]);
		qp->setOriginatingObject(object);
	}
	RETURNvoid_();
}

//void QNetworkRequest.setPriority(int priority);
KMETHOD QNetworkRequest_setPriority(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkRequest *  qp = RawPtr_to(QNetworkRequest *, sfp[0]);
	if (qp) {
		QNetworkRequest::Priority priority = Int_to(QNetworkRequest::Priority, sfp[1]);
		qp->setPriority(priority);
	}
	RETURNvoid_();
}

//void QNetworkRequest.setRawHeader(QByteArray headerName, QByteArray headerValue);
KMETHOD QNetworkRequest_setRawHeader(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkRequest *  qp = RawPtr_to(QNetworkRequest *, sfp[0]);
	if (qp) {
		const QByteArray  headerName = *RawPtr_to(const QByteArray *, sfp[1]);
		const QByteArray  headerValue = *RawPtr_to(const QByteArray *, sfp[2]);
		qp->setRawHeader(headerName, headerValue);
	}
	RETURNvoid_();
}

//void QNetworkRequest.setSslConfiguration(QSslConfiguration config);
KMETHOD QNetworkRequest_setSslConfiguration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkRequest *  qp = RawPtr_to(QNetworkRequest *, sfp[0]);
	if (qp) {
		const QSslConfiguration  config = *RawPtr_to(const QSslConfiguration *, sfp[1]);
		qp->setSslConfiguration(config);
	}
	RETURNvoid_();
}

//void QNetworkRequest.setUrl(QUrl url);
KMETHOD QNetworkRequest_setUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkRequest *  qp = RawPtr_to(QNetworkRequest *, sfp[0]);
	if (qp) {
		const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
		qp->setUrl(url);
	}
	RETURNvoid_();
}

//QSslConfiguration QNetworkRequest.getSslConfiguration();
KMETHOD QNetworkRequest_getSslConfiguration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkRequest *  qp = RawPtr_to(QNetworkRequest *, sfp[0]);
	if (qp) {
		QSslConfiguration ret_v = qp->sslConfiguration();
		QSslConfiguration *ret_v_ = new QSslConfiguration(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QUrl QNetworkRequest.getUrl();
KMETHOD QNetworkRequest_getUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkRequest *  qp = RawPtr_to(QNetworkRequest *, sfp[0]);
	if (qp) {
		QUrl ret_v = qp->url();
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QNetworkRequest.parents();
KMETHOD QNetworkRequest_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkRequest *qp = RawPtr_to(QNetworkRequest*, sfp[0]);
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

DummyQNetworkRequest::DummyQNetworkRequest()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQNetworkRequest::setSelf(knh_RawPtr_t *ptr)
{
	DummyQNetworkRequest::self = ptr;
}

bool DummyQNetworkRequest::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQNetworkRequest::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkRequest::event_map->bigin();
	if ((itr = DummyQNetworkRequest::event_map->find(str)) == DummyQNetworkRequest::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQNetworkRequest::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkRequest::slot_map->bigin();
	if ((itr = DummyQNetworkRequest::slot_map->find(str)) == DummyQNetworkRequest::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQNetworkRequest::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQNetworkRequest::connection(QObject *o)
{
	QNetworkRequest *p = dynamic_cast<QNetworkRequest*>(o);
	if (p != NULL) {
	}
}

KQNetworkRequest::KQNetworkRequest(const QUrl url) : QNetworkRequest(url)
{
	self = NULL;
	dummy = new DummyQNetworkRequest();
}

KMETHOD QNetworkRequest_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkRequest *qp = RawPtr_to(KQNetworkRequest *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkRequest]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkRequest]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QNetworkRequest_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkRequest *qp = RawPtr_to(KQNetworkRequest *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkRequest]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkRequest]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QNetworkRequest_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQNetworkRequest *qp = (KQNetworkRequest *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QNetworkRequest_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQNetworkRequest *qp = (KQNetworkRequest *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QNetworkRequest_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QNetworkRequest*>(p1->rawptr) == *static_cast<QNetworkRequest*>(p2->rawptr) ? 0 : 1);
}

void KQNetworkRequest::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QNetworkRequestConstInt[] = {
	{"HttpStatusCodeAttribute", QNetworkRequest::HttpStatusCodeAttribute},
	{"HttpReasonPhraseAttribute", QNetworkRequest::HttpReasonPhraseAttribute},
	{"RedirectionTargetAttribute", QNetworkRequest::RedirectionTargetAttribute},
	{"ConnectionEncryptedAttribute", QNetworkRequest::ConnectionEncryptedAttribute},
	{"CacheLoadControlAttribute", QNetworkRequest::CacheLoadControlAttribute},
	{"CacheSaveControlAttribute", QNetworkRequest::CacheSaveControlAttribute},
	{"SourceIsFromCacheAttribute", QNetworkRequest::SourceIsFromCacheAttribute},
	{"DoNotBufferUploadDataAttribute", QNetworkRequest::DoNotBufferUploadDataAttribute},
	{"HttpPipeliningAllowedAttribute", QNetworkRequest::HttpPipeliningAllowedAttribute},
	{"HttpPipeliningWasUsedAttribute", QNetworkRequest::HttpPipeliningWasUsedAttribute},
	{"CustomVerbAttribute", QNetworkRequest::CustomVerbAttribute},
	{"CookieLoadControlAttribute", QNetworkRequest::CookieLoadControlAttribute},
	{"CookieSaveControlAttribute", QNetworkRequest::CookieSaveControlAttribute},
	{"AuthenticationReuseAttribute", QNetworkRequest::AuthenticationReuseAttribute},
	{"User", QNetworkRequest::User},
	{"UserMax", QNetworkRequest::UserMax},
	{"AlwaysNetwork", QNetworkRequest::AlwaysNetwork},
	{"PreferNetwork", QNetworkRequest::PreferNetwork},
	{"PreferCache", QNetworkRequest::PreferCache},
	{"AlwaysCache", QNetworkRequest::AlwaysCache},
	{"ContentTypeHeader", QNetworkRequest::ContentTypeHeader},
	{"ContentLengthHeader", QNetworkRequest::ContentLengthHeader},
	{"LocationHeader", QNetworkRequest::LocationHeader},
	{"LastModifiedHeader", QNetworkRequest::LastModifiedHeader},
	{"CookieHeader", QNetworkRequest::CookieHeader},
	{"SetCookieHeader", QNetworkRequest::SetCookieHeader},
	{"Automatic", QNetworkRequest::Automatic},
	{"Manual", QNetworkRequest::Manual},
	{"HighPriority", QNetworkRequest::HighPriority},
	{"NormalPriority", QNetworkRequest::NormalPriority},
	{"LowPriority", QNetworkRequest::LowPriority},
	{NULL, 0}
};

DEFAPI(void) constQNetworkRequest(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QNetworkRequestConstInt);
}


DEFAPI(void) defQNetworkRequest(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkRequest";
	cdef->free = QNetworkRequest_free;
	cdef->reftrace = QNetworkRequest_reftrace;
	cdef->compareTo = QNetworkRequest_compareTo;
}


