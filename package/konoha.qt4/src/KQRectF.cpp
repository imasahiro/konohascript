//QRectF QRectF.new();
KMETHOD QRectF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRectF *ret_v = new KQRectF();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QRectF QRectF.new(QPointF topLeft, QSizeF size);
KMETHOD QRectF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPointF  topLeft = *RawPtr_to(const QPointF *, sfp[1]);
	const QSizeF  size = *RawPtr_to(const QSizeF *, sfp[2]);
	KQRectF *ret_v = new KQRectF(topLeft, size);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QRectF QRectF.new(QPointF topLeft, QPointF bottomRight);
KMETHOD QRectF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPointF  topLeft = *RawPtr_to(const QPointF *, sfp[1]);
	const QPointF  bottomRight = *RawPtr_to(const QPointF *, sfp[2]);
	KQRectF *ret_v = new KQRectF(topLeft, bottomRight);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QRectF QRectF.new(float x, float y, float width, float height);
KMETHOD QRectF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	qreal x = Float_to(qreal, sfp[1]);
	qreal y = Float_to(qreal, sfp[2]);
	qreal width = Float_to(qreal, sfp[3]);
	qreal height = Float_to(qreal, sfp[4]);
	KQRectF *ret_v = new KQRectF(x, y, width, height);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QRectF QRectF.new(QRect rectangle);
KMETHOD QRectF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
	KQRectF *ret_v = new KQRectF(rectangle);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QRectF.adjust(float dx1, float dy1, float dx2, float dy2);
KMETHOD QRectF_adjust(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal dx1 = Float_to(qreal, sfp[1]);
		qreal dy1 = Float_to(qreal, sfp[2]);
		qreal dx2 = Float_to(qreal, sfp[3]);
		qreal dy2 = Float_to(qreal, sfp[4]);
		qp->adjust(dx1, dy1, dx2, dy2);
	}
	RETURNvoid_();
}

//QRectF QRectF.adjusted(float dx1, float dy1, float dx2, float dy2);
KMETHOD QRectF_adjusted(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal dx1 = Float_to(qreal, sfp[1]);
		qreal dy1 = Float_to(qreal, sfp[2]);
		qreal dx2 = Float_to(qreal, sfp[3]);
		qreal dy2 = Float_to(qreal, sfp[4]);
		QRectF ret_v = qp->adjusted(dx1, dy1, dx2, dy2);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QRectF.getBottom();
KMETHOD QRectF_getBottom(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->bottom();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QPointF QRectF.getBottomLeft();
KMETHOD QRectF_getBottomLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->bottomLeft();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QRectF.getBottomRight();
KMETHOD QRectF_getBottomRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->bottomRight();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QRectF.center();
KMETHOD QRectF_center(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->center();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QRectF.contains(QPointF point);
KMETHOD QRectF_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		bool ret_v = qp->contains(point);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QRectF.contains(float x, float y);
KMETHOD QRectF_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		bool ret_v = qp->contains(x, y);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//boolean QRectF.contains(QRectF rectangle);
KMETHOD QRectF_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		bool ret_v = qp->contains(rectangle);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//void QRectF.getCoords(float x1, float y1, float x2, float y2);
KMETHOD QRectF_getCoords(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal*  x1 = RawPtr_to(qreal*, sfp[1]);
		qreal*  y1 = RawPtr_to(qreal*, sfp[2]);
		qreal*  x2 = RawPtr_to(qreal*, sfp[3]);
		qreal*  y2 = RawPtr_to(qreal*, sfp[4]);
		qp->getCoords(x1, y1, x2, y2);
	}
	RETURNvoid_();
}

//void QRectF.getRect(float x, float y, float width, float height);
KMETHOD QRectF_getRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal*  x = RawPtr_to(qreal*, sfp[1]);
		qreal*  y = RawPtr_to(qreal*, sfp[2]);
		qreal*  width = RawPtr_to(qreal*, sfp[3]);
		qreal*  height = RawPtr_to(qreal*, sfp[4]);
		qp->getRect(x, y, width, height);
	}
	RETURNvoid_();
}

//float QRectF.getHeight();
KMETHOD QRectF_getHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->height();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QRectF QRectF.intersected(QRectF rectangle);
KMETHOD QRectF_intersected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		QRectF ret_v = qp->intersected(rectangle);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QRectF.intersects(QRectF rectangle);
KMETHOD QRectF_intersects(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		bool ret_v = qp->intersects(rectangle);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QRectF.isEmpty();
KMETHOD QRectF_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//float QRectF.getLeft();
KMETHOD QRectF_getLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->left();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QRectF.moveBottom(float y);
KMETHOD QRectF_moveBottom(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal y = Float_to(qreal, sfp[1]);
		qp->moveBottom(y);
	}
	RETURNvoid_();
}

//void QRectF.moveBottomLeft(QPointF position);
KMETHOD QRectF_moveBottomLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[1]);
		qp->moveBottomLeft(position);
	}
	RETURNvoid_();
}

//void QRectF.moveBottomRight(QPointF position);
KMETHOD QRectF_moveBottomRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[1]);
		qp->moveBottomRight(position);
	}
	RETURNvoid_();
}

//void QRectF.moveCenter(QPointF position);
KMETHOD QRectF_moveCenter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[1]);
		qp->moveCenter(position);
	}
	RETURNvoid_();
}

//void QRectF.moveLeft(float x);
KMETHOD QRectF_moveLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qp->moveLeft(x);
	}
	RETURNvoid_();
}

//void QRectF.moveRight(float x);
KMETHOD QRectF_moveRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qp->moveRight(x);
	}
	RETURNvoid_();
}

//void QRectF.moveTo(float x, float y);
KMETHOD QRectF_moveTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qp->moveTo(x, y);
	}
	RETURNvoid_();
}

/*
//void QRectF.moveTo(QPointF position);
KMETHOD QRectF_moveTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[1]);
		qp->moveTo(position);
	}
	RETURNvoid_();
}
*/
//void QRectF.moveTop(float y);
KMETHOD QRectF_moveTop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal y = Float_to(qreal, sfp[1]);
		qp->moveTop(y);
	}
	RETURNvoid_();
}

//void QRectF.moveTopLeft(QPointF position);
KMETHOD QRectF_moveTopLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[1]);
		qp->moveTopLeft(position);
	}
	RETURNvoid_();
}

//void QRectF.moveTopRight(QPointF position);
KMETHOD QRectF_moveTopRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[1]);
		qp->moveTopRight(position);
	}
	RETURNvoid_();
}

//QRectF QRectF.normalized();
KMETHOD QRectF_normalized(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->normalized();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QRectF.getRight();
KMETHOD QRectF_getRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->right();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QRectF.setBottom(float y);
KMETHOD QRectF_setBottom(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal y = Float_to(qreal, sfp[1]);
		qp->setBottom(y);
	}
	RETURNvoid_();
}

//void QRectF.setBottomLeft(QPointF position);
KMETHOD QRectF_setBottomLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setBottomLeft(position);
	}
	RETURNvoid_();
}

//void QRectF.setBottomRight(QPointF position);
KMETHOD QRectF_setBottomRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setBottomRight(position);
	}
	RETURNvoid_();
}

//void QRectF.setCoords(float x1, float y1, float x2, float y2);
KMETHOD QRectF_setCoords(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal x1 = Float_to(qreal, sfp[1]);
		qreal y1 = Float_to(qreal, sfp[2]);
		qreal x2 = Float_to(qreal, sfp[3]);
		qreal y2 = Float_to(qreal, sfp[4]);
		qp->setCoords(x1, y1, x2, y2);
	}
	RETURNvoid_();
}

//void QRectF.setHeight(float height);
KMETHOD QRectF_setHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal height = Float_to(qreal, sfp[1]);
		qp->setHeight(height);
	}
	RETURNvoid_();
}

//void QRectF.setLeft(float x);
KMETHOD QRectF_setLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qp->setLeft(x);
	}
	RETURNvoid_();
}

//void QRectF.setRect(float x, float y, float width, float height);
KMETHOD QRectF_setRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal width = Float_to(qreal, sfp[3]);
		qreal height = Float_to(qreal, sfp[4]);
		qp->setRect(x, y, width, height);
	}
	RETURNvoid_();
}

//void QRectF.setRight(float x);
KMETHOD QRectF_setRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qp->setRight(x);
	}
	RETURNvoid_();
}

//void QRectF.setSize(QSizeF size);
KMETHOD QRectF_setSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QSizeF  size = *RawPtr_to(const QSizeF *, sfp[1]);
		qp->setSize(size);
	}
	RETURNvoid_();
}

//void QRectF.setTop(float y);
KMETHOD QRectF_setTop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal y = Float_to(qreal, sfp[1]);
		qp->setTop(y);
	}
	RETURNvoid_();
}

//void QRectF.setTopLeft(QPointF position);
KMETHOD QRectF_setTopLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setTopLeft(position);
	}
	RETURNvoid_();
}

//void QRectF.setTopRight(QPointF position);
KMETHOD QRectF_setTopRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setTopRight(position);
	}
	RETURNvoid_();
}

//void QRectF.setWidth(float width);
KMETHOD QRectF_setWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal width = Float_to(qreal, sfp[1]);
		qp->setWidth(width);
	}
	RETURNvoid_();
}

//void QRectF.setX(float x);
KMETHOD QRectF_setX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qp->setX(x);
	}
	RETURNvoid_();
}

//void QRectF.setY(float y);
KMETHOD QRectF_setY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal y = Float_to(qreal, sfp[1]);
		qp->setY(y);
	}
	RETURNvoid_();
}

//QSizeF QRectF.getSize();
KMETHOD QRectF_getSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		QSizeF ret_v = qp->size();
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QRectF.toAlignedRect();
KMETHOD QRectF_toAlignedRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->toAlignedRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QRectF.toRect();
KMETHOD QRectF_toRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->toRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QRectF.getTop();
KMETHOD QRectF_getTop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->top();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QPointF QRectF.getTopLeft();
KMETHOD QRectF_getTopLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->topLeft();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QRectF.getTopRight();
KMETHOD QRectF_getTopRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->topRight();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QRectF.translate(float dx, float dy);
KMETHOD QRectF_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal dx = Float_to(qreal, sfp[1]);
		qreal dy = Float_to(qreal, sfp[2]);
		qp->translate(dx, dy);
	}
	RETURNvoid_();
}

/*
//void QRectF.translate(QPointF offset);
KMETHOD QRectF_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QPointF  offset = *RawPtr_to(const QPointF *, sfp[1]);
		qp->translate(offset);
	}
	RETURNvoid_();
}
*/
//QRectF QRectF.translated(float dx, float dy);
KMETHOD QRectF_translated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal dx = Float_to(qreal, sfp[1]);
		qreal dy = Float_to(qreal, sfp[2]);
		QRectF ret_v = qp->translated(dx, dy);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRectF QRectF.translated(QPointF offset);
KMETHOD QRectF_translated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QPointF  offset = *RawPtr_to(const QPointF *, sfp[1]);
		QRectF ret_v = qp->translated(offset);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QRectF QRectF.united(QRectF rectangle);
KMETHOD QRectF_united(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		QRectF ret_v = qp->united(rectangle);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QRectF.getWidth();
KMETHOD QRectF_getWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->width();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QRectF.getX();
KMETHOD QRectF_getX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->x();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QRectF.getY();
KMETHOD QRectF_getY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *  qp = RawPtr_to(QRectF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->y();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//Array<String> QRectF.parents();
KMETHOD QRectF_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRectF *qp = RawPtr_to(QRectF*, sfp[0]);
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

DummyQRectF::DummyQRectF()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQRectF::~DummyQRectF()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQRectF::setSelf(knh_RawPtr_t *ptr)
{
	DummyQRectF::self = ptr;
}

bool DummyQRectF::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQRectF::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRectF::event_map->bigin();
	if ((itr = DummyQRectF::event_map->find(str)) == DummyQRectF::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQRectF::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRectF::slot_map->bigin();
	if ((itr = DummyQRectF::slot_map->find(str)) == DummyQRectF::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQRectF::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQRectF::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQRectF::connection(QObject *o)
{
	QRectF *p = dynamic_cast<QRectF*>(o);
	if (p != NULL) {
	}
}

KQRectF::KQRectF() : QRectF()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQRectF();
}

KQRectF::~KQRectF()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QRectF_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRectF *qp = RawPtr_to(KQRectF *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QRectF]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRectF]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QRectF_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRectF *qp = RawPtr_to(KQRectF *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QRectF]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRectF]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QRectF_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQRectF *qp = (KQRectF *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QRectF*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QRectF_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQRectF *qp = (KQRectF *)p->rawptr;
		KQRectF *qp = static_cast<KQRectF*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QRectF_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QRectF*>(p1->rawptr) == *static_cast<QRectF*>(p2->rawptr) ? 0 : 1);
}

void KQRectF::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQRectF(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QRectF";
	cdef->free = QRectF_free;
	cdef->reftrace = QRectF_reftrace;
	cdef->compareTo = QRectF_compareTo;
}


