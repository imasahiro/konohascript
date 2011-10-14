//QWaitCondition QWaitCondition.new();
KMETHOD QWaitCondition_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWaitCondition *ret_v = new KQWaitCondition();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QWaitCondition.wait(QMutex mutex,  long time);
KMETHOD QWaitCondition_wait(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWaitCondition *  qp = RawPtr_to(QWaitCondition *, sfp[0]);
	if (qp != NULL) {
		QMutex*  mutex = RawPtr_to(QMutex*, sfp[1]);
		unsigned long  time = *RawPtr_to(unsigned long *, sfp[2]);
		bool ret_v = qp->wait(mutex, time);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QWaitCondition.wait(QReadWriteLock readWriteLock,  long time);
KMETHOD QWaitCondition_wait(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWaitCondition *  qp = RawPtr_to(QWaitCondition *, sfp[0]);
	if (qp != NULL) {
		QReadWriteLock*  readWriteLock = RawPtr_to(QReadWriteLock*, sfp[1]);
		unsigned long  time = *RawPtr_to(unsigned long *, sfp[2]);
		bool ret_v = qp->wait(readWriteLock, time);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//void QWaitCondition.wakeAll();
KMETHOD QWaitCondition_wakeAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWaitCondition *  qp = RawPtr_to(QWaitCondition *, sfp[0]);
	if (qp != NULL) {
		qp->wakeAll();
	}
	RETURNvoid_();
}

//void QWaitCondition.wakeOne();
KMETHOD QWaitCondition_wakeOne(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWaitCondition *  qp = RawPtr_to(QWaitCondition *, sfp[0]);
	if (qp != NULL) {
		qp->wakeOne();
	}
	RETURNvoid_();
}


DummyQWaitCondition::DummyQWaitCondition()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQWaitCondition::setSelf(knh_RawPtr_t *ptr)
{
	DummyQWaitCondition::self = ptr;
}

bool DummyQWaitCondition::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQWaitCondition::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWaitCondition::event_map->bigin();
	if ((itr = DummyQWaitCondition::event_map->find(str)) == DummyQWaitCondition::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQWaitCondition::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQWaitCondition::slot_map->bigin();
	if ((itr = DummyQWaitCondition::slot_map->find(str)) == DummyQWaitCondition::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


void DummyQWaitCondition::connection(QObject *o)
{
	return;
}

KQWaitCondition::KQWaitCondition() : QWaitCondition()
{
	self = NULL;
	dummy = new DummyQWaitCondition();
	dummy->connection((QObject*)this);
}

KMETHOD QWaitCondition_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWaitCondition *qp = RawPtr_to(KQWaitCondition *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QWaitCondition]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWaitCondition]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QWaitCondition_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQWaitCondition *qp = RawPtr_to(KQWaitCondition *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QWaitCondition]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QWaitCondition]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QWaitCondition_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQWaitCondition *qp = (KQWaitCondition *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QWaitCondition_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	int list_size = 0;
	KNH_ENSUREREF(ctx, list_size);

	if (p->rawptr != NULL) {
		KQWaitCondition *qp = (KQWaitCondition *)p->rawptr;
		(void)qp;
	}
}

static int QWaitCondition_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQWaitCondition::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

DEFAPI(void) defQWaitCondition(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QWaitCondition";
	cdef->free = QWaitCondition_free;
	cdef->reftrace = QWaitCondition_reftrace;
	cdef->compareTo = QWaitCondition_compareTo;
}


