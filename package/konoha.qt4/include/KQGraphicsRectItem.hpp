#ifndef QGRAPHICSRECTITEM
#define QGRAPHICSRECTITEM
class DummyQGraphicsRectItem : public DummyQAbstractGraphicsShapeItem {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsRectItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsRectItem : public QGraphicsRectItem, public DummyQGraphicsRectItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsRectItem(QGraphicsItem* parent);
};

#endif //QGRAPHICSRECTITEM


