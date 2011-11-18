//
//@Virtual QModelIndex QAbstractItemModel.buddy(QModelIndex index);
KMETHOD QAbstractItemModel_buddy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
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

//@Virtual boolean QAbstractItemModel.canFetchMore(QModelIndex parent);
KMETHOD QAbstractItemModel_canFetchMore(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		bool ret_v = qp->canFetchMore(parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual QVariant QAbstractItemModel.getData(QModelIndex index, int role);
KMETHOD QAbstractItemModel_getData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
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

//@Virtual boolean QAbstractItemModel.dropMimeData(QMimeData data, int action, int row, int column, QModelIndex parent);
KMETHOD QAbstractItemModel_dropMimeData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
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

//@Virtual void QAbstractItemModel.fetchMore(QModelIndex parent);
KMETHOD QAbstractItemModel_fetchMore(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->fetchMore(parent);
	}
	RETURNvoid_();
}

//@Virtual QtItemFlags QAbstractItemModel.flags(QModelIndex index);
KMETHOD QAbstractItemModel_flags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
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

//@Virtual boolean QAbstractItemModel.hasChildren(QModelIndex parent);
KMETHOD QAbstractItemModel_hasChildren(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		bool ret_v = qp->hasChildren(parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAbstractItemModel.hasIndex(int row, int column, QModelIndex parent);
KMETHOD QAbstractItemModel_hasIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int column = Int_to(int, sfp[2]);
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[3]);
		bool ret_v = qp->hasIndex(row, column, parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual QVariant QAbstractItemModel.getHeaderData(int section, int orientation, int role);
KMETHOD QAbstractItemModel_getHeaderData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
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

//@Virtual boolean QAbstractItemModel.insertColumns(int column, int count, QModelIndex parent);
KMETHOD QAbstractItemModel_insertColumns(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
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

//@Virtual boolean QAbstractItemModel.insertRows(int row, int count, QModelIndex parent);
KMETHOD QAbstractItemModel_insertRows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
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

//@Virtual QModelIndexList QAbstractItemModel.match(QModelIndex start, int role, QVariant value, int hits, QtMatchFlags flags);
KMETHOD QAbstractItemModel_match(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
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

//@Virtual QMimeData QAbstractItemModel.mimeData(QModelIndexList indexes);
KMETHOD QAbstractItemModel_mimeData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp) {
		const QModelIndexList  indexes = *RawPtr_to(const QModelIndexList *, sfp[1]);
		QMimeData* ret_v = qp->mimeData(indexes);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMimeData*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QModelIndex QAbstractItemModel.parent(QModelIndex index);
KMETHOD QAbstractItemModel_parent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QModelIndex ret_v = qp->parent(index);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QAbstractItemModel.removeColumn(int column, QModelIndex parent);
KMETHOD QAbstractItemModel_removeColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[2]);
		bool ret_v = qp->removeColumn(column, parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QAbstractItemModel.removeColumns(int column, int count, QModelIndex parent);
KMETHOD QAbstractItemModel_removeColumns(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
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

//boolean QAbstractItemModel.removeRow(int row, QModelIndex parent);
KMETHOD QAbstractItemModel_removeRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[2]);
		bool ret_v = qp->removeRow(row, parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QAbstractItemModel.removeRows(int row, int count, QModelIndex parent);
KMETHOD QAbstractItemModel_removeRows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
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

//@Virtual boolean QAbstractItemModel.setData(QModelIndex index, QVariant value, int role);
KMETHOD QAbstractItemModel_setData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
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

//@Virtual boolean QAbstractItemModel.setHeaderData(int section, int orientation, QVariant value, int role);
KMETHOD QAbstractItemModel_setHeaderData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
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

//void QAbstractItemModel.setSupportedDragActions(QtDropActions actions);
KMETHOD QAbstractItemModel_setSupportedDragActions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp) {
		initFlag(actions, Qt::DropActions, sfp[1]);
		qp->setSupportedDragActions(actions);
	}
	RETURNvoid_();
}

//QModelIndex QAbstractItemModel.sibling(int row, int column, QModelIndex index);
KMETHOD QAbstractItemModel_sibling(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp) {
		int row = Int_to(int, sfp[1]);
		int column = Int_to(int, sfp[2]);
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[3]);
		QModelIndex ret_v = qp->sibling(row, column, index);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QAbstractItemModel.sort(int column, int order);
KMETHOD QAbstractItemModel_sort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp) {
		int column = Int_to(int, sfp[1]);
		Qt::SortOrder order = Int_to(Qt::SortOrder, sfp[2]);
		qp->sort(column, order);
	}
	RETURNvoid_();
}

//@Virtual QSize QAbstractItemModel.span(QModelIndex index);
KMETHOD QAbstractItemModel_span(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
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

//QtDropActions QAbstractItemModel.getSupportedDragActions();
KMETHOD QAbstractItemModel_getSupportedDragActions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp) {
		Qt::DropActions ret_v = qp->supportedDragActions();
		Qt::DropActions *ret_v_ = new Qt::DropActions(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QtDropActions QAbstractItemModel.supportedDropActions();
KMETHOD QAbstractItemModel_supportedDropActions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp) {
		Qt::DropActions ret_v = qp->supportedDropActions();
		Qt::DropActions *ret_v_ = new Qt::DropActions(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QAbstractItemModel.revert();
KMETHOD QAbstractItemModel_revert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp) {
		qp->revert();
	}
	RETURNvoid_();
}

//@Virtual boolean QAbstractItemModel.submit();
KMETHOD QAbstractItemModel_submit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp) {
		bool ret_v = qp->submit();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQAbstractItemModel::DummyQAbstractItemModel()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	columns_about_to_be_inserted_func = NULL;
	columns_about_to_be_moved_func = NULL;
	columns_about_to_be_removed_func = NULL;
	columns_inserted_func = NULL;
	columns_moved_func = NULL;
	columns_removed_func = NULL;
	data_changed_func = NULL;
	header_data_changed_func = NULL;
	layout_about_to_be_changed_func = NULL;
	layout_changed_func = NULL;
	model_about_to_be_reset_func = NULL;
	model_reset_func = NULL;
	rows_about_to_be_inserted_func = NULL;
	rows_about_to_be_moved_func = NULL;
	rows_about_to_be_removed_func = NULL;
	rows_inserted_func = NULL;
	rows_moved_func = NULL;
	rows_removed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("columns-about-to-be-inserted", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("columns-about-to-be-moved", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("columns-about-to-be-removed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("columns-inserted", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("columns-moved", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("columns-removed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("data-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("header-data-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("layout-about-to-be-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("layout-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("model-about-to-be-reset", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("model-reset", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("rows-about-to-be-inserted", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("rows-about-to-be-moved", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("rows-about-to-be-removed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("rows-inserted", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("rows-moved", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("rows-removed", NULL));
}
DummyQAbstractItemModel::~DummyQAbstractItemModel()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQAbstractItemModel::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractItemModel::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQAbstractItemModel::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractItemModel::columnsAboutToBeInsertedSlot(const QModelIndex parent, int start, int end)
{
	if (columns_about_to_be_inserted_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QModelIndex, parent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		lsfp[K_CALLDELTA+3].ivalue = start;
		lsfp[K_CALLDELTA+4].ivalue = end;
		knh_Func_invoke(lctx, columns_about_to_be_inserted_func, lsfp, 4);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::columnsAboutToBeMovedSlot(const QModelIndex sourceParent, int sourceStart, int sourceEnd, const QModelIndex destinationParent, int destinationColumn)
{
	if (columns_about_to_be_moved_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QModelIndex, sourceParent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		lsfp[K_CALLDELTA+3].ivalue = sourceStart;
		lsfp[K_CALLDELTA+4].ivalue = sourceEnd;
		knh_RawPtr_t *p4 = new_QRawPtr(lctx, QModelIndex, destinationParent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+5].o, UPCAST(p4));
		lsfp[K_CALLDELTA+6].ivalue = destinationColumn;
		knh_Func_invoke(lctx, columns_about_to_be_moved_func, lsfp, 6);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::columnsAboutToBeRemovedSlot(const QModelIndex parent, int start, int end)
{
	if (columns_about_to_be_removed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QModelIndex, parent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		lsfp[K_CALLDELTA+3].ivalue = start;
		lsfp[K_CALLDELTA+4].ivalue = end;
		knh_Func_invoke(lctx, columns_about_to_be_removed_func, lsfp, 4);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::columnsInsertedSlot(const QModelIndex parent, int start, int end)
{
	if (columns_inserted_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QModelIndex, parent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		lsfp[K_CALLDELTA+3].ivalue = start;
		lsfp[K_CALLDELTA+4].ivalue = end;
		knh_Func_invoke(lctx, columns_inserted_func, lsfp, 4);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::columnsMovedSlot(const QModelIndex sourceParent, int sourceStart, int sourceEnd, const QModelIndex destinationParent, int destinationColumn)
{
	if (columns_moved_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QModelIndex, sourceParent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		lsfp[K_CALLDELTA+3].ivalue = sourceStart;
		lsfp[K_CALLDELTA+4].ivalue = sourceEnd;
		knh_RawPtr_t *p4 = new_QRawPtr(lctx, QModelIndex, destinationParent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+5].o, UPCAST(p4));
		lsfp[K_CALLDELTA+6].ivalue = destinationColumn;
		knh_Func_invoke(lctx, columns_moved_func, lsfp, 6);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::columnsRemovedSlot(const QModelIndex parent, int start, int end)
{
	if (columns_removed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QModelIndex, parent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		lsfp[K_CALLDELTA+3].ivalue = start;
		lsfp[K_CALLDELTA+4].ivalue = end;
		knh_Func_invoke(lctx, columns_removed_func, lsfp, 4);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::dataChangedSlot(const QModelIndex topLeft, const QModelIndex bottomRight)
{
	if (data_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QModelIndex, topLeft);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_RawPtr_t *p2 = new_QRawPtr(lctx, QModelIndex, bottomRight);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		knh_Func_invoke(lctx, data_changed_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::headerDataChangedSlot(Qt::Orientation orientation, int first, int last)
{
	if (header_data_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = orientation;
		lsfp[K_CALLDELTA+3].ivalue = first;
		lsfp[K_CALLDELTA+4].ivalue = last;
		knh_Func_invoke(lctx, header_data_changed_func, lsfp, 4);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::layoutAboutToBeChangedSlot()
{
	if (layout_about_to_be_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, layout_about_to_be_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::layoutChangedSlot()
{
	if (layout_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, layout_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::modelAboutToBeResetSlot()
{
	if (model_about_to_be_reset_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, model_about_to_be_reset_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::modelResetSlot()
{
	if (model_reset_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, model_reset_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::rowsAboutToBeInsertedSlot(const QModelIndex parent, int start, int end)
{
	if (rows_about_to_be_inserted_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QModelIndex, parent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		lsfp[K_CALLDELTA+3].ivalue = start;
		lsfp[K_CALLDELTA+4].ivalue = end;
		knh_Func_invoke(lctx, rows_about_to_be_inserted_func, lsfp, 4);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::rowsAboutToBeMovedSlot(const QModelIndex sourceParent, int sourceStart, int sourceEnd, const QModelIndex destinationParent, int destinationRow)
{
	if (rows_about_to_be_moved_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QModelIndex, sourceParent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		lsfp[K_CALLDELTA+3].ivalue = sourceStart;
		lsfp[K_CALLDELTA+4].ivalue = sourceEnd;
		knh_RawPtr_t *p4 = new_QRawPtr(lctx, QModelIndex, destinationParent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+5].o, UPCAST(p4));
		lsfp[K_CALLDELTA+6].ivalue = destinationRow;
		knh_Func_invoke(lctx, rows_about_to_be_moved_func, lsfp, 6);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::rowsAboutToBeRemovedSlot(const QModelIndex parent, int start, int end)
{
	if (rows_about_to_be_removed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QModelIndex, parent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		lsfp[K_CALLDELTA+3].ivalue = start;
		lsfp[K_CALLDELTA+4].ivalue = end;
		knh_Func_invoke(lctx, rows_about_to_be_removed_func, lsfp, 4);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::rowsInsertedSlot(const QModelIndex parent, int start, int end)
{
	if (rows_inserted_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QModelIndex, parent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		lsfp[K_CALLDELTA+3].ivalue = start;
		lsfp[K_CALLDELTA+4].ivalue = end;
		knh_Func_invoke(lctx, rows_inserted_func, lsfp, 4);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::rowsMovedSlot(const QModelIndex sourceParent, int sourceStart, int sourceEnd, const QModelIndex destinationParent, int destinationRow)
{
	if (rows_moved_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QModelIndex, sourceParent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		lsfp[K_CALLDELTA+3].ivalue = sourceStart;
		lsfp[K_CALLDELTA+4].ivalue = sourceEnd;
		knh_RawPtr_t *p4 = new_QRawPtr(lctx, QModelIndex, destinationParent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+5].o, UPCAST(p4));
		lsfp[K_CALLDELTA+6].ivalue = destinationRow;
		knh_Func_invoke(lctx, rows_moved_func, lsfp, 6);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::rowsRemovedSlot(const QModelIndex parent, int start, int end)
{
	if (rows_removed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QModelIndex, parent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		lsfp[K_CALLDELTA+3].ivalue = start;
		lsfp[K_CALLDELTA+4].ivalue = end;
		knh_Func_invoke(lctx, rows_removed_func, lsfp, 4);
		return true;
	}
	return false;
}

bool DummyQAbstractItemModel::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractItemModel::event_map->bigin();
	if ((itr = DummyQAbstractItemModel::event_map->find(str)) == DummyQAbstractItemModel::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractItemModel::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractItemModel::slot_map->bigin();
	if ((itr = DummyQAbstractItemModel::slot_map->find(str)) == DummyQAbstractItemModel::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		columns_about_to_be_inserted_func = (*slot_map)["columns-about-to-be-inserted"];
		columns_about_to_be_moved_func = (*slot_map)["columns-about-to-be-moved"];
		columns_about_to_be_removed_func = (*slot_map)["columns-about-to-be-removed"];
		columns_inserted_func = (*slot_map)["columns-inserted"];
		columns_moved_func = (*slot_map)["columns-moved"];
		columns_removed_func = (*slot_map)["columns-removed"];
		data_changed_func = (*slot_map)["data-changed"];
		header_data_changed_func = (*slot_map)["header-data-changed"];
		layout_about_to_be_changed_func = (*slot_map)["layout-about-to-be-changed"];
		layout_changed_func = (*slot_map)["layout-changed"];
		model_about_to_be_reset_func = (*slot_map)["model-about-to-be-reset"];
		model_reset_func = (*slot_map)["model-reset"];
		rows_about_to_be_inserted_func = (*slot_map)["rows-about-to-be-inserted"];
		rows_about_to_be_moved_func = (*slot_map)["rows-about-to-be-moved"];
		rows_about_to_be_removed_func = (*slot_map)["rows-about-to-be-removed"];
		rows_inserted_func = (*slot_map)["rows-inserted"];
		rows_moved_func = (*slot_map)["rows-moved"];
		rows_removed_func = (*slot_map)["rows-removed"];
		return true;
	}
}

knh_Object_t** DummyQAbstractItemModel::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQAbstractItemModel::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 19;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, columns_about_to_be_inserted_func);
	KNH_ADDNNREF(ctx, columns_about_to_be_moved_func);
	KNH_ADDNNREF(ctx, columns_about_to_be_removed_func);
	KNH_ADDNNREF(ctx, columns_inserted_func);
	KNH_ADDNNREF(ctx, columns_moved_func);
	KNH_ADDNNREF(ctx, columns_removed_func);
	KNH_ADDNNREF(ctx, data_changed_func);
	KNH_ADDNNREF(ctx, header_data_changed_func);
	KNH_ADDNNREF(ctx, layout_about_to_be_changed_func);
	KNH_ADDNNREF(ctx, layout_changed_func);
	KNH_ADDNNREF(ctx, model_about_to_be_reset_func);
	KNH_ADDNNREF(ctx, model_reset_func);
	KNH_ADDNNREF(ctx, rows_about_to_be_inserted_func);
	KNH_ADDNNREF(ctx, rows_about_to_be_moved_func);
	KNH_ADDNNREF(ctx, rows_about_to_be_removed_func);
	KNH_ADDNNREF(ctx, rows_inserted_func);
	KNH_ADDNNREF(ctx, rows_moved_func);
	KNH_ADDNNREF(ctx, rows_removed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQAbstractItemModel::connection(QObject *o)
{
	QAbstractItemModel *p = dynamic_cast<QAbstractItemModel*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(columnsAboutToBeInserted(const QModelIndex, int, int)), this, SLOT(columnsAboutToBeInsertedSlot(const QModelIndex, int, int)));
		connect(p, SIGNAL(columnsAboutToBeMoved(const QModelIndex, int, int, const QModelIndex, int)), this, SLOT(columnsAboutToBeMovedSlot(const QModelIndex, int, int, const QModelIndex, int)));
		connect(p, SIGNAL(columnsAboutToBeRemoved(const QModelIndex, int, int)), this, SLOT(columnsAboutToBeRemovedSlot(const QModelIndex, int, int)));
		connect(p, SIGNAL(columnsInserted(const QModelIndex, int, int)), this, SLOT(columnsInsertedSlot(const QModelIndex, int, int)));
		connect(p, SIGNAL(columnsMoved(const QModelIndex, int, int, const QModelIndex, int)), this, SLOT(columnsMovedSlot(const QModelIndex, int, int, const QModelIndex, int)));
		connect(p, SIGNAL(columnsRemoved(const QModelIndex, int, int)), this, SLOT(columnsRemovedSlot(const QModelIndex, int, int)));
		connect(p, SIGNAL(dataChanged(const QModelIndex, const QModelIndex)), this, SLOT(dataChangedSlot(const QModelIndex, const QModelIndex)));
		connect(p, SIGNAL(headerDataChanged(Qt::Orientation, int, int)), this, SLOT(headerDataChangedSlot(Qt::Orientation, int, int)));
		connect(p, SIGNAL(layoutAboutToBeChanged()), this, SLOT(layoutAboutToBeChangedSlot()));
		connect(p, SIGNAL(layoutChanged()), this, SLOT(layoutChangedSlot()));
		connect(p, SIGNAL(modelAboutToBeReset()), this, SLOT(modelAboutToBeResetSlot()));
		connect(p, SIGNAL(modelReset()), this, SLOT(modelResetSlot()));
		connect(p, SIGNAL(rowsAboutToBeInserted(const QModelIndex, int, int)), this, SLOT(rowsAboutToBeInsertedSlot(const QModelIndex, int, int)));
		connect(p, SIGNAL(rowsAboutToBeMoved(const QModelIndex, int, int, const QModelIndex, int)), this, SLOT(rowsAboutToBeMovedSlot(const QModelIndex, int, int, const QModelIndex, int)));
		connect(p, SIGNAL(rowsAboutToBeRemoved(const QModelIndex, int, int)), this, SLOT(rowsAboutToBeRemovedSlot(const QModelIndex, int, int)));
		connect(p, SIGNAL(rowsInserted(const QModelIndex, int, int)), this, SLOT(rowsInsertedSlot(const QModelIndex, int, int)));
		connect(p, SIGNAL(rowsMoved(const QModelIndex, int, int, const QModelIndex, int)), this, SLOT(rowsMovedSlot(const QModelIndex, int, int, const QModelIndex, int)));
		connect(p, SIGNAL(rowsRemoved(const QModelIndex, int, int)), this, SLOT(rowsRemovedSlot(const QModelIndex, int, int)));
	}
	DummyQObject::connection(o);
}

KQAbstractItemModel::KQAbstractItemModel(QObject* parent) : QAbstractItemModel(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQAbstractItemModel();
	dummy->connection((QObject*)this);
}

KQAbstractItemModel::~KQAbstractItemModel()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QAbstractItemModel_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractItemModel *qp = RawPtr_to(KQAbstractItemModel *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractItemModel]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractItemModel]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAbstractItemModel_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractItemModel *qp = RawPtr_to(KQAbstractItemModel *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractItemModel]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractItemModel]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractItemModel_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQAbstractItemModel *qp = (KQAbstractItemModel *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QAbstractItemModel*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QAbstractItemModel_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQAbstractItemModel *qp = (KQAbstractItemModel *)p->rawptr;
		KQAbstractItemModel *qp = static_cast<KQAbstractItemModel*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAbstractItemModel_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAbstractItemModel::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQAbstractItemModel::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QAbstractItemModel::event(event);
		return false;
	}
//	QAbstractItemModel::event(event);
	return true;
}



DEFAPI(void) defQAbstractItemModel(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractItemModel";
	cdef->free = QAbstractItemModel_free;
	cdef->reftrace = QAbstractItemModel_reftrace;
	cdef->compareTo = QAbstractItemModel_compareTo;
}


