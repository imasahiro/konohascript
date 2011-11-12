//@Virtual @Override void QPageSetupDialog.setVisible(boolean visible);
KMETHOD QPageSetupDialog_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPageSetupDialog *  qp = RawPtr_to(QPageSetupDialog *, sfp[0]);
	if (qp) {
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
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QPageSetupDialog.open(QObject receiver, String member);
KMETHOD QPageSetupDialog_open(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPageSetupDialog *  qp = RawPtr_to(QPageSetupDialog *, sfp[0]);
	if (qp) {
		QObject*  receiver = RawPtr_to(QObject*, sfp[1]);
		const char*  member = RawPtr_to(const char*, sfp[2]);
		qp->open(receiver, member);
	}
	RETURNvoid_();
}

//QPageSetupDialogPageSetupDialogOptions QPageSetupDialog.getOptions();
KMETHOD QPageSetupDialog_getOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPageSetupDialog *  qp = RawPtr_to(QPageSetupDialog *, sfp[0]);
	if (qp) {
		QPageSetupDialog::PageSetupDialogOptions ret_v = qp->options();
		QPageSetupDialog::PageSetupDialogOptions *ret_v_ = new QPageSetupDialog::PageSetupDialogOptions(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPrinter QPageSetupDialog.printer();
KMETHOD QPageSetupDialog_printer(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPageSetupDialog *  qp = RawPtr_to(QPageSetupDialog *, sfp[0]);
	if (qp) {
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
	if (qp) {
		QPageSetupDialog::PageSetupDialogOption option = Int_to(QPageSetupDialog::PageSetupDialogOption, sfp[1]);
		bool on = Boolean_to(bool, sfp[2]);
		qp->setOption(option, on);
	}
	RETURNvoid_();
}

//void QPageSetupDialog.setOptions(QPageSetupDialogPageSetupDialogOptions options);
KMETHOD QPageSetupDialog_setOptions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPageSetupDialog *  qp = RawPtr_to(QPageSetupDialog *, sfp[0]);
	if (qp) {
		initFlag(options, QPageSetupDialog::PageSetupDialogOptions, sfp[1]);
		qp->setOptions(options);
	}
	RETURNvoid_();
}

//boolean QPageSetupDialog.testOption(int option);
KMETHOD QPageSetupDialog_testOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPageSetupDialog *  qp = RawPtr_to(QPageSetupDialog *, sfp[0]);
	if (qp) {
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
		bool ret = false;
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
	if ((itr = DummyQPageSetupDialog::slot_map->find(str)) == DummyQPageSetupDialog::slot_map->end()) {
		bool ret = false;
		ret = DummyQDialog::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQPageSetupDialog::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQPageSetupDialog::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQDialog::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQPageSetupDialog::connection(QObject *o)
{
	QPageSetupDialog *p = dynamic_cast<QPageSetupDialog*>(o);
	if (p != NULL) {
	}
	DummyQDialog::connection(o);
}

KQPageSetupDialog::KQPageSetupDialog(QPrinter* printer, QWidget* parent) : QPageSetupDialog(printer, parent)
{
	self = NULL;
	dummy = new DummyQPageSetupDialog();
	dummy->connection((QObject*)this);
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
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
	if (p->rawptr != NULL) {
		KQPageSetupDialog *qp = (KQPageSetupDialog *)p->rawptr;
//		KQPageSetupDialog *qp = static_cast<KQPageSetupDialog*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPageSetupDialog_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQPageSetupDialog::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQPageSetupDialog::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QPageSetupDialog::event(event);
		return false;
	}
//	QPageSetupDialog::event(event);
	return true;
}

static knh_IntData_t QPageSetupDialogConstInt[] = {
	{"DontUseSheet", QPageSetupDialog::DontUseSheet},
	{NULL, 0}
};

DEFAPI(void) constQPageSetupDialog(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QPageSetupDialogConstInt);
}


DEFAPI(void) defQPageSetupDialog(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPageSetupDialog";
	cdef->free = QPageSetupDialog_free;
	cdef->reftrace = QPageSetupDialog_reftrace;
	cdef->compareTo = QPageSetupDialog_compareTo;
}

//## QPageSetupDialogPageSetupDialogOptions QPageSetupDialogPageSetupDialogOptions.new(int value);
KMETHOD QPageSetupDialogPageSetupDialogOptions_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPageSetupDialog::PageSetupDialogOption i = Int_to(QPageSetupDialog::PageSetupDialogOption, sfp[1]);
	QPageSetupDialog::PageSetupDialogOptions *ret_v = new QPageSetupDialog::PageSetupDialogOptions(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QPageSetupDialogPageSetupDialogOptions QPageSetupDialogPageSetupDialogOptions.and(int mask);
KMETHOD QPageSetupDialogPageSetupDialogOptions_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPageSetupDialog::PageSetupDialogOptions *qp = RawPtr_to(QPageSetupDialog::PageSetupDialogOptions*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QPageSetupDialog::PageSetupDialogOptions ret = ((*qp) & i);
		QPageSetupDialog::PageSetupDialogOptions *ret_ = new QPageSetupDialog::PageSetupDialogOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPageSetupDialogPageSetupDialogOptions QPageSetupDialogPageSetupDialogOptions.iand(QPageSetupDialog::QPageSetupDialogPageSetupDialogOptions other);
KMETHOD QPageSetupDialogPageSetupDialogOptions_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPageSetupDialog::PageSetupDialogOptions *qp = RawPtr_to(QPageSetupDialog::PageSetupDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QPageSetupDialog::PageSetupDialogOptions *other = RawPtr_to(QPageSetupDialog::PageSetupDialogOptions *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPageSetupDialogPageSetupDialogOptions QPageSetupDialogPageSetupDialogOptions.or(QPageSetupDialogPageSetupDialogOptions f);
KMETHOD QPageSetupDialogPageSetupDialogOptions_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPageSetupDialog::PageSetupDialogOptions *qp = RawPtr_to(QPageSetupDialog::PageSetupDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QPageSetupDialog::PageSetupDialogOptions *f = RawPtr_to(QPageSetupDialog::PageSetupDialogOptions*, sfp[1]);
		QPageSetupDialog::PageSetupDialogOptions ret = ((*qp) | (*f));
		QPageSetupDialog::PageSetupDialogOptions *ret_ = new QPageSetupDialog::PageSetupDialogOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPageSetupDialogPageSetupDialogOptions QPageSetupDialogPageSetupDialogOptions.ior(QPageSetupDialog::QPageSetupDialogPageSetupDialogOptions other);
KMETHOD QPageSetupDialogPageSetupDialogOptions_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPageSetupDialog::PageSetupDialogOptions *qp = RawPtr_to(QPageSetupDialog::PageSetupDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QPageSetupDialog::PageSetupDialogOptions *other = RawPtr_to(QPageSetupDialog::PageSetupDialogOptions *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPageSetupDialogPageSetupDialogOptions QPageSetupDialogPageSetupDialogOptions.xor(QPageSetupDialogPageSetupDialogOptions f);
KMETHOD QPageSetupDialogPageSetupDialogOptions_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPageSetupDialog::PageSetupDialogOptions *qp = RawPtr_to(QPageSetupDialog::PageSetupDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QPageSetupDialog::PageSetupDialogOptions *f = RawPtr_to(QPageSetupDialog::PageSetupDialogOptions*, sfp[1]);
		QPageSetupDialog::PageSetupDialogOptions ret = ((*qp) ^ (*f));
		QPageSetupDialog::PageSetupDialogOptions *ret_ = new QPageSetupDialog::PageSetupDialogOptions(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QPageSetupDialogPageSetupDialogOptions QPageSetupDialogPageSetupDialogOptions.ixor(QPageSetupDialog::QPageSetupDialogPageSetupDialogOptions other);
KMETHOD QPageSetupDialogPageSetupDialogOptions_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPageSetupDialog::PageSetupDialogOptions *qp = RawPtr_to(QPageSetupDialog::PageSetupDialogOptions*, sfp[0]);
	if (qp != NULL) {
		QPageSetupDialog::PageSetupDialogOptions *other = RawPtr_to(QPageSetupDialog::PageSetupDialogOptions *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QPageSetupDialogPageSetupDialogOptions.testFlag(int flag);
KMETHOD QPageSetupDialogPageSetupDialogOptions_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPageSetupDialog::PageSetupDialogOptions *qp = RawPtr_to(QPageSetupDialog::PageSetupDialogOptions *, sfp[0]);
	if (qp != NULL) {
		QPageSetupDialog::PageSetupDialogOption flag = Int_to(QPageSetupDialog::PageSetupDialogOption, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QPageSetupDialogPageSetupDialogOptions.value();
KMETHOD QPageSetupDialogPageSetupDialogOptions_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QPageSetupDialog::PageSetupDialogOptions *qp = RawPtr_to(QPageSetupDialog::PageSetupDialogOptions *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QPageSetupDialogPageSetupDialogOptions_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QPageSetupDialog::PageSetupDialogOptions *qp = (QPageSetupDialog::PageSetupDialogOptions *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QPageSetupDialogPageSetupDialogOptions_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QPageSetupDialog::PageSetupDialogOptions *qp = (QPageSetupDialog::PageSetupDialogOptions *)p->rawptr;
		(void)qp;
	}
}

static int QPageSetupDialogPageSetupDialogOptions_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QPageSetupDialog::PageSetupDialogOptions*)p1->rawptr);
//		int v2 = int(*(QPageSetupDialog::PageSetupDialogOptions*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QPageSetupDialog::PageSetupDialogOptions v1 = *(QPageSetupDialog::PageSetupDialogOptions*)p1->rawptr;
		QPageSetupDialog::PageSetupDialogOptions v2 = *(QPageSetupDialog::PageSetupDialogOptions*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQPageSetupDialogPageSetupDialogOptions(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPageSetupDialogPageSetupDialogOptions";
	cdef->free = QPageSetupDialogPageSetupDialogOptions_free;
	cdef->reftrace = QPageSetupDialogPageSetupDialogOptions_reftrace;
	cdef->compareTo = QPageSetupDialogPageSetupDialogOptions_compareTo;
}

