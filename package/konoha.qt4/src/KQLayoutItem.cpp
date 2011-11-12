//
//QtAlignment QLayoutItem.getAlignment();
KMETHOD QLayoutItem_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *  qp = RawPtr_to(QLayoutItem *, sfp[0]);
	if (qp) {
		Qt::Alignment ret_v = qp->alignment();
		Qt::Alignment *ret_v_ = new Qt::Alignment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QLayoutItem.controlTypes();
KMETHOD QLayoutItem_controlTypes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *  qp = RawPtr_to(QLayoutItem *, sfp[0]);
	if (qp) {
		QSizePolicy::ControlTypes ret_v = qp->controlTypes();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QtOrientations QLayoutItem.expandingDirections();
KMETHOD QLayoutItem_expandingDirections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *  qp = RawPtr_to(QLayoutItem *, sfp[0]);
	if (qp) {
		Qt::Orientations ret_v = qp->expandingDirections();
		Qt::Orientations *ret_v_ = new Qt::Orientations(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QRect QLayoutItem.getGeometry();
KMETHOD QLayoutItem_getGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *  qp = RawPtr_to(QLayoutItem *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->geometry();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual boolean QLayoutItem.hasHeightForWidth();
KMETHOD QLayoutItem_hasHeightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *  qp = RawPtr_to(QLayoutItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasHeightForWidth();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual int QLayoutItem.heightForWidth(int w);
KMETHOD QLayoutItem_heightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *  qp = RawPtr_to(QLayoutItem *, sfp[0]);
	if (qp) {
		int w = Int_to(int, sfp[1]);
		int ret_v = qp->heightForWidth(w);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual void QLayoutItem.invalidate();
KMETHOD QLayoutItem_invalidate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *  qp = RawPtr_to(QLayoutItem *, sfp[0]);
	if (qp) {
		qp->invalidate();
	}
	RETURNvoid_();
}

//@Virtual boolean QLayoutItem.isEmpty();
KMETHOD QLayoutItem_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *  qp = RawPtr_to(QLayoutItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual QLayout QLayoutItem.layout();
KMETHOD QLayoutItem_layout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *  qp = RawPtr_to(QLayoutItem *, sfp[0]);
	if (qp) {
		QLayout* ret_v = qp->layout();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QLayout*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QSize QLayoutItem.maximumSize();
KMETHOD QLayoutItem_maximumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *  qp = RawPtr_to(QLayoutItem *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->maximumSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual int QLayoutItem.minimumHeightForWidth(int w);
KMETHOD QLayoutItem_minimumHeightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *  qp = RawPtr_to(QLayoutItem *, sfp[0]);
	if (qp) {
		int w = Int_to(int, sfp[1]);
		int ret_v = qp->minimumHeightForWidth(w);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QSize QLayoutItem.minimumSize();
KMETHOD QLayoutItem_minimumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *  qp = RawPtr_to(QLayoutItem *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QLayoutItem.setAlignment(QtAlignment alignment);
KMETHOD QLayoutItem_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *  qp = RawPtr_to(QLayoutItem *, sfp[0]);
	if (qp) {
		initFlag(alignment, Qt::Alignment, sfp[1]);
		qp->setAlignment(alignment);
	}
	RETURNvoid_();
}

//@Virtual void QLayoutItem.setGeometry(QRect r);
KMETHOD QLayoutItem_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *  qp = RawPtr_to(QLayoutItem *, sfp[0]);
	if (qp) {
		const QRect  r = *RawPtr_to(const QRect *, sfp[1]);
		qp->setGeometry(r);
	}
	RETURNvoid_();
}

//@Virtual QSize QLayoutItem.sizeHint();
KMETHOD QLayoutItem_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *  qp = RawPtr_to(QLayoutItem *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QSpacerItem QLayoutItem.spacerItem();
KMETHOD QLayoutItem_spacerItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *  qp = RawPtr_to(QLayoutItem *, sfp[0]);
	if (qp) {
		QSpacerItem* ret_v = qp->spacerItem();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QSpacerItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QWidget QLayoutItem.widget();
KMETHOD QLayoutItem_widget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *  qp = RawPtr_to(QLayoutItem *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->widget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QLayoutItem.parents();
KMETHOD QLayoutItem_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayoutItem *qp = RawPtr_to(QLayoutItem*, sfp[0]);
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

DummyQLayoutItem::DummyQLayoutItem()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQLayoutItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQLayoutItem::self = ptr;
}

bool DummyQLayoutItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQLayoutItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLayoutItem::event_map->bigin();
	if ((itr = DummyQLayoutItem::event_map->find(str)) == DummyQLayoutItem::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQLayoutItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLayoutItem::slot_map->bigin();
	if ((itr = DummyQLayoutItem::slot_map->find(str)) == DummyQLayoutItem::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQLayoutItem::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQLayoutItem::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQLayoutItem::connection(QObject *o)
{
	QLayoutItem *p = dynamic_cast<QLayoutItem*>(o);
	if (p != NULL) {
	}
}

KQLayoutItem::KQLayoutItem(Qt::Alignment alignment) : QLayoutItem(alignment)
{
	self = NULL;
	dummy = new DummyQLayoutItem();
}

KMETHOD QLayoutItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLayoutItem *qp = RawPtr_to(KQLayoutItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QLayoutItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLayoutItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QLayoutItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLayoutItem *qp = RawPtr_to(KQLayoutItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QLayoutItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLayoutItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QLayoutItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQLayoutItem *qp = (KQLayoutItem *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QLayoutItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQLayoutItem *qp = (KQLayoutItem *)p->rawptr;
//		KQLayoutItem *qp = static_cast<KQLayoutItem*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QLayoutItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQLayoutItem::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQLayoutItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QLayoutItem";
	cdef->free = QLayoutItem_free;
	cdef->reftrace = QLayoutItem_reftrace;
	cdef->compareTo = QLayoutItem_compareTo;
}


