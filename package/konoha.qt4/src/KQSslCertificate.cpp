//QSslCertificate QSslCertificate.new(QIODevice device, int fmt);
KMETHOD QSslCertificate_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice*  device = RawPtr_to(QIODevice*, sfp[1]);
	QSsl::EncodingFormat format = Int_to(QSsl::EncodingFormat, sfp[2]);
	KQSslCertificate *ret_v = new KQSslCertificate(device, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QSslCertificate QSslCertificate.new(QByteArray data, int fmt);
KMETHOD QSslCertificate_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QByteArray  data = *RawPtr_to(const QByteArray *, sfp[1]);
	QSsl::EncodingFormat format = Int_to(QSsl::EncodingFormat, sfp[2]);
	KQSslCertificate *ret_v = new KQSslCertificate(data, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QSslCertificate QSslCertificate.new(QSslCertificate other);
KMETHOD QSslCertificate_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QSslCertificate  other = *RawPtr_to(const QSslCertificate *, sfp[1]);
	KQSslCertificate *ret_v = new KQSslCertificate(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QSslCertificate.clear();
KMETHOD QSslCertificate_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCertificate *  qp = RawPtr_to(QSslCertificate *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//QByteArray QSslCertificate.digest(int algorithm);
KMETHOD QSslCertificate_digest(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCertificate *  qp = RawPtr_to(QSslCertificate *, sfp[0]);
	if (qp) {
		QCryptographicHash::Algorithm algorithm = Int_to(QCryptographicHash::Algorithm, sfp[1]);
		QByteArray ret_v = qp->digest(algorithm);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QSslCertificate.effectiveDate();
KMETHOD QSslCertificate_effectiveDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCertificate *  qp = RawPtr_to(QSslCertificate *, sfp[0]);
	if (qp) {
		QDateTime ret_v = qp->effectiveDate();
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QSslCertificate.expiryDate();
KMETHOD QSslCertificate_expiryDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCertificate *  qp = RawPtr_to(QSslCertificate *, sfp[0]);
	if (qp) {
		QDateTime ret_v = qp->expiryDate();
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QSslCertificate.issuerInfo(int subject);
KMETHOD QSslCertificate_issuerInfo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCertificate *  qp = RawPtr_to(QSslCertificate *, sfp[0]);
	if (qp) {
		QSslCertificate::SubjectInfo subject = Int_to(QSslCertificate::SubjectInfo, sfp[1]);
		QString ret_v = qp->issuerInfo(subject);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QSslCertificate.issuerInfo(QByteArray tag);
KMETHOD QSslCertificate_issuerInfo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCertificate *  qp = RawPtr_to(QSslCertificate *, sfp[0]);
	if (qp) {
		const QByteArray  tag = *RawPtr_to(const QByteArray *, sfp[1]);
		QString ret_v = qp->issuerInfo(tag);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QSslKey QSslCertificate.publicKey();
KMETHOD QSslCertificate_publicKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCertificate *  qp = RawPtr_to(QSslCertificate *, sfp[0]);
	if (qp) {
		QSslKey ret_v = qp->publicKey();
		QSslKey *ret_v_ = new QSslKey(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QSslCertificate.serialNumber();
KMETHOD QSslCertificate_serialNumber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCertificate *  qp = RawPtr_to(QSslCertificate *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->serialNumber();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QSslCertificate.subjectInfo(int subject);
KMETHOD QSslCertificate_subjectInfo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCertificate *  qp = RawPtr_to(QSslCertificate *, sfp[0]);
	if (qp) {
		QSslCertificate::SubjectInfo subject = Int_to(QSslCertificate::SubjectInfo, sfp[1]);
		QString ret_v = qp->subjectInfo(subject);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QSslCertificate.subjectInfo(QByteArray tag);
KMETHOD QSslCertificate_subjectInfo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCertificate *  qp = RawPtr_to(QSslCertificate *, sfp[0]);
	if (qp) {
		const QByteArray  tag = *RawPtr_to(const QByteArray *, sfp[1]);
		QString ret_v = qp->subjectInfo(tag);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QByteArray QSslCertificate.toDer();
KMETHOD QSslCertificate_toDer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCertificate *  qp = RawPtr_to(QSslCertificate *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->toDer();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QSslCertificate.toPem();
KMETHOD QSslCertificate_toPem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCertificate *  qp = RawPtr_to(QSslCertificate *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->toPem();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QSslCertificate.version();
KMETHOD QSslCertificate_version(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCertificate *  qp = RawPtr_to(QSslCertificate *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->version();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QSslCertificate> QSslCertificate.fromData(QByteArray data, int fmt);
KMETHOD QSslCertificate_fromData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QByteArray  data = *RawPtr_to(const QByteArray *, sfp[1]);
		QSsl::EncodingFormat format = Int_to(QSsl::EncodingFormat, sfp[2]);
		QList<QSslCertificate> ret_v = QSslCertificate::fromData(data, format);
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
	

//Array<QSslCertificate> QSslCertificate.fromDevice(QIODevice device, int fmt);
KMETHOD QSslCertificate_fromDevice(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QIODevice*  device = RawPtr_to(QIODevice*, sfp[1]);
		QSsl::EncodingFormat format = Int_to(QSsl::EncodingFormat, sfp[2]);
		QList<QSslCertificate> ret_v = QSslCertificate::fromDevice(device, format);
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
	

//Array<QSslCertificate> QSslCertificate.fromPath(String path, int fmt, int syntax);
KMETHOD QSslCertificate_fromPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString path = String_to(const QString, sfp[1]);
		QSsl::EncodingFormat format = Int_to(QSsl::EncodingFormat, sfp[2]);
		QRegExp::PatternSyntax syntax = Int_to(QRegExp::PatternSyntax, sfp[3]);
		QList<QSslCertificate> ret_v = QSslCertificate::fromPath(path, format, syntax);
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
	

//Array<String> QSslCertificate.parents();
KMETHOD QSslCertificate_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCertificate *qp = RawPtr_to(QSslCertificate*, sfp[0]);
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

DummyQSslCertificate::DummyQSslCertificate()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSslCertificate::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSslCertificate::self = ptr;
}

bool DummyQSslCertificate::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQSslCertificate::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSslCertificate::event_map->bigin();
	if ((itr = DummyQSslCertificate::event_map->find(str)) == DummyQSslCertificate::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSslCertificate::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSslCertificate::slot_map->bigin();
	if ((itr = DummyQSslCertificate::slot_map->find(str)) == DummyQSslCertificate::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQSslCertificate::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQSslCertificate::connection(QObject *o)
{
	QSslCertificate *p = dynamic_cast<QSslCertificate*>(o);
	if (p != NULL) {
	}
}

KQSslCertificate::KQSslCertificate(QIODevice* device, QSsl::EncodingFormat format) : QSslCertificate(device, format)
{
	self = NULL;
	dummy = new DummyQSslCertificate();
}

KMETHOD QSslCertificate_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSslCertificate *qp = RawPtr_to(KQSslCertificate *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSslCertificate]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSslCertificate]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSslCertificate_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSslCertificate *qp = RawPtr_to(KQSslCertificate *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSslCertificate]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSslCertificate]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSslCertificate_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSslCertificate *qp = (KQSslCertificate *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSslCertificate_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQSslCertificate *qp = (KQSslCertificate *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSslCertificate_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QSslCertificate*>(p1->rawptr) == *static_cast<QSslCertificate*>(p2->rawptr) ? 0 : 1);
}

void KQSslCertificate::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QSslCertificateConstInt[] = {
	{"Organization", QSslCertificate::Organization},
	{"CommonName", QSslCertificate::CommonName},
	{"LocalityName", QSslCertificate::LocalityName},
	{"OrganizationalUnitName", QSslCertificate::OrganizationalUnitName},
	{"CountryName", QSslCertificate::CountryName},
	{"StateOrProvinceName", QSslCertificate::StateOrProvinceName},
	{NULL, 0}
};

DEFAPI(void) constQSslCertificate(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QSslCertificateConstInt);
}


DEFAPI(void) defQSslCertificate(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSslCertificate";
	cdef->free = QSslCertificate_free;
	cdef->reftrace = QSslCertificate_reftrace;
	cdef->compareTo = QSslCertificate_compareTo;
}


