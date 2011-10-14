//QHelpEvent QHelpEvent.new(int type, QPoint pos, QPoint globalPos);
KMETHOD QHelpEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHelpEvent::Type type = Int_to(QHelpEvent::Type, sfp[1]);
	const QPoint  pos = *RawPtr_to(const QPoint *, sfp[2]);
	const QPoint  globalPos = *RawPtr_to(const QPoint *, sfp[3]);
	KQHelpEvent *ret_v = new KQHelpEvent(type, pos, globalPos);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QPoint QHelpEvent.globalPos();
KMETHOD QHelpEvent_globalPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHelpEvent *  qp = RawPtr_to(QHelpEvent *, sfp[0]);
	if (qp != NULL) {
		const QPoint ret_v = qp->globalPos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QHelpEvent.globalX();
KMETHOD QHelpEvent_globalX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHelpEvent *  qp = RawPtr_to(QHelpEvent *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->globalX();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QHelpEvent.globalY();
KMETHOD QHelpEvent_globalY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHelpEvent *  qp = RawPtr_to(QHelpEvent *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->globalY();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPoint QHelpEvent.pos();
KMETHOD QHelpEvent_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHelpEvent *  qp = RawPtr_to(QHelpEvent *, sfp[0]);
	if (qp != NULL) {
		const QPoint ret_v = qp->pos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QHelpEvent.x();
KMETHOD QHelpEvent_x(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHelpEvent *  qp = RawPtr_to(QHelpEvent *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->x();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QHelpEvent.y();
KMETHOD QHelpEvent_y(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHelpEvent *  qp = RawPtr_to(QHelpEvent *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->y();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQHelpEvent::DummyQHelpEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQHelpEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQHelpEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQHelpEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQHelpEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHelpEvent::event_map->bigin();
	if ((itr = DummyQHelpEvent::event_map->find(str)) == DummyQHelpEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQHelpEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHelpEvent::slot_map->bigin();
	if ((itr = DummyQHelpEvent::slot_map->find(str)) == DummyQHelpEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQHelpEvent::connection(QObject *o)
{
	DummyQEvent::connection(o);
}

KQHelpEvent::KQHelpEvent(QHelpEvent::Type type, const QPoint pos, const QPoint globalPos) : QHelpEvent(type, pos, globalPos)
{
	self = NULL;
	dummy = new DummyQHelpEvent();
	dummy->connection((QObject*)this);
}

KMETHOD QHelpEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHelpEvent *qp = RawPtr_to(KQHelpEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QHelpEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHelpEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QHelpEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHelpEvent *qp = RawPtr_to(KQHelpEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QHelpEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHelpEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QHelpEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQHelpEvent *qp = (KQHelpEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QHelpEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQHelpEvent *qp = (KQHelpEvent *)p->rawptr;
		(void)qp;
	}
}

static int QHelpEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQHelpEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQHelpEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QHelpEvent";
	cdef->free = QHelpEvent_free;
	cdef->reftrace = QHelpEvent_reftrace;
	cdef->compareTo = QHelpEvent_compareTo;
}


