#ifndef QTHREADPOOL
#define QTHREADPOOL
class DummyQThreadPool : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQThreadPool();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQThreadPool : public QThreadPool, public DummyQThreadPool {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQThreadPool(QObject* parent);
	bool event(QEvent *event);
};

#endif //QTHREADPOOL


