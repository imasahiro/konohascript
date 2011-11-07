#ifndef QPAGESETUPDIALOG
#define QPAGESETUPDIALOG
class DummyQPageSetupDialog : public DummyQDialog {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPageSetupDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQPageSetupDialog : public QPageSetupDialog {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQPageSetupDialog *dummy;
	KQPageSetupDialog(QPrinter* printer, QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QPAGESETUPDIALOG


