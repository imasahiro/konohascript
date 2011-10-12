#ifndef QGRAPHICSPOLYGONITEM
#define QGRAPHICSPOLYGONITEM
class DummyQGraphicsPolygonItem : public DummyQAbstractGraphicsShapeItem {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsPolygonItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsPolygonItem : public QGraphicsPolygonItem, public DummyQGraphicsPolygonItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsPolygonItem(QGraphicsItem* parent);
};

#endif //QGRAPHICSPOLYGONITEM


