#ifndef QLINEEDIT
#define QLINEEDIT
class DummyQLineEdit : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *cursor_position_changed_func;
	knh_Func_t *editing_finished_func;
	knh_Func_t *return_pressed_func;
	knh_Func_t *selection_changed_func;
	knh_Func_t *text_changed_func;
	knh_Func_t *text_edited_func;
	DummyQLineEdit();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool cursorPositionChangedSlot(int old, int new_);
	bool editingFinishedSlot();
	bool returnPressedSlot();
	bool selectionChangedSlot();
	bool textChangedSlot(const QString text);
	bool textEditedSlot(const QString text);
};

class KQLineEdit : public QLineEdit {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQLineEdit *dummy;
	KQLineEdit(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QLINEEDIT


