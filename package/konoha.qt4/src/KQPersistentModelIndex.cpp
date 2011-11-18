//QPersistentModelIndex QPersistentModelIndex.new(QModelIndex index);
KMETHOD QPersistentModelIndex_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QModelIndex  index = *RawPtr_to(const QModelIndex *, sfp[1]);
	KQPersistentModelIndex *ret_v = new KQPersistentModelIndex(index);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
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
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QModelIndex QPersistentModelIndex.child(int row, int column);
KMETHOD QPersistentModelIndex_child(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPersistentModelIndex *  qp = RawPtr_to(QPersistentModelIndex *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		int role = Int_to(int, sfp[1]);
		QVariant ret_v = qp->data(role);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QtItemFlags QPersistentModelIndex.flags();
KMETHOD QPersistentModelIndex_flags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPersistentModelIndex *  qp = RawPtr_to(QPersistentModelIndex *, sfp[0]);
	if (qp) {
		Qt::ItemFlags ret_v = qp->flags();
		Qt::ItemFlags *ret_v_ = new Qt::ItemFlags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAbstractItemModel QPersistentModelIndex.model();
KMETHOD QPersistentModelIndex_model(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPersistentModelIndex *  qp = RawPtr_to(QPersistentModelIndex *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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

//Array<String> QPersistentModelIndex.parents();
KMETHOD QPersistentModelIndex_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPersistentModelIndex *qp = RawPtr_to(QPersistentModelIndex*, sfp[0]);
	if (qp != NULL) {
		int size = 10;
		knh_Array_t *a = new_Array0(ctx, size);
		const knh_ClassTBL_t *ct = sfp[0].p->h.cTBL;
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}

DummyQPersistentModelIndex::DummyQPersistentModelIndex()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQPersistentModelIndex::~DummyQPersistentModelIndex()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPersistentModelIndex::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPersistentModelIndex::slot_map->bigin();
	if ((itr = DummyQPersistentModelIndex::slot_map->find(str)) == DummyQPersistentModelIndex::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQPersistentModelIndex::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQPersistentModelIndex::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQPersistentModelIndex::connection(QObject *o)
{
	QPersistentModelIndex *p = dynamic_cast<QPersistentModelIndex*>(o);
	if (p != NULL) {
	}
}

KQPersistentModelIndex::KQPersistentModelIndex(const QModelIndex index) : QPersistentModelIndex(index)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQPersistentModelIndex();
}

KQPersistentModelIndex::~KQPersistentModelIndex()
{
	delete dummy;
	dummy = NULL;
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPersistentModelIndex]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPersistentModelIndex_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQPersistentModelIndex *qp = (KQPersistentModelIndex *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QPersistentModelIndex*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QPersistentModelIndex_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQPersistentModelIndex *qp = (KQPersistentModelIndex *)p->rawptr;
		KQPersistentModelIndex *qp = static_cast<KQPersistentModelIndex*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPersistentModelIndex_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QPersistentModelIndex*>(p1->rawptr) == *static_cast<QPersistentModelIndex*>(p2->rawptr) ? 0 : 1);
}

void KQPersistentModelIndex::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQPersistentModelIndex(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPersistentModelIndex";
	cdef->free = QPersistentModelIndex_free;
	cdef->reftrace = QPersistentModelIndex_reftrace;
	cdef->compareTo = QPersistentModelIndex_compareTo;
}


