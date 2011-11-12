//QStyleOptionViewItemV3 QStyleOptionViewItemV3.new();
KMETHOD QStyleOptionViewItemV3_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionViewItemV3 *ret_v = new KQStyleOptionViewItemV3();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionViewItemV3 QStyleOptionViewItemV3.new(QStyleOptionViewItemV3 other);
KMETHOD QStyleOptionViewItemV3_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionViewItemV3  other = *RawPtr_to(const QStyleOptionViewItemV3 *, sfp[1]);
	KQStyleOptionViewItemV3 *ret_v = new KQStyleOptionViewItemV3(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QStyleOptionViewItemV3 QStyleOptionViewItemV3.new(QStyleOptionViewItem other);
KMETHOD QStyleOptionViewItemV3_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionViewItem  other = *RawPtr_to(const QStyleOptionViewItem *, sfp[1]);
	KQStyleOptionViewItemV3 *ret_v = new KQStyleOptionViewItemV3(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionViewItemV3::DummyQStyleOptionViewItemV3()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionViewItemV3::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionViewItemV3::self = ptr;
	DummyQStyleOptionViewItemV2::setSelf(ptr);
}

bool DummyQStyleOptionViewItemV3::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionViewItemV2::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionViewItemV3::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionViewItemV3::event_map->bigin();
	if ((itr = DummyQStyleOptionViewItemV3::event_map->find(str)) == DummyQStyleOptionViewItemV3::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionViewItemV2::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionViewItemV3::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionViewItemV3::slot_map->bigin();
	if ((itr = DummyQStyleOptionViewItemV3::slot_map->find(str)) == DummyQStyleOptionViewItemV3::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionViewItemV2::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyleOptionViewItemV3::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionViewItemV3::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOptionViewItemV2::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionViewItemV3::connection(QObject *o)
{
	QStyleOptionViewItemV3 *p = dynamic_cast<QStyleOptionViewItemV3*>(o);
	if (p != NULL) {
	}
	DummyQStyleOptionViewItemV2::connection(o);
}

KQStyleOptionViewItemV3::KQStyleOptionViewItemV3() : QStyleOptionViewItemV3()
{
	self = NULL;
	dummy = new DummyQStyleOptionViewItemV3();
}

KMETHOD QStyleOptionViewItemV3_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionViewItemV3 *qp = RawPtr_to(KQStyleOptionViewItemV3 *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionViewItemV3]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionViewItemV3]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionViewItemV3_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionViewItemV3 *qp = RawPtr_to(KQStyleOptionViewItemV3 *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionViewItemV3]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionViewItemV3]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionViewItemV3_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionViewItemV3 *qp = (KQStyleOptionViewItemV3 *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionViewItemV3_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQStyleOptionViewItemV3 *qp = (KQStyleOptionViewItemV3 *)p->rawptr;
//		KQStyleOptionViewItemV3 *qp = static_cast<KQStyleOptionViewItemV3*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionViewItemV3_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionViewItemV3::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionViewItemV3ConstInt[] = {
	{"Version", QStyleOptionViewItemV3::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionViewItemV3(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionViewItemV3ConstInt);
}


DEFAPI(void) defQStyleOptionViewItemV3(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionViewItemV3";
	cdef->free = QStyleOptionViewItemV3_free;
	cdef->reftrace = QStyleOptionViewItemV3_reftrace;
	cdef->compareTo = QStyleOptionViewItemV3_compareTo;
}


