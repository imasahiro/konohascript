#ifndef QDIAL
#define QDIAL
class DummyQDial : public DummyQAbstractSlider {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDial();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQDial : public QDial, public DummyQDial {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQDial(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QDIAL


