//QDir QDir.new(QDir dir);
KMETHOD QDir_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QDir  dir = *RawPtr_to(const QDir *, sfp[1]);
	KQDir *ret_v = new KQDir(dir);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QDir QDir.new(String path);
KMETHOD QDir_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString path = String_to(const QString, sfp[1]);
	KQDir *ret_v = new KQDir(path);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QDir QDir.new(String path, String nameFilter, int sort);
KMETHOD QDir_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString path = String_to(const QString, sfp[1]);
	const QString nameFilter = String_to(const QString, sfp[2]);
	QDir::SortFlags sort = Int_to(QDir::SortFlags, sfp[3]);
	KQDir *ret_v = new KQDir(path, nameFilter, sort);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//String QDir.absoluteFilePath(String fileName);
KMETHOD QDir_absoluteFilePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		QString ret_v = qp->absoluteFilePath(fileName);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QDir.absolutePath();
KMETHOD QDir_absolutePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->absolutePath();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QDir.canonicalPath();
KMETHOD QDir_canonicalPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->canonicalPath();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QDir.cd(String dirName);
KMETHOD QDir_cd(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString dirName = String_to(const QString, sfp[1]);
		bool ret_v = qp->cd(dirName);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDir.cdUp();
KMETHOD QDir_cdUp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->cdUp();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QDir.count();
KMETHOD QDir_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		uint ret_v = qp->count();
		uint *ret_v_ = new uint(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QDir.dirName();
KMETHOD QDir_dirName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->dirName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QDir.exists(String name);
KMETHOD QDir_exists(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString name = String_to(const QString, sfp[1]);
		bool ret_v = qp->exists(name);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QDir.exists();
KMETHOD QDir_exists(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->exists();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//String QDir.filePath(String fileName);
KMETHOD QDir_filePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		QString ret_v = qp->filePath(fileName);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QDir.getFilter();
KMETHOD QDir_getFilter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		QDir::Filters ret_v = qp->filter();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QDir.isAbsolute();
KMETHOD QDir_isAbsolute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isAbsolute();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDir.isReadable();
KMETHOD QDir_isReadable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isReadable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDir.isRelative();
KMETHOD QDir_isRelative(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isRelative();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDir.isRoot();
KMETHOD QDir_isRoot(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isRoot();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDir.makeAbsolute();
KMETHOD QDir_makeAbsolute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->makeAbsolute();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDir.mkdir(String dirName);
KMETHOD QDir_mkdir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString dirName = String_to(const QString, sfp[1]);
		bool ret_v = qp->mkdir(dirName);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDir.mkpath(String dirPath);
KMETHOD QDir_mkpath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString dirPath = String_to(const QString, sfp[1]);
		bool ret_v = qp->mkpath(dirPath);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//String QDir.getPath();
KMETHOD QDir_getPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->path();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QDir.refresh();
KMETHOD QDir_refresh(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		qp->refresh();
	}
	RETURNvoid_();
}

//String QDir.relativeFilePath(String fileName);
KMETHOD QDir_relativeFilePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		QString ret_v = qp->relativeFilePath(fileName);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QDir.remove(String fileName);
KMETHOD QDir_remove(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString fileName = String_to(const QString, sfp[1]);
		bool ret_v = qp->remove(fileName);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDir.rename(String oldName, String new_Name);
KMETHOD QDir_rename(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString oldName = String_to(const QString, sfp[1]);
		const QString new_Name = String_to(const QString, sfp[2]);
		bool ret_v = qp->rename(oldName, new_Name);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDir.rmdir(String dirName);
KMETHOD QDir_rmdir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString dirName = String_to(const QString, sfp[1]);
		bool ret_v = qp->rmdir(dirName);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDir.rmpath(String dirPath);
KMETHOD QDir_rmpath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString dirPath = String_to(const QString, sfp[1]);
		bool ret_v = qp->rmpath(dirPath);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QDir.setFilter(int filters);
KMETHOD QDir_setFilter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		QDir::Filters filters = Int_to(QDir::Filters, sfp[1]);
		qp->setFilter(filters);
	}
	RETURNvoid_();
}

//void QDir.setPath(String path);
KMETHOD QDir_setPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString path = String_to(const QString, sfp[1]);
		qp->setPath(path);
	}
	RETURNvoid_();
}

//void QDir.setSorting(int sort);
KMETHOD QDir_setSorting(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		QDir::SortFlags sort = Int_to(QDir::SortFlags, sfp[1]);
		qp->setSorting(sort);
	}
	RETURNvoid_();
}

//int QDir.getSorting();
KMETHOD QDir_getSorting(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		QDir::SortFlags ret_v = qp->sorting();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QDir.addSearchPath(String prefix, String path);
KMETHOD QDir_addSearchPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString prefix = String_to(const QString, sfp[1]);
		const QString path = String_to(const QString, sfp[2]);
		qp->addSearchPath(prefix, path);
	}
	RETURNvoid_();
}

//String QDir.cleanPath(String path);
KMETHOD QDir_cleanPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString path = String_to(const QString, sfp[1]);
		QString ret_v = qp->cleanPath(path);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDir QDir.getCurrent();
KMETHOD QDir_getCurrent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		QDir ret_v = qp->current();
		QDir *ret_v_ = new QDir(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QDir.currentPath();
KMETHOD QDir_currentPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->currentPath();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QDir.fromNativeSeparators(String pathName);
KMETHOD QDir_fromNativeSeparators(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString pathName = String_to(const QString, sfp[1]);
		QString ret_v = qp->fromNativeSeparators(pathName);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDir QDir.home();
KMETHOD QDir_home(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		QDir ret_v = qp->home();
		QDir *ret_v_ = new QDir(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QDir.homePath();
KMETHOD QDir_homePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->homePath();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QDir.isAbsolutePath(String path);
KMETHOD QDir_isAbsolutePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString path = String_to(const QString, sfp[1]);
		bool ret_v = qp->isAbsolutePath(path);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDir.isRelativePath(String path);
KMETHOD QDir_isRelativePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString path = String_to(const QString, sfp[1]);
		bool ret_v = qp->isRelativePath(path);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDir.match(String filter, String fileName);
KMETHOD QDir_match(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString filter = String_to(const QString, sfp[1]);
		const QString fileName = String_to(const QString, sfp[2]);
		bool ret_v = qp->match(filter, fileName);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QDir QDir.root();
KMETHOD QDir_root(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		QDir ret_v = qp->root();
		QDir *ret_v_ = new QDir(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QDir.rootPath();
KMETHOD QDir_rootPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->rootPath();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QChar QDir.separator();
KMETHOD QDir_separator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		QChar ret_v = qp->separator();
		QChar *ret_v_ = new QChar(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QDir.setCurrent(String path);
KMETHOD QDir_setCurrent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString path = String_to(const QString, sfp[1]);
		bool ret_v = qp->setCurrent(path);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QDir QDir.temp();
KMETHOD QDir_temp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		QDir ret_v = qp->temp();
		QDir *ret_v_ = new QDir(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QDir.tempPath();
KMETHOD QDir_tempPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		QString ret_v = qp->tempPath();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QDir.toNativeSeparators(String pathName);
KMETHOD QDir_toNativeSeparators(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp != NULL) {
		const QString pathName = String_to(const QString, sfp[1]);
		QString ret_v = qp->toNativeSeparators(pathName);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQDir::DummyQDir()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQDir::setSelf(knh_RawPtr_t *ptr)
{
	DummyQDir::self = ptr;
}

bool DummyQDir::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQDir::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDir::event_map->bigin();
	if ((itr = DummyQDir::event_map->find(str)) == DummyQDir::event_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDir::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDir::slot_map->bigin();
	if ((itr = DummyQDir::event_map->find(str)) == DummyQDir::slot_map->end()) {
		bool ret;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQDir::KQDir(const QDir dir) : QDir(dir)
{
	self = NULL;
}

KMETHOD QDir_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDir *qp = RawPtr_to(KQDir *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QDir]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQDir::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDir]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QDir_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQDir *qp = RawPtr_to(KQDir *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QDir]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQDir::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QDir]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QDir_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQDir *qp = (KQDir *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QDir_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQDir *qp = (KQDir *)p->rawptr;
		(void)qp;
	}
}

static int QDir_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QDir*>(p1->rawptr) == *static_cast<QDir*>(p2->rawptr) ? 0 : 1);
}

DEFAPI(void) defQDir(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDir";
	cdef->free = QDir_free;
	cdef->reftrace = QDir_reftrace;
	cdef->compareTo = QDir_compareTo;
}

static knh_IntData_t QDirConstInt[] = {
	{"Dirs", QDir::Dirs},
	{"AllDirs", QDir::AllDirs},
	{"Files", QDir::Files},
	{"Drives", QDir::Drives},
	{"NoSymLinks", QDir::NoSymLinks},
	{"NoDotAndDotDot", QDir::NoDotAndDotDot},
	{"NoDot", QDir::NoDot},
	{"NoDotDot", QDir::NoDotDot},
	{"AllEntries", QDir::AllEntries},
	{"Readable", QDir::Readable},
	{"Writable", QDir::Writable},
	{"Executable", QDir::Executable},
	{"Modified", QDir::Modified},
	{"Hidden", QDir::Hidden},
	{"System", QDir::System},
	{"CaseSensitive", QDir::CaseSensitive},
	{"Name", QDir::Name},
	{"Time", QDir::Time},
	{"Size", QDir::Size},
	{"Type", QDir::Type},
	{"Unsorted", QDir::Unsorted},
	{"NoSort", QDir::NoSort},
	{"DirsFirst", QDir::DirsFirst},
	{"DirsLast", QDir::DirsLast},
	{"Reversed", QDir::Reversed},
	{"IgnoreCase", QDir::IgnoreCase},
	{"LocaleAware", QDir::LocaleAware},
	{NULL, 0}
};

DEFAPI(void) constQDir(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QDirConstInt);
}

