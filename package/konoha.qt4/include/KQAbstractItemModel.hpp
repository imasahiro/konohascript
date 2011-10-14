#ifndef QABSTRACTITEMMODEL
#define QABSTRACTITEMMODEL
class DummyQAbstractItemModel : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *columns_about_to_be_inserted_func;
	knh_Func_t *columns_about_to_be_moved_func;
	knh_Func_t *columns_about_to_be_removed_func;
	knh_Func_t *columns_inserted_func;
	knh_Func_t *columns_moved_func;
	knh_Func_t *columns_removed_func;
	knh_Func_t *data_changed_func;
	knh_Func_t *header_data_changed_func;
	knh_Func_t *layout_about_to_be_changed_func;
	knh_Func_t *layout_changed_func;
	knh_Func_t *model_about_to_be_reset_func;
	knh_Func_t *model_reset_func;
	knh_Func_t *rows_about_to_be_inserted_func;
	knh_Func_t *rows_about_to_be_moved_func;
	knh_Func_t *rows_about_to_be_removed_func;
	knh_Func_t *rows_inserted_func;
	knh_Func_t *rows_moved_func;
	knh_Func_t *rows_removed_func;
	DummyQAbstractItemModel();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool columnsAboutToBeInsertedSlot(const QModelIndex parent, int start, int end);
	bool columnsAboutToBeMovedSlot(const QModelIndex sourceParent, int sourceStart, int sourceEnd, const QModelIndex destinationParent, int destinationColumn);
	bool columnsAboutToBeRemovedSlot(const QModelIndex parent, int start, int end);
	bool columnsInsertedSlot(const QModelIndex parent, int start, int end);
	bool columnsMovedSlot(const QModelIndex sourceParent, int sourceStart, int sourceEnd, const QModelIndex destinationParent, int destinationColumn);
	bool columnsRemovedSlot(const QModelIndex parent, int start, int end);
	bool dataChangedSlot(const QModelIndex topLeft, const QModelIndex bottomRight);
	bool headerDataChangedSlot(Qt::Orientation orientation, int first, int last);
	bool layoutAboutToBeChangedSlot();
	bool layoutChangedSlot();
	bool modelAboutToBeResetSlot();
	bool modelResetSlot();
	bool rowsAboutToBeInsertedSlot(const QModelIndex parent, int start, int end);
	bool rowsAboutToBeMovedSlot(const QModelIndex sourceParent, int sourceStart, int sourceEnd, const QModelIndex destinationParent, int destinationRow);
	bool rowsAboutToBeRemovedSlot(const QModelIndex parent, int start, int end);
	bool rowsInsertedSlot(const QModelIndex parent, int start, int end);
	bool rowsMovedSlot(const QModelIndex sourceParent, int sourceStart, int sourceEnd, const QModelIndex destinationParent, int destinationRow);
	bool rowsRemovedSlot(const QModelIndex parent, int start, int end);
};

class KQAbstractItemModel : public QAbstractItemModel {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQAbstractItemModel *dummy;
	KQAbstractItemModel(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QABSTRACTITEMMODEL


