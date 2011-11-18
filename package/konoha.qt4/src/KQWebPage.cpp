//@Virtual @Override boolean QWebPage.event(QEvent ev);
KMETHOD QWebPage_event(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QEvent*  ev = RawPtr_to(QEvent*, sfp[1]);
		bool ret_v = qp->event(ev);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QWebPage QWebPage.new(QObject parent);
KMETHOD QWebPage_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQWebPage *ret_v = new KQWebPage(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QAction QWebPage.action(int action);
KMETHOD QWebPage_action(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QWebPage::WebAction action = Int_to(QWebPage::WebAction, sfp[1]);
		QAction* ret_v = qp->action(action);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWebPage.bytesReceived();
KMETHOD QWebPage_bytesReceived(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		quint64 ret_v = qp->bytesReceived();
		quint64 *ret_v_ = new quint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QMenu QWebPage.createStandardContextMenu();
KMETHOD QWebPage_createStandardContextMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QMenu* ret_v = qp->createStandardContextMenu();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMenu*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebFrame QWebPage.currentFrame();
KMETHOD QWebPage_currentFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QWebFrame* ret_v = qp->currentFrame();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebFrame*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QWebPage.findText(String subString, QWebPageFindFlags options);
KMETHOD QWebPage_findText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		const QString subString = String_to(const QString, sfp[1]);
		initFlag(options, QWebPage::FindFlags, sfp[2]);
		bool ret_v = qp->findText(subString, options);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWebPage.focusNextPrevChild(boolean next);
KMETHOD QWebPage_focusNextPrevChild(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		bool next = Boolean_to(bool, sfp[1]);
		bool ret_v = qp->focusNextPrevChild(next);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWebPage.getForwardUnsupportedContent();
KMETHOD QWebPage_getForwardUnsupportedContent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		bool ret_v = qp->forwardUnsupportedContent();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QWebFrame QWebPage.frameAt(QPoint pos);
KMETHOD QWebPage_frameAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		QWebFrame* ret_v = qp->frameAt(pos);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebFrame*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebHistory QWebPage.history();
KMETHOD QWebPage_history(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QWebHistory* ret_v = qp->history();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebHistory*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QVariant QWebPage.inputMethodQuery(int property);
KMETHOD QWebPage_inputMethodQuery(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		Qt::InputMethodQuery property = Int_to(Qt::InputMethodQuery, sfp[1]);
		QVariant ret_v = qp->inputMethodQuery(property);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QWebPage.isContentEditable();
KMETHOD QWebPage_isContentEditable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isContentEditable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWebPage.isModified();
KMETHOD QWebPage_isModified(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isModified();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QWebPage.getLinkDelegationPolicy();
KMETHOD QWebPage_getLinkDelegationPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QWebPage::LinkDelegationPolicy ret_v = qp->linkDelegationPolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWebFrame QWebPage.mainFrame();
KMETHOD QWebPage_mainFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QWebFrame* ret_v = qp->mainFrame();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebFrame*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkAccessManager QWebPage.getNetworkAccessManager();
KMETHOD QWebPage_getNetworkAccessManager(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QNetworkAccessManager* ret_v = qp->networkAccessManager();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QNetworkAccessManager*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPalette QWebPage.getPalette();
KMETHOD QWebPage_getPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QPalette ret_v = qp->palette();
		QPalette *ret_v_ = new QPalette(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebPluginFactory QWebPage.getPluginFactory();
KMETHOD QWebPage_getPluginFactory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QWebPluginFactory* ret_v = qp->pluginFactory();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebPluginFactory*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSize QWebPage.getPreferredContentsSize();
KMETHOD QWebPage_getPreferredContentsSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->preferredContentsSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebPage.selectedText();
KMETHOD QWebPage_selectedText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QString ret_v = qp->selectedText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebPage.setContentEditable(boolean editable);
KMETHOD QWebPage_setContentEditable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		bool editable = Boolean_to(bool, sfp[1]);
		qp->setContentEditable(editable);
	}
	RETURNvoid_();
}

//void QWebPage.setForwardUnsupportedContent(boolean forward);
KMETHOD QWebPage_setForwardUnsupportedContent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		bool forward = Boolean_to(bool, sfp[1]);
		qp->setForwardUnsupportedContent(forward);
	}
	RETURNvoid_();
}

//void QWebPage.setLinkDelegationPolicy(int policy);
KMETHOD QWebPage_setLinkDelegationPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QWebPage::LinkDelegationPolicy policy = Int_to(QWebPage::LinkDelegationPolicy, sfp[1]);
		qp->setLinkDelegationPolicy(policy);
	}
	RETURNvoid_();
}

//void QWebPage.setNetworkAccessManager(QNetworkAccessManager manager);
KMETHOD QWebPage_setNetworkAccessManager(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QNetworkAccessManager*  manager = RawPtr_to(QNetworkAccessManager*, sfp[1]);
		qp->setNetworkAccessManager(manager);
	}
	RETURNvoid_();
}

//void QWebPage.setPalette(QPalette palette);
KMETHOD QWebPage_setPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		const QPalette  palette = *RawPtr_to(const QPalette *, sfp[1]);
		qp->setPalette(palette);
	}
	RETURNvoid_();
}

//void QWebPage.setPluginFactory(QWebPluginFactory factory);
KMETHOD QWebPage_setPluginFactory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QWebPluginFactory*  factory = RawPtr_to(QWebPluginFactory*, sfp[1]);
		qp->setPluginFactory(factory);
	}
	RETURNvoid_();
}

//void QWebPage.setPreferredContentsSize(QSize size);
KMETHOD QWebPage_setPreferredContentsSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		qp->setPreferredContentsSize(size);
	}
	RETURNvoid_();
}

//void QWebPage.setView(QWidget view);
KMETHOD QWebPage_setView(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QWidget*  view = RawPtr_to(QWidget*, sfp[1]);
		qp->setView(view);
	}
	RETURNvoid_();
}

//void QWebPage.setViewportSize(QSize size);
KMETHOD QWebPage_setViewportSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		qp->setViewportSize(size);
	}
	RETURNvoid_();
}

//QWebSettings QWebPage.settings();
KMETHOD QWebPage_settings(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QWebSettings* ret_v = qp->settings();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebSettings*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual boolean QWebPage.supportsExtension(int extension);
KMETHOD QWebPage_supportsExtension(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QWebPage::Extension extension = Int_to(QWebPage::Extension, sfp[1]);
		bool ret_v = qp->supportsExtension(extension);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWebPage.swallowContextMenuEvent(QContextMenuEvent event);
KMETHOD QWebPage_swallowContextMenuEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QContextMenuEvent*  event = RawPtr_to(QContextMenuEvent*, sfp[1]);
		bool ret_v = qp->swallowContextMenuEvent(event);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QWebPage.totalBytes();
KMETHOD QWebPage_totalBytes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		quint64 ret_v = qp->totalBytes();
		quint64 *ret_v_ = new quint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QWebPage.triggerAction(int action, boolean checked);
KMETHOD QWebPage_triggerAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QWebPage::WebAction action = Int_to(QWebPage::WebAction, sfp[1]);
		bool checked = Boolean_to(bool, sfp[2]);
		qp->triggerAction(action, checked);
	}
	RETURNvoid_();
}

//QUndoStack QWebPage.undoStack();
KMETHOD QWebPage_undoStack(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QUndoStack* ret_v = qp->undoStack();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QUndoStack*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebPage.updatePositionDependentActions(QPoint pos);
KMETHOD QWebPage_updatePositionDependentActions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		qp->updatePositionDependentActions(pos);
	}
	RETURNvoid_();
}

//QWidget QWebPage.getView();
KMETHOD QWebPage_getView(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->view();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSize QWebPage.getViewportSize();
KMETHOD QWebPage_getViewportSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->viewportSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QWebPage.shouldInterruptJavaScript();
KMETHOD QWebPage_shouldInterruptJavaScript(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage *  qp = RawPtr_to(QWebPage *, sfp[0]);
	if (qp) {
		bool ret_v = qp->shouldInterruptJavaScript();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQWebPage::DummyQWebPage()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	contents_changed_func = NULL;
	database_quota_exceeded_func = NULL;
	download_requested_func = NULL;
	frame_created_func = NULL;
	geometry_change_requested_func = NULL;
	link_clicked_func = NULL;
	link_hovered_func = NULL;
	load_finished_func = NULL;
	load_progress_func = NULL;
	load_started_func = NULL;
	menu_bar_visibility_change_requested_func = NULL;
	micro_focus_changed_func = NULL;
	print_requested_func = NULL;
	repaint_requested_func = NULL;
	restore_frame_state_requested_func = NULL;
	save_frame_state_requested_func = NULL;
	scroll_requested_func = NULL;
	selection_changed_func = NULL;
	status_bar_message_func = NULL;
	status_bar_visibility_change_requested_func = NULL;
	tool_bar_visibility_change_requested_func = NULL;
	unsupported_content_func = NULL;
	window_close_requested_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("contents-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("database-quota-exceeded", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("download-requested", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("frame-created", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("geometry-change-requested", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("link-clicked", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("link-hovered", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("load-finished", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("load-progress", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("load-started", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("menu-bar-visibility-change-requested", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("micro-focus-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("print-requested", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("repaint-requested", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("restore-frame-state-requested", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("save-frame-state-requested", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("scroll-requested", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("selection-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("status-bar-message", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("status-bar-visibility-change-requested", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("tool-bar-visibility-change-requested", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("unsupported-content", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("window-close-requested", NULL));
}
DummyQWebPage::~DummyQWebPage()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQWebPage::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWebPage::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQWebPage::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQWebPage::contentsChangedSlot()
{
	if (contents_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, contents_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQWebPage::databaseQuotaExceededSlot(QWebFrame* frame, QString databaseName)
{
	if (database_quota_exceeded_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QWebFrame, frame);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_RawPtr_t *p2 = new_QRawPtr(lctx, QString, databaseName);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		knh_Func_invoke(lctx, database_quota_exceeded_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQWebPage::downloadRequestedSlot(const QNetworkRequest request)
{
	if (download_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QNetworkRequest, request);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, download_requested_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWebPage::frameCreatedSlot(QWebFrame* frame)
{
	if (frame_created_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QWebFrame, frame);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, frame_created_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWebPage::geometryChangeRequestedSlot(const QRect geom)
{
	if (geometry_change_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QRect, geom);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, geometry_change_requested_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWebPage::linkClickedSlot(const QUrl url)
{
	if (link_clicked_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QUrl, url);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, link_clicked_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWebPage::linkHoveredSlot(const QString link, const QString title, const QString textContent)
{
	if (link_hovered_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QString, link);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_RawPtr_t *p2 = new_QRawPtr(lctx, QString, title);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		knh_RawPtr_t *p3 = new_QRawPtr(lctx, QString, textContent);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+4].o, UPCAST(p3));
		knh_Func_invoke(lctx, link_hovered_func, lsfp, 4);
		return true;
	}
	return false;
}

bool DummyQWebPage::loadFinishedSlot(bool ok)
{
	if (load_finished_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = ok;
		knh_Func_invoke(lctx, load_finished_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWebPage::loadProgressSlot(int progress)
{
	if (load_progress_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = progress;
		knh_Func_invoke(lctx, load_progress_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWebPage::loadStartedSlot()
{
	if (load_started_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, load_started_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQWebPage::menuBarVisibilityChangeRequestedSlot(bool visible)
{
	if (menu_bar_visibility_change_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = visible;
		knh_Func_invoke(lctx, menu_bar_visibility_change_requested_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWebPage::microFocusChangedSlot()
{
	if (micro_focus_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, micro_focus_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQWebPage::printRequestedSlot(QWebFrame* frame)
{
	if (print_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QWebFrame, frame);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, print_requested_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWebPage::repaintRequestedSlot(const QRect dirtyRect)
{
	if (repaint_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QRect, dirtyRect);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, repaint_requested_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWebPage::restoreFrameStateRequestedSlot(QWebFrame* frame)
{
	if (restore_frame_state_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QWebFrame, frame);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, restore_frame_state_requested_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWebPage::saveFrameStateRequestedSlot(QWebFrame* frame, QWebHistoryItem* item)
{
	if (save_frame_state_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QWebFrame, frame);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_RawPtr_t *p2 = new_QRawPtr(lctx, QWebHistoryItem, item);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		knh_Func_invoke(lctx, save_frame_state_requested_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQWebPage::scrollRequestedSlot(int dx, int dy, const QRect rectToScroll)
{
	if (scroll_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = dx;
		lsfp[K_CALLDELTA+3].ivalue = dy;
		knh_RawPtr_t *p3 = new_QRawPtr(lctx, QRect, rectToScroll);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+4].o, UPCAST(p3));
		knh_Func_invoke(lctx, scroll_requested_func, lsfp, 4);
		return true;
	}
	return false;
}

bool DummyQWebPage::selectionChangedSlot()
{
	if (selection_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, selection_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQWebPage::statusBarMessageSlot(const QString text)
{
	if (status_bar_message_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QString, text);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, status_bar_message_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWebPage::statusBarVisibilityChangeRequestedSlot(bool visible)
{
	if (status_bar_visibility_change_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = visible;
		knh_Func_invoke(lctx, status_bar_visibility_change_requested_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWebPage::toolBarVisibilityChangeRequestedSlot(bool visible)
{
	if (tool_bar_visibility_change_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = visible;
		knh_Func_invoke(lctx, tool_bar_visibility_change_requested_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWebPage::unsupportedContentSlot(QNetworkReply* reply)
{
	if (unsupported_content_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QNetworkReply, reply);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, unsupported_content_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWebPage::windowCloseRequestedSlot()
{
	if (window_close_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, window_close_requested_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQWebPage::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebPage::event_map->bigin();
	if ((itr = DummyQWebPage::event_map->find(str)) == DummyQWebPage::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWebPage::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebPage::slot_map->bigin();
	if ((itr = DummyQWebPage::slot_map->find(str)) == DummyQWebPage::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		contents_changed_func = (*slot_map)["contents-changed"];
		database_quota_exceeded_func = (*slot_map)["database-quota-exceeded"];
		download_requested_func = (*slot_map)["download-requested"];
		frame_created_func = (*slot_map)["frame-created"];
		geometry_change_requested_func = (*slot_map)["geometry-change-requested"];
		link_clicked_func = (*slot_map)["link-clicked"];
		link_hovered_func = (*slot_map)["link-hovered"];
		load_finished_func = (*slot_map)["load-finished"];
		load_progress_func = (*slot_map)["load-progress"];
		load_started_func = (*slot_map)["load-started"];
		menu_bar_visibility_change_requested_func = (*slot_map)["menu-bar-visibility-change-requested"];
		micro_focus_changed_func = (*slot_map)["micro-focus-changed"];
		print_requested_func = (*slot_map)["print-requested"];
		repaint_requested_func = (*slot_map)["repaint-requested"];
		restore_frame_state_requested_func = (*slot_map)["restore-frame-state-requested"];
		save_frame_state_requested_func = (*slot_map)["save-frame-state-requested"];
		scroll_requested_func = (*slot_map)["scroll-requested"];
		selection_changed_func = (*slot_map)["selection-changed"];
		status_bar_message_func = (*slot_map)["status-bar-message"];
		status_bar_visibility_change_requested_func = (*slot_map)["status-bar-visibility-change-requested"];
		tool_bar_visibility_change_requested_func = (*slot_map)["tool-bar-visibility-change-requested"];
		unsupported_content_func = (*slot_map)["unsupported-content"];
		window_close_requested_func = (*slot_map)["window-close-requested"];
		return true;
	}
}

knh_Object_t** DummyQWebPage::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQWebPage::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 24;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, contents_changed_func);
	KNH_ADDNNREF(ctx, database_quota_exceeded_func);
	KNH_ADDNNREF(ctx, download_requested_func);
	KNH_ADDNNREF(ctx, frame_created_func);
	KNH_ADDNNREF(ctx, geometry_change_requested_func);
	KNH_ADDNNREF(ctx, link_clicked_func);
	KNH_ADDNNREF(ctx, link_hovered_func);
	KNH_ADDNNREF(ctx, load_finished_func);
	KNH_ADDNNREF(ctx, load_progress_func);
	KNH_ADDNNREF(ctx, load_started_func);
	KNH_ADDNNREF(ctx, menu_bar_visibility_change_requested_func);
	KNH_ADDNNREF(ctx, micro_focus_changed_func);
	KNH_ADDNNREF(ctx, print_requested_func);
	KNH_ADDNNREF(ctx, repaint_requested_func);
	KNH_ADDNNREF(ctx, restore_frame_state_requested_func);
	KNH_ADDNNREF(ctx, save_frame_state_requested_func);
	KNH_ADDNNREF(ctx, scroll_requested_func);
	KNH_ADDNNREF(ctx, selection_changed_func);
	KNH_ADDNNREF(ctx, status_bar_message_func);
	KNH_ADDNNREF(ctx, status_bar_visibility_change_requested_func);
	KNH_ADDNNREF(ctx, tool_bar_visibility_change_requested_func);
	KNH_ADDNNREF(ctx, unsupported_content_func);
	KNH_ADDNNREF(ctx, window_close_requested_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQWebPage::connection(QObject *o)
{
	QWebPage *p = dynamic_cast<QWebPage*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(contentsChanged()), this, SLOT(contentsChangedSlot()));
		connect(p, SIGNAL(databaseQuotaExceeded(QWebFrame*, QString)), this, SLOT(databaseQuotaExceededSlot(QWebFrame*, QString)));
		connect(p, SIGNAL(downloadRequested(const QNetworkRequest)), this, SLOT(downloadRequestedSlot(const QNetworkRequest)));
		connect(p, SIGNAL(frameCreated(QWebFrame*)), this, SLOT(frameCreatedSlot(QWebFrame*)));
		connect(p, SIGNAL(geometryChangeRequested(const QRect)), this, SLOT(geometryChangeRequestedSlot(const QRect)));
		connect(p, SIGNAL(linkClicked(const QUrl)), this, SLOT(linkClickedSlot(const QUrl)));
		connect(p, SIGNAL(linkHovered(const QString, const QString, const QString)), this, SLOT(linkHoveredSlot(const QString, const QString, const QString)));
		connect(p, SIGNAL(loadFinished(bool)), this, SLOT(loadFinishedSlot(bool)));
		connect(p, SIGNAL(loadProgress(int)), this, SLOT(loadProgressSlot(int)));
		connect(p, SIGNAL(loadStarted()), this, SLOT(loadStartedSlot()));
		connect(p, SIGNAL(menuBarVisibilityChangeRequested(bool)), this, SLOT(menuBarVisibilityChangeRequestedSlot(bool)));
		connect(p, SIGNAL(microFocusChanged()), this, SLOT(microFocusChangedSlot()));
		connect(p, SIGNAL(printRequested(QWebFrame*)), this, SLOT(printRequestedSlot(QWebFrame*)));
		connect(p, SIGNAL(repaintRequested(const QRect)), this, SLOT(repaintRequestedSlot(const QRect)));
		connect(p, SIGNAL(restoreFrameStateRequested(QWebFrame*)), this, SLOT(restoreFrameStateRequestedSlot(QWebFrame*)));
		connect(p, SIGNAL(saveFrameStateRequested(QWebFrame*, QWebHistoryItem*)), this, SLOT(saveFrameStateRequestedSlot(QWebFrame*, QWebHistoryItem*)));
		connect(p, SIGNAL(scrollRequested(int, int, const QRect)), this, SLOT(scrollRequestedSlot(int, int, const QRect)));
		connect(p, SIGNAL(selectionChanged()), this, SLOT(selectionChangedSlot()));
		connect(p, SIGNAL(statusBarMessage(const QString)), this, SLOT(statusBarMessageSlot(const QString)));
		connect(p, SIGNAL(statusBarVisibilityChangeRequested(bool)), this, SLOT(statusBarVisibilityChangeRequestedSlot(bool)));
		connect(p, SIGNAL(toolBarVisibilityChangeRequested(bool)), this, SLOT(toolBarVisibilityChangeRequestedSlot(bool)));
		connect(p, SIGNAL(unsupportedContent(QNetworkReply*)), this, SLOT(unsupportedContentSlot(QNetworkReply*)));
		connect(p, SIGNAL(windowCloseRequested()), this, SLOT(windowCloseRequestedSlot()));
	}
	DummyQObject::connection(o);
}

KQWebPage::KQWebPage(QObject* parent) : QWebPage(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQWebPage();
	dummy->connection((QObject*)this);
}

KQWebPage::~KQWebPage()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QWebPage_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebPage *qp = RawPtr_to(KQWebPage *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWebPage]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebPage]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWebPage_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebPage *qp = RawPtr_to(KQWebPage *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWebPage]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebPage]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWebPage_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQWebPage *qp = (KQWebPage *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QWebPage*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QWebPage_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQWebPage *qp = (KQWebPage *)p->rawptr;
		KQWebPage *qp = static_cast<KQWebPage*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWebPage_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWebPage::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQWebPage::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QWebPage::event(event);
		return false;
	}
//	QWebPage::event(event);
	return true;
}

static knh_IntData_t QWebPageConstInt[] = {
	{"QtNetwork", QWebPage::QtNetwork},
	{"Http", QWebPage::Http},
	{"WebKit", QWebPage::WebKit},
	{"ChooseMultipleFilesExtension", QWebPage::ChooseMultipleFilesExtension},
	{"ErrorPageExtension", QWebPage::ErrorPageExtension},
	{"FindBackward", QWebPage::FindBackward},
	{"FindCaseSensitively", QWebPage::FindCaseSensitively},
	{"FindWrapsAroundDocument", QWebPage::FindWrapsAroundDocument},
	{"HighlightAllOccurrences", QWebPage::HighlightAllOccurrences},
	{"DontDelegateLinks", QWebPage::DontDelegateLinks},
	{"DelegateExternalLinks", QWebPage::DelegateExternalLinks},
	{"DelegateAllLinks", QWebPage::DelegateAllLinks},
	{"NavigationTypeLinkClicked", QWebPage::NavigationTypeLinkClicked},
	{"NavigationTypeFormSubmitted", QWebPage::NavigationTypeFormSubmitted},
	{"NavigationTypeBackOrForward", QWebPage::NavigationTypeBackOrForward},
	{"NavigationTypeReload", QWebPage::NavigationTypeReload},
	{"NavigationTypeFormResubmitted", QWebPage::NavigationTypeFormResubmitted},
	{"NavigationTypeOther", QWebPage::NavigationTypeOther},
	{"NoWebAction", QWebPage::NoWebAction},
	{"OpenLink", QWebPage::OpenLink},
	{"OpenLinkInNewWindow", QWebPage::OpenLinkInNewWindow},
	{"OpenFrameInNewWindow", QWebPage::OpenFrameInNewWindow},
	{"DownloadLinkToDisk", QWebPage::DownloadLinkToDisk},
	{"CopyLinkToClipboard", QWebPage::CopyLinkToClipboard},
	{"OpenImageInNewWindow", QWebPage::OpenImageInNewWindow},
	{"DownloadImageToDisk", QWebPage::DownloadImageToDisk},
	{"CopyImageToClipboard", QWebPage::CopyImageToClipboard},
	{"Back", QWebPage::Back},
	{"Forward", QWebPage::Forward},
	{"Stop", QWebPage::Stop},
	{"StopScheduledPageRefresh", QWebPage::StopScheduledPageRefresh},
	{"Reload", QWebPage::Reload},
	{"ReloadAndBypassCache", QWebPage::ReloadAndBypassCache},
	{"Cut", QWebPage::Cut},
	{"Copy", QWebPage::Copy},
	{"Paste", QWebPage::Paste},
	{"Undo", QWebPage::Undo},
	{"Redo", QWebPage::Redo},
	{"MoveToNextChar", QWebPage::MoveToNextChar},
	{"MoveToPreviousChar", QWebPage::MoveToPreviousChar},
	{"MoveToNextWord", QWebPage::MoveToNextWord},
	{"MoveToPreviousWord", QWebPage::MoveToPreviousWord},
	{"MoveToNextLine", QWebPage::MoveToNextLine},
	{"MoveToPreviousLine", QWebPage::MoveToPreviousLine},
	{"MoveToStartOfLine", QWebPage::MoveToStartOfLine},
	{"MoveToEndOfLine", QWebPage::MoveToEndOfLine},
	{"MoveToStartOfBlock", QWebPage::MoveToStartOfBlock},
	{"MoveToEndOfBlock", QWebPage::MoveToEndOfBlock},
	{"MoveToStartOfDocument", QWebPage::MoveToStartOfDocument},
	{"MoveToEndOfDocument", QWebPage::MoveToEndOfDocument},
	{"SelectNextChar", QWebPage::SelectNextChar},
	{"SelectPreviousChar", QWebPage::SelectPreviousChar},
	{"SelectNextWord", QWebPage::SelectNextWord},
	{"SelectPreviousWord", QWebPage::SelectPreviousWord},
	{"SelectNextLine", QWebPage::SelectNextLine},
	{"SelectPreviousLine", QWebPage::SelectPreviousLine},
	{"SelectStartOfLine", QWebPage::SelectStartOfLine},
	{"SelectEndOfLine", QWebPage::SelectEndOfLine},
	{"SelectStartOfBlock", QWebPage::SelectStartOfBlock},
	{"SelectEndOfBlock", QWebPage::SelectEndOfBlock},
	{"SelectStartOfDocument", QWebPage::SelectStartOfDocument},
	{"SelectEndOfDocument", QWebPage::SelectEndOfDocument},
	{"DeleteStartOfWord", QWebPage::DeleteStartOfWord},
	{"DeleteEndOfWord", QWebPage::DeleteEndOfWord},
	{"SetTextDirectionDefault", QWebPage::SetTextDirectionDefault},
	{"SetTextDirectionLeftToRight", QWebPage::SetTextDirectionLeftToRight},
	{"SetTextDirectionRightToLeft", QWebPage::SetTextDirectionRightToLeft},
	{"ToggleBold", QWebPage::ToggleBold},
	{"ToggleItalic", QWebPage::ToggleItalic},
	{"ToggleUnderline", QWebPage::ToggleUnderline},
	{"InspectElement", QWebPage::InspectElement},
	{"InsertParagraphSeparator", QWebPage::InsertParagraphSeparator},
	{"InsertLineSeparator", QWebPage::InsertLineSeparator},
	{"SelectAll", QWebPage::SelectAll},
	{"PasteAndMatchStyle", QWebPage::PasteAndMatchStyle},
	{"RemoveFormat", QWebPage::RemoveFormat},
	{"ToggleStrikethrough", QWebPage::ToggleStrikethrough},
	{"ToggleSubscript", QWebPage::ToggleSubscript},
	{"ToggleSuperscript", QWebPage::ToggleSuperscript},
	{"InsertUnorderedList", QWebPage::InsertUnorderedList},
	{"InsertOrderedList", QWebPage::InsertOrderedList},
	{"Indent", QWebPage::Indent},
	{"Outdent", QWebPage::Outdent},
	{"AlignCenter", QWebPage::AlignCenter},
	{"AlignJustified", QWebPage::AlignJustified},
	{"AlignLeft", QWebPage::AlignLeft},
	{"AlignRight", QWebPage::AlignRight},
	{"WebBrowserWindow", QWebPage::WebBrowserWindow},
	{"WebModalDialog", QWebPage::WebModalDialog},
	{NULL, 0}
};

DEFAPI(void) constQWebPage(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QWebPageConstInt);
}


DEFAPI(void) defQWebPage(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWebPage";
	cdef->free = QWebPage_free;
	cdef->reftrace = QWebPage_reftrace;
	cdef->compareTo = QWebPage_compareTo;
}

//## QWebPageFindFlags QWebPageFindFlags.new(int value);
KMETHOD QWebPageFindFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QWebPage::FindFlag i = Int_to(QWebPage::FindFlag, sfp[1]);
	QWebPage::FindFlags *ret_v = new QWebPage::FindFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QWebPageFindFlags QWebPageFindFlags.and(int mask);
KMETHOD QWebPageFindFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QWebPage::FindFlags *qp = RawPtr_to(QWebPage::FindFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QWebPage::FindFlags ret = ((*qp) & i);
		QWebPage::FindFlags *ret_ = new QWebPage::FindFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QWebPageFindFlags QWebPageFindFlags.iand(QWebPage::QWebPageFindFlags other);
KMETHOD QWebPageFindFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QWebPage::FindFlags *qp = RawPtr_to(QWebPage::FindFlags*, sfp[0]);
	if (qp != NULL) {
		QWebPage::FindFlags *other = RawPtr_to(QWebPage::FindFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QWebPageFindFlags QWebPageFindFlags.or(QWebPageFindFlags f);
KMETHOD QWebPageFindFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage::FindFlags *qp = RawPtr_to(QWebPage::FindFlags*, sfp[0]);
	if (qp != NULL) {
		QWebPage::FindFlags *f = RawPtr_to(QWebPage::FindFlags*, sfp[1]);
		QWebPage::FindFlags ret = ((*qp) | (*f));
		QWebPage::FindFlags *ret_ = new QWebPage::FindFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QWebPageFindFlags QWebPageFindFlags.ior(QWebPage::QWebPageFindFlags other);
KMETHOD QWebPageFindFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QWebPage::FindFlags *qp = RawPtr_to(QWebPage::FindFlags*, sfp[0]);
	if (qp != NULL) {
		QWebPage::FindFlags *other = RawPtr_to(QWebPage::FindFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QWebPageFindFlags QWebPageFindFlags.xor(QWebPageFindFlags f);
KMETHOD QWebPageFindFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebPage::FindFlags *qp = RawPtr_to(QWebPage::FindFlags*, sfp[0]);
	if (qp != NULL) {
		QWebPage::FindFlags *f = RawPtr_to(QWebPage::FindFlags*, sfp[1]);
		QWebPage::FindFlags ret = ((*qp) ^ (*f));
		QWebPage::FindFlags *ret_ = new QWebPage::FindFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QWebPageFindFlags QWebPageFindFlags.ixor(QWebPage::QWebPageFindFlags other);
KMETHOD QWebPageFindFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QWebPage::FindFlags *qp = RawPtr_to(QWebPage::FindFlags*, sfp[0]);
	if (qp != NULL) {
		QWebPage::FindFlags *other = RawPtr_to(QWebPage::FindFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QWebPageFindFlags.testFlag(int flag);
KMETHOD QWebPageFindFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QWebPage::FindFlags *qp = RawPtr_to(QWebPage::FindFlags *, sfp[0]);
	if (qp != NULL) {
		QWebPage::FindFlag flag = Int_to(QWebPage::FindFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QWebPageFindFlags.value();
KMETHOD QWebPageFindFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QWebPage::FindFlags *qp = RawPtr_to(QWebPage::FindFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QWebPageFindFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QWebPage::FindFlags *qp = (QWebPage::FindFlags *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QWebPageFindFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QWebPage::FindFlags *qp = (QWebPage::FindFlags *)p->rawptr;
		(void)qp;
	}
}

static int QWebPageFindFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QWebPage::FindFlags*)p1->rawptr);
//		int v2 = int(*(QWebPage::FindFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QWebPage::FindFlags v1 = *(QWebPage::FindFlags*)p1->rawptr;
		QWebPage::FindFlags v2 = *(QWebPage::FindFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQWebPageFindFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWebPageFindFlags";
	cdef->free = QWebPageFindFlags_free;
	cdef->reftrace = QWebPageFindFlags_reftrace;
	cdef->compareTo = QWebPageFindFlags_compareTo;
}

