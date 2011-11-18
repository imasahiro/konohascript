//QDynamicPropertyChangeEvent QDynamicPropertyChangeEvent.new(QByteArray name);
KMETHOD QDynamicPropertyChangeEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QByteArray  name = *RawPtr_to(const QByteArray *, sfp[1]);
	KQDynamicPropertyChangeEvent *ret_v = new KQDynamicPropertyChangeEvent(name);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QByteArray QDynamicPropertyChangeEvent.propertyName();
KMETHOD QDynamicPropertyChangeEvent_propertyName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDynamicPropertyChangeEvent *  qp = RawPtr_to(QDynamicPropertyChangeEvent *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->propertyName();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQDynamicPropertyChangeEvent::DummyQDynamicPropertyChangeEvent()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQDynamicPropertyChangeEvent::~DummyQDynamicPropertyChangeEvent()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQDynamicPropertyChangeEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDynamicPropertyChangeEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQDynamicPropertyChangeEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQDynamicPropertyChangeEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDynamicPropertyChangeEvent::event_map->bigin();
	if ((itr = DummyQDynamicPropertyChangeEvent::event_map->find(str)) == DummyQDynamicPropertyChangeEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDynamicPropertyChangeEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDynamicPropertyChangeEvent::slot_map->bigin();
	if ((itr = DummyQDynamicPropertyChangeEvent::slot_map->find(str)) == DummyQDynamicPropertyChangeEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQDynamicPropertyChangeEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQDynamicPropertyChangeEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQDynamicPropertyChangeEvent::connection(QObject *o)
{
	QDynamicPropertyChangeEvent *p = dynamic_cast<QDynamicPropertyChangeEvent*>(o);
	if (p != NULL) {
	}
	DummyQEvent::connection(o);
}

KQDynamicPropertyChangeEvent::KQDynamicPropertyChangeEvent(const QByteArray name) : QDynamicPropertyChangeEvent(name)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQDynamicPropertyChangeEvent();
}

KQDynamicPropertyChangeEvent::~KQDynamicPropertyChangeEvent()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QDynamicPropertyChangeEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDynamicPropertyChangeEvent *qp = RawPtr_to(KQDynamicPropertyChangeEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDynamicPropertyChangeEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDynamicPropertyChangeEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QDynamicPropertyChangeEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDynamicPropertyChangeEvent *qp = RawPtr_to(KQDynamicPropertyChangeEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDynamicPropertyChangeEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDynamicPropertyChangeEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDynamicPropertyChangeEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQDynamicPropertyChangeEvent *qp = (KQDynamicPropertyChangeEvent *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QDynamicPropertyChangeEvent*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QDynamicPropertyChangeEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQDynamicPropertyChangeEvent *qp = (KQDynamicPropertyChangeEvent *)p->rawptr;
		KQDynamicPropertyChangeEvent *qp = static_cast<KQDynamicPropertyChangeEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QDynamicPropertyChangeEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQDynamicPropertyChangeEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQDynamicPropertyChangeEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDynamicPropertyChangeEvent";
	cdef->free = QDynamicPropertyChangeEvent_free;
	cdef->reftrace = QDynamicPropertyChangeEvent_reftrace;
	cdef->compareTo = QDynamicPropertyChangeEvent_compareTo;
}


