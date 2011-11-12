//QTextOption QTextOption.new();
KMETHOD QTextOption_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextOption *ret_v = new KQTextOption();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTextOption QTextOption.new(QtAlignment alignment);
KMETHOD QTextOption_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	initFlag(alignment, Qt::Alignment, sfp[1]);
	KQTextOption *ret_v = new KQTextOption(alignment);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QTextOption QTextOption.new(QTextOption other);
KMETHOD QTextOption_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTextOption  other = *RawPtr_to(const QTextOption *, sfp[1]);
	KQTextOption *ret_v = new KQTextOption(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QtAlignment QTextOption.getAlignment();
KMETHOD QTextOption_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp) {
		Qt::Alignment ret_v = qp->alignment();
		Qt::Alignment *ret_v_ = new Qt::Alignment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextOptionFlags QTextOption.getFlags();
KMETHOD QTextOption_getFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp) {
		QTextOption::Flags ret_v = qp->flags();
		QTextOption::Flags *ret_v_ = new QTextOption::Flags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextOption.setAlignment(QtAlignment alignment);
KMETHOD QTextOption_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp) {
		initFlag(alignment, Qt::Alignment, sfp[1]);
		qp->setAlignment(alignment);
	}
	RETURNvoid_();
}

//void QTextOption.setFlags(QTextOptionFlags flags);
KMETHOD QTextOption_setFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp) {
		initFlag(flags, QTextOption::Flags, sfp[1]);
		qp->setFlags(flags);
	}
	RETURNvoid_();
}

//void QTextOption.setTabArray(Array<float> tabStops);
KMETHOD QTextOption_setTabArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<qreal> tabStops;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			tabStops.append(*(qreal*)p->rawptr);
		}
		qp->setTabArray(tabStops);
	}
	RETURNvoid_();
}

//void QTextOption.setTabStop(float tabStop);
KMETHOD QTextOption_setTabStop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp) {
		qreal tabStop = Float_to(qreal, sfp[1]);
		qp->setTabStop(tabStop);
	}
	RETURNvoid_();
}

//void QTextOption.setTextDirection(int direction);
KMETHOD QTextOption_setTextDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp) {
		Qt::LayoutDirection direction = Int_to(Qt::LayoutDirection, sfp[1]);
		qp->setTextDirection(direction);
	}
	RETURNvoid_();
}

//void QTextOption.setUseDesignMetrics(boolean enable);
KMETHOD QTextOption_setUseDesignMetrics(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setUseDesignMetrics(enable);
	}
	RETURNvoid_();
}

//void QTextOption.setWrapMode(int mode);
KMETHOD QTextOption_setWrapMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp) {
		QTextOption::WrapMode mode = Int_to(QTextOption::WrapMode, sfp[1]);
		qp->setWrapMode(mode);
	}
	RETURNvoid_();
}

//Array<float> QTextOption.getTabArray();
KMETHOD QTextOption_getTabArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp) {
		QList<qreal> ret_v = qp->tabArray();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("qreal"));
		for (int n = 0; n < list_size; n++) {
			qreal *ret_v_ = new qreal(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//float QTextOption.getTabStop();
KMETHOD QTextOption_getTabStop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->tabStop();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QTextOption.getTextDirection();
KMETHOD QTextOption_getTextDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp) {
		Qt::LayoutDirection ret_v = qp->textDirection();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QTextOption.getUseDesignMetrics();
KMETHOD QTextOption_getUseDesignMetrics(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp) {
		bool ret_v = qp->useDesignMetrics();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTextOption.getWrapMode();
KMETHOD QTextOption_getWrapMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp) {
		QTextOption::WrapMode ret_v = qp->wrapMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<String> QTextOption.parents();
KMETHOD QTextOption_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *qp = RawPtr_to(QTextOption*, sfp[0]);
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

DummyQTextOption::DummyQTextOption()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextOption::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextOption::self = ptr;
}

bool DummyQTextOption::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextOption::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextOption::event_map->bigin();
	if ((itr = DummyQTextOption::event_map->find(str)) == DummyQTextOption::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextOption::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextOption::slot_map->bigin();
	if ((itr = DummyQTextOption::slot_map->find(str)) == DummyQTextOption::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTextOption::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTextOption::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQTextOption::connection(QObject *o)
{
	QTextOption *p = dynamic_cast<QTextOption*>(o);
	if (p != NULL) {
	}
}

KQTextOption::KQTextOption() : QTextOption()
{
	self = NULL;
	dummy = new DummyQTextOption();
}

KMETHOD QTextOption_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextOption *qp = RawPtr_to(KQTextOption *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextOption]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextOption]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextOption_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextOption *qp = RawPtr_to(KQTextOption *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextOption]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextOption]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextOption_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextOption *qp = (KQTextOption *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextOption_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQTextOption *qp = (KQTextOption *)p->rawptr;
//		KQTextOption *qp = static_cast<KQTextOption*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextOption_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextOption::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QTextOptionConstInt[] = {
	{"IncludeTrailingSpaces", QTextOption::IncludeTrailingSpaces},
	{"ShowTabsAndSpaces", QTextOption::ShowTabsAndSpaces},
	{"ShowLineAndParagraphSeparators", QTextOption::ShowLineAndParagraphSeparators},
	{"AddSpaceForLineAndParagraphSeparators", QTextOption::AddSpaceForLineAndParagraphSeparators},
	{"SuppressColors", QTextOption::SuppressColors},
	{"LeftTab", QTextOption::LeftTab},
	{"RightTab", QTextOption::RightTab},
	{"CenterTab", QTextOption::CenterTab},
	{"DelimiterTab", QTextOption::DelimiterTab},
	{"NoWrap", QTextOption::NoWrap},
	{"WordWrap", QTextOption::WordWrap},
	{"ManualWrap", QTextOption::ManualWrap},
	{"WrapAnywhere", QTextOption::WrapAnywhere},
	{"WrapAtWordBoundaryOrAnywhere", QTextOption::WrapAtWordBoundaryOrAnywhere},
	{NULL, 0}
};

DEFAPI(void) constQTextOption(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTextOptionConstInt);
}


DEFAPI(void) defQTextOption(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextOption";
	cdef->free = QTextOption_free;
	cdef->reftrace = QTextOption_reftrace;
	cdef->compareTo = QTextOption_compareTo;
}

//## QTextOptionFlags QTextOptionFlags.new(int value);
KMETHOD QTextOptionFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextOption::Flag i = Int_to(QTextOption::Flag, sfp[1]);
	QTextOption::Flags *ret_v = new QTextOption::Flags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QTextOptionFlags QTextOptionFlags.and(int mask);
KMETHOD QTextOptionFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextOption::Flags *qp = RawPtr_to(QTextOption::Flags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QTextOption::Flags ret = ((*qp) & i);
		QTextOption::Flags *ret_ = new QTextOption::Flags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextOptionFlags QTextOptionFlags.iand(QTextOption::QTextOptionFlags other);
KMETHOD QTextOptionFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextOption::Flags *qp = RawPtr_to(QTextOption::Flags*, sfp[0]);
	if (qp != NULL) {
		QTextOption::Flags *other = RawPtr_to(QTextOption::Flags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextOptionFlags QTextOptionFlags.or(QTextOptionFlags f);
KMETHOD QTextOptionFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption::Flags *qp = RawPtr_to(QTextOption::Flags*, sfp[0]);
	if (qp != NULL) {
		QTextOption::Flags *f = RawPtr_to(QTextOption::Flags*, sfp[1]);
		QTextOption::Flags ret = ((*qp) | (*f));
		QTextOption::Flags *ret_ = new QTextOption::Flags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextOptionFlags QTextOptionFlags.ior(QTextOption::QTextOptionFlags other);
KMETHOD QTextOptionFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextOption::Flags *qp = RawPtr_to(QTextOption::Flags*, sfp[0]);
	if (qp != NULL) {
		QTextOption::Flags *other = RawPtr_to(QTextOption::Flags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextOptionFlags QTextOptionFlags.xor(QTextOptionFlags f);
KMETHOD QTextOptionFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption::Flags *qp = RawPtr_to(QTextOption::Flags*, sfp[0]);
	if (qp != NULL) {
		QTextOption::Flags *f = RawPtr_to(QTextOption::Flags*, sfp[1]);
		QTextOption::Flags ret = ((*qp) ^ (*f));
		QTextOption::Flags *ret_ = new QTextOption::Flags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextOptionFlags QTextOptionFlags.ixor(QTextOption::QTextOptionFlags other);
KMETHOD QTextOptionFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextOption::Flags *qp = RawPtr_to(QTextOption::Flags*, sfp[0]);
	if (qp != NULL) {
		QTextOption::Flags *other = RawPtr_to(QTextOption::Flags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QTextOptionFlags.testFlag(int flag);
KMETHOD QTextOptionFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextOption::Flags *qp = RawPtr_to(QTextOption::Flags *, sfp[0]);
	if (qp != NULL) {
		QTextOption::Flag flag = Int_to(QTextOption::Flag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QTextOptionFlags.value();
KMETHOD QTextOptionFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextOption::Flags *qp = RawPtr_to(QTextOption::Flags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QTextOptionFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QTextOption::Flags *qp = (QTextOption::Flags *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QTextOptionFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QTextOption::Flags *qp = (QTextOption::Flags *)p->rawptr;
		(void)qp;
	}
}

static int QTextOptionFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QTextOption::Flags*)p1->rawptr);
//		int v2 = int(*(QTextOption::Flags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QTextOption::Flags v1 = *(QTextOption::Flags*)p1->rawptr;
		QTextOption::Flags v2 = *(QTextOption::Flags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQTextOptionFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextOptionFlags";
	cdef->free = QTextOptionFlags_free;
	cdef->reftrace = QTextOptionFlags_reftrace;
	cdef->compareTo = QTextOptionFlags_compareTo;
}

