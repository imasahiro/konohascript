//QGraphicsColorizeEffect QGraphicsColorizeEffect.new(QObject parent);
KMETHOD QGraphicsColorizeEffect_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQGraphicsColorizeEffect *ret_v = new KQGraphicsColorizeEffect(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QColor QGraphicsColorizeEffect.getColor();
KMETHOD QGraphicsColorizeEffect_getColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsColorizeEffect *  qp = RawPtr_to(QGraphicsColorizeEffect *, sfp[0]);
	if (qp != NULL) {
		QColor ret_v = qp->color();
		QColor *ret_v_ = new QColor(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QGraphicsColorizeEffect.getStrength();
KMETHOD QGraphicsColorizeEffect_getStrength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsColorizeEffect *  qp = RawPtr_to(QGraphicsColorizeEffect *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->strength();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QGraphicsColorizeEffect.setColor(QColor c);
KMETHOD QGraphicsColorizeEffect_setColor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsColorizeEffect *  qp = RawPtr_to(QGraphicsColorizeEffect *, sfp[0]);
	if (qp != NULL) {
		const QColor  c = *RawPtr_to(const QColor *, sfp[1]);
		qp->setColor(c);
	}
	RETURNvoid_();
}

//void QGraphicsColorizeEffect.setStrength(float strength);
KMETHOD QGraphicsColorizeEffect_setStrength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsColorizeEffect *  qp = RawPtr_to(QGraphicsColorizeEffect *, sfp[0]);
	if (qp != NULL) {
		qreal strength = Float_to(qreal, sfp[1]);
		qp->setStrength(strength);
	}
	RETURNvoid_();
}


DummyQGraphicsColorizeEffect::DummyQGraphicsColorizeEffect()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGraphicsColorizeEffect::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsColorizeEffect::self = ptr;
	DummyQGraphicsEffect::setSelf(ptr);
}

bool DummyQGraphicsColorizeEffect::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsEffect::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsColorizeEffect::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsColorizeEffect::event_map->bigin();
	if ((itr = DummyQGraphicsColorizeEffect::event_map->find(str)) == DummyQGraphicsColorizeEffect::event_map->end()) {
		bool ret;
		ret = DummyQGraphicsEffect::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsColorizeEffect::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsColorizeEffect::slot_map->bigin();
	if ((itr = DummyQGraphicsColorizeEffect::event_map->find(str)) == DummyQGraphicsColorizeEffect::slot_map->end()) {
		bool ret;
		ret = DummyQGraphicsEffect::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQGraphicsColorizeEffect::KQGraphicsColorizeEffect(QObject* parent) : QGraphicsColorizeEffect(parent)
{
	self = NULL;
}

KMETHOD QGraphicsColorizeEffect_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsColorizeEffect *qp = RawPtr_to(KQGraphicsColorizeEffect *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsColorizeEffect]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQGraphicsColorizeEffect::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsColorizeEffect]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QGraphicsColorizeEffect_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsColorizeEffect *qp = RawPtr_to(KQGraphicsColorizeEffect *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsColorizeEffect]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQGraphicsColorizeEffect::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsColorizeEffect]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsColorizeEffect_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsColorizeEffect *qp = (KQGraphicsColorizeEffect *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsColorizeEffect_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQGraphicsColorizeEffect *qp = (KQGraphicsColorizeEffect *)p->rawptr;
		(void)qp;
	}
}

static int QGraphicsColorizeEffect_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQGraphicsColorizeEffect::event(QEvent *event)
{
	if (!DummyQGraphicsColorizeEffect::eventDispatcher(event)) {
		QGraphicsColorizeEffect::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQGraphicsColorizeEffect(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsColorizeEffect";
	cdef->free = QGraphicsColorizeEffect_free;
	cdef->reftrace = QGraphicsColorizeEffect_reftrace;
	cdef->compareTo = QGraphicsColorizeEffect_compareTo;
}


