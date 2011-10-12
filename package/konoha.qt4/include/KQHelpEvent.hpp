#ifndef QHELPEVENT
#define QHELPEVENT
class DummyQHelpEvent : public DummyQEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQHelpEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQHelpEvent : public QHelpEvent, public DummyQHelpEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQHelpEvent(QHelpEvent::Type type, const QPoint pos, const QPoint globalPos);
};

#endif //QHELPEVENT


