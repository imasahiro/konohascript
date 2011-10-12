//QStyleOptionFrame QStyleOptionFrame.new();
KMETHOD QStyleOptionFrame_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionFrame *ret_v = new KQStyleOptionFrame();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionFrame QStyleOptionFrame.new(QStyleOptionFrame other);
KMETHOD QStyleOptionFrame_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionFrame  other = *RawPtr_to(const QStyleOptionFrame *, sfp[1]);
	KQStyleOptionFrame *ret_v = new KQStyleOptionFrame(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionFrame::DummyQStyleOptionFrame()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionFrame::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionFrame::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionFrame::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionFrame::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionFrame::event_map->bigin();
	if ((itr = DummyQStyleOptionFrame::event_map->find(str)) == DummyQStyleOptionFrame::event_map->end()) {
		bool ret;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionFrame::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionFrame::slot_map->bigin();
	if ((itr = DummyQStyleOptionFrame::event_map->find(str)) == DummyQStyleOptionFrame::slot_map->end()) {
		bool ret;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQStyleOptionFrame::KQStyleOptionFrame() : QStyleOptionFrame()
{
	self = NULL;
}

KMETHOD QStyleOptionFrame_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionFrame *qp = RawPtr_to(KQStyleOptionFrame *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionFrame]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQStyleOptionFrame::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionFrame]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QStyleOptionFrame_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionFrame *qp = RawPtr_to(KQStyleOptionFrame *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionFrame]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQStyleOptionFrame::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionFrame]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionFrame_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionFrame *qp = (KQStyleOptionFrame *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionFrame_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQStyleOptionFrame *qp = (KQStyleOptionFrame *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionFrame_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQStyleOptionFrame(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionFrame";
	cdef->free = QStyleOptionFrame_free;
	cdef->reftrace = QStyleOptionFrame_reftrace;
	cdef->compareTo = QStyleOptionFrame_compareTo;
}

static knh_IntData_t QStyleOptionFrameConstInt[] = {
	{"Type", QStyleOptionFrame::Type},
	{"Version", QStyleOptionFrame::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionFrame(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionFrameConstInt);
}

