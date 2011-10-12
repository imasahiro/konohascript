//
//@Virtual QModelIndex QAbstractItemModel.buddy(QModelIndex index);
KMETHOD QAbstractItemModel_buddy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->fetchMore(parent);
	}
	RETURNvoid_();
}

//@Virtual int QAbstractItemModel.flags(QModelIndex index);
KMETHOD QAbstractItemModel_flags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		Qt::ItemFlags ret_v = qp->flags(index);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual boolean QAbstractItemModel.hasChildren(QModelIndex parent);
KMETHOD QAbstractItemModel_hasChildren(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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

////boolean QAbstractItemModel.insertColumn(int column, QModelIndex parent);
KMETHOD QAbstractItemModel_insertColumn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp != NULL) {
		int column = Int_to(int, sfp[1]);
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[2]);
		bool ret_v = qp->insertColumn(column, parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

////@Virtual boolean QAbstractItemModel.insertColumns(int column, int count, QModelIndex parent);
KMETHOD QAbstractItemModel_insertColumns(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp != NULL) {
		int column = Int_to(int, sfp[1]);
		int count = Int_to(int, sfp[2]);
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[3]);
		bool ret_v = qp->insertColumns(column, count, parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

////boolean QAbstractItemModel.insertRow(int row, QModelIndex parent);
KMETHOD QAbstractItemModel_insertRow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp != NULL) {
		int row = Int_to(int, sfp[1]);
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[2]);
		bool ret_v = qp->insertRow(row, parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

////@Virtual boolean QAbstractItemModel.insertRows(int row, int count, QModelIndex parent);
KMETHOD QAbstractItemModel_insertRows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp != NULL) {
		int row = Int_to(int, sfp[1]);
		int count = Int_to(int, sfp[2]);
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[3]);
		bool ret_v = qp->insertRows(row, count, parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual QModelIndexList QAbstractItemModel.match(QModelIndex start, int role, QVariant value, int hits, int flags);
KMETHOD QAbstractItemModel_match(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  start = *RawPtr_to(const QModelIndex *, sfp[1]);
		int role = Int_to(int, sfp[2]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[3]);
		int hits = Int_to(int, sfp[4]);
		Qt::MatchFlags flags = Int_to(Qt::MatchFlags, sfp[5]);
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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

//void QAbstractItemModel.setSupportedDragActions(int actions);
KMETHOD QAbstractItemModel_setSupportedDragActions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp != NULL) {
		Qt::DropActions actions = Int_to(Qt::DropActions, sfp[1]);
		qp->setSupportedDragActions(actions);
	}
	RETURNvoid_();
}

//QModelIndex QAbstractItemModel.sibling(int row, int column, QModelIndex index);
KMETHOD QAbstractItemModel_sibling(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QSize ret_v = qp->span(index);
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QAbstractItemModel.getSupportedDragActions();
KMETHOD QAbstractItemModel_getSupportedDragActions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp != NULL) {
		Qt::DropActions ret_v = qp->supportedDragActions();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual int QAbstractItemModel.supportedDropActions();
KMETHOD QAbstractItemModel_supportedDropActions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp != NULL) {
		Qt::DropActions ret_v = qp->supportedDropActions();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual void QAbstractItemModel.revert();
KMETHOD QAbstractItemModel_revert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp != NULL) {
		qp->revert();
	}
	RETURNvoid_();
}

//@Virtual boolean QAbstractItemModel.submit();
KMETHOD QAbstractItemModel_submit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractItemModel *  qp = RawPtr_to(QAbstractItemModel *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->submit();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQAbstractItemModel::DummyQAbstractItemModel()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
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

bool DummyQAbstractItemModel::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractItemModel::event_map->bigin();
	if ((itr = DummyQAbstractItemModel::event_map->find(str)) == DummyQAbstractItemModel::event_map->end()) {
		bool ret;
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
	if ((itr = DummyQAbstractItemModel::event_map->find(str)) == DummyQAbstractItemModel::slot_map->end()) {
		bool ret;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQAbstractItemModel::KQAbstractItemModel(QObject* parent) : QAbstractItemModel(parent)
{
	self = NULL;
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
		if (!qp->DummyQAbstractItemModel::addEvent(callback_func, str)) {
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
		if (!qp->DummyQAbstractItemModel::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractItemModel]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractItemModel_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAbstractItemModel *qp = (KQAbstractItemModel *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAbstractItemModel_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQAbstractItemModel *qp = (KQAbstractItemModel *)p->rawptr;
		(void)qp;
	}
}

static int QAbstractItemModel_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQAbstractItemModel::event(QEvent *event)
{
	if (!DummyQAbstractItemModel::eventDispatcher(event)) {
		QAbstractItemModel::event(event);
		return false;
	}
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


