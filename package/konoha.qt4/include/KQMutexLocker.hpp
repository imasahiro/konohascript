#ifndef QMUTEXLOCKER
#define QMUTEXLOCKER
class DummyQMutexLocker {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQMutexLocker();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQMutexLocker : public QMutexLocker, public DummyQMutexLocker {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQMutexLocker(QMutex* mutex);
};

#endif //QMUTEXLOCKER


