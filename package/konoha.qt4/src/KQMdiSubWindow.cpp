//@Virtual @Override QSize QMdiSubWindow.minimumSizeHint();
KMETHOD QMdiSubWindow_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QMdiSubWindow.sizeHint();
KMETHOD QMdiSubWindow_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QMdiSubWindow QMdiSubWindow.new(QWidget parent, int flags);
KMETHOD QMdiSubWindow_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	Qt::WindowFlags flags = Int_to(Qt::WindowFlags, sfp[2]);
	KQMdiSubWindow *ret_v = new KQMdiSubWindow(parent, flags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QMdiSubWindow.isShaded();
KMETHOD QMdiSubWindow_isShaded(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isShaded();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QMdiSubWindow.getKeyboardPageStep();
KMETHOD QMdiSubWindow_getKeyboardPageStep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->keyboardPageStep();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMdiSubWindow.getKeyboardSingleStep();
KMETHOD QMdiSubWindow_getKeyboardSingleStep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->keyboardSingleStep();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QMdiArea QMdiSubWindow.mdiArea();
KMETHOD QMdiSubWindow_mdiArea(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp != NULL) {
		QMdiArea* ret_v = qp->mdiArea();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMdiArea*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QMdiSubWindow.setKeyboardPageStep(int step);
KMETHOD QMdiSubWindow_setKeyboardPageStep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp != NULL) {
		int step = Int_to(int, sfp[1]);
		qp->setKeyboardPageStep(step);
	}
	RETURNvoid_();
}

//void QMdiSubWindow.setKeyboardSingleStep(int step);
KMETHOD QMdiSubWindow_setKeyboardSingleStep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp != NULL) {
		int step = Int_to(int, sfp[1]);
		qp->setKeyboardSingleStep(step);
	}
	RETURNvoid_();
}

//void QMdiSubWindow.setOption(int option, boolean on);
KMETHOD QMdiSubWindow_setOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp != NULL) {
		QMdiSubWindow::SubWindowOption option = Int_to(QMdiSubWindow::SubWindowOption, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		qp->setOption(option, on);
	}
	RETURNvoid_();
}

//void QMdiSubWindow.setSystemMenu(QMenu systemMenu);
KMETHOD QMdiSubWindow_setSystemMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp != NULL) {
		QMenu*  systemMenu = RawPtr_to(QMenu*, sfp[1]);
		qp->setSystemMenu(systemMenu);
	}
	RETURNvoid_();
}

//void QMdiSubWindow.setWidget(QWidget widget);
KMETHOD QMdiSubWindow_setWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setWidget(widget);
	}
	RETURNvoid_();
}

//QMenu QMdiSubWindow.getSystemMenu();
KMETHOD QMdiSubWindow_getSystemMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp != NULL) {
		QMenu* ret_v = qp->systemMenu();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMenu*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QMdiSubWindow.testOption(int option);
KMETHOD QMdiSubWindow_testOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp != NULL) {
		QMdiSubWindow::SubWindowOption option = Int_to(QMdiSubWindow::SubWindowOption, sfp[1]);
		bool ret_v = qp->testOption(option);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QWidget QMdiSubWindow.getWidget();
KMETHOD QMdiSubWindow_getWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->widget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QMdiSubWindow.showShaded();
KMETHOD QMdiSubWindow_showShaded(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp != NULL) {
		qp->showShaded();
	}
	RETURNvoid_();
}

//void QMdiSubWindow.showSystemMenu();
KMETHOD QMdiSubWindow_showSystemMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp != NULL) {
		qp->showSystemMenu();
	}
	RETURNvoid_();
}


DummyQMdiSubWindow::DummyQMdiSubWindow()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQMdiSubWindow::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMdiSubWindow::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQMdiSubWindow::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQMdiSubWindow::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMdiSubWindow::event_map->bigin();
	if ((itr = DummyQMdiSubWindow::event_map->find(str)) == DummyQMdiSubWindow::event_map->end()) {
		bool ret;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMdiSubWindow::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMdiSubWindow::slot_map->bigin();
	if ((itr = DummyQMdiSubWindow::event_map->find(str)) == DummyQMdiSubWindow::slot_map->end()) {
		bool ret;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQMdiSubWindow::KQMdiSubWindow(QWidget* parent, Qt::WindowFlags flags) : QMdiSubWindow(parent, flags)
{
	self = NULL;
}

KMETHOD QMdiSubWindow_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMdiSubWindow *qp = RawPtr_to(KQMdiSubWindow *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMdiSubWindow]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQMdiSubWindow::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMdiSubWindow]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QMdiSubWindow_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMdiSubWindow *qp = RawPtr_to(KQMdiSubWindow *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMdiSubWindow]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQMdiSubWindow::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMdiSubWindow]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMdiSubWindow_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMdiSubWindow *qp = (KQMdiSubWindow *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMdiSubWindow_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQMdiSubWindow *qp = (KQMdiSubWindow *)p->rawptr;
		(void)qp;
	}
}

static int QMdiSubWindow_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQMdiSubWindow::event(QEvent *event)
{
	if (!DummyQMdiSubWindow::eventDispatcher(event)) {
		QMdiSubWindow::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQMdiSubWindow(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMdiSubWindow";
	cdef->free = QMdiSubWindow_free;
	cdef->reftrace = QMdiSubWindow_reftrace;
	cdef->compareTo = QMdiSubWindow_compareTo;
}

static knh_IntData_t QMdiSubWindowConstInt[] = {
	{"RubberBandResize", QMdiSubWindow::RubberBandResize},
	{"RubberBandMove", QMdiSubWindow::RubberBandMove},
	{NULL, 0}
};

DEFAPI(void) constQMdiSubWindow(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QMdiSubWindowConstInt);
}

