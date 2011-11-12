//QPixmap QPixmap.new();
KMETHOD QPixmap_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPixmap *ret_v = new KQPixmap();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPixmap QPixmap.new(int width, int height);
KMETHOD QPixmap_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int width = Int_to(int, sfp[1]);
	int height = Int_to(int, sfp[2]);
	KQPixmap *ret_v = new KQPixmap(width, height);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPixmap QPixmap.new(String fileName, String fmt, QtImageConversionFlags flags);
KMETHOD QPixmap_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString fileName = String_to(const QString, sfp[1]);
	const char*  format = RawPtr_to(const char*, sfp[2]);
	initFlag(flags, Qt::ImageConversionFlags, sfp[3]);
	KQPixmap *ret_v = new KQPixmap(fileName, format, flags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPixmap QPixmap.new(QPixmap pixmap);
KMETHOD QPixmap_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
	KQPixmap *ret_v = new KQPixmap(pixmap);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPixmap QPixmap.new(QSize size);
KMETHOD QPixmap_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
	KQPixmap *ret_v = new KQPixmap(size);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QPixmap.cacheKey();
KMETHOD QPixmap_cacheKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->cacheKey();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QPixmap.convertFromImage(QImage image, QtImageConversionFlags flags);
KMETHOD QPixmap_convertFromImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		const QImage  image = *RawPtr_to(const QImage *, sfp[1]);
		initFlag(flags, Qt::ImageConversionFlags, sfp[2]);
		bool ret_v = qp->convertFromImage(image, flags);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QPixmap QPixmap.copy(QRect rectangle);
KMETHOD QPixmap_copy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		QPixmap ret_v = qp->copy(rectangle);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPixmap QPixmap.copy(int x, int y, int width, int height);
KMETHOD QPixmap_copy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int width = Int_to(int, sfp[3]);
		int height = Int_to(int, sfp[4]);
		QPixmap ret_v = qp->copy(x, y, width, height);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QBitmap QPixmap.createHeuristicMask(boolean clipTight);
KMETHOD QPixmap_createHeuristicMask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		bool clipTight = Boolean_to(bool, sfp[1]);
		QBitmap ret_v = qp->createHeuristicMask(clipTight);
		QBitmap *ret_v_ = new QBitmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBitmap QPixmap.createMaskFromColor(QColor maskColor, int mode);
KMETHOD QPixmap_createMaskFromColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		const QColor  maskColor = *RawPtr_to(const QColor *, sfp[1]);
		Qt::MaskMode mode = Int_to(Qt::MaskMode, sfp[2]);
		QBitmap ret_v = qp->createMaskFromColor(maskColor, mode);
		QBitmap *ret_v_ = new QBitmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QBitmap QPixmap.createMaskFromColor(QColor maskColor);
KMETHOD QPixmap_createMaskFromColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		const QColor  maskColor = *RawPtr_to(const QColor *, sfp[1]);
		QBitmap ret_v = qp->createMaskFromColor(maskColor);
		QBitmap *ret_v_ = new QBitmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//int QPixmap.depth();
KMETHOD QPixmap_depth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		int ret_v = qp->depth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QPixmap.detach();
KMETHOD QPixmap_detach(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		qp->detach();
	}
	RETURNvoid_();
}

//void QPixmap.fill(QColor color);
KMETHOD QPixmap_fill(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		const QColor  color = *RawPtr_to(const QColor *, sfp[1]);
		qp->fill(color);
	}
	RETURNvoid_();
}

/*
//void QPixmap.fill(QWidget widget, QPoint offset);
KMETHOD QPixmap_fill(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[1]);
		const QPoint  offset = *RawPtr_to(const QPoint *, sfp[2]);
		qp->fill(widget, offset);
	}
	RETURNvoid_();
}
*/
/*
//void QPixmap.fill(QWidget widget, int x, int y);
KMETHOD QPixmap_fill(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[1]);
		int x = Int_to(int, sfp[2]);
		int y = Int_to(int, sfp[3]);
		qp->fill(widget, x, y);
	}
	RETURNvoid_();
}
*/
//boolean QPixmap.hasAlpha();
KMETHOD QPixmap_hasAlpha(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasAlpha();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPixmap.hasAlphaChannel();
KMETHOD QPixmap_hasAlphaChannel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasAlphaChannel();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QPixmap.height();
KMETHOD QPixmap_height(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		int ret_v = qp->height();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QPixmap.isQBitmap();
KMETHOD QPixmap_isQBitmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isQBitmap();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPixmap.load(String fileName, String fmt, QtImageConversionFlags flags);
KMETHOD QPixmap_load(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		const QString fileName = String_to(const QString, sfp[1]);
		const char*  format = RawPtr_to(const char*, sfp[2]);
		initFlag(flags, Qt::ImageConversionFlags, sfp[3]);
		bool ret_v = qp->load(fileName, format, flags);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPixmap.loadFromData(String data, int len, String fmt, QtImageConversionFlags flags);
KMETHOD QPixmap_loadFromData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		const uchar*  data = RawPtr_to(const uchar*, sfp[1]);
		uint  len = *RawPtr_to(uint *, sfp[2]);
		const char*  format = RawPtr_to(const char*, sfp[3]);
		initFlag(flags, Qt::ImageConversionFlags, sfp[4]);
		bool ret_v = qp->loadFromData(data, len, format, flags);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QPixmap.loadFromData(QByteArray data, String fmt, QtImageConversionFlags flags);
KMETHOD QPixmap_loadFromData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		const QByteArray  data = *RawPtr_to(const QByteArray *, sfp[1]);
		const char*  format = RawPtr_to(const char*, sfp[2]);
		initFlag(flags, Qt::ImageConversionFlags, sfp[3]);
		bool ret_v = qp->loadFromData(data, format, flags);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//QBitmap QPixmap.getMask();
KMETHOD QPixmap_getMask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		QBitmap ret_v = qp->mask();
		QBitmap *ret_v_ = new QBitmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QPixmap.rect();
KMETHOD QPixmap_rect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->rect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QPixmap.save(String fileName, String fmt, int quality);
KMETHOD QPixmap_save(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
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
//boolean QPixmap.save(QIODevice device, String fmt, int quality);
KMETHOD QPixmap_save(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
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
//QPixmap QPixmap.scaled(QSize size, int aspectRatioMode, int transformMode);
KMETHOD QPixmap_scaled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		Qt::AspectRatioMode aspectRatioMode = Int_to(Qt::AspectRatioMode, sfp[2]);
		Qt::TransformationMode transformMode = Int_to(Qt::TransformationMode, sfp[3]);
		QPixmap ret_v = qp->scaled(size, aspectRatioMode, transformMode);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPixmap QPixmap.scaled(int width, int height, int aspectRatioMode, int transformMode);
KMETHOD QPixmap_scaled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		int width = Int_to(int, sfp[1]);
		int height = Int_to(int, sfp[2]);
		Qt::AspectRatioMode aspectRatioMode = Int_to(Qt::AspectRatioMode, sfp[3]);
		Qt::TransformationMode transformMode = Int_to(Qt::TransformationMode, sfp[4]);
		QPixmap ret_v = qp->scaled(width, height, aspectRatioMode, transformMode);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QPixmap QPixmap.scaledToHeight(int height, int mode);
KMETHOD QPixmap_scaledToHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		int height = Int_to(int, sfp[1]);
		Qt::TransformationMode mode = Int_to(Qt::TransformationMode, sfp[2]);
		QPixmap ret_v = qp->scaledToHeight(height, mode);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPixmap QPixmap.scaledToWidth(int width, int mode);
KMETHOD QPixmap_scaledToWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		int width = Int_to(int, sfp[1]);
		Qt::TransformationMode mode = Int_to(Qt::TransformationMode, sfp[2]);
		QPixmap ret_v = qp->scaledToWidth(width, mode);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QPixmap.scroll(int dx, int dy, int x, int y, int width, int height, QRegion exposed);
KMETHOD QPixmap_scroll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		int dx = Int_to(int, sfp[1]);
		int dy = Int_to(int, sfp[2]);
		int x = Int_to(int, sfp[3]);
		int y = Int_to(int, sfp[4]);
		int width = Int_to(int, sfp[5]);
		int height = Int_to(int, sfp[6]);
		QRegion*  exposed = RawPtr_to(QRegion*, sfp[7]);
		qp->scroll(dx, dy, x, y, width, height, exposed);
	}
	RETURNvoid_();
}

/*
//void QPixmap.scroll(int dx, int dy, QRect rect, QRegion exposed);
KMETHOD QPixmap_scroll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		int dx = Int_to(int, sfp[1]);
		int dy = Int_to(int, sfp[2]);
		const QRect  rect = *RawPtr_to(const QRect *, sfp[3]);
		QRegion*  exposed = RawPtr_to(QRegion*, sfp[4]);
		qp->scroll(dx, dy, rect, exposed);
	}
	RETURNvoid_();
}
*/
//void QPixmap.setMask(QBitmap mask);
KMETHOD QPixmap_setMask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		const QBitmap  mask = *RawPtr_to(const QBitmap *, sfp[1]);
		qp->setMask(mask);
	}
	RETURNvoid_();
}

//QSize QPixmap.size();
KMETHOD QPixmap_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->size();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QImage QPixmap.toImage();
KMETHOD QPixmap_toImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		QImage ret_v = qp->toImage();
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QPixmap.width();
KMETHOD QPixmap_width(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPixmap *  qp = RawPtr_to(QPixmap *, sfp[0]);
	if (qp) {
		int ret_v = qp->width();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPixmap.defaultDepth();
KMETHOD QPixmap_defaultDepth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int ret_v = QPixmap::defaultDepth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPixmap QPixmap.fromImageOL(QImage image, QtImageConversionFlags flags);
KMETHOD QPixmap_fromImageOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QImage  image = *RawPtr_to(const QImage *, sfp[1]);
		initFlag(flags, Qt::ImageConversionFlags, sfp[2]);
		QPixmap ret_v = QPixmap::fromImage(image, flags);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPixmap QPixmap.fromImageOLReader(QImageReader imageReader, QtImageConversionFlags flags);
KMETHOD QPixmap_fromImageOLReader(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QImageReader*  imageReader = RawPtr_to(QImageReader*, sfp[1]);
		initFlag(flags, Qt::ImageConversionFlags, sfp[2]);
		QPixmap ret_v = QPixmap::fromImageReader(imageReader, flags);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPixmap QPixmap.grabWidget(QWidget widget, QRect rectangle);
KMETHOD QPixmap_grabWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[2]);
		QPixmap ret_v = QPixmap::grabWidget(widget, rectangle);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPixmap QPixmap.grabWidget(QWidget widget, int x, int y, int width, int height);
KMETHOD QPixmap_grabWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		int x = Int_to(int, sfp[2]);
		int y = Int_to(int, sfp[3]);
		int width = Int_to(int, sfp[4]);
		int height = Int_to(int, sfp[5]);
		QPixmap ret_v = QPixmap::grabWidget(widget, x, y, width, height);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QTransform QPixmap.trueMatrix(QTransform matrix, int width, int height);
KMETHOD QPixmap_trueMatrix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QTransform  matrix = *RawPtr_to(const QTransform *, sfp[1]);
		int width = Int_to(int, sfp[2]);
		int height = Int_to(int, sfp[3]);
		QTransform ret_v = QPixmap::trueMatrix(matrix, width, height);
		QTransform *ret_v_ = new QTransform(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QMatrix QPixmap.trueMatrix(QMatrix m, int w, int h);
KMETHOD QPixmap_trueMatrix(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QMatrix  m = *RawPtr_to(const QMatrix *, sfp[1]);
		int w = Int_to(int, sfp[2]);
		int h = Int_to(int, sfp[3]);
		QMatrix ret_v = QPixmap::trueMatrix(m, w, h);
		QMatrix *ret_v_ = new QMatrix(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/

DummyQPixmap::DummyQPixmap()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPixmap::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPixmap::self = ptr;
	DummyQPaintDevice::setSelf(ptr);
}

bool DummyQPixmap::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQPaintDevice::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQPixmap::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPixmap::event_map->bigin();
	if ((itr = DummyQPixmap::event_map->find(str)) == DummyQPixmap::event_map->end()) {
		bool ret = false;
		ret = DummyQPaintDevice::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPixmap::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPixmap::slot_map->bigin();
	if ((itr = DummyQPixmap::slot_map->find(str)) == DummyQPixmap::slot_map->end()) {
		bool ret = false;
		ret = DummyQPaintDevice::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQPixmap::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQPixmap::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQPaintDevice::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQPixmap::connection(QObject *o)
{
	QPixmap *p = dynamic_cast<QPixmap*>(o);
	if (p != NULL) {
	}
	DummyQPaintDevice::connection(o);
}

KQPixmap::KQPixmap() : QPixmap()
{
	self = NULL;
	dummy = new DummyQPixmap();
}

KMETHOD QPixmap_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPixmap *qp = RawPtr_to(KQPixmap *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPixmap]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPixmap]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPixmap_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPixmap *qp = RawPtr_to(KQPixmap *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPixmap]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPixmap]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPixmap_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPixmap *qp = (KQPixmap *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPixmap_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQPixmap *qp = (KQPixmap *)p->rawptr;
//		KQPixmap *qp = static_cast<KQPixmap*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPixmap_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQPixmap::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QPixmapConstInt[] = {
//	{"NoAlpha", QPixmap::NoAlpha},
//	{"PremultipliedAlpha", QPixmap::PremultipliedAlpha},
//	{"Alpha", QPixmap::Alpha},
//	{"ImplicitlyShared", QPixmap::ImplicitlyShared},
//	{"ExplicitlyShared", QPixmap::ExplicitlyShared},
	{NULL, 0}
};

DEFAPI(void) constQPixmap(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QPixmapConstInt);
}


DEFAPI(void) defQPixmap(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPixmap";
	cdef->free = QPixmap_free;
	cdef->reftrace = QPixmap_reftrace;
	cdef->compareTo = QPixmap_compareTo;
}


