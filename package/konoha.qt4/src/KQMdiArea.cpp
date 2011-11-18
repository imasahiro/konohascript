//@Virtual @Override QSize QMdiArea.minimumSizeHint();
KMETHOD QMdiArea_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QMdiArea.sizeHint();
KMETHOD QMdiArea_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QMdiArea QMdiArea.new(QWidget parent);
KMETHOD QMdiArea_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQMdiArea *ret_v = new KQMdiArea(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QMdiArea.getActivationOrder();
KMETHOD QMdiArea_getActivationOrder(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QMdiArea::WindowOrder ret_v = qp->activationOrder();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QMdiSubWindow QMdiArea.getActiveSubWindow();
KMETHOD QMdiArea_getActiveSubWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QMdiSubWindow* ret_v = qp->activeSubWindow();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMdiSubWindow*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QMdiSubWindow QMdiArea.addSubWindow(QWidget widget, QtWindowFlags windowFlags);
KMETHOD QMdiArea_addSubWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		initFlag(windowFlags, Qt::WindowFlags, sfp[2]);
		QMdiSubWindow* ret_v = qp->addSubWindow(widget, windowFlags);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMdiSubWindow*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBrush QMdiArea.getBackground();
KMETHOD QMdiArea_getBackground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QBrush ret_v = qp->background();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QMdiSubWindow QMdiArea.currentSubWindow();
KMETHOD QMdiArea_currentSubWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QMdiSubWindow* ret_v = qp->currentSubWindow();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMdiSubWindow*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QMdiArea.getDocumentMode();
KMETHOD QMdiArea_getDocumentMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		bool ret_v = qp->documentMode();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QMdiArea.removeSubWindow(QWidget widget);
KMETHOD QMdiArea_removeSubWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->removeSubWindow(widget);
	}
	RETURNvoid_();
}

//void QMdiArea.setActivationOrder(int order);
KMETHOD QMdiArea_setActivationOrder(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QMdiArea::WindowOrder order = Int_to(QMdiArea::WindowOrder, sfp[1]);
		qp->setActivationOrder(order);
	}
	RETURNvoid_();
}

//void QMdiArea.setBackground(QBrush background);
KMETHOD QMdiArea_setBackground(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		const QBrush  background = *RawPtr_to(const QBrush *, sfp[1]);
		qp->setBackground(background);
	}
	RETURNvoid_();
}

//void QMdiArea.setDocumentMode(boolean enabled);
KMETHOD QMdiArea_setDocumentMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setDocumentMode(enabled);
	}
	RETURNvoid_();
}

//void QMdiArea.setOption(int option, boolean on);
KMETHOD QMdiArea_setOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QMdiArea::AreaOption option = Int_to(QMdiArea::AreaOption, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		qp->setOption(option, on);
	}
	RETURNvoid_();
}

//void QMdiArea.setTabPosition(int position);
KMETHOD QMdiArea_setTabPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QTabWidget::TabPosition position = Int_to(QTabWidget::TabPosition, sfp[1]);
		qp->setTabPosition(position);
	}
	RETURNvoid_();
}

//void QMdiArea.setTabShape(int shape);
KMETHOD QMdiArea_setTabShape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QTabWidget::TabShape shape = Int_to(QTabWidget::TabShape, sfp[1]);
		qp->setTabShape(shape);
	}
	RETURNvoid_();
}

//void QMdiArea.setViewMode(int mode);
KMETHOD QMdiArea_setViewMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QMdiArea::ViewMode mode = Int_to(QMdiArea::ViewMode, sfp[1]);
		qp->setViewMode(mode);
	}
	RETURNvoid_();
}

//Array<QMdiSubWindow> QMdiArea.subWindowList(int order);
KMETHOD QMdiArea_subWindowList(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QMdiArea::WindowOrder order = Int_to(QMdiArea::WindowOrder, sfp[1]);
		QList<QMdiSubWindow*> ret_v = qp->subWindowList(order);
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QMdiSubWindow"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//int QMdiArea.getTabPosition();
KMETHOD QMdiArea_getTabPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QTabWidget::TabPosition ret_v = qp->tabPosition();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QMdiArea.getTabShape();
KMETHOD QMdiArea_getTabShape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QTabWidget::TabShape ret_v = qp->tabShape();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QMdiArea.testOption(int option);
KMETHOD QMdiArea_testOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QMdiArea::AreaOption option = Int_to(QMdiArea::AreaOption, sfp[1]);
		bool ret_v = qp->testOption(option);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QMdiArea.getViewMode();
KMETHOD QMdiArea_getViewMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QMdiArea::ViewMode ret_v = qp->viewMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QMdiArea.activateNextSubWindow();
KMETHOD QMdiArea_activateNextSubWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		qp->activateNextSubWindow();
	}
	RETURNvoid_();
}

//void QMdiArea.activatePreviousSubWindow();
KMETHOD QMdiArea_activatePreviousSubWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		qp->activatePreviousSubWindow();
	}
	RETURNvoid_();
}

//void QMdiArea.cascadeSubWindows();
KMETHOD QMdiArea_cascadeSubWindows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		qp->cascadeSubWindows();
	}
	RETURNvoid_();
}

//void QMdiArea.closeActiveSubWindow();
KMETHOD QMdiArea_closeActiveSubWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		qp->closeActiveSubWindow();
	}
	RETURNvoid_();
}

//void QMdiArea.closeAllSubWindows();
KMETHOD QMdiArea_closeAllSubWindows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		qp->closeAllSubWindows();
	}
	RETURNvoid_();
}

//void QMdiArea.setActiveSubWindow(QMdiSubWindow window);
KMETHOD QMdiArea_setActiveSubWindow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		QMdiSubWindow*  window = RawPtr_to(QMdiSubWindow*, sfp[1]);
		qp->setActiveSubWindow(window);
	}
	RETURNvoid_();
}

//void QMdiArea.tileSubWindows();
KMETHOD QMdiArea_tileSubWindows(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea *  qp = RawPtr_to(QMdiArea *, sfp[0]);
	if (qp) {
		qp->tileSubWindows();
	}
	RETURNvoid_();
}


DummyQMdiArea::DummyQMdiArea()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	sub_window_activated_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("sub-window-activated", NULL));
}
DummyQMdiArea::~DummyQMdiArea()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQMdiArea::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMdiArea::self = ptr;
	DummyQAbstractScrollArea::setSelf(ptr);
}

bool DummyQMdiArea::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractScrollArea::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQMdiArea::subWindowActivatedSlot(QMdiSubWindow* window)
{
	if (sub_window_activated_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QMdiSubWindow, window);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, sub_window_activated_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQMdiArea::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMdiArea::event_map->bigin();
	if ((itr = DummyQMdiArea::event_map->find(str)) == DummyQMdiArea::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractScrollArea::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMdiArea::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMdiArea::slot_map->bigin();
	if ((itr = DummyQMdiArea::slot_map->find(str)) == DummyQMdiArea::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractScrollArea::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		sub_window_activated_func = (*slot_map)["sub-window-activated"];
		return true;
	}
}

knh_Object_t** DummyQMdiArea::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQMdiArea::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, sub_window_activated_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQAbstractScrollArea::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQMdiArea::connection(QObject *o)
{
	QMdiArea *p = dynamic_cast<QMdiArea*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(subWindowActivatedSlot(QMdiSubWindow*)));
	}
	DummyQAbstractScrollArea::connection(o);
}

KQMdiArea::KQMdiArea(QWidget* parent) : QMdiArea(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQMdiArea();
	dummy->connection((QObject*)this);
}

KQMdiArea::~KQMdiArea()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QMdiArea_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMdiArea *qp = RawPtr_to(KQMdiArea *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMdiArea]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMdiArea]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QMdiArea_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMdiArea *qp = RawPtr_to(KQMdiArea *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMdiArea]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMdiArea]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMdiArea_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQMdiArea *qp = (KQMdiArea *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QMdiArea*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QMdiArea_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQMdiArea *qp = (KQMdiArea *)p->rawptr;
		KQMdiArea *qp = static_cast<KQMdiArea*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QMdiArea_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMdiArea::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQMdiArea::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QMdiArea::event(event);
		return false;
	}
//	QMdiArea::event(event);
	return true;
}

static knh_IntData_t QMdiAreaConstInt[] = {
	{"DontMaximizeSubWindowOnActivation", QMdiArea::DontMaximizeSubWindowOnActivation},
	{"SubWindowView", QMdiArea::SubWindowView},
	{"TabbedView", QMdiArea::TabbedView},
	{"CreationOrder", QMdiArea::CreationOrder},
	{"StackingOrder", QMdiArea::StackingOrder},
	{"ActivationHistoryOrder", QMdiArea::ActivationHistoryOrder},
	{NULL, 0}
};

DEFAPI(void) constQMdiArea(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QMdiAreaConstInt);
}


DEFAPI(void) defQMdiArea(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMdiArea";
	cdef->free = QMdiArea_free;
	cdef->reftrace = QMdiArea_reftrace;
	cdef->compareTo = QMdiArea_compareTo;
}

//## QMdiAreaAreaOptions QMdiAreaAreaOptions.new(int value);
KMETHOD QMdiAreaAreaOptions_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMdiArea::AreaOption i = Int_to(QMdiArea::AreaOption, sfp[1]);
	QMdiArea::AreaOptions *ret_v = new QMdiArea::AreaOptions(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QMdiAreaAreaOptions QMdiAreaAreaOptions.and(int mask);
KMETHOD QMdiAreaAreaOptions_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMdiArea::AreaOptions *qp = RawPtr_to(QMdiArea::AreaOptions*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QMdiArea::AreaOptions ret = ((*qp) & i);
		QMdiArea::AreaOptions *ret_ = new QMdiArea::AreaOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMdiAreaAreaOptions QMdiAreaAreaOptions.iand(QMdiArea::QMdiAreaAreaOptions other);
KMETHOD QMdiAreaAreaOptions_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMdiArea::AreaOptions *qp = RawPtr_to(QMdiArea::AreaOptions*, sfp[0]);
	if (qp != NULL) {
		QMdiArea::AreaOptions *other = RawPtr_to(QMdiArea::AreaOptions *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMdiAreaAreaOptions QMdiAreaAreaOptions.or(QMdiAreaAreaOptions f);
KMETHOD QMdiAreaAreaOptions_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea::AreaOptions *qp = RawPtr_to(QMdiArea::AreaOptions*, sfp[0]);
	if (qp != NULL) {
		QMdiArea::AreaOptions *f = RawPtr_to(QMdiArea::AreaOptions*, sfp[1]);
		QMdiArea::AreaOptions ret = ((*qp) | (*f));
		QMdiArea::AreaOptions *ret_ = new QMdiArea::AreaOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMdiAreaAreaOptions QMdiAreaAreaOptions.ior(QMdiArea::QMdiAreaAreaOptions other);
KMETHOD QMdiAreaAreaOptions_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMdiArea::AreaOptions *qp = RawPtr_to(QMdiArea::AreaOptions*, sfp[0]);
	if (qp != NULL) {
		QMdiArea::AreaOptions *other = RawPtr_to(QMdiArea::AreaOptions *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMdiAreaAreaOptions QMdiAreaAreaOptions.xor(QMdiAreaAreaOptions f);
KMETHOD QMdiAreaAreaOptions_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMdiArea::AreaOptions *qp = RawPtr_to(QMdiArea::AreaOptions*, sfp[0]);
	if (qp != NULL) {
		QMdiArea::AreaOptions *f = RawPtr_to(QMdiArea::AreaOptions*, sfp[1]);
		QMdiArea::AreaOptions ret = ((*qp) ^ (*f));
		QMdiArea::AreaOptions *ret_ = new QMdiArea::AreaOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QMdiAreaAreaOptions QMdiAreaAreaOptions.ixor(QMdiArea::QMdiAreaAreaOptions other);
KMETHOD QMdiAreaAreaOptions_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMdiArea::AreaOptions *qp = RawPtr_to(QMdiArea::AreaOptions*, sfp[0]);
	if (qp != NULL) {
		QMdiArea::AreaOptions *other = RawPtr_to(QMdiArea::AreaOptions *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QMdiAreaAreaOptions.testFlag(int flag);
KMETHOD QMdiAreaAreaOptions_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMdiArea::AreaOptions *qp = RawPtr_to(QMdiArea::AreaOptions *, sfp[0]);
	if (qp != NULL) {
		QMdiArea::AreaOption flag = Int_to(QMdiArea::AreaOption, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QMdiAreaAreaOptions.value();
KMETHOD QMdiAreaAreaOptions_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QMdiArea::AreaOptions *qp = RawPtr_to(QMdiArea::AreaOptions *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QMdiAreaAreaOptions_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QMdiArea::AreaOptions *qp = (QMdiArea::AreaOptions *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QMdiAreaAreaOptions_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QMdiArea::AreaOptions *qp = (QMdiArea::AreaOptions *)p->rawptr;
		(void)qp;
	}
}

static int QMdiAreaAreaOptions_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QMdiArea::AreaOptions*)p1->rawptr);
//		int v2 = int(*(QMdiArea::AreaOptions*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QMdiArea::AreaOptions v1 = *(QMdiArea::AreaOptions*)p1->rawptr;
		QMdiArea::AreaOptions v2 = *(QMdiArea::AreaOptions*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQMdiAreaAreaOptions(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMdiAreaAreaOptions";
	cdef->free = QMdiAreaAreaOptions_free;
	cdef->reftrace = QMdiAreaAreaOptions_reftrace;
	cdef->compareTo = QMdiAreaAreaOptions_compareTo;
}

