//QStyleOptionFrameV2 QStyleOptionFrameV2.new();
KMETHOD QStyleOptionFrameV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionFrameV2 *ret_v = new KQStyleOptionFrameV2();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionFrameV2 QStyleOptionFrameV2.new(QStyleOptionFrameV2 other);
KMETHOD QStyleOptionFrameV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionFrameV2  other = *RawPtr_to(const QStyleOptionFrameV2 *, sfp[1]);
	KQStyleOptionFrameV2 *ret_v = new KQStyleOptionFrameV2(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QStyleOptionFrameV2 QStyleOptionFrameV2.new(QStyleOptionFrame other);
KMETHOD QStyleOptionFrameV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionFrame  other = *RawPtr_to(const QStyleOptionFrame *, sfp[1]);
	KQStyleOptionFrameV2 *ret_v = new KQStyleOptionFrameV2(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionFrameV2::DummyQStyleOptionFrameV2()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionFrameV2::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionFrameV2::self = ptr;
	DummyQStyleOptionFrame::setSelf(ptr);
}

bool DummyQStyleOptionFrameV2::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionFrame::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionFrameV2::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionFrameV2::event_map->bigin();
	if ((itr = DummyQStyleOptionFrameV2::event_map->find(str)) == DummyQStyleOptionFrameV2::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionFrame::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionFrameV2::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionFrameV2::slot_map->bigin();
	if ((itr = DummyQStyleOptionFrameV2::slot_map->find(str)) == DummyQStyleOptionFrameV2::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionFrame::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyleOptionFrameV2::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionFrameV2::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOptionFrame::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionFrameV2::connection(QObject *o)
{
	QStyleOptionFrameV2 *p = dynamic_cast<QStyleOptionFrameV2*>(o);
	if (p != NULL) {
	}
	DummyQStyleOptionFrame::connection(o);
}

KQStyleOptionFrameV2::KQStyleOptionFrameV2() : QStyleOptionFrameV2()
{
	self = NULL;
	dummy = new DummyQStyleOptionFrameV2();
}

KMETHOD QStyleOptionFrameV2_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionFrameV2 *qp = RawPtr_to(KQStyleOptionFrameV2 *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionFrameV2]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionFrameV2]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionFrameV2_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionFrameV2 *qp = RawPtr_to(KQStyleOptionFrameV2 *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionFrameV2]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionFrameV2]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionFrameV2_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionFrameV2 *qp = (KQStyleOptionFrameV2 *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionFrameV2_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQStyleOptionFrameV2 *qp = (KQStyleOptionFrameV2 *)p->rawptr;
//		KQStyleOptionFrameV2 *qp = static_cast<KQStyleOptionFrameV2*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionFrameV2_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionFrameV2::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionFrameV2ConstInt[] = {
	{"None", QStyleOptionFrameV2::None},
	{"Flat", QStyleOptionFrameV2::Flat},
	{"Version", QStyleOptionFrameV2::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionFrameV2(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionFrameV2ConstInt);
}


DEFAPI(void) defQStyleOptionFrameV2(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionFrameV2";
	cdef->free = QStyleOptionFrameV2_free;
	cdef->reftrace = QStyleOptionFrameV2_reftrace;
	cdef->compareTo = QStyleOptionFrameV2_compareTo;
}

//## QStyleOptionFrameV2FrameFeatures QStyleOptionFrameV2FrameFeatures.new(int value);
KMETHOD QStyleOptionFrameV2FrameFeatures_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionFrameV2::FrameFeature i = Int_to(QStyleOptionFrameV2::FrameFeature, sfp[1]);
	QStyleOptionFrameV2::FrameFeatures *ret_v = new QStyleOptionFrameV2::FrameFeatures(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QStyleOptionFrameV2FrameFeatures QStyleOptionFrameV2FrameFeatures.and(int mask);
KMETHOD QStyleOptionFrameV2FrameFeatures_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionFrameV2::FrameFeatures *qp = RawPtr_to(QStyleOptionFrameV2::FrameFeatures*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QStyleOptionFrameV2::FrameFeatures ret = ((*qp) & i);
		QStyleOptionFrameV2::FrameFeatures *ret_ = new QStyleOptionFrameV2::FrameFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionFrameV2FrameFeatures QStyleOptionFrameV2FrameFeatures.iand(QStyleOptionFrameV2::QStyleOptionFrameV2FrameFeatures other);
KMETHOD QStyleOptionFrameV2FrameFeatures_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionFrameV2::FrameFeatures *qp = RawPtr_to(QStyleOptionFrameV2::FrameFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionFrameV2::FrameFeatures *other = RawPtr_to(QStyleOptionFrameV2::FrameFeatures *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionFrameV2FrameFeatures QStyleOptionFrameV2FrameFeatures.or(QStyleOptionFrameV2FrameFeatures f);
KMETHOD QStyleOptionFrameV2FrameFeatures_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyleOptionFrameV2::FrameFeatures *qp = RawPtr_to(QStyleOptionFrameV2::FrameFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionFrameV2::FrameFeatures *f = RawPtr_to(QStyleOptionFrameV2::FrameFeatures*, sfp[1]);
		QStyleOptionFrameV2::FrameFeatures ret = ((*qp) | (*f));
		QStyleOptionFrameV2::FrameFeatures *ret_ = new QStyleOptionFrameV2::FrameFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionFrameV2FrameFeatures QStyleOptionFrameV2FrameFeatures.ior(QStyleOptionFrameV2::QStyleOptionFrameV2FrameFeatures other);
KMETHOD QStyleOptionFrameV2FrameFeatures_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionFrameV2::FrameFeatures *qp = RawPtr_to(QStyleOptionFrameV2::FrameFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionFrameV2::FrameFeatures *other = RawPtr_to(QStyleOptionFrameV2::FrameFeatures *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionFrameV2FrameFeatures QStyleOptionFrameV2FrameFeatures.xor(QStyleOptionFrameV2FrameFeatures f);
KMETHOD QStyleOptionFrameV2FrameFeatures_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyleOptionFrameV2::FrameFeatures *qp = RawPtr_to(QStyleOptionFrameV2::FrameFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionFrameV2::FrameFeatures *f = RawPtr_to(QStyleOptionFrameV2::FrameFeatures*, sfp[1]);
		QStyleOptionFrameV2::FrameFeatures ret = ((*qp) ^ (*f));
		QStyleOptionFrameV2::FrameFeatures *ret_ = new QStyleOptionFrameV2::FrameFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionFrameV2FrameFeatures QStyleOptionFrameV2FrameFeatures.ixor(QStyleOptionFrameV2::QStyleOptionFrameV2FrameFeatures other);
KMETHOD QStyleOptionFrameV2FrameFeatures_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionFrameV2::FrameFeatures *qp = RawPtr_to(QStyleOptionFrameV2::FrameFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionFrameV2::FrameFeatures *other = RawPtr_to(QStyleOptionFrameV2::FrameFeatures *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QStyleOptionFrameV2FrameFeatures.testFlag(int flag);
KMETHOD QStyleOptionFrameV2FrameFeatures_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionFrameV2::FrameFeatures *qp = RawPtr_to(QStyleOptionFrameV2::FrameFeatures *, sfp[0]);
	if (qp != NULL) {
		QStyleOptionFrameV2::FrameFeature flag = Int_to(QStyleOptionFrameV2::FrameFeature, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QStyleOptionFrameV2FrameFeatures.value();
KMETHOD QStyleOptionFrameV2FrameFeatures_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionFrameV2::FrameFeatures *qp = RawPtr_to(QStyleOptionFrameV2::FrameFeatures *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QStyleOptionFrameV2FrameFeatures_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QStyleOptionFrameV2::FrameFeatures *qp = (QStyleOptionFrameV2::FrameFeatures *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QStyleOptionFrameV2FrameFeatures_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QStyleOptionFrameV2::FrameFeatures *qp = (QStyleOptionFrameV2::FrameFeatures *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionFrameV2FrameFeatures_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QStyleOptionFrameV2::FrameFeatures*)p1->rawptr);
//		int v2 = int(*(QStyleOptionFrameV2::FrameFeatures*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QStyleOptionFrameV2::FrameFeatures v1 = *(QStyleOptionFrameV2::FrameFeatures*)p1->rawptr;
		QStyleOptionFrameV2::FrameFeatures v2 = *(QStyleOptionFrameV2::FrameFeatures*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQStyleOptionFrameV2FrameFeatures(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionFrameV2FrameFeatures";
	cdef->free = QStyleOptionFrameV2FrameFeatures_free;
	cdef->reftrace = QStyleOptionFrameV2FrameFeatures_reftrace;
	cdef->compareTo = QStyleOptionFrameV2FrameFeatures_compareTo;
}

