//QBrush QPaintEngineState.backgroundBrush();
KMETHOD QPaintEngineState_backgroundBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		QBrush ret_v = qp->backgroundBrush();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QPaintEngineState.backgroundMode();
KMETHOD QPaintEngineState_backgroundMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		Qt::BGMode ret_v = qp->backgroundMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QBrush QPaintEngineState.brush();
KMETHOD QPaintEngineState_brush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		QBrush ret_v = qp->brush();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QPaintEngineState.brushNeedsResolving();
KMETHOD QPaintEngineState_brushNeedsResolving(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->brushNeedsResolving();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QPointF QPaintEngineState.brushOrigin();
KMETHOD QPaintEngineState_brushOrigin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		QPointF ret_v = qp->brushOrigin();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QPaintEngineState.clipOperation();
KMETHOD QPaintEngineState_clipOperation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		Qt::ClipOperation ret_v = qp->clipOperation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPainterPath QPaintEngineState.clipPath();
KMETHOD QPaintEngineState_clipPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		QPainterPath ret_v = qp->clipPath();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRegion QPaintEngineState.clipRegion();
KMETHOD QPaintEngineState_clipRegion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		QRegion ret_v = qp->clipRegion();
		QRegion *ret_v_ = new QRegion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QPaintEngineState.compositionMode();
KMETHOD QPaintEngineState_compositionMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		QPainter::CompositionMode ret_v = qp->compositionMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QFont QPaintEngineState.font();
KMETHOD QPaintEngineState_font(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		QFont ret_v = qp->font();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QPaintEngineState.isClipEnabled();
KMETHOD QPaintEngineState_isClipEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isClipEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//float QPaintEngineState.opacity();
KMETHOD QPaintEngineState_opacity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->opacity();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QPainter QPaintEngineState.painter();
KMETHOD QPaintEngineState_painter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		QPainter* ret_v = qp->painter();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPainter*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPen QPaintEngineState.pen();
KMETHOD QPaintEngineState_pen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		QPen ret_v = qp->pen();
		QPen *ret_v_ = new QPen(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QPaintEngineState.penNeedsResolving();
KMETHOD QPaintEngineState_penNeedsResolving(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->penNeedsResolving();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QPaintEngineState.renderHints();
KMETHOD QPaintEngineState_renderHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		QPainter::RenderHints ret_v = qp->renderHints();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPaintEngineState.state();
KMETHOD QPaintEngineState_state(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		QPaintEngine::DirtyFlags ret_v = qp->state();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTransform QPaintEngineState.transform();
KMETHOD QPaintEngineState_transform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngineState *  qp = RawPtr_to(QPaintEngineState *, sfp[0]);
	if (qp != NULL) {
		QTransform ret_v = qp->transform();
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQPaintEngineState::DummyQPaintEngineState()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPaintEngineState::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPaintEngineState::self = ptr;
}

bool DummyQPaintEngineState::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQPaintEngineState::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPaintEngineState::event_map->bigin();
	if ((itr = DummyQPaintEngineState::event_map->find(str)) == DummyQPaintEngineState::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPaintEngineState::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPaintEngineState::slot_map->bigin();
	if ((itr = DummyQPaintEngineState::event_map->find(str)) == DummyQPaintEngineState::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQPaintEngineState::KQPaintEngineState() : QPaintEngineState()
{
	self = NULL;
}

KMETHOD QPaintEngineState_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPaintEngineState *qp = RawPtr_to(KQPaintEngineState *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPaintEngineState]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQPaintEngineState::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPaintEngineState]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QPaintEngineState_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPaintEngineState *qp = RawPtr_to(KQPaintEngineState *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPaintEngineState]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQPaintEngineState::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPaintEngineState]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPaintEngineState_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPaintEngineState *qp = (KQPaintEngineState *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPaintEngineState_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQPaintEngineState *qp = (KQPaintEngineState *)p->rawptr;
		(void)qp;
	}
}

static int QPaintEngineState_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQPaintEngineState(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPaintEngineState";
	cdef->free = QPaintEngineState_free;
	cdef->reftrace = QPaintEngineState_reftrace;
	cdef->compareTo = QPaintEngineState_compareTo;
}


