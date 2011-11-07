//@Virtual @Override void QInputDialog.done(int result);
KMETHOD QInputDialog_done(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		int result = Int_to(int, sfp[1]);
		qp->done(result);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QInputDialog.minimumSizeHint();
KMETHOD QInputDialog_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QInputDialog.setVisible(boolean visible);
KMETHOD QInputDialog_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setVisible(visible);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QInputDialog.sizeHint();
KMETHOD QInputDialog_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QInputDialog QInputDialog.new(QWidget parent, QtWindowFlags flags);
KMETHOD QInputDialog_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	initFlag(flags, Qt::WindowFlags, sfp[2]);
	KQInputDialog *ret_v = new KQInputDialog(parent, flags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//String QInputDialog.getCancelButtonText();
KMETHOD QInputDialog_getCancelButtonText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		QString ret_v = qp->cancelButtonText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QInputDialog.getDoubleDecimals();
KMETHOD QInputDialog_getDoubleDecimals(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		int ret_v = qp->doubleDecimals();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//double QInputDialog.getDoubleMaximum();
KMETHOD QInputDialog_getDoubleMaximum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		double ret_v = qp->doubleMaximum();
		double *ret_v_ = new double(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//double QInputDialog.getDoubleMinimum();
KMETHOD QInputDialog_getDoubleMinimum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		double ret_v = qp->doubleMinimum();
		double *ret_v_ = new double(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//double QInputDialog.getDoubleValue();
KMETHOD QInputDialog_getDoubleValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		double ret_v = qp->doubleValue();
		double *ret_v_ = new double(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QInputDialog.getInputMode();
KMETHOD QInputDialog_getInputMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		QInputDialog::InputMode ret_v = qp->inputMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QInputDialog.getIntMaximum();
KMETHOD QInputDialog_getIntMaximum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		int ret_v = qp->intMaximum();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QInputDialog.getIntMinimum();
KMETHOD QInputDialog_getIntMinimum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		int ret_v = qp->intMinimum();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QInputDialog.getIntStep();
KMETHOD QInputDialog_getIntStep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		int ret_v = qp->intStep();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QInputDialog.getIntValue();
KMETHOD QInputDialog_getIntValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		int ret_v = qp->intValue();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QInputDialog.isComboBoxEditable();
KMETHOD QInputDialog_isComboBoxEditable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isComboBoxEditable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QInputDialog.getLabelText();
KMETHOD QInputDialog_getLabelText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		QString ret_v = qp->labelText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QInputDialog.getOkButtonText();
KMETHOD QInputDialog_getOkButtonText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		QString ret_v = qp->okButtonText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QInputDialog.open(QObject receiver, String member);
KMETHOD QInputDialog_open(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		const char*  member = RawPtr_to(const char*, sfp[2]);
		qp->open(receiver, member);
	}
	RETURNvoid_();
}

//QInputDialogInputDialogOptions QInputDialog.getOptions();
KMETHOD QInputDialog_getOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		QInputDialog::InputDialogOptions ret_v = qp->options();
		QInputDialog::InputDialogOptions *ret_v_ = new QInputDialog::InputDialogOptions(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QInputDialog.setCancelButtonText(String text);
KMETHOD QInputDialog_setCancelButtonText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setCancelButtonText(text);
	}
	RETURNvoid_();
}

//void QInputDialog.setComboBoxEditable(boolean editable);
KMETHOD QInputDialog_setComboBoxEditable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		bool editable = Boolean_to(bool, sfp[1]);
		qp->setComboBoxEditable(editable);
	}
	RETURNvoid_();
}

//void QInputDialog.setDoubleDecimals(int decimals);
KMETHOD QInputDialog_setDoubleDecimals(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		int decimals = Int_to(int, sfp[1]);
		qp->setDoubleDecimals(decimals);
	}
	RETURNvoid_();
}

//void QInputDialog.setDoubleMaximum(double max);
KMETHOD QInputDialog_setDoubleMaximum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		double  max = *RawPtr_to(double *, sfp[1]);
		qp->setDoubleMaximum(max);
	}
	RETURNvoid_();
}

//void QInputDialog.setDoubleMinimum(double min);
KMETHOD QInputDialog_setDoubleMinimum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		double  min = *RawPtr_to(double *, sfp[1]);
		qp->setDoubleMinimum(min);
	}
	RETURNvoid_();
}

//void QInputDialog.setDoubleRange(double min, double max);
KMETHOD QInputDialog_setDoubleRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		double  min = *RawPtr_to(double *, sfp[1]);
		double  max = *RawPtr_to(double *, sfp[2]);
		qp->setDoubleRange(min, max);
	}
	RETURNvoid_();
}

//void QInputDialog.setDoubleValue(double value);
KMETHOD QInputDialog_setDoubleValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		double  value = *RawPtr_to(double *, sfp[1]);
		qp->setDoubleValue(value);
	}
	RETURNvoid_();
}

//void QInputDialog.setInputMode(int mode);
KMETHOD QInputDialog_setInputMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		QInputDialog::InputMode mode = Int_to(QInputDialog::InputMode, sfp[1]);
		qp->setInputMode(mode);
	}
	RETURNvoid_();
}

//void QInputDialog.setIntMaximum(int max);
KMETHOD QInputDialog_setIntMaximum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		int max = Int_to(int, sfp[1]);
		qp->setIntMaximum(max);
	}
	RETURNvoid_();
}

//void QInputDialog.setIntMinimum(int min);
KMETHOD QInputDialog_setIntMinimum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		int min = Int_to(int, sfp[1]);
		qp->setIntMinimum(min);
	}
	RETURNvoid_();
}

//void QInputDialog.setIntRange(int min, int max);
KMETHOD QInputDialog_setIntRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		int min = Int_to(int, sfp[1]);
		int max = Int_to(int, sfp[2]);
		qp->setIntRange(min, max);
	}
	RETURNvoid_();
}

//void QInputDialog.setIntStep(int step);
KMETHOD QInputDialog_setIntStep(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		int step = Int_to(int, sfp[1]);
		qp->setIntStep(step);
	}
	RETURNvoid_();
}

//void QInputDialog.setIntValue(int value);
KMETHOD QInputDialog_setIntValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		int value = Int_to(int, sfp[1]);
		qp->setIntValue(value);
	}
	RETURNvoid_();
}

//void QInputDialog.setLabelText(String text);
KMETHOD QInputDialog_setLabelText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setLabelText(text);
	}
	RETURNvoid_();
}

//void QInputDialog.setOkButtonText(String text);
KMETHOD QInputDialog_setOkButtonText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setOkButtonText(text);
	}
	RETURNvoid_();
}

//void QInputDialog.setOption(int option, boolean on);
KMETHOD QInputDialog_setOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		QInputDialog::InputDialogOption option = Int_to(QInputDialog::InputDialogOption, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		qp->setOption(option, on);
	}
	RETURNvoid_();
}

//void QInputDialog.setOptions(QInputDialogInputDialogOptions options);
KMETHOD QInputDialog_setOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		initFlag(options, QInputDialog::InputDialogOptions, sfp[1]);
		qp->setOptions(options);
	}
	RETURNvoid_();
}

//void QInputDialog.setTextEchoMode(int mode);
KMETHOD QInputDialog_setTextEchoMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		QLineEdit::EchoMode mode = Int_to(QLineEdit::EchoMode, sfp[1]);
		qp->setTextEchoMode(mode);
	}
	RETURNvoid_();
}

//void QInputDialog.setTextValue(String text);
KMETHOD QInputDialog_setTextValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setTextValue(text);
	}
	RETURNvoid_();
}

//boolean QInputDialog.testOption(int option);
KMETHOD QInputDialog_testOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		QInputDialog::InputDialogOption option = Int_to(QInputDialog::InputDialogOption, sfp[1]);
		bool ret_v = qp->testOption(option);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QInputDialog.getTextEchoMode();
KMETHOD QInputDialog_getTextEchoMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		QLineEdit::EchoMode ret_v = qp->textEchoMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QInputDialog.getTextValue();
KMETHOD QInputDialog_getTextValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp) {
		QString ret_v = qp->textValue();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//double QInputDialog.getDouble(QWidget parent, String title, String label, double value, double min, double max, int decimals, boolean ok, QtWindowFlags flags);
KMETHOD QInputDialog_getDouble(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		const QString title = String_to(const QString, sfp[2]);
		const QString label = String_to(const QString, sfp[3]);
		double  value = *RawPtr_to(double *, sfp[4]);
		double  min = *RawPtr_to(double *, sfp[5]);
		double  max = *RawPtr_to(double *, sfp[6]);
		int decimals = Int_to(int, sfp[7]);
		bool* ok = Boolean_to(bool*, sfp[8]);
		initFlag(flags, Qt::WindowFlags, sfp[9]);
		double ret_v = QInputDialog::getDouble(parent, title, label, value, min, max, decimals, ok, flags);
		double *ret_v_ = new double(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QInputDialog.getInt(QWidget parent, String title, String label, int value, int min, int max, int step, boolean ok, QtWindowFlags flags);
KMETHOD QInputDialog_getInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		const QString title = String_to(const QString, sfp[2]);
		const QString label = String_to(const QString, sfp[3]);
		int value = Int_to(int, sfp[4]);
		int min = Int_to(int, sfp[5]);
		int max = Int_to(int, sfp[6]);
		int step = Int_to(int, sfp[7]);
		bool* ok = Boolean_to(bool*, sfp[8]);
		initFlag(flags, Qt::WindowFlags, sfp[9]);
		int ret_v = QInputDialog::getInt(parent, title, label, value, min, max, step, ok, flags);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QInputDialog.getText(QWidget parent, String title, String label, int mode, String text, boolean ok, QtWindowFlags flags);
KMETHOD QInputDialog_getText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		const QString title = String_to(const QString, sfp[2]);
		const QString label = String_to(const QString, sfp[3]);
		QLineEdit::EchoMode mode = Int_to(QLineEdit::EchoMode, sfp[4]);
		const QString text = String_to(const QString, sfp[5]);
		bool* ok = Boolean_to(bool*, sfp[6]);
		initFlag(flags, Qt::WindowFlags, sfp[7]);
		QString ret_v = QInputDialog::getText(parent, title, label, mode, text, ok, flags);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQInputDialog::DummyQInputDialog()
{
	self = NULL;
	double_value_changed_func = NULL;
	double_value_selected_func = NULL;
	int_value_changed_func = NULL;
	int_value_selected_func = NULL;
	text_value_changed_func = NULL;
	text_value_selected_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("double-value-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("double-value-selected", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("int-value-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("int-value-selected", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("text-value-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("text-value-selected", NULL));
}

void DummyQInputDialog::setSelf(knh_RawPtr_t *ptr)
{
	DummyQInputDialog::self = ptr;
	DummyQDialog::setSelf(ptr);
}

bool DummyQInputDialog::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQDialog::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQInputDialog::doubleValueChangedSlot(double value)
{
	if (double_value_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, double, value);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, double_value_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQInputDialog::doubleValueSelectedSlot(double value)
{
	if (double_value_selected_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, double, value);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, double_value_selected_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQInputDialog::intValueChangedSlot(int value)
{
	if (int_value_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = value;
		knh_Func_invoke(lctx, int_value_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQInputDialog::intValueSelectedSlot(int value)
{
	if (int_value_selected_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = value;
		knh_Func_invoke(lctx, int_value_selected_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQInputDialog::textValueChangedSlot(const QString text)
{
	if (text_value_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QString, text);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, text_value_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQInputDialog::textValueSelectedSlot(const QString text)
{
	if (text_value_selected_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QString, text);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, text_value_selected_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQInputDialog::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQInputDialog::event_map->bigin();
	if ((itr = DummyQInputDialog::event_map->find(str)) == DummyQInputDialog::event_map->end()) {
		bool ret = false;
		ret = DummyQDialog::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQInputDialog::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQInputDialog::slot_map->bigin();
	if ((itr = DummyQInputDialog::slot_map->find(str)) == DummyQInputDialog::slot_map->end()) {
		bool ret = false;
		ret = DummyQDialog::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		double_value_changed_func = (*slot_map)["double-value-changed"];
		double_value_selected_func = (*slot_map)["double-value-selected"];
		int_value_changed_func = (*slot_map)["int-value-changed"];
		int_value_selected_func = (*slot_map)["int-value-selected"];
		text_value_changed_func = (*slot_map)["text-value-changed"];
		text_value_selected_func = (*slot_map)["text-value-selected"];
		return true;
	}
}

void DummyQInputDialog::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 6;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, double_value_changed_func);
	KNH_ADDNNREF(ctx, double_value_selected_func);
	KNH_ADDNNREF(ctx, int_value_changed_func);
	KNH_ADDNNREF(ctx, int_value_selected_func);
	KNH_ADDNNREF(ctx, text_value_changed_func);
	KNH_ADDNNREF(ctx, text_value_selected_func);

	KNH_SIZEREF(ctx);

	DummyQDialog::reftrace(ctx, p, tail_);
}

void DummyQInputDialog::connection(QObject *o)
{
	QInputDialog *p = dynamic_cast<QInputDialog*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(doubleValueChanged(double)), this, SLOT(doubleValueChangedSlot(double)));
		connect(p, SIGNAL(doubleValueSelected(double)), this, SLOT(doubleValueSelectedSlot(double)));
		connect(p, SIGNAL(intValueChanged(int)), this, SLOT(intValueChangedSlot(int)));
		connect(p, SIGNAL(intValueSelected(int)), this, SLOT(intValueSelectedSlot(int)));
		connect(p, SIGNAL(textValueChanged(const QString)), this, SLOT(textValueChangedSlot(const QString)));
		connect(p, SIGNAL(textValueSelected(const QString)), this, SLOT(textValueSelectedSlot(const QString)));
	}
	DummyQDialog::connection(o);
}

KQInputDialog::KQInputDialog(QWidget* parent, Qt::WindowFlags flags) : QInputDialog(parent, flags)
{
	self = NULL;
	dummy = new DummyQInputDialog();
	dummy->connection((QObject*)this);
}

KMETHOD QInputDialog_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQInputDialog *qp = RawPtr_to(KQInputDialog *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QInputDialog]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QInputDialog]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QInputDialog_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQInputDialog *qp = RawPtr_to(KQInputDialog *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QInputDialog]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QInputDialog]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QInputDialog_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQInputDialog *qp = (KQInputDialog *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QInputDialog_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQInputDialog *qp = (KQInputDialog *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QInputDialog_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQInputDialog::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQInputDialog::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QInputDialog::event(event);
		return false;
	}
	return true;
}

static knh_IntData_t QInputDialogConstInt[] = {
	{"NoButtons", QInputDialog::NoButtons},
	{"UseListViewForComboBoxItems", QInputDialog::UseListViewForComboBoxItems},
	{"TextInput", QInputDialog::TextInput},
	{"IntInput", QInputDialog::IntInput},
	{"DoubleInput", QInputDialog::DoubleInput},
	{NULL, 0}
};

DEFAPI(void) constQInputDialog(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QInputDialogConstInt);
}


DEFAPI(void) defQInputDialog(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QInputDialog";
	cdef->free = QInputDialog_free;
	cdef->reftrace = QInputDialog_reftrace;
	cdef->compareTo = QInputDialog_compareTo;
}

//## QInputDialogInputDialogOptions QInputDialogInputDialogOptions.new(int value);
KMETHOD QInputDialogInputDialogOptions_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QInputDialog::InputDialogOption i = Int_to(QInputDialog::InputDialogOption, sfp[1]);
	QInputDialog::InputDialogOptions *ret_v = new QInputDialog::InputDialogOptions(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QInputDialogInputDialogOptions QInputDialogInputDialogOptions.and(int mask);
KMETHOD QInputDialogInputDialogOptions_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QInputDialog::InputDialogOptions *qp = RawPtr_to(QInputDialog::InputDialogOptions*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QInputDialog::InputDialogOptions ret = ((*qp) & i);
		QInputDialog::InputDialogOptions *ret_ = new QInputDialog::InputDialogOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QInputDialogInputDialogOptions QInputDialogInputDialogOptions.iand(QInputDialog::QInputDialogInputDialogOptions other);
KMETHOD QInputDialogInputDialogOptions_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QInputDialog::InputDialogOptions *qp = RawPtr_to(QInputDialog::InputDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QInputDialog::InputDialogOptions *other = RawPtr_to(QInputDialog::InputDialogOptions *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QInputDialogInputDialogOptions QInputDialogInputDialogOptions.or(QInputDialogInputDialogOptions f);
KMETHOD QInputDialogInputDialogOptions_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog::InputDialogOptions *qp = RawPtr_to(QInputDialog::InputDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QInputDialog::InputDialogOptions *f = RawPtr_to(QInputDialog::InputDialogOptions*, sfp[1]);
		QInputDialog::InputDialogOptions ret = ((*qp) | (*f));
		QInputDialog::InputDialogOptions *ret_ = new QInputDialog::InputDialogOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QInputDialogInputDialogOptions QInputDialogInputDialogOptions.ior(QInputDialog::QInputDialogInputDialogOptions other);
KMETHOD QInputDialogInputDialogOptions_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QInputDialog::InputDialogOptions *qp = RawPtr_to(QInputDialog::InputDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QInputDialog::InputDialogOptions *other = RawPtr_to(QInputDialog::InputDialogOptions *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QInputDialogInputDialogOptions QInputDialogInputDialogOptions.xor(QInputDialogInputDialogOptions f);
KMETHOD QInputDialogInputDialogOptions_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog::InputDialogOptions *qp = RawPtr_to(QInputDialog::InputDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QInputDialog::InputDialogOptions *f = RawPtr_to(QInputDialog::InputDialogOptions*, sfp[1]);
		QInputDialog::InputDialogOptions ret = ((*qp) ^ (*f));
		QInputDialog::InputDialogOptions *ret_ = new QInputDialog::InputDialogOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QInputDialogInputDialogOptions QInputDialogInputDialogOptions.ixor(QInputDialog::QInputDialogInputDialogOptions other);
KMETHOD QInputDialogInputDialogOptions_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QInputDialog::InputDialogOptions *qp = RawPtr_to(QInputDialog::InputDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QInputDialog::InputDialogOptions *other = RawPtr_to(QInputDialog::InputDialogOptions *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QInputDialogInputDialogOptions.testFlag(int flag);
KMETHOD QInputDialogInputDialogOptions_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QInputDialog::InputDialogOptions *qp = RawPtr_to(QInputDialog::InputDialogOptions *, sfp[0]);
	if (qp != NULL) {
		QInputDialog::InputDialogOption flag = Int_to(QInputDialog::InputDialogOption, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QInputDialogInputDialogOptions.value();
KMETHOD QInputDialogInputDialogOptions_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QInputDialog::InputDialogOptions *qp = RawPtr_to(QInputDialog::InputDialogOptions *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QInputDialogInputDialogOptions_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QInputDialog::InputDialogOptions *qp = (QInputDialog::InputDialogOptions *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QInputDialogInputDialogOptions_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QInputDialog::InputDialogOptions *qp = (QInputDialog::InputDialogOptions *)p->rawptr;
		(void)qp;
	}
}

static int QInputDialogInputDialogOptions_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QInputDialog::InputDialogOptions*)p1->rawptr);
//		int v2 = int(*(QInputDialog::InputDialogOptions*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QInputDialog::InputDialogOptions v1 = *(QInputDialog::InputDialogOptions*)p1->rawptr;
		QInputDialog::InputDialogOptions v2 = *(QInputDialog::InputDialogOptions*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQInputDialogInputDialogOptions(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QInputDialogInputDialogOptions";
	cdef->free = QInputDialogInputDialogOptions_free;
	cdef->reftrace = QInputDialogInputDialogOptions_reftrace;
	cdef->compareTo = QInputDialogInputDialogOptions_compareTo;
}

