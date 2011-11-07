//@Virtual @Override QRectF QGraphicsPixmapItem.boundingRect();
KMETHOD QGraphicsPixmapItem_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPixmapItem *  qp = RawPtr_to(QGraphicsPixmapItem *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->boundingRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QGraphicsPixmapItem.contains(QPointF point);
KMETHOD QGraphicsPixmapItem_contains(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPixmapItem *  qp = RawPtr_to(QGraphicsPixmapItem *, sfp[0]);
	if (qp) {
		const QPointF  point = *RawPtr_to(const QPointF *, sfp[1]);
		bool ret_v = qp->contains(point);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override boolean QGraphicsPixmapItem.isObscuredBy(QGraphicsItem item);
KMETHOD QGraphicsPixmapItem_isObscuredBy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPixmapItem *  qp = RawPtr_to(QGraphicsPixmapItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		bool ret_v = qp->isObscuredBy(item);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QPainterPath QGraphicsPixmapItem.opaqueArea();
KMETHOD QGraphicsPixmapItem_opaqueArea(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPixmapItem *  qp = RawPtr_to(QGraphicsPixmapItem *, sfp[0]);
	if (qp) {
		QPainterPath ret_v = qp->opaqueArea();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QGraphicsPixmapItem.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
KMETHOD QGraphicsPixmapItem_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPixmapItem *  qp = RawPtr_to(QGraphicsPixmapItem *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionGraphicsItem*  option = RawPtr_to(const QStyleOptionGraphicsItem*, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->paint(painter, option, widget);
	}
	RETURNvoid_();
}

//@Virtual @Override QPainterPath QGraphicsPixmapItem.shape();
KMETHOD QGraphicsPixmapItem_shape(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPixmapItem *  qp = RawPtr_to(QGraphicsPixmapItem *, sfp[0]);
	if (qp) {
		QPainterPath ret_v = qp->shape();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QGraphicsPixmapItem.type();
KMETHOD QGraphicsPixmapItem_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPixmapItem *  qp = RawPtr_to(QGraphicsPixmapItem *, sfp[0]);
	if (qp) {
		int ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QGraphicsPixmapItem QGraphicsPixmapItem.new(QGraphicsItem parent);
KMETHOD QGraphicsPixmapItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[1]);
	KQGraphicsPixmapItem *ret_v = new KQGraphicsPixmapItem(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGraphicsPixmapItem QGraphicsPixmapItem.new(QPixmap pixmap, QGraphicsItem parent);
KMETHOD QGraphicsPixmapItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[2]);
	KQGraphicsPixmapItem *ret_v = new KQGraphicsPixmapItem(pixmap, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QPointF QGraphicsPixmapItem.offset();
KMETHOD QGraphicsPixmapItem_offset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPixmapItem *  qp = RawPtr_to(QGraphicsPixmapItem *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->offset();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPixmap QGraphicsPixmapItem.getPixmap();
KMETHOD QGraphicsPixmapItem_getPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPixmapItem *  qp = RawPtr_to(QGraphicsPixmapItem *, sfp[0]);
	if (qp) {
		QPixmap ret_v = qp->pixmap();
		QPixmap *ret_v_ = new QPixmap(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsPixmapItem.setOffset(QPointF offset);
KMETHOD QGraphicsPixmapItem_setOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPixmapItem *  qp = RawPtr_to(QGraphicsPixmapItem *, sfp[0]);
	if (qp) {
		const QPointF  offset = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setOffset(offset);
	}
	RETURNvoid_();
}

/*
//void QGraphicsPixmapItem.setOffset(float x, float y);
KMETHOD QGraphicsPixmapItem_setOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPixmapItem *  qp = RawPtr_to(QGraphicsPixmapItem *, sfp[0]);
	if (qp) {
		qreal x = Float_to(qreal, sfp[1]);
		qreal y = Float_to(qreal, sfp[2]);
		qp->setOffset(x, y);
	}
	RETURNvoid_();
}
*/
//void QGraphicsPixmapItem.setPixmap(QPixmap pixmap);
KMETHOD QGraphicsPixmapItem_setPixmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPixmapItem *  qp = RawPtr_to(QGraphicsPixmapItem *, sfp[0]);
	if (qp) {
		const QPixmap  pixmap = *RawPtr_to(const QPixmap *, sfp[1]);
		qp->setPixmap(pixmap);
	}
	RETURNvoid_();
}

//void QGraphicsPixmapItem.setShapeMode(int mode);
KMETHOD QGraphicsPixmapItem_setShapeMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPixmapItem *  qp = RawPtr_to(QGraphicsPixmapItem *, sfp[0]);
	if (qp) {
		QGraphicsPixmapItem::ShapeMode mode = Int_to(QGraphicsPixmapItem::ShapeMode, sfp[1]);
		qp->setShapeMode(mode);
	}
	RETURNvoid_();
}

//void QGraphicsPixmapItem.setTransformationMode(int mode);
KMETHOD QGraphicsPixmapItem_setTransformationMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPixmapItem *  qp = RawPtr_to(QGraphicsPixmapItem *, sfp[0]);
	if (qp) {
		Qt::TransformationMode mode = Int_to(Qt::TransformationMode, sfp[1]);
		qp->setTransformationMode(mode);
	}
	RETURNvoid_();
}

//int QGraphicsPixmapItem.getShapeMode();
KMETHOD QGraphicsPixmapItem_getShapeMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPixmapItem *  qp = RawPtr_to(QGraphicsPixmapItem *, sfp[0]);
	if (qp) {
		QGraphicsPixmapItem::ShapeMode ret_v = qp->shapeMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QGraphicsPixmapItem.getTransformationMode();
KMETHOD QGraphicsPixmapItem_getTransformationMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsPixmapItem *  qp = RawPtr_to(QGraphicsPixmapItem *, sfp[0]);
	if (qp) {
		Qt::TransformationMode ret_v = qp->transformationMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQGraphicsPixmapItem::DummyQGraphicsPixmapItem()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGraphicsPixmapItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsPixmapItem::self = ptr;
	DummyQGraphicsItem::setSelf(ptr);
}

bool DummyQGraphicsPixmapItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsItem::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsPixmapItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsPixmapItem::event_map->bigin();
	if ((itr = DummyQGraphicsPixmapItem::event_map->find(str)) == DummyQGraphicsPixmapItem::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsItem::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsPixmapItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsPixmapItem::slot_map->bigin();
	if ((itr = DummyQGraphicsPixmapItem::slot_map->find(str)) == DummyQGraphicsPixmapItem::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsItem::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQGraphicsPixmapItem::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQGraphicsItem::reftrace(ctx, p, tail_);
}

void DummyQGraphicsPixmapItem::connection(QObject *o)
{
	QGraphicsPixmapItem *p = dynamic_cast<QGraphicsPixmapItem*>(o);
	if (p != NULL) {
	}
	DummyQGraphicsItem::connection(o);
}

KQGraphicsPixmapItem::KQGraphicsPixmapItem(QGraphicsItem* parent) : QGraphicsPixmapItem(parent)
{
	self = NULL;
	dummy = new DummyQGraphicsPixmapItem();
}

KMETHOD QGraphicsPixmapItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsPixmapItem *qp = RawPtr_to(KQGraphicsPixmapItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsPixmapItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsPixmapItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsPixmapItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsPixmapItem *qp = RawPtr_to(KQGraphicsPixmapItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsPixmapItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsPixmapItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsPixmapItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsPixmapItem *qp = (KQGraphicsPixmapItem *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsPixmapItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGraphicsPixmapItem *qp = (KQGraphicsPixmapItem *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsPixmapItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsPixmapItem::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QGraphicsPixmapItemConstInt[] = {
	{"MaskShape", QGraphicsPixmapItem::MaskShape},
	{"BoundingRectShape", QGraphicsPixmapItem::BoundingRectShape},
	{"HeuristicMaskShape", QGraphicsPixmapItem::HeuristicMaskShape},
	{NULL, 0}
};

DEFAPI(void) constQGraphicsPixmapItem(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QGraphicsPixmapItemConstInt);
}


DEFAPI(void) defQGraphicsPixmapItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsPixmapItem";
	cdef->free = QGraphicsPixmapItem_free;
	cdef->reftrace = QGraphicsPixmapItem_reftrace;
	cdef->compareTo = QGraphicsPixmapItem_compareTo;
}


