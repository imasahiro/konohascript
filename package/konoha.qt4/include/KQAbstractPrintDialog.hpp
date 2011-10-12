#ifndef QABSTRACTPRINTDIALOG
#define QABSTRACTPRINTDIALOG
class DummyQAbstractPrintDialog : public DummyQDialog {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAbstractPrintDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQAbstractPrintDialog : public QAbstractPrintDialog, public DummyQAbstractPrintDialog {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQAbstractPrintDialog(QPrinter* printer, QWidget* parent);
	bool event(QEvent *event);
};

#endif //QABSTRACTPRINTDIALOG


