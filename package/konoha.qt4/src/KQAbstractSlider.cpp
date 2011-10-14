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
	action_triggered_func = NULL;
	range_changed_func = NULL;
	slider_moved_func = NULL;
	slider_pressed_func = NULL;
	slider_released_func = NULL;
	value_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("action-triggered", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("range-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("slider-moved", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("slider-pressed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("slider-released", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("value-changed", NULL));
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

bool DummyQAbstractSlider::actionTriggeredSlot(int action)
{
	if (action_triggered_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = action;
		knh_Func_invoke(lctx, action_triggered_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQAbstractSlider::rangeChangedSlot(int min, int max)
{
	if (range_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = min;
		lsfp[K_CALLDELTA+3].ivalue = max;
		knh_Func_invoke(lctx, range_changed_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQAbstractSlider::sliderMovedSlot(int value)
{
	if (slider_moved_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = value;
		knh_Func_invoke(lctx, slider_moved_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQAbstractSlider::sliderPressedSlot()
{
	if (slider_pressed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, slider_pressed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAbstractSlider::sliderReleasedSlot()
{
	if (slider_released_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, slider_released_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAbstractSlider::valueChangedSlot(int value)
{
	if (value_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = value;
		knh_Func_invoke(lctx, value_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQAbstractSlider::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractSlider::event_map->bigin();
	if ((itr = DummyQAbstractSlider::event_map->find(str)) == DummyQAbstractSlider::event_map->end()) {
		bool ret = false;
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
	if ((itr = DummyQAbstractSlider::slot_map->find(str)) == DummyQAbstractSlider::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		action_triggered_func = (*slot_map)["action-triggered"];
		range_changed_func = (*slot_map)["range-changed"];
		slider_moved_func = (*slot_map)["slider-moved"];
		slider_pressed_func = (*slot_map)["slider-pressed"];
		slider_released_func = (*slot_map)["slider-released"];
		value_changed_func = (*slot_map)["value-changed"];
		return true;
	}
}


void DummyQAbstractSlider::connection(QObject *o)
{
	connect(o, SIGNAL(actionTriggered(int)), this, SLOT(actionTriggeredSlot(int)));
	connect(o, SIGNAL(rangeChanged(int, int)), this, SLOT(rangeChangedSlot(int, int)));
	connect(o, SIGNAL(sliderMoved(int)), this, SLOT(sliderMovedSlot(int)));
	connect(o, SIGNAL(sliderPressed()), this, SLOT(sliderPressedSlot()));
	connect(o, SIGNAL(sliderReleased()), this, SLOT(sliderReleasedSlot()));
	connect(o, SIGNAL(valueChanged(int)), this, SLOT(valueChangedSlot(int)));
	DummyQWidget::connection(o);
}

KQAbstractSlider::KQAbstractSlider(QWidget* parent) : QAbstractSlider(parent)
{
	self = NULL;
	dummy = new DummyQAbstractSlider();
	dummy->connection((QObject*)this);
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
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
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 6;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQAbstractSlider *qp = (KQAbstractSlider *)p->rawptr;
//		(void)qp;
		if (qp->dummy->action_triggered_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->action_triggered_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->range_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->range_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->slider_moved_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->slider_moved_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->slider_pressed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->slider_pressed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->slider_released_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->slider_released_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->value_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->value_changed_func);
			KNH_SIZEREF(ctx);
		}
	}
}

static int QAbstractSlider_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAbstractSlider::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQAbstractSlider::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
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

