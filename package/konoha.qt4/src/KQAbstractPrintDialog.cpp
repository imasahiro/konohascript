//
//@Virtual int QAbstractPrintDialog.exec();
KMETHOD QAbstractPrintDialog_exec(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractPrintDialog *  qp = RawPtr_to(QAbstractPrintDialog *, sfp[0]);
	if (qp) {
		int ret_v = qp->exec();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAbstractPrintDialog.fromPage();
KMETHOD QAbstractPrintDialog_fromPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractPrintDialog *  qp = RawPtr_to(QAbstractPrintDialog *, sfp[0]);
	if (qp) {
		int ret_v = qp->fromPage();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAbstractPrintDialog.maxPage();
KMETHOD QAbstractPrintDialog_maxPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractPrintDialog *  qp = RawPtr_to(QAbstractPrintDialog *, sfp[0]);
	if (qp) {
		int ret_v = qp->maxPage();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAbstractPrintDialog.minPage();
KMETHOD QAbstractPrintDialog_minPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractPrintDialog *  qp = RawPtr_to(QAbstractPrintDialog *, sfp[0]);
	if (qp) {
		int ret_v = qp->minPage();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QAbstractPrintDialog.getPrintRange();
KMETHOD QAbstractPrintDialog_getPrintRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractPrintDialog *  qp = RawPtr_to(QAbstractPrintDialog *, sfp[0]);
	if (qp) {
		QAbstractPrintDialog::PrintRange ret_v = qp->printRange();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QPrinter QAbstractPrintDialog.printer();
KMETHOD QAbstractPrintDialog_printer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractPrintDialog *  qp = RawPtr_to(QAbstractPrintDialog *, sfp[0]);
	if (qp) {
		QPrinter* ret_v = qp->printer();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPrinter*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QAbstractPrintDialog.setFromTo(int from_, int to_);
KMETHOD QAbstractPrintDialog_setFromTo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractPrintDialog *  qp = RawPtr_to(QAbstractPrintDialog *, sfp[0]);
	if (qp) {
		int from = Int_to(int, sfp[1]);
		int to = Int_to(int, sfp[2]);
		qp->setFromTo(from, to);
	}
	RETURNvoid_();
}

//void QAbstractPrintDialog.setMinMax(int min, int max);
KMETHOD QAbstractPrintDialog_setMinMax(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractPrintDialog *  qp = RawPtr_to(QAbstractPrintDialog *, sfp[0]);
	if (qp) {
		int min = Int_to(int, sfp[1]);
		int max = Int_to(int, sfp[2]);
		qp->setMinMax(min, max);
	}
	RETURNvoid_();
}

//void QAbstractPrintDialog.setOptionTabs(Array<QWidget> tabs);
KMETHOD QAbstractPrintDialog_setOptionTabs(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractPrintDialog *  qp = RawPtr_to(QAbstractPrintDialog *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QWidget*> tabs;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			tabs.append((QWidget*)p->rawptr);
		}
		qp->setOptionTabs(tabs);
	}
	RETURNvoid_();
}

//void QAbstractPrintDialog.setPrintRange(int range);
KMETHOD QAbstractPrintDialog_setPrintRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractPrintDialog *  qp = RawPtr_to(QAbstractPrintDialog *, sfp[0]);
	if (qp) {
		QAbstractPrintDialog::PrintRange range = Int_to(QAbstractPrintDialog::PrintRange, sfp[1]);
		qp->setPrintRange(range);
	}
	RETURNvoid_();
}

//int QAbstractPrintDialog.toPage();
KMETHOD QAbstractPrintDialog_toPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractPrintDialog *  qp = RawPtr_to(QAbstractPrintDialog *, sfp[0]);
	if (qp) {
		int ret_v = qp->toPage();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQAbstractPrintDialog::DummyQAbstractPrintDialog()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQAbstractPrintDialog::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractPrintDialog::self = ptr;
	DummyQDialog::setSelf(ptr);
}

bool DummyQAbstractPrintDialog::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQDialog::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractPrintDialog::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractPrintDialog::event_map->bigin();
	if ((itr = DummyQAbstractPrintDialog::event_map->find(str)) == DummyQAbstractPrintDialog::event_map->end()) {
		bool ret = false;
		ret = DummyQDialog::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractPrintDialog::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractPrintDialog::slot_map->bigin();
	if ((itr = DummyQAbstractPrintDialog::slot_map->find(str)) == DummyQAbstractPrintDialog::slot_map->end()) {
		bool ret = false;
		ret = DummyQDialog::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQAbstractPrintDialog::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQDialog::reftrace(ctx, p, tail_);
}

void DummyQAbstractPrintDialog::connection(QObject *o)
{
	QAbstractPrintDialog *p = dynamic_cast<QAbstractPrintDialog*>(o);
	if (p != NULL) {
	}
	DummyQDialog::connection(o);
}

KQAbstractPrintDialog::KQAbstractPrintDialog(QPrinter* printer, QWidget* parent) : QAbstractPrintDialog(printer, parent)
{
	self = NULL;
	dummy = new DummyQAbstractPrintDialog();
	dummy->connection((QObject*)this);
}

KMETHOD QAbstractPrintDialog_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractPrintDialog *qp = RawPtr_to(KQAbstractPrintDialog *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractPrintDialog]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractPrintDialog]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAbstractPrintDialog_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractPrintDialog *qp = RawPtr_to(KQAbstractPrintDialog *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractPrintDialog]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractPrintDialog]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractPrintDialog_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAbstractPrintDialog *qp = (KQAbstractPrintDialog *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAbstractPrintDialog_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQAbstractPrintDialog *qp = (KQAbstractPrintDialog *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAbstractPrintDialog_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAbstractPrintDialog::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQAbstractPrintDialog::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QAbstractPrintDialog::event(event);
		return false;
	}
	return true;
}

static knh_IntData_t QAbstractPrintDialogConstInt[] = {
	{"None", QAbstractPrintDialog::None},
	{"PrintToFile", QAbstractPrintDialog::PrintToFile},
	{"PrintSelection", QAbstractPrintDialog::PrintSelection},
	{"PrintPageRange", QAbstractPrintDialog::PrintPageRange},
	{"PrintShowPageSize", QAbstractPrintDialog::PrintShowPageSize},
	{"PrintCollateCopies", QAbstractPrintDialog::PrintCollateCopies},
	{"PrintCurrentPage", QAbstractPrintDialog::PrintCurrentPage},
	{"DontUseSheet", QAbstractPrintDialog::DontUseSheet},
	{"AllPages", QAbstractPrintDialog::AllPages},
	{"Selection", QAbstractPrintDialog::Selection},
	{"PageRange", QAbstractPrintDialog::PageRange},
	{"CurrentPage", QAbstractPrintDialog::CurrentPage},
	{NULL, 0}
};

DEFAPI(void) constQAbstractPrintDialog(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QAbstractPrintDialogConstInt);
}


DEFAPI(void) defQAbstractPrintDialog(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractPrintDialog";
	cdef->free = QAbstractPrintDialog_free;
	cdef->reftrace = QAbstractPrintDialog_reftrace;
	cdef->compareTo = QAbstractPrintDialog_compareTo;
}

//## QAbstractPrintDialogPrintDialogOptions QAbstractPrintDialogPrintDialogOptions.new(int value);
KMETHOD QAbstractPrintDialogPrintDialogOptions_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAbstractPrintDialog::PrintDialogOption i = Int_to(QAbstractPrintDialog::PrintDialogOption, sfp[1]);
	QAbstractPrintDialog::PrintDialogOptions *ret_v = new QAbstractPrintDialog::PrintDialogOptions(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QAbstractPrintDialogPrintDialogOptions QAbstractPrintDialogPrintDialogOptions.and(int mask);
KMETHOD QAbstractPrintDialogPrintDialogOptions_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAbstractPrintDialog::PrintDialogOptions *qp = RawPtr_to(QAbstractPrintDialog::PrintDialogOptions*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QAbstractPrintDialog::PrintDialogOptions ret = ((*qp) & i);
		QAbstractPrintDialog::PrintDialogOptions *ret_ = new QAbstractPrintDialog::PrintDialogOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAbstractPrintDialogPrintDialogOptions QAbstractPrintDialogPrintDialogOptions.iand(QAbstractPrintDialog::QAbstractPrintDialogPrintDialogOptions other);
KMETHOD QAbstractPrintDialogPrintDialogOptions_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAbstractPrintDialog::PrintDialogOptions *qp = RawPtr_to(QAbstractPrintDialog::PrintDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QAbstractPrintDialog::PrintDialogOptions *other = RawPtr_to(QAbstractPrintDialog::PrintDialogOptions *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAbstractPrintDialogPrintDialogOptions QAbstractPrintDialogPrintDialogOptions.or(QAbstractPrintDialogPrintDialogOptions f);
KMETHOD QAbstractPrintDialogPrintDialogOptions_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractPrintDialog::PrintDialogOptions *qp = RawPtr_to(QAbstractPrintDialog::PrintDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QAbstractPrintDialog::PrintDialogOptions *f = RawPtr_to(QAbstractPrintDialog::PrintDialogOptions*, sfp[1]);
		QAbstractPrintDialog::PrintDialogOptions ret = ((*qp) | (*f));
		QAbstractPrintDialog::PrintDialogOptions *ret_ = new QAbstractPrintDialog::PrintDialogOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAbstractPrintDialogPrintDialogOptions QAbstractPrintDialogPrintDialogOptions.ior(QAbstractPrintDialog::QAbstractPrintDialogPrintDialogOptions other);
KMETHOD QAbstractPrintDialogPrintDialogOptions_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAbstractPrintDialog::PrintDialogOptions *qp = RawPtr_to(QAbstractPrintDialog::PrintDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QAbstractPrintDialog::PrintDialogOptions *other = RawPtr_to(QAbstractPrintDialog::PrintDialogOptions *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAbstractPrintDialogPrintDialogOptions QAbstractPrintDialogPrintDialogOptions.xor(QAbstractPrintDialogPrintDialogOptions f);
KMETHOD QAbstractPrintDialogPrintDialogOptions_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractPrintDialog::PrintDialogOptions *qp = RawPtr_to(QAbstractPrintDialog::PrintDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QAbstractPrintDialog::PrintDialogOptions *f = RawPtr_to(QAbstractPrintDialog::PrintDialogOptions*, sfp[1]);
		QAbstractPrintDialog::PrintDialogOptions ret = ((*qp) ^ (*f));
		QAbstractPrintDialog::PrintDialogOptions *ret_ = new QAbstractPrintDialog::PrintDialogOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QAbstractPrintDialogPrintDialogOptions QAbstractPrintDialogPrintDialogOptions.ixor(QAbstractPrintDialog::QAbstractPrintDialogPrintDialogOptions other);
KMETHOD QAbstractPrintDialogPrintDialogOptions_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAbstractPrintDialog::PrintDialogOptions *qp = RawPtr_to(QAbstractPrintDialog::PrintDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QAbstractPrintDialog::PrintDialogOptions *other = RawPtr_to(QAbstractPrintDialog::PrintDialogOptions *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QAbstractPrintDialogPrintDialogOptions.testFlag(int flag);
KMETHOD QAbstractPrintDialogPrintDialogOptions_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAbstractPrintDialog::PrintDialogOptions *qp = RawPtr_to(QAbstractPrintDialog::PrintDialogOptions *, sfp[0]);
	if (qp != NULL) {
		QAbstractPrintDialog::PrintDialogOption flag = Int_to(QAbstractPrintDialog::PrintDialogOption, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QAbstractPrintDialogPrintDialogOptions.value();
KMETHOD QAbstractPrintDialogPrintDialogOptions_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QAbstractPrintDialog::PrintDialogOptions *qp = RawPtr_to(QAbstractPrintDialog::PrintDialogOptions *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QAbstractPrintDialogPrintDialogOptions_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QAbstractPrintDialog::PrintDialogOptions *qp = (QAbstractPrintDialog::PrintDialogOptions *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QAbstractPrintDialogPrintDialogOptions_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QAbstractPrintDialog::PrintDialogOptions *qp = (QAbstractPrintDialog::PrintDialogOptions *)p->rawptr;
		(void)qp;
	}
}

static int QAbstractPrintDialogPrintDialogOptions_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QAbstractPrintDialog::PrintDialogOptions*)p1->rawptr);
//		int v2 = int(*(QAbstractPrintDialog::PrintDialogOptions*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QAbstractPrintDialog::PrintDialogOptions v1 = *(QAbstractPrintDialog::PrintDialogOptions*)p1->rawptr;
		QAbstractPrintDialog::PrintDialogOptions v2 = *(QAbstractPrintDialog::PrintDialogOptions*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQAbstractPrintDialogPrintDialogOptions(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractPrintDialogPrintDialogOptions";
	cdef->free = QAbstractPrintDialogPrintDialogOptions_free;
	cdef->reftrace = QAbstractPrintDialogPrintDialogOptions_reftrace;
	cdef->compareTo = QAbstractPrintDialogPrintDialogOptions_compareTo;
}

