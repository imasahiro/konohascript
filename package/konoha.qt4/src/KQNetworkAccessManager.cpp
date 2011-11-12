//QNetworkAccessManager QNetworkAccessManager.new(QObject parent);
KMETHOD QNetworkAccessManager_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQNetworkAccessManager *ret_v = new KQNetworkAccessManager(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QNetworkConfiguration QNetworkAccessManager.activeConfiguration();
KMETHOD QNetworkAccessManager_activeConfiguration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		QNetworkConfiguration ret_v = qp->activeConfiguration();
		QNetworkConfiguration *ret_v_ = new QNetworkConfiguration(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAbstractNetworkCache QNetworkAccessManager.getCache();
KMETHOD QNetworkAccessManager_getCache(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		QAbstractNetworkCache* ret_v = qp->cache();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractNetworkCache*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkConfiguration QNetworkAccessManager.getConfiguration();
KMETHOD QNetworkAccessManager_getConfiguration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		QNetworkConfiguration ret_v = qp->configuration();
		QNetworkConfiguration *ret_v_ = new QNetworkConfiguration(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkCookieJar QNetworkAccessManager.getCookieJar();
KMETHOD QNetworkAccessManager_getCookieJar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		QNetworkCookieJar* ret_v = qp->cookieJar();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QNetworkCookieJar*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkReply QNetworkAccessManager.deleteResource(QNetworkRequest request);
KMETHOD QNetworkAccessManager_deleteResource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		const QNetworkRequest  request = *RawPtr_to(const QNetworkRequest *, sfp[1]);
		QNetworkReply* ret_v = qp->deleteResource(request);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QNetworkReply*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkReply QNetworkAccessManager.get(QNetworkRequest request);
KMETHOD QNetworkAccessManager_get(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		const QNetworkRequest  request = *RawPtr_to(const QNetworkRequest *, sfp[1]);
		QNetworkReply* ret_v = qp->get(request);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QNetworkReply*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkReply QNetworkAccessManager.head(QNetworkRequest request);
KMETHOD QNetworkAccessManager_head(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		const QNetworkRequest  request = *RawPtr_to(const QNetworkRequest *, sfp[1]);
		QNetworkReply* ret_v = qp->head(request);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QNetworkReply*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QNetworkAccessManager.getNetworkAccessible();
KMETHOD QNetworkAccessManager_getNetworkAccessible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		QNetworkAccessManager::NetworkAccessibility ret_v = qp->networkAccessible();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QNetworkReply QNetworkAccessManager.post(QNetworkRequest request, QIODevice data);
KMETHOD QNetworkAccessManager_post(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		const QNetworkRequest  request = *RawPtr_to(const QNetworkRequest *, sfp[1]);
		QIODevice*  data = RawPtr_to(QIODevice*, sfp[2]);
		QNetworkReply* ret_v = qp->post(request, data);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QNetworkReply*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QNetworkReply QNetworkAccessManager.post(QNetworkRequest request, QByteArray data);
KMETHOD QNetworkAccessManager_post(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		const QNetworkRequest  request = *RawPtr_to(const QNetworkRequest *, sfp[1]);
		const QByteArray  data = *RawPtr_to(const QByteArray *, sfp[2]);
		QNetworkReply* ret_v = qp->post(request, data);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QNetworkReply*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QNetworkProxy QNetworkAccessManager.getProxy();
KMETHOD QNetworkAccessManager_getProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		QNetworkProxy ret_v = qp->proxy();
		QNetworkProxy *ret_v_ = new QNetworkProxy(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkProxyFactory QNetworkAccessManager.getProxyFactory();
KMETHOD QNetworkAccessManager_getProxyFactory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		QNetworkProxyFactory* ret_v = qp->proxyFactory();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QNetworkProxyFactory*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkReply QNetworkAccessManager.put(QNetworkRequest request, QIODevice data);
KMETHOD QNetworkAccessManager_put(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		const QNetworkRequest  request = *RawPtr_to(const QNetworkRequest *, sfp[1]);
		QIODevice*  data = RawPtr_to(QIODevice*, sfp[2]);
		QNetworkReply* ret_v = qp->put(request, data);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QNetworkReply*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QNetworkReply QNetworkAccessManager.put(QNetworkRequest request, QByteArray data);
KMETHOD QNetworkAccessManager_put(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		const QNetworkRequest  request = *RawPtr_to(const QNetworkRequest *, sfp[1]);
		const QByteArray  data = *RawPtr_to(const QByteArray *, sfp[2]);
		QNetworkReply* ret_v = qp->put(request, data);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QNetworkReply*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QNetworkReply QNetworkAccessManager.sendCustomRequest(QNetworkRequest request, QByteArray verb, QIODevice data);
KMETHOD QNetworkAccessManager_sendCustomRequest(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		const QNetworkRequest  request = *RawPtr_to(const QNetworkRequest *, sfp[1]);
		const QByteArray  verb = *RawPtr_to(const QByteArray *, sfp[2]);
		QIODevice*  data = RawPtr_to(QIODevice*, sfp[3]);
		QNetworkReply* ret_v = qp->sendCustomRequest(request, verb, data);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QNetworkReply*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QNetworkAccessManager.setCache(QAbstractNetworkCache cache);
KMETHOD QNetworkAccessManager_setCache(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		QAbstractNetworkCache*  cache = RawPtr_to(QAbstractNetworkCache*, sfp[1]);
		qp->setCache(cache);
	}
	RETURNvoid_();
}

//void QNetworkAccessManager.setConfiguration(QNetworkConfiguration config);
KMETHOD QNetworkAccessManager_setConfiguration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		const QNetworkConfiguration  config = *RawPtr_to(const QNetworkConfiguration *, sfp[1]);
		qp->setConfiguration(config);
	}
	RETURNvoid_();
}

//void QNetworkAccessManager.setCookieJar(QNetworkCookieJar cookieJar);
KMETHOD QNetworkAccessManager_setCookieJar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		QNetworkCookieJar*  cookieJar = RawPtr_to(QNetworkCookieJar*, sfp[1]);
		qp->setCookieJar(cookieJar);
	}
	RETURNvoid_();
}

//void QNetworkAccessManager.setNetworkAccessible(int accessible);
KMETHOD QNetworkAccessManager_setNetworkAccessible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		QNetworkAccessManager::NetworkAccessibility accessible = Int_to(QNetworkAccessManager::NetworkAccessibility, sfp[1]);
		qp->setNetworkAccessible(accessible);
	}
	RETURNvoid_();
}

//void QNetworkAccessManager.setProxy(QNetworkProxy proxy);
KMETHOD QNetworkAccessManager_setProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		const QNetworkProxy  proxy = *RawPtr_to(const QNetworkProxy *, sfp[1]);
		qp->setProxy(proxy);
	}
	RETURNvoid_();
}

//void QNetworkAccessManager.setProxyFactory(QNetworkProxyFactory factory);
KMETHOD QNetworkAccessManager_setProxyFactory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAccessManager *  qp = RawPtr_to(QNetworkAccessManager *, sfp[0]);
	if (qp) {
		QNetworkProxyFactory*  factory = RawPtr_to(QNetworkProxyFactory*, sfp[1]);
		qp->setProxyFactory(factory);
	}
	RETURNvoid_();
}


DummyQNetworkAccessManager::DummyQNetworkAccessManager()
{
	self = NULL;
	authentication_required_func = NULL;
	finished_func = NULL;
	network_accessible_changed_func = NULL;
	proxy_authentication_required_func = NULL;
	ssl_errors_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("authentication-required", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("finished", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("network-accessible-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("proxy-authentication-required", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("ssl-errors", NULL));
}

void DummyQNetworkAccessManager::setSelf(knh_RawPtr_t *ptr)
{
	DummyQNetworkAccessManager::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQNetworkAccessManager::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQNetworkAccessManager::authenticationRequiredSlot(QNetworkReply* reply, QAuthenticator* authenticator)
{
	if (authentication_required_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QNetworkReply, reply);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_RawPtr_t *p2 = new_QRawPtr(lctx, QAuthenticator, authenticator);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		knh_Func_invoke(lctx, authentication_required_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQNetworkAccessManager::finishedSlot(QNetworkReply* reply)
{
	if (finished_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QNetworkReply, reply);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, finished_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQNetworkAccessManager::networkAccessibleChangedSlot(QNetworkAccessManager::NetworkAccessibility accessible)
{
	if (network_accessible_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = accessible;
		knh_Func_invoke(lctx, network_accessible_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQNetworkAccessManager::proxyAuthenticationRequiredSlot(const QNetworkProxy proxy, QAuthenticator* authenticator)
{
	if (proxy_authentication_required_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QNetworkProxy, proxy);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_RawPtr_t *p2 = new_QRawPtr(lctx, QAuthenticator, authenticator);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		knh_Func_invoke(lctx, proxy_authentication_required_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQNetworkAccessManager::sslErrorsSlot(QNetworkReply* reply, const QList<QSslError> errors)
{
	if (ssl_errors_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QNetworkReply, reply);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		int size = errors.length();
		knh_Array_t *p2 = new_Array0(lctx, size);
		knh_class_t cid = knh_getcid(lctx, STEXT("QSslError"));
		for (int i = 0; i < size; i++) {
			QSslError *errors_ = new QSslError(errors[i]);
			knh_RawPtr_t *p = new_RawPtr(lctx, lctx->share->ClassTBL[cid], errors_);
			knh_Array_add(lctx, p2, UPCAST(p));
		}
		knh_Func_invoke(lctx, ssl_errors_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQNetworkAccessManager::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkAccessManager::event_map->bigin();
	if ((itr = DummyQNetworkAccessManager::event_map->find(str)) == DummyQNetworkAccessManager::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQNetworkAccessManager::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkAccessManager::slot_map->bigin();
	if ((itr = DummyQNetworkAccessManager::slot_map->find(str)) == DummyQNetworkAccessManager::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		authentication_required_func = (*slot_map)["authentication-required"];
		finished_func = (*slot_map)["finished"];
		network_accessible_changed_func = (*slot_map)["network-accessible-changed"];
		proxy_authentication_required_func = (*slot_map)["proxy-authentication-required"];
		ssl_errors_func = (*slot_map)["ssl-errors"];
		return true;
	}
}

knh_Object_t** DummyQNetworkAccessManager::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQNetworkAccessManager::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 5;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, authentication_required_func);
	KNH_ADDNNREF(ctx, finished_func);
	KNH_ADDNNREF(ctx, network_accessible_changed_func);
	KNH_ADDNNREF(ctx, proxy_authentication_required_func);
	KNH_ADDNNREF(ctx, ssl_errors_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQNetworkAccessManager::connection(QObject *o)
{
	QNetworkAccessManager *p = dynamic_cast<QNetworkAccessManager*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(authenticationRequired(QNetworkReply*, QAuthenticator*)), this, SLOT(authenticationRequiredSlot(QNetworkReply*, QAuthenticator*)));
		connect(p, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*)));
		connect(p, SIGNAL(networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility)), this, SLOT(networkAccessibleChangedSlot(QNetworkAccessManager::NetworkAccessibility)));
		connect(p, SIGNAL(proxyAuthenticationRequired(const QNetworkProxy, QAuthenticator*)), this, SLOT(proxyAuthenticationRequiredSlot(const QNetworkProxy, QAuthenticator*)));
		connect(p, SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError>)), this, SLOT(sslErrorsSlot(QNetworkReply*, const QList<QSslError>)));
	}
	DummyQObject::connection(o);
}

KQNetworkAccessManager::KQNetworkAccessManager(QObject* parent) : QNetworkAccessManager(parent)
{
	self = NULL;
	dummy = new DummyQNetworkAccessManager();
	dummy->connection((QObject*)this);
}

KMETHOD QNetworkAccessManager_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkAccessManager *qp = RawPtr_to(KQNetworkAccessManager *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkAccessManager]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkAccessManager]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QNetworkAccessManager_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkAccessManager *qp = RawPtr_to(KQNetworkAccessManager *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkAccessManager]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkAccessManager]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QNetworkAccessManager_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQNetworkAccessManager *qp = (KQNetworkAccessManager *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QNetworkAccessManager_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQNetworkAccessManager *qp = (KQNetworkAccessManager *)p->rawptr;
//		KQNetworkAccessManager *qp = static_cast<KQNetworkAccessManager*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QNetworkAccessManager_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQNetworkAccessManager::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQNetworkAccessManager::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QNetworkAccessManager::event(event);
		return false;
	}
//	QNetworkAccessManager::event(event);
	return true;
}

static knh_IntData_t QNetworkAccessManagerConstInt[] = {
	{"UnknownAccessibility", QNetworkAccessManager::UnknownAccessibility},
	{"NotAccessible", QNetworkAccessManager::NotAccessible},
	{"Accessible", QNetworkAccessManager::Accessible},
	{"HeadOperation", QNetworkAccessManager::HeadOperation},
	{"GetOperation", QNetworkAccessManager::GetOperation},
	{"PutOperation", QNetworkAccessManager::PutOperation},
	{"PostOperation", QNetworkAccessManager::PostOperation},
	{"DeleteOperation", QNetworkAccessManager::DeleteOperation},
	{"CustomOperation", QNetworkAccessManager::CustomOperation},
	{NULL, 0}
};

DEFAPI(void) constQNetworkAccessManager(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QNetworkAccessManagerConstInt);
}


DEFAPI(void) defQNetworkAccessManager(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkAccessManager";
	cdef->free = QNetworkAccessManager_free;
	cdef->reftrace = QNetworkAccessManager_reftrace;
	cdef->compareTo = QNetworkAccessManager_compareTo;
}


