#ifndef QOBJECT
#define QOBJECT
class DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *child_event_func;
	knh_Func_t *custom_event_func;
	knh_Func_t *timer_event_func;
	DummyQObject();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool childEvent(QChildEvent* event);
	bool customEvent(QEvent* event);
	bool timerEvent(QTimerEvent* event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQObject : public QObject, public DummyQObject {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQObject(QObject* parent);
	bool event(QEvent *event);
};

#endif //QOBJECT


