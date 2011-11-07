#ifndef QABSTRACTBUTTON
#define QABSTRACTBUTTON
class DummyQAbstractButton : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *clicked_func;
	knh_Func_t *pressed_func;
	knh_Func_t *released_func;
	knh_Func_t *toggled_func;
	DummyQAbstractButton();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool clickedSlot(bool checked);
	bool pressedSlot();
	bool releasedSlot();
	bool toggledSlot(bool checked);
};

class KQAbstractButton : public QAbstractButton {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQAbstractButton *dummy;
	KQAbstractButton(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QABSTRACTBUTTON


