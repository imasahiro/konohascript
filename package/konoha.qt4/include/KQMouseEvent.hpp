#ifndef QMOUSEEVENT
#define QMOUSEEVENT
class DummyQMouseEvent : public DummyQInputEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQMouseEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQMouseEvent : public QMouseEvent, public DummyQMouseEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQMouseEvent(QMouseEvent::Type type, const QPoint position, Qt::MouseButton button, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers);
};

#endif //QMOUSEEVENT


