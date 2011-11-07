#ifndef QNETWORKREPLY
#define QNETWORKREPLY
class DummyQNetworkReply : public DummyQIODevice {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *download_progress_func;
	knh_Func_t *error_func;
	knh_Func_t *finished_func;
	knh_Func_t *meta_data_changed_func;
	knh_Func_t *ssl_errors_func;
	knh_Func_t *upload_progress_func;
	DummyQNetworkReply();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool downloadProgressSlot(qint64 bytesReceived, qint64 bytesTotal);
	bool errorSlot(QNetworkReply::NetworkError code);
	bool finishedSlot();
	bool metaDataChangedSlot();
	bool sslErrorsSlot(const QList<QSslError> errors);
	bool uploadProgressSlot(qint64 bytesSent, qint64 bytesTotal);
};

class KQNetworkReply : public QNetworkReply {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQNetworkReply *dummy;

	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QNETWORKREPLY


