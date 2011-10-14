#ifndef QGRAPHICSSCENEMOUSEEVENT
#define QGRAPHICSSCENEMOUSEEVENT
class DummyQGraphicsSceneMouseEvent : public DummyQGraphicsSceneEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsSceneMouseEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQGraphicsSceneMouseEvent : public QGraphicsSceneMouseEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsSceneMouseEvent *dummy;
	KQGraphicsSceneMouseEvent();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QGRAPHICSSCENEMOUSEEVENT


