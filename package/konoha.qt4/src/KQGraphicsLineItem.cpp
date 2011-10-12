//@Virtual @Override QRectF QGraphicsLineItem.boundingRect();
KMETHOD QGraphicsLineItem_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLineItem *  qp = RawPtr_to(QGraphicsLineItem *, sfp[0]);
	if (qp != NULL) {
		QRectF ret_v = qp->boundingRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QGraphicsLineItem.contains(QPointF point);
KMETHOD QGraphicsLineItem_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLineItem *  qp = RawPtr_to(QGraphicsLineItem *, sfp[0]);
	if (qp != NULL) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		bool ret_v = qp->contains(point);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override boolean QGraphicsLineItem.isObscuredBy(QGraphicsItem item);
KMETHOD QGraphicsLineItem_isObscuredBy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLineItem *  qp = RawPtr_to(QGraphicsLineItem *, sfp[0]);
	if (qp != NULL) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		bool ret_v = qp->isObscuredBy(item);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QPainterPath QGraphicsLineItem.opaqueArea();
KMETHOD QGraphicsLineItem_opaqueArea(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLineItem *  qp = RawPtr_to(QGraphicsLineItem *, sfp[0]);
	if (qp != NULL) {
		QPainterPath ret_v = qp->opaqueArea();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QGraphicsLineItem.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
KMETHOD QGraphicsLineItem_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLineItem *  qp = RawPtr_to(QGraphicsLineItem *, sfp[0]);
	if (qp != NULL) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionGraphicsItem*  option = RawPtr_to(const QStyleOptionGraphicsItem*, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->paint(painter, option, widget);
	}
	RETURNvoid_();
}

//@Virtual @Override QPainterPath QGraphicsLineItem.shape();
KMETHOD QGraphicsLineItem_shape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLineItem *  qp = RawPtr_to(QGraphicsLineItem *, sfp[0]);
	if (qp != NULL) {
		QPainterPath ret_v = qp->shape();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QGraphicsLineItem.type();
KMETHOD QGraphicsLineItem_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLineItem *  qp = RawPtr_to(QGraphicsLineItem *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QGraphicsLineItem QGraphicsLineItem.new(QGraphicsItem parent);
KMETHOD QGraphicsLineItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[1]);
	KQGraphicsLineItem *ret_v = new KQGraphicsLineItem(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGraphicsLineItem QGraphicsLineItem.new(QLineF line, QGraphicsItem parent);
KMETHOD QGraphicsLineItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QLineF  line = *RawPtr_to(const QLineF *, sfp[1]);
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[2]);
	KQGraphicsLineItem *ret_v = new KQGraphicsLineItem(line, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QGraphicsLineItem QGraphicsLineItem.new(float x1, float y1, float x2, float y2, QGraphicsItem parent);
KMETHOD QGraphicsLineItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	qreal x1 = Float_to(qreal, sfp[1]);
	qreal y1 = Float_to(qreal, sfp[2]);
	qreal x2 = Float_to(qreal, sfp[3]);
	qreal y2 = Float_to(qreal, sfp[4]);
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[5]);
	KQGraphicsLineItem *ret_v = new KQGraphicsLineItem(x1, y1, x2, y2, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QLineF QGraphicsLineItem.getLine();
KMETHOD QGraphicsLineItem_getLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLineItem *  qp = RawPtr_to(QGraphicsLineItem *, sfp[0]);
	if (qp != NULL) {
		QLineF ret_v = qp->line();
		QLineF *ret_v_ = new QLineF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPen QGraphicsLineItem.getPen();
KMETHOD QGraphicsLineItem_getPen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLineItem *  qp = RawPtr_to(QGraphicsLineItem *, sfp[0]);
	if (qp != NULL) {
		QPen ret_v = qp->pen();
		QPen *ret_v_ = new QPen(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsLineItem.setLine(QLineF line);
KMETHOD QGraphicsLineItem_setLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLineItem *  qp = RawPtr_to(QGraphicsLineItem *, sfp[0]);
	if (qp != NULL) {
		const QLineF  line = *RawPtr_to(const QLineF *, sfp[1]);
		qp->setLine(line);
	}
	RETURNvoid_();
}

/*
//void QGraphicsLineItem.setLine(float x1, float y1, float x2, float y2);
KMETHOD QGraphicsLineItem_setLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLineItem *  qp = RawPtr_to(QGraphicsLineItem *, sfp[0]);
	if (qp != NULL) {
		qreal x1 = Float_to(qreal, sfp[1]);
		qreal y1 = Float_to(qreal, sfp[2]);
		qreal x2 = Float_to(qreal, sfp[3]);
		qreal y2 = Float_to(qreal, sfp[4]);
		qp->setLine(x1, y1, x2, y2);
	}
	RETURNvoid_();
}
*/
//void QGraphicsLineItem.setPen(QPen pen);
KMETHOD QGraphicsLineItem_setPen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLineItem *  qp = RawPtr_to(QGraphicsLineItem *, sfp[0]);
	if (qp != NULL) {
		const QPen  pen = *RawPtr_to(const QPen *, sfp[1]);
		qp->setPen(pen);
	}
	RETURNvoid_();
}


DummyQGraphicsLineItem::DummyQGraphicsLineItem()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGraphicsLineItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsLineItem::self = ptr;
	DummyQGraphicsItem::setSelf(ptr);
}

bool DummyQGraphicsLineItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsItem::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsLineItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsLineItem::event_map->bigin();
	if ((itr = DummyQGraphicsLineItem::event_map->find(str)) == DummyQGraphicsLineItem::event_map->end()) {
		bool ret;
		ret = DummyQGraphicsItem::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsLineItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsLineItem::slot_map->bigin();
	if ((itr = DummyQGraphicsLineItem::event_map->find(str)) == DummyQGraphicsLineItem::slot_map->end()) {
		bool ret;
		ret = DummyQGraphicsItem::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQGraphicsLineItem::KQGraphicsLineItem(QGraphicsItem* parent) : QGraphicsLineItem(parent)
{
	self = NULL;
}

KMETHOD QGraphicsLineItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsLineItem *qp = RawPtr_to(KQGraphicsLineItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsLineItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQGraphicsLineItem::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsLineItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QGraphicsLineItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsLineItem *qp = RawPtr_to(KQGraphicsLineItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsLineItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQGraphicsLineItem::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsLineItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsLineItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsLineItem *qp = (KQGraphicsLineItem *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsLineItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQGraphicsLineItem *qp = (KQGraphicsLineItem *)p->rawptr;
		(void)qp;
	}
}

static int QGraphicsLineItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQGraphicsLineItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsLineItem";
	cdef->free = QGraphicsLineItem_free;
	cdef->reftrace = QGraphicsLineItem_reftrace;
	cdef->compareTo = QGraphicsLineItem_compareTo;
}


