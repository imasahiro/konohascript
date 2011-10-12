//
//boolean QAbstractSlider.hasTracking();
KMETHOD QAbstractSlider_hasTracking(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->hasTracking();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAbstractSlider.getInvertedAppearance();
KMETHOD QAbstractSlider_getInvertedAppearance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->invertedAppearance();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAbstractSlider.getInvertedControls();
KMETHOD QAbstractSlider_getInvertedControls(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->invertedControls();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAbstractSlider.isSliderDown();
KMETHOD QAbstractSlider_isSliderDown(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isSliderDown();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QAbstractSlider.getMaximum();
KMETHOD QAbstractSlider_getMaximum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->maximum();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAbstractSlider.getMinimum();
KMETHOD QAbstractSlider_getMinimum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->minimum();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAbstractSlider.getOrientation();
KMETHOD QAbstractSlider_getOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		Qt::Orientation ret_v = qp->orientation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAbstractSlider.getPageStep();
KMETHOD QAbstractSlider_getPageStep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->pageStep();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QAbstractSlider.setInvertedAppearance(boolean arg0);
KMETHOD QAbstractSlider_setInvertedAppearance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setInvertedAppearance(arg0);
	}
	RETURNvoid_();
}

//void QAbstractSlider.setInvertedControls(boolean arg0);
KMETHOD QAbstractSlider_setInvertedControls(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setInvertedControls(arg0);
	}
	RETURNvoid_();
}

//void QAbstractSlider.setMaximum(int arg0);
KMETHOD QAbstractSlider_setMaximum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setMaximum(arg0);
	}
	RETURNvoid_();
}

//void QAbstractSlider.setMinimum(int arg0);
KMETHOD QAbstractSlider_setMinimum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setMinimum(arg0);
	}
	RETURNvoid_();
}

//void QAbstractSlider.setPageStep(int arg0);
KMETHOD QAbstractSlider_setPageStep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setPageStep(arg0);
	}
	RETURNvoid_();
}

//void QAbstractSlider.setRange(int min, int max);
KMETHOD QAbstractSlider_setRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		int min = Int_to(int, sfp[1]);
		int max = Int_to(int, sfp[2]);
		qp->setRange(min, max);
	}
	RETURNvoid_();
}

//void QAbstractSlider.setSingleStep(int arg0);
KMETHOD QAbstractSlider_setSingleStep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setSingleStep(arg0);
	}
	RETURNvoid_();
}

//void QAbstractSlider.setSliderDown(boolean arg0);
KMETHOD QAbstractSlider_setSliderDown(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setSliderDown(arg0);
	}
	RETURNvoid_();
}

//void QAbstractSlider.setSliderPosition(int arg0);
KMETHOD QAbstractSlider_setSliderPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setSliderPosition(arg0);
	}
	RETURNvoid_();
}

//void QAbstractSlider.setTracking(boolean enable);
KMETHOD QAbstractSlider_setTracking(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setTracking(enable);
	}
	RETURNvoid_();
}

//int QAbstractSlider.getSingleStep();
KMETHOD QAbstractSlider_getSingleStep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->singleStep();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAbstractSlider.getSliderPosition();
KMETHOD QAbstractSlider_getSliderPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->sliderPosition();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QAbstractSlider.triggerAction(int action);
KMETHOD QAbstractSlider_triggerAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		QAbstractSlider::SliderAction action = Int_to(QAbstractSlider::SliderAction, sfp[1]);
		qp->triggerAction(action);
	}
	RETURNvoid_();
}

//int QAbstractSlider.getValue();
KMETHOD QAbstractSlider_getValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->value();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QAbstractSlider.setOrientation(int arg0);
KMETHOD QAbstractSlider_setOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		Qt::Orientation arg0 = Int_to(Qt::Orientation, sfp[1]);
		qp->setOrientation(arg0);
	}
	RETURNvoid_();
}

//void QAbstractSlider.setValue(int arg0);
KMETHOD QAbstractSlider_setValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractSlider *  qp = RawPtr_to(QAbstractSlider *, sfp[0]);
	if (qp != NULL) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setValue(arg0);
	}
	RETURNvoid_();
}


DummyQAbstractSlider::DummyQAbstractSlider()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQAbstractSlider::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractSlider::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQAbstractSlider::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractSlider::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractSlider::event_map->bigin();
	if ((itr = DummyQAbstractSlider::event_map->find(str)) == DummyQAbstractSlider::event_map->end()) {
		bool ret;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractSlider::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractSlider::slot_map->bigin();
	if ((itr = DummyQAbstractSlider::event_map->find(str)) == DummyQAbstractSlider::slot_map->end()) {
		bool ret;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQAbstractSlider::KQAbstractSlider(QWidget* parent) : QAbstractSlider(parent)
{
	self = NULL;
}

KMETHOD QAbstractSlider_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractSlider *qp = RawPtr_to(KQAbstractSlider *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractSlider]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQAbstractSlider::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractSlider]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QAbstractSlider_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractSlider *qp = RawPtr_to(KQAbstractSlider *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractSlider]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQAbstractSlider::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractSlider]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractSlider_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAbstractSlider *qp = (KQAbstractSlider *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAbstractSlider_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQAbstractSlider *qp = (KQAbstractSlider *)p->rawptr;
		(void)qp;
	}
}

static int QAbstractSlider_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQAbstractSlider::event(QEvent *event)
{
	if (!DummyQAbstractSlider::eventDispatcher(event)) {
		QAbstractSlider::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQAbstractSlider(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractSlider";
	cdef->free = QAbstractSlider_free;
	cdef->reftrace = QAbstractSlider_reftrace;
	cdef->compareTo = QAbstractSlider_compareTo;
}

static knh_IntData_t QAbstractSliderConstInt[] = {
	{"SliderNoAction", QAbstractSlider::SliderNoAction},
	{"SliderSingleStepAdd", QAbstractSlider::SliderSingleStepAdd},
	{"SliderSingleStepSub", QAbstractSlider::SliderSingleStepSub},
	{"SliderPageStepAdd", QAbstractSlider::SliderPageStepAdd},
	{"SliderPageStepSub", QAbstractSlider::SliderPageStepSub},
	{"SliderToMinimum", QAbstractSlider::SliderToMinimum},
	{"SliderToMaximum", QAbstractSlider::SliderToMaximum},
	{"SliderMove", QAbstractSlider::SliderMove},
	{NULL, 0}
};

DEFAPI(void) constQAbstractSlider(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QAbstractSliderConstInt);
}

