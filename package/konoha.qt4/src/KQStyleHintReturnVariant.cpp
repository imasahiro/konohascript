//QStyleHintReturnVariant QStyleHintReturnVariant.new();
KMETHOD QStyleHintReturnVariant_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleHintReturnVariant *ret_v = new KQStyleHintReturnVariant();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}


DummyQStyleHintReturnVariant::DummyQStyleHintReturnVariant()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQStyleHintReturnVariant::~DummyQStyleHintReturnVariant()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQStyleHintReturnVariant::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleHintReturnVariant::self = ptr;
	DummyQStyleHintReturn::setSelf(ptr);
}

bool DummyQStyleHintReturnVariant::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleHintReturn::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleHintReturnVariant::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleHintReturnVariant::event_map->bigin();
	if ((itr = DummyQStyleHintReturnVariant::event_map->find(str)) == DummyQStyleHintReturnVariant::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleHintReturn::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleHintReturnVariant::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleHintReturnVariant::slot_map->bigin();
	if ((itr = DummyQStyleHintReturnVariant::slot_map->find(str)) == DummyQStyleHintReturnVariant::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleHintReturn::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyleHintReturnVariant::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleHintReturnVariant::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleHintReturn::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleHintReturnVariant::connection(QObject *o)
{
	QStyleHintReturnVariant *p = dynamic_cast<QStyleHintReturnVariant*>(o);
	if (p != NULL) {
	}
	DummyQStyleHintReturn::connection(o);
}

KQStyleHintReturnVariant::KQStyleHintReturnVariant() : QStyleHintReturnVariant()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQStyleHintReturnVariant();
}

KQStyleHintReturnVariant::~KQStyleHintReturnVariant()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QStyleHintReturnVariant_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleHintReturnVariant *qp = RawPtr_to(KQStyleHintReturnVariant *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleHintReturnVariant]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleHintReturnVariant]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleHintReturnVariant_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleHintReturnVariant *qp = RawPtr_to(KQStyleHintReturnVariant *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleHintReturnVariant]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleHintReturnVariant]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleHintReturnVariant_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQStyleHintReturnVariant *qp = (KQStyleHintReturnVariant *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QStyleHintReturnVariant*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QStyleHintReturnVariant_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQStyleHintReturnVariant *qp = (KQStyleHintReturnVariant *)p->rawptr;
		KQStyleHintReturnVariant *qp = static_cast<KQStyleHintReturnVariant*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleHintReturnVariant_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleHintReturnVariant::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleHintReturnVariantConstInt[] = {
	{"Type", QStyleHintReturnVariant::Type},
	{"Version", QStyleHintReturnVariant::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleHintReturnVariant(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleHintReturnVariantConstInt);
}


DEFAPI(void) defQStyleHintReturnVariant(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleHintReturnVariant";
	cdef->free = QStyleHintReturnVariant_free;
	cdef->reftrace = QStyleHintReturnVariant_reftrace;
	cdef->compareTo = QStyleHintReturnVariant_compareTo;
}


