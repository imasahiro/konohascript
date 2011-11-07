//
//QRectF QGraphicsLayoutItem.contentsRect();
KMETHOD QGraphicsLayoutItem_contentsRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->contentsRect();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSizeF QGraphicsLayoutItem.effectiveSizeHint(int which, QSizeF constraint);
KMETHOD QGraphicsLayoutItem_effectiveSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		Qt::SizeHint which = Int_to(Qt::SizeHint, sfp[1]);
		const QSizeF  constraint = *RawPtr_to(const QSizeF *, sfp[2]);
		QSizeF ret_v = qp->effectiveSizeHint(which, constraint);
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRectF QGraphicsLayoutItem.getGeometry();
KMETHOD QGraphicsLayoutItem_getGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		QRectF ret_v = qp->geometry();
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QGraphicsLayoutItem.getContentsMargins(float left, float top, float right, float bottom);
KMETHOD QGraphicsLayoutItem_getContentsMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		qreal*  left = RawPtr_to(qreal*, sfp[1]);
		qreal*  top = RawPtr_to(qreal*, sfp[2]);
		qreal*  right = RawPtr_to(qreal*, sfp[3]);
		qreal*  bottom = RawPtr_to(qreal*, sfp[4]);
		qp->getContentsMargins(left, top, right, bottom);
	}
	RETURNvoid_();
}

//QGraphicsItem QGraphicsLayoutItem.graphicsItem();
KMETHOD QGraphicsLayoutItem_graphicsItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		QGraphicsItem* ret_v = qp->graphicsItem();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QGraphicsLayoutItem.isLayout();
KMETHOD QGraphicsLayoutItem_isLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isLayout();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//float QGraphicsLayoutItem.getMaximumHeight();
KMETHOD QGraphicsLayoutItem_getMaximumHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->maximumHeight();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QSizeF QGraphicsLayoutItem.getMaximumSize();
KMETHOD QGraphicsLayoutItem_getMaximumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		QSizeF ret_v = qp->maximumSize();
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QGraphicsLayoutItem.getMaximumWidth();
KMETHOD QGraphicsLayoutItem_getMaximumWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->maximumWidth();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//float QGraphicsLayoutItem.getMinimumHeight();
KMETHOD QGraphicsLayoutItem_getMinimumHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->minimumHeight();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QSizeF QGraphicsLayoutItem.getMinimumSize();
KMETHOD QGraphicsLayoutItem_getMinimumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		QSizeF ret_v = qp->minimumSize();
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QGraphicsLayoutItem.getMinimumWidth();
KMETHOD QGraphicsLayoutItem_getMinimumWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->minimumWidth();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//boolean QGraphicsLayoutItem.ownedByLayout();
KMETHOD QGraphicsLayoutItem_ownedByLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->ownedByLayout();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QGraphicsLayoutItem QGraphicsLayoutItem.getParentLayoutItem();
KMETHOD QGraphicsLayoutItem_getParentLayoutItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		QGraphicsLayoutItem* ret_v = qp->parentLayoutItem();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsLayoutItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QGraphicsLayoutItem.getPreferredHeight();
KMETHOD QGraphicsLayoutItem_getPreferredHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->preferredHeight();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//QSizeF QGraphicsLayoutItem.getPreferredSize();
KMETHOD QGraphicsLayoutItem_getPreferredSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		QSizeF ret_v = qp->preferredSize();
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QGraphicsLayoutItem.getPreferredWidth();
KMETHOD QGraphicsLayoutItem_getPreferredWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->preferredWidth();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//@Virtual void QGraphicsLayoutItem.setGeometry(QRectF rect);
KMETHOD QGraphicsLayoutItem_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		qp->setGeometry(rect);
	}
	RETURNvoid_();
}

//void QGraphicsLayoutItem.setMaximumHeight(float height);
KMETHOD QGraphicsLayoutItem_setMaximumHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		qreal height = Float_to(qreal, sfp[1]);
		qp->setMaximumHeight(height);
	}
	RETURNvoid_();
}

//void QGraphicsLayoutItem.setMaximumSize(QSizeF size);
KMETHOD QGraphicsLayoutItem_setMaximumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		const QSizeF  size = *RawPtr_to(const QSizeF *, sfp[1]);
		qp->setMaximumSize(size);
	}
	RETURNvoid_();
}

/*
//void QGraphicsLayoutItem.setMaximumSize(float w, float h);
KMETHOD QGraphicsLayoutItem_setMaximumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		qreal w = Float_to(qreal, sfp[1]);
		qreal h = Float_to(qreal, sfp[2]);
		qp->setMaximumSize(w, h);
	}
	RETURNvoid_();
}
*/
//void QGraphicsLayoutItem.setMaximumWidth(float width);
KMETHOD QGraphicsLayoutItem_setMaximumWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		qreal width = Float_to(qreal, sfp[1]);
		qp->setMaximumWidth(width);
	}
	RETURNvoid_();
}

//void QGraphicsLayoutItem.setMinimumHeight(float height);
KMETHOD QGraphicsLayoutItem_setMinimumHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		qreal height = Float_to(qreal, sfp[1]);
		qp->setMinimumHeight(height);
	}
	RETURNvoid_();
}

//void QGraphicsLayoutItem.setMinimumSize(QSizeF size);
KMETHOD QGraphicsLayoutItem_setMinimumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		const QSizeF  size = *RawPtr_to(const QSizeF *, sfp[1]);
		qp->setMinimumSize(size);
	}
	RETURNvoid_();
}

/*
//void QGraphicsLayoutItem.setMinimumSize(float w, float h);
KMETHOD QGraphicsLayoutItem_setMinimumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		qreal w = Float_to(qreal, sfp[1]);
		qreal h = Float_to(qreal, sfp[2]);
		qp->setMinimumSize(w, h);
	}
	RETURNvoid_();
}
*/
//void QGraphicsLayoutItem.setMinimumWidth(float width);
KMETHOD QGraphicsLayoutItem_setMinimumWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		qreal width = Float_to(qreal, sfp[1]);
		qp->setMinimumWidth(width);
	}
	RETURNvoid_();
}

//void QGraphicsLayoutItem.setParentLayoutItem(QGraphicsLayoutItem parent);
KMETHOD QGraphicsLayoutItem_setParentLayoutItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		QGraphicsLayoutItem*  parent = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
		qp->setParentLayoutItem(parent);
	}
	RETURNvoid_();
}

//void QGraphicsLayoutItem.setPreferredHeight(float height);
KMETHOD QGraphicsLayoutItem_setPreferredHeight(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		qreal height = Float_to(qreal, sfp[1]);
		qp->setPreferredHeight(height);
	}
	RETURNvoid_();
}

//void QGraphicsLayoutItem.setPreferredSize(QSizeF size);
KMETHOD QGraphicsLayoutItem_setPreferredSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		const QSizeF  size = *RawPtr_to(const QSizeF *, sfp[1]);
		qp->setPreferredSize(size);
	}
	RETURNvoid_();
}

/*
//void QGraphicsLayoutItem.setPreferredSize(float w, float h);
KMETHOD QGraphicsLayoutItem_setPreferredSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		qreal w = Float_to(qreal, sfp[1]);
		qreal h = Float_to(qreal, sfp[2]);
		qp->setPreferredSize(w, h);
	}
	RETURNvoid_();
}
*/
//void QGraphicsLayoutItem.setPreferredWidth(float width);
KMETHOD QGraphicsLayoutItem_setPreferredWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		qreal width = Float_to(qreal, sfp[1]);
		qp->setPreferredWidth(width);
	}
	RETURNvoid_();
}

//void QGraphicsLayoutItem.setSizePolicy(QSizePolicy policy);
KMETHOD QGraphicsLayoutItem_setSizePolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		const QSizePolicy  policy = *RawPtr_to(const QSizePolicy *, sfp[1]);
		qp->setSizePolicy(policy);
	}
	RETURNvoid_();
}

/*
//void QGraphicsLayoutItem.setSizePolicy(int hPolicy, int vPolicy, int controlType);
KMETHOD QGraphicsLayoutItem_setSizePolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		QSizePolicy::Policy hPolicy = Int_to(QSizePolicy::Policy, sfp[1]);
		QSizePolicy::Policy vPolicy = Int_to(QSizePolicy::Policy, sfp[2]);
		QSizePolicy::ControlType controlType = Int_to(QSizePolicy::ControlType, sfp[3]);
		qp->setSizePolicy(hPolicy, vPolicy, controlType);
	}
	RETURNvoid_();
}
*/
//QSizePolicy QGraphicsLayoutItem.getSizePolicy();
KMETHOD QGraphicsLayoutItem_getSizePolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		QSizePolicy ret_v = qp->sizePolicy();
		QSizePolicy *ret_v_ = new QSizePolicy(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QGraphicsLayoutItem.updateGeometry();
KMETHOD QGraphicsLayoutItem_updateGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *  qp = RawPtr_to(QGraphicsLayoutItem *, sfp[0]);
	if (qp) {
		qp->updateGeometry();
	}
	RETURNvoid_();
}

//Array<String> QGraphicsLayoutItem.parents();
KMETHOD QGraphicsLayoutItem_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem *qp = RawPtr_to(QGraphicsLayoutItem*, sfp[0]);
	if (qp != NULL) {
		int size = 10;
		knh_Array_t *a = new_Array0(ctx, size);
		const knh_ClassTBL_t *ct = sfp[0].p->h.cTBL;
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}

DummyQGraphicsLayoutItem::DummyQGraphicsLayoutItem()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGraphicsLayoutItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsLayoutItem::self = ptr;
}

bool DummyQGraphicsLayoutItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQGraphicsLayoutItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsLayoutItem::event_map->bigin();
	if ((itr = DummyQGraphicsLayoutItem::event_map->find(str)) == DummyQGraphicsLayoutItem::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsLayoutItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsLayoutItem::slot_map->bigin();
	if ((itr = DummyQGraphicsLayoutItem::slot_map->find(str)) == DummyQGraphicsLayoutItem::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQGraphicsLayoutItem::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQGraphicsLayoutItem::connection(QObject *o)
{
	QGraphicsLayoutItem *p = dynamic_cast<QGraphicsLayoutItem*>(o);
	if (p != NULL) {
	}
}

KQGraphicsLayoutItem::KQGraphicsLayoutItem(QGraphicsLayoutItem* parent, bool isLayout) : QGraphicsLayoutItem(parent, isLayout)
{
	self = NULL;
	dummy = new DummyQGraphicsLayoutItem();
}

KMETHOD QGraphicsLayoutItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsLayoutItem *qp = RawPtr_to(KQGraphicsLayoutItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsLayoutItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsLayoutItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsLayoutItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsLayoutItem *qp = RawPtr_to(KQGraphicsLayoutItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsLayoutItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsLayoutItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsLayoutItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsLayoutItem *qp = (KQGraphicsLayoutItem *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsLayoutItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGraphicsLayoutItem *qp = (KQGraphicsLayoutItem *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsLayoutItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsLayoutItem::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQGraphicsLayoutItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsLayoutItem";
	cdef->free = QGraphicsLayoutItem_free;
	cdef->reftrace = QGraphicsLayoutItem_reftrace;
	cdef->compareTo = QGraphicsLayoutItem_compareTo;
}


