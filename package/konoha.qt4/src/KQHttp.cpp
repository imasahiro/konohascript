//QHttp QHttp.new(QObject parent);
KMETHOD QHttp_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQHttp *ret_v = new KQHttp(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QHttp QHttp.new(String hostName, int port, QObject parent);
KMETHOD QHttp_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString hostName = String_to(const QString, sfp[1]);
	quint16 port = Int_to(quint16, sfp[2]);
	QObject*  parent = RawPtr_to(QObject*, sfp[3]);
	KQHttp *ret_v = new KQHttp(hostName, port, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QHttp QHttp.new(String hostName, int mode, int port, QObject parent);
KMETHOD QHttp_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString hostName = String_to(const QString, sfp[1]);
	QHttp::ConnectionMode mode = Int_to(QHttp::ConnectionMode, sfp[2]);
	quint16 port = Int_to(quint16, sfp[3]);
	QObject*  parent = RawPtr_to(QObject*, sfp[4]);
	KQHttp *ret_v = new KQHttp(hostName, mode, port, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QHttp.bytesAvailable();
KMETHOD QHttp_bytesAvailable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->bytesAvailable();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QHttp.clearPendingRequests();
KMETHOD QHttp_clearPendingRequests(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		qp->clearPendingRequests();
	}
	RETURNvoid_();
}

//int QHttp.close();
KMETHOD QHttp_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		int ret_v = qp->close();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QIODevice QHttp.currentDestinationDevice();
KMETHOD QHttp_currentDestinationDevice(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		QIODevice* ret_v = qp->currentDestinationDevice();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QIODevice*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QHttp.currentId();
KMETHOD QHttp_currentId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		int ret_v = qp->currentId();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QHttpRequestHeader QHttp.currentRequest();
KMETHOD QHttp_currentRequest(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		QHttpRequestHeader ret_v = qp->currentRequest();
		QHttpRequestHeader *ret_v_ = new QHttpRequestHeader(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QIODevice QHttp.currentSourceDevice();
KMETHOD QHttp_currentSourceDevice(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		QIODevice* ret_v = qp->currentSourceDevice();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QIODevice*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QHttp.error();
KMETHOD QHttp_error(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		QHttp::Error ret_v = qp->error();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QHttp.errorString();
KMETHOD QHttp_errorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		QString ret_v = qp->errorString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QHttp.get(String path, QIODevice to_);
KMETHOD QHttp_get(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		const QString path = String_to(const QString, sfp[1]);
		QIODevice*  to = RawPtr_to(QIODevice*, sfp[2]);
		int ret_v = qp->get(path, to);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QHttp.hasPendingRequests();
KMETHOD QHttp_hasPendingRequests(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasPendingRequests();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QHttp.head(String path);
KMETHOD QHttp_head(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		const QString path = String_to(const QString, sfp[1]);
		int ret_v = qp->head(path);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QHttpResponseHeader QHttp.lastResponse();
KMETHOD QHttp_lastResponse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		QHttpResponseHeader ret_v = qp->lastResponse();
		QHttpResponseHeader *ret_v_ = new QHttpResponseHeader(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QHttp.post(String path, QIODevice data, QIODevice to_);
KMETHOD QHttp_post(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		const QString path = String_to(const QString, sfp[1]);
		QIODevice*  data = RawPtr_to(QIODevice*, sfp[2]);
		QIODevice*  to = RawPtr_to(QIODevice*, sfp[3]);
		int ret_v = qp->post(path, data, to);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QHttp.post(String path, QByteArray data, QIODevice to_);
KMETHOD QHttp_post(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		const QString path = String_to(const QString, sfp[1]);
		const QByteArray  data = *RawPtr_to(const QByteArray *, sfp[2]);
		QIODevice*  to = RawPtr_to(QIODevice*, sfp[3]);
		int ret_v = qp->post(path, data, to);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//int QHttp.read(String data, int maxlen);
KMETHOD QHttp_read(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		char*  data = RawPtr_to(char*, sfp[1]);
		qint64 maxlen = Int_to(qint64, sfp[2]);
		qint64 ret_v = qp->read(data, maxlen);
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QHttp.readAll();
KMETHOD QHttp_readAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->readAll();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QHttp.request(QHttpRequestHeader header, QIODevice data, QIODevice to_);
KMETHOD QHttp_request(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		const QHttpRequestHeader  header = *RawPtr_to(const QHttpRequestHeader *, sfp[1]);
		QIODevice*  data = RawPtr_to(QIODevice*, sfp[2]);
		QIODevice*  to = RawPtr_to(QIODevice*, sfp[3]);
		int ret_v = qp->request(header, data, to);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QHttp.request(QHttpRequestHeader header, QByteArray data, QIODevice to_);
KMETHOD QHttp_request(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		const QHttpRequestHeader  header = *RawPtr_to(const QHttpRequestHeader *, sfp[1]);
		const QByteArray  data = *RawPtr_to(const QByteArray *, sfp[2]);
		QIODevice*  to = RawPtr_to(QIODevice*, sfp[3]);
		int ret_v = qp->request(header, data, to);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//int QHttp.setHost(String hostName, int port);
KMETHOD QHttp_setHost(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		const QString hostName = String_to(const QString, sfp[1]);
		quint16 port = Int_to(quint16, sfp[2]);
		int ret_v = qp->setHost(hostName, port);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QHttp.setHost(String hostName, int mode, int port);
KMETHOD QHttp_setHost(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		const QString hostName = String_to(const QString, sfp[1]);
		QHttp::ConnectionMode mode = Int_to(QHttp::ConnectionMode, sfp[2]);
		quint16 port = Int_to(quint16, sfp[3]);
		int ret_v = qp->setHost(hostName, mode, port);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//int QHttp.setProxy(String host, int port, String username, String password);
KMETHOD QHttp_setProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		const QString host = String_to(const QString, sfp[1]);
		int port = Int_to(int, sfp[2]);
		const QString username = String_to(const QString, sfp[3]);
		const QString password = String_to(const QString, sfp[4]);
		int ret_v = qp->setProxy(host, port, username, password);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QHttp.setProxy(QNetworkProxy proxy);
KMETHOD QHttp_setProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		const QNetworkProxy  proxy = *RawPtr_to(const QNetworkProxy *, sfp[1]);
		int ret_v = qp->setProxy(proxy);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//int QHttp.setSocket(QTcpSocket socket);
KMETHOD QHttp_setSocket(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		QTcpSocket*  socket = RawPtr_to(QTcpSocket*, sfp[1]);
		int ret_v = qp->setSocket(socket);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QHttp.setUser(String userName, String password);
KMETHOD QHttp_setUser(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		const QString userName = String_to(const QString, sfp[1]);
		const QString password = String_to(const QString, sfp[2]);
		int ret_v = qp->setUser(userName, password);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QHttp.state();
KMETHOD QHttp_state(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		QHttp::State ret_v = qp->state();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QHttp.abort();
KMETHOD QHttp_abort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		qp->abort();
	}
	RETURNvoid_();
}

//void QHttp.ignoreSslErrors();
KMETHOD QHttp_ignoreSslErrors(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHttp *  qp = RawPtr_to(QHttp *, sfp[0]);
	if (qp) {
		qp->ignoreSslErrors();
	}
	RETURNvoid_();
}


DummyQHttp::DummyQHttp()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	authentication_required_func = NULL;
	data_read_progress_func = NULL;
	data_send_progress_func = NULL;
	done_func = NULL;
	proxy_authentication_required_func = NULL;
	ready_read_func = NULL;
	request_finished_func = NULL;
	request_started_func = NULL;
	response_header_received_func = NULL;
	ssl_errors_func = NULL;
	state_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("authentication-required", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("data-read-progress", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("data-send-progress", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("done", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("proxy-authentication-required", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("ready-read", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("request-finished", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("request-started", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("response-header-received", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("ssl-errors", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("state-changed", NULL));
}
DummyQHttp::~DummyQHttp()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQHttp::setSelf(knh_RawPtr_t *ptr)
{
	DummyQHttp::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQHttp::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQHttp::authenticationRequiredSlot(const QString hostname, quint16 port, QAuthenticator* authenticator)
{
	if (authentication_required_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QString, hostname);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_RawPtr_t *p2 = new_QRawPtr(lctx, quint16, port);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		knh_RawPtr_t *p3 = new_QRawPtr(lctx, QAuthenticator, authenticator);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+4].o, UPCAST(p3));
		knh_Func_invoke(lctx, authentication_required_func, lsfp, 4);
		return true;
	}
	return false;
}

bool DummyQHttp::dataReadProgressSlot(int done, int total)
{
	if (data_read_progress_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = done;
		lsfp[K_CALLDELTA+3].ivalue = total;
		knh_Func_invoke(lctx, data_read_progress_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQHttp::dataSendProgressSlot(int done, int total)
{
	if (data_send_progress_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = done;
		lsfp[K_CALLDELTA+3].ivalue = total;
		knh_Func_invoke(lctx, data_send_progress_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQHttp::doneSlot(bool error)
{
	if (done_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = error;
		knh_Func_invoke(lctx, done_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQHttp::proxyAuthenticationRequiredSlot(const QNetworkProxy proxy, QAuthenticator* authenticator)
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

bool DummyQHttp::readyReadSlot(const QHttpResponseHeader resp)
{
	if (ready_read_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QHttpResponseHeader, resp);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, ready_read_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQHttp::requestFinishedSlot(int id, bool error)
{
	if (request_finished_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = id;
		lsfp[K_CALLDELTA+3].bvalue = error;
		knh_Func_invoke(lctx, request_finished_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQHttp::requestStartedSlot(int id)
{
	if (request_started_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = id;
		knh_Func_invoke(lctx, request_started_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQHttp::responseHeaderReceivedSlot(const QHttpResponseHeader resp)
{
	if (response_header_received_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QHttpResponseHeader, resp);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, response_header_received_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQHttp::sslErrorsSlot(const QList<QSslError> errors)
{
	if (ssl_errors_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		int size = errors.length();
		knh_Array_t *p1 = new_Array0(lctx, size);
		knh_class_t cid = knh_getcid(lctx, STEXT("QSslError"));
		for (int i = 0; i < size; i++) {
			QSslError *errors_ = new QSslError(errors[i]);
			knh_RawPtr_t *p = new_RawPtr(lctx, lctx->share->ClassTBL[cid], errors_);
			knh_Array_add(lctx, p1, UPCAST(p));
		}
		knh_Func_invoke(lctx, ssl_errors_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQHttp::stateChangedSlot(int state)
{
	if (state_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = state;
		knh_Func_invoke(lctx, state_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQHttp::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHttp::event_map->bigin();
	if ((itr = DummyQHttp::event_map->find(str)) == DummyQHttp::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQHttp::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHttp::slot_map->bigin();
	if ((itr = DummyQHttp::slot_map->find(str)) == DummyQHttp::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		authentication_required_func = (*slot_map)["authentication-required"];
		data_read_progress_func = (*slot_map)["data-read-progress"];
		data_send_progress_func = (*slot_map)["data-send-progress"];
		done_func = (*slot_map)["done"];
		proxy_authentication_required_func = (*slot_map)["proxy-authentication-required"];
		ready_read_func = (*slot_map)["ready-read"];
		request_finished_func = (*slot_map)["request-finished"];
		request_started_func = (*slot_map)["request-started"];
		response_header_received_func = (*slot_map)["response-header-received"];
		ssl_errors_func = (*slot_map)["ssl-errors"];
		state_changed_func = (*slot_map)["state-changed"];
		return true;
	}
}

knh_Object_t** DummyQHttp::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQHttp::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 12;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, authentication_required_func);
	KNH_ADDNNREF(ctx, data_read_progress_func);
	KNH_ADDNNREF(ctx, data_send_progress_func);
	KNH_ADDNNREF(ctx, done_func);
	KNH_ADDNNREF(ctx, proxy_authentication_required_func);
	KNH_ADDNNREF(ctx, ready_read_func);
	KNH_ADDNNREF(ctx, request_finished_func);
	KNH_ADDNNREF(ctx, request_started_func);
	KNH_ADDNNREF(ctx, response_header_received_func);
	KNH_ADDNNREF(ctx, ssl_errors_func);
	KNH_ADDNNREF(ctx, state_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQHttp::connection(QObject *o)
{
	QHttp *p = dynamic_cast<QHttp*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(authenticationRequired(const QString, quint16, QAuthenticator*)), this, SLOT(authenticationRequiredSlot(const QString, quint16, QAuthenticator*)));
		connect(p, SIGNAL(dataReadProgress(int, int)), this, SLOT(dataReadProgressSlot(int, int)));
		connect(p, SIGNAL(dataSendProgress(int, int)), this, SLOT(dataSendProgressSlot(int, int)));
		connect(p, SIGNAL(done(bool)), this, SLOT(doneSlot(bool)));
		connect(p, SIGNAL(proxyAuthenticationRequired(const QNetworkProxy, QAuthenticator*)), this, SLOT(proxyAuthenticationRequiredSlot(const QNetworkProxy, QAuthenticator*)));
		connect(p, SIGNAL(readyRead(const QHttpResponseHeader)), this, SLOT(readyReadSlot(const QHttpResponseHeader)));
		connect(p, SIGNAL(requestFinished(int, bool)), this, SLOT(requestFinishedSlot(int, bool)));
		connect(p, SIGNAL(requestStarted(int)), this, SLOT(requestStartedSlot(int)));
		connect(p, SIGNAL(responseHeaderReceived(const QHttpResponseHeader)), this, SLOT(responseHeaderReceivedSlot(const QHttpResponseHeader)));
		connect(p, SIGNAL(sslErrors(const QList<QSslError>)), this, SLOT(sslErrorsSlot(const QList<QSslError>)));
		connect(p, SIGNAL(stateChanged(int)), this, SLOT(stateChangedSlot(int)));
	}
	DummyQObject::connection(o);
}

KQHttp::KQHttp(QObject* parent) : QHttp(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQHttp();
	dummy->connection((QObject*)this);
}

KQHttp::~KQHttp()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QHttp_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHttp *qp = RawPtr_to(KQHttp *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QHttp]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHttp]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QHttp_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHttp *qp = RawPtr_to(KQHttp *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QHttp]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHttp]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QHttp_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQHttp *qp = (KQHttp *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QHttp*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QHttp_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQHttp *qp = (KQHttp *)p->rawptr;
		KQHttp *qp = static_cast<KQHttp*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QHttp_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQHttp::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQHttp::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QHttp::event(event);
		return false;
	}
//	QHttp::event(event);
	return true;
}

static knh_IntData_t QHttpConstInt[] = {
	{"ConnectionModeHttp", QHttp::ConnectionModeHttp},
	{"ConnectionModeHttps", QHttp::ConnectionModeHttps},
	{"NoError", QHttp::NoError},
	{"HostNotFound", QHttp::HostNotFound},
	{"ConnectionRefused", QHttp::ConnectionRefused},
	{"UnexpectedClose", QHttp::UnexpectedClose},
	{"InvalidResponseHeader", QHttp::InvalidResponseHeader},
	{"WrongContentLength", QHttp::WrongContentLength},
	{"Aborted", QHttp::Aborted},
	{"ProxyAuthenticationRequiredError", QHttp::ProxyAuthenticationRequiredError},
	{"AuthenticationRequiredError", QHttp::AuthenticationRequiredError},
	{"UnknownError", QHttp::UnknownError},
	{"Unconnected", QHttp::Unconnected},
	{"HostLookup", QHttp::HostLookup},
	{"Connecting", QHttp::Connecting},
	{"Sending", QHttp::Sending},
	{"Reading", QHttp::Reading},
	{"Connected", QHttp::Connected},
	{"Closing", QHttp::Closing},
	{NULL, 0}
};

DEFAPI(void) constQHttp(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QHttpConstInt);
}


DEFAPI(void) defQHttp(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QHttp";
	cdef->free = QHttp_free;
	cdef->reftrace = QHttp_reftrace;
	cdef->compareTo = QHttp_compareTo;
}


