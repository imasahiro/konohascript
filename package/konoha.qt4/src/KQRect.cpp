//QRect QRect.new();
KMETHOD QRect_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRect *ret_v = new KQRect();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QRect QRect.new(QPoint topLeft, QPoint bottomRight);
KMETHOD QRect_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPoint  topLeft = *RawPtr_to(const QPoint *, sfp[1]);
	const QPoint  bottomRight = *RawPtr_to(const QPoint *, sfp[2]);
	KQRect *ret_v = new KQRect(topLeft, bottomRight);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QRect QRect.new(QPoint topLeft, QSize size);
KMETHOD QRect_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPoint  topLeft = *RawPtr_to(const QPoint *, sfp[1]);
	const QSize  size = *RawPtr_to(const QSize *, sfp[2]);
	KQRect *ret_v = new KQRect(topLeft, size);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QRect QRect.new(int x, int y, int width, int height);
KMETHOD QRect_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int x = Int_to(int, sfp[1]);
	int y = Int_to(int, sfp[2]);
	int width = Int_to(int, sfp[3]);
	int height = Int_to(int, sfp[4]);
	KQRect *ret_v = new KQRect(x, y, width, height);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QRect.adjust(int dx1, int dy1, int dx2, int dy2);
KMETHOD QRect_adjust(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int dx1 = Int_to(int, sfp[1]);
		int dy1 = Int_to(int, sfp[2]);
		int dx2 = Int_to(int, sfp[3]);
		int dy2 = Int_to(int, sfp[4]);
		qp->adjust(dx1, dy1, dx2, dy2);
	}
	RETURNvoid_();
}

//QRect QRect.adjusted(int dx1, int dy1, int dx2, int dy2);
KMETHOD QRect_adjusted(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int dx1 = Int_to(int, sfp[1]);
		int dy1 = Int_to(int, sfp[2]);
		int dx2 = Int_to(int, sfp[3]);
		int dy2 = Int_to(int, sfp[4]);
		QRect ret_v = qp->adjusted(dx1, dy1, dx2, dy2);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QRect.getBottom();
KMETHOD QRect_getBottom(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int ret_v = qp->bottom();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPoint QRect.getBottomLeft();
KMETHOD QRect_getBottomLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		QPoint ret_v = qp->bottomLeft();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QRect.getBottomRight();
KMETHOD QRect_getBottomRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		QPoint ret_v = qp->bottomRight();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QRect.center();
KMETHOD QRect_center(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		QPoint ret_v = qp->center();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QRect.contains(QPoint point, boolean proper);
KMETHOD QRect_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		bool proper = Boolean_to(bool, sfp[2]);
		bool ret_v = qp->contains(point, proper);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QRect.contains(int x, int y, boolean proper);
KMETHOD QRect_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		bool proper = Boolean_to(bool, sfp[3]);
		bool ret_v = qp->contains(x, y, proper);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//boolean QRect.contains(int x, int y);
KMETHOD QRect_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		bool ret_v = qp->contains(x, y);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//boolean QRect.contains(QRect rectangle, boolean proper);
KMETHOD QRect_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		bool proper = Boolean_to(bool, sfp[2]);
		bool ret_v = qp->contains(rectangle, proper);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//void QRect.getCoords(int x1, int y1, int x2, int y2);
KMETHOD QRect_getCoords(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int* x1 = Int_to(int*, sfp[1]);
		int* y1 = Int_to(int*, sfp[2]);
		int* x2 = Int_to(int*, sfp[3]);
		int* y2 = Int_to(int*, sfp[4]);
		qp->getCoords(x1, y1, x2, y2);
	}
	RETURNvoid_();
}

//void QRect.getRect(int x, int y, int width, int height);
KMETHOD QRect_getRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int* x = Int_to(int*, sfp[1]);
		int* y = Int_to(int*, sfp[2]);
		int* width = Int_to(int*, sfp[3]);
		int* height = Int_to(int*, sfp[4]);
		qp->getRect(x, y, width, height);
	}
	RETURNvoid_();
}

//int QRect.getHeight();
KMETHOD QRect_getHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int ret_v = qp->height();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QRect QRect.intersected(QRect rectangle);
KMETHOD QRect_intersected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		QRect ret_v = qp->intersected(rectangle);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QRect.intersects(QRect rectangle);
KMETHOD QRect_intersects(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		bool ret_v = qp->intersects(rectangle);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QRect.isEmpty();
KMETHOD QRect_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QRect.getLeft();
KMETHOD QRect_getLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int ret_v = qp->left();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QRect.moveBottom(int y);
KMETHOD QRect_moveBottom(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int y = Int_to(int, sfp[1]);
		qp->moveBottom(y);
	}
	RETURNvoid_();
}

//void QRect.moveBottomLeft(QPoint position);
KMETHOD QRect_moveBottomLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		qp->moveBottomLeft(position);
	}
	RETURNvoid_();
}

//void QRect.moveBottomRight(QPoint position);
KMETHOD QRect_moveBottomRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		qp->moveBottomRight(position);
	}
	RETURNvoid_();
}

//void QRect.moveCenter(QPoint position);
KMETHOD QRect_moveCenter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		qp->moveCenter(position);
	}
	RETURNvoid_();
}

//void QRect.moveLeft(int x);
KMETHOD QRect_moveLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		qp->moveLeft(x);
	}
	RETURNvoid_();
}

//void QRect.moveRight(int x);
KMETHOD QRect_moveRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		qp->moveRight(x);
	}
	RETURNvoid_();
}

//void QRect.moveTo(int x, int y);
KMETHOD QRect_moveTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		qp->moveTo(x, y);
	}
	RETURNvoid_();
}

/*
//void QRect.moveTo(QPoint position);
KMETHOD QRect_moveTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		qp->moveTo(position);
	}
	RETURNvoid_();
}
*/
//void QRect.moveTop(int y);
KMETHOD QRect_moveTop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int y = Int_to(int, sfp[1]);
		qp->moveTop(y);
	}
	RETURNvoid_();
}

//void QRect.moveTopLeft(QPoint position);
KMETHOD QRect_moveTopLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		qp->moveTopLeft(position);
	}
	RETURNvoid_();
}

//void QRect.moveTopRight(QPoint position);
KMETHOD QRect_moveTopRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		qp->moveTopRight(position);
	}
	RETURNvoid_();
}

//QRect QRect.normalized();
KMETHOD QRect_normalized(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->normalized();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QRect.getRight();
KMETHOD QRect_getRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int ret_v = qp->right();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QRect.setBottom(int y);
KMETHOD QRect_setBottom(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int y = Int_to(int, sfp[1]);
		qp->setBottom(y);
	}
	RETURNvoid_();
}

//void QRect.setBottomLeft(QPoint position);
KMETHOD QRect_setBottomLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		qp->setBottomLeft(position);
	}
	RETURNvoid_();
}

//void QRect.setBottomRight(QPoint position);
KMETHOD QRect_setBottomRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		qp->setBottomRight(position);
	}
	RETURNvoid_();
}

//void QRect.setCoords(int x1, int y1, int x2, int y2);
KMETHOD QRect_setCoords(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int x1 = Int_to(int, sfp[1]);
		int y1 = Int_to(int, sfp[2]);
		int x2 = Int_to(int, sfp[3]);
		int y2 = Int_to(int, sfp[4]);
		qp->setCoords(x1, y1, x2, y2);
	}
	RETURNvoid_();
}

//void QRect.setHeight(int height);
KMETHOD QRect_setHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int height = Int_to(int, sfp[1]);
		qp->setHeight(height);
	}
	RETURNvoid_();
}

//void QRect.setLeft(int x);
KMETHOD QRect_setLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		qp->setLeft(x);
	}
	RETURNvoid_();
}

//void QRect.setRect(int x, int y, int width, int height);
KMETHOD QRect_setRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		qp->setRect(x, y, width, height);
	}
	RETURNvoid_();
}

//void QRect.setRight(int x);
KMETHOD QRect_setRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		qp->setRight(x);
	}
	RETURNvoid_();
}

//void QRect.setSize(QSize size);
KMETHOD QRect_setSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		qp->setSize(size);
	}
	RETURNvoid_();
}

//void QRect.setTop(int y);
KMETHOD QRect_setTop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int y = Int_to(int, sfp[1]);
		qp->setTop(y);
	}
	RETURNvoid_();
}

//void QRect.setTopLeft(QPoint position);
KMETHOD QRect_setTopLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		qp->setTopLeft(position);
	}
	RETURNvoid_();
}

//void QRect.setTopRight(QPoint position);
KMETHOD QRect_setTopRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		qp->setTopRight(position);
	}
	RETURNvoid_();
}

//void QRect.setWidth(int width);
KMETHOD QRect_setWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int width = Int_to(int, sfp[1]);
		qp->setWidth(width);
	}
	RETURNvoid_();
}

//void QRect.setX(int x);
KMETHOD QRect_setX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		qp->setX(x);
	}
	RETURNvoid_();
}

//void QRect.setY(int y);
KMETHOD QRect_setY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int y = Int_to(int, sfp[1]);
		qp->setY(y);
	}
	RETURNvoid_();
}

//QSize QRect.getSize();
KMETHOD QRect_getSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->size();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QRect.getTop();
KMETHOD QRect_getTop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int ret_v = qp->top();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPoint QRect.getTopLeft();
KMETHOD QRect_getTopLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		QPoint ret_v = qp->topLeft();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QRect.getTopRight();
KMETHOD QRect_getTopRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		QPoint ret_v = qp->topRight();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QRect.translate(int dx, int dy);
KMETHOD QRect_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int dx = Int_to(int, sfp[1]);
		int dy = Int_to(int, sfp[2]);
		qp->translate(dx, dy);
	}
	RETURNvoid_();
}

/*
//void QRect.translate(QPoint offset);
KMETHOD QRect_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QPoint  offset = *RawPtr_to(const QPoint *, sfp[1]);
		qp->translate(offset);
	}
	RETURNvoid_();
}
*/
//QRect QRect.translated(int dx, int dy);
KMETHOD QRect_translated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int dx = Int_to(int, sfp[1]);
		int dy = Int_to(int, sfp[2]);
		QRect ret_v = qp->translated(dx, dy);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRect QRect.translated(QPoint offset);
KMETHOD QRect_translated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QPoint  offset = *RawPtr_to(const QPoint *, sfp[1]);
		QRect ret_v = qp->translated(offset);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QRect QRect.united(QRect rectangle);
KMETHOD QRect_united(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		QRect ret_v = qp->united(rectangle);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QRect.getWidth();
KMETHOD QRect_getWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int ret_v = qp->width();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QRect.getX();
KMETHOD QRect_getX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int ret_v = qp->x();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QRect.getY();
KMETHOD QRect_getY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *  qp = RawPtr_to(QRect *, sfp[0]);
	if (qp) {
		int ret_v = qp->y();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<String> QRect.parents();
KMETHOD QRect_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRect *qp = RawPtr_to(QRect*, sfp[0]);
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

DummyQRect::DummyQRect()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQRect::setSelf(knh_RawPtr_t *ptr)
{
	DummyQRect::self = ptr;
}

bool DummyQRect::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQRect::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRect::event_map->bigin();
	if ((itr = DummyQRect::event_map->find(str)) == DummyQRect::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQRect::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRect::slot_map->bigin();
	if ((itr = DummyQRect::slot_map->find(str)) == DummyQRect::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQRect::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQRect::connection(QObject *o)
{
	QRect *p = dynamic_cast<QRect*>(o);
	if (p != NULL) {
	}
}

KQRect::KQRect() : QRect()
{
	self = NULL;
	dummy = new DummyQRect();
}

KMETHOD QRect_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRect *qp = RawPtr_to(KQRect *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QRect]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRect]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QRect_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRect *qp = RawPtr_to(KQRect *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QRect]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRect]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QRect_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQRect *qp = (KQRect *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QRect_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQRect *qp = (KQRect *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QRect_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QRect*>(p1->rawptr) == *static_cast<QRect*>(p2->rawptr) ? 0 : 1);
}

void KQRect::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQRect(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QRect";
	cdef->free = QRect_free;
	cdef->reftrace = QRect_reftrace;
	cdef->compareTo = QRect_compareTo;
}


