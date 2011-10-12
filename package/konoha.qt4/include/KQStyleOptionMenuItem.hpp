#ifndef QSTYLEOPTIONMENUITEM
#define QSTYLEOPTIONMENUITEM
class DummyQStyleOptionMenuItem : public DummyQStyleOption {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionMenuItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQStyleOptionMenuItem : public QStyleOptionMenuItem, public DummyQStyleOptionMenuItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQStyleOptionMenuItem();
};

#endif //QSTYLEOPTIONMENUITEM


