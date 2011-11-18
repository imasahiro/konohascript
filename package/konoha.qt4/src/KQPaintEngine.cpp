//
//@Virtual boolean QPaintEngine.begin(QPaintDevice pdev);
KMETHOD QPaintEngine_begin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		QPaintDevice*  pdev = RawPtr_to(QPaintDevice*, sfp[1]);
		bool ret_v = qp->begin(pdev);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual void QPaintEngine.drawEllipse(QRectF rect);
KMETHOD QPaintEngine_drawEllipse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		qp->drawEllipse(rect);
	}
	RETURNvoid_();
}

/*
//@Virtual void QPaintEngine.drawEllipse(QRect rect);
KMETHOD QPaintEngine_drawEllipse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		qp->drawEllipse(rect);
	}
	RETURNvoid_();
}
*/
//@Virtual void QPaintEngine.drawImage(QRectF rectangle, QImage image, QRectF sr, QtImageConversionFlags flags);
KMETHOD QPaintEngine_drawImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		const QImage  image = *RawPtr_to(const QImage *, sfp[2]);
		const QRectF  sr = *RawPtr_to(const QRectF *, sfp[3]);
		initFlag(flags, Qt::ImageConversionFlags, sfp[4]);
		qp->drawImage(rectangle, image, sr, flags);
	}
	RETURNvoid_();
}

//@Virtual void QPaintEngine.drawLines(QLineF lines, int lineCount);
KMETHOD QPaintEngine_drawLines(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		const QLineF*  lines = RawPtr_to(const QLineF*, sfp[1]);
		int lineCount = Int_to(int, sfp[2]);
		qp->drawLines(lines, lineCount);
	}
	RETURNvoid_();
}

/*
//@Virtual void QPaintEngine.drawLines(QLine lines, int lineCount);
KMETHOD QPaintEngine_drawLines(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		const QLine*  lines = RawPtr_to(const QLine*, sfp[1]);
		int lineCount = Int_to(int, sfp[2]);
		qp->drawLines(lines, lineCount);
	}
	RETURNvoid_();
}
*/
//@Virtual void QPaintEngine.drawPath(QPainterPath path);
KMETHOD QPaintEngine_drawPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		qp->drawPath(path);
	}
	RETURNvoid_();
}

//@Virtual void QPaintEngine.drawPixmap(QRectF r, QPixmap pm, QRectF sr);
KMETHOD QPaintEngine_drawPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		const QRectF  r = *RawPtr_to(const QRectF *, sfp[1]);
		const QPixmap  pm = *RawPtr_to(const QPixmap *, sfp[2]);
		const QRectF  sr = *RawPtr_to(const QRectF *, sfp[3]);
		qp->drawPixmap(r, pm, sr);
	}
	RETURNvoid_();
}

//@Virtual void QPaintEngine.drawPoints(QPointF points, int pointCount);
KMETHOD QPaintEngine_drawPoints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		const QPointF*  points = RawPtr_to(const QPointF*, sfp[1]);
		int pointCount = Int_to(int, sfp[2]);
		qp->drawPoints(points, pointCount);
	}
	RETURNvoid_();
}

/*
//@Virtual void QPaintEngine.drawPoints(QPoint points, int pointCount);
KMETHOD QPaintEngine_drawPoints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		const QPoint*  points = RawPtr_to(const QPoint*, sfp[1]);
		int pointCount = Int_to(int, sfp[2]);
		qp->drawPoints(points, pointCount);
	}
	RETURNvoid_();
}
*/
//@Virtual void QPaintEngine.drawPolygon(QPointF points, int pointCount, int mode);
KMETHOD QPaintEngine_drawPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		const QPointF*  points = RawPtr_to(const QPointF*, sfp[1]);
		int pointCount = Int_to(int, sfp[2]);
		QPaintEngine::PolygonDrawMode mode = Int_to(QPaintEngine::PolygonDrawMode, sfp[3]);
		qp->drawPolygon(points, pointCount, mode);
	}
	RETURNvoid_();
}

/*
//@Virtual void QPaintEngine.drawPolygon(QPoint points, int pointCount, int mode);
KMETHOD QPaintEngine_drawPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		const QPoint*  points = RawPtr_to(const QPoint*, sfp[1]);
		int pointCount = Int_to(int, sfp[2]);
		QPaintEngine::PolygonDrawMode mode = Int_to(QPaintEngine::PolygonDrawMode, sfp[3]);
		qp->drawPolygon(points, pointCount, mode);
	}
	RETURNvoid_();
}
*/
//@Virtual void QPaintEngine.drawRects(QRectF rects, int rectCount);
KMETHOD QPaintEngine_drawRects(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		const QRectF*  rects = RawPtr_to(const QRectF*, sfp[1]);
		int rectCount = Int_to(int, sfp[2]);
		qp->drawRects(rects, rectCount);
	}
	RETURNvoid_();
}

/*
//@Virtual void QPaintEngine.drawRects(QRect rects, int rectCount);
KMETHOD QPaintEngine_drawRects(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		const QRect*  rects = RawPtr_to(const QRect*, sfp[1]);
		int rectCount = Int_to(int, sfp[2]);
		qp->drawRects(rects, rectCount);
	}
	RETURNvoid_();
}
*/
//@Virtual void QPaintEngine.drawTextItem(QPointF p, QTextItem textItem);
KMETHOD QPaintEngine_drawTextItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		const QPointF  p = *RawPtr_to(const QPointF *, sfp[1]);
		const QTextItem  textItem = *RawPtr_to(const QTextItem *, sfp[2]);
		qp->drawTextItem(p, textItem);
	}
	RETURNvoid_();
}

//@Virtual void QPaintEngine.drawTiledPixmap(QRectF rect, QPixmap pixmap, QPointF p);
KMETHOD QPaintEngine_drawTiledPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
		const QPointF  p = *RawPtr_to(const QPointF *, sfp[3]);
		qp->drawTiledPixmap(rect, pixmap, p);
	}
	RETURNvoid_();
}

//@Virtual boolean QPaintEngine.end();
KMETHOD QPaintEngine_end(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		bool ret_v = qp->end();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPaintEngine.hasFeature(QPaintEnginePaintEngineFeatures feature);
KMETHOD QPaintEngine_hasFeature(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		initFlag(feature, QPaintEngine::PaintEngineFeatures, sfp[1]);
		bool ret_v = qp->hasFeature(feature);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPaintEngine.isActive();
KMETHOD QPaintEngine_isActive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isActive();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QPaintDevice QPaintEngine.paintDevice();
KMETHOD QPaintEngine_paintDevice(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		QPaintDevice* ret_v = qp->paintDevice();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPaintDevice*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPainter QPaintEngine.painter();
KMETHOD QPaintEngine_painter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		QPainter* ret_v = qp->painter();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPainter*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QPaintEngine.setActive(boolean state);
KMETHOD QPaintEngine_setActive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		bool state = Boolean_to(bool, sfp[1]);
		qp->setActive(state);
	}
	RETURNvoid_();
}

//@Virtual int QPaintEngine.type();
KMETHOD QPaintEngine_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		QPaintEngine::Type ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual void QPaintEngine.updateState(QPaintEngineState state);
KMETHOD QPaintEngine_updateState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp) {
		const QPaintEngineState  state = *RawPtr_to(const QPaintEngineState *, sfp[1]);
		qp->updateState(state);
	}
	RETURNvoid_();
}

//Array<String> QPaintEngine.parents();
KMETHOD QPaintEngine_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *qp = RawPtr_to(QPaintEngine*, sfp[0]);
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

DummyQPaintEngine::DummyQPaintEngine()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQPaintEngine::~DummyQPaintEngine()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQPaintEngine::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPaintEngine::self = ptr;
}

bool DummyQPaintEngine::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQPaintEngine::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPaintEngine::event_map->bigin();
	if ((itr = DummyQPaintEngine::event_map->find(str)) == DummyQPaintEngine::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPaintEngine::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPaintEngine::slot_map->bigin();
	if ((itr = DummyQPaintEngine::slot_map->find(str)) == DummyQPaintEngine::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQPaintEngine::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQPaintEngine::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQPaintEngine::connection(QObject *o)
{
	QPaintEngine *p = dynamic_cast<QPaintEngine*>(o);
	if (p != NULL) {
	}
}

KQPaintEngine::KQPaintEngine(QPaintEngine::PaintEngineFeatures caps) : QPaintEngine(caps)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQPaintEngine();
}

KQPaintEngine::~KQPaintEngine()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QPaintEngine_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPaintEngine *qp = RawPtr_to(KQPaintEngine *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPaintEngine]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPaintEngine]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPaintEngine_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPaintEngine *qp = RawPtr_to(KQPaintEngine *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPaintEngine]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPaintEngine]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPaintEngine_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQPaintEngine *qp = (KQPaintEngine *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QPaintEngine*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QPaintEngine_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQPaintEngine *qp = (KQPaintEngine *)p->rawptr;
		KQPaintEngine *qp = static_cast<KQPaintEngine*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPaintEngine_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQPaintEngine::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QPaintEngineConstInt[] = {
	{"DirtyPen", QPaintEngine::DirtyPen},
	{"DirtyBrush", QPaintEngine::DirtyBrush},
	{"DirtyBrushOrigin", QPaintEngine::DirtyBrushOrigin},
	{"DirtyFont", QPaintEngine::DirtyFont},
	{"DirtyBackground", QPaintEngine::DirtyBackground},
	{"DirtyBackgroundMode", QPaintEngine::DirtyBackgroundMode},
	{"DirtyTransform", QPaintEngine::DirtyTransform},
	{"DirtyClipRegion", QPaintEngine::DirtyClipRegion},
	{"DirtyClipPath", QPaintEngine::DirtyClipPath},
	{"DirtyHints", QPaintEngine::DirtyHints},
	{"DirtyCompositionMode", QPaintEngine::DirtyCompositionMode},
	{"DirtyClipEnabled", QPaintEngine::DirtyClipEnabled},
	{"DirtyOpacity", QPaintEngine::DirtyOpacity},
	{"AllDirty", QPaintEngine::AllDirty},
//	{"AlphaBlend", QPaintEngine::AlphaBlend},
	{"Antialiasing", QPaintEngine::Antialiasing},
	{"BlendModes", QPaintEngine::BlendModes},
	{"BrushStroke", QPaintEngine::BrushStroke},
	{"ConicalGradientFill", QPaintEngine::ConicalGradientFill},
	{"ConstantOpacity", QPaintEngine::ConstantOpacity},
	{"LinearGradientFill", QPaintEngine::LinearGradientFill},
	{"MaskedBrush", QPaintEngine::MaskedBrush},
	{"ObjectBoundingModeGradients", QPaintEngine::ObjectBoundingModeGradients},
	{"PainterPaths", QPaintEngine::PainterPaths},
	{"PaintOutsidePaintEvent", QPaintEngine::PaintOutsidePaintEvent},
	{"PatternBrush", QPaintEngine::PatternBrush},
	{"PatternTransform", QPaintEngine::PatternTransform},
	{"PerspectiveTransform", QPaintEngine::PerspectiveTransform},
	{"PixmapTransform", QPaintEngine::PixmapTransform},
	{"PorterDuff", QPaintEngine::PorterDuff},
	{"PrimitiveTransform", QPaintEngine::PrimitiveTransform},
	{"RadialGradientFill", QPaintEngine::RadialGradientFill},
	{"RasterOpModes", QPaintEngine::RasterOpModes},
	{"AllFeatures", QPaintEngine::AllFeatures},
	{"OddEvenMode", QPaintEngine::OddEvenMode},
	{"WindingMode", QPaintEngine::WindingMode},
	{"ConvexMode", QPaintEngine::ConvexMode},
	{"PolylineMode", QPaintEngine::PolylineMode},
	{"X11", QPaintEngine::X11},
	{"Windows", QPaintEngine::Windows},
	{"MacPrinter", QPaintEngine::MacPrinter},
	{"CoreGraphics", QPaintEngine::CoreGraphics},
	{"QuickDraw", QPaintEngine::QuickDraw},
	{"QWindowSystem", QPaintEngine::QWindowSystem},
	{"PostScript", QPaintEngine::PostScript},
	{"OpenGL", QPaintEngine::OpenGL},
	{"Picture", QPaintEngine::Picture},
	{"SVG", QPaintEngine::SVG},
	{"Raster", QPaintEngine::Raster},
	{"Direct3D", QPaintEngine::Direct3D},
	{"Pdf", QPaintEngine::Pdf},
	{"OpenVG", QPaintEngine::OpenVG},
	{"User", QPaintEngine::User},
	{"MaxUser", QPaintEngine::MaxUser},
	{"OpenGL2", QPaintEngine::OpenGL2},
	{"PaintBuffer", QPaintEngine::PaintBuffer},
	{NULL, 0}
};

DEFAPI(void) constQPaintEngine(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QPaintEngineConstInt);
}


DEFAPI(void) defQPaintEngine(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPaintEngine";
	cdef->free = QPaintEngine_free;
	cdef->reftrace = QPaintEngine_reftrace;
	cdef->compareTo = QPaintEngine_compareTo;
}

//## QPaintEngineDirtyFlags QPaintEngineDirtyFlags.new(int value);
KMETHOD QPaintEngineDirtyFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPaintEngine::DirtyFlag i = Int_to(QPaintEngine::DirtyFlag, sfp[1]);
	QPaintEngine::DirtyFlags *ret_v = new QPaintEngine::DirtyFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QPaintEngineDirtyFlags QPaintEngineDirtyFlags.and(int mask);
KMETHOD QPaintEngineDirtyFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPaintEngine::DirtyFlags *qp = RawPtr_to(QPaintEngine::DirtyFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QPaintEngine::DirtyFlags ret = ((*qp) & i);
		QPaintEngine::DirtyFlags *ret_ = new QPaintEngine::DirtyFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPaintEngineDirtyFlags QPaintEngineDirtyFlags.iand(QPaintEngine::QPaintEngineDirtyFlags other);
KMETHOD QPaintEngineDirtyFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPaintEngine::DirtyFlags *qp = RawPtr_to(QPaintEngine::DirtyFlags*, sfp[0]);
	if (qp != NULL) {
		QPaintEngine::DirtyFlags *other = RawPtr_to(QPaintEngine::DirtyFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPaintEngineDirtyFlags QPaintEngineDirtyFlags.or(QPaintEngineDirtyFlags f);
KMETHOD QPaintEngineDirtyFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine::DirtyFlags *qp = RawPtr_to(QPaintEngine::DirtyFlags*, sfp[0]);
	if (qp != NULL) {
		QPaintEngine::DirtyFlags *f = RawPtr_to(QPaintEngine::DirtyFlags*, sfp[1]);
		QPaintEngine::DirtyFlags ret = ((*qp) | (*f));
		QPaintEngine::DirtyFlags *ret_ = new QPaintEngine::DirtyFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPaintEngineDirtyFlags QPaintEngineDirtyFlags.ior(QPaintEngine::QPaintEngineDirtyFlags other);
KMETHOD QPaintEngineDirtyFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPaintEngine::DirtyFlags *qp = RawPtr_to(QPaintEngine::DirtyFlags*, sfp[0]);
	if (qp != NULL) {
		QPaintEngine::DirtyFlags *other = RawPtr_to(QPaintEngine::DirtyFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPaintEngineDirtyFlags QPaintEngineDirtyFlags.xor(QPaintEngineDirtyFlags f);
KMETHOD QPaintEngineDirtyFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine::DirtyFlags *qp = RawPtr_to(QPaintEngine::DirtyFlags*, sfp[0]);
	if (qp != NULL) {
		QPaintEngine::DirtyFlags *f = RawPtr_to(QPaintEngine::DirtyFlags*, sfp[1]);
		QPaintEngine::DirtyFlags ret = ((*qp) ^ (*f));
		QPaintEngine::DirtyFlags *ret_ = new QPaintEngine::DirtyFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPaintEngineDirtyFlags QPaintEngineDirtyFlags.ixor(QPaintEngine::QPaintEngineDirtyFlags other);
KMETHOD QPaintEngineDirtyFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPaintEngine::DirtyFlags *qp = RawPtr_to(QPaintEngine::DirtyFlags*, sfp[0]);
	if (qp != NULL) {
		QPaintEngine::DirtyFlags *other = RawPtr_to(QPaintEngine::DirtyFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QPaintEngineDirtyFlags.testFlag(int flag);
KMETHOD QPaintEngineDirtyFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPaintEngine::DirtyFlags *qp = RawPtr_to(QPaintEngine::DirtyFlags *, sfp[0]);
	if (qp != NULL) {
		QPaintEngine::DirtyFlag flag = Int_to(QPaintEngine::DirtyFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QPaintEngineDirtyFlags.value();
KMETHOD QPaintEngineDirtyFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPaintEngine::DirtyFlags *qp = RawPtr_to(QPaintEngine::DirtyFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QPaintEngineDirtyFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QPaintEngine::DirtyFlags *qp = (QPaintEngine::DirtyFlags *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QPaintEngineDirtyFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QPaintEngine::DirtyFlags *qp = (QPaintEngine::DirtyFlags *)p->rawptr;
		(void)qp;
	}
}

static int QPaintEngineDirtyFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QPaintEngine::DirtyFlags*)p1->rawptr);
//		int v2 = int(*(QPaintEngine::DirtyFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QPaintEngine::DirtyFlags v1 = *(QPaintEngine::DirtyFlags*)p1->rawptr;
		QPaintEngine::DirtyFlags v2 = *(QPaintEngine::DirtyFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQPaintEngineDirtyFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPaintEngineDirtyFlags";
	cdef->free = QPaintEngineDirtyFlags_free;
	cdef->reftrace = QPaintEngineDirtyFlags_reftrace;
	cdef->compareTo = QPaintEngineDirtyFlags_compareTo;
}
//## QPaintEnginePaintEngineFeatures QPaintEnginePaintEngineFeatures.new(int value);
KMETHOD QPaintEnginePaintEngineFeatures_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPaintEngine::PaintEngineFeature i = Int_to(QPaintEngine::PaintEngineFeature, sfp[1]);
	QPaintEngine::PaintEngineFeatures *ret_v = new QPaintEngine::PaintEngineFeatures(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QPaintEnginePaintEngineFeatures QPaintEnginePaintEngineFeatures.and(int mask);
KMETHOD QPaintEnginePaintEngineFeatures_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPaintEngine::PaintEngineFeatures *qp = RawPtr_to(QPaintEngine::PaintEngineFeatures*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QPaintEngine::PaintEngineFeatures ret = ((*qp) & i);
		QPaintEngine::PaintEngineFeatures *ret_ = new QPaintEngine::PaintEngineFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPaintEnginePaintEngineFeatures QPaintEnginePaintEngineFeatures.iand(QPaintEngine::QPaintEnginePaintEngineFeatures other);
KMETHOD QPaintEnginePaintEngineFeatures_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPaintEngine::PaintEngineFeatures *qp = RawPtr_to(QPaintEngine::PaintEngineFeatures*, sfp[0]);
	if (qp != NULL) {
		QPaintEngine::PaintEngineFeatures *other = RawPtr_to(QPaintEngine::PaintEngineFeatures *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPaintEnginePaintEngineFeatures QPaintEnginePaintEngineFeatures.or(QPaintEnginePaintEngineFeatures f);
KMETHOD QPaintEnginePaintEngineFeatures_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine::PaintEngineFeatures *qp = RawPtr_to(QPaintEngine::PaintEngineFeatures*, sfp[0]);
	if (qp != NULL) {
		QPaintEngine::PaintEngineFeatures *f = RawPtr_to(QPaintEngine::PaintEngineFeatures*, sfp[1]);
		QPaintEngine::PaintEngineFeatures ret = ((*qp) | (*f));
		QPaintEngine::PaintEngineFeatures *ret_ = new QPaintEngine::PaintEngineFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPaintEnginePaintEngineFeatures QPaintEnginePaintEngineFeatures.ior(QPaintEngine::QPaintEnginePaintEngineFeatures other);
KMETHOD QPaintEnginePaintEngineFeatures_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPaintEngine::PaintEngineFeatures *qp = RawPtr_to(QPaintEngine::PaintEngineFeatures*, sfp[0]);
	if (qp != NULL) {
		QPaintEngine::PaintEngineFeatures *other = RawPtr_to(QPaintEngine::PaintEngineFeatures *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPaintEnginePaintEngineFeatures QPaintEnginePaintEngineFeatures.xor(QPaintEnginePaintEngineFeatures f);
KMETHOD QPaintEnginePaintEngineFeatures_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine::PaintEngineFeatures *qp = RawPtr_to(QPaintEngine::PaintEngineFeatures*, sfp[0]);
	if (qp != NULL) {
		QPaintEngine::PaintEngineFeatures *f = RawPtr_to(QPaintEngine::PaintEngineFeatures*, sfp[1]);
		QPaintEngine::PaintEngineFeatures ret = ((*qp) ^ (*f));
		QPaintEngine::PaintEngineFeatures *ret_ = new QPaintEngine::PaintEngineFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPaintEnginePaintEngineFeatures QPaintEnginePaintEngineFeatures.ixor(QPaintEngine::QPaintEnginePaintEngineFeatures other);
KMETHOD QPaintEnginePaintEngineFeatures_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPaintEngine::PaintEngineFeatures *qp = RawPtr_to(QPaintEngine::PaintEngineFeatures*, sfp[0]);
	if (qp != NULL) {
		QPaintEngine::PaintEngineFeatures *other = RawPtr_to(QPaintEngine::PaintEngineFeatures *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QPaintEnginePaintEngineFeatures.testFlag(int flag);
KMETHOD QPaintEnginePaintEngineFeatures_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPaintEngine::PaintEngineFeatures *qp = RawPtr_to(QPaintEngine::PaintEngineFeatures *, sfp[0]);
	if (qp != NULL) {
		QPaintEngine::PaintEngineFeature flag = Int_to(QPaintEngine::PaintEngineFeature, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QPaintEnginePaintEngineFeatures.value();
KMETHOD QPaintEnginePaintEngineFeatures_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPaintEngine::PaintEngineFeatures *qp = RawPtr_to(QPaintEngine::PaintEngineFeatures *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QPaintEnginePaintEngineFeatures_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QPaintEngine::PaintEngineFeatures *qp = (QPaintEngine::PaintEngineFeatures *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QPaintEnginePaintEngineFeatures_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QPaintEngine::PaintEngineFeatures *qp = (QPaintEngine::PaintEngineFeatures *)p->rawptr;
		(void)qp;
	}
}

static int QPaintEnginePaintEngineFeatures_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QPaintEngine::PaintEngineFeatures*)p1->rawptr);
//		int v2 = int(*(QPaintEngine::PaintEngineFeatures*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QPaintEngine::PaintEngineFeatures v1 = *(QPaintEngine::PaintEngineFeatures*)p1->rawptr;
		QPaintEngine::PaintEngineFeatures v2 = *(QPaintEngine::PaintEngineFeatures*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQPaintEnginePaintEngineFeatures(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPaintEnginePaintEngineFeatures";
	cdef->free = QPaintEnginePaintEngineFeatures_free;
	cdef->reftrace = QPaintEnginePaintEngineFeatures_reftrace;
	cdef->compareTo = QPaintEnginePaintEngineFeatures_compareTo;
}

