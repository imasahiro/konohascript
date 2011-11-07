//QStyleOptionButton QStyleOptionButton.new();
KMETHOD QStyleOptionButton_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionButton *ret_v = new KQStyleOptionButton();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionButton QStyleOptionButton.new(QStyleOptionButton other);
KMETHOD QStyleOptionButton_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionButton  other = *RawPtr_to(const QStyleOptionButton *, sfp[1]);
	KQStyleOptionButton *ret_v = new KQStyleOptionButton(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionButton::DummyQStyleOptionButton()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionButton::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionButton::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionButton::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionButton::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionButton::event_map->bigin();
	if ((itr = DummyQStyleOptionButton::event_map->find(str)) == DummyQStyleOptionButton::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionButton::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionButton::slot_map->bigin();
	if ((itr = DummyQStyleOptionButton::slot_map->find(str)) == DummyQStyleOptionButton::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQStyleOptionButton::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQStyleOption::reftrace(ctx, p, tail_);
}

void DummyQStyleOptionButton::connection(QObject *o)
{
	QStyleOptionButton *p = dynamic_cast<QStyleOptionButton*>(o);
	if (p != NULL) {
	}
	DummyQStyleOption::connection(o);
}

KQStyleOptionButton::KQStyleOptionButton() : QStyleOptionButton()
{
	self = NULL;
	dummy = new DummyQStyleOptionButton();
}

KMETHOD QStyleOptionButton_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionButton *qp = RawPtr_to(KQStyleOptionButton *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionButton]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionButton]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionButton_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionButton *qp = RawPtr_to(KQStyleOptionButton *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionButton]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionButton]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionButton_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionButton *qp = (KQStyleOptionButton *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionButton_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQStyleOptionButton *qp = (KQStyleOptionButton *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionButton_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionButton::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionButtonConstInt[] = {
	{"None", QStyleOptionButton::None},
	{"Flat", QStyleOptionButton::Flat},
	{"HasMenu", QStyleOptionButton::HasMenu},
	{"DefaultButton", QStyleOptionButton::DefaultButton},
	{"AutoDefaultButton", QStyleOptionButton::AutoDefaultButton},
	{"CommandLinkButton", QStyleOptionButton::CommandLinkButton},
	{"Type", QStyleOptionButton::Type},
	{"Version", QStyleOptionButton::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionButton(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionButtonConstInt);
}


DEFAPI(void) defQStyleOptionButton(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionButton";
	cdef->free = QStyleOptionButton_free;
	cdef->reftrace = QStyleOptionButton_reftrace;
	cdef->compareTo = QStyleOptionButton_compareTo;
}

//## QStyleOptionButtonButtonFeatures QStyleOptionButtonButtonFeatures.new(int value);
KMETHOD QStyleOptionButtonButtonFeatures_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionButton::ButtonFeature i = Int_to(QStyleOptionButton::ButtonFeature, sfp[1]);
	QStyleOptionButton::ButtonFeatures *ret_v = new QStyleOptionButton::ButtonFeatures(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QStyleOptionButtonButtonFeatures QStyleOptionButtonButtonFeatures.and(int mask);
KMETHOD QStyleOptionButtonButtonFeatures_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionButton::ButtonFeatures *qp = RawPtr_to(QStyleOptionButton::ButtonFeatures*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QStyleOptionButton::ButtonFeatures ret = ((*qp) & i);
		QStyleOptionButton::ButtonFeatures *ret_ = new QStyleOptionButton::ButtonFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionButtonButtonFeatures QStyleOptionButtonButtonFeatures.iand(QStyleOptionButton::QStyleOptionButtonButtonFeatures other);
KMETHOD QStyleOptionButtonButtonFeatures_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionButton::ButtonFeatures *qp = RawPtr_to(QStyleOptionButton::ButtonFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionButton::ButtonFeatures *other = RawPtr_to(QStyleOptionButton::ButtonFeatures *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionButtonButtonFeatures QStyleOptionButtonButtonFeatures.or(QStyleOptionButtonButtonFeatures f);
KMETHOD QStyleOptionButtonButtonFeatures_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyleOptionButton::ButtonFeatures *qp = RawPtr_to(QStyleOptionButton::ButtonFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionButton::ButtonFeatures *f = RawPtr_to(QStyleOptionButton::ButtonFeatures*, sfp[1]);
		QStyleOptionButton::ButtonFeatures ret = ((*qp) | (*f));
		QStyleOptionButton::ButtonFeatures *ret_ = new QStyleOptionButton::ButtonFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionButtonButtonFeatures QStyleOptionButtonButtonFeatures.ior(QStyleOptionButton::QStyleOptionButtonButtonFeatures other);
KMETHOD QStyleOptionButtonButtonFeatures_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionButton::ButtonFeatures *qp = RawPtr_to(QStyleOptionButton::ButtonFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionButton::ButtonFeatures *other = RawPtr_to(QStyleOptionButton::ButtonFeatures *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionButtonButtonFeatures QStyleOptionButtonButtonFeatures.xor(QStyleOptionButtonButtonFeatures f);
KMETHOD QStyleOptionButtonButtonFeatures_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyleOptionButton::ButtonFeatures *qp = RawPtr_to(QStyleOptionButton::ButtonFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionButton::ButtonFeatures *f = RawPtr_to(QStyleOptionButton::ButtonFeatures*, sfp[1]);
		QStyleOptionButton::ButtonFeatures ret = ((*qp) ^ (*f));
		QStyleOptionButton::ButtonFeatures *ret_ = new QStyleOptionButton::ButtonFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionButtonButtonFeatures QStyleOptionButtonButtonFeatures.ixor(QStyleOptionButton::QStyleOptionButtonButtonFeatures other);
KMETHOD QStyleOptionButtonButtonFeatures_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionButton::ButtonFeatures *qp = RawPtr_to(QStyleOptionButton::ButtonFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionButton::ButtonFeatures *other = RawPtr_to(QStyleOptionButton::ButtonFeatures *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QStyleOptionButtonButtonFeatures.testFlag(int flag);
KMETHOD QStyleOptionButtonButtonFeatures_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionButton::ButtonFeatures *qp = RawPtr_to(QStyleOptionButton::ButtonFeatures *, sfp[0]);
	if (qp != NULL) {
		QStyleOptionButton::ButtonFeature flag = Int_to(QStyleOptionButton::ButtonFeature, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QStyleOptionButtonButtonFeatures.value();
KMETHOD QStyleOptionButtonButtonFeatures_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionButton::ButtonFeatures *qp = RawPtr_to(QStyleOptionButton::ButtonFeatures *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QStyleOptionButtonButtonFeatures_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QStyleOptionButton::ButtonFeatures *qp = (QStyleOptionButton::ButtonFeatures *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QStyleOptionButtonButtonFeatures_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QStyleOptionButton::ButtonFeatures *qp = (QStyleOptionButton::ButtonFeatures *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionButtonButtonFeatures_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QStyleOptionButton::ButtonFeatures*)p1->rawptr);
//		int v2 = int(*(QStyleOptionButton::ButtonFeatures*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QStyleOptionButton::ButtonFeatures v1 = *(QStyleOptionButton::ButtonFeatures*)p1->rawptr;
		QStyleOptionButton::ButtonFeatures v2 = *(QStyleOptionButton::ButtonFeatures*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQStyleOptionButtonButtonFeatures(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionButtonButtonFeatures";
	cdef->free = QStyleOptionButtonButtonFeatures_free;
	cdef->reftrace = QStyleOptionButtonButtonFeatures_reftrace;
	cdef->compareTo = QStyleOptionButtonButtonFeatures_compareTo;
}

