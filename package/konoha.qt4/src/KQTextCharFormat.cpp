//QTextCharFormat QTextCharFormat.new();
KMETHOD QTextCharFormat_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextCharFormat *ret_v = new KQTextCharFormat();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//String QTextCharFormat.getAnchorHref();
KMETHOD QTextCharFormat_getAnchorHref(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->anchorHref();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFont QTextCharFormat.getFont();
KMETHOD QTextCharFormat_getFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		QFont ret_v = qp->font();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextCharFormat.getFontCapitalization();
KMETHOD QTextCharFormat_getFontCapitalization(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		QFont::Capitalization ret_v = qp->fontCapitalization();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QTextCharFormat.getFontFamily();
KMETHOD QTextCharFormat_getFontFamily(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->fontFamily();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QTextCharFormat.getFontFixedPitch();
KMETHOD QTextCharFormat_getFontFixedPitch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->fontFixedPitch();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextCharFormat.getFontItalic();
KMETHOD QTextCharFormat_getFontItalic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->fontItalic();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTextCharFormat.getFontKerning();
KMETHOD QTextCharFormat_getFontKerning(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->fontKerning();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//float QTextCharFormat.getFontLetterSpacing();
KMETHOD QTextCharFormat_getFontLetterSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->fontLetterSpacing();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//boolean QTextCharFormat.getFontOverline();
KMETHOD QTextCharFormat_getFontOverline(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->fontOverline();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//float QTextCharFormat.getFontPointSize();
KMETHOD QTextCharFormat_getFontPointSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->fontPointSize();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//boolean QTextCharFormat.getFontStrikeOut();
KMETHOD QTextCharFormat_getFontStrikeOut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->fontStrikeOut();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTextCharFormat.getFontStyleHint();
KMETHOD QTextCharFormat_getFontStyleHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		QFont::StyleHint ret_v = qp->fontStyleHint();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextCharFormat.getFontStyleStrategy();
KMETHOD QTextCharFormat_getFontStyleStrategy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		QFont::StyleStrategy ret_v = qp->fontStyleStrategy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QTextCharFormat.getFontUnderline();
KMETHOD QTextCharFormat_getFontUnderline(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->fontUnderline();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTextCharFormat.getFontWeight();
KMETHOD QTextCharFormat_getFontWeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->fontWeight();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QTextCharFormat.getFontWordSpacing();
KMETHOD QTextCharFormat_getFontWordSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->fontWordSpacing();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//boolean QTextCharFormat.isAnchor();
KMETHOD QTextCharFormat_isAnchor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isAnchor();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

////boolean QTextCharFormat.isValid();
KMETHOD QTextCharFormat_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTextCharFormat.setAnchor(boolean anchor);
KMETHOD QTextCharFormat_setAnchor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		bool anchor = Boolean_to(bool, sfp[1]);
		qp->setAnchor(anchor);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setAnchorHref(String value);
KMETHOD QTextCharFormat_setAnchorHref(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		const QString value = String_to(const QString, sfp[1]);
		qp->setAnchorHref(value);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setFont(QFont font);
KMETHOD QTextCharFormat_setFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
		qp->setFont(font);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setFontCapitalization(int capitalization);
KMETHOD QTextCharFormat_setFontCapitalization(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		QFont::Capitalization capitalization = Int_to(QFont::Capitalization, sfp[1]);
		qp->setFontCapitalization(capitalization);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setFontFamily(String family);
KMETHOD QTextCharFormat_setFontFamily(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		const QString family = String_to(const QString, sfp[1]);
		qp->setFontFamily(family);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setFontFixedPitch(boolean fixedPitch);
KMETHOD QTextCharFormat_setFontFixedPitch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		bool fixedPitch = Boolean_to(bool, sfp[1]);
		qp->setFontFixedPitch(fixedPitch);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setFontItalic(boolean italic);
KMETHOD QTextCharFormat_setFontItalic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		bool italic = Boolean_to(bool, sfp[1]);
		qp->setFontItalic(italic);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setFontKerning(boolean enable);
KMETHOD QTextCharFormat_setFontKerning(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setFontKerning(enable);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setFontLetterSpacing(float spacing);
KMETHOD QTextCharFormat_setFontLetterSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		qreal spacing = Float_to(qreal, sfp[1]);
		qp->setFontLetterSpacing(spacing);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setFontOverline(boolean overline);
KMETHOD QTextCharFormat_setFontOverline(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		bool overline = Boolean_to(bool, sfp[1]);
		qp->setFontOverline(overline);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setFontPointSize(float size);
KMETHOD QTextCharFormat_setFontPointSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		qreal size = Float_to(qreal, sfp[1]);
		qp->setFontPointSize(size);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setFontStrikeOut(boolean strikeOut);
KMETHOD QTextCharFormat_setFontStrikeOut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		bool strikeOut = Boolean_to(bool, sfp[1]);
		qp->setFontStrikeOut(strikeOut);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setFontStyleHint(int hint, int strategy);
KMETHOD QTextCharFormat_setFontStyleHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		QFont::StyleHint hint = Int_to(QFont::StyleHint, sfp[1]);
		QFont::StyleStrategy strategy = Int_to(QFont::StyleStrategy, sfp[2]);
		qp->setFontStyleHint(hint, strategy);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setFontStyleStrategy(int strategy);
KMETHOD QTextCharFormat_setFontStyleStrategy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		QFont::StyleStrategy strategy = Int_to(QFont::StyleStrategy, sfp[1]);
		qp->setFontStyleStrategy(strategy);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setFontUnderline(boolean underline);
KMETHOD QTextCharFormat_setFontUnderline(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		bool underline = Boolean_to(bool, sfp[1]);
		qp->setFontUnderline(underline);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setFontWeight(int weight);
KMETHOD QTextCharFormat_setFontWeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		int weight = Int_to(int, sfp[1]);
		qp->setFontWeight(weight);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setFontWordSpacing(float spacing);
KMETHOD QTextCharFormat_setFontWordSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		qreal spacing = Float_to(qreal, sfp[1]);
		qp->setFontWordSpacing(spacing);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setTextOutline(QPen pen);
KMETHOD QTextCharFormat_setTextOutline(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		const QPen  pen = *RawPtr_to(const QPen *, sfp[1]);
		qp->setTextOutline(pen);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setToolTip(String text);
KMETHOD QTextCharFormat_setToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setToolTip(text);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setUnderlineColor(QColor color);
KMETHOD QTextCharFormat_setUnderlineColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		const QColor  color = *RawPtr_to(const QColor *, sfp[1]);
		qp->setUnderlineColor(color);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setUnderlineStyle(int style);
KMETHOD QTextCharFormat_setUnderlineStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		QTextCharFormat::UnderlineStyle style = Int_to(QTextCharFormat::UnderlineStyle, sfp[1]);
		qp->setUnderlineStyle(style);
	}
	RETURNvoid_();
}

//void QTextCharFormat.setVerticalAlignment(int alignment);
KMETHOD QTextCharFormat_setVerticalAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		QTextCharFormat::VerticalAlignment alignment = Int_to(QTextCharFormat::VerticalAlignment, sfp[1]);
		qp->setVerticalAlignment(alignment);
	}
	RETURNvoid_();
}

//QPen QTextCharFormat.getTextOutline();
KMETHOD QTextCharFormat_getTextOutline(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		QPen ret_v = qp->textOutline();
		QPen *ret_v_ = new QPen(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QTextCharFormat.getToolTip();
KMETHOD QTextCharFormat_getToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->toolTip();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QColor QTextCharFormat.getUnderlineColor();
KMETHOD QTextCharFormat_getUnderlineColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		QColor ret_v = qp->underlineColor();
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextCharFormat.getUnderlineStyle();
KMETHOD QTextCharFormat_getUnderlineStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		QTextCharFormat::UnderlineStyle ret_v = qp->underlineStyle();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextCharFormat.getVerticalAlignment();
KMETHOD QTextCharFormat_getVerticalAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCharFormat *  qp = RawPtr_to(QTextCharFormat *, sfp[0]);
	if (qp != NULL) {
		QTextCharFormat::VerticalAlignment ret_v = qp->verticalAlignment();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQTextCharFormat::DummyQTextCharFormat()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextCharFormat::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextCharFormat::self = ptr;
	DummyQTextFormat::setSelf(ptr);
}

bool DummyQTextCharFormat::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQTextFormat::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTextCharFormat::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextCharFormat::event_map->bigin();
	if ((itr = DummyQTextCharFormat::event_map->find(str)) == DummyQTextCharFormat::event_map->end()) {
		bool ret = false;
		ret = DummyQTextFormat::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextCharFormat::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextCharFormat::slot_map->bigin();
	if ((itr = DummyQTextCharFormat::slot_map->find(str)) == DummyQTextCharFormat::slot_map->end()) {
		bool ret = false;
		ret = DummyQTextFormat::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQTextCharFormat::connection(QObject *o)
{
	DummyQTextFormat::connection(o);
}

KQTextCharFormat::KQTextCharFormat() : QTextCharFormat()
{
	self = NULL;
	dummy = new DummyQTextCharFormat();
	dummy->connection((QObject*)this);
}

KMETHOD QTextCharFormat_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextCharFormat *qp = RawPtr_to(KQTextCharFormat *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextCharFormat]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextCharFormat]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextCharFormat_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextCharFormat *qp = RawPtr_to(KQTextCharFormat *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextCharFormat]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextCharFormat]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextCharFormat_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextCharFormat *qp = (KQTextCharFormat *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextCharFormat_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQTextCharFormat *qp = (KQTextCharFormat *)p->rawptr;
		(void)qp;
	}
}

static int QTextCharFormat_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextCharFormat::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQTextCharFormat(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextCharFormat";
	cdef->free = QTextCharFormat_free;
	cdef->reftrace = QTextCharFormat_reftrace;
	cdef->compareTo = QTextCharFormat_compareTo;
}

static knh_IntData_t QTextCharFormatConstInt[] = {
	{"NoUnderline", QTextCharFormat::NoUnderline},
	{"SingleUnderline", QTextCharFormat::SingleUnderline},
	{"DashUnderline", QTextCharFormat::DashUnderline},
	{"DotLine", QTextCharFormat::DotLine},
	{"DashDotLine", QTextCharFormat::DashDotLine},
	{"DashDotDotLine", QTextCharFormat::DashDotDotLine},
	{"WaveUnderline", QTextCharFormat::WaveUnderline},
	{"SpellCheckUnderline", QTextCharFormat::SpellCheckUnderline},
	{"AlignNormal", QTextCharFormat::AlignNormal},
	{"AlignSuperScript", QTextCharFormat::AlignSuperScript},
	{"AlignSubScript", QTextCharFormat::AlignSubScript},
	{"AlignMiddle", QTextCharFormat::AlignMiddle},
	{"AlignBottom", QTextCharFormat::AlignBottom},
	{"AlignTop", QTextCharFormat::AlignTop},
	{NULL, 0}
};

DEFAPI(void) constQTextCharFormat(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTextCharFormatConstInt);
}

