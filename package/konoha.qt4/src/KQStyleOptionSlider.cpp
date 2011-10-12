//QStyleOptionSlider QStyleOptionSlider.new();
KMETHOD QStyleOptionSlider_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionSlider *ret_v = new KQStyleOptionSlider();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionSlider QStyleOptionSlider.new(QStyleOptionSlider other);
KMETHOD QStyleOptionSlider_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionSlider  other = *RawPtr_to(const QStyleOptionSlider *, sfp[1]);
	KQStyleOptionSlider *ret_v = new KQStyleOptionSlider(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionSlider::DummyQStyleOptionSlider()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionSlider::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionSlider::self = ptr;
	DummyQStyleOptionComplex::setSelf(ptr);
}

bool DummyQStyleOptionSlider::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionComplex::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionSlider::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionSlider::event_map->bigin();
	if ((itr = DummyQStyleOptionSlider::event_map->find(str)) == DummyQStyleOptionSlider::event_map->end()) {
		bool ret;
		ret = DummyQStyleOptionComplex::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionSlider::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionSlider::slot_map->bigin();
	if ((itr = DummyQStyleOptionSlider::event_map->find(str)) == DummyQStyleOptionSlider::slot_map->end()) {
		bool ret;
		ret = DummyQStyleOptionComplex::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQStyleOptionSlider::KQStyleOptionSlider() : QStyleOptionSlider()
{
	self = NULL;
}

KMETHOD QStyleOptionSlider_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionSlider *qp = RawPtr_to(KQStyleOptionSlider *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionSlider]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQStyleOptionSlider::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionSlider]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QStyleOptionSlider_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionSlider *qp = RawPtr_to(KQStyleOptionSlider *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionSlider]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQStyleOptionSlider::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionSlider]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionSlider_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionSlider *qp = (KQStyleOptionSlider *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionSlider_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQStyleOptionSlider *qp = (KQStyleOptionSlider *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionSlider_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQStyleOptionSlider(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionSlider";
	cdef->free = QStyleOptionSlider_free;
	cdef->reftrace = QStyleOptionSlider_reftrace;
	cdef->compareTo = QStyleOptionSlider_compareTo;
}

static knh_IntData_t QStyleOptionSliderConstInt[] = {
	{"Type", QStyleOptionSlider::Type},
	{"Version", QStyleOptionSlider::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionSlider(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionSliderConstInt);
}

