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
		((KQGraphicsItemGroup *)qp)->dummy->added_list->append(sfp[1].p);
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
		((KQGraphicsItemGroup *)qp)->dummy->added_list->removeOne(sfp[1].p);
		qp->removeFromGroup(item);
	}
	RETURNvoid_();
}

// //@Virtual void QGraphicsItemGroup.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
// KMETHOD QGraphicsItemGroup_paint(CTX ctx, knh_sfp_t *sfp _RIX)
// {
// 	(void)ctx;
// 	KQGraphicsItemGroup *  qp = RawPtr_to(KQGraphicsItemGroup *, sfp[0]);
// 	if (qp) {
// 		if (qp->dummy->paint_func != NULL) {
// 			knh_Func_invoke(ctx, qp->dummy->paint_func, sfp, 4);
// 		}
// 	}
// 	RETURNvoid_();
// }

//@Virtual void QGraphicsItemGroup.paint(QPainter painter, QStyleOptionGraphicsItem option, QWidget widget);
KMETHOD QGraphicsItemGroup_paint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsItemGroup *  qp = RawPtr_to(KQGraphicsItemGroup *, sfp[0]);
	if (qp) {
		QPainter*  painter = RawPtr_to(QPainter*, sfp[1]);
		const QStyleOptionGraphicsItem*  option = RawPtr_to(const QStyleOptionGraphicsItem*, sfp[2]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[3]);
		qp->paint(painter, option, widget);
	}
	RETURNvoid_();
}

void KQGraphicsItemGroup::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
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
		QGraphicsItemGroup::paint(painter, option, widget);
	}
}

DummyQGraphicsItemGroup::DummyQGraphicsItemGroup()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	paint_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	event_map->insert(map<string, knh_Func_t *>::value_type("paint", NULL));
}
DummyQGraphicsItemGroup::~DummyQGraphicsItemGroup()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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
		paint_func = (*event_map)["paint"];
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

knh_Object_t** DummyQGraphicsItemGroup::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsItemGroup::reftrace p->rawptr=[%p]\n", p->rawptr);
	int length = added_list->length();
	KNH_ENSUREREF(ctx, length);

	for (int i = 0; i < length; i++) {
		knh_RawPtr_t *item = added_list->at(i);
		KNH_ADDNNREF(ctx, item);
	}

	KNH_SIZEREF(ctx);

	tail_ = DummyQGraphicsItem::reftrace(ctx, p, tail_);

	return tail_;
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
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQGraphicsItemGroup();
	dummy->added_list = new QList<knh_RawPtr_t *>();
}

KQGraphicsItemGroup::~KQGraphicsItemGroup()
{
	delete dummy;
	dummy = NULL;
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
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQGraphicsItemGroup *qp = (KQGraphicsItemGroup *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QGraphicsItemGroup*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QGraphicsItemGroup_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQGraphicsItemGroup *qp = (KQGraphicsItemGroup *)p->rawptr;
		KQGraphicsItemGroup *qp = static_cast<KQGraphicsItemGroup*>(p->rawptr);
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

bool KQGraphicsItemGroup::sceneEvent(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGraphicsItemGroup::sceneEvent(event);
		return false;
	}
//	QGraphicsItemGroup::sceneEvent(event);
	return true;
}



DEFAPI(void) defQGraphicsItemGroup(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsItemGroup";
	cdef->free = QGraphicsItemGroup_free;
	cdef->reftrace = QGraphicsItemGroup_reftrace;
	cdef->compareTo = QGraphicsItemGroup_compareTo;
}


