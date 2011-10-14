//QStyleOptionTabWidgetFrameV2 QStyleOptionTabWidgetFrameV2.new();
KMETHOD QStyleOptionTabWidgetFrameV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabWidgetFrameV2 *ret_v = new KQStyleOptionTabWidgetFrameV2();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionTabWidgetFrameV2 QStyleOptionTabWidgetFrameV2.new(QStyleOptionTabWidgetFrameV2 other);
KMETHOD QStyleOptionTabWidgetFrameV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionTabWidgetFrameV2  other = *RawPtr_to(const QStyleOptionTabWidgetFrameV2 *, sfp[1]);
	KQStyleOptionTabWidgetFrameV2 *ret_v = new KQStyleOptionTabWidgetFrameV2(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QStyleOptionTabWidgetFrameV2 QStyleOptionTabWidgetFrameV2.new(QStyleOptionTabWidgetFrame other);
KMETHOD QStyleOptionTabWidgetFrameV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionTabWidgetFrame  other = *RawPtr_to(const QStyleOptionTabWidgetFrame *, sfp[1]);
	KQStyleOptionTabWidgetFrameV2 *ret_v = new KQStyleOptionTabWidgetFrameV2(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionTabWidgetFrameV2::DummyQStyleOptionTabWidgetFrameV2()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionTabWidgetFrameV2::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionTabWidgetFrameV2::self = ptr;
	DummyQStyleOptionTabWidgetFrame::setSelf(ptr);
}

bool DummyQStyleOptionTabWidgetFrameV2::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionTabWidgetFrame::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionTabWidgetFrameV2::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTabWidgetFrameV2::event_map->bigin();
	if ((itr = DummyQStyleOptionTabWidgetFrameV2::event_map->find(str)) == DummyQStyleOptionTabWidgetFrameV2::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionTabWidgetFrame::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionTabWidgetFrameV2::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTabWidgetFrameV2::slot_map->bigin();
	if ((itr = DummyQStyleOptionTabWidgetFrameV2::slot_map->find(str)) == DummyQStyleOptionTabWidgetFrameV2::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionTabWidgetFrame::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQStyleOptionTabWidgetFrameV2::connection(QObject *o)
{
	DummyQStyleOptionTabWidgetFrame::connection(o);
}

KQStyleOptionTabWidgetFrameV2::KQStyleOptionTabWidgetFrameV2() : QStyleOptionTabWidgetFrameV2()
{
	self = NULL;
	dummy = new DummyQStyleOptionTabWidgetFrameV2();
	dummy->connection((QObject*)this);
}

KMETHOD QStyleOptionTabWidgetFrameV2_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabWidgetFrameV2 *qp = RawPtr_to(KQStyleOptionTabWidgetFrameV2 *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTabWidgetFrameV2]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTabWidgetFrameV2]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionTabWidgetFrameV2_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabWidgetFrameV2 *qp = RawPtr_to(KQStyleOptionTabWidgetFrameV2 *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTabWidgetFrameV2]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTabWidgetFrameV2]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionTabWidgetFrameV2_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionTabWidgetFrameV2 *qp = (KQStyleOptionTabWidgetFrameV2 *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionTabWidgetFrameV2_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQStyleOptionTabWidgetFrameV2 *qp = (KQStyleOptionTabWidgetFrameV2 *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionTabWidgetFrameV2_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionTabWidgetFrameV2::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQStyleOptionTabWidgetFrameV2(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionTabWidgetFrameV2";
	cdef->free = QStyleOptionTabWidgetFrameV2_free;
	cdef->reftrace = QStyleOptionTabWidgetFrameV2_reftrace;
	cdef->compareTo = QStyleOptionTabWidgetFrameV2_compareTo;
}

static knh_IntData_t QStyleOptionTabWidgetFrameV2ConstInt[] = {
	{"Version", QStyleOptionTabWidgetFrameV2::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionTabWidgetFrameV2(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionTabWidgetFrameV2ConstInt);
}

