//@Virtual @Override QSize QProgressDialog.sizeHint();
KMETHOD QProgressDialog_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QProgressDialog QProgressDialog.new(QWidget parent, QtWindowFlags f);
KMETHOD QProgressDialog_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	initFlag(f, Qt::WindowFlags, sfp[2]);
	KQProgressDialog *ret_v = new KQProgressDialog(parent, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QProgressDialog QProgressDialog.new(String labelText, String cancelButtonText, int minimum, int maximum, QWidget parent, QtWindowFlags f);
KMETHOD QProgressDialog_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString labelText = String_to(const QString, sfp[1]);
	const QString cancelButtonText = String_to(const QString, sfp[2]);
	int minimum = Int_to(int, sfp[3]);
	int maximum = Int_to(int, sfp[4]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[5]);
	initFlag(f, Qt::WindowFlags, sfp[6]);
	KQProgressDialog *ret_v = new KQProgressDialog(labelText, cancelButtonText, minimum, maximum, parent, f);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QProgressDialog.getAutoClose();
KMETHOD QProgressDialog_getAutoClose(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		bool ret_v = qp->autoClose();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QProgressDialog.autoReset();
KMETHOD QProgressDialog_autoReset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		bool ret_v = qp->autoReset();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QProgressDialog.getLabelText();
KMETHOD QProgressDialog_getLabelText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		QString ret_v = qp->labelText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QProgressDialog.getMaximum();
KMETHOD QProgressDialog_getMaximum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		int ret_v = qp->maximum();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QProgressDialog.getMinimum();
KMETHOD QProgressDialog_getMinimum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		int ret_v = qp->minimum();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QProgressDialog.getMinimumDuration();
KMETHOD QProgressDialog_getMinimumDuration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		int ret_v = qp->minimumDuration();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QProgressDialog.openOL(QObject receiver, String member);
KMETHOD QProgressDialog_openOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		const char*  member = RawPtr_to(const char*, sfp[2]);
		qp->open(receiver, member);
	}
	RETURNvoid_();
}

//void QProgressDialog.setAutoClose(boolean close);
KMETHOD QProgressDialog_setAutoClose(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		bool close = Boolean_to(bool, sfp[1]);
		qp->setAutoClose(close);
	}
	RETURNvoid_();
}

//void QProgressDialog.setAutoReset(boolean reset);
KMETHOD QProgressDialog_setAutoReset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		bool reset = Boolean_to(bool, sfp[1]);
		qp->setAutoReset(reset);
	}
	RETURNvoid_();
}

//void QProgressDialog.setBar(QProgressBar bar);
KMETHOD QProgressDialog_setBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		QProgressBar*  bar = RawPtr_to(QProgressBar*, sfp[1]);
		qp->setBar(bar);
	}
	RETURNvoid_();
}

//void QProgressDialog.setCancelButton(QPushButton cancelButton);
KMETHOD QProgressDialog_setCancelButton(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		QPushButton*  cancelButton = RawPtr_to(QPushButton*, sfp[1]);
		qp->setCancelButton(cancelButton);
	}
	RETURNvoid_();
}

//void QProgressDialog.setLabel(QLabel label);
KMETHOD QProgressDialog_setLabel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		QLabel*  label = RawPtr_to(QLabel*, sfp[1]);
		qp->setLabel(label);
	}
	RETURNvoid_();
}

//int QProgressDialog.getValue();
KMETHOD QProgressDialog_getValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		int ret_v = qp->value();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QProgressDialog.wasCanceled();
KMETHOD QProgressDialog_wasCanceled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		bool ret_v = qp->wasCanceled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QProgressDialog.cancel();
KMETHOD QProgressDialog_cancel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		qp->cancel();
	}
	RETURNvoid_();
}

//void QProgressDialog.reset();
KMETHOD QProgressDialog_reset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		qp->reset();
	}
	RETURNvoid_();
}

//void QProgressDialog.setCancelButtonText(String cancelButtonText);
KMETHOD QProgressDialog_setCancelButtonText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		const QString cancelButtonText = String_to(const QString, sfp[1]);
		qp->setCancelButtonText(cancelButtonText);
	}
	RETURNvoid_();
}

//void QProgressDialog.setLabelText(String text);
KMETHOD QProgressDialog_setLabelText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setLabelText(text);
	}
	RETURNvoid_();
}

//void QProgressDialog.setMaximum(int maximum);
KMETHOD QProgressDialog_setMaximum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		int maximum = Int_to(int, sfp[1]);
		qp->setMaximum(maximum);
	}
	RETURNvoid_();
}

//void QProgressDialog.setMinimum(int minimum);
KMETHOD QProgressDialog_setMinimum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		int minimum = Int_to(int, sfp[1]);
		qp->setMinimum(minimum);
	}
	RETURNvoid_();
}

//void QProgressDialog.setMinimumDuration(int ms);
KMETHOD QProgressDialog_setMinimumDuration(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		int ms = Int_to(int, sfp[1]);
		qp->setMinimumDuration(ms);
	}
	RETURNvoid_();
}

//void QProgressDialog.setRange(int minimum, int maximum);
KMETHOD QProgressDialog_setRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		int minimum = Int_to(int, sfp[1]);
		int maximum = Int_to(int, sfp[2]);
		qp->setRange(minimum, maximum);
	}
	RETURNvoid_();
}

//void QProgressDialog.setValue(int progress);
KMETHOD QProgressDialog_setValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressDialog *  qp = RawPtr_to(QProgressDialog *, sfp[0]);
	if (qp) {
		int progress = Int_to(int, sfp[1]);
		qp->setValue(progress);
	}
	RETURNvoid_();
}


DummyQProgressDialog::DummyQProgressDialog()
{
	self = NULL;
	canceled_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("canceled", NULL));
}

void DummyQProgressDialog::setSelf(knh_RawPtr_t *ptr)
{
	DummyQProgressDialog::self = ptr;
	DummyQDialog::setSelf(ptr);
}

bool DummyQProgressDialog::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQDialog::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQProgressDialog::canceledSlot()
{
	if (canceled_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, canceled_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQProgressDialog::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQProgressDialog::event_map->bigin();
	if ((itr = DummyQProgressDialog::event_map->find(str)) == DummyQProgressDialog::event_map->end()) {
		bool ret = false;
		ret = DummyQDialog::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQProgressDialog::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQProgressDialog::slot_map->bigin();
	if ((itr = DummyQProgressDialog::slot_map->find(str)) == DummyQProgressDialog::slot_map->end()) {
		bool ret = false;
		ret = DummyQDialog::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		canceled_func = (*slot_map)["canceled"];
		return true;
	}
}

void DummyQProgressDialog::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 1;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, canceled_func);

	KNH_SIZEREF(ctx);

	DummyQDialog::reftrace(ctx, p, tail_);
}

void DummyQProgressDialog::connection(QObject *o)
{
	QProgressDialog *p = dynamic_cast<QProgressDialog*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(canceled()), this, SLOT(canceledSlot()));
	}
	DummyQDialog::connection(o);
}

KQProgressDialog::KQProgressDialog(QWidget* parent, Qt::WindowFlags f) : QProgressDialog(parent, f)
{
	self = NULL;
	dummy = new DummyQProgressDialog();
	dummy->connection((QObject*)this);
}

KMETHOD QProgressDialog_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQProgressDialog *qp = RawPtr_to(KQProgressDialog *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QProgressDialog]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QProgressDialog]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QProgressDialog_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQProgressDialog *qp = RawPtr_to(KQProgressDialog *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QProgressDialog]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QProgressDialog]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QProgressDialog_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQProgressDialog *qp = (KQProgressDialog *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QProgressDialog_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQProgressDialog *qp = (KQProgressDialog *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QProgressDialog_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQProgressDialog::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQProgressDialog::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QProgressDialog::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQProgressDialog(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QProgressDialog";
	cdef->free = QProgressDialog_free;
	cdef->reftrace = QProgressDialog_reftrace;
	cdef->compareTo = QProgressDialog_compareTo;
}


