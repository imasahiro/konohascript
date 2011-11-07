//QUdpSocket QUdpSocket.new(QObject parent);
KMETHOD QUdpSocket_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQUdpSocket *ret_v = new KQUdpSocket(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QUdpSocket.bind(QHostAddress address, int port);
KMETHOD QUdpSocket_bind(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUdpSocket *  qp = RawPtr_to(QUdpSocket *, sfp[0]);
	if (qp) {
		const QHostAddress  address = *RawPtr_to(const QHostAddress *, sfp[1]);
		quint16 port = Int_to(quint16, sfp[2]);
		bool ret_v = qp->bind(address, port);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QUdpSocket.bind(QHostAddress address, int port, QUdpSocketBindMode mode);
KMETHOD QUdpSocket_bind(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUdpSocket *  qp = RawPtr_to(QUdpSocket *, sfp[0]);
	if (qp) {
		const QHostAddress  address = *RawPtr_to(const QHostAddress *, sfp[1]);
		quint16 port = Int_to(quint16, sfp[2]);
		initFlag(mode, QUdpSocket::BindMode, sfp[3]);
		bool ret_v = qp->bind(address, port, mode);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//boolean QUdpSocket.bind(int port);
KMETHOD QUdpSocket_bind(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUdpSocket *  qp = RawPtr_to(QUdpSocket *, sfp[0]);
	if (qp) {
		quint16 port = Int_to(quint16, sfp[1]);
		bool ret_v = qp->bind(port);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
/*
//boolean QUdpSocket.bind(int port, QUdpSocketBindMode mode);
KMETHOD QUdpSocket_bind(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUdpSocket *  qp = RawPtr_to(QUdpSocket *, sfp[0]);
	if (qp) {
		quint16 port = Int_to(quint16, sfp[1]);
		initFlag(mode, QUdpSocket::BindMode, sfp[2]);
		bool ret_v = qp->bind(port, mode);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//boolean QUdpSocket.hasPendingDatagrams();
KMETHOD QUdpSocket_hasPendingDatagrams(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUdpSocket *  qp = RawPtr_to(QUdpSocket *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasPendingDatagrams();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QUdpSocket.pendingDatagramSize();
KMETHOD QUdpSocket_pendingDatagramSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUdpSocket *  qp = RawPtr_to(QUdpSocket *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->pendingDatagramSize();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QUdpSocket.readDatagram(String data, int maxSize, QHostAddress address, int port);
KMETHOD QUdpSocket_readDatagram(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUdpSocket *  qp = RawPtr_to(QUdpSocket *, sfp[0]);
	if (qp) {
		char*  data = RawPtr_to(char*, sfp[1]);
		qint64 maxSize = Int_to(qint64, sfp[2]);
		QHostAddress*  address = RawPtr_to(QHostAddress*, sfp[3]);
		quint16* port = Int_to(quint16*, sfp[4]);
		qint64 ret_v = qp->readDatagram(data, maxSize, address, port);
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QUdpSocket.writeDatagram(String data, int size, QHostAddress address, int port);
KMETHOD QUdpSocket_writeDatagram(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUdpSocket *  qp = RawPtr_to(QUdpSocket *, sfp[0]);
	if (qp) {
		const char*  data = RawPtr_to(const char*, sfp[1]);
		qint64 size = Int_to(qint64, sfp[2]);
		const QHostAddress  address = *RawPtr_to(const QHostAddress *, sfp[3]);
		quint16 port = Int_to(quint16, sfp[4]);
		qint64 ret_v = qp->writeDatagram(data, size, address, port);
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//int QUdpSocket.writeDatagram(QByteArray datagram, QHostAddress host, int port);
KMETHOD QUdpSocket_writeDatagram(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUdpSocket *  qp = RawPtr_to(QUdpSocket *, sfp[0]);
	if (qp) {
		const QByteArray  datagram = *RawPtr_to(const QByteArray *, sfp[1]);
		const QHostAddress  host = *RawPtr_to(const QHostAddress *, sfp[2]);
		quint16 port = Int_to(quint16, sfp[3]);
		qint64 ret_v = qp->writeDatagram(datagram, host, port);
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/

DummyQUdpSocket::DummyQUdpSocket()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQUdpSocket::setSelf(knh_RawPtr_t *ptr)
{
	DummyQUdpSocket::self = ptr;
	DummyQAbstractSocket::setSelf(ptr);
}

bool DummyQUdpSocket::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractSocket::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQUdpSocket::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQUdpSocket::event_map->bigin();
	if ((itr = DummyQUdpSocket::event_map->find(str)) == DummyQUdpSocket::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractSocket::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQUdpSocket::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQUdpSocket::slot_map->bigin();
	if ((itr = DummyQUdpSocket::slot_map->find(str)) == DummyQUdpSocket::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractSocket::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQUdpSocket::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQAbstractSocket::reftrace(ctx, p, tail_);
}

void DummyQUdpSocket::connection(QObject *o)
{
	QUdpSocket *p = dynamic_cast<QUdpSocket*>(o);
	if (p != NULL) {
	}
	DummyQAbstractSocket::connection(o);
}

KQUdpSocket::KQUdpSocket(QObject* parent) : QUdpSocket(parent)
{
	self = NULL;
	dummy = new DummyQUdpSocket();
	dummy->connection((QObject*)this);
}

KMETHOD QUdpSocket_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQUdpSocket *qp = RawPtr_to(KQUdpSocket *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QUdpSocket]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QUdpSocket]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QUdpSocket_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQUdpSocket *qp = RawPtr_to(KQUdpSocket *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QUdpSocket]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QUdpSocket]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QUdpSocket_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQUdpSocket *qp = (KQUdpSocket *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QUdpSocket_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQUdpSocket *qp = (KQUdpSocket *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QUdpSocket_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQUdpSocket::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQUdpSocket::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QUdpSocket::event(event);
		return false;
	}
	return true;
}

static knh_IntData_t QUdpSocketConstInt[] = {
	{"ShareAddress", QUdpSocket::ShareAddress},
	{"DontShareAddress", QUdpSocket::DontShareAddress},
	{"ReuseAddressHint", QUdpSocket::ReuseAddressHint},
	{"DefaultForPlatform", QUdpSocket::DefaultForPlatform},
	{NULL, 0}
};

DEFAPI(void) constQUdpSocket(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QUdpSocketConstInt);
}


DEFAPI(void) defQUdpSocket(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QUdpSocket";
	cdef->free = QUdpSocket_free;
	cdef->reftrace = QUdpSocket_reftrace;
	cdef->compareTo = QUdpSocket_compareTo;
}

//## QUdpSocketBindMode QUdpSocketBindMode.new(int value);
KMETHOD QUdpSocketBindMode_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QUdpSocket::BindFlag i = Int_to(QUdpSocket::BindFlag, sfp[1]);
	QUdpSocket::BindMode *ret_v = new QUdpSocket::BindMode(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QUdpSocketBindMode QUdpSocketBindMode.and(int mask);
KMETHOD QUdpSocketBindMode_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QUdpSocket::BindMode *qp = RawPtr_to(QUdpSocket::BindMode*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QUdpSocket::BindMode ret = ((*qp) & i);
		QUdpSocket::BindMode *ret_ = new QUdpSocket::BindMode(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QUdpSocketBindMode QUdpSocketBindMode.iand(QUdpSocket::QUdpSocketBindMode other);
KMETHOD QUdpSocketBindMode_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QUdpSocket::BindMode *qp = RawPtr_to(QUdpSocket::BindMode*, sfp[0]);
	if (qp != NULL) {
		QUdpSocket::BindMode *other = RawPtr_to(QUdpSocket::BindMode *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QUdpSocketBindMode QUdpSocketBindMode.or(QUdpSocketBindMode f);
KMETHOD QUdpSocketBindMode_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUdpSocket::BindMode *qp = RawPtr_to(QUdpSocket::BindMode*, sfp[0]);
	if (qp != NULL) {
		QUdpSocket::BindMode *f = RawPtr_to(QUdpSocket::BindMode*, sfp[1]);
		QUdpSocket::BindMode ret = ((*qp) | (*f));
		QUdpSocket::BindMode *ret_ = new QUdpSocket::BindMode(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QUdpSocketBindMode QUdpSocketBindMode.ior(QUdpSocket::QUdpSocketBindMode other);
KMETHOD QUdpSocketBindMode_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QUdpSocket::BindMode *qp = RawPtr_to(QUdpSocket::BindMode*, sfp[0]);
	if (qp != NULL) {
		QUdpSocket::BindMode *other = RawPtr_to(QUdpSocket::BindMode *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QUdpSocketBindMode QUdpSocketBindMode.xor(QUdpSocketBindMode f);
KMETHOD QUdpSocketBindMode_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUdpSocket::BindMode *qp = RawPtr_to(QUdpSocket::BindMode*, sfp[0]);
	if (qp != NULL) {
		QUdpSocket::BindMode *f = RawPtr_to(QUdpSocket::BindMode*, sfp[1]);
		QUdpSocket::BindMode ret = ((*qp) ^ (*f));
		QUdpSocket::BindMode *ret_ = new QUdpSocket::BindMode(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QUdpSocketBindMode QUdpSocketBindMode.ixor(QUdpSocket::QUdpSocketBindMode other);
KMETHOD QUdpSocketBindMode_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QUdpSocket::BindMode *qp = RawPtr_to(QUdpSocket::BindMode*, sfp[0]);
	if (qp != NULL) {
		QUdpSocket::BindMode *other = RawPtr_to(QUdpSocket::BindMode *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QUdpSocketBindMode.testFlag(int flag);
KMETHOD QUdpSocketBindMode_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QUdpSocket::BindMode *qp = RawPtr_to(QUdpSocket::BindMode *, sfp[0]);
	if (qp != NULL) {
		QUdpSocket::BindFlag flag = Int_to(QUdpSocket::BindFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QUdpSocketBindMode.value();
KMETHOD QUdpSocketBindMode_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QUdpSocket::BindMode *qp = RawPtr_to(QUdpSocket::BindMode *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QUdpSocketBindMode_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QUdpSocket::BindMode *qp = (QUdpSocket::BindMode *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QUdpSocketBindMode_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QUdpSocket::BindMode *qp = (QUdpSocket::BindMode *)p->rawptr;
		(void)qp;
	}
}

static int QUdpSocketBindMode_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QUdpSocket::BindMode*)p1->rawptr);
//		int v2 = int(*(QUdpSocket::BindMode*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QUdpSocket::BindMode v1 = *(QUdpSocket::BindMode*)p1->rawptr;
		QUdpSocket::BindMode v2 = *(QUdpSocket::BindMode*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQUdpSocketBindMode(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QUdpSocketBindMode";
	cdef->free = QUdpSocketBindMode_free;
	cdef->reftrace = QUdpSocketBindMode_reftrace;
	cdef->compareTo = QUdpSocketBindMode_compareTo;
}

