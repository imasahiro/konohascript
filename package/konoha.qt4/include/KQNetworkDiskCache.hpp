#ifndef QNETWORKDISKCACHE
#define QNETWORKDISKCACHE
class DummyQNetworkDiskCache : public DummyQAbstractNetworkCache {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQNetworkDiskCache();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQNetworkDiskCache : public QNetworkDiskCache {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQNetworkDiskCache *dummy;
	KQNetworkDiskCache(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QNETWORKDISKCACHE


