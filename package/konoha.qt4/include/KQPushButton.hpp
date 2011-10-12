#ifndef QPUSHBUTTON
#define QPUSHBUTTON
class DummyQPushButton : public DummyQAbstractButton {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPushButton();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQPushButton : public QPushButton, public DummyQPushButton {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQPushButton(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QPUSHBUTTON


