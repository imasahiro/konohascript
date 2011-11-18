//@Virtual @Override QtOrientations QWidgetItem.expandingDirections();
KMETHOD QWidgetItem_expandingDirections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidgetItem *  qp = RawPtr_to(QWidgetItem *, sfp[0]);
	if (qp) {
		Qt::Orientations ret_v = qp->expandingDirections();
		Qt::Orientations *ret_v_ = new Qt::Orientations(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QRect QWidgetItem.getGeometry();
KMETHOD QWidgetItem_getGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidgetItem *  qp = RawPtr_to(QWidgetItem *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->geometry();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QWidgetItem.hasHeightForWidth();
KMETHOD QWidgetItem_hasHeightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidgetItem *  qp = RawPtr_to(QWidgetItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasHeightForWidth();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override int QWidgetItem.heightForWidth(int w);
KMETHOD QWidgetItem_heightForWidth(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidgetItem *  qp = RawPtr_to(QWidgetItem *, sfp[0]);
	if (qp) {
		int w = Int_to(int, sfp[1]);
		int ret_v = qp->heightForWidth(w);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override boolean QWidgetItem.isEmpty();
KMETHOD QWidgetItem_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidgetItem *  qp = RawPtr_to(QWidgetItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QSize QWidgetItem.maximumSize();
KMETHOD QWidgetItem_maximumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidgetItem *  qp = RawPtr_to(QWidgetItem *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->maximumSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QWidgetItem.minimumSize();
KMETHOD QWidgetItem_minimumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidgetItem *  qp = RawPtr_to(QWidgetItem *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QWidgetItem.setGeometry(QRect rect);
KMETHOD QWidgetItem_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidgetItem *  qp = RawPtr_to(QWidgetItem *, sfp[0]);
	if (qp) {
		const QRect  rect = *RawPtr_to(const QRect *, sfp[1]);
		qp->setGeometry(rect);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QWidgetItem.sizeHint();
KMETHOD QWidgetItem_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidgetItem *  qp = RawPtr_to(QWidgetItem *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QWidget QWidgetItem.widget();
KMETHOD QWidgetItem_widget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidgetItem *  qp = RawPtr_to(QWidgetItem *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->widget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidgetItem QWidgetItem.new(QWidget widget);
KMETHOD QWidgetItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
	KQWidgetItem *ret_v = new KQWidgetItem(widget);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}


DummyQWidgetItem::DummyQWidgetItem()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQWidgetItem::~DummyQWidgetItem()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQWidgetItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWidgetItem::self = ptr;
	DummyQLayoutItem::setSelf(ptr);
}

bool DummyQWidgetItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQLayoutItem::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQWidgetItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWidgetItem::event_map->bigin();
	if ((itr = DummyQWidgetItem::event_map->find(str)) == DummyQWidgetItem::event_map->end()) {
		bool ret = false;
		ret = DummyQLayoutItem::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWidgetItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWidgetItem::slot_map->bigin();
	if ((itr = DummyQWidgetItem::slot_map->find(str)) == DummyQWidgetItem::slot_map->end()) {
		bool ret = false;
		ret = DummyQLayoutItem::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQWidgetItem::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQWidgetItem::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQLayoutItem::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQWidgetItem::connection(QObject *o)
{
	QWidgetItem *p = dynamic_cast<QWidgetItem*>(o);
	if (p != NULL) {
	}
	DummyQLayoutItem::connection(o);
}

KQWidgetItem::KQWidgetItem(QWidget* widget) : QWidgetItem(widget)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQWidgetItem();
}

KQWidgetItem::~KQWidgetItem()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QWidgetItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWidgetItem *qp = RawPtr_to(KQWidgetItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWidgetItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWidgetItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWidgetItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWidgetItem *qp = RawPtr_to(KQWidgetItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWidgetItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWidgetItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWidgetItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQWidgetItem *qp = (KQWidgetItem *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QWidgetItem*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QWidgetItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQWidgetItem *qp = (KQWidgetItem *)p->rawptr;
		KQWidgetItem *qp = static_cast<KQWidgetItem*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWidgetItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWidgetItem::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQWidgetItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWidgetItem";
	cdef->free = QWidgetItem_free;
	cdef->reftrace = QWidgetItem_reftrace;
	cdef->compareTo = QWidgetItem_compareTo;
}


