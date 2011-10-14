//@Virtual @Override QSize QTabWidget.minimumSizeHint();
KMETHOD QTabWidget_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QTabWidget.sizeHint();
KMETHOD QTabWidget_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTabWidget QTabWidget.new(QWidget parent);
KMETHOD QTabWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQTabWidget *ret_v = new KQTabWidget(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QTabWidget.addTab(QWidget page, String label);
KMETHOD QTabWidget_addTab(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  page = RawPtr_to(QWidget*, sfp[1]);
		const QString label = String_to(const QString, sfp[2]);
		int ret_v = qp->addTab(page, label);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QTabWidget.addTab(QWidget page, QIcon icon, String label);
KMETHOD QTabWidget_addTab(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  page = RawPtr_to(QWidget*, sfp[1]);
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[2]);
		const QString label = String_to(const QString, sfp[3]);
		int ret_v = qp->addTab(page, icon, label);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//void QTabWidget.clear();
KMETHOD QTabWidget_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		qp->clear();
	}
	RETURNvoid_();
}

//QWidget QTabWidget.getCornerWidget(int corner);
KMETHOD QTabWidget_getCornerWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::Corner corner = Int_to(Qt::Corner, sfp[1]);
		QWidget* ret_v = qp->cornerWidget(corner);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTabWidget.count();
KMETHOD QTabWidget_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTabWidget.getCurrentIndex();
KMETHOD QTabWidget_getCurrentIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->currentIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWidget QTabWidget.getCurrentWidget();
KMETHOD QTabWidget_getCurrentWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->currentWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QTabWidget.getDocumentMode();
KMETHOD QTabWidget_getDocumentMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->documentMode();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QTabWidget.getElideMode();
KMETHOD QTabWidget_getElideMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::TextElideMode ret_v = qp->elideMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QSize QTabWidget.getIconSize();
KMETHOD QTabWidget_getIconSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->iconSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTabWidget.indexOf(QWidget w);
KMETHOD QTabWidget_indexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  w = RawPtr_to(QWidget*, sfp[1]);
		int ret_v = qp->indexOf(w);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTabWidget.insertTab(int index, QWidget page, String label);
KMETHOD QTabWidget_insertTab(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QWidget*  page = RawPtr_to(QWidget*, sfp[2]);
		const QString label = String_to(const QString, sfp[3]);
		int ret_v = qp->insertTab(index, page, label);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QTabWidget.insertTab(int index, QWidget page, QIcon icon, String label);
KMETHOD QTabWidget_insertTab(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QWidget*  page = RawPtr_to(QWidget*, sfp[2]);
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[3]);
		const QString label = String_to(const QString, sfp[4]);
		int ret_v = qp->insertTab(index, page, icon, label);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//boolean QTabWidget.isMovable();
KMETHOD QTabWidget_isMovable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isMovable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTabWidget.isTabEnabled(int index);
KMETHOD QTabWidget_isTabEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		bool ret_v = qp->isTabEnabled(index);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QTabWidget.removeTab(int index);
KMETHOD QTabWidget_removeTab(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		qp->removeTab(index);
	}
	RETURNvoid_();
}

//void QTabWidget.setCornerWidget(QWidget widget, int corner);
KMETHOD QTabWidget_setCornerWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		Qt::Corner corner = Int_to(Qt::Corner, sfp[2]);
		qp->setCornerWidget(widget, corner);
	}
	RETURNvoid_();
}

//void QTabWidget.setDocumentMode(boolean set);
KMETHOD QTabWidget_setDocumentMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		bool set = Boolean_to(bool, sfp[1]);
		qp->setDocumentMode(set);
	}
	RETURNvoid_();
}

//void QTabWidget.setElideMode(int arg0);
KMETHOD QTabWidget_setElideMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::TextElideMode arg0 = Int_to(Qt::TextElideMode, sfp[1]);
		qp->setElideMode(arg0);
	}
	RETURNvoid_();
}

//void QTabWidget.setIconSize(QSize size);
KMETHOD QTabWidget_setIconSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		qp->setIconSize(size);
	}
	RETURNvoid_();
}

//void QTabWidget.setMovable(boolean movable);
KMETHOD QTabWidget_setMovable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		bool movable = Boolean_to(bool, sfp[1]);
		qp->setMovable(movable);
	}
	RETURNvoid_();
}

//void QTabWidget.setTabEnabled(int index, boolean enable);
KMETHOD QTabWidget_setTabEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		bool enable = Boolean_to(bool, sfp[2]);
		qp->setTabEnabled(index, enable);
	}
	RETURNvoid_();
}

//void QTabWidget.setTabIcon(int index, QIcon icon);
KMETHOD QTabWidget_setTabIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[2]);
		qp->setTabIcon(index, icon);
	}
	RETURNvoid_();
}

//void QTabWidget.setTabPosition(int arg0);
KMETHOD QTabWidget_setTabPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		QTabWidget::TabPosition arg0 = Int_to(QTabWidget::TabPosition, sfp[1]);
		qp->setTabPosition(arg0);
	}
	RETURNvoid_();
}

//void QTabWidget.setTabShape(int s);
KMETHOD QTabWidget_setTabShape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		QTabWidget::TabShape s = Int_to(QTabWidget::TabShape, sfp[1]);
		qp->setTabShape(s);
	}
	RETURNvoid_();
}

//void QTabWidget.setTabText(int index, String label);
KMETHOD QTabWidget_setTabText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		const QString label = String_to(const QString, sfp[2]);
		qp->setTabText(index, label);
	}
	RETURNvoid_();
}

//void QTabWidget.setTabToolTip(int index, String tip);
KMETHOD QTabWidget_setTabToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		const QString tip = String_to(const QString, sfp[2]);
		qp->setTabToolTip(index, tip);
	}
	RETURNvoid_();
}

//void QTabWidget.setTabWhatsThis(int index, String text);
KMETHOD QTabWidget_setTabWhatsThis(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		qp->setTabWhatsThis(index, text);
	}
	RETURNvoid_();
}

//void QTabWidget.setTabsClosable(boolean closeable);
KMETHOD QTabWidget_setTabsClosable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		bool closeable = Boolean_to(bool, sfp[1]);
		qp->setTabsClosable(closeable);
	}
	RETURNvoid_();
}

//void QTabWidget.setUsesScrollButtons(boolean useButtons);
KMETHOD QTabWidget_setUsesScrollButtons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		bool useButtons = Boolean_to(bool, sfp[1]);
		qp->setUsesScrollButtons(useButtons);
	}
	RETURNvoid_();
}

//QIcon QTabWidget.getTabIcon(int index);
KMETHOD QTabWidget_getTabIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QIcon ret_v = qp->tabIcon(index);
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTabWidget.getTabPosition();
KMETHOD QTabWidget_getTabPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		QTabWidget::TabPosition ret_v = qp->tabPosition();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTabWidget.getTabShape();
KMETHOD QTabWidget_getTabShape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		QTabWidget::TabShape ret_v = qp->tabShape();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QTabWidget.getTabText(int index);
KMETHOD QTabWidget_getTabText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QString ret_v = qp->tabText(index);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QTabWidget.getTabToolTip(int index);
KMETHOD QTabWidget_getTabToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QString ret_v = qp->tabToolTip(index);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QTabWidget.getTabWhatsThis(int index);
KMETHOD QTabWidget_getTabWhatsThis(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QString ret_v = qp->tabWhatsThis(index);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QTabWidget.getTabsClosable();
KMETHOD QTabWidget_getTabsClosable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->tabsClosable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QTabWidget.getUsesScrollButtons();
KMETHOD QTabWidget_getUsesScrollButtons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->usesScrollButtons();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QWidget QTabWidget.widget(int index);
KMETHOD QTabWidget_widget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QWidget* ret_v = qp->widget(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTabWidget.setCurrentIndex(int index);
KMETHOD QTabWidget_setCurrentIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		qp->setCurrentIndex(index);
	}
	RETURNvoid_();
}

//void QTabWidget.setCurrentWidget(QWidget widget);
KMETHOD QTabWidget_setCurrentWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabWidget *  qp = RawPtr_to(QTabWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setCurrentWidget(widget);
	}
	RETURNvoid_();
}


DummyQTabWidget::DummyQTabWidget()
{
	self = NULL;
	current_changed_func = NULL;
	tab_close_requested_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("current-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("tab-close-requested", NULL));
}

void DummyQTabWidget::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTabWidget::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQTabWidget::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTabWidget::currentChangedSlot(int index)
{
	if (current_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = index;
		knh_Func_invoke(lctx, current_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQTabWidget::tabCloseRequestedSlot(int index)
{
	if (tab_close_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = index;
		knh_Func_invoke(lctx, tab_close_requested_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQTabWidget::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTabWidget::event_map->bigin();
	if ((itr = DummyQTabWidget::event_map->find(str)) == DummyQTabWidget::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTabWidget::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTabWidget::slot_map->bigin();
	if ((itr = DummyQTabWidget::slot_map->find(str)) == DummyQTabWidget::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		current_changed_func = (*slot_map)["current-changed"];
		tab_close_requested_func = (*slot_map)["tab-close-requested"];
		return true;
	}
}


void DummyQTabWidget::connection(QObject *o)
{
	connect(o, SIGNAL(currentChanged(int)), this, SLOT(currentChangedSlot(int)));
	connect(o, SIGNAL(tabCloseRequested(int)), this, SLOT(tabCloseRequestedSlot(int)));
	DummyQWidget::connection(o);
}

KQTabWidget::KQTabWidget(QWidget* parent) : QTabWidget(parent)
{
	self = NULL;
	dummy = new DummyQTabWidget();
	dummy->connection((QObject*)this);
}

KMETHOD QTabWidget_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTabWidget *qp = RawPtr_to(KQTabWidget *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTabWidget]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTabWidget]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTabWidget_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTabWidget *qp = RawPtr_to(KQTabWidget *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTabWidget]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTabWidget]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTabWidget_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTabWidget *qp = (KQTabWidget *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTabWidget_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQTabWidget *qp = (KQTabWidget *)p->rawptr;
//		(void)qp;
		if (qp->dummy->current_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->current_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->tab_close_requested_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->tab_close_requested_func);
			KNH_SIZEREF(ctx);
		}
	}
}

static int QTabWidget_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTabWidget::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQTabWidget::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QTabWidget::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQTabWidget(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTabWidget";
	cdef->free = QTabWidget_free;
	cdef->reftrace = QTabWidget_reftrace;
	cdef->compareTo = QTabWidget_compareTo;
}

static knh_IntData_t QTabWidgetConstInt[] = {
	{"North", QTabWidget::North},
	{"South", QTabWidget::South},
	{"West", QTabWidget::West},
	{"East", QTabWidget::East},
	{"Rounded", QTabWidget::Rounded},
	{"Triangular", QTabWidget::Triangular},
	{NULL, 0}
};

DEFAPI(void) constQTabWidget(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTabWidgetConstInt);
}

