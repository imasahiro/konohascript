//@Virtual @Override void QTreeView.dataChanged(QModelIndex topLeft, QModelIndex bottomRight);
KMETHOD QTreeView_dataChanged(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		const QModelIndex  topLeft = *RawPtr_to(const QModelIndex *, sfp[1]);
		const QModelIndex  bottomRight = *RawPtr_to(const QModelIndex *, sfp[2]);
		qp->dataChanged(topLeft, bottomRight);
	}
	RETURNvoid_();
}

//@Virtual @Override QModelIndex QTreeView.indexAt(QPoint point);
KMETHOD QTreeView_indexAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		QModelIndex ret_v = qp->indexAt(point);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QTreeView.keyboardSearch(String search);
KMETHOD QTreeView_keyboardSearch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		const QString search = String_to(const QString, sfp[1]);
		qp->keyboardSearch(search);
	}
	RETURNvoid_();
}

//@Virtual @Override void QTreeView.reset();
KMETHOD QTreeView_reset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		qp->reset();
	}
	RETURNvoid_();
}

//@Virtual @Override void QTreeView.scrollTo(QModelIndex index, int hint);
KMETHOD QTreeView_scrollTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QTreeView::ScrollHint hint = Int_to(QTreeView::ScrollHint, sfp[2]);
		qp->scrollTo(index, hint);
	}
	RETURNvoid_();
}

//@Virtual @Override void QTreeView.selectAll();
KMETHOD QTreeView_selectAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		qp->selectAll();
	}
	RETURNvoid_();
}

//@Virtual @Override void QTreeView.setModel(QAbstractItemModel model);
KMETHOD QTreeView_setModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		QAbstractItemModel*  model = RawPtr_to(QAbstractItemModel*, sfp[1]);
		qp->setModel(model);
	}
	RETURNvoid_();
}

//@Virtual @Override void QTreeView.setRootIndex(QModelIndex index);
KMETHOD QTreeView_setRootIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->setRootIndex(index);
	}
	RETURNvoid_();
}

//@Virtual @Override void QTreeView.setSelectionModel(QItemSelectionModel selectionModel);
KMETHOD QTreeView_setSelectionModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		QItemSelectionModel*  selectionModel = RawPtr_to(QItemSelectionModel*, sfp[1]);
		qp->setSelectionModel(selectionModel);
	}
	RETURNvoid_();
}

//@Virtual @Override QRect QTreeView.visualRect(QModelIndex index);
KMETHOD QTreeView_visualRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QRect ret_v = qp->visualRect(index);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTreeView QTreeView.new(QWidget parent);
KMETHOD QTreeView_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQTreeView *ret_v = new KQTreeView(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QTreeView.getAllColumnsShowFocus();
KMETHOD QTreeView_getAllColumnsShowFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->allColumnsShowFocus();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTreeView.getAutoExpandDelay();
KMETHOD QTreeView_getAutoExpandDelay(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int ret_v = qp->autoExpandDelay();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTreeView.columnAt(int x);
KMETHOD QTreeView_columnAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		int ret_v = qp->columnAt(x);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTreeView.columnViewportPosition(int column);
KMETHOD QTreeView_columnViewportPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int ret_v = qp->columnViewportPosition(column);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTreeView.getColumnWidth(int column);
KMETHOD QTreeView_getColumnWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int ret_v = qp->columnWidth(column);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QTreeView.getExpandsOnDoubleClick();
KMETHOD QTreeView_getExpandsOnDoubleClick(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->expandsOnDoubleClick();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QHeaderView QTreeView.getHeader();
KMETHOD QTreeView_getHeader(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		QHeaderView* ret_v = qp->header();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QHeaderView*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTreeView.getIndentation();
KMETHOD QTreeView_getIndentation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int ret_v = qp->indentation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QModelIndex QTreeView.indexAbove(QModelIndex index);
KMETHOD QTreeView_indexAbove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QModelIndex ret_v = qp->indexAbove(index);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QModelIndex QTreeView.indexBelow(QModelIndex index);
KMETHOD QTreeView_indexBelow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QModelIndex ret_v = qp->indexBelow(index);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QTreeView.isAnimated();
KMETHOD QTreeView_isAnimated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isAnimated();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTreeView.isColumnHidden(int column);
KMETHOD QTreeView_isColumnHidden(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		bool ret_v = qp->isColumnHidden(column);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTreeView.isExpanded(QModelIndex index);
KMETHOD QTreeView_isExpanded(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		bool ret_v = qp->isExpanded(index);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTreeView.isFirstColumnSpanned(int row, QModelIndex parent);
KMETHOD QTreeView_isFirstColumnSpanned(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[2]);
		bool ret_v = qp->isFirstColumnSpanned(row, parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTreeView.isHeaderHidden();
KMETHOD QTreeView_isHeaderHidden(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isHeaderHidden();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTreeView.isRowHidden(int row, QModelIndex parent);
KMETHOD QTreeView_isRowHidden(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[2]);
		bool ret_v = qp->isRowHidden(row, parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTreeView.isSortingEnabled();
KMETHOD QTreeView_isSortingEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSortingEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTreeView.getItemsExpandable();
KMETHOD QTreeView_getItemsExpandable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->itemsExpandable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTreeView.getRootIsDecorated();
KMETHOD QTreeView_getRootIsDecorated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->rootIsDecorated();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTreeView.setAllColumnsShowFocus(boolean enable);
KMETHOD QTreeView_setAllColumnsShowFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setAllColumnsShowFocus(enable);
	}
	RETURNvoid_();
}

//void QTreeView.setAnimated(boolean enable);
KMETHOD QTreeView_setAnimated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setAnimated(enable);
	}
	RETURNvoid_();
}

//void QTreeView.setAutoExpandDelay(int delay);
KMETHOD QTreeView_setAutoExpandDelay(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int delay = Int_to(int, sfp[1]);
		qp->setAutoExpandDelay(delay);
	}
	RETURNvoid_();
}

//void QTreeView.setColumnHidden(int column, boolean hide);
KMETHOD QTreeView_setColumnHidden(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		bool hide = Boolean_to(bool, sfp[2]);
		qp->setColumnHidden(column, hide);
	}
	RETURNvoid_();
}

//void QTreeView.setColumnWidth(int column, int width);
KMETHOD QTreeView_setColumnWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int width = Int_to(int, sfp[2]);
		qp->setColumnWidth(column, width);
	}
	RETURNvoid_();
}

//void QTreeView.setExpanded(QModelIndex index, boolean expanded);
KMETHOD QTreeView_setExpanded(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		bool expanded = Boolean_to(bool, sfp[2]);
		qp->setExpanded(index, expanded);
	}
	RETURNvoid_();
}

//void QTreeView.setExpandsOnDoubleClick(boolean enable);
KMETHOD QTreeView_setExpandsOnDoubleClick(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setExpandsOnDoubleClick(enable);
	}
	RETURNvoid_();
}

//void QTreeView.setFirstColumnSpanned(int row, QModelIndex parent, boolean span);
KMETHOD QTreeView_setFirstColumnSpanned(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[2]);
		bool span = Boolean_to(bool, sfp[3]);
		qp->setFirstColumnSpanned(row, parent, span);
	}
	RETURNvoid_();
}

//void QTreeView.setHeader(QHeaderView header);
KMETHOD QTreeView_setHeader(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		QHeaderView*  header = RawPtr_to(QHeaderView*, sfp[1]);
		qp->setHeader(header);
	}
	RETURNvoid_();
}

//void QTreeView.setHeaderHidden(boolean hide);
KMETHOD QTreeView_setHeaderHidden(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool hide = Boolean_to(bool, sfp[1]);
		qp->setHeaderHidden(hide);
	}
	RETURNvoid_();
}

//void QTreeView.setIndentation(int i);
KMETHOD QTreeView_setIndentation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int i = Int_to(int, sfp[1]);
		qp->setIndentation(i);
	}
	RETURNvoid_();
}

//void QTreeView.setItemsExpandable(boolean enable);
KMETHOD QTreeView_setItemsExpandable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setItemsExpandable(enable);
	}
	RETURNvoid_();
}

//void QTreeView.setRootIsDecorated(boolean show);
KMETHOD QTreeView_setRootIsDecorated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool show = Boolean_to(bool, sfp[1]);
		qp->setRootIsDecorated(show);
	}
	RETURNvoid_();
}

//void QTreeView.setRowHidden(int row, QModelIndex parent, boolean hide);
KMETHOD QTreeView_setRowHidden(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[2]);
		bool hide = Boolean_to(bool, sfp[3]);
		qp->setRowHidden(row, parent, hide);
	}
	RETURNvoid_();
}

//void QTreeView.setSortingEnabled(boolean enable);
KMETHOD QTreeView_setSortingEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setSortingEnabled(enable);
	}
	RETURNvoid_();
}

//void QTreeView.setUniformRowHeights(boolean uniform);
KMETHOD QTreeView_setUniformRowHeights(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool uniform = Boolean_to(bool, sfp[1]);
		qp->setUniformRowHeights(uniform);
	}
	RETURNvoid_();
}

//void QTreeView.setWordWrap(boolean on);
KMETHOD QTreeView_setWordWrap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool on = Boolean_to(bool, sfp[1]);
		qp->setWordWrap(on);
	}
	RETURNvoid_();
}

//void QTreeView.sortByColumn(int column, int order);
KMETHOD QTreeView_sortByColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		Qt::SortOrder order = Int_to(Qt::SortOrder, sfp[2]);
		qp->sortByColumn(column, order);
	}
	RETURNvoid_();
}

//boolean QTreeView.getUniformRowHeights();
KMETHOD QTreeView_getUniformRowHeights(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->uniformRowHeights();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTreeView.getWordWrap();
KMETHOD QTreeView_getWordWrap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->wordWrap();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTreeView.collapse(QModelIndex index);
KMETHOD QTreeView_collapse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->collapse(index);
	}
	RETURNvoid_();
}

//void QTreeView.collapseAll();
KMETHOD QTreeView_collapseAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		qp->collapseAll();
	}
	RETURNvoid_();
}

//void QTreeView.expand(QModelIndex index);
KMETHOD QTreeView_expand(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->expand(index);
	}
	RETURNvoid_();
}

//void QTreeView.expandAll();
KMETHOD QTreeView_expandAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		qp->expandAll();
	}
	RETURNvoid_();
}

//void QTreeView.expandToDepth(int depth);
KMETHOD QTreeView_expandToDepth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int depth = Int_to(int, sfp[1]);
		qp->expandToDepth(depth);
	}
	RETURNvoid_();
}

//void QTreeView.hideColumn(int column);
KMETHOD QTreeView_hideColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qp->hideColumn(column);
	}
	RETURNvoid_();
}

//void QTreeView.resizeColumnToContents(int column);
KMETHOD QTreeView_resizeColumnToContents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qp->resizeColumnToContents(column);
	}
	RETURNvoid_();
}

//void QTreeView.showColumn(int column);
KMETHOD QTreeView_showColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTreeView *  qp = RawPtr_to(QTreeView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qp->showColumn(column);
	}
	RETURNvoid_();
}


DummyQTreeView::DummyQTreeView()
{
	self = NULL;
	collapsed_func = NULL;
	expanded_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("collapsed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("expanded", NULL));
}

void DummyQTreeView::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTreeView::self = ptr;
	DummyQAbstractItemView::setSelf(ptr);
}

bool DummyQTreeView::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractItemView::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTreeView::collapsedSlot(const QModelIndex index)
{
	if (collapsed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QModelIndex, index);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, collapsed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQTreeView::expandedSlot(const QModelIndex index)
{
	if (expanded_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QModelIndex, index);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, expanded_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQTreeView::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTreeView::event_map->bigin();
	if ((itr = DummyQTreeView::event_map->find(str)) == DummyQTreeView::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemView::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTreeView::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTreeView::slot_map->bigin();
	if ((itr = DummyQTreeView::slot_map->find(str)) == DummyQTreeView::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemView::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		collapsed_func = (*slot_map)["collapsed"];
		expanded_func = (*slot_map)["expanded"];
		return true;
	}
}

void DummyQTreeView::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, collapsed_func);
	KNH_ADDNNREF(ctx, expanded_func);

	KNH_SIZEREF(ctx);

	DummyQAbstractItemView::reftrace(ctx, p, tail_);
}

void DummyQTreeView::connection(QObject *o)
{
	QTreeView *p = dynamic_cast<QTreeView*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(collapsed(const QModelIndex)), this, SLOT(collapsedSlot(const QModelIndex)));
		connect(p, SIGNAL(expanded(const QModelIndex)), this, SLOT(expandedSlot(const QModelIndex)));
	}
	DummyQAbstractItemView::connection(o);
}

KQTreeView::KQTreeView(QWidget* parent) : QTreeView(parent)
{
	self = NULL;
	dummy = new DummyQTreeView();
	dummy->connection((QObject*)this);
}

KMETHOD QTreeView_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTreeView *qp = RawPtr_to(KQTreeView *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTreeView]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTreeView]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTreeView_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTreeView *qp = RawPtr_to(KQTreeView *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTreeView]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTreeView]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTreeView_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTreeView *qp = (KQTreeView *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTreeView_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQTreeView *qp = (KQTreeView *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTreeView_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTreeView::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQTreeView::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QTreeView::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQTreeView(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTreeView";
	cdef->free = QTreeView_free;
	cdef->reftrace = QTreeView_reftrace;
	cdef->compareTo = QTreeView_compareTo;
}


