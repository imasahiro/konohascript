#ifndef QSTYLEOPTIONMENUITEM
#define QSTYLEOPTIONMENUITEM
class DummyQStyleOptionMenuItem : public DummyQStyleOption {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionMenuItem();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQStyleOptionMenuItem : public QStyleOptionMenuItem {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQStyleOptionMenuItem *dummy;
	KQStyleOptionMenuItem();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEOPTIONMENUITEM


