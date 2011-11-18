#ifndef QINPUTDIALOG
#define QINPUTDIALOG
class DummyQInputDialog : public DummyQDialog {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *double_value_changed_func;
	knh_Func_t *double_value_selected_func;
	knh_Func_t *int_value_changed_func;
	knh_Func_t *int_value_selected_func;
	knh_Func_t *text_value_changed_func;
	knh_Func_t *text_value_selected_func;
	DummyQInputDialog();
	virtual ~DummyQInputDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool doubleValueChangedSlot(double value);
	bool doubleValueSelectedSlot(double value);
	bool intValueChangedSlot(int value);
	bool intValueSelectedSlot(int value);
	bool textValueChangedSlot(const QString text);
	bool textValueSelectedSlot(const QString text);
};

class KQInputDialog : public QInputDialog {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQInputDialog *dummy;
	KQInputDialog(QWidget* parent, Qt::WindowFlags flags);
	~KQInputDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QINPUTDIALOG


