//
//boolean QGraphicsItem.getAcceptDrops();
KMETHOD QGraphicsItem_getAcceptDrops(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->acceptDrops();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsItem.getAcceptHoverEvents();
KMETHOD QGraphicsItem_getAcceptHoverEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->acceptHoverEvents();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsItem.getAcceptTouchEvents();
KMETHOD QGraphicsItem_getAcceptTouchEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->acceptTouchEvents();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QtMouseButtons QGraphicsItem.getAcceptedMouseButtons();
KMETHOD QGraphicsItem_getAcceptedMouseButtons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		Qt::MouseButtons ret_v = qp->acceptedMouseButtons();
		Qt::MouseButtons *ret_v_ = new Qt::MouseButtons(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QGraphicsItem.advance(int phase);
KMETHOD QGraphicsItem_advance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		int phase = Int_to(int, sfp[1]);
		qp->advance(phase);
	}
	RETURNvoid_();
}

//@Virtual QRectF QGraphicsItem.boundingRect();
KMETHOD QGraphicsItem_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->boundingRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRegion QGraphicsItem.boundingRegion(QTransform itemToDeviceTransform);
KMETHOD QGraphicsItem_boundingRegion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QTransform  itemToDeviceTransform = *RawPtr_to(const QTransform *, sfp[1]);
		QRegion ret_v = qp->boundingRegion(itemToDeviceTransform);
		QRegion *ret_v_ = new QRegion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QGraphicsItem.getBoundingRegionGranularity();
KMETHOD QGraphicsItem_getBoundingRegionGranularity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->boundingRegionGranularity();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QGraphicsItem.getCacheMode();
KMETHOD QGraphicsItem_getCacheMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsItem::CacheMode ret_v = qp->cacheMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<QGraphicsItem> QGraphicsItem.childItems();
KMETHOD QGraphicsItem_childItems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QList<QGraphicsItem*> ret_v = qp->childItems();
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
	

//QRectF QGraphicsItem.childrenBoundingRect();
KMETHOD QGraphicsItem_childrenBoundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->childrenBoundingRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsItem.clearFocus();
KMETHOD QGraphicsItem_clearFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qp->clearFocus();
	}
	RETURNvoid_();
}

//QPainterPath QGraphicsItem.clipPath();
KMETHOD QGraphicsItem_clipPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QPainterPath ret_v = qp->clipPath();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual boolean QGraphicsItem.collidesWithItem(QGraphicsItem other, int mode);
KMETHOD QGraphicsItem_collidesWithItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  other = RawPtr_to(const QGraphicsItem*, sfp[1]);
		Qt::ItemSelectionMode mode = Int_to(Qt::ItemSelectionMode, sfp[2]);
		bool ret_v = qp->collidesWithItem(other, mode);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QGraphicsItem.collidesWithPath(QPainterPath path, int mode);
KMETHOD QGraphicsItem_collidesWithPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		Qt::ItemSelectionMode mode = Int_to(Qt::ItemSelectionMode, sfp[2]);
		bool ret_v = qp->collidesWithPath(path, mode);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//Array<QGraphicsItem> QGraphicsItem.collidingItems(int mode);
KMETHOD QGraphicsItem_collidingItems(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		Qt::ItemSelectionMode mode = Int_to(Qt::ItemSelectionMode, sfp[1]);
		QList<QGraphicsItem*> ret_v = qp->collidingItems(mode);
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
	

//QGraphicsItem QGraphicsItem.commonAncestorItem(QGraphicsItem other);
KMETHOD QGraphicsItem_commonAncestorItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  other = RawPtr_to(const QGraphicsItem*, sfp[1]);
		QGraphicsItem* ret_v = qp->commonAncestorItem(other);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual boolean QGraphicsItem.contains(QPointF point);
KMETHOD QGraphicsItem_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		bool ret_v = qp->contains(point);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QCursor QGraphicsItem.getCursor();
KMETHOD QGraphicsItem_getCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QCursor ret_v = qp->cursor();
		QCursor *ret_v_ = new QCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QVariant QGraphicsItem.getData(int key);
KMETHOD QGraphicsItem_getData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		int key = Int_to(int, sfp[1]);
		QVariant ret_v = qp->data(key);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTransform QGraphicsItem.deviceTransform(QTransform viewportTransform);
KMETHOD QGraphicsItem_deviceTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QTransform  viewportTransform = *RawPtr_to(const QTransform *, sfp[1]);
		QTransform ret_v = qp->deviceTransform(viewportTransform);
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QGraphicsItem.effectiveOpacity();
KMETHOD QGraphicsItem_effectiveOpacity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->effectiveOpacity();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QGraphicsItem.ensureVisible(QRectF rect, int xmargin, int ymargin);
KMETHOD QGraphicsItem_ensureVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		int xmargin = Int_to(int, sfp[2]);
		int ymargin = Int_to(int, sfp[3]);
		qp->ensureVisible(rect, xmargin, ymargin);
	}
	RETURNvoid_();
}

/*
//void QGraphicsItem.ensureVisible(float x, float y, float w, float h, int xmargin, int ymargin);
KMETHOD QGraphicsItem_ensureVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
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
//boolean QGraphicsItem.getFiltersChildEvents();
KMETHOD QGraphicsItem_getFiltersChildEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->filtersChildEvents();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QGraphicsItemGraphicsItemFlags QGraphicsItem.getFlags();
KMETHOD QGraphicsItem_getFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsItem::GraphicsItemFlags ret_v = qp->flags();
		QGraphicsItem::GraphicsItemFlags *ret_v_ = new QGraphicsItem::GraphicsItemFlags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsItem QGraphicsItem.focusItem();
KMETHOD QGraphicsItem_focusItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsItem* ret_v = qp->focusItem();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsItem QGraphicsItem.getFocusProxy();
KMETHOD QGraphicsItem_getFocusProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsItem* ret_v = qp->focusProxy();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsItem.grabKeyboard();
KMETHOD QGraphicsItem_grabKeyboard(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qp->grabKeyboard();
	}
	RETURNvoid_();
}

//void QGraphicsItem.grabMouse();
KMETHOD QGraphicsItem_grabMouse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qp->grabMouse();
	}
	RETURNvoid_();
}

//QGraphicsEffect QGraphicsItem.getGraphicsEffect();
KMETHOD QGraphicsItem_getGraphicsEffect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsEffect* ret_v = qp->graphicsEffect();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsEffect*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsItemGroup QGraphicsItem.getGroup();
KMETHOD QGraphicsItem_getGroup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsItemGroup* ret_v = qp->group();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsItemGroup*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGraphicsItem.hasCursor();
KMETHOD QGraphicsItem_hasCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasCursor();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsItem.hasFocus();
KMETHOD QGraphicsItem_hasFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasFocus();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGraphicsItem.hide();
KMETHOD QGraphicsItem_hide(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qp->hide();
	}
	RETURNvoid_();
}

//QtInputMethodHints QGraphicsItem.getInputMethodHints();
KMETHOD QGraphicsItem_getInputMethodHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		Qt::InputMethodHints ret_v = qp->inputMethodHints();
		Qt::InputMethodHints *ret_v_ = new Qt::InputMethodHints(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGraphicsItem.isActive();
KMETHOD QGraphicsItem_isActive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isActive();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsItem.isAncestorOf(QGraphicsItem child);
KMETHOD QGraphicsItem_isAncestorOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  child = RawPtr_to(const QGraphicsItem*, sfp[1]);
		bool ret_v = qp->isAncestorOf(child);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsItem.isBlockedByModalPanel(QGraphicsItem blockingPanel);
KMETHOD QGraphicsItem_isBlockedByModalPanel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsItem**  blockingPanel = RawPtr_to(QGraphicsItem**, sfp[1]);
		bool ret_v = qp->isBlockedByModalPanel(blockingPanel);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsItem.isClipped();
KMETHOD QGraphicsItem_isClipped(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isClipped();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsItem.isEnabled();
KMETHOD QGraphicsItem_isEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsItem.isObscured();
KMETHOD QGraphicsItem_isObscured(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isObscured();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QGraphicsItem.isObscured(float x, float y, float w, float h);
KMETHOD QGraphicsItem_isObscured(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		bool ret_v = qp->isObscured(x, y, w, h);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//boolean QGraphicsItem.isObscured(QRectF rect);
KMETHOD QGraphicsItem_isObscured(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		bool ret_v = qp->isObscured(rect);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//@Virtual boolean QGraphicsItem.isObscuredBy(QGraphicsItem item);
KMETHOD QGraphicsItem_isObscuredBy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		bool ret_v = qp->isObscuredBy(item);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsItem.isPanel();
KMETHOD QGraphicsItem_isPanel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isPanel();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsItem.isSelected();
KMETHOD QGraphicsItem_isSelected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSelected();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsItem.isUnderMouse();
KMETHOD QGraphicsItem_isUnderMouse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isUnderMouse();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsItem.isVisible();
KMETHOD QGraphicsItem_isVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isVisible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsItem.isVisibleTo(QGraphicsItem parent);
KMETHOD QGraphicsItem_isVisibleTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  parent = RawPtr_to(const QGraphicsItem*, sfp[1]);
		bool ret_v = qp->isVisibleTo(parent);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsItem.isWidget();
KMETHOD QGraphicsItem_isWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isWidget();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsItem.isWindow();
KMETHOD QGraphicsItem_isWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isWindow();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QTransform QGraphicsItem.itemTransform(QGraphicsItem other, boolean ok);
KMETHOD QGraphicsItem_itemTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  other = RawPtr_to(const QGraphicsItem*, sfp[1]);
		bool* ok = Boolean_to(bool*, sfp[2]);
		QTransform ret_v = qp->itemTransform(other, ok);
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QGraphicsItem.mapFromItem(QGraphicsItem item, QPointF point);
KMETHOD QGraphicsItem_mapFromItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[2]);
		QPointF ret_v = qp->mapFromItem(item, point);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPolygonF QGraphicsItem.mapFromItem(QGraphicsItem item, QRectF rect);
KMETHOD QGraphicsItem_mapFromItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[2]);
		QPolygonF ret_v = qp->mapFromItem(item, rect);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPolygonF QGraphicsItem.mapFromItem(QGraphicsItem item, QPolygonF polygon);
KMETHOD QGraphicsItem_mapFromItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		const QPolygonF  polygon = *RawPtr_to(const QPolygonF *, sfp[2]);
		QPolygonF ret_v = qp->mapFromItem(item, polygon);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPainterPath QGraphicsItem.mapFromItem(QGraphicsItem item, QPainterPath path);
KMETHOD QGraphicsItem_mapFromItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[2]);
		QPainterPath ret_v = qp->mapFromItem(item, path);
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPolygonF QGraphicsItem.mapFromItem(QGraphicsItem item, float x, float y, float w, float h);
KMETHOD QGraphicsItem_mapFromItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		qreal x = Float_to(qreal, sfp[2]);
		qreal y = Float_to(qreal, sfp[3]);
		qreal w = Float_to(qreal, sfp[4]);
		qreal h = Float_to(qreal, sfp[5]);
		QPolygonF ret_v = qp->mapFromItem(item, x, y, w, h);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPointF QGraphicsItem.mapFromItem(QGraphicsItem item, float x, float y);
KMETHOD QGraphicsItem_mapFromItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		qreal x = Float_to(qreal, sfp[2]);
		qreal y = Float_to(qreal, sfp[3]);
		QPointF ret_v = qp->mapFromItem(item, x, y);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QPointF QGraphicsItem.mapFromParent(QPointF point);
KMETHOD QGraphicsItem_mapFromParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		QPointF ret_v = qp->mapFromParent(point);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPolygonF QGraphicsItem.mapFromParent(QRectF rect);
KMETHOD QGraphicsItem_mapFromParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		QPolygonF ret_v = qp->mapFromParent(rect);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPolygonF QGraphicsItem.mapFromParent(QPolygonF polygon);
KMETHOD QGraphicsItem_mapFromParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QPolygonF  polygon = *RawPtr_to(const QPolygonF *, sfp[1]);
		QPolygonF ret_v = qp->mapFromParent(polygon);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPainterPath QGraphicsItem.mapFromParent(QPainterPath path);
KMETHOD QGraphicsItem_mapFromParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		QPainterPath ret_v = qp->mapFromParent(path);
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPolygonF QGraphicsItem.mapFromParent(float x, float y, float w, float h);
KMETHOD QGraphicsItem_mapFromParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		QPolygonF ret_v = qp->mapFromParent(x, y, w, h);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPointF QGraphicsItem.mapFromParent(float x, float y);
KMETHOD QGraphicsItem_mapFromParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		QPointF ret_v = qp->mapFromParent(x, y);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QPointF QGraphicsItem.mapFromScene(QPointF point);
KMETHOD QGraphicsItem_mapFromScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		QPointF ret_v = qp->mapFromScene(point);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPolygonF QGraphicsItem.mapFromScene(QRectF rect);
KMETHOD QGraphicsItem_mapFromScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		QPolygonF ret_v = qp->mapFromScene(rect);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPolygonF QGraphicsItem.mapFromScene(QPolygonF polygon);
KMETHOD QGraphicsItem_mapFromScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QPolygonF  polygon = *RawPtr_to(const QPolygonF *, sfp[1]);
		QPolygonF ret_v = qp->mapFromScene(polygon);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPainterPath QGraphicsItem.mapFromScene(QPainterPath path);
KMETHOD QGraphicsItem_mapFromScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
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
//QPolygonF QGraphicsItem.mapFromScene(float x, float y, float w, float h);
KMETHOD QGraphicsItem_mapFromScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		QPolygonF ret_v = qp->mapFromScene(x, y, w, h);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPointF QGraphicsItem.mapFromScene(float x, float y);
KMETHOD QGraphicsItem_mapFromScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		QPointF ret_v = qp->mapFromScene(x, y);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QRectF QGraphicsItem.mapRectFromItem(QGraphicsItem item, QRectF rect);
KMETHOD QGraphicsItem_mapRectFromItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[2]);
		QRectF ret_v = qp->mapRectFromItem(item, rect);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRectF QGraphicsItem.mapRectFromItem(QGraphicsItem item, float x, float y, float w, float h);
KMETHOD QGraphicsItem_mapRectFromItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		qreal x = Float_to(qreal, sfp[2]);
		qreal y = Float_to(qreal, sfp[3]);
		qreal w = Float_to(qreal, sfp[4]);
		qreal h = Float_to(qreal, sfp[5]);
		QRectF ret_v = qp->mapRectFromItem(item, x, y, w, h);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QRectF QGraphicsItem.mapRectFromParent(QRectF rect);
KMETHOD QGraphicsItem_mapRectFromParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		QRectF ret_v = qp->mapRectFromParent(rect);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRectF QGraphicsItem.mapRectFromParent(float x, float y, float w, float h);
KMETHOD QGraphicsItem_mapRectFromParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		QRectF ret_v = qp->mapRectFromParent(x, y, w, h);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QRectF QGraphicsItem.mapRectFromScene(QRectF rect);
KMETHOD QGraphicsItem_mapRectFromScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		QRectF ret_v = qp->mapRectFromScene(rect);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRectF QGraphicsItem.mapRectFromScene(float x, float y, float w, float h);
KMETHOD QGraphicsItem_mapRectFromScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		QRectF ret_v = qp->mapRectFromScene(x, y, w, h);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QRectF QGraphicsItem.mapRectToItem(QGraphicsItem item, QRectF rect);
KMETHOD QGraphicsItem_mapRectToItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[2]);
		QRectF ret_v = qp->mapRectToItem(item, rect);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRectF QGraphicsItem.mapRectToItem(QGraphicsItem item, float x, float y, float w, float h);
KMETHOD QGraphicsItem_mapRectToItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		qreal x = Float_to(qreal, sfp[2]);
		qreal y = Float_to(qreal, sfp[3]);
		qreal w = Float_to(qreal, sfp[4]);
		qreal h = Float_to(qreal, sfp[5]);
		QRectF ret_v = qp->mapRectToItem(item, x, y, w, h);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QRectF QGraphicsItem.mapRectToParent(QRectF rect);
KMETHOD QGraphicsItem_mapRectToParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		QRectF ret_v = qp->mapRectToParent(rect);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRectF QGraphicsItem.mapRectToParent(float x, float y, float w, float h);
KMETHOD QGraphicsItem_mapRectToParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		QRectF ret_v = qp->mapRectToParent(x, y, w, h);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QRectF QGraphicsItem.mapRectToScene(QRectF rect);
KMETHOD QGraphicsItem_mapRectToScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		QRectF ret_v = qp->mapRectToScene(rect);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRectF QGraphicsItem.mapRectToScene(float x, float y, float w, float h);
KMETHOD QGraphicsItem_mapRectToScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		QRectF ret_v = qp->mapRectToScene(x, y, w, h);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QPointF QGraphicsItem.mapToItem(QGraphicsItem item, QPointF point);
KMETHOD QGraphicsItem_mapToItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[2]);
		QPointF ret_v = qp->mapToItem(item, point);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPolygonF QGraphicsItem.mapToItem(QGraphicsItem item, QRectF rect);
KMETHOD QGraphicsItem_mapToItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[2]);
		QPolygonF ret_v = qp->mapToItem(item, rect);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPolygonF QGraphicsItem.mapToItem(QGraphicsItem item, QPolygonF polygon);
KMETHOD QGraphicsItem_mapToItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		const QPolygonF  polygon = *RawPtr_to(const QPolygonF *, sfp[2]);
		QPolygonF ret_v = qp->mapToItem(item, polygon);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPainterPath QGraphicsItem.mapToItem(QGraphicsItem item, QPainterPath path);
KMETHOD QGraphicsItem_mapToItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[2]);
		QPainterPath ret_v = qp->mapToItem(item, path);
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPolygonF QGraphicsItem.mapToItem(QGraphicsItem item, float x, float y, float w, float h);
KMETHOD QGraphicsItem_mapToItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		qreal x = Float_to(qreal, sfp[2]);
		qreal y = Float_to(qreal, sfp[3]);
		qreal w = Float_to(qreal, sfp[4]);
		qreal h = Float_to(qreal, sfp[5]);
		QPolygonF ret_v = qp->mapToItem(item, x, y, w, h);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPointF QGraphicsItem.mapToItem(QGraphicsItem item, float x, float y);
KMETHOD QGraphicsItem_mapToItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		qreal x = Float_to(qreal, sfp[2]);
		qreal y = Float_to(qreal, sfp[3]);
		QPointF ret_v = qp->mapToItem(item, x, y);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QPointF QGraphicsItem.mapToParent(QPointF point);
KMETHOD QGraphicsItem_mapToParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		QPointF ret_v = qp->mapToParent(point);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPolygonF QGraphicsItem.mapToParent(QRectF rect);
KMETHOD QGraphicsItem_mapToParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		QPolygonF ret_v = qp->mapToParent(rect);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPolygonF QGraphicsItem.mapToParent(QPolygonF polygon);
KMETHOD QGraphicsItem_mapToParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QPolygonF  polygon = *RawPtr_to(const QPolygonF *, sfp[1]);
		QPolygonF ret_v = qp->mapToParent(polygon);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPainterPath QGraphicsItem.mapToParent(QPainterPath path);
KMETHOD QGraphicsItem_mapToParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QPainterPath  path = *RawPtr_to(const QPainterPath *, sfp[1]);
		QPainterPath ret_v = qp->mapToParent(path);
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPolygonF QGraphicsItem.mapToParent(float x, float y, float w, float h);
KMETHOD QGraphicsItem_mapToParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		QPolygonF ret_v = qp->mapToParent(x, y, w, h);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPointF QGraphicsItem.mapToParent(float x, float y);
KMETHOD QGraphicsItem_mapToParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		QPointF ret_v = qp->mapToParent(x, y);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QPointF QGraphicsItem.mapToScene(QPointF point);
KMETHOD QGraphicsItem_mapToScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		QPointF ret_v = qp->mapToScene(point);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPolygonF QGraphicsItem.mapToScene(QRectF rect);
KMETHOD QGraphicsItem_mapToScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
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
//QPolygonF QGraphicsItem.mapToScene(QPolygonF polygon);
KMETHOD QGraphicsItem_mapToScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QPolygonF  polygon = *RawPtr_to(const QPolygonF *, sfp[1]);
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
//QPainterPath QGraphicsItem.mapToScene(QPainterPath path);
KMETHOD QGraphicsItem_mapToScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
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
//QPolygonF QGraphicsItem.mapToScene(float x, float y, float w, float h);
KMETHOD QGraphicsItem_mapToScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		QPolygonF ret_v = qp->mapToScene(x, y, w, h);
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPointF QGraphicsItem.mapToScene(float x, float y);
KMETHOD QGraphicsItem_mapToScene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		QPointF ret_v = qp->mapToScene(x, y);
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//void QGraphicsItem.moveBy(float dx, float dy);
KMETHOD QGraphicsItem_moveBy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal dx = Float_to(qreal, sfp[1]);
		qreal dy = Float_to(qreal, sfp[2]);
		qp->moveBy(dx, dy);
	}
	RETURNvoid_();
}

//float QGraphicsItem.getOpacity();
KMETHOD QGraphicsItem_getOpacity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->opacity();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//@Virtual QPainterPath QGraphicsItem.opaqueArea();
KMETHOD QGraphicsItem_opaqueArea(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QPainterPath ret_v = qp->opaqueArea();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QGraphicsItem.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
KMETHOD QGraphicsItem_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionGraphicsItem*  option = RawPtr_to(const QStyleOptionGraphicsItem*, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->paint(painter, option, widget);
	}
	RETURNvoid_();
}

//QGraphicsItem QGraphicsItem.panel();
KMETHOD QGraphicsItem_panel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsItem* ret_v = qp->panel();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGraphicsItem.getPanelModality();
KMETHOD QGraphicsItem_getPanelModality(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsItem::PanelModality ret_v = qp->panelModality();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QGraphicsItem QGraphicsItem.getParentItem();
KMETHOD QGraphicsItem_getParentItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsItem* ret_v = qp->parentItem();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsObject QGraphicsItem.parentObject();
KMETHOD QGraphicsItem_parentObject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsObject* ret_v = qp->parentObject();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsWidget QGraphicsItem.parentWidget();
KMETHOD QGraphicsItem_parentWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsWidget* ret_v = qp->parentWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QGraphicsItem.getPos();
KMETHOD QGraphicsItem_getPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->pos();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsItem.resetTransform();
KMETHOD QGraphicsItem_resetTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qp->resetTransform();
	}
	RETURNvoid_();
}

//float QGraphicsItem.getRotation();
KMETHOD QGraphicsItem_getRotation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->rotation();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QGraphicsItem.getScale();
KMETHOD QGraphicsItem_getScale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->scale();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QGraphicsScene QGraphicsItem.scene();
KMETHOD QGraphicsItem_scene(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsScene* ret_v = qp->scene();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsScene*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRectF QGraphicsItem.sceneBoundingRect();
KMETHOD QGraphicsItem_sceneBoundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->sceneBoundingRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QGraphicsItem.scenePos();
KMETHOD QGraphicsItem_scenePos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->scenePos();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTransform QGraphicsItem.sceneTransform();
KMETHOD QGraphicsItem_sceneTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QTransform ret_v = qp->sceneTransform();
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsItem.scroll(float dx, float dy, QRectF rect);
KMETHOD QGraphicsItem_scroll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal dx = Float_to(qreal, sfp[1]);
		qreal dy = Float_to(qreal, sfp[2]);
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[3]);
		qp->scroll(dx, dy, rect);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setAcceptDrops(boolean on);
KMETHOD QGraphicsItem_setAcceptDrops(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool on = Boolean_to(bool, sfp[1]);
		qp->setAcceptDrops(on);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setAcceptHoverEvents(boolean enabled);
KMETHOD QGraphicsItem_setAcceptHoverEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setAcceptHoverEvents(enabled);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setAcceptTouchEvents(boolean enabled);
KMETHOD QGraphicsItem_setAcceptTouchEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setAcceptTouchEvents(enabled);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setAcceptedMouseButtons(QtMouseButtons buttons);
KMETHOD QGraphicsItem_setAcceptedMouseButtons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		initFlag(buttons, Qt::MouseButtons, sfp[1]);
		qp->setAcceptedMouseButtons(buttons);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setActive(boolean active);
KMETHOD QGraphicsItem_setActive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool active = Boolean_to(bool, sfp[1]);
		qp->setActive(active);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setBoundingRegionGranularity(float granularity);
KMETHOD QGraphicsItem_setBoundingRegionGranularity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal granularity = Float_to(qreal, sfp[1]);
		qp->setBoundingRegionGranularity(granularity);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setCacheMode(int mode, QSize logicalCacheSize);
KMETHOD QGraphicsItem_setCacheMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsItem::CacheMode mode = Int_to(QGraphicsItem::CacheMode, sfp[1]);
		const QSize  logicalCacheSize = *RawPtr_to(const QSize *, sfp[2]);
		qp->setCacheMode(mode, logicalCacheSize);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setCursor(QCursor cursor);
KMETHOD QGraphicsItem_setCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QCursor  cursor = *RawPtr_to(const QCursor *, sfp[1]);
		qp->setCursor(cursor);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setData(int key, QVariant value);
KMETHOD QGraphicsItem_setData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		int key = Int_to(int, sfp[1]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[2]);
		qp->setData(key, value);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setEnabled(boolean enabled);
KMETHOD QGraphicsItem_setEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setEnabled(enabled);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setFiltersChildEvents(boolean enabled);
KMETHOD QGraphicsItem_setFiltersChildEvents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setFiltersChildEvents(enabled);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setFlag(int flag, boolean enabled);
KMETHOD QGraphicsItem_setFlag(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsItem::GraphicsItemFlag flag = Int_to(QGraphicsItem::GraphicsItemFlag, sfp[1]);
		bool enabled = Boolean_to(bool, sfp[2]);
		qp->setFlag(flag, enabled);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setFlags(QGraphicsItemGraphicsItemFlags flags);
KMETHOD QGraphicsItem_setFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		initFlag(flags, QGraphicsItem::GraphicsItemFlags, sfp[1]);
		qp->setFlags(flags);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setFocus(int focusReason);
KMETHOD QGraphicsItem_setFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		Qt::FocusReason focusReason = Int_to(Qt::FocusReason, sfp[1]);
		qp->setFocus(focusReason);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setFocusProxy(QGraphicsItem item);
KMETHOD QGraphicsItem_setFocusProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsItem*  item = RawPtr_to(QGraphicsItem*, sfp[1]);
		qp->setFocusProxy(item);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setGraphicsEffect(QGraphicsEffect effect);
KMETHOD QGraphicsItem_setGraphicsEffect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsEffect*  effect = RawPtr_to(QGraphicsEffect*, sfp[1]);
		qp->setGraphicsEffect(effect);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setGroup(QGraphicsItemGroup group);
KMETHOD QGraphicsItem_setGroup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsItemGroup*  group = RawPtr_to(QGraphicsItemGroup*, sfp[1]);
		qp->setGroup(group);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setInputMethodHints(QtInputMethodHints hints);
KMETHOD QGraphicsItem_setInputMethodHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		initFlag(hints, Qt::InputMethodHints, sfp[1]);
		qp->setInputMethodHints(hints);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setOpacity(float opacity);
KMETHOD QGraphicsItem_setOpacity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal opacity = Float_to(qreal, sfp[1]);
		qp->setOpacity(opacity);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setPanelModality(int panelModality);
KMETHOD QGraphicsItem_setPanelModality(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsItem::PanelModality panelModality = Int_to(QGraphicsItem::PanelModality, sfp[1]);
		qp->setPanelModality(panelModality);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setParentItem(QGraphicsItem new_Parent);
KMETHOD QGraphicsItem_setParentItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsItem*  new_Parent = RawPtr_to(QGraphicsItem*, sfp[1]);
		qp->setParentItem(new_Parent);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setPos(QPointF pos);
KMETHOD QGraphicsItem_setPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QPointF  pos = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setPos(pos);
	}
	RETURNvoid_();
}

/*
//void QGraphicsItem.setPos(float x, float y);
KMETHOD QGraphicsItem_setPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qp->setPos(x, y);
	}
	RETURNvoid_();
}
*/
//void QGraphicsItem.setRotation(float angle);
KMETHOD QGraphicsItem_setRotation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal angle = Float_to(qreal, sfp[1]);
		qp->setRotation(angle);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setScale(float factor);
KMETHOD QGraphicsItem_setScale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal factor = Float_to(qreal, sfp[1]);
		qp->setScale(factor);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setSelected(boolean selected);
KMETHOD QGraphicsItem_setSelected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool selected = Boolean_to(bool, sfp[1]);
		qp->setSelected(selected);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setToolTip(String toolTip);
KMETHOD QGraphicsItem_setToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QString toolTip = String_to(const QString, sfp[1]);
		qp->setToolTip(toolTip);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setTransform(QTransform matrix, boolean combine);
KMETHOD QGraphicsItem_setTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QTransform  matrix = *RawPtr_to(const QTransform *, sfp[1]);
		bool combine = Boolean_to(bool, sfp[2]);
		qp->setTransform(matrix, combine);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setTransformOriginPoint(QPointF origin);
KMETHOD QGraphicsItem_setTransformOriginPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QPointF  origin = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setTransformOriginPoint(origin);
	}
	RETURNvoid_();
}

/*
//void QGraphicsItem.setTransformOriginPoint(float x, float y);
KMETHOD QGraphicsItem_setTransformOriginPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qp->setTransformOriginPoint(x, y);
	}
	RETURNvoid_();
}
*/
//void QGraphicsItem.setTransformations(Array<QGraphicsTransform> transformations);
KMETHOD QGraphicsItem_setTransformations(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QGraphicsTransform*> transformations;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			transformations.append((QGraphicsTransform*)p->rawptr);
		}
		qp->setTransformations(transformations);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setVisible(boolean visible);
KMETHOD QGraphicsItem_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setVisible(visible);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setX(float x);
KMETHOD QGraphicsItem_setX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qp->setX(x);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setY(float y);
KMETHOD QGraphicsItem_setY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal y = Float_to(qreal, sfp[1]);
		qp->setY(y);
	}
	RETURNvoid_();
}

//void QGraphicsItem.setZValue(float z);
KMETHOD QGraphicsItem_setZValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal z = Float_to(qreal, sfp[1]);
		qp->setZValue(z);
	}
	RETURNvoid_();
}

//@Virtual QPainterPath QGraphicsItem.shape();
KMETHOD QGraphicsItem_shape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QPainterPath ret_v = qp->shape();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsItem.show();
KMETHOD QGraphicsItem_show(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qp->show();
	}
	RETURNvoid_();
}

//void QGraphicsItem.stackBefore(QGraphicsItem sibling);
KMETHOD QGraphicsItem_stackBefore(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  sibling = RawPtr_to(const QGraphicsItem*, sfp[1]);
		qp->stackBefore(sibling);
	}
	RETURNvoid_();
}

//QGraphicsObject QGraphicsItem.toGraphicsObject();
KMETHOD QGraphicsItem_toGraphicsObject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsObject* ret_v = qp->toGraphicsObject();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QGraphicsObject QGraphicsItem.toGraphicsObject();
KMETHOD QGraphicsItem_toGraphicsObject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QGraphicsObject* ret_v = qp->toGraphicsObject();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//String QGraphicsItem.getToolTip();
KMETHOD QGraphicsItem_getToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QString ret_v = qp->toolTip();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsItem QGraphicsItem.topLevelItem();
KMETHOD QGraphicsItem_topLevelItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsItem* ret_v = qp->topLevelItem();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsWidget QGraphicsItem.topLevelWidget();
KMETHOD QGraphicsItem_topLevelWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsWidget* ret_v = qp->topLevelWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTransform QGraphicsItem.getTransform();
KMETHOD QGraphicsItem_getTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QTransform ret_v = qp->transform();
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPointF QGraphicsItem.getTransformOriginPoint();
KMETHOD QGraphicsItem_getTransformOriginPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->transformOriginPoint();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QGraphicsTransform> QGraphicsItem.getTransformations();
KMETHOD QGraphicsItem_getTransformations(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QList<QGraphicsTransform*> ret_v = qp->transformations();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QGraphicsTransform"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//@Virtual int QGraphicsItem.type();
KMETHOD QGraphicsItem_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		int ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGraphicsItem.ungrabKeyboard();
KMETHOD QGraphicsItem_ungrabKeyboard(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qp->ungrabKeyboard();
	}
	RETURNvoid_();
}

//void QGraphicsItem.ungrabMouse();
KMETHOD QGraphicsItem_ungrabMouse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qp->ungrabMouse();
	}
	RETURNvoid_();
}

//void QGraphicsItem.unsetCursor();
KMETHOD QGraphicsItem_unsetCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qp->unsetCursor();
	}
	RETURNvoid_();
}

//void QGraphicsItem.update(QRectF rect);
KMETHOD QGraphicsItem_update(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		qp->update(rect);
	}
	RETURNvoid_();
}

/*
//void QGraphicsItem.update(float x, float y, float width, float height);
KMETHOD QGraphicsItem_update(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal width = Float_to(qreal, sfp[3]);
		qreal height = Float_to(qreal, sfp[4]);
		qp->update(x, y, width, height);
	}
	RETURNvoid_();
}
*/
//QGraphicsWidget QGraphicsItem.window();
KMETHOD QGraphicsItem_window(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		QGraphicsWidget* ret_v = qp->window();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QGraphicsItem.getX();
KMETHOD QGraphicsItem_getX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->x();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QGraphicsItem.getY();
KMETHOD QGraphicsItem_getY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->y();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QGraphicsItem.getZValue();
KMETHOD QGraphicsItem_getZValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *  qp = RawPtr_to(QGraphicsItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->zValue();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//Array<String> QGraphicsItem.parents();
KMETHOD QGraphicsItem_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem *qp = RawPtr_to(QGraphicsItem*, sfp[0]);
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

DummyQGraphicsItem::DummyQGraphicsItem()
{
	self = NULL;
	context_menu_event_func = NULL;
	drag_enter_event_func = NULL;
	drag_leave_event_func = NULL;
	drag_move_event_func = NULL;
	drop_event_func = NULL;
	focus_in_event_func = NULL;
	focus_out_event_func = NULL;
	hover_enter_event_func = NULL;
	hover_leave_event_func = NULL;
	hover_move_event_func = NULL;
	input_method_event_func = NULL;
	key_press_event_func = NULL;
	key_release_event_func = NULL;
	mouse_double_click_event_func = NULL;
	mouse_move_event_func = NULL;
	mouse_press_event_func = NULL;
	mouse_release_event_func = NULL;
	scene_event_func = NULL;
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
	event_map->insert(map<string, knh_Func_t *>::value_type("hover-enter-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("hover-leave-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("hover-move-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("input-method-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("key-press-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("key-release-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("mouse-double-click-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("mouse-move-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("mouse-press-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("mouse-release-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("scene-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("wheel-event", NULL));
}

void DummyQGraphicsItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsItem::self = ptr;
}

bool DummyQGraphicsItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	case QEvent::ContextMenu:
		ret = contextMenuEventDummy(dynamic_cast<QGraphicsSceneContextMenuEvent*>(event));
		break;
	case QEvent::DragEnter:
		ret = dragEnterEventDummy(dynamic_cast<QGraphicsSceneDragDropEvent*>(event));
		break;
	case QEvent::DragLeave:
		ret = dragLeaveEventDummy(dynamic_cast<QGraphicsSceneDragDropEvent*>(event));
		break;
	case QEvent::DragMove:
		ret = dragMoveEventDummy(dynamic_cast<QGraphicsSceneDragDropEvent*>(event));
		break;
	case QEvent::Drop:
		ret = dropEventDummy(dynamic_cast<QGraphicsSceneDragDropEvent*>(event));
		break;
	case QEvent::FocusIn:
		ret = focusInEventDummy(dynamic_cast<QFocusEvent*>(event));
		break;
	case QEvent::FocusOut:
		ret = focusOutEventDummy(dynamic_cast<QFocusEvent*>(event));
		break;
	case QEvent::HoverEnter:
		ret = hoverEnterEventDummy(dynamic_cast<QGraphicsSceneHoverEvent*>(event));
		break;
	case QEvent::HoverLeave:
		ret = hoverLeaveEventDummy(dynamic_cast<QGraphicsSceneHoverEvent*>(event));
		break;
	case QEvent::HoverMove:
		ret = hoverMoveEventDummy(dynamic_cast<QGraphicsSceneHoverEvent*>(event));
		break;
	case QEvent::InputMethod:
		ret = inputMethodEventDummy(dynamic_cast<QInputMethodEvent*>(event));
		break;
	case QEvent::KeyPress:
		ret = keyPressEventDummy(dynamic_cast<QKeyEvent*>(event));
		break;
	case QEvent::KeyRelease:
		ret = keyReleaseEventDummy(dynamic_cast<QKeyEvent*>(event));
		break;
	case QEvent::MouseButtonDblClick:
		ret = mouseDoubleClickEventDummy(dynamic_cast<QGraphicsSceneMouseEvent*>(event));
		break;
	case QEvent::MouseMove:
		ret = mouseMoveEventDummy(dynamic_cast<QGraphicsSceneMouseEvent*>(event));
		break;
	case QEvent::MouseButtonPress:
		ret = mousePressEventDummy(dynamic_cast<QGraphicsSceneMouseEvent*>(event));
		break;
	case QEvent::MouseButtonRelease:
		ret = mouseReleaseEventDummy(dynamic_cast<QGraphicsSceneMouseEvent*>(event));
		break;
		ret = sceneEventDummy(dynamic_cast<QEvent*>(event));
		break;
	case QEvent::Wheel:
		ret = wheelEventDummy(dynamic_cast<QGraphicsSceneWheelEvent*>(event));
		break;
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQGraphicsItem::contextMenuEventDummy(QGraphicsSceneContextMenuEvent* event)
{
	if (context_menu_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneContextMenuEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, context_menu_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::dragEnterEventDummy(QGraphicsSceneDragDropEvent* event)
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

bool DummyQGraphicsItem::dragLeaveEventDummy(QGraphicsSceneDragDropEvent* event)
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

bool DummyQGraphicsItem::dragMoveEventDummy(QGraphicsSceneDragDropEvent* event)
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

bool DummyQGraphicsItem::dropEventDummy(QGraphicsSceneDragDropEvent* event)
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

bool DummyQGraphicsItem::focusInEventDummy(QFocusEvent* event)
{
	if (focus_in_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QFocusEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, focus_in_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::focusOutEventDummy(QFocusEvent* event)
{
	if (focus_out_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QFocusEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, focus_out_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::hoverEnterEventDummy(QGraphicsSceneHoverEvent* event)
{
	if (hover_enter_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneHoverEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, hover_enter_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::hoverLeaveEventDummy(QGraphicsSceneHoverEvent* event)
{
	if (hover_leave_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneHoverEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, hover_leave_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::hoverMoveEventDummy(QGraphicsSceneHoverEvent* event)
{
	if (hover_move_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneHoverEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, hover_move_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::inputMethodEventDummy(QInputMethodEvent* event)
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

bool DummyQGraphicsItem::keyPressEventDummy(QKeyEvent* event)
{
	if (key_press_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QKeyEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, key_press_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::keyReleaseEventDummy(QKeyEvent* event)
{
	if (key_release_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QKeyEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, key_release_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::mouseDoubleClickEventDummy(QGraphicsSceneMouseEvent* event)
{
	if (mouse_double_click_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneMouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, mouse_double_click_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::mouseMoveEventDummy(QGraphicsSceneMouseEvent* event)
{
	if (mouse_move_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneMouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, mouse_move_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::mousePressEventDummy(QGraphicsSceneMouseEvent* event)
{
	if (mouse_press_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneMouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, mouse_press_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::mouseReleaseEventDummy(QGraphicsSceneMouseEvent* event)
{
	if (mouse_release_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneMouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, mouse_release_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::sceneEventDummy(QEvent* event)
{
	if (scene_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, scene_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::wheelEventDummy(QGraphicsSceneWheelEvent* event)
{
	if (wheel_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneWheelEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, wheel_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsItem::event_map->bigin();
	if ((itr = DummyQGraphicsItem::event_map->find(str)) == DummyQGraphicsItem::event_map->end()) {
		bool ret = false;
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
		hover_enter_event_func = (*event_map)["hover-enter-event"];
		hover_leave_event_func = (*event_map)["hover-leave-event"];
		hover_move_event_func = (*event_map)["hover-move-event"];
		input_method_event_func = (*event_map)["input-method-event"];
		key_press_event_func = (*event_map)["key-press-event"];
		key_release_event_func = (*event_map)["key-release-event"];
		mouse_double_click_event_func = (*event_map)["mouse-double-click-event"];
		mouse_move_event_func = (*event_map)["mouse-move-event"];
		mouse_press_event_func = (*event_map)["mouse-press-event"];
		mouse_release_event_func = (*event_map)["mouse-release-event"];
		scene_event_func = (*event_map)["scene-event"];
		wheel_event_func = (*event_map)["wheel-event"];
		return true;
	}
}

bool DummyQGraphicsItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsItem::slot_map->bigin();
	if ((itr = DummyQGraphicsItem::slot_map->find(str)) == DummyQGraphicsItem::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQGraphicsItem::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 19;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, context_menu_event_func);
	KNH_ADDNNREF(ctx, drag_enter_event_func);
	KNH_ADDNNREF(ctx, drag_leave_event_func);
	KNH_ADDNNREF(ctx, drag_move_event_func);
	KNH_ADDNNREF(ctx, drop_event_func);
	KNH_ADDNNREF(ctx, focus_in_event_func);
	KNH_ADDNNREF(ctx, focus_out_event_func);
	KNH_ADDNNREF(ctx, hover_enter_event_func);
	KNH_ADDNNREF(ctx, hover_leave_event_func);
	KNH_ADDNNREF(ctx, hover_move_event_func);
	KNH_ADDNNREF(ctx, input_method_event_func);
	KNH_ADDNNREF(ctx, key_press_event_func);
	KNH_ADDNNREF(ctx, key_release_event_func);
	KNH_ADDNNREF(ctx, mouse_double_click_event_func);
	KNH_ADDNNREF(ctx, mouse_move_event_func);
	KNH_ADDNNREF(ctx, mouse_press_event_func);
	KNH_ADDNNREF(ctx, mouse_release_event_func);
	KNH_ADDNNREF(ctx, scene_event_func);
	KNH_ADDNNREF(ctx, wheel_event_func);

	KNH_SIZEREF(ctx);

}

void DummyQGraphicsItem::connection(QObject *o)
{
	QGraphicsItem *p = dynamic_cast<QGraphicsItem*>(o);
	if (p != NULL) {
	}
}

KQGraphicsItem::KQGraphicsItem(QGraphicsItem* parent) : QGraphicsItem(parent)
{
	self = NULL;
	dummy = new DummyQGraphicsItem();
}

KMETHOD QGraphicsItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsItem *qp = RawPtr_to(KQGraphicsItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsItem *qp = RawPtr_to(KQGraphicsItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsItem *qp = (KQGraphicsItem *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGraphicsItem *qp = (KQGraphicsItem *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsItem::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QGraphicsItemConstInt[] = {
	{"NoCache", QGraphicsItem::NoCache},
	{"ItemCoordinateCache", QGraphicsItem::ItemCoordinateCache},
	{"DeviceCoordinateCache", QGraphicsItem::DeviceCoordinateCache},
	{"ItemEnabledChange", QGraphicsItem::ItemEnabledChange},
	{"ItemEnabledHasChanged", QGraphicsItem::ItemEnabledHasChanged},
	{"ItemMatrixChange", QGraphicsItem::ItemMatrixChange},
	{"ItemPositionChange", QGraphicsItem::ItemPositionChange},
	{"ItemPositionHasChanged", QGraphicsItem::ItemPositionHasChanged},
	{"ItemTransformChange", QGraphicsItem::ItemTransformChange},
	{"ItemTransformHasChanged", QGraphicsItem::ItemTransformHasChanged},
	{"ItemRotationChange", QGraphicsItem::ItemRotationChange},
	{"ItemRotationHasChanged", QGraphicsItem::ItemRotationHasChanged},
	{"ItemScaleChange", QGraphicsItem::ItemScaleChange},
	{"ItemScaleHasChanged", QGraphicsItem::ItemScaleHasChanged},
	{"ItemTransformOriginPointChange", QGraphicsItem::ItemTransformOriginPointChange},
	{"ItemTransformOriginPointHasChanged", QGraphicsItem::ItemTransformOriginPointHasChanged},
	{"ItemSelectedChange", QGraphicsItem::ItemSelectedChange},
	{"ItemSelectedHasChanged", QGraphicsItem::ItemSelectedHasChanged},
	{"ItemVisibleChange", QGraphicsItem::ItemVisibleChange},
	{"ItemVisibleHasChanged", QGraphicsItem::ItemVisibleHasChanged},
	{"ItemParentChange", QGraphicsItem::ItemParentChange},
	{"ItemParentHasChanged", QGraphicsItem::ItemParentHasChanged},
	{"ItemChildAddedChange", QGraphicsItem::ItemChildAddedChange},
	{"ItemChildRemovedChange", QGraphicsItem::ItemChildRemovedChange},
	{"ItemSceneChange", QGraphicsItem::ItemSceneChange},
	{"ItemSceneHasChanged", QGraphicsItem::ItemSceneHasChanged},
	{"ItemCursorChange", QGraphicsItem::ItemCursorChange},
	{"ItemCursorHasChanged", QGraphicsItem::ItemCursorHasChanged},
	{"ItemToolTipChange", QGraphicsItem::ItemToolTipChange},
	{"ItemToolTipHasChanged", QGraphicsItem::ItemToolTipHasChanged},
	{"ItemFlagsChange", QGraphicsItem::ItemFlagsChange},
	{"ItemFlagsHaveChanged", QGraphicsItem::ItemFlagsHaveChanged},
	{"ItemZValueChange", QGraphicsItem::ItemZValueChange},
	{"ItemZValueHasChanged", QGraphicsItem::ItemZValueHasChanged},
	{"ItemOpacityChange", QGraphicsItem::ItemOpacityChange},
	{"ItemOpacityHasChanged", QGraphicsItem::ItemOpacityHasChanged},
	{"ItemScenePositionHasChanged", QGraphicsItem::ItemScenePositionHasChanged},
	{"ItemIsMovable", QGraphicsItem::ItemIsMovable},
	{"ItemIsSelectable", QGraphicsItem::ItemIsSelectable},
	{"ItemIsFocusable", QGraphicsItem::ItemIsFocusable},
	{"ItemClipsToShape", QGraphicsItem::ItemClipsToShape},
	{"ItemClipsChildrenToShape", QGraphicsItem::ItemClipsChildrenToShape},
	{"ItemIgnoresTransformations", QGraphicsItem::ItemIgnoresTransformations},
	{"ItemIgnoresParentOpacity", QGraphicsItem::ItemIgnoresParentOpacity},
	{"ItemDoesntPropagateOpacityToChildren", QGraphicsItem::ItemDoesntPropagateOpacityToChildren},
	{"ItemStacksBehindParent", QGraphicsItem::ItemStacksBehindParent},
	{"ItemUsesExtendedStyleOption", QGraphicsItem::ItemUsesExtendedStyleOption},
	{"ItemHasNoContents", QGraphicsItem::ItemHasNoContents},
	{"ItemSendsGeometryChanges", QGraphicsItem::ItemSendsGeometryChanges},
	{"ItemAcceptsInputMethod", QGraphicsItem::ItemAcceptsInputMethod},
	{"ItemNegativeZStacksBehindParent", QGraphicsItem::ItemNegativeZStacksBehindParent},
	{"ItemIsPanel", QGraphicsItem::ItemIsPanel},
	{"ItemSendsScenePositionChanges", QGraphicsItem::ItemSendsScenePositionChanges},
	{"NonModal", QGraphicsItem::NonModal},
	{"PanelModal", QGraphicsItem::PanelModal},
	{"SceneModal", QGraphicsItem::SceneModal},
	{NULL, 0}
};

DEFAPI(void) constQGraphicsItem(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QGraphicsItemConstInt);
}


DEFAPI(void) defQGraphicsItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsItem";
	cdef->free = QGraphicsItem_free;
	cdef->reftrace = QGraphicsItem_reftrace;
	cdef->compareTo = QGraphicsItem_compareTo;
}

//## QGraphicsItemGraphicsItemFlags QGraphicsItemGraphicsItemFlags.new(int value);
KMETHOD QGraphicsItemGraphicsItemFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsItem::GraphicsItemFlag i = Int_to(QGraphicsItem::GraphicsItemFlag, sfp[1]);
	QGraphicsItem::GraphicsItemFlags *ret_v = new QGraphicsItem::GraphicsItemFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QGraphicsItemGraphicsItemFlags QGraphicsItemGraphicsItemFlags.and(int mask);
KMETHOD QGraphicsItemGraphicsItemFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsItem::GraphicsItemFlags *qp = RawPtr_to(QGraphicsItem::GraphicsItemFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QGraphicsItem::GraphicsItemFlags ret = ((*qp) & i);
		QGraphicsItem::GraphicsItemFlags *ret_ = new QGraphicsItem::GraphicsItemFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGraphicsItemGraphicsItemFlags QGraphicsItemGraphicsItemFlags.iand(QGraphicsItem::QGraphicsItemGraphicsItemFlags other);
KMETHOD QGraphicsItemGraphicsItemFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsItem::GraphicsItemFlags *qp = RawPtr_to(QGraphicsItem::GraphicsItemFlags*, sfp[0]);
	if (qp != NULL) {
		QGraphicsItem::GraphicsItemFlags *other = RawPtr_to(QGraphicsItem::GraphicsItemFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGraphicsItemGraphicsItemFlags QGraphicsItemGraphicsItemFlags.or(QGraphicsItemGraphicsItemFlags f);
KMETHOD QGraphicsItemGraphicsItemFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem::GraphicsItemFlags *qp = RawPtr_to(QGraphicsItem::GraphicsItemFlags*, sfp[0]);
	if (qp != NULL) {
		QGraphicsItem::GraphicsItemFlags *f = RawPtr_to(QGraphicsItem::GraphicsItemFlags*, sfp[1]);
		QGraphicsItem::GraphicsItemFlags ret = ((*qp) | (*f));
		QGraphicsItem::GraphicsItemFlags *ret_ = new QGraphicsItem::GraphicsItemFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGraphicsItemGraphicsItemFlags QGraphicsItemGraphicsItemFlags.ior(QGraphicsItem::QGraphicsItemGraphicsItemFlags other);
KMETHOD QGraphicsItemGraphicsItemFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsItem::GraphicsItemFlags *qp = RawPtr_to(QGraphicsItem::GraphicsItemFlags*, sfp[0]);
	if (qp != NULL) {
		QGraphicsItem::GraphicsItemFlags *other = RawPtr_to(QGraphicsItem::GraphicsItemFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGraphicsItemGraphicsItemFlags QGraphicsItemGraphicsItemFlags.xor(QGraphicsItemGraphicsItemFlags f);
KMETHOD QGraphicsItemGraphicsItemFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem::GraphicsItemFlags *qp = RawPtr_to(QGraphicsItem::GraphicsItemFlags*, sfp[0]);
	if (qp != NULL) {
		QGraphicsItem::GraphicsItemFlags *f = RawPtr_to(QGraphicsItem::GraphicsItemFlags*, sfp[1]);
		QGraphicsItem::GraphicsItemFlags ret = ((*qp) ^ (*f));
		QGraphicsItem::GraphicsItemFlags *ret_ = new QGraphicsItem::GraphicsItemFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGraphicsItemGraphicsItemFlags QGraphicsItemGraphicsItemFlags.ixor(QGraphicsItem::QGraphicsItemGraphicsItemFlags other);
KMETHOD QGraphicsItemGraphicsItemFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsItem::GraphicsItemFlags *qp = RawPtr_to(QGraphicsItem::GraphicsItemFlags*, sfp[0]);
	if (qp != NULL) {
		QGraphicsItem::GraphicsItemFlags *other = RawPtr_to(QGraphicsItem::GraphicsItemFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QGraphicsItemGraphicsItemFlags.testFlag(int flag);
KMETHOD QGraphicsItemGraphicsItemFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsItem::GraphicsItemFlags *qp = RawPtr_to(QGraphicsItem::GraphicsItemFlags *, sfp[0]);
	if (qp != NULL) {
		QGraphicsItem::GraphicsItemFlag flag = Int_to(QGraphicsItem::GraphicsItemFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QGraphicsItemGraphicsItemFlags.value();
KMETHOD QGraphicsItemGraphicsItemFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGraphicsItem::GraphicsItemFlags *qp = RawPtr_to(QGraphicsItem::GraphicsItemFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QGraphicsItemGraphicsItemFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QGraphicsItem::GraphicsItemFlags *qp = (QGraphicsItem::GraphicsItemFlags *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QGraphicsItemGraphicsItemFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QGraphicsItem::GraphicsItemFlags *qp = (QGraphicsItem::GraphicsItemFlags *)p->rawptr;
		(void)qp;
	}
}

static int QGraphicsItemGraphicsItemFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QGraphicsItem::GraphicsItemFlags*)p1->rawptr);
//		int v2 = int(*(QGraphicsItem::GraphicsItemFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QGraphicsItem::GraphicsItemFlags v1 = *(QGraphicsItem::GraphicsItemFlags*)p1->rawptr;
		QGraphicsItem::GraphicsItemFlags v2 = *(QGraphicsItem::GraphicsItemFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQGraphicsItemGraphicsItemFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsItemGraphicsItemFlags";
	cdef->free = QGraphicsItemGraphicsItemFlags_free;
	cdef->reftrace = QGraphicsItemGraphicsItemFlags_reftrace;
	cdef->compareTo = QGraphicsItemGraphicsItemFlags_compareTo;
}

