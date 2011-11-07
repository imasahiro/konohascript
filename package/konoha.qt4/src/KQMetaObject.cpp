//QMetaClassInfo QMetaObject.classInfo(int index);
KMETHOD QMetaObject_classInfo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QMetaClassInfo ret_v = qp->classInfo(index);
		QMetaClassInfo *ret_v_ = new QMetaClassInfo(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMetaObject.classInfoCount();
KMETHOD QMetaObject_classInfoCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		int ret_v = qp->classInfoCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMetaObject.classInfoOffset();
KMETHOD QMetaObject_classInfoOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		int ret_v = qp->classInfoOffset();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QMetaObject.className();
KMETHOD QMetaObject_className(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		const char* ret_v = qp->className();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (char*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QMetaMethod QMetaObject.constructor(int index);
KMETHOD QMetaObject_constructor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QMetaMethod ret_v = qp->constructor(index);
		QMetaMethod *ret_v_ = new QMetaMethod(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMetaObject.constructorCount();
KMETHOD QMetaObject_constructorCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		int ret_v = qp->constructorCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QMetaEnum QMetaObject.enumerator(int index);
KMETHOD QMetaObject_enumerator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QMetaEnum ret_v = qp->enumerator(index);
		QMetaEnum *ret_v_ = new QMetaEnum(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMetaObject.enumeratorCount();
KMETHOD QMetaObject_enumeratorCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		int ret_v = qp->enumeratorCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMetaObject.enumeratorOffset();
KMETHOD QMetaObject_enumeratorOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		int ret_v = qp->enumeratorOffset();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMetaObject.indexOfClassInfo(String name);
KMETHOD QMetaObject_indexOfClassInfo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		int ret_v = qp->indexOfClassInfo(name);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMetaObject.indexOfConstructor(String constructor);
KMETHOD QMetaObject_indexOfConstructor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		const char*  constructor = RawPtr_to(const char*, sfp[1]);
		int ret_v = qp->indexOfConstructor(constructor);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMetaObject.indexOfEnumerator(String name);
KMETHOD QMetaObject_indexOfEnumerator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		int ret_v = qp->indexOfEnumerator(name);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMetaObject.indexOfMethod(String method);
KMETHOD QMetaObject_indexOfMethod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		const char*  method = RawPtr_to(const char*, sfp[1]);
		int ret_v = qp->indexOfMethod(method);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMetaObject.indexOfProperty(String name);
KMETHOD QMetaObject_indexOfProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		int ret_v = qp->indexOfProperty(name);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMetaObject.indexOfSignal(String signal);
KMETHOD QMetaObject_indexOfSignal(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		const char*  signal = RawPtr_to(const char*, sfp[1]);
		int ret_v = qp->indexOfSignal(signal);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMetaObject.indexOfSlot(String slot);
KMETHOD QMetaObject_indexOfSlot(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		const char*  slot = RawPtr_to(const char*, sfp[1]);
		int ret_v = qp->indexOfSlot(slot);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QMetaMethod QMetaObject.method(int index);
KMETHOD QMetaObject_method(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QMetaMethod ret_v = qp->method(index);
		QMetaMethod *ret_v_ = new QMetaMethod(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMetaObject.methodCount();
KMETHOD QMetaObject_methodCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		int ret_v = qp->methodCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMetaObject.methodOffset();
KMETHOD QMetaObject_methodOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		int ret_v = qp->methodOffset();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QObject QMetaObject.newInstance(QGenericArgument val0);
KMETHOD QMetaObject_newInstance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		QGenericArgument  val0 = *RawPtr_to(QGenericArgument *, sfp[1]);
		QObject* ret_v = qp->newInstance(val0);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QMetaProperty QMetaObject.property(int index);
KMETHOD QMetaObject_property(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QMetaProperty ret_v = qp->property(index);
		QMetaProperty *ret_v_ = new QMetaProperty(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QMetaObject.propertyCount();
KMETHOD QMetaObject_propertyCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		int ret_v = qp->propertyCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMetaObject.propertyOffset();
KMETHOD QMetaObject_propertyOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		int ret_v = qp->propertyOffset();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QMetaObject QMetaObject.superClass();
KMETHOD QMetaObject_superClass(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		const QMetaObject* ret_v = qp->superClass();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMetaObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QMetaProperty QMetaObject.userProperty();
KMETHOD QMetaObject_userProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *  qp = RawPtr_to(QMetaObject *, sfp[0]);
	if (qp) {
		QMetaProperty ret_v = qp->userProperty();
		QMetaProperty *ret_v_ = new QMetaProperty(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QMetaObject.checkConnectArgs(String signal, String method);
KMETHOD QMetaObject_checkConnectArgs(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const char*  signal = RawPtr_to(const char*, sfp[1]);
		const char*  method = RawPtr_to(const char*, sfp[2]);
		bool ret_v = QMetaObject::checkConnectArgs(signal, method);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QMetaObject.connectSlotsByName(QObject object);
KMETHOD QMetaObject_connectSlotsByName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QObject*  object = RawPtr_to(QObject*, sfp[1]);
		QMetaObject::connectSlotsByName(object);
	}
	RETURNvoid_();
}

//boolean QMetaObject.invokeMethod(QObject obj, String member, int type, QGenericReturnArgument ret, QGenericArgument val0);
KMETHOD QMetaObject_invokeMethod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QObject*  obj = RawPtr_to(QObject*, sfp[1]);
		const char*  member = RawPtr_to(const char*, sfp[2]);
		Qt::ConnectionType type = Int_to(Qt::ConnectionType, sfp[3]);
		QGenericReturnArgument  ret = *RawPtr_to(QGenericReturnArgument *, sfp[4]);
		QGenericArgument  val0 = *RawPtr_to(QGenericArgument *, sfp[5]);
		bool ret_v = QMetaObject::invokeMethod(obj, member, type, ret, val0);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QMetaObject.invokeMethod(QObject obj, String member, QGenericReturnArgument ret, QGenericArgument val0);
KMETHOD QMetaObject_invokeMethod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QObject*  obj = RawPtr_to(QObject*, sfp[1]);
		const char*  member = RawPtr_to(const char*, sfp[2]);
		QGenericReturnArgument  ret = *RawPtr_to(QGenericReturnArgument *, sfp[3]);
		QGenericArgument  val0 = *RawPtr_to(QGenericArgument *, sfp[4]);
		bool ret_v = QMetaObject::invokeMethod(obj, member, ret, val0);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//boolean QMetaObject.invokeMethod(QObject obj, String member, int type, QGenericArgument val0);
KMETHOD QMetaObject_invokeMethod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QObject*  obj = RawPtr_to(QObject*, sfp[1]);
		const char*  member = RawPtr_to(const char*, sfp[2]);
		Qt::ConnectionType type = Int_to(Qt::ConnectionType, sfp[3]);
		QGenericArgument  val0 = *RawPtr_to(QGenericArgument *, sfp[4]);
		bool ret_v = QMetaObject::invokeMethod(obj, member, type, val0);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//boolean QMetaObject.invokeMethod(QObject obj, String member, QGenericArgument val0);
KMETHOD QMetaObject_invokeMethod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QObject*  obj = RawPtr_to(QObject*, sfp[1]);
		const char*  member = RawPtr_to(const char*, sfp[2]);
		QGenericArgument  val0 = *RawPtr_to(QGenericArgument *, sfp[3]);
		bool ret_v = QMetaObject::invokeMethod(obj, member, val0);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//QByteArray QMetaObject.normalizedSignature(String method);
KMETHOD QMetaObject_normalizedSignature(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const char*  method = RawPtr_to(const char*, sfp[1]);
		QByteArray ret_v = QMetaObject::normalizedSignature(method);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QMetaObject.normalizedType(String type);
KMETHOD QMetaObject_normalizedType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const char*  type = RawPtr_to(const char*, sfp[1]);
		QByteArray ret_v = QMetaObject::normalizedType(type);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QMetaObject.parents();
KMETHOD QMetaObject_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMetaObject *qp = RawPtr_to(QMetaObject*, sfp[0]);
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

DummyQMetaObject::DummyQMetaObject()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQMetaObject::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMetaObject::self = ptr;
}

bool DummyQMetaObject::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQMetaObject::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMetaObject::event_map->bigin();
	if ((itr = DummyQMetaObject::event_map->find(str)) == DummyQMetaObject::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMetaObject::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMetaObject::slot_map->bigin();
	if ((itr = DummyQMetaObject::slot_map->find(str)) == DummyQMetaObject::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQMetaObject::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQMetaObject::connection(QObject *o)
{
	QMetaObject *p = dynamic_cast<QMetaObject*>(o);
	if (p != NULL) {
	}
}

KMETHOD QMetaObject_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMetaObject *qp = RawPtr_to(KQMetaObject *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMetaObject]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMetaObject]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QMetaObject_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMetaObject *qp = RawPtr_to(KQMetaObject *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMetaObject]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMetaObject]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMetaObject_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMetaObject *qp = (KQMetaObject *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMetaObject_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQMetaObject *qp = (KQMetaObject *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QMetaObject_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMetaObject::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQMetaObject(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMetaObject";
	cdef->free = QMetaObject_free;
	cdef->reftrace = QMetaObject_reftrace;
	cdef->compareTo = QMetaObject_compareTo;
}


