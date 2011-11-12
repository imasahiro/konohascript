//@Virtual @Override QRectF QGraphicsBlurEffect.boundingRectFor(QRectF rect);
KMETHOD QGraphicsBlurEffect_boundingRectFor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsBlurEffect *  qp = RawPtr_to(QGraphicsBlurEffect *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		QRectF ret_v = qp->boundingRectFor(rect);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsBlurEffect QGraphicsBlurEffect.new(QObject parent);
KMETHOD QGraphicsBlurEffect_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQGraphicsBlurEffect *ret_v = new KQGraphicsBlurEffect(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QGraphicsBlurEffectBlurHints QGraphicsBlurEffect.getBlurHints();
KMETHOD QGraphicsBlurEffect_getBlurHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsBlurEffect *  qp = RawPtr_to(QGraphicsBlurEffect *, sfp[0]);
	if (qp) {
		QGraphicsBlurEffect::BlurHints ret_v = qp->blurHints();
		QGraphicsBlurEffect::BlurHints *ret_v_ = new QGraphicsBlurEffect::BlurHints(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QGraphicsBlurEffect.getBlurRadius();
KMETHOD QGraphicsBlurEffect_getBlurRadius(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsBlurEffect *  qp = RawPtr_to(QGraphicsBlurEffect *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->blurRadius();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QGraphicsBlurEffect.setBlurHints(QGraphicsBlurEffectBlurHints hints);
KMETHOD QGraphicsBlurEffect_setBlurHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsBlurEffect *  qp = RawPtr_to(QGraphicsBlurEffect *, sfp[0]);
	if (qp) {
		initFlag(hints, QGraphicsBlurEffect::BlurHints, sfp[1]);
		qp->setBlurHints(hints);
	}
	RETURNvoid_();
}

//void QGraphicsBlurEffect.setBlurRadius(float blurRadius);
KMETHOD QGraphicsBlurEffect_setBlurRadius(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsBlurEffect *  qp = RawPtr_to(QGraphicsBlurEffect *, sfp[0]);
	if (qp) {
		qreal blurRadius = Float_to(qreal, sfp[1]);
		qp->setBlurRadius(blurRadius);
	}
	RETURNvoid_();
}


DummyQGraphicsBlurEffect::DummyQGraphicsBlurEffect()
{
	self = NULL;
	blur_hints_changed_func = NULL;
	blur_radius_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("blur-hints-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("blur-radius-changed", NULL));
}

void DummyQGraphicsBlurEffect::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsBlurEffect::self = ptr;
	DummyQGraphicsEffect::setSelf(ptr);
}

bool DummyQGraphicsBlurEffect::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsEffect::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsBlurEffect::blurHintsChangedSlot(QGraphicsBlurEffect::BlurHints hints)
{
	if (blur_hints_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsBlurEffect::BlurHints, hints);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, blur_hints_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsBlurEffect::blurRadiusChangedSlot(qreal radius)
{
	if (blur_radius_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, qreal, radius);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, blur_radius_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsBlurEffect::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsBlurEffect::event_map->bigin();
	if ((itr = DummyQGraphicsBlurEffect::event_map->find(str)) == DummyQGraphicsBlurEffect::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsEffect::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsBlurEffect::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsBlurEffect::slot_map->bigin();
	if ((itr = DummyQGraphicsBlurEffect::slot_map->find(str)) == DummyQGraphicsBlurEffect::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsEffect::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		blur_hints_changed_func = (*slot_map)["blur-hints-changed"];
		blur_radius_changed_func = (*slot_map)["blur-radius-changed"];
		return true;
	}
}

knh_Object_t** DummyQGraphicsBlurEffect::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsBlurEffect::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, blur_hints_changed_func);
	KNH_ADDNNREF(ctx, blur_radius_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQGraphicsEffect::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGraphicsBlurEffect::connection(QObject *o)
{
	QGraphicsBlurEffect *p = dynamic_cast<QGraphicsBlurEffect*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(blurHintsChanged(QGraphicsBlurEffect::BlurHints)), this, SLOT(blurHintsChangedSlot(QGraphicsBlurEffect::BlurHints)));
		connect(p, SIGNAL(blurRadiusChanged(qreal)), this, SLOT(blurRadiusChangedSlot(qreal)));
	}
	DummyQGraphicsEffect::connection(o);
}

KQGraphicsBlurEffect::KQGraphicsBlurEffect(QObject* parent) : QGraphicsBlurEffect(parent)
{
	self = NULL;
	dummy = new DummyQGraphicsBlurEffect();
	dummy->connection((QObject*)this);
}

KMETHOD QGraphicsBlurEffect_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsBlurEffect *qp = RawPtr_to(KQGraphicsBlurEffect *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsBlurEffect]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsBlurEffect]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsBlurEffect_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsBlurEffect *qp = RawPtr_to(KQGraphicsBlurEffect *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsBlurEffect]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsBlurEffect]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsBlurEffect_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsBlurEffect *qp = (KQGraphicsBlurEffect *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsBlurEffect_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGraphicsBlurEffect *qp = (KQGraphicsBlurEffect *)p->rawptr;
//		KQGraphicsBlurEffect *qp = static_cast<KQGraphicsBlurEffect*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsBlurEffect_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsBlurEffect::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGraphicsBlurEffect::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGraphicsBlurEffect::event(event);
		return false;
	}
//	QGraphicsBlurEffect::event(event);
	return true;
}

static knh_IntData_t QGraphicsBlurEffectConstInt[] = {
	{"PerformanceHint", QGraphicsBlurEffect::PerformanceHint},
	{"QualityHint", QGraphicsBlurEffect::QualityHint},
	{"AnimationHint", QGraphicsBlurEffect::AnimationHint},
	{NULL, 0}
};

DEFAPI(void) constQGraphicsBlurEffect(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QGraphicsBlurEffectConstInt);
}


DEFAPI(void) defQGraphicsBlurEffect(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsBlurEffect";
	cdef->free = QGraphicsBlurEffect_free;
	cdef->reftrace = QGraphicsBlurEffect_reftrace;
	cdef->compareTo = QGraphicsBlurEffect_compareTo;
}

//## QGraphicsBlurEffectBlurHints QGraphicsBlurEffectBlurHints.new(int value);
KMETHOD QGraphicsBlurEffectBlurHints_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsBlurEffect::BlurHint i = Int_to(QGraphicsBlurEffect::BlurHint, sfp[1]);
	QGraphicsBlurEffect::BlurHints *ret_v = new QGraphicsBlurEffect::BlurHints(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QGraphicsBlurEffectBlurHints QGraphicsBlurEffectBlurHints.and(int mask);
KMETHOD QGraphicsBlurEffectBlurHints_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsBlurEffect::BlurHints *qp = RawPtr_to(QGraphicsBlurEffect::BlurHints*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QGraphicsBlurEffect::BlurHints ret = ((*qp) & i);
		QGraphicsBlurEffect::BlurHints *ret_ = new QGraphicsBlurEffect::BlurHints(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGraphicsBlurEffectBlurHints QGraphicsBlurEffectBlurHints.iand(QGraphicsBlurEffect::QGraphicsBlurEffectBlurHints other);
KMETHOD QGraphicsBlurEffectBlurHints_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsBlurEffect::BlurHints *qp = RawPtr_to(QGraphicsBlurEffect::BlurHints*, sfp[0]);
	if (qp != NULL) {
		QGraphicsBlurEffect::BlurHints *other = RawPtr_to(QGraphicsBlurEffect::BlurHints *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGraphicsBlurEffectBlurHints QGraphicsBlurEffectBlurHints.or(QGraphicsBlurEffectBlurHints f);
KMETHOD QGraphicsBlurEffectBlurHints_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsBlurEffect::BlurHints *qp = RawPtr_to(QGraphicsBlurEffect::BlurHints*, sfp[0]);
	if (qp != NULL) {
		QGraphicsBlurEffect::BlurHints *f = RawPtr_to(QGraphicsBlurEffect::BlurHints*, sfp[1]);
		QGraphicsBlurEffect::BlurHints ret = ((*qp) | (*f));
		QGraphicsBlurEffect::BlurHints *ret_ = new QGraphicsBlurEffect::BlurHints(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGraphicsBlurEffectBlurHints QGraphicsBlurEffectBlurHints.ior(QGraphicsBlurEffect::QGraphicsBlurEffectBlurHints other);
KMETHOD QGraphicsBlurEffectBlurHints_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsBlurEffect::BlurHints *qp = RawPtr_to(QGraphicsBlurEffect::BlurHints*, sfp[0]);
	if (qp != NULL) {
		QGraphicsBlurEffect::BlurHints *other = RawPtr_to(QGraphicsBlurEffect::BlurHints *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGraphicsBlurEffectBlurHints QGraphicsBlurEffectBlurHints.xor(QGraphicsBlurEffectBlurHints f);
KMETHOD QGraphicsBlurEffectBlurHints_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsBlurEffect::BlurHints *qp = RawPtr_to(QGraphicsBlurEffect::BlurHints*, sfp[0]);
	if (qp != NULL) {
		QGraphicsBlurEffect::BlurHints *f = RawPtr_to(QGraphicsBlurEffect::BlurHints*, sfp[1]);
		QGraphicsBlurEffect::BlurHints ret = ((*qp) ^ (*f));
		QGraphicsBlurEffect::BlurHints *ret_ = new QGraphicsBlurEffect::BlurHints(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGraphicsBlurEffectBlurHints QGraphicsBlurEffectBlurHints.ixor(QGraphicsBlurEffect::QGraphicsBlurEffectBlurHints other);
KMETHOD QGraphicsBlurEffectBlurHints_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsBlurEffect::BlurHints *qp = RawPtr_to(QGraphicsBlurEffect::BlurHints*, sfp[0]);
	if (qp != NULL) {
		QGraphicsBlurEffect::BlurHints *other = RawPtr_to(QGraphicsBlurEffect::BlurHints *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QGraphicsBlurEffectBlurHints.testFlag(int flag);
KMETHOD QGraphicsBlurEffectBlurHints_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsBlurEffect::BlurHints *qp = RawPtr_to(QGraphicsBlurEffect::BlurHints *, sfp[0]);
	if (qp != NULL) {
		QGraphicsBlurEffect::BlurHint flag = Int_to(QGraphicsBlurEffect::BlurHint, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QGraphicsBlurEffectBlurHints.value();
KMETHOD QGraphicsBlurEffectBlurHints_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsBlurEffect::BlurHints *qp = RawPtr_to(QGraphicsBlurEffect::BlurHints *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QGraphicsBlurEffectBlurHints_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QGraphicsBlurEffect::BlurHints *qp = (QGraphicsBlurEffect::BlurHints *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QGraphicsBlurEffectBlurHints_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QGraphicsBlurEffect::BlurHints *qp = (QGraphicsBlurEffect::BlurHints *)p->rawptr;
		(void)qp;
	}
}

static int QGraphicsBlurEffectBlurHints_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QGraphicsBlurEffect::BlurHints*)p1->rawptr);
//		int v2 = int(*(QGraphicsBlurEffect::BlurHints*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QGraphicsBlurEffect::BlurHints v1 = *(QGraphicsBlurEffect::BlurHints*)p1->rawptr;
		QGraphicsBlurEffect::BlurHints v2 = *(QGraphicsBlurEffect::BlurHints*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQGraphicsBlurEffectBlurHints(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsBlurEffectBlurHints";
	cdef->free = QGraphicsBlurEffectBlurHints_free;
	cdef->reftrace = QGraphicsBlurEffectBlurHints_reftrace;
	cdef->compareTo = QGraphicsBlurEffectBlurHints_compareTo;
}

