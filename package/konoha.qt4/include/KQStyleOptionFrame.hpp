#ifndef QSTYLEOPTIONFRAME
#define QSTYLEOPTIONFRAME
class DummyQStyleOptionFrame : public DummyQStyleOption {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionFrame();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQStyleOptionFrame : public QStyleOptionFrame {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQStyleOptionFrame *dummy;
	KQStyleOptionFrame();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEOPTIONFRAME


