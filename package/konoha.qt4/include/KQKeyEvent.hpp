#ifndef QKEYEVENT
#define QKEYEVENT
class DummyQKeyEvent : public DummyQInputEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQKeyEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQKeyEvent : public QKeyEvent, public DummyQKeyEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQKeyEvent(QKeyEvent::Type type, int key, Qt::KeyboardModifiers modifiers, const QString text, bool autorep, ushort count);
};

#endif //QKEYEVENT


