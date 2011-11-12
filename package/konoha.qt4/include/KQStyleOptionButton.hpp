#ifndef QSTYLEOPTIONBUTTON
#define QSTYLEOPTIONBUTTON
class DummyQStyleOptionButton : public DummyQStyleOption {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionButton();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQStyleOptionButton : public QStyleOptionButton {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQStyleOptionButton *dummy;
	KQStyleOptionButton();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEOPTIONBUTTON


