//int QGradient.getCoordinateMode();
KMETHOD QGradient_getCoordinateMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGradient *  qp = RawPtr_to(QGradient *, sfp[0]);
	if (qp) {
		QGradient::CoordinateMode ret_v = qp->coordinateMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGradient.setColorAt(float position, QColor color);
KMETHOD QGradient_setColorAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGradient *  qp = RawPtr_to(QGradient *, sfp[0]);
	if (qp) {
		qreal position = Float_to(qreal, sfp[1]);
		const QColor  color = *RawPtr_to(const QColor *, sfp[2]);
		qp->setColorAt(position, color);
	}
	RETURNvoid_();
}

//void QGradient.setCoordinateMode(int mode);
KMETHOD QGradient_setCoordinateMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGradient *  qp = RawPtr_to(QGradient *, sfp[0]);
	if (qp) {
		QGradient::CoordinateMode mode = Int_to(QGradient::CoordinateMode, sfp[1]);
		qp->setCoordinateMode(mode);
	}
	RETURNvoid_();
}

//void QGradient.setSpread(int method);
KMETHOD QGradient_setSpread(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGradient *  qp = RawPtr_to(QGradient *, sfp[0]);
	if (qp) {
		QGradient::Spread method = Int_to(QGradient::Spread, sfp[1]);
		qp->setSpread(method);
	}
	RETURNvoid_();
}

//void QGradient.setStops(QGradientStops stopPoints);
KMETHOD QGradient_setStops(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGradient *  qp = RawPtr_to(QGradient *, sfp[0]);
	if (qp) {
		const QGradientStops  stopPoints = *RawPtr_to(const QGradientStops *, sfp[1]);
		qp->setStops(stopPoints);
	}
	RETURNvoid_();
}

//int QGradient.getSpread();
KMETHOD QGradient_getSpread(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGradient *  qp = RawPtr_to(QGradient *, sfp[0]);
	if (qp) {
		QGradient::Spread ret_v = qp->spread();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QGradientStops QGradient.getStops();
KMETHOD QGradient_getStops(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGradient *  qp = RawPtr_to(QGradient *, sfp[0]);
	if (qp) {
		QGradientStops ret_v = qp->stops();
		QGradientStops *ret_v_ = new QGradientStops(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QGradient.type();
KMETHOD QGradient_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGradient *  qp = RawPtr_to(QGradient *, sfp[0]);
	if (qp) {
		QGradient::Type ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Array<String> QGradient.parents();
KMETHOD QGradient_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGradient *qp = RawPtr_to(QGradient*, sfp[0]);
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

DummyQGradient::DummyQGradient()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQGradient::~DummyQGradient()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQGradient::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGradient::self = ptr;
}

bool DummyQGradient::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQGradient::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGradient::event_map->bigin();
	if ((itr = DummyQGradient::event_map->find(str)) == DummyQGradient::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGradient::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGradient::slot_map->bigin();
	if ((itr = DummyQGradient::slot_map->find(str)) == DummyQGradient::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGradient::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGradient::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQGradient::connection(QObject *o)
{
	QGradient *p = dynamic_cast<QGradient*>(o);
	if (p != NULL) {
	}
}

KQGradient::~KQGradient()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QGradient_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGradient *qp = RawPtr_to(KQGradient *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGradient]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGradient]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGradient_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGradient *qp = RawPtr_to(KQGradient *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGradient]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGradient]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGradient_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQGradient *qp = (KQGradient *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QGradient*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QGradient_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQGradient *qp = (KQGradient *)p->rawptr;
		KQGradient *qp = static_cast<KQGradient*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGradient_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QGradient*>(p1->rawptr) == *static_cast<QGradient*>(p2->rawptr) ? 0 : 1);
}

void KQGradient::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QGradientConstInt[] = {
	{"LogicalMode", QGradient::LogicalMode},
	{"StretchToDeviceMode", QGradient::StretchToDeviceMode},
	{"ObjectBoundingMode", QGradient::ObjectBoundingMode},
	{"PadSpread", QGradient::PadSpread},
	{"RepeatSpread", QGradient::RepeatSpread},
	{"ReflectSpread", QGradient::ReflectSpread},
	{"LinearGradient", QGradient::LinearGradient},
	{"RadialGradient", QGradient::RadialGradient},
	{"ConicalGradient", QGradient::ConicalGradient},
	{"NoGradient", QGradient::NoGradient},
	{NULL, 0}
};

DEFAPI(void) constQGradient(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QGradientConstInt);
}


DEFAPI(void) defQGradient(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGradient";
	cdef->free = QGradient_free;
	cdef->reftrace = QGradient_reftrace;
	cdef->compareTo = QGradient_compareTo;
}


