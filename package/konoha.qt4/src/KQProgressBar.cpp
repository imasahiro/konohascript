//@Virtual @Override QSize QProgressBar.minimumSizeHint();
KMETHOD QProgressBar_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QProgressBar.sizeHint();
KMETHOD QProgressBar_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QProgressBar QProgressBar.new(QWidget parent);
KMETHOD QProgressBar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQProgressBar *ret_v = new KQProgressBar(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QProgressBar.getAlignment();
KMETHOD QProgressBar_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment ret_v = qp->alignment();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QProgressBar.getFormat();
KMETHOD QProgressBar_getFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->format();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QProgressBar.getInvertedAppearance();
KMETHOD QProgressBar_getInvertedAppearance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->invertedAppearance();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QProgressBar.getInvertedAppearance();
KMETHOD QProgressBar_getInvertedAppearance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->invertedAppearance();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//boolean QProgressBar.isTextVisible();
KMETHOD QProgressBar_isTextVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isTextVisible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QProgressBar.getMaximum();
KMETHOD QProgressBar_getMaximum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->maximum();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QProgressBar.getMinimum();
KMETHOD QProgressBar_getMinimum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->minimum();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QProgressBar.getOrientation();
KMETHOD QProgressBar_getOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		Qt::Orientation ret_v = qp->orientation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QProgressBar.setAlignment(int alignment);
KMETHOD QProgressBar_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment alignment = Int_to(Qt::Alignment, sfp[1]);
		qp->setAlignment(alignment);
	}
	RETURNvoid_();
}

//void QProgressBar.setFormat(String fmt);
KMETHOD QProgressBar_setFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		const QString format = String_to(const QString, sfp[1]);
		qp->setFormat(format);
	}
	RETURNvoid_();
}

//void QProgressBar.setInvertedAppearance(boolean invert);
KMETHOD QProgressBar_setInvertedAppearance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		bool invert = Boolean_to(bool, sfp[1]);
		qp->setInvertedAppearance(invert);
	}
	RETURNvoid_();
}

//void QProgressBar.setTextDirection(int textDirection);
KMETHOD QProgressBar_setTextDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		QProgressBar::Direction textDirection = Int_to(QProgressBar::Direction, sfp[1]);
		qp->setTextDirection(textDirection);
	}
	RETURNvoid_();
}

//void QProgressBar.setTextVisible(boolean visible);
KMETHOD QProgressBar_setTextVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setTextVisible(visible);
	}
	RETURNvoid_();
}

//@Virtual String QProgressBar.text();
KMETHOD QProgressBar_text(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QProgressBar.getTextDirection();
KMETHOD QProgressBar_getTextDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		QProgressBar::Direction ret_v = qp->textDirection();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QProgressBar.getTextDirection();
KMETHOD QProgressBar_getTextDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		QProgressBar::Direction ret_v = qp->textDirection();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//int QProgressBar.getValue();
KMETHOD QProgressBar_getValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->value();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QProgressBar.reset();
KMETHOD QProgressBar_reset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		qp->reset();
	}
	RETURNvoid_();
}

//void QProgressBar.setMaximum(int maximum);
KMETHOD QProgressBar_setMaximum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		int maximum = Int_to(int, sfp[1]);
		qp->setMaximum(maximum);
	}
	RETURNvoid_();
}

//void QProgressBar.setMinimum(int minimum);
KMETHOD QProgressBar_setMinimum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		int minimum = Int_to(int, sfp[1]);
		qp->setMinimum(minimum);
	}
	RETURNvoid_();
}

//void QProgressBar.setOrientation(int arg0);
KMETHOD QProgressBar_setOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		Qt::Orientation arg0 = Int_to(Qt::Orientation, sfp[1]);
		qp->setOrientation(arg0);
	}
	RETURNvoid_();
}

//void QProgressBar.setRange(int minimum, int maximum);
KMETHOD QProgressBar_setRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		int minimum = Int_to(int, sfp[1]);
		int maximum = Int_to(int, sfp[2]);
		qp->setRange(minimum, maximum);
	}
	RETURNvoid_();
}

//void QProgressBar.setValue(int value);
KMETHOD QProgressBar_setValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp != NULL) {
		int value = Int_to(int, sfp[1]);
		qp->setValue(value);
	}
	RETURNvoid_();
}


DummyQProgressBar::DummyQProgressBar()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQProgressBar::setSelf(knh_RawPtr_t *ptr)
{
	DummyQProgressBar::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQProgressBar::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQProgressBar::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQProgressBar::event_map->bigin();
	if ((itr = DummyQProgressBar::event_map->find(str)) == DummyQProgressBar::event_map->end()) {
		bool ret;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQProgressBar::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQProgressBar::slot_map->bigin();
	if ((itr = DummyQProgressBar::event_map->find(str)) == DummyQProgressBar::slot_map->end()) {
		bool ret;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQProgressBar::KQProgressBar(QWidget* parent) : QProgressBar(parent)
{
	self = NULL;
}

KMETHOD QProgressBar_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQProgressBar *qp = RawPtr_to(KQProgressBar *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QProgressBar]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQProgressBar::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QProgressBar]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QProgressBar_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQProgressBar *qp = RawPtr_to(KQProgressBar *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QProgressBar]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQProgressBar::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QProgressBar]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QProgressBar_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQProgressBar *qp = (KQProgressBar *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QProgressBar_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQProgressBar *qp = (KQProgressBar *)p->rawptr;
		(void)qp;
	}
}

static int QProgressBar_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQProgressBar::event(QEvent *event)
{
	if (!DummyQProgressBar::eventDispatcher(event)) {
		QProgressBar::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQProgressBar(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QProgressBar";
	cdef->free = QProgressBar_free;
	cdef->reftrace = QProgressBar_reftrace;
	cdef->compareTo = QProgressBar_compareTo;
}

static knh_IntData_t QProgressBarConstInt[] = {
	{"TopToBottom", QProgressBar::TopToBottom},
	{"BottomToTop", QProgressBar::BottomToTop},
	{NULL, 0}
};

DEFAPI(void) constQProgressBar(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QProgressBarConstInt);
}

