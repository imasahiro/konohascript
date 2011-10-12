#ifndef QABSTRACTSTATE
#define QABSTRACTSTATE
class DummyQAbstractState : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAbstractState();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQAbstractState : public QAbstractState, public DummyQAbstractState {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQAbstractState(QState* parent);
	bool event(QEvent *event);
};

#endif //QABSTRACTSTATE


