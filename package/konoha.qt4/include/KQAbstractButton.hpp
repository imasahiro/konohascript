#ifndef QABSTRACTBUTTON
#define QABSTRACTBUTTON
class DummyQAbstractButton : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAbstractButton();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQAbstractButton : public QAbstractButton, public DummyQAbstractButton {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQAbstractButton(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QABSTRACTBUTTON


