//@Virtual @Override boolean QAbstractGraphicsShapeItem.isObscuredBy(QGraphicsItem item);
KMETHOD QAbstractGraphicsShapeItem_isObscuredBy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractGraphicsShapeItem *  qp = RawPtr_to(QAbstractGraphicsShapeItem *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		bool ret_v = qp->isObscuredBy(item);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QPainterPath QAbstractGraphicsShapeItem.opaqueArea();
KMETHOD QAbstractGraphicsShapeItem_opaqueArea(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractGraphicsShapeItem *  qp = RawPtr_to(QAbstractGraphicsShapeItem *, sfp[0]);
	if (qp) {
		QPainterPath ret_v = qp->opaqueArea();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//
//QBrush QAbstractGraphicsShapeItem.getBrush();
KMETHOD QAbstractGraphicsShapeItem_getBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractGraphicsShapeItem *  qp = RawPtr_to(QAbstractGraphicsShapeItem *, sfp[0]);
	if (qp) {
		QBrush ret_v = qp->brush();
		QBrush *ret_v_ = new QBrush(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QPen QAbstractGraphicsShapeItem.getPen();
KMETHOD QAbstractGraphicsShapeItem_getPen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractGraphicsShapeItem *  qp = RawPtr_to(QAbstractGraphicsShapeItem *, sfp[0]);
	if (qp) {
		QPen ret_v = qp->pen();
		QPen *ret_v_ = new QPen(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QAbstractGraphicsShapeItem.setBrush(QBrush brush);
KMETHOD QAbstractGraphicsShapeItem_setBrush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractGraphicsShapeItem *  qp = RawPtr_to(QAbstractGraphicsShapeItem *, sfp[0]);
	if (qp) {
		const QBrush  brush = *RawPtr_to(const QBrush *, sfp[1]);
		qp->setBrush(brush);
	}
	RETURNvoid_();
}

//void QAbstractGraphicsShapeItem.setPen(QPen pen);
KMETHOD QAbstractGraphicsShapeItem_setPen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractGraphicsShapeItem *  qp = RawPtr_to(QAbstractGraphicsShapeItem *, sfp[0]);
	if (qp) {
		const QPen  pen = *RawPtr_to(const QPen *, sfp[1]);
		qp->setPen(pen);
	}
	RETURNvoid_();
}

// //@Virtual void QAbstractGraphicsShapeItem.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
// KMETHOD QAbstractGraphicsShapeItem_paint(CTX ctx, knh_sfp_t *sfp _RIX)
// {
// 	(void)ctx;
// 	KQAbstractGraphicsShapeItem *  qp = RawPtr_to(KQAbstractGraphicsShapeItem *, sfp[0]);
// 	if (qp) {
// 		if (qp->dummy->paint_func != NULL) {
// 			knh_Func_invoke(ctx, qp->dummy->paint_func, sfp, 4);
// 		}
// 	}
// 	RETURNvoid_();
// }

//@Virtual void QAbstractGraphicsShapeItem.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
KMETHOD QAbstractGraphicsShapeItem_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractGraphicsShapeItem *  qp = RawPtr_to(KQAbstractGraphicsShapeItem *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionGraphicsItem*  option = RawPtr_to(const QStyleOptionGraphicsItem*, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->paint(painter, option, widget);
	}
	RETURNvoid_();
}

void KQAbstractGraphicsShapeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
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
	}
}

DummyQAbstractGraphicsShapeItem::DummyQAbstractGraphicsShapeItem()
{
	self = NULL;
	paint_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	event_map->insert(map<string, knh_Func_t *>::value_type("paint", NULL));
}

void DummyQAbstractGraphicsShapeItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractGraphicsShapeItem::self = ptr;
	DummyQGraphicsItem::setSelf(ptr);
}

bool DummyQAbstractGraphicsShapeItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsItem::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractGraphicsShapeItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractGraphicsShapeItem::event_map->bigin();
	if ((itr = DummyQAbstractGraphicsShapeItem::event_map->find(str)) == DummyQAbstractGraphicsShapeItem::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsItem::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		paint_func = (*event_map)["paint"];
		return true;
	}
}

bool DummyQAbstractGraphicsShapeItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractGraphicsShapeItem::slot_map->bigin();
	if ((itr = DummyQAbstractGraphicsShapeItem::slot_map->find(str)) == DummyQAbstractGraphicsShapeItem::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsItem::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQAbstractGraphicsShapeItem::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQAbstractGraphicsShapeItem::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQGraphicsItem::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQAbstractGraphicsShapeItem::connection(QObject *o)
{
	QAbstractGraphicsShapeItem *p = dynamic_cast<QAbstractGraphicsShapeItem*>(o);
	if (p != NULL) {
	}
	DummyQGraphicsItem::connection(o);
}

KQAbstractGraphicsShapeItem::KQAbstractGraphicsShapeItem(QGraphicsItem* parent) : QAbstractGraphicsShapeItem(parent)
{
	self = NULL;
	dummy = new DummyQAbstractGraphicsShapeItem();
}

KMETHOD QAbstractGraphicsShapeItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractGraphicsShapeItem *qp = RawPtr_to(KQAbstractGraphicsShapeItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractGraphicsShapeItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractGraphicsShapeItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAbstractGraphicsShapeItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractGraphicsShapeItem *qp = RawPtr_to(KQAbstractGraphicsShapeItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractGraphicsShapeItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractGraphicsShapeItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractGraphicsShapeItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAbstractGraphicsShapeItem *qp = (KQAbstractGraphicsShapeItem *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAbstractGraphicsShapeItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQAbstractGraphicsShapeItem *qp = (KQAbstractGraphicsShapeItem *)p->rawptr;
//		KQAbstractGraphicsShapeItem *qp = static_cast<KQAbstractGraphicsShapeItem*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAbstractGraphicsShapeItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAbstractGraphicsShapeItem::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQAbstractGraphicsShapeItem::sceneEvent(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QAbstractGraphicsShapeItem::sceneEvent(event);
		return false;
	}
//	QAbstractGraphicsShapeItem::sceneEvent(event);
	return true;
}



DEFAPI(void) defQAbstractGraphicsShapeItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractGraphicsShapeItem";
	cdef->free = QAbstractGraphicsShapeItem_free;
	cdef->reftrace = QAbstractGraphicsShapeItem_reftrace;
	cdef->compareTo = QAbstractGraphicsShapeItem_compareTo;
}


