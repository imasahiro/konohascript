//@Virtual @Override void QPageSetupDialog.setVisible(boolean visible);
KMETHOD QPageSetupDialog_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPageSetupDialog *  qp = RawPtr_to(QPageSetupDialog *, sfp[0]);
	if (qp != NULL) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setVisible(visible);
	}
	RETURNvoid_();
}

//QPageSetupDialog QPageSetupDialog.new(QPrinter printer, QWidget parent);
KMETHOD QPageSetupDialog_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter*  printer = RawPtr_to(QPrinter*, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQPageSetupDialog *ret_v = new KQPageSetupDialog(printer, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPageSetupDialog QPageSetupDialog.new(QWidget parent);
KMETHOD QPageSetupDialog_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQPageSetupDialog *ret_v = new KQPageSetupDialog(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QPageSetupDialog.open(QObject receiver, String member);
KMETHOD QPageSetupDialog_open(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPageSetupDialog *  qp = RawPtr_to(QPageSetupDialog *, sfp[0]);
	if (qp != NULL) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		const char*  member = RawPtr_to(const char*, sfp[2]);
		qp->open(receiver, member);
	}
	RETURNvoid_();
}

//int QPageSetupDialog.getOptions();
KMETHOD QPageSetupDialog_getOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPageSetupDialog *  qp = RawPtr_to(QPageSetupDialog *, sfp[0]);
	if (qp != NULL) {
		QPageSetupDialog::PageSetupDialogOptions ret_v = qp->options();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPrinter QPageSetupDialog.printer();
KMETHOD QPageSetupDialog_printer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPageSetupDialog *  qp = RawPtr_to(QPageSetupDialog *, sfp[0]);
	if (qp != NULL) {
		QPrinter* ret_v = qp->printer();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPrinter*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QPageSetupDialog.setOption(int option, boolean on);
KMETHOD QPageSetupDialog_setOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPageSetupDialog *  qp = RawPtr_to(QPageSetupDialog *, sfp[0]);
	if (qp != NULL) {
		QPageSetupDialog::PageSetupDialogOption option = Int_to(QPageSetupDialog::PageSetupDialogOption, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		qp->setOption(option, on);
	}
	RETURNvoid_();
}

//void QPageSetupDialog.setOptions(int options);
KMETHOD QPageSetupDialog_setOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPageSetupDialog *  qp = RawPtr_to(QPageSetupDialog *, sfp[0]);
	if (qp != NULL) {
		QPageSetupDialog::PageSetupDialogOptions options = Int_to(QPageSetupDialog::PageSetupDialogOptions, sfp[1]);
		qp->setOptions(options);
	}
	RETURNvoid_();
}

//boolean QPageSetupDialog.testOption(int option);
KMETHOD QPageSetupDialog_testOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPageSetupDialog *  qp = RawPtr_to(QPageSetupDialog *, sfp[0]);
	if (qp != NULL) {
		QPageSetupDialog::PageSetupDialogOption option = Int_to(QPageSetupDialog::PageSetupDialogOption, sfp[1]);
		bool ret_v = qp->testOption(option);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQPageSetupDialog::DummyQPageSetupDialog()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPageSetupDialog::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPageSetupDialog::self = ptr;
	DummyQDialog::setSelf(ptr);
}

bool DummyQPageSetupDialog::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQDialog::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQPageSetupDialog::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPageSetupDialog::event_map->bigin();
	if ((itr = DummyQPageSetupDialog::event_map->find(str)) == DummyQPageSetupDialog::event_map->end()) {
		bool ret;
		ret = DummyQDialog::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPageSetupDialog::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPageSetupDialog::slot_map->bigin();
	if ((itr = DummyQPageSetupDialog::event_map->find(str)) == DummyQPageSetupDialog::slot_map->end()) {
		bool ret;
		ret = DummyQDialog::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQPageSetupDialog::KQPageSetupDialog(QPrinter* printer, QWidget* parent) : QPageSetupDialog(printer, parent)
{
	self = NULL;
}

KMETHOD QPageSetupDialog_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPageSetupDialog *qp = RawPtr_to(KQPageSetupDialog *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPageSetupDialog]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQPageSetupDialog::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPageSetupDialog]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QPageSetupDialog_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPageSetupDialog *qp = RawPtr_to(KQPageSetupDialog *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPageSetupDialog]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQPageSetupDialog::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPageSetupDialog]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPageSetupDialog_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPageSetupDialog *qp = (KQPageSetupDialog *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPageSetupDialog_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQPageSetupDialog *qp = (KQPageSetupDialog *)p->rawptr;
		(void)qp;
	}
}

static int QPageSetupDialog_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQPageSetupDialog::event(QEvent *event)
{
	if (!DummyQPageSetupDialog::eventDispatcher(event)) {
		QPageSetupDialog::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQPageSetupDialog(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPageSetupDialog";
	cdef->free = QPageSetupDialog_free;
	cdef->reftrace = QPageSetupDialog_reftrace;
	cdef->compareTo = QPageSetupDialog_compareTo;
}

static knh_IntData_t QPageSetupDialogConstInt[] = {
	{"DontUseSheet", QPageSetupDialog::DontUseSheet},
	{NULL, 0}
};

DEFAPI(void) constQPageSetupDialog(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QPageSetupDialogConstInt);
}

