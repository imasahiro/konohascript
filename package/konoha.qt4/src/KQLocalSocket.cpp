//@Virtual @Override int QLocalSocket.bytesAvailable();
KMETHOD QLocalSocket_bytesAvailable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->bytesAvailable();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QLocalSocket.bytesToWrite();
KMETHOD QLocalSocket_bytesToWrite(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->bytesToWrite();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QLocalSocket.canReadLine();
KMETHOD QLocalSocket_canReadLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		bool ret_v = qp->canReadLine();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override void QLocalSocket.close();
KMETHOD QLocalSocket_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		qp->close();
	}
	RETURNvoid_();
}

//@Virtual @Override boolean QLocalSocket.isSequential();
KMETHOD QLocalSocket_isSequential(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSequential();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override boolean QLocalSocket.waitForBytesWritten(int msecs);
KMETHOD QLocalSocket_waitForBytesWritten(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForBytesWritten(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override boolean QLocalSocket.waitForReadyRead(int msecs);
KMETHOD QLocalSocket_waitForReadyRead(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForReadyRead(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QLocalSocket QLocalSocket.new(QObject parent);
KMETHOD QLocalSocket_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQLocalSocket *ret_v = new KQLocalSocket(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QLocalSocket.abort();
KMETHOD QLocalSocket_abort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		qp->abort();
	}
	RETURNvoid_();
}

//void QLocalSocket.connectToServer(String name, QIODeviceOpenMode openMode);
KMETHOD QLocalSocket_connectToServer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		initFlag(openMode, QIODevice::OpenMode, sfp[2]);
		qp->connectToServer(name, openMode);
	}
	RETURNvoid_();
}

//void QLocalSocket.disconnectFromServer();
KMETHOD QLocalSocket_disconnectFromServer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		qp->disconnectFromServer();
	}
	RETURNvoid_();
}

//int QLocalSocket.error();
KMETHOD QLocalSocket_error(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		QLocalSocket::LocalSocketError ret_v = qp->error();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QLocalSocket.flush();
KMETHOD QLocalSocket_flush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		bool ret_v = qp->flush();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QLocalSocket.fullServerName();
KMETHOD QLocalSocket_fullServerName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		QString ret_v = qp->fullServerName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QLocalSocket.getReadBufferSize();
KMETHOD QLocalSocket_getReadBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->readBufferSize();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QLocalSocket.serverName();
KMETHOD QLocalSocket_serverName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		QString ret_v = qp->serverName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QLocalSocket.setReadBufferSize(int size);
KMETHOD QLocalSocket_setReadBufferSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		qint64 size = Int_to(qint64, sfp[1]);
		qp->setReadBufferSize(size);
	}
	RETURNvoid_();
}

//boolean QLocalSocket.setSocketDescriptor(int socketDescriptor, int socketState, QIODeviceOpenMode openMode);
KMETHOD QLocalSocket_setSocketDescriptor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		quintptr socketDescriptor = Int_to(quintptr, sfp[1]);
		QLocalSocket::LocalSocketState socketState = Int_to(QLocalSocket::LocalSocketState, sfp[2]);
		initFlag(openMode, QIODevice::OpenMode, sfp[3]);
		bool ret_v = qp->setSocketDescriptor(socketDescriptor, socketState, openMode);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QLocalSocket.getSocketDescriptor();
KMETHOD QLocalSocket_getSocketDescriptor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		quintptr ret_v = qp->socketDescriptor();
		quintptr *ret_v_ = new quintptr(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QLocalSocket.state();
KMETHOD QLocalSocket_state(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		QLocalSocket::LocalSocketState ret_v = qp->state();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QLocalSocket.waitForConnected(int msecs);
KMETHOD QLocalSocket_waitForConnected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForConnected(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QLocalSocket.waitForDisconnected(int msecs);
KMETHOD QLocalSocket_waitForDisconnected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocalSocket *  qp = RawPtr_to(QLocalSocket *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForDisconnected(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQLocalSocket::DummyQLocalSocket()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	connected_func = NULL;
	disconnected_func = NULL;
	error_func = NULL;
	state_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("connected", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("disconnected", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("error", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("state-changed", NULL));
}
DummyQLocalSocket::~DummyQLocalSocket()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQLocalSocket::setSelf(knh_RawPtr_t *ptr)
{
	DummyQLocalSocket::self = ptr;
	DummyQIODevice::setSelf(ptr);
}

bool DummyQLocalSocket::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQIODevice::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQLocalSocket::connectedSlot()
{
	if (connected_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, connected_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQLocalSocket::disconnectedSlot()
{
	if (disconnected_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, disconnected_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQLocalSocket::errorSlot(QLocalSocket::LocalSocketError socketError)
{
	if (error_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = socketError;
		knh_Func_invoke(lctx, error_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQLocalSocket::stateChangedSlot(QLocalSocket::LocalSocketState socketState)
{
	if (state_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = socketState;
		knh_Func_invoke(lctx, state_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQLocalSocket::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLocalSocket::event_map->bigin();
	if ((itr = DummyQLocalSocket::event_map->find(str)) == DummyQLocalSocket::event_map->end()) {
		bool ret = false;
		ret = DummyQIODevice::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQLocalSocket::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLocalSocket::slot_map->bigin();
	if ((itr = DummyQLocalSocket::slot_map->find(str)) == DummyQLocalSocket::slot_map->end()) {
		bool ret = false;
		ret = DummyQIODevice::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		connected_func = (*slot_map)["connected"];
		disconnected_func = (*slot_map)["disconnected"];
		error_func = (*slot_map)["error"];
		state_changed_func = (*slot_map)["state-changed"];
		return true;
	}
}

knh_Object_t** DummyQLocalSocket::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQLocalSocket::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 5;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, connected_func);
	KNH_ADDNNREF(ctx, disconnected_func);
	KNH_ADDNNREF(ctx, error_func);
	KNH_ADDNNREF(ctx, state_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQIODevice::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQLocalSocket::connection(QObject *o)
{
	QLocalSocket *p = dynamic_cast<QLocalSocket*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(connected()), this, SLOT(connectedSlot()));
		connect(p, SIGNAL(disconnected()), this, SLOT(disconnectedSlot()));
		connect(p, SIGNAL(error(QLocalSocket::LocalSocketError)), this, SLOT(errorSlot(QLocalSocket::LocalSocketError)));
		connect(p, SIGNAL(stateChanged(QLocalSocket::LocalSocketState)), this, SLOT(stateChangedSlot(QLocalSocket::LocalSocketState)));
	}
	DummyQIODevice::connection(o);
}

KQLocalSocket::KQLocalSocket(QObject* parent) : QLocalSocket(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQLocalSocket();
	dummy->connection((QObject*)this);
}

KQLocalSocket::~KQLocalSocket()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QLocalSocket_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLocalSocket *qp = RawPtr_to(KQLocalSocket *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QLocalSocket]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLocalSocket]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QLocalSocket_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLocalSocket *qp = RawPtr_to(KQLocalSocket *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QLocalSocket]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLocalSocket]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QLocalSocket_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQLocalSocket *qp = (KQLocalSocket *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QLocalSocket*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QLocalSocket_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQLocalSocket *qp = (KQLocalSocket *)p->rawptr;
		KQLocalSocket *qp = static_cast<KQLocalSocket*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QLocalSocket_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQLocalSocket::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQLocalSocket::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QLocalSocket::event(event);
		return false;
	}
//	QLocalSocket::event(event);
	return true;
}

static knh_IntData_t QLocalSocketConstInt[] = {
	{"ConnectionRefusedError", QLocalSocket::ConnectionRefusedError},
	{"PeerClosedError", QLocalSocket::PeerClosedError},
	{"ServerNotFoundError", QLocalSocket::ServerNotFoundError},
	{"SocketAccessError", QLocalSocket::SocketAccessError},
	{"SocketResourceError", QLocalSocket::SocketResourceError},
	{"SocketTimeoutError", QLocalSocket::SocketTimeoutError},
	{"DatagramTooLargeError", QLocalSocket::DatagramTooLargeError},
	{"ConnectionError", QLocalSocket::ConnectionError},
	{"UnsupportedSocketOperationError", QLocalSocket::UnsupportedSocketOperationError},
	{"UnknownSocketError", QLocalSocket::UnknownSocketError},
	{"UnconnectedState", QLocalSocket::UnconnectedState},
	{"ConnectingState", QLocalSocket::ConnectingState},
	{"ConnectedState", QLocalSocket::ConnectedState},
	{"ClosingState", QLocalSocket::ClosingState},
	{NULL, 0}
};

DEFAPI(void) constQLocalSocket(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QLocalSocketConstInt);
}


DEFAPI(void) defQLocalSocket(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QLocalSocket";
	cdef->free = QLocalSocket_free;
	cdef->reftrace = QLocalSocket_reftrace;
	cdef->compareTo = QLocalSocket_compareTo;
}


