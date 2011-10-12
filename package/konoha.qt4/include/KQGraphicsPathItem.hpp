#ifndef QGRAPHICSPATHITEM
#define QGRAPHICSPATHITEM
class DummyQGraphicsPathItem : public DummyQAbstractGraphicsShapeItem {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsPathItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsPathItem : public QGraphicsPathItem, public DummyQGraphicsPathItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsPathItem(QGraphicsItem* parent);
};

#endif //QGRAPHICSPATHITEM


