//@Virtual @Override String QAccessibleObject.actionText(int action, int t, int child);
KMETHOD QAccessibleObject_actionText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleObject *  qp = RawPtr_to(QAccessibleObject *, sfp[0]);
	if (qp != NULL) {
		int action = Int_to(int, sfp[1]);
		QAccessibleObject::Text t = Int_to(QAccessibleObject::Text, sfp[2]);
		int child = Int_to(int, sfp[3]);
		QString ret_v = qp->actionText(action, t, child);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QAccessibleObject.doAction(int action, int child, QVariantList params);
KMETHOD QAccessibleObject_doAction(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleObject *  qp = RawPtr_to(QAccessibleObject *, sfp[0]);
	if (qp != NULL) {
		int action = Int_to(int, sfp[1]);
		int child = Int_to(int, sfp[2]);
		const QVariantList  params = *RawPtr_to(const QVariantList *, sfp[3]);
		bool ret_v = qp->doAction(action, child, params);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

////@Virtual @Override boolean QAccessibleObject.isValid();
KMETHOD QAccessibleObject_isValid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleObject *  qp = RawPtr_to(QAccessibleObject *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isValid();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QObject QAccessibleObject.object();
KMETHOD QAccessibleObject_object(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleObject *  qp = RawPtr_to(QAccessibleObject *, sfp[0]);
	if (qp != NULL) {
		QObject* ret_v = qp->object();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QObject*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QRect QAccessibleObject.rect(int child);
KMETHOD QAccessibleObject_rect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleObject *  qp = RawPtr_to(QAccessibleObject *, sfp[0]);
	if (qp != NULL) {
		int child = Int_to(int, sfp[1]);
		QRect ret_v = qp->rect(child);
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QAccessibleObject.setText(int t, int child, String text);
KMETHOD QAccessibleObject_setText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleObject *  qp = RawPtr_to(QAccessibleObject *, sfp[0]);
	if (qp != NULL) {
		QAccessibleObject::Text t = Int_to(QAccessibleObject::Text, sfp[1]);
		int child = Int_to(int, sfp[2]);
		const QString text = String_to(const QString, sfp[3]);
		qp->setText(t, child, text);
	}
	RETURNvoid_();
}

//@Virtual @Override int QAccessibleObject.userActionCount(int child);
KMETHOD QAccessibleObject_userActionCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAccessibleObject *  qp = RawPtr_to(QAccessibleObject *, sfp[0]);
	if (qp != NULL) {
		int child = Int_to(int, sfp[1]);
		int ret_v = qp->userActionCount(child);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//

DummyQAccessibleObject::DummyQAccessibleObject()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQAccessibleObject::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAccessibleObject::self = ptr;
	DummyQAccessibleInterface::setSelf(ptr);
}

bool DummyQAccessibleObject::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAccessibleInterface::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQAccessibleObject::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAccessibleObject::event_map->bigin();
	if ((itr = DummyQAccessibleObject::event_map->find(str)) == DummyQAccessibleObject::event_map->end()) {
		bool ret = false;
		ret = DummyQAccessibleInterface::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAccessibleObject::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAccessibleObject::slot_map->bigin();
	if ((itr = DummyQAccessibleObject::slot_map->find(str)) == DummyQAccessibleObject::slot_map->end()) {
		bool ret = false;
		ret = DummyQAccessibleInterface::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQAccessibleObject::connection(QObject *o)
{
	DummyQAccessibleInterface::connection(o);
}

KQAccessibleObject::KQAccessibleObject(QObject* object) : QAccessibleObject(object)
{
	self = NULL;
	dummy = new DummyQAccessibleObject();
	dummy->connection((QObject*)this);
}

KMETHOD QAccessibleObject_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAccessibleObject *qp = RawPtr_to(KQAccessibleObject *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAccessibleObject]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAccessibleObject]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QAccessibleObject_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAccessibleObject *qp = RawPtr_to(KQAccessibleObject *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAccessibleObject]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAccessibleObject]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAccessibleObject_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAccessibleObject *qp = (KQAccessibleObject *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAccessibleObject_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQAccessibleObject *qp = (KQAccessibleObject *)p->rawptr;
		(void)qp;
	}
}

static int QAccessibleObject_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQAccessibleObject::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQAccessibleObject(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAccessibleObject";
	cdef->free = QAccessibleObject_free;
	cdef->reftrace = QAccessibleObject_reftrace;
	cdef->compareTo = QAccessibleObject_compareTo;
}


