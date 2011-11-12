#ifndef QTOUCHEVENT
#define QTOUCHEVENT
class DummyQTouchEvent : public DummyQInputEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTouchEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQTouchEvent : public QTouchEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQTouchEvent *dummy;
	KQTouchEvent(QEvent::Type eventType, QTouchEvent::DeviceType deviceType, Qt::KeyboardModifiers modifiers, Qt::TouchPointStates touchPointStates, const QList<QTouchEvent::TouchPoint> touchPoints);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QTOUCHEVENT


