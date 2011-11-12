#ifndef QSSLCERTIFICATE
#define QSSLCERTIFICATE
class DummyQSslCertificate {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQSslCertificate();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQSslCertificate : public QSslCertificate {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQSslCertificate *dummy;
	KQSslCertificate(QIODevice* device, QSsl::EncodingFormat format);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSSLCERTIFICATE


