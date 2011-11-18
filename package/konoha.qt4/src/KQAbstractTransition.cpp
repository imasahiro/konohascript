//
//void QAbstractTransition.addAnimation(QAbstractAnimation animation);
KMETHOD QAbstractTransition_addAnimation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTransition *  qp = RawPtr_to(QAbstractTransition *, sfp[0]);
	if (qp) {
		QAbstractAnimation*  animation = RawPtr_to(QAbstractAnimation*, sfp[1]);
		qp->addAnimation(animation);
	}
	RETURNvoid_();
}

//Array<QAbstractAnimation> QAbstractTransition.animations();
KMETHOD QAbstractTransition_animations(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTransition *  qp = RawPtr_to(QAbstractTransition *, sfp[0]);
	if (qp) {
		QList<QAbstractAnimation*> ret_v = qp->animations();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QAbstractAnimation"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//QStateMachine QAbstractTransition.machine();
KMETHOD QAbstractTransition_machine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTransition *  qp = RawPtr_to(QAbstractTransition *, sfp[0]);
	if (qp) {
		QStateMachine* ret_v = qp->machine();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QStateMachine*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QAbstractTransition.removeAnimation(QAbstractAnimation animation);
KMETHOD QAbstractTransition_removeAnimation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTransition *  qp = RawPtr_to(QAbstractTransition *, sfp[0]);
	if (qp) {
		QAbstractAnimation*  animation = RawPtr_to(QAbstractAnimation*, sfp[1]);
		qp->removeAnimation(animation);
	}
	RETURNvoid_();
}

//void QAbstractTransition.setTargetState(QAbstractState target);
KMETHOD QAbstractTransition_setTargetState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTransition *  qp = RawPtr_to(QAbstractTransition *, sfp[0]);
	if (qp) {
		QAbstractState*  target = RawPtr_to(QAbstractState*, sfp[1]);
		qp->setTargetState(target);
	}
	RETURNvoid_();
}

//void QAbstractTransition.setTargetStates(Array<QAbstractState> targets);
KMETHOD QAbstractTransition_setTargetStates(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTransition *  qp = RawPtr_to(QAbstractTransition *, sfp[0]);
	if (qp) {
		knh_Array_t *a = sfp[1].a;
		int asize = knh_Array_size(a);
		QList<QAbstractState*> targets;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			targets.append((QAbstractState*)p->rawptr);
		}
		qp->setTargetStates(targets);
	}
	RETURNvoid_();
}

//QState QAbstractTransition.sourceState();
KMETHOD QAbstractTransition_sourceState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTransition *  qp = RawPtr_to(QAbstractTransition *, sfp[0]);
	if (qp) {
		QState* ret_v = qp->sourceState();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QState*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAbstractState QAbstractTransition.getTargetState();
KMETHOD QAbstractTransition_getTargetState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTransition *  qp = RawPtr_to(QAbstractTransition *, sfp[0]);
	if (qp) {
		QAbstractState* ret_v = qp->targetState();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractState*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<QAbstractState> QAbstractTransition.getTargetStates();
KMETHOD QAbstractTransition_getTargetStates(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractTransition *  qp = RawPtr_to(QAbstractTransition *, sfp[0]);
	if (qp) {
		QList<QAbstractState*> ret_v = qp->targetStates();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QAbstractState"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	


DummyQAbstractTransition::DummyQAbstractTransition()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	triggered_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("triggered", NULL));
}
DummyQAbstractTransition::~DummyQAbstractTransition()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQAbstractTransition::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractTransition::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQAbstractTransition::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAbstractTransition::triggeredSlot()
{
	if (triggered_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, triggered_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQAbstractTransition::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractTransition::event_map->bigin();
	if ((itr = DummyQAbstractTransition::event_map->find(str)) == DummyQAbstractTransition::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractTransition::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractTransition::slot_map->bigin();
	if ((itr = DummyQAbstractTransition::slot_map->find(str)) == DummyQAbstractTransition::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		triggered_func = (*slot_map)["triggered"];
		return true;
	}
}

knh_Object_t** DummyQAbstractTransition::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQAbstractTransition::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, triggered_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQAbstractTransition::connection(QObject *o)
{
	QAbstractTransition *p = dynamic_cast<QAbstractTransition*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(triggered()), this, SLOT(triggeredSlot()));
	}
	DummyQObject::connection(o);
}

KQAbstractTransition::KQAbstractTransition(QState* sourceState) : QAbstractTransition(sourceState)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQAbstractTransition();
	dummy->connection((QObject*)this);
}

KQAbstractTransition::~KQAbstractTransition()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QAbstractTransition_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractTransition *qp = RawPtr_to(KQAbstractTransition *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractTransition]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractTransition]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAbstractTransition_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractTransition *qp = RawPtr_to(KQAbstractTransition *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractTransition]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractTransition]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractTransition_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQAbstractTransition *qp = (KQAbstractTransition *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QAbstractTransition*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QAbstractTransition_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQAbstractTransition *qp = (KQAbstractTransition *)p->rawptr;
		KQAbstractTransition *qp = static_cast<KQAbstractTransition*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QAbstractTransition_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAbstractTransition::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQAbstractTransition::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QAbstractTransition::event(event);
		return false;
	}
//	QAbstractTransition::event(event);
	return true;
}



DEFAPI(void) defQAbstractTransition(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractTransition";
	cdef->free = QAbstractTransition_free;
	cdef->reftrace = QAbstractTransition_reftrace;
	cdef->compareTo = QAbstractTransition_compareTo;
}


