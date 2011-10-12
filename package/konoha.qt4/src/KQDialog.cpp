//@Virtual @Override QSize QDialog.minimumSizeHint();
KMETHOD QDialog_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialog *  qp = RawPtr_to(QDialog *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDialog QDialog.new(QWidget parent, int f);
KMETHOD QDialog_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	Qt::WindowFlags f = Int_to(Qt::WindowFlags, sfp[2]);
	KQDialog *ret_v = new KQDialog(parent, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QDialog.isSizeGripEnabled();
KMETHOD QDialog_isSizeGripEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialog *  qp = RawPtr_to(QDialog *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setSizeGripEnabled(arg0);
	}
	RETURNvoid_();
}

////@Virtual void QDialog.accept();
KMETHOD QDialog_accept(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialog *  qp = RawPtr_to(QDialog *, sfp[0]);
	if (qp != NULL) {
		qp->accept();
	}
	RETURNvoid_();
}

//@Virtual void QDialog.done(int r);
KMETHOD QDialog_done(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialog *  qp = RawPtr_to(QDialog *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		qp->open();
	}
	RETURNvoid_();
}

//@Virtual void QDialog.reject();
KMETHOD QDialog_reject(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDialog *  qp = RawPtr_to(QDialog *, sfp[0]);
	if (qp != NULL) {
		qp->reject();
	}
	RETURNvoid_();
}


DummyQDialog::DummyQDialog()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
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

bool DummyQDialog::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDialog::event_map->bigin();
	if ((itr = DummyQDialog::event_map->find(str)) == DummyQDialog::event_map->end()) {
		bool ret;
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
	if ((itr = DummyQDialog::event_map->find(str)) == DummyQDialog::slot_map->end()) {
		bool ret;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQDialog::KQDialog(QWidget* parent, Qt::WindowFlags f) : QDialog(parent, f)
{
	self = NULL;
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
		if (!qp->DummyQDialog::addEvent(callback_func, str)) {
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
		if (!qp->DummyQDialog::signalConnect(callback_func, str)) {
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
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQDialog *qp = (KQDialog *)p->rawptr;
		(void)qp;
	}
}

static int QDialog_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQDialog::event(QEvent *event)
{
	if (!DummyQDialog::eventDispatcher(event)) {
		QDialog::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQDialog(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDialog";
	cdef->free = QDialog_free;
	cdef->reftrace = QDialog_reftrace;
	cdef->compareTo = QDialog_compareTo;
}

static knh_IntData_t QDialogConstInt[] = {
	{"Accepted", QDialog::Accepted},
	{"Rejected", QDialog::Rejected},
	{NULL, 0}
};

DEFAPI(void) constQDialog(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QDialogConstInt);
}

