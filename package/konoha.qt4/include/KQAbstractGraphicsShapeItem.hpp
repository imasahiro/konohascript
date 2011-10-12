#ifndef QABSTRACTGRAPHICSSHAPEITEM
#define QABSTRACTGRAPHICSSHAPEITEM
class DummyQAbstractGraphicsShapeItem : public DummyQGraphicsItem {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAbstractGraphicsShapeItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQAbstractGraphicsShapeItem : public QAbstractGraphicsShapeItem, public DummyQAbstractGraphicsShapeItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQAbstractGraphicsShapeItem(QGraphicsItem* parent);
};

#endif //QABSTRACTGRAPHICSSHAPEITEM


