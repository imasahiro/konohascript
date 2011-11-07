//QStyleHintReturnMask QStyleHintReturnMask.new();
KMETHOD QStyleHintReturnMask_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleHintReturnMask *ret_v = new KQStyleHintReturnMask();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}


DummyQStyleHintReturnMask::DummyQStyleHintReturnMask()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleHintReturnMask::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleHintReturnMask::self = ptr;
	DummyQStyleHintReturn::setSelf(ptr);
}

bool DummyQStyleHintReturnMask::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleHintReturn::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleHintReturnMask::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleHintReturnMask::event_map->bigin();
	if ((itr = DummyQStyleHintReturnMask::event_map->find(str)) == DummyQStyleHintReturnMask::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleHintReturn::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleHintReturnMask::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleHintReturnMask::slot_map->bigin();
	if ((itr = DummyQStyleHintReturnMask::slot_map->find(str)) == DummyQStyleHintReturnMask::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleHintReturn::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQStyleHintReturnMask::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQStyleHintReturn::reftrace(ctx, p, tail_);
}

void DummyQStyleHintReturnMask::connection(QObject *o)
{
	QStyleHintReturnMask *p = dynamic_cast<QStyleHintReturnMask*>(o);
	if (p != NULL) {
	}
	DummyQStyleHintReturn::connection(o);
}

KQStyleHintReturnMask::KQStyleHintReturnMask() : QStyleHintReturnMask()
{
	self = NULL;
	dummy = new DummyQStyleHintReturnMask();
}

KMETHOD QStyleHintReturnMask_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleHintReturnMask *qp = RawPtr_to(KQStyleHintReturnMask *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleHintReturnMask]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleHintReturnMask]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleHintReturnMask_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleHintReturnMask *qp = RawPtr_to(KQStyleHintReturnMask *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleHintReturnMask]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleHintReturnMask]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleHintReturnMask_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleHintReturnMask *qp = (KQStyleHintReturnMask *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleHintReturnMask_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQStyleHintReturnMask *qp = (KQStyleHintReturnMask *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleHintReturnMask_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleHintReturnMask::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleHintReturnMaskConstInt[] = {
	{"Type", QStyleHintReturnMask::Type},
	{"Version", QStyleHintReturnMask::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleHintReturnMask(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleHintReturnMaskConstInt);
}


DEFAPI(void) defQStyleHintReturnMask(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleHintReturnMask";
	cdef->free = QStyleHintReturnMask_free;
	cdef->reftrace = QStyleHintReturnMask_reftrace;
	cdef->compareTo = QStyleHintReturnMask_compareTo;
}


