//QNetworkConfiguration QNetworkConfiguration.new();
KMETHOD QNetworkConfiguration_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkConfiguration *ret_v = new KQNetworkConfiguration();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QNetworkConfiguration QNetworkConfiguration.new(QNetworkConfiguration other);
KMETHOD QNetworkConfiguration_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QNetworkConfiguration  other = *RawPtr_to(const QNetworkConfiguration *, sfp[1]);
	KQNetworkConfiguration *ret_v = new KQNetworkConfiguration(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//String QNetworkConfiguration.bearerName();
KMETHOD QNetworkConfiguration_bearerName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfiguration *  qp = RawPtr_to(QNetworkConfiguration *, sfp[0]);
	if (qp) {
		QString ret_v = qp->bearerName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QNetworkConfiguration.bearerType();
KMETHOD QNetworkConfiguration_bearerType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfiguration *  qp = RawPtr_to(QNetworkConfiguration *, sfp[0]);
	if (qp) {
		QNetworkConfiguration::BearerType ret_v = qp->bearerType();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QNetworkConfiguration.bearerTypeName();
KMETHOD QNetworkConfiguration_bearerTypeName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfiguration *  qp = RawPtr_to(QNetworkConfiguration *, sfp[0]);
	if (qp) {
		QString ret_v = qp->bearerTypeName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QNetworkConfiguration> QNetworkConfiguration.children();
KMETHOD QNetworkConfiguration_children(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfiguration *  qp = RawPtr_to(QNetworkConfiguration *, sfp[0]);
	if (qp) {
		QList<QNetworkConfiguration> ret_v = qp->children();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QNetworkConfiguration"));
		for (int n = 0; n < list_size; n++) {
			QNetworkConfiguration *ret_v_ = new QNetworkConfiguration(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//String QNetworkConfiguration.identifier();
KMETHOD QNetworkConfiguration_identifier(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfiguration *  qp = RawPtr_to(QNetworkConfiguration *, sfp[0]);
	if (qp) {
		QString ret_v = qp->identifier();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QNetworkConfiguration.isRoamingAvailable();
KMETHOD QNetworkConfiguration_isRoamingAvailable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfiguration *  qp = RawPtr_to(QNetworkConfiguration *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isRoamingAvailable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QNetworkConfiguration.name();
KMETHOD QNetworkConfiguration_name(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfiguration *  qp = RawPtr_to(QNetworkConfiguration *, sfp[0]);
	if (qp) {
		QString ret_v = qp->name();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QNetworkConfiguration.purpose();
KMETHOD QNetworkConfiguration_purpose(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfiguration *  qp = RawPtr_to(QNetworkConfiguration *, sfp[0]);
	if (qp) {
		QNetworkConfiguration::Purpose ret_v = qp->purpose();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QNetworkConfigurationStateFlags QNetworkConfiguration.state();
KMETHOD QNetworkConfiguration_state(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfiguration *  qp = RawPtr_to(QNetworkConfiguration *, sfp[0]);
	if (qp) {
		QNetworkConfiguration::StateFlags ret_v = qp->state();
		QNetworkConfiguration::StateFlags *ret_v_ = new QNetworkConfiguration::StateFlags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QNetworkConfiguration.type();
KMETHOD QNetworkConfiguration_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfiguration *  qp = RawPtr_to(QNetworkConfiguration *, sfp[0]);
	if (qp) {
		QNetworkConfiguration::Type ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<String> QNetworkConfiguration.parents();
KMETHOD QNetworkConfiguration_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfiguration *qp = RawPtr_to(QNetworkConfiguration*, sfp[0]);
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

DummyQNetworkConfiguration::DummyQNetworkConfiguration()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQNetworkConfiguration::setSelf(knh_RawPtr_t *ptr)
{
	DummyQNetworkConfiguration::self = ptr;
}

bool DummyQNetworkConfiguration::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQNetworkConfiguration::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkConfiguration::event_map->bigin();
	if ((itr = DummyQNetworkConfiguration::event_map->find(str)) == DummyQNetworkConfiguration::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQNetworkConfiguration::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkConfiguration::slot_map->bigin();
	if ((itr = DummyQNetworkConfiguration::slot_map->find(str)) == DummyQNetworkConfiguration::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQNetworkConfiguration::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQNetworkConfiguration::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQNetworkConfiguration::connection(QObject *o)
{
	QNetworkConfiguration *p = dynamic_cast<QNetworkConfiguration*>(o);
	if (p != NULL) {
	}
}

KQNetworkConfiguration::KQNetworkConfiguration() : QNetworkConfiguration()
{
	self = NULL;
	dummy = new DummyQNetworkConfiguration();
}

KMETHOD QNetworkConfiguration_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkConfiguration *qp = RawPtr_to(KQNetworkConfiguration *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkConfiguration]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkConfiguration]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QNetworkConfiguration_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkConfiguration *qp = RawPtr_to(KQNetworkConfiguration *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkConfiguration]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkConfiguration]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QNetworkConfiguration_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQNetworkConfiguration *qp = (KQNetworkConfiguration *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QNetworkConfiguration_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQNetworkConfiguration *qp = (KQNetworkConfiguration *)p->rawptr;
//		KQNetworkConfiguration *qp = static_cast<KQNetworkConfiguration*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QNetworkConfiguration_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QNetworkConfiguration*>(p1->rawptr) == *static_cast<QNetworkConfiguration*>(p2->rawptr) ? 0 : 1);
}

void KQNetworkConfiguration::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QNetworkConfigurationConstInt[] = {
	{"BearerUnknown", QNetworkConfiguration::BearerUnknown},
	{"BearerEthernet", QNetworkConfiguration::BearerEthernet},
	{"BearerWLAN", QNetworkConfiguration::BearerWLAN},
	{"Bearer2G", QNetworkConfiguration::Bearer2G},
	{"BearerCDMA2000", QNetworkConfiguration::BearerCDMA2000},
	{"BearerWCDMA", QNetworkConfiguration::BearerWCDMA},
	{"BearerHSPA", QNetworkConfiguration::BearerHSPA},
	{"BearerBluetooth", QNetworkConfiguration::BearerBluetooth},
	{"BearerWiMAX", QNetworkConfiguration::BearerWiMAX},
	{"UnknownPurpose", QNetworkConfiguration::UnknownPurpose},
	{"PublicPurpose", QNetworkConfiguration::PublicPurpose},
	{"PrivatePurpose", QNetworkConfiguration::PrivatePurpose},
	{"ServiceSpecificPurpose", QNetworkConfiguration::ServiceSpecificPurpose},
	{"Undefined", QNetworkConfiguration::Undefined},
	{"Defined", QNetworkConfiguration::Defined},
	{"Discovered", QNetworkConfiguration::Discovered},
	{"Active", QNetworkConfiguration::Active},
	{"InternetAccessPoint", QNetworkConfiguration::InternetAccessPoint},
	{"ServiceNetwork", QNetworkConfiguration::ServiceNetwork},
	{"UserChoice", QNetworkConfiguration::UserChoice},
	{"Invalid", QNetworkConfiguration::Invalid},
	{NULL, 0}
};

DEFAPI(void) constQNetworkConfiguration(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QNetworkConfigurationConstInt);
}


DEFAPI(void) defQNetworkConfiguration(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkConfiguration";
	cdef->free = QNetworkConfiguration_free;
	cdef->reftrace = QNetworkConfiguration_reftrace;
	cdef->compareTo = QNetworkConfiguration_compareTo;
}

//## QNetworkConfigurationStateFlags QNetworkConfigurationStateFlags.new(int value);
KMETHOD QNetworkConfigurationStateFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkConfiguration::StateFlag i = Int_to(QNetworkConfiguration::StateFlag, sfp[1]);
	QNetworkConfiguration::StateFlags *ret_v = new QNetworkConfiguration::StateFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QNetworkConfigurationStateFlags QNetworkConfigurationStateFlags.and(int mask);
KMETHOD QNetworkConfigurationStateFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkConfiguration::StateFlags *qp = RawPtr_to(QNetworkConfiguration::StateFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QNetworkConfiguration::StateFlags ret = ((*qp) & i);
		QNetworkConfiguration::StateFlags *ret_ = new QNetworkConfiguration::StateFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkConfigurationStateFlags QNetworkConfigurationStateFlags.iand(QNetworkConfiguration::QNetworkConfigurationStateFlags other);
KMETHOD QNetworkConfigurationStateFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkConfiguration::StateFlags *qp = RawPtr_to(QNetworkConfiguration::StateFlags*, sfp[0]);
	if (qp != NULL) {
		QNetworkConfiguration::StateFlags *other = RawPtr_to(QNetworkConfiguration::StateFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkConfigurationStateFlags QNetworkConfigurationStateFlags.or(QNetworkConfigurationStateFlags f);
KMETHOD QNetworkConfigurationStateFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfiguration::StateFlags *qp = RawPtr_to(QNetworkConfiguration::StateFlags*, sfp[0]);
	if (qp != NULL) {
		QNetworkConfiguration::StateFlags *f = RawPtr_to(QNetworkConfiguration::StateFlags*, sfp[1]);
		QNetworkConfiguration::StateFlags ret = ((*qp) | (*f));
		QNetworkConfiguration::StateFlags *ret_ = new QNetworkConfiguration::StateFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkConfigurationStateFlags QNetworkConfigurationStateFlags.ior(QNetworkConfiguration::QNetworkConfigurationStateFlags other);
KMETHOD QNetworkConfigurationStateFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkConfiguration::StateFlags *qp = RawPtr_to(QNetworkConfiguration::StateFlags*, sfp[0]);
	if (qp != NULL) {
		QNetworkConfiguration::StateFlags *other = RawPtr_to(QNetworkConfiguration::StateFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkConfigurationStateFlags QNetworkConfigurationStateFlags.xor(QNetworkConfigurationStateFlags f);
KMETHOD QNetworkConfigurationStateFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfiguration::StateFlags *qp = RawPtr_to(QNetworkConfiguration::StateFlags*, sfp[0]);
	if (qp != NULL) {
		QNetworkConfiguration::StateFlags *f = RawPtr_to(QNetworkConfiguration::StateFlags*, sfp[1]);
		QNetworkConfiguration::StateFlags ret = ((*qp) ^ (*f));
		QNetworkConfiguration::StateFlags *ret_ = new QNetworkConfiguration::StateFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkConfigurationStateFlags QNetworkConfigurationStateFlags.ixor(QNetworkConfiguration::QNetworkConfigurationStateFlags other);
KMETHOD QNetworkConfigurationStateFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkConfiguration::StateFlags *qp = RawPtr_to(QNetworkConfiguration::StateFlags*, sfp[0]);
	if (qp != NULL) {
		QNetworkConfiguration::StateFlags *other = RawPtr_to(QNetworkConfiguration::StateFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QNetworkConfigurationStateFlags.testFlag(int flag);
KMETHOD QNetworkConfigurationStateFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkConfiguration::StateFlags *qp = RawPtr_to(QNetworkConfiguration::StateFlags *, sfp[0]);
	if (qp != NULL) {
		QNetworkConfiguration::StateFlag flag = Int_to(QNetworkConfiguration::StateFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QNetworkConfigurationStateFlags.value();
KMETHOD QNetworkConfigurationStateFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkConfiguration::StateFlags *qp = RawPtr_to(QNetworkConfiguration::StateFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QNetworkConfigurationStateFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QNetworkConfiguration::StateFlags *qp = (QNetworkConfiguration::StateFlags *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QNetworkConfigurationStateFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QNetworkConfiguration::StateFlags *qp = (QNetworkConfiguration::StateFlags *)p->rawptr;
		(void)qp;
	}
}

static int QNetworkConfigurationStateFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QNetworkConfiguration::StateFlags*)p1->rawptr);
//		int v2 = int(*(QNetworkConfiguration::StateFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QNetworkConfiguration::StateFlags v1 = *(QNetworkConfiguration::StateFlags*)p1->rawptr;
		QNetworkConfiguration::StateFlags v2 = *(QNetworkConfiguration::StateFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQNetworkConfigurationStateFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkConfigurationStateFlags";
	cdef->free = QNetworkConfigurationStateFlags_free;
	cdef->reftrace = QNetworkConfigurationStateFlags_reftrace;
	cdef->compareTo = QNetworkConfigurationStateFlags_compareTo;
}

