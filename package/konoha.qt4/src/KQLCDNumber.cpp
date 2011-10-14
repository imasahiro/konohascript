//@Virtual @Override QSize QLCDNumber.sizeHint();
KMETHOD QLCDNumber_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QLCDNumber QLCDNumber.new(QWidget parent);
KMETHOD QLCDNumber_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQLCDNumber *ret_v = new KQLCDNumber(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QLCDNumber QLCDNumber.new(int numDigits, QWidget parent);
KMETHOD QLCDNumber_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	uint  numDigits = *RawPtr_to(uint *, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQLCDNumber *ret_v = new KQLCDNumber(numDigits, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QLCDNumber.checkOverflow(double num);
KMETHOD QLCDNumber_checkOverflow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		double  num = *RawPtr_to(double *, sfp[1]);
		bool ret_v = qp->checkOverflow(num);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QLCDNumber.checkOverflow(int num);
KMETHOD QLCDNumber_checkOverflow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		int num = Int_to(int, sfp[1]);
		bool ret_v = qp->checkOverflow(num);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//int QLCDNumber.getDigitCount();
KMETHOD QLCDNumber_getDigitCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->digitCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QLCDNumber.intValue();
KMETHOD QLCDNumber_intValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->intValue();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QLCDNumber.getMode();
KMETHOD QLCDNumber_getMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		QLCDNumber::Mode ret_v = qp->mode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QLCDNumber.getSegmentStyle();
KMETHOD QLCDNumber_getSegmentStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		QLCDNumber::SegmentStyle ret_v = qp->segmentStyle();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QLCDNumber.setDigitCount(int numDigits);
KMETHOD QLCDNumber_setDigitCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		int numDigits = Int_to(int, sfp[1]);
		qp->setDigitCount(numDigits);
	}
	RETURNvoid_();
}

//void QLCDNumber.setMode(int arg0);
KMETHOD QLCDNumber_setMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		QLCDNumber::Mode arg0 = Int_to(QLCDNumber::Mode, sfp[1]);
		qp->setMode(arg0);
	}
	RETURNvoid_();
}

//void QLCDNumber.setSegmentStyle(int arg0);
KMETHOD QLCDNumber_setSegmentStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		QLCDNumber::SegmentStyle arg0 = Int_to(QLCDNumber::SegmentStyle, sfp[1]);
		qp->setSegmentStyle(arg0);
	}
	RETURNvoid_();
}

//boolean QLCDNumber.getSmallDecimalPoint();
KMETHOD QLCDNumber_getSmallDecimalPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->smallDecimalPoint();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//double QLCDNumber.value();
KMETHOD QLCDNumber_value(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		double ret_v = qp->value();
		double *ret_v_ = new double(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QLCDNumber.display(String s);
KMETHOD QLCDNumber_display(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		const QString s = String_to(const QString, sfp[1]);
		qp->display(s);
	}
	RETURNvoid_();
}

/*
//void QLCDNumber.display(double num);
KMETHOD QLCDNumber_display(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		double  num = *RawPtr_to(double *, sfp[1]);
		qp->display(num);
	}
	RETURNvoid_();
}
*/
/*
//void QLCDNumber.display(int num);
KMETHOD QLCDNumber_display(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		int num = Int_to(int, sfp[1]);
		qp->display(num);
	}
	RETURNvoid_();
}
*/
//void QLCDNumber.setBinMode();
KMETHOD QLCDNumber_setBinMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		qp->setBinMode();
	}
	RETURNvoid_();
}

//void QLCDNumber.setDecMode();
KMETHOD QLCDNumber_setDecMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		qp->setDecMode();
	}
	RETURNvoid_();
}

//void QLCDNumber.setHexMode();
KMETHOD QLCDNumber_setHexMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		qp->setHexMode();
	}
	RETURNvoid_();
}

//void QLCDNumber.setOctMode();
KMETHOD QLCDNumber_setOctMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		qp->setOctMode();
	}
	RETURNvoid_();
}

//void QLCDNumber.setSmallDecimalPoint(boolean arg0);
KMETHOD QLCDNumber_setSmallDecimalPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLCDNumber *  qp = RawPtr_to(QLCDNumber *, sfp[0]);
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setSmallDecimalPoint(arg0);
	}
	RETURNvoid_();
}


DummyQLCDNumber::DummyQLCDNumber()
{
	self = NULL;
	overflow_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("overflow", NULL));
}

void DummyQLCDNumber::setSelf(knh_RawPtr_t *ptr)
{
	DummyQLCDNumber::self = ptr;
	DummyQFrame::setSelf(ptr);
}

bool DummyQLCDNumber::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQFrame::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQLCDNumber::overflowSlot()
{
	if (overflow_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, overflow_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQLCDNumber::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLCDNumber::event_map->bigin();
	if ((itr = DummyQLCDNumber::event_map->find(str)) == DummyQLCDNumber::event_map->end()) {
		bool ret = false;
		ret = DummyQFrame::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQLCDNumber::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLCDNumber::slot_map->bigin();
	if ((itr = DummyQLCDNumber::slot_map->find(str)) == DummyQLCDNumber::slot_map->end()) {
		bool ret = false;
		ret = DummyQFrame::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		overflow_func = (*slot_map)["overflow"];
		return true;
	}
}


void DummyQLCDNumber::connection(QObject *o)
{
	connect(o, SIGNAL(overflow()), this, SLOT(overflowSlot()));
	DummyQFrame::connection(o);
}

KQLCDNumber::KQLCDNumber(QWidget* parent) : QLCDNumber(parent)
{
	self = NULL;
	dummy = new DummyQLCDNumber();
	dummy->connection((QObject*)this);
}

KMETHOD QLCDNumber_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLCDNumber *qp = RawPtr_to(KQLCDNumber *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QLCDNumber]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLCDNumber]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QLCDNumber_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLCDNumber *qp = RawPtr_to(KQLCDNumber *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QLCDNumber]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLCDNumber]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QLCDNumber_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQLCDNumber *qp = (KQLCDNumber *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QLCDNumber_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 1;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQLCDNumber *qp = (KQLCDNumber *)p->rawptr;
//		(void)qp;
		if (qp->dummy->overflow_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->overflow_func);
			KNH_SIZEREF(ctx);
		}
	}
}

static int QLCDNumber_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQLCDNumber::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQLCDNumber::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QLCDNumber::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQLCDNumber(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QLCDNumber";
	cdef->free = QLCDNumber_free;
	cdef->reftrace = QLCDNumber_reftrace;
	cdef->compareTo = QLCDNumber_compareTo;
}

static knh_IntData_t QLCDNumberConstInt[] = {
	{"Hex", QLCDNumber::Hex},
	{"Dec", QLCDNumber::Dec},
	{"Oct", QLCDNumber::Oct},
	{"Bin", QLCDNumber::Bin},
	{"Outline", QLCDNumber::Outline},
	{"Filled", QLCDNumber::Filled},
	{"Flat", QLCDNumber::Flat},
	{NULL, 0}
};

DEFAPI(void) constQLCDNumber(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QLCDNumberConstInt);
}

