#ifndef QSTYLEOPTIONHEADER
#define QSTYLEOPTIONHEADER
class DummyQStyleOptionHeader : public DummyQStyleOption {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionHeader();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQStyleOptionHeader : public QStyleOptionHeader, public DummyQStyleOptionHeader {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQStyleOptionHeader();
};

#endif //QSTYLEOPTIONHEADER


