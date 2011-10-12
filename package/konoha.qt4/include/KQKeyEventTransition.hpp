#ifndef QKEYEVENTTRANSITION
#define QKEYEVENTTRANSITION
class DummyQKeyEventTransition : public DummyQEventTransition {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQKeyEventTransition();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQKeyEventTransition : public QKeyEventTransition, public DummyQKeyEventTransition {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQKeyEventTransition(QState* sourceState);
	bool event(QEvent *event);
};

#endif //QKEYEVENTTRANSITION


