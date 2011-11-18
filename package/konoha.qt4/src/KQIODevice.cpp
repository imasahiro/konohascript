//
/*
//*/
//@Virtual boolean QIODevice.atEnd();
KMETHOD QIODevice_atEnd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		bool ret_v = qp->atEnd();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual int QIODevice.bytesAvailable();
KMETHOD QIODevice_bytesAvailable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->bytesAvailable();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual int QIODevice.bytesToWrite();
KMETHOD QIODevice_bytesToWrite(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->bytesToWrite();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual boolean QIODevice.canReadLine();
KMETHOD QIODevice_canReadLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		bool ret_v = qp->canReadLine();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual void QIODevice.close();
KMETHOD QIODevice_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		qp->close();
	}
	RETURNvoid_();
}

//String QIODevice.errorString();
KMETHOD QIODevice_errorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		QString ret_v = qp->errorString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QIODevice.getChar(String c);
KMETHOD QIODevice_getChar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		char*  c = RawPtr_to(char*, sfp[1]);
		bool ret_v = qp->getChar(c);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QIODevice.isOpen();
KMETHOD QIODevice_isOpen(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isOpen();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QIODevice.isReadable();
KMETHOD QIODevice_isReadable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isReadable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QIODevice.isSequential();
KMETHOD QIODevice_isSequential(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSequential();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QIODevice.isTextModeEnabled();
KMETHOD QIODevice_isTextModeEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isTextModeEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QIODevice.isWritable();
KMETHOD QIODevice_isWritable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isWritable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QIODevice.open(QIODeviceOpenMode mode);
KMETHOD QIODevice_open(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		initFlag(mode, QIODevice::OpenMode, sfp[1]);
		bool ret_v = qp->open(mode);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QIODeviceOpenMode QIODevice.openMode();
KMETHOD QIODevice_openMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		QIODevice::OpenMode ret_v = qp->openMode();
		QIODevice::OpenMode *ret_v_ = new QIODevice::OpenMode(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QIODevice.peek(String data, int maxSize);
KMETHOD QIODevice_peek(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		char*  data = RawPtr_to(char*, sfp[1]);
		qint64 maxSize = Int_to(qint64, sfp[2]);
		qint64 ret_v = qp->peek(data, maxSize);
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QByteArray QIODevice.peek(int maxSize);
KMETHOD QIODevice_peek(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		qint64 maxSize = Int_to(qint64, sfp[1]);
		QByteArray ret_v = qp->peek(maxSize);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//@Virtual int QIODevice.pos();
KMETHOD QIODevice_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->pos();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QIODevice.putChar(String c);
KMETHOD QIODevice_putChar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		char  c = *RawPtr_to(char *, sfp[1]);
		bool ret_v = qp->putChar(c);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QIODevice.read(String data, int maxSize);
KMETHOD QIODevice_read(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		char*  data = RawPtr_to(char*, sfp[1]);
		qint64 maxSize = Int_to(qint64, sfp[2]);
		qint64 ret_v = qp->read(data, maxSize);
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QByteArray QIODevice.read(int maxSize);
KMETHOD QIODevice_read(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		qint64 maxSize = Int_to(qint64, sfp[1]);
		QByteArray ret_v = qp->read(maxSize);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//QByteArray QIODevice.readAll();
KMETHOD QIODevice_readAll(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->readAll();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QIODevice.readLine(String data, int maxSize);
KMETHOD QIODevice_readLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		char*  data = RawPtr_to(char*, sfp[1]);
		qint64 maxSize = Int_to(qint64, sfp[2]);
		qint64 ret_v = qp->readLine(data, maxSize);
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//QByteArray QIODevice.readLine(int maxSize);
KMETHOD QIODevice_readLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		qint64 maxSize = Int_to(qint64, sfp[1]);
		QByteArray ret_v = qp->readLine(maxSize);
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
//@Virtual boolean QIODevice.reset();
KMETHOD QIODevice_reset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		bool ret_v = qp->reset();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QIODevice.seek(int pos);
KMETHOD QIODevice_seek(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		qint64 pos = Int_to(qint64, sfp[1]);
		bool ret_v = qp->seek(pos);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QIODevice.setTextModeEnabled(boolean enabled);
KMETHOD QIODevice_setTextModeEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		bool enabled = Boolean_to(bool, sfp[1]);
		qp->setTextModeEnabled(enabled);
	}
	RETURNvoid_();
}

//@Virtual int QIODevice.size();
KMETHOD QIODevice_size(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->size();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QIODevice.ungetChar(String c);
KMETHOD QIODevice_ungetChar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		char  c = *RawPtr_to(char *, sfp[1]);
		qp->ungetChar(c);
	}
	RETURNvoid_();
}

//@Virtual boolean QIODevice.waitForBytesWritten(int msecs);
KMETHOD QIODevice_waitForBytesWritten(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForBytesWritten(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QIODevice.waitForReadyRead(int msecs);
KMETHOD QIODevice_waitForReadyRead(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		int msecs = Int_to(int, sfp[1]);
		bool ret_v = qp->waitForReadyRead(msecs);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QIODevice.write(String data, int maxSize);
KMETHOD QIODevice_write(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		const char*  data = RawPtr_to(const char*, sfp[1]);
		qint64 maxSize = Int_to(qint64, sfp[2]);
		qint64 ret_v = qp->write(data, maxSize);
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

/*
//int QIODevice.write(String data);
KMETHOD QIODevice_write(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		const char*  data = RawPtr_to(const char*, sfp[1]);
		qint64 ret_v = qp->write(data);
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/
/*
//int QIODevice.write(QByteArray byteArray);
KMETHOD QIODevice_write(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp) {
		const QByteArray  byteArray = *RawPtr_to(const QByteArray *, sfp[1]);
		qint64 ret_v = qp->write(byteArray);
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}
*/

DummyQIODevice::DummyQIODevice()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	about_to_close_func = NULL;
	bytes_written_func = NULL;
	read_channel_finished_func = NULL;
	ready_read_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("about-to-close", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("bytes-written", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("read-channel-finished", NULL));
	slot_map->insert(map<string, knh_Func_t *>::value_type("ready-read", NULL));
}
DummyQIODevice::~DummyQIODevice()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQIODevice::setSelf(knh_RawPtr_t *ptr)
{
	DummyQIODevice::self = ptr;
	DummyQObject::setSelf(ptr);
}

bool DummyQIODevice::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQIODevice::aboutToCloseSlot()
{
	if (about_to_close_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, about_to_close_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQIODevice::bytesWrittenSlot(qint64 bytes)
{
	if (bytes_written_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_RawPtr_t *p1 = new_QRawPtr(lctx, qint64, bytes);
		KNH_SETv(lctx, lsfp[K_CALLDELTA+2].o, UPCAST(p1));
		knh_Func_invoke(lctx, bytes_written_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQIODevice::readChannelFinishedSlot()
{
	if (read_channel_finished_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		knh_Func_invoke(lctx, read_channel_finished_func, lsfp, 1);
		return true;
	}
	return false;
}

bool DummyQIODevice::readyReadSlot()
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

bool DummyQIODevice::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQIODevice::event_map->bigin();
	if ((itr = DummyQIODevice::event_map->find(str)) == DummyQIODevice::event_map->end()) {
		bool ret = false;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQIODevice::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQIODevice::slot_map->bigin();
	if ((itr = DummyQIODevice::slot_map->find(str)) == DummyQIODevice::slot_map->end()) {
		bool ret = false;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		about_to_close_func = (*slot_map)["about-to-close"];
		bytes_written_func = (*slot_map)["bytes-written"];
		read_channel_finished_func = (*slot_map)["read-channel-finished"];
		ready_read_func = (*slot_map)["ready-read"];
		return true;
	}
}

knh_Object_t** DummyQIODevice::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQIODevice::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 5;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, about_to_close_func);
	KNH_ADDNNREF(ctx, bytes_written_func);
	KNH_ADDNNREF(ctx, read_channel_finished_func);
	KNH_ADDNNREF(ctx, ready_read_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQIODevice::connection(QObject *o)
{
	QIODevice *p = dynamic_cast<QIODevice*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(aboutToClose()), this, SLOT(aboutToCloseSlot()));
		connect(p, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWrittenSlot(qint64)));
		connect(p, SIGNAL(readChannelFinished()), this, SLOT(readChannelFinishedSlot()));
		connect(p, SIGNAL(readyRead()), this, SLOT(readyReadSlot()));
	}
	DummyQObject::connection(o);
}

KQIODevice::KQIODevice() : QIODevice()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQIODevice();
	dummy->connection((QObject*)this);
}

KQIODevice::~KQIODevice()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QIODevice_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQIODevice *qp = RawPtr_to(KQIODevice *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QIODevice]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QIODevice]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QIODevice_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQIODevice *qp = RawPtr_to(KQIODevice *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QIODevice]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QIODevice]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QIODevice_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQIODevice *qp = (KQIODevice *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QIODevice*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QIODevice_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQIODevice *qp = (KQIODevice *)p->rawptr;
		KQIODevice *qp = static_cast<KQIODevice*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QIODevice_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQIODevice::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQIODevice::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QIODevice::event(event);
		return false;
	}
//	QIODevice::event(event);
	return true;
}

static knh_IntData_t QIODeviceConstInt[] = {
	{"NotOpen", QIODevice::NotOpen},
	{"ReadOnly", QIODevice::ReadOnly},
	{"WriteOnly", QIODevice::WriteOnly},
	{"ReadWrite", QIODevice::ReadWrite},
	{"Append", QIODevice::Append},
	{"Truncate", QIODevice::Truncate},
	{"Text", QIODevice::Text},
	{"Unbuffered", QIODevice::Unbuffered},
	{NULL, 0}
};

DEFAPI(void) constQIODevice(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QIODeviceConstInt);
}


DEFAPI(void) defQIODevice(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QIODevice";
	cdef->free = QIODevice_free;
	cdef->reftrace = QIODevice_reftrace;
	cdef->compareTo = QIODevice_compareTo;
}

//## QIODeviceOpenMode QIODeviceOpenMode.new(int value);
KMETHOD QIODeviceOpenMode_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QIODevice::OpenModeFlag i = Int_to(QIODevice::OpenModeFlag, sfp[1]);
	QIODevice::OpenMode *ret_v = new QIODevice::OpenMode(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QIODeviceOpenMode QIODeviceOpenMode.and(int mask);
KMETHOD QIODeviceOpenMode_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QIODevice::OpenMode *qp = RawPtr_to(QIODevice::OpenMode*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QIODevice::OpenMode ret = ((*qp) & i);
		QIODevice::OpenMode *ret_ = new QIODevice::OpenMode(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QIODeviceOpenMode QIODeviceOpenMode.iand(QIODevice::QIODeviceOpenMode other);
KMETHOD QIODeviceOpenMode_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QIODevice::OpenMode *qp = RawPtr_to(QIODevice::OpenMode*, sfp[0]);
	if (qp != NULL) {
		QIODevice::OpenMode *other = RawPtr_to(QIODevice::OpenMode *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QIODeviceOpenMode QIODeviceOpenMode.or(QIODeviceOpenMode f);
KMETHOD QIODeviceOpenMode_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice::OpenMode *qp = RawPtr_to(QIODevice::OpenMode*, sfp[0]);
	if (qp != NULL) {
		QIODevice::OpenMode *f = RawPtr_to(QIODevice::OpenMode*, sfp[1]);
		QIODevice::OpenMode ret = ((*qp) | (*f));
		QIODevice::OpenMode *ret_ = new QIODevice::OpenMode(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QIODeviceOpenMode QIODeviceOpenMode.ior(QIODevice::QIODeviceOpenMode other);
KMETHOD QIODeviceOpenMode_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QIODevice::OpenMode *qp = RawPtr_to(QIODevice::OpenMode*, sfp[0]);
	if (qp != NULL) {
		QIODevice::OpenMode *other = RawPtr_to(QIODevice::OpenMode *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QIODeviceOpenMode QIODeviceOpenMode.xor(QIODeviceOpenMode f);
KMETHOD QIODeviceOpenMode_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice::OpenMode *qp = RawPtr_to(QIODevice::OpenMode*, sfp[0]);
	if (qp != NULL) {
		QIODevice::OpenMode *f = RawPtr_to(QIODevice::OpenMode*, sfp[1]);
		QIODevice::OpenMode ret = ((*qp) ^ (*f));
		QIODevice::OpenMode *ret_ = new QIODevice::OpenMode(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QIODeviceOpenMode QIODeviceOpenMode.ixor(QIODevice::QIODeviceOpenMode other);
KMETHOD QIODeviceOpenMode_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QIODevice::OpenMode *qp = RawPtr_to(QIODevice::OpenMode*, sfp[0]);
	if (qp != NULL) {
		QIODevice::OpenMode *other = RawPtr_to(QIODevice::OpenMode *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QIODeviceOpenMode.testFlag(int flag);
KMETHOD QIODeviceOpenMode_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QIODevice::OpenMode *qp = RawPtr_to(QIODevice::OpenMode *, sfp[0]);
	if (qp != NULL) {
		QIODevice::OpenModeFlag flag = Int_to(QIODevice::OpenModeFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QIODeviceOpenMode.value();
KMETHOD QIODeviceOpenMode_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QIODevice::OpenMode *qp = RawPtr_to(QIODevice::OpenMode *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QIODeviceOpenMode_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QIODevice::OpenMode *qp = (QIODevice::OpenMode *)p->rawptr;
		(void)qp;
		delete qp;
		p->rawptr = NULL;
	}
}

static void QIODeviceOpenMode_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QIODevice::OpenMode *qp = (QIODevice::OpenMode *)p->rawptr;
		(void)qp;
	}
}

static int QIODeviceOpenMode_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QIODevice::OpenMode*)p1->rawptr);
//		int v2 = int(*(QIODevice::OpenMode*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QIODevice::OpenMode v1 = *(QIODevice::OpenMode*)p1->rawptr;
		QIODevice::OpenMode v2 = *(QIODevice::OpenMode*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQIODeviceOpenMode(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QIODeviceOpenMode";
	cdef->free = QIODeviceOpenMode_free;
	cdef->reftrace = QIODeviceOpenMode_reftrace;
	cdef->compareTo = QIODeviceOpenMode_compareTo;
}

