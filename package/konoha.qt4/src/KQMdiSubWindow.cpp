//@Virtual @Override QSize QMdiSubWindow.minimumSizeHint();
KMETHOD QMdiSubWindow_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp) {
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
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QMdiSubWindow QMdiSubWindow.new(QWidget parent, QtWindowFlags flags);
KMETHOD QMdiSubWindow_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	initFlag(flags, Qt::WindowFlags, sfp[2]);
	KQMdiSubWindow *ret_v = new KQMdiSubWindow(parent, flags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QMdiSubWindow.isShaded();
KMETHOD QMdiSubWindow_isShaded(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		qp->showShaded();
	}
	RETURNvoid_();
}

//void QMdiSubWindow.showSystemMenu();
KMETHOD QMdiSubWindow_showSystemMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow *  qp = RawPtr_to(QMdiSubWindow *, sfp[0]);
	if (qp) {
		qp->showSystemMenu();
	}
	RETURNvoid_();
}


DummyQMdiSubWindow::DummyQMdiSubWindow()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	about_to_activate_func = NULL;
	window_state_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("about-to-activate", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("window-state-changed", NULL));
}
DummyQMdiSubWindow::~DummyQMdiSubWindow()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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

bool DummyQMdiSubWindow::aboutToActivateSlot()
{
	if (about_to_activate_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, about_to_activate_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQMdiSubWindow::windowStateChangedSlot(Qt::WindowStates oldState, Qt::WindowStates new_State)
{
	if (window_state_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, Qt::WindowStates, oldState);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_RawPtr_t *p2 = new_QRawPtr(lctx, Qt::WindowStates, new_State);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		knh_Func_invoke(lctx, window_state_changed_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQMdiSubWindow::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMdiSubWindow::event_map->bigin();
	if ((itr = DummyQMdiSubWindow::event_map->find(str)) == DummyQMdiSubWindow::event_map->end()) {
		bool ret = false;
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
	if ((itr = DummyQMdiSubWindow::slot_map->find(str)) == DummyQMdiSubWindow::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		about_to_activate_func = (*slot_map)["about-to-activate"];
		window_state_changed_func = (*slot_map)["window-state-changed"];
		return true;
	}
}

knh_Object_t** DummyQMdiSubWindow::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQMdiSubWindow::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 3;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, about_to_activate_func);
	KNH_ADDNNREF(ctx, window_state_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQWidget::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQMdiSubWindow::connection(QObject *o)
{
	QMdiSubWindow *p = dynamic_cast<QMdiSubWindow*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(aboutToActivate()), this, SLOT(aboutToActivateSlot()));
		connect(p, SIGNAL(windowStateChanged(Qt::WindowStates, Qt::WindowStates)), this, SLOT(windowStateChangedSlot(Qt::WindowStates, Qt::WindowStates)));
	}
	DummyQWidget::connection(o);
}

KQMdiSubWindow::KQMdiSubWindow(QWidget* parent, Qt::WindowFlags flags) : QMdiSubWindow(parent, flags)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQMdiSubWindow();
	dummy->connection((QObject*)this);
}

KQMdiSubWindow::~KQMdiSubWindow()
{
	delete dummy;
	dummy = NULL;
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMdiSubWindow]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMdiSubWindow_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQMdiSubWindow *qp = (KQMdiSubWindow *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QMdiSubWindow*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QMdiSubWindow_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQMdiSubWindow *qp = (KQMdiSubWindow *)p->rawptr;
		KQMdiSubWindow *qp = static_cast<KQMdiSubWindow*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QMdiSubWindow_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMdiSubWindow::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQMdiSubWindow::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QMdiSubWindow::event(event);
		return false;
	}
//	QMdiSubWindow::event(event);
	return true;
}

static knh_IntData_t QMdiSubWindowConstInt[] = {
	{"RubberBandResize", QMdiSubWindow::RubberBandResize},
	{"RubberBandMove", QMdiSubWindow::RubberBandMove},
	{NULL, 0}
};

DEFAPI(void) constQMdiSubWindow(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QMdiSubWindowConstInt);
}


DEFAPI(void) defQMdiSubWindow(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMdiSubWindow";
	cdef->free = QMdiSubWindow_free;
	cdef->reftrace = QMdiSubWindow_reftrace;
	cdef->compareTo = QMdiSubWindow_compareTo;
}

//## QMdiSubWindowSubWindowOptions QMdiSubWindowSubWindowOptions.new(int value);
KMETHOD QMdiSubWindowSubWindowOptions_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMdiSubWindow::SubWindowOption i = Int_to(QMdiSubWindow::SubWindowOption, sfp[1]);
	QMdiSubWindow::SubWindowOptions *ret_v = new QMdiSubWindow::SubWindowOptions(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QMdiSubWindowSubWindowOptions QMdiSubWindowSubWindowOptions.and(int mask);
KMETHOD QMdiSubWindowSubWindowOptions_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMdiSubWindow::SubWindowOptions *qp = RawPtr_to(QMdiSubWindow::SubWindowOptions*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QMdiSubWindow::SubWindowOptions ret = ((*qp) & i);
		QMdiSubWindow::SubWindowOptions *ret_ = new QMdiSubWindow::SubWindowOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMdiSubWindowSubWindowOptions QMdiSubWindowSubWindowOptions.iand(QMdiSubWindow::QMdiSubWindowSubWindowOptions other);
KMETHOD QMdiSubWindowSubWindowOptions_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMdiSubWindow::SubWindowOptions *qp = RawPtr_to(QMdiSubWindow::SubWindowOptions*, sfp[0]);
	if (qp != NULL) {
		QMdiSubWindow::SubWindowOptions *other = RawPtr_to(QMdiSubWindow::SubWindowOptions *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMdiSubWindowSubWindowOptions QMdiSubWindowSubWindowOptions.or(QMdiSubWindowSubWindowOptions f);
KMETHOD QMdiSubWindowSubWindowOptions_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow::SubWindowOptions *qp = RawPtr_to(QMdiSubWindow::SubWindowOptions*, sfp[0]);
	if (qp != NULL) {
		QMdiSubWindow::SubWindowOptions *f = RawPtr_to(QMdiSubWindow::SubWindowOptions*, sfp[1]);
		QMdiSubWindow::SubWindowOptions ret = ((*qp) | (*f));
		QMdiSubWindow::SubWindowOptions *ret_ = new QMdiSubWindow::SubWindowOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMdiSubWindowSubWindowOptions QMdiSubWindowSubWindowOptions.ior(QMdiSubWindow::QMdiSubWindowSubWindowOptions other);
KMETHOD QMdiSubWindowSubWindowOptions_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMdiSubWindow::SubWindowOptions *qp = RawPtr_to(QMdiSubWindow::SubWindowOptions*, sfp[0]);
	if (qp != NULL) {
		QMdiSubWindow::SubWindowOptions *other = RawPtr_to(QMdiSubWindow::SubWindowOptions *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMdiSubWindowSubWindowOptions QMdiSubWindowSubWindowOptions.xor(QMdiSubWindowSubWindowOptions f);
KMETHOD QMdiSubWindowSubWindowOptions_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiSubWindow::SubWindowOptions *qp = RawPtr_to(QMdiSubWindow::SubWindowOptions*, sfp[0]);
	if (qp != NULL) {
		QMdiSubWindow::SubWindowOptions *f = RawPtr_to(QMdiSubWindow::SubWindowOptions*, sfp[1]);
		QMdiSubWindow::SubWindowOptions ret = ((*qp) ^ (*f));
		QMdiSubWindow::SubWindowOptions *ret_ = new QMdiSubWindow::SubWindowOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMdiSubWindowSubWindowOptions QMdiSubWindowSubWindowOptions.ixor(QMdiSubWindow::QMdiSubWindowSubWindowOptions other);
KMETHOD QMdiSubWindowSubWindowOptions_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMdiSubWindow::SubWindowOptions *qp = RawPtr_to(QMdiSubWindow::SubWindowOptions*, sfp[0]);
	if (qp != NULL) {
		QMdiSubWindow::SubWindowOptions *other = RawPtr_to(QMdiSubWindow::SubWindowOptions *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QMdiSubWindowSubWindowOptions.testFlag(int flag);
KMETHOD QMdiSubWindowSubWindowOptions_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMdiSubWindow::SubWindowOptions *qp = RawPtr_to(QMdiSubWindow::SubWindowOptions *, sfp[0]);
	if (qp != NULL) {
		QMdiSubWindow::SubWindowOption flag = Int_to(QMdiSubWindow::SubWindowOption, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QMdiSubWindowSubWindowOptions.value();
KMETHOD QMdiSubWindowSubWindowOptions_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMdiSubWindow::SubWindowOptions *qp = RawPtr_to(QMdiSubWindow::SubWindowOptions *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QMdiSubWindowSubWindowOptions_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QMdiSubWindow::SubWindowOptions *qp = (QMdiSubWindow::SubWindowOptions *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QMdiSubWindowSubWindowOptions_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QMdiSubWindow::SubWindowOptions *qp = (QMdiSubWindow::SubWindowOptions *)p->rawptr;
		(void)qp;
	}
}

static int QMdiSubWindowSubWindowOptions_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QMdiSubWindow::SubWindowOptions*)p1->rawptr);
//		int v2 = int(*(QMdiSubWindow::SubWindowOptions*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QMdiSubWindow::SubWindowOptions v1 = *(QMdiSubWindow::SubWindowOptions*)p1->rawptr;
		QMdiSubWindow::SubWindowOptions v2 = *(QMdiSubWindow::SubWindowOptions*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQMdiSubWindowSubWindowOptions(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMdiSubWindowSubWindowOptions";
	cdef->free = QMdiSubWindowSubWindowOptions_free;
	cdef->reftrace = QMdiSubWindowSubWindowOptions_reftrace;
	cdef->compareTo = QMdiSubWindowSubWindowOptions_compareTo;
}

