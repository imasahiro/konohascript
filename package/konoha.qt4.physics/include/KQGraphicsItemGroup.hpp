#ifndef QGRAPHICSITEMGROUP
#define QGRAPHICSITEMGROUP
class DummyQGraphicsItemGroup : public DummyQGraphicsItem {
//	Q_OBJECT;
public:
	kRawPtr *self;
	QList<kRawPtr *> *added_list;
	std::map<std::string, kFunc *> *event_map;
	std::map<std::string, kFunc *> *slot_map;
	kFunc *paint_func;
	DummyQGraphicsItemGroup();
	virtual ~DummyQGraphicsItemGroup();
	void setSelf(kRawPtr *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(kFunc *callback_func, std::string str);
	bool signalConnect(kFunc *callback_func, std::string str);
	kObject** reftrace(CTX ctx, kRawPtr *p FTRARG);
	void connection(QObject *o);
};

class KQGraphicsItemGroup : public QGraphicsItemGroup {
//	Q_OBJECT;
public:
	int magic_num;
	kRawPtr *self;
	DummyQGraphicsItemGroup *dummy;
	KQGraphicsItemGroup(QGraphicsItem* parent);
	~KQGraphicsItemGroup();
	void setSelf(kRawPtr *ptr);
	bool sceneEvent(QEvent *event);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif //QGRAPHICSITEMGROUP


