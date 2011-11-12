//QImageReader QImageReader.new();
KMETHOD QImageReader_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQImageReader *ret_v = new KQImageReader();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QImageReader QImageReader.new(QIODevice device, QByteArray fmt);
KMETHOD QImageReader_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice*  device = RawPtr_to(QIODevice*, sfp[1]);
	const QByteArray  format = *RawPtr_to(const QByteArray *, sfp[2]);
	KQImageReader *ret_v = new KQImageReader(device, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QImageReader QImageReader.new(String fileName, QByteArray fmt);
KMETHOD QImageReader_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString fileName = String_to(const QString, sfp[1]);
	const QByteArray  format = *RawPtr_to(const QByteArray *, sfp[2]);
	KQImageReader *ret_v = new KQImageReader(fileName, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QImageReader.getAutoDetectImageFormat();
KMETHOD QImageReader_getAutoDetectImageFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		bool ret_v = qp->autoDetectImageFormat();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QColor QImageReader.getBackgroundColor();
KMETHOD QImageReader_getBackgroundColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		QColor ret_v = qp->backgroundColor();
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QImageReader.canRead();
KMETHOD QImageReader_canRead(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		bool ret_v = qp->canRead();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QRect QImageReader.getClipRect();
KMETHOD QImageReader_getClipRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->clipRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QImageReader.currentImageNumber();
KMETHOD QImageReader_currentImageNumber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		int ret_v = qp->currentImageNumber();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QRect QImageReader.currentImageRect();
KMETHOD QImageReader_currentImageRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->currentImageRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QImageReader.getDecideFormatFromContent();
KMETHOD QImageReader_getDecideFormatFromContent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		bool ret_v = qp->decideFormatFromContent();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QIODevice QImageReader.getDevice();
KMETHOD QImageReader_getDevice(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		QIODevice* ret_v = qp->device();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QIODevice*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QImageReader.error();
KMETHOD QImageReader_error(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		QImageReader::ImageReaderError ret_v = qp->error();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QImageReader.errorString();
KMETHOD QImageReader_errorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		QString ret_v = qp->errorString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QImageReader.getFileName();
KMETHOD QImageReader_getFileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		QString ret_v = qp->fileName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QImageReader.getFormat();
KMETHOD QImageReader_getFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->format();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QImageReader.imageCount();
KMETHOD QImageReader_imageCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		int ret_v = qp->imageCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QImageReader.imageFormat();
KMETHOD QImageReader_imageFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		QImage::Format ret_v = qp->imageFormat();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QImageReader.jumpToImage(int imageNumber);
KMETHOD QImageReader_jumpToImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		int imageNumber = Int_to(int, sfp[1]);
		bool ret_v = qp->jumpToImage(imageNumber);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QImageReader.jumpToNextImage();
KMETHOD QImageReader_jumpToNextImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		bool ret_v = qp->jumpToNextImage();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QImageReader.loopCount();
KMETHOD QImageReader_loopCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		int ret_v = qp->loopCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QImageReader.nextImageDelay();
KMETHOD QImageReader_nextImageDelay(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		int ret_v = qp->nextImageDelay();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QImageReader.getQuality();
KMETHOD QImageReader_getQuality(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		int ret_v = qp->quality();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QImage QImageReader.read();
KMETHOD QImageReader_read(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		QImage ret_v = qp->read();
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//boolean QImageReader.read(QImage image);
KMETHOD QImageReader_read(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		QImage*  image = RawPtr_to(QImage*, sfp[1]);
		bool ret_v = qp->read(image);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//QRect QImageReader.getScaledClipRect();
KMETHOD QImageReader_getScaledClipRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->scaledClipRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSize QImageReader.getScaledSize();
KMETHOD QImageReader_getScaledSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->scaledSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QImageReader.setAutoDetectImageFormat(boolean enabled);
KMETHOD QImageReader_setAutoDetectImageFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setAutoDetectImageFormat(enabled);
	}
	RETURNvoid_();
}

//void QImageReader.setBackgroundColor(QColor color);
KMETHOD QImageReader_setBackgroundColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		const QColor  color = *RawPtr_to(const QColor *, sfp[1]);
		qp->setBackgroundColor(color);
	}
	RETURNvoid_();
}

//void QImageReader.setClipRect(QRect rect);
KMETHOD QImageReader_setClipRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		qp->setClipRect(rect);
	}
	RETURNvoid_();
}

//void QImageReader.setDecideFormatFromContent(boolean ignored);
KMETHOD QImageReader_setDecideFormatFromContent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		bool ignored = Boolean_to(bool, sfp[1]);
		qp->setDecideFormatFromContent(ignored);
	}
	RETURNvoid_();
}

//void QImageReader.setDevice(QIODevice device);
KMETHOD QImageReader_setDevice(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		QIODevice*  device = RawPtr_to(QIODevice*, sfp[1]);
		qp->setDevice(device);
	}
	RETURNvoid_();
}

//void QImageReader.setFileName(String fileName);
KMETHOD QImageReader_setFileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		const QString fileName = String_to(const QString, sfp[1]);
		qp->setFileName(fileName);
	}
	RETURNvoid_();
}

//void QImageReader.setFormat(QByteArray fmt);
KMETHOD QImageReader_setFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		const QByteArray  format = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->setFormat(format);
	}
	RETURNvoid_();
}

//void QImageReader.setQuality(int quality);
KMETHOD QImageReader_setQuality(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		int quality = Int_to(int, sfp[1]);
		qp->setQuality(quality);
	}
	RETURNvoid_();
}

//void QImageReader.setScaledClipRect(QRect rect);
KMETHOD QImageReader_setScaledClipRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		qp->setScaledClipRect(rect);
	}
	RETURNvoid_();
}

//void QImageReader.setScaledSize(QSize size);
KMETHOD QImageReader_setScaledSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		qp->setScaledSize(size);
	}
	RETURNvoid_();
}

//QSize QImageReader.size();
KMETHOD QImageReader_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->size();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QImageReader.supportsAnimation();
KMETHOD QImageReader_supportsAnimation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		bool ret_v = qp->supportsAnimation();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QImageReader.supportsOption(int option);
KMETHOD QImageReader_supportsOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		QImageIOHandler::ImageOption option = Int_to(QImageIOHandler::ImageOption, sfp[1]);
		bool ret_v = qp->supportsOption(option);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QImageReader.text(String key);
KMETHOD QImageReader_text(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *  qp = RawPtr_to(QImageReader *, sfp[0]);
	if (qp) {
		const QString key = String_to(const QString, sfp[1]);
		QString ret_v = qp->text(key);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QByteArray QImageReader.imageFormat(String fileName);
KMETHOD QImageReader_imageFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString fileName = String_to(const QString, sfp[1]);
		QByteArray ret_v = QImageReader::imageFormat(fileName);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QByteArray QImageReader.imageFormat(QIODevice device);
KMETHOD QImageReader_imageFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QIODevice*  device = RawPtr_to(QIODevice*, sfp[1]);
		QByteArray ret_v = QImageReader::imageFormat(device);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//Array<QByteArray> QImageReader.supportedImageFormats();
KMETHOD QImageReader_supportedImageFormats(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QList<QByteArray> ret_v = QImageReader::supportedImageFormats();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QByteArray"));
		for (int n = 0; n < list_size; n++) {
			QByteArray *ret_v_ = new QByteArray(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//Array<String> QImageReader.parents();
KMETHOD QImageReader_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageReader *qp = RawPtr_to(QImageReader*, sfp[0]);
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

DummyQImageReader::DummyQImageReader()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQImageReader::setSelf(knh_RawPtr_t *ptr)
{
	DummyQImageReader::self = ptr;
}

bool DummyQImageReader::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQImageReader::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQImageReader::event_map->bigin();
	if ((itr = DummyQImageReader::event_map->find(str)) == DummyQImageReader::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQImageReader::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQImageReader::slot_map->bigin();
	if ((itr = DummyQImageReader::slot_map->find(str)) == DummyQImageReader::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQImageReader::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQImageReader::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQImageReader::connection(QObject *o)
{
	QImageReader *p = dynamic_cast<QImageReader*>(o);
	if (p != NULL) {
	}
}

KQImageReader::KQImageReader() : QImageReader()
{
	self = NULL;
	dummy = new DummyQImageReader();
}

KMETHOD QImageReader_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQImageReader *qp = RawPtr_to(KQImageReader *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QImageReader]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QImageReader]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QImageReader_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQImageReader *qp = RawPtr_to(KQImageReader *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QImageReader]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QImageReader]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QImageReader_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQImageReader *qp = (KQImageReader *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QImageReader_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQImageReader *qp = (KQImageReader *)p->rawptr;
//		KQImageReader *qp = static_cast<KQImageReader*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QImageReader_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQImageReader::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QImageReaderConstInt[] = {
	{"FileNotFoundError", QImageReader::FileNotFoundError},
	{"DeviceError", QImageReader::DeviceError},
	{"UnsupportedFormatError", QImageReader::UnsupportedFormatError},
	{"InvalidDataError", QImageReader::InvalidDataError},
	{"UnknownError", QImageReader::UnknownError},
	{NULL, 0}
};

DEFAPI(void) constQImageReader(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QImageReaderConstInt);
}


DEFAPI(void) defQImageReader(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QImageReader";
	cdef->free = QImageReader_free;
	cdef->reftrace = QImageReader_reftrace;
	cdef->compareTo = QImageReader_compareTo;
}


