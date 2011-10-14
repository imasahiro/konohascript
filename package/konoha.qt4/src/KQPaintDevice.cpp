//int QPaintDevice.colorCount();
KMETHOD QPaintDevice_colorCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintDevice *  qp = RawPtr_to(QPaintDevice *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->colorCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual int QPaintDevice.depth();
KMETHOD QPaintDevice_depth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintDevice *  qp = RawPtr_to(QPaintDevice *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->depth();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual int QPaintDevice.height();
KMETHOD QPaintDevice_height(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintDevice *  qp = RawPtr_to(QPaintDevice *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->height();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPaintDevice.heightMM();
KMETHOD QPaintDevice_heightMM(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintDevice *  qp = RawPtr_to(QPaintDevice *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->heightMM();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPaintDevice.logicalDpiX();
KMETHOD QPaintDevice_logicalDpiX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintDevice *  qp = RawPtr_to(QPaintDevice *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->logicalDpiX();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPaintDevice.logicalDpiY();
KMETHOD QPaintDevice_logicalDpiY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintDevice *  qp = RawPtr_to(QPaintDevice *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->logicalDpiY();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPaintDevice.numColors();
KMETHOD QPaintDevice_numColors(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintDevice *  qp = RawPtr_to(QPaintDevice *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->numColors();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QPaintEngine QPaintDevice.paintEngine();
KMETHOD QPaintDevice_paintEngine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintDevice *  qp = RawPtr_to(QPaintDevice *, sfp[0]);
	if (qp != NULL) {
		QPaintEngine* ret_v = qp->paintEngine();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QPaintEngine*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QPaintDevice.paintingActive();
KMETHOD QPaintDevice_paintingActive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintDevice *  qp = RawPtr_to(QPaintDevice *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->paintingActive();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QPaintDevice.physicalDpiX();
KMETHOD QPaintDevice_physicalDpiX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintDevice *  qp = RawPtr_to(QPaintDevice *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->physicalDpiX();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPaintDevice.physicalDpiY();
KMETHOD QPaintDevice_physicalDpiY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintDevice *  qp = RawPtr_to(QPaintDevice *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->physicalDpiY();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual int QPaintDevice.width();
KMETHOD QPaintDevice_width(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintDevice *  qp = RawPtr_to(QPaintDevice *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->width();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPaintDevice.widthMM();
KMETHOD QPaintDevice_widthMM(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPaintDevice *  qp = RawPtr_to(QPaintDevice *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->widthMM();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQPaintDevice::DummyQPaintDevice()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPaintDevice::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPaintDevice::self = ptr;
}

bool DummyQPaintDevice::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQPaintDevice::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPaintDevice::event_map->bigin();
	if ((itr = DummyQPaintDevice::event_map->find(str)) == DummyQPaintDevice::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPaintDevice::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPaintDevice::slot_map->bigin();
	if ((itr = DummyQPaintDevice::slot_map->find(str)) == DummyQPaintDevice::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQPaintDevice::connection(QObject *o)
{
	return;
}

KQPaintDevice::KQPaintDevice() : QPaintDevice()
{
	self = NULL;
	dummy = new DummyQPaintDevice();
	dummy->connection((QObject*)this);
}

KMETHOD QPaintDevice_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPaintDevice *qp = RawPtr_to(KQPaintDevice *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPaintDevice]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPaintDevice]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPaintDevice_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPaintDevice *qp = RawPtr_to(KQPaintDevice *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPaintDevice]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPaintDevice]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPaintDevice_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPaintDevice *qp = (KQPaintDevice *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPaintDevice_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQPaintDevice *qp = (KQPaintDevice *)p->rawptr;
		(void)qp;
	}
}

static int QPaintDevice_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQPaintDevice::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQPaintDevice(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPaintDevice";
	cdef->free = QPaintDevice_free;
	cdef->reftrace = QPaintDevice_reftrace;
	cdef->compareTo = QPaintDevice_compareTo;
}

static knh_IntData_t QPaintDeviceConstInt[] = {
	{"PdmWidth", QPaintDevice::PdmWidth},
	{"PdmHeight", QPaintDevice::PdmHeight},
	{"PdmWidthMM", QPaintDevice::PdmWidthMM},
	{"PdmHeightMM", QPaintDevice::PdmHeightMM},
	{"PdmNumColors", QPaintDevice::PdmNumColors},
	{"PdmDepth", QPaintDevice::PdmDepth},
	{"PdmDpiX", QPaintDevice::PdmDpiX},
	{"PdmDpiY", QPaintDevice::PdmDpiY},
	{"PdmPhysicalDpiX", QPaintDevice::PdmPhysicalDpiX},
	{"PdmPhysicalDpiY", QPaintDevice::PdmPhysicalDpiY},
	{NULL, 0}
};

DEFAPI(void) constQPaintDevice(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QPaintDeviceConstInt);
}

