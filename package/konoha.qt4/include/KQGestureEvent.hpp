#ifndef QGESTUREEVENT
#define QGESTUREEVENT
class DummyQGestureEvent : public DummyQEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGestureEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQGestureEvent : public QGestureEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGestureEvent *dummy;
	KQGestureEvent(const QList<QGesture*> gestures);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QGESTUREEVENT


