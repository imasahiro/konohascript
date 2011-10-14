#ifndef QABSTRACTTRANSITION
#define QABSTRACTTRANSITION
class DummyQAbstractTransition : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *triggered_func;
	DummyQAbstractTransition();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool triggeredSlot();
};

class KQAbstractTransition : public QAbstractTransition {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQAbstractTransition *dummy;
	KQAbstractTransition(QState* sourceState);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QABSTRACTTRANSITION


