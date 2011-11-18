#ifndef QNETWORKCOOKIEJAR
#define QNETWORKCOOKIEJAR
class DummyQNetworkCookieJar : public DummyQObject {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQNetworkCookieJar();
	virtual ~DummyQNetworkCookieJar();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQNetworkCookieJar : public QNetworkCookieJar {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQNetworkCookieJar *dummy;
	KQNetworkCookieJar(QObject* parent);
	~KQNetworkCookieJar();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QNETWORKCOOKIEJAR


