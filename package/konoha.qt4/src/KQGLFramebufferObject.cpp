//@Virtual @Override QPaintEngine QGLFramebufferObject.paintEngine();
KMETHOD QGLFramebufferObject_paintEngine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObject *  qp = RawPtr_to(QGLFramebufferObject *, sfp[0]);
	if (qp) {
		QPaintEngine* ret_v = qp->paintEngine();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPaintEngine*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGLFramebufferObject QGLFramebufferObject.new(QSize size, GLenum target);
KMETHOD QGLFramebufferObject_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
	GLenum  target = *RawPtr_to(GLenum *, sfp[2]);
	KQGLFramebufferObject *ret_v = new KQGLFramebufferObject(size, target);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGLFramebufferObject QGLFramebufferObject.new(int width, int height, GLenum target);
KMETHOD QGLFramebufferObject_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int width = Int_to(int, sfp[1]);
	int height = Int_to(int, sfp[2]);
	GLenum  target = *RawPtr_to(GLenum *, sfp[3]);
	KQGLFramebufferObject *ret_v = new KQGLFramebufferObject(width, height, target);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QGLFramebufferObject QGLFramebufferObject.new(QSize size, QGLFramebufferObjectFormat fmt);
KMETHOD QGLFramebufferObject_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
	const QGLFramebufferObjectFormat  format = *RawPtr_to(const QGLFramebufferObjectFormat *, sfp[2]);
	KQGLFramebufferObject *ret_v = new KQGLFramebufferObject(size, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QGLFramebufferObject QGLFramebufferObject.new(int width, int height, QGLFramebufferObjectFormat fmt);
KMETHOD QGLFramebufferObject_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int width = Int_to(int, sfp[1]);
	int height = Int_to(int, sfp[2]);
	const QGLFramebufferObjectFormat  format = *RawPtr_to(const QGLFramebufferObjectFormat *, sfp[3]);
	KQGLFramebufferObject *ret_v = new KQGLFramebufferObject(width, height, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QGLFramebufferObject QGLFramebufferObject.new(int width, int height, int attachment, GLenum target, GLenum internal_format);
KMETHOD QGLFramebufferObject_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int width = Int_to(int, sfp[1]);
	int height = Int_to(int, sfp[2]);
	QGLFramebufferObject::Attachment attachment = Int_to(QGLFramebufferObject::Attachment, sfp[3]);
	GLenum  target = *RawPtr_to(GLenum *, sfp[4]);
	GLenum  internal_format = *RawPtr_to(GLenum *, sfp[5]);
	KQGLFramebufferObject *ret_v = new KQGLFramebufferObject(width, height, attachment, target, internal_format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QGLFramebufferObject QGLFramebufferObject.new(QSize size, int attachment, GLenum target, GLenum internal_format);
KMETHOD QGLFramebufferObject_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
	QGLFramebufferObject::Attachment attachment = Int_to(QGLFramebufferObject::Attachment, sfp[2]);
	GLenum  target = *RawPtr_to(GLenum *, sfp[3]);
	GLenum  internal_format = *RawPtr_to(GLenum *, sfp[4]);
	KQGLFramebufferObject *ret_v = new KQGLFramebufferObject(size, attachment, target, internal_format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QGLFramebufferObject.attachment();
KMETHOD QGLFramebufferObject_attachment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObject *  qp = RawPtr_to(QGLFramebufferObject *, sfp[0]);
	if (qp) {
		QGLFramebufferObject::Attachment ret_v = qp->attachment();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QGLFramebufferObject.bind();
KMETHOD QGLFramebufferObject_bind(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObject *  qp = RawPtr_to(QGLFramebufferObject *, sfp[0]);
	if (qp) {
		bool ret_v = qp->bind();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGLFramebufferObject.drawTexture(QRectF target, GLuint textureId, GLenum textureTarget);
KMETHOD QGLFramebufferObject_drawTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObject *  qp = RawPtr_to(QGLFramebufferObject *, sfp[0]);
	if (qp) {
		const QRectF  target = *RawPtr_to(const QRectF *, sfp[1]);
		GLuint  textureId = *RawPtr_to(GLuint *, sfp[2]);
		GLenum  textureTarget = *RawPtr_to(GLenum *, sfp[3]);
		qp->drawTexture(target, textureId, textureTarget);
	}
	RETURNvoid_();
}

/*
//void QGLFramebufferObject.drawTexture(QPointF point, GLuint textureId, GLenum textureTarget);
KMETHOD QGLFramebufferObject_drawTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObject *  qp = RawPtr_to(QGLFramebufferObject *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		GLuint  textureId = *RawPtr_to(GLuint *, sfp[2]);
		GLenum  textureTarget = *RawPtr_to(GLenum *, sfp[3]);
		qp->drawTexture(point, textureId, textureTarget);
	}
	RETURNvoid_();
}
*/
//QGLFramebufferObjectFormat QGLFramebufferObject.format();
KMETHOD QGLFramebufferObject_format(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObject *  qp = RawPtr_to(QGLFramebufferObject *, sfp[0]);
	if (qp) {
		QGLFramebufferObjectFormat ret_v = qp->format();
		QGLFramebufferObjectFormat *ret_v_ = new QGLFramebufferObjectFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//GLuint QGLFramebufferObject.handle();
KMETHOD QGLFramebufferObject_handle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObject *  qp = RawPtr_to(QGLFramebufferObject *, sfp[0]);
	if (qp) {
		GLuint ret_v = qp->handle();
		GLuint *ret_v_ = new GLuint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGLFramebufferObject.isBound();
KMETHOD QGLFramebufferObject_isBound(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObject *  qp = RawPtr_to(QGLFramebufferObject *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isBound();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGLFramebufferObject.release();
KMETHOD QGLFramebufferObject_release(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObject *  qp = RawPtr_to(QGLFramebufferObject *, sfp[0]);
	if (qp) {
		bool ret_v = qp->release();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QSize QGLFramebufferObject.size();
KMETHOD QGLFramebufferObject_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObject *  qp = RawPtr_to(QGLFramebufferObject *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->size();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//GLuint QGLFramebufferObject.texture();
KMETHOD QGLFramebufferObject_texture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObject *  qp = RawPtr_to(QGLFramebufferObject *, sfp[0]);
	if (qp) {
		GLuint ret_v = qp->texture();
		GLuint *ret_v_ = new GLuint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QImage QGLFramebufferObject.toImage();
KMETHOD QGLFramebufferObject_toImage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFramebufferObject *  qp = RawPtr_to(QGLFramebufferObject *, sfp[0]);
	if (qp) {
		QImage ret_v = qp->toImage();
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGLFramebufferObject.blitFramebuffer(QGLFramebufferObject target, QRect targetRect, QGLFramebufferObject source, QRect sourceRect, GLbitfield buffers, GLenum filter);
KMETHOD QGLFramebufferObject_blitFramebuffer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QGLFramebufferObject*  target = RawPtr_to(QGLFramebufferObject*, sfp[1]);
		const QRect  targetRect = *RawPtr_to(const QRect *, sfp[2]);
		QGLFramebufferObject*  source = RawPtr_to(QGLFramebufferObject*, sfp[3]);
		const QRect  sourceRect = *RawPtr_to(const QRect *, sfp[4]);
		GLbitfield  buffers = *RawPtr_to(GLbitfield *, sfp[5]);
		GLenum  filter = *RawPtr_to(GLenum *, sfp[6]);
		QGLFramebufferObject::blitFramebuffer(target, targetRect, source, sourceRect, buffers, filter);
	}
	RETURNvoid_();
}

//boolean QGLFramebufferObject.hasOpenGLFramebufferBlit();
KMETHOD QGLFramebufferObject_hasOpenGLFramebufferBlit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QGLFramebufferObject::hasOpenGLFramebufferBlit();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGLFramebufferObject.hasOpenGLFramebufferObjects();
KMETHOD QGLFramebufferObject_hasOpenGLFramebufferObjects(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QGLFramebufferObject::hasOpenGLFramebufferObjects();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQGLFramebufferObject::DummyQGLFramebufferObject()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGLFramebufferObject::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGLFramebufferObject::self = ptr;
	DummyQPaintDevice::setSelf(ptr);
}

bool DummyQGLFramebufferObject::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQPaintDevice::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGLFramebufferObject::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLFramebufferObject::event_map->bigin();
	if ((itr = DummyQGLFramebufferObject::event_map->find(str)) == DummyQGLFramebufferObject::event_map->end()) {
		bool ret = false;
		ret = DummyQPaintDevice::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGLFramebufferObject::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLFramebufferObject::slot_map->bigin();
	if ((itr = DummyQGLFramebufferObject::slot_map->find(str)) == DummyQGLFramebufferObject::slot_map->end()) {
		bool ret = false;
		ret = DummyQPaintDevice::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGLFramebufferObject::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGLFramebufferObject::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQPaintDevice::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGLFramebufferObject::connection(QObject *o)
{
	QGLFramebufferObject *p = dynamic_cast<QGLFramebufferObject*>(o);
	if (p != NULL) {
	}
	DummyQPaintDevice::connection(o);
}

KQGLFramebufferObject::KQGLFramebufferObject(const QSize size, GLenum target) : QGLFramebufferObject(size, target)
{
	self = NULL;
	dummy = new DummyQGLFramebufferObject();
}

KMETHOD QGLFramebufferObject_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLFramebufferObject *qp = RawPtr_to(KQGLFramebufferObject *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGLFramebufferObject]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLFramebufferObject]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGLFramebufferObject_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLFramebufferObject *qp = RawPtr_to(KQGLFramebufferObject *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGLFramebufferObject]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLFramebufferObject]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGLFramebufferObject_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGLFramebufferObject *qp = (KQGLFramebufferObject *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGLFramebufferObject_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGLFramebufferObject *qp = (KQGLFramebufferObject *)p->rawptr;
//		KQGLFramebufferObject *qp = static_cast<KQGLFramebufferObject*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGLFramebufferObject_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGLFramebufferObject::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QGLFramebufferObjectConstInt[] = {
	{"NoAttachment", QGLFramebufferObject::NoAttachment},
	{"CombinedDepthStencil", QGLFramebufferObject::CombinedDepthStencil},
	{"Depth", QGLFramebufferObject::Depth},
	{NULL, 0}
};

DEFAPI(void) constQGLFramebufferObject(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QGLFramebufferObjectConstInt);
}


DEFAPI(void) defQGLFramebufferObject(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGLFramebufferObject";
	cdef->free = QGLFramebufferObject_free;
	cdef->reftrace = QGLFramebufferObject_reftrace;
	cdef->compareTo = QGLFramebufferObject_compareTo;
}


