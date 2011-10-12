#ifndef QHOVEREVENT
#define QHOVEREVENT
class DummyQHoverEvent : public DummyQEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQHoverEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQHoverEvent : public QHoverEvent, public DummyQHoverEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQHoverEvent(QHoverEvent::Type type, const QPoint pos, const QPoint oldPos);
};

#endif //QHOVEREVENT


