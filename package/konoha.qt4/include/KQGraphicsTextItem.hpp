#ifndef QGRAPHICSTEXTITEM
#define QGRAPHICSTEXTITEM
class DummyQGraphicsTextItem : public DummyQGraphicsObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *link_activated_func;
	knh_Func_t *link_hovered_func;
	knh_Func_t *paint_func;
	DummyQGraphicsTextItem();
	virtual ~DummyQGraphicsTextItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool linkActivatedSlot(const QString link);
	bool linkHoveredSlot(const QString link);
};

class KQGraphicsTextItem : public QGraphicsTextItem {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQGraphicsTextItem *dummy;
	KQGraphicsTextItem(QGraphicsItem* parent);
	~KQGraphicsTextItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool sceneEvent(QEvent *event);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif //QGRAPHICSTEXTITEM


