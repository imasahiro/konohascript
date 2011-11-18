//QUndoGroup QUndoGroup.new(QObject parent);
KMETHOD QUndoGroup_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQUndoGroup *ret_v = new KQUndoGroup(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QUndoStack QUndoGroup.getActiveStack();
KMETHOD QUndoGroup_getActiveStack(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoGroup *  qp = RawPtr_to(QUndoGroup *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		QList<QUndoStack*> ret_v = qp->stacks();
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
	if (qp) {
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
	if (qp) {
		qp->redo();
	}
	RETURNvoid_();
}

//void QUndoGroup.setActiveStack(QUndoStack stack);
KMETHOD QUndoGroup_setActiveStack(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoGroup *  qp = RawPtr_to(QUndoGroup *, sfp[0]);
	if (qp) {
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
	if (qp) {
		qp->undo();
	}
	RETURNvoid_();
}


DummyQUndoGroup::DummyQUndoGroup()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	active_stack_changed_func = NULL;
	can_redo_changed_func = NULL;
	can_undo_changed_func = NULL;
	clean_changed_func = NULL;
	index_changed_func = NULL;
	redo_text_changed_func = NULL;
	undo_text_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("active-stack-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("can-redo-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("can-undo-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("clean-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("index-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("redo-text-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("undo-text-changed", NULL));
}
DummyQUndoGroup::~DummyQUndoGroup()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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

bool DummyQUndoGroup::activeStackChangedSlot(QUndoStack* stack)
{
	if (active_stack_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QUndoStack, stack);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, active_stack_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQUndoGroup::canRedoChangedSlot(bool canRedo)
{
	if (can_redo_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = canRedo;
		knh_Func_invoke(lctx, can_redo_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQUndoGroup::canUndoChangedSlot(bool canUndo)
{
	if (can_undo_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = canUndo;
		knh_Func_invoke(lctx, can_undo_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQUndoGroup::cleanChangedSlot(bool clean)
{
	if (clean_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = clean;
		knh_Func_invoke(lctx, clean_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQUndoGroup::indexChangedSlot(int idx)
{
	if (index_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = idx;
		knh_Func_invoke(lctx, index_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQUndoGroup::redoTextChangedSlot(const QString redoText)
{
	if (redo_text_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QString, redoText);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, redo_text_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQUndoGroup::undoTextChangedSlot(const QString undoText)
{
	if (undo_text_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QString, undoText);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, undo_text_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQUndoGroup::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQUndoGroup::event_map->bigin();
	if ((itr = DummyQUndoGroup::event_map->find(str)) == DummyQUndoGroup::event_map->end()) {
		bool ret = false;
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
	if ((itr = DummyQUndoGroup::slot_map->find(str)) == DummyQUndoGroup::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		active_stack_changed_func = (*slot_map)["active-stack-changed"];
		can_redo_changed_func = (*slot_map)["can-redo-changed"];
		can_undo_changed_func = (*slot_map)["can-undo-changed"];
		clean_changed_func = (*slot_map)["clean-changed"];
		index_changed_func = (*slot_map)["index-changed"];
		redo_text_changed_func = (*slot_map)["redo-text-changed"];
		undo_text_changed_func = (*slot_map)["undo-text-changed"];
		return true;
	}
}

knh_Object_t** DummyQUndoGroup::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQUndoGroup::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 8;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, active_stack_changed_func);
	KNH_ADDNNREF(ctx, can_redo_changed_func);
	KNH_ADDNNREF(ctx, can_undo_changed_func);
	KNH_ADDNNREF(ctx, clean_changed_func);
	KNH_ADDNNREF(ctx, index_changed_func);
	KNH_ADDNNREF(ctx, redo_text_changed_func);
	KNH_ADDNNREF(ctx, undo_text_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQUndoGroup::connection(QObject *o)
{
	QUndoGroup *p = dynamic_cast<QUndoGroup*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(activeStackChanged(QUndoStack*)), this, SLOT(activeStackChangedSlot(QUndoStack*)));
		connect(p, SIGNAL(canRedoChanged(bool)), this, SLOT(canRedoChangedSlot(bool)));
		connect(p, SIGNAL(canUndoChanged(bool)), this, SLOT(canUndoChangedSlot(bool)));
		connect(p, SIGNAL(cleanChanged(bool)), this, SLOT(cleanChangedSlot(bool)));
		connect(p, SIGNAL(indexChanged(int)), this, SLOT(indexChangedSlot(int)));
		connect(p, SIGNAL(redoTextChanged(const QString)), this, SLOT(redoTextChangedSlot(const QString)));
		connect(p, SIGNAL(undoTextChanged(const QString)), this, SLOT(undoTextChangedSlot(const QString)));
	}
	DummyQObject::connection(o);
}

KQUndoGroup::KQUndoGroup(QObject* parent) : QUndoGroup(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQUndoGroup();
	dummy->connection((QObject*)this);
}

KQUndoGroup::~KQUndoGroup()
{
	delete dummy;
	dummy = NULL;
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QUndoGroup]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QUndoGroup_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQUndoGroup *qp = (KQUndoGroup *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QUndoGroup*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QUndoGroup_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQUndoGroup *qp = (KQUndoGroup *)p->rawptr;
		KQUndoGroup *qp = static_cast<KQUndoGroup*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QUndoGroup_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQUndoGroup::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQUndoGroup::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QUndoGroup::event(event);
		return false;
	}
//	QUndoGroup::event(event);
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


