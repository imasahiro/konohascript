#ifndef QOBJECT
#define QOBJECT
class DummyQObject : public QObject {
	//Q_OBJECT;
public:
	kRawPtr *self;
	std::map<std::string, kFunc *> *event_map;
	std::map<std::string, kFunc *> *slot_map;
	kFunc *child_event_func;
	kFunc *custom_event_func;
	kFunc *timer_event_func;
	kFunc *destroyed_func;
	//DummyQObject();
	//void setSelf(kRawPtr *ptr);
	//bool eventDispatcher(QEvent *event);
	//bool addEvent(kFunc *callback_func, std::string str);
	//bool signalConnect(kFunc *callback_func, std::string str);
	//void connection(QObject *o);
	//bool childEventDummy(QChildEvent* event);
	//bool customEventDummy(QEvent* event);
	//bool timerEventDummy(QTimerEvent* event);
//public slots:
//	bool destroyedSlot(QObject* obj);
};

class KQObject : public QObject {
//	Q_OBJECT;
public:
	kRawPtr *self;
	DummyQObject *dummy;
	KQObject(QObject* parent);
	//void setSelf(kRawPtr *ptr);
	//bool event(QEvent *event);
};

#endif //QOBJECT


