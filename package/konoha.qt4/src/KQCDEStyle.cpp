//@Virtual @Override void QCDEStyle.drawControl(int element, QStyleOption opt, QPainter p, QWidget widget);
KMETHOD QCDEStyle_drawControl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCDEStyle *  qp = RawPtr_to(QCDEStyle *, sfp[0]);
	if (qp != NULL) {
		QCDEStyle::ControlElement element = Int_to(QCDEStyle::ControlElement, sfp[1]);
		const QStyleOption*  opt = RawPtr_to(const QStyleOption*, sfp[2]);
		QPainter*  p = RawPtr_to(QPainter*, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		qp->drawControl(element, opt, p, widget);
	}
	RETURNvoid_();
}

//@Virtual @Override void QCDEStyle.drawPrimitive(int pe, QStyleOption opt, QPainter p, QWidget widget);
KMETHOD QCDEStyle_drawPrimitive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCDEStyle *  qp = RawPtr_to(QCDEStyle *, sfp[0]);
	if (qp != NULL) {
		QCDEStyle::PrimitiveElement pe = Int_to(QCDEStyle::PrimitiveElement, sfp[1]);
		const QStyleOption*  opt = RawPtr_to(const QStyleOption*, sfp[2]);
		QPainter*  p = RawPtr_to(QPainter*, sfp[3]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[4]);
		qp->drawPrimitive(pe, opt, p, widget);
	}
	RETURNvoid_();
}

//@Virtual @Override int QCDEStyle.pixelMetric(int metric, QStyleOption option, QWidget widget);
KMETHOD QCDEStyle_pixelMetric(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCDEStyle *  qp = RawPtr_to(QCDEStyle *, sfp[0]);
	if (qp != NULL) {
		QCDEStyle::PixelMetric metric = Int_to(QCDEStyle::PixelMetric, sfp[1]);
		const QStyleOption*  option = RawPtr_to(const QStyleOption*, sfp[2]);
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[3]);
		int ret_v = qp->pixelMetric(metric, option, widget);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QPalette QCDEStyle.standardPalette();
KMETHOD QCDEStyle_standardPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCDEStyle *  qp = RawPtr_to(QCDEStyle *, sfp[0]);
	if (qp != NULL) {
		QPalette ret_v = qp->standardPalette();
		QPalette *ret_v_ = new QPalette(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QCDEStyle QCDEStyle.new(boolean useHighlightCols);
KMETHOD QCDEStyle_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	bool useHighlightCols = Boolean_to(bool, sfp[1]);
	KQCDEStyle *ret_v = new KQCDEStyle(useHighlightCols);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}


DummyQCDEStyle::DummyQCDEStyle()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQCDEStyle::setSelf(knh_RawPtr_t *ptr)
{
	DummyQCDEStyle::self = ptr;
	DummyQMotifStyle::setSelf(ptr);
}

bool DummyQCDEStyle::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQMotifStyle::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQCDEStyle::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCDEStyle::event_map->bigin();
	if ((itr = DummyQCDEStyle::event_map->find(str)) == DummyQCDEStyle::event_map->end()) {
		bool ret;
		ret = DummyQMotifStyle::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQCDEStyle::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCDEStyle::slot_map->bigin();
	if ((itr = DummyQCDEStyle::event_map->find(str)) == DummyQCDEStyle::slot_map->end()) {
		bool ret;
		ret = DummyQMotifStyle::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQCDEStyle::KQCDEStyle(bool useHighlightCols) : QCDEStyle(useHighlightCols)
{
	self = NULL;
}

KMETHOD QCDEStyle_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCDEStyle *qp = RawPtr_to(KQCDEStyle *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QCDEStyle]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQCDEStyle::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCDEStyle]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QCDEStyle_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCDEStyle *qp = RawPtr_to(KQCDEStyle *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QCDEStyle]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQCDEStyle::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCDEStyle]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QCDEStyle_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQCDEStyle *qp = (KQCDEStyle *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QCDEStyle_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQCDEStyle *qp = (KQCDEStyle *)p->rawptr;
		(void)qp;
	}
}

static int QCDEStyle_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQCDEStyle::event(QEvent *event)
{
	if (!DummyQCDEStyle::eventDispatcher(event)) {
		QCDEStyle::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQCDEStyle(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QCDEStyle";
	cdef->free = QCDEStyle_free;
	cdef->reftrace = QCDEStyle_reftrace;
	cdef->compareTo = QCDEStyle_compareTo;
}


