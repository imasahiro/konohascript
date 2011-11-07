//QEasingCurve QEasingCurve.new(int type);
KMETHOD QEasingCurve_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEasingCurve::Type type = Int_to(QEasingCurve::Type, sfp[1]);
	KQEasingCurve *ret_v = new KQEasingCurve(type);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QEasingCurve QEasingCurve.new(QEasingCurve other);
KMETHOD QEasingCurve_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QEasingCurve  other = *RawPtr_to(const QEasingCurve *, sfp[1]);
	KQEasingCurve *ret_v = new KQEasingCurve(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//float QEasingCurve.getAmplitude();
KMETHOD QEasingCurve_getAmplitude(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEasingCurve *  qp = RawPtr_to(QEasingCurve *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->amplitude();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QEasingCurve.getOvershoot();
KMETHOD QEasingCurve_getOvershoot(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEasingCurve *  qp = RawPtr_to(QEasingCurve *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->overshoot();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QEasingCurve.getPeriod();
KMETHOD QEasingCurve_getPeriod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEasingCurve *  qp = RawPtr_to(QEasingCurve *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->period();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QEasingCurve.setAmplitude(float amplitude);
KMETHOD QEasingCurve_setAmplitude(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEasingCurve *  qp = RawPtr_to(QEasingCurve *, sfp[0]);
	if (qp) {
		qreal amplitude = Float_to(qreal, sfp[1]);
		qp->setAmplitude(amplitude);
	}
	RETURNvoid_();
}

//void QEasingCurve.setOvershoot(float overshoot);
KMETHOD QEasingCurve_setOvershoot(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEasingCurve *  qp = RawPtr_to(QEasingCurve *, sfp[0]);
	if (qp) {
		qreal overshoot = Float_to(qreal, sfp[1]);
		qp->setOvershoot(overshoot);
	}
	RETURNvoid_();
}

//void QEasingCurve.setPeriod(float period);
KMETHOD QEasingCurve_setPeriod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEasingCurve *  qp = RawPtr_to(QEasingCurve *, sfp[0]);
	if (qp) {
		qreal period = Float_to(qreal, sfp[1]);
		qp->setPeriod(period);
	}
	RETURNvoid_();
}

//void QEasingCurve.setType(int type);
KMETHOD QEasingCurve_setType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEasingCurve *  qp = RawPtr_to(QEasingCurve *, sfp[0]);
	if (qp) {
		QEasingCurve::Type type = Int_to(QEasingCurve::Type, sfp[1]);
		qp->setType(type);
	}
	RETURNvoid_();
}

//int QEasingCurve.getType();
KMETHOD QEasingCurve_getType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEasingCurve *  qp = RawPtr_to(QEasingCurve *, sfp[0]);
	if (qp) {
		QEasingCurve::Type ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QEasingCurve.valueForProgress(float progress);
KMETHOD QEasingCurve_valueForProgress(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEasingCurve *  qp = RawPtr_to(QEasingCurve *, sfp[0]);
	if (qp) {
		qreal progress = Float_to(qreal, sfp[1]);
		qreal ret_v = qp->valueForProgress(progress);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//Array<String> QEasingCurve.parents();
KMETHOD QEasingCurve_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QEasingCurve *qp = RawPtr_to(QEasingCurve*, sfp[0]);
	if (qp != NULL) {
		int size = 10;
		knh_Array_t *a = new_Array0(ctx, size);
		const knh_ClassTBL_t *ct = sfp[0].p->h.cTBL;
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}

DummyQEasingCurve::DummyQEasingCurve()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQEasingCurve::setSelf(knh_RawPtr_t *ptr)
{
	DummyQEasingCurve::self = ptr;
}

bool DummyQEasingCurve::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQEasingCurve::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQEasingCurve::event_map->bigin();
	if ((itr = DummyQEasingCurve::event_map->find(str)) == DummyQEasingCurve::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQEasingCurve::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQEasingCurve::slot_map->bigin();
	if ((itr = DummyQEasingCurve::slot_map->find(str)) == DummyQEasingCurve::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQEasingCurve::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQEasingCurve::connection(QObject *o)
{
	QEasingCurve *p = dynamic_cast<QEasingCurve*>(o);
	if (p != NULL) {
	}
}

KQEasingCurve::KQEasingCurve(QEasingCurve::Type type) : QEasingCurve(type)
{
	self = NULL;
	dummy = new DummyQEasingCurve();
}

KMETHOD QEasingCurve_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQEasingCurve *qp = RawPtr_to(KQEasingCurve *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QEasingCurve]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QEasingCurve]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QEasingCurve_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQEasingCurve *qp = RawPtr_to(KQEasingCurve *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QEasingCurve]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QEasingCurve]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QEasingCurve_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQEasingCurve *qp = (KQEasingCurve *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QEasingCurve_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQEasingCurve *qp = (KQEasingCurve *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QEasingCurve_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QEasingCurve*>(p1->rawptr) == *static_cast<QEasingCurve*>(p2->rawptr) ? 0 : 1);
}

void KQEasingCurve::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QEasingCurveConstInt[] = {
	{"Linear", QEasingCurve::Linear},
	{"InQuad", QEasingCurve::InQuad},
	{"OutQuad", QEasingCurve::OutQuad},
	{"InOutQuad", QEasingCurve::InOutQuad},
	{"OutInQuad", QEasingCurve::OutInQuad},
	{"InCubic", QEasingCurve::InCubic},
	{"OutCubic", QEasingCurve::OutCubic},
	{"InOutCubic", QEasingCurve::InOutCubic},
	{"OutInCubic", QEasingCurve::OutInCubic},
	{"InQuart", QEasingCurve::InQuart},
	{"OutQuart", QEasingCurve::OutQuart},
	{"InOutQuart", QEasingCurve::InOutQuart},
	{"OutInQuart", QEasingCurve::OutInQuart},
	{"InQuint", QEasingCurve::InQuint},
	{"OutQuint", QEasingCurve::OutQuint},
	{"InOutQuint", QEasingCurve::InOutQuint},
	{"OutInQuint", QEasingCurve::OutInQuint},
	{"InSine", QEasingCurve::InSine},
	{"OutSine", QEasingCurve::OutSine},
	{"InOutSine", QEasingCurve::InOutSine},
	{"OutInSine", QEasingCurve::OutInSine},
	{"InExpo", QEasingCurve::InExpo},
	{"OutExpo", QEasingCurve::OutExpo},
	{"InOutExpo", QEasingCurve::InOutExpo},
	{"OutInExpo", QEasingCurve::OutInExpo},
	{"InCirc", QEasingCurve::InCirc},
	{"OutCirc", QEasingCurve::OutCirc},
	{"InOutCirc", QEasingCurve::InOutCirc},
	{"OutInCirc", QEasingCurve::OutInCirc},
	{"InElastic", QEasingCurve::InElastic},
	{"OutElastic", QEasingCurve::OutElastic},
	{"InOutElastic", QEasingCurve::InOutElastic},
	{"OutInElastic", QEasingCurve::OutInElastic},
	{"InBack", QEasingCurve::InBack},
	{"OutBack", QEasingCurve::OutBack},
	{"InOutBack", QEasingCurve::InOutBack},
	{"OutInBack", QEasingCurve::OutInBack},
	{"InBounce", QEasingCurve::InBounce},
	{"OutBounce", QEasingCurve::OutBounce},
	{"InOutBounce", QEasingCurve::InOutBounce},
	{"OutInBounce", QEasingCurve::OutInBounce},
	{"Custom", QEasingCurve::Custom},
	{NULL, 0}
};

DEFAPI(void) constQEasingCurve(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QEasingCurveConstInt);
}


DEFAPI(void) defQEasingCurve(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QEasingCurve";
	cdef->free = QEasingCurve_free;
	cdef->reftrace = QEasingCurve_reftrace;
	cdef->compareTo = QEasingCurve_compareTo;
}


