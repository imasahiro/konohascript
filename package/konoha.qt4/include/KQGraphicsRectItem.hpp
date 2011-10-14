#ifndef QGRAPHICSRECTITEM
#define QGRAPHICSRECTITEM
class DummyQGraphicsRectItem : public DummyQAbstractGraphicsShapeItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsRectItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQGraphicsRectItem : public QGraphicsRectItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsRectItem *dummy;
	KQGraphicsRectItem(QGraphicsItem* parent);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QGRAPHICSRECTITEM


