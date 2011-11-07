//QDebug QDebug.new(QIODevice device);
KMETHOD QDebug_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice*  device = RawPtr_to(QIODevice*, sfp[1]);
	KQDebug *ret_v = new KQDebug(device);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QDebug QDebug.new(String str);
KMETHOD QDebug_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QString* string = String_to(QString*, sfp[1]);
	KQDebug *ret_v = new KQDebug(string);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QDebug QDebug.new(QtMsgType type);
KMETHOD QDebug_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QtMsgType  type = *RawPtr_to(QtMsgType *, sfp[1]);
	KQDebug *ret_v = new KQDebug(type);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QDebug QDebug.new(QDebug other);
KMETHOD QDebug_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QDebug  other = *RawPtr_to(const QDebug *, sfp[1]);
	KQDebug *ret_v = new KQDebug(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//QDebug QDebug.maybeSpace();
KMETHOD QDebug_maybeSpace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDebug *  qp = RawPtr_to(QDebug *, sfp[0]);
	if (qp) {
		QDebug ret_v = qp->maybeSpace();
		QDebug *ret_v_ = new QDebug(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDebug QDebug.nospace();
KMETHOD QDebug_nospace(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDebug *  qp = RawPtr_to(QDebug *, sfp[0]);
	if (qp) {
		QDebug ret_v = qp->nospace();
		QDebug *ret_v_ = new QDebug(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDebug QDebug.space();
KMETHOD QDebug_space(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDebug *  qp = RawPtr_to(QDebug *, sfp[0]);
	if (qp) {
		QDebug ret_v = qp->space();
		QDebug *ret_v_ = new QDebug(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QDebug.parents();
KMETHOD QDebug_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDebug *qp = RawPtr_to(QDebug*, sfp[0]);
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

DummyQDebug::DummyQDebug()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQDebug::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDebug::self = ptr;
}

bool DummyQDebug::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQDebug::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDebug::event_map->bigin();
	if ((itr = DummyQDebug::event_map->find(str)) == DummyQDebug::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDebug::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDebug::slot_map->bigin();
	if ((itr = DummyQDebug::slot_map->find(str)) == DummyQDebug::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

void DummyQDebug::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);


	KNH_SIZEREF(ctx);

}

void DummyQDebug::connection(QObject *o)
{
	QDebug *p = dynamic_cast<QDebug*>(o);
	if (p != NULL) {
	}
}

KQDebug::KQDebug(QIODevice* device) : QDebug(device)
{
	self = NULL;
	dummy = new DummyQDebug();
}

KMETHOD QDebug_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDebug *qp = RawPtr_to(KQDebug *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDebug]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDebug]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QDebug_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDebug *qp = RawPtr_to(KQDebug *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDebug]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDebug]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDebug_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDebug *qp = (KQDebug *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDebug_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQDebug *qp = (KQDebug *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QDebug_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQDebug::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQDebug(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDebug";
	cdef->free = QDebug_free;
	cdef->reftrace = QDebug_reftrace;
	cdef->compareTo = QDebug_compareTo;
}


