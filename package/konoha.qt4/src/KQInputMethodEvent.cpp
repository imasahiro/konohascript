//QInputMethodEvent QInputMethodEvent.new();
KMETHOD QInputMethodEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQInputMethodEvent *ret_v = new KQInputMethodEvent();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QInputMethodEvent QInputMethodEvent.new(String preeditText, Array<int> attributes);
KMETHOD QInputMethodEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString preeditText = String_to(const QString, sfp[1]);
	knh_Array_t *a = sfp[2].a;
		int asize = knh_Array_size(a);
		QList<QInputMethodEvent::Attribute> attributes;
		for (int n = 0; n < asize; n++) {
			knh_RawPtr_t *p = (knh_RawPtr_t*)(a->list[n]);
			attributes.append(*(QInputMethodEvent::Attribute*)p->rawptr);
		}
	KQInputMethodEvent *ret_v = new KQInputMethodEvent(preeditText, attributes);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QInputMethodEvent QInputMethodEvent.new(QInputMethodEvent other);
KMETHOD QInputMethodEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QInputMethodEvent  other = *RawPtr_to(const QInputMethodEvent *, sfp[1]);
	KQInputMethodEvent *ret_v = new KQInputMethodEvent(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//Array<int> QInputMethodEvent.attributes();
KMETHOD QInputMethodEvent_attributes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputMethodEvent *  qp = RawPtr_to(QInputMethodEvent *, sfp[0]);
	if (qp != NULL) {
		const QList<QInputMethodEvent::Attribute>ret_v = qp->attributes();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QInputMethodEvent::Attribute"));
		for (int n = 0; n < list_size; n++) {
			QInputMethodEvent::Attribute *ret_v_ = new QInputMethodEvent::Attribute(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//String QInputMethodEvent.getCommitString();
KMETHOD QInputMethodEvent_getCommitString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputMethodEvent *  qp = RawPtr_to(QInputMethodEvent *, sfp[0]);
	if (qp != NULL) {
		const QString ret_v = qp->commitString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QInputMethodEvent.preeditString();
KMETHOD QInputMethodEvent_preeditString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputMethodEvent *  qp = RawPtr_to(QInputMethodEvent *, sfp[0]);
	if (qp != NULL) {
		const QString ret_v = qp->preeditString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QInputMethodEvent.replacementLength();
KMETHOD QInputMethodEvent_replacementLength(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputMethodEvent *  qp = RawPtr_to(QInputMethodEvent *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->replacementLength();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QInputMethodEvent.replacementStart();
KMETHOD QInputMethodEvent_replacementStart(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputMethodEvent *  qp = RawPtr_to(QInputMethodEvent *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->replacementStart();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QInputMethodEvent.setCommitString(String commitString, int replaceFrom, int replaceLength);
KMETHOD QInputMethodEvent_setCommitString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QInputMethodEvent *  qp = RawPtr_to(QInputMethodEvent *, sfp[0]);
	if (qp != NULL) {
		const QString commitString = String_to(const QString, sfp[1]);
		int replaceFrom = Int_to(int, sfp[2]);
		int replaceLength = Int_to(int, sfp[3]);
		qp->setCommitString(commitString, replaceFrom, replaceLength);
	}
	RETURNvoid_();
}


DummyQInputMethodEvent::DummyQInputMethodEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQInputMethodEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQInputMethodEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQInputMethodEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQInputMethodEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQInputMethodEvent::event_map->bigin();
	if ((itr = DummyQInputMethodEvent::event_map->find(str)) == DummyQInputMethodEvent::event_map->end()) {
		bool ret;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQInputMethodEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQInputMethodEvent::slot_map->bigin();
	if ((itr = DummyQInputMethodEvent::event_map->find(str)) == DummyQInputMethodEvent::slot_map->end()) {
		bool ret;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQInputMethodEvent::KQInputMethodEvent() : QInputMethodEvent()
{
	self = NULL;
}

KMETHOD QInputMethodEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQInputMethodEvent *qp = RawPtr_to(KQInputMethodEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QInputMethodEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQInputMethodEvent::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QInputMethodEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QInputMethodEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQInputMethodEvent *qp = RawPtr_to(KQInputMethodEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QInputMethodEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQInputMethodEvent::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QInputMethodEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QInputMethodEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQInputMethodEvent *qp = (KQInputMethodEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QInputMethodEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQInputMethodEvent *qp = (KQInputMethodEvent *)p->rawptr;
		(void)qp;
	}
}

static int QInputMethodEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQInputMethodEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QInputMethodEvent";
	cdef->free = QInputMethodEvent_free;
	cdef->reftrace = QInputMethodEvent_reftrace;
	cdef->compareTo = QInputMethodEvent_compareTo;
}

static knh_IntData_t QInputMethodEventConstInt[] = {
	{"TextFormat", QInputMethodEvent::TextFormat},
	{"Cursor", QInputMethodEvent::Cursor},
	{"Language", QInputMethodEvent::Language},
	{"Ruby", QInputMethodEvent::Ruby},
	{"Selection", QInputMethodEvent::Selection},
	{NULL, 0}
};

DEFAPI(void) constQInputMethodEvent(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QInputMethodEventConstInt);
}

