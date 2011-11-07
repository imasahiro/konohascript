//@Virtual @Override void QMotifStyle.drawComplexControl(int cc, QStyleOptionComplex opt, QPainter p, QWidget widget);
KMETHOD QMotifStyle_drawComplexControl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMotifStyle *  qp = RawPtr_to(QMotifStyle *, sfp[0]);
	if (qp) {
		QMotifStyle::ComplexControl cc = Int_to(QMotifStyle::ComplexControl, sfp[1]);
		const QStyleOptionComplex*  opt = RawPtr_to(const QStyleOptionComplex*, sfp[2]);
		QPainter*  p = RawPtr_to(QPainter*, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		qp->drawComplexControl(cc, opt, p, widget);
	}
	RETURNvoid_();
}

//@Virtual @Override void QMotifStyle.drawControl(int element, QStyleOption opt, QPainter p, QWidget widget);
KMETHOD QMotifStyle_drawControl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMotifStyle *  qp = RawPtr_to(QMotifStyle *, sfp[0]);
	if (qp) {
		QMotifStyle::ControlElement element = Int_to(QMotifStyle::ControlElement, sfp[1]);
		const QStyleOption*  opt = RawPtr_to(const QStyleOption*, sfp[2]);
		QPainter*  p = RawPtr_to(QPainter*, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		qp->drawControl(element, opt, p, widget);
	}
	RETURNvoid_();
}

//@Virtual @Override void QMotifStyle.drawPrimitive(int pe, QStyleOption opt, QPainter p, QWidget w);
KMETHOD QMotifStyle_drawPrimitive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMotifStyle *  qp = RawPtr_to(QMotifStyle *, sfp[0]);
	if (qp) {
		QMotifStyle::PrimitiveElement pe = Int_to(QMotifStyle::PrimitiveElement, sfp[1]);
		const QStyleOption*  opt = RawPtr_to(const QStyleOption*, sfp[2]);
		QPainter*  p = RawPtr_to(QPainter*, sfp[3]);
		const QWidget*  w = RawPtr_to(const QWidget*, sfp[4]);
		qp->drawPrimitive(pe, opt, p, w);
	}
	RETURNvoid_();
}

//@Virtual @Override boolean QMotifStyle.event(QEvent e);
KMETHOD QMotifStyle_event(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMotifStyle *  qp = RawPtr_to(QMotifStyle *, sfp[0]);
	if (qp) {
		QEvent*  e = RawPtr_to(QEvent*, sfp[1]);
		bool ret_v = qp->event(e);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override int QMotifStyle.pixelMetric(int pm, QStyleOption opt, QWidget widget);
KMETHOD QMotifStyle_pixelMetric(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMotifStyle *  qp = RawPtr_to(QMotifStyle *, sfp[0]);
	if (qp) {
		QMotifStyle::PixelMetric pm = Int_to(QMotifStyle::PixelMetric, sfp[1]);
		const QStyleOption*  opt = RawPtr_to(const QStyleOption*, sfp[2]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[3]);
		int ret_v = qp->pixelMetric(pm, opt, widget);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override void QMotifStyle.polish(QPalette pal);
KMETHOD QMotifStyle_polish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMotifStyle *  qp = RawPtr_to(QMotifStyle *, sfp[0]);
	if (qp) {
		QPalette  pal = *RawPtr_to(QPalette *, sfp[1]);
		qp->polish(pal);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QMotifStyle.sizeFromContents(int ct, QStyleOption opt, QSize contentsSize, QWidget widget);
KMETHOD QMotifStyle_sizeFromContents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMotifStyle *  qp = RawPtr_to(QMotifStyle *, sfp[0]);
	if (qp) {
		QMotifStyle::ContentsType ct = Int_to(QMotifStyle::ContentsType, sfp[1]);
		const QStyleOption*  opt = RawPtr_to(const QStyleOption*, sfp[2]);
		const QSize  contentsSize = *RawPtr_to(const QSize *, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		QSize ret_v = qp->sizeFromContents(ct, opt, contentsSize, widget);
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QPalette QMotifStyle.standardPalette();
KMETHOD QMotifStyle_standardPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMotifStyle *  qp = RawPtr_to(QMotifStyle *, sfp[0]);
	if (qp) {
		QPalette ret_v = qp->standardPalette();
		QPalette *ret_v_ = new QPalette(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QPixmap QMotifStyle.standardPixmap(int standardPixmap, QStyleOption opt, QWidget widget);
KMETHOD QMotifStyle_standardPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMotifStyle *  qp = RawPtr_to(QMotifStyle *, sfp[0]);
	if (qp) {
		QMotifStyle::StandardPixmap standardPixmap = Int_to(QMotifStyle::StandardPixmap, sfp[1]);
		const QStyleOption*  opt = RawPtr_to(const QStyleOption*, sfp[2]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[3]);
		QPixmap ret_v = qp->standardPixmap(standardPixmap, opt, widget);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QMotifStyle.styleHint(int hint, QStyleOption opt, QWidget widget, QStyleHintReturn returnData);
KMETHOD QMotifStyle_styleHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMotifStyle *  qp = RawPtr_to(QMotifStyle *, sfp[0]);
	if (qp) {
		QMotifStyle::StyleHint hint = Int_to(QMotifStyle::StyleHint, sfp[1]);
		const QStyleOption*  opt = RawPtr_to(const QStyleOption*, sfp[2]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[3]);
		QStyleHintReturn*  returnData = RawPtr_to(QStyleHintReturn*, sfp[4]);
		int ret_v = qp->styleHint(hint, opt, widget, returnData);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QRect QMotifStyle.subControlRect(int cc, QStyleOptionComplex opt, int sc, QWidget widget);
KMETHOD QMotifStyle_subControlRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMotifStyle *  qp = RawPtr_to(QMotifStyle *, sfp[0]);
	if (qp) {
		QMotifStyle::ComplexControl cc = Int_to(QMotifStyle::ComplexControl, sfp[1]);
		const QStyleOptionComplex*  opt = RawPtr_to(const QStyleOptionComplex*, sfp[2]);
		QMotifStyle::SubControl sc = Int_to(QMotifStyle::SubControl, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		QRect ret_v = qp->subControlRect(cc, opt, sc, widget);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QRect QMotifStyle.subElementRect(int sr, QStyleOption opt, QWidget widget);
KMETHOD QMotifStyle_subElementRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMotifStyle *  qp = RawPtr_to(QMotifStyle *, sfp[0]);
	if (qp) {
		QMotifStyle::SubElement sr = Int_to(QMotifStyle::SubElement, sfp[1]);
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

//QMotifStyle QMotifStyle.new(boolean useHighlightCols);
KMETHOD QMotifStyle_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	bool useHighlightCols = Boolean_to(bool, sfp[1]);
	KQMotifStyle *ret_v = new KQMotifStyle(useHighlightCols);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QMotifStyle.setUseHighlightColors(boolean arg);
KMETHOD QMotifStyle_setUseHighlightColors(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMotifStyle *  qp = RawPtr_to(QMotifStyle *, sfp[0]);
	if (qp) {
		bool arg = Boolean_to(bool, sfp[1]);
		qp->setUseHighlightColors(arg);
	}
	RETURNvoid_();
}

//boolean QMotifStyle.getUseHighlightColors();
KMETHOD QMotifStyle_getUseHighlightColors(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMotifStyle *  qp = RawPtr_to(QMotifStyle *, sfp[0]);
	if (qp) {
		bool ret_v = qp->useHighlightColors();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQMotifStyle::DummyQMotifStyle()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQMotifStyle::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMotifStyle::self = ptr;
	DummyQCommonStyle::setSelf(ptr);
}

bool DummyQMotifStyle::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQCommonStyle::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQMotifStyle::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMotifStyle::event_map->bigin();
	if ((itr = DummyQMotifStyle::event_map->find(str)) == DummyQMotifStyle::event_map->end()) {
		bool ret = false;
		ret = DummyQCommonStyle::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMotifStyle::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMotifStyle::slot_map->bigin();
	if ((itr = DummyQMotifStyle::slot_map->find(str)) == DummyQMotifStyle::slot_map->end()) {
		bool ret = false;
		ret = DummyQCommonStyle::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQMotifStyle::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQCommonStyle::reftrace(ctx, p, tail_);
}

void DummyQMotifStyle::connection(QObject *o)
{
	QMotifStyle *p = dynamic_cast<QMotifStyle*>(o);
	if (p != NULL) {
	}
	DummyQCommonStyle::connection(o);
}

KQMotifStyle::KQMotifStyle(bool useHighlightCols) : QMotifStyle(useHighlightCols)
{
	self = NULL;
	dummy = new DummyQMotifStyle();
	dummy->connection((QObject*)this);
}

KMETHOD QMotifStyle_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMotifStyle *qp = RawPtr_to(KQMotifStyle *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMotifStyle]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMotifStyle]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QMotifStyle_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMotifStyle *qp = RawPtr_to(KQMotifStyle *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMotifStyle]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMotifStyle]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMotifStyle_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMotifStyle *qp = (KQMotifStyle *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMotifStyle_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQMotifStyle *qp = (KQMotifStyle *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QMotifStyle_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMotifStyle::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQMotifStyle::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QMotifStyle::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQMotifStyle(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMotifStyle";
	cdef->free = QMotifStyle_free;
	cdef->reftrace = QMotifStyle_reftrace;
	cdef->compareTo = QMotifStyle_compareTo;
}


