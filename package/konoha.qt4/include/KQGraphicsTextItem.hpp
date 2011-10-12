#ifndef QGRAPHICSTEXTITEM
#define QGRAPHICSTEXTITEM
class DummyQGraphicsTextItem : public DummyQGraphicsObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsTextItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsTextItem : public QGraphicsTextItem, public DummyQGraphicsTextItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsTextItem(QGraphicsItem* parent);
	bool event(QEvent *event);
};

#endif //QGRAPHICSTEXTITEM


