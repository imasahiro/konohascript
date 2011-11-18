//QTextDecoder QTextDecoder.new(QTextCodec codec);
KMETHOD QTextDecoder_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTextCodec*  codec = RawPtr_to(const QTextCodec*, sfp[1]);
	KQTextDecoder *ret_v = new KQTextDecoder(codec);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTextDecoder QTextDecoder.new(QTextCodec codec, int flags);
KMETHOD QTextDecoder_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTextCodec*  codec = RawPtr_to(const QTextCodec*, sfp[1]);
	QTextCodec::ConversionFlags flags = Int_to(QTextCodec::ConversionFlags, sfp[2]);
	KQTextDecoder *ret_v = new KQTextDecoder(codec, flags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//String QTextDecoder.toUnicode(String chars, int len);
KMETHOD QTextDecoder_toUnicode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDecoder *  qp = RawPtr_to(QTextDecoder *, sfp[0]);
	if (qp) {
		const char*  chars = RawPtr_to(const char*, sfp[1]);
		int len = Int_to(int, sfp[2]);
		QString ret_v = qp->toUnicode(chars, len);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//void QTextDecoder.toUnicode(String target, String chars, int len);
KMETHOD QTextDecoder_toUnicode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDecoder *  qp = RawPtr_to(QTextDecoder *, sfp[0]);
	if (qp) {
		QString* target = String_to(QString*, sfp[1]);
		const char*  chars = RawPtr_to(const char*, sfp[2]);
		int len = Int_to(int, sfp[3]);
		qp->toUnicode(target, chars, len);
	}
	RETURNvoid_();
}
*/
/*
//String QTextDecoder.toUnicode(QByteArray ba);
KMETHOD QTextDecoder_toUnicode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDecoder *  qp = RawPtr_to(QTextDecoder *, sfp[0]);
	if (qp) {
		const QByteArray  ba = *RawPtr_to(const QByteArray *, sfp[1]);
		QString ret_v = qp->toUnicode(ba);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//Array<String> QTextDecoder.parents();
KMETHOD QTextDecoder_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextDecoder *qp = RawPtr_to(QTextDecoder*, sfp[0]);
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

DummyQTextDecoder::DummyQTextDecoder()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQTextDecoder::~DummyQTextDecoder()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQTextDecoder::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextDecoder::self = ptr;
}

bool DummyQTextDecoder::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextDecoder::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextDecoder::event_map->bigin();
	if ((itr = DummyQTextDecoder::event_map->find(str)) == DummyQTextDecoder::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextDecoder::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextDecoder::slot_map->bigin();
	if ((itr = DummyQTextDecoder::slot_map->find(str)) == DummyQTextDecoder::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTextDecoder::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTextDecoder::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQTextDecoder::connection(QObject *o)
{
	QTextDecoder *p = dynamic_cast<QTextDecoder*>(o);
	if (p != NULL) {
	}
}

KQTextDecoder::KQTextDecoder(const QTextCodec* codec) : QTextDecoder(codec)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQTextDecoder();
}

KQTextDecoder::~KQTextDecoder()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QTextDecoder_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextDecoder *qp = RawPtr_to(KQTextDecoder *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextDecoder]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextDecoder]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextDecoder_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextDecoder *qp = RawPtr_to(KQTextDecoder *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextDecoder]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextDecoder]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextDecoder_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQTextDecoder *qp = (KQTextDecoder *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QTextDecoder*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QTextDecoder_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQTextDecoder *qp = (KQTextDecoder *)p->rawptr;
		KQTextDecoder *qp = static_cast<KQTextDecoder*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextDecoder_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextDecoder::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQTextDecoder(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextDecoder";
	cdef->free = QTextDecoder_free;
	cdef->reftrace = QTextDecoder_reftrace;
	cdef->compareTo = QTextDecoder_compareTo;
}


