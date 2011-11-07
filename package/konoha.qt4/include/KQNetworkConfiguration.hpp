#ifndef QNETWORKCONFIGURATION
#define QNETWORKCONFIGURATION
class DummyQNetworkConfiguration {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQNetworkConfiguration();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQNetworkConfiguration : public QNetworkConfiguration {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQNetworkConfiguration *dummy;
	KQNetworkConfiguration();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QNETWORKCONFIGURATION


