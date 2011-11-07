//QFtp QFtp.new(QObject parent);
KMETHOD QFtp_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQFtp *ret_v = new KQFtp(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QFtp.bytesAvailable();
KMETHOD QFtp_bytesAvailable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->bytesAvailable();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QFtp.cd(String dir);
KMETHOD QFtp_cd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		const QString dir = String_to(const QString, sfp[1]);
		int ret_v = qp->cd(dir);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QFtp.clearPendingCommands();
KMETHOD QFtp_clearPendingCommands(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		qp->clearPendingCommands();
	}
	RETURNvoid_();
}

//int QFtp.close();
KMETHOD QFtp_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		int ret_v = qp->close();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFtp.connectToHost(String host, int port);
KMETHOD QFtp_connectToHost(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		const QString host = String_to(const QString, sfp[1]);
		quint16 port = Int_to(quint16, sfp[2]);
		int ret_v = qp->connectToHost(host, port);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFtp.currentCommand();
KMETHOD QFtp_currentCommand(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		QFtp::Command ret_v = qp->currentCommand();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QIODevice QFtp.currentDevice();
KMETHOD QFtp_currentDevice(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		QIODevice* ret_v = qp->currentDevice();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QIODevice*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QFtp.currentId();
KMETHOD QFtp_currentId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		int ret_v = qp->currentId();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFtp.error();
KMETHOD QFtp_error(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		QFtp::Error ret_v = qp->error();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QFtp.errorString();
KMETHOD QFtp_errorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		QString ret_v = qp->errorString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QFtp.get(String file, QIODevice dev, int type);
KMETHOD QFtp_get(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		const QString file = String_to(const QString, sfp[1]);
		QIODevice*  dev = RawPtr_to(QIODevice*, sfp[2]);
		QFtp::TransferType type = Int_to(QFtp::TransferType, sfp[3]);
		int ret_v = qp->get(file, dev, type);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QFtp.hasPendingCommands();
KMETHOD QFtp_hasPendingCommands(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		bool ret_v = qp->hasPendingCommands();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QFtp.list(String dir);
KMETHOD QFtp_list(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		const QString dir = String_to(const QString, sfp[1]);
		int ret_v = qp->list(dir);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFtp.login(String user, String password);
KMETHOD QFtp_login(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		const QString user = String_to(const QString, sfp[1]);
		const QString password = String_to(const QString, sfp[2]);
		int ret_v = qp->login(user, password);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFtp.mkdir(String dir);
KMETHOD QFtp_mkdir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		const QString dir = String_to(const QString, sfp[1]);
		int ret_v = qp->mkdir(dir);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFtp.put(QIODevice dev, String file, int type);
KMETHOD QFtp_put(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		QIODevice*  dev = RawPtr_to(QIODevice*, sfp[1]);
		const QString file = String_to(const QString, sfp[2]);
		QFtp::TransferType type = Int_to(QFtp::TransferType, sfp[3]);
		int ret_v = qp->put(dev, file, type);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QFtp.put(QByteArray data, String file, int type);
KMETHOD QFtp_put(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		const QByteArray  data = *RawPtr_to(const QByteArray *, sfp[1]);
		const QString file = String_to(const QString, sfp[2]);
		QFtp::TransferType type = Int_to(QFtp::TransferType, sfp[3]);
		int ret_v = qp->put(data, file, type);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//int QFtp.rawCommand(String command);
KMETHOD QFtp_rawCommand(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		const QString command = String_to(const QString, sfp[1]);
		int ret_v = qp->rawCommand(command);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFtp.read(String data, int maxlen);
KMETHOD QFtp_read(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		char*  data = RawPtr_to(char*, sfp[1]);
		qint64 maxlen = Int_to(qint64, sfp[2]);
		qint64 ret_v = qp->read(data, maxlen);
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QFtp.readAll();
KMETHOD QFtp_readAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->readAll();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QFtp.remove(String file);
KMETHOD QFtp_remove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		const QString file = String_to(const QString, sfp[1]);
		int ret_v = qp->remove(file);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFtp.rename(String oldname, String new_name);
KMETHOD QFtp_rename(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		const QString oldname = String_to(const QString, sfp[1]);
		const QString new_name = String_to(const QString, sfp[2]);
		int ret_v = qp->rename(oldname, new_name);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFtp.rmdir(String dir);
KMETHOD QFtp_rmdir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		const QString dir = String_to(const QString, sfp[1]);
		int ret_v = qp->rmdir(dir);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFtp.setProxy(String host, int port);
KMETHOD QFtp_setProxy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		const QString host = String_to(const QString, sfp[1]);
		quint16 port = Int_to(quint16, sfp[2]);
		int ret_v = qp->setProxy(host, port);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFtp.setTransferMode(int mode);
KMETHOD QFtp_setTransferMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		QFtp::TransferMode mode = Int_to(QFtp::TransferMode, sfp[1]);
		int ret_v = qp->setTransferMode(mode);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QFtp.state();
KMETHOD QFtp_state(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		QFtp::State ret_v = qp->state();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QFtp.abort();
KMETHOD QFtp_abort(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFtp *  qp = RawPtr_to(QFtp *, sfp[0]);
	if (qp) {
		qp->abort();
	}
	RETURNvoid_();
}


DummyQFtp::DummyQFtp()
{
	self = NULL;
	command_finished_func = NULL;
	command_started_func = NULL;
	data_transfer_progress_func = NULL;
	done_func = NULL;
	list_info_func = NULL;
	raw_command_reply_func = NULL;
	ready_read_func = NULL;
	state_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("command-finished", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("command-started", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("data-transfer-progress", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("done", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("list-info", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("raw-command-reply", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("ready-read", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("state-changed", NULL));
}

void DummyQFtp::setSelf(knh_RawPtr_t *ptr)
{
	DummyQFtp::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQFtp::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQFtp::commandFinishedSlot(int id, bool error)
{
	if (command_finished_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = id;
		lsfp[K_CALLDELTA+3].bvalue = error;
		knh_Func_invoke(lctx, command_finished_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQFtp::commandStartedSlot(int id)
{
	if (command_started_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = id;
		knh_Func_invoke(lctx, command_started_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQFtp::dataTransferProgressSlot(qint64 done, qint64 total)
{
	if (data_transfer_progress_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, qint64, done);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_RawPtr_t *p2 = new_QRawPtr(lctx, qint64, total);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		knh_Func_invoke(lctx, data_transfer_progress_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQFtp::doneSlot(bool error)
{
	if (done_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].bvalue = error;
		knh_Func_invoke(lctx, done_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQFtp::listInfoSlot(const QUrlInfo i)
{
	if (list_info_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, QUrlInfo, i);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, list_info_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQFtp::rawCommandReplySlot(int replyCode, const QString detail)
{
	if (raw_command_reply_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = replyCode;
		knh_RawPtr_t *p2 = new_QRawPtr(lctx, QString, detail);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+3].o, UPCAST(p2));
		knh_Func_invoke(lctx, raw_command_reply_func, lsfp, 3);
		return true;
	}
	return false;
}

bool DummyQFtp::readyReadSlot()
{
	if (ready_read_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, ready_read_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQFtp::stateChangedSlot(int state)
{
	if (state_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = state;
		knh_Func_invoke(lctx, state_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQFtp::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFtp::event_map->bigin();
	if ((itr = DummyQFtp::event_map->find(str)) == DummyQFtp::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQFtp::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFtp::slot_map->bigin();
	if ((itr = DummyQFtp::slot_map->find(str)) == DummyQFtp::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		command_finished_func = (*slot_map)["command-finished"];
		command_started_func = (*slot_map)["command-started"];
		data_transfer_progress_func = (*slot_map)["data-transfer-progress"];
		done_func = (*slot_map)["done"];
		list_info_func = (*slot_map)["list-info"];
		raw_command_reply_func = (*slot_map)["raw-command-reply"];
		ready_read_func = (*slot_map)["ready-read"];
		state_changed_func = (*slot_map)["state-changed"];
		return true;
	}
}

void DummyQFtp::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
	int list_size = 8;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, command_finished_func);
	KNH_ADDNNREF(ctx, command_started_func);
	KNH_ADDNNREF(ctx, data_transfer_progress_func);
	KNH_ADDNNREF(ctx, done_func);
	KNH_ADDNNREF(ctx, list_info_func);
	KNH_ADDNNREF(ctx, raw_command_reply_func);
	KNH_ADDNNREF(ctx, ready_read_func);
	KNH_ADDNNREF(ctx, state_changed_func);

	KNH_SIZEREF(ctx);

	DummyQObject::reftrace(ctx, p, tail_);
}

void DummyQFtp::connection(QObject *o)
{
	QFtp *p = dynamic_cast<QFtp*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(commandFinished(int, bool)), this, SLOT(commandFinishedSlot(int, bool)));
		connect(p, SIGNAL(commandStarted(int)), this, SLOT(commandStartedSlot(int)));
		connect(p, SIGNAL(dataTransferProgress(qint64, qint64)), this, SLOT(dataTransferProgressSlot(qint64, qint64)));
		connect(p, SIGNAL(done(bool)), this, SLOT(doneSlot(bool)));
		connect(p, SIGNAL(listInfo(const QUrlInfo)), this, SLOT(listInfoSlot(const QUrlInfo)));
		connect(p, SIGNAL(rawCommandReply(int, const QString)), this, SLOT(rawCommandReplySlot(int, const QString)));
		connect(p, SIGNAL(readyRead()), this, SLOT(readyReadSlot()));
		connect(p, SIGNAL(stateChanged(int)), this, SLOT(stateChangedSlot(int)));
	}
	DummyQObject::connection(o);
}

KQFtp::KQFtp(QObject* parent) : QFtp(parent)
{
	self = NULL;
	dummy = new DummyQFtp();
	dummy->connection((QObject*)this);
}

KMETHOD QFtp_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFtp *qp = RawPtr_to(KQFtp *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QFtp]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFtp]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QFtp_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFtp *qp = RawPtr_to(KQFtp *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QFtp]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFtp]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QFtp_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQFtp *qp = (KQFtp *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QFtp_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
		KQFtp *qp = (KQFtp *)p->rawptr;
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QFtp_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQFtp::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQFtp::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QFtp::event(event);
		return false;
	}
	return true;
}

static knh_IntData_t QFtpConstInt[] = {
	{"None", QFtp::None},
	{"SetTransferMode", QFtp::SetTransferMode},
	{"SetProxy", QFtp::SetProxy},
	{"ConnectToHost", QFtp::ConnectToHost},
	{"Login", QFtp::Login},
	{"Close", QFtp::Close},
	{"List", QFtp::List},
	{"Cd", QFtp::Cd},
	{"Get", QFtp::Get},
	{"Put", QFtp::Put},
	{"Remove", QFtp::Remove},
	{"Mkdir", QFtp::Mkdir},
	{"Rmdir", QFtp::Rmdir},
	{"Rename", QFtp::Rename},
	{"RawCommand", QFtp::RawCommand},
	{"NoError", QFtp::NoError},
	{"HostNotFound", QFtp::HostNotFound},
	{"ConnectionRefused", QFtp::ConnectionRefused},
	{"NotConnected", QFtp::NotConnected},
	{"UnknownError", QFtp::UnknownError},
	{"Unconnected", QFtp::Unconnected},
	{"HostLookup", QFtp::HostLookup},
	{"Connecting", QFtp::Connecting},
	{"Connected", QFtp::Connected},
	{"LoggedIn", QFtp::LoggedIn},
	{"Closing", QFtp::Closing},
	{"Passive", QFtp::Passive},
	{"Active", QFtp::Active},
	{"Binary", QFtp::Binary},
	{"Ascii", QFtp::Ascii},
	{NULL, 0}
};

DEFAPI(void) constQFtp(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QFtpConstInt);
}


DEFAPI(void) defQFtp(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFtp";
	cdef->free = QFtp_free;
	cdef->reftrace = QFtp_reftrace;
	cdef->compareTo = QFtp_compareTo;
}


