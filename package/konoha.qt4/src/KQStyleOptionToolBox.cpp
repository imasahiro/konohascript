//QStyleOptionToolBox QStyleOptionToolBox.new();
KMETHOD QStyleOptionToolBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionToolBox *ret_v = new KQStyleOptionToolBox();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionToolBox QStyleOptionToolBox.new(QStyleOptionToolBox other);
KMETHOD QStyleOptionToolBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionToolBox  other = *RawPtr_to(const QStyleOptionToolBox *, sfp[1]);
	KQStyleOptionToolBox *ret_v = new KQStyleOptionToolBox(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionToolBox::DummyQStyleOptionToolBox()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionToolBox::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionToolBox::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionToolBox::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionToolBox::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionToolBox::event_map->bigin();
	if ((itr = DummyQStyleOptionToolBox::event_map->find(str)) == DummyQStyleOptionToolBox::event_map->end()) {
		bool ret;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionToolBox::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionToolBox::slot_map->bigin();
	if ((itr = DummyQStyleOptionToolBox::event_map->find(str)) == DummyQStyleOptionToolBox::slot_map->end()) {
		bool ret;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQStyleOptionToolBox::KQStyleOptionToolBox() : QStyleOptionToolBox()
{
	self = NULL;
}

KMETHOD QStyleOptionToolBox_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionToolBox *qp = RawPtr_to(KQStyleOptionToolBox *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionToolBox]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQStyleOptionToolBox::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionToolBox]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QStyleOptionToolBox_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionToolBox *qp = RawPtr_to(KQStyleOptionToolBox *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionToolBox]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQStyleOptionToolBox::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionToolBox]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionToolBox_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionToolBox *qp = (KQStyleOptionToolBox *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionToolBox_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQStyleOptionToolBox *qp = (KQStyleOptionToolBox *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionToolBox_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQStyleOptionToolBox(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionToolBox";
	cdef->free = QStyleOptionToolBox_free;
	cdef->reftrace = QStyleOptionToolBox_reftrace;
	cdef->compareTo = QStyleOptionToolBox_compareTo;
}

static knh_IntData_t QStyleOptionToolBoxConstInt[] = {
	{"Type", QStyleOptionToolBox::Type},
	{"Version", QStyleOptionToolBox::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionToolBox(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionToolBoxConstInt);
}

