#ifndef QABSTRACTSLIDER
#define QABSTRACTSLIDER
class DummyQAbstractSlider : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *action_triggered_func;
	knh_Func_t *range_changed_func;
	knh_Func_t *slider_moved_func;
	knh_Func_t *slider_pressed_func;
	knh_Func_t *slider_released_func;
	knh_Func_t *value_changed_func;
	DummyQAbstractSlider();
	virtual ~DummyQAbstractSlider();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool actionTriggeredSlot(int action);
	bool rangeChangedSlot(int min, int max);
	bool sliderMovedSlot(int value);
	bool sliderPressedSlot();
	bool sliderReleasedSlot();
	bool valueChangedSlot(int value);
};

class KQAbstractSlider : public QAbstractSlider {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQAbstractSlider *dummy;
	KQAbstractSlider(QWidget* parent);
	~KQAbstractSlider();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QABSTRACTSLIDER


