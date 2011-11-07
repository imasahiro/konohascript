//QStylePainter QStylePainter.new();
KMETHOD QStylePainter_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStylePainter *ret_v = new KQStylePainter();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStylePainter QStylePainter.new(QWidget widget);
KMETHOD QStylePainter_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
	KQStylePainter *ret_v = new KQStylePainter(widget);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QStylePainter QStylePainter.new(QPaintDevice pd, QWidget widget);
KMETHOD QStylePainter_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintDevice*  pd = RawPtr_to(QPaintDevice*, sfp[1]);
	QWidget*  widget = RawPtr_to(QWidget*, sfp[2]);
	KQStylePainter *ret_v = new KQStylePainter(pd, widget);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QStylePainter.beginOL(QWidget widget);
KMETHOD QStylePainter_beginOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStylePainter *  qp = RawPtr_to(QStylePainter *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		bool ret_v = qp->begin(widget);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QStylePainter.beginOL(QPaintDevice pd, QWidget widget);
KMETHOD QStylePainter_beginOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStylePainter *  qp = RawPtr_to(QStylePainter *, sfp[0]);
	if (qp) {
		QPaintDevice*  pd = RawPtr_to(QPaintDevice*, sfp[1]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[2]);
		bool ret_v = qp->begin(pd, widget);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//void QStylePainter.drawComplexControl(int cc, QStyleOptionComplex option);
KMETHOD QStylePainter_drawComplexControl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStylePainter *  qp = RawPtr_to(QStylePainter *, sfp[0]);
	if (qp) {
		QStyle::ComplexControl cc = Int_to(QStyle::ComplexControl, sfp[1]);
		const QStyleOptionComplex  option = *RawPtr_to(const QStyleOptionComplex *, sfp[2]);
		qp->drawComplexControl(cc, option);
	}
	RETURNvoid_();
}

//void QStylePainter.drawControl(int ce, QStyleOption option);
KMETHOD QStylePainter_drawControl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStylePainter *  qp = RawPtr_to(QStylePainter *, sfp[0]);
	if (qp) {
		QStyle::ControlElement ce = Int_to(QStyle::ControlElement, sfp[1]);
		const QStyleOption  option = *RawPtr_to(const QStyleOption *, sfp[2]);
		qp->drawControl(ce, option);
	}
	RETURNvoid_();
}

//void QStylePainter.drawItemPixmap(QRect rect, int flags, QPixmap pixmap);
KMETHOD QStylePainter_drawItemPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStylePainter *  qp = RawPtr_to(QStylePainter *, sfp[0]);
	if (qp) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		int flags = Int_to(int, sfp[2]);
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[3]);
		qp->drawItemPixmap(rect, flags, pixmap);
	}
	RETURNvoid_();
}

//void QStylePainter.drawItemText(QRect rect, int flags, QPalette pal, boolean enabled, String text, int textRole);
KMETHOD QStylePainter_drawItemText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStylePainter *  qp = RawPtr_to(QStylePainter *, sfp[0]);
	if (qp) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		int flags = Int_to(int, sfp[2]);
		const QPalette  pal = *RawPtr_to(const QPalette *, sfp[3]);
		bool enabled = Boolean_to(bool, sfp[4]);
		const QString text = String_to(const QString, sfp[5]);
		QPalette::ColorRole textRole = Int_to(QPalette::ColorRole, sfp[6]);
		qp->drawItemText(rect, flags, pal, enabled, text, textRole);
	}
	RETURNvoid_();
}

//void QStylePainter.drawPrimitive(int pe, QStyleOption option);
KMETHOD QStylePainter_drawPrimitive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStylePainter *  qp = RawPtr_to(QStylePainter *, sfp[0]);
	if (qp) {
		QStyle::PrimitiveElement pe = Int_to(QStyle::PrimitiveElement, sfp[1]);
		const QStyleOption  option = *RawPtr_to(const QStyleOption *, sfp[2]);
		qp->drawPrimitive(pe, option);
	}
	RETURNvoid_();
}

//QStyle QStylePainter.style();
KMETHOD QStylePainter_style(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStylePainter *  qp = RawPtr_to(QStylePainter *, sfp[0]);
	if (qp) {
		QStyle* ret_v = qp->style();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QStyle*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQStylePainter::DummyQStylePainter()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStylePainter::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStylePainter::self = ptr;
	DummyQPainter::setSelf(ptr);
}

bool DummyQStylePainter::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQPainter::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStylePainter::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStylePainter::event_map->bigin();
	if ((itr = DummyQStylePainter::event_map->find(str)) == DummyQStylePainter::event_map->end()) {
		bool ret = false;
		ret = DummyQPainter::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStylePainter::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStylePainter::slot_map->bigin();
	if ((itr = DummyQStylePainter::slot_map->find(str)) == DummyQStylePainter::slot_map->end()) {
		bool ret = false;
		ret = DummyQPainter::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQStylePainter::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQPainter::reftrace(ctx, p, tail_);
}

void DummyQStylePainter::connection(QObject *o)
{
	QStylePainter *p = dynamic_cast<QStylePainter*>(o);
	if (p != NULL) {
	}
	DummyQPainter::connection(o);
}

KQStylePainter::KQStylePainter() : QStylePainter()
{
	self = NULL;
	dummy = new DummyQStylePainter();
}

KMETHOD QStylePainter_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStylePainter *qp = RawPtr_to(KQStylePainter *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStylePainter]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStylePainter]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStylePainter_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStylePainter *qp = RawPtr_to(KQStylePainter *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStylePainter]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStylePainter]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStylePainter_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStylePainter *qp = (KQStylePainter *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStylePainter_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQStylePainter *qp = (KQStylePainter *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStylePainter_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStylePainter::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQStylePainter(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStylePainter";
	cdef->free = QStylePainter_free;
	cdef->reftrace = QStylePainter_reftrace;
	cdef->compareTo = QStylePainter_compareTo;
}


