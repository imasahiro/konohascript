//@Virtual @Override boolean QAbstractListModel.dropMimeData(QMimeData data, int action, int row, int column, QModelIndex parent);
KMETHOD QAbstractListModel_dropMimeData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractListModel *  qp = RawPtr_to(QAbstractListModel *, sfp[0]);
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

//@Virtual @Override QModelIndex QAbstractListModel.index(int row, int column, QModelIndex parent);
KMETHOD QAbstractListModel_index(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractListModel *  qp = RawPtr_to(QAbstractListModel *, sfp[0]);
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

//

DummyQAbstractListModel::DummyQAbstractListModel()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQAbstractListModel::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractListModel::self = ptr;
	DummyQAbstractItemModel::setSelf(ptr);
}

bool DummyQAbstractListModel::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractItemModel::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractListModel::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractListModel::event_map->bigin();
	if ((itr = DummyQAbstractListModel::event_map->find(str)) == DummyQAbstractListModel::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemModel::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractListModel::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractListModel::slot_map->bigin();
	if ((itr = DummyQAbstractListModel::slot_map->find(str)) == DummyQAbstractListModel::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemModel::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQAbstractListModel::connection(QObject *o)
{
	DummyQAbstractItemModel::connection(o);
}

KQAbstractListModel::KQAbstractListModel(QObject* parent) : QAbstractListModel(parent)
{
	self = NULL;
	dummy = new DummyQAbstractListModel();
	dummy->connection((QObject*)this);
}

KMETHOD QAbstractListModel_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractListModel *qp = RawPtr_to(KQAbstractListModel *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractListModel]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractListModel]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAbstractListModel_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractListModel *qp = RawPtr_to(KQAbstractListModel *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractListModel]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractListModel]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractListModel_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAbstractListModel *qp = (KQAbstractListModel *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAbstractListModel_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQAbstractListModel *qp = (KQAbstractListModel *)p->rawptr;
		(void)qp;
	}
}

static int QAbstractListModel_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAbstractListModel::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQAbstractListModel::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QAbstractListModel::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQAbstractListModel(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractListModel";
	cdef->free = QAbstractListModel_free;
	cdef->reftrace = QAbstractListModel_reftrace;
	cdef->compareTo = QAbstractListModel_compareTo;
}


