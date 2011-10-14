#ifndef QABSTRACTSTATE
#define QABSTRACTSTATE
class DummyQAbstractState : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *entered_func;
	knh_Func_t *exited_func;
	DummyQAbstractState();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool enteredSlot();
	bool exitedSlot();
};

class KQAbstractState : public QAbstractState {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQAbstractState *dummy;
	KQAbstractState(QState* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QABSTRACTSTATE


