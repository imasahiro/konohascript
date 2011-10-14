//QDialogButtonBox QDialogButtonBox.new(QWidget parent);
KMETHOD QDialogButtonBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQDialogButtonBox *ret_v = new KQDialogButtonBox(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QDialogButtonBox QDialogButtonBox.new(int orientation, QWidget parent);
KMETHOD QDialogButtonBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQDialogButtonBox *ret_v = new KQDialogButtonBox(orientation, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QDialogButtonBox QDialogButtonBox.new(int buttons, int orientation, QWidget parent);
KMETHOD QDialogButtonBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialogButtonBox::StandardButtons buttons = Int_to(QDialogButtonBox::StandardButtons, sfp[1]);
	Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[2]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[3]);
	KQDialogButtonBox *ret_v = new KQDialogButtonBox(buttons, orientation, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QDialogButtonBox.addButton(QAbstractButton button, int role);
KMETHOD QDialogButtonBox_addButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialogButtonBox *  qp = RawPtr_to(QDialogButtonBox *, sfp[0]);
	if (qp != NULL) {
		QAbstractButton*  button = RawPtr_to(QAbstractButton*, sfp[1]);
		QDialogButtonBox::ButtonRole role = Int_to(QDialogButtonBox::ButtonRole, sfp[2]);
		qp->addButton(button, role);
	}
	RETURNvoid_();
}

/*
//QPushButton QDialogButtonBox.addButton(String text, int role);
KMETHOD QDialogButtonBox_addButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialogButtonBox *  qp = RawPtr_to(QDialogButtonBox *, sfp[0]);
	if (qp != NULL) {
		const QString text = String_to(const QString, sfp[1]);
		QDialogButtonBox::ButtonRole role = Int_to(QDialogButtonBox::ButtonRole, sfp[2]);
		QPushButton* ret_v = qp->addButton(text, role);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPushButton*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QPushButton QDialogButtonBox.addButton(int button);
KMETHOD QDialogButtonBox_addButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialogButtonBox *  qp = RawPtr_to(QDialogButtonBox *, sfp[0]);
	if (qp != NULL) {
		QDialogButtonBox::StandardButton button = Int_to(QDialogButtonBox::StandardButton, sfp[1]);
		QPushButton* ret_v = qp->addButton(button);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPushButton*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QPushButton QDialogButtonBox.button(int which);
KMETHOD QDialogButtonBox_button(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialogButtonBox *  qp = RawPtr_to(QDialogButtonBox *, sfp[0]);
	if (qp != NULL) {
		QDialogButtonBox::StandardButton which = Int_to(QDialogButtonBox::StandardButton, sfp[1]);
		QPushButton* ret_v = qp->button(which);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPushButton*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDialogButtonBox.buttonRole(QAbstractButton button);
KMETHOD QDialogButtonBox_buttonRole(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialogButtonBox *  qp = RawPtr_to(QDialogButtonBox *, sfp[0]);
	if (qp != NULL) {
		QAbstractButton*  button = RawPtr_to(QAbstractButton*, sfp[1]);
		QDialogButtonBox::ButtonRole ret_v = qp->buttonRole(button);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<QAbstractButton> QDialogButtonBox.buttons();
KMETHOD QDialogButtonBox_buttons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialogButtonBox *  qp = RawPtr_to(QDialogButtonBox *, sfp[0]);
	if (qp != NULL) {
		QList<QAbstractButton*>ret_v = qp->buttons();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QAbstractButton"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//boolean QDialogButtonBox.getCenterButtons();
KMETHOD QDialogButtonBox_getCenterButtons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialogButtonBox *  qp = RawPtr_to(QDialogButtonBox *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->centerButtons();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QDialogButtonBox.clear();
KMETHOD QDialogButtonBox_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialogButtonBox *  qp = RawPtr_to(QDialogButtonBox *, sfp[0]);
	if (qp != NULL) {
		qp->clear();
	}
	RETURNvoid_();
}

//int QDialogButtonBox.getOrientation();
KMETHOD QDialogButtonBox_getOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialogButtonBox *  qp = RawPtr_to(QDialogButtonBox *, sfp[0]);
	if (qp != NULL) {
		Qt::Orientation ret_v = qp->orientation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QDialogButtonBox.removeButton(QAbstractButton button);
KMETHOD QDialogButtonBox_removeButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialogButtonBox *  qp = RawPtr_to(QDialogButtonBox *, sfp[0]);
	if (qp != NULL) {
		QAbstractButton*  button = RawPtr_to(QAbstractButton*, sfp[1]);
		qp->removeButton(button);
	}
	RETURNvoid_();
}

//void QDialogButtonBox.setCenterButtons(boolean center);
KMETHOD QDialogButtonBox_setCenterButtons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialogButtonBox *  qp = RawPtr_to(QDialogButtonBox *, sfp[0]);
	if (qp != NULL) {
		bool center = Boolean_to(bool, sfp[1]);
		qp->setCenterButtons(center);
	}
	RETURNvoid_();
}

//void QDialogButtonBox.setOrientation(int orientation);
KMETHOD QDialogButtonBox_setOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialogButtonBox *  qp = RawPtr_to(QDialogButtonBox *, sfp[0]);
	if (qp != NULL) {
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
		qp->setOrientation(orientation);
	}
	RETURNvoid_();
}

//void QDialogButtonBox.setStandardButtons(int buttons);
KMETHOD QDialogButtonBox_setStandardButtons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialogButtonBox *  qp = RawPtr_to(QDialogButtonBox *, sfp[0]);
	if (qp != NULL) {
		QDialogButtonBox::StandardButtons buttons = Int_to(QDialogButtonBox::StandardButtons, sfp[1]);
		qp->setStandardButtons(buttons);
	}
	RETURNvoid_();
}

//int QDialogButtonBox.standardButton(QAbstractButton button);
KMETHOD QDialogButtonBox_standardButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialogButtonBox *  qp = RawPtr_to(QDialogButtonBox *, sfp[0]);
	if (qp != NULL) {
		QAbstractButton*  button = RawPtr_to(QAbstractButton*, sfp[1]);
		QDialogButtonBox::StandardButton ret_v = qp->standardButton(button);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QDialogButtonBox.getStandardButtons();
KMETHOD QDialogButtonBox_getStandardButtons(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialogButtonBox *  qp = RawPtr_to(QDialogButtonBox *, sfp[0]);
	if (qp != NULL) {
		QDialogButtonBox::StandardButtons ret_v = qp->standardButtons();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQDialogButtonBox::DummyQDialogButtonBox()
{
	self = NULL;
	accepted_func = NULL;
	clicked_func = NULL;
	help_requested_func = NULL;
	rejected_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("accepted", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("clicked", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("help-requested", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("rejected", NULL));
}

void DummyQDialogButtonBox::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDialogButtonBox::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQDialogButtonBox::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQDialogButtonBox::acceptedSlot()
{
	if (accepted_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, accepted_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQDialogButtonBox::clickedSlot(QAbstractButton* button)
{
	if (clicked_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QAbstractButton, button);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, clicked_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQDialogButtonBox::helpRequestedSlot()
{
	if (help_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, help_requested_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQDialogButtonBox::rejectedSlot()
{
	if (rejected_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, rejected_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQDialogButtonBox::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDialogButtonBox::event_map->bigin();
	if ((itr = DummyQDialogButtonBox::event_map->find(str)) == DummyQDialogButtonBox::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDialogButtonBox::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDialogButtonBox::slot_map->bigin();
	if ((itr = DummyQDialogButtonBox::slot_map->find(str)) == DummyQDialogButtonBox::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		accepted_func = (*slot_map)["accepted"];
		clicked_func = (*slot_map)["clicked"];
		help_requested_func = (*slot_map)["help-requested"];
		rejected_func = (*slot_map)["rejected"];
		return true;
	}
}


void DummyQDialogButtonBox::connection(QObject *o)
{
	connect(o, SIGNAL(accepted()), this, SLOT(acceptedSlot()));
	connect(o, SIGNAL(clicked(QAbstractButton*)), this, SLOT(clickedSlot(QAbstractButton*)));
	connect(o, SIGNAL(helpRequested()), this, SLOT(helpRequestedSlot()));
	connect(o, SIGNAL(rejected()), this, SLOT(rejectedSlot()));
	DummyQWidget::connection(o);
}

KQDialogButtonBox::KQDialogButtonBox(QWidget* parent) : QDialogButtonBox(parent)
{
	self = NULL;
	dummy = new DummyQDialogButtonBox();
	dummy->connection((QObject*)this);
}

KMETHOD QDialogButtonBox_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDialogButtonBox *qp = RawPtr_to(KQDialogButtonBox *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDialogButtonBox]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDialogButtonBox]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QDialogButtonBox_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDialogButtonBox *qp = RawPtr_to(KQDialogButtonBox *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDialogButtonBox]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDialogButtonBox]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDialogButtonBox_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDialogButtonBox *qp = (KQDialogButtonBox *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDialogButtonBox_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 4;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQDialogButtonBox *qp = (KQDialogButtonBox *)p->rawptr;
//		(void)qp;
		if (qp->dummy->accepted_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->accepted_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->clicked_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->clicked_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->help_requested_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->help_requested_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->rejected_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->rejected_func);
			KNH_SIZEREF(ctx);
		}
	}
}

static int QDialogButtonBox_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQDialogButtonBox::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQDialogButtonBox::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QDialogButtonBox::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQDialogButtonBox(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDialogButtonBox";
	cdef->free = QDialogButtonBox_free;
	cdef->reftrace = QDialogButtonBox_reftrace;
	cdef->compareTo = QDialogButtonBox_compareTo;
}

static knh_IntData_t QDialogButtonBoxConstInt[] = {
	{"WinLayout", QDialogButtonBox::WinLayout},
	{"MacLayout", QDialogButtonBox::MacLayout},
	{"KdeLayout", QDialogButtonBox::KdeLayout},
	{"GnomeLayout", QDialogButtonBox::GnomeLayout},
	{"InvalidRole", QDialogButtonBox::InvalidRole},
	{"AcceptRole", QDialogButtonBox::AcceptRole},
	{"RejectRole", QDialogButtonBox::RejectRole},
	{"DestructiveRole", QDialogButtonBox::DestructiveRole},
	{"ActionRole", QDialogButtonBox::ActionRole},
	{"HelpRole", QDialogButtonBox::HelpRole},
	{"YesRole", QDialogButtonBox::YesRole},
	{"NoRole", QDialogButtonBox::NoRole},
	{"ApplyRole", QDialogButtonBox::ApplyRole},
	{"ResetRole", QDialogButtonBox::ResetRole},
	{"Ok", QDialogButtonBox::Ok},
	{"Open", QDialogButtonBox::Open},
	{"Save", QDialogButtonBox::Save},
	{"Cancel", QDialogButtonBox::Cancel},
	{"Close", QDialogButtonBox::Close},
	{"Discard", QDialogButtonBox::Discard},
	{"Apply", QDialogButtonBox::Apply},
	{"Reset", QDialogButtonBox::Reset},
	{"RestoreDefaults", QDialogButtonBox::RestoreDefaults},
	{"Help", QDialogButtonBox::Help},
	{"SaveAll", QDialogButtonBox::SaveAll},
	{"Yes", QDialogButtonBox::Yes},
	{"YesToAll", QDialogButtonBox::YesToAll},
	{"No", QDialogButtonBox::No},
	{"NoToAll", QDialogButtonBox::NoToAll},
	{"Abort", QDialogButtonBox::Abort},
	{"Retry", QDialogButtonBox::Retry},
	{"Ignore", QDialogButtonBox::Ignore},
	{"NoButton", QDialogButtonBox::NoButton},
	{NULL, 0}
};

DEFAPI(void) constQDialogButtonBox(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QDialogButtonBoxConstInt);
}

