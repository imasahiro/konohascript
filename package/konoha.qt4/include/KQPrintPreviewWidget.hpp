#ifndef QPRINTPREVIEWWIDGET
#define QPRINTPREVIEWWIDGET
class DummyQPrintPreviewWidget : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *paint_requested_func;
	knh_Func_t *preview_changed_func;
	DummyQPrintPreviewWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool paintRequestedSlot(QPrinter* printer);
	bool previewChangedSlot();
};

class KQPrintPreviewWidget : public QPrintPreviewWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQPrintPreviewWidget *dummy;
	KQPrintPreviewWidget(QPrinter* printer, QWidget* parent, Qt::WindowFlags flags);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QPRINTPREVIEWWIDGET


