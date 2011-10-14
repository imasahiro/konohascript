//QStyleOptionProgressBarV2 QStyleOptionProgressBarV2.new();
KMETHOD QStyleOptionProgressBarV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionProgressBarV2 *ret_v = new KQStyleOptionProgressBarV2();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionProgressBarV2 QStyleOptionProgressBarV2.new(QStyleOptionProgressBar other);
KMETHOD QStyleOptionProgressBarV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionProgressBar  other = *RawPtr_to(const QStyleOptionProgressBar *, sfp[1]);
	KQStyleOptionProgressBarV2 *ret_v = new KQStyleOptionProgressBarV2(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QStyleOptionProgressBarV2 QStyleOptionProgressBarV2.new(QStyleOptionProgressBarV2 other);
KMETHOD QStyleOptionProgressBarV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionProgressBarV2  other = *RawPtr_to(const QStyleOptionProgressBarV2 *, sfp[1]);
	KQStyleOptionProgressBarV2 *ret_v = new KQStyleOptionProgressBarV2(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionProgressBarV2::DummyQStyleOptionProgressBarV2()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionProgressBarV2::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionProgressBarV2::self = ptr;
	DummyQStyleOptionProgressBar::setSelf(ptr);
}

bool DummyQStyleOptionProgressBarV2::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionProgressBar::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionProgressBarV2::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionProgressBarV2::event_map->bigin();
	if ((itr = DummyQStyleOptionProgressBarV2::event_map->find(str)) == DummyQStyleOptionProgressBarV2::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionProgressBar::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionProgressBarV2::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionProgressBarV2::slot_map->bigin();
	if ((itr = DummyQStyleOptionProgressBarV2::slot_map->find(str)) == DummyQStyleOptionProgressBarV2::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionProgressBar::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQStyleOptionProgressBarV2::connection(QObject *o)
{
	DummyQStyleOptionProgressBar::connection(o);
}

KQStyleOptionProgressBarV2::KQStyleOptionProgressBarV2() : QStyleOptionProgressBarV2()
{
	self = NULL;
	dummy = new DummyQStyleOptionProgressBarV2();
	dummy->connection((QObject*)this);
}

KMETHOD QStyleOptionProgressBarV2_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionProgressBarV2 *qp = RawPtr_to(KQStyleOptionProgressBarV2 *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionProgressBarV2]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionProgressBarV2]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionProgressBarV2_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionProgressBarV2 *qp = RawPtr_to(KQStyleOptionProgressBarV2 *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionProgressBarV2]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionProgressBarV2]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionProgressBarV2_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionProgressBarV2 *qp = (KQStyleOptionProgressBarV2 *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionProgressBarV2_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQStyleOptionProgressBarV2 *qp = (KQStyleOptionProgressBarV2 *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionProgressBarV2_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionProgressBarV2::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQStyleOptionProgressBarV2(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionProgressBarV2";
	cdef->free = QStyleOptionProgressBarV2_free;
	cdef->reftrace = QStyleOptionProgressBarV2_reftrace;
	cdef->compareTo = QStyleOptionProgressBarV2_compareTo;
}

static knh_IntData_t QStyleOptionProgressBarV2ConstInt[] = {
	{"Type", QStyleOptionProgressBarV2::Type},
	{"Version", QStyleOptionProgressBarV2::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionProgressBarV2(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionProgressBarV2ConstInt);
}

