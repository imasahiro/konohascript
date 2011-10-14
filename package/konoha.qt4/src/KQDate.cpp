//QDate QDate.new();
KMETHOD QDate_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDate *ret_v = new KQDate();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QDate QDate.new(int y, int m, int d);
KMETHOD QDate_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int y = Int_to(int, sfp[1]);
	int m = Int_to(int, sfp[2]);
	int d = Int_to(int, sfp[3]);
	KQDate *ret_v = new KQDate(y, m, d);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QDate QDate.addDays(int ndays);
KMETHOD QDate_addDays(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int ndays = Int_to(int, sfp[1]);
		QDate ret_v = qp->addDays(ndays);
		QDate *ret_v_ = new QDate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDate QDate.addMonths(int nmonths);
KMETHOD QDate_addMonths(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int nmonths = Int_to(int, sfp[1]);
		QDate ret_v = qp->addMonths(nmonths);
		QDate *ret_v_ = new QDate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDate QDate.addYears(int nyears);
KMETHOD QDate_addYears(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int nyears = Int_to(int, sfp[1]);
		QDate ret_v = qp->addYears(nyears);
		QDate *ret_v_ = new QDate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDate.day();
KMETHOD QDate_day(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->day();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QDate.dayOfWeek();
KMETHOD QDate_dayOfWeek(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->dayOfWeek();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QDate.dayOfYear();
KMETHOD QDate_dayOfYear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->dayOfYear();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QDate.daysInMonth();
KMETHOD QDate_daysInMonth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->daysInMonth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QDate.daysInYear();
KMETHOD QDate_daysInYear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->daysInYear();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QDate.daysTo(QDate d);
KMETHOD QDate_daysTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		const QDate  d = *RawPtr_to(const QDate *, sfp[1]);
		int ret_v = qp->daysTo(d);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QDate.getDate(int year, int month, int day);
KMETHOD QDate_getDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int* year = Int_to(int*, sfp[1]);
		int* month = Int_to(int*, sfp[2]);
		int* day = Int_to(int*, sfp[3]);
		qp->getDate(year, month, day);
	}
	RETURNvoid_();
}

////boolean QDate.isNull();
KMETHOD QDate_isNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isNull();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

////boolean QDate.isValid();
KMETHOD QDate_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QDate.month();
KMETHOD QDate_month(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->month();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QDate.setDate(int year, int month, int day);
KMETHOD QDate_setDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int year = Int_to(int, sfp[1]);
		int month = Int_to(int, sfp[2]);
		int day = Int_to(int, sfp[3]);
		bool ret_v = qp->setDate(year, month, day);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QDate.toJulianDay();
KMETHOD QDate_toJulianDay(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->toJulianDay();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QDate.toString(String fmt);
KMETHOD QDate_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		const QString format = String_to(const QString, sfp[1]);
		QString ret_v = qp->toString(format);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QDate.toString(int fmt);
KMETHOD QDate_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		Qt::DateFormat format = Int_to(Qt::DateFormat, sfp[1]);
		QString ret_v = qp->toString(format);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//int QDate.weekNumber(int yearNumber);
KMETHOD QDate_weekNumber(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int* yearNumber = Int_to(int*, sfp[1]);
		int ret_v = qp->weekNumber(yearNumber);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QDate.year();
KMETHOD QDate_year(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->year();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QDate QDate.currentDate();
KMETHOD QDate_currentDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		QDate ret_v = qp->currentDate();
		QDate *ret_v_ = new QDate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDate QDate.fromJulianDay(int jd);
KMETHOD QDate_fromJulianDay(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int jd = Int_to(int, sfp[1]);
		QDate ret_v = qp->fromJulianDay(jd);
		QDate *ret_v_ = new QDate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDate QDate.fromString(String str, int fmt);
KMETHOD QDate_fromString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		const QString string = String_to(const QString, sfp[1]);
		Qt::DateFormat format = Int_to(Qt::DateFormat, sfp[2]);
		QDate ret_v = qp->fromString(string, format);
		QDate *ret_v_ = new QDate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QDate QDate.fromString(String str, String fmt);
KMETHOD QDate_fromString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		const QString string = String_to(const QString, sfp[1]);
		const QString format = String_to(const QString, sfp[2]);
		QDate ret_v = qp->fromString(string, format);
		QDate *ret_v_ = new QDate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//boolean QDate.isLeapYear(int year);
KMETHOD QDate_isLeapYear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int year = Int_to(int, sfp[1]);
		bool ret_v = qp->isLeapYear(year);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
////boolean QDate.isValid(int year, int month, int day);
KMETHOD QDate_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int year = Int_to(int, sfp[1]);
		int month = Int_to(int, sfp[2]);
		int day = Int_to(int, sfp[3]);
		bool ret_v = qp->isValid(year, month, day);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//String QDate.longDayName(int weekday);
KMETHOD QDate_longDayName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int weekday = Int_to(int, sfp[1]);
		QString ret_v = qp->longDayName(weekday);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QDate.longDayName(int weekday, int type);
KMETHOD QDate_longDayName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int weekday = Int_to(int, sfp[1]);
		QDate::MonthNameType type = Int_to(QDate::MonthNameType, sfp[2]);
		QString ret_v = qp->longDayName(weekday, type);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//String QDate.longMonthName(int month);
KMETHOD QDate_longMonthName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int month = Int_to(int, sfp[1]);
		QString ret_v = qp->longMonthName(month);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QDate.longMonthName(int month, int type);
KMETHOD QDate_longMonthName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int month = Int_to(int, sfp[1]);
		QDate::MonthNameType type = Int_to(QDate::MonthNameType, sfp[2]);
		QString ret_v = qp->longMonthName(month, type);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//String QDate.shortDayName(int weekday);
KMETHOD QDate_shortDayName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int weekday = Int_to(int, sfp[1]);
		QString ret_v = qp->shortDayName(weekday);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QDate.shortDayName(int weekday, int type);
KMETHOD QDate_shortDayName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int weekday = Int_to(int, sfp[1]);
		QDate::MonthNameType type = Int_to(QDate::MonthNameType, sfp[2]);
		QString ret_v = qp->shortDayName(weekday, type);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//String QDate.shortMonthName(int month);
KMETHOD QDate_shortMonthName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int month = Int_to(int, sfp[1]);
		QString ret_v = qp->shortMonthName(month);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QDate.shortMonthName(int month, int type);
KMETHOD QDate_shortMonthName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDate *  qp = RawPtr_to(QDate *, sfp[0]);
	if (qp != NULL) {
		int month = Int_to(int, sfp[1]);
		QDate::MonthNameType type = Int_to(QDate::MonthNameType, sfp[2]);
		QString ret_v = qp->shortMonthName(month, type);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/

DummyQDate::DummyQDate()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQDate::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDate::self = ptr;
}

bool DummyQDate::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQDate::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDate::event_map->bigin();
	if ((itr = DummyQDate::event_map->find(str)) == DummyQDate::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDate::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDate::slot_map->bigin();
	if ((itr = DummyQDate::slot_map->find(str)) == DummyQDate::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQDate::connection(QObject *o)
{
	return;
}

KQDate::KQDate() : QDate()
{
	self = NULL;
	dummy = new DummyQDate();
	dummy->connection((QObject*)this);
}

KMETHOD QDate_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDate *qp = RawPtr_to(KQDate *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDate]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDate]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QDate_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDate *qp = RawPtr_to(KQDate *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDate]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDate]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDate_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDate *qp = (KQDate *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDate_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQDate *qp = (KQDate *)p->rawptr;
		(void)qp;
	}
}

static int QDate_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QDate*>(p1->rawptr) == *static_cast<QDate*>(p2->rawptr) ? 0 : 1);
}

void KQDate::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQDate(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDate";
	cdef->free = QDate_free;
	cdef->reftrace = QDate_reftrace;
	cdef->compareTo = QDate_compareTo;
}

static knh_IntData_t QDateConstInt[] = {
	{"DateFormat", QDate::DateFormat},
	{"StandaloneFormat", QDate::StandaloneFormat},
	{NULL, 0}
};

DEFAPI(void) constQDate(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QDateConstInt);
}

