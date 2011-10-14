//QFont QFont.new();
KMETHOD QFont_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFont *ret_v = new KQFont();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QFont QFont.new(String family, int pointSize, int weight, boolean italic);
KMETHOD QFont_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString family = String_to(const QString, sfp[1]);
	int pointSize = Int_to(int, sfp[2]);
	int weight = Int_to(int, sfp[3]);
	bool italic = Boolean_to(bool, sfp[4]);
	KQFont *ret_v = new KQFont(family, pointSize, weight, italic);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QFont QFont.new(QFont font, QPaintDevice pd);
KMETHOD QFont_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
	QPaintDevice*  pd = RawPtr_to(QPaintDevice*, sfp[2]);
	KQFont *ret_v = new KQFont(font, pd);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QFont QFont.new(QFont font);
KMETHOD QFont_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
	KQFont *ret_v = new KQFont(font);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QFont.getBold();
KMETHOD QFont_getBold(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->bold();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QFont.getCapitalization();
KMETHOD QFont_getCapitalization(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		QFont::Capitalization ret_v = qp->capitalization();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QFont.defaultFamily();
KMETHOD QFont_defaultFamily(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->defaultFamily();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QFont.exactMatch();
KMETHOD QFont_exactMatch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->exactMatch();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QFont.getFamily();
KMETHOD QFont_getFamily(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->family();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QFont.getFixedPitch();
KMETHOD QFont_getFixedPitch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->fixedPitch();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QFont.fromString(String descrip);
KMETHOD QFont_fromString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		const QString descrip = String_to(const QString, sfp[1]);
		bool ret_v = qp->fromString(descrip);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QFont.isCopyOf(QFont f);
KMETHOD QFont_isCopyOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		const QFont  f = *RawPtr_to(const QFont *, sfp[1]);
		bool ret_v = qp->isCopyOf(f);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QFont.getItalic();
KMETHOD QFont_getItalic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->italic();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QFont.getKerning();
KMETHOD QFont_getKerning(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->kerning();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QFont.key();
KMETHOD QFont_key(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->key();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QFont.lastResortFamily();
KMETHOD QFont_lastResortFamily(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->lastResortFamily();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QFont.lastResortFont();
KMETHOD QFont_lastResortFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->lastResortFont();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QFont.getLetterSpacing();
KMETHOD QFont_getLetterSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->letterSpacing();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QFont.letterSpacingType();
KMETHOD QFont_letterSpacingType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		QFont::SpacingType ret_v = qp->letterSpacingType();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QFont.getOverline();
KMETHOD QFont_getOverline(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->overline();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QFont.getPixelSize();
KMETHOD QFont_getPixelSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->pixelSize();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFont.getPointSize();
KMETHOD QFont_getPointSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->pointSize();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QFont.getPointSizeF();
KMETHOD QFont_getPointSizeF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->pointSizeF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//boolean QFont.getRawMode();
KMETHOD QFont_getRawMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->rawMode();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QFont.getRawName();
KMETHOD QFont_getRawName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->rawName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFont QFont.resolve(QFont other);
KMETHOD QFont_resolve(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		const QFont  other = *RawPtr_to(const QFont *, sfp[1]);
		QFont ret_v = qp->resolve(other);
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QFont.setBold(boolean enable);
KMETHOD QFont_setBold(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setBold(enable);
	}
	RETURNvoid_();
}

//void QFont.setCapitalization(int caps);
KMETHOD QFont_setCapitalization(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		QFont::Capitalization caps = Int_to(QFont::Capitalization, sfp[1]);
		qp->setCapitalization(caps);
	}
	RETURNvoid_();
}

//void QFont.setFamily(String family);
KMETHOD QFont_setFamily(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		const QString family = String_to(const QString, sfp[1]);
		qp->setFamily(family);
	}
	RETURNvoid_();
}

//void QFont.setFixedPitch(boolean enable);
KMETHOD QFont_setFixedPitch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setFixedPitch(enable);
	}
	RETURNvoid_();
}

//void QFont.setItalic(boolean enable);
KMETHOD QFont_setItalic(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setItalic(enable);
	}
	RETURNvoid_();
}

//void QFont.setKerning(boolean enable);
KMETHOD QFont_setKerning(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setKerning(enable);
	}
	RETURNvoid_();
}

//void QFont.setLetterSpacing(int type, float spacing);
KMETHOD QFont_setLetterSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		QFont::SpacingType type = Int_to(QFont::SpacingType, sfp[1]);
		qreal spacing = Float_to(qreal, sfp[2]);
		qp->setLetterSpacing(type, spacing);
	}
	RETURNvoid_();
}

//void QFont.setOverline(boolean enable);
KMETHOD QFont_setOverline(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setOverline(enable);
	}
	RETURNvoid_();
}

//void QFont.setPixelSize(int pixelSize);
KMETHOD QFont_setPixelSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		int pixelSize = Int_to(int, sfp[1]);
		qp->setPixelSize(pixelSize);
	}
	RETURNvoid_();
}

//void QFont.setPointSize(int pointSize);
KMETHOD QFont_setPointSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		int pointSize = Int_to(int, sfp[1]);
		qp->setPointSize(pointSize);
	}
	RETURNvoid_();
}

//void QFont.setPointSizeF(float pointSize);
KMETHOD QFont_setPointSizeF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		qreal pointSize = Float_to(qreal, sfp[1]);
		qp->setPointSizeF(pointSize);
	}
	RETURNvoid_();
}

//void QFont.setRawMode(boolean enable);
KMETHOD QFont_setRawMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setRawMode(enable);
	}
	RETURNvoid_();
}

//void QFont.setRawName(String name);
KMETHOD QFont_setRawName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		const QString name = String_to(const QString, sfp[1]);
		qp->setRawName(name);
	}
	RETURNvoid_();
}

//void QFont.setStretch(int factor);
KMETHOD QFont_setStretch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		int factor = Int_to(int, sfp[1]);
		qp->setStretch(factor);
	}
	RETURNvoid_();
}

//void QFont.setStrikeOut(boolean enable);
KMETHOD QFont_setStrikeOut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setStrikeOut(enable);
	}
	RETURNvoid_();
}

//void QFont.setStyle(int style);
KMETHOD QFont_setStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		QFont::Style style = Int_to(QFont::Style, sfp[1]);
		qp->setStyle(style);
	}
	RETURNvoid_();
}

//void QFont.setStyleHint(int hint, int strategy);
KMETHOD QFont_setStyleHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		QFont::StyleHint hint = Int_to(QFont::StyleHint, sfp[1]);
		QFont::StyleStrategy strategy = Int_to(QFont::StyleStrategy, sfp[2]);
		qp->setStyleHint(hint, strategy);
	}
	RETURNvoid_();
}

//void QFont.setStyleStrategy(int s);
KMETHOD QFont_setStyleStrategy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		QFont::StyleStrategy s = Int_to(QFont::StyleStrategy, sfp[1]);
		qp->setStyleStrategy(s);
	}
	RETURNvoid_();
}

//void QFont.setUnderline(boolean enable);
KMETHOD QFont_setUnderline(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setUnderline(enable);
	}
	RETURNvoid_();
}

//void QFont.setWeight(int weight);
KMETHOD QFont_setWeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		int weight = Int_to(int, sfp[1]);
		qp->setWeight(weight);
	}
	RETURNvoid_();
}

//void QFont.setWordSpacing(float spacing);
KMETHOD QFont_setWordSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		qreal spacing = Float_to(qreal, sfp[1]);
		qp->setWordSpacing(spacing);
	}
	RETURNvoid_();
}

//int QFont.getStretch();
KMETHOD QFont_getStretch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->stretch();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QFont.getStrikeOut();
KMETHOD QFont_getStrikeOut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->strikeOut();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QFont.getStyle();
KMETHOD QFont_getStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		QFont::Style ret_v = qp->style();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFont.getStyleHint();
KMETHOD QFont_getStyleHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		QFont::StyleHint ret_v = qp->styleHint();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFont.getStyleStrategy();
KMETHOD QFont_getStyleStrategy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		QFont::StyleStrategy ret_v = qp->styleStrategy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QFont.toString();
KMETHOD QFont_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->toString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QFont.getUnderline();
KMETHOD QFont_getUnderline(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->underline();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QFont.getWeight();
KMETHOD QFont_getWeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->weight();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QFont.getWordSpacing();
KMETHOD QFont_getWordSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->wordSpacing();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QFont.insertSubstitution(String familyName, String substituteName);
KMETHOD QFont_insertSubstitution(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		const QString familyName = String_to(const QString, sfp[1]);
		const QString substituteName = String_to(const QString, sfp[2]);
		qp->insertSubstitution(familyName, substituteName);
	}
	RETURNvoid_();
}

//void QFont.removeSubstitution(String familyName);
KMETHOD QFont_removeSubstitution(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		const QString familyName = String_to(const QString, sfp[1]);
		qp->removeSubstitution(familyName);
	}
	RETURNvoid_();
}

//String QFont.substitute(String familyName);
KMETHOD QFont_substitute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFont *  qp = RawPtr_to(QFont *, sfp[0]);
	if (qp != NULL) {
		const QString familyName = String_to(const QString, sfp[1]);
		QString ret_v = qp->substitute(familyName);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQFont::DummyQFont()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQFont::setSelf(knh_RawPtr_t *ptr)
{
	DummyQFont::self = ptr;
}

bool DummyQFont::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQFont::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFont::event_map->bigin();
	if ((itr = DummyQFont::event_map->find(str)) == DummyQFont::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQFont::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFont::slot_map->bigin();
	if ((itr = DummyQFont::slot_map->find(str)) == DummyQFont::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQFont::connection(QObject *o)
{
	return;
}

KQFont::KQFont() : QFont()
{
	self = NULL;
	dummy = new DummyQFont();
	dummy->connection((QObject*)this);
}

KMETHOD QFont_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFont *qp = RawPtr_to(KQFont *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QFont]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFont]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QFont_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFont *qp = RawPtr_to(KQFont *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QFont]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFont]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QFont_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQFont *qp = (KQFont *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QFont_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQFont *qp = (KQFont *)p->rawptr;
		(void)qp;
	}
}

static int QFont_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QFont*>(p1->rawptr) == *static_cast<QFont*>(p2->rawptr) ? 0 : 1);
}

void KQFont::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQFont(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFont";
	cdef->free = QFont_free;
	cdef->reftrace = QFont_reftrace;
	cdef->compareTo = QFont_compareTo;
}

static knh_IntData_t QFontConstInt[] = {
	{"MixedCase", QFont::MixedCase},
	{"AllUppercase", QFont::AllUppercase},
	{"AllLowercase", QFont::AllLowercase},
	{"SmallCaps", QFont::SmallCaps},
	{"Capitalize", QFont::Capitalize},
	{"PercentageSpacing", QFont::PercentageSpacing},
	{"AbsoluteSpacing", QFont::AbsoluteSpacing},
	{"UltraCondensed", QFont::UltraCondensed},
	{"ExtraCondensed", QFont::ExtraCondensed},
	{"Condensed", QFont::Condensed},
	{"SemiCondensed", QFont::SemiCondensed},
	{"Unstretched", QFont::Unstretched},
	{"SemiExpanded", QFont::SemiExpanded},
	{"Expanded", QFont::Expanded},
	{"ExtraExpanded", QFont::ExtraExpanded},
	{"UltraExpanded", QFont::UltraExpanded},
	{"StyleNormal", QFont::StyleNormal},
	{"StyleItalic", QFont::StyleItalic},
	{"StyleOblique", QFont::StyleOblique},
	{"AnyStyle", QFont::AnyStyle},
	{"SansSerif", QFont::SansSerif},
	{"Helvetica", QFont::Helvetica},
	{"Serif", QFont::Serif},
	{"Times", QFont::Times},
	{"TypeWriter", QFont::TypeWriter},
	{"Courier", QFont::Courier},
	{"OldEnglish", QFont::OldEnglish},
	{"Decorative", QFont::Decorative},
	{"Monospace", QFont::Monospace},
	{"Fantasy", QFont::Fantasy},
	{"Cursive", QFont::Cursive},
	{"System", QFont::System},
	{"PreferDefault", QFont::PreferDefault},
	{"PreferBitmap", QFont::PreferBitmap},
	{"PreferDevice", QFont::PreferDevice},
	{"PreferOutline", QFont::PreferOutline},
	{"ForceOutline", QFont::ForceOutline},
	{"NoAntialias", QFont::NoAntialias},
	{"PreferAntialias", QFont::PreferAntialias},
	{"OpenGLCompatible", QFont::OpenGLCompatible},
	{"NoFontMerging", QFont::NoFontMerging},
	{"PreferMatch", QFont::PreferMatch},
	{"PreferQuality", QFont::PreferQuality},
	{"ForceIntegerMetrics", QFont::ForceIntegerMetrics},
	{"Light", QFont::Light},
	{"Normal", QFont::Normal},
	{"DemiBold", QFont::DemiBold},
	{"Bold", QFont::Bold},
	{"Black", QFont::Black},
	{NULL, 0}
};

DEFAPI(void) constQFont(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QFontConstInt);
}

