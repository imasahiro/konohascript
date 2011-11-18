//QNetworkInterface QNetworkInterface.new();
KMETHOD QNetworkInterface_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkInterface *ret_v = new KQNetworkInterface();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QNetworkInterface QNetworkInterface.new(QNetworkInterface other);
KMETHOD QNetworkInterface_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QNetworkInterface  other = *RawPtr_to(const QNetworkInterface *, sfp[1]);
	KQNetworkInterface *ret_v = new KQNetworkInterface(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//Array<QNetworkAddressEntry> QNetworkInterface.addressEntries();
KMETHOD QNetworkInterface_addressEntries(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkInterface *  qp = RawPtr_to(QNetworkInterface *, sfp[0]);
	if (qp) {
		QList<QNetworkAddressEntry> ret_v = qp->addressEntries();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QNetworkAddressEntry"));
		for (int n = 0; n < list_size; n++) {
			QNetworkAddressEntry *ret_v_ = new QNetworkAddressEntry(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QNetworkInterfaceInterfaceFlags QNetworkInterface.flags();
KMETHOD QNetworkInterface_flags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkInterface *  qp = RawPtr_to(QNetworkInterface *, sfp[0]);
	if (qp) {
		QNetworkInterface::InterfaceFlags ret_v = qp->flags();
		QNetworkInterface::InterfaceFlags *ret_v_ = new QNetworkInterface::InterfaceFlags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QNetworkInterface.hardwareAddress();
KMETHOD QNetworkInterface_hardwareAddress(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkInterface *  qp = RawPtr_to(QNetworkInterface *, sfp[0]);
	if (qp) {
		QString ret_v = qp->hardwareAddress();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QNetworkInterface.humanReadableName();
KMETHOD QNetworkInterface_humanReadableName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkInterface *  qp = RawPtr_to(QNetworkInterface *, sfp[0]);
	if (qp) {
		QString ret_v = qp->humanReadableName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QNetworkInterface.index();
KMETHOD QNetworkInterface_index(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkInterface *  qp = RawPtr_to(QNetworkInterface *, sfp[0]);
	if (qp) {
		int ret_v = qp->index();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QNetworkInterface.name();
KMETHOD QNetworkInterface_name(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkInterface *  qp = RawPtr_to(QNetworkInterface *, sfp[0]);
	if (qp) {
		QString ret_v = qp->name();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QHostAddress> QNetworkInterface.allAddresses();
KMETHOD QNetworkInterface_allAddresses(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QList<QHostAddress> ret_v = QNetworkInterface::allAddresses();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QHostAddress"));
		for (int n = 0; n < list_size; n++) {
			QHostAddress *ret_v_ = new QHostAddress(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//Array<QNetworkInterface> QNetworkInterface.allInterfaces();
KMETHOD QNetworkInterface_allInterfaces(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QList<QNetworkInterface> ret_v = QNetworkInterface::allInterfaces();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QNetworkInterface"));
		for (int n = 0; n < list_size; n++) {
			QNetworkInterface *ret_v_ = new QNetworkInterface(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QNetworkInterface QNetworkInterface.interfaceFromIndex(int index);
KMETHOD QNetworkInterface_interfaceFromIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int index = Int_to(int, sfp[1]);
		QNetworkInterface ret_v = QNetworkInterface::interfaceFromIndex(index);
		QNetworkInterface *ret_v_ = new QNetworkInterface(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkInterface QNetworkInterface.interfaceFromName(String name);
KMETHOD QNetworkInterface_interfaceFromName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString name = String_to(const QString, sfp[1]);
		QNetworkInterface ret_v = QNetworkInterface::interfaceFromName(name);
		QNetworkInterface *ret_v_ = new QNetworkInterface(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QNetworkInterface.parents();
KMETHOD QNetworkInterface_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkInterface *qp = RawPtr_to(QNetworkInterface*, sfp[0]);
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

DummyQNetworkInterface::DummyQNetworkInterface()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQNetworkInterface::~DummyQNetworkInterface()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQNetworkInterface::setSelf(knh_RawPtr_t *ptr)
{
	DummyQNetworkInterface::self = ptr;
}

bool DummyQNetworkInterface::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQNetworkInterface::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkInterface::event_map->bigin();
	if ((itr = DummyQNetworkInterface::event_map->find(str)) == DummyQNetworkInterface::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQNetworkInterface::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkInterface::slot_map->bigin();
	if ((itr = DummyQNetworkInterface::slot_map->find(str)) == DummyQNetworkInterface::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQNetworkInterface::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQNetworkInterface::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQNetworkInterface::connection(QObject *o)
{
	QNetworkInterface *p = dynamic_cast<QNetworkInterface*>(o);
	if (p != NULL) {
	}
}

KQNetworkInterface::KQNetworkInterface() : QNetworkInterface()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQNetworkInterface();
}

KQNetworkInterface::~KQNetworkInterface()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QNetworkInterface_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkInterface *qp = RawPtr_to(KQNetworkInterface *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkInterface]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkInterface]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QNetworkInterface_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkInterface *qp = RawPtr_to(KQNetworkInterface *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkInterface]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkInterface]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QNetworkInterface_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQNetworkInterface *qp = (KQNetworkInterface *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QNetworkInterface*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QNetworkInterface_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQNetworkInterface *qp = (KQNetworkInterface *)p->rawptr;
		KQNetworkInterface *qp = static_cast<KQNetworkInterface*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QNetworkInterface_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQNetworkInterface::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QNetworkInterfaceConstInt[] = {
	{"IsUp", QNetworkInterface::IsUp},
	{"IsRunning", QNetworkInterface::IsRunning},
	{"CanBroadcast", QNetworkInterface::CanBroadcast},
	{"IsLoopBack", QNetworkInterface::IsLoopBack},
	{"IsPointToPoint", QNetworkInterface::IsPointToPoint},
	{"CanMulticast", QNetworkInterface::CanMulticast},
	{NULL, 0}
};

DEFAPI(void) constQNetworkInterface(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QNetworkInterfaceConstInt);
}


DEFAPI(void) defQNetworkInterface(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkInterface";
	cdef->free = QNetworkInterface_free;
	cdef->reftrace = QNetworkInterface_reftrace;
	cdef->compareTo = QNetworkInterface_compareTo;
}

//## QNetworkInterfaceInterfaceFlags QNetworkInterfaceInterfaceFlags.new(int value);
KMETHOD QNetworkInterfaceInterfaceFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkInterface::InterfaceFlag i = Int_to(QNetworkInterface::InterfaceFlag, sfp[1]);
	QNetworkInterface::InterfaceFlags *ret_v = new QNetworkInterface::InterfaceFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QNetworkInterfaceInterfaceFlags QNetworkInterfaceInterfaceFlags.and(int mask);
KMETHOD QNetworkInterfaceInterfaceFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkInterface::InterfaceFlags *qp = RawPtr_to(QNetworkInterface::InterfaceFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QNetworkInterface::InterfaceFlags ret = ((*qp) & i);
		QNetworkInterface::InterfaceFlags *ret_ = new QNetworkInterface::InterfaceFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkInterfaceInterfaceFlags QNetworkInterfaceInterfaceFlags.iand(QNetworkInterface::QNetworkInterfaceInterfaceFlags other);
KMETHOD QNetworkInterfaceInterfaceFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkInterface::InterfaceFlags *qp = RawPtr_to(QNetworkInterface::InterfaceFlags*, sfp[0]);
	if (qp != NULL) {
		QNetworkInterface::InterfaceFlags *other = RawPtr_to(QNetworkInterface::InterfaceFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkInterfaceInterfaceFlags QNetworkInterfaceInterfaceFlags.or(QNetworkInterfaceInterfaceFlags f);
KMETHOD QNetworkInterfaceInterfaceFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkInterface::InterfaceFlags *qp = RawPtr_to(QNetworkInterface::InterfaceFlags*, sfp[0]);
	if (qp != NULL) {
		QNetworkInterface::InterfaceFlags *f = RawPtr_to(QNetworkInterface::InterfaceFlags*, sfp[1]);
		QNetworkInterface::InterfaceFlags ret = ((*qp) | (*f));
		QNetworkInterface::InterfaceFlags *ret_ = new QNetworkInterface::InterfaceFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkInterfaceInterfaceFlags QNetworkInterfaceInterfaceFlags.ior(QNetworkInterface::QNetworkInterfaceInterfaceFlags other);
KMETHOD QNetworkInterfaceInterfaceFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkInterface::InterfaceFlags *qp = RawPtr_to(QNetworkInterface::InterfaceFlags*, sfp[0]);
	if (qp != NULL) {
		QNetworkInterface::InterfaceFlags *other = RawPtr_to(QNetworkInterface::InterfaceFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkInterfaceInterfaceFlags QNetworkInterfaceInterfaceFlags.xor(QNetworkInterfaceInterfaceFlags f);
KMETHOD QNetworkInterfaceInterfaceFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkInterface::InterfaceFlags *qp = RawPtr_to(QNetworkInterface::InterfaceFlags*, sfp[0]);
	if (qp != NULL) {
		QNetworkInterface::InterfaceFlags *f = RawPtr_to(QNetworkInterface::InterfaceFlags*, sfp[1]);
		QNetworkInterface::InterfaceFlags ret = ((*qp) ^ (*f));
		QNetworkInterface::InterfaceFlags *ret_ = new QNetworkInterface::InterfaceFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkInterfaceInterfaceFlags QNetworkInterfaceInterfaceFlags.ixor(QNetworkInterface::QNetworkInterfaceInterfaceFlags other);
KMETHOD QNetworkInterfaceInterfaceFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkInterface::InterfaceFlags *qp = RawPtr_to(QNetworkInterface::InterfaceFlags*, sfp[0]);
	if (qp != NULL) {
		QNetworkInterface::InterfaceFlags *other = RawPtr_to(QNetworkInterface::InterfaceFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QNetworkInterfaceInterfaceFlags.testFlag(int flag);
KMETHOD QNetworkInterfaceInterfaceFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkInterface::InterfaceFlags *qp = RawPtr_to(QNetworkInterface::InterfaceFlags *, sfp[0]);
	if (qp != NULL) {
		QNetworkInterface::InterfaceFlag flag = Int_to(QNetworkInterface::InterfaceFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QNetworkInterfaceInterfaceFlags.value();
KMETHOD QNetworkInterfaceInterfaceFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkInterface::InterfaceFlags *qp = RawPtr_to(QNetworkInterface::InterfaceFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QNetworkInterfaceInterfaceFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QNetworkInterface::InterfaceFlags *qp = (QNetworkInterface::InterfaceFlags *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QNetworkInterfaceInterfaceFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QNetworkInterface::InterfaceFlags *qp = (QNetworkInterface::InterfaceFlags *)p->rawptr;
		(void)qp;
	}
}

static int QNetworkInterfaceInterfaceFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QNetworkInterface::InterfaceFlags*)p1->rawptr);
//		int v2 = int(*(QNetworkInterface::InterfaceFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QNetworkInterface::InterfaceFlags v1 = *(QNetworkInterface::InterfaceFlags*)p1->rawptr;
		QNetworkInterface::InterfaceFlags v2 = *(QNetworkInterface::InterfaceFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQNetworkInterfaceInterfaceFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkInterfaceInterfaceFlags";
	cdef->free = QNetworkInterfaceInterfaceFlags_free;
	cdef->reftrace = QNetworkInterfaceInterfaceFlags_reftrace;
	cdef->compareTo = QNetworkInterfaceInterfaceFlags_compareTo;
}

