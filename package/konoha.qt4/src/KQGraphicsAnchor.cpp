//void QGraphicsAnchor.setSizePolicy(int policy);
KMETHOD QGraphicsAnchor_setSizePolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchor *  qp = RawPtr_to(QGraphicsAnchor *, sfp[0]);
	if (qp) {
		QSizePolicy::Policy policy = Int_to(QSizePolicy::Policy, sfp[1]);
		qp->setSizePolicy(policy);
	}
	RETURNvoid_();
}

//void QGraphicsAnchor.setSpacing(float spacing);
KMETHOD QGraphicsAnchor_setSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchor *  qp = RawPtr_to(QGraphicsAnchor *, sfp[0]);
	if (qp) {
		qreal spacing = Float_to(qreal, sfp[1]);
		qp->setSpacing(spacing);
	}
	RETURNvoid_();
}

//int QGraphicsAnchor.getSizePolicy();
KMETHOD QGraphicsAnchor_getSizePolicy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchor *  qp = RawPtr_to(QGraphicsAnchor *, sfp[0]);
	if (qp) {
		QSizePolicy::Policy ret_v = qp->sizePolicy();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QGraphicsAnchor.getSpacing();
KMETHOD QGraphicsAnchor_getSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchor *  qp = RawPtr_to(QGraphicsAnchor *, sfp[0]);
	if (qp) {
		qreal ret_v = qp->spacing();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QGraphicsAnchor.unsetSpacing();
KMETHOD QGraphicsAnchor_unsetSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsAnchor *  qp = RawPtr_to(QGraphicsAnchor *, sfp[0]);
	if (qp) {
		qp->unsetSpacing();
	}
	RETURNvoid_();
}


DummyQGraphicsAnchor::DummyQGraphicsAnchor()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQGraphicsAnchor::~DummyQGraphicsAnchor()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQGraphicsAnchor::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsAnchor::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQGraphicsAnchor::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsAnchor::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsAnchor::event_map->bigin();
	if ((itr = DummyQGraphicsAnchor::event_map->find(str)) == DummyQGraphicsAnchor::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsAnchor::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsAnchor::slot_map->bigin();
	if ((itr = DummyQGraphicsAnchor::slot_map->find(str)) == DummyQGraphicsAnchor::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQGraphicsAnchor::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQGraphicsAnchor::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQGraphicsAnchor::connection(QObject *o)
{
	QGraphicsAnchor *p = dynamic_cast<QGraphicsAnchor*>(o);
	if (p != NULL) {
	}
	DummyQObject::connection(o);
}

KQGraphicsAnchor::~KQGraphicsAnchor()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QGraphicsAnchor_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsAnchor *qp = RawPtr_to(KQGraphicsAnchor *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsAnchor]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsAnchor]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QGraphicsAnchor_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsAnchor *qp = RawPtr_to(KQGraphicsAnchor *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsAnchor]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsAnchor]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsAnchor_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQGraphicsAnchor *qp = (KQGraphicsAnchor *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QGraphicsAnchor*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QGraphicsAnchor_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQGraphicsAnchor *qp = (KQGraphicsAnchor *)p->rawptr;
		KQGraphicsAnchor *qp = static_cast<KQGraphicsAnchor*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QGraphicsAnchor_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQGraphicsAnchor::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQGraphicsAnchor::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QGraphicsAnchor::event(event);
		return false;
	}
//	QGraphicsAnchor::event(event);
	return true;
}



DEFAPI(void) defQGraphicsAnchor(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsAnchor";
	cdef->free = QGraphicsAnchor_free;
	cdef->reftrace = QGraphicsAnchor_reftrace;
	cdef->compareTo = QGraphicsAnchor_compareTo;
}


