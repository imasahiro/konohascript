//@Virtual @Override int QProxyModel.columnCount(QModelIndex parent);
KMETHOD QProxyModel_columnCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		int ret_v = qp->columnCount(parent);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QVariant QProxyModel.getData(QModelIndex index, int role);
KMETHOD QProxyModel_getData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
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

//@Virtual @Override boolean QProxyModel.dropMimeData(QMimeData data, int action, int row, int column, QModelIndex parent);
KMETHOD QProxyModel_dropMimeData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
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

//@Virtual @Override void QProxyModel.fetchMore(QModelIndex parent);
KMETHOD QProxyModel_fetchMore(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->fetchMore(parent);
	}
	RETURNvoid_();
}

//@Virtual @Override int QProxyModel.flags(QModelIndex index);
KMETHOD QProxyModel_flags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		Qt::ItemFlags ret_v = qp->flags(index);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override boolean QProxyModel.hasChildren(QModelIndex parent);
KMETHOD QProxyModel_hasChildren(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		bool ret_v = qp->hasChildren(parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QVariant QProxyModel.getHeaderData(int section, int orientation, int role);
KMETHOD QProxyModel_getHeaderData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
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

//@Virtual @Override QModelIndex QProxyModel.index(int row, int column, QModelIndex parent);
KMETHOD QProxyModel_index(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
	if (qp != NULL) {
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

////@Virtual @Override boolean QProxyModel.insertColumns(int column, int count, QModelIndex parent);
KMETHOD QProxyModel_insertColumns(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
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

////@Virtual @Override boolean QProxyModel.insertRows(int row, int count, QModelIndex parent);
KMETHOD QProxyModel_insertRows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
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

//@Virtual @Override QModelIndexList QProxyModel.match(QModelIndex start, int role, QVariant value, int hits, int flags);
KMETHOD QProxyModel_match(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
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

//@Virtual @Override QMimeData QProxyModel.mimeData(QModelIndexList indexes);
KMETHOD QProxyModel_mimeData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndexList  indexes = *RawPtr_to(const QModelIndexList *, sfp[1]);
		QMimeData* ret_v = qp->mimeData(indexes);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMimeData*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QModelIndex QProxyModel.parent(QModelIndex child);
KMETHOD QProxyModel_parent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  child = *RawPtr_to(const QModelIndex *, sfp[1]);
		QModelIndex ret_v = qp->parent(child);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QProxyModel.revert();
KMETHOD QProxyModel_revert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
	if (qp != NULL) {
		qp->revert();
	}
	RETURNvoid_();
}

//@Virtual @Override int QProxyModel.rowCount(QModelIndex parent);
KMETHOD QProxyModel_rowCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		int ret_v = qp->rowCount(parent);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override boolean QProxyModel.setData(QModelIndex index, QVariant value, int role);
KMETHOD QProxyModel_setData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
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

//@Virtual @Override boolean QProxyModel.setHeaderData(int section, int orientation, QVariant value, int role);
KMETHOD QProxyModel_setHeaderData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
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

//@Virtual @Override void QProxyModel.sort(int column, int order);
KMETHOD QProxyModel_sort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
	if (qp != NULL) {
		int column = Int_to(int, sfp[1]);
		Qt::SortOrder order = Int_to(Qt::SortOrder, sfp[2]);
		qp->sort(column, order);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QProxyModel.span(QModelIndex index);
KMETHOD QProxyModel_span(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
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

//@Virtual @Override boolean QProxyModel.submit();
KMETHOD QProxyModel_submit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->submit();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override int QProxyModel.supportedDropActions();
KMETHOD QProxyModel_supportedDropActions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
	if (qp != NULL) {
		Qt::DropActions ret_v = qp->supportedDropActions();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QProxyModel QProxyModel.new(QObject parent);
KMETHOD QProxyModel_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQProxyModel *ret_v = new KQProxyModel(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QAbstractItemModel QProxyModel.getModel();
KMETHOD QProxyModel_getModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemModel* ret_v = qp->model();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractItemModel*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QProxyModel.setModel(QAbstractItemModel model);
KMETHOD QProxyModel_setModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyModel *  qp = RawPtr_to(QProxyModel *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemModel*  model = RawPtr_to(QAbstractItemModel*, sfp[1]);
		qp->setModel(model);
	}
	RETURNvoid_();
}


DummyQProxyModel::DummyQProxyModel()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQProxyModel::setSelf(knh_RawPtr_t *ptr)
{
	DummyQProxyModel::self = ptr;
	DummyQAbstractItemModel::setSelf(ptr);
}

bool DummyQProxyModel::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractItemModel::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQProxyModel::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQProxyModel::event_map->bigin();
	if ((itr = DummyQProxyModel::event_map->find(str)) == DummyQProxyModel::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemModel::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQProxyModel::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQProxyModel::slot_map->bigin();
	if ((itr = DummyQProxyModel::slot_map->find(str)) == DummyQProxyModel::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemModel::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQProxyModel::connection(QObject *o)
{
	DummyQAbstractItemModel::connection(o);
}

KQProxyModel::KQProxyModel(QObject* parent) : QProxyModel(parent)
{
	self = NULL;
	dummy = new DummyQProxyModel();
	dummy->connection((QObject*)this);
}

KMETHOD QProxyModel_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQProxyModel *qp = RawPtr_to(KQProxyModel *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QProxyModel]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QProxyModel]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QProxyModel_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQProxyModel *qp = RawPtr_to(KQProxyModel *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QProxyModel]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QProxyModel]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QProxyModel_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQProxyModel *qp = (KQProxyModel *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QProxyModel_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQProxyModel *qp = (KQProxyModel *)p->rawptr;
		(void)qp;
	}
}

static int QProxyModel_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQProxyModel::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQProxyModel::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QProxyModel::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQProxyModel(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QProxyModel";
	cdef->free = QProxyModel_free;
	cdef->reftrace = QProxyModel_reftrace;
	cdef->compareTo = QProxyModel_compareTo;
}


