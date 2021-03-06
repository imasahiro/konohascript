//QTabletEvent QTabletEvent.new(int type, QPoint pos, QPoint globalPos, QPointF hiResGlobalPos, int device, int pointerType, float pressure, int xTilt, int yTilt, float tangentialPressure, float rotation, int z, QtKeyboardModifiers keyState, int uniqueID);
KMETHOD QTabletEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent::Type type = Int_to(QTabletEvent::Type, sfp[1]);
	const QPoint  pos = *RawPtr_to(const QPoint *, sfp[2]);
	const QPoint  globalPos = *RawPtr_to(const QPoint *, sfp[3]);
	const QPointF  hiResGlobalPos = *RawPtr_to(const QPointF *, sfp[4]);
	int device = Int_to(int, sfp[5]);
	int pointerType = Int_to(int, sfp[6]);
	qreal pressure = Float_to(qreal, sfp[7]);
	int xTilt = Int_to(int, sfp[8]);
	int yTilt = Int_to(int, sfp[9]);
	qreal tangentialPressure = Float_to(qreal, sfp[10]);
	qreal rotation = Float_to(qreal, sfp[11]);
	int z = Int_to(int, sfp[12]);
	initFlag(keyState, Qt::KeyboardModifiers, sfp[13]);
	qint64 uniqueID = Int_to(qint64, sfp[14]);
	KQTabletEvent *ret_v = new KQTabletEvent(type, pos, globalPos, hiResGlobalPos, device, pointerType, pressure, xTilt, yTilt, tangentialPressure, rotation, z, keyState, uniqueID);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QTabletEvent.device();
KMETHOD QTabletEvent_device(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		QTabletEvent::TabletDevice ret_v = qp->device();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPoint QTabletEvent.globalPos();
KMETHOD QTabletEvent_globalPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		const QPoint ret_v = qp->globalPos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTabletEvent.globalX();
KMETHOD QTabletEvent_globalX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->globalX();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTabletEvent.globalY();
KMETHOD QTabletEvent_globalY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->globalY();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPointF QTabletEvent.hiResGlobalPos();
KMETHOD QTabletEvent_hiResGlobalPos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		const QPointF ret_v = qp->hiResGlobalPos();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QTabletEvent.hiResGlobalX();
KMETHOD QTabletEvent_hiResGlobalX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->hiResGlobalX();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTabletEvent.hiResGlobalY();
KMETHOD QTabletEvent_hiResGlobalY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->hiResGlobalY();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QTabletEvent.pointerType();
KMETHOD QTabletEvent_pointerType(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		QTabletEvent::PointerType ret_v = qp->pointerType();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPoint QTabletEvent.pos();
KMETHOD QTabletEvent_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		const QPoint ret_v = qp->pos();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QTabletEvent.pressure();
KMETHOD QTabletEvent_pressure(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->pressure();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTabletEvent.rotation();
KMETHOD QTabletEvent_rotation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->rotation();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QTabletEvent.tangentialPressure();
KMETHOD QTabletEvent_tangentialPressure(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->tangentialPressure();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QTabletEvent.uniqueId();
KMETHOD QTabletEvent_uniqueId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->uniqueId();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTabletEvent.x();
KMETHOD QTabletEvent_x(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->x();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTabletEvent.xTilt();
KMETHOD QTabletEvent_xTilt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->xTilt();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTabletEvent.y();
KMETHOD QTabletEvent_y(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->y();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTabletEvent.yTilt();
KMETHOD QTabletEvent_yTilt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->yTilt();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTabletEvent.z();
KMETHOD QTabletEvent_z(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTabletEvent *  qp = RawPtr_to(QTabletEvent *, sfp[0]);
	if (qp) {
		int ret_v = qp->z();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQTabletEvent::DummyQTabletEvent()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQTabletEvent::~DummyQTabletEvent()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQTabletEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTabletEvent::self = ptr;
	DummyQInputEvent::setSelf(ptr);
}

bool DummyQTabletEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQInputEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTabletEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTabletEvent::event_map->bigin();
	if ((itr = DummyQTabletEvent::event_map->find(str)) == DummyQTabletEvent::event_map->end()) {
		bool ret = false;
		ret = DummyQInputEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTabletEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTabletEvent::slot_map->bigin();
	if ((itr = DummyQTabletEvent::slot_map->find(str)) == DummyQTabletEvent::slot_map->end()) {
		bool ret = false;
		ret = DummyQInputEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTabletEvent::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTabletEvent::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQInputEvent::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQTabletEvent::connection(QObject *o)
{
	QTabletEvent *p = dynamic_cast<QTabletEvent*>(o);
	if (p != NULL) {
	}
	DummyQInputEvent::connection(o);
}

KQTabletEvent::KQTabletEvent(QTabletEvent::Type type, const QPoint pos, const QPoint globalPos, const QPointF hiResGlobalPos, int device, int pointerType, qreal pressure, int xTilt, int yTilt, qreal tangentialPressure, qreal rotation, int z, Qt::KeyboardModifiers keyState, qint64 uniqueID) : QTabletEvent(type, pos, globalPos, hiResGlobalPos, device, pointerType, pressure, xTilt, yTilt, tangentialPressure, rotation, z, keyState, uniqueID)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQTabletEvent();
}

KQTabletEvent::~KQTabletEvent()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QTabletEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTabletEvent *qp = RawPtr_to(KQTabletEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTabletEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTabletEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTabletEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTabletEvent *qp = RawPtr_to(KQTabletEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTabletEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTabletEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTabletEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQTabletEvent *qp = (KQTabletEvent *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QTabletEvent*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QTabletEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQTabletEvent *qp = (KQTabletEvent *)p->rawptr;
		KQTabletEvent *qp = static_cast<KQTabletEvent*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTabletEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTabletEvent::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QTabletEventConstInt[] = {
	{"UnknownPointer", QTabletEvent::UnknownPointer},
	{"Pen", QTabletEvent::Pen},
	{"Cursor", QTabletEvent::Cursor},
	{"Eraser", QTabletEvent::Eraser},
	{"NoDevice", QTabletEvent::NoDevice},
	{"Puck", QTabletEvent::Puck},
	{"Stylus", QTabletEvent::Stylus},
	{"Airbrush", QTabletEvent::Airbrush},
	{"FourDMouse", QTabletEvent::FourDMouse},
	{"RotationStylus", QTabletEvent::RotationStylus},
	{NULL, 0}
};

DEFAPI(void) constQTabletEvent(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QTabletEventConstInt);
}


DEFAPI(void) defQTabletEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTabletEvent";
	cdef->free = QTabletEvent_free;
	cdef->reftrace = QTabletEvent_reftrace;
	cdef->compareTo = QTabletEvent_compareTo;
}


