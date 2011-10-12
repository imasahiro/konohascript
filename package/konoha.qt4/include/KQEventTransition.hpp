#ifndef QEVENTTRANSITION
#define QEVENTTRANSITION
class DummyQEventTransition : public DummyQAbstractTransition {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQEventTransition();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQEventTransition : public QEventTransition, public DummyQEventTransition {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQEventTransition(QState* sourceState);
	bool event(QEvent *event);
};

#endif //QEVENTTRANSITION


