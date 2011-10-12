
DummyQSysInfo::DummyQSysInfo()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSysInfo::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSysInfo::self = ptr;
}

bool DummyQSysInfo::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQSysInfo::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSysInfo::event_map->bigin();
	if ((itr = DummyQSysInfo::event_map->find(str)) == DummyQSysInfo::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSysInfo::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSysInfo::slot_map->bigin();
	if ((itr = DummyQSysInfo::event_map->find(str)) == DummyQSysInfo::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQSysInfo::KQSysInfo() : QSysInfo()
{
	self = NULL;
}

KMETHOD QSysInfo_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSysInfo *qp = RawPtr_to(KQSysInfo *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSysInfo]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQSysInfo::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSysInfo]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QSysInfo_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSysInfo *qp = RawPtr_to(KQSysInfo *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSysInfo]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQSysInfo::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSysInfo]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSysInfo_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSysInfo *qp = (KQSysInfo *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSysInfo_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQSysInfo *qp = (KQSysInfo *)p->rawptr;
		(void)qp;
	}
}

static int QSysInfo_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQSysInfo(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSysInfo";
	cdef->free = QSysInfo_free;
	cdef->reftrace = QSysInfo_reftrace;
	cdef->compareTo = QSysInfo_compareTo;
}

static knh_IntData_t QSysInfoConstInt[] = {
	{"BigEndian", QSysInfo::BigEndian},
	{"LittleEndian", QSysInfo::LittleEndian},
	{"ByteOrder", QSysInfo::ByteOrder},
	{"WordSize", QSysInfo::WordSize},
	{NULL, 0}
};

DEFAPI(void) constQSysInfo(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QSysInfoConstInt);
}

