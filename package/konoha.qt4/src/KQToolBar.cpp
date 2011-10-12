//QToolBar QToolBar.new(String title, QWidget parent);
KMETHOD QToolBar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString title = String_to(const QString, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQToolBar *ret_v = new KQToolBar(title, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QToolBar QToolBar.new(QWidget parent);
KMETHOD QToolBar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQToolBar *ret_v = new KQToolBar(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QAction QToolBar.actionAt(QPoint p);
KMETHOD QToolBar_actionAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		const QPoint  p = *RawPtr_to(const QPoint *, sfp[1]);
		QAction* ret_v = qp->actionAt(p);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QAction QToolBar.actionAt(int x, int y);
KMETHOD QToolBar_actionAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		QAction* ret_v = qp->actionAt(x, y);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
////void QToolBar.addAction(QAction action);
KMETHOD QToolBar_addAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		QAction*  action = RawPtr_to(QAction*, sfp[1]);
		qp->addAction(action);
	}
	RETURNvoid_();
}

/*
////QAction QToolBar.addAction(String text);
KMETHOD QToolBar_addAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		const QString text = String_to(const QString, sfp[1]);
		QAction* ret_v = qp->addAction(text);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
////QAction QToolBar.addAction(QIcon icon, String text);
KMETHOD QToolBar_addAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		QAction* ret_v = qp->addAction(icon, text);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
////QAction QToolBar.addAction(String text, QObject receiver, String member);
KMETHOD QToolBar_addAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		const QString text = String_to(const QString, sfp[1]);
		const QObject*  receiver = RawPtr_to(const QObject*, sfp[2]);
		const char*  member = RawPtr_to(const char*, sfp[3]);
		QAction* ret_v = qp->addAction(text, receiver, member);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
////QAction QToolBar.addAction(QIcon icon, String text, QObject receiver, String member);
KMETHOD QToolBar_addAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		const QObject*  receiver = RawPtr_to(const QObject*, sfp[3]);
		const char*  member = RawPtr_to(const char*, sfp[4]);
		QAction* ret_v = qp->addAction(icon, text, receiver, member);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QAction QToolBar.addSeparator();
KMETHOD QToolBar_addSeparator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		QAction* ret_v = qp->addSeparator();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAction QToolBar.addWidget(QWidget widget);
KMETHOD QToolBar_addWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		QAction* ret_v = qp->addWidget(widget);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QToolBar.getAllowedAreas();
KMETHOD QToolBar_getAllowedAreas(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		Qt::ToolBarAreas ret_v = qp->allowedAreas();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QToolBar.clear();
KMETHOD QToolBar_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		qp->clear();
	}
	RETURNvoid_();
}

//QSize QToolBar.getIconSize();
KMETHOD QToolBar_getIconSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->iconSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAction QToolBar.insertSeparator(QAction before);
KMETHOD QToolBar_insertSeparator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		QAction*  before = RawPtr_to(QAction*, sfp[1]);
		QAction* ret_v = qp->insertSeparator(before);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAction QToolBar.insertWidget(QAction before, QWidget widget);
KMETHOD QToolBar_insertWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		QAction*  before = RawPtr_to(QAction*, sfp[1]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[2]);
		QAction* ret_v = qp->insertWidget(before, widget);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QToolBar.isAreaAllowed(int area);
KMETHOD QToolBar_isAreaAllowed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		Qt::ToolBarArea area = Int_to(Qt::ToolBarArea, sfp[1]);
		bool ret_v = qp->isAreaAllowed(area);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QToolBar.isFloatable();
KMETHOD QToolBar_isFloatable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isFloatable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QToolBar.isFloating();
KMETHOD QToolBar_isFloating(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isFloating();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QToolBar.isMovable();
KMETHOD QToolBar_isMovable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isMovable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QToolBar.getOrientation();
KMETHOD QToolBar_getOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		Qt::Orientation ret_v = qp->orientation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QToolBar.setAllowedAreas(int areas);
KMETHOD QToolBar_setAllowedAreas(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		Qt::ToolBarAreas areas = Int_to(Qt::ToolBarAreas, sfp[1]);
		qp->setAllowedAreas(areas);
	}
	RETURNvoid_();
}

//void QToolBar.setFloatable(boolean floatable);
KMETHOD QToolBar_setFloatable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		bool floatable = Boolean_to(bool, sfp[1]);
		qp->setFloatable(floatable);
	}
	RETURNvoid_();
}

//void QToolBar.setMovable(boolean movable);
KMETHOD QToolBar_setMovable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		bool movable = Boolean_to(bool, sfp[1]);
		qp->setMovable(movable);
	}
	RETURNvoid_();
}

//void QToolBar.setOrientation(int orientation);
KMETHOD QToolBar_setOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
		qp->setOrientation(orientation);
	}
	RETURNvoid_();
}

//QAction QToolBar.toggleViewAction();
KMETHOD QToolBar_toggleViewAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		QAction* ret_v = qp->toggleViewAction();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QToolBar.getToolButtonStyle();
KMETHOD QToolBar_getToolButtonStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		Qt::ToolButtonStyle ret_v = qp->toolButtonStyle();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWidget QToolBar.widgetForAction(QAction action);
KMETHOD QToolBar_widgetForAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		QAction*  action = RawPtr_to(QAction*, sfp[1]);
		QWidget* ret_v = qp->widgetForAction(action);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QToolBar.setIconSize(QSize iconSize);
KMETHOD QToolBar_setIconSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		const QSize  iconSize = *RawPtr_to(const QSize *, sfp[1]);
		qp->setIconSize(iconSize);
	}
	RETURNvoid_();
}

//void QToolBar.setToolButtonStyle(int toolButtonStyle);
KMETHOD QToolBar_setToolButtonStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolBar *  qp = RawPtr_to(QToolBar *, sfp[0]);
	if (qp != NULL) {
		Qt::ToolButtonStyle toolButtonStyle = Int_to(Qt::ToolButtonStyle, sfp[1]);
		qp->setToolButtonStyle(toolButtonStyle);
	}
	RETURNvoid_();
}


DummyQToolBar::DummyQToolBar()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQToolBar::setSelf(knh_RawPtr_t *ptr)
{
	DummyQToolBar::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQToolBar::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQToolBar::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQToolBar::event_map->bigin();
	if ((itr = DummyQToolBar::event_map->find(str)) == DummyQToolBar::event_map->end()) {
		bool ret;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQToolBar::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQToolBar::slot_map->bigin();
	if ((itr = DummyQToolBar::event_map->find(str)) == DummyQToolBar::slot_map->end()) {
		bool ret;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQToolBar::KQToolBar(const QString title, QWidget* parent) : QToolBar(title, parent)
{
	self = NULL;
}

KMETHOD QToolBar_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQToolBar *qp = RawPtr_to(KQToolBar *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QToolBar]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQToolBar::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QToolBar]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QToolBar_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQToolBar *qp = RawPtr_to(KQToolBar *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QToolBar]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQToolBar::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QToolBar]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QToolBar_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQToolBar *qp = (KQToolBar *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QToolBar_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQToolBar *qp = (KQToolBar *)p->rawptr;
		(void)qp;
	}
}

static int QToolBar_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQToolBar::event(QEvent *event)
{
	if (!DummyQToolBar::eventDispatcher(event)) {
		QToolBar::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQToolBar(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QToolBar";
	cdef->free = QToolBar_free;
	cdef->reftrace = QToolBar_reftrace;
	cdef->compareTo = QToolBar_compareTo;
}


