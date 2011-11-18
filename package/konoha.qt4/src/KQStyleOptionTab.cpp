//QStyleOptionTab QStyleOptionTab.new();
KMETHOD QStyleOptionTab_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTab *ret_v = new KQStyleOptionTab();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionTab QStyleOptionTab.new(QStyleOptionTab other);
KMETHOD QStyleOptionTab_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionTab  other = *RawPtr_to(const QStyleOptionTab *, sfp[1]);
	KQStyleOptionTab *ret_v = new KQStyleOptionTab(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionTab::DummyQStyleOptionTab()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQStyleOptionTab::~DummyQStyleOptionTab()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQStyleOptionTab::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionTab::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionTab::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionTab::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTab::event_map->bigin();
	if ((itr = DummyQStyleOptionTab::event_map->find(str)) == DummyQStyleOptionTab::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionTab::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTab::slot_map->bigin();
	if ((itr = DummyQStyleOptionTab::slot_map->find(str)) == DummyQStyleOptionTab::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyleOptionTab::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionTab::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOption::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionTab::connection(QObject *o)
{
	QStyleOptionTab *p = dynamic_cast<QStyleOptionTab*>(o);
	if (p != NULL) {
	}
	DummyQStyleOption::connection(o);
}

KQStyleOptionTab::KQStyleOptionTab() : QStyleOptionTab()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQStyleOptionTab();
}

KQStyleOptionTab::~KQStyleOptionTab()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QStyleOptionTab_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTab *qp = RawPtr_to(KQStyleOptionTab *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTab]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTab]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionTab_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTab *qp = RawPtr_to(KQStyleOptionTab *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTab]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTab]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionTab_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQStyleOptionTab *qp = (KQStyleOptionTab *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QStyleOptionTab*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QStyleOptionTab_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQStyleOptionTab *qp = (KQStyleOptionTab *)p->rawptr;
		KQStyleOptionTab *qp = static_cast<KQStyleOptionTab*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionTab_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionTab::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionTabConstInt[] = {
	{"NoCornerWidgets", QStyleOptionTab::NoCornerWidgets},
	{"LeftCornerWidget", QStyleOptionTab::LeftCornerWidget},
	{"RightCornerWidget", QStyleOptionTab::RightCornerWidget},
	{"NotAdjacent", QStyleOptionTab::NotAdjacent},
	{"NextIsSelected", QStyleOptionTab::NextIsSelected},
	{"PreviousIsSelected", QStyleOptionTab::PreviousIsSelected},
	{"Type", QStyleOptionTab::Type},
	{"Version", QStyleOptionTab::Version},
	{"Beginning", QStyleOptionTab::Beginning},
	{"Middle", QStyleOptionTab::Middle},
	{"End", QStyleOptionTab::End},
	{"OnlyOneTab", QStyleOptionTab::OnlyOneTab},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionTab(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionTabConstInt);
}


DEFAPI(void) defQStyleOptionTab(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionTab";
	cdef->free = QStyleOptionTab_free;
	cdef->reftrace = QStyleOptionTab_reftrace;
	cdef->compareTo = QStyleOptionTab_compareTo;
}

//## QStyleOptionTabCornerWidgets QStyleOptionTabCornerWidgets.new(int value);
KMETHOD QStyleOptionTabCornerWidgets_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionTab::CornerWidget i = Int_to(QStyleOptionTab::CornerWidget, sfp[1]);
	QStyleOptionTab::CornerWidgets *ret_v = new QStyleOptionTab::CornerWidgets(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QStyleOptionTabCornerWidgets QStyleOptionTabCornerWidgets.and(int mask);
KMETHOD QStyleOptionTabCornerWidgets_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionTab::CornerWidgets *qp = RawPtr_to(QStyleOptionTab::CornerWidgets*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QStyleOptionTab::CornerWidgets ret = ((*qp) & i);
		QStyleOptionTab::CornerWidgets *ret_ = new QStyleOptionTab::CornerWidgets(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionTabCornerWidgets QStyleOptionTabCornerWidgets.iand(QStyleOptionTab::QStyleOptionTabCornerWidgets other);
KMETHOD QStyleOptionTabCornerWidgets_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionTab::CornerWidgets *qp = RawPtr_to(QStyleOptionTab::CornerWidgets*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionTab::CornerWidgets *other = RawPtr_to(QStyleOptionTab::CornerWidgets *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionTabCornerWidgets QStyleOptionTabCornerWidgets.or(QStyleOptionTabCornerWidgets f);
KMETHOD QStyleOptionTabCornerWidgets_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyleOptionTab::CornerWidgets *qp = RawPtr_to(QStyleOptionTab::CornerWidgets*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionTab::CornerWidgets *f = RawPtr_to(QStyleOptionTab::CornerWidgets*, sfp[1]);
		QStyleOptionTab::CornerWidgets ret = ((*qp) | (*f));
		QStyleOptionTab::CornerWidgets *ret_ = new QStyleOptionTab::CornerWidgets(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionTabCornerWidgets QStyleOptionTabCornerWidgets.ior(QStyleOptionTab::QStyleOptionTabCornerWidgets other);
KMETHOD QStyleOptionTabCornerWidgets_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionTab::CornerWidgets *qp = RawPtr_to(QStyleOptionTab::CornerWidgets*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionTab::CornerWidgets *other = RawPtr_to(QStyleOptionTab::CornerWidgets *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionTabCornerWidgets QStyleOptionTabCornerWidgets.xor(QStyleOptionTabCornerWidgets f);
KMETHOD QStyleOptionTabCornerWidgets_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyleOptionTab::CornerWidgets *qp = RawPtr_to(QStyleOptionTab::CornerWidgets*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionTab::CornerWidgets *f = RawPtr_to(QStyleOptionTab::CornerWidgets*, sfp[1]);
		QStyleOptionTab::CornerWidgets ret = ((*qp) ^ (*f));
		QStyleOptionTab::CornerWidgets *ret_ = new QStyleOptionTab::CornerWidgets(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionTabCornerWidgets QStyleOptionTabCornerWidgets.ixor(QStyleOptionTab::QStyleOptionTabCornerWidgets other);
KMETHOD QStyleOptionTabCornerWidgets_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionTab::CornerWidgets *qp = RawPtr_to(QStyleOptionTab::CornerWidgets*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionTab::CornerWidgets *other = RawPtr_to(QStyleOptionTab::CornerWidgets *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QStyleOptionTabCornerWidgets.testFlag(int flag);
KMETHOD QStyleOptionTabCornerWidgets_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionTab::CornerWidgets *qp = RawPtr_to(QStyleOptionTab::CornerWidgets *, sfp[0]);
	if (qp != NULL) {
		QStyleOptionTab::CornerWidget flag = Int_to(QStyleOptionTab::CornerWidget, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QStyleOptionTabCornerWidgets.value();
KMETHOD QStyleOptionTabCornerWidgets_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionTab::CornerWidgets *qp = RawPtr_to(QStyleOptionTab::CornerWidgets *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QStyleOptionTabCornerWidgets_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QStyleOptionTab::CornerWidgets *qp = (QStyleOptionTab::CornerWidgets *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QStyleOptionTabCornerWidgets_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QStyleOptionTab::CornerWidgets *qp = (QStyleOptionTab::CornerWidgets *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionTabCornerWidgets_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QStyleOptionTab::CornerWidgets*)p1->rawptr);
//		int v2 = int(*(QStyleOptionTab::CornerWidgets*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QStyleOptionTab::CornerWidgets v1 = *(QStyleOptionTab::CornerWidgets*)p1->rawptr;
		QStyleOptionTab::CornerWidgets v2 = *(QStyleOptionTab::CornerWidgets*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQStyleOptionTabCornerWidgets(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionTabCornerWidgets";
	cdef->free = QStyleOptionTabCornerWidgets_free;
	cdef->reftrace = QStyleOptionTabCornerWidgets_reftrace;
	cdef->compareTo = QStyleOptionTabCornerWidgets_compareTo;
}

