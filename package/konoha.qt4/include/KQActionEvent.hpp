#ifndef QACTIONEVENT
#define QACTIONEVENT
class DummyQActionEvent : public DummyQEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQActionEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQActionEvent : public QActionEvent, public DummyQActionEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQActionEvent(int type, QAction* action, QAction* before);
};

#endif //QACTIONEVENT


