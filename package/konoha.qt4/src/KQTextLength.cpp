//QTextLength QTextLength.new();
KMETHOD QTextLength_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextLength *ret_v = new KQTextLength();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QTextLength QTextLength.new(int type, float value);
KMETHOD QTextLength_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLength::Type type = Int_to(QTextLength::Type, sfp[1]);
	qreal value = Float_to(qreal, sfp[2]);
	KQTextLength *ret_v = new KQTextLength(type, value);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//float QTextLength.rawValue();
KMETHOD QTextLength_rawValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLength *  qp = RawPtr_to(QTextLength *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->rawValue();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QTextLength.type();
KMETHOD QTextLength_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLength *  qp = RawPtr_to(QTextLength *, sfp[0]);
	if (qp) {
		QTextLength::Type ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QTextLength.value(float maximumLength);
KMETHOD QTextLength_value(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLength *  qp = RawPtr_to(QTextLength *, sfp[0]);
	if (qp) {
		qreal maximumLength = Float_to(qreal, sfp[1]);
		qreal ret_v = qp->value(maximumLength);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//Array<String> QTextLength.parents();
KMETHOD QTextLength_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextLength *qp = RawPtr_to(QTextLength*, sfp[0]);
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

DummyQTextLength::DummyQTextLength()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextLength::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextLength::self = ptr;
}

bool DummyQTextLength::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQTextLength::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextLength::event_map->bigin();
	if ((itr = DummyQTextLength::event_map->find(str)) == DummyQTextLength::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextLength::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextLength::slot_map->bigin();
	if ((itr = DummyQTextLength::slot_map->find(str)) == DummyQTextLength::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTextLength::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTextLength::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQTextLength::connection(QObject *o)
{
	QTextLength *p = dynamic_cast<QTextLength*>(o);
	if (p != NULL) {
	}
}

KQTextLength::KQTextLength() : QTextLength()
{
	self = NULL;
	dummy = new DummyQTextLength();
}

KMETHOD QTextLength_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextLength *qp = RawPtr_to(KQTextLength *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextLength]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextLength]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextLength_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextLength *qp = RawPtr_to(KQTextLength *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextLength]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextLength]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextLength_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextLength *qp = (KQTextLength *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextLength_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQTextLength *qp = (KQTextLength *)p->rawptr;
//		KQTextLength *qp = static_cast<KQTextLength*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextLength_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QTextLength*>(p1->rawptr) == *static_cast<QTextLength*>(p2->rawptr) ? 0 : 1);
}

void KQTextLength::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QTextLengthConstInt[] = {
	{"VariableLength", QTextLength::VariableLength},
	{"FixedLength", QTextLength::FixedLength},
	{"PercentageLength", QTextLength::PercentageLength},
	{NULL, 0}
};

DEFAPI(void) constQTextLength(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTextLengthConstInt);
}


DEFAPI(void) defQTextLength(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextLength";
	cdef->free = QTextLength_free;
	cdef->reftrace = QTextLength_reftrace;
	cdef->compareTo = QTextLength_compareTo;
}


