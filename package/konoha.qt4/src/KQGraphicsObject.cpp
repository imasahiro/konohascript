//
//void QGraphicsObject.grabGesture(int gesture, int flags);
KMETHOD QGraphicsObject_grabGesture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsObject *  qp = RawPtr_to(QGraphicsObject *, sfp[0]);
	if (qp != NULL) {
		Qt::GestureType gesture = Int_to(Qt::GestureType, sfp[1]);
		Qt::GestureFlags flags = Int_to(Qt::GestureFlags, sfp[2]);
		qp->grabGesture(gesture, flags);
	}
	RETURNvoid_();
}

//void QGraphicsObject.ungrabGesture(int gesture);
KMETHOD QGraphicsObject_ungrabGesture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsObject *  qp = RawPtr_to(QGraphicsObject *, sfp[0]);
	if (qp != NULL) {
		Qt::GestureType gesture = Int_to(Qt::GestureType, sfp[1]);
		qp->ungrabGesture(gesture);
	}
	RETURNvoid_();
}


DummyQGraphicsObject::DummyQGraphicsObject()
{
	self = NULL;
	enabled_changed_func = NULL;
	opacity_changed_func = NULL;
	parent_changed_func = NULL;
	rotation_changed_func = NULL;
	scale_changed_func = NULL;
	visible_changed_func = NULL;
	x_changed_func = NULL;
	y_changed_func = NULL;
	z_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("enabled-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("opacity-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("parent-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("rotation-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("scale-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("visible-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("x-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("y-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("z-changed", NULL));
}

void DummyQGraphicsObject::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsObject::self = ptr;
	DummyQGraphicsItem::setSelf(ptr);
	DummyQObject::setSelf(ptr);
}

bool DummyQGraphicsObject::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsItem::eventDispatcher(event);
		if (ret) break;
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsObject::enabledChangedSlot()
{
	if (enabled_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, enabled_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQGraphicsObject::opacityChangedSlot()
{
	if (opacity_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, opacity_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQGraphicsObject::parentChangedSlot()
{
	if (parent_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, parent_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQGraphicsObject::rotationChangedSlot()
{
	if (rotation_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, rotation_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQGraphicsObject::scaleChangedSlot()
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

bool DummyQGraphicsObject::visibleChangedSlot()
{
	if (visible_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, visible_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQGraphicsObject::xChangedSlot()
{
	if (x_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, x_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQGraphicsObject::yChangedSlot()
{
	if (y_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, y_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQGraphicsObject::zChangedSlot()
{
	if (z_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, z_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQGraphicsObject::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsObject::event_map->bigin();
	if ((itr = DummyQGraphicsObject::event_map->find(str)) == DummyQGraphicsObject::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsItem::addEvent(callback_func, str);
		if (ret) return true;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsObject::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsObject::slot_map->bigin();
	if ((itr = DummyQGraphicsObject::slot_map->find(str)) == DummyQGraphicsObject::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsItem::signalConnect(callback_func, str);
		if (ret) return true;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		enabled_changed_func = (*slot_map)["enabled-changed"];
		opacity_changed_func = (*slot_map)["opacity-changed"];
		parent_changed_func = (*slot_map)["parent-changed"];
		rotation_changed_func = (*slot_map)["rotation-changed"];
		scale_changed_func = (*slot_map)["scale-changed"];
		visible_changed_func = (*slot_map)["visible-changed"];
		x_changed_func = (*slot_map)["x-changed"];
		y_changed_func = (*slot_map)["y-changed"];
		z_changed_func = (*slot_map)["z-changed"];
		return true;
	}
}


void DummyQGraphicsObject::connection(QObject *o)
{
	connect(o, SIGNAL(enabledChanged()), this, SLOT(enabledChangedSlot()));
	connect(o, SIGNAL(opacityChanged()), this, SLOT(opacityChangedSlot()));
	connect(o, SIGNAL(parentChanged()), this, SLOT(parentChangedSlot()));
	connect(o, SIGNAL(rotationChanged()), this, SLOT(rotationChangedSlot()));
	connect(o, SIGNAL(scaleChanged()), this, SLOT(scaleChangedSlot()));
	connect(o, SIGNAL(visibleChanged()), this, SLOT(visibleChangedSlot()));
	connect(o, SIGNAL(xChanged()), this, SLOT(xChangedSlot()));
	connect(o, SIGNAL(yChanged()), this, SLOT(yChangedSlot()));
	connect(o, SIGNAL(zChanged()), this, SLOT(zChangedSlot()));
	DummyQGraphicsItem::connection(o);
	DummyQObject::connection(o);
}

KQGraphicsObject::KQGraphicsObject(QGraphicsItem* parent) : QGraphicsObject(parent)
{
	self = NULL;
	dummy = new DummyQGraphicsObject();
	dummy->connection((QObject*)this);
}

KMETHOD QGraphicsObject_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsObject *qp = RawPtr_to(KQGraphicsObject *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsObject]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsObject]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsObject_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsObject *qp = RawPtr_to(KQGraphicsObject *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsObject]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsObject]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsObject_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsObject *qp = (KQGraphicsObject *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsObject_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 9;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQGraphicsObject *qp = (KQGraphicsObject *)p->rawptr;
//		(void)qp;
		if (qp->dummy->enabled_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->enabled_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->opacity_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->opacity_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->parent_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->parent_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->rotation_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->rotation_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->scale_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->scale_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->visible_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->visible_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->x_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->x_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->y_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->y_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->z_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->z_changed_func);
			KNH_SIZEREF(ctx);
		}
	}
}

static int QGraphicsObject_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsObject::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGraphicsObject::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGraphicsObject::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQGraphicsObject(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsObject";
	cdef->free = QGraphicsObject_free;
	cdef->reftrace = QGraphicsObject_reftrace;
	cdef->compareTo = QGraphicsObject_compareTo;
}


