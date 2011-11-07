//@Virtual void QAccessibleBridge.notifyAccessibilityUpdate(int reason, QAccessibleInterface interface, int child);
KMETHOD QAccessibleBridge_notifyAccessibilityUpdate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleBridge *  qp = RawPtr_to(QAccessibleBridge *, sfp[0]);
	if (qp) {
		int reason = Int_to(int, sfp[1]);
		QAccessibleInterface*  interface = RawPtr_to(QAccessibleInterface*, sfp[2]);
		int child = Int_to(int, sfp[3]);
		qp->notifyAccessibilityUpdate(reason, interface, child);
	}
	RETURNvoid_();
}

//@Virtual void QAccessibleBridge.setRootObject(QAccessibleInterface object);
KMETHOD QAccessibleBridge_setRootObject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleBridge *  qp = RawPtr_to(QAccessibleBridge *, sfp[0]);
	if (qp) {
		QAccessibleInterface*  object = RawPtr_to(QAccessibleInterface*, sfp[1]);
		qp->setRootObject(object);
	}
	RETURNvoid_();
}

//Array<String> QAccessibleBridge.parents();
KMETHOD QAccessibleBridge_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleBridge *qp = RawPtr_to(QAccessibleBridge*, sfp[0]);
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

DummyQAccessibleBridge::DummyQAccessibleBridge()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQAccessibleBridge::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAccessibleBridge::self = ptr;
}

bool DummyQAccessibleBridge::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQAccessibleBridge::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAccessibleBridge::event_map->bigin();
	if ((itr = DummyQAccessibleBridge::event_map->find(str)) == DummyQAccessibleBridge::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAccessibleBridge::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAccessibleBridge::slot_map->bigin();
	if ((itr = DummyQAccessibleBridge::slot_map->find(str)) == DummyQAccessibleBridge::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQAccessibleBridge::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQAccessibleBridge::connection(QObject *o)
{
	QAccessibleBridge *p = dynamic_cast<QAccessibleBridge*>(o);
	if (p != NULL) {
	}
}

KMETHOD QAccessibleBridge_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAccessibleBridge *qp = RawPtr_to(KQAccessibleBridge *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAccessibleBridge]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAccessibleBridge]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAccessibleBridge_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAccessibleBridge *qp = RawPtr_to(KQAccessibleBridge *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAccessibleBridge]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAccessibleBridge]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAccessibleBridge_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAccessibleBridge *qp = (KQAccessibleBridge *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAccessibleBridge_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQAccessibleBridge *qp = (KQAccessibleBridge *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAccessibleBridge_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAccessibleBridge::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQAccessibleBridge(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAccessibleBridge";
	cdef->free = QAccessibleBridge_free;
	cdef->reftrace = QAccessibleBridge_reftrace;
	cdef->compareTo = QAccessibleBridge_compareTo;
}


