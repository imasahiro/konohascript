//QStyleOptionSizeGrip QStyleOptionSizeGrip.new();
KMETHOD QStyleOptionSizeGrip_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionSizeGrip *ret_v = new KQStyleOptionSizeGrip();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionSizeGrip QStyleOptionSizeGrip.new(QStyleOptionSizeGrip other);
KMETHOD QStyleOptionSizeGrip_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionSizeGrip  other = *RawPtr_to(const QStyleOptionSizeGrip *, sfp[1]);
	KQStyleOptionSizeGrip *ret_v = new KQStyleOptionSizeGrip(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionSizeGrip::DummyQStyleOptionSizeGrip()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionSizeGrip::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionSizeGrip::self = ptr;
	DummyQStyleOptionComplex::setSelf(ptr);
}

bool DummyQStyleOptionSizeGrip::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionComplex::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionSizeGrip::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionSizeGrip::event_map->bigin();
	if ((itr = DummyQStyleOptionSizeGrip::event_map->find(str)) == DummyQStyleOptionSizeGrip::event_map->end()) {
		bool ret;
		ret = DummyQStyleOptionComplex::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionSizeGrip::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionSizeGrip::slot_map->bigin();
	if ((itr = DummyQStyleOptionSizeGrip::event_map->find(str)) == DummyQStyleOptionSizeGrip::slot_map->end()) {
		bool ret;
		ret = DummyQStyleOptionComplex::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQStyleOptionSizeGrip::KQStyleOptionSizeGrip() : QStyleOptionSizeGrip()
{
	self = NULL;
}

KMETHOD QStyleOptionSizeGrip_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionSizeGrip *qp = RawPtr_to(KQStyleOptionSizeGrip *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionSizeGrip]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQStyleOptionSizeGrip::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionSizeGrip]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QStyleOptionSizeGrip_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionSizeGrip *qp = RawPtr_to(KQStyleOptionSizeGrip *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionSizeGrip]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQStyleOptionSizeGrip::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionSizeGrip]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionSizeGrip_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionSizeGrip *qp = (KQStyleOptionSizeGrip *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionSizeGrip_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQStyleOptionSizeGrip *qp = (KQStyleOptionSizeGrip *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionSizeGrip_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQStyleOptionSizeGrip(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionSizeGrip";
	cdef->free = QStyleOptionSizeGrip_free;
	cdef->reftrace = QStyleOptionSizeGrip_reftrace;
	cdef->compareTo = QStyleOptionSizeGrip_compareTo;
}

static knh_IntData_t QStyleOptionSizeGripConstInt[] = {
	{"Type", QStyleOptionSizeGrip::Type},
	{"Version", QStyleOptionSizeGrip::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionSizeGrip(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionSizeGripConstInt);
}

