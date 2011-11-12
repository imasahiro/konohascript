//@Virtual @Override QRectF QGraphicsWidget.boundingRect();
KMETHOD QGraphicsWidget_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->boundingRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QGraphicsWidget.getContentsMargins(float left, float top, float right, float bottom);
KMETHOD QGraphicsWidget_getContentsMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		qreal*  left = RawPtr_to(qreal*, sfp[1]);
		qreal*  top = RawPtr_to(qreal*, sfp[2]);
		qreal*  right = RawPtr_to(qreal*, sfp[3]);
		qreal*  bottom = RawPtr_to(qreal*, sfp[4]);
		qp->getContentsMargins(left, top, right, bottom);
	}
	RETURNvoid_();
}

//@Virtual @Override void QGraphicsWidget.setGeometry(QRectF rect);
KMETHOD QGraphicsWidget_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		qp->setGeometry(rect);
	}
	RETURNvoid_();
}

//@Virtual @Override QPainterPath QGraphicsWidget.shape();
KMETHOD QGraphicsWidget_shape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QPainterPath ret_v = qp->shape();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QGraphicsWidget.type();
KMETHOD QGraphicsWidget_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		int ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QGraphicsWidget QGraphicsWidget.new(QGraphicsItem parent, QtWindowFlags wFlags);
KMETHOD QGraphicsWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[1]);
	initFlag(wFlags, Qt::WindowFlags, sfp[2]);
	KQGraphicsWidget *ret_v = new KQGraphicsWidget(parent, wFlags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//Array<QAction> QGraphicsWidget.actions();
KMETHOD QGraphicsWidget_actions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QList<QAction*> ret_v = qp->actions();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QAction"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//void QGraphicsWidget.addActions(Array<QAction> actions);
KMETHOD QGraphicsWidget_addActions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QAction*> actions;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			actions.append((QAction*)p->rawptr);
		}
		qp->addActions(actions);
	}
	RETURNvoid_();
}

//void QGraphicsWidget.adjustSize();
KMETHOD QGraphicsWidget_adjustSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		qp->adjustSize();
	}
	RETURNvoid_();
}

//boolean QGraphicsWidget.getAutoFillBackground();
KMETHOD QGraphicsWidget_getAutoFillBackground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		bool ret_v = qp->autoFillBackground();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QGraphicsWidget.getFocusPolicy();
KMETHOD QGraphicsWidget_getFocusPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		Qt::FocusPolicy ret_v = qp->focusPolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QGraphicsWidget QGraphicsWidget.focusWidget();
KMETHOD QGraphicsWidget_focusWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QGraphicsWidget* ret_v = qp->focusWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFont QGraphicsWidget.getFont();
KMETHOD QGraphicsWidget_getFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QFont ret_v = qp->font();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsWidget.getWindowFrameMargins(float left, float top, float right, float bottom);
KMETHOD QGraphicsWidget_getWindowFrameMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		qreal*  left = RawPtr_to(qreal*, sfp[1]);
		qreal*  top = RawPtr_to(qreal*, sfp[2]);
		qreal*  right = RawPtr_to(qreal*, sfp[3]);
		qreal*  bottom = RawPtr_to(qreal*, sfp[4]);
		qp->getWindowFrameMargins(left, top, right, bottom);
	}
	RETURNvoid_();
}

//int QGraphicsWidget.grabShortcut(QKeySequence sequence, int context);
KMETHOD QGraphicsWidget_grabShortcut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		const QKeySequence  sequence = *RawPtr_to(const QKeySequence *, sfp[1]);
		Qt::ShortcutContext context = Int_to(Qt::ShortcutContext, sfp[2]);
		int ret_v = qp->grabShortcut(sequence, context);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGraphicsWidget.insertAction(QAction before, QAction action);
KMETHOD QGraphicsWidget_insertAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QAction*  before = RawPtr_to(QAction*, sfp[1]);
		QAction*  action = RawPtr_to(QAction*, sfp[2]);
		qp->insertAction(before, action);
	}
	RETURNvoid_();
}

//void QGraphicsWidget.insertActions(QAction before, Array<QAction> actions);
KMETHOD QGraphicsWidget_insertActions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QAction*  before = RawPtr_to(QAction*, sfp[1]);
		knh_Array_t *a = sfp[2].a;
		int asize = knh_Array_size(a);
		QList<QAction*> actions;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			actions.append((QAction*)p->rawptr);
		}
		qp->insertActions(before, actions);
	}
	RETURNvoid_();
}

//boolean QGraphicsWidget.isActiveWindow();
KMETHOD QGraphicsWidget_isActiveWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isActiveWindow();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QGraphicsLayout QGraphicsWidget.getLayout();
KMETHOD QGraphicsWidget_getLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QGraphicsLayout* ret_v = qp->layout();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsLayout*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGraphicsWidget.getLayoutDirection();
KMETHOD QGraphicsWidget_getLayoutDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		Qt::LayoutDirection ret_v = qp->layoutDirection();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual void QGraphicsWidget.paintWindowFrame(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
KMETHOD QGraphicsWidget_paintWindowFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionGraphicsItem*  option = RawPtr_to(const QStyleOptionGraphicsItem*, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->paintWindowFrame(painter, option, widget);
	}
	RETURNvoid_();
}

//QPalette QGraphicsWidget.getPalette();
KMETHOD QGraphicsWidget_getPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QPalette ret_v = qp->palette();
		QPalette *ret_v_ = new QPalette(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRectF QGraphicsWidget.rect();
KMETHOD QGraphicsWidget_rect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->rect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsWidget.releaseShortcut(int id);
KMETHOD QGraphicsWidget_releaseShortcut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		int id = Int_to(int, sfp[1]);
		qp->releaseShortcut(id);
	}
	RETURNvoid_();
}

//void QGraphicsWidget.removeAction(QAction action);
KMETHOD QGraphicsWidget_removeAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QAction*  action = RawPtr_to(QAction*, sfp[1]);
		qp->removeAction(action);
	}
	RETURNvoid_();
}

//void QGraphicsWidget.resize(QSizeF size);
KMETHOD QGraphicsWidget_resize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		const QSizeF  size = *RawPtr_to(const QSizeF *, sfp[1]);
		qp->resize(size);
	}
	RETURNvoid_();
}

/*
//void QGraphicsWidget.resize(float w, float h);
KMETHOD QGraphicsWidget_resize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		qreal w = Float_to(qreal, sfp[1]);
		qreal h = Float_to(qreal, sfp[2]);
		qp->resize(w, h);
	}
	RETURNvoid_();
}
*/
//void QGraphicsWidget.setAttribute(int attribute, boolean on);
KMETHOD QGraphicsWidget_setAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		Qt::WidgetAttribute attribute = Int_to(Qt::WidgetAttribute, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		qp->setAttribute(attribute, on);
	}
	RETURNvoid_();
}

//void QGraphicsWidget.setAutoFillBackground(boolean enabled);
KMETHOD QGraphicsWidget_setAutoFillBackground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setAutoFillBackground(enabled);
	}
	RETURNvoid_();
}

//void QGraphicsWidget.setContentsMargins(float left, float top, float right, float bottom);
KMETHOD QGraphicsWidget_setContentsMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		qreal left = Float_to(qreal, sfp[1]);
		qreal top = Float_to(qreal, sfp[2]);
		qreal right = Float_to(qreal, sfp[3]);
		qreal bottom = Float_to(qreal, sfp[4]);
		qp->setContentsMargins(left, top, right, bottom);
	}
	RETURNvoid_();
}

//void QGraphicsWidget.setFocusPolicy(int policy);
KMETHOD QGraphicsWidget_setFocusPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		Qt::FocusPolicy policy = Int_to(Qt::FocusPolicy, sfp[1]);
		qp->setFocusPolicy(policy);
	}
	RETURNvoid_();
}

//void QGraphicsWidget.setFont(QFont font);
KMETHOD QGraphicsWidget_setFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
		qp->setFont(font);
	}
	RETURNvoid_();
}

/*
//void QGraphicsWidget.setGeometry(float x, float y, float w, float h);
KMETHOD QGraphicsWidget_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal w = Float_to(qreal, sfp[3]);
		qreal h = Float_to(qreal, sfp[4]);
		qp->setGeometry(x, y, w, h);
	}
	RETURNvoid_();
}
*/
//void QGraphicsWidget.setLayout(QGraphicsLayout layout);
KMETHOD QGraphicsWidget_setLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QGraphicsLayout*  layout = RawPtr_to(QGraphicsLayout*, sfp[1]);
		qp->setLayout(layout);
	}
	RETURNvoid_();
}

//void QGraphicsWidget.setLayoutDirection(int direction);
KMETHOD QGraphicsWidget_setLayoutDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		Qt::LayoutDirection direction = Int_to(Qt::LayoutDirection, sfp[1]);
		qp->setLayoutDirection(direction);
	}
	RETURNvoid_();
}

//void QGraphicsWidget.setPalette(QPalette palette);
KMETHOD QGraphicsWidget_setPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		const QPalette  palette = *RawPtr_to(const QPalette *, sfp[1]);
		qp->setPalette(palette);
	}
	RETURNvoid_();
}

//void QGraphicsWidget.setShortcutAutoRepeat(int id, boolean enabled);
KMETHOD QGraphicsWidget_setShortcutAutoRepeat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		int id = Int_to(int, sfp[1]);
		bool enabled = Boolean_to(bool, sfp[2]);
		qp->setShortcutAutoRepeat(id, enabled);
	}
	RETURNvoid_();
}

//void QGraphicsWidget.setShortcutEnabled(int id, boolean enabled);
KMETHOD QGraphicsWidget_setShortcutEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		int id = Int_to(int, sfp[1]);
		bool enabled = Boolean_to(bool, sfp[2]);
		qp->setShortcutEnabled(id, enabled);
	}
	RETURNvoid_();
}

//void QGraphicsWidget.setStyle(QStyle style);
KMETHOD QGraphicsWidget_setStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QStyle*  style = RawPtr_to(QStyle*, sfp[1]);
		qp->setStyle(style);
	}
	RETURNvoid_();
}

//void QGraphicsWidget.setWindowFlags(QtWindowFlags wFlags);
KMETHOD QGraphicsWidget_setWindowFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		initFlag(wFlags, Qt::WindowFlags, sfp[1]);
		qp->setWindowFlags(wFlags);
	}
	RETURNvoid_();
}

//void QGraphicsWidget.setWindowFrameMargins(float left, float top, float right, float bottom);
KMETHOD QGraphicsWidget_setWindowFrameMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		qreal left = Float_to(qreal, sfp[1]);
		qreal top = Float_to(qreal, sfp[2]);
		qreal right = Float_to(qreal, sfp[3]);
		qreal bottom = Float_to(qreal, sfp[4]);
		qp->setWindowFrameMargins(left, top, right, bottom);
	}
	RETURNvoid_();
}

//void QGraphicsWidget.setWindowTitle(String title);
KMETHOD QGraphicsWidget_setWindowTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		const QString title = String_to(const QString, sfp[1]);
		qp->setWindowTitle(title);
	}
	RETURNvoid_();
}

//QSizeF QGraphicsWidget.size();
KMETHOD QGraphicsWidget_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QSizeF ret_v = qp->size();
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QStyle QGraphicsWidget.getStyle();
KMETHOD QGraphicsWidget_getStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QStyle* ret_v = qp->style();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QStyle*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGraphicsWidget.testAttribute(int attribute);
KMETHOD QGraphicsWidget_testAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		Qt::WidgetAttribute attribute = Int_to(Qt::WidgetAttribute, sfp[1]);
		bool ret_v = qp->testAttribute(attribute);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGraphicsWidget.unsetLayoutDirection();
KMETHOD QGraphicsWidget_unsetLayoutDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		qp->unsetLayoutDirection();
	}
	RETURNvoid_();
}

//void QGraphicsWidget.unsetWindowFrameMargins();
KMETHOD QGraphicsWidget_unsetWindowFrameMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		qp->unsetWindowFrameMargins();
	}
	RETURNvoid_();
}

//QtWindowFlags QGraphicsWidget.getWindowFlags();
KMETHOD QGraphicsWidget_getWindowFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		Qt::WindowFlags ret_v = qp->windowFlags();
		Qt::WindowFlags *ret_v_ = new Qt::WindowFlags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRectF QGraphicsWidget.windowFrameGeometry();
KMETHOD QGraphicsWidget_windowFrameGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->windowFrameGeometry();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRectF QGraphicsWidget.windowFrameRect();
KMETHOD QGraphicsWidget_windowFrameRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->windowFrameRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QGraphicsWidget.getWindowTitle();
KMETHOD QGraphicsWidget_getWindowTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		QString ret_v = qp->windowTitle();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGraphicsWidget.windowType();
KMETHOD QGraphicsWidget_windowType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		Qt::WindowType ret_v = qp->windowType();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGraphicsWidget.setTabOrder(QGraphicsWidget first, QGraphicsWidget second);
KMETHOD QGraphicsWidget_setTabOrder(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QGraphicsWidget*  first = RawPtr_to(QGraphicsWidget*, sfp[1]);
		QGraphicsWidget*  second = RawPtr_to(QGraphicsWidget*, sfp[2]);
		QGraphicsWidget::setTabOrder(first, second);
	}
	RETURNvoid_();
}

//boolean QGraphicsWidget.close();
KMETHOD QGraphicsWidget_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWidget *  qp = RawPtr_to(QGraphicsWidget *, sfp[0]);
	if (qp) {
		bool ret_v = qp->close();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

// //@Virtual void QGraphicsWidget.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
// KMETHOD QGraphicsWidget_paint(CTX ctx, knh_sfp_t *sfp _RIX)
// {
// 	(void)ctx;
// 	KQGraphicsWidget *  qp = RawPtr_to(KQGraphicsWidget *, sfp[0]);
// 	if (qp) {
// 		if (qp->dummy->paint_func != NULL) {
// 			knh_Func_invoke(ctx, qp->dummy->paint_func, sfp, 4);
// 		}
// 	}
// 	RETURNvoid_();
// }

//@Virtual void QGraphicsWidget.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
KMETHOD QGraphicsWidget_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsWidget *  qp = RawPtr_to(KQGraphicsWidget *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionGraphicsItem*  option = RawPtr_to(const QStyleOptionGraphicsItem*, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->paint(painter, option, widget);
	}
	RETURNvoid_();
}

void KQGraphicsWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	if (dummy->paint_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QPainter, painter);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_RawPtr_t *p2 = new_QRawPtr(lctx, QStyleOptionGraphicsItem, option);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		knh_RawPtr_t *p3 = new_QRawPtr(lctx, QWidget, widget);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+4].o, UPCAST(p3));
		knh_Func_invoke(lctx, dummy->paint_func, lsfp, 4);
	}
}

DummyQGraphicsWidget::DummyQGraphicsWidget()
{
	self = NULL;
	change_event_func = NULL;
	close_event_func = NULL;
	grab_keyboard_event_func = NULL;
	grab_mouse_event_func = NULL;
	hide_event_func = NULL;
	move_event_func = NULL;
	polish_event_func = NULL;
	resize_event_func = NULL;
	show_event_func = NULL;
	ungrab_keyboard_event_func = NULL;
	ungrab_mouse_event_func = NULL;
	window_frame_event_func = NULL;
	geometry_changed_func = NULL;
	paint_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	event_map->insert(map<string, knh_Func_t *>::value_type("change-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("close-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("grab-keyboard-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("grab-mouse-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("hide-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("move-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("polish-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("resize-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("show-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("ungrab-keyboard-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("ungrab-mouse-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("window-frame-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("paint", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("geometry-changed", NULL));
}

void DummyQGraphicsWidget::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsWidget::self = ptr;
	DummyQGraphicsObject::setSelf(ptr);
	DummyQGraphicsLayoutItem::setSelf(ptr);
}

bool DummyQGraphicsWidget::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
		ret = changeEventDummy(dynamic_cast<QEvent*>(event));
		break;
	case QEvent::Close:
		ret = closeEventDummy(dynamic_cast<QCloseEvent*>(event));
		break;
	case QEvent::GrabKeyboard:
		ret = grabKeyboardEventDummy(dynamic_cast<QEvent*>(event));
		break;
	case QEvent::GrabMouse:
		ret = grabMouseEventDummy(dynamic_cast<QEvent*>(event));
		break;
	case QEvent::Hide:
		ret = hideEventDummy(dynamic_cast<QHideEvent*>(event));
		break;
	case QEvent::GraphicsSceneMove:
		ret = moveEventDummy(dynamic_cast<QGraphicsSceneMoveEvent*>(event));
		break;
	case QEvent::GraphicsSceneResize:
		ret = resizeEventDummy(dynamic_cast<QGraphicsSceneResizeEvent*>(event));
		break;
	case QEvent::Show:
		ret = showEventDummy(dynamic_cast<QShowEvent*>(event));
		break;
	case QEvent::UngrabKeyboard:
		ret = ungrabKeyboardEventDummy(dynamic_cast<QEvent*>(event));
		break;
	case QEvent::UngrabMouse:
		ret = ungrabMouseEventDummy(dynamic_cast<QEvent*>(event));
		break;
		ret = windowFrameEventDummy(dynamic_cast<QEvent*>(event));
		break;
	default:
		ret = DummyQGraphicsObject::eventDispatcher(event);
		if (ret) break;
		ret = DummyQGraphicsLayoutItem::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsWidget::changeEventDummy(QEvent* event)
{
	if (change_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, change_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsWidget::closeEventDummy(QCloseEvent* event)
{
	if (close_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QCloseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, close_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsWidget::grabKeyboardEventDummy(QEvent* event)
{
	if (grab_keyboard_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, grab_keyboard_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsWidget::grabMouseEventDummy(QEvent* event)
{
	if (grab_mouse_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, grab_mouse_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsWidget::hideEventDummy(QHideEvent* event)
{
	if (hide_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QHideEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, hide_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsWidget::moveEventDummy(QGraphicsSceneMoveEvent* event)
{
	if (move_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneMoveEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, move_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsWidget::polishEventDummy()
{
	if (polish_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, polish_event_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQGraphicsWidget::resizeEventDummy(QGraphicsSceneResizeEvent* event)
{
	if (resize_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QGraphicsSceneResizeEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, resize_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsWidget::showEventDummy(QShowEvent* event)
{
	if (show_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QShowEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, show_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsWidget::ungrabKeyboardEventDummy(QEvent* event)
{
	if (ungrab_keyboard_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, ungrab_keyboard_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsWidget::ungrabMouseEventDummy(QEvent* event)
{
	if (ungrab_mouse_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, ungrab_mouse_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsWidget::windowFrameEventDummy(QEvent* event)
{
	if (window_frame_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, window_frame_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQGraphicsWidget::geometryChangedSlot()
{
	if (geometry_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, geometry_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQGraphicsWidget::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsWidget::event_map->bigin();
	if ((itr = DummyQGraphicsWidget::event_map->find(str)) == DummyQGraphicsWidget::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsObject::addEvent(callback_func, str);
		if (ret) return true;
		ret = DummyQGraphicsLayoutItem::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		change_event_func = (*event_map)["change-event"];
		close_event_func = (*event_map)["close-event"];
		grab_keyboard_event_func = (*event_map)["grab-keyboard-event"];
		grab_mouse_event_func = (*event_map)["grab-mouse-event"];
		hide_event_func = (*event_map)["hide-event"];
		move_event_func = (*event_map)["move-event"];
		polish_event_func = (*event_map)["polish-event"];
		resize_event_func = (*event_map)["resize-event"];
		show_event_func = (*event_map)["show-event"];
		ungrab_keyboard_event_func = (*event_map)["ungrab-keyboard-event"];
		ungrab_mouse_event_func = (*event_map)["ungrab-mouse-event"];
		window_frame_event_func = (*event_map)["window-frame-event"];
		paint_func = (*event_map)["paint"];
		return true;
	}
}

bool DummyQGraphicsWidget::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsWidget::slot_map->bigin();
	if ((itr = DummyQGraphicsWidget::slot_map->find(str)) == DummyQGraphicsWidget::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsObject::signalConnect(callback_func, str);
		if (ret) return true;
		ret = DummyQGraphicsLayoutItem::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		geometry_changed_func = (*slot_map)["geometry-changed"];
		return true;
	}
}

knh_Object_t** DummyQGraphicsWidget::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsWidget::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 13;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, change_event_func);
	KNH_ADDNNREF(ctx, close_event_func);
	KNH_ADDNNREF(ctx, grab_keyboard_event_func);
	KNH_ADDNNREF(ctx, grab_mouse_event_func);
	KNH_ADDNNREF(ctx, hide_event_func);
	KNH_ADDNNREF(ctx, move_event_func);
	KNH_ADDNNREF(ctx, polish_event_func);
	KNH_ADDNNREF(ctx, resize_event_func);
	KNH_ADDNNREF(ctx, show_event_func);
	KNH_ADDNNREF(ctx, ungrab_keyboard_event_func);
	KNH_ADDNNREF(ctx, ungrab_mouse_event_func);
	KNH_ADDNNREF(ctx, window_frame_event_func);
	KNH_ADDNNREF(ctx, geometry_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQGraphicsObject::reftrace(ctx, p, tail_);
	tail_ = DummyQGraphicsLayoutItem::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGraphicsWidget::connection(QObject *o)
{
	QGraphicsWidget *p = dynamic_cast<QGraphicsWidget*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(geometryChanged()), this, SLOT(geometryChangedSlot()));
	}
	DummyQGraphicsObject::connection(o);
	DummyQGraphicsLayoutItem::connection(o);
}

KQGraphicsWidget::KQGraphicsWidget(QGraphicsItem* parent, Qt::WindowFlags wFlags) : QGraphicsWidget(parent, wFlags)
{
	self = NULL;
	dummy = new DummyQGraphicsWidget();
	dummy->connection((QObject*)this);
}

KMETHOD QGraphicsWidget_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsWidget *qp = RawPtr_to(KQGraphicsWidget *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsWidget]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsWidget]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsWidget_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsWidget *qp = RawPtr_to(KQGraphicsWidget *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsWidget]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsWidget]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsWidget_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsWidget *qp = (KQGraphicsWidget *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsWidget_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGraphicsWidget *qp = (KQGraphicsWidget *)p->rawptr;
//		KQGraphicsWidget *qp = static_cast<KQGraphicsWidget*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsWidget_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsWidget::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGraphicsWidget::sceneEvent(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGraphicsWidget::sceneEvent(event);
		return false;
	}
//	QGraphicsWidget::sceneEvent(event);
	return true;
}



DEFAPI(void) defQGraphicsWidget(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsWidget";
	cdef->free = QGraphicsWidget_free;
	cdef->reftrace = QGraphicsWidget_reftrace;
	cdef->compareTo = QGraphicsWidget_compareTo;
}


