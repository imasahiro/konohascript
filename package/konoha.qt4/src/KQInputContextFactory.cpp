//QInputContext QInputContextFactory.create(String key, QObject parent);
KMETHOD QInputContextFactory_create(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString key = String_to(const QString, sfp[1]);
		QObject*  parent = RawPtr_to(QObject*, sfp[2]);
		QInputContext* ret_v = QInputContextFactory::create(key, parent);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QInputContext*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QInputContextFactory.description(String key);
KMETHOD QInputContextFactory_description(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString key = String_to(const QString, sfp[1]);
		QString ret_v = QInputContextFactory::description(key);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QInputContextFactory.displayName(String key);
KMETHOD QInputContextFactory_displayName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString key = String_to(const QString, sfp[1]);
		QString ret_v = QInputContextFactory::displayName(key);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QInputContextFactory.parents();
KMETHOD QInputContextFactory_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputContextFactory *qp = RawPtr_to(QInputContextFactory*, sfp[0]);
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

DummyQInputContextFactory::DummyQInputContextFactory()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQInputContextFactory::setSelf(knh_RawPtr_t *ptr)
{
	DummyQInputContextFactory::self = ptr;
}

bool DummyQInputContextFactory::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQInputContextFactory::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQInputContextFactory::event_map->bigin();
	if ((itr = DummyQInputContextFactory::event_map->find(str)) == DummyQInputContextFactory::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQInputContextFactory::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQInputContextFactory::slot_map->bigin();
	if ((itr = DummyQInputContextFactory::slot_map->find(str)) == DummyQInputContextFactory::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQInputContextFactory::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQInputContextFactory::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQInputContextFactory::connection(QObject *o)
{
	QInputContextFactory *p = dynamic_cast<QInputContextFactory*>(o);
	if (p != NULL) {
	}
}

KMETHOD QInputContextFactory_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQInputContextFactory *qp = RawPtr_to(KQInputContextFactory *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QInputContextFactory]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QInputContextFactory]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QInputContextFactory_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQInputContextFactory *qp = RawPtr_to(KQInputContextFactory *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QInputContextFactory]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QInputContextFactory]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QInputContextFactory_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQInputContextFactory *qp = (KQInputContextFactory *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QInputContextFactory_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQInputContextFactory *qp = (KQInputContextFactory *)p->rawptr;
//		KQInputContextFactory *qp = static_cast<KQInputContextFactory*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QInputContextFactory_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQInputContextFactory::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQInputContextFactory(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QInputContextFactory";
	cdef->free = QInputContextFactory_free;
	cdef->reftrace = QInputContextFactory_reftrace;
	cdef->compareTo = QInputContextFactory_compareTo;
}


