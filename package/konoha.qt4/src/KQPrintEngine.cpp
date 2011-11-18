//@Virtual boolean QPrintEngine.abort();
KMETHOD QPrintEngine_abort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintEngine *  qp = RawPtr_to(QPrintEngine *, sfp[0]);
	if (qp) {
		bool ret_v = qp->abort();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual int QPrintEngine.metric(int id);
KMETHOD QPrintEngine_metric(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintEngine *  qp = RawPtr_to(QPrintEngine *, sfp[0]);
	if (qp) {
		QPaintDevice::PaintDeviceMetric id = Int_to(QPaintDevice::PaintDeviceMetric, sfp[1]);
		int ret_v = qp->metric(id);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual boolean QPrintEngine.newPage();
KMETHOD QPrintEngine_newPage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintEngine *  qp = RawPtr_to(QPrintEngine *, sfp[0]);
	if (qp) {
		bool ret_v = qp->newPage();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual int QPrintEngine.printerState();
KMETHOD QPrintEngine_printerState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintEngine *  qp = RawPtr_to(QPrintEngine *, sfp[0]);
	if (qp) {
		QPrinter::PrinterState ret_v = qp->printerState();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QVariant QPrintEngine.getProperty(int key);
KMETHOD QPrintEngine_getProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintEngine *  qp = RawPtr_to(QPrintEngine *, sfp[0]);
	if (qp) {
		QPrintEngine::PrintEnginePropertyKey key = Int_to(QPrintEngine::PrintEnginePropertyKey, sfp[1]);
		QVariant ret_v = qp->property(key);
		QVariant *ret_v_ = new QVariant(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QPrintEngine.setProperty(int key, QVariant value);
KMETHOD QPrintEngine_setProperty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintEngine *  qp = RawPtr_to(QPrintEngine *, sfp[0]);
	if (qp) {
		QPrintEngine::PrintEnginePropertyKey key = Int_to(QPrintEngine::PrintEnginePropertyKey, sfp[1]);
		const QVariant  value = *RawPtr_to(const QVariant *, sfp[2]);
		qp->setProperty(key, value);
	}
	RETURNvoid_();
}

//Array<String> QPrintEngine.parents();
KMETHOD QPrintEngine_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPrintEngine *qp = RawPtr_to(QPrintEngine*, sfp[0]);
	if (qp != NULL) {
		int size = 10;
		knh_Array_t *a = new_Array0(ctx, size);
		const knh_ClassTBL_t *ct = sfp[0].p->h.cTBL;
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}

DummyQPrintEngine::DummyQPrintEngine()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQPrintEngine::~DummyQPrintEngine()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQPrintEngine::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPrintEngine::self = ptr;
}

bool DummyQPrintEngine::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQPrintEngine::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPrintEngine::event_map->bigin();
	if ((itr = DummyQPrintEngine::event_map->find(str)) == DummyQPrintEngine::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPrintEngine::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPrintEngine::slot_map->bigin();
	if ((itr = DummyQPrintEngine::slot_map->find(str)) == DummyQPrintEngine::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQPrintEngine::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQPrintEngine::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQPrintEngine::connection(QObject *o)
{
	QPrintEngine *p = dynamic_cast<QPrintEngine*>(o);
	if (p != NULL) {
	}
}

KQPrintEngine::~KQPrintEngine()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QPrintEngine_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPrintEngine *qp = RawPtr_to(KQPrintEngine *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPrintEngine]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPrintEngine]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPrintEngine_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPrintEngine *qp = RawPtr_to(KQPrintEngine *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPrintEngine]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPrintEngine]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPrintEngine_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQPrintEngine *qp = (KQPrintEngine *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QPrintEngine*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QPrintEngine_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQPrintEngine *qp = (KQPrintEngine *)p->rawptr;
		KQPrintEngine *qp = static_cast<KQPrintEngine*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPrintEngine_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQPrintEngine::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QPrintEngineConstInt[] = {
	{"PPK_CollateCopies", QPrintEngine::PPK_CollateCopies},
	{"PPK_ColorMode", QPrintEngine::PPK_ColorMode},
	{"PPK_Creator", QPrintEngine::PPK_Creator},
	{"PPK_Duplex", QPrintEngine::PPK_Duplex},
	{"PPK_DocumentName", QPrintEngine::PPK_DocumentName},
	{"PPK_FontEmbedding", QPrintEngine::PPK_FontEmbedding},
	{"PPK_FullPage", QPrintEngine::PPK_FullPage},
	{"PPK_NumberOfCopies", QPrintEngine::PPK_NumberOfCopies},
	{"PPK_Orientation", QPrintEngine::PPK_Orientation},
	{"PPK_OutputFileName", QPrintEngine::PPK_OutputFileName},
	{"PPK_PageOrder", QPrintEngine::PPK_PageOrder},
	{"PPK_PageRect", QPrintEngine::PPK_PageRect},
	{"PPK_PageSize", QPrintEngine::PPK_PageSize},
	{"PPK_PaperRect", QPrintEngine::PPK_PaperRect},
	{"PPK_PaperSource", QPrintEngine::PPK_PaperSource},
	{"PPK_PaperSources", QPrintEngine::PPK_PaperSources},
	{"PPK_PaperSize", QPrintEngine::PPK_PaperSize},
	{"PPK_PrinterName", QPrintEngine::PPK_PrinterName},
	{"PPK_PrinterProgram", QPrintEngine::PPK_PrinterProgram},
	{"PPK_Resolution", QPrintEngine::PPK_Resolution},
	{"PPK_SelectionOption", QPrintEngine::PPK_SelectionOption},
	{"PPK_SupportedResolutions", QPrintEngine::PPK_SupportedResolutions},
	{"PPK_SuppressSystemPrintStatus", QPrintEngine::PPK_SuppressSystemPrintStatus},
	{"PPK_WindowsPageSize", QPrintEngine::PPK_WindowsPageSize},
	{"PPK_CustomPaperSize", QPrintEngine::PPK_CustomPaperSize},
	{"PPK_PageMargins", QPrintEngine::PPK_PageMargins},
	{"PPK_CopyCount", QPrintEngine::PPK_CopyCount},
	{"PPK_SupportsMultipleCopies", QPrintEngine::PPK_SupportsMultipleCopies},
	{"PPK_CustomBase", QPrintEngine::PPK_CustomBase},
	{NULL, 0}
};

DEFAPI(void) constQPrintEngine(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QPrintEngineConstInt);
}


DEFAPI(void) defQPrintEngine(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPrintEngine";
	cdef->free = QPrintEngine_free;
	cdef->reftrace = QPrintEngine_reftrace;
	cdef->compareTo = QPrintEngine_compareTo;
}


