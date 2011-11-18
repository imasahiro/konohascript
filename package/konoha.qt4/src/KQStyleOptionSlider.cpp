//QStyleOptionSlider QStyleOptionSlider.new();
KMETHOD QStyleOptionSlider_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionSlider *ret_v = new KQStyleOptionSlider();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionSlider QStyleOptionSlider.new(QStyleOptionSlider other);
KMETHOD QStyleOptionSlider_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionSlider  other = *RawPtr_to(const QStyleOptionSlider *, sfp[1]);
	KQStyleOptionSlider *ret_v = new KQStyleOptionSlider(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionSlider::DummyQStyleOptionSlider()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQStyleOptionSlider::~DummyQStyleOptionSlider()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQStyleOptionSlider::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionSlider::self = ptr;
	DummyQStyleOptionComplex::setSelf(ptr);
}

bool DummyQStyleOptionSlider::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionComplex::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionSlider::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionSlider::event_map->bigin();
	if ((itr = DummyQStyleOptionSlider::event_map->find(str)) == DummyQStyleOptionSlider::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionComplex::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionSlider::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionSlider::slot_map->bigin();
	if ((itr = DummyQStyleOptionSlider::slot_map->find(str)) == DummyQStyleOptionSlider::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionComplex::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyleOptionSlider::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionSlider::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOptionComplex::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionSlider::connection(QObject *o)
{
	QStyleOptionSlider *p = dynamic_cast<QStyleOptionSlider*>(o);
	if (p != NULL) {
	}
	DummyQStyleOptionComplex::connection(o);
}

KQStyleOptionSlider::KQStyleOptionSlider() : QStyleOptionSlider()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQStyleOptionSlider();
}

KQStyleOptionSlider::~KQStyleOptionSlider()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QStyleOptionSlider_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionSlider *qp = RawPtr_to(KQStyleOptionSlider *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionSlider]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionSlider]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionSlider_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionSlider *qp = RawPtr_to(KQStyleOptionSlider *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionSlider]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionSlider]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionSlider_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQStyleOptionSlider *qp = (KQStyleOptionSlider *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QStyleOptionSlider*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QStyleOptionSlider_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQStyleOptionSlider *qp = (KQStyleOptionSlider *)p->rawptr;
		KQStyleOptionSlider *qp = static_cast<KQStyleOptionSlider*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionSlider_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionSlider::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionSliderConstInt[] = {
	{"Type", QStyleOptionSlider::Type},
	{"Version", QStyleOptionSlider::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionSlider(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionSliderConstInt);
}


DEFAPI(void) defQStyleOptionSlider(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionSlider";
	cdef->free = QStyleOptionSlider_free;
	cdef->reftrace = QStyleOptionSlider_reftrace;
	cdef->compareTo = QStyleOptionSlider_compareTo;
}


