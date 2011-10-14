//
//@Virtual boolean QPaintEngine.begin(QPaintDevice pdev);
KMETHOD QPaintEngine_begin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		qp->drawEllipse(rect);
	}
	RETURNvoid_();
}
*/
//@Virtual void QPaintEngine.drawImage(QRectF rectangle, QImage image, QRectF sr, int flags);
KMETHOD QPaintEngine_drawImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		const QImage  image = *RawPtr_to(const QImage *, sfp[2]);
		const QRectF  sr = *RawPtr_to(const QRectF *, sfp[3]);
		Qt::ImageConversionFlags flags = Int_to(Qt::ImageConversionFlags, sfp[4]);
		qp->drawImage(rectangle, image, sr, flags);
	}
	RETURNvoid_();
}

//@Virtual void QPaintEngine.drawLines(QLineF lines, int lineCount);
KMETHOD QPaintEngine_drawLines(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		bool ret_v = qp->end();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPaintEngine.hasFeature(int feature);
KMETHOD QPaintEngine_hasFeature(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEngine *  qp = RawPtr_to(QPaintEngine *, sfp[0]);
	if (qp != NULL) {
		QPaintEngine::PaintEngineFeatures feature = Int_to(QPaintEngine::PaintEngineFeatures, sfp[1]);
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		const QPaintEngineState  state = *RawPtr_to(const QPaintEngineState *, sfp[1]);
		qp->updateState(state);
	}
	RETURNvoid_();
}


DummyQPaintEngine::DummyQPaintEngine()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
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


void DummyQPaintEngine::connection(QObject *o)
{
	return;
}

KQPaintEngine::KQPaintEngine(QPaintEngine::PaintEngineFeatures caps) : QPaintEngine(caps)
{
	self = NULL;
	dummy = new DummyQPaintEngine();
	dummy->connection((QObject*)this);
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
	if (p->rawptr != NULL) {
		KQPaintEngine *qp = (KQPaintEngine *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPaintEngine_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQPaintEngine *qp = (KQPaintEngine *)p->rawptr;
		(void)qp;
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

DEFAPI(void) defQPaintEngine(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPaintEngine";
	cdef->free = QPaintEngine_free;
	cdef->reftrace = QPaintEngine_reftrace;
	cdef->compareTo = QPaintEngine_compareTo;
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

