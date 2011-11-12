//QUndoCommand QUndoCommand.new(QUndoCommand parent);
KMETHOD QUndoCommand_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoCommand*  parent = RawPtr_to(QUndoCommand*, sfp[1]);
	KQUndoCommand *ret_v = new KQUndoCommand(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QUndoCommand QUndoCommand.new(String text, QUndoCommand parent);
KMETHOD QUndoCommand_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString text = String_to(const QString, sfp[1]);
	QUndoCommand*  parent = RawPtr_to(QUndoCommand*, sfp[2]);
	KQUndoCommand *ret_v = new KQUndoCommand(text, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QUndoCommand QUndoCommand.child(int index);
KMETHOD QUndoCommand_child(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoCommand *  qp = RawPtr_to(QUndoCommand *, sfp[0]);
	if (qp) {
		int index = Int_to(int, sfp[1]);
		const QUndoCommand* ret_v = qp->child(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QUndoCommand*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QUndoCommand.childCount();
KMETHOD QUndoCommand_childCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoCommand *  qp = RawPtr_to(QUndoCommand *, sfp[0]);
	if (qp) {
		int ret_v = qp->childCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual int QUndoCommand.id();
KMETHOD QUndoCommand_id(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoCommand *  qp = RawPtr_to(QUndoCommand *, sfp[0]);
	if (qp) {
		int ret_v = qp->id();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual boolean QUndoCommand.mergeWith(QUndoCommand command);
KMETHOD QUndoCommand_mergeWith(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoCommand *  qp = RawPtr_to(QUndoCommand *, sfp[0]);
	if (qp) {
		const QUndoCommand*  command = RawPtr_to(const QUndoCommand*, sfp[1]);
		bool ret_v = qp->mergeWith(command);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual void QUndoCommand.redo();
KMETHOD QUndoCommand_redo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoCommand *  qp = RawPtr_to(QUndoCommand *, sfp[0]);
	if (qp) {
		qp->redo();
	}
	RETURNvoid_();
}

//void QUndoCommand.setText(String text);
KMETHOD QUndoCommand_setText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoCommand *  qp = RawPtr_to(QUndoCommand *, sfp[0]);
	if (qp) {
		const QString text = String_to(const QString, sfp[1]);
		qp->setText(text);
	}
	RETURNvoid_();
}

//String QUndoCommand.getText();
KMETHOD QUndoCommand_getText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoCommand *  qp = RawPtr_to(QUndoCommand *, sfp[0]);
	if (qp) {
		QString ret_v = qp->text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual void QUndoCommand.undo();
KMETHOD QUndoCommand_undo(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoCommand *  qp = RawPtr_to(QUndoCommand *, sfp[0]);
	if (qp) {
		qp->undo();
	}
	RETURNvoid_();
}

//Array<String> QUndoCommand.parents();
KMETHOD QUndoCommand_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUndoCommand *qp = RawPtr_to(QUndoCommand*, sfp[0]);
	if (qp != NULL) {
		int size = 10;
		knh_Array_t *a = new_Array0(ctx, size);
		const knh_ClassTBL_t *ct = sfp[0].p->h.cTBL;
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}

DummyQUndoCommand::DummyQUndoCommand()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQUndoCommand::setSelf(knh_RawPtr_t *ptr)
{
	DummyQUndoCommand::self = ptr;
}

bool DummyQUndoCommand::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQUndoCommand::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQUndoCommand::event_map->bigin();
	if ((itr = DummyQUndoCommand::event_map->find(str)) == DummyQUndoCommand::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQUndoCommand::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQUndoCommand::slot_map->bigin();
	if ((itr = DummyQUndoCommand::slot_map->find(str)) == DummyQUndoCommand::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQUndoCommand::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQUndoCommand::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQUndoCommand::connection(QObject *o)
{
	QUndoCommand *p = dynamic_cast<QUndoCommand*>(o);
	if (p != NULL) {
	}
}

KQUndoCommand::KQUndoCommand(QUndoCommand* parent) : QUndoCommand(parent)
{
	self = NULL;
	dummy = new DummyQUndoCommand();
}

KMETHOD QUndoCommand_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQUndoCommand *qp = RawPtr_to(KQUndoCommand *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QUndoCommand]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QUndoCommand]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QUndoCommand_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQUndoCommand *qp = RawPtr_to(KQUndoCommand *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QUndoCommand]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QUndoCommand]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QUndoCommand_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQUndoCommand *qp = (KQUndoCommand *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QUndoCommand_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQUndoCommand *qp = (KQUndoCommand *)p->rawptr;
//		KQUndoCommand *qp = static_cast<KQUndoCommand*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QUndoCommand_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQUndoCommand::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQUndoCommand(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QUndoCommand";
	cdef->free = QUndoCommand_free;
	cdef->reftrace = QUndoCommand_reftrace;
	cdef->compareTo = QUndoCommand_compareTo;
}


