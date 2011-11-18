//QNetworkConfigurationManager QNetworkConfigurationManager.new(QObject parent);
KMETHOD QNetworkConfigurationManager_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQNetworkConfigurationManager *ret_v = new KQNetworkConfigurationManager(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//Array<QNetworkConfiguration> QNetworkConfigurationManager.allConfigurations(int filter);
KMETHOD QNetworkConfigurationManager_allConfigurations(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfigurationManager *  qp = RawPtr_to(QNetworkConfigurationManager *, sfp[0]);
	if (qp) {
		QNetworkConfiguration::StateFlags filter = Int_to(QNetworkConfiguration::StateFlags, sfp[1]);
		QList<QNetworkConfiguration> ret_v = qp->allConfigurations(filter);
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
	

//QNetworkConfigurationManagerCapabilities QNetworkConfigurationManager.capabilities();
KMETHOD QNetworkConfigurationManager_capabilities(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfigurationManager *  qp = RawPtr_to(QNetworkConfigurationManager *, sfp[0]);
	if (qp) {
		QNetworkConfigurationManager::Capabilities ret_v = qp->capabilities();
		QNetworkConfigurationManager::Capabilities *ret_v_ = new QNetworkConfigurationManager::Capabilities(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkConfiguration QNetworkConfigurationManager.configurationFromIdentifier(String identifier);
KMETHOD QNetworkConfigurationManager_configurationFromIdentifier(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfigurationManager *  qp = RawPtr_to(QNetworkConfigurationManager *, sfp[0]);
	if (qp) {
		const QString identifier = String_to(const QString, sfp[1]);
		QNetworkConfiguration ret_v = qp->configurationFromIdentifier(identifier);
		QNetworkConfiguration *ret_v_ = new QNetworkConfiguration(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkConfiguration QNetworkConfigurationManager.defaultConfiguration();
KMETHOD QNetworkConfigurationManager_defaultConfiguration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfigurationManager *  qp = RawPtr_to(QNetworkConfigurationManager *, sfp[0]);
	if (qp) {
		QNetworkConfiguration ret_v = qp->defaultConfiguration();
		QNetworkConfiguration *ret_v_ = new QNetworkConfiguration(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QNetworkConfigurationManager.isOnline();
KMETHOD QNetworkConfigurationManager_isOnline(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfigurationManager *  qp = RawPtr_to(QNetworkConfigurationManager *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isOnline();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QNetworkConfigurationManager.updateConfigurations();
KMETHOD QNetworkConfigurationManager_updateConfigurations(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfigurationManager *  qp = RawPtr_to(QNetworkConfigurationManager *, sfp[0]);
	if (qp) {
		qp->updateConfigurations();
	}
	RETURNvoid_();
}


DummyQNetworkConfigurationManager::DummyQNetworkConfigurationManager()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	configuration_added_func = NULL;
	configuration_changed_func = NULL;
	configuration_removed_func = NULL;
	online_state_changed_func = NULL;
	update_completed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("configuration-added", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("configuration-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("configuration-removed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("online-state-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("update-completed", NULL));
}
DummyQNetworkConfigurationManager::~DummyQNetworkConfigurationManager()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQNetworkConfigurationManager::setSelf(knh_RawPtr_t *ptr)
{
	DummyQNetworkConfigurationManager::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQNetworkConfigurationManager::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQNetworkConfigurationManager::configurationAddedSlot(const QNetworkConfiguration config)
{
	if (configuration_added_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QNetworkConfiguration, config);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, configuration_added_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQNetworkConfigurationManager::configurationChangedSlot(const QNetworkConfiguration config)
{
	if (configuration_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QNetworkConfiguration, config);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, configuration_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQNetworkConfigurationManager::configurationRemovedSlot(const QNetworkConfiguration configuration)
{
	if (configuration_removed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QNetworkConfiguration, configuration);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, configuration_removed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQNetworkConfigurationManager::onlineStateChangedSlot(bool isOnline)
{
	if (online_state_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = isOnline;
		knh_Func_invoke(lctx, online_state_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQNetworkConfigurationManager::updateCompletedSlot()
{
	if (update_completed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, update_completed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQNetworkConfigurationManager::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkConfigurationManager::event_map->bigin();
	if ((itr = DummyQNetworkConfigurationManager::event_map->find(str)) == DummyQNetworkConfigurationManager::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQNetworkConfigurationManager::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkConfigurationManager::slot_map->bigin();
	if ((itr = DummyQNetworkConfigurationManager::slot_map->find(str)) == DummyQNetworkConfigurationManager::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		configuration_added_func = (*slot_map)["configuration-added"];
		configuration_changed_func = (*slot_map)["configuration-changed"];
		configuration_removed_func = (*slot_map)["configuration-removed"];
		online_state_changed_func = (*slot_map)["online-state-changed"];
		update_completed_func = (*slot_map)["update-completed"];
		return true;
	}
}

knh_Object_t** DummyQNetworkConfigurationManager::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQNetworkConfigurationManager::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 6;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, configuration_added_func);
	KNH_ADDNNREF(ctx, configuration_changed_func);
	KNH_ADDNNREF(ctx, configuration_removed_func);
	KNH_ADDNNREF(ctx, online_state_changed_func);
	KNH_ADDNNREF(ctx, update_completed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQNetworkConfigurationManager::connection(QObject *o)
{
	QNetworkConfigurationManager *p = dynamic_cast<QNetworkConfigurationManager*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(configurationAdded(const QNetworkConfiguration)), this, SLOT(configurationAddedSlot(const QNetworkConfiguration)));
		connect(p, SIGNAL(configurationChanged(const QNetworkConfiguration)), this, SLOT(configurationChangedSlot(const QNetworkConfiguration)));
		connect(p, SIGNAL(configurationRemoved(const QNetworkConfiguration)), this, SLOT(configurationRemovedSlot(const QNetworkConfiguration)));
		connect(p, SIGNAL(onlineStateChanged(bool)), this, SLOT(onlineStateChangedSlot(bool)));
		connect(p, SIGNAL(updateCompleted()), this, SLOT(updateCompletedSlot()));
	}
	DummyQObject::connection(o);
}

KQNetworkConfigurationManager::KQNetworkConfigurationManager(QObject* parent) : QNetworkConfigurationManager(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQNetworkConfigurationManager();
	dummy->connection((QObject*)this);
}

KQNetworkConfigurationManager::~KQNetworkConfigurationManager()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QNetworkConfigurationManager_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkConfigurationManager *qp = RawPtr_to(KQNetworkConfigurationManager *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkConfigurationManager]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkConfigurationManager]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QNetworkConfigurationManager_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkConfigurationManager *qp = RawPtr_to(KQNetworkConfigurationManager *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkConfigurationManager]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkConfigurationManager]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QNetworkConfigurationManager_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQNetworkConfigurationManager *qp = (KQNetworkConfigurationManager *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QNetworkConfigurationManager*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QNetworkConfigurationManager_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQNetworkConfigurationManager *qp = (KQNetworkConfigurationManager *)p->rawptr;
		KQNetworkConfigurationManager *qp = static_cast<KQNetworkConfigurationManager*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QNetworkConfigurationManager_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQNetworkConfigurationManager::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQNetworkConfigurationManager::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QNetworkConfigurationManager::event(event);
		return false;
	}
//	QNetworkConfigurationManager::event(event);
	return true;
}

static knh_IntData_t QNetworkConfigurationManagerConstInt[] = {
	{"CanStartAndStopInterfaces", QNetworkConfigurationManager::CanStartAndStopInterfaces},
	{"DirectConnectionRouting", QNetworkConfigurationManager::DirectConnectionRouting},
	{"SystemSessionSupport", QNetworkConfigurationManager::SystemSessionSupport},
	{"ApplicationLevelRoaming", QNetworkConfigurationManager::ApplicationLevelRoaming},
	{"ForcedRoaming", QNetworkConfigurationManager::ForcedRoaming},
	{"DataStatistics", QNetworkConfigurationManager::DataStatistics},
	{"NetworkSessionRequired", QNetworkConfigurationManager::NetworkSessionRequired},
	{NULL, 0}
};

DEFAPI(void) constQNetworkConfigurationManager(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QNetworkConfigurationManagerConstInt);
}


DEFAPI(void) defQNetworkConfigurationManager(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkConfigurationManager";
	cdef->free = QNetworkConfigurationManager_free;
	cdef->reftrace = QNetworkConfigurationManager_reftrace;
	cdef->compareTo = QNetworkConfigurationManager_compareTo;
}

//## QNetworkConfigurationManagerCapabilities QNetworkConfigurationManagerCapabilities.new(int value);
KMETHOD QNetworkConfigurationManagerCapabilities_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkConfigurationManager::Capability i = Int_to(QNetworkConfigurationManager::Capability, sfp[1]);
	QNetworkConfigurationManager::Capabilities *ret_v = new QNetworkConfigurationManager::Capabilities(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QNetworkConfigurationManagerCapabilities QNetworkConfigurationManagerCapabilities.and(int mask);
KMETHOD QNetworkConfigurationManagerCapabilities_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkConfigurationManager::Capabilities *qp = RawPtr_to(QNetworkConfigurationManager::Capabilities*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QNetworkConfigurationManager::Capabilities ret = ((*qp) & i);
		QNetworkConfigurationManager::Capabilities *ret_ = new QNetworkConfigurationManager::Capabilities(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkConfigurationManagerCapabilities QNetworkConfigurationManagerCapabilities.iand(QNetworkConfigurationManager::QNetworkConfigurationManagerCapabilities other);
KMETHOD QNetworkConfigurationManagerCapabilities_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkConfigurationManager::Capabilities *qp = RawPtr_to(QNetworkConfigurationManager::Capabilities*, sfp[0]);
	if (qp != NULL) {
		QNetworkConfigurationManager::Capabilities *other = RawPtr_to(QNetworkConfigurationManager::Capabilities *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkConfigurationManagerCapabilities QNetworkConfigurationManagerCapabilities.or(QNetworkConfigurationManagerCapabilities f);
KMETHOD QNetworkConfigurationManagerCapabilities_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfigurationManager::Capabilities *qp = RawPtr_to(QNetworkConfigurationManager::Capabilities*, sfp[0]);
	if (qp != NULL) {
		QNetworkConfigurationManager::Capabilities *f = RawPtr_to(QNetworkConfigurationManager::Capabilities*, sfp[1]);
		QNetworkConfigurationManager::Capabilities ret = ((*qp) | (*f));
		QNetworkConfigurationManager::Capabilities *ret_ = new QNetworkConfigurationManager::Capabilities(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkConfigurationManagerCapabilities QNetworkConfigurationManagerCapabilities.ior(QNetworkConfigurationManager::QNetworkConfigurationManagerCapabilities other);
KMETHOD QNetworkConfigurationManagerCapabilities_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkConfigurationManager::Capabilities *qp = RawPtr_to(QNetworkConfigurationManager::Capabilities*, sfp[0]);
	if (qp != NULL) {
		QNetworkConfigurationManager::Capabilities *other = RawPtr_to(QNetworkConfigurationManager::Capabilities *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkConfigurationManagerCapabilities QNetworkConfigurationManagerCapabilities.xor(QNetworkConfigurationManagerCapabilities f);
KMETHOD QNetworkConfigurationManagerCapabilities_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkConfigurationManager::Capabilities *qp = RawPtr_to(QNetworkConfigurationManager::Capabilities*, sfp[0]);
	if (qp != NULL) {
		QNetworkConfigurationManager::Capabilities *f = RawPtr_to(QNetworkConfigurationManager::Capabilities*, sfp[1]);
		QNetworkConfigurationManager::Capabilities ret = ((*qp) ^ (*f));
		QNetworkConfigurationManager::Capabilities *ret_ = new QNetworkConfigurationManager::Capabilities(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QNetworkConfigurationManagerCapabilities QNetworkConfigurationManagerCapabilities.ixor(QNetworkConfigurationManager::QNetworkConfigurationManagerCapabilities other);
KMETHOD QNetworkConfigurationManagerCapabilities_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkConfigurationManager::Capabilities *qp = RawPtr_to(QNetworkConfigurationManager::Capabilities*, sfp[0]);
	if (qp != NULL) {
		QNetworkConfigurationManager::Capabilities *other = RawPtr_to(QNetworkConfigurationManager::Capabilities *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QNetworkConfigurationManagerCapabilities.testFlag(int flag);
KMETHOD QNetworkConfigurationManagerCapabilities_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkConfigurationManager::Capabilities *qp = RawPtr_to(QNetworkConfigurationManager::Capabilities *, sfp[0]);
	if (qp != NULL) {
		QNetworkConfigurationManager::Capability flag = Int_to(QNetworkConfigurationManager::Capability, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QNetworkConfigurationManagerCapabilities.value();
KMETHOD QNetworkConfigurationManagerCapabilities_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QNetworkConfigurationManager::Capabilities *qp = RawPtr_to(QNetworkConfigurationManager::Capabilities *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QNetworkConfigurationManagerCapabilities_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QNetworkConfigurationManager::Capabilities *qp = (QNetworkConfigurationManager::Capabilities *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QNetworkConfigurationManagerCapabilities_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QNetworkConfigurationManager::Capabilities *qp = (QNetworkConfigurationManager::Capabilities *)p->rawptr;
		(void)qp;
	}
}

static int QNetworkConfigurationManagerCapabilities_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QNetworkConfigurationManager::Capabilities*)p1->rawptr);
//		int v2 = int(*(QNetworkConfigurationManager::Capabilities*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QNetworkConfigurationManager::Capabilities v1 = *(QNetworkConfigurationManager::Capabilities*)p1->rawptr;
		QNetworkConfigurationManager::Capabilities v2 = *(QNetworkConfigurationManager::Capabilities*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQNetworkConfigurationManagerCapabilities(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkConfigurationManagerCapabilities";
	cdef->free = QNetworkConfigurationManagerCapabilities_free;
	cdef->reftrace = QNetworkConfigurationManagerCapabilities_reftrace;
	cdef->compareTo = QNetworkConfigurationManagerCapabilities_compareTo;
}

