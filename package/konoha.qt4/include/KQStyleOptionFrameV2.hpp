#ifndef QSTYLEOPTIONFRAMEV2
#define QSTYLEOPTIONFRAMEV2
class DummyQStyleOptionFrameV2 : public DummyQStyleOptionFrame {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionFrameV2();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQStyleOptionFrameV2 : public QStyleOptionFrameV2 {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQStyleOptionFrameV2 *dummy;
	KQStyleOptionFrameV2();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEOPTIONFRAMEV2


