//QNetworkProxy QNetworkProxy.new();
KMETHOD QNetworkProxy_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkProxy *ret_v = new KQNetworkProxy();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QNetworkProxy QNetworkProxy.new(int type, String hostName, int port, String user, String password);
KMETHOD QNetworkProxy_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy::ProxyType type = Int_to(QNetworkProxy::ProxyType, sfp[1]);
	const QString hostName = String_to(const QString, sfp[2]);
	quint16 port = Int_to(quint16, sfp[3]);
	const QString user = String_to(const QString, sfp[4]);
	const QString password = String_to(const QString, sfp[5]);
	KQNetworkProxy *ret_v = new KQNetworkProxy(type, hostName, port, user, password);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QNetworkProxy QNetworkProxy.new(QNetworkProxy other);
KMETHOD QNetworkProxy_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QNetworkProxy  other = *RawPtr_to(const QNetworkProxy *, sfp[1]);
	KQNetworkProxy *ret_v = new KQNetworkProxy(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QNetworkProxyCapabilities QNetworkProxy.getCapabilities();
KMETHOD QNetworkProxy_getCapabilities(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy *  qp = RawPtr_to(QNetworkProxy *, sfp[0]);
	if (qp) {
		QNetworkProxy::Capabilities ret_v = qp->capabilities();
		QNetworkProxy::Capabilities *ret_v_ = new QNetworkProxy::Capabilities(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QNetworkProxy.getHostName();
KMETHOD QNetworkProxy_getHostName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy *  qp = RawPtr_to(QNetworkProxy *, sfp[0]);
	if (qp) {
		QString ret_v = qp->hostName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QNetworkProxy.isCachingProxy();
KMETHOD QNetworkProxy_isCachingProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy *  qp = RawPtr_to(QNetworkProxy *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isCachingProxy();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QNetworkProxy.isTransparentProxy();
KMETHOD QNetworkProxy_isTransparentProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy *  qp = RawPtr_to(QNetworkProxy *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isTransparentProxy();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QNetworkProxy.getPassword();
KMETHOD QNetworkProxy_getPassword(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy *  qp = RawPtr_to(QNetworkProxy *, sfp[0]);
	if (qp) {
		QString ret_v = qp->password();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QNetworkProxy.getPort();
KMETHOD QNetworkProxy_getPort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy *  qp = RawPtr_to(QNetworkProxy *, sfp[0]);
	if (qp) {
		quint16 ret_v = qp->port();
		quint16 *ret_v_ = new quint16(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QNetworkProxy.setCapabilities(QNetworkProxyCapabilities capabilities);
KMETHOD QNetworkProxy_setCapabilities(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy *  qp = RawPtr_to(QNetworkProxy *, sfp[0]);
	if (qp) {
		initFlag(capabilities, QNetworkProxy::Capabilities, sfp[1]);
		qp->setCapabilities(capabilities);
	}
	RETURNvoid_();
}

//void QNetworkProxy.setHostName(String hostName);
KMETHOD QNetworkProxy_setHostName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy *  qp = RawPtr_to(QNetworkProxy *, sfp[0]);
	if (qp) {
		const QString hostName = String_to(const QString, sfp[1]);
		qp->setHostName(hostName);
	}
	RETURNvoid_();
}

//void QNetworkProxy.setPassword(String password);
KMETHOD QNetworkProxy_setPassword(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy *  qp = RawPtr_to(QNetworkProxy *, sfp[0]);
	if (qp) {
		const QString password = String_to(const QString, sfp[1]);
		qp->setPassword(password);
	}
	RETURNvoid_();
}

//void QNetworkProxy.setPort(int port);
KMETHOD QNetworkProxy_setPort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy *  qp = RawPtr_to(QNetworkProxy *, sfp[0]);
	if (qp) {
		quint16 port = Int_to(quint16, sfp[1]);
		qp->setPort(port);
	}
	RETURNvoid_();
}

//void QNetworkProxy.setType(int type);
KMETHOD QNetworkProxy_setType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy *  qp = RawPtr_to(QNetworkProxy *, sfp[0]);
	if (qp) {
		QNetworkProxy::ProxyType type = Int_to(QNetworkProxy::ProxyType, sfp[1]);
		qp->setType(type);
	}
	RETURNvoid_();
}

//void QNetworkProxy.setUser(String user);
KMETHOD QNetworkProxy_setUser(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy *  qp = RawPtr_to(QNetworkProxy *, sfp[0]);
	if (qp) {
		const QString user = String_to(const QString, sfp[1]);
		qp->setUser(user);
	}
	RETURNvoid_();
}

//int QNetworkProxy.getType();
KMETHOD QNetworkProxy_getType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy *  qp = RawPtr_to(QNetworkProxy *, sfp[0]);
	if (qp) {
		QNetworkProxy::ProxyType ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QNetworkProxy.getUser();
KMETHOD QNetworkProxy_getUser(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy *  qp = RawPtr_to(QNetworkProxy *, sfp[0]);
	if (qp) {
		QString ret_v = qp->user();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkProxy QNetworkProxy.getApplicationProxy();
KMETHOD QNetworkProxy_getApplicationProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QNetworkProxy ret_v = QNetworkProxy::applicationProxy();
		QNetworkProxy *ret_v_ = new QNetworkProxy(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QNetworkProxy.setApplicationProxy(QNetworkProxy networkProxy);
KMETHOD QNetworkProxy_setApplicationProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QNetworkProxy  networkProxy = *RawPtr_to(const QNetworkProxy *, sfp[1]);
		QNetworkProxy::setApplicationProxy(networkProxy);
	}
	RETURNvoid_();
}

//Array<String> QNetworkProxy.parents();
KMETHOD QNetworkProxy_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy *qp = RawPtr_to(QNetworkProxy*, sfp[0]);
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

DummyQNetworkProxy::DummyQNetworkProxy()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQNetworkProxy::setSelf(knh_RawPtr_t *ptr)
{
	DummyQNetworkProxy::self = ptr;
}

bool DummyQNetworkProxy::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQNetworkProxy::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkProxy::event_map->bigin();
	if ((itr = DummyQNetworkProxy::event_map->find(str)) == DummyQNetworkProxy::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQNetworkProxy::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkProxy::slot_map->bigin();
	if ((itr = DummyQNetworkProxy::slot_map->find(str)) == DummyQNetworkProxy::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQNetworkProxy::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQNetworkProxy::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQNetworkProxy::connection(QObject *o)
{
	QNetworkProxy *p = dynamic_cast<QNetworkProxy*>(o);
	if (p != NULL) {
	}
}

KQNetworkProxy::KQNetworkProxy() : QNetworkProxy()
{
	self = NULL;
	dummy = new DummyQNetworkProxy();
}

KMETHOD QNetworkProxy_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkProxy *qp = RawPtr_to(KQNetworkProxy *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkProxy]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkProxy]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QNetworkProxy_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkProxy *qp = RawPtr_to(KQNetworkProxy *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkProxy]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkProxy]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QNetworkProxy_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQNetworkProxy *qp = (KQNetworkProxy *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QNetworkProxy_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQNetworkProxy *qp = (KQNetworkProxy *)p->rawptr;
//		KQNetworkProxy *qp = static_cast<KQNetworkProxy*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QNetworkProxy_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QNetworkProxy*>(p1->rawptr) == *static_cast<QNetworkProxy*>(p2->rawptr) ? 0 : 1);
}

void KQNetworkProxy::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QNetworkProxyConstInt[] = {
	{"TunnelingCapability", QNetworkProxy::TunnelingCapability},
	{"ListeningCapability", QNetworkProxy::ListeningCapability},
	{"UdpTunnelingCapability", QNetworkProxy::UdpTunnelingCapability},
	{"CachingCapability", QNetworkProxy::CachingCapability},
	{"HostNameLookupCapability", QNetworkProxy::HostNameLookupCapability},
	{"NoProxy", QNetworkProxy::NoProxy},
	{"DefaultProxy", QNetworkProxy::DefaultProxy},
	{"Socks5Proxy", QNetworkProxy::Socks5Proxy},
	{"HttpProxy", QNetworkProxy::HttpProxy},
	{"HttpCachingProxy", QNetworkProxy::HttpCachingProxy},
	{"FtpCachingProxy", QNetworkProxy::FtpCachingProxy},
	{NULL, 0}
};

DEFAPI(void) constQNetworkProxy(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QNetworkProxyConstInt);
}


DEFAPI(void) defQNetworkProxy(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkProxy";
	cdef->free = QNetworkProxy_free;
	cdef->reftrace = QNetworkProxy_reftrace;
	cdef->compareTo = QNetworkProxy_compareTo;
}

//## QNetworkProxyCapabilities QNetworkProxyCapabilities.new(int value);
KMETHOD QNetworkProxyCapabilities_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkProxy::Capability i = Int_to(QNetworkProxy::Capability, sfp[1]);
	QNetworkProxy::Capabilities *ret_v = new QNetworkProxy::Capabilities(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QNetworkProxyCapabilities QNetworkProxyCapabilities.and(int mask);
KMETHOD QNetworkProxyCapabilities_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkProxy::Capabilities *qp = RawPtr_to(QNetworkProxy::Capabilities*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QNetworkProxy::Capabilities ret = ((*qp) & i);
		QNetworkProxy::Capabilities *ret_ = new QNetworkProxy::Capabilities(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkProxyCapabilities QNetworkProxyCapabilities.iand(QNetworkProxy::QNetworkProxyCapabilities other);
KMETHOD QNetworkProxyCapabilities_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkProxy::Capabilities *qp = RawPtr_to(QNetworkProxy::Capabilities*, sfp[0]);
	if (qp != NULL) {
		QNetworkProxy::Capabilities *other = RawPtr_to(QNetworkProxy::Capabilities *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkProxyCapabilities QNetworkProxyCapabilities.or(QNetworkProxyCapabilities f);
KMETHOD QNetworkProxyCapabilities_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy::Capabilities *qp = RawPtr_to(QNetworkProxy::Capabilities*, sfp[0]);
	if (qp != NULL) {
		QNetworkProxy::Capabilities *f = RawPtr_to(QNetworkProxy::Capabilities*, sfp[1]);
		QNetworkProxy::Capabilities ret = ((*qp) | (*f));
		QNetworkProxy::Capabilities *ret_ = new QNetworkProxy::Capabilities(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkProxyCapabilities QNetworkProxyCapabilities.ior(QNetworkProxy::QNetworkProxyCapabilities other);
KMETHOD QNetworkProxyCapabilities_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkProxy::Capabilities *qp = RawPtr_to(QNetworkProxy::Capabilities*, sfp[0]);
	if (qp != NULL) {
		QNetworkProxy::Capabilities *other = RawPtr_to(QNetworkProxy::Capabilities *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkProxyCapabilities QNetworkProxyCapabilities.xor(QNetworkProxyCapabilities f);
KMETHOD QNetworkProxyCapabilities_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxy::Capabilities *qp = RawPtr_to(QNetworkProxy::Capabilities*, sfp[0]);
	if (qp != NULL) {
		QNetworkProxy::Capabilities *f = RawPtr_to(QNetworkProxy::Capabilities*, sfp[1]);
		QNetworkProxy::Capabilities ret = ((*qp) ^ (*f));
		QNetworkProxy::Capabilities *ret_ = new QNetworkProxy::Capabilities(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkProxyCapabilities QNetworkProxyCapabilities.ixor(QNetworkProxy::QNetworkProxyCapabilities other);
KMETHOD QNetworkProxyCapabilities_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkProxy::Capabilities *qp = RawPtr_to(QNetworkProxy::Capabilities*, sfp[0]);
	if (qp != NULL) {
		QNetworkProxy::Capabilities *other = RawPtr_to(QNetworkProxy::Capabilities *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QNetworkProxyCapabilities.testFlag(int flag);
KMETHOD QNetworkProxyCapabilities_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkProxy::Capabilities *qp = RawPtr_to(QNetworkProxy::Capabilities *, sfp[0]);
	if (qp != NULL) {
		QNetworkProxy::Capability flag = Int_to(QNetworkProxy::Capability, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QNetworkProxyCapabilities.value();
KMETHOD QNetworkProxyCapabilities_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkProxy::Capabilities *qp = RawPtr_to(QNetworkProxy::Capabilities *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QNetworkProxyCapabilities_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QNetworkProxy::Capabilities *qp = (QNetworkProxy::Capabilities *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QNetworkProxyCapabilities_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QNetworkProxy::Capabilities *qp = (QNetworkProxy::Capabilities *)p->rawptr;
		(void)qp;
	}
}

static int QNetworkProxyCapabilities_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QNetworkProxy::Capabilities*)p1->rawptr);
//		int v2 = int(*(QNetworkProxy::Capabilities*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QNetworkProxy::Capabilities v1 = *(QNetworkProxy::Capabilities*)p1->rawptr;
		QNetworkProxy::Capabilities v2 = *(QNetworkProxy::Capabilities*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQNetworkProxyCapabilities(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkProxyCapabilities";
	cdef->free = QNetworkProxyCapabilities_free;
	cdef->reftrace = QNetworkProxyCapabilities_reftrace;
	cdef->compareTo = QNetworkProxyCapabilities_compareTo;
}

