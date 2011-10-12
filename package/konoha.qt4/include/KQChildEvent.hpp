#ifndef QCHILDEVENT
#define QCHILDEVENT
class DummyQChildEvent : public DummyQEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQChildEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQChildEvent : public QChildEvent, public DummyQChildEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQChildEvent(QChildEvent::Type type, QObject* child);
};

#endif //QCHILDEVENT


