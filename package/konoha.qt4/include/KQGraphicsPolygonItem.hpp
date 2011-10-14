#ifndef QGRAPHICSPOLYGONITEM
#define QGRAPHICSPOLYGONITEM
class DummyQGraphicsPolygonItem : public DummyQAbstractGraphicsShapeItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsPolygonItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQGraphicsPolygonItem : public QGraphicsPolygonItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsPolygonItem *dummy;
	KQGraphicsPolygonItem(QGraphicsItem* parent);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QGRAPHICSPOLYGONITEM


