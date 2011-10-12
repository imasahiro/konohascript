//QLineF QLineF.new();
KMETHOD QLineF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLineF *ret_v = new KQLineF();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QLineF QLineF.new(QPointF p1, QPointF p2);
KMETHOD QLineF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPointF  p1 = *RawPtr_to(const QPointF *, sfp[1]);
	const QPointF  p2 = *RawPtr_to(const QPointF *, sfp[2]);
	KQLineF *ret_v = new KQLineF(p1, p2);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QLineF QLineF.new(float x1, float y1, float x2, float y2);
KMETHOD QLineF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	qreal x1 = Float_to(qreal, sfp[1]);
	qreal y1 = Float_to(qreal, sfp[2]);
	qreal x2 = Float_to(qreal, sfp[3]);
	qreal y2 = Float_to(qreal, sfp[4]);
	KQLineF *ret_v = new KQLineF(x1, y1, x2, y2);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QLineF QLineF.new(QLine line);
KMETHOD QLineF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QLine  line = *RawPtr_to(const QLine *, sfp[1]);
	KQLineF *ret_v = new KQLineF(line);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QPointF QLineF.getP1();
KMETHOD QLineF_getP1(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		QPointF ret_v = qp->p1();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QLineF.getP2();
KMETHOD QLineF_getP2(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		QPointF ret_v = qp->p2();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QLineF.x1();
KMETHOD QLineF_x1(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->x1();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QLineF.x2();
KMETHOD QLineF_x2(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->x2();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QLineF.y1();
KMETHOD QLineF_y1(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->y1();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QLineF.y2();
KMETHOD QLineF_y2(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->y2();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QLineF.getAngle();
KMETHOD QLineF_getAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->angle();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QLineF.angleTo(QLineF line);
KMETHOD QLineF_angleTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		const QLineF  line = *RawPtr_to(const QLineF *, sfp[1]);
		qreal ret_v = qp->angleTo(line);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QLineF.dx();
KMETHOD QLineF_dx(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->dx();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QLineF.dy();
KMETHOD QLineF_dy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->dy();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QLineF.intersect(QLineF line, QPointF intersectionPoint);
KMETHOD QLineF_intersect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		const QLineF  line = *RawPtr_to(const QLineF *, sfp[1]);
		QPointF*  intersectionPoint = RawPtr_to(QPointF*, sfp[2]);
		QLineF::IntersectType ret_v = qp->intersect(line, intersectionPoint);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

////boolean QLineF.isNull();
KMETHOD QLineF_isNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isNull();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//float QLineF.getLength();
KMETHOD QLineF_getLength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->length();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QLineF QLineF.normalVector();
KMETHOD QLineF_normalVector(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		QLineF ret_v = qp->normalVector();
		QLineF *ret_v_ = new QLineF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QLineF.pointAt(float t);
KMETHOD QLineF_pointAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		qreal t = Float_to(qreal, sfp[1]);
		QPointF ret_v = qp->pointAt(t);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QLineF.setP1(QPointF p1);
KMETHOD QLineF_setP1(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		const QPointF  p1 = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setP1(p1);
	}
	RETURNvoid_();
}

//void QLineF.setP2(QPointF p2);
KMETHOD QLineF_setP2(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		const QPointF  p2 = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setP2(p2);
	}
	RETURNvoid_();
}

//void QLineF.setAngle(float angle);
KMETHOD QLineF_setAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		qreal angle = Float_to(qreal, sfp[1]);
		qp->setAngle(angle);
	}
	RETURNvoid_();
}

//void QLineF.setLength(float length);
KMETHOD QLineF_setLength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		qreal length = Float_to(qreal, sfp[1]);
		qp->setLength(length);
	}
	RETURNvoid_();
}

//void QLineF.setLine(float x1, float y1, float x2, float y2);
KMETHOD QLineF_setLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		qreal x1 = Float_to(qreal, sfp[1]);
		qreal y1 = Float_to(qreal, sfp[2]);
		qreal x2 = Float_to(qreal, sfp[3]);
		qreal y2 = Float_to(qreal, sfp[4]);
		qp->setLine(x1, y1, x2, y2);
	}
	RETURNvoid_();
}

//void QLineF.setPoints(QPointF p1, QPointF p2);
KMETHOD QLineF_setPoints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		const QPointF  p1 = *RawPtr_to(const QPointF *, sfp[1]);
		const QPointF  p2 = *RawPtr_to(const QPointF *, sfp[2]);
		qp->setPoints(p1, p2);
	}
	RETURNvoid_();
}

//QLine QLineF.toLine();
KMETHOD QLineF_toLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		QLine ret_v = qp->toLine();
		QLine *ret_v_ = new QLine(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QLineF.translate(QPointF offset);
KMETHOD QLineF_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		const QPointF  offset = *RawPtr_to(const QPointF *, sfp[1]);
		qp->translate(offset);
	}
	RETURNvoid_();
}

/*
//void QLineF.translate(float dx, float dy);
KMETHOD QLineF_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		qreal dx = Float_to(qreal, sfp[1]);
		qreal dy = Float_to(qreal, sfp[2]);
		qp->translate(dx, dy);
	}
	RETURNvoid_();
}
*/
//QLineF QLineF.translated(QPointF offset);
KMETHOD QLineF_translated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		const QPointF  offset = *RawPtr_to(const QPointF *, sfp[1]);
		QLineF ret_v = qp->translated(offset);
		QLineF *ret_v_ = new QLineF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QLineF QLineF.translated(float dx, float dy);
KMETHOD QLineF_translated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		qreal dx = Float_to(qreal, sfp[1]);
		qreal dy = Float_to(qreal, sfp[2]);
		QLineF ret_v = qp->translated(dx, dy);
		QLineF *ret_v_ = new QLineF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QLineF QLineF.unitVector();
KMETHOD QLineF_unitVector(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		QLineF ret_v = qp->unitVector();
		QLineF *ret_v_ = new QLineF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QLineF QLineF.fromPolar(float length, float angle);
KMETHOD QLineF_fromPolar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLineF *  qp = RawPtr_to(QLineF *, sfp[0]);
	if (qp != NULL) {
		qreal length = Float_to(qreal, sfp[1]);
		qreal angle = Float_to(qreal, sfp[2]);
		QLineF ret_v = qp->fromPolar(length, angle);
		QLineF *ret_v_ = new QLineF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQLineF::DummyQLineF()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQLineF::setSelf(knh_RawPtr_t *ptr)
{
	DummyQLineF::self = ptr;
}

bool DummyQLineF::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQLineF::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLineF::event_map->bigin();
	if ((itr = DummyQLineF::event_map->find(str)) == DummyQLineF::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQLineF::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLineF::slot_map->bigin();
	if ((itr = DummyQLineF::event_map->find(str)) == DummyQLineF::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQLineF::KQLineF() : QLineF()
{
	self = NULL;
}

KMETHOD QLineF_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLineF *qp = RawPtr_to(KQLineF *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QLineF]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQLineF::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLineF]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QLineF_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLineF *qp = RawPtr_to(KQLineF *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QLineF]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQLineF::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLineF]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QLineF_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQLineF *qp = (KQLineF *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QLineF_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQLineF *qp = (KQLineF *)p->rawptr;
		(void)qp;
	}
}

static int QLineF_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QLineF*>(p1->rawptr) == *static_cast<QLineF*>(p2->rawptr) ? 0 : 1);
}

DEFAPI(void) defQLineF(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QLineF";
	cdef->free = QLineF_free;
	cdef->reftrace = QLineF_reftrace;
	cdef->compareTo = QLineF_compareTo;
}

static knh_IntData_t QLineFConstInt[] = {
	{"NoIntersection", QLineF::NoIntersection},
	{"UnboundedIntersection", QLineF::UnboundedIntersection},
	{"BoundedIntersection", QLineF::BoundedIntersection},
	{NULL, 0}
};

DEFAPI(void) constQLineF(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QLineFConstInt);
}

