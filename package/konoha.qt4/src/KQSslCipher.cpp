//QSslCipher QSslCipher.new();
KMETHOD QSslCipher_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSslCipher *ret_v = new KQSslCipher();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QSslCipher QSslCipher.new(String name, int protocol);
KMETHOD QSslCipher_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString name = String_to(const QString, sfp[1]);
	QSsl::SslProtocol protocol = Int_to(QSsl::SslProtocol, sfp[2]);
	KQSslCipher *ret_v = new KQSslCipher(name, protocol);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QSslCipher QSslCipher.new(QSslCipher other);
KMETHOD QSslCipher_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QSslCipher  other = *RawPtr_to(const QSslCipher *, sfp[1]);
	KQSslCipher *ret_v = new KQSslCipher(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//String QSslCipher.authenticationMethod();
KMETHOD QSslCipher_authenticationMethod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCipher *  qp = RawPtr_to(QSslCipher *, sfp[0]);
	if (qp) {
		QString ret_v = qp->authenticationMethod();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QSslCipher.encryptionMethod();
KMETHOD QSslCipher_encryptionMethod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCipher *  qp = RawPtr_to(QSslCipher *, sfp[0]);
	if (qp) {
		QString ret_v = qp->encryptionMethod();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QSslCipher.keyExchangeMethod();
KMETHOD QSslCipher_keyExchangeMethod(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCipher *  qp = RawPtr_to(QSslCipher *, sfp[0]);
	if (qp) {
		QString ret_v = qp->keyExchangeMethod();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QSslCipher.name();
KMETHOD QSslCipher_name(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCipher *  qp = RawPtr_to(QSslCipher *, sfp[0]);
	if (qp) {
		QString ret_v = qp->name();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QSslCipher.protocol();
KMETHOD QSslCipher_protocol(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCipher *  qp = RawPtr_to(QSslCipher *, sfp[0]);
	if (qp) {
		QSsl::SslProtocol ret_v = qp->protocol();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QSslCipher.protocolString();
KMETHOD QSslCipher_protocolString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCipher *  qp = RawPtr_to(QSslCipher *, sfp[0]);
	if (qp) {
		QString ret_v = qp->protocolString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QSslCipher.supportedBits();
KMETHOD QSslCipher_supportedBits(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCipher *  qp = RawPtr_to(QSslCipher *, sfp[0]);
	if (qp) {
		int ret_v = qp->supportedBits();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QSslCipher.usedBits();
KMETHOD QSslCipher_usedBits(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCipher *  qp = RawPtr_to(QSslCipher *, sfp[0]);
	if (qp) {
		int ret_v = qp->usedBits();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<String> QSslCipher.parents();
KMETHOD QSslCipher_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSslCipher *qp = RawPtr_to(QSslCipher*, sfp[0]);
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

DummyQSslCipher::DummyQSslCipher()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQSslCipher::~DummyQSslCipher()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQSslCipher::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSslCipher::self = ptr;
}

bool DummyQSslCipher::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQSslCipher::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSslCipher::event_map->bigin();
	if ((itr = DummyQSslCipher::event_map->find(str)) == DummyQSslCipher::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSslCipher::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSslCipher::slot_map->bigin();
	if ((itr = DummyQSslCipher::slot_map->find(str)) == DummyQSslCipher::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQSslCipher::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQSslCipher::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQSslCipher::connection(QObject *o)
{
	QSslCipher *p = dynamic_cast<QSslCipher*>(o);
	if (p != NULL) {
	}
}

KQSslCipher::KQSslCipher() : QSslCipher()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQSslCipher();
}

KQSslCipher::~KQSslCipher()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QSslCipher_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSslCipher *qp = RawPtr_to(KQSslCipher *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSslCipher]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSslCipher]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSslCipher_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSslCipher *qp = RawPtr_to(KQSslCipher *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSslCipher]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSslCipher]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSslCipher_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQSslCipher *qp = (KQSslCipher *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QSslCipher*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QSslCipher_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQSslCipher *qp = (KQSslCipher *)p->rawptr;
		KQSslCipher *qp = static_cast<KQSslCipher*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSslCipher_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QSslCipher*>(p1->rawptr) == *static_cast<QSslCipher*>(p2->rawptr) ? 0 : 1);
}

void KQSslCipher::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQSslCipher(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSslCipher";
	cdef->free = QSslCipher_free;
	cdef->reftrace = QSslCipher_reftrace;
	cdef->compareTo = QSslCipher_compareTo;
}


