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
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQStyleOptionTabWidgetFrameV2::~DummyQStyleOptionTabWidgetFrameV2()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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

knh_Object_t** DummyQStyleOptionTabWidgetFrameV2::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionTabWidgetFrameV2::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOptionTabWidgetFrame::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionTabWidgetFrameV2::connection(QObject *o)
{
	QStyleOptionTabWidgetFrameV2 *p = dynamic_cast<QStyleOptionTabWidgetFrameV2*>(o);
	if (p != NULL) {
	}
	DummyQStyleOptionTabWidgetFrame::connection(o);
}

KQStyleOptionTabWidgetFrameV2::KQStyleOptionTabWidgetFrameV2() : QStyleOptionTabWidgetFrameV2()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQStyleOptionTabWidgetFrameV2();
}

KQStyleOptionTabWidgetFrameV2::~KQStyleOptionTabWidgetFrameV2()
{
	delete dummy;
	dummy = NULL;
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
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQStyleOptionTabWidgetFrameV2 *qp = (KQStyleOptionTabWidgetFrameV2 *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QStyleOptionTabWidgetFrameV2*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QStyleOptionTabWidgetFrameV2_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQStyleOptionTabWidgetFrameV2 *qp = (KQStyleOptionTabWidgetFrameV2 *)p->rawptr;
		KQStyleOptionTabWidgetFrameV2 *qp = static_cast<KQStyleOptionTabWidgetFrameV2*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
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

static knh_IntData_t QStyleOptionTabWidgetFrameV2ConstInt[] = {
	{"Version", QStyleOptionTabWidgetFrameV2::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionTabWidgetFrameV2(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionTabWidgetFrameV2ConstInt);
}


DEFAPI(void) defQStyleOptionTabWidgetFrameV2(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionTabWidgetFrameV2";
	cdef->free = QStyleOptionTabWidgetFrameV2_free;
	cdef->reftrace = QStyleOptionTabWidgetFrameV2_reftrace;
	cdef->compareTo = QStyleOptionTabWidgetFrameV2_compareTo;
}


