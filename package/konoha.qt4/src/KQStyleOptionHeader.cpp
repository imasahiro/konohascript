//QStyleOptionHeader QStyleOptionHeader.new();
KMETHOD QStyleOptionHeader_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionHeader *ret_v = new KQStyleOptionHeader();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionHeader QStyleOptionHeader.new(QStyleOptionHeader other);
KMETHOD QStyleOptionHeader_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionHeader  other = *RawPtr_to(const QStyleOptionHeader *, sfp[1]);
	KQStyleOptionHeader *ret_v = new KQStyleOptionHeader(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionHeader::DummyQStyleOptionHeader()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionHeader::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionHeader::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionHeader::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionHeader::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionHeader::event_map->bigin();
	if ((itr = DummyQStyleOptionHeader::event_map->find(str)) == DummyQStyleOptionHeader::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionHeader::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionHeader::slot_map->bigin();
	if ((itr = DummyQStyleOptionHeader::slot_map->find(str)) == DummyQStyleOptionHeader::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyleOptionHeader::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionHeader::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOption::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionHeader::connection(QObject *o)
{
	QStyleOptionHeader *p = dynamic_cast<QStyleOptionHeader*>(o);
	if (p != NULL) {
	}
	DummyQStyleOption::connection(o);
}

KQStyleOptionHeader::KQStyleOptionHeader() : QStyleOptionHeader()
{
	self = NULL;
	dummy = new DummyQStyleOptionHeader();
}

KMETHOD QStyleOptionHeader_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionHeader *qp = RawPtr_to(KQStyleOptionHeader *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionHeader]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionHeader]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionHeader_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionHeader *qp = RawPtr_to(KQStyleOptionHeader *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionHeader]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionHeader]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionHeader_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionHeader *qp = (KQStyleOptionHeader *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionHeader_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQStyleOptionHeader *qp = (KQStyleOptionHeader *)p->rawptr;
//		KQStyleOptionHeader *qp = static_cast<KQStyleOptionHeader*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionHeader_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionHeader::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionHeaderConstInt[] = {
	{"Beginning", QStyleOptionHeader::Beginning},
	{"Middle", QStyleOptionHeader::Middle},
	{"End", QStyleOptionHeader::End},
	{"OnlyOneSection", QStyleOptionHeader::OnlyOneSection},
	{"NotAdjacent", QStyleOptionHeader::NotAdjacent},
	{"NextIsSelected", QStyleOptionHeader::NextIsSelected},
	{"PreviousIsSelected", QStyleOptionHeader::PreviousIsSelected},
	{"NextAndPreviousAreSelected", QStyleOptionHeader::NextAndPreviousAreSelected},
	{"None", QStyleOptionHeader::None},
	{"SortUp", QStyleOptionHeader::SortUp},
	{"SortDown", QStyleOptionHeader::SortDown},
	{"Type", QStyleOptionHeader::Type},
	{"Version", QStyleOptionHeader::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionHeader(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionHeaderConstInt);
}


DEFAPI(void) defQStyleOptionHeader(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionHeader";
	cdef->free = QStyleOptionHeader_free;
	cdef->reftrace = QStyleOptionHeader_reftrace;
	cdef->compareTo = QStyleOptionHeader_compareTo;
}


