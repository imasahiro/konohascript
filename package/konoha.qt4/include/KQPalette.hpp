#ifndef QPALETTE
#define QPALETTE
class DummyQPalette {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPalette();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQPalette : public QPalette {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQPalette *dummy;
	KQPalette();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QPALETTE


