#ifndef QNETWORKCACHEMETADATA
#define QNETWORKCACHEMETADATA
class DummyQNetworkCacheMetaData {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQNetworkCacheMetaData();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQNetworkCacheMetaData : public QNetworkCacheMetaData {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQNetworkCacheMetaData *dummy;
	KQNetworkCacheMetaData();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QNETWORKCACHEMETADATA


