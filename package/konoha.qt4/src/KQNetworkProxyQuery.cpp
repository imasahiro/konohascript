//QNetworkProxyQuery QNetworkProxyQuery.new();
KMETHOD QNetworkProxyQuery_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkProxyQuery *ret_v = new KQNetworkProxyQuery();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QNetworkProxyQuery QNetworkProxyQuery.new(QUrl requestUrl, int queryType);
KMETHOD QNetworkProxyQuery_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QUrl  requestUrl = *RawPtr_to(const QUrl *, sfp[1]);
	QNetworkProxyQuery::QueryType queryType = Int_to(QNetworkProxyQuery::QueryType, sfp[2]);
	KQNetworkProxyQuery *ret_v = new KQNetworkProxyQuery(requestUrl, queryType);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QNetworkProxyQuery QNetworkProxyQuery.new(String hostname, int port, String protocolTag, int queryType);
KMETHOD QNetworkProxyQuery_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString hostname = String_to(const QString, sfp[1]);
	int port = Int_to(int, sfp[2]);
	const QString protocolTag = String_to(const QString, sfp[3]);
	QNetworkProxyQuery::QueryType queryType = Int_to(QNetworkProxyQuery::QueryType, sfp[4]);
	KQNetworkProxyQuery *ret_v = new KQNetworkProxyQuery(hostname, port, protocolTag, queryType);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QNetworkProxyQuery QNetworkProxyQuery.new(int bindPort, String protocolTag, int queryType);
KMETHOD QNetworkProxyQuery_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	quint16 bindPort = Int_to(quint16, sfp[1]);
	const QString protocolTag = String_to(const QString, sfp[2]);
	QNetworkProxyQuery::QueryType queryType = Int_to(QNetworkProxyQuery::QueryType, sfp[3]);
	KQNetworkProxyQuery *ret_v = new KQNetworkProxyQuery(bindPort, protocolTag, queryType);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QNetworkProxyQuery QNetworkProxyQuery.new(QNetworkProxyQuery other);
KMETHOD QNetworkProxyQuery_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QNetworkProxyQuery  other = *RawPtr_to(const QNetworkProxyQuery *, sfp[1]);
	KQNetworkProxyQuery *ret_v = new KQNetworkProxyQuery(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QNetworkProxyQuery.getLocalPort();
KMETHOD QNetworkProxyQuery_getLocalPort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxyQuery *  qp = RawPtr_to(QNetworkProxyQuery *, sfp[0]);
	if (qp) {
		int ret_v = qp->localPort();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QNetworkProxyQuery.getPeerHostName();
KMETHOD QNetworkProxyQuery_getPeerHostName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxyQuery *  qp = RawPtr_to(QNetworkProxyQuery *, sfp[0]);
	if (qp) {
		QString ret_v = qp->peerHostName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QNetworkProxyQuery.getPeerPort();
KMETHOD QNetworkProxyQuery_getPeerPort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxyQuery *  qp = RawPtr_to(QNetworkProxyQuery *, sfp[0]);
	if (qp) {
		int ret_v = qp->peerPort();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QNetworkProxyQuery.getProtocolTag();
KMETHOD QNetworkProxyQuery_getProtocolTag(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxyQuery *  qp = RawPtr_to(QNetworkProxyQuery *, sfp[0]);
	if (qp) {
		QString ret_v = qp->protocolTag();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QNetworkProxyQuery.getQueryType();
KMETHOD QNetworkProxyQuery_getQueryType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxyQuery *  qp = RawPtr_to(QNetworkProxyQuery *, sfp[0]);
	if (qp) {
		QNetworkProxyQuery::QueryType ret_v = qp->queryType();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QNetworkProxyQuery.setLocalPort(int port);
KMETHOD QNetworkProxyQuery_setLocalPort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxyQuery *  qp = RawPtr_to(QNetworkProxyQuery *, sfp[0]);
	if (qp) {
		int port = Int_to(int, sfp[1]);
		qp->setLocalPort(port);
	}
	RETURNvoid_();
}

//void QNetworkProxyQuery.setPeerHostName(String hostname);
KMETHOD QNetworkProxyQuery_setPeerHostName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxyQuery *  qp = RawPtr_to(QNetworkProxyQuery *, sfp[0]);
	if (qp) {
		const QString hostname = String_to(const QString, sfp[1]);
		qp->setPeerHostName(hostname);
	}
	RETURNvoid_();
}

//void QNetworkProxyQuery.setPeerPort(int port);
KMETHOD QNetworkProxyQuery_setPeerPort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxyQuery *  qp = RawPtr_to(QNetworkProxyQuery *, sfp[0]);
	if (qp) {
		int port = Int_to(int, sfp[1]);
		qp->setPeerPort(port);
	}
	RETURNvoid_();
}

//void QNetworkProxyQuery.setProtocolTag(String protocolTag);
KMETHOD QNetworkProxyQuery_setProtocolTag(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxyQuery *  qp = RawPtr_to(QNetworkProxyQuery *, sfp[0]);
	if (qp) {
		const QString protocolTag = String_to(const QString, sfp[1]);
		qp->setProtocolTag(protocolTag);
	}
	RETURNvoid_();
}

//void QNetworkProxyQuery.setQueryType(int type);
KMETHOD QNetworkProxyQuery_setQueryType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxyQuery *  qp = RawPtr_to(QNetworkProxyQuery *, sfp[0]);
	if (qp) {
		QNetworkProxyQuery::QueryType type = Int_to(QNetworkProxyQuery::QueryType, sfp[1]);
		qp->setQueryType(type);
	}
	RETURNvoid_();
}

//void QNetworkProxyQuery.setUrl(QUrl url);
KMETHOD QNetworkProxyQuery_setUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxyQuery *  qp = RawPtr_to(QNetworkProxyQuery *, sfp[0]);
	if (qp) {
		const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
		qp->setUrl(url);
	}
	RETURNvoid_();
}

//QUrl QNetworkProxyQuery.getUrl();
KMETHOD QNetworkProxyQuery_getUrl(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxyQuery *  qp = RawPtr_to(QNetworkProxyQuery *, sfp[0]);
	if (qp) {
		QUrl ret_v = qp->url();
		QUrl *ret_v_ = new QUrl(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QNetworkProxyQuery.parents();
KMETHOD QNetworkProxyQuery_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QNetworkProxyQuery *qp = RawPtr_to(QNetworkProxyQuery*, sfp[0]);
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

DummyQNetworkProxyQuery::DummyQNetworkProxyQuery()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQNetworkProxyQuery::~DummyQNetworkProxyQuery()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQNetworkProxyQuery::setSelf(knh_RawPtr_t *ptr)
{
	DummyQNetworkProxyQuery::self = ptr;
}

bool DummyQNetworkProxyQuery::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQNetworkProxyQuery::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkProxyQuery::event_map->bigin();
	if ((itr = DummyQNetworkProxyQuery::event_map->find(str)) == DummyQNetworkProxyQuery::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQNetworkProxyQuery::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQNetworkProxyQuery::slot_map->bigin();
	if ((itr = DummyQNetworkProxyQuery::slot_map->find(str)) == DummyQNetworkProxyQuery::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQNetworkProxyQuery::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQNetworkProxyQuery::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQNetworkProxyQuery::connection(QObject *o)
{
	QNetworkProxyQuery *p = dynamic_cast<QNetworkProxyQuery*>(o);
	if (p != NULL) {
	}
}

KQNetworkProxyQuery::KQNetworkProxyQuery() : QNetworkProxyQuery()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQNetworkProxyQuery();
}

KQNetworkProxyQuery::~KQNetworkProxyQuery()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QNetworkProxyQuery_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkProxyQuery *qp = RawPtr_to(KQNetworkProxyQuery *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkProxyQuery]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkProxyQuery]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QNetworkProxyQuery_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQNetworkProxyQuery *qp = RawPtr_to(KQNetworkProxyQuery *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QNetworkProxyQuery]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QNetworkProxyQuery]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QNetworkProxyQuery_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQNetworkProxyQuery *qp = (KQNetworkProxyQuery *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QNetworkProxyQuery*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QNetworkProxyQuery_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQNetworkProxyQuery *qp = (KQNetworkProxyQuery *)p->rawptr;
		KQNetworkProxyQuery *qp = static_cast<KQNetworkProxyQuery*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QNetworkProxyQuery_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QNetworkProxyQuery*>(p1->rawptr) == *static_cast<QNetworkProxyQuery*>(p2->rawptr) ? 0 : 1);
}

void KQNetworkProxyQuery::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QNetworkProxyQueryConstInt[] = {
	{"TcpSocket", QNetworkProxyQuery::TcpSocket},
	{"UdpSocket", QNetworkProxyQuery::UdpSocket},
	{"TcpServer", QNetworkProxyQuery::TcpServer},
	{"UrlRequest", QNetworkProxyQuery::UrlRequest},
	{NULL, 0}
};

DEFAPI(void) constQNetworkProxyQuery(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QNetworkProxyQueryConstInt);
}


DEFAPI(void) defQNetworkProxyQuery(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QNetworkProxyQuery";
	cdef->free = QNetworkProxyQuery_free;
	cdef->reftrace = QNetworkProxyQuery_reftrace;
	cdef->compareTo = QNetworkProxyQuery_compareTo;
}


