#ifndef QSTATE
#define QSTATE
class DummyQState : public DummyQAbstractState {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *finished_func;
	knh_Func_t *properties_assigned_func;
	DummyQState();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool finishedSlot();
	bool propertiesAssignedSlot();
};

class KQState : public QState {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQState *dummy;
	KQState(QState* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QSTATE


