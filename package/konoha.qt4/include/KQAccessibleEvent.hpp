#ifndef QACCESSIBLEEVENT
#define QACCESSIBLEEVENT
class DummyQAccessibleEvent : public DummyQEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAccessibleEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQAccessibleEvent : public QAccessibleEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQAccessibleEvent *dummy;
	KQAccessibleEvent(QAccessibleEvent::Type type, int child);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QACCESSIBLEEVENT


