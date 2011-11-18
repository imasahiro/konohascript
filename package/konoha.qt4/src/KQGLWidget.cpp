//QGLWidget QGLWidget.new(QWidget parent, QGLWidget shareWidget, QtWindowFlags f);
KMETHOD QGLWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	const QGLWidget*  shareWidget = RawPtr_to(const QGLWidget*, sfp[2]);
	initFlag(f, Qt::WindowFlags, sfp[3]);
	KQGLWidget *ret_v = new KQGLWidget(parent, shareWidget, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGLWidget QGLWidget.new(QGLContext context, QWidget parent, QGLWidget shareWidget, QtWindowFlags f);
KMETHOD QGLWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLContext*  context = RawPtr_to(QGLContext*, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	const QGLWidget*  shareWidget = RawPtr_to(const QGLWidget*, sfp[3]);
	initFlag(f, Qt::WindowFlags, sfp[4]);
	KQGLWidget *ret_v = new KQGLWidget(context, parent, shareWidget, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QGLWidget QGLWidget.new(QGLFormat fmt, QWidget parent, QGLWidget shareWidget, QtWindowFlags f);
KMETHOD QGLWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QGLFormat  format = *RawPtr_to(const QGLFormat *, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	const QGLWidget*  shareWidget = RawPtr_to(const QGLWidget*, sfp[3]);
	initFlag(f, Qt::WindowFlags, sfp[4]);
	KQGLWidget *ret_v = new KQGLWidget(format, parent, shareWidget, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//GLuint QGLWidget.bindTexture(QImage image, GLenum target, GLint fmt);
KMETHOD QGLWidget_bindTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
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

/*
//GLuint QGLWidget.bindTexture(QPixmap pixmap, GLenum target, GLint fmt);
KMETHOD QGLWidget_bindTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
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
//GLuint QGLWidget.bindTexture(QImage image, GLenum target, GLint fmt, int options);
KMETHOD QGLWidget_bindTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		const QImage  image = *RawPtr_to(const QImage *, sfp[1]);
		GLenum  target = *RawPtr_to(GLenum *, sfp[2]);
		GLint  format = *RawPtr_to(GLint *, sfp[3]);
		QGLContext::BindOptions options = Int_to(QGLContext::BindOptions, sfp[4]);
		GLuint ret_v = qp->bindTexture(image, target, format, options);
		GLuint *ret_v_ = new GLuint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//GLuint QGLWidget.bindTexture(QPixmap pixmap, GLenum target, GLint fmt, int options);
KMETHOD QGLWidget_bindTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
		GLenum  target = *RawPtr_to(GLenum *, sfp[2]);
		GLint  format = *RawPtr_to(GLint *, sfp[3]);
		QGLContext::BindOptions options = Int_to(QGLContext::BindOptions, sfp[4]);
		GLuint ret_v = qp->bindTexture(pixmap, target, format, options);
		GLuint *ret_v_ = new GLuint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//GLuint QGLWidget.bindTexture(String fileName);
KMETHOD QGLWidget_bindTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
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
//QGLColormap QGLWidget.getColormap();
KMETHOD QGLWidget_getColormap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		const QGLColormap ret_v = qp->colormap();
		QGLColormap *ret_v_ = new QGLColormap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGLContext QGLWidget.context();
KMETHOD QGLWidget_context(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		const QGLContext* ret_v = qp->context();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGLContext*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGLWidget.deleteTexture(GLuint id);
KMETHOD QGLWidget_deleteTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		GLuint  id = *RawPtr_to(GLuint *, sfp[1]);
		qp->deleteTexture(id);
	}
	RETURNvoid_();
}

//void QGLWidget.doneCurrent();
KMETHOD QGLWidget_doneCurrent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		qp->doneCurrent();
	}
	RETURNvoid_();
}

//boolean QGLWidget.doubleBuffer();
KMETHOD QGLWidget_doubleBuffer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		bool ret_v = qp->doubleBuffer();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGLWidget.drawTexture(QRectF target, GLuint textureId, GLenum textureTarget);
KMETHOD QGLWidget_drawTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		const QRectF  target = *RawPtr_to(const QRectF *, sfp[1]);
		GLuint  textureId = *RawPtr_to(GLuint *, sfp[2]);
		GLenum  textureTarget = *RawPtr_to(GLenum *, sfp[3]);
		qp->drawTexture(target, textureId, textureTarget);
	}
	RETURNvoid_();
}

/*
//void QGLWidget.drawTexture(QPointF point, GLuint textureId, GLenum textureTarget);
KMETHOD QGLWidget_drawTexture(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		GLuint  textureId = *RawPtr_to(GLuint *, sfp[2]);
		GLenum  textureTarget = *RawPtr_to(GLenum *, sfp[3]);
		qp->drawTexture(point, textureId, textureTarget);
	}
	RETURNvoid_();
}
*/
//QGLFormat QGLWidget.format();
KMETHOD QGLWidget_format(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		QGLFormat ret_v = qp->format();
		QGLFormat *ret_v_ = new QGLFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QImage QGLWidget.grabFrameBuffer(boolean withAlpha);
KMETHOD QGLWidget_grabFrameBuffer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		bool withAlpha = Boolean_to(bool, sfp[1]);
		QImage ret_v = qp->grabFrameBuffer(withAlpha);
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGLWidget.isSharing();
KMETHOD QGLWidget_isSharing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSharing();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QGLWidget.makeCurrent();
KMETHOD QGLWidget_makeCurrent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		qp->makeCurrent();
	}
	RETURNvoid_();
}

//void QGLWidget.makeOverlayCurrent();
KMETHOD QGLWidget_makeOverlayCurrent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		qp->makeOverlayCurrent();
	}
	RETURNvoid_();
}

//QGLContext QGLWidget.overlayContext();
KMETHOD QGLWidget_overlayContext(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		const QGLContext* ret_v = qp->overlayContext();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGLContext*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGLWidget.qglClearColor(QColor c);
KMETHOD QGLWidget_qglClearColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		const QColor  c = *RawPtr_to(const QColor *, sfp[1]);
		qp->qglClearColor(c);
	}
	RETURNvoid_();
}

//void QGLWidget.qglColor(QColor c);
KMETHOD QGLWidget_qglColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		const QColor  c = *RawPtr_to(const QColor *, sfp[1]);
		qp->qglColor(c);
	}
	RETURNvoid_();
}

//QPixmap QGLWidget.renderPixmap(int w, int h, boolean useContext);
KMETHOD QGLWidget_renderPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		int w = Int_to(int, sfp[1]);
		int h = Int_to(int, sfp[2]);
		bool useContext = Boolean_to(bool, sfp[3]);
		QPixmap ret_v = qp->renderPixmap(w, h, useContext);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGLWidget.renderText(int x, int y, String str, QFont font, int listBase);
KMETHOD QGLWidget_renderText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		const QString str = String_to(const QString, sfp[3]);
		const QFont  font = *RawPtr_to(const QFont *, sfp[4]);
		int listBase = Int_to(int, sfp[5]);
		qp->renderText(x, y, str, font, listBase);
	}
	RETURNvoid_();
}

/*
//void QGLWidget.renderText(double x, double y, double z, String str, QFont font, int listBase);
KMETHOD QGLWidget_renderText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		double  x = *RawPtr_to(double *, sfp[1]);
		double  y = *RawPtr_to(double *, sfp[2]);
		double  z = *RawPtr_to(double *, sfp[3]);
		const QString str = String_to(const QString, sfp[4]);
		const QFont  font = *RawPtr_to(const QFont *, sfp[5]);
		int listBase = Int_to(int, sfp[6]);
		qp->renderText(x, y, z, str, font, listBase);
	}
	RETURNvoid_();
}
*/
//void QGLWidget.setColormap(QGLColormap cmap);
KMETHOD QGLWidget_setColormap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		const QGLColormap  cmap = *RawPtr_to(const QGLColormap *, sfp[1]);
		qp->setColormap(cmap);
	}
	RETURNvoid_();
}

//void QGLWidget.setMouseTracking(boolean enable);
KMETHOD QGLWidget_setMouseTracking(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setMouseTracking(enable);
	}
	RETURNvoid_();
}

//void QGLWidget.swapBuffers();
KMETHOD QGLWidget_swapBuffers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		qp->swapBuffers();
	}
	RETURNvoid_();
}

//QImage QGLWidget.convertToGLFormat(QImage img);
KMETHOD QGLWidget_convertToGLFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QImage  img = *RawPtr_to(const QImage *, sfp[1]);
		QImage ret_v = QGLWidget::convertToGLFormat(img);
		QImage *ret_v_ = new QImage(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QGLWidget.updateGL();
KMETHOD QGLWidget_updateGL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		qp->updateGL();
	}
	RETURNvoid_();
}

//@Virtual void QGLWidget.updateOverlayGL();
KMETHOD QGLWidget_updateOverlayGL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLWidget *  qp = RawPtr_to(QGLWidget *, sfp[0]);
	if (qp) {
		qp->updateOverlayGL();
	}
	RETURNvoid_();
}


DummyQGLWidget::DummyQGLWidget()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQGLWidget::~DummyQGLWidget()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQGLWidget::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGLWidget::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQGLWidget::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGLWidget::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLWidget::event_map->bigin();
	if ((itr = DummyQGLWidget::event_map->find(str)) == DummyQGLWidget::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGLWidget::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLWidget::slot_map->bigin();
	if ((itr = DummyQGLWidget::slot_map->find(str)) == DummyQGLWidget::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGLWidget::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGLWidget::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQWidget::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGLWidget::connection(QObject *o)
{
	QGLWidget *p = dynamic_cast<QGLWidget*>(o);
	if (p != NULL) {
	}
	DummyQWidget::connection(o);
}

KQGLWidget::KQGLWidget(QWidget* parent, const QGLWidget* shareWidget, Qt::WindowFlags f) : QGLWidget(parent, shareWidget, f)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQGLWidget();
	dummy->connection((QObject*)this);
}

KQGLWidget::~KQGLWidget()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QGLWidget_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLWidget *qp = RawPtr_to(KQGLWidget *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGLWidget]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLWidget]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGLWidget_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLWidget *qp = RawPtr_to(KQGLWidget *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGLWidget]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLWidget]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGLWidget_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQGLWidget *qp = (KQGLWidget *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QGLWidget*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QGLWidget_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQGLWidget *qp = (KQGLWidget *)p->rawptr;
		KQGLWidget *qp = static_cast<KQGLWidget*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGLWidget_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGLWidget::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGLWidget::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGLWidget::event(event);
		return false;
	}
//	QGLWidget::event(event);
	return true;
}



DEFAPI(void) defQGLWidget(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGLWidget";
	cdef->free = QGLWidget_free;
	cdef->reftrace = QGLWidget_reftrace;
	cdef->compareTo = QGLWidget_compareTo;
}


