#ifndef QPLAINTEXTEDIT
#define QPLAINTEXTEDIT
class DummyQPlainTextEdit : public DummyQAbstractScrollArea {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *block_count_changed_func;
	knh_Func_t *copy_available_func;
	knh_Func_t *cursor_position_changed_func;
	knh_Func_t *modification_changed_func;
	knh_Func_t *redo_available_func;
	knh_Func_t *selection_changed_func;
	knh_Func_t *text_changed_func;
	knh_Func_t *undo_available_func;
	knh_Func_t *update_request_func;
	DummyQPlainTextEdit();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool blockCountChangedSlot(int new_BlockCount);
	bool copyAvailableSlot(bool yes);
	bool cursorPositionChangedSlot();
	bool modificationChangedSlot(bool changed);
	bool redoAvailableSlot(bool available);
	bool selectionChangedSlot();
	bool textChangedSlot();
	bool undoAvailableSlot(bool available);
	bool updateRequestSlot(const QRect rect, int dy);
};

class KQPlainTextEdit : public QPlainTextEdit {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQPlainTextEdit *dummy;
	KQPlainTextEdit(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QPLAINTEXTEDIT


