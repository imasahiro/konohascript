//@Virtual @Override int QMenuBar.heightForWidth(int arg0);
KMETHOD QMenuBar_heightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		int arg0 = Int_to(int, sfp[1]);
		int ret_v = qp->heightForWidth(arg0);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QSize QMenuBar.minimumSizeHint();
KMETHOD QMenuBar_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QMenuBar.sizeHint();
KMETHOD QMenuBar_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QMenuBar QMenuBar.new(QWidget parent);
KMETHOD QMenuBar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQMenuBar *ret_v = new KQMenuBar(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QAction QMenuBar.actionAt(QPoint pt);
KMETHOD QMenuBar_actionAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		const QPoint  pt = *RawPtr_to(const QPoint *, sfp[1]);
		QAction* ret_v = qp->actionAt(pt);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QMenuBar.actionGeometry(QAction act);
KMETHOD QMenuBar_actionGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		QAction*  act = RawPtr_to(QAction*, sfp[1]);
		QRect ret_v = qp->actionGeometry(act);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAction QMenuBar.getActiveAction();
KMETHOD QMenuBar_getActiveAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		QAction* ret_v = qp->activeAction();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAction QMenuBar.addMenu(QMenu menu);
KMETHOD QMenuBar_addMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		QMenu*  menu = RawPtr_to(QMenu*, sfp[1]);
		QAction* ret_v = qp->addMenu(menu);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QMenu QMenuBar.addMenu(String title);
KMETHOD QMenuBar_addMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
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
//QMenu QMenuBar.addMenu(QIcon icon, String title);
KMETHOD QMenuBar_addMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
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
//QAction QMenuBar.addSeparator();
KMETHOD QMenuBar_addSeparator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		QAction* ret_v = qp->addSeparator();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QMenuBar.clear();
KMETHOD QMenuBar_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//QWidget QMenuBar.getCornerWidget(int corner);
KMETHOD QMenuBar_getCornerWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		Qt::Corner corner = Int_to(Qt::Corner, sfp[1]);
		QWidget* ret_v = qp->cornerWidget(corner);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAction QMenuBar.insertMenu(QAction before, QMenu menu);
KMETHOD QMenuBar_insertMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		QAction*  before = RawPtr_to(QAction*, sfp[1]);
		QMenu*  menu = RawPtr_to(QMenu*, sfp[2]);
		QAction* ret_v = qp->insertMenu(before, menu);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAction QMenuBar.insertSeparator(QAction before);
KMETHOD QMenuBar_insertSeparator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		QAction*  before = RawPtr_to(QAction*, sfp[1]);
		QAction* ret_v = qp->insertSeparator(before);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QMenuBar.isDefaultUp();
KMETHOD QMenuBar_isDefaultUp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isDefaultUp();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QMenuBar.isNativeMenuBar();
KMETHOD QMenuBar_isNativeMenuBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isNativeMenuBar();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QMenuBar.setActiveAction(QAction act);
KMETHOD QMenuBar_setActiveAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		QAction*  act = RawPtr_to(QAction*, sfp[1]);
		qp->setActiveAction(act);
	}
	RETURNvoid_();
}

//void QMenuBar.setCornerWidget(QWidget widget, int corner);
KMETHOD QMenuBar_setCornerWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		Qt::Corner corner = Int_to(Qt::Corner, sfp[2]);
		qp->setCornerWidget(widget, corner);
	}
	RETURNvoid_();
}

//void QMenuBar.setDefaultUp(boolean arg0);
KMETHOD QMenuBar_setDefaultUp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setDefaultUp(arg0);
	}
	RETURNvoid_();
}

//void QMenuBar.setNativeMenuBar(boolean nativeMenuBar);
KMETHOD QMenuBar_setNativeMenuBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		bool nativeMenuBar = Boolean_to(bool, sfp[1]);
		qp->setNativeMenuBar(nativeMenuBar);
	}
	RETURNvoid_();
}

//@Virtual void QMenuBar.setVisible(boolean visible);
KMETHOD QMenuBar_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QMenuBar *  qp = RawPtr_to(QMenuBar *, sfp[0]);
	if (qp) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setVisible(visible);
	}
	RETURNvoid_();
}


DummyQMenuBar::DummyQMenuBar()
{
	self = NULL;
	hovered_func = NULL;
	triggered_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("hovered", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("triggered", NULL));
}

void DummyQMenuBar::setSelf(knh_RawPtr_t *ptr)
{
	DummyQMenuBar::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQMenuBar::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQMenuBar::hoveredSlot(QAction* action)
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

bool DummyQMenuBar::triggeredSlot(QAction* action)
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

bool DummyQMenuBar::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMenuBar::event_map->bigin();
	if ((itr = DummyQMenuBar::event_map->find(str)) == DummyQMenuBar::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQMenuBar::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQMenuBar::slot_map->bigin();
	if ((itr = DummyQMenuBar::slot_map->find(str)) == DummyQMenuBar::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		hovered_func = (*slot_map)["hovered"];
		triggered_func = (*slot_map)["triggered"];
		return true;
	}
}

knh_Object_t** DummyQMenuBar::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQMenuBar::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, hovered_func);
	KNH_ADDNNREF(ctx, triggered_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQWidget::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQMenuBar::connection(QObject *o)
{
	QMenuBar *p = dynamic_cast<QMenuBar*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(hovered(QAction*)), this, SLOT(hoveredSlot(QAction*)));
		connect(p, SIGNAL(triggered(QAction*)), this, SLOT(triggeredSlot(QAction*)));
	}
	DummyQWidget::connection(o);
}

KQMenuBar::KQMenuBar(QWidget* parent) : QMenuBar(parent)
{
	self = NULL;
	dummy = new DummyQMenuBar();
	dummy->connection((QObject*)this);
}

KMETHOD QMenuBar_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMenuBar *qp = RawPtr_to(KQMenuBar *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QMenuBar]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMenuBar]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QMenuBar_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQMenuBar *qp = RawPtr_to(KQMenuBar *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QMenuBar]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QMenuBar]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QMenuBar_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQMenuBar *qp = (KQMenuBar *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QMenuBar_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQMenuBar *qp = (KQMenuBar *)p->rawptr;
//		KQMenuBar *qp = static_cast<KQMenuBar*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QMenuBar_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQMenuBar::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQMenuBar::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QMenuBar::event(event);
		return false;
	}
//	QMenuBar::event(event);
	return true;
}



DEFAPI(void) defQMenuBar(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QMenuBar";
	cdef->free = QMenuBar_free;
	cdef->reftrace = QMenuBar_reftrace;
	cdef->compareTo = QMenuBar_compareTo;
}


