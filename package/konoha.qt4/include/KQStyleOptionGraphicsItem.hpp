#ifndef QSTYLEOPTIONGRAPHICSITEM
#define QSTYLEOPTIONGRAPHICSITEM
class DummyQStyleOptionGraphicsItem : public DummyQStyleOption {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionGraphicsItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQStyleOptionGraphicsItem : public QStyleOptionGraphicsItem, public DummyQStyleOptionGraphicsItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQStyleOptionGraphicsItem();
};

#endif //QSTYLEOPTIONGRAPHICSITEM


