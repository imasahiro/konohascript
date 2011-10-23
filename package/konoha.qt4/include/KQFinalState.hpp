#ifndef QFINALSTATE
#define QFINALSTATE
class DummyQFinalState : public DummyQAbstractState {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQFinalState();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQFinalState : public QFinalState {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQFinalState *dummy;
	KQFinalState(QState* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QFINALSTATE

