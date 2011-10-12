#ifndef QEVENT
#define QEVENT
class DummyQEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQEvent : public QEvent, public DummyQEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQEvent(QEvent::Type type);
};

#endif //QEVENT


