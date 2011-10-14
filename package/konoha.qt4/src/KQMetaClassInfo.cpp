//String QMetaClassInfo.name();
KMETHOD QMetaClassInfo_name(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaClassInfo *  qp = RawPtr_to(QMetaClassInfo *, sfp[0]);
	if (qp != NULL) {
		const char* ret_v = qp->name();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (char*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QMetaClassInfo.value();
KMETHOD QMetaClassInfo_value(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaClassInfo *  qp = RawPtr_to(QMetaClassInfo *, sfp[0]);
	if (qp != NULL) {
		const char* ret_v = qp->value();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (char*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQMetaClassInfo::DummyQMetaClassInfo()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQMetaClassInfo::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMetaClassInfo::self = ptr;
}

bool DummyQMetaClassInfo::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQMetaClassInfo::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMetaClassInfo::event_map->bigin();
	if ((itr = DummyQMetaClassInfo::event_map->find(str)) == DummyQMetaClassInfo::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMetaClassInfo::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMetaClassInfo::slot_map->bigin();
	if ((itr = DummyQMetaClassInfo::slot_map->find(str)) == DummyQMetaClassInfo::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQMetaClassInfo::connection(QObject *o)
{
	return;
}

KQMetaClassInfo::KQMetaClassInfo() : QMetaClassInfo()
{
	self = NULL;
	dummy = new DummyQMetaClassInfo();
	dummy->connection((QObject*)this);
}

KMETHOD QMetaClassInfo_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMetaClassInfo *qp = RawPtr_to(KQMetaClassInfo *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMetaClassInfo]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMetaClassInfo]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QMetaClassInfo_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMetaClassInfo *qp = RawPtr_to(KQMetaClassInfo *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMetaClassInfo]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMetaClassInfo]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMetaClassInfo_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMetaClassInfo *qp = (KQMetaClassInfo *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMetaClassInfo_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQMetaClassInfo *qp = (KQMetaClassInfo *)p->rawptr;
		(void)qp;
	}
}

static int QMetaClassInfo_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMetaClassInfo::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQMetaClassInfo(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMetaClassInfo";
	cdef->free = QMetaClassInfo_free;
	cdef->reftrace = QMetaClassInfo_reftrace;
	cdef->compareTo = QMetaClassInfo_compareTo;
}


