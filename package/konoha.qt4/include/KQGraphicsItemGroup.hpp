#ifndef QGRAPHICSITEMGROUP
#define QGRAPHICSITEMGROUP
class DummyQGraphicsItemGroup : public DummyQGraphicsItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *paint_func;
	DummyQGraphicsItemGroup();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQGraphicsItemGroup : public QGraphicsItemGroup {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsItemGroup *dummy;
	KQGraphicsItemGroup(QGraphicsItem* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool sceneEvent(QEvent *event);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif //QGRAPHICSITEMGROUP


