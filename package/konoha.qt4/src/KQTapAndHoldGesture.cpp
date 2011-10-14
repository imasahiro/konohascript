//QPointF QTapAndHoldGesture.getPosition();
KMETHOD QTapAndHoldGesture_getPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTapAndHoldGesture *  qp = RawPtr_to(QTapAndHoldGesture *, sfp[0]);
	if (qp != NULL) {
		QPointF ret_v = qp->position();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTapAndHoldGesture.setPosition(QPointF pos);
KMETHOD QTapAndHoldGesture_setPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTapAndHoldGesture *  qp = RawPtr_to(QTapAndHoldGesture *, sfp[0]);
	if (qp != NULL) {
		const QPointF  pos = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setPosition(pos);
	}
	RETURNvoid_();
}

//void QTapAndHoldGesture.setTimeout(int msecs);
KMETHOD QTapAndHoldGesture_setTimeout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTapAndHoldGesture *  qp = RawPtr_to(QTapAndHoldGesture *, sfp[0]);
	if (qp != NULL) {
		int msecs = Int_to(int, sfp[1]);
		qp->setTimeout(msecs);
	}
	RETURNvoid_();
}

//int QTapAndHoldGesture.getTimeout();
KMETHOD QTapAndHoldGesture_getTimeout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTapAndHoldGesture *  qp = RawPtr_to(QTapAndHoldGesture *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->timeout();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQTapAndHoldGesture::DummyQTapAndHoldGesture()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTapAndHoldGesture::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTapAndHoldGesture::self = ptr;
	DummyQGesture::setSelf(ptr);
}

bool DummyQTapAndHoldGesture::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGesture::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTapAndHoldGesture::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTapAndHoldGesture::event_map->bigin();
	if ((itr = DummyQTapAndHoldGesture::event_map->find(str)) == DummyQTapAndHoldGesture::event_map->end()) {
		bool ret = false;
		ret = DummyQGesture::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTapAndHoldGesture::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTapAndHoldGesture::slot_map->bigin();
	if ((itr = DummyQTapAndHoldGesture::slot_map->find(str)) == DummyQTapAndHoldGesture::slot_map->end()) {
		bool ret = false;
		ret = DummyQGesture::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQTapAndHoldGesture::connection(QObject *o)
{
	DummyQGesture::connection(o);
}

KQTapAndHoldGesture::KQTapAndHoldGesture() : QTapAndHoldGesture()
{
	self = NULL;
	dummy = new DummyQTapAndHoldGesture();
	dummy->connection((QObject*)this);
}

KMETHOD QTapAndHoldGesture_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTapAndHoldGesture *qp = RawPtr_to(KQTapAndHoldGesture *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTapAndHoldGesture]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTapAndHoldGesture]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTapAndHoldGesture_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTapAndHoldGesture *qp = RawPtr_to(KQTapAndHoldGesture *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTapAndHoldGesture]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTapAndHoldGesture]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTapAndHoldGesture_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTapAndHoldGesture *qp = (KQTapAndHoldGesture *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTapAndHoldGesture_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQTapAndHoldGesture *qp = (KQTapAndHoldGesture *)p->rawptr;
		(void)qp;
	}
}

static int QTapAndHoldGesture_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTapAndHoldGesture::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQTapAndHoldGesture::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QTapAndHoldGesture::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQTapAndHoldGesture(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTapAndHoldGesture";
	cdef->free = QTapAndHoldGesture_free;
	cdef->reftrace = QTapAndHoldGesture_reftrace;
	cdef->compareTo = QTapAndHoldGesture_compareTo;
}


