//@Virtual @Override void QCommonStyle.drawComplexControl(int cc, QStyleOptionComplex opt, QPainter p, QWidget widget);
KMETHOD QCommonStyle_drawComplexControl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommonStyle *  qp = RawPtr_to(QCommonStyle *, sfp[0]);
	if (qp != NULL) {
		QCommonStyle::ComplexControl cc = Int_to(QCommonStyle::ComplexControl, sfp[1]);
		const QStyleOptionComplex*  opt = RawPtr_to(const QStyleOptionComplex*, sfp[2]);
		QPainter*  p = RawPtr_to(QPainter*, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		qp->drawComplexControl(cc, opt, p, widget);
	}
	RETURNvoid_();
}

//@Virtual @Override void QCommonStyle.drawControl(int element, QStyleOption opt, QPainter p, QWidget widget);
KMETHOD QCommonStyle_drawControl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommonStyle *  qp = RawPtr_to(QCommonStyle *, sfp[0]);
	if (qp != NULL) {
		QCommonStyle::ControlElement element = Int_to(QCommonStyle::ControlElement, sfp[1]);
		const QStyleOption*  opt = RawPtr_to(const QStyleOption*, sfp[2]);
		QPainter*  p = RawPtr_to(QPainter*, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		qp->drawControl(element, opt, p, widget);
	}
	RETURNvoid_();
}

//@Virtual @Override void QCommonStyle.drawPrimitive(int pe, QStyleOption opt, QPainter p, QWidget widget);
KMETHOD QCommonStyle_drawPrimitive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommonStyle *  qp = RawPtr_to(QCommonStyle *, sfp[0]);
	if (qp != NULL) {
		QCommonStyle::PrimitiveElement pe = Int_to(QCommonStyle::PrimitiveElement, sfp[1]);
		const QStyleOption*  opt = RawPtr_to(const QStyleOption*, sfp[2]);
		QPainter*  p = RawPtr_to(QPainter*, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		qp->drawPrimitive(pe, opt, p, widget);
	}
	RETURNvoid_();
}

//@Virtual @Override QPixmap QCommonStyle.generatedIconPixmap(int iconMode, QPixmap pixmap, QStyleOption opt);
KMETHOD QCommonStyle_generatedIconPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommonStyle *  qp = RawPtr_to(QCommonStyle *, sfp[0]);
	if (qp != NULL) {
		QIcon::Mode iconMode = Int_to(QIcon::Mode, sfp[1]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
		const QStyleOption*  opt = RawPtr_to(const QStyleOption*, sfp[3]);
		QPixmap ret_v = qp->generatedIconPixmap(iconMode, pixmap, opt);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QCommonStyle.hitTestComplexControl(int cc, QStyleOptionComplex opt, QPoint pt, QWidget widget);
KMETHOD QCommonStyle_hitTestComplexControl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommonStyle *  qp = RawPtr_to(QCommonStyle *, sfp[0]);
	if (qp != NULL) {
		QCommonStyle::ComplexControl cc = Int_to(QCommonStyle::ComplexControl, sfp[1]);
		const QStyleOptionComplex*  opt = RawPtr_to(const QStyleOptionComplex*, sfp[2]);
		const QPoint  pt = *RawPtr_to(const QPoint *, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		QCommonStyle::SubControl ret_v = qp->hitTestComplexControl(cc, opt, pt, widget);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override int QCommonStyle.pixelMetric(int m, QStyleOption opt, QWidget widget);
KMETHOD QCommonStyle_pixelMetric(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommonStyle *  qp = RawPtr_to(QCommonStyle *, sfp[0]);
	if (qp != NULL) {
		QCommonStyle::PixelMetric m = Int_to(QCommonStyle::PixelMetric, sfp[1]);
		const QStyleOption*  opt = RawPtr_to(const QStyleOption*, sfp[2]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[3]);
		int ret_v = qp->pixelMetric(m, opt, widget);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//@Virtual @Override void QCommonStyle.polish(QPalette pal);
KMETHOD QCommonStyle_polish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommonStyle *  qp = RawPtr_to(QCommonStyle *, sfp[0]);
	if (qp != NULL) {
		QPalette  pal = *RawPtr_to(QPalette *, sfp[1]);
		qp->polish(pal);
	}
	RETURNvoid_();
}
*/
/*
//@Virtual @Override void QCommonStyle.polish(QApplication app);
KMETHOD QCommonStyle_polish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommonStyle *  qp = RawPtr_to(QCommonStyle *, sfp[0]);
	if (qp != NULL) {
		QApplication*  app = RawPtr_to(QApplication*, sfp[1]);
		qp->polish(app);
	}
	RETURNvoid_();
}
*/
/*
//@Virtual @Override void QCommonStyle.polish(QWidget widget);
KMETHOD QCommonStyle_polish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommonStyle *  qp = RawPtr_to(QCommonStyle *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->polish(widget);
	}
	RETURNvoid_();
}
*/
//@Virtual @Override QSize QCommonStyle.sizeFromContents(int ct, QStyleOption opt, QSize csz, QWidget widget);
KMETHOD QCommonStyle_sizeFromContents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommonStyle *  qp = RawPtr_to(QCommonStyle *, sfp[0]);
	if (qp != NULL) {
		QCommonStyle::ContentsType ct = Int_to(QCommonStyle::ContentsType, sfp[1]);
		const QStyleOption*  opt = RawPtr_to(const QStyleOption*, sfp[2]);
		const QSize  csz = *RawPtr_to(const QSize *, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		QSize ret_v = qp->sizeFromContents(ct, opt, csz, widget);
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QPixmap QCommonStyle.standardPixmap(int sp, QStyleOption option, QWidget widget);
KMETHOD QCommonStyle_standardPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommonStyle *  qp = RawPtr_to(QCommonStyle *, sfp[0]);
	if (qp != NULL) {
		QCommonStyle::StandardPixmap sp = Int_to(QCommonStyle::StandardPixmap, sfp[1]);
		const QStyleOption*  option = RawPtr_to(const QStyleOption*, sfp[2]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[3]);
		QPixmap ret_v = qp->standardPixmap(sp, option, widget);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QCommonStyle.styleHint(int sh, QStyleOption opt, QWidget widget, QStyleHintReturn hret);
KMETHOD QCommonStyle_styleHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommonStyle *  qp = RawPtr_to(QCommonStyle *, sfp[0]);
	if (qp != NULL) {
		QCommonStyle::StyleHint sh = Int_to(QCommonStyle::StyleHint, sfp[1]);
		const QStyleOption*  opt = RawPtr_to(const QStyleOption*, sfp[2]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[3]);
		QStyleHintReturn*  hret = RawPtr_to(QStyleHintReturn*, sfp[4]);
		int ret_v = qp->styleHint(sh, opt, widget, hret);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QRect QCommonStyle.subControlRect(int cc, QStyleOptionComplex opt, int sc, QWidget widget);
KMETHOD QCommonStyle_subControlRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommonStyle *  qp = RawPtr_to(QCommonStyle *, sfp[0]);
	if (qp != NULL) {
		QCommonStyle::ComplexControl cc = Int_to(QCommonStyle::ComplexControl, sfp[1]);
		const QStyleOptionComplex*  opt = RawPtr_to(const QStyleOptionComplex*, sfp[2]);
		QCommonStyle::SubControl sc = Int_to(QCommonStyle::SubControl, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		QRect ret_v = qp->subControlRect(cc, opt, sc, widget);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QRect QCommonStyle.subElementRect(int sr, QStyleOption opt, QWidget widget);
KMETHOD QCommonStyle_subElementRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommonStyle *  qp = RawPtr_to(QCommonStyle *, sfp[0]);
	if (qp != NULL) {
		QCommonStyle::SubElement sr = Int_to(QCommonStyle::SubElement, sfp[1]);
		const QStyleOption*  opt = RawPtr_to(const QStyleOption*, sfp[2]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[3]);
		QRect ret_v = qp->subElementRect(sr, opt, widget);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//@Virtual @Override void QCommonStyle.unpolish(QWidget widget);
KMETHOD QCommonStyle_unpolish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommonStyle *  qp = RawPtr_to(QCommonStyle *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->unpolish(widget);
	}
	RETURNvoid_();
}
*/
/*
//@Virtual @Override void QCommonStyle.unpolish(QApplication application);
KMETHOD QCommonStyle_unpolish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCommonStyle *  qp = RawPtr_to(QCommonStyle *, sfp[0]);
	if (qp != NULL) {
		QApplication*  application = RawPtr_to(QApplication*, sfp[1]);
		qp->unpolish(application);
	}
	RETURNvoid_();
}
*/
//QCommonStyle QCommonStyle.new();
KMETHOD QCommonStyle_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCommonStyle *ret_v = new KQCommonStyle();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}


DummyQCommonStyle::DummyQCommonStyle()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQCommonStyle::setSelf(knh_RawPtr_t *ptr)
{
	DummyQCommonStyle::self = ptr;
	DummyQStyle::setSelf(ptr);
}

bool DummyQCommonStyle::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyle::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQCommonStyle::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCommonStyle::event_map->bigin();
	if ((itr = DummyQCommonStyle::event_map->find(str)) == DummyQCommonStyle::event_map->end()) {
		bool ret;
		ret = DummyQStyle::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQCommonStyle::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCommonStyle::slot_map->bigin();
	if ((itr = DummyQCommonStyle::event_map->find(str)) == DummyQCommonStyle::slot_map->end()) {
		bool ret;
		ret = DummyQStyle::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQCommonStyle::KQCommonStyle() : QCommonStyle()
{
	self = NULL;
}

KMETHOD QCommonStyle_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCommonStyle *qp = RawPtr_to(KQCommonStyle *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QCommonStyle]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQCommonStyle::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCommonStyle]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QCommonStyle_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCommonStyle *qp = RawPtr_to(KQCommonStyle *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QCommonStyle]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQCommonStyle::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCommonStyle]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QCommonStyle_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQCommonStyle *qp = (KQCommonStyle *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QCommonStyle_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQCommonStyle *qp = (KQCommonStyle *)p->rawptr;
		(void)qp;
	}
}

static int QCommonStyle_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQCommonStyle::event(QEvent *event)
{
	if (!DummyQCommonStyle::eventDispatcher(event)) {
		QCommonStyle::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQCommonStyle(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QCommonStyle";
	cdef->free = QCommonStyle_free;
	cdef->reftrace = QCommonStyle_reftrace;
	cdef->compareTo = QCommonStyle_compareTo;
}


