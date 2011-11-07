//@Virtual @Override int QGraphicsLinearLayout.count();
KMETHOD QGraphicsLinearLayout_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override void QGraphicsLinearLayout.invalidate();
KMETHOD QGraphicsLinearLayout_invalidate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		qp->invalidate();
	}
	RETURNvoid_();
}

//@Virtual @Override QGraphicsLayoutItem QGraphicsLinearLayout.itemAt(int index);
KMETHOD QGraphicsLinearLayout_itemAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QGraphicsLayoutItem* ret_v = qp->itemAt(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QGraphicsLayoutItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QGraphicsLinearLayout.removeAt(int index);
KMETHOD QGraphicsLinearLayout_removeAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		qp->removeAt(index);
	}
	RETURNvoid_();
}

//@Virtual @Override void QGraphicsLinearLayout.setGeometry(QRectF rect);
KMETHOD QGraphicsLinearLayout_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		qp->setGeometry(rect);
	}
	RETURNvoid_();
}

//@Virtual @Override QSizeF QGraphicsLinearLayout.sizeHint(int which, QSizeF constraint);
KMETHOD QGraphicsLinearLayout_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		Qt::SizeHint which = Int_to(Qt::SizeHint, sfp[1]);
		const QSizeF  constraint = *RawPtr_to(const QSizeF *, sfp[2]);
		QSizeF ret_v = qp->sizeHint(which, constraint);
		QSizeF *ret_v_ = new QSizeF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsLinearLayout QGraphicsLinearLayout.new(QGraphicsLayoutItem parent);
KMETHOD QGraphicsLinearLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLayoutItem*  parent = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
	KQGraphicsLinearLayout *ret_v = new KQGraphicsLinearLayout(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QGraphicsLinearLayout QGraphicsLinearLayout.new(int orientation, QGraphicsLayoutItem parent);
KMETHOD QGraphicsLinearLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
	QGraphicsLayoutItem*  parent = RawPtr_to(QGraphicsLayoutItem*, sfp[2]);
	KQGraphicsLinearLayout *ret_v = new KQGraphicsLinearLayout(orientation, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QGraphicsLinearLayout.addItem(QGraphicsLayoutItem item);
KMETHOD QGraphicsLinearLayout_addItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		QGraphicsLayoutItem*  item = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
		qp->addItem(item);
	}
	RETURNvoid_();
}

//void QGraphicsLinearLayout.addStretch(int stretch);
KMETHOD QGraphicsLinearLayout_addStretch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		int stretch = Int_to(int, sfp[1]);
		qp->addStretch(stretch);
	}
	RETURNvoid_();
}

//QtAlignment QGraphicsLinearLayout.getAlignment(QGraphicsLayoutItem item);
KMETHOD QGraphicsLinearLayout_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		QGraphicsLayoutItem*  item = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
		Qt::Alignment ret_v = qp->alignment(item);
		Qt::Alignment *ret_v_ = new Qt::Alignment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QGraphicsLinearLayout.insertItem(int index, QGraphicsLayoutItem item);
KMETHOD QGraphicsLinearLayout_insertItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QGraphicsLayoutItem*  item = RawPtr_to(QGraphicsLayoutItem*, sfp[2]);
		qp->insertItem(index, item);
	}
	RETURNvoid_();
}

//void QGraphicsLinearLayout.insertStretch(int index, int stretch);
KMETHOD QGraphicsLinearLayout_insertStretch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		int stretch = Int_to(int, sfp[2]);
		qp->insertStretch(index, stretch);
	}
	RETURNvoid_();
}

//float QGraphicsLinearLayout.getItemSpacing(int index);
KMETHOD QGraphicsLinearLayout_getItemSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		qreal ret_v = qp->itemSpacing(index);
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QGraphicsLinearLayout.getOrientation();
KMETHOD QGraphicsLinearLayout_getOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		Qt::Orientation ret_v = qp->orientation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QGraphicsLinearLayout.removeItem(QGraphicsLayoutItem item);
KMETHOD QGraphicsLinearLayout_removeItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		QGraphicsLayoutItem*  item = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
		qp->removeItem(item);
	}
	RETURNvoid_();
}

//void QGraphicsLinearLayout.setAlignment(QGraphicsLayoutItem item, QtAlignment alignment);
KMETHOD QGraphicsLinearLayout_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		QGraphicsLayoutItem*  item = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
		initFlag(alignment, Qt::Alignment, sfp[2]);
		qp->setAlignment(item, alignment);
	}
	RETURNvoid_();
}

//void QGraphicsLinearLayout.setItemSpacing(int index, float spacing);
KMETHOD QGraphicsLinearLayout_setItemSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		qreal spacing = Float_to(qreal, sfp[2]);
		qp->setItemSpacing(index, spacing);
	}
	RETURNvoid_();
}

//void QGraphicsLinearLayout.setOrientation(int orientation);
KMETHOD QGraphicsLinearLayout_setOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
		qp->setOrientation(orientation);
	}
	RETURNvoid_();
}

//void QGraphicsLinearLayout.setSpacing(float spacing);
KMETHOD QGraphicsLinearLayout_setSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		qreal spacing = Float_to(qreal, sfp[1]);
		qp->setSpacing(spacing);
	}
	RETURNvoid_();
}

//void QGraphicsLinearLayout.setStretchFactor(QGraphicsLayoutItem item, int stretch);
KMETHOD QGraphicsLinearLayout_setStretchFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		QGraphicsLayoutItem*  item = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
		int stretch = Int_to(int, sfp[2]);
		qp->setStretchFactor(item, stretch);
	}
	RETURNvoid_();
}

//float QGraphicsLinearLayout.getSpacing();
KMETHOD QGraphicsLinearLayout_getSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->spacing();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QGraphicsLinearLayout.getStretchFactor(QGraphicsLayoutItem item);
KMETHOD QGraphicsLinearLayout_getStretchFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsLinearLayout *  qp = RawPtr_to(QGraphicsLinearLayout *, sfp[0]);
	if (qp) {
		QGraphicsLayoutItem*  item = RawPtr_to(QGraphicsLayoutItem*, sfp[1]);
		int ret_v = qp->stretchFactor(item);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQGraphicsLinearLayout::DummyQGraphicsLinearLayout()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGraphicsLinearLayout::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsLinearLayout::self = ptr;
	DummyQGraphicsLayout::setSelf(ptr);
}

bool DummyQGraphicsLinearLayout::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsLayout::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsLinearLayout::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsLinearLayout::event_map->bigin();
	if ((itr = DummyQGraphicsLinearLayout::event_map->find(str)) == DummyQGraphicsLinearLayout::event_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsLayout::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsLinearLayout::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsLinearLayout::slot_map->bigin();
	if ((itr = DummyQGraphicsLinearLayout::slot_map->find(str)) == DummyQGraphicsLinearLayout::slot_map->end()) {
		bool ret = false;
		ret = DummyQGraphicsLayout::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQGraphicsLinearLayout::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQGraphicsLayout::reftrace(ctx, p, tail_);
}

void DummyQGraphicsLinearLayout::connection(QObject *o)
{
	QGraphicsLinearLayout *p = dynamic_cast<QGraphicsLinearLayout*>(o);
	if (p != NULL) {
	}
	DummyQGraphicsLayout::connection(o);
}

KQGraphicsLinearLayout::KQGraphicsLinearLayout(QGraphicsLayoutItem* parent) : QGraphicsLinearLayout(parent)
{
	self = NULL;
	dummy = new DummyQGraphicsLinearLayout();
}

KMETHOD QGraphicsLinearLayout_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsLinearLayout *qp = RawPtr_to(KQGraphicsLinearLayout *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsLinearLayout]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsLinearLayout]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsLinearLayout_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsLinearLayout *qp = RawPtr_to(KQGraphicsLinearLayout *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsLinearLayout]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsLinearLayout]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsLinearLayout_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsLinearLayout *qp = (KQGraphicsLinearLayout *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsLinearLayout_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQGraphicsLinearLayout *qp = (KQGraphicsLinearLayout *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsLinearLayout_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsLinearLayout::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQGraphicsLinearLayout(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsLinearLayout";
	cdef->free = QGraphicsLinearLayout_free;
	cdef->reftrace = QGraphicsLinearLayout_reftrace;
	cdef->compareTo = QGraphicsLinearLayout_compareTo;
}


