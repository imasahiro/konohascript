#ifndef QGRAPHICSITEMGROUP
#define QGRAPHICSITEMGROUP
class DummyQGraphicsItemGroup : public DummyQGraphicsItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsItemGroup();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQGraphicsItemGroup : public QGraphicsItemGroup {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsItemGroup *dummy;
	KQGraphicsItemGroup(QGraphicsItem* parent);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QGRAPHICSITEMGROUP


