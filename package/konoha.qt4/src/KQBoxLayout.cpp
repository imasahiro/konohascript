//@Virtual @Override void QBoxLayout.addItem(QLayoutItem item);
KMETHOD QBoxLayout_addItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		QLayoutItem*  item = RawPtr_to(QLayoutItem*, sfp[1]);
		qp->addItem(item);
	}
	RETURNvoid_();
}

//@Virtual @Override int QBoxLayout.count();
KMETHOD QBoxLayout_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QtOrientations QBoxLayout.expandingDirections();
KMETHOD QBoxLayout_expandingDirections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		Qt::Orientations ret_v = qp->expandingDirections();
		Qt::Orientations *ret_v_ = new Qt::Orientations(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QBoxLayout.hasHeightForWidth();
KMETHOD QBoxLayout_hasHeightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasHeightForWidth();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override int QBoxLayout.heightForWidth(int w);
KMETHOD QBoxLayout_heightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		int w = Int_to(int, sfp[1]);
		int ret_v = qp->heightForWidth(w);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override void QBoxLayout.invalidate();
KMETHOD QBoxLayout_invalidate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		qp->invalidate();
	}
	RETURNvoid_();
}

//@Virtual @Override QLayoutItem QBoxLayout.itemAt(int index);
KMETHOD QBoxLayout_itemAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QLayoutItem* ret_v = qp->itemAt(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QLayoutItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QBoxLayout.maximumSize();
KMETHOD QBoxLayout_maximumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->maximumSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QBoxLayout.minimumHeightForWidth(int w);
KMETHOD QBoxLayout_minimumHeightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		int w = Int_to(int, sfp[1]);
		int ret_v = qp->minimumHeightForWidth(w);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QSize QBoxLayout.minimumSize();
KMETHOD QBoxLayout_minimumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QBoxLayout.setGeometry(QRect r);
KMETHOD QBoxLayout_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		const QRect  r = *RawPtr_to(const QRect *, sfp[1]);
		qp->setGeometry(r);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QBoxLayout.sizeHint();
KMETHOD QBoxLayout_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QLayoutItem QBoxLayout.takeAt(int index);
KMETHOD QBoxLayout_takeAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QLayoutItem* ret_v = qp->takeAt(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QLayoutItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QBoxLayout QBoxLayout.new(int dir, QWidget parent);
KMETHOD QBoxLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout::Direction dir = Int_to(QBoxLayout::Direction, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQBoxLayout *ret_v = new KQBoxLayout(dir, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QBoxLayout.addLayout(QLayout layout, int stretch);
KMETHOD QBoxLayout_addLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		QLayout*  layout = RawPtr_to(QLayout*, sfp[1]);
		int stretch = Int_to(int, sfp[2]);
		qp->addLayout(layout, stretch);
	}
	RETURNvoid_();
}

//void QBoxLayout.addSpacerItem(QSpacerItem spacerItem);
KMETHOD QBoxLayout_addSpacerItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		QSpacerItem*  spacerItem = RawPtr_to(QSpacerItem*, sfp[1]);
		qp->addSpacerItem(spacerItem);
	}
	RETURNvoid_();
}

//void QBoxLayout.addSpacing(int size);
KMETHOD QBoxLayout_addSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		int size = Int_to(int, sfp[1]);
		qp->addSpacing(size);
	}
	RETURNvoid_();
}

//void QBoxLayout.addStretch(int stretch);
KMETHOD QBoxLayout_addStretch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		int stretch = Int_to(int, sfp[1]);
		qp->addStretch(stretch);
	}
	RETURNvoid_();
}

//void QBoxLayout.addStrut(int size);
KMETHOD QBoxLayout_addStrut(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		int size = Int_to(int, sfp[1]);
		qp->addStrut(size);
	}
	RETURNvoid_();
}

//void QBoxLayout.addWidget(QWidget widget, int stretch, QtAlignment alignment);
KMETHOD QBoxLayout_addWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		int stretch = Int_to(int, sfp[2]);
		initFlag(alignment, Qt::Alignment, sfp[3]);
		qp->addWidget(widget, stretch, alignment);
	}
	RETURNvoid_();
}

//int QBoxLayout.getDirection();
KMETHOD QBoxLayout_getDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		QBoxLayout::Direction ret_v = qp->direction();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QBoxLayout.insertLayout(int index, QLayout layout, int stretch);
KMETHOD QBoxLayout_insertLayout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QLayout*  layout = RawPtr_to(QLayout*, sfp[2]);
		int stretch = Int_to(int, sfp[3]);
		qp->insertLayout(index, layout, stretch);
	}
	RETURNvoid_();
}

//void QBoxLayout.insertSpacerItem(int index, QSpacerItem spacerItem);
KMETHOD QBoxLayout_insertSpacerItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QSpacerItem*  spacerItem = RawPtr_to(QSpacerItem*, sfp[2]);
		qp->insertSpacerItem(index, spacerItem);
	}
	RETURNvoid_();
}

//void QBoxLayout.insertSpacing(int index, int size);
KMETHOD QBoxLayout_insertSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		int size = Int_to(int, sfp[2]);
		qp->insertSpacing(index, size);
	}
	RETURNvoid_();
}

//void QBoxLayout.insertStretch(int index, int stretch);
KMETHOD QBoxLayout_insertStretch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		int stretch = Int_to(int, sfp[2]);
		qp->insertStretch(index, stretch);
	}
	RETURNvoid_();
}

//void QBoxLayout.insertWidget(int index, QWidget widget, int stretch, QtAlignment alignment);
KMETHOD QBoxLayout_insertWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		QWidget*  widget = RawPtr_to(QWidget*, sfp[2]);
		int stretch = Int_to(int, sfp[3]);
		initFlag(alignment, Qt::Alignment, sfp[4]);
		qp->insertWidget(index, widget, stretch, alignment);
	}
	RETURNvoid_();
}

//void QBoxLayout.setDirection(int direction);
KMETHOD QBoxLayout_setDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		QBoxLayout::Direction direction = Int_to(QBoxLayout::Direction, sfp[1]);
		qp->setDirection(direction);
	}
	RETURNvoid_();
}

//void QBoxLayout.setSpacing(int spacing);
KMETHOD QBoxLayout_setSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		int spacing = Int_to(int, sfp[1]);
		qp->setSpacing(spacing);
	}
	RETURNvoid_();
}

//void QBoxLayout.setStretch(int index, int stretch);
KMETHOD QBoxLayout_setStretch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		int stretch = Int_to(int, sfp[2]);
		qp->setStretch(index, stretch);
	}
	RETURNvoid_();
}

//boolean QBoxLayout.setStretchFactor(QWidget widget, int stretch);
KMETHOD QBoxLayout_setStretchFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		int stretch = Int_to(int, sfp[2]);
		bool ret_v = qp->setStretchFactor(widget, stretch);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QBoxLayout.setStretchFactor(QLayout layout, int stretch);
KMETHOD QBoxLayout_setStretchFactor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		QLayout*  layout = RawPtr_to(QLayout*, sfp[1]);
		int stretch = Int_to(int, sfp[2]);
		bool ret_v = qp->setStretchFactor(layout, stretch);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//int QBoxLayout.getSpacing();
KMETHOD QBoxLayout_getSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		int ret_v = qp->spacing();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QBoxLayout.getStretch(int index);
KMETHOD QBoxLayout_getStretch(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QBoxLayout *  qp = RawPtr_to(QBoxLayout *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		int ret_v = qp->stretch(index);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQBoxLayout::DummyQBoxLayout()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQBoxLayout::setSelf(knh_RawPtr_t *ptr)
{
	DummyQBoxLayout::self = ptr;
	DummyQLayout::setSelf(ptr);
}

bool DummyQBoxLayout::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQLayout::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQBoxLayout::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQBoxLayout::event_map->bigin();
	if ((itr = DummyQBoxLayout::event_map->find(str)) == DummyQBoxLayout::event_map->end()) {
		bool ret = false;
		ret = DummyQLayout::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQBoxLayout::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQBoxLayout::slot_map->bigin();
	if ((itr = DummyQBoxLayout::slot_map->find(str)) == DummyQBoxLayout::slot_map->end()) {
		bool ret = false;
		ret = DummyQLayout::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQBoxLayout::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQLayout::reftrace(ctx, p, tail_);
}

void DummyQBoxLayout::connection(QObject *o)
{
	QBoxLayout *p = dynamic_cast<QBoxLayout*>(o);
	if (p != NULL) {
	}
	DummyQLayout::connection(o);
}

KQBoxLayout::KQBoxLayout(QBoxLayout::Direction dir, QWidget* parent) : QBoxLayout(dir, parent)
{
	self = NULL;
	dummy = new DummyQBoxLayout();
	dummy->connection((QObject*)this);
}

KMETHOD QBoxLayout_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQBoxLayout *qp = RawPtr_to(KQBoxLayout *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QBoxLayout]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QBoxLayout]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QBoxLayout_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQBoxLayout *qp = RawPtr_to(KQBoxLayout *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QBoxLayout]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QBoxLayout]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QBoxLayout_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQBoxLayout *qp = (KQBoxLayout *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QBoxLayout_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQBoxLayout *qp = (KQBoxLayout *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QBoxLayout_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQBoxLayout::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQBoxLayout::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QBoxLayout::event(event);
		return false;
	}
	return true;
}

static knh_IntData_t QBoxLayoutConstInt[] = {
	{"LeftToRight", QBoxLayout::LeftToRight},
	{"RightToLeft", QBoxLayout::RightToLeft},
	{"TopToBottom", QBoxLayout::TopToBottom},
	{"BottomToTop", QBoxLayout::BottomToTop},
	{NULL, 0}
};

DEFAPI(void) constQBoxLayout(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QBoxLayoutConstInt);
}


DEFAPI(void) defQBoxLayout(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QBoxLayout";
	cdef->free = QBoxLayout_free;
	cdef->reftrace = QBoxLayout_reftrace;
	cdef->compareTo = QBoxLayout_compareTo;
}


