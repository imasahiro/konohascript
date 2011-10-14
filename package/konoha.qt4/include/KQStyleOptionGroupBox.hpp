#ifndef QSTYLEOPTIONGROUPBOX
#define QSTYLEOPTIONGROUPBOX
class DummyQStyleOptionGroupBox : public DummyQStyleOptionComplex {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionGroupBox();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQStyleOptionGroupBox : public QStyleOptionGroupBox {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQStyleOptionGroupBox *dummy;
	KQStyleOptionGroupBox();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEOPTIONGROUPBOX


