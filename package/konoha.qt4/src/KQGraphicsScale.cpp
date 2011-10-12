//@Virtual @Override void QGraphicsScale.applyTo(QMatrix4x4 matrix);
KMETHOD QGraphicsScale_applyTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScale *  qp = RawPtr_to(QGraphicsScale *, sfp[0]);
	if (qp != NULL) {
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
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QGraphicsScale.setXScale(float arg0);
KMETHOD QGraphicsScale_setXScale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScale *  qp = RawPtr_to(QGraphicsScale *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		qreal ret_v = qp->zScale();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}


DummyQGraphicsScale::DummyQGraphicsScale()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
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

bool DummyQGraphicsScale::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsScale::event_map->bigin();
	if ((itr = DummyQGraphicsScale::event_map->find(str)) == DummyQGraphicsScale::event_map->end()) {
		bool ret;
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
	if ((itr = DummyQGraphicsScale::event_map->find(str)) == DummyQGraphicsScale::slot_map->end()) {
		bool ret;
		ret = DummyQGraphicsTransform::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQGraphicsScale::KQGraphicsScale(QObject* parent) : QGraphicsScale(parent)
{
	self = NULL;
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
		if (!qp->DummyQGraphicsScale::addEvent(callback_func, str)) {
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
		if (!qp->DummyQGraphicsScale::signalConnect(callback_func, str)) {
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
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQGraphicsScale *qp = (KQGraphicsScale *)p->rawptr;
		(void)qp;
	}
}

static int QGraphicsScale_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQGraphicsScale::event(QEvent *event)
{
	if (!DummyQGraphicsScale::eventDispatcher(event)) {
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


