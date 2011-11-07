//Array<String> QTextBlockUserData.parents();
KMETHOD QTextBlockUserData_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBlockUserData *qp = RawPtr_to(QTextBlockUserData*, sfp[0]);
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

DummyQTextBlockUserData::DummyQTextBlockUserData()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextBlockUserData::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextBlockUserData::self = ptr;
}

bool DummyQTextBlockUserData::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextBlockUserData::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextBlockUserData::event_map->bigin();
	if ((itr = DummyQTextBlockUserData::event_map->find(str)) == DummyQTextBlockUserData::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextBlockUserData::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextBlockUserData::slot_map->bigin();
	if ((itr = DummyQTextBlockUserData::slot_map->find(str)) == DummyQTextBlockUserData::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQTextBlockUserData::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQTextBlockUserData::connection(QObject *o)
{
	QTextBlockUserData *p = dynamic_cast<QTextBlockUserData*>(o);
	if (p != NULL) {
	}
}

KMETHOD QTextBlockUserData_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextBlockUserData *qp = RawPtr_to(KQTextBlockUserData *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextBlockUserData]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextBlockUserData]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextBlockUserData_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextBlockUserData *qp = RawPtr_to(KQTextBlockUserData *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextBlockUserData]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextBlockUserData]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextBlockUserData_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextBlockUserData *qp = (KQTextBlockUserData *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextBlockUserData_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQTextBlockUserData *qp = (KQTextBlockUserData *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextBlockUserData_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextBlockUserData::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQTextBlockUserData(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextBlockUserData";
	cdef->free = QTextBlockUserData_free;
	cdef->reftrace = QTextBlockUserData_reftrace;
	cdef->compareTo = QTextBlockUserData_compareTo;
}


