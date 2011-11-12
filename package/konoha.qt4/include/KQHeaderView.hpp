#ifndef QHEADERVIEW
#define QHEADERVIEW
class DummyQHeaderView : public DummyQAbstractItemView {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *geometries_changed_func;
	knh_Func_t *section_auto_resize_func;
	knh_Func_t *section_clicked_func;
	knh_Func_t *section_count_changed_func;
	knh_Func_t *section_double_clicked_func;
	knh_Func_t *section_entered_func;
	knh_Func_t *section_handle_double_clicked_func;
	knh_Func_t *section_moved_func;
	knh_Func_t *section_pressed_func;
	knh_Func_t *section_resized_func;
	knh_Func_t *sort_indicator_changed_func;
	DummyQHeaderView();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool geometriesChangedSlot();
	bool sectionAutoResizeSlot(int logicalIndex, QHeaderView::ResizeMode mode);
	bool sectionClickedSlot(int logicalIndex);
	bool sectionCountChangedSlot(int oldCount, int new_Count);
	bool sectionDoubleClickedSlot(int logicalIndex);
	bool sectionEnteredSlot(int logicalIndex);
	bool sectionHandleDoubleClickedSlot(int logicalIndex);
	bool sectionMovedSlot(int logicalIndex, int oldVisualIndex, int new_VisualIndex);
	bool sectionPressedSlot(int logicalIndex);
	bool sectionResizedSlot(int logicalIndex, int oldSize, int new_Size);
	bool sortIndicatorChangedSlot(int logicalIndex, Qt::SortOrder order);
};

class KQHeaderView : public QHeaderView {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQHeaderView *dummy;
	KQHeaderView(Qt::Orientation orientation, QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QHEADERVIEW


