//QUndoStack QUndoStack.new(QObject parent);
KMETHOD QUndoStack_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQUndoStack *ret_v = new KQUndoStack(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QUndoStack.beginMacro(String text);
KMETHOD QUndoStack_beginMacro(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->beginMacro(text);
	}
	RETURNvoid_();
}

//boolean QUndoStack.canRedo();
KMETHOD QUndoStack_canRedo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		bool ret_v = qp->canRedo();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QUndoStack.canUndo();
KMETHOD QUndoStack_canUndo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		bool ret_v = qp->canUndo();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QUndoStack.cleanIndex();
KMETHOD QUndoStack_cleanIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		int ret_v = qp->cleanIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QUndoStack.clear();
KMETHOD QUndoStack_clear(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		qp->clear();
	}
	RETURNvoid_();
}

//QUndoCommand QUndoStack.command(int index);
KMETHOD QUndoStack_command(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		const QUndoCommand* ret_v = qp->command(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QUndoCommand*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QUndoStack.count();
KMETHOD QUndoStack_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QAction QUndoStack.createRedoAction(QObject parent, String prefix);
KMETHOD QUndoStack_createRedoAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
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

//QAction QUndoStack.createUndoAction(QObject parent, String prefix);
KMETHOD QUndoStack_createUndoAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
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

//void QUndoStack.endMacro();
KMETHOD QUndoStack_endMacro(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		qp->endMacro();
	}
	RETURNvoid_();
}

//int QUndoStack.getIndex();
KMETHOD QUndoStack_getIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		int ret_v = qp->index();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QUndoStack.isActive();
KMETHOD QUndoStack_isActive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isActive();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QUndoStack.isClean();
KMETHOD QUndoStack_isClean(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isClean();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QUndoStack.push(QUndoCommand cmd);
KMETHOD QUndoStack_push(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		QUndoCommand*  cmd = RawPtr_to(QUndoCommand*, sfp[1]);
		qp->push(cmd);
	}
	RETURNvoid_();
}

//String QUndoStack.redoText();
KMETHOD QUndoStack_redoText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		QString ret_v = qp->redoText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QUndoStack.setUndoLimit(int limit);
KMETHOD QUndoStack_setUndoLimit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		int limit = Int_to(int, sfp[1]);
		qp->setUndoLimit(limit);
	}
	RETURNvoid_();
}

//String QUndoStack.text(int idx);
KMETHOD QUndoStack_text(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		int idx = Int_to(int, sfp[1]);
		QString ret_v = qp->text(idx);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QUndoStack.getUndoLimit();
KMETHOD QUndoStack_getUndoLimit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		int ret_v = qp->undoLimit();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QUndoStack.undoText();
KMETHOD QUndoStack_undoText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		QString ret_v = qp->undoText();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QUndoStack.redo();
KMETHOD QUndoStack_redo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		qp->redo();
	}
	RETURNvoid_();
}

//void QUndoStack.setActive(boolean active);
KMETHOD QUndoStack_setActive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		bool active = Boolean_to(bool, sfp[1]);
		qp->setActive(active);
	}
	RETURNvoid_();
}

//void QUndoStack.setClean();
KMETHOD QUndoStack_setClean(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		qp->setClean();
	}
	RETURNvoid_();
}

//void QUndoStack.setIndex(int idx);
KMETHOD QUndoStack_setIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		int idx = Int_to(int, sfp[1]);
		qp->setIndex(idx);
	}
	RETURNvoid_();
}

//void QUndoStack.undo();
KMETHOD QUndoStack_undo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoStack *  qp = RawPtr_to(QUndoStack *, sfp[0]);
	if (qp) {
		qp->undo();
	}
	RETURNvoid_();
}


DummyQUndoStack::DummyQUndoStack()
{
	self = NULL;
	can_redo_changed_func = NULL;
	can_undo_changed_func = NULL;
	clean_changed_func = NULL;
	index_changed_func = NULL;
	redo_text_changed_func = NULL;
	undo_text_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("can-redo-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("can-undo-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("clean-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("index-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("redo-text-changed", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("undo-text-changed", NULL));
}

void DummyQUndoStack::setSelf(knh_RawPtr_t *ptr)
{
	DummyQUndoStack::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQUndoStack::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQUndoStack::canRedoChangedSlot(bool canRedo)
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

bool DummyQUndoStack::canUndoChangedSlot(bool canUndo)
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

bool DummyQUndoStack::cleanChangedSlot(bool clean)
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

bool DummyQUndoStack::indexChangedSlot(int idx)
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

bool DummyQUndoStack::redoTextChangedSlot(const QString redoText)
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

bool DummyQUndoStack::undoTextChangedSlot(const QString undoText)
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

bool DummyQUndoStack::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQUndoStack::event_map->bigin();
	if ((itr = DummyQUndoStack::event_map->find(str)) == DummyQUndoStack::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQUndoStack::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQUndoStack::slot_map->bigin();
	if ((itr = DummyQUndoStack::slot_map->find(str)) == DummyQUndoStack::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		can_redo_changed_func = (*slot_map)["can-redo-changed"];
		can_undo_changed_func = (*slot_map)["can-undo-changed"];
		clean_changed_func = (*slot_map)["clean-changed"];
		index_changed_func = (*slot_map)["index-changed"];
		redo_text_changed_func = (*slot_map)["redo-text-changed"];
		undo_text_changed_func = (*slot_map)["undo-text-changed"];
		return true;
	}
}

void DummyQUndoStack::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 6;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, can_redo_changed_func);
	KNH_ADDNNREF(ctx, can_undo_changed_func);
	KNH_ADDNNREF(ctx, clean_changed_func);
	KNH_ADDNNREF(ctx, index_changed_func);
	KNH_ADDNNREF(ctx, redo_text_changed_func);
	KNH_ADDNNREF(ctx, undo_text_changed_func);

	KNH_SIZEREF(ctx);

	DummyQObject::reftrace(ctx, p, tail_);
}

void DummyQUndoStack::connection(QObject *o)
{
	QUndoStack *p = dynamic_cast<QUndoStack*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(canRedoChanged(bool)), this, SLOT(canRedoChangedSlot(bool)));
		connect(p, SIGNAL(canUndoChanged(bool)), this, SLOT(canUndoChangedSlot(bool)));
		connect(p, SIGNAL(cleanChanged(bool)), this, SLOT(cleanChangedSlot(bool)));
		connect(p, SIGNAL(indexChanged(int)), this, SLOT(indexChangedSlot(int)));
		connect(p, SIGNAL(redoTextChanged(const QString)), this, SLOT(redoTextChangedSlot(const QString)));
		connect(p, SIGNAL(undoTextChanged(const QString)), this, SLOT(undoTextChangedSlot(const QString)));
	}
	DummyQObject::connection(o);
}

KQUndoStack::KQUndoStack(QObject* parent) : QUndoStack(parent)
{
	self = NULL;
	dummy = new DummyQUndoStack();
	dummy->connection((QObject*)this);
}

KMETHOD QUndoStack_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQUndoStack *qp = RawPtr_to(KQUndoStack *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QUndoStack]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QUndoStack]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QUndoStack_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQUndoStack *qp = RawPtr_to(KQUndoStack *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QUndoStack]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QUndoStack]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QUndoStack_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQUndoStack *qp = (KQUndoStack *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QUndoStack_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQUndoStack *qp = (KQUndoStack *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QUndoStack_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQUndoStack::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQUndoStack::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QUndoStack::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQUndoStack(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QUndoStack";
	cdef->free = QUndoStack_free;
	cdef->reftrace = QUndoStack_reftrace;
	cdef->compareTo = QUndoStack_compareTo;
}


