//QColor QColor.new();
KMETHOD QColor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQColor *ret_v = new KQColor();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QColor QColor.new(int r, int g, int b, int a);
KMETHOD QColor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int r = Int_to(int, sfp[1]);
	int g = Int_to(int, sfp[2]);
	int b = Int_to(int, sfp[3]);
	int a = Int_to(int, sfp[4]);
	KQColor *ret_v = new KQColor(r, g, b, a);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QColor QColor.new(QRgb color);
KMETHOD QColor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRgb  color = *RawPtr_to(QRgb *, sfp[1]);
	KQColor *ret_v = new KQColor(color);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QColor QColor.new(String name);
KMETHOD QColor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString name = String_to(const QString, sfp[1]);
	KQColor *ret_v = new KQColor(name);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QColor QColor.new(String name);
KMETHOD QColor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const char*  name = RawPtr_to(const char*, sfp[1]);
	KQColor *ret_v = new KQColor(name);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QColor QColor.new(QColor color);
KMETHOD QColor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QColor  color = *RawPtr_to(const QColor *, sfp[1]);
	KQColor *ret_v = new KQColor(color);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QColor QColor.new(int color);
KMETHOD QColor_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::GlobalColor color = Int_to(Qt::GlobalColor, sfp[1]);
	KQColor *ret_v = new KQColor(color);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QColor.getAlpha();
KMETHOD QColor_getAlpha(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int ret_v = qp->alpha();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QColor.getAlphaF();
KMETHOD QColor_getAlphaF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->alphaF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QColor.black();
KMETHOD QColor_black(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int ret_v = qp->black();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QColor.blackF();
KMETHOD QColor_blackF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->blackF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QColor.getBlue();
KMETHOD QColor_getBlue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int ret_v = qp->blue();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QColor.getBlueF();
KMETHOD QColor_getBlueF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->blueF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QColor QColor.convertTo(int colorSpec);
KMETHOD QColor_convertTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		QColor::Spec colorSpec = Int_to(QColor::Spec, sfp[1]);
		QColor ret_v = qp->convertTo(colorSpec);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QColor.cyan();
KMETHOD QColor_cyan(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int ret_v = qp->cyan();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QColor.cyanF();
KMETHOD QColor_cyanF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->cyanF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QColor QColor.darker(int factor);
KMETHOD QColor_darker(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int factor = Int_to(int, sfp[1]);
		QColor ret_v = qp->darker(factor);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QColor.getCmyk(int c, int m, int y, int k, int a);
KMETHOD QColor_getCmyk(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int* c = Int_to(int*, sfp[1]);
		int* m = Int_to(int*, sfp[2]);
		int* y = Int_to(int*, sfp[3]);
		int* k = Int_to(int*, sfp[4]);
		int* a = Int_to(int*, sfp[5]);
		qp->getCmyk(c, m, y, k, a);
	}
	RETURNvoid_();
}

//void QColor.getCmykF(float c, float m, float y, float k, float a);
KMETHOD QColor_getCmykF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal*  c = RawPtr_to(qreal*, sfp[1]);
		qreal*  m = RawPtr_to(qreal*, sfp[2]);
		qreal*  y = RawPtr_to(qreal*, sfp[3]);
		qreal*  k = RawPtr_to(qreal*, sfp[4]);
		qreal*  a = RawPtr_to(qreal*, sfp[5]);
		qp->getCmykF(c, m, y, k, a);
	}
	RETURNvoid_();
}

//void QColor.getHsl(int h, int s, int l, int a);
KMETHOD QColor_getHsl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int* h = Int_to(int*, sfp[1]);
		int* s = Int_to(int*, sfp[2]);
		int* l = Int_to(int*, sfp[3]);
		int* a = Int_to(int*, sfp[4]);
		qp->getHsl(h, s, l, a);
	}
	RETURNvoid_();
}

//void QColor.getHslF(float h, float s, float l, float a);
KMETHOD QColor_getHslF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal*  h = RawPtr_to(qreal*, sfp[1]);
		qreal*  s = RawPtr_to(qreal*, sfp[2]);
		qreal*  l = RawPtr_to(qreal*, sfp[3]);
		qreal*  a = RawPtr_to(qreal*, sfp[4]);
		qp->getHslF(h, s, l, a);
	}
	RETURNvoid_();
}

//void QColor.getHsv(int h, int s, int v, int a);
KMETHOD QColor_getHsv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int* h = Int_to(int*, sfp[1]);
		int* s = Int_to(int*, sfp[2]);
		int* v = Int_to(int*, sfp[3]);
		int* a = Int_to(int*, sfp[4]);
		qp->getHsv(h, s, v, a);
	}
	RETURNvoid_();
}

//void QColor.getHsvF(float h, float s, float v, float a);
KMETHOD QColor_getHsvF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal*  h = RawPtr_to(qreal*, sfp[1]);
		qreal*  s = RawPtr_to(qreal*, sfp[2]);
		qreal*  v = RawPtr_to(qreal*, sfp[3]);
		qreal*  a = RawPtr_to(qreal*, sfp[4]);
		qp->getHsvF(h, s, v, a);
	}
	RETURNvoid_();
}

//void QColor.getRgb(int r, int g, int b, int a);
KMETHOD QColor_getRgb(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int* r = Int_to(int*, sfp[1]);
		int* g = Int_to(int*, sfp[2]);
		int* b = Int_to(int*, sfp[3]);
		int* a = Int_to(int*, sfp[4]);
		qp->getRgb(r, g, b, a);
	}
	RETURNvoid_();
}

//void QColor.getRgbF(float r, float g, float b, float a);
KMETHOD QColor_getRgbF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal*  r = RawPtr_to(qreal*, sfp[1]);
		qreal*  g = RawPtr_to(qreal*, sfp[2]);
		qreal*  b = RawPtr_to(qreal*, sfp[3]);
		qreal*  a = RawPtr_to(qreal*, sfp[4]);
		qp->getRgbF(r, g, b, a);
	}
	RETURNvoid_();
}

//int QColor.getGreen();
KMETHOD QColor_getGreen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int ret_v = qp->green();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QColor.getGreenF();
KMETHOD QColor_getGreenF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->greenF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QColor.hslHue();
KMETHOD QColor_hslHue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int ret_v = qp->hslHue();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QColor.hslHueF();
KMETHOD QColor_hslHueF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->hslHueF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QColor.hslSaturation();
KMETHOD QColor_hslSaturation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int ret_v = qp->hslSaturation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QColor.hslSaturationF();
KMETHOD QColor_hslSaturationF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->hslSaturationF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QColor.hsvHue();
KMETHOD QColor_hsvHue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int ret_v = qp->hsvHue();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QColor.hsvHueF();
KMETHOD QColor_hsvHueF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->hsvHueF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QColor.hsvSaturation();
KMETHOD QColor_hsvSaturation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int ret_v = qp->hsvSaturation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QColor.hsvSaturationF();
KMETHOD QColor_hsvSaturationF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->hsvSaturationF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QColor.hue();
KMETHOD QColor_hue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int ret_v = qp->hue();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QColor.hueF();
KMETHOD QColor_hueF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->hueF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QColor QColor.lighter(int factor);
KMETHOD QColor_lighter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int factor = Int_to(int, sfp[1]);
		QColor ret_v = qp->lighter(factor);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QColor.lightness();
KMETHOD QColor_lightness(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int ret_v = qp->lightness();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QColor.lightnessF();
KMETHOD QColor_lightnessF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->lightnessF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QColor.magenta();
KMETHOD QColor_magenta(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int ret_v = qp->magenta();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QColor.magentaF();
KMETHOD QColor_magentaF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->magentaF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//String QColor.name();
KMETHOD QColor_name(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		QString ret_v = qp->name();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QColor.getRed();
KMETHOD QColor_getRed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int ret_v = qp->red();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QColor.getRedF();
KMETHOD QColor_getRedF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->redF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QRgb QColor.rgb();
KMETHOD QColor_rgb(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		QRgb ret_v = qp->rgb();
		QRgb *ret_v_ = new QRgb(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRgb QColor.getRgba();
KMETHOD QColor_getRgba(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		QRgb ret_v = qp->rgba();
		QRgb *ret_v_ = new QRgb(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QColor.saturation();
KMETHOD QColor_saturation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int ret_v = qp->saturation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QColor.saturationF();
KMETHOD QColor_saturationF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->saturationF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QColor.setAlpha(int alpha);
KMETHOD QColor_setAlpha(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int alpha = Int_to(int, sfp[1]);
		qp->setAlpha(alpha);
	}
	RETURNvoid_();
}

//void QColor.setAlphaF(float alpha);
KMETHOD QColor_setAlphaF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal alpha = Float_to(qreal, sfp[1]);
		qp->setAlphaF(alpha);
	}
	RETURNvoid_();
}

//void QColor.setBlue(int blue);
KMETHOD QColor_setBlue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int blue = Int_to(int, sfp[1]);
		qp->setBlue(blue);
	}
	RETURNvoid_();
}

//void QColor.setBlueF(float blue);
KMETHOD QColor_setBlueF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal blue = Float_to(qreal, sfp[1]);
		qp->setBlueF(blue);
	}
	RETURNvoid_();
}

//void QColor.setCmyk(int c, int m, int y, int k, int a);
KMETHOD QColor_setCmyk(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int c = Int_to(int, sfp[1]);
		int m = Int_to(int, sfp[2]);
		int y = Int_to(int, sfp[3]);
		int k = Int_to(int, sfp[4]);
		int a = Int_to(int, sfp[5]);
		qp->setCmyk(c, m, y, k, a);
	}
	RETURNvoid_();
}

//void QColor.setCmykF(float c, float m, float y, float k, float a);
KMETHOD QColor_setCmykF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal c = Float_to(qreal, sfp[1]);
		qreal m = Float_to(qreal, sfp[2]);
		qreal y = Float_to(qreal, sfp[3]);
		qreal k = Float_to(qreal, sfp[4]);
		qreal a = Float_to(qreal, sfp[5]);
		qp->setCmykF(c, m, y, k, a);
	}
	RETURNvoid_();
}

//void QColor.setGreen(int green);
KMETHOD QColor_setGreen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int green = Int_to(int, sfp[1]);
		qp->setGreen(green);
	}
	RETURNvoid_();
}

//void QColor.setGreenF(float green);
KMETHOD QColor_setGreenF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal green = Float_to(qreal, sfp[1]);
		qp->setGreenF(green);
	}
	RETURNvoid_();
}

//void QColor.setHsl(int h, int s, int l, int a);
KMETHOD QColor_setHsl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int h = Int_to(int, sfp[1]);
		int s = Int_to(int, sfp[2]);
		int l = Int_to(int, sfp[3]);
		int a = Int_to(int, sfp[4]);
		qp->setHsl(h, s, l, a);
	}
	RETURNvoid_();
}

//void QColor.setHslF(float h, float s, float l, float a);
KMETHOD QColor_setHslF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal h = Float_to(qreal, sfp[1]);
		qreal s = Float_to(qreal, sfp[2]);
		qreal l = Float_to(qreal, sfp[3]);
		qreal a = Float_to(qreal, sfp[4]);
		qp->setHslF(h, s, l, a);
	}
	RETURNvoid_();
}

//void QColor.setHsv(int h, int s, int v, int a);
KMETHOD QColor_setHsv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int h = Int_to(int, sfp[1]);
		int s = Int_to(int, sfp[2]);
		int v = Int_to(int, sfp[3]);
		int a = Int_to(int, sfp[4]);
		qp->setHsv(h, s, v, a);
	}
	RETURNvoid_();
}

//void QColor.setHsvF(float h, float s, float v, float a);
KMETHOD QColor_setHsvF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal h = Float_to(qreal, sfp[1]);
		qreal s = Float_to(qreal, sfp[2]);
		qreal v = Float_to(qreal, sfp[3]);
		qreal a = Float_to(qreal, sfp[4]);
		qp->setHsvF(h, s, v, a);
	}
	RETURNvoid_();
}

//void QColor.setNamedColor(String name);
KMETHOD QColor_setNamedColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		qp->setNamedColor(name);
	}
	RETURNvoid_();
}

//void QColor.setRed(int red);
KMETHOD QColor_setRed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int red = Int_to(int, sfp[1]);
		qp->setRed(red);
	}
	RETURNvoid_();
}

//void QColor.setRedF(float red);
KMETHOD QColor_setRedF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal red = Float_to(qreal, sfp[1]);
		qp->setRedF(red);
	}
	RETURNvoid_();
}

//void QColor.setRgb(int r, int g, int b, int a);
KMETHOD QColor_setRgb(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int r = Int_to(int, sfp[1]);
		int g = Int_to(int, sfp[2]);
		int b = Int_to(int, sfp[3]);
		int a = Int_to(int, sfp[4]);
		qp->setRgb(r, g, b, a);
	}
	RETURNvoid_();
}

/*
//void QColor.setRgb(QRgb rgb);
KMETHOD QColor_setRgb(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		QRgb  rgb = *RawPtr_to(QRgb *, sfp[1]);
		qp->setRgb(rgb);
	}
	RETURNvoid_();
}
*/
//void QColor.setRgbF(float r, float g, float b, float a);
KMETHOD QColor_setRgbF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal r = Float_to(qreal, sfp[1]);
		qreal g = Float_to(qreal, sfp[2]);
		qreal b = Float_to(qreal, sfp[3]);
		qreal a = Float_to(qreal, sfp[4]);
		qp->setRgbF(r, g, b, a);
	}
	RETURNvoid_();
}

//void QColor.setRgba(QRgb rgba);
KMETHOD QColor_setRgba(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		QRgb  rgba = *RawPtr_to(QRgb *, sfp[1]);
		qp->setRgba(rgba);
	}
	RETURNvoid_();
}

//int QColor.spec();
KMETHOD QColor_spec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		QColor::Spec ret_v = qp->spec();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QColor QColor.toCmyk();
KMETHOD QColor_toCmyk(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		QColor ret_v = qp->toCmyk();
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QColor QColor.toHsl();
KMETHOD QColor_toHsl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		QColor ret_v = qp->toHsl();
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QColor QColor.toHsv();
KMETHOD QColor_toHsv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		QColor ret_v = qp->toHsv();
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QColor QColor.toRgb();
KMETHOD QColor_toRgb(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		QColor ret_v = qp->toRgb();
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QColor.value();
KMETHOD QColor_value(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int ret_v = qp->value();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QColor.valueF();
KMETHOD QColor_valueF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->valueF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QColor.yellow();
KMETHOD QColor_yellow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		int ret_v = qp->yellow();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QColor.yellowF();
KMETHOD QColor_yellowF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *  qp = RawPtr_to(QColor *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->yellowF();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QColor QColor.fromCmyk(int c, int m, int y, int k, int a);
KMETHOD QColor_fromCmyk(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int c = Int_to(int, sfp[1]);
		int m = Int_to(int, sfp[2]);
		int y = Int_to(int, sfp[3]);
		int k = Int_to(int, sfp[4]);
		int a = Int_to(int, sfp[5]);
		QColor ret_v = QColor::fromCmyk(c, m, y, k, a);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QColor QColor.fromCmykF(float c, float m, float y, float k, float a);
KMETHOD QColor_fromCmykF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		qreal c = Float_to(qreal, sfp[1]);
		qreal m = Float_to(qreal, sfp[2]);
		qreal y = Float_to(qreal, sfp[3]);
		qreal k = Float_to(qreal, sfp[4]);
		qreal a = Float_to(qreal, sfp[5]);
		QColor ret_v = QColor::fromCmykF(c, m, y, k, a);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QColor QColor.fromHsl(int h, int s, int l, int a);
KMETHOD QColor_fromHsl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int h = Int_to(int, sfp[1]);
		int s = Int_to(int, sfp[2]);
		int l = Int_to(int, sfp[3]);
		int a = Int_to(int, sfp[4]);
		QColor ret_v = QColor::fromHsl(h, s, l, a);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QColor QColor.fromHslF(float h, float s, float l, float a);
KMETHOD QColor_fromHslF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		qreal h = Float_to(qreal, sfp[1]);
		qreal s = Float_to(qreal, sfp[2]);
		qreal l = Float_to(qreal, sfp[3]);
		qreal a = Float_to(qreal, sfp[4]);
		QColor ret_v = QColor::fromHslF(h, s, l, a);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QColor QColor.fromHsv(int h, int s, int v, int a);
KMETHOD QColor_fromHsv(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int h = Int_to(int, sfp[1]);
		int s = Int_to(int, sfp[2]);
		int v = Int_to(int, sfp[3]);
		int a = Int_to(int, sfp[4]);
		QColor ret_v = QColor::fromHsv(h, s, v, a);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QColor QColor.fromHsvF(float h, float s, float v, float a);
KMETHOD QColor_fromHsvF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		qreal h = Float_to(qreal, sfp[1]);
		qreal s = Float_to(qreal, sfp[2]);
		qreal v = Float_to(qreal, sfp[3]);
		qreal a = Float_to(qreal, sfp[4]);
		QColor ret_v = QColor::fromHsvF(h, s, v, a);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QColor QColor.fromRgb(QRgb rgb);
KMETHOD QColor_fromRgb(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QRgb  rgb = *RawPtr_to(QRgb *, sfp[1]);
		QColor ret_v = QColor::fromRgb(rgb);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QColor QColor.fromRgb(int r, int g, int b, int a);
KMETHOD QColor_fromRgb(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int r = Int_to(int, sfp[1]);
		int g = Int_to(int, sfp[2]);
		int b = Int_to(int, sfp[3]);
		int a = Int_to(int, sfp[4]);
		QColor ret_v = QColor::fromRgb(r, g, b, a);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QColor QColor.fromRgbF(float r, float g, float b, float a);
KMETHOD QColor_fromRgbF(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		qreal r = Float_to(qreal, sfp[1]);
		qreal g = Float_to(qreal, sfp[2]);
		qreal b = Float_to(qreal, sfp[3]);
		qreal a = Float_to(qreal, sfp[4]);
		QColor ret_v = QColor::fromRgbF(r, g, b, a);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QColor QColor.fromRgba(QRgb rgba);
KMETHOD QColor_fromRgba(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QRgb  rgba = *RawPtr_to(QRgb *, sfp[1]);
		QColor ret_v = QColor::fromRgba(rgba);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QColor.isValidColor(String name);
KMETHOD QColor_isValidColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString name = String_to(const QString, sfp[1]);
		bool ret_v = QColor::isValidColor(name);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//Array<String> QColor.parents();
KMETHOD QColor_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColor *qp = RawPtr_to(QColor*, sfp[0]);
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

DummyQColor::DummyQColor()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQColor::setSelf(knh_RawPtr_t *ptr)
{
	DummyQColor::self = ptr;
}

bool DummyQColor::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQColor::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQColor::event_map->bigin();
	if ((itr = DummyQColor::event_map->find(str)) == DummyQColor::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQColor::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQColor::slot_map->bigin();
	if ((itr = DummyQColor::slot_map->find(str)) == DummyQColor::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQColor::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQColor::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQColor::connection(QObject *o)
{
	QColor *p = dynamic_cast<QColor*>(o);
	if (p != NULL) {
	}
}

KQColor::KQColor() : QColor()
{
	self = NULL;
	dummy = new DummyQColor();
}

KMETHOD QColor_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQColor *qp = RawPtr_to(KQColor *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QColor]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QColor]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QColor_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQColor *qp = RawPtr_to(KQColor *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QColor]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QColor]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QColor_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQColor *qp = (KQColor *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QColor_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQColor *qp = (KQColor *)p->rawptr;
//		KQColor *qp = static_cast<KQColor*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QColor_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QColor*>(p1->rawptr) == *static_cast<QColor*>(p2->rawptr) ? 0 : 1);
}

void KQColor::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QColorConstInt[] = {
	{"Rgb", QColor::Rgb},
	{"Hsv", QColor::Hsv},
	{"Cmyk", QColor::Cmyk},
	{"Hsl", QColor::Hsl},
	{"Invalid", QColor::Invalid},
	{NULL, 0}
};

DEFAPI(void) constQColor(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QColorConstInt);
}


DEFAPI(void) defQColor(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QColor";
	cdef->free = QColor_free;
	cdef->reftrace = QColor_reftrace;
	cdef->compareTo = QColor_compareTo;
}


