//@Virtual @Override QSize QMenu.sizeHint();
KMETHOD QMenu_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QMenu QMenu.new(QWidget parent);
KMETHOD QMenu_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQMenu *ret_v = new KQMenu(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QMenu QMenu.new(String title, QWidget parent);
KMETHOD QMenu_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString title = String_to(const QString, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQMenu *ret_v = new KQMenu(title, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QAction QMenu.actionAt(QPoint pt);
KMETHOD QMenu_actionAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		const QPoint  pt = *RawPtr_to(const QPoint *, sfp[1]);
		QAction* ret_v = qp->actionAt(pt);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QMenu.actionGeometry(QAction act);
KMETHOD QMenu_actionGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		QAction*  act = RawPtr_to(QAction*, sfp[1]);
		QRect ret_v = qp->actionGeometry(act);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAction QMenu.getActiveAction();
KMETHOD QMenu_getActiveAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		QAction* ret_v = qp->activeAction();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

////QAction QMenu.addAction(String text);
KMETHOD QMenu_addAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		const QString text = String_to(const QString, sfp[1]);
		QAction* ret_v = qp->addAction(text);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
////QAction QMenu.addAction(QIcon icon, String text);
KMETHOD QMenu_addAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
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
////QAction QMenu.addAction(String text, QObject receiver, String member, QKeySequence shortcut);
KMETHOD QMenu_addAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		const QString text = String_to(const QString, sfp[1]);
		const QObject*  receiver = RawPtr_to(const QObject*, sfp[2]);
		const char*  member = RawPtr_to(const char*, sfp[3]);
		const QKeySequence  shortcut = *RawPtr_to(const QKeySequence *, sfp[4]);
		QAction* ret_v = qp->addAction(text, receiver, member, shortcut);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
////QAction QMenu.addAction(QIcon icon, String text, QObject receiver, String member, QKeySequence shortcut);
KMETHOD QMenu_addAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		const QObject*  receiver = RawPtr_to(const QObject*, sfp[3]);
		const char*  member = RawPtr_to(const char*, sfp[4]);
		const QKeySequence  shortcut = *RawPtr_to(const QKeySequence *, sfp[5]);
		QAction* ret_v = qp->addAction(icon, text, receiver, member, shortcut);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
////void QMenu.addAction(QAction action);
KMETHOD QMenu_addAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		QAction*  action = RawPtr_to(QAction*, sfp[1]);
		qp->addAction(action);
	}
	RETURNvoid_();
}
*/
//QAction QMenu.addMenu(QMenu menu);
KMETHOD QMenu_addMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		QMenu*  menu = RawPtr_to(QMenu*, sfp[1]);
		QAction* ret_v = qp->addMenu(menu);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QMenu QMenu.addMenu(String title);
KMETHOD QMenu_addMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		const QString title = String_to(const QString, sfp[1]);
		QMenu* ret_v = qp->addMenu(title);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMenu*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QMenu QMenu.addMenu(QIcon icon, String title);
KMETHOD QMenu_addMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
		const QString title = String_to(const QString, sfp[2]);
		QMenu* ret_v = qp->addMenu(icon, title);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMenu*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QAction QMenu.addSeparator();
KMETHOD QMenu_addSeparator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		QAction* ret_v = qp->addSeparator();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QMenu.clear();
KMETHOD QMenu_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		qp->clear();
	}
	RETURNvoid_();
}

//QAction QMenu.exec();
KMETHOD QMenu_exec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		QAction* ret_v = qp->exec();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QAction QMenu.exec(QPoint p, QAction action);
KMETHOD QMenu_exec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		const QPoint  p = *RawPtr_to(const QPoint *, sfp[1]);
		QAction*  action = RawPtr_to(QAction*, sfp[2]);
		QAction* ret_v = qp->exec(p, action);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//void QMenu.hideTearOffMenu();
KMETHOD QMenu_hideTearOffMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		qp->hideTearOffMenu();
	}
	RETURNvoid_();
}

//QIcon QMenu.getIcon();
KMETHOD QMenu_getIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		QIcon ret_v = qp->icon();
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAction QMenu.insertMenu(QAction before, QMenu menu);
KMETHOD QMenu_insertMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		QAction*  before = RawPtr_to(QAction*, sfp[1]);
		QMenu*  menu = RawPtr_to(QMenu*, sfp[2]);
		QAction* ret_v = qp->insertMenu(before, menu);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAction QMenu.insertSeparator(QAction before);
KMETHOD QMenu_insertSeparator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		QAction*  before = RawPtr_to(QAction*, sfp[1]);
		QAction* ret_v = qp->insertSeparator(before);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QMenu.isEmpty();
KMETHOD QMenu_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMenu.isTearOffEnabled();
KMETHOD QMenu_isTearOffEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isTearOffEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMenu.isTearOffMenuVisible();
KMETHOD QMenu_isTearOffMenuVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isTearOffMenuVisible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QAction QMenu.menuAction();
KMETHOD QMenu_menuAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		QAction* ret_v = qp->menuAction();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QMenu.popup(QPoint p, QAction atAction);
KMETHOD QMenu_popup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		const QPoint  p = *RawPtr_to(const QPoint *, sfp[1]);
		QAction*  atAction = RawPtr_to(QAction*, sfp[2]);
		qp->popup(p, atAction);
	}
	RETURNvoid_();
}

//boolean QMenu.getSeparatorsCollapsible();
KMETHOD QMenu_getSeparatorsCollapsible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->separatorsCollapsible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QMenu.setActiveAction(QAction act);
KMETHOD QMenu_setActiveAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		QAction*  act = RawPtr_to(QAction*, sfp[1]);
		qp->setActiveAction(act);
	}
	RETURNvoid_();
}

//void QMenu.setIcon(QIcon icon);
KMETHOD QMenu_setIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
		qp->setIcon(icon);
	}
	RETURNvoid_();
}

//void QMenu.setSeparatorsCollapsible(boolean collapse);
KMETHOD QMenu_setSeparatorsCollapsible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		bool collapse = Boolean_to(bool, sfp[1]);
		qp->setSeparatorsCollapsible(collapse);
	}
	RETURNvoid_();
}

//void QMenu.setTearOffEnabled(boolean arg0);
KMETHOD QMenu_setTearOffEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setTearOffEnabled(arg0);
	}
	RETURNvoid_();
}

//void QMenu.setTitle(String title);
KMETHOD QMenu_setTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		const QString title = String_to(const QString, sfp[1]);
		qp->setTitle(title);
	}
	RETURNvoid_();
}

//String QMenu.getTitle();
KMETHOD QMenu_getTitle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->title();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QAction QMenu.exec(Array<QAction> actions, QPoint pos, QAction at, QWidget parent);
KMETHOD QMenu_exec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QAction*> actions;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			actions.append((QAction*)p->rawptr);
		}
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[2]);
		QAction*  at = RawPtr_to(QAction*, sfp[3]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[4]);
		QAction* ret_v = qp->exec(actions, pos, at, parent);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QAction QMenu.exec(Array<QAction> actions, QPoint pos, QAction at);
KMETHOD QMenu_exec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenu *  qp = RawPtr_to(QMenu *, sfp[0]);
	if (qp != NULL) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QAction*> actions;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			actions.append((QAction*)p->rawptr);
		}
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[2]);
		QAction*  at = RawPtr_to(QAction*, sfp[3]);
		QAction* ret_v = qp->exec(actions, pos, at);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/

DummyQMenu::DummyQMenu()
{
	self = NULL;
	about_to_hide_func = NULL;
	about_to_show_func = NULL;
	hovered_func = NULL;
	triggered_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("about-to-hide", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("about-to-show", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("hovered", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("triggered", NULL));
}

void DummyQMenu::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMenu::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQMenu::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQMenu::aboutToHideSlot()
{
	if (about_to_hide_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, about_to_hide_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQMenu::aboutToShowSlot()
{
	if (about_to_show_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, about_to_show_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQMenu::hoveredSlot(QAction* action)
{
	if (hovered_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QAction, action);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, hovered_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQMenu::triggeredSlot(QAction* action)
{
	if (triggered_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QAction, action);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, triggered_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQMenu::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMenu::event_map->bigin();
	if ((itr = DummyQMenu::event_map->find(str)) == DummyQMenu::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMenu::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMenu::slot_map->bigin();
	if ((itr = DummyQMenu::slot_map->find(str)) == DummyQMenu::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		about_to_hide_func = (*slot_map)["about-to-hide"];
		about_to_show_func = (*slot_map)["about-to-show"];
		hovered_func = (*slot_map)["hovered"];
		triggered_func = (*slot_map)["triggered"];
		return true;
	}
}


void DummyQMenu::connection(QObject *o)
{
	connect(o, SIGNAL(aboutToHide()), this, SLOT(aboutToHideSlot()));
	connect(o, SIGNAL(aboutToShow()), this, SLOT(aboutToShowSlot()));
	connect(o, SIGNAL(hovered(QAction*)), this, SLOT(hoveredSlot(QAction*)));
	connect(o, SIGNAL(triggered(QAction*)), this, SLOT(triggeredSlot(QAction*)));
	DummyQWidget::connection(o);
}

KQMenu::KQMenu(QWidget* parent) : QMenu(parent)
{
	self = NULL;
	dummy = new DummyQMenu();
	dummy->connection((QObject*)this);
}

KMETHOD QMenu_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMenu *qp = RawPtr_to(KQMenu *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMenu]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMenu]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QMenu_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMenu *qp = RawPtr_to(KQMenu *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMenu]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMenu]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMenu_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMenu *qp = (KQMenu *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMenu_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 4;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQMenu *qp = (KQMenu *)p->rawptr;
//		(void)qp;
		if (qp->dummy->about_to_hide_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->about_to_hide_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->about_to_show_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->about_to_show_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->hovered_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->hovered_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->triggered_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->triggered_func);
			KNH_SIZEREF(ctx);
		}
	}
}

static int QMenu_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMenu::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQMenu::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QMenu::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQMenu(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMenu";
	cdef->free = QMenu_free;
	cdef->reftrace = QMenu_reftrace;
	cdef->compareTo = QMenu_compareTo;
}


