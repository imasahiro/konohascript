//@Virtual @Override void QGraphicsScale.applyTo(QMatrix4x4 matrix);
KMETHOD QGraphicsScale_applyTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScale *  qp = RawPtr_to(QGraphicsScale *, sfp[0]);
	if (qp) {
		QMatrix4x4*  matrix = RawPtr_to(QMatrix4x4*, sfp[1]);
		qp->applyTo(matrix);
	}
	RETURNvoid_();
}

//QGraphicsScale QGraphicsScale.new(QObject parent);
KMETHOD QGraphicsScale_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQGraphicsScale *ret_v = new KQGraphicsScale(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QGraphicsScale.setXScale(float arg0);
KMETHOD QGraphicsScale_setXScale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScale *  qp = RawPtr_to(QGraphicsScale *, sfp[0]);
	if (qp) {
		qreal arg0 = Float_to(qreal, sfp[1]);
		qp->setXScale(arg0);
	}
	RETURNvoid_();
}

//void QGraphicsScale.setYScale(float arg0);
KMETHOD QGraphicsScale_setYScale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScale *  qp = RawPtr_to(QGraphicsScale *, sfp[0]);
	if (qp) {
		qreal arg0 = Float_to(qreal, sfp[1]);
		qp->setYScale(arg0);
	}
	RETURNvoid_();
}

//void QGraphicsScale.setZScale(float arg0);
KMETHOD QGraphicsScale_setZScale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScale *  qp = RawPtr_to(QGraphicsScale *, sfp[0]);
	if (qp) {
		qreal arg0 = Float_to(qreal, sfp[1]);
		qp->setZScale(arg0);
	}
	RETURNvoid_();
}

//float QGraphicsScale.getXScale();
KMETHOD QGraphicsScale_getXScale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScale *  qp = RawPtr_to(QGraphicsScale *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->xScale();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QGraphicsScale.getYScale();
KMETHOD QGraphicsScale_getYScale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScale *  qp = RawPtr_to(QGraphicsScale *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->yScale();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QGraphicsScale.getZScale();
KMETHOD QGraphicsScale_getZScale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScale *  qp = RawPtr_to(QGraphicsScale *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->zScale();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}


DummyQGraphicsScale::DummyQGraphicsScale()
{
	self = NULL;
	origin_changed_func = NULL;
	scale_changed_func = NULL;
	x_scale_changed_func = NULL;
	y_scale_changed_func = NULL;
	z_scale_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("origin-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("scale-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("x-scale-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("y-scale-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("z-scale-changed", NULL));
}

void DummyQGraphicsScale::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsScale::self = ptr;
	DummyQGraphicsTransform::setSelf(ptr);
}

bool DummyQGraphicsScale::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsTransform::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsScale::originChangedSlot()
{
	if (origin_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, origin_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQGraphicsScale::scaleChangedSlot()
{
	if (scale_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, scale_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQGraphicsScale::xScaleChangedSlot()
{
	if (x_scale_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, x_scale_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQGraphicsScale::yScaleChangedSlot()
{
	if (y_scale_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, y_scale_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQGraphicsScale::zScaleChangedSlot()
{
	if (z_scale_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, z_scale_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQGraphicsScale::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsScale::event_map->bigin();
	if ((itr = DummyQGraphicsScale::event_map->find(str)) == DummyQGraphicsScale::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsTransform::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsScale::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsScale::slot_map->bigin();
	if ((itr = DummyQGraphicsScale::slot_map->find(str)) == DummyQGraphicsScale::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsTransform::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		origin_changed_func = (*slot_map)["origin-changed"];
		scale_changed_func = (*slot_map)["scale-changed"];
		x_scale_changed_func = (*slot_map)["x-scale-changed"];
		y_scale_changed_func = (*slot_map)["y-scale-changed"];
		z_scale_changed_func = (*slot_map)["z-scale-changed"];
		return true;
	}
}

void DummyQGraphicsScale::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 5;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, origin_changed_func);
	KNH_ADDNNREF(ctx, scale_changed_func);
	KNH_ADDNNREF(ctx, x_scale_changed_func);
	KNH_ADDNNREF(ctx, y_scale_changed_func);
	KNH_ADDNNREF(ctx, z_scale_changed_func);

	KNH_SIZEREF(ctx);

	DummyQGraphicsTransform::reftrace(ctx, p, tail_);
}

void DummyQGraphicsScale::connection(QObject *o)
{
	QGraphicsScale *p = dynamic_cast<QGraphicsScale*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(originChanged()), this, SLOT(originChangedSlot()));
		connect(p, SIGNAL(scaleChanged()), this, SLOT(scaleChangedSlot()));
		connect(p, SIGNAL(xScaleChanged()), this, SLOT(xScaleChangedSlot()));
		connect(p, SIGNAL(yScaleChanged()), this, SLOT(yScaleChangedSlot()));
		connect(p, SIGNAL(zScaleChanged()), this, SLOT(zScaleChangedSlot()));
	}
	DummyQGraphicsTransform::connection(o);
}

KQGraphicsScale::KQGraphicsScale(QObject* parent) : QGraphicsScale(parent)
{
	self = NULL;
	dummy = new DummyQGraphicsScale();
	dummy->connection((QObject*)this);
}

KMETHOD QGraphicsScale_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsScale *qp = RawPtr_to(KQGraphicsScale *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsScale]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsScale]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsScale_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsScale *qp = RawPtr_to(KQGraphicsScale *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsScale]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsScale]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsScale_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsScale *qp = (KQGraphicsScale *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsScale_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGraphicsScale *qp = (KQGraphicsScale *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsScale_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsScale::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGraphicsScale::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGraphicsScale::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQGraphicsScale(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsScale";
	cdef->free = QGraphicsScale_free;
	cdef->reftrace = QGraphicsScale_reftrace;
	cdef->compareTo = QGraphicsScale_compareTo;
}


