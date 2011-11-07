//QMainWindow QMainWindow.new(QWidget parent, QtWindowFlags flags);
KMETHOD QMainWindow_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	initFlag(flags, Qt::WindowFlags, sfp[2]);
	KQMainWindow *ret_v = new KQMainWindow(parent, flags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QMainWindow.addDockWidget(int area, QDockWidget dockwidget);
KMETHOD QMainWindow_addDockWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		Qt::DockWidgetArea area = Int_to(Qt::DockWidgetArea, sfp[1]);
		QDockWidget*  dockwidget = RawPtr_to(QDockWidget*, sfp[2]);
		qp->addDockWidget(area, dockwidget);
	}
	RETURNvoid_();
}

/*
//void QMainWindow.addDockWidget(int area, QDockWidget dockwidget, int orientation);
KMETHOD QMainWindow_addDockWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		Qt::DockWidgetArea area = Int_to(Qt::DockWidgetArea, sfp[1]);
		QDockWidget*  dockwidget = RawPtr_to(QDockWidget*, sfp[2]);
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[3]);
		qp->addDockWidget(area, dockwidget, orientation);
	}
	RETURNvoid_();
}
*/
//void QMainWindow.addToolBar(int area, QToolBar toolbar);
KMETHOD QMainWindow_addToolBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		Qt::ToolBarArea area = Int_to(Qt::ToolBarArea, sfp[1]);
		QToolBar*  toolbar = RawPtr_to(QToolBar*, sfp[2]);
		qp->addToolBar(area, toolbar);
	}
	RETURNvoid_();
}

/*
//void QMainWindow.addToolBar(QToolBar toolbar);
KMETHOD QMainWindow_addToolBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QToolBar*  toolbar = RawPtr_to(QToolBar*, sfp[1]);
		qp->addToolBar(toolbar);
	}
	RETURNvoid_();
}
*/
/*
//QToolBar QMainWindow.addToolBar(String title);
KMETHOD QMainWindow_addToolBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		const QString title = String_to(const QString, sfp[1]);
		QToolBar* ret_v = qp->addToolBar(title);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QToolBar*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//void QMainWindow.addToolBarBreak(int area);
KMETHOD QMainWindow_addToolBarBreak(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		Qt::ToolBarArea area = Int_to(Qt::ToolBarArea, sfp[1]);
		qp->addToolBarBreak(area);
	}
	RETURNvoid_();
}

//QWidget QMainWindow.getCentralWidget();
KMETHOD QMainWindow_getCentralWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->centralWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMainWindow.getCorner(int corner);
KMETHOD QMainWindow_getCorner(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		Qt::Corner corner = Int_to(Qt::Corner, sfp[1]);
		Qt::DockWidgetArea ret_v = qp->corner(corner);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QMenu QMainWindow.createPopupMenu();
KMETHOD QMainWindow_createPopupMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QMenu* ret_v = qp->createPopupMenu();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMenu*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QMainWindowDockOptions QMainWindow.getDockOptions();
KMETHOD QMainWindow_getDockOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QMainWindow::DockOptions ret_v = qp->dockOptions();
		QMainWindow::DockOptions *ret_v_ = new QMainWindow::DockOptions(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMainWindow.dockWidgetArea(QDockWidget dockwidget);
KMETHOD QMainWindow_dockWidgetArea(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QDockWidget*  dockwidget = RawPtr_to(QDockWidget*, sfp[1]);
		Qt::DockWidgetArea ret_v = qp->dockWidgetArea(dockwidget);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QMainWindow.getDocumentMode();
KMETHOD QMainWindow_getDocumentMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		bool ret_v = qp->documentMode();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QSize QMainWindow.getIconSize();
KMETHOD QMainWindow_getIconSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->iconSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QMainWindow.insertToolBar(QToolBar before, QToolBar toolbar);
KMETHOD QMainWindow_insertToolBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QToolBar*  before = RawPtr_to(QToolBar*, sfp[1]);
		QToolBar*  toolbar = RawPtr_to(QToolBar*, sfp[2]);
		qp->insertToolBar(before, toolbar);
	}
	RETURNvoid_();
}

//void QMainWindow.insertToolBarBreak(QToolBar before);
KMETHOD QMainWindow_insertToolBarBreak(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QToolBar*  before = RawPtr_to(QToolBar*, sfp[1]);
		qp->insertToolBarBreak(before);
	}
	RETURNvoid_();
}

//boolean QMainWindow.isAnimated();
KMETHOD QMainWindow_isAnimated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isAnimated();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMainWindow.isDockNestingEnabled();
KMETHOD QMainWindow_isDockNestingEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isDockNestingEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QMenuBar QMainWindow.getMenuBar();
KMETHOD QMainWindow_getMenuBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QMenuBar* ret_v = qp->menuBar();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMenuBar*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QMainWindow.getMenuWidget();
KMETHOD QMainWindow_getMenuWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->menuWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QMainWindow.removeDockWidget(QDockWidget dockwidget);
KMETHOD QMainWindow_removeDockWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QDockWidget*  dockwidget = RawPtr_to(QDockWidget*, sfp[1]);
		qp->removeDockWidget(dockwidget);
	}
	RETURNvoid_();
}

//void QMainWindow.removeToolBar(QToolBar toolbar);
KMETHOD QMainWindow_removeToolBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QToolBar*  toolbar = RawPtr_to(QToolBar*, sfp[1]);
		qp->removeToolBar(toolbar);
	}
	RETURNvoid_();
}

//void QMainWindow.removeToolBarBreak(QToolBar before);
KMETHOD QMainWindow_removeToolBarBreak(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QToolBar*  before = RawPtr_to(QToolBar*, sfp[1]);
		qp->removeToolBarBreak(before);
	}
	RETURNvoid_();
}

//boolean QMainWindow.restoreDockWidget(QDockWidget dockwidget);
KMETHOD QMainWindow_restoreDockWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QDockWidget*  dockwidget = RawPtr_to(QDockWidget*, sfp[1]);
		bool ret_v = qp->restoreDockWidget(dockwidget);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMainWindow.restoreState(QByteArray state, int version);
KMETHOD QMainWindow_restoreState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		const QByteArray  state = *RawPtr_to(const QByteArray *, sfp[1]);
		int version = Int_to(int, sfp[2]);
		bool ret_v = qp->restoreState(state, version);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QByteArray QMainWindow.saveState(int version);
KMETHOD QMainWindow_saveState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		int version = Int_to(int, sfp[1]);
		QByteArray ret_v = qp->saveState(version);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QMainWindow.setCentralWidget(QWidget widget);
KMETHOD QMainWindow_setCentralWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setCentralWidget(widget);
	}
	RETURNvoid_();
}

//void QMainWindow.setCorner(int corner, int area);
KMETHOD QMainWindow_setCorner(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		Qt::Corner corner = Int_to(Qt::Corner, sfp[1]);
		Qt::DockWidgetArea area = Int_to(Qt::DockWidgetArea, sfp[2]);
		qp->setCorner(corner, area);
	}
	RETURNvoid_();
}

//void QMainWindow.setDockOptions(QMainWindowDockOptions options);
KMETHOD QMainWindow_setDockOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		initFlag(options, QMainWindow::DockOptions, sfp[1]);
		qp->setDockOptions(options);
	}
	RETURNvoid_();
}

//void QMainWindow.setDocumentMode(boolean enabled);
KMETHOD QMainWindow_setDocumentMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setDocumentMode(enabled);
	}
	RETURNvoid_();
}

//void QMainWindow.setIconSize(QSize iconSize);
KMETHOD QMainWindow_setIconSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		const QSize  iconSize = *RawPtr_to(const QSize *, sfp[1]);
		qp->setIconSize(iconSize);
	}
	RETURNvoid_();
}

//void QMainWindow.setMenuBar(QMenuBar menuBar);
KMETHOD QMainWindow_setMenuBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QMenuBar*  menuBar = RawPtr_to(QMenuBar*, sfp[1]);
		qp->setMenuBar(menuBar);
	}
	RETURNvoid_();
}

//void QMainWindow.setMenuWidget(QWidget menuBar);
KMETHOD QMainWindow_setMenuWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QWidget*  menuBar = RawPtr_to(QWidget*, sfp[1]);
		qp->setMenuWidget(menuBar);
	}
	RETURNvoid_();
}

//void QMainWindow.setStatusBar(QStatusBar statusbar);
KMETHOD QMainWindow_setStatusBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QStatusBar*  statusbar = RawPtr_to(QStatusBar*, sfp[1]);
		qp->setStatusBar(statusbar);
	}
	RETURNvoid_();
}

//void QMainWindow.setTabPosition(QtDockWidgetAreas areas, int tabPosition);
KMETHOD QMainWindow_setTabPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		initFlag(areas, Qt::DockWidgetAreas, sfp[1]);
		QTabWidget::TabPosition tabPosition = Int_to(QTabWidget::TabPosition, sfp[2]);
		qp->setTabPosition(areas, tabPosition);
	}
	RETURNvoid_();
}

//void QMainWindow.setTabShape(int tabShape);
KMETHOD QMainWindow_setTabShape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QTabWidget::TabShape tabShape = Int_to(QTabWidget::TabShape, sfp[1]);
		qp->setTabShape(tabShape);
	}
	RETURNvoid_();
}

//void QMainWindow.setToolButtonStyle(int toolButtonStyle);
KMETHOD QMainWindow_setToolButtonStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		Qt::ToolButtonStyle toolButtonStyle = Int_to(Qt::ToolButtonStyle, sfp[1]);
		qp->setToolButtonStyle(toolButtonStyle);
	}
	RETURNvoid_();
}

//void QMainWindow.setUnifiedTitleAndToolBarOnMac(boolean set);
KMETHOD QMainWindow_setUnifiedTitleAndToolBarOnMac(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		bool set = Boolean_to(bool, sfp[1]);
		qp->setUnifiedTitleAndToolBarOnMac(set);
	}
	RETURNvoid_();
}

//void QMainWindow.splitDockWidget(QDockWidget first, QDockWidget second, int orientation);
KMETHOD QMainWindow_splitDockWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QDockWidget*  first = RawPtr_to(QDockWidget*, sfp[1]);
		QDockWidget*  second = RawPtr_to(QDockWidget*, sfp[2]);
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[3]);
		qp->splitDockWidget(first, second, orientation);
	}
	RETURNvoid_();
}

//QStatusBar QMainWindow.getStatusBar();
KMETHOD QMainWindow_getStatusBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QStatusBar* ret_v = qp->statusBar();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QStatusBar*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMainWindow.getTabPosition(int area);
KMETHOD QMainWindow_getTabPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		Qt::DockWidgetArea area = Int_to(Qt::DockWidgetArea, sfp[1]);
		QTabWidget::TabPosition ret_v = qp->tabPosition(area);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMainWindow.getTabShape();
KMETHOD QMainWindow_getTabShape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QTabWidget::TabShape ret_v = qp->tabShape();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<QDockWidget> QMainWindow.tabifiedDockWidgets(QDockWidget dockwidget);
KMETHOD QMainWindow_tabifiedDockWidgets(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QDockWidget*  dockwidget = RawPtr_to(QDockWidget*, sfp[1]);
		QList<QDockWidget*> ret_v = qp->tabifiedDockWidgets(dockwidget);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QDockWidget"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//void QMainWindow.tabifyDockWidget(QDockWidget first, QDockWidget second);
KMETHOD QMainWindow_tabifyDockWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QDockWidget*  first = RawPtr_to(QDockWidget*, sfp[1]);
		QDockWidget*  second = RawPtr_to(QDockWidget*, sfp[2]);
		qp->tabifyDockWidget(first, second);
	}
	RETURNvoid_();
}

//int QMainWindow.toolBarArea(QToolBar toolbar);
KMETHOD QMainWindow_toolBarArea(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QToolBar*  toolbar = RawPtr_to(QToolBar*, sfp[1]);
		Qt::ToolBarArea ret_v = qp->toolBarArea(toolbar);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QMainWindow.toolBarBreak(QToolBar toolbar);
KMETHOD QMainWindow_toolBarBreak(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		QToolBar*  toolbar = RawPtr_to(QToolBar*, sfp[1]);
		bool ret_v = qp->toolBarBreak(toolbar);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QMainWindow.getToolButtonStyle();
KMETHOD QMainWindow_getToolButtonStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		Qt::ToolButtonStyle ret_v = qp->toolButtonStyle();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QMainWindow.getUnifiedTitleAndToolBarOnMac();
KMETHOD QMainWindow_getUnifiedTitleAndToolBarOnMac(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		bool ret_v = qp->unifiedTitleAndToolBarOnMac();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QMainWindow.setAnimated(boolean enabled);
KMETHOD QMainWindow_setAnimated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setAnimated(enabled);
	}
	RETURNvoid_();
}

//void QMainWindow.setDockNestingEnabled(boolean enabled);
KMETHOD QMainWindow_setDockNestingEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow *  qp = RawPtr_to(QMainWindow *, sfp[0]);
	if (qp) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setDockNestingEnabled(enabled);
	}
	RETURNvoid_();
}


DummyQMainWindow::DummyQMainWindow()
{
	self = NULL;
	icon_size_changed_func = NULL;
	tool_button_style_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("icon-size-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("tool-button-style-changed", NULL));
}

void DummyQMainWindow::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMainWindow::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQMainWindow::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQMainWindow::iconSizeChangedSlot(const QSize iconSize)
{
	if (icon_size_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QSize, iconSize);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, icon_size_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQMainWindow::toolButtonStyleChangedSlot(Qt::ToolButtonStyle toolButtonStyle)
{
	if (tool_button_style_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = toolButtonStyle;
		knh_Func_invoke(lctx, tool_button_style_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQMainWindow::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMainWindow::event_map->bigin();
	if ((itr = DummyQMainWindow::event_map->find(str)) == DummyQMainWindow::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMainWindow::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMainWindow::slot_map->bigin();
	if ((itr = DummyQMainWindow::slot_map->find(str)) == DummyQMainWindow::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		icon_size_changed_func = (*slot_map)["icon-size-changed"];
		tool_button_style_changed_func = (*slot_map)["tool-button-style-changed"];
		return true;
	}
}

void DummyQMainWindow::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, icon_size_changed_func);
	KNH_ADDNNREF(ctx, tool_button_style_changed_func);

	KNH_SIZEREF(ctx);

	DummyQWidget::reftrace(ctx, p, tail_);
}

void DummyQMainWindow::connection(QObject *o)
{
	QMainWindow *p = dynamic_cast<QMainWindow*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(iconSizeChanged(const QSize)), this, SLOT(iconSizeChangedSlot(const QSize)));
		connect(p, SIGNAL(toolButtonStyleChanged(Qt::ToolButtonStyle)), this, SLOT(toolButtonStyleChangedSlot(Qt::ToolButtonStyle)));
	}
	DummyQWidget::connection(o);
}

KQMainWindow::KQMainWindow(QWidget* parent, Qt::WindowFlags flags) : QMainWindow(parent, flags)
{
	self = NULL;
	dummy = new DummyQMainWindow();
	dummy->connection((QObject*)this);
}

KMETHOD QMainWindow_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMainWindow *qp = RawPtr_to(KQMainWindow *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMainWindow]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMainWindow]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QMainWindow_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMainWindow *qp = RawPtr_to(KQMainWindow *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMainWindow]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMainWindow]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMainWindow_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMainWindow *qp = (KQMainWindow *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMainWindow_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQMainWindow *qp = (KQMainWindow *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QMainWindow_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMainWindow::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQMainWindow::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QMainWindow::event(event);
		return false;
	}
	return true;
}

static knh_IntData_t QMainWindowConstInt[] = {
	{"AnimatedDocks", QMainWindow::AnimatedDocks},
	{"AllowNestedDocks", QMainWindow::AllowNestedDocks},
	{"AllowTabbedDocks", QMainWindow::AllowTabbedDocks},
	{"ForceTabbedDocks", QMainWindow::ForceTabbedDocks},
	{"VerticalTabs", QMainWindow::VerticalTabs},
	{NULL, 0}
};

DEFAPI(void) constQMainWindow(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QMainWindowConstInt);
}


DEFAPI(void) defQMainWindow(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMainWindow";
	cdef->free = QMainWindow_free;
	cdef->reftrace = QMainWindow_reftrace;
	cdef->compareTo = QMainWindow_compareTo;
}

//## QMainWindowDockOptions QMainWindowDockOptions.new(int value);
KMETHOD QMainWindowDockOptions_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMainWindow::DockOption i = Int_to(QMainWindow::DockOption, sfp[1]);
	QMainWindow::DockOptions *ret_v = new QMainWindow::DockOptions(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QMainWindowDockOptions QMainWindowDockOptions.and(int mask);
KMETHOD QMainWindowDockOptions_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMainWindow::DockOptions *qp = RawPtr_to(QMainWindow::DockOptions*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QMainWindow::DockOptions ret = ((*qp) & i);
		QMainWindow::DockOptions *ret_ = new QMainWindow::DockOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMainWindowDockOptions QMainWindowDockOptions.iand(QMainWindow::QMainWindowDockOptions other);
KMETHOD QMainWindowDockOptions_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMainWindow::DockOptions *qp = RawPtr_to(QMainWindow::DockOptions*, sfp[0]);
	if (qp != NULL) {
		QMainWindow::DockOptions *other = RawPtr_to(QMainWindow::DockOptions *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMainWindowDockOptions QMainWindowDockOptions.or(QMainWindowDockOptions f);
KMETHOD QMainWindowDockOptions_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow::DockOptions *qp = RawPtr_to(QMainWindow::DockOptions*, sfp[0]);
	if (qp != NULL) {
		QMainWindow::DockOptions *f = RawPtr_to(QMainWindow::DockOptions*, sfp[1]);
		QMainWindow::DockOptions ret = ((*qp) | (*f));
		QMainWindow::DockOptions *ret_ = new QMainWindow::DockOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMainWindowDockOptions QMainWindowDockOptions.ior(QMainWindow::QMainWindowDockOptions other);
KMETHOD QMainWindowDockOptions_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMainWindow::DockOptions *qp = RawPtr_to(QMainWindow::DockOptions*, sfp[0]);
	if (qp != NULL) {
		QMainWindow::DockOptions *other = RawPtr_to(QMainWindow::DockOptions *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMainWindowDockOptions QMainWindowDockOptions.xor(QMainWindowDockOptions f);
KMETHOD QMainWindowDockOptions_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMainWindow::DockOptions *qp = RawPtr_to(QMainWindow::DockOptions*, sfp[0]);
	if (qp != NULL) {
		QMainWindow::DockOptions *f = RawPtr_to(QMainWindow::DockOptions*, sfp[1]);
		QMainWindow::DockOptions ret = ((*qp) ^ (*f));
		QMainWindow::DockOptions *ret_ = new QMainWindow::DockOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMainWindowDockOptions QMainWindowDockOptions.ixor(QMainWindow::QMainWindowDockOptions other);
KMETHOD QMainWindowDockOptions_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMainWindow::DockOptions *qp = RawPtr_to(QMainWindow::DockOptions*, sfp[0]);
	if (qp != NULL) {
		QMainWindow::DockOptions *other = RawPtr_to(QMainWindow::DockOptions *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QMainWindowDockOptions.testFlag(int flag);
KMETHOD QMainWindowDockOptions_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMainWindow::DockOptions *qp = RawPtr_to(QMainWindow::DockOptions *, sfp[0]);
	if (qp != NULL) {
		QMainWindow::DockOption flag = Int_to(QMainWindow::DockOption, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QMainWindowDockOptions.value();
KMETHOD QMainWindowDockOptions_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMainWindow::DockOptions *qp = RawPtr_to(QMainWindow::DockOptions *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QMainWindowDockOptions_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QMainWindow::DockOptions *qp = (QMainWindow::DockOptions *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QMainWindowDockOptions_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QMainWindow::DockOptions *qp = (QMainWindow::DockOptions *)p->rawptr;
		(void)qp;
	}
}

static int QMainWindowDockOptions_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QMainWindow::DockOptions*)p1->rawptr);
//		int v2 = int(*(QMainWindow::DockOptions*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QMainWindow::DockOptions v1 = *(QMainWindow::DockOptions*)p1->rawptr;
		QMainWindow::DockOptions v2 = *(QMainWindow::DockOptions*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQMainWindowDockOptions(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMainWindowDockOptions";
	cdef->free = QMainWindowDockOptions_free;
	cdef->reftrace = QMainWindowDockOptions_reftrace;
	cdef->compareTo = QMainWindowDockOptions_compareTo;
}

