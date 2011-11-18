//QProcessEnvironment QProcessEnvironment.new();
KMETHOD QProcessEnvironment_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQProcessEnvironment *ret_v = new KQProcessEnvironment();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QProcessEnvironment QProcessEnvironment.new(QProcessEnvironment other);
KMETHOD QProcessEnvironment_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QProcessEnvironment  other = *RawPtr_to(const QProcessEnvironment *, sfp[1]);
	KQProcessEnvironment *ret_v = new KQProcessEnvironment(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QProcessEnvironment.clear();
KMETHOD QProcessEnvironment_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcessEnvironment *  qp = RawPtr_to(QProcessEnvironment *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//boolean QProcessEnvironment.contains(String name);
KMETHOD QProcessEnvironment_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcessEnvironment *  qp = RawPtr_to(QProcessEnvironment *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		bool ret_v = qp->contains(name);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QProcessEnvironment.insert(String name, String value);
KMETHOD QProcessEnvironment_insert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcessEnvironment *  qp = RawPtr_to(QProcessEnvironment *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		const QString value = String_to(const QString, sfp[2]);
		qp->insert(name, value);
	}
	RETURNvoid_();
}

//boolean QProcessEnvironment.isEmpty();
KMETHOD QProcessEnvironment_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcessEnvironment *  qp = RawPtr_to(QProcessEnvironment *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QProcessEnvironment.remove(String name);
KMETHOD QProcessEnvironment_remove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcessEnvironment *  qp = RawPtr_to(QProcessEnvironment *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		qp->remove(name);
	}
	RETURNvoid_();
}

//String QProcessEnvironment.value(String name, String defaultValue);
KMETHOD QProcessEnvironment_value(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcessEnvironment *  qp = RawPtr_to(QProcessEnvironment *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		const QString defaultValue = String_to(const QString, sfp[2]);
		QString ret_v = qp->value(name, defaultValue);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QProcessEnvironment QProcessEnvironment.systemEnvironment();
KMETHOD QProcessEnvironment_systemEnvironment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QProcessEnvironment ret_v = QProcessEnvironment::systemEnvironment();
		QProcessEnvironment *ret_v_ = new QProcessEnvironment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QProcessEnvironment.parents();
KMETHOD QProcessEnvironment_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcessEnvironment *qp = RawPtr_to(QProcessEnvironment*, sfp[0]);
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

DummyQProcessEnvironment::DummyQProcessEnvironment()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQProcessEnvironment::~DummyQProcessEnvironment()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQProcessEnvironment::setSelf(knh_RawPtr_t *ptr)
{
	DummyQProcessEnvironment::self = ptr;
}

bool DummyQProcessEnvironment::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQProcessEnvironment::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQProcessEnvironment::event_map->bigin();
	if ((itr = DummyQProcessEnvironment::event_map->find(str)) == DummyQProcessEnvironment::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQProcessEnvironment::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQProcessEnvironment::slot_map->bigin();
	if ((itr = DummyQProcessEnvironment::slot_map->find(str)) == DummyQProcessEnvironment::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQProcessEnvironment::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQProcessEnvironment::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQProcessEnvironment::connection(QObject *o)
{
	QProcessEnvironment *p = dynamic_cast<QProcessEnvironment*>(o);
	if (p != NULL) {
	}
}

KQProcessEnvironment::KQProcessEnvironment() : QProcessEnvironment()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQProcessEnvironment();
}

KQProcessEnvironment::~KQProcessEnvironment()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QProcessEnvironment_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQProcessEnvironment *qp = RawPtr_to(KQProcessEnvironment *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QProcessEnvironment]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QProcessEnvironment]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QProcessEnvironment_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQProcessEnvironment *qp = RawPtr_to(KQProcessEnvironment *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QProcessEnvironment]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QProcessEnvironment]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QProcessEnvironment_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQProcessEnvironment *qp = (KQProcessEnvironment *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QProcessEnvironment*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QProcessEnvironment_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQProcessEnvironment *qp = (KQProcessEnvironment *)p->rawptr;
		KQProcessEnvironment *qp = static_cast<KQProcessEnvironment*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QProcessEnvironment_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QProcessEnvironment*>(p1->rawptr) == *static_cast<QProcessEnvironment*>(p2->rawptr) ? 0 : 1);
}

void KQProcessEnvironment::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQProcessEnvironment(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QProcessEnvironment";
	cdef->free = QProcessEnvironment_free;
	cdef->reftrace = QProcessEnvironment_reftrace;
	cdef->compareTo = QProcessEnvironment_compareTo;
}


