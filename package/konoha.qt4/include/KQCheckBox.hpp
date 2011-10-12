#ifndef QCHECKBOX
#define QCHECKBOX
class DummyQCheckBox : public DummyQAbstractButton {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQCheckBox();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQCheckBox : public QCheckBox, public DummyQCheckBox {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQCheckBox(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QCHECKBOX


