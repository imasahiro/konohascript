//QNetworkAddressEntry QNetworkAddressEntry.new();
KMETHOD QNetworkAddressEntry_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkAddressEntry *ret_v = new KQNetworkAddressEntry();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QNetworkAddressEntry QNetworkAddressEntry.new(QNetworkAddressEntry other);
KMETHOD QNetworkAddressEntry_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QNetworkAddressEntry  other = *RawPtr_to(const QNetworkAddressEntry *, sfp[1]);
	KQNetworkAddressEntry *ret_v = new KQNetworkAddressEntry(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QHostAddress QNetworkAddressEntry.getBroadcast();
KMETHOD QNetworkAddressEntry_getBroadcast(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAddressEntry *  qp = RawPtr_to(QNetworkAddressEntry *, sfp[0]);
	if (qp) {
		QHostAddress ret_v = qp->broadcast();
		QHostAddress *ret_v_ = new QHostAddress(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QHostAddress QNetworkAddressEntry.getIp();
KMETHOD QNetworkAddressEntry_getIp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAddressEntry *  qp = RawPtr_to(QNetworkAddressEntry *, sfp[0]);
	if (qp) {
		QHostAddress ret_v = qp->ip();
		QHostAddress *ret_v_ = new QHostAddress(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QHostAddress QNetworkAddressEntry.getNetmask();
KMETHOD QNetworkAddressEntry_getNetmask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAddressEntry *  qp = RawPtr_to(QNetworkAddressEntry *, sfp[0]);
	if (qp) {
		QHostAddress ret_v = qp->netmask();
		QHostAddress *ret_v_ = new QHostAddress(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QNetworkAddressEntry.getPrefixLength();
KMETHOD QNetworkAddressEntry_getPrefixLength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAddressEntry *  qp = RawPtr_to(QNetworkAddressEntry *, sfp[0]);
	if (qp) {
		int ret_v = qp->prefixLength();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QNetworkAddressEntry.setBroadcast(QHostAddress new_Broadcast);
KMETHOD QNetworkAddressEntry_setBroadcast(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAddressEntry *  qp = RawPtr_to(QNetworkAddressEntry *, sfp[0]);
	if (qp) {
		const QHostAddress  new_Broadcast = *RawPtr_to(const QHostAddress *, sfp[1]);
		qp->setBroadcast(new_Broadcast);
	}
	RETURNvoid_();
}

//void QNetworkAddressEntry.setIp(QHostAddress new_Ip);
KMETHOD QNetworkAddressEntry_setIp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAddressEntry *  qp = RawPtr_to(QNetworkAddressEntry *, sfp[0]);
	if (qp) {
		const QHostAddress  new_Ip = *RawPtr_to(const QHostAddress *, sfp[1]);
		qp->setIp(new_Ip);
	}
	RETURNvoid_();
}

//void QNetworkAddressEntry.setNetmask(QHostAddress new_Netmask);
KMETHOD QNetworkAddressEntry_setNetmask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAddressEntry *  qp = RawPtr_to(QNetworkAddressEntry *, sfp[0]);
	if (qp) {
		const QHostAddress  new_Netmask = *RawPtr_to(const QHostAddress *, sfp[1]);
		qp->setNetmask(new_Netmask);
	}
	RETURNvoid_();
}

//void QNetworkAddressEntry.setPrefixLength(int length);
KMETHOD QNetworkAddressEntry_setPrefixLength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAddressEntry *  qp = RawPtr_to(QNetworkAddressEntry *, sfp[0]);
	if (qp) {
		int length = Int_to(int, sfp[1]);
		qp->setPrefixLength(length);
	}
	RETURNvoid_();
}

//Array<String> QNetworkAddressEntry.parents();
KMETHOD QNetworkAddressEntry_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkAddressEntry *qp = RawPtr_to(QNetworkAddressEntry*, sfp[0]);
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

DummyQNetworkAddressEntry::DummyQNetworkAddressEntry()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQNetworkAddressEntry::setSelf(knh_RawPtr_t *ptr)
{
	DummyQNetworkAddressEntry::self = ptr;
}

bool DummyQNetworkAddressEntry::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQNetworkAddressEntry::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkAddressEntry::event_map->bigin();
	if ((itr = DummyQNetworkAddressEntry::event_map->find(str)) == DummyQNetworkAddressEntry::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQNetworkAddressEntry::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkAddressEntry::slot_map->bigin();
	if ((itr = DummyQNetworkAddressEntry::slot_map->find(str)) == DummyQNetworkAddressEntry::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQNetworkAddressEntry::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQNetworkAddressEntry::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQNetworkAddressEntry::connection(QObject *o)
{
	QNetworkAddressEntry *p = dynamic_cast<QNetworkAddressEntry*>(o);
	if (p != NULL) {
	}
}

KQNetworkAddressEntry::KQNetworkAddressEntry() : QNetworkAddressEntry()
{
	self = NULL;
	dummy = new DummyQNetworkAddressEntry();
}

KMETHOD QNetworkAddressEntry_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkAddressEntry *qp = RawPtr_to(KQNetworkAddressEntry *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkAddressEntry]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkAddressEntry]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QNetworkAddressEntry_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkAddressEntry *qp = RawPtr_to(KQNetworkAddressEntry *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkAddressEntry]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkAddressEntry]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QNetworkAddressEntry_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQNetworkAddressEntry *qp = (KQNetworkAddressEntry *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QNetworkAddressEntry_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQNetworkAddressEntry *qp = (KQNetworkAddressEntry *)p->rawptr;
//		KQNetworkAddressEntry *qp = static_cast<KQNetworkAddressEntry*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QNetworkAddressEntry_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QNetworkAddressEntry*>(p1->rawptr) == *static_cast<QNetworkAddressEntry*>(p2->rawptr) ? 0 : 1);
}

void KQNetworkAddressEntry::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQNetworkAddressEntry(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkAddressEntry";
	cdef->free = QNetworkAddressEntry_free;
	cdef->reftrace = QNetworkAddressEntry_reftrace;
	cdef->compareTo = QNetworkAddressEntry_compareTo;
}


