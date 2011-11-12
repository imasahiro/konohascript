//QHostAddress QHostAddress.new();
KMETHOD QHostAddress_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHostAddress *ret_v = new KQHostAddress();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QHostAddress QHostAddress.new(int ip4Addr);
KMETHOD QHostAddress_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	quint32 ip4Addr = Int_to(quint32, sfp[1]);
	KQHostAddress *ret_v = new KQHostAddress(ip4Addr);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QHostAddress QHostAddress.new(int ip6Addr);
KMETHOD QHostAddress_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	quint8* ip6Addr = Int_to(quint8*, sfp[1]);
	KQHostAddress *ret_v = new KQHostAddress(ip6Addr);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QHostAddress QHostAddress.new(Q_IPV6ADDR ip6Addr);
KMETHOD QHostAddress_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const Q_IPV6ADDR  ip6Addr = *RawPtr_to(const Q_IPV6ADDR *, sfp[1]);
	KQHostAddress *ret_v = new KQHostAddress(ip6Addr);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QHostAddress QHostAddress.new(sockaddr sockaddr);
KMETHOD QHostAddress_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const sockaddr*  sockaddr = RawPtr_to(const sockaddr*, sfp[1]);
	KQHostAddress *ret_v = new KQHostAddress(sockaddr);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QHostAddress QHostAddress.new(String address);
KMETHOD QHostAddress_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString address = String_to(const QString, sfp[1]);
	KQHostAddress *ret_v = new KQHostAddress(address);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QHostAddress QHostAddress.new(QHostAddress address);
KMETHOD QHostAddress_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QHostAddress  address = *RawPtr_to(const QHostAddress *, sfp[1]);
	KQHostAddress *ret_v = new KQHostAddress(address);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QHostAddress QHostAddress.new(int address);
KMETHOD QHostAddress_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostAddress::SpecialAddress address = Int_to(QHostAddress::SpecialAddress, sfp[1]);
	KQHostAddress *ret_v = new KQHostAddress(address);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QHostAddress.clear();
KMETHOD QHostAddress_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostAddress *  qp = RawPtr_to(QHostAddress *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//boolean QHostAddress.isInSubnet(QHostAddress subnet, int netmask);
KMETHOD QHostAddress_isInSubnet(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostAddress *  qp = RawPtr_to(QHostAddress *, sfp[0]);
	if (qp) {
		const QHostAddress  subnet = *RawPtr_to(const QHostAddress *, sfp[1]);
		int netmask = Int_to(int, sfp[2]);
		bool ret_v = qp->isInSubnet(subnet, netmask);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QHostAddress.protocol();
KMETHOD QHostAddress_protocol(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostAddress *  qp = RawPtr_to(QHostAddress *, sfp[0]);
	if (qp) {
		QAbstractSocket::NetworkLayerProtocol ret_v = qp->protocol();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QHostAddress.getScopeId();
KMETHOD QHostAddress_getScopeId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostAddress *  qp = RawPtr_to(QHostAddress *, sfp[0]);
	if (qp) {
		QString ret_v = qp->scopeId();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QHostAddress.setAddress(int ip4Addr);
KMETHOD QHostAddress_setAddress(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostAddress *  qp = RawPtr_to(QHostAddress *, sfp[0]);
	if (qp) {
		quint32 ip4Addr = Int_to(quint32, sfp[1]);
		qp->setAddress(ip4Addr);
	}
	RETURNvoid_();
}

/*
//void QHostAddress.setAddress(int ip6Addr);
KMETHOD QHostAddress_setAddress(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostAddress *  qp = RawPtr_to(QHostAddress *, sfp[0]);
	if (qp) {
		quint8* ip6Addr = Int_to(quint8*, sfp[1]);
		qp->setAddress(ip6Addr);
	}
	RETURNvoid_();
}
*/
/*
//void QHostAddress.setAddress(Q_IPV6ADDR ip6Addr);
KMETHOD QHostAddress_setAddress(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostAddress *  qp = RawPtr_to(QHostAddress *, sfp[0]);
	if (qp) {
		const Q_IPV6ADDR  ip6Addr = *RawPtr_to(const Q_IPV6ADDR *, sfp[1]);
		qp->setAddress(ip6Addr);
	}
	RETURNvoid_();
}
*/
/*
//boolean QHostAddress.setAddress(String address);
KMETHOD QHostAddress_setAddress(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostAddress *  qp = RawPtr_to(QHostAddress *, sfp[0]);
	if (qp) {
		const QString address = String_to(const QString, sfp[1]);
		bool ret_v = qp->setAddress(address);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//void QHostAddress.setAddress(sockaddr sockaddr);
KMETHOD QHostAddress_setAddress(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostAddress *  qp = RawPtr_to(QHostAddress *, sfp[0]);
	if (qp) {
		const sockaddr*  sockaddr = RawPtr_to(const sockaddr*, sfp[1]);
		qp->setAddress(sockaddr);
	}
	RETURNvoid_();
}
*/
//void QHostAddress.setScopeId(String id);
KMETHOD QHostAddress_setScopeId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostAddress *  qp = RawPtr_to(QHostAddress *, sfp[0]);
	if (qp) {
		const QString id = String_to(const QString, sfp[1]);
		qp->setScopeId(id);
	}
	RETURNvoid_();
}

//int QHostAddress.toIPv4Address();
KMETHOD QHostAddress_toIPv4Address(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostAddress *  qp = RawPtr_to(QHostAddress *, sfp[0]);
	if (qp) {
		quint32 ret_v = qp->toIPv4Address();
		quint32 *ret_v_ = new quint32(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Q_IPV6ADDR QHostAddress.toIPv6Address();
KMETHOD QHostAddress_toIPv6Address(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostAddress *  qp = RawPtr_to(QHostAddress *, sfp[0]);
	if (qp) {
		Q_IPV6ADDR ret_v = qp->toIPv6Address();
		Q_IPV6ADDR *ret_v_ = new Q_IPV6ADDR(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QHostAddress.toString();
KMETHOD QHostAddress_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostAddress *  qp = RawPtr_to(QHostAddress *, sfp[0]);
	if (qp) {
		QString ret_v = qp->toString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QHostAddress.parents();
KMETHOD QHostAddress_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHostAddress *qp = RawPtr_to(QHostAddress*, sfp[0]);
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

DummyQHostAddress::DummyQHostAddress()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQHostAddress::setSelf(knh_RawPtr_t *ptr)
{
	DummyQHostAddress::self = ptr;
}

bool DummyQHostAddress::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQHostAddress::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHostAddress::event_map->bigin();
	if ((itr = DummyQHostAddress::event_map->find(str)) == DummyQHostAddress::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQHostAddress::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHostAddress::slot_map->bigin();
	if ((itr = DummyQHostAddress::slot_map->find(str)) == DummyQHostAddress::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQHostAddress::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQHostAddress::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQHostAddress::connection(QObject *o)
{
	QHostAddress *p = dynamic_cast<QHostAddress*>(o);
	if (p != NULL) {
	}
}

KQHostAddress::KQHostAddress() : QHostAddress()
{
	self = NULL;
	dummy = new DummyQHostAddress();
}

KMETHOD QHostAddress_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHostAddress *qp = RawPtr_to(KQHostAddress *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QHostAddress]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHostAddress]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QHostAddress_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHostAddress *qp = RawPtr_to(KQHostAddress *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QHostAddress]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHostAddress]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QHostAddress_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQHostAddress *qp = (KQHostAddress *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QHostAddress_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQHostAddress *qp = (KQHostAddress *)p->rawptr;
//		KQHostAddress *qp = static_cast<KQHostAddress*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QHostAddress_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QHostAddress*>(p1->rawptr) == *static_cast<QHostAddress*>(p2->rawptr) ? 0 : 1);
}

void KQHostAddress::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QHostAddressConstInt[] = {
	{"Null", QHostAddress::Null},
	{"LocalHost", QHostAddress::LocalHost},
	{"LocalHostIPv6", QHostAddress::LocalHostIPv6},
	{"Broadcast", QHostAddress::Broadcast},
	{"Any", QHostAddress::Any},
	{"AnyIPv6", QHostAddress::AnyIPv6},
	{NULL, 0}
};

DEFAPI(void) constQHostAddress(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QHostAddressConstInt);
}


DEFAPI(void) defQHostAddress(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QHostAddress";
	cdef->free = QHostAddress_free;
	cdef->reftrace = QHostAddress_reftrace;
	cdef->compareTo = QHostAddress_compareTo;
}


