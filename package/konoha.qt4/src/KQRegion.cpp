//QRegion QRegion.new();
KMETHOD QRegion_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRegion *ret_v = new KQRegion();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QRegion QRegion.new(int x, int y, int w, int h, int t);
KMETHOD QRegion_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int x = Int_to(int, sfp[1]);
	int y = Int_to(int, sfp[2]);
	int w = Int_to(int, sfp[3]);
	int h = Int_to(int, sfp[4]);
	QRegion::RegionType t = Int_to(QRegion::RegionType, sfp[5]);
	KQRegion *ret_v = new KQRegion(x, y, w, h, t);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QRegion QRegion.new(QPolygon a, int fillRule);
KMETHOD QRegion_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPolygon  a = *RawPtr_to(const QPolygon *, sfp[1]);
	Qt::FillRule fillRule = Int_to(Qt::FillRule, sfp[2]);
	KQRegion *ret_v = new KQRegion(a, fillRule);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QRegion QRegion.new(QRegion r);
KMETHOD QRegion_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QRegion  r = *RawPtr_to(const QRegion *, sfp[1]);
	KQRegion *ret_v = new KQRegion(r);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QRegion QRegion.new(QBitmap bm);
KMETHOD QRegion_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QBitmap  bm = *RawPtr_to(const QBitmap *, sfp[1]);
	KQRegion *ret_v = new KQRegion(bm);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QRegion QRegion.new(QRect r, int t);
KMETHOD QRegion_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QRect  r = *RawPtr_to(const QRect *, sfp[1]);
	QRegion::RegionType t = Int_to(QRegion::RegionType, sfp[2]);
	KQRegion *ret_v = new KQRegion(r, t);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QRect QRegion.boundingRect();
KMETHOD QRegion_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->boundingRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QRegion.contains(QPoint p);
KMETHOD QRegion_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		const QPoint  p = *RawPtr_to(const QPoint *, sfp[1]);
		bool ret_v = qp->contains(p);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QRegion.contains(QRect r);
KMETHOD QRegion_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		const QRect  r = *RawPtr_to(const QRect *, sfp[1]);
		bool ret_v = qp->contains(r);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//QRegion QRegion.intersected(QRegion r);
KMETHOD QRegion_intersected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		const QRegion  r = *RawPtr_to(const QRegion *, sfp[1]);
		QRegion ret_v = qp->intersected(r);
		QRegion *ret_v_ = new QRegion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRegion QRegion.intersected(QRect rect);
KMETHOD QRegion_intersected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		QRegion ret_v = qp->intersected(rect);
		QRegion *ret_v_ = new QRegion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//boolean QRegion.intersects(QRegion region);
KMETHOD QRegion_intersects(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		const QRegion  region = *RawPtr_to(const QRegion *, sfp[1]);
		bool ret_v = qp->intersects(region);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QRegion.intersects(QRect rect);
KMETHOD QRegion_intersects(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		bool ret_v = qp->intersects(rect);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//boolean QRegion.isEmpty();
KMETHOD QRegion_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QRegion.rectCount();
KMETHOD QRegion_rectCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		int ret_v = qp->rectCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QRegion.setRects(QRect rects, int number);
KMETHOD QRegion_setRects(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		const QRect*  rects = RawPtr_to(const QRect*, sfp[1]);
		int number = Int_to(int, sfp[2]);
		qp->setRects(rects, number);
	}
	RETURNvoid_();
}

//QRegion QRegion.subtracted(QRegion r);
KMETHOD QRegion_subtracted(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		const QRegion  r = *RawPtr_to(const QRegion *, sfp[1]);
		QRegion ret_v = qp->subtracted(r);
		QRegion *ret_v_ = new QRegion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QRegion.translate(int dx, int dy);
KMETHOD QRegion_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		int dx = Int_to(int, sfp[1]);
		int dy = Int_to(int, sfp[2]);
		qp->translate(dx, dy);
	}
	RETURNvoid_();
}

/*
//void QRegion.translate(QPoint point);
KMETHOD QRegion_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		qp->translate(point);
	}
	RETURNvoid_();
}
*/
//QRegion QRegion.translated(int dx, int dy);
KMETHOD QRegion_translated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		int dx = Int_to(int, sfp[1]);
		int dy = Int_to(int, sfp[2]);
		QRegion ret_v = qp->translated(dx, dy);
		QRegion *ret_v_ = new QRegion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRegion QRegion.translated(QPoint p);
KMETHOD QRegion_translated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		const QPoint  p = *RawPtr_to(const QPoint *, sfp[1]);
		QRegion ret_v = qp->translated(p);
		QRegion *ret_v_ = new QRegion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QRegion QRegion.united(QRegion r);
KMETHOD QRegion_united(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		const QRegion  r = *RawPtr_to(const QRegion *, sfp[1]);
		QRegion ret_v = qp->united(r);
		QRegion *ret_v_ = new QRegion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QRegion QRegion.united(QRect rect);
KMETHOD QRegion_united(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		QRegion ret_v = qp->united(rect);
		QRegion *ret_v_ = new QRegion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QRegion QRegion.xored(QRegion r);
KMETHOD QRegion_xored(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *  qp = RawPtr_to(QRegion *, sfp[0]);
	if (qp) {
		const QRegion  r = *RawPtr_to(const QRegion *, sfp[1]);
		QRegion ret_v = qp->xored(r);
		QRegion *ret_v_ = new QRegion(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QRegion.parents();
KMETHOD QRegion_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QRegion *qp = RawPtr_to(QRegion*, sfp[0]);
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

DummyQRegion::DummyQRegion()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQRegion::setSelf(knh_RawPtr_t *ptr)
{
	DummyQRegion::self = ptr;
}

bool DummyQRegion::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQRegion::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRegion::event_map->bigin();
	if ((itr = DummyQRegion::event_map->find(str)) == DummyQRegion::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQRegion::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQRegion::slot_map->bigin();
	if ((itr = DummyQRegion::slot_map->find(str)) == DummyQRegion::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQRegion::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQRegion::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQRegion::connection(QObject *o)
{
	QRegion *p = dynamic_cast<QRegion*>(o);
	if (p != NULL) {
	}
}

KQRegion::KQRegion() : QRegion()
{
	self = NULL;
	dummy = new DummyQRegion();
}

KMETHOD QRegion_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRegion *qp = RawPtr_to(KQRegion *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QRegion]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRegion]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QRegion_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQRegion *qp = RawPtr_to(KQRegion *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QRegion]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QRegion]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QRegion_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQRegion *qp = (KQRegion *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QRegion_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQRegion *qp = (KQRegion *)p->rawptr;
//		KQRegion *qp = static_cast<KQRegion*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QRegion_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QRegion*>(p1->rawptr) == *static_cast<QRegion*>(p2->rawptr) ? 0 : 1);
}

void KQRegion::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QRegionConstInt[] = {
	{"Rectangle", QRegion::Rectangle},
	{"Ellipse", QRegion::Ellipse},
	{NULL, 0}
};

DEFAPI(void) constQRegion(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QRegionConstInt);
}


DEFAPI(void) defQRegion(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QRegion";
	cdef->free = QRegion_free;
	cdef->reftrace = QRegion_reftrace;
	cdef->compareTo = QRegion_compareTo;
}


