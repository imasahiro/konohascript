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


void DummyQStyleOptionButton::connection(QObject *o)
{
	DummyQStyleOption::connection(o);
}

KQStyleOptionButton::KQStyleOptionButton() : QStyleOptionButton()
{
	self = NULL;
	dummy = new DummyQStyleOptionButton();
	dummy->connection((QObject*)this);
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
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQStyleOptionButton *qp = (KQStyleOptionButton *)p->rawptr;
		(void)qp;
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

DEFAPI(void) defQStyleOptionButton(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionButton";
	cdef->free = QStyleOptionButton_free;
	cdef->reftrace = QStyleOptionButton_reftrace;
	cdef->compareTo = QStyleOptionButton_compareTo;
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

