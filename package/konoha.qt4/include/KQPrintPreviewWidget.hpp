#ifndef QPRINTPREVIEWWIDGET
#define QPRINTPREVIEWWIDGET
class DummyQPrintPreviewWidget : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPrintPreviewWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQPrintPreviewWidget : public QPrintPreviewWidget, public DummyQPrintPreviewWidget {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQPrintPreviewWidget(QPrinter* printer, QWidget* parent, Qt::WindowFlags flags);
	bool event(QEvent *event);
};

#endif //QPRINTPREVIEWWIDGET


