//@Virtual Array<QByteArray> QTextCodec.aliases();
KMETHOD QTextCodec_aliases(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCodec *  qp = RawPtr_to(QTextCodec *, sfp[0]);
	if (qp) {
		QList<QByteArray> ret_v = qp->aliases();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QByteArray"));
		for (int n = 0; n < list_size; n++) {
			QByteArray *ret_v_ = new QByteArray(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//boolean QTextCodec.canEncode(QChar ch);
KMETHOD QTextCodec_canEncode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCodec *  qp = RawPtr_to(QTextCodec *, sfp[0]);
	if (qp) {
		QChar  ch = *RawPtr_to(QChar *, sfp[1]);
		bool ret_v = qp->canEncode(ch);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QTextCodec.canEncode(String s);
KMETHOD QTextCodec_canEncode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCodec *  qp = RawPtr_to(QTextCodec *, sfp[0]);
	if (qp) {
		const QString s = String_to(const QString, sfp[1]);
		bool ret_v = qp->canEncode(s);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//QByteArray QTextCodec.fromUnicode(String str);
KMETHOD QTextCodec_fromUnicode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCodec *  qp = RawPtr_to(QTextCodec *, sfp[0]);
	if (qp) {
		const QString str = String_to(const QString, sfp[1]);
		QByteArray ret_v = qp->fromUnicode(str);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextDecoder QTextCodec.makeDecoder();
KMETHOD QTextCodec_makeDecoder(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCodec *  qp = RawPtr_to(QTextCodec *, sfp[0]);
	if (qp) {
		QTextDecoder* ret_v = qp->makeDecoder();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextDecoder*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QTextDecoder QTextCodec.makeDecoder(QTextCodecConversionFlags flags);
KMETHOD QTextCodec_makeDecoder(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCodec *  qp = RawPtr_to(QTextCodec *, sfp[0]);
	if (qp) {
		initFlag(flags, QTextCodec::ConversionFlags, sfp[1]);
		QTextDecoder* ret_v = qp->makeDecoder(flags);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextDecoder*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QTextEncoder QTextCodec.makeEncoder();
KMETHOD QTextCodec_makeEncoder(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCodec *  qp = RawPtr_to(QTextCodec *, sfp[0]);
	if (qp) {
		QTextEncoder* ret_v = qp->makeEncoder();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextEncoder*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QTextEncoder QTextCodec.makeEncoder(QTextCodecConversionFlags flags);
KMETHOD QTextCodec_makeEncoder(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCodec *  qp = RawPtr_to(QTextCodec *, sfp[0]);
	if (qp) {
		initFlag(flags, QTextCodec::ConversionFlags, sfp[1]);
		QTextEncoder* ret_v = qp->makeEncoder(flags);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextEncoder*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//@Virtual int QTextCodec.mibEnum();
KMETHOD QTextCodec_mibEnum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCodec *  qp = RawPtr_to(QTextCodec *, sfp[0]);
	if (qp) {
		int ret_v = qp->mibEnum();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QByteArray QTextCodec.name();
KMETHOD QTextCodec_name(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCodec *  qp = RawPtr_to(QTextCodec *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->name();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QTextCodec.toUnicode(QByteArray a);
KMETHOD QTextCodec_toUnicode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCodec *  qp = RawPtr_to(QTextCodec *, sfp[0]);
	if (qp) {
		const QByteArray  a = *RawPtr_to(const QByteArray *, sfp[1]);
		QString ret_v = qp->toUnicode(a);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QTextCodec.toUnicode(String chars);
KMETHOD QTextCodec_toUnicode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCodec *  qp = RawPtr_to(QTextCodec *, sfp[0]);
	if (qp) {
		const char*  chars = RawPtr_to(const char*, sfp[1]);
		QString ret_v = qp->toUnicode(chars);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//Array<QByteArray> QTextCodec.availableCodecs();
KMETHOD QTextCodec_availableCodecs(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QList<QByteArray> ret_v = QTextCodec::availableCodecs();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QByteArray"));
		for (int n = 0; n < list_size; n++) {
			QByteArray *ret_v_ = new QByteArray(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//Array<int> QTextCodec.availableMibs();
KMETHOD QTextCodec_availableMibs(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QList<int> ret_v = QTextCodec::availableMibs();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("int"));
		for (int n = 0; n < list_size; n++) {
			int *ret_v_ = new int(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QTextCodec QTextCodec.getCodecForCStrings();
KMETHOD QTextCodec_getCodecForCStrings(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QTextCodec* ret_v = QTextCodec::codecForCStrings();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextCodec*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextCodec QTextCodec.codecForHtml(QByteArray ba, QTextCodec defaultCodec);
KMETHOD QTextCodec_codecForHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QByteArray  ba = *RawPtr_to(const QByteArray *, sfp[1]);
		QTextCodec*  defaultCodec = RawPtr_to(QTextCodec*, sfp[2]);
		QTextCodec* ret_v = QTextCodec::codecForHtml(ba, defaultCodec);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextCodec*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QTextCodec QTextCodec.codecForHtml(QByteArray ba);
KMETHOD QTextCodec_codecForHtml(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QByteArray  ba = *RawPtr_to(const QByteArray *, sfp[1]);
		QTextCodec* ret_v = QTextCodec::codecForHtml(ba);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextCodec*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QTextCodec QTextCodec.getCodecForLocale();
KMETHOD QTextCodec_getCodecForLocale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QTextCodec* ret_v = QTextCodec::codecForLocale();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextCodec*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextCodec QTextCodec.codecForMib(int mib);
KMETHOD QTextCodec_codecForMib(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int mib = Int_to(int, sfp[1]);
		QTextCodec* ret_v = QTextCodec::codecForMib(mib);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextCodec*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextCodec QTextCodec.codecForName(QByteArray name);
KMETHOD QTextCodec_codecForName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QByteArray  name = *RawPtr_to(const QByteArray *, sfp[1]);
		QTextCodec* ret_v = QTextCodec::codecForName(name);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextCodec*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QTextCodec QTextCodec.codecForName(String name);
KMETHOD QTextCodec_codecForName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const char*  name = RawPtr_to(const char*, sfp[1]);
		QTextCodec* ret_v = QTextCodec::codecForName(name);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextCodec*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QTextCodec QTextCodec.getCodecForTr();
KMETHOD QTextCodec_getCodecForTr(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QTextCodec* ret_v = QTextCodec::codecForTr();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextCodec*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextCodec QTextCodec.codecForUtfText(QByteArray ba, QTextCodec defaultCodec);
KMETHOD QTextCodec_codecForUtfText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QByteArray  ba = *RawPtr_to(const QByteArray *, sfp[1]);
		QTextCodec*  defaultCodec = RawPtr_to(QTextCodec*, sfp[2]);
		QTextCodec* ret_v = QTextCodec::codecForUtfText(ba, defaultCodec);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextCodec*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QTextCodec QTextCodec.codecForUtfText(QByteArray ba);
KMETHOD QTextCodec_codecForUtfText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QByteArray  ba = *RawPtr_to(const QByteArray *, sfp[1]);
		QTextCodec* ret_v = QTextCodec::codecForUtfText(ba);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextCodec*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//void QTextCodec.setCodecForCStrings(QTextCodec codec);
KMETHOD QTextCodec_setCodecForCStrings(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QTextCodec*  codec = RawPtr_to(QTextCodec*, sfp[1]);
		QTextCodec::setCodecForCStrings(codec);
	}
	RETURNvoid_();
}

//void QTextCodec.setCodecForLocale(QTextCodec c);
KMETHOD QTextCodec_setCodecForLocale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QTextCodec*  c = RawPtr_to(QTextCodec*, sfp[1]);
		QTextCodec::setCodecForLocale(c);
	}
	RETURNvoid_();
}

//void QTextCodec.setCodecForTr(QTextCodec c);
KMETHOD QTextCodec_setCodecForTr(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QTextCodec*  c = RawPtr_to(QTextCodec*, sfp[1]);
		QTextCodec::setCodecForTr(c);
	}
	RETURNvoid_();
}

//Array<String> QTextCodec.parents();
KMETHOD QTextCodec_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCodec *qp = RawPtr_to(QTextCodec*, sfp[0]);
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

DummyQTextCodec::DummyQTextCodec()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextCodec::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextCodec::self = ptr;
}

bool DummyQTextCodec::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextCodec::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextCodec::event_map->bigin();
	if ((itr = DummyQTextCodec::event_map->find(str)) == DummyQTextCodec::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextCodec::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextCodec::slot_map->bigin();
	if ((itr = DummyQTextCodec::slot_map->find(str)) == DummyQTextCodec::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTextCodec::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTextCodec::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQTextCodec::connection(QObject *o)
{
	QTextCodec *p = dynamic_cast<QTextCodec*>(o);
	if (p != NULL) {
	}
}

KMETHOD QTextCodec_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextCodec *qp = RawPtr_to(KQTextCodec *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextCodec]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextCodec]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextCodec_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextCodec *qp = RawPtr_to(KQTextCodec *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextCodec]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextCodec]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextCodec_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextCodec *qp = (KQTextCodec *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextCodec_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQTextCodec *qp = (KQTextCodec *)p->rawptr;
//		KQTextCodec *qp = static_cast<KQTextCodec*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextCodec_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextCodec::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QTextCodecConstInt[] = {
	{"DefaultConversion", QTextCodec::DefaultConversion},
	{"ConvertInvalidToNull", QTextCodec::ConvertInvalidToNull},
	{"IgnoreHeader", QTextCodec::IgnoreHeader},
	{NULL, 0}
};

DEFAPI(void) constQTextCodec(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTextCodecConstInt);
}


DEFAPI(void) defQTextCodec(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextCodec";
	cdef->free = QTextCodec_free;
	cdef->reftrace = QTextCodec_reftrace;
	cdef->compareTo = QTextCodec_compareTo;
}

//## QTextCodecConversionFlags QTextCodecConversionFlags.new(int value);
KMETHOD QTextCodecConversionFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextCodec::ConversionFlag i = Int_to(QTextCodec::ConversionFlag, sfp[1]);
	QTextCodec::ConversionFlags *ret_v = new QTextCodec::ConversionFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QTextCodecConversionFlags QTextCodecConversionFlags.and(int mask);
KMETHOD QTextCodecConversionFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextCodec::ConversionFlags *qp = RawPtr_to(QTextCodec::ConversionFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QTextCodec::ConversionFlags ret = ((*qp) & i);
		QTextCodec::ConversionFlags *ret_ = new QTextCodec::ConversionFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextCodecConversionFlags QTextCodecConversionFlags.iand(QTextCodec::QTextCodecConversionFlags other);
KMETHOD QTextCodecConversionFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextCodec::ConversionFlags *qp = RawPtr_to(QTextCodec::ConversionFlags*, sfp[0]);
	if (qp != NULL) {
		QTextCodec::ConversionFlags *other = RawPtr_to(QTextCodec::ConversionFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextCodecConversionFlags QTextCodecConversionFlags.or(QTextCodecConversionFlags f);
KMETHOD QTextCodecConversionFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCodec::ConversionFlags *qp = RawPtr_to(QTextCodec::ConversionFlags*, sfp[0]);
	if (qp != NULL) {
		QTextCodec::ConversionFlags *f = RawPtr_to(QTextCodec::ConversionFlags*, sfp[1]);
		QTextCodec::ConversionFlags ret = ((*qp) | (*f));
		QTextCodec::ConversionFlags *ret_ = new QTextCodec::ConversionFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextCodecConversionFlags QTextCodecConversionFlags.ior(QTextCodec::QTextCodecConversionFlags other);
KMETHOD QTextCodecConversionFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextCodec::ConversionFlags *qp = RawPtr_to(QTextCodec::ConversionFlags*, sfp[0]);
	if (qp != NULL) {
		QTextCodec::ConversionFlags *other = RawPtr_to(QTextCodec::ConversionFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextCodecConversionFlags QTextCodecConversionFlags.xor(QTextCodecConversionFlags f);
KMETHOD QTextCodecConversionFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextCodec::ConversionFlags *qp = RawPtr_to(QTextCodec::ConversionFlags*, sfp[0]);
	if (qp != NULL) {
		QTextCodec::ConversionFlags *f = RawPtr_to(QTextCodec::ConversionFlags*, sfp[1]);
		QTextCodec::ConversionFlags ret = ((*qp) ^ (*f));
		QTextCodec::ConversionFlags *ret_ = new QTextCodec::ConversionFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextCodecConversionFlags QTextCodecConversionFlags.ixor(QTextCodec::QTextCodecConversionFlags other);
KMETHOD QTextCodecConversionFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextCodec::ConversionFlags *qp = RawPtr_to(QTextCodec::ConversionFlags*, sfp[0]);
	if (qp != NULL) {
		QTextCodec::ConversionFlags *other = RawPtr_to(QTextCodec::ConversionFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QTextCodecConversionFlags.testFlag(int flag);
KMETHOD QTextCodecConversionFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextCodec::ConversionFlags *qp = RawPtr_to(QTextCodec::ConversionFlags *, sfp[0]);
	if (qp != NULL) {
		QTextCodec::ConversionFlag flag = Int_to(QTextCodec::ConversionFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QTextCodecConversionFlags.value();
KMETHOD QTextCodecConversionFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextCodec::ConversionFlags *qp = RawPtr_to(QTextCodec::ConversionFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QTextCodecConversionFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QTextCodec::ConversionFlags *qp = (QTextCodec::ConversionFlags *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QTextCodecConversionFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QTextCodec::ConversionFlags *qp = (QTextCodec::ConversionFlags *)p->rawptr;
		(void)qp;
	}
}

static int QTextCodecConversionFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QTextCodec::ConversionFlags*)p1->rawptr);
//		int v2 = int(*(QTextCodec::ConversionFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QTextCodec::ConversionFlags v1 = *(QTextCodec::ConversionFlags*)p1->rawptr;
		QTextCodec::ConversionFlags v2 = *(QTextCodec::ConversionFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQTextCodecConversionFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextCodecConversionFlags";
	cdef->free = QTextCodecConversionFlags_free;
	cdef->reftrace = QTextCodecConversionFlags_reftrace;
	cdef->compareTo = QTextCodecConversionFlags_compareTo;
}

