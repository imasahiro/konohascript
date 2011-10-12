//QImage QImage.new();
KMETHOD QImage_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQImage *ret_v = new KQImage();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QImage QImage.new(QSize size, int fmt);
KMETHOD QImage_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
	QImage::Format format = Int_to(QImage::Format, sfp[2]);
	KQImage *ret_v = new KQImage(size, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QImage QImage.new(int width, int height, int fmt);
KMETHOD QImage_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int width = Int_to(int, sfp[1]);
	int height = Int_to(int, sfp[2]);
	QImage::Format format = Int_to(QImage::Format, sfp[3]);
	KQImage *ret_v = new KQImage(width, height, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QImage QImage.new(String data, int width, int height, int fmt);
KMETHOD QImage_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	uchar*  data = RawPtr_to(uchar*, sfp[1]);
	int width = Int_to(int, sfp[2]);
	int height = Int_to(int, sfp[3]);
	QImage::Format format = Int_to(QImage::Format, sfp[4]);
	KQImage *ret_v = new KQImage(data, width, height, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QImage QImage.new(String data, int width, int height, int fmt);
KMETHOD QImage_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const uchar*  data = RawPtr_to(const uchar*, sfp[1]);
	int width = Int_to(int, sfp[2]);
	int height = Int_to(int, sfp[3]);
	QImage::Format format = Int_to(QImage::Format, sfp[4]);
	KQImage *ret_v = new KQImage(data, width, height, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QImage QImage.new(String data, int width, int height, int bytesPerLine, int fmt);
KMETHOD QImage_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	uchar*  data = RawPtr_to(uchar*, sfp[1]);
	int width = Int_to(int, sfp[2]);
	int height = Int_to(int, sfp[3]);
	int bytesPerLine = Int_to(int, sfp[4]);
	QImage::Format format = Int_to(QImage::Format, sfp[5]);
	KQImage *ret_v = new KQImage(data, width, height, bytesPerLine, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QImage QImage.new(String data, int width, int height, int bytesPerLine, int fmt);
KMETHOD QImage_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const uchar*  data = RawPtr_to(const uchar*, sfp[1]);
	int width = Int_to(int, sfp[2]);
	int height = Int_to(int, sfp[3]);
	int bytesPerLine = Int_to(int, sfp[4]);
	QImage::Format format = Int_to(QImage::Format, sfp[5]);
	KQImage *ret_v = new KQImage(data, width, height, bytesPerLine, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QImage QImage.new(String fileName, String fmt);
KMETHOD QImage_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString fileName = String_to(const QString, sfp[1]);
	const char*  format = RawPtr_to(const char*, sfp[2]);
	KQImage *ret_v = new KQImage(fileName, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QImage QImage.new(String fileName, String fmt);
KMETHOD QImage_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const char*  fileName = RawPtr_to(const char*, sfp[1]);
	const char*  format = RawPtr_to(const char*, sfp[2]);
	KQImage *ret_v = new KQImage(fileName, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QImage QImage.new(QImage image);
KMETHOD QImage_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QImage  image = *RawPtr_to(const QImage *, sfp[1]);
	KQImage *ret_v = new KQImage(image);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QImage.allGray();
KMETHOD QImage_allGray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->allGray();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QImage.bitPlaneCount();
KMETHOD QImage_bitPlaneCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->bitPlaneCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QImage.bits();
KMETHOD QImage_bits(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		uchar* ret_v = qp->bits();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (uchar*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QImage.bits();
KMETHOD QImage_bits(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const uchar* ret_v = qp->bits();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (uchar*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//int QImage.byteCount();
KMETHOD QImage_byteCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->byteCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QImage.bytesPerLine();
KMETHOD QImage_bytesPerLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->bytesPerLine();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QImage.cacheKey();
KMETHOD QImage_cacheKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		qint64 ret_v = qp->cacheKey();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRgb QImage.getColor(int i);
KMETHOD QImage_getColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QRgb ret_v = qp->color(i);
		QRgb *ret_v_ = new QRgb(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QImage.getColorCount();
KMETHOD QImage_getColorCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->colorCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QImage.constBits();
KMETHOD QImage_constBits(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const uchar* ret_v = qp->constBits();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (uchar*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QImage.constScanLine(int i);
KMETHOD QImage_constScanLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		const uchar* ret_v = qp->constScanLine(i);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (uchar*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QImage QImage.convertToFormat(int fmt, int flags);
KMETHOD QImage_convertToFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		QImage::Format format = Int_to(QImage::Format, sfp[1]);
		Qt::ImageConversionFlags flags = Int_to(Qt::ImageConversionFlags, sfp[2]);
		QImage ret_v = qp->convertToFormat(format, flags);
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QImage QImage.copy(QRect rectangle);
KMETHOD QImage_copy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		QImage ret_v = qp->copy(rectangle);
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QImage QImage.copy(int x, int y, int width, int height);
KMETHOD QImage_copy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		QImage ret_v = qp->copy(x, y, width, height);
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QImage QImage.createAlphaMask(int flags);
KMETHOD QImage_createAlphaMask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		Qt::ImageConversionFlags flags = Int_to(Qt::ImageConversionFlags, sfp[1]);
		QImage ret_v = qp->createAlphaMask(flags);
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QImage QImage.createHeuristicMask(boolean clipTight);
KMETHOD QImage_createHeuristicMask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		bool clipTight = Boolean_to(bool, sfp[1]);
		QImage ret_v = qp->createHeuristicMask(clipTight);
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QImage QImage.createMaskFromColor(QRgb color, int mode);
KMETHOD QImage_createMaskFromColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		QRgb  color = *RawPtr_to(QRgb *, sfp[1]);
		Qt::MaskMode mode = Int_to(Qt::MaskMode, sfp[2]);
		QImage ret_v = qp->createMaskFromColor(color, mode);
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QImage.depth();
KMETHOD QImage_depth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->depth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QImage.getDotsPerMeterX();
KMETHOD QImage_getDotsPerMeterX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->dotsPerMeterX();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QImage.getDotsPerMeterY();
KMETHOD QImage_getDotsPerMeterY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->dotsPerMeterY();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QImage.fill(int pixelValue);
KMETHOD QImage_fill(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		uint  pixelValue = *RawPtr_to(uint *, sfp[1]);
		qp->fill(pixelValue);
	}
	RETURNvoid_();
}

//int QImage.fmt();
KMETHOD QImage_format(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		QImage::Format ret_v = qp->format();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QImage.hasAlphaChannel();
KMETHOD QImage_hasAlphaChannel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->hasAlphaChannel();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QImage.height();
KMETHOD QImage_height(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->height();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QImage.invertPixels(int mode);
KMETHOD QImage_invertPixels(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		QImage::InvertMode mode = Int_to(QImage::InvertMode, sfp[1]);
		qp->invertPixels(mode);
	}
	RETURNvoid_();
}

//boolean QImage.isGrayscale();
KMETHOD QImage_isGrayscale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isGrayscale();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

////boolean QImage.isNull();
KMETHOD QImage_isNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isNull();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QImage.load(String fileName, String fmt);
KMETHOD QImage_load(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		const char*  format = RawPtr_to(const char*, sfp[2]);
		bool ret_v = qp->load(fileName, format);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QImage.load(QIODevice device, String fmt);
KMETHOD QImage_load(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		QIODevice*  device = RawPtr_to(QIODevice*, sfp[1]);
		const char*  format = RawPtr_to(const char*, sfp[2]);
		bool ret_v = qp->load(device, format);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//boolean QImage.loadFromData(String data, int len, String fmt);
KMETHOD QImage_loadFromData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const uchar*  data = RawPtr_to(const uchar*, sfp[1]);
		int len = Int_to(int, sfp[2]);
		const char*  format = RawPtr_to(const char*, sfp[3]);
		bool ret_v = qp->loadFromData(data, len, format);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QImage.loadFromData(QByteArray data, String fmt);
KMETHOD QImage_loadFromData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const QByteArray  data = *RawPtr_to(const QByteArray *, sfp[1]);
		const char*  format = RawPtr_to(const char*, sfp[2]);
		bool ret_v = qp->loadFromData(data, format);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//QImage QImage.mirrored(boolean horizontal, boolean vertical);
KMETHOD QImage_mirrored(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		bool horizontal = Boolean_to(bool, sfp[1]);
		bool vertical = Boolean_to(bool, sfp[2]);
		QImage ret_v = qp->mirrored(horizontal, vertical);
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QImage.offset();
KMETHOD QImage_offset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		QPoint ret_v = qp->offset();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRgb QImage.getPixel(QPoint position);
KMETHOD QImage_getPixel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		QRgb ret_v = qp->pixel(position);
		QRgb *ret_v_ = new QRgb(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRgb QImage.getPixel(int x, int y);
KMETHOD QImage_getPixel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		QRgb ret_v = qp->pixel(x, y);
		QRgb *ret_v_ = new QRgb(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//int QImage.pixelIndex(QPoint position);
KMETHOD QImage_pixelIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		int ret_v = qp->pixelIndex(position);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QImage.pixelIndex(int x, int y);
KMETHOD QImage_pixelIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int ret_v = qp->pixelIndex(x, y);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//QRect QImage.rect();
KMETHOD QImage_rect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		QRect ret_v = qp->rect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QImage QImage.rgbSwapped();
KMETHOD QImage_rgbSwapped(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		QImage ret_v = qp->rgbSwapped();
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QImage.save(String fileName, String fmt, int quality);
KMETHOD QImage_save(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		const char*  format = RawPtr_to(const char*, sfp[2]);
		int quality = Int_to(int, sfp[3]);
		bool ret_v = qp->save(fileName, format, quality);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QImage.save(QIODevice device, String fmt, int quality);
KMETHOD QImage_save(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		QIODevice*  device = RawPtr_to(QIODevice*, sfp[1]);
		const char*  format = RawPtr_to(const char*, sfp[2]);
		int quality = Int_to(int, sfp[3]);
		bool ret_v = qp->save(device, format, quality);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//QImage QImage.scaled(QSize size, int aspectRatioMode, int transformMode);
KMETHOD QImage_scaled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		Qt::AspectRatioMode aspectRatioMode = Int_to(Qt::AspectRatioMode, sfp[2]);
		Qt::TransformationMode transformMode = Int_to(Qt::TransformationMode, sfp[3]);
		QImage ret_v = qp->scaled(size, aspectRatioMode, transformMode);
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QImage QImage.scaled(int width, int height, int aspectRatioMode, int transformMode);
KMETHOD QImage_scaled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int width = Int_to(int, sfp[1]);
		int height = Int_to(int, sfp[2]);
		Qt::AspectRatioMode aspectRatioMode = Int_to(Qt::AspectRatioMode, sfp[3]);
		Qt::TransformationMode transformMode = Int_to(Qt::TransformationMode, sfp[4]);
		QImage ret_v = qp->scaled(width, height, aspectRatioMode, transformMode);
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QImage QImage.scaledToHeight(int height, int mode);
KMETHOD QImage_scaledToHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int height = Int_to(int, sfp[1]);
		Qt::TransformationMode mode = Int_to(Qt::TransformationMode, sfp[2]);
		QImage ret_v = qp->scaledToHeight(height, mode);
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QImage QImage.scaledToWidth(int width, int mode);
KMETHOD QImage_scaledToWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int width = Int_to(int, sfp[1]);
		Qt::TransformationMode mode = Int_to(Qt::TransformationMode, sfp[2]);
		QImage ret_v = qp->scaledToWidth(width, mode);
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QImage.scanLine(int i);
KMETHOD QImage_scanLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		uchar* ret_v = qp->scanLine(i);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (uchar*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QImage.scanLine(int i);
KMETHOD QImage_scanLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		const uchar* ret_v = qp->scanLine(i);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (uchar*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//void QImage.setColor(int index, QRgb colorValue);
KMETHOD QImage_setColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QRgb  colorValue = *RawPtr_to(QRgb *, sfp[2]);
		qp->setColor(index, colorValue);
	}
	RETURNvoid_();
}

//void QImage.setColorCount(int colorCount);
KMETHOD QImage_setColorCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int colorCount = Int_to(int, sfp[1]);
		qp->setColorCount(colorCount);
	}
	RETURNvoid_();
}

//void QImage.setDotsPerMeterX(int x);
KMETHOD QImage_setDotsPerMeterX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		qp->setDotsPerMeterX(x);
	}
	RETURNvoid_();
}

//void QImage.setDotsPerMeterY(int y);
KMETHOD QImage_setDotsPerMeterY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int y = Int_to(int, sfp[1]);
		qp->setDotsPerMeterY(y);
	}
	RETURNvoid_();
}

//void QImage.setOffset(QPoint offset);
KMETHOD QImage_setOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const QPoint  offset = *RawPtr_to(const QPoint *, sfp[1]);
		qp->setOffset(offset);
	}
	RETURNvoid_();
}

//void QImage.setPixel(QPoint position, int index_or_rgb);
KMETHOD QImage_setPixel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[1]);
		uint  index_or_rgb = *RawPtr_to(uint *, sfp[2]);
		qp->setPixel(position, index_or_rgb);
	}
	RETURNvoid_();
}

/*
//void QImage.setPixel(int x, int y, int index_or_rgb);
KMETHOD QImage_setPixel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		uint  index_or_rgb = *RawPtr_to(uint *, sfp[3]);
		qp->setPixel(x, y, index_or_rgb);
	}
	RETURNvoid_();
}
*/
//void QImage.setText(String key, String text);
KMETHOD QImage_setText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const QString key = String_to(const QString, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		qp->setText(key, text);
	}
	RETURNvoid_();
}

//QSize QImage.size();
KMETHOD QImage_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->size();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QImage.getText(String key);
KMETHOD QImage_getText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const QString key = String_to(const QString, sfp[1]);
		QString ret_v = qp->text(key);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

////QImage QImage.transformed(QMatrix matrix, int mode);
KMETHOD QImage_transformed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const QMatrix  matrix = *RawPtr_to(const QMatrix *, sfp[1]);
		Qt::TransformationMode mode = Int_to(Qt::TransformationMode, sfp[2]);
		QImage ret_v = qp->transformed(matrix, mode);
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
////QImage QImage.transformed(QTransform matrix, int mode);
KMETHOD QImage_transformed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const QTransform  matrix = *RawPtr_to(const QTransform *, sfp[1]);
		Qt::TransformationMode mode = Int_to(Qt::TransformationMode, sfp[2]);
		QImage ret_v = qp->transformed(matrix, mode);
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//boolean QImage.valid(QPoint pos);
KMETHOD QImage_valid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		bool ret_v = qp->valid(pos);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QImage.valid(int x, int y);
KMETHOD QImage_valid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		bool ret_v = qp->valid(x, y);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//int QImage.width();
KMETHOD QImage_width(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->width();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QImage QImage.fromData(String data, int size, String fmt);
KMETHOD QImage_fromData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const uchar*  data = RawPtr_to(const uchar*, sfp[1]);
		int size = Int_to(int, sfp[2]);
		const char*  format = RawPtr_to(const char*, sfp[3]);
		QImage ret_v = qp->fromData(data, size, format);
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QImage QImage.fromData(QByteArray data, String fmt);
KMETHOD QImage_fromData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const QByteArray  data = *RawPtr_to(const QByteArray *, sfp[1]);
		const char*  format = RawPtr_to(const char*, sfp[2]);
		QImage ret_v = qp->fromData(data, format);
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QMatrix QImage.trueMatrix(QMatrix matrix, int width, int height);
KMETHOD QImage_trueMatrix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const QMatrix  matrix = *RawPtr_to(const QMatrix *, sfp[1]);
		int width = Int_to(int, sfp[2]);
		int height = Int_to(int, sfp[3]);
		QMatrix ret_v = qp->trueMatrix(matrix, width, height);
		QMatrix *ret_v_ = new QMatrix(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QTransform QImage.trueMatrix(QTransform matrix, int width, int height);
KMETHOD QImage_trueMatrix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImage *  qp = RawPtr_to(QImage *, sfp[0]);
	if (qp != NULL) {
		const QTransform  matrix = *RawPtr_to(const QTransform *, sfp[1]);
		int width = Int_to(int, sfp[2]);
		int height = Int_to(int, sfp[3]);
		QTransform ret_v = qp->trueMatrix(matrix, width, height);
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/

DummyQImage::DummyQImage()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQImage::setSelf(knh_RawPtr_t *ptr)
{
	DummyQImage::self = ptr;
	DummyQPaintDevice::setSelf(ptr);
}

bool DummyQImage::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQPaintDevice::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQImage::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQImage::event_map->bigin();
	if ((itr = DummyQImage::event_map->find(str)) == DummyQImage::event_map->end()) {
		bool ret;
		ret = DummyQPaintDevice::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQImage::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQImage::slot_map->bigin();
	if ((itr = DummyQImage::event_map->find(str)) == DummyQImage::slot_map->end()) {
		bool ret;
		ret = DummyQPaintDevice::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQImage::KQImage() : QImage()
{
	self = NULL;
}

KMETHOD QImage_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQImage *qp = RawPtr_to(KQImage *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QImage]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQImage::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QImage]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QImage_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQImage *qp = RawPtr_to(KQImage *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QImage]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQImage::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QImage]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QImage_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQImage *qp = (KQImage *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QImage_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQImage *qp = (KQImage *)p->rawptr;
		(void)qp;
	}
}

static int QImage_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QImage*>(p1->rawptr) == *static_cast<QImage*>(p2->rawptr) ? 0 : 1);
}

DEFAPI(void) defQImage(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QImage";
	cdef->free = QImage_free;
	cdef->reftrace = QImage_reftrace;
	cdef->compareTo = QImage_compareTo;
}

static knh_IntData_t QImageConstInt[] = {
	{"Format_Invalid", QImage::Format_Invalid},
	{"Format_Mono", QImage::Format_Mono},
	{"Format_MonoLSB", QImage::Format_MonoLSB},
	{"Format_Indexed8", QImage::Format_Indexed8},
	{"Format_RGB32", QImage::Format_RGB32},
	{"Format_ARGB32", QImage::Format_ARGB32},
	{"Format_ARGB32_Premultiplied", QImage::Format_ARGB32_Premultiplied},
	{"Format_RGB16", QImage::Format_RGB16},
	{"Format_ARGB8565_Premultiplied", QImage::Format_ARGB8565_Premultiplied},
	{"Format_RGB666", QImage::Format_RGB666},
	{"Format_ARGB6666_Premultiplied", QImage::Format_ARGB6666_Premultiplied},
	{"Format_RGB555", QImage::Format_RGB555},
	{"Format_ARGB8555_Premultiplied", QImage::Format_ARGB8555_Premultiplied},
	{"Format_RGB888", QImage::Format_RGB888},
	{"Format_RGB444", QImage::Format_RGB444},
	{"Format_ARGB4444_Premultiplied", QImage::Format_ARGB4444_Premultiplied},
	{"InvertRgb", QImage::InvertRgb},
	{"InvertRgba", QImage::InvertRgba},
	{NULL, 0}
};

DEFAPI(void) constQImage(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QImageConstInt);
}

