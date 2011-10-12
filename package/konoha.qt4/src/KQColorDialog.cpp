//@Virtual @Override void QColorDialog.setVisible(boolean visible);
KMETHOD QColorDialog_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp != NULL) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setVisible(visible);
	}
	RETURNvoid_();
}

//QColorDialog QColorDialog.new(QWidget parent);
KMETHOD QColorDialog_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQColorDialog *ret_v = new KQColorDialog(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QColorDialog QColorDialog.new(QColor initial, QWidget parent);
KMETHOD QColorDialog_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QColor  initial = *RawPtr_to(const QColor *, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQColorDialog *ret_v = new KQColorDialog(initial, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QColor QColorDialog.getCurrentColor();
KMETHOD QColorDialog_getCurrentColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp != NULL) {
		QColor ret_v = qp->currentColor();
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QColorDialog.open();
KMETHOD QColorDialog_open(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp != NULL) {
		qp->open();
	}
	RETURNvoid_();
}

/*
//void QColorDialog.open(QObject receiver, String member);
KMETHOD QColorDialog_open(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp != NULL) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		const char*  member = RawPtr_to(const char*, sfp[2]);
		qp->open(receiver, member);
	}
	RETURNvoid_();
}
*/
//int QColorDialog.getOptions();
KMETHOD QColorDialog_getOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp != NULL) {
		QColorDialog::ColorDialogOptions ret_v = qp->options();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QColor QColorDialog.selectedColor();
KMETHOD QColorDialog_selectedColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp != NULL) {
		QColor ret_v = qp->selectedColor();
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QColorDialog.setCurrentColor(QColor color);
KMETHOD QColorDialog_setCurrentColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp != NULL) {
		const QColor  color = *RawPtr_to(const QColor *, sfp[1]);
		qp->setCurrentColor(color);
	}
	RETURNvoid_();
}

//void QColorDialog.setOption(int option, boolean on);
KMETHOD QColorDialog_setOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp != NULL) {
		QColorDialog::ColorDialogOption option = Int_to(QColorDialog::ColorDialogOption, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		qp->setOption(option, on);
	}
	RETURNvoid_();
}

//void QColorDialog.setOptions(int options);
KMETHOD QColorDialog_setOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp != NULL) {
		QColorDialog::ColorDialogOptions options = Int_to(QColorDialog::ColorDialogOptions, sfp[1]);
		qp->setOptions(options);
	}
	RETURNvoid_();
}

//boolean QColorDialog.testOption(int option);
KMETHOD QColorDialog_testOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp != NULL) {
		QColorDialog::ColorDialogOption option = Int_to(QColorDialog::ColorDialogOption, sfp[1]);
		bool ret_v = qp->testOption(option);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QRgb QColorDialog.getCustomColor(int index);
KMETHOD QColorDialog_getCustomColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QRgb ret_v = qp->customColor(index);
		QRgb *ret_v_ = new QRgb(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QColorDialog.customCount();
KMETHOD QColorDialog_customCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->customCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QColor QColorDialog.getColor(QColor initial, QWidget parent, String title, int options);
KMETHOD QColorDialog_getColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp != NULL) {
		const QColor  initial = *RawPtr_to(const QColor *, sfp[1]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
		const QString title = String_to(const QString, sfp[3]);
		QColorDialog::ColorDialogOptions options = Int_to(QColorDialog::ColorDialogOptions, sfp[4]);
		QColor ret_v = qp->getColor(initial, parent, title, options);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QColor QColorDialog.getColor(QColor initial, QWidget parent);
KMETHOD QColorDialog_getColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp != NULL) {
		const QColor  initial = *RawPtr_to(const QColor *, sfp[1]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
		QColor ret_v = qp->getColor(initial, parent);
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//void QColorDialog.setCustomColor(int index, QRgb color);
KMETHOD QColorDialog_setCustomColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QRgb  color = *RawPtr_to(QRgb *, sfp[2]);
		qp->setCustomColor(index, color);
	}
	RETURNvoid_();
}

//void QColorDialog.setStandardColor(int index, QRgb color);
KMETHOD QColorDialog_setStandardColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QRgb  color = *RawPtr_to(QRgb *, sfp[2]);
		qp->setStandardColor(index, color);
	}
	RETURNvoid_();
}


DummyQColorDialog::DummyQColorDialog()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQColorDialog::setSelf(knh_RawPtr_t *ptr)
{
	DummyQColorDialog::self = ptr;
	DummyQDialog::setSelf(ptr);
}

bool DummyQColorDialog::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQDialog::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQColorDialog::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQColorDialog::event_map->bigin();
	if ((itr = DummyQColorDialog::event_map->find(str)) == DummyQColorDialog::event_map->end()) {
		bool ret;
		ret = DummyQDialog::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQColorDialog::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQColorDialog::slot_map->bigin();
	if ((itr = DummyQColorDialog::event_map->find(str)) == DummyQColorDialog::slot_map->end()) {
		bool ret;
		ret = DummyQDialog::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQColorDialog::KQColorDialog(QWidget* parent) : QColorDialog(parent)
{
	self = NULL;
}

KMETHOD QColorDialog_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQColorDialog *qp = RawPtr_to(KQColorDialog *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QColorDialog]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQColorDialog::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QColorDialog]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QColorDialog_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQColorDialog *qp = RawPtr_to(KQColorDialog *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QColorDialog]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQColorDialog::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QColorDialog]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QColorDialog_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQColorDialog *qp = (KQColorDialog *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QColorDialog_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQColorDialog *qp = (KQColorDialog *)p->rawptr;
		(void)qp;
	}
}

static int QColorDialog_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQColorDialog::event(QEvent *event)
{
	if (!DummyQColorDialog::eventDispatcher(event)) {
		QColorDialog::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQColorDialog(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QColorDialog";
	cdef->free = QColorDialog_free;
	cdef->reftrace = QColorDialog_reftrace;
	cdef->compareTo = QColorDialog_compareTo;
}

static knh_IntData_t QColorDialogConstInt[] = {
//	{"ShowAlphaChannel", QColorDialog::ShowAlphaChannel},
	{"NoButtons", QColorDialog::NoButtons},
	{"DontUseNativeDialog", QColorDialog::DontUseNativeDialog},
	{NULL, 0}
};

DEFAPI(void) constQColorDialog(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QColorDialogConstInt);
}

