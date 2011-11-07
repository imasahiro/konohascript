//QMetaEnum QMetaProperty.enumerator();
KMETHOD QMetaProperty_enumerator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		QMetaEnum ret_v = qp->enumerator();
		QMetaEnum *ret_v_ = new QMetaEnum(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QMetaProperty.hasNotifySignal();
KMETHOD QMetaProperty_hasNotifySignal(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasNotifySignal();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMetaProperty.isConstant();
KMETHOD QMetaProperty_isConstant(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isConstant();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMetaProperty.isDesignable(QObject object);
KMETHOD QMetaProperty_isDesignable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		const QObject*  object = RawPtr_to(const QObject*, sfp[1]);
		bool ret_v = qp->isDesignable(object);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMetaProperty.isEnumType();
KMETHOD QMetaProperty_isEnumType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEnumType();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMetaProperty.isFinal();
KMETHOD QMetaProperty_isFinal(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isFinal();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMetaProperty.isFlagType();
KMETHOD QMetaProperty_isFlagType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isFlagType();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMetaProperty.isReadable();
KMETHOD QMetaProperty_isReadable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isReadable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMetaProperty.isResettable();
KMETHOD QMetaProperty_isResettable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isResettable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMetaProperty.isScriptable(QObject object);
KMETHOD QMetaProperty_isScriptable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		const QObject*  object = RawPtr_to(const QObject*, sfp[1]);
		bool ret_v = qp->isScriptable(object);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMetaProperty.isStored(QObject object);
KMETHOD QMetaProperty_isStored(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		const QObject*  object = RawPtr_to(const QObject*, sfp[1]);
		bool ret_v = qp->isStored(object);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMetaProperty.isUser(QObject object);
KMETHOD QMetaProperty_isUser(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		const QObject*  object = RawPtr_to(const QObject*, sfp[1]);
		bool ret_v = qp->isUser(object);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMetaProperty.isWritable();
KMETHOD QMetaProperty_isWritable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isWritable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QMetaProperty.name();
KMETHOD QMetaProperty_name(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		const char* ret_v = qp->name();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (char*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QMetaMethod QMetaProperty.notifySignal();
KMETHOD QMetaProperty_notifySignal(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		QMetaMethod ret_v = qp->notifySignal();
		QMetaMethod *ret_v_ = new QMetaMethod(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMetaProperty.notifySignalIndex();
KMETHOD QMetaProperty_notifySignalIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		int ret_v = qp->notifySignalIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMetaProperty.propertyIndex();
KMETHOD QMetaProperty_propertyIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		int ret_v = qp->propertyIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QVariant QMetaProperty.read(QObject object);
KMETHOD QMetaProperty_read(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		const QObject*  object = RawPtr_to(const QObject*, sfp[1]);
		QVariant ret_v = qp->read(object);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QMetaProperty.reset(QObject object);
KMETHOD QMetaProperty_reset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		QObject*  object = RawPtr_to(QObject*, sfp[1]);
		bool ret_v = qp->reset(object);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QMetaProperty.type();
KMETHOD QMetaProperty_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		QVariant::Type ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QMetaProperty.typeName();
KMETHOD QMetaProperty_typeName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		const char* ret_v = qp->typeName();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (char*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMetaProperty.userType();
KMETHOD QMetaProperty_userType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		int ret_v = qp->userType();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QMetaProperty.write(QObject object, QVariant value);
KMETHOD QMetaProperty_write(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *  qp = RawPtr_to(QMetaProperty *, sfp[0]);
	if (qp) {
		QObject*  object = RawPtr_to(QObject*, sfp[1]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[2]);
		bool ret_v = qp->write(object, value);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//Array<String> QMetaProperty.parents();
KMETHOD QMetaProperty_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaProperty *qp = RawPtr_to(QMetaProperty*, sfp[0]);
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

DummyQMetaProperty::DummyQMetaProperty()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQMetaProperty::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMetaProperty::self = ptr;
}

bool DummyQMetaProperty::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQMetaProperty::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMetaProperty::event_map->bigin();
	if ((itr = DummyQMetaProperty::event_map->find(str)) == DummyQMetaProperty::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMetaProperty::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMetaProperty::slot_map->bigin();
	if ((itr = DummyQMetaProperty::slot_map->find(str)) == DummyQMetaProperty::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQMetaProperty::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQMetaProperty::connection(QObject *o)
{
	QMetaProperty *p = dynamic_cast<QMetaProperty*>(o);
	if (p != NULL) {
	}
}

KMETHOD QMetaProperty_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMetaProperty *qp = RawPtr_to(KQMetaProperty *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMetaProperty]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMetaProperty]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QMetaProperty_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMetaProperty *qp = RawPtr_to(KQMetaProperty *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMetaProperty]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMetaProperty]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMetaProperty_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMetaProperty *qp = (KQMetaProperty *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMetaProperty_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQMetaProperty *qp = (KQMetaProperty *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QMetaProperty_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMetaProperty::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQMetaProperty(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMetaProperty";
	cdef->free = QMetaProperty_free;
	cdef->reftrace = QMetaProperty_reftrace;
	cdef->compareTo = QMetaProperty_compareTo;
}


