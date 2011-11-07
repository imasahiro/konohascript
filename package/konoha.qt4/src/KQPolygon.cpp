//QPolygon QPolygon.new();
KMETHOD QPolygon_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPolygon *ret_v = new KQPolygon();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPolygon QPolygon.new(int size);
KMETHOD QPolygon_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int size = Int_to(int, sfp[1]);
	KQPolygon *ret_v = new KQPolygon(size);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPolygon QPolygon.new(QPolygon polygon);
KMETHOD QPolygon_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPolygon  polygon = *RawPtr_to(const QPolygon *, sfp[1]);
	KQPolygon *ret_v = new KQPolygon(polygon);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPolygon QPolygon.new(QRect rectangle, boolean closed);
KMETHOD QPolygon_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QRect  rectangle = *RawPtr_to(const QRect *, sfp[1]);
	bool closed = Boolean_to(bool, sfp[2]);
	KQPolygon *ret_v = new KQPolygon(rectangle, closed);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QRect QPolygon.boundingRect();
KMETHOD QPolygon_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygon *  qp = RawPtr_to(QPolygon *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->boundingRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QPolygon.containsPoint(QPoint point, int fillRule);
KMETHOD QPolygon_containsPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygon *  qp = RawPtr_to(QPolygon *, sfp[0]);
	if (qp) {
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
		Qt::FillRule fillRule = Int_to(Qt::FillRule, sfp[2]);
		bool ret_v = qp->containsPoint(point, fillRule);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QPolygon QPolygon.intersected(QPolygon r);
KMETHOD QPolygon_intersected(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygon *  qp = RawPtr_to(QPolygon *, sfp[0]);
	if (qp) {
		const QPolygon  r = *RawPtr_to(const QPolygon *, sfp[1]);
		QPolygon ret_v = qp->intersected(r);
		QPolygon *ret_v_ = new QPolygon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QPolygon.getPoint(int index, int x, int y);
KMETHOD QPolygon_getPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygon *  qp = RawPtr_to(QPolygon *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		int* x = Int_to(int*, sfp[2]);
		int* y = Int_to(int*, sfp[3]);
		qp->point(index, x, y);
	}
	RETURNvoid_();
}

/*
//QPoint QPolygon.getPoint(int index);
KMETHOD QPolygon_getPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygon *  qp = RawPtr_to(QPolygon *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QPoint ret_v = qp->point(index);
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//void QPolygon.putPoints(int index, int nPoints, QPolygon fromPolygon, int fromIndex);
KMETHOD QPolygon_putPoints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygon *  qp = RawPtr_to(QPolygon *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		int nPoints = Int_to(int, sfp[2]);
		const QPolygon  fromPolygon = *RawPtr_to(const QPolygon *, sfp[3]);
		int fromIndex = Int_to(int, sfp[4]);
		qp->putPoints(index, nPoints, fromPolygon, fromIndex);
	}
	RETURNvoid_();
}

//void QPolygon.setPoint(int index, int x, int y);
KMETHOD QPolygon_setPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygon *  qp = RawPtr_to(QPolygon *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		int x = Int_to(int, sfp[2]);
		int y = Int_to(int, sfp[3]);
		qp->setPoint(index, x, y);
	}
	RETURNvoid_();
}

/*
//void QPolygon.setPoint(int index, QPoint point);
KMETHOD QPolygon_setPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygon *  qp = RawPtr_to(QPolygon *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		const QPoint  point = *RawPtr_to(const QPoint *, sfp[2]);
		qp->setPoint(index, point);
	}
	RETURNvoid_();
}
*/
//void QPolygon.setPoints(int nPoints, int points);
KMETHOD QPolygon_setPoints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygon *  qp = RawPtr_to(QPolygon *, sfp[0]);
	if (qp) {
		int nPoints = Int_to(int, sfp[1]);
		const int* points = Int_to(const int*, sfp[2]);
		qp->setPoints(nPoints, points);
	}
	RETURNvoid_();
}

//QPolygon QPolygon.subtracted(QPolygon r);
KMETHOD QPolygon_subtracted(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygon *  qp = RawPtr_to(QPolygon *, sfp[0]);
	if (qp) {
		const QPolygon  r = *RawPtr_to(const QPolygon *, sfp[1]);
		QPolygon ret_v = qp->subtracted(r);
		QPolygon *ret_v_ = new QPolygon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QPolygon.translate(int dx, int dy);
KMETHOD QPolygon_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygon *  qp = RawPtr_to(QPolygon *, sfp[0]);
	if (qp) {
		int dx = Int_to(int, sfp[1]);
		int dy = Int_to(int, sfp[2]);
		qp->translate(dx, dy);
	}
	RETURNvoid_();
}

/*
//void QPolygon.translate(QPoint offset);
KMETHOD QPolygon_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygon *  qp = RawPtr_to(QPolygon *, sfp[0]);
	if (qp) {
		const QPoint  offset = *RawPtr_to(const QPoint *, sfp[1]);
		qp->translate(offset);
	}
	RETURNvoid_();
}
*/
//QPolygon QPolygon.translated(int dx, int dy);
KMETHOD QPolygon_translated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygon *  qp = RawPtr_to(QPolygon *, sfp[0]);
	if (qp) {
		int dx = Int_to(int, sfp[1]);
		int dy = Int_to(int, sfp[2]);
		QPolygon ret_v = qp->translated(dx, dy);
		QPolygon *ret_v_ = new QPolygon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QPolygon QPolygon.translated(QPoint offset);
KMETHOD QPolygon_translated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygon *  qp = RawPtr_to(QPolygon *, sfp[0]);
	if (qp) {
		const QPoint  offset = *RawPtr_to(const QPoint *, sfp[1]);
		QPolygon ret_v = qp->translated(offset);
		QPolygon *ret_v_ = new QPolygon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QPolygon QPolygon.united(QPolygon r);
KMETHOD QPolygon_united(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPolygon *  qp = RawPtr_to(QPolygon *, sfp[0]);
	if (qp) {
		const QPolygon  r = *RawPtr_to(const QPolygon *, sfp[1]);
		QPolygon ret_v = qp->united(r);
		QPolygon *ret_v_ = new QPolygon(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQPolygon::DummyQPolygon()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPolygon::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPolygon::self = ptr;
	DummyQVector::setSelf(ptr);
}

bool DummyQPolygon::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQVector::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQPolygon::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPolygon::event_map->bigin();
	if ((itr = DummyQPolygon::event_map->find(str)) == DummyQPolygon::event_map->end()) {
		bool ret = false;
		ret = DummyQVector::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPolygon::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPolygon::slot_map->bigin();
	if ((itr = DummyQPolygon::slot_map->find(str)) == DummyQPolygon::slot_map->end()) {
		bool ret = false;
		ret = DummyQVector::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQPolygon::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQVector::reftrace(ctx, p, tail_);
}

void DummyQPolygon::connection(QObject *o)
{
	QPolygon *p = dynamic_cast<QPolygon*>(o);
	if (p != NULL) {
	}
	DummyQVector::connection(o);
}

KQPolygon::KQPolygon() : QPolygon()
{
	self = NULL;
	dummy = new DummyQPolygon();
}

KMETHOD QPolygon_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPolygon *qp = RawPtr_to(KQPolygon *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPolygon]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPolygon]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPolygon_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPolygon *qp = RawPtr_to(KQPolygon *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPolygon]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPolygon]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPolygon_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPolygon *qp = (KQPolygon *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPolygon_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQPolygon *qp = (KQPolygon *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPolygon_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQPolygon::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQPolygon(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPolygon";
	cdef->free = QPolygon_free;
	cdef->reftrace = QPolygon_reftrace;
	cdef->compareTo = QPolygon_compareTo;
}


