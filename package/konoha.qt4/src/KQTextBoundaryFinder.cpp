//QTextBoundaryFinder QTextBoundaryFinder.new();
KMETHOD QTextBoundaryFinder_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextBoundaryFinder *ret_v = new KQTextBoundaryFinder();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTextBoundaryFinder QTextBoundaryFinder.new(QTextBoundaryFinder other);
KMETHOD QTextBoundaryFinder_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTextBoundaryFinder  other = *RawPtr_to(const QTextBoundaryFinder *, sfp[1]);
	KQTextBoundaryFinder *ret_v = new KQTextBoundaryFinder(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QTextBoundaryFinder QTextBoundaryFinder.new(int type, String str);
KMETHOD QTextBoundaryFinder_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBoundaryFinder::BoundaryType type = Int_to(QTextBoundaryFinder::BoundaryType, sfp[1]);
	const QString string = String_to(const QString, sfp[2]);
	KQTextBoundaryFinder *ret_v = new KQTextBoundaryFinder(type, string);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QTextBoundaryFinder QTextBoundaryFinder.new(int type, QChar chars, int length, String buffer, int bufferSize);
KMETHOD QTextBoundaryFinder_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBoundaryFinder::BoundaryType type = Int_to(QTextBoundaryFinder::BoundaryType, sfp[1]);
	const QChar*  chars = RawPtr_to(const QChar*, sfp[2]);
	int length = Int_to(int, sfp[3]);
	unsigned char*  buffer = RawPtr_to(unsigned char*, sfp[4]);
	int bufferSize = Int_to(int, sfp[5]);
	KQTextBoundaryFinder *ret_v = new KQTextBoundaryFinder(type, chars, length, buffer, bufferSize);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QTextBoundaryFinderBoundaryReasons QTextBoundaryFinder.boundaryReasons();
KMETHOD QTextBoundaryFinder_boundaryReasons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBoundaryFinder *  qp = RawPtr_to(QTextBoundaryFinder *, sfp[0]);
	if (qp) {
		QTextBoundaryFinder::BoundaryReasons ret_v = qp->boundaryReasons();
		QTextBoundaryFinder::BoundaryReasons *ret_v_ = new QTextBoundaryFinder::BoundaryReasons(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QTextBoundaryFinder.isAtBoundary();
KMETHOD QTextBoundaryFinder_isAtBoundary(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBoundaryFinder *  qp = RawPtr_to(QTextBoundaryFinder *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isAtBoundary();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTextBoundaryFinder.getPosition();
KMETHOD QTextBoundaryFinder_getPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBoundaryFinder *  qp = RawPtr_to(QTextBoundaryFinder *, sfp[0]);
	if (qp) {
		int ret_v = qp->position();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTextBoundaryFinder.setPosition(int position);
KMETHOD QTextBoundaryFinder_setPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBoundaryFinder *  qp = RawPtr_to(QTextBoundaryFinder *, sfp[0]);
	if (qp) {
		int position = Int_to(int, sfp[1]);
		qp->setPosition(position);
	}
	RETURNvoid_();
}

//String QTextBoundaryFinder.string();
KMETHOD QTextBoundaryFinder_string(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBoundaryFinder *  qp = RawPtr_to(QTextBoundaryFinder *, sfp[0]);
	if (qp) {
		QString ret_v = qp->string();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTextBoundaryFinder.toEnd();
KMETHOD QTextBoundaryFinder_toEnd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBoundaryFinder *  qp = RawPtr_to(QTextBoundaryFinder *, sfp[0]);
	if (qp) {
		qp->toEnd();
	}
	RETURNvoid_();
}

//int QTextBoundaryFinder.toNextBoundary();
KMETHOD QTextBoundaryFinder_toNextBoundary(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBoundaryFinder *  qp = RawPtr_to(QTextBoundaryFinder *, sfp[0]);
	if (qp) {
		int ret_v = qp->toNextBoundary();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextBoundaryFinder.toPreviousBoundary();
KMETHOD QTextBoundaryFinder_toPreviousBoundary(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBoundaryFinder *  qp = RawPtr_to(QTextBoundaryFinder *, sfp[0]);
	if (qp) {
		int ret_v = qp->toPreviousBoundary();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QTextBoundaryFinder.toStart();
KMETHOD QTextBoundaryFinder_toStart(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBoundaryFinder *  qp = RawPtr_to(QTextBoundaryFinder *, sfp[0]);
	if (qp) {
		qp->toStart();
	}
	RETURNvoid_();
}

//int QTextBoundaryFinder.type();
KMETHOD QTextBoundaryFinder_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBoundaryFinder *  qp = RawPtr_to(QTextBoundaryFinder *, sfp[0]);
	if (qp) {
		QTextBoundaryFinder::BoundaryType ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<String> QTextBoundaryFinder.parents();
KMETHOD QTextBoundaryFinder_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBoundaryFinder *qp = RawPtr_to(QTextBoundaryFinder*, sfp[0]);
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

DummyQTextBoundaryFinder::DummyQTextBoundaryFinder()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextBoundaryFinder::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextBoundaryFinder::self = ptr;
}

bool DummyQTextBoundaryFinder::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextBoundaryFinder::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextBoundaryFinder::event_map->bigin();
	if ((itr = DummyQTextBoundaryFinder::event_map->find(str)) == DummyQTextBoundaryFinder::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextBoundaryFinder::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextBoundaryFinder::slot_map->bigin();
	if ((itr = DummyQTextBoundaryFinder::slot_map->find(str)) == DummyQTextBoundaryFinder::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQTextBoundaryFinder::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQTextBoundaryFinder::connection(QObject *o)
{
	QTextBoundaryFinder *p = dynamic_cast<QTextBoundaryFinder*>(o);
	if (p != NULL) {
	}
}

KQTextBoundaryFinder::KQTextBoundaryFinder() : QTextBoundaryFinder()
{
	self = NULL;
	dummy = new DummyQTextBoundaryFinder();
}

KMETHOD QTextBoundaryFinder_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextBoundaryFinder *qp = RawPtr_to(KQTextBoundaryFinder *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextBoundaryFinder]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextBoundaryFinder]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextBoundaryFinder_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextBoundaryFinder *qp = RawPtr_to(KQTextBoundaryFinder *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextBoundaryFinder]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextBoundaryFinder]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextBoundaryFinder_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextBoundaryFinder *qp = (KQTextBoundaryFinder *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextBoundaryFinder_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQTextBoundaryFinder *qp = (KQTextBoundaryFinder *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextBoundaryFinder_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextBoundaryFinder::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QTextBoundaryFinderConstInt[] = {
	{"NotAtBoundary", QTextBoundaryFinder::NotAtBoundary},
	{"StartWord", QTextBoundaryFinder::StartWord},
	{"EndWord", QTextBoundaryFinder::EndWord},
	{"Grapheme", QTextBoundaryFinder::Grapheme},
	{"Word", QTextBoundaryFinder::Word},
	{"Line", QTextBoundaryFinder::Line},
	{"Sentence", QTextBoundaryFinder::Sentence},
	{NULL, 0}
};

DEFAPI(void) constQTextBoundaryFinder(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTextBoundaryFinderConstInt);
}


DEFAPI(void) defQTextBoundaryFinder(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextBoundaryFinder";
	cdef->free = QTextBoundaryFinder_free;
	cdef->reftrace = QTextBoundaryFinder_reftrace;
	cdef->compareTo = QTextBoundaryFinder_compareTo;
}

//## QTextBoundaryFinderBoundaryReasons QTextBoundaryFinderBoundaryReasons.new(int value);
KMETHOD QTextBoundaryFinderBoundaryReasons_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextBoundaryFinder::BoundaryReason i = Int_to(QTextBoundaryFinder::BoundaryReason, sfp[1]);
	QTextBoundaryFinder::BoundaryReasons *ret_v = new QTextBoundaryFinder::BoundaryReasons(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QTextBoundaryFinderBoundaryReasons QTextBoundaryFinderBoundaryReasons.and(int mask);
KMETHOD QTextBoundaryFinderBoundaryReasons_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextBoundaryFinder::BoundaryReasons *qp = RawPtr_to(QTextBoundaryFinder::BoundaryReasons*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QTextBoundaryFinder::BoundaryReasons ret = ((*qp) & i);
		QTextBoundaryFinder::BoundaryReasons *ret_ = new QTextBoundaryFinder::BoundaryReasons(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextBoundaryFinderBoundaryReasons QTextBoundaryFinderBoundaryReasons.iand(QTextBoundaryFinder::QTextBoundaryFinderBoundaryReasons other);
KMETHOD QTextBoundaryFinderBoundaryReasons_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextBoundaryFinder::BoundaryReasons *qp = RawPtr_to(QTextBoundaryFinder::BoundaryReasons*, sfp[0]);
	if (qp != NULL) {
		QTextBoundaryFinder::BoundaryReasons *other = RawPtr_to(QTextBoundaryFinder::BoundaryReasons *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextBoundaryFinderBoundaryReasons QTextBoundaryFinderBoundaryReasons.or(QTextBoundaryFinderBoundaryReasons f);
KMETHOD QTextBoundaryFinderBoundaryReasons_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBoundaryFinder::BoundaryReasons *qp = RawPtr_to(QTextBoundaryFinder::BoundaryReasons*, sfp[0]);
	if (qp != NULL) {
		QTextBoundaryFinder::BoundaryReasons *f = RawPtr_to(QTextBoundaryFinder::BoundaryReasons*, sfp[1]);
		QTextBoundaryFinder::BoundaryReasons ret = ((*qp) | (*f));
		QTextBoundaryFinder::BoundaryReasons *ret_ = new QTextBoundaryFinder::BoundaryReasons(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextBoundaryFinderBoundaryReasons QTextBoundaryFinderBoundaryReasons.ior(QTextBoundaryFinder::QTextBoundaryFinderBoundaryReasons other);
KMETHOD QTextBoundaryFinderBoundaryReasons_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextBoundaryFinder::BoundaryReasons *qp = RawPtr_to(QTextBoundaryFinder::BoundaryReasons*, sfp[0]);
	if (qp != NULL) {
		QTextBoundaryFinder::BoundaryReasons *other = RawPtr_to(QTextBoundaryFinder::BoundaryReasons *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextBoundaryFinderBoundaryReasons QTextBoundaryFinderBoundaryReasons.xor(QTextBoundaryFinderBoundaryReasons f);
KMETHOD QTextBoundaryFinderBoundaryReasons_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextBoundaryFinder::BoundaryReasons *qp = RawPtr_to(QTextBoundaryFinder::BoundaryReasons*, sfp[0]);
	if (qp != NULL) {
		QTextBoundaryFinder::BoundaryReasons *f = RawPtr_to(QTextBoundaryFinder::BoundaryReasons*, sfp[1]);
		QTextBoundaryFinder::BoundaryReasons ret = ((*qp) ^ (*f));
		QTextBoundaryFinder::BoundaryReasons *ret_ = new QTextBoundaryFinder::BoundaryReasons(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QTextBoundaryFinderBoundaryReasons QTextBoundaryFinderBoundaryReasons.ixor(QTextBoundaryFinder::QTextBoundaryFinderBoundaryReasons other);
KMETHOD QTextBoundaryFinderBoundaryReasons_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextBoundaryFinder::BoundaryReasons *qp = RawPtr_to(QTextBoundaryFinder::BoundaryReasons*, sfp[0]);
	if (qp != NULL) {
		QTextBoundaryFinder::BoundaryReasons *other = RawPtr_to(QTextBoundaryFinder::BoundaryReasons *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QTextBoundaryFinderBoundaryReasons.testFlag(int flag);
KMETHOD QTextBoundaryFinderBoundaryReasons_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextBoundaryFinder::BoundaryReasons *qp = RawPtr_to(QTextBoundaryFinder::BoundaryReasons *, sfp[0]);
	if (qp != NULL) {
		QTextBoundaryFinder::BoundaryReason flag = Int_to(QTextBoundaryFinder::BoundaryReason, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QTextBoundaryFinderBoundaryReasons.value();
KMETHOD QTextBoundaryFinderBoundaryReasons_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QTextBoundaryFinder::BoundaryReasons *qp = RawPtr_to(QTextBoundaryFinder::BoundaryReasons *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QTextBoundaryFinderBoundaryReasons_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QTextBoundaryFinder::BoundaryReasons *qp = (QTextBoundaryFinder::BoundaryReasons *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QTextBoundaryFinderBoundaryReasons_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QTextBoundaryFinder::BoundaryReasons *qp = (QTextBoundaryFinder::BoundaryReasons *)p->rawptr;
		(void)qp;
	}
}

static int QTextBoundaryFinderBoundaryReasons_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QTextBoundaryFinder::BoundaryReasons*)p1->rawptr);
//		int v2 = int(*(QTextBoundaryFinder::BoundaryReasons*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QTextBoundaryFinder::BoundaryReasons v1 = *(QTextBoundaryFinder::BoundaryReasons*)p1->rawptr;
		QTextBoundaryFinder::BoundaryReasons v2 = *(QTextBoundaryFinder::BoundaryReasons*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQTextBoundaryFinderBoundaryReasons(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextBoundaryFinderBoundaryReasons";
	cdef->free = QTextBoundaryFinderBoundaryReasons_free;
	cdef->reftrace = QTextBoundaryFinderBoundaryReasons_reftrace;
	cdef->compareTo = QTextBoundaryFinderBoundaryReasons_compareTo;
}

