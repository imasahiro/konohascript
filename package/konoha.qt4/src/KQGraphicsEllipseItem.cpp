//@Virtual @Override QRectF QGraphicsEllipseItem.boundingRect();
KMETHOD QGraphicsEllipseItem_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEllipseItem *  qp = RawPtr_to(QGraphicsEllipseItem *, sfp[0]);
	if (qp != NULL) {
		QRectF ret_v = qp->boundingRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QGraphicsEllipseItem.contains(QPointF point);
KMETHOD QGraphicsEllipseItem_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEllipseItem *  qp = RawPtr_to(QGraphicsEllipseItem *, sfp[0]);
	if (qp != NULL) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		bool ret_v = qp->contains(point);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override boolean QGraphicsEllipseItem.isObscuredBy(QGraphicsItem item);
KMETHOD QGraphicsEllipseItem_isObscuredBy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEllipseItem *  qp = RawPtr_to(QGraphicsEllipseItem *, sfp[0]);
	if (qp != NULL) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		bool ret_v = qp->isObscuredBy(item);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QPainterPath QGraphicsEllipseItem.opaqueArea();
KMETHOD QGraphicsEllipseItem_opaqueArea(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEllipseItem *  qp = RawPtr_to(QGraphicsEllipseItem *, sfp[0]);
	if (qp != NULL) {
		QPainterPath ret_v = qp->opaqueArea();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QGraphicsEllipseItem.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
KMETHOD QGraphicsEllipseItem_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEllipseItem *  qp = RawPtr_to(QGraphicsEllipseItem *, sfp[0]);
	if (qp != NULL) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionGraphicsItem*  option = RawPtr_to(const QStyleOptionGraphicsItem*, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->paint(painter, option, widget);
	}
	RETURNvoid_();
}

//@Virtual @Override QPainterPath QGraphicsEllipseItem.shape();
KMETHOD QGraphicsEllipseItem_shape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEllipseItem *  qp = RawPtr_to(QGraphicsEllipseItem *, sfp[0]);
	if (qp != NULL) {
		QPainterPath ret_v = qp->shape();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QGraphicsEllipseItem.type();
KMETHOD QGraphicsEllipseItem_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEllipseItem *  qp = RawPtr_to(QGraphicsEllipseItem *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QGraphicsEllipseItem QGraphicsEllipseItem.new(QGraphicsItem parent);
KMETHOD QGraphicsEllipseItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[1]);
	KQGraphicsEllipseItem *ret_v = new KQGraphicsEllipseItem(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGraphicsEllipseItem QGraphicsEllipseItem.new(QRectF rect, QGraphicsItem parent);
KMETHOD QGraphicsEllipseItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[2]);
	KQGraphicsEllipseItem *ret_v = new KQGraphicsEllipseItem(rect, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QGraphicsEllipseItem QGraphicsEllipseItem.new(float x, float y, float width, float height, QGraphicsItem parent);
KMETHOD QGraphicsEllipseItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	qreal x = Float_to(qreal, sfp[1]);
	qreal y = Float_to(qreal, sfp[2]);
	qreal width = Float_to(qreal, sfp[3]);
	qreal height = Float_to(qreal, sfp[4]);
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[5]);
	KQGraphicsEllipseItem *ret_v = new KQGraphicsEllipseItem(x, y, width, height, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QRectF QGraphicsEllipseItem.getRect();
KMETHOD QGraphicsEllipseItem_getRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEllipseItem *  qp = RawPtr_to(QGraphicsEllipseItem *, sfp[0]);
	if (qp != NULL) {
		QRectF ret_v = qp->rect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsEllipseItem.setRect(QRectF rect);
KMETHOD QGraphicsEllipseItem_setRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEllipseItem *  qp = RawPtr_to(QGraphicsEllipseItem *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		qp->setRect(rect);
	}
	RETURNvoid_();
}

/*
//void QGraphicsEllipseItem.setRect(float x, float y, float width, float height);
KMETHOD QGraphicsEllipseItem_setRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEllipseItem *  qp = RawPtr_to(QGraphicsEllipseItem *, sfp[0]);
	if (qp != NULL) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal width = Float_to(qreal, sfp[3]);
		qreal height = Float_to(qreal, sfp[4]);
		qp->setRect(x, y, width, height);
	}
	RETURNvoid_();
}
*/
//void QGraphicsEllipseItem.setSpanAngle(int angle);
KMETHOD QGraphicsEllipseItem_setSpanAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEllipseItem *  qp = RawPtr_to(QGraphicsEllipseItem *, sfp[0]);
	if (qp != NULL) {
		int angle = Int_to(int, sfp[1]);
		qp->setSpanAngle(angle);
	}
	RETURNvoid_();
}

//void QGraphicsEllipseItem.setStartAngle(int angle);
KMETHOD QGraphicsEllipseItem_setStartAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEllipseItem *  qp = RawPtr_to(QGraphicsEllipseItem *, sfp[0]);
	if (qp != NULL) {
		int angle = Int_to(int, sfp[1]);
		qp->setStartAngle(angle);
	}
	RETURNvoid_();
}

//int QGraphicsEllipseItem.getSpanAngle();
KMETHOD QGraphicsEllipseItem_getSpanAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEllipseItem *  qp = RawPtr_to(QGraphicsEllipseItem *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->spanAngle();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QGraphicsEllipseItem.getStartAngle();
KMETHOD QGraphicsEllipseItem_getStartAngle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsEllipseItem *  qp = RawPtr_to(QGraphicsEllipseItem *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->startAngle();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQGraphicsEllipseItem::DummyQGraphicsEllipseItem()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGraphicsEllipseItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsEllipseItem::self = ptr;
	DummyQAbstractGraphicsShapeItem::setSelf(ptr);
}

bool DummyQGraphicsEllipseItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractGraphicsShapeItem::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsEllipseItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsEllipseItem::event_map->bigin();
	if ((itr = DummyQGraphicsEllipseItem::event_map->find(str)) == DummyQGraphicsEllipseItem::event_map->end()) {
		bool ret;
		ret = DummyQAbstractGraphicsShapeItem::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsEllipseItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsEllipseItem::slot_map->bigin();
	if ((itr = DummyQGraphicsEllipseItem::event_map->find(str)) == DummyQGraphicsEllipseItem::slot_map->end()) {
		bool ret;
		ret = DummyQAbstractGraphicsShapeItem::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQGraphicsEllipseItem::KQGraphicsEllipseItem(QGraphicsItem* parent) : QGraphicsEllipseItem(parent)
{
	self = NULL;
}

KMETHOD QGraphicsEllipseItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsEllipseItem *qp = RawPtr_to(KQGraphicsEllipseItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsEllipseItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQGraphicsEllipseItem::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsEllipseItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QGraphicsEllipseItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsEllipseItem *qp = RawPtr_to(KQGraphicsEllipseItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsEllipseItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQGraphicsEllipseItem::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsEllipseItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsEllipseItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsEllipseItem *qp = (KQGraphicsEllipseItem *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsEllipseItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQGraphicsEllipseItem *qp = (KQGraphicsEllipseItem *)p->rawptr;
		(void)qp;
	}
}

static int QGraphicsEllipseItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQGraphicsEllipseItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsEllipseItem";
	cdef->free = QGraphicsEllipseItem_free;
	cdef->reftrace = QGraphicsEllipseItem_reftrace;
	cdef->compareTo = QGraphicsEllipseItem_compareTo;
}


