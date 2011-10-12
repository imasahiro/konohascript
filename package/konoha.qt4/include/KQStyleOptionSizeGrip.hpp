#ifndef QSTYLEOPTIONSIZEGRIP
#define QSTYLEOPTIONSIZEGRIP
class DummyQStyleOptionSizeGrip : public DummyQStyleOptionComplex {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionSizeGrip();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQStyleOptionSizeGrip : public QStyleOptionSizeGrip, public DummyQStyleOptionSizeGrip {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQStyleOptionSizeGrip();
};

#endif //QSTYLEOPTIONSIZEGRIP


