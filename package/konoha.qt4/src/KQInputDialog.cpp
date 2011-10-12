//@Virtual @Override void QInputDialog.done(int result);
KMETHOD QInputDialog_done(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QInputDialog QInputDialog.new(QWidget parent, int flags);
KMETHOD QInputDialog_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	Qt::WindowFlags flags = Int_to(Qt::WindowFlags, sfp[2]);
	KQInputDialog *ret_v = new KQInputDialog(parent, flags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//String QInputDialog.getCancelButtonText();
KMETHOD QInputDialog_getCancelButtonText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		const char*  member = RawPtr_to(const char*, sfp[2]);
		qp->open(receiver, member);
	}
	RETURNvoid_();
}

//int QInputDialog.getOptions();
KMETHOD QInputDialog_getOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp != NULL) {
		QInputDialog::InputDialogOptions ret_v = qp->options();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QInputDialog.setCancelButtonText(String text);
KMETHOD QInputDialog_setCancelButtonText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		QInputDialog::InputDialogOption option = Int_to(QInputDialog::InputDialogOption, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		qp->setOption(option, on);
	}
	RETURNvoid_();
}

//void QInputDialog.setOptions(int options);
KMETHOD QInputDialog_setOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp != NULL) {
		QInputDialog::InputDialogOptions options = Int_to(QInputDialog::InputDialogOptions, sfp[1]);
		qp->setOptions(options);
	}
	RETURNvoid_();
}

//void QInputDialog.setTextEchoMode(int mode);
KMETHOD QInputDialog_setTextEchoMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		QString ret_v = qp->textValue();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//double QInputDialog.getDouble(QWidget parent, String title, String label, double value, double min, double max, int decimals, boolean ok, int flags);
KMETHOD QInputDialog_getDouble(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp != NULL) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		const QString title = String_to(const QString, sfp[2]);
		const QString label = String_to(const QString, sfp[3]);
		double  value = *RawPtr_to(double *, sfp[4]);
		double  min = *RawPtr_to(double *, sfp[5]);
		double  max = *RawPtr_to(double *, sfp[6]);
		int decimals = Int_to(int, sfp[7]);
		bool* ok = Boolean_to(bool*, sfp[8]);
		Qt::WindowFlags flags = Int_to(Qt::WindowFlags, sfp[9]);
		double ret_v = qp->getDouble(parent, title, label, value, min, max, decimals, ok, flags);
		double *ret_v_ = new double(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QInputDialog.getInt(QWidget parent, String title, String label, int value, int min, int max, int step, boolean ok, int flags);
KMETHOD QInputDialog_getInt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp != NULL) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		const QString title = String_to(const QString, sfp[2]);
		const QString label = String_to(const QString, sfp[3]);
		int value = Int_to(int, sfp[4]);
		int min = Int_to(int, sfp[5]);
		int max = Int_to(int, sfp[6]);
		int step = Int_to(int, sfp[7]);
		bool* ok = Boolean_to(bool*, sfp[8]);
		Qt::WindowFlags flags = Int_to(Qt::WindowFlags, sfp[9]);
		int ret_v = qp->getInt(parent, title, label, value, min, max, step, ok, flags);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QInputDialog.getText(QWidget parent, String title, String label, int mode, String text, boolean ok, int flags);
KMETHOD QInputDialog_getText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputDialog *  qp = RawPtr_to(QInputDialog *, sfp[0]);
	if (qp != NULL) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		const QString title = String_to(const QString, sfp[2]);
		const QString label = String_to(const QString, sfp[3]);
		QLineEdit::EchoMode mode = Int_to(QLineEdit::EchoMode, sfp[4]);
		const QString text = String_to(const QString, sfp[5]);
		bool* ok = Boolean_to(bool*, sfp[6]);
		Qt::WindowFlags flags = Int_to(Qt::WindowFlags, sfp[7]);
		QString ret_v = qp->getText(parent, title, label, mode, text, ok, flags);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQInputDialog::DummyQInputDialog()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
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

bool DummyQInputDialog::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQInputDialog::event_map->bigin();
	if ((itr = DummyQInputDialog::event_map->find(str)) == DummyQInputDialog::event_map->end()) {
		bool ret;
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
	if ((itr = DummyQInputDialog::event_map->find(str)) == DummyQInputDialog::slot_map->end()) {
		bool ret;
		ret = DummyQDialog::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQInputDialog::KQInputDialog(QWidget* parent, Qt::WindowFlags flags) : QInputDialog(parent, flags)
{
	self = NULL;
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
		if (!qp->DummyQInputDialog::addEvent(callback_func, str)) {
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
		if (!qp->DummyQInputDialog::signalConnect(callback_func, str)) {
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
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQInputDialog *qp = (KQInputDialog *)p->rawptr;
		(void)qp;
	}
}

static int QInputDialog_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQInputDialog::event(QEvent *event)
{
	if (!DummyQInputDialog::eventDispatcher(event)) {
		QInputDialog::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQInputDialog(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QInputDialog";
	cdef->free = QInputDialog_free;
	cdef->reftrace = QInputDialog_reftrace;
	cdef->compareTo = QInputDialog_compareTo;
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

