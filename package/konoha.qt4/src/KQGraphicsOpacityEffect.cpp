//QGraphicsOpacityEffect QGraphicsOpacityEffect.new(QObject parent);
KMETHOD QGraphicsOpacityEffect_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQGraphicsOpacityEffect *ret_v = new KQGraphicsOpacityEffect(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//float QGraphicsOpacityEffect.getOpacity();
KMETHOD QGraphicsOpacityEffect_getOpacity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsOpacityEffect *  qp = RawPtr_to(QGraphicsOpacityEffect *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->opacity();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QBrush QGraphicsOpacityEffect.getOpacityMask();
KMETHOD QGraphicsOpacityEffect_getOpacityMask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsOpacityEffect *  qp = RawPtr_to(QGraphicsOpacityEffect *, sfp[0]);
	if (qp != NULL) {
		QBrush ret_v = qp->opacityMask();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsOpacityEffect.setOpacity(float opacity);
KMETHOD QGraphicsOpacityEffect_setOpacity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsOpacityEffect *  qp = RawPtr_to(QGraphicsOpacityEffect *, sfp[0]);
	if (qp != NULL) {
		qreal opacity = Float_to(qreal, sfp[1]);
		qp->setOpacity(opacity);
	}
	RETURNvoid_();
}

//void QGraphicsOpacityEffect.setOpacityMask(QBrush mask);
KMETHOD QGraphicsOpacityEffect_setOpacityMask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsOpacityEffect *  qp = RawPtr_to(QGraphicsOpacityEffect *, sfp[0]);
	if (qp != NULL) {
		const QBrush  mask = *RawPtr_to(const QBrush *, sfp[1]);
		qp->setOpacityMask(mask);
	}
	RETURNvoid_();
}


DummyQGraphicsOpacityEffect::DummyQGraphicsOpacityEffect()
{
	self = NULL;
	opacity_changed_func = NULL;
	opacity_mask_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("opacity-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("opacity-mask-changed", NULL));
}

void DummyQGraphicsOpacityEffect::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsOpacityEffect::self = ptr;
	DummyQGraphicsEffect::setSelf(ptr);
}

bool DummyQGraphicsOpacityEffect::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsEffect::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsOpacityEffect::opacityChangedSlot(qreal opacity)
{
	if (opacity_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, qreal, opacity);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, opacity_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsOpacityEffect::opacityMaskChangedSlot(const QBrush mask)
{
	if (opacity_mask_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QBrush, mask);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, opacity_mask_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsOpacityEffect::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsOpacityEffect::event_map->bigin();
	if ((itr = DummyQGraphicsOpacityEffect::event_map->find(str)) == DummyQGraphicsOpacityEffect::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsEffect::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsOpacityEffect::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsOpacityEffect::slot_map->bigin();
	if ((itr = DummyQGraphicsOpacityEffect::slot_map->find(str)) == DummyQGraphicsOpacityEffect::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsEffect::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		opacity_changed_func = (*slot_map)["opacity-changed"];
		opacity_mask_changed_func = (*slot_map)["opacity-mask-changed"];
		return true;
	}
}


void DummyQGraphicsOpacityEffect::connection(QObject *o)
{
	connect(o, SIGNAL(opacityChanged(qreal)), this, SLOT(opacityChangedSlot(qreal)));
	connect(o, SIGNAL(opacityMaskChanged(const QBrush)), this, SLOT(opacityMaskChangedSlot(const QBrush)));
	DummyQGraphicsEffect::connection(o);
}

KQGraphicsOpacityEffect::KQGraphicsOpacityEffect(QObject* parent) : QGraphicsOpacityEffect(parent)
{
	self = NULL;
	dummy = new DummyQGraphicsOpacityEffect();
	dummy->connection((QObject*)this);
}

KMETHOD QGraphicsOpacityEffect_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsOpacityEffect *qp = RawPtr_to(KQGraphicsOpacityEffect *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsOpacityEffect]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsOpacityEffect]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsOpacityEffect_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsOpacityEffect *qp = RawPtr_to(KQGraphicsOpacityEffect *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsOpacityEffect]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsOpacityEffect]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsOpacityEffect_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsOpacityEffect *qp = (KQGraphicsOpacityEffect *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsOpacityEffect_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQGraphicsOpacityEffect *qp = (KQGraphicsOpacityEffect *)p->rawptr;
//		(void)qp;
		if (qp->dummy->opacity_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->opacity_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->opacity_mask_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->opacity_mask_changed_func);
			KNH_SIZEREF(ctx);
		}
	}
}

static int QGraphicsOpacityEffect_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsOpacityEffect::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGraphicsOpacityEffect::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGraphicsOpacityEffect::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQGraphicsOpacityEffect(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsOpacityEffect";
	cdef->free = QGraphicsOpacityEffect_free;
	cdef->reftrace = QGraphicsOpacityEffect_reftrace;
	cdef->compareTo = QGraphicsOpacityEffect_compareTo;
}


