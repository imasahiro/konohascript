//
//boolean QAbstractButton.getAutoExclusive();
KMETHOD QAbstractButton_getAutoExclusive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		bool ret_v = qp->autoExclusive();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAbstractButton.getAutoRepeat();
KMETHOD QAbstractButton_getAutoRepeat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		bool ret_v = qp->autoRepeat();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QAbstractButton.getAutoRepeatDelay();
KMETHOD QAbstractButton_getAutoRepeatDelay(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		int ret_v = qp->autoRepeatDelay();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAbstractButton.getAutoRepeatInterval();
KMETHOD QAbstractButton_getAutoRepeatInterval(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		int ret_v = qp->autoRepeatInterval();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QButtonGroup QAbstractButton.group();
KMETHOD QAbstractButton_group(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		QButtonGroup* ret_v = qp->group();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QButtonGroup*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QIcon QAbstractButton.getIcon();
KMETHOD QAbstractButton_getIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		QIcon ret_v = qp->icon();
		QIcon *ret_v_ = new QIcon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSize QAbstractButton.getIconSize();
KMETHOD QAbstractButton_getIconSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->iconSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QAbstractButton.isCheckable();
KMETHOD QAbstractButton_isCheckable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isCheckable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAbstractButton.isChecked();
KMETHOD QAbstractButton_isChecked(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isChecked();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAbstractButton.isDown();
KMETHOD QAbstractButton_isDown(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isDown();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QAbstractButton.setAutoExclusive(boolean arg0);
KMETHOD QAbstractButton_setAutoExclusive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setAutoExclusive(arg0);
	}
	RETURNvoid_();
}

//void QAbstractButton.setAutoRepeat(boolean arg0);
KMETHOD QAbstractButton_setAutoRepeat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setAutoRepeat(arg0);
	}
	RETURNvoid_();
}

//void QAbstractButton.setAutoRepeatDelay(int arg0);
KMETHOD QAbstractButton_setAutoRepeatDelay(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setAutoRepeatDelay(arg0);
	}
	RETURNvoid_();
}

//void QAbstractButton.setAutoRepeatInterval(int arg0);
KMETHOD QAbstractButton_setAutoRepeatInterval(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setAutoRepeatInterval(arg0);
	}
	RETURNvoid_();
}

//void QAbstractButton.setCheckable(boolean arg0);
KMETHOD QAbstractButton_setCheckable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setCheckable(arg0);
	}
	RETURNvoid_();
}

//void QAbstractButton.setDown(boolean arg0);
KMETHOD QAbstractButton_setDown(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setDown(arg0);
	}
	RETURNvoid_();
}

//void QAbstractButton.setIcon(QIcon icon);
KMETHOD QAbstractButton_setIcon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
		qp->setIcon(icon);
	}
	RETURNvoid_();
}

//void QAbstractButton.setShortcut(QKeySequence key);
KMETHOD QAbstractButton_setShortcut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		const QKeySequence  key = *RawPtr_to(const QKeySequence *, sfp[1]);
		qp->setShortcut(key);
	}
	RETURNvoid_();
}

//void QAbstractButton.setText(String text);
KMETHOD QAbstractButton_setText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setText(text);
	}
	RETURNvoid_();
}

//QKeySequence QAbstractButton.getShortcut();
KMETHOD QAbstractButton_getShortcut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		QKeySequence ret_v = qp->shortcut();
		QKeySequence *ret_v_ = new QKeySequence(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QAbstractButton.getText();
KMETHOD QAbstractButton_getText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		QString ret_v = qp->text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QAbstractButton.animateClick(int msec);
KMETHOD QAbstractButton_animateClick(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		int msec = Int_to(int, sfp[1]);
		qp->animateClick(msec);
	}
	RETURNvoid_();
}

//void QAbstractButton.click();
KMETHOD QAbstractButton_click(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		qp->click();
	}
	RETURNvoid_();
}

//void QAbstractButton.setChecked(boolean arg0);
KMETHOD QAbstractButton_setChecked(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setChecked(arg0);
	}
	RETURNvoid_();
}

//void QAbstractButton.setIconSize(QSize size);
KMETHOD QAbstractButton_setIconSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		const QSize  size = *RawPtr_to(const QSize *, sfp[1]);
		qp->setIconSize(size);
	}
	RETURNvoid_();
}

//void QAbstractButton.toggle();
KMETHOD QAbstractButton_toggle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractButton *  qp = RawPtr_to(QAbstractButton *, sfp[0]);
	if (qp) {
		qp->toggle();
	}
	RETURNvoid_();
}


DummyQAbstractButton::DummyQAbstractButton()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	clicked_func = NULL;
	pressed_func = NULL;
	released_func = NULL;
	toggled_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("clicked", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("pressed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("released", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("toggled", NULL));
}
DummyQAbstractButton::~DummyQAbstractButton()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQAbstractButton::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractButton::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQAbstractButton::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractButton::clickedSlot(bool checked)
{
	if (clicked_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = checked;
		knh_Func_invoke(lctx, clicked_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQAbstractButton::pressedSlot()
{
	if (pressed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, pressed_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAbstractButton::releasedSlot()
{
	if (released_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, released_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAbstractButton::toggledSlot(bool checked)
{
	if (toggled_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = checked;
		knh_Func_invoke(lctx, toggled_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQAbstractButton::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractButton::event_map->bigin();
	if ((itr = DummyQAbstractButton::event_map->find(str)) == DummyQAbstractButton::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractButton::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractButton::slot_map->bigin();
	if ((itr = DummyQAbstractButton::slot_map->find(str)) == DummyQAbstractButton::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		clicked_func = (*slot_map)["clicked"];
		pressed_func = (*slot_map)["pressed"];
		released_func = (*slot_map)["released"];
		toggled_func = (*slot_map)["toggled"];
		return true;
	}
}

knh_Object_t** DummyQAbstractButton::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQAbstractButton::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 5;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, clicked_func);
	KNH_ADDNNREF(ctx, pressed_func);
	KNH_ADDNNREF(ctx, released_func);
	KNH_ADDNNREF(ctx, toggled_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQWidget::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQAbstractButton::connection(QObject *o)
{
	QAbstractButton *p = dynamic_cast<QAbstractButton*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(clicked(bool)), this, SLOT(clickedSlot(bool)));
		connect(p, SIGNAL(pressed()), this, SLOT(pressedSlot()));
		connect(p, SIGNAL(released()), this, SLOT(releasedSlot()));
		connect(p, SIGNAL(toggled(bool)), this, SLOT(toggledSlot(bool)));
	}
	DummyQWidget::connection(o);
}

KQAbstractButton::KQAbstractButton(QWidget* parent) : QAbstractButton(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQAbstractButton();
	dummy->connection((QObject*)this);
}

KQAbstractButton::~KQAbstractButton()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QAbstractButton_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractButton *qp = RawPtr_to(KQAbstractButton *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractButton]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractButton]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAbstractButton_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractButton *qp = RawPtr_to(KQAbstractButton *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractButton]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractButton]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractButton_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQAbstractButton *qp = (KQAbstractButton *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QAbstractButton*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QAbstractButton_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQAbstractButton *qp = (KQAbstractButton *)p->rawptr;
		KQAbstractButton *qp = static_cast<KQAbstractButton*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAbstractButton_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAbstractButton::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQAbstractButton::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QAbstractButton::event(event);
		return false;
	}
//	QAbstractButton::event(event);
	return true;
}



DEFAPI(void) defQAbstractButton(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractButton";
	cdef->free = QAbstractButton_free;
	cdef->reftrace = QAbstractButton_reftrace;
	cdef->compareTo = QAbstractButton_compareTo;
}


