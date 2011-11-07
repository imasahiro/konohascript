//QMovie QMovie.new(QObject parent);
KMETHOD QMovie_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQMovie *ret_v = new KQMovie(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
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
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QColor QMovie.getBackgroundColor();
KMETHOD QMovie_getBackgroundColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		QRect ret_v = qp->frameRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QMovie.jumpToFrame(int frameNumber);
KMETHOD QMovie_jumpToFrame(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (true) {
		QList<QByteArray> ret_v = QMovie::supportedFormats();
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		qp->start();
	}
	RETURNvoid_();
}

//void QMovie.stop();
KMETHOD QMovie_stop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMovie *  qp = RawPtr_to(QMovie *, sfp[0]);
	if (qp) {
		qp->stop();
	}
	RETURNvoid_();
}


DummyQMovie::DummyQMovie()
{
	self = NULL;
	error_func = NULL;
	finished_func = NULL;
	frame_changed_func = NULL;
	resized_func = NULL;
	started_func = NULL;
	state_changed_func = NULL;
	updated_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("error", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("finished", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("frame-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("resized", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("started", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("state-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("updated", NULL));
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

bool DummyQMovie::errorSlot(QImageReader::ImageReaderError error)
{
	if (error_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = error;
		knh_Func_invoke(lctx, error_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQMovie::finishedSlot()
{
	if (finished_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, finished_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQMovie::frameChangedSlot(int frameNumber)
{
	if (frame_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = frameNumber;
		knh_Func_invoke(lctx, frame_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQMovie::resizedSlot(const QSize size)
{
	if (resized_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QSize, size);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, resized_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQMovie::startedSlot()
{
	if (started_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, started_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQMovie::stateChangedSlot(QMovie::MovieState state)
{
	if (state_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = state;
		knh_Func_invoke(lctx, state_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQMovie::updatedSlot(const QRect rect)
{
	if (updated_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QRect, rect);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, updated_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQMovie::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMovie::event_map->bigin();
	if ((itr = DummyQMovie::event_map->find(str)) == DummyQMovie::event_map->end()) {
		bool ret = false;
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
	if ((itr = DummyQMovie::slot_map->find(str)) == DummyQMovie::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		error_func = (*slot_map)["error"];
		finished_func = (*slot_map)["finished"];
		frame_changed_func = (*slot_map)["frame-changed"];
		resized_func = (*slot_map)["resized"];
		started_func = (*slot_map)["started"];
		state_changed_func = (*slot_map)["state-changed"];
		updated_func = (*slot_map)["updated"];
		return true;
	}
}

void DummyQMovie::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 7;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, error_func);
	KNH_ADDNNREF(ctx, finished_func);
	KNH_ADDNNREF(ctx, frame_changed_func);
	KNH_ADDNNREF(ctx, resized_func);
	KNH_ADDNNREF(ctx, started_func);
	KNH_ADDNNREF(ctx, state_changed_func);
	KNH_ADDNNREF(ctx, updated_func);

	KNH_SIZEREF(ctx);

	DummyQObject::reftrace(ctx, p, tail_);
}

void DummyQMovie::connection(QObject *o)
{
	QMovie *p = dynamic_cast<QMovie*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(error(QImageReader::ImageReaderError)), this, SLOT(errorSlot(QImageReader::ImageReaderError)));
		connect(p, SIGNAL(finished()), this, SLOT(finishedSlot()));
		connect(p, SIGNAL(frameChanged(int)), this, SLOT(frameChangedSlot(int)));
		connect(p, SIGNAL(resized(const QSize)), this, SLOT(resizedSlot(const QSize)));
		connect(p, SIGNAL(started()), this, SLOT(startedSlot()));
		connect(p, SIGNAL(stateChanged(QMovie::MovieState)), this, SLOT(stateChangedSlot(QMovie::MovieState)));
		connect(p, SIGNAL(updated(const QRect)), this, SLOT(updatedSlot(const QRect)));
	}
	DummyQObject::connection(o);
}

KQMovie::KQMovie(QObject* parent) : QMovie(parent)
{
	self = NULL;
	dummy = new DummyQMovie();
	dummy->connection((QObject*)this);
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
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
	if (p->rawptr != NULL) {
		KQMovie *qp = (KQMovie *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QMovie_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMovie::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQMovie::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QMovie::event(event);
		return false;
	}
	return true;
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


DEFAPI(void) defQMovie(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMovie";
	cdef->free = QMovie_free;
	cdef->reftrace = QMovie_reftrace;
	cdef->compareTo = QMovie_compareTo;
}


