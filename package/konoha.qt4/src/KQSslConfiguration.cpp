//QSslConfiguration QSslConfiguration.new();
KMETHOD QSslConfiguration_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSslConfiguration *ret_v = new KQSslConfiguration();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QSslConfiguration QSslConfiguration.new(QSslConfiguration other);
KMETHOD QSslConfiguration_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QSslConfiguration  other = *RawPtr_to(const QSslConfiguration *, sfp[1]);
	KQSslConfiguration *ret_v = new KQSslConfiguration(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//Array<QSslCertificate> QSslConfiguration.getCaCertificates();
KMETHOD QSslConfiguration_getCaCertificates(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *  qp = RawPtr_to(QSslConfiguration *, sfp[0]);
	if (qp) {
		QList<QSslCertificate> ret_v = qp->caCertificates();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QSslCertificate"));
		for (int n = 0; n < list_size; n++) {
			QSslCertificate *ret_v_ = new QSslCertificate(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//Array<QSslCipher> QSslConfiguration.getCiphers();
KMETHOD QSslConfiguration_getCiphers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *  qp = RawPtr_to(QSslConfiguration *, sfp[0]);
	if (qp) {
		QList<QSslCipher> ret_v = qp->ciphers();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QSslCipher"));
		for (int n = 0; n < list_size; n++) {
			QSslCipher *ret_v_ = new QSslCipher(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QSslCertificate QSslConfiguration.getLocalCertificate();
KMETHOD QSslConfiguration_getLocalCertificate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *  qp = RawPtr_to(QSslConfiguration *, sfp[0]);
	if (qp) {
		QSslCertificate ret_v = qp->localCertificate();
		QSslCertificate *ret_v_ = new QSslCertificate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSslCertificate QSslConfiguration.peerCertificate();
KMETHOD QSslConfiguration_peerCertificate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *  qp = RawPtr_to(QSslConfiguration *, sfp[0]);
	if (qp) {
		QSslCertificate ret_v = qp->peerCertificate();
		QSslCertificate *ret_v_ = new QSslCertificate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QSslCertificate> QSslConfiguration.peerCertificateChain();
KMETHOD QSslConfiguration_peerCertificateChain(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *  qp = RawPtr_to(QSslConfiguration *, sfp[0]);
	if (qp) {
		QList<QSslCertificate> ret_v = qp->peerCertificateChain();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QSslCertificate"));
		for (int n = 0; n < list_size; n++) {
			QSslCertificate *ret_v_ = new QSslCertificate(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//int QSslConfiguration.getPeerVerifyDepth();
KMETHOD QSslConfiguration_getPeerVerifyDepth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *  qp = RawPtr_to(QSslConfiguration *, sfp[0]);
	if (qp) {
		int ret_v = qp->peerVerifyDepth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QSslConfiguration.getPeerVerifyMode();
KMETHOD QSslConfiguration_getPeerVerifyMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *  qp = RawPtr_to(QSslConfiguration *, sfp[0]);
	if (qp) {
		QSslSocket::PeerVerifyMode ret_v = qp->peerVerifyMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QSslKey QSslConfiguration.getPrivateKey();
KMETHOD QSslConfiguration_getPrivateKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *  qp = RawPtr_to(QSslConfiguration *, sfp[0]);
	if (qp) {
		QSslKey ret_v = qp->privateKey();
		QSslKey *ret_v_ = new QSslKey(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QSslConfiguration.getProtocol();
KMETHOD QSslConfiguration_getProtocol(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *  qp = RawPtr_to(QSslConfiguration *, sfp[0]);
	if (qp) {
		QSsl::SslProtocol ret_v = qp->protocol();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QSslCipher QSslConfiguration.sessionCipher();
KMETHOD QSslConfiguration_sessionCipher(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *  qp = RawPtr_to(QSslConfiguration *, sfp[0]);
	if (qp) {
		QSslCipher ret_v = qp->sessionCipher();
		QSslCipher *ret_v_ = new QSslCipher(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QSslConfiguration.setCaCertificates(Array<QSslCertificate> certificates);
KMETHOD QSslConfiguration_setCaCertificates(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *  qp = RawPtr_to(QSslConfiguration *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QSslCertificate> certificates;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			certificates.append(*(QSslCertificate*)p->rawptr);
		}
		qp->setCaCertificates(certificates);
	}
	RETURNvoid_();
}

//void QSslConfiguration.setCiphers(Array<QSslCipher> ciphers);
KMETHOD QSslConfiguration_setCiphers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *  qp = RawPtr_to(QSslConfiguration *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QSslCipher> ciphers;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			ciphers.append(*(QSslCipher*)p->rawptr);
		}
		qp->setCiphers(ciphers);
	}
	RETURNvoid_();
}

//void QSslConfiguration.setLocalCertificate(QSslCertificate certificate);
KMETHOD QSslConfiguration_setLocalCertificate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *  qp = RawPtr_to(QSslConfiguration *, sfp[0]);
	if (qp) {
		const QSslCertificate  certificate = *RawPtr_to(const QSslCertificate *, sfp[1]);
		qp->setLocalCertificate(certificate);
	}
	RETURNvoid_();
}

//void QSslConfiguration.setPeerVerifyDepth(int depth);
KMETHOD QSslConfiguration_setPeerVerifyDepth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *  qp = RawPtr_to(QSslConfiguration *, sfp[0]);
	if (qp) {
		int depth = Int_to(int, sfp[1]);
		qp->setPeerVerifyDepth(depth);
	}
	RETURNvoid_();
}

//void QSslConfiguration.setPeerVerifyMode(int mode);
KMETHOD QSslConfiguration_setPeerVerifyMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *  qp = RawPtr_to(QSslConfiguration *, sfp[0]);
	if (qp) {
		QSslSocket::PeerVerifyMode mode = Int_to(QSslSocket::PeerVerifyMode, sfp[1]);
		qp->setPeerVerifyMode(mode);
	}
	RETURNvoid_();
}

//void QSslConfiguration.setPrivateKey(QSslKey key);
KMETHOD QSslConfiguration_setPrivateKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *  qp = RawPtr_to(QSslConfiguration *, sfp[0]);
	if (qp) {
		const QSslKey  key = *RawPtr_to(const QSslKey *, sfp[1]);
		qp->setPrivateKey(key);
	}
	RETURNvoid_();
}

//void QSslConfiguration.setProtocol(int protocol);
KMETHOD QSslConfiguration_setProtocol(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *  qp = RawPtr_to(QSslConfiguration *, sfp[0]);
	if (qp) {
		QSsl::SslProtocol protocol = Int_to(QSsl::SslProtocol, sfp[1]);
		qp->setProtocol(protocol);
	}
	RETURNvoid_();
}

//QSslConfiguration QSslConfiguration.getDefaultConfiguration();
KMETHOD QSslConfiguration_getDefaultConfiguration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QSslConfiguration ret_v = QSslConfiguration::defaultConfiguration();
		QSslConfiguration *ret_v_ = new QSslConfiguration(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QSslConfiguration.setDefaultConfiguration(QSslConfiguration configuration);
KMETHOD QSslConfiguration_setDefaultConfiguration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QSslConfiguration  configuration = *RawPtr_to(const QSslConfiguration *, sfp[1]);
		QSslConfiguration::setDefaultConfiguration(configuration);
	}
	RETURNvoid_();
}

//Array<String> QSslConfiguration.parents();
KMETHOD QSslConfiguration_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslConfiguration *qp = RawPtr_to(QSslConfiguration*, sfp[0]);
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

DummyQSslConfiguration::DummyQSslConfiguration()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSslConfiguration::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSslConfiguration::self = ptr;
}

bool DummyQSslConfiguration::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQSslConfiguration::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSslConfiguration::event_map->bigin();
	if ((itr = DummyQSslConfiguration::event_map->find(str)) == DummyQSslConfiguration::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSslConfiguration::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSslConfiguration::slot_map->bigin();
	if ((itr = DummyQSslConfiguration::slot_map->find(str)) == DummyQSslConfiguration::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQSslConfiguration::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQSslConfiguration::connection(QObject *o)
{
	QSslConfiguration *p = dynamic_cast<QSslConfiguration*>(o);
	if (p != NULL) {
	}
}

KQSslConfiguration::KQSslConfiguration() : QSslConfiguration()
{
	self = NULL;
	dummy = new DummyQSslConfiguration();
}

KMETHOD QSslConfiguration_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSslConfiguration *qp = RawPtr_to(KQSslConfiguration *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSslConfiguration]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSslConfiguration]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSslConfiguration_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSslConfiguration *qp = RawPtr_to(KQSslConfiguration *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSslConfiguration]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSslConfiguration]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSslConfiguration_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSslConfiguration *qp = (KQSslConfiguration *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSslConfiguration_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQSslConfiguration *qp = (KQSslConfiguration *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSslConfiguration_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QSslConfiguration*>(p1->rawptr) == *static_cast<QSslConfiguration*>(p2->rawptr) ? 0 : 1);
}

void KQSslConfiguration::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQSslConfiguration(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSslConfiguration";
	cdef->free = QSslConfiguration_free;
	cdef->reftrace = QSslConfiguration_reftrace;
	cdef->compareTo = QSslConfiguration_compareTo;
}


