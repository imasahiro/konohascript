//QLatin1String QLatin1String.new(String str);
KMETHOD QLatin1String_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const char*  str = RawPtr_to(const char*, sfp[1]);
	KQLatin1String *ret_v = new KQLatin1String(str);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//String QLatin1String.latin1();
KMETHOD QLatin1String_latin1(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLatin1String *  qp = RawPtr_to(QLatin1String *, sfp[0]);
	if (qp) {
		const char* ret_v = qp->latin1();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (char*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QLatin1String.parents();
KMETHOD QLatin1String_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLatin1String *qp = RawPtr_to(QLatin1String*, sfp[0]);
	if (qp != NULL) {
		int size = 10;
		knh_Array_t *a = new_Array0(ctx, size);
		const knh_ClassTBL_t *ct = sfp[0].p->h.cTBL;
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}

DummyQLatin1String::DummyQLatin1String()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQLatin1String::setSelf(knh_RawPtr_t *ptr)
{
	DummyQLatin1String::self = ptr;
}

bool DummyQLatin1String::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQLatin1String::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLatin1String::event_map->bigin();
	if ((itr = DummyQLatin1String::event_map->find(str)) == DummyQLatin1String::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQLatin1String::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLatin1String::slot_map->bigin();
	if ((itr = DummyQLatin1String::slot_map->find(str)) == DummyQLatin1String::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQLatin1String::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQLatin1String::connection(QObject *o)
{
	QLatin1String *p = dynamic_cast<QLatin1String*>(o);
	if (p != NULL) {
	}
}

KQLatin1String::KQLatin1String(const char* str) : QLatin1String(str)
{
	self = NULL;
	dummy = new DummyQLatin1String();
}

KMETHOD QLatin1String_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLatin1String *qp = RawPtr_to(KQLatin1String *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QLatin1String]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLatin1String]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QLatin1String_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLatin1String *qp = RawPtr_to(KQLatin1String *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QLatin1String]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLatin1String]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QLatin1String_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQLatin1String *qp = (KQLatin1String *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QLatin1String_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQLatin1String *qp = (KQLatin1String *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QLatin1String_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QLatin1String*>(p1->rawptr) == *static_cast<QLatin1String*>(p2->rawptr) ? 0 : 1);
}

void KQLatin1String::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQLatin1String(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QLatin1String";
	cdef->free = QLatin1String_free;
	cdef->reftrace = QLatin1String_reftrace;
	cdef->compareTo = QLatin1String_compareTo;
}


