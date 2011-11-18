//
//int QStyle.combinedLayoutSpacing(int controls1, int controls2, int orientation, QStyleOption option, QWidget widget);
KMETHOD QStyle_combinedLayoutSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QSizePolicy::ControlTypes controls1 = Int_to(QSizePolicy::ControlTypes, sfp[1]);
		QSizePolicy::ControlTypes controls2 = Int_to(QSizePolicy::ControlTypes, sfp[2]);
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[3]);
		QStyleOption*  option = RawPtr_to(QStyleOption*, sfp[4]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[5]);
		int ret_v = qp->combinedLayoutSpacing(controls1, controls2, orientation, option, widget);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual void QStyle.drawComplexControl(int control, QStyleOptionComplex option, QPainter painter, QWidget widget);
KMETHOD QStyle_drawComplexControl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QStyle::ComplexControl control = Int_to(QStyle::ComplexControl, sfp[1]);
		const QStyleOptionComplex*  option = RawPtr_to(const QStyleOptionComplex*, sfp[2]);
		QPainter*  painter = RawPtr_to(QPainter*, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		qp->drawComplexControl(control, option, painter, widget);
	}
	RETURNvoid_();
}

//@Virtual void QStyle.drawControl(int element, QStyleOption option, QPainter painter, QWidget widget);
KMETHOD QStyle_drawControl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QStyle::ControlElement element = Int_to(QStyle::ControlElement, sfp[1]);
		const QStyleOption*  option = RawPtr_to(const QStyleOption*, sfp[2]);
		QPainter*  painter = RawPtr_to(QPainter*, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		qp->drawControl(element, option, painter, widget);
	}
	RETURNvoid_();
}

//@Virtual void QStyle.drawItemPixmap(QPainter painter, QRect rectangle, int alignment, QPixmap pixmap);
KMETHOD QStyle_drawItemPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[2]);
		int alignment = Int_to(int, sfp[3]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[4]);
		qp->drawItemPixmap(painter, rectangle, alignment, pixmap);
	}
	RETURNvoid_();
}

//@Virtual void QStyle.drawItemText(QPainter painter, QRect rectangle, int alignment, QPalette palette, boolean enabled, String text, int textRole);
KMETHOD QStyle_drawItemText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[2]);
		int alignment = Int_to(int, sfp[3]);
		const QPalette  palette = *RawPtr_to(const QPalette *, sfp[4]);
		bool enabled = Boolean_to(bool, sfp[5]);
		const QString text = String_to(const QString, sfp[6]);
		QPalette::ColorRole textRole = Int_to(QPalette::ColorRole, sfp[7]);
		qp->drawItemText(painter, rectangle, alignment, palette, enabled, text, textRole);
	}
	RETURNvoid_();
}

//@Virtual void QStyle.drawPrimitive(int element, QStyleOption option, QPainter painter, QWidget widget);
KMETHOD QStyle_drawPrimitive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QStyle::PrimitiveElement element = Int_to(QStyle::PrimitiveElement, sfp[1]);
		const QStyleOption*  option = RawPtr_to(const QStyleOption*, sfp[2]);
		QPainter*  painter = RawPtr_to(QPainter*, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		qp->drawPrimitive(element, option, painter, widget);
	}
	RETURNvoid_();
}

//@Virtual QPixmap QStyle.generatedIconPixmap(int iconMode, QPixmap pixmap, QStyleOption option);
KMETHOD QStyle_generatedIconPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QIcon::Mode iconMode = Int_to(QIcon::Mode, sfp[1]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
		const QStyleOption*  option = RawPtr_to(const QStyleOption*, sfp[3]);
		QPixmap ret_v = qp->generatedIconPixmap(iconMode, pixmap, option);
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual int QStyle.hitTestComplexControl(int control, QStyleOptionComplex option, QPoint position, QWidget widget);
KMETHOD QStyle_hitTestComplexControl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QStyle::ComplexControl control = Int_to(QStyle::ComplexControl, sfp[1]);
		const QStyleOptionComplex*  option = RawPtr_to(const QStyleOptionComplex*, sfp[2]);
		const QPoint  position = *RawPtr_to(const QPoint *, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		QStyle::SubControl ret_v = qp->hitTestComplexControl(control, option, position, widget);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QRect QStyle.itemPixmapRect(QRect rectangle, int alignment, QPixmap pixmap);
KMETHOD QStyle_itemPixmapRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
		int alignment = Int_to(int, sfp[2]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[3]);
		QRect ret_v = qp->itemPixmapRect(rectangle, alignment, pixmap);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QRect QStyle.itemTextRect(QFontMetrics metrics, QRect rectangle, int alignment, boolean enabled, String text);
KMETHOD QStyle_itemTextRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		const QFontMetrics  metrics = *RawPtr_to(const QFontMetrics *, sfp[1]);
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[2]);
		int alignment = Int_to(int, sfp[3]);
		bool enabled = Boolean_to(bool, sfp[4]);
		const QString text = String_to(const QString, sfp[5]);
		QRect ret_v = qp->itemTextRect(metrics, rectangle, alignment, enabled, text);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QStyle.layoutSpacing(int control1, int control2, int orientation, QStyleOption option, QWidget widget);
KMETHOD QStyle_layoutSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QSizePolicy::ControlType control1 = Int_to(QSizePolicy::ControlType, sfp[1]);
		QSizePolicy::ControlType control2 = Int_to(QSizePolicy::ControlType, sfp[2]);
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[3]);
		const QStyleOption*  option = RawPtr_to(const QStyleOption*, sfp[4]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[5]);
		int ret_v = qp->layoutSpacing(control1, control2, orientation, option, widget);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual int QStyle.pixelMetric(int metric, QStyleOption option, QWidget widget);
KMETHOD QStyle_pixelMetric(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QStyle::PixelMetric metric = Int_to(QStyle::PixelMetric, sfp[1]);
		const QStyleOption*  option = RawPtr_to(const QStyleOption*, sfp[2]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[3]);
		int ret_v = qp->pixelMetric(metric, option, widget);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual void QStyle.polish(QWidget widget);
KMETHOD QStyle_polish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->polish(widget);
	}
	RETURNvoid_();
}

/*
//@Virtual void QStyle.polish(QApplication application);
KMETHOD QStyle_polish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QApplication*  application = RawPtr_to(QApplication*, sfp[1]);
		qp->polish(application);
	}
	RETURNvoid_();
}
*/
/*
//@Virtual void QStyle.polish(QPalette palette);
KMETHOD QStyle_polish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QPalette  palette = *RawPtr_to(QPalette *, sfp[1]);
		qp->polish(palette);
	}
	RETURNvoid_();
}
*/
//QStyle QStyle.proxy();
KMETHOD QStyle_proxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		const QStyle* ret_v = qp->proxy();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QStyle*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QSize QStyle.sizeFromContents(int type, QStyleOption option, QSize contentsSize, QWidget widget);
KMETHOD QStyle_sizeFromContents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QStyle::ContentsType type = Int_to(QStyle::ContentsType, sfp[1]);
		const QStyleOption*  option = RawPtr_to(const QStyleOption*, sfp[2]);
		const QSize  contentsSize = *RawPtr_to(const QSize *, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		QSize ret_v = qp->sizeFromContents(type, option, contentsSize, widget);
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QIcon QStyle.standardIcon(int standardIcon, QStyleOption option, QWidget widget);
KMETHOD QStyle_standardIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QStyle::StandardPixmap standardIcon = Int_to(QStyle::StandardPixmap, sfp[1]);
		const QStyleOption*  option = RawPtr_to(const QStyleOption*, sfp[2]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[3]);
		QIcon ret_v = qp->standardIcon(standardIcon, option, widget);
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QPalette QStyle.standardPalette();
KMETHOD QStyle_standardPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QPalette ret_v = qp->standardPalette();
		QPalette *ret_v_ = new QPalette(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual int QStyle.styleHint(int hint, QStyleOption option, QWidget widget, QStyleHintReturn returnData);
KMETHOD QStyle_styleHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QStyle::StyleHint hint = Int_to(QStyle::StyleHint, sfp[1]);
		const QStyleOption*  option = RawPtr_to(const QStyleOption*, sfp[2]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[3]);
		QStyleHintReturn*  returnData = RawPtr_to(QStyleHintReturn*, sfp[4]);
		int ret_v = qp->styleHint(hint, option, widget, returnData);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QRect QStyle.subControlRect(int control, QStyleOptionComplex option, int subControl, QWidget widget);
KMETHOD QStyle_subControlRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QStyle::ComplexControl control = Int_to(QStyle::ComplexControl, sfp[1]);
		const QStyleOptionComplex*  option = RawPtr_to(const QStyleOptionComplex*, sfp[2]);
		QStyle::SubControl subControl = Int_to(QStyle::SubControl, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		QRect ret_v = qp->subControlRect(control, option, subControl, widget);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QRect QStyle.subElementRect(int element, QStyleOption option, QWidget widget);
KMETHOD QStyle_subElementRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QStyle::SubElement element = Int_to(QStyle::SubElement, sfp[1]);
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

//@Virtual void QStyle.unpolish(QWidget widget);
KMETHOD QStyle_unpolish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->unpolish(widget);
	}
	RETURNvoid_();
}

/*
//@Virtual void QStyle.unpolish(QApplication application);
KMETHOD QStyle_unpolish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle *  qp = RawPtr_to(QStyle *, sfp[0]);
	if (qp) {
		QApplication*  application = RawPtr_to(QApplication*, sfp[1]);
		qp->unpolish(application);
	}
	RETURNvoid_();
}
*/
//QRect QStyle.alignedRect(int direction, QtAlignment alignment, QSize size, QRect rectangle);
KMETHOD QStyle_alignedRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		Qt::LayoutDirection direction = Int_to(Qt::LayoutDirection, sfp[1]);
		initFlag(alignment, Qt::Alignment, sfp[2]);
		const QSize  size = *RawPtr_to(const QSize *, sfp[3]);
		const QRect  rectangle = *RawPtr_to(const QRect *, sfp[4]);
		QRect ret_v = QStyle::alignedRect(direction, alignment, size, rectangle);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QStyle.sliderPositionFromValue(int min, int max, int logicalValue, int span, boolean upsideDown);
KMETHOD QStyle_sliderPositionFromValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int min = Int_to(int, sfp[1]);
		int max = Int_to(int, sfp[2]);
		int logicalValue = Int_to(int, sfp[3]);
		int span = Int_to(int, sfp[4]);
		bool upsideDown = Boolean_to(bool, sfp[5]);
		int ret_v = QStyle::sliderPositionFromValue(min, max, logicalValue, span, upsideDown);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QStyle.sliderValueFromPosition(int min, int max, int position, int span, boolean upsideDown);
KMETHOD QStyle_sliderValueFromPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int min = Int_to(int, sfp[1]);
		int max = Int_to(int, sfp[2]);
		int position = Int_to(int, sfp[3]);
		int span = Int_to(int, sfp[4]);
		bool upsideDown = Boolean_to(bool, sfp[5]);
		int ret_v = QStyle::sliderValueFromPosition(min, max, position, span, upsideDown);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QtAlignment QStyle.visualAlignment(int direction, QtAlignment alignment);
KMETHOD QStyle_visualAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		Qt::LayoutDirection direction = Int_to(Qt::LayoutDirection, sfp[1]);
		initFlag(alignment, Qt::Alignment, sfp[2]);
		Qt::Alignment ret_v = QStyle::visualAlignment(direction, alignment);
		Qt::Alignment *ret_v_ = new Qt::Alignment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QStyle.visualPos(int direction, QRect boundingRectangle, QPoint logicalPosition);
KMETHOD QStyle_visualPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		Qt::LayoutDirection direction = Int_to(Qt::LayoutDirection, sfp[1]);
		const QRect  boundingRectangle = *RawPtr_to(const QRect *, sfp[2]);
		const QPoint  logicalPosition = *RawPtr_to(const QPoint *, sfp[3]);
		QPoint ret_v = QStyle::visualPos(direction, boundingRectangle, logicalPosition);
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QStyle.visualRect(int direction, QRect boundingRectangle, QRect logicalRectangle);
KMETHOD QStyle_visualRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		Qt::LayoutDirection direction = Int_to(Qt::LayoutDirection, sfp[1]);
		const QRect  boundingRectangle = *RawPtr_to(const QRect *, sfp[2]);
		const QRect  logicalRectangle = *RawPtr_to(const QRect *, sfp[3]);
		QRect ret_v = QStyle::visualRect(direction, boundingRectangle, logicalRectangle);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQStyle::DummyQStyle()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQStyle::~DummyQStyle()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQStyle::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyle::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQStyle::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyle::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyle::event_map->bigin();
	if ((itr = DummyQStyle::event_map->find(str)) == DummyQStyle::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyle::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyle::slot_map->bigin();
	if ((itr = DummyQStyle::slot_map->find(str)) == DummyQStyle::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyle::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyle::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyle::connection(QObject *o)
{
	QStyle *p = dynamic_cast<QStyle*>(o);
	if (p != NULL) {
	}
	DummyQObject::connection(o);
}

KQStyle::KQStyle() : QStyle()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQStyle();
	dummy->connection((QObject*)this);
}

KQStyle::~KQStyle()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QStyle_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyle *qp = RawPtr_to(KQStyle *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyle]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyle]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyle_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyle *qp = RawPtr_to(KQStyle *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyle]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyle]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyle_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQStyle *qp = (KQStyle *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QStyle*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QStyle_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQStyle *qp = (KQStyle *)p->rawptr;
		KQStyle *qp = static_cast<KQStyle*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyle_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyle::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQStyle::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QStyle::event(event);
		return false;
	}
//	QStyle::event(event);
	return true;
}

static knh_IntData_t QStyleConstInt[] = {
	{"CC_SpinBox", QStyle::CC_SpinBox},
	{"CC_ComboBox", QStyle::CC_ComboBox},
	{"CC_ScrollBar", QStyle::CC_ScrollBar},
	{"CC_Slider", QStyle::CC_Slider},
	{"CC_ToolButton", QStyle::CC_ToolButton},
	{"CC_TitleBar", QStyle::CC_TitleBar},
	{"CC_Q3ListView", QStyle::CC_Q3ListView},
	{"CC_GroupBox", QStyle::CC_GroupBox},
	{"CC_Dial", QStyle::CC_Dial},
	{"CC_MdiControls", QStyle::CC_MdiControls},
	{"CC_CustomBase", QStyle::CC_CustomBase},
	{"CT_CheckBox", QStyle::CT_CheckBox},
	{"CT_ComboBox", QStyle::CT_ComboBox},
	{"CT_Q3DockWindow", QStyle::CT_Q3DockWindow},
	{"CT_HeaderSection", QStyle::CT_HeaderSection},
	{"CT_LineEdit", QStyle::CT_LineEdit},
	{"CT_Menu", QStyle::CT_Menu},
	{"CT_Q3Header", QStyle::CT_Q3Header},
	{"CT_MenuBar", QStyle::CT_MenuBar},
	{"CT_MenuBarItem", QStyle::CT_MenuBarItem},
	{"CT_MenuItem", QStyle::CT_MenuItem},
	{"CT_ProgressBar", QStyle::CT_ProgressBar},
	{"CT_PushButton", QStyle::CT_PushButton},
	{"CT_RadioButton", QStyle::CT_RadioButton},
	{"CT_SizeGrip", QStyle::CT_SizeGrip},
	{"CT_Slider", QStyle::CT_Slider},
	{"CT_ScrollBar", QStyle::CT_ScrollBar},
	{"CT_SpinBox", QStyle::CT_SpinBox},
	{"CT_Splitter", QStyle::CT_Splitter},
	{"CT_TabBarTab", QStyle::CT_TabBarTab},
	{"CT_TabWidget", QStyle::CT_TabWidget},
	{"CT_ToolButton", QStyle::CT_ToolButton},
	{"CT_GroupBox", QStyle::CT_GroupBox},
	{"CT_ItemViewItem", QStyle::CT_ItemViewItem},
	{"CT_CustomBase", QStyle::CT_CustomBase},
	{"CT_MdiControls", QStyle::CT_MdiControls},
	{"CE_PushButton", QStyle::CE_PushButton},
	{"CE_PushButtonBevel", QStyle::CE_PushButtonBevel},
	{"CE_PushButtonLabel", QStyle::CE_PushButtonLabel},
	{"CE_DockWidgetTitle", QStyle::CE_DockWidgetTitle},
	{"CE_Splitter", QStyle::CE_Splitter},
	{"CE_CheckBox", QStyle::CE_CheckBox},
	{"CE_CheckBoxLabel", QStyle::CE_CheckBoxLabel},
	{"CE_RadioButton", QStyle::CE_RadioButton},
	{"CE_RadioButtonLabel", QStyle::CE_RadioButtonLabel},
	{"CE_TabBarTab", QStyle::CE_TabBarTab},
	{"CE_TabBarTabShape", QStyle::CE_TabBarTabShape},
	{"CE_TabBarTabLabel", QStyle::CE_TabBarTabLabel},
	{"CE_ProgressBar", QStyle::CE_ProgressBar},
	{"CE_ProgressBarGroove", QStyle::CE_ProgressBarGroove},
	{"CE_ProgressBarContents", QStyle::CE_ProgressBarContents},
	{"CE_ProgressBarLabel", QStyle::CE_ProgressBarLabel},
	{"CE_ToolButtonLabel", QStyle::CE_ToolButtonLabel},
	{"CE_MenuBarItem", QStyle::CE_MenuBarItem},
	{"CE_MenuBarEmptyArea", QStyle::CE_MenuBarEmptyArea},
	{"CE_MenuItem", QStyle::CE_MenuItem},
	{"CE_MenuScroller", QStyle::CE_MenuScroller},
	{"CE_MenuTearoff", QStyle::CE_MenuTearoff},
	{"CE_MenuEmptyArea", QStyle::CE_MenuEmptyArea},
	{"CE_MenuHMargin", QStyle::CE_MenuHMargin},
	{"CE_MenuVMargin", QStyle::CE_MenuVMargin},
	{"CE_Q3DockWindowEmptyArea", QStyle::CE_Q3DockWindowEmptyArea},
	{"CE_ToolBoxTab", QStyle::CE_ToolBoxTab},
	{"CE_SizeGrip", QStyle::CE_SizeGrip},
	{"CE_Header", QStyle::CE_Header},
	{"CE_HeaderSection", QStyle::CE_HeaderSection},
	{"CE_HeaderLabel", QStyle::CE_HeaderLabel},
	{"CE_ScrollBarAddLine", QStyle::CE_ScrollBarAddLine},
	{"CE_ScrollBarSubLine", QStyle::CE_ScrollBarSubLine},
	{"CE_ScrollBarAddPage", QStyle::CE_ScrollBarAddPage},
	{"CE_ScrollBarSubPage", QStyle::CE_ScrollBarSubPage},
	{"CE_ScrollBarSlider", QStyle::CE_ScrollBarSlider},
	{"CE_ScrollBarFirst", QStyle::CE_ScrollBarFirst},
	{"CE_ScrollBarLast", QStyle::CE_ScrollBarLast},
	{"CE_RubberBand", QStyle::CE_RubberBand},
	{"CE_FocusFrame", QStyle::CE_FocusFrame},
	{"CE_ItemViewItem", QStyle::CE_ItemViewItem},
	{"CE_CustomBase", QStyle::CE_CustomBase},
	{"CE_ComboBoxLabel", QStyle::CE_ComboBoxLabel},
	{"CE_ToolBar", QStyle::CE_ToolBar},
	{"CE_ToolBoxTabShape", QStyle::CE_ToolBoxTabShape},
	{"CE_ToolBoxTabLabel", QStyle::CE_ToolBoxTabLabel},
	{"CE_HeaderEmptyArea", QStyle::CE_HeaderEmptyArea},
	{"CE_ShapedFrame", QStyle::CE_ShapedFrame},
	{"PM_ButtonMargin", QStyle::PM_ButtonMargin},
	{"PM_DockWidgetTitleBarButtonMargin", QStyle::PM_DockWidgetTitleBarButtonMargin},
	{"PM_ButtonDefaultIndicator", QStyle::PM_ButtonDefaultIndicator},
	{"PM_MenuButtonIndicator", QStyle::PM_MenuButtonIndicator},
	{"PM_ButtonShiftHorizontal", QStyle::PM_ButtonShiftHorizontal},
	{"PM_ButtonShiftVertical", QStyle::PM_ButtonShiftVertical},
	{"PM_DefaultFrameWidth", QStyle::PM_DefaultFrameWidth},
	{"PM_SpinBoxFrameWidth", QStyle::PM_SpinBoxFrameWidth},
	{"PM_ComboBoxFrameWidth", QStyle::PM_ComboBoxFrameWidth},
	{"PM_MDIFrameWidth", QStyle::PM_MDIFrameWidth},
	{"PM_MdiSubWindowFrameWidth", QStyle::PM_MdiSubWindowFrameWidth},
	{"PM_MDIMinimizedWidth", QStyle::PM_MDIMinimizedWidth},
	{"PM_MdiSubWindowMinimizedWidth", QStyle::PM_MdiSubWindowMinimizedWidth},
	{"PM_LayoutLeftMargin", QStyle::PM_LayoutLeftMargin},
	{"PM_LayoutTopMargin", QStyle::PM_LayoutTopMargin},
	{"PM_LayoutRightMargin", QStyle::PM_LayoutRightMargin},
	{"PM_LayoutBottomMargin", QStyle::PM_LayoutBottomMargin},
	{"PM_LayoutHorizontalSpacing", QStyle::PM_LayoutHorizontalSpacing},
	{"PM_LayoutVerticalSpacing", QStyle::PM_LayoutVerticalSpacing},
	{"PM_MaximumDragDistance", QStyle::PM_MaximumDragDistance},
	{"PM_ScrollBarExtent", QStyle::PM_ScrollBarExtent},
	{"PM_ScrollBarSliderMin", QStyle::PM_ScrollBarSliderMin},
	{"PM_SliderThickness", QStyle::PM_SliderThickness},
	{"PM_SliderControlThickness", QStyle::PM_SliderControlThickness},
	{"PM_SliderLength", QStyle::PM_SliderLength},
	{"PM_SliderTickmarkOffset", QStyle::PM_SliderTickmarkOffset},
	{"PM_SliderSpaceAvailable", QStyle::PM_SliderSpaceAvailable},
	{"PM_DockWidgetSeparatorExtent", QStyle::PM_DockWidgetSeparatorExtent},
	{"PM_DockWidgetHandleExtent", QStyle::PM_DockWidgetHandleExtent},
	{"PM_DockWidgetFrameWidth", QStyle::PM_DockWidgetFrameWidth},
	{"PM_DockWidgetTitleMargin", QStyle::PM_DockWidgetTitleMargin},
	{"PM_MenuBarPanelWidth", QStyle::PM_MenuBarPanelWidth},
	{"PM_MenuBarItemSpacing", QStyle::PM_MenuBarItemSpacing},
	{"PM_MenuBarHMargin", QStyle::PM_MenuBarHMargin},
	{"PM_MenuBarVMargin", QStyle::PM_MenuBarVMargin},
	{"PM_ToolBarFrameWidth", QStyle::PM_ToolBarFrameWidth},
	{"PM_ToolBarHandleExtent", QStyle::PM_ToolBarHandleExtent},
	{"PM_ToolBarItemMargin", QStyle::PM_ToolBarItemMargin},
	{"PM_ToolBarItemSpacing", QStyle::PM_ToolBarItemSpacing},
	{"PM_ToolBarSeparatorExtent", QStyle::PM_ToolBarSeparatorExtent},
	{"PM_ToolBarExtensionExtent", QStyle::PM_ToolBarExtensionExtent},
	{"PM_TabBarTabOverlap", QStyle::PM_TabBarTabOverlap},
	{"PM_TabBarTabHSpace", QStyle::PM_TabBarTabHSpace},
	{"PM_TabBarTabVSpace", QStyle::PM_TabBarTabVSpace},
	{"PM_TabBarBaseHeight", QStyle::PM_TabBarBaseHeight},
	{"PM_TabBarBaseOverlap", QStyle::PM_TabBarBaseOverlap},
	{"PM_TabBarScrollButtonWidth", QStyle::PM_TabBarScrollButtonWidth},
	{"PM_TabBarTabShiftHorizontal", QStyle::PM_TabBarTabShiftHorizontal},
	{"PM_TabBarTabShiftVertical", QStyle::PM_TabBarTabShiftVertical},
	{"PM_ProgressBarChunkWidth", QStyle::PM_ProgressBarChunkWidth},
	{"PM_SplitterWidth", QStyle::PM_SplitterWidth},
	{"PM_TitleBarHeight", QStyle::PM_TitleBarHeight},
	{"PM_IndicatorWidth", QStyle::PM_IndicatorWidth},
	{"PM_IndicatorHeight", QStyle::PM_IndicatorHeight},
	{"PM_ExclusiveIndicatorWidth", QStyle::PM_ExclusiveIndicatorWidth},
	{"PM_ExclusiveIndicatorHeight", QStyle::PM_ExclusiveIndicatorHeight},
	{"PM_MenuPanelWidth", QStyle::PM_MenuPanelWidth},
	{"PM_MenuHMargin", QStyle::PM_MenuHMargin},
	{"PM_MenuVMargin", QStyle::PM_MenuVMargin},
	{"PM_MenuScrollerHeight", QStyle::PM_MenuScrollerHeight},
	{"PM_MenuTearoffHeight", QStyle::PM_MenuTearoffHeight},
	{"PM_MenuDesktopFrameWidth", QStyle::PM_MenuDesktopFrameWidth},
	{"PM_CheckListButtonSize", QStyle::PM_CheckListButtonSize},
	{"PM_CheckListControllerSize", QStyle::PM_CheckListControllerSize},
	{"PM_HeaderMarkSize", QStyle::PM_HeaderMarkSize},
	{"PM_HeaderGripMargin", QStyle::PM_HeaderGripMargin},
	{"PM_HeaderMargin", QStyle::PM_HeaderMargin},
	{"PM_SpinBoxSliderHeight", QStyle::PM_SpinBoxSliderHeight},
	{"PM_ToolBarIconSize", QStyle::PM_ToolBarIconSize},
	{"PM_SmallIconSize", QStyle::PM_SmallIconSize},
	{"PM_LargeIconSize", QStyle::PM_LargeIconSize},
	{"PM_FocusFrameHMargin", QStyle::PM_FocusFrameHMargin},
	{"PM_FocusFrameVMargin", QStyle::PM_FocusFrameVMargin},
	{"PM_IconViewIconSize", QStyle::PM_IconViewIconSize},
	{"PM_ListViewIconSize", QStyle::PM_ListViewIconSize},
	{"PM_ToolTipLabelFrameWidth", QStyle::PM_ToolTipLabelFrameWidth},
	{"PM_CheckBoxLabelSpacing", QStyle::PM_CheckBoxLabelSpacing},
	{"PM_RadioButtonLabelSpacing", QStyle::PM_RadioButtonLabelSpacing},
	{"PM_TabBarIconSize", QStyle::PM_TabBarIconSize},
	{"PM_SizeGripSize", QStyle::PM_SizeGripSize},
	{"PM_MessageBoxIconSize", QStyle::PM_MessageBoxIconSize},
	{"PM_ButtonIconSize", QStyle::PM_ButtonIconSize},
	{"PM_TextCursorWidth", QStyle::PM_TextCursorWidth},
	{"PM_TabBar_ScrollButtonOverlap", QStyle::PM_TabBar_ScrollButtonOverlap},
	{"PM_TabCloseIndicatorWidth", QStyle::PM_TabCloseIndicatorWidth},
	{"PM_TabCloseIndicatorHeight", QStyle::PM_TabCloseIndicatorHeight},
	{"PM_CustomBase", QStyle::PM_CustomBase},
	{"PM_DefaultTopLevelMargin", QStyle::PM_DefaultTopLevelMargin},
	{"PM_DefaultChildMargin", QStyle::PM_DefaultChildMargin},
	{"PM_DefaultLayoutSpacing", QStyle::PM_DefaultLayoutSpacing},
	{"PM_ScrollView_ScrollBarSpacing", QStyle::PM_ScrollView_ScrollBarSpacing},
	{"PM_SubMenuOverlap", QStyle::PM_SubMenuOverlap},
	{"PE_FrameStatusBar", QStyle::PE_FrameStatusBar},
	{"PE_PanelButtonCommand", QStyle::PE_PanelButtonCommand},
	{"PE_FrameDefaultButton", QStyle::PE_FrameDefaultButton},
	{"PE_PanelButtonBevel", QStyle::PE_PanelButtonBevel},
	{"PE_PanelButtonTool", QStyle::PE_PanelButtonTool},
	{"PE_PanelLineEdit", QStyle::PE_PanelLineEdit},
	{"PE_IndicatorButtonDropDown", QStyle::PE_IndicatorButtonDropDown},
	{"PE_FrameFocusRect", QStyle::PE_FrameFocusRect},
	{"PE_IndicatorArrowUp", QStyle::PE_IndicatorArrowUp},
	{"PE_IndicatorArrowDown", QStyle::PE_IndicatorArrowDown},
	{"PE_IndicatorArrowRight", QStyle::PE_IndicatorArrowRight},
	{"PE_IndicatorArrowLeft", QStyle::PE_IndicatorArrowLeft},
	{"PE_IndicatorSpinUp", QStyle::PE_IndicatorSpinUp},
	{"PE_IndicatorSpinDown", QStyle::PE_IndicatorSpinDown},
	{"PE_IndicatorSpinPlus", QStyle::PE_IndicatorSpinPlus},
	{"PE_IndicatorSpinMinus", QStyle::PE_IndicatorSpinMinus},
	{"PE_IndicatorItemViewItemCheck", QStyle::PE_IndicatorItemViewItemCheck},
	{"PE_IndicatorCheckBox", QStyle::PE_IndicatorCheckBox},
	{"PE_IndicatorRadioButton", QStyle::PE_IndicatorRadioButton},
	{"PE_Q3DockWindowSeparator", QStyle::PE_Q3DockWindowSeparator},
	{"PE_IndicatorDockWidgetResizeHandle", QStyle::PE_IndicatorDockWidgetResizeHandle},
	{"PE_Frame", QStyle::PE_Frame},
	{"PE_FrameMenu", QStyle::PE_FrameMenu},
	{"PE_PanelMenuBar", QStyle::PE_PanelMenuBar},
	{"PE_PanelScrollAreaCorner", QStyle::PE_PanelScrollAreaCorner},
	{"PE_FrameDockWidget", QStyle::PE_FrameDockWidget},
	{"PE_FrameTabWidget", QStyle::PE_FrameTabWidget},
	{"PE_FrameLineEdit", QStyle::PE_FrameLineEdit},
	{"PE_FrameGroupBox", QStyle::PE_FrameGroupBox},
	{"PE_FrameButtonBevel", QStyle::PE_FrameButtonBevel},
	{"PE_FrameButtonTool", QStyle::PE_FrameButtonTool},
	{"PE_IndicatorHeaderArrow", QStyle::PE_IndicatorHeaderArrow},
	{"PE_FrameStatusBarItem", QStyle::PE_FrameStatusBarItem},
	{"PE_FrameWindow", QStyle::PE_FrameWindow},
	{"PE_Q3Separator", QStyle::PE_Q3Separator},
	{"PE_IndicatorMenuCheckMark", QStyle::PE_IndicatorMenuCheckMark},
	{"PE_IndicatorProgressChunk", QStyle::PE_IndicatorProgressChunk},
	{"PE_Q3CheckListController", QStyle::PE_Q3CheckListController},
	{"PE_Q3CheckListIndicator", QStyle::PE_Q3CheckListIndicator},
	{"PE_Q3CheckListExclusiveIndicator", QStyle::PE_Q3CheckListExclusiveIndicator},
	{"PE_IndicatorBranch", QStyle::PE_IndicatorBranch},
	{"PE_IndicatorToolBarHandle", QStyle::PE_IndicatorToolBarHandle},
	{"PE_IndicatorToolBarSeparator", QStyle::PE_IndicatorToolBarSeparator},
	{"PE_PanelToolBar", QStyle::PE_PanelToolBar},
	{"PE_PanelTipLabel", QStyle::PE_PanelTipLabel},
	{"PE_FrameTabBarBase", QStyle::PE_FrameTabBarBase},
	{"PE_IndicatorTabTear", QStyle::PE_IndicatorTabTear},
	{"PE_IndicatorColumnViewArrow", QStyle::PE_IndicatorColumnViewArrow},
	{"PE_Widget", QStyle::PE_Widget},
	{"PE_CustomBase", QStyle::PE_CustomBase},
	{"PE_IndicatorItemViewItemDrop", QStyle::PE_IndicatorItemViewItemDrop},
	{"PE_PanelItemViewItem", QStyle::PE_PanelItemViewItem},
	{"PE_PanelItemViewRow", QStyle::PE_PanelItemViewRow},
	{"PE_PanelStatusBar", QStyle::PE_PanelStatusBar},
	{"PE_IndicatorTabClose", QStyle::PE_IndicatorTabClose},
	{"PE_PanelMenu", QStyle::PE_PanelMenu},
	{"RSIP_OnMouseClickAndAlreadyFocused", QStyle::RSIP_OnMouseClickAndAlreadyFocused},
	{"RSIP_OnMouseClick", QStyle::RSIP_OnMouseClick},
	{"SP_TitleBarMinButton", QStyle::SP_TitleBarMinButton},
	{"SP_TitleBarMenuButton", QStyle::SP_TitleBarMenuButton},
	{"SP_TitleBarMaxButton", QStyle::SP_TitleBarMaxButton},
	{"SP_TitleBarCloseButton", QStyle::SP_TitleBarCloseButton},
	{"SP_TitleBarNormalButton", QStyle::SP_TitleBarNormalButton},
	{"SP_TitleBarShadeButton", QStyle::SP_TitleBarShadeButton},
	{"SP_TitleBarUnshadeButton", QStyle::SP_TitleBarUnshadeButton},
	{"SP_TitleBarContextHelpButton", QStyle::SP_TitleBarContextHelpButton},
	{"SP_MessageBoxInformation", QStyle::SP_MessageBoxInformation},
	{"SP_MessageBoxWarning", QStyle::SP_MessageBoxWarning},
	{"SP_MessageBoxCritical", QStyle::SP_MessageBoxCritical},
	{"SP_MessageBoxQuestion", QStyle::SP_MessageBoxQuestion},
	{"SP_DesktopIcon", QStyle::SP_DesktopIcon},
	{"SP_TrashIcon", QStyle::SP_TrashIcon},
	{"SP_ComputerIcon", QStyle::SP_ComputerIcon},
	{"SP_DriveFDIcon", QStyle::SP_DriveFDIcon},
	{"SP_DriveHDIcon", QStyle::SP_DriveHDIcon},
	{"SP_DriveCDIcon", QStyle::SP_DriveCDIcon},
	{"SP_DriveDVDIcon", QStyle::SP_DriveDVDIcon},
	{"SP_DriveNetIcon", QStyle::SP_DriveNetIcon},
	{"SP_DirHomeIcon", QStyle::SP_DirHomeIcon},
	{"SP_DirOpenIcon", QStyle::SP_DirOpenIcon},
	{"SP_DirClosedIcon", QStyle::SP_DirClosedIcon},
	{"SP_DirIcon", QStyle::SP_DirIcon},
	{"SP_DirLinkIcon", QStyle::SP_DirLinkIcon},
	{"SP_FileIcon", QStyle::SP_FileIcon},
	{"SP_FileLinkIcon", QStyle::SP_FileLinkIcon},
	{"SP_FileDialogStart", QStyle::SP_FileDialogStart},
	{"SP_FileDialogEnd", QStyle::SP_FileDialogEnd},
	{"SP_FileDialogToParent", QStyle::SP_FileDialogToParent},
	{"SP_FileDialogNewFolder", QStyle::SP_FileDialogNewFolder},
	{"SP_FileDialogDetailedView", QStyle::SP_FileDialogDetailedView},
	{"SP_FileDialogInfoView", QStyle::SP_FileDialogInfoView},
	{"SP_FileDialogContentsView", QStyle::SP_FileDialogContentsView},
	{"SP_FileDialogListView", QStyle::SP_FileDialogListView},
	{"SP_FileDialogBack", QStyle::SP_FileDialogBack},
	{"SP_DockWidgetCloseButton", QStyle::SP_DockWidgetCloseButton},
	{"SP_ToolBarHorizontalExtensionButton", QStyle::SP_ToolBarHorizontalExtensionButton},
	{"SP_ToolBarVerticalExtensionButton", QStyle::SP_ToolBarVerticalExtensionButton},
	{"SP_DialogOkButton", QStyle::SP_DialogOkButton},
	{"SP_DialogCancelButton", QStyle::SP_DialogCancelButton},
	{"SP_DialogHelpButton", QStyle::SP_DialogHelpButton},
	{"SP_DialogOpenButton", QStyle::SP_DialogOpenButton},
	{"SP_DialogSaveButton", QStyle::SP_DialogSaveButton},
	{"SP_DialogCloseButton", QStyle::SP_DialogCloseButton},
	{"SP_DialogApplyButton", QStyle::SP_DialogApplyButton},
	{"SP_DialogResetButton", QStyle::SP_DialogResetButton},
	{"SP_DialogDiscardButton", QStyle::SP_DialogDiscardButton},
	{"SP_DialogYesButton", QStyle::SP_DialogYesButton},
	{"SP_DialogNoButton", QStyle::SP_DialogNoButton},
	{"SP_ArrowUp", QStyle::SP_ArrowUp},
	{"SP_ArrowDown", QStyle::SP_ArrowDown},
	{"SP_ArrowLeft", QStyle::SP_ArrowLeft},
	{"SP_ArrowRight", QStyle::SP_ArrowRight},
	{"SP_ArrowBack", QStyle::SP_ArrowBack},
	{"SP_ArrowForward", QStyle::SP_ArrowForward},
	{"SP_CommandLink", QStyle::SP_CommandLink},
	{"SP_VistaShield", QStyle::SP_VistaShield},
	{"SP_BrowserReload", QStyle::SP_BrowserReload},
	{"SP_BrowserStop", QStyle::SP_BrowserStop},
	{"SP_MediaPlay", QStyle::SP_MediaPlay},
	{"SP_MediaStop", QStyle::SP_MediaStop},
	{"SP_MediaPause", QStyle::SP_MediaPause},
	{"SP_MediaSkipForward", QStyle::SP_MediaSkipForward},
	{"SP_MediaSkipBackward", QStyle::SP_MediaSkipBackward},
	{"SP_MediaSeekForward", QStyle::SP_MediaSeekForward},
	{"SP_MediaSeekBackward", QStyle::SP_MediaSeekBackward},
	{"SP_MediaVolume", QStyle::SP_MediaVolume},
	{"SP_MediaVolumeMuted", QStyle::SP_MediaVolumeMuted},
	{"SP_CustomBase", QStyle::SP_CustomBase},
	{"State_None", QStyle::State_None},
	{"State_Active", QStyle::State_Active},
	{"State_AutoRaise", QStyle::State_AutoRaise},
	{"State_Children", QStyle::State_Children},
	{"State_DownArrow", QStyle::State_DownArrow},
	{"State_Editing", QStyle::State_Editing},
	{"State_Enabled", QStyle::State_Enabled},
//	{"State_HasEditFocus", QStyle::State_HasEditFocus},
	{"State_HasFocus", QStyle::State_HasFocus},
	{"State_Horizontal", QStyle::State_Horizontal},
	{"State_KeyboardFocusChange", QStyle::State_KeyboardFocusChange},
	{"State_MouseOver", QStyle::State_MouseOver},
	{"State_NoChange", QStyle::State_NoChange},
	{"State_Off", QStyle::State_Off},
	{"State_On", QStyle::State_On},
	{"State_Raised", QStyle::State_Raised},
	{"State_ReadOnly", QStyle::State_ReadOnly},
	{"State_Selected", QStyle::State_Selected},
	{"State_Item", QStyle::State_Item},
	{"State_Open", QStyle::State_Open},
	{"State_Sibling", QStyle::State_Sibling},
	{"State_Sunken", QStyle::State_Sunken},
	{"State_UpArrow", QStyle::State_UpArrow},
	{"State_Mini", QStyle::State_Mini},
	{"State_Small", QStyle::State_Small},
	{"SH_EtchDisabledText", QStyle::SH_EtchDisabledText},
	{"SH_DitherDisabledText", QStyle::SH_DitherDisabledText},
//	{"SH_GUIStyle", QStyle::SH_GUIStyle},
	{"SH_ScrollBar_ContextMenu", QStyle::SH_ScrollBar_ContextMenu},
	{"SH_ScrollBar_MiddleClickAbsolutePosition", QStyle::SH_ScrollBar_MiddleClickAbsolutePosition},
	{"SH_ScrollBar_LeftClickAbsolutePosition", QStyle::SH_ScrollBar_LeftClickAbsolutePosition},
	{"SH_ScrollBar_ScrollWhenPointerLeavesControl", QStyle::SH_ScrollBar_ScrollWhenPointerLeavesControl},
	{"SH_ScrollBar_RollBetweenButtons", QStyle::SH_ScrollBar_RollBetweenButtons},
	{"SH_TabBar_Alignment", QStyle::SH_TabBar_Alignment},
	{"SH_Header_ArrowAlignment", QStyle::SH_Header_ArrowAlignment},
	{"SH_Slider_SnapToValue", QStyle::SH_Slider_SnapToValue},
	{"SH_Slider_SloppyKeyEvents", QStyle::SH_Slider_SloppyKeyEvents},
	{"SH_ProgressDialog_CenterCancelButton", QStyle::SH_ProgressDialog_CenterCancelButton},
	{"SH_ProgressDialog_TextLabelAlignment", QStyle::SH_ProgressDialog_TextLabelAlignment},
	{"SH_PrintDialog_RightAlignButtons", QStyle::SH_PrintDialog_RightAlignButtons},
	{"SH_MainWindow_SpaceBelowMenuBar", QStyle::SH_MainWindow_SpaceBelowMenuBar},
	{"SH_FontDialog_SelectAssociatedText", QStyle::SH_FontDialog_SelectAssociatedText},
	{"SH_Menu_KeyboardSearch", QStyle::SH_Menu_KeyboardSearch},
	{"SH_Menu_AllowActiveAndDisabled", QStyle::SH_Menu_AllowActiveAndDisabled},
	{"SH_Menu_SpaceActivatesItem", QStyle::SH_Menu_SpaceActivatesItem},
	{"SH_Menu_SubMenuPopupDelay", QStyle::SH_Menu_SubMenuPopupDelay},
	{"SH_Menu_Scrollable", QStyle::SH_Menu_Scrollable},
	{"SH_Menu_SloppySubMenus", QStyle::SH_Menu_SloppySubMenus},
	{"SH_ScrollView_FrameOnlyAroundContents", QStyle::SH_ScrollView_FrameOnlyAroundContents},
	{"SH_MenuBar_AltKeyNavigation", QStyle::SH_MenuBar_AltKeyNavigation},
	{"SH_ComboBox_ListMouseTracking", QStyle::SH_ComboBox_ListMouseTracking},
	{"SH_Menu_MouseTracking", QStyle::SH_Menu_MouseTracking},
	{"SH_MenuBar_MouseTracking", QStyle::SH_MenuBar_MouseTracking},
	{"SH_Menu_FillScreenWithScroll", QStyle::SH_Menu_FillScreenWithScroll},
	{"SH_Menu_SelectionWrap", QStyle::SH_Menu_SelectionWrap},
	{"SH_ItemView_ChangeHighlightOnFocus", QStyle::SH_ItemView_ChangeHighlightOnFocus},
	{"SH_Widget_ShareActivation", QStyle::SH_Widget_ShareActivation},
	{"SH_TabBar_SelectMouseType", QStyle::SH_TabBar_SelectMouseType},
	{"SH_Q3ListViewExpand_SelectMouseType", QStyle::SH_Q3ListViewExpand_SelectMouseType},
	{"SH_TabBar_PreferNoArrows", QStyle::SH_TabBar_PreferNoArrows},
	{"SH_ComboBox_Popup", QStyle::SH_ComboBox_Popup},
	{"SH_Workspace_FillSpaceOnMaximize", QStyle::SH_Workspace_FillSpaceOnMaximize},
	{"SH_TitleBar_NoBorder", QStyle::SH_TitleBar_NoBorder},
	{"SH_ScrollBar_StopMouseOverSlider", QStyle::SH_ScrollBar_StopMouseOverSlider},
	{"SH_Slider_StopMouseOverSlider", QStyle::SH_Slider_StopMouseOverSlider},
	{"SH_BlinkCursorWhenTextSelected", QStyle::SH_BlinkCursorWhenTextSelected},
	{"SH_RichText_FullWidthSelection", QStyle::SH_RichText_FullWidthSelection},
	{"SH_GroupBox_TextLabelVerticalAlignment", QStyle::SH_GroupBox_TextLabelVerticalAlignment},
	{"SH_GroupBox_TextLabelColor", QStyle::SH_GroupBox_TextLabelColor},
	{"SH_DialogButtons_DefaultButton", QStyle::SH_DialogButtons_DefaultButton},
	{"SH_ToolBox_SelectedPageTitleBold", QStyle::SH_ToolBox_SelectedPageTitleBold},
	{"SH_LineEdit_PasswordCharacter", QStyle::SH_LineEdit_PasswordCharacter},
	{"SH_Table_GridLineColor", QStyle::SH_Table_GridLineColor},
	{"SH_UnderlineShortcut", QStyle::SH_UnderlineShortcut},
	{"SH_SpellCheckUnderlineStyle", QStyle::SH_SpellCheckUnderlineStyle},
	{"SH_SpinBox_AnimateButton", QStyle::SH_SpinBox_AnimateButton},
	{"SH_SpinBox_KeyPressAutoRepeatRate", QStyle::SH_SpinBox_KeyPressAutoRepeatRate},
	{"SH_SpinBox_ClickAutoRepeatRate", QStyle::SH_SpinBox_ClickAutoRepeatRate},
	{"SH_SpinBox_ClickAutoRepeatThreshold", QStyle::SH_SpinBox_ClickAutoRepeatThreshold},
	{"SH_ToolTipLabel_Opacity", QStyle::SH_ToolTipLabel_Opacity},
	{"SH_DrawMenuBarSeparator", QStyle::SH_DrawMenuBarSeparator},
	{"SH_TitleBar_ModifyNotification", QStyle::SH_TitleBar_ModifyNotification},
	{"SH_Button_FocusPolicy", QStyle::SH_Button_FocusPolicy},
	{"SH_CustomBase", QStyle::SH_CustomBase},
	{"SH_MenuBar_DismissOnSecondClick", QStyle::SH_MenuBar_DismissOnSecondClick},
	{"SH_MessageBox_UseBorderForButtonSpacing", QStyle::SH_MessageBox_UseBorderForButtonSpacing},
	{"SH_MessageBox_CenterButtons", QStyle::SH_MessageBox_CenterButtons},
	{"SH_MessageBox_TextInteractionFlags", QStyle::SH_MessageBox_TextInteractionFlags},
	{"SH_TitleBar_AutoRaise", QStyle::SH_TitleBar_AutoRaise},
	{"SH_ToolButton_PopupDelay", QStyle::SH_ToolButton_PopupDelay},
	{"SH_FocusFrame_Mask", QStyle::SH_FocusFrame_Mask},
	{"SH_RubberBand_Mask", QStyle::SH_RubberBand_Mask},
	{"SH_WindowFrame_Mask", QStyle::SH_WindowFrame_Mask},
	{"SH_SpinControls_DisableOnBounds", QStyle::SH_SpinControls_DisableOnBounds},
	{"SH_Dial_BackgroundRole", QStyle::SH_Dial_BackgroundRole},
//	{"SH_ScrollBar_BackgroundMode", QStyle::SH_ScrollBar_BackgroundMode},
	{"SH_ComboBox_LayoutDirection", QStyle::SH_ComboBox_LayoutDirection},
	{"SH_ItemView_EllipsisLocation", QStyle::SH_ItemView_EllipsisLocation},
	{"SH_ItemView_ShowDecorationSelected", QStyle::SH_ItemView_ShowDecorationSelected},
	{"SH_ItemView_ActivateItemOnSingleClick", QStyle::SH_ItemView_ActivateItemOnSingleClick},
	{"SH_Slider_AbsoluteSetButtons", QStyle::SH_Slider_AbsoluteSetButtons},
	{"SH_Slider_PageSetButtons", QStyle::SH_Slider_PageSetButtons},
	{"SH_TabBar_ElideMode", QStyle::SH_TabBar_ElideMode},
	{"SH_DialogButtonLayout", QStyle::SH_DialogButtonLayout},
	{"SH_WizardStyle", QStyle::SH_WizardStyle},
	{"SH_FormLayoutWrapPolicy", QStyle::SH_FormLayoutWrapPolicy},
	{"SH_FormLayoutFieldGrowthPolicy", QStyle::SH_FormLayoutFieldGrowthPolicy},
	{"SH_FormLayoutFormAlignment", QStyle::SH_FormLayoutFormAlignment},
	{"SH_FormLayoutLabelAlignment", QStyle::SH_FormLayoutLabelAlignment},
	{"SH_ItemView_ArrowKeysNavigateIntoChildren", QStyle::SH_ItemView_ArrowKeysNavigateIntoChildren},
	{"SH_ComboBox_PopupFrameStyle", QStyle::SH_ComboBox_PopupFrameStyle},
	{"SH_DialogButtonBox_ButtonsHaveIcons", QStyle::SH_DialogButtonBox_ButtonsHaveIcons},
	{"SH_ItemView_MovementWithoutUpdatingSelection", QStyle::SH_ItemView_MovementWithoutUpdatingSelection},
	{"SH_ToolTip_Mask", QStyle::SH_ToolTip_Mask},
	{"SH_FocusFrame_AboveWidget", QStyle::SH_FocusFrame_AboveWidget},
	{"SH_TextControl_FocusIndicatorTextCharFormat", QStyle::SH_TextControl_FocusIndicatorTextCharFormat},
	{"SH_Menu_FlashTriggeredItem", QStyle::SH_Menu_FlashTriggeredItem},
	{"SH_Menu_FadeOutOnHide", QStyle::SH_Menu_FadeOutOnHide},
	{"SH_TabWidget_DefaultTabPosition", QStyle::SH_TabWidget_DefaultTabPosition},
	{"SH_ToolBar_Movable", QStyle::SH_ToolBar_Movable},
	{"SH_ItemView_PaintAlternatingRowColorsForEmptyArea", QStyle::SH_ItemView_PaintAlternatingRowColorsForEmptyArea},
	{"SH_Menu_Mask", QStyle::SH_Menu_Mask},
	{"SH_ItemView_DrawDelegateFrame", QStyle::SH_ItemView_DrawDelegateFrame},
	{"SH_TabBar_CloseButtonPosition", QStyle::SH_TabBar_CloseButtonPosition},
	{"SH_DockWidget_ButtonsHaveFrame", QStyle::SH_DockWidget_ButtonsHaveFrame},
	{"SH_ToolButtonStyle", QStyle::SH_ToolButtonStyle},
	{"SH_RequestSoftwareInputPanel", QStyle::SH_RequestSoftwareInputPanel},
	{"SC_None", QStyle::SC_None},
	{"SC_ScrollBarAddLine", QStyle::SC_ScrollBarAddLine},
	{"SC_ScrollBarSubLine", QStyle::SC_ScrollBarSubLine},
	{"SC_ScrollBarAddPage", QStyle::SC_ScrollBarAddPage},
	{"SC_ScrollBarSubPage", QStyle::SC_ScrollBarSubPage},
	{"SC_ScrollBarFirst", QStyle::SC_ScrollBarFirst},
	{"SC_ScrollBarLast", QStyle::SC_ScrollBarLast},
	{"SC_ScrollBarSlider", QStyle::SC_ScrollBarSlider},
	{"SC_ScrollBarGroove", QStyle::SC_ScrollBarGroove},
	{"SC_SpinBoxUp", QStyle::SC_SpinBoxUp},
	{"SC_SpinBoxDown", QStyle::SC_SpinBoxDown},
	{"SC_SpinBoxFrame", QStyle::SC_SpinBoxFrame},
	{"SC_SpinBoxEditField", QStyle::SC_SpinBoxEditField},
	{"SC_ComboBoxEditField", QStyle::SC_ComboBoxEditField},
	{"SC_ComboBoxArrow", QStyle::SC_ComboBoxArrow},
	{"SC_ComboBoxFrame", QStyle::SC_ComboBoxFrame},
	{"SC_ComboBoxListBoxPopup", QStyle::SC_ComboBoxListBoxPopup},
	{"SC_SliderGroove", QStyle::SC_SliderGroove},
	{"SC_SliderHandle", QStyle::SC_SliderHandle},
	{"SC_SliderTickmarks", QStyle::SC_SliderTickmarks},
	{"SC_ToolButton", QStyle::SC_ToolButton},
	{"SC_ToolButtonMenu", QStyle::SC_ToolButtonMenu},
	{"SC_TitleBarSysMenu", QStyle::SC_TitleBarSysMenu},
	{"SC_TitleBarMinButton", QStyle::SC_TitleBarMinButton},
	{"SC_TitleBarMaxButton", QStyle::SC_TitleBarMaxButton},
	{"SC_TitleBarCloseButton", QStyle::SC_TitleBarCloseButton},
	{"SC_TitleBarLabel", QStyle::SC_TitleBarLabel},
	{"SC_TitleBarNormalButton", QStyle::SC_TitleBarNormalButton},
	{"SC_TitleBarShadeButton", QStyle::SC_TitleBarShadeButton},
	{"SC_TitleBarUnshadeButton", QStyle::SC_TitleBarUnshadeButton},
	{"SC_TitleBarContextHelpButton", QStyle::SC_TitleBarContextHelpButton},
	{"SC_Q3ListView", QStyle::SC_Q3ListView},
	{"SC_Q3ListViewExpand", QStyle::SC_Q3ListViewExpand},
	{"SC_DialHandle", QStyle::SC_DialHandle},
	{"SC_DialGroove", QStyle::SC_DialGroove},
	{"SC_DialTickmarks", QStyle::SC_DialTickmarks},
	{"SC_GroupBoxFrame", QStyle::SC_GroupBoxFrame},
	{"SC_GroupBoxLabel", QStyle::SC_GroupBoxLabel},
	{"SC_GroupBoxCheckBox", QStyle::SC_GroupBoxCheckBox},
	{"SC_GroupBoxContents", QStyle::SC_GroupBoxContents},
	{"SC_MdiNormalButton", QStyle::SC_MdiNormalButton},
	{"SC_MdiMinButton", QStyle::SC_MdiMinButton},
	{"SC_MdiCloseButton", QStyle::SC_MdiCloseButton},
	{"SC_All", QStyle::SC_All},
	{"SE_PushButtonContents", QStyle::SE_PushButtonContents},
	{"SE_PushButtonFocusRect", QStyle::SE_PushButtonFocusRect},
	{"SE_PushButtonLayoutItem", QStyle::SE_PushButtonLayoutItem},
	{"SE_CheckBoxIndicator", QStyle::SE_CheckBoxIndicator},
	{"SE_CheckBoxContents", QStyle::SE_CheckBoxContents},
	{"SE_CheckBoxFocusRect", QStyle::SE_CheckBoxFocusRect},
	{"SE_CheckBoxClickRect", QStyle::SE_CheckBoxClickRect},
	{"SE_CheckBoxLayoutItem", QStyle::SE_CheckBoxLayoutItem},
	{"SE_DateTimeEditLayoutItem", QStyle::SE_DateTimeEditLayoutItem},
	{"SE_RadioButtonIndicator", QStyle::SE_RadioButtonIndicator},
	{"SE_RadioButtonContents", QStyle::SE_RadioButtonContents},
	{"SE_RadioButtonFocusRect", QStyle::SE_RadioButtonFocusRect},
	{"SE_RadioButtonClickRect", QStyle::SE_RadioButtonClickRect},
	{"SE_RadioButtonLayoutItem", QStyle::SE_RadioButtonLayoutItem},
	{"SE_ComboBoxFocusRect", QStyle::SE_ComboBoxFocusRect},
	{"SE_SliderFocusRect", QStyle::SE_SliderFocusRect},
	{"SE_SliderLayoutItem", QStyle::SE_SliderLayoutItem},
	{"SE_SpinBoxLayoutItem", QStyle::SE_SpinBoxLayoutItem},
	{"SE_Q3DockWindowHandleRect", QStyle::SE_Q3DockWindowHandleRect},
	{"SE_ProgressBarGroove", QStyle::SE_ProgressBarGroove},
	{"SE_ProgressBarContents", QStyle::SE_ProgressBarContents},
	{"SE_ProgressBarLabel", QStyle::SE_ProgressBarLabel},
	{"SE_ProgressBarLayoutItem", QStyle::SE_ProgressBarLayoutItem},
	{"SE_FrameContents", QStyle::SE_FrameContents},
	{"SE_ShapedFrameContents", QStyle::SE_ShapedFrameContents},
	{"SE_FrameLayoutItem", QStyle::SE_FrameLayoutItem},
	{"SE_HeaderArrow", QStyle::SE_HeaderArrow},
	{"SE_HeaderLabel", QStyle::SE_HeaderLabel},
	{"SE_LabelLayoutItem", QStyle::SE_LabelLayoutItem},
	{"SE_LineEditContents", QStyle::SE_LineEditContents},
	{"SE_TabWidgetLeftCorner", QStyle::SE_TabWidgetLeftCorner},
	{"SE_TabWidgetRightCorner", QStyle::SE_TabWidgetRightCorner},
	{"SE_TabWidgetTabBar", QStyle::SE_TabWidgetTabBar},
	{"SE_TabWidgetTabContents", QStyle::SE_TabWidgetTabContents},
	{"SE_TabWidgetTabPane", QStyle::SE_TabWidgetTabPane},
	{"SE_TabWidgetLayoutItem", QStyle::SE_TabWidgetLayoutItem},
	{"SE_ToolBoxTabContents", QStyle::SE_ToolBoxTabContents},
	{"SE_ToolButtonLayoutItem", QStyle::SE_ToolButtonLayoutItem},
	{"SE_ItemViewItemCheckIndicator", QStyle::SE_ItemViewItemCheckIndicator},
	{"SE_TabBarTearIndicator", QStyle::SE_TabBarTearIndicator},
	{"SE_TreeViewDisclosureItem", QStyle::SE_TreeViewDisclosureItem},
	{"SE_DialogButtonBoxLayoutItem", QStyle::SE_DialogButtonBoxLayoutItem},
	{"SE_GroupBoxLayoutItem", QStyle::SE_GroupBoxLayoutItem},
	{"SE_CustomBase", QStyle::SE_CustomBase},
	{"SE_DockWidgetFloatButton", QStyle::SE_DockWidgetFloatButton},
	{"SE_DockWidgetTitleBarText", QStyle::SE_DockWidgetTitleBarText},
	{"SE_DockWidgetCloseButton", QStyle::SE_DockWidgetCloseButton},
	{"SE_DockWidgetIcon", QStyle::SE_DockWidgetIcon},
	{"SE_ComboBoxLayoutItem", QStyle::SE_ComboBoxLayoutItem},
	{"SE_ItemViewItemDecoration", QStyle::SE_ItemViewItemDecoration},
	{"SE_ItemViewItemText", QStyle::SE_ItemViewItemText},
	{"SE_ItemViewItemFocusRect", QStyle::SE_ItemViewItemFocusRect},
	{"SE_TabBarTabLeftButton", QStyle::SE_TabBarTabLeftButton},
	{"SE_TabBarTabRightButton", QStyle::SE_TabBarTabRightButton},
	{"SE_TabBarTabText", QStyle::SE_TabBarTabText},
	{"SE_ToolBarHandle", QStyle::SE_ToolBarHandle},
	{NULL, 0}
};

DEFAPI(void) constQStyle(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleConstInt);
}


DEFAPI(void) defQStyle(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyle";
	cdef->free = QStyle_free;
	cdef->reftrace = QStyle_reftrace;
	cdef->compareTo = QStyle_compareTo;
}

//## QStyleState QStyleState.new(int value);
KMETHOD QStyleState_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyle::StateFlag i = Int_to(QStyle::StateFlag, sfp[1]);
	QStyle::State *ret_v = new QStyle::State(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QStyleState QStyleState.and(int mask);
KMETHOD QStyleState_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyle::State *qp = RawPtr_to(QStyle::State*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QStyle::State ret = ((*qp) & i);
		QStyle::State *ret_ = new QStyle::State(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleState QStyleState.iand(QStyle::QStyleState other);
KMETHOD QStyleState_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyle::State *qp = RawPtr_to(QStyle::State*, sfp[0]);
	if (qp != NULL) {
		QStyle::State *other = RawPtr_to(QStyle::State *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleState QStyleState.or(QStyleState f);
KMETHOD QStyleState_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle::State *qp = RawPtr_to(QStyle::State*, sfp[0]);
	if (qp != NULL) {
		QStyle::State *f = RawPtr_to(QStyle::State*, sfp[1]);
		QStyle::State ret = ((*qp) | (*f));
		QStyle::State *ret_ = new QStyle::State(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleState QStyleState.ior(QStyle::QStyleState other);
KMETHOD QStyleState_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyle::State *qp = RawPtr_to(QStyle::State*, sfp[0]);
	if (qp != NULL) {
		QStyle::State *other = RawPtr_to(QStyle::State *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleState QStyleState.xor(QStyleState f);
KMETHOD QStyleState_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle::State *qp = RawPtr_to(QStyle::State*, sfp[0]);
	if (qp != NULL) {
		QStyle::State *f = RawPtr_to(QStyle::State*, sfp[1]);
		QStyle::State ret = ((*qp) ^ (*f));
		QStyle::State *ret_ = new QStyle::State(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleState QStyleState.ixor(QStyle::QStyleState other);
KMETHOD QStyleState_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyle::State *qp = RawPtr_to(QStyle::State*, sfp[0]);
	if (qp != NULL) {
		QStyle::State *other = RawPtr_to(QStyle::State *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QStyleState.testFlag(int flag);
KMETHOD QStyleState_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyle::State *qp = RawPtr_to(QStyle::State *, sfp[0]);
	if (qp != NULL) {
		QStyle::StateFlag flag = Int_to(QStyle::StateFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QStyleState.value();
KMETHOD QStyleState_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyle::State *qp = RawPtr_to(QStyle::State *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QStyleState_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QStyle::State *qp = (QStyle::State *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QStyleState_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QStyle::State *qp = (QStyle::State *)p->rawptr;
		(void)qp;
	}
}

static int QStyleState_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QStyle::State*)p1->rawptr);
//		int v2 = int(*(QStyle::State*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QStyle::State v1 = *(QStyle::State*)p1->rawptr;
		QStyle::State v2 = *(QStyle::State*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQStyleState(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleState";
	cdef->free = QStyleState_free;
	cdef->reftrace = QStyleState_reftrace;
	cdef->compareTo = QStyleState_compareTo;
}
//## QStyleSubControls QStyleSubControls.new(int value);
KMETHOD QStyleSubControls_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyle::SubControl i = Int_to(QStyle::SubControl, sfp[1]);
	QStyle::SubControls *ret_v = new QStyle::SubControls(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QStyleSubControls QStyleSubControls.and(int mask);
KMETHOD QStyleSubControls_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyle::SubControls *qp = RawPtr_to(QStyle::SubControls*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QStyle::SubControls ret = ((*qp) & i);
		QStyle::SubControls *ret_ = new QStyle::SubControls(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleSubControls QStyleSubControls.iand(QStyle::QStyleSubControls other);
KMETHOD QStyleSubControls_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyle::SubControls *qp = RawPtr_to(QStyle::SubControls*, sfp[0]);
	if (qp != NULL) {
		QStyle::SubControls *other = RawPtr_to(QStyle::SubControls *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleSubControls QStyleSubControls.or(QStyleSubControls f);
KMETHOD QStyleSubControls_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle::SubControls *qp = RawPtr_to(QStyle::SubControls*, sfp[0]);
	if (qp != NULL) {
		QStyle::SubControls *f = RawPtr_to(QStyle::SubControls*, sfp[1]);
		QStyle::SubControls ret = ((*qp) | (*f));
		QStyle::SubControls *ret_ = new QStyle::SubControls(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleSubControls QStyleSubControls.ior(QStyle::QStyleSubControls other);
KMETHOD QStyleSubControls_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyle::SubControls *qp = RawPtr_to(QStyle::SubControls*, sfp[0]);
	if (qp != NULL) {
		QStyle::SubControls *other = RawPtr_to(QStyle::SubControls *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleSubControls QStyleSubControls.xor(QStyleSubControls f);
KMETHOD QStyleSubControls_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyle::SubControls *qp = RawPtr_to(QStyle::SubControls*, sfp[0]);
	if (qp != NULL) {
		QStyle::SubControls *f = RawPtr_to(QStyle::SubControls*, sfp[1]);
		QStyle::SubControls ret = ((*qp) ^ (*f));
		QStyle::SubControls *ret_ = new QStyle::SubControls(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleSubControls QStyleSubControls.ixor(QStyle::QStyleSubControls other);
KMETHOD QStyleSubControls_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyle::SubControls *qp = RawPtr_to(QStyle::SubControls*, sfp[0]);
	if (qp != NULL) {
		QStyle::SubControls *other = RawPtr_to(QStyle::SubControls *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QStyleSubControls.testFlag(int flag);
KMETHOD QStyleSubControls_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyle::SubControls *qp = RawPtr_to(QStyle::SubControls *, sfp[0]);
	if (qp != NULL) {
		QStyle::SubControl flag = Int_to(QStyle::SubControl, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QStyleSubControls.value();
KMETHOD QStyleSubControls_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyle::SubControls *qp = RawPtr_to(QStyle::SubControls *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QStyleSubControls_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QStyle::SubControls *qp = (QStyle::SubControls *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QStyleSubControls_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QStyle::SubControls *qp = (QStyle::SubControls *)p->rawptr;
		(void)qp;
	}
}

static int QStyleSubControls_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QStyle::SubControls*)p1->rawptr);
//		int v2 = int(*(QStyle::SubControls*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QStyle::SubControls v1 = *(QStyle::SubControls*)p1->rawptr;
		QStyle::SubControls v2 = *(QStyle::SubControls*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQStyleSubControls(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleSubControls";
	cdef->free = QStyleSubControls_free;
	cdef->reftrace = QStyleSubControls_reftrace;
	cdef->compareTo = QStyleSubControls_compareTo;
}

