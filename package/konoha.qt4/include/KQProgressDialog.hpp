#ifndef QPROGRESSDIALOG
#define QPROGRESSDIALOG
class DummyQProgressDialog : public DummyQDialog {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *canceled_func;
	DummyQProgressDialog();
	virtual ~DummyQProgressDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool canceledSlot();
};

class KQProgressDialog : public QProgressDialog {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQProgressDialog *dummy;
	KQProgressDialog(QWidget* parent, Qt::WindowFlags f);
	~KQProgressDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QPROGRESSDIALOG


