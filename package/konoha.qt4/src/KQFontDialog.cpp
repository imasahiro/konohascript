//@Virtual @Override void QFontDialog.setVisible(boolean visible);
KMETHOD QFontDialog_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		const char*  member = RawPtr_to(const char*, sfp[2]);
		qp->open(receiver, member);
	}
	RETURNvoid_();
}

//int QFontDialog.getOptions();
KMETHOD QFontDialog_getOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp != NULL) {
		QFontDialog::FontDialogOptions ret_v = qp->options();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QFont QFontDialog.selectedFont();
KMETHOD QFontDialog_selectedFont(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		QFontDialog::FontDialogOption option = Int_to(QFontDialog::FontDialogOption, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		qp->setOption(option, on);
	}
	RETURNvoid_();
}

//void QFontDialog.setOptions(int options);
KMETHOD QFontDialog_setOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp != NULL) {
		QFontDialog::FontDialogOptions options = Int_to(QFontDialog::FontDialogOptions, sfp[1]);
		qp->setOptions(options);
	}
	RETURNvoid_();
}

//boolean QFontDialog.testOption(int option);
KMETHOD QFontDialog_testOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp != NULL) {
		QFontDialog::FontDialogOption option = Int_to(QFontDialog::FontDialogOption, sfp[1]);
		bool ret_v = qp->testOption(option);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QFont QFontDialog.getFontOL(boolean ok, QFont initial, QWidget parent, String title, int options);
KMETHOD QFontDialog_getFontOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp != NULL) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		const QFont  initial = *RawPtr_to(const QFont *, sfp[2]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[3]);
		const QString title = String_to(const QString, sfp[4]);
		QFontDialog::FontDialogOptions options = Int_to(QFontDialog::FontDialogOptions, sfp[5]);
		QFont ret_v = qp->getFont(ok, initial, parent, title, options);
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
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp != NULL) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		const QFont  initial = *RawPtr_to(const QFont *, sfp[2]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[3]);
		const char*  name = RawPtr_to(const char*, sfp[4]);
		QFont ret_v = qp->getFont(ok, initial, parent, name);
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
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp != NULL) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
		const char*  name = RawPtr_to(const char*, sfp[3]);
		QFont ret_v = qp->getFont(ok, parent, name);
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
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp != NULL) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		const QFont  initial = *RawPtr_to(const QFont *, sfp[2]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[3]);
		const QString title = String_to(const QString, sfp[4]);
		QFont ret_v = qp->getFont(ok, initial, parent, title);
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
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp != NULL) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		const QFont  initial = *RawPtr_to(const QFont *, sfp[2]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[3]);
		QFont ret_v = qp->getFont(ok, initial, parent);
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
	QFontDialog *  qp = RawPtr_to(QFontDialog *, sfp[0]);
	if (qp != NULL) {
		bool* ok = Boolean_to(bool*, sfp[1]);
		QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
		QFont ret_v = qp->getFont(ok, parent);
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
	self = NULL;
	current_font_changed_func = NULL;
	font_selected_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("current-font-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("font-selected", NULL));
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


void DummyQFontDialog::connection(QObject *o)
{
	connect(o, SIGNAL(currentFontChanged(const QFont)), this, SLOT(currentFontChangedSlot(const QFont)));
	connect(o, SIGNAL(fontSelected(const QFont)), this, SLOT(fontSelectedSlot(const QFont)));
	DummyQDialog::connection(o);
}

KQFontDialog::KQFontDialog(QWidget* parent) : QFontDialog(parent)
{
	self = NULL;
	dummy = new DummyQFontDialog();
	dummy->connection((QObject*)this);
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
	if (p->rawptr != NULL) {
		KQFontDialog *qp = (KQFontDialog *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QFontDialog_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQFontDialog *qp = (KQFontDialog *)p->rawptr;
//		(void)qp;
		if (qp->dummy->current_font_changed_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->current_font_changed_func);
			KNH_SIZEREF(ctx);
		}
		if (qp->dummy->font_selected_func != NULL) {
			KNH_ADDREF(ctx, qp->dummy->font_selected_func);
			KNH_SIZEREF(ctx);
		}
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
	return true;
}

DEFAPI(void) defQFontDialog(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFontDialog";
	cdef->free = QFontDialog_free;
	cdef->reftrace = QFontDialog_reftrace;
	cdef->compareTo = QFontDialog_compareTo;
}

static knh_IntData_t QFontDialogConstInt[] = {
	{"NoButtons", QFontDialog::NoButtons},
	{"DontUseNativeDialog", QFontDialog::DontUseNativeDialog},
	{NULL, 0}
};

DEFAPI(void) constQFontDialog(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QFontDialogConstInt);
}

