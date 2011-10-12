//QSplashScreen QSplashScreen.new(QPixmap pixmap, int f);
KMETHOD QSplashScreen_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
	Qt::WindowFlags f = Int_to(Qt::WindowFlags, sfp[2]);
	KQSplashScreen *ret_v = new KQSplashScreen(pixmap, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QSplashScreen QSplashScreen.new(QWidget parent, QPixmap pixmap, int f);
KMETHOD QSplashScreen_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
	Qt::WindowFlags f = Int_to(Qt::WindowFlags, sfp[3]);
	KQSplashScreen *ret_v = new KQSplashScreen(parent, pixmap, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QSplashScreen.finish(QWidget mainWin);
KMETHOD QSplashScreen_finish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplashScreen *  qp = RawPtr_to(QSplashScreen *, sfp[0]);
	if (qp != NULL) {
		QWidget*  mainWin = RawPtr_to(QWidget*, sfp[1]);
		qp->finish(mainWin);
	}
	RETURNvoid_();
}

//QPixmap QSplashScreen.getPixmap();
KMETHOD QSplashScreen_getPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplashScreen *  qp = RawPtr_to(QSplashScreen *, sfp[0]);
	if (qp != NULL) {
		const QPixmap ret_v = qp->pixmap();
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QSplashScreen.repaintOL();
KMETHOD QSplashScreen_repaintOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplashScreen *  qp = RawPtr_to(QSplashScreen *, sfp[0]);
	if (qp != NULL) {
		qp->repaint();
	}
	RETURNvoid_();
}

//void QSplashScreen.setPixmap(QPixmap pixmap);
KMETHOD QSplashScreen_setPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplashScreen *  qp = RawPtr_to(QSplashScreen *, sfp[0]);
	if (qp != NULL) {
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
		qp->setPixmap(pixmap);
	}
	RETURNvoid_();
}

//void QSplashScreen.clearMessage();
KMETHOD QSplashScreen_clearMessage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplashScreen *  qp = RawPtr_to(QSplashScreen *, sfp[0]);
	if (qp != NULL) {
		qp->clearMessage();
	}
	RETURNvoid_();
}

//void QSplashScreen.showMessage(String message, int alignment, QColor color);
KMETHOD QSplashScreen_showMessage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplashScreen *  qp = RawPtr_to(QSplashScreen *, sfp[0]);
	if (qp != NULL) {
		const QString message = String_to(const QString, sfp[1]);
		int alignment = Int_to(int, sfp[2]);
		const QColor  color = *RawPtr_to(const QColor *, sfp[3]);
		qp->showMessage(message, alignment, color);
	}
	RETURNvoid_();
}


DummyQSplashScreen::DummyQSplashScreen()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSplashScreen::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSplashScreen::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQSplashScreen::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQSplashScreen::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSplashScreen::event_map->bigin();
	if ((itr = DummyQSplashScreen::event_map->find(str)) == DummyQSplashScreen::event_map->end()) {
		bool ret;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSplashScreen::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSplashScreen::slot_map->bigin();
	if ((itr = DummyQSplashScreen::event_map->find(str)) == DummyQSplashScreen::slot_map->end()) {
		bool ret;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQSplashScreen::KQSplashScreen(const QPixmap pixmap, Qt::WindowFlags f) : QSplashScreen(pixmap, f)
{
	self = NULL;
}

KMETHOD QSplashScreen_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSplashScreen *qp = RawPtr_to(KQSplashScreen *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSplashScreen]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQSplashScreen::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSplashScreen]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QSplashScreen_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSplashScreen *qp = RawPtr_to(KQSplashScreen *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSplashScreen]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQSplashScreen::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSplashScreen]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSplashScreen_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSplashScreen *qp = (KQSplashScreen *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSplashScreen_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQSplashScreen *qp = (KQSplashScreen *)p->rawptr;
		(void)qp;
	}
}

static int QSplashScreen_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQSplashScreen::event(QEvent *event)
{
	if (!DummyQSplashScreen::eventDispatcher(event)) {
		QSplashScreen::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQSplashScreen(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSplashScreen";
	cdef->free = QSplashScreen_free;
	cdef->reftrace = QSplashScreen_reftrace;
	cdef->compareTo = QSplashScreen_compareTo;
}


