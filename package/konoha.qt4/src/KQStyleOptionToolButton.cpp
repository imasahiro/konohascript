//QStyleOptionToolButton QStyleOptionToolButton.new();
KMETHOD QStyleOptionToolButton_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionToolButton *ret_v = new KQStyleOptionToolButton();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionToolButton QStyleOptionToolButton.new(QStyleOptionToolButton other);
KMETHOD QStyleOptionToolButton_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionToolButton  other = *RawPtr_to(const QStyleOptionToolButton *, sfp[1]);
	KQStyleOptionToolButton *ret_v = new KQStyleOptionToolButton(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionToolButton::DummyQStyleOptionToolButton()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionToolButton::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionToolButton::self = ptr;
	DummyQStyleOptionComplex::setSelf(ptr);
}

bool DummyQStyleOptionToolButton::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionComplex::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionToolButton::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionToolButton::event_map->bigin();
	if ((itr = DummyQStyleOptionToolButton::event_map->find(str)) == DummyQStyleOptionToolButton::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionComplex::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionToolButton::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionToolButton::slot_map->bigin();
	if ((itr = DummyQStyleOptionToolButton::slot_map->find(str)) == DummyQStyleOptionToolButton::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionComplex::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQStyleOptionToolButton::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQStyleOptionComplex::reftrace(ctx, p, tail_);
}

void DummyQStyleOptionToolButton::connection(QObject *o)
{
	QStyleOptionToolButton *p = dynamic_cast<QStyleOptionToolButton*>(o);
	if (p != NULL) {
	}
	DummyQStyleOptionComplex::connection(o);
}

KQStyleOptionToolButton::KQStyleOptionToolButton() : QStyleOptionToolButton()
{
	self = NULL;
	dummy = new DummyQStyleOptionToolButton();
}

KMETHOD QStyleOptionToolButton_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionToolButton *qp = RawPtr_to(KQStyleOptionToolButton *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionToolButton]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionToolButton]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionToolButton_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionToolButton *qp = RawPtr_to(KQStyleOptionToolButton *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionToolButton]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionToolButton]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionToolButton_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionToolButton *qp = (KQStyleOptionToolButton *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionToolButton_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQStyleOptionToolButton *qp = (KQStyleOptionToolButton *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionToolButton_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionToolButton::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionToolButtonConstInt[] = {
	{"Type", QStyleOptionToolButton::Type},
	{"Version", QStyleOptionToolButton::Version},
	{"None", QStyleOptionToolButton::None},
	{"Arrow", QStyleOptionToolButton::Arrow},
	{"Menu", QStyleOptionToolButton::Menu},
	{"PopupDelay", QStyleOptionToolButton::PopupDelay},
	{"HasMenu", QStyleOptionToolButton::HasMenu},
	{"MenuButtonPopup", QStyleOptionToolButton::MenuButtonPopup},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionToolButton(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionToolButtonConstInt);
}


DEFAPI(void) defQStyleOptionToolButton(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionToolButton";
	cdef->free = QStyleOptionToolButton_free;
	cdef->reftrace = QStyleOptionToolButton_reftrace;
	cdef->compareTo = QStyleOptionToolButton_compareTo;
}

//## QStyleOptionToolButtonToolButtonFeatures QStyleOptionToolButtonToolButtonFeatures.new(int value);
KMETHOD QStyleOptionToolButtonToolButtonFeatures_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionToolButton::ToolButtonFeature i = Int_to(QStyleOptionToolButton::ToolButtonFeature, sfp[1]);
	QStyleOptionToolButton::ToolButtonFeatures *ret_v = new QStyleOptionToolButton::ToolButtonFeatures(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QStyleOptionToolButtonToolButtonFeatures QStyleOptionToolButtonToolButtonFeatures.and(int mask);
KMETHOD QStyleOptionToolButtonToolButtonFeatures_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionToolButton::ToolButtonFeatures *qp = RawPtr_to(QStyleOptionToolButton::ToolButtonFeatures*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QStyleOptionToolButton::ToolButtonFeatures ret = ((*qp) & i);
		QStyleOptionToolButton::ToolButtonFeatures *ret_ = new QStyleOptionToolButton::ToolButtonFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionToolButtonToolButtonFeatures QStyleOptionToolButtonToolButtonFeatures.iand(QStyleOptionToolButton::QStyleOptionToolButtonToolButtonFeatures other);
KMETHOD QStyleOptionToolButtonToolButtonFeatures_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionToolButton::ToolButtonFeatures *qp = RawPtr_to(QStyleOptionToolButton::ToolButtonFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionToolButton::ToolButtonFeatures *other = RawPtr_to(QStyleOptionToolButton::ToolButtonFeatures *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionToolButtonToolButtonFeatures QStyleOptionToolButtonToolButtonFeatures.or(QStyleOptionToolButtonToolButtonFeatures f);
KMETHOD QStyleOptionToolButtonToolButtonFeatures_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyleOptionToolButton::ToolButtonFeatures *qp = RawPtr_to(QStyleOptionToolButton::ToolButtonFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionToolButton::ToolButtonFeatures *f = RawPtr_to(QStyleOptionToolButton::ToolButtonFeatures*, sfp[1]);
		QStyleOptionToolButton::ToolButtonFeatures ret = ((*qp) | (*f));
		QStyleOptionToolButton::ToolButtonFeatures *ret_ = new QStyleOptionToolButton::ToolButtonFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionToolButtonToolButtonFeatures QStyleOptionToolButtonToolButtonFeatures.ior(QStyleOptionToolButton::QStyleOptionToolButtonToolButtonFeatures other);
KMETHOD QStyleOptionToolButtonToolButtonFeatures_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionToolButton::ToolButtonFeatures *qp = RawPtr_to(QStyleOptionToolButton::ToolButtonFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionToolButton::ToolButtonFeatures *other = RawPtr_to(QStyleOptionToolButton::ToolButtonFeatures *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionToolButtonToolButtonFeatures QStyleOptionToolButtonToolButtonFeatures.xor(QStyleOptionToolButtonToolButtonFeatures f);
KMETHOD QStyleOptionToolButtonToolButtonFeatures_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QStyleOptionToolButton::ToolButtonFeatures *qp = RawPtr_to(QStyleOptionToolButton::ToolButtonFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionToolButton::ToolButtonFeatures *f = RawPtr_to(QStyleOptionToolButton::ToolButtonFeatures*, sfp[1]);
		QStyleOptionToolButton::ToolButtonFeatures ret = ((*qp) ^ (*f));
		QStyleOptionToolButton::ToolButtonFeatures *ret_ = new QStyleOptionToolButton::ToolButtonFeatures(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QStyleOptionToolButtonToolButtonFeatures QStyleOptionToolButtonToolButtonFeatures.ixor(QStyleOptionToolButton::QStyleOptionToolButtonToolButtonFeatures other);
KMETHOD QStyleOptionToolButtonToolButtonFeatures_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionToolButton::ToolButtonFeatures *qp = RawPtr_to(QStyleOptionToolButton::ToolButtonFeatures*, sfp[0]);
	if (qp != NULL) {
		QStyleOptionToolButton::ToolButtonFeatures *other = RawPtr_to(QStyleOptionToolButton::ToolButtonFeatures *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QStyleOptionToolButtonToolButtonFeatures.testFlag(int flag);
KMETHOD QStyleOptionToolButtonToolButtonFeatures_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionToolButton::ToolButtonFeatures *qp = RawPtr_to(QStyleOptionToolButton::ToolButtonFeatures *, sfp[0]);
	if (qp != NULL) {
		QStyleOptionToolButton::ToolButtonFeature flag = Int_to(QStyleOptionToolButton::ToolButtonFeature, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QStyleOptionToolButtonToolButtonFeatures.value();
KMETHOD QStyleOptionToolButtonToolButtonFeatures_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QStyleOptionToolButton::ToolButtonFeatures *qp = RawPtr_to(QStyleOptionToolButton::ToolButtonFeatures *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QStyleOptionToolButtonToolButtonFeatures_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QStyleOptionToolButton::ToolButtonFeatures *qp = (QStyleOptionToolButton::ToolButtonFeatures *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QStyleOptionToolButtonToolButtonFeatures_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QStyleOptionToolButton::ToolButtonFeatures *qp = (QStyleOptionToolButton::ToolButtonFeatures *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionToolButtonToolButtonFeatures_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QStyleOptionToolButton::ToolButtonFeatures*)p1->rawptr);
//		int v2 = int(*(QStyleOptionToolButton::ToolButtonFeatures*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QStyleOptionToolButton::ToolButtonFeatures v1 = *(QStyleOptionToolButton::ToolButtonFeatures*)p1->rawptr;
		QStyleOptionToolButton::ToolButtonFeatures v2 = *(QStyleOptionToolButton::ToolButtonFeatures*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQStyleOptionToolButtonToolButtonFeatures(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionToolButtonToolButtonFeatures";
	cdef->free = QStyleOptionToolButtonToolButtonFeatures_free;
	cdef->reftrace = QStyleOptionToolButtonToolButtonFeatures_reftrace;
	cdef->compareTo = QStyleOptionToolButtonToolButtonFeatures_compareTo;
}

