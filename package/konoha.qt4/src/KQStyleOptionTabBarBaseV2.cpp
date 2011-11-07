//QStyleOptionTabBarBaseV2 QStyleOptionTabBarBaseV2.new();
KMETHOD QStyleOptionTabBarBaseV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabBarBaseV2 *ret_v = new KQStyleOptionTabBarBaseV2();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionTabBarBaseV2 QStyleOptionTabBarBaseV2.new(QStyleOptionTabBarBaseV2 other);
KMETHOD QStyleOptionTabBarBaseV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionTabBarBaseV2  other = *RawPtr_to(const QStyleOptionTabBarBaseV2 *, sfp[1]);
	KQStyleOptionTabBarBaseV2 *ret_v = new KQStyleOptionTabBarBaseV2(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QStyleOptionTabBarBaseV2 QStyleOptionTabBarBaseV2.new(QStyleOptionTabBarBase other);
KMETHOD QStyleOptionTabBarBaseV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionTabBarBase  other = *RawPtr_to(const QStyleOptionTabBarBase *, sfp[1]);
	KQStyleOptionTabBarBaseV2 *ret_v = new KQStyleOptionTabBarBaseV2(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionTabBarBaseV2::DummyQStyleOptionTabBarBaseV2()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionTabBarBaseV2::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionTabBarBaseV2::self = ptr;
	DummyQStyleOptionTabBarBase::setSelf(ptr);
}

bool DummyQStyleOptionTabBarBaseV2::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionTabBarBase::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionTabBarBaseV2::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTabBarBaseV2::event_map->bigin();
	if ((itr = DummyQStyleOptionTabBarBaseV2::event_map->find(str)) == DummyQStyleOptionTabBarBaseV2::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionTabBarBase::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionTabBarBaseV2::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTabBarBaseV2::slot_map->bigin();
	if ((itr = DummyQStyleOptionTabBarBaseV2::slot_map->find(str)) == DummyQStyleOptionTabBarBaseV2::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionTabBarBase::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQStyleOptionTabBarBaseV2::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQStyleOptionTabBarBase::reftrace(ctx, p, tail_);
}

void DummyQStyleOptionTabBarBaseV2::connection(QObject *o)
{
	QStyleOptionTabBarBaseV2 *p = dynamic_cast<QStyleOptionTabBarBaseV2*>(o);
	if (p != NULL) {
	}
	DummyQStyleOptionTabBarBase::connection(o);
}

KQStyleOptionTabBarBaseV2::KQStyleOptionTabBarBaseV2() : QStyleOptionTabBarBaseV2()
{
	self = NULL;
	dummy = new DummyQStyleOptionTabBarBaseV2();
}

KMETHOD QStyleOptionTabBarBaseV2_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabBarBaseV2 *qp = RawPtr_to(KQStyleOptionTabBarBaseV2 *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTabBarBaseV2]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTabBarBaseV2]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionTabBarBaseV2_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabBarBaseV2 *qp = RawPtr_to(KQStyleOptionTabBarBaseV2 *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTabBarBaseV2]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTabBarBaseV2]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionTabBarBaseV2_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionTabBarBaseV2 *qp = (KQStyleOptionTabBarBaseV2 *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionTabBarBaseV2_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQStyleOptionTabBarBaseV2 *qp = (KQStyleOptionTabBarBaseV2 *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionTabBarBaseV2_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionTabBarBaseV2::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionTabBarBaseV2ConstInt[] = {
	{"Version", QStyleOptionTabBarBaseV2::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionTabBarBaseV2(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionTabBarBaseV2ConstInt);
}


DEFAPI(void) defQStyleOptionTabBarBaseV2(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionTabBarBaseV2";
	cdef->free = QStyleOptionTabBarBaseV2_free;
	cdef->reftrace = QStyleOptionTabBarBaseV2_reftrace;
	cdef->compareTo = QStyleOptionTabBarBaseV2_compareTo;
}


