//QLatin1Char QLatin1Char.new(String c);
KMETHOD QLatin1Char_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	char  c = *RawPtr_to(char *, sfp[1]);
	KQLatin1Char *ret_v = new KQLatin1Char(c);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//String QLatin1Char.toLatin1();
KMETHOD QLatin1Char_toLatin1(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLatin1Char *  qp = RawPtr_to(QLatin1Char *, sfp[0]);
	if (qp != NULL) {
		char ret_v = qp->toLatin1();
		char *ret_v_ = new char(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QLatin1Char.unicode();
KMETHOD QLatin1Char_unicode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLatin1Char *  qp = RawPtr_to(QLatin1Char *, sfp[0]);
	if (qp != NULL) {
		ushort ret_v = qp->unicode();
		ushort *ret_v_ = new ushort(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQLatin1Char::DummyQLatin1Char()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQLatin1Char::setSelf(knh_RawPtr_t *ptr)
{
	DummyQLatin1Char::self = ptr;
}

bool DummyQLatin1Char::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQLatin1Char::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLatin1Char::event_map->bigin();
	if ((itr = DummyQLatin1Char::event_map->find(str)) == DummyQLatin1Char::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQLatin1Char::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLatin1Char::slot_map->bigin();
	if ((itr = DummyQLatin1Char::event_map->find(str)) == DummyQLatin1Char::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQLatin1Char::KQLatin1Char(char c) : QLatin1Char(c)
{
	self = NULL;
}

KMETHOD QLatin1Char_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLatin1Char *qp = RawPtr_to(KQLatin1Char *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QLatin1Char]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQLatin1Char::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLatin1Char]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QLatin1Char_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLatin1Char *qp = RawPtr_to(KQLatin1Char *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QLatin1Char]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQLatin1Char::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLatin1Char]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QLatin1Char_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQLatin1Char *qp = (KQLatin1Char *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QLatin1Char_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQLatin1Char *qp = (KQLatin1Char *)p->rawptr;
		(void)qp;
	}
}

static int QLatin1Char_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQLatin1Char(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QLatin1Char";
	cdef->free = QLatin1Char_free;
	cdef->reftrace = QLatin1Char_reftrace;
	cdef->compareTo = QLatin1Char_compareTo;
}


