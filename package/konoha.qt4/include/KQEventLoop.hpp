#ifndef QEVENTLOOP
#define QEVENTLOOP
class DummyQEventLoop : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQEventLoop();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQEventLoop : public QEventLoop, public DummyQEventLoop {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQEventLoop(QObject* parent);
	bool event(QEvent *event);
};

#endif //QEVENTLOOP


