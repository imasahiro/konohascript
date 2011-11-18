//@Virtual @Override boolean QApplication.notify(QObject receiver, QEvent e);

//QApplication QApplication.new(int argc, String argv);
KMETHOD QApplication_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int dummy = 0;
	char **argv = (char **)malloc(1 * sizeof(char *));
	memset(argv, 0, sizeof(char *));
//	QApplication *app = new QApplication(dummy, argv);
	KQApplication *app = new KQApplication(dummy, argv);
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, app, NULL);
	app->setSelf(p);
	RETURN_(p);
}

/*
//QApplication QApplication.new(int argc, String argv, boolean GUIenabled);
KMETHOD QApplication_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int dummy = 0;
	char **argv = (char **)malloc(1 * sizeof(char *));
	memset(argv, 0, sizeof(char *));
//	QApplication *app = new QApplication(dummy, argv);
	KQApplication *app = new KQApplication(dummy, argv);
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, app, NULL);
	app->setSelf(p);
	RETURN_(p);
}
*/
/*
//QApplication QApplication.new(int argc, String argv, int type);
KMETHOD QApplication_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	int dummy = 0;
	char **argv = (char **)malloc(1 * sizeof(char *));
	memset(argv, 0, sizeof(char *));
//	QApplication *app = new QApplication(dummy, argv);
	KQApplication *app = new KQApplication(dummy, argv);
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, app, NULL);
	app->setSelf(p);
	RETURN_(p);
}
*/
//QInputContext QApplication.getInputContext();

//boolean QApplication.isSessionRestored();

//String QApplication.sessionId();

//String QApplication.sessionKey();

//void QApplication.setInputContext(QInputContext inputContext);

//String QApplication.getStyleSheet();

//QWidget QApplication.activeModalWidget();

//QWidget QApplication.activePopupWidget();

//QWidget QApplication.getActiveWindow();

//void QApplication.alert(QWidget widget, int msec);

//QWidgetList QApplication.allWidgets();

//void QApplication.beep();

//void QApplication.changeOverrideCursor(QCursor cursor);

//QClipboard QApplication.clipboard();

//int QApplication.getColorSpec();

//int QApplication.getCursorFlashTime();

//QDesktopWidget QApplication.desktop();

//boolean QApplication.getDesktopSettingsAware();

//int QApplication.getDoubleClickInterval();

//int QApplication.exec();
KMETHOD QApplication_exec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		exec_flag = true;
		int ret_v = QApplication::exec();
//		fprintf(stderr, "exec end\n");
		exec_flag = false;
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWidget QApplication.focusWidget();

//QFont QApplication.getFont();

/*
//QFont QApplication.getFont(QWidget widget);
*/
/*
//QFont QApplication.getFont(String className);
*/
//QFontMetrics QApplication.fontMetrics();

//QSize QApplication.getGlobalStrut();

//boolean QApplication.isEffectEnabled(int effect);

//boolean QApplication.isLeftToRight();

//boolean QApplication.isRightToLeft();

//int QApplication.keyboardInputDirection();

//int QApplication.getKeyboardInputInterval();

//QLocale QApplication.keyboardInputLocale();

//QtKeyboardModifiers QApplication.keyboardModifiers();

//int QApplication.getLayoutDirection();

//QtMouseButtons QApplication.mouseButtons();

//QCursor QApplication.getOverrideCursor();

//QPalette QApplication.getPalette();

/*
//QPalette QApplication.getPalette(QWidget widget);
*/
/*
//QPalette QApplication.getPalette(String className);
*/
//boolean QApplication.getQuitOnLastWindowClosed();

//void QApplication.restoreOverrideCursor();

//void QApplication.setActiveWindow(QWidget active);

//void QApplication.setColorSpec(int spec);

//void QApplication.setCursorFlashTime(int arg0);

//void QApplication.setDesktopSettingsAware(boolean on);

//void QApplication.setDoubleClickInterval(int arg0);

//void QApplication.setEffectEnabled(int effect, boolean enable);

//void QApplication.setFont(QFont font, String className);

//void QApplication.setGlobalStrut(QSize arg0);

//void QApplication.setGraphicsSystem(String system);

//void QApplication.setKeyboardInputInterval(int arg0);

//void QApplication.setLayoutDirection(int direction);

//void QApplication.setOverrideCursor(QCursor cursor);

//void QApplication.setPalette(QPalette palette, String className);

//void QApplication.setQuitOnLastWindowClosed(boolean quit);

//void QApplication.setStartDragDistance(int l);

//void QApplication.setStartDragTime(int ms);

//void QApplication.setStyle(QStyle style);

/*
//QStyle QApplication.setStyle(String style);
*/
//void QApplication.setWheelScrollLines(int arg0);

//void QApplication.setWindowIcon(QIcon icon);

//int QApplication.getStartDragDistance();

//int QApplication.getStartDragTime();

//QStyle QApplication.getStyle();

//void QApplication.syncX();

//QWidget QApplication.topLevelAt(QPoint point);

/*
//QWidget QApplication.topLevelAt(int x, int y);
*/
//QWidgetList QApplication.topLevelWidgets();

//int QApplication.type();

//int QApplication.getWheelScrollLines();

//QWidget QApplication.widgetAt(QPoint point);

/*
//QWidget QApplication.widgetAt(int x, int y);
*/
//QIcon QApplication.getWindowIcon();

//void QApplication.aboutQt();

//boolean QApplication.getAutoSipEnabled();

//void QApplication.closeAllWindows();

//void QApplication.setAutoSipEnabled(boolean enabled);

//void QApplication.setStyleSheet(String sheet);


DummyQApplication::DummyQApplication()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	focus_changed_func = NULL;
	font_database_changed_func = NULL;
	last_window_closed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("focus-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("font-database-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("last-window-closed", NULL));
}
DummyQApplication::~DummyQApplication()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQApplication::setSelf(knh_RawPtr_t *ptr)
{
	DummyQApplication::self = ptr;
	DummyQCoreApplication::setSelf(ptr);
}

bool DummyQApplication::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQCoreApplication::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQApplication::focusChangedSlot(QWidget* old, QWidget* now)
{
	if (focus_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QWidget, old);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_RawPtr_t *p2 = new_QRawPtr(lctx, QWidget, now);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		knh_Func_invoke(lctx, focus_changed_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQApplication::fontDatabaseChangedSlot()
{
	if (font_database_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, font_database_changed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQApplication::lastWindowClosedSlot()
{
	if (last_window_closed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, last_window_closed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQApplication::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQApplication::event_map->bigin();
	if ((itr = DummyQApplication::event_map->find(str)) == DummyQApplication::event_map->end()) {
		bool ret = false;
		ret = DummyQCoreApplication::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQApplication::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQApplication::slot_map->bigin();
	if ((itr = DummyQApplication::slot_map->find(str)) == DummyQApplication::slot_map->end()) {
		bool ret = false;
		ret = DummyQCoreApplication::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		focus_changed_func = (*slot_map)["focus-changed"];
		font_database_changed_func = (*slot_map)["font-database-changed"];
		last_window_closed_func = (*slot_map)["last-window-closed"];
		return true;
	}
}

knh_Object_t** DummyQApplication::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQApplication::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 4;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, focus_changed_func);
	KNH_ADDNNREF(ctx, font_database_changed_func);
	KNH_ADDNNREF(ctx, last_window_closed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQCoreApplication::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQApplication::connection(QObject *o)
{
	QApplication *p = dynamic_cast<QApplication*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(focusChanged(QWidget*, QWidget*)), this, SLOT(focusChangedSlot(QWidget*, QWidget*)));
		connect(p, SIGNAL(fontDatabaseChanged()), this, SLOT(fontDatabaseChangedSlot()));
		connect(p, SIGNAL(lastWindowClosed()), this, SLOT(lastWindowClosedSlot()));
	}
	DummyQCoreApplication::connection(o);
}

KQApplication::KQApplication(int argc, char** argv) : QApplication(argc, argv)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQApplication();
	dummy->connection((QObject*)this);
}

KQApplication::~KQApplication()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QApplication_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQApplication *qp = RawPtr_to(KQApplication *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QApplication]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QApplication]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QApplication_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQApplication *qp = RawPtr_to(KQApplication *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QApplication]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QApplication]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QApplication_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQApplication *qp = (KQApplication *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QApplication*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QApplication_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQApplication *qp = (KQApplication *)p->rawptr;
		KQApplication *qp = static_cast<KQApplication*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QApplication_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQApplication::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQApplication::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QApplication::event(event);
		return false;
	}
//	QApplication::event(event);
	return true;
}

static knh_IntData_t QApplicationConstInt[] = {
	{"NormalColor", QApplication::NormalColor},
	{"CustomColor", QApplication::CustomColor},
	{"ManyColor", QApplication::ManyColor},
	{"Tty", QApplication::Tty},
	{"GuiClient", QApplication::GuiClient},
	{"GuiServer", QApplication::GuiServer},
	{NULL, 0}
};

DEFAPI(void) constQApplication(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QApplicationConstInt);
}


DEFAPI(void) defQApplication(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QApplication";
	cdef->free = QApplication_free;
	cdef->reftrace = QApplication_reftrace;
	cdef->compareTo = QApplication_compareTo;
}


