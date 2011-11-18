#ifndef QCHECKBOX
#define QCHECKBOX
class DummyQCheckBox : public DummyQAbstractButton {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *state_changed_func;
	DummyQCheckBox();
	virtual ~DummyQCheckBox();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool stateChangedSlot(int state);
};

class KQCheckBox : public QCheckBox {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQCheckBox *dummy;
	KQCheckBox(QWidget* parent);
	~KQCheckBox();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QCHECKBOX


