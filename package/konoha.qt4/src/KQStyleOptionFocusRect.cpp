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
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQStyleOptionFocusRect::~DummyQStyleOptionFocusRect()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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

knh_Object_t** DummyQStyleOptionFocusRect::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionFocusRect::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOption::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionFocusRect::connection(QObject *o)
{
	QStyleOptionFocusRect *p = dynamic_cast<QStyleOptionFocusRect*>(o);
	if (p != NULL) {
	}
	DummyQStyleOption::connection(o);
}

KQStyleOptionFocusRect::KQStyleOptionFocusRect() : QStyleOptionFocusRect()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQStyleOptionFocusRect();
}

KQStyleOptionFocusRect::~KQStyleOptionFocusRect()
{
	delete dummy;
	dummy = NULL;
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
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQStyleOptionFocusRect *qp = (KQStyleOptionFocusRect *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QStyleOptionFocusRect*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QStyleOptionFocusRect_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQStyleOptionFocusRect *qp = (KQStyleOptionFocusRect *)p->rawptr;
		KQStyleOptionFocusRect *qp = static_cast<KQStyleOptionFocusRect*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
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

static knh_IntData_t QStyleOptionFocusRectConstInt[] = {
	{"Type", QStyleOptionFocusRect::Type},
	{"Version", QStyleOptionFocusRect::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionFocusRect(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionFocusRectConstInt);
}


DEFAPI(void) defQStyleOptionFocusRect(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionFocusRect";
	cdef->free = QStyleOptionFocusRect_free;
	cdef->reftrace = QStyleOptionFocusRect_reftrace;
	cdef->compareTo = QStyleOptionFocusRect_compareTo;
}


