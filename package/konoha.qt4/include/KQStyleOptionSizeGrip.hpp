#ifndef QSTYLEOPTIONSIZEGRIP
#define QSTYLEOPTIONSIZEGRIP
class DummyQStyleOptionSizeGrip : public DummyQStyleOptionComplex {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionSizeGrip();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQStyleOptionSizeGrip : public QStyleOptionSizeGrip {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQStyleOptionSizeGrip *dummy;
	KQStyleOptionSizeGrip();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEOPTIONSIZEGRIP


