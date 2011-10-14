//QStyleOptionTab QStyleOptionTab.new();
KMETHOD QStyleOptionTab_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTab *ret_v = new KQStyleOptionTab();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionTab QStyleOptionTab.new(QStyleOptionTab other);
KMETHOD QStyleOptionTab_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionTab  other = *RawPtr_to(const QStyleOptionTab *, sfp[1]);
	KQStyleOptionTab *ret_v = new KQStyleOptionTab(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionTab::DummyQStyleOptionTab()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionTab::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionTab::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionTab::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionTab::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTab::event_map->bigin();
	if ((itr = DummyQStyleOptionTab::event_map->find(str)) == DummyQStyleOptionTab::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionTab::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTab::slot_map->bigin();
	if ((itr = DummyQStyleOptionTab::slot_map->find(str)) == DummyQStyleOptionTab::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQStyleOptionTab::connection(QObject *o)
{
	DummyQStyleOption::connection(o);
}

KQStyleOptionTab::KQStyleOptionTab() : QStyleOptionTab()
{
	self = NULL;
	dummy = new DummyQStyleOptionTab();
	dummy->connection((QObject*)this);
}

KMETHOD QStyleOptionTab_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTab *qp = RawPtr_to(KQStyleOptionTab *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTab]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTab]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionTab_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTab *qp = RawPtr_to(KQStyleOptionTab *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTab]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTab]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionTab_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionTab *qp = (KQStyleOptionTab *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionTab_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQStyleOptionTab *qp = (KQStyleOptionTab *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionTab_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionTab::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQStyleOptionTab(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionTab";
	cdef->free = QStyleOptionTab_free;
	cdef->reftrace = QStyleOptionTab_reftrace;
	cdef->compareTo = QStyleOptionTab_compareTo;
}

static knh_IntData_t QStyleOptionTabConstInt[] = {
	{"NoCornerWidgets", QStyleOptionTab::NoCornerWidgets},
	{"LeftCornerWidget", QStyleOptionTab::LeftCornerWidget},
	{"RightCornerWidget", QStyleOptionTab::RightCornerWidget},
	{"NotAdjacent", QStyleOptionTab::NotAdjacent},
	{"NextIsSelected", QStyleOptionTab::NextIsSelected},
	{"PreviousIsSelected", QStyleOptionTab::PreviousIsSelected},
	{"Type", QStyleOptionTab::Type},
	{"Version", QStyleOptionTab::Version},
	{"Beginning", QStyleOptionTab::Beginning},
	{"Middle", QStyleOptionTab::Middle},
	{"End", QStyleOptionTab::End},
	{"OnlyOneTab", QStyleOptionTab::OnlyOneTab},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionTab(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionTabConstInt);
}

