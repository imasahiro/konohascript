#ifndef QGRAPHICSLAYOUTITEM
#define QGRAPHICSLAYOUTITEM
class DummyQGraphicsLayoutItem {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsLayoutItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsLayoutItem : public QGraphicsLayoutItem, public DummyQGraphicsLayoutItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsLayoutItem(QGraphicsLayoutItem* parent, bool isLayout);
};

#endif //QGRAPHICSLAYOUTITEM


