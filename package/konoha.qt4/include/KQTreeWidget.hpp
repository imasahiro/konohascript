#ifndef QTREEWIDGET
#define QTREEWIDGET
class DummyQTreeWidget : public DummyQTreeView {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *current_item_changed_func;
	knh_Func_t *item_activated_func;
	knh_Func_t *item_changed_func;
	knh_Func_t *item_clicked_func;
	knh_Func_t *item_collapsed_func;
	knh_Func_t *item_double_clicked_func;
	knh_Func_t *item_entered_func;
	knh_Func_t *item_expanded_func;
	knh_Func_t *item_pressed_func;
	knh_Func_t *item_selection_changed_func;
	DummyQTreeWidget();
	virtual ~DummyQTreeWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool currentItemChangedSlot(QTreeWidgetItem* current, QTreeWidgetItem* previous);
	bool itemActivatedSlot(QTreeWidgetItem* item, int column);
	bool itemChangedSlot(QTreeWidgetItem* item, int column);
	bool itemClickedSlot(QTreeWidgetItem* item, int column);
	bool itemCollapsedSlot(QTreeWidgetItem* item);
	bool itemDoubleClickedSlot(QTreeWidgetItem* item, int column);
	bool itemEnteredSlot(QTreeWidgetItem* item, int column);
	bool itemExpandedSlot(QTreeWidgetItem* item);
	bool itemPressedSlot(QTreeWidgetItem* item, int column);
	bool itemSelectionChangedSlot();
};

class KQTreeWidget : public QTreeWidget {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQTreeWidget *dummy;
	KQTreeWidget(QWidget* parent);
	~KQTreeWidget();
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QTREEWIDGET


