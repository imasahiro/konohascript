//boolean QMetaEnum.isFlag();
KMETHOD QMetaEnum_isFlag(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaEnum *  qp = RawPtr_to(QMetaEnum *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isFlag();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QMetaEnum.key(int index);
KMETHOD QMetaEnum_key(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaEnum *  qp = RawPtr_to(QMetaEnum *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		const char* ret_v = qp->key(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (char*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMetaEnum.keyCount();
KMETHOD QMetaEnum_keyCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaEnum *  qp = RawPtr_to(QMetaEnum *, sfp[0]);
	if (qp) {
		int ret_v = qp->keyCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMetaEnum.keyToValue(String key);
KMETHOD QMetaEnum_keyToValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaEnum *  qp = RawPtr_to(QMetaEnum *, sfp[0]);
	if (qp) {
		const char*  key = RawPtr_to(const char*, sfp[1]);
		int ret_v = qp->keyToValue(key);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMetaEnum.keysToValue(String keys);
KMETHOD QMetaEnum_keysToValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaEnum *  qp = RawPtr_to(QMetaEnum *, sfp[0]);
	if (qp) {
		const char*  keys = RawPtr_to(const char*, sfp[1]);
		int ret_v = qp->keysToValue(keys);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QMetaEnum.name();
KMETHOD QMetaEnum_name(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaEnum *  qp = RawPtr_to(QMetaEnum *, sfp[0]);
	if (qp) {
		const char* ret_v = qp->name();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (char*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QMetaEnum.scope();
KMETHOD QMetaEnum_scope(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaEnum *  qp = RawPtr_to(QMetaEnum *, sfp[0]);
	if (qp) {
		const char* ret_v = qp->scope();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (char*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMetaEnum.value(int index);
KMETHOD QMetaEnum_value(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaEnum *  qp = RawPtr_to(QMetaEnum *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		int ret_v = qp->value(index);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QMetaEnum.valueToKey(int value);
KMETHOD QMetaEnum_valueToKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaEnum *  qp = RawPtr_to(QMetaEnum *, sfp[0]);
	if (qp) {
		int value = Int_to(int, sfp[1]);
		const char* ret_v = qp->valueToKey(value);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (char*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QMetaEnum.valueToKeys(int value);
KMETHOD QMetaEnum_valueToKeys(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaEnum *  qp = RawPtr_to(QMetaEnum *, sfp[0]);
	if (qp) {
		int value = Int_to(int, sfp[1]);
		QByteArray ret_v = qp->valueToKeys(value);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QMetaEnum.parents();
KMETHOD QMetaEnum_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaEnum *qp = RawPtr_to(QMetaEnum*, sfp[0]);
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

DummyQMetaEnum::DummyQMetaEnum()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQMetaEnum::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMetaEnum::self = ptr;
}

bool DummyQMetaEnum::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQMetaEnum::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMetaEnum::event_map->bigin();
	if ((itr = DummyQMetaEnum::event_map->find(str)) == DummyQMetaEnum::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMetaEnum::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMetaEnum::slot_map->bigin();
	if ((itr = DummyQMetaEnum::slot_map->find(str)) == DummyQMetaEnum::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQMetaEnum::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQMetaEnum::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQMetaEnum::connection(QObject *o)
{
	QMetaEnum *p = dynamic_cast<QMetaEnum*>(o);
	if (p != NULL) {
	}
}

KMETHOD QMetaEnum_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMetaEnum *qp = RawPtr_to(KQMetaEnum *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMetaEnum]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMetaEnum]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QMetaEnum_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMetaEnum *qp = RawPtr_to(KQMetaEnum *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMetaEnum]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMetaEnum]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMetaEnum_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMetaEnum *qp = (KQMetaEnum *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMetaEnum_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQMetaEnum *qp = (KQMetaEnum *)p->rawptr;
//		KQMetaEnum *qp = static_cast<KQMetaEnum*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QMetaEnum_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMetaEnum::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQMetaEnum(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMetaEnum";
	cdef->free = QMetaEnum_free;
	cdef->reftrace = QMetaEnum_reftrace;
	cdef->compareTo = QMetaEnum_compareTo;
}


