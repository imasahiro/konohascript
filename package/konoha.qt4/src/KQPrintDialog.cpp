//@Virtual @Override void QPrintDialog.done(int result);
KMETHOD QPrintDialog_done(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintDialog *  qp = RawPtr_to(QPrintDialog *, sfp[0]);
	if (qp) {
		int result = Int_to(int, sfp[1]);
		qp->done(result);
	}
	RETURNvoid_();
}

//@Virtual @Override int QPrintDialog.exec();
KMETHOD QPrintDialog_exec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintDialog *  qp = RawPtr_to(QPrintDialog *, sfp[0]);
	if (qp) {
		int ret_v = qp->exec();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override void QPrintDialog.setVisible(boolean visible);
KMETHOD QPrintDialog_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintDialog *  qp = RawPtr_to(QPrintDialog *, sfp[0]);
	if (qp) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setVisible(visible);
	}
	RETURNvoid_();
}

//QPrintDialog QPrintDialog.new(QPrinter printer, QWidget parent);
KMETHOD QPrintDialog_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter*  printer = RawPtr_to(QPrinter*, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQPrintDialog *ret_v = new KQPrintDialog(printer, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPrintDialog QPrintDialog.new(QWidget parent);
KMETHOD QPrintDialog_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQPrintDialog *ret_v = new KQPrintDialog(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QPrintDialog.open(QObject receiver, String member);
KMETHOD QPrintDialog_open(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintDialog *  qp = RawPtr_to(QPrintDialog *, sfp[0]);
	if (qp) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		const char*  member = RawPtr_to(const char*, sfp[2]);
		qp->open(receiver, member);
	}
	RETURNvoid_();
}

//QAbstractPrintDialogPrintDialogOptions QPrintDialog.getOptions();
KMETHOD QPrintDialog_getOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintDialog *  qp = RawPtr_to(QPrintDialog *, sfp[0]);
	if (qp) {
		QAbstractPrintDialog::PrintDialogOptions ret_v = qp->options();
		QAbstractPrintDialog::PrintDialogOptions *ret_v_ = new QAbstractPrintDialog::PrintDialogOptions(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPrinter QPrintDialog.printer();
KMETHOD QPrintDialog_printer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintDialog *  qp = RawPtr_to(QPrintDialog *, sfp[0]);
	if (qp) {
		QPrinter* ret_v = qp->printer();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPrinter*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QPrintDialog.setOption(int option, boolean on);
KMETHOD QPrintDialog_setOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintDialog *  qp = RawPtr_to(QPrintDialog *, sfp[0]);
	if (qp) {
		QPrintDialog::PrintDialogOption option = Int_to(QPrintDialog::PrintDialogOption, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		qp->setOption(option, on);
	}
	RETURNvoid_();
}

//void QPrintDialog.setOptions(QAbstractPrintDialogPrintDialogOptions options);
KMETHOD QPrintDialog_setOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintDialog *  qp = RawPtr_to(QPrintDialog *, sfp[0]);
	if (qp) {
		initFlag(options, QAbstractPrintDialog::PrintDialogOptions, sfp[1]);
		qp->setOptions(options);
	}
	RETURNvoid_();
}

//boolean QPrintDialog.testOption(int option);
KMETHOD QPrintDialog_testOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintDialog *  qp = RawPtr_to(QPrintDialog *, sfp[0]);
	if (qp) {
		QPrintDialog::PrintDialogOption option = Int_to(QPrintDialog::PrintDialogOption, sfp[1]);
		bool ret_v = qp->testOption(option);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}


DummyQPrintDialog::DummyQPrintDialog()
{
	self = NULL;
	accepted_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("accepted", NULL));
}

void DummyQPrintDialog::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPrintDialog::self = ptr;
	DummyQAbstractPrintDialog::setSelf(ptr);
}

bool DummyQPrintDialog::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractPrintDialog::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQPrintDialog::acceptedSlot(QPrinter* printer)
{
	if (accepted_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QPrinter, printer);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, accepted_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQPrintDialog::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPrintDialog::event_map->bigin();
	if ((itr = DummyQPrintDialog::event_map->find(str)) == DummyQPrintDialog::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractPrintDialog::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPrintDialog::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPrintDialog::slot_map->bigin();
	if ((itr = DummyQPrintDialog::slot_map->find(str)) == DummyQPrintDialog::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractPrintDialog::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		accepted_func = (*slot_map)["accepted"];
		return true;
	}
}

knh_Object_t** DummyQPrintDialog::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQPrintDialog::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 1;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, accepted_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQAbstractPrintDialog::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQPrintDialog::connection(QObject *o)
{
	QPrintDialog *p = dynamic_cast<QPrintDialog*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(accepted(QPrinter*)), this, SLOT(acceptedSlot(QPrinter*)));
	}
	DummyQAbstractPrintDialog::connection(o);
}

KQPrintDialog::KQPrintDialog(QPrinter* printer, QWidget* parent) : QPrintDialog(printer, parent)
{
	self = NULL;
	dummy = new DummyQPrintDialog();
	dummy->connection((QObject*)this);
}

KMETHOD QPrintDialog_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPrintDialog *qp = RawPtr_to(KQPrintDialog *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPrintDialog]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPrintDialog]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPrintDialog_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPrintDialog *qp = RawPtr_to(KQPrintDialog *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPrintDialog]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPrintDialog]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPrintDialog_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPrintDialog *qp = (KQPrintDialog *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPrintDialog_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQPrintDialog *qp = (KQPrintDialog *)p->rawptr;
//		KQPrintDialog *qp = static_cast<KQPrintDialog*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPrintDialog_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQPrintDialog::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQPrintDialog::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QPrintDialog::event(event);
		return false;
	}
//	QPrintDialog::event(event);
	return true;
}



DEFAPI(void) defQPrintDialog(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPrintDialog";
	cdef->free = QPrintDialog_free;
	cdef->reftrace = QPrintDialog_reftrace;
	cdef->compareTo = QPrintDialog_compareTo;
}


