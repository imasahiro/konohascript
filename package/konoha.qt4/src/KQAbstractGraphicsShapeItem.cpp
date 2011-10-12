//@Virtual @Override boolean QAbstractGraphicsShapeItem.isObscuredBy(QGraphicsItem item);
KMETHOD QAbstractGraphicsShapeItem_isObscuredBy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractGraphicsShapeItem *  qp = RawPtr_to(QAbstractGraphicsShapeItem *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		const QPen  pen = *RawPtr_to(const QPen *, sfp[1]);
		qp->setPen(pen);
	}
	RETURNvoid_();
}


DummyQAbstractGraphicsShapeItem::DummyQAbstractGraphicsShapeItem()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
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
		bool ret;
		ret = DummyQGraphicsItem::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractGraphicsShapeItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractGraphicsShapeItem::slot_map->bigin();
	if ((itr = DummyQAbstractGraphicsShapeItem::event_map->find(str)) == DummyQAbstractGraphicsShapeItem::slot_map->end()) {
		bool ret;
		ret = DummyQGraphicsItem::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQAbstractGraphicsShapeItem::KQAbstractGraphicsShapeItem(QGraphicsItem* parent) : QAbstractGraphicsShapeItem(parent)
{
	self = NULL;
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
		if (!qp->DummyQAbstractGraphicsShapeItem::addEvent(callback_func, str)) {
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
		if (!qp->DummyQAbstractGraphicsShapeItem::signalConnect(callback_func, str)) {
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
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQAbstractGraphicsShapeItem *qp = (KQAbstractGraphicsShapeItem *)p->rawptr;
		(void)qp;
	}
}

static int QAbstractGraphicsShapeItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQAbstractGraphicsShapeItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractGraphicsShapeItem";
	cdef->free = QAbstractGraphicsShapeItem_free;
	cdef->reftrace = QAbstractGraphicsShapeItem_reftrace;
	cdef->compareTo = QAbstractGraphicsShapeItem_compareTo;
}


