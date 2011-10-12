#ifndef QRUNNABLE
#define QRUNNABLE
class DummyQRunnable {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQRunnable();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQRunnable : public QRunnable, public DummyQRunnable {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQRunnable();
};

#endif //QRUNNABLE


