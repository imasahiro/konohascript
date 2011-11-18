//QThread QThread.new(QObject parent);
KMETHOD QThread_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQThread *ret_v = new KQThread(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QThread.exit(int returnCode);
KMETHOD QThread_exit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		uint ret_v = qp->stackSize();
		uint *ret_v_ = new uint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QThread.wait(long time);
KMETHOD QThread_wait(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp) {
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
	if (true) {
		QThread* ret_v = QThread::currentThread();
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
	if (true) {
		int ret_v = QThread::idealThreadCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QThread.yieldCurrentThread();
KMETHOD QThread_yieldCurrentThread(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QThread::yieldCurrentThread();
	}
	RETURNvoid_();
}

//void QThread.quit();
KMETHOD QThread_quit(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp) {
		qp->quit();
	}
	RETURNvoid_();
}

//void QThread.start(int priority);
KMETHOD QThread_start(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QThread *  qp = RawPtr_to(QThread *, sfp[0]);
	if (qp) {
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
	if (qp) {
		qp->terminate();
	}
	RETURNvoid_();
}


DummyQThread::DummyQThread()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	finished_func = NULL;
	started_func = NULL;
	terminated_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("finished", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("started", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("terminated", NULL));
}
DummyQThread::~DummyQThread()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
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

bool DummyQThread::finishedSlot()
{
	if (finished_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, finished_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQThread::startedSlot()
{
	if (started_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, started_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQThread::terminatedSlot()
{
	if (terminated_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, terminated_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQThread::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQThread::event_map->bigin();
	if ((itr = DummyQThread::event_map->find(str)) == DummyQThread::event_map->end()) {
		bool ret = false;
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
	if ((itr = DummyQThread::slot_map->find(str)) == DummyQThread::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		finished_func = (*slot_map)["finished"];
		started_func = (*slot_map)["started"];
		terminated_func = (*slot_map)["terminated"];
		return true;
	}
}

knh_Object_t** DummyQThread::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQThread::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 4;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, finished_func);
	KNH_ADDNNREF(ctx, started_func);
	KNH_ADDNNREF(ctx, terminated_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQThread::connection(QObject *o)
{
	QThread *p = dynamic_cast<QThread*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(finished()), this, SLOT(finishedSlot()));
		connect(p, SIGNAL(started()), this, SLOT(startedSlot()));
		connect(p, SIGNAL(terminated()), this, SLOT(terminatedSlot()));
	}
	DummyQObject::connection(o);
}

KQThread::KQThread(QObject* parent) : QThread(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQThread();
	dummy->connection((QObject*)this);
}

KQThread::~KQThread()
{
	delete dummy;
	dummy = NULL;
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QThread]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QThread_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQThread *qp = (KQThread *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QThread*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QThread_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQThread *qp = (KQThread *)p->rawptr;
		KQThread *qp = static_cast<KQThread*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QThread_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQThread::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQThread::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QThread::event(event);
		return false;
	}
//	QThread::event(event);
	return true;
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


DEFAPI(void) defQThread(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QThread";
	cdef->free = QThread_free;
	cdef->reftrace = QThread_reftrace;
	cdef->compareTo = QThread_compareTo;
}


