#ifndef QPRINTPREVIEWDIALOG
#define QPRINTPREVIEWDIALOG
class DummyQPrintPreviewDialog : public DummyQDialog {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *paint_requested_func;
	DummyQPrintPreviewDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool paintRequestedSlot(QPrinter* printer);
};

class KQPrintPreviewDialog : public QPrintPreviewDialog {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQPrintPreviewDialog *dummy;
	KQPrintPreviewDialog(QPrinter* printer, QWidget* parent, Qt::WindowFlags flags);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QPRINTPREVIEWDIALOG


