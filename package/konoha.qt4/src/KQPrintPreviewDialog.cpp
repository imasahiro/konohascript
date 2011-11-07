//@Virtual @Override void QPrintPreviewDialog.done(int result);
KMETHOD QPrintPreviewDialog_done(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewDialog *  qp = RawPtr_to(QPrintPreviewDialog *, sfp[0]);
	if (qp) {
		int result = Int_to(int, sfp[1]);
		qp->done(result);
	}
	RETURNvoid_();
}

//@Virtual @Override void QPrintPreviewDialog.setVisible(boolean visible);
KMETHOD QPrintPreviewDialog_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewDialog *  qp = RawPtr_to(QPrintPreviewDialog *, sfp[0]);
	if (qp) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setVisible(visible);
	}
	RETURNvoid_();
}

//QPrintPreviewDialog QPrintPreviewDialog.new(QPrinter printer, QWidget parent, QtWindowFlags flags);
KMETHOD QPrintPreviewDialog_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinter*  printer = RawPtr_to(QPrinter*, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	initFlag(flags, Qt::WindowFlags, sfp[3]);
	KQPrintPreviewDialog *ret_v = new KQPrintPreviewDialog(printer, parent, flags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPrintPreviewDialog QPrintPreviewDialog.new(QWidget parent, QtWindowFlags flags);
KMETHOD QPrintPreviewDialog_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	initFlag(flags, Qt::WindowFlags, sfp[2]);
	KQPrintPreviewDialog *ret_v = new KQPrintPreviewDialog(parent, flags);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QPrintPreviewDialog.open(QObject receiver, String member);
KMETHOD QPrintPreviewDialog_open(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewDialog *  qp = RawPtr_to(QPrintPreviewDialog *, sfp[0]);
	if (qp) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		const char*  member = RawPtr_to(const char*, sfp[2]);
		qp->open(receiver, member);
	}
	RETURNvoid_();
}

//QPrinter QPrintPreviewDialog.printer();
KMETHOD QPrintPreviewDialog_printer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintPreviewDialog *  qp = RawPtr_to(QPrintPreviewDialog *, sfp[0]);
	if (qp) {
		QPrinter* ret_v = qp->printer();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPrinter*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQPrintPreviewDialog::DummyQPrintPreviewDialog()
{
	self = NULL;
	paint_requested_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("paint-requested", NULL));
}

void DummyQPrintPreviewDialog::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPrintPreviewDialog::self = ptr;
	DummyQDialog::setSelf(ptr);
}

bool DummyQPrintPreviewDialog::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQDialog::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQPrintPreviewDialog::paintRequestedSlot(QPrinter* printer)
{
	if (paint_requested_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QPrinter, printer);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, paint_requested_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQPrintPreviewDialog::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPrintPreviewDialog::event_map->bigin();
	if ((itr = DummyQPrintPreviewDialog::event_map->find(str)) == DummyQPrintPreviewDialog::event_map->end()) {
		bool ret = false;
		ret = DummyQDialog::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPrintPreviewDialog::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPrintPreviewDialog::slot_map->bigin();
	if ((itr = DummyQPrintPreviewDialog::slot_map->find(str)) == DummyQPrintPreviewDialog::slot_map->end()) {
		bool ret = false;
		ret = DummyQDialog::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		paint_requested_func = (*slot_map)["paint-requested"];
		return true;
	}
}

void DummyQPrintPreviewDialog::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 1;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, paint_requested_func);

	KNH_SIZEREF(ctx);

	DummyQDialog::reftrace(ctx, p, tail_);
}

void DummyQPrintPreviewDialog::connection(QObject *o)
{
	QPrintPreviewDialog *p = dynamic_cast<QPrintPreviewDialog*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(paintRequested(QPrinter*)), this, SLOT(paintRequestedSlot(QPrinter*)));
	}
	DummyQDialog::connection(o);
}

KQPrintPreviewDialog::KQPrintPreviewDialog(QPrinter* printer, QWidget* parent, Qt::WindowFlags flags) : QPrintPreviewDialog(printer, parent, flags)
{
	self = NULL;
	dummy = new DummyQPrintPreviewDialog();
	dummy->connection((QObject*)this);
}

KMETHOD QPrintPreviewDialog_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPrintPreviewDialog *qp = RawPtr_to(KQPrintPreviewDialog *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPrintPreviewDialog]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPrintPreviewDialog]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPrintPreviewDialog_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPrintPreviewDialog *qp = RawPtr_to(KQPrintPreviewDialog *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPrintPreviewDialog]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPrintPreviewDialog]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPrintPreviewDialog_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPrintPreviewDialog *qp = (KQPrintPreviewDialog *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPrintPreviewDialog_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQPrintPreviewDialog *qp = (KQPrintPreviewDialog *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPrintPreviewDialog_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQPrintPreviewDialog::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQPrintPreviewDialog::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QPrintPreviewDialog::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQPrintPreviewDialog(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPrintPreviewDialog";
	cdef->free = QPrintPreviewDialog_free;
	cdef->reftrace = QPrintPreviewDialog_reftrace;
	cdef->compareTo = QPrintPreviewDialog_compareTo;
}


