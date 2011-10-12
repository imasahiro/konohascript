//@Virtual @Override void QTreeWidget.setSelectionModel(QItemSelectionModel selectionModel);
KMETHOD QTreeWidget_setSelectionModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		QItemSelectionModel*  selectionModel = RawPtr_to(QItemSelectionModel*, sfp[1]);
		qp->setSelectionModel(selectionModel);
	}
	RETURNvoid_();
}

//QTreeWidget QTreeWidget.new(QWidget parent);
KMETHOD QTreeWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQTreeWidget *ret_v = new KQTreeWidget(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QTreeWidget.addtopLevelItem(QTreeWidgetItem item);
KMETHOD QTreeWidget_addTopLevelItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		QTreeWidgetItem*  item = RawPtr_to(QTreeWidgetItem*, sfp[1]);
		qp->addTopLevelItem(item);
	}
	RETURNvoid_();
}

//void QTreeWidget.addtopLevelItems(Array<QTreeWidgetItem> items);
KMETHOD QTreeWidget_addTopLevelItems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QTreeWidgetItem*> items;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			items.append((QTreeWidgetItem*)p->rawptr);
		}
		qp->addTopLevelItems(items);
	}
	RETURNvoid_();
}

//void QTreeWidget.closePersistentEditorOL(QTreeWidgetItem item, int column);
KMETHOD QTreeWidget_closePersistentEditorOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		QTreeWidgetItem*  item = RawPtr_to(QTreeWidgetItem*, sfp[1]);
		int column = Int_to(int, sfp[2]);
		qp->closePersistentEditor(item, column);
	}
	RETURNvoid_();
}

//int QTreeWidget.getColumnCount();
KMETHOD QTreeWidget_getColumnCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->columnCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTreeWidget.currentColumn();
KMETHOD QTreeWidget_currentColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->currentColumn();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTreeWidgetItem QTreeWidget.getCurrentItem();
KMETHOD QTreeWidget_getCurrentItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		QTreeWidgetItem* ret_v = qp->currentItem();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTreeWidgetItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTreeWidget.editItem(QTreeWidgetItem item, int column);
KMETHOD QTreeWidget_editItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		QTreeWidgetItem*  item = RawPtr_to(QTreeWidgetItem*, sfp[1]);
		int column = Int_to(int, sfp[2]);
		qp->editItem(item, column);
	}
	RETURNvoid_();
}

//Array<QTreeWidgetItem> QTreeWidget.findItems(String text, int flags, int column);
KMETHOD QTreeWidget_findItems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		const QString text = String_to(const QString, sfp[1]);
		Qt::MatchFlags flags = Int_to(Qt::MatchFlags, sfp[2]);
		int column = Int_to(int, sfp[3]);
		QList<QTreeWidgetItem*>ret_v = qp->findItems(text, flags, column);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QTreeWidgetItem"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QTreeWidgetItem QTreeWidget.getHeaderItem();
KMETHOD QTreeWidget_getHeaderItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		QTreeWidgetItem* ret_v = qp->headerItem();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTreeWidgetItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTreeWidget.indexOftopLevelItem(QTreeWidgetItem item);
KMETHOD QTreeWidget_indexOfTopLevelItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		QTreeWidgetItem*  item = RawPtr_to(QTreeWidgetItem*, sfp[1]);
		int ret_v = qp->indexOfTopLevelItem(item);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTreeWidget.inserttopLevelItem(int index, QTreeWidgetItem item);
KMETHOD QTreeWidget_insertTopLevelItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QTreeWidgetItem*  item = RawPtr_to(QTreeWidgetItem*, sfp[2]);
		qp->insertTopLevelItem(index, item);
	}
	RETURNvoid_();
}

//void QTreeWidget.inserttopLevelItems(int index, Array<QTreeWidgetItem> items);
KMETHOD QTreeWidget_insertTopLevelItems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		knh_Array_t *a = sfp[2].a;
		int asize = knh_Array_size(a);
		QList<QTreeWidgetItem*> items;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			items.append((QTreeWidgetItem*)p->rawptr);
		}
		qp->insertTopLevelItems(index, items);
	}
	RETURNvoid_();
}

//QTreeWidgetItem QTreeWidget.invisibleRootItem();
KMETHOD QTreeWidget_invisibleRootItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		QTreeWidgetItem* ret_v = qp->invisibleRootItem();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTreeWidgetItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QTreeWidget.isFirstItemColumnSpanned(QTreeWidgetItem item);
KMETHOD QTreeWidget_isFirstItemColumnSpanned(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		const QTreeWidgetItem*  item = RawPtr_to(const QTreeWidgetItem*, sfp[1]);
		bool ret_v = qp->isFirstItemColumnSpanned(item);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QTreeWidgetItem QTreeWidget.itemAbove(QTreeWidgetItem item);
KMETHOD QTreeWidget_itemAbove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		const QTreeWidgetItem*  item = RawPtr_to(const QTreeWidgetItem*, sfp[1]);
		QTreeWidgetItem* ret_v = qp->itemAbove(item);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTreeWidgetItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTreeWidgetItem QTreeWidget.itemAt(QPoint p);
KMETHOD QTreeWidget_itemAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		const QPoint  p = *RawPtr_to(const QPoint *, sfp[1]);
		QTreeWidgetItem* ret_v = qp->itemAt(p);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTreeWidgetItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QTreeWidgetItem QTreeWidget.itemAt(int x, int y);
KMETHOD QTreeWidget_itemAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		QTreeWidgetItem* ret_v = qp->itemAt(x, y);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTreeWidgetItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QTreeWidgetItem QTreeWidget.itemBelow(QTreeWidgetItem item);
KMETHOD QTreeWidget_itemBelow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		const QTreeWidgetItem*  item = RawPtr_to(const QTreeWidgetItem*, sfp[1]);
		QTreeWidgetItem* ret_v = qp->itemBelow(item);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTreeWidgetItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QTreeWidget.getItemWidget(QTreeWidgetItem item, int column);
KMETHOD QTreeWidget_getItemWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		QTreeWidgetItem*  item = RawPtr_to(QTreeWidgetItem*, sfp[1]);
		int column = Int_to(int, sfp[2]);
		QWidget* ret_v = qp->itemWidget(item, column);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTreeWidget.openPersistentEditorOL(QTreeWidgetItem item, int column);
KMETHOD QTreeWidget_openPersistentEditorOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		QTreeWidgetItem*  item = RawPtr_to(QTreeWidgetItem*, sfp[1]);
		int column = Int_to(int, sfp[2]);
		qp->openPersistentEditor(item, column);
	}
	RETURNvoid_();
}

//void QTreeWidget.removeItemWidget(QTreeWidgetItem item, int column);
KMETHOD QTreeWidget_removeItemWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		QTreeWidgetItem*  item = RawPtr_to(QTreeWidgetItem*, sfp[1]);
		int column = Int_to(int, sfp[2]);
		qp->removeItemWidget(item, column);
	}
	RETURNvoid_();
}

//Array<QTreeWidgetItem> QTreeWidget.selectedItems();
KMETHOD QTreeWidget_selectedItems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		QList<QTreeWidgetItem*>ret_v = qp->selectedItems();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QTreeWidgetItem"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//void QTreeWidget.setColumnCount(int columns);
KMETHOD QTreeWidget_setColumnCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		int columns = Int_to(int, sfp[1]);
		qp->setColumnCount(columns);
	}
	RETURNvoid_();
}

//void QTreeWidget.setCurrentItem(QTreeWidgetItem item);
KMETHOD QTreeWidget_setCurrentItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		QTreeWidgetItem*  item = RawPtr_to(QTreeWidgetItem*, sfp[1]);
		qp->setCurrentItem(item);
	}
	RETURNvoid_();
}

/*
//void QTreeWidget.setCurrentItem(QTreeWidgetItem item, int column);
KMETHOD QTreeWidget_setCurrentItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		QTreeWidgetItem*  item = RawPtr_to(QTreeWidgetItem*, sfp[1]);
		int column = Int_to(int, sfp[2]);
		qp->setCurrentItem(item, column);
	}
	RETURNvoid_();
}
*/
/*
//void QTreeWidget.setCurrentItem(QTreeWidgetItem item, int column, int command);
KMETHOD QTreeWidget_setCurrentItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		QTreeWidgetItem*  item = RawPtr_to(QTreeWidgetItem*, sfp[1]);
		int column = Int_to(int, sfp[2]);
		QItemSelectionModel::SelectionFlags command = Int_to(QItemSelectionModel::SelectionFlags, sfp[3]);
		qp->setCurrentItem(item, column, command);
	}
	RETURNvoid_();
}
*/
//void QTreeWidget.setFirstItemColumnSpanned(QTreeWidgetItem item, boolean span);
KMETHOD QTreeWidget_setFirstItemColumnSpanned(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		const QTreeWidgetItem*  item = RawPtr_to(const QTreeWidgetItem*, sfp[1]);
		bool span = Boolean_to(bool, sfp[2]);
		qp->setFirstItemColumnSpanned(item, span);
	}
	RETURNvoid_();
}

//void QTreeWidget.setHeaderItem(QTreeWidgetItem item);
KMETHOD QTreeWidget_setHeaderItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		QTreeWidgetItem*  item = RawPtr_to(QTreeWidgetItem*, sfp[1]);
		qp->setHeaderItem(item);
	}
	RETURNvoid_();
}

//void QTreeWidget.setHeaderLabel(String label);
KMETHOD QTreeWidget_setHeaderLabel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		const QString label = String_to(const QString, sfp[1]);
		qp->setHeaderLabel(label);
	}
	RETURNvoid_();
}

//void QTreeWidget.setItemWidget(QTreeWidgetItem item, int column, QWidget widget);
KMETHOD QTreeWidget_setItemWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		QTreeWidgetItem*  item = RawPtr_to(QTreeWidgetItem*, sfp[1]);
		int column = Int_to(int, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->setItemWidget(item, column, widget);
	}
	RETURNvoid_();
}

//int QTreeWidget.sortColumn();
KMETHOD QTreeWidget_sortColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->sortColumn();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTreeWidget.sortItems(int column, int order);
KMETHOD QTreeWidget_sortItems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		int column = Int_to(int, sfp[1]);
		Qt::SortOrder order = Int_to(Qt::SortOrder, sfp[2]);
		qp->sortItems(column, order);
	}
	RETURNvoid_();
}

//QTreeWidgetItem QTreeWidget.taketopLevelItem(int index);
KMETHOD QTreeWidget_takeTopLevelItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QTreeWidgetItem* ret_v = qp->takeTopLevelItem(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTreeWidgetItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTreeWidgetItem QTreeWidget.topLevelItem(int index);
KMETHOD QTreeWidget_topLevelItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QTreeWidgetItem* ret_v = qp->topLevelItem(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTreeWidgetItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTreeWidget.topLevelItemCount();
KMETHOD QTreeWidget_topLevelItemCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->topLevelItemCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QRect QTreeWidget.visualItemRect(QTreeWidgetItem item);
KMETHOD QTreeWidget_visualItemRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		const QTreeWidgetItem*  item = RawPtr_to(const QTreeWidgetItem*, sfp[1]);
		QRect ret_v = qp->visualItemRect(item);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTreeWidget.clear();
KMETHOD QTreeWidget_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		qp->clear();
	}
	RETURNvoid_();
}

//void QTreeWidget.collapseItem(QTreeWidgetItem item);
KMETHOD QTreeWidget_collapseItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		const QTreeWidgetItem*  item = RawPtr_to(const QTreeWidgetItem*, sfp[1]);
		qp->collapseItem(item);
	}
	RETURNvoid_();
}

//void QTreeWidget.expandItem(QTreeWidgetItem item);
KMETHOD QTreeWidget_expandItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		const QTreeWidgetItem*  item = RawPtr_to(const QTreeWidgetItem*, sfp[1]);
		qp->expandItem(item);
	}
	RETURNvoid_();
}

//void QTreeWidget.scrollToItem(QTreeWidgetItem item, int hint);
KMETHOD QTreeWidget_scrollToItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeWidget *  qp = RawPtr_to(QTreeWidget *, sfp[0]);
	if (qp != NULL) {
		const QTreeWidgetItem*  item = RawPtr_to(const QTreeWidgetItem*, sfp[1]);
		QAbstractItemView::ScrollHint hint = Int_to(QAbstractItemView::ScrollHint, sfp[2]);
		qp->scrollToItem(item, hint);
	}
	RETURNvoid_();
}


DummyQTreeWidget::DummyQTreeWidget()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTreeWidget::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTreeWidget::self = ptr;
	DummyQTreeView::setSelf(ptr);
}

bool DummyQTreeWidget::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQTreeView::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTreeWidget::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTreeWidget::event_map->bigin();
	if ((itr = DummyQTreeWidget::event_map->find(str)) == DummyQTreeWidget::event_map->end()) {
		bool ret;
		ret = DummyQTreeView::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTreeWidget::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTreeWidget::slot_map->bigin();
	if ((itr = DummyQTreeWidget::event_map->find(str)) == DummyQTreeWidget::slot_map->end()) {
		bool ret;
		ret = DummyQTreeView::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTreeWidget::KQTreeWidget(QWidget* parent) : QTreeWidget(parent)
{
	self = NULL;
}

KMETHOD QTreeWidget_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTreeWidget *qp = RawPtr_to(KQTreeWidget *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTreeWidget]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQTreeWidget::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTreeWidget]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QTreeWidget_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTreeWidget *qp = RawPtr_to(KQTreeWidget *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTreeWidget]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQTreeWidget::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTreeWidget]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTreeWidget_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTreeWidget *qp = (KQTreeWidget *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTreeWidget_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTreeWidget *qp = (KQTreeWidget *)p->rawptr;
		(void)qp;
	}
}

static int QTreeWidget_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQTreeWidget::event(QEvent *event)
{
	if (!DummyQTreeWidget::eventDispatcher(event)) {
		QTreeWidget::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQTreeWidget(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTreeWidget";
	cdef->free = QTreeWidget_free;
	cdef->reftrace = QTreeWidget_reftrace;
	cdef->compareTo = QTreeWidget_compareTo;
}


