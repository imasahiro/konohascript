//QNetworkSession QNetworkSession.new(QNetworkConfiguration connectionConfig, QObject parent);
KMETHOD QNetworkSession_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QNetworkConfiguration  connectionConfig = *RawPtr_to(const QNetworkConfiguration *, sfp[1]);
	QObject*  parent = RawPtr_to(QObject*, sfp[2]);
	KQNetworkSession *ret_v = new KQNetworkSession(connectionConfig, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QNetworkSession.activeTime();
KMETHOD QNetworkSession_activeTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkSession *  qp = RawPtr_to(QNetworkSession *, sfp[0]);
	if (qp) {
		quint64 ret_v = qp->activeTime();
		quint64 *ret_v_ = new quint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QNetworkSession.bytesReceived();
KMETHOD QNetworkSession_bytesReceived(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkSession *  qp = RawPtr_to(QNetworkSession *, sfp[0]);
	if (qp) {
		quint64 ret_v = qp->bytesReceived();
		quint64 *ret_v_ = new quint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QNetworkSession.bytesWritten();
KMETHOD QNetworkSession_bytesWritten(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkSession *  qp = RawPtr_to(QNetworkSession *, sfp[0]);
	if (qp) {
		quint64 ret_v = qp->bytesWritten();
		quint64 *ret_v_ = new quint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkConfiguration QNetworkSession.configuration();
KMETHOD QNetworkSession_configuration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkSession *  qp = RawPtr_to(QNetworkSession *, sfp[0]);
	if (qp) {
		QNetworkConfiguration ret_v = qp->configuration();
		QNetworkConfiguration *ret_v_ = new QNetworkConfiguration(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QNetworkSession.error();
KMETHOD QNetworkSession_error(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkSession *  qp = RawPtr_to(QNetworkSession *, sfp[0]);
	if (qp) {
		QNetworkSession::SessionError ret_v = qp->error();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QNetworkSession.errorString();
KMETHOD QNetworkSession_errorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkSession *  qp = RawPtr_to(QNetworkSession *, sfp[0]);
	if (qp) {
		QString ret_v = qp->errorString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkInterface QNetworkSession.interface();
KMETHOD QNetworkSession_interface(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkSession *  qp = RawPtr_to(QNetworkSession *, sfp[0]);
	if (qp) {
		QNetworkInterface ret_v = qp->interface();
		QNetworkInterface *ret_v_ = new QNetworkInterface(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QNetworkSession.isOpen();
KMETHOD QNetworkSession_isOpen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkSession *  qp = RawPtr_to(QNetworkSession *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isOpen();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QVariant QNetworkSession.getSessionProperty(String key);
KMETHOD QNetworkSession_getSessionProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkSession *  qp = RawPtr_to(QNetworkSession *, sfp[0]);
	if (qp) {
		const QString key = String_to(const QString, sfp[1]);
		QVariant ret_v = qp->sessionProperty(key);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QNetworkSession.setSessionProperty(String key, QVariant value);
KMETHOD QNetworkSession_setSessionProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkSession *  qp = RawPtr_to(QNetworkSession *, sfp[0]);
	if (qp) {
		const QString key = String_to(const QString, sfp[1]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[2]);
		qp->setSessionProperty(key, value);
	}
	RETURNvoid_();
}

//int QNetworkSession.state();
KMETHOD QNetworkSession_state(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkSession *  qp = RawPtr_to(QNetworkSession *, sfp[0]);
	if (qp) {
		QNetworkSession::State ret_v = qp->state();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QNetworkSession.waitForOpened(int msecs);
KMETHOD QNetworkSession_waitForOpened(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkSession *  qp = RawPtr_to(QNetworkSession *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForOpened(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QNetworkSession.close();
KMETHOD QNetworkSession_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkSession *  qp = RawPtr_to(QNetworkSession *, sfp[0]);
	if (qp) {
		qp->close();
	}
	RETURNvoid_();
}

//void QNetworkSession.migrate();
KMETHOD QNetworkSession_migrate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkSession *  qp = RawPtr_to(QNetworkSession *, sfp[0]);
	if (qp) {
		qp->migrate();
	}
	RETURNvoid_();
}

//void QNetworkSession.open();
KMETHOD QNetworkSession_open(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkSession *  qp = RawPtr_to(QNetworkSession *, sfp[0]);
	if (qp) {
		qp->open();
	}
	RETURNvoid_();
}

//void QNetworkSession.reject();
KMETHOD QNetworkSession_reject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkSession *  qp = RawPtr_to(QNetworkSession *, sfp[0]);
	if (qp) {
		qp->reject();
	}
	RETURNvoid_();
}

//void QNetworkSession.stop();
KMETHOD QNetworkSession_stop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkSession *  qp = RawPtr_to(QNetworkSession *, sfp[0]);
	if (qp) {
		qp->stop();
	}
	RETURNvoid_();
}


DummyQNetworkSession::DummyQNetworkSession()
{
	self = NULL;
	closed_func = NULL;
	error_func = NULL;
	new_configuration_activated_func = NULL;
	opened_func = NULL;
	preferred_configuration_changed_func = NULL;
	state_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("closed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("error", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("new-configuration-activated", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("opened", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("preferred-configuration-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("state-changed", NULL));
}

void DummyQNetworkSession::setSelf(knh_RawPtr_t *ptr)
{
	DummyQNetworkSession::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQNetworkSession::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQNetworkSession::closedSlot()
{
	if (closed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, closed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQNetworkSession::errorSlot(QNetworkSession::SessionError error)
{
	if (error_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = error;
		knh_Func_invoke(lctx, error_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQNetworkSession::newConfigurationActivatedSlot()
{
	if (new_configuration_activated_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, new_configuration_activated_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQNetworkSession::openedSlot()
{
	if (opened_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, opened_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQNetworkSession::preferredConfigurationChangedSlot(const QNetworkConfiguration config, bool isSeamless)
{
	if (preferred_configuration_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QNetworkConfiguration, config);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		lsfp[K_CALLDELTA+3].bvalue = isSeamless;
		knh_Func_invoke(lctx, preferred_configuration_changed_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQNetworkSession::stateChangedSlot(QNetworkSession::State state)
{
	if (state_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = state;
		knh_Func_invoke(lctx, state_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQNetworkSession::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkSession::event_map->bigin();
	if ((itr = DummyQNetworkSession::event_map->find(str)) == DummyQNetworkSession::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQNetworkSession::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkSession::slot_map->bigin();
	if ((itr = DummyQNetworkSession::slot_map->find(str)) == DummyQNetworkSession::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		closed_func = (*slot_map)["closed"];
		error_func = (*slot_map)["error"];
		new_configuration_activated_func = (*slot_map)["new-configuration-activated"];
		opened_func = (*slot_map)["opened"];
		preferred_configuration_changed_func = (*slot_map)["preferred-configuration-changed"];
		state_changed_func = (*slot_map)["state-changed"];
		return true;
	}
}

knh_Object_t** DummyQNetworkSession::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQNetworkSession::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 6;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, closed_func);
	KNH_ADDNNREF(ctx, error_func);
	KNH_ADDNNREF(ctx, new_configuration_activated_func);
	KNH_ADDNNREF(ctx, opened_func);
	KNH_ADDNNREF(ctx, preferred_configuration_changed_func);
	KNH_ADDNNREF(ctx, state_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQNetworkSession::connection(QObject *o)
{
	QNetworkSession *p = dynamic_cast<QNetworkSession*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(closed()), this, SLOT(closedSlot()));
		connect(p, SIGNAL(error(QNetworkSession::SessionError)), this, SLOT(errorSlot(QNetworkSession::SessionError)));
		connect(p, SIGNAL(newConfigurationActivated()), this, SLOT(newConfigurationActivatedSlot()));
		connect(p, SIGNAL(opened()), this, SLOT(openedSlot()));
		connect(p, SIGNAL(preferredConfigurationChanged(const QNetworkConfiguration, bool)), this, SLOT(preferredConfigurationChangedSlot(const QNetworkConfiguration, bool)));
		connect(p, SIGNAL(stateChanged(QNetworkSession::State)), this, SLOT(stateChangedSlot(QNetworkSession::State)));
	}
	DummyQObject::connection(o);
}

KQNetworkSession::KQNetworkSession(const QNetworkConfiguration connectionConfig, QObject* parent) : QNetworkSession(connectionConfig, parent)
{
	self = NULL;
	dummy = new DummyQNetworkSession();
	dummy->connection((QObject*)this);
}

KMETHOD QNetworkSession_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkSession *qp = RawPtr_to(KQNetworkSession *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkSession]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkSession]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QNetworkSession_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkSession *qp = RawPtr_to(KQNetworkSession *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkSession]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkSession]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QNetworkSession_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQNetworkSession *qp = (KQNetworkSession *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QNetworkSession_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQNetworkSession *qp = (KQNetworkSession *)p->rawptr;
//		KQNetworkSession *qp = static_cast<KQNetworkSession*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QNetworkSession_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQNetworkSession::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQNetworkSession::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QNetworkSession::event(event);
		return false;
	}
//	QNetworkSession::event(event);
	return true;
}

static knh_IntData_t QNetworkSessionConstInt[] = {
	{"UnknownSessionError", QNetworkSession::UnknownSessionError},
	{"SessionAbortedError", QNetworkSession::SessionAbortedError},
	{"RoamingError", QNetworkSession::RoamingError},
	{"OperationNotSupportedError", QNetworkSession::OperationNotSupportedError},
	{"InvalidConfigurationError", QNetworkSession::InvalidConfigurationError},
	{"Invalid", QNetworkSession::Invalid},
	{"NotAvailable", QNetworkSession::NotAvailable},
	{"Connecting", QNetworkSession::Connecting},
	{"Connected", QNetworkSession::Connected},
	{"Closing", QNetworkSession::Closing},
	{"Disconnected", QNetworkSession::Disconnected},
	{"Roaming", QNetworkSession::Roaming},
	{NULL, 0}
};

DEFAPI(void) constQNetworkSession(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QNetworkSessionConstInt);
}


DEFAPI(void) defQNetworkSession(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkSession";
	cdef->free = QNetworkSession_free;
	cdef->reftrace = QNetworkSession_reftrace;
	cdef->compareTo = QNetworkSession_compareTo;
}


