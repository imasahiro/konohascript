#ifndef QSPINBOX
#define QSPINBOX
class DummyQSpinBox : public DummyQAbstractSpinBox {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQSpinBox();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQSpinBox : public QSpinBox, public DummyQSpinBox {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQSpinBox(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QSPINBOX


