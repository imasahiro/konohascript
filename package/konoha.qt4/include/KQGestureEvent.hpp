#ifndef QGESTUREEVENT
#define QGESTUREEVENT
class DummyQGestureEvent : public DummyQEvent {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGestureEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGestureEvent : public QGestureEvent, public DummyQGestureEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGestureEvent(const QList<QGesture*> gestures);
};

#endif //QGESTUREEVENT


