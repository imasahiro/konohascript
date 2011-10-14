//
//QRectF QGraphicsEffect.boundingRect();
KMETHOD QGraphicsEffect_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEffect *  qp = RawPtr_to(QGraphicsEffect *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		qp->update();
	}
	RETURNvoid_();
}


DummyQGraphicsEffect::DummyQGraphicsEffect()
{
	self = NULL;
	enabled_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("enabled-changed", NULL));
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


void DummyQGraphicsEffect::connection(QObject *o)
{
	connect(o, SIGNAL(enabledChanged(bool)), this, SLOT(enabledChangedSlot(bool)));
	DummyQObject::connection(o);
}

KQGraphicsEffect::KQGraphicsEffect(QObject* parent) : QGraphicsEffect(parent)
{
	self = NULL;
	dummy = new DummyQGraphicsEffect();
	dummy->connection((QObject*)this);
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
	if (p->rawptr != NULL) {
		KQGraphicsEffect *qp = (KQGraphicsEffect *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsEffect_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 1;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQGraphicsEffect *qp = (KQGraphicsEffect *)p->rawptr;
//		(void)qp;
		if (qp->dummy->enabled_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->enabled_changed_func);
			KNH_SIZEREF(ctx);
		}
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
	return true;
}

DEFAPI(void) defQGraphicsEffect(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsEffect";
	cdef->free = QGraphicsEffect_free;
	cdef->reftrace = QGraphicsEffect_reftrace;
	cdef->compareTo = QGraphicsEffect_compareTo;
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

