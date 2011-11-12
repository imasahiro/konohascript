//@Virtual @Override boolean QAbstractTableModel.dropMimeData(QMimeData data, int action, int row, int column, QModelIndex parent);
KMETHOD QAbstractTableModel_dropMimeData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTableModel *  qp = RawPtr_to(QAbstractTableModel *, sfp[0]);
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

//@Virtual @Override QModelIndex QAbstractTableModel.index(int row, int column, QModelIndex parent);
KMETHOD QAbstractTableModel_index(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTableModel *  qp = RawPtr_to(QAbstractTableModel *, sfp[0]);
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

//

DummyQAbstractTableModel::DummyQAbstractTableModel()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQAbstractTableModel::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractTableModel::self = ptr;
	DummyQAbstractItemModel::setSelf(ptr);
}

bool DummyQAbstractTableModel::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractItemModel::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractTableModel::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractTableModel::event_map->bigin();
	if ((itr = DummyQAbstractTableModel::event_map->find(str)) == DummyQAbstractTableModel::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemModel::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractTableModel::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractTableModel::slot_map->bigin();
	if ((itr = DummyQAbstractTableModel::slot_map->find(str)) == DummyQAbstractTableModel::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractItemModel::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQAbstractTableModel::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQAbstractTableModel::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQAbstractItemModel::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQAbstractTableModel::connection(QObject *o)
{
	QAbstractTableModel *p = dynamic_cast<QAbstractTableModel*>(o);
	if (p != NULL) {
	}
	DummyQAbstractItemModel::connection(o);
}

KQAbstractTableModel::KQAbstractTableModel(QObject* parent) : QAbstractTableModel(parent)
{
	self = NULL;
	dummy = new DummyQAbstractTableModel();
	dummy->connection((QObject*)this);
}

KMETHOD QAbstractTableModel_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractTableModel *qp = RawPtr_to(KQAbstractTableModel *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractTableModel]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractTableModel]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAbstractTableModel_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractTableModel *qp = RawPtr_to(KQAbstractTableModel *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractTableModel]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractTableModel]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractTableModel_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAbstractTableModel *qp = (KQAbstractTableModel *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAbstractTableModel_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQAbstractTableModel *qp = (KQAbstractTableModel *)p->rawptr;
//		KQAbstractTableModel *qp = static_cast<KQAbstractTableModel*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAbstractTableModel_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAbstractTableModel::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQAbstractTableModel::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QAbstractTableModel::event(event);
		return false;
	}
//	QAbstractTableModel::event(event);
	return true;
}



DEFAPI(void) defQAbstractTableModel(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractTableModel";
	cdef->free = QAbstractTableModel_free;
	cdef->reftrace = QAbstractTableModel_reftrace;
	cdef->compareTo = QAbstractTableModel_compareTo;
}


