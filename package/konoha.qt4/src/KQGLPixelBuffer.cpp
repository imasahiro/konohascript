//@Virtual @Override QPaintEngine QGLPixelBuffer.paintEngine();
KMETHOD QGLPixelBuffer_paintEngine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLPixelBuffer *  qp = RawPtr_to(QGLPixelBuffer *, sfp[0]);
	if (qp) {
		QPaintEngine* ret_v = qp->paintEngine();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPaintEngine*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGLPixelBuffer QGLPixelBuffer.new(QSize size, QGLFormat fmt, QGLWidget shareWidget);
KMETHOD QGLPixelBuffer_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
	const QGLFormat  format = *RawPtr_to(const QGLFormat *, sfp[2]);
	QGLWidget*  shareWidget = RawPtr_to(QGLWidget*, sfp[3]);
	KQGLPixelBuffer *ret_v = new KQGLPixelBuffer(size, format, shareWidget);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGLPixelBuffer QGLPixelBuffer.new(int width, int height, QGLFormat fmt, QGLWidget shareWidget);
KMETHOD QGLPixelBuffer_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int width = Int_to(int, sfp[1]);
	int height = Int_to(int, sfp[2]);
	const QGLFormat  format = *RawPtr_to(const QGLFormat *, sfp[3]);
	QGLWidget*  shareWidget = RawPtr_to(QGLWidget*, sfp[4]);
	KQGLPixelBuffer *ret_v = new KQGLPixelBuffer(width, height, format, shareWidget);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//GLuint QGLPixelBuffer.bindTexture(QImage image, GLenum target);
KMETHOD QGLPixelBuffer_bindTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLPixelBuffer *  qp = RawPtr_to(QGLPixelBuffer *, sfp[0]);
	if (qp) {
		const QImage  image = *RawPtr_to(const QImage *, sfp[1]);
		GLenum  target = *RawPtr_to(GLenum *, sfp[2]);
		GLuint ret_v = qp->bindTexture(image, target);
		GLuint *ret_v_ = new GLuint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//GLuint QGLPixelBuffer.bindTexture(QPixmap pixmap, GLenum target);
KMETHOD QGLPixelBuffer_bindTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLPixelBuffer *  qp = RawPtr_to(QGLPixelBuffer *, sfp[0]);
	if (qp) {
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
		GLenum  target = *RawPtr_to(GLenum *, sfp[2]);
		GLuint ret_v = qp->bindTexture(pixmap, target);
		GLuint *ret_v_ = new GLuint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//GLuint QGLPixelBuffer.bindTexture(String fileName);
KMETHOD QGLPixelBuffer_bindTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLPixelBuffer *  qp = RawPtr_to(QGLPixelBuffer *, sfp[0]);
	if (qp) {
		const QString fileName = String_to(const QString, sfp[1]);
		GLuint ret_v = qp->bindTexture(fileName);
		GLuint *ret_v_ = new GLuint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//boolean QGLPixelBuffer.bindToDynamicTexture(GLuint texture_id);
KMETHOD QGLPixelBuffer_bindToDynamicTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLPixelBuffer *  qp = RawPtr_to(QGLPixelBuffer *, sfp[0]);
	if (qp) {
		GLuint  texture_id = *RawPtr_to(GLuint *, sfp[1]);
		bool ret_v = qp->bindToDynamicTexture(texture_id);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGLPixelBuffer.deleteTexture(GLuint texture_id);
KMETHOD QGLPixelBuffer_deleteTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLPixelBuffer *  qp = RawPtr_to(QGLPixelBuffer *, sfp[0]);
	if (qp) {
		GLuint  texture_id = *RawPtr_to(GLuint *, sfp[1]);
		qp->deleteTexture(texture_id);
	}
	RETURNvoid_();
}

//boolean QGLPixelBuffer.doneCurrent();
KMETHOD QGLPixelBuffer_doneCurrent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLPixelBuffer *  qp = RawPtr_to(QGLPixelBuffer *, sfp[0]);
	if (qp) {
		bool ret_v = qp->doneCurrent();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGLPixelBuffer.drawTexture(QRectF target, GLuint textureId, GLenum textureTarget);
KMETHOD QGLPixelBuffer_drawTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLPixelBuffer *  qp = RawPtr_to(QGLPixelBuffer *, sfp[0]);
	if (qp) {
		const QRectF  target = *RawPtr_to(const QRectF *, sfp[1]);
		GLuint  textureId = *RawPtr_to(GLuint *, sfp[2]);
		GLenum  textureTarget = *RawPtr_to(GLenum *, sfp[3]);
		qp->drawTexture(target, textureId, textureTarget);
	}
	RETURNvoid_();
}

/*
//void QGLPixelBuffer.drawTexture(QPointF point, GLuint textureId, GLenum textureTarget);
KMETHOD QGLPixelBuffer_drawTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLPixelBuffer *  qp = RawPtr_to(QGLPixelBuffer *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		GLuint  textureId = *RawPtr_to(GLuint *, sfp[2]);
		GLenum  textureTarget = *RawPtr_to(GLenum *, sfp[3]);
		qp->drawTexture(point, textureId, textureTarget);
	}
	RETURNvoid_();
}
*/
//QGLFormat QGLPixelBuffer.format();
KMETHOD QGLPixelBuffer_format(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLPixelBuffer *  qp = RawPtr_to(QGLPixelBuffer *, sfp[0]);
	if (qp) {
		QGLFormat ret_v = qp->format();
		QGLFormat *ret_v_ = new QGLFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//GLuint QGLPixelBuffer.generateDynamicTexture();
KMETHOD QGLPixelBuffer_generateDynamicTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLPixelBuffer *  qp = RawPtr_to(QGLPixelBuffer *, sfp[0]);
	if (qp) {
		GLuint ret_v = qp->generateDynamicTexture();
		GLuint *ret_v_ = new GLuint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGLPixelBuffer.makeCurrent();
KMETHOD QGLPixelBuffer_makeCurrent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLPixelBuffer *  qp = RawPtr_to(QGLPixelBuffer *, sfp[0]);
	if (qp) {
		bool ret_v = qp->makeCurrent();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGLPixelBuffer.releaseFromDynamicTexture();
KMETHOD QGLPixelBuffer_releaseFromDynamicTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLPixelBuffer *  qp = RawPtr_to(QGLPixelBuffer *, sfp[0]);
	if (qp) {
		qp->releaseFromDynamicTexture();
	}
	RETURNvoid_();
}

//QSize QGLPixelBuffer.size();
KMETHOD QGLPixelBuffer_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLPixelBuffer *  qp = RawPtr_to(QGLPixelBuffer *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->size();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QImage QGLPixelBuffer.toImage();
KMETHOD QGLPixelBuffer_toImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLPixelBuffer *  qp = RawPtr_to(QGLPixelBuffer *, sfp[0]);
	if (qp) {
		QImage ret_v = qp->toImage();
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGLPixelBuffer.updateDynamicTexture(GLuint texture_id);
KMETHOD QGLPixelBuffer_updateDynamicTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLPixelBuffer *  qp = RawPtr_to(QGLPixelBuffer *, sfp[0]);
	if (qp) {
		GLuint  texture_id = *RawPtr_to(GLuint *, sfp[1]);
		qp->updateDynamicTexture(texture_id);
	}
	RETURNvoid_();
}

//boolean QGLPixelBuffer.hasOpenGLPbuffers();
KMETHOD QGLPixelBuffer_hasOpenGLPbuffers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QGLPixelBuffer::hasOpenGLPbuffers();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQGLPixelBuffer::DummyQGLPixelBuffer()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQGLPixelBuffer::~DummyQGLPixelBuffer()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQGLPixelBuffer::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGLPixelBuffer::self = ptr;
	DummyQPaintDevice::setSelf(ptr);
}

bool DummyQGLPixelBuffer::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQPaintDevice::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGLPixelBuffer::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLPixelBuffer::event_map->bigin();
	if ((itr = DummyQGLPixelBuffer::event_map->find(str)) == DummyQGLPixelBuffer::event_map->end()) {
		bool ret = false;
		ret = DummyQPaintDevice::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGLPixelBuffer::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLPixelBuffer::slot_map->bigin();
	if ((itr = DummyQGLPixelBuffer::slot_map->find(str)) == DummyQGLPixelBuffer::slot_map->end()) {
		bool ret = false;
		ret = DummyQPaintDevice::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGLPixelBuffer::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGLPixelBuffer::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQPaintDevice::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGLPixelBuffer::connection(QObject *o)
{
	QGLPixelBuffer *p = dynamic_cast<QGLPixelBuffer*>(o);
	if (p != NULL) {
	}
	DummyQPaintDevice::connection(o);
}

KQGLPixelBuffer::KQGLPixelBuffer(const QSize size, const QGLFormat format, QGLWidget* shareWidget) : QGLPixelBuffer(size, format, shareWidget)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQGLPixelBuffer();
}

KQGLPixelBuffer::~KQGLPixelBuffer()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QGLPixelBuffer_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLPixelBuffer *qp = RawPtr_to(KQGLPixelBuffer *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGLPixelBuffer]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLPixelBuffer]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGLPixelBuffer_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLPixelBuffer *qp = RawPtr_to(KQGLPixelBuffer *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGLPixelBuffer]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLPixelBuffer]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGLPixelBuffer_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQGLPixelBuffer *qp = (KQGLPixelBuffer *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QGLPixelBuffer*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QGLPixelBuffer_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQGLPixelBuffer *qp = (KQGLPixelBuffer *)p->rawptr;
		KQGLPixelBuffer *qp = static_cast<KQGLPixelBuffer*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGLPixelBuffer_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGLPixelBuffer::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQGLPixelBuffer(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGLPixelBuffer";
	cdef->free = QGLPixelBuffer_free;
	cdef->reftrace = QGLPixelBuffer_reftrace;
	cdef->compareTo = QGLPixelBuffer_compareTo;
}


