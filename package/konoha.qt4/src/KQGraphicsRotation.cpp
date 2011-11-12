//@Virtual @Override void QGraphicsRotation.applyTo(QMatrix4x4 matrix);
KMETHOD QGraphicsRotation_applyTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsRotation *  qp = RawPtr_to(QGraphicsRotation *, sfp[0]);
	if (qp) {
		QMatrix4x4*  matrix = RawPtr_to(QMatrix4x4*, sfp[1]);
		qp->applyTo(matrix);
	}
	RETURNvoid_();
}

//QGraphicsRotation QGraphicsRotation.new(QObject parent);
KMETHOD QGraphicsRotation_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQGraphicsRotation *ret_v = new KQGraphicsRotation(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//float QGraphicsRotation.getAngle();
KMETHOD QGraphicsRotation_getAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsRotation *  qp = RawPtr_to(QGraphicsRotation *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->angle();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QGraphicsRotation.setAngle(float arg0);
KMETHOD QGraphicsRotation_setAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsRotation *  qp = RawPtr_to(QGraphicsRotation *, sfp[0]);
	if (qp) {
		qreal arg0 = Float_to(qreal, sfp[1]);
		qp->setAngle(arg0);
	}
	RETURNvoid_();
}

//void QGraphicsRotation.setAxis(int axis);
KMETHOD QGraphicsRotation_setAxis(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsRotation *  qp = RawPtr_to(QGraphicsRotation *, sfp[0]);
	if (qp) {
		Qt::Axis axis = Int_to(Qt::Axis, sfp[1]);
		qp->setAxis(axis);
	}
	RETURNvoid_();
}


DummyQGraphicsRotation::DummyQGraphicsRotation()
{
	self = NULL;
	angle_changed_func = NULL;
	axis_changed_func = NULL;
	origin_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("angle-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("axis-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("origin-changed", NULL));
}

void DummyQGraphicsRotation::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsRotation::self = ptr;
	DummyQGraphicsTransform::setSelf(ptr);
}

bool DummyQGraphicsRotation::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsTransform::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsRotation::angleChangedSlot()
{
	if (angle_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, angle_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQGraphicsRotation::axisChangedSlot()
{
	if (axis_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, axis_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQGraphicsRotation::originChangedSlot()
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

bool DummyQGraphicsRotation::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsRotation::event_map->bigin();
	if ((itr = DummyQGraphicsRotation::event_map->find(str)) == DummyQGraphicsRotation::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsTransform::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsRotation::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsRotation::slot_map->bigin();
	if ((itr = DummyQGraphicsRotation::slot_map->find(str)) == DummyQGraphicsRotation::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsTransform::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		angle_changed_func = (*slot_map)["angle-changed"];
		axis_changed_func = (*slot_map)["axis-changed"];
		origin_changed_func = (*slot_map)["origin-changed"];
		return true;
	}
}

knh_Object_t** DummyQGraphicsRotation::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsRotation::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 3;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, angle_changed_func);
	KNH_ADDNNREF(ctx, axis_changed_func);
	KNH_ADDNNREF(ctx, origin_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQGraphicsTransform::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGraphicsRotation::connection(QObject *o)
{
	QGraphicsRotation *p = dynamic_cast<QGraphicsRotation*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(angleChanged()), this, SLOT(angleChangedSlot()));
		connect(p, SIGNAL(axisChanged()), this, SLOT(axisChangedSlot()));
		connect(p, SIGNAL(originChanged()), this, SLOT(originChangedSlot()));
	}
	DummyQGraphicsTransform::connection(o);
}

KQGraphicsRotation::KQGraphicsRotation(QObject* parent) : QGraphicsRotation(parent)
{
	self = NULL;
	dummy = new DummyQGraphicsRotation();
	dummy->connection((QObject*)this);
}

KMETHOD QGraphicsRotation_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsRotation *qp = RawPtr_to(KQGraphicsRotation *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsRotation]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsRotation]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsRotation_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsRotation *qp = RawPtr_to(KQGraphicsRotation *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsRotation]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsRotation]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsRotation_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsRotation *qp = (KQGraphicsRotation *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsRotation_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGraphicsRotation *qp = (KQGraphicsRotation *)p->rawptr;
//		KQGraphicsRotation *qp = static_cast<KQGraphicsRotation*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsRotation_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsRotation::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGraphicsRotation::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGraphicsRotation::event(event);
		return false;
	}
//	QGraphicsRotation::event(event);
	return true;
}



DEFAPI(void) defQGraphicsRotation(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsRotation";
	cdef->free = QGraphicsRotation_free;
	cdef->reftrace = QGraphicsRotation_reftrace;
	cdef->compareTo = QGraphicsRotation_compareTo;
}


