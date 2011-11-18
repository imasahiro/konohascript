//QStyleOptionToolBoxV2 QStyleOptionToolBoxV2.new();
KMETHOD QStyleOptionToolBoxV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionToolBoxV2 *ret_v = new KQStyleOptionToolBoxV2();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionToolBoxV2 QStyleOptionToolBoxV2.new(QStyleOptionToolBoxV2 other);
KMETHOD QStyleOptionToolBoxV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionToolBoxV2  other = *RawPtr_to(const QStyleOptionToolBoxV2 *, sfp[1]);
	KQStyleOptionToolBoxV2 *ret_v = new KQStyleOptionToolBoxV2(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QStyleOptionToolBoxV2 QStyleOptionToolBoxV2.new(QStyleOptionToolBox other);
KMETHOD QStyleOptionToolBoxV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionToolBox  other = *RawPtr_to(const QStyleOptionToolBox *, sfp[1]);
	KQStyleOptionToolBoxV2 *ret_v = new KQStyleOptionToolBoxV2(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionToolBoxV2::DummyQStyleOptionToolBoxV2()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQStyleOptionToolBoxV2::~DummyQStyleOptionToolBoxV2()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQStyleOptionToolBoxV2::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionToolBoxV2::self = ptr;
	DummyQStyleOptionToolBox::setSelf(ptr);
}

bool DummyQStyleOptionToolBoxV2::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionToolBox::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionToolBoxV2::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionToolBoxV2::event_map->bigin();
	if ((itr = DummyQStyleOptionToolBoxV2::event_map->find(str)) == DummyQStyleOptionToolBoxV2::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionToolBox::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionToolBoxV2::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionToolBoxV2::slot_map->bigin();
	if ((itr = DummyQStyleOptionToolBoxV2::slot_map->find(str)) == DummyQStyleOptionToolBoxV2::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionToolBox::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyleOptionToolBoxV2::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionToolBoxV2::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOptionToolBox::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionToolBoxV2::connection(QObject *o)
{
	QStyleOptionToolBoxV2 *p = dynamic_cast<QStyleOptionToolBoxV2*>(o);
	if (p != NULL) {
	}
	DummyQStyleOptionToolBox::connection(o);
}

KQStyleOptionToolBoxV2::KQStyleOptionToolBoxV2() : QStyleOptionToolBoxV2()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQStyleOptionToolBoxV2();
}

KQStyleOptionToolBoxV2::~KQStyleOptionToolBoxV2()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QStyleOptionToolBoxV2_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionToolBoxV2 *qp = RawPtr_to(KQStyleOptionToolBoxV2 *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionToolBoxV2]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionToolBoxV2]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionToolBoxV2_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionToolBoxV2 *qp = RawPtr_to(KQStyleOptionToolBoxV2 *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionToolBoxV2]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionToolBoxV2]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionToolBoxV2_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQStyleOptionToolBoxV2 *qp = (KQStyleOptionToolBoxV2 *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QStyleOptionToolBoxV2*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QStyleOptionToolBoxV2_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQStyleOptionToolBoxV2 *qp = (KQStyleOptionToolBoxV2 *)p->rawptr;
		KQStyleOptionToolBoxV2 *qp = static_cast<KQStyleOptionToolBoxV2*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionToolBoxV2_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionToolBoxV2::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionToolBoxV2ConstInt[] = {
	{"NotAdjacent", QStyleOptionToolBoxV2::NotAdjacent},
	{"NextIsSelected", QStyleOptionToolBoxV2::NextIsSelected},
	{"PreviousIsSelected", QStyleOptionToolBoxV2::PreviousIsSelected},
	{"Version", QStyleOptionToolBoxV2::Version},
	{"Beginning", QStyleOptionToolBoxV2::Beginning},
	{"Middle", QStyleOptionToolBoxV2::Middle},
	{"End", QStyleOptionToolBoxV2::End},
	{"OnlyOneTab", QStyleOptionToolBoxV2::OnlyOneTab},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionToolBoxV2(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionToolBoxV2ConstInt);
}


DEFAPI(void) defQStyleOptionToolBoxV2(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionToolBoxV2";
	cdef->free = QStyleOptionToolBoxV2_free;
	cdef->reftrace = QStyleOptionToolBoxV2_reftrace;
	cdef->compareTo = QStyleOptionToolBoxV2_compareTo;
}


