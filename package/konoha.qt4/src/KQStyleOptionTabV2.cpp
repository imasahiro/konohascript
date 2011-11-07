//QStyleOptionTabV2 QStyleOptionTabV2.new();
KMETHOD QStyleOptionTabV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabV2 *ret_v = new KQStyleOptionTabV2();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionTabV2 QStyleOptionTabV2.new(QStyleOptionTabV2 other);
KMETHOD QStyleOptionTabV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionTabV2  other = *RawPtr_to(const QStyleOptionTabV2 *, sfp[1]);
	KQStyleOptionTabV2 *ret_v = new KQStyleOptionTabV2(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QStyleOptionTabV2 QStyleOptionTabV2.new(QStyleOptionTab other);
KMETHOD QStyleOptionTabV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionTab  other = *RawPtr_to(const QStyleOptionTab *, sfp[1]);
	KQStyleOptionTabV2 *ret_v = new KQStyleOptionTabV2(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionTabV2::DummyQStyleOptionTabV2()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionTabV2::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionTabV2::self = ptr;
	DummyQStyleOptionTab::setSelf(ptr);
}

bool DummyQStyleOptionTabV2::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionTab::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionTabV2::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTabV2::event_map->bigin();
	if ((itr = DummyQStyleOptionTabV2::event_map->find(str)) == DummyQStyleOptionTabV2::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionTab::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionTabV2::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTabV2::slot_map->bigin();
	if ((itr = DummyQStyleOptionTabV2::slot_map->find(str)) == DummyQStyleOptionTabV2::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionTab::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQStyleOptionTabV2::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQStyleOptionTab::reftrace(ctx, p, tail_);
}

void DummyQStyleOptionTabV2::connection(QObject *o)
{
	QStyleOptionTabV2 *p = dynamic_cast<QStyleOptionTabV2*>(o);
	if (p != NULL) {
	}
	DummyQStyleOptionTab::connection(o);
}

KQStyleOptionTabV2::KQStyleOptionTabV2() : QStyleOptionTabV2()
{
	self = NULL;
	dummy = new DummyQStyleOptionTabV2();
}

KMETHOD QStyleOptionTabV2_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabV2 *qp = RawPtr_to(KQStyleOptionTabV2 *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTabV2]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTabV2]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionTabV2_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabV2 *qp = RawPtr_to(KQStyleOptionTabV2 *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTabV2]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTabV2]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionTabV2_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionTabV2 *qp = (KQStyleOptionTabV2 *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionTabV2_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQStyleOptionTabV2 *qp = (KQStyleOptionTabV2 *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionTabV2_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionTabV2::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionTabV2ConstInt[] = {
	{"Version", QStyleOptionTabV2::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionTabV2(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionTabV2ConstInt);
}


DEFAPI(void) defQStyleOptionTabV2(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionTabV2";
	cdef->free = QStyleOptionTabV2_free;
	cdef->reftrace = QStyleOptionTabV2_reftrace;
	cdef->compareTo = QStyleOptionTabV2_compareTo;
}


