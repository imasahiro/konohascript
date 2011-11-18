#ifndef QSTYLEOPTIONCOMPLEX
#define QSTYLEOPTIONCOMPLEX
class DummyQStyleOptionComplex : public DummyQStyleOption {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionComplex();
	virtual ~DummyQStyleOptionComplex();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQStyleOptionComplex : public QStyleOptionComplex {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQStyleOptionComplex *dummy;
	KQStyleOptionComplex(int version, int type);
	~KQStyleOptionComplex();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEOPTIONCOMPLEX


