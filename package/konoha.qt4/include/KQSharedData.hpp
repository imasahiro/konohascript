#ifndef QSHAREDDATA
#define QSHAREDDATA
class DummyQSharedData {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQSharedData();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQSharedData : public QSharedData {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQSharedData *dummy;
	KQSharedData();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSHAREDDATA


