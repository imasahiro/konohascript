#ifndef QABSTRACTTRANSITION
#define QABSTRACTTRANSITION
class DummyQAbstractTransition : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAbstractTransition();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQAbstractTransition : public QAbstractTransition, public DummyQAbstractTransition {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQAbstractTransition(QState* sourceState);
	bool event(QEvent *event);
};

#endif //QABSTRACTTRANSITION


