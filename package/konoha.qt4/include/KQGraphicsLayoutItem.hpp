#ifndef QGRAPHICSLAYOUTITEM
#define QGRAPHICSLAYOUTITEM
class DummyQGraphicsLayoutItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsLayoutItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQGraphicsLayoutItem : public QGraphicsLayoutItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsLayoutItem *dummy;
	KQGraphicsLayoutItem(QGraphicsLayoutItem* parent, bool isLayout);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QGRAPHICSLAYOUTITEM


