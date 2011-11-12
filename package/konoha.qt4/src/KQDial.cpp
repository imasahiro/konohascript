//@Virtual @Override QSize QDial.minimumSizeHint();
KMETHOD QDial_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDial *  qp = RawPtr_to(QDial *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QDial.sizeHint();
KMETHOD QDial_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDial *  qp = RawPtr_to(QDial *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDial QDial.new(QWidget parent);
KMETHOD QDial_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQDial *ret_v = new KQDial(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QDial.notchSize();
KMETHOD QDial_notchSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDial *  qp = RawPtr_to(QDial *, sfp[0]);
	if (qp) {
		int ret_v = qp->notchSize();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QDial.getNotchTarget();
KMETHOD QDial_getNotchTarget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDial *  qp = RawPtr_to(QDial *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->notchTarget();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//boolean QDial.getNotchesVisible();
KMETHOD QDial_getNotchesVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDial *  qp = RawPtr_to(QDial *, sfp[0]);
	if (qp) {
		bool ret_v = qp->notchesVisible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QDial.setNotchTarget(double target);
KMETHOD QDial_setNotchTarget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDial *  qp = RawPtr_to(QDial *, sfp[0]);
	if (qp) {
		double  target = *RawPtr_to(double *, sfp[1]);
		qp->setNotchTarget(target);
	}
	RETURNvoid_();
}

//boolean QDial.getWrapping();
KMETHOD QDial_getWrapping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDial *  qp = RawPtr_to(QDial *, sfp[0]);
	if (qp) {
		bool ret_v = qp->wrapping();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QDial.setNotchesVisible(boolean visible);
KMETHOD QDial_setNotchesVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDial *  qp = RawPtr_to(QDial *, sfp[0]);
	if (qp) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setNotchesVisible(visible);
	}
	RETURNvoid_();
}

//void QDial.setWrapping(boolean on);
KMETHOD QDial_setWrapping(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDial *  qp = RawPtr_to(QDial *, sfp[0]);
	if (qp) {
		bool on = Boolean_to(bool, sfp[1]);
		qp->setWrapping(on);
	}
	RETURNvoid_();
}


DummyQDial::DummyQDial()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQDial::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDial::self = ptr;
	DummyQAbstractSlider::setSelf(ptr);
}

bool DummyQDial::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractSlider::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQDial::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDial::event_map->bigin();
	if ((itr = DummyQDial::event_map->find(str)) == DummyQDial::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractSlider::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDial::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDial::slot_map->bigin();
	if ((itr = DummyQDial::slot_map->find(str)) == DummyQDial::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractSlider::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQDial::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQDial::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQAbstractSlider::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQDial::connection(QObject *o)
{
	QDial *p = dynamic_cast<QDial*>(o);
	if (p != NULL) {
	}
	DummyQAbstractSlider::connection(o);
}

KQDial::KQDial(QWidget* parent) : QDial(parent)
{
	self = NULL;
	dummy = new DummyQDial();
	dummy->connection((QObject*)this);
}

KMETHOD QDial_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDial *qp = RawPtr_to(KQDial *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDial]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDial]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QDial_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDial *qp = RawPtr_to(KQDial *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDial]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDial]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDial_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDial *qp = (KQDial *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDial_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQDial *qp = (KQDial *)p->rawptr;
//		KQDial *qp = static_cast<KQDial*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QDial_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQDial::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQDial::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QDial::event(event);
		return false;
	}
//	QDial::event(event);
	return true;
}



DEFAPI(void) defQDial(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDial";
	cdef->free = QDial_free;
	cdef->reftrace = QDial_reftrace;
	cdef->compareTo = QDial_compareTo;
}


