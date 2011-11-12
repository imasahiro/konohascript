//QContextMenuEvent QContextMenuEvent.new(int reason, QPoint pos, QPoint globalPos, QtKeyboardModifiers modifiers);
KMETHOD QContextMenuEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QContextMenuEvent::Reason reason = Int_to(QContextMenuEvent::Reason, sfp[1]);
	const QPoint  pos = *RawPtr_to(const QPoint *, sfp[2]);
	const QPoint  globalPos = *RawPtr_to(const QPoint *, sfp[3]);
	initFlag(modifiers, Qt::KeyboardModifiers, sfp[4]);
	KQContextMenuEvent *ret_v = new KQContextMenuEvent(reason, pos, globalPos, modifiers);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QContextMenuEvent QContextMenuEvent.new(int reason, QPoint pos, QPoint globalPos);
KMETHOD QContextMenuEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QContextMenuEvent::Reason reason = Int_to(QContextMenuEvent::Reason, sfp[1]);
	const QPoint  pos = *RawPtr_to(const QPoint *, sfp[2]);
	const QPoint  globalPos = *RawPtr_to(const QPoint *, sfp[3]);
	KQContextMenuEvent *ret_v = new KQContextMenuEvent(reason, pos, globalPos);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QContextMenuEvent QContextMenuEvent.new(int reason, QPoint pos);
KMETHOD QContextMenuEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QContextMenuEvent::Reason reason = Int_to(QContextMenuEvent::Reason, sfp[1]);
	const QPoint  pos = *RawPtr_to(const QPoint *, sfp[2]);
	KQContextMenuEvent *ret_v = new KQContextMenuEvent(reason, pos);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QPoint QContextMenuEvent.globalPos();
KMETHOD QContextMenuEvent_globalPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QContextMenuEvent *  qp = RawPtr_to(QContextMenuEvent *, sfp[0]);
	if (qp) {
		const QPoint ret_v = qp->globalPos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QContextMenuEvent.globalX();
KMETHOD QContextMenuEvent_globalX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QContextMenuEvent *  qp = RawPtr_to(QContextMenuEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->globalX();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QContextMenuEvent.globalY();
KMETHOD QContextMenuEvent_globalY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QContextMenuEvent *  qp = RawPtr_to(QContextMenuEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->globalY();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPoint QContextMenuEvent.pos();
KMETHOD QContextMenuEvent_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QContextMenuEvent *  qp = RawPtr_to(QContextMenuEvent *, sfp[0]);
	if (qp) {
		const QPoint ret_v = qp->pos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QContextMenuEvent.reason();
KMETHOD QContextMenuEvent_reason(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QContextMenuEvent *  qp = RawPtr_to(QContextMenuEvent *, sfp[0]);
	if (qp) {
		QContextMenuEvent::Reason ret_v = qp->reason();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QContextMenuEvent.x();
KMETHOD QContextMenuEvent_x(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QContextMenuEvent *  qp = RawPtr_to(QContextMenuEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->x();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QContextMenuEvent.y();
KMETHOD QContextMenuEvent_y(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QContextMenuEvent *  qp = RawPtr_to(QContextMenuEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->y();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQContextMenuEvent::DummyQContextMenuEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQContextMenuEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQContextMenuEvent::self = ptr;
	DummyQInputEvent::setSelf(ptr);
}

bool DummyQContextMenuEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQInputEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQContextMenuEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQContextMenuEvent::event_map->bigin();
	if ((itr = DummyQContextMenuEvent::event_map->find(str)) == DummyQContextMenuEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQInputEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQContextMenuEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQContextMenuEvent::slot_map->bigin();
	if ((itr = DummyQContextMenuEvent::slot_map->find(str)) == DummyQContextMenuEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQInputEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQContextMenuEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQContextMenuEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQInputEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQContextMenuEvent::connection(QObject *o)
{
	QContextMenuEvent *p = dynamic_cast<QContextMenuEvent*>(o);
	if (p != NULL) {
	}
	DummyQInputEvent::connection(o);
}

KQContextMenuEvent::KQContextMenuEvent(QContextMenuEvent::Reason reason, const QPoint pos, const QPoint globalPos, Qt::KeyboardModifiers modifiers) : QContextMenuEvent(reason, pos, globalPos, modifiers)
{
	self = NULL;
	dummy = new DummyQContextMenuEvent();
}

KMETHOD QContextMenuEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQContextMenuEvent *qp = RawPtr_to(KQContextMenuEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QContextMenuEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QContextMenuEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QContextMenuEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQContextMenuEvent *qp = RawPtr_to(KQContextMenuEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QContextMenuEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QContextMenuEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QContextMenuEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQContextMenuEvent *qp = (KQContextMenuEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QContextMenuEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQContextMenuEvent *qp = (KQContextMenuEvent *)p->rawptr;
//		KQContextMenuEvent *qp = static_cast<KQContextMenuEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QContextMenuEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQContextMenuEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QContextMenuEventConstInt[] = {
	{"Mouse", QContextMenuEvent::Mouse},
	{"Keyboard", QContextMenuEvent::Keyboard},
	{"Other", QContextMenuEvent::Other},
	{NULL, 0}
};

DEFAPI(void) constQContextMenuEvent(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QContextMenuEventConstInt);
}


DEFAPI(void) defQContextMenuEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QContextMenuEvent";
	cdef->free = QContextMenuEvent_free;
	cdef->reftrace = QContextMenuEvent_reftrace;
	cdef->compareTo = QContextMenuEvent_compareTo;
}


