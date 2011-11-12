//QTcpServer QTcpServer.new(QObject parent);
KMETHOD QTcpServer_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQTcpServer *ret_v = new KQTcpServer(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QTcpServer.close();
KMETHOD QTcpServer_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTcpServer *  qp = RawPtr_to(QTcpServer *, sfp[0]);
	if (qp) {
		qp->close();
	}
	RETURNvoid_();
}

//String QTcpServer.errorString();
KMETHOD QTcpServer_errorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTcpServer *  qp = RawPtr_to(QTcpServer *, sfp[0]);
	if (qp) {
		QString ret_v = qp->errorString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual boolean QTcpServer.hasPendingConnections();
KMETHOD QTcpServer_hasPendingConnections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTcpServer *  qp = RawPtr_to(QTcpServer *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasPendingConnections();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTcpServer.isListening();
KMETHOD QTcpServer_isListening(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTcpServer *  qp = RawPtr_to(QTcpServer *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isListening();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTcpServer.listen(QHostAddress address, int port);
KMETHOD QTcpServer_listen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTcpServer *  qp = RawPtr_to(QTcpServer *, sfp[0]);
	if (qp) {
		const QHostAddress  address = *RawPtr_to(const QHostAddress *, sfp[1]);
		quint16 port = Int_to(quint16, sfp[2]);
		bool ret_v = qp->listen(address, port);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTcpServer.getMaxPendingConnections();
KMETHOD QTcpServer_getMaxPendingConnections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTcpServer *  qp = RawPtr_to(QTcpServer *, sfp[0]);
	if (qp) {
		int ret_v = qp->maxPendingConnections();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QTcpSocket QTcpServer.nextPendingConnection();
KMETHOD QTcpServer_nextPendingConnection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTcpServer *  qp = RawPtr_to(QTcpServer *, sfp[0]);
	if (qp) {
		QTcpSocket* ret_v = qp->nextPendingConnection();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTcpSocket*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QNetworkProxy QTcpServer.getProxy();
KMETHOD QTcpServer_getProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTcpServer *  qp = RawPtr_to(QTcpServer *, sfp[0]);
	if (qp) {
		QNetworkProxy ret_v = qp->proxy();
		QNetworkProxy *ret_v_ = new QNetworkProxy(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QHostAddress QTcpServer.serverAddress();
KMETHOD QTcpServer_serverAddress(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTcpServer *  qp = RawPtr_to(QTcpServer *, sfp[0]);
	if (qp) {
		QHostAddress ret_v = qp->serverAddress();
		QHostAddress *ret_v_ = new QHostAddress(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTcpServer.serverError();
KMETHOD QTcpServer_serverError(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTcpServer *  qp = RawPtr_to(QTcpServer *, sfp[0]);
	if (qp) {
		QAbstractSocket::SocketError ret_v = qp->serverError();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTcpServer.serverPort();
KMETHOD QTcpServer_serverPort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTcpServer *  qp = RawPtr_to(QTcpServer *, sfp[0]);
	if (qp) {
		quint16 ret_v = qp->serverPort();
		quint16 *ret_v_ = new quint16(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTcpServer.setMaxPendingConnections(int numConnections);
KMETHOD QTcpServer_setMaxPendingConnections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTcpServer *  qp = RawPtr_to(QTcpServer *, sfp[0]);
	if (qp) {
		int numConnections = Int_to(int, sfp[1]);
		qp->setMaxPendingConnections(numConnections);
	}
	RETURNvoid_();
}

//void QTcpServer.setProxy(QNetworkProxy networkProxy);
KMETHOD QTcpServer_setProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTcpServer *  qp = RawPtr_to(QTcpServer *, sfp[0]);
	if (qp) {
		const QNetworkProxy  networkProxy = *RawPtr_to(const QNetworkProxy *, sfp[1]);
		qp->setProxy(networkProxy);
	}
	RETURNvoid_();
}

//boolean QTcpServer.setSocketDescriptor(int socketDescriptor);
KMETHOD QTcpServer_setSocketDescriptor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTcpServer *  qp = RawPtr_to(QTcpServer *, sfp[0]);
	if (qp) {
		int socketDescriptor = Int_to(int, sfp[1]);
		bool ret_v = qp->setSocketDescriptor(socketDescriptor);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTcpServer.getSocketDescriptor();
KMETHOD QTcpServer_getSocketDescriptor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTcpServer *  qp = RawPtr_to(QTcpServer *, sfp[0]);
	if (qp) {
		int ret_v = qp->socketDescriptor();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QTcpServer.waitForNewConnection(int msec, boolean timedOut);
KMETHOD QTcpServer_waitForNewConnection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTcpServer *  qp = RawPtr_to(QTcpServer *, sfp[0]);
	if (qp) {
		int msec = Int_to(int, sfp[1]);
		bool* timedOut = Boolean_to(bool*, sfp[2]);
		bool ret_v = qp->waitForNewConnection(msec, timedOut);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQTcpServer::DummyQTcpServer()
{
	self = NULL;
	new_connection_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("new-connection", NULL));
}

void DummyQTcpServer::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTcpServer::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQTcpServer::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTcpServer::newConnectionSlot()
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

bool DummyQTcpServer::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTcpServer::event_map->bigin();
	if ((itr = DummyQTcpServer::event_map->find(str)) == DummyQTcpServer::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTcpServer::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTcpServer::slot_map->bigin();
	if ((itr = DummyQTcpServer::slot_map->find(str)) == DummyQTcpServer::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		new_connection_func = (*slot_map)["new-connection"];
		return true;
	}
}

knh_Object_t** DummyQTcpServer::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTcpServer::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 1;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, new_connection_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQTcpServer::connection(QObject *o)
{
	QTcpServer *p = dynamic_cast<QTcpServer*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(newConnection()), this, SLOT(newConnectionSlot()));
	}
	DummyQObject::connection(o);
}

KQTcpServer::KQTcpServer(QObject* parent) : QTcpServer(parent)
{
	self = NULL;
	dummy = new DummyQTcpServer();
	dummy->connection((QObject*)this);
}

KMETHOD QTcpServer_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTcpServer *qp = RawPtr_to(KQTcpServer *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTcpServer]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTcpServer]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTcpServer_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTcpServer *qp = RawPtr_to(KQTcpServer *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTcpServer]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTcpServer]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTcpServer_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTcpServer *qp = (KQTcpServer *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTcpServer_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQTcpServer *qp = (KQTcpServer *)p->rawptr;
//		KQTcpServer *qp = static_cast<KQTcpServer*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTcpServer_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTcpServer::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQTcpServer::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QTcpServer::event(event);
		return false;
	}
//	QTcpServer::event(event);
	return true;
}



DEFAPI(void) defQTcpServer(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTcpServer";
	cdef->free = QTcpServer_free;
	cdef->reftrace = QTcpServer_reftrace;
	cdef->compareTo = QTcpServer_compareTo;
}


