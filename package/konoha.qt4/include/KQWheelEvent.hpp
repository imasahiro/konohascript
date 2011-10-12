#ifndef QWHEELEVENT
#define QWHEELEVENT
class DummyQWheelEvent : public DummyQInputEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQWheelEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQWheelEvent : public QWheelEvent, public DummyQWheelEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQWheelEvent(const QPoint pos, int delta, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers, Qt::Orientation orient);
};

#endif //QWHEELEVENT


