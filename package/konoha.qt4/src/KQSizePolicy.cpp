//QSizePolicy QSizePolicy.new();
KMETHOD QSizePolicy_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSizePolicy *ret_v = new KQSizePolicy();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QSizePolicy QSizePolicy.new(int horizontal, int vertical);
KMETHOD QSizePolicy_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy::Policy horizontal = Int_to(QSizePolicy::Policy, sfp[1]);
	QSizePolicy::Policy vertical = Int_to(QSizePolicy::Policy, sfp[2]);
	KQSizePolicy *ret_v = new KQSizePolicy(horizontal, vertical);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QSizePolicy QSizePolicy.new(int horizontal, int vertical, int type);
KMETHOD QSizePolicy_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy::Policy horizontal = Int_to(QSizePolicy::Policy, sfp[1]);
	QSizePolicy::Policy vertical = Int_to(QSizePolicy::Policy, sfp[2]);
	QSizePolicy::ControlType type = Int_to(QSizePolicy::ControlType, sfp[3]);
	KQSizePolicy *ret_v = new KQSizePolicy(horizontal, vertical, type);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QSizePolicy.getControlType();
KMETHOD QSizePolicy_getControlType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp != NULL) {
		QSizePolicy::ControlType ret_v = qp->controlType();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QSizePolicy.expandingDirections();
KMETHOD QSizePolicy_expandingDirections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp != NULL) {
		Qt::Orientations ret_v = qp->expandingDirections();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QSizePolicy.hasHeightForWidth();
KMETHOD QSizePolicy_hasHeightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->hasHeightForWidth();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QSizePolicy.getHorizontalPolicy();
KMETHOD QSizePolicy_getHorizontalPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp != NULL) {
		QSizePolicy::Policy ret_v = qp->horizontalPolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QSizePolicy.getHorizontalStretch();
KMETHOD QSizePolicy_getHorizontalStretch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->horizontalStretch();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QSizePolicy.setControlType(int type);
KMETHOD QSizePolicy_setControlType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp != NULL) {
		QSizePolicy::ControlType type = Int_to(QSizePolicy::ControlType, sfp[1]);
		qp->setControlType(type);
	}
	RETURNvoid_();
}

//void QSizePolicy.setHeightForWidth(boolean dependent);
KMETHOD QSizePolicy_setHeightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp != NULL) {
		bool dependent = Boolean_to(bool, sfp[1]);
		qp->setHeightForWidth(dependent);
	}
	RETURNvoid_();
}

//void QSizePolicy.setHorizontalPolicy(int policy);
KMETHOD QSizePolicy_setHorizontalPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp != NULL) {
		QSizePolicy::Policy policy = Int_to(QSizePolicy::Policy, sfp[1]);
		qp->setHorizontalPolicy(policy);
	}
	RETURNvoid_();
}

//void QSizePolicy.setHorizontalStretch(String stretchFactor);
KMETHOD QSizePolicy_setHorizontalStretch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp != NULL) {
		uchar  stretchFactor = *RawPtr_to(uchar *, sfp[1]);
		qp->setHorizontalStretch(stretchFactor);
	}
	RETURNvoid_();
}

//void QSizePolicy.setVerticalPolicy(int policy);
KMETHOD QSizePolicy_setVerticalPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp != NULL) {
		QSizePolicy::Policy policy = Int_to(QSizePolicy::Policy, sfp[1]);
		qp->setVerticalPolicy(policy);
	}
	RETURNvoid_();
}

//void QSizePolicy.setVerticalStretch(String stretchFactor);
KMETHOD QSizePolicy_setVerticalStretch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp != NULL) {
		uchar  stretchFactor = *RawPtr_to(uchar *, sfp[1]);
		qp->setVerticalStretch(stretchFactor);
	}
	RETURNvoid_();
}

//void QSizePolicy.transpose();
KMETHOD QSizePolicy_transpose(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp != NULL) {
		qp->transpose();
	}
	RETURNvoid_();
}

//int QSizePolicy.getVerticalPolicy();
KMETHOD QSizePolicy_getVerticalPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp != NULL) {
		QSizePolicy::Policy ret_v = qp->verticalPolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QSizePolicy.getVerticalStretch();
KMETHOD QSizePolicy_getVerticalStretch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->verticalStretch();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQSizePolicy::DummyQSizePolicy()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSizePolicy::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSizePolicy::self = ptr;
}

bool DummyQSizePolicy::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQSizePolicy::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSizePolicy::event_map->bigin();
	if ((itr = DummyQSizePolicy::event_map->find(str)) == DummyQSizePolicy::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSizePolicy::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSizePolicy::slot_map->bigin();
	if ((itr = DummyQSizePolicy::event_map->find(str)) == DummyQSizePolicy::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQSizePolicy::KQSizePolicy() : QSizePolicy()
{
	self = NULL;
}

KMETHOD QSizePolicy_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSizePolicy *qp = RawPtr_to(KQSizePolicy *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSizePolicy]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQSizePolicy::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSizePolicy]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QSizePolicy_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSizePolicy *qp = RawPtr_to(KQSizePolicy *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSizePolicy]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQSizePolicy::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSizePolicy]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSizePolicy_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSizePolicy *qp = (KQSizePolicy *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSizePolicy_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQSizePolicy *qp = (KQSizePolicy *)p->rawptr;
		(void)qp;
	}
}

static int QSizePolicy_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QSizePolicy*>(p1->rawptr) == *static_cast<QSizePolicy*>(p2->rawptr) ? 0 : 1);
}

DEFAPI(void) defQSizePolicy(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSizePolicy";
	cdef->free = QSizePolicy_free;
	cdef->reftrace = QSizePolicy_reftrace;
	cdef->compareTo = QSizePolicy_compareTo;
}

static knh_IntData_t QSizePolicyConstInt[] = {
	{"DefaultType", QSizePolicy::DefaultType},
	{"ButtonBox", QSizePolicy::ButtonBox},
	{"CheckBox", QSizePolicy::CheckBox},
	{"ComboBox", QSizePolicy::ComboBox},
	{"Frame", QSizePolicy::Frame},
	{"GroupBox", QSizePolicy::GroupBox},
	{"Label", QSizePolicy::Label},
	{"Line", QSizePolicy::Line},
	{"LineEdit", QSizePolicy::LineEdit},
	{"PushButton", QSizePolicy::PushButton},
	{"RadioButton", QSizePolicy::RadioButton},
	{"Slider", QSizePolicy::Slider},
	{"SpinBox", QSizePolicy::SpinBox},
	{"TabWidget", QSizePolicy::TabWidget},
	{"ToolButton", QSizePolicy::ToolButton},
	{"Fixed", QSizePolicy::Fixed},
	{"Minimum", QSizePolicy::Minimum},
	{"Maximum", QSizePolicy::Maximum},
	{"Preferred", QSizePolicy::Preferred},
	{"Expanding", QSizePolicy::Expanding},
	{"MinimumExpanding", QSizePolicy::MinimumExpanding},
	{"Ignored", QSizePolicy::Ignored},
	{"GrowFlag", QSizePolicy::GrowFlag},
	{"ExpandFlag", QSizePolicy::ExpandFlag},
	{"ShrinkFlag", QSizePolicy::ShrinkFlag},
	{"IgnoreFlag", QSizePolicy::IgnoreFlag},
	{NULL, 0}
};

DEFAPI(void) constQSizePolicy(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QSizePolicyConstInt);
}

