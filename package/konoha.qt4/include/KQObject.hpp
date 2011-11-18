#ifndef QOBJECT
#define QOBJECT
class DummyQObject : public QObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *child_event_func;
	knh_Func_t *custom_event_func;
	knh_Func_t *timer_event_func;
	knh_Func_t *destroyed_func;
	knh_RawPtr_t *childEventPtr;
	knh_RawPtr_t *customEventPtr;
	knh_RawPtr_t *timerEventPtr;
	DummyQObject();
	virtual ~DummyQObject();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
	bool childEventDummy(QChildEvent* event);
	bool customEventDummy(QEvent* event);
	bool timerEventDummy(QTimerEvent* event);
public slots:
	bool destroyedSlot(QObject* obj);
};

class KQObject : public QObject {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQObject *dummy;
	KQObject(QObject* parent);
	~KQObject();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QOBJECT


