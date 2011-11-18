//QSystemTrayIcon QSystemTrayIcon.new(QObject parent);
KMETHOD QSystemTrayIcon_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQSystemTrayIcon *ret_v = new KQSystemTrayIcon(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QSystemTrayIcon QSystemTrayIcon.new(QIcon icon, QObject parent);
KMETHOD QSystemTrayIcon_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
	QObject*  parent = RawPtr_to(QObject*, sfp[2]);
	KQSystemTrayIcon *ret_v = new KQSystemTrayIcon(icon, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QMenu QSystemTrayIcon.getContextMenu();
KMETHOD QSystemTrayIcon_getContextMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemTrayIcon *  qp = RawPtr_to(QSystemTrayIcon *, sfp[0]);
	if (qp) {
		QMenu* ret_v = qp->contextMenu();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMenu*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QSystemTrayIcon.geometry();
KMETHOD QSystemTrayIcon_geometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemTrayIcon *  qp = RawPtr_to(QSystemTrayIcon *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->geometry();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QIcon QSystemTrayIcon.getIcon();
KMETHOD QSystemTrayIcon_getIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemTrayIcon *  qp = RawPtr_to(QSystemTrayIcon *, sfp[0]);
	if (qp) {
		QIcon ret_v = qp->icon();
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QSystemTrayIcon.isVisible();
KMETHOD QSystemTrayIcon_isVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemTrayIcon *  qp = RawPtr_to(QSystemTrayIcon *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isVisible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QSystemTrayIcon.setContextMenu(QMenu menu);
KMETHOD QSystemTrayIcon_setContextMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemTrayIcon *  qp = RawPtr_to(QSystemTrayIcon *, sfp[0]);
	if (qp) {
		QMenu*  menu = RawPtr_to(QMenu*, sfp[1]);
		qp->setContextMenu(menu);
	}
	RETURNvoid_();
}

//void QSystemTrayIcon.setIcon(QIcon icon);
KMETHOD QSystemTrayIcon_setIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemTrayIcon *  qp = RawPtr_to(QSystemTrayIcon *, sfp[0]);
	if (qp) {
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
		qp->setIcon(icon);
	}
	RETURNvoid_();
}

//void QSystemTrayIcon.setToolTip(String tip);
KMETHOD QSystemTrayIcon_setToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemTrayIcon *  qp = RawPtr_to(QSystemTrayIcon *, sfp[0]);
	if (qp) {
		const QString tip = String_to(const QString, sfp[1]);
		qp->setToolTip(tip);
	}
	RETURNvoid_();
}

//void QSystemTrayIcon.showMessage(String title, String message, int icon, int millisecondsTimeoutHint);
KMETHOD QSystemTrayIcon_showMessage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemTrayIcon *  qp = RawPtr_to(QSystemTrayIcon *, sfp[0]);
	if (qp) {
		const QString title = String_to(const QString, sfp[1]);
		const QString message = String_to(const QString, sfp[2]);
		QSystemTrayIcon::MessageIcon icon = Int_to(QSystemTrayIcon::MessageIcon, sfp[3]);
		int millisecondsTimeoutHint = Int_to(int, sfp[4]);
		qp->showMessage(title, message, icon, millisecondsTimeoutHint);
	}
	RETURNvoid_();
}

//String QSystemTrayIcon.getToolTip();
KMETHOD QSystemTrayIcon_getToolTip(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemTrayIcon *  qp = RawPtr_to(QSystemTrayIcon *, sfp[0]);
	if (qp) {
		QString ret_v = qp->toolTip();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QSystemTrayIcon.isSystemTrayAvailable();
KMETHOD QSystemTrayIcon_isSystemTrayAvailable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QSystemTrayIcon::isSystemTrayAvailable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QSystemTrayIcon.supportsMessages();
KMETHOD QSystemTrayIcon_supportsMessages(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool ret_v = QSystemTrayIcon::supportsMessages();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QSystemTrayIcon.hide();
KMETHOD QSystemTrayIcon_hide(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemTrayIcon *  qp = RawPtr_to(QSystemTrayIcon *, sfp[0]);
	if (qp) {
		qp->hide();
	}
	RETURNvoid_();
}

//void QSystemTrayIcon.setVisible(boolean visible);
KMETHOD QSystemTrayIcon_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemTrayIcon *  qp = RawPtr_to(QSystemTrayIcon *, sfp[0]);
	if (qp) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setVisible(visible);
	}
	RETURNvoid_();
}

//void QSystemTrayIcon.show();
KMETHOD QSystemTrayIcon_show(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSystemTrayIcon *  qp = RawPtr_to(QSystemTrayIcon *, sfp[0]);
	if (qp) {
		qp->show();
	}
	RETURNvoid_();
}


DummyQSystemTrayIcon::DummyQSystemTrayIcon()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	activated_func = NULL;
	message_clicked_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("activated", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("message-clicked", NULL));
}
DummyQSystemTrayIcon::~DummyQSystemTrayIcon()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQSystemTrayIcon::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSystemTrayIcon::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQSystemTrayIcon::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQSystemTrayIcon::activatedSlot(QSystemTrayIcon::ActivationReason reason)
{
	if (activated_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = reason;
		knh_Func_invoke(lctx, activated_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQSystemTrayIcon::messageClickedSlot()
{
	if (message_clicked_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, message_clicked_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQSystemTrayIcon::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSystemTrayIcon::event_map->bigin();
	if ((itr = DummyQSystemTrayIcon::event_map->find(str)) == DummyQSystemTrayIcon::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSystemTrayIcon::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSystemTrayIcon::slot_map->bigin();
	if ((itr = DummyQSystemTrayIcon::slot_map->find(str)) == DummyQSystemTrayIcon::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		activated_func = (*slot_map)["activated"];
		message_clicked_func = (*slot_map)["message-clicked"];
		return true;
	}
}

knh_Object_t** DummyQSystemTrayIcon::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQSystemTrayIcon::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 3;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, activated_func);
	KNH_ADDNNREF(ctx, message_clicked_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQSystemTrayIcon::connection(QObject *o)
{
	QSystemTrayIcon *p = dynamic_cast<QSystemTrayIcon*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(activatedSlot(QSystemTrayIcon::ActivationReason)));
		connect(p, SIGNAL(messageClicked()), this, SLOT(messageClickedSlot()));
	}
	DummyQObject::connection(o);
}

KQSystemTrayIcon::KQSystemTrayIcon(QObject* parent) : QSystemTrayIcon(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQSystemTrayIcon();
	dummy->connection((QObject*)this);
}

KQSystemTrayIcon::~KQSystemTrayIcon()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QSystemTrayIcon_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSystemTrayIcon *qp = RawPtr_to(KQSystemTrayIcon *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSystemTrayIcon]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSystemTrayIcon]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSystemTrayIcon_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSystemTrayIcon *qp = RawPtr_to(KQSystemTrayIcon *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSystemTrayIcon]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSystemTrayIcon]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSystemTrayIcon_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQSystemTrayIcon *qp = (KQSystemTrayIcon *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QSystemTrayIcon*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QSystemTrayIcon_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQSystemTrayIcon *qp = (KQSystemTrayIcon *)p->rawptr;
		KQSystemTrayIcon *qp = static_cast<KQSystemTrayIcon*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSystemTrayIcon_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSystemTrayIcon::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQSystemTrayIcon::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QSystemTrayIcon::event(event);
		return false;
	}
//	QSystemTrayIcon::event(event);
	return true;
}

static knh_IntData_t QSystemTrayIconConstInt[] = {
	{"Unknown", QSystemTrayIcon::Unknown},
	{"Context", QSystemTrayIcon::Context},
	{"DoubleClick", QSystemTrayIcon::DoubleClick},
	{"Trigger", QSystemTrayIcon::Trigger},
	{"MiddleClick", QSystemTrayIcon::MiddleClick},
	{"NoIcon", QSystemTrayIcon::NoIcon},
	{"Information", QSystemTrayIcon::Information},
	{"Warning", QSystemTrayIcon::Warning},
	{"Critical", QSystemTrayIcon::Critical},
	{NULL, 0}
};

DEFAPI(void) constQSystemTrayIcon(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QSystemTrayIconConstInt);
}


DEFAPI(void) defQSystemTrayIcon(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSystemTrayIcon";
	cdef->free = QSystemTrayIcon_free;
	cdef->reftrace = QSystemTrayIcon_reftrace;
	cdef->compareTo = QSystemTrayIcon_compareTo;
}


