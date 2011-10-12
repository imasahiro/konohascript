//QMovie QMovie.new(QObject parent);
KMETHOD QMovie_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQMovie *ret_v = new KQMovie(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QMovie QMovie.new(QIODevice device, QByteArray fmt, QObject parent);
KMETHOD QMovie_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice*  device = RawPtr_to(QIODevice*, sfp[1]);
	const QByteArray  format = *RawPtr_to(const QByteArray *, sfp[2]);
	QObject*  parent = RawPtr_to(QObject*, sfp[3]);
	KQMovie *ret_v = new KQMovie(device, format, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QMovie QMovie.new(String fileName, QByteArray fmt, QObject parent);
KMETHOD QMovie_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString fileName = String_to(const QString, sfp[1]);
	const QByteArray  format = *RawPtr_to(const QByteArray *, sfp[2]);
	QObject*  parent = RawPtr_to(QObject*, sfp[3]);
	KQMovie *ret_v = new KQMovie(fileName, format, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QColor QMovie.getBackgroundColor();
KMETHOD QMovie_getBackgroundColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		QColor ret_v = qp->backgroundColor();
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMovie.getCacheMode();
KMETHOD QMovie_getCacheMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		QMovie::CacheMode ret_v = qp->cacheMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMovie.currentFrameNumber();
KMETHOD QMovie_currentFrameNumber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->currentFrameNumber();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QImage QMovie.currentImage();
KMETHOD QMovie_currentImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		QImage ret_v = qp->currentImage();
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPixmap QMovie.currentPixmap();
KMETHOD QMovie_currentPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		QPixmap ret_v = qp->currentPixmap();
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QIODevice QMovie.getDevice();
KMETHOD QMovie_getDevice(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		QIODevice* ret_v = qp->device();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QIODevice*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QMovie.getFileName();
KMETHOD QMovie_getFileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->fileName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QMovie.getFormat();
KMETHOD QMovie_getFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		QByteArray ret_v = qp->format();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMovie.frameCount();
KMETHOD QMovie_frameCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->frameCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QRect QMovie.frameRect();
KMETHOD QMovie_frameRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		QRect ret_v = qp->frameRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

////boolean QMovie.isValid();
KMETHOD QMovie_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMovie.jumpToFrame(int frameNumber);
KMETHOD QMovie_jumpToFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		int frameNumber = Int_to(int, sfp[1]);
		bool ret_v = qp->jumpToFrame(frameNumber);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QMovie.loopCount();
KMETHOD QMovie_loopCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->loopCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMovie.nextFrameDelay();
KMETHOD QMovie_nextFrameDelay(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->nextFrameDelay();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QSize QMovie.getScaledSize();
KMETHOD QMovie_getScaledSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->scaledSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QMovie.setBackgroundColor(QColor color);
KMETHOD QMovie_setBackgroundColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		const QColor  color = *RawPtr_to(const QColor *, sfp[1]);
		qp->setBackgroundColor(color);
	}
	RETURNvoid_();
}

//void QMovie.setCacheMode(int mode);
KMETHOD QMovie_setCacheMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		QMovie::CacheMode mode = Int_to(QMovie::CacheMode, sfp[1]);
		qp->setCacheMode(mode);
	}
	RETURNvoid_();
}

//void QMovie.setDevice(QIODevice device);
KMETHOD QMovie_setDevice(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		QIODevice*  device = RawPtr_to(QIODevice*, sfp[1]);
		qp->setDevice(device);
	}
	RETURNvoid_();
}

//void QMovie.setFileName(String fileName);
KMETHOD QMovie_setFileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		qp->setFileName(fileName);
	}
	RETURNvoid_();
}

//void QMovie.setFormat(QByteArray fmt);
KMETHOD QMovie_setFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		const QByteArray  format = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->setFormat(format);
	}
	RETURNvoid_();
}

//void QMovie.setScaledSize(QSize size);
KMETHOD QMovie_setScaledSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		qp->setScaledSize(size);
	}
	RETURNvoid_();
}

//int QMovie.getSpeed();
KMETHOD QMovie_getSpeed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->speed();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMovie.state();
KMETHOD QMovie_state(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		QMovie::MovieState ret_v = qp->state();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<QByteArray> QMovie.supportedFormats();
KMETHOD QMovie_supportedFormats(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		QList<QByteArray>ret_v = qp->supportedFormats();
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
	

//boolean QMovie.jumpToNextFrame();
KMETHOD QMovie_jumpToNextFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->jumpToNextFrame();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QMovie.setPaused(boolean paused);
KMETHOD QMovie_setPaused(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		bool paused = Boolean_to(bool, sfp[1]);
		qp->setPaused(paused);
	}
	RETURNvoid_();
}

//void QMovie.setSpeed(int percentSpeed);
KMETHOD QMovie_setSpeed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		int percentSpeed = Int_to(int, sfp[1]);
		qp->setSpeed(percentSpeed);
	}
	RETURNvoid_();
}

//void QMovie.start();
KMETHOD QMovie_start(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		qp->start();
	}
	RETURNvoid_();
}

//void QMovie.stop();
KMETHOD QMovie_stop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp != NULL) {
		qp->stop();
	}
	RETURNvoid_();
}


DummyQMovie::DummyQMovie()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQMovie::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMovie::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQMovie::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQMovie::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMovie::event_map->bigin();
	if ((itr = DummyQMovie::event_map->find(str)) == DummyQMovie::event_map->end()) {
		bool ret;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMovie::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMovie::slot_map->bigin();
	if ((itr = DummyQMovie::event_map->find(str)) == DummyQMovie::slot_map->end()) {
		bool ret;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQMovie::KQMovie(QObject* parent) : QMovie(parent)
{
	self = NULL;
}

KMETHOD QMovie_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMovie *qp = RawPtr_to(KQMovie *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMovie]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQMovie::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMovie]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QMovie_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMovie *qp = RawPtr_to(KQMovie *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMovie]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQMovie::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMovie]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMovie_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMovie *qp = (KQMovie *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMovie_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQMovie *qp = (KQMovie *)p->rawptr;
		(void)qp;
	}
}

static int QMovie_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQMovie::event(QEvent *event)
{
	if (!DummyQMovie::eventDispatcher(event)) {
		QMovie::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQMovie(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMovie";
	cdef->free = QMovie_free;
	cdef->reftrace = QMovie_reftrace;
	cdef->compareTo = QMovie_compareTo;
}

static knh_IntData_t QMovieConstInt[] = {
	{"CacheNone", QMovie::CacheNone},
	{"CacheAll", QMovie::CacheAll},
	{"NotRunning", QMovie::NotRunning},
	{"Paused", QMovie::Paused},
	{"Running", QMovie::Running},
	{NULL, 0}
};

DEFAPI(void) constQMovie(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QMovieConstInt);
}

