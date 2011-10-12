//QStyleHintReturn QStyleHintReturn.new(int version, int type);
KMETHOD QStyleHintReturn_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int version = Int_to(int, sfp[1]);
	int type = Int_to(int, sfp[2]);
	KQStyleHintReturn *ret_v = new KQStyleHintReturn(version, type);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}


DummyQStyleHintReturn::DummyQStyleHintReturn()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleHintReturn::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleHintReturn::self = ptr;
}

bool DummyQStyleHintReturn::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQStyleHintReturn::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleHintReturn::event_map->bigin();
	if ((itr = DummyQStyleHintReturn::event_map->find(str)) == DummyQStyleHintReturn::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleHintReturn::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleHintReturn::slot_map->bigin();
	if ((itr = DummyQStyleHintReturn::event_map->find(str)) == DummyQStyleHintReturn::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQStyleHintReturn::KQStyleHintReturn(int version, int type) : QStyleHintReturn(version, type)
{
	self = NULL;
}

KMETHOD QStyleHintReturn_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleHintReturn *qp = RawPtr_to(KQStyleHintReturn *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleHintReturn]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQStyleHintReturn::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleHintReturn]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QStyleHintReturn_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleHintReturn *qp = RawPtr_to(KQStyleHintReturn *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleHintReturn]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQStyleHintReturn::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleHintReturn]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleHintReturn_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleHintReturn *qp = (KQStyleHintReturn *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleHintReturn_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQStyleHintReturn *qp = (KQStyleHintReturn *)p->rawptr;
		(void)qp;
	}
}

static int QStyleHintReturn_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQStyleHintReturn(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleHintReturn";
	cdef->free = QStyleHintReturn_free;
	cdef->reftrace = QStyleHintReturn_reftrace;
	cdef->compareTo = QStyleHintReturn_compareTo;
}

static knh_IntData_t QStyleHintReturnConstInt[] = {
	{"SH_Default", QStyleHintReturn::SH_Default},
	{"SH_Mask", QStyleHintReturn::SH_Mask},
	{"SH_Variant", QStyleHintReturn::SH_Variant},
	{"Type", QStyleHintReturn::Type},
	{"Version", QStyleHintReturn::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleHintReturn(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleHintReturnConstInt);
}

