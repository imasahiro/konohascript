//boolean QAbstractFileEngine.atEnd();
KMETHOD QAbstractFileEngine_atEnd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->atEnd();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QAbstractFileEngine.caseSensitive();
KMETHOD QAbstractFileEngine_caseSensitive(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->caseSensitive();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QAbstractFileEngine.close();
KMETHOD QAbstractFileEngine_close(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->close();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QAbstractFileEngine.copy(String new_Name);
KMETHOD QAbstractFileEngine_copy(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		const QString new_Name = String_to(const QString, sfp[1]);
		bool ret_v = qp->copy(new_Name);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QAbstractFileEngine.errorString();
KMETHOD QAbstractFileEngine_errorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->errorString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual boolean QAbstractFileEngine.extension(int extension, int option, int output);
KMETHOD QAbstractFileEngine_extension(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		QAbstractFileEngine::Extension extension = Int_to(QAbstractFileEngine::Extension, sfp[1]);
		const QAbstractFileEngine::ExtensionOption*  option = RawPtr_to(const QAbstractFileEngine::ExtensionOption*, sfp[2]);
		QAbstractFileEngine::ExtensionReturn* output = Int_to(QAbstractFileEngine::ExtensionReturn*, sfp[3]);
		bool ret_v = qp->extension(extension, option, output);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual int QAbstractFileEngine.fileFlags(int type);
KMETHOD QAbstractFileEngine_fileFlags(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		QAbstractFileEngine::FileFlags type = Int_to(QAbstractFileEngine::FileFlags, sfp[1]);
		QAbstractFileEngine::FileFlags ret_v = qp->fileFlags(type);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual String QAbstractFileEngine.getFileName(int file);
KMETHOD QAbstractFileEngine_getFileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		QAbstractFileEngine::FileName file = Int_to(QAbstractFileEngine::FileName, sfp[1]);
		QString ret_v = qp->fileName(file);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual QDateTime QAbstractFileEngine.fileTime(int time);
KMETHOD QAbstractFileEngine_fileTime(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		QAbstractFileEngine::FileTime time = Int_to(QAbstractFileEngine::FileTime, sfp[1]);
		QDateTime ret_v = qp->fileTime(time);
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual boolean QAbstractFileEngine.flush();
KMETHOD QAbstractFileEngine_flush(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->flush();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual int QAbstractFileEngine.handle();
KMETHOD QAbstractFileEngine_handle(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->handle();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual boolean QAbstractFileEngine.isRelativePath();
KMETHOD QAbstractFileEngine_isRelativePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isRelativePath();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QAbstractFileEngine.isSequential();
KMETHOD QAbstractFileEngine_isSequential(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isSequential();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QAbstractFileEngine.link(String new_Name);
KMETHOD QAbstractFileEngine_link(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		const QString new_Name = String_to(const QString, sfp[1]);
		bool ret_v = qp->link(new_Name);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QAbstractFileEngine.mkdir(String dirName, boolean createParentDirectories);
KMETHOD QAbstractFileEngine_mkdir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		const QString dirName = String_to(const QString, sfp[1]);
		bool createParentDirectories = Boolean_to(bool, sfp[2]);
		bool ret_v = qp->mkdir(dirName, createParentDirectories);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QAbstractFileEngine.open(int mode);
KMETHOD QAbstractFileEngine_open(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		QIODevice::OpenMode mode = Int_to(QIODevice::OpenMode, sfp[1]);
		bool ret_v = qp->open(mode);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual String QAbstractFileEngine.owner(int owner);
KMETHOD QAbstractFileEngine_owner(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		QAbstractFileEngine::FileOwner owner = Int_to(QAbstractFileEngine::FileOwner, sfp[1]);
		QString ret_v = qp->owner(owner);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual int QAbstractFileEngine.ownerId(int owner);
KMETHOD QAbstractFileEngine_ownerId(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		QAbstractFileEngine::FileOwner owner = Int_to(QAbstractFileEngine::FileOwner, sfp[1]);
		uint ret_v = qp->ownerId(owner);
		uint *ret_v_ = new uint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual int QAbstractFileEngine.pos();
KMETHOD QAbstractFileEngine_pos(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		qint64 ret_v = qp->pos();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual int QAbstractFileEngine.read(String data, int maxlen);
KMETHOD QAbstractFileEngine_read(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
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

//@Virtual int QAbstractFileEngine.readLine(String data, int maxlen);
KMETHOD QAbstractFileEngine_readLine(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		char*  data = RawPtr_to(char*, sfp[1]);
		qint64 maxlen = Int_to(qint64, sfp[2]);
		qint64 ret_v = qp->readLine(data, maxlen);
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual boolean QAbstractFileEngine.remove();
KMETHOD QAbstractFileEngine_remove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->remove();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QAbstractFileEngine.rename(String new_Name);
KMETHOD QAbstractFileEngine_rename(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		const QString new_Name = String_to(const QString, sfp[1]);
		bool ret_v = qp->rename(new_Name);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QAbstractFileEngine.rmdir(String dirName, boolean recurseParentDirectories);
KMETHOD QAbstractFileEngine_rmdir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		const QString dirName = String_to(const QString, sfp[1]);
		bool recurseParentDirectories = Boolean_to(bool, sfp[2]);
		bool ret_v = qp->rmdir(dirName, recurseParentDirectories);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QAbstractFileEngine.seek(int offset);
KMETHOD QAbstractFileEngine_seek(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		qint64 offset = Int_to(qint64, sfp[1]);
		bool ret_v = qp->seek(offset);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual void QAbstractFileEngine.setFileName(String file);
KMETHOD QAbstractFileEngine_setFileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		const QString file = String_to(const QString, sfp[1]);
		qp->setFileName(file);
	}
	RETURNvoid_();
}

//@Virtual boolean QAbstractFileEngine.setPermissions(int perms);
KMETHOD QAbstractFileEngine_setPermissions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		uint  perms = *RawPtr_to(uint *, sfp[1]);
		bool ret_v = qp->setPermissions(perms);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual boolean QAbstractFileEngine.setSize(int size);
KMETHOD QAbstractFileEngine_setSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		qint64 size = Int_to(qint64, sfp[1]);
		bool ret_v = qp->setSize(size);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual int QAbstractFileEngine.getSize();
KMETHOD QAbstractFileEngine_getSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		qint64 ret_v = qp->size();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual boolean QAbstractFileEngine.supportsExtension(int extension);
KMETHOD QAbstractFileEngine_supportsExtension(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		QAbstractFileEngine::Extension extension = Int_to(QAbstractFileEngine::Extension, sfp[1]);
		bool ret_v = qp->supportsExtension(extension);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QAbstractFileEngine.unmap(String address);
KMETHOD QAbstractFileEngine_unmap(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		uchar*  address = RawPtr_to(uchar*, sfp[1]);
		bool ret_v = qp->unmap(address);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual int QAbstractFileEngine.write(String data, int len);
KMETHOD QAbstractFileEngine_write(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		const char*  data = RawPtr_to(const char*, sfp[1]);
		qint64 len = Int_to(qint64, sfp[2]);
		qint64 ret_v = qp->write(data, len);
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAbstractFileEngine QAbstractFileEngine.create(String fileName);
KMETHOD QAbstractFileEngine_create(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QAbstractFileEngine *  qp = RawPtr_to(QAbstractFileEngine *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		QAbstractFileEngine* ret_v = qp->create(fileName);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAbstractFileEngine*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQAbstractFileEngine::DummyQAbstractFileEngine()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQAbstractFileEngine::setSelf(knh_RawPtr_t *ptr)
{
	DummyQAbstractFileEngine::self = ptr;
}

bool DummyQAbstractFileEngine::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQAbstractFileEngine::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractFileEngine::event_map->bigin();
	if ((itr = DummyQAbstractFileEngine::event_map->find(str)) == DummyQAbstractFileEngine::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQAbstractFileEngine::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQAbstractFileEngine::slot_map->bigin();
	if ((itr = DummyQAbstractFileEngine::event_map->find(str)) == DummyQAbstractFileEngine::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQAbstractFileEngine::KQAbstractFileEngine() : QAbstractFileEngine()
{
	self = NULL;
}

KMETHOD QAbstractFileEngine_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractFileEngine *qp = RawPtr_to(KQAbstractFileEngine *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractFileEngine]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQAbstractFileEngine::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractFileEngine]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QAbstractFileEngine_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQAbstractFileEngine *qp = RawPtr_to(KQAbstractFileEngine *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QAbstractFileEngine]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQAbstractFileEngine::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QAbstractFileEngine]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QAbstractFileEngine_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQAbstractFileEngine *qp = (KQAbstractFileEngine *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QAbstractFileEngine_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQAbstractFileEngine *qp = (KQAbstractFileEngine *)p->rawptr;
		(void)qp;
	}
}

static int QAbstractFileEngine_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQAbstractFileEngine(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QAbstractFileEngine";
	cdef->free = QAbstractFileEngine_free;
	cdef->reftrace = QAbstractFileEngine_reftrace;
	cdef->compareTo = QAbstractFileEngine_compareTo;
}

static knh_IntData_t QAbstractFileEngineConstInt[] = {
	{"AtEndExtension", QAbstractFileEngine::AtEndExtension},
	{"FastReadLineExtension", QAbstractFileEngine::FastReadLineExtension},
	{"MapExtension", QAbstractFileEngine::MapExtension},
	{"UnMapExtension", QAbstractFileEngine::UnMapExtension},
	{"ReadOwnerPerm", QAbstractFileEngine::ReadOwnerPerm},
	{"WriteOwnerPerm", QAbstractFileEngine::WriteOwnerPerm},
	{"ExeOwnerPerm", QAbstractFileEngine::ExeOwnerPerm},
	{"ReadUserPerm", QAbstractFileEngine::ReadUserPerm},
	{"WriteUserPerm", QAbstractFileEngine::WriteUserPerm},
	{"ExeUserPerm", QAbstractFileEngine::ExeUserPerm},
	{"ReadGroupPerm", QAbstractFileEngine::ReadGroupPerm},
	{"WriteGroupPerm", QAbstractFileEngine::WriteGroupPerm},
	{"ExeGroupPerm", QAbstractFileEngine::ExeGroupPerm},
	{"ReadOtherPerm", QAbstractFileEngine::ReadOtherPerm},
	{"WriteOtherPerm", QAbstractFileEngine::WriteOtherPerm},
	{"ExeOtherPerm", QAbstractFileEngine::ExeOtherPerm},
	{"LinkType", QAbstractFileEngine::LinkType},
	{"FileType", QAbstractFileEngine::FileType},
	{"BundleType", QAbstractFileEngine::BundleType},
	{"DirectoryType", QAbstractFileEngine::DirectoryType},
	{"HiddenFlag", QAbstractFileEngine::HiddenFlag},
	{"ExistsFlag", QAbstractFileEngine::ExistsFlag},
	{"RootFlag", QAbstractFileEngine::RootFlag},
	{"LocalDiskFlag", QAbstractFileEngine::LocalDiskFlag},
	{"Refresh", QAbstractFileEngine::Refresh},
	{"DefaultName", QAbstractFileEngine::DefaultName},
	{"BaseName", QAbstractFileEngine::BaseName},
	{"PathName", QAbstractFileEngine::PathName},
	{"AbsoluteName", QAbstractFileEngine::AbsoluteName},
	{"AbsolutePathName", QAbstractFileEngine::AbsolutePathName},
	{"LinkName", QAbstractFileEngine::LinkName},
	{"CanonicalName", QAbstractFileEngine::CanonicalName},
	{"CanonicalPathName", QAbstractFileEngine::CanonicalPathName},
	{"BundleName", QAbstractFileEngine::BundleName},
	{"OwnerUser", QAbstractFileEngine::OwnerUser},
	{"OwnerGroup", QAbstractFileEngine::OwnerGroup},
	{"CreationTime", QAbstractFileEngine::CreationTime},
	{"ModificationTime", QAbstractFileEngine::ModificationTime},
	{"AccessTime", QAbstractFileEngine::AccessTime},
	{NULL, 0}
};

DEFAPI(void) constQAbstractFileEngine(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QAbstractFileEngineConstInt);
}

