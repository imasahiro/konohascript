//@Virtual @Override QRectF QGraphicsDropShadowEffect.boundingRectFor(QRectF rect);
KMETHOD QGraphicsDropShadowEffect_boundingRectFor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		QRectF ret_v = qp->boundingRectFor(rect);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsDropShadowEffect QGraphicsDropShadowEffect.new(QObject parent);
KMETHOD QGraphicsDropShadowEffect_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQGraphicsDropShadowEffect *ret_v = new KQGraphicsDropShadowEffect(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//float QGraphicsDropShadowEffect.getBlurRadius();
KMETHOD QGraphicsDropShadowEffect_getBlurRadius(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->blurRadius();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QColor QGraphicsDropShadowEffect.getColor();
KMETHOD QGraphicsDropShadowEffect_getColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp != NULL) {
		QColor ret_v = qp->color();
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QGraphicsDropShadowEffect.offset();
KMETHOD QGraphicsDropShadowEffect_offset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp != NULL) {
		QPointF ret_v = qp->offset();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QGraphicsDropShadowEffect.xOffset();
KMETHOD QGraphicsDropShadowEffect_xOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->xOffset();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QGraphicsDropShadowEffect.yOffset();
KMETHOD QGraphicsDropShadowEffect_yOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->yOffset();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QGraphicsDropShadowEffect.setBlurRadius(float blurRadius);
KMETHOD QGraphicsDropShadowEffect_setBlurRadius(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp != NULL) {
		qreal blurRadius = Float_to(qreal, sfp[1]);
		qp->setBlurRadius(blurRadius);
	}
	RETURNvoid_();
}

//void QGraphicsDropShadowEffect.setColor(QColor color);
KMETHOD QGraphicsDropShadowEffect_setColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp != NULL) {
		const QColor  color = *RawPtr_to(const QColor *, sfp[1]);
		qp->setColor(color);
	}
	RETURNvoid_();
}

//void QGraphicsDropShadowEffect.setOffset(QPointF ofs);
KMETHOD QGraphicsDropShadowEffect_setOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp != NULL) {
		const QPointF  ofs = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setOffset(ofs);
	}
	RETURNvoid_();
}

/*
//void QGraphicsDropShadowEffect.setOffset(float dx, float dy);
KMETHOD QGraphicsDropShadowEffect_setOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp != NULL) {
		qreal dx = Float_to(qreal, sfp[1]);
		qreal dy = Float_to(qreal, sfp[2]);
		qp->setOffset(dx, dy);
	}
	RETURNvoid_();
}
*/
/*
//void QGraphicsDropShadowEffect.setOffset(float d);
KMETHOD QGraphicsDropShadowEffect_setOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp != NULL) {
		qreal d = Float_to(qreal, sfp[1]);
		qp->setOffset(d);
	}
	RETURNvoid_();
}
*/
//void QGraphicsDropShadowEffect.setXOffset(float dx);
KMETHOD QGraphicsDropShadowEffect_setXOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp != NULL) {
		qreal dx = Float_to(qreal, sfp[1]);
		qp->setXOffset(dx);
	}
	RETURNvoid_();
}

//void QGraphicsDropShadowEffect.setYOffset(float dy);
KMETHOD QGraphicsDropShadowEffect_setYOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsDropShadowEffect *  qp = RawPtr_to(QGraphicsDropShadowEffect *, sfp[0]);
	if (qp != NULL) {
		qreal dy = Float_to(qreal, sfp[1]);
		qp->setYOffset(dy);
	}
	RETURNvoid_();
}


DummyQGraphicsDropShadowEffect::DummyQGraphicsDropShadowEffect()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGraphicsDropShadowEffect::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsDropShadowEffect::self = ptr;
	DummyQGraphicsEffect::setSelf(ptr);
}

bool DummyQGraphicsDropShadowEffect::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsEffect::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsDropShadowEffect::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsDropShadowEffect::event_map->bigin();
	if ((itr = DummyQGraphicsDropShadowEffect::event_map->find(str)) == DummyQGraphicsDropShadowEffect::event_map->end()) {
		bool ret;
		ret = DummyQGraphicsEffect::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsDropShadowEffect::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsDropShadowEffect::slot_map->bigin();
	if ((itr = DummyQGraphicsDropShadowEffect::event_map->find(str)) == DummyQGraphicsDropShadowEffect::slot_map->end()) {
		bool ret;
		ret = DummyQGraphicsEffect::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQGraphicsDropShadowEffect::KQGraphicsDropShadowEffect(QObject* parent) : QGraphicsDropShadowEffect(parent)
{
	self = NULL;
}

KMETHOD QGraphicsDropShadowEffect_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsDropShadowEffect *qp = RawPtr_to(KQGraphicsDropShadowEffect *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsDropShadowEffect]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQGraphicsDropShadowEffect::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsDropShadowEffect]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QGraphicsDropShadowEffect_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsDropShadowEffect *qp = RawPtr_to(KQGraphicsDropShadowEffect *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsDropShadowEffect]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQGraphicsDropShadowEffect::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsDropShadowEffect]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsDropShadowEffect_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsDropShadowEffect *qp = (KQGraphicsDropShadowEffect *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsDropShadowEffect_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQGraphicsDropShadowEffect *qp = (KQGraphicsDropShadowEffect *)p->rawptr;
		(void)qp;
	}
}

static int QGraphicsDropShadowEffect_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQGraphicsDropShadowEffect::event(QEvent *event)
{
	if (!DummyQGraphicsDropShadowEffect::eventDispatcher(event)) {
		QGraphicsDropShadowEffect::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQGraphicsDropShadowEffect(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsDropShadowEffect";
	cdef->free = QGraphicsDropShadowEffect_free;
	cdef->reftrace = QGraphicsDropShadowEffect_reftrace;
	cdef->compareTo = QGraphicsDropShadowEffect_compareTo;
}


