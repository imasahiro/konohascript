#ifndef QCONTEXTMENUEVENT
#define QCONTEXTMENUEVENT
class DummyQContextMenuEvent : public DummyQInputEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQContextMenuEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQContextMenuEvent : public QContextMenuEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQContextMenuEvent *dummy;
	KQContextMenuEvent(QContextMenuEvent::Reason reason, const QPoint pos, const QPoint globalPos, Qt::KeyboardModifiers modifiers);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QCONTEXTMENUEVENT


