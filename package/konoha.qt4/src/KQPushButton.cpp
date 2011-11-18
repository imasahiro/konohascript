//@Virtual @Override QSize QPushButton.minimumSizeHint();
KMETHOD QPushButton_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPushButton *  qp = RawPtr_to(QPushButton *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QPushButton.getAutoDefault();
KMETHOD QPushButton_getAutoDefault(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPushButton *  qp = RawPtr_to(QPushButton *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		qp->showMenu();
	}
	RETURNvoid_();
}


DummyQPushButton::DummyQPushButton()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQPushButton::~DummyQPushButton()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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
		bool ret = false;
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
	if ((itr = DummyQPushButton::slot_map->find(str)) == DummyQPushButton::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractButton::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQPushButton::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQPushButton::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQAbstractButton::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQPushButton::connection(QObject *o)
{
	QPushButton *p = dynamic_cast<QPushButton*>(o);
	if (p != NULL) {
	}
	DummyQAbstractButton::connection(o);
}

KQPushButton::KQPushButton(QWidget* parent) : QPushButton(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQPushButton();
	dummy->connection((QObject*)this);
}

KQPushButton::~KQPushButton()
{
	delete dummy;
	dummy = NULL;
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPushButton]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPushButton_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQPushButton *qp = (KQPushButton *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QPushButton*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QPushButton_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQPushButton *qp = (KQPushButton *)p->rawptr;
		KQPushButton *qp = static_cast<KQPushButton*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPushButton_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQPushButton::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQPushButton::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QPushButton::event(event);
		return false;
	}
//	QPushButton::event(event);
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


