//
//@Virtual Array<QNetworkProxy> QNetworkProxyFactory.queryProxy(QNetworkProxyQuery query);
KMETHOD QNetworkProxyFactory_queryProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxyFactory *  qp = RawPtr_to(QNetworkProxyFactory *, sfp[0]);
	if (qp) {
		const QNetworkProxyQuery  query = *RawPtr_to(const QNetworkProxyQuery *, sfp[1]);
		QList<QNetworkProxy> ret_v = qp->queryProxy(query);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QNetworkProxy"));
		for (int n = 0; n < list_size; n++) {
			QNetworkProxy *ret_v_ = new QNetworkProxy(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//Array<QNetworkProxy> QNetworkProxyFactory.proxyForQuery(QNetworkProxyQuery query);
KMETHOD QNetworkProxyFactory_proxyForQuery(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QNetworkProxyQuery  query = *RawPtr_to(const QNetworkProxyQuery *, sfp[1]);
		QList<QNetworkProxy> ret_v = QNetworkProxyFactory::proxyForQuery(query);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QNetworkProxy"));
		for (int n = 0; n < list_size; n++) {
			QNetworkProxy *ret_v_ = new QNetworkProxy(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//void QNetworkProxyFactory.setApplicationProxyFactory(QNetworkProxyFactory factory);
KMETHOD QNetworkProxyFactory_setApplicationProxyFactory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QNetworkProxyFactory*  factory = RawPtr_to(QNetworkProxyFactory*, sfp[1]);
		QNetworkProxyFactory::setApplicationProxyFactory(factory);
	}
	RETURNvoid_();
}

//void QNetworkProxyFactory.setUseSystemConfiguration(boolean enable);
KMETHOD QNetworkProxyFactory_setUseSystemConfiguration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool enable = Boolean_to(bool, sfp[1]);
		QNetworkProxyFactory::setUseSystemConfiguration(enable);
	}
	RETURNvoid_();
}

//Array<QNetworkProxy> QNetworkProxyFactory.systemProxyForQuery(QNetworkProxyQuery query);
KMETHOD QNetworkProxyFactory_systemProxyForQuery(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QNetworkProxyQuery  query = *RawPtr_to(const QNetworkProxyQuery *, sfp[1]);
		QList<QNetworkProxy> ret_v = QNetworkProxyFactory::systemProxyForQuery(query);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QNetworkProxy"));
		for (int n = 0; n < list_size; n++) {
			QNetworkProxy *ret_v_ = new QNetworkProxy(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//Array<String> QNetworkProxyFactory.parents();
KMETHOD QNetworkProxyFactory_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxyFactory *qp = RawPtr_to(QNetworkProxyFactory*, sfp[0]);
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

DummyQNetworkProxyFactory::DummyQNetworkProxyFactory()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQNetworkProxyFactory::~DummyQNetworkProxyFactory()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQNetworkProxyFactory::setSelf(knh_RawPtr_t *ptr)
{
	DummyQNetworkProxyFactory::self = ptr;
}

bool DummyQNetworkProxyFactory::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQNetworkProxyFactory::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkProxyFactory::event_map->bigin();
	if ((itr = DummyQNetworkProxyFactory::event_map->find(str)) == DummyQNetworkProxyFactory::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQNetworkProxyFactory::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkProxyFactory::slot_map->bigin();
	if ((itr = DummyQNetworkProxyFactory::slot_map->find(str)) == DummyQNetworkProxyFactory::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQNetworkProxyFactory::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQNetworkProxyFactory::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQNetworkProxyFactory::connection(QObject *o)
{
	QNetworkProxyFactory *p = dynamic_cast<QNetworkProxyFactory*>(o);
	if (p != NULL) {
	}
}

KQNetworkProxyFactory::KQNetworkProxyFactory() : QNetworkProxyFactory()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQNetworkProxyFactory();
}

KQNetworkProxyFactory::~KQNetworkProxyFactory()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QNetworkProxyFactory_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkProxyFactory *qp = RawPtr_to(KQNetworkProxyFactory *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkProxyFactory]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkProxyFactory]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QNetworkProxyFactory_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkProxyFactory *qp = RawPtr_to(KQNetworkProxyFactory *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkProxyFactory]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkProxyFactory]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QNetworkProxyFactory_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQNetworkProxyFactory *qp = (KQNetworkProxyFactory *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QNetworkProxyFactory*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QNetworkProxyFactory_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQNetworkProxyFactory *qp = (KQNetworkProxyFactory *)p->rawptr;
		KQNetworkProxyFactory *qp = static_cast<KQNetworkProxyFactory*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QNetworkProxyFactory_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQNetworkProxyFactory::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQNetworkProxyFactory(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkProxyFactory";
	cdef->free = QNetworkProxyFactory_free;
	cdef->reftrace = QNetworkProxyFactory_reftrace;
	cdef->compareTo = QNetworkProxyFactory_compareTo;
}


