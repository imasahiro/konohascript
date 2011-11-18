//QUrlInfo QUrlInfo.new();
KMETHOD QUrlInfo_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQUrlInfo *ret_v = new KQUrlInfo();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QUrlInfo QUrlInfo.new(QUrlInfo ui);
KMETHOD QUrlInfo_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QUrlInfo  ui = *RawPtr_to(const QUrlInfo *, sfp[1]);
	KQUrlInfo *ret_v = new KQUrlInfo(ui);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QUrlInfo QUrlInfo.new(String name, int permissions, String owner, String group, int size, QDateTime lastModified, QDateTime lastRead, boolean isDir, boolean isFile, boolean isSymLink, boolean isWritable, boolean isReadable, boolean isExecutable);
KMETHOD QUrlInfo_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString name = String_to(const QString, sfp[1]);
	int permissions = Int_to(int, sfp[2]);
	const QString owner = String_to(const QString, sfp[3]);
	const QString group = String_to(const QString, sfp[4]);
	qint64 size = Int_to(qint64, sfp[5]);
	const QDateTime  lastModified = *RawPtr_to(const QDateTime *, sfp[6]);
	const QDateTime  lastRead = *RawPtr_to(const QDateTime *, sfp[7]);
	bool isDir = Boolean_to(bool, sfp[8]);
	bool isFile = Boolean_to(bool, sfp[9]);
	bool isSymLink = Boolean_to(bool, sfp[10]);
	bool isWritable = Boolean_to(bool, sfp[11]);
	bool isReadable = Boolean_to(bool, sfp[12]);
	bool isExecutable = Boolean_to(bool, sfp[13]);
	KQUrlInfo *ret_v = new KQUrlInfo(name, permissions, owner, group, size, lastModified, lastRead, isDir, isFile, isSymLink, isWritable, isReadable, isExecutable);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QUrlInfo QUrlInfo.new(QUrl url, int permissions, String owner, String group, int size, QDateTime lastModified, QDateTime lastRead, boolean isDir, boolean isFile, boolean isSymLink, boolean isWritable, boolean isReadable, boolean isExecutable);
KMETHOD QUrlInfo_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QUrl  url = *RawPtr_to(const QUrl *, sfp[1]);
	int permissions = Int_to(int, sfp[2]);
	const QString owner = String_to(const QString, sfp[3]);
	const QString group = String_to(const QString, sfp[4]);
	qint64 size = Int_to(qint64, sfp[5]);
	const QDateTime  lastModified = *RawPtr_to(const QDateTime *, sfp[6]);
	const QDateTime  lastRead = *RawPtr_to(const QDateTime *, sfp[7]);
	bool isDir = Boolean_to(bool, sfp[8]);
	bool isFile = Boolean_to(bool, sfp[9]);
	bool isSymLink = Boolean_to(bool, sfp[10]);
	bool isWritable = Boolean_to(bool, sfp[11]);
	bool isReadable = Boolean_to(bool, sfp[12]);
	bool isExecutable = Boolean_to(bool, sfp[13]);
	KQUrlInfo *ret_v = new KQUrlInfo(url, permissions, owner, group, size, lastModified, lastRead, isDir, isFile, isSymLink, isWritable, isReadable, isExecutable);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//String QUrlInfo.getGroup();
KMETHOD QUrlInfo_getGroup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		QString ret_v = qp->group();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QUrlInfo.isDir();
KMETHOD QUrlInfo_isDir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isDir();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QUrlInfo.isExecutable();
KMETHOD QUrlInfo_isExecutable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isExecutable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QUrlInfo.isFile();
KMETHOD QUrlInfo_isFile(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isFile();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QUrlInfo.isReadable();
KMETHOD QUrlInfo_isReadable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isReadable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QUrlInfo.isSymLink();
KMETHOD QUrlInfo_isSymLink(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isSymLink();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QUrlInfo.isWritable();
KMETHOD QUrlInfo_isWritable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isWritable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QDateTime QUrlInfo.getLastModified();
KMETHOD QUrlInfo_getLastModified(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		QDateTime ret_v = qp->lastModified();
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QDateTime QUrlInfo.getLastRead();
KMETHOD QUrlInfo_getLastRead(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		QDateTime ret_v = qp->lastRead();
		QDateTime *ret_v_ = new QDateTime(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QUrlInfo.getName();
KMETHOD QUrlInfo_getName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		QString ret_v = qp->name();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QUrlInfo.getOwner();
KMETHOD QUrlInfo_getOwner(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		QString ret_v = qp->owner();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QUrlInfo.getPermissions();
KMETHOD QUrlInfo_getPermissions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		int ret_v = qp->permissions();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual void QUrlInfo.setDir(boolean b);
KMETHOD QUrlInfo_setDir(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		bool b = Boolean_to(bool, sfp[1]);
		qp->setDir(b);
	}
	RETURNvoid_();
}

//@Virtual void QUrlInfo.setFile(boolean b);
KMETHOD QUrlInfo_setFile(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		bool b = Boolean_to(bool, sfp[1]);
		qp->setFile(b);
	}
	RETURNvoid_();
}

//@Virtual void QUrlInfo.setGroup(String s);
KMETHOD QUrlInfo_setGroup(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		const QString s = String_to(const QString, sfp[1]);
		qp->setGroup(s);
	}
	RETURNvoid_();
}

//@Virtual void QUrlInfo.setLastModified(QDateTime dt);
KMETHOD QUrlInfo_setLastModified(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		const QDateTime  dt = *RawPtr_to(const QDateTime *, sfp[1]);
		qp->setLastModified(dt);
	}
	RETURNvoid_();
}

//void QUrlInfo.setLastRead(QDateTime dt);
KMETHOD QUrlInfo_setLastRead(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		const QDateTime  dt = *RawPtr_to(const QDateTime *, sfp[1]);
		qp->setLastRead(dt);
	}
	RETURNvoid_();
}

//@Virtual void QUrlInfo.setName(String name);
KMETHOD QUrlInfo_setName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		const QString name = String_to(const QString, sfp[1]);
		qp->setName(name);
	}
	RETURNvoid_();
}

//@Virtual void QUrlInfo.setOwner(String s);
KMETHOD QUrlInfo_setOwner(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		const QString s = String_to(const QString, sfp[1]);
		qp->setOwner(s);
	}
	RETURNvoid_();
}

//@Virtual void QUrlInfo.setPermissions(int p);
KMETHOD QUrlInfo_setPermissions(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		int p = Int_to(int, sfp[1]);
		qp->setPermissions(p);
	}
	RETURNvoid_();
}

//@Virtual void QUrlInfo.setReadable(boolean b);
KMETHOD QUrlInfo_setReadable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		bool b = Boolean_to(bool, sfp[1]);
		qp->setReadable(b);
	}
	RETURNvoid_();
}

//@Virtual void QUrlInfo.setSize(int size);
KMETHOD QUrlInfo_setSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		qint64 size = Int_to(qint64, sfp[1]);
		qp->setSize(size);
	}
	RETURNvoid_();
}

//@Virtual void QUrlInfo.setSymLink(boolean b);
KMETHOD QUrlInfo_setSymLink(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		bool b = Boolean_to(bool, sfp[1]);
		qp->setSymLink(b);
	}
	RETURNvoid_();
}

//@Virtual void QUrlInfo.setWritable(boolean b);
KMETHOD QUrlInfo_setWritable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		bool b = Boolean_to(bool, sfp[1]);
		qp->setWritable(b);
	}
	RETURNvoid_();
}

//int QUrlInfo.getSize();
KMETHOD QUrlInfo_getSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *  qp = RawPtr_to(QUrlInfo *, sfp[0]);
	if (qp) {
		qint64 ret_v = qp->size();
		qint64 *ret_v_ = new qint64(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QUrlInfo.equal(QUrlInfo i1, QUrlInfo i2, int sortBy);
KMETHOD QUrlInfo_equal(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QUrlInfo  i1 = *RawPtr_to(const QUrlInfo *, sfp[1]);
		const QUrlInfo  i2 = *RawPtr_to(const QUrlInfo *, sfp[2]);
		int sortBy = Int_to(int, sfp[3]);
		bool ret_v = QUrlInfo::equal(i1, i2, sortBy);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QUrlInfo.greaterThan(QUrlInfo i1, QUrlInfo i2, int sortBy);
KMETHOD QUrlInfo_greaterThan(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QUrlInfo  i1 = *RawPtr_to(const QUrlInfo *, sfp[1]);
		const QUrlInfo  i2 = *RawPtr_to(const QUrlInfo *, sfp[2]);
		int sortBy = Int_to(int, sfp[3]);
		bool ret_v = QUrlInfo::greaterThan(i1, i2, sortBy);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QUrlInfo.lessThan(QUrlInfo i1, QUrlInfo i2, int sortBy);
KMETHOD QUrlInfo_lessThan(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		const QUrlInfo  i1 = *RawPtr_to(const QUrlInfo *, sfp[1]);
		const QUrlInfo  i2 = *RawPtr_to(const QUrlInfo *, sfp[2]);
		int sortBy = Int_to(int, sfp[3]);
		bool ret_v = QUrlInfo::lessThan(i1, i2, sortBy);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//Array<String> QUrlInfo.parents();
KMETHOD QUrlInfo_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QUrlInfo *qp = RawPtr_to(QUrlInfo*, sfp[0]);
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

DummyQUrlInfo::DummyQUrlInfo()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQUrlInfo::~DummyQUrlInfo()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQUrlInfo::setSelf(knh_RawPtr_t *ptr)
{
	DummyQUrlInfo::self = ptr;
}

bool DummyQUrlInfo::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQUrlInfo::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQUrlInfo::event_map->bigin();
	if ((itr = DummyQUrlInfo::event_map->find(str)) == DummyQUrlInfo::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQUrlInfo::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQUrlInfo::slot_map->bigin();
	if ((itr = DummyQUrlInfo::slot_map->find(str)) == DummyQUrlInfo::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQUrlInfo::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQUrlInfo::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQUrlInfo::connection(QObject *o)
{
	QUrlInfo *p = dynamic_cast<QUrlInfo*>(o);
	if (p != NULL) {
	}
}

KQUrlInfo::KQUrlInfo() : QUrlInfo()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQUrlInfo();
}

KQUrlInfo::~KQUrlInfo()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QUrlInfo_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQUrlInfo *qp = RawPtr_to(KQUrlInfo *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QUrlInfo]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QUrlInfo]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QUrlInfo_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQUrlInfo *qp = RawPtr_to(KQUrlInfo *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QUrlInfo]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QUrlInfo]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QUrlInfo_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQUrlInfo *qp = (KQUrlInfo *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QUrlInfo*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QUrlInfo_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQUrlInfo *qp = (KQUrlInfo *)p->rawptr;
		KQUrlInfo *qp = static_cast<KQUrlInfo*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QUrlInfo_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (*static_cast<QUrlInfo*>(p1->rawptr) == *static_cast<QUrlInfo*>(p2->rawptr) ? 0 : 1);
}

void KQUrlInfo::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QUrlInfoConstInt[] = {
	{"ReadOwner", QUrlInfo::ReadOwner},
	{"WriteOwner", QUrlInfo::WriteOwner},
	{"ExeOwner", QUrlInfo::ExeOwner},
	{"ReadGroup", QUrlInfo::ReadGroup},
	{"WriteGroup", QUrlInfo::WriteGroup},
	{"ExeGroup", QUrlInfo::ExeGroup},
	{"ReadOther", QUrlInfo::ReadOther},
	{"WriteOther", QUrlInfo::WriteOther},
	{"ExeOther", QUrlInfo::ExeOther},
	{NULL, 0}
};

DEFAPI(void) constQUrlInfo(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QUrlInfoConstInt);
}


DEFAPI(void) defQUrlInfo(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QUrlInfo";
	cdef->free = QUrlInfo_free;
	cdef->reftrace = QUrlInfo_reftrace;
	cdef->compareTo = QUrlInfo_compareTo;
}


