//@Virtual @Override QPaintEngine QWidget.paintEngine();
KMETHOD QWidget_paintEngine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QPaintEngine* ret_v = qp->paintEngine();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPaintEngine*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QWidget.new(QWidget parent, int f);
KMETHOD QWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	Qt::WindowFlags f = Int_to(Qt::WindowFlags, sfp[2]);
	KQWidget *ret_v = new KQWidget(parent, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QWidget.getAcceptDrops();
KMETHOD QWidget_getAcceptDrops(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->acceptDrops();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QWidget.getAccessibleDescription();
KMETHOD QWidget_getAccessibleDescription(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->accessibleDescription();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWidget.getAccessibleName();
KMETHOD QWidget_getAccessibleName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->accessibleName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QAction> QWidget.actions();
KMETHOD QWidget_actions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QList<QAction*>ret_v = qp->actions();
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
	

//void QWidget.activateWindow();
KMETHOD QWidget_activateWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->activateWindow();
	}
	RETURNvoid_();
}

////void QWidget.addAction(QAction action);
KMETHOD QWidget_addAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QAction*  action = RawPtr_to(QAction*, sfp[1]);
		qp->addAction(action);
	}
	RETURNvoid_();
}

////void QWidget.addActions(Array<QAction> actions);
KMETHOD QWidget_addActions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
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

//void QWidget.adjustSize();
KMETHOD QWidget_adjustSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->adjustSize();
	}
	RETURNvoid_();
}

//boolean QWidget.getAutoFillBackground();
KMETHOD QWidget_getAutoFillBackground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->autoFillBackground();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QWidget.getBackgroundRole();
KMETHOD QWidget_getBackgroundRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QPalette::ColorRole ret_v = qp->backgroundRole();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QSize QWidget.getBaseSize();
KMETHOD QWidget_getBaseSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->baseSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QWidget.childAt(int x, int y);
KMETHOD QWidget_childAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		QWidget* ret_v = qp->childAt(x, y);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QWidget QWidget.childAt(QPoint p);
KMETHOD QWidget_childAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QPoint  p = *RawPtr_to(const QPoint *, sfp[1]);
		QWidget* ret_v = qp->childAt(p);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QRect QWidget.childrenRect();
KMETHOD QWidget_childrenRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QRect ret_v = qp->childrenRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRegion QWidget.childrenRegion();
KMETHOD QWidget_childrenRegion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QRegion ret_v = qp->childrenRegion();
		QRegion *ret_v_ = new QRegion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWidget.clearFocus();
KMETHOD QWidget_clearFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->clearFocus();
	}
	RETURNvoid_();
}

//void QWidget.clearMask();
KMETHOD QWidget_clearMask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->clearMask();
	}
	RETURNvoid_();
}

//QMargins QWidget.contentsMargins();
KMETHOD QWidget_contentsMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QMargins ret_v = qp->contentsMargins();
		QMargins *ret_v_ = new QMargins(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QWidget.contentsRect();
KMETHOD QWidget_contentsRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QRect ret_v = qp->contentsRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWidget.getContextMenuPolicy();
KMETHOD QWidget_getContextMenuPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::ContextMenuPolicy ret_v = qp->contextMenuPolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QCursor QWidget.getCursor();
KMETHOD QWidget_getCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QCursor ret_v = qp->cursor();
		QCursor *ret_v_ = new QCursor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWidget.ensurePolished();
KMETHOD QWidget_ensurePolished(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->ensurePolished();
	}
	RETURNvoid_();
}

//int QWidget.getFocusPolicy();
KMETHOD QWidget_getFocusPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::FocusPolicy ret_v = qp->focusPolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWidget QWidget.getFocusProxy();
KMETHOD QWidget_getFocusProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->focusProxy();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QWidget.focusWidget();
KMETHOD QWidget_focusWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->focusWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFont QWidget.getFont();
KMETHOD QWidget_getFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QFont ret_v = qp->font();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFontInfo QWidget.fontInfo();
KMETHOD QWidget_fontInfo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QFontInfo ret_v = qp->fontInfo();
		QFontInfo *ret_v_ = new QFontInfo(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFontMetrics QWidget.fontMetrics();
KMETHOD QWidget_fontMetrics(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QFontMetrics ret_v = qp->fontMetrics();
		QFontMetrics *ret_v_ = new QFontMetrics(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWidget.getForegroundRole();
KMETHOD QWidget_getForegroundRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QPalette::ColorRole ret_v = qp->foregroundRole();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QRect QWidget.frameGeometry();
KMETHOD QWidget_frameGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QRect ret_v = qp->frameGeometry();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSize QWidget.frameSize();
KMETHOD QWidget_frameSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->frameSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QWidget.getGeometry();
KMETHOD QWidget_getGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QRect ret_v = qp->geometry();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWidget.getContentsMargins(int left, int top, int right, int bottom);
KMETHOD QWidget_getContentsMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int* left = Int_to(int*, sfp[1]);
		int* top = Int_to(int*, sfp[2]);
		int* right = Int_to(int*, sfp[3]);
		int* bottom = Int_to(int*, sfp[4]);
		qp->getContentsMargins(left, top, right, bottom);
	}
	RETURNvoid_();
}

//void QWidget.grabGesture(int gesture, int flags);
KMETHOD QWidget_grabGesture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::GestureType gesture = Int_to(Qt::GestureType, sfp[1]);
		Qt::GestureFlags flags = Int_to(Qt::GestureFlags, sfp[2]);
		qp->grabGesture(gesture, flags);
	}
	RETURNvoid_();
}

//void QWidget.grabKeyboard();
KMETHOD QWidget_grabKeyboard(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->grabKeyboard();
	}
	RETURNvoid_();
}

//void QWidget.grabMouse();
KMETHOD QWidget_grabMouse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->grabMouse();
	}
	RETURNvoid_();
}

/*
//void QWidget.grabMouse(QCursor cursor);
KMETHOD QWidget_grabMouse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QCursor  cursor = *RawPtr_to(const QCursor *, sfp[1]);
		qp->grabMouse(cursor);
	}
	RETURNvoid_();
}
*/
//int QWidget.grabShortcut(QKeySequence key, int context);
KMETHOD QWidget_grabShortcut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QKeySequence  key = *RawPtr_to(const QKeySequence *, sfp[1]);
		Qt::ShortcutContext context = Int_to(Qt::ShortcutContext, sfp[2]);
		int ret_v = qp->grabShortcut(key, context);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QGraphicsEffect QWidget.getGraphicsEffect();
KMETHOD QWidget_getGraphicsEffect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QGraphicsEffect* ret_v = qp->graphicsEffect();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsEffect*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsProxyWidget QWidget.graphicsProxyWidget();
KMETHOD QWidget_graphicsProxyWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QGraphicsProxyWidget* ret_v = qp->graphicsProxyWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsProxyWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QWidget.hasFocus();
KMETHOD QWidget_hasFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->hasFocus();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWidget.hasMouseTracking();
KMETHOD QWidget_hasMouseTracking(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->hasMouseTracking();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QWidget.height();
KMETHOD QWidget_height(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->height();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual int QWidget.heightForWidth(int w);
KMETHOD QWidget_heightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int w = Int_to(int, sfp[1]);
		int ret_v = qp->heightForWidth(w);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QInputContext QWidget.getInputContext();
KMETHOD QWidget_getInputContext(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QInputContext* ret_v = qp->inputContext();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QInputContext*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWidget.getInputMethodHints();
KMETHOD QWidget_getInputMethodHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::InputMethodHints ret_v = qp->inputMethodHints();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QVariant QWidget.inputMethodQuery(int query);
KMETHOD QWidget_inputMethodQuery(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
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

//void QWidget.insertAction(QAction before, QAction action);
KMETHOD QWidget_insertAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QAction*  before = RawPtr_to(QAction*, sfp[1]);
		QAction*  action = RawPtr_to(QAction*, sfp[2]);
		qp->insertAction(before, action);
	}
	RETURNvoid_();
}

//void QWidget.insertActions(QAction before, Array<QAction> actions);
KMETHOD QWidget_insertActions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
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

//boolean QWidget.isActiveWindow();
KMETHOD QWidget_isActiveWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isActiveWindow();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWidget.isAncestorOf(QWidget child);
KMETHOD QWidget_isAncestorOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QWidget*  child = RawPtr_to(const QWidget*, sfp[1]);
		bool ret_v = qp->isAncestorOf(child);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWidget.isEnabled();
KMETHOD QWidget_isEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWidget.isEnabledTo(QWidget ancestor);
KMETHOD QWidget_isEnabledTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  ancestor = RawPtr_to(QWidget*, sfp[1]);
		bool ret_v = qp->isEnabledTo(ancestor);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWidget.isFullScreen();
KMETHOD QWidget_isFullScreen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isFullScreen();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWidget.isHidden();
KMETHOD QWidget_isHidden(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isHidden();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWidget.isMaximized();
KMETHOD QWidget_isMaximized(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isMaximized();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWidget.isMinimized();
KMETHOD QWidget_isMinimized(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isMinimized();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWidget.isModal();
KMETHOD QWidget_isModal(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isModal();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWidget.isVisible();
KMETHOD QWidget_isVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isVisible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWidget.isVisibleTo(QWidget ancestor);
KMETHOD QWidget_isVisibleTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  ancestor = RawPtr_to(QWidget*, sfp[1]);
		bool ret_v = qp->isVisibleTo(ancestor);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWidget.isWindow();
KMETHOD QWidget_isWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isWindow();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWidget.isWindowModified();
KMETHOD QWidget_isWindowModified(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isWindowModified();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QLayout QWidget.getLayout();
KMETHOD QWidget_getLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QLayout* ret_v = qp->layout();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QLayout*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWidget.getLayoutDirection();
KMETHOD QWidget_getLayoutDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::LayoutDirection ret_v = qp->layoutDirection();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QLocale QWidget.getLocale();
KMETHOD QWidget_getLocale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QLocale ret_v = qp->locale();
		QLocale *ret_v_ = new QLocale(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QWidget.mapFrom(QWidget parent, QPoint pos);
KMETHOD QWidget_mapFrom(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[2]);
		QPoint ret_v = qp->mapFrom(parent, pos);
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QWidget.mapFromGlobal(QPoint pos);
KMETHOD QWidget_mapFromGlobal(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		QPoint ret_v = qp->mapFromGlobal(pos);
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QWidget.mapFromParent(QPoint pos);
KMETHOD QWidget_mapFromParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		QPoint ret_v = qp->mapFromParent(pos);
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QWidget.mapTo(QWidget parent, QPoint pos);
KMETHOD QWidget_mapTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[2]);
		QPoint ret_v = qp->mapTo(parent, pos);
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QWidget.mapToGlobal(QPoint pos);
KMETHOD QWidget_mapToGlobal(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		QPoint ret_v = qp->mapToGlobal(pos);
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QWidget.mapToParent(QPoint pos);
KMETHOD QWidget_mapToParent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		QPoint ret_v = qp->mapToParent(pos);
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRegion QWidget.getMask();
KMETHOD QWidget_getMask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QRegion ret_v = qp->mask();
		QRegion *ret_v_ = new QRegion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWidget.getMaximumHeight();
KMETHOD QWidget_getMaximumHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->maximumHeight();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QSize QWidget.getMaximumSize();
KMETHOD QWidget_getMaximumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->maximumSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWidget.getMaximumWidth();
KMETHOD QWidget_getMaximumWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->maximumWidth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QWidget.getMinimumHeight();
KMETHOD QWidget_getMinimumHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->minimumHeight();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QSize QWidget.getMinimumSize();
KMETHOD QWidget_getMinimumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->minimumSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QSize QWidget.minimumSizeHint();
KMETHOD QWidget_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWidget.getMinimumWidth();
KMETHOD QWidget_getMinimumWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->minimumWidth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QWidget.move(QPoint arg0);
KMETHOD QWidget_move(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QPoint  arg0 = *RawPtr_to(const QPoint *, sfp[1]);
		qp->move(arg0);
	}
	RETURNvoid_();
}

/*
//void QWidget.move(int x, int y);
KMETHOD QWidget_move(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		qp->move(x, y);
	}
	RETURNvoid_();
}
*/
//QWidget QWidget.nativeParentWidget();
KMETHOD QWidget_nativeParentWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->nativeParentWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QWidget.nextInFocusChain();
KMETHOD QWidget_nextInFocusChain(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->nextInFocusChain();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QWidget.normalGeometry();
KMETHOD QWidget_normalGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QRect ret_v = qp->normalGeometry();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWidget.overrideWindowFlags(int flags);
KMETHOD QWidget_overrideWindowFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::WindowFlags flags = Int_to(Qt::WindowFlags, sfp[1]);
		qp->overrideWindowFlags(flags);
	}
	RETURNvoid_();
}

//QPalette QWidget.getPalette();
KMETHOD QWidget_getPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QPalette ret_v = qp->palette();
		QPalette *ret_v_ = new QPalette(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QWidget.parentWidget();
KMETHOD QWidget_parentWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->parentWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QWidget.pos();
KMETHOD QWidget_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QPoint ret_v = qp->pos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QWidget.previousInFocusChain();
KMETHOD QWidget_previousInFocusChain(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->previousInFocusChain();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QWidget.rect();
KMETHOD QWidget_rect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QRect ret_v = qp->rect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWidget.releaseKeyboard();
KMETHOD QWidget_releaseKeyboard(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->releaseKeyboard();
	}
	RETURNvoid_();
}

//void QWidget.releaseMouse();
KMETHOD QWidget_releaseMouse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->releaseMouse();
	}
	RETURNvoid_();
}

//void QWidget.releaseShortcut(int id);
KMETHOD QWidget_releaseShortcut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int id = Int_to(int, sfp[1]);
		qp->releaseShortcut(id);
	}
	RETURNvoid_();
}

//void QWidget.removeAction(QAction action);
KMETHOD QWidget_removeAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QAction*  action = RawPtr_to(QAction*, sfp[1]);
		qp->removeAction(action);
	}
	RETURNvoid_();
}

//void QWidget.render(QPaintDevice target, QPoint targetOffset, QRegion sourceRegion, int renderFlags);
KMETHOD QWidget_render(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QPaintDevice*  target = RawPtr_to(QPaintDevice*, sfp[1]);
		const QPoint  targetOffset = *RawPtr_to(const QPoint *, sfp[2]);
		const QRegion  sourceRegion = *RawPtr_to(const QRegion *, sfp[3]);
		QWidget::RenderFlags renderFlags = Int_to(QWidget::RenderFlags, sfp[4]);
		qp->render(target, targetOffset, sourceRegion, renderFlags);
	}
	RETURNvoid_();
}

/*
//void QWidget.render(QPainter painter, QPoint targetOffset, QRegion sourceRegion, int renderFlags);
KMETHOD QWidget_render(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QPoint  targetOffset = *RawPtr_to(const QPoint *, sfp[2]);
		const QRegion  sourceRegion = *RawPtr_to(const QRegion *, sfp[3]);
		QWidget::RenderFlags renderFlags = Int_to(QWidget::RenderFlags, sfp[4]);
		qp->render(painter, targetOffset, sourceRegion, renderFlags);
	}
	RETURNvoid_();
}
*/
//void QWidget.repaint(int x, int y, int w, int h);
KMETHOD QWidget_repaint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int w = Int_to(int, sfp[3]);
		int h = Int_to(int, sfp[4]);
		qp->repaint(x, y, w, h);
	}
	RETURNvoid_();
}

/*
//void QWidget.repaint(QRect rect);
KMETHOD QWidget_repaint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		qp->repaint(rect);
	}
	RETURNvoid_();
}
*/
/*
//void QWidget.repaint(QRegion rgn);
KMETHOD QWidget_repaint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QRegion  rgn = *RawPtr_to(const QRegion *, sfp[1]);
		qp->repaint(rgn);
	}
	RETURNvoid_();
}
*/
//void QWidget.resize(QSize arg0);
KMETHOD QWidget_resize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QSize  arg0 = *RawPtr_to(const QSize *, sfp[1]);
		qp->resize(arg0);
	}
	RETURNvoid_();
}

/*
//void QWidget.resize(int w, int h);
KMETHOD QWidget_resize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int w = Int_to(int, sfp[1]);
		int h = Int_to(int, sfp[2]);
		qp->resize(w, h);
	}
	RETURNvoid_();
}
*/
//boolean QWidget.restoreGeometry(QByteArray geometry);
KMETHOD QWidget_restoreGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QByteArray  geometry = *RawPtr_to(const QByteArray *, sfp[1]);
		bool ret_v = qp->restoreGeometry(geometry);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QByteArray QWidget.saveGeometry();
KMETHOD QWidget_saveGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QByteArray ret_v = qp->saveGeometry();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWidget.scroll(int dx, int dy);
KMETHOD QWidget_scroll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int dx = Int_to(int, sfp[1]);
		int dy = Int_to(int, sfp[2]);
		qp->scroll(dx, dy);
	}
	RETURNvoid_();
}

/*
//void QWidget.scroll(int dx, int dy, QRect r);
KMETHOD QWidget_scroll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int dx = Int_to(int, sfp[1]);
		int dy = Int_to(int, sfp[2]);
		const QRect  r = *RawPtr_to(const QRect *, sfp[3]);
		qp->scroll(dx, dy, r);
	}
	RETURNvoid_();
}
*/
//void QWidget.setAcceptDrops(boolean on);
KMETHOD QWidget_setAcceptDrops(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool on = Boolean_to(bool, sfp[1]);
		qp->setAcceptDrops(on);
	}
	RETURNvoid_();
}

//void QWidget.setAccessibleDescription(String description);
KMETHOD QWidget_setAccessibleDescription(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QString description = String_to(const QString, sfp[1]);
		qp->setAccessibleDescription(description);
	}
	RETURNvoid_();
}

//void QWidget.setAccessibleName(String name);
KMETHOD QWidget_setAccessibleName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QString name = String_to(const QString, sfp[1]);
		qp->setAccessibleName(name);
	}
	RETURNvoid_();
}

//void QWidget.setAttribute(int attribute, boolean on);
KMETHOD QWidget_setAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::WidgetAttribute attribute = Int_to(Qt::WidgetAttribute, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		qp->setAttribute(attribute, on);
	}
	RETURNvoid_();
}

//void QWidget.setAutoFillBackground(boolean enabled);
KMETHOD QWidget_setAutoFillBackground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setAutoFillBackground(enabled);
	}
	RETURNvoid_();
}

//void QWidget.setBackgroundRole(int role);
KMETHOD QWidget_setBackgroundRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QPalette::ColorRole role = Int_to(QPalette::ColorRole, sfp[1]);
		qp->setBackgroundRole(role);
	}
	RETURNvoid_();
}

//void QWidget.setBaseSize(QSize arg0);
KMETHOD QWidget_setBaseSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QSize  arg0 = *RawPtr_to(const QSize *, sfp[1]);
		qp->setBaseSize(arg0);
	}
	RETURNvoid_();
}

/*
//void QWidget.setBaseSize(int basew, int baseh);
KMETHOD QWidget_setBaseSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int basew = Int_to(int, sfp[1]);
		int baseh = Int_to(int, sfp[2]);
		qp->setBaseSize(basew, baseh);
	}
	RETURNvoid_();
}
*/
//void QWidget.setContentsMargins(int left, int top, int right, int bottom);
KMETHOD QWidget_setContentsMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int left = Int_to(int, sfp[1]);
		int top = Int_to(int, sfp[2]);
		int right = Int_to(int, sfp[3]);
		int bottom = Int_to(int, sfp[4]);
		qp->setContentsMargins(left, top, right, bottom);
	}
	RETURNvoid_();
}

/*
//void QWidget.setContentsMargins(QMargins margins);
KMETHOD QWidget_setContentsMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QMargins  margins = *RawPtr_to(const QMargins *, sfp[1]);
		qp->setContentsMargins(margins);
	}
	RETURNvoid_();
}
*/
//void QWidget.setContextMenuPolicy(int policy);
KMETHOD QWidget_setContextMenuPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::ContextMenuPolicy policy = Int_to(Qt::ContextMenuPolicy, sfp[1]);
		qp->setContextMenuPolicy(policy);
	}
	RETURNvoid_();
}

//void QWidget.setCursor(QCursor arg0);
KMETHOD QWidget_setCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QCursor  arg0 = *RawPtr_to(const QCursor *, sfp[1]);
		qp->setCursor(arg0);
	}
	RETURNvoid_();
}

//void QWidget.setFixedHeight(int h);
KMETHOD QWidget_setFixedHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int h = Int_to(int, sfp[1]);
		qp->setFixedHeight(h);
	}
	RETURNvoid_();
}

//void QWidget.setFixedSize(QSize s);
KMETHOD QWidget_setFixedSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QSize  s = *RawPtr_to(const QSize *, sfp[1]);
		qp->setFixedSize(s);
	}
	RETURNvoid_();
}

/*
//void QWidget.setFixedSize(int w, int h);
KMETHOD QWidget_setFixedSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int w = Int_to(int, sfp[1]);
		int h = Int_to(int, sfp[2]);
		qp->setFixedSize(w, h);
	}
	RETURNvoid_();
}
*/
//void QWidget.setFixedWidth(int w);
KMETHOD QWidget_setFixedWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int w = Int_to(int, sfp[1]);
		qp->setFixedWidth(w);
	}
	RETURNvoid_();
}

//void QWidget.setFocus(int reason);
KMETHOD QWidget_setFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::FocusReason reason = Int_to(Qt::FocusReason, sfp[1]);
		qp->setFocus(reason);
	}
	RETURNvoid_();
}

//void QWidget.setFocusPolicy(int policy);
KMETHOD QWidget_setFocusPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::FocusPolicy policy = Int_to(Qt::FocusPolicy, sfp[1]);
		qp->setFocusPolicy(policy);
	}
	RETURNvoid_();
}

//void QWidget.setFocusProxy(QWidget w);
KMETHOD QWidget_setFocusProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  w = RawPtr_to(QWidget*, sfp[1]);
		qp->setFocusProxy(w);
	}
	RETURNvoid_();
}

//void QWidget.setFont(QFont arg0);
KMETHOD QWidget_setFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QFont  arg0 = *RawPtr_to(const QFont *, sfp[1]);
		qp->setFont(arg0);
	}
	RETURNvoid_();
}

//void QWidget.setForegroundRole(int role);
KMETHOD QWidget_setForegroundRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QPalette::ColorRole role = Int_to(QPalette::ColorRole, sfp[1]);
		qp->setForegroundRole(role);
	}
	RETURNvoid_();
}

//void QWidget.setGeometry(QRect arg0);
KMETHOD QWidget_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QRect  arg0 = *RawPtr_to(const QRect *, sfp[1]);
		qp->setGeometry(arg0);
	}
	RETURNvoid_();
}

/*
//void QWidget.setGeometry(int x, int y, int w, int h);
KMETHOD QWidget_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int w = Int_to(int, sfp[3]);
		int h = Int_to(int, sfp[4]);
		qp->setGeometry(x, y, w, h);
	}
	RETURNvoid_();
}
*/
//void QWidget.setGraphicsEffect(QGraphicsEffect effect);
KMETHOD QWidget_setGraphicsEffect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QGraphicsEffect*  effect = RawPtr_to(QGraphicsEffect*, sfp[1]);
		qp->setGraphicsEffect(effect);
	}
	RETURNvoid_();
}

//void QWidget.setInputContext(QInputContext context);
KMETHOD QWidget_setInputContext(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QInputContext*  context = RawPtr_to(QInputContext*, sfp[1]);
		qp->setInputContext(context);
	}
	RETURNvoid_();
}

//void QWidget.setInputMethodHints(int hints);
KMETHOD QWidget_setInputMethodHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::InputMethodHints hints = Int_to(Qt::InputMethodHints, sfp[1]);
		qp->setInputMethodHints(hints);
	}
	RETURNvoid_();
}

//void QWidget.setLayout(QLayout layout);
KMETHOD QWidget_setLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QLayout*  layout = RawPtr_to(QLayout*, sfp[1]);
		qp->setLayout(layout);
	}
	RETURNvoid_();
}

//void QWidget.setLayoutDirection(int direction);
KMETHOD QWidget_setLayoutDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::LayoutDirection direction = Int_to(Qt::LayoutDirection, sfp[1]);
		qp->setLayoutDirection(direction);
	}
	RETURNvoid_();
}

//void QWidget.setLocale(QLocale locale);
KMETHOD QWidget_setLocale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QLocale  locale = *RawPtr_to(const QLocale *, sfp[1]);
		qp->setLocale(locale);
	}
	RETURNvoid_();
}

//void QWidget.setMask(QBitmap bitmap);
KMETHOD QWidget_setMask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QBitmap  bitmap = *RawPtr_to(const QBitmap *, sfp[1]);
		qp->setMask(bitmap);
	}
	RETURNvoid_();
}

/*
//void QWidget.setMask(QRegion region);
KMETHOD QWidget_setMask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QRegion  region = *RawPtr_to(const QRegion *, sfp[1]);
		qp->setMask(region);
	}
	RETURNvoid_();
}
*/
//void QWidget.setMaximumHeight(int maxh);
KMETHOD QWidget_setMaximumHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int maxh = Int_to(int, sfp[1]);
		qp->setMaximumHeight(maxh);
	}
	RETURNvoid_();
}

//void QWidget.setMaximumSize(QSize arg0);
KMETHOD QWidget_setMaximumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QSize  arg0 = *RawPtr_to(const QSize *, sfp[1]);
		qp->setMaximumSize(arg0);
	}
	RETURNvoid_();
}

/*
//void QWidget.setMaximumSize(int maxw, int maxh);
KMETHOD QWidget_setMaximumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int maxw = Int_to(int, sfp[1]);
		int maxh = Int_to(int, sfp[2]);
		qp->setMaximumSize(maxw, maxh);
	}
	RETURNvoid_();
}
*/
//void QWidget.setMaximumWidth(int maxw);
KMETHOD QWidget_setMaximumWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int maxw = Int_to(int, sfp[1]);
		qp->setMaximumWidth(maxw);
	}
	RETURNvoid_();
}

//void QWidget.setMinimumHeight(int minh);
KMETHOD QWidget_setMinimumHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int minh = Int_to(int, sfp[1]);
		qp->setMinimumHeight(minh);
	}
	RETURNvoid_();
}

//void QWidget.setMinimumSize(QSize arg0);
KMETHOD QWidget_setMinimumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QSize  arg0 = *RawPtr_to(const QSize *, sfp[1]);
		qp->setMinimumSize(arg0);
	}
	RETURNvoid_();
}

/*
//void QWidget.setMinimumSize(int minw, int minh);
KMETHOD QWidget_setMinimumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int minw = Int_to(int, sfp[1]);
		int minh = Int_to(int, sfp[2]);
		qp->setMinimumSize(minw, minh);
	}
	RETURNvoid_();
}
*/
//void QWidget.setMinimumWidth(int minw);
KMETHOD QWidget_setMinimumWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int minw = Int_to(int, sfp[1]);
		qp->setMinimumWidth(minw);
	}
	RETURNvoid_();
}

//void QWidget.setMouseTracking(boolean enable);
KMETHOD QWidget_setMouseTracking(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setMouseTracking(enable);
	}
	RETURNvoid_();
}

//void QWidget.setPalette(QPalette arg0);
KMETHOD QWidget_setPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QPalette  arg0 = *RawPtr_to(const QPalette *, sfp[1]);
		qp->setPalette(arg0);
	}
	RETURNvoid_();
}

//void QWidget.setParentOL(QWidget parent);
KMETHOD QWidget_setParentOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		qp->setParent(parent);
	}
	RETURNvoid_();
}

/*
//void QWidget.setParentOL(QWidget parent, int f);
KMETHOD QWidget_setParentOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		Qt::WindowFlags f = Int_to(Qt::WindowFlags, sfp[2]);
		qp->setParent(parent, f);
	}
	RETURNvoid_();
}
*/
//void QWidget.setShortcutAutoRepeat(int id, boolean enable);
KMETHOD QWidget_setShortcutAutoRepeat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int id = Int_to(int, sfp[1]);
		bool enable = Boolean_to(bool, sfp[2]);
		qp->setShortcutAutoRepeat(id, enable);
	}
	RETURNvoid_();
}

//void QWidget.setShortcutEnabled(int id, boolean enable);
KMETHOD QWidget_setShortcutEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int id = Int_to(int, sfp[1]);
		bool enable = Boolean_to(bool, sfp[2]);
		qp->setShortcutEnabled(id, enable);
	}
	RETURNvoid_();
}

//void QWidget.setSizeIncrement(QSize arg0);
KMETHOD QWidget_setSizeIncrement(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QSize  arg0 = *RawPtr_to(const QSize *, sfp[1]);
		qp->setSizeIncrement(arg0);
	}
	RETURNvoid_();
}

/*
//void QWidget.setSizeIncrement(int w, int h);
KMETHOD QWidget_setSizeIncrement(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int w = Int_to(int, sfp[1]);
		int h = Int_to(int, sfp[2]);
		qp->setSizeIncrement(w, h);
	}
	RETURNvoid_();
}
*/
//void QWidget.setSizePolicy(QSizePolicy arg0);
KMETHOD QWidget_setSizePolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QSizePolicy  arg0 = *RawPtr_to(QSizePolicy *, sfp[1]);
		qp->setSizePolicy(arg0);
	}
	RETURNvoid_();
}

/*
//void QWidget.setSizePolicy(int horizontal, int vertical);
KMETHOD QWidget_setSizePolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QSizePolicy::Policy horizontal = Int_to(QSizePolicy::Policy, sfp[1]);
		QSizePolicy::Policy vertical = Int_to(QSizePolicy::Policy, sfp[2]);
		qp->setSizePolicy(horizontal, vertical);
	}
	RETURNvoid_();
}
*/
//void QWidget.setStatusTip(String arg0);
KMETHOD QWidget_setStatusTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QString arg0 = String_to(const QString, sfp[1]);
		qp->setStatusTip(arg0);
	}
	RETURNvoid_();
}

//void QWidget.setStyle(QStyle style);
KMETHOD QWidget_setStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QStyle*  style = RawPtr_to(QStyle*, sfp[1]);
		qp->setStyle(style);
	}
	RETURNvoid_();
}

//void QWidget.setToolTip(String arg0);
KMETHOD QWidget_setToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QString arg0 = String_to(const QString, sfp[1]);
		qp->setToolTip(arg0);
	}
	RETURNvoid_();
}

//void QWidget.setUpdatesEnabled(boolean enable);
KMETHOD QWidget_setUpdatesEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setUpdatesEnabled(enable);
	}
	RETURNvoid_();
}

//void QWidget.setWhatsThis(String arg0);
KMETHOD QWidget_setWhatsThis(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QString arg0 = String_to(const QString, sfp[1]);
		qp->setWhatsThis(arg0);
	}
	RETURNvoid_();
}

//void QWidget.setWindowFilePath(String filePath);
KMETHOD QWidget_setWindowFilePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QString filePath = String_to(const QString, sfp[1]);
		qp->setWindowFilePath(filePath);
	}
	RETURNvoid_();
}

//void QWidget.setWindowFlags(int type);
KMETHOD QWidget_setWindowFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::WindowFlags type = Int_to(Qt::WindowFlags, sfp[1]);
		qp->setWindowFlags(type);
	}
	RETURNvoid_();
}

//void QWidget.setWindowIcon(QIcon icon);
KMETHOD QWidget_setWindowIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
		qp->setWindowIcon(icon);
	}
	RETURNvoid_();
}

//void QWidget.setWindowIconText(String arg0);
KMETHOD QWidget_setWindowIconText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QString arg0 = String_to(const QString, sfp[1]);
		qp->setWindowIconText(arg0);
	}
	RETURNvoid_();
}

////void QWidget.setWindowModality(int windowModality);
KMETHOD QWidget_setWindowModality(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::WindowModality windowModality = Int_to(Qt::WindowModality, sfp[1]);
		qp->setWindowModality(windowModality);
	}
	RETURNvoid_();
}

//void QWidget.setWindowOpacity(float level);
KMETHOD QWidget_setWindowOpacity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qreal level = Float_to(qreal, sfp[1]);
		qp->setWindowOpacity(level);
	}
	RETURNvoid_();
}

//void QWidget.setWindowRole(String role);
KMETHOD QWidget_setWindowRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QString role = String_to(const QString, sfp[1]);
		qp->setWindowRole(role);
	}
	RETURNvoid_();
}

//void QWidget.setWindowState(int windowState);
KMETHOD QWidget_setWindowState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::WindowStates windowState = Int_to(Qt::WindowStates, sfp[1]);
		qp->setWindowState(windowState);
	}
	RETURNvoid_();
}

//void QWidget.setWindowSurface(QWindowSurface surface);
KMETHOD QWidget_setWindowSurface(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWindowSurface*  surface = RawPtr_to(QWindowSurface*, sfp[1]);
		qp->setWindowSurface(surface);
	}
	RETURNvoid_();
}

//QSize QWidget.size();
KMETHOD QWidget_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->size();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QSize QWidget.sizeHint();
KMETHOD QWidget_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSize QWidget.getSizeIncrement();
KMETHOD QWidget_getSizeIncrement(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeIncrement();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSizePolicy QWidget.getSizePolicy();
KMETHOD QWidget_getSizePolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QSizePolicy ret_v = qp->sizePolicy();
		QSizePolicy *ret_v_ = new QSizePolicy(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWidget.stackUnder(QWidget w);
KMETHOD QWidget_stackUnder(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  w = RawPtr_to(QWidget*, sfp[1]);
		qp->stackUnder(w);
	}
	RETURNvoid_();
}

//String QWidget.getStatusTip();
KMETHOD QWidget_getStatusTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->statusTip();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QStyle QWidget.getStyle();
KMETHOD QWidget_getStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QStyle* ret_v = qp->style();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QStyle*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWidget.getStyleSheet();
KMETHOD QWidget_getStyleSheet(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->styleSheet();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QWidget.testAttribute(int attribute);
KMETHOD QWidget_testAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::WidgetAttribute attribute = Int_to(Qt::WidgetAttribute, sfp[1]);
		bool ret_v = qp->testAttribute(attribute);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QWidget.getToolTip();
KMETHOD QWidget_getToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->toolTip();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QWidget.underMouse();
KMETHOD QWidget_underMouse(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->underMouse();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QWidget.ungrabGesture(int gesture);
KMETHOD QWidget_ungrabGesture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::GestureType gesture = Int_to(Qt::GestureType, sfp[1]);
		qp->ungrabGesture(gesture);
	}
	RETURNvoid_();
}

//void QWidget.unsetCursor();
KMETHOD QWidget_unsetCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->unsetCursor();
	}
	RETURNvoid_();
}

//void QWidget.unsetLayoutDirection();
KMETHOD QWidget_unsetLayoutDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->unsetLayoutDirection();
	}
	RETURNvoid_();
}

//void QWidget.unsetLocale();
KMETHOD QWidget_unsetLocale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->unsetLocale();
	}
	RETURNvoid_();
}

//void QWidget.updateOL(int x, int y, int w, int h);
KMETHOD QWidget_updateOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int w = Int_to(int, sfp[3]);
		int h = Int_to(int, sfp[4]);
		qp->update(x, y, w, h);
	}
	RETURNvoid_();
}

/*
//void QWidget.updateOL(QRect rect);
KMETHOD QWidget_updateOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		qp->update(rect);
	}
	RETURNvoid_();
}
*/
/*
//void QWidget.updateOL(QRegion rgn);
KMETHOD QWidget_updateOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QRegion  rgn = *RawPtr_to(const QRegion *, sfp[1]);
		qp->update(rgn);
	}
	RETURNvoid_();
}
*/
//void QWidget.updateOLGeometry();
KMETHOD QWidget_updateOLGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->updateGeometry();
	}
	RETURNvoid_();
}

//boolean QWidget.getUpdatesEnabled();
KMETHOD QWidget_getUpdatesEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->updatesEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QRegion QWidget.visibleRegion();
KMETHOD QWidget_visibleRegion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QRegion ret_v = qp->visibleRegion();
		QRegion *ret_v_ = new QRegion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWidget.getWhatsThis();
KMETHOD QWidget_getWhatsThis(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->whatsThis();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWidget.width();
KMETHOD QWidget_width(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->width();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWidget QWidget.window();
KMETHOD QWidget_window(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->window();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWidget.getWindowFilePath();
KMETHOD QWidget_getWindowFilePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->windowFilePath();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWidget.getWindowFlags();
KMETHOD QWidget_getWindowFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::WindowFlags ret_v = qp->windowFlags();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QIcon QWidget.getWindowIcon();
KMETHOD QWidget_getWindowIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QIcon ret_v = qp->windowIcon();
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWidget.getWindowIconText();
KMETHOD QWidget_getWindowIconText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->windowIconText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWidget.getWindowModality();
KMETHOD QWidget_getWindowModality(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::WindowModality ret_v = qp->windowModality();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QWidget.getWindowOpacity();
KMETHOD QWidget_getWindowOpacity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->windowOpacity();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//String QWidget.getWindowRole();
KMETHOD QWidget_getWindowRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->windowRole();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWidget.getWindowState();
KMETHOD QWidget_getWindowState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::WindowStates ret_v = qp->windowState();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWindowSurface QWidget.getWindowSurface();
KMETHOD QWidget_getWindowSurface(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWindowSurface* ret_v = qp->windowSurface();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWindowSurface*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWidget.getWindowTitle();
KMETHOD QWidget_getWindowTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->windowTitle();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWidget.windowType();
KMETHOD QWidget_windowType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::WindowType ret_v = qp->windowType();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QWidget.x();
KMETHOD QWidget_x(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->x();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QWidget.y();
KMETHOD QWidget_y(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->y();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWidget QWidget.keyboardGrabber();
KMETHOD QWidget_keyboardGrabber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->keyboardGrabber();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QWidget.mouseGrabber();
KMETHOD QWidget_mouseGrabber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->mouseGrabber();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWidget.setTabOrder(QWidget first, QWidget second);
KMETHOD QWidget_setTabOrder(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  first = RawPtr_to(QWidget*, sfp[1]);
		QWidget*  second = RawPtr_to(QWidget*, sfp[2]);
		qp->setTabOrder(first, second);
	}
	RETURNvoid_();
}

//boolean QWidget.close();
KMETHOD QWidget_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->close();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QWidget.hide();
KMETHOD QWidget_hide(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->hide();
	}
	RETURNvoid_();
}

//void QWidget.lower();
KMETHOD QWidget_lower(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->lower();
	}
	RETURNvoid_();
}

//void QWidget.raise();
KMETHOD QWidget_raise(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->raise();
	}
	RETURNvoid_();
}

/*
//void QWidget.repaint();
KMETHOD QWidget_repaint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->repaint();
	}
	RETURNvoid_();
}
*/
//void QWidget.setDisabled(boolean disable);
KMETHOD QWidget_setDisabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool disable = Boolean_to(bool, sfp[1]);
		qp->setDisabled(disable);
	}
	RETURNvoid_();
}

//void QWidget.setEnabled(boolean arg0);
KMETHOD QWidget_setEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setEnabled(arg0);
	}
	RETURNvoid_();
}

/*
//void QWidget.setFocus();
KMETHOD QWidget_setFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->setFocus();
	}
	RETURNvoid_();
}
*/
//void QWidget.setHidden(boolean hidden);
KMETHOD QWidget_setHidden(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool hidden = Boolean_to(bool, sfp[1]);
		qp->setHidden(hidden);
	}
	RETURNvoid_();
}

//void QWidget.setStyleSheet(String styleSheet);
KMETHOD QWidget_setStyleSheet(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QString styleSheet = String_to(const QString, sfp[1]);
		qp->setStyleSheet(styleSheet);
	}
	RETURNvoid_();
}

//@Virtual void QWidget.setVisible(boolean visible);
KMETHOD QWidget_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setVisible(visible);
	}
	RETURNvoid_();
}

//void QWidget.setWindowModified(boolean arg0);
KMETHOD QWidget_setWindowModified(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setWindowModified(arg0);
	}
	RETURNvoid_();
}

//void QWidget.setWindowTitleOL(String arg0);
KMETHOD QWidget_setWindowTitleOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		const QString arg0 = String_to(const QString, sfp[1]);
		qp->setWindowTitle(arg0);
	}
	RETURNvoid_();
}

//void QWidget.show();
KMETHOD QWidget_show(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->show();
	}
	RETURNvoid_();
}

//void QWidget.showFullScreen();
KMETHOD QWidget_showFullScreen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->showFullScreen();
	}
	RETURNvoid_();
}

//void QWidget.showMaximized();
KMETHOD QWidget_showMaximized(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->showMaximized();
	}
	RETURNvoid_();
}

//void QWidget.showMinimized();
KMETHOD QWidget_showMinimized(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->showMinimized();
	}
	RETURNvoid_();
}

//void QWidget.showNormal();
KMETHOD QWidget_showNormal(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->showNormal();
	}
	RETURNvoid_();
}

/*
//void QWidget.updateOL();
KMETHOD QWidget_updateOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget *  qp = RawPtr_to(QWidget *, sfp[0]);
	if (qp != NULL) {
		qp->update();
	}
	RETURNvoid_();
}
*/

DummyQWidget::DummyQWidget()
{
	self = NULL;
	action_event_func = NULL;
	change_event_func = NULL;
	close_event_func = NULL;
	context_menu_event_func = NULL;
	drag_enter_event_func = NULL;
	drag_leave_event_func = NULL;
	drag_move_event_func = NULL;
	drop_event_func = NULL;
	enter_event_func = NULL;
	focus_in_event_func = NULL;
	focus_out_event_func = NULL;
	hide_event_func = NULL;
	input_method_event_func = NULL;
	key_press_event_func = NULL;
	key_release_event_func = NULL;
	leave_event_func = NULL;
	mouse_double_click_event_func = NULL;
	mouse_move_event_func = NULL;
	mouse_press_event_func = NULL;
	mouse_release_event_func = NULL;
	move_event_func = NULL;
	paint_event_func = NULL;
	resize_event_func = NULL;
	show_event_func = NULL;
	tablet_event_func = NULL;
	wheel_event_func = NULL;
	custom_context_menu_requested_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	event_map->insert(map<string, knh_Func_t *>::value_type("action-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("change-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("close-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("context-menu-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("drag-enter-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("drag-leave-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("drag-move-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("drop-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("enter-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("focus-in-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("focus-out-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("hide-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("input-method-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("key-press-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("key-release-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("leave-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("mouse-double-click-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("mouse-move-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("mouse-press-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("mouse-release-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("move-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("paint-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("resize-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("show-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("tablet-event", NULL));
	event_map->insert(map<string, knh_Func_t *>::value_type("wheel-event", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("custom-context-menu-requested", NULL));
}

void DummyQWidget::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWidget::self = ptr;
	DummyQObject::setSelf(ptr);
	DummyQPaintDevice::setSelf(ptr);
}

bool DummyQWidget::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	case QEvent::ActionAdded:
	case QEvent::ActionChanged:
	case QEvent::ActionRemoved:
		ret = actionEventDummy(dynamic_cast<QActionEvent*>(event));
		break;
	case QEvent::ActivationChange:
	case QEvent::ApplicationFontChange:
	case QEvent::ApplicationLayoutDirectionChange:
	case QEvent::ApplicationPaletteChange:
	case QEvent::ApplicationWindowIconChange:
	case QEvent::ContentsRectChange:
	case QEvent::CursorChange:
	case QEvent::EnabledChange:
	case QEvent::FontChange:
	case QEvent::IconTextChange:
	case QEvent::LanguageChange:
	case QEvent::LayoutDirectionChange:
	case QEvent::LocaleChange:
	case QEvent::MacSizeChange:
	case QEvent::ModifiedChange:
	case QEvent::MouseTrackingChange:
	case QEvent::PaletteChange:
	case QEvent::ParentAboutToChange:
	case QEvent::ParentChange:
	case QEvent::StyleChange:
	case QEvent::ToolBarChange:
	case QEvent::ToolTipChange:
	case QEvent::WindowIconChange:
	case QEvent::WindowStateChange:
	case QEvent::WindowTitleChange:
	case QEvent::ZOrderChange:
	case QEvent::KeyboardLayoutChange:
	case QEvent::DynamicPropertyChange:
	case QEvent::WinIdChange:
		ret = changeEventDummy(dynamic_cast<QEvent*>(event));
		break;
	case QEvent::Close:
		ret = closeEventDummy(dynamic_cast<QCloseEvent*>(event));
		break;
	case QEvent::ContextMenu:
		ret = contextMenuEventDummy(dynamic_cast<QContextMenuEvent*>(event));
		break;
	case QEvent::DragEnter:
		ret = dragEnterEventDummy(dynamic_cast<QDragEnterEvent*>(event));
		break;
	case QEvent::DragLeave:
		ret = dragLeaveEventDummy(dynamic_cast<QDragLeaveEvent*>(event));
		break;
	case QEvent::DragMove:
		ret = dragMoveEventDummy(dynamic_cast<QDragMoveEvent*>(event));
		break;
	case QEvent::Drop:
		ret = dropEventDummy(dynamic_cast<QDropEvent*>(event));
		break;
	case QEvent::Enter:
		ret = enterEventDummy(dynamic_cast<QEvent*>(event));
		break;
	case QEvent::FocusIn:
		ret = focusInEventDummy(dynamic_cast<QFocusEvent*>(event));
		break;
	case QEvent::FocusOut:
		ret = focusOutEventDummy(dynamic_cast<QFocusEvent*>(event));
		break;
	case QEvent::Hide:
		ret = hideEventDummy(dynamic_cast<QHideEvent*>(event));
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
	case QEvent::Leave:
		ret = leaveEventDummy(dynamic_cast<QEvent*>(event));
		break;
	case QEvent::MouseButtonDblClick:
		ret = mouseDoubleClickEventDummy(dynamic_cast<QMouseEvent*>(event));
		break;
	case QEvent::MouseMove:
		ret = mouseMoveEventDummy(dynamic_cast<QMouseEvent*>(event));
		break;
	case QEvent::MouseButtonPress:
		ret = mousePressEventDummy(dynamic_cast<QMouseEvent*>(event));
		break;
	case QEvent::MouseButtonRelease:
		ret = mouseReleaseEventDummy(dynamic_cast<QMouseEvent*>(event));
		break;
	case QEvent::Move:
		ret = moveEventDummy(dynamic_cast<QMoveEvent*>(event));
		break;
	case QEvent::Paint:
		ret = paintEventDummy(dynamic_cast<QPaintEvent*>(event));
		break;
	case QEvent::Resize:
		ret = resizeEventDummy(dynamic_cast<QResizeEvent*>(event));
		break;
	case QEvent::Show:
		ret = showEventDummy(dynamic_cast<QShowEvent*>(event));
		break;
	case QEvent::TabletMove:
	case QEvent::TabletPress:
	case QEvent::TabletRelease:
	case QEvent::TabletEnterProximity:
	case QEvent::TabletLeaveProximity:
		ret = tabletEventDummy(dynamic_cast<QTabletEvent*>(event));
		break;
	case QEvent::Wheel:
		ret = wheelEventDummy(dynamic_cast<QWheelEvent*>(event));
		break;
	default:
		ret = DummyQObject::eventDispatcher(event);
		if (ret) break;
		ret = DummyQPaintDevice::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQWidget::actionEventDummy(QActionEvent* event)
{
	if (action_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QActionEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, action_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::changeEventDummy(QEvent* event)
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

bool DummyQWidget::closeEventDummy(QCloseEvent* event)
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

bool DummyQWidget::contextMenuEventDummy(QContextMenuEvent* event)
{
	if (context_menu_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QContextMenuEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, context_menu_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::dragEnterEventDummy(QDragEnterEvent* event)
{
	if (drag_enter_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QDragEnterEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, drag_enter_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::dragLeaveEventDummy(QDragLeaveEvent* event)
{
	if (drag_leave_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QDragLeaveEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, drag_leave_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::dragMoveEventDummy(QDragMoveEvent* event)
{
	if (drag_move_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QDragMoveEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, drag_move_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::dropEventDummy(QDropEvent* event)
{
	if (drop_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QDropEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, drop_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::enterEventDummy(QEvent* event)
{
	if (enter_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, enter_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::focusInEventDummy(QFocusEvent* event)
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

bool DummyQWidget::focusOutEventDummy(QFocusEvent* event)
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

bool DummyQWidget::hideEventDummy(QHideEvent* event)
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

bool DummyQWidget::inputMethodEventDummy(QInputMethodEvent* event)
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

bool DummyQWidget::keyPressEventDummy(QKeyEvent* event)
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

bool DummyQWidget::keyReleaseEventDummy(QKeyEvent* event)
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

bool DummyQWidget::leaveEventDummy(QEvent* event)
{
	if (leave_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, leave_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::mouseDoubleClickEventDummy(QMouseEvent* event)
{
	if (mouse_double_click_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QMouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, mouse_double_click_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::mouseMoveEventDummy(QMouseEvent* event)
{
	if (mouse_move_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QMouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, mouse_move_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::mousePressEventDummy(QMouseEvent* event)
{
	if (mouse_press_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QMouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, mouse_press_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::mouseReleaseEventDummy(QMouseEvent* event)
{
	if (mouse_release_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QMouseEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, mouse_release_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::moveEventDummy(QMoveEvent* event)
{
	if (move_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QMoveEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, move_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::paintEventDummy(QPaintEvent* event)
{
	if (paint_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QPaintEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, paint_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::resizeEventDummy(QResizeEvent* event)
{
	if (resize_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QResizeEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, resize_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::showEventDummy(QShowEvent* event)
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

bool DummyQWidget::tabletEventDummy(QTabletEvent* event)
{
	if (tablet_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QTabletEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, tablet_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::wheelEventDummy(QWheelEvent* event)
{
	if (wheel_event_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QWheelEvent, event);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, wheel_event_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::customContextMenuRequestedSlot(const QPoint pos)
{
	if (custom_context_menu_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QPoint, pos);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, custom_context_menu_requested_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWidget::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWidget::event_map->bigin();
	if ((itr = DummyQWidget::event_map->find(str)) == DummyQWidget::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		if (ret) return true;
		ret = DummyQPaintDevice::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		action_event_func = (*event_map)["action-event"];
		change_event_func = (*event_map)["change-event"];
		close_event_func = (*event_map)["close-event"];
		context_menu_event_func = (*event_map)["context-menu-event"];
		drag_enter_event_func = (*event_map)["drag-enter-event"];
		drag_leave_event_func = (*event_map)["drag-leave-event"];
		drag_move_event_func = (*event_map)["drag-move-event"];
		drop_event_func = (*event_map)["drop-event"];
		enter_event_func = (*event_map)["enter-event"];
		focus_in_event_func = (*event_map)["focus-in-event"];
		focus_out_event_func = (*event_map)["focus-out-event"];
		hide_event_func = (*event_map)["hide-event"];
		input_method_event_func = (*event_map)["input-method-event"];
		key_press_event_func = (*event_map)["key-press-event"];
		key_release_event_func = (*event_map)["key-release-event"];
		leave_event_func = (*event_map)["leave-event"];
		mouse_double_click_event_func = (*event_map)["mouse-double-click-event"];
		mouse_move_event_func = (*event_map)["mouse-move-event"];
		mouse_press_event_func = (*event_map)["mouse-press-event"];
		mouse_release_event_func = (*event_map)["mouse-release-event"];
		move_event_func = (*event_map)["move-event"];
		paint_event_func = (*event_map)["paint-event"];
		resize_event_func = (*event_map)["resize-event"];
		show_event_func = (*event_map)["show-event"];
		tablet_event_func = (*event_map)["tablet-event"];
		wheel_event_func = (*event_map)["wheel-event"];
		return true;
	}
}

bool DummyQWidget::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWidget::slot_map->bigin();
	if ((itr = DummyQWidget::slot_map->find(str)) == DummyQWidget::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		if (ret) return true;
		ret = DummyQPaintDevice::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		custom_context_menu_requested_func = (*slot_map)["custom-context-menu-requested"];
		return true;
	}
}


void DummyQWidget::connection(QObject *o)
{
	connect(o, SIGNAL(customContextMenuRequested(const QPoint)), this, SLOT(customContextMenuRequestedSlot(const QPoint)));
	DummyQObject::connection(o);
	DummyQPaintDevice::connection(o);
}

KQWidget::KQWidget(QWidget* parent, Qt::WindowFlags f) : QWidget(parent, f)
{
	self = NULL;
	dummy = new DummyQWidget();
	dummy->connection((QObject*)this);
}

KMETHOD QWidget_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWidget *qp = RawPtr_to(KQWidget *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWidget]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWidget]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWidget_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWidget *qp = RawPtr_to(KQWidget *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWidget]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWidget]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWidget_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWidget *qp = (KQWidget *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWidget_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 27;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQWidget *qp = (KQWidget *)p->rawptr;
//		(void)qp;
		if (qp->dummy->action_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->action_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->change_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->change_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->close_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->close_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->context_menu_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->context_menu_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->drag_enter_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->drag_enter_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->drag_leave_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->drag_leave_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->drag_move_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->drag_move_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->drop_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->drop_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->enter_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->enter_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->focus_in_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->focus_in_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->focus_out_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->focus_out_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->hide_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->hide_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->input_method_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->input_method_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->key_press_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->key_press_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->key_release_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->key_release_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->leave_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->leave_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->mouse_double_click_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->mouse_double_click_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->mouse_move_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->mouse_move_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->mouse_press_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->mouse_press_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->mouse_release_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->mouse_release_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->move_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->move_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->paint_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->paint_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->resize_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->resize_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->show_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->show_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->tablet_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->tablet_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->wheel_event_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->wheel_event_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->custom_context_menu_requested_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->custom_context_menu_requested_func);
			KNH_SIZEREF(ctx);
		}
	}
}

static int QWidget_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWidget::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQWidget::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QWidget::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQWidget(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWidget";
	cdef->free = QWidget_free;
	cdef->reftrace = QWidget_reftrace;
	cdef->compareTo = QWidget_compareTo;
}

static knh_IntData_t QWidgetConstInt[] = {
	{"DrawWindowBackground", QWidget::DrawWindowBackground},
	{"DrawChildren", QWidget::DrawChildren},
	{"IgnoreMask", QWidget::IgnoreMask},
	{NULL, 0}
};

DEFAPI(void) constQWidget(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QWidgetConstInt);
}

