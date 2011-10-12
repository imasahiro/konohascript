//@Virtual @Override QVariant QAbstractItemView.inputMethodQuery(int query);
KMETHOD QAbstractItemView_inputMethodQuery(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		Qt::InputMethodQuery query = Int_to(Qt::InputMethodQuery, sfp[1]);
		QVariant ret_v = qp->inputMethodQuery(query);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//
//boolean QAbstractItemView.getAlternatingRowColors();
KMETHOD QAbstractItemView_getAlternatingRowColors(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->alternatingRowColors();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QAbstractItemView.getAutoScrollMargin();
KMETHOD QAbstractItemView_getAutoScrollMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->autoScrollMargin();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QAbstractItemView.closePersistentEditor(QModelIndex index);
KMETHOD QAbstractItemView_closePersistentEditor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->closePersistentEditor(index);
	}
	RETURNvoid_();
}

//QModelIndex QAbstractItemView.getCurrentIndex();
KMETHOD QAbstractItemView_getCurrentIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QModelIndex ret_v = qp->currentIndex();
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QAbstractItemView.getDefaultDropAction();
KMETHOD QAbstractItemView_getDefaultDropAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		Qt::DropAction ret_v = qp->defaultDropAction();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAbstractItemView.getDragDropMode();
KMETHOD QAbstractItemView_getDragDropMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemView::DragDropMode ret_v = qp->dragDropMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QAbstractItemView.getDragDropOverwriteMode();
KMETHOD QAbstractItemView_getDragDropOverwriteMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->dragDropOverwriteMode();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAbstractItemView.getDragEnabled();
KMETHOD QAbstractItemView_getDragEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->dragEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QAbstractItemView.getEditTriggers();
KMETHOD QAbstractItemView_getEditTriggers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemView::EditTriggers ret_v = qp->editTriggers();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QAbstractItemView.hasAutoScroll();
KMETHOD QAbstractItemView_hasAutoScroll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->hasAutoScroll();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QAbstractItemView.getHorizontalScrollMode();
KMETHOD QAbstractItemView_getHorizontalScrollMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemView::ScrollMode ret_v = qp->horizontalScrollMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QSize QAbstractItemView.getIconSize();
KMETHOD QAbstractItemView_getIconSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->iconSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QModelIndex QAbstractItemView.indexAt(QPoint point);
KMETHOD QAbstractItemView_indexAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		QModelIndex ret_v = qp->indexAt(point);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QAbstractItemView.getIndexWidget(QModelIndex index);
KMETHOD QAbstractItemView_getIndexWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QWidget* ret_v = qp->indexWidget(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAbstractItemDelegate QAbstractItemView.getItemDelegate();
KMETHOD QAbstractItemView_getItemDelegate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemDelegate* ret_v = qp->itemDelegate();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractItemDelegate*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QAbstractItemDelegate QAbstractItemView.getItemDelegate(QModelIndex index);
KMETHOD QAbstractItemView_getItemDelegate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QAbstractItemDelegate* ret_v = qp->itemDelegate(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractItemDelegate*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QAbstractItemDelegate QAbstractItemView.getItemDelegateForColumn(int column);
KMETHOD QAbstractItemView_getItemDelegateForColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		int column = Int_to(int, sfp[1]);
		QAbstractItemDelegate* ret_v = qp->itemDelegateForColumn(column);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractItemDelegate*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAbstractItemDelegate QAbstractItemView.getItemDelegateForRow(int row);
KMETHOD QAbstractItemView_getItemDelegateForRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		int row = Int_to(int, sfp[1]);
		QAbstractItemDelegate* ret_v = qp->itemDelegateForRow(row);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractItemDelegate*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QAbstractItemView.keyboardSearch(String search);
KMETHOD QAbstractItemView_keyboardSearch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		const QString search = String_to(const QString, sfp[1]);
		qp->keyboardSearch(search);
	}
	RETURNvoid_();
}

//QAbstractItemModel QAbstractItemView.getModel();
KMETHOD QAbstractItemView_getModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemModel* ret_v = qp->model();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractItemModel*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QAbstractItemView.openPersistentEditor(QModelIndex index);
KMETHOD QAbstractItemView_openPersistentEditor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->openPersistentEditor(index);
	}
	RETURNvoid_();
}

//QModelIndex QAbstractItemView.getRootIndex();
KMETHOD QAbstractItemView_getRootIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QModelIndex ret_v = qp->rootIndex();
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QAbstractItemView.scrollTo(QModelIndex index, int hint);
KMETHOD QAbstractItemView_scrollTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QAbstractItemView::ScrollHint hint = Int_to(QAbstractItemView::ScrollHint, sfp[2]);
		qp->scrollTo(index, hint);
	}
	RETURNvoid_();
}

//int QAbstractItemView.getSelectionBehavior();
KMETHOD QAbstractItemView_getSelectionBehavior(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemView::SelectionBehavior ret_v = qp->selectionBehavior();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAbstractItemView.getSelectionMode();
KMETHOD QAbstractItemView_getSelectionMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemView::SelectionMode ret_v = qp->selectionMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QItemSelectionModel QAbstractItemView.getSelectionModel();
KMETHOD QAbstractItemView_getSelectionModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QItemSelectionModel* ret_v = qp->selectionModel();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QItemSelectionModel*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QAbstractItemView.setAlternatingRowColors(boolean enable);
KMETHOD QAbstractItemView_setAlternatingRowColors(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setAlternatingRowColors(enable);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setAutoScroll(boolean enable);
KMETHOD QAbstractItemView_setAutoScroll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setAutoScroll(enable);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setAutoScrollMargin(int margin);
KMETHOD QAbstractItemView_setAutoScrollMargin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		int margin = Int_to(int, sfp[1]);
		qp->setAutoScrollMargin(margin);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setDefaultDropAction(int dropAction);
KMETHOD QAbstractItemView_setDefaultDropAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		Qt::DropAction dropAction = Int_to(Qt::DropAction, sfp[1]);
		qp->setDefaultDropAction(dropAction);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setDragDropMode(int behavior);
KMETHOD QAbstractItemView_setDragDropMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemView::DragDropMode behavior = Int_to(QAbstractItemView::DragDropMode, sfp[1]);
		qp->setDragDropMode(behavior);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setDragDropOverwriteMode(boolean overwrite);
KMETHOD QAbstractItemView_setDragDropOverwriteMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		bool overwrite = Boolean_to(bool, sfp[1]);
		qp->setDragDropOverwriteMode(overwrite);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setDragEnabled(boolean enable);
KMETHOD QAbstractItemView_setDragEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setDragEnabled(enable);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setDropIndicatorShown(boolean enable);
KMETHOD QAbstractItemView_setDropIndicatorShown(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setDropIndicatorShown(enable);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setEditTriggers(int triggers);
KMETHOD QAbstractItemView_setEditTriggers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemView::EditTriggers triggers = Int_to(QAbstractItemView::EditTriggers, sfp[1]);
		qp->setEditTriggers(triggers);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setHorizontalScrollMode(int mode);
KMETHOD QAbstractItemView_setHorizontalScrollMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemView::ScrollMode mode = Int_to(QAbstractItemView::ScrollMode, sfp[1]);
		qp->setHorizontalScrollMode(mode);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setIconSize(QSize size);
KMETHOD QAbstractItemView_setIconSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		qp->setIconSize(size);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setIndexWidget(QModelIndex index, QWidget widget);
KMETHOD QAbstractItemView_setIndexWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[2]);
		qp->setIndexWidget(index, widget);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setItemDelegate(QAbstractItemDelegate delegate);
KMETHOD QAbstractItemView_setItemDelegate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemDelegate*  delegate = RawPtr_to(QAbstractItemDelegate*, sfp[1]);
		qp->setItemDelegate(delegate);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setItemDelegateForColumn(int column, QAbstractItemDelegate delegate);
KMETHOD QAbstractItemView_setItemDelegateForColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		int column = Int_to(int, sfp[1]);
		QAbstractItemDelegate*  delegate = RawPtr_to(QAbstractItemDelegate*, sfp[2]);
		qp->setItemDelegateForColumn(column, delegate);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setItemDelegateForRow(int row, QAbstractItemDelegate delegate);
KMETHOD QAbstractItemView_setItemDelegateForRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		int row = Int_to(int, sfp[1]);
		QAbstractItemDelegate*  delegate = RawPtr_to(QAbstractItemDelegate*, sfp[2]);
		qp->setItemDelegateForRow(row, delegate);
	}
	RETURNvoid_();
}

//@Virtual void QAbstractItemView.setModel(QAbstractItemModel model);
KMETHOD QAbstractItemView_setModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemModel*  model = RawPtr_to(QAbstractItemModel*, sfp[1]);
		qp->setModel(model);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setSelectionBehavior(int behavior);
KMETHOD QAbstractItemView_setSelectionBehavior(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemView::SelectionBehavior behavior = Int_to(QAbstractItemView::SelectionBehavior, sfp[1]);
		qp->setSelectionBehavior(behavior);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setSelectionMode(int mode);
KMETHOD QAbstractItemView_setSelectionMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemView::SelectionMode mode = Int_to(QAbstractItemView::SelectionMode, sfp[1]);
		qp->setSelectionMode(mode);
	}
	RETURNvoid_();
}

//@Virtual void QAbstractItemView.setSelectionModel(QItemSelectionModel selectionModel);
KMETHOD QAbstractItemView_setSelectionModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QItemSelectionModel*  selectionModel = RawPtr_to(QItemSelectionModel*, sfp[1]);
		qp->setSelectionModel(selectionModel);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setTabKeyNavigation(boolean enable);
KMETHOD QAbstractItemView_setTabKeyNavigation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setTabKeyNavigation(enable);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setTextElideMode(int mode);
KMETHOD QAbstractItemView_setTextElideMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		Qt::TextElideMode mode = Int_to(Qt::TextElideMode, sfp[1]);
		qp->setTextElideMode(mode);
	}
	RETURNvoid_();
}

//void QAbstractItemView.setVerticalScrollMode(int mode);
KMETHOD QAbstractItemView_setVerticalScrollMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemView::ScrollMode mode = Int_to(QAbstractItemView::ScrollMode, sfp[1]);
		qp->setVerticalScrollMode(mode);
	}
	RETURNvoid_();
}

//boolean QAbstractItemView.showDropIndicator();
KMETHOD QAbstractItemView_showDropIndicator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->showDropIndicator();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual int QAbstractItemView.sizeHintForColumn(int column);
KMETHOD QAbstractItemView_sizeHintForColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		int column = Int_to(int, sfp[1]);
		int ret_v = qp->sizeHintForColumn(column);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QSize QAbstractItemView.sizeHintForIndex(QModelIndex index);
KMETHOD QAbstractItemView_sizeHintForIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QSize ret_v = qp->sizeHintForIndex(index);
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual int QAbstractItemView.sizeHintForRow(int row);
KMETHOD QAbstractItemView_sizeHintForRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		int row = Int_to(int, sfp[1]);
		int ret_v = qp->sizeHintForRow(row);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QAbstractItemView.getTabKeyNavigation();
KMETHOD QAbstractItemView_getTabKeyNavigation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->tabKeyNavigation();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QAbstractItemView.getTextElideMode();
KMETHOD QAbstractItemView_getTextElideMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		Qt::TextElideMode ret_v = qp->textElideMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAbstractItemView.getVerticalScrollMode();
KMETHOD QAbstractItemView_getVerticalScrollMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemView::ScrollMode ret_v = qp->verticalScrollMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QRect QAbstractItemView.visualRect(QModelIndex index);
KMETHOD QAbstractItemView_visualRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QRect ret_v = qp->visualRect(index);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QAbstractItemView.clearSelection();
KMETHOD QAbstractItemView_clearSelection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		qp->clearSelection();
	}
	RETURNvoid_();
}

//void QAbstractItemView.edit(QModelIndex index);
KMETHOD QAbstractItemView_edit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->edit(index);
	}
	RETURNvoid_();
}

//@Virtual void QAbstractItemView.reset();
KMETHOD QAbstractItemView_reset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		qp->reset();
	}
	RETURNvoid_();
}

//void QAbstractItemView.scrollToBottom();
KMETHOD QAbstractItemView_scrollToBottom(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		qp->scrollToBottom();
	}
	RETURNvoid_();
}

//void QAbstractItemView.scrollTotop();
KMETHOD QAbstractItemView_scrollToTop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		qp->scrollToTop();
	}
	RETURNvoid_();
}

//@Virtual void QAbstractItemView.selectAll();
KMETHOD QAbstractItemView_selectAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		qp->selectAll();
	}
	RETURNvoid_();
}

//void QAbstractItemView.setCurrentIndex(QModelIndex index);
KMETHOD QAbstractItemView_setCurrentIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->setCurrentIndex(index);
	}
	RETURNvoid_();
}

//@Virtual void QAbstractItemView.setRootIndex(QModelIndex index);
KMETHOD QAbstractItemView_setRootIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->setRootIndex(index);
	}
	RETURNvoid_();
}

//void QAbstractItemView.update(QModelIndex index);
KMETHOD QAbstractItemView_update(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemView *  qp = RawPtr_to(QAbstractItemView *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->update(index);
	}
	RETURNvoid_();
}


DummyQAbstractItemView::DummyQAbstractItemView()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQAbstractItemView::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractItemView::self = ptr;
	DummyQAbstractScrollArea::setSelf(ptr);
}

bool DummyQAbstractItemView::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractScrollArea::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractItemView::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractItemView::event_map->bigin();
	if ((itr = DummyQAbstractItemView::event_map->find(str)) == DummyQAbstractItemView::event_map->end()) {
		bool ret;
		ret = DummyQAbstractScrollArea::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractItemView::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractItemView::slot_map->bigin();
	if ((itr = DummyQAbstractItemView::event_map->find(str)) == DummyQAbstractItemView::slot_map->end()) {
		bool ret;
		ret = DummyQAbstractScrollArea::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQAbstractItemView::KQAbstractItemView(QWidget* parent) : QAbstractItemView(parent)
{
	self = NULL;
}

KMETHOD QAbstractItemView_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractItemView *qp = RawPtr_to(KQAbstractItemView *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractItemView]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQAbstractItemView::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractItemView]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QAbstractItemView_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractItemView *qp = RawPtr_to(KQAbstractItemView *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractItemView]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQAbstractItemView::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractItemView]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractItemView_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAbstractItemView *qp = (KQAbstractItemView *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAbstractItemView_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQAbstractItemView *qp = (KQAbstractItemView *)p->rawptr;
		(void)qp;
	}
}

static int QAbstractItemView_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQAbstractItemView::event(QEvent *event)
{
	if (!DummyQAbstractItemView::eventDispatcher(event)) {
		QAbstractItemView::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQAbstractItemView(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractItemView";
	cdef->free = QAbstractItemView_free;
	cdef->reftrace = QAbstractItemView_reftrace;
	cdef->compareTo = QAbstractItemView_compareTo;
}

static knh_IntData_t QAbstractItemViewConstInt[] = {
	{"NoDragDrop", QAbstractItemView::NoDragDrop},
	{"DragOnly", QAbstractItemView::DragOnly},
	{"DropOnly", QAbstractItemView::DropOnly},
	{"DragDrop", QAbstractItemView::DragDrop},
	{"InternalMove", QAbstractItemView::InternalMove},
	{"NoEditTriggers", QAbstractItemView::NoEditTriggers},
	{"CurrentChanged", QAbstractItemView::CurrentChanged},
	{"DoubleClicked", QAbstractItemView::DoubleClicked},
	{"SelectedClicked", QAbstractItemView::SelectedClicked},
	{"EditKeyPressed", QAbstractItemView::EditKeyPressed},
	{"AnyKeyPressed", QAbstractItemView::AnyKeyPressed},
	{"AllEditTriggers", QAbstractItemView::AllEditTriggers},
	{"EnsureVisible", QAbstractItemView::EnsureVisible},
	{"PositionAtTop", QAbstractItemView::PositionAtTop},
	{"PositionAtBottom", QAbstractItemView::PositionAtBottom},
	{"PositionAtCenter", QAbstractItemView::PositionAtCenter},
	{"ScrollPerItem", QAbstractItemView::ScrollPerItem},
	{"ScrollPerPixel", QAbstractItemView::ScrollPerPixel},
	{"SelectItems", QAbstractItemView::SelectItems},
	{"SelectRows", QAbstractItemView::SelectRows},
	{"SelectColumns", QAbstractItemView::SelectColumns},
	{"SingleSelection", QAbstractItemView::SingleSelection},
	{"ContiguousSelection", QAbstractItemView::ContiguousSelection},
	{"ExtendedSelection", QAbstractItemView::ExtendedSelection},
	{"MultiSelection", QAbstractItemView::MultiSelection},
	{"NoSelection", QAbstractItemView::NoSelection},
	{NULL, 0}
};

DEFAPI(void) constQAbstractItemView(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QAbstractItemViewConstInt);
}

