//QStyleOptionFocusRect QStyleOptionFocusRect.new();
KMETHOD QStyleOptionFocusRect_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionFocusRect *ret_v = new KQStyleOptionFocusRect();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionFocusRect QStyleOptionFocusRect.new(QStyleOptionFocusRect other);
KMETHOD QStyleOptionFocusRect_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionFocusRect  other = *RawPtr_to(const QStyleOptionFocusRect *, sfp[1]);
	KQStyleOptionFocusRect *ret_v = new KQStyleOptionFocusRect(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionFocusRect::DummyQStyleOptionFocusRect()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionFocusRect::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionFocusRect::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionFocusRect::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionFocusRect::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionFocusRect::event_map->bigin();
	if ((itr = DummyQStyleOptionFocusRect::event_map->find(str)) == DummyQStyleOptionFocusRect::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionFocusRect::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionFocusRect::slot_map->bigin();
	if ((itr = DummyQStyleOptionFocusRect::slot_map->find(str)) == DummyQStyleOptionFocusRect::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQStyleOptionFocusRect::connection(QObject *o)
{
	DummyQStyleOption::connection(o);
}

KQStyleOptionFocusRect::KQStyleOptionFocusRect() : QStyleOptionFocusRect()
{
	self = NULL;
	dummy = new DummyQStyleOptionFocusRect();
	dummy->connection((QObject*)this);
}

KMETHOD QStyleOptionFocusRect_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionFocusRect *qp = RawPtr_to(KQStyleOptionFocusRect *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionFocusRect]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionFocusRect]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionFocusRect_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionFocusRect *qp = RawPtr_to(KQStyleOptionFocusRect *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionFocusRect]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionFocusRect]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionFocusRect_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionFocusRect *qp = (KQStyleOptionFocusRect *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionFocusRect_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQStyleOptionFocusRect *qp = (KQStyleOptionFocusRect *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionFocusRect_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionFocusRect::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQStyleOptionFocusRect(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionFocusRect";
	cdef->free = QStyleOptionFocusRect_free;
	cdef->reftrace = QStyleOptionFocusRect_reftrace;
	cdef->compareTo = QStyleOptionFocusRect_compareTo;
}

static knh_IntData_t QStyleOptionFocusRectConstInt[] = {
	{"Type", QStyleOptionFocusRect::Type},
	{"Version", QStyleOptionFocusRect::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionFocusRect(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionFocusRectConstInt);
}

