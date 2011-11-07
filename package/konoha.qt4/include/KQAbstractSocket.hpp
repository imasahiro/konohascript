#ifndef QABSTRACTSOCKET
#define QABSTRACTSOCKET
class DummyQAbstractSocket : public DummyQIODevice {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *connected_func;
	knh_Func_t *disconnected_func;
	knh_Func_t *error_func;
	knh_Func_t *host_found_func;
	knh_Func_t *proxy_authentication_required_func;
	knh_Func_t *state_changed_func;
	DummyQAbstractSocket();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool connectedSlot();
	bool disconnectedSlot();
	bool errorSlot(QAbstractSocket::SocketError socketError);
	bool hostFoundSlot();
	bool proxyAuthenticationRequiredSlot(const QNetworkProxy proxy, QAuthenticator* authenticator);
	bool stateChangedSlot(QAbstractSocket::SocketState socketState);
};

class KQAbstractSocket : public QAbstractSocket {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQAbstractSocket *dummy;
	KQAbstractSocket(QAbstractSocket::SocketType socketType, QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QABSTRACTSOCKET


