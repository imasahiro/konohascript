#ifndef QSTYLEOPTIONCOMPLEX
#define QSTYLEOPTIONCOMPLEX
class DummyQStyleOptionComplex : public DummyQStyleOption {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionComplex();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQStyleOptionComplex : public QStyleOptionComplex {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQStyleOptionComplex *dummy;
	KQStyleOptionComplex(int version, int type);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEOPTIONCOMPLEX


