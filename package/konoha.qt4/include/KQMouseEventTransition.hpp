#ifndef QMOUSEEVENTTRANSITION
#define QMOUSEEVENTTRANSITION
class DummyQMouseEventTransition : public DummyQEventTransition {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQMouseEventTransition();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQMouseEventTransition : public QMouseEventTransition, public DummyQMouseEventTransition {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQMouseEventTransition(QState* sourceState);
	bool event(QEvent *event);
};

#endif //QMOUSEEVENTTRANSITION


