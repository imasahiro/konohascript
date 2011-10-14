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
	DummyQGraphicsTextItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool linkActivatedSlot(const QString link);
	bool linkHoveredSlot(const QString link);
};

class KQGraphicsTextItem : public QGraphicsTextItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsTextItem *dummy;
	KQGraphicsTextItem(QGraphicsItem* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QGRAPHICSTEXTITEM


