//
//QRectF QGraphicsEffect.boundingRect();
KMETHOD QGraphicsEffect_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEffect *  qp = RawPtr_to(QGraphicsEffect *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->boundingRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QRectF QGraphicsEffect.boundingRectFor(QRectF rect);
KMETHOD QGraphicsEffect_boundingRectFor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEffect *  qp = RawPtr_to(QGraphicsEffect *, sfp[0]);
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

//boolean QGraphicsEffect.isEnabled();
KMETHOD QGraphicsEffect_isEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEffect *  qp = RawPtr_to(QGraphicsEffect *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGraphicsEffect.setEnabled(boolean enable);
KMETHOD QGraphicsEffect_setEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEffect *  qp = RawPtr_to(QGraphicsEffect *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setEnabled(enable);
	}
	RETURNvoid_();
}

//void QGraphicsEffect.update();
KMETHOD QGraphicsEffect_update(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEffect *  qp = RawPtr_to(QGraphicsEffect *, sfp[0]);
	if (qp) {
		qp->update();
	}
	RETURNvoid_();
}


DummyQGraphicsEffect::DummyQGraphicsEffect()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	enabled_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("enabled-changed", NULL));
}
DummyQGraphicsEffect::~DummyQGraphicsEffect()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQGraphicsEffect::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsEffect::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQGraphicsEffect::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsEffect::enabledChangedSlot(bool enabled)
{
	if (enabled_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = enabled;
		knh_Func_invoke(lctx, enabled_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsEffect::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsEffect::event_map->bigin();
	if ((itr = DummyQGraphicsEffect::event_map->find(str)) == DummyQGraphicsEffect::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsEffect::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsEffect::slot_map->bigin();
	if ((itr = DummyQGraphicsEffect::slot_map->find(str)) == DummyQGraphicsEffect::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		enabled_changed_func = (*slot_map)["enabled-changed"];
		return true;
	}
}

knh_Object_t** DummyQGraphicsEffect::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsEffect::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, enabled_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGraphicsEffect::connection(QObject *o)
{
	QGraphicsEffect *p = dynamic_cast<QGraphicsEffect*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(enabledChanged(bool)), this, SLOT(enabledChangedSlot(bool)));
	}
	DummyQObject::connection(o);
}

KQGraphicsEffect::KQGraphicsEffect(QObject* parent) : QGraphicsEffect(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQGraphicsEffect();
	dummy->connection((QObject*)this);
}

KQGraphicsEffect::~KQGraphicsEffect()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QGraphicsEffect_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsEffect *qp = RawPtr_to(KQGraphicsEffect *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsEffect]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsEffect]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsEffect_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsEffect *qp = RawPtr_to(KQGraphicsEffect *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsEffect]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsEffect]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsEffect_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQGraphicsEffect *qp = (KQGraphicsEffect *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QGraphicsEffect*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QGraphicsEffect_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQGraphicsEffect *qp = (KQGraphicsEffect *)p->rawptr;
		KQGraphicsEffect *qp = static_cast<KQGraphicsEffect*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsEffect_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsEffect::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGraphicsEffect::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGraphicsEffect::event(event);
		return false;
	}
//	QGraphicsEffect::event(event);
	return true;
}

static knh_IntData_t QGraphicsEffectConstInt[] = {
	{"SourceAttached", QGraphicsEffect::SourceAttached},
	{"SourceDetached", QGraphicsEffect::SourceDetached},
	{"SourceBoundingRectChanged", QGraphicsEffect::SourceBoundingRectChanged},
	{"SourceInvalidated", QGraphicsEffect::SourceInvalidated},
	{"NoPad", QGraphicsEffect::NoPad},
	{"PadToTransparentBorder", QGraphicsEffect::PadToTransparentBorder},
	{"PadToEffectiveBoundingRect", QGraphicsEffect::PadToEffectiveBoundingRect},
	{NULL, 0}
};

DEFAPI(void) constQGraphicsEffect(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QGraphicsEffectConstInt);
}


DEFAPI(void) defQGraphicsEffect(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsEffect";
	cdef->free = QGraphicsEffect_free;
	cdef->reftrace = QGraphicsEffect_reftrace;
	cdef->compareTo = QGraphicsEffect_compareTo;
}

//## QGraphicsEffectChangeFlags QGraphicsEffectChangeFlags.new(int value);
KMETHOD QGraphicsEffectChangeFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsEffect::ChangeFlag i = Int_to(QGraphicsEffect::ChangeFlag, sfp[1]);
	QGraphicsEffect::ChangeFlags *ret_v = new QGraphicsEffect::ChangeFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QGraphicsEffectChangeFlags QGraphicsEffectChangeFlags.and(int mask);
KMETHOD QGraphicsEffectChangeFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsEffect::ChangeFlags *qp = RawPtr_to(QGraphicsEffect::ChangeFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QGraphicsEffect::ChangeFlags ret = ((*qp) & i);
		QGraphicsEffect::ChangeFlags *ret_ = new QGraphicsEffect::ChangeFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGraphicsEffectChangeFlags QGraphicsEffectChangeFlags.iand(QGraphicsEffect::QGraphicsEffectChangeFlags other);
KMETHOD QGraphicsEffectChangeFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsEffect::ChangeFlags *qp = RawPtr_to(QGraphicsEffect::ChangeFlags*, sfp[0]);
	if (qp != NULL) {
		QGraphicsEffect::ChangeFlags *other = RawPtr_to(QGraphicsEffect::ChangeFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGraphicsEffectChangeFlags QGraphicsEffectChangeFlags.or(QGraphicsEffectChangeFlags f);
KMETHOD QGraphicsEffectChangeFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEffect::ChangeFlags *qp = RawPtr_to(QGraphicsEffect::ChangeFlags*, sfp[0]);
	if (qp != NULL) {
		QGraphicsEffect::ChangeFlags *f = RawPtr_to(QGraphicsEffect::ChangeFlags*, sfp[1]);
		QGraphicsEffect::ChangeFlags ret = ((*qp) | (*f));
		QGraphicsEffect::ChangeFlags *ret_ = new QGraphicsEffect::ChangeFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGraphicsEffectChangeFlags QGraphicsEffectChangeFlags.ior(QGraphicsEffect::QGraphicsEffectChangeFlags other);
KMETHOD QGraphicsEffectChangeFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsEffect::ChangeFlags *qp = RawPtr_to(QGraphicsEffect::ChangeFlags*, sfp[0]);
	if (qp != NULL) {
		QGraphicsEffect::ChangeFlags *other = RawPtr_to(QGraphicsEffect::ChangeFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGraphicsEffectChangeFlags QGraphicsEffectChangeFlags.xor(QGraphicsEffectChangeFlags f);
KMETHOD QGraphicsEffectChangeFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEffect::ChangeFlags *qp = RawPtr_to(QGraphicsEffect::ChangeFlags*, sfp[0]);
	if (qp != NULL) {
		QGraphicsEffect::ChangeFlags *f = RawPtr_to(QGraphicsEffect::ChangeFlags*, sfp[1]);
		QGraphicsEffect::ChangeFlags ret = ((*qp) ^ (*f));
		QGraphicsEffect::ChangeFlags *ret_ = new QGraphicsEffect::ChangeFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGraphicsEffectChangeFlags QGraphicsEffectChangeFlags.ixor(QGraphicsEffect::QGraphicsEffectChangeFlags other);
KMETHOD QGraphicsEffectChangeFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsEffect::ChangeFlags *qp = RawPtr_to(QGraphicsEffect::ChangeFlags*, sfp[0]);
	if (qp != NULL) {
		QGraphicsEffect::ChangeFlags *other = RawPtr_to(QGraphicsEffect::ChangeFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QGraphicsEffectChangeFlags.testFlag(int flag);
KMETHOD QGraphicsEffectChangeFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsEffect::ChangeFlags *qp = RawPtr_to(QGraphicsEffect::ChangeFlags *, sfp[0]);
	if (qp != NULL) {
		QGraphicsEffect::ChangeFlag flag = Int_to(QGraphicsEffect::ChangeFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QGraphicsEffectChangeFlags.value();
KMETHOD QGraphicsEffectChangeFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsEffect::ChangeFlags *qp = RawPtr_to(QGraphicsEffect::ChangeFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QGraphicsEffectChangeFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QGraphicsEffect::ChangeFlags *qp = (QGraphicsEffect::ChangeFlags *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QGraphicsEffectChangeFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QGraphicsEffect::ChangeFlags *qp = (QGraphicsEffect::ChangeFlags *)p->rawptr;
		(void)qp;
	}
}

static int QGraphicsEffectChangeFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QGraphicsEffect::ChangeFlags*)p1->rawptr);
//		int v2 = int(*(QGraphicsEffect::ChangeFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QGraphicsEffect::ChangeFlags v1 = *(QGraphicsEffect::ChangeFlags*)p1->rawptr;
		QGraphicsEffect::ChangeFlags v2 = *(QGraphicsEffect::ChangeFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQGraphicsEffectChangeFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsEffectChangeFlags";
	cdef->free = QGraphicsEffectChangeFlags_free;
	cdef->reftrace = QGraphicsEffectChangeFlags_reftrace;
	cdef->compareTo = QGraphicsEffectChangeFlags_compareTo;
}

