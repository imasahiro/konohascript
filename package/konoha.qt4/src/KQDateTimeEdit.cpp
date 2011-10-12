//@Virtual @Override void QDateTimeEdit.clear();
KMETHOD QDateTimeEdit_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		qp->clear();
	}
	RETURNvoid_();
}

//@Virtual @Override boolean QDateTimeEdit.event(QEvent event);
KMETHOD QDateTimeEdit_event(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QEvent*  event = RawPtr_to(QEvent*, sfp[1]);
		bool ret_v = qp->event(event);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QSize QDateTimeEdit.sizeHint();
KMETHOD QDateTimeEdit_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QDateTimeEdit.stepBy(int steps);
KMETHOD QDateTimeEdit_stepBy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		int steps = Int_to(int, sfp[1]);
		qp->stepBy(steps);
	}
	RETURNvoid_();
}

//QDateTimeEdit QDateTimeEdit.new(QWidget parent);
KMETHOD QDateTimeEdit_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQDateTimeEdit *ret_v = new KQDateTimeEdit(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QDateTimeEdit QDateTimeEdit.new(QDateTime datetime, QWidget parent);
KMETHOD QDateTimeEdit_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QDateTime  datetime = *RawPtr_to(const QDateTime *, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQDateTimeEdit *ret_v = new KQDateTimeEdit(datetime, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QDateTimeEdit QDateTimeEdit.new(QDate date, QWidget parent);
KMETHOD QDateTimeEdit_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QDate  date = *RawPtr_to(const QDate *, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQDateTimeEdit *ret_v = new KQDateTimeEdit(date, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QDateTimeEdit QDateTimeEdit.new(QTime time, QWidget parent);
KMETHOD QDateTimeEdit_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QTime  time = *RawPtr_to(const QTime *, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQDateTimeEdit *ret_v = new KQDateTimeEdit(time, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QDateTimeEdit.getCalendarPopup();
KMETHOD QDateTimeEdit_getCalendarPopup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->calendarPopup();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QCalendarWidget QDateTimeEdit.getCalendarWidget();
KMETHOD QDateTimeEdit_getCalendarWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QCalendarWidget* ret_v = qp->calendarWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QCalendarWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QDateTimeEdit.clearMaximumDate();
KMETHOD QDateTimeEdit_clearMaximumDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		qp->clearMaximumDate();
	}
	RETURNvoid_();
}

//void QDateTimeEdit.clearMaximumDateTime();
KMETHOD QDateTimeEdit_clearMaximumDateTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		qp->clearMaximumDateTime();
	}
	RETURNvoid_();
}

//void QDateTimeEdit.clearMaximumTime();
KMETHOD QDateTimeEdit_clearMaximumTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		qp->clearMaximumTime();
	}
	RETURNvoid_();
}

//void QDateTimeEdit.clearMinimumDate();
KMETHOD QDateTimeEdit_clearMinimumDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		qp->clearMinimumDate();
	}
	RETURNvoid_();
}

//void QDateTimeEdit.clearMinimumDateTime();
KMETHOD QDateTimeEdit_clearMinimumDateTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		qp->clearMinimumDateTime();
	}
	RETURNvoid_();
}

//void QDateTimeEdit.clearMinimumTime();
KMETHOD QDateTimeEdit_clearMinimumTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		qp->clearMinimumTime();
	}
	RETURNvoid_();
}

//int QDateTimeEdit.getCurrentSection();
KMETHOD QDateTimeEdit_getCurrentSection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QDateTimeEdit::Section ret_v = qp->currentSection();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QDateTimeEdit.getCurrentSectionIndex();
KMETHOD QDateTimeEdit_getCurrentSectionIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->currentSectionIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QDate QDateTimeEdit.getDate();
KMETHOD QDateTimeEdit_getDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QDate ret_v = qp->date();
		QDate *ret_v_ = new QDate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QDateTimeEdit.getDateTime();
KMETHOD QDateTimeEdit_getDateTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QDateTime ret_v = qp->dateTime();
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QDateTimeEdit.getDisplayFormat();
KMETHOD QDateTimeEdit_getDisplayFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->displayFormat();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDateTimeEdit.displayedSections();
KMETHOD QDateTimeEdit_displayedSections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QDateTimeEdit::Sections ret_v = qp->displayedSections();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QDate QDateTimeEdit.getMaximumDate();
KMETHOD QDateTimeEdit_getMaximumDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QDate ret_v = qp->maximumDate();
		QDate *ret_v_ = new QDate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QDateTimeEdit.getMaximumDateTime();
KMETHOD QDateTimeEdit_getMaximumDateTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QDateTime ret_v = qp->maximumDateTime();
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTime QDateTimeEdit.getMaximumTime();
KMETHOD QDateTimeEdit_getMaximumTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QTime ret_v = qp->maximumTime();
		QTime *ret_v_ = new QTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDate QDateTimeEdit.getMinimumDate();
KMETHOD QDateTimeEdit_getMinimumDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QDate ret_v = qp->minimumDate();
		QDate *ret_v_ = new QDate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QDateTimeEdit.getMinimumDateTime();
KMETHOD QDateTimeEdit_getMinimumDateTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QDateTime ret_v = qp->minimumDateTime();
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTime QDateTimeEdit.getMinimumTime();
KMETHOD QDateTimeEdit_getMinimumTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QTime ret_v = qp->minimumTime();
		QTime *ret_v_ = new QTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDateTimeEdit.sectionAt(int index);
KMETHOD QDateTimeEdit_sectionAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QDateTimeEdit::Section ret_v = qp->sectionAt(index);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QDateTimeEdit.sectionCount();
KMETHOD QDateTimeEdit_sectionCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->sectionCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QDateTimeEdit.sectionText(int section);
KMETHOD QDateTimeEdit_sectionText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QDateTimeEdit::Section section = Int_to(QDateTimeEdit::Section, sfp[1]);
		QString ret_v = qp->sectionText(section);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QDateTimeEdit.setCalendarPopup(boolean enable);
KMETHOD QDateTimeEdit_setCalendarPopup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setCalendarPopup(enable);
	}
	RETURNvoid_();
}

//void QDateTimeEdit.setCalendarWidget(QCalendarWidget calendarWidget);
KMETHOD QDateTimeEdit_setCalendarWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QCalendarWidget*  calendarWidget = RawPtr_to(QCalendarWidget*, sfp[1]);
		qp->setCalendarWidget(calendarWidget);
	}
	RETURNvoid_();
}

//void QDateTimeEdit.setCurrentSection(int section);
KMETHOD QDateTimeEdit_setCurrentSection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QDateTimeEdit::Section section = Int_to(QDateTimeEdit::Section, sfp[1]);
		qp->setCurrentSection(section);
	}
	RETURNvoid_();
}

//void QDateTimeEdit.setCurrentSectionIndex(int index);
KMETHOD QDateTimeEdit_setCurrentSectionIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		qp->setCurrentSectionIndex(index);
	}
	RETURNvoid_();
}

//void QDateTimeEdit.setDateRange(QDate min, QDate max);
KMETHOD QDateTimeEdit_setDateRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		const QDate  min = *RawPtr_to(const QDate *, sfp[1]);
		const QDate  max = *RawPtr_to(const QDate *, sfp[2]);
		qp->setDateRange(min, max);
	}
	RETURNvoid_();
}

//void QDateTimeEdit.setDateTimeRange(QDateTime min, QDateTime max);
KMETHOD QDateTimeEdit_setDateTimeRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		const QDateTime  min = *RawPtr_to(const QDateTime *, sfp[1]);
		const QDateTime  max = *RawPtr_to(const QDateTime *, sfp[2]);
		qp->setDateTimeRange(min, max);
	}
	RETURNvoid_();
}

//void QDateTimeEdit.setDisplayFormat(String fmt);
KMETHOD QDateTimeEdit_setDisplayFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		const QString format = String_to(const QString, sfp[1]);
		qp->setDisplayFormat(format);
	}
	RETURNvoid_();
}

//void QDateTimeEdit.setMaximumDate(QDate max);
KMETHOD QDateTimeEdit_setMaximumDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		const QDate  max = *RawPtr_to(const QDate *, sfp[1]);
		qp->setMaximumDate(max);
	}
	RETURNvoid_();
}

//void QDateTimeEdit.setMaximumDateTime(QDateTime dt);
KMETHOD QDateTimeEdit_setMaximumDateTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		const QDateTime  dt = *RawPtr_to(const QDateTime *, sfp[1]);
		qp->setMaximumDateTime(dt);
	}
	RETURNvoid_();
}

//void QDateTimeEdit.setMaximumTime(QTime max);
KMETHOD QDateTimeEdit_setMaximumTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		const QTime  max = *RawPtr_to(const QTime *, sfp[1]);
		qp->setMaximumTime(max);
	}
	RETURNvoid_();
}

//void QDateTimeEdit.setMinimumDate(QDate min);
KMETHOD QDateTimeEdit_setMinimumDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		const QDate  min = *RawPtr_to(const QDate *, sfp[1]);
		qp->setMinimumDate(min);
	}
	RETURNvoid_();
}

//void QDateTimeEdit.setMinimumDateTime(QDateTime dt);
KMETHOD QDateTimeEdit_setMinimumDateTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		const QDateTime  dt = *RawPtr_to(const QDateTime *, sfp[1]);
		qp->setMinimumDateTime(dt);
	}
	RETURNvoid_();
}

//void QDateTimeEdit.setMinimumTime(QTime min);
KMETHOD QDateTimeEdit_setMinimumTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		const QTime  min = *RawPtr_to(const QTime *, sfp[1]);
		qp->setMinimumTime(min);
	}
	RETURNvoid_();
}

//void QDateTimeEdit.setSelectedSection(int section);
KMETHOD QDateTimeEdit_setSelectedSection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QDateTimeEdit::Section section = Int_to(QDateTimeEdit::Section, sfp[1]);
		qp->setSelectedSection(section);
	}
	RETURNvoid_();
}

//void QDateTimeEdit.setTimeRange(QTime min, QTime max);
KMETHOD QDateTimeEdit_setTimeRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		const QTime  min = *RawPtr_to(const QTime *, sfp[1]);
		const QTime  max = *RawPtr_to(const QTime *, sfp[2]);
		qp->setTimeRange(min, max);
	}
	RETURNvoid_();
}

//void QDateTimeEdit.setTimeSpec(int spec);
KMETHOD QDateTimeEdit_setTimeSpec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		Qt::TimeSpec spec = Int_to(Qt::TimeSpec, sfp[1]);
		qp->setTimeSpec(spec);
	}
	RETURNvoid_();
}

//QTime QDateTimeEdit.getTime();
KMETHOD QDateTimeEdit_getTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		QTime ret_v = qp->time();
		QTime *ret_v_ = new QTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDateTimeEdit.getTimeSpec();
KMETHOD QDateTimeEdit_getTimeSpec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		Qt::TimeSpec ret_v = qp->timeSpec();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QDateTimeEdit.setDate(QDate date);
KMETHOD QDateTimeEdit_setDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		const QDate  date = *RawPtr_to(const QDate *, sfp[1]);
		qp->setDate(date);
	}
	RETURNvoid_();
}

//void QDateTimeEdit.setDateTime(QDateTime dateTime);
KMETHOD QDateTimeEdit_setDateTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		const QDateTime  dateTime = *RawPtr_to(const QDateTime *, sfp[1]);
		qp->setDateTime(dateTime);
	}
	RETURNvoid_();
}

//void QDateTimeEdit.setTime(QTime time);
KMETHOD QDateTimeEdit_setTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp != NULL) {
		const QTime  time = *RawPtr_to(const QTime *, sfp[1]);
		qp->setTime(time);
	}
	RETURNvoid_();
}


DummyQDateTimeEdit::DummyQDateTimeEdit()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQDateTimeEdit::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDateTimeEdit::self = ptr;
	DummyQAbstractSpinBox::setSelf(ptr);
}

bool DummyQDateTimeEdit::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractSpinBox::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQDateTimeEdit::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDateTimeEdit::event_map->bigin();
	if ((itr = DummyQDateTimeEdit::event_map->find(str)) == DummyQDateTimeEdit::event_map->end()) {
		bool ret;
		ret = DummyQAbstractSpinBox::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDateTimeEdit::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDateTimeEdit::slot_map->bigin();
	if ((itr = DummyQDateTimeEdit::event_map->find(str)) == DummyQDateTimeEdit::slot_map->end()) {
		bool ret;
		ret = DummyQAbstractSpinBox::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQDateTimeEdit::KQDateTimeEdit(QWidget* parent) : QDateTimeEdit(parent)
{
	self = NULL;
}

KMETHOD QDateTimeEdit_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDateTimeEdit *qp = RawPtr_to(KQDateTimeEdit *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDateTimeEdit]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQDateTimeEdit::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDateTimeEdit]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QDateTimeEdit_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDateTimeEdit *qp = RawPtr_to(KQDateTimeEdit *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDateTimeEdit]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQDateTimeEdit::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDateTimeEdit]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDateTimeEdit_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDateTimeEdit *qp = (KQDateTimeEdit *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDateTimeEdit_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQDateTimeEdit *qp = (KQDateTimeEdit *)p->rawptr;
		(void)qp;
	}
}

static int QDateTimeEdit_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQDateTimeEdit::event(QEvent *event)
{
	if (!DummyQDateTimeEdit::eventDispatcher(event)) {
		QDateTimeEdit::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQDateTimeEdit(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDateTimeEdit";
	cdef->free = QDateTimeEdit_free;
	cdef->reftrace = QDateTimeEdit_reftrace;
	cdef->compareTo = QDateTimeEdit_compareTo;
}

static knh_IntData_t QDateTimeEditConstInt[] = {
	{"NoSection", QDateTimeEdit::NoSection},
	{"AmPmSection", QDateTimeEdit::AmPmSection},
	{"MSecSection", QDateTimeEdit::MSecSection},
	{"SecondSection", QDateTimeEdit::SecondSection},
	{"MinuteSection", QDateTimeEdit::MinuteSection},
	{"HourSection", QDateTimeEdit::HourSection},
	{"DaySection", QDateTimeEdit::DaySection},
	{"MonthSection", QDateTimeEdit::MonthSection},
	{"YearSection", QDateTimeEdit::YearSection},
	{NULL, 0}
};

DEFAPI(void) constQDateTimeEdit(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QDateTimeEditConstInt);
}

