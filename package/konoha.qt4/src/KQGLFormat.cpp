//QGLFormat QGLFormat.new();
KMETHOD QGLFormat_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLFormat *ret_v = new KQGLFormat();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGLFormat QGLFormat.new(int options, int plane);
KMETHOD QGLFormat_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGL::FormatOptions options = Int_to(QGL::FormatOptions, sfp[1]);
	int plane = Int_to(int, sfp[2]);
	KQGLFormat *ret_v = new KQGLFormat(options, plane);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QGLFormat QGLFormat.new(QGLFormat other);
KMETHOD QGLFormat_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QGLFormat  other = *RawPtr_to(const QGLFormat *, sfp[1]);
	KQGLFormat *ret_v = new KQGLFormat(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QGLFormat.getAccum();
KMETHOD QGLFormat_getAccum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool ret_v = qp->accum();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QGLFormat.getAccumBufferSize();
KMETHOD QGLFormat_getAccumBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->accumBufferSize();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QGLFormat.getAlpha();
KMETHOD QGLFormat_getAlpha(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool ret_v = qp->alpha();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QGLFormat.getAlphaBufferSize();
KMETHOD QGLFormat_getAlphaBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->alphaBufferSize();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QGLFormat.getBlueBufferSize();
KMETHOD QGLFormat_getBlueBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->blueBufferSize();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QGLFormat.getDepth();
KMETHOD QGLFormat_getDepth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool ret_v = qp->depth();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QGLFormat.getDepthBufferSize();
KMETHOD QGLFormat_getDepthBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->depthBufferSize();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QGLFormat.getDirectRendering();
KMETHOD QGLFormat_getDirectRendering(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool ret_v = qp->directRendering();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGLFormat.getDoubleBuffer();
KMETHOD QGLFormat_getDoubleBuffer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool ret_v = qp->doubleBuffer();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QGLFormat.getGreenBufferSize();
KMETHOD QGLFormat_getGreenBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->greenBufferSize();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QGLFormat.hasOverlay();
KMETHOD QGLFormat_hasOverlay(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasOverlay();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QGLFormat.majorVersion();
KMETHOD QGLFormat_majorVersion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->majorVersion();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QGLFormat.minorVersion();
KMETHOD QGLFormat_minorVersion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->minorVersion();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QGLFormat.getPlane();
KMETHOD QGLFormat_getPlane(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->plane();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QGLFormat.getProfile();
KMETHOD QGLFormat_getProfile(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		QGLFormat::OpenGLContextProfile ret_v = qp->profile();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QGLFormat.getRedBufferSize();
KMETHOD QGLFormat_getRedBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->redBufferSize();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QGLFormat.getRgba();
KMETHOD QGLFormat_getRgba(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool ret_v = qp->rgba();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGLFormat.getSampleBuffers();
KMETHOD QGLFormat_getSampleBuffers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool ret_v = qp->sampleBuffers();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QGLFormat.getSamples();
KMETHOD QGLFormat_getSamples(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->samples();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGLFormat.setAccum(boolean enable);
KMETHOD QGLFormat_setAccum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setAccum(enable);
	}
	RETURNvoid_();
}

//void QGLFormat.setAccumBufferSize(int size);
KMETHOD QGLFormat_setAccumBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int size = Int_to(int, sfp[1]);
		qp->setAccumBufferSize(size);
	}
	RETURNvoid_();
}

//void QGLFormat.setAlpha(boolean enable);
KMETHOD QGLFormat_setAlpha(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setAlpha(enable);
	}
	RETURNvoid_();
}

//void QGLFormat.setAlphaBufferSize(int size);
KMETHOD QGLFormat_setAlphaBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int size = Int_to(int, sfp[1]);
		qp->setAlphaBufferSize(size);
	}
	RETURNvoid_();
}

//void QGLFormat.setBlueBufferSize(int size);
KMETHOD QGLFormat_setBlueBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int size = Int_to(int, sfp[1]);
		qp->setBlueBufferSize(size);
	}
	RETURNvoid_();
}

//void QGLFormat.setDepth(boolean enable);
KMETHOD QGLFormat_setDepth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setDepth(enable);
	}
	RETURNvoid_();
}

//void QGLFormat.setDepthBufferSize(int size);
KMETHOD QGLFormat_setDepthBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int size = Int_to(int, sfp[1]);
		qp->setDepthBufferSize(size);
	}
	RETURNvoid_();
}

//void QGLFormat.setDirectRendering(boolean enable);
KMETHOD QGLFormat_setDirectRendering(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setDirectRendering(enable);
	}
	RETURNvoid_();
}

//void QGLFormat.setDoubleBuffer(boolean enable);
KMETHOD QGLFormat_setDoubleBuffer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setDoubleBuffer(enable);
	}
	RETURNvoid_();
}

//void QGLFormat.setGreenBufferSize(int size);
KMETHOD QGLFormat_setGreenBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int size = Int_to(int, sfp[1]);
		qp->setGreenBufferSize(size);
	}
	RETURNvoid_();
}

//void QGLFormat.setOption(int opt);
KMETHOD QGLFormat_setOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		QGL::FormatOptions opt = Int_to(QGL::FormatOptions, sfp[1]);
		qp->setOption(opt);
	}
	RETURNvoid_();
}

//void QGLFormat.setOverlay(boolean enable);
KMETHOD QGLFormat_setOverlay(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setOverlay(enable);
	}
	RETURNvoid_();
}

//void QGLFormat.setPlane(int plane);
KMETHOD QGLFormat_setPlane(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int plane = Int_to(int, sfp[1]);
		qp->setPlane(plane);
	}
	RETURNvoid_();
}

//void QGLFormat.setProfile(int profile);
KMETHOD QGLFormat_setProfile(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		QGLFormat::OpenGLContextProfile profile = Int_to(QGLFormat::OpenGLContextProfile, sfp[1]);
		qp->setProfile(profile);
	}
	RETURNvoid_();
}

//void QGLFormat.setRedBufferSize(int size);
KMETHOD QGLFormat_setRedBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int size = Int_to(int, sfp[1]);
		qp->setRedBufferSize(size);
	}
	RETURNvoid_();
}

//void QGLFormat.setRgba(boolean enable);
KMETHOD QGLFormat_setRgba(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setRgba(enable);
	}
	RETURNvoid_();
}

//void QGLFormat.setSampleBuffers(boolean enable);
KMETHOD QGLFormat_setSampleBuffers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setSampleBuffers(enable);
	}
	RETURNvoid_();
}

//void QGLFormat.setSamples(int numSamples);
KMETHOD QGLFormat_setSamples(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int numSamples = Int_to(int, sfp[1]);
		qp->setSamples(numSamples);
	}
	RETURNvoid_();
}

//void QGLFormat.setStencil(boolean enable);
KMETHOD QGLFormat_setStencil(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setStencil(enable);
	}
	RETURNvoid_();
}

//void QGLFormat.setStencilBufferSize(int size);
KMETHOD QGLFormat_setStencilBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int size = Int_to(int, sfp[1]);
		qp->setStencilBufferSize(size);
	}
	RETURNvoid_();
}

//void QGLFormat.setStereo(boolean enable);
KMETHOD QGLFormat_setStereo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setStereo(enable);
	}
	RETURNvoid_();
}

//void QGLFormat.setSwapInterval(int interval);
KMETHOD QGLFormat_setSwapInterval(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int interval = Int_to(int, sfp[1]);
		qp->setSwapInterval(interval);
	}
	RETURNvoid_();
}

//void QGLFormat.setVersion(int major, int minor);
KMETHOD QGLFormat_setVersion(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int major = Int_to(int, sfp[1]);
		int minor = Int_to(int, sfp[2]);
		qp->setVersion(major, minor);
	}
	RETURNvoid_();
}

//boolean QGLFormat.getStencil();
KMETHOD QGLFormat_getStencil(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool ret_v = qp->stencil();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QGLFormat.getStencilBufferSize();
KMETHOD QGLFormat_getStencilBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->stencilBufferSize();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QGLFormat.getStereo();
KMETHOD QGLFormat_getStereo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		bool ret_v = qp->stereo();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QGLFormat.getSwapInterval();
KMETHOD QGLFormat_getSwapInterval(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		int ret_v = qp->swapInterval();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QGLFormat.testOption(int opt);
KMETHOD QGLFormat_testOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *  qp = RawPtr_to(QGLFormat *, sfp[0]);
	if (qp) {
		QGL::FormatOptions opt = Int_to(QGL::FormatOptions, sfp[1]);
		bool ret_v = qp->testOption(opt);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QGLFormat QGLFormat.getDefaultFormat();
KMETHOD QGLFormat_getDefaultFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QGLFormat ret_v = QGLFormat::defaultFormat();
		QGLFormat *ret_v_ = new QGLFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGLFormat QGLFormat.getDefaultOverlayFormat();
KMETHOD QGLFormat_getDefaultOverlayFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QGLFormat ret_v = QGLFormat::defaultOverlayFormat();
		QGLFormat *ret_v_ = new QGLFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGLFormat.hasOpenGL();
KMETHOD QGLFormat_hasOpenGL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QGLFormat::hasOpenGL();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QGLFormat.hasOpenGLOverlays();
KMETHOD QGLFormat_hasOpenGLOverlays(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QGLFormat::hasOpenGLOverlays();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QGLFormatOpenGLVersionFlags QGLFormat.openGLVersionFlags();
KMETHOD QGLFormat_openGLVersionFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QGLFormat::OpenGLVersionFlags ret_v = QGLFormat::openGLVersionFlags();
		QGLFormat::OpenGLVersionFlags *ret_v_ = new QGLFormat::OpenGLVersionFlags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGLFormat.setDefaultFormat(QGLFormat f);
KMETHOD QGLFormat_setDefaultFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QGLFormat  f = *RawPtr_to(const QGLFormat *, sfp[1]);
		QGLFormat::setDefaultFormat(f);
	}
	RETURNvoid_();
}

//void QGLFormat.setDefaultOverlayFormat(QGLFormat f);
KMETHOD QGLFormat_setDefaultOverlayFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QGLFormat  f = *RawPtr_to(const QGLFormat *, sfp[1]);
		QGLFormat::setDefaultOverlayFormat(f);
	}
	RETURNvoid_();
}

//Array<String> QGLFormat.parents();
KMETHOD QGLFormat_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat *qp = RawPtr_to(QGLFormat*, sfp[0]);
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

DummyQGLFormat::DummyQGLFormat()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGLFormat::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGLFormat::self = ptr;
}

bool DummyQGLFormat::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQGLFormat::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLFormat::event_map->bigin();
	if ((itr = DummyQGLFormat::event_map->find(str)) == DummyQGLFormat::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGLFormat::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGLFormat::slot_map->bigin();
	if ((itr = DummyQGLFormat::slot_map->find(str)) == DummyQGLFormat::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGLFormat::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGLFormat::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQGLFormat::connection(QObject *o)
{
	QGLFormat *p = dynamic_cast<QGLFormat*>(o);
	if (p != NULL) {
	}
}

KQGLFormat::KQGLFormat() : QGLFormat()
{
	self = NULL;
	dummy = new DummyQGLFormat();
}

KMETHOD QGLFormat_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLFormat *qp = RawPtr_to(KQGLFormat *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGLFormat]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLFormat]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGLFormat_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGLFormat *qp = RawPtr_to(KQGLFormat *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGLFormat]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGLFormat]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGLFormat_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGLFormat *qp = (KQGLFormat *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGLFormat_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGLFormat *qp = (KQGLFormat *)p->rawptr;
//		KQGLFormat *qp = static_cast<KQGLFormat*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGLFormat_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QGLFormat*>(p1->rawptr) == *static_cast<QGLFormat*>(p2->rawptr) ? 0 : 1);
}

void KQGLFormat::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QGLFormatConstInt[] = {
	{"NoProfile", QGLFormat::NoProfile},
	{"CoreProfile", QGLFormat::CoreProfile},
	{"CompatibilityProfile", QGLFormat::CompatibilityProfile},
	{"OpenGL_Version_None", QGLFormat::OpenGL_Version_None},
	{"OpenGL_Version_1_1", QGLFormat::OpenGL_Version_1_1},
	{"OpenGL_Version_1_2", QGLFormat::OpenGL_Version_1_2},
	{"OpenGL_Version_1_3", QGLFormat::OpenGL_Version_1_3},
	{"OpenGL_Version_1_4", QGLFormat::OpenGL_Version_1_4},
	{"OpenGL_Version_1_5", QGLFormat::OpenGL_Version_1_5},
	{"OpenGL_Version_2_0", QGLFormat::OpenGL_Version_2_0},
	{"OpenGL_Version_2_1", QGLFormat::OpenGL_Version_2_1},
	{"OpenGL_Version_3_0", QGLFormat::OpenGL_Version_3_0},
	{"OpenGL_Version_3_1", QGLFormat::OpenGL_Version_3_1},
	{"OpenGL_Version_3_2", QGLFormat::OpenGL_Version_3_2},
	{"OpenGL_Version_3_3", QGLFormat::OpenGL_Version_3_3},
	{"OpenGL_Version_4_0", QGLFormat::OpenGL_Version_4_0},
	{"OpenGL_ES_CommonLite_Version_1_0", QGLFormat::OpenGL_ES_CommonLite_Version_1_0},
	{"OpenGL_ES_Common_Version_1_0", QGLFormat::OpenGL_ES_Common_Version_1_0},
	{"OpenGL_ES_CommonLite_Version_1_1", QGLFormat::OpenGL_ES_CommonLite_Version_1_1},
	{"OpenGL_ES_Common_Version_1_1", QGLFormat::OpenGL_ES_Common_Version_1_1},
	{"OpenGL_ES_Version_2_0", QGLFormat::OpenGL_ES_Version_2_0},
	{NULL, 0}
};

DEFAPI(void) constQGLFormat(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QGLFormatConstInt);
}


DEFAPI(void) defQGLFormat(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGLFormat";
	cdef->free = QGLFormat_free;
	cdef->reftrace = QGLFormat_reftrace;
	cdef->compareTo = QGLFormat_compareTo;
}

//## QGLFormatOpenGLVersionFlags QGLFormatOpenGLVersionFlags.new(int value);
KMETHOD QGLFormatOpenGLVersionFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLFormat::OpenGLVersionFlag i = Int_to(QGLFormat::OpenGLVersionFlag, sfp[1]);
	QGLFormat::OpenGLVersionFlags *ret_v = new QGLFormat::OpenGLVersionFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QGLFormatOpenGLVersionFlags QGLFormatOpenGLVersionFlags.and(int mask);
KMETHOD QGLFormatOpenGLVersionFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLFormat::OpenGLVersionFlags *qp = RawPtr_to(QGLFormat::OpenGLVersionFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QGLFormat::OpenGLVersionFlags ret = ((*qp) & i);
		QGLFormat::OpenGLVersionFlags *ret_ = new QGLFormat::OpenGLVersionFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGLFormatOpenGLVersionFlags QGLFormatOpenGLVersionFlags.iand(QGLFormat::QGLFormatOpenGLVersionFlags other);
KMETHOD QGLFormatOpenGLVersionFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLFormat::OpenGLVersionFlags *qp = RawPtr_to(QGLFormat::OpenGLVersionFlags*, sfp[0]);
	if (qp != NULL) {
		QGLFormat::OpenGLVersionFlags *other = RawPtr_to(QGLFormat::OpenGLVersionFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGLFormatOpenGLVersionFlags QGLFormatOpenGLVersionFlags.or(QGLFormatOpenGLVersionFlags f);
KMETHOD QGLFormatOpenGLVersionFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat::OpenGLVersionFlags *qp = RawPtr_to(QGLFormat::OpenGLVersionFlags*, sfp[0]);
	if (qp != NULL) {
		QGLFormat::OpenGLVersionFlags *f = RawPtr_to(QGLFormat::OpenGLVersionFlags*, sfp[1]);
		QGLFormat::OpenGLVersionFlags ret = ((*qp) | (*f));
		QGLFormat::OpenGLVersionFlags *ret_ = new QGLFormat::OpenGLVersionFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGLFormatOpenGLVersionFlags QGLFormatOpenGLVersionFlags.ior(QGLFormat::QGLFormatOpenGLVersionFlags other);
KMETHOD QGLFormatOpenGLVersionFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLFormat::OpenGLVersionFlags *qp = RawPtr_to(QGLFormat::OpenGLVersionFlags*, sfp[0]);
	if (qp != NULL) {
		QGLFormat::OpenGLVersionFlags *other = RawPtr_to(QGLFormat::OpenGLVersionFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGLFormatOpenGLVersionFlags QGLFormatOpenGLVersionFlags.xor(QGLFormatOpenGLVersionFlags f);
KMETHOD QGLFormatOpenGLVersionFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGLFormat::OpenGLVersionFlags *qp = RawPtr_to(QGLFormat::OpenGLVersionFlags*, sfp[0]);
	if (qp != NULL) {
		QGLFormat::OpenGLVersionFlags *f = RawPtr_to(QGLFormat::OpenGLVersionFlags*, sfp[1]);
		QGLFormat::OpenGLVersionFlags ret = ((*qp) ^ (*f));
		QGLFormat::OpenGLVersionFlags *ret_ = new QGLFormat::OpenGLVersionFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QGLFormatOpenGLVersionFlags QGLFormatOpenGLVersionFlags.ixor(QGLFormat::QGLFormatOpenGLVersionFlags other);
KMETHOD QGLFormatOpenGLVersionFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLFormat::OpenGLVersionFlags *qp = RawPtr_to(QGLFormat::OpenGLVersionFlags*, sfp[0]);
	if (qp != NULL) {
		QGLFormat::OpenGLVersionFlags *other = RawPtr_to(QGLFormat::OpenGLVersionFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QGLFormatOpenGLVersionFlags.testFlag(int flag);
KMETHOD QGLFormatOpenGLVersionFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLFormat::OpenGLVersionFlags *qp = RawPtr_to(QGLFormat::OpenGLVersionFlags *, sfp[0]);
	if (qp != NULL) {
		QGLFormat::OpenGLVersionFlag flag = Int_to(QGLFormat::OpenGLVersionFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QGLFormatOpenGLVersionFlags.value();
KMETHOD QGLFormatOpenGLVersionFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QGLFormat::OpenGLVersionFlags *qp = RawPtr_to(QGLFormat::OpenGLVersionFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QGLFormatOpenGLVersionFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QGLFormat::OpenGLVersionFlags *qp = (QGLFormat::OpenGLVersionFlags *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QGLFormatOpenGLVersionFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QGLFormat::OpenGLVersionFlags *qp = (QGLFormat::OpenGLVersionFlags *)p->rawptr;
		(void)qp;
	}
}

static int QGLFormatOpenGLVersionFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QGLFormat::OpenGLVersionFlags*)p1->rawptr);
//		int v2 = int(*(QGLFormat::OpenGLVersionFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QGLFormat::OpenGLVersionFlags v1 = *(QGLFormat::OpenGLVersionFlags*)p1->rawptr;
		QGLFormat::OpenGLVersionFlags v2 = *(QGLFormat::OpenGLVersionFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQGLFormatOpenGLVersionFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGLFormatOpenGLVersionFlags";
	cdef->free = QGLFormatOpenGLVersionFlags_free;
	cdef->reftrace = QGLFormatOpenGLVersionFlags_reftrace;
	cdef->compareTo = QGLFormatOpenGLVersionFlags_compareTo;
}

