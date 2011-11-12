//@Virtual @Override QRectF QGraphicsRectItem.boundingRect();
KMETHOD QGraphicsRectItem_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsRectItem *  qp = RawPtr_to(QGraphicsRectItem *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->boundingRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QGraphicsRectItem.contains(QPointF point);
KMETHOD QGraphicsRectItem_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsRectItem *  qp = RawPtr_to(QGraphicsRectItem *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		bool ret_v = qp->contains(point);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override boolean QGraphicsRectItem.isObscuredBy(QGraphicsItem item);
KMETHOD QGraphicsRectItem_isObscuredBy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsRectItem *  qp = RawPtr_to(QGraphicsRectItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		bool ret_v = qp->isObscuredBy(item);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QPainterPath QGraphicsRectItem.opaqueArea();
KMETHOD QGraphicsRectItem_opaqueArea(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsRectItem *  qp = RawPtr_to(QGraphicsRectItem *, sfp[0]);
	if (qp) {
		QPainterPath ret_v = qp->opaqueArea();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QPainterPath QGraphicsRectItem.shape();
KMETHOD QGraphicsRectItem_shape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsRectItem *  qp = RawPtr_to(QGraphicsRectItem *, sfp[0]);
	if (qp) {
		QPainterPath ret_v = qp->shape();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QGraphicsRectItem.type();
KMETHOD QGraphicsRectItem_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsRectItem *  qp = RawPtr_to(QGraphicsRectItem *, sfp[0]);
	if (qp) {
		int ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QGraphicsRectItem QGraphicsRectItem.new(QGraphicsItem parent);
KMETHOD QGraphicsRectItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[1]);
	KQGraphicsRectItem *ret_v = new KQGraphicsRectItem(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGraphicsRectItem QGraphicsRectItem.new(QRectF rect, QGraphicsItem parent);
KMETHOD QGraphicsRectItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[2]);
	KQGraphicsRectItem *ret_v = new KQGraphicsRectItem(rect, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QGraphicsRectItem QGraphicsRectItem.new(float x, float y, float width, float height, QGraphicsItem parent);
KMETHOD QGraphicsRectItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	qreal x = Float_to(qreal, sfp[1]);
	qreal y = Float_to(qreal, sfp[2]);
	qreal width = Float_to(qreal, sfp[3]);
	qreal height = Float_to(qreal, sfp[4]);
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[5]);
	KQGraphicsRectItem *ret_v = new KQGraphicsRectItem(x, y, width, height, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QRectF QGraphicsRectItem.getRect();
KMETHOD QGraphicsRectItem_getRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsRectItem *  qp = RawPtr_to(QGraphicsRectItem *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->rect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsRectItem.setRect(QRectF rectangle);
KMETHOD QGraphicsRectItem_setRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsRectItem *  qp = RawPtr_to(QGraphicsRectItem *, sfp[0]);
	if (qp) {
		const QRectF  rectangle = *RawPtr_to(const QRectF *, sfp[1]);
		qp->setRect(rectangle);
	}
	RETURNvoid_();
}

/*
//void QGraphicsRectItem.setRect(float x, float y, float width, float height);
KMETHOD QGraphicsRectItem_setRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsRectItem *  qp = RawPtr_to(QGraphicsRectItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qreal width = Float_to(qreal, sfp[3]);
		qreal height = Float_to(qreal, sfp[4]);
		qp->setRect(x, y, width, height);
	}
	RETURNvoid_();
}
*/
// //@Virtual void QGraphicsRectItem.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
// KMETHOD QGraphicsRectItem_paint(CTX ctx, knh_sfp_t *sfp _RIX)
// {
// 	(void)ctx;
// 	KQGraphicsRectItem *  qp = RawPtr_to(KQGraphicsRectItem *, sfp[0]);
// 	if (qp) {
// 		if (qp->dummy->paint_func != NULL) {
// 			knh_Func_invoke(ctx, qp->dummy->paint_func, sfp, 4);
// 		}
// 	}
// 	RETURNvoid_();
// }

//@Virtual void QGraphicsRectItem.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
KMETHOD QGraphicsRectItem_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsRectItem *  qp = RawPtr_to(KQGraphicsRectItem *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionGraphicsItem*  option = RawPtr_to(const QStyleOptionGraphicsItem*, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->paint(painter, option, widget);
	}
	RETURNvoid_();
}

void KQGraphicsRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	if (dummy->paint_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QPainter, painter);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_RawPtr_t *p2 = new_QRawPtr(lctx, QStyleOptionGraphicsItem, option);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		knh_RawPtr_t *p3 = new_QRawPtr(lctx, QWidget, widget);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+4].o, UPCAST(p3));
		knh_Func_invoke(lctx, dummy->paint_func, lsfp, 4);
	} else {
		QGraphicsRectItem::paint(painter, option, widget);
	}
}

DummyQGraphicsRectItem::DummyQGraphicsRectItem()
{
	self = NULL;
	paint_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	event_map->insert(map<string, knh_Func_t *>::value_type("paint", NULL));
}

void DummyQGraphicsRectItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsRectItem::self = ptr;
	DummyQAbstractGraphicsShapeItem::setSelf(ptr);
}

bool DummyQGraphicsRectItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractGraphicsShapeItem::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsRectItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsRectItem::event_map->bigin();
	if ((itr = DummyQGraphicsRectItem::event_map->find(str)) == DummyQGraphicsRectItem::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractGraphicsShapeItem::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		paint_func = (*event_map)["paint"];
		return true;
	}
}

bool DummyQGraphicsRectItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsRectItem::slot_map->bigin();
	if ((itr = DummyQGraphicsRectItem::slot_map->find(str)) == DummyQGraphicsRectItem::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractGraphicsShapeItem::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGraphicsRectItem::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsRectItem::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQAbstractGraphicsShapeItem::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGraphicsRectItem::connection(QObject *o)
{
	QGraphicsRectItem *p = dynamic_cast<QGraphicsRectItem*>(o);
	if (p != NULL) {
	}
	DummyQAbstractGraphicsShapeItem::connection(o);
}

KQGraphicsRectItem::KQGraphicsRectItem(QGraphicsItem* parent) : QGraphicsRectItem(parent)
{
	self = NULL;
	dummy = new DummyQGraphicsRectItem();
}

KMETHOD QGraphicsRectItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsRectItem *qp = RawPtr_to(KQGraphicsRectItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsRectItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsRectItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsRectItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsRectItem *qp = RawPtr_to(KQGraphicsRectItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsRectItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsRectItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsRectItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsRectItem *qp = (KQGraphicsRectItem *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsRectItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGraphicsRectItem *qp = (KQGraphicsRectItem *)p->rawptr;
//		KQGraphicsRectItem *qp = static_cast<KQGraphicsRectItem*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsRectItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsRectItem::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGraphicsRectItem::sceneEvent(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGraphicsRectItem::sceneEvent(event);
		return false;
	}
//	QGraphicsRectItem::sceneEvent(event);
	return true;
}



DEFAPI(void) defQGraphicsRectItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsRectItem";
	cdef->free = QGraphicsRectItem_free;
	cdef->reftrace = QGraphicsRectItem_reftrace;
	cdef->compareTo = QGraphicsRectItem_compareTo;
}


