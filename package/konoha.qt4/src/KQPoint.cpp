//QPoint QPoint.new();
KMETHOD QPoint_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPoint *ret_v = new KQPoint();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPoint QPoint.new(int x, int y);
KMETHOD QPoint_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int x = Int_to(int, sfp[1]);
	int y = Int_to(int, sfp[2]);
	KQPoint *ret_v = new KQPoint(x, y);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
////boolean QPoint.isNull();
KMETHOD QPoint_isNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPoint *  qp = RawPtr_to(QPoint *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isNull();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QPoint.manhattanLength();
KMETHOD QPoint_manhattanLength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPoint *  qp = RawPtr_to(QPoint *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->manhattanLength();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPoint.rx();
KMETHOD QPoint_rx(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPoint *  qp = RawPtr_to(QPoint *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->rx();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPoint.ry();
KMETHOD QPoint_ry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPoint *  qp = RawPtr_to(QPoint *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->ry();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QPoint.setX(int x);
KMETHOD QPoint_setX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPoint *  qp = RawPtr_to(QPoint *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		qp->setX(x);
	}
	RETURNvoid_();
}

//void QPoint.setY(int y);
KMETHOD QPoint_setY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPoint *  qp = RawPtr_to(QPoint *, sfp[0]);
	if (qp != NULL) {
		int y = Int_to(int, sfp[1]);
		qp->setY(y);
	}
	RETURNvoid_();
}

//int QPoint.getX();
KMETHOD QPoint_getX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPoint *  qp = RawPtr_to(QPoint *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->x();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QPoint.getY();
KMETHOD QPoint_getY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPoint *  qp = RawPtr_to(QPoint *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->y();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQPoint::DummyQPoint()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPoint::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPoint::self = ptr;
}

bool DummyQPoint::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQPoint::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPoint::event_map->bigin();
	if ((itr = DummyQPoint::event_map->find(str)) == DummyQPoint::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPoint::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPoint::slot_map->bigin();
	if ((itr = DummyQPoint::slot_map->find(str)) == DummyQPoint::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQPoint::connection(QObject *o)
{
	return;
}

KQPoint::KQPoint() : QPoint()
{
	self = NULL;
	dummy = new DummyQPoint();
	dummy->connection((QObject*)this);
}

KMETHOD QPoint_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPoint *qp = RawPtr_to(KQPoint *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPoint]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPoint]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPoint_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPoint *qp = RawPtr_to(KQPoint *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPoint]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPoint]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPoint_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPoint *qp = (KQPoint *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPoint_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQPoint *qp = (KQPoint *)p->rawptr;
		(void)qp;
	}
}

static int QPoint_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQPoint::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQPoint(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPoint";
	cdef->free = QPoint_free;
	cdef->reftrace = QPoint_reftrace;
	cdef->compareTo = QPoint_compareTo;
}


