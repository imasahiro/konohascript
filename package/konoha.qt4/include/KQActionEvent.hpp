#ifndef QACTIONEVENT
#define QACTIONEVENT
class DummyQActionEvent : public DummyQEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQActionEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQActionEvent : public QActionEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQActionEvent *dummy;
	KQActionEvent(int type, QAction* action, QAction* before);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QACTIONEVENT


