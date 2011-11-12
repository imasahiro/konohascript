//QSslKey QSslKey.new();
KMETHOD QSslKey_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSslKey *ret_v = new KQSslKey();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QSslKey QSslKey.new(QByteArray encoded, int algorithm, int encoding, int type, QByteArray passPhrase);
KMETHOD QSslKey_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QByteArray  encoded = *RawPtr_to(const QByteArray *, sfp[1]);
	QSsl::KeyAlgorithm algorithm = Int_to(QSsl::KeyAlgorithm, sfp[2]);
	QSsl::EncodingFormat encoding = Int_to(QSsl::EncodingFormat, sfp[3]);
	QSsl::KeyType type = Int_to(QSsl::KeyType, sfp[4]);
	const QByteArray  passPhrase = *RawPtr_to(const QByteArray *, sfp[5]);
	KQSslKey *ret_v = new KQSslKey(encoded, algorithm, encoding, type, passPhrase);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QSslKey QSslKey.new(QIODevice device, int algorithm, int encoding, int type, QByteArray passPhrase);
KMETHOD QSslKey_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice*  device = RawPtr_to(QIODevice*, sfp[1]);
	QSsl::KeyAlgorithm algorithm = Int_to(QSsl::KeyAlgorithm, sfp[2]);
	QSsl::EncodingFormat encoding = Int_to(QSsl::EncodingFormat, sfp[3]);
	QSsl::KeyType type = Int_to(QSsl::KeyType, sfp[4]);
	const QByteArray  passPhrase = *RawPtr_to(const QByteArray *, sfp[5]);
	KQSslKey *ret_v = new KQSslKey(device, algorithm, encoding, type, passPhrase);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QSslKey QSslKey.new(QSslKey other);
KMETHOD QSslKey_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QSslKey  other = *RawPtr_to(const QSslKey *, sfp[1]);
	KQSslKey *ret_v = new KQSslKey(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QSslKey.algorithm();
KMETHOD QSslKey_algorithm(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslKey *  qp = RawPtr_to(QSslKey *, sfp[0]);
	if (qp) {
		QSsl::KeyAlgorithm ret_v = qp->algorithm();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QSslKey.clear();
KMETHOD QSslKey_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslKey *  qp = RawPtr_to(QSslKey *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//int QSslKey.length();
KMETHOD QSslKey_length(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslKey *  qp = RawPtr_to(QSslKey *, sfp[0]);
	if (qp) {
		int ret_v = qp->length();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QByteArray QSslKey.toDer(QByteArray passPhrase);
KMETHOD QSslKey_toDer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslKey *  qp = RawPtr_to(QSslKey *, sfp[0]);
	if (qp) {
		const QByteArray  passPhrase = *RawPtr_to(const QByteArray *, sfp[1]);
		QByteArray ret_v = qp->toDer(passPhrase);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QSslKey.toPem(QByteArray passPhrase);
KMETHOD QSslKey_toPem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslKey *  qp = RawPtr_to(QSslKey *, sfp[0]);
	if (qp) {
		const QByteArray  passPhrase = *RawPtr_to(const QByteArray *, sfp[1]);
		QByteArray ret_v = qp->toPem(passPhrase);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QSslKey.type();
KMETHOD QSslKey_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslKey *  qp = RawPtr_to(QSslKey *, sfp[0]);
	if (qp) {
		QSsl::KeyType ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<String> QSslKey.parents();
KMETHOD QSslKey_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslKey *qp = RawPtr_to(QSslKey*, sfp[0]);
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

DummyQSslKey::DummyQSslKey()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSslKey::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSslKey::self = ptr;
}

bool DummyQSslKey::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQSslKey::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSslKey::event_map->bigin();
	if ((itr = DummyQSslKey::event_map->find(str)) == DummyQSslKey::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSslKey::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSslKey::slot_map->bigin();
	if ((itr = DummyQSslKey::slot_map->find(str)) == DummyQSslKey::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQSslKey::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQSslKey::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQSslKey::connection(QObject *o)
{
	QSslKey *p = dynamic_cast<QSslKey*>(o);
	if (p != NULL) {
	}
}

KQSslKey::KQSslKey() : QSslKey()
{
	self = NULL;
	dummy = new DummyQSslKey();
}

KMETHOD QSslKey_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSslKey *qp = RawPtr_to(KQSslKey *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSslKey]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSslKey]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSslKey_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSslKey *qp = RawPtr_to(KQSslKey *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSslKey]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSslKey]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSslKey_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSslKey *qp = (KQSslKey *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSslKey_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQSslKey *qp = (KQSslKey *)p->rawptr;
//		KQSslKey *qp = static_cast<KQSslKey*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSslKey_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QSslKey*>(p1->rawptr) == *static_cast<QSslKey*>(p2->rawptr) ? 0 : 1);
}

void KQSslKey::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQSslKey(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSslKey";
	cdef->free = QSslKey_free;
	cdef->reftrace = QSslKey_reftrace;
	cdef->compareTo = QSslKey_compareTo;
}


