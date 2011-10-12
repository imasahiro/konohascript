//QPrinterInfo QPrinterInfo.new();
KMETHOD QPrinterInfo_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPrinterInfo *ret_v = new KQPrinterInfo();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPrinterInfo QPrinterInfo.new(QPrinterInfo src);
KMETHOD QPrinterInfo_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPrinterInfo  src = *RawPtr_to(const QPrinterInfo *, sfp[1]);
	KQPrinterInfo *ret_v = new KQPrinterInfo(src);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPrinterInfo QPrinterInfo.new(QPrinter printer);
KMETHOD QPrinterInfo_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPrinter  printer = *RawPtr_to(const QPrinter *, sfp[1]);
	KQPrinterInfo *ret_v = new KQPrinterInfo(printer);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QPrinterInfo.isDefault();
KMETHOD QPrinterInfo_isDefault(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinterInfo *  qp = RawPtr_to(QPrinterInfo *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isDefault();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

////boolean QPrinterInfo.isNull();
KMETHOD QPrinterInfo_isNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinterInfo *  qp = RawPtr_to(QPrinterInfo *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isNull();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QPrinterInfo.printerName();
KMETHOD QPrinterInfo_printerName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinterInfo *  qp = RawPtr_to(QPrinterInfo *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->printerName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<int> QPrinterInfo.supportedPaperSizes();
KMETHOD QPrinterInfo_supportedPaperSizes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinterInfo *  qp = RawPtr_to(QPrinterInfo *, sfp[0]);
	if (qp != NULL) {
		QList<QPrinter::PaperSize>ret_v = qp->supportedPaperSizes();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QPrinter::PaperSize"));
		for (int n = 0; n < list_size; n++) {
			QPrinter::PaperSize *ret_v_ = new QPrinter::PaperSize(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//Array<QPrinterInfo> QPrinterInfo.availablePrinters();
KMETHOD QPrinterInfo_availablePrinters(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinterInfo *  qp = RawPtr_to(QPrinterInfo *, sfp[0]);
	if (qp != NULL) {
		QList<QPrinterInfo>ret_v = qp->availablePrinters();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QPrinterInfo"));
		for (int n = 0; n < list_size; n++) {
			QPrinterInfo *ret_v_ = new QPrinterInfo(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QPrinterInfo QPrinterInfo.defaultPrinter();
KMETHOD QPrinterInfo_defaultPrinter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrinterInfo *  qp = RawPtr_to(QPrinterInfo *, sfp[0]);
	if (qp != NULL) {
		QPrinterInfo ret_v = qp->defaultPrinter();
		QPrinterInfo *ret_v_ = new QPrinterInfo(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQPrinterInfo::DummyQPrinterInfo()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPrinterInfo::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPrinterInfo::self = ptr;
}

bool DummyQPrinterInfo::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQPrinterInfo::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPrinterInfo::event_map->bigin();
	if ((itr = DummyQPrinterInfo::event_map->find(str)) == DummyQPrinterInfo::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPrinterInfo::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPrinterInfo::slot_map->bigin();
	if ((itr = DummyQPrinterInfo::event_map->find(str)) == DummyQPrinterInfo::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQPrinterInfo::KQPrinterInfo() : QPrinterInfo()
{
	self = NULL;
}

KMETHOD QPrinterInfo_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPrinterInfo *qp = RawPtr_to(KQPrinterInfo *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPrinterInfo]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQPrinterInfo::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPrinterInfo]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QPrinterInfo_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPrinterInfo *qp = RawPtr_to(KQPrinterInfo *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPrinterInfo]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQPrinterInfo::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPrinterInfo]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPrinterInfo_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPrinterInfo *qp = (KQPrinterInfo *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPrinterInfo_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQPrinterInfo *qp = (KQPrinterInfo *)p->rawptr;
		(void)qp;
	}
}

static int QPrinterInfo_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQPrinterInfo(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPrinterInfo";
	cdef->free = QPrinterInfo_free;
	cdef->reftrace = QPrinterInfo_reftrace;
	cdef->compareTo = QPrinterInfo_compareTo;
}


