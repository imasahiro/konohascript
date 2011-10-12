//@Virtual @Override int QSpacerItem.expandingDirections();
KMETHOD QSpacerItem_expandingDirections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp != NULL) {
		Qt::Orientations ret_v = qp->expandingDirections();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QRect QSpacerItem.getGeometry();
KMETHOD QSpacerItem_getGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp != NULL) {
		QRect ret_v = qp->geometry();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QSpacerItem.isEmpty();
KMETHOD QSpacerItem_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QSize QSpacerItem.maximumSize();
KMETHOD QSpacerItem_maximumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->maximumSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QSpacerItem.minimumSize();
KMETHOD QSpacerItem_minimumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->minimumSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QSpacerItem.setGeometry(QRect r);
KMETHOD QSpacerItem_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp != NULL) {
		const QRect  r = *RawPtr_to(const QRect *, sfp[1]);
		qp->setGeometry(r);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QSpacerItem.sizeHint();
KMETHOD QSpacerItem_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSpacerItem QSpacerItem.spacerItem();
KMETHOD QSpacerItem_spacerItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp != NULL) {
		QSpacerItem* ret_v = qp->spacerItem();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QSpacerItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSpacerItem QSpacerItem.new(int w, int h, int hPolicy, int vPolicy);
KMETHOD QSpacerItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int w = Int_to(int, sfp[1]);
	int h = Int_to(int, sfp[2]);
	QSizePolicy::Policy hPolicy = Int_to(QSizePolicy::Policy, sfp[3]);
	QSizePolicy::Policy vPolicy = Int_to(QSizePolicy::Policy, sfp[4]);
	KQSpacerItem *ret_v = new KQSpacerItem(w, h, hPolicy, vPolicy);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QSpacerItem.changeSize(int w, int h, int hPolicy, int vPolicy);
KMETHOD QSpacerItem_changeSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp != NULL) {
		int w = Int_to(int, sfp[1]);
		int h = Int_to(int, sfp[2]);
		QSizePolicy::Policy hPolicy = Int_to(QSizePolicy::Policy, sfp[3]);
		QSizePolicy::Policy vPolicy = Int_to(QSizePolicy::Policy, sfp[4]);
		qp->changeSize(w, h, hPolicy, vPolicy);
	}
	RETURNvoid_();
}


DummyQSpacerItem::DummyQSpacerItem()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQSpacerItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSpacerItem::self = ptr;
	DummyQLayoutItem::setSelf(ptr);
}

bool DummyQSpacerItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQLayoutItem::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQSpacerItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSpacerItem::event_map->bigin();
	if ((itr = DummyQSpacerItem::event_map->find(str)) == DummyQSpacerItem::event_map->end()) {
		bool ret;
		ret = DummyQLayoutItem::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSpacerItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSpacerItem::slot_map->bigin();
	if ((itr = DummyQSpacerItem::event_map->find(str)) == DummyQSpacerItem::slot_map->end()) {
		bool ret;
		ret = DummyQLayoutItem::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQSpacerItem::KQSpacerItem(int w, int h, QSizePolicy::Policy hPolicy, QSizePolicy::Policy vPolicy) : QSpacerItem(w, h, hPolicy, vPolicy)
{
	self = NULL;
}

KMETHOD QSpacerItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSpacerItem *qp = RawPtr_to(KQSpacerItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSpacerItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQSpacerItem::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSpacerItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QSpacerItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSpacerItem *qp = RawPtr_to(KQSpacerItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSpacerItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQSpacerItem::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSpacerItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSpacerItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQSpacerItem *qp = (KQSpacerItem *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QSpacerItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQSpacerItem *qp = (KQSpacerItem *)p->rawptr;
		(void)qp;
	}
}

static int QSpacerItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQSpacerItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSpacerItem";
	cdef->free = QSpacerItem_free;
	cdef->reftrace = QSpacerItem_reftrace;
	cdef->compareTo = QSpacerItem_compareTo;
}


