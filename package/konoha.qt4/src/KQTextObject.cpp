//QTextDocument QTextObject.document();
KMETHOD QTextObject_document(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextObject *  qp = RawPtr_to(QTextObject *, sfp[0]);
	if (qp) {
		QTextDocument* ret_v = qp->document();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QTextDocument*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QTextFormat QTextObject.format();
KMETHOD QTextObject_format(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextObject *  qp = RawPtr_to(QTextObject *, sfp[0]);
	if (qp) {
		QTextFormat ret_v = qp->format();
		QTextFormat *ret_v_ = new QTextFormat(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QTextObject.formatIndex();
KMETHOD QTextObject_formatIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextObject *  qp = RawPtr_to(QTextObject *, sfp[0]);
	if (qp) {
		int ret_v = qp->formatIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QTextObject.objectIndex();
KMETHOD QTextObject_objectIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTextObject *  qp = RawPtr_to(QTextObject *, sfp[0]);
	if (qp) {
		int ret_v = qp->objectIndex();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}


DummyQTextObject::DummyQTextObject()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQTextObject::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextObject::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQTextObject::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTextObject::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextObject::event_map->bigin();
	if ((itr = DummyQTextObject::event_map->find(str)) == DummyQTextObject::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextObject::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextObject::slot_map->bigin();
	if ((itr = DummyQTextObject::slot_map->find(str)) == DummyQTextObject::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQTextObject::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

	DummyQObject::reftrace(ctx, p, tail_);
}

void DummyQTextObject::connection(QObject *o)
{
	QTextObject *p = dynamic_cast<QTextObject*>(o);
	if (p != NULL) {
	}
	DummyQObject::connection(o);
}

KMETHOD QTextObject_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextObject *qp = RawPtr_to(KQTextObject *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextObject]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextObject]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextObject_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextObject *qp = RawPtr_to(KQTextObject *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextObject]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextObject]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextObject_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQTextObject *qp = (KQTextObject *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QTextObject_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQTextObject *qp = (KQTextObject *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextObject_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextObject::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQTextObject::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QTextObject::event(event);
		return false;
	}
	return true;
}



DEFAPI(void) defQTextObject(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextObject";
	cdef->free = QTextObject_free;
	cdef->reftrace = QTextObject_reftrace;
	cdef->compareTo = QTextObject_compareTo;
}


