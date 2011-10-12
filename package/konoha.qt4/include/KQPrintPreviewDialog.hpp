#ifndef QPRINTPREVIEWDIALOG
#define QPRINTPREVIEWDIALOG
class DummyQPrintPreviewDialog : public DummyQDialog {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPrintPreviewDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQPrintPreviewDialog : public QPrintPreviewDialog, public DummyQPrintPreviewDialog {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQPrintPreviewDialog(QPrinter* printer, QWidget* parent, Qt::WindowFlags flags);
	bool event(QEvent *event);
};

#endif //QPRINTPREVIEWDIALOG


