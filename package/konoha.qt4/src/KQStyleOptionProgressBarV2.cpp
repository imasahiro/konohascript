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
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQStyleOptionProgressBarV2::~DummyQStyleOptionProgressBarV2()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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

knh_Object_t** DummyQStyleOptionProgressBarV2::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionProgressBarV2::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOptionProgressBar::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionProgressBarV2::connection(QObject *o)
{
	QStyleOptionProgressBarV2 *p = dynamic_cast<QStyleOptionProgressBarV2*>(o);
	if (p != NULL) {
	}
	DummyQStyleOptionProgressBar::connection(o);
}

KQStyleOptionProgressBarV2::KQStyleOptionProgressBarV2() : QStyleOptionProgressBarV2()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQStyleOptionProgressBarV2();
}

KQStyleOptionProgressBarV2::~KQStyleOptionProgressBarV2()
{
	delete dummy;
	dummy = NULL;
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
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQStyleOptionProgressBarV2 *qp = (KQStyleOptionProgressBarV2 *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QStyleOptionProgressBarV2*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QStyleOptionProgressBarV2_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQStyleOptionProgressBarV2 *qp = (KQStyleOptionProgressBarV2 *)p->rawptr;
		KQStyleOptionProgressBarV2 *qp = static_cast<KQStyleOptionProgressBarV2*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
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

static knh_IntData_t QStyleOptionProgressBarV2ConstInt[] = {
	{"Type", QStyleOptionProgressBarV2::Type},
	{"Version", QStyleOptionProgressBarV2::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionProgressBarV2(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionProgressBarV2ConstInt);
}


DEFAPI(void) defQStyleOptionProgressBarV2(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionProgressBarV2";
	cdef->free = QStyleOptionProgressBarV2_free;
	cdef->reftrace = QStyleOptionProgressBarV2_reftrace;
	cdef->compareTo = QStyleOptionProgressBarV2_compareTo;
}


