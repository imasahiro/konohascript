//QDockWidget QDockWidget.new(String title, QWidget parent, int flags);
KMETHOD QDockWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString title = String_to(const QString, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	Qt::WindowFlags flags = Int_to(Qt::WindowFlags, sfp[3]);
	KQDockWidget *ret_v = new KQDockWidget(title, parent, flags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QDockWidget QDockWidget.new(QWidget parent, int flags);
KMETHOD QDockWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	Qt::WindowFlags flags = Int_to(Qt::WindowFlags, sfp[2]);
	KQDockWidget *ret_v = new KQDockWidget(parent, flags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QDockWidget.getAllowedAreas();
KMETHOD QDockWidget_getAllowedAreas(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDockWidget *  qp = RawPtr_to(QDockWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::DockWidgetAreas ret_v = qp->allowedAreas();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QDockWidget.getFeatures();
KMETHOD QDockWidget_getFeatures(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDockWidget *  qp = RawPtr_to(QDockWidget *, sfp[0]);
	if (qp != NULL) {
		QDockWidget::DockWidgetFeatures ret_v = qp->features();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QDockWidget.isAreaAllowed(int area);
KMETHOD QDockWidget_isAreaAllowed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDockWidget *  qp = RawPtr_to(QDockWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::DockWidgetArea area = Int_to(Qt::DockWidgetArea, sfp[1]);
		bool ret_v = qp->isAreaAllowed(area);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDockWidget.isFloating();
KMETHOD QDockWidget_isFloating(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDockWidget *  qp = RawPtr_to(QDockWidget *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isFloating();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QDockWidget.setAllowedAreas(int areas);
KMETHOD QDockWidget_setAllowedAreas(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDockWidget *  qp = RawPtr_to(QDockWidget *, sfp[0]);
	if (qp != NULL) {
		Qt::DockWidgetAreas areas = Int_to(Qt::DockWidgetAreas, sfp[1]);
		qp->setAllowedAreas(areas);
	}
	RETURNvoid_();
}

//void QDockWidget.setFeatures(int features);
KMETHOD QDockWidget_setFeatures(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDockWidget *  qp = RawPtr_to(QDockWidget *, sfp[0]);
	if (qp != NULL) {
		QDockWidget::DockWidgetFeatures features = Int_to(QDockWidget::DockWidgetFeatures, sfp[1]);
		qp->setFeatures(features);
	}
	RETURNvoid_();
}

//void QDockWidget.setFloating(boolean floating);
KMETHOD QDockWidget_setFloating(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDockWidget *  qp = RawPtr_to(QDockWidget *, sfp[0]);
	if (qp != NULL) {
		bool floating = Boolean_to(bool, sfp[1]);
		qp->setFloating(floating);
	}
	RETURNvoid_();
}

//void QDockWidget.setTitleBarWidget(QWidget widget);
KMETHOD QDockWidget_setTitleBarWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDockWidget *  qp = RawPtr_to(QDockWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setTitleBarWidget(widget);
	}
	RETURNvoid_();
}

//void QDockWidget.setWidget(QWidget widget);
KMETHOD QDockWidget_setWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDockWidget *  qp = RawPtr_to(QDockWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setWidget(widget);
	}
	RETURNvoid_();
}

//QWidget QDockWidget.getTitleBarWidget();
KMETHOD QDockWidget_getTitleBarWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDockWidget *  qp = RawPtr_to(QDockWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->titleBarWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAction QDockWidget.toggleViewAction();
KMETHOD QDockWidget_toggleViewAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDockWidget *  qp = RawPtr_to(QDockWidget *, sfp[0]);
	if (qp != NULL) {
		QAction* ret_v = qp->toggleViewAction();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QDockWidget.getWidget();
KMETHOD QDockWidget_getWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDockWidget *  qp = RawPtr_to(QDockWidget *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->widget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQDockWidget::DummyQDockWidget()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQDockWidget::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDockWidget::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQDockWidget::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQDockWidget::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDockWidget::event_map->bigin();
	if ((itr = DummyQDockWidget::event_map->find(str)) == DummyQDockWidget::event_map->end()) {
		bool ret;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDockWidget::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDockWidget::slot_map->bigin();
	if ((itr = DummyQDockWidget::event_map->find(str)) == DummyQDockWidget::slot_map->end()) {
		bool ret;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQDockWidget::KQDockWidget(const QString title, QWidget* parent, Qt::WindowFlags flags) : QDockWidget(title, parent, flags)
{
	self = NULL;
}

KMETHOD QDockWidget_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDockWidget *qp = RawPtr_to(KQDockWidget *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDockWidget]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQDockWidget::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDockWidget]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QDockWidget_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDockWidget *qp = RawPtr_to(KQDockWidget *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDockWidget]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQDockWidget::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDockWidget]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDockWidget_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDockWidget *qp = (KQDockWidget *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDockWidget_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQDockWidget *qp = (KQDockWidget *)p->rawptr;
		(void)qp;
	}
}

static int QDockWidget_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQDockWidget::event(QEvent *event)
{
	if (!DummyQDockWidget::eventDispatcher(event)) {
		QDockWidget::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQDockWidget(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDockWidget";
	cdef->free = QDockWidget_free;
	cdef->reftrace = QDockWidget_reftrace;
	cdef->compareTo = QDockWidget_compareTo;
}

static knh_IntData_t QDockWidgetConstInt[] = {
	{"DockWidgetClosable", QDockWidget::DockWidgetClosable},
	{"DockWidgetMovable", QDockWidget::DockWidgetMovable},
	{"DockWidgetFloatable", QDockWidget::DockWidgetFloatable},
	{"DockWidgetVerticalTitleBar", QDockWidget::DockWidgetVerticalTitleBar},
	{"AllDockWidgetFeatures", QDockWidget::AllDockWidgetFeatures},
	{"NoDockWidgetFeatures", QDockWidget::NoDockWidgetFeatures},
	{NULL, 0}
};

DEFAPI(void) constQDockWidget(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QDockWidgetConstInt);
}

