//@Virtual @Override QVariant QAbstractProxyModel.getData(QModelIndex proxyIndex, int role);
KMETHOD QAbstractProxyModel_getData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractProxyModel *  qp = RawPtr_to(QAbstractProxyModel *, sfp[0]);
	if (qp) {
		const QModelIndex  proxyIndex = *RawPtr_to(const QModelIndex *, sfp[1]);
		int role = Int_to(int, sfp[2]);
		QVariant ret_v = qp->data(proxyIndex, role);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QtItemFlags QAbstractProxyModel.flags(QModelIndex index);
KMETHOD QAbstractProxyModel_flags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractProxyModel *  qp = RawPtr_to(QAbstractProxyModel *, sfp[0]);
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

//@Virtual @Override QVariant QAbstractProxyModel.getHeaderData(int section, int orientation, int role);
KMETHOD QAbstractProxyModel_getHeaderData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractProxyModel *  qp = RawPtr_to(QAbstractProxyModel *, sfp[0]);
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

//@Virtual @Override void QAbstractProxyModel.revert();
KMETHOD QAbstractProxyModel_revert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractProxyModel *  qp = RawPtr_to(QAbstractProxyModel *, sfp[0]);
	if (qp) {
		qp->revert();
	}
	RETURNvoid_();
}

//@Virtual @Override boolean QAbstractProxyModel.setData(QModelIndex index, QVariant value, int role);
KMETHOD QAbstractProxyModel_setData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractProxyModel *  qp = RawPtr_to(QAbstractProxyModel *, sfp[0]);
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

//@Virtual @Override boolean QAbstractProxyModel.setHeaderData(int section, int orientation, QVariant value, int role);
KMETHOD QAbstractProxyModel_setHeaderData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractProxyModel *  qp = RawPtr_to(QAbstractProxyModel *, sfp[0]);
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

//@Virtual @Override boolean QAbstractProxyModel.submit();
KMETHOD QAbstractProxyModel_submit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractProxyModel *  qp = RawPtr_to(QAbstractProxyModel *, sfp[0]);
	if (qp) {
		bool ret_v = qp->submit();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//
//@Virtual QModelIndex QAbstractProxyModel.mapFromSource(QModelIndex sourceIndex);
KMETHOD QAbstractProxyModel_mapFromSource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractProxyModel *  qp = RawPtr_to(QAbstractProxyModel *, sfp[0]);
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

//@Virtual QItemSelection QAbstractProxyModel.mapSelectionFromSource(QItemSelection sourceSelection);
KMETHOD QAbstractProxyModel_mapSelectionFromSource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractProxyModel *  qp = RawPtr_to(QAbstractProxyModel *, sfp[0]);
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

//@Virtual QItemSelection QAbstractProxyModel.mapSelectionToSource(QItemSelection proxySelection);
KMETHOD QAbstractProxyModel_mapSelectionToSource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractProxyModel *  qp = RawPtr_to(QAbstractProxyModel *, sfp[0]);
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

//@Virtual QModelIndex QAbstractProxyModel.mapToSource(QModelIndex proxyIndex);
KMETHOD QAbstractProxyModel_mapToSource(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractProxyModel *  qp = RawPtr_to(QAbstractProxyModel *, sfp[0]);
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

//@Virtual void QAbstractProxyModel.setSourceModel(QAbstractItemModel sourceModel);
KMETHOD QAbstractProxyModel_setSourceModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractProxyModel *  qp = RawPtr_to(QAbstractProxyModel *, sfp[0]);
	if (qp) {
		QAbstractItemModel*  sourceModel = RawPtr_to(QAbstractItemModel*, sfp[1]);
		qp->setSourceModel(sourceModel);
	}
	RETURNvoid_();
}

//QAbstractItemModel QAbstractProxyModel.getSourceModel();
KMETHOD QAbstractProxyModel_getSourceModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractProxyModel *  qp = RawPtr_to(QAbstractProxyModel *, sfp[0]);
	if (qp) {
		QAbstractItemModel* ret_v = qp->sourceModel();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractItemModel*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQAbstractProxyModel::DummyQAbstractProxyModel()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQAbstractProxyModel::~DummyQAbstractProxyModel()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQAbstractProxyModel::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractProxyModel::self = ptr;
	DummyQAbstractItemModel::setSelf(ptr);
}

bool DummyQAbstractProxyModel::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractItemModel::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractProxyModel::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractProxyModel::event_map->bigin();
	if ((itr = DummyQAbstractProxyModel::event_map->find(str)) == DummyQAbstractProxyModel::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemModel::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractProxyModel::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractProxyModel::slot_map->bigin();
	if ((itr = DummyQAbstractProxyModel::slot_map->find(str)) == DummyQAbstractProxyModel::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemModel::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQAbstractProxyModel::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQAbstractProxyModel::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQAbstractItemModel::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQAbstractProxyModel::connection(QObject *o)
{
	QAbstractProxyModel *p = dynamic_cast<QAbstractProxyModel*>(o);
	if (p != NULL) {
	}
	DummyQAbstractItemModel::connection(o);
}

KQAbstractProxyModel::KQAbstractProxyModel(QObject* parent) : QAbstractProxyModel(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQAbstractProxyModel();
	dummy->connection((QObject*)this);
}

KQAbstractProxyModel::~KQAbstractProxyModel()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QAbstractProxyModel_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractProxyModel *qp = RawPtr_to(KQAbstractProxyModel *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractProxyModel]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractProxyModel]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAbstractProxyModel_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractProxyModel *qp = RawPtr_to(KQAbstractProxyModel *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractProxyModel]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractProxyModel]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractProxyModel_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQAbstractProxyModel *qp = (KQAbstractProxyModel *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QAbstractProxyModel*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QAbstractProxyModel_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQAbstractProxyModel *qp = (KQAbstractProxyModel *)p->rawptr;
		KQAbstractProxyModel *qp = static_cast<KQAbstractProxyModel*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAbstractProxyModel_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAbstractProxyModel::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQAbstractProxyModel::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QAbstractProxyModel::event(event);
		return false;
	}
//	QAbstractProxyModel::event(event);
	return true;
}



DEFAPI(void) defQAbstractProxyModel(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractProxyModel";
	cdef->free = QAbstractProxyModel_free;
	cdef->reftrace = QAbstractProxyModel_reftrace;
	cdef->compareTo = QAbstractProxyModel_compareTo;
}


