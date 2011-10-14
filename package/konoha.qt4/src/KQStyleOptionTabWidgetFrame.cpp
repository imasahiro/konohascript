//QStyleOptionTabWidgetFrame QStyleOptionTabWidgetFrame.new();
KMETHOD QStyleOptionTabWidgetFrame_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabWidgetFrame *ret_v = new KQStyleOptionTabWidgetFrame();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionTabWidgetFrame QStyleOptionTabWidgetFrame.new(QStyleOptionTabWidgetFrame other);
KMETHOD QStyleOptionTabWidgetFrame_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionTabWidgetFrame  other = *RawPtr_to(const QStyleOptionTabWidgetFrame *, sfp[1]);
	KQStyleOptionTabWidgetFrame *ret_v = new KQStyleOptionTabWidgetFrame(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionTabWidgetFrame::DummyQStyleOptionTabWidgetFrame()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionTabWidgetFrame::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionTabWidgetFrame::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionTabWidgetFrame::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionTabWidgetFrame::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTabWidgetFrame::event_map->bigin();
	if ((itr = DummyQStyleOptionTabWidgetFrame::event_map->find(str)) == DummyQStyleOptionTabWidgetFrame::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionTabWidgetFrame::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionTabWidgetFrame::slot_map->bigin();
	if ((itr = DummyQStyleOptionTabWidgetFrame::slot_map->find(str)) == DummyQStyleOptionTabWidgetFrame::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQStyleOptionTabWidgetFrame::connection(QObject *o)
{
	DummyQStyleOption::connection(o);
}

KQStyleOptionTabWidgetFrame::KQStyleOptionTabWidgetFrame() : QStyleOptionTabWidgetFrame()
{
	self = NULL;
	dummy = new DummyQStyleOptionTabWidgetFrame();
	dummy->connection((QObject*)this);
}

KMETHOD QStyleOptionTabWidgetFrame_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabWidgetFrame *qp = RawPtr_to(KQStyleOptionTabWidgetFrame *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTabWidgetFrame]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTabWidgetFrame]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionTabWidgetFrame_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionTabWidgetFrame *qp = RawPtr_to(KQStyleOptionTabWidgetFrame *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionTabWidgetFrame]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionTabWidgetFrame]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionTabWidgetFrame_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionTabWidgetFrame *qp = (KQStyleOptionTabWidgetFrame *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionTabWidgetFrame_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQStyleOptionTabWidgetFrame *qp = (KQStyleOptionTabWidgetFrame *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionTabWidgetFrame_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionTabWidgetFrame::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQStyleOptionTabWidgetFrame(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionTabWidgetFrame";
	cdef->free = QStyleOptionTabWidgetFrame_free;
	cdef->reftrace = QStyleOptionTabWidgetFrame_reftrace;
	cdef->compareTo = QStyleOptionTabWidgetFrame_compareTo;
}

static knh_IntData_t QStyleOptionTabWidgetFrameConstInt[] = {
	{"Type", QStyleOptionTabWidgetFrame::Type},
	{"Version", QStyleOptionTabWidgetFrame::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionTabWidgetFrame(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionTabWidgetFrameConstInt);
}

