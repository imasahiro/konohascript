#ifndef QPRINTDIALOG
#define QPRINTDIALOG
class DummyQPrintDialog : public DummyQAbstractPrintDialog {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPrintDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQPrintDialog : public QPrintDialog, public DummyQPrintDialog {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQPrintDialog(QPrinter* printer, QWidget* parent);
	bool event(QEvent *event);
};

#endif //QPRINTDIALOG


