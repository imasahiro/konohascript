//@Virtual @Override void QFontDialog.setVisible(boolean visible);
KMETHOD QFontDialog_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setVisible(visible);
	}
	RETURNvoid_();
}

//QFontDialog QFontDialog.new(QWidget parent);
KMETHOD QFontDialog_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQFontDialog *ret_v = new KQFontDialog(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QFontDialog QFontDialog.new(QFont initial, QWidget parent);
KMETHOD QFontDialog_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QFont  initial = *RawPtr_to(const QFont *, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQFontDialog *ret_v = new KQFontDialog(initial, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QFont QFontDialog.getCurrentFont();
KMETHOD QFontDialog_getCurrentFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp) {
		QFont ret_v = qp->currentFont();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QFontDialog.openOL(QObject receiver, String member);
KMETHOD QFontDialog_openOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		const char*  member = RawPtr_to(const char*, sfp[2]);
		qp->open(receiver, member);
	}
	RETURNvoid_();
}

//QFontDialogFontDialogOptions QFontDialog.getOptions();
KMETHOD QFontDialog_getOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp) {
		QFontDialog::FontDialogOptions ret_v = qp->options();
		QFontDialog::FontDialogOptions *ret_v_ = new QFontDialog::FontDialogOptions(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QFont QFontDialog.selectedFont();
KMETHOD QFontDialog_selectedFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp) {
		QFont ret_v = qp->selectedFont();
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QFontDialog.setCurrentFont(QFont font);
KMETHOD QFontDialog_setCurrentFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp) {
		const QFont  font = *RawPtr_to(const QFont *, sfp[1]);
		qp->setCurrentFont(font);
	}
	RETURNvoid_();
}

//void QFontDialog.setOption(int option, boolean on);
KMETHOD QFontDialog_setOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp) {
		QFontDialog::FontDialogOption option = Int_to(QFontDialog::FontDialogOption, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		qp->setOption(option, on);
	}
	RETURNvoid_();
}

//void QFontDialog.setOptions(QFontDialogFontDialogOptions options);
KMETHOD QFontDialog_setOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp) {
		initFlag(options, QFontDialog::FontDialogOptions, sfp[1]);
		qp->setOptions(options);
	}
	RETURNvoid_();
}

//boolean QFontDialog.testOption(int option);
KMETHOD QFontDialog_testOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp) {
		QFontDialog::FontDialogOption option = Int_to(QFontDialog::FontDialogOption, sfp[1]);
		bool ret_v = qp->testOption(option);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QFont QFontDialog.getFontOL(boolean ok, QFont initial, QWidget parent, String title, QFontDialogFontDialogOptions options);
KMETHOD QFontDialog_getFontOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		const QFont  initial = *RawPtr_to(const QFont *, sfp[2]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[3]);
		const QString title = String_to(const QString, sfp[4]);
		initFlag(options, QFontDialog::FontDialogOptions, sfp[5]);
		QFont ret_v = QFontDialog::getFont(ok, initial, parent, title, options);
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QFont QFontDialog.getFontOL(boolean ok, QFont initial, QWidget parent, String name);
KMETHOD QFontDialog_getFontOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		const QFont  initial = *RawPtr_to(const QFont *, sfp[2]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[3]);
		const char*  name = RawPtr_to(const char*, sfp[4]);
		QFont ret_v = QFontDialog::getFont(ok, initial, parent, name);
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QFont QFontDialog.getFontOL(boolean ok, QWidget parent, String name);
KMETHOD QFontDialog_getFontOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
		const char*  name = RawPtr_to(const char*, sfp[3]);
		QFont ret_v = QFontDialog::getFont(ok, parent, name);
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QFont QFontDialog.getFontOL(boolean ok, QFont initial, QWidget parent, String title);
KMETHOD QFontDialog_getFontOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		const QFont  initial = *RawPtr_to(const QFont *, sfp[2]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[3]);
		const QString title = String_to(const QString, sfp[4]);
		QFont ret_v = QFontDialog::getFont(ok, initial, parent, title);
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QFont QFontDialog.getFontOL(boolean ok, QFont initial, QWidget parent);
KMETHOD QFontDialog_getFontOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		const QFont  initial = *RawPtr_to(const QFont *, sfp[2]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[3]);
		QFont ret_v = QFontDialog::getFont(ok, initial, parent);
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//QFont QFontDialog.getFontOL(boolean ok, QWidget parent);
KMETHOD QFontDialog_getFontOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
		QFont ret_v = QFontDialog::getFont(ok, parent);
		QFont *ret_v_ = new QFont(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/

DummyQFontDialog::DummyQFontDialog()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	current_font_changed_func = NULL;
	font_selected_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("current-font-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("font-selected", NULL));
}
DummyQFontDialog::~DummyQFontDialog()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQFontDialog::setSelf(knh_RawPtr_t *ptr)
{
	DummyQFontDialog::self = ptr;
	DummyQDialog::setSelf(ptr);
}

bool DummyQFontDialog::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQDialog::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQFontDialog::currentFontChangedSlot(const QFont font)
{
	if (current_font_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QFont, font);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, current_font_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQFontDialog::fontSelectedSlot(const QFont font)
{
	if (font_selected_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QFont, font);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, font_selected_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQFontDialog::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFontDialog::event_map->bigin();
	if ((itr = DummyQFontDialog::event_map->find(str)) == DummyQFontDialog::event_map->end()) {
		bool ret = false;
		ret = DummyQDialog::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQFontDialog::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFontDialog::slot_map->bigin();
	if ((itr = DummyQFontDialog::slot_map->find(str)) == DummyQFontDialog::slot_map->end()) {
		bool ret = false;
		ret = DummyQDialog::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		current_font_changed_func = (*slot_map)["current-font-changed"];
		font_selected_func = (*slot_map)["font-selected"];
		return true;
	}
}

knh_Object_t** DummyQFontDialog::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQFontDialog::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 3;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, current_font_changed_func);
	KNH_ADDNNREF(ctx, font_selected_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQDialog::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQFontDialog::connection(QObject *o)
{
	QFontDialog *p = dynamic_cast<QFontDialog*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(currentFontChanged(const QFont)), this, SLOT(currentFontChangedSlot(const QFont)));
		connect(p, SIGNAL(fontSelected(const QFont)), this, SLOT(fontSelectedSlot(const QFont)));
	}
	DummyQDialog::connection(o);
}

KQFontDialog::KQFontDialog(QWidget* parent) : QFontDialog(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQFontDialog();
	dummy->connection((QObject*)this);
}

KQFontDialog::~KQFontDialog()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QFontDialog_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFontDialog *qp = RawPtr_to(KQFontDialog *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QFontDialog]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFontDialog]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QFontDialog_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFontDialog *qp = RawPtr_to(KQFontDialog *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QFontDialog]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFontDialog]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QFontDialog_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQFontDialog *qp = (KQFontDialog *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QFontDialog*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QFontDialog_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQFontDialog *qp = (KQFontDialog *)p->rawptr;
		KQFontDialog *qp = static_cast<KQFontDialog*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QFontDialog_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQFontDialog::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQFontDialog::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QFontDialog::event(event);
		return false;
	}
//	QFontDialog::event(event);
	return true;
}

static knh_IntData_t QFontDialogConstInt[] = {
	{"NoButtons", QFontDialog::NoButtons},
	{"DontUseNativeDialog", QFontDialog::DontUseNativeDialog},
	{NULL, 0}
};

DEFAPI(void) constQFontDialog(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QFontDialogConstInt);
}


DEFAPI(void) defQFontDialog(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFontDialog";
	cdef->free = QFontDialog_free;
	cdef->reftrace = QFontDialog_reftrace;
	cdef->compareTo = QFontDialog_compareTo;
}

//## QFontDialogFontDialogOptions QFontDialogFontDialogOptions.new(int value);
KMETHOD QFontDialogFontDialogOptions_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QFontDialog::FontDialogOption i = Int_to(QFontDialog::FontDialogOption, sfp[1]);
	QFontDialog::FontDialogOptions *ret_v = new QFontDialog::FontDialogOptions(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QFontDialogFontDialogOptions QFontDialogFontDialogOptions.and(int mask);
KMETHOD QFontDialogFontDialogOptions_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QFontDialog::FontDialogOptions *qp = RawPtr_to(QFontDialog::FontDialogOptions*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QFontDialog::FontDialogOptions ret = ((*qp) & i);
		QFontDialog::FontDialogOptions *ret_ = new QFontDialog::FontDialogOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QFontDialogFontDialogOptions QFontDialogFontDialogOptions.iand(QFontDialog::QFontDialogFontDialogOptions other);
KMETHOD QFontDialogFontDialogOptions_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QFontDialog::FontDialogOptions *qp = RawPtr_to(QFontDialog::FontDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QFontDialog::FontDialogOptions *other = RawPtr_to(QFontDialog::FontDialogOptions *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QFontDialogFontDialogOptions QFontDialogFontDialogOptions.or(QFontDialogFontDialogOptions f);
KMETHOD QFontDialogFontDialogOptions_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDialog::FontDialogOptions *qp = RawPtr_to(QFontDialog::FontDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QFontDialog::FontDialogOptions *f = RawPtr_to(QFontDialog::FontDialogOptions*, sfp[1]);
		QFontDialog::FontDialogOptions ret = ((*qp) | (*f));
		QFontDialog::FontDialogOptions *ret_ = new QFontDialog::FontDialogOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QFontDialogFontDialogOptions QFontDialogFontDialogOptions.ior(QFontDialog::QFontDialogFontDialogOptions other);
KMETHOD QFontDialogFontDialogOptions_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QFontDialog::FontDialogOptions *qp = RawPtr_to(QFontDialog::FontDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QFontDialog::FontDialogOptions *other = RawPtr_to(QFontDialog::FontDialogOptions *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QFontDialogFontDialogOptions QFontDialogFontDialogOptions.xor(QFontDialogFontDialogOptions f);
KMETHOD QFontDialogFontDialogOptions_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDialog::FontDialogOptions *qp = RawPtr_to(QFontDialog::FontDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QFontDialog::FontDialogOptions *f = RawPtr_to(QFontDialog::FontDialogOptions*, sfp[1]);
		QFontDialog::FontDialogOptions ret = ((*qp) ^ (*f));
		QFontDialog::FontDialogOptions *ret_ = new QFontDialog::FontDialogOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QFontDialogFontDialogOptions QFontDialogFontDialogOptions.ixor(QFontDialog::QFontDialogFontDialogOptions other);
KMETHOD QFontDialogFontDialogOptions_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QFontDialog::FontDialogOptions *qp = RawPtr_to(QFontDialog::FontDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QFontDialog::FontDialogOptions *other = RawPtr_to(QFontDialog::FontDialogOptions *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QFontDialogFontDialogOptions.testFlag(int flag);
KMETHOD QFontDialogFontDialogOptions_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QFontDialog::FontDialogOptions *qp = RawPtr_to(QFontDialog::FontDialogOptions *, sfp[0]);
	if (qp != NULL) {
		QFontDialog::FontDialogOption flag = Int_to(QFontDialog::FontDialogOption, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QFontDialogFontDialogOptions.value();
KMETHOD QFontDialogFontDialogOptions_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QFontDialog::FontDialogOptions *qp = RawPtr_to(QFontDialog::FontDialogOptions *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QFontDialogFontDialogOptions_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QFontDialog::FontDialogOptions *qp = (QFontDialog::FontDialogOptions *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QFontDialogFontDialogOptions_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QFontDialog::FontDialogOptions *qp = (QFontDialog::FontDialogOptions *)p->rawptr;
		(void)qp;
	}
}

static int QFontDialogFontDialogOptions_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QFontDialog::FontDialogOptions*)p1->rawptr);
//		int v2 = int(*(QFontDialog::FontDialogOptions*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QFontDialog::FontDialogOptions v1 = *(QFontDialog::FontDialogOptions*)p1->rawptr;
		QFontDialog::FontDialogOptions v2 = *(QFontDialog::FontDialogOptions*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQFontDialogFontDialogOptions(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFontDialogFontDialogOptions";
	cdef->free = QFontDialogFontDialogOptions_free;
	cdef->reftrace = QFontDialogFontDialogOptions_reftrace;
	cdef->compareTo = QFontDialogFontDialogOptions_compareTo;
}

