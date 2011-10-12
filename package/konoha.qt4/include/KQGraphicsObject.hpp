#ifndef QGRAPHICSOBJECT
#define QGRAPHICSOBJECT
class DummyQGraphicsObject : public DummyQGraphicsItem, public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsObject();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsObject : public QGraphicsObject, public DummyQGraphicsObject {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsObject(QGraphicsItem* parent);
	bool event(QEvent *event);
};

#endif //QGRAPHICSOBJECT


