//@Virtual @Override QSize QCheckBox.sizeHint();
KMETHOD QCheckBox_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCheckBox *  qp = RawPtr_to(QCheckBox *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QCheckBox QCheckBox.new(QWidget parent);
KMETHOD QCheckBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQCheckBox *ret_v = new KQCheckBox(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QCheckBox QCheckBox.new(String text, QWidget parent);
KMETHOD QCheckBox_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString text = String_to(const QString, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQCheckBox *ret_v = new KQCheckBox(text, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QCheckBox.getCheckState();
KMETHOD QCheckBox_getCheckState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCheckBox *  qp = RawPtr_to(QCheckBox *, sfp[0]);
	if (qp) {
		Qt::CheckState ret_v = qp->checkState();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QCheckBox.isTristate();
KMETHOD QCheckBox_isTristate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCheckBox *  qp = RawPtr_to(QCheckBox *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isTristate();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QCheckBox.setCheckState(int state);
KMETHOD QCheckBox_setCheckState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCheckBox *  qp = RawPtr_to(QCheckBox *, sfp[0]);
	if (qp) {
		Qt::CheckState state = Int_to(Qt::CheckState, sfp[1]);
		qp->setCheckState(state);
	}
	RETURNvoid_();
}

//void QCheckBox.setTristate(boolean y);
KMETHOD QCheckBox_setTristate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QCheckBox *  qp = RawPtr_to(QCheckBox *, sfp[0]);
	if (qp) {
		bool y = Boolean_to(bool, sfp[1]);
		qp->setTristate(y);
	}
	RETURNvoid_();
}


DummyQCheckBox::DummyQCheckBox()
{
	self = NULL;
	state_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("state-changed", NULL));
}

void DummyQCheckBox::setSelf(knh_RawPtr_t *ptr)
{
	DummyQCheckBox::self = ptr;
	DummyQAbstractButton::setSelf(ptr);
}

bool DummyQCheckBox::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractButton::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQCheckBox::stateChangedSlot(int state)
{
	if (state_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = state;
		knh_Func_invoke(lctx, state_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQCheckBox::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCheckBox::event_map->bigin();
	if ((itr = DummyQCheckBox::event_map->find(str)) == DummyQCheckBox::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractButton::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQCheckBox::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQCheckBox::slot_map->bigin();
	if ((itr = DummyQCheckBox::slot_map->find(str)) == DummyQCheckBox::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractButton::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		state_changed_func = (*slot_map)["state-changed"];
		return true;
	}
}

void DummyQCheckBox::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 1;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, state_changed_func);

	KNH_SIZEREF(ctx);

	DummyQAbstractButton::reftrace(ctx, p, tail_);
}

void DummyQCheckBox::connection(QObject *o)
{
	QCheckBox *p = dynamic_cast<QCheckBox*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(stateChanged(int)), this, SLOT(stateChangedSlot(int)));
	}
	DummyQAbstractButton::connection(o);
}

KQCheckBox::KQCheckBox(QWidget* parent) : QCheckBox(parent)
{
	self = NULL;
	dummy = new DummyQCheckBox();
	dummy->connection((QObject*)this);
}

KMETHOD QCheckBox_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCheckBox *qp = RawPtr_to(KQCheckBox *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QCheckBox]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCheckBox]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QCheckBox_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQCheckBox *qp = RawPtr_to(KQCheckBox *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QCheckBox]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QCheckBox]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QCheckBox_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQCheckBox *qp = (KQCheckBox *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QCheckBox_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQCheckBox *qp = (KQCheckBox *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QCheckBox_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQCheckBox::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQCheckBox::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QCheckBox::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQCheckBox(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QCheckBox";
	cdef->free = QCheckBox_free;
	cdef->reftrace = QCheckBox_reftrace;
	cdef->compareTo = QCheckBox_compareTo;
}


