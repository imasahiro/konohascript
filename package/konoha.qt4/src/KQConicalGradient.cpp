//QConicalGradient QConicalGradient.new();
KMETHOD QConicalGradient_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQConicalGradient *ret_v = new KQConicalGradient();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QConicalGradient QConicalGradient.new(QPointF center, float angle);
KMETHOD QConicalGradient_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPointF  center = *RawPtr_to(const QPointF *, sfp[1]);
	qreal angle = Float_to(qreal, sfp[2]);
	KQConicalGradient *ret_v = new KQConicalGradient(center, angle);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QConicalGradient QConicalGradient.new(float cx, float cy, float angle);
KMETHOD QConicalGradient_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	qreal cx = Float_to(qreal, sfp[1]);
	qreal cy = Float_to(qreal, sfp[2]);
	qreal angle = Float_to(qreal, sfp[3]);
	KQConicalGradient *ret_v = new KQConicalGradient(cx, cy, angle);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//float QConicalGradient.getAngle();
KMETHOD QConicalGradient_getAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QConicalGradient *  qp = RawPtr_to(QConicalGradient *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->angle();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QPointF QConicalGradient.getCenter();
KMETHOD QConicalGradient_getCenter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QConicalGradient *  qp = RawPtr_to(QConicalGradient *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->center();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QConicalGradient.setAngle(float angle);
KMETHOD QConicalGradient_setAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QConicalGradient *  qp = RawPtr_to(QConicalGradient *, sfp[0]);
	if (qp) {
		qreal angle = Float_to(qreal, sfp[1]);
		qp->setAngle(angle);
	}
	RETURNvoid_();
}

//void QConicalGradient.setCenter(QPointF center);
KMETHOD QConicalGradient_setCenter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QConicalGradient *  qp = RawPtr_to(QConicalGradient *, sfp[0]);
	if (qp) {
		const QPointF  center = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setCenter(center);
	}
	RETURNvoid_();
}

/*
//void QConicalGradient.setCenter(float x, float y);
KMETHOD QConicalGradient_setCenter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QConicalGradient *  qp = RawPtr_to(QConicalGradient *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qp->setCenter(x, y);
	}
	RETURNvoid_();
}
*/

DummyQConicalGradient::DummyQConicalGradient()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQConicalGradient::setSelf(knh_RawPtr_t *ptr)
{
	DummyQConicalGradient::self = ptr;
	DummyQGradient::setSelf(ptr);
}

bool DummyQConicalGradient::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGradient::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQConicalGradient::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQConicalGradient::event_map->bigin();
	if ((itr = DummyQConicalGradient::event_map->find(str)) == DummyQConicalGradient::event_map->end()) {
		bool ret = false;
		ret = DummyQGradient::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQConicalGradient::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQConicalGradient::slot_map->bigin();
	if ((itr = DummyQConicalGradient::slot_map->find(str)) == DummyQConicalGradient::slot_map->end()) {
		bool ret = false;
		ret = DummyQGradient::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQConicalGradient::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQGradient::reftrace(ctx, p, tail_);
}

void DummyQConicalGradient::connection(QObject *o)
{
	QConicalGradient *p = dynamic_cast<QConicalGradient*>(o);
	if (p != NULL) {
	}
	DummyQGradient::connection(o);
}

KQConicalGradient::KQConicalGradient() : QConicalGradient()
{
	self = NULL;
	dummy = new DummyQConicalGradient();
}

KMETHOD QConicalGradient_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQConicalGradient *qp = RawPtr_to(KQConicalGradient *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QConicalGradient]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QConicalGradient]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QConicalGradient_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQConicalGradient *qp = RawPtr_to(KQConicalGradient *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QConicalGradient]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QConicalGradient]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QConicalGradient_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQConicalGradient *qp = (KQConicalGradient *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QConicalGradient_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQConicalGradient *qp = (KQConicalGradient *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QConicalGradient_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQConicalGradient::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQConicalGradient(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QConicalGradient";
	cdef->free = QConicalGradient_free;
	cdef->reftrace = QConicalGradient_reftrace;
	cdef->compareTo = QConicalGradient_compareTo;
}


