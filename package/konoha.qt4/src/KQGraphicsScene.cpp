//QGraphicsScene QGraphicsScene.new(QObject parent);
KMETHOD QGraphicsScene_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQGraphicsScene *ret_v = new KQGraphicsScene(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGraphicsScene QGraphicsScene.new(QRectF sceneRect, QObject parent);
KMETHOD QGraphicsScene_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QRectF  sceneRect = *RawPtr_to(const QRectF *, sfp[1]);
	QObject*  parent = RawPtr_to(QObject*, sfp[2]);
	KQGraphicsScene *ret_v = new KQGraphicsScene(sceneRect, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QGraphicsScene QGraphicsScene.new(float x, float y, float width, float height, QObject parent);
KMETHOD QGraphicsScene_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	qreal x = Float_to(qreal, sfp[1]);
	qreal y = Float_to(qreal, sfp[2]);
	qreal width = Float_to(qreal, sfp[3]);
	qreal height = Float_to(qreal, sfp[4]);
	QObject*  parent = RawPtr_to(QObject*, sfp[5]);
	KQGraphicsScene *ret_v = new KQGraphicsScene(x, y, width, height, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QGraphicsItem QGraphicsScene.getActivePanel();
KMETHOD QGraphicsScene_getActivePanel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QGraphicsItem* ret_v = qp->activePanel();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsWidget QGraphicsScene.getActiveWindow();
KMETHOD QGraphicsScene_getActiveWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QGraphicsWidget* ret_v = qp->activeWindow();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsEllipseItem QGraphicsScene.addEllipse(QRectF rect, QPen pen, QBrush brush);
KMETHOD QGraphicsScene_addEllipse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		const QPen  pen = *RawPtr_to(const QPen *, sfp[2]);
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[3]);
		QGraphicsEllipseItem* ret_v = qp->addEllipse(rect, pen, brush);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsEllipseItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QGraphicsEllipseItem QGraphicsScene.addEllipse(float x, float y, float w, float h, QPen pen, QBrush brush);
KMETHOD QGraphicsScene_addEllipse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		const QPen  pen = *RawPtr_to(const QPen *, sfp[5]);
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[6]);
		QGraphicsEllipseItem* ret_v = qp->addEllipse(x, y, w, h, pen, brush);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsEllipseItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//void QGraphicsScene.addItem(QGraphicsItem item);
KMETHOD QGraphicsScene_addItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QGraphicsItem*  item = RawPtr_to(QGraphicsItem*, sfp[1]);
		qp->addItem(item);
	}
	RETURNvoid_();
}

//QGraphicsLineItem QGraphicsScene.addLine(QLineF line, QPen pen);
KMETHOD QGraphicsScene_addLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QLineF  line = *RawPtr_to(const QLineF *, sfp[1]);
		const QPen  pen = *RawPtr_to(const QPen *, sfp[2]);
		QGraphicsLineItem* ret_v = qp->addLine(line, pen);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsLineItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QGraphicsLineItem QGraphicsScene.addLine(float x1, float y1, float x2, float y2, QPen pen);
KMETHOD QGraphicsScene_addLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		qreal x1 = Float_to(qreal, sfp[1]);
		qreal y1 = Float_to(qreal, sfp[2]);
		qreal x2 = Float_to(qreal, sfp[3]);
		qreal y2 = Float_to(qreal, sfp[4]);
		const QPen  pen = *RawPtr_to(const QPen *, sfp[5]);
		QGraphicsLineItem* ret_v = qp->addLine(x1, y1, x2, y2, pen);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsLineItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QGraphicsPathItem QGraphicsScene.addPath(QPainterPath path, QPen pen, QBrush brush);
KMETHOD QGraphicsScene_addPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		const QPen  pen = *RawPtr_to(const QPen *, sfp[2]);
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[3]);
		QGraphicsPathItem* ret_v = qp->addPath(path, pen, brush);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsPathItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsPixmapItem QGraphicsScene.addPixmap(QPixmap pixmap);
KMETHOD QGraphicsScene_addPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
		QGraphicsPixmapItem* ret_v = qp->addPixmap(pixmap);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsPixmapItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsPolygonItem QGraphicsScene.addPolygon(QPolygonF polygon, QPen pen, QBrush brush);
KMETHOD QGraphicsScene_addPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QPolygonF  polygon = *RawPtr_to(const QPolygonF *, sfp[1]);
		const QPen  pen = *RawPtr_to(const QPen *, sfp[2]);
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[3]);
		QGraphicsPolygonItem* ret_v = qp->addPolygon(polygon, pen, brush);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsPolygonItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsRectItem QGraphicsScene.addRect(QRectF rect, QPen pen, QBrush brush);
KMETHOD QGraphicsScene_addRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		const QPen  pen = *RawPtr_to(const QPen *, sfp[2]);
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[3]);
		QGraphicsRectItem* ret_v = qp->addRect(rect, pen, brush);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsRectItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QGraphicsRectItem QGraphicsScene.addRect(float x, float y, float w, float h, QPen pen, QBrush brush);
KMETHOD QGraphicsScene_addRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		const QPen  pen = *RawPtr_to(const QPen *, sfp[5]);
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[6]);
		QGraphicsRectItem* ret_v = qp->addRect(x, y, w, h, pen, brush);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsRectItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QGraphicsSimpleTextItem QGraphicsScene.addSimpleText(String text, QFont font);
KMETHOD QGraphicsScene_addSimpleText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QString text = String_to(const QString, sfp[1]);
		const QFont  font = *RawPtr_to(const QFont *, sfp[2]);
		QGraphicsSimpleTextItem* ret_v = qp->addSimpleText(text, font);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsSimpleTextItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsTextItem QGraphicsScene.addText(String text, QFont font);
KMETHOD QGraphicsScene_addText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QString text = String_to(const QString, sfp[1]);
		const QFont  font = *RawPtr_to(const QFont *, sfp[2]);
		QGraphicsTextItem* ret_v = qp->addText(text, font);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsTextItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsProxyWidget QGraphicsScene.addWidget(QWidget widget, int wFlags);
KMETHOD QGraphicsScene_addWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		Qt::WindowFlags wFlags = Int_to(Qt::WindowFlags, sfp[2]);
		QGraphicsProxyWidget* ret_v = qp->addWidget(widget, wFlags);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsProxyWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QGraphicsScene.getBackgroundBrush();
KMETHOD QGraphicsScene_getBackgroundBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QBrush ret_v = qp->backgroundBrush();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGraphicsScene.getBspTreeDepth();
KMETHOD QGraphicsScene_getBspTreeDepth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->bspTreeDepth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGraphicsScene.clearFocus();
KMETHOD QGraphicsScene_clearFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		qp->clearFocus();
	}
	RETURNvoid_();
}

//Array<QGraphicsItem> QGraphicsScene.collidingItems(QGraphicsItem item, int mode);
KMETHOD QGraphicsScene_collidingItems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		Qt::ItemSelectionMode mode = Int_to(Qt::ItemSelectionMode, sfp[2]);
		QList<QGraphicsItem*>ret_v = qp->collidingItems(item, mode);
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
	

//QGraphicsItemGroup QGraphicsScene.createItemGroup(Array<QGraphicsItem> items);
KMETHOD QGraphicsScene_createItemGroup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QGraphicsItem*> items;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			items.append((QGraphicsItem*)p->rawptr);
		}
		QGraphicsItemGroup* ret_v = qp->createItemGroup(items);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsItemGroup*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsScene.destroyItemGroup(QGraphicsItemGroup group);
KMETHOD QGraphicsScene_destroyItemGroup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QGraphicsItemGroup*  group = RawPtr_to(QGraphicsItemGroup*, sfp[1]);
		qp->destroyItemGroup(group);
	}
	RETURNvoid_();
}

//QGraphicsItem QGraphicsScene.getFocusItem();
KMETHOD QGraphicsScene_getFocusItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QGraphicsItem* ret_v = qp->focusItem();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFont QGraphicsScene.getFont();
KMETHOD QGraphicsScene_getFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QFont ret_v = qp->font();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QGraphicsScene.getForegroundBrush();
KMETHOD QGraphicsScene_getForegroundBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QBrush ret_v = qp->foregroundBrush();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGraphicsScene.hasFocus();
KMETHOD QGraphicsScene_hasFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->hasFocus();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//float QGraphicsScene.height();
KMETHOD QGraphicsScene_height(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->height();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//@Virtual QVariant QGraphicsScene.inputMethodQuery(int query);
KMETHOD QGraphicsScene_inputMethodQuery(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
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

//void QGraphicsScene.invalidate(float x, float y, float w, float h, int layers);
KMETHOD QGraphicsScene_invalidate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		QGraphicsScene::SceneLayers layers = Int_to(QGraphicsScene::SceneLayers, sfp[5]);
		qp->invalidate(x, y, w, h, layers);
	}
	RETURNvoid_();
}

//boolean QGraphicsScene.isActive();
KMETHOD QGraphicsScene_isActive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isActive();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsScene.isSortCacheEnabled();
KMETHOD QGraphicsScene_isSortCacheEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isSortCacheEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QGraphicsItem QGraphicsScene.itemAt(QPointF position, QTransform deviceTransform);
KMETHOD QGraphicsScene_itemAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QPointF  position = *RawPtr_to(const QPointF *, sfp[1]);
		const QTransform  deviceTransform = *RawPtr_to(const QTransform *, sfp[2]);
		QGraphicsItem* ret_v = qp->itemAt(position, deviceTransform);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QGraphicsItem QGraphicsScene.itemAt(float x, float y, QTransform deviceTransform);
KMETHOD QGraphicsScene_itemAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		const QTransform  deviceTransform = *RawPtr_to(const QTransform *, sfp[3]);
		QGraphicsItem* ret_v = qp->itemAt(x, y, deviceTransform);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//int QGraphicsScene.getItemIndexMethod();
KMETHOD QGraphicsScene_getItemIndexMethod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QGraphicsScene::ItemIndexMethod ret_v = qp->itemIndexMethod();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<QGraphicsItem> QGraphicsScene.items();
KMETHOD QGraphicsScene_items(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
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
//Array<QGraphicsItem> QGraphicsScene.items(int order);
KMETHOD QGraphicsScene_items(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		Qt::SortOrder order = Int_to(Qt::SortOrder, sfp[1]);
		QList<QGraphicsItem*>ret_v = qp->items(order);
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
//Array<QGraphicsItem> QGraphicsScene.items(QPointF pos, int mode, int order, QTransform deviceTransform);
KMETHOD QGraphicsScene_items(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QPointF  pos = *RawPtr_to(const QPointF *, sfp[1]);
		Qt::ItemSelectionMode mode = Int_to(Qt::ItemSelectionMode, sfp[2]);
		Qt::SortOrder order = Int_to(Qt::SortOrder, sfp[3]);
		const QTransform  deviceTransform = *RawPtr_to(const QTransform *, sfp[4]);
		QList<QGraphicsItem*>ret_v = qp->items(pos, mode, order, deviceTransform);
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
//Array<QGraphicsItem> QGraphicsScene.items(float x, float y, float w, float h, int mode, int order, QTransform deviceTransform);
KMETHOD QGraphicsScene_items(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		Qt::ItemSelectionMode mode = Int_to(Qt::ItemSelectionMode, sfp[5]);
		Qt::SortOrder order = Int_to(Qt::SortOrder, sfp[6]);
		const QTransform  deviceTransform = *RawPtr_to(const QTransform *, sfp[7]);
		QList<QGraphicsItem*>ret_v = qp->items(x, y, w, h, mode, order, deviceTransform);
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
//Array<QGraphicsItem> QGraphicsScene.items(QRectF rect, int mode, int order, QTransform deviceTransform);
KMETHOD QGraphicsScene_items(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		Qt::ItemSelectionMode mode = Int_to(Qt::ItemSelectionMode, sfp[2]);
		Qt::SortOrder order = Int_to(Qt::SortOrder, sfp[3]);
		const QTransform  deviceTransform = *RawPtr_to(const QTransform *, sfp[4]);
		QList<QGraphicsItem*>ret_v = qp->items(rect, mode, order, deviceTransform);
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
//Array<QGraphicsItem> QGraphicsScene.items(QPolygonF polygon, int mode, int order, QTransform deviceTransform);
KMETHOD QGraphicsScene_items(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QPolygonF  polygon = *RawPtr_to(const QPolygonF *, sfp[1]);
		Qt::ItemSelectionMode mode = Int_to(Qt::ItemSelectionMode, sfp[2]);
		Qt::SortOrder order = Int_to(Qt::SortOrder, sfp[3]);
		const QTransform  deviceTransform = *RawPtr_to(const QTransform *, sfp[4]);
		QList<QGraphicsItem*>ret_v = qp->items(polygon, mode, order, deviceTransform);
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
//Array<QGraphicsItem> QGraphicsScene.items(QPainterPath path, int mode, int order, QTransform deviceTransform);
KMETHOD QGraphicsScene_items(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		Qt::ItemSelectionMode mode = Int_to(Qt::ItemSelectionMode, sfp[2]);
		Qt::SortOrder order = Int_to(Qt::SortOrder, sfp[3]);
		const QTransform  deviceTransform = *RawPtr_to(const QTransform *, sfp[4]);
		QList<QGraphicsItem*>ret_v = qp->items(path, mode, order, deviceTransform);
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
//QRectF QGraphicsScene.itemsBoundingRect();
KMETHOD QGraphicsScene_itemsBoundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QRectF ret_v = qp->itemsBoundingRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsItem QGraphicsScene.mouseGrabberItem();
KMETHOD QGraphicsScene_mouseGrabberItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QGraphicsItem* ret_v = qp->mouseGrabberItem();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPalette QGraphicsScene.getPalette();
KMETHOD QGraphicsScene_getPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QPalette ret_v = qp->palette();
		QPalette *ret_v_ = new QPalette(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsScene.removeItem(QGraphicsItem item);
KMETHOD QGraphicsScene_removeItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QGraphicsItem*  item = RawPtr_to(QGraphicsItem*, sfp[1]);
		qp->removeItem(item);
	}
	RETURNvoid_();
}

//void QGraphicsScene.render(QPainter painter, QRectF target, QRectF source, int aspectRatioMode);
KMETHOD QGraphicsScene_render(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QRectF  target = *RawPtr_to(const QRectF *, sfp[2]);
		const QRectF  source = *RawPtr_to(const QRectF *, sfp[3]);
		Qt::AspectRatioMode aspectRatioMode = Int_to(Qt::AspectRatioMode, sfp[4]);
		qp->render(painter, target, source, aspectRatioMode);
	}
	RETURNvoid_();
}

//QRectF QGraphicsScene.getSceneRect();
KMETHOD QGraphicsScene_getSceneRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QRectF ret_v = qp->sceneRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QGraphicsItem> QGraphicsScene.selectedItems();
KMETHOD QGraphicsScene_selectedItems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QList<QGraphicsItem*>ret_v = qp->selectedItems();
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
	

//QPainterPath QGraphicsScene.getSelectionArea();
KMETHOD QGraphicsScene_getSelectionArea(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QPainterPath ret_v = qp->selectionArea();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGraphicsScene.sendEvent(QGraphicsItem item, QEvent event);
KMETHOD QGraphicsScene_sendEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QGraphicsItem*  item = RawPtr_to(QGraphicsItem*, sfp[1]);
		QEvent*  event = RawPtr_to(QEvent*, sfp[2]);
		bool ret_v = qp->sendEvent(item, event);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGraphicsScene.setActivePanel(QGraphicsItem item);
KMETHOD QGraphicsScene_setActivePanel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QGraphicsItem*  item = RawPtr_to(QGraphicsItem*, sfp[1]);
		qp->setActivePanel(item);
	}
	RETURNvoid_();
}

//void QGraphicsScene.setActiveWindow(QGraphicsWidget widget);
KMETHOD QGraphicsScene_setActiveWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QGraphicsWidget*  widget = RawPtr_to(QGraphicsWidget*, sfp[1]);
		qp->setActiveWindow(widget);
	}
	RETURNvoid_();
}

//void QGraphicsScene.setBackgroundBrush(QBrush brush);
KMETHOD QGraphicsScene_setBackgroundBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[1]);
		qp->setBackgroundBrush(brush);
	}
	RETURNvoid_();
}

//void QGraphicsScene.setBspTreeDepth(int depth);
KMETHOD QGraphicsScene_setBspTreeDepth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		int depth = Int_to(int, sfp[1]);
		qp->setBspTreeDepth(depth);
	}
	RETURNvoid_();
}

//void QGraphicsScene.setFocus(int focusReason);
KMETHOD QGraphicsScene_setFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		Qt::FocusReason focusReason = Int_to(Qt::FocusReason, sfp[1]);
		qp->setFocus(focusReason);
	}
	RETURNvoid_();
}

//void QGraphicsScene.setFocusItem(QGraphicsItem item, int focusReason);
KMETHOD QGraphicsScene_setFocusItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QGraphicsItem*  item = RawPtr_to(QGraphicsItem*, sfp[1]);
		Qt::FocusReason focusReason = Int_to(Qt::FocusReason, sfp[2]);
		qp->setFocusItem(item, focusReason);
	}
	RETURNvoid_();
}

//void QGraphicsScene.setFont(QFont font);
KMETHOD QGraphicsScene_setFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
		qp->setFont(font);
	}
	RETURNvoid_();
}

//void QGraphicsScene.setForegroundBrush(QBrush brush);
KMETHOD QGraphicsScene_setForegroundBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[1]);
		qp->setForegroundBrush(brush);
	}
	RETURNvoid_();
}

//void QGraphicsScene.setItemIndexMethod(int method);
KMETHOD QGraphicsScene_setItemIndexMethod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QGraphicsScene::ItemIndexMethod method = Int_to(QGraphicsScene::ItemIndexMethod, sfp[1]);
		qp->setItemIndexMethod(method);
	}
	RETURNvoid_();
}

//void QGraphicsScene.setPalette(QPalette palette);
KMETHOD QGraphicsScene_setPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QPalette  palette = *RawPtr_to(const QPalette *, sfp[1]);
		qp->setPalette(palette);
	}
	RETURNvoid_();
}

//void QGraphicsScene.setSceneRect(QRectF rect);
KMETHOD QGraphicsScene_setSceneRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		qp->setSceneRect(rect);
	}
	RETURNvoid_();
}

/*
//void QGraphicsScene.setSceneRect(float x, float y, float w, float h);
KMETHOD QGraphicsScene_setSceneRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
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
//void QGraphicsScene.setSelectionArea(QPainterPath path, QTransform deviceTransform);
KMETHOD QGraphicsScene_setSelectionArea(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		const QTransform  deviceTransform = *RawPtr_to(const QTransform *, sfp[2]);
		qp->setSelectionArea(path, deviceTransform);
	}
	RETURNvoid_();
}

/*
//void QGraphicsScene.setSelectionArea(QPainterPath path, int mode, QTransform deviceTransform);
KMETHOD QGraphicsScene_setSelectionArea(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		Qt::ItemSelectionMode mode = Int_to(Qt::ItemSelectionMode, sfp[2]);
		const QTransform  deviceTransform = *RawPtr_to(const QTransform *, sfp[3]);
		qp->setSelectionArea(path, mode, deviceTransform);
	}
	RETURNvoid_();
}
*/
//void QGraphicsScene.setSortCacheEnabled(boolean enabled);
KMETHOD QGraphicsScene_setSortCacheEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setSortCacheEnabled(enabled);
	}
	RETURNvoid_();
}

//void QGraphicsScene.setStickyFocus(boolean enabled);
KMETHOD QGraphicsScene_setStickyFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setStickyFocus(enabled);
	}
	RETURNvoid_();
}

//void QGraphicsScene.setStyle(QStyle style);
KMETHOD QGraphicsScene_setStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QStyle*  style = RawPtr_to(QStyle*, sfp[1]);
		qp->setStyle(style);
	}
	RETURNvoid_();
}

//boolean QGraphicsScene.getStickyFocus();
KMETHOD QGraphicsScene_getStickyFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->stickyFocus();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QStyle QGraphicsScene.getStyle();
KMETHOD QGraphicsScene_getStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QStyle* ret_v = qp->style();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QStyle*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsScene.update(float x, float y, float w, float h);
KMETHOD QGraphicsScene_update(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		qp->update(x, y, w, h);
	}
	RETURNvoid_();
}

//Array<QGraphicsView> QGraphicsScene.views();
KMETHOD QGraphicsScene_views(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		QList<QGraphicsView*>ret_v = qp->views();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QGraphicsView"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//float QGraphicsScene.width();
KMETHOD QGraphicsScene_width(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->width();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QGraphicsScene.advance();
KMETHOD QGraphicsScene_advance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		qp->advance();
	}
	RETURNvoid_();
}

//void QGraphicsScene.clear();
KMETHOD QGraphicsScene_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		qp->clear();
	}
	RETURNvoid_();
}

//void QGraphicsScene.clearSelection();
KMETHOD QGraphicsScene_clearSelection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		qp->clearSelection();
	}
	RETURNvoid_();
}

/*
//void QGraphicsScene.invalidate(QRectF rect, int layers);
KMETHOD QGraphicsScene_invalidate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		QGraphicsScene::SceneLayers layers = Int_to(QGraphicsScene::SceneLayers, sfp[2]);
		qp->invalidate(rect, layers);
	}
	RETURNvoid_();
}
*/
/*
//void QGraphicsScene.update(QRectF rect);
KMETHOD QGraphicsScene_update(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsScene *  qp = RawPtr_to(QGraphicsScene *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		qp->update(rect);
	}
	RETURNvoid_();
}
*/

DummyQGraphicsScene::DummyQGraphicsScene()
{
	self = NULL;
	context_menu_event_func = NULL;
	drag_enter_event_func = NULL;
	drag_leave_event_func = NULL;
	drag_move_event_func = NULL;
	drop_event_func = NULL;
	focus_in_event_func = NULL;
	focus_out_event_func = NULL;
	help_event_func = NULL;
	input_method_event_func = NULL;
	key_press_event_func = NULL;
	key_release_event_func = NULL;
	mouse_double_click_event_func = NULL;
	mouse_move_event_func = NULL;
	mouse_press_event_func = NULL;
	mouse_release_event_func = NULL;
	wheel_event_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	event_map->insert(map<string, knh_Func_t *>::value_type("context-menu-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("drag-enter-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("drag-leave-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("drag-move-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("drop-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("focus-in-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("focus-out-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("help-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("input-method-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("key-press-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("key-release-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("mouse-double-click-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("mouse-move-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("mouse-press-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("mouse-release-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("wheel-event", NULL));
}

void DummyQGraphicsScene::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsScene::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQGraphicsScene::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	case QEvent::GraphicsSceneContextMenu:
		ret = contextMenuEvent(dynamic_cast<QGraphicsSceneContextMenuEvent*>(event));
		break;
	case QEvent::GraphicsSceneDragEnter:
		ret = dragEnterEvent(dynamic_cast<QGraphicsSceneDragDropEvent*>(event));
		break;
	case QEvent::GraphicsSceneDragLeave:
		ret = dragLeaveEvent(dynamic_cast<QGraphicsSceneDragDropEvent*>(event));
		break;
	case QEvent::GraphicsSceneDragMove:
		ret = dragMoveEvent(dynamic_cast<QGraphicsSceneDragDropEvent*>(event));
		break;
	case QEvent::GraphicsSceneDrop:
		ret = dropEvent(dynamic_cast<QGraphicsSceneDragDropEvent*>(event));
		break;
	case QEvent::FocusIn:
		ret = focusInEvent(dynamic_cast<QFocusEvent*>(event));
		break;
	case QEvent::FocusOut:
		ret = focusOutEvent(dynamic_cast<QFocusEvent*>(event));
		break;
	case QEvent::GraphicsSceneHelp:
		ret = helpEvent(dynamic_cast<QGraphicsSceneHelpEvent*>(event));
		break;
	case QEvent::InputMethod:
		ret = inputMethodEvent(dynamic_cast<QInputMethodEvent*>(event));
		break;
	case QEvent::KeyPress:
		ret = keyPressEvent(dynamic_cast<QKeyEvent*>(event));
		break;
	case QEvent::KeyRelease:
		ret = keyReleaseEvent(dynamic_cast<QKeyEvent*>(event));
		break;
	case QEvent::GraphicsSceneMouseDoubleClick:
		ret = mouseDoubleClickEvent(dynamic_cast<QGraphicsSceneMouseEvent*>(event));
		break;
	case QEvent::GraphicsSceneMouseMove:
		ret = mouseMoveEvent(dynamic_cast<QGraphicsSceneMouseEvent*>(event));
		break;
	case QEvent::GraphicsSceneMousePress:
		ret = mousePressEvent(dynamic_cast<QGraphicsSceneMouseEvent*>(event));
		break;
	case QEvent::GraphicsSceneMouseRelease:
		ret = mouseReleaseEvent(dynamic_cast<QGraphicsSceneMouseEvent*>(event));
		break;
	case QEvent::GraphicsSceneWheel:
		ret = wheelEvent(dynamic_cast<QGraphicsSceneWheelEvent*>(event));
		break;
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsScene::contextMenuEvent(QGraphicsSceneContextMenuEvent* contextMenuEvent)
{
	if (context_menu_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneContextMenuEvent, contextMenuEvent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, context_menu_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsScene::dragEnterEvent(QGraphicsSceneDragDropEvent* event)
{
	if (drag_enter_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneDragDropEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, drag_enter_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsScene::dragLeaveEvent(QGraphicsSceneDragDropEvent* event)
{
	if (drag_leave_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneDragDropEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, drag_leave_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsScene::dragMoveEvent(QGraphicsSceneDragDropEvent* event)
{
	if (drag_move_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneDragDropEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, drag_move_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsScene::dropEvent(QGraphicsSceneDragDropEvent* event)
{
	if (drop_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneDragDropEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, drop_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsScene::focusInEvent(QFocusEvent* focusEvent)
{
	if (focus_in_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QFocusEvent, focusEvent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, focus_in_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsScene::focusOutEvent(QFocusEvent* focusEvent)
{
	if (focus_out_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QFocusEvent, focusEvent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, focus_out_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsScene::helpEvent(QGraphicsSceneHelpEvent* helpEvent)
{
	if (help_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneHelpEvent, helpEvent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, help_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsScene::inputMethodEvent(QInputMethodEvent* event)
{
	if (input_method_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QInputMethodEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, input_method_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsScene::keyPressEvent(QKeyEvent* keyEvent)
{
	if (key_press_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QKeyEvent, keyEvent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, key_press_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsScene::keyReleaseEvent(QKeyEvent* keyEvent)
{
	if (key_release_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QKeyEvent, keyEvent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, key_release_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
	if (mouse_double_click_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneMouseEvent, mouseEvent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, mouse_double_click_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
	if (mouse_move_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneMouseEvent, mouseEvent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, mouse_move_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
	if (mouse_press_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneMouseEvent, mouseEvent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, mouse_press_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
	if (mouse_release_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneMouseEvent, mouseEvent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, mouse_release_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsScene::wheelEvent(QGraphicsSceneWheelEvent* wheelEvent)
{
	if (wheel_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneWheelEvent, wheelEvent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, wheel_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsScene::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsScene::event_map->bigin();
	if ((itr = DummyQGraphicsScene::event_map->find(str)) == DummyQGraphicsScene::event_map->end()) {
		bool ret;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		context_menu_event_func = (*event_map)["context-menu-event"];
		drag_enter_event_func = (*event_map)["drag-enter-event"];
		drag_leave_event_func = (*event_map)["drag-leave-event"];
		drag_move_event_func = (*event_map)["drag-move-event"];
		drop_event_func = (*event_map)["drop-event"];
		focus_in_event_func = (*event_map)["focus-in-event"];
		focus_out_event_func = (*event_map)["focus-out-event"];
		help_event_func = (*event_map)["help-event"];
		input_method_event_func = (*event_map)["input-method-event"];
		key_press_event_func = (*event_map)["key-press-event"];
		key_release_event_func = (*event_map)["key-release-event"];
		mouse_double_click_event_func = (*event_map)["mouse-double-click-event"];
		mouse_move_event_func = (*event_map)["mouse-move-event"];
		mouse_press_event_func = (*event_map)["mouse-press-event"];
		mouse_release_event_func = (*event_map)["mouse-release-event"];
		wheel_event_func = (*event_map)["wheel-event"];
		return true;
	}
}

bool DummyQGraphicsScene::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsScene::slot_map->bigin();
	if ((itr = DummyQGraphicsScene::event_map->find(str)) == DummyQGraphicsScene::slot_map->end()) {
		bool ret;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQGraphicsScene::KQGraphicsScene(QObject* parent) : QGraphicsScene(parent)
{
	self = NULL;
}

KMETHOD QGraphicsScene_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsScene *qp = RawPtr_to(KQGraphicsScene *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsScene]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQGraphicsScene::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsScene]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QGraphicsScene_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsScene *qp = RawPtr_to(KQGraphicsScene *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsScene]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQGraphicsScene::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsScene]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsScene_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsScene *qp = (KQGraphicsScene *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsScene_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQGraphicsScene *qp = (KQGraphicsScene *)p->rawptr;
//		(void)qp;
		if (qp->context_menu_event_func != NULL) {
			KNH_ADDREF(ctx, qp->context_menu_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->drag_enter_event_func != NULL) {
			KNH_ADDREF(ctx, qp->drag_enter_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->drag_leave_event_func != NULL) {
			KNH_ADDREF(ctx, qp->drag_leave_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->drag_move_event_func != NULL) {
			KNH_ADDREF(ctx, qp->drag_move_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->drop_event_func != NULL) {
			KNH_ADDREF(ctx, qp->drop_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->focus_in_event_func != NULL) {
			KNH_ADDREF(ctx, qp->focus_in_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->focus_out_event_func != NULL) {
			KNH_ADDREF(ctx, qp->focus_out_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->help_event_func != NULL) {
			KNH_ADDREF(ctx, qp->help_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->input_method_event_func != NULL) {
			KNH_ADDREF(ctx, qp->input_method_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->key_press_event_func != NULL) {
			KNH_ADDREF(ctx, qp->key_press_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->key_release_event_func != NULL) {
			KNH_ADDREF(ctx, qp->key_release_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->mouse_double_click_event_func != NULL) {
			KNH_ADDREF(ctx, qp->mouse_double_click_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->mouse_move_event_func != NULL) {
			KNH_ADDREF(ctx, qp->mouse_move_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->mouse_press_event_func != NULL) {
			KNH_ADDREF(ctx, qp->mouse_press_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->mouse_release_event_func != NULL) {
			KNH_ADDREF(ctx, qp->mouse_release_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->wheel_event_func != NULL) {
			KNH_ADDREF(ctx, qp->wheel_event_func);
			KNH_SIZEREF(ctx);
		}
	}
}

static int QGraphicsScene_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQGraphicsScene::event(QEvent *event)
{
	if (!DummyQGraphicsScene::eventDispatcher(event)) {
		QGraphicsScene::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQGraphicsScene(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsScene";
	cdef->free = QGraphicsScene_free;
	cdef->reftrace = QGraphicsScene_reftrace;
	cdef->compareTo = QGraphicsScene_compareTo;
}

static knh_IntData_t QGraphicsSceneConstInt[] = {
	{"BspTreeIndex", QGraphicsScene::BspTreeIndex},
	{"NoIndex", QGraphicsScene::NoIndex},
	{"ItemLayer", QGraphicsScene::ItemLayer},
	{"BackgroundLayer", QGraphicsScene::BackgroundLayer},
	{"ForegroundLayer", QGraphicsScene::ForegroundLayer},
	{"AllLayers", QGraphicsScene::AllLayers},
	{NULL, 0}
};

DEFAPI(void) constQGraphicsScene(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QGraphicsSceneConstInt);
}

