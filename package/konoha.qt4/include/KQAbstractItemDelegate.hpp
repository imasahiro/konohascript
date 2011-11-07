#ifndef QABSTRACTITEMDELEGATE
#define QABSTRACTITEMDELEGATE
class DummyQAbstractItemDelegate : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *close_editor_func;
	knh_Func_t *commit_data_func;
	knh_Func_t *size_hint_changed_func;
	DummyQAbstractItemDelegate();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool closeEditorSlot(QWidget* editor, QAbstractItemDelegate::EndEditHint hint);
	bool commitDataSlot(QWidget* editor);
	bool sizeHintChangedSlot(const QModelIndex index);
};

class KQAbstractItemDelegate : public QAbstractItemDelegate {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQAbstractItemDelegate *dummy;
	KQAbstractItemDelegate(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QABSTRACTITEMDELEGATE


