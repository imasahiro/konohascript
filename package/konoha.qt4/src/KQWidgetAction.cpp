//QWidgetAction QWidgetAction.new(QObject parent);
KMETHOD QWidgetAction_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQWidgetAction *ret_v = new KQWidgetAction(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QWidget QWidgetAction.getDefaultWidget();
KMETHOD QWidgetAction_getDefaultWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidgetAction *  qp = RawPtr_to(QWidgetAction *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->defaultWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWidgetAction.releaseWidget(QWidget widget);
KMETHOD QWidgetAction_releaseWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidgetAction *  qp = RawPtr_to(QWidgetAction *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->releaseWidget(widget);
	}
	RETURNvoid_();
}

//QWidget QWidgetAction.requestWidget(QWidget parent);
KMETHOD QWidgetAction_requestWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidgetAction *  qp = RawPtr_to(QWidgetAction *, sfp[0]);
	if (qp) {
		QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
		QWidget* ret_v = qp->requestWidget(parent);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QWidgetAction.setDefaultWidget(QWidget widget);
KMETHOD QWidgetAction_setDefaultWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidgetAction *  qp = RawPtr_to(QWidgetAction *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setDefaultWidget(widget);
	}
	RETURNvoid_();
}


DummyQWidgetAction::DummyQWidgetAction()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQWidgetAction::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWidgetAction::self = ptr;
	DummyQAction::setSelf(ptr);
}

bool DummyQWidgetAction::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAction::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQWidgetAction::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWidgetAction::event_map->bigin();
	if ((itr = DummyQWidgetAction::event_map->find(str)) == DummyQWidgetAction::event_map->end()) {
		bool ret = false;
		ret = DummyQAction::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWidgetAction::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWidgetAction::slot_map->bigin();
	if ((itr = DummyQWidgetAction::slot_map->find(str)) == DummyQWidgetAction::slot_map->end()) {
		bool ret = false;
		ret = DummyQAction::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQWidgetAction::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQAction::reftrace(ctx, p, tail_);
}

void DummyQWidgetAction::connection(QObject *o)
{
	QWidgetAction *p = dynamic_cast<QWidgetAction*>(o);
	if (p != NULL) {
	}
	DummyQAction::connection(o);
}

KQWidgetAction::KQWidgetAction(QObject* parent) : QWidgetAction(parent)
{
	self = NULL;
	dummy = new DummyQWidgetAction();
	dummy->connection((QObject*)this);
}

KMETHOD QWidgetAction_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWidgetAction *qp = RawPtr_to(KQWidgetAction *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWidgetAction]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWidgetAction]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWidgetAction_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWidgetAction *qp = RawPtr_to(KQWidgetAction *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWidgetAction]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWidgetAction]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWidgetAction_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWidgetAction *qp = (KQWidgetAction *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWidgetAction_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQWidgetAction *qp = (KQWidgetAction *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QWidgetAction_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWidgetAction::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQWidgetAction::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QWidgetAction::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQWidgetAction(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWidgetAction";
	cdef->free = QWidgetAction_free;
	cdef->reftrace = QWidgetAction_reftrace;
	cdef->compareTo = QWidgetAction_compareTo;
}


