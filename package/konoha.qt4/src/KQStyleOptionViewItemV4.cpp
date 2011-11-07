//QStyleOptionViewItemV4 QStyleOptionViewItemV4.new();
KMETHOD QStyleOptionViewItemV4_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionViewItemV4 *ret_v = new KQStyleOptionViewItemV4();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionViewItemV4 QStyleOptionViewItemV4.new(QStyleOptionViewItemV4 other);
KMETHOD QStyleOptionViewItemV4_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionViewItemV4  other = *RawPtr_to(const QStyleOptionViewItemV4 *, sfp[1]);
	KQStyleOptionViewItemV4 *ret_v = new KQStyleOptionViewItemV4(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QStyleOptionViewItemV4 QStyleOptionViewItemV4.new(QStyleOptionViewItem other);
KMETHOD QStyleOptionViewItemV4_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionViewItem  other = *RawPtr_to(const QStyleOptionViewItem *, sfp[1]);
	KQStyleOptionViewItemV4 *ret_v = new KQStyleOptionViewItemV4(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionViewItemV4::DummyQStyleOptionViewItemV4()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionViewItemV4::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionViewItemV4::self = ptr;
	DummyQStyleOptionViewItemV3::setSelf(ptr);
}

bool DummyQStyleOptionViewItemV4::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionViewItemV3::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionViewItemV4::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionViewItemV4::event_map->bigin();
	if ((itr = DummyQStyleOptionViewItemV4::event_map->find(str)) == DummyQStyleOptionViewItemV4::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionViewItemV3::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionViewItemV4::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionViewItemV4::slot_map->bigin();
	if ((itr = DummyQStyleOptionViewItemV4::slot_map->find(str)) == DummyQStyleOptionViewItemV4::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionViewItemV3::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQStyleOptionViewItemV4::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQStyleOptionViewItemV3::reftrace(ctx, p, tail_);
}

void DummyQStyleOptionViewItemV4::connection(QObject *o)
{
	QStyleOptionViewItemV4 *p = dynamic_cast<QStyleOptionViewItemV4*>(o);
	if (p != NULL) {
	}
	DummyQStyleOptionViewItemV3::connection(o);
}

KQStyleOptionViewItemV4::KQStyleOptionViewItemV4() : QStyleOptionViewItemV4()
{
	self = NULL;
	dummy = new DummyQStyleOptionViewItemV4();
}

KMETHOD QStyleOptionViewItemV4_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionViewItemV4 *qp = RawPtr_to(KQStyleOptionViewItemV4 *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionViewItemV4]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionViewItemV4]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionViewItemV4_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionViewItemV4 *qp = RawPtr_to(KQStyleOptionViewItemV4 *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionViewItemV4]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionViewItemV4]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionViewItemV4_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionViewItemV4 *qp = (KQStyleOptionViewItemV4 *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionViewItemV4_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQStyleOptionViewItemV4 *qp = (KQStyleOptionViewItemV4 *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionViewItemV4_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionViewItemV4::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionViewItemV4ConstInt[] = {
	{"Version", QStyleOptionViewItemV4::Version},
	{"Invalid", QStyleOptionViewItemV4::Invalid},
	{"Beginning", QStyleOptionViewItemV4::Beginning},
	{"Middle", QStyleOptionViewItemV4::Middle},
	{"End", QStyleOptionViewItemV4::End},
	{"OnlyOne", QStyleOptionViewItemV4::OnlyOne},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionViewItemV4(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionViewItemV4ConstInt);
}


DEFAPI(void) defQStyleOptionViewItemV4(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionViewItemV4";
	cdef->free = QStyleOptionViewItemV4_free;
	cdef->reftrace = QStyleOptionViewItemV4_reftrace;
	cdef->compareTo = QStyleOptionViewItemV4_compareTo;
}


