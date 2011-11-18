//QStyleOptionToolBar QStyleOptionToolBar.new();
KMETHOD QStyleOptionToolBar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionToolBar *ret_v = new KQStyleOptionToolBar();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionToolBar QStyleOptionToolBar.new(QStyleOptionToolBar other);
KMETHOD QStyleOptionToolBar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionToolBar  other = *RawPtr_to(const QStyleOptionToolBar *, sfp[1]);
	KQStyleOptionToolBar *ret_v = new KQStyleOptionToolBar(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionToolBar::DummyQStyleOptionToolBar()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQStyleOptionToolBar::~DummyQStyleOptionToolBar()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQStyleOptionToolBar::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionToolBar::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionToolBar::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionToolBar::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionToolBar::event_map->bigin();
	if ((itr = DummyQStyleOptionToolBar::event_map->find(str)) == DummyQStyleOptionToolBar::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionToolBar::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionToolBar::slot_map->bigin();
	if ((itr = DummyQStyleOptionToolBar::slot_map->find(str)) == DummyQStyleOptionToolBar::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyleOptionToolBar::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionToolBar::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOption::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionToolBar::connection(QObject *o)
{
	QStyleOptionToolBar *p = dynamic_cast<QStyleOptionToolBar*>(o);
	if (p != NULL) {
	}
	DummyQStyleOption::connection(o);
}

KQStyleOptionToolBar::KQStyleOptionToolBar() : QStyleOptionToolBar()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQStyleOptionToolBar();
}

KQStyleOptionToolBar::~KQStyleOptionToolBar()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QStyleOptionToolBar_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionToolBar *qp = RawPtr_to(KQStyleOptionToolBar *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionToolBar]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionToolBar]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionToolBar_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionToolBar *qp = RawPtr_to(KQStyleOptionToolBar *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionToolBar]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionToolBar]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionToolBar_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQStyleOptionToolBar *qp = (KQStyleOptionToolBar *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QStyleOptionToolBar*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QStyleOptionToolBar_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQStyleOptionToolBar *qp = (KQStyleOptionToolBar *)p->rawptr;
		KQStyleOptionToolBar *qp = static_cast<KQStyleOptionToolBar*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionToolBar_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionToolBar::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionToolBarConstInt[] = {
	{"Type", QStyleOptionToolBar::Type},
	{"Version", QStyleOptionToolBar::Version},
	{"None", QStyleOptionToolBar::None},
	{"Movable", QStyleOptionToolBar::Movable},
	{"Beginning", QStyleOptionToolBar::Beginning},
	{"Middle", QStyleOptionToolBar::Middle},
	{"End", QStyleOptionToolBar::End},
	{"OnlyOne", QStyleOptionToolBar::OnlyOne},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionToolBar(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionToolBarConstInt);
}


DEFAPI(void) defQStyleOptionToolBar(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionToolBar";
	cdef->free = QStyleOptionToolBar_free;
	cdef->reftrace = QStyleOptionToolBar_reftrace;
	cdef->compareTo = QStyleOptionToolBar_compareTo;
}

//## QStyleOptionToolBarToolBarFeatures QStyleOptionToolBarToolBarFeatures.new(int value);
KMETHOD QStyleOptionToolBarToolBarFeatures_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionToolBar::ToolBarFeature i = Int_to(QStyleOptionToolBar::ToolBarFeature, sfp[1]);
	QStyleOptionToolBar::ToolBarFeatures *ret_v = new QStyleOptionToolBar::ToolBarFeatures(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QStyleOptionToolBarToolBarFeatures QStyleOptionToolBarToolBarFeatures.and(int mask);
KMETHOD QStyleOptionToolBarToolBarFeatures_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionToolBar::ToolBarFeatures *qp = RawPtr_to(QStyleOptionToolBar::ToolBarFeatures*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QStyleOptionToolBar::ToolBarFeatures ret = ((*qp) & i);
		QStyleOptionToolBar::ToolBarFeatures *ret_ = new QStyleOptionToolBar::ToolBarFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionToolBarToolBarFeatures QStyleOptionToolBarToolBarFeatures.iand(QStyleOptionToolBar::QStyleOptionToolBarToolBarFeatures other);
KMETHOD QStyleOptionToolBarToolBarFeatures_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionToolBar::ToolBarFeatures *qp = RawPtr_to(QStyleOptionToolBar::ToolBarFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionToolBar::ToolBarFeatures *other = RawPtr_to(QStyleOptionToolBar::ToolBarFeatures *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionToolBarToolBarFeatures QStyleOptionToolBarToolBarFeatures.or(QStyleOptionToolBarToolBarFeatures f);
KMETHOD QStyleOptionToolBarToolBarFeatures_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyleOptionToolBar::ToolBarFeatures *qp = RawPtr_to(QStyleOptionToolBar::ToolBarFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionToolBar::ToolBarFeatures *f = RawPtr_to(QStyleOptionToolBar::ToolBarFeatures*, sfp[1]);
		QStyleOptionToolBar::ToolBarFeatures ret = ((*qp) | (*f));
		QStyleOptionToolBar::ToolBarFeatures *ret_ = new QStyleOptionToolBar::ToolBarFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionToolBarToolBarFeatures QStyleOptionToolBarToolBarFeatures.ior(QStyleOptionToolBar::QStyleOptionToolBarToolBarFeatures other);
KMETHOD QStyleOptionToolBarToolBarFeatures_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionToolBar::ToolBarFeatures *qp = RawPtr_to(QStyleOptionToolBar::ToolBarFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionToolBar::ToolBarFeatures *other = RawPtr_to(QStyleOptionToolBar::ToolBarFeatures *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionToolBarToolBarFeatures QStyleOptionToolBarToolBarFeatures.xor(QStyleOptionToolBarToolBarFeatures f);
KMETHOD QStyleOptionToolBarToolBarFeatures_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyleOptionToolBar::ToolBarFeatures *qp = RawPtr_to(QStyleOptionToolBar::ToolBarFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionToolBar::ToolBarFeatures *f = RawPtr_to(QStyleOptionToolBar::ToolBarFeatures*, sfp[1]);
		QStyleOptionToolBar::ToolBarFeatures ret = ((*qp) ^ (*f));
		QStyleOptionToolBar::ToolBarFeatures *ret_ = new QStyleOptionToolBar::ToolBarFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionToolBarToolBarFeatures QStyleOptionToolBarToolBarFeatures.ixor(QStyleOptionToolBar::QStyleOptionToolBarToolBarFeatures other);
KMETHOD QStyleOptionToolBarToolBarFeatures_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionToolBar::ToolBarFeatures *qp = RawPtr_to(QStyleOptionToolBar::ToolBarFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionToolBar::ToolBarFeatures *other = RawPtr_to(QStyleOptionToolBar::ToolBarFeatures *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QStyleOptionToolBarToolBarFeatures.testFlag(int flag);
KMETHOD QStyleOptionToolBarToolBarFeatures_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionToolBar::ToolBarFeatures *qp = RawPtr_to(QStyleOptionToolBar::ToolBarFeatures *, sfp[0]);
	if (qp != NULL) {
		QStyleOptionToolBar::ToolBarFeature flag = Int_to(QStyleOptionToolBar::ToolBarFeature, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QStyleOptionToolBarToolBarFeatures.value();
KMETHOD QStyleOptionToolBarToolBarFeatures_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionToolBar::ToolBarFeatures *qp = RawPtr_to(QStyleOptionToolBar::ToolBarFeatures *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QStyleOptionToolBarToolBarFeatures_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QStyleOptionToolBar::ToolBarFeatures *qp = (QStyleOptionToolBar::ToolBarFeatures *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QStyleOptionToolBarToolBarFeatures_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QStyleOptionToolBar::ToolBarFeatures *qp = (QStyleOptionToolBar::ToolBarFeatures *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionToolBarToolBarFeatures_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QStyleOptionToolBar::ToolBarFeatures*)p1->rawptr);
//		int v2 = int(*(QStyleOptionToolBar::ToolBarFeatures*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QStyleOptionToolBar::ToolBarFeatures v1 = *(QStyleOptionToolBar::ToolBarFeatures*)p1->rawptr;
		QStyleOptionToolBar::ToolBarFeatures v2 = *(QStyleOptionToolBar::ToolBarFeatures*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQStyleOptionToolBarToolBarFeatures(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionToolBarToolBarFeatures";
	cdef->free = QStyleOptionToolBarToolBarFeatures_free;
	cdef->reftrace = QStyleOptionToolBarToolBarFeatures_reftrace;
	cdef->compareTo = QStyleOptionToolBarToolBarFeatures_compareTo;
}

