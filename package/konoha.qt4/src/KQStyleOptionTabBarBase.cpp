//QStyleOptionTabBarBase QStyleOptionTabBarBase.new();
KMETHOD QStyleOptionTabBarBase_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabBarBase *ret_v = new KQStyleOptionTabBarBase();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionTabBarBase QStyleOptionTabBarBase.new(QStyleOptionTabBarBase other);
KMETHOD QStyleOptionTabBarBase_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionTabBarBase  other = *RawPtr_to(const QStyleOptionTabBarBase *, sfp[1]);
	KQStyleOptionTabBarBase *ret_v = new KQStyleOptionTabBarBase(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionTabBarBase::DummyQStyleOptionTabBarBase()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQStyleOptionTabBarBase::~DummyQStyleOptionTabBarBase()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQStyleOptionTabBarBase::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionTabBarBase::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionTabBarBase::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionTabBarBase::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTabBarBase::event_map->bigin();
	if ((itr = DummyQStyleOptionTabBarBase::event_map->find(str)) == DummyQStyleOptionTabBarBase::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionTabBarBase::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTabBarBase::slot_map->bigin();
	if ((itr = DummyQStyleOptionTabBarBase::slot_map->find(str)) == DummyQStyleOptionTabBarBase::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyleOptionTabBarBase::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionTabBarBase::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOption::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionTabBarBase::connection(QObject *o)
{
	QStyleOptionTabBarBase *p = dynamic_cast<QStyleOptionTabBarBase*>(o);
	if (p != NULL) {
	}
	DummyQStyleOption::connection(o);
}

KQStyleOptionTabBarBase::KQStyleOptionTabBarBase() : QStyleOptionTabBarBase()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQStyleOptionTabBarBase();
}

KQStyleOptionTabBarBase::~KQStyleOptionTabBarBase()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QStyleOptionTabBarBase_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabBarBase *qp = RawPtr_to(KQStyleOptionTabBarBase *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTabBarBase]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTabBarBase]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionTabBarBase_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabBarBase *qp = RawPtr_to(KQStyleOptionTabBarBase *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTabBarBase]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTabBarBase]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionTabBarBase_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQStyleOptionTabBarBase *qp = (KQStyleOptionTabBarBase *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QStyleOptionTabBarBase*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QStyleOptionTabBarBase_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQStyleOptionTabBarBase *qp = (KQStyleOptionTabBarBase *)p->rawptr;
		KQStyleOptionTabBarBase *qp = static_cast<KQStyleOptionTabBarBase*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionTabBarBase_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionTabBarBase::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionTabBarBaseConstInt[] = {
	{"Type", QStyleOptionTabBarBase::Type},
	{"Version", QStyleOptionTabBarBase::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionTabBarBase(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionTabBarBaseConstInt);
}


DEFAPI(void) defQStyleOptionTabBarBase(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionTabBarBase";
	cdef->free = QStyleOptionTabBarBase_free;
	cdef->reftrace = QStyleOptionTabBarBase_reftrace;
	cdef->compareTo = QStyleOptionTabBarBase_compareTo;
}


