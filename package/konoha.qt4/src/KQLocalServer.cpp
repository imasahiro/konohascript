//QLocalServer QLocalServer.new(QObject parent);
KMETHOD QLocalServer_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQLocalServer *ret_v = new KQLocalServer(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QLocalServer.close();
KMETHOD QLocalServer_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalServer *  qp = RawPtr_to(QLocalServer *, sfp[0]);
	if (qp) {
		qp->close();
	}
	RETURNvoid_();
}

//String QLocalServer.errorString();
KMETHOD QLocalServer_errorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalServer *  qp = RawPtr_to(QLocalServer *, sfp[0]);
	if (qp) {
		QString ret_v = qp->errorString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QLocalServer.fullServerName();
KMETHOD QLocalServer_fullServerName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalServer *  qp = RawPtr_to(QLocalServer *, sfp[0]);
	if (qp) {
		QString ret_v = qp->fullServerName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual boolean QLocalServer.hasPendingConnections();
KMETHOD QLocalServer_hasPendingConnections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalServer *  qp = RawPtr_to(QLocalServer *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasPendingConnections();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QLocalServer.isListening();
KMETHOD QLocalServer_isListening(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalServer *  qp = RawPtr_to(QLocalServer *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isListening();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QLocalServer.listen(String name);
KMETHOD QLocalServer_listen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalServer *  qp = RawPtr_to(QLocalServer *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		bool ret_v = qp->listen(name);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QLocalServer.getMaxPendingConnections();
KMETHOD QLocalServer_getMaxPendingConnections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalServer *  qp = RawPtr_to(QLocalServer *, sfp[0]);
	if (qp) {
		int ret_v = qp->maxPendingConnections();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QLocalSocket QLocalServer.nextPendingConnection();
KMETHOD QLocalServer_nextPendingConnection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalServer *  qp = RawPtr_to(QLocalServer *, sfp[0]);
	if (qp) {
		QLocalSocket* ret_v = qp->nextPendingConnection();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QLocalSocket*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QLocalServer.serverError();
KMETHOD QLocalServer_serverError(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalServer *  qp = RawPtr_to(QLocalServer *, sfp[0]);
	if (qp) {
		QAbstractSocket::SocketError ret_v = qp->serverError();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QLocalServer.serverName();
KMETHOD QLocalServer_serverName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalServer *  qp = RawPtr_to(QLocalServer *, sfp[0]);
	if (qp) {
		QString ret_v = qp->serverName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QLocalServer.setMaxPendingConnections(int numConnections);
KMETHOD QLocalServer_setMaxPendingConnections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalServer *  qp = RawPtr_to(QLocalServer *, sfp[0]);
	if (qp) {
		int numConnections = Int_to(int, sfp[1]);
		qp->setMaxPendingConnections(numConnections);
	}
	RETURNvoid_();
}

//boolean QLocalServer.waitForNewConnection(int msec, boolean timedOut);
KMETHOD QLocalServer_waitForNewConnection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalServer *  qp = RawPtr_to(QLocalServer *, sfp[0]);
	if (qp) {
		int msec = Int_to(int, sfp[1]);
		bool* timedOut = Boolean_to(bool*, sfp[2]);
		bool ret_v = qp->waitForNewConnection(msec, timedOut);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QLocalServer.removeServer(String name);
KMETHOD QLocalServer_removeServer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString name = String_to(const QString, sfp[1]);
		bool ret_v = QLocalServer::removeServer(name);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQLocalServer::DummyQLocalServer()
{
	self = NULL;
	new_connection_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("new-connection", NULL));
}

void DummyQLocalServer::setSelf(knh_RawPtr_t *ptr)
{
	DummyQLocalServer::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQLocalServer::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQLocalServer::newConnectionSlot()
{
	if (new_connection_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, new_connection_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQLocalServer::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLocalServer::event_map->bigin();
	if ((itr = DummyQLocalServer::event_map->find(str)) == DummyQLocalServer::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQLocalServer::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLocalServer::slot_map->bigin();
	if ((itr = DummyQLocalServer::slot_map->find(str)) == DummyQLocalServer::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		new_connection_func = (*slot_map)["new-connection"];
		return true;
	}
}

void DummyQLocalServer::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 1;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, new_connection_func);

	KNH_SIZEREF(ctx);

	DummyQObject::reftrace(ctx, p, tail_);
}

void DummyQLocalServer::connection(QObject *o)
{
	QLocalServer *p = dynamic_cast<QLocalServer*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(newConnection()), this, SLOT(newConnectionSlot()));
	}
	DummyQObject::connection(o);
}

KQLocalServer::KQLocalServer(QObject* parent) : QLocalServer(parent)
{
	self = NULL;
	dummy = new DummyQLocalServer();
	dummy->connection((QObject*)this);
}

KMETHOD QLocalServer_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLocalServer *qp = RawPtr_to(KQLocalServer *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QLocalServer]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLocalServer]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QLocalServer_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLocalServer *qp = RawPtr_to(KQLocalServer *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QLocalServer]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLocalServer]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QLocalServer_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQLocalServer *qp = (KQLocalServer *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QLocalServer_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQLocalServer *qp = (KQLocalServer *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QLocalServer_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQLocalServer::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQLocalServer::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QLocalServer::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQLocalServer(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QLocalServer";
	cdef->free = QLocalServer_free;
	cdef->reftrace = QLocalServer_reftrace;
	cdef->compareTo = QLocalServer_compareTo;
}


