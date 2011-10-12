//QSystemLocale QSystemLocale.new();
KMETHOD QSystemLocale_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSystemLocale *ret_v = new KQSystemLocale();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//@Virtual QLocale QSystemLocale.fallbackLocale();
KMETHOD QSystemLocale_fallbackLocale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemLocale *  qp = RawPtr_to(QSystemLocale *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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


DummyQSystemLocale::DummyQSystemLocale()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
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
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSystemLocale::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSystemLocale::slot_map->bigin();
	if ((itr = DummyQSystemLocale::event_map->find(str)) == DummyQSystemLocale::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQSystemLocale::KQSystemLocale() : QSystemLocale()
{
	self = NULL;
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
		if (!qp->DummyQSystemLocale::addEvent(callback_func, str)) {
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
		if (!qp->DummyQSystemLocale::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSystemLocale]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSystemLocale_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSystemLocale *qp = (KQSystemLocale *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSystemLocale_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQSystemLocale *qp = (KQSystemLocale *)p->rawptr;
		(void)qp;
	}
}

static int QSystemLocale_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQSystemLocale(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSystemLocale";
	cdef->free = QSystemLocale_free;
	cdef->reftrace = QSystemLocale_reftrace;
	cdef->compareTo = QSystemLocale_compareTo;
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

