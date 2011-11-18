//QSplashScreen QSplashScreen.new(QPixmap pixmap, QtWindowFlags f);
KMETHOD QSplashScreen_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
	initFlag(f, Qt::WindowFlags, sfp[2]);
	KQSplashScreen *ret_v = new KQSplashScreen(pixmap, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QSplashScreen QSplashScreen.new(QWidget parent, QPixmap pixmap, QtWindowFlags f);
KMETHOD QSplashScreen_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[2]);
	initFlag(f, Qt::WindowFlags, sfp[3]);
	KQSplashScreen *ret_v = new KQSplashScreen(parent, pixmap, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QSplashScreen.finish(QWidget mainWin);
KMETHOD QSplashScreen_finish(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplashScreen *  qp = RawPtr_to(QSplashScreen *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		qp->repaint();
	}
	RETURNvoid_();
}

//void QSplashScreen.setPixmap(QPixmap pixmap);
KMETHOD QSplashScreen_setPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplashScreen *  qp = RawPtr_to(QSplashScreen *, sfp[0]);
	if (qp) {
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
	if (qp) {
		qp->clearMessage();
	}
	RETURNvoid_();
}

//void QSplashScreen.showMessage(String message, int alignment, QColor color);
KMETHOD QSplashScreen_showMessage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSplashScreen *  qp = RawPtr_to(QSplashScreen *, sfp[0]);
	if (qp) {
		const QString message = String_to(const QString, sfp[1]);
		int alignment = Int_to(int, sfp[2]);
		const QColor  color = *RawPtr_to(const QColor *, sfp[3]);
		qp->showMessage(message, alignment, color);
	}
	RETURNvoid_();
}


DummyQSplashScreen::DummyQSplashScreen()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	message_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("message-changed", NULL));
}
DummyQSplashScreen::~DummyQSplashScreen()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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

bool DummyQSplashScreen::messageChangedSlot(const QString message)
{
	if (message_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QString, message);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, message_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQSplashScreen::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSplashScreen::event_map->bigin();
	if ((itr = DummyQSplashScreen::event_map->find(str)) == DummyQSplashScreen::event_map->end()) {
		bool ret = false;
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
	if ((itr = DummyQSplashScreen::slot_map->find(str)) == DummyQSplashScreen::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		message_changed_func = (*slot_map)["message-changed"];
		return true;
	}
}

knh_Object_t** DummyQSplashScreen::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQSplashScreen::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, message_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQWidget::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQSplashScreen::connection(QObject *o)
{
	QSplashScreen *p = dynamic_cast<QSplashScreen*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(messageChanged(const QString)), this, SLOT(messageChangedSlot(const QString)));
	}
	DummyQWidget::connection(o);
}

KQSplashScreen::KQSplashScreen(const QPixmap pixmap, Qt::WindowFlags f) : QSplashScreen(pixmap, f)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQSplashScreen();
	dummy->connection((QObject*)this);
}

KQSplashScreen::~KQSplashScreen()
{
	delete dummy;
	dummy = NULL;
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSplashScreen]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSplashScreen_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQSplashScreen *qp = (KQSplashScreen *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QSplashScreen*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QSplashScreen_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQSplashScreen *qp = (KQSplashScreen *)p->rawptr;
		KQSplashScreen *qp = static_cast<KQSplashScreen*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSplashScreen_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSplashScreen::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQSplashScreen::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QSplashScreen::event(event);
		return false;
	}
//	QSplashScreen::event(event);
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


