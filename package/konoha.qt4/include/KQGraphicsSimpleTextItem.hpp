#ifndef QGRAPHICSSIMPLETEXTITEM
#define QGRAPHICSSIMPLETEXTITEM
class DummyQGraphicsSimpleTextItem : public DummyQAbstractGraphicsShapeItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *paint_func;
	DummyQGraphicsSimpleTextItem();
	virtual ~DummyQGraphicsSimpleTextItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQGraphicsSimpleTextItem : public QGraphicsSimpleTextItem {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQGraphicsSimpleTextItem *dummy;
	KQGraphicsSimpleTextItem(QGraphicsItem* parent);
	~KQGraphicsSimpleTextItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool sceneEvent(QEvent *event);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif //QGRAPHICSSIMPLETEXTITEM


