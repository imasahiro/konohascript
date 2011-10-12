//QPersistentModelIndex QPersistentModelIndex.new(QModelIndex index);
KMETHOD QPersistentModelIndex_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
	KQPersistentModelIndex *ret_v = new KQPersistentModelIndex(index);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPersistentModelIndex QPersistentModelIndex.new(QPersistentModelIndex other);
KMETHOD QPersistentModelIndex_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPersistentModelIndex  other = *RawPtr_to(const QPersistentModelIndex *, sfp[1]);
	KQPersistentModelIndex *ret_v = new KQPersistentModelIndex(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QModelIndex QPersistentModelIndex.child(int row, int column);
KMETHOD QPersistentModelIndex_child(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPersistentModelIndex *  qp = RawPtr_to(QPersistentModelIndex *, sfp[0]);
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

//int QPersistentModelIndex.column();
KMETHOD QPersistentModelIndex_column(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPersistentModelIndex *  qp = RawPtr_to(QPersistentModelIndex *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->column();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QVariant QPersistentModelIndex.data(int role);
KMETHOD QPersistentModelIndex_data(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPersistentModelIndex *  qp = RawPtr_to(QPersistentModelIndex *, sfp[0]);
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

//int QPersistentModelIndex.flags();
KMETHOD QPersistentModelIndex_flags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPersistentModelIndex *  qp = RawPtr_to(QPersistentModelIndex *, sfp[0]);
	if (qp != NULL) {
		Qt::ItemFlags ret_v = qp->flags();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

////boolean QPersistentModelIndex.isValid();
KMETHOD QPersistentModelIndex_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPersistentModelIndex *  qp = RawPtr_to(QPersistentModelIndex *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QAbstractItemModel QPersistentModelIndex.model();
KMETHOD QPersistentModelIndex_model(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPersistentModelIndex *  qp = RawPtr_to(QPersistentModelIndex *, sfp[0]);
	if (qp != NULL) {
		const QAbstractItemModel* ret_v = qp->model();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractItemModel*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QModelIndex QPersistentModelIndex.parent();
KMETHOD QPersistentModelIndex_parent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPersistentModelIndex *  qp = RawPtr_to(QPersistentModelIndex *, sfp[0]);
	if (qp != NULL) {
		QModelIndex ret_v = qp->parent();
		QModelIndex *ret_v_ = new QModelIndex(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QPersistentModelIndex.row();
KMETHOD QPersistentModelIndex_row(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPersistentModelIndex *  qp = RawPtr_to(QPersistentModelIndex *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->row();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QModelIndex QPersistentModelIndex.sibling(int row, int column);
KMETHOD QPersistentModelIndex_sibling(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPersistentModelIndex *  qp = RawPtr_to(QPersistentModelIndex *, sfp[0]);
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


DummyQPersistentModelIndex::DummyQPersistentModelIndex()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPersistentModelIndex::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPersistentModelIndex::self = ptr;
}

bool DummyQPersistentModelIndex::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQPersistentModelIndex::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPersistentModelIndex::event_map->bigin();
	if ((itr = DummyQPersistentModelIndex::event_map->find(str)) == DummyQPersistentModelIndex::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPersistentModelIndex::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPersistentModelIndex::slot_map->bigin();
	if ((itr = DummyQPersistentModelIndex::event_map->find(str)) == DummyQPersistentModelIndex::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQPersistentModelIndex::KQPersistentModelIndex(const QModelIndex index) : QPersistentModelIndex(index)
{
	self = NULL;
}

KMETHOD QPersistentModelIndex_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPersistentModelIndex *qp = RawPtr_to(KQPersistentModelIndex *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPersistentModelIndex]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQPersistentModelIndex::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPersistentModelIndex]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QPersistentModelIndex_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPersistentModelIndex *qp = RawPtr_to(KQPersistentModelIndex *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPersistentModelIndex]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQPersistentModelIndex::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPersistentModelIndex]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPersistentModelIndex_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPersistentModelIndex *qp = (KQPersistentModelIndex *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPersistentModelIndex_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQPersistentModelIndex *qp = (KQPersistentModelIndex *)p->rawptr;
		(void)qp;
	}
}

static int QPersistentModelIndex_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QPersistentModelIndex*>(p1->rawptr) == *static_cast<QPersistentModelIndex*>(p2->rawptr) ? 0 : 1);
}

DEFAPI(void) defQPersistentModelIndex(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPersistentModelIndex";
	cdef->free = QPersistentModelIndex_free;
	cdef->reftrace = QPersistentModelIndex_reftrace;
	cdef->compareTo = QPersistentModelIndex_compareTo;
}


