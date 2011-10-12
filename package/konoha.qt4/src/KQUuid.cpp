//QUuid QUuid.new();
KMETHOD QUuid_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQUuid *ret_v = new KQUuid();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QUuid QUuid.new(int l, int w1, int w2, String b1, String b2, String b3, String b4, String b5, String b6, String b7, String b8);
KMETHOD QUuid_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	uint  l = *RawPtr_to(uint *, sfp[1]);
	ushort  w1 = *RawPtr_to(ushort *, sfp[2]);
	ushort  w2 = *RawPtr_to(ushort *, sfp[3]);
	uchar  b1 = *RawPtr_to(uchar *, sfp[4]);
	uchar  b2 = *RawPtr_to(uchar *, sfp[5]);
	uchar  b3 = *RawPtr_to(uchar *, sfp[6]);
	uchar  b4 = *RawPtr_to(uchar *, sfp[7]);
	uchar  b5 = *RawPtr_to(uchar *, sfp[8]);
	uchar  b6 = *RawPtr_to(uchar *, sfp[9]);
	uchar  b7 = *RawPtr_to(uchar *, sfp[10]);
	uchar  b8 = *RawPtr_to(uchar *, sfp[11]);
	KQUuid *ret_v = new KQUuid(l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QUuid QUuid.new(String text);
KMETHOD QUuid_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString text = String_to(const QString, sfp[1]);
	KQUuid *ret_v = new KQUuid(text);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QUuid QUuid.new(GUID guid);
KMETHOD QUuid_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const GUID  guid = *RawPtr_to(const GUID *, sfp[1]);
	KQUuid *ret_v = new KQUuid(guid);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
////boolean QUuid.isNull();
KMETHOD QUuid_isNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUuid *  qp = RawPtr_to(QUuid *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isNull();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QUuid.toString();
KMETHOD QUuid_toString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUuid *  qp = RawPtr_to(QUuid *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->toString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QUuid.variant();
KMETHOD QUuid_variant(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUuid *  qp = RawPtr_to(QUuid *, sfp[0]);
	if (qp != NULL) {
		QUuid::Variant ret_v = qp->variant();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QUuid.version();
KMETHOD QUuid_version(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUuid *  qp = RawPtr_to(QUuid *, sfp[0]);
	if (qp != NULL) {
		QUuid::Version ret_v = qp->version();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QUuid QUuid.createUuid();
KMETHOD QUuid_createUuid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUuid *  qp = RawPtr_to(QUuid *, sfp[0]);
	if (qp != NULL) {
		QUuid ret_v = qp->createUuid();
		QUuid *ret_v_ = new QUuid(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQUuid::DummyQUuid()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQUuid::setSelf(knh_RawPtr_t *ptr)
{
	DummyQUuid::self = ptr;
}

bool DummyQUuid::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQUuid::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQUuid::event_map->bigin();
	if ((itr = DummyQUuid::event_map->find(str)) == DummyQUuid::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQUuid::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQUuid::slot_map->bigin();
	if ((itr = DummyQUuid::event_map->find(str)) == DummyQUuid::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQUuid::KQUuid() : QUuid()
{
	self = NULL;
}

KMETHOD QUuid_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQUuid *qp = RawPtr_to(KQUuid *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QUuid]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQUuid::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QUuid]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QUuid_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQUuid *qp = RawPtr_to(KQUuid *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QUuid]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQUuid::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QUuid]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QUuid_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQUuid *qp = (KQUuid *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QUuid_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQUuid *qp = (KQUuid *)p->rawptr;
		(void)qp;
	}
}

static int QUuid_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QUuid*>(p1->rawptr) == *static_cast<QUuid*>(p2->rawptr) ? 0 : 1);
}

DEFAPI(void) defQUuid(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QUuid";
	cdef->free = QUuid_free;
	cdef->reftrace = QUuid_reftrace;
	cdef->compareTo = QUuid_compareTo;
}

static knh_IntData_t QUuidConstInt[] = {
	{"VarUnknown", QUuid::VarUnknown},
	{"NCS", QUuid::NCS},
	{"DCE", QUuid::DCE},
	{"Microsoft", QUuid::Microsoft},
	{"Reserved", QUuid::Reserved},
	{"VerUnknown", QUuid::VerUnknown},
	{"Time", QUuid::Time},
	{"EmbeddedPOSIX", QUuid::EmbeddedPOSIX},
	{"Name", QUuid::Name},
	{"Random", QUuid::Random},
	{NULL, 0}
};

DEFAPI(void) constQUuid(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QUuidConstInt);
}

