//@Virtual @Override boolean QProcess.atEnd();
KMETHOD QProcess_atEnd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		bool ret_v = qp->atEnd();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override int QProcess.bytesAvailable();
KMETHOD QProcess_bytesAvailable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->bytesAvailable();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override int QProcess.bytesToWrite();
KMETHOD QProcess_bytesToWrite(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->bytesToWrite();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QProcess.canReadLine();
KMETHOD QProcess_canReadLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		bool ret_v = qp->canReadLine();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override void QProcess.close();
KMETHOD QProcess_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		qp->close();
	}
	RETURNvoid_();
}

//@Virtual @Override boolean QProcess.isSequential();
KMETHOD QProcess_isSequential(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSequential();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override boolean QProcess.waitForBytesWritten(int msecs);
KMETHOD QProcess_waitForBytesWritten(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForBytesWritten(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override boolean QProcess.waitForReadyRead(int msecs);
KMETHOD QProcess_waitForReadyRead(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForReadyRead(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QProcess QProcess.new(QObject parent);
KMETHOD QProcess_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQProcess *ret_v = new KQProcess(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QProcess.closeReadChannel(int channel);
KMETHOD QProcess_closeReadChannel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		QProcess::ProcessChannel channel = Int_to(QProcess::ProcessChannel, sfp[1]);
		qp->closeReadChannel(channel);
	}
	RETURNvoid_();
}

//void QProcess.closeWriteChannel();
KMETHOD QProcess_closeWriteChannel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		qp->closeWriteChannel();
	}
	RETURNvoid_();
}

//int QProcess.error();
KMETHOD QProcess_error(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		QProcess::ProcessError ret_v = qp->error();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QProcess.exitCode();
KMETHOD QProcess_exitCode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		int ret_v = qp->exitCode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QProcess.exitStatus();
KMETHOD QProcess_exitStatus(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		QProcess::ExitStatus ret_v = qp->exitStatus();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//Q_PID QProcess.pid();
KMETHOD QProcess_pid(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		Q_PID ret_v = qp->pid();
		Q_PID *ret_v_ = new Q_PID(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QProcess.getProcessChannelMode();
KMETHOD QProcess_getProcessChannelMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		QProcess::ProcessChannelMode ret_v = qp->processChannelMode();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QProcessEnvironment QProcess.getProcessEnvironment();
KMETHOD QProcess_getProcessEnvironment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		QProcessEnvironment ret_v = qp->processEnvironment();
		QProcessEnvironment *ret_v_ = new QProcessEnvironment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QProcess.readAllStandardError();
KMETHOD QProcess_readAllStandardError(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->readAllStandardError();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QProcess.readAllStandardOutput();
KMETHOD QProcess_readAllStandardOutput(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->readAllStandardOutput();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QProcess.getReadChannel();
KMETHOD QProcess_getReadChannel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		QProcess::ProcessChannel ret_v = qp->readChannel();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QProcess.setProcessChannelMode(int mode);
KMETHOD QProcess_setProcessChannelMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		QProcess::ProcessChannelMode mode = Int_to(QProcess::ProcessChannelMode, sfp[1]);
		qp->setProcessChannelMode(mode);
	}
	RETURNvoid_();
}

//void QProcess.setProcessEnvironment(QProcessEnvironment environment);
KMETHOD QProcess_setProcessEnvironment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		const QProcessEnvironment  environment = *RawPtr_to(const QProcessEnvironment *, sfp[1]);
		qp->setProcessEnvironment(environment);
	}
	RETURNvoid_();
}

//void QProcess.setReadChannel(int channel);
KMETHOD QProcess_setReadChannel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		QProcess::ProcessChannel channel = Int_to(QProcess::ProcessChannel, sfp[1]);
		qp->setReadChannel(channel);
	}
	RETURNvoid_();
}

//void QProcess.setStandardErrorFile(String fileName, QIODeviceOpenMode mode);
KMETHOD QProcess_setStandardErrorFile(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		const QString fileName = String_to(const QString, sfp[1]);
		initFlag(mode, QIODevice::OpenMode, sfp[2]);
		qp->setStandardErrorFile(fileName, mode);
	}
	RETURNvoid_();
}

//void QProcess.setStandardInputFile(String fileName);
KMETHOD QProcess_setStandardInputFile(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		const QString fileName = String_to(const QString, sfp[1]);
		qp->setStandardInputFile(fileName);
	}
	RETURNvoid_();
}

//void QProcess.setStandardOutputFile(String fileName, QIODeviceOpenMode mode);
KMETHOD QProcess_setStandardOutputFile(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		const QString fileName = String_to(const QString, sfp[1]);
		initFlag(mode, QIODevice::OpenMode, sfp[2]);
		qp->setStandardOutputFile(fileName, mode);
	}
	RETURNvoid_();
}

//void QProcess.setStandardOutputProcess(QProcess destination);
KMETHOD QProcess_setStandardOutputProcess(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		QProcess*  destination = RawPtr_to(QProcess*, sfp[1]);
		qp->setStandardOutputProcess(destination);
	}
	RETURNvoid_();
}

//void QProcess.setWorkingDirectory(String dir);
KMETHOD QProcess_setWorkingDirectory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		const QString dir = String_to(const QString, sfp[1]);
		qp->setWorkingDirectory(dir);
	}
	RETURNvoid_();
}

//void QProcess.start(String program, QIODeviceOpenMode mode);
KMETHOD QProcess_start(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		const QString program = String_to(const QString, sfp[1]);
		initFlag(mode, QIODevice::OpenMode, sfp[2]);
		qp->start(program, mode);
	}
	RETURNvoid_();
}

//int QProcess.state();
KMETHOD QProcess_state(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		QProcess::ProcessState ret_v = qp->state();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QProcess.waitForFinished(int msecs);
KMETHOD QProcess_waitForFinished(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForFinished(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QProcess.waitForStarted(int msecs);
KMETHOD QProcess_waitForStarted(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForStarted(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QProcess.getWorkingDirectory();
KMETHOD QProcess_getWorkingDirectory(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		QString ret_v = qp->workingDirectory();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QProcess.execute(String program);
KMETHOD QProcess_execute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString program = String_to(const QString, sfp[1]);
		int ret_v = QProcess::execute(program);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QProcess.startDetached(String program);
KMETHOD QProcess_startDetached(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString program = String_to(const QString, sfp[1]);
		bool ret_v = QProcess::startDetached(program);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QProcess.kill();
KMETHOD QProcess_kill(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		qp->kill();
	}
	RETURNvoid_();
}

//void QProcess.terminate();
KMETHOD QProcess_terminate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp) {
		qp->terminate();
	}
	RETURNvoid_();
}


DummyQProcess::DummyQProcess()
{
	self = NULL;
	error_func = NULL;
	finished_func = NULL;
	ready_read_standard_error_func = NULL;
	ready_read_standard_output_func = NULL;
	started_func = NULL;
	state_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("error", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("finished", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("ready-read-standard-error", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("ready-read-standard-output", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("started", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("state-changed", NULL));
}

void DummyQProcess::setSelf(knh_RawPtr_t *ptr)
{
	DummyQProcess::self = ptr;
	DummyQIODevice::setSelf(ptr);
}

bool DummyQProcess::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQIODevice::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQProcess::errorSlot(QProcess::ProcessError error)
{
	if (error_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = error;
		knh_Func_invoke(lctx, error_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQProcess::finishedSlot(int exitCode, QProcess::ExitStatus exitStatus)
{
	if (finished_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = exitCode;
		lsfp[K_CALLDELTA+3].ivalue = exitStatus;
		knh_Func_invoke(lctx, finished_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQProcess::readyReadStandardErrorSlot()
{
	if (ready_read_standard_error_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, ready_read_standard_error_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQProcess::readyReadStandardOutputSlot()
{
	if (ready_read_standard_output_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, ready_read_standard_output_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQProcess::startedSlot()
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

bool DummyQProcess::stateChangedSlot(QProcess::ProcessState new_State)
{
	if (state_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = new_State;
		knh_Func_invoke(lctx, state_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQProcess::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQProcess::event_map->bigin();
	if ((itr = DummyQProcess::event_map->find(str)) == DummyQProcess::event_map->end()) {
		bool ret = false;
		ret = DummyQIODevice::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQProcess::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQProcess::slot_map->bigin();
	if ((itr = DummyQProcess::slot_map->find(str)) == DummyQProcess::slot_map->end()) {
		bool ret = false;
		ret = DummyQIODevice::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		error_func = (*slot_map)["error"];
		finished_func = (*slot_map)["finished"];
		ready_read_standard_error_func = (*slot_map)["ready-read-standard-error"];
		ready_read_standard_output_func = (*slot_map)["ready-read-standard-output"];
		started_func = (*slot_map)["started"];
		state_changed_func = (*slot_map)["state-changed"];
		return true;
	}
}

knh_Object_t** DummyQProcess::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQProcess::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 6;
	KNH_ENSUREREF(ctx, list_size);
	KNH_ADDNNREF(ctx, error_func);
	KNH_ADDNNREF(ctx, finished_func);
	KNH_ADDNNREF(ctx, ready_read_standard_error_func);
	KNH_ADDNNREF(ctx, ready_read_standard_output_func);
	KNH_ADDNNREF(ctx, started_func);
	KNH_ADDNNREF(ctx, state_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQIODevice::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQProcess::connection(QObject *o)
{
	QProcess *p = dynamic_cast<QProcess*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(error(QProcess::ProcessError)), this, SLOT(errorSlot(QProcess::ProcessError)));
		connect(p, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(finishedSlot(int, QProcess::ExitStatus)));
		connect(p, SIGNAL(readyReadStandardError()), this, SLOT(readyReadStandardErrorSlot()));
		connect(p, SIGNAL(readyReadStandardOutput()), this, SLOT(readyReadStandardOutputSlot()));
		connect(p, SIGNAL(started()), this, SLOT(startedSlot()));
		connect(p, SIGNAL(stateChanged(QProcess::ProcessState)), this, SLOT(stateChangedSlot(QProcess::ProcessState)));
	}
	DummyQIODevice::connection(o);
}

KQProcess::KQProcess(QObject* parent) : QProcess(parent)
{
	self = NULL;
	dummy = new DummyQProcess();
	dummy->connection((QObject*)this);
}

KMETHOD QProcess_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQProcess *qp = RawPtr_to(KQProcess *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QProcess]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QProcess]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QProcess_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQProcess *qp = RawPtr_to(KQProcess *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QProcess]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QProcess]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QProcess_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQProcess *qp = (KQProcess *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QProcess_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQProcess *qp = (KQProcess *)p->rawptr;
//		KQProcess *qp = static_cast<KQProcess*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QProcess_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQProcess::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQProcess::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QProcess::event(event);
		return false;
	}
//	QProcess::event(event);
	return true;
}

static knh_IntData_t QProcessConstInt[] = {
	{"NormalExit", QProcess::NormalExit},
	{"CrashExit", QProcess::CrashExit},
	{"StandardOutput", QProcess::StandardOutput},
	{"StandardError", QProcess::StandardError},
	{"SeparateChannels", QProcess::SeparateChannels},
	{"MergedChannels", QProcess::MergedChannels},
	{"ForwardedChannels", QProcess::ForwardedChannels},
	{"FailedToStart", QProcess::FailedToStart},
	{"Crashed", QProcess::Crashed},
	{"Timedout", QProcess::Timedout},
	{"WriteError", QProcess::WriteError},
	{"ReadError", QProcess::ReadError},
	{"UnknownError", QProcess::UnknownError},
	{"NotRunning", QProcess::NotRunning},
	{"Starting", QProcess::Starting},
	{"Running", QProcess::Running},
	{NULL, 0}
};

DEFAPI(void) constQProcess(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QProcessConstInt);
}


DEFAPI(void) defQProcess(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QProcess";
	cdef->free = QProcess_free;
	cdef->reftrace = QProcess_reftrace;
	cdef->compareTo = QProcess_compareTo;
}


