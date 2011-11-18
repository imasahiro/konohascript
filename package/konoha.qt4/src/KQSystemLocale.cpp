//QSystemLocale QSystemLocale.new();
KMETHOD QSystemLocale_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSystemLocale *ret_v = new KQSystemLocale();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//@Virtual QLocale QSystemLocale.fallbackLocale();
KMETHOD QSystemLocale_fallbackLocale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemLocale *  qp = RawPtr_to(QSystemLocale *, sfp[0]);
	if (qp) {
		QLocale ret_v = qp->fallbackLocale();
		QLocale *ret_v_ = new QLocale(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QVariant QSystemLocale.query(int type, QVariant in);
KMETHOD QSystemLocale_query(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemLocale *  qp = RawPtr_to(QSystemLocale *, sfp[0]);
	if (qp) {
		QSystemLocale::QueryType type = Int_to(QSystemLocale::QueryType, sfp[1]);
		QVariant  in = *RawPtr_to(QVariant *, sfp[2]);
		QVariant ret_v = qp->query(type, in);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QSystemLocale.parents();
KMETHOD QSystemLocale_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemLocale *qp = RawPtr_to(QSystemLocale*, sfp[0]);
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

DummyQSystemLocale::DummyQSystemLocale()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQSystemLocale::~DummyQSystemLocale()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQSystemLocale::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSystemLocale::self = ptr;
}

bool DummyQSystemLocale::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQSystemLocale::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSystemLocale::event_map->bigin();
	if ((itr = DummyQSystemLocale::event_map->find(str)) == DummyQSystemLocale::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSystemLocale::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSystemLocale::slot_map->bigin();
	if ((itr = DummyQSystemLocale::slot_map->find(str)) == DummyQSystemLocale::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQSystemLocale::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQSystemLocale::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQSystemLocale::connection(QObject *o)
{
	QSystemLocale *p = dynamic_cast<QSystemLocale*>(o);
	if (p != NULL) {
	}
}

KQSystemLocale::KQSystemLocale() : QSystemLocale()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQSystemLocale();
}

KQSystemLocale::~KQSystemLocale()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QSystemLocale_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSystemLocale *qp = RawPtr_to(KQSystemLocale *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSystemLocale]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSystemLocale]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSystemLocale_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSystemLocale *qp = RawPtr_to(KQSystemLocale *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSystemLocale]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSystemLocale]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSystemLocale_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQSystemLocale *qp = (KQSystemLocale *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QSystemLocale*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QSystemLocale_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQSystemLocale *qp = (KQSystemLocale *)p->rawptr;
		KQSystemLocale *qp = static_cast<KQSystemLocale*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSystemLocale_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSystemLocale::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QSystemLocaleConstInt[] = {
	{"LanguageId", QSystemLocale::LanguageId},
	{"CountryId", QSystemLocale::CountryId},
	{"DecimalPoint", QSystemLocale::DecimalPoint},
	{"GroupSeparator", QSystemLocale::GroupSeparator},
	{"ZeroDigit", QSystemLocale::ZeroDigit},
	{"NegativeSign", QSystemLocale::NegativeSign},
	{"PositiveSign", QSystemLocale::PositiveSign},
	{"DateFormatLong", QSystemLocale::DateFormatLong},
	{"DateFormatShort", QSystemLocale::DateFormatShort},
	{"TimeFormatLong", QSystemLocale::TimeFormatLong},
	{"TimeFormatShort", QSystemLocale::TimeFormatShort},
	{"DayNameLong", QSystemLocale::DayNameLong},
	{"DayNameShort", QSystemLocale::DayNameShort},
	{"MonthNameLong", QSystemLocale::MonthNameLong},
	{"MonthNameShort", QSystemLocale::MonthNameShort},
	{"DateToStringLong", QSystemLocale::DateToStringLong},
	{"DateToStringShort", QSystemLocale::DateToStringShort},
	{"TimeToStringLong", QSystemLocale::TimeToStringLong},
	{"TimeToStringShort", QSystemLocale::TimeToStringShort},
	{"DateTimeFormatLong", QSystemLocale::DateTimeFormatLong},
	{"DateTimeFormatShort", QSystemLocale::DateTimeFormatShort},
	{"DateTimeToStringLong", QSystemLocale::DateTimeToStringLong},
	{"DateTimeToStringShort", QSystemLocale::DateTimeToStringShort},
	{"MeasurementSystem", QSystemLocale::MeasurementSystem},
	{"AMText", QSystemLocale::AMText},
	{"PMText", QSystemLocale::PMText},
	{NULL, 0}
};

DEFAPI(void) constQSystemLocale(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QSystemLocaleConstInt);
}


DEFAPI(void) defQSystemLocale(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSystemLocale";
	cdef->free = QSystemLocale_free;
	cdef->reftrace = QSystemLocale_reftrace;
	cdef->compareTo = QSystemLocale_compareTo;
}


