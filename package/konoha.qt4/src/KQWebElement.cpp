//QWebElement QWebElement.new();
KMETHOD QWebElement_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebElement *ret_v = new KQWebElement();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QWebElement QWebElement.new(QWebElement other);
KMETHOD QWebElement_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QWebElement  other = *RawPtr_to(const QWebElement *, sfp[1]);
	KQWebElement *ret_v = new KQWebElement(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QWebElement.addClass(String name);
KMETHOD QWebElement_addClass(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		qp->addClass(name);
	}
	RETURNvoid_();
}

//void QWebElement.appendInside(String markup);
KMETHOD QWebElement_appendInside(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString markup = String_to(const QString, sfp[1]);
		qp->appendInside(markup);
	}
	RETURNvoid_();
}

/*
//void QWebElement.appendInside(QWebElement element);
KMETHOD QWebElement_appendInside(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QWebElement  element = *RawPtr_to(const QWebElement *, sfp[1]);
		qp->appendInside(element);
	}
	RETURNvoid_();
}
*/
//void QWebElement.appendOutside(String markup);
KMETHOD QWebElement_appendOutside(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString markup = String_to(const QString, sfp[1]);
		qp->appendOutside(markup);
	}
	RETURNvoid_();
}

/*
//void QWebElement.appendOutside(QWebElement element);
KMETHOD QWebElement_appendOutside(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QWebElement  element = *RawPtr_to(const QWebElement *, sfp[1]);
		qp->appendOutside(element);
	}
	RETURNvoid_();
}
*/
//String QWebElement.getAttribute(String name, String defaultValue);
KMETHOD QWebElement_getAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		const QString defaultValue = String_to(const QString, sfp[2]);
		QString ret_v = qp->attribute(name, defaultValue);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebElement.getAttributeNS(String namespaceUri, String name, String defaultValue);
KMETHOD QWebElement_getAttributeNS(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString namespaceUri = String_to(const QString, sfp[1]);
		const QString name = String_to(const QString, sfp[2]);
		const QString defaultValue = String_to(const QString, sfp[3]);
		QString ret_v = qp->attributeNS(namespaceUri, name, defaultValue);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebElement QWebElement.clone();
KMETHOD QWebElement_clone(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QWebElement ret_v = qp->clone();
		QWebElement *ret_v_ = new QWebElement(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebElement QWebElement.document();
KMETHOD QWebElement_document(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QWebElement ret_v = qp->document();
		QWebElement *ret_v_ = new QWebElement(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebElement.encloseContentsWith(QWebElement element);
KMETHOD QWebElement_encloseContentsWith(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QWebElement  element = *RawPtr_to(const QWebElement *, sfp[1]);
		qp->encloseContentsWith(element);
	}
	RETURNvoid_();
}

/*
//void QWebElement.encloseContentsWith(String markup);
KMETHOD QWebElement_encloseContentsWith(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString markup = String_to(const QString, sfp[1]);
		qp->encloseContentsWith(markup);
	}
	RETURNvoid_();
}
*/
//void QWebElement.encloseWith(String markup);
KMETHOD QWebElement_encloseWith(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString markup = String_to(const QString, sfp[1]);
		qp->encloseWith(markup);
	}
	RETURNvoid_();
}

/*
//void QWebElement.encloseWith(QWebElement element);
KMETHOD QWebElement_encloseWith(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QWebElement  element = *RawPtr_to(const QWebElement *, sfp[1]);
		qp->encloseWith(element);
	}
	RETURNvoid_();
}
*/
//QVariant QWebElement.evaluateJavaScript(String scriptSource);
KMETHOD QWebElement_evaluateJavaScript(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString scriptSource = String_to(const QString, sfp[1]);
		QVariant ret_v = qp->evaluateJavaScript(scriptSource);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebElementCollection QWebElement.findAll(String selectorQuery);
KMETHOD QWebElement_findAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString selectorQuery = String_to(const QString, sfp[1]);
		QWebElementCollection ret_v = qp->findAll(selectorQuery);
		QWebElementCollection *ret_v_ = new QWebElementCollection(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebElement QWebElement.findFirst(String selectorQuery);
KMETHOD QWebElement_findFirst(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString selectorQuery = String_to(const QString, sfp[1]);
		QWebElement ret_v = qp->findFirst(selectorQuery);
		QWebElement *ret_v_ = new QWebElement(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebElement QWebElement.firstChild();
KMETHOD QWebElement_firstChild(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QWebElement ret_v = qp->firstChild();
		QWebElement *ret_v_ = new QWebElement(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QWebElement.geometry();
KMETHOD QWebElement_geometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->geometry();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QWebElement.hasAttribute(String name);
KMETHOD QWebElement_hasAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		bool ret_v = qp->hasAttribute(name);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWebElement.hasAttributeNS(String namespaceUri, String name);
KMETHOD QWebElement_hasAttributeNS(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString namespaceUri = String_to(const QString, sfp[1]);
		const QString name = String_to(const QString, sfp[2]);
		bool ret_v = qp->hasAttributeNS(namespaceUri, name);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWebElement.hasAttributes();
KMETHOD QWebElement_hasAttributes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasAttributes();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWebElement.hasClass(String name);
KMETHOD QWebElement_hasClass(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		bool ret_v = qp->hasClass(name);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QWebElement.hasFocus();
KMETHOD QWebElement_hasFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasFocus();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QWebElement QWebElement.lastChild();
KMETHOD QWebElement_lastChild(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QWebElement ret_v = qp->lastChild();
		QWebElement *ret_v_ = new QWebElement(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebElement.localName();
KMETHOD QWebElement_localName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QString ret_v = qp->localName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebElement.namespaceUri();
KMETHOD QWebElement_namespaceUri(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QString ret_v = qp->namespaceUri();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebElement QWebElement.nextSibling();
KMETHOD QWebElement_nextSibling(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QWebElement ret_v = qp->nextSibling();
		QWebElement *ret_v_ = new QWebElement(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebElement QWebElement.parent();
KMETHOD QWebElement_parent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QWebElement ret_v = qp->parent();
		QWebElement *ret_v_ = new QWebElement(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebElement.prefix();
KMETHOD QWebElement_prefix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QString ret_v = qp->prefix();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebElement.prependInside(String markup);
KMETHOD QWebElement_prependInside(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString markup = String_to(const QString, sfp[1]);
		qp->prependInside(markup);
	}
	RETURNvoid_();
}

/*
//void QWebElement.prependInside(QWebElement element);
KMETHOD QWebElement_prependInside(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QWebElement  element = *RawPtr_to(const QWebElement *, sfp[1]);
		qp->prependInside(element);
	}
	RETURNvoid_();
}
*/
//void QWebElement.prependOutside(String markup);
KMETHOD QWebElement_prependOutside(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString markup = String_to(const QString, sfp[1]);
		qp->prependOutside(markup);
	}
	RETURNvoid_();
}

/*
//void QWebElement.prependOutside(QWebElement element);
KMETHOD QWebElement_prependOutside(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QWebElement  element = *RawPtr_to(const QWebElement *, sfp[1]);
		qp->prependOutside(element);
	}
	RETURNvoid_();
}
*/
//QWebElement QWebElement.previousSibling();
KMETHOD QWebElement_previousSibling(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QWebElement ret_v = qp->previousSibling();
		QWebElement *ret_v_ = new QWebElement(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebElement.removeAllChildren();
KMETHOD QWebElement_removeAllChildren(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		qp->removeAllChildren();
	}
	RETURNvoid_();
}

//void QWebElement.removeAttribute(String name);
KMETHOD QWebElement_removeAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		qp->removeAttribute(name);
	}
	RETURNvoid_();
}

//void QWebElement.removeAttributeNS(String namespaceUri, String name);
KMETHOD QWebElement_removeAttributeNS(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString namespaceUri = String_to(const QString, sfp[1]);
		const QString name = String_to(const QString, sfp[2]);
		qp->removeAttributeNS(namespaceUri, name);
	}
	RETURNvoid_();
}

//void QWebElement.removeClass(String name);
KMETHOD QWebElement_removeClass(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		qp->removeClass(name);
	}
	RETURNvoid_();
}

//void QWebElement.removeFromDocument();
KMETHOD QWebElement_removeFromDocument(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		qp->removeFromDocument();
	}
	RETURNvoid_();
}

//void QWebElement.render(QPainter painter);
KMETHOD QWebElement_render(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		qp->render(painter);
	}
	RETURNvoid_();
}

//void QWebElement.replace(String markup);
KMETHOD QWebElement_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString markup = String_to(const QString, sfp[1]);
		qp->replace(markup);
	}
	RETURNvoid_();
}

/*
//void QWebElement.replace(QWebElement element);
KMETHOD QWebElement_replace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QWebElement  element = *RawPtr_to(const QWebElement *, sfp[1]);
		qp->replace(element);
	}
	RETURNvoid_();
}
*/
//void QWebElement.setAttribute(String name, String value);
KMETHOD QWebElement_setAttribute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		const QString value = String_to(const QString, sfp[2]);
		qp->setAttribute(name, value);
	}
	RETURNvoid_();
}

//void QWebElement.setAttributeNS(String namespaceUri, String name, String value);
KMETHOD QWebElement_setAttributeNS(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString namespaceUri = String_to(const QString, sfp[1]);
		const QString name = String_to(const QString, sfp[2]);
		const QString value = String_to(const QString, sfp[3]);
		qp->setAttributeNS(namespaceUri, name, value);
	}
	RETURNvoid_();
}

//void QWebElement.setFocus();
KMETHOD QWebElement_setFocus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		qp->setFocus();
	}
	RETURNvoid_();
}

//void QWebElement.setInnerXml(String markup);
KMETHOD QWebElement_setInnerXml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString markup = String_to(const QString, sfp[1]);
		qp->setInnerXml(markup);
	}
	RETURNvoid_();
}

//void QWebElement.setOuterXml(String markup);
KMETHOD QWebElement_setOuterXml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString markup = String_to(const QString, sfp[1]);
		qp->setOuterXml(markup);
	}
	RETURNvoid_();
}

//void QWebElement.setPlainText(String text);
KMETHOD QWebElement_setPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setPlainText(text);
	}
	RETURNvoid_();
}

//void QWebElement.setStyleProperty(String name, String value);
KMETHOD QWebElement_setStyleProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		const QString value = String_to(const QString, sfp[2]);
		qp->setStyleProperty(name, value);
	}
	RETURNvoid_();
}

//String QWebElement.getStyleProperty(String name, int strategy);
KMETHOD QWebElement_getStyleProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		QWebElement::StyleResolveStrategy strategy = Int_to(QWebElement::StyleResolveStrategy, sfp[2]);
		QString ret_v = qp->styleProperty(name, strategy);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebElement.tagName();
KMETHOD QWebElement_tagName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QString ret_v = qp->tagName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWebElement QWebElement.takeFromDocument();
KMETHOD QWebElement_takeFromDocument(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QWebElement ret_v = qp->takeFromDocument();
		QWebElement *ret_v_ = new QWebElement(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebElement.toInnerXml();
KMETHOD QWebElement_toInnerXml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QString ret_v = qp->toInnerXml();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebElement.toOuterXml();
KMETHOD QWebElement_toOuterXml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QString ret_v = qp->toOuterXml();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QWebElement.toPlainText();
KMETHOD QWebElement_toPlainText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QString ret_v = qp->toPlainText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWebElement.toggleClass(String name);
KMETHOD QWebElement_toggleClass(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		qp->toggleClass(name);
	}
	RETURNvoid_();
}

//QWebFrame QWebElement.webFrame();
KMETHOD QWebElement_webFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *  qp = RawPtr_to(QWebElement *, sfp[0]);
	if (qp) {
		QWebFrame* ret_v = qp->webFrame();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWebFrame*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QWebElement.parents();
KMETHOD QWebElement_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWebElement *qp = RawPtr_to(QWebElement*, sfp[0]);
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

DummyQWebElement::DummyQWebElement()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQWebElement::~DummyQWebElement()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQWebElement::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWebElement::self = ptr;
}

bool DummyQWebElement::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQWebElement::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebElement::event_map->bigin();
	if ((itr = DummyQWebElement::event_map->find(str)) == DummyQWebElement::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWebElement::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWebElement::slot_map->bigin();
	if ((itr = DummyQWebElement::slot_map->find(str)) == DummyQWebElement::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQWebElement::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQWebElement::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQWebElement::connection(QObject *o)
{
	QWebElement *p = dynamic_cast<QWebElement*>(o);
	if (p != NULL) {
	}
}

KQWebElement::KQWebElement() : QWebElement()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQWebElement();
}

KQWebElement::~KQWebElement()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QWebElement_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebElement *qp = RawPtr_to(KQWebElement *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWebElement]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebElement]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWebElement_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWebElement *qp = RawPtr_to(KQWebElement *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWebElement]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWebElement]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWebElement_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQWebElement *qp = (KQWebElement *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QWebElement*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QWebElement_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQWebElement *qp = (KQWebElement *)p->rawptr;
		KQWebElement *qp = static_cast<KQWebElement*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWebElement_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QWebElement*>(p1->rawptr) == *static_cast<QWebElement*>(p2->rawptr) ? 0 : 1);
}

void KQWebElement::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QWebElementConstInt[] = {
	{"InlineStyle", QWebElement::InlineStyle},
	{"CascadedStyle", QWebElement::CascadedStyle},
	{"ComputedStyle", QWebElement::ComputedStyle},
	{NULL, 0}
};

DEFAPI(void) constQWebElement(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QWebElementConstInt);
}


DEFAPI(void) defQWebElement(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWebElement";
	cdef->free = QWebElement_free;
	cdef->reftrace = QWebElement_reftrace;
	cdef->compareTo = QWebElement_compareTo;
}


