//@Virtual @Override QSize QTabBar.minimumSizeHint();
KMETHOD QTabBar_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QTabBar.sizeHint();
KMETHOD QTabBar_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTabBar QTabBar.new(QWidget parent);
KMETHOD QTabBar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQTabBar *ret_v = new KQTabBar(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QTabBar.addTab(String text);
KMETHOD QTabBar_addTab(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		const QString text = String_to(const QString, sfp[1]);
		int ret_v = qp->addTab(text);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QTabBar.addTab(QIcon icon, String text);
KMETHOD QTabBar_addTab(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		int ret_v = qp->addTab(icon, text);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//int QTabBar.count();
KMETHOD QTabBar_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTabBar.getCurrentIndex();
KMETHOD QTabBar_getCurrentIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->currentIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QTabBar.getDocumentMode();
KMETHOD QTabBar_getDocumentMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->documentMode();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTabBar.getDrawBase();
KMETHOD QTabBar_getDrawBase(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->drawBase();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTabBar.getElideMode();
KMETHOD QTabBar_getElideMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		Qt::TextElideMode ret_v = qp->elideMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QTabBar.getExpanding();
KMETHOD QTabBar_getExpanding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->expanding();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QSize QTabBar.getIconSize();
KMETHOD QTabBar_getIconSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->iconSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTabBar.insertTab(int index, String text);
KMETHOD QTabBar_insertTab(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		int ret_v = qp->insertTab(index, text);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QTabBar.insertTab(int index, QIcon icon, String text);
KMETHOD QTabBar_insertTab(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		int ret_v = qp->insertTab(index, icon, text);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//boolean QTabBar.isMovable();
KMETHOD QTabBar_isMovable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isMovable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTabBar.isTabEnabled(int index);
KMETHOD QTabBar_isTabEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		bool ret_v = qp->isTabEnabled(index);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTabBar.moveTab(int from_, int to_);
KMETHOD QTabBar_moveTab(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int from = Int_to(int, sfp[1]);
		int to = Int_to(int, sfp[2]);
		qp->moveTab(from, to);
	}
	RETURNvoid_();
}

//void QTabBar.removeTab(int index);
KMETHOD QTabBar_removeTab(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		qp->removeTab(index);
	}
	RETURNvoid_();
}

//int QTabBar.getSelectionBehaviorOnRemove();
KMETHOD QTabBar_getSelectionBehaviorOnRemove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		QTabBar::SelectionBehavior ret_v = qp->selectionBehaviorOnRemove();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTabBar.setDocumentMode(boolean set);
KMETHOD QTabBar_setDocumentMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		bool set = Boolean_to(bool, sfp[1]);
		qp->setDocumentMode(set);
	}
	RETURNvoid_();
}

//void QTabBar.setDrawBase(boolean drawTheBase);
KMETHOD QTabBar_setDrawBase(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		bool drawTheBase = Boolean_to(bool, sfp[1]);
		qp->setDrawBase(drawTheBase);
	}
	RETURNvoid_();
}

//void QTabBar.setElideMode(int arg0);
KMETHOD QTabBar_setElideMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		Qt::TextElideMode arg0 = Int_to(Qt::TextElideMode, sfp[1]);
		qp->setElideMode(arg0);
	}
	RETURNvoid_();
}

//void QTabBar.setExpanding(boolean enabled);
KMETHOD QTabBar_setExpanding(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setExpanding(enabled);
	}
	RETURNvoid_();
}

//void QTabBar.setIconSize(QSize size);
KMETHOD QTabBar_setIconSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		qp->setIconSize(size);
	}
	RETURNvoid_();
}

//void QTabBar.setMovable(boolean movable);
KMETHOD QTabBar_setMovable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		bool movable = Boolean_to(bool, sfp[1]);
		qp->setMovable(movable);
	}
	RETURNvoid_();
}

//void QTabBar.setSelectionBehaviorOnRemove(int behavior);
KMETHOD QTabBar_setSelectionBehaviorOnRemove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		QTabBar::SelectionBehavior behavior = Int_to(QTabBar::SelectionBehavior, sfp[1]);
		qp->setSelectionBehaviorOnRemove(behavior);
	}
	RETURNvoid_();
}

//void QTabBar.setShape(int shape);
KMETHOD QTabBar_setShape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		QTabBar::Shape shape = Int_to(QTabBar::Shape, sfp[1]);
		qp->setShape(shape);
	}
	RETURNvoid_();
}

//void QTabBar.setTabButton(int index, int position, QWidget widget);
KMETHOD QTabBar_setTabButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QTabBar::ButtonPosition position = Int_to(QTabBar::ButtonPosition, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->setTabButton(index, position, widget);
	}
	RETURNvoid_();
}

//void QTabBar.setTabData(int index, QVariant data);
KMETHOD QTabBar_setTabData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		const QVariant  data = *RawPtr_to(const QVariant *, sfp[2]);
		qp->setTabData(index, data);
	}
	RETURNvoid_();
}

//void QTabBar.setTabEnabled(int index, boolean enabled);
KMETHOD QTabBar_setTabEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		bool enabled = Boolean_to(bool, sfp[2]);
		qp->setTabEnabled(index, enabled);
	}
	RETURNvoid_();
}

//void QTabBar.setTabIcon(int index, QIcon icon);
KMETHOD QTabBar_setTabIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[2]);
		qp->setTabIcon(index, icon);
	}
	RETURNvoid_();
}

//void QTabBar.setTabText(int index, String text);
KMETHOD QTabBar_setTabText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		qp->setTabText(index, text);
	}
	RETURNvoid_();
}

//void QTabBar.setTabTextColor(int index, QColor color);
KMETHOD QTabBar_setTabTextColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		const QColor  color = *RawPtr_to(const QColor *, sfp[2]);
		qp->setTabTextColor(index, color);
	}
	RETURNvoid_();
}

//void QTabBar.setTabToolTip(int index, String tip);
KMETHOD QTabBar_setTabToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		const QString tip = String_to(const QString, sfp[2]);
		qp->setTabToolTip(index, tip);
	}
	RETURNvoid_();
}

//void QTabBar.setTabWhatsThis(int index, String text);
KMETHOD QTabBar_setTabWhatsThis(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		qp->setTabWhatsThis(index, text);
	}
	RETURNvoid_();
}

//void QTabBar.setTabsClosable(boolean closable);
KMETHOD QTabBar_setTabsClosable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		bool closable = Boolean_to(bool, sfp[1]);
		qp->setTabsClosable(closable);
	}
	RETURNvoid_();
}

//void QTabBar.setUsesScrollButtons(boolean useButtons);
KMETHOD QTabBar_setUsesScrollButtons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		bool useButtons = Boolean_to(bool, sfp[1]);
		qp->setUsesScrollButtons(useButtons);
	}
	RETURNvoid_();
}

//int QTabBar.getShape();
KMETHOD QTabBar_getShape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		QTabBar::Shape ret_v = qp->shape();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTabBar.tabAt(QPoint position);
KMETHOD QTabBar_tabAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		int ret_v = qp->tabAt(position);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWidget QTabBar.getTabButton(int index, int position);
KMETHOD QTabBar_getTabButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QTabBar::ButtonPosition position = Int_to(QTabBar::ButtonPosition, sfp[2]);
		QWidget* ret_v = qp->tabButton(index, position);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QVariant QTabBar.getTabData(int index);
KMETHOD QTabBar_getTabData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QVariant ret_v = qp->tabData(index);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QIcon QTabBar.getTabIcon(int index);
KMETHOD QTabBar_getTabIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QIcon ret_v = qp->tabIcon(index);
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QTabBar.tabRect(int index);
KMETHOD QTabBar_tabRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QRect ret_v = qp->tabRect(index);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QTabBar.getTabText(int index);
KMETHOD QTabBar_getTabText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QString ret_v = qp->tabText(index);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QColor QTabBar.getTabTextColor(int index);
KMETHOD QTabBar_getTabTextColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QColor ret_v = qp->tabTextColor(index);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QTabBar.getTabToolTip(int index);
KMETHOD QTabBar_getTabToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QString ret_v = qp->tabToolTip(index);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QTabBar.getTabWhatsThis(int index);
KMETHOD QTabBar_getTabWhatsThis(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QString ret_v = qp->tabWhatsThis(index);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QTabBar.getTabsClosable();
KMETHOD QTabBar_getTabsClosable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->tabsClosable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTabBar.getUsesScrollButtons();
KMETHOD QTabBar_getUsesScrollButtons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->usesScrollButtons();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTabBar.setCurrentIndex(int index);
KMETHOD QTabBar_setCurrentIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabBar *  qp = RawPtr_to(QTabBar *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		qp->setCurrentIndex(index);
	}
	RETURNvoid_();
}


DummyQTabBar::DummyQTabBar()
{
	self = NULL;
	current_changed_func = NULL;
	tab_close_requested_func = NULL;
	tab_moved_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("current-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("tab-close-requested", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("tab-moved", NULL));
}

void DummyQTabBar::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTabBar::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQTabBar::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTabBar::currentChangedSlot(int index)
{
	if (current_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = index;
		knh_Func_invoke(lctx, current_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQTabBar::tabCloseRequestedSlot(int index)
{
	if (tab_close_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = index;
		knh_Func_invoke(lctx, tab_close_requested_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQTabBar::tabMovedSlot(int from, int to)
{
	if (tab_moved_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = from;
		lsfp[K_CALLDELTA+3].ivalue = to;
		knh_Func_invoke(lctx, tab_moved_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQTabBar::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTabBar::event_map->bigin();
	if ((itr = DummyQTabBar::event_map->find(str)) == DummyQTabBar::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTabBar::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTabBar::slot_map->bigin();
	if ((itr = DummyQTabBar::slot_map->find(str)) == DummyQTabBar::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		current_changed_func = (*slot_map)["current-changed"];
		tab_close_requested_func = (*slot_map)["tab-close-requested"];
		tab_moved_func = (*slot_map)["tab-moved"];
		return true;
	}
}


void DummyQTabBar::connection(QObject *o)
{
	connect(o, SIGNAL(currentChanged(int)), this, SLOT(currentChangedSlot(int)));
	connect(o, SIGNAL(tabCloseRequested(int)), this, SLOT(tabCloseRequestedSlot(int)));
	connect(o, SIGNAL(tabMoved(int, int)), this, SLOT(tabMovedSlot(int, int)));
	DummyQWidget::connection(o);
}

KQTabBar::KQTabBar(QWidget* parent) : QTabBar(parent)
{
	self = NULL;
	dummy = new DummyQTabBar();
	dummy->connection((QObject*)this);
}

KMETHOD QTabBar_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTabBar *qp = RawPtr_to(KQTabBar *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTabBar]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTabBar]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTabBar_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTabBar *qp = RawPtr_to(KQTabBar *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTabBar]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTabBar]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTabBar_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTabBar *qp = (KQTabBar *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTabBar_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 3;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQTabBar *qp = (KQTabBar *)p->rawptr;
//		(void)qp;
		if (qp->dummy->current_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->current_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->tab_close_requested_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->tab_close_requested_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->tab_moved_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->tab_moved_func);
			KNH_SIZEREF(ctx);
		}
	}
}

static int QTabBar_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTabBar::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQTabBar::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QTabBar::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQTabBar(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTabBar";
	cdef->free = QTabBar_free;
	cdef->reftrace = QTabBar_reftrace;
	cdef->compareTo = QTabBar_compareTo;
}

static knh_IntData_t QTabBarConstInt[] = {
	{"LeftSide", QTabBar::LeftSide},
	{"RightSide", QTabBar::RightSide},
	{"SelectLeftTab", QTabBar::SelectLeftTab},
	{"SelectRightTab", QTabBar::SelectRightTab},
	{"SelectPreviousTab", QTabBar::SelectPreviousTab},
	{"RoundedNorth", QTabBar::RoundedNorth},
	{"RoundedSouth", QTabBar::RoundedSouth},
	{"RoundedWest", QTabBar::RoundedWest},
	{"RoundedEast", QTabBar::RoundedEast},
	{"TriangularNorth", QTabBar::TriangularNorth},
	{"TriangularSouth", QTabBar::TriangularSouth},
	{"TriangularWest", QTabBar::TriangularWest},
	{"TriangularEast", QTabBar::TriangularEast},
	{NULL, 0}
};

DEFAPI(void) constQTabBar(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTabBarConstInt);
}

