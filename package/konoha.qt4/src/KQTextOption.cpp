//QTextOption QTextOption.new();
KMETHOD QTextOption_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextOption *ret_v = new KQTextOption();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTextOption QTextOption.new(int alignment);
KMETHOD QTextOption_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::Alignment alignment = Int_to(Qt::Alignment, sfp[1]);
	KQTextOption *ret_v = new KQTextOption(alignment);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
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
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QTextOption.getAlignment();
KMETHOD QTextOption_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment ret_v = qp->alignment();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextOption.getFlags();
KMETHOD QTextOption_getFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp != NULL) {
		QTextOption::Flags ret_v = qp->flags();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTextOption.setAlignment(int alignment);
KMETHOD QTextOption_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment alignment = Int_to(Qt::Alignment, sfp[1]);
		qp->setAlignment(alignment);
	}
	RETURNvoid_();
}

//void QTextOption.setFlags(int flags);
KMETHOD QTextOption_setFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp != NULL) {
		QTextOption::Flags flags = Int_to(QTextOption::Flags, sfp[1]);
		qp->setFlags(flags);
	}
	RETURNvoid_();
}

//void QTextOption.setTabArray(Array<float> tabStops);
KMETHOD QTextOption_setTabArray(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
		qreal tabStop = Float_to(qreal, sfp[1]);
		qp->setTabStop(tabStop);
	}
	RETURNvoid_();
}

//void QTextOption.setTabs(Array<int> tabStops);
KMETHOD QTextOption_setTabs(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp != NULL) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QTextOption::Tab> tabStops;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			tabStops.append(*(QTextOption::Tab*)p->rawptr);
		}
		qp->setTabs(tabStops);
	}
	RETURNvoid_();
}

//void QTextOption.setTextDirection(int direction);
KMETHOD QTextOption_setTextDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		QList<qreal>ret_v = qp->tabArray();
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
	if (qp != NULL) {
		qreal ret_v = qp->tabStop();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//Array<int> QTextOption.getTabs();
KMETHOD QTextOption_getTabs(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp != NULL) {
		QList<QTextOption::Tab>ret_v = qp->tabs();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QTextOption::Tab"));
		for (int n = 0; n < list_size; n++) {
			QTextOption::Tab *ret_v_ = new QTextOption::Tab(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//int QTextOption.getTextDirection();
KMETHOD QTextOption_getTextDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextOption *  qp = RawPtr_to(QTextOption *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		QTextOption::WrapMode ret_v = qp->wrapMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
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
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextOption::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextOption::slot_map->bigin();
	if ((itr = DummyQTextOption::event_map->find(str)) == DummyQTextOption::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQTextOption::KQTextOption() : QTextOption()
{
	self = NULL;
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
		if (!qp->DummyQTextOption::addEvent(callback_func, str)) {
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
		if (!qp->DummyQTextOption::signalConnect(callback_func, str)) {
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
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQTextOption *qp = (KQTextOption *)p->rawptr;
		(void)qp;
	}
}

static int QTextOption_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQTextOption(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextOption";
	cdef->free = QTextOption_free;
	cdef->reftrace = QTextOption_reftrace;
	cdef->compareTo = QTextOption_compareTo;
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

