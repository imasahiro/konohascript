//QGenericArgument QGenericArgument.new(String name, void data);
KMETHOD QGenericArgument_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const char*  name = RawPtr_to(const char*, sfp[1]);
	const void*  data = RawPtr_to(const void*, sfp[2]);
	KQGenericArgument *ret_v = new KQGenericArgument(name, data);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QGenericArgument.data();
KMETHOD QGenericArgument_data(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGenericArgument *  qp = RawPtr_to(QGenericArgument *, sfp[0]);
	if (qp != NULL) {
		void* ret_v = qp->data();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (void*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QGenericArgument.name();
KMETHOD QGenericArgument_name(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGenericArgument *  qp = RawPtr_to(QGenericArgument *, sfp[0]);
	if (qp != NULL) {
		const char* ret_v = qp->name();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (char*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQGenericArgument::DummyQGenericArgument()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGenericArgument::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGenericArgument::self = ptr;
}

bool DummyQGenericArgument::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQGenericArgument::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGenericArgument::event_map->bigin();
	if ((itr = DummyQGenericArgument::event_map->find(str)) == DummyQGenericArgument::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGenericArgument::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGenericArgument::slot_map->bigin();
	if ((itr = DummyQGenericArgument::event_map->find(str)) == DummyQGenericArgument::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQGenericArgument::KQGenericArgument(const char* name, const void* data) : QGenericArgument(name, data)
{
	self = NULL;
}

KMETHOD QGenericArgument_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGenericArgument *qp = RawPtr_to(KQGenericArgument *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGenericArgument]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQGenericArgument::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGenericArgument]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QGenericArgument_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGenericArgument *qp = RawPtr_to(KQGenericArgument *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGenericArgument]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQGenericArgument::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGenericArgument]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGenericArgument_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGenericArgument *qp = (KQGenericArgument *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGenericArgument_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQGenericArgument *qp = (KQGenericArgument *)p->rawptr;
		(void)qp;
	}
}

static int QGenericArgument_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQGenericArgument(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGenericArgument";
	cdef->free = QGenericArgument_free;
	cdef->reftrace = QGenericArgument_reftrace;
	cdef->compareTo = QGenericArgument_compareTo;
}


