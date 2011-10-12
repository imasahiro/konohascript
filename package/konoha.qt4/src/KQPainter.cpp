//QPainter QPainter.new();
KMETHOD QPainter_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPainter *ret_v = new KQPainter();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPainter QPainter.new(QPaintDevice device);
KMETHOD QPainter_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintDevice*  device = RawPtr_to(QPaintDevice*, sfp[1]);
	KQPainter *ret_v = new KQPainter(device);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QBrush QPainter.getBackground();
KMETHOD QPainter_getBackground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QBrush ret_v = qp->background();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QPainter.getBackgroundMode();
KMETHOD QPainter_getBackgroundMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		Qt::BGMode ret_v = qp->backgroundMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QPainter.begin(QPaintDevice device);
KMETHOD QPainter_begin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		QPaintDevice*  device = RawPtr_to(QPaintDevice*, sfp[1]);
		bool ret_v = qp->begin(device);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QPainter.beginNativePainting();
KMETHOD QPainter_beginNativePainting(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		qp->beginNativePainting();
	}
	RETURNvoid_();
}

//QRectF QPainter.boundingRect(QRectF rectangle, int flags, String text);
KMETHOD QPainter_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		int flags = Int_to(int, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		QRectF ret_v = qp->boundingRect(rectangle, flags, text);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRect QPainter.boundingRect(QRect rectangle, int flags, String text);
KMETHOD QPainter_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		int flags = Int_to(int, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		QRect ret_v = qp->boundingRect(rectangle, flags, text);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QRect QPainter.boundingRect(int x, int y, int w, int h, int flags, String text);
KMETHOD QPainter_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int w = Int_to(int, sfp[3]);
		int h = Int_to(int, sfp[4]);
		int flags = Int_to(int, sfp[5]);
		const QString text = String_to(const QString, sfp[6]);
		QRect ret_v = qp->boundingRect(x, y, w, h, flags, text);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QRectF QPainter.boundingRect(QRectF rectangle, String text, QTextOption option);
KMETHOD QPainter_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		const QTextOption  option = *RawPtr_to(const QTextOption *, sfp[3]);
		QRectF ret_v = qp->boundingRect(rectangle, text, option);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QBrush QPainter.getBrush();
KMETHOD QPainter_getBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QBrush ret_v = qp->brush();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QPainter.getBrushOrigin();
KMETHOD QPainter_getBrushOrigin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		QPoint ret_v = qp->brushOrigin();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPainterPath QPainter.getClipPath();
KMETHOD QPainter_getClipPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		QPainterPath ret_v = qp->clipPath();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRegion QPainter.getClipRegion();
KMETHOD QPainter_getClipRegion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		QRegion ret_v = qp->clipRegion();
		QRegion *ret_v_ = new QRegion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTransform QPainter.combinedTransform();
KMETHOD QPainter_combinedTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		QTransform ret_v = qp->combinedTransform();
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QPainter.getCompositionMode();
KMETHOD QPainter_getCompositionMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		QPainter::CompositionMode ret_v = qp->compositionMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPaintDevice QPainter.device();
KMETHOD QPainter_device(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		QPaintDevice* ret_v = qp->device();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPaintDevice*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTransform QPainter.deviceTransform();
KMETHOD QPainter_deviceTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QTransform ret_v = qp->deviceTransform();
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QPainter.drawArc(QRectF rectangle, int startAngle, int spanAngle);
KMETHOD QPainter_drawArc(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		int startAngle = Int_to(int, sfp[2]);
		int spanAngle = Int_to(int, sfp[3]);
		qp->drawArc(rectangle, startAngle, spanAngle);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawArc(QRect rectangle, int startAngle, int spanAngle);
KMETHOD QPainter_drawArc(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		int startAngle = Int_to(int, sfp[2]);
		int spanAngle = Int_to(int, sfp[3]);
		qp->drawArc(rectangle, startAngle, spanAngle);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawArc(int x, int y, int width, int height, int startAngle, int spanAngle);
KMETHOD QPainter_drawArc(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		int startAngle = Int_to(int, sfp[5]);
		int spanAngle = Int_to(int, sfp[6]);
		qp->drawArc(x, y, width, height, startAngle, spanAngle);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawChord(QRectF rectangle, int startAngle, int spanAngle);
KMETHOD QPainter_drawChord(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		int startAngle = Int_to(int, sfp[2]);
		int spanAngle = Int_to(int, sfp[3]);
		qp->drawChord(rectangle, startAngle, spanAngle);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawChord(QRect rectangle, int startAngle, int spanAngle);
KMETHOD QPainter_drawChord(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		int startAngle = Int_to(int, sfp[2]);
		int spanAngle = Int_to(int, sfp[3]);
		qp->drawChord(rectangle, startAngle, spanAngle);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawChord(int x, int y, int width, int height, int startAngle, int spanAngle);
KMETHOD QPainter_drawChord(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		int startAngle = Int_to(int, sfp[5]);
		int spanAngle = Int_to(int, sfp[6]);
		qp->drawChord(x, y, width, height, startAngle, spanAngle);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawConvexPolygon(QPointF points, int pointCount);
KMETHOD QPainter_drawConvexPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPointF*  points = RawPtr_to(const QPointF*, sfp[1]);
		int pointCount = Int_to(int, sfp[2]);
		qp->drawConvexPolygon(points, pointCount);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawConvexPolygon(QPoint points, int pointCount);
KMETHOD QPainter_drawConvexPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPoint*  points = RawPtr_to(const QPoint*, sfp[1]);
		int pointCount = Int_to(int, sfp[2]);
		qp->drawConvexPolygon(points, pointCount);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawConvexPolygon(QPolygonF polygon);
KMETHOD QPainter_drawConvexPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPolygonF  polygon = *RawPtr_to(const QPolygonF *, sfp[1]);
		qp->drawConvexPolygon(polygon);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawConvexPolygon(QPolygon polygon);
KMETHOD QPainter_drawConvexPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPolygon  polygon = *RawPtr_to(const QPolygon *, sfp[1]);
		qp->drawConvexPolygon(polygon);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawEllipse(QRectF rectangle);
KMETHOD QPainter_drawEllipse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		qp->drawEllipse(rectangle);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawEllipse(QRect rectangle);
KMETHOD QPainter_drawEllipse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		qp->drawEllipse(rectangle);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawEllipse(int x, int y, int width, int height);
KMETHOD QPainter_drawEllipse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		qp->drawEllipse(x, y, width, height);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawEllipse(QPointF center, float rx, float ry);
KMETHOD QPainter_drawEllipse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPointF  center = *RawPtr_to(const QPointF *, sfp[1]);
		qreal rx = Float_to(qreal, sfp[2]);
		qreal ry = Float_to(qreal, sfp[3]);
		qp->drawEllipse(center, rx, ry);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawEllipse(QPoint center, int rx, int ry);
KMETHOD QPainter_drawEllipse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPoint  center = *RawPtr_to(const QPoint *, sfp[1]);
		int rx = Int_to(int, sfp[2]);
		int ry = Int_to(int, sfp[3]);
		qp->drawEllipse(center, rx, ry);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawImage(QRectF target, QImage image, QRectF source, int flags);
KMETHOD QPainter_drawImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  target = *RawPtr_to(const QRectF *, sfp[1]);
		const QImage  image = *RawPtr_to(const QImage *, sfp[2]);
		const QRectF  source = *RawPtr_to(const QRectF *, sfp[3]);
		Qt::ImageConversionFlags flags = Int_to(Qt::ImageConversionFlags, sfp[4]);
		qp->drawImage(target, image, source, flags);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawImage(QRect target, QImage image, QRect source, int flags);
KMETHOD QPainter_drawImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  target = *RawPtr_to(const QRect *, sfp[1]);
		const QImage  image = *RawPtr_to(const QImage *, sfp[2]);
		const QRect  source = *RawPtr_to(const QRect *, sfp[3]);
		Qt::ImageConversionFlags flags = Int_to(Qt::ImageConversionFlags, sfp[4]);
		qp->drawImage(target, image, source, flags);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawImage(QPointF point, QImage image);
KMETHOD QPainter_drawImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		const QImage  image = *RawPtr_to(const QImage *, sfp[2]);
		qp->drawImage(point, image);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawImage(QPoint point, QImage image);
KMETHOD QPainter_drawImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		const QImage  image = *RawPtr_to(const QImage *, sfp[2]);
		qp->drawImage(point, image);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawImage(QPointF point, QImage image, QRectF source, int flags);
KMETHOD QPainter_drawImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		const QImage  image = *RawPtr_to(const QImage *, sfp[2]);
		const QRectF  source = *RawPtr_to(const QRectF *, sfp[3]);
		Qt::ImageConversionFlags flags = Int_to(Qt::ImageConversionFlags, sfp[4]);
		qp->drawImage(point, image, source, flags);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawImage(QPoint point, QImage image, QRect source, int flags);
KMETHOD QPainter_drawImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		const QImage  image = *RawPtr_to(const QImage *, sfp[2]);
		const QRect  source = *RawPtr_to(const QRect *, sfp[3]);
		Qt::ImageConversionFlags flags = Int_to(Qt::ImageConversionFlags, sfp[4]);
		qp->drawImage(point, image, source, flags);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawImage(QRectF rectangle, QImage image);
KMETHOD QPainter_drawImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		const QImage  image = *RawPtr_to(const QImage *, sfp[2]);
		qp->drawImage(rectangle, image);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawImage(QRect rectangle, QImage image);
KMETHOD QPainter_drawImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		const QImage  image = *RawPtr_to(const QImage *, sfp[2]);
		qp->drawImage(rectangle, image);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawImage(int x, int y, QImage image, int sx, int sy, int sw, int sh, int flags);
KMETHOD QPainter_drawImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		const QImage  image = *RawPtr_to(const QImage *, sfp[3]);
		int sx = Int_to(int, sfp[4]);
		int sy = Int_to(int, sfp[5]);
		int sw = Int_to(int, sfp[6]);
		int sh = Int_to(int, sfp[7]);
		Qt::ImageConversionFlags flags = Int_to(Qt::ImageConversionFlags, sfp[8]);
		qp->drawImage(x, y, image, sx, sy, sw, sh, flags);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawLine(QLineF line);
KMETHOD QPainter_drawLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QLineF  line = *RawPtr_to(const QLineF *, sfp[1]);
		qp->drawLine(line);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawLine(QLine line);
KMETHOD QPainter_drawLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QLine  line = *RawPtr_to(const QLine *, sfp[1]);
		qp->drawLine(line);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawLine(QPoint p1, QPoint p2);
KMETHOD QPainter_drawLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPoint  p1 = *RawPtr_to(const QPoint *, sfp[1]);
		const QPoint  p2 = *RawPtr_to(const QPoint *, sfp[2]);
		qp->drawLine(p1, p2);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawLine(QPointF p1, QPointF p2);
KMETHOD QPainter_drawLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPointF  p1 = *RawPtr_to(const QPointF *, sfp[1]);
		const QPointF  p2 = *RawPtr_to(const QPointF *, sfp[2]);
		qp->drawLine(p1, p2);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawLine(int x1, int y1, int x2, int y2);
KMETHOD QPainter_drawLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x1 = Int_to(int, sfp[1]);
		int y1 = Int_to(int, sfp[2]);
		int x2 = Int_to(int, sfp[3]);
		int y2 = Int_to(int, sfp[4]);
		qp->drawLine(x1, y1, x2, y2);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawLines(QLineF lines, int lineCount);
KMETHOD QPainter_drawLines(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QLineF*  lines = RawPtr_to(const QLineF*, sfp[1]);
		int lineCount = Int_to(int, sfp[2]);
		qp->drawLines(lines, lineCount);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawLines(QLine lines, int lineCount);
KMETHOD QPainter_drawLines(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QLine*  lines = RawPtr_to(const QLine*, sfp[1]);
		int lineCount = Int_to(int, sfp[2]);
		qp->drawLines(lines, lineCount);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawLines(QPointF pointPairs, int lineCount);
KMETHOD QPainter_drawLines(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPointF*  pointPairs = RawPtr_to(const QPointF*, sfp[1]);
		int lineCount = Int_to(int, sfp[2]);
		qp->drawLines(pointPairs, lineCount);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawLines(QPoint pointPairs, int lineCount);
KMETHOD QPainter_drawLines(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPoint*  pointPairs = RawPtr_to(const QPoint*, sfp[1]);
		int lineCount = Int_to(int, sfp[2]);
		qp->drawLines(pointPairs, lineCount);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawPath(QPainterPath path);
KMETHOD QPainter_drawPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		qp->drawPath(path);
	}
	RETURNvoid_();
}

//void QPainter.drawPicture(QPointF point, QPicture picture);
KMETHOD QPainter_drawPicture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		const QPicture  picture = *RawPtr_to(const QPicture *, sfp[2]);
		qp->drawPicture(point, picture);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawPicture(QPoint point, QPicture picture);
KMETHOD QPainter_drawPicture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		const QPicture  picture = *RawPtr_to(const QPicture *, sfp[2]);
		qp->drawPicture(point, picture);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPicture(int x, int y, QPicture picture);
KMETHOD QPainter_drawPicture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		const QPicture  picture = *RawPtr_to(const QPicture *, sfp[3]);
		qp->drawPicture(x, y, picture);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawPie(QRectF rectangle, int startAngle, int spanAngle);
KMETHOD QPainter_drawPie(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		int startAngle = Int_to(int, sfp[2]);
		int spanAngle = Int_to(int, sfp[3]);
		qp->drawPie(rectangle, startAngle, spanAngle);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawPie(QRect rectangle, int startAngle, int spanAngle);
KMETHOD QPainter_drawPie(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		int startAngle = Int_to(int, sfp[2]);
		int spanAngle = Int_to(int, sfp[3]);
		qp->drawPie(rectangle, startAngle, spanAngle);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPie(int x, int y, int width, int height, int startAngle, int spanAngle);
KMETHOD QPainter_drawPie(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		int startAngle = Int_to(int, sfp[5]);
		int spanAngle = Int_to(int, sfp[6]);
		qp->drawPie(x, y, width, height, startAngle, spanAngle);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawPixmap(QRectF target, QPixmap pixmap, QRectF source);
KMETHOD QPainter_drawPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  target = *RawPtr_to(const QRectF *, sfp[1]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
		const QRectF  source = *RawPtr_to(const QRectF *, sfp[3]);
		qp->drawPixmap(target, pixmap, source);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawPixmap(QRect target, QPixmap pixmap, QRect source);
KMETHOD QPainter_drawPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  target = *RawPtr_to(const QRect *, sfp[1]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
		const QRect  source = *RawPtr_to(const QRect *, sfp[3]);
		qp->drawPixmap(target, pixmap, source);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPixmap(QPointF point, QPixmap pixmap, QRectF source);
KMETHOD QPainter_drawPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
		const QRectF  source = *RawPtr_to(const QRectF *, sfp[3]);
		qp->drawPixmap(point, pixmap, source);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPixmap(QPoint point, QPixmap pixmap, QRect source);
KMETHOD QPainter_drawPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
		const QRect  source = *RawPtr_to(const QRect *, sfp[3]);
		qp->drawPixmap(point, pixmap, source);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPixmap(QPointF point, QPixmap pixmap);
KMETHOD QPainter_drawPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
		qp->drawPixmap(point, pixmap);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPixmap(QPoint point, QPixmap pixmap);
KMETHOD QPainter_drawPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
		qp->drawPixmap(point, pixmap);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPixmap(int x, int y, QPixmap pixmap);
KMETHOD QPainter_drawPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[3]);
		qp->drawPixmap(x, y, pixmap);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPixmap(QRect rectangle, QPixmap pixmap);
KMETHOD QPainter_drawPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
		qp->drawPixmap(rectangle, pixmap);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPixmap(int x, int y, int width, int height, QPixmap pixmap);
KMETHOD QPainter_drawPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[5]);
		qp->drawPixmap(x, y, width, height, pixmap);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPixmap(int x, int y, int w, int h, QPixmap pixmap, int sx, int sy, int sw, int sh);
KMETHOD QPainter_drawPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int w = Int_to(int, sfp[3]);
		int h = Int_to(int, sfp[4]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[5]);
		int sx = Int_to(int, sfp[6]);
		int sy = Int_to(int, sfp[7]);
		int sw = Int_to(int, sfp[8]);
		int sh = Int_to(int, sfp[9]);
		qp->drawPixmap(x, y, w, h, pixmap, sx, sy, sw, sh);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPixmap(int x, int y, QPixmap pixmap, int sx, int sy, int sw, int sh);
KMETHOD QPainter_drawPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[3]);
		int sx = Int_to(int, sfp[4]);
		int sy = Int_to(int, sfp[5]);
		int sw = Int_to(int, sfp[6]);
		int sh = Int_to(int, sfp[7]);
		qp->drawPixmap(x, y, pixmap, sx, sy, sw, sh);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawPixmapFragments(int fragments, int fragmentCount, QPixmap pixmap, int hints);
KMETHOD QPainter_drawPixmapFragments(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPainter::PixmapFragment*  fragments = RawPtr_to(const QPainter::PixmapFragment*, sfp[1]);
		int fragmentCount = Int_to(int, sfp[2]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[3]);
		QPainter::PixmapFragmentHints hints = Int_to(QPainter::PixmapFragmentHints, sfp[4]);
		qp->drawPixmapFragments(fragments, fragmentCount, pixmap, hints);
	}
	RETURNvoid_();
}

//void QPainter.drawPoint(QPointF position);
KMETHOD QPainter_drawPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[1]);
		qp->drawPoint(position);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawPoint(QPoint position);
KMETHOD QPainter_drawPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		qp->drawPoint(position);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPoint(int x, int y);
KMETHOD QPainter_drawPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		qp->drawPoint(x, y);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawPoints(QPointF points, int pointCount);
KMETHOD QPainter_drawPoints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPointF*  points = RawPtr_to(const QPointF*, sfp[1]);
		int pointCount = Int_to(int, sfp[2]);
		qp->drawPoints(points, pointCount);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawPoints(QPoint points, int pointCount);
KMETHOD QPainter_drawPoints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPoint*  points = RawPtr_to(const QPoint*, sfp[1]);
		int pointCount = Int_to(int, sfp[2]);
		qp->drawPoints(points, pointCount);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPoints(QPolygonF points);
KMETHOD QPainter_drawPoints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPolygonF  points = *RawPtr_to(const QPolygonF *, sfp[1]);
		qp->drawPoints(points);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPoints(QPolygon points);
KMETHOD QPainter_drawPoints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPolygon  points = *RawPtr_to(const QPolygon *, sfp[1]);
		qp->drawPoints(points);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawPolygon(QPointF points, int pointCount, int fillRule);
KMETHOD QPainter_drawPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPointF*  points = RawPtr_to(const QPointF*, sfp[1]);
		int pointCount = Int_to(int, sfp[2]);
		Qt::FillRule fillRule = Int_to(Qt::FillRule, sfp[3]);
		qp->drawPolygon(points, pointCount, fillRule);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawPolygon(QPoint points, int pointCount, int fillRule);
KMETHOD QPainter_drawPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPoint*  points = RawPtr_to(const QPoint*, sfp[1]);
		int pointCount = Int_to(int, sfp[2]);
		Qt::FillRule fillRule = Int_to(Qt::FillRule, sfp[3]);
		qp->drawPolygon(points, pointCount, fillRule);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPolygon(QPolygonF points, int fillRule);
KMETHOD QPainter_drawPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPolygonF  points = *RawPtr_to(const QPolygonF *, sfp[1]);
		Qt::FillRule fillRule = Int_to(Qt::FillRule, sfp[2]);
		qp->drawPolygon(points, fillRule);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPolygon(QPolygon points, int fillRule);
KMETHOD QPainter_drawPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPolygon  points = *RawPtr_to(const QPolygon *, sfp[1]);
		Qt::FillRule fillRule = Int_to(Qt::FillRule, sfp[2]);
		qp->drawPolygon(points, fillRule);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawPolyline(QPointF points, int pointCount);
KMETHOD QPainter_drawPolyline(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPointF*  points = RawPtr_to(const QPointF*, sfp[1]);
		int pointCount = Int_to(int, sfp[2]);
		qp->drawPolyline(points, pointCount);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawPolyline(QPoint points, int pointCount);
KMETHOD QPainter_drawPolyline(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPoint*  points = RawPtr_to(const QPoint*, sfp[1]);
		int pointCount = Int_to(int, sfp[2]);
		qp->drawPolyline(points, pointCount);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPolyline(QPolygonF points);
KMETHOD QPainter_drawPolyline(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPolygonF  points = *RawPtr_to(const QPolygonF *, sfp[1]);
		qp->drawPolyline(points);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawPolyline(QPolygon points);
KMETHOD QPainter_drawPolyline(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPolygon  points = *RawPtr_to(const QPolygon *, sfp[1]);
		qp->drawPolyline(points);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawRect(QRectF rectangle);
KMETHOD QPainter_drawRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		qp->drawRect(rectangle);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawRect(QRect rectangle);
KMETHOD QPainter_drawRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		qp->drawRect(rectangle);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawRect(int x, int y, int width, int height);
KMETHOD QPainter_drawRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		qp->drawRect(x, y, width, height);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawRects(QRectF rectangles, int rectCount);
KMETHOD QPainter_drawRects(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF*  rectangles = RawPtr_to(const QRectF*, sfp[1]);
		int rectCount = Int_to(int, sfp[2]);
		qp->drawRects(rectangles, rectCount);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawRects(QRect rectangles, int rectCount);
KMETHOD QPainter_drawRects(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect*  rectangles = RawPtr_to(const QRect*, sfp[1]);
		int rectCount = Int_to(int, sfp[2]);
		qp->drawRects(rectangles, rectCount);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawRoundedRect(QRectF rect, float xRadius, float yRadius, int mode);
KMETHOD QPainter_drawRoundedRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		qreal xRadius = Float_to(qreal, sfp[2]);
		qreal yRadius = Float_to(qreal, sfp[3]);
		Qt::SizeMode mode = Int_to(Qt::SizeMode, sfp[4]);
		qp->drawRoundedRect(rect, xRadius, yRadius, mode);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawRoundedRect(QRect rect, float xRadius, float yRadius, int mode);
KMETHOD QPainter_drawRoundedRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		qreal xRadius = Float_to(qreal, sfp[2]);
		qreal yRadius = Float_to(qreal, sfp[3]);
		Qt::SizeMode mode = Int_to(Qt::SizeMode, sfp[4]);
		qp->drawRoundedRect(rect, xRadius, yRadius, mode);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawRoundedRect(int x, int y, int w, int h, float xRadius, float yRadius, int mode);
KMETHOD QPainter_drawRoundedRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int w = Int_to(int, sfp[3]);
		int h = Int_to(int, sfp[4]);
		qreal xRadius = Float_to(qreal, sfp[5]);
		qreal yRadius = Float_to(qreal, sfp[6]);
		Qt::SizeMode mode = Int_to(Qt::SizeMode, sfp[7]);
		qp->drawRoundedRect(x, y, w, h, xRadius, yRadius, mode);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawStaticText(QPointF topLeftPosition, QStaticText staticText);
KMETHOD QPainter_drawStaticText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPointF  topLeftPosition = *RawPtr_to(const QPointF *, sfp[1]);
		const QStaticText  staticText = *RawPtr_to(const QStaticText *, sfp[2]);
		qp->drawStaticText(topLeftPosition, staticText);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawStaticText(QPoint topLeftPosition, QStaticText staticText);
KMETHOD QPainter_drawStaticText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPoint  topLeftPosition = *RawPtr_to(const QPoint *, sfp[1]);
		const QStaticText  staticText = *RawPtr_to(const QStaticText *, sfp[2]);
		qp->drawStaticText(topLeftPosition, staticText);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawStaticText(int left, int top, QStaticText staticText);
KMETHOD QPainter_drawStaticText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int left = Int_to(int, sfp[1]);
		int top = Int_to(int, sfp[2]);
		const QStaticText  staticText = *RawPtr_to(const QStaticText *, sfp[3]);
		qp->drawStaticText(left, top, staticText);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawText(QPointF position, String text);
KMETHOD QPainter_drawText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		qp->drawText(position, text);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawText(QPoint position, String text);
KMETHOD QPainter_drawText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		qp->drawText(position, text);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawText(QRectF rectangle, int flags, String text, QRectF boundingRect);
KMETHOD QPainter_drawText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		int flags = Int_to(int, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		QRectF*  boundingRect = RawPtr_to(QRectF*, sfp[4]);
		qp->drawText(rectangle, flags, text, boundingRect);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawText(QRect rectangle, int flags, String text, QRect boundingRect);
KMETHOD QPainter_drawText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		int flags = Int_to(int, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		QRect*  boundingRect = RawPtr_to(QRect*, sfp[4]);
		qp->drawText(rectangle, flags, text, boundingRect);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawText(int x, int y, String text);
KMETHOD QPainter_drawText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		qp->drawText(x, y, text);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawText(int x, int y, int width, int height, int flags, String text, QRect boundingRect);
KMETHOD QPainter_drawText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		int flags = Int_to(int, sfp[5]);
		const QString text = String_to(const QString, sfp[6]);
		QRect*  boundingRect = RawPtr_to(QRect*, sfp[7]);
		qp->drawText(x, y, width, height, flags, text, boundingRect);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawText(QRectF rectangle, String text, QTextOption option);
KMETHOD QPainter_drawText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		const QTextOption  option = *RawPtr_to(const QTextOption *, sfp[3]);
		qp->drawText(rectangle, text, option);
	}
	RETURNvoid_();
}
*/
//void QPainter.drawTiledPixmap(QRectF rectangle, QPixmap pixmap, QPointF position);
KMETHOD QPainter_drawTiledPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[3]);
		qp->drawTiledPixmap(rectangle, pixmap, position);
	}
	RETURNvoid_();
}

/*
//void QPainter.drawTiledPixmap(QRect rectangle, QPixmap pixmap, QPoint position);
KMETHOD QPainter_drawTiledPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[3]);
		qp->drawTiledPixmap(rectangle, pixmap, position);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.drawTiledPixmap(int x, int y, int width, int height, QPixmap pixmap, int sx, int sy);
KMETHOD QPainter_drawTiledPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[5]);
		int sx = Int_to(int, sfp[6]);
		int sy = Int_to(int, sfp[7]);
		qp->drawTiledPixmap(x, y, width, height, pixmap, sx, sy);
	}
	RETURNvoid_();
}
*/
//boolean QPainter.end();
KMETHOD QPainter_end(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->end();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QPainter.endNativePainting();
KMETHOD QPainter_endNativePainting(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		qp->endNativePainting();
	}
	RETURNvoid_();
}

//void QPainter.eraseRect(QRectF rectangle);
KMETHOD QPainter_eraseRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		qp->eraseRect(rectangle);
	}
	RETURNvoid_();
}

/*
//void QPainter.eraseRect(QRect rectangle);
KMETHOD QPainter_eraseRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		qp->eraseRect(rectangle);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.eraseRect(int x, int y, int width, int height);
KMETHOD QPainter_eraseRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		qp->eraseRect(x, y, width, height);
	}
	RETURNvoid_();
}
*/
//void QPainter.fillPath(QPainterPath path, QBrush brush);
KMETHOD QPainter_fillPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[2]);
		qp->fillPath(path, brush);
	}
	RETURNvoid_();
}

//void QPainter.fillRect(QRectF rectangle, QBrush brush);
KMETHOD QPainter_fillRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[2]);
		qp->fillRect(rectangle, brush);
	}
	RETURNvoid_();
}

/*
//void QPainter.fillRect(int x, int y, int width, int height, int style);
KMETHOD QPainter_fillRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		Qt::BrushStyle style = Int_to(Qt::BrushStyle, sfp[5]);
		qp->fillRect(x, y, width, height, style);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.fillRect(QRect rectangle, int style);
KMETHOD QPainter_fillRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		Qt::BrushStyle style = Int_to(Qt::BrushStyle, sfp[2]);
		qp->fillRect(rectangle, style);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.fillRect(QRectF rectangle, int style);
KMETHOD QPainter_fillRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		Qt::BrushStyle style = Int_to(Qt::BrushStyle, sfp[2]);
		qp->fillRect(rectangle, style);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.fillRect(QRect rectangle, QBrush brush);
KMETHOD QPainter_fillRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[2]);
		qp->fillRect(rectangle, brush);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.fillRect(QRect rectangle, QColor color);
KMETHOD QPainter_fillRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		const QColor  color = *RawPtr_to(const QColor *, sfp[2]);
		qp->fillRect(rectangle, color);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.fillRect(QRectF rectangle, QColor color);
KMETHOD QPainter_fillRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		const QColor  color = *RawPtr_to(const QColor *, sfp[2]);
		qp->fillRect(rectangle, color);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.fillRect(int x, int y, int width, int height, QBrush brush);
KMETHOD QPainter_fillRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[5]);
		qp->fillRect(x, y, width, height, brush);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.fillRect(int x, int y, int width, int height, QColor color);
KMETHOD QPainter_fillRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		const QColor  color = *RawPtr_to(const QColor *, sfp[5]);
		qp->fillRect(x, y, width, height, color);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.fillRect(int x, int y, int width, int height, int color);
KMETHOD QPainter_fillRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		Qt::GlobalColor color = Int_to(Qt::GlobalColor, sfp[5]);
		qp->fillRect(x, y, width, height, color);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.fillRect(QRect rectangle, int color);
KMETHOD QPainter_fillRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		Qt::GlobalColor color = Int_to(Qt::GlobalColor, sfp[2]);
		qp->fillRect(rectangle, color);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.fillRect(QRectF rectangle, int color);
KMETHOD QPainter_fillRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		Qt::GlobalColor color = Int_to(Qt::GlobalColor, sfp[2]);
		qp->fillRect(rectangle, color);
	}
	RETURNvoid_();
}
*/
//QFont QPainter.getFont();
KMETHOD QPainter_getFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QFont ret_v = qp->font();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFontInfo QPainter.fontInfo();
KMETHOD QPainter_fontInfo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		QFontInfo ret_v = qp->fontInfo();
		QFontInfo *ret_v_ = new QFontInfo(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFontMetrics QPainter.fontMetrics();
KMETHOD QPainter_fontMetrics(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		QFontMetrics ret_v = qp->fontMetrics();
		QFontMetrics *ret_v_ = new QFontMetrics(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QPainter.hasClipping();
KMETHOD QPainter_hasClipping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->hasClipping();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QPainter.initFrom(QWidget widget);
KMETHOD QPainter_initFrom(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[1]);
		qp->initFrom(widget);
	}
	RETURNvoid_();
}

//boolean QPainter.isActive();
KMETHOD QPainter_isActive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isActive();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QPainter.getLayoutDirection();
KMETHOD QPainter_getLayoutDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		Qt::LayoutDirection ret_v = qp->layoutDirection();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QPainter.getOpacity();
KMETHOD QPainter_getOpacity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->opacity();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QPaintEngine QPainter.paintEngine();
KMETHOD QPainter_paintEngine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		QPaintEngine* ret_v = qp->paintEngine();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPaintEngine*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPen QPainter.getPen();
KMETHOD QPainter_getPen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPen ret_v = qp->pen();
		QPen *ret_v_ = new QPen(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QPainter.getRenderHints();
KMETHOD QPainter_getRenderHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		QPainter::RenderHints ret_v = qp->renderHints();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QPainter.resetTransform();
KMETHOD QPainter_resetTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		qp->resetTransform();
	}
	RETURNvoid_();
}

//void QPainter.restore();
KMETHOD QPainter_restore(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		qp->restore();
	}
	RETURNvoid_();
}

//void QPainter.rotate(float angle);
KMETHOD QPainter_rotate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		qreal angle = Float_to(qreal, sfp[1]);
		qp->rotate(angle);
	}
	RETURNvoid_();
}

//void QPainter.save();
KMETHOD QPainter_save(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		qp->save();
	}
	RETURNvoid_();
}

//void QPainter.scale(float sx, float sy);
KMETHOD QPainter_scale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		qreal sx = Float_to(qreal, sfp[1]);
		qreal sy = Float_to(qreal, sfp[2]);
		qp->scale(sx, sy);
	}
	RETURNvoid_();
}

//void QPainter.setBackground(QBrush brush);
KMETHOD QPainter_setBackground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[1]);
		qp->setBackground(brush);
	}
	RETURNvoid_();
}

//void QPainter.setBackgroundMode(int mode);
KMETHOD QPainter_setBackgroundMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		Qt::BGMode mode = Int_to(Qt::BGMode, sfp[1]);
		qp->setBackgroundMode(mode);
	}
	RETURNvoid_();
}

//void QPainter.setBrush(QBrush brush);
KMETHOD QPainter_setBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[1]);
		qp->setBrush(brush);
	}
	RETURNvoid_();
}

/*
//void QPainter.setBrush(int style);
KMETHOD QPainter_setBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		Qt::BrushStyle style = Int_to(Qt::BrushStyle, sfp[1]);
		qp->setBrush(style);
	}
	RETURNvoid_();
}
*/
//void QPainter.setBrushOrigin(QPointF position);
KMETHOD QPainter_setBrushOrigin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setBrushOrigin(position);
	}
	RETURNvoid_();
}

/*
//void QPainter.setBrushOrigin(QPoint position);
KMETHOD QPainter_setBrushOrigin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		qp->setBrushOrigin(position);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.setBrushOrigin(int x, int y);
KMETHOD QPainter_setBrushOrigin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		qp->setBrushOrigin(x, y);
	}
	RETURNvoid_();
}
*/
//void QPainter.setClipPath(QPainterPath path, int operation);
KMETHOD QPainter_setClipPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		Qt::ClipOperation operation = Int_to(Qt::ClipOperation, sfp[2]);
		qp->setClipPath(path, operation);
	}
	RETURNvoid_();
}

//void QPainter.setClipRect(QRectF rectangle, int operation);
KMETHOD QPainter_setClipRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		Qt::ClipOperation operation = Int_to(Qt::ClipOperation, sfp[2]);
		qp->setClipRect(rectangle, operation);
	}
	RETURNvoid_();
}

/*
//void QPainter.setClipRect(int x, int y, int width, int height, int operation);
KMETHOD QPainter_setClipRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		Qt::ClipOperation operation = Int_to(Qt::ClipOperation, sfp[5]);
		qp->setClipRect(x, y, width, height, operation);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.setClipRect(QRect rectangle, int operation);
KMETHOD QPainter_setClipRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		Qt::ClipOperation operation = Int_to(Qt::ClipOperation, sfp[2]);
		qp->setClipRect(rectangle, operation);
	}
	RETURNvoid_();
}
*/
//void QPainter.setClipRegion(QRegion region, int operation);
KMETHOD QPainter_setClipRegion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRegion  region = *RawPtr_to(const QRegion *, sfp[1]);
		Qt::ClipOperation operation = Int_to(Qt::ClipOperation, sfp[2]);
		qp->setClipRegion(region, operation);
	}
	RETURNvoid_();
}

//void QPainter.setClipping(boolean enable);
KMETHOD QPainter_setClipping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setClipping(enable);
	}
	RETURNvoid_();
}

//void QPainter.setCompositionMode(int mode);
KMETHOD QPainter_setCompositionMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		QPainter::CompositionMode mode = Int_to(QPainter::CompositionMode, sfp[1]);
		qp->setCompositionMode(mode);
	}
	RETURNvoid_();
}

//void QPainter.setFont(QFont font);
KMETHOD QPainter_setFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
		qp->setFont(font);
	}
	RETURNvoid_();
}

//void QPainter.setLayoutDirection(int direction);
KMETHOD QPainter_setLayoutDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		Qt::LayoutDirection direction = Int_to(Qt::LayoutDirection, sfp[1]);
		qp->setLayoutDirection(direction);
	}
	RETURNvoid_();
}

//void QPainter.setOpacity(float opacity);
KMETHOD QPainter_setOpacity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		qreal opacity = Float_to(qreal, sfp[1]);
		qp->setOpacity(opacity);
	}
	RETURNvoid_();
}

//void QPainter.setPen(QPen pen);
KMETHOD QPainter_setPen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPen  pen = *RawPtr_to(const QPen *, sfp[1]);
		qp->setPen(pen);
	}
	RETURNvoid_();
}

/*
//void QPainter.setPen(QColor color);
KMETHOD QPainter_setPen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QColor  color = *RawPtr_to(const QColor *, sfp[1]);
		qp->setPen(color);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.setPen(int style);
KMETHOD QPainter_setPen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		Qt::PenStyle style = Int_to(Qt::PenStyle, sfp[1]);
		qp->setPen(style);
	}
	RETURNvoid_();
}
*/
//void QPainter.setRenderHint(int hint, boolean on);
KMETHOD QPainter_setRenderHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		QPainter::RenderHint hint = Int_to(QPainter::RenderHint, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		qp->setRenderHint(hint, on);
	}
	RETURNvoid_();
}

//void QPainter.setRenderHints(int hints, boolean on);
KMETHOD QPainter_setRenderHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		QPainter::RenderHints hints = Int_to(QPainter::RenderHints, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		qp->setRenderHints(hints, on);
	}
	RETURNvoid_();
}

//void QPainter.setTransform(QTransform transform, boolean combine);
KMETHOD QPainter_setTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QTransform  transform = *RawPtr_to(const QTransform *, sfp[1]);
		bool combine = Boolean_to(bool, sfp[2]);
		qp->setTransform(transform, combine);
	}
	RETURNvoid_();
}

//void QPainter.setViewTransformEnabled(boolean enable);
KMETHOD QPainter_setViewTransformEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setViewTransformEnabled(enable);
	}
	RETURNvoid_();
}

//void QPainter.setViewport(QRect rectangle);
KMETHOD QPainter_setViewport(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		qp->setViewport(rectangle);
	}
	RETURNvoid_();
}

/*
//void QPainter.setViewport(int x, int y, int width, int height);
KMETHOD QPainter_setViewport(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		qp->setViewport(x, y, width, height);
	}
	RETURNvoid_();
}
*/
//void QPainter.setWindow(QRect rectangle);
KMETHOD QPainter_setWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		qp->setWindow(rectangle);
	}
	RETURNvoid_();
}

/*
//void QPainter.setWindow(int x, int y, int width, int height);
KMETHOD QPainter_setWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		qp->setWindow(x, y, width, height);
	}
	RETURNvoid_();
}
*/
//void QPainter.setWorldMatrixEnabled(boolean enable);
KMETHOD QPainter_setWorldMatrixEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setWorldMatrixEnabled(enable);
	}
	RETURNvoid_();
}

//void QPainter.setWorldTransform(QTransform matrix, boolean combine);
KMETHOD QPainter_setWorldTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QTransform  matrix = *RawPtr_to(const QTransform *, sfp[1]);
		bool combine = Boolean_to(bool, sfp[2]);
		qp->setWorldTransform(matrix, combine);
	}
	RETURNvoid_();
}

//void QPainter.shear(float sh, float sv);
KMETHOD QPainter_shear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		qreal sh = Float_to(qreal, sfp[1]);
		qreal sv = Float_to(qreal, sfp[2]);
		qp->shear(sh, sv);
	}
	RETURNvoid_();
}

//void QPainter.strokePath(QPainterPath path, QPen pen);
KMETHOD QPainter_strokePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		const QPen  pen = *RawPtr_to(const QPen *, sfp[2]);
		qp->strokePath(path, pen);
	}
	RETURNvoid_();
}

//boolean QPainter.testRenderHint(int hint);
KMETHOD QPainter_testRenderHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		QPainter::RenderHint hint = Int_to(QPainter::RenderHint, sfp[1]);
		bool ret_v = qp->testRenderHint(hint);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QTransform QPainter.getTransform();
KMETHOD QPainter_getTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QTransform ret_v = qp->transform();
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QPainter.translate(QPointF offset);
KMETHOD QPainter_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPointF  offset = *RawPtr_to(const QPointF *, sfp[1]);
		qp->translate(offset);
	}
	RETURNvoid_();
}

/*
//void QPainter.translate(QPoint offset);
KMETHOD QPainter_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QPoint  offset = *RawPtr_to(const QPoint *, sfp[1]);
		qp->translate(offset);
	}
	RETURNvoid_();
}
*/
/*
//void QPainter.translate(float dx, float dy);
KMETHOD QPainter_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		qreal dx = Float_to(qreal, sfp[1]);
		qreal dy = Float_to(qreal, sfp[2]);
		qp->translate(dx, dy);
	}
	RETURNvoid_();
}
*/
//boolean QPainter.getViewTransformEnabled();
KMETHOD QPainter_getViewTransformEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->viewTransformEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QRect QPainter.getViewport();
KMETHOD QPainter_getViewport(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		QRect ret_v = qp->viewport();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QPainter.getWindow();
KMETHOD QPainter_getWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		QRect ret_v = qp->window();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QPainter.getWorldMatrixEnabled();
KMETHOD QPainter_getWorldMatrixEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->worldMatrixEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QTransform QPainter.getWorldTransform();
KMETHOD QPainter_getWorldTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainter *  qp = RawPtr_to(QPainter *, sfp[0]);
	if (qp != NULL) {
		const QTransform ret_v = qp->worldTransform();
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQPainter::DummyQPainter()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPainter::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPainter::self = ptr;
}

bool DummyQPainter::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQPainter::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPainter::event_map->bigin();
	if ((itr = DummyQPainter::event_map->find(str)) == DummyQPainter::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPainter::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPainter::slot_map->bigin();
	if ((itr = DummyQPainter::event_map->find(str)) == DummyQPainter::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQPainter::KQPainter() : QPainter()
{
	self = NULL;
}

KMETHOD QPainter_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPainter *qp = RawPtr_to(KQPainter *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPainter]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQPainter::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPainter]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QPainter_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPainter *qp = RawPtr_to(KQPainter *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPainter]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQPainter::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPainter]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPainter_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPainter *qp = (KQPainter *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPainter_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQPainter *qp = (KQPainter *)p->rawptr;
		(void)qp;
	}
}

static int QPainter_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQPainter(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPainter";
	cdef->free = QPainter_free;
	cdef->reftrace = QPainter_reftrace;
	cdef->compareTo = QPainter_compareTo;
}

static knh_IntData_t QPainterConstInt[] = {
	{"CompositionMode_SourceOver", QPainter::CompositionMode_SourceOver},
	{"CompositionMode_DestinationOver", QPainter::CompositionMode_DestinationOver},
	{"CompositionMode_Clear", QPainter::CompositionMode_Clear},
	{"CompositionMode_Source", QPainter::CompositionMode_Source},
	{"CompositionMode_Destination", QPainter::CompositionMode_Destination},
	{"CompositionMode_SourceIn", QPainter::CompositionMode_SourceIn},
	{"CompositionMode_DestinationIn", QPainter::CompositionMode_DestinationIn},
	{"CompositionMode_SourceOut", QPainter::CompositionMode_SourceOut},
	{"CompositionMode_DestinationOut", QPainter::CompositionMode_DestinationOut},
	{"CompositionMode_SourceAtop", QPainter::CompositionMode_SourceAtop},
	{"CompositionMode_DestinationAtop", QPainter::CompositionMode_DestinationAtop},
	{"CompositionMode_Xor", QPainter::CompositionMode_Xor},
	{"CompositionMode_Plus", QPainter::CompositionMode_Plus},
	{"CompositionMode_Multiply", QPainter::CompositionMode_Multiply},
	{"CompositionMode_Screen", QPainter::CompositionMode_Screen},
	{"CompositionMode_Overlay", QPainter::CompositionMode_Overlay},
	{"CompositionMode_Darken", QPainter::CompositionMode_Darken},
	{"CompositionMode_Lighten", QPainter::CompositionMode_Lighten},
	{"CompositionMode_ColorDodge", QPainter::CompositionMode_ColorDodge},
	{"CompositionMode_ColorBurn", QPainter::CompositionMode_ColorBurn},
	{"CompositionMode_HardLight", QPainter::CompositionMode_HardLight},
	{"CompositionMode_SoftLight", QPainter::CompositionMode_SoftLight},
	{"CompositionMode_Difference", QPainter::CompositionMode_Difference},
	{"CompositionMode_Exclusion", QPainter::CompositionMode_Exclusion},
	{"RasterOp_SourceOrDestination", QPainter::RasterOp_SourceOrDestination},
	{"RasterOp_SourceAndDestination", QPainter::RasterOp_SourceAndDestination},
	{"RasterOp_SourceXorDestination", QPainter::RasterOp_SourceXorDestination},
	{"RasterOp_NotSourceAndNotDestination", QPainter::RasterOp_NotSourceAndNotDestination},
	{"RasterOp_NotSourceOrNotDestination", QPainter::RasterOp_NotSourceOrNotDestination},
	{"RasterOp_NotSourceXorDestination", QPainter::RasterOp_NotSourceXorDestination},
	{"RasterOp_NotSource", QPainter::RasterOp_NotSource},
	{"RasterOp_NotSourceAndDestination", QPainter::RasterOp_NotSourceAndDestination},
	{"RasterOp_SourceAndNotDestination", QPainter::RasterOp_SourceAndNotDestination},
	{"OpaqueHint", QPainter::OpaqueHint},
	{"Antialiasing", QPainter::Antialiasing},
	{"TextAntialiasing", QPainter::TextAntialiasing},
	{"SmoothPixmapTransform", QPainter::SmoothPixmapTransform},
	{"HighQualityAntialiasing", QPainter::HighQualityAntialiasing},
	{"NonCosmeticDefaultPen", QPainter::NonCosmeticDefaultPen},
	{NULL, 0}
};

DEFAPI(void) constQPainter(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QPainterConstInt);
}

