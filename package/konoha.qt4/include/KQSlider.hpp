#ifndef QSLIDER
#define QSLIDER
class DummyQSlider : public DummyQAbstractSlider {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQSlider();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQSlider : public QSlider, public DummyQSlider {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQSlider(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QSLIDER


