//@Virtual @Override QRectF QGraphicsPolygonItem.boundingRect();
KMETHOD QGraphicsPolygonItem_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPolygonItem *  qp = RawPtr_to(QGraphicsPolygonItem *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->boundingRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QGraphicsPolygonItem.contains(QPointF point);
KMETHOD QGraphicsPolygonItem_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPolygonItem *  qp = RawPtr_to(QGraphicsPolygonItem *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		bool ret_v = qp->contains(point);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override boolean QGraphicsPolygonItem.isObscuredBy(QGraphicsItem item);
KMETHOD QGraphicsPolygonItem_isObscuredBy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPolygonItem *  qp = RawPtr_to(QGraphicsPolygonItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		bool ret_v = qp->isObscuredBy(item);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QPainterPath QGraphicsPolygonItem.opaqueArea();
KMETHOD QGraphicsPolygonItem_opaqueArea(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPolygonItem *  qp = RawPtr_to(QGraphicsPolygonItem *, sfp[0]);
	if (qp) {
		QPainterPath ret_v = qp->opaqueArea();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QGraphicsPolygonItem.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
KMETHOD QGraphicsPolygonItem_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPolygonItem *  qp = RawPtr_to(QGraphicsPolygonItem *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionGraphicsItem*  option = RawPtr_to(const QStyleOptionGraphicsItem*, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->paint(painter, option, widget);
	}
	RETURNvoid_();
}

//@Virtual @Override QPainterPath QGraphicsPolygonItem.shape();
KMETHOD QGraphicsPolygonItem_shape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPolygonItem *  qp = RawPtr_to(QGraphicsPolygonItem *, sfp[0]);
	if (qp) {
		QPainterPath ret_v = qp->shape();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QGraphicsPolygonItem.type();
KMETHOD QGraphicsPolygonItem_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPolygonItem *  qp = RawPtr_to(QGraphicsPolygonItem *, sfp[0]);
	if (qp) {
		int ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QGraphicsPolygonItem QGraphicsPolygonItem.new(QGraphicsItem parent);
KMETHOD QGraphicsPolygonItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[1]);
	KQGraphicsPolygonItem *ret_v = new KQGraphicsPolygonItem(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGraphicsPolygonItem QGraphicsPolygonItem.new(QPolygonF polygon, QGraphicsItem parent);
KMETHOD QGraphicsPolygonItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPolygonF  polygon = *RawPtr_to(const QPolygonF *, sfp[1]);
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[2]);
	KQGraphicsPolygonItem *ret_v = new KQGraphicsPolygonItem(polygon, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QGraphicsPolygonItem.getFillRule();
KMETHOD QGraphicsPolygonItem_getFillRule(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPolygonItem *  qp = RawPtr_to(QGraphicsPolygonItem *, sfp[0]);
	if (qp) {
		Qt::FillRule ret_v = qp->fillRule();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QPolygonF QGraphicsPolygonItem.getPolygon();
KMETHOD QGraphicsPolygonItem_getPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPolygonItem *  qp = RawPtr_to(QGraphicsPolygonItem *, sfp[0]);
	if (qp) {
		QPolygonF ret_v = qp->polygon();
		QPolygonF *ret_v_ = new QPolygonF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsPolygonItem.setFillRule(int rule);
KMETHOD QGraphicsPolygonItem_setFillRule(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPolygonItem *  qp = RawPtr_to(QGraphicsPolygonItem *, sfp[0]);
	if (qp) {
		Qt::FillRule rule = Int_to(Qt::FillRule, sfp[1]);
		qp->setFillRule(rule);
	}
	RETURNvoid_();
}

//void QGraphicsPolygonItem.setPolygon(QPolygonF polygon);
KMETHOD QGraphicsPolygonItem_setPolygon(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPolygonItem *  qp = RawPtr_to(QGraphicsPolygonItem *, sfp[0]);
	if (qp) {
		const QPolygonF  polygon = *RawPtr_to(const QPolygonF *, sfp[1]);
		qp->setPolygon(polygon);
	}
	RETURNvoid_();
}


DummyQGraphicsPolygonItem::DummyQGraphicsPolygonItem()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGraphicsPolygonItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsPolygonItem::self = ptr;
	DummyQAbstractGraphicsShapeItem::setSelf(ptr);
}

bool DummyQGraphicsPolygonItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractGraphicsShapeItem::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsPolygonItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsPolygonItem::event_map->bigin();
	if ((itr = DummyQGraphicsPolygonItem::event_map->find(str)) == DummyQGraphicsPolygonItem::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractGraphicsShapeItem::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsPolygonItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsPolygonItem::slot_map->bigin();
	if ((itr = DummyQGraphicsPolygonItem::slot_map->find(str)) == DummyQGraphicsPolygonItem::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractGraphicsShapeItem::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQGraphicsPolygonItem::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQAbstractGraphicsShapeItem::reftrace(ctx, p, tail_);
}

void DummyQGraphicsPolygonItem::connection(QObject *o)
{
	QGraphicsPolygonItem *p = dynamic_cast<QGraphicsPolygonItem*>(o);
	if (p != NULL) {
	}
	DummyQAbstractGraphicsShapeItem::connection(o);
}

KQGraphicsPolygonItem::KQGraphicsPolygonItem(QGraphicsItem* parent) : QGraphicsPolygonItem(parent)
{
	self = NULL;
	dummy = new DummyQGraphicsPolygonItem();
}

KMETHOD QGraphicsPolygonItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsPolygonItem *qp = RawPtr_to(KQGraphicsPolygonItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsPolygonItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsPolygonItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsPolygonItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsPolygonItem *qp = RawPtr_to(KQGraphicsPolygonItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsPolygonItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsPolygonItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsPolygonItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsPolygonItem *qp = (KQGraphicsPolygonItem *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsPolygonItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGraphicsPolygonItem *qp = (KQGraphicsPolygonItem *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsPolygonItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsPolygonItem::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQGraphicsPolygonItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsPolygonItem";
	cdef->free = QGraphicsPolygonItem_free;
	cdef->reftrace = QGraphicsPolygonItem_reftrace;
	cdef->compareTo = QGraphicsPolygonItem_compareTo;
}


