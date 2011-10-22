#ifndef QRADIOBUTTON
#define QRADIOBUTTON
class DummyQRadioButton : public DummyQAbstractButton {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQRadioButton();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQRadioButton : public QRadioButton {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQRadioButton *dummy;
	KQRadioButton(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QRADIOBUTTON

