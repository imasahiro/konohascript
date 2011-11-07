//@Virtual @Override QSize QToolButton.minimumSizeHint();
KMETHOD QToolButton_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolButton *  qp = RawPtr_to(QToolButton *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QToolButton.sizeHint();
KMETHOD QToolButton_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolButton *  qp = RawPtr_to(QToolButton *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QToolButton QToolButton.new(QWidget parent);
KMETHOD QToolButton_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQToolButton *ret_v = new KQToolButton(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QToolButton.getArrowType();
KMETHOD QToolButton_getArrowType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolButton *  qp = RawPtr_to(QToolButton *, sfp[0]);
	if (qp) {
		Qt::ArrowType ret_v = qp->arrowType();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QToolButton.getAutoRaise();
KMETHOD QToolButton_getAutoRaise(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolButton *  qp = RawPtr_to(QToolButton *, sfp[0]);
	if (qp) {
		bool ret_v = qp->autoRaise();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QMenu QToolButton.getMenu();
KMETHOD QToolButton_getMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolButton *  qp = RawPtr_to(QToolButton *, sfp[0]);
	if (qp) {
		QMenu* ret_v = qp->menu();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMenu*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QToolButton.getPopupMode();
KMETHOD QToolButton_getPopupMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolButton *  qp = RawPtr_to(QToolButton *, sfp[0]);
	if (qp) {
		QToolButton::ToolButtonPopupMode ret_v = qp->popupMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QToolButton.setArrowType(int type);
KMETHOD QToolButton_setArrowType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolButton *  qp = RawPtr_to(QToolButton *, sfp[0]);
	if (qp) {
		Qt::ArrowType type = Int_to(Qt::ArrowType, sfp[1]);
		qp->setArrowType(type);
	}
	RETURNvoid_();
}

//void QToolButton.setAutoRaise(boolean enable);
KMETHOD QToolButton_setAutoRaise(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolButton *  qp = RawPtr_to(QToolButton *, sfp[0]);
	if (qp) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setAutoRaise(enable);
	}
	RETURNvoid_();
}

//void QToolButton.setMenu(QMenu menu);
KMETHOD QToolButton_setMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolButton *  qp = RawPtr_to(QToolButton *, sfp[0]);
	if (qp) {
		QMenu*  menu = RawPtr_to(QMenu*, sfp[1]);
		qp->setMenu(menu);
	}
	RETURNvoid_();
}

//void QToolButton.setPopupMode(int mode);
KMETHOD QToolButton_setPopupMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolButton *  qp = RawPtr_to(QToolButton *, sfp[0]);
	if (qp) {
		QToolButton::ToolButtonPopupMode mode = Int_to(QToolButton::ToolButtonPopupMode, sfp[1]);
		qp->setPopupMode(mode);
	}
	RETURNvoid_();
}

//int QToolButton.getToolButtonStyle();
KMETHOD QToolButton_getToolButtonStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolButton *  qp = RawPtr_to(QToolButton *, sfp[0]);
	if (qp) {
		Qt::ToolButtonStyle ret_v = qp->toolButtonStyle();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QToolButton.setToolButtonStyle(int style);
KMETHOD QToolButton_setToolButtonStyle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolButton *  qp = RawPtr_to(QToolButton *, sfp[0]);
	if (qp) {
		Qt::ToolButtonStyle style = Int_to(Qt::ToolButtonStyle, sfp[1]);
		qp->setToolButtonStyle(style);
	}
	RETURNvoid_();
}

//void QToolButton.showMenu();
KMETHOD QToolButton_showMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QToolButton *  qp = RawPtr_to(QToolButton *, sfp[0]);
	if (qp) {
		qp->showMenu();
	}
	RETURNvoid_();
}


DummyQToolButton::DummyQToolButton()
{
	self = NULL;
	triggered_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("triggered", NULL));
}

void DummyQToolButton::setSelf(knh_RawPtr_t *ptr)
{
	DummyQToolButton::self = ptr;
	DummyQAbstractButton::setSelf(ptr);
}

bool DummyQToolButton::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractButton::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQToolButton::triggeredSlot(QAction* action)
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

bool DummyQToolButton::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQToolButton::event_map->bigin();
	if ((itr = DummyQToolButton::event_map->find(str)) == DummyQToolButton::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractButton::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQToolButton::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQToolButton::slot_map->bigin();
	if ((itr = DummyQToolButton::slot_map->find(str)) == DummyQToolButton::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractButton::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		triggered_func = (*slot_map)["triggered"];
		return true;
	}
}

void DummyQToolButton::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 1;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, triggered_func);

	KNH_SIZEREF(ctx);

	DummyQAbstractButton::reftrace(ctx, p, tail_);
}

void DummyQToolButton::connection(QObject *o)
{
	QToolButton *p = dynamic_cast<QToolButton*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(triggered(QAction*)), this, SLOT(triggeredSlot(QAction*)));
	}
	DummyQAbstractButton::connection(o);
}

KQToolButton::KQToolButton(QWidget* parent) : QToolButton(parent)
{
	self = NULL;
	dummy = new DummyQToolButton();
	dummy->connection((QObject*)this);
}

KMETHOD QToolButton_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQToolButton *qp = RawPtr_to(KQToolButton *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QToolButton]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QToolButton]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QToolButton_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQToolButton *qp = RawPtr_to(KQToolButton *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QToolButton]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QToolButton]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QToolButton_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQToolButton *qp = (KQToolButton *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QToolButton_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQToolButton *qp = (KQToolButton *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QToolButton_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQToolButton::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQToolButton::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QToolButton::event(event);
		return false;
	}
	return true;
}

static knh_IntData_t QToolButtonConstInt[] = {
	{"DelayedPopup", QToolButton::DelayedPopup},
	{"MenuButtonPopup", QToolButton::MenuButtonPopup},
	{"InstantPopup", QToolButton::InstantPopup},
	{NULL, 0}
};

DEFAPI(void) constQToolButton(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QToolButtonConstInt);
}


DEFAPI(void) defQToolButton(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QToolButton";
	cdef->free = QToolButton_free;
	cdef->reftrace = QToolButton_reftrace;
	cdef->compareTo = QToolButton_compareTo;
}


