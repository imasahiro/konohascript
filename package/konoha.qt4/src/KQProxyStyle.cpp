//@Virtual @Override void QProxyStyle.drawComplexControl(int control, QStyleOptionComplex option, QPainter painter, QWidget widget);
KMETHOD QProxyStyle_drawComplexControl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QProxyStyle::ComplexControl control = Int_to(QProxyStyle::ComplexControl, sfp[1]);
		const QStyleOptionComplex*  option = RawPtr_to(const QStyleOptionComplex*, sfp[2]);
		QPainter*  painter = RawPtr_to(QPainter*, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		qp->drawComplexControl(control, option, painter, widget);
	}
	RETURNvoid_();
}

//@Virtual @Override void QProxyStyle.drawControl(int element, QStyleOption option, QPainter painter, QWidget widget);
KMETHOD QProxyStyle_drawControl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QProxyStyle::ControlElement element = Int_to(QProxyStyle::ControlElement, sfp[1]);
		const QStyleOption*  option = RawPtr_to(const QStyleOption*, sfp[2]);
		QPainter*  painter = RawPtr_to(QPainter*, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		qp->drawControl(element, option, painter, widget);
	}
	RETURNvoid_();
}

//@Virtual @Override void QProxyStyle.drawItemPixmap(QPainter painter, QRect rect, int alignment, QPixmap pixmap);
KMETHOD QProxyStyle_drawItemPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QRect  rect = *RawPtr_to(const QRect *, sfp[2]);
		int alignment = Int_to(int, sfp[3]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[4]);
		qp->drawItemPixmap(painter, rect, alignment, pixmap);
	}
	RETURNvoid_();
}

//@Virtual @Override void QProxyStyle.drawItemText(QPainter painter, QRect rect, int flags, QPalette pal, boolean enabled, String text, int textRole);
KMETHOD QProxyStyle_drawItemText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QRect  rect = *RawPtr_to(const QRect *, sfp[2]);
		int flags = Int_to(int, sfp[3]);
		const QPalette  pal = *RawPtr_to(const QPalette *, sfp[4]);
		bool enabled = Boolean_to(bool, sfp[5]);
		const QString text = String_to(const QString, sfp[6]);
		QPalette::ColorRole textRole = Int_to(QPalette::ColorRole, sfp[7]);
		qp->drawItemText(painter, rect, flags, pal, enabled, text, textRole);
	}
	RETURNvoid_();
}

//@Virtual @Override void QProxyStyle.drawPrimitive(int element, QStyleOption option, QPainter painter, QWidget widget);
KMETHOD QProxyStyle_drawPrimitive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QProxyStyle::PrimitiveElement element = Int_to(QProxyStyle::PrimitiveElement, sfp[1]);
		const QStyleOption*  option = RawPtr_to(const QStyleOption*, sfp[2]);
		QPainter*  painter = RawPtr_to(QPainter*, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		qp->drawPrimitive(element, option, painter, widget);
	}
	RETURNvoid_();
}

//@Virtual @Override QPixmap QProxyStyle.generatedIconPixmap(int iconMode, QPixmap pixmap, QStyleOption opt);
KMETHOD QProxyStyle_generatedIconPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
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

//@Virtual @Override int QProxyStyle.hitTestComplexControl(int control, QStyleOptionComplex option, QPoint pos, QWidget widget);
KMETHOD QProxyStyle_hitTestComplexControl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QProxyStyle::ComplexControl control = Int_to(QProxyStyle::ComplexControl, sfp[1]);
		const QStyleOptionComplex*  option = RawPtr_to(const QStyleOptionComplex*, sfp[2]);
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		QProxyStyle::SubControl ret_v = qp->hitTestComplexControl(control, option, pos, widget);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QRect QProxyStyle.itemPixmapRect(QRect r, int flags, QPixmap pixmap);
KMETHOD QProxyStyle_itemPixmapRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		const QRect  r = *RawPtr_to(const QRect *, sfp[1]);
		int flags = Int_to(int, sfp[2]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[3]);
		QRect ret_v = qp->itemPixmapRect(r, flags, pixmap);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QRect QProxyStyle.itemTextRect(QFontMetrics fm, QRect r, int flags, boolean enabled, String text);
KMETHOD QProxyStyle_itemTextRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		const QFontMetrics  fm = *RawPtr_to(const QFontMetrics *, sfp[1]);
		const QRect  r = *RawPtr_to(const QRect *, sfp[2]);
		int flags = Int_to(int, sfp[3]);
		bool enabled = Boolean_to(bool, sfp[4]);
		const QString text = String_to(const QString, sfp[5]);
		QRect ret_v = qp->itemTextRect(fm, r, flags, enabled, text);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QProxyStyle.pixelMetric(int metric, QStyleOption option, QWidget widget);
KMETHOD QProxyStyle_pixelMetric(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QProxyStyle::PixelMetric metric = Int_to(QProxyStyle::PixelMetric, sfp[1]);
		const QStyleOption*  option = RawPtr_to(const QStyleOption*, sfp[2]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[3]);
		int ret_v = qp->pixelMetric(metric, option, widget);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//@Virtual @Override void QProxyStyle.polish(QWidget widget);
KMETHOD QProxyStyle_polish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->polish(widget);
	}
	RETURNvoid_();
}
*/
/*
//@Virtual @Override void QProxyStyle.polish(QPalette pal);
KMETHOD QProxyStyle_polish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QPalette  pal = *RawPtr_to(QPalette *, sfp[1]);
		qp->polish(pal);
	}
	RETURNvoid_();
}
*/
/*
//@Virtual @Override void QProxyStyle.polish(QApplication app);
KMETHOD QProxyStyle_polish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QApplication*  app = RawPtr_to(QApplication*, sfp[1]);
		qp->polish(app);
	}
	RETURNvoid_();
}
*/
//@Virtual @Override QSize QProxyStyle.sizeFromContents(int type, QStyleOption option, QSize size, QWidget widget);
KMETHOD QProxyStyle_sizeFromContents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QProxyStyle::ContentsType type = Int_to(QProxyStyle::ContentsType, sfp[1]);
		const QStyleOption*  option = RawPtr_to(const QStyleOption*, sfp[2]);
		const QSize  size = *RawPtr_to(const QSize *, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		QSize ret_v = qp->sizeFromContents(type, option, size, widget);
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QPalette QProxyStyle.standardPalette();
KMETHOD QProxyStyle_standardPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QPalette ret_v = qp->standardPalette();
		QPalette *ret_v_ = new QPalette(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QPixmap QProxyStyle.standardPixmap(int standardPixmap, QStyleOption opt, QWidget widget);
KMETHOD QProxyStyle_standardPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QProxyStyle::StandardPixmap standardPixmap = Int_to(QProxyStyle::StandardPixmap, sfp[1]);
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

//@Virtual @Override int QProxyStyle.styleHint(int hint, QStyleOption option, QWidget widget, QStyleHintReturn returnData);
KMETHOD QProxyStyle_styleHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QProxyStyle::StyleHint hint = Int_to(QProxyStyle::StyleHint, sfp[1]);
		const QStyleOption*  option = RawPtr_to(const QStyleOption*, sfp[2]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[3]);
		QStyleHintReturn*  returnData = RawPtr_to(QStyleHintReturn*, sfp[4]);
		int ret_v = qp->styleHint(hint, option, widget, returnData);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QRect QProxyStyle.subControlRect(int cc, QStyleOptionComplex option, int sc, QWidget widget);
KMETHOD QProxyStyle_subControlRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QProxyStyle::ComplexControl cc = Int_to(QProxyStyle::ComplexControl, sfp[1]);
		const QStyleOptionComplex*  option = RawPtr_to(const QStyleOptionComplex*, sfp[2]);
		QProxyStyle::SubControl sc = Int_to(QProxyStyle::SubControl, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		QRect ret_v = qp->subControlRect(cc, option, sc, widget);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QRect QProxyStyle.subElementRect(int element, QStyleOption option, QWidget widget);
KMETHOD QProxyStyle_subElementRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QProxyStyle::SubElement element = Int_to(QProxyStyle::SubElement, sfp[1]);
		const QStyleOption*  option = RawPtr_to(const QStyleOption*, sfp[2]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[3]);
		QRect ret_v = qp->subElementRect(element, option, widget);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//@Virtual @Override void QProxyStyle.unpolish(QWidget widget);
KMETHOD QProxyStyle_unpolish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->unpolish(widget);
	}
	RETURNvoid_();
}
*/
/*
//@Virtual @Override void QProxyStyle.unpolish(QApplication app);
KMETHOD QProxyStyle_unpolish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QApplication*  app = RawPtr_to(QApplication*, sfp[1]);
		qp->unpolish(app);
	}
	RETURNvoid_();
}
*/
//QProxyStyle QProxyStyle.new(QStyle style);
KMETHOD QProxyStyle_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle*  style = RawPtr_to(QStyle*, sfp[1]);
	KQProxyStyle *ret_v = new KQProxyStyle(style);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QStyle QProxyStyle.getBaseStyle();
KMETHOD QProxyStyle_getBaseStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QStyle* ret_v = qp->baseStyle();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QStyle*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QProxyStyle.setBaseStyle(QStyle style);
KMETHOD QProxyStyle_setBaseStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProxyStyle *  qp = RawPtr_to(QProxyStyle *, sfp[0]);
	if (qp) {
		QStyle*  style = RawPtr_to(QStyle*, sfp[1]);
		qp->setBaseStyle(style);
	}
	RETURNvoid_();
}


DummyQProxyStyle::DummyQProxyStyle()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQProxyStyle::setSelf(knh_RawPtr_t *ptr)
{
	DummyQProxyStyle::self = ptr;
	DummyQCommonStyle::setSelf(ptr);
}

bool DummyQProxyStyle::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQCommonStyle::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQProxyStyle::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQProxyStyle::event_map->bigin();
	if ((itr = DummyQProxyStyle::event_map->find(str)) == DummyQProxyStyle::event_map->end()) {
		bool ret = false;
		ret = DummyQCommonStyle::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQProxyStyle::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQProxyStyle::slot_map->bigin();
	if ((itr = DummyQProxyStyle::slot_map->find(str)) == DummyQProxyStyle::slot_map->end()) {
		bool ret = false;
		ret = DummyQCommonStyle::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQProxyStyle::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQCommonStyle::reftrace(ctx, p, tail_);
}

void DummyQProxyStyle::connection(QObject *o)
{
	QProxyStyle *p = dynamic_cast<QProxyStyle*>(o);
	if (p != NULL) {
	}
	DummyQCommonStyle::connection(o);
}

KQProxyStyle::KQProxyStyle(QStyle* style) : QProxyStyle(style)
{
	self = NULL;
	dummy = new DummyQProxyStyle();
	dummy->connection((QObject*)this);
}

KMETHOD QProxyStyle_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQProxyStyle *qp = RawPtr_to(KQProxyStyle *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QProxyStyle]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QProxyStyle]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QProxyStyle_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQProxyStyle *qp = RawPtr_to(KQProxyStyle *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QProxyStyle]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QProxyStyle]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QProxyStyle_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQProxyStyle *qp = (KQProxyStyle *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QProxyStyle_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQProxyStyle *qp = (KQProxyStyle *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QProxyStyle_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQProxyStyle::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQProxyStyle::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QProxyStyle::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQProxyStyle(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QProxyStyle";
	cdef->free = QProxyStyle_free;
	cdef->reftrace = QProxyStyle_reftrace;
	cdef->compareTo = QProxyStyle_compareTo;
}


