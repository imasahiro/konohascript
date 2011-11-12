//@Virtual @Override boolean QScrollBar.event(QEvent event);
KMETHOD QScrollBar_event(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QScrollBar *  qp = RawPtr_to(QScrollBar *, sfp[0]);
	if (qp) {
		QEvent*  event = RawPtr_to(QEvent*, sfp[1]);
		bool ret_v = qp->event(event);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QSize QScrollBar.sizeHint();
KMETHOD QScrollBar_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QScrollBar *  qp = RawPtr_to(QScrollBar *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QScrollBar QScrollBar.new(QWidget parent);
KMETHOD QScrollBar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQScrollBar *ret_v = new KQScrollBar(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QScrollBar QScrollBar.new(int orientation, QWidget parent);
KMETHOD QScrollBar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQScrollBar *ret_v = new KQScrollBar(orientation, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQScrollBar::DummyQScrollBar()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQScrollBar::setSelf(knh_RawPtr_t *ptr)
{
	DummyQScrollBar::self = ptr;
	DummyQAbstractSlider::setSelf(ptr);
}

bool DummyQScrollBar::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractSlider::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQScrollBar::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQScrollBar::event_map->bigin();
	if ((itr = DummyQScrollBar::event_map->find(str)) == DummyQScrollBar::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractSlider::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQScrollBar::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQScrollBar::slot_map->bigin();
	if ((itr = DummyQScrollBar::slot_map->find(str)) == DummyQScrollBar::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractSlider::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQScrollBar::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQScrollBar::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQAbstractSlider::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQScrollBar::connection(QObject *o)
{
	QScrollBar *p = dynamic_cast<QScrollBar*>(o);
	if (p != NULL) {
	}
	DummyQAbstractSlider::connection(o);
}

KQScrollBar::KQScrollBar(QWidget* parent) : QScrollBar(parent)
{
	self = NULL;
	dummy = new DummyQScrollBar();
	dummy->connection((QObject*)this);
}

KMETHOD QScrollBar_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQScrollBar *qp = RawPtr_to(KQScrollBar *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QScrollBar]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QScrollBar]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QScrollBar_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQScrollBar *qp = RawPtr_to(KQScrollBar *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QScrollBar]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QScrollBar]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QScrollBar_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQScrollBar *qp = (KQScrollBar *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QScrollBar_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQScrollBar *qp = (KQScrollBar *)p->rawptr;
//		KQScrollBar *qp = static_cast<KQScrollBar*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QScrollBar_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQScrollBar::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQScrollBar::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QScrollBar::event(event);
		return false;
	}
//	QScrollBar::event(event);
	return true;
}



DEFAPI(void) defQScrollBar(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QScrollBar";
	cdef->free = QScrollBar_free;
	cdef->reftrace = QScrollBar_reftrace;
	cdef->compareTo = QScrollBar_compareTo;
}


