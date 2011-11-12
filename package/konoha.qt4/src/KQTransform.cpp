//QTransform QTransform.new();
KMETHOD QTransform_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTransform *ret_v = new KQTransform();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTransform QTransform.new(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33);
KMETHOD QTransform_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	qreal m11 = Float_to(qreal, sfp[1]);
	qreal m12 = Float_to(qreal, sfp[2]);
	qreal m13 = Float_to(qreal, sfp[3]);
	qreal m21 = Float_to(qreal, sfp[4]);
	qreal m22 = Float_to(qreal, sfp[5]);
	qreal m23 = Float_to(qreal, sfp[6]);
	qreal m31 = Float_to(qreal, sfp[7]);
	qreal m32 = Float_to(qreal, sfp[8]);
	qreal m33 = Float_to(qreal, sfp[9]);
	KQTransform *ret_v = new KQTransform(m11, m12, m13, m21, m22, m23, m31, m32, m33);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QTransform QTransform.new(float m11, float m12, float m21, float m22, float dx, float dy);
KMETHOD QTransform_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	qreal m11 = Float_to(qreal, sfp[1]);
	qreal m12 = Float_to(qreal, sfp[2]);
	qreal m21 = Float_to(qreal, sfp[3]);
	qreal m22 = Float_to(qreal, sfp[4]);
	qreal dx = Float_to(qreal, sfp[5]);
	qreal dy = Float_to(qreal, sfp[6]);
	KQTransform *ret_v = new KQTransform(m11, m12, m21, m22, dx, dy);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QTransform QTransform.new(QMatrix matrix);
KMETHOD QTransform_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QMatrix  matrix = *RawPtr_to(const QMatrix *, sfp[1]);
	KQTransform *ret_v = new KQTransform(matrix);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//float QTransform.m11();
KMETHOD QTransform_m11(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->m11();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTransform.m12();
KMETHOD QTransform_m12(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->m12();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTransform.m13();
KMETHOD QTransform_m13(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->m13();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTransform.m21();
KMETHOD QTransform_m21(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->m21();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTransform.m22();
KMETHOD QTransform_m22(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->m22();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTransform.m23();
KMETHOD QTransform_m23(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->m23();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTransform.m31();
KMETHOD QTransform_m31(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->m31();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTransform.m32();
KMETHOD QTransform_m32(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->m32();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTransform.m33();
KMETHOD QTransform_m33(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->m33();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QTransform QTransform.adjoint();
KMETHOD QTransform_adjoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		QTransform ret_v = qp->adjoint();
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QTransform.determinant();
KMETHOD QTransform_determinant(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->determinant();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTransform.dx();
KMETHOD QTransform_dx(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->dx();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTransform.dy();
KMETHOD QTransform_dy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->dy();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QTransform QTransform.inverted(boolean invertible);
KMETHOD QTransform_inverted(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		bool* invertible = Boolean_to(bool*, sfp[1]);
		QTransform ret_v = qp->inverted(invertible);
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QTransform.isAffine();
KMETHOD QTransform_isAffine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isAffine();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTransform.isIdentity();
KMETHOD QTransform_isIdentity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isIdentity();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTransform.isInvertible();
KMETHOD QTransform_isInvertible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isInvertible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTransform.isRotating();
KMETHOD QTransform_isRotating(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isRotating();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTransform.isScaling();
KMETHOD QTransform_isScaling(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isScaling();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTransform.isTranslating();
KMETHOD QTransform_isTranslating(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isTranslating();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTransform.map(float x, float y, float tx, float ty);
KMETHOD QTransform_map(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal*  tx = RawPtr_to(qreal*, sfp[3]);
		qreal*  ty = RawPtr_to(qreal*, sfp[4]);
		qp->map(x, y, tx, ty);
	}
	RETURNvoid_();
}

/*
//QPointF QTransform.map(QPointF p);
KMETHOD QTransform_map(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		const QPointF  p = *RawPtr_to(const QPointF *, sfp[1]);
		QPointF ret_v = qp->map(p);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPoint QTransform.map(QPoint point);
KMETHOD QTransform_map(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		QPoint ret_v = qp->map(point);
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QLine QTransform.map(QLine l);
KMETHOD QTransform_map(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		const QLine  l = *RawPtr_to(const QLine *, sfp[1]);
		QLine ret_v = qp->map(l);
		QLine *ret_v_ = new QLine(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QLineF QTransform.map(QLineF line);
KMETHOD QTransform_map(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		const QLineF  line = *RawPtr_to(const QLineF *, sfp[1]);
		QLineF ret_v = qp->map(line);
		QLineF *ret_v_ = new QLineF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPolygonF QTransform.map(QPolygonF polygon);
KMETHOD QTransform_map(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		const QPolygonF  polygon = *RawPtr_to(const QPolygonF *, sfp[1]);
		QPolygonF ret_v = qp->map(polygon);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPolygon QTransform.map(QPolygon polygon);
KMETHOD QTransform_map(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		const QPolygon  polygon = *RawPtr_to(const QPolygon *, sfp[1]);
		QPolygon ret_v = qp->map(polygon);
		QPolygon *ret_v_ = new QPolygon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QRegion QTransform.map(QRegion region);
KMETHOD QTransform_map(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		const QRegion  region = *RawPtr_to(const QRegion *, sfp[1]);
		QRegion ret_v = qp->map(region);
		QRegion *ret_v_ = new QRegion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPainterPath QTransform.map(QPainterPath path);
KMETHOD QTransform_map(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		QPainterPath ret_v = qp->map(path);
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//void QTransform.map(int x, int y, int tx, int ty);
KMETHOD QTransform_map(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int* tx = Int_to(int*, sfp[3]);
		int* ty = Int_to(int*, sfp[4]);
		qp->map(x, y, tx, ty);
	}
	RETURNvoid_();
}
*/
//QRectF QTransform.mapRect(QRectF rectangle);
KMETHOD QTransform_mapRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		QRectF ret_v = qp->mapRect(rectangle);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRect QTransform.mapRect(QRect rectangle);
KMETHOD QTransform_mapRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		QRect ret_v = qp->mapRect(rectangle);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QPolygon QTransform.mapToPolygon(QRect rectangle);
KMETHOD QTransform_mapToPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		QPolygon ret_v = qp->mapToPolygon(rectangle);
		QPolygon *ret_v_ = new QPolygon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTransform.reset();
KMETHOD QTransform_reset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qp->reset();
	}
	RETURNvoid_();
}

//QTransform QTransform.rotate(float angle, int axis);
KMETHOD QTransform_rotate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal angle = Float_to(qreal, sfp[1]);
		Qt::Axis axis = Int_to(Qt::Axis, sfp[2]);
		QTransform ret_v = qp->rotate(angle, axis);
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTransform QTransform.rotateRadians(float angle, int axis);
KMETHOD QTransform_rotateRadians(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal angle = Float_to(qreal, sfp[1]);
		Qt::Axis axis = Int_to(Qt::Axis, sfp[2]);
		QTransform ret_v = qp->rotateRadians(angle, axis);
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTransform QTransform.scale(float sx, float sy);
KMETHOD QTransform_scale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal sx = Float_to(qreal, sfp[1]);
		qreal sy = Float_to(qreal, sfp[2]);
		QTransform ret_v = qp->scale(sx, sy);
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTransform.setMatrix(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33);
KMETHOD QTransform_setMatrix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal m11 = Float_to(qreal, sfp[1]);
		qreal m12 = Float_to(qreal, sfp[2]);
		qreal m13 = Float_to(qreal, sfp[3]);
		qreal m21 = Float_to(qreal, sfp[4]);
		qreal m22 = Float_to(qreal, sfp[5]);
		qreal m23 = Float_to(qreal, sfp[6]);
		qreal m31 = Float_to(qreal, sfp[7]);
		qreal m32 = Float_to(qreal, sfp[8]);
		qreal m33 = Float_to(qreal, sfp[9]);
		qp->setMatrix(m11, m12, m13, m21, m22, m23, m31, m32, m33);
	}
	RETURNvoid_();
}

//QTransform QTransform.shear(float sh, float sv);
KMETHOD QTransform_shear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal sh = Float_to(qreal, sfp[1]);
		qreal sv = Float_to(qreal, sfp[2]);
		QTransform ret_v = qp->shear(sh, sv);
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QMatrix QTransform.toAffine();
KMETHOD QTransform_toAffine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		const QMatrix ret_v = qp->toAffine();
		QMatrix *ret_v_ = new QMatrix(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTransform QTransform.translate(float dx, float dy);
KMETHOD QTransform_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		qreal dx = Float_to(qreal, sfp[1]);
		qreal dy = Float_to(qreal, sfp[2]);
		QTransform ret_v = qp->translate(dx, dy);
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTransform QTransform.transposed();
KMETHOD QTransform_transposed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		QTransform ret_v = qp->transposed();
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTransform.type();
KMETHOD QTransform_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *  qp = RawPtr_to(QTransform *, sfp[0]);
	if (qp) {
		QTransform::TransformationType ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTransform QTransform.fromScale(float sx, float sy);
KMETHOD QTransform_fromScale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		qreal sx = Float_to(qreal, sfp[1]);
		qreal sy = Float_to(qreal, sfp[2]);
		QTransform ret_v = QTransform::fromScale(sx, sy);
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTransform QTransform.fromTranslate(float dx, float dy);
KMETHOD QTransform_fromTranslate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		qreal dx = Float_to(qreal, sfp[1]);
		qreal dy = Float_to(qreal, sfp[2]);
		QTransform ret_v = QTransform::fromTranslate(dx, dy);
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QTransform.quadToQuad(QPolygonF one, QPolygonF two, QTransform trans);
KMETHOD QTransform_quadToQuad(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QPolygonF  one = *RawPtr_to(const QPolygonF *, sfp[1]);
		const QPolygonF  two = *RawPtr_to(const QPolygonF *, sfp[2]);
		QTransform  trans = *RawPtr_to(QTransform *, sfp[3]);
		bool ret_v = QTransform::quadToQuad(one, two, trans);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTransform.quadToSquare(QPolygonF quad, QTransform trans);
KMETHOD QTransform_quadToSquare(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QPolygonF  quad = *RawPtr_to(const QPolygonF *, sfp[1]);
		QTransform  trans = *RawPtr_to(QTransform *, sfp[2]);
		bool ret_v = QTransform::quadToSquare(quad, trans);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTransform.squareToQuad(QPolygonF quad, QTransform trans);
KMETHOD QTransform_squareToQuad(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QPolygonF  quad = *RawPtr_to(const QPolygonF *, sfp[1]);
		QTransform  trans = *RawPtr_to(QTransform *, sfp[2]);
		bool ret_v = QTransform::squareToQuad(quad, trans);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//Array<String> QTransform.parents();
KMETHOD QTransform_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTransform *qp = RawPtr_to(QTransform*, sfp[0]);
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

DummyQTransform::DummyQTransform()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTransform::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTransform::self = ptr;
}

bool DummyQTransform::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTransform::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTransform::event_map->bigin();
	if ((itr = DummyQTransform::event_map->find(str)) == DummyQTransform::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTransform::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTransform::slot_map->bigin();
	if ((itr = DummyQTransform::slot_map->find(str)) == DummyQTransform::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTransform::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTransform::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQTransform::connection(QObject *o)
{
	QTransform *p = dynamic_cast<QTransform*>(o);
	if (p != NULL) {
	}
}

KQTransform::KQTransform() : QTransform()
{
	self = NULL;
	dummy = new DummyQTransform();
}

KMETHOD QTransform_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTransform *qp = RawPtr_to(KQTransform *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTransform]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTransform]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTransform_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTransform *qp = RawPtr_to(KQTransform *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTransform]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTransform]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTransform_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTransform *qp = (KQTransform *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTransform_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQTransform *qp = (KQTransform *)p->rawptr;
//		KQTransform *qp = static_cast<KQTransform*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTransform_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QTransform*>(p1->rawptr) == *static_cast<QTransform*>(p2->rawptr) ? 0 : 1);
}

void KQTransform::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QTransformConstInt[] = {
	{"TxNone", QTransform::TxNone},
	{"TxTranslate", QTransform::TxTranslate},
	{"TxScale", QTransform::TxScale},
	{"TxRotate", QTransform::TxRotate},
	{"TxShear", QTransform::TxShear},
	{"TxProject", QTransform::TxProject},
	{NULL, 0}
};

DEFAPI(void) constQTransform(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTransformConstInt);
}


DEFAPI(void) defQTransform(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTransform";
	cdef->free = QTransform_free;
	cdef->reftrace = QTransform_reftrace;
	cdef->compareTo = QTransform_compareTo;
}


