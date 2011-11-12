//@Virtual @Override boolean QAbstractSocket.atEnd();
KMETHOD QAbstractSocket_atEnd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		bool ret_v = qp->atEnd();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override int QAbstractSocket.bytesAvailable();
KMETHOD QAbstractSocket_bytesAvailable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->bytesAvailable();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QAbstractSocket.bytesToWrite();
KMETHOD QAbstractSocket_bytesToWrite(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->bytesToWrite();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QAbstractSocket.canReadLine();
KMETHOD QAbstractSocket_canReadLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		bool ret_v = qp->canReadLine();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override void QAbstractSocket.close();
KMETHOD QAbstractSocket_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		qp->close();
	}
	RETURNvoid_();
}

//@Virtual @Override boolean QAbstractSocket.isSequential();
KMETHOD QAbstractSocket_isSequential(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSequential();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override boolean QAbstractSocket.waitForBytesWritten(int msecs);
KMETHOD QAbstractSocket_waitForBytesWritten(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForBytesWritten(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override boolean QAbstractSocket.waitForReadyRead(int msecs);
KMETHOD QAbstractSocket_waitForReadyRead(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForReadyRead(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//
//void QAbstractSocket.abort();
KMETHOD QAbstractSocket_abort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		qp->abort();
	}
	RETURNvoid_();
}

//void QAbstractSocket.connectToHost(String hostName, int port, QIODeviceOpenMode openMode);
KMETHOD QAbstractSocket_connectToHost(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		const QString hostName = String_to(const QString, sfp[1]);
		quint16 port = Int_to(quint16, sfp[2]);
		initFlag(openMode, QIODevice::OpenMode, sfp[3]);
		qp->connectToHost(hostName, port, openMode);
	}
	RETURNvoid_();
}

/*
//void QAbstractSocket.connectToHost(QHostAddress address, int port, QIODeviceOpenMode openMode);
KMETHOD QAbstractSocket_connectToHost(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		const QHostAddress  address = *RawPtr_to(const QHostAddress *, sfp[1]);
		quint16 port = Int_to(quint16, sfp[2]);
		initFlag(openMode, QIODevice::OpenMode, sfp[3]);
		qp->connectToHost(address, port, openMode);
	}
	RETURNvoid_();
}
*/
//void QAbstractSocket.disconnectFromHost();
KMETHOD QAbstractSocket_disconnectFromHost(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		qp->disconnectFromHost();
	}
	RETURNvoid_();
}

//int QAbstractSocket.error();
KMETHOD QAbstractSocket_error(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		QAbstractSocket::SocketError ret_v = qp->error();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QAbstractSocket.flush();
KMETHOD QAbstractSocket_flush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		bool ret_v = qp->flush();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QHostAddress QAbstractSocket.localAddress();
KMETHOD QAbstractSocket_localAddress(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		QHostAddress ret_v = qp->localAddress();
		QHostAddress *ret_v_ = new QHostAddress(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QAbstractSocket.localPort();
KMETHOD QAbstractSocket_localPort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		quint16 ret_v = qp->localPort();
		quint16 *ret_v_ = new quint16(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QHostAddress QAbstractSocket.peerAddress();
KMETHOD QAbstractSocket_peerAddress(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		QHostAddress ret_v = qp->peerAddress();
		QHostAddress *ret_v_ = new QHostAddress(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QAbstractSocket.peerName();
KMETHOD QAbstractSocket_peerName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		QString ret_v = qp->peerName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QAbstractSocket.peerPort();
KMETHOD QAbstractSocket_peerPort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		quint16 ret_v = qp->peerPort();
		quint16 *ret_v_ = new quint16(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkProxy QAbstractSocket.getProxy();
KMETHOD QAbstractSocket_getProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		QNetworkProxy ret_v = qp->proxy();
		QNetworkProxy *ret_v_ = new QNetworkProxy(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QAbstractSocket.getReadBufferSize();
KMETHOD QAbstractSocket_getReadBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->readBufferSize();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QAbstractSocket.setProxy(QNetworkProxy networkProxy);
KMETHOD QAbstractSocket_setProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		const QNetworkProxy  networkProxy = *RawPtr_to(const QNetworkProxy *, sfp[1]);
		qp->setProxy(networkProxy);
	}
	RETURNvoid_();
}

//void QAbstractSocket.setReadBufferSize(int size);
KMETHOD QAbstractSocket_setReadBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		qint64 size = Int_to(qint64, sfp[1]);
		qp->setReadBufferSize(size);
	}
	RETURNvoid_();
}

//boolean QAbstractSocket.setSocketDescriptor(int socketDescriptor, int socketState, QIODeviceOpenMode openMode);
KMETHOD QAbstractSocket_setSocketDescriptor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		int socketDescriptor = Int_to(int, sfp[1]);
		QAbstractSocket::SocketState socketState = Int_to(QAbstractSocket::SocketState, sfp[2]);
		initFlag(openMode, QIODevice::OpenMode, sfp[3]);
		bool ret_v = qp->setSocketDescriptor(socketDescriptor, socketState, openMode);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QAbstractSocket.setSocketOption(int option, QVariant value);
KMETHOD QAbstractSocket_setSocketOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		QAbstractSocket::SocketOption option = Int_to(QAbstractSocket::SocketOption, sfp[1]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[2]);
		qp->setSocketOption(option, value);
	}
	RETURNvoid_();
}

//int QAbstractSocket.getSocketDescriptor();
KMETHOD QAbstractSocket_getSocketDescriptor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		int ret_v = qp->socketDescriptor();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QVariant QAbstractSocket.getSocketOption(int option);
KMETHOD QAbstractSocket_getSocketOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		QAbstractSocket::SocketOption option = Int_to(QAbstractSocket::SocketOption, sfp[1]);
		QVariant ret_v = qp->socketOption(option);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QAbstractSocket.socketType();
KMETHOD QAbstractSocket_socketType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		QAbstractSocket::SocketType ret_v = qp->socketType();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAbstractSocket.state();
KMETHOD QAbstractSocket_state(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		QAbstractSocket::SocketState ret_v = qp->state();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QAbstractSocket.waitForConnected(int msecs);
KMETHOD QAbstractSocket_waitForConnected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForConnected(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAbstractSocket.waitForDisconnected(int msecs);
KMETHOD QAbstractSocket_waitForDisconnected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSocket *  qp = RawPtr_to(QAbstractSocket *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForDisconnected(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQAbstractSocket::DummyQAbstractSocket()
{
	self = NULL;
	connected_func = NULL;
	disconnected_func = NULL;
	error_func = NULL;
	host_found_func = NULL;
	proxy_authentication_required_func = NULL;
	state_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("connected", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("disconnected", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("error", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("host-found", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("proxy-authentication-required", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("state-changed", NULL));
}

void DummyQAbstractSocket::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractSocket::self = ptr;
	DummyQIODevice::setSelf(ptr);
}

bool DummyQAbstractSocket::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQIODevice::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractSocket::connectedSlot()
{
	if (connected_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, connected_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAbstractSocket::disconnectedSlot()
{
	if (disconnected_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, disconnected_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAbstractSocket::errorSlot(QAbstractSocket::SocketError socketError)
{
	if (error_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = socketError;
		knh_Func_invoke(lctx, error_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQAbstractSocket::hostFoundSlot()
{
	if (host_found_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, host_found_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAbstractSocket::proxyAuthenticationRequiredSlot(const QNetworkProxy proxy, QAuthenticator* authenticator)
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

bool DummyQAbstractSocket::stateChangedSlot(QAbstractSocket::SocketState socketState)
{
	if (state_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = socketState;
		knh_Func_invoke(lctx, state_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQAbstractSocket::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractSocket::event_map->bigin();
	if ((itr = DummyQAbstractSocket::event_map->find(str)) == DummyQAbstractSocket::event_map->end()) {
		bool ret = false;
		ret = DummyQIODevice::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractSocket::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractSocket::slot_map->bigin();
	if ((itr = DummyQAbstractSocket::slot_map->find(str)) == DummyQAbstractSocket::slot_map->end()) {
		bool ret = false;
		ret = DummyQIODevice::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		connected_func = (*slot_map)["connected"];
		disconnected_func = (*slot_map)["disconnected"];
		error_func = (*slot_map)["error"];
		host_found_func = (*slot_map)["host-found"];
		proxy_authentication_required_func = (*slot_map)["proxy-authentication-required"];
		state_changed_func = (*slot_map)["state-changed"];
		return true;
	}
}

knh_Object_t** DummyQAbstractSocket::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQAbstractSocket::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 6;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, connected_func);
	KNH_ADDNNREF(ctx, disconnected_func);
	KNH_ADDNNREF(ctx, error_func);
	KNH_ADDNNREF(ctx, host_found_func);
	KNH_ADDNNREF(ctx, proxy_authentication_required_func);
	KNH_ADDNNREF(ctx, state_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQIODevice::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQAbstractSocket::connection(QObject *o)
{
	QAbstractSocket *p = dynamic_cast<QAbstractSocket*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(connected()), this, SLOT(connectedSlot()));
		connect(p, SIGNAL(disconnected()), this, SLOT(disconnectedSlot()));
		connect(p, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(errorSlot(QAbstractSocket::SocketError)));
		connect(p, SIGNAL(hostFound()), this, SLOT(hostFoundSlot()));
		connect(p, SIGNAL(proxyAuthenticationRequired(const QNetworkProxy, QAuthenticator*)), this, SLOT(proxyAuthenticationRequiredSlot(const QNetworkProxy, QAuthenticator*)));
		connect(p, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChangedSlot(QAbstractSocket::SocketState)));
	}
	DummyQIODevice::connection(o);
}

KQAbstractSocket::KQAbstractSocket(QAbstractSocket::SocketType socketType, QObject* parent) : QAbstractSocket(socketType, parent)
{
	self = NULL;
	dummy = new DummyQAbstractSocket();
	dummy->connection((QObject*)this);
}

KMETHOD QAbstractSocket_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractSocket *qp = RawPtr_to(KQAbstractSocket *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractSocket]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractSocket]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAbstractSocket_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractSocket *qp = RawPtr_to(KQAbstractSocket *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractSocket]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractSocket]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractSocket_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAbstractSocket *qp = (KQAbstractSocket *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAbstractSocket_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQAbstractSocket *qp = (KQAbstractSocket *)p->rawptr;
//		KQAbstractSocket *qp = static_cast<KQAbstractSocket*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAbstractSocket_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAbstractSocket::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQAbstractSocket::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QAbstractSocket::event(event);
		return false;
	}
//	QAbstractSocket::event(event);
	return true;
}

static knh_IntData_t QAbstractSocketConstInt[] = {
	{"IPv4Protocol", QAbstractSocket::IPv4Protocol},
	{"IPv6Protocol", QAbstractSocket::IPv6Protocol},
	{"UnknownNetworkLayerProtocol", QAbstractSocket::UnknownNetworkLayerProtocol},
	{"ConnectionRefusedError", QAbstractSocket::ConnectionRefusedError},
	{"RemoteHostClosedError", QAbstractSocket::RemoteHostClosedError},
	{"HostNotFoundError", QAbstractSocket::HostNotFoundError},
	{"SocketAccessError", QAbstractSocket::SocketAccessError},
	{"SocketResourceError", QAbstractSocket::SocketResourceError},
	{"SocketTimeoutError", QAbstractSocket::SocketTimeoutError},
	{"DatagramTooLargeError", QAbstractSocket::DatagramTooLargeError},
	{"NetworkError", QAbstractSocket::NetworkError},
	{"AddressInUseError", QAbstractSocket::AddressInUseError},
	{"SocketAddressNotAvailableError", QAbstractSocket::SocketAddressNotAvailableError},
	{"UnsupportedSocketOperationError", QAbstractSocket::UnsupportedSocketOperationError},
	{"ProxyAuthenticationRequiredError", QAbstractSocket::ProxyAuthenticationRequiredError},
	{"SslHandshakeFailedError", QAbstractSocket::SslHandshakeFailedError},
	{"UnfinishedSocketOperationError", QAbstractSocket::UnfinishedSocketOperationError},
	{"ProxyConnectionRefusedError", QAbstractSocket::ProxyConnectionRefusedError},
	{"ProxyConnectionClosedError", QAbstractSocket::ProxyConnectionClosedError},
	{"ProxyConnectionTimeoutError", QAbstractSocket::ProxyConnectionTimeoutError},
	{"ProxyNotFoundError", QAbstractSocket::ProxyNotFoundError},
	{"ProxyProtocolError", QAbstractSocket::ProxyProtocolError},
	{"UnknownSocketError", QAbstractSocket::UnknownSocketError},
	{"LowDelayOption", QAbstractSocket::LowDelayOption},
	{"KeepAliveOption", QAbstractSocket::KeepAliveOption},
	{"UnconnectedState", QAbstractSocket::UnconnectedState},
	{"HostLookupState", QAbstractSocket::HostLookupState},
	{"ConnectingState", QAbstractSocket::ConnectingState},
	{"ConnectedState", QAbstractSocket::ConnectedState},
	{"BoundState", QAbstractSocket::BoundState},
	{"ClosingState", QAbstractSocket::ClosingState},
	{"ListeningState", QAbstractSocket::ListeningState},
	{"TcpSocket", QAbstractSocket::TcpSocket},
	{"UdpSocket", QAbstractSocket::UdpSocket},
	{"UnknownSocketType", QAbstractSocket::UnknownSocketType},
	{NULL, 0}
};

DEFAPI(void) constQAbstractSocket(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QAbstractSocketConstInt);
}


DEFAPI(void) defQAbstractSocket(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractSocket";
	cdef->free = QAbstractSocket_free;
	cdef->reftrace = QAbstractSocket_reftrace;
	cdef->compareTo = QAbstractSocket_compareTo;
}


