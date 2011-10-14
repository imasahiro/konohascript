//QStyleOptionProgressBar QStyleOptionProgressBar.new();
KMETHOD QStyleOptionProgressBar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionProgressBar *ret_v = new KQStyleOptionProgressBar();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionProgressBar QStyleOptionProgressBar.new(QStyleOptionProgressBar other);
KMETHOD QStyleOptionProgressBar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionProgressBar  other = *RawPtr_to(const QStyleOptionProgressBar *, sfp[1]);
	KQStyleOptionProgressBar *ret_v = new KQStyleOptionProgressBar(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionProgressBar::DummyQStyleOptionProgressBar()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionProgressBar::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionProgressBar::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionProgressBar::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionProgressBar::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionProgressBar::event_map->bigin();
	if ((itr = DummyQStyleOptionProgressBar::event_map->find(str)) == DummyQStyleOptionProgressBar::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionProgressBar::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionProgressBar::slot_map->bigin();
	if ((itr = DummyQStyleOptionProgressBar::slot_map->find(str)) == DummyQStyleOptionProgressBar::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQStyleOptionProgressBar::connection(QObject *o)
{
	DummyQStyleOption::connection(o);
}

KQStyleOptionProgressBar::KQStyleOptionProgressBar() : QStyleOptionProgressBar()
{
	self = NULL;
	dummy = new DummyQStyleOptionProgressBar();
	dummy->connection((QObject*)this);
}

KMETHOD QStyleOptionProgressBar_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionProgressBar *qp = RawPtr_to(KQStyleOptionProgressBar *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionProgressBar]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionProgressBar]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionProgressBar_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionProgressBar *qp = RawPtr_to(KQStyleOptionProgressBar *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionProgressBar]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionProgressBar]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionProgressBar_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionProgressBar *qp = (KQStyleOptionProgressBar *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionProgressBar_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQStyleOptionProgressBar *qp = (KQStyleOptionProgressBar *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionProgressBar_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionProgressBar::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQStyleOptionProgressBar(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionProgressBar";
	cdef->free = QStyleOptionProgressBar_free;
	cdef->reftrace = QStyleOptionProgressBar_reftrace;
	cdef->compareTo = QStyleOptionProgressBar_compareTo;
}

static knh_IntData_t QStyleOptionProgressBarConstInt[] = {
	{"Type", QStyleOptionProgressBar::Type},
	{"Version", QStyleOptionProgressBar::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionProgressBar(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionProgressBarConstInt);
}

