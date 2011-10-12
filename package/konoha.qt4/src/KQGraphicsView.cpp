//@Virtual @Override QVariant QGraphicsView.inputMethodQuery(int query);
KMETHOD QGraphicsView_inputMethodQuery(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		Qt::InputMethodQuery query = Int_to(Qt::InputMethodQuery, sfp[1]);
		QVariant ret_v = qp->inputMethodQuery(query);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QGraphicsView.sizeHint();
KMETHOD QGraphicsView_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsView QGraphicsView.new(QWidget parent);
KMETHOD QGraphicsView_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQGraphicsView *ret_v = new KQGraphicsView(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGraphicsView QGraphicsView.new(QGraphicsScene scene, QWidget parent);
KMETHOD QGraphicsView_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene*  scene = RawPtr_to(QGraphicsScene*, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQGraphicsView *ret_v = new KQGraphicsView(scene, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QGraphicsView.getAlignment();
KMETHOD QGraphicsView_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment ret_v = qp->alignment();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QBrush QGraphicsView.getBackgroundBrush();
KMETHOD QGraphicsView_getBackgroundBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QBrush ret_v = qp->backgroundBrush();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGraphicsView.getCacheMode();
KMETHOD QGraphicsView_getCacheMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QGraphicsView::CacheMode ret_v = qp->cacheMode();
		QGraphicsView::CacheMode *ret_v_ = new QGraphicsView::CacheMode(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsView.centerOn(QPointF pos);
KMETHOD QGraphicsView_centerOn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QPointF  pos = *RawPtr_to(const QPointF *, sfp[1]);
		qp->centerOn(pos);
	}
	RETURNvoid_();
}

/*
//void QGraphicsView.centerOn(float x, float y);
KMETHOD QGraphicsView_centerOn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qp->centerOn(x, y);
	}
	RETURNvoid_();
}
*/
/*
//void QGraphicsView.centerOn(QGraphicsItem item);
KMETHOD QGraphicsView_centerOn(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		qp->centerOn(item);
	}
	RETURNvoid_();
}
*/
//int QGraphicsView.getDragMode();
KMETHOD QGraphicsView_getDragMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QGraphicsView::DragMode ret_v = qp->dragMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGraphicsView.ensureVisible(QRectF rect, int xmargin, int ymargin);
KMETHOD QGraphicsView_ensureVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		int xmargin = Int_to(int, sfp[2]);
		int ymargin = Int_to(int, sfp[3]);
		qp->ensureVisible(rect, xmargin, ymargin);
	}
	RETURNvoid_();
}

/*
//void QGraphicsView.ensureVisible(float x, float y, float w, float h, int xmargin, int ymargin);
KMETHOD QGraphicsView_ensureVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		int xmargin = Int_to(int, sfp[5]);
		int ymargin = Int_to(int, sfp[6]);
		qp->ensureVisible(x, y, w, h, xmargin, ymargin);
	}
	RETURNvoid_();
}
*/
/*
//void QGraphicsView.ensureVisible(QGraphicsItem item, int xmargin, int ymargin);
KMETHOD QGraphicsView_ensureVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		int xmargin = Int_to(int, sfp[2]);
		int ymargin = Int_to(int, sfp[3]);
		qp->ensureVisible(item, xmargin, ymargin);
	}
	RETURNvoid_();
}
*/
//void QGraphicsView.fitInView(QRectF rect, int aspectRatioMode);
KMETHOD QGraphicsView_fitInView(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		Qt::AspectRatioMode aspectRatioMode = Int_to(Qt::AspectRatioMode, sfp[2]);
		qp->fitInView(rect, aspectRatioMode);
	}
	RETURNvoid_();
}

/*
//void QGraphicsView.fitInView(float x, float y, float w, float h, int aspectRatioMode);
KMETHOD QGraphicsView_fitInView(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		Qt::AspectRatioMode aspectRatioMode = Int_to(Qt::AspectRatioMode, sfp[5]);
		qp->fitInView(x, y, w, h, aspectRatioMode);
	}
	RETURNvoid_();
}
*/
/*
//void QGraphicsView.fitInView(QGraphicsItem item, int aspectRatioMode);
KMETHOD QGraphicsView_fitInView(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		Qt::AspectRatioMode aspectRatioMode = Int_to(Qt::AspectRatioMode, sfp[2]);
		qp->fitInView(item, aspectRatioMode);
	}
	RETURNvoid_();
}
*/
//QBrush QGraphicsView.getForegroundBrush();
KMETHOD QGraphicsView_getForegroundBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QBrush ret_v = qp->foregroundBrush();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGraphicsView.isInteractive();
KMETHOD QGraphicsView_isInteractive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isInteractive();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsView.isTransformed();
KMETHOD QGraphicsView_isTransformed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isTransformed();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QGraphicsItem QGraphicsView.itemAt(QPoint pos);
KMETHOD QGraphicsView_itemAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		QGraphicsItem* ret_v = qp->itemAt(pos);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QGraphicsItem QGraphicsView.itemAt(int x, int y);
KMETHOD QGraphicsView_itemAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		QGraphicsItem* ret_v = qp->itemAt(x, y);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//Array<QGraphicsItem> QGraphicsView.items();
KMETHOD QGraphicsView_items(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QList<QGraphicsItem*>ret_v = qp->items();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QGraphicsItem"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

/*
//Array<QGraphicsItem> QGraphicsView.items(QPoint pos);
KMETHOD QGraphicsView_items(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		QList<QGraphicsItem*>ret_v = qp->items(pos);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QGraphicsItem"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	
*/
/*
//Array<QGraphicsItem> QGraphicsView.items(int x, int y);
KMETHOD QGraphicsView_items(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		QList<QGraphicsItem*>ret_v = qp->items(x, y);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QGraphicsItem"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	
*/
/*
//Array<QGraphicsItem> QGraphicsView.items(int x, int y, int w, int h, int mode);
KMETHOD QGraphicsView_items(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int w = Int_to(int, sfp[3]);
		int h = Int_to(int, sfp[4]);
		Qt::ItemSelectionMode mode = Int_to(Qt::ItemSelectionMode, sfp[5]);
		QList<QGraphicsItem*>ret_v = qp->items(x, y, w, h, mode);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QGraphicsItem"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	
*/
/*
//Array<QGraphicsItem> QGraphicsView.items(QRect rect, int mode);
KMETHOD QGraphicsView_items(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		Qt::ItemSelectionMode mode = Int_to(Qt::ItemSelectionMode, sfp[2]);
		QList<QGraphicsItem*>ret_v = qp->items(rect, mode);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QGraphicsItem"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	
*/
/*
//Array<QGraphicsItem> QGraphicsView.items(QPolygon polygon, int mode);
KMETHOD QGraphicsView_items(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QPolygon  polygon = *RawPtr_to(const QPolygon *, sfp[1]);
		Qt::ItemSelectionMode mode = Int_to(Qt::ItemSelectionMode, sfp[2]);
		QList<QGraphicsItem*>ret_v = qp->items(polygon, mode);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QGraphicsItem"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	
*/
/*
//Array<QGraphicsItem> QGraphicsView.items(QPainterPath path, int mode);
KMETHOD QGraphicsView_items(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		Qt::ItemSelectionMode mode = Int_to(Qt::ItemSelectionMode, sfp[2]);
		QList<QGraphicsItem*>ret_v = qp->items(path, mode);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QGraphicsItem"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	
*/
//QPoint QGraphicsView.mapFromScene(QPointF point);
KMETHOD QGraphicsView_mapFromScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		QPoint ret_v = qp->mapFromScene(point);
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPolygon QGraphicsView.mapFromScene(QRectF rect);
KMETHOD QGraphicsView_mapFromScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		QPolygon ret_v = qp->mapFromScene(rect);
		QPolygon *ret_v_ = new QPolygon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPolygon QGraphicsView.mapFromScene(QPolygonF polygon);
KMETHOD QGraphicsView_mapFromScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QPolygonF  polygon = *RawPtr_to(const QPolygonF *, sfp[1]);
		QPolygon ret_v = qp->mapFromScene(polygon);
		QPolygon *ret_v_ = new QPolygon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPainterPath QGraphicsView.mapFromScene(QPainterPath path);
KMETHOD QGraphicsView_mapFromScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		QPainterPath ret_v = qp->mapFromScene(path);
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPoint QGraphicsView.mapFromScene(float x, float y);
KMETHOD QGraphicsView_mapFromScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		QPoint ret_v = qp->mapFromScene(x, y);
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPolygon QGraphicsView.mapFromScene(float x, float y, float w, float h);
KMETHOD QGraphicsView_mapFromScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		QPolygon ret_v = qp->mapFromScene(x, y, w, h);
		QPolygon *ret_v_ = new QPolygon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QPointF QGraphicsView.mapToScene(QPoint point);
KMETHOD QGraphicsView_mapToScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		QPointF ret_v = qp->mapToScene(point);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPolygonF QGraphicsView.mapToScene(QRect rect);
KMETHOD QGraphicsView_mapToScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		QPolygonF ret_v = qp->mapToScene(rect);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPolygonF QGraphicsView.mapToScene(QPolygon polygon);
KMETHOD QGraphicsView_mapToScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QPolygon  polygon = *RawPtr_to(const QPolygon *, sfp[1]);
		QPolygonF ret_v = qp->mapToScene(polygon);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPainterPath QGraphicsView.mapToScene(QPainterPath path);
KMETHOD QGraphicsView_mapToScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		QPainterPath ret_v = qp->mapToScene(path);
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPointF QGraphicsView.mapToScene(int x, int y);
KMETHOD QGraphicsView_mapToScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		QPointF ret_v = qp->mapToScene(x, y);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPolygonF QGraphicsView.mapToScene(int x, int y, int w, int h);
KMETHOD QGraphicsView_mapToScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int w = Int_to(int, sfp[3]);
		int h = Int_to(int, sfp[4]);
		QPolygonF ret_v = qp->mapToScene(x, y, w, h);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QMatrix QGraphicsView.getMatrix();
KMETHOD QGraphicsView_getMatrix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QMatrix ret_v = qp->matrix();
		QMatrix *ret_v_ = new QMatrix(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGraphicsView.getOptimizationFlags();
KMETHOD QGraphicsView_getOptimizationFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QGraphicsView::OptimizationFlags ret_v = qp->optimizationFlags();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGraphicsView.render(QPainter painter, QRectF target, QRect source, int aspectRatioMode);
KMETHOD QGraphicsView_render(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QRectF  target = *RawPtr_to(const QRectF *, sfp[2]);
		const QRect  source = *RawPtr_to(const QRect *, sfp[3]);
		Qt::AspectRatioMode aspectRatioMode = Int_to(Qt::AspectRatioMode, sfp[4]);
		qp->render(painter, target, source, aspectRatioMode);
	}
	RETURNvoid_();
}

//int QGraphicsView.getRenderHints();
KMETHOD QGraphicsView_getRenderHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QPainter::RenderHints ret_v = qp->renderHints();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGraphicsView.resetCachedContent();
KMETHOD QGraphicsView_resetCachedContent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		qp->resetCachedContent();
	}
	RETURNvoid_();
}

//void QGraphicsView.resetMatrix();
KMETHOD QGraphicsView_resetMatrix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		qp->resetMatrix();
	}
	RETURNvoid_();
}

//void QGraphicsView.resetTransform();
KMETHOD QGraphicsView_resetTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		qp->resetTransform();
	}
	RETURNvoid_();
}

//int QGraphicsView.getResizeAnchor();
KMETHOD QGraphicsView_getResizeAnchor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QGraphicsView::ViewportAnchor ret_v = qp->resizeAnchor();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGraphicsView.rotate(float angle);
KMETHOD QGraphicsView_rotate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		qreal angle = Float_to(qreal, sfp[1]);
		qp->rotate(angle);
	}
	RETURNvoid_();
}

//int QGraphicsView.getRubberBandSelectionMode();
KMETHOD QGraphicsView_getRubberBandSelectionMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		Qt::ItemSelectionMode ret_v = qp->rubberBandSelectionMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGraphicsView.scale(float sx, float sy);
KMETHOD QGraphicsView_scale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		qreal sx = Float_to(qreal, sfp[1]);
		qreal sy = Float_to(qreal, sfp[2]);
		qp->scale(sx, sy);
	}
	RETURNvoid_();
}

//QGraphicsScene QGraphicsView.getScene();
KMETHOD QGraphicsView_getScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QGraphicsScene* ret_v = qp->scene();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsScene*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRectF QGraphicsView.getSceneRect();
KMETHOD QGraphicsView_getSceneRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QRectF ret_v = qp->sceneRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsView.setAlignment(int alignment);
KMETHOD QGraphicsView_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment alignment = Int_to(Qt::Alignment, sfp[1]);
		qp->setAlignment(alignment);
	}
	RETURNvoid_();
}

//void QGraphicsView.setBackgroundBrush(QBrush brush);
KMETHOD QGraphicsView_setBackgroundBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[1]);
		qp->setBackgroundBrush(brush);
	}
	RETURNvoid_();
}

//void QGraphicsView.setCacheMode(int mode);
KMETHOD QGraphicsView_setCacheMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QGraphicsView::CacheMode  mode = *RawPtr_to(QGraphicsView::CacheMode *, sfp[1]);
		qp->setCacheMode(mode);
	}
	RETURNvoid_();
}

//void QGraphicsView.setDragMode(int mode);
KMETHOD QGraphicsView_setDragMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QGraphicsView::DragMode mode = Int_to(QGraphicsView::DragMode, sfp[1]);
		qp->setDragMode(mode);
	}
	RETURNvoid_();
}

//void QGraphicsView.setForegroundBrush(QBrush brush);
KMETHOD QGraphicsView_setForegroundBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[1]);
		qp->setForegroundBrush(brush);
	}
	RETURNvoid_();
}

//void QGraphicsView.setInteractive(boolean allowed);
KMETHOD QGraphicsView_setInteractive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		bool allowed = Boolean_to(bool, sfp[1]);
		qp->setInteractive(allowed);
	}
	RETURNvoid_();
}

//void QGraphicsView.setMatrix(QMatrix matrix, boolean combine);
KMETHOD QGraphicsView_setMatrix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QMatrix  matrix = *RawPtr_to(const QMatrix *, sfp[1]);
		bool combine = Boolean_to(bool, sfp[2]);
		qp->setMatrix(matrix, combine);
	}
	RETURNvoid_();
}

//void QGraphicsView.setOptimizationFlag(int flag, boolean enabled);
KMETHOD QGraphicsView_setOptimizationFlag(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QGraphicsView::OptimizationFlag flag = Int_to(QGraphicsView::OptimizationFlag, sfp[1]);
		bool enabled = Boolean_to(bool, sfp[2]);
		qp->setOptimizationFlag(flag, enabled);
	}
	RETURNvoid_();
}

//void QGraphicsView.setOptimizationFlags(int flags);
KMETHOD QGraphicsView_setOptimizationFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QGraphicsView::OptimizationFlags flags = Int_to(QGraphicsView::OptimizationFlags, sfp[1]);
		qp->setOptimizationFlags(flags);
	}
	RETURNvoid_();
}

//void QGraphicsView.setRenderHint(int hint, boolean enabled);
KMETHOD QGraphicsView_setRenderHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QPainter::RenderHint hint = Int_to(QPainter::RenderHint, sfp[1]);
		bool enabled = Boolean_to(bool, sfp[2]);
		qp->setRenderHint(hint, enabled);
	}
	RETURNvoid_();
}

//void QGraphicsView.setRenderHints(int hints);
KMETHOD QGraphicsView_setRenderHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QPainter::RenderHints hints = Int_to(QPainter::RenderHints, sfp[1]);
		qp->setRenderHints(hints);
	}
	RETURNvoid_();
}

//void QGraphicsView.setResizeAnchor(int anchor);
KMETHOD QGraphicsView_setResizeAnchor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QGraphicsView::ViewportAnchor anchor = Int_to(QGraphicsView::ViewportAnchor, sfp[1]);
		qp->setResizeAnchor(anchor);
	}
	RETURNvoid_();
}

//void QGraphicsView.setRubberBandSelectionMode(int mode);
KMETHOD QGraphicsView_setRubberBandSelectionMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		Qt::ItemSelectionMode mode = Int_to(Qt::ItemSelectionMode, sfp[1]);
		qp->setRubberBandSelectionMode(mode);
	}
	RETURNvoid_();
}

//void QGraphicsView.setScene(QGraphicsScene scene);
KMETHOD QGraphicsView_setScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QGraphicsScene*  scene = RawPtr_to(QGraphicsScene*, sfp[1]);
		qp->setScene(scene);
	}
	RETURNvoid_();
}

//void QGraphicsView.setSceneRect(QRectF rect);
KMETHOD QGraphicsView_setSceneRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		qp->setSceneRect(rect);
	}
	RETURNvoid_();
}

/*
//void QGraphicsView.setSceneRect(float x, float y, float w, float h);
KMETHOD QGraphicsView_setSceneRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		qp->setSceneRect(x, y, w, h);
	}
	RETURNvoid_();
}
*/
//void QGraphicsView.setTransform(QTransform matrix, boolean combine);
KMETHOD QGraphicsView_setTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QTransform  matrix = *RawPtr_to(const QTransform *, sfp[1]);
		bool combine = Boolean_to(bool, sfp[2]);
		qp->setTransform(matrix, combine);
	}
	RETURNvoid_();
}

//void QGraphicsView.setTransformationAnchor(int anchor);
KMETHOD QGraphicsView_setTransformationAnchor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QGraphicsView::ViewportAnchor anchor = Int_to(QGraphicsView::ViewportAnchor, sfp[1]);
		qp->setTransformationAnchor(anchor);
	}
	RETURNvoid_();
}

//void QGraphicsView.setViewportUpdateMode(int mode);
KMETHOD QGraphicsView_setViewportUpdateMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QGraphicsView::ViewportUpdateMode mode = Int_to(QGraphicsView::ViewportUpdateMode, sfp[1]);
		qp->setViewportUpdateMode(mode);
	}
	RETURNvoid_();
}

//void QGraphicsView.shear(float sh, float sv);
KMETHOD QGraphicsView_shear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		qreal sh = Float_to(qreal, sfp[1]);
		qreal sv = Float_to(qreal, sfp[2]);
		qp->shear(sh, sv);
	}
	RETURNvoid_();
}

//QTransform QGraphicsView.getTransform();
KMETHOD QGraphicsView_getTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QTransform ret_v = qp->transform();
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGraphicsView.getTransformationAnchor();
KMETHOD QGraphicsView_getTransformationAnchor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QGraphicsView::ViewportAnchor ret_v = qp->transformationAnchor();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGraphicsView.translate(float dx, float dy);
KMETHOD QGraphicsView_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		qreal dx = Float_to(qreal, sfp[1]);
		qreal dy = Float_to(qreal, sfp[2]);
		qp->translate(dx, dy);
	}
	RETURNvoid_();
}

//QTransform QGraphicsView.viewportTransform();
KMETHOD QGraphicsView_viewportTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QTransform ret_v = qp->viewportTransform();
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGraphicsView.getViewportUpdateMode();
KMETHOD QGraphicsView_getViewportUpdateMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		QGraphicsView::ViewportUpdateMode ret_v = qp->viewportUpdateMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGraphicsView.invalidateScene(QRectF rect, int layers);
KMETHOD QGraphicsView_invalidateScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		QGraphicsScene::SceneLayers layers = Int_to(QGraphicsScene::SceneLayers, sfp[2]);
		qp->invalidateScene(rect, layers);
	}
	RETURNvoid_();
}

//void QGraphicsView.updateScene(Array<QRectF> rects);
KMETHOD QGraphicsView_updateScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QRectF> rects;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			rects.append(*(QRectF*)p->rawptr);
		}
		qp->updateScene(rects);
	}
	RETURNvoid_();
}

//void QGraphicsView.updateSceneRect(QRectF rect);
KMETHOD QGraphicsView_updateSceneRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsView *  qp = RawPtr_to(QGraphicsView *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		qp->updateSceneRect(rect);
	}
	RETURNvoid_();
}


DummyQGraphicsView::DummyQGraphicsView()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGraphicsView::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsView::self = ptr;
	DummyQAbstractScrollArea::setSelf(ptr);
}

bool DummyQGraphicsView::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractScrollArea::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsView::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsView::event_map->bigin();
	if ((itr = DummyQGraphicsView::event_map->find(str)) == DummyQGraphicsView::event_map->end()) {
		bool ret;
		ret = DummyQAbstractScrollArea::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsView::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsView::slot_map->bigin();
	if ((itr = DummyQGraphicsView::event_map->find(str)) == DummyQGraphicsView::slot_map->end()) {
		bool ret;
		ret = DummyQAbstractScrollArea::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQGraphicsView::KQGraphicsView(QWidget* parent) : QGraphicsView(parent)
{
	self = NULL;
}

KMETHOD QGraphicsView_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsView *qp = RawPtr_to(KQGraphicsView *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsView]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQGraphicsView::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsView]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QGraphicsView_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsView *qp = RawPtr_to(KQGraphicsView *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsView]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQGraphicsView::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsView]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsView_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsView *qp = (KQGraphicsView *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsView_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQGraphicsView *qp = (KQGraphicsView *)p->rawptr;
		(void)qp;
	}
}

static int QGraphicsView_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQGraphicsView::event(QEvent *event)
{
	if (!DummyQGraphicsView::eventDispatcher(event)) {
		QGraphicsView::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQGraphicsView(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsView";
	cdef->free = QGraphicsView_free;
	cdef->reftrace = QGraphicsView_reftrace;
	cdef->compareTo = QGraphicsView_compareTo;
}

static knh_IntData_t QGraphicsViewConstInt[] = {
	{"CacheNone", QGraphicsView::CacheNone},
	{"CacheBackground", QGraphicsView::CacheBackground},
	{"NoDrag", QGraphicsView::NoDrag},
	{"ScrollHandDrag", QGraphicsView::ScrollHandDrag},
	{"RubberBandDrag", QGraphicsView::RubberBandDrag},
	{"DontClipPainter", QGraphicsView::DontClipPainter},
	{"DontSavePainterState", QGraphicsView::DontSavePainterState},
	{"DontAdjustForAntialiasing", QGraphicsView::DontAdjustForAntialiasing},
	{"IndirectPainting", QGraphicsView::IndirectPainting},
	{"NoAnchor", QGraphicsView::NoAnchor},
	{"AnchorViewCenter", QGraphicsView::AnchorViewCenter},
	{"AnchorUnderMouse", QGraphicsView::AnchorUnderMouse},
	{"FullViewportUpdate", QGraphicsView::FullViewportUpdate},
	{"MinimalViewportUpdate", QGraphicsView::MinimalViewportUpdate},
	{"SmartViewportUpdate", QGraphicsView::SmartViewportUpdate},
	{"BoundingRectViewportUpdate", QGraphicsView::BoundingRectViewportUpdate},
	{"NoViewportUpdate", QGraphicsView::NoViewportUpdate},
	{NULL, 0}
};

DEFAPI(void) constQGraphicsView(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QGraphicsViewConstInt);
}

