//@Virtual @Override QModelIndex QSortFilterProxyModel.buddy(QModelIndex index);
KMETHOD QSortFilterProxyModel_buddy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QModelIndex ret_v = qp->buddy(index);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QSortFilterProxyModel.canFetchMore(QModelIndex parent);
KMETHOD QSortFilterProxyModel_canFetchMore(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		bool ret_v = qp->canFetchMore(parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override int QSortFilterProxyModel.columnCount(QModelIndex parent);
KMETHOD QSortFilterProxyModel_columnCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		int ret_v = qp->columnCount(parent);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QVariant QSortFilterProxyModel.getData(QModelIndex index, int role);
KMETHOD QSortFilterProxyModel_getData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		int role = Int_to(int, sfp[2]);
		QVariant ret_v = qp->data(index, role);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QSortFilterProxyModel.dropMimeData(QMimeData data, int action, int row, int column, QModelIndex parent);
KMETHOD QSortFilterProxyModel_dropMimeData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QMimeData*  data = RawPtr_to(const QMimeData*, sfp[1]);
		Qt::DropAction action = Int_to(Qt::DropAction, sfp[2]);
		int row = Int_to(int, sfp[3]);
		int column = Int_to(int, sfp[4]);
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[5]);
		bool ret_v = qp->dropMimeData(data, action, row, column, parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override void QSortFilterProxyModel.fetchMore(QModelIndex parent);
KMETHOD QSortFilterProxyModel_fetchMore(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->fetchMore(parent);
	}
	RETURNvoid_();
}

//@Virtual @Override QtItemFlags QSortFilterProxyModel.flags(QModelIndex index);
KMETHOD QSortFilterProxyModel_flags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		Qt::ItemFlags ret_v = qp->flags(index);
		Qt::ItemFlags *ret_v_ = new Qt::ItemFlags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QSortFilterProxyModel.hasChildren(QModelIndex parent);
KMETHOD QSortFilterProxyModel_hasChildren(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		bool ret_v = qp->hasChildren(parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QVariant QSortFilterProxyModel.getHeaderData(int section, int orientation, int role);
KMETHOD QSortFilterProxyModel_getHeaderData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		int section = Int_to(int, sfp[1]);
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[2]);
		int role = Int_to(int, sfp[3]);
		QVariant ret_v = qp->headerData(section, orientation, role);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QModelIndex QSortFilterProxyModel.index(int row, int column, QModelIndex parent);
KMETHOD QSortFilterProxyModel_index(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int column = Int_to(int, sfp[2]);
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[3]);
		QModelIndex ret_v = qp->index(row, column, parent);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QSortFilterProxyModel.insertColumns(int column, int count, QModelIndex parent);
KMETHOD QSortFilterProxyModel_insertColumns(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int count = Int_to(int, sfp[2]);
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[3]);
		bool ret_v = qp->insertColumns(column, count, parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override boolean QSortFilterProxyModel.insertRows(int row, int count, QModelIndex parent);
KMETHOD QSortFilterProxyModel_insertRows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int count = Int_to(int, sfp[2]);
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[3]);
		bool ret_v = qp->insertRows(row, count, parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QModelIndex QSortFilterProxyModel.mapFromSource(QModelIndex sourceIndex);
KMETHOD QSortFilterProxyModel_mapFromSource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QModelIndex  sourceIndex = *RawPtr_to(const QModelIndex *, sfp[1]);
		QModelIndex ret_v = qp->mapFromSource(sourceIndex);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QItemSelection QSortFilterProxyModel.mapSelectionFromSource(QItemSelection sourceSelection);
KMETHOD QSortFilterProxyModel_mapSelectionFromSource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QItemSelection  sourceSelection = *RawPtr_to(const QItemSelection *, sfp[1]);
		QItemSelection ret_v = qp->mapSelectionFromSource(sourceSelection);
		QItemSelection *ret_v_ = new QItemSelection(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QItemSelection QSortFilterProxyModel.mapSelectionToSource(QItemSelection proxySelection);
KMETHOD QSortFilterProxyModel_mapSelectionToSource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QItemSelection  proxySelection = *RawPtr_to(const QItemSelection *, sfp[1]);
		QItemSelection ret_v = qp->mapSelectionToSource(proxySelection);
		QItemSelection *ret_v_ = new QItemSelection(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QModelIndex QSortFilterProxyModel.mapToSource(QModelIndex proxyIndex);
KMETHOD QSortFilterProxyModel_mapToSource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QModelIndex  proxyIndex = *RawPtr_to(const QModelIndex *, sfp[1]);
		QModelIndex ret_v = qp->mapToSource(proxyIndex);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QModelIndexList QSortFilterProxyModel.match(QModelIndex start, int role, QVariant value, int hits, QtMatchFlags flags);
KMETHOD QSortFilterProxyModel_match(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QModelIndex  start = *RawPtr_to(const QModelIndex *, sfp[1]);
		int role = Int_to(int, sfp[2]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[3]);
		int hits = Int_to(int, sfp[4]);
		initFlag(flags, Qt::MatchFlags, sfp[5]);
		QModelIndexList ret_v = qp->match(start, role, value, hits, flags);
		QModelIndexList *ret_v_ = new QModelIndexList(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QMimeData QSortFilterProxyModel.mimeData(QModelIndexList indexes);
KMETHOD QSortFilterProxyModel_mimeData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QModelIndexList  indexes = *RawPtr_to(const QModelIndexList *, sfp[1]);
		QMimeData* ret_v = qp->mimeData(indexes);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMimeData*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QModelIndex QSortFilterProxyModel.parent(QModelIndex child);
KMETHOD QSortFilterProxyModel_parent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QModelIndex  child = *RawPtr_to(const QModelIndex *, sfp[1]);
		QModelIndex ret_v = qp->parent(child);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QSortFilterProxyModel.removeColumns(int column, int count, QModelIndex parent);
KMETHOD QSortFilterProxyModel_removeColumns(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		int count = Int_to(int, sfp[2]);
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[3]);
		bool ret_v = qp->removeColumns(column, count, parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override boolean QSortFilterProxyModel.removeRows(int row, int count, QModelIndex parent);
KMETHOD QSortFilterProxyModel_removeRows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int count = Int_to(int, sfp[2]);
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[3]);
		bool ret_v = qp->removeRows(row, count, parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override int QSortFilterProxyModel.rowCount(QModelIndex parent);
KMETHOD QSortFilterProxyModel_rowCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		int ret_v = qp->rowCount(parent);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override boolean QSortFilterProxyModel.setData(QModelIndex index, QVariant value, int role);
KMETHOD QSortFilterProxyModel_setData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[2]);
		int role = Int_to(int, sfp[3]);
		bool ret_v = qp->setData(index, value, role);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override boolean QSortFilterProxyModel.setHeaderData(int section, int orientation, QVariant value, int role);
KMETHOD QSortFilterProxyModel_setHeaderData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		int section = Int_to(int, sfp[1]);
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[2]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[3]);
		int role = Int_to(int, sfp[4]);
		bool ret_v = qp->setHeaderData(section, orientation, value, role);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override void QSortFilterProxyModel.setSourceModel(QAbstractItemModel sourceModel);
KMETHOD QSortFilterProxyModel_setSourceModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		QAbstractItemModel*  sourceModel = RawPtr_to(QAbstractItemModel*, sfp[1]);
		qp->setSourceModel(sourceModel);
	}
	RETURNvoid_();
}

//@Virtual @Override void QSortFilterProxyModel.sort(int column, int order);
KMETHOD QSortFilterProxyModel_sort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		Qt::SortOrder order = Int_to(Qt::SortOrder, sfp[2]);
		qp->sort(column, order);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QSortFilterProxyModel.span(QModelIndex index);
KMETHOD QSortFilterProxyModel_span(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QSize ret_v = qp->span(index);
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QtDropActions QSortFilterProxyModel.supportedDropActions();
KMETHOD QSortFilterProxyModel_supportedDropActions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		Qt::DropActions ret_v = qp->supportedDropActions();
		Qt::DropActions *ret_v_ = new Qt::DropActions(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSortFilterProxyModel QSortFilterProxyModel.new(QObject parent);
KMETHOD QSortFilterProxyModel_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQSortFilterProxyModel *ret_v = new KQSortFilterProxyModel(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QSortFilterProxyModel.getDynamicSortFilter();
KMETHOD QSortFilterProxyModel_getDynamicSortFilter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		bool ret_v = qp->dynamicSortFilter();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QSortFilterProxyModel.getFilterCaseSensitivity();
KMETHOD QSortFilterProxyModel_getFilterCaseSensitivity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		Qt::CaseSensitivity ret_v = qp->filterCaseSensitivity();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QSortFilterProxyModel.getFilterKeyColumn();
KMETHOD QSortFilterProxyModel_getFilterKeyColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		int ret_v = qp->filterKeyColumn();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QRegExp QSortFilterProxyModel.getFilterRegExp();
KMETHOD QSortFilterProxyModel_getFilterRegExp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		QRegExp ret_v = qp->filterRegExp();
		QRegExp *ret_v_ = new QRegExp(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QSortFilterProxyModel.getFilterRole();
KMETHOD QSortFilterProxyModel_getFilterRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		int ret_v = qp->filterRole();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QSortFilterProxyModel.isSortLocaleAware();
KMETHOD QSortFilterProxyModel_isSortLocaleAware(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSortLocaleAware();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QSortFilterProxyModel.setDynamicSortFilter(boolean enable);
KMETHOD QSortFilterProxyModel_setDynamicSortFilter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setDynamicSortFilter(enable);
	}
	RETURNvoid_();
}

//void QSortFilterProxyModel.setFilterCaseSensitivity(int cs);
KMETHOD QSortFilterProxyModel_setFilterCaseSensitivity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		Qt::CaseSensitivity cs = Int_to(Qt::CaseSensitivity, sfp[1]);
		qp->setFilterCaseSensitivity(cs);
	}
	RETURNvoid_();
}

//void QSortFilterProxyModel.setFilterKeyColumn(int column);
KMETHOD QSortFilterProxyModel_setFilterKeyColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		qp->setFilterKeyColumn(column);
	}
	RETURNvoid_();
}

//void QSortFilterProxyModel.setFilterRegExp(QRegExp regExp);
KMETHOD QSortFilterProxyModel_setFilterRegExp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QRegExp  regExp = *RawPtr_to(const QRegExp *, sfp[1]);
		qp->setFilterRegExp(regExp);
	}
	RETURNvoid_();
}

//void QSortFilterProxyModel.setFilterRole(int role);
KMETHOD QSortFilterProxyModel_setFilterRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		int role = Int_to(int, sfp[1]);
		qp->setFilterRole(role);
	}
	RETURNvoid_();
}

//void QSortFilterProxyModel.setSortCaseSensitivity(int cs);
KMETHOD QSortFilterProxyModel_setSortCaseSensitivity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		Qt::CaseSensitivity cs = Int_to(Qt::CaseSensitivity, sfp[1]);
		qp->setSortCaseSensitivity(cs);
	}
	RETURNvoid_();
}

//void QSortFilterProxyModel.setSortLocaleAware(boolean on);
KMETHOD QSortFilterProxyModel_setSortLocaleAware(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		bool on = Boolean_to(bool, sfp[1]);
		qp->setSortLocaleAware(on);
	}
	RETURNvoid_();
}

//void QSortFilterProxyModel.setSortRole(int role);
KMETHOD QSortFilterProxyModel_setSortRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		int role = Int_to(int, sfp[1]);
		qp->setSortRole(role);
	}
	RETURNvoid_();
}

//int QSortFilterProxyModel.getSortCaseSensitivity();
KMETHOD QSortFilterProxyModel_getSortCaseSensitivity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		Qt::CaseSensitivity ret_v = qp->sortCaseSensitivity();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QSortFilterProxyModel.sortColumn();
KMETHOD QSortFilterProxyModel_sortColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		int ret_v = qp->sortColumn();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QSortFilterProxyModel.sortOrder();
KMETHOD QSortFilterProxyModel_sortOrder(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		Qt::SortOrder ret_v = qp->sortOrder();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QSortFilterProxyModel.getSortRole();
KMETHOD QSortFilterProxyModel_getSortRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		int ret_v = qp->sortRole();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QSortFilterProxyModel.invalidate();
KMETHOD QSortFilterProxyModel_invalidate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		qp->invalidate();
	}
	RETURNvoid_();
}

//void QSortFilterProxyModel.setFilterFixedString(String pattern);
KMETHOD QSortFilterProxyModel_setFilterFixedString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QString pattern = String_to(const QString, sfp[1]);
		qp->setFilterFixedString(pattern);
	}
	RETURNvoid_();
}

/*
//void QSortFilterProxyModel.setFilterRegExp(String pattern);
KMETHOD QSortFilterProxyModel_setFilterRegExp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QString pattern = String_to(const QString, sfp[1]);
		qp->setFilterRegExp(pattern);
	}
	RETURNvoid_();
}
*/
//void QSortFilterProxyModel.setFilterWildcard(String pattern);
KMETHOD QSortFilterProxyModel_setFilterWildcard(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSortFilterProxyModel *  qp = RawPtr_to(QSortFilterProxyModel *, sfp[0]);
	if (qp) {
		const QString pattern = String_to(const QString, sfp[1]);
		qp->setFilterWildcard(pattern);
	}
	RETURNvoid_();
}


DummyQSortFilterProxyModel::DummyQSortFilterProxyModel()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSortFilterProxyModel::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSortFilterProxyModel::self = ptr;
	DummyQAbstractProxyModel::setSelf(ptr);
}

bool DummyQSortFilterProxyModel::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractProxyModel::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQSortFilterProxyModel::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSortFilterProxyModel::event_map->bigin();
	if ((itr = DummyQSortFilterProxyModel::event_map->find(str)) == DummyQSortFilterProxyModel::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractProxyModel::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSortFilterProxyModel::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSortFilterProxyModel::slot_map->bigin();
	if ((itr = DummyQSortFilterProxyModel::slot_map->find(str)) == DummyQSortFilterProxyModel::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractProxyModel::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQSortFilterProxyModel::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQAbstractProxyModel::reftrace(ctx, p, tail_);
}

void DummyQSortFilterProxyModel::connection(QObject *o)
{
	QSortFilterProxyModel *p = dynamic_cast<QSortFilterProxyModel*>(o);
	if (p != NULL) {
	}
	DummyQAbstractProxyModel::connection(o);
}

KQSortFilterProxyModel::KQSortFilterProxyModel(QObject* parent) : QSortFilterProxyModel(parent)
{
	self = NULL;
	dummy = new DummyQSortFilterProxyModel();
	dummy->connection((QObject*)this);
}

KMETHOD QSortFilterProxyModel_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSortFilterProxyModel *qp = RawPtr_to(KQSortFilterProxyModel *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSortFilterProxyModel]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSortFilterProxyModel]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSortFilterProxyModel_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSortFilterProxyModel *qp = RawPtr_to(KQSortFilterProxyModel *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSortFilterProxyModel]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSortFilterProxyModel]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSortFilterProxyModel_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSortFilterProxyModel *qp = (KQSortFilterProxyModel *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSortFilterProxyModel_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQSortFilterProxyModel *qp = (KQSortFilterProxyModel *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSortFilterProxyModel_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSortFilterProxyModel::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQSortFilterProxyModel::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QSortFilterProxyModel::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQSortFilterProxyModel(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSortFilterProxyModel";
	cdef->free = QSortFilterProxyModel_free;
	cdef->reftrace = QSortFilterProxyModel_reftrace;
	cdef->compareTo = QSortFilterProxyModel_compareTo;
}


