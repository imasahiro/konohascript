//QGenericReturnArgument QGenericReturnArgument.new(String name, void data);
KMETHOD QGenericReturnArgument_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const char*  name = RawPtr_to(const char*, sfp[1]);
	void*  data = RawPtr_to(void*, sfp[2]);
	KQGenericReturnArgument *ret_v = new KQGenericReturnArgument(name, data);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}


DummyQGenericReturnArgument::DummyQGenericReturnArgument()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGenericReturnArgument::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGenericReturnArgument::self = ptr;
	DummyQGenericArgument::setSelf(ptr);
}

bool DummyQGenericReturnArgument::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGenericArgument::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGenericReturnArgument::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGenericReturnArgument::event_map->bigin();
	if ((itr = DummyQGenericReturnArgument::event_map->find(str)) == DummyQGenericReturnArgument::event_map->end()) {
		bool ret = false;
		ret = DummyQGenericArgument::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGenericReturnArgument::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGenericReturnArgument::slot_map->bigin();
	if ((itr = DummyQGenericReturnArgument::slot_map->find(str)) == DummyQGenericReturnArgument::slot_map->end()) {
		bool ret = false;
		ret = DummyQGenericArgument::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGenericReturnArgument::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGenericReturnArgument::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQGenericArgument::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGenericReturnArgument::connection(QObject *o)
{
	QGenericReturnArgument *p = dynamic_cast<QGenericReturnArgument*>(o);
	if (p != NULL) {
	}
	DummyQGenericArgument::connection(o);
}

KQGenericReturnArgument::KQGenericReturnArgument(const char* name, void* data) : QGenericReturnArgument(name, data)
{
	self = NULL;
	dummy = new DummyQGenericReturnArgument();
}

KMETHOD QGenericReturnArgument_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGenericReturnArgument *qp = RawPtr_to(KQGenericReturnArgument *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGenericReturnArgument]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGenericReturnArgument]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGenericReturnArgument_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGenericReturnArgument *qp = RawPtr_to(KQGenericReturnArgument *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGenericReturnArgument]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGenericReturnArgument]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGenericReturnArgument_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGenericReturnArgument *qp = (KQGenericReturnArgument *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGenericReturnArgument_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGenericReturnArgument *qp = (KQGenericReturnArgument *)p->rawptr;
//		KQGenericReturnArgument *qp = static_cast<KQGenericReturnArgument*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGenericReturnArgument_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGenericReturnArgument::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQGenericReturnArgument(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGenericReturnArgument";
	cdef->free = QGenericReturnArgument_free;
	cdef->reftrace = QGenericReturnArgument_reftrace;
	cdef->compareTo = QGenericReturnArgument_compareTo;
}


