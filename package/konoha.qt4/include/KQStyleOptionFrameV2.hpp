#ifndef QSTYLEOPTIONFRAMEV2
#define QSTYLEOPTIONFRAMEV2
class DummyQStyleOptionFrameV2 : public DummyQStyleOptionFrame {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionFrameV2();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQStyleOptionFrameV2 : public QStyleOptionFrameV2, public DummyQStyleOptionFrameV2 {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQStyleOptionFrameV2();
};

#endif //QSTYLEOPTIONFRAMEV2


