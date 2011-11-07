//QPointF QPointF.new();
KMETHOD QPointF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPointF *ret_v = new KQPointF();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QPointF QPointF.new(QPoint point);
KMETHOD QPointF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPoint  point = *RawPtr_to(const QPoint *, sfp[1]);
	KQPointF *ret_v = new KQPointF(point);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QPointF QPointF.new(float x, float y);
KMETHOD QPointF_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	qreal x = Float_to(qreal, sfp[1]);
	qreal y = Float_to(qreal, sfp[2]);
	KQPointF *ret_v = new KQPointF(x, y);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//float QPointF.manhattanLength();
KMETHOD QPointF_manhattanLength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPointF *  qp = RawPtr_to(QPointF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->manhattanLength();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QPointF.rx();
KMETHOD QPointF_rx(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPointF *  qp = RawPtr_to(QPointF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->rx();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QPointF.ry();
KMETHOD QPointF_ry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPointF *  qp = RawPtr_to(QPointF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->ry();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QPointF.setX(float x);
KMETHOD QPointF_setX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPointF *  qp = RawPtr_to(QPointF *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qp->setX(x);
	}
	RETURNvoid_();
}

//void QPointF.setY(float y);
KMETHOD QPointF_setY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPointF *  qp = RawPtr_to(QPointF *, sfp[0]);
	if (qp) {
		qreal y = Float_to(qreal, sfp[1]);
		qp->setY(y);
	}
	RETURNvoid_();
}

//QPoint QPointF.toPoint();
KMETHOD QPointF_toPoint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPointF *  qp = RawPtr_to(QPointF *, sfp[0]);
	if (qp) {
		QPoint ret_v = qp->toPoint();
		QPoint *ret_v_ = new QPoint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QPointF.getX();
KMETHOD QPointF_getX(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPointF *  qp = RawPtr_to(QPointF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->x();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QPointF.getY();
KMETHOD QPointF_getY(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPointF *  qp = RawPtr_to(QPointF *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->y();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//Array<String> QPointF.parents();
KMETHOD QPointF_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QPointF *qp = RawPtr_to(QPointF*, sfp[0]);
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

DummyQPointF::DummyQPointF()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQPointF::setSelf(knh_RawPtr_t *ptr)
{
	DummyQPointF::self = ptr;
}

bool DummyQPointF::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQPointF::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPointF::event_map->bigin();
	if ((itr = DummyQPointF::event_map->find(str)) == DummyQPointF::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQPointF::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQPointF::slot_map->bigin();
	if ((itr = DummyQPointF::slot_map->find(str)) == DummyQPointF::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQPointF::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQPointF::connection(QObject *o)
{
	QPointF *p = dynamic_cast<QPointF*>(o);
	if (p != NULL) {
	}
}

KQPointF::KQPointF() : QPointF()
{
	self = NULL;
	dummy = new DummyQPointF();
}

KMETHOD QPointF_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPointF *qp = RawPtr_to(KQPointF *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QPointF]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPointF]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QPointF_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQPointF *qp = RawPtr_to(KQPointF *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QPointF]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QPointF]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QPointF_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQPointF *qp = (KQPointF *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QPointF_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQPointF *qp = (KQPointF *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QPointF_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QPointF*>(p1->rawptr) == *static_cast<QPointF*>(p2->rawptr) ? 0 : 1);
}

void KQPointF::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQPointF(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QPointF";
	cdef->free = QPointF_free;
	cdef->reftrace = QPointF_reftrace;
	cdef->compareTo = QPointF_compareTo;
}


