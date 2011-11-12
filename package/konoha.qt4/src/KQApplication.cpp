//@Virtual @Override boolean QApplication.notify(QObject receiver, QEvent e);
KMETHOD QApplication_notify(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QApplication *  qp = RawPtr_to(QApplication *, sfp[0]);
	if (qp) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		QEvent*  e = RawPtr_to(QEvent*, sfp[2]);
		bool ret_v = qp->notify(receiver, e);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

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
KMETHOD QApplication_getInputContext(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QApplication *  qp = RawPtr_to(QApplication *, sfp[0]);
	if (qp) {
		QInputContext* ret_v = qp->inputContext();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QInputContext*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QApplication.isSessionRestored();
KMETHOD QApplication_isSessionRestored(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QApplication *  qp = RawPtr_to(QApplication *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSessionRestored();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QApplication.sessionId();
KMETHOD QApplication_sessionId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QApplication *  qp = RawPtr_to(QApplication *, sfp[0]);
	if (qp) {
		QString ret_v = qp->sessionId();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QApplication.sessionKey();
KMETHOD QApplication_sessionKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QApplication *  qp = RawPtr_to(QApplication *, sfp[0]);
	if (qp) {
		QString ret_v = qp->sessionKey();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QApplication.setInputContext(QInputContext inputContext);
KMETHOD QApplication_setInputContext(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QApplication *  qp = RawPtr_to(QApplication *, sfp[0]);
	if (qp) {
		QInputContext*  inputContext = RawPtr_to(QInputContext*, sfp[1]);
		qp->setInputContext(inputContext);
	}
	RETURNvoid_();
}

//String QApplication.getStyleSheet();
KMETHOD QApplication_getStyleSheet(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QApplication *  qp = RawPtr_to(QApplication *, sfp[0]);
	if (qp) {
		QString ret_v = qp->styleSheet();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QApplication.activeModalWidget();
KMETHOD QApplication_activeModalWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidget* ret_v = QApplication::activeModalWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QApplication.activePopupWidget();
KMETHOD QApplication_activePopupWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidget* ret_v = QApplication::activePopupWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QApplication.getActiveWindow();
KMETHOD QApplication_getActiveWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidget* ret_v = QApplication::activeWindow();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QApplication.alert(QWidget widget, int msec);
KMETHOD QApplication_alert(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		int msec = Int_to(int, sfp[2]);
		QApplication::alert(widget, msec);
	}
	RETURNvoid_();
}

//QWidgetList QApplication.allWidgets();
KMETHOD QApplication_allWidgets(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidgetList ret_v = QApplication::allWidgets();
		QWidgetList *ret_v_ = new QWidgetList(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QApplication.beep();
KMETHOD QApplication_beep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QApplication::beep();
	}
	RETURNvoid_();
}

//void QApplication.changeOverrideCursor(QCursor cursor);
KMETHOD QApplication_changeOverrideCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QCursor  cursor = *RawPtr_to(const QCursor *, sfp[1]);
		QApplication::changeOverrideCursor(cursor);
	}
	RETURNvoid_();
}

//QClipboard QApplication.clipboard();
KMETHOD QApplication_clipboard(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QClipboard* ret_v = QApplication::clipboard();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QClipboard*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QApplication.getColorSpec();
KMETHOD QApplication_getColorSpec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int ret_v = QApplication::colorSpec();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QApplication.getCursorFlashTime();
KMETHOD QApplication_getCursorFlashTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int ret_v = QApplication::cursorFlashTime();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QDesktopWidget QApplication.desktop();
KMETHOD QApplication_desktop(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QDesktopWidget* ret_v = QApplication::desktop();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QDesktopWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QApplication.getDesktopSettingsAware();
KMETHOD QApplication_getDesktopSettingsAware(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QApplication::desktopSettingsAware();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QApplication.getDoubleClickInterval();
KMETHOD QApplication_getDoubleClickInterval(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int ret_v = QApplication::doubleClickInterval();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QApplication.exec();
KMETHOD QApplication_exec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int ret_v = QApplication::exec();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWidget QApplication.focusWidget();
KMETHOD QApplication_focusWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidget* ret_v = QApplication::focusWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFont QApplication.getFont();
KMETHOD QApplication_getFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QFont ret_v = QApplication::font();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QFont QApplication.getFont(QWidget widget);
KMETHOD QApplication_getFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[1]);
		QFont ret_v = QApplication::font(widget);
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QFont QApplication.getFont(String className);
KMETHOD QApplication_getFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const char*  className = RawPtr_to(const char*, sfp[1]);
		QFont ret_v = QApplication::font(className);
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QFontMetrics QApplication.fontMetrics();
KMETHOD QApplication_fontMetrics(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QFontMetrics ret_v = QApplication::fontMetrics();
		QFontMetrics *ret_v_ = new QFontMetrics(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSize QApplication.getGlobalStrut();
KMETHOD QApplication_getGlobalStrut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QSize ret_v = QApplication::globalStrut();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QApplication.isEffectEnabled(int effect);
KMETHOD QApplication_isEffectEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		Qt::UIEffect effect = Int_to(Qt::UIEffect, sfp[1]);
		bool ret_v = QApplication::isEffectEnabled(effect);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QApplication.isLeftToRight();
KMETHOD QApplication_isLeftToRight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QApplication::isLeftToRight();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QApplication.isRightToLeft();
KMETHOD QApplication_isRightToLeft(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QApplication::isRightToLeft();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QApplication.keyboardInputDirection();
KMETHOD QApplication_keyboardInputDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		Qt::LayoutDirection ret_v = QApplication::keyboardInputDirection();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QApplication.getKeyboardInputInterval();
KMETHOD QApplication_getKeyboardInputInterval(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int ret_v = QApplication::keyboardInputInterval();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QLocale QApplication.keyboardInputLocale();
KMETHOD QApplication_keyboardInputLocale(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QLocale ret_v = QApplication::keyboardInputLocale();
		QLocale *ret_v_ = new QLocale(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QtKeyboardModifiers QApplication.keyboardModifiers();
KMETHOD QApplication_keyboardModifiers(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		Qt::KeyboardModifiers ret_v = QApplication::keyboardModifiers();
		Qt::KeyboardModifiers *ret_v_ = new Qt::KeyboardModifiers(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QApplication.getLayoutDirection();
KMETHOD QApplication_getLayoutDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		Qt::LayoutDirection ret_v = QApplication::layoutDirection();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QtMouseButtons QApplication.mouseButtons();
KMETHOD QApplication_mouseButtons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		Qt::MouseButtons ret_v = QApplication::mouseButtons();
		Qt::MouseButtons *ret_v_ = new Qt::MouseButtons(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QCursor QApplication.getOverrideCursor();
KMETHOD QApplication_getOverrideCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QCursor* ret_v = QApplication::overrideCursor();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QCursor*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPalette QApplication.getPalette();
KMETHOD QApplication_getPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QPalette ret_v = QApplication::palette();
		QPalette *ret_v_ = new QPalette(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPalette QApplication.getPalette(QWidget widget);
KMETHOD QApplication_getPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[1]);
		QPalette ret_v = QApplication::palette(widget);
		QPalette *ret_v_ = new QPalette(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPalette QApplication.getPalette(String className);
KMETHOD QApplication_getPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const char*  className = RawPtr_to(const char*, sfp[1]);
		QPalette ret_v = QApplication::palette(className);
		QPalette *ret_v_ = new QPalette(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//boolean QApplication.getQuitOnLastWindowClosed();
KMETHOD QApplication_getQuitOnLastWindowClosed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QApplication::quitOnLastWindowClosed();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QApplication.restoreOverrideCursor();
KMETHOD QApplication_restoreOverrideCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QApplication::restoreOverrideCursor();
	}
	RETURNvoid_();
}

//void QApplication.setActiveWindow(QWidget active);
KMETHOD QApplication_setActiveWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidget*  active = RawPtr_to(QWidget*, sfp[1]);
		QApplication::setActiveWindow(active);
	}
	RETURNvoid_();
}

//void QApplication.setColorSpec(int spec);
KMETHOD QApplication_setColorSpec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int spec = Int_to(int, sfp[1]);
		QApplication::setColorSpec(spec);
	}
	RETURNvoid_();
}

//void QApplication.setCursorFlashTime(int arg0);
KMETHOD QApplication_setCursorFlashTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int arg0 = Int_to(int, sfp[1]);
		QApplication::setCursorFlashTime(arg0);
	}
	RETURNvoid_();
}

//void QApplication.setDesktopSettingsAware(boolean on);
KMETHOD QApplication_setDesktopSettingsAware(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool on = Boolean_to(bool, sfp[1]);
		QApplication::setDesktopSettingsAware(on);
	}
	RETURNvoid_();
}

//void QApplication.setDoubleClickInterval(int arg0);
KMETHOD QApplication_setDoubleClickInterval(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int arg0 = Int_to(int, sfp[1]);
		QApplication::setDoubleClickInterval(arg0);
	}
	RETURNvoid_();
}

//void QApplication.setEffectEnabled(int effect, boolean enable);
KMETHOD QApplication_setEffectEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		Qt::UIEffect effect = Int_to(Qt::UIEffect, sfp[1]);
		bool enable = Boolean_to(bool, sfp[2]);
		QApplication::setEffectEnabled(effect, enable);
	}
	RETURNvoid_();
}

//void QApplication.setFont(QFont font, String className);
KMETHOD QApplication_setFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
		const char*  className = RawPtr_to(const char*, sfp[2]);
		QApplication::setFont(font, className);
	}
	RETURNvoid_();
}

//void QApplication.setGlobalStrut(QSize arg0);
KMETHOD QApplication_setGlobalStrut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QSize  arg0 = *RawPtr_to(const QSize *, sfp[1]);
		QApplication::setGlobalStrut(arg0);
	}
	RETURNvoid_();
}

//void QApplication.setGraphicsSystem(String system);
KMETHOD QApplication_setGraphicsSystem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString system = String_to(const QString, sfp[1]);
		QApplication::setGraphicsSystem(system);
	}
	RETURNvoid_();
}

//void QApplication.setKeyboardInputInterval(int arg0);
KMETHOD QApplication_setKeyboardInputInterval(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int arg0 = Int_to(int, sfp[1]);
		QApplication::setKeyboardInputInterval(arg0);
	}
	RETURNvoid_();
}

//void QApplication.setLayoutDirection(int direction);
KMETHOD QApplication_setLayoutDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		Qt::LayoutDirection direction = Int_to(Qt::LayoutDirection, sfp[1]);
		QApplication::setLayoutDirection(direction);
	}
	RETURNvoid_();
}

//void QApplication.setOverrideCursor(QCursor cursor);
KMETHOD QApplication_setOverrideCursor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QCursor  cursor = *RawPtr_to(const QCursor *, sfp[1]);
		QApplication::setOverrideCursor(cursor);
	}
	RETURNvoid_();
}

//void QApplication.setPalette(QPalette palette, String className);
KMETHOD QApplication_setPalette(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QPalette  palette = *RawPtr_to(const QPalette *, sfp[1]);
		const char*  className = RawPtr_to(const char*, sfp[2]);
		QApplication::setPalette(palette, className);
	}
	RETURNvoid_();
}

//void QApplication.setQuitOnLastWindowClosed(boolean quit);
KMETHOD QApplication_setQuitOnLastWindowClosed(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool quit = Boolean_to(bool, sfp[1]);
		QApplication::setQuitOnLastWindowClosed(quit);
	}
	RETURNvoid_();
}

//void QApplication.setStartDragDistance(int l);
KMETHOD QApplication_setStartDragDistance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int l = Int_to(int, sfp[1]);
		QApplication::setStartDragDistance(l);
	}
	RETURNvoid_();
}

//void QApplication.setStartDragTime(int ms);
KMETHOD QApplication_setStartDragTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int ms = Int_to(int, sfp[1]);
		QApplication::setStartDragTime(ms);
	}
	RETURNvoid_();
}

//void QApplication.setStyle(QStyle style);
KMETHOD QApplication_setStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QStyle*  style = RawPtr_to(QStyle*, sfp[1]);
		QApplication::setStyle(style);
	}
	RETURNvoid_();
}

/*
//QStyle QApplication.setStyle(String style);
KMETHOD QApplication_setStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString style = String_to(const QString, sfp[1]);
		QStyle* ret_v = QApplication::setStyle(style);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QStyle*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//void QApplication.setWheelScrollLines(int arg0);
KMETHOD QApplication_setWheelScrollLines(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int arg0 = Int_to(int, sfp[1]);
		QApplication::setWheelScrollLines(arg0);
	}
	RETURNvoid_();
}

//void QApplication.setWindowIcon(QIcon icon);
KMETHOD QApplication_setWindowIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
		QApplication::setWindowIcon(icon);
	}
	RETURNvoid_();
}

//int QApplication.getStartDragDistance();
KMETHOD QApplication_getStartDragDistance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int ret_v = QApplication::startDragDistance();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QApplication.getStartDragTime();
KMETHOD QApplication_getStartDragTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int ret_v = QApplication::startDragTime();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QStyle QApplication.getStyle();
KMETHOD QApplication_getStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QStyle* ret_v = QApplication::style();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QStyle*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QApplication.syncX();
KMETHOD QApplication_syncX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QApplication::syncX();
	}
	RETURNvoid_();
}

//QWidget QApplication.topLevelAt(QPoint point);
KMETHOD QApplication_topLevelAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		QWidget* ret_v = QApplication::topLevelAt(point);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QWidget QApplication.topLevelAt(int x, int y);
KMETHOD QApplication_topLevelAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		QWidget* ret_v = QApplication::topLevelAt(x, y);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QWidgetList QApplication.topLevelWidgets();
KMETHOD QApplication_topLevelWidgets(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidgetList ret_v = QApplication::topLevelWidgets();
		QWidgetList *ret_v_ = new QWidgetList(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QApplication.type();
KMETHOD QApplication_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QApplication::Type ret_v = QApplication::type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QApplication.getWheelScrollLines();
KMETHOD QApplication_getWheelScrollLines(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int ret_v = QApplication::wheelScrollLines();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QWidget QApplication.widgetAt(QPoint point);
KMETHOD QApplication_widgetAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		QWidget* ret_v = QApplication::widgetAt(point);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QWidget QApplication.widgetAt(int x, int y);
KMETHOD QApplication_widgetAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		QWidget* ret_v = QApplication::widgetAt(x, y);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QIcon QApplication.getWindowIcon();
KMETHOD QApplication_getWindowIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QIcon ret_v = QApplication::windowIcon();
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QApplication.aboutQt();
KMETHOD QApplication_aboutQt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QApplication *  qp = RawPtr_to(QApplication *, sfp[0]);
	if (qp) {
		qp->aboutQt();
	}
	RETURNvoid_();
}

//boolean QApplication.getAutoSipEnabled();
KMETHOD QApplication_getAutoSipEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QApplication *  qp = RawPtr_to(QApplication *, sfp[0]);
	if (qp) {
		bool ret_v = qp->autoSipEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QApplication.closeAllWindows();
KMETHOD QApplication_closeAllWindows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QApplication *  qp = RawPtr_to(QApplication *, sfp[0]);
	if (qp) {
		qp->closeAllWindows();
	}
	RETURNvoid_();
}

//void QApplication.setAutoSipEnabled(boolean enabled);
KMETHOD QApplication_setAutoSipEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QApplication *  qp = RawPtr_to(QApplication *, sfp[0]);
	if (qp) {
		const bool enabled = Boolean_to(const bool, sfp[1]);
		qp->setAutoSipEnabled(enabled);
	}
	RETURNvoid_();
}

//void QApplication.setStyleSheet(String sheet);
KMETHOD QApplication_setStyleSheet(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QApplication *  qp = RawPtr_to(QApplication *, sfp[0]);
	if (qp) {
		const QString sheet = String_to(const QString, sfp[1]);
		qp->setStyleSheet(sheet);
	}
	RETURNvoid_();
}


DummyQApplication::DummyQApplication()
{
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

	int list_size = 3;
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
	self = NULL;
	dummy = new DummyQApplication();
	dummy->connection((QObject*)this);
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
	if (p->rawptr != NULL) {
		KQApplication *qp = (KQApplication *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QApplication_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQApplication *qp = (KQApplication *)p->rawptr;
//		KQApplication *qp = static_cast<KQApplication*>(p->rawptr);
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


