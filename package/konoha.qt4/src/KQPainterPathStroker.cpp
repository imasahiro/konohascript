//QPainterPathStroker QPainterPathStroker.new();
KMETHOD QPainterPathStroker_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPainterPathStroker *ret_v = new KQPainterPathStroker();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QPainterPathStroker.getCapStyle();
KMETHOD QPainterPathStroker_getCapStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPathStroker *  qp = RawPtr_to(QPainterPathStroker *, sfp[0]);
	if (qp != NULL) {
		Qt::PenCapStyle ret_v = qp->capStyle();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPainterPath QPainterPathStroker.createStroke(QPainterPath path);
KMETHOD QPainterPathStroker_createStroke(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPathStroker *  qp = RawPtr_to(QPainterPathStroker *, sfp[0]);
	if (qp != NULL) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		QPainterPath ret_v = qp->createStroke(path);
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QPainterPathStroker.getCurveThreshold();
KMETHOD QPainterPathStroker_getCurveThreshold(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPathStroker *  qp = RawPtr_to(QPainterPathStroker *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->curveThreshold();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QPainterPathStroker.dashOffset();
KMETHOD QPainterPathStroker_dashOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPathStroker *  qp = RawPtr_to(QPainterPathStroker *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->dashOffset();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QPainterPathStroker.getJoinStyle();
KMETHOD QPainterPathStroker_getJoinStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPathStroker *  qp = RawPtr_to(QPainterPathStroker *, sfp[0]);
	if (qp != NULL) {
		Qt::PenJoinStyle ret_v = qp->joinStyle();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QPainterPathStroker.getMiterLimit();
KMETHOD QPainterPathStroker_getMiterLimit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPathStroker *  qp = RawPtr_to(QPainterPathStroker *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->miterLimit();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QPainterPathStroker.setCapStyle(int style);
KMETHOD QPainterPathStroker_setCapStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPathStroker *  qp = RawPtr_to(QPainterPathStroker *, sfp[0]);
	if (qp != NULL) {
		Qt::PenCapStyle style = Int_to(Qt::PenCapStyle, sfp[1]);
		qp->setCapStyle(style);
	}
	RETURNvoid_();
}

//void QPainterPathStroker.setCurveThreshold(float threshold);
KMETHOD QPainterPathStroker_setCurveThreshold(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPathStroker *  qp = RawPtr_to(QPainterPathStroker *, sfp[0]);
	if (qp != NULL) {
		qreal threshold = Float_to(qreal, sfp[1]);
		qp->setCurveThreshold(threshold);
	}
	RETURNvoid_();
}

//void QPainterPathStroker.setDashOffset(float offset);
KMETHOD QPainterPathStroker_setDashOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPathStroker *  qp = RawPtr_to(QPainterPathStroker *, sfp[0]);
	if (qp != NULL) {
		qreal offset = Float_to(qreal, sfp[1]);
		qp->setDashOffset(offset);
	}
	RETURNvoid_();
}

//void QPainterPathStroker.setDashPattern(int style);
KMETHOD QPainterPathStroker_setDashPattern(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPathStroker *  qp = RawPtr_to(QPainterPathStroker *, sfp[0]);
	if (qp != NULL) {
		Qt::PenStyle style = Int_to(Qt::PenStyle, sfp[1]);
		qp->setDashPattern(style);
	}
	RETURNvoid_();
}

//void QPainterPathStroker.setJoinStyle(int style);
KMETHOD QPainterPathStroker_setJoinStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPathStroker *  qp = RawPtr_to(QPainterPathStroker *, sfp[0]);
	if (qp != NULL) {
		Qt::PenJoinStyle style = Int_to(Qt::PenJoinStyle, sfp[1]);
		qp->setJoinStyle(style);
	}
	RETURNvoid_();
}

//void QPainterPathStroker.setMiterLimit(float limit);
KMETHOD QPainterPathStroker_setMiterLimit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPathStroker *  qp = RawPtr_to(QPainterPathStroker *, sfp[0]);
	if (qp != NULL) {
		qreal limit = Float_to(qreal, sfp[1]);
		qp->setMiterLimit(limit);
	}
	RETURNvoid_();
}

//void QPainterPathStroker.setWidth(float width);
KMETHOD QPainterPathStroker_setWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPathStroker *  qp = RawPtr_to(QPainterPathStroker *, sfp[0]);
	if (qp != NULL) {
		qreal width = Float_to(qreal, sfp[1]);
		qp->setWidth(width);
	}
	RETURNvoid_();
}

//float QPainterPathStroker.getWidth();
KMETHOD QPainterPathStroker_getWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPathStroker *  qp = RawPtr_to(QPainterPathStroker *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->width();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}


DummyQPainterPathStroker::DummyQPainterPathStroker()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPainterPathStroker::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPainterPathStroker::self = ptr;
}

bool DummyQPainterPathStroker::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQPainterPathStroker::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPainterPathStroker::event_map->bigin();
	if ((itr = DummyQPainterPathStroker::event_map->find(str)) == DummyQPainterPathStroker::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPainterPathStroker::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPainterPathStroker::slot_map->bigin();
	if ((itr = DummyQPainterPathStroker::event_map->find(str)) == DummyQPainterPathStroker::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQPainterPathStroker::KQPainterPathStroker() : QPainterPathStroker()
{
	self = NULL;
}

KMETHOD QPainterPathStroker_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPainterPathStroker *qp = RawPtr_to(KQPainterPathStroker *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPainterPathStroker]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQPainterPathStroker::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPainterPathStroker]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QPainterPathStroker_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPainterPathStroker *qp = RawPtr_to(KQPainterPathStroker *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPainterPathStroker]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQPainterPathStroker::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPainterPathStroker]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPainterPathStroker_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPainterPathStroker *qp = (KQPainterPathStroker *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPainterPathStroker_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQPainterPathStroker *qp = (KQPainterPathStroker *)p->rawptr;
		(void)qp;
	}
}

static int QPainterPathStroker_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQPainterPathStroker(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPainterPathStroker";
	cdef->free = QPainterPathStroker_free;
	cdef->reftrace = QPainterPathStroker_reftrace;
	cdef->compareTo = QPainterPathStroker_compareTo;
}


