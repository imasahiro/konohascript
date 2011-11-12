//QStyleOptionRubberBand QStyleOptionRubberBand.new();
KMETHOD QStyleOptionRubberBand_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionRubberBand *ret_v = new KQStyleOptionRubberBand();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionRubberBand QStyleOptionRubberBand.new(QStyleOptionRubberBand other);
KMETHOD QStyleOptionRubberBand_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionRubberBand  other = *RawPtr_to(const QStyleOptionRubberBand *, sfp[1]);
	KQStyleOptionRubberBand *ret_v = new KQStyleOptionRubberBand(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionRubberBand::DummyQStyleOptionRubberBand()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionRubberBand::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionRubberBand::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionRubberBand::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionRubberBand::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionRubberBand::event_map->bigin();
	if ((itr = DummyQStyleOptionRubberBand::event_map->find(str)) == DummyQStyleOptionRubberBand::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionRubberBand::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionRubberBand::slot_map->bigin();
	if ((itr = DummyQStyleOptionRubberBand::slot_map->find(str)) == DummyQStyleOptionRubberBand::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyleOptionRubberBand::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionRubberBand::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOption::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionRubberBand::connection(QObject *o)
{
	QStyleOptionRubberBand *p = dynamic_cast<QStyleOptionRubberBand*>(o);
	if (p != NULL) {
	}
	DummyQStyleOption::connection(o);
}

KQStyleOptionRubberBand::KQStyleOptionRubberBand() : QStyleOptionRubberBand()
{
	self = NULL;
	dummy = new DummyQStyleOptionRubberBand();
}

KMETHOD QStyleOptionRubberBand_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionRubberBand *qp = RawPtr_to(KQStyleOptionRubberBand *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionRubberBand]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionRubberBand]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionRubberBand_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionRubberBand *qp = RawPtr_to(KQStyleOptionRubberBand *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionRubberBand]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionRubberBand]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionRubberBand_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionRubberBand *qp = (KQStyleOptionRubberBand *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionRubberBand_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQStyleOptionRubberBand *qp = (KQStyleOptionRubberBand *)p->rawptr;
//		KQStyleOptionRubberBand *qp = static_cast<KQStyleOptionRubberBand*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionRubberBand_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionRubberBand::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionRubberBandConstInt[] = {
	{"Type", QStyleOptionRubberBand::Type},
	{"Version", QStyleOptionRubberBand::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionRubberBand(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionRubberBandConstInt);
}


DEFAPI(void) defQStyleOptionRubberBand(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionRubberBand";
	cdef->free = QStyleOptionRubberBand_free;
	cdef->reftrace = QStyleOptionRubberBand_reftrace;
	cdef->compareTo = QStyleOptionRubberBand_compareTo;
}


