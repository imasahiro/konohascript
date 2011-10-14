#ifndef QGRAPHICSPATHITEM
#define QGRAPHICSPATHITEM
class DummyQGraphicsPathItem : public DummyQAbstractGraphicsShapeItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsPathItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQGraphicsPathItem : public QGraphicsPathItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsPathItem *dummy;
	KQGraphicsPathItem(QGraphicsItem* parent);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QGRAPHICSPATHITEM


