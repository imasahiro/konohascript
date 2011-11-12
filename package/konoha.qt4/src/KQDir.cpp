//QDir QDir.new(QDir dir);
KMETHOD QDir_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QDir  dir = *RawPtr_to(const QDir *, sfp[1]);
	KQDir *ret_v = new KQDir(dir);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
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
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QDir QDir.new(String path, String nameFilter, QDirSortFlags sort);
KMETHOD QDir_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString path = String_to(const QString, sfp[1]);
	const QString nameFilter = String_to(const QString, sfp[2]);
	initFlag(sort, QDir::SortFlags, sfp[3]);
	KQDir *ret_v = new KQDir(path, nameFilter, sort);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//String QDir.absoluteFilePath(String fileName);
KMETHOD QDir_absoluteFilePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		const QString fileName = String_to(const QString, sfp[1]);
		QString ret_v = qp->filePath(fileName);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDirFilters QDir.getFilter();
KMETHOD QDir_getFilter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp) {
		QDir::Filters ret_v = qp->filter();
		QDir::Filters *ret_v_ = new QDir::Filters(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QDir.isAbsolute();
KMETHOD QDir_isAbsolute(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		qp->refresh();
	}
	RETURNvoid_();
}

//String QDir.relativeFilePath(String fileName);
KMETHOD QDir_relativeFilePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
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
	if (qp) {
		const QString dirPath = String_to(const QString, sfp[1]);
		bool ret_v = qp->rmpath(dirPath);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QDir.setFilter(QDirFilters filters);
KMETHOD QDir_setFilter(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp) {
		initFlag(filters, QDir::Filters, sfp[1]);
		qp->setFilter(filters);
	}
	RETURNvoid_();
}

//void QDir.setPath(String path);
KMETHOD QDir_setPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp) {
		const QString path = String_to(const QString, sfp[1]);
		qp->setPath(path);
	}
	RETURNvoid_();
}

//void QDir.setSorting(QDirSortFlags sort);
KMETHOD QDir_setSorting(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp) {
		initFlag(sort, QDir::SortFlags, sfp[1]);
		qp->setSorting(sort);
	}
	RETURNvoid_();
}

//QDirSortFlags QDir.getSorting();
KMETHOD QDir_getSorting(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *  qp = RawPtr_to(QDir *, sfp[0]);
	if (qp) {
		QDir::SortFlags ret_v = qp->sorting();
		QDir::SortFlags *ret_v_ = new QDir::SortFlags(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QDir.addSearchPath(String prefix, String path);
KMETHOD QDir_addSearchPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString prefix = String_to(const QString, sfp[1]);
		const QString path = String_to(const QString, sfp[2]);
		QDir::addSearchPath(prefix, path);
	}
	RETURNvoid_();
}

//String QDir.cleanPath(String path);
KMETHOD QDir_cleanPath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString path = String_to(const QString, sfp[1]);
		QString ret_v = QDir::cleanPath(path);
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
	if (true) {
		QDir ret_v = QDir::current();
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
	if (true) {
		QString ret_v = QDir::currentPath();
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
	if (true) {
		const QString pathName = String_to(const QString, sfp[1]);
		QString ret_v = QDir::fromNativeSeparators(pathName);
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
	if (true) {
		QDir ret_v = QDir::home();
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
	if (true) {
		QString ret_v = QDir::homePath();
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
	if (true) {
		const QString path = String_to(const QString, sfp[1]);
		bool ret_v = QDir::isAbsolutePath(path);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDir.isRelativePath(String path);
KMETHOD QDir_isRelativePath(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString path = String_to(const QString, sfp[1]);
		bool ret_v = QDir::isRelativePath(path);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QDir.match(String filter, String fileName);
KMETHOD QDir_match(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QString filter = String_to(const QString, sfp[1]);
		const QString fileName = String_to(const QString, sfp[2]);
		bool ret_v = QDir::match(filter, fileName);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QDir QDir.root();
KMETHOD QDir_root(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QDir ret_v = QDir::root();
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
	if (true) {
		QString ret_v = QDir::rootPath();
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
	if (true) {
		QChar ret_v = QDir::separator();
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
	if (true) {
		const QString path = String_to(const QString, sfp[1]);
		bool ret_v = QDir::setCurrent(path);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QDir QDir.temp();
KMETHOD QDir_temp(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QDir ret_v = QDir::temp();
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
	if (true) {
		QString ret_v = QDir::tempPath();
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
	if (true) {
		const QString pathName = String_to(const QString, sfp[1]);
		QString ret_v = QDir::toNativeSeparators(pathName);
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//Array<String> QDir.parents();
KMETHOD QDir_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir *qp = RawPtr_to(QDir*, sfp[0]);
	if (qp != NULL) {
		int size = 10;
		knh_Array_t *a = new_Array0(ctx, size);
		const knh_ClassTBL_t *ct = sfp[0].p->h.cTBL;
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
		}
		RETURN_(a);
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
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQDir::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQDir::slot_map->bigin();
	if ((itr = DummyQDir::slot_map->find(str)) == DummyQDir::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQDir::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQDir::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQDir::connection(QObject *o)
{
	QDir *p = dynamic_cast<QDir*>(o);
	if (p != NULL) {
	}
}

KQDir::KQDir(const QDir dir) : QDir(dir)
{
	self = NULL;
	dummy = new DummyQDir();
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
		if (!qp->dummy->addEvent(callback_func, str)) {
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
		if (!qp->dummy->signalConnect(callback_func, str)) {
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
	if (p->rawptr != NULL) {
		KQDir *qp = (KQDir *)p->rawptr;
//		KQDir *qp = static_cast<KQDir*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QDir_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QDir*>(p1->rawptr) == *static_cast<QDir*>(p2->rawptr) ? 0 : 1);
}

void KQDir::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
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


DEFAPI(void) defQDir(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDir";
	cdef->free = QDir_free;
	cdef->reftrace = QDir_reftrace;
	cdef->compareTo = QDir_compareTo;
}

//## QDirFilters QDirFilters.new(int value);
KMETHOD QDirFilters_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDir::Filter i = Int_to(QDir::Filter, sfp[1]);
	QDir::Filters *ret_v = new QDir::Filters(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QDirFilters QDirFilters.and(int mask);
KMETHOD QDirFilters_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDir::Filters *qp = RawPtr_to(QDir::Filters*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QDir::Filters ret = ((*qp) & i);
		QDir::Filters *ret_ = new QDir::Filters(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QDirFilters QDirFilters.iand(QDir::QDirFilters other);
KMETHOD QDirFilters_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDir::Filters *qp = RawPtr_to(QDir::Filters*, sfp[0]);
	if (qp != NULL) {
		QDir::Filters *other = RawPtr_to(QDir::Filters *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QDirFilters QDirFilters.or(QDirFilters f);
KMETHOD QDirFilters_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir::Filters *qp = RawPtr_to(QDir::Filters*, sfp[0]);
	if (qp != NULL) {
		QDir::Filters *f = RawPtr_to(QDir::Filters*, sfp[1]);
		QDir::Filters ret = ((*qp) | (*f));
		QDir::Filters *ret_ = new QDir::Filters(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QDirFilters QDirFilters.ior(QDir::QDirFilters other);
KMETHOD QDirFilters_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDir::Filters *qp = RawPtr_to(QDir::Filters*, sfp[0]);
	if (qp != NULL) {
		QDir::Filters *other = RawPtr_to(QDir::Filters *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QDirFilters QDirFilters.xor(QDirFilters f);
KMETHOD QDirFilters_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir::Filters *qp = RawPtr_to(QDir::Filters*, sfp[0]);
	if (qp != NULL) {
		QDir::Filters *f = RawPtr_to(QDir::Filters*, sfp[1]);
		QDir::Filters ret = ((*qp) ^ (*f));
		QDir::Filters *ret_ = new QDir::Filters(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QDirFilters QDirFilters.ixor(QDir::QDirFilters other);
KMETHOD QDirFilters_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDir::Filters *qp = RawPtr_to(QDir::Filters*, sfp[0]);
	if (qp != NULL) {
		QDir::Filters *other = RawPtr_to(QDir::Filters *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QDirFilters.testFlag(int flag);
KMETHOD QDirFilters_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDir::Filters *qp = RawPtr_to(QDir::Filters *, sfp[0]);
	if (qp != NULL) {
		QDir::Filter flag = Int_to(QDir::Filter, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QDirFilters.value();
KMETHOD QDirFilters_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDir::Filters *qp = RawPtr_to(QDir::Filters *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QDirFilters_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QDir::Filters *qp = (QDir::Filters *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QDirFilters_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QDir::Filters *qp = (QDir::Filters *)p->rawptr;
		(void)qp;
	}
}

static int QDirFilters_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QDir::Filters*)p1->rawptr);
//		int v2 = int(*(QDir::Filters*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QDir::Filters v1 = *(QDir::Filters*)p1->rawptr;
		QDir::Filters v2 = *(QDir::Filters*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQDirFilters(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDirFilters";
	cdef->free = QDirFilters_free;
	cdef->reftrace = QDirFilters_reftrace;
	cdef->compareTo = QDirFilters_compareTo;
}
//## QDirSortFlags QDirSortFlags.new(int value);
KMETHOD QDirSortFlags_new(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDir::SortFlag i = Int_to(QDir::SortFlag, sfp[1]);
	QDir::SortFlags *ret_v = new QDir::SortFlags(i);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	RETURN_(rptr);
}

//## QDirSortFlags QDirSortFlags.and(int mask);
KMETHOD QDirSortFlags_and(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDir::SortFlags *qp = RawPtr_to(QDir::SortFlags*, sfp[0]);
	if (qp != NULL) {
		int i = Int_to(int, sfp[1]);
		QDir::SortFlags ret = ((*qp) & i);
		QDir::SortFlags *ret_ = new QDir::SortFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QDirSortFlags QDirSortFlags.iand(QDir::QDirSortFlags other);
KMETHOD QDirSortFlags_iand(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDir::SortFlags *qp = RawPtr_to(QDir::SortFlags*, sfp[0]);
	if (qp != NULL) {
		QDir::SortFlags *other = RawPtr_to(QDir::SortFlags *, sfp[1]);
		*qp = ((*qp) & (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QDirSortFlags QDirSortFlags.or(QDirSortFlags f);
KMETHOD QDirSortFlags_or(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir::SortFlags *qp = RawPtr_to(QDir::SortFlags*, sfp[0]);
	if (qp != NULL) {
		QDir::SortFlags *f = RawPtr_to(QDir::SortFlags*, sfp[1]);
		QDir::SortFlags ret = ((*qp) | (*f));
		QDir::SortFlags *ret_ = new QDir::SortFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QDirSortFlags QDirSortFlags.ior(QDir::QDirSortFlags other);
KMETHOD QDirSortFlags_ior(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDir::SortFlags *qp = RawPtr_to(QDir::SortFlags*, sfp[0]);
	if (qp != NULL) {
		QDir::SortFlags *other = RawPtr_to(QDir::SortFlags *, sfp[1]);
		*qp = ((*qp) | (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QDirSortFlags QDirSortFlags.xor(QDirSortFlags f);
KMETHOD QDirSortFlags_xor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QDir::SortFlags *qp = RawPtr_to(QDir::SortFlags*, sfp[0]);
	if (qp != NULL) {
		QDir::SortFlags *f = RawPtr_to(QDir::SortFlags*, sfp[1]);
		QDir::SortFlags ret = ((*qp) ^ (*f));
		QDir::SortFlags *ret_ = new QDir::SortFlags(ret);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## QDirSortFlags QDirSortFlags.ixor(QDir::QDirSortFlags other);
KMETHOD QDirSortFlags_ixor(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDir::SortFlags *qp = RawPtr_to(QDir::SortFlags*, sfp[0]);
	if (qp != NULL) {
		QDir::SortFlags *other = RawPtr_to(QDir::SortFlags *, sfp[1]);
		*qp = ((*qp) ^ (*other));
		RETURN_(qp);
	} else {
		RETURN_(KNH_NULL);
	}
}

//## boolean QDirSortFlags.testFlag(int flag);
KMETHOD QDirSortFlags_testFlag(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDir::SortFlags *qp = RawPtr_to(QDir::SortFlags *, sfp[0]);
	if (qp != NULL) {
		QDir::SortFlag flag = Int_to(QDir::SortFlag, sfp[1]);
		bool ret = qp->testFlag(flag);
		RETURNb_(ret);
	} else {
		RETURNb_(false);
	}
}

//## int QDirSortFlags.value();
KMETHOD QDirSortFlags_value(CTX ctx, knh_sfp_t *sfp _RIX) {
	(void)ctx;
	QDir::SortFlags *qp = RawPtr_to(QDir::SortFlags *, sfp[0]);
	if (qp != NULL) {
		int ret = int(*qp);
		RETURNi_(ret);
	} else {
		RETURNi_(0);
	}
}

static void QDirSortFlags_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		QDir::SortFlags *qp = (QDir::SortFlags *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}

static void QDirSortFlags_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		QDir::SortFlags *qp = (QDir::SortFlags *)p->rawptr;
		(void)qp;
	}
}

static int QDirSortFlags_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	if (p1->rawptr == NULL || p2->rawptr == NULL) {
		return 1;
	} else {
//		int v1 = int(*(QDir::SortFlags*)p1->rawptr);
//		int v2 = int(*(QDir::SortFlags*)p2->rawptr);
//		return (v1 == v2 ? 0 : 1);
		QDir::SortFlags v1 = *(QDir::SortFlags*)p1->rawptr;
		QDir::SortFlags v2 = *(QDir::SortFlags*)p2->rawptr;
//		return (v1 == v2 ? 0 : 1);
		return (v1 == v2 ? 0 : 1);

	}
}

DEFAPI(void) defQDirSortFlags(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QDirSortFlags";
	cdef->free = QDirSortFlags_free;
	cdef->reftrace = QDirSortFlags_reftrace;
	cdef->compareTo = QDirSortFlags_compareTo;
}

