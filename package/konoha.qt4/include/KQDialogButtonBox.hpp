#ifndef QDIALOGBUTTONBOX
#define QDIALOGBUTTONBOX
class DummyQDialogButtonBox : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *accepted_func;
	knh_Func_t *clicked_func;
	knh_Func_t *help_requested_func;
	knh_Func_t *rejected_func;
	DummyQDialogButtonBox();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool acceptedSlot();
	bool clickedSlot(QAbstractButton* button);
	bool helpRequestedSlot();
	bool rejectedSlot();
};

class KQDialogButtonBox : public QDialogButtonBox {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQDialogButtonBox *dummy;
	KQDialogButtonBox(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QDIALOGBUTTONBOX


