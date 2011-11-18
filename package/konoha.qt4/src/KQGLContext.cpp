//QGLContext QGLContext.new(QGLFormat fmt);
KMETHOD QGLContext_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QGLFormat  format = *RawPtr_to(const QGLFormat *, sfp[1]);
	KQGLContext *ret_v = new KQGLContext(format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//GLuint QGLContext.bindTexture(QImage image, GLenum target, GLint fmt, QGLContextBindOptions options);
KMETHOD QGLContext_bindTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		const QImage  image = *RawPtr_to(const QImage *, sfp[1]);
		GLenum  target = *RawPtr_to(GLenum *, sfp[2]);
		GLint  format = *RawPtr_to(GLint *, sfp[3]);
		initFlag(options, QGLContext::BindOptions, sfp[4]);
		GLuint ret_v = qp->bindTexture(image, target, format, options);
		GLuint *ret_v_ = new GLuint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//GLuint QGLContext.bindTexture(String fileName);
KMETHOD QGLContext_bindTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
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
/*
//GLuint QGLContext.bindTexture(QImage image, GLenum target, GLint fmt);
KMETHOD QGLContext_bindTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		const QImage  image = *RawPtr_to(const QImage *, sfp[1]);
		GLenum  target = *RawPtr_to(GLenum *, sfp[2]);
		GLint  format = *RawPtr_to(GLint *, sfp[3]);
		GLuint ret_v = qp->bindTexture(image, target, format);
		GLuint *ret_v_ = new GLuint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//GLuint QGLContext.bindTexture(QPixmap pixmap, GLenum target, GLint fmt);
KMETHOD QGLContext_bindTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
		GLenum  target = *RawPtr_to(GLenum *, sfp[2]);
		GLint  format = *RawPtr_to(GLint *, sfp[3]);
		GLuint ret_v = qp->bindTexture(pixmap, target, format);
		GLuint *ret_v_ = new GLuint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//GLuint QGLContext.bindTexture(QPixmap pixmap, GLenum target, GLint fmt, QGLContextBindOptions options);
KMETHOD QGLContext_bindTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
		GLenum  target = *RawPtr_to(GLenum *, sfp[2]);
		GLint  format = *RawPtr_to(GLint *, sfp[3]);
		initFlag(options, QGLContext::BindOptions, sfp[4]);
		GLuint ret_v = qp->bindTexture(pixmap, target, format, options);
		GLuint *ret_v_ = new GLuint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//@Virtual boolean QGLContext.create(QGLContext shareContext);
KMETHOD QGLContext_create(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		const QGLContext*  shareContext = RawPtr_to(const QGLContext*, sfp[1]);
		bool ret_v = qp->create(shareContext);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGLContext.deleteTexture(GLuint id);
KMETHOD QGLContext_deleteTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		GLuint  id = *RawPtr_to(GLuint *, sfp[1]);
		qp->deleteTexture(id);
	}
	RETURNvoid_();
}

//QPaintDevice QGLContext.device();
KMETHOD QGLContext_device(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		QPaintDevice* ret_v = qp->device();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPaintDevice*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QGLContext.doneCurrent();
KMETHOD QGLContext_doneCurrent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		qp->doneCurrent();
	}
	RETURNvoid_();
}

//void QGLContext.drawTexture(QRectF target, GLuint textureId, GLenum textureTarget);
KMETHOD QGLContext_drawTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		const QRectF  target = *RawPtr_to(const QRectF *, sfp[1]);
		GLuint  textureId = *RawPtr_to(GLuint *, sfp[2]);
		GLenum  textureTarget = *RawPtr_to(GLenum *, sfp[3]);
		qp->drawTexture(target, textureId, textureTarget);
	}
	RETURNvoid_();
}

/*
//void QGLContext.drawTexture(QPointF point, GLuint textureId, GLenum textureTarget);
KMETHOD QGLContext_drawTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		GLuint  textureId = *RawPtr_to(GLuint *, sfp[2]);
		GLenum  textureTarget = *RawPtr_to(GLenum *, sfp[3]);
		qp->drawTexture(point, textureId, textureTarget);
	}
	RETURNvoid_();
}
*/
//QGLFormat QGLContext.getFormat();
KMETHOD QGLContext_getFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		QGLFormat ret_v = qp->format();
		QGLFormat *ret_v_ = new QGLFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGLContext.getProcAddress(String proc);
KMETHOD QGLContext_getProcAddress(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		const QString proc = String_to(const QString, sfp[1]);
		void* ret_v = qp->getProcAddress(proc);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (void*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGLContext.isSharing();
KMETHOD QGLContext_isSharing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSharing();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual void QGLContext.makeCurrent();
KMETHOD QGLContext_makeCurrent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		qp->makeCurrent();
	}
	RETURNvoid_();
}

//QColor QGLContext.overlayTransparentColor();
KMETHOD QGLContext_overlayTransparentColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		QColor ret_v = qp->overlayTransparentColor();
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGLFormat QGLContext.requestedFormat();
KMETHOD QGLContext_requestedFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		QGLFormat ret_v = qp->requestedFormat();
		QGLFormat *ret_v_ = new QGLFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGLContext.reset();
KMETHOD QGLContext_reset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		qp->reset();
	}
	RETURNvoid_();
}

//void QGLContext.setFormat(QGLFormat fmt);
KMETHOD QGLContext_setFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		const QGLFormat  format = *RawPtr_to(const QGLFormat *, sfp[1]);
		qp->setFormat(format);
	}
	RETURNvoid_();
}

//@Virtual void QGLContext.swapBuffers();
KMETHOD QGLContext_swapBuffers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *  qp = RawPtr_to(QGLContext *, sfp[0]);
	if (qp) {
		qp->swapBuffers();
	}
	RETURNvoid_();
}

//boolean QGLContext.areSharing(QGLContext context1, QGLContext context2);
KMETHOD QGLContext_areSharing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QGLContext*  context1 = RawPtr_to(const QGLContext*, sfp[1]);
		const QGLContext*  context2 = RawPtr_to(const QGLContext*, sfp[2]);
		bool ret_v = QGLContext::areSharing(context1, context2);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QGLContext QGLContext.currentContext();
KMETHOD QGLContext_currentContext(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QGLContext* ret_v = QGLContext::currentContext();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGLContext*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGLContext.setTextureCacheLimit(int size);
KMETHOD QGLContext_setTextureCacheLimit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int size = Int_to(int, sfp[1]);
		QGLContext::setTextureCacheLimit(size);
	}
	RETURNvoid_();
}

//int QGLContext.getTextureCacheLimit();
KMETHOD QGLContext_getTextureCacheLimit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int ret_v = QGLContext::textureCacheLimit();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<String> QGLContext.parents();
KMETHOD QGLContext_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext *qp = RawPtr_to(QGLContext*, sfp[0]);
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

DummyQGLContext::DummyQGLContext()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQGLContext::~DummyQGLContext()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQGLContext::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGLContext::self = ptr;
}

bool DummyQGLContext::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQGLContext::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLContext::event_map->bigin();
	if ((itr = DummyQGLContext::event_map->find(str)) == DummyQGLContext::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGLContext::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLContext::slot_map->bigin();
	if ((itr = DummyQGLContext::slot_map->find(str)) == DummyQGLContext::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGLContext::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGLContext::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQGLContext::connection(QObject *o)
{
	QGLContext *p = dynamic_cast<QGLContext*>(o);
	if (p != NULL) {
	}
}

KQGLContext::KQGLContext(const QGLFormat format) : QGLContext(format)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQGLContext();
}

KQGLContext::~KQGLContext()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QGLContext_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLContext *qp = RawPtr_to(KQGLContext *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGLContext]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLContext]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGLContext_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLContext *qp = RawPtr_to(KQGLContext *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGLContext]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLContext]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGLContext_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQGLContext *qp = (KQGLContext *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QGLContext*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QGLContext_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQGLContext *qp = (KQGLContext *)p->rawptr;
		KQGLContext *qp = static_cast<KQGLContext*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGLContext_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGLContext::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QGLContextConstInt[] = {
	{"NoBindOption", QGLContext::NoBindOption},
	{"InvertedYBindOption", QGLContext::InvertedYBindOption},
	{"MipmapBindOption", QGLContext::MipmapBindOption},
//	{"PremultipliedAlphaBindOption", QGLContext::PremultipliedAlphaBindOption},
	{"LinearFilteringBindOption", QGLContext::LinearFilteringBindOption},
	{"DefaultBindOption", QGLContext::DefaultBindOption},
	{NULL, 0}
};

DEFAPI(void) constQGLContext(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QGLContextConstInt);
}


DEFAPI(void) defQGLContext(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGLContext";
	cdef->free = QGLContext_free;
	cdef->reftrace = QGLContext_reftrace;
	cdef->compareTo = QGLContext_compareTo;
}

//## QGLContextBindOptions QGLContextBindOptions.new(int value);
KMETHOD QGLContextBindOptions_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLContext::BindOption i = Int_to(QGLContext::BindOption, sfp[1]);
	QGLContext::BindOptions *ret_v = new QGLContext::BindOptions(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QGLContextBindOptions QGLContextBindOptions.and(int mask);
KMETHOD QGLContextBindOptions_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLContext::BindOptions *qp = RawPtr_to(QGLContext::BindOptions*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QGLContext::BindOptions ret = ((*qp) & i);
		QGLContext::BindOptions *ret_ = new QGLContext::BindOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGLContextBindOptions QGLContextBindOptions.iand(QGLContext::QGLContextBindOptions other);
KMETHOD QGLContextBindOptions_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLContext::BindOptions *qp = RawPtr_to(QGLContext::BindOptions*, sfp[0]);
	if (qp != NULL) {
		QGLContext::BindOptions *other = RawPtr_to(QGLContext::BindOptions *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGLContextBindOptions QGLContextBindOptions.or(QGLContextBindOptions f);
KMETHOD QGLContextBindOptions_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext::BindOptions *qp = RawPtr_to(QGLContext::BindOptions*, sfp[0]);
	if (qp != NULL) {
		QGLContext::BindOptions *f = RawPtr_to(QGLContext::BindOptions*, sfp[1]);
		QGLContext::BindOptions ret = ((*qp) | (*f));
		QGLContext::BindOptions *ret_ = new QGLContext::BindOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGLContextBindOptions QGLContextBindOptions.ior(QGLContext::QGLContextBindOptions other);
KMETHOD QGLContextBindOptions_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLContext::BindOptions *qp = RawPtr_to(QGLContext::BindOptions*, sfp[0]);
	if (qp != NULL) {
		QGLContext::BindOptions *other = RawPtr_to(QGLContext::BindOptions *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGLContextBindOptions QGLContextBindOptions.xor(QGLContextBindOptions f);
KMETHOD QGLContextBindOptions_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext::BindOptions *qp = RawPtr_to(QGLContext::BindOptions*, sfp[0]);
	if (qp != NULL) {
		QGLContext::BindOptions *f = RawPtr_to(QGLContext::BindOptions*, sfp[1]);
		QGLContext::BindOptions ret = ((*qp) ^ (*f));
		QGLContext::BindOptions *ret_ = new QGLContext::BindOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGLContextBindOptions QGLContextBindOptions.ixor(QGLContext::QGLContextBindOptions other);
KMETHOD QGLContextBindOptions_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLContext::BindOptions *qp = RawPtr_to(QGLContext::BindOptions*, sfp[0]);
	if (qp != NULL) {
		QGLContext::BindOptions *other = RawPtr_to(QGLContext::BindOptions *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QGLContextBindOptions.testFlag(int flag);
KMETHOD QGLContextBindOptions_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLContext::BindOptions *qp = RawPtr_to(QGLContext::BindOptions *, sfp[0]);
	if (qp != NULL) {
		QGLContext::BindOption flag = Int_to(QGLContext::BindOption, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QGLContextBindOptions.value();
KMETHOD QGLContextBindOptions_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLContext::BindOptions *qp = RawPtr_to(QGLContext::BindOptions *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QGLContextBindOptions_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QGLContext::BindOptions *qp = (QGLContext::BindOptions *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QGLContextBindOptions_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QGLContext::BindOptions *qp = (QGLContext::BindOptions *)p->rawptr;
		(void)qp;
	}
}

static int QGLContextBindOptions_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QGLContext::BindOptions*)p1->rawptr);
//		int v2 = int(*(QGLContext::BindOptions*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QGLContext::BindOptions v1 = *(QGLContext::BindOptions*)p1->rawptr;
		QGLContext::BindOptions v2 = *(QGLContext::BindOptions*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQGLContextBindOptions(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGLContextBindOptions";
	cdef->free = QGLContextBindOptions_free;
	cdef->reftrace = QGLContextBindOptions_reftrace;
	cdef->compareTo = QGLContextBindOptions_compareTo;
}

