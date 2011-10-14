#ifndef QGRAPHICSELLIPSEITEM
#define QGRAPHICSELLIPSEITEM
class DummyQGraphicsEllipseItem : public DummyQAbstractGraphicsShapeItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsEllipseItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQGraphicsEllipseItem : public QGraphicsEllipseItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsEllipseItem *dummy;
	KQGraphicsEllipseItem(QGraphicsItem* parent);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QGRAPHICSELLIPSEITEM


