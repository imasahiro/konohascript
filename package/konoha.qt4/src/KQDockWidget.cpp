//QDockWidget QDockWidget.new(String title, QWidget parent, int flags);
KMETHOD QDockWidget_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString title = String_to(const QString, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	Qt::WindowFlags flags = Int_to(Qt::WindowFlags, sfp[3]);
	KQDockWidget *ret_v = new KQDockWidget(title, parent, flags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
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
	allowed_areas_changed_func = NULL;
	dock_location_changed_func = NULL;
	features_changed_func = NULL;
	top_level_changed_func = NULL;
	visibility_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("allowed-areas-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("dock-location-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("features-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("top-level-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("visibility-changed", NULL));
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

bool DummyQDockWidget::allowedAreasChangedSlot(Qt::DockWidgetAreas allowedAreas)
{
	if (allowed_areas_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = allowedAreas;
		knh_Func_invoke(lctx, allowed_areas_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQDockWidget::dockLocationChangedSlot(Qt::DockWidgetArea area)
{
	if (dock_location_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = area;
		knh_Func_invoke(lctx, dock_location_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQDockWidget::featuresChangedSlot(QDockWidget::DockWidgetFeatures features)
{
	if (features_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = features;
		knh_Func_invoke(lctx, features_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQDockWidget::topLevelChangedSlot(bool topLevel)
{
	if (top_level_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = topLevel;
		knh_Func_invoke(lctx, top_level_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQDockWidget::visibilityChangedSlot(bool visible)
{
	if (visibility_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = visible;
		knh_Func_invoke(lctx, visibility_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQDockWidget::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDockWidget::event_map->bigin();
	if ((itr = DummyQDockWidget::event_map->find(str)) == DummyQDockWidget::event_map->end()) {
		bool ret = false;
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
	if ((itr = DummyQDockWidget::slot_map->find(str)) == DummyQDockWidget::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		allowed_areas_changed_func = (*slot_map)["allowed-areas-changed"];
		dock_location_changed_func = (*slot_map)["dock-location-changed"];
		features_changed_func = (*slot_map)["features-changed"];
		top_level_changed_func = (*slot_map)["top-level-changed"];
		visibility_changed_func = (*slot_map)["visibility-changed"];
		return true;
	}
}


void DummyQDockWidget::connection(QObject *o)
{
	connect(o, SIGNAL(allowedAreasChanged(Qt::DockWidgetAreas)), this, SLOT(allowedAreasChangedSlot(Qt::DockWidgetAreas)));
	connect(o, SIGNAL(dockLocationChanged(Qt::DockWidgetArea)), this, SLOT(dockLocationChangedSlot(Qt::DockWidgetArea)));
	connect(o, SIGNAL(featuresChanged(QDockWidget::DockWidgetFeatures)), this, SLOT(featuresChangedSlot(QDockWidget::DockWidgetFeatures)));
	connect(o, SIGNAL(topLevelChanged(bool)), this, SLOT(topLevelChangedSlot(bool)));
	connect(o, SIGNAL(visibilityChanged(bool)), this, SLOT(visibilityChangedSlot(bool)));
	DummyQWidget::connection(o);
}

KQDockWidget::KQDockWidget(const QString title, QWidget* parent, Qt::WindowFlags flags) : QDockWidget(title, parent, flags)
{
	self = NULL;
	dummy = new DummyQDockWidget();
	dummy->connection((QObject*)this);
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
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
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 5;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQDockWidget *qp = (KQDockWidget *)p->rawptr;
//		(void)qp;
		if (qp->dummy->allowed_areas_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->allowed_areas_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->dock_location_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->dock_location_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->features_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->features_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->top_level_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->top_level_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->visibility_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->visibility_changed_func);
			KNH_SIZEREF(ctx);
		}
	}
}

static int QDockWidget_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQDockWidget::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQDockWidget::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
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

