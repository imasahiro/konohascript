//@Virtual @Override QModelIndex QTableView.indexAt(QPoint pos);
KMETHOD QTableView_indexAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		QModelIndex ret_v = qp->indexAt(pos);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QTableView.setModel(QAbstractItemModel model);
KMETHOD QTableView_setModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		QAbstractItemModel*  model = RawPtr_to(QAbstractItemModel*, sfp[1]);
		qp->setModel(model);
	}
	RETURNvoid_();
}

//@Virtual @Override void QTableView.setRootIndex(QModelIndex index);
KMETHOD QTableView_setRootIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->setRootIndex(index);
	}
	RETURNvoid_();
}

//@Virtual @Override void QTableView.setSelectionModel(QItemSelectionModel selectionModel);
KMETHOD QTableView_setSelectionModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		QItemSelectionModel*  selectionModel = RawPtr_to(QItemSelectionModel*, sfp[1]);
		qp->setSelectionModel(selectionModel);
	}
	RETURNvoid_();
}

//QTableView QTableView.new(QWidget parent);
KMETHOD QTableView_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQTableView *ret_v = new KQTableView(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QTableView.clearSpans();
KMETHOD QTableView_clearSpans(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		qp->clearSpans();
	}
	RETURNvoid_();
}

//int QTableView.columnAt(int x);
KMETHOD QTableView_columnAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		int ret_v = qp->columnAt(x);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTableView.columnSpan(int row, int column);
KMETHOD QTableView_columnSpan(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int column = Int_to(int, sfp[2]);
		int ret_v = qp->columnSpan(row, column);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTableView.columnViewportPosition(int column);
KMETHOD QTableView_columnViewportPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int ret_v = qp->columnViewportPosition(column);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTableView.getColumnWidth(int column);
KMETHOD QTableView_getColumnWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int ret_v = qp->columnWidth(column);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTableView.getGridStyle();
KMETHOD QTableView_getGridStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		Qt::PenStyle ret_v = qp->gridStyle();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QHeaderView QTableView.getHorizontalHeader();
KMETHOD QTableView_getHorizontalHeader(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		QHeaderView* ret_v = qp->horizontalHeader();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QHeaderView*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QTableView.isColumnHidden(int column);
KMETHOD QTableView_isColumnHidden(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		bool ret_v = qp->isColumnHidden(column);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTableView.isCornerButtonEnabled();
KMETHOD QTableView_isCornerButtonEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isCornerButtonEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTableView.isRowHidden(int row);
KMETHOD QTableView_isRowHidden(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		bool ret_v = qp->isRowHidden(row);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTableView.isSortingEnabled();
KMETHOD QTableView_isSortingEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSortingEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTableView.rowAt(int y);
KMETHOD QTableView_rowAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int y = Int_to(int, sfp[1]);
		int ret_v = qp->rowAt(y);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTableView.getRowHeight(int row);
KMETHOD QTableView_getRowHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int ret_v = qp->rowHeight(row);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTableView.rowSpan(int row, int column);
KMETHOD QTableView_rowSpan(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int column = Int_to(int, sfp[2]);
		int ret_v = qp->rowSpan(row, column);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTableView.rowViewportPosition(int row);
KMETHOD QTableView_rowViewportPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int ret_v = qp->rowViewportPosition(row);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTableView.setColumnHidden(int column, boolean hide);
KMETHOD QTableView_setColumnHidden(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		bool hide = Boolean_to(bool, sfp[2]);
		qp->setColumnHidden(column, hide);
	}
	RETURNvoid_();
}

//void QTableView.setColumnWidth(int column, int width);
KMETHOD QTableView_setColumnWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int width = Int_to(int, sfp[2]);
		qp->setColumnWidth(column, width);
	}
	RETURNvoid_();
}

//void QTableView.setCornerButtonEnabled(boolean enable);
KMETHOD QTableView_setCornerButtonEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setCornerButtonEnabled(enable);
	}
	RETURNvoid_();
}

//void QTableView.setGridStyle(int style);
KMETHOD QTableView_setGridStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		Qt::PenStyle style = Int_to(Qt::PenStyle, sfp[1]);
		qp->setGridStyle(style);
	}
	RETURNvoid_();
}

//void QTableView.setHorizontalHeader(QHeaderView header);
KMETHOD QTableView_setHorizontalHeader(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		QHeaderView*  header = RawPtr_to(QHeaderView*, sfp[1]);
		qp->setHorizontalHeader(header);
	}
	RETURNvoid_();
}

//void QTableView.setRowHeight(int row, int height);
KMETHOD QTableView_setRowHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int height = Int_to(int, sfp[2]);
		qp->setRowHeight(row, height);
	}
	RETURNvoid_();
}

//void QTableView.setRowHidden(int row, boolean hide);
KMETHOD QTableView_setRowHidden(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		bool hide = Boolean_to(bool, sfp[2]);
		qp->setRowHidden(row, hide);
	}
	RETURNvoid_();
}

//void QTableView.setSortingEnabled(boolean enable);
KMETHOD QTableView_setSortingEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setSortingEnabled(enable);
	}
	RETURNvoid_();
}

//void QTableView.setSpan(int row, int column, int rowSpanCount, int columnSpanCount);
KMETHOD QTableView_setSpan(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int column = Int_to(int, sfp[2]);
		int rowSpanCount = Int_to(int, sfp[3]);
		int columnSpanCount = Int_to(int, sfp[4]);
		qp->setSpan(row, column, rowSpanCount, columnSpanCount);
	}
	RETURNvoid_();
}

//void QTableView.setVerticalHeader(QHeaderView header);
KMETHOD QTableView_setVerticalHeader(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		QHeaderView*  header = RawPtr_to(QHeaderView*, sfp[1]);
		qp->setVerticalHeader(header);
	}
	RETURNvoid_();
}

//void QTableView.setWordWrap(boolean on);
KMETHOD QTableView_setWordWrap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		bool on = Boolean_to(bool, sfp[1]);
		qp->setWordWrap(on);
	}
	RETURNvoid_();
}

//boolean QTableView.getShowGrid();
KMETHOD QTableView_getShowGrid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->showGrid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTableView.sortByColumn(int column, int order);
KMETHOD QTableView_sortByColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		Qt::SortOrder order = Int_to(Qt::SortOrder, sfp[2]);
		qp->sortByColumn(column, order);
	}
	RETURNvoid_();
}

//QHeaderView QTableView.getVerticalHeader();
KMETHOD QTableView_getVerticalHeader(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		QHeaderView* ret_v = qp->verticalHeader();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QHeaderView*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QTableView.getWordWrap();
KMETHOD QTableView_getWordWrap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->wordWrap();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTableView.hideColumn(int column);
KMETHOD QTableView_hideColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qp->hideColumn(column);
	}
	RETURNvoid_();
}

//void QTableView.hideRow(int row);
KMETHOD QTableView_hideRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		qp->hideRow(row);
	}
	RETURNvoid_();
}

//void QTableView.resizeColumnToContents(int column);
KMETHOD QTableView_resizeColumnToContents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qp->resizeColumnToContents(column);
	}
	RETURNvoid_();
}

//void QTableView.resizeColumnsToContents();
KMETHOD QTableView_resizeColumnsToContents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		qp->resizeColumnsToContents();
	}
	RETURNvoid_();
}

//void QTableView.resizeRowToContents(int row);
KMETHOD QTableView_resizeRowToContents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		qp->resizeRowToContents(row);
	}
	RETURNvoid_();
}

//void QTableView.resizeRowsToContents();
KMETHOD QTableView_resizeRowsToContents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		qp->resizeRowsToContents();
	}
	RETURNvoid_();
}

//void QTableView.selectColumn(int column);
KMETHOD QTableView_selectColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qp->selectColumn(column);
	}
	RETURNvoid_();
}

//void QTableView.selectRow(int row);
KMETHOD QTableView_selectRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		qp->selectRow(row);
	}
	RETURNvoid_();
}

//void QTableView.setShowGrid(boolean show);
KMETHOD QTableView_setShowGrid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		bool show = Boolean_to(bool, sfp[1]);
		qp->setShowGrid(show);
	}
	RETURNvoid_();
}

//void QTableView.showColumn(int column);
KMETHOD QTableView_showColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qp->showColumn(column);
	}
	RETURNvoid_();
}

//void QTableView.showRow(int row);
KMETHOD QTableView_showRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTableView *  qp = RawPtr_to(QTableView *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		qp->showRow(row);
	}
	RETURNvoid_();
}


DummyQTableView::DummyQTableView()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQTableView::~DummyQTableView()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQTableView::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTableView::self = ptr;
	DummyQAbstractItemView::setSelf(ptr);
}

bool DummyQTableView::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractItemView::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTableView::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTableView::event_map->bigin();
	if ((itr = DummyQTableView::event_map->find(str)) == DummyQTableView::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemView::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTableView::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTableView::slot_map->bigin();
	if ((itr = DummyQTableView::slot_map->find(str)) == DummyQTableView::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemView::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTableView::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTableView::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQAbstractItemView::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQTableView::connection(QObject *o)
{
	QTableView *p = dynamic_cast<QTableView*>(o);
	if (p != NULL) {
	}
	DummyQAbstractItemView::connection(o);
}

KQTableView::KQTableView(QWidget* parent) : QTableView(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQTableView();
	dummy->connection((QObject*)this);
}

KQTableView::~KQTableView()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QTableView_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTableView *qp = RawPtr_to(KQTableView *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTableView]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTableView]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTableView_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTableView *qp = RawPtr_to(KQTableView *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTableView]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTableView]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTableView_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQTableView *qp = (KQTableView *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QTableView*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QTableView_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQTableView *qp = (KQTableView *)p->rawptr;
		KQTableView *qp = static_cast<KQTableView*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTableView_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTableView::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQTableView::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QTableView::event(event);
		return false;
	}
//	QTableView::event(event);
	return true;
}



DEFAPI(void) defQTableView(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTableView";
	cdef->free = QTableView_free;
	cdef->reftrace = QTableView_reftrace;
	cdef->compareTo = QTableView_compareTo;
}


