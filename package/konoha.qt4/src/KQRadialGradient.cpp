//QRadialGradient QRadialGradient.new();
KMETHOD QRadialGradient_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRadialGradient *ret_v = new KQRadialGradient();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QRadialGradient QRadialGradient.new(QPointF center, float radius, QPointF focalPoint);
KMETHOD QRadialGradient_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPointF  center = *RawPtr_to(const QPointF *, sfp[1]);
	qreal radius = Float_to(qreal, sfp[2]);
	const QPointF  focalPoint = *RawPtr_to(const QPointF *, sfp[3]);
	KQRadialGradient *ret_v = new KQRadialGradient(center, radius, focalPoint);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QRadialGradient QRadialGradient.new(float cx, float cy, float radius, float fx, float fy);
KMETHOD QRadialGradient_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	qreal cx = Float_to(qreal, sfp[1]);
	qreal cy = Float_to(qreal, sfp[2]);
	qreal radius = Float_to(qreal, sfp[3]);
	qreal fx = Float_to(qreal, sfp[4]);
	qreal fy = Float_to(qreal, sfp[5]);
	KQRadialGradient *ret_v = new KQRadialGradient(cx, cy, radius, fx, fy);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QRadialGradient QRadialGradient.new(QPointF center, float radius);
KMETHOD QRadialGradient_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPointF  center = *RawPtr_to(const QPointF *, sfp[1]);
	qreal radius = Float_to(qreal, sfp[2]);
	KQRadialGradient *ret_v = new KQRadialGradient(center, radius);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QRadialGradient QRadialGradient.new(float cx, float cy, float radius);
KMETHOD QRadialGradient_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	qreal cx = Float_to(qreal, sfp[1]);
	qreal cy = Float_to(qreal, sfp[2]);
	qreal radius = Float_to(qreal, sfp[3]);
	KQRadialGradient *ret_v = new KQRadialGradient(cx, cy, radius);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QPointF QRadialGradient.getCenter();
KMETHOD QRadialGradient_getCenter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRadialGradient *  qp = RawPtr_to(QRadialGradient *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->center();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QRadialGradient.getFocalPoint();
KMETHOD QRadialGradient_getFocalPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRadialGradient *  qp = RawPtr_to(QRadialGradient *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->focalPoint();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QRadialGradient.getRadius();
KMETHOD QRadialGradient_getRadius(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRadialGradient *  qp = RawPtr_to(QRadialGradient *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->radius();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QRadialGradient.setCenter(QPointF center);
KMETHOD QRadialGradient_setCenter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRadialGradient *  qp = RawPtr_to(QRadialGradient *, sfp[0]);
	if (qp) {
		const QPointF  center = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setCenter(center);
	}
	RETURNvoid_();
}

/*
//void QRadialGradient.setCenter(float x, float y);
KMETHOD QRadialGradient_setCenter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRadialGradient *  qp = RawPtr_to(QRadialGradient *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qp->setCenter(x, y);
	}
	RETURNvoid_();
}
*/
//void QRadialGradient.setFocalPoint(QPointF focalPoint);
KMETHOD QRadialGradient_setFocalPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRadialGradient *  qp = RawPtr_to(QRadialGradient *, sfp[0]);
	if (qp) {
		const QPointF  focalPoint = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setFocalPoint(focalPoint);
	}
	RETURNvoid_();
}

/*
//void QRadialGradient.setFocalPoint(float x, float y);
KMETHOD QRadialGradient_setFocalPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRadialGradient *  qp = RawPtr_to(QRadialGradient *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qp->setFocalPoint(x, y);
	}
	RETURNvoid_();
}
*/
//void QRadialGradient.setRadius(float radius);
KMETHOD QRadialGradient_setRadius(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRadialGradient *  qp = RawPtr_to(QRadialGradient *, sfp[0]);
	if (qp) {
		qreal radius = Float_to(qreal, sfp[1]);
		qp->setRadius(radius);
	}
	RETURNvoid_();
}


DummyQRadialGradient::DummyQRadialGradient()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQRadialGradient::setSelf(knh_RawPtr_t *ptr)
{
	DummyQRadialGradient::self = ptr;
	DummyQGradient::setSelf(ptr);
}

bool DummyQRadialGradient::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGradient::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQRadialGradient::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRadialGradient::event_map->bigin();
	if ((itr = DummyQRadialGradient::event_map->find(str)) == DummyQRadialGradient::event_map->end()) {
		bool ret = false;
		ret = DummyQGradient::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQRadialGradient::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRadialGradient::slot_map->bigin();
	if ((itr = DummyQRadialGradient::slot_map->find(str)) == DummyQRadialGradient::slot_map->end()) {
		bool ret = false;
		ret = DummyQGradient::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQRadialGradient::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQGradient::reftrace(ctx, p, tail_);
}

void DummyQRadialGradient::connection(QObject *o)
{
	QRadialGradient *p = dynamic_cast<QRadialGradient*>(o);
	if (p != NULL) {
	}
	DummyQGradient::connection(o);
}

KQRadialGradient::KQRadialGradient() : QRadialGradient()
{
	self = NULL;
	dummy = new DummyQRadialGradient();
}

KMETHOD QRadialGradient_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRadialGradient *qp = RawPtr_to(KQRadialGradient *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QRadialGradient]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRadialGradient]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QRadialGradient_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRadialGradient *qp = RawPtr_to(KQRadialGradient *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QRadialGradient]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRadialGradient]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QRadialGradient_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQRadialGradient *qp = (KQRadialGradient *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QRadialGradient_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQRadialGradient *qp = (KQRadialGradient *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QRadialGradient_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQRadialGradient::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQRadialGradient(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QRadialGradient";
	cdef->free = QRadialGradient_free;
	cdef->reftrace = QRadialGradient_reftrace;
	cdef->compareTo = QRadialGradient_compareTo;
}


