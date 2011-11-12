//QPainterPath QPainterPath.new();
KMETHOD QPainterPath_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPainterPath *ret_v = new KQPainterPath();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPainterPath QPainterPath.new(QPointF startPoint);
KMETHOD QPainterPath_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPointF  startPoint = *RawPtr_to(const QPointF *, sfp[1]);
	KQPainterPath *ret_v = new KQPainterPath(startPoint);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPainterPath QPainterPath.new(QPainterPath path);
KMETHOD QPainterPath_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
	KQPainterPath *ret_v = new KQPainterPath(path);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QPainterPath.addEllipse(QRectF boundingRectangle);
KMETHOD QPainterPath_addEllipse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QRectF  boundingRectangle = *RawPtr_to(const QRectF *, sfp[1]);
		qp->addEllipse(boundingRectangle);
	}
	RETURNvoid_();
}

/*
//void QPainterPath.addEllipse(float x, float y, float width, float height);
KMETHOD QPainterPath_addEllipse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal width = Float_to(qreal, sfp[3]);
		qreal height = Float_to(qreal, sfp[4]);
		qp->addEllipse(x, y, width, height);
	}
	RETURNvoid_();
}
*/
/*
//void QPainterPath.addEllipse(QPointF center, float rx, float ry);
KMETHOD QPainterPath_addEllipse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QPointF  center = *RawPtr_to(const QPointF *, sfp[1]);
		qreal rx = Float_to(qreal, sfp[2]);
		qreal ry = Float_to(qreal, sfp[3]);
		qp->addEllipse(center, rx, ry);
	}
	RETURNvoid_();
}
*/
//void QPainterPath.addPath(QPainterPath path);
KMETHOD QPainterPath_addPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		qp->addPath(path);
	}
	RETURNvoid_();
}

//void QPainterPath.addPolygon(QPolygonF polygon);
KMETHOD QPainterPath_addPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QPolygonF  polygon = *RawPtr_to(const QPolygonF *, sfp[1]);
		qp->addPolygon(polygon);
	}
	RETURNvoid_();
}

//void QPainterPath.addRect(QRectF rectangle);
KMETHOD QPainterPath_addRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		qp->addRect(rectangle);
	}
	RETURNvoid_();
}

/*
//void QPainterPath.addRect(float x, float y, float width, float height);
KMETHOD QPainterPath_addRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal width = Float_to(qreal, sfp[3]);
		qreal height = Float_to(qreal, sfp[4]);
		qp->addRect(x, y, width, height);
	}
	RETURNvoid_();
}
*/
//void QPainterPath.addRegion(QRegion region);
KMETHOD QPainterPath_addRegion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QRegion  region = *RawPtr_to(const QRegion *, sfp[1]);
		qp->addRegion(region);
	}
	RETURNvoid_();
}

//void QPainterPath.addRoundedRect(QRectF rect, float xRadius, float yRadius, int mode);
KMETHOD QPainterPath_addRoundedRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		qreal xRadius = Float_to(qreal, sfp[2]);
		qreal yRadius = Float_to(qreal, sfp[3]);
		Qt::SizeMode mode = Int_to(Qt::SizeMode, sfp[4]);
		qp->addRoundedRect(rect, xRadius, yRadius, mode);
	}
	RETURNvoid_();
}

/*
//void QPainterPath.addRoundedRect(float x, float y, float w, float h, float xRadius, float yRadius, int mode);
KMETHOD QPainterPath_addRoundedRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		qreal xRadius = Float_to(qreal, sfp[5]);
		qreal yRadius = Float_to(qreal, sfp[6]);
		Qt::SizeMode mode = Int_to(Qt::SizeMode, sfp[7]);
		qp->addRoundedRect(x, y, w, h, xRadius, yRadius, mode);
	}
	RETURNvoid_();
}
*/
//void QPainterPath.addText(QPointF point, QFont font, String text);
KMETHOD QPainterPath_addText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		const QFont  font = *RawPtr_to(const QFont *, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		qp->addText(point, font, text);
	}
	RETURNvoid_();
}

/*
//void QPainterPath.addText(float x, float y, QFont font, String text);
KMETHOD QPainterPath_addText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		const QFont  font = *RawPtr_to(const QFont *, sfp[3]);
		const QString text = String_to(const QString, sfp[4]);
		qp->addText(x, y, font, text);
	}
	RETURNvoid_();
}
*/
//float QPainterPath.angleAtPercent(float t);
KMETHOD QPainterPath_angleAtPercent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qreal t = Float_to(qreal, sfp[1]);
		qreal ret_v = qp->angleAtPercent(t);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QPainterPath.arcMoveTo(QRectF rectangle, float angle);
KMETHOD QPainterPath_arcMoveTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		qreal angle = Float_to(qreal, sfp[2]);
		qp->arcMoveTo(rectangle, angle);
	}
	RETURNvoid_();
}

/*
//void QPainterPath.arcMoveTo(float x, float y, float width, float height, float angle);
KMETHOD QPainterPath_arcMoveTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal width = Float_to(qreal, sfp[3]);
		qreal height = Float_to(qreal, sfp[4]);
		qreal angle = Float_to(qreal, sfp[5]);
		qp->arcMoveTo(x, y, width, height, angle);
	}
	RETURNvoid_();
}
*/
//void QPainterPath.arcTo(QRectF rectangle, float startAngle, float sweepLength);
KMETHOD QPainterPath_arcTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		qreal startAngle = Float_to(qreal, sfp[2]);
		qreal sweepLength = Float_to(qreal, sfp[3]);
		qp->arcTo(rectangle, startAngle, sweepLength);
	}
	RETURNvoid_();
}

/*
//void QPainterPath.arcTo(float x, float y, float width, float height, float startAngle, float sweepLength);
KMETHOD QPainterPath_arcTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal width = Float_to(qreal, sfp[3]);
		qreal height = Float_to(qreal, sfp[4]);
		qreal startAngle = Float_to(qreal, sfp[5]);
		qreal sweepLength = Float_to(qreal, sfp[6]);
		qp->arcTo(x, y, width, height, startAngle, sweepLength);
	}
	RETURNvoid_();
}
*/
//QRectF QPainterPath.boundingRect();
KMETHOD QPainterPath_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->boundingRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QPainterPath.closeSubpath();
KMETHOD QPainterPath_closeSubpath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qp->closeSubpath();
	}
	RETURNvoid_();
}

//void QPainterPath.connectPath(QPainterPath path);
KMETHOD QPainterPath_connectPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		qp->connectPath(path);
	}
	RETURNvoid_();
}

//boolean QPainterPath.contains(QPointF point);
KMETHOD QPainterPath_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		bool ret_v = qp->contains(point);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QPainterPath.contains(QRectF rectangle);
KMETHOD QPainterPath_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		bool ret_v = qp->contains(rectangle);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//boolean QPainterPath.contains(QPainterPath p);
KMETHOD QPainterPath_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QPainterPath  p = *RawPtr_to(const QPainterPath *, sfp[1]);
		bool ret_v = qp->contains(p);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//QRectF QPainterPath.controlPointRect();
KMETHOD QPainterPath_controlPointRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->controlPointRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QPainterPath.cubicTo(QPointF c1, QPointF c2, QPointF endPoint);
KMETHOD QPainterPath_cubicTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QPointF  c1 = *RawPtr_to(const QPointF *, sfp[1]);
		const QPointF  c2 = *RawPtr_to(const QPointF *, sfp[2]);
		const QPointF  endPoint = *RawPtr_to(const QPointF *, sfp[3]);
		qp->cubicTo(c1, c2, endPoint);
	}
	RETURNvoid_();
}

/*
//void QPainterPath.cubicTo(float c1X, float c1Y, float c2X, float c2Y, float endPointX, float endPointY);
KMETHOD QPainterPath_cubicTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qreal c1X = Float_to(qreal, sfp[1]);
		qreal c1Y = Float_to(qreal, sfp[2]);
		qreal c2X = Float_to(qreal, sfp[3]);
		qreal c2Y = Float_to(qreal, sfp[4]);
		qreal endPointX = Float_to(qreal, sfp[5]);
		qreal endPointY = Float_to(qreal, sfp[6]);
		qp->cubicTo(c1X, c1Y, c2X, c2Y, endPointX, endPointY);
	}
	RETURNvoid_();
}
*/
//QPointF QPainterPath.currentPosition();
KMETHOD QPainterPath_currentPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->currentPosition();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QPainterPath.elementCount();
KMETHOD QPainterPath_elementCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		int ret_v = qp->elementCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPainterPath.getFillRule();
KMETHOD QPainterPath_getFillRule(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		Qt::FillRule ret_v = qp->fillRule();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPainterPath QPainterPath.intersected(QPainterPath p);
KMETHOD QPainterPath_intersected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QPainterPath  p = *RawPtr_to(const QPainterPath *, sfp[1]);
		QPainterPath ret_v = qp->intersected(p);
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QPainterPath.intersects(QRectF rectangle);
KMETHOD QPainterPath_intersects(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		bool ret_v = qp->intersects(rectangle);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QPainterPath.intersects(QPainterPath p);
KMETHOD QPainterPath_intersects(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QPainterPath  p = *RawPtr_to(const QPainterPath *, sfp[1]);
		bool ret_v = qp->intersects(p);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//boolean QPainterPath.isEmpty();
KMETHOD QPainterPath_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//float QPainterPath.length();
KMETHOD QPainterPath_length(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->length();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QPainterPath.lineTo(QPointF endPoint);
KMETHOD QPainterPath_lineTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QPointF  endPoint = *RawPtr_to(const QPointF *, sfp[1]);
		qp->lineTo(endPoint);
	}
	RETURNvoid_();
}

/*
//void QPainterPath.lineTo(float x, float y);
KMETHOD QPainterPath_lineTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qp->lineTo(x, y);
	}
	RETURNvoid_();
}
*/
//void QPainterPath.moveTo(QPointF point);
KMETHOD QPainterPath_moveTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		qp->moveTo(point);
	}
	RETURNvoid_();
}

/*
//void QPainterPath.moveTo(float x, float y);
KMETHOD QPainterPath_moveTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qp->moveTo(x, y);
	}
	RETURNvoid_();
}
*/
//float QPainterPath.percentAtLength(float len);
KMETHOD QPainterPath_percentAtLength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qreal len = Float_to(qreal, sfp[1]);
		qreal ret_v = qp->percentAtLength(len);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QPointF QPainterPath.pointAtPercent(float t);
KMETHOD QPainterPath_pointAtPercent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qreal t = Float_to(qreal, sfp[1]);
		QPointF ret_v = qp->pointAtPercent(t);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QPainterPath.quadTo(QPointF c, QPointF endPoint);
KMETHOD QPainterPath_quadTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QPointF  c = *RawPtr_to(const QPointF *, sfp[1]);
		const QPointF  endPoint = *RawPtr_to(const QPointF *, sfp[2]);
		qp->quadTo(c, endPoint);
	}
	RETURNvoid_();
}

/*
//void QPainterPath.quadTo(float cx, float cy, float endPointX, float endPointY);
KMETHOD QPainterPath_quadTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qreal cx = Float_to(qreal, sfp[1]);
		qreal cy = Float_to(qreal, sfp[2]);
		qreal endPointX = Float_to(qreal, sfp[3]);
		qreal endPointY = Float_to(qreal, sfp[4]);
		qp->quadTo(cx, cy, endPointX, endPointY);
	}
	RETURNvoid_();
}
*/
//void QPainterPath.setElementPositionAt(int index, float x, float y);
KMETHOD QPainterPath_setElementPositionAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		qreal x = Float_to(qreal, sfp[2]);
		qreal y = Float_to(qreal, sfp[3]);
		qp->setElementPositionAt(index, x, y);
	}
	RETURNvoid_();
}

//void QPainterPath.setFillRule(int fillRule);
KMETHOD QPainterPath_setFillRule(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		Qt::FillRule fillRule = Int_to(Qt::FillRule, sfp[1]);
		qp->setFillRule(fillRule);
	}
	RETURNvoid_();
}

//QPainterPath QPainterPath.simplified();
KMETHOD QPainterPath_simplified(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		QPainterPath ret_v = qp->simplified();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QPainterPath.slopeAtPercent(float t);
KMETHOD QPainterPath_slopeAtPercent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qreal t = Float_to(qreal, sfp[1]);
		qreal ret_v = qp->slopeAtPercent(t);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QPainterPath QPainterPath.subtracted(QPainterPath p);
KMETHOD QPainterPath_subtracted(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QPainterPath  p = *RawPtr_to(const QPainterPath *, sfp[1]);
		QPainterPath ret_v = qp->subtracted(p);
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPolygonF QPainterPath.toFillPolygon(QTransform matrix);
KMETHOD QPainterPath_toFillPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QTransform  matrix = *RawPtr_to(const QTransform *, sfp[1]);
		QPolygonF ret_v = qp->toFillPolygon(matrix);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPolygonF QPainterPath.toFillPolygon(QMatrix matrix);
KMETHOD QPainterPath_toFillPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QMatrix  matrix = *RawPtr_to(const QMatrix *, sfp[1]);
		QPolygonF ret_v = qp->toFillPolygon(matrix);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//Array<QPolygonF> QPainterPath.toFillPolygons(QTransform matrix);
KMETHOD QPainterPath_toFillPolygons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QTransform  matrix = *RawPtr_to(const QTransform *, sfp[1]);
		QList<QPolygonF> ret_v = qp->toFillPolygons(matrix);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QPolygonF"));
		for (int n = 0; n < list_size; n++) {
			QPolygonF *ret_v_ = new QPolygonF(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

/*
//Array<QPolygonF> QPainterPath.toFillPolygons(QMatrix matrix);
KMETHOD QPainterPath_toFillPolygons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QMatrix  matrix = *RawPtr_to(const QMatrix *, sfp[1]);
		QList<QPolygonF> ret_v = qp->toFillPolygons(matrix);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QPolygonF"));
		for (int n = 0; n < list_size; n++) {
			QPolygonF *ret_v_ = new QPolygonF(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	
*/
//QPainterPath QPainterPath.toReversed();
KMETHOD QPainterPath_toReversed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		QPainterPath ret_v = qp->toReversed();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QPolygonF> QPainterPath.toSubpathPolygons(QTransform matrix);
KMETHOD QPainterPath_toSubpathPolygons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QTransform  matrix = *RawPtr_to(const QTransform *, sfp[1]);
		QList<QPolygonF> ret_v = qp->toSubpathPolygons(matrix);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QPolygonF"));
		for (int n = 0; n < list_size; n++) {
			QPolygonF *ret_v_ = new QPolygonF(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

/*
//Array<QPolygonF> QPainterPath.toSubpathPolygons(QMatrix matrix);
KMETHOD QPainterPath_toSubpathPolygons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QMatrix  matrix = *RawPtr_to(const QMatrix *, sfp[1]);
		QList<QPolygonF> ret_v = qp->toSubpathPolygons(matrix);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QPolygonF"));
		for (int n = 0; n < list_size; n++) {
			QPolygonF *ret_v_ = new QPolygonF(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	
*/
//void QPainterPath.translate(float dx, float dy);
KMETHOD QPainterPath_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qreal dx = Float_to(qreal, sfp[1]);
		qreal dy = Float_to(qreal, sfp[2]);
		qp->translate(dx, dy);
	}
	RETURNvoid_();
}

/*
//void QPainterPath.translate(QPointF offset);
KMETHOD QPainterPath_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QPointF  offset = *RawPtr_to(const QPointF *, sfp[1]);
		qp->translate(offset);
	}
	RETURNvoid_();
}
*/
//QPainterPath QPainterPath.translated(float dx, float dy);
KMETHOD QPainterPath_translated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		qreal dx = Float_to(qreal, sfp[1]);
		qreal dy = Float_to(qreal, sfp[2]);
		QPainterPath ret_v = qp->translated(dx, dy);
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPainterPath QPainterPath.translated(QPointF offset);
KMETHOD QPainterPath_translated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QPointF  offset = *RawPtr_to(const QPointF *, sfp[1]);
		QPainterPath ret_v = qp->translated(offset);
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QPainterPath QPainterPath.united(QPainterPath p);
KMETHOD QPainterPath_united(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *  qp = RawPtr_to(QPainterPath *, sfp[0]);
	if (qp) {
		const QPainterPath  p = *RawPtr_to(const QPainterPath *, sfp[1]);
		QPainterPath ret_v = qp->united(p);
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QPainterPath.parents();
KMETHOD QPainterPath_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPainterPath *qp = RawPtr_to(QPainterPath*, sfp[0]);
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

DummyQPainterPath::DummyQPainterPath()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPainterPath::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPainterPath::self = ptr;
}

bool DummyQPainterPath::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQPainterPath::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPainterPath::event_map->bigin();
	if ((itr = DummyQPainterPath::event_map->find(str)) == DummyQPainterPath::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPainterPath::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPainterPath::slot_map->bigin();
	if ((itr = DummyQPainterPath::slot_map->find(str)) == DummyQPainterPath::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQPainterPath::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQPainterPath::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQPainterPath::connection(QObject *o)
{
	QPainterPath *p = dynamic_cast<QPainterPath*>(o);
	if (p != NULL) {
	}
}

KQPainterPath::KQPainterPath() : QPainterPath()
{
	self = NULL;
	dummy = new DummyQPainterPath();
}

KMETHOD QPainterPath_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPainterPath *qp = RawPtr_to(KQPainterPath *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPainterPath]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPainterPath]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPainterPath_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPainterPath *qp = RawPtr_to(KQPainterPath *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPainterPath]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPainterPath]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPainterPath_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPainterPath *qp = (KQPainterPath *)p->rawptr;
		delete qp;
	}
}
static void QPainterPath_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQPainterPath *qp = (KQPainterPath *)p->rawptr;
//		KQPainterPath *qp = static_cast<KQPainterPath*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPainterPath_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QPainterPath*>(p1->rawptr) == *static_cast<QPainterPath*>(p2->rawptr) ? 0 : 1);
}

void KQPainterPath::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QPainterPathConstInt[] = {
	{"MoveToElement", QPainterPath::MoveToElement},
	{"LineToElement", QPainterPath::LineToElement},
	{"CurveToElement", QPainterPath::CurveToElement},
	{"CurveToDataElement", QPainterPath::CurveToDataElement},
	{NULL, 0}
};

DEFAPI(void) constQPainterPath(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QPainterPathConstInt);
}


DEFAPI(void) defQPainterPath(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPainterPath";
	cdef->free = QPainterPath_free;
	cdef->reftrace = QPainterPath_reftrace;
	cdef->compareTo = QPainterPath_compareTo;
}


