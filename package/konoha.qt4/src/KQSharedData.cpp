//QSharedData QSharedData.new();
KMETHOD QSharedData_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSharedData *ret_v = new KQSharedData();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
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
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQSharedData::DummyQSharedData()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
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
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSharedData::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSharedData::slot_map->bigin();
	if ((itr = DummyQSharedData::event_map->find(str)) == DummyQSharedData::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQSharedData::KQSharedData() : QSharedData()
{
	self = NULL;
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
		if (!qp->DummyQSharedData::addEvent(callback_func, str)) {
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
		if (!qp->DummyQSharedData::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSharedData]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSharedData_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSharedData *qp = (KQSharedData *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSharedData_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQSharedData *qp = (KQSharedData *)p->rawptr;
		(void)qp;
	}
}

static int QSharedData_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQSharedData(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSharedData";
	cdef->free = QSharedData_free;
	cdef->reftrace = QSharedData_reftrace;
	cdef->compareTo = QSharedData_compareTo;
}


