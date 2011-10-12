//QStyleOptionViewItemV2 QStyleOptionViewItemV2.new();
KMETHOD QStyleOptionViewItemV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionViewItemV2 *ret_v = new KQStyleOptionViewItemV2();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionViewItemV2 QStyleOptionViewItemV2.new(QStyleOptionViewItemV2 other);
KMETHOD QStyleOptionViewItemV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionViewItemV2  other = *RawPtr_to(const QStyleOptionViewItemV2 *, sfp[1]);
	KQStyleOptionViewItemV2 *ret_v = new KQStyleOptionViewItemV2(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QStyleOptionViewItemV2 QStyleOptionViewItemV2.new(QStyleOptionViewItem other);
KMETHOD QStyleOptionViewItemV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionViewItem  other = *RawPtr_to(const QStyleOptionViewItem *, sfp[1]);
	KQStyleOptionViewItemV2 *ret_v = new KQStyleOptionViewItemV2(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionViewItemV2::DummyQStyleOptionViewItemV2()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionViewItemV2::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionViewItemV2::self = ptr;
	DummyQStyleOptionViewItem::setSelf(ptr);
}

bool DummyQStyleOptionViewItemV2::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionViewItem::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionViewItemV2::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionViewItemV2::event_map->bigin();
	if ((itr = DummyQStyleOptionViewItemV2::event_map->find(str)) == DummyQStyleOptionViewItemV2::event_map->end()) {
		bool ret;
		ret = DummyQStyleOptionViewItem::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionViewItemV2::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionViewItemV2::slot_map->bigin();
	if ((itr = DummyQStyleOptionViewItemV2::event_map->find(str)) == DummyQStyleOptionViewItemV2::slot_map->end()) {
		bool ret;
		ret = DummyQStyleOptionViewItem::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQStyleOptionViewItemV2::KQStyleOptionViewItemV2() : QStyleOptionViewItemV2()
{
	self = NULL;
}

KMETHOD QStyleOptionViewItemV2_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionViewItemV2 *qp = RawPtr_to(KQStyleOptionViewItemV2 *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionViewItemV2]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQStyleOptionViewItemV2::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionViewItemV2]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QStyleOptionViewItemV2_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionViewItemV2 *qp = RawPtr_to(KQStyleOptionViewItemV2 *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionViewItemV2]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQStyleOptionViewItemV2::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionViewItemV2]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionViewItemV2_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionViewItemV2 *qp = (KQStyleOptionViewItemV2 *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionViewItemV2_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQStyleOptionViewItemV2 *qp = (KQStyleOptionViewItemV2 *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionViewItemV2_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQStyleOptionViewItemV2(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionViewItemV2";
	cdef->free = QStyleOptionViewItemV2_free;
	cdef->reftrace = QStyleOptionViewItemV2_reftrace;
	cdef->compareTo = QStyleOptionViewItemV2_compareTo;
}

static knh_IntData_t QStyleOptionViewItemV2ConstInt[] = {
	{"Version", QStyleOptionViewItemV2::Version},
	{"None", QStyleOptionViewItemV2::None},
	{"WrapText", QStyleOptionViewItemV2::WrapText},
	{"Alternate", QStyleOptionViewItemV2::Alternate},
	{"HasCheckIndicator", QStyleOptionViewItemV2::HasCheckIndicator},
	{"HasDisplay", QStyleOptionViewItemV2::HasDisplay},
	{"HasDecoration", QStyleOptionViewItemV2::HasDecoration},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionViewItemV2(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionViewItemV2ConstInt);
}

