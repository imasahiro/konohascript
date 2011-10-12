//@Virtual @Override QSize QPushButton.minimumSizeHint();
KMETHOD QPushButton_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPushButton *  qp = RawPtr_to(QPushButton *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QPushButton.sizeHint();
KMETHOD QPushButton_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPushButton *  qp = RawPtr_to(QPushButton *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPushButton QPushButton.new(QWidget parent);
KMETHOD QPushButton_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQPushButton *ret_v = new KQPushButton(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPushButton QPushButton.new(String text, QWidget parent);
KMETHOD QPushButton_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString text = String_to(const QString, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQPushButton *ret_v = new KQPushButton(text, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPushButton QPushButton.new(QIcon icon, String text, QWidget parent);
KMETHOD QPushButton_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
	const QString text = String_to(const QString, sfp[2]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[3]);
	KQPushButton *ret_v = new KQPushButton(icon, text, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QPushButton.getAutoDefault();
KMETHOD QPushButton_getAutoDefault(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPushButton *  qp = RawPtr_to(QPushButton *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->autoDefault();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPushButton.isDefault();
KMETHOD QPushButton_isDefault(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPushButton *  qp = RawPtr_to(QPushButton *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isDefault();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QPushButton.isFlat();
KMETHOD QPushButton_isFlat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPushButton *  qp = RawPtr_to(QPushButton *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isFlat();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QMenu QPushButton.getMenu();
KMETHOD QPushButton_getMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPushButton *  qp = RawPtr_to(QPushButton *, sfp[0]);
	if (qp != NULL) {
		QMenu* ret_v = qp->menu();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QMenu*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QPushButton.setAutoDefault(boolean arg0);
KMETHOD QPushButton_setAutoDefault(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPushButton *  qp = RawPtr_to(QPushButton *, sfp[0]);
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setAutoDefault(arg0);
	}
	RETURNvoid_();
}

//void QPushButton.setDefault(boolean arg0);
KMETHOD QPushButton_setDefault(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPushButton *  qp = RawPtr_to(QPushButton *, sfp[0]);
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setDefault(arg0);
	}
	RETURNvoid_();
}

//void QPushButton.setFlat(boolean arg0);
KMETHOD QPushButton_setFlat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPushButton *  qp = RawPtr_to(QPushButton *, sfp[0]);
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setFlat(arg0);
	}
	RETURNvoid_();
}

//void QPushButton.setMenu(QMenu menu);
KMETHOD QPushButton_setMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPushButton *  qp = RawPtr_to(QPushButton *, sfp[0]);
	if (qp != NULL) {
		QMenu*  menu = RawPtr_to(QMenu*, sfp[1]);
		qp->setMenu(menu);
	}
	RETURNvoid_();
}

//void QPushButton.showMenu();
KMETHOD QPushButton_showMenu(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPushButton *  qp = RawPtr_to(QPushButton *, sfp[0]);
	if (qp != NULL) {
		qp->showMenu();
	}
	RETURNvoid_();
}


DummyQPushButton::DummyQPushButton()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPushButton::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPushButton::self = ptr;
	DummyQAbstractButton::setSelf(ptr);
}

bool DummyQPushButton::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractButton::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQPushButton::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPushButton::event_map->bigin();
	if ((itr = DummyQPushButton::event_map->find(str)) == DummyQPushButton::event_map->end()) {
		bool ret;
		ret = DummyQAbstractButton::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPushButton::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPushButton::slot_map->bigin();
	if ((itr = DummyQPushButton::event_map->find(str)) == DummyQPushButton::slot_map->end()) {
		bool ret;
		ret = DummyQAbstractButton::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQPushButton::KQPushButton(QWidget* parent) : QPushButton(parent)
{
	self = NULL;
}

KMETHOD QPushButton_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPushButton *qp = RawPtr_to(KQPushButton *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPushButton]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQPushButton::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPushButton]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QPushButton_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPushButton *qp = RawPtr_to(KQPushButton *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPushButton]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQPushButton::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPushButton]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPushButton_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPushButton *qp = (KQPushButton *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPushButton_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQPushButton *qp = (KQPushButton *)p->rawptr;
		(void)qp;
	}
}

static int QPushButton_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQPushButton::event(QEvent *event)
{
	if (!DummyQPushButton::eventDispatcher(event)) {
		QPushButton::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQPushButton(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPushButton";
	cdef->free = QPushButton_free;
	cdef->reftrace = QPushButton_reftrace;
	cdef->compareTo = QPushButton_compareTo;
}


