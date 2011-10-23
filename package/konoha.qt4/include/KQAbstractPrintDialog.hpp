#ifndef QABSTRACTPRINTDIALOG
#define QABSTRACTPRINTDIALOG
class DummyQAbstractPrintDialog : public DummyQDialog {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQAbstractPrintDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQAbstractPrintDialog : public QAbstractPrintDialog {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQAbstractPrintDialog *dummy;
	KQAbstractPrintDialog(QPrinter* printer, QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QABSTRACTPRINTDIALOG

