//QSharedData QSharedData.new();
KMETHOD QSharedData_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSharedData *ret_v = new KQSharedData();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QSharedData QSharedData.new(QSharedData other);
KMETHOD QSharedData_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QSharedData  other = *RawPtr_to(const QSharedData *, sfp[1]);
	KQSharedData *ret_v = new KQSharedData(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//Array<String> QSharedData.parents();
KMETHOD QSharedData_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSharedData *qp = RawPtr_to(QSharedData*, sfp[0]);
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

DummyQSharedData::DummyQSharedData()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQSharedData::~DummyQSharedData()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQSharedData::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSharedData::self = ptr;
}

bool DummyQSharedData::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQSharedData::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSharedData::event_map->bigin();
	if ((itr = DummyQSharedData::event_map->find(str)) == DummyQSharedData::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSharedData::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSharedData::slot_map->bigin();
	if ((itr = DummyQSharedData::slot_map->find(str)) == DummyQSharedData::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQSharedData::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQSharedData::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQSharedData::connection(QObject *o)
{
	QSharedData *p = dynamic_cast<QSharedData*>(o);
	if (p != NULL) {
	}
}

KQSharedData::KQSharedData() : QSharedData()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQSharedData();
}

KQSharedData::~KQSharedData()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QSharedData_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSharedData *qp = RawPtr_to(KQSharedData *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSharedData]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSharedData]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSharedData_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSharedData *qp = RawPtr_to(KQSharedData *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSharedData]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSharedData]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSharedData_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQSharedData *qp = (KQSharedData *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QSharedData*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QSharedData_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQSharedData *qp = (KQSharedData *)p->rawptr;
		KQSharedData *qp = static_cast<KQSharedData*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSharedData_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSharedData::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQSharedData(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSharedData";
	cdef->free = QSharedData_free;
	cdef->reftrace = QSharedData_reftrace;
	cdef->compareTo = QSharedData_compareTo;
}


