//QStyleOptionTabV3 QStyleOptionTabV3.new();
KMETHOD QStyleOptionTabV3_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabV3 *ret_v = new KQStyleOptionTabV3();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionTabV3 QStyleOptionTabV3.new(QStyleOptionTabV3 other);
KMETHOD QStyleOptionTabV3_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionTabV3  other = *RawPtr_to(const QStyleOptionTabV3 *, sfp[1]);
	KQStyleOptionTabV3 *ret_v = new KQStyleOptionTabV3(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QStyleOptionTabV3 QStyleOptionTabV3.new(QStyleOptionTabV2 other);
KMETHOD QStyleOptionTabV3_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionTabV2  other = *RawPtr_to(const QStyleOptionTabV2 *, sfp[1]);
	KQStyleOptionTabV3 *ret_v = new KQStyleOptionTabV3(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QStyleOptionTabV3 QStyleOptionTabV3.new(QStyleOptionTab other);
KMETHOD QStyleOptionTabV3_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionTab  other = *RawPtr_to(const QStyleOptionTab *, sfp[1]);
	KQStyleOptionTabV3 *ret_v = new KQStyleOptionTabV3(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionTabV3::DummyQStyleOptionTabV3()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQStyleOptionTabV3::~DummyQStyleOptionTabV3()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQStyleOptionTabV3::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionTabV3::self = ptr;
	DummyQStyleOptionTabV2::setSelf(ptr);
}

bool DummyQStyleOptionTabV3::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionTabV2::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionTabV3::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTabV3::event_map->bigin();
	if ((itr = DummyQStyleOptionTabV3::event_map->find(str)) == DummyQStyleOptionTabV3::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionTabV2::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionTabV3::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTabV3::slot_map->bigin();
	if ((itr = DummyQStyleOptionTabV3::slot_map->find(str)) == DummyQStyleOptionTabV3::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionTabV2::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyleOptionTabV3::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionTabV3::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOptionTabV2::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionTabV3::connection(QObject *o)
{
	QStyleOptionTabV3 *p = dynamic_cast<QStyleOptionTabV3*>(o);
	if (p != NULL) {
	}
	DummyQStyleOptionTabV2::connection(o);
}

KQStyleOptionTabV3::KQStyleOptionTabV3() : QStyleOptionTabV3()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQStyleOptionTabV3();
}

KQStyleOptionTabV3::~KQStyleOptionTabV3()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QStyleOptionTabV3_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabV3 *qp = RawPtr_to(KQStyleOptionTabV3 *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTabV3]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTabV3]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionTabV3_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabV3 *qp = RawPtr_to(KQStyleOptionTabV3 *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTabV3]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTabV3]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionTabV3_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQStyleOptionTabV3 *qp = (KQStyleOptionTabV3 *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QStyleOptionTabV3*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QStyleOptionTabV3_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQStyleOptionTabV3 *qp = (KQStyleOptionTabV3 *)p->rawptr;
		KQStyleOptionTabV3 *qp = static_cast<KQStyleOptionTabV3*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionTabV3_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionTabV3::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionTabV3ConstInt[] = {
	{"Version", QStyleOptionTabV3::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionTabV3(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionTabV3ConstInt);
}


DEFAPI(void) defQStyleOptionTabV3(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionTabV3";
	cdef->free = QStyleOptionTabV3_free;
	cdef->reftrace = QStyleOptionTabV3_reftrace;
	cdef->compareTo = QStyleOptionTabV3_compareTo;
}


