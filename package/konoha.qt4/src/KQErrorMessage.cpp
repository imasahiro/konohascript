//QErrorMessage QErrorMessage.new(QWidget parent);
KMETHOD QErrorMessage_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQErrorMessage *ret_v = new KQErrorMessage(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QErrorMessage QErrorMessage.qtHandler();
KMETHOD QErrorMessage_qtHandler(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QErrorMessage* ret_v = QErrorMessage::qtHandler();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QErrorMessage*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QErrorMessage.showMessage(String message);
KMETHOD QErrorMessage_showMessage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QErrorMessage *  qp = RawPtr_to(QErrorMessage *, sfp[0]);
	if (qp) {
		const QString message = String_to(const QString, sfp[1]);
		qp->showMessage(message);
	}
	RETURNvoid_();
}

/*
//void QErrorMessage.showMessage(String message, String type);
KMETHOD QErrorMessage_showMessage(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QErrorMessage *  qp = RawPtr_to(QErrorMessage *, sfp[0]);
	if (qp) {
		const QString message = String_to(const QString, sfp[1]);
		const QString type = String_to(const QString, sfp[2]);
		qp->showMessage(message, type);
	}
	RETURNvoid_();
}
*/

DummyQErrorMessage::DummyQErrorMessage()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQErrorMessage::~DummyQErrorMessage()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQErrorMessage::setSelf(knh_RawPtr_t *ptr)
{
	DummyQErrorMessage::self = ptr;
	DummyQDialog::setSelf(ptr);
}

bool DummyQErrorMessage::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQDialog::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQErrorMessage::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQErrorMessage::event_map->bigin();
	if ((itr = DummyQErrorMessage::event_map->find(str)) == DummyQErrorMessage::event_map->end()) {
		bool ret = false;
		ret = DummyQDialog::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQErrorMessage::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQErrorMessage::slot_map->bigin();
	if ((itr = DummyQErrorMessage::slot_map->find(str)) == DummyQErrorMessage::slot_map->end()) {
		bool ret = false;
		ret = DummyQDialog::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQErrorMessage::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQErrorMessage::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQDialog::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQErrorMessage::connection(QObject *o)
{
	QErrorMessage *p = dynamic_cast<QErrorMessage*>(o);
	if (p != NULL) {
	}
	DummyQDialog::connection(o);
}

KQErrorMessage::KQErrorMessage(QWidget* parent) : QErrorMessage(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQErrorMessage();
	dummy->connection((QObject*)this);
}

KQErrorMessage::~KQErrorMessage()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QErrorMessage_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQErrorMessage *qp = RawPtr_to(KQErrorMessage *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QErrorMessage]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QErrorMessage]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QErrorMessage_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQErrorMessage *qp = RawPtr_to(KQErrorMessage *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QErrorMessage]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QErrorMessage]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QErrorMessage_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQErrorMessage *qp = (KQErrorMessage *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QErrorMessage*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QErrorMessage_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQErrorMessage *qp = (KQErrorMessage *)p->rawptr;
		KQErrorMessage *qp = static_cast<KQErrorMessage*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QErrorMessage_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQErrorMessage::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQErrorMessage::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QErrorMessage::event(event);
		return false;
	}
//	QErrorMessage::event(event);
	return true;
}



DEFAPI(void) defQErrorMessage(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QErrorMessage";
	cdef->free = QErrorMessage_free;
	cdef->reftrace = QErrorMessage_reftrace;
	cdef->compareTo = QErrorMessage_compareTo;
}


