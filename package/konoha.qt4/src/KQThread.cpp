//QThread QThread.new(QObject parent);
KMETHOD QThread_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQThread *ret_v = new KQThread(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QThread.exit(int returnCode);
KMETHOD QThread_exit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp != NULL) {
		int returnCode = Int_to(int, sfp[1]);
		qp->exit(returnCode);
	}
	RETURNvoid_();
}

//boolean QThread.isFinished();
KMETHOD QThread_isFinished(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isFinished();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QThread.isRunning();
KMETHOD QThread_isRunning(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isRunning();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QThread.getPriority();
KMETHOD QThread_getPriority(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp != NULL) {
		QThread::Priority ret_v = qp->priority();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QThread.setPriority(int priority);
KMETHOD QThread_setPriority(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp != NULL) {
		QThread::Priority priority = Int_to(QThread::Priority, sfp[1]);
		qp->setPriority(priority);
	}
	RETURNvoid_();
}

//void QThread.setStackSize(int stackSize);
KMETHOD QThread_setStackSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp != NULL) {
		uint  stackSize = *RawPtr_to(uint *, sfp[1]);
		qp->setStackSize(stackSize);
	}
	RETURNvoid_();
}

//int QThread.getStackSize();
KMETHOD QThread_getStackSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp != NULL) {
		uint ret_v = qp->stackSize();
		uint *ret_v_ = new uint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QThread.wait( long time);
KMETHOD QThread_wait(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp != NULL) {
		unsigned long  time = *RawPtr_to(unsigned long *, sfp[1]);
		bool ret_v = qp->wait(time);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QThread QThread.currentThread();
KMETHOD QThread_currentThread(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp != NULL) {
		QThread* ret_v = qp->currentThread();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QThread*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QThread.idealThreadCount();
KMETHOD QThread_idealThreadCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->idealThreadCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QThread.yieldCurrentThread();
KMETHOD QThread_yieldCurrentThread(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp != NULL) {
		qp->yieldCurrentThread();
	}
	RETURNvoid_();
}

//void QThread.quit();
KMETHOD QThread_quit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp != NULL) {
		qp->quit();
	}
	RETURNvoid_();
}

//void QThread.start(int priority);
KMETHOD QThread_start(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp != NULL) {
		QThread::Priority priority = Int_to(QThread::Priority, sfp[1]);
		qp->start(priority);
	}
	RETURNvoid_();
}

//void QThread.terminate();
KMETHOD QThread_terminate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp != NULL) {
		qp->terminate();
	}
	RETURNvoid_();
}


DummyQThread::DummyQThread()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQThread::setSelf(knh_RawPtr_t *ptr)
{
	DummyQThread::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQThread::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQThread::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQThread::event_map->bigin();
	if ((itr = DummyQThread::event_map->find(str)) == DummyQThread::event_map->end()) {
		bool ret;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQThread::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQThread::slot_map->bigin();
	if ((itr = DummyQThread::event_map->find(str)) == DummyQThread::slot_map->end()) {
		bool ret;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQThread::KQThread(QObject* parent) : QThread(parent)
{
	self = NULL;
}

KMETHOD QThread_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQThread *qp = RawPtr_to(KQThread *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QThread]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQThread::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QThread]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QThread_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQThread *qp = RawPtr_to(KQThread *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QThread]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQThread::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QThread]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QThread_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQThread *qp = (KQThread *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QThread_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQThread *qp = (KQThread *)p->rawptr;
		(void)qp;
	}
}

static int QThread_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQThread::event(QEvent *event)
{
	if (!DummyQThread::eventDispatcher(event)) {
		QThread::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQThread(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QThread";
	cdef->free = QThread_free;
	cdef->reftrace = QThread_reftrace;
	cdef->compareTo = QThread_compareTo;
}

static knh_IntData_t QThreadConstInt[] = {
	{"IdlePriority", QThread::IdlePriority},
	{"LowestPriority", QThread::LowestPriority},
	{"LowPriority", QThread::LowPriority},
	{"NormalPriority", QThread::NormalPriority},
	{"HighPriority", QThread::HighPriority},
	{"HighestPriority", QThread::HighestPriority},
	{"TimeCriticalPriority", QThread::TimeCriticalPriority},
	{"InheritPriority", QThread::InheritPriority},
	{NULL, 0}
};

DEFAPI(void) constQThread(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QThreadConstInt);
}

