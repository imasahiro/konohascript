//@Virtual @Override QSize QDialog.minimumSizeHint();
KMETHOD QDialog_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialog *  qp = RawPtr_to(QDialog *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QDialog.setVisible(boolean visible);
KMETHOD QDialog_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialog *  qp = RawPtr_to(QDialog *, sfp[0]);
	if (qp) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setVisible(visible);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QDialog.sizeHint();
KMETHOD QDialog_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialog *  qp = RawPtr_to(QDialog *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDialog QDialog.new(QWidget parent, QtWindowFlags f);
KMETHOD QDialog_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	initFlag(f, Qt::WindowFlags, sfp[2]);
	KQDialog *ret_v = new KQDialog(parent, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QDialog.isSizeGripEnabled();
KMETHOD QDialog_isSizeGripEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialog *  qp = RawPtr_to(QDialog *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSizeGripEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QDialog.getResult();
KMETHOD QDialog_getResult(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialog *  qp = RawPtr_to(QDialog *, sfp[0]);
	if (qp) {
		int ret_v = qp->result();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QDialog.setModal(boolean modal);
KMETHOD QDialog_setModal(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialog *  qp = RawPtr_to(QDialog *, sfp[0]);
	if (qp) {
		bool modal = Boolean_to(bool, sfp[1]);
		qp->setModal(modal);
	}
	RETURNvoid_();
}

//void QDialog.setResult(int i);
KMETHOD QDialog_setResult(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialog *  qp = RawPtr_to(QDialog *, sfp[0]);
	if (qp) {
		int i = Int_to(int, sfp[1]);
		qp->setResult(i);
	}
	RETURNvoid_();
}

//void QDialog.setSizeGripEnabled(boolean arg0);
KMETHOD QDialog_setSizeGripEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialog *  qp = RawPtr_to(QDialog *, sfp[0]);
	if (qp) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setSizeGripEnabled(arg0);
	}
	RETURNvoid_();
}

//@Virtual void QDialog.done(int r);
KMETHOD QDialog_done(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialog *  qp = RawPtr_to(QDialog *, sfp[0]);
	if (qp) {
		int r = Int_to(int, sfp[1]);
		qp->done(r);
	}
	RETURNvoid_();
}

//int QDialog.exec();
KMETHOD QDialog_exec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialog *  qp = RawPtr_to(QDialog *, sfp[0]);
	if (qp) {
		int ret_v = qp->exec();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QDialog.open();
KMETHOD QDialog_open(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialog *  qp = RawPtr_to(QDialog *, sfp[0]);
	if (qp) {
		qp->open();
	}
	RETURNvoid_();
}

//@Virtual void QDialog.reject();
KMETHOD QDialog_reject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialog *  qp = RawPtr_to(QDialog *, sfp[0]);
	if (qp) {
		qp->reject();
	}
	RETURNvoid_();
}


DummyQDialog::DummyQDialog()
{
	self = NULL;
	accepted_func = NULL;
	finished_func = NULL;
	rejected_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("accepted", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("finished", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("rejected", NULL));
}

void DummyQDialog::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDialog::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQDialog::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQDialog::acceptedSlot()
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

bool DummyQDialog::finishedSlot(int result)
{
	if (finished_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = result;
		knh_Func_invoke(lctx, finished_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQDialog::rejectedSlot()
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

bool DummyQDialog::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDialog::event_map->bigin();
	if ((itr = DummyQDialog::event_map->find(str)) == DummyQDialog::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDialog::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDialog::slot_map->bigin();
	if ((itr = DummyQDialog::slot_map->find(str)) == DummyQDialog::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		accepted_func = (*slot_map)["accepted"];
		finished_func = (*slot_map)["finished"];
		rejected_func = (*slot_map)["rejected"];
		return true;
	}
}

knh_Object_t** DummyQDialog::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQDialog::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 3;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, accepted_func);
	KNH_ADDNNREF(ctx, finished_func);
	KNH_ADDNNREF(ctx, rejected_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQWidget::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQDialog::connection(QObject *o)
{
	QDialog *p = dynamic_cast<QDialog*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(accepted()), this, SLOT(acceptedSlot()));
		connect(p, SIGNAL(finished(int)), this, SLOT(finishedSlot(int)));
		connect(p, SIGNAL(rejected()), this, SLOT(rejectedSlot()));
	}
	DummyQWidget::connection(o);
}

KQDialog::KQDialog(QWidget* parent, Qt::WindowFlags f) : QDialog(parent, f)
{
	self = NULL;
	dummy = new DummyQDialog();
	dummy->connection((QObject*)this);
}

KMETHOD QDialog_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDialog *qp = RawPtr_to(KQDialog *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDialog]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDialog]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QDialog_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDialog *qp = RawPtr_to(KQDialog *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDialog]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDialog]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDialog_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDialog *qp = (KQDialog *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDialog_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQDialog *qp = (KQDialog *)p->rawptr;
//		KQDialog *qp = static_cast<KQDialog*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QDialog_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQDialog::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQDialog::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QDialog::event(event);
		return false;
	}
//	QDialog::event(event);
	return true;
}

static knh_IntData_t QDialogConstInt[] = {
	{"Accepted", QDialog::Accepted},
	{"Rejected", QDialog::Rejected},
	{NULL, 0}
};

DEFAPI(void) constQDialog(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QDialogConstInt);
}


DEFAPI(void) defQDialog(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDialog";
	cdef->free = QDialog_free;
	cdef->reftrace = QDialog_reftrace;
	cdef->compareTo = QDialog_compareTo;
}


