//@Virtual @Override int QGraphicsAnchorLayout.count();
KMETHOD QGraphicsAnchorLayout_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchorLayout *  qp = RawPtr_to(QGraphicsAnchorLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override void QGraphicsAnchorLayout.invalidate();
KMETHOD QGraphicsAnchorLayout_invalidate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchorLayout *  qp = RawPtr_to(QGraphicsAnchorLayout *, sfp[0]);
	if (qp) {
		qp->invalidate();
	}
	RETURNvoid_();
}

//@Virtual @Override QGraphicsLayoutItem QGraphicsAnchorLayout.itemAt(int index);
KMETHOD QGraphicsAnchorLayout_itemAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchorLayout *  qp = RawPtr_to(QGraphicsAnchorLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QGraphicsLayoutItem* ret_v = qp->itemAt(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsLayoutItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QGraphicsAnchorLayout.removeAt(int index);
KMETHOD QGraphicsAnchorLayout_removeAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchorLayout *  qp = RawPtr_to(QGraphicsAnchorLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		qp->removeAt(index);
	}
	RETURNvoid_();
}

//@Virtual @Override void QGraphicsAnchorLayout.setGeometry(QRectF geom);
KMETHOD QGraphicsAnchorLayout_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchorLayout *  qp = RawPtr_to(QGraphicsAnchorLayout *, sfp[0]);
	if (qp) {
		const QRectF  geom = *RawPtr_to(const QRectF *, sfp[1]);
		qp->setGeometry(geom);
	}
	RETURNvoid_();
}

//QGraphicsAnchorLayout QGraphicsAnchorLayout.new(QGraphicsLayoutItem parent);
KMETHOD QGraphicsAnchorLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem*  parent = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
	KQGraphicsAnchorLayout *ret_v = new KQGraphicsAnchorLayout(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QGraphicsAnchor QGraphicsAnchorLayout.addAnchor(QGraphicsLayoutItem firstItem, int firstEdge, QGraphicsLayoutItem secondItem, int secondEdge);
KMETHOD QGraphicsAnchorLayout_addAnchor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchorLayout *  qp = RawPtr_to(QGraphicsAnchorLayout *, sfp[0]);
	if (qp) {
		QGraphicsLayoutItem*  firstItem = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
		Qt::AnchorPoint firstEdge = Int_to(Qt::AnchorPoint, sfp[2]);
		QGraphicsLayoutItem*  secondItem = RawPtr_to(QGraphicsLayoutItem*, sfp[3]);
		Qt::AnchorPoint secondEdge = Int_to(Qt::AnchorPoint, sfp[4]);
		QGraphicsAnchor* ret_v = qp->addAnchor(firstItem, firstEdge, secondItem, secondEdge);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsAnchor*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsAnchorLayout.addAnchors(QGraphicsLayoutItem firstItem, QGraphicsLayoutItem secondItem, QtOrientations orientations);
KMETHOD QGraphicsAnchorLayout_addAnchors(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchorLayout *  qp = RawPtr_to(QGraphicsAnchorLayout *, sfp[0]);
	if (qp) {
		QGraphicsLayoutItem*  firstItem = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
		QGraphicsLayoutItem*  secondItem = RawPtr_to(QGraphicsLayoutItem*, sfp[2]);
		initFlag(orientations, Qt::Orientations, sfp[3]);
		qp->addAnchors(firstItem, secondItem, orientations);
	}
	RETURNvoid_();
}

//void QGraphicsAnchorLayout.addCornerAnchors(QGraphicsLayoutItem firstItem, int firstCorner, QGraphicsLayoutItem secondItem, int secondCorner);
KMETHOD QGraphicsAnchorLayout_addCornerAnchors(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchorLayout *  qp = RawPtr_to(QGraphicsAnchorLayout *, sfp[0]);
	if (qp) {
		QGraphicsLayoutItem*  firstItem = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
		Qt::Corner firstCorner = Int_to(Qt::Corner, sfp[2]);
		QGraphicsLayoutItem*  secondItem = RawPtr_to(QGraphicsLayoutItem*, sfp[3]);
		Qt::Corner secondCorner = Int_to(Qt::Corner, sfp[4]);
		qp->addCornerAnchors(firstItem, firstCorner, secondItem, secondCorner);
	}
	RETURNvoid_();
}

//QGraphicsAnchor QGraphicsAnchorLayout.anchor(QGraphicsLayoutItem firstItem, int firstEdge, QGraphicsLayoutItem secondItem, int secondEdge);
KMETHOD QGraphicsAnchorLayout_anchor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchorLayout *  qp = RawPtr_to(QGraphicsAnchorLayout *, sfp[0]);
	if (qp) {
		QGraphicsLayoutItem*  firstItem = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
		Qt::AnchorPoint firstEdge = Int_to(Qt::AnchorPoint, sfp[2]);
		QGraphicsLayoutItem*  secondItem = RawPtr_to(QGraphicsLayoutItem*, sfp[3]);
		Qt::AnchorPoint secondEdge = Int_to(Qt::AnchorPoint, sfp[4]);
		QGraphicsAnchor* ret_v = qp->anchor(firstItem, firstEdge, secondItem, secondEdge);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsAnchor*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QGraphicsAnchorLayout.getHorizontalSpacing();
KMETHOD QGraphicsAnchorLayout_getHorizontalSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchorLayout *  qp = RawPtr_to(QGraphicsAnchorLayout *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->horizontalSpacing();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QGraphicsAnchorLayout.setHorizontalSpacing(float spacing);
KMETHOD QGraphicsAnchorLayout_setHorizontalSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchorLayout *  qp = RawPtr_to(QGraphicsAnchorLayout *, sfp[0]);
	if (qp) {
		qreal spacing = Float_to(qreal, sfp[1]);
		qp->setHorizontalSpacing(spacing);
	}
	RETURNvoid_();
}

//void QGraphicsAnchorLayout.setSpacing(float spacing);
KMETHOD QGraphicsAnchorLayout_setSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchorLayout *  qp = RawPtr_to(QGraphicsAnchorLayout *, sfp[0]);
	if (qp) {
		qreal spacing = Float_to(qreal, sfp[1]);
		qp->setSpacing(spacing);
	}
	RETURNvoid_();
}

//void QGraphicsAnchorLayout.setVerticalSpacing(float spacing);
KMETHOD QGraphicsAnchorLayout_setVerticalSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchorLayout *  qp = RawPtr_to(QGraphicsAnchorLayout *, sfp[0]);
	if (qp) {
		qreal spacing = Float_to(qreal, sfp[1]);
		qp->setVerticalSpacing(spacing);
	}
	RETURNvoid_();
}

//float QGraphicsAnchorLayout.getVerticalSpacing();
KMETHOD QGraphicsAnchorLayout_getVerticalSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchorLayout *  qp = RawPtr_to(QGraphicsAnchorLayout *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->verticalSpacing();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}


DummyQGraphicsAnchorLayout::DummyQGraphicsAnchorLayout()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGraphicsAnchorLayout::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsAnchorLayout::self = ptr;
	DummyQGraphicsLayout::setSelf(ptr);
}

bool DummyQGraphicsAnchorLayout::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsLayout::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsAnchorLayout::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsAnchorLayout::event_map->bigin();
	if ((itr = DummyQGraphicsAnchorLayout::event_map->find(str)) == DummyQGraphicsAnchorLayout::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsLayout::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsAnchorLayout::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsAnchorLayout::slot_map->bigin();
	if ((itr = DummyQGraphicsAnchorLayout::slot_map->find(str)) == DummyQGraphicsAnchorLayout::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsLayout::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQGraphicsAnchorLayout::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQGraphicsLayout::reftrace(ctx, p, tail_);
}

void DummyQGraphicsAnchorLayout::connection(QObject *o)
{
	QGraphicsAnchorLayout *p = dynamic_cast<QGraphicsAnchorLayout*>(o);
	if (p != NULL) {
	}
	DummyQGraphicsLayout::connection(o);
}

KQGraphicsAnchorLayout::KQGraphicsAnchorLayout(QGraphicsLayoutItem* parent) : QGraphicsAnchorLayout(parent)
{
	self = NULL;
	dummy = new DummyQGraphicsAnchorLayout();
}

KMETHOD QGraphicsAnchorLayout_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsAnchorLayout *qp = RawPtr_to(KQGraphicsAnchorLayout *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsAnchorLayout]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsAnchorLayout]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsAnchorLayout_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsAnchorLayout *qp = RawPtr_to(KQGraphicsAnchorLayout *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsAnchorLayout]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsAnchorLayout]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsAnchorLayout_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsAnchorLayout *qp = (KQGraphicsAnchorLayout *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsAnchorLayout_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGraphicsAnchorLayout *qp = (KQGraphicsAnchorLayout *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsAnchorLayout_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsAnchorLayout::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQGraphicsAnchorLayout(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsAnchorLayout";
	cdef->free = QGraphicsAnchorLayout_free;
	cdef->reftrace = QGraphicsAnchorLayout_reftrace;
	cdef->compareTo = QGraphicsAnchorLayout_compareTo;
}


