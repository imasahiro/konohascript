#ifndef QABSTRACTSLIDER
#define QABSTRACTSLIDER
class DummyQAbstractSlider : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAbstractSlider();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQAbstractSlider : public QAbstractSlider, public DummyQAbstractSlider {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQAbstractSlider(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QABSTRACTSLIDER


