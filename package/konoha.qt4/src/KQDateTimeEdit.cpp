//@Virtual @Override void QDateTimeEdit.clear();
KMETHOD QDateTimeEdit_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//@Virtual @Override boolean QDateTimeEdit.event(QEvent event);
KMETHOD QDateTimeEdit_event(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QDateTimeEdit.getCalendarPopup();
KMETHOD QDateTimeEdit_getCalendarPopup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		qp->clearMaximumDate();
	}
	RETURNvoid_();
}

//void QDateTimeEdit.clearMaximumDateTime();
KMETHOD QDateTimeEdit_clearMaximumDateTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp) {
		qp->clearMaximumDateTime();
	}
	RETURNvoid_();
}

//void QDateTimeEdit.clearMaximumTime();
KMETHOD QDateTimeEdit_clearMaximumTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp) {
		qp->clearMaximumTime();
	}
	RETURNvoid_();
}

//void QDateTimeEdit.clearMinimumDate();
KMETHOD QDateTimeEdit_clearMinimumDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp) {
		qp->clearMinimumDate();
	}
	RETURNvoid_();
}

//void QDateTimeEdit.clearMinimumDateTime();
KMETHOD QDateTimeEdit_clearMinimumDateTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp) {
		qp->clearMinimumDateTime();
	}
	RETURNvoid_();
}

//void QDateTimeEdit.clearMinimumTime();
KMETHOD QDateTimeEdit_clearMinimumTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp) {
		qp->clearMinimumTime();
	}
	RETURNvoid_();
}

//int QDateTimeEdit.getCurrentSection();
KMETHOD QDateTimeEdit_getCurrentSection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		QString ret_v = qp->displayFormat();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTimeEditSections QDateTimeEdit.displayedSections();
KMETHOD QDateTimeEdit_displayedSections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp) {
		QDateTimeEdit::Sections ret_v = qp->displayedSections();
		QDateTimeEdit::Sections *ret_v_ = new QDateTimeEdit::Sections(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDate QDateTimeEdit.getMaximumDate();
KMETHOD QDateTimeEdit_getMaximumDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit *  qp = RawPtr_to(QDateTimeEdit *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		const QTime  time = *RawPtr_to(const QTime *, sfp[1]);
		qp->setTime(time);
	}
	RETURNvoid_();
}


DummyQDateTimeEdit::DummyQDateTimeEdit()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	date_changed_func = NULL;
	date_time_changed_func = NULL;
	time_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("date-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("date-time-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("time-changed", NULL));
}
DummyQDateTimeEdit::~DummyQDateTimeEdit()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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

bool DummyQDateTimeEdit::dateChangedSlot(const QDate date)
{
	if (date_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QDate, date);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, date_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQDateTimeEdit::dateTimeChangedSlot(const QDateTime datetime)
{
	if (date_time_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QDateTime, datetime);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, date_time_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQDateTimeEdit::timeChangedSlot(const QTime time)
{
	if (time_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QTime, time);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, time_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQDateTimeEdit::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDateTimeEdit::event_map->bigin();
	if ((itr = DummyQDateTimeEdit::event_map->find(str)) == DummyQDateTimeEdit::event_map->end()) {
		bool ret = false;
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
	if ((itr = DummyQDateTimeEdit::slot_map->find(str)) == DummyQDateTimeEdit::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractSpinBox::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		date_changed_func = (*slot_map)["date-changed"];
		date_time_changed_func = (*slot_map)["date-time-changed"];
		time_changed_func = (*slot_map)["time-changed"];
		return true;
	}
}

knh_Object_t** DummyQDateTimeEdit::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQDateTimeEdit::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 4;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, date_changed_func);
	KNH_ADDNNREF(ctx, date_time_changed_func);
	KNH_ADDNNREF(ctx, time_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQAbstractSpinBox::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQDateTimeEdit::connection(QObject *o)
{
	QDateTimeEdit *p = dynamic_cast<QDateTimeEdit*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(dateChanged(const QDate)), this, SLOT(dateChangedSlot(const QDate)));
		connect(p, SIGNAL(dateTimeChanged(const QDateTime)), this, SLOT(dateTimeChangedSlot(const QDateTime)));
		connect(p, SIGNAL(timeChanged(const QTime)), this, SLOT(timeChangedSlot(const QTime)));
	}
	DummyQAbstractSpinBox::connection(o);
}

KQDateTimeEdit::KQDateTimeEdit(QWidget* parent) : QDateTimeEdit(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQDateTimeEdit();
	dummy->connection((QObject*)this);
}

KQDateTimeEdit::~KQDateTimeEdit()
{
	delete dummy;
	dummy = NULL;
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDateTimeEdit]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDateTimeEdit_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQDateTimeEdit *qp = (KQDateTimeEdit *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QDateTimeEdit*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QDateTimeEdit_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQDateTimeEdit *qp = (KQDateTimeEdit *)p->rawptr;
		KQDateTimeEdit *qp = static_cast<KQDateTimeEdit*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QDateTimeEdit_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQDateTimeEdit::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQDateTimeEdit::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QDateTimeEdit::event(event);
		return false;
	}
//	QDateTimeEdit::event(event);
	return true;
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


DEFAPI(void) defQDateTimeEdit(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDateTimeEdit";
	cdef->free = QDateTimeEdit_free;
	cdef->reftrace = QDateTimeEdit_reftrace;
	cdef->compareTo = QDateTimeEdit_compareTo;
}

//## QDateTimeEditSections QDateTimeEditSections.new(int value);
KMETHOD QDateTimeEditSections_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDateTimeEdit::Section i = Int_to(QDateTimeEdit::Section, sfp[1]);
	QDateTimeEdit::Sections *ret_v = new QDateTimeEdit::Sections(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QDateTimeEditSections QDateTimeEditSections.and(int mask);
KMETHOD QDateTimeEditSections_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDateTimeEdit::Sections *qp = RawPtr_to(QDateTimeEdit::Sections*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QDateTimeEdit::Sections ret = ((*qp) & i);
		QDateTimeEdit::Sections *ret_ = new QDateTimeEdit::Sections(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QDateTimeEditSections QDateTimeEditSections.iand(QDateTimeEdit::QDateTimeEditSections other);
KMETHOD QDateTimeEditSections_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDateTimeEdit::Sections *qp = RawPtr_to(QDateTimeEdit::Sections*, sfp[0]);
	if (qp != NULL) {
		QDateTimeEdit::Sections *other = RawPtr_to(QDateTimeEdit::Sections *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QDateTimeEditSections QDateTimeEditSections.or(QDateTimeEditSections f);
KMETHOD QDateTimeEditSections_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit::Sections *qp = RawPtr_to(QDateTimeEdit::Sections*, sfp[0]);
	if (qp != NULL) {
		QDateTimeEdit::Sections *f = RawPtr_to(QDateTimeEdit::Sections*, sfp[1]);
		QDateTimeEdit::Sections ret = ((*qp) | (*f));
		QDateTimeEdit::Sections *ret_ = new QDateTimeEdit::Sections(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QDateTimeEditSections QDateTimeEditSections.ior(QDateTimeEdit::QDateTimeEditSections other);
KMETHOD QDateTimeEditSections_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDateTimeEdit::Sections *qp = RawPtr_to(QDateTimeEdit::Sections*, sfp[0]);
	if (qp != NULL) {
		QDateTimeEdit::Sections *other = RawPtr_to(QDateTimeEdit::Sections *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QDateTimeEditSections QDateTimeEditSections.xor(QDateTimeEditSections f);
KMETHOD QDateTimeEditSections_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDateTimeEdit::Sections *qp = RawPtr_to(QDateTimeEdit::Sections*, sfp[0]);
	if (qp != NULL) {
		QDateTimeEdit::Sections *f = RawPtr_to(QDateTimeEdit::Sections*, sfp[1]);
		QDateTimeEdit::Sections ret = ((*qp) ^ (*f));
		QDateTimeEdit::Sections *ret_ = new QDateTimeEdit::Sections(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QDateTimeEditSections QDateTimeEditSections.ixor(QDateTimeEdit::QDateTimeEditSections other);
KMETHOD QDateTimeEditSections_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDateTimeEdit::Sections *qp = RawPtr_to(QDateTimeEdit::Sections*, sfp[0]);
	if (qp != NULL) {
		QDateTimeEdit::Sections *other = RawPtr_to(QDateTimeEdit::Sections *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QDateTimeEditSections.testFlag(int flag);
KMETHOD QDateTimeEditSections_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDateTimeEdit::Sections *qp = RawPtr_to(QDateTimeEdit::Sections *, sfp[0]);
	if (qp != NULL) {
		QDateTimeEdit::Section flag = Int_to(QDateTimeEdit::Section, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QDateTimeEditSections.value();
KMETHOD QDateTimeEditSections_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDateTimeEdit::Sections *qp = RawPtr_to(QDateTimeEdit::Sections *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QDateTimeEditSections_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QDateTimeEdit::Sections *qp = (QDateTimeEdit::Sections *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QDateTimeEditSections_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QDateTimeEdit::Sections *qp = (QDateTimeEdit::Sections *)p->rawptr;
		(void)qp;
	}
}

static int QDateTimeEditSections_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QDateTimeEdit::Sections*)p1->rawptr);
//		int v2 = int(*(QDateTimeEdit::Sections*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QDateTimeEdit::Sections v1 = *(QDateTimeEdit::Sections*)p1->rawptr;
		QDateTimeEdit::Sections v2 = *(QDateTimeEdit::Sections*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQDateTimeEditSections(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDateTimeEditSections";
	cdef->free = QDateTimeEditSections_free;
	cdef->reftrace = QDateTimeEditSections_reftrace;
	cdef->compareTo = QDateTimeEditSections_compareTo;
}

