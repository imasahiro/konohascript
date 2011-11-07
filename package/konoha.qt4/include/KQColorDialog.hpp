#ifndef QCOLORDIALOG
#define QCOLORDIALOG
class DummyQColorDialog : public DummyQDialog {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *color_selected_func;
	knh_Func_t *current_color_changed_func;
	DummyQColorDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool colorSelectedSlot(const QColor color);
	bool currentColorChangedSlot(const QColor color);
};

class KQColorDialog : public QColorDialog {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQColorDialog *dummy;
	KQColorDialog(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QCOLORDIALOG


