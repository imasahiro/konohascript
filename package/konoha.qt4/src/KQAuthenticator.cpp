//QAuthenticator QAuthenticator.new();
KMETHOD QAuthenticator_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAuthenticator *ret_v = new KQAuthenticator();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QAuthenticator QAuthenticator.new(QAuthenticator other);
KMETHOD QAuthenticator_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QAuthenticator  other = *RawPtr_to(const QAuthenticator *, sfp[1]);
	KQAuthenticator *ret_v = new KQAuthenticator(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QVariant QAuthenticator.getOption(String opt);
KMETHOD QAuthenticator_getOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAuthenticator *  qp = RawPtr_to(QAuthenticator *, sfp[0]);
	if (qp) {
		const QString opt = String_to(const QString, sfp[1]);
		QVariant ret_v = qp->option(opt);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QVariantHash QAuthenticator.options();
KMETHOD QAuthenticator_options(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAuthenticator *  qp = RawPtr_to(QAuthenticator *, sfp[0]);
	if (qp) {
		QVariantHash ret_v = qp->options();
		QVariantHash *ret_v_ = new QVariantHash(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QAuthenticator.getPassword();
KMETHOD QAuthenticator_getPassword(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAuthenticator *  qp = RawPtr_to(QAuthenticator *, sfp[0]);
	if (qp) {
		QString ret_v = qp->password();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QAuthenticator.realm();
KMETHOD QAuthenticator_realm(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAuthenticator *  qp = RawPtr_to(QAuthenticator *, sfp[0]);
	if (qp) {
		QString ret_v = qp->realm();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QAuthenticator.setOption(String opt, QVariant value);
KMETHOD QAuthenticator_setOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAuthenticator *  qp = RawPtr_to(QAuthenticator *, sfp[0]);
	if (qp) {
		const QString opt = String_to(const QString, sfp[1]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[2]);
		qp->setOption(opt, value);
	}
	RETURNvoid_();
}

//void QAuthenticator.setPassword(String password);
KMETHOD QAuthenticator_setPassword(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAuthenticator *  qp = RawPtr_to(QAuthenticator *, sfp[0]);
	if (qp) {
		const QString password = String_to(const QString, sfp[1]);
		qp->setPassword(password);
	}
	RETURNvoid_();
}

//void QAuthenticator.setUser(String user);
KMETHOD QAuthenticator_setUser(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAuthenticator *  qp = RawPtr_to(QAuthenticator *, sfp[0]);
	if (qp) {
		const QString user = String_to(const QString, sfp[1]);
		qp->setUser(user);
	}
	RETURNvoid_();
}

//String QAuthenticator.getUser();
KMETHOD QAuthenticator_getUser(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAuthenticator *  qp = RawPtr_to(QAuthenticator *, sfp[0]);
	if (qp) {
		QString ret_v = qp->user();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QAuthenticator.parents();
KMETHOD QAuthenticator_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAuthenticator *qp = RawPtr_to(QAuthenticator*, sfp[0]);
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

DummyQAuthenticator::DummyQAuthenticator()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQAuthenticator::~DummyQAuthenticator()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQAuthenticator::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAuthenticator::self = ptr;
}

bool DummyQAuthenticator::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQAuthenticator::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAuthenticator::event_map->bigin();
	if ((itr = DummyQAuthenticator::event_map->find(str)) == DummyQAuthenticator::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAuthenticator::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAuthenticator::slot_map->bigin();
	if ((itr = DummyQAuthenticator::slot_map->find(str)) == DummyQAuthenticator::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQAuthenticator::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQAuthenticator::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQAuthenticator::connection(QObject *o)
{
	QAuthenticator *p = dynamic_cast<QAuthenticator*>(o);
	if (p != NULL) {
	}
}

KQAuthenticator::KQAuthenticator() : QAuthenticator()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQAuthenticator();
}

KQAuthenticator::~KQAuthenticator()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QAuthenticator_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAuthenticator *qp = RawPtr_to(KQAuthenticator *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAuthenticator]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAuthenticator]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAuthenticator_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAuthenticator *qp = RawPtr_to(KQAuthenticator *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAuthenticator]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAuthenticator]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAuthenticator_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQAuthenticator *qp = (KQAuthenticator *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QAuthenticator*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QAuthenticator_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQAuthenticator *qp = (KQAuthenticator *)p->rawptr;
		KQAuthenticator *qp = static_cast<KQAuthenticator*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAuthenticator_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QAuthenticator*>(p1->rawptr) == *static_cast<QAuthenticator*>(p2->rawptr) ? 0 : 1);
}

void KQAuthenticator::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQAuthenticator(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAuthenticator";
	cdef->free = QAuthenticator_free;
	cdef->reftrace = QAuthenticator_reftrace;
	cdef->compareTo = QAuthenticator_compareTo;
}


