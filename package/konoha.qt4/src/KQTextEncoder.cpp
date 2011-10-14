//QTextEncoder QTextEncoder.new(QTextCodec codec);
KMETHOD QTextEncoder_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTextCodec*  codec = RawPtr_to(const QTextCodec*, sfp[1]);
	KQTextEncoder *ret_v = new KQTextEncoder(codec);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTextEncoder QTextEncoder.new(QTextCodec codec, int flags);
KMETHOD QTextEncoder_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTextCodec*  codec = RawPtr_to(const QTextCodec*, sfp[1]);
	QTextCodec::ConversionFlags flags = Int_to(QTextCodec::ConversionFlags, sfp[2]);
	KQTextEncoder *ret_v = new KQTextEncoder(codec, flags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QByteArray QTextEncoder.fromUnicode(String str);
KMETHOD QTextEncoder_fromUnicode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEncoder *  qp = RawPtr_to(QTextEncoder *, sfp[0]);
	if (qp != NULL) {
		const QString str = String_to(const QString, sfp[1]);
		QByteArray ret_v = qp->fromUnicode(str);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QByteArray QTextEncoder.fromUnicode(QChar uc, int len);
KMETHOD QTextEncoder_fromUnicode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextEncoder *  qp = RawPtr_to(QTextEncoder *, sfp[0]);
	if (qp != NULL) {
		const QChar*  uc = RawPtr_to(const QChar*, sfp[1]);
		int len = Int_to(int, sfp[2]);
		QByteArray ret_v = qp->fromUnicode(uc, len);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/

DummyQTextEncoder::DummyQTextEncoder()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextEncoder::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextEncoder::self = ptr;
}

bool DummyQTextEncoder::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextEncoder::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextEncoder::event_map->bigin();
	if ((itr = DummyQTextEncoder::event_map->find(str)) == DummyQTextEncoder::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextEncoder::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextEncoder::slot_map->bigin();
	if ((itr = DummyQTextEncoder::slot_map->find(str)) == DummyQTextEncoder::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQTextEncoder::connection(QObject *o)
{
	return;
}

KQTextEncoder::KQTextEncoder(const QTextCodec* codec) : QTextEncoder(codec)
{
	self = NULL;
	dummy = new DummyQTextEncoder();
	dummy->connection((QObject*)this);
}

KMETHOD QTextEncoder_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextEncoder *qp = RawPtr_to(KQTextEncoder *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextEncoder]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextEncoder]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextEncoder_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextEncoder *qp = RawPtr_to(KQTextEncoder *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextEncoder]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextEncoder]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextEncoder_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextEncoder *qp = (KQTextEncoder *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextEncoder_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQTextEncoder *qp = (KQTextEncoder *)p->rawptr;
		(void)qp;
	}
}

static int QTextEncoder_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextEncoder::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQTextEncoder(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextEncoder";
	cdef->free = QTextEncoder_free;
	cdef->reftrace = QTextEncoder_reftrace;
	cdef->compareTo = QTextEncoder_compareTo;
}


