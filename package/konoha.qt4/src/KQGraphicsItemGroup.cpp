//@Virtual @Override QRectF QGraphicsItemGroup.boundingRect();
KMETHOD QGraphicsItemGroup_boundingRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItemGroup *  qp = RawPtr_to(QGraphicsItemGroup *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->boundingRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QGraphicsItemGroup.isObscuredBy(QGraphicsItem item);
KMETHOD QGraphicsItemGroup_isObscuredBy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItemGroup *  qp = RawPtr_to(QGraphicsItemGroup *, sfp[0]);
	if (qp) {
		const QGraphicsItem*  item = RawPtr_to(const QGraphicsItem*, sfp[1]);
		bool ret_v = qp->isObscuredBy(item);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QPainterPath QGraphicsItemGroup.opaqueArea();
KMETHOD QGraphicsItemGroup_opaqueArea(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItemGroup *  qp = RawPtr_to(QGraphicsItemGroup *, sfp[0]);
	if (qp) {
		QPainterPath ret_v = qp->opaqueArea();
		QPainterPath *ret_v_ = new QPainterPath(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QGraphicsItemGroup.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
KMETHOD QGraphicsItemGroup_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItemGroup *  qp = RawPtr_to(QGraphicsItemGroup *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionGraphicsItem*  option = RawPtr_to(const QStyleOptionGraphicsItem*, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->paint(painter, option, widget);
	}
	RETURNvoid_();
}

//@Virtual @Override int QGraphicsItemGroup.type();
KMETHOD QGraphicsItemGroup_type(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItemGroup *  qp = RawPtr_to(QGraphicsItemGroup *, sfp[0]);
	if (qp) {
		int ret_v = qp->type();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QGraphicsItemGroup QGraphicsItemGroup.new(QGraphicsItem parent);
KMETHOD QGraphicsItemGroup_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItem*  parent = RawPtr_to(QGraphicsItem*, sfp[1]);
	KQGraphicsItemGroup *ret_v = new KQGraphicsItemGroup(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QGraphicsItemGroup.addToGroup(QGraphicsItem item);
KMETHOD QGraphicsItemGroup_addToGroup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItemGroup *  qp = RawPtr_to(QGraphicsItemGroup *, sfp[0]);
	if (qp) {
		QGraphicsItem*  item = RawPtr_to(QGraphicsItem*, sfp[1]);
		qp->addToGroup(item);
	}
	RETURNvoid_();
}

//void QGraphicsItemGroup.removeFromGroup(QGraphicsItem item);
KMETHOD QGraphicsItemGroup_removeFromGroup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsItemGroup *  qp = RawPtr_to(QGraphicsItemGroup *, sfp[0]);
	if (qp) {
		QGraphicsItem*  item = RawPtr_to(QGraphicsItem*, sfp[1]);
		qp->removeFromGroup(item);
	}
	RETURNvoid_();
}


DummyQGraphicsItemGroup::DummyQGraphicsItemGroup()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGraphicsItemGroup::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsItemGroup::self = ptr;
	DummyQGraphicsItem::setSelf(ptr);
}

bool DummyQGraphicsItemGroup::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsItem::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsItemGroup::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsItemGroup::event_map->bigin();
	if ((itr = DummyQGraphicsItemGroup::event_map->find(str)) == DummyQGraphicsItemGroup::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsItem::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsItemGroup::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsItemGroup::slot_map->bigin();
	if ((itr = DummyQGraphicsItemGroup::slot_map->find(str)) == DummyQGraphicsItemGroup::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsItem::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQGraphicsItemGroup::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQGraphicsItem::reftrace(ctx, p, tail_);
}

void DummyQGraphicsItemGroup::connection(QObject *o)
{
	QGraphicsItemGroup *p = dynamic_cast<QGraphicsItemGroup*>(o);
	if (p != NULL) {
	}
	DummyQGraphicsItem::connection(o);
}

KQGraphicsItemGroup::KQGraphicsItemGroup(QGraphicsItem* parent) : QGraphicsItemGroup(parent)
{
	self = NULL;
	dummy = new DummyQGraphicsItemGroup();
}

KMETHOD QGraphicsItemGroup_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsItemGroup *qp = RawPtr_to(KQGraphicsItemGroup *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsItemGroup]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsItemGroup]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsItemGroup_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsItemGroup *qp = RawPtr_to(KQGraphicsItemGroup *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsItemGroup]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsItemGroup]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsItemGroup_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsItemGroup *qp = (KQGraphicsItemGroup *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsItemGroup_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGraphicsItemGroup *qp = (KQGraphicsItemGroup *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsItemGroup_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsItemGroup::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQGraphicsItemGroup(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsItemGroup";
	cdef->free = QGraphicsItemGroup_free;
	cdef->reftrace = QGraphicsItemGroup_reftrace;
	cdef->compareTo = QGraphicsItemGroup_compareTo;
}


