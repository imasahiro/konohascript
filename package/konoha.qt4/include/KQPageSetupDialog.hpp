#ifndef QPAGESETUPDIALOG
#define QPAGESETUPDIALOG
class DummyQPageSetupDialog : public DummyQDialog {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPageSetupDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQPageSetupDialog : public QPageSetupDialog, public DummyQPageSetupDialog {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQPageSetupDialog(QPrinter* printer, QWidget* parent);
	bool event(QEvent *event);
};

#endif //QPAGESETUPDIALOG


