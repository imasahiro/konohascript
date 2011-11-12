//@Virtual @Override boolean QWebView.event(QEvent e);
KMETHOD QWebView_event(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		QEvent*  e = RawPtr_to(QEvent*, sfp[1]);
		bool ret_v = qp->event(e);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QVariant QWebView.inputMethodQuery(int property);
KMETHOD QWebView_inputMethodQuery(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
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

//@Virtual @Override QSize QWebView.sizeHint();
KMETHOD QWebView_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebView QWebView.new(QWidget parent);
KMETHOD QWebView_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQWebView *ret_v = new KQWebView(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QWebView.findText(String subString, int options);
KMETHOD QWebView_findText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		const QString subString = String_to(const QString, sfp[1]);
		QWebPage::FindFlags options = Int_to(QWebPage::FindFlags, sfp[2]);
		bool ret_v = qp->findText(subString, options);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QWebHistory QWebView.history();
KMETHOD QWebView_history(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		QWebHistory* ret_v = qp->history();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebHistory*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QIcon QWebView.icon();
KMETHOD QWebView_icon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		QIcon ret_v = qp->icon();
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QWebView.isModified();
KMETHOD QWebView_isModified(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isModified();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QWebView.load(QUrl url);
KMETHOD QWebView_load(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
		qp->load(url);
	}
	RETURNvoid_();
}

/*
//void QWebView.load(QNetworkRequest request, int operation, QByteArray body);
KMETHOD QWebView_load(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		const QNetworkRequest  request = *RawPtr_to(const QNetworkRequest *, sfp[1]);
		QNetworkAccessManager::Operation operation = Int_to(QNetworkAccessManager::Operation, sfp[2]);
		const QByteArray  body = *RawPtr_to(const QByteArray *, sfp[3]);
		qp->load(request, operation, body);
	}
	RETURNvoid_();
}
*/
//QWebPage QWebView.getPage();
KMETHOD QWebView_getPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		QWebPage* ret_v = qp->page();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebPage*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAction QWebView.pageAction(int action);
KMETHOD QWebView_pageAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		QWebPage::WebAction action = Int_to(QWebPage::WebAction, sfp[1]);
		QAction* ret_v = qp->pageAction(action);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWebView.getRenderHints();
KMETHOD QWebView_getRenderHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		QPainter::RenderHints ret_v = qp->renderHints();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QWebView.selectedText();
KMETHOD QWebView_selectedText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		QString ret_v = qp->selectedText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebView.setContent(QByteArray data, String mimeType, QUrl baseUrl);
KMETHOD QWebView_setContent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		const QByteArray  data = *RawPtr_to(const QByteArray *, sfp[1]);
		const QString mimeType = String_to(const QString, sfp[2]);
		const QUrl  baseUrl = *RawPtr_to(const QUrl *, sfp[3]);
		qp->setContent(data, mimeType, baseUrl);
	}
	RETURNvoid_();
}

//void QWebView.setHtml(String html, QUrl baseUrl);
KMETHOD QWebView_setHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		const QString html = String_to(const QString, sfp[1]);
		const QUrl  baseUrl = *RawPtr_to(const QUrl *, sfp[2]);
		qp->setHtml(html, baseUrl);
	}
	RETURNvoid_();
}

//void QWebView.setPage(QWebPage page);
KMETHOD QWebView_setPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		QWebPage*  page = RawPtr_to(QWebPage*, sfp[1]);
		qp->setPage(page);
	}
	RETURNvoid_();
}

//void QWebView.setRenderHint(int hint, boolean enabled);
KMETHOD QWebView_setRenderHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		QPainter::RenderHint hint = Int_to(QPainter::RenderHint, sfp[1]);
		bool enabled = Boolean_to(bool, sfp[2]);
		qp->setRenderHint(hint, enabled);
	}
	RETURNvoid_();
}

//void QWebView.setRenderHints(int hints);
KMETHOD QWebView_setRenderHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		QPainter::RenderHints hints = Int_to(QPainter::RenderHints, sfp[1]);
		qp->setRenderHints(hints);
	}
	RETURNvoid_();
}

//void QWebView.setTextSizeMultiplier(float factor);
KMETHOD QWebView_setTextSizeMultiplier(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		qreal factor = Float_to(qreal, sfp[1]);
		qp->setTextSizeMultiplier(factor);
	}
	RETURNvoid_();
}

//void QWebView.setUrl(QUrl url);
KMETHOD QWebView_setUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
		qp->setUrl(url);
	}
	RETURNvoid_();
}

//void QWebView.setZoomFactor(float factor);
KMETHOD QWebView_setZoomFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		qreal factor = Float_to(qreal, sfp[1]);
		qp->setZoomFactor(factor);
	}
	RETURNvoid_();
}

//QWebSettings QWebView.settings();
KMETHOD QWebView_settings(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		QWebSettings* ret_v = qp->settings();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebSettings*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QWebView.getTextSizeMultiplier();
KMETHOD QWebView_getTextSizeMultiplier(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->textSizeMultiplier();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//String QWebView.title();
KMETHOD QWebView_title(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		QString ret_v = qp->title();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebView.triggerPageAction(int action, boolean checked);
KMETHOD QWebView_triggerPageAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		QWebPage::WebAction action = Int_to(QWebPage::WebAction, sfp[1]);
		bool checked = Boolean_to(bool, sfp[2]);
		qp->triggerPageAction(action, checked);
	}
	RETURNvoid_();
}

//QUrl QWebView.getUrl();
KMETHOD QWebView_getUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		QUrl ret_v = qp->url();
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QWebView.getZoomFactor();
KMETHOD QWebView_getZoomFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->zoomFactor();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QWebView.back();
KMETHOD QWebView_back(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		qp->back();
	}
	RETURNvoid_();
}

//void QWebView.forward();
KMETHOD QWebView_forward(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		qp->forward();
	}
	RETURNvoid_();
}

//void QWebView.print(QPrinter printer);
KMETHOD QWebView_print(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		QPrinter*  printer = RawPtr_to(QPrinter*, sfp[1]);
		qp->print(printer);
	}
	RETURNvoid_();
}

//void QWebView.reload();
KMETHOD QWebView_reload(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		qp->reload();
	}
	RETURNvoid_();
}

//void QWebView.stop();
KMETHOD QWebView_stop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebView *  qp = RawPtr_to(QWebView *, sfp[0]);
	if (qp) {
		qp->stop();
	}
	RETURNvoid_();
}


DummyQWebView::DummyQWebView()
{
	self = NULL;
	icon_changed_func = NULL;
	link_clicked_func = NULL;
	load_finished_func = NULL;
	load_progress_func = NULL;
	load_started_func = NULL;
	selection_changed_func = NULL;
	status_bar_message_func = NULL;
	title_changed_func = NULL;
	url_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("icon-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("link-clicked", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("load-finished", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("load-progress", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("load-started", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("selection-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("status-bar-message", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("title-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("url-changed", NULL));
}

void DummyQWebView::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWebView::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQWebView::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQWebView::iconChangedSlot()
{
	if (icon_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, icon_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQWebView::linkClickedSlot(const QUrl url)
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

bool DummyQWebView::loadFinishedSlot(bool ok)
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

bool DummyQWebView::loadProgressSlot(int progress)
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

bool DummyQWebView::loadStartedSlot()
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

bool DummyQWebView::selectionChangedSlot()
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

bool DummyQWebView::statusBarMessageSlot(const QString text)
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

bool DummyQWebView::titleChangedSlot(const QString title)
{
	if (title_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QString, title);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, title_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWebView::urlChangedSlot(const QUrl url)
{
	if (url_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QUrl, url);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, url_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWebView::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebView::event_map->bigin();
	if ((itr = DummyQWebView::event_map->find(str)) == DummyQWebView::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWebView::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebView::slot_map->bigin();
	if ((itr = DummyQWebView::slot_map->find(str)) == DummyQWebView::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		icon_changed_func = (*slot_map)["icon-changed"];
		link_clicked_func = (*slot_map)["link-clicked"];
		load_finished_func = (*slot_map)["load-finished"];
		load_progress_func = (*slot_map)["load-progress"];
		load_started_func = (*slot_map)["load-started"];
		selection_changed_func = (*slot_map)["selection-changed"];
		status_bar_message_func = (*slot_map)["status-bar-message"];
		title_changed_func = (*slot_map)["title-changed"];
		url_changed_func = (*slot_map)["url-changed"];
		return true;
	}
}

knh_Object_t** DummyQWebView::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQWebView::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 9;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, icon_changed_func);
	KNH_ADDNNREF(ctx, link_clicked_func);
	KNH_ADDNNREF(ctx, load_finished_func);
	KNH_ADDNNREF(ctx, load_progress_func);
	KNH_ADDNNREF(ctx, load_started_func);
	KNH_ADDNNREF(ctx, selection_changed_func);
	KNH_ADDNNREF(ctx, status_bar_message_func);
	KNH_ADDNNREF(ctx, title_changed_func);
	KNH_ADDNNREF(ctx, url_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQWidget::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQWebView::connection(QObject *o)
{
	QWebView *p = dynamic_cast<QWebView*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(iconChanged()), this, SLOT(iconChangedSlot()));
		connect(p, SIGNAL(linkClicked(const QUrl)), this, SLOT(linkClickedSlot(const QUrl)));
		connect(p, SIGNAL(loadFinished(bool)), this, SLOT(loadFinishedSlot(bool)));
		connect(p, SIGNAL(loadProgress(int)), this, SLOT(loadProgressSlot(int)));
		connect(p, SIGNAL(loadStarted()), this, SLOT(loadStartedSlot()));
		connect(p, SIGNAL(selectionChanged()), this, SLOT(selectionChangedSlot()));
		connect(p, SIGNAL(statusBarMessage(const QString)), this, SLOT(statusBarMessageSlot(const QString)));
		connect(p, SIGNAL(titleChanged(const QString)), this, SLOT(titleChangedSlot(const QString)));
		connect(p, SIGNAL(urlChanged(const QUrl)), this, SLOT(urlChangedSlot(const QUrl)));
	}
	DummyQWidget::connection(o);
}

KQWebView::KQWebView(QWidget* parent) : QWebView(parent)
{
	self = NULL;
	dummy = new DummyQWebView();
	dummy->connection((QObject*)this);
}

KMETHOD QWebView_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebView *qp = RawPtr_to(KQWebView *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWebView]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebView]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWebView_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebView *qp = RawPtr_to(KQWebView *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWebView]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebView]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWebView_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWebView *qp = (KQWebView *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWebView_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQWebView *qp = (KQWebView *)p->rawptr;
//		KQWebView *qp = static_cast<KQWebView*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWebView_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWebView::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQWebView::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QWebView::event(event);
		return false;
	}
//	QWebView::event(event);
	return true;
}



DEFAPI(void) defQWebView(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWebView";
	cdef->free = QWebView_free;
	cdef->reftrace = QWebView_reftrace;
	cdef->compareTo = QWebView_compareTo;
}


