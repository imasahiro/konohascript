//QAction QAction.new(QObject parent);
KMETHOD QAction_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQAction *ret_v = new KQAction(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QAction QAction.new(String text, QObject parent);
KMETHOD QAction_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString text = String_to(const QString, sfp[1]);
	QObject*  parent = RawPtr_to(QObject*, sfp[2]);
	KQAction *ret_v = new KQAction(text, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QAction QAction.new(QIcon icon, String text, QObject parent);
KMETHOD QAction_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
	const QString text = String_to(const QString, sfp[2]);
	QObject*  parent = RawPtr_to(QObject*, sfp[3]);
	KQAction *ret_v = new KQAction(icon, text, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QActionGroup QAction.getActionGroup();
KMETHOD QAction_getActionGroup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QActionGroup* ret_v = qp->actionGroup();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QActionGroup*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QAction.activate(int event);
KMETHOD QAction_activate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QAction::ActionEvent event = Int_to(QAction::ActionEvent, sfp[1]);
		qp->activate(event);
	}
	RETURNvoid_();
}

//Array<QGraphicsWidget> QAction.associatedGraphicsWidgets();
KMETHOD QAction_associatedGraphicsWidgets(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QList<QGraphicsWidget*> ret_v = qp->associatedGraphicsWidgets();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QGraphicsWidget"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//Array<QWidget> QAction.associatedWidgets();
KMETHOD QAction_associatedWidgets(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QList<QWidget*> ret_v = qp->associatedWidgets();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QWidget"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//boolean QAction.getAutoRepeat();
KMETHOD QAction_getAutoRepeat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		bool ret_v = qp->autoRepeat();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QVariant QAction.getData();
KMETHOD QAction_getData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QVariant ret_v = qp->data();
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFont QAction.getFont();
KMETHOD QAction_getFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QFont ret_v = qp->font();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QIcon QAction.getIcon();
KMETHOD QAction_getIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QIcon ret_v = qp->icon();
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QAction.getIconText();
KMETHOD QAction_getIconText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QString ret_v = qp->iconText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QAction.isCheckable();
KMETHOD QAction_isCheckable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isCheckable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAction.isChecked();
KMETHOD QAction_isChecked(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isChecked();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAction.isEnabled();
KMETHOD QAction_isEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAction.isIconVisibleInMenu();
KMETHOD QAction_isIconVisibleInMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isIconVisibleInMenu();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAction.isSeparator();
KMETHOD QAction_isSeparator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSeparator();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAction.isVisible();
KMETHOD QAction_isVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isVisible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QMenu QAction.getMenu();
KMETHOD QAction_getMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QMenu* ret_v = qp->menu();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMenu*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QAction.getMenuRole();
KMETHOD QAction_getMenuRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QAction::MenuRole ret_v = qp->menuRole();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWidget QAction.parentWidget();
KMETHOD QAction_parentWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->parentWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QAction.getPriority();
KMETHOD QAction_getPriority(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QAction::Priority ret_v = qp->priority();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QAction.setActionGroup(QActionGroup group);
KMETHOD QAction_setActionGroup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QActionGroup*  group = RawPtr_to(QActionGroup*, sfp[1]);
		qp->setActionGroup(group);
	}
	RETURNvoid_();
}

//void QAction.setAutoRepeat(boolean arg0);
KMETHOD QAction_setAutoRepeat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setAutoRepeat(arg0);
	}
	RETURNvoid_();
}

//void QAction.setCheckable(boolean arg0);
KMETHOD QAction_setCheckable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setCheckable(arg0);
	}
	RETURNvoid_();
}

//void QAction.setData(QVariant userData);
KMETHOD QAction_setData(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		const QVariant  userData = *RawPtr_to(const QVariant *, sfp[1]);
		qp->setData(userData);
	}
	RETURNvoid_();
}

//void QAction.setFont(QFont font);
KMETHOD QAction_setFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
		qp->setFont(font);
	}
	RETURNvoid_();
}

//void QAction.setIcon(QIcon icon);
KMETHOD QAction_setIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
		qp->setIcon(icon);
	}
	RETURNvoid_();
}

//void QAction.setIconText(String text);
KMETHOD QAction_setIconText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setIconText(text);
	}
	RETURNvoid_();
}

//void QAction.setIconVisibleInMenu(boolean visible);
KMETHOD QAction_setIconVisibleInMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setIconVisibleInMenu(visible);
	}
	RETURNvoid_();
}

//void QAction.setMenu(QMenu menu);
KMETHOD QAction_setMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QMenu*  menu = RawPtr_to(QMenu*, sfp[1]);
		qp->setMenu(menu);
	}
	RETURNvoid_();
}

//void QAction.setMenuRole(int menuRole);
KMETHOD QAction_setMenuRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QAction::MenuRole menuRole = Int_to(QAction::MenuRole, sfp[1]);
		qp->setMenuRole(menuRole);
	}
	RETURNvoid_();
}

//void QAction.setPriority(int priority);
KMETHOD QAction_setPriority(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QAction::Priority priority = Int_to(QAction::Priority, sfp[1]);
		qp->setPriority(priority);
	}
	RETURNvoid_();
}

//void QAction.setSeparator(boolean b);
KMETHOD QAction_setSeparator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		bool b = Boolean_to(bool, sfp[1]);
		qp->setSeparator(b);
	}
	RETURNvoid_();
}

//void QAction.setShortcut(QKeySequence shortcut);
KMETHOD QAction_setShortcut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		const QKeySequence  shortcut = *RawPtr_to(const QKeySequence *, sfp[1]);
		qp->setShortcut(shortcut);
	}
	RETURNvoid_();
}

//void QAction.setShortcutContext(int context);
KMETHOD QAction_setShortcutContext(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		Qt::ShortcutContext context = Int_to(Qt::ShortcutContext, sfp[1]);
		qp->setShortcutContext(context);
	}
	RETURNvoid_();
}

//void QAction.setShortcuts(Array<QKeySequence> shortcuts);
KMETHOD QAction_setShortcuts(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QKeySequence> shortcuts;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			shortcuts.append(*(QKeySequence*)p->rawptr);
		}
		qp->setShortcuts(shortcuts);
	}
	RETURNvoid_();
}

/*
//void QAction.setShortcuts(int key);
KMETHOD QAction_setShortcuts(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QKeySequence::StandardKey key = Int_to(QKeySequence::StandardKey, sfp[1]);
		qp->setShortcuts(key);
	}
	RETURNvoid_();
}
*/
//void QAction.setSoftKeyRole(int softKeyRole);
KMETHOD QAction_setSoftKeyRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QAction::SoftKeyRole softKeyRole = Int_to(QAction::SoftKeyRole, sfp[1]);
		qp->setSoftKeyRole(softKeyRole);
	}
	RETURNvoid_();
}

//void QAction.setStatusTip(String statusTip);
KMETHOD QAction_setStatusTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		const QString statusTip = String_to(const QString, sfp[1]);
		qp->setStatusTip(statusTip);
	}
	RETURNvoid_();
}

//void QAction.setText(String text);
KMETHOD QAction_setText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setText(text);
	}
	RETURNvoid_();
}

//void QAction.setToolTip(String tip);
KMETHOD QAction_setToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		const QString tip = String_to(const QString, sfp[1]);
		qp->setToolTip(tip);
	}
	RETURNvoid_();
}

//void QAction.setWhatsThis(String what);
KMETHOD QAction_setWhatsThis(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		const QString what = String_to(const QString, sfp[1]);
		qp->setWhatsThis(what);
	}
	RETURNvoid_();
}

//QKeySequence QAction.getShortcut();
KMETHOD QAction_getShortcut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QKeySequence ret_v = qp->shortcut();
		QKeySequence *ret_v_ = new QKeySequence(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QAction.getShortcutContext();
KMETHOD QAction_getShortcutContext(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		Qt::ShortcutContext ret_v = qp->shortcutContext();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<QKeySequence> QAction.getShortcuts();
KMETHOD QAction_getShortcuts(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QList<QKeySequence> ret_v = qp->shortcuts();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QKeySequence"));
		for (int n = 0; n < list_size; n++) {
			QKeySequence *ret_v_ = new QKeySequence(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//boolean QAction.showStatusText(QWidget widget);
KMETHOD QAction_showStatusText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		bool ret_v = qp->showStatusText(widget);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QAction.getSoftKeyRole();
KMETHOD QAction_getSoftKeyRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QAction::SoftKeyRole ret_v = qp->softKeyRole();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QAction.getStatusTip();
KMETHOD QAction_getStatusTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QString ret_v = qp->statusTip();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QAction.getText();
KMETHOD QAction_getText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QString ret_v = qp->text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QAction.getToolTip();
KMETHOD QAction_getToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QString ret_v = qp->toolTip();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QAction.getWhatsThis();
KMETHOD QAction_getWhatsThis(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		QString ret_v = qp->whatsThis();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QAction.hover();
KMETHOD QAction_hover(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		qp->hover();
	}
	RETURNvoid_();
}

//void QAction.setChecked(boolean arg0);
KMETHOD QAction_setChecked(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setChecked(arg0);
	}
	RETURNvoid_();
}

//void QAction.setDisabled(boolean b);
KMETHOD QAction_setDisabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		bool b = Boolean_to(bool, sfp[1]);
		qp->setDisabled(b);
	}
	RETURNvoid_();
}

//void QAction.setEnabled(boolean arg0);
KMETHOD QAction_setEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setEnabled(arg0);
	}
	RETURNvoid_();
}

//void QAction.setVisible(boolean arg0);
KMETHOD QAction_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setVisible(arg0);
	}
	RETURNvoid_();
}

//void QAction.toggle();
KMETHOD QAction_toggle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		qp->toggle();
	}
	RETURNvoid_();
}

//void QAction.trigger();
KMETHOD QAction_trigger(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAction *  qp = RawPtr_to(QAction *, sfp[0]);
	if (qp) {
		qp->trigger();
	}
	RETURNvoid_();
}


DummyQAction::DummyQAction()
{
	self = NULL;
	changed_func = NULL;
	hovered_func = NULL;
	toggled_func = NULL;
	triggered_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("hovered", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("toggled", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("triggered", NULL));
}

void DummyQAction::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAction::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQAction::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAction::changedSlot()
{
	if (changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAction::hoveredSlot()
{
	if (hovered_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, hovered_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAction::toggledSlot(bool checked)
{
	if (toggled_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = checked;
		knh_Func_invoke(lctx, toggled_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQAction::triggeredSlot(bool checked)
{
	if (triggered_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = checked;
		knh_Func_invoke(lctx, triggered_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQAction::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAction::event_map->bigin();
	if ((itr = DummyQAction::event_map->find(str)) == DummyQAction::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAction::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAction::slot_map->bigin();
	if ((itr = DummyQAction::slot_map->find(str)) == DummyQAction::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		changed_func = (*slot_map)["changed"];
		hovered_func = (*slot_map)["hovered"];
		toggled_func = (*slot_map)["toggled"];
		triggered_func = (*slot_map)["triggered"];
		return true;
	}
}

void DummyQAction::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 4;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, changed_func);
	KNH_ADDNNREF(ctx, hovered_func);
	KNH_ADDNNREF(ctx, toggled_func);
	KNH_ADDNNREF(ctx, triggered_func);

	KNH_SIZEREF(ctx);

	DummyQObject::reftrace(ctx, p, tail_);
}

void DummyQAction::connection(QObject *o)
{
	QAction *p = dynamic_cast<QAction*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(changed()), this, SLOT(changedSlot()));
		connect(p, SIGNAL(hovered()), this, SLOT(hoveredSlot()));
		connect(p, SIGNAL(toggled(bool)), this, SLOT(toggledSlot(bool)));
		connect(p, SIGNAL(triggered(bool)), this, SLOT(triggeredSlot(bool)));
	}
	DummyQObject::connection(o);
}

KQAction::KQAction(QObject* parent) : QAction(parent)
{
	self = NULL;
	dummy = new DummyQAction();
	dummy->connection((QObject*)this);
}

KMETHOD QAction_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAction *qp = RawPtr_to(KQAction *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAction]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAction]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAction_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAction *qp = RawPtr_to(KQAction *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAction]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAction]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAction_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAction *qp = (KQAction *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAction_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQAction *qp = (KQAction *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAction_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAction::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQAction::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QAction::event(event);
		return false;
	}
	return true;
}

static knh_IntData_t QActionConstInt[] = {
	{"Trigger", QAction::Trigger},
	{"Hover", QAction::Hover},
	{"NoRole", QAction::NoRole},
	{"TextHeuristicRole", QAction::TextHeuristicRole},
	{"ApplicationSpecificRole", QAction::ApplicationSpecificRole},
	{"AboutQtRole", QAction::AboutQtRole},
	{"AboutRole", QAction::AboutRole},
	{"PreferencesRole", QAction::PreferencesRole},
	{"QuitRole", QAction::QuitRole},
	{"LowPriority", QAction::LowPriority},
	{"NormalPriority", QAction::NormalPriority},
	{"HighPriority", QAction::HighPriority},
	{"NoSoftKey", QAction::NoSoftKey},
	{"PositiveSoftKey", QAction::PositiveSoftKey},
	{"NegativeSoftKey", QAction::NegativeSoftKey},
	{"SelectSoftKey", QAction::SelectSoftKey},
	{NULL, 0}
};

DEFAPI(void) constQAction(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QActionConstInt);
}


DEFAPI(void) defQAction(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAction";
	cdef->free = QAction_free;
	cdef->reftrace = QAction_reftrace;
	cdef->compareTo = QAction_compareTo;
}


