//QHoverEvent QHoverEvent.new(int type, QPoint pos, QPoint oldPos);
KMETHOD QHoverEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHoverEvent::Type type = Int_to(QHoverEvent::Type, sfp[1]);
	const QPoint  pos = *RawPtr_to(const QPoint *, sfp[2]);
	const QPoint  oldPos = *RawPtr_to(const QPoint *, sfp[3]);
	KQHoverEvent *ret_v = new KQHoverEvent(type, pos, oldPos);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QPoint QHoverEvent.oldPos();
KMETHOD QHoverEvent_oldPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHoverEvent *  qp = RawPtr_to(QHoverEvent *, sfp[0]);
	if (qp) {
		const QPoint ret_v = qp->oldPos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QHoverEvent.pos();
KMETHOD QHoverEvent_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHoverEvent *  qp = RawPtr_to(QHoverEvent *, sfp[0]);
	if (qp) {
		const QPoint ret_v = qp->pos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQHoverEvent::DummyQHoverEvent()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQHoverEvent::~DummyQHoverEvent()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQHoverEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQHoverEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQHoverEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQHoverEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHoverEvent::event_map->bigin();
	if ((itr = DummyQHoverEvent::event_map->find(str)) == DummyQHoverEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQHoverEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHoverEvent::slot_map->bigin();
	if ((itr = DummyQHoverEvent::slot_map->find(str)) == DummyQHoverEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQHoverEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQHoverEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQHoverEvent::connection(QObject *o)
{
	QHoverEvent *p = dynamic_cast<QHoverEvent*>(o);
	if (p != NULL) {
	}
	DummyQEvent::connection(o);
}

KQHoverEvent::KQHoverEvent(QHoverEvent::Type type, const QPoint pos, const QPoint oldPos) : QHoverEvent(type, pos, oldPos)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQHoverEvent();
}

KQHoverEvent::~KQHoverEvent()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QHoverEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHoverEvent *qp = RawPtr_to(KQHoverEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QHoverEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHoverEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QHoverEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHoverEvent *qp = RawPtr_to(KQHoverEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QHoverEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHoverEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QHoverEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQHoverEvent *qp = (KQHoverEvent *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QHoverEvent*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QHoverEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQHoverEvent *qp = (KQHoverEvent *)p->rawptr;
		KQHoverEvent *qp = static_cast<KQHoverEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QHoverEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQHoverEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQHoverEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QHoverEvent";
	cdef->free = QHoverEvent_free;
	cdef->reftrace = QHoverEvent_reftrace;
	cdef->compareTo = QHoverEvent_compareTo;
}


