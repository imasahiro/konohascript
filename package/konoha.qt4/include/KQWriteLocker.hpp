#ifndef QWRITELOCKER
#define QWRITELOCKER
class DummyQWriteLocker {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQWriteLocker();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQWriteLocker : public QWriteLocker {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQWriteLocker *dummy;
	KQWriteLocker(QReadWriteLock* lock);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QWRITELOCKER


