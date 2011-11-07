//@Virtual @Override QSize QWorkspace.sizeHint();
KMETHOD QWorkspace_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWorkspace *  qp = RawPtr_to(QWorkspace *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWorkspace QWorkspace.new(QWidget parent);
KMETHOD QWorkspace_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQWorkspace *ret_v = new KQWorkspace(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QWidget QWorkspace.getActiveWindow();
KMETHOD QWorkspace_getActiveWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWorkspace *  qp = RawPtr_to(QWorkspace *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->activeWindow();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QWorkspace.addWindow(QWidget w, QtWindowFlags flags);
KMETHOD QWorkspace_addWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWorkspace *  qp = RawPtr_to(QWorkspace *, sfp[0]);
	if (qp) {
		QWidget*  w = RawPtr_to(QWidget*, sfp[1]);
		initFlag(flags, Qt::WindowFlags, sfp[2]);
		QWidget* ret_v = qp->addWindow(w, flags);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QWorkspace.getBackground();
KMETHOD QWorkspace_getBackground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWorkspace *  qp = RawPtr_to(QWorkspace *, sfp[0]);
	if (qp) {
		QBrush ret_v = qp->background();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QWorkspace.getScrollBarsEnabled();
KMETHOD QWorkspace_getScrollBarsEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWorkspace *  qp = RawPtr_to(QWorkspace *, sfp[0]);
	if (qp) {
		bool ret_v = qp->scrollBarsEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QWorkspace.setBackground(QBrush background);
KMETHOD QWorkspace_setBackground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWorkspace *  qp = RawPtr_to(QWorkspace *, sfp[0]);
	if (qp) {
		const QBrush  background = *RawPtr_to(const QBrush *, sfp[1]);
		qp->setBackground(background);
	}
	RETURNvoid_();
}

//void QWorkspace.setScrollBarsEnabled(boolean enable);
KMETHOD QWorkspace_setScrollBarsEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWorkspace *  qp = RawPtr_to(QWorkspace *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setScrollBarsEnabled(enable);
	}
	RETURNvoid_();
}

//QWidgetList QWorkspace.windowList(int order);
KMETHOD QWorkspace_windowList(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWorkspace *  qp = RawPtr_to(QWorkspace *, sfp[0]);
	if (qp) {
		QWorkspace::WindowOrder order = Int_to(QWorkspace::WindowOrder, sfp[1]);
		QWidgetList ret_v = qp->windowList(order);
		QWidgetList *ret_v_ = new QWidgetList(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWorkspace.activateNextWindow();
KMETHOD QWorkspace_activateNextWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWorkspace *  qp = RawPtr_to(QWorkspace *, sfp[0]);
	if (qp) {
		qp->activateNextWindow();
	}
	RETURNvoid_();
}

//void QWorkspace.activatePreviousWindow();
KMETHOD QWorkspace_activatePreviousWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWorkspace *  qp = RawPtr_to(QWorkspace *, sfp[0]);
	if (qp) {
		qp->activatePreviousWindow();
	}
	RETURNvoid_();
}

//void QWorkspace.arrangeIcons();
KMETHOD QWorkspace_arrangeIcons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWorkspace *  qp = RawPtr_to(QWorkspace *, sfp[0]);
	if (qp) {
		qp->arrangeIcons();
	}
	RETURNvoid_();
}

//void QWorkspace.cascade();
KMETHOD QWorkspace_cascade(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWorkspace *  qp = RawPtr_to(QWorkspace *, sfp[0]);
	if (qp) {
		qp->cascade();
	}
	RETURNvoid_();
}

//void QWorkspace.closeActiveWindow();
KMETHOD QWorkspace_closeActiveWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWorkspace *  qp = RawPtr_to(QWorkspace *, sfp[0]);
	if (qp) {
		qp->closeActiveWindow();
	}
	RETURNvoid_();
}

//void QWorkspace.closeAllWindows();
KMETHOD QWorkspace_closeAllWindows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWorkspace *  qp = RawPtr_to(QWorkspace *, sfp[0]);
	if (qp) {
		qp->closeAllWindows();
	}
	RETURNvoid_();
}

//void QWorkspace.setActiveWindow(QWidget w);
KMETHOD QWorkspace_setActiveWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWorkspace *  qp = RawPtr_to(QWorkspace *, sfp[0]);
	if (qp) {
		QWidget*  w = RawPtr_to(QWidget*, sfp[1]);
		qp->setActiveWindow(w);
	}
	RETURNvoid_();
}

//void QWorkspace.tile();
KMETHOD QWorkspace_tile(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWorkspace *  qp = RawPtr_to(QWorkspace *, sfp[0]);
	if (qp) {
		qp->tile();
	}
	RETURNvoid_();
}


DummyQWorkspace::DummyQWorkspace()
{
	self = NULL;
	window_activated_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("window-activated", NULL));
}

void DummyQWorkspace::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWorkspace::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQWorkspace::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQWorkspace::windowActivatedSlot(QWidget* w)
{
	if (window_activated_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QWidget, w);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, window_activated_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQWorkspace::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWorkspace::event_map->bigin();
	if ((itr = DummyQWorkspace::event_map->find(str)) == DummyQWorkspace::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWorkspace::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWorkspace::slot_map->bigin();
	if ((itr = DummyQWorkspace::slot_map->find(str)) == DummyQWorkspace::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		window_activated_func = (*slot_map)["window-activated"];
		return true;
	}
}

void DummyQWorkspace::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 1;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, window_activated_func);

	KNH_SIZEREF(ctx);

	DummyQWidget::reftrace(ctx, p, tail_);
}

void DummyQWorkspace::connection(QObject *o)
{
	QWorkspace *p = dynamic_cast<QWorkspace*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(windowActivated(QWidget*)), this, SLOT(windowActivatedSlot(QWidget*)));
	}
	DummyQWidget::connection(o);
}

KQWorkspace::KQWorkspace(QWidget* parent) : QWorkspace(parent)
{
	self = NULL;
	dummy = new DummyQWorkspace();
	dummy->connection((QObject*)this);
}

KMETHOD QWorkspace_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWorkspace *qp = RawPtr_to(KQWorkspace *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWorkspace]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWorkspace]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWorkspace_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWorkspace *qp = RawPtr_to(KQWorkspace *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWorkspace]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWorkspace]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWorkspace_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWorkspace *qp = (KQWorkspace *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWorkspace_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQWorkspace *qp = (KQWorkspace *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWorkspace_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWorkspace::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQWorkspace::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QWorkspace::event(event);
		return false;
	}
	return true;
}

static knh_IntData_t QWorkspaceConstInt[] = {
	{"CreationOrder", QWorkspace::CreationOrder},
	{"StackingOrder", QWorkspace::StackingOrder},
	{NULL, 0}
};

DEFAPI(void) constQWorkspace(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QWorkspaceConstInt);
}


DEFAPI(void) defQWorkspace(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWorkspace";
	cdef->free = QWorkspace_free;
	cdef->reftrace = QWorkspace_reftrace;
	cdef->compareTo = QWorkspace_compareTo;
}


