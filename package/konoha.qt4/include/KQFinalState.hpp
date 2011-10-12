#ifndef QFINALSTATE
#define QFINALSTATE
class DummyQFinalState : public DummyQAbstractState {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQFinalState();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQFinalState : public QFinalState, public DummyQFinalState {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQFinalState(QState* parent);
	bool event(QEvent *event);
};

#endif //QFINALSTATE


