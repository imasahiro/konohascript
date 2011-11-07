#ifndef QTEXTDOCUMENT
#define QTEXTDOCUMENT
class DummyQTextDocument : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *block_count_changed_func;
	knh_Func_t *contents_change_func;
	knh_Func_t *contents_changed_func;
	knh_Func_t *cursor_position_changed_func;
	knh_Func_t *document_layout_changed_func;
	knh_Func_t *modification_changed_func;
	knh_Func_t *redo_available_func;
	knh_Func_t *undo_available_func;
	knh_Func_t *undo_command_added_func;
	DummyQTextDocument();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool blockCountChangedSlot(int new_BlockCount);
	bool contentsChangeSlot(int position, int charsRemoved, int charsAdded);
	bool contentsChangedSlot();
	bool cursorPositionChangedSlot(const QTextCursor cursor);
	bool documentLayoutChangedSlot();
	bool modificationChangedSlot(bool changed);
	bool redoAvailableSlot(bool available);
	bool undoAvailableSlot(bool available);
	bool undoCommandAddedSlot();
};

class KQTextDocument : public QTextDocument {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQTextDocument *dummy;
	KQTextDocument(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QTEXTDOCUMENT


