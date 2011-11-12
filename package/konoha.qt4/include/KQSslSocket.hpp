#ifndef QSSLSOCKET
#define QSSLSOCKET
class DummyQSslSocket : public DummyQTcpSocket {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *encrypted_func;
	knh_Func_t *encrypted_bytes_written_func;
	knh_Func_t *mode_changed_func;
	knh_Func_t *peer_verify_error_func;
	knh_Func_t *ssl_errors_func;
	DummyQSslSocket();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool encryptedSlot();
	bool encryptedBytesWrittenSlot(qint64 written);
	bool modeChangedSlot(QSslSocket::SslMode mode);
	bool peerVerifyErrorSlot(const QSslError error);
	bool sslErrorsSlot(const QList<QSslError> errors);
};

class KQSslSocket : public QSslSocket {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQSslSocket *dummy;
	KQSslSocket(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QSSLSOCKET


