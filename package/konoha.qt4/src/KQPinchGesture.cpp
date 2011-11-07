//QPointF QPinchGesture.getCenterPoint();
KMETHOD QPinchGesture_getCenterPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->centerPoint();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPinchGestureChangeFlags QPinchGesture.getChangeFlags();
KMETHOD QPinchGesture_getChangeFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		QPinchGesture::ChangeFlags ret_v = qp->changeFlags();
		QPinchGesture::ChangeFlags *ret_v_ = new QPinchGesture::ChangeFlags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QPinchGesture.getLastCenterPoint();
KMETHOD QPinchGesture_getLastCenterPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->lastCenterPoint();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QPinchGesture.getLastRotationAngle();
KMETHOD QPinchGesture_getLastRotationAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->lastRotationAngle();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QPinchGesture.getLastScaleFactor();
KMETHOD QPinchGesture_getLastScaleFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->lastScaleFactor();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QPinchGesture.getRotationAngle();
KMETHOD QPinchGesture_getRotationAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->rotationAngle();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QPinchGesture.getScaleFactor();
KMETHOD QPinchGesture_getScaleFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->scaleFactor();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QPinchGesture.setCenterPoint(QPointF value);
KMETHOD QPinchGesture_setCenterPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		const QPointF  value = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setCenterPoint(value);
	}
	RETURNvoid_();
}

//void QPinchGesture.setChangeFlags(QPinchGestureChangeFlags value);
KMETHOD QPinchGesture_setChangeFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		initFlag(value, QPinchGesture::ChangeFlags, sfp[1]);
		qp->setChangeFlags(value);
	}
	RETURNvoid_();
}

//void QPinchGesture.setLastCenterPoint(QPointF value);
KMETHOD QPinchGesture_setLastCenterPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		const QPointF  value = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setLastCenterPoint(value);
	}
	RETURNvoid_();
}

//void QPinchGesture.setLastRotationAngle(float value);
KMETHOD QPinchGesture_setLastRotationAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		qreal value = Float_to(qreal, sfp[1]);
		qp->setLastRotationAngle(value);
	}
	RETURNvoid_();
}

//void QPinchGesture.setLastScaleFactor(float value);
KMETHOD QPinchGesture_setLastScaleFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		qreal value = Float_to(qreal, sfp[1]);
		qp->setLastScaleFactor(value);
	}
	RETURNvoid_();
}

//void QPinchGesture.setRotationAngle(float value);
KMETHOD QPinchGesture_setRotationAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		qreal value = Float_to(qreal, sfp[1]);
		qp->setRotationAngle(value);
	}
	RETURNvoid_();
}

//void QPinchGesture.setScaleFactor(float value);
KMETHOD QPinchGesture_setScaleFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		qreal value = Float_to(qreal, sfp[1]);
		qp->setScaleFactor(value);
	}
	RETURNvoid_();
}

//void QPinchGesture.setStartCenterPoint(QPointF value);
KMETHOD QPinchGesture_setStartCenterPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		const QPointF  value = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setStartCenterPoint(value);
	}
	RETURNvoid_();
}

//void QPinchGesture.setTotalChangeFlags(QPinchGestureChangeFlags value);
KMETHOD QPinchGesture_setTotalChangeFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		initFlag(value, QPinchGesture::ChangeFlags, sfp[1]);
		qp->setTotalChangeFlags(value);
	}
	RETURNvoid_();
}

//void QPinchGesture.setTotalRotationAngle(float value);
KMETHOD QPinchGesture_setTotalRotationAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		qreal value = Float_to(qreal, sfp[1]);
		qp->setTotalRotationAngle(value);
	}
	RETURNvoid_();
}

//void QPinchGesture.setTotalScaleFactor(float value);
KMETHOD QPinchGesture_setTotalScaleFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		qreal value = Float_to(qreal, sfp[1]);
		qp->setTotalScaleFactor(value);
	}
	RETURNvoid_();
}

//QPointF QPinchGesture.getStartCenterPoint();
KMETHOD QPinchGesture_getStartCenterPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->startCenterPoint();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPinchGestureChangeFlags QPinchGesture.getTotalChangeFlags();
KMETHOD QPinchGesture_getTotalChangeFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		QPinchGesture::ChangeFlags ret_v = qp->totalChangeFlags();
		QPinchGesture::ChangeFlags *ret_v_ = new QPinchGesture::ChangeFlags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QPinchGesture.getTotalRotationAngle();
KMETHOD QPinchGesture_getTotalRotationAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->totalRotationAngle();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QPinchGesture.getTotalScaleFactor();
KMETHOD QPinchGesture_getTotalScaleFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture *  qp = RawPtr_to(QPinchGesture *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->totalScaleFactor();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}


DummyQPinchGesture::DummyQPinchGesture()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPinchGesture::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPinchGesture::self = ptr;
	DummyQGesture::setSelf(ptr);
}

bool DummyQPinchGesture::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGesture::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQPinchGesture::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPinchGesture::event_map->bigin();
	if ((itr = DummyQPinchGesture::event_map->find(str)) == DummyQPinchGesture::event_map->end()) {
		bool ret = false;
		ret = DummyQGesture::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPinchGesture::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPinchGesture::slot_map->bigin();
	if ((itr = DummyQPinchGesture::slot_map->find(str)) == DummyQPinchGesture::slot_map->end()) {
		bool ret = false;
		ret = DummyQGesture::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQPinchGesture::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQGesture::reftrace(ctx, p, tail_);
}

void DummyQPinchGesture::connection(QObject *o)
{
	QPinchGesture *p = dynamic_cast<QPinchGesture*>(o);
	if (p != NULL) {
	}
	DummyQGesture::connection(o);
}

KMETHOD QPinchGesture_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPinchGesture *qp = RawPtr_to(KQPinchGesture *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPinchGesture]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPinchGesture]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPinchGesture_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPinchGesture *qp = RawPtr_to(KQPinchGesture *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPinchGesture]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPinchGesture]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPinchGesture_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPinchGesture *qp = (KQPinchGesture *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPinchGesture_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQPinchGesture *qp = (KQPinchGesture *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPinchGesture_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQPinchGesture::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQPinchGesture::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QPinchGesture::event(event);
		return false;
	}
	return true;
}

static knh_IntData_t QPinchGestureConstInt[] = {
	{"ScaleFactorChanged", QPinchGesture::ScaleFactorChanged},
	{"RotationAngleChanged", QPinchGesture::RotationAngleChanged},
	{"CenterPointChanged", QPinchGesture::CenterPointChanged},
	{NULL, 0}
};

DEFAPI(void) constQPinchGesture(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QPinchGestureConstInt);
}


DEFAPI(void) defQPinchGesture(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPinchGesture";
	cdef->free = QPinchGesture_free;
	cdef->reftrace = QPinchGesture_reftrace;
	cdef->compareTo = QPinchGesture_compareTo;
}

//## QPinchGestureChangeFlags QPinchGestureChangeFlags.new(int value);
KMETHOD QPinchGestureChangeFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPinchGesture::ChangeFlag i = Int_to(QPinchGesture::ChangeFlag, sfp[1]);
	QPinchGesture::ChangeFlags *ret_v = new QPinchGesture::ChangeFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QPinchGestureChangeFlags QPinchGestureChangeFlags.and(int mask);
KMETHOD QPinchGestureChangeFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPinchGesture::ChangeFlags *qp = RawPtr_to(QPinchGesture::ChangeFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QPinchGesture::ChangeFlags ret = ((*qp) & i);
		QPinchGesture::ChangeFlags *ret_ = new QPinchGesture::ChangeFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPinchGestureChangeFlags QPinchGestureChangeFlags.iand(QPinchGesture::QPinchGestureChangeFlags other);
KMETHOD QPinchGestureChangeFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPinchGesture::ChangeFlags *qp = RawPtr_to(QPinchGesture::ChangeFlags*, sfp[0]);
	if (qp != NULL) {
		QPinchGesture::ChangeFlags *other = RawPtr_to(QPinchGesture::ChangeFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPinchGestureChangeFlags QPinchGestureChangeFlags.or(QPinchGestureChangeFlags f);
KMETHOD QPinchGestureChangeFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture::ChangeFlags *qp = RawPtr_to(QPinchGesture::ChangeFlags*, sfp[0]);
	if (qp != NULL) {
		QPinchGesture::ChangeFlags *f = RawPtr_to(QPinchGesture::ChangeFlags*, sfp[1]);
		QPinchGesture::ChangeFlags ret = ((*qp) | (*f));
		QPinchGesture::ChangeFlags *ret_ = new QPinchGesture::ChangeFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPinchGestureChangeFlags QPinchGestureChangeFlags.ior(QPinchGesture::QPinchGestureChangeFlags other);
KMETHOD QPinchGestureChangeFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPinchGesture::ChangeFlags *qp = RawPtr_to(QPinchGesture::ChangeFlags*, sfp[0]);
	if (qp != NULL) {
		QPinchGesture::ChangeFlags *other = RawPtr_to(QPinchGesture::ChangeFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPinchGestureChangeFlags QPinchGestureChangeFlags.xor(QPinchGestureChangeFlags f);
KMETHOD QPinchGestureChangeFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPinchGesture::ChangeFlags *qp = RawPtr_to(QPinchGesture::ChangeFlags*, sfp[0]);
	if (qp != NULL) {
		QPinchGesture::ChangeFlags *f = RawPtr_to(QPinchGesture::ChangeFlags*, sfp[1]);
		QPinchGesture::ChangeFlags ret = ((*qp) ^ (*f));
		QPinchGesture::ChangeFlags *ret_ = new QPinchGesture::ChangeFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPinchGestureChangeFlags QPinchGestureChangeFlags.ixor(QPinchGesture::QPinchGestureChangeFlags other);
KMETHOD QPinchGestureChangeFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPinchGesture::ChangeFlags *qp = RawPtr_to(QPinchGesture::ChangeFlags*, sfp[0]);
	if (qp != NULL) {
		QPinchGesture::ChangeFlags *other = RawPtr_to(QPinchGesture::ChangeFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QPinchGestureChangeFlags.testFlag(int flag);
KMETHOD QPinchGestureChangeFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPinchGesture::ChangeFlags *qp = RawPtr_to(QPinchGesture::ChangeFlags *, sfp[0]);
	if (qp != NULL) {
		QPinchGesture::ChangeFlag flag = Int_to(QPinchGesture::ChangeFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QPinchGestureChangeFlags.value();
KMETHOD QPinchGestureChangeFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPinchGesture::ChangeFlags *qp = RawPtr_to(QPinchGesture::ChangeFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QPinchGestureChangeFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QPinchGesture::ChangeFlags *qp = (QPinchGesture::ChangeFlags *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QPinchGestureChangeFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QPinchGesture::ChangeFlags *qp = (QPinchGesture::ChangeFlags *)p->rawptr;
		(void)qp;
	}
}

static int QPinchGestureChangeFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QPinchGesture::ChangeFlags*)p1->rawptr);
//		int v2 = int(*(QPinchGesture::ChangeFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QPinchGesture::ChangeFlags v1 = *(QPinchGesture::ChangeFlags*)p1->rawptr;
		QPinchGesture::ChangeFlags v2 = *(QPinchGesture::ChangeFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQPinchGestureChangeFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPinchGestureChangeFlags";
	cdef->free = QPinchGestureChangeFlags_free;
	cdef->reftrace = QPinchGestureChangeFlags_reftrace;
	cdef->compareTo = QPinchGestureChangeFlags_compareTo;
}

