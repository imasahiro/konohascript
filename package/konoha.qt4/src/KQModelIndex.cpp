//QModelIndex QModelIndex.new();
KMETHOD QModelIndex_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQModelIndex *ret_v = new KQModelIndex();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QModelIndex QModelIndex.new(QModelIndex other);
KMETHOD QModelIndex_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QModelIndex  other = *RawPtr_to(const QModelIndex *, sfp[1]);
	KQModelIndex *ret_v = new KQModelIndex(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QModelIndex QModelIndex.child(int row, int column);
KMETHOD QModelIndex_child(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QModelIndex *  qp = RawPtr_to(QModelIndex *, sfp[0]);
	if (qp != NULL) {
		int row = Int_to(int, sfp[1]);
		int column = Int_to(int, sfp[2]);
		QModelIndex ret_v = qp->child(row, column);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QModelIndex.column();
KMETHOD QModelIndex_column(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QModelIndex *  qp = RawPtr_to(QModelIndex *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->column();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QVariant QModelIndex.data(int role);
KMETHOD QModelIndex_data(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QModelIndex *  qp = RawPtr_to(QModelIndex *, sfp[0]);
	if (qp != NULL) {
		int role = Int_to(int, sfp[1]);
		QVariant ret_v = qp->data(role);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QModelIndex.flags();
KMETHOD QModelIndex_flags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QModelIndex *  qp = RawPtr_to(QModelIndex *, sfp[0]);
	if (qp != NULL) {
		Qt::ItemFlags ret_v = qp->flags();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QModelIndex.internalId();
KMETHOD QModelIndex_internalId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QModelIndex *  qp = RawPtr_to(QModelIndex *, sfp[0]);
	if (qp != NULL) {
		qint64 ret_v = qp->internalId();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QModelIndex.internalPointer();
KMETHOD QModelIndex_internalPointer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QModelIndex *  qp = RawPtr_to(QModelIndex *, sfp[0]);
	if (qp != NULL) {
		void* ret_v = qp->internalPointer();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (void*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

////boolean QModelIndex.isValid();
KMETHOD QModelIndex_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QModelIndex *  qp = RawPtr_to(QModelIndex *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QAbstractItemModel QModelIndex.model();
KMETHOD QModelIndex_model(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QModelIndex *  qp = RawPtr_to(QModelIndex *, sfp[0]);
	if (qp != NULL) {
		const QAbstractItemModel* ret_v = qp->model();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractItemModel*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QModelIndex QModelIndex.parent();
KMETHOD QModelIndex_parent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QModelIndex *  qp = RawPtr_to(QModelIndex *, sfp[0]);
	if (qp != NULL) {
		QModelIndex ret_v = qp->parent();
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QModelIndex.row();
KMETHOD QModelIndex_row(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QModelIndex *  qp = RawPtr_to(QModelIndex *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->row();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QModelIndex QModelIndex.sibling(int row, int column);
KMETHOD QModelIndex_sibling(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QModelIndex *  qp = RawPtr_to(QModelIndex *, sfp[0]);
	if (qp != NULL) {
		int row = Int_to(int, sfp[1]);
		int column = Int_to(int, sfp[2]);
		QModelIndex ret_v = qp->sibling(row, column);
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQModelIndex::DummyQModelIndex()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQModelIndex::setSelf(knh_RawPtr_t *ptr)
{
	DummyQModelIndex::self = ptr;
}

bool DummyQModelIndex::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQModelIndex::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQModelIndex::event_map->bigin();
	if ((itr = DummyQModelIndex::event_map->find(str)) == DummyQModelIndex::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQModelIndex::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQModelIndex::slot_map->bigin();
	if ((itr = DummyQModelIndex::event_map->find(str)) == DummyQModelIndex::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQModelIndex::KQModelIndex() : QModelIndex()
{
	self = NULL;
}

KMETHOD QModelIndex_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQModelIndex *qp = RawPtr_to(KQModelIndex *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QModelIndex]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQModelIndex::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QModelIndex]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QModelIndex_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQModelIndex *qp = RawPtr_to(KQModelIndex *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QModelIndex]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQModelIndex::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QModelIndex]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QModelIndex_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQModelIndex *qp = (KQModelIndex *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QModelIndex_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQModelIndex *qp = (KQModelIndex *)p->rawptr;
		(void)qp;
	}
}

static int QModelIndex_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QModelIndex*>(p1->rawptr) == *static_cast<QModelIndex*>(p2->rawptr) ? 0 : 1);
}

DEFAPI(void) defQModelIndex(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QModelIndex";
	cdef->free = QModelIndex_free;
	cdef->reftrace = QModelIndex_reftrace;
	cdef->compareTo = QModelIndex_compareTo;
}


