#ifndef QUNDOGROUP
#define QUNDOGROUP
class DummyQUndoGroup : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *active_stack_changed_func;
	knh_Func_t *can_redo_changed_func;
	knh_Func_t *can_undo_changed_func;
	knh_Func_t *clean_changed_func;
	knh_Func_t *index_changed_func;
	knh_Func_t *redo_text_changed_func;
	knh_Func_t *undo_text_changed_func;
	DummyQUndoGroup();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool activeStackChangedSlot(QUndoStack* stack);
	bool canRedoChangedSlot(bool canRedo);
	bool canUndoChangedSlot(bool canUndo);
	bool cleanChangedSlot(bool clean);
	bool indexChangedSlot(int idx);
	bool redoTextChangedSlot(const QString redoText);
	bool undoTextChangedSlot(const QString undoText);
};

class KQUndoGroup : public QUndoGroup {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQUndoGroup *dummy;
	KQUndoGroup(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QUNDOGROUP


