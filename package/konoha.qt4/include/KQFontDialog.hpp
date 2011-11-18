#ifndef QFONTDIALOG
#define QFONTDIALOG
class DummyQFontDialog : public DummyQDialog {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *current_font_changed_func;
	knh_Func_t *font_selected_func;
	DummyQFontDialog();
	virtual ~DummyQFontDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool currentFontChangedSlot(const QFont font);
	bool fontSelectedSlot(const QFont font);
};

class KQFontDialog : public QFontDialog {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQFontDialog *dummy;
	KQFontDialog(QWidget* parent);
	~KQFontDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QFONTDIALOG


