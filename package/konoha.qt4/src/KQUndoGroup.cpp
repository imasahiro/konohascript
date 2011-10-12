//QUndoGroup QUndoGroup.new(QObject parent);
KMETHOD QUndoGroup_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQUndoGroup *ret_v = new KQUndoGroup(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QUndoStack QUndoGroup.getActiveStack();
KMETHOD QUndoGroup_getActiveStack(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoGroup *  qp = RawPtr_to(QUndoGroup *, sfp[0]);
	if (qp != NULL) {
		QUndoStack* ret_v = qp->activeStack();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QUndoStack*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QUndoGroup.addStack(QUndoStack stack);
KMETHOD QUndoGroup_addStack(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoGroup *  qp = RawPtr_to(QUndoGroup *, sfp[0]);
	if (qp != NULL) {
		QUndoStack*  stack = RawPtr_to(QUndoStack*, sfp[1]);
		qp->addStack(stack);
	}
	RETURNvoid_();
}

//boolean QUndoGroup.canRedo();
KMETHOD QUndoGroup_canRedo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoGroup *  qp = RawPtr_to(QUndoGroup *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->canRedo();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QUndoGroup.canUndo();
KMETHOD QUndoGroup_canUndo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoGroup *  qp = RawPtr_to(QUndoGroup *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->canUndo();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QAction QUndoGroup.createRedoAction(QObject parent, String prefix);
KMETHOD QUndoGroup_createRedoAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoGroup *  qp = RawPtr_to(QUndoGroup *, sfp[0]);
	if (qp != NULL) {
		QObject*  parent = RawPtr_to(QObject*, sfp[1]);
		const QString prefix = String_to(const QString, sfp[2]);
		QAction* ret_v = qp->createRedoAction(parent, prefix);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAction QUndoGroup.createUndoAction(QObject parent, String prefix);
KMETHOD QUndoGroup_createUndoAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoGroup *  qp = RawPtr_to(QUndoGroup *, sfp[0]);
	if (qp != NULL) {
		QObject*  parent = RawPtr_to(QObject*, sfp[1]);
		const QString prefix = String_to(const QString, sfp[2]);
		QAction* ret_v = qp->createUndoAction(parent, prefix);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QUndoGroup.isClean();
KMETHOD QUndoGroup_isClean(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoGroup *  qp = RawPtr_to(QUndoGroup *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isClean();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QUndoGroup.redoText();
KMETHOD QUndoGroup_redoText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoGroup *  qp = RawPtr_to(QUndoGroup *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->redoText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QUndoGroup.removeStack(QUndoStack stack);
KMETHOD QUndoGroup_removeStack(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoGroup *  qp = RawPtr_to(QUndoGroup *, sfp[0]);
	if (qp != NULL) {
		QUndoStack*  stack = RawPtr_to(QUndoStack*, sfp[1]);
		qp->removeStack(stack);
	}
	RETURNvoid_();
}

//Array<QUndoStack> QUndoGroup.stacks();
KMETHOD QUndoGroup_stacks(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoGroup *  qp = RawPtr_to(QUndoGroup *, sfp[0]);
	if (qp != NULL) {
		QList<QUndoStack*>ret_v = qp->stacks();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QUndoStack"));
		for (int n = 0; n < list_size; n++) {
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v[n]);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//String QUndoGroup.undoText();
KMETHOD QUndoGroup_undoText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoGroup *  qp = RawPtr_to(QUndoGroup *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->undoText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QUndoGroup.redo();
KMETHOD QUndoGroup_redo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoGroup *  qp = RawPtr_to(QUndoGroup *, sfp[0]);
	if (qp != NULL) {
		qp->redo();
	}
	RETURNvoid_();
}

//void QUndoGroup.setActiveStack(QUndoStack stack);
KMETHOD QUndoGroup_setActiveStack(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoGroup *  qp = RawPtr_to(QUndoGroup *, sfp[0]);
	if (qp != NULL) {
		QUndoStack*  stack = RawPtr_to(QUndoStack*, sfp[1]);
		qp->setActiveStack(stack);
	}
	RETURNvoid_();
}

//void QUndoGroup.undo();
KMETHOD QUndoGroup_undo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoGroup *  qp = RawPtr_to(QUndoGroup *, sfp[0]);
	if (qp != NULL) {
		qp->undo();
	}
	RETURNvoid_();
}


DummyQUndoGroup::DummyQUndoGroup()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQUndoGroup::setSelf(knh_RawPtr_t *ptr)
{
	DummyQUndoGroup::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQUndoGroup::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQUndoGroup::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQUndoGroup::event_map->bigin();
	if ((itr = DummyQUndoGroup::event_map->find(str)) == DummyQUndoGroup::event_map->end()) {
		bool ret;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQUndoGroup::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQUndoGroup::slot_map->bigin();
	if ((itr = DummyQUndoGroup::event_map->find(str)) == DummyQUndoGroup::slot_map->end()) {
		bool ret;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQUndoGroup::KQUndoGroup(QObject* parent) : QUndoGroup(parent)
{
	self = NULL;
}

KMETHOD QUndoGroup_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQUndoGroup *qp = RawPtr_to(KQUndoGroup *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QUndoGroup]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQUndoGroup::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QUndoGroup]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QUndoGroup_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQUndoGroup *qp = RawPtr_to(KQUndoGroup *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QUndoGroup]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQUndoGroup::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QUndoGroup]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QUndoGroup_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQUndoGroup *qp = (KQUndoGroup *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QUndoGroup_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQUndoGroup *qp = (KQUndoGroup *)p->rawptr;
		(void)qp;
	}
}

static int QUndoGroup_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQUndoGroup::event(QEvent *event)
{
	if (!DummyQUndoGroup::eventDispatcher(event)) {
		QUndoGroup::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQUndoGroup(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QUndoGroup";
	cdef->free = QUndoGroup_free;
	cdef->reftrace = QUndoGroup_reftrace;
	cdef->compareTo = QUndoGroup_compareTo;
}


