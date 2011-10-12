#ifndef QGRAPHICSSIMPLETEXTITEM
#define QGRAPHICSSIMPLETEXTITEM
class DummyQGraphicsSimpleTextItem : public DummyQAbstractGraphicsShapeItem {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsSimpleTextItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsSimpleTextItem : public QGraphicsSimpleTextItem, public DummyQGraphicsSimpleTextItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsSimpleTextItem(QGraphicsItem* parent);
};

#endif //QGRAPHICSSIMPLETEXTITEM


