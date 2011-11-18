//@Virtual @Override boolean QSlider.event(QEvent event);
KMETHOD QSlider_event(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSlider *  qp = RawPtr_to(QSlider *, sfp[0]);
	if (qp) {
		QEvent*  event = RawPtr_to(QEvent*, sfp[1]);
		bool ret_v = qp->event(event);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QSize QSlider.minimumSizeHint();
KMETHOD QSlider_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSlider *  qp = RawPtr_to(QSlider *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QSlider.sizeHint();
KMETHOD QSlider_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSlider *  qp = RawPtr_to(QSlider *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSlider QSlider.new(QWidget parent);
KMETHOD QSlider_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQSlider *ret_v = new KQSlider(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QSlider QSlider.new(int orientation, QWidget parent);
KMETHOD QSlider_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQSlider *ret_v = new KQSlider(orientation, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//void QSlider.setTickInterval(int ti);
KMETHOD QSlider_setTickInterval(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSlider *  qp = RawPtr_to(QSlider *, sfp[0]);
	if (qp) {
		int ti = Int_to(int, sfp[1]);
		qp->setTickInterval(ti);
	}
	RETURNvoid_();
}

//void QSlider.setTickPosition(int position);
KMETHOD QSlider_setTickPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSlider *  qp = RawPtr_to(QSlider *, sfp[0]);
	if (qp) {
		QSlider::TickPosition position = Int_to(QSlider::TickPosition, sfp[1]);
		qp->setTickPosition(position);
	}
	RETURNvoid_();
}

//int QSlider.getTickInterval();
KMETHOD QSlider_getTickInterval(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSlider *  qp = RawPtr_to(QSlider *, sfp[0]);
	if (qp) {
		int ret_v = qp->tickInterval();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QSlider.getTickPosition();
KMETHOD QSlider_getTickPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSlider *  qp = RawPtr_to(QSlider *, sfp[0]);
	if (qp) {
		QSlider::TickPosition ret_v = qp->tickPosition();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQSlider::DummyQSlider()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQSlider::~DummyQSlider()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQSlider::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSlider::self = ptr;
	DummyQAbstractSlider::setSelf(ptr);
}

bool DummyQSlider::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractSlider::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQSlider::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSlider::event_map->bigin();
	if ((itr = DummyQSlider::event_map->find(str)) == DummyQSlider::event_map->end()) {
		bool ret = false;
		ret = DummyQAbstractSlider::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSlider::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSlider::slot_map->bigin();
	if ((itr = DummyQSlider::slot_map->find(str)) == DummyQSlider::slot_map->end()) {
		bool ret = false;
		ret = DummyQAbstractSlider::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQSlider::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQSlider::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQAbstractSlider::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQSlider::connection(QObject *o)
{
	QSlider *p = dynamic_cast<QSlider*>(o);
	if (p != NULL) {
	}
	DummyQAbstractSlider::connection(o);
}

KQSlider::KQSlider(QWidget* parent) : QSlider(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQSlider();
	dummy->connection((QObject*)this);
}

KQSlider::~KQSlider()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QSlider_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSlider *qp = RawPtr_to(KQSlider *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSlider]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSlider]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSlider_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSlider *qp = RawPtr_to(KQSlider *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSlider]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSlider]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSlider_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQSlider *qp = (KQSlider *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QSlider*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QSlider_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQSlider *qp = (KQSlider *)p->rawptr;
		KQSlider *qp = static_cast<KQSlider*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSlider_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSlider::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQSlider::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QSlider::event(event);
		return false;
	}
//	QSlider::event(event);
	return true;
}

static knh_IntData_t QSliderConstInt[] = {
	{"NoTicks", QSlider::NoTicks},
	{"TicksBothSides", QSlider::TicksBothSides},
	{"TicksAbove", QSlider::TicksAbove},
	{"TicksBelow", QSlider::TicksBelow},
	{"TicksLeft", QSlider::TicksLeft},
	{"TicksRight", QSlider::TicksRight},
	{NULL, 0}
};

DEFAPI(void) constQSlider(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QSliderConstInt);
}


DEFAPI(void) defQSlider(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSlider";
	cdef->free = QSlider_free;
	cdef->reftrace = QSlider_reftrace;
	cdef->compareTo = QSlider_compareTo;
}


