//@Virtual @Override boolean QGraphicsWebView.event(QEvent event);
KMETHOD QGraphicsWebView_event(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		QEvent*  event = RawPtr_to(QEvent*, sfp[1]);
		bool ret_v = qp->event(event);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QVariant QGraphicsWebView.inputMethodQuery(int query);
KMETHOD QGraphicsWebView_inputMethodQuery(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		Qt::InputMethodQuery query = Int_to(Qt::InputMethodQuery, sfp[1]);
		QVariant ret_v = qp->inputMethodQuery(query);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QVariant QGraphicsWebView.itemChange(int change, QVariant value);
KMETHOD QGraphicsWebView_itemChange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		QGraphicsWebView::GraphicsItemChange change = Int_to(QGraphicsWebView::GraphicsItemChange, sfp[1]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[2]);
		QVariant ret_v = qp->itemChange(change, value);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QGraphicsWebView.setGeometry(QRectF rect);
KMETHOD QGraphicsWebView_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		qp->setGeometry(rect);
	}
	RETURNvoid_();
}

//@Virtual @Override QSizeF QGraphicsWebView.sizeHint(int which, QSizeF constraint);
KMETHOD QGraphicsWebView_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		Qt::SizeHint which = Int_to(Qt::SizeHint, sfp[1]);
		const QSizeF  constraint = *RawPtr_to(const QSizeF *, sfp[2]);
		QSizeF ret_v = qp->sizeHint(which, constraint);
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QGraphicsWebView.updateGeometry();
KMETHOD QGraphicsWebView_updateGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		qp->updateGeometry();
	}
	RETURNvoid_();
}

//QGraphicsWebView QGraphicsWebView.new(QGraphicsItem parent);
KMETHOD QGraphicsWebView_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[1]);
	KQGraphicsWebView *ret_v = new KQGraphicsWebView(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QGraphicsWebView.findText(String subString, int options);
KMETHOD QGraphicsWebView_findText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		const QString subString = String_to(const QString, sfp[1]);
		QWebPage::FindFlags options = Int_to(QWebPage::FindFlags, sfp[2]);
		bool ret_v = qp->findText(subString, options);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QWebHistory QGraphicsWebView.history();
KMETHOD QGraphicsWebView_history(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		QWebHistory* ret_v = qp->history();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebHistory*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QIcon QGraphicsWebView.icon();
KMETHOD QGraphicsWebView_icon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		QIcon ret_v = qp->icon();
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGraphicsWebView.isModified();
KMETHOD QGraphicsWebView_isModified(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isModified();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGraphicsWebView.isTiledBackingStoreFrozen();
KMETHOD QGraphicsWebView_isTiledBackingStoreFrozen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isTiledBackingStoreFrozen();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGraphicsWebView.load(QUrl url);
KMETHOD QGraphicsWebView_load(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
		qp->load(url);
	}
	RETURNvoid_();
}

/*
//void QGraphicsWebView.load(QNetworkRequest request, int operation, QByteArray body);
KMETHOD QGraphicsWebView_load(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		const QNetworkRequest  request = *RawPtr_to(const QNetworkRequest *, sfp[1]);
		QNetworkAccessManager::Operation operation = Int_to(QNetworkAccessManager::Operation, sfp[2]);
		const QByteArray  body = *RawPtr_to(const QByteArray *, sfp[3]);
		qp->load(request, operation, body);
	}
	RETURNvoid_();
}
*/
//QWebPage QGraphicsWebView.getPage();
KMETHOD QGraphicsWebView_getPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		QWebPage* ret_v = qp->page();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebPage*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAction QGraphicsWebView.pageAction(int action);
KMETHOD QGraphicsWebView_pageAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		QWebPage::WebAction action = Int_to(QWebPage::WebAction, sfp[1]);
		QAction* ret_v = qp->pageAction(action);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGraphicsWebView.getResizesToContents();
KMETHOD QGraphicsWebView_getResizesToContents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		bool ret_v = qp->resizesToContents();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGraphicsWebView.setContent(QByteArray data, String mimeType, QUrl baseUrl);
KMETHOD QGraphicsWebView_setContent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		const QByteArray  data = *RawPtr_to(const QByteArray *, sfp[1]);
		const QString mimeType = String_to(const QString, sfp[2]);
		const QUrl  baseUrl = *RawPtr_to(const QUrl *, sfp[3]);
		qp->setContent(data, mimeType, baseUrl);
	}
	RETURNvoid_();
}

//void QGraphicsWebView.setHtml(String html, QUrl baseUrl);
KMETHOD QGraphicsWebView_setHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		const QString html = String_to(const QString, sfp[1]);
		const QUrl  baseUrl = *RawPtr_to(const QUrl *, sfp[2]);
		qp->setHtml(html, baseUrl);
	}
	RETURNvoid_();
}

//void QGraphicsWebView.setPage(QWebPage page);
KMETHOD QGraphicsWebView_setPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		QWebPage*  page = RawPtr_to(QWebPage*, sfp[1]);
		qp->setPage(page);
	}
	RETURNvoid_();
}

//void QGraphicsWebView.setResizesToContents(boolean enabled);
KMETHOD QGraphicsWebView_setResizesToContents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setResizesToContents(enabled);
	}
	RETURNvoid_();
}

//void QGraphicsWebView.setTiledBackingStoreFrozen(boolean frozen);
KMETHOD QGraphicsWebView_setTiledBackingStoreFrozen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		bool frozen = Boolean_to(bool, sfp[1]);
		qp->setTiledBackingStoreFrozen(frozen);
	}
	RETURNvoid_();
}

//void QGraphicsWebView.setUrl(QUrl arg0);
KMETHOD QGraphicsWebView_setUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		const QUrl  arg0 = *RawPtr_to(const QUrl *, sfp[1]);
		qp->setUrl(arg0);
	}
	RETURNvoid_();
}

//void QGraphicsWebView.setZoomFactor(float arg0);
KMETHOD QGraphicsWebView_setZoomFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		qreal arg0 = Float_to(qreal, sfp[1]);
		qp->setZoomFactor(arg0);
	}
	RETURNvoid_();
}

//QWebSettings QGraphicsWebView.settings();
KMETHOD QGraphicsWebView_settings(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		QWebSettings* ret_v = qp->settings();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebSettings*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QGraphicsWebView.title();
KMETHOD QGraphicsWebView_title(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		QString ret_v = qp->title();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsWebView.triggerPageAction(int action, boolean checked);
KMETHOD QGraphicsWebView_triggerPageAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		QWebPage::WebAction action = Int_to(QWebPage::WebAction, sfp[1]);
		bool checked = Boolean_to(bool, sfp[2]);
		qp->triggerPageAction(action, checked);
	}
	RETURNvoid_();
}

//QUrl QGraphicsWebView.getUrl();
KMETHOD QGraphicsWebView_getUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		QUrl ret_v = qp->url();
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QGraphicsWebView.getZoomFactor();
KMETHOD QGraphicsWebView_getZoomFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->zoomFactor();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QGraphicsWebView.back();
KMETHOD QGraphicsWebView_back(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		qp->back();
	}
	RETURNvoid_();
}

//void QGraphicsWebView.forward();
KMETHOD QGraphicsWebView_forward(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		qp->forward();
	}
	RETURNvoid_();
}

//void QGraphicsWebView.reload();
KMETHOD QGraphicsWebView_reload(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		qp->reload();
	}
	RETURNvoid_();
}

//void QGraphicsWebView.stop();
KMETHOD QGraphicsWebView_stop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsWebView *  qp = RawPtr_to(QGraphicsWebView *, sfp[0]);
	if (qp) {
		qp->stop();
	}
	RETURNvoid_();
}

// //@Virtual void QGraphicsWebView.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
// KMETHOD QGraphicsWebView_paint(CTX ctx, knh_sfp_t *sfp _RIX)
// {
// 	(void)ctx;
// 	KQGraphicsWebView *  qp = RawPtr_to(KQGraphicsWebView *, sfp[0]);
// 	if (qp) {
// 		if (qp->dummy->paint_func != NULL) {
// 			knh_Func_invoke(ctx, qp->dummy->paint_func, sfp, 4);
// 		}
// 	}
// 	RETURNvoid_();
// }

//@Virtual void QGraphicsWebView.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
KMETHOD QGraphicsWebView_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsWebView *  qp = RawPtr_to(KQGraphicsWebView *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionGraphicsItem*  option = RawPtr_to(const QStyleOptionGraphicsItem*, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->paint(painter, option, widget);
	}
	RETURNvoid_();
}

void KQGraphicsWebView::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
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

DummyQGraphicsWebView::DummyQGraphicsWebView()
{
	self = NULL;
	icon_changed_func = NULL;
	link_clicked_func = NULL;
	load_finished_func = NULL;
	load_progress_func = NULL;
	load_started_func = NULL;
	status_bar_message_func = NULL;
	title_changed_func = NULL;
	url_changed_func = NULL;
	paint_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	event_map->insert(map<string, knh_Func_t *>::value_type("paint", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("icon-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("link-clicked", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("load-finished", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("load-progress", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("load-started", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("status-bar-message", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("title-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("url-changed", NULL));
}

void DummyQGraphicsWebView::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsWebView::self = ptr;
	DummyQGraphicsWidget::setSelf(ptr);
}

bool DummyQGraphicsWebView::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsWebView::iconChangedSlot()
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

bool DummyQGraphicsWebView::linkClickedSlot(const QUrl url)
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

bool DummyQGraphicsWebView::loadFinishedSlot(bool ok)
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

bool DummyQGraphicsWebView::loadProgressSlot(int progress)
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

bool DummyQGraphicsWebView::loadStartedSlot()
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

bool DummyQGraphicsWebView::statusBarMessageSlot(const QString text)
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

bool DummyQGraphicsWebView::titleChangedSlot(const QString title)
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

bool DummyQGraphicsWebView::urlChangedSlot(const QUrl url)
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

bool DummyQGraphicsWebView::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsWebView::event_map->bigin();
	if ((itr = DummyQGraphicsWebView::event_map->find(str)) == DummyQGraphicsWebView::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		paint_func = (*event_map)["paint"];
		return true;
	}
}

bool DummyQGraphicsWebView::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsWebView::slot_map->bigin();
	if ((itr = DummyQGraphicsWebView::slot_map->find(str)) == DummyQGraphicsWebView::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		icon_changed_func = (*slot_map)["icon-changed"];
		link_clicked_func = (*slot_map)["link-clicked"];
		load_finished_func = (*slot_map)["load-finished"];
		load_progress_func = (*slot_map)["load-progress"];
		load_started_func = (*slot_map)["load-started"];
		status_bar_message_func = (*slot_map)["status-bar-message"];
		title_changed_func = (*slot_map)["title-changed"];
		url_changed_func = (*slot_map)["url-changed"];
		return true;
	}
}

knh_Object_t** DummyQGraphicsWebView::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsWebView::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 8;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, icon_changed_func);
	KNH_ADDNNREF(ctx, link_clicked_func);
	KNH_ADDNNREF(ctx, load_finished_func);
	KNH_ADDNNREF(ctx, load_progress_func);
	KNH_ADDNNREF(ctx, load_started_func);
	KNH_ADDNNREF(ctx, status_bar_message_func);
	KNH_ADDNNREF(ctx, title_changed_func);
	KNH_ADDNNREF(ctx, url_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQGraphicsWidget::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGraphicsWebView::connection(QObject *o)
{
	QGraphicsWebView *p = dynamic_cast<QGraphicsWebView*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(iconChanged()), this, SLOT(iconChangedSlot()));
		connect(p, SIGNAL(linkClicked(const QUrl)), this, SLOT(linkClickedSlot(const QUrl)));
		connect(p, SIGNAL(loadFinished(bool)), this, SLOT(loadFinishedSlot(bool)));
		connect(p, SIGNAL(loadProgress(int)), this, SLOT(loadProgressSlot(int)));
		connect(p, SIGNAL(loadStarted()), this, SLOT(loadStartedSlot()));
		connect(p, SIGNAL(statusBarMessage(const QString)), this, SLOT(statusBarMessageSlot(const QString)));
		connect(p, SIGNAL(titleChanged(const QString)), this, SLOT(titleChangedSlot(const QString)));
		connect(p, SIGNAL(urlChanged(const QUrl)), this, SLOT(urlChangedSlot(const QUrl)));
	}
	DummyQGraphicsWidget::connection(o);
}

KQGraphicsWebView::KQGraphicsWebView(QGraphicsItem* parent) : QGraphicsWebView(parent)
{
	self = NULL;
	dummy = new DummyQGraphicsWebView();
	dummy->connection((QObject*)this);
}

KMETHOD QGraphicsWebView_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsWebView *qp = RawPtr_to(KQGraphicsWebView *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsWebView]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsWebView]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsWebView_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsWebView *qp = RawPtr_to(KQGraphicsWebView *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsWebView]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsWebView]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsWebView_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsWebView *qp = (KQGraphicsWebView *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsWebView_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGraphicsWebView *qp = (KQGraphicsWebView *)p->rawptr;
//		KQGraphicsWebView *qp = static_cast<KQGraphicsWebView*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsWebView_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsWebView::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGraphicsWebView::sceneEvent(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGraphicsWebView::sceneEvent(event);
		return false;
	}
//	QGraphicsWebView::sceneEvent(event);
	return true;
}



DEFAPI(void) defQGraphicsWebView(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsWebView";
	cdef->free = QGraphicsWebView_free;
	cdef->reftrace = QGraphicsWebView_reftrace;
	cdef->compareTo = QGraphicsWebView_compareTo;
}


