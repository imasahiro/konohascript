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
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
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

bool DummyQGraphicsObject::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsObject::event_map->bigin();
	if ((itr = DummyQGraphicsObject::event_map->find(str)) == DummyQGraphicsObject::event_map->end()) {
		bool ret;
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
	if ((itr = DummyQGraphicsObject::event_map->find(str)) == DummyQGraphicsObject::slot_map->end()) {
		bool ret;
		ret = DummyQGraphicsItem::signalConnect(callback_func, str);
		if (ret) return true;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQGraphicsObject::KQGraphicsObject(QGraphicsItem* parent) : QGraphicsObject(parent)
{
	self = NULL;
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
		if (!qp->DummyQGraphicsObject::addEvent(callback_func, str)) {
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
		if (!qp->DummyQGraphicsObject::signalConnect(callback_func, str)) {
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
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQGraphicsObject *qp = (KQGraphicsObject *)p->rawptr;
		(void)qp;
	}
}

static int QGraphicsObject_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQGraphicsObject::event(QEvent *event)
{
	if (!DummyQGraphicsObject::eventDispatcher(event)) {
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


