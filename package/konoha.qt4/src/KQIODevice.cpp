//
/*
//*/
//@Virtual boolean QIODevice.atEnd();
KMETHOD QIODevice_atEnd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		qp->close();
	}
	RETURNvoid_();
}

//String QIODevice.errorString();
KMETHOD QIODevice_errorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
		bool ret_v = qp->isWritable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QIODevice.open(int mode);
KMETHOD QIODevice_open(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp != NULL) {
		QIODevice::OpenMode  mode = *RawPtr_to(QIODevice::OpenMode *, sfp[1]);
		bool ret_v = qp->open(mode);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QIODevice.openMode();
KMETHOD QIODevice_openMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice *  qp = RawPtr_to(QIODevice *, sfp[0]);
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	if (qp != NULL) {
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
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
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

bool DummyQIODevice::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQIODevice::event_map->bigin();
	if ((itr = DummyQIODevice::event_map->find(str)) == DummyQIODevice::event_map->end()) {
		bool ret;
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
	if ((itr = DummyQIODevice::event_map->find(str)) == DummyQIODevice::slot_map->end()) {
		bool ret;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQIODevice::KQIODevice() : QIODevice()
{
	self = NULL;
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
		if (!qp->DummyQIODevice::addEvent(callback_func, str)) {
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
		if (!qp->DummyQIODevice::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QIODevice]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QIODevice_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQIODevice *qp = (KQIODevice *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QIODevice_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQIODevice *qp = (KQIODevice *)p->rawptr;
		(void)qp;
	}
}

static int QIODevice_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQIODevice::event(QEvent *event)
{
	if (!DummyQIODevice::eventDispatcher(event)) {
		QIODevice::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQIODevice(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QIODevice";
	cdef->free = QIODevice_free;
	cdef->reftrace = QIODevice_reftrace;
	cdef->compareTo = QIODevice_compareTo;
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

