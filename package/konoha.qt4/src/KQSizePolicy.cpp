//QSizePolicy QSizePolicy.new();
KMETHOD QSizePolicy_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSizePolicy *ret_v = new KQSizePolicy();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
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
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QSizePolicy.getControlType();
KMETHOD QSizePolicy_getControlType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp) {
		QSizePolicy::ControlType ret_v = qp->controlType();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QtOrientations QSizePolicy.expandingDirections();
KMETHOD QSizePolicy_expandingDirections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp) {
		Qt::Orientations ret_v = qp->expandingDirections();
		Qt::Orientations *ret_v_ = new Qt::Orientations(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QSizePolicy.hasHeightForWidth();
KMETHOD QSizePolicy_hasHeightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		qp->transpose();
	}
	RETURNvoid_();
}

//int QSizePolicy.getVerticalPolicy();
KMETHOD QSizePolicy_getVerticalPolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *  qp = RawPtr_to(QSizePolicy *, sfp[0]);
	if (qp) {
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
	if (qp) {
		int ret_v = qp->verticalStretch();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<String> QSizePolicy.parents();
KMETHOD QSizePolicy_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy *qp = RawPtr_to(QSizePolicy*, sfp[0]);
	if (qp != NULL) {
		int size = 10;
		knh_Array_t *a = new_Array0(ctx, size);
		const knh_ClassTBL_t *ct = sfp[0].p->h.cTBL;
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
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
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSizePolicy::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSizePolicy::slot_map->bigin();
	if ((itr = DummyQSizePolicy::slot_map->find(str)) == DummyQSizePolicy::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQSizePolicy::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQSizePolicy::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQSizePolicy::connection(QObject *o)
{
	QSizePolicy *p = dynamic_cast<QSizePolicy*>(o);
	if (p != NULL) {
	}
}

KQSizePolicy::KQSizePolicy() : QSizePolicy()
{
	self = NULL;
	dummy = new DummyQSizePolicy();
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
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
	if (p->rawptr != NULL) {
		KQSizePolicy *qp = (KQSizePolicy *)p->rawptr;
//		KQSizePolicy *qp = static_cast<KQSizePolicy*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSizePolicy_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QSizePolicy*>(p1->rawptr) == *static_cast<QSizePolicy*>(p2->rawptr) ? 0 : 1);
}

void KQSizePolicy::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
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


DEFAPI(void) defQSizePolicy(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSizePolicy";
	cdef->free = QSizePolicy_free;
	cdef->reftrace = QSizePolicy_reftrace;
	cdef->compareTo = QSizePolicy_compareTo;
}

//## QSizePolicyControlTypes QSizePolicyControlTypes.new(int value);
KMETHOD QSizePolicyControlTypes_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QSizePolicy::ControlType i = Int_to(QSizePolicy::ControlType, sfp[1]);
	QSizePolicy::ControlTypes *ret_v = new QSizePolicy::ControlTypes(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QSizePolicyControlTypes QSizePolicyControlTypes.and(int mask);
KMETHOD QSizePolicyControlTypes_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QSizePolicy::ControlTypes *qp = RawPtr_to(QSizePolicy::ControlTypes*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QSizePolicy::ControlTypes ret = ((*qp) & i);
		QSizePolicy::ControlTypes *ret_ = new QSizePolicy::ControlTypes(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QSizePolicyControlTypes QSizePolicyControlTypes.iand(QSizePolicy::QSizePolicyControlTypes other);
KMETHOD QSizePolicyControlTypes_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QSizePolicy::ControlTypes *qp = RawPtr_to(QSizePolicy::ControlTypes*, sfp[0]);
	if (qp != NULL) {
		QSizePolicy::ControlTypes *other = RawPtr_to(QSizePolicy::ControlTypes *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QSizePolicyControlTypes QSizePolicyControlTypes.or(QSizePolicyControlTypes f);
KMETHOD QSizePolicyControlTypes_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy::ControlTypes *qp = RawPtr_to(QSizePolicy::ControlTypes*, sfp[0]);
	if (qp != NULL) {
		QSizePolicy::ControlTypes *f = RawPtr_to(QSizePolicy::ControlTypes*, sfp[1]);
		QSizePolicy::ControlTypes ret = ((*qp) | (*f));
		QSizePolicy::ControlTypes *ret_ = new QSizePolicy::ControlTypes(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QSizePolicyControlTypes QSizePolicyControlTypes.ior(QSizePolicy::QSizePolicyControlTypes other);
KMETHOD QSizePolicyControlTypes_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QSizePolicy::ControlTypes *qp = RawPtr_to(QSizePolicy::ControlTypes*, sfp[0]);
	if (qp != NULL) {
		QSizePolicy::ControlTypes *other = RawPtr_to(QSizePolicy::ControlTypes *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QSizePolicyControlTypes QSizePolicyControlTypes.xor(QSizePolicyControlTypes f);
KMETHOD QSizePolicyControlTypes_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSizePolicy::ControlTypes *qp = RawPtr_to(QSizePolicy::ControlTypes*, sfp[0]);
	if (qp != NULL) {
		QSizePolicy::ControlTypes *f = RawPtr_to(QSizePolicy::ControlTypes*, sfp[1]);
		QSizePolicy::ControlTypes ret = ((*qp) ^ (*f));
		QSizePolicy::ControlTypes *ret_ = new QSizePolicy::ControlTypes(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QSizePolicyControlTypes QSizePolicyControlTypes.ixor(QSizePolicy::QSizePolicyControlTypes other);
KMETHOD QSizePolicyControlTypes_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QSizePolicy::ControlTypes *qp = RawPtr_to(QSizePolicy::ControlTypes*, sfp[0]);
	if (qp != NULL) {
		QSizePolicy::ControlTypes *other = RawPtr_to(QSizePolicy::ControlTypes *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QSizePolicyControlTypes.testFlag(int flag);
KMETHOD QSizePolicyControlTypes_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QSizePolicy::ControlTypes *qp = RawPtr_to(QSizePolicy::ControlTypes *, sfp[0]);
	if (qp != NULL) {
		QSizePolicy::ControlType flag = Int_to(QSizePolicy::ControlType, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QSizePolicyControlTypes.value();
KMETHOD QSizePolicyControlTypes_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QSizePolicy::ControlTypes *qp = RawPtr_to(QSizePolicy::ControlTypes *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QSizePolicyControlTypes_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QSizePolicy::ControlTypes *qp = (QSizePolicy::ControlTypes *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QSizePolicyControlTypes_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QSizePolicy::ControlTypes *qp = (QSizePolicy::ControlTypes *)p->rawptr;
		(void)qp;
	}
}

static int QSizePolicyControlTypes_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QSizePolicy::ControlTypes*)p1->rawptr);
//		int v2 = int(*(QSizePolicy::ControlTypes*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QSizePolicy::ControlTypes v1 = *(QSizePolicy::ControlTypes*)p1->rawptr;
		QSizePolicy::ControlTypes v2 = *(QSizePolicy::ControlTypes*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQSizePolicyControlTypes(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSizePolicyControlTypes";
	cdef->free = QSizePolicyControlTypes_free;
	cdef->reftrace = QSizePolicyControlTypes_reftrace;
	cdef->compareTo = QSizePolicyControlTypes_compareTo;
}

