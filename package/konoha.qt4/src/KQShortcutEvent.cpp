//QShortcutEvent QShortcutEvent.new(QKeySequence key, int id, boolean ambiguous);
KMETHOD QShortcutEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QKeySequence  key = *RawPtr_to(const QKeySequence *, sfp[1]);
	int id = Int_to(int, sfp[2]);
	bool ambiguous = Boolean_to(bool, sfp[3]);
	KQShortcutEvent *ret_v = new KQShortcutEvent(key, id, ambiguous);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QShortcutEvent.isAmbiguous();
KMETHOD QShortcutEvent_isAmbiguous(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QShortcutEvent *  qp = RawPtr_to(QShortcutEvent *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isAmbiguous();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QKeySequence QShortcutEvent.key();
KMETHOD QShortcutEvent_key(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QShortcutEvent *  qp = RawPtr_to(QShortcutEvent *, sfp[0]);
	if (qp) {
		const QKeySequence ret_v = qp->key();
		QKeySequence *ret_v_ = new QKeySequence(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QShortcutEvent.shortcutId();
KMETHOD QShortcutEvent_shortcutId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QShortcutEvent *  qp = RawPtr_to(QShortcutEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->shortcutId();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQShortcutEvent::DummyQShortcutEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQShortcutEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQShortcutEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQShortcutEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQShortcutEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQShortcutEvent::event_map->bigin();
	if ((itr = DummyQShortcutEvent::event_map->find(str)) == DummyQShortcutEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQShortcutEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQShortcutEvent::slot_map->bigin();
	if ((itr = DummyQShortcutEvent::slot_map->find(str)) == DummyQShortcutEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQShortcutEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQShortcutEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQShortcutEvent::connection(QObject *o)
{
	QShortcutEvent *p = dynamic_cast<QShortcutEvent*>(o);
	if (p != NULL) {
	}
	DummyQEvent::connection(o);
}

KQShortcutEvent::KQShortcutEvent(const QKeySequence key, int id, bool ambiguous) : QShortcutEvent(key, id, ambiguous)
{
	self = NULL;
	dummy = new DummyQShortcutEvent();
}

KMETHOD QShortcutEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQShortcutEvent *qp = RawPtr_to(KQShortcutEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QShortcutEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QShortcutEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QShortcutEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQShortcutEvent *qp = RawPtr_to(KQShortcutEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QShortcutEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QShortcutEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QShortcutEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQShortcutEvent *qp = (KQShortcutEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QShortcutEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQShortcutEvent *qp = (KQShortcutEvent *)p->rawptr;
//		KQShortcutEvent *qp = static_cast<KQShortcutEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QShortcutEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQShortcutEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQShortcutEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QShortcutEvent";
	cdef->free = QShortcutEvent_free;
	cdef->reftrace = QShortcutEvent_reftrace;
	cdef->compareTo = QShortcutEvent_compareTo;
}


