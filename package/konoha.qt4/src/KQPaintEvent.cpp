//QPaintEvent QPaintEvent.new(QRegion paintRegion);
KMETHOD QPaintEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QRegion  paintRegion = *RawPtr_to(const QRegion *, sfp[1]);
	KQPaintEvent *ret_v = new KQPaintEvent(paintRegion);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPaintEvent QPaintEvent.new(QRect paintRect);
KMETHOD QPaintEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QRect  paintRect = *RawPtr_to(const QRect *, sfp[1]);
	KQPaintEvent *ret_v = new KQPaintEvent(paintRect);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QRect QPaintEvent.rect();
KMETHOD QPaintEvent_rect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEvent *  qp = RawPtr_to(QPaintEvent *, sfp[0]);
	if (qp != NULL) {
		const QRect ret_v = qp->rect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRegion QPaintEvent.region();
KMETHOD QPaintEvent_region(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintEvent *  qp = RawPtr_to(QPaintEvent *, sfp[0]);
	if (qp != NULL) {
		const QRegion ret_v = qp->region();
		QRegion *ret_v_ = new QRegion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQPaintEvent::DummyQPaintEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPaintEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPaintEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQPaintEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQPaintEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPaintEvent::event_map->bigin();
	if ((itr = DummyQPaintEvent::event_map->find(str)) == DummyQPaintEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPaintEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPaintEvent::slot_map->bigin();
	if ((itr = DummyQPaintEvent::slot_map->find(str)) == DummyQPaintEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQPaintEvent::connection(QObject *o)
{
	DummyQEvent::connection(o);
}

KQPaintEvent::KQPaintEvent(const QRegion paintRegion) : QPaintEvent(paintRegion)
{
	self = NULL;
	dummy = new DummyQPaintEvent();
	dummy->connection((QObject*)this);
}

KMETHOD QPaintEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPaintEvent *qp = RawPtr_to(KQPaintEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPaintEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPaintEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPaintEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPaintEvent *qp = RawPtr_to(KQPaintEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPaintEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPaintEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPaintEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPaintEvent *qp = (KQPaintEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPaintEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQPaintEvent *qp = (KQPaintEvent *)p->rawptr;
		(void)qp;
	}
}

static int QPaintEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQPaintEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQPaintEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPaintEvent";
	cdef->free = QPaintEvent_free;
	cdef->reftrace = QPaintEvent_reftrace;
	cdef->compareTo = QPaintEvent_compareTo;
}


