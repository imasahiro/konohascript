#ifndef QHTTP
#define QHTTP
class DummyQHttp : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *authentication_required_func;
	knh_Func_t *data_read_progress_func;
	knh_Func_t *data_send_progress_func;
	knh_Func_t *done_func;
	knh_Func_t *proxy_authentication_required_func;
	knh_Func_t *ready_read_func;
	knh_Func_t *request_finished_func;
	knh_Func_t *request_started_func;
	knh_Func_t *response_header_received_func;
	knh_Func_t *ssl_errors_func;
	knh_Func_t *state_changed_func;
	DummyQHttp();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool authenticationRequiredSlot(const QString hostname, quint16 port, QAuthenticator* authenticator);
	bool dataReadProgressSlot(int done, int total);
	bool dataSendProgressSlot(int done, int total);
	bool doneSlot(bool error);
	bool proxyAuthenticationRequiredSlot(const QNetworkProxy proxy, QAuthenticator* authenticator);
	bool readyReadSlot(const QHttpResponseHeader resp);
	bool requestFinishedSlot(int id, bool error);
	bool requestStartedSlot(int id);
	bool responseHeaderReceivedSlot(const QHttpResponseHeader resp);
	bool sslErrorsSlot(const QList<QSslError> errors);
	bool stateChangedSlot(int state);
};

class KQHttp : public QHttp {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQHttp *dummy;
	KQHttp(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QHTTP


