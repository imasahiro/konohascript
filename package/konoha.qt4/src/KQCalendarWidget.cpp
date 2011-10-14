//@Virtual @Override QSize QCalendarWidget.minimumSizeHint();
KMETHOD QCalendarWidget_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QCalendarWidget.sizeHint();
KMETHOD QCalendarWidget_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QCalendarWidget QCalendarWidget.new(QWidget parent);
KMETHOD QCalendarWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQCalendarWidget *ret_v = new KQCalendarWidget(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QCalendarWidget.getDateEditAcceptDelay();
KMETHOD QCalendarWidget_getDateEditAcceptDelay(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->dateEditAcceptDelay();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextCharFormat QCalendarWidget.getDateTextFormat(QDate date);
KMETHOD QCalendarWidget_getDateTextFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		const QDate  date = *RawPtr_to(const QDate *, sfp[1]);
		QTextCharFormat ret_v = qp->dateTextFormat(date);
		QTextCharFormat *ret_v_ = new QTextCharFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QCalendarWidget.getFirstDayOfWeek();
KMETHOD QCalendarWidget_getFirstDayOfWeek(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::DayOfWeek ret_v = qp->firstDayOfWeek();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextCharFormat QCalendarWidget.getHeaderTextFormat();
KMETHOD QCalendarWidget_getHeaderTextFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		QTextCharFormat ret_v = qp->headerTextFormat();
		QTextCharFormat *ret_v_ = new QTextCharFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QCalendarWidget.getHorizontalHeaderFormat();
KMETHOD QCalendarWidget_getHorizontalHeaderFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		QCalendarWidget::HorizontalHeaderFormat ret_v = qp->horizontalHeaderFormat();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QCalendarWidget.isDateEditEnabled();
KMETHOD QCalendarWidget_isDateEditEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isDateEditEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QCalendarWidget.isGridVisible();
KMETHOD QCalendarWidget_isGridVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isGridVisible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QCalendarWidget.isNavigationBarVisible();
KMETHOD QCalendarWidget_isNavigationBarVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isNavigationBarVisible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QDate QCalendarWidget.getMaximumDate();
KMETHOD QCalendarWidget_getMaximumDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		QDate ret_v = qp->maximumDate();
		QDate *ret_v_ = new QDate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDate QCalendarWidget.getMinimumDate();
KMETHOD QCalendarWidget_getMinimumDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		QDate ret_v = qp->minimumDate();
		QDate *ret_v_ = new QDate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QCalendarWidget.monthShown();
KMETHOD QCalendarWidget_monthShown(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->monthShown();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QDate QCalendarWidget.getSelectedDate();
KMETHOD QCalendarWidget_getSelectedDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		QDate ret_v = qp->selectedDate();
		QDate *ret_v_ = new QDate(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QCalendarWidget.getSelectionMode();
KMETHOD QCalendarWidget_getSelectionMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		QCalendarWidget::SelectionMode ret_v = qp->selectionMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QCalendarWidget.setDateEditAcceptDelay(int delay);
KMETHOD QCalendarWidget_setDateEditAcceptDelay(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		int delay = Int_to(int, sfp[1]);
		qp->setDateEditAcceptDelay(delay);
	}
	RETURNvoid_();
}

//void QCalendarWidget.setDateEditEnabled(boolean enable);
KMETHOD QCalendarWidget_setDateEditEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setDateEditEnabled(enable);
	}
	RETURNvoid_();
}

//void QCalendarWidget.setDateTextFormat(QDate date, QTextCharFormat fmt);
KMETHOD QCalendarWidget_setDateTextFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		const QDate  date = *RawPtr_to(const QDate *, sfp[1]);
		const QTextCharFormat  format = *RawPtr_to(const QTextCharFormat *, sfp[2]);
		qp->setDateTextFormat(date, format);
	}
	RETURNvoid_();
}

//void QCalendarWidget.setFirstDayOfWeek(int dayOfWeek);
KMETHOD QCalendarWidget_setFirstDayOfWeek(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::DayOfWeek dayOfWeek = Int_to(Qt::DayOfWeek, sfp[1]);
		qp->setFirstDayOfWeek(dayOfWeek);
	}
	RETURNvoid_();
}

//void QCalendarWidget.setHeaderTextFormat(QTextCharFormat fmt);
KMETHOD QCalendarWidget_setHeaderTextFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		const QTextCharFormat  format = *RawPtr_to(const QTextCharFormat *, sfp[1]);
		qp->setHeaderTextFormat(format);
	}
	RETURNvoid_();
}

//void QCalendarWidget.setHorizontalHeaderFormat(int fmt);
KMETHOD QCalendarWidget_setHorizontalHeaderFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		QCalendarWidget::HorizontalHeaderFormat format = Int_to(QCalendarWidget::HorizontalHeaderFormat, sfp[1]);
		qp->setHorizontalHeaderFormat(format);
	}
	RETURNvoid_();
}

//void QCalendarWidget.setMaximumDate(QDate date);
KMETHOD QCalendarWidget_setMaximumDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		const QDate  date = *RawPtr_to(const QDate *, sfp[1]);
		qp->setMaximumDate(date);
	}
	RETURNvoid_();
}

//void QCalendarWidget.setMinimumDate(QDate date);
KMETHOD QCalendarWidget_setMinimumDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		const QDate  date = *RawPtr_to(const QDate *, sfp[1]);
		qp->setMinimumDate(date);
	}
	RETURNvoid_();
}

//void QCalendarWidget.setSelectionMode(int mode);
KMETHOD QCalendarWidget_setSelectionMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		QCalendarWidget::SelectionMode mode = Int_to(QCalendarWidget::SelectionMode, sfp[1]);
		qp->setSelectionMode(mode);
	}
	RETURNvoid_();
}

//void QCalendarWidget.setVerticalHeaderFormat(int fmt);
KMETHOD QCalendarWidget_setVerticalHeaderFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		QCalendarWidget::VerticalHeaderFormat format = Int_to(QCalendarWidget::VerticalHeaderFormat, sfp[1]);
		qp->setVerticalHeaderFormat(format);
	}
	RETURNvoid_();
}

//void QCalendarWidget.setWeekdayTextFormat(int dayOfWeek, QTextCharFormat fmt);
KMETHOD QCalendarWidget_setWeekdayTextFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::DayOfWeek dayOfWeek = Int_to(Qt::DayOfWeek, sfp[1]);
		const QTextCharFormat  format = *RawPtr_to(const QTextCharFormat *, sfp[2]);
		qp->setWeekdayTextFormat(dayOfWeek, format);
	}
	RETURNvoid_();
}

//int QCalendarWidget.getVerticalHeaderFormat();
KMETHOD QCalendarWidget_getVerticalHeaderFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		QCalendarWidget::VerticalHeaderFormat ret_v = qp->verticalHeaderFormat();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QTextCharFormat QCalendarWidget.getWeekdayTextFormat(int dayOfWeek);
KMETHOD QCalendarWidget_getWeekdayTextFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::DayOfWeek dayOfWeek = Int_to(Qt::DayOfWeek, sfp[1]);
		QTextCharFormat ret_v = qp->weekdayTextFormat(dayOfWeek);
		QTextCharFormat *ret_v_ = new QTextCharFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QCalendarWidget.yearShown();
KMETHOD QCalendarWidget_yearShown(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->yearShown();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QCalendarWidget.setCurrentPage(int year, int month);
KMETHOD QCalendarWidget_setCurrentPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		int year = Int_to(int, sfp[1]);
		int month = Int_to(int, sfp[2]);
		qp->setCurrentPage(year, month);
	}
	RETURNvoid_();
}

//void QCalendarWidget.setDateRange(QDate min, QDate max);
KMETHOD QCalendarWidget_setDateRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		const QDate  min = *RawPtr_to(const QDate *, sfp[1]);
		const QDate  max = *RawPtr_to(const QDate *, sfp[2]);
		qp->setDateRange(min, max);
	}
	RETURNvoid_();
}

//void QCalendarWidget.setGridVisible(boolean show);
KMETHOD QCalendarWidget_setGridVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		bool show = Boolean_to(bool, sfp[1]);
		qp->setGridVisible(show);
	}
	RETURNvoid_();
}

//void QCalendarWidget.setNavigationBarVisible(boolean visible);
KMETHOD QCalendarWidget_setNavigationBarVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setNavigationBarVisible(visible);
	}
	RETURNvoid_();
}

//void QCalendarWidget.setSelectedDate(QDate date);
KMETHOD QCalendarWidget_setSelectedDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		const QDate  date = *RawPtr_to(const QDate *, sfp[1]);
		qp->setSelectedDate(date);
	}
	RETURNvoid_();
}

//void QCalendarWidget.showNextMonth();
KMETHOD QCalendarWidget_showNextMonth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		qp->showNextMonth();
	}
	RETURNvoid_();
}

//void QCalendarWidget.showNextYear();
KMETHOD QCalendarWidget_showNextYear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		qp->showNextYear();
	}
	RETURNvoid_();
}

//void QCalendarWidget.showPreviousMonth();
KMETHOD QCalendarWidget_showPreviousMonth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		qp->showPreviousMonth();
	}
	RETURNvoid_();
}

//void QCalendarWidget.showPreviousYear();
KMETHOD QCalendarWidget_showPreviousYear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		qp->showPreviousYear();
	}
	RETURNvoid_();
}

//void QCalendarWidget.showSelectedDate();
KMETHOD QCalendarWidget_showSelectedDate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		qp->showSelectedDate();
	}
	RETURNvoid_();
}

//void QCalendarWidget.showToday();
KMETHOD QCalendarWidget_showToday(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCalendarWidget *  qp = RawPtr_to(QCalendarWidget *, sfp[0]);
	if (qp != NULL) {
		qp->showToday();
	}
	RETURNvoid_();
}


DummyQCalendarWidget::DummyQCalendarWidget()
{
	self = NULL;
	activated_func = NULL;
	clicked_func = NULL;
	current_page_changed_func = NULL;
	selection_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("activated", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("clicked", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("current-page-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("selection-changed", NULL));
}

void DummyQCalendarWidget::setSelf(knh_RawPtr_t *ptr)
{
	DummyQCalendarWidget::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQCalendarWidget::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQCalendarWidget::activatedSlot(const QDate date)
{
	if (activated_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QDate, date);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, activated_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQCalendarWidget::clickedSlot(const QDate date)
{
	if (clicked_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QDate, date);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, clicked_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQCalendarWidget::currentPageChangedSlot(int year, int month)
{
	if (current_page_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = year;
		lsfp[K_CALLDELTA+3].ivalue = month;
		knh_Func_invoke(lctx, current_page_changed_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQCalendarWidget::selectionChangedSlot()
{
	if (selection_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, selection_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQCalendarWidget::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCalendarWidget::event_map->bigin();
	if ((itr = DummyQCalendarWidget::event_map->find(str)) == DummyQCalendarWidget::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQCalendarWidget::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCalendarWidget::slot_map->bigin();
	if ((itr = DummyQCalendarWidget::slot_map->find(str)) == DummyQCalendarWidget::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		activated_func = (*slot_map)["activated"];
		clicked_func = (*slot_map)["clicked"];
		current_page_changed_func = (*slot_map)["current-page-changed"];
		selection_changed_func = (*slot_map)["selection-changed"];
		return true;
	}
}


void DummyQCalendarWidget::connection(QObject *o)
{
	connect(o, SIGNAL(activated(const QDate)), this, SLOT(activatedSlot(const QDate)));
	connect(o, SIGNAL(clicked(const QDate)), this, SLOT(clickedSlot(const QDate)));
	connect(o, SIGNAL(currentPageChanged(int, int)), this, SLOT(currentPageChangedSlot(int, int)));
	connect(o, SIGNAL(selectionChanged()), this, SLOT(selectionChangedSlot()));
	DummyQWidget::connection(o);
}

KQCalendarWidget::KQCalendarWidget(QWidget* parent) : QCalendarWidget(parent)
{
	self = NULL;
	dummy = new DummyQCalendarWidget();
	dummy->connection((QObject*)this);
}

KMETHOD QCalendarWidget_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCalendarWidget *qp = RawPtr_to(KQCalendarWidget *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QCalendarWidget]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCalendarWidget]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QCalendarWidget_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCalendarWidget *qp = RawPtr_to(KQCalendarWidget *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QCalendarWidget]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCalendarWidget]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QCalendarWidget_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQCalendarWidget *qp = (KQCalendarWidget *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QCalendarWidget_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 4;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQCalendarWidget *qp = (KQCalendarWidget *)p->rawptr;
//		(void)qp;
		if (qp->dummy->activated_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->activated_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->clicked_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->clicked_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->current_page_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->current_page_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->selection_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->selection_changed_func);
			KNH_SIZEREF(ctx);
		}
	}
}

static int QCalendarWidget_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQCalendarWidget::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQCalendarWidget::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QCalendarWidget::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQCalendarWidget(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QCalendarWidget";
	cdef->free = QCalendarWidget_free;
	cdef->reftrace = QCalendarWidget_reftrace;
	cdef->compareTo = QCalendarWidget_compareTo;
}

static knh_IntData_t QCalendarWidgetConstInt[] = {
	{"SingleLetterDayNames", QCalendarWidget::SingleLetterDayNames},
	{"ShortDayNames", QCalendarWidget::ShortDayNames},
	{"LongDayNames", QCalendarWidget::LongDayNames},
	{"NoHorizontalHeader", QCalendarWidget::NoHorizontalHeader},
	{"NoSelection", QCalendarWidget::NoSelection},
	{"SingleSelection", QCalendarWidget::SingleSelection},
	{"ISOWeekNumbers", QCalendarWidget::ISOWeekNumbers},
	{"NoVerticalHeader", QCalendarWidget::NoVerticalHeader},
	{NULL, 0}
};

DEFAPI(void) constQCalendarWidget(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QCalendarWidgetConstInt);
}

