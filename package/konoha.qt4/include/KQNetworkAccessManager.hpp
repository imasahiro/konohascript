#ifndef QNETWORKACCESSMANAGER
#define QNETWORKACCESSMANAGER
class DummyQNetworkAccessManager : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *authentication_required_func;
	knh_Func_t *finished_func;
	knh_Func_t *network_accessible_changed_func;
	knh_Func_t *proxy_authentication_required_func;
	knh_Func_t *ssl_errors_func;
	DummyQNetworkAccessManager();
	virtual ~DummyQNetworkAccessManager();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool authenticationRequiredSlot(QNetworkReply* reply, QAuthenticator* authenticator);
	bool finishedSlot(QNetworkReply* reply);
	bool networkAccessibleChangedSlot(QNetworkAccessManager::NetworkAccessibility accessible);
	bool proxyAuthenticationRequiredSlot(const QNetworkProxy proxy, QAuthenticator* authenticator);
	bool sslErrorsSlot(QNetworkReply* reply, const QList<QSslError> errors);
};

class KQNetworkAccessManager : public QNetworkAccessManager {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQNetworkAccessManager *dummy;
	KQNetworkAccessManager(QObject* parent);
	~KQNetworkAccessManager();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QNETWORKACCESSMANAGER


