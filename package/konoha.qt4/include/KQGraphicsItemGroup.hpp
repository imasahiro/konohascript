#ifndef QGRAPHICSITEMGROUP
#define QGRAPHICSITEMGROUP
class DummyQGraphicsItemGroup : public DummyQGraphicsItem {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsItemGroup();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQGraphicsItemGroup : public QGraphicsItemGroup, public DummyQGraphicsItemGroup {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQGraphicsItemGroup(QGraphicsItem* parent);
};

#endif //QGRAPHICSITEMGROUP


