#ifndef QPROGRESSDIALOG
#define QPROGRESSDIALOG
class DummyQProgressDialog : public DummyQDialog {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQProgressDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQProgressDialog : public QProgressDialog, public DummyQProgressDialog {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQProgressDialog(QWidget* parent, Qt::WindowFlags f);
	bool event(QEvent *event);
};

#endif //QPROGRESSDIALOG


