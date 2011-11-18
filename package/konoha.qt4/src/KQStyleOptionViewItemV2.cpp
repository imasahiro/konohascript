//QStyleOptionViewItemV2 QStyleOptionViewItemV2.new();
KMETHOD QStyleOptionViewItemV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionViewItemV2 *ret_v = new KQStyleOptionViewItemV2();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionViewItemV2 QStyleOptionViewItemV2.new(QStyleOptionViewItemV2 other);
KMETHOD QStyleOptionViewItemV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionViewItemV2  other = *RawPtr_to(const QStyleOptionViewItemV2 *, sfp[1]);
	KQStyleOptionViewItemV2 *ret_v = new KQStyleOptionViewItemV2(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QStyleOptionViewItemV2 QStyleOptionViewItemV2.new(QStyleOptionViewItem other);
KMETHOD QStyleOptionViewItemV2_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionViewItem  other = *RawPtr_to(const QStyleOptionViewItem *, sfp[1]);
	KQStyleOptionViewItemV2 *ret_v = new KQStyleOptionViewItemV2(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionViewItemV2::DummyQStyleOptionViewItemV2()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQStyleOptionViewItemV2::~DummyQStyleOptionViewItemV2()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQStyleOptionViewItemV2::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionViewItemV2::self = ptr;
	DummyQStyleOptionViewItem::setSelf(ptr);
}

bool DummyQStyleOptionViewItemV2::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionViewItem::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionViewItemV2::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionViewItemV2::event_map->bigin();
	if ((itr = DummyQStyleOptionViewItemV2::event_map->find(str)) == DummyQStyleOptionViewItemV2::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionViewItem::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionViewItemV2::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionViewItemV2::slot_map->bigin();
	if ((itr = DummyQStyleOptionViewItemV2::slot_map->find(str)) == DummyQStyleOptionViewItemV2::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionViewItem::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyleOptionViewItemV2::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionViewItemV2::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOptionViewItem::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionViewItemV2::connection(QObject *o)
{
	QStyleOptionViewItemV2 *p = dynamic_cast<QStyleOptionViewItemV2*>(o);
	if (p != NULL) {
	}
	DummyQStyleOptionViewItem::connection(o);
}

KQStyleOptionViewItemV2::KQStyleOptionViewItemV2() : QStyleOptionViewItemV2()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQStyleOptionViewItemV2();
}

KQStyleOptionViewItemV2::~KQStyleOptionViewItemV2()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QStyleOptionViewItemV2_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionViewItemV2 *qp = RawPtr_to(KQStyleOptionViewItemV2 *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionViewItemV2]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionViewItemV2]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionViewItemV2_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionViewItemV2 *qp = RawPtr_to(KQStyleOptionViewItemV2 *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionViewItemV2]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionViewItemV2]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionViewItemV2_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQStyleOptionViewItemV2 *qp = (KQStyleOptionViewItemV2 *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QStyleOptionViewItemV2*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QStyleOptionViewItemV2_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQStyleOptionViewItemV2 *qp = (KQStyleOptionViewItemV2 *)p->rawptr;
		KQStyleOptionViewItemV2 *qp = static_cast<KQStyleOptionViewItemV2*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionViewItemV2_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionViewItemV2::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionViewItemV2ConstInt[] = {
	{"Version", QStyleOptionViewItemV2::Version},
	{"None", QStyleOptionViewItemV2::None},
	{"WrapText", QStyleOptionViewItemV2::WrapText},
	{"Alternate", QStyleOptionViewItemV2::Alternate},
	{"HasCheckIndicator", QStyleOptionViewItemV2::HasCheckIndicator},
	{"HasDisplay", QStyleOptionViewItemV2::HasDisplay},
	{"HasDecoration", QStyleOptionViewItemV2::HasDecoration},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionViewItemV2(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionViewItemV2ConstInt);
}


DEFAPI(void) defQStyleOptionViewItemV2(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionViewItemV2";
	cdef->free = QStyleOptionViewItemV2_free;
	cdef->reftrace = QStyleOptionViewItemV2_reftrace;
	cdef->compareTo = QStyleOptionViewItemV2_compareTo;
}

//## QStyleOptionViewItemV2ViewItemFeatures QStyleOptionViewItemV2ViewItemFeatures.new(int value);
KMETHOD QStyleOptionViewItemV2ViewItemFeatures_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionViewItemV2::ViewItemFeature i = Int_to(QStyleOptionViewItemV2::ViewItemFeature, sfp[1]);
	QStyleOptionViewItemV2::ViewItemFeatures *ret_v = new QStyleOptionViewItemV2::ViewItemFeatures(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QStyleOptionViewItemV2ViewItemFeatures QStyleOptionViewItemV2ViewItemFeatures.and(int mask);
KMETHOD QStyleOptionViewItemV2ViewItemFeatures_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionViewItemV2::ViewItemFeatures *qp = RawPtr_to(QStyleOptionViewItemV2::ViewItemFeatures*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QStyleOptionViewItemV2::ViewItemFeatures ret = ((*qp) & i);
		QStyleOptionViewItemV2::ViewItemFeatures *ret_ = new QStyleOptionViewItemV2::ViewItemFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionViewItemV2ViewItemFeatures QStyleOptionViewItemV2ViewItemFeatures.iand(QStyleOptionViewItemV2::QStyleOptionViewItemV2ViewItemFeatures other);
KMETHOD QStyleOptionViewItemV2ViewItemFeatures_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionViewItemV2::ViewItemFeatures *qp = RawPtr_to(QStyleOptionViewItemV2::ViewItemFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionViewItemV2::ViewItemFeatures *other = RawPtr_to(QStyleOptionViewItemV2::ViewItemFeatures *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionViewItemV2ViewItemFeatures QStyleOptionViewItemV2ViewItemFeatures.or(QStyleOptionViewItemV2ViewItemFeatures f);
KMETHOD QStyleOptionViewItemV2ViewItemFeatures_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyleOptionViewItemV2::ViewItemFeatures *qp = RawPtr_to(QStyleOptionViewItemV2::ViewItemFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionViewItemV2::ViewItemFeatures *f = RawPtr_to(QStyleOptionViewItemV2::ViewItemFeatures*, sfp[1]);
		QStyleOptionViewItemV2::ViewItemFeatures ret = ((*qp) | (*f));
		QStyleOptionViewItemV2::ViewItemFeatures *ret_ = new QStyleOptionViewItemV2::ViewItemFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionViewItemV2ViewItemFeatures QStyleOptionViewItemV2ViewItemFeatures.ior(QStyleOptionViewItemV2::QStyleOptionViewItemV2ViewItemFeatures other);
KMETHOD QStyleOptionViewItemV2ViewItemFeatures_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionViewItemV2::ViewItemFeatures *qp = RawPtr_to(QStyleOptionViewItemV2::ViewItemFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionViewItemV2::ViewItemFeatures *other = RawPtr_to(QStyleOptionViewItemV2::ViewItemFeatures *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionViewItemV2ViewItemFeatures QStyleOptionViewItemV2ViewItemFeatures.xor(QStyleOptionViewItemV2ViewItemFeatures f);
KMETHOD QStyleOptionViewItemV2ViewItemFeatures_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyleOptionViewItemV2::ViewItemFeatures *qp = RawPtr_to(QStyleOptionViewItemV2::ViewItemFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionViewItemV2::ViewItemFeatures *f = RawPtr_to(QStyleOptionViewItemV2::ViewItemFeatures*, sfp[1]);
		QStyleOptionViewItemV2::ViewItemFeatures ret = ((*qp) ^ (*f));
		QStyleOptionViewItemV2::ViewItemFeatures *ret_ = new QStyleOptionViewItemV2::ViewItemFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionViewItemV2ViewItemFeatures QStyleOptionViewItemV2ViewItemFeatures.ixor(QStyleOptionViewItemV2::QStyleOptionViewItemV2ViewItemFeatures other);
KMETHOD QStyleOptionViewItemV2ViewItemFeatures_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionViewItemV2::ViewItemFeatures *qp = RawPtr_to(QStyleOptionViewItemV2::ViewItemFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionViewItemV2::ViewItemFeatures *other = RawPtr_to(QStyleOptionViewItemV2::ViewItemFeatures *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QStyleOptionViewItemV2ViewItemFeatures.testFlag(int flag);
KMETHOD QStyleOptionViewItemV2ViewItemFeatures_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionViewItemV2::ViewItemFeatures *qp = RawPtr_to(QStyleOptionViewItemV2::ViewItemFeatures *, sfp[0]);
	if (qp != NULL) {
		QStyleOptionViewItemV2::ViewItemFeature flag = Int_to(QStyleOptionViewItemV2::ViewItemFeature, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QStyleOptionViewItemV2ViewItemFeatures.value();
KMETHOD QStyleOptionViewItemV2ViewItemFeatures_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionViewItemV2::ViewItemFeatures *qp = RawPtr_to(QStyleOptionViewItemV2::ViewItemFeatures *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QStyleOptionViewItemV2ViewItemFeatures_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QStyleOptionViewItemV2::ViewItemFeatures *qp = (QStyleOptionViewItemV2::ViewItemFeatures *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QStyleOptionViewItemV2ViewItemFeatures_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QStyleOptionViewItemV2::ViewItemFeatures *qp = (QStyleOptionViewItemV2::ViewItemFeatures *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionViewItemV2ViewItemFeatures_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QStyleOptionViewItemV2::ViewItemFeatures*)p1->rawptr);
//		int v2 = int(*(QStyleOptionViewItemV2::ViewItemFeatures*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QStyleOptionViewItemV2::ViewItemFeatures v1 = *(QStyleOptionViewItemV2::ViewItemFeatures*)p1->rawptr;
		QStyleOptionViewItemV2::ViewItemFeatures v2 = *(QStyleOptionViewItemV2::ViewItemFeatures*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQStyleOptionViewItemV2ViewItemFeatures(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionViewItemV2ViewItemFeatures";
	cdef->free = QStyleOptionViewItemV2ViewItemFeatures_free;
	cdef->reftrace = QStyleOptionViewItemV2ViewItemFeatures_reftrace;
	cdef->compareTo = QStyleOptionViewItemV2ViewItemFeatures_compareTo;
}

