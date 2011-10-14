#ifndef QABSTRACTGRAPHICSSHAPEITEM
#define QABSTRACTGRAPHICSSHAPEITEM
class DummyQAbstractGraphicsShapeItem : public DummyQGraphicsItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAbstractGraphicsShapeItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQAbstractGraphicsShapeItem : public QAbstractGraphicsShapeItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQAbstractGraphicsShapeItem *dummy;
	KQAbstractGraphicsShapeItem(QGraphicsItem* parent);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QABSTRACTGRAPHICSSHAPEITEM


