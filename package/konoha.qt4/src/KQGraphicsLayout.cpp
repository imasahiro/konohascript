//@Virtual @Override void QGraphicsLayout.getContentsMargins(float left, float top, float right, float bottom);
KMETHOD QGraphicsLayout_getContentsMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayout *  qp = RawPtr_to(QGraphicsLayout *, sfp[0]);
	if (qp) {
		qreal*  left = RawPtr_to(qreal*, sfp[1]);
		qreal*  top = RawPtr_to(qreal*, sfp[2]);
		qreal*  right = RawPtr_to(qreal*, sfp[3]);
		qreal*  bottom = RawPtr_to(qreal*, sfp[4]);
		qp->getContentsMargins(left, top, right, bottom);
	}
	RETURNvoid_();
}

//@Virtual @Override void QGraphicsLayout.updateGeometry();
KMETHOD QGraphicsLayout_updateGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayout *  qp = RawPtr_to(QGraphicsLayout *, sfp[0]);
	if (qp) {
		qp->updateGeometry();
	}
	RETURNvoid_();
}

//
//void QGraphicsLayout.activate();
KMETHOD QGraphicsLayout_activate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayout *  qp = RawPtr_to(QGraphicsLayout *, sfp[0]);
	if (qp) {
		qp->activate();
	}
	RETURNvoid_();
}

//@Virtual int QGraphicsLayout.count();
KMETHOD QGraphicsLayout_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayout *  qp = RawPtr_to(QGraphicsLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual void QGraphicsLayout.invalidate();
KMETHOD QGraphicsLayout_invalidate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayout *  qp = RawPtr_to(QGraphicsLayout *, sfp[0]);
	if (qp) {
		qp->invalidate();
	}
	RETURNvoid_();
}

//boolean QGraphicsLayout.isActivated();
KMETHOD QGraphicsLayout_isActivated(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayout *  qp = RawPtr_to(QGraphicsLayout *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isActivated();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual QGraphicsLayoutItem QGraphicsLayout.itemAt(int i);
KMETHOD QGraphicsLayout_itemAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayout *  qp = RawPtr_to(QGraphicsLayout *, sfp[0]);
	if (qp) {
		int i = Int_to(int, sfp[1]);
		QGraphicsLayoutItem* ret_v = qp->itemAt(i);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsLayoutItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QGraphicsLayout.removeAt(int index);
KMETHOD QGraphicsLayout_removeAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayout *  qp = RawPtr_to(QGraphicsLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		qp->removeAt(index);
	}
	RETURNvoid_();
}

//void QGraphicsLayout.setContentsMargins(float left, float top, float right, float bottom);
KMETHOD QGraphicsLayout_setContentsMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayout *  qp = RawPtr_to(QGraphicsLayout *, sfp[0]);
	if (qp) {
		qreal left = Float_to(qreal, sfp[1]);
		qreal top = Float_to(qreal, sfp[2]);
		qreal right = Float_to(qreal, sfp[3]);
		qreal bottom = Float_to(qreal, sfp[4]);
		qp->setContentsMargins(left, top, right, bottom);
	}
	RETURNvoid_();
}

//@Virtual void QGraphicsLayout.widgetEvent(QEvent e);
KMETHOD QGraphicsLayout_widgetEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayout *  qp = RawPtr_to(QGraphicsLayout *, sfp[0]);
	if (qp) {
		QEvent*  e = RawPtr_to(QEvent*, sfp[1]);
		qp->widgetEvent(e);
	}
	RETURNvoid_();
}


DummyQGraphicsLayout::DummyQGraphicsLayout()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGraphicsLayout::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsLayout::self = ptr;
	DummyQGraphicsLayoutItem::setSelf(ptr);
}

bool DummyQGraphicsLayout::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsLayoutItem::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsLayout::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsLayout::event_map->bigin();
	if ((itr = DummyQGraphicsLayout::event_map->find(str)) == DummyQGraphicsLayout::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsLayoutItem::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsLayout::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsLayout::slot_map->bigin();
	if ((itr = DummyQGraphicsLayout::slot_map->find(str)) == DummyQGraphicsLayout::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsLayoutItem::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQGraphicsLayout::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQGraphicsLayoutItem::reftrace(ctx, p, tail_);
}

void DummyQGraphicsLayout::connection(QObject *o)
{
	QGraphicsLayout *p = dynamic_cast<QGraphicsLayout*>(o);
	if (p != NULL) {
	}
	DummyQGraphicsLayoutItem::connection(o);
}

KQGraphicsLayout::KQGraphicsLayout(QGraphicsLayoutItem* parent) : QGraphicsLayout(parent)
{
	self = NULL;
	dummy = new DummyQGraphicsLayout();
}

KMETHOD QGraphicsLayout_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsLayout *qp = RawPtr_to(KQGraphicsLayout *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsLayout]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsLayout]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsLayout_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsLayout *qp = RawPtr_to(KQGraphicsLayout *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsLayout]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsLayout]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsLayout_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsLayout *qp = (KQGraphicsLayout *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsLayout_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGraphicsLayout *qp = (KQGraphicsLayout *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsLayout_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsLayout::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQGraphicsLayout(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsLayout";
	cdef->free = QGraphicsLayout_free;
	cdef->reftrace = QGraphicsLayout_reftrace;
	cdef->compareTo = QGraphicsLayout_compareTo;
}


