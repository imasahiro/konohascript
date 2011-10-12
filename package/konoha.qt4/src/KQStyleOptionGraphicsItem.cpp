//QStyleOptionGraphicsItem QStyleOptionGraphicsItem.new();
KMETHOD QStyleOptionGraphicsItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionGraphicsItem *ret_v = new KQStyleOptionGraphicsItem();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionGraphicsItem QStyleOptionGraphicsItem.new(QStyleOptionGraphicsItem other);
KMETHOD QStyleOptionGraphicsItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionGraphicsItem  other = *RawPtr_to(const QStyleOptionGraphicsItem *, sfp[1]);
	KQStyleOptionGraphicsItem *ret_v = new KQStyleOptionGraphicsItem(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//float QStyleOptionGraphicsItem.levelOfDetailFromTransform(QTransform worldTransform);
KMETHOD QStyleOptionGraphicsItem_levelOfDetailFromTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyleOptionGraphicsItem *  qp = RawPtr_to(QStyleOptionGraphicsItem *, sfp[0]);
	if (qp != NULL) {
		const QTransform  worldTransform = *RawPtr_to(const QTransform *, sfp[1]);
		qreal ret_v = qp->levelOfDetailFromTransform(worldTransform);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}


DummyQStyleOptionGraphicsItem::DummyQStyleOptionGraphicsItem()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionGraphicsItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionGraphicsItem::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionGraphicsItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionGraphicsItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionGraphicsItem::event_map->bigin();
	if ((itr = DummyQStyleOptionGraphicsItem::event_map->find(str)) == DummyQStyleOptionGraphicsItem::event_map->end()) {
		bool ret;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionGraphicsItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionGraphicsItem::slot_map->bigin();
	if ((itr = DummyQStyleOptionGraphicsItem::event_map->find(str)) == DummyQStyleOptionGraphicsItem::slot_map->end()) {
		bool ret;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQStyleOptionGraphicsItem::KQStyleOptionGraphicsItem() : QStyleOptionGraphicsItem()
{
	self = NULL;
}

KMETHOD QStyleOptionGraphicsItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionGraphicsItem *qp = RawPtr_to(KQStyleOptionGraphicsItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionGraphicsItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQStyleOptionGraphicsItem::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionGraphicsItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QStyleOptionGraphicsItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionGraphicsItem *qp = RawPtr_to(KQStyleOptionGraphicsItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionGraphicsItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQStyleOptionGraphicsItem::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionGraphicsItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionGraphicsItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionGraphicsItem *qp = (KQStyleOptionGraphicsItem *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionGraphicsItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQStyleOptionGraphicsItem *qp = (KQStyleOptionGraphicsItem *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionGraphicsItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQStyleOptionGraphicsItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionGraphicsItem";
	cdef->free = QStyleOptionGraphicsItem_free;
	cdef->reftrace = QStyleOptionGraphicsItem_reftrace;
	cdef->compareTo = QStyleOptionGraphicsItem_compareTo;
}

static knh_IntData_t QStyleOptionGraphicsItemConstInt[] = {
	{"Type", QStyleOptionGraphicsItem::Type},
	{"Version", QStyleOptionGraphicsItem::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionGraphicsItem(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionGraphicsItemConstInt);
}

