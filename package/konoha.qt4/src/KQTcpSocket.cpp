//QTcpSocket QTcpSocket.new(QObject parent);
KMETHOD QTcpSocket_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQTcpSocket *ret_v = new KQTcpSocket(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}


DummyQTcpSocket::DummyQTcpSocket()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTcpSocket::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTcpSocket::self = ptr;
	DummyQAbstractSocket::setSelf(ptr);
}

bool DummyQTcpSocket::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractSocket::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTcpSocket::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTcpSocket::event_map->bigin();
	if ((itr = DummyQTcpSocket::event_map->find(str)) == DummyQTcpSocket::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractSocket::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTcpSocket::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTcpSocket::slot_map->bigin();
	if ((itr = DummyQTcpSocket::slot_map->find(str)) == DummyQTcpSocket::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractSocket::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQTcpSocket::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQAbstractSocket::reftrace(ctx, p, tail_);
}

void DummyQTcpSocket::connection(QObject *o)
{
	QTcpSocket *p = dynamic_cast<QTcpSocket*>(o);
	if (p != NULL) {
	}
	DummyQAbstractSocket::connection(o);
}

KQTcpSocket::KQTcpSocket(QObject* parent) : QTcpSocket(parent)
{
	self = NULL;
	dummy = new DummyQTcpSocket();
	dummy->connection((QObject*)this);
}

KMETHOD QTcpSocket_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTcpSocket *qp = RawPtr_to(KQTcpSocket *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTcpSocket]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTcpSocket]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTcpSocket_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTcpSocket *qp = RawPtr_to(KQTcpSocket *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTcpSocket]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTcpSocket]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTcpSocket_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTcpSocket *qp = (KQTcpSocket *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTcpSocket_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQTcpSocket *qp = (KQTcpSocket *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTcpSocket_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTcpSocket::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQTcpSocket::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QTcpSocket::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQTcpSocket(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTcpSocket";
	cdef->free = QTcpSocket_free;
	cdef->reftrace = QTcpSocket_reftrace;
	cdef->compareTo = QTcpSocket_compareTo;
}


