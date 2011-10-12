#ifndef QSTYLEOPTIONFRAMEV3
#define QSTYLEOPTIONFRAMEV3
class DummyQStyleOptionFrameV3 : public DummyQStyleOptionFrameV2 {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionFrameV3();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQStyleOptionFrameV3 : public QStyleOptionFrameV3, public DummyQStyleOptionFrameV3 {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQStyleOptionFrameV3();
};

#endif //QSTYLEOPTIONFRAMEV3


