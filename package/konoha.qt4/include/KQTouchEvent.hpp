#ifndef QTOUCHEVENT
#define QTOUCHEVENT
class DummyQTouchEvent : public DummyQInputEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTouchEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTouchEvent : public QTouchEvent, public DummyQTouchEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQTouchEvent(QEvent::Type eventType, QTouchEvent::DeviceType deviceType, Qt::KeyboardModifiers modifiers, Qt::TouchPointStates touchPointStates, const QList<QTouchEvent::TouchPoint> touchPoints);
};

#endif //QTOUCHEVENT


