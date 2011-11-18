//@Virtual @Override void QColorDialog.setVisible(boolean visible);
KMETHOD QColorDialog_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp) {
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
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QColor QColorDialog.getCurrentColor();
KMETHOD QColorDialog_getCurrentColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		const char*  member = RawPtr_to(const char*, sfp[2]);
		qp->open(receiver, member);
	}
	RETURNvoid_();
}
*/
//QColorDialogColorDialogOptions QColorDialog.getOptions();
KMETHOD QColorDialog_getOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp) {
		QColorDialog::ColorDialogOptions ret_v = qp->options();
		QColorDialog::ColorDialogOptions *ret_v_ = new QColorDialog::ColorDialogOptions(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QColor QColorDialog.selectedColor();
KMETHOD QColorDialog_selectedColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		QColorDialog::ColorDialogOption option = Int_to(QColorDialog::ColorDialogOption, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		qp->setOption(option, on);
	}
	RETURNvoid_();
}

//void QColorDialog.setOptions(QColorDialogColorDialogOptions options);
KMETHOD QColorDialog_setOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp) {
		initFlag(options, QColorDialog::ColorDialogOptions, sfp[1]);
		qp->setOptions(options);
	}
	RETURNvoid_();
}

//boolean QColorDialog.testOption(int option);
KMETHOD QColorDialog_testOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog *  qp = RawPtr_to(QColorDialog *, sfp[0]);
	if (qp) {
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
	if (true) {
		int index = Int_to(int, sfp[1]);
		QRgb ret_v = QColorDialog::customColor(index);
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
	if (true) {
		int ret_v = QColorDialog::customCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QColor QColorDialog.getColor(QColor initial, QWidget parent, String title, QColorDialogColorDialogOptions options);
KMETHOD QColorDialog_getColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QColor  initial = *RawPtr_to(const QColor *, sfp[1]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
		const QString title = String_to(const QString, sfp[3]);
		initFlag(options, QColorDialog::ColorDialogOptions, sfp[4]);
		QColor ret_v = QColorDialog::getColor(initial, parent, title, options);
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
	if (true) {
		const QColor  initial = *RawPtr_to(const QColor *, sfp[1]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
		QColor ret_v = QColorDialog::getColor(initial, parent);
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
	if (true) {
		int index = Int_to(int, sfp[1]);
		QRgb  color = *RawPtr_to(QRgb *, sfp[2]);
		QColorDialog::setCustomColor(index, color);
	}
	RETURNvoid_();
}

//void QColorDialog.setStandardColor(int index, QRgb color);
KMETHOD QColorDialog_setStandardColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		int index = Int_to(int, sfp[1]);
		QRgb  color = *RawPtr_to(QRgb *, sfp[2]);
		QColorDialog::setStandardColor(index, color);
	}
	RETURNvoid_();
}


DummyQColorDialog::DummyQColorDialog()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	color_selected_func = NULL;
	current_color_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("color-selected", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("current-color-changed", NULL));
}
DummyQColorDialog::~DummyQColorDialog()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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

bool DummyQColorDialog::colorSelectedSlot(const QColor color)
{
	if (color_selected_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QColor, color);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, color_selected_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQColorDialog::currentColorChangedSlot(const QColor color)
{
	if (current_color_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QColor, color);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, current_color_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQColorDialog::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQColorDialog::event_map->bigin();
	if ((itr = DummyQColorDialog::event_map->find(str)) == DummyQColorDialog::event_map->end()) {
		bool ret = false;
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
	if ((itr = DummyQColorDialog::slot_map->find(str)) == DummyQColorDialog::slot_map->end()) {
		bool ret = false;
		ret = DummyQDialog::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		color_selected_func = (*slot_map)["color-selected"];
		current_color_changed_func = (*slot_map)["current-color-changed"];
		return true;
	}
}

knh_Object_t** DummyQColorDialog::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQColorDialog::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 3;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, color_selected_func);
	KNH_ADDNNREF(ctx, current_color_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQDialog::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQColorDialog::connection(QObject *o)
{
	QColorDialog *p = dynamic_cast<QColorDialog*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(colorSelected(const QColor)), this, SLOT(colorSelectedSlot(const QColor)));
		connect(p, SIGNAL(currentColorChanged(const QColor)), this, SLOT(currentColorChangedSlot(const QColor)));
	}
	DummyQDialog::connection(o);
}

KQColorDialog::KQColorDialog(QWidget* parent) : QColorDialog(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQColorDialog();
	dummy->connection((QObject*)this);
}

KQColorDialog::~KQColorDialog()
{
	delete dummy;
	dummy = NULL;
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QColorDialog]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QColorDialog_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQColorDialog *qp = (KQColorDialog *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QColorDialog*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QColorDialog_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQColorDialog *qp = (KQColorDialog *)p->rawptr;
		KQColorDialog *qp = static_cast<KQColorDialog*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QColorDialog_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQColorDialog::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQColorDialog::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QColorDialog::event(event);
		return false;
	}
//	QColorDialog::event(event);
	return true;
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


DEFAPI(void) defQColorDialog(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QColorDialog";
	cdef->free = QColorDialog_free;
	cdef->reftrace = QColorDialog_reftrace;
	cdef->compareTo = QColorDialog_compareTo;
}

//## QColorDialogColorDialogOptions QColorDialogColorDialogOptions.new(int value);
KMETHOD QColorDialogColorDialogOptions_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QColorDialog::ColorDialogOption i = Int_to(QColorDialog::ColorDialogOption, sfp[1]);
	QColorDialog::ColorDialogOptions *ret_v = new QColorDialog::ColorDialogOptions(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QColorDialogColorDialogOptions QColorDialogColorDialogOptions.and(int mask);
KMETHOD QColorDialogColorDialogOptions_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QColorDialog::ColorDialogOptions *qp = RawPtr_to(QColorDialog::ColorDialogOptions*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QColorDialog::ColorDialogOptions ret = ((*qp) & i);
		QColorDialog::ColorDialogOptions *ret_ = new QColorDialog::ColorDialogOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QColorDialogColorDialogOptions QColorDialogColorDialogOptions.iand(QColorDialog::QColorDialogColorDialogOptions other);
KMETHOD QColorDialogColorDialogOptions_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QColorDialog::ColorDialogOptions *qp = RawPtr_to(QColorDialog::ColorDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QColorDialog::ColorDialogOptions *other = RawPtr_to(QColorDialog::ColorDialogOptions *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QColorDialogColorDialogOptions QColorDialogColorDialogOptions.or(QColorDialogColorDialogOptions f);
KMETHOD QColorDialogColorDialogOptions_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog::ColorDialogOptions *qp = RawPtr_to(QColorDialog::ColorDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QColorDialog::ColorDialogOptions *f = RawPtr_to(QColorDialog::ColorDialogOptions*, sfp[1]);
		QColorDialog::ColorDialogOptions ret = ((*qp) | (*f));
		QColorDialog::ColorDialogOptions *ret_ = new QColorDialog::ColorDialogOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QColorDialogColorDialogOptions QColorDialogColorDialogOptions.ior(QColorDialog::QColorDialogColorDialogOptions other);
KMETHOD QColorDialogColorDialogOptions_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QColorDialog::ColorDialogOptions *qp = RawPtr_to(QColorDialog::ColorDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QColorDialog::ColorDialogOptions *other = RawPtr_to(QColorDialog::ColorDialogOptions *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QColorDialogColorDialogOptions QColorDialogColorDialogOptions.xor(QColorDialogColorDialogOptions f);
KMETHOD QColorDialogColorDialogOptions_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QColorDialog::ColorDialogOptions *qp = RawPtr_to(QColorDialog::ColorDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QColorDialog::ColorDialogOptions *f = RawPtr_to(QColorDialog::ColorDialogOptions*, sfp[1]);
		QColorDialog::ColorDialogOptions ret = ((*qp) ^ (*f));
		QColorDialog::ColorDialogOptions *ret_ = new QColorDialog::ColorDialogOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QColorDialogColorDialogOptions QColorDialogColorDialogOptions.ixor(QColorDialog::QColorDialogColorDialogOptions other);
KMETHOD QColorDialogColorDialogOptions_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QColorDialog::ColorDialogOptions *qp = RawPtr_to(QColorDialog::ColorDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QColorDialog::ColorDialogOptions *other = RawPtr_to(QColorDialog::ColorDialogOptions *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QColorDialogColorDialogOptions.testFlag(int flag);
KMETHOD QColorDialogColorDialogOptions_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QColorDialog::ColorDialogOptions *qp = RawPtr_to(QColorDialog::ColorDialogOptions *, sfp[0]);
	if (qp != NULL) {
		QColorDialog::ColorDialogOption flag = Int_to(QColorDialog::ColorDialogOption, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QColorDialogColorDialogOptions.value();
KMETHOD QColorDialogColorDialogOptions_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QColorDialog::ColorDialogOptions *qp = RawPtr_to(QColorDialog::ColorDialogOptions *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QColorDialogColorDialogOptions_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QColorDialog::ColorDialogOptions *qp = (QColorDialog::ColorDialogOptions *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QColorDialogColorDialogOptions_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QColorDialog::ColorDialogOptions *qp = (QColorDialog::ColorDialogOptions *)p->rawptr;
		(void)qp;
	}
}

static int QColorDialogColorDialogOptions_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QColorDialog::ColorDialogOptions*)p1->rawptr);
//		int v2 = int(*(QColorDialog::ColorDialogOptions*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QColorDialog::ColorDialogOptions v1 = *(QColorDialog::ColorDialogOptions*)p1->rawptr;
		QColorDialog::ColorDialogOptions v2 = *(QColorDialog::ColorDialogOptions*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQColorDialogColorDialogOptions(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QColorDialogColorDialogOptions";
	cdef->free = QColorDialogColorDialogOptions_free;
	cdef->reftrace = QColorDialogColorDialogOptions_reftrace;
	cdef->compareTo = QColorDialogColorDialogOptions_compareTo;
}

