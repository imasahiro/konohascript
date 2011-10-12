#ifndef QTHREAD
#define QTHREAD
class DummyQThread : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQThread();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQThread : public QThread, public DummyQThread {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQThread(QObject* parent);
	bool event(QEvent *event);
};

#endif //QTHREAD


