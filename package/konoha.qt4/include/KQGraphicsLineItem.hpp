#ifndef QGRAPHICSLINEITEM
#define QGRAPHICSLINEITEM
class DummyQGraphicsLineItem : public DummyQGraphicsItem {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsLineItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsLineItem : public QGraphicsLineItem, public DummyQGraphicsLineItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsLineItem(QGraphicsItem* parent);
};

#endif //QGRAPHICSLINEITEM


