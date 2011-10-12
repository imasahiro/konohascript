//QLinearGradient QLinearGradient.new();
KMETHOD QLinearGradient_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLinearGradient *ret_v = new KQLinearGradient();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QLinearGradient QLinearGradient.new(QPointF start, QPointF finalStop);
KMETHOD QLinearGradient_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPointF  start = *RawPtr_to(const QPointF *, sfp[1]);
	const QPointF  finalStop = *RawPtr_to(const QPointF *, sfp[2]);
	KQLinearGradient *ret_v = new KQLinearGradient(start, finalStop);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QLinearGradient QLinearGradient.new(float x1, float y1, float x2, float y2);
KMETHOD QLinearGradient_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	qreal x1 = Float_to(qreal, sfp[1]);
	qreal y1 = Float_to(qreal, sfp[2]);
	qreal x2 = Float_to(qreal, sfp[3]);
	qreal y2 = Float_to(qreal, sfp[4]);
	KQLinearGradient *ret_v = new KQLinearGradient(x1, y1, x2, y2);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QPointF QLinearGradient.getFinalStop();
KMETHOD QLinearGradient_getFinalStop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLinearGradient *  qp = RawPtr_to(QLinearGradient *, sfp[0]);
	if (qp != NULL) {
		QPointF ret_v = qp->finalStop();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QLinearGradient.setFinalStop(QPointF stop);
KMETHOD QLinearGradient_setFinalStop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLinearGradient *  qp = RawPtr_to(QLinearGradient *, sfp[0]);
	if (qp != NULL) {
		const QPointF  stop = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setFinalStop(stop);
	}
	RETURNvoid_();
}

/*
//void QLinearGradient.setFinalStop(float x, float y);
KMETHOD QLinearGradient_setFinalStop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLinearGradient *  qp = RawPtr_to(QLinearGradient *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qp->setFinalStop(x, y);
	}
	RETURNvoid_();
}
*/
//void QLinearGradient.setStart(QPointF start);
KMETHOD QLinearGradient_setStart(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLinearGradient *  qp = RawPtr_to(QLinearGradient *, sfp[0]);
	if (qp != NULL) {
		const QPointF  start = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setStart(start);
	}
	RETURNvoid_();
}

/*
//void QLinearGradient.setStart(float x, float y);
KMETHOD QLinearGradient_setStart(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLinearGradient *  qp = RawPtr_to(QLinearGradient *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qp->setStart(x, y);
	}
	RETURNvoid_();
}
*/
//QPointF QLinearGradient.getStart();
KMETHOD QLinearGradient_getStart(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLinearGradient *  qp = RawPtr_to(QLinearGradient *, sfp[0]);
	if (qp != NULL) {
		QPointF ret_v = qp->start();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQLinearGradient::DummyQLinearGradient()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQLinearGradient::setSelf(knh_RawPtr_t *ptr)
{
	DummyQLinearGradient::self = ptr;
	DummyQGradient::setSelf(ptr);
}

bool DummyQLinearGradient::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGradient::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQLinearGradient::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLinearGradient::event_map->bigin();
	if ((itr = DummyQLinearGradient::event_map->find(str)) == DummyQLinearGradient::event_map->end()) {
		bool ret;
		ret = DummyQGradient::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQLinearGradient::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLinearGradient::slot_map->bigin();
	if ((itr = DummyQLinearGradient::event_map->find(str)) == DummyQLinearGradient::slot_map->end()) {
		bool ret;
		ret = DummyQGradient::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQLinearGradient::KQLinearGradient() : QLinearGradient()
{
	self = NULL;
}

KMETHOD QLinearGradient_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLinearGradient *qp = RawPtr_to(KQLinearGradient *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QLinearGradient]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQLinearGradient::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLinearGradient]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QLinearGradient_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLinearGradient *qp = RawPtr_to(KQLinearGradient *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QLinearGradient]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQLinearGradient::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLinearGradient]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QLinearGradient_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQLinearGradient *qp = (KQLinearGradient *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QLinearGradient_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQLinearGradient *qp = (KQLinearGradient *)p->rawptr;
		(void)qp;
	}
}

static int QLinearGradient_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQLinearGradient(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QLinearGradient";
	cdef->free = QLinearGradient_free;
	cdef->reftrace = QLinearGradient_reftrace;
	cdef->compareTo = QLinearGradient_compareTo;
}


