#ifndef QCONTEXTMENUEVENT
#define QCONTEXTMENUEVENT
class DummyQContextMenuEvent : public DummyQInputEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQContextMenuEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQContextMenuEvent : public QContextMenuEvent, public DummyQContextMenuEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQContextMenuEvent(QContextMenuEvent::Reason reason, const QPoint pos, const QPoint globalPos, Qt::KeyboardModifiers modifiers);
};

#endif //QCONTEXTMENUEVENT


