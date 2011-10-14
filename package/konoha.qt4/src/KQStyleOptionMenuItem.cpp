//QStyleOptionMenuItem QStyleOptionMenuItem.new();
KMETHOD QStyleOptionMenuItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionMenuItem *ret_v = new KQStyleOptionMenuItem();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionMenuItem QStyleOptionMenuItem.new(QStyleOptionMenuItem other);
KMETHOD QStyleOptionMenuItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionMenuItem  other = *RawPtr_to(const QStyleOptionMenuItem *, sfp[1]);
	KQStyleOptionMenuItem *ret_v = new KQStyleOptionMenuItem(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionMenuItem::DummyQStyleOptionMenuItem()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionMenuItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionMenuItem::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionMenuItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionMenuItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionMenuItem::event_map->bigin();
	if ((itr = DummyQStyleOptionMenuItem::event_map->find(str)) == DummyQStyleOptionMenuItem::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionMenuItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionMenuItem::slot_map->bigin();
	if ((itr = DummyQStyleOptionMenuItem::slot_map->find(str)) == DummyQStyleOptionMenuItem::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQStyleOptionMenuItem::connection(QObject *o)
{
	DummyQStyleOption::connection(o);
}

KQStyleOptionMenuItem::KQStyleOptionMenuItem() : QStyleOptionMenuItem()
{
	self = NULL;
	dummy = new DummyQStyleOptionMenuItem();
	dummy->connection((QObject*)this);
}

KMETHOD QStyleOptionMenuItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionMenuItem *qp = RawPtr_to(KQStyleOptionMenuItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionMenuItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionMenuItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionMenuItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionMenuItem *qp = RawPtr_to(KQStyleOptionMenuItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionMenuItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionMenuItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionMenuItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionMenuItem *qp = (KQStyleOptionMenuItem *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionMenuItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQStyleOptionMenuItem *qp = (KQStyleOptionMenuItem *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionMenuItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionMenuItem::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQStyleOptionMenuItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionMenuItem";
	cdef->free = QStyleOptionMenuItem_free;
	cdef->reftrace = QStyleOptionMenuItem_reftrace;
	cdef->compareTo = QStyleOptionMenuItem_compareTo;
}

static knh_IntData_t QStyleOptionMenuItemConstInt[] = {
	{"NotCheckable", QStyleOptionMenuItem::NotCheckable},
	{"Exclusive", QStyleOptionMenuItem::Exclusive},
	{"NonExclusive", QStyleOptionMenuItem::NonExclusive},
	{"Normal", QStyleOptionMenuItem::Normal},
	{"DefaultItem", QStyleOptionMenuItem::DefaultItem},
	{"Separator", QStyleOptionMenuItem::Separator},
	{"SubMenu", QStyleOptionMenuItem::SubMenu},
	{"Scroller", QStyleOptionMenuItem::Scroller},
	{"TearOff", QStyleOptionMenuItem::TearOff},
	{"Margin", QStyleOptionMenuItem::Margin},
	{"EmptyArea", QStyleOptionMenuItem::EmptyArea},
	{"Type", QStyleOptionMenuItem::Type},
	{"Version", QStyleOptionMenuItem::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionMenuItem(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionMenuItemConstInt);
}

