//@Virtual @Override boolean QWebFrame.event(QEvent e);
KMETHOD QWebFrame_event(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QEvent*  e = RawPtr_to(QEvent*, sfp[1]);
		bool ret_v = qp->q_self->event(e);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QWebFrame.addToJavaScriptWindowObject(String name, QObject object);
KMETHOD QWebFrame_addToJavaScriptWindowObject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		QObject*  object = RawPtr_to(QObject*, sfp[2]);
		qp->q_self->addToJavaScriptWindowObject(name, object);
	}
	RETURNvoid_();
}

/*
//void QWebFrame.addToJavaScriptWindowObject(String name, QObject object, int own);
KMETHOD QWebFrame_addToJavaScriptWindowObject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		QObject*  object = RawPtr_to(QObject*, sfp[2]);
		QScriptEngine::ValueOwnership own = Int_to(QScriptEngine::ValueOwnership, sfp[3]);
		qp->q_self->addToJavaScriptWindowObject(name, object, own);
	}
	RETURNvoid_();
}
*/
//QUrl QWebFrame.baseUrl();
KMETHOD QWebFrame_baseUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QUrl ret_v = qp->q_self->baseUrl();
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QWebFrame> QWebFrame.childFrames();
KMETHOD QWebFrame_childFrames(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QList<QWebFrame*> ret_v = qp->q_self->childFrames();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QWebFrame"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QSize QWebFrame.contentsSize();
KMETHOD QWebFrame_contentsSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->q_self->contentsSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebElement QWebFrame.documentElement();
KMETHOD QWebFrame_documentElement(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QWebElement ret_v = qp->q_self->documentElement();
		QWebElement *ret_v_ = new QWebElement(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebElementCollection QWebFrame.findAllElements(String selectorQuery);
KMETHOD QWebFrame_findAllElements(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		const QString selectorQuery = String_to(const QString, sfp[1]);
		QWebElementCollection ret_v = qp->q_self->findAllElements(selectorQuery);
		QWebElementCollection *ret_v_ = new QWebElementCollection(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebElement QWebFrame.findFirstElement(String selectorQuery);
KMETHOD QWebFrame_findFirstElement(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		const QString selectorQuery = String_to(const QString, sfp[1]);
		QWebElement ret_v = qp->q_self->findFirstElement(selectorQuery);
		QWebElement *ret_v_ = new QWebElement(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebFrame.frameName();
KMETHOD QWebFrame_frameName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QString ret_v = qp->q_self->frameName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QWebFrame.geometry();
KMETHOD QWebFrame_geometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->q_self->geometry();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QWebFrame.hasFocus();
KMETHOD QWebFrame_hasFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		bool ret_v = qp->q_self->hasFocus();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QWebHitTestResult QWebFrame.hitTestContent(QPoint pos);
KMETHOD QWebFrame_hitTestContent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		QWebHitTestResult ret_v = qp->q_self->hitTestContent(pos);
		QWebHitTestResult *ret_v_ = new QWebHitTestResult(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QIcon QWebFrame.icon();
KMETHOD QWebFrame_icon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QIcon ret_v = qp->q_self->icon();
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebFrame.load(QUrl url);
KMETHOD QWebFrame_load(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
		qp->q_self->load(url);
	}
	RETURNvoid_();
}

/*
//void QWebFrame.load(QNetworkRequest req, int operation, QByteArray body);
KMETHOD QWebFrame_load(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		const QNetworkRequest  req = *RawPtr_to(const QNetworkRequest *, sfp[1]);
		QNetworkAccessManager::Operation operation = Int_to(QNetworkAccessManager::Operation, sfp[2]);
		const QByteArray  body = *RawPtr_to(const QByteArray *, sfp[3]);
		qp->q_self->load(req, operation, body);
	}
	RETURNvoid_();
}
*/
//QWebPage QWebFrame.page();
KMETHOD QWebFrame_page(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QWebPage* ret_v = qp->q_self->page();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebPage*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebFrame QWebFrame.parentFrame();
KMETHOD QWebFrame_parentFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QWebFrame* ret_v = qp->q_self->parentFrame();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebFrame*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QWebFrame.pos();
KMETHOD QWebFrame_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QPoint ret_v = qp->q_self->pos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebFrame.render(QPainter painter);
KMETHOD QWebFrame_render(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		qp->q_self->render(painter);
	}
	RETURNvoid_();
}

/*
//void QWebFrame.render(QPainter painter, QRegion clip);
KMETHOD QWebFrame_render(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QRegion  clip = *RawPtr_to(const QRegion *, sfp[2]);
		qp->q_self->render(painter, clip);
	}
	RETURNvoid_();
}
*/
/*
//void QWebFrame.render(QPainter painter, int layer, QRegion clip);
KMETHOD QWebFrame_render(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		QWebFrame::RenderLayer layer = Int_to(QWebFrame::RenderLayer, sfp[2]);
		const QRegion  clip = *RawPtr_to(const QRegion *, sfp[3]);
		qp->q_self->render(painter, layer, clip);
	}
	RETURNvoid_();
}
*/
//String QWebFrame.renderTreeDump();
KMETHOD QWebFrame_renderTreeDump(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QString ret_v = qp->q_self->renderTreeDump();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QUrl QWebFrame.requestedUrl();
KMETHOD QWebFrame_requestedUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QUrl ret_v = qp->q_self->requestedUrl();
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebFrame.scroll(int dx, int dy);
KMETHOD QWebFrame_scroll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		int dx = Int_to(int, sfp[1]);
		int dy = Int_to(int, sfp[2]);
		qp->q_self->scroll(dx, dy);
	}
	RETURNvoid_();
}

//QRect QWebFrame.scrollBarGeometry(int orientation);
KMETHOD QWebFrame_scrollBarGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
		QRect ret_v = qp->q_self->scrollBarGeometry(orientation);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QWebFrame.scrollBarMaximum(int orientation);
KMETHOD QWebFrame_scrollBarMaximum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
		int ret_v = qp->q_self->scrollBarMaximum(orientation);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QWebFrame.scrollBarMinimum(int orientation);
KMETHOD QWebFrame_scrollBarMinimum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
		int ret_v = qp->q_self->scrollBarMinimum(orientation);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QWebFrame.getScrollBarPolicy(int orientation);
KMETHOD QWebFrame_getScrollBarPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
		Qt::ScrollBarPolicy ret_v = qp->q_self->scrollBarPolicy(orientation);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QWebFrame.getScrollBarValue(int orientation);
KMETHOD QWebFrame_getScrollBarValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
		int ret_v = qp->q_self->scrollBarValue(orientation);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPoint QWebFrame.getScrollPosition();
KMETHOD QWebFrame_getScrollPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QPoint ret_v = qp->q_self->scrollPosition();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebFrame.scrollToAnchor(String anchor);
KMETHOD QWebFrame_scrollToAnchor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		const QString anchor = String_to(const QString, sfp[1]);
		qp->q_self->scrollToAnchor(anchor);
	}
	RETURNvoid_();
}

//QWebSecurityOrigin QWebFrame.securityOrigin();
KMETHOD QWebFrame_securityOrigin(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QWebSecurityOrigin ret_v = qp->q_self->securityOrigin();
		QWebSecurityOrigin *ret_v_ = new QWebSecurityOrigin(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebFrame.setContent(QByteArray data, String mimeType, QUrl baseUrl);
KMETHOD QWebFrame_setContent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		const QByteArray  data = *RawPtr_to(const QByteArray *, sfp[1]);
		const QString mimeType = String_to(const QString, sfp[2]);
		const QUrl  baseUrl = *RawPtr_to(const QUrl *, sfp[3]);
		qp->q_self->setContent(data, mimeType, baseUrl);
	}
	RETURNvoid_();
}

//void QWebFrame.setFocus();
KMETHOD QWebFrame_setFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		qp->q_self->setFocus();
	}
	RETURNvoid_();
}

//void QWebFrame.setHtml(String html, QUrl baseUrl);
KMETHOD QWebFrame_setHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		const QString html = String_to(const QString, sfp[1]);
		const QUrl  baseUrl = *RawPtr_to(const QUrl *, sfp[2]);
		qp->q_self->setHtml(html, baseUrl);
	}
	RETURNvoid_();
}

//void QWebFrame.setScrollBarPolicy(int orientation, int policy);
KMETHOD QWebFrame_setScrollBarPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
		Qt::ScrollBarPolicy policy = Int_to(Qt::ScrollBarPolicy, sfp[2]);
		qp->q_self->setScrollBarPolicy(orientation, policy);
	}
	RETURNvoid_();
}

//void QWebFrame.setScrollBarValue(int orientation, int value);
KMETHOD QWebFrame_setScrollBarValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
		int value = Int_to(int, sfp[2]);
		qp->q_self->setScrollBarValue(orientation, value);
	}
	RETURNvoid_();
}

//void QWebFrame.setScrollPosition(QPoint pos);
KMETHOD QWebFrame_setScrollPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		qp->q_self->setScrollPosition(pos);
	}
	RETURNvoid_();
}

//void QWebFrame.setTextSizeMultiplier(float factor);
KMETHOD QWebFrame_setTextSizeMultiplier(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		qreal factor = Float_to(qreal, sfp[1]);
		qp->q_self->setTextSizeMultiplier(factor);
	}
	RETURNvoid_();
}

//void QWebFrame.setUrl(QUrl url);
KMETHOD QWebFrame_setUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
		qp->q_self->setUrl(url);
	}
	RETURNvoid_();
}

//void QWebFrame.setZoomFactor(float factor);
KMETHOD QWebFrame_setZoomFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		qreal factor = Float_to(qreal, sfp[1]);
		qp->q_self->setZoomFactor(factor);
	}
	RETURNvoid_();
}

//float QWebFrame.getTextSizeMultiplier();
KMETHOD QWebFrame_getTextSizeMultiplier(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->q_self->textSizeMultiplier();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//String QWebFrame.title();
KMETHOD QWebFrame_title(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QString ret_v = qp->q_self->title();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebFrame.toHtml();
KMETHOD QWebFrame_toHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QString ret_v = qp->q_self->toHtml();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebFrame.toPlainText();
KMETHOD QWebFrame_toPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QString ret_v = qp->q_self->toPlainText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QUrl QWebFrame.getUrl();
KMETHOD QWebFrame_getUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QUrl ret_v = qp->q_self->url();
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QWebFrame.getZoomFactor();
KMETHOD QWebFrame_getZoomFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->q_self->zoomFactor();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QVariant QWebFrame.evaluateJavaScript(String scriptSource);
KMETHOD QWebFrame_evaluateJavaScript(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		const QString scriptSource = String_to(const QString, sfp[1]);
		QVariant ret_v = qp->q_self->evaluateJavaScript(scriptSource);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebFrame.print(QPrinter printer);
KMETHOD QWebFrame_print(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *  qp = RawPtr_to(KQWebFrame *, sfp[0]);
	if (qp) {
		QPrinter*  printer = RawPtr_to(QPrinter*, sfp[1]);
		qp->q_self->print(printer);
	}
	RETURNvoid_();
}


DummyQWebFrame::DummyQWebFrame()
{
	self = NULL;
	contents_size_changed_func = NULL;
	icon_changed_func = NULL;
	initial_layout_completed_func = NULL;
	java_script_window_object_cleared_func = NULL;
	load_finished_func = NULL;
	load_started_func = NULL;
	page_changed_func = NULL;
	title_changed_func = NULL;
	url_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("contents-size-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("icon-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("initial-layout-completed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("java-script-window-object-cleared", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("load-finished", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("load-started", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("page-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("title-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("url-changed", NULL));
}

void DummyQWebFrame::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWebFrame::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQWebFrame::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQWebFrame::contentsSizeChangedSlot(const QSize size)
{
	if (contents_size_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QSize, size);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, contents_size_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWebFrame::iconChangedSlot()
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

bool DummyQWebFrame::initialLayoutCompletedSlot()
{
	if (initial_layout_completed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, initial_layout_completed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQWebFrame::javaScriptWindowObjectClearedSlot()
{
	if (java_script_window_object_cleared_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, java_script_window_object_cleared_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQWebFrame::loadFinishedSlot(bool ok)
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

bool DummyQWebFrame::loadStartedSlot()
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

bool DummyQWebFrame::pageChangedSlot()
{
	if (page_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, page_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQWebFrame::titleChangedSlot(const QString title)
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

bool DummyQWebFrame::urlChangedSlot(const QUrl url)
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

bool DummyQWebFrame::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebFrame::event_map->bigin();
	if ((itr = DummyQWebFrame::event_map->find(str)) == DummyQWebFrame::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWebFrame::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebFrame::slot_map->bigin();
	if ((itr = DummyQWebFrame::slot_map->find(str)) == DummyQWebFrame::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		contents_size_changed_func = (*slot_map)["contents-size-changed"];
		icon_changed_func = (*slot_map)["icon-changed"];
		initial_layout_completed_func = (*slot_map)["initial-layout-completed"];
		java_script_window_object_cleared_func = (*slot_map)["java-script-window-object-cleared"];
		load_finished_func = (*slot_map)["load-finished"];
		load_started_func = (*slot_map)["load-started"];
		page_changed_func = (*slot_map)["page-changed"];
		title_changed_func = (*slot_map)["title-changed"];
		url_changed_func = (*slot_map)["url-changed"];
		return true;
	}
}

knh_Object_t** DummyQWebFrame::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQWebFrame::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 9;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, contents_size_changed_func);
	KNH_ADDNNREF(ctx, icon_changed_func);
	KNH_ADDNNREF(ctx, initial_layout_completed_func);
	KNH_ADDNNREF(ctx, java_script_window_object_cleared_func);
	KNH_ADDNNREF(ctx, load_finished_func);
	KNH_ADDNNREF(ctx, load_started_func);
	KNH_ADDNNREF(ctx, page_changed_func);
	KNH_ADDNNREF(ctx, title_changed_func);
	KNH_ADDNNREF(ctx, url_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQWebFrame::connection(QObject *o)
{
	QWebFrame *p = dynamic_cast<QWebFrame*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(contentsSizeChanged(const QSize)), this, SLOT(contentsSizeChangedSlot(const QSize)));
		connect(p, SIGNAL(iconChanged()), this, SLOT(iconChangedSlot()));
		connect(p, SIGNAL(initialLayoutCompleted()), this, SLOT(initialLayoutCompletedSlot()));
		connect(p, SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(javaScriptWindowObjectClearedSlot()));
		connect(p, SIGNAL(loadFinished(bool)), this, SLOT(loadFinishedSlot(bool)));
		connect(p, SIGNAL(loadStarted()), this, SLOT(loadStartedSlot()));
		connect(p, SIGNAL(pageChanged()), this, SLOT(pageChangedSlot()));
		connect(p, SIGNAL(titleChanged(const QString)), this, SLOT(titleChangedSlot(const QString)));
		connect(p, SIGNAL(urlChanged(const QUrl)), this, SLOT(urlChangedSlot(const QUrl)));
	}
	DummyQObject::connection(o);
}

KMETHOD QWebFrame_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *qp = RawPtr_to(KQWebFrame *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWebFrame]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebFrame]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWebFrame_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebFrame *qp = RawPtr_to(KQWebFrame *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWebFrame]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebFrame]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWebFrame_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWebFrame *qp = (KQWebFrame *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWebFrame_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQWebFrame *qp = (KQWebFrame *)p->rawptr;
//		KQWebFrame *qp = static_cast<KQWebFrame*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWebFrame_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWebFrame::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQWebFrame::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		q_self->event(event);
		return false;
	}
//	q_self->event(event);
	return true;
}

static knh_IntData_t QWebFrameConstInt[] = {
	{"ContentsLayer", QWebFrame::ContentsLayer},
	{"ScrollBarLayer", QWebFrame::ScrollBarLayer},
	{"PanIconLayer", QWebFrame::PanIconLayer},
	{"AllLayers", QWebFrame::AllLayers},
	{NULL, 0}
};

DEFAPI(void) constQWebFrame(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QWebFrameConstInt);
}


DEFAPI(void) defQWebFrame(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWebFrame";
	cdef->free = QWebFrame_free;
	cdef->reftrace = QWebFrame_reftrace;
	cdef->compareTo = QWebFrame_compareTo;
}


