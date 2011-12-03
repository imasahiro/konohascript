#ifndef QABSTRACTGRAPHICSSHAPEITEM
#define QABSTRACTGRAPHICSSHAPEITEM
class DummyQAbstractGraphicsShapeItem : public DummyQGraphicsItem {
//	Q_OBJECT;
public:
	kRawPtr *self;
	std::map<std::string, kFunc *> *event_map;
	std::map<std::string, kFunc *> *slot_map;
	kFunc *paint_func;
	DummyQAbstractGraphicsShapeItem();
	virtual ~DummyQAbstractGraphicsShapeItem();
	void setSelf(kRawPtr *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(kFunc *callback_func, std::string str);
	bool signalConnect(kFunc *callback_func, std::string str);
	kObject** reftrace(CTX ctx, kRawPtr *p FTRARG);
	void connection(QObject *o);
};

class KQAbstractGraphicsShapeItem : public QAbstractGraphicsShapeItem {
//	Q_OBJECT;
public:
	int magic_num;
	kRawPtr *self;
	DummyQAbstractGraphicsShapeItem *dummy;
	KQAbstractGraphicsShapeItem(QGraphicsItem* parent);
	~KQAbstractGraphicsShapeItem();
	void setSelf(kRawPtr *ptr);
	bool sceneEvent(QEvent *event);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif //QABSTRACTGRAPHICSSHAPEITEM


