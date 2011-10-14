//@Virtual @Override int QDirModel.columnCount(QModelIndex parent);
KMETHOD QDirModel_columnCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		int ret_v = qp->columnCount(parent);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QVariant QDirModel.getData(QModelIndex index, int role);
KMETHOD QDirModel_getData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
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

//@Virtual @Override boolean QDirModel.dropMimeData(QMimeData data, int action, int row, int column, QModelIndex parent);
KMETHOD QDirModel_dropMimeData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
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

//@Virtual @Override int QDirModel.flags(QModelIndex index);
KMETHOD QDirModel_flags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		Qt::ItemFlags ret_v = qp->flags(index);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override boolean QDirModel.hasChildren(QModelIndex parent);
KMETHOD QDirModel_hasChildren(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		bool ret_v = qp->hasChildren(parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QVariant QDirModel.headerData(int section, int orientation, int role);
KMETHOD QDirModel_headerData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
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

//@Virtual @Override QModelIndex QDirModel.index(int row, int column, QModelIndex parent);
KMETHOD QDirModel_index(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
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

//@Virtual @Override QMimeData QDirModel.mimeData(QModelIndexList indexes);
KMETHOD QDirModel_mimeData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndexList  indexes = *RawPtr_to(const QModelIndexList *, sfp[1]);
		QMimeData* ret_v = qp->mimeData(indexes);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMimeData*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QModelIndex QDirModel.parent(QModelIndex child);
KMETHOD QDirModel_parent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
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

//@Virtual @Override int QDirModel.rowCount(QModelIndex parent);
KMETHOD QDirModel_rowCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		int ret_v = qp->rowCount(parent);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override boolean QDirModel.setData(QModelIndex index, QVariant value, int role);
KMETHOD QDirModel_setData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
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

//@Virtual @Override void QDirModel.sort(int column, int order);
KMETHOD QDirModel_sort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		int column = Int_to(int, sfp[1]);
		Qt::SortOrder order = Int_to(Qt::SortOrder, sfp[2]);
		qp->sort(column, order);
	}
	RETURNvoid_();
}

//@Virtual @Override int QDirModel.supportedDropActions();
KMETHOD QDirModel_supportedDropActions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		Qt::DropActions ret_v = qp->supportedDropActions();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QDirModel QDirModel.new(QObject parent);
KMETHOD QDirModel_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQDirModel *ret_v = new KQDirModel(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QIcon QDirModel.fileIcon(QModelIndex index);
KMETHOD QDirModel_fileIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QIcon ret_v = qp->fileIcon(index);
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QDirModel.fileName(QModelIndex index);
KMETHOD QDirModel_fileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QString ret_v = qp->fileName(index);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QDirModel.filePath(QModelIndex index);
KMETHOD QDirModel_filePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		QString ret_v = qp->filePath(index);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDirModel.getFilter();
KMETHOD QDirModel_getFilter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		QDir::Filters ret_v = qp->filter();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//QModelIndex QDirModel.index(String path, int column);
KMETHOD QDirModel_index(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		const QString path = String_to(const QString, sfp[1]);
		int column = Int_to(int, sfp[2]);
		QModelIndex ret_v = qp->index(path, column);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//boolean QDirModel.isDir(QModelIndex index);
KMETHOD QDirModel_isDir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		bool ret_v = qp->isDir(index);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDirModel.isReadOnly();
KMETHOD QDirModel_isReadOnly(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isReadOnly();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDirModel.getLazyChildCount();
KMETHOD QDirModel_getLazyChildCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->lazyChildCount();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QModelIndex QDirModel.mkdir(QModelIndex parent, String name);
KMETHOD QDirModel_mkdir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		const QString name = String_to(const QString, sfp[2]);
		QModelIndex ret_v = qp->mkdir(parent, name);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QDirModel.remove(QModelIndex index);
KMETHOD QDirModel_remove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		bool ret_v = qp->remove(index);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDirModel.getResolveSymlinks();
KMETHOD QDirModel_getResolveSymlinks(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->resolveSymlinks();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDirModel.rmdir(QModelIndex index);
KMETHOD QDirModel_rmdir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
		bool ret_v = qp->rmdir(index);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QDirModel.setFilter(int filters);
KMETHOD QDirModel_setFilter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		QDir::Filters filters = Int_to(QDir::Filters, sfp[1]);
		qp->setFilter(filters);
	}
	RETURNvoid_();
}

//void QDirModel.setLazyChildCount(boolean enable);
KMETHOD QDirModel_setLazyChildCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setLazyChildCount(enable);
	}
	RETURNvoid_();
}

//void QDirModel.setReadOnly(boolean enable);
KMETHOD QDirModel_setReadOnly(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setReadOnly(enable);
	}
	RETURNvoid_();
}

//void QDirModel.setResolveSymlinks(boolean enable);
KMETHOD QDirModel_setResolveSymlinks(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setResolveSymlinks(enable);
	}
	RETURNvoid_();
}

//void QDirModel.setSorting(int sort);
KMETHOD QDirModel_setSorting(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		QDir::SortFlags sort = Int_to(QDir::SortFlags, sfp[1]);
		qp->setSorting(sort);
	}
	RETURNvoid_();
}

//int QDirModel.getSorting();
KMETHOD QDirModel_getSorting(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		QDir::SortFlags ret_v = qp->sorting();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QDirModel.refresh(QModelIndex parent);
KMETHOD QDirModel_refresh(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDirModel *  qp = RawPtr_to(QDirModel *, sfp[0]);
	if (qp != NULL) {
		const QModelIndex  parent = *RawPtr_to(const QModelIndex *, sfp[1]);
		qp->refresh(parent);
	}
	RETURNvoid_();
}


DummyQDirModel::DummyQDirModel()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQDirModel::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDirModel::self = ptr;
	DummyQAbstractItemModel::setSelf(ptr);
}

bool DummyQDirModel::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractItemModel::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQDirModel::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDirModel::event_map->bigin();
	if ((itr = DummyQDirModel::event_map->find(str)) == DummyQDirModel::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemModel::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDirModel::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDirModel::slot_map->bigin();
	if ((itr = DummyQDirModel::slot_map->find(str)) == DummyQDirModel::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemModel::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQDirModel::connection(QObject *o)
{
	DummyQAbstractItemModel::connection(o);
}

KQDirModel::KQDirModel(QObject* parent) : QDirModel(parent)
{
	self = NULL;
	dummy = new DummyQDirModel();
	dummy->connection((QObject*)this);
}

KMETHOD QDirModel_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDirModel *qp = RawPtr_to(KQDirModel *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDirModel]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDirModel]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QDirModel_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDirModel *qp = RawPtr_to(KQDirModel *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDirModel]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDirModel]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDirModel_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDirModel *qp = (KQDirModel *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDirModel_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQDirModel *qp = (KQDirModel *)p->rawptr;
		(void)qp;
	}
}

static int QDirModel_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQDirModel::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQDirModel::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QDirModel::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQDirModel(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDirModel";
	cdef->free = QDirModel_free;
	cdef->reftrace = QDirModel_reftrace;
	cdef->compareTo = QDirModel_compareTo;
}

static knh_IntData_t QDirModelConstInt[] = {
	{"FileIconRole", QDirModel::FileIconRole},
	{"FilePathRole", QDirModel::FilePathRole},
	{"FileNameRole", QDirModel::FileNameRole},
	{NULL, 0}
};

DEFAPI(void) constQDirModel(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QDirModelConstInt);
}

