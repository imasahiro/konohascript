//QStyleOptionViewItem QStyleOptionViewItem.new();
KMETHOD QStyleOptionViewItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionViewItem *ret_v = new KQStyleOptionViewItem();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionViewItem QStyleOptionViewItem.new(QStyleOptionViewItem other);
KMETHOD QStyleOptionViewItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionViewItem  other = *RawPtr_to(const QStyleOptionViewItem *, sfp[1]);
	KQStyleOptionViewItem *ret_v = new KQStyleOptionViewItem(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionViewItem::DummyQStyleOptionViewItem()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionViewItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionViewItem::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionViewItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionViewItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionViewItem::event_map->bigin();
	if ((itr = DummyQStyleOptionViewItem::event_map->find(str)) == DummyQStyleOptionViewItem::event_map->end()) {
		bool ret;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionViewItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionViewItem::slot_map->bigin();
	if ((itr = DummyQStyleOptionViewItem::event_map->find(str)) == DummyQStyleOptionViewItem::slot_map->end()) {
		bool ret;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQStyleOptionViewItem::KQStyleOptionViewItem() : QStyleOptionViewItem()
{
	self = NULL;
}

KMETHOD QStyleOptionViewItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionViewItem *qp = RawPtr_to(KQStyleOptionViewItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionViewItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQStyleOptionViewItem::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionViewItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QStyleOptionViewItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionViewItem *qp = RawPtr_to(KQStyleOptionViewItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionViewItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQStyleOptionViewItem::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionViewItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionViewItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionViewItem *qp = (KQStyleOptionViewItem *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionViewItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQStyleOptionViewItem *qp = (KQStyleOptionViewItem *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionViewItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQStyleOptionViewItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionViewItem";
	cdef->free = QStyleOptionViewItem_free;
	cdef->reftrace = QStyleOptionViewItem_reftrace;
	cdef->compareTo = QStyleOptionViewItem_compareTo;
}

static knh_IntData_t QStyleOptionViewItemConstInt[] = {
	{"Left", QStyleOptionViewItem::Left},
	{"Right", QStyleOptionViewItem::Right},
	{"Top", QStyleOptionViewItem::Top},
	{"Bottom", QStyleOptionViewItem::Bottom},
	{"Type", QStyleOptionViewItem::Type},
	{"Version", QStyleOptionViewItem::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionViewItem(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionViewItemConstInt);
}

