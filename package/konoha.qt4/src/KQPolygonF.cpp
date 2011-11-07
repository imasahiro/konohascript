//QPolygonF QPolygonF.new();
KMETHOD QPolygonF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPolygonF *ret_v = new KQPolygonF();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPolygonF QPolygonF.new(int size);
KMETHOD QPolygonF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int size = Int_to(int, sfp[1]);
	KQPolygonF *ret_v = new KQPolygonF(size);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPolygonF QPolygonF.new(QPolygonF polygon);
KMETHOD QPolygonF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPolygonF  polygon = *RawPtr_to(const QPolygonF *, sfp[1]);
	KQPolygonF *ret_v = new KQPolygonF(polygon);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPolygonF QPolygonF.new(QRectF rectangle);
KMETHOD QPolygonF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
	KQPolygonF *ret_v = new KQPolygonF(rectangle);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPolygonF QPolygonF.new(QPolygon polygon);
KMETHOD QPolygonF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPolygon  polygon = *RawPtr_to(const QPolygon *, sfp[1]);
	KQPolygonF *ret_v = new KQPolygonF(polygon);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QRectF QPolygonF.boundingRect();
KMETHOD QPolygonF_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygonF *  qp = RawPtr_to(QPolygonF *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->boundingRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QPolygonF.containsPoint(QPointF point, int fillRule);
KMETHOD QPolygonF_containsPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygonF *  qp = RawPtr_to(QPolygonF *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		Qt::FillRule fillRule = Int_to(Qt::FillRule, sfp[2]);
		bool ret_v = qp->containsPoint(point, fillRule);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QPolygonF QPolygonF.intersected(QPolygonF r);
KMETHOD QPolygonF_intersected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygonF *  qp = RawPtr_to(QPolygonF *, sfp[0]);
	if (qp) {
		const QPolygonF  r = *RawPtr_to(const QPolygonF *, sfp[1]);
		QPolygonF ret_v = qp->intersected(r);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QPolygonF.isClosed();
KMETHOD QPolygonF_isClosed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygonF *  qp = RawPtr_to(QPolygonF *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isClosed();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QPolygonF QPolygonF.subtracted(QPolygonF r);
KMETHOD QPolygonF_subtracted(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygonF *  qp = RawPtr_to(QPolygonF *, sfp[0]);
	if (qp) {
		const QPolygonF  r = *RawPtr_to(const QPolygonF *, sfp[1]);
		QPolygonF ret_v = qp->subtracted(r);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPolygon QPolygonF.toPolygon();
KMETHOD QPolygonF_toPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygonF *  qp = RawPtr_to(QPolygonF *, sfp[0]);
	if (qp) {
		QPolygon ret_v = qp->toPolygon();
		QPolygon *ret_v_ = new QPolygon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QPolygonF.translate(QPointF offset);
KMETHOD QPolygonF_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygonF *  qp = RawPtr_to(QPolygonF *, sfp[0]);
	if (qp) {
		const QPointF  offset = *RawPtr_to(const QPointF *, sfp[1]);
		qp->translate(offset);
	}
	RETURNvoid_();
}

/*
//void QPolygonF.translate(float dx, float dy);
KMETHOD QPolygonF_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygonF *  qp = RawPtr_to(QPolygonF *, sfp[0]);
	if (qp) {
		qreal dx = Float_to(qreal, sfp[1]);
		qreal dy = Float_to(qreal, sfp[2]);
		qp->translate(dx, dy);
	}
	RETURNvoid_();
}
*/
//QPolygonF QPolygonF.translated(QPointF offset);
KMETHOD QPolygonF_translated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygonF *  qp = RawPtr_to(QPolygonF *, sfp[0]);
	if (qp) {
		const QPointF  offset = *RawPtr_to(const QPointF *, sfp[1]);
		QPolygonF ret_v = qp->translated(offset);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPolygonF QPolygonF.translated(float dx, float dy);
KMETHOD QPolygonF_translated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygonF *  qp = RawPtr_to(QPolygonF *, sfp[0]);
	if (qp) {
		qreal dx = Float_to(qreal, sfp[1]);
		qreal dy = Float_to(qreal, sfp[2]);
		QPolygonF ret_v = qp->translated(dx, dy);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QPolygonF QPolygonF.united(QPolygonF r);
KMETHOD QPolygonF_united(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygonF *  qp = RawPtr_to(QPolygonF *, sfp[0]);
	if (qp) {
		const QPolygonF  r = *RawPtr_to(const QPolygonF *, sfp[1]);
		QPolygonF ret_v = qp->united(r);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQPolygonF::DummyQPolygonF()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPolygonF::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPolygonF::self = ptr;
	DummyQVector::setSelf(ptr);
}

bool DummyQPolygonF::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQVector::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQPolygonF::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPolygonF::event_map->bigin();
	if ((itr = DummyQPolygonF::event_map->find(str)) == DummyQPolygonF::event_map->end()) {
		bool ret = false;
		ret = DummyQVector::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPolygonF::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPolygonF::slot_map->bigin();
	if ((itr = DummyQPolygonF::slot_map->find(str)) == DummyQPolygonF::slot_map->end()) {
		bool ret = false;
		ret = DummyQVector::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQPolygonF::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQVector::reftrace(ctx, p, tail_);
}

void DummyQPolygonF::connection(QObject *o)
{
	QPolygonF *p = dynamic_cast<QPolygonF*>(o);
	if (p != NULL) {
	}
	DummyQVector::connection(o);
}

KQPolygonF::KQPolygonF() : QPolygonF()
{
	self = NULL;
	dummy = new DummyQPolygonF();
}

KMETHOD QPolygonF_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPolygonF *qp = RawPtr_to(KQPolygonF *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPolygonF]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPolygonF]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPolygonF_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPolygonF *qp = RawPtr_to(KQPolygonF *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPolygonF]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPolygonF]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPolygonF_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPolygonF *qp = (KQPolygonF *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPolygonF_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQPolygonF *qp = (KQPolygonF *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPolygonF_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQPolygonF::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQPolygonF(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPolygonF";
	cdef->free = QPolygonF_free;
	cdef->reftrace = QPolygonF_reftrace;
	cdef->compareTo = QPolygonF_compareTo;
}


