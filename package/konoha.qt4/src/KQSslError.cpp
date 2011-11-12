//QSslError QSslError.new();
KMETHOD QSslError_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSslError *ret_v = new KQSslError();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QSslError QSslError.new(int error);
KMETHOD QSslError_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslError::SslError error = Int_to(QSslError::SslError, sfp[1]);
	KQSslError *ret_v = new KQSslError(error);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QSslError QSslError.new(int error, QSslCertificate certificate);
KMETHOD QSslError_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslError::SslError error = Int_to(QSslError::SslError, sfp[1]);
	const QSslCertificate  certificate = *RawPtr_to(const QSslCertificate *, sfp[2]);
	KQSslError *ret_v = new KQSslError(error, certificate);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QSslError QSslError.new(QSslError other);
KMETHOD QSslError_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QSslError  other = *RawPtr_to(const QSslError *, sfp[1]);
	KQSslError *ret_v = new KQSslError(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QSslCertificate QSslError.certificate();
KMETHOD QSslError_certificate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslError *  qp = RawPtr_to(QSslError *, sfp[0]);
	if (qp) {
		QSslCertificate ret_v = qp->certificate();
		QSslCertificate *ret_v_ = new QSslCertificate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QSslError.error();
KMETHOD QSslError_error(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslError *  qp = RawPtr_to(QSslError *, sfp[0]);
	if (qp) {
		QSslError::SslError ret_v = qp->error();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QSslError.errorString();
KMETHOD QSslError_errorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslError *  qp = RawPtr_to(QSslError *, sfp[0]);
	if (qp) {
		QString ret_v = qp->errorString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QSslError.parents();
KMETHOD QSslError_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslError *qp = RawPtr_to(QSslError*, sfp[0]);
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

DummyQSslError::DummyQSslError()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSslError::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSslError::self = ptr;
}

bool DummyQSslError::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQSslError::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSslError::event_map->bigin();
	if ((itr = DummyQSslError::event_map->find(str)) == DummyQSslError::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSslError::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSslError::slot_map->bigin();
	if ((itr = DummyQSslError::slot_map->find(str)) == DummyQSslError::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQSslError::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQSslError::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQSslError::connection(QObject *o)
{
	QSslError *p = dynamic_cast<QSslError*>(o);
	if (p != NULL) {
	}
}

KQSslError::KQSslError() : QSslError()
{
	self = NULL;
	dummy = new DummyQSslError();
}

KMETHOD QSslError_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSslError *qp = RawPtr_to(KQSslError *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSslError]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSslError]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSslError_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSslError *qp = RawPtr_to(KQSslError *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSslError]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSslError]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSslError_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSslError *qp = (KQSslError *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSslError_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQSslError *qp = (KQSslError *)p->rawptr;
//		KQSslError *qp = static_cast<KQSslError*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSslError_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QSslError*>(p1->rawptr) == *static_cast<QSslError*>(p2->rawptr) ? 0 : 1);
}

void KQSslError::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QSslErrorConstInt[] = {
	{"NoError", QSslError::NoError},
	{"UnableToGetIssuerCertificate", QSslError::UnableToGetIssuerCertificate},
	{"UnableToDecryptCertificateSignature", QSslError::UnableToDecryptCertificateSignature},
	{"UnableToDecodeIssuerPublicKey", QSslError::UnableToDecodeIssuerPublicKey},
	{"CertificateSignatureFailed", QSslError::CertificateSignatureFailed},
	{"CertificateNotYetValid", QSslError::CertificateNotYetValid},
	{"CertificateExpired", QSslError::CertificateExpired},
	{"InvalidNotBeforeField", QSslError::InvalidNotBeforeField},
	{"InvalidNotAfterField", QSslError::InvalidNotAfterField},
	{"SelfSignedCertificate", QSslError::SelfSignedCertificate},
	{"SelfSignedCertificateInChain", QSslError::SelfSignedCertificateInChain},
	{"UnableToGetLocalIssuerCertificate", QSslError::UnableToGetLocalIssuerCertificate},
	{"UnableToVerifyFirstCertificate", QSslError::UnableToVerifyFirstCertificate},
	{"CertificateRevoked", QSslError::CertificateRevoked},
	{"InvalidCaCertificate", QSslError::InvalidCaCertificate},
	{"PathLengthExceeded", QSslError::PathLengthExceeded},
	{"InvalidPurpose", QSslError::InvalidPurpose},
	{"CertificateUntrusted", QSslError::CertificateUntrusted},
	{"CertificateRejected", QSslError::CertificateRejected},
	{"SubjectIssuerMismatch", QSslError::SubjectIssuerMismatch},
	{"AuthorityIssuerSerialNumberMismatch", QSslError::AuthorityIssuerSerialNumberMismatch},
	{"NoPeerCertificate", QSslError::NoPeerCertificate},
	{"HostNameMismatch", QSslError::HostNameMismatch},
	{"UnspecifiedError", QSslError::UnspecifiedError},
	{"NoSslSupport", QSslError::NoSslSupport},
	{NULL, 0}
};

DEFAPI(void) constQSslError(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QSslErrorConstInt);
}


DEFAPI(void) defQSslError(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSslError";
	cdef->free = QSslError_free;
	cdef->reftrace = QSslError_reftrace;
	cdef->compareTo = QSslError_compareTo;
}


