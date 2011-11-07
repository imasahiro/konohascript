#ifndef QTABLETEVENT
#define QTABLETEVENT
class DummyQTabletEvent : public DummyQInputEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTabletEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQTabletEvent : public QTabletEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQTabletEvent *dummy;
	KQTabletEvent(QTabletEvent::Type type, const QPoint pos, const QPoint globalPos, const QPointF hiResGlobalPos, int device, int pointerType, qreal pressure, int xTilt, int yTilt, qreal tangentialPressure, qreal rotation, int z, Qt::KeyboardModifiers keyState, qint64 uniqueID);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QTABLETEVENT


