#ifndef QDOUBLESPINBOX
#define QDOUBLESPINBOX
class DummyQDoubleSpinBox : public DummyQAbstractSpinBox {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQDoubleSpinBox();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQDoubleSpinBox : public QDoubleSpinBox {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQDoubleSpinBox *dummy;
	KQDoubleSpinBox(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QDOUBLESPINBOX


