//QLine QLine.new();
KMETHOD QLine_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLine *ret_v = new KQLine();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QLine QLine.new(QPoint p1, QPoint p2);
KMETHOD QLine_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPoint  p1 = *RawPtr_to(const QPoint *, sfp[1]);
	const QPoint  p2 = *RawPtr_to(const QPoint *, sfp[2]);
	KQLine *ret_v = new KQLine(p1, p2);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QLine QLine.new(int x1, int y1, int x2, int y2);
KMETHOD QLine_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int x1 = Int_to(int, sfp[1]);
	int y1 = Int_to(int, sfp[2]);
	int x2 = Int_to(int, sfp[3]);
	int y2 = Int_to(int, sfp[4]);
	KQLine *ret_v = new KQLine(x1, y1, x2, y2);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QPoint QLine.getP1();
KMETHOD QLine_getP1(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLine *  qp = RawPtr_to(QLine *, sfp[0]);
	if (qp != NULL) {
		QPoint ret_v = qp->p1();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPoint QLine.getP2();
KMETHOD QLine_getP2(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLine *  qp = RawPtr_to(QLine *, sfp[0]);
	if (qp != NULL) {
		QPoint ret_v = qp->p2();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QLine.x1();
KMETHOD QLine_x1(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLine *  qp = RawPtr_to(QLine *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->x1();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QLine.x2();
KMETHOD QLine_x2(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLine *  qp = RawPtr_to(QLine *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->x2();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QLine.y1();
KMETHOD QLine_y1(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLine *  qp = RawPtr_to(QLine *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->y1();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QLine.y2();
KMETHOD QLine_y2(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLine *  qp = RawPtr_to(QLine *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->y2();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QLine.dx();
KMETHOD QLine_dx(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLine *  qp = RawPtr_to(QLine *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->dx();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QLine.dy();
KMETHOD QLine_dy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLine *  qp = RawPtr_to(QLine *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->dy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

////boolean QLine.isNull();
KMETHOD QLine_isNull(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLine *  qp = RawPtr_to(QLine *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isNull();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QLine.setP1(QPoint p1);
KMETHOD QLine_setP1(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLine *  qp = RawPtr_to(QLine *, sfp[0]);
	if (qp != NULL) {
		const QPoint  p1 = *RawPtr_to(const QPoint *, sfp[1]);
		qp->setP1(p1);
	}
	RETURNvoid_();
}

//void QLine.setP2(QPoint p2);
KMETHOD QLine_setP2(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLine *  qp = RawPtr_to(QLine *, sfp[0]);
	if (qp != NULL) {
		const QPoint  p2 = *RawPtr_to(const QPoint *, sfp[1]);
		qp->setP2(p2);
	}
	RETURNvoid_();
}

//void QLine.setLine(int x1, int y1, int x2, int y2);
KMETHOD QLine_setLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLine *  qp = RawPtr_to(QLine *, sfp[0]);
	if (qp != NULL) {
		int x1 = Int_to(int, sfp[1]);
		int y1 = Int_to(int, sfp[2]);
		int x2 = Int_to(int, sfp[3]);
		int y2 = Int_to(int, sfp[4]);
		qp->setLine(x1, y1, x2, y2);
	}
	RETURNvoid_();
}

//void QLine.setPoints(QPoint p1, QPoint p2);
KMETHOD QLine_setPoints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLine *  qp = RawPtr_to(QLine *, sfp[0]);
	if (qp != NULL) {
		const QPoint  p1 = *RawPtr_to(const QPoint *, sfp[1]);
		const QPoint  p2 = *RawPtr_to(const QPoint *, sfp[2]);
		qp->setPoints(p1, p2);
	}
	RETURNvoid_();
}

//void QLine.translate(QPoint offset);
KMETHOD QLine_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLine *  qp = RawPtr_to(QLine *, sfp[0]);
	if (qp != NULL) {
		const QPoint  offset = *RawPtr_to(const QPoint *, sfp[1]);
		qp->translate(offset);
	}
	RETURNvoid_();
}

/*
//void QLine.translate(int dx, int dy);
KMETHOD QLine_translate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLine *  qp = RawPtr_to(QLine *, sfp[0]);
	if (qp != NULL) {
		int dx = Int_to(int, sfp[1]);
		int dy = Int_to(int, sfp[2]);
		qp->translate(dx, dy);
	}
	RETURNvoid_();
}
*/
//QLine QLine.translated(QPoint offset);
KMETHOD QLine_translated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLine *  qp = RawPtr_to(QLine *, sfp[0]);
	if (qp != NULL) {
		const QPoint  offset = *RawPtr_to(const QPoint *, sfp[1]);
		QLine ret_v = qp->translated(offset);
		QLine *ret_v_ = new QLine(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QLine QLine.translated(int dx, int dy);
KMETHOD QLine_translated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLine *  qp = RawPtr_to(QLine *, sfp[0]);
	if (qp != NULL) {
		int dx = Int_to(int, sfp[1]);
		int dy = Int_to(int, sfp[2]);
		QLine ret_v = qp->translated(dx, dy);
		QLine *ret_v_ = new QLine(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/

DummyQLine::DummyQLine()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQLine::setSelf(knh_RawPtr_t *ptr)
{
	DummyQLine::self = ptr;
}

bool DummyQLine::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQLine::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLine::event_map->bigin();
	if ((itr = DummyQLine::event_map->find(str)) == DummyQLine::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQLine::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLine::slot_map->bigin();
	if ((itr = DummyQLine::slot_map->find(str)) == DummyQLine::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQLine::connection(QObject *o)
{
	return;
}

KQLine::KQLine() : QLine()
{
	self = NULL;
	dummy = new DummyQLine();
	dummy->connection((QObject*)this);
}

KMETHOD QLine_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLine *qp = RawPtr_to(KQLine *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QLine]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLine]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QLine_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLine *qp = RawPtr_to(KQLine *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QLine]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLine]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QLine_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQLine *qp = (KQLine *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QLine_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQLine *qp = (KQLine *)p->rawptr;
		(void)qp;
	}
}

static int QLine_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QLine*>(p1->rawptr) == *static_cast<QLine*>(p2->rawptr) ? 0 : 1);
}

void KQLine::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQLine(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QLine";
	cdef->free = QLine_free;
	cdef->reftrace = QLine_reftrace;
	cdef->compareTo = QLine_compareTo;
}


