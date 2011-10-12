//@Virtual @Override boolean QProcess.atEnd();
KMETHOD QProcess_atEnd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		qp->close();
	}
	RETURNvoid_();
}

//@Virtual @Override boolean QProcess.isSequential();
KMETHOD QProcess_isSequential(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QProcess.closeReadChannel(int channel);
KMETHOD QProcess_closeReadChannel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
		qp->closeWriteChannel();
	}
	RETURNvoid_();
}

//int QProcess.error();
KMETHOD QProcess_error(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		QProcess::ProcessChannel channel = Int_to(QProcess::ProcessChannel, sfp[1]);
		qp->setReadChannel(channel);
	}
	RETURNvoid_();
}

//void QProcess.setStandardErrorFile(String fileName, int mode);
KMETHOD QProcess_setStandardErrorFile(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		QProcess::OpenMode  mode = *RawPtr_to(QProcess::OpenMode *, sfp[2]);
		qp->setStandardErrorFile(fileName, mode);
	}
	RETURNvoid_();
}

//void QProcess.setStandardInputFile(String fileName);
KMETHOD QProcess_setStandardInputFile(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		qp->setStandardInputFile(fileName);
	}
	RETURNvoid_();
}

//void QProcess.setStandardOutputFile(String fileName, int mode);
KMETHOD QProcess_setStandardOutputFile(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		QProcess::OpenMode  mode = *RawPtr_to(QProcess::OpenMode *, sfp[2]);
		qp->setStandardOutputFile(fileName, mode);
	}
	RETURNvoid_();
}

//void QProcess.setStandardOutputProcess(QProcess destination);
KMETHOD QProcess_setStandardOutputProcess(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
		const QString dir = String_to(const QString, sfp[1]);
		qp->setWorkingDirectory(dir);
	}
	RETURNvoid_();
}

//void QProcess.start(String program, int mode);
KMETHOD QProcess_start(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp != NULL) {
		const QString program = String_to(const QString, sfp[1]);
		QProcess::OpenMode  mode = *RawPtr_to(QProcess::OpenMode *, sfp[2]);
		qp->start(program, mode);
	}
	RETURNvoid_();
}

//int QProcess.state();
KMETHOD QProcess_state(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp != NULL) {
		const QString program = String_to(const QString, sfp[1]);
		int ret_v = qp->execute(program);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QProcess.startDetached(String program);
KMETHOD QProcess_startDetached(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp != NULL) {
		const QString program = String_to(const QString, sfp[1]);
		bool ret_v = qp->startDetached(program);
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
	if (qp != NULL) {
		qp->kill();
	}
	RETURNvoid_();
}

//void QProcess.terminate();
KMETHOD QProcess_terminate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProcess *  qp = RawPtr_to(QProcess *, sfp[0]);
	if (qp != NULL) {
		qp->terminate();
	}
	RETURNvoid_();
}


DummyQProcess::DummyQProcess()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
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

bool DummyQProcess::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQProcess::event_map->bigin();
	if ((itr = DummyQProcess::event_map->find(str)) == DummyQProcess::event_map->end()) {
		bool ret;
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
	if ((itr = DummyQProcess::event_map->find(str)) == DummyQProcess::slot_map->end()) {
		bool ret;
		ret = DummyQIODevice::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQProcess::KQProcess(QObject* parent) : QProcess(parent)
{
	self = NULL;
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
		if (!qp->DummyQProcess::addEvent(callback_func, str)) {
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
		if (!qp->DummyQProcess::signalConnect(callback_func, str)) {
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
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQProcess *qp = (KQProcess *)p->rawptr;
		(void)qp;
	}
}

static int QProcess_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQProcess::event(QEvent *event)
{
	if (!DummyQProcess::eventDispatcher(event)) {
		QProcess::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQProcess(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QProcess";
	cdef->free = QProcess_free;
	cdef->reftrace = QProcess_reftrace;
	cdef->compareTo = QProcess_compareTo;
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

