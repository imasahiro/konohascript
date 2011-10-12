//QActionGroup QActionGroup.new(QObject parent);
KMETHOD QActionGroup_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQActionGroup *ret_v = new KQActionGroup(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//Array<QAction> QActionGroup.actions();
KMETHOD QActionGroup_actions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QActionGroup *  qp = RawPtr_to(QActionGroup *, sfp[0]);
	if (qp != NULL) {
		QList<QAction*>ret_v = qp->actions();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QAction"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

////QAction QActionGroup.addAction(QAction action);
KMETHOD QActionGroup_addAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QActionGroup *  qp = RawPtr_to(QActionGroup *, sfp[0]);
	if (qp != NULL) {
		QAction*  action = RawPtr_to(QAction*, sfp[1]);
		QAction* ret_v = qp->addAction(action);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
////QAction QActionGroup.addAction(String text);
KMETHOD QActionGroup_addAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QActionGroup *  qp = RawPtr_to(QActionGroup *, sfp[0]);
	if (qp != NULL) {
		const QString text = String_to(const QString, sfp[1]);
		QAction* ret_v = qp->addAction(text);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
////QAction QActionGroup.addAction(QIcon icon, String text);
KMETHOD QActionGroup_addAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QActionGroup *  qp = RawPtr_to(QActionGroup *, sfp[0]);
	if (qp != NULL) {
		const QIcon  icon = *RawPtr_to(const QIcon *, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		QAction* ret_v = qp->addAction(icon, text);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QAction QActionGroup.checkedAction();
KMETHOD QActionGroup_checkedAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QActionGroup *  qp = RawPtr_to(QActionGroup *, sfp[0]);
	if (qp != NULL) {
		QAction* ret_v = qp->checkedAction();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QActionGroup.isEnabled();
KMETHOD QActionGroup_isEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QActionGroup *  qp = RawPtr_to(QActionGroup *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QActionGroup.isExclusive();
KMETHOD QActionGroup_isExclusive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QActionGroup *  qp = RawPtr_to(QActionGroup *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isExclusive();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QActionGroup.isVisible();
KMETHOD QActionGroup_isVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QActionGroup *  qp = RawPtr_to(QActionGroup *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isVisible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QActionGroup.removeAction(QAction action);
KMETHOD QActionGroup_removeAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QActionGroup *  qp = RawPtr_to(QActionGroup *, sfp[0]);
	if (qp != NULL) {
		QAction*  action = RawPtr_to(QAction*, sfp[1]);
		qp->removeAction(action);
	}
	RETURNvoid_();
}

//void QActionGroup.setDisabled(boolean b);
KMETHOD QActionGroup_setDisabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QActionGroup *  qp = RawPtr_to(QActionGroup *, sfp[0]);
	if (qp != NULL) {
		bool b = Boolean_to(bool, sfp[1]);
		qp->setDisabled(b);
	}
	RETURNvoid_();
}

//void QActionGroup.setEnabled(boolean arg0);
KMETHOD QActionGroup_setEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QActionGroup *  qp = RawPtr_to(QActionGroup *, sfp[0]);
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setEnabled(arg0);
	}
	RETURNvoid_();
}

//void QActionGroup.setExclusive(boolean arg0);
KMETHOD QActionGroup_setExclusive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QActionGroup *  qp = RawPtr_to(QActionGroup *, sfp[0]);
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setExclusive(arg0);
	}
	RETURNvoid_();
}

//void QActionGroup.setVisible(boolean arg0);
KMETHOD QActionGroup_setVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QActionGroup *  qp = RawPtr_to(QActionGroup *, sfp[0]);
	if (qp != NULL) {
		bool arg0 = Boolean_to(bool, sfp[1]);
		qp->setVisible(arg0);
	}
	RETURNvoid_();
}


DummyQActionGroup::DummyQActionGroup()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQActionGroup::setSelf(knh_RawPtr_t *ptr)
{
	DummyQActionGroup::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQActionGroup::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQActionGroup::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQActionGroup::event_map->bigin();
	if ((itr = DummyQActionGroup::event_map->find(str)) == DummyQActionGroup::event_map->end()) {
		bool ret;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQActionGroup::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQActionGroup::slot_map->bigin();
	if ((itr = DummyQActionGroup::event_map->find(str)) == DummyQActionGroup::slot_map->end()) {
		bool ret;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQActionGroup::KQActionGroup(QObject* parent) : QActionGroup(parent)
{
	self = NULL;
}

KMETHOD QActionGroup_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQActionGroup *qp = RawPtr_to(KQActionGroup *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QActionGroup]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQActionGroup::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QActionGroup]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QActionGroup_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQActionGroup *qp = RawPtr_to(KQActionGroup *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QActionGroup]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQActionGroup::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QActionGroup]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QActionGroup_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQActionGroup *qp = (KQActionGroup *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QActionGroup_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQActionGroup *qp = (KQActionGroup *)p->rawptr;
		(void)qp;
	}
}

static int QActionGroup_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQActionGroup::event(QEvent *event)
{
	if (!DummyQActionGroup::eventDispatcher(event)) {
		QActionGroup::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQActionGroup(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QActionGroup";
	cdef->free = QActionGroup_free;
	cdef->reftrace = QActionGroup_reftrace;
	cdef->compareTo = QActionGroup_compareTo;
}


