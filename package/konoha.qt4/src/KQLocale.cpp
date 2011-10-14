//QLocale QLocale.new();
KMETHOD QLocale_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLocale *ret_v = new KQLocale();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QLocale QLocale.new(String name);
KMETHOD QLocale_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString name = String_to(const QString, sfp[1]);
	KQLocale *ret_v = new KQLocale(name);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QLocale QLocale.new(int language, int country);
KMETHOD QLocale_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale::Language language = Int_to(QLocale::Language, sfp[1]);
	QLocale::Country country = Int_to(QLocale::Country, sfp[2]);
	KQLocale *ret_v = new KQLocale(language, country);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QLocale QLocale.new(QLocale other);
KMETHOD QLocale_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QLocale  other = *RawPtr_to(const QLocale *, sfp[1]);
	KQLocale *ret_v = new KQLocale(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//String QLocale.amText();
KMETHOD QLocale_amText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->amText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QLocale.country();
KMETHOD QLocale_country(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QLocale::Country ret_v = qp->country();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QLocale.dateFormat(int fmt);
KMETHOD QLocale_dateFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QLocale::FormatType format = Int_to(QLocale::FormatType, sfp[1]);
		QString ret_v = qp->dateFormat(format);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QLocale.dateTimeFormat(int fmt);
KMETHOD QLocale_dateTimeFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QLocale::FormatType format = Int_to(QLocale::FormatType, sfp[1]);
		QString ret_v = qp->dateTimeFormat(format);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QLocale.dayName(int day, int type);
KMETHOD QLocale_dayName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		int day = Int_to(int, sfp[1]);
		QLocale::FormatType type = Int_to(QLocale::FormatType, sfp[2]);
		QString ret_v = qp->dayName(day, type);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QChar QLocale.decimalPoint();
KMETHOD QLocale_decimalPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QChar ret_v = qp->decimalPoint();
		QChar *ret_v_ = new QChar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QChar QLocale.exponential();
KMETHOD QLocale_exponential(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QChar ret_v = qp->exponential();
		QChar *ret_v_ = new QChar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QChar QLocale.groupSeparator();
KMETHOD QLocale_groupSeparator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QChar ret_v = qp->groupSeparator();
		QChar *ret_v_ = new QChar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QLocale.language();
KMETHOD QLocale_language(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QLocale::Language ret_v = qp->language();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QLocale.measurementSystem();
KMETHOD QLocale_measurementSystem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QLocale::MeasurementSystem ret_v = qp->measurementSystem();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QLocale.monthName(int month, int type);
KMETHOD QLocale_monthName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		int month = Int_to(int, sfp[1]);
		QLocale::FormatType type = Int_to(QLocale::FormatType, sfp[2]);
		QString ret_v = qp->monthName(month, type);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QLocale.name();
KMETHOD QLocale_name(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->name();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QChar QLocale.negativeSign();
KMETHOD QLocale_negativeSign(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QChar ret_v = qp->negativeSign();
		QChar *ret_v_ = new QChar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QLocale.getNumberOptions();
KMETHOD QLocale_getNumberOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QLocale::NumberOptions ret_v = qp->numberOptions();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QChar QLocale.percent();
KMETHOD QLocale_percent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QChar ret_v = qp->percent();
		QChar *ret_v_ = new QChar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QLocale.pmText();
KMETHOD QLocale_pmText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->pmText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QChar QLocale.positiveSign();
KMETHOD QLocale_positiveSign(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QChar ret_v = qp->positiveSign();
		QChar *ret_v_ = new QChar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QLocale.setNumberOptions(int options);
KMETHOD QLocale_setNumberOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QLocale::NumberOptions options = Int_to(QLocale::NumberOptions, sfp[1]);
		qp->setNumberOptions(options);
	}
	RETURNvoid_();
}

//String QLocale.standaloneDayName(int day, int type);
KMETHOD QLocale_standaloneDayName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		int day = Int_to(int, sfp[1]);
		QLocale::FormatType type = Int_to(QLocale::FormatType, sfp[2]);
		QString ret_v = qp->standaloneDayName(day, type);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QLocale.standaloneMonthName(int month, int type);
KMETHOD QLocale_standaloneMonthName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		int month = Int_to(int, sfp[1]);
		QLocale::FormatType type = Int_to(QLocale::FormatType, sfp[2]);
		QString ret_v = qp->standaloneMonthName(month, type);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QLocale.textDirection();
KMETHOD QLocale_textDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		Qt::LayoutDirection ret_v = qp->textDirection();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QLocale.timeFormat(int fmt);
KMETHOD QLocale_timeFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QLocale::FormatType format = Int_to(QLocale::FormatType, sfp[1]);
		QString ret_v = qp->timeFormat(format);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDate QLocale.toDate(String str, int fmt);
KMETHOD QLocale_toDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QString string = String_to(const QString, sfp[1]);
		QLocale::FormatType format = Int_to(QLocale::FormatType, sfp[2]);
		QDate ret_v = qp->toDate(string, format);
		QDate *ret_v_ = new QDate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QDate QLocale.toDate(String str, String fmt);
KMETHOD QLocale_toDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QString string = String_to(const QString, sfp[1]);
		const QString format = String_to(const QString, sfp[2]);
		QDate ret_v = qp->toDate(string, format);
		QDate *ret_v_ = new QDate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QDateTime QLocale.toDateTime(String str, int fmt);
KMETHOD QLocale_toDateTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QString string = String_to(const QString, sfp[1]);
		QLocale::FormatType format = Int_to(QLocale::FormatType, sfp[2]);
		QDateTime ret_v = qp->toDateTime(string, format);
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QDateTime QLocale.toDateTime(String str, String fmt);
KMETHOD QLocale_toDateTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QString string = String_to(const QString, sfp[1]);
		const QString format = String_to(const QString, sfp[2]);
		QDateTime ret_v = qp->toDateTime(string, format);
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//double QLocale.toDouble(String s, boolean ok);
KMETHOD QLocale_toDouble(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QString s = String_to(const QString, sfp[1]);
		bool* ok = Boolean_to(bool*, sfp[2]);
		double ret_v = qp->toDouble(s, ok);
		double *ret_v_ = new double(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QLocale.toFloat(String s, boolean ok);
KMETHOD QLocale_toFloat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QString s = String_to(const QString, sfp[1]);
		bool* ok = Boolean_to(bool*, sfp[2]);
		float ret_v = qp->toFloat(s, ok);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QLocale.toInt(String s, boolean ok, int base);
KMETHOD QLocale_toInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QString s = String_to(const QString, sfp[1]);
		bool* ok = Boolean_to(bool*, sfp[2]);
		int base = Int_to(int, sfp[3]);
		int ret_v = qp->toInt(s, ok, base);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QLocale.toLongLong(String s, boolean ok, int base);
KMETHOD QLocale_toLongLong(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QString s = String_to(const QString, sfp[1]);
		bool* ok = Boolean_to(bool*, sfp[2]);
		int base = Int_to(int, sfp[3]);
		qlonglong ret_v = qp->toLongLong(s, ok, base);
		qlonglong *ret_v_ = new qlonglong(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//short QLocale.toShort(String s, boolean ok, int base);
KMETHOD QLocale_toShort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QString s = String_to(const QString, sfp[1]);
		bool* ok = Boolean_to(bool*, sfp[2]);
		int base = Int_to(int, sfp[3]);
		short ret_v = qp->toShort(s, ok, base);
		short *ret_v_ = new short(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QLocale.toString(int i);
KMETHOD QLocale_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		qlonglong  i = *RawPtr_to(qlonglong *, sfp[1]);
		QString ret_v = qp->toString(i);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//String QLocale.toString(QDate date, String fmt);
KMETHOD QLocale_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QDate  date = *RawPtr_to(const QDate *, sfp[1]);
		const QString format = String_to(const QString, sfp[2]);
		QString ret_v = qp->toString(date, format);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//String QLocale.toString(QDate date, int fmt);
KMETHOD QLocale_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QDate  date = *RawPtr_to(const QDate *, sfp[1]);
		QLocale::FormatType format = Int_to(QLocale::FormatType, sfp[2]);
		QString ret_v = qp->toString(date, format);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//String QLocale.toString(QTime time, String fmt);
KMETHOD QLocale_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QTime  time = *RawPtr_to(const QTime *, sfp[1]);
		const QString format = String_to(const QString, sfp[2]);
		QString ret_v = qp->toString(time, format);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//String QLocale.toString(QTime time, int fmt);
KMETHOD QLocale_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QTime  time = *RawPtr_to(const QTime *, sfp[1]);
		QLocale::FormatType format = Int_to(QLocale::FormatType, sfp[2]);
		QString ret_v = qp->toString(time, format);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//String QLocale.toString(QDateTime dateTime, int fmt);
KMETHOD QLocale_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QDateTime  dateTime = *RawPtr_to(const QDateTime *, sfp[1]);
		QLocale::FormatType format = Int_to(QLocale::FormatType, sfp[2]);
		QString ret_v = qp->toString(dateTime, format);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//String QLocale.toString(QDateTime dateTime, String fmt);
KMETHOD QLocale_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QDateTime  dateTime = *RawPtr_to(const QDateTime *, sfp[1]);
		const QString format = String_to(const QString, sfp[2]);
		QString ret_v = qp->toString(dateTime, format);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//String QLocale.toString(int i);
KMETHOD QLocale_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		qulonglong  i = *RawPtr_to(qulonglong *, sfp[1]);
		QString ret_v = qp->toString(i);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//String QLocale.toString(double i, String f, int prec);
KMETHOD QLocale_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		double  i = *RawPtr_to(double *, sfp[1]);
		char  f = *RawPtr_to(char *, sfp[2]);
		int prec = Int_to(int, sfp[3]);
		QString ret_v = qp->toString(i, f, prec);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//String QLocale.toString(short i);
KMETHOD QLocale_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		short  i = *RawPtr_to(short *, sfp[1]);
		QString ret_v = qp->toString(i);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//String QLocale.toString(int i);
KMETHOD QLocale_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		ushort  i = *RawPtr_to(ushort *, sfp[1]);
		QString ret_v = qp->toString(i);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//String QLocale.toString(int i);
KMETHOD QLocale_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QString ret_v = qp->toString(i);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//String QLocale.toString(int i);
KMETHOD QLocale_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		uint  i = *RawPtr_to(uint *, sfp[1]);
		QString ret_v = qp->toString(i);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//String QLocale.toString(float i, String f, int prec);
KMETHOD QLocale_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		float i = Float_to(float, sfp[1]);
		char  f = *RawPtr_to(char *, sfp[2]);
		int prec = Int_to(int, sfp[3]);
		QString ret_v = qp->toString(i, f, prec);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QTime QLocale.toTime(String str, int fmt);
KMETHOD QLocale_toTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QString string = String_to(const QString, sfp[1]);
		QLocale::FormatType format = Int_to(QLocale::FormatType, sfp[2]);
		QTime ret_v = qp->toTime(string, format);
		QTime *ret_v_ = new QTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QTime QLocale.toTime(String str, String fmt);
KMETHOD QLocale_toTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QString string = String_to(const QString, sfp[1]);
		const QString format = String_to(const QString, sfp[2]);
		QTime ret_v = qp->toTime(string, format);
		QTime *ret_v_ = new QTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//int QLocale.toUInt(String s, boolean ok, int base);
KMETHOD QLocale_toUInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QString s = String_to(const QString, sfp[1]);
		bool* ok = Boolean_to(bool*, sfp[2]);
		int base = Int_to(int, sfp[3]);
		uint ret_v = qp->toUInt(s, ok, base);
		uint *ret_v_ = new uint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QLocale.toULongLong(String s, boolean ok, int base);
KMETHOD QLocale_toULongLong(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QString s = String_to(const QString, sfp[1]);
		bool* ok = Boolean_to(bool*, sfp[2]);
		int base = Int_to(int, sfp[3]);
		qlonglong ret_v = qp->toULongLong(s, ok, base);
		qlonglong *ret_v_ = new qlonglong(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QLocale.toUShort(String s, boolean ok, int base);
KMETHOD QLocale_toUShort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QString s = String_to(const QString, sfp[1]);
		bool* ok = Boolean_to(bool*, sfp[2]);
		int base = Int_to(int, sfp[3]);
		ushort ret_v = qp->toUShort(s, ok, base);
		ushort *ret_v_ = new ushort(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QChar QLocale.zeroDigit();
KMETHOD QLocale_zeroDigit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QChar ret_v = qp->zeroDigit();
		QChar *ret_v_ = new QChar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QLocale QLocale.c();
KMETHOD QLocale_c(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QLocale ret_v = qp->c();
		QLocale *ret_v_ = new QLocale(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<int> QLocale.countriesForLanguage(int language);
KMETHOD QLocale_countriesForLanguage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QLocale::Language language = Int_to(QLocale::Language, sfp[1]);
		QList<QLocale::Country>ret_v = qp->countriesForLanguage(language);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QLocale::Country"));
		for (int n = 0; n < list_size; n++) {
			QLocale::Country *ret_v_ = new QLocale::Country(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//String QLocale.countryToString(int country);
KMETHOD QLocale_countryToString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QLocale::Country country = Int_to(QLocale::Country, sfp[1]);
		QString ret_v = qp->countryToString(country);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QLocale.languageToString(int language);
KMETHOD QLocale_languageToString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QLocale::Language language = Int_to(QLocale::Language, sfp[1]);
		QString ret_v = qp->languageToString(language);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QLocale.setDefault(QLocale locale);
KMETHOD QLocale_setDefault(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		const QLocale  locale = *RawPtr_to(const QLocale *, sfp[1]);
		qp->setDefault(locale);
	}
	RETURNvoid_();
}

//QLocale QLocale.system();
KMETHOD QLocale_system(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLocale *  qp = RawPtr_to(QLocale *, sfp[0]);
	if (qp != NULL) {
		QLocale ret_v = qp->system();
		QLocale *ret_v_ = new QLocale(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQLocale::DummyQLocale()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQLocale::setSelf(knh_RawPtr_t *ptr)
{
	DummyQLocale::self = ptr;
}

bool DummyQLocale::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQLocale::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLocale::event_map->bigin();
	if ((itr = DummyQLocale::event_map->find(str)) == DummyQLocale::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQLocale::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLocale::slot_map->bigin();
	if ((itr = DummyQLocale::slot_map->find(str)) == DummyQLocale::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQLocale::connection(QObject *o)
{
	return;
}

KQLocale::KQLocale() : QLocale()
{
	self = NULL;
	dummy = new DummyQLocale();
	dummy->connection((QObject*)this);
}

KMETHOD QLocale_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLocale *qp = RawPtr_to(KQLocale *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QLocale]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLocale]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QLocale_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLocale *qp = RawPtr_to(KQLocale *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QLocale]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLocale]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QLocale_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQLocale *qp = (KQLocale *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QLocale_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQLocale *qp = (KQLocale *)p->rawptr;
		(void)qp;
	}
}

static int QLocale_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QLocale*>(p1->rawptr) == *static_cast<QLocale*>(p2->rawptr) ? 0 : 1);
}

void KQLocale::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQLocale(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QLocale";
	cdef->free = QLocale_free;
	cdef->reftrace = QLocale_reftrace;
	cdef->compareTo = QLocale_compareTo;
}

static knh_IntData_t QLocaleConstInt[] = {
	{"AnyCountry", QLocale::AnyCountry},
	{"Afghanistan", QLocale::Afghanistan},
	{"Albania", QLocale::Albania},
	{"Algeria", QLocale::Algeria},
	{"AmericanSamoa", QLocale::AmericanSamoa},
	{"Andorra", QLocale::Andorra},
	{"Angola", QLocale::Angola},
	{"Anguilla", QLocale::Anguilla},
	{"Antarctica", QLocale::Antarctica},
	{"AntiguaAndBarbuda", QLocale::AntiguaAndBarbuda},
	{"Argentina", QLocale::Argentina},
	{"Armenia", QLocale::Armenia},
	{"Aruba", QLocale::Aruba},
	{"Australia", QLocale::Australia},
	{"Austria", QLocale::Austria},
	{"Azerbaijan", QLocale::Azerbaijan},
	{"Bahamas", QLocale::Bahamas},
	{"Bahrain", QLocale::Bahrain},
	{"Bangladesh", QLocale::Bangladesh},
	{"Barbados", QLocale::Barbados},
	{"Belarus", QLocale::Belarus},
	{"Belgium", QLocale::Belgium},
	{"Belize", QLocale::Belize},
	{"Benin", QLocale::Benin},
	{"Bermuda", QLocale::Bermuda},
	{"Bhutan", QLocale::Bhutan},
	{"Bolivia", QLocale::Bolivia},
	{"BosniaAndHerzegowina", QLocale::BosniaAndHerzegowina},
	{"Botswana", QLocale::Botswana},
	{"BouvetIsland", QLocale::BouvetIsland},
	{"Brazil", QLocale::Brazil},
	{"BritishIndianOceanTerritory", QLocale::BritishIndianOceanTerritory},
	{"BruneiDarussalam", QLocale::BruneiDarussalam},
	{"Bulgaria", QLocale::Bulgaria},
	{"BurkinaFaso", QLocale::BurkinaFaso},
	{"Burundi", QLocale::Burundi},
	{"Cambodia", QLocale::Cambodia},
	{"Cameroon", QLocale::Cameroon},
	{"Canada", QLocale::Canada},
	{"CapeVerde", QLocale::CapeVerde},
	{"CaymanIslands", QLocale::CaymanIslands},
	{"CentralAfricanRepublic", QLocale::CentralAfricanRepublic},
	{"Chad", QLocale::Chad},
	{"Chile", QLocale::Chile},
	{"China", QLocale::China},
	{"ChristmasIsland", QLocale::ChristmasIsland},
	{"CocosIslands", QLocale::CocosIslands},
	{"Colombia", QLocale::Colombia},
	{"Comoros", QLocale::Comoros},
	{"DemocraticRepublicOfCongo", QLocale::DemocraticRepublicOfCongo},
	{"PeoplesRepublicOfCongo", QLocale::PeoplesRepublicOfCongo},
	{"CookIslands", QLocale::CookIslands},
	{"CostaRica", QLocale::CostaRica},
	{"IvoryCoast", QLocale::IvoryCoast},
	{"Croatia", QLocale::Croatia},
	{"Cuba", QLocale::Cuba},
	{"Cyprus", QLocale::Cyprus},
	{"CzechRepublic", QLocale::CzechRepublic},
	{"Denmark", QLocale::Denmark},
	{"Djibouti", QLocale::Djibouti},
	{"Dominica", QLocale::Dominica},
	{"DominicanRepublic", QLocale::DominicanRepublic},
	{"EastTimor", QLocale::EastTimor},
	{"Ecuador", QLocale::Ecuador},
	{"Egypt", QLocale::Egypt},
	{"ElSalvador", QLocale::ElSalvador},
	{"EquatorialGuinea", QLocale::EquatorialGuinea},
	{"Eritrea", QLocale::Eritrea},
	{"Estonia", QLocale::Estonia},
	{"Ethiopia", QLocale::Ethiopia},
	{"FalklandIslands", QLocale::FalklandIslands},
	{"FaroeIslands", QLocale::FaroeIslands},
	{"FijiCountry", QLocale::FijiCountry},
	{"Finland", QLocale::Finland},
	{"France", QLocale::France},
	{"MetropolitanFrance", QLocale::MetropolitanFrance},
	{"FrenchGuiana", QLocale::FrenchGuiana},
	{"FrenchPolynesia", QLocale::FrenchPolynesia},
	{"FrenchSouthernTerritories", QLocale::FrenchSouthernTerritories},
	{"Gabon", QLocale::Gabon},
	{"Gambia", QLocale::Gambia},
	{"Georgia", QLocale::Georgia},
	{"Germany", QLocale::Germany},
	{"Ghana", QLocale::Ghana},
	{"Gibraltar", QLocale::Gibraltar},
	{"Greece", QLocale::Greece},
	{"Greenland", QLocale::Greenland},
	{"Grenada", QLocale::Grenada},
	{"Guadeloupe", QLocale::Guadeloupe},
	{"Guam", QLocale::Guam},
	{"Guatemala", QLocale::Guatemala},
	{"Guinea", QLocale::Guinea},
	{"GuineaBissau", QLocale::GuineaBissau},
	{"Guyana", QLocale::Guyana},
	{"Haiti", QLocale::Haiti},
	{"HeardAndMcDonaldIslands", QLocale::HeardAndMcDonaldIslands},
	{"Honduras", QLocale::Honduras},
	{"HongKong", QLocale::HongKong},
	{"Hungary", QLocale::Hungary},
	{"Iceland", QLocale::Iceland},
	{"India", QLocale::India},
	{"Indonesia", QLocale::Indonesia},
	{"Iran", QLocale::Iran},
	{"Iraq", QLocale::Iraq},
	{"Ireland", QLocale::Ireland},
	{"Israel", QLocale::Israel},
	{"Italy", QLocale::Italy},
	{"Jamaica", QLocale::Jamaica},
	{"Japan", QLocale::Japan},
	{"Jordan", QLocale::Jordan},
	{"Kazakhstan", QLocale::Kazakhstan},
	{"Kenya", QLocale::Kenya},
	{"Kiribati", QLocale::Kiribati},
	{"DemocraticRepublicOfKorea", QLocale::DemocraticRepublicOfKorea},
	{"RepublicOfKorea", QLocale::RepublicOfKorea},
	{"Kuwait", QLocale::Kuwait},
	{"Kyrgyzstan", QLocale::Kyrgyzstan},
	{"Lao", QLocale::Lao},
	{"Latvia", QLocale::Latvia},
	{"Lebanon", QLocale::Lebanon},
	{"Lesotho", QLocale::Lesotho},
	{"Liberia", QLocale::Liberia},
	{"LibyanArabJamahiriya", QLocale::LibyanArabJamahiriya},
	{"Liechtenstein", QLocale::Liechtenstein},
	{"Lithuania", QLocale::Lithuania},
	{"Luxembourg", QLocale::Luxembourg},
	{"Macau", QLocale::Macau},
	{"Macedonia", QLocale::Macedonia},
	{"Madagascar", QLocale::Madagascar},
	{"Malawi", QLocale::Malawi},
	{"Malaysia", QLocale::Malaysia},
	{"Maldives", QLocale::Maldives},
	{"Mali", QLocale::Mali},
	{"Malta", QLocale::Malta},
	{"MarshallIslands", QLocale::MarshallIslands},
	{"Martinique", QLocale::Martinique},
	{"Mauritania", QLocale::Mauritania},
	{"Mauritius", QLocale::Mauritius},
	{"Mayotte", QLocale::Mayotte},
	{"Mexico", QLocale::Mexico},
	{"Micronesia", QLocale::Micronesia},
	{"Moldova", QLocale::Moldova},
	{"Monaco", QLocale::Monaco},
	{"Mongolia", QLocale::Mongolia},
	{"Montserrat", QLocale::Montserrat},
	{"Morocco", QLocale::Morocco},
	{"Mozambique", QLocale::Mozambique},
	{"Myanmar", QLocale::Myanmar},
	{"Namibia", QLocale::Namibia},
	{"NauruCountry", QLocale::NauruCountry},
	{"Nepal", QLocale::Nepal},
	{"Netherlands", QLocale::Netherlands},
	{"NetherlandsAntilles", QLocale::NetherlandsAntilles},
	{"NewCaledonia", QLocale::NewCaledonia},
	{"NewZealand", QLocale::NewZealand},
	{"Nicaragua", QLocale::Nicaragua},
	{"Niger", QLocale::Niger},
	{"Nigeria", QLocale::Nigeria},
	{"Niue", QLocale::Niue},
	{"NorfolkIsland", QLocale::NorfolkIsland},
	{"NorthernMarianaIslands", QLocale::NorthernMarianaIslands},
	{"Norway", QLocale::Norway},
	{"Oman", QLocale::Oman},
	{"Pakistan", QLocale::Pakistan},
	{"Palau", QLocale::Palau},
	{"PalestinianTerritory", QLocale::PalestinianTerritory},
	{"Panama", QLocale::Panama},
	{"PapuaNewGuinea", QLocale::PapuaNewGuinea},
	{"Paraguay", QLocale::Paraguay},
	{"Peru", QLocale::Peru},
	{"Philippines", QLocale::Philippines},
	{"Pitcairn", QLocale::Pitcairn},
	{"Poland", QLocale::Poland},
	{"Portugal", QLocale::Portugal},
	{"PuertoRico", QLocale::PuertoRico},
	{"Qatar", QLocale::Qatar},
	{"Reunion", QLocale::Reunion},
	{"Romania", QLocale::Romania},
	{"RussianFederation", QLocale::RussianFederation},
	{"Rwanda", QLocale::Rwanda},
	{"SaintKittsAndNevis", QLocale::SaintKittsAndNevis},
	{"StLucia", QLocale::StLucia},
	{"StVincentAndTheGrenadines", QLocale::StVincentAndTheGrenadines},
	{"Samoa", QLocale::Samoa},
	{"SanMarino", QLocale::SanMarino},
	{"SaoTomeAndPrincipe", QLocale::SaoTomeAndPrincipe},
	{"SaudiArabia", QLocale::SaudiArabia},
	{"Senegal", QLocale::Senegal},
	{"SerbiaAndMontenegro", QLocale::SerbiaAndMontenegro},
	{"Seychelles", QLocale::Seychelles},
	{"SierraLeone", QLocale::SierraLeone},
	{"Singapore", QLocale::Singapore},
	{"Slovakia", QLocale::Slovakia},
	{"Slovenia", QLocale::Slovenia},
	{"SolomonIslands", QLocale::SolomonIslands},
	{"Somalia", QLocale::Somalia},
	{"SouthAfrica", QLocale::SouthAfrica},
	{"SouthGeorgiaAndTheSouthSandwichIslands", QLocale::SouthGeorgiaAndTheSouthSandwichIslands},
	{"Spain", QLocale::Spain},
	{"SriLanka", QLocale::SriLanka},
	{"StHelena", QLocale::StHelena},
	{"StPierreAndMiquelon", QLocale::StPierreAndMiquelon},
	{"Sudan", QLocale::Sudan},
	{"Suriname", QLocale::Suriname},
	{"SvalbardAndJanMayenIslands", QLocale::SvalbardAndJanMayenIslands},
	{"Swaziland", QLocale::Swaziland},
	{"Sweden", QLocale::Sweden},
	{"Switzerland", QLocale::Switzerland},
	{"SyrianArabRepublic", QLocale::SyrianArabRepublic},
	{"Taiwan", QLocale::Taiwan},
	{"Tajikistan", QLocale::Tajikistan},
	{"Tanzania", QLocale::Tanzania},
	{"Thailand", QLocale::Thailand},
	{"Togo", QLocale::Togo},
	{"Tokelau", QLocale::Tokelau},
	{"TongaCountry", QLocale::TongaCountry},
	{"TrinidadAndTobago", QLocale::TrinidadAndTobago},
	{"Tunisia", QLocale::Tunisia},
	{"Turkey", QLocale::Turkey},
	{"Turkmenistan", QLocale::Turkmenistan},
	{"TurksAndCaicosIslands", QLocale::TurksAndCaicosIslands},
	{"Tuvalu", QLocale::Tuvalu},
	{"Uganda", QLocale::Uganda},
	{"Ukraine", QLocale::Ukraine},
	{"UnitedArabEmirates", QLocale::UnitedArabEmirates},
	{"UnitedKingdom", QLocale::UnitedKingdom},
	{"UnitedStates", QLocale::UnitedStates},
	{"UnitedStatesMinorOutlyingIslands", QLocale::UnitedStatesMinorOutlyingIslands},
	{"Uruguay", QLocale::Uruguay},
	{"Uzbekistan", QLocale::Uzbekistan},
	{"Vanuatu", QLocale::Vanuatu},
	{"VaticanCityState", QLocale::VaticanCityState},
	{"Venezuela", QLocale::Venezuela},
	{"VietNam", QLocale::VietNam},
	{"BritishVirginIslands", QLocale::BritishVirginIslands},
	{"USVirginIslands", QLocale::USVirginIslands},
	{"WallisAndFutunaIslands", QLocale::WallisAndFutunaIslands},
	{"WesternSahara", QLocale::WesternSahara},
	{"Yemen", QLocale::Yemen},
	{"Yugoslavia", QLocale::Yugoslavia},
	{"Zambia", QLocale::Zambia},
	{"Zimbabwe", QLocale::Zimbabwe},
	{"SerbiaAndMontenegro", QLocale::SerbiaAndMontenegro},
	{"Montenegro", QLocale::Montenegro},
	{"Serbia", QLocale::Serbia},
	{"SaintBarthelemy", QLocale::SaintBarthelemy},
	{"SaintMartin", QLocale::SaintMartin},
	{"LatinAmericaAndTheCaribbean", QLocale::LatinAmericaAndTheCaribbean},
	{"LongFormat", QLocale::LongFormat},
	{"ShortFormat", QLocale::ShortFormat},
	{"NarrowFormat", QLocale::NarrowFormat},
	{"C", QLocale::C},
	{"Abkhazian", QLocale::Abkhazian},
	{"Afan", QLocale::Afan},
	{"Afar", QLocale::Afar},
	{"Afrikaans", QLocale::Afrikaans},
	{"Albanian", QLocale::Albanian},
	{"Amharic", QLocale::Amharic},
	{"Arabic", QLocale::Arabic},
	{"Armenian", QLocale::Armenian},
	{"Assamese", QLocale::Assamese},
	{"Aymara", QLocale::Aymara},
	{"Azerbaijani", QLocale::Azerbaijani},
	{"Bashkir", QLocale::Bashkir},
	{"Basque", QLocale::Basque},
	{"Bengali", QLocale::Bengali},
	{"Bhutani", QLocale::Bhutani},
	{"Bihari", QLocale::Bihari},
	{"Bislama", QLocale::Bislama},
	{"Bosnian", QLocale::Bosnian},
	{"Breton", QLocale::Breton},
	{"Bulgarian", QLocale::Bulgarian},
	{"Burmese", QLocale::Burmese},
	{"Byelorussian", QLocale::Byelorussian},
	{"Cambodian", QLocale::Cambodian},
	{"Catalan", QLocale::Catalan},
	{"Chinese", QLocale::Chinese},
	{"Cornish", QLocale::Cornish},
	{"Corsican", QLocale::Corsican},
	{"Croatian", QLocale::Croatian},
	{"Czech", QLocale::Czech},
	{"Danish", QLocale::Danish},
	{"Divehi", QLocale::Divehi},
	{"Dutch", QLocale::Dutch},
	{"English", QLocale::English},
	{"Esperanto", QLocale::Esperanto},
	{"Estonian", QLocale::Estonian},
	{"Faroese", QLocale::Faroese},
	{"FijiLanguage", QLocale::FijiLanguage},
	{"Finnish", QLocale::Finnish},
	{"French", QLocale::French},
	{"Frisian", QLocale::Frisian},
	{"Gaelic", QLocale::Gaelic},
	{"Galician", QLocale::Galician},
	{"Georgian", QLocale::Georgian},
	{"German", QLocale::German},
	{"Greek", QLocale::Greek},
	{"Greenlandic", QLocale::Greenlandic},
	{"Guarani", QLocale::Guarani},
	{"Gujarati", QLocale::Gujarati},
	{"Hausa", QLocale::Hausa},
	{"Hebrew", QLocale::Hebrew},
	{"Hindi", QLocale::Hindi},
	{"Hungarian", QLocale::Hungarian},
	{"Icelandic", QLocale::Icelandic},
	{"Indonesian", QLocale::Indonesian},
	{"Interlingua", QLocale::Interlingua},
	{"Interlingue", QLocale::Interlingue},
	{"Inuktitut", QLocale::Inuktitut},
	{"Inupiak", QLocale::Inupiak},
	{"Irish", QLocale::Irish},
	{"Italian", QLocale::Italian},
	{"Japanese", QLocale::Japanese},
	{"Javanese", QLocale::Javanese},
	{"Kannada", QLocale::Kannada},
	{"Kashmiri", QLocale::Kashmiri},
	{"Kazakh", QLocale::Kazakh},
	{"Kinyarwanda", QLocale::Kinyarwanda},
	{"Kirghiz", QLocale::Kirghiz},
	{"Korean", QLocale::Korean},
	{"Kurdish", QLocale::Kurdish},
	{"Kurundi", QLocale::Kurundi},
	{"Laothian", QLocale::Laothian},
	{"Latin", QLocale::Latin},
	{"Latvian", QLocale::Latvian},
	{"Lingala", QLocale::Lingala},
	{"Lithuanian", QLocale::Lithuanian},
	{"Macedonian", QLocale::Macedonian},
	{"Malagasy", QLocale::Malagasy},
	{"Malay", QLocale::Malay},
	{"Malayalam", QLocale::Malayalam},
	{"Maltese", QLocale::Maltese},
	{"Manx", QLocale::Manx},
	{"Maori", QLocale::Maori},
	{"Marathi", QLocale::Marathi},
	{"Moldavian", QLocale::Moldavian},
	{"Mongolian", QLocale::Mongolian},
	{"NauruLanguage", QLocale::NauruLanguage},
	{"Nepali", QLocale::Nepali},
	{"Norwegian", QLocale::Norwegian},
	{"NorwegianBokmal", QLocale::NorwegianBokmal},
	{"Nynorsk", QLocale::Nynorsk},
	{"NorwegianNynorsk", QLocale::NorwegianNynorsk},
	{"Occitan", QLocale::Occitan},
	{"Oriya", QLocale::Oriya},
	{"Pashto", QLocale::Pashto},
	{"Persian", QLocale::Persian},
	{"Polish", QLocale::Polish},
	{"Portuguese", QLocale::Portuguese},
	{"Punjabi", QLocale::Punjabi},
	{"Quechua", QLocale::Quechua},
	{"RhaetoRomance", QLocale::RhaetoRomance},
	{"Romanian", QLocale::Romanian},
	{"Russian", QLocale::Russian},
	{"Samoan", QLocale::Samoan},
	{"Sangho", QLocale::Sangho},
	{"Sanskrit", QLocale::Sanskrit},
	{"Serbian", QLocale::Serbian},
	{"SerboCroatian", QLocale::SerboCroatian},
	{"Sesotho", QLocale::Sesotho},
	{"Setswana", QLocale::Setswana},
	{"Shona", QLocale::Shona},
	{"Sindhi", QLocale::Sindhi},
	{"Singhalese", QLocale::Singhalese},
	{"Siswati", QLocale::Siswati},
	{"Slovak", QLocale::Slovak},
	{"Slovenian", QLocale::Slovenian},
	{"Somali", QLocale::Somali},
	{"Spanish", QLocale::Spanish},
	{"Sundanese", QLocale::Sundanese},
	{"Swahili", QLocale::Swahili},
	{"Swedish", QLocale::Swedish},
	{"Tagalog", QLocale::Tagalog},
	{"Tajik", QLocale::Tajik},
	{"Tamil", QLocale::Tamil},
	{"Tatar", QLocale::Tatar},
	{"Telugu", QLocale::Telugu},
	{"Thai", QLocale::Thai},
	{"Tibetan", QLocale::Tibetan},
	{"Tigrinya", QLocale::Tigrinya},
	{"TongaLanguage", QLocale::TongaLanguage},
	{"Tsonga", QLocale::Tsonga},
	{"Turkish", QLocale::Turkish},
	{"Turkmen", QLocale::Turkmen},
	{"Twi", QLocale::Twi},
	{"Uigur", QLocale::Uigur},
	{"Ukrainian", QLocale::Ukrainian},
	{"Urdu", QLocale::Urdu},
	{"Uzbek", QLocale::Uzbek},
	{"Vietnamese", QLocale::Vietnamese},
	{"Volapuk", QLocale::Volapuk},
	{"Welsh", QLocale::Welsh},
	{"Wolof", QLocale::Wolof},
	{"Xhosa", QLocale::Xhosa},
	{"Yiddish", QLocale::Yiddish},
	{"Yoruba", QLocale::Yoruba},
	{"Zhuang", QLocale::Zhuang},
	{"Zulu", QLocale::Zulu},
	{"Bosnian", QLocale::Bosnian},
	{"Divehi", QLocale::Divehi},
	{"Manx", QLocale::Manx},
	{"Cornish", QLocale::Cornish},
	{"Akan", QLocale::Akan},
	{"Konkani", QLocale::Konkani},
	{"Ga", QLocale::Ga},
	{"Igbo", QLocale::Igbo},
	{"Kamba", QLocale::Kamba},
	{"Syriac", QLocale::Syriac},
	{"Blin", QLocale::Blin},
	{"Geez", QLocale::Geez},
	{"Koro", QLocale::Koro},
	{"Sidamo", QLocale::Sidamo},
	{"Atsam", QLocale::Atsam},
	{"Tigre", QLocale::Tigre},
	{"Jju", QLocale::Jju},
	{"Friulian", QLocale::Friulian},
	{"Venda", QLocale::Venda},
	{"Ewe", QLocale::Ewe},
	{"Walamo", QLocale::Walamo},
	{"Hawaiian", QLocale::Hawaiian},
	{"Tyap", QLocale::Tyap},
	{"Chewa", QLocale::Chewa},
	{"Filipino", QLocale::Filipino},
	{"SwissGerman", QLocale::SwissGerman},
	{"SichuanYi", QLocale::SichuanYi},
	{"Kpelle", QLocale::Kpelle},
	{"LowGerman", QLocale::LowGerman},
	{"SouthNdebele", QLocale::SouthNdebele},
	{"NorthernSotho", QLocale::NorthernSotho},
	{"NorthernSami", QLocale::NorthernSami},
	{"Taroko", QLocale::Taroko},
	{"Gusii", QLocale::Gusii},
	{"Taita", QLocale::Taita},
	{"Fulah", QLocale::Fulah},
	{"Kikuyu", QLocale::Kikuyu},
	{"Samburu", QLocale::Samburu},
	{"Sena", QLocale::Sena},
	{"NorthNdebele", QLocale::NorthNdebele},
	{"Rombo", QLocale::Rombo},
	{"Tachelhit", QLocale::Tachelhit},
	{"Kabyle", QLocale::Kabyle},
	{"Nyankole", QLocale::Nyankole},
	{"Bena", QLocale::Bena},
	{"Vunjo", QLocale::Vunjo},
	{"Bambara", QLocale::Bambara},
	{"Embu", QLocale::Embu},
	{"Cherokee", QLocale::Cherokee},
	{"Morisyen", QLocale::Morisyen},
	{"Makonde", QLocale::Makonde},
	{"Langi", QLocale::Langi},
	{"Ganda", QLocale::Ganda},
	{"Bemba", QLocale::Bemba},
	{"Kabuverdianu", QLocale::Kabuverdianu},
	{"Meru", QLocale::Meru},
	{"Kalenjin", QLocale::Kalenjin},
	{"Nama", QLocale::Nama},
	{"Machame", QLocale::Machame},
	{"Colognian", QLocale::Colognian},
	{"Masai", QLocale::Masai},
	{"Soga", QLocale::Soga},
	{"Luyia", QLocale::Luyia},
	{"Asu", QLocale::Asu},
	{"Teso", QLocale::Teso},
	{"Saho", QLocale::Saho},
	{"KoyraChiini", QLocale::KoyraChiini},
	{"Rwa", QLocale::Rwa},
	{"Luo", QLocale::Luo},
	{"Chiga", QLocale::Chiga},
	{"CentralMoroccoTamazight", QLocale::CentralMoroccoTamazight},
	{"KoyraboroSenni", QLocale::KoyraboroSenni},
	{"Shambala", QLocale::Shambala},
	{"MetricSystem", QLocale::MetricSystem},
	{"ImperialSystem", QLocale::ImperialSystem},
	{"OmitGroupSeparator", QLocale::OmitGroupSeparator},
	{"RejectGroupSeparator", QLocale::RejectGroupSeparator},
	{NULL, 0}
};

DEFAPI(void) constQLocale(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QLocaleConstInt);
}

